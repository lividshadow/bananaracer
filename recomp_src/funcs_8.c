#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void transition_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0C44: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0C48: addiu       $v0, $v0, 0x3750
    ctx->r2 = ADD32(ctx->r2, 0X3750);
    // 0x800C0C4C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800C0C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0C54: beq         $a0, $zero, L_800C0C84
    if (ctx->r4 == 0) {
        // 0x800C0C58: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C0C84;
    }
    // 0x800C0C58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0C5C: jal         0x80071380
    // 0x800C0C60: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800C0C60: nop

    after_0:
    // 0x800C0C64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0C68: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0C6C: addiu       $v1, $v1, 0x3758
    ctx->r3 = ADD32(ctx->r3, 0X3758);
    // 0x800C0C70: addiu       $v0, $v0, 0x3750
    ctx->r2 = ADD32(ctx->r2, 0X3750);
    // 0x800C0C74: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C0C78: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C0C7C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C0C80: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_800C0C84:
    // 0x800C0C84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0C8C: sw          $zero, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = 0;
    // 0x800C0C90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0C94: sw          $zero, 0x3760($at)
    MEM_W(0X3760, ctx->r1) = 0;
    // 0x800C0C98: jr          $ra
    // 0x800C0C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C0C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void obj_init_rgbalight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800403E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800403EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800403F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800403F4: jal         0x80031CEC
    // 0x800403F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    light_add_from_level_object_entry(rdram, ctx);
        goto after_0;
    // 0x800403F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800403FC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80040400: nop

    // 0x80040404: sw          $v0, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r2;
    // 0x80040408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004040C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040410: jr          $ra
    // 0x80040414: nop

    return;
    // 0x80040414: nop

;}
RECOMP_FUNC void music_sequence_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002570: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80002574: lw          $t6, -0x3460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3460);
    // 0x80002578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000257C: bne         $a0, $t6, L_800025BC
    if (ctx->r4 != ctx->r14) {
        // 0x80002580: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800025BC;
    }
    // 0x80002580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002584: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002588: lbu         $t7, 0x62C0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X62C0);
    // 0x8000258C: nop

    // 0x80002590: beq         $t7, $zero, L_800025BC
    if (ctx->r15 == 0) {
        // 0x80002594: nop
    
            goto L_800025BC;
    }
    // 0x80002594: nop

    // 0x80002598: jal         0x800C8B30
    // 0x8000259C: nop

    alCSPStop(rdram, ctx);
        goto after_0;
    // 0x8000259C: nop

    after_0:
    // 0x800025A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800025A4: sb          $zero, 0x62C0($at)
    MEM_B(0X62C0, ctx->r1) = 0;
    // 0x800025A8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800025AC: sb          $zero, 0x6284($at)
    MEM_B(0X6284, ctx->r1) = 0;
    // 0x800025B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800025B4: b           L_800025F8
    // 0x800025B8: sb          $zero, -0x3434($at)
    MEM_B(-0X3434, ctx->r1) = 0;
        goto L_800025F8;
    // 0x800025B8: sb          $zero, -0x3434($at)
    MEM_B(-0X3434, ctx->r1) = 0;
L_800025BC:
    // 0x800025BC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800025C0: lw          $t8, -0x345C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X345C);
    // 0x800025C4: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800025C8: bne         $a0, $t8, L_800025FC
    if (ctx->r4 != ctx->r24) {
        // 0x800025CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800025FC;
    }
    // 0x800025CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800025D0: lbu         $t9, 0x62C1($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X62C1);
    // 0x800025D4: nop

    // 0x800025D8: beq         $t9, $zero, L_800025FC
    if (ctx->r25 == 0) {
        // 0x800025DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800025FC;
    }
    // 0x800025DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800025E0: jal         0x800C8B30
    // 0x800025E4: nop

    alCSPStop(rdram, ctx);
        goto after_1;
    // 0x800025E4: nop

    after_1:
    // 0x800025E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800025EC: sb          $zero, 0x62C1($at)
    MEM_B(0X62C1, ctx->r1) = 0;
    // 0x800025F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800025F4: sb          $zero, -0x3430($at)
    MEM_B(-0X3430, ctx->r1) = 0;
L_800025F8:
    // 0x800025F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800025FC:
    // 0x800025FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002600: jr          $ra
    // 0x80002604: nop

    return;
    // 0x80002604: nop

;}
RECOMP_FUNC void alInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8D4C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C8D50: addiu       $v0, $v0, 0x3D10
    ctx->r2 = ADD32(ctx->r2, 0X3D10);
    // 0x800C8D54: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C8D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8D60: bnel        $t6, $zero, L_800C8D74
    if (ctx->r14 != 0) {
        // 0x800C8D64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8D74;
    }
    goto skip_0;
    // 0x800C8D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C8D68: jal         0x80065370
    // 0x800C8D6C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    alSynNew(rdram, ctx);
        goto after_0;
    // 0x800C8D6C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_0:
    // 0x800C8D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8D74:
    // 0x800C8D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8D78: jr          $ra
    // 0x800C8D7C: nop

    return;
    // 0x800C8D7C: nop

;}
RECOMP_FUNC void leveltable_world_level_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B294: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006B298: lw          $a1, 0x16F0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X16F0);
    // 0x8006B29C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006B2A0: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x8006B2A4: sra         $a0, $t6, 24
    ctx->r4 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006B2A8: blez        $a1, L_8006B2E4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006B2AC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006B2E4;
    }
    // 0x8006B2AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006B2B0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006B2B4: sll         $a3, $a1, 2
    ctx->r7 = S32(ctx->r5 << 2);
    // 0x8006B2B8: subu        $a3, $a3, $a1
    ctx->r7 = SUB32(ctx->r7, ctx->r5);
    // 0x8006B2BC: lw          $a2, 0x16FC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X16FC);
    // 0x8006B2C0: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x8006B2C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006B2C8:
    // 0x8006B2C8: lb          $t8, 0x0($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X0);
    // 0x8006B2CC: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8006B2D0: bne         $a0, $t8, L_8006B2DC
    if (ctx->r4 != ctx->r24) {
        // 0x8006B2D4: slt         $at, $v0, $a3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8006B2DC;
    }
    // 0x8006B2D4: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8006B2D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006B2DC:
    // 0x8006B2DC: bne         $at, $zero, L_8006B2C8
    if (ctx->r1 != 0) {
        // 0x8006B2E0: addiu       $a2, $a2, 0x6
        ctx->r6 = ADD32(ctx->r6, 0X6);
            goto L_8006B2C8;
    }
    // 0x8006B2E0: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
L_8006B2E4:
    // 0x8006B2E4: jr          $ra
    // 0x8006B2E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8006B2E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800BBF78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC498: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BC49C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800BC4A0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800BC4A4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800BC4A8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800BC4AC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800BC4B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800BC4B4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800BC4B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800BC4BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800BC4C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BC4C4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800BC4C8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BC4CC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BC4D0: lw          $t7, -0x5A78($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5A78);
    // 0x800BC4D4: lw          $t8, -0x5A50($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5A50);
    // 0x800BC4D8: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800BC4DC: lw          $s4, 0x8($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X8);
    // 0x800BC4E0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800BC4E4: beq         $t8, $zero, L_800BC4F4
    if (ctx->r24 == 0) {
        // 0x800BC4E8: sw          $t7, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r15;
            goto L_800BC4F4;
    }
    // 0x800BC4E8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x800BC4EC: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800BC4F0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_800BC4F4:
    // 0x800BC4F4: lh          $t6, 0x0($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X0);
    // 0x800BC4F8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC4FC: addiu       $v1, $v1, -0x5980
    ctx->r3 = ADD32(ctx->r3, -0X5980);
    // 0x800BC500: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BC504: lh          $t8, 0x6($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X6);
    // 0x800BC508: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BC50C: addiu       $a0, $a0, -0x5978
    ctx->r4 = ADD32(ctx->r4, -0X5978);
    // 0x800BC510: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800BC514: lh          $t7, 0x4($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X4);
    // 0x800BC518: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BC51C: addiu       $a2, $a2, -0x597C
    ctx->r6 = ADD32(ctx->r6, -0X597C);
    // 0x800BC520: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800BC524: lh          $t9, 0xA($s4)
    ctx->r25 = MEM_H(ctx->r20, 0XA);
    // 0x800BC528: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800BC52C: addiu       $t1, $t1, -0x5974
    ctx->r9 = ADD32(ctx->r9, -0X5974);
    // 0x800BC530: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800BC534: lh          $t6, 0x1A($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC538: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x800BC53C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800BC540: bne         $at, $zero, L_800BC5CC
    if (ctx->r1 != 0) {
        // 0x800BC544: lui         $s6, 0x8013
        ctx->r22 = S32(0X8013 << 16);
            goto L_800BC5CC;
    }
    // 0x800BC544: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800BC548: addiu       $s0, $s4, 0xC
    ctx->r16 = ADD32(ctx->r20, 0XC);
L_800BC54C:
    // 0x800BC54C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800BC550: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800BC554: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x800BC558: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800BC55C: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x800BC560: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BC564: beq         $at, $zero, L_800BC570
    if (ctx->r1 == 0) {
        // 0x800BC568: nop
    
            goto L_800BC570;
    }
    // 0x800BC568: nop

    // 0x800BC56C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800BC570:
    // 0x800BC570: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x800BC574: nop

    // 0x800BC578: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BC57C: beq         $at, $zero, L_800BC588
    if (ctx->r1 == 0) {
        // 0x800BC580: nop
    
            goto L_800BC588;
    }
    // 0x800BC580: nop

    // 0x800BC584: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_800BC588:
    // 0x800BC588: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x800BC58C: nop

    // 0x800BC590: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800BC594: beq         $at, $zero, L_800BC5A0
    if (ctx->r1 == 0) {
        // 0x800BC598: nop
    
            goto L_800BC5A0;
    }
    // 0x800BC598: nop

    // 0x800BC59C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800BC5A0:
    // 0x800BC5A0: lh          $v0, 0xA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA);
    // 0x800BC5A4: nop

    // 0x800BC5A8: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BC5AC: beq         $at, $zero, L_800BC5B8
    if (ctx->r1 == 0) {
        // 0x800BC5B0: nop
    
            goto L_800BC5B8;
    }
    // 0x800BC5B0: nop

    // 0x800BC5B4: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_800BC5B8:
    // 0x800BC5B8: lh          $t7, 0x1A($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC5BC: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC5C0: slt         $at, $ra, $t7
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BC5C4: bne         $at, $zero, L_800BC54C
    if (ctx->r1 != 0) {
        // 0x800BC5C8: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800BC54C;
    }
    // 0x800BC5C8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800BC5CC:
    // 0x800BC5CC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BC5D0: lw          $a0, -0x5990($t9)
    ctx->r4 = MEM_W(ctx->r25, -0X5990);
    // 0x800BC5D4: addiu       $s6, $s6, -0x5970
    ctx->r22 = ADD32(ctx->r22, -0X5970);
    // 0x800BC5D8: sw          $a0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r4;
    // 0x800BC5DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BC5E0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BC5E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BC5E8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800BC5EC: lw          $t0, -0x5974($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5974);
    // 0x800BC5F0: lw          $a1, -0x597C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X597C);
    // 0x800BC5F4: lw          $a3, -0x5978($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5978);
    // 0x800BC5F8: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BC5FC: beq         $at, $zero, L_800BC624
    if (ctx->r1 == 0) {
        // 0x800BC600: lui         $s5, 0x8013
        ctx->r21 = S32(0X8013 << 16);
            goto L_800BC624;
    }
    // 0x800BC600: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800BC604: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BC608: lw          $a2, -0x5998($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5998);
    // 0x800BC60C: nop

L_800BC610:
    // 0x800BC610: subu        $t6, $a0, $a2
    ctx->r14 = SUB32(ctx->r4, ctx->r6);
    // 0x800BC614: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BC618: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x800BC61C: bne         $at, $zero, L_800BC610
    if (ctx->r1 != 0) {
        // 0x800BC620: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800BC610;
    }
    // 0x800BC620: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_800BC624:
    // 0x800BC624: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BC628: lw          $t8, -0x598C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X598C);
    // 0x800BC62C: addiu       $s5, $s5, -0x596C
    ctx->r21 = ADD32(ctx->r21, -0X596C);
    // 0x800BC630: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800BC634: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x800BC638: lw          $a2, -0x5998($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5998);
    // 0x800BC63C: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BC640: beq         $at, $zero, L_800BC668
    if (ctx->r1 == 0) {
        // 0x800BC644: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800BC668;
    }
    // 0x800BC644: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800BC648: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC64C: lw          $v1, -0x5994($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5994);
    // 0x800BC650: nop

L_800BC654:
    // 0x800BC654: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x800BC658: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BC65C: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x800BC660: bne         $at, $zero, L_800BC654
    if (ctx->r1 != 0) {
        // 0x800BC664: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800BC654;
    }
    // 0x800BC664: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800BC668:
    // 0x800BC668: subu        $t9, $a3, $a0
    ctx->r25 = SUB32(ctx->r7, ctx->r4);
    // 0x800BC66C: div         $zero, $t9, $a2
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r6)));
    // 0x800BC670: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800BC674: addiu       $fp, $fp, -0x5994
    ctx->r30 = ADD32(ctx->r30, -0X5994);
    // 0x800BC678: subu        $t7, $t0, $v0
    ctx->r15 = SUB32(ctx->r8, ctx->r2);
    // 0x800BC67C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800BC680: addiu       $s7, $s7, -0x5968
    ctx->r23 = ADD32(ctx->r23, -0X5968);
    // 0x800BC684: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800BC688: addiu       $s2, $s2, 0x3664
    ctx->r18 = ADD32(ctx->r18, 0X3664);
    // 0x800BC68C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800BC690: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800BC694: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BC698: addiu       $s1, $s1, -0x5964
    ctx->r17 = ADD32(ctx->r17, -0X5964);
    // 0x800BC69C: addiu       $s0, $s0, 0x371C
    ctx->r16 = ADD32(ctx->r16, 0X371C);
    // 0x800BC6A0: bne         $a2, $zero, L_800BC6AC
    if (ctx->r6 != 0) {
        // 0x800BC6A4: nop
    
            goto L_800BC6AC;
    }
    // 0x800BC6A4: nop

    // 0x800BC6A8: break       7
    do_break(2148255400);
L_800BC6AC:
    // 0x800BC6AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC6B0: bne         $a2, $at, L_800BC6C4
    if (ctx->r6 != ctx->r1) {
        // 0x800BC6B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC6C4;
    }
    // 0x800BC6B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC6B8: bne         $t9, $at, L_800BC6C4
    if (ctx->r25 != ctx->r1) {
        // 0x800BC6BC: nop
    
            goto L_800BC6C4;
    }
    // 0x800BC6BC: nop

    // 0x800BC6C0: break       6
    do_break(2148255424);
L_800BC6C4:
    // 0x800BC6C4: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800BC6C8: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC6CC: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800BC6D0: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x800BC6D4: div         $zero, $t7, $t9
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r25)));
    // 0x800BC6D8: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x800BC6DC: bne         $t9, $zero, L_800BC6E8
    if (ctx->r25 != 0) {
        // 0x800BC6E0: nop
    
            goto L_800BC6E8;
    }
    // 0x800BC6E0: nop

    // 0x800BC6E4: break       7
    do_break(2148255460);
L_800BC6E8:
    // 0x800BC6E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC6EC: bne         $t9, $at, L_800BC700
    if (ctx->r25 != ctx->r1) {
        // 0x800BC6F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC700;
    }
    // 0x800BC6F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC6F4: bne         $t7, $at, L_800BC700
    if (ctx->r15 != ctx->r1) {
        // 0x800BC6F8: nop
    
            goto L_800BC700;
    }
    // 0x800BC6F8: nop

    // 0x800BC6FC: break       6
    do_break(2148255484);
L_800BC700:
    // 0x800BC700: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800BC704: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC708: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800BC70C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BC710: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC714: mflo        $t9
    ctx->r25 = lo;
    // 0x800BC718: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BC71C: beq         $a1, $zero, L_800BC734
    if (ctx->r5 == 0) {
        // 0x800BC720: sw          $t6, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r14;
            goto L_800BC734;
    }
    // 0x800BC720: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800BC724: jal         0x80071380
    // 0x800BC728: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800BC728: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800BC72C: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x800BC730: nop

L_800BC734:
    // 0x800BC734: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800BC738: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800BC73C: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC740: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800BC744: mflo        $a0
    ctx->r4 = lo;
    // 0x800BC748: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800BC74C: jal         0x80070EDC
    // 0x800BC750: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800BC750: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x800BC754: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800BC758: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BC75C: lw          $a0, 0x3668($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3668);
    // 0x800BC760: nop

    // 0x800BC764: beq         $a0, $zero, L_800BC774
    if (ctx->r4 == 0) {
        // 0x800BC768: nop
    
            goto L_800BC774;
    }
    // 0x800BC768: nop

    // 0x800BC76C: jal         0x80071380
    // 0x800BC770: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800BC770: nop

    after_2:
L_800BC774:
    // 0x800BC774: lh          $t9, 0x1A($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC778: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800BC77C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800BC780: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x800BC784: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BC788: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x800BC78C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800BC790: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800BC794: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800BC798: jal         0x80070EDC
    // 0x800BC79C: addiu       $a0, $a0, 0x880
    ctx->r4 = ADD32(ctx->r4, 0X880);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x800BC79C: addiu       $a0, $a0, 0x880
    ctx->r4 = ADD32(ctx->r4, 0X880);
    after_3:
    // 0x800BC7A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC7A4: sw          $v0, 0x3668($at)
    MEM_W(0X3668, ctx->r1) = ctx->r2;
    // 0x800BC7A8: lh          $t8, 0x1A($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC7AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BC7B0: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800BC7B4: lw          $t9, 0x3668($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3668);
    // 0x800BC7B8: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800BC7BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BC7C0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BC7C4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800BC7C8: addiu       $a1, $a1, 0x3720
    ctx->r5 = ADD32(ctx->r5, 0X3720);
    // 0x800BC7CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BC7D0: addiu       $t9, $t7, 0x800
    ctx->r25 = ADD32(ctx->r15, 0X800);
    // 0x800BC7D4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800BC7D8: addiu       $a0, $a0, 0x3724
    ctx->r4 = ADD32(ctx->r4, 0X3724);
    // 0x800BC7DC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800BC7E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BC7E4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800BC7E8: addiu       $t7, $t9, 0x80
    ctx->r15 = ADD32(ctx->r25, 0X80);
    // 0x800BC7EC: addiu       $v1, $v1, 0x3714
    ctx->r3 = ADD32(ctx->r3, 0X3714);
    // 0x800BC7F0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BC7F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BC7F8: blez        $t9, L_800BC82C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BC7FC: or          $ra, $zero, $zero
        ctx->r31 = 0 | 0;
            goto L_800BC82C;
    }
    // 0x800BC7FC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800BC800: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800BC804:
    // 0x800BC804: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BC808: nop

    // 0x800BC80C: addu        $t7, $t6, $ra
    ctx->r15 = ADD32(ctx->r14, ctx->r31);
    // 0x800BC810: sb          $v0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r2;
    // 0x800BC814: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800BC818: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC81C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BC820: slt         $at, $ra, $t9
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BC824: bne         $at, $zero, L_800BC804
    if (ctx->r1 != 0) {
        // 0x800BC828: nop
    
            goto L_800BC804;
    }
    // 0x800BC828: nop

L_800BC82C:
    // 0x800BC82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BC830:
    // 0x800BC830: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800BC834: nop

    // 0x800BC838: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800BC83C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC840: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800BC844: bne         $at, $zero, L_800BC830
    if (ctx->r1 != 0) {
        // 0x800BC848: sw          $zero, 0x0($t7)
        MEM_W(0X0, ctx->r15) = 0;
            goto L_800BC830;
    }
    // 0x800BC848: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800BC84C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC850: sw          $zero, 0x3718($at)
    MEM_W(0X3718, ctx->r1) = 0;
    // 0x800BC854: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800BC858: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800BC85C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800BC860: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC864: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC868: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800BC86C: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800BC870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BC874: addiu       $v1, $v1, -0x5858
    ctx->r3 = ADD32(ctx->r3, -0X5858);
    // 0x800BC878: addiu       $s4, $s4, -0x5998
    ctx->r20 = ADD32(ctx->r20, -0X5998);
    // 0x800BC87C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800BC880: lui         $t3, 0x40
    ctx->r11 = S32(0X40 << 16);
    // 0x800BC884: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800BC888: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC88C: blez        $t6, L_800BC8C4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BC890: nop
    
            goto L_800BC8C4;
    }
    // 0x800BC890: nop

L_800BC894:
    // 0x800BC894: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800BC898: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC89C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800BC8A0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800BC8A4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BC8A8: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800BC8AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC8B0: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC8B4: mflo        $t7
    ctx->r15 = lo;
    // 0x800BC8B8: slt         $at, $ra, $t7
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BC8BC: bne         $at, $zero, L_800BC894
    if (ctx->r1 != 0) {
        // 0x800BC8C0: nop
    
            goto L_800BC894;
    }
    // 0x800BC8C0: nop

L_800BC8C4:
    // 0x800BC8C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BC8C8: addiu       $v0, $v0, -0x5958
    ctx->r2 = ADD32(ctx->r2, -0X5958);
L_800BC8CC:
    // 0x800BC8CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC8D0: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800BC8D4: bne         $at, $zero, L_800BC8CC
    if (ctx->r1 != 0) {
        // 0x800BC8D8: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_800BC8CC;
    }
    // 0x800BC8D8: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800BC8DC: lh          $t9, 0x1A($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X1A);
    // 0x800BC8E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BC8E4: addiu       $v0, $v0, -0x5960
    ctx->r2 = ADD32(ctx->r2, -0X5960);
    // 0x800BC8E8: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800BC8EC: blez        $t9, L_800BCBB8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BC8F0: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_800BCBB8;
    }
    // 0x800BC8F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BC8F4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800BC8F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BC8FC: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x800BC900: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800BC904:
    // 0x800BC904: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x800BC908: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800BC90C: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x800BC910: subu        $t1, $t7, $a0
    ctx->r9 = SUB32(ctx->r15, ctx->r4);
    // 0x800BC914: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800BC918: div         $zero, $t1, $a2
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r6)));
    // 0x800BC91C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x800BC920: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x800BC924: lw          $v1, 0x0($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X0);
    // 0x800BC928: subu        $t2, $t8, $v0
    ctx->r10 = SUB32(ctx->r24, ctx->r2);
    // 0x800BC92C: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x800BC930: bne         $a2, $zero, L_800BC93C
    if (ctx->r6 != 0) {
        // 0x800BC934: nop
    
            goto L_800BC93C;
    }
    // 0x800BC934: nop

    // 0x800BC938: break       7
    do_break(2148256056);
L_800BC93C:
    // 0x800BC93C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC940: bne         $a2, $at, L_800BC954
    if (ctx->r6 != ctx->r1) {
        // 0x800BC944: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC954;
    }
    // 0x800BC944: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC948: bne         $t1, $at, L_800BC954
    if (ctx->r9 != ctx->r1) {
        // 0x800BC94C: nop
    
            goto L_800BC954;
    }
    // 0x800BC94C: nop

    // 0x800BC950: break       6
    do_break(2148256080);
L_800BC954:
    // 0x800BC954: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800BC958: lh          $t5, 0x20($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X20);
    // 0x800BC95C: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800BC960: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800BC964: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BC968: mflo        $t9
    ctx->r25 = lo;
    // 0x800BC96C: nop

    // 0x800BC970: nop

    // 0x800BC974: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC978: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC97C: addu        $t1, $t6, $a0
    ctx->r9 = ADD32(ctx->r14, ctx->r4);
    // 0x800BC980: nop

    // 0x800BC984: div         $zero, $t2, $v1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r3)));
    // 0x800BC988: bne         $v1, $zero, L_800BC994
    if (ctx->r3 != 0) {
        // 0x800BC98C: nop
    
            goto L_800BC994;
    }
    // 0x800BC98C: nop

    // 0x800BC990: break       7
    do_break(2148256144);
L_800BC994:
    // 0x800BC994: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC998: bne         $v1, $at, L_800BC9AC
    if (ctx->r3 != ctx->r1) {
        // 0x800BC99C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC9AC;
    }
    // 0x800BC99C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC9A0: bne         $t2, $at, L_800BC9AC
    if (ctx->r10 != ctx->r1) {
        // 0x800BC9A4: nop
    
            goto L_800BC9AC;
    }
    // 0x800BC9A4: nop

    // 0x800BC9A8: break       6
    do_break(2148256168);
L_800BC9AC:
    // 0x800BC9AC: mflo        $t7
    ctx->r15 = lo;
    // 0x800BC9B0: nop

    // 0x800BC9B4: nop

    // 0x800BC9B8: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC9BC: mflo        $t8
    ctx->r24 = lo;
    // 0x800BC9C0: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800BC9C4: blez        $t5, L_800BCA24
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800BC9C8: nop
    
            goto L_800BCA24;
    }
    // 0x800BC9C8: nop

    // 0x800BC9CC: sll         $a2, $t5, 2
    ctx->r6 = S32(ctx->r13 << 2);
    // 0x800BC9D0: subu        $a2, $a2, $t5
    ctx->r6 = SUB32(ctx->r6, ctx->r13);
    // 0x800BC9D4: lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XC);
    // 0x800BC9D8: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800BC9DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800BC9E0:
    // 0x800BC9E0: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x800BC9E4: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x800BC9E8: andi        $t9, $a0, 0x2000
    ctx->r25 = ctx->r4 & 0X2000;
    // 0x800BC9EC: beq         $t9, $zero, L_800BCA1C
    if (ctx->r25 == 0) {
        // 0x800BC9F0: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800BCA1C;
    }
    // 0x800BC9F0: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BC9F4: and         $t6, $a0, $t3
    ctx->r14 = ctx->r4 & ctx->r11;
    // 0x800BC9F8: beq         $t6, $zero, L_800BCA1C
    if (ctx->r14 == 0) {
        // 0x800BC9FC: nop
    
            goto L_800BCA1C;
    }
    // 0x800BC9FC: nop

    // 0x800BCA00: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x800BCA04: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800BCA08: multu       $t8, $t4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCA0C: mflo        $t9
    ctx->r25 = lo;
    // 0x800BCA10: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800BCA14: lh          $a3, 0x2($t6)
    ctx->r7 = MEM_H(ctx->r14, 0X2);
    // 0x800BCA18: nop

L_800BCA1C:
    // 0x800BCA1C: bne         $at, $zero, L_800BC9E0
    if (ctx->r1 != 0) {
        // 0x800BCA20: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800BC9E0;
    }
    // 0x800BCA20: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_800BCA24:
    // 0x800BCA24: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BCA28: lw          $t8, 0x3668($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3668);
    // 0x800BCA2C: addiu       $t0, $t0, 0x44
    ctx->r8 = ADD32(ctx->r8, 0X44);
    // 0x800BCA30: addu        $a0, $s2, $t8
    ctx->r4 = ADD32(ctx->r18, ctx->r24);
    // 0x800BCA34: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x800BCA38: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
    // 0x800BCA3C: sh          $a3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r7;
    // 0x800BCA40: sh          $t2, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r10;
    // 0x800BCA44: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800BCA48: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800BCA4C: subu        $t9, $t1, $t7
    ctx->r25 = SUB32(ctx->r9, ctx->r15);
    // 0x800BCA50: div         $zero, $t9, $t6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r14)));
    // 0x800BCA54: bne         $t6, $zero, L_800BCA60
    if (ctx->r14 != 0) {
        // 0x800BCA58: nop
    
            goto L_800BCA60;
    }
    // 0x800BCA58: nop

    // 0x800BCA5C: break       7
    do_break(2148256348);
L_800BCA60:
    // 0x800BCA60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BCA64: bne         $t6, $at, L_800BCA78
    if (ctx->r14 != ctx->r1) {
        // 0x800BCA68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BCA78;
    }
    // 0x800BCA68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BCA6C: bne         $t9, $at, L_800BCA78
    if (ctx->r25 != ctx->r1) {
        // 0x800BCA70: nop
    
            goto L_800BCA78;
    }
    // 0x800BCA70: nop

    // 0x800BCA74: break       6
    do_break(2148256372);
L_800BCA78:
    // 0x800BCA78: mflo        $t8
    ctx->r24 = lo;
    // 0x800BCA7C: sb          $t8, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r24;
    // 0x800BCA80: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800BCA84: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800BCA88: subu        $t9, $t2, $t7
    ctx->r25 = SUB32(ctx->r10, ctx->r15);
    // 0x800BCA8C: div         $zero, $t9, $t6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r14)));
    // 0x800BCA90: lbu         $a2, 0xA($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0XA);
    // 0x800BCA94: bne         $t6, $zero, L_800BCAA0
    if (ctx->r14 != 0) {
        // 0x800BCA98: nop
    
            goto L_800BCAA0;
    }
    // 0x800BCA98: nop

    // 0x800BCA9C: break       7
    do_break(2148256412);
L_800BCAA0:
    // 0x800BCAA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BCAA4: bne         $t6, $at, L_800BCAB8
    if (ctx->r14 != ctx->r1) {
        // 0x800BCAA8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BCAB8;
    }
    // 0x800BCAA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BCAAC: bne         $t9, $at, L_800BCAB8
    if (ctx->r25 != ctx->r1) {
        // 0x800BCAB0: nop
    
            goto L_800BCAB8;
    }
    // 0x800BCAB0: nop

    // 0x800BCAB4: break       6
    do_break(2148256436);
L_800BCAB8:
    // 0x800BCAB8: mflo        $t8
    ctx->r24 = lo;
    // 0x800BCABC: sb          $t8, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r24;
    // 0x800BCAC0: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800BCAC4: andi        $s1, $t8, 0xFF
    ctx->r17 = ctx->r24 & 0XFF;
    // 0x800BCAC8: multu       $s1, $t7
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCACC: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x800BCAD0: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x800BCAD4: or          $t5, $s1, $zero
    ctx->r13 = ctx->r17 | 0;
    // 0x800BCAD8: mflo        $t9
    ctx->r25 = lo;
    // 0x800BCADC: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x800BCAE0: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x800BCAE4: lb          $t8, -0x19($t0)
    ctx->r24 = MEM_B(ctx->r8, -0X19);
    // 0x800BCAE8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800BCAEC: beq         $t8, $zero, L_800BCB80
    if (ctx->r24 == 0) {
        // 0x800BCAF0: nop
    
            goto L_800BCB80;
    }
    // 0x800BCAF0: nop

    // 0x800BCAF4: multu       $a2, $t7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCAF8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BCAFC: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BCB00: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BCB04: addiu       $t8, $t8, -0x5958
    ctx->r24 = ADD32(ctx->r24, -0X5958);
    // 0x800BCB08: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800BCB0C: mflo        $v0
    ctx->r2 = lo;
    // 0x800BCB10: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCB14: bne         $at, $zero, L_800BCB2C
    if (ctx->r1 != 0) {
        // 0x800BCB18: nop
    
            goto L_800BCB2C;
    }
    // 0x800BCB18: nop

L_800BCB1C:
    // 0x800BCB1C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800BCB20: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCB24: beq         $at, $zero, L_800BCB1C
    if (ctx->r1 == 0) {
        // 0x800BCB28: nop
    
            goto L_800BCB1C;
    }
    // 0x800BCB28: nop

L_800BCB2C:
    // 0x800BCB2C: sh          $v0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r2;
    // 0x800BCB30: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800BCB34: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BCB38: multu       $t5, $t9
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCB3C: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BCB40: mflo        $v0
    ctx->r2 = lo;
    // 0x800BCB44: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCB48: bne         $at, $zero, L_800BCB60
    if (ctx->r1 != 0) {
        // 0x800BCB4C: nop
    
            goto L_800BCB60;
    }
    // 0x800BCB4C: nop

L_800BCB50:
    // 0x800BCB50: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800BCB54: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCB58: beq         $at, $zero, L_800BCB50
    if (ctx->r1 == 0) {
        // 0x800BCB5C: nop
    
            goto L_800BCB50;
    }
    // 0x800BCB5C: nop

L_800BCB60:
    // 0x800BCB60: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x800BCB64: lbu         $t9, 0xA($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XA);
    // 0x800BCB68: sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // 0x800BCB6C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800BCB70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800BCB74: sllv        $t8, $t6, $t9
    ctx->r24 = S32(ctx->r14 << (ctx->r25 & 31));
    // 0x800BCB78: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800BCB7C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800BCB80:
    // 0x800BCB80: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BCB84: sb          $a1, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r5;
    // 0x800BCB88: sb          $a1, 0x19($a0)
    MEM_B(0X19, ctx->r4) = ctx->r5;
    // 0x800BCB8C: sb          $a1, 0x16($a0)
    MEM_B(0X16, ctx->r4) = ctx->r5;
    // 0x800BCB90: sb          $a1, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r5;
    // 0x800BCB94: sb          $a1, 0x17($a0)
    MEM_B(0X17, ctx->r4) = ctx->r5;
    // 0x800BCB98: sb          $a1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r5;
    // 0x800BCB9C: sb          $a1, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r5;
    // 0x800BCBA0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x800BCBA4: lw          $t9, -0x5960($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5960);
    // 0x800BCBA8: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x800BCBAC: slt         $at, $ra, $t9
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BCBB0: bne         $at, $zero, L_800BC904
    if (ctx->r1 != 0) {
        // 0x800BCBB4: addiu       $s3, $s3, 0x44
        ctx->r19 = ADD32(ctx->r19, 0X44);
            goto L_800BC904;
    }
    // 0x800BCBB4: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
L_800BCBB8:
    // 0x800BCBB8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800BCBBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BCBC0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCBC4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800BCBC8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800BCBCC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800BCBD0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800BCBD4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800BCBD8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800BCBDC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800BCBE0: jr          $ra
    // 0x800BCBE4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BCBE4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void render_dialogue_option(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D6FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009D700: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009D704: lb          $t7, 0x6A78($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6A78);
    // 0x8009D708: lb          $t6, 0x6AA4($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X6AA4);
    // 0x8009D70C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009D710: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009D714: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D718: xor         $a0, $t6, $t7
    ctx->r4 = ctx->r14 ^ ctx->r15;
    // 0x8009D71C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8009D720: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8009D724: jal         0x8009D65C
    // 0x8009D728: sltiu       $a0, $a0, 0x1
    ctx->r4 = ctx->r4 < 0X1 ? 1 : 0;
    set_option_text_colour(rdram, ctx);
        goto after_0;
    // 0x8009D728: sltiu       $a0, $a0, 0x1
    ctx->r4 = ctx->r4 < 0X1 ? 1 : 0;
    after_0:
    // 0x8009D72C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D730: addiu       $v0, $v0, 0x6AA4
    ctx->r2 = ADD32(ctx->r2, 0X6AA4);
    // 0x8009D734: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009D738: lb          $t9, 0x6A78($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X6A78);
    // 0x8009D73C: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x8009D740: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D744: bne         $t8, $t9, L_8009D758
    if (ctx->r24 != ctx->r25) {
        // 0x8009D748: addiu       $a1, $zero, -0x8000
        ctx->r5 = ADD32(0, -0X8000);
            goto L_8009D758;
    }
    // 0x8009D748: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009D74C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8009D750: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D754: sb          $t0, 0x6AB6($at)
    MEM_B(0X6AB6, ctx->r1) = ctx->r8;
L_8009D758:
    // 0x8009D758: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009D75C: lb          $a2, 0x6AAE($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X6AAE);
    // 0x8009D760: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009D764: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009D768: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009D76C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009D770: jal         0x800C56C8
    // 0x8009D774: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    render_dialogue_text(rdram, ctx);
        goto after_1;
    // 0x8009D774: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_1:
    // 0x8009D778: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D77C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009D780: addiu       $v1, $v1, 0x6AAE
    ctx->r3 = ADD32(ctx->r3, 0X6AAE);
    // 0x8009D784: addiu       $v0, $v0, 0x6AA4
    ctx->r2 = ADD32(ctx->r2, 0X6AA4);
    // 0x8009D788: lb          $t3, 0x0($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X0);
    // 0x8009D78C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8009D790: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D798: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8009D79C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009D7A0: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8009D7A4: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8009D7A8: jr          $ra
    // 0x8009D7AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009D7AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void vec3f_rotate_py(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800706D0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800706D4: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x800706D8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800706DC: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800706E0: jal         0x80070A04
    // 0x800706E4: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800706E4: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    after_0:
    // 0x800706E8: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800706EC: jal         0x80070A38
    // 0x800706F0: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800706F0: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    after_1:
    // 0x800706F4: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800706F8: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x800706FC: jal         0x80070A04
    // 0x80070700: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80070700: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_2:
    // 0x80070704: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070708: jal         0x80070A38
    // 0x8007070C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    coss_f(rdram, ctx);
        goto after_3;
    // 0x8007070C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    after_3:
    // 0x80070710: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80070714: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80070718: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x8007071C: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x80070720: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070724: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070728: jr          $ra
    // 0x8007072C: nop

    return;
    // 0x8007072C: nop

;}
RECOMP_FUNC void viewport_rsp_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006839C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800683A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800683A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800683A8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800683AC: jal         0x8009C850
    // 0x800683B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x800683B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800683B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800683B8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800683BC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800683C0: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x800683C4: beq         $t6, $zero, L_800683D4
    if (ctx->r14 == 0) {
        // 0x800683C8: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800683D4;
    }
    // 0x800683C8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800683CC: b           L_800683D8
    // 0x800683D0: negu        $a2, $a1
    ctx->r6 = SUB32(0, ctx->r5);
        goto L_800683D8;
    // 0x800683D0: negu        $a2, $a1
    ctx->r6 = SUB32(0, ctx->r5);
L_800683D4:
    // 0x800683D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_800683D8:
    // 0x800683D8: lb          $t7, -0x2A30($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2A30);
    // 0x800683DC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800683E0: beq         $t7, $zero, L_800683F0
    if (ctx->r15 == 0) {
        // 0x800683E4: addiu       $a3, $a3, 0x1264
        ctx->r7 = ADD32(ctx->r7, 0X1264);
            goto L_800683F0;
    }
    // 0x800683E4: addiu       $a3, $a3, 0x1264
    ctx->r7 = ADD32(ctx->r7, 0X1264);
    // 0x800683E8: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x800683EC: negu        $a2, $a1
    ctx->r6 = SUB32(0, ctx->r5);
L_800683F0:
    // 0x800683F0: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800683F4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800683F8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800683FC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80068400: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80068404: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80068408: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006840C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80068410: lw          $t9, -0x29FC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X29FC);
    // 0x80068414: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80068418: andi        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 & 0X1;
    // 0x8006841C: bne         $t3, $zero, L_80068488
    if (ctx->r11 != 0) {
        // 0x80068420: addiu       $t2, $t2, -0x2948
        ctx->r10 = ADD32(ctx->r10, -0X2948);
            goto L_80068488;
    }
    // 0x80068420: addiu       $t2, $t2, -0x2948
    ctx->r10 = ADD32(ctx->r10, -0X2948);
    // 0x80068424: sll         $t4, $a1, 4
    ctx->r12 = S32(ctx->r5 << 4);
    // 0x80068428: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x8006842C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80068430: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80068434: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80068438: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8006843C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80068440: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80068444: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80068448: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x8006844C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80068450: sh          $t3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r11;
    // 0x80068454: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80068458: lui         $t5, 0x380
    ctx->r13 = S32(0X380 << 16);
    // 0x8006845C: addiu       $t4, $a0, 0x8
    ctx->r12 = ADD32(ctx->r4, 0X8);
    // 0x80068460: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80068464: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x80068468: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8006846C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80068470: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068474: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80068478: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8006847C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80068480: b           L_800684DC
    // 0x80068484: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
        goto L_800684DC;
    // 0x80068484: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
