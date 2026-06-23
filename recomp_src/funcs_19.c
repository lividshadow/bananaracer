#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void obj_loop_char_select(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003837C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80038380: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80038384: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80038388: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003838C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80038390: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80038394: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80038398: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8003839C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800383A0: jal         0x8001F494
    // 0x800383A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x800383A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800383A8: lw          $v1, 0x64($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X64);
    // 0x800383AC: sw          $zero, 0x74($s2)
    MEM_W(0X74, ctx->r18) = 0;
    // 0x800383B0: beq         $v1, $zero, L_80038738
    if (ctx->r3 == 0) {
        // 0x800383B4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80038738;
    }
    // 0x800383B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800383B8: lb          $t7, 0x3A($s2)
    ctx->r15 = MEM_B(ctx->r18, 0X3A);
    // 0x800383BC: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    // 0x800383C0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800383C4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800383C8: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800383CC: nop

    // 0x800383D0: beq         $v0, $zero, L_80038738
    if (ctx->r2 == 0) {
        // 0x800383D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80038738;
    }
    // 0x800383D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800383D8: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x800383DC: jal         0x8009F214
    // 0x800383E0: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    is_drumstick_unlocked(rdram, ctx);
        goto after_1;
    // 0x800383E0: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_1:
    // 0x800383E4: beq         $v0, $zero, L_80038418
    if (ctx->r2 == 0) {
        // 0x800383E8: nop
    
            goto L_80038418;
    }
    // 0x800383E8: nop

    // 0x800383EC: jal         0x8009F1FC
    // 0x800383F0: nop

    is_tt_unlocked(rdram, ctx);
        goto after_2;
    // 0x800383F0: nop

    after_2:
    // 0x800383F4: beq         $v0, $zero, L_8003840C
    if (ctx->r2 == 0) {
        // 0x800383F8: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_8003840C;
    }
    // 0x800383F8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800383FC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80038400: addiu       $a2, $a2, -0x3020
    ctx->r6 = ADD32(ctx->r6, -0X3020);
    // 0x80038404: b           L_80038440
    // 0x80038408: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
        goto L_80038440;
    // 0x80038408: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_8003840C:
    // 0x8003840C: addiu       $a2, $a2, -0x3038
    ctx->r6 = ADD32(ctx->r6, -0X3038);
    // 0x80038410: b           L_80038440
    // 0x80038414: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
        goto L_80038440;
    // 0x80038414: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_80038418:
    // 0x80038418: jal         0x8009F1FC
    // 0x8003841C: nop

    is_tt_unlocked(rdram, ctx);
        goto after_3;
    // 0x8003841C: nop

    after_3:
    // 0x80038420: beq         $v0, $zero, L_80038438
    if (ctx->r2 == 0) {
        // 0x80038424: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_80038438;
    }
    // 0x80038424: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80038428: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8003842C: addiu       $a2, $a2, -0x302C
    ctx->r6 = ADD32(ctx->r6, -0X302C);
    // 0x80038430: b           L_80038440
    // 0x80038434: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
        goto L_80038440;
    // 0x80038434: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_80038438:
    // 0x80038438: addiu       $a2, $a2, -0x3040
    ctx->r6 = ADD32(ctx->r6, -0X3040);
    // 0x8003843C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80038440:
    // 0x80038440: blez        $a0, L_8003847C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80038444: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003847C;
    }
    // 0x80038444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038448: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8003844C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80038450: lh          $v1, 0x28($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X28);
    // 0x80038454: nop

L_80038458:
    // 0x80038458: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x8003845C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80038460: bne         $v1, $t2, L_8003846C
    if (ctx->r3 != ctx->r10) {
        // 0x80038464: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8003846C;
    }
    // 0x80038464: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80038468: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8003846C:
    // 0x8003846C: beq         $at, $zero, L_8003847C
    if (ctx->r1 == 0) {
        // 0x80038470: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8003847C;
    }
    // 0x80038470: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80038474: beq         $s0, $zero, L_80038458
    if (ctx->r16 == 0) {
        // 0x80038478: nop
    
            goto L_80038458;
    }
    // 0x80038478: nop

L_8003847C:
    // 0x8003847C: beq         $s0, $zero, L_80038638
    if (ctx->r16 == 0) {
        // 0x80038480: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80038638;
    }
    // 0x80038480: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80038484: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80038488: sb          $t3, 0x3B($s2)
    MEM_B(0X3B, ctx->r18) = ctx->r11;
    // 0x8003848C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80038490: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80038494: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x80038498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003849C:
    // 0x8003849C: sb          $v1, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r3;
    // 0x800384A0: jal         0x8009C7C4
    // 0x800384A4: sw          $a1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r5;
    get_player_character(rdram, ctx);
        goto after_4;
    // 0x800384A4: sw          $a1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r5;
    after_4:
    // 0x800384A8: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800384AC: lbu         $v1, 0x4F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X4F);
    // 0x800384B0: bne         $v0, $a1, L_800384CC
    if (ctx->r2 != ctx->r5) {
        // 0x800384B4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800384CC;
    }
    // 0x800384B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800384B8: addu        $t4, $s1, $v1
    ctx->r12 = ADD32(ctx->r17, ctx->r3);
    // 0x800384BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800384C0: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x800384C4: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800384C8: sb          $s0, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r16;
L_800384CC:
    // 0x800384CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800384D0: bne         $s0, $at, L_8003849C
    if (ctx->r16 != ctx->r1) {
        // 0x800384D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003849C;
    }
    // 0x800384D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800384D8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800384DC: addiu       $t7, $t7, -0x3014
    ctx->r15 = ADD32(ctx->r15, -0X3014);
    // 0x800384E0: addu        $v0, $a1, $t7
    ctx->r2 = ADD32(ctx->r5, ctx->r15);
    // 0x800384E4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800384E8: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800384EC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800384F0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800384F4: andi        $a0, $t9, 0xFF
    ctx->r4 = ctx->r25 & 0XFF;
    // 0x800384F8: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x800384FC: bne         $at, $zero, L_80038524
    if (ctx->r1 != 0) {
        // 0x80038500: sb          $t9, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r25;
            goto L_80038524;
    }
    // 0x80038500: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80038504: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80038508: addiu       $t2, $t2, -0x3008
    ctx->r10 = ADD32(ctx->r10, -0X3008);
    // 0x8003850C: addu        $t0, $a1, $t2
    ctx->r8 = ADD32(ctx->r5, ctx->r10);
    // 0x80038510: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x80038514: andi        $t1, $a0, 0xF
    ctx->r9 = ctx->r4 & 0XF;
    // 0x80038518: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8003851C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80038520: sb          $t4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r12;
L_80038524:
    // 0x80038524: addiu       $t5, $t5, -0x3008
    ctx->r13 = ADD32(ctx->r13, -0X3008);
    // 0x80038528: addu        $t0, $a1, $t5
    ctx->r8 = ADD32(ctx->r5, ctx->r13);
    // 0x8003852C: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x80038530: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80038534: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80038538: bne         $at, $zero, L_80038544
    if (ctx->r1 != 0) {
        // 0x8003853C: nop
    
            goto L_80038544;
    }
    // 0x8003853C: nop

    // 0x80038540: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_80038544:
    // 0x80038544: blez        $a3, L_80038638
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80038548: nop
    
            goto L_80038638;
    }
    // 0x80038548: nop

    // 0x8003854C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80038550: jal         0x8009C7B8
    // 0x80038554: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    charselect_status(rdram, ctx);
        goto after_5;
    // 0x80038554: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_5:
    // 0x80038558: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8003855C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80038560: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80038564: blez        $a3, L_800385D4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80038568: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800385D4;
    }
    // 0x80038568: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003856C: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x80038570: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80038574:
    // 0x80038574: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80038578: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003857C: addu        $t8, $t6, $a2
    ctx->r24 = ADD32(ctx->r14, ctx->r6);
    // 0x80038580: lb          $t9, 0x0($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X0);
    // 0x80038584: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80038588: bne         $t9, $at, L_800385C4
    if (ctx->r25 != ctx->r1) {
        // 0x8003858C: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_800385C4;
    }
    // 0x8003858C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80038590: sw          $s0, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r16;
    // 0x80038594: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80038598: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8003859C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800385A0: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x800385A4: jal         0x800B019C
    // 0x800385A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    obj_spawn_particle(rdram, ctx);
        goto after_6;
    // 0x800385A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_6:
    // 0x800385AC: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800385B0: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x800385B4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800385B8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800385BC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800385C0: nop

L_800385C4:
    // 0x800385C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800385C8: bne         $v1, $a3, L_80038574
    if (ctx->r3 != ctx->r7) {
        // 0x800385CC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80038574;
    }
    // 0x800385CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800385D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800385D4:
    // 0x800385D4: lh          $a2, 0x28($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X28);
    // 0x800385D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800385DC: blez        $a2, L_80038634
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800385E0: nop
    
            goto L_80038634;
    }
    // 0x800385E0: nop

L_800385E4:
    // 0x800385E4: lw          $t1, 0x38($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X38);
    // 0x800385E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800385EC: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    // 0x800385F0: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x800385F4: nop

    // 0x800385F8: bltz        $a1, L_80038628
    if (SIGNED(ctx->r5) < 0) {
        // 0x800385FC: slti        $at, $a1, 0x4
        ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
            goto L_80038628;
    }
    // 0x800385FC: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80038600: beq         $at, $zero, L_8003862C
    if (ctx->r1 == 0) {
        // 0x80038604: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8003862C;
    }
    // 0x80038604: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80038608: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x8003860C: nop

    // 0x80038610: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x80038614: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80038618: nop

    // 0x8003861C: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x80038620: lh          $a2, 0x28($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X28);
    // 0x80038624: nop

L_80038628:
    // 0x80038628: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
L_8003862C:
    // 0x8003862C: bne         $at, $zero, L_800385E4
    if (ctx->r1 != 0) {
        // 0x80038630: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800385E4;
    }
    // 0x80038630: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80038634:
    // 0x80038634: sb          $zero, 0x3B($s2)
    MEM_B(0X3B, ctx->r18) = 0;
L_80038638:
    // 0x80038638: lb          $v0, 0x3B($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X3B);
    // 0x8003863C: nop

    // 0x80038640: bltz        $v0, L_80038738
    if (SIGNED(ctx->r2) < 0) {
        // 0x80038644: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80038738;
    }
    // 0x80038644: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80038648: lh          $t5, 0x48($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X48);
    // 0x8003864C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80038650: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80038654: beq         $at, $zero, L_80038734
    if (ctx->r1 == 0) {
        // 0x80038658: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_80038734;
    }
    // 0x80038658: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8003865C: lw          $t7, 0x44($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X44);
    // 0x80038660: lbu         $t2, 0x2C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2C);
    // 0x80038664: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80038668: lw          $a1, 0x4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4);
    // 0x8003866C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038670: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80038674: bne         $t2, $at, L_80038734
    if (ctx->r10 != ctx->r1) {
        // 0x80038678: sll         $t9, $a1, 4
        ctx->r25 = S32(ctx->r5 << 4);
            goto L_80038734;
    }
    // 0x80038678: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8003867C: jal         0x800015F8
    // 0x80038680: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    music_animation_fraction(rdram, ctx);
        goto after_7;
    // 0x80038680: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    after_7:
    // 0x80038684: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80038688: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003868C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80038690: cvt.d.s     $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.d = CVT_D_S(ctx->f0.fl);
    // 0x80038694: c.lt.d      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.d < ctx->f14.d;
    // 0x80038698: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8003869C: bc1f        L_800386F4
    if (!c1cs) {
        // 0x800386A0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800386F4;
    }
    // 0x800386A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800386A4: sub.d       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f14.d - ctx->f18.d;
    // 0x800386A8: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800386AC: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800386B0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800386B4: add.d       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f2.d + ctx->f2.d;
    // 0x800386B8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800386BC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800386C0: mul.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800386C4: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800386C8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800386CC: nop

    // 0x800386D0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800386D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800386D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800386DC: nop

    // 0x800386E0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800386E4: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800386E8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800386EC: b           L_80038734
    // 0x800386F0: sh          $t4, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r12;
        goto L_80038734;
    // 0x800386F0: sh          $t4, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r12;
L_800386F4:
    // 0x800386F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800386F8: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x800386FC: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80038700: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80038704: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80038708: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8003870C: nop

    // 0x80038710: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80038714: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80038718: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003871C: nop

    // 0x80038720: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80038724: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80038728: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8003872C: sh          $t7, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r15;
    // 0x80038730: nop

L_80038734:
    // 0x80038734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80038738:
    // 0x80038738: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003873C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80038740: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80038744: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80038748: jr          $ra
    // 0x8003874C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8003874C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void music_voicelimit_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000BE0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80000BE4: lbu         $t6, -0x3420($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3420);
    // 0x80000BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000BF4: bne         $t6, $zero, L_80000C0C
    if (ctx->r14 != 0) {
        // 0x80000BF8: andi        $a1, $a0, 0xFF
        ctx->r5 = ctx->r4 & 0XFF;
            goto L_80000C0C;
    }
    // 0x80000BF8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80000BFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000C00: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80000C04: jal         0x8000B010
    // 0x80000C08: nop

    set_voice_limit(rdram, ctx);
        goto after_0;
    // 0x80000C08: nop

    after_0:
L_80000C0C:
    // 0x80000C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000C14: jr          $ra
    // 0x80000C18: nop

    return;
    // 0x80000C18: nop

;}
RECOMP_FUNC void audioStartThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002A58: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002A5C: jal         0x800C8F00
    // 0x80002A60: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    osStartThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80002A60: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    after_0:
    // 0x80002A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002A6C: jr          $ra
    // 0x80002A70: nop

    return;
    // 0x80002A70: nop

;}
RECOMP_FUNC void hud_lives_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2834: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2838: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A283C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A2840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2844: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A2848: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A284C: lb          $t7, 0x3($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3);
    // 0x800A2850: addiu       $s0, $s0, 0x729C
    ctx->r16 = ADD32(ctx->r16, 0X729C);
    // 0x800A2854: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A2858: addiu       $t8, $t7, 0x38
    ctx->r24 = ADD32(ctx->r15, 0X38);
    // 0x800A285C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A2860: sh          $t8, 0x646($t9)
    MEM_H(0X646, ctx->r25) = ctx->r24;
    // 0x800A2864: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A2868: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800A286C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A2870: bne         $at, $zero, L_800A2898
    if (ctx->r1 != 0) {
        // 0x800A2874: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A2898;
    }
    // 0x800A2874: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A2878: bne         $v1, $at, L_800A28EC
    if (ctx->r3 != ctx->r1) {
        // 0x800A287C: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_800A28EC;
    }
    // 0x800A287C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800A2880: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A2884: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A2888: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800A288C: nop

    // 0x800A2890: bne         $t1, $at, L_800A28EC
    if (ctx->r9 != ctx->r1) {
        // 0x800A2894: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_800A28EC;
    }
    // 0x800A2894: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_800A2898:
    // 0x800A2898: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800A289C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A28A0: sb          $t2, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = ctx->r10;
    // 0x800A28A4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A28A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A28AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A28B0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A28B4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A28B8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A28BC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A28C0: jal         0x800AAB5C
    // 0x800A28C4: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A28C4: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_0:
    // 0x800A28C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A28CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A28D0: sb          $zero, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = 0;
    // 0x800A28D4: jal         0x800784A4
    // 0x800A28D8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rdp_init(rdram, ctx);
        goto after_1;
    // 0x800A28D8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_1:
    // 0x800A28DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A28E0: jal         0x8007B820
    // 0x800A28E4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rendermode_reset(rdram, ctx);
        goto after_2;
    // 0x800A28E4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_2:
    // 0x800A28E8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_800A28EC:
    // 0x800A28EC: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800A28F0: lb          $v0, 0x185($t3)
    ctx->r2 = MEM_B(ctx->r11, 0X185);
    // 0x800A28F4: nop

    // 0x800A28F8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800A28FC: beq         $at, $zero, L_800A2940
    if (ctx->r1 == 0) {
        // 0x800A2900: nop
    
            goto L_800A2940;
    }
    // 0x800A2900: nop

    // 0x800A2904: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800A2908: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A290C: sh          $v0, 0x6D8($t4)
    MEM_H(0X6D8, ctx->r12) = ctx->r2;
    // 0x800A2910: lbu         $t5, 0x72F7($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X72F7);
    // 0x800A2914: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A2918: bne         $t5, $at, L_800A29D8
    if (ctx->r13 != ctx->r1) {
        // 0x800A291C: nop
    
            goto L_800A29D8;
    }
    // 0x800A291C: nop

    // 0x800A2920: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2924: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800A2928: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A292C: lwc1        $f4, 0x6CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A2930: nop

    // 0x800A2934: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A2938: b           L_800A29D8
    // 0x800A293C: swc1        $f8, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f8.u32l;
        goto L_800A29D8;
    // 0x800A293C: swc1        $f8, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f8.u32l;
L_800A2940:
    // 0x800A2940: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800A2944: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A2948: bne         $v1, $zero, L_800A2954
    if (ctx->r3 != 0) {
        // 0x800A294C: nop
    
            goto L_800A2954;
    }
    // 0x800A294C: nop

    // 0x800A2950: break       7
    do_break(2148149584);
L_800A2954:
    // 0x800A2954: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A2958: bne         $v1, $at, L_800A296C
    if (ctx->r3 != ctx->r1) {
        // 0x800A295C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A296C;
    }
    // 0x800A295C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A2960: bne         $v0, $at, L_800A296C
    if (ctx->r2 != ctx->r1) {
        // 0x800A2964: nop
    
            goto L_800A296C;
    }
    // 0x800A2964: nop

    // 0x800A2968: break       6
    do_break(2148149608);
L_800A296C:
    // 0x800A296C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2970: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2974: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2978: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A297C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A2980: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A2984: mflo        $t6
    ctx->r14 = lo;
    // 0x800A2988: sh          $t6, 0x6D8($t7)
    MEM_H(0X6D8, ctx->r15) = ctx->r14;
    // 0x800A298C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A2990: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800A2994: lb          $t9, 0x185($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X185);
    // 0x800A2998: nop

    // 0x800A299C: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x800A29A0: bne         $v1, $zero, L_800A29AC
    if (ctx->r3 != 0) {
        // 0x800A29A4: nop
    
            goto L_800A29AC;
    }
    // 0x800A29A4: nop

    // 0x800A29A8: break       7
    do_break(2148149672);
L_800A29AC:
    // 0x800A29AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A29B0: bne         $v1, $at, L_800A29C4
    if (ctx->r3 != ctx->r1) {
        // 0x800A29B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A29C4;
    }
    // 0x800A29B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A29B8: bne         $t9, $at, L_800A29C4
    if (ctx->r25 != ctx->r1) {
        // 0x800A29BC: nop
    
            goto L_800A29C4;
    }
    // 0x800A29BC: nop

    // 0x800A29C0: break       6
    do_break(2148149696);
L_800A29C4:
    // 0x800A29C4: mfhi        $t0
    ctx->r8 = hi;
    // 0x800A29C8: sh          $t0, 0x6F8($t1)
    MEM_H(0X6F8, ctx->r9) = ctx->r8;
    // 0x800A29CC: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A29D0: jal         0x800AAB5C
    // 0x800A29D4: addiu       $a3, $a3, 0x6E0
    ctx->r7 = ADD32(ctx->r7, 0X6E0);
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A29D4: addiu       $a3, $a3, 0x6E0
    ctx->r7 = ADD32(ctx->r7, 0X6E0);
    after_3:
L_800A29D8:
    // 0x800A29D8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A29DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A29E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A29E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A29E8: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A29EC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A29F0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A29F4: jal         0x800AAB5C
    // 0x800A29F8: addiu       $a3, $a3, 0x6C0
    ctx->r7 = ADD32(ctx->r7, 0X6C0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A29F8: addiu       $a3, $a3, 0x6C0
    ctx->r7 = ADD32(ctx->r7, 0X6C0);
    after_4:
    // 0x800A29FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A2A00: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A2A04: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800A2A08: bne         $a0, $v1, L_800A2A50
    if (ctx->r4 != ctx->r3) {
        // 0x800A2A0C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A2A50;
    }
    // 0x800A2A0C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2A10: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800A2A14: nop

    // 0x800A2A18: lb          $t3, 0x185($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X185);
    // 0x800A2A1C: nop

    // 0x800A2A20: slti        $at, $t3, 0xA
    ctx->r1 = SIGNED(ctx->r11) < 0XA ? 1 : 0;
    // 0x800A2A24: beq         $at, $zero, L_800A2A50
    if (ctx->r1 == 0) {
        // 0x800A2A28: nop
    
            goto L_800A2A50;
    }
    // 0x800A2A28: nop

    // 0x800A2A2C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2A30: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800A2A34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A2A38: lwc1        $f10, 0x6CC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A2A3C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A2A40: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800A2A44: swc1        $f18, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f18.u32l;
    // 0x800A2A48: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A2A4C: nop

L_800A2A50:
    // 0x800A2A50: beq         $a0, $v1, L_800A2ABC
    if (ctx->r4 == ctx->r3) {
        // 0x800A2A54: addiu       $a1, $a1, 0x72C0
        ctx->r5 = ADD32(ctx->r5, 0X72C0);
            goto L_800A2ABC;
    }
    // 0x800A2A54: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A2A58: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A2A5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2A60: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2A64: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A2A68: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A2A6C: jal         0x800AAB5C
    // 0x800A2A70: addiu       $a3, $a3, 0x6A0
    ctx->r7 = ADD32(ctx->r7, 0X6A0);
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A2A70: addiu       $a3, $a3, 0x6A0
    ctx->r7 = ADD32(ctx->r7, 0X6A0);
    after_5:
    // 0x800A2A74: jal         0x8007C36C
    // 0x800A2A78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_6;
    // 0x800A2A78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A2A7C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A2A80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2A84: sb          $t4, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = ctx->r12;
    // 0x800A2A88: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800A2A8C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2A90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2A94: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2A98: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A2A9C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A2AA0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A2AA4: jal         0x800AAB5C
    // 0x800A2AA8: addiu       $a3, $a3, 0x680
    ctx->r7 = ADD32(ctx->r7, 0X680);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A2AA8: addiu       $a3, $a3, 0x680
    ctx->r7 = ADD32(ctx->r7, 0X680);
    after_7:
    // 0x800A2AAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A2AB0: sb          $zero, 0x7295($at)
    MEM_B(0X7295, ctx->r1) = 0;
    // 0x800A2AB4: jal         0x8007C36C
    // 0x800A2AB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_8;
    // 0x800A2AB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
L_800A2ABC:
    // 0x800A2ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2AC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A2AC4: jr          $ra
    // 0x800A2AC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A2AC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_init_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DAF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004DAF4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004DAF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004DAFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DB00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004DB04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004DB08: sw          $zero, -0x2544($at)
    MEM_W(-0X2544, ctx->r1) = 0;
    // 0x8004DB0C: lh          $t6, 0xC($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XC);
    // 0x8004DB10: lw          $s0, 0x64($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X64);
    // 0x8004DB14: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x8004DB18: lh          $t7, 0xA($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XA);
    // 0x8004DB1C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8004DB20: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x8004DB24: lh          $t8, 0x8($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X8);
    // 0x8004DB28: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8004DB2C: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
    // 0x8004DB30: lh          $a2, 0xE($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XE);
    // 0x8004DB34: sb          $zero, 0x194($s0)
    MEM_B(0X194, ctx->r16) = 0;
    // 0x8004DB38: swc1        $f2, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f2.u32l;
    // 0x8004DB3C: bltz        $a2, L_8004DB80
    if (SIGNED(ctx->r6) < 0) {
        // 0x8004DB40: swc1        $f2, 0x90($s0)
        MEM_W(0X90, ctx->r16) = ctx->f2.u32l;
            goto L_8004DB80;
    }
    // 0x8004DB40: swc1        $f2, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f2.u32l;
    // 0x8004DB44: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x8004DB48: beq         $at, $zero, L_8004DB80
    if (ctx->r1 == 0) {
        // 0x8004DB4C: nop
    
            goto L_8004DB80;
    }
    // 0x8004DB4C: nop

    // 0x8004DB50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004DB54: jal         0x8000E158
    // 0x8004DB58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    is_race_started_by_player_two(rdram, ctx);
        goto after_0;
    // 0x8004DB58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004DB5C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB60: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8004DB64: beq         $v0, $zero, L_8004DB74
    if (ctx->r2 == 0) {
        // 0x8004DB68: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004DB74;
    }
    // 0x8004DB68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004DB6C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004DB70: subu        $a2, $t9, $a2
    ctx->r6 = SUB32(ctx->r25, ctx->r6);
L_8004DB74:
    // 0x8004DB74: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004DB78: b           L_8004DB84
    // 0x8004DB7C: sh          $a2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r6;
        goto L_8004DB84;
    // 0x8004DB7C: sh          $a2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r6;
L_8004DB80:
    // 0x8004DB80: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
L_8004DB84:
    // 0x8004DB84: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x8004DB88: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004DB8C: sh          $t2, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r10;
    // 0x8004DB90: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x8004DB94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004DB98: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004DB9C: sh          $t3, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r11;
    // 0x8004DBA0: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x8004DBA4: sh          $t4, 0x196($s0)
    MEM_H(0X196, ctx->r16) = ctx->r12;
    // 0x8004DBA8: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DBAC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004DBB0: swc1        $f6, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f6.u32l;
    // 0x8004DBB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004DBB8: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DBBC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8004DBC0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8004DBC4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004DBC8: swc1        $f10, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f10.u32l;
    // 0x8004DBCC: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DBD0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004DBD4: swc1        $f16, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f16.u32l;
    // 0x8004DBD8: lwc1        $f18, 0xC($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DBDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004DBE0: swc1        $f18, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f18.u32l;
    // 0x8004DBE4: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DBE8: nop

    // 0x8004DBEC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8004DBF0: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x8004DBF4: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DBF8: nop

    // 0x8004DBFC: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x8004DC00: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DC04: nop

    // 0x8004DC08: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    // 0x8004DC0C: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DC10: nop

    // 0x8004DC14: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8004DC18: swc1        $f18, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f18.u32l;
    // 0x8004DC1C: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DC20: nop

    // 0x8004DC24: swc1        $f4, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f4.u32l;
    // 0x8004DC28: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DC2C: nop

    // 0x8004DC30: swc1        $f6, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f6.u32l;
    // 0x8004DC34: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DC38: nop

    // 0x8004DC3C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8004DC40: swc1        $f10, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->f10.u32l;
    // 0x8004DC44: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DC48: nop

    // 0x8004DC4C: swc1        $f16, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f16.u32l;
    // 0x8004DC50: lwc1        $f18, 0xC($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DC54: nop

    // 0x8004DC58: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x8004DC5C: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DC60: nop

    // 0x8004DC64: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
    // 0x8004DC68: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DC6C: nop

    // 0x8004DC70: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    // 0x8004DC74: lw          $t5, 0x4C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DC78: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DC7C: nop

    // 0x8004DC80: swc1        $f8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f8.u32l;
    // 0x8004DC84: lw          $t6, 0x4C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DC88: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DC8C: nop

    // 0x8004DC90: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
    // 0x8004DC94: lw          $t7, 0x4C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DC98: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DC9C: nop

    // 0x8004DCA0: swc1        $f16, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f16.u32l;
    // 0x8004DCA4: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8004DCA8: sb          $t8, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r24;
    // 0x8004DCAC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8004DCB0: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x8004DCB4: sh          $t9, 0x1AA($s0)
    MEM_H(0X1AA, ctx->r16) = ctx->r25;
    // 0x8004DCB8: sh          $t1, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r9;
    // 0x8004DCBC: sb          $t2, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r10;
    // 0x8004DCC0: swc1        $f2, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f2.u32l;
    // 0x8004DCC4: sb          $zero, 0x1FD($s0)
    MEM_B(0X1FD, ctx->r16) = 0;
    // 0x8004DCC8: sw          $zero, 0x178($s0)
    MEM_W(0X178, ctx->r16) = 0;
    // 0x8004DCCC: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    // 0x8004DCD0: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8004DCD4: sw          $zero, 0x218($s0)
    MEM_W(0X218, ctx->r16) = 0;
    // 0x8004DCD8: sw          $zero, 0x220($s0)
    MEM_W(0X220, ctx->r16) = 0;
    // 0x8004DCDC: beq         $v0, $at, L_8004DD8C
    if (ctx->r2 == ctx->r1) {
        // 0x8004DCE0: sw          $zero, 0x21C($s0)
        MEM_W(0X21C, ctx->r16) = 0;
            goto L_8004DD8C;
    }
    // 0x8004DCE0: sw          $zero, 0x21C($s0)
    MEM_W(0X21C, ctx->r16) = 0;
    // 0x8004DCE4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004DCE8: addiu       $v0, $v0, -0x24FE
    ctx->r2 = ADD32(ctx->r2, -0X24FE);
    // 0x8004DCEC: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x8004DCF0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004DCF4: bne         $t3, $zero, L_8004DD8C
    if (ctx->r11 != 0) {
        // 0x8004DCF8: nop
    
            goto L_8004DD8C;
    }
    // 0x8004DCF8: nop

    // 0x8004DCFC: jal         0x80066828
    // 0x8004DD00: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    set_active_camera(rdram, ctx);
        goto after_1;
    // 0x8004DD00: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x8004DD04: jal         0x80069F3C
    // 0x8004DD08: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_2;
    // 0x8004DD08: nop

    after_2:
    // 0x8004DD0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004DD10: addiu       $v1, $v1, -0x2578
    ctx->r3 = ADD32(ctx->r3, -0X2578);
    // 0x8004DD14: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004DD18: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8004DD1C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8004DD20: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD24: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x8004DD28: sh          $t5, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r13;
    // 0x8004DD2C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD30: lh          $t7, 0x196($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X196);
    // 0x8004DD34: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8004DD38: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x8004DD3C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD40: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004DD44: sh          $zero, 0x36($t9)
    MEM_H(0X36, ctx->r25) = 0;
    // 0x8004DD48: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004DD50: sb          $t0, 0x3C($t1)
    MEM_B(0X3C, ctx->r9) = ctx->r8;
    // 0x8004DD54: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD58: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8004DD5C: sb          $t0, 0x3D($t2)
    MEM_B(0X3D, ctx->r10) = ctx->r8;
    // 0x8004DD60: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD64: nop

    // 0x8004DD68: sb          $t0, 0x3E($t3)
    MEM_B(0X3E, ctx->r11) = ctx->r8;
    // 0x8004DD6C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD70: nop

    // 0x8004DD74: sb          $t0, 0x3F($t4)
    MEM_B(0X3F, ctx->r12) = ctx->r8;
    // 0x8004DD78: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD7C: jal         0x80057A80
    // 0x8004DD80: swc1        $f18, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f18.u32l;
    update_player_camera(rdram, ctx);
        goto after_3;
    // 0x8004DD80: swc1        $f18, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f18.u32l;
    after_3:
    // 0x8004DD84: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8004DD88: nop

L_8004DD8C:
    // 0x8004DD8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004DD90: addiu       $v0, $v0, -0x24FE
    ctx->r2 = ADD32(ctx->r2, -0X24FE);
    // 0x8004DD94: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8004DD98: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8004DD9C: bne         $t6, $zero, L_8004DDBC
    if (ctx->r14 != 0) {
        // 0x8004DDA0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004DDBC;
    }
    // 0x8004DDA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004DDA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DDA8: sb          $zero, -0x24FD($at)
    MEM_B(-0X24FD, ctx->r1) = 0;
    // 0x8004DDAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DDB0: sh          $zero, -0x24FA($at)
    MEM_H(-0X24FA, ctx->r1) = 0;
    // 0x8004DDB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DDB8: sb          $zero, -0x24FC($at)
    MEM_B(-0X24FC, ctx->r1) = 0;
L_8004DDBC:
    // 0x8004DDBC: lw          $t8, 0x4C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DDC0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8004DDC4: sh          $t7, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r15;
    // 0x8004DDC8: lw          $t9, 0x4C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DDCC: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8004DDD0: sb          $zero, 0x11($t9)
    MEM_B(0X11, ctx->r25) = 0;
    // 0x8004DDD4: lw          $t2, 0x4C($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DDD8: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8004DDDC: sb          $t1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r9;
    // 0x8004DDE0: lw          $t4, 0x4C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DDE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DDE8: sb          $t3, 0x12($t4)
    MEM_B(0X12, ctx->r12) = ctx->r11;
    // 0x8004DDEC: sb          $zero, 0x1EE($s0)
    MEM_B(0X1EE, ctx->r16) = 0;
    // 0x8004DDF0: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x8004DDF4: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8004DDF8: bne         $t5, $zero, L_8004DE04
    if (ctx->r13 != 0) {
        // 0x8004DDFC: addiu       $t7, $zero, 0x64
        ctx->r15 = ADD32(0, 0X64);
            goto L_8004DE04;
    }
    // 0x8004DDFC: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8004DE00: sb          $t0, 0x1F7($s0)
    MEM_B(0X1F7, ctx->r16) = ctx->r8;
L_8004DE04:
    // 0x8004DE04: sh          $zero, -0x2520($at)
    MEM_H(-0X2520, ctx->r1) = 0;
    // 0x8004DE08: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8004DE0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004DE10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DE14: swc1        $f4, -0x253C($at)
    MEM_W(-0X253C, ctx->r1) = ctx->f4.u32l;
    // 0x8004DE18: sb          $t6, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r14;
    // 0x8004DE1C: sh          $t7, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r15;
    // 0x8004DE20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DE24: sb          $zero, -0x2500($at)
    MEM_B(-0X2500, ctx->r1) = 0;
    // 0x8004DE28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DE2C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004DE30: sb          $zero, -0x24F4($at)
    MEM_B(-0X24F4, ctx->r1) = 0;
    // 0x8004DE34: sb          $zero, -0x24F3($at)
    MEM_B(-0X24F3, ctx->r1) = 0;
    // 0x8004DE38: sb          $zero, -0x24F2($at)
    MEM_B(-0X24F2, ctx->r1) = 0;
    // 0x8004DE3C: sb          $zero, -0x24F1($at)
    MEM_B(-0X24F1, ctx->r1) = 0;
    // 0x8004DE40: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8004DE44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004DE48: jal         0x80043F0C
    // 0x8004DE4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    increment_ai_behaviour_chances(rdram, ctx);
        goto after_4;
    // 0x8004DE4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8004DE50: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8004DE54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DE58: sb          $v0, -0x24FD($at)
    MEM_B(-0X24FD, ctx->r1) = ctx->r2;
    // 0x8004DE5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DE60: sb          $zero, -0x24FB($at)
    MEM_B(-0X24FB, ctx->r1) = 0;
    // 0x8004DE64: sb          $zero, 0x20A($s0)
    MEM_B(0X20A, ctx->r16) = 0;
    // 0x8004DE68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DE6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004DE70: jr          $ra
    // 0x8004DE74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8004DE74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void get_projection_matrix_s16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069FF4: jr          $ra
    // 0x80069FF8: addiu       $v0, $v0, 0x1560
    ctx->r2 = ADD32(ctx->r2, 0X1560);
    return;
    // 0x80069FF8: addiu       $v0, $v0, 0x1560
    ctx->r2 = ADD32(ctx->r2, 0X1560);
;}
RECOMP_FUNC void obj_init_midifade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041AD0: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80041AD4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80041AD8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80041ADC: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80041AE0: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80041AE4: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80041AE8: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80041AEC: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80041AF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041AF4: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x80041AF8: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x80041AFC: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x80041B00: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80041B04: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80041B08: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80041B0C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041B10: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x80041B14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041B18: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80041B1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80041B20: bc1f        L_80041B2C
    if (!c1cs) {
        // 0x80041B24: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80041B2C;
    }
    // 0x80041B24: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80041B28: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_80041B2C:
    // 0x80041B2C: nop

    // 0x80041B30: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80041B34: lw          $t2, 0x40($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X40);
    // 0x80041B38: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80041B3C: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80041B40: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80041B44: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80041B48: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    // 0x80041B4C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80041B50: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80041B54: sh          $t3, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r11;
    // 0x80041B58: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80041B5C: nop

    // 0x80041B60: sh          $t4, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r12;
    // 0x80041B64: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    // 0x80041B68: swc1        $f22, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f22.u32l;
    // 0x80041B6C: sw          $t0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r8;
    // 0x80041B70: sw          $a2, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r6;
    // 0x80041B74: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
    // 0x80041B78: swc1        $f20, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f20.u32l;
    // 0x80041B7C: swc1        $f20, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f20.u32l;
    // 0x80041B80: jal         0x8006FE70
    // 0x80041B84: sh          $t5, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = ctx->r13;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x80041B84: sh          $t5, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = ctx->r13;
    after_0:
    // 0x80041B88: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80041B8C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041B90: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80041B94: addiu       $t6, $sp, 0xDC
    ctx->r14 = ADD32(ctx->r29, 0XDC);
    // 0x80041B98: addiu       $t7, $sp, 0xD8
    ctx->r15 = ADD32(ctx->r29, 0XD8);
    // 0x80041B9C: addiu       $t8, $sp, 0xD4
    ctx->r24 = ADD32(ctx->r29, 0XD4);
    // 0x80041BA0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80041BA4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80041BA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80041BAC: jal         0x8006F88C
    // 0x80041BB0: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x80041BB0: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    after_1:
    // 0x80041BB4: lw          $t0, 0xFC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XFC);
    // 0x80041BB8: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80041BBC: lw          $a0, 0x104($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X104);
    // 0x80041BC0: swc1        $f4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f4.u32l;
    // 0x80041BC4: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80041BC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80041BCC: swc1        $f6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f6.u32l;
    // 0x80041BD0: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80041BD4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80041BD8: swc1        $f8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f8.u32l;
    // 0x80041BDC: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80041BE0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80041BE4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80041BE8: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80041BEC: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80041BF0: nop

    // 0x80041BF4: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80041BF8: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80041BFC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80041C00: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80041C04: nop

    // 0x80041C08: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80041C0C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80041C10: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x80041C14: swc1        $f6, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f6.u32l;
    // 0x80041C18: lbu         $t9, 0x1A($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1A);
    // 0x80041C1C: nop

    // 0x80041C20: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    // 0x80041C24: lbu         $t1, 0x1B($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X1B);
    // 0x80041C28: nop

    // 0x80041C2C: sb          $t1, 0x40($t0)
    MEM_B(0X40, ctx->r8) = ctx->r9;
L_80041C30:
    // 0x80041C30: lbu         $t2, 0xA($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XA);
    // 0x80041C34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80041C38: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x80041C3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80041C40: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80041C44: bne         $at, $zero, L_80041C30
    if (ctx->r1 != 0) {
        // 0x80041C48: sb          $t2, 0x2F($v1)
        MEM_B(0X2F, ctx->r3) = ctx->r10;
            goto L_80041C30;
    }
    // 0x80041C48: sb          $t2, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r10;
    // 0x80041C4C: lw          $t3, 0x68($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X68);
    // 0x80041C50: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80041C54: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80041C58: nop

    // 0x80041C5C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80041C60: nop

    // 0x80041C64: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x80041C68: lh          $a3, 0x24($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X24);
    // 0x80041C6C: addiu       $v1, $a2, 0xA
    ctx->r3 = ADD32(ctx->r6, 0XA);
    // 0x80041C70: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x80041C74: lh          $t5, 0x2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2);
    // 0x80041C78: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    // 0x80041C7C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80041C80: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80041C84: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80041C88: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80041C8C: sll         $a1, $a3, 2
    ctx->r5 = S32(ctx->r7 << 2);
    // 0x80041C90: addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // 0x80041C94: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041C98: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80041C9C: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80041CA0: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80041CA4: addiu       $a0, $a2, 0xA
    ctx->r4 = ADD32(ctx->r6, 0XA);
    // 0x80041CA8: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x80041CAC: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x80041CB0: bne         $at, $zero, L_80041D78
    if (ctx->r1 != 0) {
        // 0x80041CB4: mov.s       $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
            goto L_80041D78;
    }
    // 0x80041CB4: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
L_80041CB8:
    // 0x80041CB8: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80041CBC: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80041CC0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80041CC4: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80041CC8: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80041CCC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80041CD0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80041CD4: nop

    // 0x80041CD8: bc1f        L_80041CE4
    if (!c1cs) {
        // 0x80041CDC: nop
    
            goto L_80041CE4;
    }
    // 0x80041CDC: nop

    // 0x80041CE0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80041CE4:
    // 0x80041CE4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80041CE8: nop

    // 0x80041CEC: bc1f        L_80041CF8
    if (!c1cs) {
        // 0x80041CF0: nop
    
            goto L_80041CF8;
    }
    // 0x80041CF0: nop

    // 0x80041CF4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80041CF8:
    // 0x80041CF8: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80041CFC: nop

    // 0x80041D00: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80041D04: nop

    // 0x80041D08: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80041D0C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80041D10: nop

    // 0x80041D14: bc1f        L_80041D20
    if (!c1cs) {
        // 0x80041D18: nop
    
            goto L_80041D20;
    }
    // 0x80041D18: nop

    // 0x80041D1C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_80041D20:
    // 0x80041D20: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80041D24: nop

    // 0x80041D28: bc1f        L_80041D34
    if (!c1cs) {
        // 0x80041D2C: nop
    
            goto L_80041D34;
    }
    // 0x80041D2C: nop

    // 0x80041D30: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80041D34:
    // 0x80041D34: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80041D38: nop

    // 0x80041D3C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80041D40: nop

    // 0x80041D44: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041D48: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80041D4C: nop

    // 0x80041D50: bc1f        L_80041D5C
    if (!c1cs) {
        // 0x80041D54: nop
    
            goto L_80041D5C;
    }
    // 0x80041D54: nop

    // 0x80041D58: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80041D5C:
    // 0x80041D5C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80041D60: nop

    // 0x80041D64: bc1f        L_80041D70
    if (!c1cs) {
        // 0x80041D68: nop
    
            goto L_80041D70;
    }
    // 0x80041D68: nop

    // 0x80041D6C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80041D70:
    // 0x80041D70: bne         $at, $zero, L_80041CB8
    if (ctx->r1 != 0) {
        // 0x80041D74: addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
            goto L_80041CB8;
    }
    // 0x80041D74: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
L_80041D78:
    // 0x80041D78: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80041D7C: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x80041D80: swc1        $f14, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f14.u32l;
    // 0x80041D84: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    // 0x80041D88: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    // 0x80041D8C: jal         0x80070A38
    // 0x80041D90: sw          $t0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r8;
    coss_f(rdram, ctx);
        goto after_2;
    // 0x80041D90: sw          $t0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r8;
    after_2:
    // 0x80041D94: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80041D98: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80041D9C: jal         0x80070A04
    // 0x80041DA0: nop

    sins_f(rdram, ctx);
        goto after_3;
    // 0x80041DA0: nop

    after_3:
    // 0x80041DA4: lwc1        $f14, 0x80($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80041DA8: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80041DAC: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80041DB0: mul.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80041DB4: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
    // 0x80041DB8: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80041DBC: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80041DC0: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80041DC4: lw          $t0, 0xFC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XFC);
    // 0x80041DC8: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80041DCC: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80041DD0: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80041DD4: mov.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
    // 0x80041DD8: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80041DDC: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80041DE0: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80041DE4: add.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80041DE8: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80041DEC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80041DF0: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80041DF4: bc1f        L_80041E08
    if (!c1cs) {
        // 0x80041DF8: sub.s       $f12, $f6, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
            goto L_80041E08;
    }
    // 0x80041DF8: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80041DFC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80041E00: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80041E04: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80041E08:
    // 0x80041E08: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80041E0C: nop

    // 0x80041E10: bc1f        L_80041E24
    if (!c1cs) {
        // 0x80041E14: nop
    
            goto L_80041E24;
    }
    // 0x80041E14: nop

    // 0x80041E18: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80041E1C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x80041E20: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80041E24:
    // 0x80041E24: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041E28: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80041E2C: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80041E30: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041E34: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x80041E38: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041E3C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80041E40: mul.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80041E44: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041E48: swc1        $f8, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f8.u32l;
    // 0x80041E4C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041E50: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80041E54: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80041E58: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041E5C: swc1        $f8, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f8.u32l;
    // 0x80041E60: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041E64: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80041E68: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80041E6C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041E70: swc1        $f8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f8.u32l;
    // 0x80041E74: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041E78: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80041E7C: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80041E80: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041E84: swc1        $f8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f8.u32l;
    // 0x80041E88: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041E8C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80041E90: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80041E94: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x80041E98: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041E9C: swc1        $f8, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f8.u32l;
    // 0x80041EA0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80041EA4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80041EA8: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80041EAC: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80041EB0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80041EB4: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80041EB8: jr          $ra
    // 0x80041EBC: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80041EBC: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void tex_enable_modes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B278: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B27C: addiu       $v0, $v0, 0x6918
    ctx->r2 = ADD32(ctx->r2, 0X6918);
    // 0x8007B280: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007B284: nor         $t7, $a0, $zero
    ctx->r15 = ~(ctx->r4 | 0);
    // 0x8007B288: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8007B28C: jr          $ra
    // 0x8007B290: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x8007B290: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void play_footstep_sounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800113CC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800113D0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800113D4: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800113D8: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800113DC: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800113E0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800113E4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800113E8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800113EC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800113F0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800113F4: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800113F8: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800113FC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80011400: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80011404: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80011408: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001140C: lbu         $t6, 0x5B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5B);
    // 0x80011410: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80011414: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80011418: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x8001141C: beq         $at, $zero, L_80011520
    if (ctx->r1 == 0) {
        // 0x80011420: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80011520;
    }
    // 0x80011420: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80011424: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x80011428: lbu         $a0, 0x5C($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X5C);
    // 0x8001142C: jal         0x8001E2D0
    // 0x80011430: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80011430: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    after_0:
    // 0x80011434: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x80011438: lb          $t0, 0x2($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X2);
    // 0x8001143C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80011440: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80011444: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80011448: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001144C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80011450: lh          $s4, 0x18($s1)
    ctx->r20 = MEM_H(ctx->r17, 0X18);
    // 0x80011454: lb          $s2, 0x0($v0)
    ctx->r18 = MEM_B(ctx->r2, 0X0);
    // 0x80011458: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8001145C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80011460: sra         $t1, $s3, 4
    ctx->r9 = S32(SIGNED(ctx->r19) >> 4);
    // 0x80011464: mul.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80011468: sra         $t2, $s4, 4
    ctx->r10 = S32(SIGNED(ctx->r20) >> 4);
    // 0x8001146C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80011470: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x80011474: or          $s4, $t2, $zero
    ctx->r20 = ctx->r10 | 0;
    // 0x80011478: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001147C: blez        $s2, L_80011520
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80011480: cvt.s.w     $f22, $f10
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80011520;
    }
    // 0x80011480: cvt.s.w     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80011484: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x80011488: nop

    // 0x8001148C: addu        $t3, $s0, $s6
    ctx->r11 = ADD32(ctx->r16, ctx->r22);
L_80011490:
    // 0x80011490: lb          $v0, 0x3($t3)
    ctx->r2 = MEM_B(ctx->r11, 0X3);
    // 0x80011494: nop

    // 0x80011498: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001149C: bne         $at, $zero, L_800114A8
    if (ctx->r1 != 0) {
        // 0x800114A0: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800114A8;
    }
    // 0x800114A0: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800114A4: bne         $at, $zero, L_800114BC
    if (ctx->r1 != 0) {
        // 0x800114A8: slt         $at, $v0, $s4
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_800114BC;
    }
L_800114A8:
    // 0x800114A8: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800114AC: bne         $at, $zero, L_80011510
    if (ctx->r1 != 0) {
        // 0x800114B0: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80011510;
    }
    // 0x800114B0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800114B4: beq         $at, $zero, L_80011510
    if (ctx->r1 == 0) {
        // 0x800114B8: nop
    
            goto L_80011510;
    }
    // 0x800114B8: nop

