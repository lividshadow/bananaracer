#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void particle_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E9C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E9C4: lw          $v0, -0x4C1C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C1C);
    // 0x8000E9C8: jr          $ra
    // 0x8000E9CC: nop

    return;
    // 0x8000E9CC: nop

;}
RECOMP_FUNC void rumble_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800724D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800724DC: jr          $ra
    // 0x800724E0: sw          $a0, -0x1600($at)
    MEM_W(-0X1600, ctx->r1) = ctx->r4;
    return;
    // 0x800724E0: sw          $a0, -0x1600($at)
    MEM_W(-0X1600, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void find_active_pool_slot_colours(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071AE4: addiu       $sp, $sp, -0x238
    ctx->r29 = ADD32(ctx->r29, -0X238);
    // 0x80071AE8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80071AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80071AF0: addiu       $a0, $sp, 0x138
    ctx->r4 = ADD32(ctx->r29, 0X138);
    // 0x80071AF4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80071AF8: addiu       $v1, $sp, 0x138
    ctx->r3 = ADD32(ctx->r29, 0X138);
L_80071AFC:
    // 0x80071AFC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80071B00: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80071B04: sw          $zero, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = 0;
    // 0x80071B08: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80071B0C: sw          $zero, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = 0;
    // 0x80071B10: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80071B14: sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
    // 0x80071B18: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80071B1C: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x80071B20: bne         $a1, $v1, L_80071AFC
    if (ctx->r5 != ctx->r3) {
        // 0x80071B24: sw          $zero, -0x10($a1)
        MEM_W(-0X10, ctx->r5) = 0;
            goto L_80071AFC;
    }
    // 0x80071B24: sw          $zero, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = 0;
    // 0x80071B28: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80071B2C: lw          $a0, 0x3B40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3B40);
    // 0x80071B30: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071B34: blez        $a0, L_80071C24
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80071B38: addiu       $a1, $t6, 0x3B00
        ctx->r5 = ADD32(ctx->r14, 0X3B00);
            goto L_80071C24;
    }
    // 0x80071B38: addiu       $a1, $t6, 0x3B00
    ctx->r5 = ADD32(ctx->r14, 0X3B00);
    // 0x80071B3C: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x80071B40: addu        $t2, $t7, $a1
    ctx->r10 = ADD32(ctx->r15, ctx->r5);
    // 0x80071B44: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
    // 0x80071B48: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80071B4C: addiu       $t4, $sp, 0x38
    ctx->r12 = ADD32(ctx->r29, 0X38);
    // 0x80071B50: addiu       $t3, $sp, 0x138
    ctx->r11 = ADD32(ctx->r29, 0X138);
L_80071B54:
    // 0x80071B54: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x80071B58: nop

    // 0x80071B5C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80071B60:
    // 0x80071B60: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x80071B64: nop

    // 0x80071B68: beq         $t8, $zero, L_80071BEC
    if (ctx->r24 == 0) {
        // 0x80071B6C: nop
    
            goto L_80071BEC;
    }
    // 0x80071B6C: nop

    // 0x80071B70: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x80071B74: lw          $t9, 0x138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X138);
    // 0x80071B78: beq         $a2, $zero, L_80071BEC
    if (ctx->r6 == 0) {
        // 0x80071B7C: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_80071BEC;
    }
    // 0x80071B7C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80071B80: beq         $a2, $t9, L_80071BBC
    if (ctx->r6 == ctx->r25) {
        // 0x80071B84: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80071BBC;
    }
    // 0x80071B84: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80071B88: beq         $t9, $zero, L_80071BC0
    if (ctx->r25 == 0) {
        // 0x80071B8C: slti        $at, $t0, 0x40
        ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
            goto L_80071BC0;
    }
    // 0x80071B8C: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
L_80071B90:
    // 0x80071B90: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80071B94: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
    // 0x80071B98: beq         $at, $zero, L_80071BBC
    if (ctx->r1 == 0) {
        // 0x80071B9C: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_80071BBC;
    }
    // 0x80071B9C: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80071BA0: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x80071BA4: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80071BA8: nop

    // 0x80071BAC: beq         $a3, $a2, L_80071BC0
    if (ctx->r7 == ctx->r6) {
        // 0x80071BB0: slti        $at, $t0, 0x40
        ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
            goto L_80071BC0;
    }
    // 0x80071BB0: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
    // 0x80071BB4: bne         $a2, $zero, L_80071B90
    if (ctx->r6 != 0) {
        // 0x80071BB8: nop
    
            goto L_80071B90;
    }
    // 0x80071BB8: nop

L_80071BBC:
    // 0x80071BBC: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
L_80071BC0:
    // 0x80071BC0: beq         $at, $zero, L_80071BE8
    if (ctx->r1 == 0) {
        // 0x80071BC4: sll         $a2, $t0, 2
        ctx->r6 = S32(ctx->r8 << 2);
            goto L_80071BE8;
    }
    // 0x80071BC4: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
    // 0x80071BC8: addu        $t8, $t3, $a2
    ctx->r24 = ADD32(ctx->r11, ctx->r6);
    // 0x80071BCC: sw          $a3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r7;
    // 0x80071BD0: addu        $t1, $t4, $a2
    ctx->r9 = ADD32(ctx->r12, ctx->r6);
    // 0x80071BD4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80071BD8: nop

    // 0x80071BDC: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80071BE0: b           L_80071BEC
    // 0x80071BE4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
        goto L_80071BEC;
    // 0x80071BE4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_80071BE8:
    // 0x80071BE8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80071BEC:
    // 0x80071BEC: lh          $a3, 0xC($v1)
    ctx->r7 = MEM_H(ctx->r3, 0XC);
    // 0x80071BF0: nop

    // 0x80071BF4: beq         $a3, $t5, L_80071C0C
    if (ctx->r7 == ctx->r13) {
        // 0x80071BF8: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80071C0C;
    }
    // 0x80071BF8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80071BFC: multu       $a3, $s0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071C00: mflo        $t6
    ctx->r14 = lo;
    // 0x80071C04: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80071C08: nop

L_80071C0C:
    // 0x80071C0C: bne         $a2, $t5, L_80071B60
    if (ctx->r6 != ctx->r13) {
        // 0x80071C10: nop
    
            goto L_80071B60;
    }
    // 0x80071C10: nop

    // 0x80071C14: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80071C18: sltu        $at, $a1, $t2
    ctx->r1 = ctx->r5 < ctx->r10 ? 1 : 0;
    // 0x80071C1C: bne         $at, $zero, L_80071B54
    if (ctx->r1 != 0) {
        // 0x80071C20: nop
    
            goto L_80071B54;
    }
    // 0x80071C20: nop

L_80071C24:
    // 0x80071C24: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x80071C28: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80071C2C: beq         $t8, $zero, L_80071C5C
    if (ctx->r24 == 0) {
        // 0x80071C30: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80071C5C;
    }
    // 0x80071C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80071C34: sll         $t9, $zero, 2
    ctx->r25 = S32(0 << 2);
    // 0x80071C38: addiu       $t7, $sp, 0x138
    ctx->r15 = ADD32(ctx->r29, 0X138);
    // 0x80071C3C: addu        $a0, $t9, $t7
    ctx->r4 = ADD32(ctx->r25, ctx->r15);
    // 0x80071C40: addiu       $v1, $sp, 0x238
    ctx->r3 = ADD32(ctx->r29, 0X238);
L_80071C44:
    // 0x80071C44: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80071C48: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80071C4C: beq         $t6, $zero, L_80071C5C
    if (ctx->r14 == 0) {
        // 0x80071C50: nop
    
            goto L_80071C5C;
    }
    // 0x80071C50: nop

    // 0x80071C54: bne         $a0, $v1, L_80071C44
    if (ctx->r4 != ctx->r3) {
        // 0x80071C58: nop
    
            goto L_80071C44;
    }
    // 0x80071C58: nop

L_80071C5C:
    // 0x80071C5C: jr          $ra
    // 0x80071C60: addiu       $sp, $sp, 0x238
    ctx->r29 = ADD32(ctx->r29, 0X238);
    return;
    // 0x80071C60: addiu       $sp, $sp, 0x238
    ctx->r29 = ADD32(ctx->r29, 0X238);
;}
RECOMP_FUNC void move_dialogue_box_to_front(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5988: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C598C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5990: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5994: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5998: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C599C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C59A0: lw          $a2, 0x24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X24);
    // 0x800C59A4: addiu       $v1, $v0, 0x24
    ctx->r3 = ADD32(ctx->r2, 0X24);
    // 0x800C59A8: beq         $a2, $zero, L_800C59D4
    if (ctx->r6 == 0) {
        // 0x800C59AC: nop
    
            goto L_800C59D4;
    }
    // 0x800C59AC: nop

    // 0x800C59B0: beq         $a2, $a1, L_800C59D4
    if (ctx->r6 == ctx->r5) {
        // 0x800C59B4: nop
    
            goto L_800C59D4;
    }
    // 0x800C59B4: nop

L_800C59B8:
    // 0x800C59B8: addiu       $v1, $a2, 0x1C
    ctx->r3 = ADD32(ctx->r6, 0X1C);
    // 0x800C59BC: lw          $a2, 0x1C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1C);
    // 0x800C59C0: nop

    // 0x800C59C4: beq         $a2, $zero, L_800C59D4
    if (ctx->r6 == 0) {
        // 0x800C59C8: nop
    
            goto L_800C59D4;
    }
    // 0x800C59C8: nop

    // 0x800C59CC: bne         $a2, $a1, L_800C59B8
    if (ctx->r6 != ctx->r5) {
        // 0x800C59D0: nop
    
            goto L_800C59B8;
    }
    // 0x800C59D0: nop

L_800C59D4:
    // 0x800C59D4: beq         $a2, $zero, L_800C59EC
    if (ctx->r6 == 0) {
        // 0x800C59D8: nop
    
            goto L_800C59EC;
    }
    // 0x800C59D8: nop

    // 0x800C59DC: lw          $t8, 0x1C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X1C);
    // 0x800C59E0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800C59E4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C59E8: sb          $t9, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r25;
L_800C59EC:
    // 0x800C59EC: jr          $ra
    // 0x800C59F0: nop

    return;
    // 0x800C59F0: nop

;}
RECOMP_FUNC void light_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032258: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003225C: jr          $ra
    // 0x80032260: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
    return;
    // 0x80032260: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5850: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800D5854: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x800D5858: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x800D585C: blez        $a1, L_800D58A0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D5860: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_800D58A0;
    }
    // 0x800D5860: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800D5864:
    // 0x800D5864: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x800D5868: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800D586C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x800D5870: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800D5874: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x800D5878: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800D587C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800D5880: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x800D5884: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x800D5888: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D588C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x800D5890: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800D5894: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800D5898: bne         $at, $zero, L_800D5864
    if (ctx->r1 != 0) {
        // 0x800D589C: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_800D5864;
    }
    // 0x800D589C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_800D58A0:
    // 0x800D58A0: lhu         $v0, 0xA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XA);
    // 0x800D58A4: jr          $ra
    // 0x800D58A8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800D58A8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void obj_id_valid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010028: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001002C: lw          $t6, -0x4BC8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BC8);
    // 0x80010030: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80010034: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80010038: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001003C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80010040: lw          $t0, -0x4D18($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4D18);
    // 0x80010044: jr          $ra
    // 0x80010048: slt         $v0, $t9, $t0
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    return;
    // 0x80010048: slt         $v0, $t9, $t0
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
;}
RECOMP_FUNC void func_8005250C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005254C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052550: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80052554: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80052558: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005255C: lb          $t6, 0x173($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X173);
    // 0x80052560: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80052564: blez        $t6, L_800525A4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80052568: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_800525A4;
    }
    // 0x80052568: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8005256C: jal         0x8001E2D0
    // 0x80052570: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80052570: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80052574: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80052578: nop

    // 0x8005257C: lb          $t7, 0x172($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X172);
    // 0x80052580: lb          $t9, 0x174($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X174);
    // 0x80052584: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80052588: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005258C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80052590: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80052594: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80052598: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8005259C: lb          $v1, 0x0($t2)
    ctx->r3 = MEM_B(ctx->r10, 0X0);
    // 0x800525A0: nop

L_800525A4:
    // 0x800525A4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800525A8: lw          $t3, -0x2554($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2554);
    // 0x800525AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800525B0: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x800525B4: beq         $t4, $zero, L_800525D0
    if (ctx->r12 == 0) {
        // 0x800525B8: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_800525D0;
    }
    // 0x800525B8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800525BC: beq         $v1, $at, L_800525D0
    if (ctx->r3 == ctx->r1) {
        // 0x800525C0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800525D0;
    }
    // 0x800525C0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800525C4: beq         $v1, $at, L_800525D0
    if (ctx->r3 == ctx->r1) {
        // 0x800525C8: addiu       $t5, $zero, 0x5
        ctx->r13 = ADD32(0, 0X5);
            goto L_800525D0;
    }
    // 0x800525C8: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x800525CC: sb          $t5, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = ctx->r13;
L_800525D0:
    // 0x800525D0: lb          $t6, 0x1D3($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1D3);
    // 0x800525D4: nop

    // 0x800525D8: beq         $t6, $zero, L_800525F0
    if (ctx->r14 == 0) {
        // 0x800525DC: nop
    
            goto L_800525F0;
    }
    // 0x800525DC: nop

    // 0x800525E0: lbu         $t7, 0x1F3($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1F3);
    // 0x800525E4: nop

    // 0x800525E8: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x800525EC: sb          $t9, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r25;
L_800525F0:
    // 0x800525F0: lbu         $t8, 0x1F3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1F3);
    // 0x800525F4: nop

    // 0x800525F8: andi        $t0, $t8, 0x8
    ctx->r8 = ctx->r24 & 0X8;
    // 0x800525FC: beq         $t0, $zero, L_80052658
    if (ctx->r8 == 0) {
        // 0x80052600: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_80052658;
    }
    // 0x80052600: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80052604: lw          $t1, -0x2EF8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2EF8);
    // 0x80052608: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8005260C: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80052610: beq         $at, $zero, L_80052654
    if (ctx->r1 == 0) {
        // 0x80052614: nop
    
            goto L_80052654;
    }
    // 0x80052614: nop

    // 0x80052618: lw          $t2, -0x2524($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2524);
    // 0x8005261C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80052620: bltz        $t2, L_80052644
    if (SIGNED(ctx->r10) < 0) {
        // 0x80052624: nop
    
            goto L_80052644;
    }
    // 0x80052624: nop

    // 0x80052628: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8005262C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80052630: lw          $t4, 0x74($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X74);
    // 0x80052634: nop

    // 0x80052638: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8005263C: b           L_80052654
    // 0x80052640: sw          $t5, 0x74($t3)
    MEM_W(0X74, ctx->r11) = ctx->r13;
        goto L_80052654;
    // 0x80052640: sw          $t5, 0x74($t3)
    MEM_W(0X74, ctx->r11) = ctx->r13;
L_80052644:
    // 0x80052644: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80052648: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8005264C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80052650: sw          $t9, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r25;
L_80052654:
    // 0x80052654: sb          $t8, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = ctx->r24;
L_80052658:
    // 0x80052658: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005265C: lw          $t0, -0x2540($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2540);
    // 0x80052660: nop

    // 0x80052664: beq         $t0, $zero, L_80052674
    if (ctx->r8 == 0) {
        // 0x80052668: nop
    
            goto L_80052674;
    }
    // 0x80052668: nop

    // 0x8005266C: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
    // 0x80052670: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
L_80052674:
    // 0x80052674: lb          $t1, 0x1D8($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X1D8);
    // 0x80052678: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005267C: bne         $t1, $at, L_8005268C
    if (ctx->r9 != ctx->r1) {
        // 0x80052680: nop
    
            goto L_8005268C;
    }
    // 0x80052680: nop

    // 0x80052684: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
    // 0x80052688: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
L_8005268C:
    // 0x8005268C: lbu         $t2, 0x1F2($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1F2);
    // 0x80052690: nop

    // 0x80052694: sltiu       $at, $t2, 0x8
    ctx->r1 = ctx->r10 < 0X8 ? 1 : 0;
    // 0x80052698: beq         $at, $zero, L_800529B8
    if (ctx->r1 == 0) {
        // 0x8005269C: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_800529B8;
    }
    // 0x8005269C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800526A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800526A4: addu        $at, $at, $t2
    gpr jr_addend_800526B0 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800526A8: lw          $t2, 0x6C60($at)
    ctx->r10 = ADD32(ctx->r1, 0X6C60);
    // 0x800526AC: nop

    // 0x800526B0: jr          $t2
    // 0x800526B4: nop

    switch (jr_addend_800526B0 >> 2) {
        case 0: goto L_800526B8; break;
        case 1: goto L_800529B8; break;
        case 2: goto L_800529B8; break;
        case 3: goto L_800527EC; break;
        case 4: goto L_8005284C; break;
        case 5: goto L_80052898; break;
        case 6: goto L_800528E4; break;
        case 7: goto L_80052950; break;
        default: switch_error(__func__, 0x800526B0, 0x800E6C60);
    }
    // 0x800526B4: nop

L_800526B8:
    // 0x800526B8: lh          $t4, 0x1A2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X1A2);
    // 0x800526BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800526C0: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800526C4: sra         $t3, $t5, 8
    ctx->r11 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800526C8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800526CC: lwc1        $f8, -0x2510($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2510);
    // 0x800526D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800526D4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800526D8: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x800526DC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800526E0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800526E4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800526E8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800526EC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800526F0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800526F4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800526F8: nop

    // 0x800526FC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80052700: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80052704: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80052708: nop

    // 0x8005270C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80052710: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80052714: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80052718: subu        $v1, $t9, $v1
    ctx->r3 = SUB32(ctx->r25, ctx->r3);
    // 0x8005271C: bgez        $v1, L_80052728
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80052720: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80052728;
    }
    // 0x80052720: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80052724: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80052728:
    // 0x80052728: slti        $at, $v1, 0x4A
    ctx->r1 = SIGNED(ctx->r3) < 0X4A ? 1 : 0;
    // 0x8005272C: bne         $at, $zero, L_80052738
    if (ctx->r1 != 0) {
        // 0x80052730: nop
    
            goto L_80052738;
    }
    // 0x80052730: nop

    // 0x80052734: addiu       $v1, $zero, 0x49
    ctx->r3 = ADD32(0, 0X49);
L_80052738:
    // 0x80052738: lh          $a2, 0x18($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X18);
    // 0x8005273C: nop

    // 0x80052740: subu        $a0, $v1, $a2
    ctx->r4 = SUB32(ctx->r3, ctx->r6);
    // 0x80052744: blez        $a0, L_80052760
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80052748: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80052760;
    }
    // 0x80052748: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005274C: subu        $v1, $t8, $v0
    ctx->r3 = SUB32(ctx->r24, ctx->r2);
    // 0x80052750: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80052754: beq         $at, $zero, L_80052760
    if (ctx->r1 == 0) {
        // 0x80052758: nop
    
            goto L_80052760;
    }
    // 0x80052758: nop

    // 0x8005275C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80052760:
    // 0x80052760: bgez        $a0, L_80052790
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80052764: addu        $t1, $a2, $v1
        ctx->r9 = ADD32(ctx->r6, ctx->r3);
            goto L_80052790;
    }
    // 0x80052764: addu        $t1, $a2, $v1
    ctx->r9 = ADD32(ctx->r6, ctx->r3);
    // 0x80052768: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8005276C: nop

    // 0x80052770: negu        $at, $v0
    ctx->r1 = SUB32(0, ctx->r2);
    // 0x80052774: sll         $t0, $at, 2
    ctx->r8 = S32(ctx->r1 << 2);
    // 0x80052778: subu        $v1, $t0, $at
    ctx->r3 = SUB32(ctx->r8, ctx->r1);
    // 0x8005277C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80052780: beq         $at, $zero, L_80052790
    if (ctx->r1 == 0) {
        // 0x80052784: addu        $t1, $a2, $v1
        ctx->r9 = ADD32(ctx->r6, ctx->r3);
            goto L_80052790;
    }
    // 0x80052784: addu        $t1, $a2, $v1
    ctx->r9 = ADD32(ctx->r6, ctx->r3);
    // 0x80052788: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8005278C: addu        $t1, $a2, $v1
    ctx->r9 = ADD32(ctx->r6, ctx->r3);
L_80052790:
    // 0x80052790: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    // 0x80052794: sb          $zero, 0x3B($t2)
    MEM_B(0X3B, ctx->r10) = 0;
    // 0x80052798: lbu         $v0, 0x1F3($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1F3);
    // 0x8005279C: nop

    // 0x800527A0: andi        $t4, $v0, 0x4
    ctx->r12 = ctx->r2 & 0X4;
    // 0x800527A4: beq         $t4, $zero, L_800527B4
    if (ctx->r12 == 0) {
        // 0x800527A8: andi        $t3, $v0, 0xFFFB
        ctx->r11 = ctx->r2 & 0XFFFB;
            goto L_800527B4;
    }
    // 0x800527A8: andi        $t3, $v0, 0xFFFB
    ctx->r11 = ctx->r2 & 0XFFFB;
    // 0x800527AC: sb          $t5, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = ctx->r13;
    // 0x800527B0: sb          $t3, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r11;
L_800527B4:
    // 0x800527B4: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800527B8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800527BC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800527C0: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x800527C4: nop

    // 0x800527C8: bc1f        L_800529BC
    if (!c1cs) {
        // 0x800527CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800529BC;
    }
    // 0x800527CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800527D0: lw          $t7, -0x2558($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2558);
    // 0x800527D4: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800527D8: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x800527DC: beq         $t9, $zero, L_800529BC
    if (ctx->r25 == 0) {
        // 0x800527E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800529BC;
    }
    // 0x800527E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800527E4: b           L_800529B8
    // 0x800527E8: sb          $t6, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = ctx->r14;
        goto L_800529B8;
    // 0x800527E8: sb          $t6, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = ctx->r14;
L_800527EC:
    // 0x800527EC: lbu         $t8, 0x1F3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1F3);
    // 0x800527F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800527F4: andi        $t0, $t8, 0x4
    ctx->r8 = ctx->r24 & 0X4;
    // 0x800527F8: beq         $t0, $zero, L_80052804
    if (ctx->r8 == 0) {
        // 0x800527FC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80052804;
    }
    // 0x800527FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80052800: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80052804:
    // 0x80052804: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80052808: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x8005280C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80052810: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80052814: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80052818: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005281C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80052820: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80052824: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80052828: jal         0x800529C8
    // 0x8005282C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    func_80052988(rdram, ctx);
        goto after_1;
    // 0x8005282C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    after_1:
    // 0x80052830: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80052834: nop

    // 0x80052838: lbu         $t5, 0x1F3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X1F3);
    // 0x8005283C: nop

    // 0x80052840: andi        $t3, $t5, 0xFFFB
    ctx->r11 = ctx->r13 & 0XFFFB;
    // 0x80052844: b           L_800529B8
    // 0x80052848: sb          $t3, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r11;
        goto L_800529B8;
    // 0x80052848: sb          $t3, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r11;
L_8005284C:
    // 0x8005284C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80052850: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052854: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80052858: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8005285C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80052860: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80052864: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80052868: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005286C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80052870: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80052874: jal         0x800529C8
    // 0x80052878: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80052988(rdram, ctx);
        goto after_2;
    // 0x80052878: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_2:
    // 0x8005287C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80052880: nop

    // 0x80052884: lbu         $t8, 0x1F3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1F3);
    // 0x80052888: nop

    // 0x8005288C: andi        $t0, $t8, 0xFFF7
    ctx->r8 = ctx->r24 & 0XFFF7;
    // 0x80052890: b           L_800529B8
    // 0x80052894: sb          $t0, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r8;
        goto L_800529B8;
    // 0x80052894: sb          $t0, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r8;
L_80052898:
    // 0x80052898: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8005289C: lw          $t1, -0x2558($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2558);
    // 0x800528A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800528A4: andi        $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 & 0X2000;
    // 0x800528A8: beq         $t2, $zero, L_800528B4
    if (ctx->r10 == 0) {
        // 0x800528AC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800528B4;
    }
    // 0x800528AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800528B0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800528B4:
    // 0x800528B4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800528B8: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x800528BC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800528C0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800528C4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800528C8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800528CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800528D0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800528D4: jal         0x800529C8
    // 0x800528D8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    func_80052988(rdram, ctx);
        goto after_3;
    // 0x800528D8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_3:
    // 0x800528DC: b           L_800529BC
    // 0x800528E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800529BC;
    // 0x800528E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800528E4:
    // 0x800528E4: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800528E8: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800528EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800528F0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800528F4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x800528F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800528FC: bc1f        L_80052920
    if (!c1cs) {
        // 0x80052900: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80052920;
    }
    // 0x80052900: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80052904: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80052908: lw          $t7, -0x2558($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2558);
    // 0x8005290C: nop

    // 0x80052910: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x80052914: beq         $t9, $zero, L_80052924
    if (ctx->r25 == 0) {
        // 0x80052918: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_80052924;
    }
    // 0x80052918: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8005291C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80052920:
    // 0x80052920: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_80052924:
    // 0x80052924: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80052928: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8005292C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80052930: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80052934: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80052938: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005293C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80052940: jal         0x800529C8
    // 0x80052944: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_80052988(rdram, ctx);
        goto after_4;
    // 0x80052944: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_4:
    // 0x80052948: b           L_800529BC
    // 0x8005294C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800529BC;
    // 0x8005294C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80052950:
    // 0x80052950: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80052954: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052958: addiu       $t1, $zero, 0x60
    ctx->r9 = ADD32(0, 0X60);
    // 0x8005295C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80052960: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80052964: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80052968: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8005296C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80052970: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80052974: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80052978: jal         0x800529C8
    // 0x8005297C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    func_80052988(rdram, ctx);
        goto after_5;
    // 0x8005297C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    after_5:
    // 0x80052980: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80052984: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052988: lbu         $t5, 0x1F2($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X1F2);
    // 0x8005298C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80052990: bne         $t5, $zero, L_800529B8
    if (ctx->r13 != 0) {
        // 0x80052994: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800529B8;
    }
    // 0x80052994: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80052998: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8005299C: addiu       $t3, $zero, 0x60
    ctx->r11 = ADD32(0, 0X60);
    // 0x800529A0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800529A4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800529A8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800529AC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800529B0: jal         0x800529C8
    // 0x800529B4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80052988(rdram, ctx);
        goto after_6;
    // 0x800529B4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_6:
L_800529B8:
    // 0x800529B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800529BC:
    // 0x800529BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800529C0: jr          $ra
    // 0x800529C4: nop

    return;
    // 0x800529C4: nop

;}
RECOMP_FUNC void func_80017978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800179AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800179B0: lw          $a2, -0x4A8C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4A8C);
    // 0x800179B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800179B8: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
L_800179BC:
    // 0x800179BC: addu        $v1, $t6, $a2
    ctx->r3 = ADD32(ctx->r14, ctx->r6);
    // 0x800179C0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800179C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800179C8: bne         $t7, $zero, L_800179E8
    if (ctx->r15 != 0) {
        // 0x800179CC: sll         $t9, $v0, 16
        ctx->r25 = S32(ctx->r2 << 16);
            goto L_800179E8;
    }
    // 0x800179CC: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800179D0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800179D4: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800179D8: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x800179DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800179E0: jr          $ra
    // 0x800179E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800179E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800179E8:
    // 0x800179E8: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800179EC: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800179F0: bne         $at, $zero, L_800179BC
    if (ctx->r1 != 0) {
        // 0x800179F4: sll         $t6, $v0, 6
        ctx->r14 = S32(ctx->r2 << 6);
            goto L_800179BC;
    }
    // 0x800179F4: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x800179F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800179FC: jr          $ra
    // 0x80017A00: nop

    return;
    // 0x80017A00: nop

;}
RECOMP_FUNC void hud_init_element(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F574: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8009F578: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8009F57C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8009F580: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8009F584: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8009F588: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8009F58C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8009F590: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8009F594: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8009F598: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8009F59C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8009F5A0: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8009F5A4: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8009F5A8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8009F5AC: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8009F5B0: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8009F5B4: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8009F5B8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8009F5BC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8009F5C0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8009F5C4: jal         0x8006BFD8
    // 0x8009F5C8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    level_type(rdram, ctx);
        goto after_0;
    // 0x8009F5C8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8009F5CC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009F5D0: beq         $t4, $v0, L_8009F5E4
    if (ctx->r12 == ctx->r2) {
        // 0x8009F5D4: lui         $s0, 0x8000
        ctx->r16 = S32(0X8000 << 16);
            goto L_8009F5E4;
    }
    // 0x8009F5D4: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8009F5D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009F5DC: bne         $v0, $at, L_8009F5FC
    if (ctx->r2 != ctx->r1) {
        // 0x8009F5E0: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8009F5FC;
    }
    // 0x8009F5E0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
L_8009F5E4:
    // 0x8009F5E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F5E8: sw          $zero, 0x72E4($at)
    MEM_W(0X72E4, ctx->r1) = 0;
    // 0x8009F5EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F5F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009F5F4: b           L_8009F64C
    // 0x8009F5F8: sb          $t6, 0x72F4($at)
    MEM_B(0X72F4, ctx->r1) = ctx->r14;
        goto L_8009F64C;
    // 0x8009F5F8: sb          $t6, 0x72F4($at)
    MEM_B(0X72F4, ctx->r1) = ctx->r14;
L_8009F5FC:
    // 0x8009F5FC: lw          $t7, 0x72CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72CC);
    // 0x8009F600: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x8009F604: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8009F608: beq         $at, $zero, L_8009F62C
    if (ctx->r1 == 0) {
        // 0x8009F60C: addiu       $t9, $zero, 0xC8
        ctx->r25 = ADD32(0, 0XC8);
            goto L_8009F62C;
    }
    // 0x8009F60C: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8009F610: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F614: sw          $t8, 0x72E4($at)
    MEM_W(0X72E4, ctx->r1) = ctx->r24;
    // 0x8009F618: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8009F61C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009F620: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F624: b           L_8009F644
    // 0x8009F628: swc1        $f4, 0x72F0($at)
    MEM_W(0X72F0, ctx->r1) = ctx->f4.u32l;
        goto L_8009F644;
    // 0x8009F628: swc1        $f4, 0x72F0($at)
    MEM_W(0X72F0, ctx->r1) = ctx->f4.u32l;
L_8009F62C:
    // 0x8009F62C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F630: sw          $t9, 0x72E4($at)
    MEM_W(0X72E4, ctx->r1) = ctx->r25;
    // 0x8009F634: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8009F638: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009F63C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F640: swc1        $f6, 0x72F0($at)
    MEM_W(0X72F0, ctx->r1) = ctx->f6.u32l;
L_8009F644:
    // 0x8009F644: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F648: sb          $zero, 0x72F4($at)
    MEM_B(0X72F4, ctx->r1) = 0;
L_8009F64C:
    // 0x8009F64C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F650: sh          $zero, 0x72EC($at)
    MEM_H(0X72EC, ctx->r1) = 0;
    // 0x8009F654: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F658: sb          $zero, 0x7294($at)
    MEM_B(0X7294, ctx->r1) = 0;
    // 0x8009F65C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F660: sb          $zero, 0x72F6($at)
    MEM_B(0X72F6, ctx->r1) = 0;
    // 0x8009F664: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F668: sb          $zero, 0x72F8($at)
    MEM_B(0X72F8, ctx->r1) = 0;
    // 0x8009F66C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F670: sb          $zero, 0x72F5($at)
    MEM_B(0X72F5, ctx->r1) = 0;
    // 0x8009F674: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F678: addiu       $s0, $s0, 0x300
    ctx->r16 = ADD32(ctx->r16, 0X300);
    // 0x8009F67C: sb          $zero, 0x7290($at)
    MEM_B(0X7290, ctx->r1) = 0;
    // 0x8009F680: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8009F684: addiu       $t9, $zero, -0x64
    ctx->r25 = ADD32(0, -0X64);
    // 0x8009F688: bne         $t6, $zero, L_8009F6A0
    if (ctx->r14 != 0) {
        // 0x8009F68C: addiu       $a0, $zero, 0x78
        ctx->r4 = ADD32(0, 0X78);
            goto L_8009F6A0;
    }
    // 0x8009F68C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x8009F690: addiu       $t7, $zero, 0x3D
    ctx->r15 = ADD32(0, 0X3D);
    // 0x8009F694: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F698: b           L_8009F6AC
    // 0x8009F69C: sb          $t7, 0x774B($at)
    MEM_B(0X774B, ctx->r1) = ctx->r15;
        goto L_8009F6AC;
    // 0x8009F69C: sb          $t7, 0x774B($at)
    MEM_B(0X774B, ctx->r1) = ctx->r15;
L_8009F6A0:
    // 0x8009F6A0: addiu       $t8, $zero, 0x33
    ctx->r24 = ADD32(0, 0X33);
    // 0x8009F6A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6A8: sb          $t8, 0x774B($at)
    MEM_B(0X774B, ctx->r1) = ctx->r24;
L_8009F6AC:
    // 0x8009F6AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6B0: sb          $zero, 0x7291($at)
    MEM_B(0X7291, ctx->r1) = 0;
    // 0x8009F6B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6B8: sb          $zero, 0x7292($at)
    MEM_B(0X7292, ctx->r1) = 0;
    // 0x8009F6BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6C0: sb          $zero, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = 0;
    // 0x8009F6C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6C8: sb          $zero, 0x7749($at)
    MEM_B(0X7749, ctx->r1) = 0;
    // 0x8009F6CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6D0: sw          $t9, 0x730C($at)
    MEM_W(0X730C, ctx->r1) = ctx->r25;
    // 0x8009F6D4: jal         0x8006FB8C
    // 0x8009F6D8: addiu       $a1, $zero, 0x168
    ctx->r5 = ADD32(0, 0X168);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x8009F6D8: addiu       $a1, $zero, 0x168
    ctx->r5 = ADD32(0, 0X168);
    after_1:
    // 0x8009F6DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6E0: jal         0x8000E158
    // 0x8009F6E4: sw          $v0, 0x7310($at)
    MEM_W(0X7310, ctx->r1) = ctx->r2;
    is_race_started_by_player_two(rdram, ctx);
        goto after_2;
    // 0x8009F6E4: sw          $v0, 0x7310($at)
    MEM_W(0X7310, ctx->r1) = ctx->r2;
    after_2:
    // 0x8009F6E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F6EC: sb          $v0, 0x774A($at)
    MEM_B(0X774A, ctx->r1) = ctx->r2;
    // 0x8009F6F0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8009F6F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F6F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009F6FC: addiu       $a0, $a0, 0x7750
    ctx->r4 = ADD32(ctx->r4, 0X7750);
    // 0x8009F700: addiu       $v1, $v1, 0x774C
    ctx->r3 = ADD32(ctx->r3, 0X774C);
    // 0x8009F704: addiu       $t6, $zero, 0x37
    ctx->r14 = ADD32(0, 0X37);
    // 0x8009F708: addiu       $t7, $zero, 0xB3
    ctx->r15 = ADD32(0, 0XB3);
    // 0x8009F70C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009F710: bne         $t8, $zero, L_8009F72C
    if (ctx->r24 != 0) {
        // 0x8009F714: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8009F72C;
    }
    // 0x8009F714: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009F718: addiu       $t6, $t7, 0x1E
    ctx->r14 = ADD32(ctx->r15, 0X1E);
    // 0x8009F71C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8009F720: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009F724: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x8009F728: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8009F72C:
    // 0x8009F72C: jal         0x8001B674
    // 0x8009F730: nop

    timetrial_ghost_staff(rdram, ctx);
        goto after_3;
    // 0x8009F730: nop

    after_3:
    // 0x8009F734: bne         $v0, $zero, L_8009F748
    if (ctx->r2 != 0) {
        // 0x8009F738: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8009F748;
    }
    // 0x8009F738: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009F73C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F740: b           L_8009F754
    // 0x8009F744: sb          $zero, 0x7331($at)
    MEM_B(0X7331, ctx->r1) = 0;
        goto L_8009F754;
    // 0x8009F744: sb          $zero, 0x7331($at)
    MEM_B(0X7331, ctx->r1) = 0;
L_8009F748:
    // 0x8009F748: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009F74C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F750: sb          $t9, 0x7331($at)
    MEM_B(0X7331, ctx->r1) = ctx->r25;
L_8009F754:
    // 0x8009F754: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009F758: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x8009F75C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009F760: beq         $v0, $at, L_8009F770
    if (ctx->r2 == ctx->r1) {
        // 0x8009F764: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_8009F770;
    }
    // 0x8009F764: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8009F768: b           L_8009F774
    // 0x8009F76C: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
        goto L_8009F774;
    // 0x8009F76C: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
L_8009F770:
    // 0x8009F770: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
L_8009F774:
    // 0x8009F774: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8009F778: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009F77C: blez        $t7, L_800A04E4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8009F780: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800A04E4;
    }
    // 0x8009F780: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009F784: lui         $at, 0xC268
    ctx->r1 = S32(0XC268 << 16);
    // 0x8009F788: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8009F78C: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x8009F790: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8009F794: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8009F798: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8009F79C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009F7A0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8009F7A4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8009F7A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8009F7AC: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x8009F7B0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8009F7B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009F7B8: addiu       $t8, $t8, 0x72A0
    ctx->r24 = ADD32(ctx->r24, 0X72A0);
    // 0x8009F7BC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009F7C0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009F7C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009F7C8: lwc1        $f15, -0x73D8($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, -0X73D8);
    // 0x8009F7CC: lwc1        $f14, -0x73D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X73D4);
    // 0x8009F7D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009F7D4: addiu       $a1, $a1, 0x729C
    ctx->r5 = ADD32(ctx->r5, 0X729C);
    // 0x8009F7D8: addiu       $t1, $t1, 0x72B0
    ctx->r9 = ADD32(ctx->r9, 0X72B0);
    // 0x8009F7DC: addiu       $s0, $s0, 0x2B44
    ctx->r16 = ADD32(ctx->r16, 0X2B44);
    // 0x8009F7E0: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x8009F7E4: addiu       $fp, $zero, 0x36
    ctx->r30 = ADD32(0, 0X36);
    // 0x8009F7E8: addiu       $s7, $zero, 0x1C
    ctx->r23 = ADD32(0, 0X1C);
    // 0x8009F7EC: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x8009F7F0: addiu       $s5, $zero, 0xB
    ctx->r21 = ADD32(0, 0XB);
    // 0x8009F7F4: addiu       $s4, $zero, 0xF
    ctx->r20 = ADD32(0, 0XF);
    // 0x8009F7F8: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8009F7FC: addiu       $s2, $zero, 0x760
    ctx->r18 = ADD32(0, 0X760);
    // 0x8009F800: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x8009F804: addiu       $ra, $zero, 0x12
    ctx->r31 = ADD32(0, 0X12);
    // 0x8009F808: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8009F80C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8009F810: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8009F814: ori         $t0, $zero, 0xC000
    ctx->r8 = 0 | 0XC000;