L_80068488:
    // 0x80068488: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006848C: lui         $t4, 0x380
    ctx->r12 = S32(0X380 << 16);
    // 0x80068490: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x80068494: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80068498: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x8006849C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800684A0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800684A4: lw          $t8, -0x295C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X295C);
    // 0x800684A8: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800684AC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800684B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800684B4: addiu       $t2, $t2, -0x2948
    ctx->r10 = ADD32(ctx->r10, -0X2948);
    // 0x800684B8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800684BC: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x800684C0: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x800684C4: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x800684C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800684CC: ori         $at, $at, 0xA0
    ctx->r1 = ctx->r1 | 0XA0;
    // 0x800684D0: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x800684D4: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800684D8: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
L_800684DC:
    // 0x800684DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800684E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800684E4: jr          $ra
    // 0x800684E8: nop

    return;
    // 0x800684E8: nop

;}
RECOMP_FUNC void is_in_tracks_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C814: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C818: lw          $v0, -0x5C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C8);
    // 0x8009C81C: jr          $ra
    // 0x8009C820: nop

    return;
    // 0x8009C820: nop

;}
RECOMP_FUNC void sndp_voice_handler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800033C8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800033CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800033D0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800033D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800033D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800033DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800033E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800033E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800033E8: addiu       $s1, $a0, 0x28
    ctx->r17 = ADD32(ctx->r4, 0X28);
    // 0x800033EC: addiu       $s2, $a0, 0x14
    ctx->r18 = ADD32(ctx->r4, 0X14);
    // 0x800033F0: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
    // 0x800033F4: addiu       $s4, $sp, 0x3C
    ctx->r20 = ADD32(ctx->r29, 0X3C);
L_800033F8:
    // 0x800033F8: lh          $t6, 0x28($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X28);
    // 0x800033FC: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80003400: bne         $s3, $t6, L_80003424
    if (ctx->r19 != ctx->r14) {
        // 0x80003404: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80003424;
    }
    // 0x80003404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80003408: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x8000340C: lw          $a2, 0x4C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4C);
    // 0x80003410: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80003414: jal         0x800C970C
    // 0x80003418: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80003418: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8000341C: b           L_80003430
    // 0x80003420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_80003430;
    // 0x80003420: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80003424:
    // 0x80003424: jal         0x80003470
    // 0x80003428: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    sndp_handle_event(rdram, ctx);
        goto after_1;
    // 0x80003428: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8000342C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80003430:
    // 0x80003430: jal         0x800C9830
    // 0x80003434: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    alEvtqNextEvent(rdram, ctx);
        goto after_2;
    // 0x80003434: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80003438: beq         $v0, $zero, L_800033F8
    if (ctx->r2 == 0) {
        // 0x8000343C: sw          $v0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->r2;
            goto L_800033F8;
    }
    // 0x8000343C: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80003440: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x80003444: nop

    // 0x80003448: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8000344C: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    // 0x80003450: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80003454: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80003458: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000345C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80003460: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80003464: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80003468: jr          $ra
    // 0x8000346C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000346C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void tex_get_table_2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B294: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B298: lw          $v0, 0x68D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68D8);
    // 0x8007B29C: jr          $ra
    // 0x8007B2A0: nop

    return;
    // 0x8007B2A0: nop

;}
RECOMP_FUNC void get_distance_to_active_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006658C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80066590: lb          $t6, 0x1294($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X1294);
    // 0x80066594: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80066598: lw          $v1, 0x1264($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1264);
    // 0x8006659C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800665A0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800665A4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800665A8: beq         $t6, $zero, L_800665B4
    if (ctx->r14 == 0) {
        // 0x800665AC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800665B4;
    }
    // 0x800665AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800665B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800665B4:
    // 0x800665B4: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x800665B8: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x800665BC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800665C0: addiu       $t8, $t8, 0x1040
    ctx->r24 = ADD32(ctx->r24, 0X1040);
    // 0x800665C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800665C8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800665CC: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800665D0: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800665D4: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800665D8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800665DC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800665E0: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800665E4: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800665E8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800665EC: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800665F0: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800665F4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800665F8: nop

    // 0x800665FC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80066600: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80066604: jal         0x800CA030
    // 0x80066608: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80066608: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x8006660C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066614: jr          $ra
    // 0x80066618: nop

    return;
    // 0x80066618: nop

;}
RECOMP_FUNC void level_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B464: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B468: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006B46C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B470: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8006B474: lw          $t7, 0x16F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16F4);
    // 0x8006B478: jr          $ra
    // 0x8006B47C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    return;
    // 0x8006B47C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
;}
RECOMP_FUNC void mtx_head_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800699D0: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800699D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800699D8: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800699DC: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800699E0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800699E4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800699E8: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800699EC: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800699F0: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x800699F4: lh          $t9, 0x16($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X16);
    // 0x800699F8: nop

    // 0x800699FC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80069A00: nop

    // 0x80069A04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80069A08: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80069A0C: lh          $t0, 0x18($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X18);
    // 0x80069A10: nop

    // 0x80069A14: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80069A18: nop

    // 0x80069A1C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80069A20: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80069A24: lh          $t1, 0x1A($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X1A);
    // 0x80069A28: nop

    // 0x80069A2C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80069A30: nop

    // 0x80069A34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80069A38: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
    // 0x80069A3C: lh          $a0, 0x1C($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1C);
    // 0x80069A40: jal         0x80070A38
    // 0x80069A44: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80069A44: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    after_0:
    // 0x80069A48: lw          $a2, 0x108($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X108);
    // 0x80069A4C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80069A50: lh          $a0, 0x1C($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1C);
    // 0x80069A54: jal         0x80070A04
    // 0x80069A58: nop

    sins_f(rdram, ctx);
        goto after_1;
    // 0x80069A58: nop

    after_1:
    // 0x80069A5C: lh          $a0, 0x10E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X10E);
    // 0x80069A60: jal         0x80070A38
    // 0x80069A64: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_2;
    // 0x80069A64: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80069A68: lh          $a0, 0x10E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X10E);
    // 0x80069A6C: jal         0x80070A04
    // 0x80069A70: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80069A70: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_3:
    // 0x80069A74: mul.s       $f18, $f22, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x80069A78: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80069A7C: lwc1        $f14, 0xF4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80069A80: lwc1        $f12, 0xF0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80069A84: mul.s       $f10, $f22, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x80069A88: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80069A8C: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80069A90: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    // 0x80069A94: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80069A98: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80069A9C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x80069AA0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80069AA4: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80069AA8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80069AAC: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x80069AB0: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x80069AB4: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80069AB8: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x80069ABC: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x80069AC0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80069AC4: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80069AC8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80069ACC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80069AD0: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    // 0x80069AD4: mul.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80069AD8: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x80069ADC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80069AE0: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x80069AE4: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x80069AE8: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80069AEC: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x80069AF0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80069AF4: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x80069AF8: add.s       $f18, $f2, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x80069AFC: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80069B00: swc1        $f16, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f16.u32l;
    // 0x80069B04: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80069B08: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80069B0C: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x80069B10: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069B14: mul.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80069B18: add.s       $f2, $f18, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80069B1C: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80069B20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069B24: add.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80069B28: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80069B2C: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x80069B30: mul.s       $f16, $f12, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80069B34: swc1        $f14, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f14.u32l;
    // 0x80069B38: lwc1        $f14, 0xF8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80069B3C: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x80069B40: mul.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80069B44: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80069B48: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80069B4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80069B50: mul.s       $f10, $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80069B54: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80069B58: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80069B5C: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x80069B60: add.s       $f2, $f18, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80069B64: swc1        $f22, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f22.u32l;
    // 0x80069B68: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80069B6C: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80069B70: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    // 0x80069B74: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x80069B78: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
    // 0x80069B7C: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80069B80: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80069B84: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80069B88: addiu       $a1, $a1, 0x1620
    ctx->r5 = ADD32(ctx->r5, 0X1620);
    // 0x80069B8C: swc1        $f16, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f16.u32l;
    // 0x80069B90: jal         0x8006F9A8
    // 0x80069B94: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    mtxf_mul(rdram, ctx);
        goto after_4;
    // 0x80069B94: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    after_4:
    // 0x80069B98: lw          $t2, 0x104($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X104);
    // 0x80069B9C: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x80069BA0: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x80069BA4: jal         0x8006FAB0
    // 0x80069BA8: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_5;
    // 0x80069BA8: nop

    after_5:
    // 0x80069BAC: lw          $a1, 0x100($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X100);
    // 0x80069BB0: lw          $a2, 0x104($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X104);
    // 0x80069BB4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80069BB8: lui         $t4, 0x180
    ctx->r12 = S32(0X180 << 16);
    // 0x80069BBC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80069BC0: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x80069BC4: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80069BC8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80069BCC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80069BD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80069BD4: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80069BD8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80069BDC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80069BE0: lui         $t0, 0xBC00
    ctx->r8 = S32(0XBC00 << 16);
    // 0x80069BE4: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x80069BE8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80069BEC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80069BF0: ori         $t0, $t0, 0xA
    ctx->r8 = ctx->r8 | 0XA;
    // 0x80069BF4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80069BF8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80069BFC: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x80069C00: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80069C04: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80069C08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80069C0C: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80069C10: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80069C14: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80069C18: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80069C1C: jr          $ra
    // 0x80069C20: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80069C20: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_80074EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075110: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80075114: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80075118: addiu       $a2, $zero, 0x1100
    ctx->r6 = ADD32(0, 0X1100);
    // 0x8007511C: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80075120: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80075124: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80075128: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8007512C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80075130: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80075134: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80075138: addiu       $a0, $v0, 0x200
    ctx->r4 = ADD32(ctx->r2, 0X200);
    // 0x8007513C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80075140: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80075144: jal         0x80070EDC
    // 0x80075148: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80075148: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007514C: lui         $t6, 0x4748
    ctx->r14 = S32(0X4748 << 16);
    // 0x80075150: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80075154: ori         $t6, $t6, 0x5353
    ctx->r14 = ctx->r14 | 0X5353;
    // 0x80075158: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007515C: lh          $t7, 0x46($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X46);
    // 0x80075160: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x80075164: sb          $t7, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r15;
    // 0x80075168: lh          $t8, 0x4A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4A);
    // 0x8007516C: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x80075170: lh          $t2, 0x6($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6);
    // 0x80075174: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80075178: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x8007517C: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x80075180: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
    // 0x80075184: sb          $t8, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r24;
    // 0x80075188: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x8007518C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80075190: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x80075194: lh          $t4, 0x6($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X6);
    // 0x80075198: sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
    // 0x8007519C: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x800751A0: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x800751A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800751A8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800751AC: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // 0x800751B0: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x800751B4: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800751B8: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x800751BC: sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
    // 0x800751C0: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x800751C4: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x800751C8: sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
    // 0x800751CC: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x800751D0: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x800751D4: sb          $a0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r4;
    // 0x800751D8: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x800751DC: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
    // 0x800751E0: nop

    // 0x800751E4: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x800751E8: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800751EC: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800751F0: lh          $a3, 0x56($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X56);
    // 0x800751F4: lh          $a2, 0x52($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X52);
    // 0x800751F8: lh          $a1, 0x4E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4E);
    // 0x800751FC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80075200: addu        $a0, $t3, $t1
    ctx->r4 = ADD32(ctx->r11, ctx->r9);
    // 0x80075204: jal         0x80074D00
    // 0x80075208: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_80074AA8(rdram, ctx);
        goto after_1;
    // 0x80075208: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_1:
    // 0x8007520C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80075210: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80075214: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80075218: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007521C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80075220: addiu       $t7, $t6, 0x100
    ctx->r15 = ADD32(ctx->r14, 0X100);
    // 0x80075224: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80075228: addiu       $a3, $a3, 0x7D08
    ctx->r7 = ADD32(ctx->r7, 0X7D08);
    // 0x8007522C: addiu       $a2, $a2, 0x7CF8
    ctx->r6 = ADD32(ctx->r6, 0X7CF8);
    // 0x80075230: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80075234: jal         0x8007692C
    // 0x80075238: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    write_controller_pak_file(rdram, ctx);
        goto after_2;
    // 0x80075238: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8007523C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80075240: jal         0x80071380
    // 0x80075244: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80075244: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x80075248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007524C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80075250: jr          $ra
    // 0x80075254: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80075254: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_init_wardensmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038B08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80038B0C: jr          $ra
    // 0x80038B10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80038B10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void textbox_visible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3958: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C395C: lb          $t6, 0x3C00($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3C00);
    // 0x800C3960: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C3964: beq         $t6, $zero, L_800C3990
    if (ctx->r14 == 0) {
        // 0x800C3968: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800C3990;
    }
    // 0x800C3968: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C396C: lbu         $t7, -0x52B7($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X52B7);
    // 0x800C3970: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C3974: beq         $t7, $zero, L_800C3990
    if (ctx->r15 == 0) {
        // 0x800C3978: nop
    
            goto L_800C3990;
    }
    // 0x800C3978: nop

    // 0x800C397C: lb          $t8, -0x52B8($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X52B8);
    // 0x800C3980: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C3984: beq         $t8, $zero, L_800C3990
    if (ctx->r24 == 0) {
        // 0x800C3988: nop
    
            goto L_800C3990;
    }
    // 0x800C3988: nop

    // 0x800C398C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800C3990:
    // 0x800C3990: jr          $ra
    // 0x800C3994: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C3994: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void alLoadNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065138: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006513C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80065140: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80065144: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80065148: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006514C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80065150: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80065154: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80065158: addiu       $a1, $a1, -0x3EB4
    ctx->r5 = ADD32(ctx->r5, -0X3EB4);
    // 0x8006515C: addiu       $a2, $a2, -0x4560
    ctx->r6 = ADD32(ctx->r6, -0X4560);
    // 0x80065160: jal         0x800CA610
    // 0x80065164: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80065164: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80065168: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8006516C: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80065170: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065174: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006517C: jal         0x800C7D50
    // 0x80065180: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80065180: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80065184: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80065188: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8006518C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80065190: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80065194: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006519C: jal         0x800C7D50
    // 0x800651A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800651A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800651A4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800651A8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800651AC: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800651B0: jalr        $t9
    // 0x800651B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800651B4: nop

    after_3:
    // 0x800651B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800651BC: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800651C0: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x800651C4: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x800651C8: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x800651CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800651D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800651D4: jr          $ra
    // 0x800651D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800651D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void strcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4C70: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4C74: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800B4C78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4C7C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4C80: beq         $v0, $zero, L_800B4C9C
    if (ctx->r2 == 0) {
        // 0x800B4C84: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B4C9C;
    }
    // 0x800B4C84: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B4C88:
    // 0x800B4C88: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4C8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4C90: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4C94: bne         $v0, $zero, L_800B4C88
    if (ctx->r2 != 0) {
        // 0x800B4C98: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_800B4C88;
    }
    // 0x800B4C98: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800B4C9C:
    // 0x800B4C9C: jr          $ra
    // 0x800B4CA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B4CA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void racer_ai_eggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800452E0: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800452E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800452E8: sw          $zero, -0x2554($at)
    MEM_W(-0X2554, ctx->r1) = 0;
    // 0x800452EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800452F0: sw          $zero, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = 0;
    // 0x800452F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800452F8: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x800452FC: sw          $t6, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r14;
    // 0x80045300: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045304: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80045308: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
    // 0x8004530C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80045310: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80045314: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80045318: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8004531C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045320: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80045324: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80045328: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8004532C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80045330: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80045334: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80045338: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8004533C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80045340: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80045344: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80045348: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8004534C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80045350: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80045354: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80045358: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
    // 0x8004535C: jal         0x8001BAA8
    // 0x80045360: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x80045360: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    after_0:
    // 0x80045364: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80045368: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004536C: bne         $t7, $at, L_80045C44
    if (ctx->r15 != ctx->r1) {
        // 0x80045370: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C44;
    }
    // 0x80045370: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045374: jal         0x8006BFF0
    // 0x80045378: nop

    level_header(rdram, ctx);
        goto after_1;
    // 0x80045378: nop

    after_1:
    // 0x8004537C: addiu       $t8, $v0, 0x2A
    ctx->r24 = ADD32(ctx->r2, 0X2A);
    // 0x80045380: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80045384: lb          $t9, 0x1E2($s5)
    ctx->r25 = MEM_B(ctx->r21, 0X1E2);
    // 0x80045388: nop

    // 0x8004538C: beq         $t9, $zero, L_800453C8
    if (ctx->r25 == 0) {
        // 0x80045390: nop
    
            goto L_800453C8;
    }
    // 0x80045390: nop

    // 0x80045394: lh          $t0, 0x1C6($s5)
    ctx->r8 = MEM_H(ctx->r21, 0X1C6);
    // 0x80045398: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8004539C: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x800453A0: sh          $t1, 0x1C6($s5)
    MEM_H(0X1C6, ctx->r21) = ctx->r9;
    // 0x800453A4: lh          $t2, 0x1C6($s5)
    ctx->r10 = MEM_H(ctx->r21, 0X1C6);
    // 0x800453A8: nop

    // 0x800453AC: slti        $at, $t2, 0x3D
    ctx->r1 = SIGNED(ctx->r10) < 0X3D ? 1 : 0;
    // 0x800453B0: bne         $at, $zero, L_800453CC
    if (ctx->r1 != 0) {
        // 0x800453B4: nop
    
            goto L_800453CC;
    }
    // 0x800453B4: nop

    // 0x800453B8: sh          $zero, 0x1C6($s5)
    MEM_H(0X1C6, ctx->r21) = 0;
    // 0x800453BC: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
    // 0x800453C0: b           L_800453CC
    // 0x800453C4: sb          $t3, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r11;
        goto L_800453CC;
    // 0x800453C4: sb          $t3, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r11;
L_800453C8:
    // 0x800453C8: sh          $zero, 0x1C6($s5)
    MEM_H(0X1C6, ctx->r21) = 0;
L_800453CC:
    // 0x800453CC: lbu         $v1, 0x1CD($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X1CD);
    // 0x800453D0: nop

    // 0x800453D4: bne         $v1, $zero, L_800458E8
    if (ctx->r3 != 0) {
        // 0x800453D8: nop
    
            goto L_800458E8;
    }
    // 0x800453D8: nop

    // 0x800453DC: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x800453E0: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
L_800453E4:
    // 0x800453E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800453E8: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800453EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800453F0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800453F4: addiu       $a1, $a1, -0x24F5
    ctx->r5 = ADD32(ctx->r5, -0X24F5);
    // 0x800453F8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800453FC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80045400:
    // 0x80045400: lb          $v0, 0x0($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X0);
    // 0x80045404: nop

    // 0x80045408: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x8004540C: multu       $t4, $s7
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80045410: andi        $t7, $v0, 0x40
    ctx->r15 = ctx->r2 & 0X40;
    // 0x80045414: andi        $t0, $v0, 0x80
    ctx->r8 = ctx->r2 & 0X80;
    // 0x80045418: mflo        $v1
    ctx->r3 = lo;
    // 0x8004541C: sll         $t5, $v1, 24
    ctx->r13 = S32(ctx->r3 << 24);
    // 0x80045420: sra         $t6, $t5, 24
    ctx->r14 = S32(SIGNED(ctx->r13) >> 24);
    // 0x80045424: beq         $t7, $zero, L_8004543C
    if (ctx->r15 == 0) {
        // 0x80045428: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8004543C;
    }
    // 0x80045428: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8004542C: addiu       $v1, $t6, 0x2
    ctx->r3 = ADD32(ctx->r14, 0X2);
    // 0x80045430: sll         $t8, $v1, 24
    ctx->r24 = S32(ctx->r3 << 24);
    // 0x80045434: b           L_80045450
    // 0x80045438: sra         $v1, $t8, 24
    ctx->r3 = S32(SIGNED(ctx->r24) >> 24);
        goto L_80045450;
    // 0x80045438: sra         $v1, $t8, 24
    ctx->r3 = S32(SIGNED(ctx->r24) >> 24);
L_8004543C:
    // 0x8004543C: beq         $t0, $zero, L_80045454
    if (ctx->r8 == 0) {
        // 0x80045440: slt         $at, $s2, $v1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80045454;
    }
    // 0x80045440: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80045444: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80045448: sll         $t1, $v1, 24
    ctx->r9 = S32(ctx->r3 << 24);
    // 0x8004544C: sra         $v1, $t1, 24
    ctx->r3 = S32(SIGNED(ctx->r9) >> 24);
L_80045450:
    // 0x80045450: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
L_80045454:
    // 0x80045454: beq         $at, $zero, L_80045474
    if (ctx->r1 == 0) {
        // 0x80045458: nop
    
            goto L_80045474;
    }
    // 0x80045458: nop

    // 0x8004545C: sll         $s2, $v1, 24
    ctx->r18 = S32(ctx->r3 << 24);
    // 0x80045460: sll         $s0, $a0, 24
    ctx->r16 = S32(ctx->r4 << 24);
    // 0x80045464: sra         $t3, $s2, 24
    ctx->r11 = S32(SIGNED(ctx->r18) >> 24);
    // 0x80045468: sra         $t4, $s0, 24
    ctx->r12 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8004546C: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x80045470: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
L_80045474:
    // 0x80045474: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80045478: bgez        $a0, L_80045400
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8004547C: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80045400;
    }
    // 0x8004547C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80045480: lbu         $v0, 0x1CE($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X1CE);
    // 0x80045484: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80045488: andi        $t5, $v0, 0x40
    ctx->r13 = ctx->r2 & 0X40;
    // 0x8004548C: beq         $t5, $zero, L_800454B0
    if (ctx->r13 == 0) {
        // 0x80045490: andi        $t9, $v0, 0x80
        ctx->r25 = ctx->r2 & 0X80;
            goto L_800454B0;
    }
    // 0x80045490: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x80045494: andi        $s1, $v0, 0xF
    ctx->r17 = ctx->r2 & 0XF;
    // 0x80045498: sll         $t6, $s1, 24
    ctx->r14 = S32(ctx->r17 << 24);
    // 0x8004549C: sra         $s1, $t6, 24
    ctx->r17 = S32(SIGNED(ctx->r14) >> 24);
    // 0x800454A0: sb          $t8, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r24;
    // 0x800454A4: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x800454A8: sb          $zero, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = 0;
    // 0x800454AC: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
L_800454B0:
    // 0x800454B0: beq         $t9, $zero, L_80045620
    if (ctx->r25 == 0) {
        // 0x800454B4: nop
    
            goto L_80045620;
    }
    // 0x800454B4: nop

    // 0x800454B8: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800454BC: nop

    // 0x800454C0: lb          $a0, 0x6($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X6);
    // 0x800454C4: jal         0x80044490
    // 0x800454C8: nop

    roll_percent_chance(rdram, ctx);
        goto after_2;
    // 0x800454C8: nop

    after_2:
    // 0x800454CC: beq         $v0, $zero, L_800454E0
    if (ctx->r2 == 0) {
        // 0x800454D0: lw          $t1, 0x74($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X74);
            goto L_800454E0;
    }
    // 0x800454D0: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x800454D4: b           L_8004550C
    // 0x800454D8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
        goto L_8004550C;
    // 0x800454D8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x800454DC: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
L_800454E0:
    // 0x800454E0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800454E4: lb          $a0, 0x2($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X2);
    // 0x800454E8: jal         0x80044490
    // 0x800454EC: nop

    roll_percent_chance(rdram, ctx);
        goto after_3;
    // 0x800454EC: nop

    after_3:
    // 0x800454F0: beq         $v0, $zero, L_80045510
    if (ctx->r2 == 0) {
        // 0x800454F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80045510;
    }
    // 0x800454F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800454F8: jal         0x80066450
    // 0x800454FC: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_4;
    // 0x800454FC: nop

    after_4:
    // 0x80045500: bne         $v0, $zero, L_80045510
    if (ctx->r2 != 0) {
        // 0x80045504: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80045510;
    }
    // 0x80045504: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80045508: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8004550C:
    // 0x8004550C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80045510:
    // 0x80045510: bne         $s2, $at, L_800455CC
    if (ctx->r18 != ctx->r1) {
        // 0x80045514: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800455CC;
    }
    // 0x80045514: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045518: lb          $v0, 0x2($s5)
    ctx->r2 = MEM_B(ctx->r21, 0X2);
    // 0x8004551C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045520: beq         $v0, $zero, L_80045540
    if (ctx->r2 == 0) {
        // 0x80045524: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80045540;
    }
    // 0x80045524: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80045528: lb          $t2, -0x24F8($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X24F8);
    // 0x8004552C: nop

    // 0x80045530: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x80045534: beq         $t3, $zero, L_80045540
    if (ctx->r11 == 0) {
        // 0x80045538: nop
    
            goto L_80045540;
    }
    // 0x80045538: nop

    // 0x8004553C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80045540:
    // 0x80045540: beq         $v0, $at, L_80045560
    if (ctx->r2 == ctx->r1) {
        // 0x80045544: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80045560;
    }
    // 0x80045544: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80045548: lb          $t4, -0x24F7($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X24F7);
    // 0x8004554C: nop

    // 0x80045550: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x80045554: beq         $t5, $zero, L_80045564
    if (ctx->r13 == 0) {
        // 0x80045558: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80045564;
    }
    // 0x80045558: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004555C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80045560:
    // 0x80045560: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80045564:
    // 0x80045564: beq         $v0, $at, L_80045584
    if (ctx->r2 == ctx->r1) {
        // 0x80045568: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80045584;
    }
    // 0x80045568: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004556C: lb          $t6, -0x24F6($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X24F6);
    // 0x80045570: nop

    // 0x80045574: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x80045578: beq         $t7, $zero, L_80045588
    if (ctx->r15 == 0) {
        // 0x8004557C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80045588;
    }
    // 0x8004557C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80045580: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80045584:
    // 0x80045584: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80045588:
    // 0x80045588: beq         $v0, $at, L_800455B0
    if (ctx->r2 == ctx->r1) {
        // 0x8004558C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800455B0;
    }
    // 0x8004558C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80045590: lb          $t8, -0x24F5($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X24F5);
    // 0x80045594: nop

    // 0x80045598: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x8004559C: beq         $t9, $zero, L_800455B4
    if (ctx->r25 == 0) {
        // 0x800455A0: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800455B4;
    }
    // 0x800455A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800455A4: sll         $s1, $s7, 24
    ctx->r17 = S32(ctx->r23 << 24);
    // 0x800455A8: sra         $t0, $s1, 24
    ctx->r8 = S32(SIGNED(ctx->r17) >> 24);
    // 0x800455AC: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
L_800455B0:
    // 0x800455B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_800455B4:
    // 0x800455B4: bne         $s1, $at, L_800455C4
    if (ctx->r17 != ctx->r1) {
        // 0x800455B8: addiu       $t1, $zero, 0x7
        ctx->r9 = ADD32(0, 0X7);
            goto L_800455C4;
    }
    // 0x800455B8: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x800455BC: b           L_800455C8
    // 0x800455C0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_800455C8;
    // 0x800455C0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800455C4:
    // 0x800455C4: sb          $t1, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r9;
L_800455C8:
    // 0x800455C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800455CC:
    // 0x800455CC: bne         $s2, $at, L_8004561C
    if (ctx->r18 != ctx->r1) {
        // 0x800455D0: nop
    
            goto L_8004561C;
    }
    // 0x800455D0: nop

    // 0x800455D4: lb          $t2, 0x173($s5)
    ctx->r10 = MEM_B(ctx->r21, 0X173);
    // 0x800455D8: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800455DC: beq         $t2, $zero, L_80045618
    if (ctx->r10 == 0) {
        // 0x800455E0: nop
    
            goto L_80045618;
    }
    // 0x800455E0: nop

    // 0x800455E4: lb          $v0, 0x2($s5)
    ctx->r2 = MEM_B(ctx->r21, 0X2);
    // 0x800455E8: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800455EC: beq         $s0, $v0, L_80045604
    if (ctx->r16 == ctx->r2) {
        // 0x800455F0: sb          $t3, 0x1CD($s5)
        MEM_B(0X1CD, ctx->r21) = ctx->r11;
            goto L_80045604;
    }
    // 0x800455F0: sb          $t3, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r11;
    // 0x800455F4: sll         $s1, $s0, 24
    ctx->r17 = S32(ctx->r16 << 24);
    // 0x800455F8: sra         $t4, $s1, 24
    ctx->r12 = S32(SIGNED(ctx->r17) >> 24);
    // 0x800455FC: b           L_8004561C
    // 0x80045600: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
        goto L_8004561C;
    // 0x80045600: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
L_80045604:
    // 0x80045604: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    // 0x80045608: andi        $t5, $s1, 0x3
    ctx->r13 = ctx->r17 & 0X3;
    // 0x8004560C: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80045610: b           L_8004561C
    // 0x80045614: sra         $s1, $t6, 24
    ctx->r17 = S32(SIGNED(ctx->r14) >> 24);
        goto L_8004561C;
    // 0x80045614: sra         $s1, $t6, 24
    ctx->r17 = S32(SIGNED(ctx->r14) >> 24);
L_80045618:
    // 0x80045618: sb          $t8, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r24;
L_8004561C:
    // 0x8004561C: sb          $zero, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = 0;
L_80045620:
    // 0x80045620: lw          $t9, 0x144($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X144);
    // 0x80045624: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80045628: beq         $t9, $zero, L_80045634
    if (ctx->r25 == 0) {
        // 0x8004562C: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80045634;
    }
    // 0x8004562C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80045630: sb          $t0, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r8;
L_80045634:
    // 0x80045634: lbu         $v0, 0x1CE($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X1CE);
    // 0x80045638: nop

    // 0x8004563C: beq         $v0, $zero, L_80045648
    if (ctx->r2 == 0) {
        // 0x80045640: nop
    
            goto L_80045648;
    }
    // 0x80045640: nop

    // 0x80045644: sb          $v0, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r2;
L_80045648:
    // 0x80045648: lbu         $t1, 0x1CD($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X1CD);
    // 0x8004564C: sb          $zero, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = 0;
    // 0x80045650: bne         $t1, $zero, L_8004569C
    if (ctx->r9 != 0) {
        // 0x80045654: nop
    
            goto L_8004569C;
    }
    // 0x80045654: nop

    // 0x80045658: lw          $t2, 0x4C($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X4C);
    // 0x8004565C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045660: lbu         $v0, 0x12($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X12);
    // 0x80045664: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80045668: beq         $v0, $at, L_80045688
    if (ctx->r2 == ctx->r1) {
        // 0x8004566C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80045688;
    }
    // 0x8004566C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80045670: beq         $v0, $at, L_80045690
    if (ctx->r2 == ctx->r1) {
        // 0x80045674: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80045690;
    }
    // 0x80045674: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80045678: beq         $v0, $s7, L_80045698
    if (ctx->r2 == ctx->r23) {
        // 0x8004567C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80045698;
    }
    // 0x8004567C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80045680: b           L_800456A0
    // 0x80045684: lb          $t6, 0x1D8($s5)
    ctx->r14 = MEM_B(ctx->r21, 0X1D8);
        goto L_800456A0;
    // 0x80045684: lb          $t6, 0x1D8($s5)
    ctx->r14 = MEM_B(ctx->r21, 0X1D8);
L_80045688:
    // 0x80045688: b           L_8004569C
    // 0x8004568C: sb          $t3, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r11;
        goto L_8004569C;
    // 0x8004568C: sb          $t3, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r11;
L_80045690:
    // 0x80045690: b           L_8004569C
    // 0x80045694: sb          $t4, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r12;
        goto L_8004569C;
    // 0x80045694: sb          $t4, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r12;
L_80045698:
    // 0x80045698: sb          $t5, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r13;
L_8004569C:
    // 0x8004569C: lb          $t6, 0x1D8($s5)
    ctx->r14 = MEM_B(ctx->r21, 0X1D8);
L_800456A0:
    // 0x800456A0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800456A4: beq         $t6, $zero, L_800456B0
    if (ctx->r14 == 0) {
        // 0x800456A8: nop
    
            goto L_800456B0;
    }
    // 0x800456A8: nop

    // 0x800456AC: sb          $t7, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = ctx->r15;
L_800456B0:
    // 0x800456B0: lbu         $t8, 0x1CD($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X1CD);
    // 0x800456B4: nop

    // 0x800456B8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800456BC: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x800456C0: beq         $at, $zero, L_80045724
    if (ctx->r1 == 0) {
        // 0x800456C4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80045724;
    }
    // 0x800456C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800456C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800456CC: addu        $at, $at, $t9
    gpr jr_addend_800456D8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800456D0: lw          $t9, 0x68E8($at)
    ctx->r25 = ADD32(ctx->r1, 0X68E8);
    // 0x800456D4: nop

    // 0x800456D8: jr          $t9
    // 0x800456DC: nop

    switch (jr_addend_800456D8 >> 2) {
        case 0: goto L_800456E0; break;
        case 1: goto L_800456E8; break;
        case 2: goto L_800456F0; break;
        case 3: goto L_800456FC; break;
        case 4: goto L_8004570C; break;
        case 5: goto L_80045714; break;
        case 6: goto L_800456F0; break;
        case 7: goto L_8004571C; break;
        default: switch_error(__func__, 0x800456D8, 0x800E68E8);
    }
    // 0x800456DC: nop

L_800456E0:
    // 0x800456E0: b           L_80045724
    // 0x800456E4: addiu       $s3, $zero, 0x2D
    ctx->r19 = ADD32(0, 0X2D);
        goto L_80045724;
    // 0x800456E4: addiu       $s3, $zero, 0x2D
    ctx->r19 = ADD32(0, 0X2D);
L_800456E8:
    // 0x800456E8: b           L_80045724
    // 0x800456EC: addiu       $s3, $zero, 0x5C
    ctx->r19 = ADD32(0, 0X5C);
        goto L_80045724;
    // 0x800456EC: addiu       $s3, $zero, 0x5C
    ctx->r19 = ADD32(0, 0X5C);
L_800456F0:
    // 0x800456F0: addiu       $s3, $zero, 0x5C
    ctx->r19 = ADD32(0, 0X5C);
    // 0x800456F4: b           L_80045724
    // 0x800456F8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
        goto L_80045724;
    // 0x800456F8: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_800456FC:
    // 0x800456FC: lb          $s1, 0x2($s5)
    ctx->r17 = MEM_B(ctx->r21, 0X2);
    // 0x80045700: addiu       $s3, $zero, 0x5C
    ctx->r19 = ADD32(0, 0X5C);
    // 0x80045704: b           L_80045724
    // 0x80045708: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
        goto L_80045724;
    // 0x80045708: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_8004570C:
    // 0x8004570C: b           L_80045724
    // 0x80045710: addiu       $s3, $zero, 0x11
    ctx->r19 = ADD32(0, 0X11);
        goto L_80045724;
    // 0x80045710: addiu       $s3, $zero, 0x11
    ctx->r19 = ADD32(0, 0X11);
L_80045714:
    // 0x80045714: b           L_80045724
    // 0x80045718: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80045724;
    // 0x80045718: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8004571C:
    // 0x8004571C: addiu       $s3, $zero, 0x2D
    ctx->r19 = ADD32(0, 0X2D);
    // 0x80045720: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80045724:
    // 0x80045724: beq         $s3, $zero, L_800458A0
    if (ctx->r19 == 0) {
        // 0x80045728: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800458A0;
    }
    // 0x80045728: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004572C: beq         $s3, $at, L_800458A0
    if (ctx->r19 == ctx->r1) {
        // 0x80045730: addiu       $a0, $sp, 0x94
        ctx->r4 = ADD32(ctx->r29, 0X94);
            goto L_800458A0;
    }
    // 0x80045730: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80045734: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80045738: lwc1        $f24, 0x6908($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X6908);
    // 0x8004573C: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x80045740: jal         0x8000E988
    // 0x80045744: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    objGetObjList(rdram, ctx);
        goto after_5;
    // 0x80045744: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    after_5:
    // 0x80045748: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x8004574C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80045750: blez        $t0, L_800458A0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80045754: sw          $zero, 0x94($sp)
        MEM_W(0X94, ctx->r29) = 0;
            goto L_800458A0;
    }
    // 0x80045754: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
L_80045758:
    // 0x80045758: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8004575C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80045760: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80045764: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x80045768: lw          $s0, 0x0($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X0);
    // 0x8004576C: nop

    // 0x80045770: lh          $t4, 0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X6);
    // 0x80045774: nop

    // 0x80045778: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8004577C: bne         $t5, $zero, L_8004582C
    if (ctx->r13 != 0) {
        // 0x80045780: nop
    
            goto L_8004582C;
    }
    // 0x80045780: nop

    // 0x80045784: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x80045788: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8004578C: bne         $s3, $t6, L_8004582C
    if (ctx->r19 != ctx->r14) {
        // 0x80045790: nop
    
            goto L_8004582C;
    }
    // 0x80045790: nop

    // 0x80045794: beq         $s3, $at, L_800457E4
    if (ctx->r19 == ctx->r1) {
        // 0x80045798: addiu       $at, $zero, 0x5C
        ctx->r1 = ADD32(0, 0X5C);
            goto L_800457E4;
    }
    // 0x80045798: addiu       $at, $zero, 0x5C
    ctx->r1 = ADD32(0, 0X5C);
    // 0x8004579C: beq         $s3, $at, L_800457AC
    if (ctx->r19 == ctx->r1) {
        // 0x800457A0: nop
    
            goto L_800457AC;
    }
    // 0x800457A0: nop

    // 0x800457A4: b           L_8004582C
    // 0x800457A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8004582C;
    // 0x800457A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800457AC:
    // 0x800457AC: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x800457B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800457B4: lb          $t7, 0x8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X8);
    // 0x800457B8: nop

    // 0x800457BC: bne         $s2, $t7, L_8004582C
    if (ctx->r18 != ctx->r15) {
        // 0x800457C0: nop
    
            goto L_8004582C;
    }
    // 0x800457C0: nop

    // 0x800457C4: beq         $s1, $at, L_800457DC
    if (ctx->r17 == ctx->r1) {
        // 0x800457C8: nop
    
            goto L_800457DC;
    }
    // 0x800457C8: nop

    // 0x800457CC: lb          $t8, 0x9($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X9);
    // 0x800457D0: nop

    // 0x800457D4: bne         $s1, $t8, L_8004582C
    if (ctx->r17 != ctx->r24) {
        // 0x800457D8: nop
    
            goto L_8004582C;
    }
    // 0x800457D8: nop

