#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void credits_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B72C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009B730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B734: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8009B738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009B73C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009B740: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009B744: bne         $at, $zero, L_8009B754
    if (ctx->r1 != 0) {
        // 0x8009B748: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8009B754;
    }
    // 0x8009B748: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8009B74C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009B750: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_8009B754:
    // 0x8009B754: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8009B758: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009B75C: bgez        $t2, L_8009B768
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8009B760: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_8009B768;
    }
    // 0x8009B760: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8009B764: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8009B768:
    // 0x8009B768: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B76C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009B770: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009B774: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009B778: addiu       $t9, $t9, 0x1D00
    ctx->r25 = ADD32(ctx->r25, 0X1D00);
    // 0x8009B77C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8009B780: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009B784: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009B788: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B78C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8009B790: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8009B794: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8009B798: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x8009B79C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8009B7A0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8009B7A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B7A8: lui         $t8, 0xFFFD
    ctx->r24 = S32(0XFFFD << 16);
    // 0x8009B7AC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009B7B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009B7B4: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x8009B7B8: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8009B7BC: ori         $t8, $t8, 0xF6FB
    ctx->r24 = ctx->r24 | 0XF6FB;
    // 0x8009B7C0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009B7C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009B7C8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8009B7CC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8009B7D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B7D4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8009B7D8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8009B7DC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B7E0: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8009B7E4: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x8009B7E8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009B7EC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009B7F0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x8009B7F4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8009B7F8: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8009B7FC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009B800: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009B804: or          $t4, $t9, $t8
    ctx->r12 = ctx->r25 | ctx->r24;
    // 0x8009B808: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8009B80C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8009B810: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8009B814: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x8009B818: andi        $t6, $t5, 0x3FF
    ctx->r14 = ctx->r13 & 0X3FF;
    // 0x8009B81C: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x8009B820: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8009B824: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x8009B828: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8009B82C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B830: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8009B834: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009B838: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009B83C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009B840: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009B844: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009B848: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8009B84C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009B850: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009B854: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009B858: jal         0x8007B820
    // 0x8009B85C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x8009B85C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    after_0:
    // 0x8009B860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B868: jr          $ra
    // 0x8009B86C: nop

    return;
    // 0x8009B86C: nop

;}
RECOMP_FUNC void find_next_checkpoint_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA50: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8001BA54: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BA58: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BA5C: lw          $v0, -0x4BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB4);
    // 0x8001BA60: mflo        $t6
    ctx->r14 = lo;
    // 0x8001BA64: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x8001BA68: beq         $a1, $zero, L_8001BA90
    if (ctx->r5 == 0) {
        // 0x8001BA6C: nop
    
            goto L_8001BA90;
    }
    // 0x8001BA6C: nop

    // 0x8001BA70: lb          $a0, 0x3A($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X3A);
    // 0x8001BA74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001BA78: beq         $a0, $at, L_8001BA90
    if (ctx->r4 == ctx->r1) {
        // 0x8001BA7C: nop
    
            goto L_8001BA90;
    }
    // 0x8001BA7C: nop

    // 0x8001BA80: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BA84: mflo        $t7
    ctx->r15 = lo;
    // 0x8001BA88: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x8001BA8C: nop

L_8001BA90:
    // 0x8001BA90: jr          $ra
    // 0x8001BA94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001BA94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void racer_play_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005708C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80057090: lw          $t7, -0x2524($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2524);
    // 0x80057094: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80057098: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005709C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800570A0: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800570A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800570A8: beq         $t7, $at, L_800570D4
    if (ctx->r15 == ctx->r1) {
        // 0x800570AC: or          $t6, $a0, $zero
        ctx->r14 = ctx->r4 | 0;
            goto L_800570D4;
    }
    // 0x800570AC: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800570B0: lw          $t8, 0x108($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X108);
    // 0x800570B4: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x800570B8: bne         $t8, $zero, L_800570D8
    if (ctx->r24 != 0) {
        // 0x800570BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800570D8;
    }
    // 0x800570BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800570C0: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    // 0x800570C4: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x800570C8: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    // 0x800570CC: jal         0x80001EA8
    // 0x800570D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_0;
    // 0x800570D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
L_800570D4:
    // 0x800570D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800570D8:
    // 0x800570D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800570DC: jr          $ra
    // 0x800570E0: nop

    return;
    // 0x800570E0: nop

;}
RECOMP_FUNC void func_800BA288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA7A8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA7AC: lw          $v1, -0x5960($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5960);
    // 0x800BA7B0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800BA7B4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800BA7B8: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800BA7BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BA7C0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800BA7C4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800BA7C8: blez        $v1, L_800BA9C8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BA7CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BA9C8;
    }
    // 0x800BA7CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BA7D0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BA7D4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BA7D8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BA7DC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BA7E0: addiu       $t1, $t1, 0x3668
    ctx->r9 = ADD32(ctx->r9, 0X3668);
    // 0x800BA7E4: addiu       $t2, $t2, -0x5958
    ctx->r10 = ADD32(ctx->r10, -0X5958);
    // 0x800BA7E8: addiu       $t3, $t3, -0x5A78
    ctx->r11 = ADD32(ctx->r11, -0X5A78);
    // 0x800BA7EC: addiu       $t4, $t4, 0x3664
    ctx->r12 = ADD32(ctx->r12, 0X3664);
    // 0x800BA7F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BA7F4: addiu       $s1, $zero, 0x80
    ctx->r17 = ADD32(0, 0X80);
    // 0x800BA7F8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
L_800BA7FC:
    // 0x800BA7FC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800BA800: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BA804: addu        $a3, $a0, $a2
    ctx->r7 = ADD32(ctx->r4, ctx->r6);
    // 0x800BA808: lbu         $t7, 0xA($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0XA);
    // 0x800BA80C: lbu         $t6, 0xB($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XB);
    // 0x800BA810: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x800BA814: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800BA818: addu        $t7, $t2, $t8
    ctx->r15 = ADD32(ctx->r10, ctx->r24);
    // 0x800BA81C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x800BA820: nop

    // 0x800BA824: and         $t8, $t9, $t6
    ctx->r24 = ctx->r25 & ctx->r14;
    // 0x800BA828: beq         $t8, $zero, L_800BA9B8
    if (ctx->r24 == 0) {
        // 0x800BA82C: nop
    
            goto L_800BA9B8;
    }
    // 0x800BA82C: nop

    // 0x800BA830: lw          $t7, 0x28($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X28);
    // 0x800BA834: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BA838: beq         $t7, $zero, L_800BA910
    if (ctx->r15 == 0) {
        // 0x800BA83C: nop
    
            goto L_800BA910;
    }
    // 0x800BA83C: nop

L_800BA840:
    // 0x800BA840: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800BA844: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800BA848: addu        $t6, $a0, $a2
    ctx->r14 = ADD32(ctx->r4, ctx->r6);
    // 0x800BA84C: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800BA850: nop

    // 0x800BA854: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA858: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x800BA85C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800BA860: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800BA864: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800BA868: sllv        $t6, $t7, $t9
    ctx->r14 = S32(ctx->r15 << (ctx->r25 & 31));
    // 0x800BA86C: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x800BA870: beq         $t7, $zero, L_800BA8B8
    if (ctx->r15 == 0) {
        // 0x800BA874: sll         $t8, $v0, 3
        ctx->r24 = S32(ctx->r2 << 3);
            goto L_800BA8B8;
    }
    // 0x800BA874: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800BA878: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800BA87C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800BA880: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BA884: addu        $t8, $a0, $t9
    ctx->r24 = ADD32(ctx->r4, ctx->r25);
    // 0x800BA888: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x800BA88C: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800BA890: addu        $a3, $t7, $v1
    ctx->r7 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA894: lbu         $t0, 0x14($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA898: nop

    // 0x800BA89C: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BA8A0: beq         $at, $zero, L_800BA8B0
    if (ctx->r1 == 0) {
        // 0x800BA8A4: subu        $t9, $t0, $a1
        ctx->r25 = SUB32(ctx->r8, ctx->r5);
            goto L_800BA8B0;
    }
    // 0x800BA8A4: subu        $t9, $t0, $a1
    ctx->r25 = SUB32(ctx->r8, ctx->r5);
    // 0x800BA8A8: b           L_800BA8F4
    // 0x800BA8AC: sb          $t9, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r25;
        goto L_800BA8F4;
    // 0x800BA8AC: sb          $t9, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r25;
L_800BA8B0:
    // 0x800BA8B0: b           L_800BA8F4
    // 0x800BA8B4: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
        goto L_800BA8F4;
    // 0x800BA8B4: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
L_800BA8B8:
    // 0x800BA8B8: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800BA8BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800BA8C0: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x800BA8C4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800BA8C8: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800BA8CC: addu        $a3, $t9, $v1
    ctx->r7 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA8D0: lbu         $t8, 0x14($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA8D4: nop

    // 0x800BA8D8: addu        $t0, $t8, $a1
    ctx->r8 = ADD32(ctx->r24, ctx->r5);
    // 0x800BA8DC: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800BA8E0: beq         $at, $zero, L_800BA8F0
    if (ctx->r1 == 0) {
        // 0x800BA8E4: nop
    
            goto L_800BA8F0;
    }
    // 0x800BA8E4: nop

    // 0x800BA8E8: b           L_800BA8F4
    // 0x800BA8EC: sb          $t0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r8;
        goto L_800BA8F4;
    // 0x800BA8EC: sb          $t0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r8;
L_800BA8F0:
    // 0x800BA8F0: sb          $s1, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r17;
L_800BA8F4:
    // 0x800BA8F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BA8F8: bne         $v1, $t5, L_800BA840
    if (ctx->r3 != ctx->r13) {
        // 0x800BA8FC: nop
    
            goto L_800BA840;
    }
    // 0x800BA8FC: nop

    // 0x800BA900: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA904: lw          $v1, -0x5960($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5960);
    // 0x800BA908: b           L_800BA9BC
    // 0x800BA90C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800BA9BC;
    // 0x800BA90C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA910:
    // 0x800BA910: lw          $t7, 0xC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XC);
    // 0x800BA914: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800BA918: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA91C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800BA920: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA924: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
    // 0x800BA928: beq         $t7, $zero, L_800BA96C
    if (ctx->r15 == 0) {
        // 0x800BA92C: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_800BA96C;
    }
    // 0x800BA92C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800BA930: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800BA934: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BA938: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x800BA93C: addu        $a3, $t9, $v1
    ctx->r7 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA940: lbu         $t0, 0x14($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA944: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA948: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BA94C: beq         $at, $zero, L_800BA95C
    if (ctx->r1 == 0) {
        // 0x800BA950: subu        $t8, $t0, $a1
        ctx->r24 = SUB32(ctx->r8, ctx->r5);
            goto L_800BA95C;
    }
    // 0x800BA950: subu        $t8, $t0, $a1
    ctx->r24 = SUB32(ctx->r8, ctx->r5);
    // 0x800BA954: b           L_800BA960
    // 0x800BA958: sb          $t8, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r24;
        goto L_800BA960;
    // 0x800BA958: sb          $t8, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r24;
L_800BA95C:
    // 0x800BA95C: sb          $zero, 0x14($a3)
    MEM_B(0X14, ctx->r7) = 0;
L_800BA960:
    // 0x800BA960: lw          $v1, -0x5960($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5960);
    // 0x800BA964: b           L_800BA9BC
    // 0x800BA968: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800BA9BC;
    // 0x800BA968: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA96C:
    // 0x800BA96C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800BA970: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800BA974: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BA978: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x800BA97C: addu        $a3, $t6, $v1
    ctx->r7 = ADD32(ctx->r14, ctx->r3);
    // 0x800BA980: lbu         $t9, 0x14($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X14);
    // 0x800BA984: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA988: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x800BA98C: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800BA990: beq         $at, $zero, L_800BA9AC
    if (ctx->r1 == 0) {
        // 0x800BA994: nop
    
            goto L_800BA9AC;
    }
    // 0x800BA994: nop

    // 0x800BA998: sb          $t0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r8;
    // 0x800BA99C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA9A0: lw          $v1, -0x5960($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5960);
    // 0x800BA9A4: b           L_800BA9BC
    // 0x800BA9A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800BA9BC;
    // 0x800BA9A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA9AC:
    // 0x800BA9AC: sb          $s1, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r17;
    // 0x800BA9B0: lw          $v1, -0x5960($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5960);
    // 0x800BA9B4: nop

L_800BA9B8:
    // 0x800BA9B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800BA9BC:
    // 0x800BA9BC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BA9C0: bne         $at, $zero, L_800BA7FC
    if (ctx->r1 != 0) {
        // 0x800BA9C4: addiu       $a2, $a2, 0x1C
        ctx->r6 = ADD32(ctx->r6, 0X1C);
            goto L_800BA7FC;
    }
    // 0x800BA9C4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
L_800BA9C8:
    // 0x800BA9C8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800BA9CC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800BA9D0: jr          $ra
    // 0x800BA9D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800BA9D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void obj_init_collectegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003526C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80035270: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80035274: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80035278: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003527C: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80035280: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80035284: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80035288: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003528C: nop

    // 0x80035290: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80035294: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80035298: jr          $ra
    // 0x8003529C: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    return;
    // 0x8003529C: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
;}
RECOMP_FUNC void copy_viewport_frame_size_to_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066E6C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066E70: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066E74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066E78: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066E7C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066E80: addiu       $t7, $t7, -0x2A2C
    ctx->r15 = ADD32(ctx->r15, -0X2A2C);
    // 0x80066E84: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066E88: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066E8C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80066E90: nop

    // 0x80066E94: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80066E98: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80066E9C: nop

    // 0x80066EA0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80066EA4: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80066EA8: nop

    // 0x80066EAC: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x80066EB0: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x80066EB4: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80066EB8: jr          $ra
    // 0x80066EBC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    return;
    // 0x80066EBC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
;}
RECOMP_FUNC void obj_init_frog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042258: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8004225C: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x80042260: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042264: sb          $t6, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r14;
    // 0x80042268: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8004226C: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x80042270: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80042274: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80042278: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004227C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80042280: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80042284: nop

    // 0x80042288: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8004228C: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x80042290: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x80042294: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80042298: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004229C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800422A0: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x800422A4: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800422A8: nop

    // 0x800422AC: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800422B0: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x800422B4: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800422B8: nop

    // 0x800422BC: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x800422C0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800422C4: sb          $zero, 0x19($v0)
    MEM_B(0X19, ctx->r2) = 0;
    // 0x800422C8: swc1        $f8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f8.u32l;
    // 0x800422CC: beq         $t8, $zero, L_8004231C
    if (ctx->r24 == 0) {
        // 0x800422D0: swc1        $f6, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
            goto L_8004231C;
    }
    // 0x800422D0: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x800422D4: sb          $t9, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r25;
    // 0x800422D8: jal         0x8009F214
    // 0x800422DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_drumstick_unlocked(rdram, ctx);
        goto after_0;
    // 0x800422DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800422E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800422E4: bne         $v0, $zero, L_8004230C
    if (ctx->r2 != 0) {
        // 0x800422E8: nop
    
            goto L_8004230C;
    }
    // 0x800422E8: nop

    // 0x800422EC: jal         0x8006ECD0
    // 0x800422F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_1;
    // 0x800422F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x800422F4: lhu         $t0, 0xE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XE);
    // 0x800422F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800422FC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80042300: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80042304: beq         $t1, $at, L_80042324
    if (ctx->r9 == ctx->r1) {
        // 0x80042308: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80042324;
    }
    // 0x80042308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004230C:
    // 0x8004230C: jal         0x8000FFB8
    // 0x80042310: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x80042310: nop

    after_2:
    // 0x80042314: b           L_80042324
    // 0x80042318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80042324;
    // 0x80042318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004231C:
    // 0x8004231C: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
    // 0x80042320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80042324:
    // 0x80042324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042328: jr          $ra
    // 0x8004232C: nop

    return;
    // 0x8004232C: nop

;}
RECOMP_FUNC void reset_controller_sticks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C3A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3A4: sb          $zero, 0x69FC($at)
    MEM_B(0X69FC, ctx->r1) = 0;
    // 0x8009C3A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3AC: sb          $zero, 0x6A04($at)
    MEM_B(0X6A04, ctx->r1) = 0;
    // 0x8009C3B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3B4: sb          $zero, 0x69F4($at)
    MEM_B(0X69F4, ctx->r1) = 0;
    // 0x8009C3B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3BC: sb          $zero, 0x69F8($at)
    MEM_B(0X69F8, ctx->r1) = 0;
    // 0x8009C3C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3C4: sb          $zero, 0x6A08($at)
    MEM_B(0X6A08, ctx->r1) = 0;
    // 0x8009C3C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3CC: sb          $zero, 0x6A0C($at)
    MEM_B(0X6A0C, ctx->r1) = 0;
    // 0x8009C3D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3D4: sb          $zero, 0x69FD($at)
    MEM_B(0X69FD, ctx->r1) = 0;
    // 0x8009C3D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3DC: sb          $zero, 0x6A05($at)
    MEM_B(0X6A05, ctx->r1) = 0;
    // 0x8009C3E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3E4: sb          $zero, 0x69F5($at)
    MEM_B(0X69F5, ctx->r1) = 0;
    // 0x8009C3E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3EC: sb          $zero, 0x69F9($at)
    MEM_B(0X69F9, ctx->r1) = 0;
    // 0x8009C3F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3F4: sb          $zero, 0x6A09($at)
    MEM_B(0X6A09, ctx->r1) = 0;
    // 0x8009C3F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C3FC: sb          $zero, 0x6A0D($at)
    MEM_B(0X6A0D, ctx->r1) = 0;
    // 0x8009C400: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C404: sb          $zero, 0x69FE($at)
    MEM_B(0X69FE, ctx->r1) = 0;
    // 0x8009C408: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C40C: sb          $zero, 0x6A06($at)
    MEM_B(0X6A06, ctx->r1) = 0;
    // 0x8009C410: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C414: sb          $zero, 0x69F6($at)
    MEM_B(0X69F6, ctx->r1) = 0;
    // 0x8009C418: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C41C: sb          $zero, 0x69FA($at)
    MEM_B(0X69FA, ctx->r1) = 0;
    // 0x8009C420: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C424: sb          $zero, 0x6A0A($at)
    MEM_B(0X6A0A, ctx->r1) = 0;
    // 0x8009C428: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C42C: sb          $zero, 0x6A0E($at)
    MEM_B(0X6A0E, ctx->r1) = 0;
    // 0x8009C430: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C434: sb          $zero, 0x69FF($at)
    MEM_B(0X69FF, ctx->r1) = 0;
    // 0x8009C438: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C43C: sb          $zero, 0x6A07($at)
    MEM_B(0X6A07, ctx->r1) = 0;
    // 0x8009C440: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C444: sb          $zero, 0x69F7($at)
    MEM_B(0X69F7, ctx->r1) = 0;
    // 0x8009C448: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C44C: sb          $zero, 0x69FB($at)
    MEM_B(0X69FB, ctx->r1) = 0;
    // 0x8009C450: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C454: sb          $zero, 0x6A0B($at)
    MEM_B(0X6A0B, ctx->r1) = 0;
    // 0x8009C458: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C45C: jr          $ra
    // 0x8009C460: sb          $zero, 0x6A0F($at)
    MEM_B(0X6A0F, ctx->r1) = 0;
    return;
    // 0x8009C460: sb          $zero, 0x6A0F($at)
    MEM_B(0X6A0F, ctx->r1) = 0;
;}
RECOMP_FUNC void filename_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097E54: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80097E58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097E5C: lwc1        $f0, 0x7210($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7210);
    // 0x80097E60: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80097E64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80097E68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80097E6C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80097E70: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80097E74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80097E78: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80097E7C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80097E80: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80097E84: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80097E88: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80097E8C: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x80097E90: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80097E94: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80097E98: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80097E9C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80097EA0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80097EA4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80097EA8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80097EAC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80097EB0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80097EB4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80097EB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80097EBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80097EC0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80097EC4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80097EC8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80097ECC: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80097ED0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80097ED4: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x80097ED8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80097EDC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80097EE0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80097EE4: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80097EE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80097EEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80097EF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097EF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80097EF8: jal         0x800C492C
    // 0x80097EFC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    set_text_background_colour(rdram, ctx);
        goto after_0;
    // 0x80097EFC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80097F00: jal         0x800C484C
    // 0x80097F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_1;
    // 0x80097F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80097F08: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x80097F0C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80097F10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80097F14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80097F18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097F1C: jal         0x800C48E4
    // 0x80097F20: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x80097F20: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x80097F24: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80097F28: addiu       $s1, $s1, -0x5E0
    ctx->r17 = ADD32(ctx->r17, -0X5E0);
    // 0x80097F2C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80097F30: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80097F34: addiu       $s0, $s0, 0x1510
    ctx->r16 = ADD32(ctx->r16, 0X1510);
    // 0x80097F38: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80097F3C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80097F40: addiu       $s3, $s3, 0x693C
    ctx->r19 = ADD32(ctx->r19, 0X693C);
    // 0x80097F44: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80097F48: lw          $a3, 0x20($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X20);
    // 0x80097F4C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80097F50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097F54: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
    // 0x80097F58: jal         0x800C49A0
    // 0x80097F5C: addiu       $a2, $a2, -0x16
    ctx->r6 = ADD32(ctx->r6, -0X16);
    draw_text(rdram, ctx);
        goto after_3;
    // 0x80097F5C: addiu       $a2, $a2, -0x16
    ctx->r6 = ADD32(ctx->r6, -0X16);
    after_3:
    // 0x80097F60: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80097F64: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80097F68: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80097F6C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80097F70: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80097F74: jal         0x800C48E4
    // 0x80097F78: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x80097F78: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_4:
    // 0x80097F7C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80097F80: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80097F84: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80097F88: lw          $a3, 0x20($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X20);
    // 0x80097F8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80097F90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80097F94: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80097F98: jal         0x800C49A0
    // 0x80097F9C: addiu       $a2, $a2, -0x18
    ctx->r6 = ADD32(ctx->r6, -0X18);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80097F9C: addiu       $a2, $a2, -0x18
    ctx->r6 = ADD32(ctx->r6, -0X18);
    after_5:
    // 0x80097FA0: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80097FA4: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80097FA8: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80097FAC: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x80097FB0: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80097FB4: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80097FB8: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80097FBC: addiu       $s4, $s4, 0x150C
    ctx->r20 = ADD32(ctx->r20, 0X150C);
    // 0x80097FC0: addiu       $s7, $s7, 0x722C
    ctx->r23 = ADD32(ctx->r23, 0X722C);
    // 0x80097FC4: addiu       $fp, $fp, 0x14EC
    ctx->r30 = ADD32(ctx->r30, 0X14EC);
L_80097FC8:
    // 0x80097FC8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80097FCC: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80097FD0: beq         $t7, $zero, L_80097FEC
    if (ctx->r15 == 0) {
        // 0x80097FD4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80097FEC;
    }
    // 0x80097FD4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80097FD8: addiu       $s1, $v1, -0x28
    ctx->r17 = ADD32(ctx->r3, -0X28);
    // 0x80097FDC: addiu       $s0, $v0, -0x1
    ctx->r16 = ADD32(ctx->r2, -0X1);
    // 0x80097FE0: addiu       $s5, $zero, -0x28
    ctx->r21 = ADD32(0, -0X28);
    // 0x80097FE4: b           L_80097FF4
    // 0x80097FE8: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
        goto L_80097FF4;
    // 0x80097FE8: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_80097FEC:
    // 0x80097FEC: addiu       $s5, $zero, 0x28
    ctx->r21 = ADD32(0, 0X28);
    // 0x80097FF0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80097FF4:
    // 0x80097FF4: slti        $at, $s1, -0xF
    ctx->r1 = SIGNED(ctx->r17) < -0XF ? 1 : 0;
    // 0x80097FF8: bne         $at, $zero, L_80098150
    if (ctx->r1 != 0) {
        // 0x80097FFC: slti        $at, $s1, 0x150
        ctx->r1 = SIGNED(ctx->r17) < 0X150 ? 1 : 0;
            goto L_80098150;
    }
    // 0x80097FFC: slti        $at, $s1, 0x150
    ctx->r1 = SIGNED(ctx->r17) < 0X150 ? 1 : 0;
    // 0x80098000: beq         $at, $zero, L_80098154
    if (ctx->r1 == 0) {
        // 0x80098004: lw          $t9, 0x60($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X60);
            goto L_80098154;
    }
    // 0x80098004: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
L_80098008:
    // 0x80098008: bgez        $s0, L_80098014
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8009800C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80098014;
    }
    // 0x8009800C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80098010: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
L_80098014:
    // 0x80098014: slti        $at, $s0, 0x1F
    ctx->r1 = SIGNED(ctx->r16) < 0X1F ? 1 : 0;
    // 0x80098018: bne         $at, $zero, L_80098024
    if (ctx->r1 != 0) {
        // 0x8009801C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80098024;
    }
    // 0x8009801C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80098020: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80098024:
    // 0x80098024: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80098028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009802C: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80098030: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x80098034: bne         $s0, $t8, L_80098060
    if (ctx->r16 != ctx->r24) {
        // 0x80098038: addiu       $t1, $zero, 0xFF
        ctx->r9 = ADD32(0, 0XFF);
            goto L_80098060;
    }
    // 0x80098038: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009803C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80098040: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80098044: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80098048: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009804C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80098050: jal         0x800C48E4
    // 0x80098054: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_6;
    // 0x80098054: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80098058: b           L_8009806C
    // 0x8009805C: slti        $at, $s0, 0x1C
    ctx->r1 = SIGNED(ctx->r16) < 0X1C ? 1 : 0;
        goto L_8009806C;
    // 0x8009805C: slti        $at, $s0, 0x1C
    ctx->r1 = SIGNED(ctx->r16) < 0X1C ? 1 : 0;
L_80098060:
    // 0x80098060: jal         0x800C48E4
    // 0x80098064: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x80098064: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_7:
    // 0x80098068: slti        $at, $s0, 0x1C
    ctx->r1 = SIGNED(ctx->r16) < 0X1C ? 1 : 0;