L_8009F818:
    // 0x8009F818: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8009F81C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009F820: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8009F824: addiu       $v0, $v0, 0x23E4
    ctx->r2 = ADD32(ctx->r2, 0X23E4);
    // 0x8009F828: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009F82C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_8009F830:
    // 0x8009F830: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F834: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009F838: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8009F83C: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x8009F840: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F844: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009F848: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8009F84C: swc1        $f10, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f10.u32l;
    // 0x8009F850: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F854: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009F858: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8009F85C: swc1        $f4, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f4.u32l;
    // 0x8009F860: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009F864: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009F868: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8009F86C: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x8009F870: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F874: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009F878: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F87C: sh          $t7, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r15;
    // 0x8009F880: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F884: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8009F888: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F88C: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x8009F890: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F894: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8009F898: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F89C: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x8009F8A0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8A4: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8009F8A8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F8AC: sh          $t7, 0x6($t9)
    MEM_H(0X6, ctx->r25) = ctx->r15;
    // 0x8009F8B0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8B4: lh          $t6, 0x18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X18);
    // 0x8009F8B8: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F8BC: sh          $t6, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r14;
    // 0x8009F8C0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8C4: lb          $t9, 0x1A($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1A);
    // 0x8009F8C8: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F8CC: sb          $t9, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r25;
    // 0x8009F8D0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8D4: lb          $t7, 0x1B($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1B);
    // 0x8009F8D8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F8DC: sb          $t7, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = ctx->r15;
    // 0x8009F8E0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8E4: lb          $t6, 0x1C($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C);
    // 0x8009F8E8: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F8EC: sb          $t6, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r14;
    // 0x8009F8F0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F8F4: lb          $t9, 0x1D($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1D);
    // 0x8009F8F8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8009F8FC: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x8009F900: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8009F904: bne         $v0, $s0, L_8009F830
    if (ctx->r2 != ctx->r16) {
        // 0x8009F908: sb          $t9, 0x1D($t6)
        MEM_B(0X1D, ctx->r14) = ctx->r25;
            goto L_8009F830;
    }
    // 0x8009F908: sb          $t9, 0x1D($t6)
    MEM_B(0X1D, ctx->r14) = ctx->r25;
    // 0x8009F90C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F910: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8009F914: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F918: sb          $t7, 0x5DC($t8)
    MEM_B(0X5DC, ctx->r24) = ctx->r15;
    // 0x8009F91C: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x8009F920: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8009F924: bne         $t4, $v1, L_8009FB38
    if (ctx->r12 != ctx->r3) {
        // 0x8009F928: nop
    
            goto L_8009FB38;
    }
    // 0x8009F928: nop

    // 0x8009F92C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009F930: addiu       $v0, $v1, 0x2B44
    ctx->r2 = ADD32(ctx->r3, 0X2B44);
    // 0x8009F934: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8009F938: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009F93C: beq         $t2, $t9, L_8009FA3C
    if (ctx->r10 == ctx->r25) {
        // 0x8009F940: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_8009FA3C;
    }
    // 0x8009F940: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009F944: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009F948: addiu       $t6, $t6, 0x2B44
    ctx->r14 = ADD32(ctx->r14, 0X2B44);
    // 0x8009F94C: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    // 0x8009F950: nop

L_8009F954:
    // 0x8009F954: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8009F958: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009F95C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8009F960: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x8009F964: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009F968: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8009F96C: swc1        $f10, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f10.u32l;
    // 0x8009F970: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8009F974: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009F978: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8009F97C: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8009F980: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x8009F984: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8009F988: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8009F98C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8009F990: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x8009F994: nop

    // 0x8009F998: andi        $t6, $t8, 0xC000
    ctx->r14 = ctx->r24 & 0XC000;
    // 0x8009F99C: bne         $t0, $t6, L_8009F9E8
    if (ctx->r8 != ctx->r14) {
        // 0x8009F9A0: nop
    
            goto L_8009F9E8;
    }
    // 0x8009F9A0: nop

    // 0x8009F9A4: bne         $a3, $zero, L_8009F9C8
    if (ctx->r7 != 0) {
        // 0x8009F9A8: nop
    
            goto L_8009F9C8;
    }
    // 0x8009F9A8: nop

    // 0x8009F9AC: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009F9B0: nop

    // 0x8009F9B4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8009F9B8: nop

    // 0x8009F9BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009F9C0: b           L_8009FA2C
    // 0x8009F9C4: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
        goto L_8009FA2C;
    // 0x8009F9C4: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
L_8009F9C8:
    // 0x8009F9C8: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x8009F9CC: nop

    // 0x8009F9D0: addiu       $t8, $t9, 0x6C
    ctx->r24 = ADD32(ctx->r25, 0X6C);
    // 0x8009F9D4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8009F9D8: nop

    // 0x8009F9DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009F9E0: b           L_8009FA2C
    // 0x8009F9E4: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
        goto L_8009FA2C;
    // 0x8009F9E4: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
L_8009F9E8:
    // 0x8009F9E8: bne         $a3, $zero, L_8009FA10
    if (ctx->r7 != 0) {
        // 0x8009F9EC: nop
    
            goto L_8009FA10;
    }
    // 0x8009F9EC: nop

    // 0x8009F9F0: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8009F9F4: nop

    // 0x8009F9F8: addiu       $t7, $t6, 0x3C
    ctx->r15 = ADD32(ctx->r14, 0X3C);
    // 0x8009F9FC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8009FA00: nop

    // 0x8009FA04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009FA08: b           L_8009FA2C
    // 0x8009FA0C: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
        goto L_8009FA2C;
    // 0x8009FA0C: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
L_8009FA10:
    // 0x8009FA10: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x8009FA14: nop

    // 0x8009FA18: addiu       $t8, $t9, -0x30
    ctx->r24 = ADD32(ctx->r25, -0X30);
    // 0x8009FA1C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8009FA20: nop

    // 0x8009FA24: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009FA28: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
L_8009FA2C:
    // 0x8009FA2C: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x8009FA30: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8009FA34: bne         $t2, $a0, L_8009F954
    if (ctx->r10 != ctx->r4) {
        // 0x8009FA38: nop
    
            goto L_8009F954;
    }
    // 0x8009FA38: nop

L_8009FA3C:
    // 0x8009FA3C: lwc1        $f4, -0x73C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X73C8);
    // 0x8009FA40: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA44: lui         $at, 0x4377
    ctx->r1 = S32(0X4377 << 16);
    // 0x8009FA48: swc1        $f4, 0x64C($t6)
    MEM_W(0X64C, ctx->r14) = ctx->f4.u32l;
    // 0x8009FA4C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009FA54: swc1        $f0, 0x650($t7)
    MEM_W(0X650, ctx->r15) = ctx->f0.u32l;
    // 0x8009FA58: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA5C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8009FA60: swc1        $f6, 0x40C($t9)
    MEM_W(0X40C, ctx->r25) = ctx->f6.u32l;
    // 0x8009FA64: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009FA6C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009FA70: swc1        $f8, 0x410($t8)
    MEM_W(0X410, ctx->r24) = ctx->f8.u32l;
    // 0x8009FA74: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA78: lwc1        $f10, -0x73C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X73C4);
    // 0x8009FA7C: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x8009FA80: swc1        $f10, 0x66C($t6)
    MEM_W(0X66C, ctx->r14) = ctx->f10.u32l;
    // 0x8009FA84: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009FA8C: lui         $at, 0x42CE
    ctx->r1 = S32(0X42CE << 16);
    // 0x8009FA90: swc1        $f4, 0x670($t7)
    MEM_W(0X670, ctx->r15) = ctx->f4.u32l;
    // 0x8009FA94: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FA98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009FA9C: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x8009FAA0: swc1        $f6, 0x68C($t9)
    MEM_W(0X68C, ctx->r25) = ctx->f6.u32l;
    // 0x8009FAA4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009FAAC: lui         $at, 0x4384
    ctx->r1 = S32(0X4384 << 16);
    // 0x8009FAB0: swc1        $f8, 0x690($t8)
    MEM_W(0X690, ctx->r24) = ctx->f8.u32l;
    // 0x8009FAB4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009FABC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8009FAC0: swc1        $f10, 0x6AC($t6)
    MEM_W(0X6AC, ctx->r14) = ctx->f10.u32l;
    // 0x8009FAC4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009FACC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009FAD0: swc1        $f4, 0x6B0($t7)
    MEM_W(0X6B0, ctx->r15) = ctx->f4.u32l;
    // 0x8009FAD4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAD8: lwc1        $f6, -0x73C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73C0);
    // 0x8009FADC: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x8009FAE0: swc1        $f6, 0x6CC($t9)
    MEM_W(0X6CC, ctx->r25) = ctx->f6.u32l;
    // 0x8009FAE4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009FAEC: lui         $at, 0x4389
    ctx->r1 = S32(0X4389 << 16);
    // 0x8009FAF0: swc1        $f8, 0x6D0($t8)
    MEM_W(0X6D0, ctx->r24) = ctx->f8.u32l;
    // 0x8009FAF4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FAF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009FAFC: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x8009FB00: swc1        $f10, 0x6EC($t6)
    MEM_W(0X6EC, ctx->r14) = ctx->f10.u32l;
    // 0x8009FB04: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009FB0C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009FB10: swc1        $f4, 0x6F0($t7)
    MEM_W(0X6F0, ctx->r15) = ctx->f4.u32l;
    // 0x8009FB14: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB18: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009FB1C: swc1        $f0, 0x650($t9)
    MEM_W(0X650, ctx->r25) = ctx->f0.u32l;
    // 0x8009FB20: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB24: nop

    // 0x8009FB28: sb          $t8, 0x5DC($t6)
    MEM_B(0X5DC, ctx->r14) = ctx->r24;
    // 0x8009FB2C: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x8009FB30: b           L_8009FCFC
    // 0x8009FB34: nop

        goto L_8009FCFC;
    // 0x8009FB34: nop

L_8009FB38:
    // 0x8009FB38: beq         $t3, $v1, L_8009FB44
    if (ctx->r11 == ctx->r3) {
        // 0x8009FB3C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8009FB44;
    }
    // 0x8009FB3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009FB40: bne         $v1, $at, L_8009FCFC
    if (ctx->r3 != ctx->r1) {
        // 0x8009FB44: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8009FCFC;
    }
L_8009FB44:
    // 0x8009FB44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009FB48: addiu       $v0, $a0, 0x2C04
    ctx->r2 = ADD32(ctx->r4, 0X2C04);
    // 0x8009FB4C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8009FB50: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009FB54: beq         $t2, $t7, L_8009FCFC
    if (ctx->r10 == ctx->r15) {
        // 0x8009FB58: addiu       $t9, $t9, 0x2C04
        ctx->r25 = ADD32(ctx->r25, 0X2C04);
            goto L_8009FCFC;
    }
    // 0x8009FB58: addiu       $t9, $t9, 0x2C04
    ctx->r25 = ADD32(ctx->r25, 0X2C04);
    // 0x8009FB5C: lh          $v1, 0x0($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X0);
    // 0x8009FB60: nop

L_8009FB64:
    // 0x8009FB64: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FB68: sll         $t6, $v1, 5
    ctx->r14 = S32(ctx->r3 << 5);
    // 0x8009FB6C: addu        $a0, $t8, $t6
    ctx->r4 = ADD32(ctx->r24, ctx->r14);
    // 0x8009FB70: lh          $t9, 0x6($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X6);
    // 0x8009FB74: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8009FB78: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8009FB7C: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8009FB80: lh          $t9, 0x0($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X0);
    // 0x8009FB84: nop

    // 0x8009FB88: andi        $t7, $t9, 0xC000
    ctx->r15 = ctx->r25 & 0XC000;
    // 0x8009FB8C: bne         $t0, $t7, L_8009FC38
    if (ctx->r8 != ctx->r15) {
        // 0x8009FB90: nop
    
            goto L_8009FC38;
    }
    // 0x8009FB90: nop

    // 0x8009FB94: beq         $a3, $zero, L_8009FBA4
    if (ctx->r7 == 0) {
        // 0x8009FB98: nop
    
            goto L_8009FBA4;
    }
    // 0x8009FB98: nop

    // 0x8009FB9C: bne         $a3, $t3, L_8009FBC0
    if (ctx->r7 != ctx->r11) {
        // 0x8009FBA0: nop
    
            goto L_8009FBC0;
    }
    // 0x8009FBA0: nop

L_8009FBA4:
    // 0x8009FBA4: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8009FBA8: nop

    // 0x8009FBAC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8009FBB0: nop

    // 0x8009FBB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009FBB8: b           L_8009FBDC
    // 0x8009FBBC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
        goto L_8009FBDC;
    // 0x8009FBBC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
L_8009FBC0:
    // 0x8009FBC0: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x8009FBC4: nop

    // 0x8009FBC8: addiu       $t9, $t6, 0xA0
    ctx->r25 = ADD32(ctx->r14, 0XA0);
    // 0x8009FBCC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8009FBD0: nop

    // 0x8009FBD4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009FBD8: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_8009FBDC:
    // 0x8009FBDC: beq         $a3, $zero, L_8009FBEC
    if (ctx->r7 == 0) {
        // 0x8009FBE0: nop
    
            goto L_8009FBEC;
    }
    // 0x8009FBE0: nop

    // 0x8009FBE4: bne         $a3, $t4, L_8009FC10
    if (ctx->r7 != ctx->r12) {
        // 0x8009FBE8: nop
    
            goto L_8009FC10;
    }
    // 0x8009FBE8: nop

L_8009FBEC:
    // 0x8009FBEC: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009FBF0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8009FBF4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8009FBF8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FBFC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009FC00: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x8009FC04: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x8009FC08: b           L_8009FCE0
    // 0x8009FC0C: swc1        $f8, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f8.u32l;
        goto L_8009FCE0;
    // 0x8009FC0C: swc1        $f8, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f8.u32l;
L_8009FC10:
    // 0x8009FC10: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8009FC14: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8009FC18: addiu       $t8, $t6, 0x6C
    ctx->r24 = ADD32(ctx->r14, 0X6C);
    // 0x8009FC1C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8009FC20: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FC24: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009FC28: sll         $t6, $t7, 5
    ctx->r14 = S32(ctx->r15 << 5);
    // 0x8009FC2C: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8009FC30: b           L_8009FCE0
    // 0x8009FC34: swc1        $f4, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f4.u32l;
        goto L_8009FCE0;
    // 0x8009FC34: swc1        $f4, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f4.u32l;
L_8009FC38:
    // 0x8009FC38: beq         $a3, $zero, L_8009FC48
    if (ctx->r7 == 0) {
        // 0x8009FC3C: nop
    
            goto L_8009FC48;
    }
    // 0x8009FC3C: nop

    // 0x8009FC40: bne         $a3, $t3, L_8009FC68
    if (ctx->r7 != ctx->r11) {
        // 0x8009FC44: nop
    
            goto L_8009FC68;
    }
    // 0x8009FC44: nop

L_8009FC48:
    // 0x8009FC48: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8009FC4C: nop

    // 0x8009FC50: addiu       $t9, $t7, -0x50
    ctx->r25 = ADD32(ctx->r15, -0X50);
    // 0x8009FC54: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8009FC58: nop

    // 0x8009FC5C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009FC60: b           L_8009FC84
    // 0x8009FC64: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
        goto L_8009FC84;
    // 0x8009FC64: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
L_8009FC68:
    // 0x8009FC68: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x8009FC6C: nop

    // 0x8009FC70: addiu       $t8, $t6, 0x50
    ctx->r24 = ADD32(ctx->r14, 0X50);
    // 0x8009FC74: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8009FC78: nop

    // 0x8009FC7C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009FC80: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_8009FC84:
    // 0x8009FC84: beq         $a3, $zero, L_8009FC94
    if (ctx->r7 == 0) {
        // 0x8009FC88: nop
    
            goto L_8009FC94;
    }
    // 0x8009FC88: nop

    // 0x8009FC8C: bne         $a3, $t4, L_8009FCBC
    if (ctx->r7 != ctx->r12) {
        // 0x8009FC90: nop
    
            goto L_8009FCBC;
    }
    // 0x8009FC90: nop

L_8009FC94:
    // 0x8009FC94: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8009FC98: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8009FC9C: addiu       $t9, $t7, 0x3C
    ctx->r25 = ADD32(ctx->r15, 0X3C);
    // 0x8009FCA0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8009FCA4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FCA8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009FCAC: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x8009FCB0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8009FCB4: b           L_8009FCE0
    // 0x8009FCB8: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
        goto L_8009FCE0;
    // 0x8009FCB8: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
L_8009FCBC:
    // 0x8009FCBC: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8009FCC0: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8009FCC4: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x8009FCC8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8009FCCC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FCD0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009FCD4: sll         $t8, $t9, 5
    ctx->r24 = S32(ctx->r25 << 5);
    // 0x8009FCD8: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8009FCDC: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
L_8009FCE0:
    // 0x8009FCE0: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x8009FCE4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8009FCE8: bne         $t2, $v1, L_8009FB64
    if (ctx->r10 != ctx->r3) {
        // 0x8009FCEC: nop
    
            goto L_8009FB64;
    }
    // 0x8009FCEC: nop

    // 0x8009FCF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009FCF4: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x8009FCF8: nop

L_8009FCFC:
    // 0x8009FCFC: beq         $v1, $zero, L_8009FE18
    if (ctx->r3 == 0) {
        // 0x8009FD00: nop
    
            goto L_8009FE18;
    }
    // 0x8009FD00: nop

    // 0x8009FD04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8009FD08:
    // 0x8009FD08: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FD0C: nop

    // 0x8009FD10: addu        $a0, $t9, $v1
    ctx->r4 = ADD32(ctx->r25, ctx->r3);
    // 0x8009FD14: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x8009FD18: nop

    // 0x8009FD1C: bne         $t5, $v0, L_8009FD2C
    if (ctx->r13 != ctx->r2) {
        // 0x8009FD20: nop
    
            goto L_8009FD2C;
    }
    // 0x8009FD20: nop

    // 0x8009FD24: b           L_8009FE00
    // 0x8009FD28: sh          $s1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r17;
        goto L_8009FE00;
    // 0x8009FD28: sh          $s1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r17;
L_8009FD2C:
    // 0x8009FD2C: bne         $s3, $v0, L_8009FD3C
    if (ctx->r19 != ctx->r2) {
        // 0x8009FD30: nop
    
            goto L_8009FD3C;
    }
    // 0x8009FD30: nop

    // 0x8009FD34: b           L_8009FE00
    // 0x8009FD38: sh          $s4, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r20;
        goto L_8009FE00;
    // 0x8009FD38: sh          $s4, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r20;
L_8009FD3C:
    // 0x8009FD3C: bne         $s5, $v0, L_8009FD4C
    if (ctx->r21 != ctx->r2) {
        // 0x8009FD40: nop
    
            goto L_8009FD4C;
    }
    // 0x8009FD40: nop

    // 0x8009FD44: b           L_8009FE00
    // 0x8009FD48: sh          $s6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r22;
        goto L_8009FE00;
    // 0x8009FD48: sh          $s6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r22;
L_8009FD4C:
    // 0x8009FD4C: bne         $ra, $v0, L_8009FD5C
    if (ctx->r31 != ctx->r2) {
        // 0x8009FD50: nop
    
            goto L_8009FD5C;
    }
    // 0x8009FD50: nop

    // 0x8009FD54: b           L_8009FE00
    // 0x8009FD58: sh          $s7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r23;
        goto L_8009FE00;
    // 0x8009FD58: sh          $s7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r23;
L_8009FD5C:
    // 0x8009FD5C: bne         $fp, $v0, L_8009FD80
    if (ctx->r30 != ctx->r2) {
        // 0x8009FD60: nop
    
            goto L_8009FD80;
    }
    // 0x8009FD60: nop

    // 0x8009FD64: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8009FD68: nop

    // 0x8009FD6C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009FD70: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x8009FD74: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8009FD78: b           L_8009FE00
    // 0x8009FD7C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
        goto L_8009FE00;
    // 0x8009FD7C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_8009FD80:
    // 0x8009FD80: beq         $v1, $zero, L_8009FE00
    if (ctx->r3 == 0) {
        // 0x8009FD84: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_8009FE00;
    }
    // 0x8009FD84: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8009FD88: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FD8C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8009FE00;
    }
    // 0x8009FD8C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8009FD90: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FD94: addiu       $at, $zero, 0x4A0
        ctx->r1 = ADD32(0, 0X4A0);
            goto L_8009FE00;
    }
    // 0x8009FD94: addiu       $at, $zero, 0x4A0
    ctx->r1 = ADD32(0, 0X4A0);
    // 0x8009FD98: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FD9C: addiu       $at, $zero, 0x5E0
        ctx->r1 = ADD32(0, 0X5E0);
            goto L_8009FE00;
    }
    // 0x8009FD9C: addiu       $at, $zero, 0x5E0
    ctx->r1 = ADD32(0, 0X5E0);
    // 0x8009FDA0: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDA4: addiu       $at, $zero, 0x600
        ctx->r1 = ADD32(0, 0X600);
            goto L_8009FE00;
    }
    // 0x8009FDA4: addiu       $at, $zero, 0x600
    ctx->r1 = ADD32(0, 0X600);
    // 0x8009FDA8: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDAC: addiu       $at, $zero, 0x60
        ctx->r1 = ADD32(0, 0X60);
            goto L_8009FE00;
    }
    // 0x8009FDAC: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x8009FDB0: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDB4: addiu       $at, $zero, 0x640
        ctx->r1 = ADD32(0, 0X640);
            goto L_8009FE00;
    }
    // 0x8009FDB4: addiu       $at, $zero, 0x640
    ctx->r1 = ADD32(0, 0X640);
    // 0x8009FDB8: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDBC: addiu       $at, $zero, 0x660
        ctx->r1 = ADD32(0, 0X660);
            goto L_8009FE00;
    }
    // 0x8009FDBC: addiu       $at, $zero, 0x660
    ctx->r1 = ADD32(0, 0X660);
    // 0x8009FDC0: beq         $v1, $at, L_8009FE00
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDC4: slti        $at, $v1, 0x680
        ctx->r1 = SIGNED(ctx->r3) < 0X680 ? 1 : 0;
            goto L_8009FE00;
    }
    // 0x8009FDC4: slti        $at, $v1, 0x680
    ctx->r1 = SIGNED(ctx->r3) < 0X680 ? 1 : 0;
    // 0x8009FDC8: bne         $at, $zero, L_8009FDE8
    if (ctx->r1 != 0) {
        // 0x8009FDCC: slti        $at, $v1, 0x700
        ctx->r1 = SIGNED(ctx->r3) < 0X700 ? 1 : 0;
            goto L_8009FDE8;
    }
    // 0x8009FDCC: slti        $at, $v1, 0x700
    ctx->r1 = SIGNED(ctx->r3) < 0X700 ? 1 : 0;
    // 0x8009FDD0: beq         $at, $zero, L_8009FDE8
    if (ctx->r1 == 0) {
        // 0x8009FDD4: addiu       $at, $zero, 0x380
        ctx->r1 = ADD32(0, 0X380);
            goto L_8009FDE8;
    }
    // 0x8009FDD4: addiu       $at, $zero, 0x380
    ctx->r1 = ADD32(0, 0X380);
    // 0x8009FDD8: beq         $v1, $at, L_8009FDE8
    if (ctx->r3 == ctx->r1) {
        // 0x8009FDDC: addiu       $at, $zero, 0x120
        ctx->r1 = ADD32(0, 0X120);
            goto L_8009FDE8;
    }
    // 0x8009FDDC: addiu       $at, $zero, 0x120
    ctx->r1 = ADD32(0, 0X120);
    // 0x8009FDE0: bne         $v1, $at, L_8009FE00
    if (ctx->r3 != ctx->r1) {
        // 0x8009FDE4: nop
    
            goto L_8009FE00;
    }
    // 0x8009FDE4: nop

L_8009FDE8:
    // 0x8009FDE8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8009FDEC: nop

    // 0x8009FDF0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8009FDF4: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8009FDF8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8009FDFC: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_8009FE00:
    // 0x8009FE00: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8009FE04: bne         $v1, $s2, L_8009FD08
    if (ctx->r3 != ctx->r18) {
        // 0x8009FE08: nop
    
            goto L_8009FD08;
    }
    // 0x8009FE08: nop

    // 0x8009FE0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009FE10: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x8009FE14: nop

L_8009FE18:
    // 0x8009FE18: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE1C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8009FE20: bne         $at, $zero, L_8009FEE0
    if (ctx->r1 != 0) {
        // 0x8009FE24: nop
    
            goto L_8009FEE0;
    }
    // 0x8009FE24: nop

    // 0x8009FE28: swc1        $f22, 0x3C8($a0)
    MEM_W(0X3C8, ctx->r4) = ctx->f22.u32l;
    // 0x8009FE2C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE30: nop

    // 0x8009FE34: swc1        $f22, 0x3E8($t7)
    MEM_W(0X3E8, ctx->r15) = ctx->f22.u32l;
    // 0x8009FE38: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE3C: nop

    // 0x8009FE40: swc1        $f22, 0x3A8($t8)
    MEM_W(0X3A8, ctx->r24) = ctx->f22.u32l;
    // 0x8009FE44: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE48: nop

    // 0x8009FE4C: swc1        $f22, 0x188($t6)
    MEM_W(0X188, ctx->r14) = ctx->f22.u32l;
    // 0x8009FE50: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE54: nop

    // 0x8009FE58: swc1        $f22, 0x1A8($t9)
    MEM_W(0X1A8, ctx->r25) = ctx->f22.u32l;
    // 0x8009FE5C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE60: addiu       $t9, $zero, 0x26
    ctx->r25 = ADD32(0, 0X26);
    // 0x8009FE64: swc1        $f22, 0x468($t7)
    MEM_W(0X468, ctx->r15) = ctx->f22.u32l;
    // 0x8009FE68: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE6C: nop

    // 0x8009FE70: swc1        $f22, 0x488($t8)
    MEM_W(0X488, ctx->r24) = ctx->f22.u32l;
    // 0x8009FE74: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE78: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x8009FE7C: swc1        $f22, 0x1C8($t6)
    MEM_W(0X1C8, ctx->r14) = ctx->f22.u32l;
    // 0x8009FE80: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE84: nop

    // 0x8009FE88: sh          $t9, 0x3C6($t7)
    MEM_H(0X3C6, ctx->r15) = ctx->r25;
    // 0x8009FE8C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE90: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x8009FE94: sh          $t8, 0x3E6($t6)
    MEM_H(0X3E6, ctx->r14) = ctx->r24;
    // 0x8009FE98: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FE9C: addiu       $t8, $zero, 0x25
    ctx->r24 = ADD32(0, 0X25);
    // 0x8009FEA0: sh          $t9, 0x3A6($t7)
    MEM_H(0X3A6, ctx->r15) = ctx->r25;
    // 0x8009FEA4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FEA8: addiu       $t9, $zero, 0x27
    ctx->r25 = ADD32(0, 0X27);
    // 0x8009FEAC: sh          $t8, 0x186($t6)
    MEM_H(0X186, ctx->r14) = ctx->r24;
    // 0x8009FEB0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FEB4: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x8009FEB8: sh          $t9, 0x1A6($t7)
    MEM_H(0X1A6, ctx->r15) = ctx->r25;
    // 0x8009FEBC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FEC0: addiu       $t9, $zero, 0x2C
    ctx->r25 = ADD32(0, 0X2C);
    // 0x8009FEC4: sh          $t8, 0x466($t6)
    MEM_H(0X466, ctx->r14) = ctx->r24;
    // 0x8009FEC8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009FECC: addiu       $t8, $zero, 0x2A
    ctx->r24 = ADD32(0, 0X2A);
    // 0x8009FED0: sh          $t9, 0x486($t7)
    MEM_H(0X486, ctx->r15) = ctx->r25;
    // 0x8009FED4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8009FED8: b           L_8009FEF0
    // 0x8009FEDC: sh          $t8, 0x1C6($t6)
    MEM_H(0X1C6, ctx->r14) = ctx->r24;
        goto L_8009FEF0;
    // 0x8009FEDC: sh          $t8, 0x1C6($t6)
    MEM_H(0X1C6, ctx->r14) = ctx->r24;
L_8009FEE0:
    // 0x8009FEE0: sb          $t4, 0x5D($a0)
    MEM_B(0X5D, ctx->r4) = ctx->r12;
    // 0x8009FEE4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8009FEE8: nop

    // 0x8009FEEC: sb          $t4, 0x37D($t9)
    MEM_B(0X37D, ctx->r25) = ctx->r12;