L_800457DC:
    // 0x800457DC: b           L_8004582C
    // 0x800457E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8004582C;
    // 0x800457E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800457E4:
    // 0x800457E4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x800457E8: bne         $s2, $zero, L_80045808
    if (ctx->r18 != 0) {
        // 0x800457EC: nop
    
            goto L_80045808;
    }
    // 0x800457EC: nop

    // 0x800457F0: lb          $t9, 0xB($v0)
    ctx->r25 = MEM_B(ctx->r2, 0XB);
    // 0x800457F4: nop

    // 0x800457F8: bne         $t9, $zero, L_8004582C
    if (ctx->r25 != 0) {
        // 0x800457FC: nop
    
            goto L_8004582C;
    }
    // 0x800457FC: nop

    // 0x80045800: b           L_8004582C
    // 0x80045804: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8004582C;
    // 0x80045804: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80045808:
    // 0x80045808: lb          $t0, 0xB($v0)
    ctx->r8 = MEM_B(ctx->r2, 0XB);
    // 0x8004580C: nop

    // 0x80045810: bne         $s7, $t0, L_8004582C
    if (ctx->r23 != ctx->r8) {
        // 0x80045814: nop
    
            goto L_8004582C;
    }
    // 0x80045814: nop

    // 0x80045818: lb          $t1, 0xA($v0)
    ctx->r9 = MEM_B(ctx->r2, 0XA);
    // 0x8004581C: nop

    // 0x80045820: bne         $s1, $t1, L_8004582C
    if (ctx->r17 != ctx->r9) {
        // 0x80045824: nop
    
            goto L_8004582C;
    }
    // 0x80045824: nop

    // 0x80045828: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8004582C:
    // 0x8004582C: beq         $v1, $zero, L_8004588C
    if (ctx->r3 == 0) {
        // 0x80045830: lw          $t2, 0x94($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X94);
            goto L_8004588C;
    }
    // 0x80045830: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80045834: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80045838: lwc1        $f6, 0xC($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0XC);
    // 0x8004583C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80045840: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80045844: lwc1        $f10, 0x10($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80045848: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8004584C: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80045850: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80045854: lwc1        $f18, 0x14($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80045858: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8004585C: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80045860: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80045864: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80045868: jal         0x800CA030
    // 0x8004586C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x8004586C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_6:
    // 0x80045870: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80045874: nop

    // 0x80045878: bc1f        L_8004588C
    if (!c1cs) {
        // 0x8004587C: lw          $t2, 0x94($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X94);
            goto L_8004588C;
    }
    // 0x8004587C: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80045880: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80045884: or          $fp, $s0, $zero
    ctx->r30 = ctx->r16 | 0;
    // 0x80045888: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
L_8004588C:
    // 0x8004588C: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80045890: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80045894: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80045898: bne         $at, $zero, L_80045758
    if (ctx->r1 != 0) {
        // 0x8004589C: sw          $t3, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r11;
            goto L_80045758;
    }
    // 0x8004589C: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
L_800458A0:
    // 0x800458A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800458A4: bne         $s3, $at, L_800458C0
    if (ctx->r19 != ctx->r1) {
        // 0x800458A8: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800458C0;
    }
    // 0x800458A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800458AC: beq         $s1, $at, L_800458C0
    if (ctx->r17 == ctx->r1) {
        // 0x800458B0: nop
    
            goto L_800458C0;
    }
    // 0x800458B0: nop

    // 0x800458B4: jal         0x8001BAFC
    // 0x800458B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    get_racer_object(rdram, ctx);
        goto after_7;
    // 0x800458B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x800458BC: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_800458C0:
    // 0x800458C0: bne         $fp, $zero, L_800458D4
    if (ctx->r30 != 0) {
        // 0x800458C4: sw          $fp, 0x154($s5)
        MEM_W(0X154, ctx->r21) = ctx->r30;
            goto L_800458D4;
    }
    // 0x800458C4: sw          $fp, 0x154($s5)
    MEM_W(0X154, ctx->r21) = ctx->r30;
    // 0x800458C8: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x800458CC: sb          $t5, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r13;
    // 0x800458D0: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_800458D4:
    // 0x800458D4: lbu         $v1, 0x1CD($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X1CD);
    // 0x800458D8: nop

    // 0x800458DC: beq         $v1, $zero, L_800453E4
    if (ctx->r3 == 0) {
        // 0x800458E0: nop
    
            goto L_800453E4;
    }
    // 0x800458E0: nop

    // 0x800458E4: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
L_800458E8:
    // 0x800458E8: lw          $s0, 0x154($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X154);
    // 0x800458EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800458F0: beq         $s0, $zero, L_80045AE8
    if (ctx->r16 == 0) {
        // 0x800458F4: addiu       $s7, $zero, 0x3
        ctx->r23 = ADD32(0, 0X3);
            goto L_80045AE8;
    }
    // 0x800458F4: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x800458F8: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x800458FC: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80045900: bne         $t6, $at, L_80045950
    if (ctx->r14 != ctx->r1) {
        // 0x80045904: nop
    
            goto L_80045950;
    }
    // 0x80045904: nop

    // 0x80045908: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8004590C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045910: bne         $v1, $at, L_80045930
    if (ctx->r3 != ctx->r1) {
        // 0x80045914: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80045930;
    }
    // 0x80045914: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80045918: lb          $t7, 0xB($v0)
    ctx->r15 = MEM_B(ctx->r2, 0XB);
    // 0x8004591C: nop

    // 0x80045920: beq         $t7, $zero, L_80045934
    if (ctx->r15 == 0) {
        // 0x80045924: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80045934;
    }
    // 0x80045924: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80045928: lbu         $a0, 0x1CD($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0X1CD);
    // 0x8004592C: sw          $zero, 0x154($s5)
    MEM_W(0X154, ctx->r21) = 0;
L_80045930:
    // 0x80045930: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_80045934:
    // 0x80045934: bne         $a0, $at, L_80045950
    if (ctx->r4 != ctx->r1) {
        // 0x80045938: nop
    
            goto L_80045950;
    }
    // 0x80045938: nop

    // 0x8004593C: lb          $t8, 0xB($v0)
    ctx->r24 = MEM_B(ctx->r2, 0XB);
    // 0x80045940: nop

    // 0x80045944: beq         $s7, $t8, L_80045950
    if (ctx->r23 == ctx->r24) {
        // 0x80045948: nop
    
            goto L_80045950;
    }
    // 0x80045948: nop

    // 0x8004594C: sw          $zero, 0x154($s5)
    MEM_W(0X154, ctx->r21) = 0;
L_80045950:
    // 0x80045950: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80045954: lwc1        $f18, 0xC($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80045958: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8004595C: sub.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80045960: lwc1        $f10, 0x14($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80045964: mul.s       $f24, $f20, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80045968: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004596C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80045970: lwc1        $f6, 0x10($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80045974: mul.s       $f0, $f14, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80045978: sub.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004597C: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    // 0x80045980: mul.s       $f16, $f22, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80045984: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80045988: add.s       $f18, $f24, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f24.fl + ctx->f16.fl;
    // 0x8004598C: jal         0x800CA030
    // 0x80045990: add.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f0.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x80045990: add.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f0.fl;
    after_8:
    // 0x80045994: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80045998: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004599C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800459A0: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800459A4: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800459A8: bc1f        L_80045A70
    if (!c1cs) {
        // 0x800459AC: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80045A70;
    }
    // 0x800459AC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800459B0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800459B4: jal         0x80070990
    // 0x800459B8: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    arctan2_f(rdram, ctx);
        goto after_9;
    // 0x800459B8: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x800459BC: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800459C0: addu        $t9, $v0, $at
    ctx->r25 = ADD32(ctx->r2, ctx->r1);
    // 0x800459C4: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x800459C8: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    // 0x800459CC: lh          $t1, 0x1A0($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X1A0);
    // 0x800459D0: ori         $s1, $zero, 0x8001
    ctx->r17 = 0 | 0X8001;
    // 0x800459D4: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800459D8: subu        $v1, $t0, $t2
    ctx->r3 = SUB32(ctx->r8, ctx->r10);
    // 0x800459DC: lwc1        $f2, 0xA8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800459E0: slt         $at, $v1, $s1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800459E4: bne         $at, $zero, L_800459F4
    if (ctx->r1 != 0) {
        // 0x800459E8: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800459F4;
    }
    // 0x800459E8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800459EC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800459F0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800459F4:
    // 0x800459F4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800459F8: beq         $at, $zero, L_80045A04
    if (ctx->r1 == 0) {
        // 0x800459FC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80045A04;
    }
    // 0x800459FC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80045A00: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80045A04:
    // 0x80045A04: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80045A08: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x80045A0C: sra         $t4, $t3, 5
    ctx->r12 = S32(SIGNED(ctx->r11) >> 5);
    // 0x80045A10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045A14: sw          $t4, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r12;
    // 0x80045A18: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    // 0x80045A1C: jal         0x800CA030
    // 0x80045A20: add.s       $f12, $f24, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f24.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x80045A20: add.s       $f12, $f24, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f24.fl + ctx->f8.fl;
    after_10:
    // 0x80045A24: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80045A28: jal         0x80070990
    // 0x80045A2C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    arctan2_f(rdram, ctx);
        goto after_11;
    // 0x80045A2C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_11:
    // 0x80045A30: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80045A34: lwc1        $f2, 0xA8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80045A38: slt         $at, $a0, $s1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80045A3C: bne         $at, $zero, L_80045A50
    if (ctx->r1 != 0) {
        // 0x80045A40: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80045A50;
    }
    // 0x80045A40: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80045A44: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80045A48: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80045A4C: addu        $v1, $a0, $at
    ctx->r3 = ADD32(ctx->r4, ctx->r1);
L_80045A50:
    // 0x80045A50: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80045A54: beq         $at, $zero, L_80045A60
    if (ctx->r1 == 0) {
        // 0x80045A58: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80045A60;
    }
    // 0x80045A58: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80045A5C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80045A60:
    // 0x80045A60: negu        $t5, $v1
    ctx->r13 = SUB32(0, ctx->r3);
    // 0x80045A64: sra         $t6, $t5, 7
    ctx->r14 = S32(SIGNED(ctx->r13) >> 7);
    // 0x80045A68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045A6C: sw          $t6, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r14;
L_80045A70:
    // 0x80045A70: lb          $v0, 0x1CC($s5)
    ctx->r2 = MEM_B(ctx->r21, 0X1CC);
    // 0x80045A74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045A78: bgez        $v0, L_80045AA4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80045A7C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80045AA4;
    }
    // 0x80045A7C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80045A80: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
    // 0x80045A84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045A88: addiu       $t7, $zero, -0x23
    ctx->r15 = ADD32(0, -0X23);
    // 0x80045A8C: sw          $t7, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r15;
    // 0x80045A90: lb          $t8, 0x1CC($s5)
    ctx->r24 = MEM_B(ctx->r21, 0X1CC);
    // 0x80045A94: nop

    // 0x80045A98: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80045A9C: b           L_80045AEC
    // 0x80045AA0: sb          $t9, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = ctx->r25;
        goto L_80045AEC;
    // 0x80045AA0: sb          $t9, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = ctx->r25;
L_80045AA4:
    // 0x80045AA4: lw          $v1, -0x254C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X254C);
    // 0x80045AA8: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80045AAC: slti        $at, $v1, 0x3D
    ctx->r1 = SIGNED(ctx->r3) < 0X3D ? 1 : 0;
    // 0x80045AB0: beq         $at, $zero, L_80045AC0
    if (ctx->r1 == 0) {
        // 0x80045AB4: slti        $at, $v1, -0x3C
        ctx->r1 = SIGNED(ctx->r3) < -0X3C ? 1 : 0;
            goto L_80045AC0;
    }
    // 0x80045AB4: slti        $at, $v1, -0x3C
    ctx->r1 = SIGNED(ctx->r3) < -0X3C ? 1 : 0;
    // 0x80045AB8: beq         $at, $zero, L_80045AE0
    if (ctx->r1 == 0) {
        // 0x80045ABC: nop
    
            goto L_80045AE0;
    }
    // 0x80045ABC: nop

L_80045AC0:
    // 0x80045AC0: sb          $t1, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = ctx->r9;
    // 0x80045AC4: lb          $t0, 0x1CC($s5)
    ctx->r8 = MEM_B(ctx->r21, 0X1CC);
    // 0x80045AC8: addiu       $t2, $zero, -0x28
    ctx->r10 = ADD32(0, -0X28);
    // 0x80045ACC: slti        $at, $t0, 0x6F
    ctx->r1 = SIGNED(ctx->r8) < 0X6F ? 1 : 0;
    // 0x80045AD0: bne         $at, $zero, L_80045AEC
    if (ctx->r1 != 0) {
        // 0x80045AD4: nop
    
            goto L_80045AEC;
    }
    // 0x80045AD4: nop

    // 0x80045AD8: b           L_80045AEC
    // 0x80045ADC: sb          $t2, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = ctx->r10;
        goto L_80045AEC;
    // 0x80045ADC: sb          $t2, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = ctx->r10;
L_80045AE0:
    // 0x80045AE0: b           L_80045AEC
    // 0x80045AE4: sb          $zero, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = 0;
        goto L_80045AEC;
    // 0x80045AE4: sb          $zero, 0x1CC($s5)
    MEM_B(0X1CC, ctx->r21) = 0;
L_80045AE8:
    // 0x80045AE8: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_80045AEC:
    // 0x80045AEC: lbu         $t3, 0x1CD($s5)
    ctx->r11 = MEM_BU(ctx->r21, 0X1CD);
    // 0x80045AF0: nop

    // 0x80045AF4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80045AF8: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x80045AFC: beq         $at, $zero, L_80045C40
    if (ctx->r1 == 0) {
        // 0x80045B00: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80045C40;
    }
    // 0x80045B00: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80045B04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80045B08: addu        $at, $at, $t4
    gpr jr_addend_80045B14 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80045B0C: lw          $t4, 0x690C($at)
    ctx->r12 = ADD32(ctx->r1, 0X690C);
    // 0x80045B10: nop

    // 0x80045B14: jr          $t4
    // 0x80045B18: nop

    switch (jr_addend_80045B14 >> 2) {
        case 0: goto L_80045B1C; break;
        case 1: goto L_80045B38; break;
        case 2: goto L_80045B70; break;
        case 3: goto L_80045B70; break;
        case 4: goto L_80045B98; break;
        case 5: goto L_80045BB0; break;
        case 6: goto L_80045BF8; break;
        case 7: goto L_80045B1C; break;
        default: switch_error(__func__, 0x80045B14, 0x800E690C);
    }
    // 0x80045B18: nop

L_80045B1C:
    // 0x80045B1C: lw          $t5, 0x144($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X144);
    // 0x80045B20: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80045B24: beq         $t5, $zero, L_80045C44
    if (ctx->r13 == 0) {
        // 0x80045B28: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C44;
    }
    // 0x80045B28: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045B2C: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
    // 0x80045B30: b           L_80045C40
    // 0x80045B34: sb          $t6, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r14;
        goto L_80045C40;
    // 0x80045B34: sb          $t6, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r14;
L_80045B38:
    // 0x80045B38: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80045B3C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80045B40: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80045B44: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80045B48: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80045B4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80045B50: bc1f        L_80045C40
    if (!c1cs) {
        // 0x80045B54: addiu       $v0, $v0, -0x2554
        ctx->r2 = ADD32(ctx->r2, -0X2554);
            goto L_80045C40;
    }
    // 0x80045B54: addiu       $v0, $v0, -0x2554
    ctx->r2 = ADD32(ctx->r2, -0X2554);
    // 0x80045B58: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
    // 0x80045B5C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80045B60: nop

    // 0x80045B64: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x80045B68: b           L_80045C40
    // 0x80045B6C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_80045C40;
    // 0x80045B6C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80045B70:
    // 0x80045B70: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x80045B74: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80045B78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80045B7C: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x80045B80: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80045B84: nop

    // 0x80045B88: bc1f        L_80045C44
    if (!c1cs) {
        // 0x80045B8C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C44;
    }
    // 0x80045B8C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045B90: b           L_80045C40
    // 0x80045B94: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
        goto L_80045C40;
    // 0x80045B94: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_80045B98:
    // 0x80045B98: lb          $t9, 0x173($s5)
    ctx->r25 = MEM_B(ctx->r21, 0X173);
    // 0x80045B9C: nop

    // 0x80045BA0: beq         $t9, $zero, L_80045C44
    if (ctx->r25 == 0) {
        // 0x80045BA4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C44;
    }
    // 0x80045BA4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045BA8: b           L_80045C40
    // 0x80045BAC: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
        goto L_80045C40;
    // 0x80045BAC: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_80045BB0:
    // 0x80045BB0: lb          $t1, 0x173($s5)
    ctx->r9 = MEM_B(ctx->r21, 0X173);
    // 0x80045BB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80045BB8: bne         $t1, $zero, L_80045BC4
    if (ctx->r9 != 0) {
        // 0x80045BBC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80045BC4;
    }
    // 0x80045BBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80045BC0: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_80045BC4:
    // 0x80045BC4: lwc1        $f9, 0x6930($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6930);
    // 0x80045BC8: lwc1        $f8, 0x6934($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6934);
    // 0x80045BCC: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80045BD0: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80045BD4: addiu       $v0, $v0, -0x2550
    ctx->r2 = ADD32(ctx->r2, -0X2550);
    // 0x80045BD8: bc1f        L_80045C44
    if (!c1cs) {
        // 0x80045BDC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C44;
    }
    // 0x80045BDC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045BE0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80045BE4: nop

    // 0x80045BE8: ori         $t2, $t0, 0x2000
    ctx->r10 = ctx->r8 | 0X2000;
    // 0x80045BEC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80045BF0: b           L_80045C40
    // 0x80045BF4: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
        goto L_80045C40;
    // 0x80045BF4: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
L_80045BF8:
    // 0x80045BF8: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x80045BFC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80045C00: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80045C04: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80045C08: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80045C0C: nop

    // 0x80045C10: bc1f        L_80045C44
    if (!c1cs) {
        // 0x80045C14: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C44;
    }
    // 0x80045C14: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045C18: beq         $s0, $zero, L_80045C44
    if (ctx->r16 == 0) {
        // 0x80045C1C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80045C44;
    }
    // 0x80045C1C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80045C20: sb          $zero, 0x1CD($s5)
    MEM_B(0X1CD, ctx->r21) = 0;
    // 0x80045C24: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80045C28: nop

    // 0x80045C2C: lb          $t3, 0x9($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X9);
    // 0x80045C30: nop

    // 0x80045C34: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x80045C38: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x80045C3C: sb          $t5, 0x1CE($s5)
    MEM_B(0X1CE, ctx->r21) = ctx->r13;
L_80045C40:
    // 0x80045C40: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80045C44:
    // 0x80045C44: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80045C48: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80045C4C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80045C50: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80045C54: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80045C58: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80045C5C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80045C60: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80045C64: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80045C68: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80045C6C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80045C70: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80045C74: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80045C78: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80045C7C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80045C80: jr          $ra
    // 0x80045C84: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80045C84: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void timetrial_write_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059BCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059BD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80059BD4: lb          $v0, -0x24E4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X24E4);
    // 0x80059BD8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80059BDC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80059BE0: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x80059BE4: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80059BE8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80059BEC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80059BF0: lh          $t2, -0x24E0($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X24E0);
    // 0x80059BF4: lw          $t4, -0x24F0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X24F0);
    // 0x80059BF8: lh          $t0, 0x3A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3A);
    // 0x80059BFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80059C00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80059C04: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80059C08: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80059C0C: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80059C10: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x80059C14: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    // 0x80059C18: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80059C1C: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80059C20: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80059C24: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80059C28: jal         0x80075258
    // 0x80059C2C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80075000(rdram, ctx);
        goto after_0;
    // 0x80059C2C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x80059C30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80059C34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80059C38: jr          $ra
    // 0x80059C3C: nop

    return;
    // 0x80059C3C: nop

;}
RECOMP_FUNC void get_language(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F064: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009F068: lw          $t7, 0x69EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69EC);
    // 0x8009F06C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8009F070: andi        $t9, $t7, 0xC
    ctx->r25 = ctx->r15 & 0XC;
    // 0x8009F074: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009F078: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8009F07C: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
    // 0x8009F080: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8009F084: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009F088: beq         $t9, $at, L_8009F0B8
    if (ctx->r25 == ctx->r1) {
        // 0x8009F08C: nop
    
            goto L_8009F0B8;
    }
    // 0x8009F08C: nop

    // 0x8009F090: bne         $t8, $zero, L_8009F0A0
    if (ctx->r24 != 0) {
        // 0x8009F094: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8009F0A0;
    }
    // 0x8009F094: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8009F098: beq         $t9, $at, L_8009F0C0
    if (ctx->r25 == ctx->r1) {
        // 0x8009F09C: nop
    
            goto L_8009F0C0;
    }
    // 0x8009F09C: nop

L_8009F0A0:
    // 0x8009F0A0: bne         $t8, $zero, L_8009F0CC
    if (ctx->r24 != 0) {
        // 0x8009F0A4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8009F0CC;
    }
    // 0x8009F0A4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8009F0A8: beq         $t9, $at, L_8009F0C8
    if (ctx->r25 == ctx->r1) {
        // 0x8009F0AC: nop
    
            goto L_8009F0C8;
    }
    // 0x8009F0AC: nop

    // 0x8009F0B0: b           L_8009F0D0
    // 0x8009F0B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8009F0D0;
    // 0x8009F0B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009F0B8:
    // 0x8009F0B8: b           L_8009F0CC
    // 0x8009F0BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8009F0CC;
    // 0x8009F0BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8009F0C0:
    // 0x8009F0C0: b           L_8009F0CC
    // 0x8009F0C4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8009F0CC;
    // 0x8009F0C4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8009F0C8:
    // 0x8009F0C8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8009F0CC:
    // 0x8009F0CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009F0D0:
    // 0x8009F0D0: jr          $ra
    // 0x8009F0D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8009F0D4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void clear_lap_records(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E9B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006E9B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006E9B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006E9BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006E9C0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8006E9C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E9C8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8006E9CC: jal         0x8006B464
    // 0x8006E9D0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    level_count(rdram, ctx);
        goto after_0;
    // 0x8006E9D0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x8006E9D4: jal         0x8001E2D0
    // 0x8006E9D8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8006E9D8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_1:
    // 0x8006E9DC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8006E9E0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8006E9E4: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8006E9E8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_8006E9EC:
    // 0x8006E9EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006E9F0: blez        $t6, L_8006EBB4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006E9F4: andi        $t2, $s1, 0x1
        ctx->r10 = ctx->r17 & 0X1;
            goto L_8006EBB4;
    }
    // 0x8006E9F4: andi        $t2, $s1, 0x1
    ctx->r10 = ctx->r17 & 0X1;
    // 0x8006E9F8: andi        $v1, $t6, 0x1
    ctx->r3 = ctx->r14 & 0X1;
    // 0x8006E9FC: beq         $v1, $zero, L_8006EA7C
    if (ctx->r3 == 0) {
        // 0x8006EA00: andi        $t3, $s1, 0x2
        ctx->r11 = ctx->r17 & 0X2;
            goto L_8006EA7C;
    }
    // 0x8006EA00: andi        $t3, $s1, 0x2
    ctx->r11 = ctx->r17 & 0X2;
    // 0x8006EA04: beq         $t2, $zero, L_8006EA38
    if (ctx->r10 == 0) {
        // 0x8006EA08: sll         $v1, $t0, 2
        ctx->r3 = S32(ctx->r8 << 2);
            goto L_8006EA38;
    }
    // 0x8006EA08: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EA0C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8006EA10: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8006EA14: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EA18: lw          $t9, 0x18($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X18);
    // 0x8006EA1C: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
    // 0x8006EA20: nop

    // 0x8006EA24: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8006EA28: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8006EA2C: lhu         $t5, 0x4($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X4);
    // 0x8006EA30: nop

    // 0x8006EA34: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
L_8006EA38:
    // 0x8006EA38: beq         $t3, $zero, L_8006EA6C
    if (ctx->r11 == 0) {
        // 0x8006EA3C: sll         $v1, $t0, 2
        ctx->r3 = S32(ctx->r8 << 2);
            goto L_8006EA6C;
    }
    // 0x8006EA3C: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EA40: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8006EA44: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8006EA48: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EA4C: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    // 0x8006EA50: lhu         $t8, 0x2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2);
    // 0x8006EA54: nop

    // 0x8006EA58: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8006EA5C: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8006EA60: lhu         $t5, 0x0($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X0);
    // 0x8006EA64: nop

    // 0x8006EA68: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
L_8006EA6C:
    // 0x8006EA6C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8006EA70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8006EA74: beq         $a3, $t7, L_8006EBB4
    if (ctx->r7 == ctx->r15) {
        // 0x8006EA78: nop
    
            goto L_8006EBB4;
    }
    // 0x8006EA78: nop

L_8006EA7C:
    // 0x8006EA7C: beq         $t2, $zero, L_8006EAC4
    if (ctx->r10 == 0) {
        // 0x8006EA80: nop
    
            goto L_8006EAC4;
    }
    // 0x8006EA80: nop

    // 0x8006EA84: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006EA88: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EA8C: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EA90: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x8006EA94: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006EA98: mflo        $t8
    ctx->r24 = lo;
    // 0x8006EA9C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8006EAA0: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8006EAA4: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006EAA8: lhu         $t6, 0x6($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X6);
    // 0x8006EAAC: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8006EAB0: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x8006EAB4: lw          $t5, 0x24($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X24);
    // 0x8006EAB8: lhu         $t9, 0x4($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X4);
    // 0x8006EABC: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006EAC0: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
L_8006EAC4:
    // 0x8006EAC4: beq         $t3, $zero, L_8006EB0C
    if (ctx->r11 == 0) {
        // 0x8006EAC8: nop
    
            goto L_8006EB0C;
    }
    // 0x8006EAC8: nop

    // 0x8006EACC: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006EAD0: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EAD4: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EAD8: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x8006EADC: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006EAE0: mflo        $t6
    ctx->r14 = lo;
    // 0x8006EAE4: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x8006EAE8: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x8006EAEC: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006EAF0: lhu         $t9, 0x2($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X2);
    // 0x8006EAF4: addu        $t6, $t7, $a1
    ctx->r14 = ADD32(ctx->r15, ctx->r5);
    // 0x8006EAF8: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x8006EAFC: lw          $t5, 0x3C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X3C);
    // 0x8006EB00: lhu         $t8, 0x0($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X0);
    // 0x8006EB04: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006EB08: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
L_8006EB0C:
    // 0x8006EB0C: beq         $t2, $zero, L_8006EB58
    if (ctx->r10 == 0) {
        // 0x8006EB10: nop
    
            goto L_8006EB58;
    }
    // 0x8006EB10: nop

    // 0x8006EB14: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006EB18: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EB1C: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EB20: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x8006EB24: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006EB28: mflo        $t9
    ctx->r25 = lo;
    // 0x8006EB2C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006EB30: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x8006EB34: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006EB38: lhu         $t8, 0x1E($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X1E);
    // 0x8006EB3C: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x8006EB40: sh          $t8, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r24;
    // 0x8006EB44: lw          $t5, 0x24($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X24);
    // 0x8006EB48: lhu         $t6, 0x1C($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X1C);
    // 0x8006EB4C: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006EB50: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x8006EB54: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
L_8006EB58:
    // 0x8006EB58: beq         $t3, $zero, L_8006EBA8
    if (ctx->r11 == 0) {
        // 0x8006EB5C: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_8006EBA8;
    }
    // 0x8006EB5C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006EB60: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006EB64: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8006EB68: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x8006EB6C: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    // 0x8006EB70: sll         $a1, $a3, 1
    ctx->r5 = S32(ctx->r7 << 1);
    // 0x8006EB74: mflo        $t8
    ctx->r24 = lo;
    // 0x8006EB78: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8006EB7C: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8006EB80: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
    // 0x8006EB84: lhu         $t6, 0x1A($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X1A);
    // 0x8006EB88: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8006EB8C: sh          $t6, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r14;
    // 0x8006EB90: lw          $t5, 0x3C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X3C);
    // 0x8006EB94: lhu         $t9, 0x18($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X18);
    // 0x8006EB98: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x8006EB9C: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x8006EBA0: sh          $t9, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r25;
    // 0x8006EBA4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_8006EBA8:
    // 0x8006EBA8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8006EBAC: bne         $a3, $t6, L_8006EA7C
    if (ctx->r7 != ctx->r14) {
        // 0x8006EBB0: nop
    
            goto L_8006EA7C;
    }
    // 0x8006EBB0: nop

L_8006EBB4:
    // 0x8006EBB4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8006EBB8: bne         $t0, $t4, L_8006E9EC
    if (ctx->r8 != ctx->r12) {
        // 0x8006EBBC: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_8006E9EC;
    }
    // 0x8006EBBC: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8006EBC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EBC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006EBC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006EBCC: jr          $ra
    // 0x8006EBD0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006EBD0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alSeqChOff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063D30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063D3C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063D40: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063D44: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063D48: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80063D4C: addiu       $t8, $zero, 0x6A
    ctx->r24 = ADD32(0, 0X6A);
    // 0x80063D50: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063D54: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063D58: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063D5C: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063D60: sb          $a3, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r7;
    // 0x80063D64: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063D68: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063D6C: jal         0x800C970C
    // 0x80063D70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063D70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80063D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063D7C: jr          $ra
    // 0x80063D80: nop

    return;
    // 0x80063D80: nop

;}
RECOMP_FUNC void instShowBearBar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E128: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x8000E12C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E130: jr          $ra
    // 0x8000E134: sh          $t6, -0x3388($at)
    MEM_H(-0X3388, ctx->r1) = ctx->r14;
    return;
    // 0x8000E134: sh          $t6, -0x3388($at)
    MEM_H(-0X3388, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void trackmenu_setup_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800913E8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800913EC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800913F0: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800913F4: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800913F8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800913FC: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80091400: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80091404: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80091408: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8009140C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80091410: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80091414: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80091418: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8009141C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80091420: jal         0x8006ECD0
    // 0x80091424: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80091424: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    after_0:
    // 0x80091428: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8009142C: addiu       $s0, $s0, 0x300
    ctx->r16 = ADD32(ctx->r16, 0X300);
    // 0x80091430: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80091434: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80091438: bne         $t6, $zero, L_80091448
    if (ctx->r14 != 0) {
        // 0x8009143C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80091448;
    }
    // 0x8009143C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80091440: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80091444: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
L_80091448:
    // 0x80091448: lw          $t8, -0x5C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5C4);
    // 0x8009144C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091450: bne         $t8, $at, L_80091488
    if (ctx->r24 != ctx->r1) {
        // 0x80091454: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80091488;
    }
    // 0x80091454: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80091458: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009145C: lw          $t9, 0x6F88($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6F88);
    // 0x80091460: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80091464: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80091468: beq         $at, $zero, L_80091488
    if (ctx->r1 == 0) {
        // 0x8009146C: nop
    
            goto L_80091488;
    }
    // 0x8009146C: nop

    // 0x80091470: lw          $t0, 0x6980($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6980);
    // 0x80091474: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80091478: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x8009147C: bne         $at, $zero, L_80091488
    if (ctx->r1 != 0) {
        // 0x80091480: nop
    
            goto L_80091488;
    }
    // 0x80091480: nop

    // 0x80091484: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
L_80091488:
    // 0x80091488: jal         0x80066AD4
    // 0x8009148C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camDisableUserView(rdram, ctx);
        goto after_1;
    // 0x8009148C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80091490: jal         0x8009C2A0
    // 0x80091494: nop

    menu_camera_centre(rdram, ctx);
        goto after_2;
    // 0x80091494: nop

    after_2:
    // 0x80091498: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009149C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800914A0: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x800914A4: jal         0x8006816C
    // 0x800914A8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    mtx_ortho(rdram, ctx);
        goto after_3;
    // 0x800914A8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_3:
    // 0x800914AC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800914B0: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x800914B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800914B8: bgez        $v0, L_80091560
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800914BC: addiu       $v1, $v1, -0x324
        ctx->r3 = ADD32(ctx->r3, -0X324);
            goto L_80091560;
    }
    // 0x800914BC: addiu       $v1, $v1, -0x324
    ctx->r3 = ADD32(ctx->r3, -0X324);
    // 0x800914C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800914C4: lw          $v0, 0x6FB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6FB4);
    // 0x800914C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800914CC: bne         $v0, $at, L_800914E0
    if (ctx->r2 != ctx->r1) {
        // 0x800914D0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800914E0;
    }
    // 0x800914D0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800914D4: b           L_80091500
    // 0x800914D8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
        goto L_80091500;
    // 0x800914D8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800914DC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_800914E0:
    // 0x800914E0: bne         $v0, $at, L_800914F8
    if (ctx->r2 != ctx->r1) {
        // 0x800914E4: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_800914F8;
    }
    // 0x800914E4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800914E8: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x800914EC: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
    // 0x800914F0: b           L_80091500
    // 0x800914F4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
        goto L_80091500;
    // 0x800914F4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800914F8:
    // 0x800914F8: sw          $t3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r11;
    // 0x800914FC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80091500:
    // 0x80091500: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80091504: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80091508: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x8009150C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80091510: swc1        $f0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f0.u32l;
    // 0x80091514: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80091518: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009151C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80091520: swc1        $f0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f0.u32l;
    // 0x80091524: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80091528: nop

    // 0x8009152C: bne         $t8, $zero, L_80091540
    if (ctx->r24 != 0) {
        // 0x80091530: nop
    
            goto L_80091540;
    }
    // 0x80091530: nop

    // 0x80091534: lwc1        $f4, -0x7580($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7580);
    // 0x80091538: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009153C: swc1        $f4, -0x62C($at)
    MEM_W(-0X62C, ctx->r1) = ctx->f4.u32l;
L_80091540:
    // 0x80091540: jal         0x8009CFA4
    // 0x80091544: nop

    menu_element_render(rdram, ctx);
        goto after_4;
    // 0x80091544: nop

    after_4:
    // 0x80091548: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009154C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80091550: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091554: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80091558: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8009155C: swc1        $f6, -0x62C($at)
    MEM_W(-0X62C, ctx->r1) = ctx->f6.u32l;
L_80091560:
    // 0x80091560: slti        $at, $v0, -0x16
    ctx->r1 = SIGNED(ctx->r2) < -0X16 ? 1 : 0;
    // 0x80091564: bne         $at, $zero, L_80092674
    if (ctx->r1 != 0) {
        // 0x80091568: slti        $at, $v0, 0x1F
        ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
            goto L_80092674;
    }
    // 0x80091568: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8009156C: beq         $at, $zero, L_80092674
    if (ctx->r1 == 0) {
        // 0x80091570: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80092674;
    }
    // 0x80091570: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80091574: bgez        $v0, L_80091590
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80091578: lui         $fp, 0x800E
        ctx->r30 = S32(0X800E << 16);
            goto L_80091590;
    }
    // 0x80091578: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8009157C: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80091580: addiu       $t0, $t9, 0xFF
    ctx->r8 = ADD32(ctx->r25, 0XFF);
    // 0x80091584: addiu       $fp, $fp, -0x31C
    ctx->r30 = ADD32(ctx->r30, -0X31C);
    // 0x80091588: b           L_800915A0
    // 0x8009158C: sw          $t0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r8;
        goto L_800915A0;
    // 0x8009158C: sw          $t0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r8;
L_80091590:
    // 0x80091590: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80091594: addiu       $fp, $fp, -0x31C
    ctx->r30 = ADD32(ctx->r30, -0X31C);
    // 0x80091598: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009159C: sw          $t1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r9;
L_800915A0:
    // 0x800915A0: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800915A4: nop

    // 0x800915A8: bgez        $t2, L_800915B4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800915AC: nop
    
            goto L_800915B4;
    }
    // 0x800915AC: nop

    // 0x800915B0: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
L_800915B4:
    // 0x800915B4: lw          $a0, -0x5BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5BC);
    // 0x800915B8: jal         0x8006B338
    // 0x800915BC: nop

    leveltable_vehicle_usable(rdram, ctx);
        goto after_5;
    // 0x800915BC: nop

    after_5:
    // 0x800915C0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800915C4: lw          $t3, -0x5C4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5C4);
    // 0x800915C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800915CC: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800915D0: bne         $at, $zero, L_80091604
    if (ctx->r1 != 0) {
        // 0x800915D4: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80091604;
    }
    // 0x800915D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800915D8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800915DC: lw          $v1, -0x5BC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5BC);
    // 0x800915E0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800915E4: bne         $v1, $at, L_800915F0
    if (ctx->r3 != ctx->r1) {
        // 0x800915E8: addiu       $at, $zero, -0x3
        ctx->r1 = ADD32(0, -0X3);
            goto L_800915F0;
    }
    // 0x800915E8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800915EC: and         $a1, $v0, $at
    ctx->r5 = ctx->r2 & ctx->r1;
L_800915F0:
    // 0x800915F0: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800915F4: bne         $v1, $at, L_80091604
    if (ctx->r3 != ctx->r1) {
        // 0x800915F8: addiu       $at, $zero, -0x5
        ctx->r1 = ADD32(0, -0X5);
            goto L_80091604;
    }
    // 0x800915F8: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800915FC: and         $t4, $a1, $at
    ctx->r12 = ctx->r5 & ctx->r1;
    // 0x80091600: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_80091604:
    // 0x80091604: lw          $a0, -0x5BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5BC);
    // 0x80091608: jal         0x8006C01C
    // 0x8009160C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    level_name(rdram, ctx);
        goto after_6;
    // 0x8009160C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    after_6:
    // 0x80091610: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80091614: jal         0x800C484C
    // 0x80091618: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x80091618: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x8009161C: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x80091620: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x80091624: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x80091628: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009162C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80091630: jal         0x800C48E4
    // 0x80091634: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x80091634: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_8:
    // 0x80091638: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009163C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80091640: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80091644: jal         0x800C492C
    // 0x80091648: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_9;
    // 0x80091648: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x8009164C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091650: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80091654: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80091658: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8009165C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80091660: addiu       $a2, $zero, 0x2B
    ctx->r6 = ADD32(0, 0X2B);
    // 0x80091664: jal         0x800C49A0
    // 0x80091668: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_10;
    // 0x80091668: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_10:
    // 0x8009166C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80091670: lw          $a2, 0x695C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X695C);
    // 0x80091674: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80091678: sll         $t7, $a2, 3
    ctx->r15 = S32(ctx->r6 << 3);
    // 0x8009167C: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80091680: bne         $at, $zero, L_80091690
    if (ctx->r1 != 0) {
        // 0x80091684: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_80091690;
    }
    // 0x80091684: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80091688: addiu       $t8, $zero, 0x1FF
    ctx->r24 = ADD32(0, 0X1FF);
    // 0x8009168C: subu        $a2, $t8, $t7
    ctx->r6 = SUB32(ctx->r24, ctx->r15);
L_80091690:
    // 0x80091690: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x80091694: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80091698: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009169C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    // 0x800916A0: jal         0x800C551C
    // 0x800916A4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_11;
    // 0x800916A4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_11:
    // 0x800916A8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800916AC: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x800916B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800916B4: beq         $v0, $at, L_800916E0
    if (ctx->r2 == ctx->r1) {
        // 0x800916B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800916E0;
    }
    // 0x800916B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800916BC: bne         $v0, $at, L_8009188C
    if (ctx->r2 != ctx->r1) {
        // 0x800916C0: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8009188C;
    }
    // 0x800916C0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800916C4: lw          $t0, 0x6F88($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6F88);
    // 0x800916C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800916CC: bne         $t0, $at, L_8009188C
    if (ctx->r8 != ctx->r1) {
        // 0x800916D0: nop
    
            goto L_8009188C;
    }
    // 0x800916D0: nop

    // 0x800916D4: jal         0x8009F1A4
    // 0x800916D8: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_12;
    // 0x800916D8: nop

    after_12:
    // 0x800916DC: beq         $v0, $zero, L_8009188C
    if (ctx->r2 == 0) {
        // 0x800916E0: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8009188C;
    }