L_8009806C:
    // 0x8009806C: beq         $at, $zero, L_800980AC
    if (ctx->r1 == 0) {
        // 0x80098070: nop
    
            goto L_800980AC;
    }
    // 0x80098070: nop

    // 0x80098074: jal         0x800C484C
    // 0x80098078: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_8;
    // 0x80098078: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x8009807C: addu        $t2, $fp, $s0
    ctx->r10 = ADD32(ctx->r30, ctx->r16);
    // 0x80098080: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80098084: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80098088: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8009808C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80098090: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80098094: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80098098: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8009809C: jal         0x800C49A0
    // 0x800980A0: sb          $t3, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r11;
    draw_text(rdram, ctx);
        goto after_9;
    // 0x800980A0: sb          $t3, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r11;
    after_9:
    // 0x800980A4: b           L_80098138
    // 0x800980A8: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
        goto L_80098138;
    // 0x800980A8: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_800980AC:
    // 0x800980AC: jal         0x800C484C
    // 0x800980B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_10;
    // 0x800980B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x800980B4: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800980B8: bne         $s0, $at, L_800980E4
    if (ctx->r16 != ctx->r1) {
        // 0x800980BC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800980E4;
    }
    // 0x800980BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800980C0: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800980C4: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x800980C8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800980CC: addiu       $a3, $a3, -0x782C
    ctx->r7 = ADD32(ctx->r7, -0X782C);
    // 0x800980D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800980D4: jal         0x800C49A0
    // 0x800980D8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_11;
    // 0x800980D8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_11:
    // 0x800980DC: b           L_80098138
    // 0x800980E0: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
        goto L_80098138;
    // 0x800980E0: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_800980E4:
    // 0x800980E4: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x800980E8: bne         $s0, $at, L_80098118
    if (ctx->r16 != ctx->r1) {
        // 0x800980EC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80098118;
    }
    // 0x800980EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800980F0: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800980F4: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x800980F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800980FC: addiu       $a3, $a3, -0x7828
    ctx->r7 = ADD32(ctx->r7, -0X7828);
    // 0x80098100: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80098104: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80098108: jal         0x800C49A0
    // 0x8009810C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_12;
    // 0x8009810C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_12:
    // 0x80098110: b           L_80098138
    // 0x80098114: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
        goto L_80098138;
    // 0x80098114: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_80098118:
    // 0x80098118: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8009811C: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80098120: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80098124: addiu       $a3, $a3, -0x7824
    ctx->r7 = ADD32(ctx->r7, -0X7824);
    // 0x80098128: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8009812C: jal         0x800C49A0
    // 0x80098130: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_13;
    // 0x80098130: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_13:
    // 0x80098134: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
L_80098138:
    // 0x80098138: slti        $at, $s1, -0xF
    ctx->r1 = SIGNED(ctx->r17) < -0XF ? 1 : 0;
    // 0x8009813C: bne         $at, $zero, L_80098150
    if (ctx->r1 != 0) {
        // 0x80098140: addu        $s0, $s0, $s6
        ctx->r16 = ADD32(ctx->r16, ctx->r22);
            goto L_80098150;
    }
    // 0x80098140: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x80098144: slti        $at, $s1, 0x150
    ctx->r1 = SIGNED(ctx->r17) < 0X150 ? 1 : 0;
    // 0x80098148: bne         $at, $zero, L_80098008
    if (ctx->r1 != 0) {
        // 0x8009814C: nop
    
            goto L_80098008;
    }
    // 0x8009814C: nop

L_80098150:
    // 0x80098150: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
L_80098154:
    // 0x80098154: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80098158: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8009815C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80098160: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80098164: bne         $t8, $at, L_80097FC8
    if (ctx->r24 != ctx->r1) {
        // 0x80098168: sw          $t8, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r24;
            goto L_80097FC8;
    }
    // 0x80098168: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x8009816C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098170: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x80098174: lw          $a0, 0x7238($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7238);
    // 0x80098178: jal         0x80097D0C
    // 0x8009817C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    filename_trim(rdram, ctx);
        goto after_14;
    // 0x8009817C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x80098180: beq         $s0, $zero, L_8009821C
    if (ctx->r16 == 0) {
        // 0x80098184: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8009821C;
    }
    // 0x80098184: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80098188: lw          $a0, 0x151C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X151C);
    // 0x8009818C: jal         0x800C484C
    // 0x80098190: nop

    set_text_font(rdram, ctx);
        goto after_15;
    // 0x80098190: nop

    after_15:
    // 0x80098194: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x80098198: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8009819C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800981A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800981A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800981A8: jal         0x800C48E4
    // 0x800981AC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_16;
    // 0x800981AC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_16:
    // 0x800981B0: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800981B4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800981B8: addiu       $s2, $s2, 0x1518
    ctx->r18 = ADD32(ctx->r18, 0X1518);
    // 0x800981BC: addiu       $s1, $s1, 0x1514
    ctx->r17 = ADD32(ctx->r17, 0X1514);
    // 0x800981C0: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800981C4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800981C8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800981CC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800981D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800981D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800981D8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800981DC: jal         0x800C49A0
    // 0x800981E0: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    draw_text(rdram, ctx);
        goto after_17;
    // 0x800981E0: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    after_17:
    // 0x800981E4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800981E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800981EC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800981F0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800981F4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800981F8: jal         0x800C48E4
    // 0x800981FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x800981FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x80098200: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80098204: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80098208: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8009820C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80098210: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80098214: jal         0x800C49A0
    // 0x80098218: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_19;
    // 0x80098218: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_19:
L_8009821C:
    // 0x8009821C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80098220: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80098224: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80098228: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8009822C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80098230: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80098234: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80098238: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8009823C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80098240: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80098244: jr          $ra
    // 0x80098248: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80098248: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void vec3f_rotate_ypr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070618: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007061C: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070620: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80070624: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80070628: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8007062C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80070630: jal         0x80070A04
    // 0x80070634: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x80070634: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_0:
    // 0x80070638: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8007063C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80070640: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070644: jal         0x80070A38
    // 0x80070648: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x80070648: nop

    after_1:
    // 0x8007064C: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070650: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x80070654: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070658: add.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8007065C: jal         0x80070A04
    // 0x80070660: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80070660: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x80070664: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80070668: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x8007066C: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070670: jal         0x80070A38
    // 0x80070674: nop

    coss_f(rdram, ctx);
        goto after_3;
    // 0x80070674: nop

    after_3:
    // 0x80070678: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007067C: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x80070680: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070684: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80070688: jal         0x80070A04
    // 0x8007068C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_4;
    // 0x8007068C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    after_4:
    // 0x80070690: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070694: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x80070698: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007069C: jal         0x80070A38
    // 0x800706A0: nop

    coss_f(rdram, ctx);
        goto after_5;
    // 0x800706A0: nop

    after_5:
    // 0x800706A4: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800706A8: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x800706AC: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800706B0: sub.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800706B4: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800706B8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800706BC: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800706C0: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x800706C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800706C8: jr          $ra
    // 0x800706CC: nop

    return;
    // 0x800706CC: nop

;}
RECOMP_FUNC void lensflare_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACF80: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x800ACF84: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800ACF88: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800ACF8C: addiu       $s6, $s6, 0x3010
    ctx->r22 = ADD32(ctx->r22, 0X3010);
    // 0x800ACF90: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800ACF94: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800ACF98: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800ACF9C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800ACFA0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800ACFA4: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800ACFA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800ACFAC: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800ACFB0: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x800ACFB4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800ACFB8: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800ACFBC: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800ACFC0: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800ACFC4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800ACFC8: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800ACFCC: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x800ACFD0: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800ACFD4: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x800ACFD8: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800ACFDC: beq         $t7, $zero, L_800AD478
    if (ctx->r15 == 0) {
        // 0x800ACFE0: swc1        $f20, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
            goto L_800AD478;
    }
    // 0x800ACFE0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800ACFE4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800ACFE8: lw          $t9, 0x3014($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3014);
    // 0x800ACFEC: nop

    // 0x800ACFF0: bne         $t9, $zero, L_800AD47C
    if (ctx->r25 != 0) {
        // 0x800ACFF4: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800AD47C;
    }
    // 0x800ACFF4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800ACFF8: jal         0x80066450
    // 0x800ACFFC: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800ACFFC: nop

    after_0:
    // 0x800AD000: bne         $v0, $zero, L_800AD478
    if (ctx->r2 != 0) {
        // 0x800AD004: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_800AD478;
    }
    // 0x800AD004: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800AD008: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800AD00C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800AD010: lw          $t3, 0x3C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X3C);
    // 0x800AD014: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AD018: swc1        $f20, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f20.u32l;
    // 0x800AD01C: swc1        $f20, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f20.u32l;
    // 0x800AD020: sw          $t3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r11;
    // 0x800AD024: jal         0x80069FE4
    // 0x800AD028: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    get_projection_matrix_f32(rdram, ctx);
        goto after_1;
    // 0x800AD028: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800AD02C: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    // 0x800AD030: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800AD034: jal         0x8006F92C
    // 0x800AD038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_2;
    // 0x800AD038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800AD03C: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800AD040: addiu       $fp, $fp, -0x7E10
    ctx->r30 = ADD32(ctx->r30, -0X7E10);
    // 0x800AD044: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800AD048: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800AD04C: lwc1        $f10, 0x4($fp)
    ctx->f10.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800AD050: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800AD054: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800AD058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AD05C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AD060: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800AD064: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800AD068: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AD06C: lwc1        $f8, 0x8($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X8);
    // 0x800AD070: nop

    // 0x800AD074: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AD078: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AD07C: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x800AD080: nop

    // 0x800AD084: bc1f        L_800AD47C
    if (!c1cs) {
        // 0x800AD088: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800AD47C;
    }
    // 0x800AD088: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800AD08C: jal         0x80066F1C
    // 0x800AD090: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    viewport_main(rdram, ctx);
        goto after_3;
    // 0x800AD090: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x800AD094: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AD098: jal         0x80068648
    // 0x800AD09C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_4;
    // 0x800AD09C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x800AD0A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800AD0A4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800AD0A8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800AD0AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD0B0: lwc1        $f12, 0x0($fp)
    ctx->f12.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800AD0B4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AD0B8: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800AD0BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD0C0: lwc1        $f14, 0x4($fp)
    ctx->f14.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800AD0C4: lwc1        $f2, 0x8($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X8);
    // 0x800AD0C8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AD0CC: lwc1        $f18, 0xC8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800AD0D0: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800AD0D4: swc1        $f10, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f10.u32l;
    // 0x800AD0D8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800AD0DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD0E0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AD0E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AD0E8: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800AD0EC: swc1        $f10, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f10.u32l;
    // 0x800AD0F0: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800AD0F4: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800AD0F8: mul.s       $f20, $f18, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800AD0FC: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800AD100: sh          $zero, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = 0;
    // 0x800AD104: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
    // 0x800AD108: mul.s       $f22, $f20, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800AD10C: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800AD110: sh          $zero, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = 0;
    // 0x800AD114: sh          $zero, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = 0;
    // 0x800AD118: mul.s       $f16, $f24, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x800AD11C: lui         $s4, 0xFA00
    ctx->r20 = S32(0XFA00 << 16);
    // 0x800AD120: addiu       $s3, $sp, 0xA4
    ctx->r19 = ADD32(ctx->r29, 0XA4);
    // 0x800AD124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AD128: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800AD12C: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800AD130: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800AD134: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x800AD138: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800AD13C: nop

    // 0x800AD140: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AD144: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x800AD148: swc1        $f8, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f8.u32l;
    // 0x800AD14C: sub.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800AD150: swc1        $f6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f6.u32l;
L_800AD154:
    // 0x800AD154: bne         $s2, $zero, L_800AD168
    if (ctx->r18 != 0) {
        // 0x800AD158: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800AD168;
    }
    // 0x800AD158: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800AD15C: lw          $s0, -0x7E14($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7E14);
    // 0x800AD160: b           L_800AD188
    // 0x800AD164: nop

        goto L_800AD188;
    // 0x800AD164: nop

L_800AD168:
    // 0x800AD168: bne         $s2, $v0, L_800AD180
    if (ctx->r18 != ctx->r2) {
        // 0x800AD16C: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800AD180;
    }
    // 0x800AD16C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800AD170: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800AD174: lw          $s0, -0x7E1C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7E1C);
    // 0x800AD178: b           L_800AD188
    // 0x800AD17C: nop

        goto L_800AD188;
    // 0x800AD17C: nop

L_800AD180:
    // 0x800AD180: lw          $s0, -0x7E18($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7E18);
    // 0x800AD184: nop

L_800AD188:
    // 0x800AD188: beq         $s0, $zero, L_800AD2EC
    if (ctx->r16 == 0) {
        // 0x800AD18C: nop
    
            goto L_800AD2EC;
    }
    // 0x800AD18C: nop

    // 0x800AD190: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800AD194: nop

    // 0x800AD198: blez        $t5, L_800AD2EC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800AD19C: nop
    
            goto L_800AD2EC;
    }
    // 0x800AD19C: nop

L_800AD1A0:
    // 0x800AD1A0: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800AD1A4: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800AD1A8: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800AD1AC: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x800AD1B0: swc1        $f4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f4.u32l;
    // 0x800AD1B4: beq         $s2, $zero, L_800AD210
    if (ctx->r18 == 0) {
        // 0x800AD1B8: swc1        $f10, 0xB8($sp)
        MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
            goto L_800AD210;
    }
    // 0x800AD1B8: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x800AD1BC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AD1C0: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x800AD1C4: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800AD1C8: nop

    // 0x800AD1CC: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AD1D0: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800AD1D4: nop

    // 0x800AD1D8: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AD1DC: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x800AD1E0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AD1E4: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800AD1E8: nop

    // 0x800AD1EC: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800AD1F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AD1F4: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800AD1F8: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x800AD1FC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800AD200: nop

    // 0x800AD204: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AD208: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800AD20C: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
L_800AD210:
    // 0x800AD210: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AD214: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AD218: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800AD21C: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x800AD220: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800AD224: nop

    // 0x800AD228: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800AD22C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800AD230: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x800AD234: lbu         $t3, 0x5($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X5);
    // 0x800AD238: lbu         $t7, 0x4($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4);
    // 0x800AD23C: sll         $t5, $t3, 16
    ctx->r13 = S32(ctx->r11 << 16);
    // 0x800AD240: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x800AD244: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x800AD248: lbu         $t9, 0x7($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7);
    // 0x800AD24C: lbu         $t7, 0x6($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6);
    // 0x800AD250: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AD254: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800AD258: or          $t3, $t8, $t6
    ctx->r11 = ctx->r24 | ctx->r14;
    // 0x800AD25C: bgez        $t9, L_800AD270
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800AD260: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800AD270;
    }
    // 0x800AD260: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AD264: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AD268: nop

    // 0x800AD26C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800AD270:
    // 0x800AD270: mul.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800AD274: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AD278: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AD27C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800AD280: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AD284: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800AD288: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AD28C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD290: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD294: nop

    // 0x800AD298: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AD29C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800AD2A0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AD2A4: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x800AD2A8: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x800AD2AC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800AD2B0: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800AD2B4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800AD2B8: lw          $t9, 0x68($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X68);
    // 0x800AD2BC: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800AD2C0: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x800AD2C4: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800AD2C8: addiu       $t8, $zero, 0x104
    ctx->r24 = ADD32(0, 0X104);
    // 0x800AD2CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800AD2D0: jal         0x80068754
    // 0x800AD2D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    render_sprite_billboard(rdram, ctx);
        goto after_5;
    // 0x800AD2D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_5:
    // 0x800AD2D8: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x800AD2DC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800AD2E0: bgtz        $t6, L_800AD1A0
    if (SIGNED(ctx->r14) > 0) {
        // 0x800AD2E4: nop
    
            goto L_800AD1A0;
    }
    // 0x800AD2E4: nop

    // 0x800AD2E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AD2EC:
    // 0x800AD2EC: bne         $s2, $v0, L_800AD354
    if (ctx->r18 != ctx->r2) {
        // 0x800AD2F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AD354;
    }
    // 0x800AD2F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AD2F4: lwc1        $f12, 0x0($fp)
    ctx->f12.u32l = MEM_W(ctx->r30, 0X0);
    // 0x800AD2F8: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800AD2FC: lwc1        $f14, 0x4($fp)
    ctx->f14.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800AD300: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800AD304: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800AD308: lwc1        $f2, 0x8($fp)
    ctx->f2.u32l = MEM_W(ctx->r30, 0X8);
    // 0x800AD30C: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x800AD310: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800AD314: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AD318: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800AD31C: nop

    // 0x800AD320: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800AD324: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800AD328: mul.s       $f0, $f6, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800AD32C: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800AD330: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AD334: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AD338: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800AD33C: swc1        $f4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f4.u32l;
    // 0x800AD340: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800AD344: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800AD348: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x800AD34C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800AD350: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
L_800AD354:
    // 0x800AD354: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800AD358: bne         $s2, $at, L_800AD154
    if (ctx->r18 != ctx->r1) {
        // 0x800AD35C: nop
    
            goto L_800AD154;
    }
    // 0x800AD35C: nop

    // 0x800AD360: jal         0x8007A970
    // 0x800AD364: nop

    fb_size(rdram, ctx);
        goto after_6;
    // 0x800AD364: nop

    after_6:
    // 0x800AD368: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800AD36C: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800AD370: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800AD374: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AD378: addiu       $t4, $t4, 0x2EB8
    ctx->r12 = ADD32(ctx->r12, 0X2EB8);
    // 0x800AD37C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800AD380: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AD384: sra         $t0, $v0, 16
    ctx->r8 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800AD388: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800AD38C: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x800AD390: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800AD394: andi        $t5, $t0, 0xFFFF
    ctx->r13 = ctx->r8 & 0XFFFF;
    // 0x800AD398: sw          $s4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r20;
    // 0x800AD39C: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x800AD3A0: lbu         $t5, 0x11($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X11);
    // 0x800AD3A4: lbu         $t7, 0x10($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X10);
    // 0x800AD3A8: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x800AD3AC: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800AD3B0: or          $t4, $t8, $t9
    ctx->r12 = ctx->r24 | ctx->r25;
    // 0x800AD3B4: lbu         $t8, 0x13($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X13);
    // 0x800AD3B8: lbu         $t7, 0x12($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X12);
    // 0x800AD3BC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800AD3C0: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800AD3C4: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x800AD3C8: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x800AD3CC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800AD3D0: bgez        $t8, L_800AD3E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800AD3D4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800AD3E8;
    }
    // 0x800AD3D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AD3D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800AD3DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AD3E0: nop

    // 0x800AD3E4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800AD3E8:
    // 0x800AD3E8: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800AD3EC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800AD3F0: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800AD3F4: lui         $t8, 0xFFFD
    ctx->r24 = S32(0XFFFD << 16);
    // 0x800AD3F8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AD3FC: ori         $t8, $t8, 0xF6FB
    ctx->r24 = ctx->r24 | 0XF6FB;
    // 0x800AD400: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AD404: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD408: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD40C: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800AD410: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800AD414: addiu       $a3, $v1, 0x8
    ctx->r7 = ADD32(ctx->r3, 0X8);
    // 0x800AD418: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800AD41C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AD420: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x800AD424: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800AD428: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800AD42C: andi        $t9, $t1, 0x3FF
    ctx->r25 = ctx->r9 & 0X3FF;
    // 0x800AD430: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800AD434: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800AD438: sll         $t3, $t9, 14
    ctx->r11 = S32(ctx->r25 << 14);
    // 0x800AD43C: andi        $t7, $t0, 0x3FF
    ctx->r15 = ctx->r8 & 0X3FF;
    // 0x800AD440: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800AD444: or          $t5, $t3, $at
    ctx->r13 = ctx->r11 | ctx->r1;
    // 0x800AD448: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x800AD44C: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x800AD450: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x800AD454: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800AD458: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800AD45C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800AD460: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AD464: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AD468: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800AD46C: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x800AD470: jal         0x8007B820
    // 0x800AD474: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rendermode_reset(rdram, ctx);
        goto after_7;
    // 0x800AD474: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
L_800AD478:
    // 0x800AD478: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800AD47C:
    // 0x800AD47C: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800AD480: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800AD484: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800AD488: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AD48C: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800AD490: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AD494: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800AD498: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD49C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800AD4A0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800AD4A4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800AD4A8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800AD4AC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800AD4B0: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800AD4B4: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800AD4B8: jr          $ra
    // 0x800AD4BC: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x800AD4BC: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void enable_dialogue_box_vertices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5C04: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5C08: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5C0C: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5C10: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5C14: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5C18: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5C1C: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5C20: nop

    // 0x800C5C24: ori         $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 | 0X4000;
    // 0x800C5C28: jr          $ra
    // 0x800C5C2C: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5C2C: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void mtx_pop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C80: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069C84: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80069C88: addiu       $a2, $a2, 0x129C
    ctx->r6 = ADD32(ctx->r6, 0X129C);
    // 0x80069C8C: addiu       $a1, $a1, 0x12A0
    ctx->r5 = ADD32(ctx->r5, 0X12A0);
    // 0x80069C90: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80069C94: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80069C98: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80069C9C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80069CA0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80069CA4: blez        $t9, L_80069CE8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80069CA8: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_80069CE8;
    }
    // 0x80069CA8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80069CAC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80069CB0: lui         $t2, 0x140
    ctx->r10 = S32(0X140 << 16);
    // 0x80069CB4: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80069CB8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80069CBC: ori         $t2, $t2, 0x40
    ctx->r10 = ctx->r10 | 0X40;
    // 0x80069CC0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80069CC4: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80069CC8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80069CCC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80069CD0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80069CD4: lw          $t5, 0x1308($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1308);
    // 0x80069CD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80069CDC: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80069CE0: jr          $ra
    // 0x80069CE4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    return;
    // 0x80069CE4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80069CE8:
    // 0x80069CE8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80069CEC: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80069CF0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80069CF4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80069CF8: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x80069CFC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80069D00: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80069D04: jr          $ra
    // 0x80069D08: nop

    return;
    // 0x80069D08: nop

;}
RECOMP_FUNC void obj_init_hittester(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800381CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800381D0: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x800381D4: addiu       $t6, $zero, 0x81
    ctx->r14 = ADD32(0, 0X81);
    // 0x800381D8: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800381DC: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x800381E0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800381E4: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800381E8: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x800381EC: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800381F0: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x800381F4: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x800381F8: jr          $ra
    // 0x800381FC: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x800381FC: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void cheatlist_exclusive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ADB0: and         $t6, $a0, $a1
    ctx->r14 = ctx->r4 & ctx->r5;
    // 0x8008ADB4: beq         $t6, $zero, L_8008ADD8
    if (ctx->r14 == 0) {
        // 0x8008ADB8: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8008ADD8;
    }
    // 0x8008ADB8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008ADBC: addiu       $v1, $v1, 0x318
    ctx->r3 = ADD32(ctx->r3, 0X318);
    // 0x8008ADC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008ADC4: nor         $t8, $a2, $zero
    ctx->r24 = ~(ctx->r6 | 0);
    // 0x8008ADC8: and         $t7, $a0, $v0
    ctx->r15 = ctx->r4 & ctx->r2;
    // 0x8008ADCC: beq         $t7, $zero, L_8008ADD8
    if (ctx->r15 == 0) {
        // 0x8008ADD0: and         $t9, $v0, $t8
        ctx->r25 = ctx->r2 & ctx->r24;
            goto L_8008ADD8;
    }
    // 0x8008ADD0: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x8008ADD4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8008ADD8:
    // 0x8008ADD8: jr          $ra
    // 0x8008ADDC: nop

    return;
    // 0x8008ADDC: nop

;}
RECOMP_FUNC void func_8002C71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C75C: lh          $t6, 0x20($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X20);
    // 0x8002C760: addiu       $t0, $zero, -0x2710
    ctx->r8 = ADD32(0, -0X2710);
    // 0x8002C764: sh          $t0, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r8;
    // 0x8002C768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002C76C: blez        $t6, L_8002C7FC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002C770: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002C7FC;
    }
    // 0x8002C770: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002C774: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C778: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
L_8002C77C:
    // 0x8002C77C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8002C780: nop

    // 0x8002C784: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C788: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8002C78C: nop

    // 0x8002C790: andi        $t2, $t9, 0x2000
    ctx->r10 = ctx->r25 & 0X2000;
    // 0x8002C794: beq         $t2, $zero, L_8002C7E8
    if (ctx->r10 == 0) {
        // 0x8002C798: nop
    
            goto L_8002C7E8;
    }
    // 0x8002C798: nop

    // 0x8002C79C: lw          $t3, 0x34($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X34);
    // 0x8002C7A0: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8002C7A4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8002C7A8: sh          $v1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r3;
    // 0x8002C7AC: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8002C7B0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8002C7B4: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C7B8: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x8002C7BC: lh          $a3, 0x38($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X38);
    // 0x8002C7C0: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002C7C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002C7C8: mflo        $t2
    ctx->r10 = lo;
    // 0x8002C7CC: addu        $t3, $t6, $t2
    ctx->r11 = ADD32(ctx->r14, ctx->r10);
    // 0x8002C7D0: lh          $a2, 0x2($t3)
    ctx->r6 = MEM_H(ctx->r11, 0X2);
    // 0x8002C7D4: beq         $t0, $a3, L_8002C7E4
    if (ctx->r8 == ctx->r7) {
        // 0x8002C7D8: slt         $at, $a3, $a2
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8002C7E4;
    }
    // 0x8002C7D8: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002C7DC: beq         $at, $zero, L_8002C7E8
    if (ctx->r1 == 0) {
        // 0x8002C7E0: nop
    
            goto L_8002C7E8;
    }
    // 0x8002C7E0: nop

L_8002C7E4:
    // 0x8002C7E4: sh          $a2, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r6;
L_8002C7E8:
    // 0x8002C7E8: lh          $t4, 0x20($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X20);
    // 0x8002C7EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002C7F0: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002C7F4: bne         $at, $zero, L_8002C77C
    if (ctx->r1 != 0) {
        // 0x8002C7F8: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8002C77C;
    }
    // 0x8002C7F8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_8002C7FC:
    // 0x8002C7FC: jr          $ra
    // 0x8002C800: sh          $v0, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r2;
    return;
    // 0x8002C800: sh          $v0, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void emitter_change_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF694: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AF698: lw          $t6, 0x3278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3278);
    // 0x800AF69C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AF6A0: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AF6A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF6A8: bne         $at, $zero, L_800AF6B4
    if (ctx->r1 != 0) {
        // 0x800AF6AC: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800AF6B4;
    }
    // 0x800AF6AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800AF6B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800AF6B4:
    // 0x800AF6B4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AF6B8: lw          $t7, 0x3284($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3284);
    // 0x800AF6BC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AF6C0: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AF6C4: bne         $at, $zero, L_800AF6D0
    if (ctx->r1 != 0) {
        // 0x800AF6C8: nop
    
            goto L_800AF6D0;
    }
    // 0x800AF6C8: nop

    // 0x800AF6CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800AF6D0:
    // 0x800AF6D0: lw          $t8, 0x328C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X328C);
    // 0x800AF6D4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800AF6D8: lh          $t1, 0x8($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X8);
    // 0x800AF6DC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AF6E0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800AF6E4: bne         $a2, $t1, L_800AF6FC
    if (ctx->r6 != ctx->r9) {
        // 0x800AF6E8: nop
    
            goto L_800AF6FC;
    }
    // 0x800AF6E8: nop

    // 0x800AF6EC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800AF6F0: nop

    // 0x800AF6F4: beq         $v0, $t2, L_800AF734
    if (ctx->r2 == ctx->r10) {
        // 0x800AF6F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800AF734;
    }
    // 0x800AF6F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AF6FC:
    // 0x800AF6FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800AF700: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800AF704: jal         0x800B27C0
    // 0x800AF708: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    emitter_cleanup(rdram, ctx);
        goto after_0;
    // 0x800AF708: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800AF70C: lh          $t3, 0x32($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X32);
    // 0x800AF710: lh          $t4, 0x36($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X36);
    // 0x800AF714: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800AF718: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800AF71C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800AF720: lh          $a3, 0x2E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2E);
    // 0x800AF724: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800AF728: jal         0x800AF7FC
    // 0x800AF72C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    emitter_init_with_pos(rdram, ctx);
        goto after_1;
    // 0x800AF72C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_1:
    // 0x800AF730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AF734:
    // 0x800AF734: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AF738: jr          $ra
    // 0x800AF73C: nop

    return;
    // 0x800AF73C: nop