L_800114BC:
    // 0x800114BC: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800114C0: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800114C4: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x800114C8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800114CC: jal         0x8006A054
    // 0x800114D0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    set_camera_shake_by_distance(rdram, ctx);
        goto after_1;
    // 0x800114D0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_1:
    // 0x800114D4: andi        $t4, $s0, 0x1
    ctx->r12 = ctx->r16 & 0X1;
    // 0x800114D8: beq         $t4, $zero, L_800114E8
    if (ctx->r12 == 0) {
        // 0x800114DC: addiu       $t5, $zero, 0x4
        ctx->r13 = ADD32(0, 0X4);
            goto L_800114E8;
    }
    // 0x800114DC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800114E0: b           L_800114EC
    // 0x800114E4: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
        goto L_800114EC;
    // 0x800114E4: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
L_800114E8:
    // 0x800114E8: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_800114EC:
    // 0x800114EC: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x800114F0: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x800114F4: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x800114F8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800114FC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80011500: jal         0x80009558
    // 0x80011504: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_2;
    // 0x80011504: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x80011508: addiu       $v1, $s0, 0x1
    ctx->r3 = ADD32(ctx->r16, 0X1);
    // 0x8001150C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80011510:
    // 0x80011510: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80011514: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80011518: bne         $at, $zero, L_80011490
    if (ctx->r1 != 0) {
        // 0x8001151C: addu        $t3, $s0, $s6
        ctx->r11 = ADD32(ctx->r16, ctx->r22);
            goto L_80011490;
    }
    // 0x8001151C: addu        $t3, $s0, $s6
    ctx->r11 = ADD32(ctx->r16, ctx->r22);
L_80011520:
    // 0x80011520: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80011524: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80011528: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001152C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80011530: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80011534: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80011538: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8001153C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80011540: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80011544: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80011548: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8001154C: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80011550: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80011554: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80011558: jr          $ra
    // 0x8001155C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001155C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void hud_setting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A89B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A89B8: lw          $t6, 0x72CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72CC);
    // 0x800A89BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A89C0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800A89C4: lb          $v0, 0x2D24($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2D24);
    // 0x800A89C8: jr          $ra
    // 0x800A89CC: nop

    return;
    // 0x800A89CC: nop

;}
RECOMP_FUNC void hud_visibility(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB730: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AB734: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x800AB738: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB73C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AB740: jr          $ra
    // 0x800AB744: sb          $t8, 0x7292($at)
    MEM_B(0X7292, ctx->r1) = ctx->r24;
    return;
    // 0x800AB744: sb          $t8, 0x7292($at)
    MEM_B(0X7292, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void is_postrace_viewport_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ECF4: lb          $v0, 0x3A96($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3A96);
    // 0x8006ECF8: jr          $ra
    // 0x8006ECFC: nop

    return;
    // 0x8006ECFC: nop

;}
RECOMP_FUNC void __freeParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800658DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800658E0: lw          $v0, 0x3D10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3D10);
    // 0x800658E4: nop

    // 0x800658E8: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x800658EC: nop

    // 0x800658F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800658F4: jr          $ra
    // 0x800658F8: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
    return;
    // 0x800658F8: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_80060C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060E98: bne         $a1, $a3, L_80060EB4
    if (ctx->r5 != ctx->r7) {
        // 0x80060E9C: lw          $v1, 0x10($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X10);
            goto L_80060EB4;
    }
    // 0x80060E9C: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80060EA0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80060EA4: nop

    // 0x80060EA8: beq         $a2, $v1, L_80060EC8
    if (ctx->r6 == ctx->r3) {
        // 0x80060EAC: nop
    
            goto L_80060EC8;
    }
    // 0x80060EAC: nop

    // 0x80060EB0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
L_80060EB4:
    // 0x80060EB4: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80060EB8: bne         $a1, $v1, L_80060ED0
    if (ctx->r5 != ctx->r3) {
        // 0x80060EBC: nop
    
            goto L_80060ED0;
    }
    // 0x80060EBC: nop

    // 0x80060EC0: bne         $a2, $a3, L_80060ED0
    if (ctx->r6 != ctx->r7) {
        // 0x80060EC4: nop
    
            goto L_80060ED0;
    }
    // 0x80060EC4: nop

L_80060EC8:
    // 0x80060EC8: jr          $ra
    // 0x80060ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80060ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060ED0:
    // 0x80060ED0: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060ED4: mflo        $t6
    ctx->r14 = lo;
    // 0x80060ED8: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x80060EDC: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x80060EE0: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060EE4: addiu       $t2, $t1, -0x4
    ctx->r10 = ADD32(ctx->r9, -0X4);
    // 0x80060EE8: addiu       $t8, $t1, 0x4
    ctx->r24 = ADD32(ctx->r9, 0X4);
    // 0x80060EEC: mflo        $t7
    ctx->r15 = lo;
    // 0x80060EF0: addu        $t0, $t7, $a0
    ctx->r8 = ADD32(ctx->r15, ctx->r4);
    // 0x80060EF4: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x80060EF8: nop

    // 0x80060EFC: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80060F00: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F04: slt         $at, $t3, $t8
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
            goto L_80060FE8;
    }
    // 0x80060F04: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060F08: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F0C: nop
    
            goto L_80060FE8;
    }
    // 0x80060F0C: nop

    // 0x80060F10: lh          $a3, 0x2($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X2);
    // 0x80060F14: lh          $a1, 0x2($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X2);
    // 0x80060F18: addiu       $t9, $a3, -0x4
    ctx->r25 = ADD32(ctx->r7, -0X4);
    // 0x80060F1C: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060F20: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F24: addiu       $t6, $a3, 0x4
        ctx->r14 = ADD32(ctx->r7, 0X4);
            goto L_80060FE8;
    }
    // 0x80060F24: addiu       $t6, $a3, 0x4
    ctx->r14 = ADD32(ctx->r7, 0X4);
    // 0x80060F28: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80060F2C: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F30: nop
    
            goto L_80060FE8;
    }
    // 0x80060F30: nop

    // 0x80060F34: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x80060F38: lh          $a1, 0x4($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X4);
    // 0x80060F3C: addiu       $t7, $a3, -0x4
    ctx->r15 = ADD32(ctx->r7, -0X4);
    // 0x80060F40: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060F44: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F48: addiu       $t8, $a3, 0x4
        ctx->r24 = ADD32(ctx->r7, 0X4);
            goto L_80060FE8;
    }
    // 0x80060F48: addiu       $t8, $a3, 0x4
    ctx->r24 = ADD32(ctx->r7, 0X4);
    // 0x80060F4C: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060F50: beq         $at, $zero, L_80060FE8
    if (ctx->r1 == 0) {
        // 0x80060F54: nop
    
            goto L_80060FE8;
    }
    // 0x80060F54: nop

    // 0x80060F58: multu       $v1, $t5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060F5C: mflo        $t9
    ctx->r25 = lo;
    // 0x80060F60: addu        $a3, $t9, $a0
    ctx->r7 = ADD32(ctx->r25, ctx->r4);
    // 0x80060F64: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x80060F68: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060F6C: addiu       $t7, $t4, -0x4
    ctx->r15 = ADD32(ctx->r12, -0X4);
    // 0x80060F70: addiu       $t8, $t4, 0x4
    ctx->r24 = ADD32(ctx->r12, 0X4);
    // 0x80060F74: mflo        $t6
    ctx->r14 = lo;
    // 0x80060F78: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
    // 0x80060F7C: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80060F80: nop

    // 0x80060F84: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80060F88: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80060F8C: slt         $at, $t0, $t8
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
            goto L_800610DC;
    }
    // 0x80060F8C: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060F90: beq         $at, $zero, L_800610E0
    if (ctx->r1 == 0) {
        // 0x80060F94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800610E0;
    }
    // 0x80060F94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060F98: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x80060F9C: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80060FA0: addiu       $t9, $t3, -0x4
    ctx->r25 = ADD32(ctx->r11, -0X4);
    // 0x80060FA4: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80060FA8: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80060FAC: addiu       $t6, $t3, 0x4
        ctx->r14 = ADD32(ctx->r11, 0X4);
            goto L_800610DC;
    }
    // 0x80060FAC: addiu       $t6, $t3, 0x4
    ctx->r14 = ADD32(ctx->r11, 0X4);
    // 0x80060FB0: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80060FB4: beq         $at, $zero, L_800610E0
    if (ctx->r1 == 0) {
        // 0x80060FB8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800610E0;
    }
    // 0x80060FB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060FBC: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x80060FC0: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x80060FC4: addiu       $t7, $t3, -0x4
    ctx->r15 = ADD32(ctx->r11, -0X4);
    // 0x80060FC8: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80060FCC: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80060FD0: addiu       $t8, $t3, 0x4
        ctx->r24 = ADD32(ctx->r11, 0X4);
            goto L_800610DC;
    }
    // 0x80060FD0: addiu       $t8, $t3, 0x4
    ctx->r24 = ADD32(ctx->r11, 0X4);
    // 0x80060FD4: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060FD8: beq         $at, $zero, L_800610E0
    if (ctx->r1 == 0) {
        // 0x80060FDC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800610E0;
    }
    // 0x80060FDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060FE0: jr          $ra
    // 0x80060FE4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80060FE4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80060FE8:
    // 0x80060FE8: multu       $v1, $t5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060FEC: mflo        $t9
    ctx->r25 = lo;
    // 0x80060FF0: addu        $a3, $t9, $a0
    ctx->r7 = ADD32(ctx->r25, ctx->r4);
    // 0x80060FF4: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x80060FF8: nop

    // 0x80060FFC: addiu       $t6, $t4, -0x4
    ctx->r14 = ADD32(ctx->r12, -0X4);
    // 0x80061000: slt         $at, $t6, $t3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80061004: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061008: addiu       $t7, $t4, 0x4
        ctx->r15 = ADD32(ctx->r12, 0X4);
            goto L_800610DC;
    }
    // 0x80061008: addiu       $t7, $t4, 0x4
    ctx->r15 = ADD32(ctx->r12, 0X4);
    // 0x8006100C: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80061010: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061014: nop
    
            goto L_800610DC;
    }
    // 0x80061014: nop

    // 0x80061018: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x8006101C: lh          $a1, 0x2($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X2);
    // 0x80061020: addiu       $t8, $t3, -0x4
    ctx->r24 = ADD32(ctx->r11, -0X4);
    // 0x80061024: slt         $at, $t8, $a1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80061028: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x8006102C: addiu       $t9, $t3, 0x4
        ctx->r25 = ADD32(ctx->r11, 0X4);
            goto L_800610DC;
    }
    // 0x8006102C: addiu       $t9, $t3, 0x4
    ctx->r25 = ADD32(ctx->r11, 0X4);
    // 0x80061030: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061034: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061038: nop
    
            goto L_800610DC;
    }
    // 0x80061038: nop

    // 0x8006103C: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x80061040: lh          $a1, 0x4($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X4);
    // 0x80061044: addiu       $t6, $t3, -0x4
    ctx->r14 = ADD32(ctx->r11, -0X4);
    // 0x80061048: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8006104C: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061050: addiu       $t7, $t3, 0x4
        ctx->r15 = ADD32(ctx->r11, 0X4);
            goto L_800610DC;
    }
    // 0x80061050: addiu       $t7, $t3, 0x4
    ctx->r15 = ADD32(ctx->r11, 0X4);
    // 0x80061054: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80061058: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x8006105C: nop
    
            goto L_800610DC;
    }
    // 0x8006105C: nop

    // 0x80061060: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80061064: addiu       $t9, $t1, 0x4
    ctx->r25 = ADD32(ctx->r9, 0X4);
    // 0x80061068: mflo        $t8
    ctx->r24 = lo;
    // 0x8006106C: addu        $a1, $t8, $a0
    ctx->r5 = ADD32(ctx->r24, ctx->r4);
    // 0x80061070: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80061074: nop

    // 0x80061078: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8006107C: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061080: slt         $at, $t0, $t9
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_800610DC;
    }
    // 0x80061080: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80061084: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x80061088: nop
    
            goto L_800610DC;
    }
    // 0x80061088: nop

    // 0x8006108C: lh          $a3, 0x2($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X2);
    // 0x80061090: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80061094: addiu       $t6, $a3, -0x4
    ctx->r14 = ADD32(ctx->r7, -0X4);
    // 0x80061098: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006109C: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x800610A0: addiu       $t7, $a3, 0x4
        ctx->r15 = ADD32(ctx->r7, 0X4);
            goto L_800610DC;
    }
    // 0x800610A0: addiu       $t7, $a3, 0x4
    ctx->r15 = ADD32(ctx->r7, 0X4);
    // 0x800610A4: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800610A8: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x800610AC: nop
    
            goto L_800610DC;
    }
    // 0x800610AC: nop

    // 0x800610B0: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x800610B4: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x800610B8: addiu       $t8, $a3, -0x4
    ctx->r24 = ADD32(ctx->r7, -0X4);
    // 0x800610BC: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800610C0: beq         $at, $zero, L_800610DC
    if (ctx->r1 == 0) {
        // 0x800610C4: addiu       $t9, $a3, 0x4
        ctx->r25 = ADD32(ctx->r7, 0X4);
            goto L_800610DC;
    }
    // 0x800610C4: addiu       $t9, $a3, 0x4
    ctx->r25 = ADD32(ctx->r7, 0X4);
    // 0x800610C8: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800610CC: beq         $at, $zero, L_800610E0
    if (ctx->r1 == 0) {
        // 0x800610D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800610E0;
    }
    // 0x800610D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800610D4: jr          $ra
    // 0x800610D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800610D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800610DC:
    // 0x800610DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800610E0:
    // 0x800610E0: jr          $ra
    // 0x800610E4: nop

    return;
    // 0x800610E4: nop

;}
RECOMP_FUNC void racer_sound_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F94: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80007F98: lbu         $v0, -0x33C0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X33C0);
    // 0x80007F9C: jr          $ra
    // 0x80007FA0: nop

    return;
    // 0x80007FA0: nop

;}
RECOMP_FUNC void hud_time_trial_message(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A72FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7304: jal         0x8006ECD0
    // 0x800A7308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x800A7308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A730C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800A7310: nop

    // 0x800A7314: beq         $v1, $zero, L_800A7380
    if (ctx->r3 == 0) {
        // 0x800A7318: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A7380;
    }
    // 0x800A7318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A731C: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800A7320: nop

    // 0x800A7324: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A7328: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A732C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A7330: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800A7334: lb          $t9, 0x58($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X58);
    // 0x800A7338: nop

    // 0x800A733C: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x800A7340: beq         $t0, $zero, L_800A736C
    if (ctx->r8 == 0) {
        // 0x800A7344: nop
    
            goto L_800A736C;
    }
    // 0x800A7344: nop

    // 0x800A7348: jal         0x8006BFD8
    // 0x800A734C: nop

    level_type(rdram, ctx);
        goto after_1;
    // 0x800A734C: nop

    after_1:
    // 0x800A7350: bne         $v0, $zero, L_800A736C
    if (ctx->r2 != 0) {
        // 0x800A7354: addiu       $a0, $zero, 0x145
        ctx->r4 = ADD32(0, 0X145);
            goto L_800A736C;
    }
    // 0x800A7354: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    // 0x800A7358: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A735C: jal         0x80001D04
    // 0x800A7360: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800A7360: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    after_2:
    // 0x800A7364: b           L_800A7380
    // 0x800A7368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A7380;
    // 0x800A7368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A736C:
    // 0x800A736C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7370: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A7374: jal         0x80001D04
    // 0x800A7378: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A7378: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    after_3:
    // 0x800A737C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7380:
    // 0x800A7380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7384: jr          $ra
    // 0x800A7388: nop

    return;
    // 0x800A7388: nop

;}
RECOMP_FUNC void music_next(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001954: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80001958: lbu         $v1, -0x3434($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X3434);
    // 0x8000195C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001960: beq         $v1, $zero, L_80001970
    if (ctx->r3 == 0) {
        // 0x80001964: nop
    
            goto L_80001970;
    }
    // 0x80001964: nop

    // 0x80001968: jr          $ra
    // 0x8000196C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000196C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80001970:
    // 0x80001970: lbu         $v0, 0x6284($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6284);
    // 0x80001974: nop

    // 0x80001978: jr          $ra
    // 0x8000197C: nop

    return;
    // 0x8000197C: nop

;}
RECOMP_FUNC void setup_particle_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0920: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B0924: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0928: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B092C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B0930: lh          $t6, 0x18($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X18);
    // 0x800B0934: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B0938: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B093C: nop

    // 0x800B0940: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B0944: swc1        $f6, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f6.u32l;
    // 0x800B0948: lh          $t7, 0x1A($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X1A);
    // 0x800B094C: nop

    // 0x800B0950: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B0954: nop

    // 0x800B0958: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B095C: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x800B0960: lh          $t8, 0x1C($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1C);
    // 0x800B0964: nop

    // 0x800B0968: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B096C: nop

    // 0x800B0970: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B0974: swc1        $f18, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f18.u32l;
    // 0x800B0978: lwc1        $f4, 0x58($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X58);
    // 0x800B097C: nop

    // 0x800B0980: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x800B0984: lw          $t9, 0x5C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X5C);
    // 0x800B0988: nop

    // 0x800B098C: sll         $t0, $t9, 12
    ctx->r8 = S32(ctx->r25 << 12);
    // 0x800B0990: bgez        $t0, L_800B09E4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B0994: nop
    
            goto L_800B09E4;
    }
    // 0x800B0994: nop

    // 0x800B0998: lw          $a1, 0x94($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X94);
    // 0x800B099C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B09A0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B09A4: jal         0x8006FB8C
    // 0x800B09A8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800B09A8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_0:
    // 0x800B09AC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800B09B0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B09B4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B09B8: lwc1        $f17, -0x6EC8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X6EC8);
    // 0x800B09BC: lwc1        $f16, -0x6EC4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6EC4);
    // 0x800B09C0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B09C4: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800B09C8: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800B09CC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B09D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B09D4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800B09D8: add.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d + ctx->f18.d;
    // 0x800B09DC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800B09E0: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_800B09E4:
    // 0x800B09E4: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x800B09E8: nop

    // 0x800B09EC: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800B09F0: beq         $t2, $zero, L_800B0B4C
    if (ctx->r10 == 0) {
        // 0x800B09F4: nop
    
            goto L_800B0B4C;
    }
    // 0x800B09F4: nop

    // 0x800B09F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B09FC: nop

    // 0x800B0A00: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800B0A04: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800B0A08: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B0A0C: nop

    // 0x800B0A10: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x800B0A14: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x800B0A18: lw          $v1, 0x5C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X5C);
    // 0x800B0A1C: nop

    // 0x800B0A20: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x800B0A24: beq         $t3, $zero, L_800B0A84
    if (ctx->r11 == 0) {
        // 0x800B0A28: andi        $t4, $v1, 0x6
        ctx->r12 = ctx->r3 & 0X6;
            goto L_800B0A84;
    }
    // 0x800B0A28: andi        $t4, $v1, 0x6
    ctx->r12 = ctx->r3 & 0X6;
    // 0x800B0A2C: lw          $a1, 0x60($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X60);
    // 0x800B0A30: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B0A34: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B0A38: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B0A3C: jal         0x8006FB8C
    // 0x800B0A40: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800B0A40: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_1:
    // 0x800B0A44: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800B0A48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0A4C: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B0A50: lwc1        $f11, -0x6EC0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X6EC0);
    // 0x800B0A54: lwc1        $f10, -0x6EBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6EBC);
    // 0x800B0A58: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800B0A5C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B0A60: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0A64: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0A68: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B0A6C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B0A70: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x800B0A74: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0A78: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x800B0A7C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800B0A80: andi        $t4, $v1, 0x6
    ctx->r12 = ctx->r3 & 0X6;
L_800B0A84:
    // 0x800B0A84: beq         $t4, $zero, L_800B0B0C
    if (ctx->r12 == 0) {
        // 0x800B0A88: addiu       $a0, $a2, 0xC
        ctx->r4 = ADD32(ctx->r6, 0XC);
            goto L_800B0B0C;
    }
    // 0x800B0A88: addiu       $a0, $a2, 0xC
    ctx->r4 = ADD32(ctx->r6, 0XC);
    // 0x800B0A8C: lh          $t5, 0xC($a2)
    ctx->r13 = MEM_H(ctx->r6, 0XC);
    // 0x800B0A90: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x800B0A94: beq         $t6, $zero, L_800B0ACC
    if (ctx->r14 == 0) {
        // 0x800B0A98: sh          $t5, 0x28($sp)
        MEM_H(0X28, ctx->r29) = ctx->r13;
            goto L_800B0ACC;
    }
    // 0x800B0A98: sh          $t5, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r13;
    // 0x800B0A9C: lh          $a1, 0x64($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X64);
    // 0x800B0AA0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B0AA4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B0AA8: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B0AAC: jal         0x8006FB8C
    // 0x800B0AB0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800B0AB0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_2:
    // 0x800B0AB4: lh          $t7, 0x28($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X28);
    // 0x800B0AB8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0ABC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800B0AC0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B0AC4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0AC8: sh          $t8, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r24;
L_800B0ACC:
    // 0x800B0ACC: lh          $t9, 0xE($a2)
    ctx->r25 = MEM_H(ctx->r6, 0XE);
    // 0x800B0AD0: andi        $t0, $v1, 0x4
    ctx->r8 = ctx->r3 & 0X4;
    // 0x800B0AD4: beq         $t0, $zero, L_800B0AF8
    if (ctx->r8 == 0) {
        // 0x800B0AD8: sh          $t9, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r25;
            goto L_800B0AF8;
    }
    // 0x800B0AD8: sh          $t9, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r25;
    // 0x800B0ADC: lh          $a1, 0x66($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X66);
    // 0x800B0AE0: jal         0x8006FB8C
    // 0x800B0AE4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_3;
    // 0x800B0AE4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_3:
    // 0x800B0AE8: lh          $t1, 0x2A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2A);
    // 0x800B0AEC: nop

    // 0x800B0AF0: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800B0AF4: sh          $t2, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r10;
L_800B0AF8:
    // 0x800B0AF8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B0AFC: jal         0x800706D0
    // 0x800B0B00: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    vec3f_rotate_py(rdram, ctx);
        goto after_4;
    // 0x800B0B00: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x800B0B04: b           L_800B0B18
    // 0x800B0B08: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
        goto L_800B0B18;
    // 0x800B0B08: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
L_800B0B0C:
    // 0x800B0B0C: jal         0x80070560
    // 0x800B0B10: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    vec3f_rotate(rdram, ctx);
        goto after_5;
    // 0x800B0B10: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x800B0B14: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
L_800B0B18:
    // 0x800B0B18: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B0B1C: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800B0B20: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0B24: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800B0B28: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x800B0B2C: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800B0B30: nop

    // 0x800B0B34: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B0B38: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x800B0B3C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0B40: nop

    // 0x800B0B44: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0B48: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
L_800B0B4C:
    // 0x800B0B4C: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x800B0B50: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B0B54: beq         $v0, $at, L_800B0B70
    if (ctx->r2 == ctx->r1) {
        // 0x800B0B58: nop
    
            goto L_800B0B70;
    }
    // 0x800B0B58: nop

    // 0x800B0B5C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800B0B60: jal         0x80070560
    // 0x800B0B64: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    vec3f_rotate(rdram, ctx);
        goto after_6;
    // 0x800B0B64: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    after_6:
    // 0x800B0B68: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x800B0B6C: nop

L_800B0B70:
    // 0x800B0B70: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800B0B74: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800B0B78: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800B0B7C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B0B80: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800B0B84: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x800B0B88: bne         $v0, $at, L_800B0B9C
    if (ctx->r2 != ctx->r1) {
        // 0x800B0B8C: swc1        $f8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
            goto L_800B0B9C;
    }
    // 0x800B0B8C: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800B0B90: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800B0B94: jal         0x80070560
    // 0x800B0B98: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    vec3f_rotate(rdram, ctx);
        goto after_7;
    // 0x800B0B98: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    after_7:
L_800B0B9C:
    // 0x800B0B9C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800B0BA0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B0BA4: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800B0BA8: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B0BAC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0BB0: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B0BB4: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800B0BB8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800B0BBC: nop

    // 0x800B0BC0: lwc1        $f18, 0x10($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800B0BC4: nop

    // 0x800B0BC8: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B0BCC: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x800B0BD0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B0BD4: nop

    // 0x800B0BD8: lwc1        $f4, 0x14($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X14);
    // 0x800B0BDC: nop

    // 0x800B0BE0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0BE4: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800B0BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0BEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0BF0: jr          $ra
    // 0x800B0BF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B0BF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void path_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011390: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80011394: jr          $ra
    // 0x80011398: sw          $zero, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = 0;
    return;
    // 0x80011398: sw          $zero, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = 0;
;}
RECOMP_FUNC void savemenu_input_source(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087940: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80087944: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x80087948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008794C: beq         $t6, $zero, L_80087998
    if (ctx->r14 == 0) {
        // 0x80087950: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_80087998;
    }
    // 0x80087950: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80087954: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80087958: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008795C: lw          $t8, 0x6FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6FD0);
    // 0x80087960: lw          $t7, 0x6FD4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6FD4);
    // 0x80087964: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087968: beq         $t7, $t8, L_80087980
    if (ctx->r15 == ctx->r24) {
        // 0x8008796C: sw          $zero, 0x6980($at)
        MEM_W(0X6980, ctx->r1) = 0;
            goto L_80087980;
    }
    // 0x8008796C: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x80087970: jal         0x80087648
    // 0x80087974: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    savemenu_render_error(rdram, ctx);
        goto after_0;
    // 0x80087974: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80087978: b           L_80087A48
    // 0x8008797C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80087A48;
    // 0x8008797C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087980:
    // 0x80087980: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80087984: jal         0x80001D04
    // 0x80087988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80087988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8008798C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80087990: b           L_80087A44
    // 0x80087994: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
        goto L_80087A44;
    // 0x80087994: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_80087998:
    // 0x80087998: andi        $t0, $a0, 0x9000
    ctx->r8 = ctx->r4 & 0X9000;
    // 0x8008799C: beq         $t0, $zero, L_800879BC
    if (ctx->r8 == 0) {
        // 0x800879A0: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_800879BC;
    }
    // 0x800879A0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800879A4: jal         0x80001D04
    // 0x800879A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800879A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800879AC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800879B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800879B4: b           L_80087A44
    // 0x800879B8: sw          $t1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r9;
        goto L_80087A44;
    // 0x800879B8: sw          $t1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r9;
L_800879BC:
    // 0x800879BC: bgez        $a1, L_800879FC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800879C0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800879FC;
    }
    // 0x800879C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800879C4: addiu       $v0, $v0, 0x7194
    ctx->r2 = ADD32(ctx->r2, 0X7194);
    // 0x800879C8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800879CC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800879D0: blez        $t2, L_800879FC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800879D4: nop
    
            goto L_800879FC;
    }
    // 0x800879D4: nop

    // 0x800879D8: jal         0x80001D04
    // 0x800879DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800879DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800879E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800879E4: addiu       $v0, $v0, 0x7194
    ctx->r2 = ADD32(ctx->r2, 0X7194);
    // 0x800879E8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800879EC: nop

    // 0x800879F0: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800879F4: b           L_80087A44
    // 0x800879F8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_80087A44;
    // 0x800879F8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_800879FC:
    // 0x800879FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087A00: blez        $a1, L_80087A44
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80087A04: addiu       $v0, $v0, 0x7194
        ctx->r2 = ADD32(ctx->r2, 0X7194);
            goto L_80087A44;
    }
    // 0x80087A04: addiu       $v0, $v0, 0x7194
    ctx->r2 = ADD32(ctx->r2, 0X7194);
    // 0x80087A08: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80087A0C: lw          $t6, 0x6FC8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FC8);
    // 0x80087A10: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80087A14: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80087A18: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80087A1C: beq         $at, $zero, L_80087A44
    if (ctx->r1 == 0) {
        // 0x80087A20: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80087A44;
    }
    // 0x80087A20: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087A24: jal         0x80001D04
    // 0x80087A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x80087A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80087A2C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087A30: addiu       $v0, $v0, 0x7194
    ctx->r2 = ADD32(ctx->r2, 0X7194);
    // 0x80087A34: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80087A38: nop

    // 0x80087A3C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80087A40: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80087A44:
    // 0x80087A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087A48:
    // 0x80087A48: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80087A4C: jr          $ra
    // 0x80087A50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80087A50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void rspF3DDKRXbusStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void set_dialogue_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C54DC: bltz        $a0, L_800C5514
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C54E0: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C5514;
    }
    // 0x800C54E0: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C54E4: beq         $at, $zero, L_800C5514
    if (ctx->r1 == 0) {
        // 0x800C54E8: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C5514;
    }
    // 0x800C54E8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C54EC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C54F0: lw          $t8, -0x5260($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5260);
    // 0x800C54F4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C54F8: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C54FC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5500: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5504: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C5508: beq         $at, $zero, L_800C5514
    if (ctx->r1 == 0) {
        // 0x800C550C: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_800C5514;
    }
    // 0x800C550C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5510: sb          $a1, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r5;
L_800C5514:
    // 0x800C5514: jr          $ra
    // 0x800C5518: nop

    return;
    // 0x800C5518: nop

;}
RECOMP_FUNC void alAdpcmPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC14C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800CC150: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800CC154: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800CC158: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CC15C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800CC160: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800CC164: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800CC168: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800CC16C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800CC170: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800CC174: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800CC178: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800CC17C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800CC180: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800CC184: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800CC188: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800CC18C: bne         $a2, $zero, L_800CC19C
    if (ctx->r6 != 0) {
        // 0x800CC190: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_800CC19C;
    }
    // 0x800CC190: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800CC194: b           L_800CC5BC
    // 0x800CC198: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
        goto L_800CC5BC;
    // 0x800CC198: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
L_800CC19C:
    // 0x800CC19C: lw          $t6, 0x2C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X2C);
    // 0x800CC1A0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CC1A4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC1A8: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x800CC1AC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800CC1B0: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x800CC1B4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800CC1B8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CC1BC: lw          $t9, 0x28($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X28);
    // 0x800CC1C0: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800CC1C4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC1C8: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x800CC1CC: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x800CC1D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CC1D4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800CC1D8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800CC1DC: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800CC1E0: lw          $v1, 0x38($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X38);
    // 0x800CC1E4: lw          $a0, 0x20($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X20);
    // 0x800CC1E8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800CC1EC: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x800CC1F0: sltu        $t1, $a0, $t9
    ctx->r9 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x800CC1F4: beq         $t1, $zero, L_800CC208
    if (ctx->r9 == 0) {
        // 0x800CC1F8: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_800CC208;
    }
    // 0x800CC1F8: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800CC1FC: lw          $t1, 0x24($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X24);
    // 0x800CC200: sltu        $t6, $zero, $t1
    ctx->r14 = 0 < ctx->r9 ? 1 : 0;
    // 0x800CC204: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
L_800CC208:
    // 0x800CC208: beq         $t1, $zero, L_800CC218
    if (ctx->r9 == 0) {
        // 0x800CC20C: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800CC218;
    }
    // 0x800CC20C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800CC210: b           L_800CC218
    // 0x800CC214: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
        goto L_800CC218;
    // 0x800CC214: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
L_800CC218:
    // 0x800CC218: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC21C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800CC220: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800CC224: beq         $v1, $zero, L_800CC234
    if (ctx->r3 == 0) {
        // 0x800CC228: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800CC234;
    }
    // 0x800CC228: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800CC22C: b           L_800CC234
    // 0x800CC230: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
        goto L_800CC234;
    // 0x800CC230: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
L_800CC234:
    // 0x800CC234: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800CC238: bgez        $a0, L_800CC244
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800CC23C: nop
    
            goto L_800CC244;
    }
    // 0x800CC23C: nop

    // 0x800CC240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800CC244:
    // 0x800CC244: beq         $t1, $zero, L_800CC44C
    if (ctx->r9 == 0) {
        // 0x800CC248: addiu       $fp, $a0, 0xF
        ctx->r30 = ADD32(ctx->r4, 0XF);
            goto L_800CC44C;
    }
    // 0x800CC248: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800CC24C: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800CC250: sra         $t8, $fp, 4
    ctx->r24 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800CC254: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800CC258: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800CC25C: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x800CC260: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x800CC264: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800CC268: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800CC26C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800CC270: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800CC274: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800CC278: or          $fp, $t8, $zero
    ctx->r30 = ctx->r24 | 0;
    // 0x800CC27C: jal         0x800CC020
    // 0x800CC280: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    static_3_800CC020(rdram, ctx);
        goto after_0;
    // 0x800CC280: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_0:
    // 0x800CC284: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC288: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800CC28C: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800CC290: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800CC294: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800CC298: beq         $v1, $zero, L_800CC2B4
    if (ctx->r3 == 0) {
        // 0x800CC29C: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800CC2B4;
    }
    // 0x800CC29C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800CC2A0: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800CC2A4: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800CC2A8: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800CC2AC: b           L_800CC2C0
    // 0x800CC2B0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
        goto L_800CC2C0;
    // 0x800CC2B0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800CC2B4:
    // 0x800CC2B4: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800CC2B8: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800CC2BC: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_800CC2C0:
    // 0x800CC2C0: lw          $v0, 0x1C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1C);
    // 0x800CC2C4: lw          $t7, 0x28($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X28);
    // 0x800CC2C8: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CC2CC: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800CC2D0: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800CC2D4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800CC2D8: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x800CC2DC: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800CC2E0: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800CC2E4: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800CC2E8: addiu       $t9, $t7, 0x9
    ctx->r25 = ADD32(ctx->r15, 0X9);
    // 0x800CC2EC: sw          $t9, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r25;
    // 0x800CC2F0: sw          $v0, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r2;
    // 0x800CC2F4: beq         $at, $zero, L_800CC41C
    if (ctx->r1 == 0) {
        // 0x800CC2F8: lh          $a2, 0x0($a3)
        ctx->r6 = MEM_H(ctx->r7, 0X0);
            goto L_800CC41C;
    }
    // 0x800CC2F8: lh          $a2, 0x0($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X0);
    // 0x800CC2FC: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_800CC300:
    // 0x800CC300: addiu       $t8, $fp, 0x1
    ctx->r24 = ADD32(ctx->r30, 0X1);
    // 0x800CC304: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x800CC308: lw          $v0, 0x24($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X24);
    // 0x800CC30C: addu        $a3, $t6, $a2
    ctx->r7 = ADD32(ctx->r14, ctx->r6);
    // 0x800CC310: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800CC314: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x800CC318: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CC31C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x800CC320: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800CC324: beq         $v0, $at, L_800CC338
    if (ctx->r2 == ctx->r1) {
        // 0x800CC328: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_800CC338;
    }
    // 0x800CC328: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800CC32C: beq         $v0, $zero, L_800CC338
    if (ctx->r2 == 0) {
        // 0x800CC330: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800CC338;
    }
    // 0x800CC330: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800CC334: sw          $t9, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->r25;
L_800CC338:
    // 0x800CC338: lw          $t8, 0x20($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X20);
    // 0x800CC33C: lw          $t6, 0x1C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X1C);
    // 0x800CC340: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800CC344: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800CC348: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x800CC34C: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800CC350: beq         $at, $zero, L_800CC360
    if (ctx->r1 == 0) {
        // 0x800CC354: sll         $s5, $a3, 16
        ctx->r21 = S32(ctx->r7 << 16);
            goto L_800CC360;
    }
    // 0x800CC354: sll         $s5, $a3, 16
    ctx->r21 = S32(ctx->r7 << 16);
    // 0x800CC358: b           L_800CC364
    // 0x800CC35C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_800CC364;
    // 0x800CC35C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_800CC360:
    // 0x800CC360: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800CC364:
    // 0x800CC364: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC368: sra         $t8, $s5, 16
    ctx->r24 = S32(SIGNED(ctx->r21) >> 16);
    // 0x800CC36C: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
    // 0x800CC370: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x800CC374: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800CC378: bgez        $a0, L_800CC384
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800CC37C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800CC384;
    }
    // 0x800CC37C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800CC380: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800CC384:
    // 0x800CC384: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800CC388: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800CC38C: sra         $t9, $fp, 4
    ctx->r25 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800CC390: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800CC394: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800CC398: ori         $t6, $s4, 0x2
    ctx->r14 = ctx->r20 | 0X2;
    // 0x800CC39C: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800CC3A0: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800CC3A4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800CC3A8: or          $fp, $t9, $zero
    ctx->r30 = ctx->r25 | 0;
    // 0x800CC3AC: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800CC3B0: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x800CC3B4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800CC3B8: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800CC3BC: jal         0x800CC020
    // 0x800CC3C0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    static_3_800CC020(rdram, ctx);
        goto after_1;
    // 0x800CC3C0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_1:
    // 0x800CC3C4: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC3C8: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x800CC3CC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CC3D0: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800CC3D4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC3D8: addu        $t8, $t9, $a3
    ctx->r24 = ADD32(ctx->r25, ctx->r7);
    // 0x800CC3DC: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800CC3E0: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800CC3E4: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800CC3E8: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x800CC3EC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CC3F0: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800CC3F4: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800CC3F8: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800CC3FC: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800CC400: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CC404: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800CC408: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800CC40C: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CC410: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800CC414: bne         $at, $zero, L_800CC300
    if (ctx->r1 != 0) {
        // 0x800CC418: addiu       $t2, $v0, 0x8
        ctx->r10 = ADD32(ctx->r2, 0X8);
            goto L_800CC300;
    }
    // 0x800CC418: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
L_800CC41C:
    // 0x800CC41C: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC420: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800CC424: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800CC428: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800CC42C: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800CC430: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800CC434: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800CC438: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800CC43C: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800CC440: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800CC444: b           L_800CC5BC
    // 0x800CC448: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800CC5BC;
    // 0x800CC448: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800CC44C:
    // 0x800CC44C: lw          $v0, 0x28($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X28);
    // 0x800CC450: sra         $t7, $fp, 4
    ctx->r15 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800CC454: lw          $t9, 0x44($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X44);
    // 0x800CC458: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x800CC45C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800CC460: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800CC464: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x800CC468: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800CC46C: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x800CC470: subu        $t6, $t3, $t8
    ctx->r14 = SUB32(ctx->r11, ctx->r24);
    // 0x800CC474: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x800CC478: bgez        $v1, L_800CC484
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800CC47C: sll         $a1, $fp, 4
        ctx->r5 = S32(ctx->r30 << 4);
            goto L_800CC484;
    }
    // 0x800CC47C: sll         $a1, $fp, 4
    ctx->r5 = S32(ctx->r30 << 4);
    // 0x800CC480: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CC484:
    // 0x800CC484: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800CC488: mflo        $v0
    ctx->r2 = lo;
    // 0x800CC48C: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x800CC490: addu        $t4, $a1, $a2
    ctx->r12 = ADD32(ctx->r5, ctx->r6);
    // 0x800CC494: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CC498: beq         $at, $zero, L_800CC4A4
    if (ctx->r1 == 0) {
        // 0x800CC49C: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_800CC4A4;
    }
    // 0x800CC49C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800CC4A0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_800CC4A4:
    // 0x800CC4A4: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x800CC4A8: subu        $t6, $a0, $t8
    ctx->r14 = SUB32(ctx->r4, ctx->r24);
    // 0x800CC4AC: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CC4B0: beq         $at, $zero, L_800CC560
    if (ctx->r1 == 0) {
        // 0x800CC4B4: subu        $a2, $t1, $v1
        ctx->r6 = SUB32(ctx->r9, ctx->r3);
            goto L_800CC560;
    }
    // 0x800CC4B4: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    // 0x800CC4B8: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800CC4BC: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800CC4C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800CC4C4: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800CC4C8: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x800CC4CC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800CC4D0: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800CC4D4: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800CC4D8: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800CC4DC: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800CC4E0: subu        $s6, $a1, $a0
    ctx->r22 = SUB32(ctx->r5, ctx->r4);
    // 0x800CC4E4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800CC4E8: jal         0x800CC020
    // 0x800CC4EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    static_3_800CC020(rdram, ctx);
        goto after_2;
    // 0x800CC4EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_2:
    // 0x800CC4F0: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC4F4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800CC4F8: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800CC4FC: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800CC500: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800CC504: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800CC508: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800CC50C: beq         $v1, $zero, L_800CC528
    if (ctx->r3 == 0) {
        // 0x800CC510: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800CC528;
    }
    // 0x800CC510: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800CC514: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800CC518: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800CC51C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800CC520: b           L_800CC534
    // 0x800CC524: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_800CC534;
    // 0x800CC524: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_800CC528:
    // 0x800CC528: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800CC52C: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x800CC530: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800CC534:
    // 0x800CC534: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800CC538: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800CC53C: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800CC540: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800CC544: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800CC548: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800CC54C: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800CC550: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800CC554: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800CC558: b           L_800CC568
    // 0x800CC55C: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800CC568;
    // 0x800CC55C: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800CC560:
    // 0x800CC560: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800CC564: sw          $t3, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r11;
L_800CC568:
    // 0x800CC568: beq         $a0, $zero, L_800CC5B8
    if (ctx->r4 == 0) {
        // 0x800CC56C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800CC5B8;
    }
    // 0x800CC56C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800CC570: beq         $t5, $zero, L_800CC588
    if (ctx->r13 == 0) {
        // 0x800CC574: sw          $zero, 0x3C($s7)
        MEM_W(0X3C, ctx->r23) = 0;
            goto L_800CC588;
    }
    // 0x800CC574: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800CC578: subu        $v1, $t4, $a0
    ctx->r3 = SUB32(ctx->r12, ctx->r4);
    // 0x800CC57C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800CC580: b           L_800CC58C
    // 0x800CC584: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_800CC58C;
    // 0x800CC584: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800CC588:
    // 0x800CC588: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CC58C:
    // 0x800CC58C: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800CC590: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CC594: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC598: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800CC59C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800CC5A0: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800CC5A4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CC5A8: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800CC5AC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800CC5B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CC5B4: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_800CC5B8:
    // 0x800CC5B8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800CC5BC:
    // 0x800CC5BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800CC5C0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800CC5C4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800CC5C8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800CC5CC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800CC5D0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800CC5D4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800CC5D8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800CC5DC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800CC5E0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800CC5E4: jr          $ra
    // 0x800CC5E8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800CC5E8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void music_table_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000216C: beq         $a0, $zero, L_80002180
    if (ctx->r4 == 0) {
        // 0x80002170: lui         $t6, 0x8011
        ctx->r14 = S32(0X8011 << 16);
            goto L_80002180;
    }
    // 0x80002170: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80002174: lw          $t6, 0x629C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X629C);
    // 0x80002178: nop

    // 0x8000217C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_80002180:
    // 0x80002180: beq         $a1, $zero, L_80002194
    if (ctx->r5 == 0) {
        // 0x80002184: lui         $t7, 0x8011
        ctx->r15 = S32(0X8011 << 16);
            goto L_80002194;
    }
    // 0x80002184: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002188: lw          $t7, 0x62AC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62AC);
    // 0x8000218C: nop

    // 0x80002190: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_80002194:
    // 0x80002194: beq         $a2, $zero, L_800021A8
    if (ctx->r6 == 0) {
        // 0x80002198: lui         $t8, 0x8011
        ctx->r24 = S32(0X8011 << 16);
            goto L_800021A8;
    }
    // 0x80002198: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8000219C: lw          $t8, 0x62A4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X62A4);
    // 0x800021A0: nop

    // 0x800021A4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800021A8:
    // 0x800021A8: jr          $ra
    // 0x800021AC: nop

    return;
    // 0x800021AC: nop

;}
RECOMP_FUNC void debug_render_checkpoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BB9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001BBA0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8001BBA4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001BBA8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8001BBAC: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8001BBB0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001BBB4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001BBB8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001BBBC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8001BBC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001BBC4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8001BBC8: jal         0x8007B918
    // 0x8001BBCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x8001BBCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8001BBD0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8001BBD4: addiu       $s4, $s4, -0x4BB0
    ctx->r20 = ADD32(ctx->r20, -0X4BB0);
    // 0x8001BBD8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8001BBDC: nop

    // 0x8001BBE0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8001BBE4: bne         $at, $zero, L_8001BC58
    if (ctx->r1 != 0) {
        // 0x8001BBE8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001BC58;
    }
    // 0x8001BBE8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001BBEC: blez        $v0, L_8001BC24
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001BBF0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001BC24;
    }
    // 0x8001BBF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001BBF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001BBF8:
    // 0x8001BBF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001BBFC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8001BC00: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8001BC04: jal         0x8001BC74
    // 0x8001BC08: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    debug_render_checkpoint_node(rdram, ctx);
        goto after_1;
    // 0x8001BC08: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_1:
    // 0x8001BC0C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8001BC10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001BC14: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BC18: bne         $at, $zero, L_8001BBF8
    if (ctx->r1 != 0) {
        // 0x8001BC1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001BBF8;
    }
    // 0x8001BC1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001BC20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001BC24:
    // 0x8001BC24: blez        $v0, L_8001BC54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001BC28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001BC54;
    }
    // 0x8001BC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001BC2C:
    // 0x8001BC2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001BC30: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8001BC34: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8001BC38: jal         0x8001BC74
    // 0x8001BC3C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    debug_render_checkpoint_node(rdram, ctx);
        goto after_2;
    // 0x8001BC3C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_2:
    // 0x8001BC40: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8001BC44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001BC48: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001BC4C: bne         $at, $zero, L_8001BC2C
    if (ctx->r1 != 0) {
        // 0x8001BC50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001BC2C;
    }
    // 0x8001BC50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001BC54:
    // 0x8001BC54: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001BC58:
    // 0x8001BC58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001BC5C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001BC60: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001BC64: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8001BC68: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8001BC6C: jr          $ra
    // 0x8001BC70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001BC70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void trophyround_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80098C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098C98: jal         0x800C478C
    // 0x80098C9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x80098C9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80098CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098CA8: jr          $ra
    // 0x80098CAC: nop

    return;
    // 0x80098CAC: nop

;}
RECOMP_FUNC void obj_init_skycontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF98: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CF9C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003CFA0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003CFA4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CFA8: nop

    // 0x8003CFAC: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003CFB0: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x8003CFB4: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CFB8: nop

    // 0x8003CFBC: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003CFC0: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003CFC4: nop

    // 0x8003CFC8: sw          $t1, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r9;
    // 0x8003CFCC: lbu         $t2, 0x9($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X9);
    // 0x8003CFD0: jr          $ra
    // 0x8003CFD4: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
    return;
    // 0x8003CFD4: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void mtxf_from_translation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070838: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8007083C: addiu       $t1, $t0, 0x40
    ctx->r9 = ADD32(ctx->r8, 0X40);
L_80070840:
    // 0x80070840: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80070844: bne         $t1, $t0, L_80070840
    if (ctx->r9 != ctx->r8) {
        // 0x80070848: sw          $zero, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = 0;
            goto L_80070840;
    }
    // 0x80070848: sw          $zero, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = 0;
    // 0x8007084C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80070850: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070854: nop

    // 0x80070858: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x8007085C: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80070860: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x80070864: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x80070868: sw          $a1, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r5;
    // 0x8007086C: sw          $a2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r6;
    // 0x80070870: jr          $ra
    // 0x80070874: sw          $a3, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r7;
    return;
    // 0x80070874: sw          $a3, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void obj_loop_torch_mist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034B8C: lw          $t7, 0x78($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X78);
    // 0x80034B90: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80034B94: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034B98: mflo        $t8
    ctx->r24 = lo;
    // 0x80034B9C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80034BA0: jr          $ra
    // 0x80034BA4: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    return;
    // 0x80034BA4: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void sound_jingle_tempo_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800017D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800017D8: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800017DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800017E0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800017E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800017E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800017EC: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800017F0: lwc1        $f16, 0x4F7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4F7C);
    // 0x800017F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800017F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800017FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001800: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80001804: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80001808: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000180C: nop

    // 0x80001810: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80001814: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001818: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000181C: nop

    // 0x80001820: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80001824: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80001828: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000182C: jal         0x800C7F40
    // 0x80001830: nop

    alCSPSetTempo(rdram, ctx);
        goto after_0;
    // 0x80001830: nop

    after_0:
    // 0x80001834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000183C: jr          $ra
    // 0x80001840: nop

    return;
    // 0x80001840: nop