L_800916E0:
    // 0x800916E0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800916E4: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x800916E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800916EC: lw          $a0, 0x248($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X248);
    // 0x800916F0: jal         0x800C5300
    // 0x800916F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_text_width(rdram, ctx);
        goto after_13;
    // 0x800916F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x800916F8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800916FC: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x80091700: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80091704: lw          $a0, 0x24C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X24C);
    // 0x80091708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009170C: jal         0x800C5300
    // 0x80091710: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_text_width(rdram, ctx);
        goto after_14;
    // 0x80091710: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80091714: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80091718: beq         $at, $zero, L_80091724
    if (ctx->r1 == 0) {
        // 0x8009171C: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_80091724;
    }
    // 0x8009171C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80091720: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_80091724:
    // 0x80091724: addiu       $s0, $s0, 0xC80
    ctx->r16 = ADD32(ctx->r16, 0XC80);
    // 0x80091728: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x8009172C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091730: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80091734: beq         $at, $zero, L_80091744
    if (ctx->r1 == 0) {
        // 0x80091738: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_80091744;
    }
    // 0x80091738: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8009173C: b           L_80091748
    // 0x80091740: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
        goto L_80091748;
    // 0x80091740: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_80091744:
    // 0x80091744: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
L_80091748:
    // 0x80091748: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8009174C: lui         $at, 0xB0E0
    ctx->r1 = S32(0XB0E0 << 16);
    // 0x80091750: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80091754: lw          $t0, 0x6BFC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6BFC);
    // 0x80091758: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x8009175C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80091760: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x80091764: lh          $t7, 0xA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA);
    // 0x80091768: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8009176C: sra         $a1, $s4, 1
    ctx->r5 = S32(SIGNED(ctx->r20) >> 1);
    // 0x80091770: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x80091774: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80091778: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8009177C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80091780: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80091784: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80091788: subu        $a2, $t4, $t3
    ctx->r6 = SUB32(ctx->r12, ctx->r11);
    // 0x8009178C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80091790: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80091794: jal         0x800809D0
    // 0x80091798: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_80080580(rdram, ctx);
        goto after_15;
    // 0x80091798: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_15:
    // 0x8009179C: jal         0x800812BC
    // 0x800917A0: nop

    menu_geometry_end(rdram, ctx);
        goto after_16;
    // 0x800917A0: nop

    after_16:
    // 0x800917A4: jal         0x800C484C
    // 0x800917A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_17;
    // 0x800917A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x800917AC: lh          $t1, 0xE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XE);
    // 0x800917B0: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x800917B4: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x800917B8: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x800917BC: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800917C0: addu        $s7, $t4, $t3
    ctx->r23 = ADD32(ctx->r12, ctx->r11);
    // 0x800917C4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800917C8: addiu       $s6, $s6, 0x998
    ctx->r22 = ADD32(ctx->r22, 0X998);
    // 0x800917CC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800917D0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800917D4: addiu       $s2, $zero, 0xA1
    ctx->r18 = ADD32(0, 0XA1);
L_800917D8:
    // 0x800917D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800917DC: or          $s0, $s7, $zero
    ctx->r16 = ctx->r23 | 0;
L_800917E0:
    // 0x800917E0: bne         $s3, $zero, L_80091810
    if (ctx->r19 != 0) {
        // 0x800917E4: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80091810;
    }
    // 0x800917E4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800917E8: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x800917EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800917F0: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800917F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800917F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800917FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80091800: jal         0x800C48E4
    // 0x80091804: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x80091804: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_18:
    // 0x80091808: b           L_8009183C
    // 0x8009180C: nop

        goto L_8009183C;
    // 0x8009180C: nop

L_80091810:
    // 0x80091810: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x80091814: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80091818: bne         $s4, $t7, L_80091828
    if (ctx->r20 != ctx->r15) {
        // 0x8009181C: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80091828;
    }
    // 0x8009181C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80091820: lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X84);
    // 0x80091824: nop

L_80091828:
    // 0x80091828: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8009182C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80091830: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80091834: jal         0x800C48E4
    // 0x80091838: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    set_text_colour(rdram, ctx);
        goto after_19;
    // 0x80091838: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_19:
L_8009183C:
    // 0x8009183C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80091840: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x80091844: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091848: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x8009184C: lw          $a3, 0x248($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X248);
    // 0x80091850: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80091854: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80091858: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8009185C: subu        $a1, $s2, $s3
    ctx->r5 = SUB32(ctx->r18, ctx->r19);
    // 0x80091860: jal         0x800C49A0
    // 0x80091864: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    draw_text(rdram, ctx);
        goto after_20;
    // 0x80091864: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_20:
    // 0x80091868: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x8009186C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80091870: bne         $s3, $at, L_800917E0
    if (ctx->r19 != ctx->r1) {
        // 0x80091874: addiu       $s0, $s0, -0x2
        ctx->r16 = ADD32(ctx->r16, -0X2);
            goto L_800917E0;
    }
    // 0x80091874: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // 0x80091878: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8009187C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091880: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80091884: bne         $s4, $at, L_800917D8
    if (ctx->r20 != ctx->r1) {
        // 0x80091888: addiu       $s7, $s7, 0x10
        ctx->r23 = ADD32(ctx->r23, 0X10);
            goto L_800917D8;
    }
    // 0x80091888: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
L_8009188C:
    // 0x8009188C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80091890: lw          $t2, 0x6F88($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6F88);
    // 0x80091894: nop

    // 0x80091898: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x8009189C: beq         $at, $zero, L_80092400
    if (ctx->r1 == 0) {
        // 0x800918A0: nop
    
            goto L_80092400;
    }
    // 0x800918A0: nop

    // 0x800918A4: jal         0x800C484C
    // 0x800918A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_21;
    // 0x800918A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
    // 0x800918AC: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x800918B0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800918B4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800918B8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800918BC: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x800918C0: jal         0x800C48E4
    // 0x800918C4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    set_text_colour(rdram, ctx);
        goto after_22;
    // 0x800918C4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_22:
    // 0x800918C8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800918CC: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x800918D0: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x800918D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800918D8: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800918DC: lw          $a3, 0x24($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X24);
    // 0x800918E0: addiu       $s0, $s0, 0x48
    ctx->r16 = ADD32(ctx->r16, 0X48);
    // 0x800918E4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800918E8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800918EC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800918F0: jal         0x800C49A0
    // 0x800918F4: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    draw_text(rdram, ctx);
        goto after_23;
    // 0x800918F4: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_23:
    // 0x800918F8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800918FC: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x80091900: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x80091904: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091908: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8009190C: lw          $a3, 0x28($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X28);
    // 0x80091910: addiu       $s2, $s2, 0x5C
    ctx->r18 = ADD32(ctx->r18, 0X5C);
    // 0x80091914: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80091918: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009191C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091920: jal         0x800C49A0
    // 0x80091924: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    draw_text(rdram, ctx);
        goto after_24;
    // 0x80091924: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_24:
    // 0x80091928: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8009192C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80091930: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80091934: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80091938: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x8009193C: jal         0x800C48E4
    // 0x80091940: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    set_text_colour(rdram, ctx);
        goto after_25;
    // 0x80091940: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_25:
    // 0x80091944: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80091948: lb          $t0, 0x6F80($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X6F80);
    // 0x8009194C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80091950: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80091954: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80091958: lw          $t3, -0x5BC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5BC);
    // 0x8009195C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80091960: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x80091964: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80091968: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8009196C: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x80091970: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x80091974: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80091978: jal         0x80097C34
    // 0x8009197C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_26;
    // 0x8009197C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_26:
    // 0x80091980: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091984: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80091988: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009198C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091990: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x80091994: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80091998: jal         0x800C49A0
    // 0x8009199C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    draw_text(rdram, ctx);
        goto after_27;
    // 0x8009199C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_27:
    // 0x800919A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800919A4: lb          $t0, 0x6F80($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X6F80);
    // 0x800919A8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800919AC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800919B0: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800919B4: lw          $t3, -0x5BC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5BC);
    // 0x800919B8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800919BC: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x800919C0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800919C4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800919C8: lhu         $a0, 0x0($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X0);
    // 0x800919CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800919D0: jal         0x80097C34
    // 0x800919D4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_28;
    // 0x800919D4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_28:
    // 0x800919D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800919DC: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x800919E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800919E4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800919E8: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x800919EC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800919F0: jal         0x800C49A0
    // 0x800919F4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    draw_text(rdram, ctx);
        goto after_29;
    // 0x800919F4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_29:
    // 0x800919F8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800919FC: lb          $t0, 0x6F80($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X6F80);
    // 0x80091A00: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80091A04: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80091A08: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80091A0C: lw          $t3, -0x5BC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5BC);
    // 0x80091A10: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80091A14: lw          $t1, 0x3C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X3C);
    // 0x80091A18: sll         $t2, $t3, 1
    ctx->r10 = S32(ctx->r11 << 1);
    // 0x80091A1C: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x80091A20: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    // 0x80091A24: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80091A28: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80091A2C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80091A30: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80091A34: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80091A38: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80091A3C: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x80091A40: jal         0x80081C50
    // 0x80091A44: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    menu_timestamp_render(rdram, ctx);
        goto after_30;
    // 0x80091A44: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_30:
    // 0x80091A48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80091A4C: lb          $t7, 0x6F80($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6F80);
    // 0x80091A50: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80091A54: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80091A58: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80091A5C: lw          $t1, -0x5BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5BC);
    // 0x80091A60: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x80091A64: lw          $t3, 0x24($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X24);
    // 0x80091A68: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80091A6C: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x80091A70: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    // 0x80091A74: addiu       $t5, $zero, 0xC0
    ctx->r13 = ADD32(0, 0XC0);
    // 0x80091A78: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80091A7C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80091A80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80091A84: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80091A88: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80091A8C: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x80091A90: jal         0x80081C50
    // 0x80091A94: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    menu_timestamp_render(rdram, ctx);
        goto after_31;
    // 0x80091A94: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_31:
    // 0x80091A98: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80091A9C: lw          $t7, 0x6980($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6980);
    // 0x80091AA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80091AA4: beq         $t7, $at, L_80092400
    if (ctx->r15 == ctx->r1) {
        // 0x80091AA8: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80092400;
    }
    // 0x80091AA8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091AAC: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x80091AB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80091AB4: bne         $v0, $at, L_80091C40
    if (ctx->r2 != ctx->r1) {
        // 0x80091AB8: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80091C40;
    }
    // 0x80091AB8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80091ABC: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80091AC0: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    // 0x80091AC4: addiu       $t8, $t0, 0x89
    ctx->r24 = ADD32(ctx->r8, 0X89);
    // 0x80091AC8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80091ACC: addiu       $a3, $zero, 0xBA
    ctx->r7 = ADD32(0, 0XBA);
    // 0x80091AD0: jal         0x800C543C
    // 0x80091AD4: addiu       $a2, $t0, 0x70
    ctx->r6 = ADD32(ctx->r8, 0X70);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_32;
    // 0x80091AD4: addiu       $a2, $t0, 0x70
    ctx->r6 = ADD32(ctx->r8, 0X70);
    after_32:
    // 0x80091AD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091ADC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80091AE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80091AE8: jal         0x800C60B8
    // 0x80091AEC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_33;
    // 0x80091AEC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_33:
    // 0x80091AF0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80091AF4: lw          $t9, 0x6980($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6980);
    // 0x80091AF8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091AFC: bgtz        $t9, L_80091B4C
    if (SIGNED(ctx->r25) > 0) {
        // 0x80091B00: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_80091B4C;
    }
    // 0x80091B00: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091B04: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    // 0x80091B08: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x80091B0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091B10: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80091B14: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80091B18: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80091B1C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80091B20: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80091B24: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80091B28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80091B2C: addiu       $a1, $a1, 0xB34
    ctx->r5 = ADD32(ctx->r5, 0XB34);
    // 0x80091B30: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091B34: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x80091B38: addiu       $a3, $a3, 0x72
    ctx->r7 = ADD32(ctx->r7, 0X72);
    // 0x80091B3C: jal         0x80078F08
    // 0x80091B40: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    texrect_draw(rdram, ctx);
        goto after_34;
    // 0x80091B40: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    after_34:
    // 0x80091B44: b           L_80091C30
    // 0x80091B48: nop

        goto L_80091C30;
    // 0x80091B48: nop

L_80091B4C:
    // 0x80091B4C: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    // 0x80091B50: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x80091B54: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80091B58: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80091B5C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80091B60: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80091B64: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80091B68: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80091B6C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80091B70: addiu       $a1, $a1, 0xB44
    ctx->r5 = ADD32(ctx->r5, 0XB44);
    // 0x80091B74: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x80091B78: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80091B7C: addiu       $a3, $a3, 0x72
    ctx->r7 = ADD32(ctx->r7, 0X72);
    // 0x80091B80: jal         0x80078F08
    // 0x80091B84: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    texrect_draw(rdram, ctx);
        goto after_35;
    // 0x80091B84: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_35:
    // 0x80091B88: lw          $s7, 0x80($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X80);
    // 0x80091B8C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80091B90: addiu       $s0, $s0, 0xBC8
    ctx->r16 = ADD32(ctx->r16, 0XBC8);
    // 0x80091B94: addiu       $s7, $s7, 0x97
    ctx->r23 = ADD32(ctx->r23, 0X97);
L_80091B98:
    // 0x80091B98: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80091B9C: lw          $t8, 0x994($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X994);
    // 0x80091BA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091BA4: bne         $s5, $t8, L_80091BEC
    if (ctx->r21 != ctx->r24) {
        // 0x80091BA8: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_80091BEC;
    }
    // 0x80091BA8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091BAC: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x80091BB0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091BB4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80091BB8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80091BBC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80091BC0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80091BC4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80091BC8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80091BCC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80091BD0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091BD4: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    // 0x80091BD8: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80091BDC: jal         0x80078F08
    // 0x80091BE0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    texrect_draw(rdram, ctx);
        goto after_36;
    // 0x80091BE0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    after_36:
    // 0x80091BE4: b           L_80091C20
    // 0x80091BE8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
        goto L_80091C20;
    // 0x80091BE8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_80091BEC:
    // 0x80091BEC: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80091BF0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80091BF4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80091BF8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80091BFC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80091C00: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80091C04: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80091C08: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80091C0C: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    // 0x80091C10: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80091C14: jal         0x80078F08
    // 0x80091C18: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    texrect_draw(rdram, ctx);
        goto after_37;
    // 0x80091C18: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_37:
    // 0x80091C1C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_80091C20:
    // 0x80091C20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091C24: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80091C28: bne         $s5, $at, L_80091B98
    if (ctx->r21 != ctx->r1) {
        // 0x80091C2C: addiu       $s7, $s7, 0x18
        ctx->r23 = ADD32(ctx->r23, 0X18);
            goto L_80091B98;
    }
    // 0x80091C2C: addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
L_80091C30:
    // 0x80091C30: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091C34: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x80091C38: b           L_80091D68
    // 0x80091C3C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
        goto L_80091D68;
    // 0x80091C3C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80091C40:
    // 0x80091C40: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80091C44: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80091C48: bne         $t0, $zero, L_80091D68
    if (ctx->r8 != 0) {
        // 0x80091C4C: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80091D68;
    }
    // 0x80091C4C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80091C50: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091C54: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80091C58: addiu       $t1, $t1, 0xC08
    ctx->r9 = ADD32(ctx->r9, 0XC08);
    // 0x80091C5C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80091C60: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80091C64: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80091C68: addiu       $s2, $s2, 0x6F84
    ctx->r18 = ADD32(ctx->r18, 0X6F84);
    // 0x80091C6C: addiu       $s1, $s1, 0xBE0
    ctx->r17 = ADD32(ctx->r17, 0XBE0);
    // 0x80091C70: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80091C74: mflo        $s3
    ctx->r19 = lo;
    // 0x80091C78: sll         $t9, $s3, 1
    ctx->r25 = S32(ctx->r19 << 1);
    // 0x80091C7C: blez        $v0, L_80091D64
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80091C80: addu        $s0, $t9, $t1
        ctx->r16 = ADD32(ctx->r25, ctx->r9);
            goto L_80091D64;
    }
    // 0x80091C80: addu        $s0, $t9, $t1
    ctx->r16 = ADD32(ctx->r25, ctx->r9);
L_80091C84:
    // 0x80091C84: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091C88: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x80091C8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80091C90: bne         $v0, $at, L_80091CA4
    if (ctx->r2 != ctx->r1) {
        // 0x80091C94: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_80091CA4;
    }
    // 0x80091C94: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80091C98: lw          $t3, 0x6980($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6980);
    // 0x80091C9C: nop

    // 0x80091CA0: beq         $s5, $t3, L_80091CC0
    if (ctx->r21 == ctx->r11) {
        // 0x80091CA4: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80091CC0;
    }
L_80091CA4:
    // 0x80091CA4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80091CA8: bne         $at, $zero, L_80091D04
    if (ctx->r1 != 0) {
        // 0x80091CAC: addu        $t2, $s2, $s5
        ctx->r10 = ADD32(ctx->r18, ctx->r21);
            goto L_80091D04;
    }
    // 0x80091CAC: addu        $t2, $s2, $s5
    ctx->r10 = ADD32(ctx->r18, ctx->r21);
    // 0x80091CB0: lb          $t4, 0x0($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X0);
    // 0x80091CB4: nop

    // 0x80091CB8: bne         $t4, $zero, L_80091D04
    if (ctx->r12 != 0) {
        // 0x80091CBC: nop
    
            goto L_80091D04;
    }
    // 0x80091CBC: nop

L_80091CC0:
    // 0x80091CC0: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x80091CC4: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80091CC8: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80091CCC: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x80091CD0: addiu       $t7, $v1, 0x17
    ctx->r15 = ADD32(ctx->r3, 0X17);
    // 0x80091CD4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80091CD8: addiu       $a2, $v1, -0x2
    ctx->r6 = ADD32(ctx->r3, -0X2);
    // 0x80091CDC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80091CE0: addiu       $a1, $v0, -0x2
    ctx->r5 = ADD32(ctx->r2, -0X2);
    // 0x80091CE4: jal         0x800C543C
    // 0x80091CE8: addiu       $a3, $v0, 0x32
    ctx->r7 = ADD32(ctx->r2, 0X32);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_38;
    // 0x80091CE8: addiu       $a3, $v0, 0x32
    ctx->r7 = ADD32(ctx->r2, 0X32);
    after_38:
    // 0x80091CEC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091CF0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091CF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80091CF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80091CFC: jal         0x800C60B8
    // 0x80091D00: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_39;
    // 0x80091D00: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_39:
L_80091D04:
    // 0x80091D04: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x80091D08: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80091D0C: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x80091D10: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091D14: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80091D18: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x80091D1C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80091D20: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80091D24: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80091D28: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80091D2C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80091D30: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80091D34: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091D38: addu        $a3, $t0, $t8
    ctx->r7 = ADD32(ctx->r8, ctx->r24);
    // 0x80091D3C: jal         0x80078F08
    // 0x80091D40: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    texrect_draw(rdram, ctx);
        goto after_40;
    // 0x80091D40: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    after_40:
    // 0x80091D44: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80091D48: slt         $at, $s5, $s7
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x80091D4C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80091D50: bne         $at, $zero, L_80091C84
    if (ctx->r1 != 0) {
        // 0x80091D54: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80091C84;
    }
    // 0x80091D54: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80091D58: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091D5C: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x80091D60: nop

L_80091D64:
    // 0x80091D64: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80091D68:
    // 0x80091D68: beq         $at, $zero, L_80091D80
    if (ctx->r1 == 0) {
        // 0x80091D6C: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80091D80;
    }
    // 0x80091D6C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80091D70: lw          $t4, 0x6980($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6980);
    // 0x80091D74: nop

    // 0x80091D78: bne         $t4, $zero, L_80091F24
    if (ctx->r12 != 0) {
        // 0x80091D7C: lw          $s0, 0x80($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X80);
            goto L_80091F24;
    }
    // 0x80091D7C: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
L_80091D80:
    // 0x80091D80: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80091D84: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80091D88: bne         $t5, $zero, L_80091F24
    if (ctx->r13 != 0) {
        // 0x80091D8C: lw          $s0, 0x80($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X80);
            goto L_80091F24;
    }
    // 0x80091D8C: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x80091D90: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091D94: lw          $s7, 0x80($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X80);
    // 0x80091D98: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80091D9C: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80091DA0: addiu       $s7, $s7, 0x8B
    ctx->r23 = ADD32(ctx->r23, 0X8B);
    // 0x80091DA4: mflo        $s3
    ctx->r19 = lo;
    // 0x80091DA8: sra         $t7, $s3, 1
    ctx->r15 = S32(SIGNED(ctx->r19) >> 1);
    // 0x80091DAC: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
    // 0x80091DB0: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
L_80091DB4:
    // 0x80091DB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80091DB8: sllv        $t8, $t0, $s5
    ctx->r24 = S32(ctx->r8 << (ctx->r21 & 31));
    // 0x80091DBC: and         $t1, $t8, $t9
    ctx->r9 = ctx->r24 & ctx->r25;
    // 0x80091DC0: beq         $t1, $zero, L_80091F14
    if (ctx->r9 == 0) {
        // 0x80091DC4: nop
    
            goto L_80091F14;
    }
    // 0x80091DC4: nop

    // 0x80091DC8: blez        $v0, L_80091F10
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80091DCC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80091F10;
    }
    // 0x80091DCC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80091DD0: sll         $t3, $s5, 2
    ctx->r11 = S32(ctx->r21 << 2);
    // 0x80091DD4: subu        $t3, $t3, $s5
    ctx->r11 = SUB32(ctx->r11, ctx->r21);
    // 0x80091DD8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80091DDC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80091DE0: addiu       $t6, $t6, 0xC30
    ctx->r14 = ADD32(ctx->r14, 0XC30);
    // 0x80091DE4: addiu       $t4, $t4, 0xBA4
    ctx->r12 = ADD32(ctx->r12, 0XBA4);
    // 0x80091DE8: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80091DEC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80091DF0: sll         $t5, $s3, 1
    ctx->r13 = S32(ctx->r19 << 1);
    // 0x80091DF4: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x80091DF8: addiu       $s1, $s1, 0x6F80
    ctx->r17 = ADD32(ctx->r17, 0X6F80);
    // 0x80091DFC: addu        $s2, $t2, $t4
    ctx->r18 = ADD32(ctx->r10, ctx->r12);
L_80091E00:
    // 0x80091E00: lb          $t7, 0x0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X0);
    // 0x80091E04: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80091E08: bne         $s5, $t7, L_80091E50
    if (ctx->r21 != ctx->r15) {
        // 0x80091E0C: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_80091E50;
    }
    // 0x80091E0C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80091E10: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x80091E14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091E18: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x80091E1C: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x80091E20: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80091E24: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80091E28: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80091E2C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80091E30: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80091E34: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80091E38: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091E3C: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80091E40: jal         0x80078F08
    // 0x80091E44: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    texrect_draw(rdram, ctx);
        goto after_41;
    // 0x80091E44: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_41:
    // 0x80091E48: b           L_80091EF4
    // 0x80091E4C: nop

        goto L_80091EF4;
    // 0x80091E4C: nop

L_80091E50:
    // 0x80091E50: lw          $t4, -0x5BC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5BC);
    // 0x80091E54: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x80091E58: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80091E5C: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80091E60: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80091E64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091E68: andi        $t0, $t7, 0x2
    ctx->r8 = ctx->r15 & 0X2;
    // 0x80091E6C: beq         $t0, $zero, L_80091EB4
    if (ctx->r8 == 0) {
        // 0x80091E70: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_80091EB4;
    }
    // 0x80091E70: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091E74: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x80091E78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091E7C: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x80091E80: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x80091E84: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80091E88: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80091E8C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80091E90: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80091E94: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80091E98: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80091E9C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091EA0: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80091EA4: jal         0x80078F08
    // 0x80091EA8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    texrect_draw(rdram, ctx);
        goto after_42;
    // 0x80091EA8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_42:
    // 0x80091EAC: b           L_80091EF4
    // 0x80091EB0: nop

        goto L_80091EF4;
    // 0x80091EB0: nop

L_80091EB4:
    // 0x80091EB4: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80091EB8: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x80091EBC: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x80091EC0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80091EC4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80091EC8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80091ECC: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80091ED0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80091ED4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80091ED8: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80091EDC: bgez        $t6, L_80091EEC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80091EE0: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_80091EEC;
    }
    // 0x80091EE0: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80091EE4: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x80091EE8: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80091EEC:
    // 0x80091EEC: jal         0x80078F08
    // 0x80091EF0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    texrect_draw(rdram, ctx);
        goto after_43;
    // 0x80091EF0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_43:
L_80091EF4:
    // 0x80091EF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091EF8: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x80091EFC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80091F00: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80091F04: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80091F08: bne         $at, $zero, L_80091E00
    if (ctx->r1 != 0) {
        // 0x80091F0C: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80091E00;
    }
    // 0x80091F0C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80091F10:
    // 0x80091F10: addiu       $s7, $s7, 0x18
    ctx->r23 = ADD32(ctx->r23, 0X18);
L_80091F14:
    // 0x80091F14: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80091F18: bne         $s5, $s6, L_80091DB4
    if (ctx->r21 != ctx->r22) {
        // 0x80091F1C: lw          $t9, 0x7C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X7C);
            goto L_80091DB4;
    }
    // 0x80091F1C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80091F20: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
L_80091F24:
    // 0x80091F24: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80091F28: lb          $v1, 0x6F80($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6F80);
    // 0x80091F2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091F30: addiu       $s0, $s0, 0x8B
    ctx->r16 = ADD32(ctx->r16, 0X8B);
    // 0x80091F34: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80091F38: bne         $v1, $at, L_80091F44
    if (ctx->r3 != ctx->r1) {
        // 0x80091F3C: or          $s7, $s0, $zero
        ctx->r23 = ctx->r16 | 0;
            goto L_80091F44;
    }
    // 0x80091F3C: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
    // 0x80091F40: addiu       $s7, $s0, 0x2
    ctx->r23 = ADD32(ctx->r16, 0X2);
L_80091F44:
    // 0x80091F44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80091F48: bne         $v0, $at, L_80092020
    if (ctx->r2 != ctx->r1) {
        // 0x80091F4C: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80092020;
    }
    // 0x80091F4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80091F50: lw          $t0, 0x6980($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6980);
    // 0x80091F54: nop

    // 0x80091F58: bne         $t0, $zero, L_80091FC0
    if (ctx->r8 != 0) {
        // 0x80091F5C: nop
    
            goto L_80091FC0;
    }
    // 0x80091F5C: nop

    // 0x80091F60: multu       $v1, $s6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091F64: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80091F68: addiu       $s1, $s1, 0xBA4
    ctx->r17 = ADD32(ctx->r17, 0XBA4);
    // 0x80091F6C: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x80091F70: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091F74: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80091F78: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80091F7C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80091F80: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091F84: addiu       $a2, $zero, 0x95
    ctx->r6 = ADD32(0, 0X95);
    // 0x80091F88: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80091F8C: mflo        $t8
    ctx->r24 = lo;
    // 0x80091F90: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80091F94: addu        $t1, $s1, $t9
    ctx->r9 = ADD32(ctx->r17, ctx->r25);
    // 0x80091F98: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80091F9C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80091FA0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80091FA4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80091FA8: jal         0x80078F08
    // 0x80091FAC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    texrect_draw(rdram, ctx);
        goto after_44;
    // 0x80091FAC: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_44:
    // 0x80091FB0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091FB4: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x80091FB8: b           L_80092020
    // 0x80091FBC: nop

        goto L_80092020;
    // 0x80091FBC: nop

L_80091FC0:
    // 0x80091FC0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80091FC4: lw          $t6, 0x994($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X994);
    // 0x80091FC8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80091FCC: multu       $t6, $s6
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091FD0: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x80091FD4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091FD8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80091FDC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80091FE0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80091FE4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80091FE8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80091FEC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80091FF0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80091FF4: addiu       $a2, $zero, 0x95
    ctx->r6 = ADD32(0, 0X95);
    // 0x80091FF8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80091FFC: mflo        $t7
    ctx->r15 = lo;
    // 0x80092000: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80092004: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80092008: lw          $a1, 0xBC8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XBC8);
    // 0x8009200C: jal         0x80078F08
    // 0x80092010: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    texrect_draw(rdram, ctx);
        goto after_45;
    // 0x80092010: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_45:
    // 0x80092014: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80092018: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8009201C: nop

L_80092020:
    // 0x80092020: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80092024: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092028: bne         $v0, $at, L_800920F0
    if (ctx->r2 != ctx->r1) {
        // 0x8009202C: addiu       $s1, $s1, 0xBA4
        ctx->r17 = ADD32(ctx->r17, 0XBA4);
            goto L_800920F0;
    }
    // 0x8009202C: addiu       $s1, $s1, 0xBA4
    ctx->r17 = ADD32(ctx->r17, 0XBA4);
    // 0x80092030: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80092034: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80092038: bne         $t4, $zero, L_800920F0
    if (ctx->r12 != 0) {
        // 0x8009203C: nop
    
            goto L_800920F0;
    }
    // 0x8009203C: nop

    // 0x80092040: lb          $t2, 0x6F80($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X6F80);
    // 0x80092044: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x80092048: multu       $t2, $s6
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009204C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092050: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80092054: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80092058: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009205C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80092060: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
    // 0x80092064: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80092068: addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    // 0x8009206C: mflo        $t5
    ctx->r13 = lo;
    // 0x80092070: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80092074: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80092078: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x8009207C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80092080: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80092084: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80092088: jal         0x80078F08
    // 0x8009208C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    texrect_draw(rdram, ctx);
        goto after_46;
    // 0x8009208C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_46:
    // 0x80092090: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80092094: lb          $v0, 0x6F81($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6F81);
    // 0x80092098: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009209C: bne         $v0, $at, L_800920A8
    if (ctx->r2 != ctx->r1) {
        // 0x800920A0: nop
    
            goto L_800920A8;
    }
    // 0x800920A0: nop

    // 0x800920A4: addiu       $s7, $s0, 0x2
    ctx->r23 = ADD32(ctx->r16, 0X2);
L_800920A8:
    // 0x800920A8: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800920AC: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x800920B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800920B4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800920B8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800920BC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800920C0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800920C4: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x800920C8: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800920CC: mflo        $t3
    ctx->r11 = lo;
    // 0x800920D0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800920D4: addu        $t2, $s1, $t4
    ctx->r10 = ADD32(ctx->r17, ctx->r12);
    // 0x800920D8: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x800920DC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800920E0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800920E4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800920E8: jal         0x80078F08
    // 0x800920EC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    texrect_draw(rdram, ctx);
        goto after_47;
    // 0x800920EC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_47:
L_800920F0:
    // 0x800920F0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800920F4: jal         0x8007B820
    // 0x800920F8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    rendermode_reset(rdram, ctx);
        goto after_48;
    // 0x800920F8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_48:
    // 0x800920FC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80092100: lw          $t8, -0x5C4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5C4);
    // 0x80092104: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80092108: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8009210C: beq         $at, $zero, L_80092198
    if (ctx->r1 == 0) {
        // 0x80092110: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_80092198;
    }
    // 0x80092110: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80092114: bne         $t9, $zero, L_80092194
    if (ctx->r25 != 0) {
        // 0x80092118: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80092194;
    }
    // 0x80092118: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009211C: addiu       $v0, $v0, -0x324
    ctx->r2 = ADD32(ctx->r2, -0X324);
    // 0x80092120: lui         $at, 0xC250
    ctx->r1 = S32(0XC250 << 16);
    // 0x80092124: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80092128: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8009212C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80092130: swc1        $f8, 0xF0($t1)
    MEM_W(0XF0, ctx->r9) = ctx->f8.u32l;
    // 0x80092134: lw          $t3, -0x5C4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5C4);
    // 0x80092138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009213C: bne         $t3, $at, L_80092164
    if (ctx->r11 != ctx->r1) {
        // 0x80092140: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80092164;
    }
    // 0x80092140: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80092144: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x80092148: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009214C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80092150: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80092154: jal         0x8009CFA4
    // 0x80092158: swc1        $f10, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_49;
    // 0x80092158: swc1        $f10, 0xEC($t4)
    MEM_W(0XEC, ctx->r12) = ctx->f10.u32l;
    after_49:
    // 0x8009215C: b           L_80092198
    // 0x80092160: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_80092198;
    // 0x80092160: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80092164:
    // 0x80092164: lui         $at, 0xC240
    ctx->r1 = S32(0XC240 << 16);
    // 0x80092168: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009216C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80092170: jal         0x8009CFA4
    // 0x80092174: swc1        $f16, 0xEC($t2)
    MEM_W(0XEC, ctx->r10) = ctx->f16.u32l;
    menu_element_render(rdram, ctx);
        goto after_50;
    // 0x80092174: swc1        $f16, 0xEC($t2)
    MEM_W(0XEC, ctx->r10) = ctx->f16.u32l;
    after_50:
    // 0x80092178: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8009217C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80092180: lw          $t5, -0x324($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X324);
    // 0x80092184: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80092188: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009218C: jal         0x8009CFA4
    // 0x80092190: swc1        $f18, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_51;
    // 0x80092190: swc1        $f18, 0xEC($t5)
    MEM_W(0XEC, ctx->r13) = ctx->f18.u32l;
    after_51:
L_80092194:
    // 0x80092194: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80092198:
    // 0x80092198: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009219C: beq         $t6, $zero, L_80092400
    if (ctx->r14 == 0) {
        // 0x800921A0: nop
    
            goto L_80092400;
    }
    // 0x800921A0: nop

    // 0x800921A4: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x800921A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800921AC: lw          $a0, 0x220($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X220);
    // 0x800921B0: jal         0x800C5300
    // 0x800921B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_text_width(rdram, ctx);
        goto after_52;
    // 0x800921B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_52:
    // 0x800921B8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800921BC: addiu       $s2, $s2, 0xC64
    ctx->r18 = ADD32(ctx->r18, 0XC64);
    // 0x800921C0: lh          $v1, 0x4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X4);
    // 0x800921C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800921C8: addiu       $t0, $v1, -0xC
    ctx->r8 = ADD32(ctx->r3, -0XC);
    // 0x800921CC: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800921D0: beq         $at, $zero, L_800921E0
    if (ctx->r1 == 0) {
        // 0x800921D4: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_800921E0;
    }
    // 0x800921D4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800921D8: b           L_800921E4
    // 0x800921DC: addiu       $s4, $v0, 0xC
    ctx->r20 = ADD32(ctx->r2, 0XC);
        goto L_800921E4;
    // 0x800921DC: addiu       $s4, $v0, 0xC
    ctx->r20 = ADD32(ctx->r2, 0XC);
L_800921E0:
    // 0x800921E0: or          $s4, $v1, $zero
    ctx->r20 = ctx->r3 | 0;
L_800921E4:
    // 0x800921E4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800921E8: lw          $t5, 0x6BFC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6BFC);
    // 0x800921EC: lh          $t8, 0x2($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X2);
    // 0x800921F0: lh          $t1, 0x6($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X6);
    // 0x800921F4: lh          $t3, 0x8($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X8);
    // 0x800921F8: lh          $t4, 0xA($s2)
    ctx->r12 = MEM_H(ctx->r18, 0XA);
    // 0x800921FC: lui         $t2, 0xB0E0
    ctx->r10 = S32(0XB0E0 << 16);
    // 0x80092200: ori         $t2, $t2, 0xC0FF
    ctx->r10 = ctx->r10 | 0XC0FF;
    // 0x80092204: sra         $a1, $s4, 1
    ctx->r5 = S32(SIGNED(ctx->r20) >> 1);
    // 0x80092208: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x8009220C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x80092210: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80092214: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80092218: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8009221C: subu        $a2, $t9, $t8
    ctx->r6 = SUB32(ctx->r25, ctx->r24);
    // 0x80092220: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80092224: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80092228: jal         0x800809D0
    // 0x8009222C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    func_80080580(rdram, ctx);
        goto after_53;
    // 0x8009222C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_53:
    // 0x80092230: jal         0x800812BC
    // 0x80092234: nop

    menu_geometry_end(rdram, ctx);
        goto after_54;
    // 0x80092234: nop

    after_54:
    // 0x80092238: jal         0x800C484C
    // 0x8009223C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_55;
    // 0x8009223C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_55:
    // 0x80092240: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80092244: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80092248: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009224C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80092250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80092254: jal         0x800C48E4
    // 0x80092258: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_56;
    // 0x80092258: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_56:
    // 0x8009225C: lh          $t9, 0xE($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XE);
    // 0x80092260: lh          $t8, 0x2($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X2);
    // 0x80092264: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80092268: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009226C: lh          $t7, 0xC($s2)
    ctx->r15 = MEM_H(ctx->r18, 0XC);
    // 0x80092270: lh          $t0, 0x0($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X0);
    // 0x80092274: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x80092278: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x8009227C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092280: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80092284: lw          $a3, 0x220($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X220);
    // 0x80092288: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    // 0x8009228C: addu        $a2, $t1, $t3
    ctx->r6 = ADD32(ctx->r9, ctx->r11);
    // 0x80092290: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80092294: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80092298: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009229C: jal         0x800C49A0
    // 0x800922A0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    draw_text(rdram, ctx);
        goto after_57;
    // 0x800922A0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_57:
    // 0x800922A4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800922A8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800922AC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800922B0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800922B4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800922B8: jal         0x800C48E4
    // 0x800922BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_58;
    // 0x800922BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_58:
    // 0x800922C0: lh          $t0, 0xE($s2)
    ctx->r8 = MEM_H(ctx->r18, 0XE);
    // 0x800922C4: lh          $t9, 0x2($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X2);
    // 0x800922C8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800922CC: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x800922D0: lh          $t6, 0xC($s2)
    ctx->r14 = MEM_H(ctx->r18, 0XC);
    // 0x800922D4: lh          $t7, 0x0($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X0);
    // 0x800922D8: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x800922DC: addu        $t8, $t0, $t9
    ctx->r24 = ADD32(ctx->r8, ctx->r25);
    // 0x800922E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800922E4: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x800922E8: lw          $a3, 0x220($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X220);
    // 0x800922EC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800922F0: addu        $a2, $t8, $t1
    ctx->r6 = ADD32(ctx->r24, ctx->r9);
    // 0x800922F4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800922F8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800922FC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80092300: jal         0x800C49A0
    // 0x80092304: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    draw_text(rdram, ctx);
        goto after_59;
    // 0x80092304: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_59:
    // 0x80092308: jal         0x80068748
    // 0x8009230C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_60;
    // 0x8009230C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_60:
    // 0x80092310: jal         0x8007C36C
    // 0x80092314: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_61;
    // 0x80092314: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_61:
    // 0x80092318: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8009231C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80092320: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80092324: addiu       $s0, $s0, -0x5D8
    ctx->r16 = ADD32(ctx->r16, -0X5D8);
    // 0x80092328: addiu       $s1, $s1, -0x5D4
    ctx->r17 = ADD32(ctx->r17, -0X5D4);
    // 0x8009232C: addiu       $s5, $s5, 0x990
    ctx->r21 = ADD32(ctx->r21, 0X990);
    // 0x80092330: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80092334: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
L_80092338:
    // 0x80092338: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x8009233C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80092340: bne         $s4, $t2, L_80092378
    if (ctx->r20 != ctx->r10) {
        // 0x80092344: sll         $v0, $s4, 1
        ctx->r2 = S32(ctx->r20 << 1);
            goto L_80092378;
    }
    // 0x80092344: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x80092348: lw          $t5, 0x6980($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6980);
    // 0x8009234C: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x80092350: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80092354: beq         $at, $zero, L_8009236C
    if (ctx->r1 == 0) {
        // 0x80092358: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_8009236C;
    }
    // 0x80092358: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009235C: subu        $v0, $t7, $t6
    ctx->r2 = SUB32(ctx->r15, ctx->r14);
    // 0x80092360: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x80092364: b           L_80092374
    // 0x80092368: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
        goto L_80092374;
    // 0x80092368: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
L_8009236C:
    // 0x8009236C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80092370: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_80092374:
    // 0x80092374: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