;}
RECOMP_FUNC void gzip_size_uncompressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C673C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C6740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6744: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C6748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C674C: lw          $a1, 0x3CF4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3CF4);
    // 0x800C6750: jal         0x80077190
    // 0x800C6754: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    asset_load(rdram, ctx);
        goto after_0;
    // 0x800C6754: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x800C6758: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C675C: lw          $a0, 0x3CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3CF4);
    // 0x800C6760: jal         0x800C670C
    // 0x800C6764: nop

    byteswap32(rdram, ctx);
        goto after_1;
    // 0x800C6764: nop

    after_1:
    // 0x800C6768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C676C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C6770: jr          $ra
    // 0x800C6774: nop

    return;
    // 0x800C6774: nop

;}
RECOMP_FUNC void obj_init_animcar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038800: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80038804: jr          $ra
    // 0x80038808: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80038808: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void mempool_locked_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800716B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800716BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800716C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800716C4: jal         0x8006F750
    // 0x800716C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x800716C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800716CC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800716D0: jal         0x8007182C
    // 0x800716D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_get_pool(rdram, ctx);
        goto after_1;
    // 0x800716D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800716D8: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800716DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800716E0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800716E4: lw          $a0, 0x3B08($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3B08);
    // 0x800716E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800716EC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800716F0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800716F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800716F8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_800716FC:
    // 0x800716FC: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071700: mflo        $t7
    ctx->r15 = lo;
    // 0x80071704: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x80071708: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8007170C: nop

    // 0x80071710: bne         $s0, $t8, L_80071748
    if (ctx->r16 != ctx->r24) {
        // 0x80071714: nop
    
            goto L_80071748;
    }
    // 0x80071714: nop

    // 0x80071718: lh          $v0, 0x8($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X8);
    // 0x8007171C: nop

    // 0x80071720: beq         $a3, $v0, L_80071730
    if (ctx->r7 == ctx->r2) {
        // 0x80071724: ori         $t9, $v0, 0x2
        ctx->r25 = ctx->r2 | 0X2;
            goto L_80071730;
    }
    // 0x80071724: ori         $t9, $v0, 0x2
    ctx->r25 = ctx->r2 | 0X2;
    // 0x80071728: bne         $t0, $v0, L_80071748
    if (ctx->r8 != ctx->r2) {
        // 0x8007172C: ori         $t9, $v0, 0x2
        ctx->r25 = ctx->r2 | 0X2;
            goto L_80071748;
    }
    // 0x8007172C: ori         $t9, $v0, 0x2
    ctx->r25 = ctx->r2 | 0X2;
L_80071730:
    // 0x80071730: sh          $t9, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r25;
    // 0x80071734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80071738: jal         0x8006F77C
    // 0x8007173C: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x8007173C: nop

    after_2:
    // 0x80071740: b           L_80071768
    // 0x80071744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80071768;
    // 0x80071744: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80071748:
    // 0x80071748: lh          $v1, 0xC($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XC);
    // 0x8007174C: nop

    // 0x80071750: bne         $v1, $t1, L_800716FC
    if (ctx->r3 != ctx->r9) {
        // 0x80071754: nop
    
            goto L_800716FC;
    }
    // 0x80071754: nop

    // 0x80071758: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007175C: jal         0x8006F77C
    // 0x80071760: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80071760: nop

    after_3:
    // 0x80071764: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80071768:
    // 0x80071768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007176C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071770: jr          $ra
    // 0x80071774: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80071774: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void cam_set_sprite_anim_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068748: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006874C: jr          $ra
    // 0x80068750: sw          $a0, 0x128C($at)
    MEM_W(0X128C, ctx->r1) = ctx->r4;
    return;
    // 0x80068750: sw          $a0, 0x128C($at)
    MEM_W(0X128C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void init_lpfilter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B90: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80064B94: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x80064B98: sll         $t6, $v0, 14
    ctx->r14 = S32(ctx->r2 << 14);
    // 0x80064B9C: sra         $v1, $t6, 15
    ctx->r3 = S32(SIGNED(ctx->r14) >> 15);
    // 0x80064BA0: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80064BA4: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80064BA8: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x80064BAC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80064BB0: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x80064BB4: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x80064BB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80064BBC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_80064BC0:
    // 0x80064BC0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80064BC4: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x80064BC8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80064BCC: bne         $at, $zero, L_80064BC0
    if (ctx->r1 != 0) {
        // 0x80064BD0: sh          $zero, 0x6($a2)
        MEM_H(0X6, ctx->r6) = 0;
            goto L_80064BC0;
    }
    // 0x80064BD0: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80064BD4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80064BD8: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x80064BDC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80064BE0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80064BE4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80064BE8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80064BEC: div.d       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x80064BF0: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80064BF4: sh          $v1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r3;
    // 0x80064BF8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80064BFC: beq         $at, $zero, L_80064C40
    if (ctx->r1 == 0) {
        // 0x80064C00: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80064C40;
    }
    // 0x80064C00: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_80064C04:
    // 0x80064C04: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80064C08: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80064C0C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80064C10: mul.d       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x80064C14: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80064C18: nop

    // 0x80064C1C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80064C20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80064C24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80064C28: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80064C2C: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x80064C30: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80064C34: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80064C38: bne         $at, $zero, L_80064C04
    if (ctx->r1 != 0) {
        // 0x80064C3C: sh          $t3, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r11;
            goto L_80064C04;
    }
    // 0x80064C3C: sh          $t3, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r11;
L_80064C40:
    // 0x80064C40: jr          $ra
    // 0x80064C44: nop

    return;
    // 0x80064C44: nop

;}
RECOMP_FUNC void obj_init_bubbler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004207C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042080: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042084: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80042088: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004208C: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x80042090: lbu         $a2, 0x8($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X8);
    // 0x80042094: lbu         $a1, 0x9($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X9);
    // 0x80042098: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x8004209C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800420A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800420A4: jal         0x800AF694
    // 0x800420A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    emitter_change_settings(rdram, ctx);
        goto after_0;
    // 0x800420A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800420AC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800420B0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800420B4: lhu         $t9, 0xA($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XA);
    // 0x800420B8: nop

    // 0x800420BC: sw          $t9, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->r25;
    // 0x800420C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800420C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800420C8: jr          $ra
    // 0x800420CC: nop

    return;
    // 0x800420CC: nop

;}
RECOMP_FUNC void level_properties_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3EC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006C3F0: addiu       $t0, $t0, -0x2768
    ctx->r8 = ADD32(ctx->r8, -0X2768);
    // 0x8006C3F4: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C3F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006C3FC: addiu       $v1, $v1, 0x1748
    ctx->r3 = ADD32(ctx->r3, 0X1748);
    // 0x8006C400: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8006C404: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8006C408: sh          $a0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r4;
    // 0x8006C40C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8006C410: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x8006C414: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C418: nop

    // 0x8006C41C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8006C420: addu        $t1, $v1, $t9
    ctx->r9 = ADD32(ctx->r3, ctx->r25);
    // 0x8006C424: sh          $a1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r5;
    // 0x8006C428: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8006C42C: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x8006C430: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C434: nop

    // 0x8006C438: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x8006C43C: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8006C440: sh          $a2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r6;
    // 0x8006C444: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8006C448: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x8006C44C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C450: nop

    // 0x8006C454: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8006C458: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8006C45C: sh          $a3, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r7;
    // 0x8006C460: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8006C464: jr          $ra
    // 0x8006C468: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    return;
    // 0x8006C468: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
;}
RECOMP_FUNC void thread3_verify_stack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066070: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066074: addiu       $v0, $v0, -0x2328
    ctx->r2 = ADD32(ctx->r2, -0X2328);
    // 0x80066078: lw          $t7, 0x2004($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2004);
    // 0x8006607C: lw          $t6, 0x2000($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2000);
    // 0x80066080: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80066084: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80066088: sltiu       $at, $t9, 0x1
    ctx->r1 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x8006608C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80066090: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x80066094: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80066098: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8006609C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800660A0: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x800660A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800660A8: sw          $t8, 0x2000($v0)
    MEM_W(0X2000, ctx->r2) = ctx->r24;
    // 0x800660AC: sw          $t9, 0x2004($v0)
    MEM_W(0X2004, ctx->r2) = ctx->r25;
    // 0x800660B0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800660B4: bne         $t8, $t2, L_800660C0
    if (ctx->r24 != ctx->r10) {
        // 0x800660B8: sw          $t3, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r11;
            goto L_800660C0;
    }
    // 0x800660B8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800660BC: beq         $t9, $t3, L_800660CC
    if (ctx->r25 == ctx->r11) {
        // 0x800660C0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800660CC;
    }
L_800660C0:
    // 0x800660C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800660C4: jal         0x800CA2B4
    // 0x800660C8: addiu       $a0, $a0, 0x7460
    ctx->r4 = ADD32(ctx->r4, 0X7460);
    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800660C8: addiu       $a0, $a0, 0x7460
    ctx->r4 = ADD32(ctx->r4, 0X7460);
    after_0:
L_800660CC:
    // 0x800660CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800660D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800660D4: jr          $ra
    // 0x800660D8: nop

    return;
    // 0x800660D8: nop

;}
RECOMP_FUNC void racer_update_progress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C418: jal         0x8001BA98
    // 0x8005C41C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_checkpoint_count(rdram, ctx);
        goto after_0;
    // 0x8005C41C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005C420: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005C424: nop

    // 0x8005C428: lb          $t6, 0x192($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X192);
    // 0x8005C42C: nop

    // 0x8005C430: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8005C434: sb          $t7, 0x192($a0)
    MEM_B(0X192, ctx->r4) = ctx->r15;
    // 0x8005C438: lb          $v1, 0x192($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X192);
    // 0x8005C43C: nop

    // 0x8005C440: bgez        $v1, L_8005C460
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005C444: nop
    
            goto L_8005C460;
    }
    // 0x8005C444: nop

    // 0x8005C448: lb          $a1, 0x193($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X193);
    // 0x8005C44C: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x8005C450: blez        $a1, L_8005C460
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005C454: sb          $t8, 0x192($a0)
        MEM_B(0X192, ctx->r4) = ctx->r24;
            goto L_8005C460;
    }
    // 0x8005C454: sb          $t8, 0x192($a0)
    MEM_B(0X192, ctx->r4) = ctx->r24;
    // 0x8005C458: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x8005C45C: sb          $t9, 0x193($a0)
    MEM_B(0X193, ctx->r4) = ctx->r25;
L_8005C460:
    // 0x8005C460: lh          $v0, 0x190($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X190);
    // 0x8005C464: nop

    // 0x8005C468: slti        $at, $v0, -0x7CFF
    ctx->r1 = SIGNED(ctx->r2) < -0X7CFF ? 1 : 0;
    // 0x8005C46C: bne         $at, $zero, L_8005C478
    if (ctx->r1 != 0) {
        // 0x8005C470: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8005C478;
    }
    // 0x8005C470: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8005C474: sh          $t0, 0x190($a0)
    MEM_H(0X190, ctx->r4) = ctx->r8;
L_8005C478:
    // 0x8005C478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C47C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C480: jr          $ra
    // 0x8005C484: nop

    return;
    // 0x8005C484: nop

;}
RECOMP_FUNC void alFilterNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA610: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800CA614: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800CA618: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800CA61C: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x800CA620: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x800CA624: jr          $ra
    // 0x800CA628: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    return;
    // 0x800CA628: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void hud_main_time_trial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2CBC: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800A2CC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A2CC4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A2CC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A2CCC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A2CD0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A2CD4: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800A2CD8: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x800A2CDC: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x800A2CE0: lw          $t7, 0x64($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X64);
    // 0x800A2CE4: addiu       $s0, $s0, 0x72B4
    ctx->r16 = ADD32(ctx->r16, 0X72B4);
    // 0x800A2CE8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A2CEC: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x800A2CF0: lw          $t8, 0x50($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X50);
    // 0x800A2CF4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800A2CF8: bne         $t8, $zero, L_800A2D74
    if (ctx->r24 != 0) {
        // 0x800A2CFC: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A2D74;
    }
    // 0x800A2CFC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A2D00: lw          $t9, 0x72B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72B0);
    // 0x800A2D04: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800A2D08: lh          $t3, 0x28($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X28);
    // 0x800A2D0C: sb          $t4, 0x91($sp)
    MEM_B(0X91, ctx->r29) = ctx->r12;
    // 0x800A2D10: sh          $zero, 0x92($sp)
    MEM_H(0X92, ctx->r29) = 0;
    // 0x800A2D14: sh          $zero, 0x94($sp)
    MEM_H(0X94, ctx->r29) = 0;
    // 0x800A2D18: sh          $zero, 0x96($sp)
    MEM_H(0X96, ctx->r29) = 0;
    // 0x800A2D1C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A2D20: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x800A2D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2D28: jal         0x8000EA54
    // 0x800A2D2C: sb          $t3, 0x90($sp)
    MEM_B(0X90, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x800A2D2C: sb          $t3, 0x90($sp)
    MEM_B(0X90, ctx->r29) = ctx->r11;
    after_0:
    // 0x800A2D30: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A2D34: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2D38: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A2D3C: addiu       $s1, $s1, 0x729C
    ctx->r17 = ADD32(ctx->r17, 0X729C);
    // 0x800A2D40: sw          $v0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r2;
    // 0x800A2D44: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800A2D48: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x800A2D4C: sh          $t6, 0x340($t7)
    MEM_H(0X340, ctx->r15) = ctx->r14;
    // 0x800A2D50: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A2D54: nop

    // 0x800A2D58: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x800A2D5C: nop

    // 0x800A2D60: beq         $a0, $zero, L_800A2D74
    if (ctx->r4 == 0) {
        // 0x800A2D64: nop
    
            goto L_800A2D74;
    }
    // 0x800A2D64: nop

    // 0x800A2D68: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x800A2D6C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A2D70: nop

L_800A2D74:
    // 0x800A2D74: lw          $t8, 0x88($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X88);
    // 0x800A2D78: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A2D7C: bne         $t8, $zero, L_800A2DD8
    if (ctx->r24 != 0) {
        // 0x800A2D80: addiu       $s1, $s1, 0x729C
        ctx->r17 = ADD32(ctx->r17, 0X729C);
            goto L_800A2DD8;
    }
    // 0x800A2D80: addiu       $s1, $s1, 0x729C
    ctx->r17 = ADD32(ctx->r17, 0X729C);
    // 0x800A2D84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A2D88: lw          $t9, 0x72B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72B0);
    // 0x800A2D8C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800A2D90: lh          $t3, 0x44($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X44);
    // 0x800A2D94: sb          $t4, 0x89($sp)
    MEM_B(0X89, ctx->r29) = ctx->r12;
    // 0x800A2D98: sh          $zero, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = 0;
    // 0x800A2D9C: sh          $zero, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = 0;
    // 0x800A2DA0: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x800A2DA4: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A2DA8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x800A2DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2DB0: jal         0x8000EA54
    // 0x800A2DB4: sb          $t3, 0x88($sp)
    MEM_B(0X88, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_1;
    // 0x800A2DB4: sb          $t3, 0x88($sp)
    MEM_B(0X88, ctx->r29) = ctx->r11;
    after_1:
    // 0x800A2DB8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A2DBC: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2DC0: sw          $v0, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->r2;
    // 0x800A2DC4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800A2DC8: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x800A2DCC: sh          $t6, 0x440($t7)
    MEM_H(0X440, ctx->r15) = ctx->r14;
    // 0x800A2DD0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800A2DD4: nop

L_800A2DD8:
    // 0x800A2DD8: lw          $s0, 0x50($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X50);
    // 0x800A2DDC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A2DE0: beq         $s0, $zero, L_800A3BFC
    if (ctx->r16 == 0) {
        // 0x800A2DE4: addiu       $s2, $s2, 0x7327
        ctx->r18 = ADD32(ctx->r18, 0X7327);
            goto L_800A3BFC;
    }
    // 0x800A2DE4: addiu       $s2, $s2, 0x7327
    ctx->r18 = ADD32(ctx->r18, 0X7327);
    // 0x800A2DE8: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2DEC: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x800A2DF0: sb          $t8, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r24;
    // 0x800A2DF4: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x800A2DF8: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800A2DFC: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800A2E00: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800A2E04: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800A2E08: sh          $t3, 0x52($t5)
    MEM_H(0X52, ctx->r13) = ctx->r11;
    // 0x800A2E0C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2E10: nop

    // 0x800A2E14: beq         $v0, $at, L_800A30A8
    if (ctx->r2 == ctx->r1) {
        // 0x800A2E18: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A30A8;
    }
    // 0x800A2E18: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A2E1C: bne         $v0, $at, L_800A2E54
    if (ctx->r2 != ctx->r1) {
        // 0x800A2E20: nop
    
            goto L_800A2E54;
    }
    // 0x800A2E20: nop

    // 0x800A2E24: jal         0x8001139C
    // 0x800A2E28: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    get_race_countdown(rdram, ctx);
        goto after_2;
    // 0x800A2E28: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_2:
    // 0x800A2E2C: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2E30: bne         $v0, $zero, L_800A2E4C
    if (ctx->r2 != 0) {
        // 0x800A2E34: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_800A2E4C;
    }
    // 0x800A2E34: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800A2E38: jal         0x800015C8
    // 0x800A2E3C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    music_is_playing(rdram, ctx);
        goto after_3;
    // 0x800A2E3C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_3:
    // 0x800A2E40: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2E44: bne         $v0, $zero, L_800A2E54
    if (ctx->r2 != 0) {
        // 0x800A2E48: addiu       $t6, $zero, 0x10
        ctx->r14 = ADD32(0, 0X10);
            goto L_800A2E54;
    }
    // 0x800A2E48: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
L_800A2E4C:
    // 0x800A2E4C: b           L_800A3094
    // 0x800A2E50: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
        goto L_800A3094;
    // 0x800A2E50: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
L_800A2E54:
    // 0x800A2E54: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2E58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A2E5C: bne         $t7, $at, L_800A2F68
    if (ctx->r15 != ctx->r1) {
        // 0x800A2E60: nop
    
            goto L_800A2F68;
    }
    // 0x800A2E60: nop

    // 0x800A2E64: jal         0x800015F8
    // 0x800A2E68: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    music_animation_fraction(rdram, ctx);
        goto after_4;
    // 0x800A2E68: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_4:
    // 0x800A2E6C: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800A2E70: lbu         $t4, 0x0($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2E74: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800A2E78: sll         $t3, $t4, 3
    ctx->r11 = S32(ctx->r12 << 3);
    // 0x800A2E7C: lw          $t2, 0x44($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X44);
    // 0x800A2E80: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800A2E84: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x800A2E88: lw          $v0, 0x4($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X4);
    // 0x800A2E8C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A2E90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A2E94: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x800A2E98: c.eq.d      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.d == ctx->f12.d;
    // 0x800A2E9C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800A2EA0: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2EA4: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800A2EA8: bc1f        L_800A2EB8
    if (!c1cs) {
        // 0x800A2EAC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800A2EB8;
    }
    // 0x800A2EAC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800A2EB0: b           L_800A3094
    // 0x800A2EB4: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
        goto L_800A3094;
    // 0x800A2EB4: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
L_800A2EB8:
    // 0x800A2EB8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A2EBC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800A2EC0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A2EC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A2EC8: c.lt.d      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.d < ctx->f12.d;
    // 0x800A2ECC: nop

    // 0x800A2ED0: bc1f        L_800A2F28
    if (!c1cs) {
        // 0x800A2ED4: nop
    
            goto L_800A2F28;
    }
    // 0x800A2ED4: nop

    // 0x800A2ED8: sub.d       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f12.d - ctx->f18.d;
    // 0x800A2EDC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800A2EE0: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x800A2EE4: cvt.d.s     $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.d = CVT_D_S(ctx->f14.fl);
    // 0x800A2EE8: add.d       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f2.d + ctx->f2.d;
    // 0x800A2EEC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A2EF0: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x800A2EF4: mul.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800A2EF8: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800A2EFC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A2F00: nop

    // 0x800A2F04: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A2F08: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2F0C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2F10: nop

    // 0x800A2F14: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A2F18: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A2F1C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A2F20: b           L_800A3094
    // 0x800A2F24: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
        goto L_800A3094;
    // 0x800A2F24: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
L_800A2F28:
    // 0x800A2F28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A2F2C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A2F30: mul.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800A2F34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A2F38: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800A2F3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A2F40: nop

    // 0x800A2F44: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A2F48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2F4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2F50: nop

    // 0x800A2F54: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A2F58: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800A2F5C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A2F60: b           L_800A3094
    // 0x800A2F64: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
        goto L_800A3094;
    // 0x800A2F64: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
L_800A2F68:
    // 0x800A2F68: jal         0x8006ECE0
    // 0x800A2F6C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    is_game_paused(rdram, ctx);
        goto after_5;
    // 0x800A2F6C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_5:
    // 0x800A2F70: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A2F74: bne         $v0, $zero, L_800A3094
    if (ctx->r2 != 0) {
        // 0x800A2F78: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A3094;
    }
    // 0x800A2F78: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2F7C: addiu       $a1, $a1, 0x7329
    ctx->r5 = ADD32(ctx->r5, 0X7329);
    // 0x800A2F80: lb          $v0, 0x0($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X0);
    // 0x800A2F84: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800A2F88: bgez        $v0, L_800A2FD4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A2F8C: nop
    
            goto L_800A2FD4;
    }
    // 0x800A2F8C: nop

    // 0x800A2F90: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x800A2F94: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    // 0x800A2F98: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A2F9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A2FA0: mflo        $v1
    ctx->r3 = lo;
    // 0x800A2FA4: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x800A2FA8: slt         $at, $t3, $a0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A2FAC: beq         $at, $zero, L_800A2FBC
    if (ctx->r1 == 0) {
        // 0x800A2FB0: addu        $t5, $a0, $v1
        ctx->r13 = ADD32(ctx->r4, ctx->r3);
            goto L_800A2FBC;
    }
    // 0x800A2FB0: addu        $t5, $a0, $v1
    ctx->r13 = ADD32(ctx->r4, ctx->r3);
    // 0x800A2FB4: b           L_800A3094
    // 0x800A2FB8: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
        goto L_800A3094;
    // 0x800A2FB8: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
L_800A2FBC:
    // 0x800A2FBC: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
    // 0x800A2FC0: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x800A2FC4: nop

    // 0x800A2FC8: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800A2FCC: b           L_800A3094
    // 0x800A2FD0: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
        goto L_800A3094;
    // 0x800A2FD0: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
L_800A2FD4:
    // 0x800A2FD4: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A2FD8: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x800A2FDC: mflo        $t2
    ctx->r10 = lo;
    // 0x800A2FE0: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800A2FE4: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
    // 0x800A2FE8: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x800A2FEC: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800A2FF0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800A2FF4: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x800A2FF8: lw          $t7, 0x44($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X44);
    // 0x800A2FFC: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x800A3000: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x800A3004: lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X4);
    // 0x800A3008: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A300C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800A3010: sll         $t2, $v1, 4
    ctx->r10 = S32(ctx->r3 << 4);
    // 0x800A3014: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A3018: bne         $at, $zero, L_800A3098
    if (ctx->r1 != 0) {
        // 0x800A301C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3098;
    }
    // 0x800A301C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3020: lbu         $t5, 0x7328($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7328);
    // 0x800A3024: nop

    // 0x800A3028: beq         $t5, $zero, L_800A3048
    if (ctx->r13 == 0) {
        // 0x800A302C: nop
    
            goto L_800A3048;
    }
    // 0x800A302C: nop

    // 0x800A3030: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x800A3034: addiu       $t7, $t2, -0x1
    ctx->r15 = ADD32(ctx->r10, -0X1);
    // 0x800A3038: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x800A303C: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x800A3040: b           L_800A3094
    // 0x800A3044: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
        goto L_800A3094;
    // 0x800A3044: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
L_800A3048:
    // 0x800A3048: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800A304C: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3050: nop

    // 0x800A3054: lbu         $t9, 0x1FC($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X1FC);
    // 0x800A3058: nop

    // 0x800A305C: bne         $t9, $zero, L_800A3098
    if (ctx->r25 != 0) {
        // 0x800A3060: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A3098;
    }
    // 0x800A3060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3064: lb          $t2, 0x1D8($t4)
    ctx->r10 = MEM_B(ctx->r12, 0X1D8);
    // 0x800A3068: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A306C: bne         $t2, $zero, L_800A3094
    if (ctx->r10 != 0) {
        // 0x800A3070: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A3094;
    }
    // 0x800A3070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A3074: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A3078: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A307C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800A3080: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800A3084: jal         0x800A3C14
    // 0x800A3088: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    hud_stopwatch_face(rdram, ctx);
        goto after_6;
    // 0x800A3088: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_6:
    // 0x800A308C: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A3090: nop

L_800A3094:
    // 0x800A3094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A3098:
    // 0x800A3098: jal         0x80061F70
    // 0x800A309C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    obj_animate(rdram, ctx);
        goto after_7;
    // 0x800A309C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_7:
    // 0x800A30A0: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A30A4: nop

L_800A30A8:
    // 0x800A30A8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A30AC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A30B0: addiu       $s2, $s2, 0x72BC
    ctx->r18 = ADD32(ctx->r18, 0X72BC);
    // 0x800A30B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A30B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A30BC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A30C0: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A30C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A30C8: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A30CC: jal         0x800AAB5C
    // 0x800A30D0: addiu       $a3, $a3, 0x340
    ctx->r7 = ADD32(ctx->r7, 0X340);
    hud_element_render(rdram, ctx);
        goto after_8;
    // 0x800A30D0: addiu       $a3, $a3, 0x340
    ctx->r7 = ADD32(ctx->r7, 0X340);
    after_8:
    // 0x800A30D4: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x800A30D8: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A30DC: lb          $v1, 0x193($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X193);
    // 0x800A30E0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A30E4: bltz        $v1, L_800A3118
    if (SIGNED(ctx->r3) < 0) {
        // 0x800A30E8: lui         $t8, 0x8000
        ctx->r24 = S32(0X8000 << 16);
            goto L_800A3118;
    }
    // 0x800A30E8: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800A30EC: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800A30F0: addu        $s0, $a1, $t5
    ctx->r16 = ADD32(ctx->r5, ctx->r13);
    // 0x800A30F4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800A30F8:
    // 0x800A30F8: lw          $t6, 0x128($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X128);
    // 0x800A30FC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800A3100: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800A3104: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A3108: bne         $at, $zero, L_800A3118
    if (ctx->r1 != 0) {
        // 0x800A310C: addu        $t1, $t1, $t6
        ctx->r9 = ADD32(ctx->r9, ctx->r14);
            goto L_800A3118;
    }
    // 0x800A310C: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x800A3110: bne         $t0, $v0, L_800A30F8
    if (ctx->r8 != ctx->r2) {
        // 0x800A3114: nop
    
            goto L_800A30F8;
    }
    // 0x800A3114: nop

L_800A3118:
    // 0x800A3118: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800A311C: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A3120: bne         $t8, $zero, L_800A316C
    if (ctx->r24 != 0) {
        // 0x800A3124: nop
    
            goto L_800A316C;
    }
    // 0x800A3124: nop

    // 0x800A3128: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800A312C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A3130: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A3134: lwc1        $f11, -0x7348($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X7348);
    // 0x800A3138: lwc1        $f10, -0x7344($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7344);
    // 0x800A313C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A3140: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800A3144: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A3148: nop

    // 0x800A314C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A3150: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A3154: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A3158: nop

    // 0x800A315C: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800A3160: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A3164: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800A3168: nop

L_800A316C:
    // 0x800A316C: jal         0x8000C8B4
    // 0x800A3170: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_9;
    // 0x800A3170: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_9:
    // 0x800A3174: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A3178: nop

    // 0x800A317C: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A3180: beq         $at, $zero, L_800A3198
    if (ctx->r1 == 0) {
        // 0x800A3184: addiu       $s0, $zero, 0x444
        ctx->r16 = ADD32(0, 0X444);
            goto L_800A3198;
    }
    // 0x800A3184: addiu       $s0, $zero, 0x444
    ctx->r16 = ADD32(0, 0X444);
    // 0x800A3188: jal         0x8000C8B4
    // 0x800A318C: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    normalise_time(rdram, ctx);
        goto after_10;
    // 0x800A318C: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    after_10:
    // 0x800A3190: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800A3194: addiu       $s0, $zero, 0x444
    ctx->r16 = ADD32(0, 0X444);
L_800A3198:
    // 0x800A3198: multu       $t1, $s0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A319C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800A31A0: mflo        $t9
    ctx->r25 = lo;
    // 0x800A31A4: addiu       $t4, $t9, 0x7FF8
    ctx->r12 = ADD32(ctx->r25, 0X7FF8);
    // 0x800A31A8: sh          $t4, 0x444($t2)
    MEM_H(0X444, ctx->r10) = ctx->r12;
    // 0x800A31AC: jal         0x8000E0B0
    // 0x800A31B0: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    get_contpak_error(rdram, ctx);
        goto after_11;
    // 0x800A31B0: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    after_11:
    // 0x800A31B4: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A31B8: bgtz        $v0, L_800A31F0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800A31BC: addiu       $v1, $zero, 0x3C
        ctx->r3 = ADD32(0, 0X3C);
            goto L_800A31F0;
    }
    // 0x800A31BC: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x800A31C0: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A31C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A31C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A31CC: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A31D0: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A31D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A31D8: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x800A31DC: jal         0x800AAB5C
    // 0x800A31E0: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A31E0: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    after_12:
    // 0x800A31E4: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800A31E8: nop

    // 0x800A31EC: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_800A31F0:
    // 0x800A31F0: div         $zero, $t1, $v1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r3)));
    // 0x800A31F4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800A31F8: bne         $v1, $zero, L_800A3204
    if (ctx->r3 != 0) {
        // 0x800A31FC: nop
    
            goto L_800A3204;
    }
    // 0x800A31FC: nop

    // 0x800A3200: break       7
    do_break(2148151808);