;}
RECOMP_FUNC void func_80000C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000C70: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80000C74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000C78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000C7C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80000C80: jal         0x80063CD0
    // 0x80000C84: nop

    func_80063A90(rdram, ctx);
        goto after_0;
    // 0x80000C84: nop

    after_0:
    // 0x80000C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000C8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000C90: jr          $ra
    // 0x80000C94: nop

    return;
    // 0x80000C94: nop

;}
RECOMP_FUNC void update_camera_hovercraft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048EA4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80048EA8: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x80048EAC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80048EB0: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80048EB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80048EB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80048EBC: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80048EC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80048EC4: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x80048EC8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80048ECC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80048ED0: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80048ED4: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x80048ED8: jal         0x80066450
    // 0x80048EDC: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x80048EDC: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80048EE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80048EE4: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80048EE8: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80048EEC: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80048EF0: bne         $v0, $a2, L_80048F14
    if (ctx->r2 != ctx->r6) {
        // 0x80048EF4: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80048F14;
    }
    // 0x80048EF4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80048EF8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80048EFC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80048F00: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x80048F04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80048F08: addiu       $t7, $zero, 0x280
    ctx->r15 = ADD32(0, 0X280);
    // 0x80048F0C: b           L_80048F30
    // 0x80048F10: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80048F30;
    // 0x80048F10: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80048F14:
    // 0x80048F14: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80048F18: bne         $at, $zero, L_80048F30
    if (ctx->r1 != 0) {
        // 0x80048F1C: lui         $at, 0x4302
        ctx->r1 = S32(0X4302 << 16);
            goto L_80048F30;
    }
    // 0x80048F1C: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80048F20: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80048F24: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80048F28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80048F2C: nop

L_80048F30:
    // 0x80048F30: addiu       $s0, $s0, -0x2578
    ctx->r16 = ADD32(ctx->r16, -0X2578);
    // 0x80048F34: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80048F38: lwc1        $f16, 0xB8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x80048F3C: lbu         $v0, 0x3B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3B);
    // 0x80048F40: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80048F44: beq         $v0, $a2, L_80048F64
    if (ctx->r2 == ctx->r6) {
        // 0x80048F48: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80048F64;
    }
    // 0x80048F48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048F4C: beq         $v0, $at, L_80048F74
    if (ctx->r2 == ctx->r1) {
        // 0x80048F50: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80048F74;
    }
    // 0x80048F50: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80048F54: beq         $v0, $at, L_80048F94
    if (ctx->r2 == ctx->r1) {
        // 0x80048F58: lui         $at, 0x4254
        ctx->r1 = S32(0X4254 << 16);
            goto L_80048F94;
    }
    // 0x80048F58: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x80048F5C: b           L_80048FC8
    // 0x80048F60: lb          $t8, 0x1E4($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1E4);
        goto L_80048FC8;
    // 0x80048F60: lb          $t8, 0x1E4($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1E4);
L_80048F64:
    // 0x80048F64: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80048F68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048F6C: b           L_80048FC4
    // 0x80048F70: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
        goto L_80048FC4;
    // 0x80048F70: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
L_80048F74:
    // 0x80048F74: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80048F78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048F7C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80048F80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80048F84: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80048F88: b           L_80048FC4
    // 0x80048F8C: sub.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f8.fl;
        goto L_80048FC4;
    // 0x80048F8C: sub.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80048F90: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
L_80048F94:
    // 0x80048F94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80048F98: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80048F9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048FA0: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80048FA4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80048FA8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048FAC: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80048FB0: sub.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80048FB4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80048FB8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80048FBC: sub.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80048FC0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_80048FC4:
    // 0x80048FC4: lb          $t8, 0x1E4($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1E4);
L_80048FC8:
    // 0x80048FC8: nop

    // 0x80048FCC: bne         $t8, $zero, L_80049084
    if (ctx->r24 != 0) {
        // 0x80048FD0: nop
    
            goto L_80049084;
    }
    // 0x80048FD0: nop

    // 0x80048FD4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80048FD8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80048FDC: lh          $v0, 0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X2);
    // 0x80048FE0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80048FE4: blez        $v0, L_80049008
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80048FE8: nop
    
            goto L_80049008;
    }
    // 0x80048FE8: nop

    // 0x80048FEC: addiu       $v0, $v0, -0x61C
    ctx->r2 = ADD32(ctx->r2, -0X61C);
    // 0x80048FF0: bgez        $v0, L_80049000
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80048FF4: sra         $t0, $v0, 1
        ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80049000;
    }
    // 0x80048FF4: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80048FF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80048FFC: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
L_80049000:
    // 0x80049000: b           L_80049018
    // 0x80049004: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80049018;
    // 0x80049004: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80049008:
    // 0x80049008: addiu       $v0, $v0, 0x61C
    ctx->r2 = ADD32(ctx->r2, 0X61C);
    // 0x8004900C: blez        $v0, L_80049018
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80049010: nop
    
            goto L_80049018;
    }
    // 0x80049010: nop

    // 0x80049014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80049018:
    // 0x80049018: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x8004901C: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // 0x80049020: andi        $t2, $a0, 0xFFFF
    ctx->r10 = ctx->r4 & 0XFFFF;
    // 0x80049024: subu        $v1, $v0, $t2
    ctx->r3 = SUB32(ctx->r2, ctx->r10);
    // 0x80049028: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004902C: bne         $at, $zero, L_8004903C
    if (ctx->r1 != 0) {
        // 0x80049030: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004903C;
    }
    // 0x80049030: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80049034: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80049038: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004903C:
    // 0x8004903C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80049040: beq         $at, $zero, L_8004904C
    if (ctx->r1 == 0) {
        // 0x80049044: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004904C;
    }
    // 0x80049044: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80049048: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004904C:
    // 0x8004904C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80049050: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80049054: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80049058: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004905C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049060: nop

    // 0x80049064: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80049068: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x8004906C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80049070: multu       $v1, $t4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80049074: mflo        $t5
    ctx->r13 = lo;
    // 0x80049078: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8004907C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80049080: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
L_80049084:
    // 0x80049084: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80049088: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8004908C: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x80049090: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80049094: jal         0x80066450
    // 0x80049098: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80049098: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8004909C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800490A0: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800490A4: lwc1        $f0, 0x2C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x800490A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800490AC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800490B0: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x800490B4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800490B8: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800490BC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800490C0: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800490C4: bc1f        L_80049114
    if (!c1cs) {
        // 0x800490C8: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80049114;
    }
    // 0x800490C8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800490CC: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800490D0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800490D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800490D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800490DC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800490E0: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800490E4: lwc1        $f11, 0x6A28($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6A28);
    // 0x800490E8: lwc1        $f10, 0x6A2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6A2C);
    // 0x800490EC: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x800490F0: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800490F4: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x800490F8: nop

    // 0x800490FC: bc1f        L_8004910C
    if (!c1cs) {
        // 0x80049100: nop
    
            goto L_8004910C;
    }
    // 0x80049100: nop

    // 0x80049104: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80049108: nop

L_8004910C:
    // 0x8004910C: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80049110: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80049114:
    // 0x80049114: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80049118: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004911C: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80049120: lw          $t8, -0x2540($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2540);
    // 0x80049124: nop

    // 0x80049128: bne         $t8, $zero, L_8004917C
    if (ctx->r24 != 0) {
        // 0x8004912C: add.s       $f14, $f14, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
            goto L_8004917C;
    }
    // 0x8004912C: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80049130: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80049134: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80049138: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x8004913C: jal         0x8000C8B4
    // 0x80049140: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    normalise_time(rdram, ctx);
        goto after_2;
    // 0x80049140: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80049144: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80049148: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004914C: lb          $v1, 0x1D3($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1D3);
    // 0x80049150: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80049154: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80049158: beq         $at, $zero, L_8004916C
    if (ctx->r1 == 0) {
        // 0x8004915C: lui         $at, 0xC1F0
        ctx->r1 = S32(0XC1F0 << 16);
            goto L_8004916C;
    }
    // 0x8004915C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80049160: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80049164: b           L_8004917C
    // 0x80049168: nop

        goto L_8004917C;
    // 0x80049168: nop

L_8004916C:
    // 0x8004916C: blez        $v1, L_8004917C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80049170: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8004917C;
    }
    // 0x80049170: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80049174: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80049178: nop

L_8004917C:
    // 0x8004917C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80049180: lw          $t9, -0x2540($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2540);
    // 0x80049184: nop

    // 0x80049188: slti        $at, $t9, 0x51
    ctx->r1 = SIGNED(ctx->r25) < 0X51 ? 1 : 0;
    // 0x8004918C: bne         $at, $zero, L_800491AC
    if (ctx->r1 != 0) {
        // 0x80049190: nop
    
            goto L_800491AC;
    }
    // 0x80049190: nop

    // 0x80049194: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80049198: nop

    // 0x8004919C: swc1        $f14, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f14.u32l;
    // 0x800491A0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800491A4: nop

    // 0x800491A8: swc1        $f18, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f18.u32l;
L_800491AC:
    // 0x800491AC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800491B0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800491B4: lwc1        $f0, 0x1C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800491B8: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800491BC: sub.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800491C0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800491C4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800491C8: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800491CC: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800491D0: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x800491D4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800491D8: swc1        $f6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f6.u32l;
    // 0x800491DC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800491E0: nop

    // 0x800491E4: lwc1        $f2, 0x20($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800491E8: nop

    // 0x800491EC: sub.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800491F0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x800491F4: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800491F8: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x800491FC: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x80049200: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80049204: swc1        $f4, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f4.u32l;
    // 0x80049208: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8004920C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80049210: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x80049214: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80049218: subu        $a0, $t3, $t4
    ctx->r4 = SUB32(ctx->r11, ctx->r12);
    // 0x8004921C: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x80049220: jal         0x80070A04
    // 0x80049224: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80049224: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_3:
    // 0x80049228: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8004922C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80049230: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80049234: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80049238: nop

    // 0x8004923C: subu        $a0, $t8, $t9
    ctx->r4 = SUB32(ctx->r24, ctx->r25);
    // 0x80049240: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80049244: jal         0x80070A38
    // 0x80049248: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    coss_f(rdram, ctx);
        goto after_4;
    // 0x80049248: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    after_4:
    // 0x8004924C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80049250: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80049254: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80049258: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8004925C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80049260: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80049264: ori         $t3, $zero, 0x8000
    ctx->r11 = 0 | 0X8000;
    // 0x80049268: lh          $t2, 0x196($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X196);
    // 0x8004926C: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80049270: subu        $a0, $t3, $t2
    ctx->r4 = SUB32(ctx->r11, ctx->r10);
    // 0x80049274: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x80049278: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8004927C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80049280: jal         0x80070A04
    // 0x80049284: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    sins_f(rdram, ctx);
        goto after_5;
    // 0x80049284: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80049288: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8004928C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80049290: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80049294: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x80049298: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004929C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800492A0: lh          $t7, 0x196($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X196);
    // 0x800492A4: nop

    // 0x800492A8: subu        $a0, $t8, $t7
    ctx->r4 = SUB32(ctx->r24, ctx->r15);
    // 0x800492AC: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x800492B0: jal         0x80070A38
    // 0x800492B4: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    coss_f(rdram, ctx);
        goto after_6;
    // 0x800492B4: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_6:
    // 0x800492B8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800492BC: lh          $t3, -0x24FA($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X24FA);
    // 0x800492C0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800492C4: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800492C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800492CC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800492D0: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800492D4: lwc1        $f8, 0x1C($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800492D8: lui         $at, 0x4620
    ctx->r1 = S32(0X4620 << 16);
    // 0x800492DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800492E0: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800492E4: nop

    // 0x800492E8: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800492EC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800492F0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800492F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800492F8: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800492FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80049300: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80049304: sub.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d - ctx->f10.d;
    // 0x80049308: lwc1        $f6, 0x38($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X38);
    // 0x8004930C: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x80049310: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80049314: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80049318: nop

    // 0x8004931C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80049320: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80049324: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80049328: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8004932C: lwc1        $f6, 0x30($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X30);
    // 0x80049330: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80049334: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80049338: lwc1        $f12, 0xC8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x8004933C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80049340: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80049344: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80049348: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x8004934C: mul.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80049350: sub.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80049354: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80049358: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x8004935C: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80049360: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x80049364: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80049368: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8004936C: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80049370: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80049374: sub.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d - ctx->f10.d;
    // 0x80049378: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004937C: swc1        $f6, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f6.u32l;
    // 0x80049380: jal         0x80070A04
    // 0x80049384: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    sins_f(rdram, ctx);
        goto after_7;
    // 0x80049384: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x80049388: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8004938C: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80049390: lwc1        $f8, 0xC8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x80049394: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80049398: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8004939C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800493A0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800493A4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800493A8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800493AC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800493B0: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800493B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800493B8: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x800493BC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800493C0: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800493C4: lwc1        $f12, 0x10($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800493C8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800493CC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800493D0: sub.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x800493D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800493D8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800493DC: nop

    // 0x800493E0: bc1f        L_80049400
    if (!c1cs) {
        // 0x800493E4: nop
    
            goto L_80049400;
    }
    // 0x800493E4: nop

    // 0x800493E8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800493EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800493F0: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800493F4: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800493F8: b           L_8004945C
    // 0x800493FC: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
        goto L_8004945C;
    // 0x800493FC: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_80049400:
    // 0x80049400: lw          $t6, -0x2544($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2544);
    // 0x80049404: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049408: bne         $t6, $at, L_80049428
    if (ctx->r14 != ctx->r1) {
        // 0x8004940C: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_80049428;
    }
    // 0x8004940C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80049410: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80049414: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80049418: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8004941C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80049420: b           L_80049440
    // 0x80049424: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
        goto L_80049440;
    // 0x80049424: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_80049428:
    // 0x80049428: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8004942C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80049430: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80049434: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80049438: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8004943C: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
L_80049440:
    // 0x80049440: lb          $t8, 0x1D3($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1D3);
    // 0x80049444: nop

    // 0x80049448: beq         $t8, $zero, L_8004945C
    if (ctx->r24 == 0) {
        // 0x8004944C: nop
    
            goto L_8004945C;
    }
    // 0x8004944C: nop

    // 0x80049450: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80049454: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x80049458: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_8004945C:
    // 0x8004945C: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80049460: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80049464: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x80049468: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8004946C: nop

    // 0x80049470: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x80049474: lw          $t9, -0x2540($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2540);
    // 0x80049478: nop

    // 0x8004947C: beq         $t9, $zero, L_80049494
    if (ctx->r25 == 0) {
        // 0x80049480: nop
    
            goto L_80049494;
    }
    // 0x80049480: nop

    // 0x80049484: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80049488: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8004948C: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80049490: swc1        $f8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f8.u32l;
L_80049494:
    // 0x80049494: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x80049498: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x8004949C: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x800494A0: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x800494A4: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800494A8: jal         0x80070A38
    // 0x800494AC: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    coss_f(rdram, ctx);
        goto after_8;
    // 0x800494AC: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    after_8:
    // 0x800494B0: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800494B4: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800494B8: lwc1        $f10, 0x14($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X14);
    // 0x800494BC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800494C0: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800494C4: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800494C8: swc1        $f4, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f4.u32l;
    // 0x800494CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800494D0: lh          $t5, 0x196($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X196);
    // 0x800494D4: nop

    // 0x800494D8: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x800494DC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800494E0: nop

    // 0x800494E4: lwc1        $f12, 0xC($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800494E8: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800494EC: lw          $a2, 0x14($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X14);
    // 0x800494F0: jal         0x80029F58
    // 0x800494F4: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_9;
    // 0x800494F4: nop

    after_9:
    // 0x800494F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800494FC: beq         $v0, $at, L_80049514
    if (ctx->r2 == ctx->r1) {
        // 0x80049500: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80049514;
    }
    // 0x80049500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80049504: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80049508: nop

    // 0x8004950C: sh          $v0, 0x34($t8)
    MEM_H(0X34, ctx->r24) = ctx->r2;
    // 0x80049510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80049514:
    // 0x80049514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80049518: jr          $ra
    // 0x8004951C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8004951C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void tex_palette_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F3B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007F3B8: lw          $t8, 0x68CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X68CC);
    // 0x8007F3BC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8007F3C0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8007F3C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007F3C8: jr          $ra
    // 0x8007F3CC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x8007F3CC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void func_8002F2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F2EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002F2F0: lw          $v1, -0x4968($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4968);
    // 0x8002F2F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002F2F8: blez        $v1, L_8002F39C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002F2FC: addiu       $a0, $t6, -0x4960
        ctx->r4 = ADD32(ctx->r14, -0X4960);
            goto L_8002F39C;
    }
    // 0x8002F2FC: addiu       $a0, $t6, -0x4960
    ctx->r4 = ADD32(ctx->r14, -0X4960);
    // 0x8002F300: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8002F304: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x8002F308: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002F30C: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8002F310: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8002F314: lwc1        $f18, -0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, -0X10);
    // 0x8002F318: beq         $at, $zero, L_8002F368
    if (ctx->r1 == 0) {
        // 0x8002F31C: nop
    
            goto L_8002F368;
    }
    // 0x8002F31C: nop

L_8002F320:
    // 0x8002F320: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F324: lwc1        $f14, -0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8002F328: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F32C: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F330: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F334: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F338: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F33C: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F340: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002F344: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8002F348: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F34C: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8002F350: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F354: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F358: nop

    // 0x8002F35C: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F360: bne         $at, $zero, L_8002F320
    if (ctx->r1 != 0) {
        // 0x8002F364: swc1        $f8, -0x1C($a0)
        MEM_W(-0X1C, ctx->r4) = ctx->f8.u32l;
            goto L_8002F320;
    }
    // 0x8002F364: swc1        $f8, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = ctx->f8.u32l;
L_8002F368:
    // 0x8002F368: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F36C: lwc1        $f14, -0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8002F370: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F374: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F378: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F37C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F380: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F384: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F388: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F38C: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F390: nop

    // 0x8002F394: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F398: swc1        $f8, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f8.u32l;
L_8002F39C:
    // 0x8002F39C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002F3A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002F3A4: addiu       $t0, $t0, -0x4750
    ctx->r8 = ADD32(ctx->r8, -0X4750);
    // 0x8002F3A8: addiu       $a1, $a1, -0x4760
    ctx->r5 = ADD32(ctx->r5, -0X4760);
    // 0x8002F3AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8002F3B0:
    // 0x8002F3B0: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x8002F3B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002F3B8: blez        $a2, L_8002F46C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8002F3BC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8002F46C;
    }
    // 0x8002F3BC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8002F3C0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F3C4: addiu       $t9, $t9, -0x4750
    ctx->r25 = ADD32(ctx->r25, -0X4750);
    // 0x8002F3C8: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x8002F3CC: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8002F3D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F3D4: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002F3D8: lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC);
    // 0x8002F3DC: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002F3E0: beq         $at, $zero, L_8002F434
    if (ctx->r1 == 0) {
        // 0x8002F3E4: nop
    
            goto L_8002F434;
    }
    // 0x8002F3E4: nop

L_8002F3E8:
    // 0x8002F3E8: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F3EC: lwc1        $f14, 0x8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F3F0: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F3F4: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F3F8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F3FC: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F400: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F404: lwc1        $f18, 0x20($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X20);
    // 0x8002F408: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F40C: lw          $v0, 0x2C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X2C);
    // 0x8002F410: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F414: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002F418: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F41C: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x8002F420: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F424: nop

    // 0x8002F428: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F42C: bne         $at, $zero, L_8002F3E8
    if (ctx->r1 != 0) {
        // 0x8002F430: swc1        $f8, -0x1C($a3)
        MEM_W(-0X1C, ctx->r7) = ctx->f8.u32l;
            goto L_8002F3E8;
    }
    // 0x8002F430: swc1        $f8, -0x1C($a3)
    MEM_W(-0X1C, ctx->r7) = ctx->f8.u32l;
L_8002F434:
    // 0x8002F434: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F438: lwc1        $f14, 0x8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F43C: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F440: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F444: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F448: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F44C: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F450: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x8002F454: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F458: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F45C: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F460: nop

    // 0x8002F464: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F468: swc1        $f8, -0x1C($a3)
    MEM_W(-0X1C, ctx->r7) = ctx->f8.u32l;
L_8002F46C:
    // 0x8002F46C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8002F470: bne         $a1, $t0, L_8002F3B0
    if (ctx->r5 != ctx->r8) {
        // 0x8002F474: addiu       $a0, $a0, 0x20
        ctx->r4 = ADD32(ctx->r4, 0X20);
            goto L_8002F3B0;
    }
    // 0x8002F474: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8002F478: jr          $ra
    // 0x8002F47C: nop

    return;
    // 0x8002F47C: nop

;}
RECOMP_FUNC void load_level_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006DD80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DD84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006DD88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006DD8C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006DD90: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006DD94: jal         0x800712F0
    // 0x8006DD98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006DD98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006DD9C: jal         0x800660E0
    // 0x8006DDA0: nop

    cam_init(rdram, ctx);
        goto after_1;
    // 0x8006DDA0: nop

    after_1:
    // 0x8006DDA4: jal         0x800C35A0
    // 0x8006DDA8: nop

    load_game_text_table(rdram, ctx);
        goto after_2;
    // 0x8006DDA8: nop

    after_2:
    // 0x8006DDAC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8006DDB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DDB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006DDB8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8006DDBC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DDC0: jal         0x8006B490
    // 0x8006DDC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    level_load(rdram, ctx);
        goto after_3;
    // 0x8006DDC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x8006DDC8: jal         0x80066450
    // 0x8006DDCC: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_4;
    // 0x8006DDCC: nop

    after_4:
    // 0x8006DDD0: jal         0x8009F230
    // 0x8006DDD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    hud_init(rdram, ctx);
        goto after_5;
    // 0x8006DDD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8006DDD8: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8006DDDC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006DDE0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8006DDE4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8006DDE8: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // 0x8006DDEC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x8006DDF0: jal         0x800AEC88
    // 0x8006DDF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    init_particle_buffers(rdram, ctx);
        goto after_6;
    // 0x8006DDF4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_6:
    // 0x8006DDF8: jal         0x8001BF54
    // 0x8006DDFC: nop

    ainode_update(rdram, ctx);
        goto after_7;
    // 0x8006DDFC: nop

    after_7:
    // 0x8006DE00: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006DE04: jal         0x800CD7C0
    // 0x8006DE08: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_8;
    // 0x8006DE08: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x8006DE0C: jal         0x800712F0
    // 0x8006DE10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_9;
    // 0x8006DE10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x8006DE14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DE18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006DE1C: jr          $ra
    // 0x8006DE20: nop

    return;
    // 0x8006DE20: nop

;}
RECOMP_FUNC void alSynAddPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9938: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C993C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800C9940: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C9944: jal         0x800C9F90
    // 0x800C9948: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9948: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C994C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800C9950: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9954: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C9958: lw          $t6, 0x20($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X20);
    // 0x800C995C: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x800C9960: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C9964: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800C9968: jal         0x800C9F90
    // 0x800C996C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800C996C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    after_1:
    // 0x800C9970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9978: jr          $ra
    // 0x800C997C: nop

    return;
    // 0x800C997C: nop