L_80092378:
    // 0x80092378: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    // 0x8009237C: addu        $v1, $s2, $t0
    ctx->r3 = ADD32(ctx->r18, ctx->r8);
    // 0x80092380: lh          $t9, 0x10($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X10);
    // 0x80092384: lh          $t8, 0x0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X0);
    // 0x80092388: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009238C: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x80092390: addiu       $t3, $t1, -0xA0
    ctx->r11 = ADD32(ctx->r9, -0XA0);
    // 0x80092394: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80092398: addiu       $a1, $a1, -0x324
    ctx->r5 = ADD32(ctx->r5, -0X324);
    // 0x8009239C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800923A0: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800923A4: addiu       $t8, $v0, 0x2
    ctx->r24 = ADD32(ctx->r2, 0X2);
    // 0x800923A8: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
    // 0x800923AC: lh          $t2, 0x12($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X12);
    // 0x800923B0: lh          $t7, 0x2($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X2);
    // 0x800923B4: negu        $t5, $t2
    ctx->r13 = SUB32(0, ctx->r10);
    // 0x800923B8: subu        $t6, $t5, $t7
    ctx->r14 = SUB32(ctx->r13, ctx->r15);
    // 0x800923BC: addiu       $t0, $t6, 0x78
    ctx->r8 = ADD32(ctx->r14, 0X78);
    // 0x800923C0: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800923C4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800923C8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800923CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800923D0: swc1        $f10, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f10.u32l;
    // 0x800923D4: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800923D8: jal         0x8009CFA4
    // 0x800923DC: sh          $t8, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r24;
    menu_element_render(rdram, ctx);
        goto after_62;
    // 0x800923DC: sh          $t8, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r24;
    after_62:
    // 0x800923E0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800923E4: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x800923E8: bne         $s4, $s6, L_80092338
    if (ctx->r20 != ctx->r22) {
        // 0x800923EC: sb          $s3, 0x0($s1)
        MEM_B(0X0, ctx->r17) = ctx->r19;
            goto L_80092338;
    }
    // 0x800923EC: sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
    // 0x800923F0: jal         0x8007C36C
    // 0x800923F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_63;
    // 0x800923F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_63:
    // 0x800923F8: jal         0x80068748
    // 0x800923FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_64;
    // 0x800923FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_64:
L_80092400:
    // 0x80092400: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80092404: lw          $t3, 0x6F88($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6F88);
    // 0x80092408: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x8009240C: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80092410: beq         $at, $zero, L_8009252C
    if (ctx->r1 == 0) {
        // 0x80092414: nop
    
            goto L_8009252C;
    }
    // 0x80092414: nop

    // 0x80092418: jal         0x8007C36C
    // 0x8009241C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_65;
    // 0x8009241C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_65:
    // 0x80092420: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80092424: addiu       $s1, $s1, -0x5EC
    ctx->r17 = ADD32(ctx->r17, -0X5EC);
    // 0x80092428: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009242C: addiu       $s5, $zero, 0xB
    ctx->r21 = ADD32(0, 0XB);
    // 0x80092430: beq         $t4, $zero, L_8009243C
    if (ctx->r12 == 0) {
        // 0x80092434: lui         $at, 0x4228
        ctx->r1 = S32(0X4228 << 16);
            goto L_8009243C;
    }
    // 0x80092434: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x80092438: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
L_8009243C:
    // 0x8009243C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80092440: lw          $t2, -0x324($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X324);
    // 0x80092444: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80092448: sll         $s0, $s5, 5
    ctx->r16 = S32(ctx->r21 << 5);
    // 0x8009244C: addu        $t5, $t2, $s0
    ctx->r13 = ADD32(ctx->r10, ctx->r16);
    // 0x80092450: swc1        $f16, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f16.u32l;
    // 0x80092454: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80092458: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009245C: lw          $t0, -0x5BC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5BC);
    // 0x80092460: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80092464: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80092468: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8009246C: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x80092470: nop

    // 0x80092474: andi        $t3, $t1, 0x2
    ctx->r11 = ctx->r9 & 0X2;
    // 0x80092478: bne         $t3, $zero, L_80092490
    if (ctx->r11 != 0) {
        // 0x8009247C: nop
    
            goto L_80092490;
    }
    // 0x8009247C: nop

    // 0x80092480: jal         0x8009F1A4
    // 0x80092484: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_66;
    // 0x80092484: nop

    after_66:
    // 0x80092488: beq         $v0, $zero, L_800924C0
    if (ctx->r2 == 0) {
        // 0x8009248C: lw          $t6, 0x70($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X70);
            goto L_800924C0;
    }
    // 0x8009248C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
L_80092490:
    // 0x80092490: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80092494: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80092498: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x8009249C: addiu       $t5, $t2, -0x80
    ctx->r13 = ADD32(ctx->r10, -0X80);
    // 0x800924A0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800924A4: lw          $t7, -0x324($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X324);
    // 0x800924A8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800924AC: addu        $t0, $t7, $s0
    ctx->r8 = ADD32(ctx->r15, ctx->r16);
    // 0x800924B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800924B4: jal         0x8009CFA4
    // 0x800924B8: swc1        $f4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f4.u32l;
    menu_element_render(rdram, ctx);
        goto after_67;
    // 0x800924B8: swc1        $f4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f4.u32l;
    after_67:
    // 0x800924BC: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
L_800924C0:
    // 0x800924C0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800924C4: lw          $t8, -0x5BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5BC);
    // 0x800924C8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800924CC: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x800924D0: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x800924D4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800924D8: nop

    // 0x800924DC: andi        $t2, $t4, 0x4
    ctx->r10 = ctx->r12 & 0X4;
    // 0x800924E0: bne         $t2, $zero, L_800924F8
    if (ctx->r10 != 0) {
        // 0x800924E4: nop
    
            goto L_800924F8;
    }
    // 0x800924E4: nop

    // 0x800924E8: jal         0x8009F1A4
    // 0x800924EC: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_68;
    // 0x800924EC: nop

    after_68:
    // 0x800924F0: beq         $v0, $zero, L_80092524
    if (ctx->r2 == 0) {
        // 0x800924F4: nop
    
            goto L_80092524;
    }
    // 0x800924F4: nop

L_800924F8:
    // 0x800924F8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800924FC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80092500: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x80092504: addiu       $t0, $t7, 0x78
    ctx->r8 = ADD32(ctx->r15, 0X78);
    // 0x80092508: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8009250C: lw          $t6, -0x324($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X324);
    // 0x80092510: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80092514: addu        $t8, $t6, $s0
    ctx->r24 = ADD32(ctx->r14, ctx->r16);
    // 0x80092518: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8009251C: jal         0x8009CFA4
    // 0x80092520: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    menu_element_render(rdram, ctx);
        goto after_69;
    // 0x80092520: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    after_69:
L_80092524:
    // 0x80092524: jal         0x8007C36C
    // 0x80092528: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_70;
    // 0x80092528: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_70:
L_8009252C:
    // 0x8009252C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80092530: lw          $t9, -0x5C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5C4);
    // 0x80092534: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80092538: bne         $t9, $at, L_800925AC
    if (ctx->r25 != ctx->r1) {
        // 0x8009253C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800925AC;
    }
    // 0x8009253C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80092540: lw          $t1, 0x6980($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6980);
    // 0x80092544: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092548: bltz        $t1, L_800925AC
    if (SIGNED(ctx->r9) < 0) {
        // 0x8009254C: nop
    
            goto L_800925AC;
    }
    // 0x8009254C: nop

    // 0x80092550: lw          $a0, -0x5BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5BC);
    // 0x80092554: jal         0x80093128
    // 0x80092558: nop

    trackmenu_staff_beaten(rdram, ctx);
        goto after_71;
    // 0x80092558: nop

    after_71:
    // 0x8009255C: bltz        $v0, L_800925AC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80092560: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800925AC;
    }
    // 0x80092560: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092564: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    // 0x80092568: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x8009256C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80092570: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80092574: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80092578: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009257C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80092580: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80092584: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80092588: addiu       $a1, $a1, 0xB94
    ctx->r5 = ADD32(ctx->r5, 0XB94);
    // 0x8009258C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80092590: addiu       $a2, $zero, 0xCC
    ctx->r6 = ADD32(0, 0XCC);
    // 0x80092594: addiu       $a3, $a3, 0x7A
    ctx->r7 = ADD32(ctx->r7, 0X7A);
    // 0x80092598: jal         0x80078F08
    // 0x8009259C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    texrect_draw(rdram, ctx);
        goto after_72;
    // 0x8009259C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_72:
    // 0x800925A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800925A4: jal         0x8007B820
    // 0x800925A8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    rendermode_reset(rdram, ctx);
        goto after_73;
    // 0x800925A8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_73:
L_800925AC:
    // 0x800925AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800925B0: lw          $t7, 0x6F88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6F88);
    // 0x800925B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800925B8: beq         $t7, $at, L_8009266C
    if (ctx->r15 == ctx->r1) {
        // 0x800925BC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8009266C;
    }
    // 0x800925BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800925C0: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x800925C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800925C8: bne         $v0, $at, L_800925E0
    if (ctx->r2 != ctx->r1) {
        // 0x800925CC: nop
    
            goto L_800925E0;
    }
    // 0x800925CC: nop

    // 0x800925D0: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800925D4: nop

    // 0x800925D8: beq         $t0, $zero, L_80092600
    if (ctx->r8 == 0) {
        // 0x800925DC: nop
    
            goto L_80092600;
    }
    // 0x800925DC: nop

L_800925E0:
    // 0x800925E0: bne         $s6, $v0, L_800925F8
    if (ctx->r22 != ctx->r2) {
        // 0x800925E4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800925F8;
    }
    // 0x800925E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800925E8: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800925EC: nop

    // 0x800925F0: bne         $t6, $zero, L_80092600
    if (ctx->r14 != 0) {
        // 0x800925F4: nop
    
            goto L_80092600;
    }
    // 0x800925F4: nop

L_800925F8:
    // 0x800925F8: bne         $v0, $at, L_80092670
    if (ctx->r2 != ctx->r1) {
        // 0x800925FC: addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
            goto L_80092670;
    }
    // 0x800925FC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_80092600:
    // 0x80092600: jal         0x800C484C
    // 0x80092604: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_74;
    // 0x80092604: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_74:
    // 0x80092608: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8009260C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80092610: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80092614: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80092618: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009261C: jal         0x800C48E4
    // 0x80092620: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    set_text_colour(rdram, ctx);
        goto after_75;
    // 0x80092620: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_75:
    // 0x80092624: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80092628: lw          $t9, 0x6F88($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6F88);
    // 0x8009262C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80092630: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80092634: bne         $at, $zero, L_8009264C
    if (ctx->r1 != 0) {
        // 0x80092638: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_8009264C;
    }
    // 0x80092638: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8009263C: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x80092640: nop

    // 0x80092644: addiu       $t3, $t1, 0x18
    ctx->r11 = ADD32(ctx->r9, 0X18);
    // 0x80092648: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
L_8009264C:
    // 0x8009264C: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80092650: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80092654: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80092658: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8009265C: addiu       $a3, $a3, -0x7834
    ctx->r7 = ADD32(ctx->r7, -0X7834);
    // 0x80092660: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80092664: jal         0x800C49A0
    // 0x80092668: addiu       $a2, $a2, 0xAC
    ctx->r6 = ADD32(ctx->r6, 0XAC);
    draw_text(rdram, ctx);
        goto after_76;
    // 0x80092668: addiu       $a2, $a2, 0xAC
    ctx->r6 = ADD32(ctx->r6, 0XAC);
    after_76:
L_8009266C:
    // 0x8009266C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_80092670:
    // 0x80092670: sw          $t2, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r10;
L_80092674:
    // 0x80092674: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80092678: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8009267C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80092680: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80092684: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80092688: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8009268C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80092690: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80092694: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80092698: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8009269C: jr          $ra
    // 0x800926A0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800926A0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void render_ortho_triangle_image(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E34: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80068E38: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x80068E3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80068E40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068E44: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80068E48: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80068E4C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80068E50: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80068E54: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80068E58: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80068E5C: beq         $t6, $zero, L_800691C8
    if (ctx->r14 == 0) {
        // 0x80068E60: sw          $a1, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->r5;
            goto L_800691C8;
    }
    // 0x80068E60: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x80068E64: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80068E68: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80068E6C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80068E70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068E74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068E78: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80068E7C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80068E80: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80068E84: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80068E88: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80068E8C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80068E90: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80068E94: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80068E98: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80068E9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068EA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068EA4: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80068EA8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80068EAC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80068EB0: addiu       $s4, $s4, 0x129C
    ctx->r20 = ADD32(ctx->r20, 0X129C);
    // 0x80068EB4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80068EB8: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80068EBC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80068EC0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80068EC4: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x80068EC8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80068ECC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068ED0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068ED4: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80068ED8: sb          $a1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r5;
    // 0x80068EDC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80068EE0: sb          $a1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r5;
    // 0x80068EE4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80068EE8: sb          $a1, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r5;
    // 0x80068EEC: sb          $a1, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r5;
    // 0x80068EF0: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x80068EF4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80068EF8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80068EFC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80068F00: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068F04: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80068F08: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80068F0C: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x80068F10: andi        $t8, $t7, 0x6
    ctx->r24 = ctx->r15 & 0X6;
    // 0x80068F14: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80068F18: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x80068F1C: ori         $t2, $t1, 0x1A
    ctx->r10 = ctx->r9 | 0X1A;
    // 0x80068F20: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80068F24: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80068F28: addiu       $s2, $s2, 0x1270
    ctx->r18 = ADD32(ctx->r18, 0X1270);
    // 0x80068F2C: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80068F30: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80068F34: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80068F38: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80068F3C: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x80068F40: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80068F44: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80068F48: lh          $s3, 0x18($a3)
    ctx->r19 = MEM_H(ctx->r7, 0X18);
    // 0x80068F4C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80068F50: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x80068F54: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80068F58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80068F5C: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x80068F60: sh          $t1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r9;
    // 0x80068F64: lh          $t2, 0x2($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X2);
    // 0x80068F68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80068F6C: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80068F70: sh          $t3, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r11;
    // 0x80068F74: lw          $t4, 0x1264($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1264);
    // 0x80068F78: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x80068F7C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80068F80: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80068F84: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80068F88: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80068F8C: lh          $t6, 0x1044($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1044);
    // 0x80068F90: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80068F94: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80068F98: sh          $t8, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r24;
    // 0x80068F9C: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
    // 0x80068FA0: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x80068FA4: swc1        $f0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
    // 0x80068FA8: lb          $t9, 0x1295($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X1295);
    // 0x80068FAC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068FB0: beq         $t9, $zero, L_80069008
    if (ctx->r25 == 0) {
        // 0x80068FB4: nop
    
            goto L_80069008;
    }
    // 0x80068FB4: nop

    // 0x80068FB8: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80068FBC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80068FC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80068FC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80068FC8: jal         0x80070878
    // 0x80068FCC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    mtxf_from_scale(rdram, ctx);
        goto after_0;
    // 0x80068FCC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x80068FD0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80068FD4: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x80068FD8: lw          $a3, 0x6714($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6714);
    // 0x80068FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068FE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068FE4: jal         0x80070370
    // 0x80068FE8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    mtxf_billboard(rdram, ctx);
        goto after_1;
    // 0x80068FE8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80068FEC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80068FF0: addiu       $a2, $a2, 0x15E0
    ctx->r6 = ADD32(ctx->r6, 0X15E0);
    // 0x80068FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068FF8: jal         0x8006F9A8
    // 0x80068FFC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    mtxf_mul(rdram, ctx);
        goto after_2;
    // 0x80068FFC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_2:
    // 0x80069000: b           L_80069028
    // 0x80069004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80069028;
    // 0x80069004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80069008:
    // 0x80069008: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006900C: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x80069010: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80069014: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80069018: jal         0x80070878
    // 0x8006901C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    mtxf_from_scale(rdram, ctx);
        goto after_3;
    // 0x8006901C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80069020: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x80069024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80069028:
    // 0x80069028: jal         0x800700B4
    // 0x8006902C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_4;
    // 0x8006902C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80069030: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80069034: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80069038: addiu       $s2, $s2, 0x12F0
    ctx->r18 = ADD32(ctx->r18, 0X12F0);
    // 0x8006903C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80069040: addu        $t3, $s2, $t2
    ctx->r11 = ADD32(ctx->r18, ctx->r10);
    // 0x80069044: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x80069048: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006904C: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x80069050: jal         0x8006F9A8
    // 0x80069054: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mtxf_mul(rdram, ctx);
        goto after_5;
    // 0x80069054: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80069058: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8006905C: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80069060: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80069064: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x80069068: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8006906C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80069070: jal         0x8006FAB0
    // 0x80069074: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_6;
    // 0x80069074: nop

    after_6:
    // 0x80069078: lw          $a1, 0xE4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE4);
    // 0x8006907C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80069080: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80069084: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069088: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8006908C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80069090: sw          $t8, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r24;
    // 0x80069094: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80069098: lui         $t3, 0x180
    ctx->r11 = S32(0X180 << 16);
    // 0x8006909C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800690A0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800690A4: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x800690A8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800690AC: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800690B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800690B4: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800690B8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800690BC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800690C0: lui         $s0, 0xBC00
    ctx->r16 = S32(0XBC00 << 16);
    // 0x800690C4: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x800690C8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800690CC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800690D0: ori         $s0, $s0, 0x2
    ctx->r16 = ctx->r16 | 0X2;
    // 0x800690D4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800690D8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800690DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800690E0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800690E4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800690E8: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x800690EC: lw          $t1, 0x128C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X128C);
    // 0x800690F0: lw          $t6, 0xF0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF0);
    // 0x800690F4: bne         $t1, $zero, L_8006911C
    if (ctx->r9 != 0) {
        // 0x800690F8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8006911C;
    }
    // 0x800690F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800690FC: lw          $t3, 0xF0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF0);
    // 0x80069100: andi        $t2, $s3, 0xFF
    ctx->r10 = ctx->r19 & 0XFF;
    // 0x80069104: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80069108: nop

    // 0x8006910C: multu       $t2, $t4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069110: mflo        $s3
    ctx->r19 = lo;
    // 0x80069114: sra         $t5, $s3, 8
    ctx->r13 = S32(SIGNED(ctx->r19) >> 8);
    // 0x80069118: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
L_8006911C:
    // 0x8006911C: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x80069120: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x80069124: jal         0x8007C384
    // 0x80069128: or          $a1, $t7, $t9
    ctx->r5 = ctx->r15 | ctx->r25;
    material_load_simple(rdram, ctx);
        goto after_7;
    // 0x80069128: or          $a1, $t7, $t9
    ctx->r5 = ctx->r15 | ctx->r25;
    after_7:
    // 0x8006912C: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x80069130: nop

    // 0x80069134: lh          $v0, 0x0($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X0);
    // 0x80069138: nop

    // 0x8006913C: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80069140: bne         $at, $zero, L_8006914C
    if (ctx->r1 != 0) {
        // 0x80069144: nop
    
            goto L_8006914C;
    }
    // 0x80069144: nop

    // 0x80069148: addiu       $s3, $v0, -0x1
    ctx->r19 = ADD32(ctx->r2, -0X1);
L_8006914C:
    // 0x8006914C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80069150: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80069154: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80069158: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8006915C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80069160: lw          $t2, 0xF0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF0);
    // 0x80069164: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x80069168: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8006916C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80069170: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x80069174: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80069178: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8006917C: ori         $t3, $t3, 0xA
    ctx->r11 = ctx->r11 | 0XA;
    // 0x80069180: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80069184: bne         $t9, $zero, L_80069194
    if (ctx->r25 != 0) {
        // 0x80069188: sw          $t9, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r25;
            goto L_80069194;
    }
    // 0x80069188: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8006918C: b           L_80069198
    // 0x80069190: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80069198;
    // 0x80069190: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80069194:
    // 0x80069194: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80069198:
    // 0x80069198: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8006919C: sll         $t2, $s3, 6
    ctx->r10 = S32(ctx->r19 << 6);
    // 0x800691A0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800691A4: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x800691A8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800691AC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800691B0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800691B4: nop

    // 0x800691B8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800691BC: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x800691C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800691C4: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_800691C8:
    // 0x800691C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800691CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800691D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800691D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800691D8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800691DC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800691E0: jr          $ra
    // 0x800691E4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x800691E4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void alSaveNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006532C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80065330: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80065334: addiu       $a2, $a2, -0x35C0
    ctx->r6 = ADD32(ctx->r6, -0X35C0);
    // 0x80065338: addiu       $a1, $a1, -0x358C
    ctx->r5 = ADD32(ctx->r5, -0X358C);
    // 0x8006533C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065340: jal         0x800CA610
    // 0x80065344: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80065344: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80065348: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006534C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80065350: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80065354: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80065358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006535C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065360: jr          $ra
    // 0x80065364: nop

    return;
    // 0x80065364: nop

;}
RECOMP_FUNC void set_level_default_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DD58: jr          $ra
    // 0x8006DD5C: sw          $a0, 0x3A98($at)
    MEM_W(0X3A98, ctx->r1) = ctx->r4;
    return;
    // 0x8006DD5C: sw          $a0, 0x3A98($at)
    MEM_W(0X3A98, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void render_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3CA0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B3CA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B3CA8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B3CAC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B3CB0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B3CB4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B3CB8: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800B3CBC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800B3CC0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B3CC4: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x800B3CC8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800B3CCC: beq         $t8, $zero, L_800B3CEC
    if (ctx->r24 == 0) {
        // 0x800B3CD0: addiu       $t3, $zero, 0xA
        ctx->r11 = ADD32(0, 0XA);
            goto L_800B3CEC;
    }
    // 0x800B3CD0: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x800B3CD4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B3CD8: lw          $t9, 0x326C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X326C);
    // 0x800B3CDC: nop

    // 0x800B3CE0: slti        $at, $t9, 0x200
    ctx->r1 = SIGNED(ctx->r25) < 0X200 ? 1 : 0;
    // 0x800B3CE4: bne         $at, $zero, L_800B43B0
    if (ctx->r1 != 0) {
        // 0x800B3CE8: nop
    
            goto L_800B43B0;
    }
    // 0x800B3CE8: nop

L_800B3CEC:
    // 0x800B3CEC: lh          $t2, 0x5C($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X5C);
    // 0x800B3CF0: nop

    // 0x800B3CF4: sra         $t4, $t2, 8
    ctx->r12 = S32(SIGNED(ctx->r10) >> 8);
    // 0x800B3CF8: andi        $t2, $t4, 0xFF
    ctx->r10 = ctx->r12 & 0XFF;
    // 0x800B3CFC: blez        $t2, L_800B43B0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B3D00: nop
    
            goto L_800B43B0;
    }
    // 0x800B3D00: nop

    // 0x800B3D04: lh          $v1, 0x2C($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2C);
    // 0x800B3D08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800B3D0C: beq         $a1, $v1, L_800B3FDC
    if (ctx->r5 == ctx->r3) {
        // 0x800B3D10: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B3FDC;
    }
    // 0x800B3D10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B3D14: beq         $v1, $at, L_800B3FDC
    if (ctx->r3 == ctx->r1) {
        // 0x800B3D18: addiu       $t1, $zero, 0xFF
        ctx->r9 = ADD32(0, 0XFF);
            goto L_800B3FDC;
    }
    // 0x800B3D18: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800B3D1C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3D20: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800B3D24: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B3D28: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B3D2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B3D30: lbu         $t6, 0x6D($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X6D);
    // 0x800B3D34: lbu         $t9, 0x6C($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6C);
    // 0x800B3D38: lbu         $t5, 0x6E($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X6E);
    // 0x800B3D3C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800B3D40: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x800B3D44: lbu         $t9, 0x6F($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X6F);
    // 0x800B3D48: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800B3D4C: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B3D50: or          $t4, $t8, $t6
    ctx->r12 = ctx->r24 | ctx->r14;
    // 0x800B3D54: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800B3D58: beq         $t2, $t1, L_800B3DA4
    if (ctx->r10 == ctx->r9) {
        // 0x800B3D5C: sw          $t5, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r13;
            goto L_800B3DA4;
    }
    // 0x800B3D5C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B3D60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B3D64: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800B3D68: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x800B3D6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B3D70: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B3D74: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x800B3D78: addiu       $t3, $zero, 0x10E
    ctx->r11 = ADD32(0, 0X10E);
    // 0x800B3D7C: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x800B3D80: sll         $t4, $t7, 24
    ctx->r12 = S32(ctx->r15 << 24);
    // 0x800B3D84: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800B3D88: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800B3D8C: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800B3D90: or          $t6, $t5, $t8
    ctx->r14 = ctx->r13 | ctx->r24;
    // 0x800B3D94: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x800B3D98: or          $t4, $t6, $t7
    ctx->r12 = ctx->r14 | ctx->r15;
    // 0x800B3D9C: b           L_800B3DC0
    // 0x800B3DA0: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
        goto L_800B3DC0;
    // 0x800B3DA0: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
L_800B3DA4:
    // 0x800B3DA4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3DA8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800B3DAC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B3DB0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B3DB4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B3DB8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B3DBC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800B3DC0:
    // 0x800B3DC0: lh          $t6, 0x2C($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2C);
    // 0x800B3DC4: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B3DC8: bne         $t6, $at, L_800B3E64
    if (ctx->r14 != ctx->r1) {
        // 0x800B3DCC: nop
    
            goto L_800B3E64;
    }
    // 0x800B3DCC: nop

    // 0x800B3DD0: lh          $v1, 0x18($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X18);
    // 0x800B3DD4: lw          $t0, 0x44($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X44);
    // 0x800B3DD8: sra         $t7, $v1, 8
    ctx->r15 = S32(SIGNED(ctx->r3) >> 8);
    // 0x800B3DDC: sh          $t7, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r15;
    // 0x800B3DE0: lh          $t4, 0x18($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X18);
    // 0x800B3DE4: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x800B3DE8: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3DEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B3DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3DF4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800B3DF8: mflo        $t9
    ctx->r25 = lo;
    // 0x800B3DFC: nop

    // 0x800B3E00: nop

    // 0x800B3E04: div         $zero, $t9, $t5
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r13)));
    // 0x800B3E08: bne         $t5, $zero, L_800B3E14
    if (ctx->r13 != 0) {
        // 0x800B3E0C: nop
    
            goto L_800B3E14;
    }
    // 0x800B3E0C: nop

    // 0x800B3E10: break       7
    do_break(2148220432);
L_800B3E14:
    // 0x800B3E14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B3E18: bne         $t5, $at, L_800B3E2C
    if (ctx->r13 != ctx->r1) {
        // 0x800B3E1C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B3E2C;
    }
    // 0x800B3E1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B3E20: bne         $t9, $at, L_800B3E2C
    if (ctx->r25 != ctx->r1) {
        // 0x800B3E24: nop
    
            goto L_800B3E2C;
    }
    // 0x800B3E24: nop

    // 0x800B3E28: break       6
    do_break(2148220456);
L_800B3E2C:
    // 0x800B3E2C: mflo        $t8
    ctx->r24 = lo;
    // 0x800B3E30: sh          $t8, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r24;
    // 0x800B3E34: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800B3E38: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800B3E3C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B3E40: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800B3E44: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800B3E48: jal         0x80068754
    // 0x800B3E4C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    render_sprite_billboard(rdram, ctx);
        goto after_0;
    // 0x800B3E4C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x800B3E50: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x800B3E54: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B3E58: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800B3E5C: b           L_800B3F80
    // 0x800B3E60: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
        goto L_800B3F80;
    // 0x800B3E60: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
L_800B3E64:
    // 0x800B3E64: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B3E68: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800B3E6C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B3E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3E74: beq         $t6, $zero, L_800B3F80
    if (ctx->r14 == 0) {
        // 0x800B3E78: or          $a2, $s1, $zero
        ctx->r6 = ctx->r17 | 0;
            goto L_800B3F80;
    }
    // 0x800B3E78: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800B3E7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B3E80: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B3E84: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800B3E88: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B3E8C: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800B3E90: jal         0x800696C4
    // 0x800B3E94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_1;
    // 0x800B3E94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800B3E98: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B3E9C: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B3EA0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800B3EA4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B3EA8: sll         $t7, $a3, 8
    ctx->r15 = S32(ctx->r7 << 8);
    // 0x800B3EAC: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800B3EB0: jal         0x8007B938
    // 0x800B3EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    material_set(rdram, ctx);
        goto after_2;
    // 0x800B3EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800B3EB8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3EBC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B3EC0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B3EC4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800B3EC8: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B3ECC: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x800B3ED0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B3ED4: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800B3ED8: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x800B3EDC: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x800B3EE0: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800B3EE4: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800B3EE8: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x800B3EEC: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x800B3EF0: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800B3EF4: addu        $t7, $t5, $a1
    ctx->r15 = ADD32(ctx->r13, ctx->r5);
    // 0x800B3EF8: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x800B3EFC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B3F00: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800B3F04: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x800B3F08: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800B3F0C: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x800B3F10: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B3F14: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B3F18: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800B3F1C: addu        $t4, $t7, $a3
    ctx->r12 = ADD32(ctx->r15, ctx->r7);
    // 0x800B3F20: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B3F24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3F2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B3F30: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B3F34: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x800B3F38: nop

    // 0x800B3F3C: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x800B3F40: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800B3F44: ori         $t5, $t8, 0x1
    ctx->r13 = ctx->r24 | 0X1;
    // 0x800B3F48: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x800B3F4C: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800B3F50: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x800B3F54: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800B3F58: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x800B3F5C: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800B3F60: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B3F64: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800B3F68: nop

    // 0x800B3F6C: addu        $t4, $t7, $a3
    ctx->r12 = ADD32(ctx->r15, ctx->r7);
    // 0x800B3F70: jal         0x80069C80
    // 0x800B3F74: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    mtx_pop(rdram, ctx);
        goto after_3;
    // 0x800B3F74: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    after_3:
    // 0x800B3F78: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B3F7C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
L_800B3F80:
    // 0x800B3F80: bne         $t2, $t1, L_800B3F98
    if (ctx->r10 != ctx->r9) {
        // 0x800B3F84: lui         $t8, 0xFA00
        ctx->r24 = S32(0XFA00 << 16);
            goto L_800B3F98;
    }
    // 0x800B3F84: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800B3F88: lh          $t6, 0x4A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4A);
    // 0x800B3F8C: nop

    // 0x800B3F90: beq         $t1, $t6, L_800B3FB0
    if (ctx->r9 == ctx->r14) {
        // 0x800B3F94: nop
    
            goto L_800B3FB0;
    }
    // 0x800B3F94: nop

L_800B3F98:
    // 0x800B3F98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3F9C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B3FA0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B3FA4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B3FA8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B3FAC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800B3FB0:
    // 0x800B3FB0: lbu         $t7, 0x6F($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X6F);
    // 0x800B3FB4: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800B3FB8: beq         $t7, $zero, L_800B43B4
    if (ctx->r15 == 0) {
        // 0x800B3FBC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B43B4;
    }
    // 0x800B3FBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B3FC0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3FC4: addiu       $t9, $zero, -0x100
    ctx->r25 = ADD32(0, -0X100);
    // 0x800B3FC8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B3FCC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800B3FD0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B3FD4: b           L_800B43B0
    // 0x800B3FD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_800B43B0;
    // 0x800B3FD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800B3FDC:
    // 0x800B3FDC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B3FE0: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x800B3FE4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B3FE8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800B3FEC: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x800B3FF0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B3FF4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B3FF8: lh          $v1, 0x2C($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2C);
    // 0x800B3FFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B4000: bne         $a1, $v1, L_800B4190
    if (ctx->r5 != ctx->r3) {
        // 0x800B4004: nop
    
            goto L_800B4190;
    }
    // 0x800B4004: nop

    // 0x800B4008: lh          $t4, 0x3A($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X3A);
    // 0x800B400C: nop

    // 0x800B4010: blez        $t4, L_800B43B4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B4014: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B43B4;
    }
    // 0x800B4014: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B4018: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B401C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800B4020: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B4024: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B4028: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B402C: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x800B4030: nop

    // 0x800B4034: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800B4038: sll         $t5, $t8, 24
    ctx->r13 = S32(ctx->r24 << 24);
    // 0x800B403C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800B4040: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800B4044: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x800B4048: or          $t9, $t4, $t6
    ctx->r25 = ctx->r12 | ctx->r14;
    // 0x800B404C: ori         $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 | 0XFF;
    // 0x800B4050: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B4054: lb          $t5, 0x77($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X77);
    // 0x800B4058: nop

    // 0x800B405C: bne         $t5, $zero, L_800B406C
    if (ctx->r13 != 0) {
        // 0x800B4060: nop
    
            goto L_800B406C;
    }
    // 0x800B4060: nop

    // 0x800B4064: jal         0x800B43C4
    // 0x800B4068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    regenerate_point_particles_mesh(rdram, ctx);
        goto after_4;
    // 0x800B4068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_800B406C:
    // 0x800B406C: lbu         $v0, 0x75($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X75);
    // 0x800B4070: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B4074: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B4078: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800B407C: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B4080: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x800B4084: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800B4088: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x800B408C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800B4090: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B4094: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x800B4098: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B409C: sll         $t8, $a3, 8
    ctx->r24 = S32(ctx->r7 << 8);
    // 0x800B40A0: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x800B40A4: ori         $a2, $a2, 0x10B
    ctx->r6 = ctx->r6 | 0X10B;
    // 0x800B40A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B40AC: jal         0x8007B938
    // 0x800B40B0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    material_set(rdram, ctx);
        goto after_5;
    // 0x800B40B0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_5:
    // 0x800B40B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B40B8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B40BC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B40C0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800B40C4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800B40C8: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x800B40CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B40D0: addu        $t0, $t7, $a3
    ctx->r8 = ADD32(ctx->r15, ctx->r7);
    // 0x800B40D4: addiu       $t4, $a1, -0x1
    ctx->r12 = ADD32(ctx->r5, -0X1);
    // 0x800B40D8: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x800B40DC: andi        $t9, $t0, 0x6
    ctx->r25 = ctx->r8 & 0X6;
    // 0x800B40E0: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x800B40E4: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x800B40E8: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800B40EC: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800B40F0: addu        $t9, $t6, $a1
    ctx->r25 = ADD32(ctx->r14, ctx->r5);
    // 0x800B40F4: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800B40F8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B40FC: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x800B4100: addiu       $t5, $t8, 0x8
    ctx->r13 = ADD32(ctx->r24, 0X8);
    // 0x800B4104: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x800B4108: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x800B410C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B4110: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800B4114: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4118: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800B411C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B4120: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B4124: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x800B4128: nop

    // 0x800B412C: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x800B4130: sll         $t5, $t8, 4
    ctx->r13 = S32(ctx->r24 << 4);
    // 0x800B4134: ori         $t4, $t5, 0x1
    ctx->r12 = ctx->r13 | 0X1;
    // 0x800B4138: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x800B413C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800B4140: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x800B4144: andi        $t5, $t8, 0xFFFF
    ctx->r13 = ctx->r24 & 0XFFFF;
    // 0x800B4148: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800B414C: or          $t4, $t9, $t5
    ctx->r12 = ctx->r25 | ctx->r13;
    // 0x800B4150: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B4154: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800B4158: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800B415C: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x800B4160: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B4164: lh          $t8, 0x4A($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4A);
    // 0x800B4168: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800B416C: beq         $t8, $at, L_800B43B4
    if (ctx->r24 == ctx->r1) {
        // 0x800B4170: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B43B4;
    }
    // 0x800B4170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B4174: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4178: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B417C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B4180: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B4184: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B4188: b           L_800B43B0
    // 0x800B418C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_800B43B0;
    // 0x800B418C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800B4190:
    // 0x800B4190: bne         $v1, $at, L_800B43B4
    if (ctx->r3 != ctx->r1) {
        // 0x800B4194: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B43B4;
    }
    // 0x800B4194: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B4198: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B419C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800B41A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B41A4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B41A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B41AC: lh          $v1, 0x4A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X4A);
    // 0x800B41B0: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x800B41B4: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800B41B8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800B41BC: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x800B41C0: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x800B41C4: or          $t4, $t9, $t5
    ctx->r12 = ctx->r25 | ctx->r13;
    // 0x800B41C8: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x800B41CC: andi        $t8, $t2, 0xFF
    ctx->r24 = ctx->r10 & 0XFF;
    // 0x800B41D0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800B41D4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B41D8: lbu         $a1, 0x68($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X68);
    // 0x800B41DC: ori         $a2, $a2, 0x10B
    ctx->r6 = ctx->r6 | 0X10B;
    // 0x800B41E0: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x800B41E4: bne         $at, $zero, L_800B42D0
    if (ctx->r1 != 0) {
        // 0x800B41E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800B42D0;
    }
    // 0x800B41E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B41EC: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B41F0: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B41F4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B41F8: sll         $t5, $a3, 8
    ctx->r13 = S32(ctx->r7 << 8);
    // 0x800B41FC: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x800B4200: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B4204: jal         0x8007B938
    // 0x800B4208: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    material_set(rdram, ctx);
        goto after_6;
    // 0x800B4208: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_6:
    // 0x800B420C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4210: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B4214: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B4218: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B421C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800B4220: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B4224: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x800B4228: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B422C: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x800B4230: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x800B4234: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800B4238: andi        $t5, $t9, 0x6
    ctx->r13 = ctx->r25 & 0X6;
    // 0x800B423C: or          $t4, $t6, $t5
    ctx->r12 = ctx->r14 | ctx->r13;
    // 0x800B4240: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x800B4244: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800B4248: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800B424C: addu        $t5, $t6, $a1
    ctx->r13 = ADD32(ctx->r14, ctx->r5);
    // 0x800B4250: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x800B4254: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B4258: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800B425C: addiu       $t7, $t4, 0x8
    ctx->r15 = ADD32(ctx->r12, 0X8);
    // 0x800B4260: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800B4264: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800B4268: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B426C: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B4270: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800B4274: addu        $t4, $t5, $a3
    ctx->r12 = ADD32(ctx->r13, ctx->r7);
    // 0x800B4278: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B427C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4280: nop

    // 0x800B4284: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B4288: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B428C: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x800B4290: nop

    // 0x800B4294: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x800B4298: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x800B429C: ori         $t6, $t8, 0x1
    ctx->r14 = ctx->r24 | 0X1;
    // 0x800B42A0: andi        $t5, $t6, 0xFF
    ctx->r13 = ctx->r14 & 0XFF;
    // 0x800B42A4: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x800B42A8: sll         $t9, $a2, 4
    ctx->r25 = S32(ctx->r6 << 4);
    // 0x800B42AC: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800B42B0: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x800B42B4: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800B42B8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B42BC: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800B42C0: nop

    // 0x800B42C4: addu        $t4, $t5, $a3
    ctx->r12 = ADD32(ctx->r13, ctx->r7);
    // 0x800B42C8: b           L_800B437C
    // 0x800B42CC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_800B437C;
    // 0x800B42CC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_800B42D0:
    // 0x800B42D0: blez        $a1, L_800B437C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800B42D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800B437C;
    }
    // 0x800B42D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B42D8: lw          $v1, 0x44($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X44);
    // 0x800B42DC: lh          $a3, 0x18($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X18);
    // 0x800B42E0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800B42E4: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x800B42E8: sll         $t9, $a3, 8
    ctx->r25 = S32(ctx->r7 << 8);
    // 0x800B42EC: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800B42F0: ori         $a2, $a2, 0x10B
    ctx->r6 = ctx->r6 | 0X10B;
    // 0x800B42F4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B42F8: jal         0x8007B938
    // 0x800B42FC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    material_set(rdram, ctx);
        goto after_7;
    // 0x800B42FC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_7:
    // 0x800B4300: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4304: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B4308: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B430C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B4310: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800B4314: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B4318: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800B431C: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800B4320: andi        $t5, $t6, 0x6
    ctx->r13 = ctx->r14 & 0X6;
    // 0x800B4324: ori         $t4, $t5, 0x18
    ctx->r12 = ctx->r13 | 0X18;
    // 0x800B4328: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x800B432C: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800B4330: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800B4334: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800B4338: ori         $t6, $t8, 0x50
    ctx->r14 = ctx->r24 | 0X50;
    // 0x800B433C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B4340: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B4344: lui         $t7, 0x501
    ctx->r15 = S32(0X501 << 16);
    // 0x800B4348: addu        $t4, $t5, $a3
    ctx->r12 = ADD32(ctx->r13, ctx->r7);
    // 0x800B434C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B4350: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B4354: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x800B4358: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B435C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800B4360: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B4364: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x800B4368: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x800B436C: sll         $t5, $t6, 4
    ctx->r13 = S32(ctx->r14 << 4);
    // 0x800B4370: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x800B4374: addu        $t9, $t4, $a3
    ctx->r25 = ADD32(ctx->r12, ctx->r7);
    // 0x800B4378: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800B437C:
    // 0x800B437C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800B4380: bne         $t2, $at, L_800B4398
    if (ctx->r10 != ctx->r1) {
        // 0x800B4384: lui         $t8, 0xFA00
        ctx->r24 = S32(0XFA00 << 16);
            goto L_800B4398;
    }
    // 0x800B4384: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800B4388: lh          $t7, 0x4A($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4A);
    // 0x800B438C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800B4390: beq         $t7, $at, L_800B43B4
    if (ctx->r15 == ctx->r1) {
        // 0x800B4394: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B43B4;
    }
    // 0x800B4394: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B4398:
    // 0x800B4398: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B439C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800B43A0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B43A4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800B43A8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B43AC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800B43B0:
    // 0x800B43B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B43B4:
    // 0x800B43B4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B43B8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B43BC: jr          $ra
    // 0x800B43C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B43C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void music_jingle_current(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001980: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001984: lbu         $v0, 0x6285($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6285);
    // 0x80001988: jr          $ra
    // 0x8000198C: nop

    return;
    // 0x8000198C: nop