L_800A3204:
    // 0x800A3204: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A3208: bne         $v1, $at, L_800A321C
    if (ctx->r3 != ctx->r1) {
        // 0x800A320C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A321C;
    }
    // 0x800A320C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A3210: bne         $t1, $at, L_800A321C
    if (ctx->r9 != ctx->r1) {
        // 0x800A3214: nop
    
            goto L_800A321C;
    }
    // 0x800A3214: nop

    // 0x800A3218: break       6
    do_break(2148151832);
L_800A321C:
    // 0x800A321C: mflo        $t3
    ctx->r11 = lo;
    // 0x800A3220: addiu       $t5, $t3, 0x1E
    ctx->r13 = ADD32(ctx->r11, 0X1E);
    // 0x800A3224: nop

    // 0x800A3228: div         $zero, $t5, $v1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r3)));
    // 0x800A322C: bne         $v1, $zero, L_800A3238
    if (ctx->r3 != 0) {
        // 0x800A3230: nop
    
            goto L_800A3238;
    }
    // 0x800A3230: nop

    // 0x800A3234: break       7
    do_break(2148151860);
L_800A3238:
    // 0x800A3238: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A323C: bne         $v1, $at, L_800A3250
    if (ctx->r3 != ctx->r1) {
        // 0x800A3240: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A3250;
    }
    // 0x800A3240: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A3244: bne         $t5, $at, L_800A3250
    if (ctx->r13 != ctx->r1) {
        // 0x800A3248: nop
    
            goto L_800A3250;
    }
    // 0x800A3248: nop

    // 0x800A324C: break       6
    do_break(2148151884);
L_800A3250:
    // 0x800A3250: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800A3254: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A3258: mfhi        $t1
    ctx->r9 = hi;
    // 0x800A325C: nop

    // 0x800A3260: nop

    // 0x800A3264: multu       $t1, $s0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A3268: mflo        $t6
    ctx->r14 = lo;
    // 0x800A326C: sh          $t6, 0x444($t8)
    MEM_H(0X444, ctx->r24) = ctx->r14;
    // 0x800A3270: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A3274: nop

    // 0x800A3278: lwc1        $f8, 0x350($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X350);
    // 0x800A327C: nop

    // 0x800A3280: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A3284: jal         0x8000E0B0
    // 0x800A3288: swc1        $f4, 0x450($v0)
    MEM_W(0X450, ctx->r2) = ctx->f4.u32l;
    get_contpak_error(rdram, ctx);
        goto after_13;
    // 0x800A3288: swc1        $f4, 0x450($v0)
    MEM_W(0X450, ctx->r2) = ctx->f4.u32l;
    after_13:
    // 0x800A328C: bgtz        $v0, L_800A32B8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800A3290: lw          $t7, 0x98($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X98);
            goto L_800A32B8;
    }
    // 0x800A3290: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x800A3294: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A3298: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A329C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A32A0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A32A4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A32A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A32AC: jal         0x800AAB5C
    // 0x800A32B0: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    hud_element_render(rdram, ctx);
        goto after_14;
    // 0x800A32B0: addiu       $a3, $a3, 0x440
    ctx->r7 = ADD32(ctx->r7, 0X440);
    after_14:
    // 0x800A32B4: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
L_800A32B8:
    // 0x800A32B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A32BC: jal         0x80068748
    // 0x800A32C0: sb          $zero, 0x20($t7)
    MEM_B(0X20, ctx->r15) = 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_15;
    // 0x800A32C0: sb          $zero, 0x20($t7)
    MEM_B(0X20, ctx->r15) = 0;
    after_15:
    // 0x800A32C4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A32C8: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A32CC: jal         0x800A13F4
    // 0x800A32D0: nop

    hud_course_arrows(rdram, ctx);
        goto after_16;
    // 0x800A32D0: nop

    after_16:
    // 0x800A32D4: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A32D8: nop

    // 0x800A32DC: lb          $t9, 0x1D8($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A32E0: nop

    // 0x800A32E4: bne         $t9, $zero, L_800A3618
    if (ctx->r25 != 0) {
        // 0x800A32E8: nop
    
            goto L_800A3618;
    }
    // 0x800A32E8: nop

    // 0x800A32EC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A32F0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800A32F4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A32F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A32FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A3300: lwc1        $f6, 0x2F0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X2F0);
    // 0x800A3304: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A3308: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A330C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A3310: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800A3314: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A3318: sw          $t3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r11;
    // 0x800A331C: lb          $t5, 0x194($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X194);
    // 0x800A3320: nop

    // 0x800A3324: blez        $t5, L_800A34C4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A3328: sll         $t5, $t0, 2
        ctx->r13 = S32(ctx->r8 << 2);
            goto L_800A34C4;
    }
    // 0x800A3328: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800A332C: lw          $t6, 0x7320($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7320);
    // 0x800A3330: sll         $v0, $zero, 2
    ctx->r2 = S32(0 << 2);
    // 0x800A3334: lb          $t8, 0x4B($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X4B);
    // 0x800A3338: addu        $s0, $t1, $v0
    ctx->r16 = ADD32(ctx->r9, ctx->r2);
    // 0x800A333C: blez        $t8, L_800A34C0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800A3340: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800A34C0;
    }
    // 0x800A3340: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800A3344: addiu       $t7, $t7, 0x2D2C
    ctx->r15 = ADD32(ctx->r15, 0X2D2C);
    // 0x800A3348: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x800A334C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_800A3350:
    // 0x800A3350: lw          $a0, 0x128($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X128);
    // 0x800A3354: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x800A3358: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800A335C: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x800A3360: jal         0x800597E0
    // 0x800A3364: addiu       $a3, $sp, 0xAC
    ctx->r7 = ADD32(ctx->r29, 0XAC);
    get_timestamp_from_frames(rdram, ctx);
        goto after_17;
    // 0x800A3364: addiu       $a3, $sp, 0xAC
    ctx->r7 = ADD32(ctx->r29, 0XAC);
    after_17:
    // 0x800A3368: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800A336C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A3370: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x800A3374: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A3378: sw          $t2, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r10;
    // 0x800A337C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800A3380: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A3384: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A3388: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A338C: lwc1        $f10, 0x2EC($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X2EC);
    // 0x800A3390: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800A3394: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A3398: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x800A339C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800A33A0: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x800A33A4: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    // 0x800A33A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A33AC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A33B0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A33B4: jal         0x800A8518
    // 0x800A33B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    hud_timer_render(rdram, ctx);
        goto after_18;
    // 0x800A33B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_18:
    // 0x800A33BC: addiu       $t7, $zero, -0x2
    ctx->r15 = ADD32(0, -0X2);
    // 0x800A33C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A33C4: sw          $t7, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r15;
    // 0x800A33C8: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x800A33CC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800A33D0: addiu       $t4, $t9, 0xC
    ctx->r12 = ADD32(ctx->r25, 0XC);
    // 0x800A33D4: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800A33D8: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x800A33DC: sw          $t4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r12;
    // 0x800A33E0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800A33E4: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A33E8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A33EC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800A33F0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800A33F4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800A33F8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800A33FC: sh          $t1, 0x338($t6)
    MEM_H(0X338, ctx->r14) = ctx->r9;
    // 0x800A3400: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A3404: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3408: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A340C: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A3410: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A3414: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x800A3418: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A341C: jal         0x800AAB5C
    // 0x800A3420: addiu       $a3, $a3, 0x320
    ctx->r7 = ADD32(ctx->r7, 0X320);
    hud_element_render(rdram, ctx);
        goto after_19;
    // 0x800A3420: addiu       $a3, $a3, 0x320
    ctx->r7 = ADD32(ctx->r7, 0X320);
    after_19:
    // 0x800A3424: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800A3428: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A342C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3430: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A3434: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A3438: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A343C: jal         0x800AAB5C
    // 0x800A3440: addiu       $a3, $a3, 0x300
    ctx->r7 = ADD32(ctx->r7, 0X300);
    hud_element_render(rdram, ctx);
        goto after_20;
    // 0x800A3440: addiu       $a3, $a3, 0x300
    ctx->r7 = ADD32(ctx->r7, 0X300);
    after_20:
    // 0x800A3444: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A3448: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800A344C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A3450: lwc1        $f6, 0x330($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X330);
    // 0x800A3454: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A3458: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A345C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A3460: swc1        $f8, 0x330($v0)
    MEM_W(0X330, ctx->r2) = ctx->f8.u32l;
    // 0x800A3464: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A3468: nop

    // 0x800A346C: lwc1        $f10, 0x310($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X310);
    // 0x800A3470: nop

    // 0x800A3474: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A3478: swc1        $f4, 0x310($v0)
    MEM_W(0X310, ctx->r2) = ctx->f4.u32l;
    // 0x800A347C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800A3480: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3484: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x800A3488: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800A348C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800A3490: lb          $t4, 0x194($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X194);
    // 0x800A3494: nop

    // 0x800A3498: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800A349C: beq         $at, $zero, L_800A34C4
    if (ctx->r1 == 0) {
        // 0x800A34A0: sll         $t5, $t0, 2
        ctx->r13 = S32(ctx->r8 << 2);
            goto L_800A34C4;
    }
    // 0x800A34A0: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800A34A4: lw          $t2, 0x7320($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7320);
    // 0x800A34A8: nop

    // 0x800A34AC: lb          $t3, 0x4B($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X4B);
    // 0x800A34B0: nop

    // 0x800A34B4: slt         $at, $t0, $t3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800A34B8: bne         $at, $zero, L_800A3350
    if (ctx->r1 != 0) {
        // 0x800A34BC: nop
    
            goto L_800A3350;
    }
    // 0x800A34BC: nop

L_800A34C0:
    // 0x800A34C0: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
L_800A34C4:
    // 0x800A34C4: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800A34C8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A34CC: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800A34D0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A34D4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A34D8: lwc1        $f8, 0x330($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X330);
    // 0x800A34DC: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A34E0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A34E4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A34E8: swc1        $f10, 0x330($v0)
    MEM_W(0X330, ctx->r2) = ctx->f10.u32l;
    // 0x800A34EC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800A34F0: addiu       $s0, $s0, 0x730C
    ctx->r16 = ADD32(ctx->r16, 0X730C);
    // 0x800A34F4: lwc1        $f4, 0x310($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X310);
    // 0x800A34F8: nop

    // 0x800A34FC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A3500: swc1        $f6, 0x310($v0)
    MEM_W(0X310, ctx->r2) = ctx->f6.u32l;
    // 0x800A3504: lbu         $t6, 0x1EF($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X1EF);
    // 0x800A3508: nop

    // 0x800A350C: andi        $t8, $t6, 0x4
    ctx->r24 = ctx->r14 & 0X4;
    // 0x800A3510: beq         $t8, $zero, L_800A3554
    if (ctx->r24 == 0) {
        // 0x800A3514: nop
    
            goto L_800A3554;
    }
    // 0x800A3514: nop

    // 0x800A3518: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A351C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800A3520: bgtz        $t7, L_800A3554
    if (SIGNED(ctx->r15) > 0) {
        // 0x800A3524: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_800A3554;
    }
    // 0x800A3524: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A3528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A352C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800A3530: jal         0x800A3C14
    // 0x800A3534: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_21;
    // 0x800A3534: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_21:
    // 0x800A3538: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A353C: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x800A3540: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800A3544: lbu         $t2, 0x1EF($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1EF);
    // 0x800A3548: nop

    // 0x800A354C: andi        $t3, $t2, 0xFFFB
    ctx->r11 = ctx->r10 & 0XFFFB;
    // 0x800A3550: sb          $t3, 0x1EF($t1)
    MEM_B(0X1EF, ctx->r9) = ctx->r11;
L_800A3554:
    // 0x800A3554: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A3558: addiu       $s0, $s0, 0x730C
    ctx->r16 = ADD32(ctx->r16, 0X730C);
    // 0x800A355C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A3560: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3564: blez        $v0, L_800A3580
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A3568: subu        $t6, $v0, $t5
        ctx->r14 = SUB32(ctx->r2, ctx->r13);
            goto L_800A3580;
    }
    // 0x800A3568: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x800A356C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800A3570: bgez        $t6, L_800A3580
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800A3574: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800A3580;
    }
    // 0x800A3574: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800A3578: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800A357C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A3580:
    // 0x800A3580: bne         $v0, $zero, L_800A3618
    if (ctx->r2 != 0) {
        // 0x800A3584: nop
    
            goto L_800A3618;
    }
    // 0x800A3584: nop

    // 0x800A3588: lb          $t8, 0x1D8($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A358C: addiu       $t7, $zero, -0x64
    ctx->r15 = ADD32(0, -0X64);
    // 0x800A3590: bne         $t8, $zero, L_800A3618
    if (ctx->r24 != 0) {
        // 0x800A3594: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A3618;
    }
    // 0x800A3594: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A3598: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800A359C: lw          $t9, 0x7300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7300);
    // 0x800A35A0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A35A4: bne         $t9, $zero, L_800A3618
    if (ctx->r25 != 0) {
        // 0x800A35A8: addiu       $s0, $s0, 0x7324
        ctx->r16 = ADD32(ctx->r16, 0X7324);
            goto L_800A3618;
    }
    // 0x800A35A8: addiu       $s0, $s0, 0x7324
    ctx->r16 = ADD32(ctx->r16, 0X7324);
    // 0x800A35AC: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x800A35B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A35B4: jal         0x8006FB8C
    // 0x800A35B8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    rand_range(rdram, ctx);
        goto after_22;
    // 0x800A35B8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_22:
    // 0x800A35BC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A35C0: addiu       $s1, $s1, 0x7308
    ctx->r17 = ADD32(ctx->r17, 0X7308);
    // 0x800A35C4: lhu         $t2, 0x0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X0);
    // 0x800A35C8: addiu       $v1, $v0, 0x14B
    ctx->r3 = ADD32(ctx->r2, 0X14B);
    // 0x800A35CC: andi        $t3, $v1, 0xFFFF
    ctx->r11 = ctx->r3 & 0XFFFF;
    // 0x800A35D0: bne         $t2, $t3, L_800A35FC
    if (ctx->r10 != ctx->r11) {
        // 0x800A35D4: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A35FC;
    }
    // 0x800A35D4: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A35D8:
    // 0x800A35D8: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x800A35DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A35E0: jal         0x8006FB8C
    // 0x800A35E4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    rand_range(rdram, ctx);
        goto after_23;
    // 0x800A35E4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_23:
    // 0x800A35E8: lhu         $t4, 0x0($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X0);
    // 0x800A35EC: addiu       $v1, $v0, 0x14B
    ctx->r3 = ADD32(ctx->r2, 0X14B);
    // 0x800A35F0: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x800A35F4: beq         $t4, $t5, L_800A35D8
    if (ctx->r12 == ctx->r13) {
        // 0x800A35F8: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A35D8;
    }
    // 0x800A35F8: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A35FC:
    // 0x800A35FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3600: sh          $a0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r4;
    // 0x800A3604: jal         0x80001D04
    // 0x800A3608: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_24;
    // 0x800A3608: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_24:
    // 0x800A360C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A3610: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3614: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
L_800A3618:
    // 0x800A3618: lb          $v1, 0x193($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X193);
    // 0x800A361C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A3620: blez        $v1, L_800A3728
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A3624: addiu       $s1, $s1, 0x7308
        ctx->r17 = ADD32(ctx->r17, 0X7308);
            goto L_800A3728;
    }
    // 0x800A3624: addiu       $s1, $s1, 0x7308
    ctx->r17 = ADD32(ctx->r17, 0X7308);
    // 0x800A3628: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A362C: lw          $t8, 0x7320($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7320);
    // 0x800A3630: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800A3634: lb          $t7, 0x4B($t8)
    ctx->r15 = MEM_B(ctx->r24, 0X4B);
    // 0x800A3638: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800A363C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800A3640: beq         $at, $zero, L_800A3728
    if (ctx->r1 == 0) {
        // 0x800A3644: nop
    
            goto L_800A3728;
    }
    // 0x800A3644: nop

    // 0x800A3648: lw          $t3, 0x128($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X128);
    // 0x800A364C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A3650: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x800A3654: beq         $at, $zero, L_800A3728
    if (ctx->r1 == 0) {
        // 0x800A3658: nop
    
            goto L_800A3728;
    }
    // 0x800A3658: nop

    // 0x800A365C: lw          $t4, 0x7300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7300);
    // 0x800A3660: nop

    // 0x800A3664: bne         $t4, $zero, L_800A3728
    if (ctx->r12 != 0) {
        // 0x800A3668: nop
    
            goto L_800A3728;
    }
    // 0x800A3668: nop

    // 0x800A366C: lb          $t5, 0x1D6($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X1D6);
    // 0x800A3670: nop

    // 0x800A3674: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x800A3678: beq         $at, $zero, L_800A3728
    if (ctx->r1 == 0) {
        // 0x800A367C: nop
    
            goto L_800A3728;
    }
    // 0x800A367C: nop

    // 0x800A3680: jal         0x8006ECD0
    // 0x800A3684: nop

    get_settings(rdram, ctx);
        goto after_25;
    // 0x800A3684: nop

    after_25:
    // 0x800A3688: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A368C: addiu       $s0, $s0, 0x7744
    ctx->r16 = ADD32(ctx->r16, 0X7744);
    // 0x800A3690: jal         0x8006BFC8
    // 0x800A3694: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    level_id(rdram, ctx);
        goto after_26;
    // 0x800A3694: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    after_26:
    // 0x800A3698: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x800A369C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A36A0: lb          $v1, 0x193($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X193);
    // 0x800A36A4: lb          $t2, 0x1D6($t6)
    ctx->r10 = MEM_B(ctx->r14, 0X1D6);
    // 0x800A36A8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800A36AC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A36B0: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800A36B4: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800A36B8: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x800A36BC: lw          $a0, 0x124($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X124);
    // 0x800A36C0: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800A36C4: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800A36C8: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x800A36CC: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x800A36D0: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A36D4: beq         $at, $zero, L_800A3728
    if (ctx->r1 == 0) {
        // 0x800A36D8: nop
    
            goto L_800A3728;
    }
    // 0x800A36D8: nop

    // 0x800A36DC: blez        $a1, L_800A3714
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800A36E0: or          $t1, $a0, $zero
        ctx->r9 = ctx->r4 | 0;
            goto L_800A3714;
    }
    // 0x800A36E0: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800A36E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A36E8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800A36EC: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_800A36F0:
    // 0x800A36F0: lw          $t9, 0x128($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X128);
    // 0x800A36F4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A36F8: slt         $at, $t1, $t9
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A36FC: bne         $at, $zero, L_800A370C
    if (ctx->r1 != 0) {
        // 0x800A3700: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800A370C;
    }
    // 0x800A3700: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A3704: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800A3708: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800A370C:
    // 0x800A370C: bne         $at, $zero, L_800A36F0
    if (ctx->r1 != 0) {
        // 0x800A3710: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A36F0;
    }
    // 0x800A3710: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800A3714:
    // 0x800A3714: beq         $t1, $zero, L_800A3728
    if (ctx->r9 == 0) {
        // 0x800A3718: addiu       $a0, $zero, 0x144
        ctx->r4 = ADD32(0, 0X144);
            goto L_800A3728;
    }
    // 0x800A3718: addiu       $a0, $zero, 0x144
    ctx->r4 = ADD32(0, 0X144);
    // 0x800A371C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3720: jal         0x80001D04
    // 0x800A3724: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_27;
    // 0x800A3724: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_27:
L_800A3728:
    // 0x800A3728: jal         0x8001B2BC
    // 0x800A372C: nop

    timetrial_valid_player_ghost(rdram, ctx);
        goto after_28;
    // 0x800A372C: nop

    after_28:
    // 0x800A3730: beq         $v0, $zero, L_800A3870
    if (ctx->r2 == 0) {
        // 0x800A3734: lw          $t2, 0xA0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XA0);
            goto L_800A3870;
    }
    // 0x800A3734: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3738: jal         0x8001B314
    // 0x800A373C: nop

    timetrial_player_ghost(rdram, ctx);
        goto after_29;
    // 0x800A373C: nop

    after_29:
    // 0x800A3740: beq         $v0, $zero, L_800A386C
    if (ctx->r2 == 0) {
        // 0x800A3744: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800A386C;
    }
    // 0x800A3744: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A3748: jal         0x8001139C
    // 0x800A374C: nop

    get_race_countdown(rdram, ctx);
        goto after_30;
    // 0x800A374C: nop

    after_30:
    // 0x800A3750: bne         $v0, $zero, L_800A3870
    if (ctx->r2 != 0) {
        // 0x800A3754: lw          $t2, 0xA0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XA0);
            goto L_800A3870;
    }
    // 0x800A3754: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3758: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x800A375C: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800A3760: lb          $t4, 0x1D8($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X1D8);
    // 0x800A3764: nop

    // 0x800A3768: bne         $t4, $zero, L_800A3870
    if (ctx->r12 != 0) {
        // 0x800A376C: lw          $t2, 0xA0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XA0);
            goto L_800A3870;
    }
    // 0x800A376C: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3770: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A3774: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800A3778: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800A377C: lwc1        $f6, 0x10($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800A3780: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A3784: lwc1        $f10, 0x14($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X14);
    // 0x800A3788: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A378C: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800A3790: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800A3794: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A3798: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800A379C: nop

    // 0x800A37A0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A37A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A37A8: jal         0x800CA030
    // 0x800A37AC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_31;
    // 0x800A37AC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_31:
    // 0x800A37B0: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x800A37B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A37B8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A37BC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800A37C0: nop

    // 0x800A37C4: bc1f        L_800A3848
    if (!c1cs) {
        // 0x800A37C8: nop
    
            goto L_800A3848;
    }
    // 0x800A37C8: nop

    // 0x800A37CC: lw          $t8, 0x7300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7300);
    // 0x800A37D0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A37D4: bne         $t8, $zero, L_800A3848
    if (ctx->r24 != 0) {
        // 0x800A37D8: addiu       $s0, $s0, 0x7310
        ctx->r16 = ADD32(ctx->r16, 0X7310);
            goto L_800A3848;
    }
    // 0x800A37D8: addiu       $s0, $s0, 0x7310
    ctx->r16 = ADD32(ctx->r16, 0X7310);
    // 0x800A37DC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A37E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A37E4: bne         $t7, $zero, L_800A3848
    if (ctx->r15 != 0) {
        // 0x800A37E8: nop
    
            goto L_800A3848;
    }
    // 0x800A37E8: nop

    // 0x800A37EC: jal         0x8006FB8C
    // 0x800A37F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rand_range(rdram, ctx);
        goto after_32;
    // 0x800A37F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x800A37F4: lhu         $t2, 0x0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X0);
    // 0x800A37F8: addiu       $v1, $v0, 0x147
    ctx->r3 = ADD32(ctx->r2, 0X147);
    // 0x800A37FC: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800A3800: bne         $t2, $t6, L_800A3828
    if (ctx->r10 != ctx->r14) {
        // 0x800A3804: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A3828;
    }
    // 0x800A3804: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A3808:
    // 0x800A3808: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A380C: jal         0x8006FB8C
    // 0x800A3810: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rand_range(rdram, ctx);
        goto after_33;
    // 0x800A3810: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_33:
    // 0x800A3814: lhu         $t9, 0x0($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X0);
    // 0x800A3818: addiu       $v1, $v0, 0x147
    ctx->r3 = ADD32(ctx->r2, 0X147);
    // 0x800A381C: andi        $t3, $v1, 0xFFFF
    ctx->r11 = ctx->r3 & 0XFFFF;
    // 0x800A3820: beq         $t9, $t3, L_800A3808
    if (ctx->r25 == ctx->r11) {
        // 0x800A3824: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_800A3808;
    }
    // 0x800A3824: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
L_800A3828:
    // 0x800A3828: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A382C: sh          $a0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r4;
    // 0x800A3830: jal         0x80001D04
    // 0x800A3834: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_34;
    // 0x800A3834: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_34:
    // 0x800A3838: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x800A383C: jal         0x8006FB8C
    // 0x800A3840: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    rand_range(rdram, ctx);
        goto after_35;
    // 0x800A3840: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    after_35:
    // 0x800A3844: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800A3848:
    // 0x800A3848: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A384C: addiu       $s0, $s0, 0x7310
    ctx->r16 = ADD32(ctx->r16, 0X7310);
    // 0x800A3850: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A3854: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3858: nop

    // 0x800A385C: subu        $t8, $t4, $t5
    ctx->r24 = SUB32(ctx->r12, ctx->r13);
    // 0x800A3860: bgez        $t8, L_800A386C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A3864: sw          $t8, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r24;
            goto L_800A386C;
    }
    // 0x800A3864: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800A3868: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800A386C:
    // 0x800A386C: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