;}
RECOMP_FUNC void level_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C13C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C144: jal         0x8006C3A4
    // 0x8006C148: nop

    aitable_free(rdram, ctx);
        goto after_0;
    // 0x8006C148: nop

    after_0:
    // 0x8006C14C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006C150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006C154: jal         0x80077F84
    // 0x8006C158: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bgdraw_primcolour(rdram, ctx);
        goto after_1;
    // 0x8006C158: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8006C15C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C160: lw          $a0, 0x16E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E8);
    // 0x8006C164: jal         0x80071380
    // 0x8006C168: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x8006C168: nop

    after_2:
    // 0x8006C16C: jal         0x800049D8
    // 0x8006C170: nop

    sndp_stop_all_looped(rdram, ctx);
        goto after_3;
    // 0x8006C170: nop

    after_3:
    // 0x8006C174: jal         0x80001844
    // 0x8006C178: nop

    music_stop(rdram, ctx);
        goto after_4;
    // 0x8006C178: nop

    after_4:
    // 0x8006C17C: jal         0x800018E0
    // 0x8006C180: nop

    music_jingle_stop(rdram, ctx);
        goto after_5;
    // 0x8006C180: nop

    after_5:
    // 0x8006C184: jal         0x800012E8
    // 0x8006C188: nop

    music_channel_reset_all(rdram, ctx);
        goto after_6;
    // 0x8006C188: nop

    after_6:
    // 0x8006C18C: jal         0x80031BA0
    // 0x8006C190: nop

    lights_free(rdram, ctx);
        goto after_7;
    // 0x8006C190: nop

    after_7:
    // 0x8006C194: jal         0x8002C814
    // 0x8006C198: nop

    free_track(rdram, ctx);
        goto after_8;
    // 0x8006C198: nop

    after_8:
    // 0x8006C19C: jal         0x80008174
    // 0x8006C1A0: nop

    audspat_reset(rdram, ctx);
        goto after_9;
    // 0x8006C1A0: nop

    after_9:
    // 0x8006C1A4: jal         0x80000968
    // 0x8006C1A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_10;
    // 0x8006C1A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8006C1AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C1B0: lw          $v0, 0x16E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16E8);
    // 0x8006C1B4: nop

    // 0x8006C1B8: lh          $t6, 0x90($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X90);
    // 0x8006C1BC: nop

    // 0x8006C1C0: blez        $t6, L_8006C1DC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006C1C4: nop
    
            goto L_8006C1DC;
    }
    // 0x8006C1C4: nop

    // 0x8006C1C8: jal         0x800AB8BC
    // 0x8006C1CC: nop

    weather_free(rdram, ctx);
        goto after_11;
    // 0x8006C1CC: nop

    after_11:
    // 0x8006C1D0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C1D4: lw          $v0, 0x16E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16E8);
    // 0x8006C1D8: nop

L_8006C1DC:
    // 0x8006C1DC: lb          $t7, 0x49($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X49);
    // 0x8006C1E0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006C1E4: bne         $t7, $at, L_8006C1FC
    if (ctx->r15 != ctx->r1) {
        // 0x8006C1E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006C1FC;
    }
    // 0x8006C1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C1EC: lw          $a0, 0xA4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XA4);
    // 0x8006C1F0: jal         0x8007B70C
    // 0x8006C1F4: nop

    tex_free(rdram, ctx);
        goto after_12;
    // 0x8006C1F4: nop

    after_12:
    // 0x8006C1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006C1FC:
    // 0x8006C1FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C200: jr          $ra
    // 0x8006C204: nop

    return;
    // 0x8006C204: nop

;}
RECOMP_FUNC void obj_loop_gbparkwarden(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ACE0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003ACE4: jr          $ra
    // 0x8003ACE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003ACE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void sound_update_queue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000D00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80000D04: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80000D08: addiu       $a1, $a1, 0x62BC
    ctx->r5 = ADD32(ctx->r5, 0X62BC);
    // 0x80000D0C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80000D10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000D14: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x80000D18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80000D1C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80000D20: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80000D24: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80000D28: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80000D2C: blez        $v1, L_80000DBC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80000D30: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80000DBC;
    }
    // 0x80000D30: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80000D34: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000D38: addiu       $v0, $v0, 0x62B8
    ctx->r2 = ADD32(ctx->r2, 0X62B8);
    // 0x80000D3C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80000D40: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80000D44: addu        $t8, $t6, $s0
    ctx->r24 = ADD32(ctx->r14, ctx->r16);
    // 0x80000D48: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80000D4C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80000D50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000D54: addiu       $a0, $a0, -0x3440
    ctx->r4 = ADD32(ctx->r4, -0X3440);
    // 0x80000D58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80000D5C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80000D60: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80000D64: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80000D68: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80000D6C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80000D70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000D74: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80000D78: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80000D7C: nop

    // 0x80000D80: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80000D84: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x80000D88: nop

    // 0x80000D8C: bc1f        L_80000DA4
    if (!c1cs) {
        // 0x80000D90: nop
    
            goto L_80000DA4;
    }
    // 0x80000D90: nop

    // 0x80000D94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80000D98: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80000D9C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80000DA0: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_80000DA4:
    // 0x80000DA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000DA8: lbu         $a0, -0x3458($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3458);
    // 0x80000DAC: jal         0x80001990
    // 0x80000DB0: nop

    music_volume_set(rdram, ctx);
        goto after_0;
    // 0x80000DB0: nop

    after_0:
    // 0x80000DB4: b           L_80000E44
    // 0x80000DB8: nop

        goto L_80000E44;
    // 0x80000DB8: nop

L_80000DBC:
    // 0x80000DBC: bgez        $v1, L_80000E44
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80000DC0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80000E44;
    }
    // 0x80000DC0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000DC4: addiu       $v0, $v0, 0x62B8
    ctx->r2 = ADD32(ctx->r2, 0X62B8);
    // 0x80000DC8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80000DCC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80000DD0: subu        $t1, $t9, $s0
    ctx->r9 = SUB32(ctx->r25, ctx->r16);
    // 0x80000DD4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80000DD8: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80000DDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000DE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80000DE4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80000DE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000DEC: addiu       $a0, $a0, -0x3440
    ctx->r4 = ADD32(ctx->r4, -0X3440);
    // 0x80000DF0: div.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80000DF4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80000DF8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80000DFC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80000E00: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80000E04: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80000E08: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80000E0C: nop

    // 0x80000E10: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80000E14: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80000E18: nop

    // 0x80000E1C: bc1f        L_80000E34
    if (!c1cs) {
        // 0x80000E20: nop
    
            goto L_80000E34;
    }
    // 0x80000E20: nop

    // 0x80000E24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80000E28: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80000E2C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80000E30: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_80000E34:
    // 0x80000E34: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000E38: lbu         $a0, -0x3458($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3458);
    // 0x80000E3C: jal         0x80001990
    // 0x80000E40: nop

    music_volume_set(rdram, ctx);
        goto after_1;
    // 0x80000E40: nop

    after_1:
L_80000E44:
    // 0x80000E44: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80000E48: addiu       $s3, $s3, -0x3438
    ctx->r19 = ADD32(ctx->r19, -0X3438);
    // 0x80000E4C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80000E50: nop

    // 0x80000E54: blez        $v0, L_80000EFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80000E58: nop
    
            goto L_80000EFC;
    }
    // 0x80000E58: nop

    // 0x80000E5C: blez        $v0, L_80000EFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80000E60: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80000EFC;
    }
    // 0x80000E60: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80000E64: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80000E68: addiu       $s1, $s1, 0x62C8
    ctx->r17 = ADD32(ctx->r17, 0X62C8);
    // 0x80000E6C: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
L_80000E70:
    // 0x80000E70: lh          $t2, 0x2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2);
    // 0x80000E74: nop

    // 0x80000E78: subu        $t3, $t2, $s4
    ctx->r11 = SUB32(ctx->r10, ctx->r20);
    // 0x80000E7C: sh          $t3, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r11;
    // 0x80000E80: lh          $t4, 0x2($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2);
    // 0x80000E84: nop

    // 0x80000E88: bgtz        $t4, L_80000EE8
    if (SIGNED(ctx->r12) > 0) {
        // 0x80000E8C: nop
    
            goto L_80000EE8;
    }
    // 0x80000E8C: nop

    // 0x80000E90: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80000E94: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80000E98: jal         0x80001D04
    // 0x80000E9C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80000E9C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    after_2:
    // 0x80000EA0: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80000EA4: nop

    // 0x80000EA8: addiu       $v0, $t5, -0x1
    ctx->r2 = ADD32(ctx->r13, -0X1);
    // 0x80000EAC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80000EB0: beq         $at, $zero, L_80000EF0
    if (ctx->r1 == 0) {
        // 0x80000EB4: sw          $v0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r2;
            goto L_80000EF0;
    }
    // 0x80000EB4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80000EB8: lhu         $t7, 0x8($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X8);
    // 0x80000EBC: lh          $t8, 0xA($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XA);
    // 0x80000EC0: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80000EC4: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    // 0x80000EC8: sh          $t8, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r24;
    // 0x80000ECC: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x80000ED0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80000ED4:
    // 0x80000ED4: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80000ED8: bne         $at, $zero, L_80000ED4
    if (ctx->r1 != 0) {
        // 0x80000EDC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80000ED4;
    }
    // 0x80000EDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80000EE0: b           L_80000EF4
    // 0x80000EE4: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_80000EF4;
    // 0x80000EE4: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
L_80000EE8:
    // 0x80000EE8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80000EEC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_80000EF0:
    // 0x80000EF0: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
L_80000EF4:
    // 0x80000EF4: bne         $at, $zero, L_80000E70
    if (ctx->r1 != 0) {
        // 0x80000EF8: nop
    
            goto L_80000E70;
    }
    // 0x80000EF8: nop

L_80000EFC:
    // 0x80000EFC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80000F00: addiu       $s0, $s0, -0x3460
    ctx->r16 = ADD32(ctx->r16, -0X3460);
    // 0x80000F04: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80000F08: lw          $a1, 0x627C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X627C);
    // 0x80000F0C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80000F10: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80000F14: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80000F18: addiu       $a3, $a3, 0x6308
    ctx->r7 = ADD32(ctx->r7, 0X6308);
    // 0x80000F1C: jal         0x8000232C
    // 0x80000F20: addiu       $a2, $a2, -0x3434
    ctx->r6 = ADD32(ctx->r6, -0X3434);
    music_sequence_init(rdram, ctx);
        goto after_3;
    // 0x80000F20: addiu       $a2, $a2, -0x3434
    ctx->r6 = ADD32(ctx->r6, -0X3434);
    after_3:
    // 0x80000F24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000F28: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80000F2C: lw          $a1, 0x6280($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6280);
    // 0x80000F30: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80000F34: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80000F38: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80000F3C: addiu       $a3, $a3, 0x6400
    ctx->r7 = ADD32(ctx->r7, 0X6400);
    // 0x80000F40: jal         0x8000232C
    // 0x80000F44: addiu       $a2, $a2, -0x3430
    ctx->r6 = ADD32(ctx->r6, -0X3430);
    music_sequence_init(rdram, ctx);
        goto after_4;
    // 0x80000F44: addiu       $a2, $a2, -0x3430
    ctx->r6 = ADD32(ctx->r6, -0X3430);
    after_4:
    // 0x80000F48: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80000F4C: addiu       $s1, $s1, 0x62B0
    ctx->r17 = ADD32(ctx->r17, 0X62B0);
    // 0x80000F50: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x80000F54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80000F58: bne         $t0, $at, L_80000FC0
    if (ctx->r8 != ctx->r1) {
        // 0x80000F5C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80000FC0;
    }
    // 0x80000F5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000F60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80000F64: nop

    // 0x80000F68: lw          $t1, 0x18($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X18);
    // 0x80000F6C: nop

    // 0x80000F70: beq         $t1, $zero, L_80000FC0
    if (ctx->r9 == 0) {
        // 0x80000F74: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80000FC0;
    }
    // 0x80000F74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000F78: jal         0x800C7DF0
    // 0x80000F7C: nop

    alCSPGetTempo(rdram, ctx);
        goto after_5;
    // 0x80000F7C: nop

    after_5:
    // 0x80000F80: lui         $t2, 0x393
    ctx->r10 = S32(0X393 << 16);
    // 0x80000F84: ori         $t2, $t2, 0x8700
    ctx->r10 = ctx->r10 | 0X8700;
    // 0x80000F88: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x80000F8C: bne         $v0, $zero, L_80000F98
    if (ctx->r2 != 0) {
        // 0x80000F90: nop
    
            goto L_80000F98;
    }
    // 0x80000F90: nop

    // 0x80000F94: break       7
    do_break(2147487636);
L_80000F98:
    // 0x80000F98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80000F9C: bne         $v0, $at, L_80000FB0
    if (ctx->r2 != ctx->r1) {
        // 0x80000FA0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80000FB0;
    }
    // 0x80000FA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80000FA4: bne         $t2, $at, L_80000FB0
    if (ctx->r10 != ctx->r1) {
        // 0x80000FA8: nop
    
            goto L_80000FB0;
    }
    // 0x80000FA8: nop

    // 0x80000FAC: break       6
    do_break(2147487660);
L_80000FB0:
    // 0x80000FB0: mflo        $t3
    ctx->r11 = lo;
    // 0x80000FB4: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
    // 0x80000FB8: nop

    // 0x80000FBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80000FC0:
    // 0x80000FC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000FC4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80000FC8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80000FCC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80000FD0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80000FD4: jr          $ra
    // 0x80000FD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80000FD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void set_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800306A4: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800306A8: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800306AC: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800306B0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800306B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800306B8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800306BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800306C0: andi        $t1, $a3, 0xFF
    ctx->r9 = ctx->r7 & 0XFF;
    // 0x800306C4: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800306C8: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800306CC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800306D0: beq         $at, $zero, L_800306F0
    if (ctx->r1 == 0) {
        // 0x800306D4: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_800306F0;
    }
    // 0x800306D4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800306D8: sll         $a1, $t9, 16
    ctx->r5 = S32(ctx->r25 << 16);
    // 0x800306DC: sll         $a2, $t7, 16
    ctx->r6 = S32(ctx->r15 << 16);
    // 0x800306E0: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800306E4: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800306E8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800306EC: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
L_800306F0:
    // 0x800306F0: slti        $at, $a2, 0x400
    ctx->r1 = SIGNED(ctx->r6) < 0X400 ? 1 : 0;
    // 0x800306F4: bne         $at, $zero, L_80030700
    if (ctx->r1 != 0) {
        // 0x800306F8: sll         $t5, $a0, 3
        ctx->r13 = S32(ctx->r4 << 3);
            goto L_80030700;
    }
    // 0x800306F8: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x800306FC: addiu       $a2, $zero, 0x3FF
    ctx->r6 = ADD32(0, 0X3FF);
L_80030700:
    // 0x80030700: addiu       $v0, $a2, -0x5
    ctx->r2 = ADD32(ctx->r6, -0X5);
    // 0x80030704: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030708: bne         $at, $zero, L_8003071C
    if (ctx->r1 != 0) {
        // 0x8003070C: subu        $t5, $t5, $a0
        ctx->r13 = SUB32(ctx->r13, ctx->r4);
            goto L_8003071C;
    }
    // 0x8003070C: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x80030710: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80030714: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80030718: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_8003071C:
    // 0x8003071C: lbu         $v1, 0x13($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X13);
    // 0x80030720: lbu         $t0, 0x17($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X17);
    // 0x80030724: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80030728: addiu       $t6, $t6, -0x26F8
    ctx->r14 = ADD32(ctx->r14, -0X26F8);
    // 0x8003072C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80030730: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x80030734: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80030738: sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5 << 16);
    // 0x8003073C: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x80030740: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x80030744: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x80030748: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x8003074C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80030750: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80030754: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80030758: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8003075C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80030760: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80030764: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x80030768: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8003076C: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x80030770: sb          $a3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r7;
    // 0x80030774: sh          $a1, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r5;
    // 0x80030778: sh          $a2, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r6;
    // 0x8003077C: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80030780: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x80030784: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80030788: jr          $ra
    // 0x8003078C: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
    return;
    // 0x8003078C: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void mark_to_write_flap_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE04: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EE08: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EE0C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EE10: nop

    // 0x8006EE14: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8006EE18: jr          $ra
    // 0x8006EE1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EE1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void __CSPPostNextSeqEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062C0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80062C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062C14: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80062C18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80062C1C: bne         $t6, $at, L_80062C6C
    if (ctx->r14 != ctx->r1) {
        // 0x80062C20: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80062C6C;
    }
    // 0x80062C20: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80062C24: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x80062C28: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80062C2C: beq         $a0, $zero, L_80062C70
    if (ctx->r4 == 0) {
        // 0x80062C30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80062C70;
    }
    // 0x80062C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062C34: jal         0x800C894C
    // 0x80062C38: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    __alCSeqNextDelta(rdram, ctx);
        goto after_0;
    // 0x80062C38: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80062C3C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80062C40: beq         $v0, $zero, L_80062C70
    if (ctx->r2 == 0) {
        // 0x80062C44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80062C70;
    }
    // 0x80062C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062C48: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x80062C4C: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x80062C50: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80062C54: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x80062C58: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062C5C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80062C60: mflo        $a2
    ctx->r6 = lo;
    // 0x80062C64: jal         0x800C970C
    // 0x80062C68: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80062C68: nop

    after_1:
L_80062C6C:
    // 0x80062C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80062C70:
    // 0x80062C70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80062C74: jr          $ra
    // 0x80062C78: nop

    return;
    // 0x80062C78: nop

;}
RECOMP_FUNC void obj_loop_animator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037824: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80037828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003782C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80037830: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80037834: lh          $t0, 0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X4);
    // 0x80037838: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
    // 0x8003783C: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037840: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x80037844: mflo        $t0
    ctx->r8 = lo;
    // 0x80037848: sll         $t6, $t0, 4
    ctx->r14 = S32(ctx->r8 << 4);
    // 0x8003784C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80037850: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037854: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x80037858: sh          $t9, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r25;
    // 0x8003785C: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    // 0x80037860: nop

    // 0x80037864: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x80037868: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x8003786C: sra         $t0, $v0, 4
    ctx->r8 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80037870: mflo        $t1
    ctx->r9 = lo;
    // 0x80037874: sll         $t7, $t1, 4
    ctx->r15 = S32(ctx->r9 << 4);
    // 0x80037878: addu        $t7, $t6, $t7
    ctx->r15 = ADD32(ctx->r14, ctx->r15);
    // 0x8003787C: sh          $t7, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r15;
    // 0x80037880: lh          $a2, 0xA($v1)
    ctx->r6 = MEM_H(ctx->r3, 0XA);
    // 0x80037884: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80037888: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8003788C: sh          $t9, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r25;
    // 0x80037890: beq         $t6, $at, L_80037A48
    if (ctx->r14 == ctx->r1) {
        // 0x80037894: sra         $t1, $a2, 4
        ctx->r9 = S32(SIGNED(ctx->r6) >> 4);
            goto L_80037A48;
    }
    // 0x80037894: sra         $t1, $a2, 4
    ctx->r9 = S32(SIGNED(ctx->r6) >> 4);
    // 0x80037898: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8003789C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800378A0: jal         0x8002C804
    // 0x800378A4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x800378A4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_0:
    // 0x800378A8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800378AC: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800378B0: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800378B4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800378B8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800378BC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800378C0: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x800378C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800378C8: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x800378CC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800378D0: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x800378D4: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x800378D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800378DC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800378E0: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800378E4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800378E8: lh          $t4, 0x4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4);
    // 0x800378EC: lh          $t3, 0x10($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X10);
    // 0x800378F0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800378F4: beq         $t5, $at, L_80037A4C
    if (ctx->r13 == ctx->r1) {
        // 0x800378F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80037A4C;
    }
    // 0x800378F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800378FC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80037900: sll         $t8, $t5, 3
    ctx->r24 = S32(ctx->r13 << 3);
    // 0x80037904: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80037908: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x8003790C: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80037910: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x80037914: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x80037918: sll         $a1, $v1, 7
    ctx->r5 = S32(ctx->r3 << 7);
    // 0x8003791C: beq         $at, $zero, L_80037A48
    if (ctx->r1 == 0) {
        // 0x80037920: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80037A48;
    }
    // 0x80037920: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80037924:
    // 0x80037924: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80037928: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x8003792C: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x80037930: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80037934: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80037938: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x8003793C: bne         $t7, $zero, L_80037A40
    if (ctx->r15 != 0) {
        // 0x80037940: nop
    
            goto L_80037A40;
    }
    // 0x80037940: nop

    // 0x80037944: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x80037948: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8003794C: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80037950: beq         $at, $zero, L_8003797C
    if (ctx->r1 == 0) {
        // 0x80037954: sll         $a3, $a0, 1
        ctx->r7 = S32(ctx->r4 << 1);
            goto L_8003797C;
    }
    // 0x80037954: sll         $a3, $a0, 1
    ctx->r7 = S32(ctx->r4 << 1);
    // 0x80037958: subu        $t8, $v1, $a1
    ctx->r24 = SUB32(ctx->r3, ctx->r5);
    // 0x8003795C: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x80037960: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x80037964: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x80037968: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x8003796C: subu        $t8, $t9, $a1
    ctx->r24 = SUB32(ctx->r25, ctx->r5);
    // 0x80037970: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x80037974: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x80037978: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
L_8003797C:
    // 0x8003797C: bgez        $v1, L_800379A0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80037980: addu        $t6, $v1, $a1
        ctx->r14 = ADD32(ctx->r3, ctx->r5);
            goto L_800379A0;
    }
    // 0x80037980: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x80037984: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x80037988: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x8003798C: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x80037990: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x80037994: addu        $t6, $t8, $a1
    ctx->r14 = ADD32(ctx->r24, ctx->r5);
    // 0x80037998: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x8003799C: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
L_800379A0:
    // 0x800379A0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800379A4: nop

    // 0x800379A8: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800379AC: beq         $at, $zero, L_800379D4
    if (ctx->r1 == 0) {
        // 0x800379B0: subu        $t7, $v1, $a0
        ctx->r15 = SUB32(ctx->r3, ctx->r4);
            goto L_800379D4;
    }
    // 0x800379B0: subu        $t7, $v1, $a0
    ctx->r15 = SUB32(ctx->r3, ctx->r4);
    // 0x800379B4: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x800379B8: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x800379BC: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x800379C0: subu        $t8, $t9, $a0
    ctx->r24 = SUB32(ctx->r25, ctx->r4);
    // 0x800379C4: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x800379C8: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800379CC: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x800379D0: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
L_800379D4:
    // 0x800379D4: bgez        $v1, L_800379FC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800379D8: addu        $t9, $v1, $a0
        ctx->r25 = ADD32(ctx->r3, ctx->r4);
            goto L_800379FC;
    }
    // 0x800379D8: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    // 0x800379DC: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x800379E0: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x800379E4: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x800379E8: addu        $t6, $t8, $a0
    ctx->r14 = ADD32(ctx->r24, ctx->r4);
    // 0x800379EC: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800379F0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800379F4: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x800379F8: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
L_800379FC:
    // 0x800379FC: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x80037A00: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x80037A04: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x80037A08: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x80037A0C: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x80037A10: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x80037A14: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x80037A18: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x80037A1C: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
    // 0x80037A20: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x80037A24: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x80037A28: addu        $t7, $v1, $t0
    ctx->r15 = ADD32(ctx->r3, ctx->r8);
    // 0x80037A2C: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x80037A30: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x80037A34: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x80037A38: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x80037A3C: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
L_80037A40:
    // 0x80037A40: bne         $a2, $t3, L_80037924
    if (ctx->r6 != ctx->r11) {
        // 0x80037A44: nop
    
            goto L_80037924;
    }
    // 0x80037A44: nop

L_80037A48:
    // 0x80037A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037A4C:
    // 0x80037A4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80037A50: jr          $ra
    // 0x80037A54: nop

    return;
    // 0x80037A54: nop

;}
RECOMP_FUNC void filename_trim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097D0C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80097D10: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80097D14: beq         $t6, $zero, L_80097DA8
    if (ctx->r14 == 0) {
        // 0x80097D18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80097DA8;
    }
    // 0x80097D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80097D1C: lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X0);
    // 0x80097D20: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80097D24: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
L_80097D28:
    // 0x80097D28: bne         $t0, $a2, L_80097D8C
    if (ctx->r8 != ctx->r6) {
        // 0x80097D2C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80097D8C;
    }
    // 0x80097D2C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80097D30: lbu         $a2, 0x1($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X1);
    // 0x80097D34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80097D38: bne         $t0, $a2, L_80097D50
    if (ctx->r8 != ctx->r6) {
        // 0x80097D3C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80097D50;
    }
    // 0x80097D3C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80097D40:
    // 0x80097D40: lbu         $a2, 0x1($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X1);
    // 0x80097D44: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80097D48: beq         $t0, $a2, L_80097D40
    if (ctx->r8 == ctx->r6) {
        // 0x80097D4C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80097D40;
    }
    // 0x80097D4C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80097D50:
    // 0x80097D50: beq         $a2, $zero, L_80097DA0
    if (ctx->r6 == 0) {
        // 0x80097D54: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80097DA0;
    }
    // 0x80097D54: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80097D58: beq         $at, $zero, L_80097DA0
    if (ctx->r1 == 0) {
        // 0x80097D5C: nop
    
            goto L_80097DA0;
    }
    // 0x80097D5C: nop

    // 0x80097D60: addu        $a2, $v1, $a0
    ctx->r6 = ADD32(ctx->r3, ctx->r4);