L_8009FEF0:
    // 0x8009FEF0: jal         0x8000E4D8
    // 0x8009FEF4: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    is_in_time_trial(rdram, ctx);
        goto after_4;
    // 0x8009FEF4: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_4:
    // 0x8009FEF8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009FEFC: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8009FF00: beq         $v0, $zero, L_800A0010
    if (ctx->r2 == 0) {
        // 0x8009FF04: addiu       $a1, $a1, 0x729C
        ctx->r5 = ADD32(ctx->r5, 0X729C);
            goto L_800A0010;
    }
    // 0x8009FF04: addiu       $a1, $a1, 0x729C
    ctx->r5 = ADD32(ctx->r5, 0X729C);
    // 0x8009FF08: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF0C: nop

    // 0x8009FF10: lwc1        $f6, 0xEC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8009FF14: nop

    // 0x8009FF18: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8009FF1C: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x8009FF20: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF24: nop

    // 0x8009FF28: lwc1        $f10, 0x10C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x8009FF2C: nop

    // 0x8009FF30: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8009FF34: swc1        $f4, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FF38: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF3C: nop

    // 0x8009FF40: lwc1        $f6, 0x12C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x8009FF44: nop

    // 0x8009FF48: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8009FF4C: swc1        $f8, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FF50: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF54: nop

    // 0x8009FF58: lwc1        $f10, 0x38C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38C);
    // 0x8009FF5C: nop

    // 0x8009FF60: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8009FF64: swc1        $f4, 0x38C($a0)
    MEM_W(0X38C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FF68: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF6C: nop

    // 0x8009FF70: lwc1        $f6, 0x36C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X36C);
    // 0x8009FF74: nop

    // 0x8009FF78: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8009FF7C: swc1        $f8, 0x36C($a0)
    MEM_W(0X36C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FF80: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF84: nop

    // 0x8009FF88: lwc1        $f10, 0x24C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24C);
    // 0x8009FF8C: nop

    // 0x8009FF90: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8009FF94: swc1        $f4, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FF98: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FF9C: nop

    // 0x8009FFA0: lwc1        $f6, 0x8C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8009FFA4: nop

    // 0x8009FFA8: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8009FFAC: swc1        $f8, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f8.u32l;
    // 0x8009FFB0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FFB4: nop

    // 0x8009FFB8: lwc1        $f10, 0xAC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x8009FFBC: nop

    // 0x8009FFC0: add.s       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8009FFC4: swc1        $f4, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f4.u32l;
    // 0x8009FFC8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FFCC: nop

    // 0x8009FFD0: lwc1        $f6, 0xCC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x8009FFD4: nop

    // 0x8009FFD8: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8009FFDC: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
    // 0x8009FFE0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FFE4: nop

    // 0x8009FFE8: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8009FFEC: nop

    // 0x8009FFF0: add.s       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8009FFF4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8009FFF8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8009FFFC: nop

    // 0x800A0000: lwc1        $f6, 0x20C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20C);
    // 0x800A0004: nop

    // 0x800A0008: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x800A000C: swc1        $f8, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f8.u32l;
L_800A0010:
    // 0x800A0010: jal         0x8006BFD8
    // 0x800A0014: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    level_type(rdram, ctx);
        goto after_5;
    // 0x800A0014: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_5:
    // 0x800A0018: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A001C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A0020: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A0024: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0028: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x800A002C: addiu       $a1, $a1, 0x729C
    ctx->r5 = ADD32(ctx->r5, 0X729C);
    // 0x800A0030: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800A0034: beq         $v0, $at, L_800A0050
    if (ctx->r2 == ctx->r1) {
        // 0x800A0038: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800A0050;
    }
    // 0x800A0038: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A003C: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A0040: beq         $v0, $at, L_800A015C
    if (ctx->r2 == ctx->r1) {
        // 0x800A0044: lui         $t7, 0x8000
        ctx->r15 = S32(0X8000 << 16);
            goto L_800A015C;
    }
    // 0x800A0044: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800A0048: b           L_800A0260
    // 0x800A004C: nop

        goto L_800A0260;
    // 0x800A004C: nop

L_800A0050:
    // 0x800A0050: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0054: nop

    // 0x800A0058: lwc1        $f10, 0xEC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x800A005C: nop

    // 0x800A0060: add.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x800A0064: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x800A0068: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A006C: nop

    // 0x800A0070: lwc1        $f6, 0x10C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x800A0074: nop

    // 0x800A0078: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x800A007C: swc1        $f8, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f8.u32l;
    // 0x800A0080: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0084: nop

    // 0x800A0088: lwc1        $f10, 0x12C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x800A008C: nop

    // 0x800A0090: add.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x800A0094: swc1        $f4, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f4.u32l;
    // 0x800A0098: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A009C: nop

    // 0x800A00A0: lwc1        $f6, 0x38C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X38C);
    // 0x800A00A4: nop

    // 0x800A00A8: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x800A00AC: swc1        $f8, 0x38C($a0)
    MEM_W(0X38C, ctx->r4) = ctx->f8.u32l;
    // 0x800A00B0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A00B4: nop

    // 0x800A00B8: lwc1        $f10, 0x36C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X36C);
    // 0x800A00BC: nop

    // 0x800A00C0: add.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x800A00C4: swc1        $f4, 0x36C($a0)
    MEM_W(0X36C, ctx->r4) = ctx->f4.u32l;
    // 0x800A00C8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A00CC: nop

    // 0x800A00D0: lwc1        $f6, 0x24C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24C);
    // 0x800A00D4: nop

    // 0x800A00D8: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x800A00DC: swc1        $f8, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f8.u32l;
    // 0x800A00E0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A00E4: nop

    // 0x800A00E8: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800A00EC: nop

    // 0x800A00F0: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x800A00F4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x800A00F8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A00FC: nop

    // 0x800A0100: lwc1        $f6, 0x8C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x800A0104: nop

    // 0x800A0108: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800A010C: swc1        $f8, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f8.u32l;
    // 0x800A0110: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0114: nop

    // 0x800A0118: lwc1        $f10, 0xAC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x800A011C: nop

    // 0x800A0120: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x800A0124: swc1        $f4, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f4.u32l;
    // 0x800A0128: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A012C: nop

    // 0x800A0130: lwc1        $f6, 0xCC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x800A0134: nop

    // 0x800A0138: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800A013C: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
    // 0x800A0140: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0144: nop

    // 0x800A0148: lwc1        $f10, 0x20C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20C);
    // 0x800A014C: nop

    // 0x800A0150: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x800A0154: b           L_800A0260
    // 0x800A0158: swc1        $f4, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f4.u32l;
        goto L_800A0260;
    // 0x800A0158: swc1        $f4, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f4.u32l;
L_800A015C:
    // 0x800A015C: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800A0160: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0164: bne         $t7, $zero, L_800A0184
    if (ctx->r15 != 0) {
        // 0x800A0168: nop
    
            goto L_800A0184;
    }
    // 0x800A0168: nop

    // 0x800A016C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0170: nop

    // 0x800A0174: lwc1        $f6, 0x410($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X410);
    // 0x800A0178: nop

    // 0x800A017C: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800A0180: swc1        $f8, 0x410($a0)
    MEM_W(0X410, ctx->r4) = ctx->f8.u32l;
L_800A0184:
    // 0x800A0184: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A0188: nop

    // 0x800A018C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800A0190: bne         $at, $zero, L_800A01B8
    if (ctx->r1 != 0) {
        // 0x800A0194: nop
    
            goto L_800A01B8;
    }
    // 0x800A0194: nop

    // 0x800A0198: beq         $a3, $zero, L_800A01A8
    if (ctx->r7 == 0) {
        // 0x800A019C: nop
    
            goto L_800A01A8;
    }
    // 0x800A019C: nop

    // 0x800A01A0: bne         $a3, $t3, L_800A01B0
    if (ctx->r7 != ctx->r11) {
        // 0x800A01A4: nop
    
            goto L_800A01B0;
    }
    // 0x800A01A4: nop

L_800A01A8:
    // 0x800A01A8: b           L_800A01CC
    // 0x800A01AC: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
        goto L_800A01CC;
    // 0x800A01AC: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_800A01B0:
    // 0x800A01B0: b           L_800A01CC
    // 0x800A01B4: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
        goto L_800A01CC;
    // 0x800A01B4: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
L_800A01B8:
    // 0x800A01B8: bne         $t4, $v0, L_800A01CC
    if (ctx->r12 != ctx->r2) {
        // 0x800A01BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A01CC;
    }
    // 0x800A01BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A01C0: b           L_800A01CC
    // 0x800A01C4: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
        goto L_800A01CC;
    // 0x800A01C4: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
    // 0x800A01C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A01CC:
    // 0x800A01CC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800A01D0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A01D4: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A01D8: lwc1        $f4, 0x36C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X36C);
    // 0x800A01DC: nop

    // 0x800A01E0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A01E4: swc1        $f6, 0x36C($a0)
    MEM_W(0X36C, ctx->r4) = ctx->f6.u32l;
    // 0x800A01E8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A01EC: nop

    // 0x800A01F0: lwc1        $f8, 0xEC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x800A01F4: nop

    // 0x800A01F8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A01FC: swc1        $f10, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f10.u32l;
    // 0x800A0200: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0204: nop

    // 0x800A0208: lwc1        $f4, 0x10C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x800A020C: nop

    // 0x800A0210: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A0214: swc1        $f6, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f6.u32l;
    // 0x800A0218: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A021C: nop

    // 0x800A0220: lwc1        $f8, 0x12C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x800A0224: nop

    // 0x800A0228: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A022C: swc1        $f10, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->f10.u32l;
    // 0x800A0230: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0234: nop

    // 0x800A0238: lwc1        $f4, 0x38C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38C);
    // 0x800A023C: nop

    // 0x800A0240: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A0244: swc1        $f6, 0x38C($a0)
    MEM_W(0X38C, ctx->r4) = ctx->f6.u32l;
    // 0x800A0248: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A024C: nop

    // 0x800A0250: lwc1        $f8, 0x24C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24C);
    // 0x800A0254: nop

    // 0x800A0258: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A025C: swc1        $f10, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f10.u32l;
L_800A0260:
    // 0x800A0260: jal         0x80023450
    // 0x800A0264: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    is_taj_challenge(rdram, ctx);
        goto after_6;
    // 0x800A0264: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    after_6:
    // 0x800A0268: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A026C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A0270: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A0274: lwc1        $f13, -0x7398($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, -0X7398);
    // 0x800A0278: lwc1        $f12, -0x7394($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7394);
    // 0x800A027C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A0280: lwc1        $f15, -0x7390($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, -0X7390);
    // 0x800A0284: lwc1        $f14, -0x738C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X738C);
    // 0x800A0288: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x800A028C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A0290: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A0294: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A0298: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A029C: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x800A02A0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A02A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A02A8: addiu       $t1, $t1, 0x72B0
    ctx->r9 = ADD32(ctx->r9, 0X72B0);
    // 0x800A02AC: addiu       $a1, $a1, 0x729C
    ctx->r5 = ADD32(ctx->r5, 0X729C);
    // 0x800A02B0: ori         $t0, $zero, 0xC000
    ctx->r8 = 0 | 0XC000;
    // 0x800A02B4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800A02B8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800A02BC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A02C0: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x800A02C4: beq         $v0, $zero, L_800A0344
    if (ctx->r2 == 0) {
        // 0x800A02C8: addiu       $ra, $zero, 0x12
        ctx->r31 = ADD32(0, 0X12);
            goto L_800A0344;
    }
    // 0x800A02C8: addiu       $ra, $zero, 0x12
    ctx->r31 = ADD32(0, 0X12);
    // 0x800A02CC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A02D0: nop

    // 0x800A02D4: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800A02D8: nop

    // 0x800A02DC: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A02E0: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x800A02E4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A02E8: nop

    // 0x800A02EC: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x800A02F0: nop

    // 0x800A02F4: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A02F8: swc1        $f10, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f10.u32l;
    // 0x800A02FC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0300: nop

    // 0x800A0304: lwc1        $f4, 0xAC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x800A0308: nop

    // 0x800A030C: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A0310: swc1        $f6, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f6.u32l;
    // 0x800A0314: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0318: nop

    // 0x800A031C: lwc1        $f8, 0xCC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x800A0320: nop

    // 0x800A0324: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A0328: swc1        $f10, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f10.u32l;
    // 0x800A032C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A0330: nop

    // 0x800A0334: lwc1        $f4, 0x20C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20C);
    // 0x800A0338: nop

    // 0x800A033C: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800A0340: swc1        $f6, 0x20C($a0)
    MEM_W(0X20C, ctx->r4) = ctx->f6.u32l;
L_800A0344:
    // 0x800A0344: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800A0348: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800A034C: nop

    // 0x800A0350: bne         $t8, $zero, L_800A04A0
    if (ctx->r24 != 0) {
        // 0x800A0354: nop
    
            goto L_800A04A0;
    }
    // 0x800A0354: nop

    // 0x800A0358: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A035C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A0360: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
L_800A0364:
    // 0x800A0364: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A0368: nop

    // 0x800A036C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800A0370: mul.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x800A0374: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800A0378: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800A037C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A0380: nop

    // 0x800A0384: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x800A0388: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800A038C: nop

    // 0x800A0390: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800A0394: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x800A0398: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A039C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800A03A0: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800A03A4: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x800A03A8: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800A03AC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800A03B0: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800A03B4: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800A03B8: slti        $at, $v1, 0x760
    ctx->r1 = SIGNED(ctx->r3) < 0X760 ? 1 : 0;
    // 0x800A03BC: andi        $t9, $t7, 0xC000
    ctx->r25 = ctx->r15 & 0XC000;
    // 0x800A03C0: bne         $t0, $t9, L_800A03E0
    if (ctx->r8 != ctx->r25) {
        // 0x800A03C4: nop
    
            goto L_800A03E0;
    }
    // 0x800A03C4: nop

    // 0x800A03C8: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A03CC: nop

    // 0x800A03D0: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A03D4: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800A03D8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800A03DC: nop

L_800A03E0:
    // 0x800A03E0: bne         $at, $zero, L_800A0364
    if (ctx->r1 != 0) {
        // 0x800A03E4: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800A0364;
    }
    // 0x800A03E4: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800A03E8: addiu       $v0, $a0, 0x4E0
    ctx->r2 = ADD32(ctx->r4, 0X4E0);
    // 0x800A03EC: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A03F0: addiu       $a2, $zero, 0x2A
    ctx->r6 = ADD32(0, 0X2A);
    // 0x800A03F4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A03F8: sll         $v1, $a2, 5
    ctx->r3 = S32(ctx->r6 << 5);
    // 0x800A03FC: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x800A0400: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A0404: nop

    // 0x800A0408: lwc1        $f4, 0x510($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X510);
    // 0x800A040C: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
    // 0x800A0410: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A0414: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x800A0418: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A041C: nop

    // 0x800A0420: lwc1        $f8, 0x530($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X530);
    // 0x800A0424: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
    // 0x800A0428: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A042C: swc1        $f10, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f10.u32l;
    // 0x800A0430: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800A0434: nop

    // 0x800A0438: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x800A043C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A0440: nop

    // 0x800A0444: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A0448: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800A044C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A0450: nop

    // 0x800A0454: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x800A0458: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800A045C: nop

    // 0x800A0460: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A0464: swc1        $f10, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f10.u32l;
    // 0x800A0468: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A046C: nop

    // 0x800A0470: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x800A0474: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800A0478: nop

    // 0x800A047C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A0480: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
    // 0x800A0484: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A0488: nop

    // 0x800A048C: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x800A0490: lwc1        $f8, 0x70($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X70);
    // 0x800A0494: nop

    // 0x800A0498: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A049C: swc1        $f10, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f10.u32l;
L_800A04A0:
    // 0x800A04A0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800A04A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800A04A8: swc1        $f22, 0x268($t8)
    MEM_W(0X268, ctx->r24) = ctx->f22.u32l;
    // 0x800A04AC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A04B0: nop

    // 0x800A04B4: sh          $ra, 0x286($t6)
    MEM_H(0X286, ctx->r14) = ctx->r31;
    // 0x800A04B8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A04BC: nop

    // 0x800A04C0: sh          $t5, 0x2A6($t7)
    MEM_H(0X2A6, ctx->r15) = ctx->r13;
    // 0x800A04C4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A04C8: nop

    // 0x800A04CC: sh          $t5, 0x2C6($t9)
    MEM_H(0X2C6, ctx->r25) = ctx->r13;
    // 0x800A04D0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800A04D4: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x800A04D8: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800A04DC: bne         $a3, $t7, L_8009F818
    if (ctx->r7 != ctx->r15) {
        // 0x800A04E0: sw          $t6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r14;
            goto L_8009F818;
    }
    // 0x800A04E0: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_800A04E4:
    // 0x800A04E4: jal         0x8006BFD8
    // 0x800A04E8: nop

    level_type(rdram, ctx);
        goto after_7;
    // 0x800A04E8: nop

    after_7:
    // 0x800A04EC: andi        $t9, $v0, 0x40
    ctx->r25 = ctx->r2 & 0X40;
    // 0x800A04F0: beq         $t9, $zero, L_800A0514
    if (ctx->r25 == 0) {
        // 0x800A04F4: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800A0514;
    }
    // 0x800A04F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A04F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A04FC: addiu       $v0, $v0, 0x2D24
    ctx->r2 = ADD32(ctx->r2, 0X2D24);
    // 0x800A0500: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x800A0504: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A0508: sb          $t8, 0x2D28($at)
    MEM_B(0X2D28, ctx->r1) = ctx->r24;
    // 0x800A050C: b           L_800A0524
    // 0x800A0510: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
        goto L_800A0524;
    // 0x800A0510: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
L_800A0514:
    // 0x800A0514: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A0518: lb          $t6, 0x2D28($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X2D28);
    // 0x800A051C: addiu       $v0, $v0, 0x2D24
    ctx->r2 = ADD32(ctx->r2, 0X2D24);
    // 0x800A0520: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
L_800A0524:
    // 0x800A0524: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800A0528: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A052C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A0530: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800A0534: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A0538: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800A053C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A0540: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800A0544: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A0548: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800A054C: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A0550: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800A0554: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800A0558: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800A055C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800A0560: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800A0564: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800A0568: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800A056C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800A0570: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800A0574: jr          $ra
    // 0x800A0578: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800A0578: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void obj_shade_fancy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D718: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D71C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D720: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001D724: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001D728: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001D72C: lh          $t0, 0x28($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X28);
    // 0x8001D730: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8001D734: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001D738: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001D73C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001D740: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8001D744: blez        $t0, L_8001D7A8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001D748: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001D7A8;
    }
    // 0x8001D748: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001D74C: lw          $a2, 0x38($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X38);
    // 0x8001D750: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8001D754: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_8001D758:
    // 0x8001D758: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001D75C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001D760: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x8001D764: sra         $v1, $t2, 16
    ctx->r3 = S32(SIGNED(ctx->r10) >> 16);
    // 0x8001D768: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001D76C: mflo        $t6
    ctx->r14 = lo;
    // 0x8001D770: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x8001D774: lbu         $t7, 0x6($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X6);
    // 0x8001D778: nop

    // 0x8001D77C: beq         $a0, $t7, L_8001D788
    if (ctx->r4 == ctx->r15) {
        // 0x8001D780: nop
    
            goto L_8001D788;
    }
    // 0x8001D780: nop

    // 0x8001D784: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8001D788:
    // 0x8001D788: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8001D78C: nop

    // 0x8001D790: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001D794: beq         $t9, $zero, L_8001D7A0
    if (ctx->r25 == 0) {
        // 0x8001D798: nop
    
            goto L_8001D7A0;
    }
    // 0x8001D798: nop

    // 0x8001D79C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_8001D7A0:
    // 0x8001D7A0: bne         $at, $zero, L_8001D758
    if (ctx->r1 != 0) {
        // 0x8001D7A4: nop
    
            goto L_8001D758;
    }
    // 0x8001D7A4: nop

L_8001D7A8:
    // 0x8001D7A8: beq         $a3, $zero, L_8001D810
    if (ctx->r7 == 0) {
        // 0x8001D7AC: nop
    
            goto L_8001D810;
    }
    // 0x8001D7AC: nop

    // 0x8001D7B0: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x8001D7B4: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    // 0x8001D7B8: lbu         $t5, 0x71($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X71);
    // 0x8001D7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D7C0: beq         $t5, $zero, L_8001D7FC
    if (ctx->r13 == 0) {
        // 0x8001D7C4: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8001D7FC;
    }
    // 0x8001D7C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001D7C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D7CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D7D0: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    // 0x8001D7D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D7D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001D7DC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8001D7E0: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x8001D7E4: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    // 0x8001D7E8: jal         0x8001D840
    // 0x8001D7EC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    calc_dynamic_lighting_for_object_1(rdram, ctx);
        goto after_0;
    // 0x8001D7EC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001D7F0: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x8001D7F4: b           L_8001D810
    // 0x8001D7F8: nop

        goto L_8001D810;
    // 0x8001D7F8: nop

L_8001D7FC:
    // 0x8001D7FC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8001D800: jal         0x80024784
    // 0x8001D804: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    calc_dynamic_lighting_for_object_2(rdram, ctx);
        goto after_1;
    // 0x8001D804: sh          $t1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r9;
    after_1:
    // 0x8001D808: lh          $t1, 0x2E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2E);
    // 0x8001D80C: nop

L_8001D810:
    // 0x8001D810: beq         $t1, $zero, L_8001D830
    if (ctx->r9 == 0) {
        // 0x8001D814: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001D830;
    }
    // 0x8001D814: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D818: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x8001D81C: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x8001D820: lh          $a3, 0x0($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X0);
    // 0x8001D824: jal         0x8001DD88
    // 0x8001D828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    calc_env_mapping_for_object(rdram, ctx);
        goto after_2;
    // 0x8001D828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8001D82C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001D830:
    // 0x8001D830: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D834: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001D838: jr          $ra
    // 0x8001D83C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001D83C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void get_file_extension(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073EB4: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x80073EB8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80073EBC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80073EC0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80073EC4: sw          $a1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r5;
    // 0x80073EC8: sw          $a2, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r6;
    // 0x80073ECC: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x80073ED0: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x80073ED4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80073ED8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80073EDC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80073EE0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80073EE4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80073EE8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80073EEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80073EF0: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x80073EF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80073EF8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80073EFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80073F00: addiu       $a2, $sp, 0x100
    ctx->r6 = ADD32(ctx->r29, 0X100);
    // 0x80073F04: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80073F08: jal         0x800760B8
    // 0x80073F0C: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    get_controller_pak_file_list(rdram, ctx);
        goto after_0;
    // 0x80073F0C: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    after_0:
    // 0x80073F10: bne         $v0, $zero, L_80074040
    if (ctx->r2 != 0) {
        // 0x80073F14: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_80074040;
    }
    // 0x80073F14: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80073F18: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80073F1C: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80073F20: addiu       $s7, $s7, 0x7BD0
    ctx->r23 = ADD32(ctx->r23, 0X7BD0);
    // 0x80073F24: addiu       $fp, $fp, 0x7BC0
    ctx->r30 = ADD32(ctx->r30, 0X7BC0);
    // 0x80073F28: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80073F2C: addiu       $s0, $sp, 0x100
    ctx->r16 = ADD32(ctx->r29, 0X100);
    // 0x80073F30: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
    // 0x80073F34: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80073F38: addiu       $s5, $sp, 0x140
    ctx->r21 = ADD32(ctx->r29, 0X140);
L_80073F3C:
    // 0x80073F3C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80073F40: lw          $t9, 0x144($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X144);
    // 0x80073F44: beq         $t8, $zero, L_80073FD0
    if (ctx->r24 == 0) {
        // 0x80073F48: nop
    
            goto L_80073FD0;
    }
    // 0x80073F48: nop

    // 0x80073F4C: bne         $t9, $s6, L_80073F7C
    if (ctx->r25 != ctx->r22) {
        // 0x80073F50: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80073F7C;
    }
    // 0x80073F50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80073F54: jal         0x800CE6FC
    // 0x80073F58: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    strlen_recomp(rdram, ctx);
        goto after_1;
    // 0x80073F58: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x80073F5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80073F60: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80073F64: jal         0x800CE5B0
    // 0x80073F68: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _bcmp(rdram, ctx);
        goto after_2;
    // 0x80073F68: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80073F6C: beq         $v0, $zero, L_80073FA0
    if (ctx->r2 == 0) {
        // 0x80073F70: addu        $t0, $sp, $s3
        ctx->r8 = ADD32(ctx->r29, ctx->r19);
            goto L_80073FA0;
    }
    // 0x80073F70: addu        $t0, $sp, $s3
    ctx->r8 = ADD32(ctx->r29, ctx->r19);
    // 0x80073F74: b           L_80073FD4
    // 0x80073F78: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_80073FD4;
    // 0x80073F78: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80073F7C:
    // 0x80073F7C: jal         0x800CE6FC
    // 0x80073F80: addiu       $a0, $a0, 0x7BF0
    ctx->r4 = ADD32(ctx->r4, 0X7BF0);
    strlen_recomp(rdram, ctx);
        goto after_3;
    // 0x80073F80: addiu       $a0, $a0, 0x7BF0
    ctx->r4 = ADD32(ctx->r4, 0X7BF0);
    after_3:
    // 0x80073F84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80073F88: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80073F8C: addiu       $a1, $a1, 0x7BE0
    ctx->r5 = ADD32(ctx->r5, 0X7BE0);
    // 0x80073F90: jal         0x800CE5B0
    // 0x80073F94: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _bcmp(rdram, ctx);
        goto after_4;
    // 0x80073F94: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x80073F98: bne         $v0, $zero, L_80073FD0
    if (ctx->r2 != 0) {
        // 0x80073F9C: addu        $t0, $sp, $s3
        ctx->r8 = ADD32(ctx->r29, ctx->r19);
            goto L_80073FD0;
    }
    // 0x80073F9C: addu        $t0, $sp, $s3
    ctx->r8 = ADD32(ctx->r29, ctx->r19);
L_80073FA0:
    // 0x80073FA0: lw          $t0, 0xC0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XC0);
    // 0x80073FA4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80073FA8: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80073FAC: nop

    // 0x80073FB0: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80073FB4: beq         $at, $zero, L_80073FC4
    if (ctx->r1 == 0) {
        // 0x80073FB8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80073FC4;
    }
    // 0x80073FB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073FBC: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x80073FC0: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
L_80073FC4:
    // 0x80073FC4: addiu       $t1, $v1, 0x1F
    ctx->r9 = ADD32(ctx->r3, 0X1F);
    // 0x80073FC8: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80073FCC: or          $s1, $s1, $t3
    ctx->r17 = ctx->r17 | ctx->r11;
L_80073FD0:
    // 0x80073FD0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80073FD4:
    // 0x80073FD4: bne         $s0, $s5, L_80073F3C
    if (ctx->r16 != ctx->r21) {
        // 0x80073FD8: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80073F3C;
    }
    // 0x80073FD8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80073FDC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80073FE0: lw          $v0, 0x148($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X148);
    // 0x80073FE4: bne         $s4, $at, L_80073FF8
    if (ctx->r20 != ctx->r1) {
        // 0x80073FE8: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_80073FF8;
    }
    // 0x80073FE8: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80073FEC: b           L_80074038
    // 0x80073FF0: addiu       $s2, $zero, 0x41
    ctx->r18 = ADD32(0, 0X41);
        goto L_80074038;
    // 0x80073FF0: addiu       $s2, $zero, 0x41
    ctx->r18 = ADD32(0, 0X41);
    // 0x80073FF4: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
L_80073FF8:
    // 0x80073FF8: bne         $s4, $at, L_80074030
    if (ctx->r20 != ctx->r1) {
        // 0x80073FFC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80074030;
    }
    // 0x80073FFC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80074000: addiu       $s2, $zero, 0x41
    ctx->r18 = ADD32(0, 0X41);
L_80074004:
    // 0x80074004: andi        $t4, $s1, 0x1
    ctx->r12 = ctx->r17 & 0X1;
    // 0x80074008: beq         $t4, $zero, L_80074038
    if (ctx->r12 == 0) {
        // 0x8007400C: sra         $t5, $s1, 1
        ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
            goto L_80074038;
    }
    // 0x8007400C: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80074010: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80074014: andi        $t6, $s2, 0xFF
    ctx->r14 = ctx->r18 & 0XFF;
    // 0x80074018: slti        $at, $t6, 0x5B
    ctx->r1 = SIGNED(ctx->r14) < 0X5B ? 1 : 0;
    // 0x8007401C: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x80074020: bne         $at, $zero, L_80074004
    if (ctx->r1 != 0) {
        // 0x80074024: or          $s1, $t5, $zero
        ctx->r17 = ctx->r13 | 0;
            goto L_80074004;
    }
    // 0x80074024: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x80074028: b           L_8007403C
    // 0x8007402C: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
        goto L_8007403C;
    // 0x8007402C: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
L_80074030:
    // 0x80074030: andi        $t7, $s2, 0xFF
    ctx->r15 = ctx->r18 & 0XFF;
    // 0x80074034: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_80074038:
    // 0x80074038: sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
L_8007403C:
    // 0x8007403C: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
L_80074040:
    // 0x80074040: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80074044: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x80074048: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007404C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80074050: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80074054: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80074058: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8007405C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80074060: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80074064: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80074068: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8007406C: jr          $ra
    // 0x80074070: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x80074070: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void viewport_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800684EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800684F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800684F4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800684F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800684FC: sw          $t6, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->r14;
    // 0x80068500: jal         0x8007A970
    // 0x80068504: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80068504: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80068508: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006850C: lw          $t7, 0x1264($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1264);
    // 0x80068510: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80068514: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80068518: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8006851C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80068520: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80068524: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80068528: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006852C: lw          $t9, -0x29FC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X29FC);
    // 0x80068530: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80068534: andi        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 & 0X1;
    // 0x80068538: srl         $t0, $v0, 16
    ctx->r8 = S32(U32(ctx->r2) >> 16);
    // 0x8006853C: bne         $t2, $zero, L_80068614
    if (ctx->r10 != 0) {
        // 0x80068540: andi        $t1, $v0, 0xFFFF
        ctx->r9 = ctx->r2 & 0XFFFF;
            goto L_80068614;
    }
    // 0x80068540: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x80068544: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80068548: addiu       $t5, $t1, -0x1
    ctx->r13 = ADD32(ctx->r9, -0X1);
    // 0x8006854C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80068550: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80068554: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80068558: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006855C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80068560: lui         $t4, 0xED00
    ctx->r12 = S32(0XED00 << 16);
    // 0x80068564: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80068568: bgez        $t5, L_80068580
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8006856C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80068580;
    }
    // 0x8006856C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80068570: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80068574: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80068578: nop

    // 0x8006857C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80068580:
    // 0x80068580: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80068584: addiu       $t2, $t0, -0x1
    ctx->r10 = ADD32(ctx->r8, -0X1);
    // 0x80068588: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006858C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80068590: nop

    // 0x80068594: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80068598: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006859C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800685A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800685A4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800685A8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800685AC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800685B0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800685B4: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800685B8: bgez        $t2, L_800685CC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800685BC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800685CC;
    }
    // 0x800685BC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800685C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800685C4: nop

    // 0x800685C8: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800685CC:
    // 0x800685CC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800685D0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800685D4: srl         $a1, $t1, 1
    ctx->r5 = S32(U32(ctx->r9) >> 1);
    // 0x800685D8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800685DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800685E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800685E4: srl         $a2, $t0, 1
    ctx->r6 = S32(U32(ctx->r8) >> 1);
    // 0x800685E8: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800685EC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800685F0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800685F4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800685F8: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x800685FC: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x80068600: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80068604: jal         0x80068398
    // 0x80068608: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    viewport_rsp_set(rdram, ctx);
        goto after_1;
    // 0x80068608: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    after_1:
    // 0x8006860C: b           L_80068638
    // 0x80068610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80068638;
    // 0x80068610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80068614:
    // 0x80068614: jal         0x80067C7C
    // 0x80068618: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    viewport_scissor(rdram, ctx);
        goto after_2;
    // 0x80068618: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x8006861C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80068620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068624: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80068628: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006862C: jal         0x80068398
    // 0x80068630: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    viewport_rsp_set(rdram, ctx);
        goto after_3;
    // 0x80068630: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80068634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80068638:
    // 0x80068638: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006863C: sw          $zero, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = 0;
    // 0x80068640: jr          $ra
    // 0x80068644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80068644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void race_check_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001983C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80019840: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80019844: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80019848: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001984C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80019850: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80019854: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80019858: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001985C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80019860: jal         0x8006BFF0
    // 0x80019864: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80019864: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    after_0:
    // 0x80019868: jal         0x8006ECD0
    // 0x8001986C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_1;
    // 0x8001986C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_1:
    // 0x80019870: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80019874: sh          $zero, 0x88($sp)
    MEM_H(0X88, ctx->r29) = 0;
    // 0x80019878: sh          $zero, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = 0;
    // 0x8001987C: lb          $v1, 0x4C($ra)
    ctx->r3 = MEM_B(ctx->r31, 0X4C);
    // 0x80019880: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80019884: beq         $v1, $zero, L_80019F10
    if (ctx->r3 == 0) {
        // 0x80019888: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80019F10;
    }
    // 0x80019888: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001988C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80019890: beq         $v1, $at, L_80019F10
    if (ctx->r3 == ctx->r1) {
        // 0x80019894: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80019F10;
    }
    // 0x80019894: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80019898: beq         $v1, $at, L_80019F10
    if (ctx->r3 == ctx->r1) {
        // 0x8001989C: andi        $t6, $v1, 0x40
        ctx->r14 = ctx->r3 & 0X40;
            goto L_80019F10;
    }
    // 0x8001989C: andi        $t6, $v1, 0x40
    ctx->r14 = ctx->r3 & 0X40;
    // 0x800198A0: beq         $t6, $zero, L_8001A7E4
    if (ctx->r14 == 0) {
        // 0x800198A4: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_8001A7E4;
    }
    // 0x800198A4: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800198A8: bne         $v1, $at, L_800198CC
    if (ctx->r3 != ctx->r1) {
        // 0x800198AC: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800198CC;
    }
    // 0x800198AC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800198B0: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x800198B4: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800198B8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800198BC: jal         0x80045168
    // 0x800198C0: nop

    racer_update_eggs(rdram, ctx);
        goto after_2;
    // 0x800198C0: nop

    after_2:
    // 0x800198C4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800198C8: nop

L_800198CC:
    // 0x800198CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800198D0: lw          $t7, -0x4CCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CCC);
    // 0x800198D4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800198D8: bne         $t7, $zero, L_8001A7E4
    if (ctx->r15 != 0) {
        // 0x800198DC: addiu       $t3, $t3, -0x4B9C
        ctx->r11 = ADD32(ctx->r11, -0X4B9C);
            goto L_8001A7E4;
    }
    // 0x800198DC: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x800198E0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800198E4: addiu       $s2, $s2, -0x4B90
    ctx->r18 = ADD32(ctx->r18, -0X4B90);
    // 0x800198E8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800198EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800198F0: blez        $a3, L_80019A8C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800198F4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80019A8C;
    }
    // 0x800198F4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800198F8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800198FC: addiu       $s1, $s1, -0x4CC0
    ctx->r17 = ADD32(ctx->r17, -0X4CC0);
    // 0x80019900: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80019904: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80019908: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8001990C: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
L_80019910:
    // 0x80019910: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80019914: nop

    // 0x80019918: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001991C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80019920: nop

    // 0x80019924: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80019928: nop

    // 0x8001992C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80019930: lb          $t8, 0x4C($ra)
    ctx->r24 = MEM_B(ctx->r31, 0X4C);
    // 0x80019934: nop

    // 0x80019938: bne         $t1, $t8, L_80019A00
    if (ctx->r9 != ctx->r24) {
        // 0x8001993C: nop
    
            goto L_80019A00;
    }
    // 0x8001993C: nop

    // 0x80019940: lb          $t9, 0x185($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X185);
    // 0x80019944: nop

    // 0x80019948: bgtz        $t9, L_80019A00
    if (SIGNED(ctx->r25) > 0) {
        // 0x8001994C: nop
    
            goto L_80019A00;
    }
    // 0x8001994C: nop

    // 0x80019950: lb          $t6, 0x1D8($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X1D8);
    // 0x80019954: nop

    // 0x80019958: bne         $t6, $zero, L_80019A00
    if (ctx->r14 != 0) {
        // 0x8001995C: nop
    
            goto L_80019A00;
    }
    // 0x8001995C: nop

    // 0x80019960: sb          $s4, 0x1D8($t7)
    MEM_B(0X1D8, ctx->r15) = ctx->r20;
    // 0x80019964: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80019968: nop

    // 0x8001996C: sb          $zero, 0x173($t7)
    MEM_B(0X173, ctx->r15) = 0;
    // 0x80019970: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80019974: nop

    // 0x80019978: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001997C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80019980: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80019984: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80019988: jal         0x80006AC8
    // 0x8001998C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    racer_sound_free(rdram, ctx);
        goto after_3;
    // 0x8001998C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_3:
    // 0x80019990: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80019994: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x80019998: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001999C: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800199A0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800199A4: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x800199A8: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800199AC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800199B0: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x800199B4: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x800199B8: ori         $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 | 0X4000;
    // 0x800199BC: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x800199C0: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800199C4: nop

    // 0x800199C8: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x800199CC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800199D0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800199D4: lw          $t9, 0x4C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4C);
    // 0x800199D8: nop

    // 0x800199DC: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x800199E0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800199E4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800199E8: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800199EC: sh          $t8, 0x1AC($t9)
    MEM_H(0X1AC, ctx->r25) = ctx->r24;
    // 0x800199F0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800199F4: nop

    // 0x800199F8: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800199FC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_80019A00:
    // 0x80019A00: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80019A04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80019A08: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80019A0C: lb          $v1, 0x1D8($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1D8);
    // 0x80019A10: beq         $s5, $t8, L_80019A40
    if (ctx->r21 == ctx->r24) {
        // 0x80019A14: nop
    
            goto L_80019A40;
    }
    // 0x80019A14: nop

    // 0x80019A18: beq         $v1, $zero, L_80019A34
    if (ctx->r3 == 0) {
        // 0x80019A1C: lh          $t6, 0x8A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X8A);
            goto L_80019A34;
    }
    // 0x80019A1C: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
    // 0x80019A20: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
    // 0x80019A24: nop

    // 0x80019A28: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80019A2C: sh          $t7, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r15;
    // 0x80019A30: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
L_80019A34:
    // 0x80019A34: nop

    // 0x80019A38: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80019A3C: sh          $t8, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r24;
L_80019A40:
    // 0x80019A40: beq         $v1, $zero, L_80019A78
    if (ctx->r3 == 0) {
        // 0x80019A44: nop
    
            goto L_80019A78;
    }
    // 0x80019A44: nop

    // 0x80019A48: lh          $t6, 0x1AC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1AC);
    // 0x80019A4C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80019A50: sll         $t9, $s3, 16
    ctx->r25 = S32(ctx->r19 << 16);
    // 0x80019A54: bne         $t6, $zero, L_80019A78
    if (ctx->r14 != 0) {
        // 0x80019A58: sra         $s3, $t9, 16
        ctx->r19 = S32(SIGNED(ctx->r25) >> 16);
            goto L_80019A78;
    }
    // 0x80019A58: sra         $s3, $t9, 16
    ctx->r19 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80019A5C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80019A60: nop

    // 0x80019A64: sh          $t8, 0x1AC($v0)
    MEM_H(0X1AC, ctx->r2) = ctx->r24;
    // 0x80019A68: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80019A6C: nop

    // 0x80019A70: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80019A74: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_80019A78:
    // 0x80019A78: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80019A7C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80019A80: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80019A84: bne         $at, $zero, L_80019910
    if (ctx->r1 != 0) {
        // 0x80019A88: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80019910;
    }
    // 0x80019A88: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80019A8C:
    // 0x80019A8C: lb          $t6, 0x4C($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4C);
    // 0x80019A90: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80019A94: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80019A98: addiu       $s1, $s1, -0x4CC0
    ctx->r17 = ADD32(ctx->r17, -0X4CC0);
    // 0x80019A9C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80019AA0: beq         $t1, $t6, L_80019AB0
    if (ctx->r9 == ctx->r14) {
        // 0x80019AA4: addiu       $s5, $zero, -0x1
        ctx->r21 = ADD32(0, -0X1);
            goto L_80019AB0;
    }
    // 0x80019AA4: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80019AA8: bgtz        $s3, L_80019AEC
    if (SIGNED(ctx->r19) > 0) {
        // 0x80019AAC: nop
    
            goto L_80019AEC;
    }
    // 0x80019AAC: nop

L_80019AB0:
    // 0x80019AB0: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    // 0x80019AB4: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
    // 0x80019AB8: bne         $t8, $s4, L_80019ACC
    if (ctx->r24 != ctx->r20) {
        // 0x80019ABC: lh          $t7, 0x8A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X8A);
            goto L_80019ACC;
    }
    // 0x80019ABC: lh          $t7, 0x8A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8A);
    // 0x80019AC0: beq         $t9, $s4, L_80019AEC
    if (ctx->r25 == ctx->r20) {
        // 0x80019AC4: nop
    
            goto L_80019AEC;
    }
    // 0x80019AC4: nop

    // 0x80019AC8: lh          $t7, 0x8A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8A);
L_80019ACC:
    // 0x80019ACC: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
    // 0x80019AD0: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80019AD4: bne         $at, $zero, L_80019AE0
    if (ctx->r1 != 0) {
        // 0x80019AD8: slt         $at, $t6, $t7
        ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
            goto L_80019AE0;
    }
    // 0x80019AD8: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80019ADC: beq         $at, $zero, L_80019AEC
    if (ctx->r1 == 0) {
        // 0x80019AE0: slti        $at, $s3, 0x3
        ctx->r1 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
            goto L_80019AEC;
    }
L_80019AE0:
    // 0x80019AE0: slti        $at, $s3, 0x3
    ctx->r1 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
    // 0x80019AE4: bne         $at, $zero, L_8001A7E4
    if (ctx->r1 != 0) {
        // 0x80019AE8: nop
    
            goto L_8001A7E4;
    }
    // 0x80019AE8: nop

L_80019AEC:
    // 0x80019AEC: blez        $a3, L_80019BF4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80019AF0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80019BF4;
    }
    // 0x80019AF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019AF4: addiu       $v1, $sp, 0x5C
    ctx->r3 = ADD32(ctx->r29, 0X5C);
    // 0x80019AF8: addu        $a0, $a3, $v1
    ctx->r4 = ADD32(ctx->r7, ctx->r3);
    // 0x80019AFC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80019B00: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80019B04: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80019B08: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
L_80019B0C:
    // 0x80019B0C: lb          $t9, 0x4C($ra)
    ctx->r25 = MEM_B(ctx->r31, 0X4C);
    // 0x80019B10: nop

    // 0x80019B14: bne         $t1, $t9, L_80019B38
    if (ctx->r9 != ctx->r25) {
        // 0x80019B18: nop
    
            goto L_80019B38;
    }
    // 0x80019B18: nop

    // 0x80019B1C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80019B20: nop

    // 0x80019B24: lb          $t7, 0x185($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X185);
    // 0x80019B28: nop

    // 0x80019B2C: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x80019B30: b           L_80019BB4
    // 0x80019B34: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
        goto L_80019BB4;
    // 0x80019B34: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_80019B38:
    // 0x80019B38: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80019B3C: nop

    // 0x80019B40: lb          $t9, 0x193($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X193);
    // 0x80019B44: nop

    // 0x80019B48: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x80019B4C: lb          $t6, 0x4C($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4C);
    // 0x80019B50: nop

    // 0x80019B54: bne         $a2, $t6, L_80019BB4
    if (ctx->r6 != ctx->r14) {
        // 0x80019B58: nop
    
            goto L_80019BB4;
    }
    // 0x80019B58: nop

    // 0x80019B5C: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x80019B60: nop

    // 0x80019B64: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019B68: mflo        $t8
    ctx->r24 = lo;
    // 0x80019B6C: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80019B70: lb          $t9, 0x1CF($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1CF);
    // 0x80019B74: nop

    // 0x80019B78: beq         $t9, $zero, L_80019B94
    if (ctx->r25 == 0) {
        // 0x80019B7C: nop
    
            goto L_80019B94;
    }
    // 0x80019B7C: nop

    // 0x80019B80: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x80019B84: nop

    // 0x80019B88: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x80019B8C: b           L_80019BB4
    // 0x80019B90: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
        goto L_80019BB4;
    // 0x80019B90: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_80019B94:
    // 0x80019B94: lw          $t8, 0x144($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X144);
    // 0x80019B98: nop

    // 0x80019B9C: beq         $t8, $zero, L_80019BB4
    if (ctx->r24 == 0) {
        // 0x80019BA0: nop
    
            goto L_80019BB4;
    }
    // 0x80019BA0: nop

    // 0x80019BA4: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x80019BA8: nop

    // 0x80019BAC: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80019BB0: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_80019BB4:
    // 0x80019BB4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80019BB8: nop

    // 0x80019BBC: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80019BC0: bne         $at, $zero, L_80019BD4
    if (ctx->r1 != 0) {
        // 0x80019BC4: nop
    
            goto L_80019BD4;
    }
    // 0x80019BC4: nop

    // 0x80019BC8: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x80019BCC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80019BD0: nop