L_800A3870:
    // 0x800A3870: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3874: lb          $v1, 0x193($t2)
    ctx->r3 = MEM_B(ctx->r10, 0X193);
    // 0x800A3878: nop

    // 0x800A387C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800A3880: addu        $t9, $t2, $t6
    ctx->r25 = ADD32(ctx->r10, ctx->r14);
    // 0x800A3884: lw          $t3, 0x128($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X128);
    // 0x800A3888: nop

    // 0x800A388C: slti        $at, $t3, 0x1E
    ctx->r1 = SIGNED(ctx->r11) < 0X1E ? 1 : 0;
    // 0x800A3890: beq         $at, $zero, L_800A38BC
    if (ctx->r1 == 0) {
        // 0x800A3894: nop
    
            goto L_800A38BC;
    }
    // 0x800A3894: nop

    // 0x800A3898: beq         $v1, $zero, L_800A38BC
    if (ctx->r3 == 0) {
        // 0x800A389C: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_800A38BC;
    }
    // 0x800A389C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800A38A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A38A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A38A8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800A38AC: jal         0x800A3C14
    // 0x800A38B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_36;
    // 0x800A38B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_36:
    // 0x800A38B4: b           L_800A3910
    // 0x800A38B8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
        goto L_800A3910;
    // 0x800A38B8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
L_800A38BC:
    // 0x800A38BC: lb          $t5, 0x1D3($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X1D3);
    // 0x800A38C0: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x800A38C4: blez        $t5, L_800A38E8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A38C8: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_800A38E8;
    }
    // 0x800A38C8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800A38CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A38D0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800A38D4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800A38D8: jal         0x800A3C14
    // 0x800A38DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_37;
    // 0x800A38DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_37:
    // 0x800A38E0: b           L_800A3910
    // 0x800A38E4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
        goto L_800A3910;
    // 0x800A38E4: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
L_800A38E8:
    // 0x800A38E8: lbu         $t7, 0x1FC($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X1FC);
    // 0x800A38EC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800A38F0: slti        $at, $t7, 0x79
    ctx->r1 = SIGNED(ctx->r15) < 0X79 ? 1 : 0;
    // 0x800A38F4: bne         $at, $zero, L_800A390C
    if (ctx->r1 != 0) {
        // 0x800A38F8: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_800A390C;
    }
    // 0x800A38F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800A38FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A3900: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800A3904: jal         0x800A3C14
    // 0x800A3908: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    hud_stopwatch_face(rdram, ctx);
        goto after_38;
    // 0x800A3908: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_38:
L_800A390C:
    // 0x800A390C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
L_800A3910:
    // 0x800A3910: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3914: jal         0x800A5498
    // 0x800A3918: nop

    hud_lap_count(rdram, ctx);
        goto after_39;
    // 0x800A3918: nop

    after_39:
    // 0x800A391C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3920: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3924: jal         0x800A80C4
    // 0x800A3928: nop

    hud_race_time(rdram, ctx);
        goto after_40;
    // 0x800A3928: nop

    after_40:
    // 0x800A392C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3930: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3934: jal         0x800A469C
    // 0x800A3938: nop

    hud_bananas(rdram, ctx);
        goto after_41;
    // 0x800A3938: nop

    after_41:
    // 0x800A393C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800A3940: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3944: jal         0x800A5FAC
    // 0x800A3948: nop

    hud_wrong_way(rdram, ctx);
        goto after_42;
    // 0x800A3948: nop

    after_42:
    // 0x800A394C: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800A3950: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3954: jal         0x800A422C
    // 0x800A3958: nop

    hud_race_start(rdram, ctx);
        goto after_43;
    // 0x800A3958: nop

    after_43:
    // 0x800A395C: lw          $a0, 0xC4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC4);
    // 0x800A3960: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3964: jal         0x800A3DCC
    // 0x800A3968: nop

    hud_speedometre(rdram, ctx);
        goto after_44;
    // 0x800A3968: nop

    after_44:
    // 0x800A396C: jal         0x8000E0B0
    // 0x800A3970: nop

    get_contpak_error(rdram, ctx);
        goto after_45;
    // 0x800A3970: nop

    after_45:
    // 0x800A3974: blez        $v0, L_800A3BF4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A3978: nop
    
            goto L_800A3BF4;
    }
    // 0x800A3978: nop

    // 0x800A397C: jal         0x8000E0B0
    // 0x800A3980: nop

    get_contpak_error(rdram, ctx);
        goto after_46;
    // 0x800A3980: nop

    after_46:
    // 0x800A3984: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A3988: beq         $v0, $at, L_800A39B4
    if (ctx->r2 == ctx->r1) {
        // 0x800A398C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A39B4;
    }
    // 0x800A398C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A3990: beq         $v0, $at, L_800A39DC
    if (ctx->r2 == ctx->r1) {
        // 0x800A3994: lui         $t3, 0x800F
        ctx->r11 = S32(0X800F << 16);
            goto L_800A39DC;
    }
    // 0x800A3994: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800A3998: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A399C: beq         $v0, $at, L_800A3A00
    if (ctx->r2 == ctx->r1) {
        // 0x800A39A0: lui         $t8, 0x800F
        ctx->r24 = S32(0X800F << 16);
            goto L_800A3A00;
    }
    // 0x800A39A0: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800A39A4: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800A39A8: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x800A39AC: b           L_800A3A20
    // 0x800A39B0: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
        goto L_800A3A20;
    // 0x800A39B0: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_800A39B4:
    // 0x800A39B4: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800A39B8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800A39BC: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800A39C0: addiu       $t2, $t2, -0x7430
    ctx->r10 = ADD32(ctx->r10, -0X7430);
    // 0x800A39C4: addiu       $t6, $t6, -0x7428
    ctx->r14 = ADD32(ctx->r14, -0X7428);
    // 0x800A39C8: addiu       $t9, $t9, -0x7420
    ctx->r25 = ADD32(ctx->r25, -0X7420);
    // 0x800A39CC: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800A39D0: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x800A39D4: b           L_800A3A20
    // 0x800A39D8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
        goto L_800A3A20;
    // 0x800A39D8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_800A39DC:
    // 0x800A39DC: lui         $t4, 0x800F
    ctx->r12 = S32(0X800F << 16);
    // 0x800A39E0: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800A39E4: addiu       $t3, $t3, -0x7418
    ctx->r11 = ADD32(ctx->r11, -0X7418);
    // 0x800A39E8: addiu       $t4, $t4, -0x740C
    ctx->r12 = ADD32(ctx->r12, -0X740C);
    // 0x800A39EC: addiu       $t5, $t5, -0x7408
    ctx->r13 = ADD32(ctx->r13, -0X7408);
    // 0x800A39F0: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x800A39F4: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x800A39F8: b           L_800A3A20
    // 0x800A39FC: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
        goto L_800A3A20;
    // 0x800A39FC: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
L_800A3A00:
    // 0x800A3A00: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800A3A04: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800A3A08: addiu       $t8, $t8, -0x7400
    ctx->r24 = ADD32(ctx->r24, -0X7400);
    // 0x800A3A0C: addiu       $t7, $t7, -0x73F4
    ctx->r15 = ADD32(ctx->r15, -0X73F4);
    // 0x800A3A10: addiu       $t2, $t2, -0x73F0
    ctx->r10 = ADD32(ctx->r10, -0X73F0);
    // 0x800A3A14: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800A3A18: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x800A3A1C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_800A3A20:
    // 0x800A3A20: jal         0x800C46C4
    // 0x800A3A24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_kerning(rdram, ctx);
        goto after_47;
    // 0x800A3A24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_47:
    // 0x800A3A28: jal         0x800C484C
    // 0x800A3A2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_48;
    // 0x800A3A2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_48:
    // 0x800A3A30: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A3A34: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A3A38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A3A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A3A40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A3A44: jal         0x800C48E4
    // 0x800A3A48: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_49;
    // 0x800A3A48: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_49:
    // 0x800A3A4C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A3A50: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A3A54: addiu       $s1, $s1, 0x72E4
    ctx->r17 = ADD32(ctx->r17, 0X72E4);
    // 0x800A3A58: addiu       $s0, $s0, 0x774C
    ctx->r16 = ADD32(ctx->r16, 0X774C);
    // 0x800A3A5C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A3A60: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800A3A64: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3A68: lw          $t5, 0x72E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E8);
    // 0x800A3A6C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3A70: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3A74: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800A3A78: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800A3A7C: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800A3A80: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800A3A84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A3A88: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A3A8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3A90: jal         0x800C49A0
    // 0x800A3A94: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    draw_text(rdram, ctx);
        goto after_50;
    // 0x800A3A94: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_50:
    // 0x800A3A98: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A3A9C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800A3AA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A3AA4: lw          $t9, 0x72E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72E8);
    // 0x800A3AA8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3AAC: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3AB0: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x800A3AB4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800A3AB8: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800A3ABC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    // 0x800A3AC0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A3AC4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A3AC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3ACC: jal         0x800C49A0
    // 0x800A3AD0: addiu       $a2, $a2, 0xF
    ctx->r6 = ADD32(ctx->r6, 0XF);
    draw_text(rdram, ctx);
        goto after_51;
    // 0x800A3AD0: addiu       $a2, $a2, 0xF
    ctx->r6 = ADD32(ctx->r6, 0XF);
    after_51:
    // 0x800A3AD4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A3AD8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800A3ADC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A3AE0: lw          $t7, 0x72E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72E8);
    // 0x800A3AE4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3AE8: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3AEC: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x800A3AF0: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800A3AF4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800A3AF8: addu        $a1, $t8, $t7
    ctx->r5 = ADD32(ctx->r24, ctx->r15);
    // 0x800A3AFC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A3B00: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A3B04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3B08: jal         0x800C49A0
    // 0x800A3B0C: addiu       $a2, $a2, 0x1D
    ctx->r6 = ADD32(ctx->r6, 0X1D);
    draw_text(rdram, ctx);
        goto after_52;
    // 0x800A3B0C: addiu       $a2, $a2, 0x1D
    ctx->r6 = ADD32(ctx->r6, 0X1D);
    after_52:
    // 0x800A3B10: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A3B14: lw          $v0, 0x7754($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7754);
    // 0x800A3B18: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800A3B1C: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x800A3B20: lbu         $a0, 0x10($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X10);
    // 0x800A3B24: lbu         $a1, 0x11($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X11);
    // 0x800A3B28: lbu         $a2, 0x12($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X12);
    // 0x800A3B2C: jal         0x800C48E4
    // 0x800A3B30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    set_text_colour(rdram, ctx);
        goto after_53;
    // 0x800A3B30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_53:
    // 0x800A3B34: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A3B38: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800A3B3C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3B40: lw          $t5, 0x72E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72E8);
    // 0x800A3B44: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3B48: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3B4C: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800A3B50: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800A3B54: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800A3B58: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800A3B5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3B60: jal         0x800C49A0
    // 0x800A3B64: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    draw_text(rdram, ctx);
        goto after_54;
    // 0x800A3B64: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_54:
    // 0x800A3B68: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A3B6C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800A3B70: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A3B74: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3B78: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3B7C: lw          $t9, 0x72E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X72E8);
    // 0x800A3B80: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800A3B84: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800A3B88: addu        $t6, $t7, $t2
    ctx->r14 = ADD32(ctx->r15, ctx->r10);
    // 0x800A3B8C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800A3B90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3B94: addiu       $a2, $a2, 0xE
    ctx->r6 = ADD32(ctx->r6, 0XE);
    // 0x800A3B98: jal         0x800C49A0
    // 0x800A3B9C: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    draw_text(rdram, ctx);
        goto after_55;
    // 0x800A3B9C: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    after_55:
    // 0x800A3BA0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A3BA4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800A3BA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A3BAC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3BB0: lw          $a2, 0x7750($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7750);
    // 0x800A3BB4: lw          $t7, 0x72E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72E8);
    // 0x800A3BB8: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x800A3BBC: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800A3BC0: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x800A3BC4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A3BC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800A3BCC: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    // 0x800A3BD0: jal         0x800C49A0
    // 0x800A3BD4: addu        $a1, $t8, $t7
    ctx->r5 = ADD32(ctx->r24, ctx->r15);
    draw_text(rdram, ctx);
        goto after_56;
    // 0x800A3BD4: addu        $a1, $t8, $t7
    ctx->r5 = ADD32(ctx->r24, ctx->r15);
    after_56:
    // 0x800A3BD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3BDC: lw          $a0, 0x7754($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7754);
    // 0x800A3BE0: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x800A3BE4: jal         0x8007F69C
    // 0x800A3BE8: nop

    update_colour_cycle(rdram, ctx);
        goto after_57;
    // 0x800A3BE8: nop

    after_57:
    // 0x800A3BEC: jal         0x800C46C4
    // 0x800A3BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_kerning(rdram, ctx);
        goto after_58;
    // 0x800A3BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_58:
L_800A3BF4:
    // 0x800A3BF4: jal         0x80068748
    // 0x800A3BF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_59;
    // 0x800A3BF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_59:
L_800A3BFC:
    // 0x800A3BFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A3C00: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A3C04: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A3C08: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A3C0C: jr          $ra
    // 0x800A3C10: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800A3C10: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_8006F20C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F44C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F450: lh          $t6, -0x26FC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X26FC);
    // 0x8006F454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F458: bne         $t6, $zero, L_8006F484
    if (ctx->r14 != 0) {
        // 0x8006F45C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F484;
    }
    // 0x8006F45C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F460: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F464: jal         0x800C06F8
    // 0x8006F468: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F468: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    after_0:
    // 0x8006F46C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F470: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F474: sh          $t7, -0x26FC($at)
    MEM_H(-0X26FC, ctx->r1) = ctx->r15;
    // 0x8006F478: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F47C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006F480: sb          $t8, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = ctx->r24;
L_8006F484:
    // 0x8006F484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F488: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F48C: jr          $ra
    // 0x8006F490: nop

    return;
    // 0x8006F490: nop

;}
RECOMP_FUNC void try_free_object_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C844: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C848: addiu       $a2, $a2, -0x4C34
    ctx->r6 = ADD32(ctx->r6, -0X4C34);
    // 0x8000C84C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8000C850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C858: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C85C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C860: nop

    // 0x8000C864: beq         $v1, $zero, L_8000C8A4
    if (ctx->r3 == 0) {
        // 0x8000C868: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8000C8A4;
    }
    // 0x8000C868: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8000C86C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8000C870: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8000C874: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000C878: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8000C87C: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8000C880: nop

    // 0x8000C884: bne         $t0, $zero, L_8000C8A8
    if (ctx->r8 != 0) {
        // 0x8000C888: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000C8A8;
    }
    // 0x8000C888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C88C: lw          $t1, -0x4C38($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4C38);
    // 0x8000C890: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8000C894: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8000C898: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8000C89C: jal         0x80071380
    // 0x8000C8A0: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8000C8A0: nop

    after_0:
L_8000C8A4:
    // 0x8000C8A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000C8A8:
    // 0x8000C8A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C8AC: jr          $ra
    // 0x8000C8B0: nop

    return;
    // 0x8000C8B0: nop

;}
RECOMP_FUNC void obj_spawn_effect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FC84: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003FC88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003FC8C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003FC90: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x8003FC94: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003FC98: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003FC9C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003FCA0: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8003FCA4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003FCA8: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8003FCAC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003FCB0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8003FCB4: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8003FCB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8003FCBC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8003FCC0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8003FCC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003FCC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003FCCC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8003FCD0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8003FCD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003FCD8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8003FCDC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8003FCE0: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8003FCE4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8003FCE8: addiu       $t2, $t1, 0x24
    ctx->r10 = ADD32(ctx->r9, 0X24);
    // 0x8003FCEC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8003FCF0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003FCF4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003FCF8: sh          $t2, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r10;
    // 0x8003FCFC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8003FD00: sb          $t5, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r13;
    // 0x8003FD04: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8003FD08: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8003FD0C: sb          $a3, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r7;
    // 0x8003FD10: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8003FD14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003FD18: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    // 0x8003FD1C: sb          $t6, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r14;
    // 0x8003FD20: jal         0x8000EA54
    // 0x8003FD24: sh          $t4, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r12;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x8003FD24: sh          $t4, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r12;
    after_0:
    // 0x8003FD28: beq         $v0, $zero, L_8003FD70
    if (ctx->r2 == 0) {
        // 0x8003FD2C: lui         $at, 0x400C
        ctx->r1 = S32(0X400C << 16);
            goto L_8003FD70;
    }
    // 0x8003FD2C: lui         $at, 0x400C
    ctx->r1 = S32(0X400C << 16);
    // 0x8003FD30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003FD34: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003FD38: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003FD3C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003FD40: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003FD44: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003FD48: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003FD4C: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8003FD50: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8003FD54: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8003FD58: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003FD5C: nop

    // 0x8003FD60: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003FD64: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8003FD68: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8003FD6C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
L_8003FD70:
    // 0x8003FD70: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8003FD74: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8003FD78: beq         $v0, $zero, L_8003FD98
    if (ctx->r2 == 0) {
        // 0x8003FD7C: andi        $a0, $v0, 0xFFFF
        ctx->r4 = ctx->r2 & 0XFFFF;
            goto L_8003FD98;
    }
    // 0x8003FD7C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8003FD80: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8003FD84: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003FD88: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8003FD8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003FD90: jal         0x80009558
    // 0x8003FD94: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_1;
    // 0x8003FD94: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
L_8003FD98:
    // 0x8003FD98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003FD9C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003FDA0: jr          $ra
    // 0x8003FDA4: nop

    return;
    // 0x8003FDA4: nop

;}
RECOMP_FUNC void write_time_data_to_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800743A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800743A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800743A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800743AC: jal         0x80073EAC
    // 0x800743B0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    get_time_data_file_size(rdram, ctx);
        goto after_0;
    // 0x800743B0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800743B4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800743B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800743BC: jal         0x80070EDC
    // 0x800743C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800743C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800743C4: lui         $t6, 0x5449
    ctx->r14 = S32(0X5449 << 16);
    // 0x800743C8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800743CC: ori         $t6, $t6, 0x4D44
    ctx->r14 = ctx->r14 | 0X4D44;
    // 0x800743D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800743D4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800743D8: jal         0x80073AFC
    // 0x800743DC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800738A4(rdram, ctx);
        goto after_2;
    // 0x800743DC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x800743E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800743E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800743E8: jal         0x80073EB4
    // 0x800743EC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    get_file_extension(rdram, ctx);
        goto after_3;
    // 0x800743EC: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x800743F0: bne         $v0, $zero, L_80074424
    if (ctx->r2 != 0) {
        // 0x800743F4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80074424;
    }
    // 0x800743F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800743F8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800743FC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80074400: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80074404: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80074408: addiu       $a2, $a2, 0x7C30
    ctx->r6 = ADD32(ctx->r6, 0X7C30);
    // 0x8007440C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80074410: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x80074414: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80074418: jal         0x8007692C
    // 0x8007441C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    write_controller_pak_file(rdram, ctx);
        goto after_4;
    // 0x8007441C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_4:
    // 0x80074420: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80074424:
    // 0x80074424: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80074428: jal         0x80071380
    // 0x8007442C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8007442C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_5:
    // 0x80074430: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80074434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074438: beq         $v1, $zero, L_80074454
    if (ctx->r3 == 0) {
        // 0x8007443C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80074454;
    }
    // 0x8007443C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80074440: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80074444: nop

    // 0x80074448: sll         $t0, $t9, 30
    ctx->r8 = S32(ctx->r25 << 30);
    // 0x8007444C: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x80074450: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80074454:
    // 0x80074454: jr          $ra
    // 0x80074458: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80074458: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void set_pause_lockout_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F5C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F5CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006F5D0: jr          $ra
    // 0x8006F5D4: sb          $a0, -0x26F8($at)
    MEM_B(-0X26F8, ctx->r1) = ctx->r4;
    return;
    // 0x8006F5D4: sb          $a0, -0x26F8($at)
    MEM_B(-0X26F8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_init_unknown94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042190: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80042194: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80042198: jr          $ra
    // 0x8004219C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x8004219C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void calc_dynamic_lighting_for_object_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D840: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8001D844: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001D848: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001D84C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001D850: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001D854: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001D858: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001D85C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001D860: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001D864: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001D868: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D86C: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8001D870: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x8001D874: lw          $v0, 0x54($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X54);
    // 0x8001D878: sll         $s2, $a2, 16
    ctx->r18 = S32(ctx->r6 << 16);
    // 0x8001D87C: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D880: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x8001D884: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001D888: beq         $v0, $zero, L_8001DD58
    if (ctx->r2 == 0) {
        // 0x8001D88C: or          $s7, $a1, $zero
        ctx->r23 = ctx->r5 | 0;
            goto L_8001DD58;
    }
    // 0x8001D88C: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8001D890: lw          $t7, 0x40($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X40);
    // 0x8001D894: lw          $fp, 0x44($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X44);
    // 0x8001D898: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8001D89C: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x8001D8A0: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x8001D8A4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001D8A8: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D8AC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001D8B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001D8B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001D8B8: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8001D8BC: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x8001D8C0: nop

    // 0x8001D8C4: lh          $t8, 0xA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XA);
    // 0x8001D8C8: nop

    // 0x8001D8CC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001D8D0: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D8D4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8001D8D8: nop

    // 0x8001D8DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001D8E0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8001D8E4: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x8001D8E8: nop

    // 0x8001D8EC: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x8001D8F0: nop

    // 0x8001D8F4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001D8F8: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D8FC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8001D900: nop

    // 0x8001D904: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001D908: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x8001D90C: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x8001D910: nop

    // 0x8001D914: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8001D918: sh          $t8, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r24;
    // 0x8001D91C: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8001D920: nop

    // 0x8001D924: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x8001D928: sh          $t6, 0x96($sp)
    MEM_H(0X96, ctx->r29) = ctx->r14;
    // 0x8001D92C: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x8001D930: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x8001D934: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8001D938: sh          $t8, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r24;
    // 0x8001D93C: jal         0x80070618
    // 0x8001D940: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    vec3f_rotate_ypr(rdram, ctx);
        goto after_0;
    // 0x8001D940: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    after_0:
    // 0x8001D944: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x8001D948: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001D94C: lbu         $t6, 0x3D($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X3D);
    // 0x8001D950: nop

    // 0x8001D954: beq         $t6, $zero, L_8001D984
    if (ctx->r14 == 0) {
        // 0x8001D958: nop
    
            goto L_8001D984;
    }
    // 0x8001D958: nop

    // 0x8001D95C: beq         $s2, $zero, L_8001D984
    if (ctx->r18 == 0) {
        // 0x8001D960: nop
    
            goto L_8001D984;
    }
    // 0x8001D960: nop

    // 0x8001D964: jal         0x80069FE4
    // 0x8001D968: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    get_projection_matrix_f32(rdram, ctx);
        goto after_1;
    // 0x8001D968: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    after_1:
    // 0x8001D96C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001D970: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001D974: jal         0x8006F92C
    // 0x8001D978: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_2;
    // 0x8001D978: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x8001D97C: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001D980: nop

L_8001D984:
    // 0x8001D984: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001D988: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001D98C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001D990: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8001D994: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001D998: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8001D99C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D9A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D9A4: lw          $v0, 0x54($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X54);
    // 0x8001D9A8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001D9AC: lh          $t6, 0x1C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1C);
    // 0x8001D9B0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8001D9B4: mfc1        $s3, $f8
    ctx->r19 = (int32_t)ctx->f8.u32l;
    // 0x8001D9B8: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8001D9BC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001D9C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D9C4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001D9C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D9CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D9D0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8001D9D4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8001D9D8: lbu         $s6, 0x7($v0)
    ctx->r22 = MEM_BU(ctx->r2, 0X7);
    // 0x8001D9DC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001D9E0: mfc1        $s4, $f18
    ctx->r20 = (int32_t)ctx->f18.u32l;
    // 0x8001D9E4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001D9E8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001D9EC: nop

    // 0x8001D9F0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001D9F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D9F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D9FC: nop

    // 0x8001DA00: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001DA04: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001DA08: mfc1        $s5, $f8
    ctx->r21 = (int32_t)ctx->f8.u32l;
    // 0x8001DA0C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001DA10: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x8001DA14: lw          $t8, 0x54($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X54);
    // 0x8001DA18: nop

    // 0x8001DA1C: lh          $t9, 0x1E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X1E);
    // 0x8001DA20: nop

    // 0x8001DA24: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001DA28: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8001DA2C: nop

    // 0x8001DA30: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001DA34: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8001DA38: lw          $t7, 0x54($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X54);
    // 0x8001DA3C: nop

    // 0x8001DA40: lh          $t8, 0x20($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X20);
    // 0x8001DA44: nop

    // 0x8001DA48: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001DA4C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8001DA50: nop

    // 0x8001DA54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001DA58: beq         $s2, $zero, L_8001DA80
    if (ctx->r18 == 0) {
        // 0x8001DA5C: swc1        $f8, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
            goto L_8001DA80;
    }
    // 0x8001DA5C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x8001DA60: jal         0x80069FE4
    // 0x8001DA64: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    get_projection_matrix_f32(rdram, ctx);
        goto after_3;
    // 0x8001DA64: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    after_3:
    // 0x8001DA68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001DA6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001DA70: jal         0x8006F92C
    // 0x8001DA74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_4;
    // 0x8001DA74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x8001DA78: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001DA7C: nop

L_8001DA80:
    // 0x8001DA80: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8001DA84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001DA88: jal         0x80070618
    // 0x8001DA8C: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    vec3f_rotate_ypr(rdram, ctx);
        goto after_5;
    // 0x8001DA8C: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    after_5:
    // 0x8001DA90: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001DA94: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8001DA98: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001DA9C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001DAA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DAA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DAA8: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001DAAC: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001DAB0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001DAB4: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001DAB8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001DABC: lw          $v0, 0x54($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X54);
    // 0x8001DAC0: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x8001DAC4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8001DAC8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001DACC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8001DAD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DAD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DAD8: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8001DADC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8001DAE0: lwc1        $f2, 0xB0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8001DAE4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8001DAE8: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x8001DAEC: lh          $t1, 0x9E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9E);
    // 0x8001DAF0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001DAF4: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8001DAF8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001DAFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DB00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DB04: nop

    // 0x8001DB08: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001DB0C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001DB10: mfc1        $ra, $f8
    ctx->r31 = (int32_t)ctx->f8.u32l;
    // 0x8001DB14: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001DB18: lwc1        $f8, 0x2C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8001DB1C: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x8001DB20: lh          $v1, 0x28($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X28);
    // 0x8001DB24: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8001DB28: nop

    // 0x8001DB2C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8001DB30: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001DB34: nop

    // 0x8001DB38: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001DB3C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DB40: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DB44: nop

    // 0x8001DB48: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001DB4C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001DB50: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8001DB54: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001DB58: nop

    // 0x8001DB5C: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001DB60: nop

    // 0x8001DB64: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8001DB68: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001DB6C: nop

    // 0x8001DB70: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001DB74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001DB78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001DB7C: nop

    // 0x8001DB80: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8001DB84: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x8001DB88: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001DB8C: blez        $v1, L_8001DD58
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001DB90: nop
    
            goto L_8001DD58;
    }
    // 0x8001DB90: nop

    // 0x8001DB94: lw          $a2, 0x38($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X38);
    // 0x8001DB98: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_8001DB9C:
    // 0x8001DB9C: lh          $t3, 0x9A($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X9A);
    // 0x8001DBA0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8001DBA4: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8001DBA8: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8001DBAC: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8001DBB0: addu        $v0, $a2, $t3
    ctx->r2 = ADD32(ctx->r6, ctx->r11);
    // 0x8001DBB4: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x8001DBB8: nop

    // 0x8001DBBC: beq         $t8, $at, L_8001DD0C
    if (ctx->r24 == ctx->r1) {
        // 0x8001DBC0: nop
    
            goto L_8001DD0C;
    }
    // 0x8001DBC0: nop

    // 0x8001DBC4: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x8001DBC8: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x8001DBCC: nop

    // 0x8001DBD0: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001DBD4: beq         $at, $zero, L_8001DD3C
    if (ctx->r1 == 0) {
        // 0x8001DBD8: lh          $v0, 0x9A($sp)
        ctx->r2 = MEM_H(ctx->r29, 0X9A);
            goto L_8001DD3C;
    }
    // 0x8001DBD8: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