L_80097D64:
    // 0x80097D64: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x80097D68: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80097D6C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80097D70: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80097D74: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80097D78: bne         $at, $zero, L_80097D64
    if (ctx->r1 != 0) {
        // 0x80097D7C: sb          $t7, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r15;
            goto L_80097D64;
    }
    // 0x80097D7C: sb          $t7, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r15;
    // 0x80097D80: lbu         $a2, 0x0($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X0);
    // 0x80097D84: b           L_80097DA0
    // 0x80097D88: nop

        goto L_80097DA0;
    // 0x80097D88: nop

L_80097D8C:
    // 0x80097D8C: sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // 0x80097D90: lbu         $a2, 0x1($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X1);
    // 0x80097D94: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80097D98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80097D9C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80097DA0:
    // 0x80097DA0: bne         $a2, $zero, L_80097D28
    if (ctx->r6 != 0) {
        // 0x80097DA4: nop
    
            goto L_80097D28;
    }
    // 0x80097DA4: nop

L_80097DA8:
    // 0x80097DA8: jr          $ra
    // 0x80097DAC: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    return;
    // 0x80097DAC: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
;}
RECOMP_FUNC void postrace_offsets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800822A4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800822A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800822AC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800822B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800822B4: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800822B8: sw          $a0, -0x2E8($at)
    MEM_W(-0X2E8, ctx->r1) = ctx->r4;
    // 0x800822BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800822C0: sw          $zero, -0x2EC($at)
    MEM_W(-0X2EC, ctx->r1) = 0;
    // 0x800822C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800822C8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800822CC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800822D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800822D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800822D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800822DC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800822E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800822E4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800822E8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800822EC: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800822F0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800822F4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800822F8: addiu       $v0, $v0, 0x6DF8
    ctx->r2 = ADD32(ctx->r2, 0X6DF8);
    // 0x800822FC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80082300: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80082304: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80082308: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008230C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082314: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80082318: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8008231C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80082320: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80082324: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80082328: sw          $t9, 0x6DFC($at)
    MEM_W(0X6DFC, ctx->r1) = ctx->r25;
    // 0x8008232C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80082330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082334: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80082338: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008233C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80082340: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082344: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008234C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80082350: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80082354: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80082358: sw          $t1, 0x6E00($at)
    MEM_W(0X6E00, ctx->r1) = ctx->r9;
    // 0x8008235C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082360: sw          $zero, 0x6DF4($at)
    MEM_W(0X6DF4, ctx->r1) = 0;
    // 0x80082364: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082368: sw          $t2, -0x2E4($at)
    MEM_W(-0X2E4, ctx->r1) = ctx->r10;
    // 0x8008236C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082370: sw          $t3, -0x2E0($at)
    MEM_W(-0X2E0, ctx->r1) = ctx->r11;
    // 0x80082374: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80082378: nop

    // 0x8008237C: blez        $t4, L_80082390
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80082380: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80082390;
    }
    // 0x80082380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082384: jal         0x80001D04
    // 0x80082388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80082388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8008238C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80082390:
    // 0x80082390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80082394: jr          $ra
    // 0x80082398: nop

    return;
    // 0x80082398: nop

;}
RECOMP_FUNC void gzip_inflate_codes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C75A0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C75A4: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C75A8: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x800C75AC: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x800C75B0: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x800C75B4: addiu       $t3, $t3, -0x65F4
    ctx->r11 = ADD32(ctx->r11, -0X65F4);
    // 0x800C75B8: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800C75BC: sll         $t0, $a3, 1
    ctx->r8 = S32(ctx->r7 << 1);
    // 0x800C75C0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800C75C4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800C75C8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C75CC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C75D0: addu        $v1, $t3, $v0
    ctx->r3 = ADD32(ctx->r11, ctx->r2);
    // 0x800C75D4: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x800C75D8: lw          $s2, 0x3CF8($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X3CF8);
    // 0x800C75DC: lw          $s1, 0x3CFC($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X3CFC);
    // 0x800C75E0: lw          $t9, -0x4F70($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4F70);
    // 0x800C75E4: lw          $s0, -0x4F6C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4F6C);
    // 0x800C75E8: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x800C75EC: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
L_800C75F0:
    // 0x800C75F0: sltu        $at, $s0, $a2
    ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
L_800C75F4:
    // 0x800C75F4: beql        $at, $zero, L_800C761C
    if (ctx->r1 == 0) {
        // 0x800C75F8: and         $v0, $t9, $t5
        ctx->r2 = ctx->r25 & ctx->r13;
            goto L_800C761C;
    }
    goto skip_0;
    // 0x800C75F8: and         $v0, $t9, $t5
    ctx->r2 = ctx->r25 & ctx->r13;
    skip_0:
L_800C75FC:
    // 0x800C75FC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C7600: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C7604: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C7608: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C760C: slt         $at, $s0, $a2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C7610: bne         $at, $zero, L_800C75FC
    if (ctx->r1 != 0) {
        // 0x800C7614: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C75FC;
    }
    // 0x800C7614: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
    // 0x800C7618: and         $v0, $t9, $t5
    ctx->r2 = ctx->r25 & ctx->r13;
L_800C761C:
    // 0x800C761C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C7620: addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
    // 0x800C7624: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7628: slti        $at, $t8, 0x11
    ctx->r1 = SIGNED(ctx->r24) < 0X11 ? 1 : 0;
    // 0x800C762C: bnel        $at, $zero, L_800C7698
    if (ctx->r1 != 0) {
        // 0x800C7630: lbu         $v0, 0x1($t7)
        ctx->r2 = MEM_BU(ctx->r15, 0X1);
            goto L_800C7698;
    }
    goto skip_1;
    // 0x800C7630: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
    skip_1:
    // 0x800C7634: lb          $v1, 0x1($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X1);
L_800C7638:
    // 0x800C7638: addi        $t8, $t8, -0x10
    ctx->r24 = ADD32(ctx->r24, -0X10);
    // 0x800C763C: sub         $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // 0x800C7640: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C7644: beq         $at, $zero, L_800C7668
    if (ctx->r1 == 0) {
        // 0x800C7648: srlv        $t9, $t9, $v1
        ctx->r25 = S32(U32(ctx->r25) >> (ctx->r3 & 31));
            goto L_800C7668;
    }
    // 0x800C7648: srlv        $t9, $t9, $v1
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r3 & 31));
L_800C764C:
    // 0x800C764C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C7650: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C7654: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C7658: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C765C: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7660: bne         $at, $zero, L_800C764C
    if (ctx->r1 != 0) {
        // 0x800C7664: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C764C;
    }
    // 0x800C7664: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C7668:
    // 0x800C7668: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    // 0x800C766C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C7670: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C7674: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800C7678: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C767C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C7680: add         $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x800C7684: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7688: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x800C768C: beql        $at, $zero, L_800C7638
    if (ctx->r1 == 0) {
        // 0x800C7690: lb          $v1, 0x1($t7)
        ctx->r3 = MEM_B(ctx->r15, 0X1);
            goto L_800C7638;
    }
    goto skip_2;
    // 0x800C7690: lb          $v1, 0x1($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X1);
    skip_2:
    // 0x800C7694: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
L_800C7698:
    // 0x800C7698: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800C769C: srlv        $t9, $t9, $v0
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r2 & 31));
    // 0x800C76A0: bne         $t8, $at, L_800C76B8
    if (ctx->r24 != ctx->r1) {
        // 0x800C76A4: sub         $s0, $s0, $v0
        ctx->r16 = SUB32(ctx->r16, ctx->r2);
            goto L_800C76B8;
    }
    // 0x800C76A4: sub         $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C76A8: lhu         $v0, 0x4($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X4);
    // 0x800C76AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C76B0: j           L_800C75F0
    // 0x800C76B4: sb          $v0, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r2;
        goto L_800C75F0;
    // 0x800C76B4: sb          $v0, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r2;
L_800C76B8:
    // 0x800C76B8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800C76BC: beq         $t8, $at, L_800C7860
    if (ctx->r24 == ctx->r1) {
        // 0x800C76C0: sltu        $at, $s0, $t8
        ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
            goto L_800C7860;
    }
    // 0x800C76C0: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C76C4: beql        $at, $zero, L_800C76EC
    if (ctx->r1 == 0) {
        // 0x800C76C8: sll         $v0, $t8, 1
        ctx->r2 = S32(ctx->r24 << 1);
            goto L_800C76EC;
    }
    goto skip_3;
    // 0x800C76C8: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    skip_3:
L_800C76CC:
    // 0x800C76CC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C76D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C76D4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C76D8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C76DC: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C76E0: bne         $at, $zero, L_800C76CC
    if (ctx->r1 != 0) {
        // 0x800C76E4: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C76CC;
    }
    // 0x800C76E4: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
    // 0x800C76E8: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
L_800C76EC:
    // 0x800C76EC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C76F0: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C76F4: lhu         $t0, 0x4($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X4);
    // 0x800C76F8: sub         $s0, $s0, $t8
    ctx->r16 = SUB32(ctx->r16, ctx->r24);
    // 0x800C76FC: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x800C7700: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C7704: srlv        $t9, $t9, $t8
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r24 & 31));
    // 0x800C7708: beq         $at, $zero, L_800C772C
    if (ctx->r1 == 0) {
        // 0x800C770C: addu        $t6, $t0, $t1
        ctx->r14 = ADD32(ctx->r8, ctx->r9);
            goto L_800C772C;
    }
    // 0x800C770C: addu        $t6, $t0, $t1
    ctx->r14 = ADD32(ctx->r8, ctx->r9);
L_800C7710:
    // 0x800C7710: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C7714: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C7718: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C771C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C7720: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C7724: bne         $at, $zero, L_800C7710
    if (ctx->r1 != 0) {
        // 0x800C7728: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C7710;
    }
    // 0x800C7728: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C772C:
    // 0x800C772C: and         $v0, $t4, $t9
    ctx->r2 = ctx->r12 & ctx->r25;
    // 0x800C7730: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C7734: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800C7738: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C773C: slti        $at, $t8, 0x11
    ctx->r1 = SIGNED(ctx->r24) < 0X11 ? 1 : 0;
    // 0x800C7740: bnel        $at, $zero, L_800C77AC
    if (ctx->r1 != 0) {
        // 0x800C7744: lbu         $v0, 0x1($t7)
        ctx->r2 = MEM_BU(ctx->r15, 0X1);
            goto L_800C77AC;
    }
    goto skip_4;
    // 0x800C7744: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
    skip_4:
    // 0x800C7748: lbu         $t0, 0x1($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X1);
L_800C774C:
    // 0x800C774C: addi        $t8, $t8, -0x10
    ctx->r24 = ADD32(ctx->r24, -0X10);
    // 0x800C7750: sub         $s0, $s0, $t0
    ctx->r16 = SUB32(ctx->r16, ctx->r8);
    // 0x800C7754: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C7758: beq         $at, $zero, L_800C777C
    if (ctx->r1 == 0) {
        // 0x800C775C: srlv        $t9, $t9, $t0
        ctx->r25 = S32(U32(ctx->r25) >> (ctx->r8 & 31));
            goto L_800C777C;
    }
    // 0x800C775C: srlv        $t9, $t9, $t0
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r8 & 31));
L_800C7760:
    // 0x800C7760: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C7764: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C7768: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C776C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C7770: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7774: bne         $at, $zero, L_800C7760
    if (ctx->r1 != 0) {
        // 0x800C7778: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C7760;
    }
    // 0x800C7778: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C777C:
    // 0x800C777C: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    // 0x800C7780: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C7784: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C7788: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800C778C: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C7790: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C7794: addu        $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x800C7798: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C779C: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x800C77A0: beql        $at, $zero, L_800C774C
    if (ctx->r1 == 0) {
        // 0x800C77A4: lbu         $t0, 0x1($t7)
        ctx->r8 = MEM_BU(ctx->r15, 0X1);
            goto L_800C774C;
    }
    goto skip_5;
    // 0x800C77A4: lbu         $t0, 0x1($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X1);
    skip_5:
    // 0x800C77A8: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
L_800C77AC:
    // 0x800C77AC: sub         $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C77B0: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C77B4: beq         $at, $zero, L_800C77D8
    if (ctx->r1 == 0) {
        // 0x800C77B8: srlv        $t9, $t9, $v0
        ctx->r25 = S32(U32(ctx->r25) >> (ctx->r2 & 31));
            goto L_800C77D8;
    }
    // 0x800C77B8: srlv        $t9, $t9, $v0
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r2 & 31));
L_800C77BC:
    // 0x800C77BC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C77C0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C77C4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C77C8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C77CC: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C77D0: bne         $at, $zero, L_800C77BC
    if (ctx->r1 != 0) {
        // 0x800C77D4: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C77BC;
    }
    // 0x800C77D4: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C77D8:
    // 0x800C77D8: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    // 0x800C77DC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C77E0: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C77E4: lhu         $v1, 0x4($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X4);
    // 0x800C77E8: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x800C77EC: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C77F0: sub         $t0, $s1, $v1
    ctx->r8 = SUB32(ctx->r17, ctx->r3);
    // 0x800C77F4: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x800C77F8: srlv        $t9, $t9, $t8
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r24 & 31));
    // 0x800C77FC: beq         $v0, $zero, L_800C7828
    if (ctx->r2 == 0) {
        // 0x800C7800: sub         $s0, $s0, $t8
        ctx->r16 = SUB32(ctx->r16, ctx->r24);
            goto L_800C7828;
    }
    // 0x800C7800: sub         $s0, $s0, $t8
    ctx->r16 = SUB32(ctx->r16, ctx->r24);
    // 0x800C7804: sub         $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
L_800C7808:
    // 0x800C7808: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800C780C: addi        $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C7810: addi        $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C7814: addi        $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C7818: bne         $v0, $zero, L_800C7808
    if (ctx->r2 != 0) {
        // 0x800C781C: sb          $t2, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r10;
            goto L_800C7808;
    }
    // 0x800C781C: sb          $t2, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r10;
    // 0x800C7820: beql        $t6, $zero, L_800C75F4
    if (ctx->r14 == 0) {
        // 0x800C7824: sltu        $at, $s0, $a2
        ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
            goto L_800C75F4;
    }
    goto skip_6;
    // 0x800C7824: sltu        $at, $s0, $a2
    ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
    skip_6:
L_800C7828:
    // 0x800C7828: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x800C782C: addiu       $t6, $t6, -0x4
    ctx->r14 = ADD32(ctx->r14, -0X4);
    // 0x800C7830: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800C7834: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x800C7838: lbu         $v1, -0x3($t0)
    ctx->r3 = MEM_BU(ctx->r8, -0X3);
    // 0x800C783C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800C7840: sb          $v1, -0x3($s1)
    MEM_B(-0X3, ctx->r17) = ctx->r3;
    // 0x800C7844: lbu         $t1, -0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, -0X2);
    // 0x800C7848: sb          $t1, -0x2($s1)
    MEM_B(-0X2, ctx->r17) = ctx->r9;
    // 0x800C784C: lbu         $t2, -0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, -0X1);
    // 0x800C7850: bne         $t6, $zero, L_800C7828
    if (ctx->r14 != 0) {
        // 0x800C7854: sb          $t2, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r10;
            goto L_800C7828;
    }
    // 0x800C7854: sb          $t2, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r10;
    // 0x800C7858: j           L_800C75F0
    // 0x800C785C: nop

        goto L_800C75F0;
    // 0x800C785C: nop

L_800C7860:
    // 0x800C7860: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7864: sw          $s2, 0x3CF8($at)
    MEM_W(0X3CF8, ctx->r1) = ctx->r18;
    // 0x800C7868: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C786C: sw          $s1, 0x3CFC($at)
    MEM_W(0X3CFC, ctx->r1) = ctx->r17;
    // 0x800C7870: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7874: sw          $t9, -0x4F70($at)
    MEM_W(-0X4F70, ctx->r1) = ctx->r25;
    // 0x800C7878: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C787C: sw          $s0, -0x4F6C($at)
    MEM_W(-0X4F6C, ctx->r1) = ctx->r16;
    // 0x800C7880: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x800C7884: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x800C7888: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800C788C: jr          $ra
    // 0x800C7890: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C7890: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void obj_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010994: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80010998: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001099C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800109A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800109A4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800109A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800109AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800109B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800109B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800109B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800109BC: jal         0x800245E8
    // 0x800109C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x800109C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // 0x800109C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800109C8: lw          $v0, -0x4CD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CD0);
    // 0x800109CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800109D0: blez        $v0, L_80010A08
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800109D4: sw          $v0, -0x4CC8($at)
        MEM_W(-0X4CC8, ctx->r1) = ctx->r2;
            goto L_80010A08;
    }
    // 0x800109D4: sw          $v0, -0x4CC8($at)
    MEM_W(-0X4CC8, ctx->r1) = ctx->r2;
    // 0x800109D8: jal         0x800A06D0
    // 0x800109DC: nop

    race_starting(rdram, ctx);
        goto after_1;
    // 0x800109DC: nop

    after_1:
    // 0x800109E0: beq         $v0, $zero, L_80010A08
    if (ctx->r2 == 0) {
        // 0x800109E4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80010A08;
    }
    // 0x800109E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800109E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800109EC: addiu       $a0, $a0, -0x4CD0
    ctx->r4 = ADD32(ctx->r4, -0X4CD0);
    // 0x800109F0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800109F4: addiu       $v1, $v1, -0x4CC4
    ctx->r3 = ADD32(ctx->r3, -0X4CC4);
    // 0x800109F8: subu        $v0, $t6, $s4
    ctx->r2 = SUB32(ctx->r14, ctx->r20);
    // 0x800109FC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80010A00: b           L_80010A28
    // 0x80010A04: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_80010A28;
    // 0x80010A04: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80010A08:
    // 0x80010A08: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80010A0C: addiu       $v1, $v1, -0x4CC4
    ctx->r3 = ADD32(ctx->r3, -0X4CC4);
    // 0x80010A10: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80010A14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010A18: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x80010A1C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80010A20: lw          $v0, -0x4CD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CD0);
    // 0x80010A24: nop

L_80010A28:
    // 0x80010A28: bgtz        $v0, L_80010A38
    if (SIGNED(ctx->r2) > 0) {
        // 0x80010A2C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80010A38;
    }
    // 0x80010A2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80010A30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80010A34: sw          $zero, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = 0;
L_80010A38:
    // 0x80010A38: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010A3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80010A40: addiu       $v0, $v0, -0x4D5F
    ctx->r2 = ADD32(ctx->r2, -0X4D5F);
    // 0x80010A44: sb          $zero, -0x4D43($at)
    MEM_B(-0X4D43, ctx->r1) = 0;
    // 0x80010A48: lb          $t0, 0x0($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X0);
    // 0x80010A4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80010A50: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x80010A54: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x80010A58: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x80010A5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80010A60: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80010A64: addiu       $a0, $a0, -0x4B90
    ctx->r4 = ADD32(ctx->r4, -0X4B90);
    // 0x80010A68: sb          $zero, -0x4D5E($at)
    MEM_B(-0X4D5E, ctx->r1) = 0;
    // 0x80010A6C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80010A70: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80010A74: blez        $t4, L_80010AFC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80010A78: lui         $s5, 0x8012
        ctx->r21 = S32(0X8012 << 16);
            goto L_80010AFC;
    }
    // 0x80010A78: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010A7C: addiu       $s5, $s5, -0x4B9C
    ctx->r21 = ADD32(ctx->r21, -0X4B9C);
    // 0x80010A80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80010A84:
    // 0x80010A84: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x80010A88: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010A8C: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80010A90: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80010A94: nop

    // 0x80010A98: lw          $a1, 0x64($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X64);
    // 0x80010A9C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80010AA0: nop

    // 0x80010AA4: swc1        $f4, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->f4.u32l;
    // 0x80010AA8: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80010AAC: nop

    // 0x80010AB0: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80010AB4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80010AB8: nop

    // 0x80010ABC: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80010AC0: nop

    // 0x80010AC4: swc1        $f6, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f6.u32l;
    // 0x80010AC8: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x80010ACC: nop

    // 0x80010AD0: addu        $t0, $t1, $v1
    ctx->r8 = ADD32(ctx->r9, ctx->r3);
    // 0x80010AD4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80010AD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80010ADC: lwc1        $f8, 0x14($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80010AE0: nop

    // 0x80010AE4: swc1        $f8, 0x64($a1)
    MEM_W(0X64, ctx->r5) = ctx->f8.u32l;
    // 0x80010AE8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80010AEC: nop

    // 0x80010AF0: slt         $at, $s3, $t3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80010AF4: bne         $at, $zero, L_80010A84
    if (ctx->r1 != 0) {
        // 0x80010AF8: nop
    
            goto L_80010A84;
    }
    // 0x80010AF8: nop

L_80010AFC:
    // 0x80010AFC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010B00: jal         0x800142B8
    // 0x80010B04: addiu       $s5, $s5, -0x4B9C
    ctx->r21 = ADD32(ctx->r21, -0X4B9C);
    obj_tick_anims(rdram, ctx);
        goto after_2;
    // 0x80010B04: addiu       $s5, $s5, -0x4B9C
    ctx->r21 = ADD32(ctx->r21, -0X4B9C);
    after_2:
    // 0x80010B08: jal         0x800155B8
    // 0x80010B0C: nop

    process_object_interactions(rdram, ctx);
        goto after_3;
    // 0x80010B0C: nop

    after_3:
    // 0x80010B10: jal         0x8001E8D0
    // 0x80010B14: nop

    func_8001E89C(rdram, ctx);
        goto after_4;
    // 0x80010B14: nop

    after_4:
    // 0x80010B18: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80010B1C: addiu       $s3, $s3, -0x4C10
    ctx->r19 = ADD32(ctx->r19, -0X4C10);
    // 0x80010B20: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80010B24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80010B28: blez        $t4, L_80010B68
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80010B2C: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80010B68;
    }
    // 0x80010B2C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010B30: addiu       $s0, $s0, -0x4C14
    ctx->r16 = ADD32(ctx->r16, -0X4C14);
    // 0x80010B34: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80010B38:
    // 0x80010B38: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80010B3C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010B40: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80010B44: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80010B48: jal         0x80023F7C
    // 0x80010B4C: nop

    run_object_loop_func(rdram, ctx);
        goto after_5;
    // 0x80010B4C: nop

    after_5:
    // 0x80010B50: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80010B54: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010B58: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80010B5C: bne         $at, $zero, L_80010B38
    if (ctx->r1 != 0) {
        // 0x80010B60: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010B38;
    }
    // 0x80010B60: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010B64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80010B68:
    // 0x80010B68: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010B6C: addiu       $s0, $s0, -0x4C14
    ctx->r16 = ADD32(ctx->r16, -0X4C14);
    // 0x80010B70: jal         0x8001E720
    // 0x80010B74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001E6EC(rdram, ctx);
        goto after_6;
    // 0x80010B74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80010B78: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80010B7C: nop

    // 0x80010B80: blez        $t8, L_80010BB4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80010B84: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80010BB4;
    }
    // 0x80010B84: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80010B88:
    // 0x80010B88: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80010B8C: nop

    // 0x80010B90: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x80010B94: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80010B98: jal         0x800170D0
    // 0x80010B9C: nop

    obj_collision_transform(rdram, ctx);
        goto after_7;
    // 0x80010B9C: nop

    after_7:
    // 0x80010BA0: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80010BA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010BA8: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80010BAC: bne         $at, $zero, L_80010B88
    if (ctx->r1 != 0) {
        // 0x80010BB0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010B88;
    }
    // 0x80010BB0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80010BB4:
    // 0x80010BB4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80010BB8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010BBC: lw          $s3, -0x4C24($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X4C24);
    // 0x80010BC0: lw          $s1, -0x4C20($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4C20);
    // 0x80010BC4: nop

    // 0x80010BC8: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80010BCC: beq         $at, $zero, L_80010D00
    if (ctx->r1 == 0) {
        // 0x80010BD0: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010D00;
    }
    // 0x80010BD0: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
    // 0x80010BD4: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x80010BD8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80010BDC: addiu       $s6, $s6, -0x4C28
    ctx->r22 = ADD32(ctx->r22, -0X4C28);
    // 0x80010BE0: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80010BE4: addiu       $s1, $zero, 0x21
    ctx->r17 = ADD32(0, 0X21);