;}
RECOMP_FUNC void initialise_player_viewport_vars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028D10: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80028D14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028D18: jal         0x80069F60
    // 0x80028D1C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80028D1C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80028D20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028D24: jal         0x80066460
    // 0x80028D28: sw          $v0, -0x49D0($at)
    MEM_W(-0X49D0, ctx->r1) = ctx->r2;
    get_current_viewport(rdram, ctx);
        goto after_1;
    // 0x80028D28: sw          $v0, -0x49D0($at)
    MEM_W(-0X49D0, ctx->r1) = ctx->r2;
    after_1:
    // 0x80028D2C: jal         0x80031058
    // 0x80028D30: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    compute_scene_camera_transform_matrix(rdram, ctx);
        goto after_2;
    // 0x80028D30: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80028D34: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80028D38: addiu       $v0, $v0, -0x2618
    ctx->r2 = ADD32(ctx->r2, -0X2618);
    // 0x80028D3C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80028D40: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80028D44: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80028D48: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80028D4C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80028D50: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80028D54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80028D58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80028D5C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80028D60: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80028D64: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80028D68: nop

    // 0x80028D6C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80028D70: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80028D74: div.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80028D78: jal         0x8001D614
    // 0x80028D7C: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    update_envmap_position(rdram, ctx);
        goto after_3;
    // 0x80028D7C: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    after_3:
    // 0x80028D80: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028D84: lw          $v1, -0x49D0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49D0);
    // 0x80028D88: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80028D8C: lh          $v0, 0x34($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X34);
    // 0x80028D90: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80028D94: bltz        $v0, L_80028DD0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80028D98: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80028DD0;
    }
    // 0x80028D98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80028D9C: lw          $a0, -0x3178($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3178);
    // 0x80028DA0: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x80028DA4: lh          $t9, 0x1A($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X1A);
    // 0x80028DA8: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80028DAC: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80028DB0: beq         $at, $zero, L_80028DD0
    if (ctx->r1 == 0) {
        // 0x80028DB4: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80028DD0;
    }
    // 0x80028DB4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80028DB8: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x80028DBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028DC0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80028DC4: lh          $t4, 0x28($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X28);
    // 0x80028DC8: b           L_80028DDC
    // 0x80028DCC: sw          $t4, -0x49AC($at)
    MEM_W(-0X49AC, ctx->r1) = ctx->r12;
        goto L_80028DDC;
    // 0x80028DCC: sw          $t4, -0x49AC($at)
    MEM_W(-0X49AC, ctx->r1) = ctx->r12;
L_80028DD0:
    // 0x80028DD0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80028DD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028DD8: sw          $t5, -0x49AC($at)
    MEM_W(-0X49AC, ctx->r1) = ctx->r13;
L_80028DDC:
    // 0x80028DDC: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80028DE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028DE4: swc1        $f6, -0x276C($at)
    MEM_W(-0X276C, ctx->r1) = ctx->f6.u32l;
    // 0x80028DE8: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80028DEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028DF0: swc1        $f8, -0x2768($at)
    MEM_W(-0X2768, ctx->r1) = ctx->f8.u32l;
    // 0x80028DF4: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80028DF8: lw          $t6, -0x26FC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26FC);
    // 0x80028DFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028E00: beq         $t6, $zero, L_80028FBC
    if (ctx->r14 == 0) {
        // 0x80028E04: swc1        $f10, -0x2764($at)
        MEM_W(-0X2764, ctx->r1) = ctx->f10.u32l;
            goto L_80028FBC;
    }
    // 0x80028E04: swc1        $f10, -0x2764($at)
    MEM_W(-0X2764, ctx->r1) = ctx->f10.u32l;
    // 0x80028E08: jal         0x800B90AC
    // 0x80028E0C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    waves_visibility_reset(rdram, ctx);
        goto after_4;
    // 0x80028E0C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80028E10: jal         0x8001BAA8
    // 0x80028E14: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    get_racer_objects(rdram, ctx);
        goto after_5;
    // 0x80028E14: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x80028E18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80028E1C: lw          $t7, -0x49D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49D0);
    // 0x80028E20: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80028E24: lh          $t8, 0x36($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X36);
    // 0x80028E28: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80028E2C: beq         $t8, $at, L_80028F2C
    if (ctx->r24 == ctx->r1) {
        // 0x80028E30: nop
    
            goto L_80028F2C;
    }
    // 0x80028E30: nop

    // 0x80028E34: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80028E38: nop

    // 0x80028E3C: blez        $t9, L_80028F2C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80028E40: nop
    
            goto L_80028F2C;
    }
    // 0x80028E40: nop

    // 0x80028E44: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80028E48: jal         0x80066750
    // 0x80028E4C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_6;
    // 0x80028E4C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80028E50: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80028E54: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80028E58: bne         $v0, $zero, L_80028F2C
    if (ctx->r2 != 0) {
        // 0x80028E5C: addiu       $v1, $a0, -0x4
        ctx->r3 = ADD32(ctx->r4, -0X4);
            goto L_80028F2C;
    }
    // 0x80028E5C: addiu       $v1, $a0, -0x4
    ctx->r3 = ADD32(ctx->r4, -0X4);
    // 0x80028E60: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80028E64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80028E68: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_80028E6C:
    // 0x80028E6C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80028E70: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028E74: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80028E78: lw          $a0, 0x64($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X64);
    // 0x80028E7C: beq         $at, $zero, L_80028E94
    if (ctx->r1 == 0) {
        // 0x80028E80: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80028E94;
    }
    // 0x80028E80: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80028E84: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x80028E88: nop

    // 0x80028E8C: bne         $a3, $t2, L_80028E6C
    if (ctx->r7 != ctx->r10) {
        // 0x80028E90: nop
    
            goto L_80028E6C;
    }
    // 0x80028E90: nop

L_80028E94:
    // 0x80028E94: jal         0x80066460
    // 0x80028E98: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    get_current_viewport(rdram, ctx);
        goto after_7;
    // 0x80028E98: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x80028E9C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80028EA0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80028EA4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80028EA8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80028EAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028EB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028EB4: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80028EB8: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80028EBC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80028EC0: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80028EC4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80028EC8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80028ECC: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80028ED0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80028ED4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80028ED8: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80028EDC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028EE0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028EE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80028EE8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028EEC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80028EF0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80028EF4: nop

    // 0x80028EF8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80028EFC: nop

    // 0x80028F00: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80028F04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028F08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028F0C: nop

    // 0x80028F10: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028F14: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80028F18: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80028F1C: jal         0x800B9124
    // 0x80028F20: nop

    waves_visibility(rdram, ctx);
        goto after_8;
    // 0x80028F20: nop

    after_8:
    // 0x80028F24: b           L_80028FBC
    // 0x80028F28: nop

        goto L_80028FBC;
    // 0x80028F28: nop

L_80028F2C:
    // 0x80028F2C: jal         0x80066460
    // 0x80028F30: nop

    get_current_viewport(rdram, ctx);
        goto after_9;
    // 0x80028F30: nop

    after_9:
    // 0x80028F34: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80028F38: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028F3C: lw          $v1, -0x49D0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49D0);
    // 0x80028F40: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80028F44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028F48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028F4C: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80028F50: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80028F54: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80028F58: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80028F5C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028F60: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80028F64: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80028F68: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80028F6C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80028F70: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80028F74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028F78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028F7C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80028F80: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028F84: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80028F88: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80028F8C: nop

    // 0x80028F90: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028F94: nop

    // 0x80028F98: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028F9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028FA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028FA4: nop

    // 0x80028FA8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028FAC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80028FB0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028FB4: jal         0x800B9124
    // 0x80028FB8: nop

    waves_visibility(rdram, ctx);
        goto after_10;
    // 0x80028FB8: nop

    after_10:
L_80028FBC:
    // 0x80028FBC: jal         0x8006BFF0
    // 0x80028FC0: nop

    level_header(rdram, ctx);
        goto after_11;
    // 0x80028FC0: nop

    after_11:
    // 0x80028FC4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80028FC8: jal         0x80028FEC
    // 0x80028FCC: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
    render_level_geometry_and_objects(rdram, ctx);
        goto after_12;
    // 0x80028FCC: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
    after_12:
    // 0x80028FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028FD4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80028FD8: jr          $ra
    // 0x80028FDC: nop

    return;
    // 0x80028FDC: nop

;}
RECOMP_FUNC void gzip_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C66D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C66D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C66D8: addiu       $a0, $zero, 0x2800
    ctx->r4 = ADD32(0, 0X2800);
    // 0x800C66DC: jal         0x80070EDC
    // 0x800C66E0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C66E0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_0:
    // 0x800C66E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C66E8: sw          $v0, 0x3CF0($at)
    MEM_W(0X3CF0, ctx->r1) = ctx->r2;
    // 0x800C66EC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800C66F0: jal         0x80070EDC
    // 0x800C66F4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800C66F4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_1:
    // 0x800C66F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C66FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6700: sw          $v0, 0x3CF4($at)
    MEM_W(0X3CF4, ctx->r1) = ctx->r2;
    // 0x800C6704: jr          $ra
    // 0x800C6708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C6708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mempool_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070E24: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80070E28: addiu       $t1, $t1, 0x3B40
    ctx->r9 = ADD32(ctx->r9, 0X3B40);
    // 0x80070E2C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80070E30: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80070E34: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80070E38: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80070E3C: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x80070E40: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x80070E44: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80070E48: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x80070E4C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80070E50: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x80070E54: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x80070E58: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80070E5C: blez        $a2, L_80070E7C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80070E60: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80070E7C;
    }
    // 0x80070E60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80070E64:
    // 0x80070E64: sh          $v1, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r3;
    // 0x80070E68: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80070E6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80070E70: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80070E74: bne         $at, $zero, L_80070E64
    if (ctx->r1 != 0) {
        // 0x80070E78: addiu       $t0, $t0, 0x14
        ctx->r8 = ADD32(ctx->r8, 0X14);
            goto L_80070E64;
    }
    // 0x80070E78: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
L_80070E7C:
    // 0x80070E7C: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80070E80: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80070E84: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80070E88: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80070E8C: lw          $t0, 0x8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X8);
    // 0x80070E90: andi        $t3, $a0, 0xF
    ctx->r11 = ctx->r4 & 0XF;
    // 0x80070E94: beq         $t3, $zero, L_80070EB0
    if (ctx->r11 == 0) {
        // 0x80070E98: subu        $t6, $a1, $v1
        ctx->r14 = SUB32(ctx->r5, ctx->r3);
            goto L_80070EB0;
    }
    // 0x80070E98: subu        $t6, $a1, $v1
    ctx->r14 = SUB32(ctx->r5, ctx->r3);
    // 0x80070E9C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80070EA0: and         $t4, $a0, $at
    ctx->r12 = ctx->r4 & ctx->r1;
    // 0x80070EA4: addiu       $t5, $t4, 0x10
    ctx->r13 = ADD32(ctx->r12, 0X10);
    // 0x80070EA8: b           L_80070EB4
    // 0x80070EAC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
        goto L_80070EB4;
    // 0x80070EAC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_80070EB0:
    // 0x80070EB0: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
L_80070EB4:
    // 0x80070EB4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80070EB8: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80070EBC: sh          $zero, 0x8($t0)
    MEM_H(0X8, ctx->r8) = 0;
    // 0x80070EC0: sh          $a0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r4;
    // 0x80070EC4: sh          $a0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r4;
    // 0x80070EC8: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80070ECC: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x80070ED0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80070ED4: jr          $ra
    // 0x80070ED8: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    return;
    // 0x80070ED8: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
;}
RECOMP_FUNC void audspat_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008048: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000804C: addiu       $a0, $a0, -0x5E40
    ctx->r4 = ADD32(ctx->r4, -0X5E40);
    // 0x80008050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008054: jal         0x80002128
    // 0x80008058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sound_table_properties(rdram, ctx);
        goto after_0;
    // 0x80008058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000805C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80008060: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80008064: jal         0x80070EDC
    // 0x80008068: addiu       $a0, $zero, 0x5A0
    ctx->r4 = ADD32(0, 0X5A0);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80008068: addiu       $a0, $zero, 0x5A0
    ctx->r4 = ADD32(0, 0X5A0);
    after_1:
    // 0x8000806C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80008070: addiu       $a2, $a2, -0x5E38
    ctx->r6 = ADD32(ctx->r6, -0X5E38);
    // 0x80008074: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80008078: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8000807C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80008080: jal         0x80070EDC
    // 0x80008084: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80008084: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_2:
    // 0x80008088: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000808C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80008090: sw          $v0, -0x5E30($at)
    MEM_W(-0X5E30, ctx->r1) = ctx->r2;
    // 0x80008094: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80008098: jal         0x80070EDC
    // 0x8000809C: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8000809C: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_3:
    // 0x800080A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800080A4: sw          $v0, -0x5E3C($at)
    MEM_W(-0X5E3C, ctx->r1) = ctx->r2;
    // 0x800080A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800080AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800080B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800080B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800080B8: addiu       $a2, $a2, -0x5E38
    ctx->r6 = ADD32(ctx->r6, -0X5E38);
    // 0x800080BC: sh          $zero, -0x33B0($at)
    MEM_H(-0X33B0, ctx->r1) = 0;
    // 0x800080C0: addiu       $v1, $v1, -0x5E28
    ctx->r3 = ADD32(ctx->r3, -0X5E28);
    // 0x800080C4: addiu       $v0, $v0, -0x53A8
    ctx->r2 = ADD32(ctx->r2, -0X53A8);
L_800080C8:
    // 0x800080C8: addiu       $v1, $v1, 0x180
    ctx->r3 = ADD32(ctx->r3, 0X180);
    // 0x800080CC: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800080D0: bne         $at, $zero, L_800080C8
    if (ctx->r1 != 0) {
        // 0x800080D4: sw          $zero, -0x8($v1)
        MEM_W(-0X8, ctx->r3) = 0;
            goto L_800080C8;
    }
    // 0x800080D4: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x800080D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800080DC: addiu       $v1, $zero, 0x5A0
    ctx->r3 = ADD32(0, 0X5A0);
L_800080E0:
    // 0x800080E0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800080E4: nop

    // 0x800080E8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800080EC: sw          $zero, 0x18($t7)
    MEM_W(0X18, ctx->r15) = 0;
    // 0x800080F0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800080F4: nop

    // 0x800080F8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800080FC: sw          $zero, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = 0;
    // 0x80008100: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80008104: nop

    // 0x80008108: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8000810C: sw          $zero, 0x60($t1)
    MEM_W(0X60, ctx->r9) = 0;
    // 0x80008110: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80008114: nop

    // 0x80008118: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8000811C: addiu       $v0, $v0, 0x90
    ctx->r2 = ADD32(ctx->r2, 0X90);
    // 0x80008120: bne         $v0, $v1, L_800080E0
    if (ctx->r2 != ctx->r3) {
        // 0x80008124: sw          $zero, 0x84($t3)
        MEM_W(0X84, ctx->r11) = 0;
            goto L_800080E0;
    }
    // 0x80008124: sw          $zero, 0x84($t3)
    MEM_W(0X84, ctx->r11) = 0;
    // 0x80008128: jal         0x80008174
    // 0x8000812C: nop

    audspat_reset(rdram, ctx);
        goto after_4;
    // 0x8000812C: nop

    after_4:
    // 0x80008130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008138: jr          $ra
    // 0x8000813C: nop

    return;
    // 0x8000813C: nop

;}
RECOMP_FUNC void obj_loop_banana(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D5E0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003D5E4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003D5E8: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003D5EC: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003D5F0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003D5F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003D5F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003D5FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003D600: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8003D604: bne         $t7, $zero, L_8003D624
    if (ctx->r15 != 0) {
        // 0x8003D608: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8003D624;
    }
    // 0x8003D608: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003D60C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D610: lwc1        $f9, 0x6720($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6720);
    // 0x8003D614: lwc1        $f8, 0x6724($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6724);
    // 0x8003D618: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D61C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003D620: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8003D624:
    // 0x8003D624: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x8003D628: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003D62C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8003D630: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x8003D634: lw          $t5, 0x78($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X78);
    // 0x8003D638: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8003D63C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003D640: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8003D644: bne         $t5, $at, L_8003D6AC
    if (ctx->r13 != ctx->r1) {
        // 0x8003D648: sh          $t4, 0x18($s0)
        MEM_H(0X18, ctx->r16) = ctx->r12;
            goto L_8003D6AC;
    }
    // 0x8003D648: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
    // 0x8003D64C: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x8003D650: addiu       $t1, $s0, 0x78
    ctx->r9 = ADD32(ctx->r16, 0X78);
    // 0x8003D654: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x8003D658: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x8003D65C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003D660: lh          $t8, 0x6($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X6);
    // 0x8003D664: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003D668: subu        $t9, $t8, $t2
    ctx->r25 = SUB32(ctx->r24, ctx->r10);
    // 0x8003D66C: sh          $t9, 0x6($t1)
    MEM_H(0X6, ctx->r9) = ctx->r25;
    // 0x8003D670: sw          $t3, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r11;
    // 0x8003D674: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8003D678: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003D67C: jal         0x800B019C
    // 0x8003D680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_0;
    // 0x8003D680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8003D684: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D688: nop

    // 0x8003D68C: lh          $t4, 0x6($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X6);
    // 0x8003D690: nop

    // 0x8003D694: bgtz        $t4, L_8003DBD4
    if (SIGNED(ctx->r12) > 0) {
        // 0x8003D698: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003D698: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003D69C: jal         0x8000FFB8
    // 0x8003D6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x8003D6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003D6A4: b           L_8003DBD4
    // 0x8003D6A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003DBD4;
    // 0x8003D6A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003D6AC:
    // 0x8003D6AC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D6B0: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x8003D6B4: lb          $v0, 0x8($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X8);
    // 0x8003D6B8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D6BC: blez        $v0, L_8003D6D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D6C0: addiu       $t1, $s0, 0x78
        ctx->r9 = ADD32(ctx->r16, 0X78);
            goto L_8003D6D0;
    }
    // 0x8003D6C0: addiu       $t1, $s0, 0x78
    ctx->r9 = ADD32(ctx->r16, 0X78);
    // 0x8003D6C4: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8003D6C8: b           L_8003D6D8
    // 0x8003D6CC: sb          $t7, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r15;
        goto L_8003D6D8;
    // 0x8003D6CC: sb          $t7, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r15;
L_8003D6D0:
    // 0x8003D6D0: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
    // 0x8003D6D4: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_8003D6D8:
    // 0x8003D6D8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8003D6DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003D6E0: bne         $t2, $at, L_8003D950
    if (ctx->r10 != ctx->r1) {
        // 0x8003D6E4: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_8003D950;
    }
    // 0x8003D6E4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D6E8: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D6EC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D6F0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003D6F4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003D6F8: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8003D6FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003D700: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8003D704: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x8003D708: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8003D70C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D710: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D714: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003D718: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8003D71C: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8003D720: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003D724: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x8003D728: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D72C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003D730: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003D734: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8003D738: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003D73C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003D740: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8003D744: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x8003D748: jal         0x80031170
    // 0x8003D74C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_2;
    // 0x8003D74C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8003D750: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D754: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003D758: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x8003D75C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8003D760: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8003D764: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003D768: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8003D76C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8003D770: jal         0x80031640
    // 0x8003D774: addiu       $a3, $sp, 0x43
    ctx->r7 = ADD32(ctx->r29, 0X43);
    resolve_collisions(rdram, ctx);
        goto after_3;
    // 0x8003D774: addiu       $a3, $sp, 0x43
    ctx->r7 = ADD32(ctx->r29, 0X43);
    after_3:
    // 0x8003D778: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003D77C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D780: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8003D784: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003D788: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D78C: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003D790: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D794: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003D798: mtc1        $zero, $f13
    ctx->f_odd[(13 - 1) * 2] = 0;
    // 0x8003D79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D7A0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8003D7A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003D7A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003D7AC: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x8003D7B0: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003D7B4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003D7B8: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8003D7BC: nop

    // 0x8003D7C0: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003D7C4: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8003D7C8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003D7CC: nop

    // 0x8003D7D0: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8003D7D4: nop

    // 0x8003D7D8: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003D7DC: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8003D7E0: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003D7E4: nop

    // 0x8003D7E8: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8003D7EC: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003D7F0: nop

    // 0x8003D7F4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8003D7F8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003D7FC: nop

    // 0x8003D800: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8003D804: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D808: nop

    // 0x8003D80C: lb          $t6, 0x9($t4)
    ctx->r14 = MEM_B(ctx->r12, 0X9);
    // 0x8003D810: nop

    // 0x8003D814: beq         $t6, $at, L_8003D870
    if (ctx->r14 == ctx->r1) {
        // 0x8003D818: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8003D870;
    }
    // 0x8003D818: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D81C: lwc1        $f1, 0x6728($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6728);
    // 0x8003D820: lwc1        $f0, 0x672C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X672C);
    // 0x8003D824: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003D828: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8003D82C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003D830: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003D834: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8003D838: sub.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d - ctx->f18.d;
    // 0x8003D83C: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D840: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8003D844: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D848: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8003D84C: mul.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8003D850: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8003D854: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8003D858: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8003D85C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x8003D860: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x8003D864: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8003D868: b           L_8003D884
    // 0x8003D86C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
        goto L_8003D884;
    // 0x8003D86C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_8003D870:
    // 0x8003D870: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003D874: nop

    // 0x8003D878: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8003D87C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x8003D880: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8003D884:
    // 0x8003D884: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003D888: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003D88C: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D890: c.lt.d      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.d < ctx->f12.d;
    // 0x8003D894: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8003D898: bc1f        L_8003D8A4
    if (!c1cs) {
        // 0x8003D89C: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8003D8A4;
    }
    // 0x8003D89C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003D8A0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8003D8A4:
    // 0x8003D8A4: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003D8A8: nop

    // 0x8003D8AC: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8003D8B0: c.lt.d      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.d < ctx->f12.d;
    // 0x8003D8B4: nop

    // 0x8003D8B8: bc1f        L_8003D8C4
    if (!c1cs) {
        // 0x8003D8BC: nop
    
            goto L_8003D8C4;
    }
    // 0x8003D8BC: nop

    // 0x8003D8C0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8003D8C4:
    // 0x8003D8C4: blez        $t7, L_8003D900
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8003D8C8: nop
    
            goto L_8003D900;
    }
    // 0x8003D8C8: nop

    // 0x8003D8CC: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8003D8D0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003D8D4: cvt.d.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.d = CVT_D_S(ctx->f2.fl);
    // 0x8003D8D8: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x8003D8DC: nop

    // 0x8003D8E0: bc1f        L_8003D900
    if (!c1cs) {
        // 0x8003D8E4: nop
    
            goto L_8003D900;
    }
    // 0x8003D8E4: nop

    // 0x8003D8E8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003D8EC: c.lt.d      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.d < ctx->f12.d;
    // 0x8003D8F0: nop

    // 0x8003D8F4: bc1f        L_8003D900
    if (!c1cs) {
        // 0x8003D8F8: nop
    
            goto L_8003D900;
    }
    // 0x8003D8F8: nop

    // 0x8003D8FC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_8003D900:
    // 0x8003D900: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D904: lwc1        $f4, 0x6730($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6730);
    // 0x8003D908: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003D90C: jal         0x8002B9FC
    // 0x8003D910: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    func_8002B9BC(rdram, ctx);
        goto after_4;
    // 0x8003D910: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8003D914: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D918: beq         $v0, $zero, L_8003D950
    if (ctx->r2 == 0) {
        // 0x8003D91C: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_8003D950;
    }
    // 0x8003D91C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D920: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D924: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003D928: nop

    // 0x8003D92C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8003D930: nop

    // 0x8003D934: bc1f        L_8003D950
    if (!c1cs) {
        // 0x8003D938: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_8003D950;
    }
    // 0x8003D938: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D93C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8003D940: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003D944: nop

    // 0x8003D948: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8003D94C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
L_8003D950:
    // 0x8003D950: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003D954: lb          $t8, 0x9($t5)
    ctx->r24 = MEM_B(ctx->r13, 0X9);
    // 0x8003D958: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003D95C: beq         $t8, $at, L_8003D968
    if (ctx->r24 == ctx->r1) {
        // 0x8003D960: addiu       $a0, $zero, 0x46
        ctx->r4 = ADD32(0, 0X46);
            goto L_8003D968;
    }
    // 0x8003D960: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x8003D964: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
L_8003D968:
    // 0x8003D968: lh          $v0, 0x4($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X4);
    // 0x8003D96C: nop

    // 0x8003D970: blez        $v0, L_8003D980
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D974: subu        $t9, $v0, $t2
        ctx->r25 = SUB32(ctx->r2, ctx->r10);
            goto L_8003D980;
    }
    // 0x8003D974: subu        $t9, $v0, $t2
    ctx->r25 = SUB32(ctx->r2, ctx->r10);
    // 0x8003D978: b           L_8003D984
    // 0x8003D97C: sh          $t9, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r25;
        goto L_8003D984;
    // 0x8003D97C: sh          $t9, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r25;
L_8003D980:
    // 0x8003D980: sh          $zero, 0x4($t1)
    MEM_H(0X4, ctx->r9) = 0;
L_8003D984:
    // 0x8003D984: lw          $t3, 0x4C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4C);
    // 0x8003D988: nop

    // 0x8003D98C: lbu         $t4, 0x13($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X13);
    // 0x8003D990: nop

    // 0x8003D994: slti        $at, $t4, 0x78
    ctx->r1 = SIGNED(ctx->r12) < 0X78 ? 1 : 0;
    // 0x8003D998: beq         $at, $zero, L_8003DA0C
    if (ctx->r1 == 0) {
        // 0x8003D99C: nop
    
            goto L_8003DA0C;
    }
    // 0x8003D99C: nop

    // 0x8003D9A0: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    // 0x8003D9A4: jal         0x8006BFD8
    // 0x8003D9A8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    level_type(rdram, ctx);
        goto after_5;
    // 0x8003D9A8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_5:
    // 0x8003D9AC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8003D9B0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003D9B4: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8003D9B8: bne         $v0, $at, L_8003DA0C
    if (ctx->r2 != ctx->r1) {
        // 0x8003D9BC: nop
    
            goto L_8003DA0C;
    }
    // 0x8003D9BC: nop

    // 0x8003D9C0: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003D9C4: nop

    // 0x8003D9C8: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8003D9CC: nop

    // 0x8003D9D0: beq         $v1, $zero, L_8003DA0C
    if (ctx->r3 == 0) {
        // 0x8003D9D4: nop
    
            goto L_8003DA0C;
    }
    // 0x8003D9D4: nop

    // 0x8003D9D8: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8003D9DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003D9E0: lb          $t5, 0x54($t7)
    ctx->r13 = MEM_B(ctx->r15, 0X54);
    // 0x8003D9E4: nop

    // 0x8003D9E8: bne         $t5, $at, L_8003DA0C
    if (ctx->r13 != ctx->r1) {
        // 0x8003D9EC: nop
    
            goto L_8003DA0C;
    }
    // 0x8003D9EC: nop

    // 0x8003D9F0: lw          $t0, 0x64($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X64);
    // 0x8003D9F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003D9F8: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x8003D9FC: nop

    // 0x8003DA00: bne         $t8, $at, L_8003DA0C
    if (ctx->r24 != ctx->r1) {
        // 0x8003DA04: nop
    
            goto L_8003DA0C;
    }
    // 0x8003DA04: nop

    // 0x8003DA08: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