L_8001DBDC:
    // 0x8001DBDC: multu       $t1, $s1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DBE0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8001DBE4: mflo        $t7
    ctx->r15 = lo;
    // 0x8001DBE8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001DBEC: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x8001DBF0: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x8001DBF4: multu       $a2, $s5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DBF8: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x8001DBFC: mflo        $t8
    ctx->r24 = lo;
    // 0x8001DC00: nop

    // 0x8001DC04: nop

    // 0x8001DC08: multu       $a3, $s3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC0C: mflo        $t9
    ctx->r25 = lo;
    // 0x8001DC10: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8001DC14: nop

    // 0x8001DC18: multu       $t0, $s4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC1C: mflo        $t7
    ctx->r15 = lo;
    // 0x8001DC20: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8001DC24: sra         $t8, $a0, 13
    ctx->r24 = S32(SIGNED(ctx->r4) >> 13);
    // 0x8001DC28: blez        $t8, L_8001DC50
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001DC2C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001DC50;
    }
    // 0x8001DC2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001DC30: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC34: mflo        $a0
    ctx->r4 = lo;
    // 0x8001DC38: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001DC3C: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x8001DC40: bne         $at, $zero, L_8001DC50
    if (ctx->r1 != 0) {
        // 0x8001DC44: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_8001DC50;
    }
    // 0x8001DC44: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8001DC48: b           L_8001DC50
    // 0x8001DC4C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
        goto L_8001DC50;
    // 0x8001DC4C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8001DC50:
    // 0x8001DC50: multu       $a2, $ra
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC54: mflo        $t6
    ctx->r14 = lo;
    // 0x8001DC58: nop

    // 0x8001DC5C: nop

    // 0x8001DC60: multu       $a3, $t4
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC64: mflo        $t7
    ctx->r15 = lo;
    // 0x8001DC68: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001DC6C: nop

    // 0x8001DC70: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC74: mflo        $t9
    ctx->r25 = lo;
    // 0x8001DC78: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8001DC7C: sra         $t6, $v1, 13
    ctx->r14 = S32(SIGNED(ctx->r3) >> 13);
    // 0x8001DC80: blez        $t6, L_8001DCAC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001DC84: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_8001DCAC;
    }
    // 0x8001DC84: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x8001DC88: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DC8C: mflo        $v1
    ctx->r3 = lo;
    // 0x8001DC90: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001DC94: addu        $v1, $t7, $t2
    ctx->r3 = ADD32(ctx->r15, ctx->r10);
    // 0x8001DC98: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8001DC9C: bne         $at, $zero, L_8001DCAC
    if (ctx->r1 != 0) {
        // 0x8001DCA0: nop
    
            goto L_8001DCAC;
    }
    // 0x8001DCA0: nop

    // 0x8001DCA4: b           L_8001DCAC
    // 0x8001DCA8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_8001DCAC;
    // 0x8001DCA8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_8001DCAC:
    // 0x8001DCAC: multu       $a1, $s2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001DCB0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001DCB4: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8001DCB8: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001DCBC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001DCC0: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8001DCC4: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001DCC8: mflo        $t8
    ctx->r24 = lo;
    // 0x8001DCCC: addu        $v0, $fp, $t8
    ctx->r2 = ADD32(ctx->r30, ctx->r24);
    // 0x8001DCD0: sb          $a0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r4;
    // 0x8001DCD4: sb          $a0, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r4;
    // 0x8001DCD8: sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
    // 0x8001DCDC: sb          $v1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r3;
    // 0x8001DCE0: lw          $a2, 0x38($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X38);
    // 0x8001DCE4: nop

    // 0x8001DCE8: addu        $t9, $a2, $t3
    ctx->r25 = ADD32(ctx->r6, ctx->r11);
    // 0x8001DCEC: lh          $t6, 0xE($t9)
    ctx->r14 = MEM_H(ctx->r25, 0XE);
    // 0x8001DCF0: nop

    // 0x8001DCF4: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001DCF8: bne         $at, $zero, L_8001DBDC
    if (ctx->r1 != 0) {
        // 0x8001DCFC: nop
    
            goto L_8001DBDC;
    }
    // 0x8001DCFC: nop

    // 0x8001DD00: lh          $v1, 0x28($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X28);
    // 0x8001DD04: b           L_8001DD3C
    // 0x8001DD08: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
        goto L_8001DD3C;
    // 0x8001DD08: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
L_8001DD0C:
    // 0x8001DD0C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8001DD10: nop

    // 0x8001DD14: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8001DD18: beq         $t8, $zero, L_8001DD38
    if (ctx->r24 == 0) {
        // 0x8001DD1C: nop
    
            goto L_8001DD38;
    }
    // 0x8001DD1C: nop

    // 0x8001DD20: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x8001DD24: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8001DD28: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x8001DD2C: subu        $t1, $t6, $t7
    ctx->r9 = SUB32(ctx->r14, ctx->r15);
    // 0x8001DD30: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8001DD34: sra         $t1, $t8, 16
    ctx->r9 = S32(SIGNED(ctx->r24) >> 16);
L_8001DD38:
    // 0x8001DD38: lh          $v0, 0x9A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X9A);
L_8001DD3C:
    // 0x8001DD3C: nop

    // 0x8001DD40: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001DD44: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8001DD48: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001DD4C: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001DD50: bne         $at, $zero, L_8001DB9C
    if (ctx->r1 != 0) {
        // 0x8001DD54: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_8001DB9C;
    }
    // 0x8001DD54: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
L_8001DD58:
    // 0x8001DD58: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001DD5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001DD60: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DD64: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001DD68: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001DD6C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001DD70: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001DD74: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001DD78: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001DD7C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001DD80: jr          $ra
    // 0x8001DD84: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8001DD84: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void render_fill_rectangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C600C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C6010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C6014: jal         0x8007A970
    // 0x800C6018: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800C6018: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C601C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800C6020: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6024: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800C6028: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C602C: bltz        $a3, L_800C60A8
    if (SIGNED(ctx->r7) < 0) {
        // 0x800C6030: andi        $t6, $v0, 0xFFFF
        ctx->r14 = ctx->r2 & 0XFFFF;
            goto L_800C60A8;
    }
    // 0x800C6030: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x800C6034: sltu        $at, $a1, $t6
    ctx->r1 = ctx->r5 < ctx->r14 ? 1 : 0;
    // 0x800C6038: beq         $at, $zero, L_800C60AC
    if (ctx->r1 == 0) {
        // 0x800C603C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C60AC;
    }
    // 0x800C603C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6040: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C6044: srl         $t7, $v0, 16
    ctx->r15 = S32(U32(ctx->r2) >> 16);
    // 0x800C6048: bltz        $a0, L_800C60A8
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C604C: sltu        $at, $a2, $t7
        ctx->r1 = ctx->r6 < ctx->r15 ? 1 : 0;
            goto L_800C60A8;
    }
    // 0x800C604C: sltu        $at, $a2, $t7
    ctx->r1 = ctx->r6 < ctx->r15 ? 1 : 0;
    // 0x800C6050: beq         $at, $zero, L_800C60A8
    if (ctx->r1 == 0) {
        // 0x800C6054: andi        $t9, $a3, 0x3FF
        ctx->r25 = ctx->r7 & 0X3FF;
            goto L_800C60A8;
    }
    // 0x800C6054: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x800C6058: bgez        $a1, L_800C6064
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800C605C: sll         $t1, $t9, 14
        ctx->r9 = S32(ctx->r25 << 14);
            goto L_800C6064;
    }
    // 0x800C605C: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x800C6060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800C6064:
    // 0x800C6064: bgez        $a2, L_800C6070
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C6068: lui         $at, 0xF600
        ctx->r1 = S32(0XF600 << 16);
            goto L_800C6070;
    }
    // 0x800C6068: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C606C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800C6070:
    // 0x800C6070: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800C6074: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x800C6078: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C607C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800C6080: andi        $t8, $a2, 0x3FF
    ctx->r24 = ctx->r6 & 0X3FF;
    // 0x800C6084: andi        $t3, $a0, 0x3FF
    ctx->r11 = ctx->r4 & 0X3FF;
    // 0x800C6088: andi        $t6, $a1, 0x3FF
    ctx->r14 = ctx->r5 & 0X3FF;
    // 0x800C608C: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x800C6090: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800C6094: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C6098: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x800C609C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800C60A0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800C60A4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_800C60A8:
    // 0x800C60A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C60AC:
    // 0x800C60AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C60B0: jr          $ra
    // 0x800C60B4: nop

    return;
    // 0x800C60B4: nop

;}
RECOMP_FUNC void waves_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA138: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800BA13C: addiu       $t1, $t1, -0x5A28
    ctx->r9 = ADD32(ctx->r9, -0X5A28);
    // 0x800BA140: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BA144: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800BA148: addiu       $t3, $t3, -0x5A78
    ctx->r11 = ADD32(ctx->r11, -0X5A78);
    // 0x800BA14C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BA150: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // 0x800BA154: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BA158: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800BA15C: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800BA160: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800BA164: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BA168: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800BA16C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BA170: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800BA174: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BA178: blez        $v0, L_800BA268
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BA17C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800BA268;
    }
    // 0x800BA17C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800BA180: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800BA184: addiu       $a2, $a2, 0x35D4
    ctx->r6 = ADD32(ctx->r6, 0X35D4);
L_800BA188:
    // 0x800BA188: blez        $v0, L_800BA258
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BA18C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800BA258;
    }
    // 0x800BA18C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BA190: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BA194: sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8 << 2);
    // 0x800BA198: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
L_800BA19C:
    // 0x800BA19C: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800BA1A0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BA1A4: addu        $t6, $t7, $s1
    ctx->r14 = ADD32(ctx->r15, ctx->r17);
    // 0x800BA1A8: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800BA1AC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800BA1B0: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800BA1B4: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x800BA1B8: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800BA1BC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800BA1C0: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA1C4: bne         $at, $zero, L_800BA1F0
    if (ctx->r1 != 0) {
        // 0x800BA1C8: subu        $t9, $a0, $v0
        ctx->r25 = SUB32(ctx->r4, ctx->r2);
            goto L_800BA1F0;
    }
    // 0x800BA1C8: subu        $t9, $a0, $v0
    ctx->r25 = SUB32(ctx->r4, ctx->r2);
L_800BA1CC:
    // 0x800BA1CC: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x800BA1D0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800BA1D4: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800BA1D8: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x800BA1DC: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800BA1E0: nop

    // 0x800BA1E4: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA1E8: beq         $at, $zero, L_800BA1CC
    if (ctx->r1 == 0) {
        // 0x800BA1EC: subu        $t9, $a0, $v0
        ctx->r25 = SUB32(ctx->r4, ctx->r2);
            goto L_800BA1CC;
    }
    // 0x800BA1EC: subu        $t9, $a0, $v0
    ctx->r25 = SUB32(ctx->r4, ctx->r2);
L_800BA1F0:
    // 0x800BA1F0: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800BA1F4: nop

    // 0x800BA1F8: addu        $t8, $t6, $s1
    ctx->r24 = ADD32(ctx->r14, ctx->r17);
    // 0x800BA1FC: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x800BA200: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BA204: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800BA208: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
    // 0x800BA20C: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x800BA210: nop

    // 0x800BA214: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA218: bne         $at, $zero, L_800BA244
    if (ctx->r1 != 0) {
        // 0x800BA21C: subu        $t7, $a0, $v0
        ctx->r15 = SUB32(ctx->r4, ctx->r2);
            goto L_800BA244;
    }
    // 0x800BA21C: subu        $t7, $a0, $v0
    ctx->r15 = SUB32(ctx->r4, ctx->r2);
L_800BA220:
    // 0x800BA220: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
    // 0x800BA224: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800BA228: lw          $v0, 0x20($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X20);
    // 0x800BA22C: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x800BA230: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x800BA234: nop

    // 0x800BA238: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA23C: beq         $at, $zero, L_800BA220
    if (ctx->r1 == 0) {
        // 0x800BA240: subu        $t7, $a0, $v0
        ctx->r15 = SUB32(ctx->r4, ctx->r2);
            goto L_800BA220;
    }
    // 0x800BA240: subu        $t7, $a0, $v0
    ctx->r15 = SUB32(ctx->r4, ctx->r2);
L_800BA244:
    // 0x800BA244: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // 0x800BA248: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800BA24C: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA250: bne         $at, $zero, L_800BA19C
    if (ctx->r1 != 0) {
        // 0x800BA254: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800BA19C;
    }
    // 0x800BA254: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800BA258:
    // 0x800BA258: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BA25C: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA260: bne         $at, $zero, L_800BA188
    if (ctx->r1 != 0) {
        // 0x800BA264: nop
    
            goto L_800BA188;
    }
    // 0x800BA264: nop

L_800BA268:
    // 0x800BA268: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BA26C: lw          $a1, 0x3660($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3660);
    // 0x800BA270: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA274: lhu         $t9, 0x14($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X14);
    // 0x800BA278: addiu       $a0, $a0, -0x59A4
    ctx->r4 = ADD32(ctx->r4, -0X59A4);
    // 0x800BA27C: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA280: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800BA284: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800BA288: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BA28C: addiu       $a3, $a3, -0x59B0
    ctx->r7 = ADD32(ctx->r7, -0X59B0);
    // 0x800BA290: addiu       $t0, $t0, 0x35D8
    ctx->r8 = ADD32(ctx->r8, 0X35D8);
    // 0x800BA294: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800BA298: mflo        $t7
    ctx->r15 = lo;
    // 0x800BA29C: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x800BA2A0: bgez        $v0, L_800BA2B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800BA2A4: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_800BA2B0;
    }
    // 0x800BA2A4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800BA2A8: b           L_800BA2DC
    // 0x800BA2AC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_800BA2DC;
    // 0x800BA2AC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800BA2B0:
    // 0x800BA2B0: lhu         $v1, 0x12($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X12);
    // 0x800BA2B4: nop

    // 0x800BA2B8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BA2BC: bne         $at, $zero, L_800BA2DC
    if (ctx->r1 != 0) {
        // 0x800BA2C0: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_800BA2DC;
    }
    // 0x800BA2C0: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
L_800BA2C4:
    // 0x800BA2C4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800BA2C8: lhu         $v1, 0x12($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X12);
    // 0x800BA2CC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800BA2D0: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BA2D4: beq         $at, $zero, L_800BA2C4
    if (ctx->r1 == 0) {
        // 0x800BA2D8: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_800BA2C4;
    }
    // 0x800BA2D8: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
L_800BA2DC:
    // 0x800BA2DC: lw          $t8, 0x38($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X38);
    // 0x800BA2E0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BA2E4: multu       $t8, $s1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA2E8: addiu       $t2, $t2, -0x59BC
    ctx->r10 = ADD32(ctx->r10, -0X59BC);
    // 0x800BA2EC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800BA2F0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BA2F4: lw          $t8, -0x59AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X59AC);
    // 0x800BA2F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BA2FC: addiu       $v0, $v0, -0x59B8
    ctx->r2 = ADD32(ctx->r2, -0X59B8);
    // 0x800BA300: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800BA304: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BA308: addiu       $a1, $a1, -0x59B4
    ctx->r5 = ADD32(ctx->r5, -0X59B4);
    // 0x800BA30C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BA310: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BA314: mflo        $t7
    ctx->r15 = lo;
    // 0x800BA318: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800BA31C: lw          $t6, 0x3C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X3C);
    // 0x800BA320: and         $t7, $t9, $t8
    ctx->r15 = ctx->r25 & ctx->r24;
    // 0x800BA324: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA328: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800BA32C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x800BA330: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BA334: lw          $t6, -0x59A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X59A8);
    // 0x800BA338: mflo        $t9
    ctx->r25 = lo;
    // 0x800BA33C: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800BA340: and         $a2, $t7, $t6
    ctx->r6 = ctx->r15 & ctx->r14;
    // 0x800BA344: bltz        $a0, L_800BA3B0
    if (SIGNED(ctx->r4) < 0) {
        // 0x800BA348: sw          $a2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r6;
            goto L_800BA3B0;
    }
    // 0x800BA348: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_800BA34C:
    // 0x800BA34C: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x800BA350: bltz        $a0, L_800BA394
    if (SIGNED(ctx->r4) < 0) {
        // 0x800BA354: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_800BA394;
    }
    // 0x800BA354: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800BA358: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
L_800BA35C:
    // 0x800BA35C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BA360: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800BA364: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA368: sh          $v1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r3;
    // 0x800BA36C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800BA370: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BA374: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x800BA378: sh          $a2, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r6;
    // 0x800BA37C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800BA380: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800BA384: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800BA388: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BA38C: beq         $at, $zero, L_800BA35C
    if (ctx->r1 == 0) {
        // 0x800BA390: addu        $v1, $v1, $t8
        ctx->r3 = ADD32(ctx->r3, ctx->r24);
            goto L_800BA35C;
    }
    // 0x800BA390: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
L_800BA394:
    // 0x800BA394: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800BA398: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BA39C: slt         $at, $a0, $s2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800BA3A0: beq         $at, $zero, L_800BA34C
    if (ctx->r1 == 0) {
        // 0x800BA3A4: addu        $a2, $a2, $t7
        ctx->r6 = ADD32(ctx->r6, ctx->r15);
            goto L_800BA34C;
    }
    // 0x800BA3A4: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA3A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BA3AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800BA3B0:
    // 0x800BA3B0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BA3B4: lw          $t6, -0x59C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X59C8);
    // 0x800BA3B8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800BA3BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BA3C0: beq         $t6, $at, L_800BA3D0
    if (ctx->r14 == ctx->r1) {
        // 0x800BA3C4: addiu       $t0, $t0, 0x35D8
        ctx->r8 = ADD32(ctx->r8, 0X35D8);
            goto L_800BA3D0;
    }
    // 0x800BA3C4: addiu       $t0, $t0, 0x35D8
    ctx->r8 = ADD32(ctx->r8, 0X35D8);
    // 0x800BA3C8: b           L_800BA3D4
    // 0x800BA3CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_800BA3D4;
    // 0x800BA3CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800BA3D0:
    // 0x800BA3D0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
L_800BA3D4:
    // 0x800BA3D4: addiu       $ra, $a0, 0x1
    ctx->r31 = ADD32(ctx->r4, 0X1);
    // 0x800BA3D8: blez        $a0, L_800BA658
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BA3DC: sw          $ra, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r31;
            goto L_800BA658;
    }
    // 0x800BA3DC: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800BA3E0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800BA3E4: addiu       $a2, $a2, 0x3610
    ctx->r6 = ADD32(ctx->r6, 0X3610);
L_800BA3E8:
    // 0x800BA3E8: blez        $a0, L_800BA63C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BA3EC: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_800BA63C;
    }
    // 0x800BA3EC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_800BA3F0:
    // 0x800BA3F0: blez        $t2, L_800BA624
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800BA3F4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800BA624;
    }
    // 0x800BA3F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BA3F8: sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16 << 4);
    // 0x800BA3FC: sll         $a0, $t5, 2
    ctx->r4 = S32(ctx->r13 << 2);
    // 0x800BA400: sll         $a1, $ra, 2
    ctx->r5 = S32(ctx->r31 << 2);
L_800BA404:
    // 0x800BA404: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BA408: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800BA40C: addu        $t7, $t8, $a0
    ctx->r15 = ADD32(ctx->r24, ctx->r4);
    // 0x800BA410: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x800BA414: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800BA418: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800BA41C: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x800BA420: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800BA424: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800BA428: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BA42C: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800BA430: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
    // 0x800BA434: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BA438: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BA43C: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x800BA440: lh          $t6, 0x6($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X6);
    // 0x800BA444: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA448: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800BA44C: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA450: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BA454: nop

    // 0x800BA458: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA45C: sh          $t6, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r14;
    // 0x800BA460: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BA464: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BA468: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800BA46C: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x800BA470: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA474: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA478: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800BA47C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA480: nop

    // 0x800BA484: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA488: sh          $t6, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r14;
    // 0x800BA48C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BA490: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800BA494: addu        $t7, $t8, $a1
    ctx->r15 = ADD32(ctx->r24, ctx->r5);
    // 0x800BA498: lh          $t6, 0x2($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X2);
    // 0x800BA49C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800BA4A0: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800BA4A4: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800BA4A8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800BA4AC: nop

    // 0x800BA4B0: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800BA4B4: sh          $t6, 0xA($t7)
    MEM_H(0XA, ctx->r15) = ctx->r14;
    // 0x800BA4B8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BA4BC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BA4C0: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x800BA4C4: lh          $t6, 0x4($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X4);
    // 0x800BA4C8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA4CC: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800BA4D0: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA4D4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BA4D8: nop

    // 0x800BA4DC: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA4E0: sh          $t6, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r14;
    // 0x800BA4E4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BA4E8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BA4EC: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800BA4F0: lh          $t6, 0x6($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X6);
    // 0x800BA4F4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA4F8: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA4FC: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800BA500: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA504: nop

    // 0x800BA508: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA50C: sh          $t6, 0xE($t9)
    MEM_H(0XE, ctx->r25) = ctx->r14;
    // 0x800BA510: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BA514: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800BA518: addu        $t7, $t8, $a0
    ctx->r15 = ADD32(ctx->r24, ctx->r4);
    // 0x800BA51C: lh          $t6, 0x4($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X4);
    // 0x800BA520: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800BA524: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800BA528: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800BA52C: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800BA530: nop

    // 0x800BA534: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800BA538: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800BA53C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BA540: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BA544: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x800BA548: lh          $t6, 0x6($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X6);
    // 0x800BA54C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA550: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800BA554: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA558: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BA55C: nop

    // 0x800BA560: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA564: sh          $t6, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r14;
    // 0x800BA568: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BA56C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BA570: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800BA574: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x800BA578: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA57C: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA580: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800BA584: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA588: nop

    // 0x800BA58C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA590: sh          $t6, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r14;
    // 0x800BA594: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800BA598: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800BA59C: addu        $t7, $t8, $a1
    ctx->r15 = ADD32(ctx->r24, ctx->r5);
    // 0x800BA5A0: lh          $t6, 0x6($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X6);
    // 0x800BA5A4: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800BA5A8: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800BA5AC: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800BA5B0: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800BA5B4: nop

    // 0x800BA5B8: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x800BA5BC: sh          $t6, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r14;
    // 0x800BA5C0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BA5C4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BA5C8: addu        $t8, $t9, $a1
    ctx->r24 = ADD32(ctx->r25, ctx->r5);
    // 0x800BA5CC: lh          $t6, 0x4($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X4);
    // 0x800BA5D0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800BA5D4: addu        $t8, $a2, $t9
    ctx->r24 = ADD32(ctx->r6, ctx->r25);
    // 0x800BA5D8: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x800BA5DC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BA5E0: nop

    // 0x800BA5E4: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800BA5E8: sh          $t6, 0x1C($t8)
    MEM_H(0X1C, ctx->r24) = ctx->r14;
    // 0x800BA5EC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BA5F0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BA5F4: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800BA5F8: lh          $t6, 0x6($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X6);
    // 0x800BA5FC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BA600: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x800BA604: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x800BA608: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800BA60C: nop

    // 0x800BA610: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BA614: bne         $a3, $t2, L_800BA404
    if (ctx->r7 != ctx->r10) {
        // 0x800BA618: sh          $t6, 0x1E($t9)
        MEM_H(0X1E, ctx->r25) = ctx->r14;
            goto L_800BA404;
    }
    // 0x800BA618: sh          $t6, 0x1E($t9)
    MEM_H(0X1E, ctx->r25) = ctx->r14;
    // 0x800BA61C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800BA620: nop

L_800BA624:
    // 0x800BA624: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800BA628: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BA62C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800BA630: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BA634: bne         $at, $zero, L_800BA3F0
    if (ctx->r1 != 0) {
        // 0x800BA638: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_800BA3F0;
    }
    // 0x800BA638: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800BA63C:
    // 0x800BA63C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BA640: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BA644: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800BA648: bne         $at, $zero, L_800BA3E8
    if (ctx->r1 != 0) {
        // 0x800BA64C: addiu       $ra, $ra, 0x1
        ctx->r31 = ADD32(ctx->r31, 0X1);
            goto L_800BA3E8;
    }
    // 0x800BA64C: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BA650: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x800BA654: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_800BA658:
    // 0x800BA658: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800BA65C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BA660: addiu       $t8, $t8, 0x3620
    ctx->r24 = ADD32(ctx->r24, 0X3620);
    // 0x800BA664: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x800BA668: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800BA66C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800BA670: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x800BA674: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA678: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800BA67C: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x800BA680: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x800BA684: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800BA688: addu        $a2, $v1, $t2
    ctx->r6 = ADD32(ctx->r3, ctx->r10);
    // 0x800BA68C: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x800BA690: mflo        $a3
    ctx->r7 = lo;
    // 0x800BA694: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x800BA698: addu        $a1, $v1, $t8
    ctx->r5 = ADD32(ctx->r3, ctx->r24);
    // 0x800BA69C: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x800BA6A0: nop

    // 0x800BA6A4: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x800BA6A8: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x800BA6AC: nop

    // 0x800BA6B0: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800BA6B4: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800BA6B8: nop

    // 0x800BA6BC: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
    // 0x800BA6C0: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800BA6C4: nop

    // 0x800BA6C8: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x800BA6CC: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x800BA6D0: nop

    // 0x800BA6D4: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
    // 0x800BA6D8: lh          $t6, 0x2($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X2);
    // 0x800BA6DC: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x800BA6E0: sh          $t6, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r14;
    // 0x800BA6E4: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x800BA6E8: addu        $t6, $v1, $t7
    ctx->r14 = ADD32(ctx->r3, ctx->r15);
    // 0x800BA6EC: sh          $t9, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r25;
    // 0x800BA6F0: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x800BA6F4: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x800BA6F8: sh          $t8, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r24;
    // 0x800BA6FC: lh          $t9, 0x0($t4)
    ctx->r25 = MEM_H(ctx->r12, 0X0);
    // 0x800BA700: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BA704: sh          $t9, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r25;
    // 0x800BA708: lh          $t8, 0x2($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X2);
    // 0x800BA70C: nop

    // 0x800BA710: sh          $t8, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r24;
    // 0x800BA714: lw          $t7, 0x3718($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3718);
    // 0x800BA718: nop

    // 0x800BA71C: blez        $t7, L_800BA734
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800BA720: nop
    
            goto L_800BA734;
    }
    // 0x800BA720: nop

    // 0x800BA724: jal         0x800C03B8
    // 0x800BA728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BFE98(rdram, ctx);
        goto after_0;
    // 0x800BA728: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800BA72C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BA730: addiu       $t3, $t3, -0x5A78
    ctx->r11 = ADD32(ctx->r11, -0X5A78);