L_80019BD4:
    // 0x80019BD4: bgez        $v0, L_80019BE0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80019BD8: nop
    
            goto L_80019BE0;
    }
    // 0x80019BD8: nop

    // 0x80019BDC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80019BE0:
    // 0x80019BE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80019BE4: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80019BE8: bne         $at, $zero, L_80019B0C
    if (ctx->r1 != 0) {
        // 0x80019BEC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80019B0C;
    }
    // 0x80019BEC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80019BF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80019BF4:
    // 0x80019BF4: addiu       $t0, $sp, 0x6C
    ctx->r8 = ADD32(ctx->r29, 0X6C);
    // 0x80019BF8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
L_80019BFC:
    // 0x80019BFC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80019C00: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x80019C04: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x80019C08: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80019C0C: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80019C10: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80019C14: blez        $a3, L_80019C78
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80019C18: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_80019C78;
    }
    // 0x80019C18: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80019C1C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
L_80019C20:
    // 0x80019C20: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80019C24: addu        $t7, $a2, $s0
    ctx->r15 = ADD32(ctx->r6, ctx->r16);
    // 0x80019C28: lb          $t6, 0x1D8($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X1D8);
    // 0x80019C2C: nop

    // 0x80019C30: bne         $t6, $zero, L_80019C64
    if (ctx->r14 != 0) {
        // 0x80019C34: nop
    
            goto L_80019C64;
    }
    // 0x80019C34: nop

    // 0x80019C38: lb          $v0, 0x0($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X0);
    // 0x80019C3C: nop

    // 0x80019C40: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80019C44: bne         $at, $zero, L_80019C64
    if (ctx->r1 != 0) {
        // 0x80019C48: nop
    
            goto L_80019C64;
    }
    // 0x80019C48: nop

    // 0x80019C4C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80019C50: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80019C54: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80019C58: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80019C5C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80019C60: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_80019C64:
    // 0x80019C64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80019C68: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80019C6C: bne         $at, $zero, L_80019C20
    if (ctx->r1 != 0) {
        // 0x80019C70: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80019C20;
    }
    // 0x80019C70: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80019C74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80019C78:
    // 0x80019C78: beq         $a0, $s5, L_80019CD4
    if (ctx->r4 == ctx->r21) {
        // 0x80019C7C: nop
    
            goto L_80019CD4;
    }
    // 0x80019C7C: nop

    // 0x80019C80: lb          $t6, 0x4C($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4C);
    // 0x80019C84: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80019C88: bne         $t1, $t6, L_80019CB0
    if (ctx->r9 != ctx->r14) {
        // 0x80019C8C: addu        $v0, $t0, $t9
        ctx->r2 = ADD32(ctx->r8, ctx->r25);
            goto L_80019CB0;
    }
    // 0x80019C8C: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x80019C90: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80019C94: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80019C98: addu        $v0, $t0, $t7
    ctx->r2 = ADD32(ctx->r8, ctx->r15);
    // 0x80019C9C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80019CA0: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80019CA4: subu        $t6, $t9, $t8
    ctx->r14 = SUB32(ctx->r25, ctx->r24);
    // 0x80019CA8: b           L_80019CC0
    // 0x80019CAC: sh          $t6, 0x1AC($t7)
    MEM_H(0X1AC, ctx->r15) = ctx->r14;
        goto L_80019CC0;
    // 0x80019CAC: sh          $t6, 0x1AC($t7)
    MEM_H(0X1AC, ctx->r15) = ctx->r14;
L_80019CB0:
    // 0x80019CB0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80019CB4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80019CB8: nop

    // 0x80019CBC: sh          $t8, 0x1AC($t6)
    MEM_H(0X1AC, ctx->r14) = ctx->r24;
L_80019CC0:
    // 0x80019CC0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80019CC4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80019CC8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80019CCC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80019CD0: sb          $s4, 0x1D8($t8)
    MEM_B(0X1D8, ctx->r24) = ctx->r20;
L_80019CD4:
    // 0x80019CD4: bne         $a0, $s5, L_80019BFC
    if (ctx->r4 != ctx->r21) {
        // 0x80019CD8: nop
    
            goto L_80019BFC;
    }
    // 0x80019CD8: nop

    // 0x80019CDC: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80019CE0: addiu       $s3, $s3, -0x334C
    ctx->r19 = ADD32(ctx->r19, -0X334C);
    // 0x80019CE4: jal         0x8009C814
    // 0x80019CE8: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    is_in_tracks_mode(rdram, ctx);
        goto after_4;
    // 0x80019CE8: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_4:
    // 0x80019CEC: bne         $v0, $zero, L_80019D80
    if (ctx->r2 != 0) {
        // 0x80019CF0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019D80;
    }
    // 0x80019CF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019CF4: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80019CF8: nop

    // 0x80019CFC: lh          $t7, 0x1AC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X1AC);
    // 0x80019D00: nop

    // 0x80019D04: beq         $s4, $t7, L_80019D34
    if (ctx->r20 == ctx->r15) {
        // 0x80019D08: nop
    
            goto L_80019D34;
    }
    // 0x80019D08: nop

    // 0x80019D0C: jal         0x8009F1C4
    // 0x80019D10: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_5;
    // 0x80019D10: nop

    after_5:
    // 0x80019D14: beq         $v0, $zero, L_80019D80
    if (ctx->r2 == 0) {
        // 0x80019D18: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019D80;
    }
    // 0x80019D18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019D1C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80019D20: nop

    // 0x80019D24: lh          $t8, 0x1AC($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X1AC);
    // 0x80019D28: nop

    // 0x80019D2C: bne         $s4, $t8, L_80019D80
    if (ctx->r20 != ctx->r24) {
        // 0x80019D30: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019D80;
    }
    // 0x80019D30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80019D34:
    // 0x80019D34: lbu         $t7, 0x49($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X49);
    // 0x80019D38: lw          $t6, 0x4($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X4);
    // 0x80019D3C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80019D40: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
    // 0x80019D44: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80019D48: nop

    // 0x80019D4C: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x80019D50: bne         $t8, $zero, L_80019D7C
    if (ctx->r24 != 0) {
        // 0x80019D54: ori         $t7, $v1, 0x2
        ctx->r15 = ctx->r3 | 0X2;
            goto L_80019D7C;
    }
    // 0x80019D54: ori         $t7, $v1, 0x2
    ctx->r15 = ctx->r3 | 0X2;
    // 0x80019D58: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80019D5C: lbu         $s0, 0x16($s6)
    ctx->r16 = MEM_BU(ctx->r22, 0X16);
    // 0x80019D60: nop

    // 0x80019D64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80019D68: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x80019D6C: bne         $at, $zero, L_80019D78
    if (ctx->r1 != 0) {
        // 0x80019D70: nop
    
            goto L_80019D78;
    }
    // 0x80019D70: nop

    // 0x80019D74: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80019D78:
    // 0x80019D78: sb          $s0, 0x16($s6)
    MEM_B(0X16, ctx->r22) = ctx->r16;
L_80019D7C:
    // 0x80019D7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80019D80:
    // 0x80019D80: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
L_80019D84:
    // 0x80019D84: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80019D88: slti        $at, $a2, 0x8
    ctx->r1 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    // 0x80019D8C: sb          $s5, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r21;
    // 0x80019D90: bne         $at, $zero, L_80019D84
    if (ctx->r1 != 0) {
        // 0x80019D94: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_80019D84;
    }
    // 0x80019D94: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80019D98: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80019D9C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80019DA0: blez        $t6, L_80019E00
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80019DA4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80019E00;
    }
    // 0x80019DA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019DA8: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80019DAC: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
L_80019DB0:
    // 0x80019DB0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80019DB4: nop

    // 0x80019DB8: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80019DBC: nop

    // 0x80019DC0: beq         $s5, $t9, L_80019DDC
    if (ctx->r21 == ctx->r25) {
        // 0x80019DC4: nop
    
            goto L_80019DDC;
    }
    // 0x80019DC4: nop

    // 0x80019DC8: lh          $t8, 0x1AC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X1AC);
    // 0x80019DCC: nop

    // 0x80019DD0: bne         $s4, $t8, L_80019DDC
    if (ctx->r20 != ctx->r24) {
        // 0x80019DD4: nop
    
            goto L_80019DDC;
    }
    // 0x80019DD4: nop

    // 0x80019DD8: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
L_80019DDC:
    // 0x80019DDC: lh          $t7, 0x1AC($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X1AC);
    // 0x80019DE0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80019DE4: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x80019DE8: sb          $t6, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r14;
    // 0x80019DEC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80019DF0: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80019DF4: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80019DF8: bne         $at, $zero, L_80019DB0
    if (ctx->r1 != 0) {
        // 0x80019DFC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80019DB0;
    }
    // 0x80019DFC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80019E00:
    // 0x80019E00: jal         0x80000B34
    // 0x80019E04: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    music_play(rdram, ctx);
        goto after_6;
    // 0x80019E04: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_6:
    // 0x80019E08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80019E0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019E10: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80019E14: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
L_80019E18:
    // 0x80019E18: lb          $t8, 0x5A($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5A);
    // 0x80019E1C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80019E20: bne         $s5, $t8, L_80019E30
    if (ctx->r21 != ctx->r24) {
        // 0x80019E24: nop
    
            goto L_80019E30;
    }
    // 0x80019E24: nop

    // 0x80019E28: sb          $a1, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r5;
    // 0x80019E2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80019E30:
    // 0x80019E30: bne         $v1, $a0, L_80019E18
    if (ctx->r3 != ctx->r4) {
        // 0x80019E34: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_80019E18;
    }
    // 0x80019E34: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80019E38: jal         0x8009F1C4
    // 0x80019E3C: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    is_in_two_player_adventure(rdram, ctx);
        goto after_7;
    // 0x80019E3C: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_7:
    // 0x80019E40: beq         $v0, $zero, L_80019E64
    if (ctx->r2 == 0) {
        // 0x80019E44: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80019E64;
    }
    // 0x80019E44: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80019E48: lb          $t7, 0x72($s6)
    ctx->r15 = MEM_B(ctx->r22, 0X72);
    // 0x80019E4C: lb          $t6, 0x5A($s6)
    ctx->r14 = MEM_B(ctx->r22, 0X5A);
    // 0x80019E50: nop

    // 0x80019E54: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80019E58: beq         $at, $zero, L_80019E64
    if (ctx->r1 == 0) {
        // 0x80019E5C: nop
    
            goto L_80019E64;
    }
    // 0x80019E5C: nop

    // 0x80019E60: sb          $s4, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r20;
L_80019E64:
    // 0x80019E64: bne         $s0, $zero, L_80019ED8
    if (ctx->r16 != 0) {
        // 0x80019E68: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80019ED8;
    }
    // 0x80019E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019E6C: jal         0x8009F1C4
    // 0x80019E70: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_8;
    // 0x80019E70: nop

    after_8:
    // 0x80019E74: beq         $v0, $zero, L_80019EC8
    if (ctx->r2 == 0) {
        // 0x80019E78: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80019EC8;
    }
    // 0x80019E78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019E7C: lb          $t9, 0x0($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X0);
    // 0x80019E80: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80019E84: beq         $t9, $zero, L_80019EB0
    if (ctx->r25 == 0) {
        // 0x80019E88: nop
    
            goto L_80019EB0;
    }
    // 0x80019E88: nop

    // 0x80019E8C: jal         0x8006F5D8
    // 0x80019E90: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    swap_lead_player(rdram, ctx);
        goto after_9;
    // 0x80019E90: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_9:
    // 0x80019E94: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80019E98: lb          $t8, -0x3354($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X3354);
    // 0x80019E9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80019EA0: beq         $t8, $zero, L_80019EC8
    if (ctx->r24 == 0) {
        // 0x80019EA4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80019EC8;
    }
    // 0x80019EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019EA8: b           L_80019EC4
    // 0x80019EAC: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
        goto L_80019EC4;
    // 0x80019EAC: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
L_80019EB0:
    // 0x80019EB0: lb          $t7, -0x3354($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X3354);
    // 0x80019EB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80019EB8: beq         $t7, $zero, L_80019EC8
    if (ctx->r15 == 0) {
        // 0x80019EBC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80019EC8;
    }
    // 0x80019EBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019EC0: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
L_80019EC4:
    // 0x80019EC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80019EC8:
    // 0x80019EC8: jal         0x80094B8C
    // 0x80019ECC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    postrace_start(rdram, ctx);
        goto after_10;
    // 0x80019ECC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_10:
    // 0x80019ED0: b           L_80019F04
    // 0x80019ED4: nop

        goto L_80019F04;
    // 0x80019ED4: nop

L_80019ED8:
    // 0x80019ED8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019EDC: jal         0x8006C3EC
    // 0x80019EE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_11;
    // 0x80019EE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80019EE4: lbu         $a3, 0x16($s6)
    ctx->r7 = MEM_BU(ctx->r22, 0X16);
    // 0x80019EE8: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x80019EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019EF0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80019EF4: jal         0x8006C3EC
    // 0x80019EF8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    level_properties_push(rdram, ctx);
        goto after_12;
    // 0x80019EF8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    after_12:
    // 0x80019EFC: jal         0x8001A908
    // 0x80019F00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_finish_adventure(rdram, ctx);
        goto after_13;
    // 0x80019F00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
L_80019F04:
    // 0x80019F04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80019F08: b           L_8001A7E4
    // 0x80019F0C: sw          $s4, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r20;
        goto L_8001A7E4;
    // 0x80019F0C: sw          $s4, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r20;
L_80019F10:
    // 0x80019F10: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80019F14: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80019F18: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80019F1C: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80019F20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019F24: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x80019F28: addiu       $s2, $s2, -0x4B90
    ctx->r18 = ADD32(ctx->r18, -0X4B90);
    // 0x80019F2C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80019F30: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
L_80019F34:
    // 0x80019F34: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x80019F38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80019F3C: addu        $t6, $t1, $t2
    ctx->r14 = ADD32(ctx->r9, ctx->r10);
    // 0x80019F40: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80019F44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019F48: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x80019F4C: nop

    // 0x80019F50: lh          $t4, 0x1AA($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X1AA);
    // 0x80019F54: nop

L_80019F58:
    // 0x80019F58: beq         $a1, $s0, L_80019FE8
    if (ctx->r5 == ctx->r16) {
        // 0x80019F5C: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80019FE8;
    }
    // 0x80019F5C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80019F60: addu        $t7, $t1, $t8
    ctx->r15 = ADD32(ctx->r9, ctx->r24);
    // 0x80019F64: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80019F68: lb          $t9, 0x1D8($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D8);
    // 0x80019F6C: lw          $v0, 0x64($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X64);
    // 0x80019F70: bne         $t9, $zero, L_80019F90
    if (ctx->r25 != 0) {
        // 0x80019F74: nop
    
            goto L_80019F90;
    }
    // 0x80019F74: nop

    // 0x80019F78: lb          $t8, 0x1D8($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1D8);
    // 0x80019F7C: nop

    // 0x80019F80: beq         $t8, $zero, L_80019F90
    if (ctx->r24 == 0) {
        // 0x80019F84: nop
    
            goto L_80019F90;
    }
    // 0x80019F84: nop

    // 0x80019F88: b           L_80019FE8
    // 0x80019F8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_80019FE8;
    // 0x80019F8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019F90:
    // 0x80019F90: lh          $v1, 0x190($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X190);
    // 0x80019F94: lh          $a0, 0x190($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X190);
    // 0x80019F98: nop

    // 0x80019F9C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80019FA0: beq         $at, $zero, L_80019FB0
    if (ctx->r1 == 0) {
        // 0x80019FA4: nop
    
            goto L_80019FB0;
    }
    // 0x80019FA4: nop

    // 0x80019FA8: b           L_80019FE8
    // 0x80019FAC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_80019FE8;
    // 0x80019FAC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019FB0:
    // 0x80019FB0: bne         $a0, $v1, L_80019FE8
    if (ctx->r4 != ctx->r3) {
        // 0x80019FB4: nop
    
            goto L_80019FE8;
    }
    // 0x80019FB4: nop

    // 0x80019FB8: lh          $v1, 0x1A8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1A8);
    // 0x80019FBC: lh          $a0, 0x1A8($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X1A8);
    // 0x80019FC0: nop

    // 0x80019FC4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80019FC8: beq         $at, $zero, L_80019FD4
    if (ctx->r1 == 0) {
        // 0x80019FCC: nop
    
            goto L_80019FD4;
    }
    // 0x80019FCC: nop

    // 0x80019FD0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019FD4:
    // 0x80019FD4: bne         $v1, $a0, L_80019FE8
    if (ctx->r3 != ctx->r4) {
        // 0x80019FD8: slt         $at, $s0, $a1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80019FE8;
    }
    // 0x80019FD8: slt         $at, $s0, $a1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80019FDC: beq         $at, $zero, L_80019FE8
    if (ctx->r1 == 0) {
        // 0x80019FE0: nop
    
            goto L_80019FE8;
    }
    // 0x80019FE0: nop

    // 0x80019FE4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80019FE8:
    // 0x80019FE8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80019FEC: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80019FF0: bne         $at, $zero, L_80019F58
    if (ctx->r1 != 0) {
        // 0x80019FF4: nop
    
            goto L_80019F58;
    }
    // 0x80019FF4: nop

    // 0x80019FF8: sh          $a2, 0x1AA($t0)
    MEM_H(0X1AA, ctx->r8) = ctx->r6;
    // 0x80019FFC: lb          $t6, 0x4B($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4B);
    // 0x8001A000: lb          $t7, 0x193($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X193);
    // 0x8001A004: nop

    // 0x8001A008: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001A00C: beq         $at, $zero, L_8001A070
    if (ctx->r1 == 0) {
        // 0x8001A010: nop
    
            goto L_8001A070;
    }
    // 0x8001A010: nop

    // 0x8001A014: lh          $v0, 0x1AA($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X1AA);
    // 0x8001A018: nop

    // 0x8001A01C: bne         $t4, $v0, L_8001A06C
    if (ctx->r12 != ctx->r2) {
        // 0x8001A020: nop
    
            goto L_8001A06C;
    }
    // 0x8001A020: nop

    // 0x8001A024: lh          $v1, 0x1B0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X1B0);
    // 0x8001A028: nop

    // 0x8001A02C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001A030: beq         $at, $zero, L_8001A050
    if (ctx->r1 == 0) {
        // 0x8001A034: nop
    
            goto L_8001A050;
    }
    // 0x8001A034: nop

    // 0x8001A038: lb          $t9, 0x1D6($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D6);
    // 0x8001A03C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001A040: beq         $t9, $at, L_8001A070
    if (ctx->r25 == ctx->r1) {
        // 0x8001A044: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8001A070;
    }
    // 0x8001A044: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8001A048: b           L_8001A070
    // 0x8001A04C: sh          $t8, 0x1B0($t0)
    MEM_H(0X1B0, ctx->r8) = ctx->r24;
        goto L_8001A070;
    // 0x8001A04C: sh          $t8, 0x1B0($t0)
    MEM_H(0X1B0, ctx->r8) = ctx->r24;
L_8001A050:
    // 0x8001A050: lh          $t7, 0x1AE($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X1AE);
    // 0x8001A054: nop

    // 0x8001A058: beq         $t7, $v0, L_8001A070
    if (ctx->r15 == ctx->r2) {
        // 0x8001A05C: nop
    
            goto L_8001A070;
    }
    // 0x8001A05C: nop

    // 0x8001A060: sh          $t5, 0x1B2($t0)
    MEM_H(0X1B2, ctx->r8) = ctx->r13;
    // 0x8001A064: b           L_8001A070
    // 0x8001A068: sh          $v0, 0x1AE($t0)
    MEM_H(0X1AE, ctx->r8) = ctx->r2;
        goto L_8001A070;
    // 0x8001A068: sh          $v0, 0x1AE($t0)
    MEM_H(0X1AE, ctx->r8) = ctx->r2;
L_8001A06C:
    // 0x8001A06C: sh          $zero, 0x1B0($t0)
    MEM_H(0X1B0, ctx->r8) = 0;
L_8001A070:
    // 0x8001A070: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A074: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A078: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A07C: bne         $at, $zero, L_80019F34
    if (ctx->r1 != 0) {
        // 0x8001A080: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_80019F34;
    }
    // 0x8001A080: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A084: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001A088: addiu       $s1, $s1, -0x4CC0
    ctx->r17 = ADD32(ctx->r17, -0X4CC0);
    // 0x8001A08C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001A090: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x8001A094: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_8001A098:
    // 0x8001A098: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8001A09C: nop

    // 0x8001A0A0: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x8001A0A4: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8001A0A8: lb          $t6, 0x4B($ra)
    ctx->r14 = MEM_B(ctx->r31, 0X4B);
    // 0x8001A0AC: lw          $t0, 0x64($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X64);
    // 0x8001A0B0: nop

    // 0x8001A0B4: lb          $t7, 0x193($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X193);
    // 0x8001A0B8: nop

    // 0x8001A0BC: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001A0C0: bne         $at, $zero, L_8001A164
    if (ctx->r1 != 0) {
        // 0x8001A0C4: nop
    
            goto L_8001A164;
    }
    // 0x8001A0C4: nop

    // 0x8001A0C8: lb          $t9, 0x1D8($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A0CC: nop

    // 0x8001A0D0: bne         $t9, $zero, L_8001A164
    if (ctx->r25 != 0) {
        // 0x8001A0D4: nop
    
            goto L_8001A164;
    }
    // 0x8001A0D4: nop

    // 0x8001A0D8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8001A0DC: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8001A0E0: jal         0x8006DC4C
    // 0x8001A0E4: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    get_game_mode(rdram, ctx);
        goto after_14;
    // 0x8001A0E4: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_14:
    // 0x8001A0E8: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A0EC: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001A0F0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001A0F4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8001A0F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001A0FC: beq         $v0, $at, L_8001A164
    if (ctx->r2 == ctx->r1) {
        // 0x8001A100: addiu       $t3, $t3, -0x4B9C
        ctx->r11 = ADD32(ctx->r11, -0X4B9C);
            goto L_8001A164;
    }
    // 0x8001A100: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x8001A104: sb          $s4, 0x1D8($t0)
    MEM_B(0X1D8, ctx->r8) = ctx->r20;
    // 0x8001A108: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8001A10C: nop

    // 0x8001A110: sh          $t8, 0x1AC($t0)
    MEM_H(0X1AC, ctx->r8) = ctx->r24;
    // 0x8001A114: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A118: nop

    // 0x8001A11C: bne         $s4, $v0, L_8001A160
    if (ctx->r20 != ctx->r2) {
        // 0x8001A120: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8001A160;
    }
    // 0x8001A120: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8001A124: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8001A128: addiu       $a0, $zero, 0x23C
    ctx->r4 = ADD32(0, 0X23C);
    // 0x8001A12C: bne         $s5, $t7, L_8001A15C
    if (ctx->r21 != ctx->r15) {
        // 0x8001A130: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001A15C;
    }
    // 0x8001A130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A134: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8001A138: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8001A13C: jal         0x80001D04
    // 0x8001A140: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x8001A140: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_15:
    // 0x8001A144: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001A148: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A14C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001A150: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8001A154: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A158: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
L_8001A15C:
    // 0x8001A15C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
L_8001A160:
    // 0x8001A160: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_8001A164:
    // 0x8001A164: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A168: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x8001A16C: lb          $v0, 0x1D8($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A170: beq         $s5, $t9, L_8001A1A4
    if (ctx->r21 == ctx->r25) {
        // 0x8001A174: sll         $v1, $a3, 2
        ctx->r3 = S32(ctx->r7 << 2);
            goto L_8001A1A4;
    }
    // 0x8001A174: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x8001A178: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    // 0x8001A17C: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
    // 0x8001A180: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x8001A184: beq         $v0, $zero, L_8001A1B8
    if (ctx->r2 == 0) {
        // 0x8001A188: sh          $t7, 0x8A($sp)
        MEM_H(0X8A, ctx->r29) = ctx->r15;
            goto L_8001A1B8;
    }
    // 0x8001A188: sh          $t7, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r15;
    // 0x8001A18C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001A190: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x8001A194: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8001A198: sh          $t9, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r25;
    // 0x8001A19C: b           L_8001A1B8
    // 0x8001A1A0: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
        goto L_8001A1B8;
    // 0x8001A1A0: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
L_8001A1A4:
    // 0x8001A1A4: beq         $v0, $zero, L_8001A1B8
    if (ctx->r2 == 0) {
        // 0x8001A1A8: nop
    
            goto L_8001A1B8;
    }
    // 0x8001A1A8: nop

    // 0x8001A1AC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001A1B0: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x8001A1B4: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
L_8001A1B8:
    // 0x8001A1B8: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A1BC: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001A1C0: bne         $at, $zero, L_8001A098
    if (ctx->r1 != 0) {
        // 0x8001A1C4: nop
    
            goto L_8001A098;
    }
    // 0x8001A1C4: nop

    // 0x8001A1C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A1CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A1D0: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A1D4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001A1D8:
    // 0x8001A1D8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001A1DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A1E0: addu        $t7, $t8, $t2
    ctx->r15 = ADD32(ctx->r24, ctx->r10);
    // 0x8001A1E4: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8001A1E8: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001A1EC: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A1F0: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001A1F4: bne         $at, $zero, L_8001A1D8
    if (ctx->r1 != 0) {
        // 0x8001A1F8: nop
    
            goto L_8001A1D8;
    }
    // 0x8001A1F8: nop

    // 0x8001A1FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A200: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001A204:
    // 0x8001A204: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x8001A208: nop

    // 0x8001A20C: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x8001A210: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001A214: nop

    // 0x8001A218: lw          $t0, 0x64($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X64);
    // 0x8001A21C: nop

    // 0x8001A220: lb          $t7, 0x1D8($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A224: nop

    // 0x8001A228: beq         $t7, $zero, L_8001A23C
    if (ctx->r15 == 0) {
        // 0x8001A22C: nop
    
            goto L_8001A23C;
    }
    // 0x8001A22C: nop

    // 0x8001A230: lh          $a2, 0x1AC($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X1AC);
    // 0x8001A234: b           L_8001A248
    // 0x8001A238: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_8001A248;
    // 0x8001A238: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001A23C:
    // 0x8001A23C: lh          $a2, 0x1AA($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X1AA);
    // 0x8001A240: nop

    // 0x8001A244: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001A248:
    // 0x8001A248: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001A24C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8001A250: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8001A254: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8001A258: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A25C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A260: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A264: bne         $at, $zero, L_8001A204
    if (ctx->r1 != 0) {
        // 0x8001A268: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001A204;
    }
    // 0x8001A268: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A26C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001A274:
    // 0x8001A274: blez        $a3, L_8001A2D0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8001A278: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001A2D0;
    }
    // 0x8001A278: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001A27C: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8001A280: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8001A284: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8001A288: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8001A28C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8001A290: nop

    // 0x8001A294: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
L_8001A298:
    // 0x8001A298: addu        $t7, $v1, $t8
    ctx->r15 = ADD32(ctx->r3, ctx->r24);
    // 0x8001A29C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8001A2A0: nop

    // 0x8001A2A4: bne         $t6, $v0, L_8001A2C0
    if (ctx->r14 != ctx->r2) {
        // 0x8001A2A8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001A2C0;
    }
    // 0x8001A2A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001A2AC: sll         $a0, $s4, 24
    ctx->r4 = S32(ctx->r20 << 24);
    // 0x8001A2B0: sra         $t9, $a0, 24
    ctx->r25 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8001A2B4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8001A2B8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8001A2BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001A2C0:
    // 0x8001A2C0: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A2C4: bne         $at, $zero, L_8001A298
    if (ctx->r1 != 0) {
        // 0x8001A2C8: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_8001A298;
    }
    // 0x8001A2C8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8001A2CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001A2D0:
    // 0x8001A2D0: bne         $a0, $zero, L_8001A334
    if (ctx->r4 != 0) {
        // 0x8001A2D4: nop
    
            goto L_8001A334;
    }
    // 0x8001A2D4: nop

    // 0x8001A2D8: blez        $a3, L_8001A334
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8001A2DC: nop
    
            goto L_8001A334;
    }
    // 0x8001A2DC: nop

L_8001A2E0:
    // 0x8001A2E0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001A2E4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8001A2E8: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x8001A2EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001A2F0: nop

    // 0x8001A2F4: bne         $t6, $zero, L_8001A324
    if (ctx->r14 != 0) {
        // 0x8001A2F8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001A324;
    }
    // 0x8001A2F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001A2FC: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x8001A300: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8001A304: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8001A308: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8001A30C: nop

    // 0x8001A310: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001A314: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x8001A318: nop

    // 0x8001A31C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8001A320: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001A324:
    // 0x8001A324: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A328: bne         $at, $zero, L_8001A2E0
    if (ctx->r1 != 0) {
        // 0x8001A32C: nop
    
            goto L_8001A2E0;
    }
    // 0x8001A32C: nop

    // 0x8001A330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001A334:
    // 0x8001A334: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A338: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001A33C: bne         $at, $zero, L_8001A274
    if (ctx->r1 != 0) {
        // 0x8001A340: nop
    
            goto L_8001A274;
    }
    // 0x8001A340: nop

    // 0x8001A344: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001A348:
    // 0x8001A348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001A34C: jal         0x8006A794
    // 0x8001A350: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_16;
    // 0x8001A350: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    after_16:
    // 0x8001A354: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x8001A358: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A35C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8001A360: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001A364: addiu       $t3, $t3, -0x4B9C
    ctx->r11 = ADD32(ctx->r11, -0X4B9C);
    // 0x8001A368: bne         $at, $zero, L_8001A348
    if (ctx->r1 != 0) {
        // 0x8001A36C: or          $a1, $a1, $v0
        ctx->r5 = ctx->r5 | ctx->r2;
            goto L_8001A348;
    }
    // 0x8001A36C: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x8001A370: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8001A374: lb          $t9, -0x4B8A($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X4B8A);
    // 0x8001A378: lh          $t8, 0x88($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X88);
    // 0x8001A37C: beq         $t9, $zero, L_8001A39C
    if (ctx->r25 == 0) {
        // 0x8001A380: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8001A39C;
    }
    // 0x8001A380: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001A384: beq         $t8, $zero, L_8001A39C
    if (ctx->r24 == 0) {
        // 0x8001A388: nop
    
            goto L_8001A39C;
    }
    // 0x8001A388: nop

    // 0x8001A38C: jal         0x80022E4C
    // 0x8001A390: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mode_end_taj_race(rdram, ctx);
        goto after_17;
    // 0x8001A390: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x8001A394: b           L_8001A7E8
    // 0x8001A398: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8001A7E8;
    // 0x8001A398: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001A39C:
    // 0x8001A39C: lb          $t7, -0x4D44($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X4D44);
    // 0x8001A3A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001A3A4: beq         $t7, $zero, L_8001A400
    if (ctx->r15 == 0) {
        // 0x8001A3A8: nop
    
            goto L_8001A400;
    }
    // 0x8001A3A8: nop

    // 0x8001A3AC: beq         $s3, $zero, L_8001A400
    if (ctx->r19 == 0) {
        // 0x8001A3B0: nop
    
            goto L_8001A400;
    }
    // 0x8001A3B0: nop

    // 0x8001A3B4: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8001A3B8: nop

    // 0x8001A3BC: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8001A3C0: nop

    // 0x8001A3C4: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x8001A3C8: nop

    // 0x8001A3CC: lb          $t8, 0x1D8($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A3D0: nop

    // 0x8001A3D4: bne         $t8, $zero, L_8001A7E8
    if (ctx->r24 != 0) {
        // 0x8001A3D8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7E8;
    }
    // 0x8001A3D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001A3DC: sb          $s4, 0x1D8($t0)
    MEM_B(0X1D8, ctx->r8) = ctx->r20;
    // 0x8001A3E0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8001A3E4: nop

    // 0x8001A3E8: sh          $t7, 0x1AC($t0)
    MEM_H(0X1AC, ctx->r8) = ctx->r15;
    // 0x8001A3EC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001A3F0: nop

    // 0x8001A3F4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8001A3F8: b           L_8001A7E4
    // 0x8001A3FC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
        goto L_8001A7E4;
    // 0x8001A3FC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_8001A400:
    // 0x8001A400: lw          $t8, -0x4CCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4CCC);
    // 0x8001A404: nop

    // 0x8001A408: bne         $t8, $zero, L_8001A7E8
    if (ctx->r24 != 0) {
        // 0x8001A40C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7E8;
    }
    // 0x8001A40C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001A410: jal         0x8009F1C4
    // 0x8001A414: sb          $zero, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = 0;
    is_in_two_player_adventure(rdram, ctx);
        goto after_18;
    // 0x8001A414: sb          $zero, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = 0;
    after_18:
    // 0x8001A418: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A41C: beq         $v0, $zero, L_8001A460
    if (ctx->r2 == 0) {
        // 0x8001A420: addiu       $t1, $t1, -0x4B98
        ctx->r9 = ADD32(ctx->r9, -0X4B98);
            goto L_8001A460;
    }
    // 0x8001A420: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A424: lh          $t7, 0x88($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X88);
    // 0x8001A428: nop

    // 0x8001A42C: blez        $t7, L_8001A464
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8001A430: lh          $t6, 0x88($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X88);
            goto L_8001A464;
    }
    // 0x8001A430: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
    // 0x8001A434: jal         0x80099B68
    // 0x8001A438: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_19;
    // 0x8001A438: nop

    after_19:
    // 0x8001A43C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A440: bne         $v0, $zero, L_8001A460
    if (ctx->r2 != 0) {
        // 0x8001A444: addiu       $t1, $t1, -0x4B98
        ctx->r9 = ADD32(ctx->r9, -0X4B98);
            goto L_8001A460;
    }
    // 0x8001A444: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A448: jal         0x8001A80C
    // 0x8001A44C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    set_course_finish_flags(rdram, ctx);
        goto after_20;
    // 0x8001A44C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_20:
    // 0x8001A450: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A454: beq         $v0, $zero, L_8001A460
    if (ctx->r2 == 0) {
        // 0x8001A458: addiu       $t1, $t1, -0x4B98
        ctx->r9 = ADD32(ctx->r9, -0X4B98);
            goto L_8001A460;
    }
    // 0x8001A458: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A45C: sb          $s4, 0x5B($sp)
    MEM_B(0X5B, ctx->r29) = ctx->r20;
L_8001A460:
    // 0x8001A460: lh          $t6, 0x88($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88);
L_8001A464:
    // 0x8001A464: lh          $t9, 0x8A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X8A);
    // 0x8001A468: nop

    // 0x8001A46C: beq         $t6, $t9, L_8001A4A4
    if (ctx->r14 == ctx->r25) {
        // 0x8001A470: slti        $at, $t9, 0x2
        ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
            goto L_8001A4A4;
    }
    // 0x8001A470: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8001A474: bne         $at, $zero, L_8001A498
    if (ctx->r1 != 0) {
        // 0x8001A478: lb          $t6, 0x5B($sp)
        ctx->r14 = MEM_B(ctx->r29, 0X5B);
            goto L_8001A498;
    }
    // 0x8001A478: lb          $t6, 0x5B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X5B);
    // 0x8001A47C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8001A480: nop

    // 0x8001A484: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8001A488: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001A48C: beq         $at, $zero, L_8001A4A8
    if (ctx->r1 == 0) {
        // 0x8001A490: lh          $t9, 0x88($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X88);
            goto L_8001A4A8;
    }
    // 0x8001A490: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
    // 0x8001A494: lb          $t6, 0x5B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X5B);
L_8001A498:
    // 0x8001A498: nop

    // 0x8001A49C: beq         $t6, $zero, L_8001A7E8
    if (ctx->r14 == 0) {
        // 0x8001A4A0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7E8;
    }
    // 0x8001A4A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001A4A4:
    // 0x8001A4A4: lh          $t9, 0x88($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X88);
L_8001A4A8:
    // 0x8001A4A8: lh          $t8, 0x8A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8A);
    // 0x8001A4AC: nop

    // 0x8001A4B0: beq         $t9, $t8, L_8001A558
    if (ctx->r25 == ctx->r24) {
        // 0x8001A4B4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001A558;
    }
    // 0x8001A4B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A4B8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001A4BC:
    // 0x8001A4BC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8001A4C0: nop

    // 0x8001A4C4: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x8001A4C8: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8001A4CC: nop

    // 0x8001A4D0: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x8001A4D4: nop

    // 0x8001A4D8: lb          $t8, 0x1D8($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X1D8);
    // 0x8001A4DC: nop

    // 0x8001A4E0: bne         $t8, $zero, L_8001A544
    if (ctx->r24 != 0) {
        // 0x8001A4E4: nop
    
            goto L_8001A544;
    }
    // 0x8001A4E4: nop

    // 0x8001A4E8: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    // 0x8001A4EC: nop

    // 0x8001A4F0: bltz        $a0, L_8001A524
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001A4F4: nop
    
            goto L_8001A524;
    }
    // 0x8001A4F4: nop

    // 0x8001A4F8: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8001A4FC: jal         0x80066828
    // 0x8001A500: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    set_active_camera(rdram, ctx);
        goto after_21;
    // 0x8001A500: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_21:
    // 0x8001A504: jal         0x80069F3C
    // 0x8001A508: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_22;
    // 0x8001A508: nop

    after_22:
    // 0x8001A50C: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A510: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A514: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8001A518: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8001A51C: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A520: sh          $t7, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r15;
L_8001A524:
    // 0x8001A524: sb          $s4, 0x1D8($t0)
    MEM_B(0X1D8, ctx->r8) = ctx->r20;
    // 0x8001A528: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001A52C: nop

    // 0x8001A530: sh          $t6, 0x1AC($t0)
    MEM_H(0X1AC, ctx->r8) = ctx->r14;
    // 0x8001A534: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8001A538: nop

    // 0x8001A53C: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8001A540: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