L_8003DA0C:
    // 0x8003DA0C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003DA10: nop

    // 0x8003DA14: lbu         $t2, 0x13($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X13);
    // 0x8003DA18: nop

    // 0x8003DA1C: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8003DA20: beq         $at, $zero, L_8003DBD4
    if (ctx->r1 == 0) {
        // 0x8003DA24: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003DA24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DA28: lh          $t9, 0x4($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X4);
    // 0x8003DA2C: nop

    // 0x8003DA30: bne         $t9, $zero, L_8003DBD4
    if (ctx->r25 != 0) {
        // 0x8003DA34: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003DA34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DA38: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003DA3C: nop

    // 0x8003DA40: beq         $v1, $zero, L_8003DBD4
    if (ctx->r3 == 0) {
        // 0x8003DA44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003DA44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DA48: lw          $t3, 0x40($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X40);
    // 0x8003DA4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DA50: lb          $t4, 0x54($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X54);
    // 0x8003DA54: nop

    // 0x8003DA58: bne         $t4, $at, L_8003DBD4
    if (ctx->r12 != ctx->r1) {
        // 0x8003DA5C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003DA5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003DA60: lw          $t0, 0x64($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X64);
    // 0x8003DA64: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003DA68: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x8003DA6C: jal         0x8006BFD8
    // 0x8003DA70: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    level_type(rdram, ctx);
        goto after_6;
    // 0x8003DA70: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    after_6:
    // 0x8003DA74: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8003DA78: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DA7C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DA80: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8003DA84: bne         $v0, $at, L_8003DAA0
    if (ctx->r2 != ctx->r1) {
        // 0x8003DA88: addiu       $a0, $zero, 0x22
        ctx->r4 = ADD32(0, 0X22);
            goto L_8003DAA0;
    }
    // 0x8003DA88: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8003DA8C: lb          $t6, 0x185($t0)
    ctx->r14 = MEM_B(ctx->r8, 0X185);
    // 0x8003DA90: nop

    // 0x8003DA94: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8003DA98: beq         $at, $zero, L_8003DBD4
    if (ctx->r1 == 0) {
        // 0x8003DA9C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003DBD4;
    }
    // 0x8003DA9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003DAA0:
    // 0x8003DAA0: lw          $t7, 0x180($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X180);
    // 0x8003DAA4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8003DAA8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8003DAAC: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x8003DAB0: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x8003DAB4: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x8003DAB8: addiu       $t8, $t0, 0x180
    ctx->r24 = ADD32(ctx->r8, 0X180);
    // 0x8003DABC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003DAC0: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003DAC4: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8003DAC8: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x8003DACC: jal         0x80009558
    // 0x8003DAD0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_7;
    // 0x8003DAD0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_7:
    // 0x8003DAD4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003DAD8: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8003DADC: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DAE0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DAE4: beq         $a0, $zero, L_8003DB0C
    if (ctx->r4 == 0) {
        // 0x8003DAE8: nop
    
            goto L_8003DB0C;
    }
    // 0x8003DAE8: nop

    // 0x8003DAEC: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x8003DAF0: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8003DAF4: jal         0x800096F8
    // 0x8003DAF8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    audspat_point_stop(rdram, ctx);
        goto after_8;
    // 0x8003DAF8: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_8:
    // 0x8003DAFC: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8003DB00: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DB04: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DB08: nop

L_8003DB0C:
    // 0x8003DB0C: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x8003DB10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003DB14: beq         $t2, $at, L_8003DB64
    if (ctx->r10 == ctx->r1) {
        // 0x8003DB18: nop
    
            goto L_8003DB64;
    }
    // 0x8003DB18: nop

    // 0x8003DB1C: lb          $t9, 0x185($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X185);
    // 0x8003DB20: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8003DB24: bne         $t9, $at, L_8003DB64
    if (ctx->r25 != ctx->r1) {
        // 0x8003DB28: nop
    
            goto L_8003DB64;
    }
    // 0x8003DB28: nop

    // 0x8003DB2C: lb          $a0, 0x3($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X3);
    // 0x8003DB30: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x8003DB34: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x8003DB38: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x8003DB3C: addiu       $a0, $a0, 0x7B
    ctx->r4 = ADD32(ctx->r4, 0X7B);
    // 0x8003DB40: andi        $t3, $a0, 0xFFFF
    ctx->r11 = ctx->r4 & 0XFFFF;
    // 0x8003DB44: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8003DB48: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8003DB4C: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8003DB50: jal         0x80001EA8
    // 0x8003DB54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_9;
    // 0x8003DB54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x8003DB58: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8003DB5C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DB60: nop

L_8003DB64:
    // 0x8003DB64: lb          $t4, 0x185($t0)
    ctx->r12 = MEM_B(ctx->r8, 0X185);
    // 0x8003DB68: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003DB6C: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8003DB70: sb          $t6, 0x185($t0)
    MEM_B(0X185, ctx->r8) = ctx->r14;
    // 0x8003DB74: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8003DB78: nop

    // 0x8003DB7C: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x8003DB80: nop

    // 0x8003DB84: beq         $v0, $zero, L_8003DB90
    if (ctx->r2 == 0) {
        // 0x8003DB88: nop
    
            goto L_8003DB90;
    }
    // 0x8003DB88: nop

    // 0x8003DB8C: sw          $t5, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r13;
L_8003DB90:
    // 0x8003DB90: jal         0x8009C90C
    // 0x8003DB94: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    get_number_of_active_players(rdram, ctx);
        goto after_10;
    // 0x8003DB94: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_10:
    // 0x8003DB98: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8003DB9C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8003DBA0: bne         $at, $zero, L_8003DBB8
    if (ctx->r1 != 0) {
        // 0x8003DBA4: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8003DBB8;
    }
    // 0x8003DBA4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8003DBA8: jal         0x8000FFB8
    // 0x8003DBAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_11;
    // 0x8003DBAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8003DBB0: b           L_8003DBD4
    // 0x8003DBB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003DBD4;
    // 0x8003DBB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003DBB8:
    // 0x8003DBB8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8003DBBC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003DBC0: sw          $t2, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r10;
    // 0x8003DBC4: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8003DBC8: jal         0x800B019C
    // 0x8003DBCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_12;
    // 0x8003DBCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8003DBD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003DBD4:
    // 0x8003DBD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003DBD8: jr          $ra
    // 0x8003DBDC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003DBDC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void debug_render_checkpoint_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC74: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001BC78: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001BC7C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001BC80: jr          $ra
    // 0x8001BC84: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x8001BC84: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void swap_lead_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F5D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F5DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F5E0: jal         0x8006A74C
    // 0x8006F5E4: nop

    input_swap_id(rdram, ctx);
        goto after_0;
    // 0x8006F5E4: nop

    after_0:
    // 0x8006F5E8: jal         0x8000E194
    // 0x8006F5EC: nop

    toggle_lead_player_index(rdram, ctx);
        goto after_1;
    // 0x8006F5EC: nop

    after_1:
    // 0x8006F5F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006F5F4: lw          $v0, 0x3A90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A90);
    // 0x8006F5F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006F5FC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8006F600: addiu       $v1, $v0, 0x54
    ctx->r3 = ADD32(ctx->r2, 0X54);
    // 0x8006F604: addiu       $a0, $v0, 0x6C
    ctx->r4 = ADD32(ctx->r2, 0X6C);
L_8006F608:
    // 0x8006F608: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006F60C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8006F610: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8006F614: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8006F618: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8006F61C: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8006F620: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x8006F624: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006F628: sb          $t7, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r15;
    // 0x8006F62C: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8006F630: lbu         $v0, -0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X2);
    // 0x8006F634: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x8006F638: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006F63C: sb          $t8, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r24;
    // 0x8006F640: sb          $v0, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r2;
    // 0x8006F644: lbu         $v0, -0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X1);
    // 0x8006F648: lbu         $t9, -0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X1);
    // 0x8006F64C: nop

    // 0x8006F650: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x8006F654: bne         $a1, $a2, L_8006F608
    if (ctx->r5 != ctx->r6) {
        // 0x8006F658: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_8006F608;
    }
    // 0x8006F658: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
    // 0x8006F65C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F664: jr          $ra
    // 0x8006F668: nop

    return;
    // 0x8006F668: nop

;}
RECOMP_FUNC void set_position_goal_from_path(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800590C0: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800590C4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800590C8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800590CC: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800590D0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800590D4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800590D8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800590DC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800590E0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800590E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800590E8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800590EC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800590F0: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800590F4: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800590F8: jal         0x8001BA98
    // 0x800590FC: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    get_checkpoint_count(rdram, ctx);
        goto after_0;
    // 0x800590FC: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    after_0:
    // 0x80059100: beq         $v0, $zero, L_80059218
    if (ctx->r2 == 0) {
        // 0x80059104: or          $s6, $v0, $zero
        ctx->r22 = ctx->r2 | 0;
            goto L_80059218;
    }
    // 0x80059104: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80059108: lwc1        $f6, 0xA8($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0XA8);
    // 0x8005910C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80059110: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80059114: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80059118: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005911C: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x80059120: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80059124: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x80059128: addiu       $s2, $sp, 0x84
    ctx->r18 = ADD32(ctx->r29, 0X84);
    // 0x8005912C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80059130: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x80059134: bc1f        L_80059140
    if (!c1cs) {
        // 0x80059138: addiu       $s0, $sp, 0x5C
        ctx->r16 = ADD32(ctx->r29, 0X5C);
            goto L_80059140;
    }
    // 0x80059138: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x8005913C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80059140:
    // 0x80059140: lb          $v1, 0x192($s5)
    ctx->r3 = MEM_B(ctx->r21, 0X192);
    // 0x80059144: addiu       $s4, $sp, 0x70
    ctx->r20 = ADD32(ctx->r29, 0X70);
    // 0x80059148: addiu       $s1, $v1, -0x2
    ctx->r17 = ADD32(ctx->r3, -0X2);
    // 0x8005914C: bgez        $s1, L_80059158
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80059150: nop
    
            goto L_80059158;
    }
    // 0x80059150: nop

    // 0x80059154: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_80059158:
    // 0x80059158: lbu         $a1, 0x1C8($s5)
    ctx->r5 = MEM_BU(ctx->r21, 0X1C8);
    // 0x8005915C: jal         0x8001BA50
    // 0x80059160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_1;
    // 0x80059160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80059164: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80059168: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005916C: swc1        $f16, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
    // 0x80059170: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80059174: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80059178: swc1        $f18, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f18.u32l;
    // 0x8005917C: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80059180: bne         $s1, $s6, L_8005918C
    if (ctx->r17 != ctx->r22) {
        // 0x80059184: swc1        $f6, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
            goto L_8005918C;
    }
    // 0x80059184: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x80059188: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8005918C:
    // 0x8005918C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80059190: bne         $s0, $s4, L_80059158
    if (ctx->r16 != ctx->r20) {
        // 0x80059194: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80059158;
    }
    // 0x80059194: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80059198: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005919C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800591A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800591A4: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x800591A8: c.le.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d <= ctx->f0.d;
    // 0x800591AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800591B0: bc1f        L_800591D0
    if (!c1cs) {
        // 0x800591B4: addiu       $a0, $sp, 0x84
        ctx->r4 = ADD32(ctx->r29, 0X84);
            goto L_800591D0;
    }
    // 0x800591B4: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800591B8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800591BC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800591C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800591C4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800591C8: sub.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d - ctx->f8.d;
    // 0x800591CC: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
L_800591D0:
    // 0x800591D0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800591D4: jal         0x80022574
    // 0x800591D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_2;
    // 0x800591D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800591DC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800591E0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800591E4: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x800591E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800591EC: jal         0x80022574
    // 0x800591F0: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_3;
    // 0x800591F0: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    after_3:
    // 0x800591F4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800591F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800591FC: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80059200: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80059204: jal         0x80022574
    // 0x80059208: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_4;
    // 0x80059208: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    after_4:
    // 0x8005920C: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x80059210: nop

    // 0x80059214: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
L_80059218:
    // 0x80059218: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005921C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80059220: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80059224: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80059228: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005922C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80059230: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80059234: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80059238: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8005923C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80059240: jr          $ra
    // 0x80059244: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80059244: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800BB2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB814: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800BB818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BB81C: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800BB820: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800BB824: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800BB828: bltz        $a0, L_800BB848
    if (SIGNED(ctx->r4) < 0) {
        // 0x800BB82C: sw          $a3, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r7;
            goto L_800BB848;
    }
    // 0x800BB82C: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800BB830: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BB834: lw          $t7, -0x5960($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5960);
    // 0x800BB838: nop

    // 0x800BB83C: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BB840: bne         $at, $zero, L_800BB850
    if (ctx->r1 != 0) {
        // 0x800BB844: lw          $t8, 0xA8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA8);
            goto L_800BB850;
    }
    // 0x800BB844: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
L_800BB848:
    // 0x800BB848: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x800BB84C: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
L_800BB850:
    // 0x800BB850: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BB854: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800BB858: lw          $t9, 0x3668($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3668);
    // 0x800BB85C: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x800BB860: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BB864: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x800BB868: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BB86C: lw          $t9, 0x370C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X370C);
    // 0x800BB870: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x800BB874: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB878: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800BB87C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB880: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BB884: lwc1        $f6, -0x5984($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800BB888: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB88C: lwc1        $f8, -0x5988($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BB890: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800BB894: addiu       $t1, $t1, -0x5A78
    ctx->r9 = ADD32(ctx->r9, -0X5A78);
    // 0x800BB898: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x800BB89C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB8A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB8A4: lwc1        $f4, 0x44($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X44);
    // 0x800BB8A8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800BB8AC: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800BB8B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BB8B4: lw          $t7, 0x28($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X28);
    // 0x800BB8B8: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB8BC: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x800BB8C0: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x800BB8C4: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x800BB8C8: beq         $t7, $zero, L_800BB900
    if (ctx->r15 == 0) {
        // 0x800BB8CC: div.s       $f16, $f10, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
            goto L_800BB900;
    }
    // 0x800BB8CC: div.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800BB8D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BB8D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB8D8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BB8DC: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BB8E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BB8E4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BB8E8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BB8EC: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800BB8F0: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x800BB8F4: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x800BB8F8: b           L_800BB910
    // 0x800BB8FC: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
        goto L_800BB910;
    // 0x800BB8FC: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
L_800BB900:
    // 0x800BB900: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BB904: nop

    // 0x800BB908: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BB90C: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
L_800BB910:
    // 0x800BB910: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x800BB914: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BB918: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800BB91C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB920: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB924: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BB928: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800BB92C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800BB930: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x800BB934: bc1f        L_800BB948
    if (!c1cs) {
        // 0x800BB938: nop
    
            goto L_800BB948;
    }
    // 0x800BB938: nop

    // 0x800BB93C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BB940: b           L_800BB974
    // 0x800BB944: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
        goto L_800BB974;
    // 0x800BB944: swc1        $f4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f4.u32l;
L_800BB948:
    // 0x800BB948: lwc1        $f0, -0x59A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800BB94C: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BB950: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB954: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x800BB958: nop

    // 0x800BB95C: bc1f        L_800BB974
    if (!c1cs) {
        // 0x800BB960: nop
    
            goto L_800BB974;
    }
    // 0x800BB960: nop

    // 0x800BB964: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB968: nop

    // 0x800BB96C: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800BB970: swc1        $f8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f8.u32l;
L_800BB974:
    // 0x800BB974: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x800BB978: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BB97C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800BB980: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB984: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BB988: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800BB98C: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800BB990: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x800BB994: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x800BB998: bc1f        L_800BB9AC
    if (!c1cs) {
        // 0x800BB99C: nop
    
            goto L_800BB9AC;
    }
    // 0x800BB99C: nop

    // 0x800BB9A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BB9A4: b           L_800BB9D8
    // 0x800BB9A8: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
        goto L_800BB9D8;
    // 0x800BB9A8: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
L_800BB9AC:
    // 0x800BB9AC: lwc1        $f0, -0x599C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800BB9B0: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BB9B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB9B8: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x800BB9BC: nop

    // 0x800BB9C0: bc1f        L_800BB9D8
    if (!c1cs) {
        // 0x800BB9C4: nop
    
            goto L_800BB9D8;
    }
    // 0x800BB9C4: nop

    // 0x800BB9C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BB9CC: nop

    // 0x800BB9D0: sub.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800BB9D4: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
L_800BB9D8:
    // 0x800BB9D8: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BB9DC: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BB9E0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800BB9E4: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BB9E8: lw          $v1, 0x4($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X4);
    // 0x800BB9EC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BB9F0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800BB9F4: nop

    // 0x800BB9F8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800BB9FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BBA00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BBA04: nop

    // 0x800BBA08: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BBA0C: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BBA10: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800BBA14: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800BBA18: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BBA1C: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x800BBA20: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800BBA24: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BBA28: nop

    // 0x800BBA2C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BBA30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BBA34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BBA38: nop

    // 0x800BBA3C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BBA40: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800BBA44: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BBA48: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BBA4C: sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    // 0x800BBA50: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBA54: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBA58: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BBA5C: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800BBA60: nop

    // 0x800BBA64: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800BBA68: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800BBA6C: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x800BBA70: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BBA74: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800BBA78: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800BBA7C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BBA80: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x800BBA84: lh          $t9, 0x12($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X12);
    // 0x800BBA88: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BBA8C: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800BBA90: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBA94: bne         $at, $zero, L_800BBAAC
    if (ctx->r1 != 0) {
        // 0x800BBA98: nop
    
            goto L_800BBAAC;
    }
    // 0x800BBA98: nop

L_800BBA9C:
    // 0x800BBA9C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x800BBAA0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBAA4: beq         $at, $zero, L_800BBA9C
    if (ctx->r1 == 0) {
        // 0x800BBAA8: nop
    
            goto L_800BBA9C;
    }
    // 0x800BBAA8: nop

L_800BBAAC:
    // 0x800BBAAC: lh          $t7, 0x10($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X10);
    // 0x800BBAB0: addiu       $ra, $t0, 0x1
    ctx->r31 = ADD32(ctx->r8, 0X1);
    // 0x800BBAB4: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x800BBAB8: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBABC: bne         $at, $zero, L_800BBAD4
    if (ctx->r1 != 0) {
        // 0x800BBAC0: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_800BBAD4;
    }
    // 0x800BBAC0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
L_800BBAC4:
    // 0x800BBAC4: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // 0x800BBAC8: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBACC: beq         $at, $zero, L_800BBAC4
    if (ctx->r1 == 0) {
        // 0x800BBAD0: nop
    
            goto L_800BBAC4;
    }
    // 0x800BBAD0: nop

L_800BBAD4:
    // 0x800BBAD4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800BBAD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BBADC: bc1t        L_800BBB10
    if (c1cs) {
        // 0x800BBAE0: slt         $at, $ra, $v1
        ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BBB10;
    }
    // 0x800BBAE0: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBAE4: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800BBAE8: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BBAEC: div.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BBAF0: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BBAF4: nop

    // 0x800BBAF8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BBAFC: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x800BBB00: nop

    // 0x800BBB04: bc1f        L_800BBB10
    if (!c1cs) {
        // 0x800BBB08: nop
    
            goto L_800BBB10;
    }
    // 0x800BBB08: nop

    // 0x800BBB0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800BBB10:
    // 0x800BBB10: beq         $v0, $zero, L_800BBE90
    if (ctx->r2 == 0) {
        // 0x800BBB14: nop
    
            goto L_800BBE90;
    }
    // 0x800BBB14: nop

    // 0x800BBB18: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBB1C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BBB20: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BBB24: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BBB28: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BBB2C: lwc1        $f14, 0x40($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X40);
    // 0x800BBB30: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBB34: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BBB38: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBB3C: mflo        $t9
    ctx->r25 = lo;
    // 0x800BBB40: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800BBB44: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BBB48: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x800BBB4C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800BBB50: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800BBB54: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BBB58: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BBB5C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BBB60: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BBB64: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BBB68: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BBB6C: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BBB70: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800BBB74: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800BBB78: blez        $t3, L_800BBBD4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BBB7C: swc1        $f8, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
            goto L_800BBBD4;
    }
    // 0x800BBB7C: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x800BBB80: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BBB84: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800BBB88: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800BBB8C: jal         0x800BF4E4
    // 0x800BBB90: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800BBB90: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800BBB94: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBB98: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBB9C: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800BBBA0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BBBA4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BBBA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBBAC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBBB0: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BBBB4: lwc1        $f14, -0x5A38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800BBBB8: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BBBBC: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BBBC0: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BBBC4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800BBBC8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800BBBCC: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBBD0: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
L_800BBBD4:
    // 0x800BBBD4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBBD8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800BBBDC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800BBBE0: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBBE4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800BBBE8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BBBEC: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x800BBBF0: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BBBF4: addiu       $t1, $a3, 0x1
    ctx->r9 = ADD32(ctx->r7, 0X1);
    // 0x800BBBF8: mflo        $t9
    ctx->r25 = lo;
    // 0x800BBBFC: addu        $ra, $t5, $t9
    ctx->r31 = ADD32(ctx->r13, ctx->r25);
    // 0x800BBC00: addu        $t6, $t4, $ra
    ctx->r14 = ADD32(ctx->r12, ctx->r31);
    // 0x800BBC04: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x800BBC08: nop

    // 0x800BBC0C: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BBC10: beq         $at, $zero, L_800BBC40
    if (ctx->r1 == 0) {
        // 0x800BBC14: slt         $at, $t1, $v1
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BBC40;
    }
    // 0x800BBC14: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBC18: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800BBC1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBC20: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BBC24: lwc1        $f4, -0x5A34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BBC28: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BBC2C: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBC30: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800BBC34: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BBC38: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x800BBC3C: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
L_800BBC40:
    // 0x800BBC40: bne         $at, $zero, L_800BBC50
    if (ctx->r1 != 0) {
        // 0x800BBC44: nop
    
            goto L_800BBC50;
    }
    // 0x800BBC44: nop

    // 0x800BBC48: b           L_800BBC60
    // 0x800BBC4C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_800BBC60;
    // 0x800BBC4C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800BBC50:
    // 0x800BBC50: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBC54: mflo        $t7
    ctx->r15 = lo;
    // 0x800BBC58: addu        $a0, $t7, $t0
    ctx->r4 = ADD32(ctx->r15, ctx->r8);
    // 0x800BBC5C: nop

L_800BBC60:
    // 0x800BBC60: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800BBC64: addu        $v0, $t2, $t8
    ctx->r2 = ADD32(ctx->r10, ctx->r24);
    // 0x800BBC68: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800BBC6C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800BBC70: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BBC74: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800BBC78: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BBC7C: addu        $t6, $a1, $t9
    ctx->r14 = ADD32(ctx->r5, ctx->r25);
    // 0x800BBC80: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BBC84: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BBC88: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBC8C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800BBC90: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BBC94: mul.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BBC98: blez        $t3, L_800BBD0C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BBC9C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800BBD0C;
    }
    // 0x800BBC9C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BBCA0: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BBCA4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800BBCA8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800BBCAC: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800BBCB0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800BBCB4: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BBCB8: jal         0x800BF4E4
    // 0x800BBCBC: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_1;
    // 0x800BBCBC: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x800BBCC0: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BBCC4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBCC8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BBCCC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BBCD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBCD4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBCD8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BBCDC: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BBCE0: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BBCE4: lwc1        $f14, -0x5A38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800BBCE8: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BBCEC: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BBCF0: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BBCF4: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800BBCF8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800BBCFC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800BBD00: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800BBD04: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBD08: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_800BBD0C:
    // 0x800BBD0C: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBD10: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800BBD14: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BBD18: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBD1C: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800BBD20: mflo        $t6
    ctx->r14 = lo;
    // 0x800BBD24: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800BBD28: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800BBD2C: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBD30: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800BBD34: nop

    // 0x800BBD38: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BBD3C: mflo        $a2
    ctx->r6 = lo;
    // 0x800BBD40: addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    // 0x800BBD44: beq         $at, $zero, L_800BBD6C
    if (ctx->r1 == 0) {
        // 0x800BBD48: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800BBD6C;
    }
    // 0x800BBD48: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BBD4C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800BBD50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBD54: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBD58: lwc1        $f4, -0x5A34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BBD5C: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BBD60: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BBD64: mul.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800BBD68: nop

L_800BBD6C:
    // 0x800BBD6C: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBD70: bne         $at, $zero, L_800BBD80
    if (ctx->r1 != 0) {
        // 0x800BBD74: nop
    
            goto L_800BBD80;
    }
    // 0x800BBD74: nop

    // 0x800BBD78: b           L_800BBD80
    // 0x800BBD7C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_800BBD80;
    // 0x800BBD7C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_800BBD80:
    // 0x800BBD80: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BBD84: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x800BBD88: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800BBD8C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800BBD90: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BBD94: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BBD98: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BBD9C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BBDA0: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BBDA4: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BBDA8: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BBDAC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BBDB0: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BBDB4: mul.s       $f2, $f8, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BBDB8: blez        $t3, L_800BBDF4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BBDBC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800BBDF4;
    }
    // 0x800BBDBC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BBDC0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBDC4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800BBDC8: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x800BBDCC: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BBDD0: jal         0x800BF4E4
    // 0x800BBDD4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_2;
    // 0x800BBDD4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x800BBDD8: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800BBDDC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BBDE0: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BBDE4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800BBDE8: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BBDEC: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBDF0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_800BBDF4:
    // 0x800BBDF4: addu        $t9, $t4, $ra
    ctx->r25 = ADD32(ctx->r12, ctx->r31);
    // 0x800BBDF8: lbu         $v0, 0x1($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X1);
    // 0x800BBDFC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBE00: lw          $v1, -0x5A50($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A50);
    // 0x800BBE04: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BBE08: beq         $at, $zero, L_800BBE30
    if (ctx->r1 == 0) {
        // 0x800BBE0C: nop
    
            goto L_800BBE30;
    }
    // 0x800BBE0C: nop

    // 0x800BBE10: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800BBE14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBE18: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BBE1C: lwc1        $f10, -0x5A34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BBE20: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800BBE24: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800BBE28: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800BBE2C: nop

L_800BBE30:
    // 0x800BBE30: beq         $v1, $zero, L_800BBE5C
    if (ctx->r3 == 0) {
        // 0x800BBE34: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800BBE5C;
    }
    // 0x800BBE34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BBE38: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBE3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BBE40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BBE44: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BBE48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BBE4C: mul.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800BBE50: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x800BBE54: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800BBE58: nop

L_800BBE5C:
    // 0x800BBE5C: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBE60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BBE64: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BBE68: sub.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800BBE6C: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
    // 0x800BBE70: mul.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800BBE74: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BBE78: nop

    // 0x800BBE7C: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BBE80: sub.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800BBE84: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BBE88: b           L_800BC220
    // 0x800BBE8C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
        goto L_800BC220;
    // 0x800BBE8C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
L_800BBE90:
    // 0x800BBE90: bne         $at, $zero, L_800BBEA8
    if (ctx->r1 != 0) {
        // 0x800BBE94: nop
    
            goto L_800BBEA8;
    }
    // 0x800BBE94: nop

    // 0x800BBE98: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBE9C: mflo        $a0
    ctx->r4 = lo;
    // 0x800BBEA0: b           L_800BBEB8
    // 0x800BBEA4: nop

        goto L_800BBEB8;
    // 0x800BBEA4: nop

L_800BBEA8:
    // 0x800BBEA8: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBEAC: mflo        $t6
    ctx->r14 = lo;
    // 0x800BBEB0: addu        $a0, $t0, $t6
    ctx->r4 = ADD32(ctx->r8, ctx->r14);
    // 0x800BBEB4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800BBEB8:
    // 0x800BBEB8: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BBEBC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800BBEC0: addu        $v0, $t2, $t7
    ctx->r2 = ADD32(ctx->r10, ctx->r15);
    // 0x800BBEC4: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x800BBEC8: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800BBECC: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BBED0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BBED4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BBED8: addu        $t6, $a1, $t9
    ctx->r14 = ADD32(ctx->r5, ctx->r25);
    // 0x800BBEDC: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BBEE0: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BBEE4: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BBEE8: lwc1        $f14, 0x40($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X40);
    // 0x800BBEEC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BBEF0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBEF4: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800BBEF8: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BBEFC: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BBF00: blez        $t3, L_800BBF6C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BBF04: swc1        $f10, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
            goto L_800BBF6C;
    }
    // 0x800BBF04: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x800BBF08: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BBF0C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBF10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BBF14: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800BBF18: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800BBF1C: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x800BBF20: jal         0x800BF4E4
    // 0x800BBF24: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    waves_get_y(rdram, ctx);
        goto after_3;
    // 0x800BBF24: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_3:
    // 0x800BBF28: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBF2C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BBF30: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800BBF34: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BBF38: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BBF3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBF40: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BBF44: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BBF48: lwc1        $f14, -0x5A38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800BBF4C: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BBF50: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BBF54: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BBF58: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800BBF5C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800BBF60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BBF64: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BBF68: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
L_800BBF6C:
    // 0x800BBF6C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800BBF70: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800BBF74: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800BBF78: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBF7C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800BBF80: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BBF84: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x800BBF88: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BBF8C: addiu       $t1, $a3, 0x1
    ctx->r9 = ADD32(ctx->r7, 0X1);
    // 0x800BBF90: mflo        $t6
    ctx->r14 = lo;
    // 0x800BBF94: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800BBF98: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800BBF9C: lbu         $v0, 0x1($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X1);
    // 0x800BBFA0: nop

    // 0x800BBFA4: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BBFA8: beq         $at, $zero, L_800BBFD8
    if (ctx->r1 == 0) {
        // 0x800BBFAC: slt         $at, $t1, $v1
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BBFD8;
    }
    // 0x800BBFAC: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BBFB0: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800BBFB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BBFB8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BBFBC: lwc1        $f6, -0x5A34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BBFC0: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800BBFC4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BBFC8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800BBFCC: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BBFD0: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x800BBFD4: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
L_800BBFD8:
    // 0x800BBFD8: bne         $at, $zero, L_800BBFE8
    if (ctx->r1 != 0) {
        // 0x800BBFDC: nop
    
            goto L_800BBFE8;
    }
    // 0x800BBFDC: nop

    // 0x800BBFE0: b           L_800BBFF8
    // 0x800BBFE4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_800BBFF8;
    // 0x800BBFE4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800BBFE8:
    // 0x800BBFE8: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BBFEC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BBFF0: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800BBFF4: nop

L_800BBFF8:
    // 0x800BBFF8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BBFFC: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x800BC000: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800BC004: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800BC008: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BC00C: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x800BC010: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BC014: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BC018: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BC01C: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BC020: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BC024: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800BC028: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BC02C: mul.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800BC030: blez        $t3, L_800BC09C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BC034: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800BC09C;
    }
    // 0x800BC034: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BC038: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BC03C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BC040: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800BC044: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800BC048: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BC04C: jal         0x800BF4E4
    // 0x800BC050: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_4;
    // 0x800BC050: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x800BC054: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BC058: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC05C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BC060: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BC064: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC068: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BC06C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BC070: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BC074: lw          $t3, 0x3718($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3718);
    // 0x800BC078: lwc1        $f14, -0x5A38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800BC07C: lw          $t2, 0x35D4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35D4);
    // 0x800BC080: lw          $a1, 0x35D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X35D0);
    // 0x800BC084: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BC088: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800BC08C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800BC090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BC094: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BC098: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_800BC09C:
    // 0x800BC09C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800BC0A0: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800BC0A4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BC0A8: multu       $a2, $t9
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC0AC: or          $a0, $ra, $zero
    ctx->r4 = ctx->r31 | 0;
    // 0x800BC0B0: mflo        $t6
    ctx->r14 = lo;
    // 0x800BC0B4: addu        $a3, $t5, $t6
    ctx->r7 = ADD32(ctx->r13, ctx->r14);
    // 0x800BC0B8: addu        $t7, $t4, $a3
    ctx->r15 = ADD32(ctx->r12, ctx->r7);
    // 0x800BC0BC: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800BC0C0: nop

    // 0x800BC0C4: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BC0C8: beq         $at, $zero, L_800BC0F4
    if (ctx->r1 == 0) {
        // 0x800BC0CC: slt         $at, $ra, $v1
        ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BC0F4;
    }
    // 0x800BC0CC: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC0D0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800BC0D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC0D8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BC0DC: lwc1        $f6, -0x5A34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BC0E0: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800BC0E4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800BC0E8: mul.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800BC0EC: nop

    // 0x800BC0F0: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
L_800BC0F4:
    // 0x800BC0F4: bne         $at, $zero, L_800BC104
    if (ctx->r1 != 0) {
        // 0x800BC0F8: nop
    
            goto L_800BC104;
    }
    // 0x800BC0F8: nop

    // 0x800BC0FC: b           L_800BC104
    // 0x800BC100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800BC104;
    // 0x800BC100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BC104:
    // 0x800BC104: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC108: beq         $at, $zero, L_800BC124
    if (ctx->r1 == 0) {
        // 0x800BC10C: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_800BC124;
    }
    // 0x800BC10C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800BC110: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC114: mflo        $t8
    ctx->r24 = lo;
    // 0x800BC118: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800BC11C: nop

    // 0x800BC120: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
L_800BC124:
    // 0x800BC124: addu        $v0, $t2, $t9
    ctx->r2 = ADD32(ctx->r10, ctx->r25);
    // 0x800BC128: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x800BC12C: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800BC130: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BC134: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800BC138: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BC13C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800BC140: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BC144: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BC148: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800BC14C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BC150: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BC154: mul.s       $f2, $f10, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800BC158: blez        $t3, L_800BC190
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800BC15C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800BC190;
    }
    // 0x800BC15C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BC160: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800BC164: swc1        $f2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f2.u32l;
    // 0x800BC168: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x800BC16C: jal         0x800BF4E4
    // 0x800BC170: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    waves_get_y(rdram, ctx);
        goto after_5;
    // 0x800BC170: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x800BC174: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800BC178: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BC17C: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BC180: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800BC184: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BC188: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800BC18C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_800BC190:
    // 0x800BC190: addu        $t8, $t4, $a3
    ctx->r24 = ADD32(ctx->r12, ctx->r7);
    // 0x800BC194: lbu         $v0, 0x1($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X1);
    // 0x800BC198: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BC19C: lw          $v1, -0x5A50($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A50);
    // 0x800BC1A0: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BC1A4: beq         $at, $zero, L_800BC1CC
    if (ctx->r1 == 0) {
        // 0x800BC1A8: nop
    
            goto L_800BC1CC;
    }
    // 0x800BC1A8: nop

    // 0x800BC1AC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BC1B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC1B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BC1B8: lwc1        $f8, -0x5A34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BC1BC: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BC1C0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BC1C4: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800BC1C8: nop

L_800BC1CC:
    // 0x800BC1CC: beq         $v1, $zero, L_800BC1F8
    if (ctx->r3 == 0) {
        // 0x800BC1D0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800BC1F8;
    }
    // 0x800BC1D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BC1D4: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BC1D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BC1DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BC1E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BC1E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BC1E8: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800BC1EC: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x800BC1F0: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800BC1F4: nop

L_800BC1F8:
    // 0x800BC1F8: sub.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x800BC1FC: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800BC200: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BC204: mul.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800BC208: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BC20C: swc1        $f8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f8.u32l;
    // 0x800BC210: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800BC214: sub.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800BC218: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BC21C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
L_800BC220:
    // 0x800BC220: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800BC224: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    // 0x800BC228: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x800BC22C: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x800BC230: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800BC234: nop

    // 0x800BC238: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800BC23C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BC240: jal         0x800CA030
    // 0x800BC244: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x800BC244: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_6:
    // 0x800BC248: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800BC24C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800BC250: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800BC254: c.eq.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d == ctx->f4.d;
    // 0x800BC258: lwc1        $f14, 0x88($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800BC25C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800BC260: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800BC264: bc1t        L_800BC2D4
    if (c1cs) {
        // 0x800BC268: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800BC2D4;
    }
    // 0x800BC268: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800BC26C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x800BC270: c.eq.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d == ctx->f6.d;
    // 0x800BC274: nop

    // 0x800BC278: bc1t        L_800BC2D0
    if (c1cs) {
        // 0x800BC27C: nop
    
            goto L_800BC2D0;
    }
    // 0x800BC27C: nop

    // 0x800BC280: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800BC284: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BC288: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800BC28C: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BC290: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800BC294: nop

    // 0x800BC298: div.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800BC29C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800BC2A0: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800BC2A4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800BC2A8: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800BC2AC: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800BC2B0: swc1        $f2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f2.u32l;
    // 0x800BC2B4: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BC2B8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800BC2BC: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800BC2C0: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800BC2C4: div.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BC2C8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800BC2CC: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
L_800BC2D0:
    // 0x800BC2D0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800BC2D4:
    // 0x800BC2D4: lwc1        $f2, 0x84($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800BC2D8: beq         $t9, $zero, L_800BC2F0
    if (ctx->r25 == 0) {
        // 0x800BC2DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BC2F0;
    }
    // 0x800BC2DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BC2E0: swc1        $f14, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f14.u32l;
    // 0x800BC2E4: swc1        $f2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f2.u32l;
    // 0x800BC2E8: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
    // 0x800BC2EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BC2F0:
    // 0x800BC2F0: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800BC2F4: jr          $ra
    // 0x800BC2F8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800BC2F8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void racer_set_dialogue_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A42C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005A430: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A434: jr          $ra
    // 0x8005A438: sb          $t6, -0x24FD($at)
    MEM_B(-0X24FD, ctx->r1) = ctx->r14;
    return;
    // 0x8005A438: sb          $t6, -0x24FD($at)
    MEM_B(-0X24FD, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void objGetObjList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E988: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E98C: lw          $t6, -0x4C20($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C20);
    // 0x8000E990: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000E994: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000E998: lw          $t7, -0x4C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C24);
    // 0x8000E99C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E9A0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000E9A4: lw          $v0, -0x4C28($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C28);
    // 0x8000E9A8: jr          $ra
    // 0x8000E9AC: nop

    return;
    // 0x8000E9AC: nop

;}
RECOMP_FUNC void obj_loop_door(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B9C8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8003B9CC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003B9D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003B9D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003B9D8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8003B9DC: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8003B9E0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B9E4: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8003B9E8: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x8003B9EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B9F0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8003B9F4: bne         $t8, $zero, L_8003BA14
    if (ctx->r24 != 0) {
        // 0x8003B9F8: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_8003BA14;
    }
    // 0x8003B9F8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8003B9FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003BA00: lwc1        $f9, 0x66F8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X66F8);
    // 0x8003BA04: lwc1        $f8, 0x66FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X66FC);
    // 0x8003BA08: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003BA0C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003BA10: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_8003BA14:
    // 0x8003BA14: jal         0x8006ECD0
    // 0x8003BA18: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003BA18: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8003BA1C: lbu         $t3, 0x49($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X49);
    // 0x8003BA20: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8003BA24: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x8003BA28: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003BA2C: lb          $v1, 0xE($t0)
    ctx->r3 = MEM_B(ctx->r8, 0XE);
    // 0x8003BA30: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8003BA34: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x8003BA38: bltz        $v1, L_8003C1D4
    if (SIGNED(ctx->r3) < 0) {
        // 0x8003BA3C: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8003C1D4;
    }
    // 0x8003BA3C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8003BA40: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8003BA44: sllv        $t7, $t6, $v1
    ctx->r15 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x8003BA48: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8003BA4C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003BA50: nop

    // 0x8003BA54: lbu         $a0, 0x13($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X13);
    // 0x8003BA58: nop

    // 0x8003BA5C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8003BA60: lbu         $t8, 0xF($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XF);
    // 0x8003BA64: nop

    // 0x8003BA68: andi        $t3, $t8, 0x1
    ctx->r11 = ctx->r24 & 0X1;
    // 0x8003BA6C: bne         $t3, $zero, L_8003BA7C
    if (ctx->r11 != 0) {
        // 0x8003BA70: lw          $t9, 0x54($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X54);
            goto L_8003BA7C;
    }
    // 0x8003BA70: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8003BA74: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x8003BA78: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
L_8003BA7C:
    // 0x8003BA7C: nop

    // 0x8003BA80: and         $t4, $a1, $t9
    ctx->r12 = ctx->r5 & ctx->r25;
    // 0x8003BA84: bne         $t4, $zero, L_8003BBC8
    if (ctx->r12 != 0) {
        // 0x8003BA88: sw          $t4, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r12;
            goto L_8003BBC8;
    }
    // 0x8003BA88: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8003BA8C: lbu         $t6, 0x12($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X12);
    // 0x8003BA90: nop

    // 0x8003BA94: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003BA98: beq         $at, $zero, L_8003BBC8
    if (ctx->r1 == 0) {
        // 0x8003BA9C: nop
    
            goto L_8003BBC8;
    }
    // 0x8003BA9C: nop

    // 0x8003BAA0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003BAA4: nop

    // 0x8003BAA8: beq         $v1, $zero, L_8003BBC8
    if (ctx->r3 == 0) {
        // 0x8003BAAC: nop
    
            goto L_8003BBC8;
    }
    // 0x8003BAAC: nop

    // 0x8003BAB0: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8003BAB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BAB8: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x8003BABC: nop

    // 0x8003BAC0: bne         $a2, $t8, L_8003BBC8
    if (ctx->r6 != ctx->r24) {
        // 0x8003BAC4: nop
    
            goto L_8003BBC8;
    }
    // 0x8003BAC4: nop

    // 0x8003BAC8: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003BACC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BAD0: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x8003BAD4: nop

    // 0x8003BAD8: beq         $t3, $at, L_8003BBA8
    if (ctx->r11 == ctx->r1) {
        // 0x8003BADC: nop
    
            goto L_8003BBA8;
    }
    // 0x8003BADC: nop

    // 0x8003BAE0: lw          $t9, 0x5C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X5C);
    // 0x8003BAE4: nop

    // 0x8003BAE8: lw          $t4, 0x100($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X100);
    // 0x8003BAEC: nop

    // 0x8003BAF0: bne         $v1, $t4, L_8003BBA8
    if (ctx->r3 != ctx->r12) {
        // 0x8003BAF4: nop
    
            goto L_8003BBA8;
    }
    // 0x8003BAF4: nop

    // 0x8003BAF8: lb          $t5, 0x13($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X13);
    // 0x8003BAFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BB00: beq         $t5, $at, L_8003BBA4
    if (ctx->r13 == ctx->r1) {
        // 0x8003BB04: addiu       $t3, $zero, 0x12C
        ctx->r11 = ADD32(0, 0X12C);
            goto L_8003BBA4;
    }
    // 0x8003BB04: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x8003BB08: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BB0C: jal         0x800C3958
    // 0x8003BB10: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    textbox_visible(rdram, ctx);
        goto after_1;
    // 0x8003BB10: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_1:
    // 0x8003BB14: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB18: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BB1C: bne         $v0, $zero, L_8003BBA4
    if (ctx->r2 != 0) {
        // 0x8003BB20: addiu       $t3, $zero, 0x12C
        ctx->r11 = ADD32(0, 0X12C);
            goto L_8003BBA4;
    }
    // 0x8003BB20: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x8003BB24: lh          $t6, 0xC($t0)
    ctx->r14 = MEM_H(ctx->r8, 0XC);
    // 0x8003BB28: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    // 0x8003BB2C: bne         $t6, $zero, L_8003BBA4
    if (ctx->r14 != 0) {
        // 0x8003BB30: addiu       $t3, $zero, 0x12C
        ctx->r11 = ADD32(0, 0X12C);
            goto L_8003BBA4;
    }
    // 0x8003BB30: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x8003BB34: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BB38: jal         0x80000C98
    // 0x8003BB3C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    music_fade(rdram, ctx);
        goto after_2;
    // 0x8003BB3C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_2:
    // 0x8003BB40: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB44: addiu       $t7, $zero, 0x8C
    ctx->r15 = ADD32(0, 0X8C);
    // 0x8003BB48: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8003BB4C: jal         0x80000C38
    // 0x8003BB50: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_3;
    // 0x8003BB50: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    after_3:
    // 0x8003BB54: jal         0x80008140
    // 0x8003BB58: nop

    audspat_jingle_off(rdram, ctx);
        goto after_4;
    // 0x8003BB58: nop

    after_4:
    // 0x8003BB5C: jal         0x80001BC0
    // 0x8003BB60: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    music_jingle_play(rdram, ctx);
        goto after_5;
    // 0x8003BB60: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_5:
    // 0x8003BB64: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB68: nop

    // 0x8003BB6C: lbu         $a0, 0x10($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X10);
    // 0x8003BB70: jal         0x800C3698
    // 0x8003BB74: nop

    set_textbox_display_value(rdram, ctx);
        goto after_6;
    // 0x8003BB74: nop

    after_6:
    // 0x8003BB78: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB7C: nop

    // 0x8003BB80: lb          $a0, 0x13($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X13);
    // 0x8003BB84: nop

    // 0x8003BB88: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x8003BB8C: jal         0x800C3744
    // 0x8003BB90: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    set_current_text(rdram, ctx);
        goto after_7;
    // 0x8003BB90: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_7:
    // 0x8003BB94: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BB98: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BB9C: nop

    // 0x8003BBA0: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
L_8003BBA4:
    // 0x8003BBA4: sh          $t3, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r11;
L_8003BBA8:
    // 0x8003BBA8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BBAC: jal         0x800C3958
    // 0x8003BBB0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    textbox_visible(rdram, ctx);
        goto after_8;
    // 0x8003BBB0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_8:
    // 0x8003BBB4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BBB8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BBBC: beq         $v0, $zero, L_8003BBC8
    if (ctx->r2 == 0) {
        // 0x8003BBC0: addiu       $t9, $zero, 0x12C
        ctx->r25 = ADD32(0, 0X12C);
            goto L_8003BBC8;
    }
    // 0x8003BBC0: addiu       $t9, $zero, 0x12C
    ctx->r25 = ADD32(0, 0X12C);
    // 0x8003BBC4: sh          $t9, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r25;
L_8003BBC8:
    // 0x8003BBC8: lw          $t4, 0x8($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X8);
    // 0x8003BBCC: nop

    // 0x8003BBD0: beq         $t4, $zero, L_8003BC40
    if (ctx->r12 == 0) {
        // 0x8003BBD4: nop
    
            goto L_8003BC40;
    }
    // 0x8003BBD4: nop

    // 0x8003BBD8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BBDC: jal         0x80001C08
    // 0x8003BBE0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    music_jingle_playing(rdram, ctx);
        goto after_9;
    // 0x8003BBE0: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_9:
    // 0x8003BBE4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BBE8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BBEC: bne         $v0, $zero, L_8003BC40
    if (ctx->r2 != 0) {
        // 0x8003BBF0: nop
    
            goto L_8003BC40;
    }
    // 0x8003BBF0: nop

    // 0x8003BBF4: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8003BBF8: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8003BBFC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8003BC00: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003BC04: beq         $at, $zero, L_8003BC14
    if (ctx->r1 == 0) {
        // 0x8003BC08: subu        $t5, $v0, $v1
        ctx->r13 = SUB32(ctx->r2, ctx->r3);
            goto L_8003BC14;
    }
    // 0x8003BC08: subu        $t5, $v0, $v1
    ctx->r13 = SUB32(ctx->r2, ctx->r3);
    // 0x8003BC0C: b           L_8003BC40
    // 0x8003BC10: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
        goto L_8003BC40;
    // 0x8003BC10: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
L_8003BC14:
    // 0x8003BC14: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x8003BC18: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8003BC1C: jal         0x80000C98
    // 0x8003BC20: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    music_fade(rdram, ctx);
        goto after_10;
    // 0x8003BC20: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_10:
    // 0x8003BC24: jal         0x80000C38
    // 0x8003BC28: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_11;
    // 0x8003BC28: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_11:
    // 0x8003BC2C: jal         0x80008168
    // 0x8003BC30: nop

    audspat_jingle_on(rdram, ctx);
        goto after_12;
    // 0x8003BC30: nop

    after_12:
    // 0x8003BC34: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BC38: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BC3C: nop

L_8003BC40:
    // 0x8003BC40: lh          $v0, 0xC($t0)
    ctx->r2 = MEM_H(ctx->r8, 0XC);
    // 0x8003BC44: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8003BC48: blez        $v0, L_8003BC5C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003BC4C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8003BC5C;
    }
    // 0x8003BC4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BC50: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // 0x8003BC54: b           L_8003BC60
    // 0x8003BC58: sh          $t6, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r14;
        goto L_8003BC60;
    // 0x8003BC58: sh          $t6, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r14;
L_8003BC5C:
    // 0x8003BC5C: sh          $zero, 0xC($t0)
    MEM_H(0XC, ctx->r8) = 0;