L_800BA734:
    // 0x800BA734: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA738: addiu       $v1, $v1, -0x5318
    ctx->r3 = ADD32(ctx->r3, -0X5318);
    // 0x800BA73C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA740: nop

    // 0x800BA744: blez        $v0, L_800BA790
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BA748: slt         $at, $s1, $v0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800BA790;
    }
    // 0x800BA748: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA74C: beq         $at, $zero, L_800BA780
    if (ctx->r1 == 0) {
        // 0x800BA750: nop
    
            goto L_800BA780;
    }
    // 0x800BA750: nop

    // 0x800BA754: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800BA758: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BA75C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BA760: lwc1        $f8, -0x531C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X531C);
    // 0x800BA764: lwc1        $f16, 0x40($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X40);
    // 0x800BA768: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BA76C: subu        $t6, $v0, $s1
    ctx->r14 = SUB32(ctx->r2, ctx->r17);
    // 0x800BA770: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BA774: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800BA778: b           L_800BA790
    // 0x800BA77C: swc1        $f18, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
        goto L_800BA790;
    // 0x800BA77C: swc1        $f18, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
L_800BA780:
    // 0x800BA780: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BA784: lwc1        $f4, -0x5320($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5320);
    // 0x800BA788: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800BA78C: swc1        $f4, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f4.u32l;
L_800BA790:
    // 0x800BA790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BA794: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BA798: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA79C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800BA7A0: jr          $ra
    // 0x800BA7A4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BA7A4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void waves_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B87D4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800B87D8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B87DC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B87E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B87E4: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800B87E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B87EC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B87F0: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800B87F4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800B87F8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800B87FC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800B8800: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800B8804: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B8808: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B880C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B8810: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B8814: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B8818: sw          $a2, -0x59C8($at)
    MEM_W(-0X59C8, ctx->r1) = ctx->r6;
    // 0x800B881C: jal         0x800B8654
    // 0x800B8820: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    waves_init_header(rdram, ctx);
        goto after_0;
    // 0x800B8820: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800B8824: jal         0x800B83D4
    // 0x800B8828: nop

    waves_alloc(rdram, ctx);
        goto after_1;
    // 0x800B8828: nop

    after_1:
    // 0x800B882C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800B8830: jal         0x800BC2FC
    // 0x800B8834: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800BBDDC(rdram, ctx);
        goto after_2;
    // 0x800B8834: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800B8838: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B883C: lw          $t6, -0x5998($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5998);
    // 0x800B8840: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B8844: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B8848: addiu       $a1, $a1, -0x59A0
    ctx->r5 = ADD32(ctx->r5, -0X59A0);
    // 0x800B884C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B8850: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B8854: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800B8858: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800B885C: lw          $t7, -0x5994($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5994);
    // 0x800B8860: addiu       $s4, $s4, -0x5A78
    ctx->r20 = ADD32(ctx->r20, -0X5A78);
    // 0x800B8864: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8868: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B886C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B8870: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B8874: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B8878: addiu       $a2, $a2, -0x599C
    ctx->r6 = ADD32(ctx->r6, -0X599C);
    // 0x800B887C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B8880: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x800B8884: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800B8888: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800B888C: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800B8890: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800B8894: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B8898: addiu       $s2, $s2, -0x5984
    ctx->r18 = ADD32(ctx->r18, -0X5984);
    // 0x800B889C: addiu       $s1, $s1, -0x5988
    ctx->r17 = ADD32(ctx->r17, -0X5988);
    // 0x800B88A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B88A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B88A8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B88AC: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B88B0: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x800B88B4: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x800B88B8: sw          $zero, -0x59BC($at)
    MEM_W(-0X59BC, ctx->r1) = 0;
    // 0x800B88BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B88C0: lw          $v1, -0x59C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X59C0);
    // 0x800B88C4: sw          $zero, -0x59B8($at)
    MEM_W(-0X59B8, ctx->r1) = 0;
    // 0x800B88C8: lw          $t9, 0x30($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X30);
    // 0x800B88CC: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x800B88D0: nop

    // 0x800B88D4: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B88D8: mflo        $t2
    ctx->r10 = lo;
    // 0x800B88DC: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x800B88E0: nop

    // 0x800B88E4: div         $zero, $t3, $v0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r2)));
    // 0x800B88E8: bne         $v0, $zero, L_800B88F4
    if (ctx->r2 != 0) {
        // 0x800B88EC: nop
    
            goto L_800B88F4;
    }
    // 0x800B88EC: nop

    // 0x800B88F0: break       7
    do_break(2148239600);
L_800B88F4:
    // 0x800B88F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B88F8: bne         $v0, $at, L_800B890C
    if (ctx->r2 != ctx->r1) {
        // 0x800B88FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B890C;
    }
    // 0x800B88FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8900: bne         $t3, $at, L_800B890C
    if (ctx->r11 != ctx->r1) {
        // 0x800B8904: nop
    
            goto L_800B890C;
    }
    // 0x800B8904: nop

    // 0x800B8908: break       6
    do_break(2148239624);
L_800B890C:
    // 0x800B890C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8910: mflo        $t4
    ctx->r12 = lo;
    // 0x800B8914: sw          $t4, -0x59B4($at)
    MEM_W(-0X59B4, ctx->r1) = ctx->r12;
    // 0x800B8918: lw          $t6, 0x34($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X34);
    // 0x800B891C: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x800B8920: nop

    // 0x800B8924: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8928: mflo        $t7
    ctx->r15 = lo;
    // 0x800B892C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x800B8930: nop

    // 0x800B8934: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x800B8938: bne         $v0, $zero, L_800B8944
    if (ctx->r2 != 0) {
        // 0x800B893C: nop
    
            goto L_800B8944;
    }
    // 0x800B893C: nop

    // 0x800B8940: break       7
    do_break(2148239680);
L_800B8944:
    // 0x800B8944: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B8948: bne         $v0, $at, L_800B895C
    if (ctx->r2 != ctx->r1) {
        // 0x800B894C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B895C;
    }
    // 0x800B894C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8950: bne         $t8, $at, L_800B895C
    if (ctx->r24 != ctx->r1) {
        // 0x800B8954: nop
    
            goto L_800B895C;
    }
    // 0x800B8954: nop

    // 0x800B8958: break       6
    do_break(2148239704);
L_800B895C:
    // 0x800B895C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8960: mflo        $t9
    ctx->r25 = lo;
    // 0x800B8964: sw          $t9, -0x59B0($at)
    MEM_W(-0X59B0, ctx->r1) = ctx->r25;
    // 0x800B8968: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x800B896C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8970: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x800B8974: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800B8978: sw          $t4, -0x59AC($at)
    MEM_W(-0X59AC, ctx->r1) = ctx->r12;
    // 0x800B897C: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x800B8980: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8984: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800B8988: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B898C: sw          $t7, -0x59A8($at)
    MEM_W(-0X59A8, ctx->r1) = ctx->r15;
    // 0x800B8990: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8994: sw          $zero, -0x59A4($at)
    MEM_W(-0X59A4, ctx->r1) = 0;
    // 0x800B8998: lw          $t8, 0x8($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X8);
    // 0x800B899C: lw          $a0, 0x20($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X20);
    // 0x800B89A0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800B89A4: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x800B89A8: lw          $t3, 0x14($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X14);
    // 0x800B89AC: lw          $s6, 0x10($s4)
    ctx->r22 = MEM_W(ctx->r20, 0X10);
    // 0x800B89B0: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800B89B4: bne         $a0, $zero, L_800B89C0
    if (ctx->r4 != 0) {
        // 0x800B89B8: nop
    
            goto L_800B89C0;
    }
    // 0x800B89B8: nop

    // 0x800B89BC: break       7
    do_break(2148239804);
L_800B89C0:
    // 0x800B89C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B89C4: bne         $a0, $at, L_800B89D8
    if (ctx->r4 != ctx->r1) {
        // 0x800B89C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B89D8;
    }
    // 0x800B89C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B89CC: bne         $t9, $at, L_800B89D8
    if (ctx->r25 != ctx->r1) {
        // 0x800B89D0: nop
    
            goto L_800B89D8;
    }
    // 0x800B89D0: nop

    // 0x800B89D4: break       6
    do_break(2148239828);
L_800B89D8:
    // 0x800B89D8: lw          $fp, 0x1C($s4)
    ctx->r30 = MEM_W(ctx->r20, 0X1C);
    // 0x800B89DC: mflo        $t2
    ctx->r10 = lo;
    // 0x800B89E0: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800B89E4: nop

    // 0x800B89E8: div         $zero, $t4, $a0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r4)));
    // 0x800B89EC: bne         $a0, $zero, L_800B89F8
    if (ctx->r4 != 0) {
        // 0x800B89F0: nop
    
            goto L_800B89F8;
    }
    // 0x800B89F0: nop

    // 0x800B89F4: break       7
    do_break(2148239860);
L_800B89F8:
    // 0x800B89F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B89FC: bne         $a0, $at, L_800B8A10
    if (ctx->r4 != ctx->r1) {
        // 0x800B8A00: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B8A10;
    }
    // 0x800B8A00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8A04: bne         $t4, $at, L_800B8A10
    if (ctx->r12 != ctx->r1) {
        // 0x800B8A08: nop
    
            goto L_800B8A10;
    }
    // 0x800B8A08: nop

    // 0x800B8A0C: break       6
    do_break(2148239884);
L_800B8A10:
    // 0x800B8A10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B8A14: lwc1        $f10, -0x67E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X67E0);
    // 0x800B8A18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8A1C: swc1        $f10, -0x5A24($at)
    MEM_W(-0X5A24, ctx->r1) = ctx->f10.u32l;
    // 0x800B8A20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B8A24: lwc1        $f16, -0x67DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X67DC);
    // 0x800B8A28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8A2C: swc1        $f16, -0x5A20($at)
    MEM_W(-0X5A20, ctx->r1) = ctx->f16.u32l;
    // 0x800B8A30: mflo        $t5
    ctx->r13 = lo;
    // 0x800B8A34: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800B8A38: blez        $a0, L_800B8B38
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B8A3C: lui         $s5, 0x800E
        ctx->r21 = S32(0X800E << 16);
            goto L_800B8B38;
    }
    // 0x800B8A3C: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800B8A40: addiu       $s5, $s5, 0x35D0
    ctx->r21 = ADD32(ctx->r21, 0X35D0);
    // 0x800B8A44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B8A48:
    // 0x800B8A48: sll         $a0, $s6, 16
    ctx->r4 = S32(ctx->r22 << 16);
    // 0x800B8A4C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B8A50: jal         0x80070A04
    // 0x800B8A54: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x800B8A54: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_3:
    // 0x800B8A58: sll         $a0, $fp, 16
    ctx->r4 = S32(ctx->r30 << 16);
    // 0x800B8A5C: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B8A60: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800B8A64: jal         0x80070A04
    // 0x800B8A68: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_4;
    // 0x800B8A68: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_4:
    // 0x800B8A6C: lwc1        $f18, 0x18($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X18);
    // 0x800B8A70: lwc1        $f6, 0xC($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800B8A74: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800B8A78: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800B8A7C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B8A80: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800B8A84: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800B8A88: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B8A8C: addiu       $v1, $v1, -0x5A24
    ctx->r3 = ADD32(ctx->r3, -0X5A24);
    // 0x800B8A90: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B8A94: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x800B8A98: lw          $t2, 0x28($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X28);
    // 0x800B8A9C: nop

    // 0x800B8AA0: beq         $t2, $zero, L_800B8AC4
    if (ctx->r10 == 0) {
        // 0x800B8AA4: nop
    
            goto L_800B8AC4;
    }
    // 0x800B8AA4: nop

    // 0x800B8AA8: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x800B8AAC: nop

    // 0x800B8AB0: addu        $v0, $t3, $s0
    ctx->r2 = ADD32(ctx->r11, ctx->r16);
    // 0x800B8AB4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B8AB8: nop

    // 0x800B8ABC: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B8AC0: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_800B8AC4:
    // 0x800B8AC4: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x800B8AC8: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B8ACC: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x800B8AD0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B8AD4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B8AD8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800B8ADC: nop

    // 0x800B8AE0: bc1f        L_800B8AF4
    if (!c1cs) {
        // 0x800B8AE4: nop
    
            goto L_800B8AF4;
    }
    // 0x800B8AE4: nop

    // 0x800B8AE8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800B8AEC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B8AF0: nop

L_800B8AF4:
    // 0x800B8AF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B8AF8: addiu       $v0, $v0, -0x5A20
    ctx->r2 = ADD32(ctx->r2, -0X5A20);
    // 0x800B8AFC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B8B00: nop

    // 0x800B8B04: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800B8B08: nop

    // 0x800B8B0C: bc1f        L_800B8B18
    if (!c1cs) {
        // 0x800B8B10: nop
    
            goto L_800B8B18;
    }
    // 0x800B8B10: nop

    // 0x800B8B14: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800B8B18:
    // 0x800B8B18: lw          $t7, 0x20($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X20);
    // 0x800B8B1C: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800B8B20: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800B8B24: slt         $at, $s7, $t7
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B8B28: addu        $s6, $s6, $t5
    ctx->r22 = ADD32(ctx->r22, ctx->r13);
    // 0x800B8B2C: bne         $at, $zero, L_800B8A48
    if (ctx->r1 != 0) {
        // 0x800B8B30: addu        $fp, $fp, $t6
        ctx->r30 = ADD32(ctx->r30, ctx->r14);
            goto L_800B8A48;
    }
    // 0x800B8B30: addu        $fp, $fp, $t6
    ctx->r30 = ADD32(ctx->r30, ctx->r14);
    // 0x800B8B34: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_800B8B38:
    // 0x800B8B38: jal         0x8006FB58
    // 0x800B8B3C: nop

    save_rng_seed(rdram, ctx);
        goto after_5;
    // 0x800B8B3C: nop

    after_5:
    // 0x800B8B40: lui         $a0, 0x5741
    ctx->r4 = S32(0X5741 << 16);
    // 0x800B8B44: jal         0x8006FB4C
    // 0x800B8B48: ori         $a0, $a0, 0x5646
    ctx->r4 = ctx->r4 | 0X5646;
    set_rng_seed(rdram, ctx);
        goto after_6;
    // 0x800B8B48: ori         $a0, $a0, 0x5646
    ctx->r4 = ctx->r4 | 0X5646;
    after_6:
    // 0x800B8B4C: lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X4);
    // 0x800B8B50: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B8B54: blez        $v1, L_800B8BD8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B8B58: nop
    
            goto L_800B8BD8;
    }
    // 0x800B8B58: nop

    // 0x800B8B5C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800B8B60: addiu       $fp, $fp, 0x35D4
    ctx->r30 = ADD32(ctx->r30, 0X35D4);
L_800B8B64:
    // 0x800B8B64: blez        $v1, L_800B8BC0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B8B68: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B8BC0;
    }
    // 0x800B8B68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B8B6C: sll         $s6, $s5, 2
    ctx->r22 = S32(ctx->r21 << 2);
L_800B8B70:
    // 0x800B8B70: lw          $a1, 0x20($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X20);
    // 0x800B8B74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8B78: jal         0x8006FB8C
    // 0x800B8B7C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800B8B7C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_7:
    // 0x800B8B80: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B8B84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8B88: addu        $t9, $t8, $s6
    ctx->r25 = ADD32(ctx->r24, ctx->r22);
    // 0x800B8B8C: sh          $v0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r2;
    // 0x800B8B90: lw          $a1, 0x20($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X20);
    // 0x800B8B94: jal         0x8006FB8C
    // 0x800B8B98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_8;
    // 0x800B8B98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_8:
    // 0x800B8B9C: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800B8BA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8BA4: addu        $t3, $t2, $s6
    ctx->r11 = ADD32(ctx->r10, ctx->r22);
    // 0x800B8BA8: sh          $v0, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r2;
    // 0x800B8BAC: lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X4);
    // 0x800B8BB0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800B8BB4: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B8BB8: bne         $at, $zero, L_800B8B70
    if (ctx->r1 != 0) {
        // 0x800B8BBC: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800B8B70;
    }
    // 0x800B8BBC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800B8BC0:
    // 0x800B8BC0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B8BC4: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B8BC8: bne         $at, $zero, L_800B8B64
    if (ctx->r1 != 0) {
        // 0x800B8BCC: nop
    
            goto L_800B8B64;
    }
    // 0x800B8BCC: nop

    // 0x800B8BD0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B8BD4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_800B8BD8:
    // 0x800B8BD8: jal         0x8006FB6C
    // 0x800B8BDC: nop

    load_rng_seed(rdram, ctx);
        goto after_9;
    // 0x800B8BDC: nop

    after_9:
    // 0x800B8BE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B8BE4: beq         $s3, $at, L_800B8BF4
    if (ctx->r19 == ctx->r1) {
        // 0x800B8BE8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800B8BF4;
    }
    // 0x800B8BE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B8BEC: b           L_800B8BF8
    // 0x800B8BF0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
        goto L_800B8BF8;
    // 0x800B8BF0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_800B8BF4:
    // 0x800B8BF4: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_800B8BF8:
    // 0x800B8BF8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B8BFC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800B8C00: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8C04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B8C08: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_800B8C0C:
    // 0x800B8C0C: bltz        $v0, L_800B8D80
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B8C10: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800B8D80;
    }
    // 0x800B8C10: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800B8C14:
    // 0x800B8C14: bltz        $v0, L_800B8D6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B8C18: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B8D6C;
    }
    // 0x800B8C18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B8C1C:
    // 0x800B8C1C: blez        $s3, L_800B8D5C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800B8C20: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B8D5C;
    }
    // 0x800B8C20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8C24: mtc1        $s0, $f20
    ctx->f20.u32l = ctx->r16;
    // 0x800B8C28: mtc1        $s7, $f18
    ctx->f18.u32l = ctx->r23;
    // 0x800B8C2C: cvt.s.w     $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = CVT_S_W(ctx->f20.u32l);
    // 0x800B8C30: sll         $v1, $s5, 2
    ctx->r3 = S32(ctx->r21 << 2);
    // 0x800B8C34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B8C38: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B8C3C: addu        $v1, $v1, $s5
    ctx->r3 = ADD32(ctx->r3, ctx->r21);
    // 0x800B8C40: addiu       $v0, $v0, 0x3600
    ctx->r2 = ADD32(ctx->r2, 0X3600);
    // 0x800B8C44: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_800B8C48:
    // 0x800B8C48: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800B8C4C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B8C50: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800B8C54: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800B8C58: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B8C5C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800B8C60: add.d       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f18.d + ctx->f0.d;
    // 0x800B8C64: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B8C68: nop

    // 0x800B8C6C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B8C70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B8C74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B8C78: nop

    // 0x800B8C7C: cvt.w.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_D(ctx->f6.d);
    // 0x800B8C80: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800B8C84: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B8C88: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x800B8C8C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x800B8C90: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B8C94: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800B8C98: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x800B8C9C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800B8CA0: add.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f16.d + ctx->f0.d;
    // 0x800B8CA4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B8CA8: nop

    // 0x800B8CAC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B8CB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B8CB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B8CB8: nop

    // 0x800B8CBC: cvt.w.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_D(ctx->f18.d);
    // 0x800B8CC0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800B8CC4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B8CC8: sh          $t9, 0x4($t3)
    MEM_H(0X4, ctx->r11) = ctx->r25;
    // 0x800B8CCC: lw          $t4, 0x4C($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X4C);
    // 0x800B8CD0: nop

    // 0x800B8CD4: bne         $t4, $zero, L_800B8D10
    if (ctx->r12 != 0) {
        // 0x800B8CD8: nop
    
            goto L_800B8D10;
    }
    // 0x800B8CD8: nop

    // 0x800B8CDC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B8CE0: nop

    // 0x800B8CE4: addu        $t5, $t6, $v1
    ctx->r13 = ADD32(ctx->r14, ctx->r3);
    // 0x800B8CE8: sb          $a1, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r5;
    // 0x800B8CEC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B8CF0: nop

    // 0x800B8CF4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800B8CF8: sb          $a1, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r5;
    // 0x800B8CFC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B8D00: nop

    // 0x800B8D04: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x800B8D08: b           L_800B8D40
    // 0x800B8D0C: sb          $a1, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r5;
        goto L_800B8D40;
    // 0x800B8D0C: sb          $a1, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r5;
L_800B8D10:
    // 0x800B8D10: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800B8D14: nop

    // 0x800B8D18: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800B8D1C: sb          $zero, 0x6($t4)
    MEM_B(0X6, ctx->r12) = 0;
    // 0x800B8D20: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B8D24: nop

    // 0x800B8D28: addu        $t5, $t6, $v1
    ctx->r13 = ADD32(ctx->r14, ctx->r3);
    // 0x800B8D2C: sb          $zero, 0x7($t5)
    MEM_B(0X7, ctx->r13) = 0;
    // 0x800B8D30: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B8D34: nop

    // 0x800B8D38: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800B8D3C: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
L_800B8D40:
    // 0x800B8D40: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B8D44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B8D48: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x800B8D4C: bne         $a0, $s3, L_800B8C48
    if (ctx->r4 != ctx->r19) {
        // 0x800B8D50: sb          $a1, 0x9($t9)
        MEM_B(0X9, ctx->r25) = ctx->r5;
            goto L_800B8C48;
    }
    // 0x800B8D50: sb          $a1, 0x9($t9)
    MEM_B(0X9, ctx->r25) = ctx->r5;
    // 0x800B8D54: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8D58: nop

L_800B8D5C:
    // 0x800B8D5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8D60: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800B8D64: beq         $at, $zero, L_800B8C1C
    if (ctx->r1 == 0) {
        // 0x800B8D68: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800B8C1C;
    }
    // 0x800B8D68: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_800B8D6C:
    // 0x800B8D6C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B8D70: slt         $at, $v0, $s7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x800B8D74: beq         $at, $zero, L_800B8C14
    if (ctx->r1 == 0) {
        // 0x800B8D78: nop
    
            goto L_800B8C14;
    }
    // 0x800B8D78: nop

    // 0x800B8D7C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_800B8D80:
    // 0x800B8D80: slti        $at, $a2, 0x19
    ctx->r1 = SIGNED(ctx->r6) < 0X19 ? 1 : 0;
    // 0x800B8D84: bne         $at, $zero, L_800B8C0C
    if (ctx->r1 != 0) {
        // 0x800B8D88: nop
    
            goto L_800B8C0C;
    }
    // 0x800B8D88: nop

    // 0x800B8D8C: blez        $v0, L_800B8E80
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B8D90: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800B8E80;
    }
    // 0x800B8D90: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B8D94: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
L_800B8D98:
    // 0x800B8D98: blez        $v0, L_800B8E70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B8D9C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800B8E70;
    }
    // 0x800B8D9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B8DA0:
    // 0x800B8DA0: blez        $s3, L_800B8E60
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800B8DA4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B8E60;
    }
    // 0x800B8DA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8DA8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B8DAC: addiu       $v1, $v1, 0x3610
    ctx->r3 = ADD32(ctx->r3, 0X3610);
    // 0x800B8DB0: addiu       $a1, $s0, 0x1
    ctx->r5 = ADD32(ctx->r16, 0X1);
    // 0x800B8DB4: sll         $v0, $s5, 4
    ctx->r2 = S32(ctx->r21 << 4);
L_800B8DB8:
    // 0x800B8DB8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800B8DBC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B8DC0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800B8DC4: sb          $a2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r6;
    // 0x800B8DC8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B8DCC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B8DD0: addu        $t5, $t6, $v0
    ctx->r13 = ADD32(ctx->r14, ctx->r2);
    // 0x800B8DD4: sb          $s0, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r16;
    // 0x800B8DD8: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800B8DDC: lw          $t9, -0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, -0X4);
    // 0x800B8DE0: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800B8DE4: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x800B8DE8: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800B8DEC: sb          $t2, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r10;
    // 0x800B8DF0: lw          $t4, -0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, -0X4);
    // 0x800B8DF4: addiu       $s5, $s5, 0x0
    ctx->r21 = ADD32(ctx->r21, 0X0);
    // 0x800B8DF8: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800B8DFC: sb          $a1, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r5;
    // 0x800B8E00: lw          $t5, -0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, -0X4);
    // 0x800B8E04: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800B8E08: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800B8E0C: sb          $a2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r6;
    // 0x800B8E10: lw          $t8, -0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X4);
    // 0x800B8E14: nop

    // 0x800B8E18: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800B8E1C: sb          $a1, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r5;
    // 0x800B8E20: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800B8E24: lw          $t6, -0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X4);
    // 0x800B8E28: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800B8E2C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B8E30: addu        $t5, $t6, $v0
    ctx->r13 = ADD32(ctx->r14, ctx->r2);
    // 0x800B8E34: sb          $t4, 0x2($t5)
    MEM_B(0X2, ctx->r13) = ctx->r12;
    // 0x800B8E38: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800B8E3C: lw          $t2, -0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, -0X4);
    // 0x800B8E40: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800B8E44: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x800B8E48: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800B8E4C: sb          $t9, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r25;
    // 0x800B8E50: bne         $a0, $s3, L_800B8DB8
    if (ctx->r4 != ctx->r19) {
        // 0x800B8E54: addiu       $v0, $v0, -0x10
        ctx->r2 = ADD32(ctx->r2, -0X10);
            goto L_800B8DB8;
    }
    // 0x800B8E54: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // 0x800B8E58: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8E5C: nop

L_800B8E60:
    // 0x800B8E60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B8E64: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B8E68: bne         $at, $zero, L_800B8DA0
    if (ctx->r1 != 0) {
        // 0x800B8E6C: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_800B8DA0;
    }
    // 0x800B8E6C: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
L_800B8E70:
    // 0x800B8E70: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800B8E74: slt         $at, $s7, $v0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B8E78: bne         $at, $zero, L_800B8D98
    if (ctx->r1 != 0) {
        // 0x800B8E7C: nop
    
            goto L_800B8D98;
    }
    // 0x800B8E7C: nop