L_8001A544:
    // 0x8001A544: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8001A548: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A54C: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001A550: bne         $at, $zero, L_8001A4BC
    if (ctx->r1 != 0) {
        // 0x8001A554: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001A4BC;
    }
    // 0x8001A554: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
L_8001A558:
    // 0x8001A558: lui         $v1, 0xA460
    ctx->r3 = S32(0XA460 << 16);
    // 0x8001A55C: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x8001A560: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001A564: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001A568: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8001A56C: beq         $t6, $zero, L_8001A588
    if (ctx->r14 == 0) {
        // 0x8001A570: lui         $t8, 0xB000
        ctx->r24 = S32(0XB000 << 16);
            goto L_8001A588;
    }
    // 0x8001A570: lui         $t8, 0xB000
    ctx->r24 = S32(0XB000 << 16);
L_8001A574:
    // 0x8001A574: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001A578: nop

    // 0x8001A57C: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8001A580: bne         $t9, $zero, L_8001A574
    if (ctx->r25 != 0) {
        // 0x8001A584: nop
    
            goto L_8001A574;
    }
    // 0x8001A584: nop

L_8001A588:
    // 0x8001A588: lw          $t7, 0x574($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X574);
    // 0x8001A58C: addiu       $at, $zero, 0x6C07
    ctx->r1 = ADD32(0, 0X6C07);
    // 0x8001A590: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x8001A594: beq         $t6, $at, L_8001A5A8
    if (ctx->r14 == ctx->r1) {
        // 0x8001A598: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8001A5A8;
    }
    // 0x8001A598: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001A59C: sll         $a0, $s4, 24
    ctx->r4 = S32(ctx->r20 << 24);
    // 0x8001A5A0: sra         $t9, $a0, 24
    ctx->r25 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8001A5A4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_8001A5A8:
    // 0x8001A5A8: lbu         $t8, -0x4B8B($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X4B8B);
    // 0x8001A5AC: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8001A5B0: bne         $t8, $zero, L_8001A60C
    if (ctx->r24 != 0) {
        // 0x8001A5B4: addiu       $s3, $s3, -0x334C
        ctx->r19 = ADD32(ctx->r19, -0X334C);
            goto L_8001A60C;
    }
    // 0x8001A5B4: addiu       $s3, $s3, -0x334C
    ctx->r19 = ADD32(ctx->r19, -0X334C);
    // 0x8001A5B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A5BC: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001A5C0: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_8001A5C4:
    // 0x8001A5C4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8001A5C8: nop

    // 0x8001A5CC: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x8001A5D0: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8001A5D4: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001A5D8: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x8001A5DC: nop

    // 0x8001A5E0: lb          $a2, 0x2($t0)
    ctx->r6 = MEM_B(ctx->r8, 0X2);
    // 0x8001A5E4: nop

    // 0x8001A5E8: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A5EC: mflo        $t8
    ctx->r24 = lo;
    // 0x8001A5F0: addu        $t7, $s6, $t8
    ctx->r15 = ADD32(ctx->r22, ctx->r24);
    // 0x8001A5F4: sb          $s0, 0x5A($t7)
    MEM_B(0X5A, ctx->r15) = ctx->r16;
    // 0x8001A5F8: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8001A5FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A600: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001A604: bne         $at, $zero, L_8001A5C4
    if (ctx->r1 != 0) {
        // 0x8001A608: nop
    
            goto L_8001A5C4;
    }
    // 0x8001A608: nop

L_8001A60C:
    // 0x8001A60C: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x8001A610: jal         0x8009F1C4
    // 0x8001A614: sb          $a0, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r4;
    is_in_two_player_adventure(rdram, ctx);
        goto after_23;
    // 0x8001A614: sb          $a0, 0x5A($sp)
    MEM_B(0X5A, ctx->r29) = ctx->r4;
    after_23:
    // 0x8001A618: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001A61C: beq         $v0, $zero, L_8001A640
    if (ctx->r2 == 0) {
        // 0x8001A620: addiu       $t1, $t1, -0x4B98
        ctx->r9 = ADD32(ctx->r9, -0X4B98);
            goto L_8001A640;
    }
    // 0x8001A620: addiu       $t1, $t1, -0x4B98
    ctx->r9 = ADD32(ctx->r9, -0X4B98);
    // 0x8001A624: lb          $t9, 0x72($s6)
    ctx->r25 = MEM_B(ctx->r22, 0X72);
    // 0x8001A628: lb          $t8, 0x5A($s6)
    ctx->r24 = MEM_B(ctx->r22, 0X5A);
    // 0x8001A62C: nop

    // 0x8001A630: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001A634: beq         $at, $zero, L_8001A640
    if (ctx->r1 == 0) {
        // 0x8001A638: nop
    
            goto L_8001A640;
    }
    // 0x8001A638: nop

    // 0x8001A63C: sb          $s4, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r20;
L_8001A640:
    // 0x8001A640: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8001A644: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001A648: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8001A64C: addiu       $s1, $s1, -0x4CBC
    ctx->r17 = ADD32(ctx->r17, -0X4CBC);
    // 0x8001A650: lw          $t0, 0x64($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X64);
    // 0x8001A654: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x8001A658: lbu         $t9, 0x4A($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X4A);
    // 0x8001A65C: nop

    // 0x8001A660: beq         $s4, $t9, L_8001A67C
    if (ctx->r20 == ctx->r25) {
        // 0x8001A664: nop
    
            goto L_8001A67C;
    }
    // 0x8001A664: nop

    // 0x8001A668: jal         0x8009F1C4
    // 0x8001A66C: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    is_in_two_player_adventure(rdram, ctx);
        goto after_24;
    // 0x8001A66C: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    after_24:
    // 0x8001A670: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x8001A674: beq         $v0, $zero, L_8001A6B0
    if (ctx->r2 == 0) {
        // 0x8001A678: nop
    
            goto L_8001A6B0;
    }
    // 0x8001A678: nop

L_8001A67C:
    // 0x8001A67C: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x8001A680: nop

    // 0x8001A684: beq         $s5, $t8, L_8001A6B0
    if (ctx->r21 == ctx->r24) {
        // 0x8001A688: nop
    
            goto L_8001A6B0;
    }
    // 0x8001A688: nop

    // 0x8001A68C: jal         0x8009C814
    // 0x8001A690: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_25;
    // 0x8001A690: nop

    after_25:
    // 0x8001A694: bne         $v0, $zero, L_8001A6B0
    if (ctx->r2 != 0) {
        // 0x8001A698: nop
    
            goto L_8001A6B0;
    }
    // 0x8001A698: nop

    // 0x8001A69C: jal         0x80099B68
    // 0x8001A6A0: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_26;
    // 0x8001A6A0: nop

    after_26:
    // 0x8001A6A4: bne         $v0, $zero, L_8001A6B0
    if (ctx->r2 != 0) {
        // 0x8001A6A8: nop
    
            goto L_8001A6B0;
    }
    // 0x8001A6A8: nop

    // 0x8001A6AC: sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
L_8001A6B0:
    // 0x8001A6B0: lb          $t7, 0x0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X0);
    // 0x8001A6B4: lb          $t6, 0x5B($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X5B);
    // 0x8001A6B8: beq         $t7, $zero, L_8001A6D4
    if (ctx->r15 == 0) {
        // 0x8001A6BC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001A6D4;
    }
    // 0x8001A6BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A6C0: bne         $t6, $zero, L_8001A6D8
    if (ctx->r14 != 0) {
        // 0x8001A6C4: lb          $t9, 0x5B($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X5B);
            goto L_8001A6D8;
    }
    // 0x8001A6C4: lb          $t9, 0x5B($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X5B);
    // 0x8001A6C8: jal         0x8001A80C
    // 0x8001A6CC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    set_course_finish_flags(rdram, ctx);
        goto after_27;
    // 0x8001A6CC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_27:
    // 0x8001A6D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8001A6D4:
    // 0x8001A6D4: lb          $t9, 0x5B($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X5B);
L_8001A6D8:
    // 0x8001A6D8: nop

    // 0x8001A6DC: beq         $t9, $zero, L_8001A6F0
    if (ctx->r25 == 0) {
        // 0x8001A6E0: lb          $t8, 0x5A($sp)
        ctx->r24 = MEM_B(ctx->r29, 0X5A);
            goto L_8001A6F0;
    }
    // 0x8001A6E0: lb          $t8, 0x5A($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X5A);
    // 0x8001A6E4: sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
    // 0x8001A6E8: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x8001A6EC: lb          $t8, 0x5A($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X5A);
L_8001A6F0:
    // 0x8001A6F0: nop

    // 0x8001A6F4: beq         $t8, $zero, L_8001A704
    if (ctx->r24 == 0) {
        // 0x8001A6F8: nop
    
            goto L_8001A704;
    }
    // 0x8001A6F8: nop

    // 0x8001A6FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A700: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8001A704:
    // 0x8001A704: bne         $s0, $zero, L_8001A778
    if (ctx->r16 != 0) {
        // 0x8001A708: nop
    
            goto L_8001A778;
    }
    // 0x8001A708: nop

    // 0x8001A70C: jal         0x8009F1C4
    // 0x8001A710: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_28;
    // 0x8001A710: nop

    after_28:
    // 0x8001A714: beq         $v0, $zero, L_8001A764
    if (ctx->r2 == 0) {
        // 0x8001A718: nop
    
            goto L_8001A764;
    }
    // 0x8001A718: nop

    // 0x8001A71C: lb          $t7, 0x0($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X0);
    // 0x8001A720: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001A724: beq         $t7, $zero, L_8001A750
    if (ctx->r15 == 0) {
        // 0x8001A728: nop
    
            goto L_8001A750;
    }
    // 0x8001A728: nop

    // 0x8001A72C: jal         0x8006F5D8
    // 0x8001A730: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    swap_lead_player(rdram, ctx);
        goto after_29;
    // 0x8001A730: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    after_29:
    // 0x8001A734: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001A738: lb          $t6, -0x3354($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X3354);
    // 0x8001A73C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A740: beq         $t6, $zero, L_8001A764
    if (ctx->r14 == 0) {
        // 0x8001A744: nop
    
            goto L_8001A764;
    }
    // 0x8001A744: nop

    // 0x8001A748: b           L_8001A764
    // 0x8001A74C: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
        goto L_8001A764;
    // 0x8001A74C: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
L_8001A750:
    // 0x8001A750: lb          $t9, -0x3354($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X3354);
    // 0x8001A754: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001A758: beq         $t9, $zero, L_8001A764
    if (ctx->r25 == 0) {
        // 0x8001A75C: nop
    
            goto L_8001A764;
    }
    // 0x8001A75C: nop

    // 0x8001A760: sb          $s4, -0x3348($at)
    MEM_B(-0X3348, ctx->r1) = ctx->r20;
L_8001A764:
    // 0x8001A764: lb          $a0, 0x0($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X0);
    // 0x8001A768: jal         0x80094B8C
    // 0x8001A76C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    postrace_start(rdram, ctx);
        goto after_30;
    // 0x8001A76C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_30:
    // 0x8001A770: b           L_8001A7C8
    // 0x8001A774: nop

        goto L_8001A7C8;
    // 0x8001A774: nop

L_8001A778:
    // 0x8001A778: lbu         $t7, 0x48($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X48);
    // 0x8001A77C: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x8001A780: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8001A784: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x8001A788: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8001A78C: nop

    // 0x8001A790: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8001A794: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8001A798: lbu         $t8, 0x48($s6)
    ctx->r24 = MEM_BU(ctx->r22, 0X48);
    // 0x8001A79C: nop

    // 0x8001A7A0: beq         $t8, $zero, L_8001A7C0
    if (ctx->r24 == 0) {
        // 0x8001A7A4: nop
    
            goto L_8001A7C0;
    }
    // 0x8001A7A4: nop

    // 0x8001A7A8: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8001A7AC: nop

    // 0x8001A7B0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8001A7B4: nop

    // 0x8001A7B8: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8001A7BC: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
L_8001A7C0:
    // 0x8001A7C0: jal         0x8001A908
    // 0x8001A7C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_finish_adventure(rdram, ctx);
        goto after_31;
    // 0x8001A7C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_31:
L_8001A7C8:
    // 0x8001A7C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A7CC: jal         0x8009C90C
    // 0x8001A7D0: sw          $s5, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r21;
    get_number_of_active_players(rdram, ctx);
        goto after_32;
    // 0x8001A7D0: sw          $s5, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = ctx->r21;
    after_32:
    // 0x8001A7D4: bne         $v0, $s4, L_8001A7E8
    if (ctx->r2 != ctx->r20) {
        // 0x8001A7D8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001A7E8;
    }
    // 0x8001A7D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001A7DC: jal         0x8001AE98
    // 0x8001A7E0: nop

    race_finish_time_trial(rdram, ctx);
        goto after_33;
    // 0x8001A7E0: nop

    after_33:
L_8001A7E4:
    // 0x8001A7E4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001A7E8:
    // 0x8001A7E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A7EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A7F0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001A7F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001A7F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001A7FC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A800: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001A804: jr          $ra
    // 0x8001A808: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8001A808: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void texrect_draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078F08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80078F0C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80078F10: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80078F14: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80078F18: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80078F1C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80078F20: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80078F24: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80078F28: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80078F2C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80078F30: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80078F34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80078F38: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80078F3C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80078F40: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078F44: addiu       $t8, $t8, -0x1458
    ctx->r24 = ADD32(ctx->r24, -0X1458);
    // 0x80078F48: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80078F4C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80078F50: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80078F54: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80078F58: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80078F5C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80078F60: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078F64: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80078F68: lbu         $t8, 0x43($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X43);
    // 0x80078F6C: lbu         $t7, 0x47($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X47);
    // 0x80078F70: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80078F74: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80078F78: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80078F7C: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    // 0x80078F80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80078F84: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x80078F88: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80078F8C: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x80078F90: sll         $fp, $a2, 2
    ctx->r30 = S32(ctx->r6 << 2);
    // 0x80078F94: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80078F98: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80078F9C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80078FA0: sll         $ra, $a3, 2
    ctx->r31 = S32(ctx->r7 << 2);
    // 0x80078FA4: beq         $t0, $zero, L_800790EC
    if (ctx->r8 == 0) {
        // 0x80078FA8: or          $t2, $a1, $zero
        ctx->r10 = ctx->r5 | 0;
            goto L_800790EC;
    }
    // 0x80078FA8: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x80078FAC: lui         $s7, 0x400
    ctx->r23 = S32(0X400 << 16);
    // 0x80078FB0: ori         $s7, $s7, 0x400
    ctx->r23 = ctx->r23 | 0X400;
    // 0x80078FB4: lui         $s6, 0xB200
    ctx->r22 = S32(0XB200 << 16);
    // 0x80078FB8: lui         $s5, 0xB300
    ctx->r21 = S32(0XB300 << 16);
    // 0x80078FBC: lui         $s4, 0xE400
    ctx->r20 = S32(0XE400 << 16);
    // 0x80078FC0: lui         $s3, 0x8000
    ctx->r19 = S32(0X8000 << 16);
    // 0x80078FC4: lui         $s2, 0x700
    ctx->r18 = S32(0X700 << 16);
L_80078FC8:
    // 0x80078FC8: lh          $t6, 0x4($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X4);
    // 0x80078FCC: lh          $t9, 0x6($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X6);
    // 0x80078FD0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80078FD4: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x80078FD8: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80078FDC: lbu         $t9, 0x1($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X1);
    // 0x80078FE0: addu        $a2, $t8, $fp
    ctx->r6 = ADD32(ctx->r24, ctx->r30);
    // 0x80078FE4: addu        $a3, $t7, $ra
    ctx->r7 = ADD32(ctx->r15, ctx->r31);
    // 0x80078FE8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80078FEC: addu        $t3, $t8, $a2
    ctx->r11 = ADD32(ctx->r24, ctx->r6);
    // 0x80078FF0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80078FF4: blez        $t3, L_800790DC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80078FF8: addu        $t4, $t7, $a3
        ctx->r12 = ADD32(ctx->r15, ctx->r7);
            goto L_800790DC;
    }
    // 0x80078FF8: addu        $t4, $t7, $a3
    ctx->r12 = ADD32(ctx->r15, ctx->r7);
    // 0x80078FFC: blez        $t4, L_800790DC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80079000: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_800790DC;
    }
    // 0x80079000: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80079004: bgez        $a2, L_80079018
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80079008: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80079018;
    }
    // 0x80079008: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007900C: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x80079010: negu        $t5, $t5
    ctx->r13 = SUB32(0, ctx->r13);
    // 0x80079014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80079018:
    // 0x80079018: bgez        $a3, L_8007902C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8007901C: nop
    
            goto L_8007902C;
    }
    // 0x8007901C: nop

    // 0x80079020: sll         $s1, $a3, 3
    ctx->r17 = S32(ctx->r7 << 3);
    // 0x80079024: negu        $s1, $s1
    ctx->r17 = SUB32(0, ctx->r17);
    // 0x80079028: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8007902C:
    // 0x8007902C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079030: nop

    // 0x80079034: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80079038: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007903C: lh          $a0, 0xA($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XA);
    // 0x80079040: nop

    // 0x80079044: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x80079048: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8007904C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80079050: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80079054: or          $t7, $t9, $s2
    ctx->r15 = ctx->r25 | ctx->r18;
    // 0x80079058: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8007905C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80079060: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x80079064: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x80079068: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x8007906C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80079070: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079074: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80079078: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007907C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80079080: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x80079084: or          $t7, $t6, $s4
    ctx->r15 = ctx->r14 | ctx->r20;
    // 0x80079088: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8007908C: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x80079090: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80079094: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x80079098: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007909C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800790A0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800790A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800790A8: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x800790AC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800790B0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800790B4: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x800790B8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800790BC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800790C0: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x800790C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800790C8: nop

    // 0x800790CC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800790D0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800790D4: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x800790D8: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
L_800790DC:
    // 0x800790DC: lw          $t0, 0x8($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X8);
    // 0x800790E0: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x800790E4: bne         $t0, $zero, L_80078FC8
    if (ctx->r8 != 0) {
        // 0x800790E8: nop
    
            goto L_80078FC8;
    }
    // 0x800790E8: nop

L_800790EC:
    // 0x800790EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800790F0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800790F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800790F8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800790FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80079100: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80079104: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079108: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8007910C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80079110: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80079114: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80079118: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007911C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80079120: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80079124: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80079128: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8007912C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80079130: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80079134: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80079138: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8007913C: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80079140: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80079144: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80079148: jr          $ra
    // 0x8007914C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007914C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void dialogue_npc_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D4AC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009D4B0: addiu       $t6, $t6, -0x59C
    ctx->r14 = ADD32(ctx->r14, -0X59C);
    // 0x8009D4B4: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8009D4B8: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x8009D4BC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D4C0: bne         $t7, $zero, L_8009D4EC
    if (ctx->r15 != 0) {
        // 0x8009D4C4: addiu       $t8, $t8, -0x599
        ctx->r24 = ADD32(ctx->r24, -0X599);
            goto L_8009D4EC;
    }
    // 0x8009D4C4: addiu       $t8, $t8, -0x599
    ctx->r24 = ADD32(ctx->r24, -0X599);
    // 0x8009D4C8: beq         $v0, $t8, L_8009D4E0
    if (ctx->r2 == ctx->r24) {
        // 0x8009D4CC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8009D4E0;
    }
    // 0x8009D4CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009D4D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D4D4: sb          $zero, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = 0;
    // 0x8009D4D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D4DC: sb          $zero, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = 0;
L_8009D4E0:
    // 0x8009D4E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D4E4: sb          $v1, -0x5A0($at)
    MEM_B(-0X5A0, ctx->r1) = ctx->r3;
    // 0x8009D4E8: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8009D4EC:
    // 0x8009D4EC: jr          $ra
    // 0x8009D4F0: nop

    return;
    // 0x8009D4F0: nop

;}
RECOMP_FUNC void obj_init_dynamic_lighting_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038220: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80038224: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038228: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003822C: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80038230: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80038234: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80038238: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x8003823C: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80038240: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80038244: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x80038248: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x8003824C: jr          $ra
    // 0x80038250: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x80038250: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void begin_lighthouse_rocket_cutscene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F4DC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F4E0: lh          $t6, -0x26FC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X26FC);
    // 0x8006F4E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F4E8: bne         $t6, $zero, L_8006F568
    if (ctx->r14 != 0) {
        // 0x8006F4EC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F568;
    }
    // 0x8006F4EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F4F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006F4F4: lw          $v0, 0x3A90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A90);
    // 0x8006F4F8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006F4FC: lhu         $t7, 0xE($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XE);
    // 0x8006F500: nop

    // 0x8006F504: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8006F508: bne         $t8, $at, L_8006F56C
    if (ctx->r24 != ctx->r1) {
        // 0x8006F50C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006F56C;
    }
    // 0x8006F50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F510: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8006F514: nop

    // 0x8006F518: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x8006F51C: bne         $t9, $zero, L_8006F56C
    if (ctx->r25 != 0) {
        // 0x8006F520: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006F56C;
    }
    // 0x8006F520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F524: lhu         $t0, 0xC($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XC);
    // 0x8006F528: ori         $t2, $v1, 0x1
    ctx->r10 = ctx->r3 | 0X1;
    // 0x8006F52C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8006F530: beq         $t1, $zero, L_8006F568
    if (ctx->r9 == 0) {
        // 0x8006F534: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006F568;
    }
    // 0x8006F534: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F538: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8006F53C: jal         0x800C06F8
    // 0x8006F540: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F540: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    after_0:
    // 0x8006F544: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x8006F548: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F54C: sh          $t3, -0x26FC($at)
    MEM_H(-0X26FC, ctx->r1) = ctx->r11;
    // 0x8006F550: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F554: addiu       $t4, $zero, 0x2D
    ctx->r12 = ADD32(0, 0X2D);
    // 0x8006F558: sb          $t4, 0x3AA5($at)
    MEM_B(0X3AA5, ctx->r1) = ctx->r12;
    // 0x8006F55C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F560: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8006F564: sb          $t5, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = ctx->r13;
L_8006F568:
    // 0x8006F568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006F56C:
    // 0x8006F56C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F570: jr          $ra
    // 0x8006F574: nop

    return;
    // 0x8006F574: nop

;}
RECOMP_FUNC void music_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001990: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001994: addiu       $v0, $v0, -0x3458
    ctx->r2 = ADD32(ctx->r2, -0X3458);
    // 0x80001998: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000199C: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x800019A0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800019A4: lw          $t7, -0x343C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X343C);
    // 0x800019A8: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800019AC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800019B0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800019B4: lw          $t9, -0x3424($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3424);
    // 0x800019B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800019BC: lwc1        $f8, -0x3440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3440);
    // 0x800019C0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800019C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800019C8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800019CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800019D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800019D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800019D8: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800019DC: mflo        $t8
    ctx->r24 = lo;
    // 0x800019E0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800019E4: nop

    // 0x800019E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800019EC: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800019F0: nop

    // 0x800019F4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800019F8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800019FC: nop

    // 0x80001A00: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80001A04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001A08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80001A0C: nop

    // 0x80001A10: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80001A14: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80001A18: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80001A1C: sra         $t1, $a1, 8
    ctx->r9 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80001A20: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80001A24: jal         0x800C7DB0
    // 0x80001A28: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_0;
    // 0x80001A28: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_0:
    // 0x80001A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001A30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001A34: jr          $ra
    // 0x80001A38: nop

    return;
    // 0x80001A38: nop

;}
RECOMP_FUNC void obj_loop_frog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042330: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x80042334: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80042338: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8004233C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80042340: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80042344: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80042348: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004234C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80042350: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80042354: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80042358: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8004235C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80042360: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80042364: bne         $t6, $zero, L_80042384
    if (ctx->r14 != 0) {
        // 0x80042368: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80042384;
    }
    // 0x80042368: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8004236C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042370: lwc1        $f9, 0x67E0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X67E0);
    // 0x80042374: lwc1        $f8, 0x67E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X67E4);
    // 0x80042378: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8004237C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80042380: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_80042384:
    // 0x80042384: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x80042388: nop

    // 0x8004238C: lbu         $t7, 0x14($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X14);
    // 0x80042390: nop

    // 0x80042394: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80042398: beq         $at, $zero, L_800429B4
    if (ctx->r1 == 0) {
        // 0x8004239C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800429B4;
    }
    // 0x8004239C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800423A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800423A4: addu        $at, $at, $t7
    gpr jr_addend_800423B0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800423A8: lw          $t7, 0x67E8($at)
    ctx->r15 = ADD32(ctx->r1, 0X67E8);
    // 0x800423AC: nop

    // 0x800423B0: jr          $t7
    // 0x800423B4: nop

    switch (jr_addend_800423B0 >> 2) {
        case 0: goto L_800423B8; break;
        case 1: goto L_800426F8; break;
        case 2: goto L_800428D8; break;
        case 3: goto L_80042928; break;
        case 4: goto L_8004296C; break;
        default: switch_error(__func__, 0x800423B0, 0x800E67E8);
    }
    // 0x800423B4: nop

L_800423B8:
    // 0x800423B8: sw          $zero, 0x104($sp)
    MEM_W(0X104, ctx->r29) = 0;
    // 0x800423BC: lb          $v0, 0x19($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X19);
    // 0x800423C0: lui         $a3, 0x42C0
    ctx->r7 = S32(0X42C0 << 16);
    // 0x800423C4: blez        $v0, L_800423D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800423C8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800423D4;
    }
    // 0x800423C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800423CC: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x800423D0: sb          $t8, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r24;
L_800423D4:
    // 0x800423D4: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800423D8: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800423DC: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x800423E0: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x800423E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800423E8: sw          $a1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r5;
    // 0x800423EC: jal         0x80016E1C
    // 0x800423F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    obj_dist_racer(rdram, ctx);
        goto after_0;
    // 0x800423F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x800423F4: lw          $a1, 0x114($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X114);
    // 0x800423F8: blez        $v0, L_80042534
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800423FC: nop
    
            goto L_80042534;
    }
    // 0x800423FC: nop

    // 0x80042400: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80042404: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80042408: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004240C: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80042410: lb          $t2, 0x19($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X19);
    // 0x80042414: lwc1        $f16, 0xC($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80042418: lwc1        $f18, 0x10($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X10);
    // 0x8004241C: lwc1        $f4, 0x14($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X14);
    // 0x80042420: sub.s       $f20, $f0, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80042424: sub.s       $f14, $f12, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80042428: bgtz        $t2, L_800424E4
    if (SIGNED(ctx->r10) > 0) {
        // 0x8004242C: sub.s       $f22, $f2, $f4
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_800424E4;
    }
    // 0x8004242C: sub.s       $f22, $f2, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80042430: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80042434: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80042438: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004243C: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80042440: nop

    // 0x80042444: mul.s       $f16, $f22, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80042448: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004244C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80042450: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80042454: nop

    // 0x80042458: bc1f        L_800424E4
    if (!c1cs) {
        // 0x8004245C: nop
    
            goto L_800424E4;
    }
    // 0x8004245C: nop

    // 0x80042460: lbu         $t3, 0x15($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X15);
    // 0x80042464: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80042468: beq         $t3, $zero, L_800424BC
    if (ctx->r11 == 0) {
        // 0x8004246C: addiu       $a0, $zero, 0x13F
        ctx->r4 = ADD32(0, 0X13F);
            goto L_800424BC;
    }
    // 0x8004246C: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x80042470: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80042474: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80042478: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8004247C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80042480: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80042484: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    // 0x80042488: jal         0x80009558
    // 0x8004248C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_1;
    // 0x8004248C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x80042490: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80042494: jal         0x8009EFBC
    // 0x80042498: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_eeprom_settings_value(rdram, ctx);
        goto after_2;
    // 0x80042498: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8004249C: jal         0x8009C824
    // 0x800424A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_magic_code_flags(rdram, ctx);
        goto after_3;
    // 0x800424A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x800424A4: jal         0x8006DAE4
    // 0x800424A8: nop

    set_drumstick_unlock_transition(rdram, ctx);
        goto after_4;
    // 0x800424A8: nop

    after_4:
    // 0x800424AC: jal         0x8000FFB8
    // 0x800424B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_5;
    // 0x800424B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800424B4: b           L_800429B8
    // 0x800424B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800429B8;
    // 0x800424B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800424BC:
    // 0x800424BC: sb          $t5, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r13;
    // 0x800424C0: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x800424C4: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x800424C8: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x800424CC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800424D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800424D4: jal         0x80009558
    // 0x800424D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_6;
    // 0x800424D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_6:
    // 0x800424DC: b           L_80042588
    // 0x800424E0: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
        goto L_80042588;
    // 0x800424E0: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
L_800424E4:
    // 0x800424E4: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x800424E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800424EC: lbu         $t7, 0x15($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15);
    // 0x800424F0: neg.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = -ctx->f20.fl;
    // 0x800424F4: beq         $t7, $zero, L_80042514
    if (ctx->r15 == 0) {
        // 0x800424F8: swc1        $f6, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
            goto L_80042514;
    }
    // 0x800424F8: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x800424FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042500: lwc1        $f10, 0x67FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X67FC);
    // 0x80042504: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80042508: nop

    // 0x8004250C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80042510: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
L_80042514:
    // 0x80042514: jal         0x80070990
    // 0x80042518: neg.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = -ctx->f22.fl;
    arctan2_f(rdram, ctx);
        goto after_7;
    // 0x80042518: neg.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = -ctx->f22.fl;
    after_7:
    // 0x8004251C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80042520: addu        $t8, $v0, $at
    ctx->r24 = ADD32(ctx->r2, ctx->r1);
    // 0x80042524: sh          $t8, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r24;
    // 0x80042528: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004252C: b           L_80042584
    // 0x80042530: sw          $t9, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r25;
        goto L_80042584;
    // 0x80042530: sw          $t9, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r25;
L_80042534:
    // 0x80042534: lh          $t0, 0x16($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X16);
    // 0x80042538: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004253C: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x80042540: sh          $t1, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r9;
    // 0x80042544: lh          $t2, 0x16($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X16);
    // 0x80042548: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8004254C: bgez        $t2, L_80042584
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80042550: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_80042584;
    }
    // 0x80042550: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80042554: jal         0x8006FB8C
    // 0x80042558: sw          $t3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r11;
    rand_range(rdram, ctx);
        goto after_8;
    // 0x80042558: sw          $t3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r11;
    after_8:
    // 0x8004255C: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80042560: addiu       $a0, $zero, -0x4000
    ctx->r4 = ADD32(0, -0X4000);
    // 0x80042564: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80042568: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    // 0x8004256C: jal         0x8006FB8C
    // 0x80042570: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    rand_range(rdram, ctx);
        goto after_9;
    // 0x80042570: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_9:
    // 0x80042574: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x80042578: nop

    // 0x8004257C: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80042580: sh          $t5, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r13;
L_80042584:
    // 0x80042584: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
L_80042588:
    // 0x80042588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004258C: beq         $t6, $zero, L_800429B4
    if (ctx->r14 == 0) {
        // 0x80042590: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800429B4;
    }
    // 0x80042590: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80042594:
    // 0x80042594: lh          $a0, 0x1A($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A);
    // 0x80042598: sw          $v1, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r3;
    // 0x8004259C: jal         0x80070A04
    // 0x800425A0: sw          $v0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_10;
    // 0x800425A0: sw          $v0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r2;
    after_10:
    // 0x800425A4: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800425A8: lh          $a0, 0x1A($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A);
    // 0x800425AC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800425B0: jal         0x80070A38
    // 0x800425B4: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    coss_f(rdram, ctx);
        goto after_11;
    // 0x800425B4: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    after_11:
    // 0x800425B8: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800425BC: lw          $v0, 0x108($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X108);
    // 0x800425C0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800425C4: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800425C8: lw          $v1, 0x100($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X100);
    // 0x800425CC: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800425D0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800425D4: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x800425D8: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800425DC: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800425E0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800425E4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800425E8: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800425EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800425F0: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800425F4: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800425F8: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800425FC: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80042600: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80042604: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80042608: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004260C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80042610: nop

    // 0x80042614: bc1f        L_80042624
    if (!c1cs) {
        // 0x80042618: nop
    
            goto L_80042624;
    }
    // 0x80042618: nop

    // 0x8004261C: b           L_80042634
    // 0x80042620: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80042634;
    // 0x80042620: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80042624:
    // 0x80042624: lh          $t7, 0x1A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A);
    // 0x80042628: nop

    // 0x8004262C: addiu       $t8, $t7, 0x4000
    ctx->r24 = ADD32(ctx->r15, 0X4000);
    // 0x80042630: sh          $t8, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r24;
L_80042634:
    // 0x80042634: beq         $at, $zero, L_80042644
    if (ctx->r1 == 0) {
        // 0x80042638: nop
    
            goto L_80042644;
    }
    // 0x80042638: nop

    // 0x8004263C: beq         $v1, $zero, L_80042594
    if (ctx->r3 == 0) {
        // 0x80042640: nop
    
            goto L_80042594;
    }
    // 0x80042640: nop

L_80042644:
    // 0x80042644: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80042648: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004264C: bne         $v1, $zero, L_80042678
    if (ctx->r3 != 0) {
        // 0x80042650: nop
    
            goto L_80042678;
    }
    // 0x80042650: nop

    // 0x80042654: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80042658: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004265C: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80042660: jal         0x80070990
    // 0x80042664: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    arctan2_f(rdram, ctx);
        goto after_12;
    // 0x80042664: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    after_12:
    // 0x80042668: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // 0x8004266C: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80042670: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80042674: nop

L_80042678:
    // 0x80042678: lbu         $t9, 0x15($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15);
    // 0x8004267C: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x80042680: beq         $t9, $zero, L_800426B0
    if (ctx->r25 == 0) {
        // 0x80042684: addiu       $t1, $zero, 0x4
        ctx->r9 = ADD32(0, 0X4);
            goto L_800426B0;
    }
    // 0x80042684: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80042688: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004268C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80042690: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80042694: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80042698: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8004269C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800426A0: jal         0x80009558
    // 0x800426A4: addiu       $a0, $zero, 0x1A4
    ctx->r4 = ADD32(0, 0X1A4);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_13;
    // 0x800426A4: addiu       $a0, $zero, 0x1A4
    ctx->r4 = ADD32(0, 0X1A4);
    after_13:
    // 0x800426A8: b           L_800426CC
    // 0x800426AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_800426CC;
    // 0x800426AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800426B0:
    // 0x800426B0: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x800426B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800426B8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800426BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800426C0: jal         0x80009558
    // 0x800426C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_14;
    // 0x800426C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_14:
    // 0x800426C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800426CC:
    // 0x800426CC: sb          $t2, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r10;
    // 0x800426D0: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800426D4: lh          $t4, 0x1A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A);
    // 0x800426D8: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x800426DC: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800426E0: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800426E4: sb          $t3, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r11;
    // 0x800426E8: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800426EC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800426F0: b           L_800429B4
    // 0x800426F4: sh          $t5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r13;
        goto L_800429B4;
    // 0x800426F4: sh          $t5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r13;
L_800426F8:
    // 0x800426F8: lb          $t6, 0x18($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X18);
    // 0x800426FC: lb          $v0, 0x19($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X19);
    // 0x80042700: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x80042704: blez        $v0, L_80042714
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80042708: sb          $t7, 0x18($s0)
        MEM_B(0X18, ctx->r16) = ctx->r15;
            goto L_80042714;
    }
    // 0x80042708: sb          $t7, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r15;
    // 0x8004270C: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x80042710: sb          $t8, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r24;
L_80042714:
    // 0x80042714: lb          $v1, 0x18($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X18);
    // 0x80042718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004271C: bgez        $v1, L_80042738
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80042720: addiu       $a1, $zero, 0x12C
        ctx->r5 = ADD32(0, 0X12C);
            goto L_80042738;
    }
    // 0x80042720: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x80042724: jal         0x8006FB8C
    // 0x80042728: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    rand_range(rdram, ctx);
        goto after_15;
    // 0x80042728: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    after_15:
    // 0x8004272C: sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
    // 0x80042730: lb          $v1, 0x18($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X18);
    // 0x80042734: sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
L_80042738:
    // 0x80042738: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8004273C: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x80042740: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80042744: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80042748: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8004274C: mflo        $t2
    ctx->r10 = lo;
    // 0x80042750: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x80042754: lb          $t3, 0x18($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X18);
    // 0x80042758: nop

    // 0x8004275C: sll         $t4, $t3, 26
    ctx->r12 = S32(ctx->r11 << 26);
    // 0x80042760: jal         0x80070A38
    // 0x80042764: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_16;
    // 0x80042764: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_16:
    // 0x80042768: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004276C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80042770: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80042774: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80042778: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004277C: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80042780: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    // 0x80042784: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80042788: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8004278C: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x80042790: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80042794: nop

    // 0x80042798: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8004279C: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x800427A0: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800427A4: nop

    // 0x800427A8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800427AC: jal         0x80011560
    // 0x800427B0: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_17;
    // 0x800427B0: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    after_17:
    // 0x800427B4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800427B8: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x800427BC: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x800427C0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800427C4: jal         0x80011570
    // 0x800427C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    move_object(rdram, ctx);
        goto after_18;
    // 0x800427C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x800427CC: lh          $a0, 0x2E($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2E);
    // 0x800427D0: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x800427D4: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x800427D8: jal         0x8002BAF0
    // 0x800427DC: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    collision_get_y(rdram, ctx);
        goto after_19;
    // 0x800427DC: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_19:
    // 0x800427E0: beq         $v0, $zero, L_80042804
    if (ctx->r2 == 0) {
        // 0x800427E4: nop
    
            goto L_80042804;
    }
    // 0x800427E4: nop

    // 0x800427E8: jal         0x80011560
    // 0x800427EC: swc1        $f20, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f20.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_20;
    // 0x800427EC: swc1        $f20, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f20.u32l;
    after_20:
    // 0x800427F0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800427F4: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800427F8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800427FC: jal         0x80011570
    // 0x80042800: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    move_object(rdram, ctx);
        goto after_21;
    // 0x80042800: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