L_80010BE8:
    // 0x80010BE8: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80010BEC: nop

    // 0x80010BF0: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80010BF4: lw          $s0, 0x0($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X0);
    // 0x80010BF8: nop

    // 0x80010BFC: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80010C00: nop

    // 0x80010C04: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80010C08: bne         $t6, $zero, L_80010CF0
    if (ctx->r14 != 0) {
        // 0x80010C0C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C0C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C10: lh          $v0, 0x48($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X48);
    // 0x80010C14: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80010C18: beq         $s1, $v0, L_80010CF0
    if (ctx->r17 == ctx->r2) {
        // 0x80010C1C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C1C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C20: beq         $v0, $at, L_80010CEC
    if (ctx->r2 == ctx->r1) {
        // 0x80010C24: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80010CEC;
    }
    // 0x80010C24: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80010C28: beq         $v0, $at, L_80010CF0
    if (ctx->r2 == ctx->r1) {
        // 0x80010C2C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C2C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C30: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80010C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010C38: beq         $v0, $zero, L_80010C60
    if (ctx->r2 == 0) {
        // 0x80010C3C: nop
    
            goto L_80010C60;
    }
    // 0x80010C3C: nop

    // 0x80010C40: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x80010C44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80010C48: beq         $t7, $at, L_80010C68
    if (ctx->r15 == ctx->r1) {
        // 0x80010C4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010C68;
    }
    // 0x80010C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010C50: jal         0x80023F7C
    // 0x80010C54: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    run_object_loop_func(rdram, ctx);
        goto after_8;
    // 0x80010C54: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_8:
    // 0x80010C58: b           L_80010C6C
    // 0x80010C5C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
        goto L_80010C6C;
    // 0x80010C5C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
L_80010C60:
    // 0x80010C60: jal         0x80023F7C
    // 0x80010C64: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    run_object_loop_func(rdram, ctx);
        goto after_9;
    // 0x80010C64: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_9:
L_80010C68:
    // 0x80010C68: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
L_80010C6C:
    // 0x80010C6C: nop

    // 0x80010C70: lb          $t8, 0x53($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X53);
    // 0x80010C74: nop

    // 0x80010C78: bne         $t8, $zero, L_80010CF0
    if (ctx->r24 != 0) {
        // 0x80010C7C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C7C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C80: lb          $a0, 0x55($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X55);
    // 0x80010C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010C88: blez        $a0, L_80010CD4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80010C8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80010CD4;
    }
    // 0x80010C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80010C90:
    // 0x80010C90: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x80010C94: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80010C98: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x80010C9C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80010CA0: nop

    // 0x80010CA4: beq         $v1, $zero, L_80010CCC
    if (ctx->r3 == 0) {
        // 0x80010CA8: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80010CCC;
    }
    // 0x80010CA8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80010CAC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80010CB0: nop

    // 0x80010CB4: sh          $s4, 0x52($t0)
    MEM_H(0X52, ctx->r8) = ctx->r20;
    // 0x80010CB8: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x80010CBC: nop

    // 0x80010CC0: lb          $a0, 0x55($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X55);
    // 0x80010CC4: nop

    // 0x80010CC8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
L_80010CCC:
    // 0x80010CCC: bne         $at, $zero, L_80010C90
    if (ctx->r1 != 0) {
        // 0x80010CD0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80010C90;
    }
    // 0x80010CD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80010CD4:
    // 0x80010CD4: lbu         $t2, 0x72($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X72);
    // 0x80010CD8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80010CDC: beq         $t2, $at, L_80010CEC
    if (ctx->r10 == ctx->r1) {
        // 0x80010CE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010CEC;
    }
    // 0x80010CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010CE4: jal         0x80014090
    // 0x80010CE8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80014090(rdram, ctx);
        goto after_10;
    // 0x80010CE8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_10:
L_80010CEC:
    // 0x80010CEC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80010CF0:
    // 0x80010CF0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010CF4: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80010CF8: bne         $at, $zero, L_80010BE8
    if (ctx->r1 != 0) {
        // 0x80010CFC: nop
    
            goto L_80010BE8;
    }
    // 0x80010CFC: nop

L_80010D00:
    // 0x80010D00: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80010D04: lw          $t4, -0x4B90($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B90);
    // 0x80010D08: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80010D0C: addiu       $s6, $s6, -0x4C28
    ctx->r22 = ADD32(ctx->r22, -0X4C28);
    // 0x80010D10: blez        $t4, L_80010D4C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80010D14: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80010D4C;
    }
    // 0x80010D14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80010D18: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80010D1C:
    // 0x80010D1C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x80010D20: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010D24: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80010D28: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80010D2C: jal         0x8004DE78
    // 0x80010D30: nop

    update_player_racer(rdram, ctx);
        goto after_11;
    // 0x80010D30: nop

    after_11:
    // 0x80010D34: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80010D38: lw          $t7, -0x4B90($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B90);
    // 0x80010D3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010D40: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80010D44: bne         $at, $zero, L_80010D1C
    if (ctx->r1 != 0) {
        // 0x80010D48: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010D1C;
    }
    // 0x80010D48: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80010D4C:
    // 0x80010D4C: jal         0x8006BFD8
    // 0x80010D50: nop

    level_type(rdram, ctx);
        goto after_12;
    // 0x80010D50: nop

    after_12:
    // 0x80010D54: bne         $v0, $zero, L_80010DC8
    if (ctx->r2 != 0) {
        // 0x80010D58: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80010DC8;
    }
    // 0x80010D58: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010D5C: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80010D60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80010D64: blez        $a3, L_80010DC8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80010D68: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_80010DC8;
    }
    // 0x80010D68: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80010D6C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010D70: addiu       $s0, $s0, -0x4B98
    ctx->r16 = ADD32(ctx->r16, -0X4B98);
L_80010D74:
    // 0x80010D74: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80010D78: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80010D7C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80010D80: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80010D84: nop

    // 0x80010D88: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x80010D8C: nop

    // 0x80010D90: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80010D94: nop

    // 0x80010D98: beq         $s2, $t0, L_80010DBC
    if (ctx->r18 == ctx->r8) {
        // 0x80010D9C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80010DBC;
    }
    // 0x80010D9C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010DA0: jal         0x80043F0C
    // 0x80010DA4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    increment_ai_behaviour_chances(rdram, ctx);
        goto after_13;
    // 0x80010DA4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_13:
    // 0x80010DA8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010DAC: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80010DB0: nop

    // 0x80010DB4: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80010DB8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80010DBC:
    // 0x80010DBC: slt         $at, $s1, $a3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80010DC0: bne         $at, $zero, L_80010D74
    if (ctx->r1 != 0) {
        // 0x80010DC4: nop
    
            goto L_80010D74;
    }
    // 0x80010DC4: nop

L_80010DC8:
    // 0x80010DC8: jal         0x8000BADC
    // 0x80010DCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    racerfx_update(rdram, ctx);
        goto after_14;
    // 0x80010DCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_14:
    // 0x80010DD0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010DD4: lw          $s1, -0x4C20($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4C20);
    // 0x80010DD8: nop

    // 0x80010DDC: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80010DE0: beq         $at, $zero, L_80010E58
    if (ctx->r1 == 0) {
        // 0x80010DE4: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010E58;
    }
    // 0x80010DE4: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
    // 0x80010DE8: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
L_80010DEC:
    // 0x80010DEC: lw          $t2, 0x0($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X0);
    // 0x80010DF0: nop

    // 0x80010DF4: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80010DF8: lw          $s0, 0x0($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X0);
    // 0x80010DFC: nop

    // 0x80010E00: lh          $t4, 0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X6);
    // 0x80010E04: nop

    // 0x80010E08: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80010E0C: bne         $t5, $zero, L_80010E24
    if (ctx->r13 != 0) {
        // 0x80010E10: nop
    
            goto L_80010E24;
    }
    // 0x80010E10: nop

    // 0x80010E14: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x80010E18: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80010E1C: beq         $t6, $at, L_80010E34
    if (ctx->r14 == ctx->r1) {
        // 0x80010E20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010E34;
    }
    // 0x80010E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80010E24:
    // 0x80010E24: lh          $t7, 0x48($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X48);
    // 0x80010E28: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80010E2C: bne         $t7, $at, L_80010E48
    if (ctx->r15 != ctx->r1) {
        // 0x80010E30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010E48;
    }
    // 0x80010E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80010E34:
    // 0x80010E34: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010E38: jal         0x80023F7C
    // 0x80010E3C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    run_object_loop_func(rdram, ctx);
        goto after_15;
    // 0x80010E3C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_15:
    // 0x80010E40: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80010E44: nop

L_80010E48:
    // 0x80010E48: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010E4C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010E50: bne         $at, $zero, L_80010DEC
    if (ctx->r1 != 0) {
        // 0x80010E54: nop
    
            goto L_80010DEC;
    }
    // 0x80010E54: nop

L_80010E58:
    // 0x80010E58: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80010E5C: lw          $t8, -0x4C1C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4C1C);
    // 0x80010E60: nop

    // 0x80010E64: blez        $t8, L_80010EC8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80010E68: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_80010EC8;
    }
    // 0x80010E68: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010E6C: lw          $s1, -0x4C20($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4C20);
    // 0x80010E70: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x80010E74: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80010E78: beq         $at, $zero, L_80010EC8
    if (ctx->r1 == 0) {
        // 0x80010E7C: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010EC8;
    }
    // 0x80010E7C: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
L_80010E80:
    // 0x80010E80: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x80010E84: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010E88: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x80010E8C: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x80010E90: nop

    // 0x80010E94: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x80010E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010E9C: andi        $t2, $t0, 0x8000
    ctx->r10 = ctx->r8 & 0X8000;
    // 0x80010EA0: beq         $t2, $zero, L_80010EB8
    if (ctx->r10 == 0) {
        // 0x80010EA4: nop
    
            goto L_80010EB8;
    }
    // 0x80010EA4: nop

    // 0x80010EA8: jal         0x800B285C
    // 0x80010EAC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    particle_update(rdram, ctx);
        goto after_16;
    // 0x80010EAC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_16:
    // 0x80010EB0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80010EB4: nop

L_80010EB8:
    // 0x80010EB8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010EBC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010EC0: bne         $at, $zero, L_80010E80
    if (ctx->r1 != 0) {
        // 0x80010EC4: nop
    
            goto L_80010E80;
    }
    // 0x80010EC4: nop

L_80010EC8:
    // 0x80010EC8: jal         0x800323D8
    // 0x80010ECC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    light_update_all(rdram, ctx);
        goto after_17;
    // 0x80010ECC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_17:
    // 0x80010ED0: jal         0x80032CAC
    // 0x80010ED4: nop

    light_count(rdram, ctx);
        goto after_18;
    // 0x80010ED4: nop

    after_18:
    // 0x80010ED8: blez        $v0, L_80010F58
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80010EDC: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_80010F58;
    }
    // 0x80010EDC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010EE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010EE4: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x80010EE8: lw          $s1, -0x4C20($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4C20);
    // 0x80010EEC: nop

    // 0x80010EF0: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010EF4: beq         $at, $zero, L_80010F58
    if (ctx->r1 == 0) {
        // 0x80010EF8: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010F58;
    }
    // 0x80010EF8: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
L_80010EFC:
    // 0x80010EFC: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80010F00: nop

    // 0x80010F04: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80010F08: lw          $s0, 0x0($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X0);
    // 0x80010F0C: nop

    // 0x80010F10: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80010F14: nop

    // 0x80010F18: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80010F1C: bne         $t6, $zero, L_80010F48
    if (ctx->r14 != 0) {
        // 0x80010F20: nop
    
            goto L_80010F48;
    }
    // 0x80010F20: nop

    // 0x80010F24: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x80010F28: nop

    // 0x80010F2C: beq         $t7, $zero, L_80010F48
    if (ctx->r15 == 0) {
        // 0x80010F30: nop
    
            goto L_80010F48;
    }
    // 0x80010F30: nop

    // 0x80010F34: jal         0x80032CBC
    // 0x80010F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    light_update_shading(rdram, ctx);
        goto after_19;
    // 0x80010F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80010F3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010F40: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x80010F44: nop

L_80010F48:
    // 0x80010F48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010F4C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010F50: bne         $at, $zero, L_80010EFC
    if (ctx->r1 != 0) {
        // 0x80010F54: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010EFC;
    }
    // 0x80010F54: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80010F58:
    // 0x80010F58: jal         0x8001E720
    // 0x80010F5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8001E6EC(rdram, ctx);
        goto after_20;
    // 0x80010F5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x80010F60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80010F64: lb          $t8, -0x4B89($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X4B89);
    // 0x80010F68: nop

    // 0x80010F6C: beq         $t8, $zero, L_80010F7C
    if (ctx->r24 == 0) {
        // 0x80010F70: nop
    
            goto L_80010F7C;
    }
    // 0x80010F70: nop

    // 0x80010F74: jal         0x8002297C
    // 0x80010F78: nop

    mode_init_taj_race(rdram, ctx);
        goto after_21;
    // 0x80010F78: nop

    after_21:
L_80010F7C:
    // 0x80010F7C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010F80: addiu       $s0, $s0, -0x4CD4
    ctx->r16 = ADD32(ctx->r16, -0X4CD4);
    // 0x80010F84: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80010F88: nop

    // 0x80010F8C: bne         $t9, $zero, L_80010FB4
    if (ctx->r25 != 0) {
        // 0x80010F90: nop
    
            goto L_80010FB4;
    }
    // 0x80010F90: nop

    // 0x80010F94: jal         0x8001004C
    // 0x80010F98: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_22;
    // 0x80010F98: nop

    after_22:
    // 0x80010F9C: jal         0x80017ECC
    // 0x80010FA0: nop

    checkpoint_update_all(rdram, ctx);
        goto after_23;
    // 0x80010FA0: nop

    after_23:
    // 0x80010FA4: jal         0x8001BC88
    // 0x80010FA8: nop

    spectate_update(rdram, ctx);
        goto after_24;
    // 0x80010FA8: nop

    after_24:
    // 0x80010FAC: jal         0x8001E970
    // 0x80010FB0: nop

    func_8001E93C(rdram, ctx);
        goto after_25;
    // 0x80010FB0: nop

    after_25:
L_80010FB4:
    // 0x80010FB4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010FB8: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80010FBC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80010FC0: beq         $a3, $zero, L_80011004
    if (ctx->r7 == 0) {
        // 0x80010FC4: nop
    
            goto L_80011004;
    }
    // 0x80010FC4: nop

    // 0x80010FC8: lh          $t1, -0x4D32($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4D32);
    // 0x80010FCC: nop

    // 0x80010FD0: bne         $t1, $zero, L_80010FF0
    if (ctx->r9 != 0) {
        // 0x80010FD4: nop
    
            goto L_80010FF0;
    }
    // 0x80010FD4: nop

    // 0x80010FD8: jal         0x8001983C
    // 0x80010FDC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_check_finish(rdram, ctx);
        goto after_26;
    // 0x80010FDC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_26:
    // 0x80010FE0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010FE4: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80010FE8: b           L_80011004
    // 0x80010FEC: nop

        goto L_80011004;
    // 0x80010FEC: nop

L_80010FF0:
    // 0x80010FF0: jal         0x8001A928
    // 0x80010FF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_transition_adventure(rdram, ctx);
        goto after_27;
    // 0x80010FF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_27:
    // 0x80010FF8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010FFC: lw          $a3, -0x4B90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4B90);
    // 0x80011000: nop

L_80011004:
    // 0x80011004: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80011008: lw          $a0, -0x4B94($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4B94);
    // 0x8001100C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80011010: jal         0x80008438
    // 0x80011014: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    audspat_update_all(rdram, ctx);
        goto after_28;
    // 0x80011014: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_28:
    // 0x80011018: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x8001101C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011020: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80011024: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80011028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001102C: swc1        $f16, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->f16.u32l;
    // 0x80011030: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80011034: sb          $zero, -0x4D5C($at)
    MEM_B(-0X4D5C, ctx->r1) = 0;
    // 0x80011038: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001103C: jal         0x8000E2B4
    // 0x80011040: sb          $zero, -0x4D2D($at)
    MEM_B(-0X4D2D, ctx->r1) = 0;
    transform_player_vehicle(rdram, ctx);
        goto after_29;
    // 0x80011040: sb          $zero, -0x4D2D($at)
    MEM_B(-0X4D2D, ctx->r1) = 0;
    after_29:
    // 0x80011044: jal         0x8009D4F4
    // 0x80011048: nop

    dialogue_try_close(rdram, ctx);
        goto after_30;
    // 0x80011048: nop

    after_30:
    // 0x8001104C: jal         0x80017A04
    // 0x80011050: nop

    func_800179D0(rdram, ctx);
        goto after_31;
    // 0x80011050: nop

    after_31:
    // 0x80011054: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80011058: addiu       $v1, $v1, -0x4B80
    ctx->r3 = ADD32(ctx->r3, -0X4B80);
    // 0x8001105C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80011060: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80011064: bne         $v0, $at, L_80011100
    if (ctx->r2 != ctx->r1) {
        // 0x80011068: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80011100;
    }
    // 0x80011068: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001106C: lw          $t2, -0x4CD0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4CD0);
    // 0x80011070: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80011074: bne         $t2, $at, L_8001110C
    if (ctx->r10 != ctx->r1) {
        // 0x80011078: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8001110C;
    }
    // 0x80011078: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001107C: lh          $t3, -0x4C06($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4C06);
    // 0x80011080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011084: bne         $t3, $zero, L_8001110C
    if (ctx->r11 != 0) {
        // 0x80011088: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001110C;
    }
    // 0x80011088: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001108C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80011090:
    // 0x80011090: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80011094: jal         0x8006A794
    // 0x80011098: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_32;
    // 0x80011098: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_32:
    // 0x8001109C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800110A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800110A4: bne         $s3, $s0, L_80011090
    if (ctx->r19 != ctx->r16) {
        // 0x800110A8: or          $a1, $a1, $v0
        ctx->r5 = ctx->r5 | ctx->r2;
            goto L_80011090;
    }
    // 0x800110A8: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x800110AC: andi        $t4, $a1, 0x8000
    ctx->r12 = ctx->r5 & 0X8000;
    // 0x800110B0: beq         $t4, $zero, L_800110C8
    if (ctx->r12 == 0) {
        // 0x800110B4: andi        $t5, $a1, 0x4000
        ctx->r13 = ctx->r5 & 0X4000;
            goto L_800110C8;
    }
    // 0x800110B4: andi        $t5, $a1, 0x4000
    ctx->r13 = ctx->r5 & 0X4000;
    // 0x800110B8: jal         0x8001E490
    // 0x800110BC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_8001E45C(rdram, ctx);
        goto after_33;
    // 0x800110BC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_33:
    // 0x800110C0: b           L_80011110
    // 0x800110C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80011110;
    // 0x800110C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800110C8:
    // 0x800110C8: beq         $t5, $zero, L_80011110
    if (ctx->r13 == 0) {
        // 0x800110CC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80011110;
    }
    // 0x800110CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800110D0: jal         0x80099B68
    // 0x800110D4: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_34;
    // 0x800110D4: nop

    after_34:
    // 0x800110D8: bne         $v0, $zero, L_80011110
    if (ctx->r2 != 0) {
        // 0x800110DC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80011110;
    }
    // 0x800110DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800110E0: jal         0x8009C814
    // 0x800110E4: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_35;
    // 0x800110E4: nop

    after_35:
    // 0x800110E8: bne         $v0, $zero, L_80011110
    if (ctx->r2 != 0) {
        // 0x800110EC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80011110;
    }
    // 0x800110EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800110F0: jal         0x8006F380
    // 0x800110F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    level_transition_begin(rdram, ctx);
        goto after_36;
    // 0x800110F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_36:
    // 0x800110F8: b           L_80011110
    // 0x800110FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80011110;
    // 0x800110FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80011100:
    // 0x80011100: bne         $v0, $zero, L_8001110C
    if (ctx->r2 != 0) {
        // 0x80011104: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8001110C;
    }
    // 0x80011104: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80011108: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_8001110C:
    // 0x8001110C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80011110:
    // 0x80011110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80011114: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80011118: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001111C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80011120: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80011124: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80011128: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001112C: jr          $ra
    // 0x80011130: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80011130: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void obj_init_fireball_octoweapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033F84: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80033F88: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80033F8C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80033F90: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80033F94: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80033F98: jr          $ra
    // 0x80033F9C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    return;
    // 0x80033F9C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
;}
RECOMP_FUNC void timetrial_load_staff_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B324: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001B328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B32C: jal         0x8006B2EC
    // 0x8001B330: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    leveltable_vehicle_default(rdram, ctx);
        goto after_0;
    // 0x8001B330: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001B334: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001B338: addiu       $a1, $a1, -0x4BFC
    ctx->r5 = ADD32(ctx->r5, -0X4BFC);
    // 0x8001B33C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8001B340: jal         0x80076EE4
    // 0x8001B344: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x8001B344: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_1:
    // 0x8001B348: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001B34C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001B350: addiu       $a1, $a1, -0x4BFC
    ctx->r5 = ADD32(ctx->r5, -0X4BFC);
    // 0x8001B354: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8001B358: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001B35C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_8001B360:
    // 0x8001B360: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8001B364: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001B368: bne         $a2, $t6, L_8001B390
    if (ctx->r6 != ctx->r14) {
        // 0x8001B36C: nop
    
            goto L_8001B390;
    }
    // 0x8001B36C: nop

    // 0x8001B370: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8001B374: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x8001B378: nop

    // 0x8001B37C: bne         $t7, $t8, L_8001B390
    if (ctx->r15 != ctx->r24) {
        // 0x8001B380: nop
    
            goto L_8001B390;
    }
    // 0x8001B380: nop

    // 0x8001B384: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8001B388: b           L_8001B3A0
    // 0x8001B38C: nop

        goto L_8001B3A0;
    // 0x8001B38C: nop

L_8001B390:
    // 0x8001B390: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8001B394: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001B398: bne         $a3, $v0, L_8001B360
    if (ctx->r7 != ctx->r2) {
        // 0x8001B39C: nop
    
            goto L_8001B360;
    }
    // 0x8001B39C: nop

L_8001B3A0:
    // 0x8001B3A0: beq         $a3, $v0, L_8001B3C4
    if (ctx->r7 == ctx->r2) {
        // 0x8001B3A4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8001B3C4;
    }
    // 0x8001B3A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001B3A8: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8001B3AC: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8001B3B0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B3B4: addiu       $a2, $a2, -0x4C00
    ctx->r6 = ADD32(ctx->r6, -0X4C00);
    // 0x8001B3B8: jal         0x80059AB8
    // 0x8001B3BC: subu        $a1, $t9, $a0
    ctx->r5 = SUB32(ctx->r25, ctx->r4);
    load_tt_ghost(rdram, ctx);
        goto after_2;
    // 0x8001B3BC: subu        $a1, $t9, $a0
    ctx->r5 = SUB32(ctx->r25, ctx->r4);
    after_2:
    // 0x8001B3C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8001B3C4:
    // 0x8001B3C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001B3C8: jal         0x80071380
    // 0x8001B3CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x8001B3CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x8001B3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B3D4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B3D8: jr          $ra
    // 0x8001B3DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001B3DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void race_is_adventure_2P(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006C3E0: lb          $v0, -0x2778($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2778);
    // 0x8006C3E4: jr          $ra
    // 0x8006C3E8: nop

    return;
    // 0x8006C3E8: nop

;}