L_800B8E80:
    // 0x800B8E80: jal         0x800BCBE8
    // 0x800B8E84: nop

    func_800BC6C8(rdram, ctx);
        goto after_10;
    // 0x800B8E84: nop

    after_10:
    // 0x800B8E88: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800B8E8C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B8E90: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800B8E94: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8E98: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800B8E9C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B8EA0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B8EA4: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800B8EA8: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800B8EAC: addiu       $t1, $t1, 0x3608
    ctx->r9 = ADD32(ctx->r9, 0X3608);
    // 0x800B8EB0: addiu       $a3, $a3, 0x3600
    ctx->r7 = ADD32(ctx->r7, 0X3600);
    // 0x800B8EB4: addiu       $a0, $a0, -0x5A18
    ctx->r4 = ADD32(ctx->r4, -0X5A18);
    // 0x800B8EB8: mflo        $s5
    ctx->r21 = lo;
    // 0x800B8EBC: sll         $v1, $s5, 2
    ctx->r3 = S32(ctx->r21 << 2);
    // 0x800B8EC0: addu        $v1, $v1, $s5
    ctx->r3 = ADD32(ctx->r3, ctx->r21);
    // 0x800B8EC4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_800B8EC8:
    // 0x800B8EC8: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800B8ECC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800B8ED0: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x800B8ED4: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x800B8ED8: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x800B8EDC: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x800B8EE0: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x800B8EE4: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x800B8EE8: lbu         $t7, 0x6($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X6);
    // 0x800B8EEC: addu        $a2, $a1, $v1
    ctx->r6 = ADD32(ctx->r5, ctx->r3);
    // 0x800B8EF0: sb          $t7, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r15;
    // 0x800B8EF4: lbu         $t8, 0x7($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X7);
    // 0x800B8EF8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x800B8EFC: sb          $t8, -0x21($a0)
    MEM_B(-0X21, ctx->r4) = ctx->r24;
    // 0x800B8F00: lbu         $t2, 0x8($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X8);
    // 0x800B8F04: nop

    // 0x800B8F08: sb          $t2, -0x20($a0)
    MEM_B(-0X20, ctx->r4) = ctx->r10;
    // 0x800B8F0C: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x800B8F10: nop

    // 0x800B8F14: sb          $t9, -0x1F($a0)
    MEM_B(-0X1F, ctx->r4) = ctx->r25;
    // 0x800B8F18: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800B8F1C: sh          $zero, -0x1C($a0)
    MEM_H(-0X1C, ctx->r4) = 0;
    // 0x800B8F20: sh          $t3, -0x1E($a0)
    MEM_H(-0X1E, ctx->r4) = ctx->r11;
    // 0x800B8F24: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800B8F28: nop

    // 0x800B8F2C: sh          $t6, -0x1A($a0)
    MEM_H(-0X1A, ctx->r4) = ctx->r14;
    // 0x800B8F30: lbu         $t4, 0x6($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X6);
    // 0x800B8F34: nop

    // 0x800B8F38: sb          $t4, -0x18($a0)
    MEM_B(-0X18, ctx->r4) = ctx->r12;
    // 0x800B8F3C: lbu         $t5, 0x7($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X7);
    // 0x800B8F40: nop

    // 0x800B8F44: sb          $t5, -0x17($a0)
    MEM_B(-0X17, ctx->r4) = ctx->r13;
    // 0x800B8F48: lbu         $t7, 0x8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X8);
    // 0x800B8F4C: nop

    // 0x800B8F50: sb          $t7, -0x16($a0)
    MEM_B(-0X16, ctx->r4) = ctx->r15;
    // 0x800B8F54: lbu         $t8, 0x9($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X9);
    // 0x800B8F58: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x800B8F5C: sb          $t8, -0x15($a0)
    MEM_B(-0X15, ctx->r4) = ctx->r24;
    // 0x800B8F60: lh          $t2, 0x0($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X0);
    // 0x800B8F64: sh          $zero, -0x12($a0)
    MEM_H(-0X12, ctx->r4) = 0;
    // 0x800B8F68: sh          $t2, -0x14($a0)
    MEM_H(-0X14, ctx->r4) = ctx->r10;
    // 0x800B8F6C: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x800B8F70: addu        $t7, $t7, $s5
    ctx->r15 = ADD32(ctx->r15, ctx->r21);
    // 0x800B8F74: sh          $t9, -0x10($a0)
    MEM_H(-0X10, ctx->r4) = ctx->r25;
    // 0x800B8F78: lbu         $t3, 0x6($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X6);
    // 0x800B8F7C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800B8F80: sb          $t3, -0xE($a0)
    MEM_B(-0XE, ctx->r4) = ctx->r11;
    // 0x800B8F84: lbu         $t6, 0x7($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X7);
    // 0x800B8F88: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800B8F8C: sb          $t6, -0xD($a0)
    MEM_B(-0XD, ctx->r4) = ctx->r14;
    // 0x800B8F90: lbu         $t4, 0x8($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X8);
    // 0x800B8F94: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x800B8F98: sb          $t4, -0xC($a0)
    MEM_B(-0XC, ctx->r4) = ctx->r12;
    // 0x800B8F9C: lbu         $t5, 0x9($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X9);
    // 0x800B8FA0: nop

    // 0x800B8FA4: sb          $t5, -0xB($a0)
    MEM_B(-0XB, ctx->r4) = ctx->r13;
    // 0x800B8FA8: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800B8FAC: sh          $zero, -0x8($a0)
    MEM_H(-0X8, ctx->r4) = 0;
    // 0x800B8FB0: sh          $t2, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r10;
    // 0x800B8FB4: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800B8FB8: nop

    // 0x800B8FBC: sh          $t9, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r25;
    // 0x800B8FC0: lbu         $t3, 0x6($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X6);
    // 0x800B8FC4: nop

    // 0x800B8FC8: sb          $t3, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r11;
    // 0x800B8FCC: lbu         $t6, 0x7($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X7);
    // 0x800B8FD0: nop

    // 0x800B8FD4: sb          $t6, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r14;
    // 0x800B8FD8: lbu         $t4, 0x8($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X8);
    // 0x800B8FDC: nop

    // 0x800B8FE0: sb          $t4, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r12;
    // 0x800B8FE4: lbu         $t5, 0x9($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X9);
    // 0x800B8FE8: bne         $a3, $t1, L_800B8EC8
    if (ctx->r7 != ctx->r9) {
        // 0x800B8FEC: sb          $t5, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r13;
            goto L_800B8EC8;
    }
    // 0x800B8FEC: sb          $t5, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r13;
    // 0x800B8FF0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800B8FF4: jal         0x800BD190
    // 0x800B8FF8: nop

    func_800BCC70(rdram, ctx);
        goto after_11;
    // 0x800B8FF8: nop

    after_11:
    // 0x800B8FFC: lw          $t7, 0x24($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X24);
    // 0x800B9000: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B9004: bne         $t7, $at, L_800B9030
    if (ctx->r15 != ctx->r1) {
        // 0x800B9008: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_800B9030;
    }
    // 0x800B9008: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800B900C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B9010: addiu       $t8, $t8, 0x3678
    ctx->r24 = ADD32(ctx->r24, 0X3678);
    // 0x800B9014: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9018: sw          $t8, 0x3670($at)
    MEM_W(0X3670, ctx->r1) = ctx->r24;
    // 0x800B901C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B9020: addiu       $t2, $t2, 0x368C
    ctx->r10 = ADD32(ctx->r10, 0X368C);
    // 0x800B9024: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9028: b           L_800B9054
    // 0x800B902C: sw          $t2, 0x3674($at)
    MEM_W(0X3674, ctx->r1) = ctx->r10;
        goto L_800B9054;
    // 0x800B902C: sw          $t2, 0x3674($at)
    MEM_W(0X3674, ctx->r1) = ctx->r10;
L_800B9030:
    // 0x800B9030: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B9034: sw          $t9, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->r25;
    // 0x800B9038: addiu       $t3, $t3, 0x36A0
    ctx->r11 = ADD32(ctx->r11, 0X36A0);
    // 0x800B903C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9040: sw          $t3, 0x3670($at)
    MEM_W(0X3670, ctx->r1) = ctx->r11;
    // 0x800B9044: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B9048: addiu       $t6, $t6, 0x36D4
    ctx->r14 = ADD32(ctx->r14, 0X36D4);
    // 0x800B904C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9050: sw          $t6, 0x3674($at)
    MEM_W(0X3674, ctx->r1) = ctx->r14;
L_800B9054:
    // 0x800B9054: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9058: sw          $zero, 0x3718($at)
    MEM_W(0X3718, ctx->r1) = 0;
    // 0x800B905C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B9060: sw          $zero, -0x5318($at)
    MEM_W(-0X5318, ctx->r1) = 0;
    // 0x800B9064: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B9068: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B906C: sw          $zero, 0x3728($at)
    MEM_W(0X3728, ctx->r1) = 0;
    // 0x800B9070: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B9074: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B9078: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B907C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B9080: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B9084: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B9088: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B908C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B9090: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800B9094: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800B9098: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800B909C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800B90A0: sw          $zero, -0x5A28($at)
    MEM_W(-0X5A28, ctx->r1) = 0;
    // 0x800B90A4: jr          $ra
    // 0x800B90A8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800B90A8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void obj_init_midichset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042054: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80042058: lhu         $t6, 0x8($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X8);
    // 0x8004205C: nop

    // 0x80042060: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80042064: lbu         $t7, 0xA($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA);
    // 0x80042068: nop

    // 0x8004206C: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
    // 0x80042070: lbu         $t8, 0xB($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XB);
    // 0x80042074: jr          $ra
    // 0x80042078: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
    return;
    // 0x80042078: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void racer_sound_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800050D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800050D4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800050D8: lbu         $t6, -0x33C0($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X33C0);
    // 0x800050DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800050E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800050E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800050E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800050EC: beq         $t6, $zero, L_80005244
    if (ctx->r14 == 0) {
        // 0x800050F0: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_80005244;
    }
    // 0x800050F0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800050F4: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x800050F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800050FC: addiu       $v0, $v0, -0x5E44
    ctx->r2 = ADD32(ctx->r2, -0X5E44);
    // 0x80005100: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80005104: lw          $t9, 0x118($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X118);
    // 0x80005108: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000510C: addiu       $a1, $a1, -0x5E48
    ctx->r5 = ADD32(ctx->r5, -0X5E48);
    // 0x80005110: beq         $t9, $zero, L_80005244
    if (ctx->r25 == 0) {
        // 0x80005114: sw          $t9, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r25;
            goto L_80005244;
    }
    // 0x80005114: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80005118: jal         0x8001139C
    // 0x8000511C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x8000511C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80005120: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80005124: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80005128: beq         $v0, $zero, L_8000517C
    if (ctx->r2 == 0) {
        // 0x8000512C: addiu       $a1, $a1, -0x5E48
        ctx->r5 = ADD32(ctx->r5, -0X5E48);
            goto L_8000517C;
    }
    // 0x8000512C: addiu       $a1, $a1, -0x5E48
    ctx->r5 = ADD32(ctx->r5, -0X5E48);
    // 0x80005130: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005134: lw          $t1, -0x5E44($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E44);
    // 0x80005138: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000513C: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x80005140: nop

    // 0x80005144: beq         $a0, $at, L_8000517C
    if (ctx->r4 == ctx->r1) {
        // 0x80005148: nop
    
            goto L_8000517C;
    }
    // 0x80005148: nop

    // 0x8000514C: jal         0x8006A768
    // 0x80005150: nop

    input_held(rdram, ctx);
        goto after_1;
    // 0x80005150: nop

    after_1:
    // 0x80005154: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80005158: lw          $t2, -0x5E44($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E44);
    // 0x8000515C: nop

    // 0x80005160: lh          $a0, 0x0($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X0);
    // 0x80005164: jal         0x8006A794
    // 0x80005168: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x80005168: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x8000516C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80005170: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80005174: addiu       $a1, $a1, -0x5E48
    ctx->r5 = ADD32(ctx->r5, -0X5E48);
    // 0x80005178: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_8000517C:
    // 0x8000517C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80005180: lui         $at, 0xC6FA
    ctx->r1 = S32(0XC6FA << 16);
    // 0x80005184: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x80005188: nop

    // 0x8000518C: bne         $t3, $zero, L_800051B8
    if (ctx->r11 != 0) {
        // 0x80005190: nop
    
            goto L_800051B8;
    }
    // 0x80005190: nop

    // 0x80005194: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80005198: nop

    // 0x8000519C: swc1        $f0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f0.u32l;
    // 0x800051A0: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800051A4: nop

    // 0x800051A8: swc1        $f0, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->f0.u32l;
    // 0x800051AC: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800051B0: b           L_80005244
    // 0x800051B4: swc1        $f0, 0x80($t5)
    MEM_W(0X80, ctx->r13) = ctx->f0.u32l;
        goto L_80005244;
    // 0x800051B4: swc1        $f0, 0x80($t5)
    MEM_W(0X80, ctx->r13) = ctx->f0.u32l;
L_800051B8:
    // 0x800051B8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800051BC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800051C0: swc1        $f4, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f4.u32l;
    // 0x800051C4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800051C8: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800051CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800051D0: swc1        $f6, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->f6.u32l;
    // 0x800051D4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800051D8: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800051DC: nop

    // 0x800051E0: swc1        $f8, 0x80($t7)
    MEM_W(0X80, ctx->r15) = ctx->f8.u32l;
    // 0x800051E4: lw          $t8, -0x5E44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E44);
    // 0x800051E8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800051EC: lb          $v1, 0x1D7($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X1D7);
    // 0x800051F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800051F4: beq         $v1, $at, L_8000520C
    if (ctx->r3 == ctx->r1) {
        // 0x800051F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000520C;
    }
    // 0x800051F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800051FC: beq         $v1, $at, L_80005220
    if (ctx->r3 == ctx->r1) {
        // 0x80005200: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80005220;
    }
    // 0x80005200: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80005204: b           L_80005238
    // 0x80005208: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
        goto L_80005238;
    // 0x80005208: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_8000520C:
    // 0x8000520C: jal         0x80005D08
    // 0x80005210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    racer_sound_hovercraft(rdram, ctx);
        goto after_3;
    // 0x80005210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80005214: b           L_80005248
    // 0x80005218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80005248;
    // 0x80005218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000521C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_80005220:
    // 0x80005220: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80005224: jal         0x800063EC
    // 0x80005228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    racer_sound_plane(rdram, ctx);
        goto after_4;
    // 0x80005228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8000522C: b           L_80005248
    // 0x80005230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80005248;
    // 0x80005230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005234: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_80005238:
    // 0x80005238: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8000523C: jal         0x80005254
    // 0x80005240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    racer_sound_car(rdram, ctx);
        goto after_5;
    // 0x80005240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80005244:
    // 0x80005244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80005248:
    // 0x80005248: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000524C: jr          $ra
    // 0x80005250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80005250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void get_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB80: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006FB84: jr          $ra
    // 0x8006FB88: lw          $v0, -0x265C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X265C);
    return;
    // 0x8006FB88: lw          $v0, -0x265C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X265C);
;}
RECOMP_FUNC void is_in_two_player_adventure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F1C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009F1C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F1CC: jal         0x8009C814
    // 0x8009F1D0: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8009F1D0: nop

    after_0:
    // 0x8009F1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F1D8: beq         $v0, $zero, L_8009F1E8
    if (ctx->r2 == 0) {
        // 0x8009F1DC: nop
    
            goto L_8009F1E8;
    }
    // 0x8009F1DC: nop

    // 0x8009F1E0: b           L_8009F1F4
    // 0x8009F1E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009F1F4;
    // 0x8009F1E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009F1E8:
    // 0x8009F1E8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009F1EC: lw          $v0, -0x5C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C0);
    // 0x8009F1F0: nop

L_8009F1F4:
    // 0x8009F1F4: jr          $ra
    // 0x8009F1F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009F1F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void begin_trophy_race_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F494: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F498: lh          $t6, -0x26FC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X26FC);
    // 0x8006F49C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F4A0: bne         $t6, $zero, L_8006F4CC
    if (ctx->r14 != 0) {
        // 0x8006F4A4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F4CC;
    }
    // 0x8006F4A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F4A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F4AC: jal         0x800C06F8
    // 0x8006F4B0: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F4B0: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    after_0:
    // 0x8006F4B4: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F4B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F4BC: sh          $t7, -0x26FC($at)
    MEM_H(-0X26FC, ctx->r1) = ctx->r15;
    // 0x8006F4C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F4C4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8006F4C8: sb          $t8, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = ctx->r24;
L_8006F4CC:
    // 0x8006F4CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F4D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F4D4: jr          $ra
    // 0x8006F4D8: nop

    return;
    // 0x8006F4D8: nop

;}
RECOMP_FUNC void _doModFunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064AC4: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80064AC8: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80064ACC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80064AD0: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80064AD4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80064AD8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80064ADC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80064AE0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80064AE4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80064AE8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80064AEC: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80064AF0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80064AF4: nop

    // 0x80064AF8: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80064AFC: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80064B00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80064B04: bc1f        L_80064B28
    if (!c1cs) {
        // 0x80064B08: nop
    
            goto L_80064B28;
    }
    // 0x80064B08: nop

    // 0x80064B0C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80064B10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80064B14: nop

    // 0x80064B18: sub.d       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f0.d - ctx->f8.d;
    // 0x80064B1C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80064B20: b           L_80064B30
    // 0x80064B24: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
        goto L_80064B30;
    // 0x80064B24: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
L_80064B28:
    // 0x80064B28: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    // 0x80064B2C: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
L_80064B30:
    // 0x80064B30: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80064B34: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80064B38: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80064B3C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80064B40: bc1f        L_80064B4C
    if (!c1cs) {
        // 0x80064B44: nop
    
            goto L_80064B4C;
    }
    // 0x80064B44: nop

    // 0x80064B48: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80064B4C:
    // 0x80064B4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80064B50: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80064B54: sub.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f4.d - ctx->f8.d;
    // 0x80064B58: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80064B5C: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x80064B60: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80064B64: jr          $ra
    // 0x80064B68: nop

    return;
    // 0x80064B68: nop

;}
RECOMP_FUNC void obj_init_characterflag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035F38: lh          $t6, 0xE($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XE);
    // 0x80035F3C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80035F40: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    // 0x80035F44: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x80035F48: lh          $t9, 0xC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XC);
    // 0x80035F4C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80035F50: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x80035F54: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x80035F58: lh          $t1, 0xA($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XA);
    // 0x80035F5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80035F60: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80035F64: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80035F68: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80035F6C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035F70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035F74: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80035F78: nop

    // 0x80035F7C: bc1f        L_80035F8C
    if (!c1cs) {
        // 0x80035F80: nop
    
            goto L_80035F8C;
    }
    // 0x80035F80: nop

    // 0x80035F84: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80035F88: nop

L_80035F8C:
    // 0x80035F8C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80035F90: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x80035F94: nop

    // 0x80035F98: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80035F9C: nop

    // 0x80035FA0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80035FA4: jr          $ra
    // 0x80035FA8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80035FA8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80070058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070298: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007029C: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x800702A0: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x800702A4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800702A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800702AC: jal         0x80070A70
    // 0x800702B0: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    static_3_80070A70(rdram, ctx);
        goto after_0;
    // 0x800702B0: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_0:
    // 0x800702B4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800702B8: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x800702BC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800702C0: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800702C4: jal         0x80070A6C
    // 0x800702C8: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x800702C8: nop

    after_1:
    // 0x800702CC: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800702D0: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x800702D4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800702D8: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800702DC: jal         0x80070A70
    // 0x800702E0: nop

    static_3_80070A70(rdram, ctx);
        goto after_2;
    // 0x800702E0: nop

    after_2:
    // 0x800702E4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800702E8: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x800702EC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800702F0: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800702F4: jal         0x80070A6C
    // 0x800702F8: nop

    coss_s16(rdram, ctx);
        goto after_3;
    // 0x800702F8: nop

    after_3:
    // 0x800702FC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80070300: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80070304: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80070308: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8007030C: jal         0x80070A70
    // 0x80070310: nop

    static_3_80070A70(rdram, ctx);
        goto after_4;
    // 0x80070310: nop

    after_4:
    // 0x80070314: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80070318: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x8007031C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80070320: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80070324: jal         0x80070A6C
    // 0x80070328: nop

    coss_s16(rdram, ctx);
        goto after_5;
    // 0x80070328: nop

    after_5:
    // 0x8007032C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80070330: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80070334: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x80070338: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007033C: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x80070340: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x80070344: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80070348: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007034C: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80070350: swc1        $f18, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f18.u32l;
    // 0x80070354: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070358: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8007035C: mul.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80070360: nop

    // 0x80070364: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80070368: jr          $ra
    // 0x8007036C: nop

    return;
    // 0x8007036C: nop

;}
RECOMP_FUNC void pakmenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80089A3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80089A40: jal         0x8009CA4C
    // 0x80089A44: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    menu_asset_free(rdram, ctx);
        goto after_0;
    // 0x80089A44: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_0:
    // 0x80089A48: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089A4C: lw          $a0, 0x7060($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7060);
    // 0x80089A50: jal         0x80071380
    // 0x80089A54: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x80089A54: nop

    after_1:
    // 0x80089A58: jal         0x800C478C
    // 0x80089A5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_2;
    // 0x80089A5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80089A60: jal         0x800724D8
    // 0x80089A64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_enable(rdram, ctx);
        goto after_3;
    // 0x80089A64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80089A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80089A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80089A70: jr          $ra
    // 0x80089A74: nop

    return;
    // 0x80089A74: nop

;}
RECOMP_FUNC void __scTaskReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A238: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007A23C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A240: beq         $a0, $zero, L_8007A27C
    if (ctx->r4 == 0) {
        // 0x8007A244: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8007A27C;
    }
    // 0x8007A244: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007A248: jal         0x800D23D0
    // 0x8007A24C: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A24C: nop

    after_0:
    // 0x8007A250: jal         0x800D2410
    // 0x8007A254: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A254: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8007A258: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A25C: nop

    // 0x8007A260: beq         $v0, $t7, L_8007A274
    if (ctx->r2 == ctx->r15) {
        // 0x8007A264: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_8007A274;
    }
    // 0x8007A264: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8007A268: b           L_8007A280
    // 0x8007A26C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007A280;
    // 0x8007A26C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007A270: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_8007A274:
    // 0x8007A274: b           L_8007A284
    // 0x8007A278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8007A284;
    // 0x8007A278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007A27C:
    // 0x8007A27C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007A280:
    // 0x8007A280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007A284:
    // 0x8007A284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007A288: jr          $ra
    // 0x8007A28C: nop

    return;
    // 0x8007A28C: nop

;}
RECOMP_FUNC void fileselect_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E8E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E8E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E8E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E8EC: jal         0x8009C9EC
    // 0x8008E8F0: addiu       $a0, $a0, 0x918
    ctx->r4 = ADD32(ctx->r4, 0X918);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8008E8F0: addiu       $a0, $a0, 0x918
    ctx->r4 = ADD32(ctx->r4, 0X918);
    after_0:
    // 0x8008E8F4: jal         0x800803D8
    // 0x8008E8F8: nop

    menu_button_free(rdram, ctx);
        goto after_1;
    // 0x8008E8F8: nop

    after_1:
    // 0x8008E8FC: jal         0x800C478C
    // 0x8008E900: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_2;
    // 0x8008E900: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x8008E904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E90C: jr          $ra
    // 0x8008E910: nop

    return;
    // 0x8008E910: nop

;}
RECOMP_FUNC void gfxtask_run_xbus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800778A0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800778A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800778A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800778AC: addiu       $v1, $v1, -0x15AC
    ctx->r3 = ADD32(ctx->r3, -0X15AC);
    // 0x800778B0: sw          $t6, -0x15A4($at)
    MEM_W(-0X15A4, ctx->r1) = ctx->r14;
    // 0x800778B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800778B8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800778BC: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800778C0: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800778C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800778C8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800778CC: addiu       $t8, $t8, 0x64E0
    ctx->r24 = ADD32(ctx->r24, 0X64E0);
    // 0x800778D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800778D4: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800778D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800778DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800778E0: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x800778E4: bne         $t9, $at, L_800778F0
    if (ctx->r25 != ctx->r1) {
        // 0x800778E8: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_800778F0;
    }
    // 0x800778E8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800778EC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800778F0:
    // 0x800778F0: subu        $t3, $a1, $a0
    ctx->r11 = SUB32(ctx->r5, ctx->r4);
    // 0x800778F4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800778F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800778FC: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80077900: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80077904: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80077908: addiu       $v1, $v1, -0x75E0
    ctx->r3 = ADD32(ctx->r3, -0X75E0);
    // 0x8007790C: addiu       $t2, $t2, 0x6478
    ctx->r10 = ADD32(ctx->r10, 0X6478);
    // 0x80077910: sw          $t4, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r12;
    // 0x80077914: sw          $t5, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r13;
    // 0x80077918: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007791C: addiu       $t7, $t7, -0x7510
    ctx->r15 = ADD32(ctx->r15, -0X7510);
    // 0x80077920: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80077924: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x80077928: sw          $t2, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r10;
    // 0x8007792C: sw          $t6, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r14;
    // 0x80077930: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x80077934: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80077938: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8007793C: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x80077940: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
    // 0x80077944: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80077948: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x8007794C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80077950: addiu       $t4, $t4, 0x4C40
    ctx->r12 = ADD32(ctx->r12, 0X4C40);
    // 0x80077954: addiu       $t5, $t5, 0x6440
    ctx->r13 = ADD32(ctx->r13, 0X6440);
    // 0x80077958: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007795C: sw          $t8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r24;
    // 0x80077960: addiu       $t9, $t9, -0x5120
    ctx->r25 = ADD32(ctx->r25, -0X5120);
    // 0x80077964: addiu       $t0, $t0, -0x4EE0
    ctx->r8 = ADD32(ctx->r8, -0X4EE0);
    // 0x80077968: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x8007796C: addiu       $t2, $t2, 0x4840
    ctx->r10 = ADD32(ctx->r10, 0X4840);
    // 0x80077970: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x80077974: sw          $t4, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r12;
    // 0x80077978: sw          $t5, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r13;
    // 0x8007797C: addiu       $t6, $t6, 0x7770
    ctx->r14 = ADD32(ctx->r14, 0X7770);
    // 0x80077980: addiu       $t7, $zero, 0xA00
    ctx->r15 = ADD32(0, 0XA00);
    // 0x80077984: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x80077988: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x8007798C: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80077990: sw          $v1, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r3;
    // 0x80077994: sw          $t9, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r25;
    // 0x80077998: sw          $t0, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r8;
    // 0x8007799C: sw          $t1, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r9;
    // 0x800779A0: sw          $t2, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r10;
    // 0x800779A4: sw          $t3, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r11;
    // 0x800779A8: sw          $t6, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r14;
    // 0x800779AC: sw          $t7, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r15;
    // 0x800779B0: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800779B4: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x800779B8: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800779BC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800779C0: lw          $t8, 0x6874($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6874);
    // 0x800779C4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800779C8: sw          $v0, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r2;
    // 0x800779CC: sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
    // 0x800779D0: sw          $t8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r24;
    // 0x800779D4: jal         0x800D1E00
    // 0x800779D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800779D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800779DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800779E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800779E4: lw          $a0, 0x66A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66A0);
    // 0x800779E8: jal         0x800C9390
    // 0x800779EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800779EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800779F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800779F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800779F8: jr          $ra
    // 0x800779FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800779FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