L_80042804:
    // 0x80042804: lb          $t6, 0x19($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X19);
    // 0x80042808: nop

    // 0x8004280C: bgtz        $t6, L_800429B8
    if (SIGNED(ctx->r14) > 0) {
        // 0x80042810: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800429B8;
    }
    // 0x80042810: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80042814: lb          $v1, 0x18($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X18);
    // 0x80042818: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x8004281C: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80042820: bne         $at, $zero, L_80042834
    if (ctx->r1 != 0) {
        // 0x80042824: addiu       $t7, $sp, 0x44
        ctx->r15 = ADD32(ctx->r29, 0X44);
            goto L_80042834;
    }
    // 0x80042824: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x80042828: slti        $at, $v1, 0x1B
    ctx->r1 = SIGNED(ctx->r3) < 0X1B ? 1 : 0;
    // 0x8004282C: bne         $at, $zero, L_800429B8
    if (ctx->r1 != 0) {
        // 0x80042830: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800429B8;
    }
    // 0x80042830: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80042834:
    // 0x80042834: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80042838: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004283C: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x80042840: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80042844: jal         0x80016E1C
    // 0x80042848: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    obj_dist_racer(rdram, ctx);
        goto after_22;
    // 0x80042848: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_22:
    // 0x8004284C: beq         $v0, $zero, L_800429B8
    if (ctx->r2 == 0) {
        // 0x80042850: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800429B8;
    }
    // 0x80042850: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80042854: lbu         $t8, 0x15($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X15);
    // 0x80042858: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8004285C: beq         $t8, $zero, L_800428B0
    if (ctx->r24 == 0) {
        // 0x80042860: addiu       $a0, $zero, 0x13F
        ctx->r4 = ADD32(0, 0X13F);
            goto L_800428B0;
    }
    // 0x80042860: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x80042864: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80042868: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004286C: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80042870: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80042874: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80042878: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8004287C: jal         0x80009558
    // 0x80042880: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_23;
    // 0x80042880: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    after_23:
    // 0x80042884: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80042888: jal         0x8009EFBC
    // 0x8004288C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_eeprom_settings_value(rdram, ctx);
        goto after_24;
    // 0x8004288C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_24:
    // 0x80042890: jal         0x8009C824
    // 0x80042894: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_magic_code_flags(rdram, ctx);
        goto after_25;
    // 0x80042894: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_25:
    // 0x80042898: jal         0x8006DAE4
    // 0x8004289C: nop

    set_drumstick_unlock_transition(rdram, ctx);
        goto after_26;
    // 0x8004289C: nop

    after_26:
    // 0x800428A0: jal         0x8000FFB8
    // 0x800428A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_27;
    // 0x800428A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x800428A8: b           L_800429B8
    // 0x800428AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800429B8;
    // 0x800428AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800428B0:
    // 0x800428B0: sb          $t0, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r8;
    // 0x800428B4: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x800428B8: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x800428BC: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x800428C0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800428C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800428C8: jal         0x80009558
    // 0x800428CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_28;
    // 0x800428CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_28:
    // 0x800428D0: b           L_800429B8
    // 0x800428D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800429B8;
    // 0x800428D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800428D8:
    // 0x800428D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800428DC: lwc1        $f0, 0x6800($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6800);
    // 0x800428E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800428E4: lwc1        $f18, 0x6804($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6804);
    // 0x800428E8: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800428EC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800428F0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800428F4: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x800428F8: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800428FC: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x80042900: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80042904: nop

    // 0x80042908: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8004290C: nop

    // 0x80042910: bc1f        L_800429B8
    if (!c1cs) {
        // 0x80042914: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800429B8;
    }
    // 0x80042914: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80042918: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x8004291C: sb          $t2, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r10;
    // 0x80042920: b           L_800429B4
    // 0x80042924: sh          $t3, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r11;
        goto L_800429B4;
    // 0x80042924: sh          $t3, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r11;
L_80042928:
    // 0x80042928: lh          $t4, 0x16($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X16);
    // 0x8004292C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80042930: subu        $t5, $t4, $a1
    ctx->r13 = SUB32(ctx->r12, ctx->r5);
    // 0x80042934: sh          $t5, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r13;
    // 0x80042938: lh          $t6, 0x16($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16);
    // 0x8004293C: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    // 0x80042940: bgez        $t6, L_800429B4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80042944: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_800429B4;
    }
    // 0x80042944: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80042948: sb          $t7, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r15;
    // 0x8004294C: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80042950: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x80042954: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80042958: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8004295C: jal         0x80009558
    // 0x80042960: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_29;
    // 0x80042960: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_29:
    // 0x80042964: b           L_800429B8
    // 0x80042968: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800429B8;
    // 0x80042968: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8004296C:
    // 0x8004296C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042970: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80042974: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80042978: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8004297C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80042980: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80042984: bc1f        L_800429A0
    if (!c1cs) {
        // 0x80042988: nop
    
            goto L_800429A0;
    }
    // 0x80042988: nop

    // 0x8004298C: swc1        $f12, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f12.u32l;
    // 0x80042990: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // 0x80042994: sh          $zero, 0x16($s0)
    MEM_H(0X16, ctx->r16) = 0;
    // 0x80042998: b           L_800429B4
    // 0x8004299C: sb          $t9, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r25;
        goto L_800429B4;
    // 0x8004299C: sb          $t9, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r25;
L_800429A0:
    // 0x800429A0: lwc1        $f10, 0x6808($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6808);
    // 0x800429A4: nop

    // 0x800429A8: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800429AC: add.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800429B0: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_800429B4:
    // 0x800429B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800429B8:
    // 0x800429B8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800429BC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800429C0: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800429C4: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800429C8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800429CC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800429D0: jr          $ra
    // 0x800429D4: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x800429D4: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void delete_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076520: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80076524: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80076528: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8007652C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80076530: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80076534: jal         0x80075B34
    // 0x80076538: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80076538: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007653C: beq         $v0, $zero, L_80076558
    if (ctx->r2 == 0) {
        // 0x80076540: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80076558;
    }
    // 0x80076540: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80076544: jal         0x80075D44
    // 0x80076548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80076548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8007654C: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x80076550: b           L_800765CC
    // 0x80076554: or          $v0, $t6, $s1
    ctx->r2 = ctx->r14 | ctx->r17;
        goto L_800765CC;
    // 0x80076554: or          $v0, $t6, $s1
    ctx->r2 = ctx->r14 | ctx->r17;
L_80076558:
    // 0x80076558: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8007655C: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x80076560: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80076564: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x80076568: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007656C: sll         $s1, $s0, 30
    ctx->r17 = S32(ctx->r16 << 30);
    // 0x80076570: addiu       $t9, $t9, 0x4598
    ctx->r25 = ADD32(ctx->r25, 0X4598);
    // 0x80076574: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80076578: ori         $t7, $s1, 0x9
    ctx->r15 = ctx->r17 | 0X9;
    // 0x8007657C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80076580: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80076584: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80076588: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007658C: jal         0x800D0AE0
    // 0x80076590: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    osPfsFileState_recomp(rdram, ctx);
        goto after_2;
    // 0x80076590: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x80076594: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80076598: bne         $v0, $zero, L_800765C0
    if (ctx->r2 != 0) {
        // 0x8007659C: addiu       $a3, $sp, 0x3E
        ctx->r7 = ADD32(ctx->r29, 0X3E);
            goto L_800765C0;
    }
    // 0x8007659C: addiu       $a3, $sp, 0x3E
    ctx->r7 = ADD32(ctx->r29, 0X3E);
    // 0x800765A0: lhu         $a1, 0x38($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X38);
    // 0x800765A4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800765A8: addiu       $t0, $sp, 0x3A
    ctx->r8 = ADD32(ctx->r29, 0X3A);
    // 0x800765AC: jal         0x800D0DD0
    // 0x800765B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    osPfsDeleteFile_recomp(rdram, ctx);
        goto after_3;
    // 0x800765B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_3:
    // 0x800765B4: bne         $v0, $zero, L_800765C0
    if (ctx->r2 != 0) {
        // 0x800765B8: nop
    
            goto L_800765C0;
    }
    // 0x800765B8: nop

    // 0x800765BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800765C0:
    // 0x800765C0: jal         0x80075D44
    // 0x800765C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_4;
    // 0x800765C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800765C8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_800765CC:
    // 0x800765CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800765D0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800765D4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800765D8: jr          $ra
    // 0x800765DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800765DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _saveBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064878: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006487C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80064880: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064884: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80064888: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8006488C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80064890: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80064894: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80064898: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8006489C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800648A0: beq         $at, $zero, L_800648AC
    if (ctx->r1 == 0) {
        // 0x800648A4: addu        $t0, $v0, $t7
        ctx->r8 = ADD32(ctx->r2, ctx->r15);
            goto L_800648AC;
    }
    // 0x800648A4: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x800648A8: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_800648AC:
    // 0x800648AC: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800648B0: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800648B4: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800648B8: addu        $a3, $t8, $a1
    ctx->r7 = ADD32(ctx->r24, ctx->r5);
    // 0x800648BC: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x800648C0: beq         $at, $zero, L_800649B4
    if (ctx->r1 == 0) {
        // 0x800648C4: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_800649B4;
    }
    // 0x800648C4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800648C8: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x800648CC: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x800648D0: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x800648D4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800648D8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800648DC: sra         $t4, $t1, 1
    ctx->r12 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800648E0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800648E4: andi        $t9, $t5, 0xFFFF
    ctx->r25 = ctx->r13 & 0XFFFF;
    // 0x800648E8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800648EC: or          $t3, $t8, $t9
    ctx->r11 = ctx->r24 | ctx->r25;
    // 0x800648F0: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800648F4: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800648F8: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800648FC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80064900: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80064904: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80064908: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8006490C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80064910: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80064914: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80064918: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8006491C: jal         0x800C9250
    // 0x80064920: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80064920: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80064924: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80064928: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8006492C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80064930: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80064934: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80064938: lui         $t5, 0x800
    ctx->r13 = S32(0X800 << 16);
    // 0x8006493C: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x80064940: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80064944: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80064948: subu        $t3, $a3, $t0
    ctx->r11 = SUB32(ctx->r7, ctx->r8);
    // 0x8006494C: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80064950: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x80064954: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80064958: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8006495C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80064960: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80064964: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064968: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8006496C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80064970: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80064974: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80064978: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8006497C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064980: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    // 0x80064984: jal         0x800C9250
    // 0x80064988: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80064988: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8006498C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80064990: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80064994: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80064998: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x8006499C: andi        $t5, $a2, 0xFFFF
    ctx->r13 = ctx->r6 & 0XFFFF;
    // 0x800649A0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800649A4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800649A8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800649AC: b           L_800649FC
    // 0x800649B0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800649FC;
    // 0x800649B0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800649B4:
    // 0x800649B4: lui         $t6, 0x800
    ctx->r14 = S32(0X800 << 16);
    // 0x800649B8: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800649BC: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800649C0: andi        $t4, $a2, 0xFFFF
    ctx->r12 = ctx->r6 & 0XFFFF;
    // 0x800649C4: sll         $t3, $t8, 16
    ctx->r11 = S32(ctx->r24 << 16);
    // 0x800649C8: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800649CC: addiu       $s0, $t9, 0x8
    ctx->r16 = ADD32(ctx->r25, 0X8);
    // 0x800649D0: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x800649D4: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800649D8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800649DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800649E0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800649E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800649E8: jal         0x800C9250
    // 0x800649EC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800649EC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800649F0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800649F4: nop

    // 0x800649F8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800649FC:
    // 0x800649FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80064A00: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80064A04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064A08: jr          $ra
    // 0x80064A0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80064A0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void hud_sound_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A799C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A79A0: lw          $t6, 0x7300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7300);
    // 0x800A79A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A79A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A79AC: bne         $t6, $zero, L_800A79D0
    if (ctx->r14 != 0) {
        // 0x800A79B0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800A79D0;
    }
    // 0x800A79B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A79B4: jal         0x8006ECE0
    // 0x800A79B8: nop

    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800A79B8: nop

    after_0:
    // 0x800A79BC: bne         $v0, $zero, L_800A79D0
    if (ctx->r2 != 0) {
        // 0x800A79C0: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A79D0;
    }
    // 0x800A79C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A79C4: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x800A79C8: jal         0x80001D04
    // 0x800A79CC: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800A79CC: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_1:
L_800A79D0:
    // 0x800A79D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A79D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A79D8: jr          $ra
    // 0x800A79DC: nop

    return;
    // 0x800A79DC: nop

;}
RECOMP_FUNC void func_80065A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065CC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065CC4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065CCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80065CD0: lbu         $v0, 0xDC($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XDC);
    // 0x80065CD4: lh          $t6, 0x2A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2A);
    // 0x80065CD8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80065CDC: beq         $t6, $v0, L_80065D50
    if (ctx->r14 == ctx->r2) {
        // 0x80065CE0: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80065D50;
    }
    // 0x80065CE0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80065CE4: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80065CE8: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80065CEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80065CF0: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80065CF4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80065CF8: addiu       $a2, $a3, 0x8C
    ctx->r6 = ADD32(ctx->r7, 0X8C);
    // 0x80065CFC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80065D00: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80065D04: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80065D08: jal         0x80065C14
    // 0x80065D0C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    alAuxBusParam(rdram, ctx);
        goto after_0;
    // 0x80065D0C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80065D10: lh          $t2, 0x2A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2A);
    // 0x80065D14: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80065D18: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80065D1C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80065D20: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80065D24: lw          $t1, 0x34($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X34);
    // 0x80065D28: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80065D2C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80065D30: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80065D34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80065D38: jal         0x80065C14
    // 0x80065D3C: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    alAuxBusParam(rdram, ctx);
        goto after_1;
    // 0x80065D3C: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    after_1:
    // 0x80065D40: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x80065D44: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80065D48: nop

    // 0x80065D4C: sb          $t4, 0xDC($t5)
    MEM_B(0XDC, ctx->r13) = ctx->r12;
L_80065D50:
    // 0x80065D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065D54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065D58: jr          $ra
    // 0x80065D5C: nop

    return;
    // 0x80065D5C: nop

;}
RECOMP_FUNC void guMtxIdentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4EA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D4EA4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D4EA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D4EAC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D4EB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D4EB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D4EB8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800D4EBC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800D4EC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800D4EC4:
    // 0x800D4EC4: bnel        $v0, $zero, L_800D4ED8
    if (ctx->r2 != 0) {
        // 0x800D4EC8: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_800D4ED8;
    }
    goto skip_0;
    // 0x800D4EC8: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x800D4ECC: b           L_800D4ED8
    // 0x800D4ED0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_800D4ED8;
    // 0x800D4ED0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800D4ED4: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_800D4ED8:
    // 0x800D4ED8: bnel        $v0, $a0, L_800D4EEC
    if (ctx->r2 != ctx->r4) {
        // 0x800D4EDC: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_800D4EEC;
    }
    goto skip_1;
    // 0x800D4EDC: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x800D4EE0: b           L_800D4EEC
    // 0x800D4EE4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_800D4EEC;
    // 0x800D4EE4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800D4EE8: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_800D4EEC:
    // 0x800D4EEC: bnel        $v0, $a1, L_800D4F00
    if (ctx->r2 != ctx->r5) {
        // 0x800D4EF0: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_800D4F00;
    }
    goto skip_2;
    // 0x800D4EF0: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x800D4EF4: b           L_800D4F00
    // 0x800D4EF8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_800D4F00;
    // 0x800D4EF8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x800D4EFC: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_800D4F00:
    // 0x800D4F00: bnel        $v0, $a2, L_800D4F14
    if (ctx->r2 != ctx->r6) {
        // 0x800D4F04: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_800D4F14;
    }
    goto skip_3;
    // 0x800D4F04: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x800D4F08: b           L_800D4F14
    // 0x800D4F0C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_800D4F14;
    // 0x800D4F0C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x800D4F10: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_800D4F14:
    // 0x800D4F14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D4F18: bne         $v0, $a3, L_800D4EC4
    if (ctx->r2 != ctx->r7) {
        // 0x800D4F1C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800D4EC4;
    }
    // 0x800D4F1C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800D4F20: jr          $ra
    // 0x800D4F24: nop

    return;
    // 0x800D4F24: nop

;}
RECOMP_FUNC void __voiceNeedsNoteKill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AC34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000AC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AC3C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8000AC40: lw          $a3, 0x50($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X50);
    // 0x8000AC44: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000AC48: beq         $a3, $zero, L_8000ACD0
    if (ctx->r7 == 0) {
        // 0x8000AC4C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8000ACD0;
    }
    // 0x8000AC4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000AC50: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_8000AC54:
    // 0x8000AC54: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x8000AC58: lh          $t7, 0xC($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XC);
    // 0x8000AC5C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000AC60: bne         $a0, $t7, L_8000ACC8
    if (ctx->r4 != ctx->r15) {
        // 0x8000AC64: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_8000ACC8;
    }
    // 0x8000AC64: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8000AC68: lw          $t8, 0x10($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X10);
    // 0x8000AC6C: nop

    // 0x8000AC70: bne         $a1, $t8, L_8000ACC8
    if (ctx->r5 != ctx->r24) {
        // 0x8000AC74: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_8000ACC8;
    }
    // 0x8000AC74: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000AC78: beq         $at, $zero, L_8000ACC0
    if (ctx->r1 == 0) {
        // 0x8000AC7C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8000ACC0;
    }
    // 0x8000AC7C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000AC80: beq         $v0, $zero, L_8000AC98
    if (ctx->r2 == 0) {
        // 0x8000AC84: nop
    
            goto L_8000AC98;
    }
    // 0x8000AC84: nop

    // 0x8000AC88: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8000AC8C: nop

    // 0x8000AC90: addu        $t2, $t9, $v1
    ctx->r10 = ADD32(ctx->r25, ctx->r3);
    // 0x8000AC94: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
L_8000AC98:
    // 0x8000AC98: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8000AC9C: jal         0x800C8CC0
    // 0x8000ACA0: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x8000ACA0: sb          $t1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r9;
    after_0:
    // 0x8000ACA4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8000ACA8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000ACAC: jal         0x800C8CF0
    // 0x8000ACB0: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    alLink(rdram, ctx);
        goto after_1;
    // 0x8000ACB0: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    after_1:
    // 0x8000ACB4: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
    // 0x8000ACB8: b           L_8000ACD4
    // 0x8000ACBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000ACD4;
    // 0x8000ACBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000ACC0:
    // 0x8000ACC0: b           L_8000ACD0
    // 0x8000ACC4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_8000ACD0;
    // 0x8000ACC4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8000ACC8:
    // 0x8000ACC8: bne         $v0, $zero, L_8000AC54
    if (ctx->r2 != 0) {
        // 0x8000ACCC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8000AC54;
    }
    // 0x8000ACCC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8000ACD0:
    // 0x8000ACD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000ACD4:
    // 0x8000ACD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000ACD8: jr          $ra
    // 0x8000ACDC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x8000ACDC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void directional_lighting_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B88C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B890: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B894: sh          $v0, 0x6924($at)
    MEM_H(0X6924, ctx->r1) = ctx->r2;
    // 0x8007B898: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B89C: jr          $ra
    // 0x8007B8A0: sh          $v0, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r2;
    return;
    // 0x8007B8A0: sh          $v0, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void obj_table_ids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010018: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001001C: lw          $v0, -0x4BC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BC4);
    // 0x80010020: jr          $ra
    // 0x80010024: nop

    return;
    // 0x80010024: nop

;}
RECOMP_FUNC void rendermode_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B820: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B824: sw          $zero, 0x691C($at)
    MEM_W(0X691C, ctx->r1) = 0;
    // 0x8007B828: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B82C: sw          $zero, 0x6914($at)
    MEM_W(0X6914, ctx->r1) = 0;
    // 0x8007B830: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B834: sh          $zero, 0x6920($at)
    MEM_H(0X6920, ctx->r1) = 0;
    // 0x8007B838: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B83C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007B840: sh          $t6, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r14;
    // 0x8007B844: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B848: sw          $zero, 0x6918($at)
    MEM_W(0X6918, ctx->r1) = 0;
    // 0x8007B84C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B850: sh          $zero, 0x6924($at)
    MEM_H(0X6924, ctx->r1) = 0;
    // 0x8007B854: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007B858: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007B85C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8007B860: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007B864: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007B868: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007B86C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007B870: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x8007B874: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007B878: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007B87C: addiu       $t1, $zero, 0x205
    ctx->r9 = ADD32(0, 0X205);
    // 0x8007B880: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8007B884: jr          $ra
    // 0x8007B888: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    return;
    // 0x8007B888: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
;}
RECOMP_FUNC void menu_imagegroup_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CDE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009CDEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009CDF0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009CDF4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009CDF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009CDFC: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8009CE00: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009CE04: beq         $s2, $t6, L_8009CE34
    if (ctx->r18 == ctx->r14) {
        // 0x8009CE08: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009CE34;
    }
    // 0x8009CE08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009CE0C: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x8009CE10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009CE14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8009CE18:
    // 0x8009CE18: jal         0x8009CE48
    // 0x8009CE1C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    menu_image_load(rdram, ctx);
        goto after_0;
    // 0x8009CE1C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x8009CE20: lh          $s1, 0x0($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X0);
    // 0x8009CE24: nop

    // 0x8009CE28: bne         $s2, $s1, L_8009CE18
    if (ctx->r18 != ctx->r17) {
        // 0x8009CE2C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009CE18;
    }
    // 0x8009CE2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009CE30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009CE34:
    // 0x8009CE34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009CE38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CE3C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009CE40: jr          $ra
    // 0x8009CE44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009CE44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sndp_set_param(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800049F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800049FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004A00: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80004A04: sh          $a1, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r5;
    // 0x80004A08: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80004A0C: beq         $a0, $zero, L_80004A2C
    if (ctx->r4 == 0) {
        // 0x80004A10: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80004A2C;
    }
    // 0x80004A10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80004A14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004A18: lw          $a0, -0x33D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33D4);
    // 0x80004A1C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80004A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004A24: jal         0x800C970C
    // 0x80004A28: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80004A28: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_0:
L_80004A2C:
    // 0x80004A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004A30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80004A34: jr          $ra
    // 0x80004A38: nop

    return;
    // 0x80004A38: nop

;}
RECOMP_FUNC void func_80054FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055010: addiu       $sp, $sp, -0x1A0
    ctx->r29 = ADD32(ctx->r29, -0X1A0);
    // 0x80055014: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80055018: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005501C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80055020: sw          $a2, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r6;
    // 0x80055024: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055028: lwc1        $f0, -0x2590($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2590);
    // 0x8005502C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80055030: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80055034: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80055038: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8005503C: bc1f        L_80055050
    if (!c1cs) {
        // 0x80055040: nop
    
            goto L_80055050;
    }
    // 0x80055040: nop

    // 0x80055044: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80055048: jal         0x8002AD08
    // 0x8005504C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_collision_mode(rdram, ctx);
        goto after_0;
    // 0x8005504C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
L_80055050:
    // 0x80055050: sh          $zero, 0x130($sp)
    MEM_H(0X130, ctx->r29) = 0;
    // 0x80055054: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x80055058: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005505C: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x80055060: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80055064: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80055068: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005506C: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x80055070: lh          $t8, 0x4($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4);
    // 0x80055074: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80055078: sh          $t8, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r24;
    // 0x8005507C: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    // 0x80055080: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80055084: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80055088: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x8005508C: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80055090: nop

    // 0x80055094: swc1        $f10, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f10.u32l;
    // 0x80055098: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005509C: jal         0x8006FE70
    // 0x800550A0: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_1;
    // 0x800550A0: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
    after_1:
    // 0x800550A4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800550A8: lw          $v1, -0x2518($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2518);
    // 0x800550AC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800550B0: addiu       $t1, $sp, 0x134
    ctx->r9 = ADD32(ctx->r29, 0X134);
    // 0x800550B4: addiu       $t2, $sp, 0x138
    ctx->r10 = ADD32(ctx->r29, 0X138);
    // 0x800550B8: addiu       $t3, $sp, 0x13C
    ctx->r11 = ADD32(ctx->r29, 0X13C);
    // 0x800550BC: addiu       $t4, $sp, 0xE0
    ctx->r12 = ADD32(ctx->r29, 0XE0);
    // 0x800550C0: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
L_800550C4:
    // 0x800550C4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800550C8: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x800550CC: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x800550D0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800550D4: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800550D8: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800550DC: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800550E0: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x800550E4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800550E8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800550EC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800550F0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800550F4: jal         0x8006F88C
    // 0x800550F8: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x800550F8: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    after_2:
    // 0x800550FC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80055100: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80055104: lw          $t9, -0x2518($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2518);
    // 0x80055108: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8005510C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80055110: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80055114: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80055118: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8005511C: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x80055120: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80055124: addiu       $t6, $sp, 0x5C
    ctx->r14 = ADD32(ctx->r29, 0X5C);
    // 0x80055128: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005512C: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x80055130: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80055134: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80055138: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8005513C: sb          $t5, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r13;
    // 0x80055140: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80055144: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80055148: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x8005514C: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80055150: bne         $at, $zero, L_800550C4
    if (ctx->r1 != 0) {
        // 0x80055154: swc1        $f6, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->f6.u32l;
            goto L_800550C4;
    }
    // 0x80055154: swc1        $f6, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->f6.u32l;
    // 0x80055158: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005515C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80055160: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80055164: addiu       $t0, $t0, -0x2534
    ctx->r8 = ADD32(ctx->r8, -0X2534);
    // 0x80055168: addiu       $v1, $v1, -0x2538
    ctx->r3 = ADD32(ctx->r3, -0X2538);
    // 0x8005516C: sw          $zero, 0x190($sp)
    MEM_W(0X190, ctx->r29) = 0;
    // 0x80055170: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x80055174: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x80055178: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8005517C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055180: bne         $t7, $at, L_80055198
    if (ctx->r15 != ctx->r1) {
        // 0x80055184: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80055198;
    }
    // 0x80055184: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80055188: lb          $t8, 0x1D7($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D7);
    // 0x8005518C: nop

    // 0x80055190: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x80055194: beq         $at, $zero, L_800551DC
    if (ctx->r1 == 0) {
        // 0x80055198: addiu       $t9, $sp, 0x134
        ctx->r25 = ADD32(ctx->r29, 0X134);
            goto L_800551DC;
    }
L_80055198:
    // 0x80055198: addiu       $t9, $sp, 0x134
    ctx->r25 = ADD32(ctx->r29, 0X134);
    // 0x8005519C: addiu       $t5, $sp, 0xE0
    ctx->r13 = ADD32(ctx->r29, 0XE0);
    // 0x800551A0: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x800551A4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800551A8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800551AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800551B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800551B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800551B8: addiu       $a2, $sp, 0x190
    ctx->r6 = ADD32(ctx->r29, 0X190);
    // 0x800551BC: jal         0x8001727C
    // 0x800551C0: addiu       $a3, $s0, 0xD8
    ctx->r7 = ADD32(ctx->r16, 0XD8);
    collision_objectmodel(rdram, ctx);
        goto after_3;
    // 0x800551C0: addiu       $a3, $s0, 0xD8
    ctx->r7 = ADD32(ctx->r16, 0XD8);
    after_3:
    // 0x800551C4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800551C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800551CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800551D0: addiu       $t0, $t0, -0x2534
    ctx->r8 = ADD32(ctx->r8, -0X2534);
    // 0x800551D4: addiu       $v1, $v1, -0x2538
    ctx->r3 = ADD32(ctx->r3, -0X2538);
    // 0x800551D8: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_800551DC:
    // 0x800551DC: andi        $t7, $t1, 0x80
    ctx->r15 = ctx->r9 & 0X80;
    // 0x800551E0: beq         $t7, $zero, L_800552E0
    if (ctx->r15 == 0) {
        // 0x800551E4: addiu       $a1, $s0, 0xD8
        ctx->r5 = ADD32(ctx->r16, 0XD8);
            goto L_800552E0;
    }
    // 0x800551E4: addiu       $a1, $s0, 0xD8
    ctx->r5 = ADD32(ctx->r16, 0XD8);
    // 0x800551E8: lwc1        $f8, 0x134($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X134);
    // 0x800551EC: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800551F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800551F4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800551F8: lwc1        $f6, 0x13C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x800551FC: swc1        $f4, -0x2538($at)
    MEM_W(-0X2538, ctx->r1) = ctx->f4.u32l;
    // 0x80055200: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80055204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055208: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005520C: lwc1        $f4, 0x140($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X140);
    // 0x80055210: swc1        $f10, -0x2534($at)
    MEM_W(-0X2534, ctx->r1) = ctx->f10.u32l;
    // 0x80055214: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80055218: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005521C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80055220: lwc1        $f10, 0x148($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X148);
    // 0x80055224: swc1        $f8, -0x2538($at)
    MEM_W(-0X2538, ctx->r1) = ctx->f8.u32l;
    // 0x80055228: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8005522C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055230: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80055234: lwc1        $f8, 0x14C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x80055238: swc1        $f6, -0x2534($at)
    MEM_W(-0X2534, ctx->r1) = ctx->f6.u32l;
    // 0x8005523C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80055240: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055244: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80055248: lwc1        $f6, 0x154($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X154);
    // 0x8005524C: swc1        $f4, -0x2538($at)
    MEM_W(-0X2538, ctx->r1) = ctx->f4.u32l;
    // 0x80055250: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80055254: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055258: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005525C: lwc1        $f4, 0x158($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X158);
    // 0x80055260: swc1        $f10, -0x2534($at)
    MEM_W(-0X2534, ctx->r1) = ctx->f10.u32l;
    // 0x80055264: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80055268: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005526C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80055270: lwc1        $f10, 0x160($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X160);
    // 0x80055274: swc1        $f8, -0x2538($at)
    MEM_W(-0X2538, ctx->r1) = ctx->f8.u32l;
    // 0x80055278: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8005527C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055280: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80055284: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80055288: swc1        $f6, -0x2534($at)
    MEM_W(-0X2534, ctx->r1) = ctx->f6.u32l;
    // 0x8005528C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80055290: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80055294: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80055298: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8005529C: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800552A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800552A4: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x800552A8: and         $t9, $t1, $at
    ctx->r25 = ctx->r9 & ctx->r1;
    // 0x800552AC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x800552B0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800552B4: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800552B8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800552BC: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x800552C0: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800552C4: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800552C8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800552CC: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x800552D0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800552D4: sh          $t8, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r24;
    // 0x800552D8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800552DC: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
L_800552E0:
    // 0x800552E0: beq         $t1, $zero, L_8005535C
    if (ctx->r9 == 0) {
        // 0x800552E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005535C;
    }
    // 0x800552E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800552E8: lwc1        $f8, 0x138($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800552EC: lwc1        $f10, 0x144($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800552F0: add.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800552F4: lwc1        $f4, 0x150($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X150);
    // 0x800552F8: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800552FC: lwc1        $f6, 0x15C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x80055300: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80055304: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80055308: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8005530C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80055310: swc1        $f0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f0.u32l;
    // 0x80055314: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80055318: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005531C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80055320: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80055324: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80055328: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005532C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80055330: swc1        $f8, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f8.u32l;
    // 0x80055334: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80055338: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005533C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80055340: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80055344: sub.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d - ctx->f8.d;
    // 0x80055348: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8005534C: nop

    // 0x80055350: bc1f        L_8005535C
    if (!c1cs) {
        // 0x80055354: nop
    
            goto L_8005535C;
    }
    // 0x80055354: nop

    // 0x80055358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005535C:
    // 0x8005535C: lb          $a3, 0x1D6($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055360: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x80055364: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80055368: sb          $v0, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r2;
    // 0x8005536C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80055370: jal         0x80031170
    // 0x80055374: addiu       $a2, $sp, 0x134
    ctx->r6 = ADD32(ctx->r29, 0X134);
    generate_collision_candidates(rdram, ctx);
        goto after_4;
    // 0x80055374: addiu       $a2, $sp, 0x134
    ctx->r6 = ADD32(ctx->r29, 0X134);
    after_4:
    // 0x80055378: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8005537C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80055380: addiu       $t6, $sp, 0x190
    ctx->r14 = ADD32(ctx->r29, 0X190);
    // 0x80055384: sw          $zero, 0x190($sp)
    MEM_W(0X190, ctx->r29) = 0;
    // 0x80055388: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005538C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80055390: addiu       $a1, $sp, 0x134
    ctx->r5 = ADD32(ctx->r29, 0X134);
    // 0x80055394: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x80055398: jal         0x80031640
    // 0x8005539C: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    resolve_collisions(rdram, ctx);
        goto after_5;
    // 0x8005539C: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x800553A0: sb          $v0, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = ctx->r2;
    // 0x800553A4: addiu       $a0, $sp, 0x180
    ctx->r4 = ADD32(ctx->r29, 0X180);
    // 0x800553A8: addiu       $a1, $sp, 0x178
    ctx->r5 = ADD32(ctx->r29, 0X178);
    // 0x800553AC: jal         0x8002AD14
    // 0x800553B0: addiu       $a2, $sp, 0x17C
    ctx->r6 = ADD32(ctx->r29, 0X17C);
    get_collision_normal(rdram, ctx);
        goto after_6;
    // 0x800553B0: addiu       $a2, $sp, 0x17C
    ctx->r6 = ADD32(ctx->r29, 0X17C);
    after_6:
    // 0x800553B4: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800553B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800553BC: beq         $v0, $zero, L_800555C4
    if (ctx->r2 == 0) {
        // 0x800553C0: sw          $v0, 0x184($sp)
        MEM_W(0X184, ctx->r29) = ctx->r2;
            goto L_800555C4;
    }
    // 0x800553C0: sw          $v0, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r2;
    // 0x800553C4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800553C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800553CC: lwc1        $f6, 0x180($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X180);
    // 0x800553D0: lwc1        $f8, 0x17C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x800553D4: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800553D8: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x800553DC: mul.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800553E0: jal         0x80070990
    // 0x800553E4: nop

    arctan2_f(rdram, ctx);
        goto after_7;
    // 0x800553E4: nop

    after_7:
    // 0x800553E8: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x800553EC: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800553F0: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x800553F4: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x800553F8: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800553FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80055400: slti        $at, $t6, 0x2000
    ctx->r1 = SIGNED(ctx->r14) < 0X2000 ? 1 : 0;
    // 0x80055404: beq         $at, $zero, L_80055414
    if (ctx->r1 == 0) {
        // 0x80055408: slti        $at, $t6, -0x1FFF
        ctx->r1 = SIGNED(ctx->r14) < -0X1FFF ? 1 : 0;
            goto L_80055414;
    }
    // 0x80055408: slti        $at, $t6, -0x1FFF
    ctx->r1 = SIGNED(ctx->r14) < -0X1FFF ? 1 : 0;
    // 0x8005540C: beq         $at, $zero, L_80055420
    if (ctx->r1 == 0) {
        // 0x80055410: nop
    
            goto L_80055420;
    }
    // 0x80055410: nop

L_80055414:
    // 0x80055414: lb          $t7, 0x1D6($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055418: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005541C: bne         $t7, $at, L_800555C4
    if (ctx->r15 != ctx->r1) {
        // 0x80055420: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800555C4;
    }
L_80055420:
    // 0x80055420: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80055424: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80055428: lwc1        $f7, 0x6DC8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6DC8);
    // 0x8005542C: lwc1        $f6, 0x6DCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6DCC);
    // 0x80055430: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80055434: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80055438: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005543C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80055440: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80055444: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80055448: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8005544C: swc1        $f10, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f10.u32l;
    // 0x80055450: bc1f        L_80055460
    if (!c1cs) {
        // 0x80055454: nop
    
            goto L_80055460;
    }
    // 0x80055454: nop

    // 0x80055458: neg.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = -ctx->f10.fl;
    // 0x8005545C: swc1        $f0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f0.u32l;
L_80055460:
    // 0x80055460: lwc1        $f0, 0x178($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80055464: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80055468: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8005546C: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80055470: nop

    // 0x80055474: bc1f        L_800554B4
    if (!c1cs) {
        // 0x80055478: nop
    
            goto L_800554B4;
    }
    // 0x80055478: nop

    // 0x8005547C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80055480: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80055484: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80055488: mul.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f6.d);
    // 0x8005548C: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    // 0x80055490: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80055494: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80055498: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8005549C: jal         0x80072670
    // 0x800554A0: nop

    rumble_set_fade(rdram, ctx);
        goto after_8;
    // 0x800554A0: nop

    after_8:
    // 0x800554A4: lwc1        $f0, 0x178($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X178);
    // 0x800554A8: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x800554AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800554B0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_800554B4:
    // 0x800554B4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800554B8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800554BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800554C0: swc1        $f0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f0.u32l;
    // 0x800554C4: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x800554C8: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x800554CC: bc1f        L_800555C4
    if (!c1cs) {
        // 0x800554D0: nop
    
            goto L_800555C4;
    }
    // 0x800554D0: nop

    // 0x800554D4: lbu         $t8, 0x1F3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1F3);
    // 0x800554D8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800554DC: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x800554E0: sb          $t9, 0x1F3($s0)
    MEM_B(0X1F3, ctx->r16) = ctx->r25;
    // 0x800554E4: lw          $t5, -0x2524($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2524);
    // 0x800554E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800554EC: beq         $t5, $at, L_80055508
    if (ctx->r13 == ctx->r1) {
        // 0x800554F0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80055508;
    }
    // 0x800554F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800554F4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800554F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800554FC: lw          $t6, -0x2578($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2578);
    // 0x80055500: nop

    // 0x80055504: swc1        $f6, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f6.u32l;