L_8003BC60:
    // 0x8003BC60: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003BC64: lbu         $t8, 0x12($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X12);
    // 0x8003BC68: lbu         $t7, 0x13($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X13);
    // 0x8003BC6C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003BC70: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003BC74: beq         $at, $zero, L_8003BCD8
    if (ctx->r1 == 0) {
        // 0x8003BC78: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8003BCD8;
    }
    // 0x8003BC78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003BC7C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003BC80: nop

    // 0x8003BC84: beq         $v1, $zero, L_8003BCD8
    if (ctx->r3 == 0) {
        // 0x8003BC88: nop
    
            goto L_8003BCD8;
    }
    // 0x8003BC88: nop

    // 0x8003BC8C: lw          $t3, 0x40($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X40);
    // 0x8003BC90: nop

    // 0x8003BC94: lb          $t9, 0x54($t3)
    ctx->r25 = MEM_B(ctx->r11, 0X54);
    // 0x8003BC98: nop

    // 0x8003BC9C: bne         $a2, $t9, L_8003BCD8
    if (ctx->r6 != ctx->r25) {
        // 0x8003BCA0: nop
    
            goto L_8003BCD8;
    }
    // 0x8003BCA0: nop

    // 0x8003BCA4: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003BCA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003BCAC: lb          $a0, 0x1D6($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X1D6);
    // 0x8003BCB0: nop

    // 0x8003BCB4: beq         $a0, $a2, L_8003BCCC
    if (ctx->r4 == ctx->r6) {
        // 0x8003BCB8: nop
    
            goto L_8003BCCC;
    }
    // 0x8003BCB8: nop

    // 0x8003BCBC: beq         $a0, $at, L_8003BCD8
    if (ctx->r4 == ctx->r1) {
        // 0x8003BCC0: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_8003BCD8;
    }
    // 0x8003BCC0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8003BCC4: b           L_8003BCD8
    // 0x8003BCC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_8003BCD8;
    // 0x8003BCC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_8003BCCC:
    // 0x8003BCCC: b           L_8003BCD8
    // 0x8003BCD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8003BCD8;
    // 0x8003BCD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8003BCD4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8003BCD8:
    // 0x8003BCD8: lbu         $t4, 0x10($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X10);
    // 0x8003BCDC: lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X0);
    // 0x8003BCE0: addiu       $at, $zero, 0x87
    ctx->r1 = ADD32(0, 0X87);
    // 0x8003BCE4: beq         $v0, $at, L_8003BCF8
    if (ctx->r2 == ctx->r1) {
        // 0x8003BCE8: and         $a0, $a0, $t4
        ctx->r4 = ctx->r4 & ctx->r12;
            goto L_8003BCF8;
    }
    // 0x8003BCE8: and         $a0, $a0, $t4
    ctx->r4 = ctx->r4 & ctx->r12;
    // 0x8003BCEC: addiu       $at, $zero, 0xD7
    ctx->r1 = ADD32(0, 0XD7);
    // 0x8003BCF0: bne         $v0, $at, L_8003BD20
    if (ctx->r2 != ctx->r1) {
        // 0x8003BCF4: nop
    
            goto L_8003BD20;
    }
    // 0x8003BCF4: nop

L_8003BCF8:
    // 0x8003BCF8: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x8003BCFC: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003BD00: jal         0x800235F4
    // 0x8003BD04: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    obj_door_override(rdram, ctx);
        goto after_13;
    // 0x8003BD04: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_13:
    // 0x8003BD08: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8003BD0C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003BD10: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003BD14: beq         $v0, $zero, L_8003BD20
    if (ctx->r2 == 0) {
        // 0x8003BD18: nop
    
            goto L_8003BD20;
    }
    // 0x8003BD18: nop

    // 0x8003BD1C: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_8003BD20:
    // 0x8003BD20: lb          $t5, 0x15($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X15);
    // 0x8003BD24: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003BD28: bne         $t5, $zero, L_8003BD74
    if (ctx->r13 != 0) {
        // 0x8003BD2C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8003BD74;
    }
    // 0x8003BD2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003BD30: lbu         $v0, 0x12($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X12);
    // 0x8003BD34: bne         $a0, $zero, L_8003BD60
    if (ctx->r4 != 0) {
        // 0x8003BD38: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_8003BD60;
    }
    // 0x8003BD38: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8003BD3C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003BD40: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8003BD44: beq         $t6, $zero, L_8003BD5C
    if (ctx->r14 == 0) {
        // 0x8003BD48: slt         $at, $t7, $v0
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8003BD5C;
    }
    // 0x8003BD48: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003BD4C: beq         $at, $zero, L_8003BD60
    if (ctx->r1 == 0) {
        // 0x8003BD50: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_8003BD60;
    }
    // 0x8003BD50: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8003BD54: b           L_8003BD74
    // 0x8003BD58: sb          $a2, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r6;
        goto L_8003BD74;
    // 0x8003BD58: sb          $a2, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r6;
L_8003BD5C:
    // 0x8003BD5C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
L_8003BD60:
    // 0x8003BD60: addiu       $t3, $v0, 0xA
    ctx->r11 = ADD32(ctx->r2, 0XA);
    // 0x8003BD64: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003BD68: beq         $at, $zero, L_8003BD74
    if (ctx->r1 == 0) {
        // 0x8003BD6C: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_8003BD74;
    }
    // 0x8003BD6C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8003BD70: sb          $t9, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r25;
L_8003BD74:
    // 0x8003BD74: lbu         $t4, 0xF($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XF);
    // 0x8003BD78: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003BD7C: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8003BD80: beq         $t5, $zero, L_8003BEFC
    if (ctx->r13 == 0) {
        // 0x8003BD84: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003BEFC;
    }
    // 0x8003BD84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003BD88: beq         $t6, $zero, L_8003BE58
    if (ctx->r14 == 0) {
        // 0x8003BD8C: nop
    
            goto L_8003BE58;
    }
    // 0x8003BD8C: nop

    // 0x8003BD90: lbu         $t7, 0x0($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X0);
    // 0x8003BD94: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8003BD98: bne         $t7, $at, L_8003BE58
    if (ctx->r15 != ctx->r1) {
        // 0x8003BD9C: nop
    
            goto L_8003BE58;
    }
    // 0x8003BD9C: nop

    // 0x8003BDA0: lb          $t3, 0x14($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X14);
    // 0x8003BDA4: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    // 0x8003BDA8: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8003BDAC: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x8003BDB0: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8003BDB4: nop

    // 0x8003BDB8: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x8003BDBC: beq         $t5, $zero, L_8003BE4C
    if (ctx->r13 == 0) {
        // 0x8003BDC0: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_8003BE4C;
    }
    // 0x8003BDC0: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x8003BDC4: lbu         $v0, 0x48($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BDC8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003BDCC: beq         $v0, $at, L_8003BDE8
    if (ctx->r2 == ctx->r1) {
        // 0x8003BDD0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003BDE8;
    }
    // 0x8003BDD0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003BDD4: lhu         $t6, 0xC($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0XC);
    // 0x8003BDD8: sllv        $t3, $t7, $v0
    ctx->r11 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x8003BDDC: and         $t8, $t6, $t3
    ctx->r24 = ctx->r14 & ctx->r11;
    // 0x8003BDE0: beq         $t8, $zero, L_8003BE2C
    if (ctx->r24 == 0) {
        // 0x8003BDE4: nop
    
            goto L_8003BE2C;
    }
    // 0x8003BDE4: nop

L_8003BDE8:
    // 0x8003BDE8: lbu         $t9, 0x15($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X15);
    // 0x8003BDEC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003BDF0: andi        $t4, $t9, 0xFF
    ctx->r12 = ctx->r25 & 0XFF;
    // 0x8003BDF4: slti        $at, $t4, 0xA
    ctx->r1 = SIGNED(ctx->r12) < 0XA ? 1 : 0;
    // 0x8003BDF8: bne         $at, $zero, L_8003BE0C
    if (ctx->r1 != 0) {
        // 0x8003BDFC: sb          $t9, 0x10($t0)
        MEM_B(0X10, ctx->r8) = ctx->r25;
            goto L_8003BE0C;
    }
    // 0x8003BDFC: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003BE00: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8003BE04: b           L_8003BE10
    // 0x8003BE08: sb          $t5, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r13;
        goto L_8003BE10;
    // 0x8003BE08: sb          $t5, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r13;
L_8003BE0C:
    // 0x8003BE0C: sb          $t7, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r15;
L_8003BE10:
    // 0x8003BE10: lb          $t3, 0x14($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X14);
    // 0x8003BE14: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x8003BE18: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8003BE1C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8003BE20: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8003BE24: b           L_8003BE4C
    // 0x8003BE28: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
        goto L_8003BE4C;
    // 0x8003BE28: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
L_8003BE2C:
    // 0x8003BE2C: sb          $zero, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = 0;
    // 0x8003BE30: lb          $t5, 0x14($t2)
    ctx->r13 = MEM_B(ctx->r10, 0X14);
    // 0x8003BE34: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x8003BE38: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8003BE3C: addu        $t3, $t4, $t7
    ctx->r11 = ADD32(ctx->r12, ctx->r15);
    // 0x8003BE40: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8003BE44: nop

    // 0x8003BE48: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
L_8003BE4C:
    // 0x8003BE4C: beq         $t6, $zero, L_8003BE58
    if (ctx->r14 == 0) {
        // 0x8003BE50: nop
    
            goto L_8003BE58;
    }
    // 0x8003BE50: nop

    // 0x8003BE54: sb          $a2, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r6;
L_8003BE58:
    // 0x8003BE58: lb          $v1, 0x15($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X15);
    // 0x8003BE5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BE60: bne         $a2, $v1, L_8003BEB8
    if (ctx->r6 != ctx->r3) {
        // 0x8003BE64: nop
    
            goto L_8003BEB8;
    }
    // 0x8003BE64: nop

    // 0x8003BE68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003BE6C: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8003BE70: lwc1        $f7, 0x6700($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6700);
    // 0x8003BE74: lwc1        $f6, 0x6704($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6704);
    // 0x8003BE78: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003BE7C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8003BE80: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8003BE84: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003BE88: cvt.d.s     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.d = CVT_D_S(ctx->f16.fl);
    // 0x8003BE8C: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8003BE90: nop

    // 0x8003BE94: bc1f        L_8003C028
    if (!c1cs) {
        // 0x8003BE98: nop
    
            goto L_8003C028;
    }
    // 0x8003BE98: nop

    // 0x8003BE9C: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8003BEA0: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x8003BEA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003BEA8: add.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f2.d + ctx->f16.d;
    // 0x8003BEAC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8003BEB0: b           L_8003C028
    // 0x8003BEB4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
        goto L_8003C028;
    // 0x8003BEB4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_8003BEB8:
    // 0x8003BEB8: bne         $v1, $at, L_8003C028
    if (ctx->r3 != ctx->r1) {
        // 0x8003BEBC: nop
    
            goto L_8003C028;
    }
    // 0x8003BEBC: nop

    // 0x8003BEC0: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003BEC4: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8003BEC8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003BECC: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8003BED0: nop

    // 0x8003BED4: bc1f        L_8003C028
    if (!c1cs) {
        // 0x8003BED8: nop
    
            goto L_8003C028;
    }
    // 0x8003BED8: nop

    // 0x8003BEDC: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8003BEE0: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x8003BEE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003BEE8: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8003BEEC: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x8003BEF0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8003BEF4: b           L_8003C028
    // 0x8003BEF8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
        goto L_8003C028;
    // 0x8003BEF8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_8003BEFC:
    // 0x8003BEFC: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x8003BF00: addiu       $at, $zero, 0xD7
    ctx->r1 = ADD32(0, 0XD7);
    // 0x8003BF04: bne         $t8, $at, L_8003BF9C
    if (ctx->r24 != ctx->r1) {
        // 0x8003BF08: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8003BF9C;
    }
    // 0x8003BF08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003BF0C: sb          $zero, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = 0;
    // 0x8003BF10: lbu         $a0, 0x48($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BF14: lhu         $v1, 0xC($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XC);
    // 0x8003BF18: sllv        $t5, $t9, $a0
    ctx->r13 = S32(ctx->r25 << (ctx->r4 & 31));
    // 0x8003BF1C: and         $t4, $v1, $t5
    ctx->r12 = ctx->r3 & ctx->r13;
    // 0x8003BF20: beq         $t4, $zero, L_8003BF54
    if (ctx->r12 == 0) {
        // 0x8003BF24: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8003BF54;
    }
    // 0x8003BF24: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8003BF28: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8003BF2C: sll         $t3, $a0, 1
    ctx->r11 = S32(ctx->r4 << 1);
    // 0x8003BF30: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x8003BF34: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8003BF38: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003BF3C: bne         $t8, $at, L_8003BF58
    if (ctx->r24 != ctx->r1) {
        // 0x8003BF40: addiu       $t9, $v0, 0x6
        ctx->r25 = ADD32(ctx->r2, 0X6);
            goto L_8003BF58;
    }
    // 0x8003BF40: addiu       $t9, $v0, 0x6
    ctx->r25 = ADD32(ctx->r2, 0X6);
    // 0x8003BF44: sb          $a2, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r6;
    // 0x8003BF48: lhu         $v1, 0xC($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XC);
    // 0x8003BF4C: lbu         $v0, 0x48($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BF50: nop

L_8003BF54:
    // 0x8003BF54: addiu       $t9, $v0, 0x6
    ctx->r25 = ADD32(ctx->r2, 0X6);
L_8003BF58:
    // 0x8003BF58: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003BF5C: sllv        $t4, $t5, $t9
    ctx->r12 = S32(ctx->r13 << (ctx->r25 & 31));
    // 0x8003BF60: and         $t7, $v1, $t4
    ctx->r15 = ctx->r3 & ctx->r12;
    // 0x8003BF64: beq         $t7, $zero, L_8003BF7C
    if (ctx->r15 == 0) {
        // 0x8003BF68: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8003BF7C;
    }
    // 0x8003BF68: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003BF6C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003BF70: sb          $t3, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r11;
    // 0x8003BF74: lbu         $v0, 0x48($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X48);
    // 0x8003BF78: nop

L_8003BF7C:
    // 0x8003BF7C: bne         $v0, $at, L_8003BF9C
    if (ctx->r2 != ctx->r1) {
        // 0x8003BF80: nop
    
            goto L_8003BF9C;
    }
    // 0x8003BF80: nop

    // 0x8003BF84: lb          $v0, 0x3A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X3A);
    // 0x8003BF88: nop

    // 0x8003BF8C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8003BF90: beq         $at, $zero, L_8003BF9C
    if (ctx->r1 == 0) {
        // 0x8003BF94: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8003BF9C;
    }
    // 0x8003BF94: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8003BF98: sb          $t6, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r14;
L_8003BF9C:
    // 0x8003BF9C: lb          $v1, 0x15($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X15);
    // 0x8003BFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003BFA4: bne         $a2, $v1, L_8003BFC8
    if (ctx->r6 != ctx->r3) {
        // 0x8003BFA8: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8003BFC8;
    }
    // 0x8003BFA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003BFAC: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8003BFB0: lw          $t5, 0x7C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X7C);
    // 0x8003BFB4: nop

    // 0x8003BFB8: subu        $v0, $t8, $t5
    ctx->r2 = SUB32(ctx->r24, ctx->r13);
    // 0x8003BFBC: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8003BFC0: b           L_8003BFE8
    // 0x8003BFC4: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
        goto L_8003BFE8;
    // 0x8003BFC4: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
L_8003BFC8:
    // 0x8003BFC8: bne         $v1, $at, L_8003BFEC
    if (ctx->r3 != ctx->r1) {
        // 0x8003BFCC: sra         $t5, $v0, 3
        ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8003BFEC;
    }
    // 0x8003BFCC: sra         $t5, $v0, 3
    ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8003BFD0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8003BFD4: lw          $t3, 0x78($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X78);
    // 0x8003BFD8: nop

    // 0x8003BFDC: subu        $v0, $t7, $t3
    ctx->r2 = SUB32(ctx->r15, ctx->r11);
    // 0x8003BFE0: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x8003BFE4: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
L_8003BFE8:
    // 0x8003BFE8: sra         $t5, $v0, 3
    ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
L_8003BFEC:
    // 0x8003BFEC: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8003BFF0: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8003BFF4: slti        $at, $v0, 0x201
    ctx->r1 = SIGNED(ctx->r2) < 0X201 ? 1 : 0;
    // 0x8003BFF8: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8003BFFC: bne         $at, $zero, L_8003C00C
    if (ctx->r1 != 0) {
        // 0x8003C000: slti        $at, $v0, -0x200
        ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
            goto L_8003C00C;
    }
    // 0x8003C000: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
    // 0x8003C004: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8003C008: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
L_8003C00C:
    // 0x8003C00C: beq         $at, $zero, L_8003C01C
    if (ctx->r1 == 0) {
        // 0x8003C010: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_8003C01C;
    }
    // 0x8003C010: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x8003C014: addiu       $v0, $zero, -0x200
    ctx->r2 = ADD32(0, -0X200);
    // 0x8003C018: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
L_8003C01C:
    // 0x8003C01C: beq         $v0, $zero, L_8003C028
    if (ctx->r2 == 0) {
        // 0x8003C020: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_8003C028;
    }
    // 0x8003C020: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x8003C024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8003C028:
    // 0x8003C028: beq         $a1, $zero, L_8003C078
    if (ctx->r5 == 0) {
        // 0x8003C02C: nop
    
            goto L_8003C078;
    }
    // 0x8003C02C: nop

    // 0x8003C030: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8003C034: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    // 0x8003C038: bne         $t3, $zero, L_8003C0A8
    if (ctx->r11 != 0) {
        // 0x8003C03C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8003C0A8;
    }
    // 0x8003C03C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003C040: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003C044: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003C048: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003C04C: addiu       $t8, $t0, 0x4
    ctx->r24 = ADD32(ctx->r8, 0X4);
    // 0x8003C050: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003C054: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8003C058: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003C05C: jal         0x80009558
    // 0x8003C060: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_14;
    // 0x8003C060: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_14:
    // 0x8003C064: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003C068: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003C06C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003C070: b           L_8003C0AC
    // 0x8003C074: lb          $v0, 0x14($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X14);
        goto L_8003C0AC;
    // 0x8003C074: lb          $v0, 0x14($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X14);
L_8003C078:
    // 0x8003C078: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x8003C07C: sb          $zero, 0x15($t0)
    MEM_B(0X15, ctx->r8) = 0;
    // 0x8003C080: beq         $v0, $zero, L_8003C0A8
    if (ctx->r2 == 0) {
        // 0x8003C084: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003C0A8;
    }
    // 0x8003C084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003C088: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8003C08C: jal         0x800096F8
    // 0x8003C090: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    audspat_point_stop(rdram, ctx);
        goto after_15;
    // 0x8003C090: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_15:
    // 0x8003C094: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8003C098: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003C09C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8003C0A0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003C0A4: nop

L_8003C0A8:
    // 0x8003C0A8: lb          $v0, 0x14($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X14);
L_8003C0AC:
    // 0x8003C0AC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003C0B0: bltz        $v0, L_8003C0F4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8003C0B4: nop
    
            goto L_8003C0F4;
    }
    // 0x8003C0B4: nop

    // 0x8003C0B8: lhu         $t9, 0x8($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X8);
    // 0x8003C0BC: sllv        $a0, $t5, $v0
    ctx->r4 = S32(ctx->r13 << (ctx->r2 & 31));
    // 0x8003C0C0: and         $t4, $t9, $a0
    ctx->r12 = ctx->r25 & ctx->r4;
    // 0x8003C0C4: beq         $t4, $zero, L_8003C1D4
    if (ctx->r12 == 0) {
        // 0x8003C0C8: nop
    
            goto L_8003C1D4;
    }
    // 0x8003C0C8: nop

    // 0x8003C0CC: lbu         $t3, 0x49($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C0D0: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8003C0D4: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8003C0D8: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x8003C0DC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003C0E0: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003C0E4: nop

    // 0x8003C0E8: or          $t9, $t8, $t5
    ctx->r25 = ctx->r24 | ctx->r13;
    // 0x8003C0EC: b           L_8003C1D4
    // 0x8003C0F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_8003C1D4;
    // 0x8003C0F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8003C0F4:
    // 0x8003C0F4: lb          $t4, 0x13($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X13);
    // 0x8003C0F8: lw          $v1, 0x4($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X4);
    // 0x8003C0FC: bne         $t4, $zero, L_8003C168
    if (ctx->r12 != 0) {
        // 0x8003C100: nop
    
            goto L_8003C168;
    }
    // 0x8003C100: nop

    // 0x8003C104: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8003C108: lbu         $t6, 0x10($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X10);
    // 0x8003C10C: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x8003C110: nop

    // 0x8003C114: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003C118: bne         $at, $zero, L_8003C144
    if (ctx->r1 != 0) {
        // 0x8003C11C: nop
    
            goto L_8003C144;
    }
    // 0x8003C11C: nop

    // 0x8003C120: lbu         $t8, 0x49($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C124: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8003C128: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8003C12C: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x8003C130: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8003C134: nop

    // 0x8003C138: or          $t3, $t9, $t4
    ctx->r11 = ctx->r25 | ctx->r12;
    // 0x8003C13C: b           L_8003C1D4
    // 0x8003C140: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8003C1D4;
    // 0x8003C140: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8003C144:
    // 0x8003C144: lbu         $t7, 0x49($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C148: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8003C14C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8003C150: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x8003C154: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003C158: nor         $t9, $t5, $zero
    ctx->r25 = ~(ctx->r13 | 0);
    // 0x8003C15C: and         $t4, $t8, $t9
    ctx->r12 = ctx->r24 & ctx->r25;
    // 0x8003C160: b           L_8003C1D4
    // 0x8003C164: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8003C1D4;
    // 0x8003C164: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8003C168:
    // 0x8003C168: lbu         $t7, 0x48($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X48);
    // 0x8003C16C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8003C170: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8003C174: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x8003C178: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x8003C17C: lbu         $t9, 0x10($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X10);
    // 0x8003C180: nop

    // 0x8003C184: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003C188: bne         $at, $zero, L_8003C1B4
    if (ctx->r1 != 0) {
        // 0x8003C18C: nop
    
            goto L_8003C1B4;
    }
    // 0x8003C18C: nop

    // 0x8003C190: lbu         $t4, 0x49($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C194: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8003C198: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8003C19C: addu        $v0, $v1, $t7
    ctx->r2 = ADD32(ctx->r3, ctx->r15);
    // 0x8003C1A0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8003C1A4: nop

    // 0x8003C1A8: or          $t5, $t3, $t6
    ctx->r13 = ctx->r11 | ctx->r14;
    // 0x8003C1AC: b           L_8003C1D4
    // 0x8003C1B0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_8003C1D4;
    // 0x8003C1B0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8003C1B4:
    // 0x8003C1B4: lbu         $t8, 0x49($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X49);
    // 0x8003C1B8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8003C1BC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003C1C0: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x8003C1C4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8003C1C8: nor         $t3, $t7, $zero
    ctx->r11 = ~(ctx->r15 | 0);
    // 0x8003C1CC: and         $t6, $t4, $t3
    ctx->r14 = ctx->r12 & ctx->r11;
    // 0x8003C1D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8003C1D4:
    // 0x8003C1D4: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C1D8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8003C1DC: sb          $t5, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r13;
    // 0x8003C1E0: lw          $t9, 0x4C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C1E4: nop

    // 0x8003C1E8: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8003C1EC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C1F0: nop

    // 0x8003C1F4: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
    // 0x8003C1F8: nop

    // 0x8003C1FC: andi        $t4, $t7, 0xFFF7
    ctx->r12 = ctx->r15 & 0XFFF7;
    // 0x8003C200: sh          $t4, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r12;
    // 0x8003C204: lw          $t3, 0x5C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X5C);
    // 0x8003C208: nop

    // 0x8003C20C: sw          $zero, 0x100($t3)
    MEM_W(0X100, ctx->r11) = 0;
    // 0x8003C210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003C214: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003C218: jr          $ra
    // 0x8003C21C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8003C21C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void weather_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB8BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB8C0: lw          $a0, 0x2E9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2E9C);
    // 0x800AB8C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AB8C8: beq         $a0, $zero, L_800AB8E0
    if (ctx->r4 == 0) {
        // 0x800AB8CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AB8E0;
    }
    // 0x800AB8CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AB8D0: jal         0x80071380
    // 0x800AB8D4: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AB8D4: nop

    after_0:
    // 0x800AB8D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB8DC: sw          $zero, 0x2E9C($at)
    MEM_W(0X2E9C, ctx->r1) = 0;
L_800AB8E0:
    // 0x800AB8E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB8E4: addiu       $v0, $v0, 0x2EA4
    ctx->r2 = ADD32(ctx->r2, 0X2EA4);
    // 0x800AB8E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800AB8EC: nop

    // 0x800AB8F0: beq         $a0, $zero, L_800AB90C
    if (ctx->r4 == 0) {
        // 0x800AB8F4: nop
    
            goto L_800AB90C;
    }
    // 0x800AB8F4: nop

    // 0x800AB8F8: jal         0x80071380
    // 0x800AB8FC: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AB8FC: nop

    after_1:
    // 0x800AB900: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB904: addiu       $v0, $v0, 0x2EA4
    ctx->r2 = ADD32(ctx->r2, 0X2EA4);
    // 0x800AB908: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800AB90C:
    // 0x800AB90C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800AB910: nop

    // 0x800AB914: beq         $a0, $zero, L_800AB930
    if (ctx->r4 == 0) {
        // 0x800AB918: nop
    
            goto L_800AB930;
    }
    // 0x800AB918: nop

    // 0x800AB91C: jal         0x80071380
    // 0x800AB920: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800AB920: nop

    after_2:
    // 0x800AB924: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB928: addiu       $v0, $v0, 0x2EA4
    ctx->r2 = ADD32(ctx->r2, 0X2EA4);
    // 0x800AB92C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_800AB930:
    // 0x800AB930: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB934: lw          $a0, 0x2E64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2E64);
    // 0x800AB938: nop

    // 0x800AB93C: beq         $a0, $zero, L_800AB954
    if (ctx->r4 == 0) {
        // 0x800AB940: nop
    
            goto L_800AB954;
    }
    // 0x800AB940: nop

    // 0x800AB944: jal         0x80071380
    // 0x800AB948: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800AB948: nop

    after_3:
    // 0x800AB94C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB950: sw          $zero, 0x2E64($at)
    MEM_W(0X2E64, ctx->r1) = 0;
L_800AB954:
    // 0x800AB954: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB958: addiu       $v0, $v0, 0x2E68
    ctx->r2 = ADD32(ctx->r2, 0X2E68);
    // 0x800AB95C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800AB960: nop

    // 0x800AB964: beq         $a0, $zero, L_800AB980
    if (ctx->r4 == 0) {
        // 0x800AB968: nop
    
            goto L_800AB980;
    }
    // 0x800AB968: nop

    // 0x800AB96C: jal         0x80071380
    // 0x800AB970: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800AB970: nop

    after_4:
    // 0x800AB974: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB978: addiu       $v0, $v0, 0x2E68
    ctx->r2 = ADD32(ctx->r2, 0X2E68);
    // 0x800AB97C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800AB980:
    // 0x800AB980: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x800AB984: nop

    // 0x800AB988: beq         $a0, $zero, L_800AB9A4
    if (ctx->r4 == 0) {
        // 0x800AB98C: nop
    
            goto L_800AB9A4;
    }
    // 0x800AB98C: nop

    // 0x800AB990: jal         0x8007B70C
    // 0x800AB994: nop

    tex_free(rdram, ctx);
        goto after_5;
    // 0x800AB994: nop

    after_5:
    // 0x800AB998: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AB99C: addiu       $v0, $v0, 0x2E68
    ctx->r2 = ADD32(ctx->r2, 0X2E68);
    // 0x800AB9A0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
L_800AB9A4:
    // 0x800AB9A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AB9A8: lw          $a0, 0x2EA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2EA0);
    // 0x800AB9AC: nop

    // 0x800AB9B0: beq         $a0, $zero, L_800AB9C8
    if (ctx->r4 == 0) {
        // 0x800AB9B4: nop
    
            goto L_800AB9C8;
    }
    // 0x800AB9B4: nop

    // 0x800AB9B8: jal         0x80071380
    // 0x800AB9BC: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800AB9BC: nop

    after_6:
    // 0x800AB9C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB9C4: sw          $zero, 0x2EA0($at)
    MEM_W(0X2EA0, ctx->r1) = 0;
L_800AB9C8:
    // 0x800AB9C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB9CC: sw          $zero, 0x3018($at)
    MEM_W(0X3018, ctx->r1) = 0;
    // 0x800AB9D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB9D4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AB9D8: lw          $t7, 0x31EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31EC);
    // 0x800AB9DC: sw          $zero, 0x3010($at)
    MEM_W(0X3010, ctx->r1) = 0;
    // 0x800AB9E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB9E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AB9E8: beq         $t7, $zero, L_800AB9F8
    if (ctx->r15 == 0) {
        // 0x800AB9EC: sw          $t6, 0x3014($at)
        MEM_W(0X3014, ctx->r1) = ctx->r14;
            goto L_800AB9F8;
    }
    // 0x800AB9EC: sw          $t6, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = ctx->r14;
    // 0x800AB9F0: jal         0x800AD780
    // 0x800AB9F4: nop

    free_rain_memory(rdram, ctx);
        goto after_7;
    // 0x800AB9F4: nop

    after_7:
L_800AB9F8:
    // 0x800AB9F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AB9FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ABA00: jr          $ra
    // 0x800ABA04: nop

    return;
    // 0x800ABA04: nop

;}
RECOMP_FUNC void mempool_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071380: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80071384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071388: jal         0x8006F750
    // 0x8007138C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x8007138C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80071390: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071394: lw          $t6, 0x434C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X434C);
    // 0x80071398: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007139C: bne         $t6, $zero, L_800713B4
    if (ctx->r14 != 0) {
        // 0x800713A0: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_800713B4;
    }
    // 0x800713A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800713A4: jal         0x800714B8
    // 0x800713A8: nop

    mempool_free_addr(rdram, ctx);
        goto after_1;
    // 0x800713A8: nop

    after_1:
    // 0x800713AC: b           L_800713C0
    // 0x800713B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_800713C0;
    // 0x800713B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800713B4:
    // 0x800713B4: jal         0x80071680
    // 0x800713B8: nop

    mempool_free_queue(rdram, ctx);
        goto after_2;
    // 0x800713B8: nop

    after_2:
    // 0x800713BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800713C0:
    // 0x800713C0: jal         0x8006F77C
    // 0x800713C4: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x800713C4: nop

    after_3:
    // 0x800713C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800713CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800713D0: jr          $ra
    // 0x800713D4: nop

    return;
    // 0x800713D4: nop

;}
RECOMP_FUNC void hud_eggs_portrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1EE4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A1EE8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A1EEC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A1EF0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A1EF4: addiu       $s2, $s2, 0x729C
    ctx->r18 = ADD32(ctx->r18, 0X729C);
    // 0x800A1EF8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A1EFC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A1F00: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A1F04: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800A1F08: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800A1F0C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800A1F10: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800A1F14: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A1F18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A1F1C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A1F20: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A1F24: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800A1F28: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1F2C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1F30: lwc1        $f4, 0x66C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A1F34: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1F38: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1F3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A1F40: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A1F44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A1F48: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x800A1F4C: lb          $t8, 0x3($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X3);
    // 0x800A1F50: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A1F54: addiu       $t9, $t8, 0x38
    ctx->r25 = ADD32(ctx->r24, 0X38);
    // 0x800A1F58: sh          $t9, 0x646($v0)
    MEM_H(0X646, ctx->r2) = ctx->r25;
    // 0x800A1F5C: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A1F60: sb          $t0, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = ctx->r8;
    // 0x800A1F64: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A1F68: bne         $at, $zero, L_800A1F8C
    if (ctx->r1 != 0) {
        // 0x800A1F6C: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_800A1F8C;
    }
    // 0x800A1F6C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800A1F70: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800A1F74: bne         $s1, $v1, L_800A1FB4
    if (ctx->r17 != ctx->r3) {
        // 0x800A1F78: nop
    
            goto L_800A1FB4;
    }
    // 0x800A1F78: nop

    // 0x800A1F7C: lh          $t1, 0x0($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X0);
    // 0x800A1F80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A1F84: bne         $t1, $at, L_800A1FB4
    if (ctx->r9 != ctx->r1) {
        // 0x800A1F88: nop
    
            goto L_800A1FB4;
    }
    // 0x800A1F88: nop

L_800A1F8C:
    // 0x800A1F8C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A1F90: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A1F94: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A1F98: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800A1F9C: addiu       $a2, $s6, 0x72C4
    ctx->r6 = ADD32(ctx->r22, 0X72C4);
    // 0x800A1FA0: addiu       $a1, $s5, 0x72C0
    ctx->r5 = ADD32(ctx->r21, 0X72C0);
    // 0x800A1FA4: addiu       $a0, $s4, 0x72BC
    ctx->r4 = ADD32(ctx->r20, 0X72BC);
    // 0x800A1FA8: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800A1FAC: jal         0x800AAB5C
    // 0x800A1FB0: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A1FB0: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_0:
L_800A1FB4:
    // 0x800A1FB4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A1FB8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A1FBC: lb          $v0, 0x67A($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X67A);
    // 0x800A1FC0: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A1FC4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800A1FC8: addiu       $s6, $s6, 0x72C4
    ctx->r22 = ADD32(ctx->r22, 0X72C4);
    // 0x800A1FCC: addiu       $s5, $s5, 0x72C0
    ctx->r21 = ADD32(ctx->r21, 0X72C0);
    // 0x800A1FD0: bgez        $v0, L_800A1FE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A1FD4: addiu       $s4, $s4, 0x72BC
        ctx->r20 = ADD32(ctx->r20, 0X72BC);
            goto L_800A1FE8;
    }
    // 0x800A1FD4: addiu       $s4, $s4, 0x72BC
    ctx->r20 = ADD32(ctx->r20, 0X72BC);
    // 0x800A1FD8: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x800A1FDC: addiu       $t4, $t3, 0x100
    ctx->r12 = ADD32(ctx->r11, 0X100);
    // 0x800A1FE0: b           L_800A1FF8
    // 0x800A1FE4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_800A1FF8;
    // 0x800A1FE4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_800A1FE8:
    // 0x800A1FE8: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x800A1FEC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800A1FF0: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x800A1FF4: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_800A1FF8:
    // 0x800A1FF8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800A1FFC: addiu       $t9, $zero, 0xFE
    ctx->r25 = ADD32(0, 0XFE);
    // 0x800A2000: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x800A2004: bne         $at, $zero, L_800A2010
    if (ctx->r1 != 0) {
        // 0x800A2008: nop
    
            goto L_800A2010;
    }
    // 0x800A2008: nop

    // 0x800A200C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_800A2010:
    // 0x800A2010: lb          $t0, 0x193($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X193);
    // 0x800A2014: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A2018: blez        $t0, L_800A2074
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800A201C: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_800A2074;
    }
    // 0x800A201C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800A2020: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A2024: nop

L_800A2028:
    // 0x800A2028: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A202C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A2030: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800A2034: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800A2038: jal         0x800AAB5C
    // 0x800A203C: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A203C: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    after_1:
    // 0x800A2040: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A2044: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A2048: lwc1        $f8, 0x66C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A204C: nop

    // 0x800A2050: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A2054: swc1        $f10, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f10.u32l;
    // 0x800A2058: lb          $t1, 0x193($s3)
    ctx->r9 = MEM_B(ctx->r19, 0X193);
    // 0x800A205C: nop

    // 0x800A2060: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A2064: beq         $at, $zero, L_800A2078
    if (ctx->r1 == 0) {
        // 0x800A2068: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_800A2078;
    }
    // 0x800A2068: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800A206C: bne         $s0, $s1, L_800A2028
    if (ctx->r16 != ctx->r17) {
        // 0x800A2070: nop
    
            goto L_800A2028;
    }
    // 0x800A2070: nop

L_800A2074:
    // 0x800A2074: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
L_800A2078:
    // 0x800A2078: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800A207C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A2080: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800A2084: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800A2088: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A208C: sw          $t3, 0x2DB4($at)
    MEM_W(0X2DB4, ctx->r1) = ctx->r11;
    // 0x800A2090: lb          $t4, 0x1CF($s3)
    ctx->r12 = MEM_B(ctx->r19, 0X1CF);
    // 0x800A2094: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800A2098: blez        $t4, L_800A20F8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A209C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800A20F8;
    }
    // 0x800A209C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A20A0: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800A20A4: beq         $at, $zero, L_800A20FC
    if (ctx->r1 == 0) {
        // 0x800A20A8: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_800A20FC;
    }
    // 0x800A20A8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_800A20AC:
    // 0x800A20AC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A20B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A20B4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800A20B8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800A20BC: jal         0x800AAB5C
    // 0x800A20C0: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A20C0: addiu       $a3, $a3, 0x660
    ctx->r7 = ADD32(ctx->r7, 0X660);
    after_2:
    // 0x800A20C4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A20C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A20CC: lwc1        $f16, 0x66C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A20D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800A20D4: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x800A20D8: swc1        $f18, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f18.u32l;
    // 0x800A20DC: lb          $t6, 0x1CF($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X1CF);
    // 0x800A20E0: nop

    // 0x800A20E4: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800A20E8: beq         $at, $zero, L_800A20F8
    if (ctx->r1 == 0) {
        // 0x800A20EC: slti        $at, $s1, 0x3
        ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
            goto L_800A20F8;
    }
    // 0x800A20EC: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800A20F0: bne         $at, $zero, L_800A20AC
    if (ctx->r1 != 0) {
        // 0x800A20F4: nop
    
            goto L_800A20AC;
    }
    // 0x800A20F4: nop

L_800A20F8:
    // 0x800A20F8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_800A20FC:
    // 0x800A20FC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800A2100: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800A2104: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2108: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A210C: swc1        $f6, 0x66C($t7)
    MEM_W(0X66C, ctx->r15) = ctx->f6.u32l;
    // 0x800A2110: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A2114: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800A2118: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800A211C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800A2120: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800A2124: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A2128: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A212C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A2130: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A2134: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A2138: sb          $zero, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = 0;
    // 0x800A213C: jr          $ra
    // 0x800A2140: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800A2140: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void cam_get_active_camera_no_cutscenes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069F3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069F40: lw          $t6, 0x1264($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1264);
    // 0x80069F44: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069F48: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80069F4C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80069F50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069F54: addiu       $t8, $t8, 0x1040
    ctx->r24 = ADD32(ctx->r24, 0X1040);
    // 0x80069F58: jr          $ra
    // 0x80069F5C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x80069F5C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void reset_particles_with_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE808: jal         0x800AE8D4
    // 0x800AE80C: nop

    free_particle_buffers(rdram, ctx);
        goto after_0;
    // 0x800AE80C: nop

    after_0:
    // 0x800AE810: jal         0x800AE998
    // 0x800AE814: nop

    free_particle_vertices_triangles(rdram, ctx);
        goto after_1;
    // 0x800AE814: nop

    after_1:
    // 0x800AE818: jal         0x800AE9F0
    // 0x800AE81C: nop

    free_particle_assets(rdram, ctx);
        goto after_2;
    // 0x800AE81C: nop

    after_2:
    // 0x800AE820: jal         0x800AE838
    // 0x800AE824: nop

    particle_free_dummy(rdram, ctx);
        goto after_3;
    // 0x800AE824: nop

    after_3:
    // 0x800AE828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE82C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE830: jr          $ra
    // 0x800AE834: nop

    return;
    // 0x800AE834: nop

;}
RECOMP_FUNC void leveltable_non_challenge_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B258: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x8006B25C: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006B260: bltz        $t7, L_8006B288
    if (SIGNED(ctx->r15) < 0) {
        // 0x8006B264: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8006B288;
    }
    // 0x8006B264: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006B268: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x8006B26C: beq         $at, $zero, L_8006B288
    if (ctx->r1 == 0) {
        // 0x8006B270: sll         $t8, $t7, 2
        ctx->r24 = S32(ctx->r15 << 2);
            goto L_8006B288;
    }
    // 0x8006B270: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006B274: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006B278: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8006B27C: lw          $v0, 0x1700($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1700);
    // 0x8006B280: jr          $ra
    // 0x8006B284: nop

    return;
    // 0x8006B284: nop

L_8006B288:
    // 0x8006B288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B28C: jr          $ra
    // 0x8006B290: nop

    return;
    // 0x8006B290: nop

;}