L_80055508:
    // 0x80055508: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8005550C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055510: beq         $t8, $at, L_80055548
    if (ctx->r24 == ctx->r1) {
        // 0x80055514: sb          $t7, 0x1D2($s0)
        MEM_B(0X1D2, ctx->r16) = ctx->r15;
            goto L_80055548;
    }
    // 0x80055514: sb          $t7, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r15;
    // 0x80055518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005551C: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x80055520: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80055524: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    // 0x80055528: jal         0x800570F8
    // 0x8005552C: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    play_random_character_voice(rdram, ctx);
        goto after_9;
    // 0x8005552C: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    after_9:
    // 0x80055530: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80055534: jal         0x80057088
    // 0x80055538: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    racer_play_sound(rdram, ctx);
        goto after_10;
    // 0x80055538: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_10:
    // 0x8005553C: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x80055540: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80055544: nop

L_80055548:
    // 0x80055548: lbu         $t9, 0x1EF($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1EF);
    // 0x8005554C: lb          $t6, 0x1D6($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055550: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80055554: ori         $t5, $t9, 0x4
    ctx->r13 = ctx->r25 | 0X4;
    // 0x80055558: bne         $t6, $at, L_80055580
    if (ctx->r14 != ctx->r1) {
        // 0x8005555C: sb          $t5, 0x1EF($s0)
        MEM_B(0X1EF, ctx->r16) = ctx->r13;
            goto L_80055580;
    }
    // 0x8005555C: sb          $t5, 0x1EF($s0)
    MEM_B(0X1EF, ctx->r16) = ctx->r13;
    // 0x80055560: lwc1        $f0, 0x178($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80055564: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80055568: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005556C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80055570: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80055574: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80055578: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8005557C: swc1        $f0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->f0.u32l;
L_80055580:
    // 0x80055580: lwc1        $f6, 0x180($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X180);
    // 0x80055584: lwc1        $f8, 0x178($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80055588: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005558C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80055590: swc1        $f10, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f10.u32l;
    // 0x80055594: lwc1        $f6, 0x178($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X178);
    // 0x80055598: lwc1        $f4, 0x17C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X17C);
    // 0x8005559C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800555A0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800555A4: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800555A8: swc1        $f8, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f8.u32l;
    // 0x800555AC: lwc1        $f6, 0x6DD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6DD4);
    // 0x800555B0: lwc1        $f7, 0x6DD0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6DD0);
    // 0x800555B4: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x800555B8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800555BC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800555C0: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
L_800555C4:
    // 0x800555C4: lb          $t7, 0x5F($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X5F);
    // 0x800555C8: nop

    // 0x800555CC: beq         $t7, $zero, L_80055648
    if (ctx->r15 == 0) {
        // 0x800555D0: nop
    
            goto L_80055648;
    }
    // 0x800555D0: nop

    // 0x800555D4: lw          $t8, 0x190($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X190);
    // 0x800555D8: nop

    // 0x800555DC: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800555E0: bne         $at, $zero, L_80055648
    if (ctx->r1 != 0) {
        // 0x800555E4: nop
    
            goto L_80055648;
    }
    // 0x800555E4: nop

    // 0x800555E8: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800555EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800555F0: beq         $t9, $at, L_8005562C
    if (ctx->r25 == ctx->r1) {
        // 0x800555F4: nop
    
            goto L_8005562C;
    }
    // 0x800555F4: nop

    // 0x800555F8: lw          $t5, 0x20($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X20);
    // 0x800555FC: nop

    // 0x80055600: bne         $t5, $zero, L_8005562C
    if (ctx->r13 != 0) {
        // 0x80055604: nop
    
            goto L_8005562C;
    }
    // 0x80055604: nop

    // 0x80055608: lh          $t6, 0x18E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18E);
    // 0x8005560C: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x80055610: bgtz        $t6, L_8005562C
    if (SIGNED(ctx->r14) > 0) {
        // 0x80055614: addiu       $a1, $s0, 0x20
        ctx->r5 = ADD32(ctx->r16, 0X20);
            goto L_8005562C;
    }
    // 0x80055614: addiu       $a1, $s0, 0x20
    ctx->r5 = ADD32(ctx->r16, 0X20);
    // 0x80055618: jal         0x80001D04
    // 0x8005561C: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    sound_play(rdram, ctx);
        goto after_11;
    // 0x8005561C: sw          $t1, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r9;
    after_11:
    // 0x80055620: lw          $t1, 0x18C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18C);
    // 0x80055624: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80055628: nop

L_8005562C:
    // 0x8005562C: lb          $t7, 0x1ED($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1ED);
    // 0x80055630: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80055634: bne         $t7, $zero, L_80055644
    if (ctx->r15 != 0) {
        // 0x80055638: addiu       $t9, $zero, 0x3C
        ctx->r25 = ADD32(0, 0X3C);
            goto L_80055644;
    }
    // 0x80055638: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8005563C: b           L_80055648
    // 0x80055640: sb          $t8, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r24;
        goto L_80055648;
    // 0x80055640: sb          $t8, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r24;
L_80055644:
    // 0x80055644: sb          $t9, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r25;
L_80055648:
    // 0x80055648: lb          $t5, 0x1E3($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E3);
    // 0x8005564C: sb          $t1, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r9;
    // 0x80055650: or          $t6, $t5, $t1
    ctx->r14 = ctx->r13 | ctx->r9;
    // 0x80055654: sb          $t6, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = ctx->r14;
    // 0x80055658: lb          $v0, 0x1E3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E3);
    // 0x8005565C: sb          $zero, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = 0;
    // 0x80055660: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80055664: beq         $t7, $zero, L_8005567C
    if (ctx->r15 == 0) {
        // 0x80055668: addiu       $v1, $sp, 0x134
        ctx->r3 = ADD32(ctx->r29, 0X134);
            goto L_8005567C;
    }
    // 0x80055668: addiu       $v1, $sp, 0x134
    ctx->r3 = ADD32(ctx->r29, 0X134);
    // 0x8005566C: lb          $t8, 0x1E2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E2);
    // 0x80055670: lb          $v0, 0x1E3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E3);
    // 0x80055674: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80055678: sb          $t9, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r25;
L_8005567C:
    // 0x8005567C: sll         $t5, $v0, 30
    ctx->r13 = S32(ctx->r2 << 30);
    // 0x80055680: bgez        $t5, L_80055698
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80055684: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_80055698;
    }
    // 0x80055684: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80055688: lb          $t6, 0x1E2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005568C: lb          $v0, 0x1E3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E3);
    // 0x80055690: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80055694: sb          $t7, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r15;
L_80055698:
    // 0x80055698: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x8005569C: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x800556A0: beq         $t9, $zero, L_800556B8
    if (ctx->r25 == 0) {
        // 0x800556A4: or          $t1, $t8, $zero
        ctx->r9 = ctx->r24 | 0;
            goto L_800556B8;
    }
    // 0x800556A4: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x800556A8: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x800556AC: lb          $v0, 0x1E3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E3);
    // 0x800556B0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800556B4: sb          $t6, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r14;
L_800556B8:
    // 0x800556B8: sll         $t7, $t1, 1
    ctx->r15 = S32(ctx->r9 << 1);
    // 0x800556BC: and         $t8, $v0, $t7
    ctx->r24 = ctx->r2 & ctx->r15;
    // 0x800556C0: beq         $t8, $zero, L_800556D8
    if (ctx->r24 == 0) {
        // 0x800556C4: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800556D8;
    }
    // 0x800556C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800556C8: lb          $t9, 0x1E2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E2);
    // 0x800556CC: nop

    // 0x800556D0: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x800556D4: sb          $t5, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r13;
L_800556D8:
    // 0x800556D8: addiu       $a0, $sp, 0x164
    ctx->r4 = ADD32(ctx->r29, 0X164);
L_800556DC:
    // 0x800556DC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800556E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800556E4: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800556E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800556EC: bne         $at, $zero, L_800556DC
    if (ctx->r1 != 0) {
        // 0x800556F0: swc1        $f4, 0xD4($v0)
        MEM_W(0XD4, ctx->r2) = ctx->f4.u32l;
            goto L_800556DC;
    }
    // 0x800556F0: swc1        $f4, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f4.u32l;
    // 0x800556F4: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x800556F8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800556FC: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
L_80055700:
    // 0x80055700: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80055704: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80055708: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8005570C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80055710: bne         $at, $zero, L_80055700
    if (ctx->r1 != 0) {
        // 0x80055714: sb          $t6, 0x1DB($v1)
        MEM_B(0X1DB, ctx->r3) = ctx->r14;
            goto L_80055700;
    }
    // 0x80055714: sb          $t6, 0x1DB($v1)
    MEM_B(0X1DB, ctx->r3) = ctx->r14;
    // 0x80055718: swc1        $f16, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f16.u32l;
    // 0x8005571C: swc1        $f16, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f16.u32l;
    // 0x80055720: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
    // 0x80055724: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80055728: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8005572C:
    // 0x8005572C: lwc1        $f6, 0xD8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x80055730: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80055734: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x80055738: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005573C: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80055740: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x80055744: lwc1        $f4, 0xDC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XDC);
    // 0x80055748: slti        $at, $a0, 0xC
    ctx->r1 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // 0x8005574C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80055750: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80055754: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
    // 0x80055758: lwc1        $f10, 0xE0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE0);
    // 0x8005575C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80055760: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80055764: bne         $at, $zero, L_8005572C
    if (ctx->r1 != 0) {
        // 0x80055768: swc1        $f6, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
            goto L_8005572C;
    }
    // 0x80055768: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8005576C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80055770: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80055774: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80055778: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8005577C: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80055780: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80055784: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x80055788: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005578C: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x80055790: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80055794: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80055798: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8005579C: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x800557A0: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800557A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800557A8: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800557AC: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    // 0x800557B0: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x800557B4: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800557B8: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x800557BC: nop

    // 0x800557C0: negu        $t5, $t9
    ctx->r13 = SUB32(0, ctx->r25);
    // 0x800557C4: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x800557C8: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x800557CC: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x800557D0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800557D4: sh          $t7, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r15;
    // 0x800557D8: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800557DC: nop

    // 0x800557E0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800557E4: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x800557E8: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800557EC: nop

    // 0x800557F0: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800557F4: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x800557F8: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800557FC: nop

    // 0x80055800: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80055804: jal         0x800700B4
    // 0x80055808: swc1        $f8, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f8.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_12;
    // 0x80055808: swc1        $f8, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f8.u32l;
    after_12:
    // 0x8005580C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80055810: addiu       $t0, $sp, 0x11C
    ctx->r8 = ADD32(ctx->r29, 0X11C);
    // 0x80055814: addiu       $t1, $sp, 0x108
    ctx->r9 = ADD32(ctx->r29, 0X108);
    // 0x80055818: addiu       $v1, $sp, 0xF4
    ctx->r3 = ADD32(ctx->r29, 0XF4);
L_8005581C:
    // 0x8005581C: lw          $a1, 0xD8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XD8);
    // 0x80055820: lw          $a2, 0xDC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XDC);
    // 0x80055824: lw          $a3, 0xE0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE0);
    // 0x80055828: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8005582C: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x80055830: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x80055834: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80055838: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8005583C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80055840: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80055844: jal         0x8006F88C
    // 0x80055848: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    mtxf_transform_point(rdram, ctx);
        goto after_13;
    // 0x80055848: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_13:
    // 0x8005584C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80055850: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80055854: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80055858: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8005585C: addiu       $t8, $sp, 0x104
    ctx->r24 = ADD32(ctx->r29, 0X104);
    // 0x80055860: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80055864: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80055868: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8005586C: bne         $v1, $t8, L_8005581C
    if (ctx->r3 != ctx->r24) {
        // 0x80055870: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_8005581C;
    }
    // 0x80055870: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80055874: lb          $t9, 0x1D6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055878: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005587C: beq         $t9, $at, L_800559A0
    if (ctx->r25 == ctx->r1) {
        // 0x80055880: nop
    
            goto L_800559A0;
    }
    // 0x80055880: nop

    // 0x80055884: lwc1        $f10, 0x120($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80055888: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8005588C: lwc1        $f6, 0xF8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80055890: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80055894: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80055898: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8005589C: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800558A0: lwc1        $f10, 0x128($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X128);
    // 0x800558A4: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800558A8: lwc1        $f6, 0x100($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800558AC: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800558B0: swc1        $f18, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f18.u32l;
    // 0x800558B4: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800558B8: swc1        $f16, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->f16.u32l;
    // 0x800558BC: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800558C0: jal         0x80070990
    // 0x800558C4: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    arctan2_f(rdram, ctx);
        goto after_14;
    // 0x800558C4: sub.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f0.fl;
    after_14:
    // 0x800558C8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800558CC: addu        $a0, $v0, $at
    ctx->r4 = ADD32(ctx->r2, ctx->r1);
    // 0x800558D0: andi        $t5, $a0, 0xFFFF
    ctx->r13 = ctx->r4 & 0XFFFF;
    // 0x800558D4: lb          $t7, 0x1D2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D2);
    // 0x800558D8: sll         $v1, $t5, 16
    ctx->r3 = S32(ctx->r13 << 16);
    // 0x800558DC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800558E0: sra         $t6, $v1, 16
    ctx->r14 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800558E4: bne         $a1, $t7, L_80055910
    if (ctx->r5 != ctx->r15) {
        // 0x800558E8: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80055910;
    }
    // 0x800558E8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800558EC: sll         $v0, $t5, 16
    ctx->r2 = S32(ctx->r13 << 16);
    // 0x800558F0: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800558F4: blez        $t8, L_80055904
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800558F8: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80055904;
    }
    // 0x800558F8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800558FC: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x80055900: sh          $t9, 0x19C($s0)
    MEM_H(0X19C, ctx->r16) = ctx->r25;
L_80055904:
    // 0x80055904: bgez        $v0, L_80055910
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80055908: addiu       $t5, $zero, -0x800
        ctx->r13 = ADD32(0, -0X800);
            goto L_80055910;
    }
    // 0x80055908: addiu       $t5, $zero, -0x800
    ctx->r13 = ADD32(0, -0X800);
    // 0x8005590C: sh          $t5, 0x19C($s0)
    MEM_H(0X19C, ctx->r16) = ctx->r13;
L_80055910:
    // 0x80055910: lb          $t6, 0x1D2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D2);
    // 0x80055914: nop

    // 0x80055918: beq         $t6, $zero, L_8005592C
    if (ctx->r14 == 0) {
        // 0x8005591C: slti        $at, $v1, 0x1F5
        ctx->r1 = SIGNED(ctx->r3) < 0X1F5 ? 1 : 0;
            goto L_8005592C;
    }
    // 0x8005591C: slti        $at, $v1, 0x1F5
    ctx->r1 = SIGNED(ctx->r3) < 0X1F5 ? 1 : 0;
    // 0x80055920: lh          $v1, 0x19C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X19C);
    // 0x80055924: nop

    // 0x80055928: slti        $at, $v1, 0x1F5
    ctx->r1 = SIGNED(ctx->r3) < 0X1F5 ? 1 : 0;
L_8005592C:
    // 0x8005592C: beq         $at, $zero, L_8005593C
    if (ctx->r1 == 0) {
        // 0x80055930: slti        $at, $v1, -0x1F4
        ctx->r1 = SIGNED(ctx->r3) < -0X1F4 ? 1 : 0;
            goto L_8005593C;
    }
    // 0x80055930: slti        $at, $v1, -0x1F4
    ctx->r1 = SIGNED(ctx->r3) < -0X1F4 ? 1 : 0;
    // 0x80055934: beq         $at, $zero, L_8005596C
    if (ctx->r1 == 0) {
        // 0x80055938: lh          $t8, 0x130($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X130);
            goto L_8005596C;
    }
    // 0x80055938: lh          $t8, 0x130($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X130);
L_8005593C:
    // 0x8005593C: lw          $t7, 0x10C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10C);
    // 0x80055940: lh          $t5, 0x1A2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A2);
    // 0x80055944: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055948: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
    // 0x8005594C: mflo        $t8
    ctx->r24 = lo;
    // 0x80055950: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80055954: sw          $t9, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r25;
    // 0x80055958: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005595C: mflo        $t6
    ctx->r14 = lo;
    // 0x80055960: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80055964: sh          $t7, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r15;
    // 0x80055968: lh          $t8, 0x130($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X130);
L_8005596C:
    // 0x8005596C: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
    // 0x80055970: beq         $t8, $zero, L_8005597C
    if (ctx->r24 == 0) {
        // 0x80055974: sll         $t5, $t9, 18
        ctx->r13 = S32(ctx->r25 << 18);
            goto L_8005597C;
    }
    // 0x80055974: sll         $t5, $t9, 18
    ctx->r13 = S32(ctx->r25 << 18);
    // 0x80055978: sra         $v1, $t5, 16
    ctx->r3 = S32(SIGNED(ctx->r13) >> 16);
L_8005597C:
    // 0x8005597C: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x80055980: sra         $t8, $v1, 2
    ctx->r24 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80055984: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80055988: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
    // 0x8005598C: lh          $t6, 0x1A2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A2);
    // 0x80055990: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x80055994: nop

    // 0x80055998: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8005599C: sh          $t7, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r15;
L_800559A0:
    // 0x800559A0: lwc1        $f10, 0xFC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800559A4: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800559A8: lwc1        $f6, 0x110($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X110);
    // 0x800559AC: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800559B0: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800559B4: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800559B8: swc1        $f12, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->f12.u32l;
    // 0x800559BC: jal         0x80070990
    // 0x800559C0: swc1        $f14, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f14.u32l;
    arctan2_f(rdram, ctx);
        goto after_15;
    // 0x800559C0: swc1        $f14, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f14.u32l;
    after_15:
    // 0x800559C4: lw          $t8, 0x184($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X184);
    // 0x800559C8: nop

    // 0x800559CC: bne         $t8, $zero, L_800559E4
    if (ctx->r24 != 0) {
        // 0x800559D0: nop
    
            goto L_800559E4;
    }
    // 0x800559D0: nop

    // 0x800559D4: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x800559D8: addiu       $t6, $v0, -0x4000
    ctx->r14 = ADD32(ctx->r2, -0X4000);
    // 0x800559DC: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800559E0: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
L_800559E4:
    // 0x800559E4: lwc1        $f10, 0x120($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800559E8: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800559EC: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800559F0: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800559F4: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800559F8: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800559FC: swc1        $f12, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->f12.u32l;
    // 0x80055A00: jal         0x80070990
    // 0x80055A04: swc1        $f14, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f14.u32l;
    arctan2_f(rdram, ctx);
        goto after_16;
    // 0x80055A04: swc1        $f14, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->f14.u32l;
    after_16:
    // 0x80055A08: lw          $t8, 0x184($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X184);
    // 0x80055A0C: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x80055A10: bne         $t8, $zero, L_80055A28
    if (ctx->r24 != 0) {
        // 0x80055A14: nop
    
            goto L_80055A28;
    }
    // 0x80055A14: nop

    // 0x80055A18: lh          $t5, 0x1A4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A4);
    // 0x80055A1C: subu        $t7, $t9, $v0
    ctx->r15 = SUB32(ctx->r25, ctx->r2);
    // 0x80055A20: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80055A24: sh          $t8, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r24;
L_80055A28:
    // 0x80055A28: lb          $v0, 0x1D6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055A2C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80055A30: beq         $v0, $at, L_80055AB0
    if (ctx->r2 == ctx->r1) {
        // 0x80055A34: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80055AB0;
    }
    // 0x80055A34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80055A38: beq         $v0, $at, L_80055AB0
    if (ctx->r2 == ctx->r1) {
        // 0x80055A3C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80055AB0;
    }
    // 0x80055A3C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80055A40: beq         $v0, $at, L_80055AB0
    if (ctx->r2 == ctx->r1) {
        // 0x80055A44: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80055AB0;
    }
    // 0x80055A44: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80055A48: beq         $v0, $at, L_80055AB4
    if (ctx->r2 == ctx->r1) {
        // 0x80055A4C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80055AB4;
    }
    // 0x80055A4C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80055A50: lh          $v0, 0x1A4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A4);
    // 0x80055A54: addiu       $t9, $zero, 0x3400
    ctx->r25 = ADD32(0, 0X3400);
    // 0x80055A58: slti        $at, $v0, 0x3401
    ctx->r1 = SIGNED(ctx->r2) < 0X3401 ? 1 : 0;
    // 0x80055A5C: bne         $at, $zero, L_80055A70
    if (ctx->r1 != 0) {
        // 0x80055A60: addiu       $t6, $zero, -0x3400
        ctx->r14 = ADD32(0, -0X3400);
            goto L_80055A70;
    }
    // 0x80055A60: addiu       $t6, $zero, -0x3400
    ctx->r14 = ADD32(0, -0X3400);
    // 0x80055A64: sh          $t9, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r25;
    // 0x80055A68: lh          $v0, 0x1A4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A4);
    // 0x80055A6C: nop

L_80055A70:
    // 0x80055A70: slti        $at, $v0, -0x3400
    ctx->r1 = SIGNED(ctx->r2) < -0X3400 ? 1 : 0;
    // 0x80055A74: beq         $at, $zero, L_80055A80
    if (ctx->r1 == 0) {
        // 0x80055A78: addiu       $t5, $zero, 0x3400
        ctx->r13 = ADD32(0, 0X3400);
            goto L_80055A80;
    }
    // 0x80055A78: addiu       $t5, $zero, 0x3400
    ctx->r13 = ADD32(0, 0X3400);
    // 0x80055A7C: sh          $t6, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r14;
L_80055A80:
    // 0x80055A80: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    // 0x80055A84: addiu       $t7, $zero, -0x3400
    ctx->r15 = ADD32(0, -0X3400);
    // 0x80055A88: slti        $at, $v0, 0x3401
    ctx->r1 = SIGNED(ctx->r2) < 0X3401 ? 1 : 0;
    // 0x80055A8C: bne         $at, $zero, L_80055AA4
    if (ctx->r1 != 0) {
        // 0x80055A90: slti        $at, $v0, -0x3400
        ctx->r1 = SIGNED(ctx->r2) < -0X3400 ? 1 : 0;
            goto L_80055AA4;
    }
    // 0x80055A90: slti        $at, $v0, -0x3400
    ctx->r1 = SIGNED(ctx->r2) < -0X3400 ? 1 : 0;
    // 0x80055A94: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
    // 0x80055A98: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    // 0x80055A9C: nop

    // 0x80055AA0: slti        $at, $v0, -0x3400
    ctx->r1 = SIGNED(ctx->r2) < -0X3400 ? 1 : 0;
L_80055AA4:
    // 0x80055AA4: beq         $at, $zero, L_80055AB4
    if (ctx->r1 == 0) {
        // 0x80055AA8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80055AB4;
    }
    // 0x80055AA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80055AAC: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
L_80055AB0:
    // 0x80055AB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80055AB4:
    // 0x80055AB4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80055AB8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80055ABC: jr          $ra
    // 0x80055AC0: addiu       $sp, $sp, 0x1A0
    ctx->r29 = ADD32(ctx->r29, 0X1A0);
    return;
    // 0x80055AC0: addiu       $sp, $sp, 0x1A0
    ctx->r29 = ADD32(ctx->r29, 0X1A0);
;}
RECOMP_FUNC void alCSPGetChlVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7F00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C7F04: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x800C7F08: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800C7F0C: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800C7F10: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C7F14: jr          $ra
    // 0x800C7F18: lbu         $v0, 0x9($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X9);
    return;
    // 0x800C7F18: lbu         $v0, 0x9($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X9);
;}
RECOMP_FUNC void sndp_stop_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000499C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800049A0: jal         0x800048D8
    // 0x800049A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sndp_stop_with_flags(rdram, ctx);
        goto after_0;
    // 0x800049A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800049A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800049AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800049B0: jr          $ra
    // 0x800049B4: nop

    return;
    // 0x800049B4: nop

;}
RECOMP_FUNC void obj_init_ttdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C220: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
    // 0x8003C224: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003C228: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003C22C: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x8003C230: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x8003C234: lb          $t9, 0xE($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XE);
    // 0x8003C238: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003C23C: sb          $t9, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r25;
    // 0x8003C240: lbu         $t0, 0xB($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XB);
    // 0x8003C244: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003C248: sb          $t0, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r8;
    // 0x8003C24C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003C250: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8003C254: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8003C258: lbu         $t1, 0xA($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XA);
    // 0x8003C25C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003C260: sb          $t1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r9;
    // 0x8003C264: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x8003C268: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003C26C: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
    // 0x8003C270: lbu         $t3, 0x9($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X9);
    // 0x8003C274: nop

    // 0x8003C278: andi        $t4, $t3, 0x3F
    ctx->r12 = ctx->r11 & 0X3F;
    // 0x8003C27C: sll         $t5, $t4, 10
    ctx->r13 = S32(ctx->r12 << 10);
    // 0x8003C280: sw          $t5, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r13;
    // 0x8003C284: lbu         $t7, 0xC($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XC);
    // 0x8003C288: nop

    // 0x8003C28C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8003C290: nop

    // 0x8003C294: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003C298: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003C29C: nop

    // 0x8003C2A0: bc1f        L_8003C2B0
    if (!c1cs) {
        // 0x8003C2A4: nop
    
            goto L_8003C2B0;
    }
    // 0x8003C2A4: nop

    // 0x8003C2A8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003C2AC: nop

L_8003C2B0:
    // 0x8003C2B0: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003C2B4: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8003C2B8: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C2BC: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8003C2C0: addiu       $t9, $zero, 0x21
    ctx->r25 = ADD32(0, 0X21);
    // 0x8003C2C4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8003C2C8: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8003C2CC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003C2D0: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x8003C2D4: sh          $t9, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r25;
    // 0x8003C2D8: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C2DC: nop

    // 0x8003C2E0: sb          $t1, 0x11($t2)
    MEM_B(0X11, ctx->r10) = ctx->r9;
    // 0x8003C2E4: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C2E8: nop

    // 0x8003C2EC: sb          $t3, 0x10($t4)
    MEM_B(0X10, ctx->r12) = ctx->r11;
    // 0x8003C2F0: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x8003C2F4: nop

    // 0x8003C2F8: sb          $zero, 0x12($t5)
    MEM_B(0X12, ctx->r13) = 0;
    // 0x8003C2FC: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8003C300: lb          $t6, 0x3A($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3A);
    // 0x8003C304: lb          $t8, 0x55($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X55);
    // 0x8003C308: nop

    // 0x8003C30C: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003C310: bne         $at, $zero, L_8003C31C
    if (ctx->r1 != 0) {
        // 0x8003C314: nop
    
            goto L_8003C31C;
    }
    // 0x8003C314: nop

    // 0x8003C318: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003C31C:
    // 0x8003C31C: jr          $ra
    // 0x8003C320: nop

    return;
    // 0x8003C320: nop

;}
RECOMP_FUNC void get_eeprom_settings_pointer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EFB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EFB4: jr          $ra
    // 0x8009EFB8: addiu       $v0, $v0, 0x69E8
    ctx->r2 = ADD32(ctx->r2, 0X69E8);
    return;
    // 0x8009EFB8: addiu       $v0, $v0, 0x69E8
    ctx->r2 = ADD32(ctx->r2, 0X69E8);
;}
RECOMP_FUNC void timetrial_swap_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800599D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800599D8: lb          $t6, -0x24E4($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X24E4);
    // 0x800599DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800599E0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800599E4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800599E8: sb          $t8, -0x24E3($at)
    MEM_B(-0X24E3, ctx->r1) = ctx->r24;
    // 0x800599EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800599F0: jr          $ra
    // 0x800599F4: sh          $a0, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r4;
    return;
    // 0x800599F4: sh          $a0, -0x24D4($at)
    MEM_H(-0X24D4, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _filterBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064A10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80064A14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064A18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80064A1C: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x80064A20: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80064A24: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80064A28: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80064A2C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80064A30: lui         $t1, 0xB00
    ctx->r9 = S32(0XB00 << 16);
    // 0x80064A34: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x80064A38: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80064A3C: ori         $t1, $t1, 0x20
    ctx->r9 = ctx->r9 | 0X20;
    // 0x80064A40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80064A44: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80064A48: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80064A4C: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
    // 0x80064A50: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80064A54: jal         0x800C9250
    // 0x80064A58: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80064A58: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x80064A5C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80064A60: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x80064A64: addiu       $v1, $a3, 0x10
    ctx->r3 = ADD32(ctx->r7, 0X10);
    // 0x80064A68: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80064A6C: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x80064A70: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80064A74: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x80064A78: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80064A7C: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80064A80: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80064A84: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80064A88: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x80064A8C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80064A90: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80064A94: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80064A98: jal         0x800C9250
    // 0x80064A9C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80064A9C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x80064AA0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80064AA4: nop

    // 0x80064AA8: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80064AAC: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80064AB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80064AB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064AB8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80064ABC: jr          $ra
    // 0x80064AC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80064AC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void music_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C98: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80000C9C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CA0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80000CA4: sw          $zero, 0x62B8($at)
    MEM_W(0X62B8, ctx->r1) = 0;
    // 0x80000CA8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80000CAC: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80000CB0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000CB4: jr          $ra
    // 0x80000CB8: sw          $t7, 0x62BC($at)
    MEM_W(0X62BC, ctx->r1) = ctx->r15;
    return;
    // 0x80000CB8: sw          $t7, 0x62BC($at)
    MEM_W(0X62BC, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void dummy_80079810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079C60: jr          $ra
    // 0x80079C64: nop

    return;
    // 0x80079C64: nop

;}
RECOMP_FUNC void rspF3DDKRFifoStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void set_textbox_display_value(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3698: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C369C: jr          $ra
    // 0x800C36A0: sh          $a0, 0x3C04($at)
    MEM_H(0X3C04, ctx->r1) = ctx->r4;
    return;
    // 0x800C36A0: sh          $a0, 0x3C04($at)
    MEM_H(0X3C04, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void align16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071A90: andi        $v1, $a0, 0xF
    ctx->r3 = ctx->r4 & 0XF;
    // 0x80071A94: blez        $v1, L_80071AA4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071A98: nop
    
            goto L_80071AA4;
    }
    // 0x80071A98: nop

    // 0x80071A9C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80071AA0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_80071AA4:
    // 0x80071AA4: jr          $ra
    // 0x80071AA8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80071AA8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_800113BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800113BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800113C0: lw          $v0, -0x4CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CC4);
    // 0x800113C4: jr          $ra
    // 0x800113C8: nop

    return;
    // 0x800113C8: nop

;}
RECOMP_FUNC void menu_trophy_race_rankings_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098F60: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80098F64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098F68: jal         0x8006ECD0
    // 0x80098F6C: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80098F6C: nop

    after_0:
    // 0x80098F70: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80098F74: jal         0x8001E2D0
    // 0x80098F78: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80098F78: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_1:
    // 0x80098F7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098F80: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x80098F84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098F88: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x80098F8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098F90: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80098F94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098F98: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x80098F9C: jal         0x8009C3A0
    // 0x80098FA0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    reset_controller_sticks(rdram, ctx);
        goto after_2;
    // 0x80098FA0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80098FA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80098FA8: jal         0x8009CBB8
    // 0x80098FAC: addiu       $a0, $a0, 0x15A4
    ctx->r4 = ADD32(ctx->r4, 0X15A4);
    menu_assetgroup_load(rdram, ctx);
        goto after_3;
    // 0x80098FAC: addiu       $a0, $a0, 0x15A4
    ctx->r4 = ADD32(ctx->r4, 0X15A4);
    after_3:
    // 0x80098FB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80098FB4: jal         0x8009CDE8
    // 0x80098FB8: addiu       $a0, $a0, 0x15C0
    ctx->r4 = ADD32(ctx->r4, 0X15C0);
    menu_imagegroup_load(rdram, ctx);
        goto after_4;
    // 0x80098FB8: addiu       $a0, $a0, 0x15C0
    ctx->r4 = ADD32(ctx->r4, 0X15C0);
    after_4:
    // 0x80098FBC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80098FC0: addiu       $v1, $v1, 0x156C
    ctx->r3 = ADD32(ctx->r3, 0X156C);
    // 0x80098FC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80098FC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098FCC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80098FD0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80098FD4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80098FD8: addiu       $a1, $a1, 0x1568
    ctx->r5 = ADD32(ctx->r5, 0X1568);
    // 0x80098FDC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80098FE0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80098FE4: sw          $v0, 0x1570($at)
    MEM_W(0X1570, ctx->r1) = ctx->r2;
    // 0x80098FE8: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
L_80098FEC:
    // 0x80098FEC: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80098FF0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80098FF4: beq         $at, $zero, L_80099024
    if (ctx->r1 == 0) {
        // 0x80098FF8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80099024;
    }
    // 0x80098FF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80098FFC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80099000: nop

    // 0x80099004: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099008: mflo        $t8
    ctx->r24 = lo;
    // 0x8009900C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80099010: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x80099014: lb          $t6, -0x6($t5)
    ctx->r14 = MEM_B(ctx->r13, -0X6);
    // 0x80099018: nop

    // 0x8009901C: beq         $a0, $t6, L_80098FEC
    if (ctx->r4 == ctx->r14) {
        // 0x80099020: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80098FEC;
    }
    // 0x80099020: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
L_80099024:
    // 0x80099024: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80099028: beq         $at, $zero, L_80099060
    if (ctx->r1 == 0) {
        // 0x8009902C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80099060;
    }
    // 0x8009902C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80099030: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80099034: lw          $v0, -0x5E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E0);
    // 0x80099038: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009903C: lw          $t7, 0x188($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X188);
    // 0x80099040: addiu       $v1, $v1, 0x71B0
    ctx->r3 = ADD32(ctx->r3, 0X71B0);
    // 0x80099044: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80099048: lw          $t8, 0x204($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X204);
    // 0x8009904C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80099050: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099054: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80099058: b           L_80099080
    // 0x8009905C: sw          $t9, 0x71D4($at)
    MEM_W(0X71D4, ctx->r1) = ctx->r25;
        goto L_80099080;
    // 0x8009905C: sw          $t9, 0x71D4($at)
    MEM_W(0X71D4, ctx->r1) = ctx->r25;
L_80099060:
    // 0x80099060: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80099064: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x80099068: addiu       $v1, $v1, 0x71B0
    ctx->r3 = ADD32(ctx->r3, 0X71B0);
    // 0x8009906C: lw          $t6, 0x244($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X244);
    // 0x80099070: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80099074: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099078: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8009907C: sw          $t7, 0x71D4($at)
    MEM_W(0X71D4, ctx->r1) = ctx->r15;
L_80099080:
    // 0x80099080: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099084: sw          $zero, 0x7028($at)
    MEM_W(0X7028, ctx->r1) = 0;
    // 0x80099088: jal         0x80094B08
    // 0x8009908C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    menu_racer_portraits(rdram, ctx);
        goto after_5;
    // 0x8009908C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_5:
    // 0x80099090: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80099094: addiu       $t3, $t3, -0x5C4
    ctx->r11 = ADD32(ctx->r11, -0X5C4);
    // 0x80099098: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8009909C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800990A0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800990A4: bne         $at, $zero, L_800990B8
    if (ctx->r1 != 0) {
        // 0x800990A8: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_800990B8;
    }
    // 0x800990A8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800990AC: addiu       $t4, $t4, 0x1564
    ctx->r12 = ADD32(ctx->r12, 0X1564);
    // 0x800990B0: b           L_80099110
    // 0x800990B4: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
        goto L_80099110;
    // 0x800990B4: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
L_800990B8:
    // 0x800990B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800990BC: beq         $v0, $at, L_800990DC
    if (ctx->r2 == ctx->r1) {
        // 0x800990C0: nop
    
            goto L_800990DC;
    }
    // 0x800990C0: nop

    // 0x800990C4: jal         0x8009F1C4
    // 0x800990C8: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    is_in_two_player_adventure(rdram, ctx);
        goto after_6;
    // 0x800990C8: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_6:
    // 0x800990CC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800990D0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800990D4: beq         $v0, $zero, L_80099100
    if (ctx->r2 == 0) {
        // 0x800990D8: addiu       $t3, $t3, -0x5C4
        ctx->r11 = ADD32(ctx->r11, -0X5C4);
            goto L_80099100;
    }
    // 0x800990D8: addiu       $t3, $t3, -0x5C4
    ctx->r11 = ADD32(ctx->r11, -0X5C4);
L_800990DC:
    // 0x800990DC: jal         0x8009C984
    // 0x800990E0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    get_multiplayer_racer_count(rdram, ctx);
        goto after_7;
    // 0x800990E0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_7:
    // 0x800990E4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800990E8: addiu       $t4, $t4, 0x1564
    ctx->r12 = ADD32(ctx->r12, 0X1564);
    // 0x800990EC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800990F0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800990F4: addiu       $t3, $t3, -0x5C4
    ctx->r11 = ADD32(ctx->r11, -0X5C4);
    // 0x800990F8: b           L_80099110
    // 0x800990FC: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
        goto L_80099110;
    // 0x800990FC: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
L_80099100:
    // 0x80099100: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80099104: addiu       $t4, $t4, 0x1564
    ctx->r12 = ADD32(ctx->r12, 0X1564);
    // 0x80099108: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8009910C: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_80099110:
    // 0x80099110: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80099114: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80099118: blez        $a1, L_8009918C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8009911C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8009918C;
    }
    // 0x8009911C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80099120: addiu       $a0, $a0, 0x69C8
    ctx->r4 = ADD32(ctx->r4, 0X69C8);
    // 0x80099124: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80099128:
    // 0x80099128: blez        $a1, L_80099178
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8009912C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80099178;
    }
    // 0x8009912C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80099130: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80099134:
    // 0x80099134: lb          $t9, 0x5A($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X5A);
    // 0x80099138: addu        $t5, $a0, $t0
    ctx->r13 = ADD32(ctx->r4, ctx->r8);
    // 0x8009913C: bne         $t0, $t9, L_80099168
    if (ctx->r8 != ctx->r25) {
        // 0x80099140: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80099168;
    }
    // 0x80099140: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80099144: sb          $a3, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r7;
    // 0x80099148: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8009914C: addiu       $t6, $t6, 0x69B8
    ctx->r14 = ADD32(ctx->r14, 0X69B8);
    // 0x80099150: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80099154: beq         $at, $zero, L_80099164
    if (ctx->r1 == 0) {
        // 0x80099158: addu        $v0, $t0, $t6
        ctx->r2 = ADD32(ctx->r8, ctx->r14);
            goto L_80099164;
    }
    // 0x80099158: addu        $v0, $t0, $t6
    ctx->r2 = ADD32(ctx->r8, ctx->r14);
    // 0x8009915C: b           L_80099168
    // 0x80099160: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
        goto L_80099168;
    // 0x80099160: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_80099164:
    // 0x80099164: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80099168:
    // 0x80099168: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8009916C: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80099170: bne         $at, $zero, L_80099134
    if (ctx->r1 != 0) {
        // 0x80099174: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_80099134;
    }
    // 0x80099174: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
L_80099178:
    // 0x80099178: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8009917C: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80099180: bne         $at, $zero, L_80099128
    if (ctx->r1 != 0) {
        // 0x80099184: nop
    
            goto L_80099128;
    }
    // 0x80099184: nop

    // 0x80099188: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8009918C:
    // 0x8009918C: blez        $a1, L_800991D4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80099190: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800991D4;
    }
    // 0x80099190: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80099194: addiu       $v0, $t8, 0x6998
    ctx->r2 = ADD32(ctx->r24, 0X6998);
    // 0x80099198: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8009919C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800991A0: addiu       $a0, $a0, 0x1584
    ctx->r4 = ADD32(ctx->r4, 0X1584);
    // 0x800991A4: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    // 0x800991A8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_800991AC:
    // 0x800991AC: lb          $t5, 0x5A($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X5A);
    // 0x800991B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800991B4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800991B8: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800991BC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800991C0: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800991C4: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x800991C8: bne         $at, $zero, L_800991AC
    if (ctx->r1 != 0) {
        // 0x800991CC: sw          $t9, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r25;
            goto L_800991AC;
    }
    // 0x800991CC: sw          $t9, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r25;
    // 0x800991D0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800991D4:
    // 0x800991D4: blez        $a1, L_80099220
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800991D8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80099220;
    }
    // 0x800991D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800991DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800991E0: addiu       $a0, $a0, 0x69D0
    ctx->r4 = ADD32(ctx->r4, 0X69D0);
    // 0x800991E4: addiu       $v0, $v0, 0x6998
    ctx->r2 = ADD32(ctx->r2, 0X6998);
    // 0x800991E8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800991EC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
L_800991F0:
    // 0x800991F0: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x800991F4: lw          $t5, 0x54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X54);
    // 0x800991F8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800991FC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80099200: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80099204: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x80099208: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8009920C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80099210: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80099214: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80099218: bne         $at, $zero, L_800991F0
    if (ctx->r1 != 0) {
        // 0x8009921C: sw          $t6, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r14;
            goto L_800991F0;
    }
    // 0x8009921C: sw          $t6, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r14;
L_80099220:
    // 0x80099220: addiu       $t0, $a1, -0x1
    ctx->r8 = ADD32(ctx->r5, -0X1);
    // 0x80099224: blez        $t0, L_8009931C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80099228: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8009931C;
    }
    // 0x80099228: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009922C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80099230: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80099234: addiu       $t1, $t1, 0x69D0
    ctx->r9 = ADD32(ctx->r9, 0X69D0);
L_80099238:
    // 0x80099238: blez        $t0, L_80099308
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8009923C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80099308;
    }
    // 0x8009923C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80099240: andi        $v0, $t0, 0x1
    ctx->r2 = ctx->r8 & 0X1;
    // 0x80099244: beq         $v0, $zero, L_80099280
    if (ctx->r2 == 0) {
        // 0x80099248: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80099280;
    }
    // 0x80099248: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8009924C: beq         $at, $zero, L_8009927C
    if (ctx->r1 == 0) {
        // 0x80099250: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8009927C;
    }
    // 0x80099250: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80099254: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80099258: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8009925C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80099260: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80099264: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80099268: lbu         $t7, 0x69D1($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X69D1);
    // 0x8009926C: lbu         $v0, 0x69D0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X69D0);
    // 0x80099270: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099274: sb          $t7, 0x69D0($at)
    MEM_B(0X69D0, ctx->r1) = ctx->r15;
    // 0x80099278: sb          $v0, 0x69D1($at)
    MEM_B(0X69D1, ctx->r1) = ctx->r2;
L_8009927C:
    // 0x8009927C: beq         $a3, $t0, L_80099308
    if (ctx->r7 == ctx->r8) {
        // 0x80099280: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_80099308;
    }
L_80099280:
    // 0x80099280: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80099284: addiu       $t8, $sp, 0x48
    ctx->r24 = ADD32(ctx->r29, 0X48);
    // 0x80099288: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x8009928C: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x80099290: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
L_80099294:
    // 0x80099294: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x80099298: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x8009929C: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x800992A0: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800992A4: beq         $at, $zero, L_800992C8
    if (ctx->r1 == 0) {
        // 0x800992A8: nop
    
            goto L_800992C8;
    }
    // 0x800992A8: nop

    // 0x800992AC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800992B0: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x800992B4: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800992B8: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x800992BC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800992C0: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x800992C4: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
L_800992C8:
    // 0x800992C8: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x800992CC: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x800992D0: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800992D4: beq         $at, $zero, L_800992F4
    if (ctx->r1 == 0) {
        // 0x800992D8: nop
    
            goto L_800992F4;
    }
    // 0x800992D8: nop

    // 0x800992DC: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x800992E0: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x800992E4: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x800992E8: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x800992EC: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x800992F0: sb          $t6, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r14;
L_800992F4:
    // 0x800992F4: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800992F8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800992FC: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80099300: bne         $a3, $t0, L_80099294
    if (ctx->r7 != ctx->r8) {
        // 0x80099304: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_80099294;
    }
    // 0x80099304: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80099308:
    // 0x80099308: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8009930C: bgtz        $t0, L_80099238
    if (SIGNED(ctx->r8) > 0) {
        // 0x80099310: nop
    
            goto L_80099238;
    }
    // 0x80099310: nop

    // 0x80099314: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80099318: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
L_8009931C:
    // 0x8009931C: jal         0x8009F1C4
    // 0x80099320: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_8;
    // 0x80099320: nop

    after_8:
    // 0x80099324: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80099328: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009932C: addiu       $t4, $t4, 0x1564
    ctx->r12 = ADD32(ctx->r12, 0X1564);
    // 0x80099330: addiu       $t3, $t3, -0x5C4
    ctx->r11 = ADD32(ctx->r11, -0X5C4);
    // 0x80099334: beq         $v0, $zero, L_80099344
    if (ctx->r2 == 0) {
        // 0x80099338: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80099344;
    }
    // 0x80099338: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8009933C: b           L_8009934C
    // 0x80099340: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_8009934C;
    // 0x80099340: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_80099344:
    // 0x80099344: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80099348: nop

L_8009934C:
    // 0x8009934C: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80099350: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80099354: blez        $a1, L_80099398
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80099358: addiu       $a0, $a0, 0x69D0
        ctx->r4 = ADD32(ctx->r4, 0X69D0);
            goto L_80099398;
    }
    // 0x80099358: addiu       $a0, $a0, 0x69D0
    ctx->r4 = ADD32(ctx->r4, 0X69D0);
    // 0x8009935C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80099360: addiu       $v0, $t7, 0x69C0
    ctx->r2 = ADD32(ctx->r15, 0X69C0);
    // 0x80099364: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
L_80099368:
    // 0x80099368: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8009936C: nop

    // 0x80099370: slt         $at, $t9, $a3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80099374: beq         $at, $zero, L_80099384
    if (ctx->r1 == 0) {
        // 0x80099378: nop
    
            goto L_80099384;
    }
    // 0x80099378: nop

    // 0x8009937C: b           L_80099388
    // 0x80099380: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
        goto L_80099388;
    // 0x80099380: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_80099384:
    // 0x80099384: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80099388:
    // 0x80099388: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009938C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80099390: bne         $at, $zero, L_80099368
    if (ctx->r1 != 0) {
        // 0x80099394: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80099368;
    }
    // 0x80099394: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80099398:
    // 0x80099398: jal         0x800C46D0
    // 0x8009939C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_9;
    // 0x8009939C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x800993A0: jal         0x80000BE0
    // 0x800993A4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_10;
    // 0x800993A4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_10:
    // 0x800993A8: jal         0x80000B34
    // 0x800993AC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_11;
    // 0x800993AC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_11:
    // 0x800993B0: jal         0x80000C98
    // 0x800993B4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    music_fade(rdram, ctx);
        goto after_12;
    // 0x800993B4: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_12:
    // 0x800993B8: jal         0x80098CB0
    // 0x800993BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80098774(rdram, ctx);
        goto after_13;
    // 0x800993BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x800993C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800993C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800993C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800993CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800993D0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800993D4: addiu       $a0, $a0, 0x15C8
    ctx->r4 = ADD32(ctx->r4, 0X15C8);
    // 0x800993D8: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x800993DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800993E0: jal         0x800822A4
    // 0x800993E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    postrace_offsets(rdram, ctx);
        goto after_14;
    // 0x800993E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_14:
    // 0x800993E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800993EC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800993F0: jr          $ra
    // 0x800993F4: nop

    return;
    // 0x800993F4: nop

;}
RECOMP_FUNC void obj_init_lighthouse_rocketsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003576C: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80035770: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80035774: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80035778: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003577C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035780: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80035784: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035788: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003578C: nop

    // 0x80035790: bc1f        L_800357A0
    if (!c1cs) {
        // 0x80035794: nop
    
            goto L_800357A0;
    }
    // 0x80035794: nop

    // 0x80035798: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003579C: nop

L_800357A0:
    // 0x800357A0: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800357A4: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800357A8: lb          $t1, 0x3A($a0)
    ctx->r9 = MEM_B(ctx->r4, 0X3A);
    // 0x800357AC: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800357B0: nop

    // 0x800357B4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800357B8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800357BC: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800357C0: nop

    // 0x800357C4: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x800357C8: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x800357CC: lb          $t2, 0x55($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X55);
    // 0x800357D0: nop

    // 0x800357D4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800357D8: bne         $at, $zero, L_800357E4
    if (ctx->r1 != 0) {
        // 0x800357DC: nop
    
            goto L_800357E4;
    }
    // 0x800357DC: nop

    // 0x800357E0: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_800357E4:
    // 0x800357E4: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x800357E8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800357EC: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x800357F0: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x800357F4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800357F8: sb          $t5, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r13;
    // 0x800357FC: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80035800: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80035804: sb          $t7, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r15;
    // 0x80035808: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x8003580C: jr          $ra
    // 0x80035810: sb          $zero, 0x12($t9)
    MEM_B(0X12, ctx->r25) = 0;
    return;
    // 0x80035810: sb          $zero, 0x12($t9)
    MEM_B(0X12, ctx->r25) = 0;
;}
RECOMP_FUNC void rankings_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80099B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099B44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80099B48: jal         0x8009C9EC
    // 0x80099B4C: addiu       $a0, $a0, 0x15A4
    ctx->r4 = ADD32(ctx->r4, 0X15A4);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x80099B4C: addiu       $a0, $a0, 0x15A4
    ctx->r4 = ADD32(ctx->r4, 0X15A4);
    after_0:
    // 0x80099B50: jal         0x800C478C
    // 0x80099B54: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x80099B54: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80099B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099B5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80099B60: jr          $ra
    // 0x80099B64: nop

    return;
    // 0x80099B64: nop

;}
RECOMP_FUNC void render_epc_lock_up_display(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7D30: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800B7D34: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B7D38: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B7D3C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800B7D40: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800B7D44: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B7D48: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B7D4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B7D50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B7D54: addiu       $t7, $t7, 0x35BC
    ctx->r15 = ADD32(ctx->r15, 0X35BC);
    // 0x800B7D58: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800B7D5C: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x800B7D60: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800B7D64: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800B7D68: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800B7D6C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B7D70: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800B7D74: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800B7D78: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800B7D7C: jal         0x800B68BC
    // 0x800B7D80: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    set_render_printf_position(rdram, ctx);
        goto after_0;
    // 0x800B7D80: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    after_0:
    // 0x800B7D84: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B7D88: addiu       $v1, $v1, 0x35B4
    ctx->r3 = ADD32(ctx->r3, 0X35B4);
    // 0x800B7D8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800B7D90: nop

    // 0x800B7D94: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x800B7D98: beq         $at, $zero, L_800B8208
    if (ctx->r1 == 0) {
        // 0x800B7D9C: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_800B8208;
    }
    // 0x800B7D9C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800B7DA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B7DA4: addu        $at, $at, $t1
    gpr jr_addend_800B7DB0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800B7DA8: lw          $t1, -0x6944($at)
    ctx->r9 = ADD32(ctx->r1, -0X6944);
    // 0x800B7DAC: nop

    // 0x800B7DB0: jr          $t1
    // 0x800B7DB4: nop

    switch (jr_addend_800B7DB0 >> 2) {
        case 0: goto L_800B7DB8; break;
        case 1: goto L_800B8138; break;
        case 2: goto L_800B8138; break;
        case 3: goto L_800B8138; break;
        case 4: goto L_800B8190; break;
        case 5: goto L_800B8204; break;
        default: switch_error(__func__, 0x800B7DB0, 0x800E96BC);
    }
    // 0x800B7DB4: nop

L_800B7DB8:
    // 0x800B7DB8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800B7DBC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B7DC0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800B7DC4: addiu       $v1, $v1, -0x6240
    ctx->r3 = ADD32(ctx->r3, -0X6240);
    // 0x800B7DC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B7DCC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B7DD0: lwc1        $f4, 0x130($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X130);
    // 0x800B7DD4: lwc1        $f8, 0x134($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X134);
    // 0x800B7DD8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B7DDC: lwc1        $f16, 0x138($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X138);
    // 0x800B7DE0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800B7DE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B7DE8: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800B7DEC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B7DF0: lw          $t6, 0x120($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X120);
    // 0x800B7DF4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B7DF8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B7DFC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B7E00: addiu       $v0, $v0, -0x5A90
    ctx->r2 = ADD32(ctx->r2, -0X5A90);
    // 0x800B7E04: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B7E08: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800B7E0C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B7E10: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800B7E14: nop

    // 0x800B7E18: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B7E1C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B7E20: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B7E24: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B7E28: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B7E2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B7E30: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B7E34: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800B7E38: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B7E3C: bne         $t6, $at, L_800B7EFC
    if (ctx->r14 != ctx->r1) {
        // 0x800B7E40: sw          $t8, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r24;
            goto L_800B7EFC;
    }
    // 0x800B7E40: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800B7E44: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7E48: lw          $a1, -0x6124($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6124);
    // 0x800B7E4C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7E50: jal         0x800B643C
    // 0x800B7E54: addiu       $a0, $a0, -0x6B68
    ctx->r4 = ADD32(ctx->r4, -0X6B68);
    render_printf(rdram, ctx);
        goto after_1;
    // 0x800B7E54: addiu       $a0, $a0, -0x6B68
    ctx->r4 = ADD32(ctx->r4, -0X6B68);
    after_1:
    // 0x800B7E58: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B7E5C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7E60: lw          $a2, -0x61FC($t3)
    ctx->r6 = MEM_W(ctx->r11, -0X61FC);
    // 0x800B7E64: lw          $a1, -0x6204($t1)
    ctx->r5 = MEM_W(ctx->r9, -0X6204);
    // 0x800B7E68: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7E6C: jal         0x800B643C
    // 0x800B7E70: addiu       $a0, $a0, -0x6B58
    ctx->r4 = ADD32(ctx->r4, -0X6B58);
    render_printf(rdram, ctx);
        goto after_2;
    // 0x800B7E70: addiu       $a0, $a0, -0x6B58
    ctx->r4 = ADD32(ctx->r4, -0X6B58);
    after_2:
    // 0x800B7E74: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B7E78: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x800B7E7C: addiu       $s5, $s5, -0x6B3C
    ctx->r21 = ADD32(ctx->r21, -0X6B3C);
    // 0x800B7E80: addiu       $s0, $s0, -0x5A90
    ctx->r16 = ADD32(ctx->r16, -0X5A90);
    // 0x800B7E84: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B7E88: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_800B7E8C:
    // 0x800B7E8C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7E90: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x800B7E94: beq         $s4, $a2, L_800B7EC8
    if (ctx->r20 == ctx->r6) {
        // 0x800B7E98: nop
    
            goto L_800B7EC8;
    }
    // 0x800B7E98: nop

    // 0x800B7E9C: bne         $s3, $zero, L_800B7EB8
    if (ctx->r19 != 0) {
        // 0x800B7EA0: addu        $s1, $s2, $t7
        ctx->r17 = ADD32(ctx->r18, ctx->r15);
            goto L_800B7EB8;
    }
    // 0x800B7EA0: addu        $s1, $s2, $t7
    ctx->r17 = ADD32(ctx->r18, ctx->r15);
    // 0x800B7EA4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800B7EA8: jal         0x800B643C
    // 0x800B7EAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    render_printf(rdram, ctx);
        goto after_3;
    // 0x800B7EAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x800B7EB0: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7EB4: nop

L_800B7EB8:
    // 0x800B7EB8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7EBC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800B7EC0: jal         0x800B643C
    // 0x800B7EC4: addiu       $a0, $a0, -0x6B30
    ctx->r4 = ADD32(ctx->r4, -0X6B30);
    render_printf(rdram, ctx);
        goto after_4;
    // 0x800B7EC4: addiu       $a0, $a0, -0x6B30
    ctx->r4 = ADD32(ctx->r4, -0X6B30);
    after_4:
L_800B7EC8:
    // 0x800B7EC8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B7ECC: addiu       $t4, $t4, -0x5A84
    ctx->r12 = ADD32(ctx->r12, -0X5A84);
    // 0x800B7ED0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B7ED4: bne         $s0, $t4, L_800B7E8C
    if (ctx->r16 != ctx->r12) {
        // 0x800B7ED8: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800B7E8C;
    }
    // 0x800B7ED8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800B7EDC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7EE0: jal         0x800B643C
    // 0x800B7EE4: addiu       $a0, $a0, -0x6B28
    ctx->r4 = ADD32(ctx->r4, -0X6B28);
    render_printf(rdram, ctx);
        goto after_5;
    // 0x800B7EE4: addiu       $a0, $a0, -0x6B28
    ctx->r4 = ADD32(ctx->r4, -0X6B28);
    after_5:
    // 0x800B7EE8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7EEC: jal         0x800B643C
    // 0x800B7EF0: addiu       $a0, $a0, -0x6B24
    ctx->r4 = ADD32(ctx->r4, -0X6B24);
    render_printf(rdram, ctx);
        goto after_6;
    // 0x800B7EF0: addiu       $a0, $a0, -0x6B24
    ctx->r4 = ADD32(ctx->r4, -0X6B24);
    after_6:
    // 0x800B7EF4: b           L_800B820C
    // 0x800B7EF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B820C;
    // 0x800B7EF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B7EFC:
    // 0x800B7EFC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7F00: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
    // 0x800B7F04: jal         0x800B643C
    // 0x800B7F08: addiu       $a0, $a0, -0x6B14
    ctx->r4 = ADD32(ctx->r4, -0X6B14);
    render_printf(rdram, ctx);
        goto after_7;
    // 0x800B7F08: addiu       $a0, $a0, -0x6B14
    ctx->r4 = ADD32(ctx->r4, -0X6B14);
    after_7:
    // 0x800B7F0C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7F10: lw          $a1, -0x6124($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6124);
    // 0x800B7F14: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7F18: jal         0x800B643C
    // 0x800B7F1C: addiu       $a0, $a0, -0x6AFC
    ctx->r4 = ADD32(ctx->r4, -0X6AFC);
    render_printf(rdram, ctx);
        goto after_8;
    // 0x800B7F1C: addiu       $a0, $a0, -0x6AFC
    ctx->r4 = ADD32(ctx->r4, -0X6AFC);
    after_8:
    // 0x800B7F20: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7F24: lw          $a1, -0x6120($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6120);
    // 0x800B7F28: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7F2C: jal         0x800B643C
    // 0x800B7F30: addiu       $a0, $a0, -0x6AEC
    ctx->r4 = ADD32(ctx->r4, -0X6AEC);
    render_printf(rdram, ctx);
        goto after_9;
    // 0x800B7F30: addiu       $a0, $a0, -0x6AEC
    ctx->r4 = ADD32(ctx->r4, -0X6AEC);
    after_9:
    // 0x800B7F34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7F38: lw          $a1, -0x6128($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6128);
    // 0x800B7F3C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7F40: jal         0x800B643C
    // 0x800B7F44: addiu       $a0, $a0, -0x6ADC
    ctx->r4 = ADD32(ctx->r4, -0X6ADC);
    render_printf(rdram, ctx);
        goto after_10;
    // 0x800B7F44: addiu       $a0, $a0, -0x6ADC
    ctx->r4 = ADD32(ctx->r4, -0X6ADC);
    after_10:
    // 0x800B7F48: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7F4C: lw          $a1, -0x611C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X611C);
    // 0x800B7F50: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7F54: jal         0x800B643C
    // 0x800B7F58: addiu       $a0, $a0, -0x6ACC
    ctx->r4 = ADD32(ctx->r4, -0X6ACC);
    render_printf(rdram, ctx);
        goto after_11;
    // 0x800B7F58: addiu       $a0, $a0, -0x6ACC
    ctx->r4 = ADD32(ctx->r4, -0X6ACC);
    after_11:
    // 0x800B7F5C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B7F60: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x800B7F64: addiu       $s5, $s5, -0x6AB8
    ctx->r21 = ADD32(ctx->r21, -0X6AB8);
    // 0x800B7F68: addiu       $s0, $s0, -0x5A90
    ctx->r16 = ADD32(ctx->r16, -0X5A90);
    // 0x800B7F6C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B7F70: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_800B7F74:
    // 0x800B7F74: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7F78: addiu       $t5, $sp, 0x50
    ctx->r13 = ADD32(ctx->r29, 0X50);
    // 0x800B7F7C: beq         $s4, $a2, L_800B7FB0
    if (ctx->r20 == ctx->r6) {
        // 0x800B7F80: nop
    
            goto L_800B7FB0;
    }
    // 0x800B7F80: nop

    // 0x800B7F84: bne         $s3, $zero, L_800B7FA0
    if (ctx->r19 != 0) {
        // 0x800B7F88: addu        $s1, $s2, $t5
        ctx->r17 = ADD32(ctx->r18, ctx->r13);
            goto L_800B7FA0;
    }
    // 0x800B7F88: addu        $s1, $s2, $t5
    ctx->r17 = ADD32(ctx->r18, ctx->r13);
    // 0x800B7F8C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800B7F90: jal         0x800B643C
    // 0x800B7F94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    render_printf(rdram, ctx);
        goto after_12;
    // 0x800B7F94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_12:
    // 0x800B7F98: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800B7F9C: nop

L_800B7FA0:
    // 0x800B7FA0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7FA4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800B7FA8: jal         0x800B643C
    // 0x800B7FAC: addiu       $a0, $a0, -0x6AAC
    ctx->r4 = ADD32(ctx->r4, -0X6AAC);
    render_printf(rdram, ctx);
        goto after_13;
    // 0x800B7FAC: addiu       $a0, $a0, -0x6AAC
    ctx->r4 = ADD32(ctx->r4, -0X6AAC);
    after_13:
L_800B7FB0:
    // 0x800B7FB0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7FB4: addiu       $t9, $t9, -0x5A84
    ctx->r25 = ADD32(ctx->r25, -0X5A84);
    // 0x800B7FB8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B7FBC: bne         $s0, $t9, L_800B7F74
    if (ctx->r16 != ctx->r25) {
        // 0x800B7FC0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800B7F74;
    }
    // 0x800B7FC0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800B7FC4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7FC8: jal         0x800B643C
    // 0x800B7FCC: addiu       $a0, $a0, -0x6AA4
    ctx->r4 = ADD32(ctx->r4, -0X6AA4);
    render_printf(rdram, ctx);
        goto after_14;
    // 0x800B7FCC: addiu       $a0, $a0, -0x6AA4
    ctx->r4 = ADD32(ctx->r4, -0X6AA4);
    after_14:
    // 0x800B7FD0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B7FD4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B7FD8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B7FDC: lw          $a3, -0x620C($t1)
    ctx->r7 = MEM_W(ctx->r9, -0X620C);
    // 0x800B7FE0: lw          $a2, -0x6214($t7)
    ctx->r6 = MEM_W(ctx->r15, -0X6214);
    // 0x800B7FE4: lw          $a1, -0x621C($t9)
    ctx->r5 = MEM_W(ctx->r25, -0X621C);
    // 0x800B7FE8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B7FEC: jal         0x800B643C
    // 0x800B7FF0: addiu       $a0, $a0, -0x6AA0
    ctx->r4 = ADD32(ctx->r4, -0X6AA0);
    render_printf(rdram, ctx);
        goto after_15;
    // 0x800B7FF0: addiu       $a0, $a0, -0x6AA0
    ctx->r4 = ADD32(ctx->r4, -0X6AA0);
    after_15:
    // 0x800B7FF4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7FF8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B7FFC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B8000: lw          $a3, -0x61F4($t9)
    ctx->r7 = MEM_W(ctx->r25, -0X61F4);
    // 0x800B8004: lw          $a2, -0x61FC($t5)
    ctx->r6 = MEM_W(ctx->r13, -0X61FC);
    // 0x800B8008: lw          $a1, -0x6204($t3)
    ctx->r5 = MEM_W(ctx->r11, -0X6204);
    // 0x800B800C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B8010: jal         0x800B643C
    // 0x800B8014: addiu       $a0, $a0, -0x6A80
    ctx->r4 = ADD32(ctx->r4, -0X6A80);
    render_printf(rdram, ctx);
        goto after_16;
    // 0x800B8014: addiu       $a0, $a0, -0x6A80
    ctx->r4 = ADD32(ctx->r4, -0X6A80);
    after_16:
    // 0x800B8018: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B801C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B8020: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B8024: lw          $a3, -0x61DC($t3)
    ctx->r7 = MEM_W(ctx->r11, -0X61DC);
    // 0x800B8028: lw          $a2, -0x61E4($t1)
    ctx->r6 = MEM_W(ctx->r9, -0X61E4);
    // 0x800B802C: lw          $a1, -0x61EC($t7)
    ctx->r5 = MEM_W(ctx->r15, -0X61EC);
    // 0x800B8030: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B8034: jal         0x800B643C
    // 0x800B8038: addiu       $a0, $a0, -0x6A60
    ctx->r4 = ADD32(ctx->r4, -0X6A60);
    render_printf(rdram, ctx);
        goto after_17;
    // 0x800B8038: addiu       $a0, $a0, -0x6A60
    ctx->r4 = ADD32(ctx->r4, -0X6A60);
    after_17:
    // 0x800B803C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B8040: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B8044: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B8048: lw          $a3, -0x61C4($t7)
    ctx->r7 = MEM_W(ctx->r15, -0X61C4);
    // 0x800B804C: lw          $a2, -0x61CC($t9)
    ctx->r6 = MEM_W(ctx->r25, -0X61CC);
    // 0x800B8050: lw          $a1, -0x61D4($t5)
    ctx->r5 = MEM_W(ctx->r13, -0X61D4);
    // 0x800B8054: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B8058: jal         0x800B643C
    // 0x800B805C: addiu       $a0, $a0, -0x6A40
    ctx->r4 = ADD32(ctx->r4, -0X6A40);
    render_printf(rdram, ctx);
        goto after_18;
    // 0x800B805C: addiu       $a0, $a0, -0x6A40
    ctx->r4 = ADD32(ctx->r4, -0X6A40);
    after_18:
    // 0x800B8060: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B8064: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B8068: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B806C: lw          $a3, -0x61AC($t5)
    ctx->r7 = MEM_W(ctx->r13, -0X61AC);
    // 0x800B8070: lw          $a2, -0x61B4($t3)
    ctx->r6 = MEM_W(ctx->r11, -0X61B4);
    // 0x800B8074: lw          $a1, -0x61BC($t1)
    ctx->r5 = MEM_W(ctx->r9, -0X61BC);
    // 0x800B8078: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B807C: jal         0x800B643C
    // 0x800B8080: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    render_printf(rdram, ctx);
        goto after_19;
    // 0x800B8080: addiu       $a0, $a0, -0x6A20
    ctx->r4 = ADD32(ctx->r4, -0X6A20);
    after_19:
    // 0x800B8084: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B8088: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B808C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B8090: lw          $a3, -0x6194($t1)
    ctx->r7 = MEM_W(ctx->r9, -0X6194);
    // 0x800B8094: lw          $a2, -0x619C($t7)
    ctx->r6 = MEM_W(ctx->r15, -0X619C);
    // 0x800B8098: lw          $a1, -0x61A4($t9)
    ctx->r5 = MEM_W(ctx->r25, -0X61A4);
    // 0x800B809C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B80A0: jal         0x800B643C
    // 0x800B80A4: addiu       $a0, $a0, -0x6A00
    ctx->r4 = ADD32(ctx->r4, -0X6A00);
    render_printf(rdram, ctx);
        goto after_20;
    // 0x800B80A4: addiu       $a0, $a0, -0x6A00
    ctx->r4 = ADD32(ctx->r4, -0X6A00);
    after_20:
    // 0x800B80A8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B80AC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B80B0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B80B4: lw          $a3, -0x617C($t9)
    ctx->r7 = MEM_W(ctx->r25, -0X617C);
    // 0x800B80B8: lw          $a2, -0x6184($t5)
    ctx->r6 = MEM_W(ctx->r13, -0X6184);
    // 0x800B80BC: lw          $a1, -0x618C($t3)
    ctx->r5 = MEM_W(ctx->r11, -0X618C);
    // 0x800B80C0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B80C4: jal         0x800B643C
    // 0x800B80C8: addiu       $a0, $a0, -0x69E0
    ctx->r4 = ADD32(ctx->r4, -0X69E0);
    render_printf(rdram, ctx);
        goto after_21;
    // 0x800B80C8: addiu       $a0, $a0, -0x69E0
    ctx->r4 = ADD32(ctx->r4, -0X69E0);
    after_21:
    // 0x800B80CC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B80D0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B80D4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B80D8: lw          $a3, -0x6164($t3)
    ctx->r7 = MEM_W(ctx->r11, -0X6164);
    // 0x800B80DC: lw          $a2, -0x616C($t1)
    ctx->r6 = MEM_W(ctx->r9, -0X616C);
    // 0x800B80E0: lw          $a1, -0x6174($t7)
    ctx->r5 = MEM_W(ctx->r15, -0X6174);
    // 0x800B80E4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B80E8: jal         0x800B643C
    // 0x800B80EC: addiu       $a0, $a0, -0x69C0
    ctx->r4 = ADD32(ctx->r4, -0X69C0);
    render_printf(rdram, ctx);
        goto after_22;
    // 0x800B80EC: addiu       $a0, $a0, -0x69C0
    ctx->r4 = ADD32(ctx->r4, -0X69C0);
    after_22:
    // 0x800B80F0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B80F4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B80F8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B80FC: lw          $a3, -0x614C($t7)
    ctx->r7 = MEM_W(ctx->r15, -0X614C);
    // 0x800B8100: lw          $a2, -0x6154($t9)
    ctx->r6 = MEM_W(ctx->r25, -0X6154);
    // 0x800B8104: lw          $a1, -0x615C($t5)
    ctx->r5 = MEM_W(ctx->r13, -0X615C);
    // 0x800B8108: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B810C: jal         0x800B643C
    // 0x800B8110: addiu       $a0, $a0, -0x69A0
    ctx->r4 = ADD32(ctx->r4, -0X69A0);
    render_printf(rdram, ctx);
        goto after_23;
    // 0x800B8110: addiu       $a0, $a0, -0x69A0
    ctx->r4 = ADD32(ctx->r4, -0X69A0);
    after_23:
    // 0x800B8114: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B8118: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B811C: lw          $a2, -0x613C($t3)
    ctx->r6 = MEM_W(ctx->r11, -0X613C);
    // 0x800B8120: lw          $a1, -0x6144($t1)
    ctx->r5 = MEM_W(ctx->r9, -0X6144);
    // 0x800B8124: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B8128: jal         0x800B643C
    // 0x800B812C: addiu       $a0, $a0, -0x6980
    ctx->r4 = ADD32(ctx->r4, -0X6980);
    render_printf(rdram, ctx);
        goto after_24;
    // 0x800B812C: addiu       $a0, $a0, -0x6980
    ctx->r4 = ADD32(ctx->r4, -0X6980);
    after_24:
    // 0x800B8130: b           L_800B820C
    // 0x800B8134: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B820C;
    // 0x800B8134: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B8138:
    // 0x800B8138: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800B813C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800B8140: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800B8144: addiu       $v1, $v1, -0x30
    ctx->r3 = ADD32(ctx->r3, -0X30);
    // 0x800B8148: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B814C: addiu       $t5, $t5, -0x6090
    ctx->r13 = ADD32(ctx->r13, -0X6090);
    // 0x800B8150: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800B8154: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800B8158: addiu       $s1, $s1, -0x6968
    ctx->r17 = ADD32(ctx->r17, -0X6968);
    // 0x800B815C: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x800B8160: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B8164: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
L_800B8168:
    // 0x800B8168: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800B816C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x800B8170: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800B8174: jal         0x800B643C
    // 0x800B8178: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    render_printf(rdram, ctx);
        goto after_25;
    // 0x800B8178: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x800B817C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B8180: bne         $s4, $s5, L_800B8168
    if (ctx->r20 != ctx->r21) {
        // 0x800B8184: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800B8168;
    }
    // 0x800B8184: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B8188: b           L_800B820C
    // 0x800B818C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B820C;
    // 0x800B818C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B8190:
    // 0x800B8190: sll         $v1, $v0, 7
    ctx->r3 = S32(ctx->r2 << 7);
    // 0x800B8194: addiu       $v1, $v1, -0x200
    ctx->r3 = ADD32(ctx->r3, -0X200);
    // 0x800B8198: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B819C: addiu       $t9, $t9, -0x5E90
    ctx->r25 = ADD32(ctx->r25, -0X5E90);
    // 0x800B81A0: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800B81A4: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x800B81A8: addiu       $s2, $s2, -0x6950
    ctx->r18 = ADD32(ctx->r18, -0X6950);
    // 0x800B81AC: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x800B81B0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B81B4: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x800B81B8: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_800B81BC:
    // 0x800B81BC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B81C0: jal         0x800B643C
    // 0x800B81C4: addiu       $a0, $a0, -0x6954
    ctx->r4 = ADD32(ctx->r4, -0X6954);
    render_printf(rdram, ctx);
        goto after_26;
    // 0x800B81C4: addiu       $a0, $a0, -0x6954
    ctx->r4 = ADD32(ctx->r4, -0X6954);
    after_26:
    // 0x800B81C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B81CC:
    // 0x800B81CC: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    // 0x800B81D0: jal         0x800B643C
    // 0x800B81D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    render_printf(rdram, ctx);
        goto after_27;
    // 0x800B81D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_27:
    // 0x800B81D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B81DC: bne         $s0, $s3, L_800B81CC
    if (ctx->r16 != ctx->r19) {
        // 0x800B81E0: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800B81CC;
    }
    // 0x800B81E0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800B81E4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B81E8: jal         0x800B643C
    // 0x800B81EC: addiu       $a0, $a0, -0x6948
    ctx->r4 = ADD32(ctx->r4, -0X6948);
    render_printf(rdram, ctx);
        goto after_28;
    // 0x800B81EC: addiu       $a0, $a0, -0x6948
    ctx->r4 = ADD32(ctx->r4, -0X6948);
    after_28:
    // 0x800B81F0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B81F4: bne         $s4, $s5, L_800B81BC
    if (ctx->r20 != ctx->r21) {
        // 0x800B81F8: nop
    
            goto L_800B81BC;
    }
    // 0x800B81F8: nop

    // 0x800B81FC: b           L_800B820C
    // 0x800B8200: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800B820C;
    // 0x800B8200: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B8204:
    // 0x800B8204: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800B8208:
    // 0x800B8208: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B820C:
    // 0x800B820C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B8210: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B8214: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8218: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B821C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800B8220: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800B8224: jr          $ra
    // 0x800B8228: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800B8228: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void race_postrace_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB20: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x8006DB24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DB28: jr          $ra
    // 0x8006DB2C: sb          $t6, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = ctx->r14;
    return;
    // 0x8006DB2C: sb          $t6, 0x3A96($at)
    MEM_B(0X3A96, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void mark_write_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF20: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EF24: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EF28: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EF2C: nop

    // 0x8006EF30: ori         $t7, $t6, 0x200
    ctx->r15 = ctx->r14 | 0X200;
    // 0x8006EF34: jr          $ra
    // 0x8006EF38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EF38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
