#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void sort_objects_by_dist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015348: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001534C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80015350: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80015354: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015358: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001535C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80015360: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80015364: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80015368: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8001536C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80015370: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80015374: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80015378: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8001537C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80015380: bne         $at, $zero, L_80015584
    if (ctx->r1 != 0) {
        // 0x80015384: swc1        $f20, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
            goto L_80015584;
    }
    // 0x80015384: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80015388: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001538C: bne         $at, $zero, L_80015460
    if (ctx->r1 != 0) {
        // 0x80015390: sll         $s1, $a0, 2
        ctx->r17 = S32(ctx->r4 << 2);
            goto L_80015460;
    }
    // 0x80015390: sll         $s1, $a0, 2
    ctx->r17 = S32(ctx->r4 << 2);
    // 0x80015394: lui         $at, 0xC67A
    ctx->r1 = S32(0XC67A << 16);
    // 0x80015398: sll         $s5, $a1, 2
    ctx->r21 = S32(ctx->r5 << 2);
    // 0x8001539C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800153A0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800153A4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800153A8: addiu       $s2, $s2, -0x4C28
    ctx->r18 = ADD32(ctx->r18, -0X4C28);
    // 0x800153AC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800153B0:
    // 0x800153B0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800153B4: nop

    // 0x800153B8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800153BC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800153C0: nop

    // 0x800153C4: beq         $a0, $zero, L_80015450
    if (ctx->r4 == 0) {
        // 0x800153C8: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80015450;
    }
    // 0x800153C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800153CC: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x800153D0: nop

    // 0x800153D4: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800153D8: beq         $t9, $zero, L_80015400
    if (ctx->r25 == 0) {
        // 0x800153DC: nop
    
            goto L_80015400;
    }
    // 0x800153DC: nop

    // 0x800153E0: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800153E4: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800153E8: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800153EC: jal         0x8006A008
    // 0x800153F0: nop

    get_distance_to_camera(rdram, ctx);
        goto after_0;
    // 0x800153F0: nop

    after_0:
    // 0x800153F4: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800153F8: b           L_80015454
    // 0x800153FC: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
        goto L_80015454;
    // 0x800153FC: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
L_80015400:
    // 0x80015400: lw          $t0, 0x40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X40);
    // 0x80015404: nop

    // 0x80015408: lhu         $t1, 0x30($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X30);
    // 0x8001540C: nop

    // 0x80015410: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80015414: beq         $t2, $zero, L_80015430
    if (ctx->r10 == 0) {
        // 0x80015418: nop
    
            goto L_80015430;
    }
    // 0x80015418: nop

    // 0x8001541C: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80015420: nop

    // 0x80015424: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80015428: b           L_80015454
    // 0x8001542C: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
        goto L_80015454;
    // 0x8001542C: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
L_80015430:
    // 0x80015430: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80015434: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80015438: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8001543C: jal         0x8006A008
    // 0x80015440: nop

    get_distance_to_camera(rdram, ctx);
        goto after_1;
    // 0x80015440: nop

    after_1:
    // 0x80015444: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80015448: b           L_80015454
    // 0x8001544C: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
        goto L_80015454;
    // 0x8001544C: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_80015450:
    // 0x80015450: swc1        $f22, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f22.u32l;
L_80015454:
    // 0x80015454: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80015458: bne         $s5, $s1, L_800153B0
    if (ctx->r21 != ctx->r17) {
        // 0x8001545C: nop
    
            goto L_800153B0;
    }
    // 0x8001545C: nop

L_80015460:
    // 0x80015460: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80015464: addiu       $s2, $s2, -0x4C28
    ctx->r18 = ADD32(ctx->r18, -0X4C28);
    // 0x80015468: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
L_8001546C:
    // 0x8001546C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80015470: beq         $at, $zero, L_8001557C
    if (ctx->r1 == 0) {
        // 0x80015474: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_8001557C;
    }
    // 0x80015474: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80015478: subu        $v1, $s4, $s3
    ctx->r3 = SUB32(ctx->r20, ctx->r19);
    // 0x8001547C: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x80015480: beq         $t3, $zero, L_800154D8
    if (ctx->r11 == 0) {
        // 0x80015484: sll         $s1, $v0, 2
        ctx->r17 = S32(ctx->r2 << 2);
            goto L_800154D8;
    }
    // 0x80015484: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x80015488: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8001548C: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x80015490: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x80015494: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80015498: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8001549C: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800154A0: lwc1        $f2, 0x30($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800154A4: addiu       $a3, $s3, 0x1
    ctx->r7 = ADD32(ctx->r19, 0X1);
    // 0x800154A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800154AC: nop

    // 0x800154B0: bc1f        L_800154CC
    if (!c1cs) {
        // 0x800154B4: nop
    
            goto L_800154CC;
    }
    // 0x800154B4: nop

    // 0x800154B8: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800154BC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800154C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800154C4: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x800154C8: sw          $a0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r4;
L_800154CC:
    // 0x800154CC: beq         $a3, $s4, L_8001557C
    if (ctx->r7 == ctx->r20) {
        // 0x800154D0: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_8001557C;
    }
    // 0x800154D0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800154D4: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
L_800154D8:
    // 0x800154D8: sll         $a2, $s4, 2
    ctx->r6 = S32(ctx->r20 << 2);
L_800154DC:
    // 0x800154DC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800154E0: nop

    // 0x800154E4: addu        $v0, $t7, $s1
    ctx->r2 = ADD32(ctx->r15, ctx->r17);
    // 0x800154E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800154EC: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x800154F0: lwc1        $f16, 0x30($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800154F4: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800154F8: nop

    // 0x800154FC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80015500: nop

    // 0x80015504: bc1f        L_8001553C
    if (!c1cs) {
        // 0x80015508: nop
    
            goto L_8001553C;
    }
    // 0x80015508: nop

    // 0x8001550C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80015510: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80015514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015518: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x8001551C: sw          $a0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r4;
    // 0x80015520: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80015524: nop

    // 0x80015528: addu        $v0, $t0, $s1
    ctx->r2 = ADD32(ctx->r8, ctx->r17);
    // 0x8001552C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80015530: nop

    // 0x80015534: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80015538: nop

L_8001553C:
    // 0x8001553C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80015540: nop

    // 0x80015544: lwc1        $f18, 0x30($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80015548: nop

    // 0x8001554C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80015550: nop

    // 0x80015554: bc1f        L_80015570
    if (!c1cs) {
        // 0x80015558: nop
    
            goto L_80015570;
    }
    // 0x80015558: nop

    // 0x8001555C: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80015560: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80015564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015568: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8001556C: sw          $v1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r3;
L_80015570:
    // 0x80015570: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80015574: bne         $s1, $a2, L_800154DC
    if (ctx->r17 != ctx->r6) {
        // 0x80015578: nop
    
            goto L_800154DC;
    }
    // 0x80015578: nop

L_8001557C:
    // 0x8001557C: beq         $a1, $zero, L_8001546C
    if (ctx->r5 == 0) {
        // 0x80015580: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_8001546C;
    }
    // 0x80015580: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
L_80015584:
    // 0x80015584: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80015588: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001558C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80015590: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80015594: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80015598: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8001559C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800155A0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800155A4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800155A8: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800155AC: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800155B0: jr          $ra
    // 0x800155B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800155B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mark_to_read_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED80: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006ED84: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006ED88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006ED8C: nop

    // 0x8006ED90: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8006ED94: jr          $ra
    // 0x8006ED98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006ED98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void obj_init_eggcreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035680: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80035684: jr          $ra
    // 0x80035688: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80035688: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void add_segment_to_order(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029D54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029D58: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80029D5C: lw          $t0, -0x3178($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3178);
    // 0x80029D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029D64: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80029D68: lh          $t6, 0x1A($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X1A);
    // 0x80029D6C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80029D70: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80029D74: beq         $at, $zero, L_80029E10
    if (ctx->r1 == 0) {
        // 0x80029D78: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80029E10;
    }
    // 0x80029D78: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80029D7C: lw          $v1, -0x49AC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49AC);
    // 0x80029D80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80029D84: beq         $v1, $at, L_80029DB4
    if (ctx->r3 == ctx->r1) {
        // 0x80029D88: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80029DB4;
    }
    // 0x80029D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029D8C: lw          $t7, 0x10($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X10);
    // 0x80029D90: sra         $t9, $a0, 3
    ctx->r25 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80029D94: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80029D98: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80029D9C: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x80029DA0: andi        $t2, $a0, 0x7
    ctx->r10 = ctx->r4 & 0X7;
    // 0x80029DA4: srlv        $v0, $v0, $t2
    ctx->r2 = S32(U32(ctx->r2) >> (ctx->r10 & 31));
    // 0x80029DA8: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x80029DAC: b           L_80029DB4
    // 0x80029DB0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_80029DB4;
    // 0x80029DB0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80029DB4:
    // 0x80029DB4: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x80029DB8: beq         $t4, $zero, L_80029E10
    if (ctx->r12 == 0) {
        // 0x80029DBC: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_80029E10;
    }
    // 0x80029DBC: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80029DC0: lw          $t5, 0x8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X8);
    // 0x80029DC4: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x80029DC8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80029DCC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80029DD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80029DD4: jal         0x8002A638
    // 0x80029DD8: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    block_visible(rdram, ctx);
        goto after_0;
    // 0x80029DD8: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_0:
    // 0x80029DDC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80029DE0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80029DE4: beq         $v0, $zero, L_80029E14
    if (ctx->r2 == 0) {
        // 0x80029DE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80029E14;
    }
    // 0x80029DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029DEC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80029DF0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80029DF4: nop

    // 0x80029DF8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80029DFC: sb          $a3, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r7;
    // 0x80029E00: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80029E04: nop

    // 0x80029E08: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80029E0C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_80029E10:
    // 0x80029E10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80029E14:
    // 0x80029E14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029E18: jr          $ra
    // 0x80029E1C: nop

    return;
    // 0x80029E1C: nop

;}
RECOMP_FUNC void thread0_Main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7524: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B7528: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B752C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800B7530: addiu       $s3, $s3, -0x62B0
    ctx->r19 = ADD32(ctx->r19, -0X62B0);
    // 0x800B7534: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B7538: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B753C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800B7540: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7544: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B7548: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B754C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B7550: addiu       $a1, $a1, -0x6298
    ctx->r5 = ADD32(ctx->r5, -0X6298);
    // 0x800B7554: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B7558: jal         0x800C8D80
    // 0x800B755C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800B755C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800B7560: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800B7564: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800B7568: jal         0x800CD110
    // 0x800B756C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800B756C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800B7570: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800B7574: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800B7578: jal         0x800CD110
    // 0x800B757C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800B757C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x800B7580: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7584: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B7588: addiu       $a2, $a2, -0x6278
    ctx->r6 = ADD32(ctx->r6, -0X6278);
    // 0x800B758C: addiu       $a1, $a1, -0x6258
    ctx->r5 = ADD32(ctx->r5, -0X6258);
    // 0x800B7590: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x800B7594: jal         0x800C6560
    // 0x800B7598: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_3;
    // 0x800B7598: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_3:
    // 0x800B759C: addiu       $s2, $zero, -0x9
    ctx->r18 = ADD32(0, -0X9);
    // 0x800B75A0: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x800B75A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800B75A8:
    // 0x800B75A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B75AC: jal         0x800C9110
    // 0x800B75B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800B75B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800B75B4: jal         0x800B760C
    // 0x800B75B8: and         $s0, $s0, $s2
    ctx->r16 = ctx->r16 & ctx->r18;
    enable_interupts_on_main(rdram, ctx);
        goto after_5;
    // 0x800B75B8: and         $s0, $s0, $s2
    ctx->r16 = ctx->r16 & ctx->r18;
    after_5:
    // 0x800B75BC: jal         0x800B7680
    // 0x800B75C0: nop

    stop_all_threads_except_main(rdram, ctx);
        goto after_6;
    // 0x800B75C0: nop

    after_6:
    // 0x800B75C4: jal         0x800B76EC
    // 0x800B75C8: nop

    write_epc_data_to_cpak(rdram, ctx);
        goto after_7;
    // 0x800B75C8: nop

    after_7:
    // 0x800B75CC: b           L_800B75A8
    // 0x800B75D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_800B75A8;
    // 0x800B75D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B75D4: nop

    // 0x800B75D8: nop

    // 0x800B75DC: nop

    // 0x800B75E0: nop

    // 0x800B75E4: nop

    // 0x800B75E8: nop

    // 0x800B75EC: nop

    // 0x800B75F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B75F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B75F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B75FC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7600: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B7604: jr          $ra
    // 0x800B7608: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B7608: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void hud_sound_play_delayed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A79E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A79E4: addiu       $v0, $v0, 0x7334
    ctx->r2 = ADD32(ctx->r2, 0X7334);
    // 0x800A79E8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800A79EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A79F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A79F4: bne         $t7, $zero, L_800A7A40
    if (ctx->r15 != 0) {
        // 0x800A79F8: andi        $t6, $a0, 0xFFFF
        ctx->r14 = ctx->r4 & 0XFFFF;
            goto L_800A7A40;
    }
    // 0x800A79F8: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800A79FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7A00: sh          $t6, 0x733C($at)
    MEM_H(0X733C, ctx->r1) = ctx->r14;
    // 0x800A7A04: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800A7A08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A7A0C: nop

    // 0x800A7A10: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800A7A14: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A7A18: nop

    // 0x800A7A1C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A7A20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7A24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7A28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7A2C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A7A30: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800A7A34: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A7A38: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A7A3C: sw          $a2, 0x7338($at)
    MEM_W(0X7338, ctx->r1) = ctx->r6;
L_800A7A40:
    // 0x800A7A40: jr          $ra
    // 0x800A7A44: nop

    return;
    // 0x800A7A44: nop

;}
RECOMP_FUNC void get_race_start_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800113AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800113B0: lw          $v0, -0x4CC8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CC8);
    // 0x800113B4: jr          $ra
    // 0x800113B8: nop

    return;
    // 0x800113B8: nop

;}
RECOMP_FUNC void rain_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD824: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800AD828: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800AD82C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800AD830: bne         $t6, $zero, L_800AD87C
    if (ctx->r14 != 0) {
        // 0x800AD834: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_800AD87C;
    }
    // 0x800AD834: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AD838: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800AD83C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800AD840: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AD844: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800AD848: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800AD84C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD850: addiu       $v1, $v1, 0x3208
    ctx->r3 = ADD32(ctx->r3, 0X3208);
    // 0x800AD854: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AD858: nop

    // 0x800AD85C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AD860: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD864: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD868: nop

    // 0x800AD86C: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800AD870: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AD874: b           L_800AD8C0
    // 0x800AD878: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
        goto L_800AD8C0;
    // 0x800AD878: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
L_800AD87C:
    // 0x800AD87C: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x800AD880: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800AD884: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AD888: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800AD88C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800AD890: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD894: addiu       $v1, $v1, 0x3208
    ctx->r3 = ADD32(ctx->r3, 0X3208);
    // 0x800AD898: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AD89C: nop

    // 0x800AD8A0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AD8A4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD8A8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD8AC: nop

    // 0x800AD8B0: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800AD8B4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AD8B8: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800AD8BC: nop

L_800AD8C0:
    // 0x800AD8C0: addiu       $a2, $a2, 0x31F8
    ctx->r6 = ADD32(ctx->r6, 0X31F8);
    // 0x800AD8C4: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x800AD8C8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AD8CC: lw          $t0, 0x31F0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X31F0);
    // 0x800AD8D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AD8D4: subu        $t1, $a0, $t0
    ctx->r9 = SUB32(ctx->r4, ctx->r8);
    // 0x800AD8D8: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800AD8DC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AD8E0: addiu       $a3, $a3, 0x3204
    ctx->r7 = ADD32(ctx->r7, 0X3204);
    // 0x800AD8E4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AD8E8: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x800AD8EC: bne         $v0, $zero, L_800AD8F8
    if (ctx->r2 != 0) {
        // 0x800AD8F0: nop
    
            goto L_800AD8F8;
    }
    // 0x800AD8F0: nop

    // 0x800AD8F4: break       7
    do_break(2148194548);
L_800AD8F8:
    // 0x800AD8F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AD8FC: bne         $v0, $at, L_800AD910
    if (ctx->r2 != ctx->r1) {
        // 0x800AD900: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AD910;
    }
    // 0x800AD900: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD904: bne         $t1, $at, L_800AD910
    if (ctx->r9 != ctx->r1) {
        // 0x800AD908: nop
    
            goto L_800AD910;
    }
    // 0x800AD908: nop

    // 0x800AD90C: break       6
    do_break(2148194572);
L_800AD910:
    // 0x800AD910: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD914: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800AD918: mflo        $t2
    ctx->r10 = lo;
    // 0x800AD91C: sw          $t2, 0x31F4($at)
    MEM_W(0X31F4, ctx->r1) = ctx->r10;
    // 0x800AD920: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x800AD924: lw          $t4, 0x31FC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X31FC);
    // 0x800AD928: nop

    // 0x800AD92C: subu        $t5, $a1, $t4
    ctx->r13 = SUB32(ctx->r5, ctx->r12);
    // 0x800AD930: div         $zero, $t5, $v0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r2)));
    // 0x800AD934: bne         $v0, $zero, L_800AD940
    if (ctx->r2 != 0) {
        // 0x800AD938: nop
    
            goto L_800AD940;
    }
    // 0x800AD938: nop

    // 0x800AD93C: break       7
    do_break(2148194620);
L_800AD940:
    // 0x800AD940: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AD944: bne         $v0, $at, L_800AD958
    if (ctx->r2 != ctx->r1) {
        // 0x800AD948: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AD958;
    }
    // 0x800AD948: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD94C: bne         $t5, $at, L_800AD958
    if (ctx->r13 != ctx->r1) {
        // 0x800AD950: nop
    
            goto L_800AD958;
    }
    // 0x800AD950: nop

    // 0x800AD954: break       6
    do_break(2148194644);
L_800AD958:
    // 0x800AD958: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD95C: mflo        $t6
    ctx->r14 = lo;
    // 0x800AD960: sw          $t6, 0x3200($at)
    MEM_W(0X3200, ctx->r1) = ctx->r14;
    // 0x800AD964: jr          $ra
    // 0x800AD968: nop

    return;
    // 0x800AD968: nop

;}
RECOMP_FUNC void sndp_handle_event(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003470: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80003474: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80003478: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000347C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80003480: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80003484: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80003488: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8000348C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80003490: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80003494: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80003498: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000349C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800034A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800034A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800034A8: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    // 0x800034AC: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x800034B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800034B4: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x800034B8: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800034BC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
L_800034C0:
    // 0x800034C0: nop

    // 0x800034C4: beq         $t7, $zero, L_800034E8
    if (ctx->r15 == 0) {
        // 0x800034C8: nop
    
            goto L_800034E8;
    }
    // 0x800034C8: nop

    // 0x800034CC: sw          $s1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r17;
    // 0x800034D0: lhu         $t8, 0x0($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X0);
    // 0x800034D4: nop

    // 0x800034D8: sh          $t8, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r24;
    // 0x800034DC: lw          $t9, 0x8($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X8);
    // 0x800034E0: addiu       $s5, $sp, 0x9C
    ctx->r21 = ADD32(ctx->r29, 0X9C);
    // 0x800034E4: sw          $t9, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r25;
L_800034E8:
    // 0x800034E8: lw          $s1, 0x4($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X4);
    // 0x800034EC: nop

    // 0x800034F0: lw          $s2, 0x8($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X8);
    // 0x800034F4: nop

    // 0x800034F8: bne         $s2, $zero, L_80003510
    if (ctx->r18 != 0) {
        // 0x800034FC: addiu       $a0, $sp, 0x72
        ctx->r4 = ADD32(ctx->r29, 0X72);
            goto L_80003510;
    }
    // 0x800034FC: addiu       $a0, $sp, 0x72
    ctx->r4 = ADD32(ctx->r29, 0X72);
    // 0x80003500: jal         0x800042CC
    // 0x80003504: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    sndp_get_state_counts(rdram, ctx);
        goto after_0;
    // 0x80003504: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_0:
    // 0x80003508: b           L_800040E0
    // 0x8000350C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x8000350C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80003510:
    // 0x80003510: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80003514: lw          $s6, 0x4($s2)
    ctx->r22 = MEM_W(ctx->r18, 0X4);
    // 0x80003518: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x8000351C: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003520: nop

    // 0x80003524: slti        $at, $v1, 0x101
    ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
    // 0x80003528: bne         $at, $zero, L_8000355C
    if (ctx->r1 != 0) {
        // 0x8000352C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000355C;
    }
    // 0x8000352C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80003530: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x80003534: beq         $v0, $at, L_8000400C
    if (ctx->r2 == ctx->r1) {
        // 0x80003538: addiu       $at, $zero, 0x400
        ctx->r1 = ADD32(0, 0X400);
            goto L_8000400C;
    }
    // 0x80003538: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x8000353C: beq         $v0, $at, L_80003A0C
    if (ctx->r2 == ctx->r1) {
        // 0x80003540: addiu       $at, $zero, 0x800
        ctx->r1 = ADD32(0, 0X800);
            goto L_80003A0C;
    }
    // 0x80003540: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x80003544: beq         $v0, $at, L_80003D78
    if (ctx->r2 == ctx->r1) {
        // 0x80003548: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_80003D78;
    }
    // 0x80003548: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8000354C: beq         $v0, $at, L_80003A10
    if (ctx->r2 == ctx->r1) {
        // 0x80003550: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_80003A10;
    }
    // 0x80003550: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80003554: b           L_80004094
    // 0x80003558: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x80003558: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_8000355C:
    // 0x8000355C: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x80003560: bne         $at, $zero, L_80003580
    if (ctx->r1 != 0) {
        // 0x80003564: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_80003580;
    }
    // 0x80003564: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80003568: beq         $v0, $at, L_80003FF0
    if (ctx->r2 == ctx->r1) {
        // 0x8000356C: addiu       $at, $zero, 0x100
        ctx->r1 = ADD32(0, 0X100);
            goto L_80003FF0;
    }
    // 0x8000356C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80003570: beq         $v0, $at, L_80003C08
    if (ctx->r2 == ctx->r1) {
        // 0x80003574: nop
    
            goto L_80003C08;
    }
    // 0x80003574: nop

    // 0x80003578: b           L_80004094
    // 0x8000357C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x8000357C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80003580:
    // 0x80003580: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x80003584: bne         $at, $zero, L_800035A0
    if (ctx->r1 != 0) {
        // 0x80003588: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_800035A0;
    }
    // 0x80003588: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8000358C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80003590: beq         $v0, $at, L_80003E8C
    if (ctx->r2 == ctx->r1) {
        // 0x80003594: nop
    
            goto L_80003E8C;
    }
    // 0x80003594: nop

    // 0x80003598: b           L_80004094
    // 0x8000359C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x8000359C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_800035A0:
    // 0x800035A0: sltiu       $at, $t1, 0x10
    ctx->r1 = ctx->r9 < 0X10 ? 1 : 0;
    // 0x800035A4: beq         $at, $zero, L_80004090
    if (ctx->r1 == 0) {
        // 0x800035A8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80004090;
    }
    // 0x800035A8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800035AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800035B0: addu        $at, $at, $t1
    gpr jr_addend_800035BC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800035B4: lw          $t1, 0x5140($at)
    ctx->r9 = ADD32(ctx->r1, 0X5140);
    // 0x800035B8: nop

    // 0x800035BC: jr          $t1
    // 0x800035C0: nop

    switch (jr_addend_800035BC >> 2) {
        case 0: goto L_800035C4; break;
        case 1: goto L_80003A0C; break;
        case 2: goto L_80004090; break;
        case 3: goto L_80003B2C; break;
        case 4: goto L_80004090; break;
        case 5: goto L_80004090; break;
        case 6: goto L_80004090; break;
        case 7: goto L_80003C8C; break;
        case 8: goto L_80004090; break;
        case 9: goto L_80004090; break;
        case 10: goto L_80004090; break;
        case 11: goto L_80004090; break;
        case 12: goto L_80004090; break;
        case 13: goto L_80004090; break;
        case 14: goto L_80004090; break;
        case 15: goto L_80003BA4; break;
        default: switch_error(__func__, 0x800035BC, 0x800E5140);
    }
    // 0x800035C0: nop

L_800035C4:
    // 0x800035C4: lbu         $v0, 0x3F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3F);
    // 0x800035C8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800035CC: beq         $v0, $at, L_800035E0
    if (ctx->r2 == ctx->r1) {
        // 0x800035D0: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_800035E0;
    }
    // 0x800035D0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800035D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800035D8: bne         $v0, $at, L_800040E0
    if (ctx->r2 != ctx->r1) {
        // 0x800035DC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800040E0;
    }
    // 0x800035DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800035E0:
    // 0x800035E0: sh          $zero, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = 0;
    // 0x800035E4: lbu         $t2, 0x36($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X36);
    // 0x800035E8: sb          $zero, 0xCC($sp)
    MEM_B(0XCC, ctx->r29) = 0;
    // 0x800035EC: sh          $t2, 0xC8($sp)
    MEM_H(0XC8, ctx->r29) = ctx->r10;
    // 0x800035F0: lw          $t4, 0x48($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X48);
    // 0x800035F4: lh          $t3, -0x33CC($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X33CC);
    // 0x800035F8: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x800035FC: slt         $s0, $t3, $t4
    ctx->r16 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80003600: xori        $s0, $s0, 0x1
    ctx->r16 = ctx->r16 ^ 0X1;
    // 0x80003604: beq         $s0, $zero, L_80003620
    if (ctx->r16 == 0) {
        // 0x80003608: nop
    
            goto L_80003620;
    }
    // 0x80003608: nop

    // 0x8000360C: lbu         $t5, 0x3E($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003610: nop

    // 0x80003614: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80003618: beq         $t6, $zero, L_80003634
    if (ctx->r14 == 0) {
        // 0x8000361C: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_80003634;
    }
    // 0x8000361C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_80003620:
    // 0x80003620: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003624: jal         0x800C9A68
    // 0x80003628: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    alSynAllocVoice(rdram, ctx);
        goto after_1;
    // 0x80003628: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    after_1:
    // 0x8000362C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80003630: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_80003634:
    // 0x80003634: sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30 << 16);
    // 0x80003638: beq         $t7, $zero, L_80003650
    if (ctx->r15 == 0) {
        // 0x8000363C: sra         $t8, $a2, 16
        ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
            goto L_80003650;
    }
    // 0x8000363C: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003640: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003644: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x80003648: jal         0x80065CC0
    // 0x8000364C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_80065A80(rdram, ctx);
        goto after_2;
    // 0x8000364C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_2:
L_80003650:
    // 0x80003650: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80003654: lbu         $v0, 0x3E($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003658: bne         $t9, $zero, L_8000377C
    if (ctx->r25 != 0) {
        // 0x8000365C: addiu       $s3, $s1, 0xC
        ctx->r19 = ADD32(ctx->r17, 0XC);
            goto L_8000377C;
    }
    // 0x8000365C: addiu       $s3, $s1, 0xC
    ctx->r19 = ADD32(ctx->r17, 0XC);
    // 0x80003660: andi        $t0, $v0, 0x12
    ctx->r8 = ctx->r2 & 0X12;
    // 0x80003664: bne         $t0, $zero, L_8000367C
    if (ctx->r8 != 0) {
        // 0x80003668: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8000367C;
    }
    // 0x80003668: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8000366C: lw          $t1, 0x38($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X38);
    // 0x80003670: nop

    // 0x80003674: blez        $t1, L_800036A4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80003678: nop
    
            goto L_800036A4;
    }
    // 0x80003678: nop

L_8000367C:
    // 0x8000367C: lw          $t3, 0x38($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X38);
    // 0x80003680: sb          $t2, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r10;
    // 0x80003684: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80003688: sw          $t4, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r12;
    // 0x8000368C: addiu       $a0, $s7, 0x14
    ctx->r4 = ADD32(ctx->r23, 0X14);
    // 0x80003690: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80003694: jal         0x800C970C
    // 0x80003698: ori         $a2, $zero, 0x8235
    ctx->r6 = 0 | 0X8235;
    alEvtqPostEvent(rdram, ctx);
        goto after_3;
    // 0x80003698: ori         $a2, $zero, 0x8235
    ctx->r6 = 0 | 0X8235;
    after_3:
    // 0x8000369C: b           L_800040E0
    // 0x800036A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x800036A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800036A4:
    // 0x800036A4: beq         $s0, $zero, L_8000376C
    if (ctx->r16 == 0) {
        // 0x800036A8: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8000376C;
    }
    // 0x800036A8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800036AC: lw          $v0, -0x33DC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X33DC);
    // 0x800036B0: addiu       $s4, $sp, 0x5C
    ctx->r20 = ADD32(ctx->r29, 0X5C);
    // 0x800036B4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800036B8: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_800036BC:
    // 0x800036BC: lbu         $t5, 0x36($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X36);
    // 0x800036C0: lbu         $t6, 0x36($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X36);
    // 0x800036C4: nop

    // 0x800036C8: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800036CC: bne         $at, $zero, L_80003724
    if (ctx->r1 != 0) {
        // 0x800036D0: nop
    
            goto L_80003724;
    }
    // 0x800036D0: nop

    // 0x800036D4: lbu         $t7, 0x3F($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3F);
    // 0x800036D8: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800036DC: beq         $s2, $t7, L_80003724
    if (ctx->r18 == ctx->r15) {
        // 0x800036E0: addiu       $a0, $s7, 0x14
        ctx->r4 = ADD32(ctx->r23, 0X14);
            goto L_80003724;
    }
    // 0x800036E0: addiu       $a0, $s7, 0x14
    ctx->r4 = ADD32(ctx->r23, 0X14);
    // 0x800036E4: sh          $t8, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r24;
    // 0x800036E8: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x800036EC: sb          $s3, 0x3F($v0)
    MEM_B(0X3F, ctx->r2) = ctx->r19;
    // 0x800036F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800036F4: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x800036F8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800036FC: jal         0x800C970C
    // 0x80003700: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x80003700: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    after_4:
    // 0x80003704: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80003708: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x8000370C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003710: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x80003714: jal         0x800C9BB0
    // 0x80003718: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    alSynSetVol(rdram, ctx);
        goto after_5;
    // 0x80003718: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    after_5:
    // 0x8000371C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80003720: nop

L_80003724:
    // 0x80003724: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80003728: beq         $s0, $zero, L_80003738
    if (ctx->r16 == 0) {
        // 0x8000372C: nop
    
            goto L_80003738;
    }
    // 0x8000372C: nop

    // 0x80003730: bne         $v0, $zero, L_800036BC
    if (ctx->r2 != 0) {
        // 0x80003734: nop
    
            goto L_800036BC;
    }
    // 0x80003734: nop

L_80003738:
    // 0x80003738: bne         $s0, $zero, L_8000375C
    if (ctx->r16 != 0) {
        // 0x8000373C: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8000375C;
    }
    // 0x8000373C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80003740: sw          $t9, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r25;
    // 0x80003744: addiu       $a0, $s7, 0x14
    ctx->r4 = ADD32(ctx->r23, 0X14);
    // 0x80003748: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000374C: jal         0x800C970C
    // 0x80003750: addiu       $a2, $zero, 0x3E9
    ctx->r6 = ADD32(0, 0X3E9);
    alEvtqPostEvent(rdram, ctx);
        goto after_6;
    // 0x80003750: addiu       $a2, $zero, 0x3E9
    ctx->r6 = ADD32(0, 0X3E9);
    after_6:
    // 0x80003754: b           L_800040E0
    // 0x80003758: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x80003758: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000375C:
    // 0x8000375C: jal         0x8000410C
    // 0x80003760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_7;
    // 0x80003760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80003764: b           L_800040E0
    // 0x80003768: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x80003768: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000376C:
    // 0x8000376C: jal         0x8000410C
    // 0x80003770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_8;
    // 0x80003770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80003774: b           L_800040E0
    // 0x80003778: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x80003778: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000377C:
    // 0x8000377C: ori         $t0, $v0, 0x4
    ctx->r8 = ctx->r2 | 0X4;
    // 0x80003780: sb          $t0, 0x3E($s1)
    MEM_B(0X3E, ctx->r17) = ctx->r8;
    // 0x80003784: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x80003788: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x8000378C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80003790: jal         0x800C9C50
    // 0x80003794: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    alSynStartVoice(rdram, ctx);
        goto after_9;
    // 0x80003794: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    after_9:
    // 0x80003798: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000379C: sb          $t1, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r9;
    // 0x800037A0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800037A4: lh          $t2, -0x33CC($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X33CC);
    // 0x800037A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800037AC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800037B0: sh          $t3, -0x33CC($at)
    MEM_H(-0X33CC, ctx->r1) = ctx->r11;
    // 0x800037B4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800037B8: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800037BC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800037C0: lwc1        $f16, 0x28($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800037C4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800037C8: lh          $t3, 0x34($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X34);
    // 0x800037CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800037D0: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    // 0x800037D4: lbu         $t7, 0x2($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X2);
    // 0x800037D8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800037DC: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800037E0: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x800037E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800037E8: lw          $t6, -0x5E58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E58);
    // 0x800037EC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800037F0: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x800037F4: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800037F8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800037FC: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80003800: mflo        $t4
    ctx->r12 = lo;
    // 0x80003804: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80003808: nop

    // 0x8000380C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80003810: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003814: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003818: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8000381C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80003820: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80003824: lbu         $t5, 0xD($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XD);
    // 0x80003828: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x8000382C: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003830: mflo        $t7
    ctx->r15 = lo;
    // 0x80003834: nop

    // 0x80003838: nop

    // 0x8000383C: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80003840: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003844: mflo        $t8
    ctx->r24 = lo;
    // 0x80003848: nop

    // 0x8000384C: nop

    // 0x80003850: multu       $t1, $t8
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003854: mflo        $a0
    ctx->r4 = lo;
    // 0x80003858: nop

    // 0x8000385C: nop

    // 0x80003860: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003864: mflo        $t6
    ctx->r14 = lo;
    // 0x80003868: addiu       $a0, $t6, -0x1
    ctx->r4 = ADD32(ctx->r14, -0X1);
    // 0x8000386C: bgez        $a0, L_8000387C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003870: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8000387C;
    }
    // 0x80003870: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003874: b           L_8000387C
    // 0x80003878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000387C;
    // 0x80003878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000387C:
    // 0x8000387C: lw          $t9, -0x33D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33D0);
    // 0x80003880: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003884: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003888: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000388C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003890: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80003894: mflo        $v0
    ctx->r2 = lo;
    // 0x80003898: srl         $t0, $v0, 8
    ctx->r8 = S32(U32(ctx->r2) >> 8);
    // 0x8000389C: jal         0x800C9BB0
    // 0x800038A0: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    alSynSetVol(rdram, ctx);
        goto after_10;
    // 0x800038A0: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    after_10:
    // 0x800038A4: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x800038A8: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x800038AC: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800038B0: sra         $t2, $a2, 16
    ctx->r10 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800038B4: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800038B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800038BC: jal         0x800C9BB0
    // 0x800038C0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_11;
    // 0x800038C0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_11:
    // 0x800038C4: lbu         $t3, 0x3C($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X3C);
    // 0x800038C8: lbu         $t4, 0xC($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XC);
    // 0x800038CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800038D0: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x800038D4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800038D8: blez        $v1, L_800038E8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800038DC: addiu       $a2, $zero, 0x7F
        ctx->r6 = ADD32(0, 0X7F);
            goto L_800038E8;
    }
    // 0x800038DC: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x800038E0: b           L_800038E8
    // 0x800038E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800038E8;
    // 0x800038E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800038E8:
    // 0x800038E8: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800038EC: beq         $at, $zero, L_8000390C
    if (ctx->r1 == 0) {
        // 0x800038F0: nop
    
            goto L_8000390C;
    }
    // 0x800038F0: nop

    // 0x800038F4: blez        $v1, L_80003904
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800038F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003904;
    }
    // 0x800038F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800038FC: b           L_8000390C
    // 0x80003900: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
        goto L_8000390C;
    // 0x80003900: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
L_80003904:
    // 0x80003904: b           L_8000390C
    // 0x80003908: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
        goto L_8000390C;
    // 0x80003908: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_8000390C:
    // 0x8000390C: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003910: jal         0x80065D60
    // 0x80003914: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alSynSetPan(rdram, ctx);
        goto after_12;
    // 0x80003914: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_12:
    // 0x80003918: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8000391C: lwc1        $f8, 0x28($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003920: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003924: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80003928: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000392C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80003930: jal         0x800C9CE0
    // 0x80003934: nop

    alSynSetPitch(rdram, ctx);
        goto after_13;
    // 0x80003934: nop

    after_13:
    // 0x80003938: lbu         $t7, 0x3($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X3);
    // 0x8000393C: lbu         $t5, 0x3D($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X3D);
    // 0x80003940: andi        $t1, $t7, 0xF
    ctx->r9 = ctx->r15 & 0XF;
    // 0x80003944: addu        $v1, $t5, $t1
    ctx->r3 = ADD32(ctx->r13, ctx->r9);
    // 0x80003948: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8000394C: bgez        $t8, L_8000395C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80003950: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8000395C;
    }
    // 0x80003950: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80003954: b           L_80003960
    // 0x80003958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003960;
    // 0x80003958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000395C:
    // 0x8000395C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80003960:
    // 0x80003960: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80003964: bne         $at, $zero, L_80003974
    if (ctx->r1 != 0) {
        // 0x80003968: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80003974;
    }
    // 0x80003968: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000396C: b           L_80003988
    // 0x80003970: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
        goto L_80003988;
    // 0x80003970: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80003974:
    // 0x80003974: bgez        $v1, L_80003984
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80003978: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80003984;
    }
    // 0x80003978: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000397C: b           L_80003984
    // 0x80003980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003984;
    // 0x80003980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003984:
    // 0x80003984: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80003988:
    // 0x80003988: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x8000398C: jal         0x800C9D70
    // 0x80003990: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_14;
    // 0x80003990: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    after_14:
    // 0x80003994: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80003998: sh          $t6, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r14;
    // 0x8000399C: sw          $s1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r17;
    // 0x800039A0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800039A4: lwc1        $f4, 0x2C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800039A8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800039AC: lwc1        $f8, 0x28($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800039B0: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800039B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800039B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800039BC: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x800039C0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800039C4: nop

    // 0x800039C8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800039CC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800039D0: nop

    // 0x800039D4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800039D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800039DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800039E0: nop

    // 0x800039E4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800039E8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800039EC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800039F0: jal         0x800C970C
    // 0x800039F4: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_15;
    // 0x800039F4: nop

    after_15:
    // 0x800039F8: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x800039FC: nop

    // 0x80003A00: andi        $t3, $v0, 0x2D1
    ctx->r11 = ctx->r2 & 0X2D1;
    // 0x80003A04: b           L_80004094
    // 0x80003A08: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_80004094;
    // 0x80003A08: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80003A0C:
    // 0x80003A0C: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
L_80003A10:
    // 0x80003A10: bne         $v1, $at, L_80003A2C
    if (ctx->r3 != ctx->r1) {
        // 0x80003A14: nop
    
            goto L_80003A2C;
    }
    // 0x80003A14: nop

    // 0x80003A18: lbu         $t4, 0x3E($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003A1C: nop

    // 0x80003A20: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x80003A24: beq         $t7, $zero, L_80003B24
    if (ctx->r15 == 0) {
        // 0x80003A28: nop
    
            goto L_80003B24;
    }
    // 0x80003A28: nop

L_80003A2C:
    // 0x80003A2C: lbu         $v0, 0x3F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003A30: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    // 0x80003A34: beq         $v0, $fp, L_80003A58
    if (ctx->r2 == ctx->r30) {
        // 0x80003A38: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80003A58;
    }
    // 0x80003A38: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003A3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80003A40: beq         $v0, $at, L_80003B00
    if (ctx->r2 == ctx->r1) {
        // 0x80003A44: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80003B00;
    }
    // 0x80003A44: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80003A48: beq         $v0, $at, L_80003B00
    if (ctx->r2 == ctx->r1) {
        // 0x80003A4C: nop
    
            goto L_80003B00;
    }
    // 0x80003A4C: nop

    // 0x80003A50: b           L_80003B14
    // 0x80003A54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_80003B14;
    // 0x80003A54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80003A58:
    // 0x80003A58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80003A5C: jal         0x800041FC
    // 0x80003A60: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    static_3_800041FC(rdram, ctx);
        goto after_16;
    // 0x80003A60: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_16:
    // 0x80003A64: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80003A68: lwc1        $f6, 0x28($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003A6C: lw          $t1, 0x8($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X8);
    // 0x80003A70: lwc1        $f10, 0x2C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003A74: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80003A78: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003A7C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80003A80: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003A84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003A88: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80003A8C: nop

    // 0x80003A90: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80003A94: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80003A98: nop

    // 0x80003A9C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80003AA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003AA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003AA8: nop

    // 0x80003AAC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80003AB0: mfc1        $s0, $f18
    ctx->r16 = (int32_t)ctx->f18.u32l;
    // 0x80003AB4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80003AB8: jal         0x800C9BB0
    // 0x80003ABC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_17;
    // 0x80003ABC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_17:
    // 0x80003AC0: beq         $s0, $zero, L_80003AEC
    if (ctx->r16 == 0) {
        // 0x80003AC4: addiu       $t6, $zero, 0x80
        ctx->r14 = ADD32(0, 0X80);
            goto L_80003AEC;
    }
    // 0x80003AC4: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80003AC8: sh          $t6, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r14;
    // 0x80003ACC: sw          $s1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r17;
    // 0x80003AD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003AD4: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80003AD8: jal         0x800C970C
    // 0x80003ADC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_18;
    // 0x80003ADC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
    // 0x80003AE0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80003AE4: b           L_80003AF4
    // 0x80003AE8: sb          $t9, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r25;
        goto L_80003AF4;
    // 0x80003AE8: sb          $t9, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r25;
L_80003AEC:
    // 0x80003AEC: jal         0x8000410C
    // 0x80003AF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_19;
    // 0x80003AF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
L_80003AF4:
    // 0x80003AF4: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003AF8: b           L_80003B14
    // 0x80003AFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_80003B14;
    // 0x80003AFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80003B00:
    // 0x80003B00: jal         0x8000410C
    // 0x80003B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_20;
    // 0x80003B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80003B08: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003B0C: nop

    // 0x80003B10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80003B14:
    // 0x80003B14: bne         $v1, $at, L_80003B24
    if (ctx->r3 != ctx->r1) {
        // 0x80003B18: addiu       $t0, $zero, 0x1000
        ctx->r8 = ADD32(0, 0X1000);
            goto L_80003B24;
    }
    // 0x80003B18: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x80003B1C: sh          $t0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r8;
    // 0x80003B20: andi        $v1, $t0, 0xFFFF
    ctx->r3 = ctx->r8 & 0XFFFF;
L_80003B24:
    // 0x80003B24: b           L_80004094
    // 0x80003B28: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x80003B28: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80003B2C:
    // 0x80003B2C: lw          $t2, 0x8($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X8);
    // 0x80003B30: lbu         $t3, 0x3F($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003B34: sb          $t2, 0x3C($s1)
    MEM_B(0X3C, ctx->r17) = ctx->r10;
    // 0x80003B38: bne         $fp, $t3, L_80003B90
    if (ctx->r30 != ctx->r11) {
        // 0x80003B3C: nop
    
            goto L_80003B90;
    }
    // 0x80003B3C: nop

    // 0x80003B40: lbu         $t7, 0xC($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XC);
    // 0x80003B44: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x80003B48: addu        $v1, $t4, $t7
    ctx->r3 = ADD32(ctx->r12, ctx->r15);
    // 0x80003B4C: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x80003B50: blez        $v1, L_80003B60
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80003B54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003B60;
    }
    // 0x80003B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003B58: b           L_80003B60
    // 0x80003B5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80003B60;
    // 0x80003B5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80003B60:
    // 0x80003B60: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x80003B64: beq         $at, $zero, L_80003B84
    if (ctx->r1 == 0) {
        // 0x80003B68: addiu       $a2, $zero, 0x7F
        ctx->r6 = ADD32(0, 0X7F);
            goto L_80003B84;
    }
    // 0x80003B68: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x80003B6C: blez        $v1, L_80003B7C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80003B70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003B7C;
    }
    // 0x80003B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003B74: b           L_80003B84
    // 0x80003B78: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
        goto L_80003B84;
    // 0x80003B78: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
L_80003B7C:
    // 0x80003B7C: b           L_80003B84
    // 0x80003B80: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
        goto L_80003B84;
    // 0x80003B80: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_80003B84:
    // 0x80003B84: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003B88: jal         0x80065D60
    // 0x80003B8C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    alSynSetPan(rdram, ctx);
        goto after_21;
    // 0x80003B8C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    after_21:
L_80003B90:
    // 0x80003B90: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003B94: nop

    // 0x80003B98: andi        $t5, $v0, 0x2D1
    ctx->r13 = ctx->r2 & 0X2D1;
    // 0x80003B9C: b           L_80004094
    // 0x80003BA0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80004094;
    // 0x80003BA0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80003BA4:
    // 0x80003BA4: lwc1        $f4, 0x8($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80003BA8: lbu         $t1, 0x3F($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003BAC: swc1        $f4, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f4.u32l;
    // 0x80003BB0: bne         $fp, $t1, L_80003BF4
    if (ctx->r30 != ctx->r9) {
        // 0x80003BB4: nop
    
            goto L_80003BF4;
    }
    // 0x80003BB4: nop

    // 0x80003BB8: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003BBC: lwc1        $f8, 0x28($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003BC0: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003BC4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80003BC8: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003BCC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80003BD0: jal         0x800C9CE0
    // 0x80003BD4: nop

    alSynSetPitch(rdram, ctx);
        goto after_22;
    // 0x80003BD4: nop

    after_22:
    // 0x80003BD8: lbu         $t8, 0x3E($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003BDC: nop

    // 0x80003BE0: andi        $t6, $t8, 0x20
    ctx->r14 = ctx->r24 & 0X20;
    // 0x80003BE4: beq         $t6, $zero, L_80003BF4
    if (ctx->r14 == 0) {
        // 0x80003BE8: nop
    
            goto L_80003BF4;
    }
    // 0x80003BE8: nop

    // 0x80003BEC: jal         0x8000418C
    // 0x80003BF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_apply_pitch_slide(rdram, ctx);
        goto after_23;
    // 0x80003BF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
L_80003BF4:
    // 0x80003BF4: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003BF8: nop

    // 0x80003BFC: andi        $t9, $v0, 0x2D1
    ctx->r25 = ctx->r2 & 0X2D1;
    // 0x80003C00: b           L_80004094
    // 0x80003C04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80004094;
    // 0x80003C04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80003C08:
    // 0x80003C08: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
    // 0x80003C0C: lbu         $t2, 0x3F($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003C10: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003C14: bne         $fp, $t2, L_80003C78
    if (ctx->r30 != ctx->r10) {
        // 0x80003C18: sb          $t0, 0x3D($s1)
        MEM_B(0X3D, ctx->r17) = ctx->r8;
            goto L_80003C78;
    }
    // 0x80003C18: sb          $t0, 0x3D($s1)
    MEM_B(0X3D, ctx->r17) = ctx->r8;
    // 0x80003C1C: lbu         $t4, 0x3($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X3);
    // 0x80003C20: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x80003C24: andi        $t7, $t4, 0xF
    ctx->r15 = ctx->r12 & 0XF;
    // 0x80003C28: addu        $v1, $t3, $t7
    ctx->r3 = ADD32(ctx->r11, ctx->r15);
    // 0x80003C2C: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x80003C30: bgez        $t5, L_80003C40
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80003C34: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_80003C40;
    }
    // 0x80003C34: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x80003C38: b           L_80003C44
    // 0x80003C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003C44;
    // 0x80003C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003C40:
    // 0x80003C40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80003C44:
    // 0x80003C44: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80003C48: bne         $at, $zero, L_80003C58
    if (ctx->r1 != 0) {
        // 0x80003C4C: nop
    
            goto L_80003C58;
    }
    // 0x80003C4C: nop

    // 0x80003C50: b           L_80003C6C
    // 0x80003C54: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
        goto L_80003C6C;
    // 0x80003C54: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80003C58:
    // 0x80003C58: bgez        $v1, L_80003C68
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80003C5C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80003C68;
    }
    // 0x80003C5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80003C60: b           L_80003C68
    // 0x80003C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003C68;
    // 0x80003C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003C68:
    // 0x80003C68: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80003C6C:
    // 0x80003C6C: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003C70: jal         0x800C9D70
    // 0x80003C74: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_24;
    // 0x80003C74: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    after_24:
L_80003C78:
    // 0x80003C78: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003C7C: nop

    // 0x80003C80: andi        $t1, $v0, 0x2D1
    ctx->r9 = ctx->r2 & 0X2D1;
    // 0x80003C84: b           L_80004094
    // 0x80003C88: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80004094;
    // 0x80003C88: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80003C8C:
    // 0x80003C8C: lw          $t8, 0x8($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X8);
    // 0x80003C90: lbu         $t6, 0x3F($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003C94: sh          $t8, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r24;
    // 0x80003C98: bne         $fp, $t6, L_80003D64
    if (ctx->r30 != ctx->r14) {
        // 0x80003C9C: nop
    
            goto L_80003D64;
    }
    // 0x80003C9C: nop

    // 0x80003CA0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80003CA4: lh          $t8, 0x34($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X34);
    // 0x80003CA8: lbu         $t1, 0xD($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0XD);
    // 0x80003CAC: lbu         $t0, 0x2($s6)
    ctx->r8 = MEM_BU(ctx->r22, 0X2);
    // 0x80003CB0: multu       $t1, $t8
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003CB4: andi        $t2, $t0, 0x3F
    ctx->r10 = ctx->r8 & 0X3F;
    // 0x80003CB8: lbu         $t0, 0xD($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XD);
    // 0x80003CBC: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80003CC0: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x80003CC4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80003CC8: lw          $t9, -0x5E58($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E58);
    // 0x80003CCC: nop

    // 0x80003CD0: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x80003CD4: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x80003CD8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80003CDC: mflo        $t6
    ctx->r14 = lo;
    // 0x80003CE0: nop

    // 0x80003CE4: nop

    // 0x80003CE8: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003CEC: mflo        $t2
    ctx->r10 = lo;
    // 0x80003CF0: nop

    // 0x80003CF4: nop

    // 0x80003CF8: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80003CFC: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003D00: mflo        $t9
    ctx->r25 = lo;
    // 0x80003D04: nop

    // 0x80003D08: nop

    // 0x80003D0C: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003D10: mflo        $a0
    ctx->r4 = lo;
    // 0x80003D14: nop

    // 0x80003D18: nop

    // 0x80003D1C: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003D20: mflo        $t4
    ctx->r12 = lo;
    // 0x80003D24: addiu       $a0, $t4, -0x1
    ctx->r4 = ADD32(ctx->r12, -0X1);
    // 0x80003D28: bgez        $a0, L_80003D38
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003D2C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80003D38;
    }
    // 0x80003D2C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003D30: b           L_80003D38
    // 0x80003D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003D38;
    // 0x80003D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003D38:
    // 0x80003D38: lw          $t3, -0x33D0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X33D0);
    // 0x80003D3C: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003D40: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003D44: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003D48: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x80003D4C: mflo        $v0
    ctx->r2 = lo;
    // 0x80003D50: srl         $t5, $v0, 8
    ctx->r13 = S32(U32(ctx->r2) >> 8);
    // 0x80003D54: sll         $a2, $t5, 16
    ctx->r6 = S32(ctx->r13 << 16);
    // 0x80003D58: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003D5C: jal         0x800C9BB0
    // 0x80003D60: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    alSynSetVol(rdram, ctx);
        goto after_25;
    // 0x80003D60: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_25:
L_80003D64:
    // 0x80003D64: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003D68: nop

    // 0x80003D6C: andi        $t8, $v0, 0x2D1
    ctx->r24 = ctx->r2 & 0X2D1;
    // 0x80003D70: b           L_80004094
    // 0x80003D74: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_80004094;
    // 0x80003D74: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80003D78:
    // 0x80003D78: lbu         $t6, 0x3F($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003D7C: nop

    // 0x80003D80: bne         $fp, $t6, L_80003E84
    if (ctx->r30 != ctx->r14) {
        // 0x80003D84: nop
    
            goto L_80003E84;
    }
    // 0x80003D84: nop

    // 0x80003D88: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80003D8C: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003D90: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80003D94: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003D98: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80003D9C: lh          $t6, 0x34($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X34);
    // 0x80003DA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80003DA4: lbu         $t8, 0xD($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XD);
    // 0x80003DA8: lbu         $t9, 0x2($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X2);
    // 0x80003DAC: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80003DB0: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003DB4: andi        $t4, $t9, 0x3F
    ctx->r12 = ctx->r25 & 0X3F;
    // 0x80003DB8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80003DBC: lw          $t7, -0x5E58($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E58);
    // 0x80003DC0: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x80003DC4: addu        $t5, $t7, $t3
    ctx->r13 = ADD32(ctx->r15, ctx->r11);
    // 0x80003DC8: lh          $t1, 0x0($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X0);
    // 0x80003DCC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80003DD0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80003DD4: mflo        $t0
    ctx->r8 = lo;
    // 0x80003DD8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80003DDC: nop

    // 0x80003DE0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80003DE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003DE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003DEC: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x80003DF0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80003DF4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80003DF8: lbu         $t2, 0xD($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0XD);
    // 0x80003DFC: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
    // 0x80003E00: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003E04: mflo        $t9
    ctx->r25 = lo;
    // 0x80003E08: nop

    // 0x80003E0C: nop

    // 0x80003E10: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80003E14: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003E18: mflo        $t4
    ctx->r12 = lo;
    // 0x80003E1C: nop

    // 0x80003E20: nop

    // 0x80003E24: multu       $t1, $t4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003E28: mflo        $a0
    ctx->r4 = lo;
    // 0x80003E2C: nop

    // 0x80003E30: nop

    // 0x80003E34: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003E38: mflo        $t7
    ctx->r15 = lo;
    // 0x80003E3C: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    // 0x80003E40: bgez        $a0, L_80003E50
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003E44: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80003E50;
    }
    // 0x80003E44: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003E48: b           L_80003E50
    // 0x80003E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003E50;
    // 0x80003E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003E50:
    // 0x80003E50: lw          $t3, -0x33D0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X33D0);
    // 0x80003E54: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003E58: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003E5C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003E60: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80003E64: mflo        $v0
    ctx->r2 = lo;
    // 0x80003E68: srl         $t5, $v0, 8
    ctx->r13 = S32(U32(ctx->r2) >> 8);
    // 0x80003E6C: sll         $a2, $t5, 16
    ctx->r6 = S32(ctx->r13 << 16);
    // 0x80003E70: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003E74: jal         0x800C9BB0
    // 0x80003E78: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    alSynSetVol(rdram, ctx);
        goto after_26;
    // 0x80003E78: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_26:
    // 0x80003E7C: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003E80: nop

L_80003E84:
    // 0x80003E84: b           L_80004094
    // 0x80003E88: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x80003E88: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80003E8C:
    // 0x80003E8C: lbu         $t6, 0x3E($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003E90: nop

    // 0x80003E94: andi        $t0, $t6, 0x2
    ctx->r8 = ctx->r14 & 0X2;
    // 0x80003E98: bne         $t0, $zero, L_80003FDC
    if (ctx->r8 != 0) {
        // 0x80003E9C: nop
    
            goto L_80003FDC;
    }
    // 0x80003E9C: nop

    // 0x80003EA0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80003EA4: lh          $t8, 0x34($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X34);
    // 0x80003EA8: lbu         $t5, 0xD($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XD);
    // 0x80003EAC: lbu         $t0, 0xD($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XD);
    // 0x80003EB0: multu       $t5, $t8
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003EB4: lbu         $t9, 0x2($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X2);
    // 0x80003EB8: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x80003EBC: andi        $t1, $t9, 0x3F
    ctx->r9 = ctx->r25 & 0X3F;
    // 0x80003EC0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80003EC4: lw          $t2, -0x5E58($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E58);
    // 0x80003EC8: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x80003ECC: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x80003ED0: lh          $t3, 0x0($t7)
    ctx->r11 = MEM_H(ctx->r15, 0X0);
    // 0x80003ED4: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    // 0x80003ED8: mflo        $t6
    ctx->r14 = lo;
    // 0x80003EDC: nop

    // 0x80003EE0: nop

    // 0x80003EE4: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003EE8: mflo        $t9
    ctx->r25 = lo;
    // 0x80003EEC: nop

    // 0x80003EF0: nop

    // 0x80003EF4: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80003EF8: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003EFC: mflo        $t1
    ctx->r9 = lo;
    // 0x80003F00: nop

    // 0x80003F04: nop

    // 0x80003F08: multu       $t3, $t1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003F0C: mflo        $a0
    ctx->r4 = lo;
    // 0x80003F10: nop

    // 0x80003F14: nop

    // 0x80003F18: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003F1C: mflo        $t2
    ctx->r10 = lo;
    // 0x80003F20: addiu       $a0, $t2, -0x1
    ctx->r4 = ADD32(ctx->r10, -0X1);
    // 0x80003F24: bgez        $a0, L_80003F34
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003F28: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80003F34;
    }
    // 0x80003F28: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003F2C: b           L_80003F34
    // 0x80003F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003F34;
    // 0x80003F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003F34:
    // 0x80003F34: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x80003F38: lwc1        $f6, 0x28($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003F3C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80003F40: lwc1        $f10, 0x2C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003F44: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80003F48: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80003F4C: lw          $t4, -0x33D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X33D0);
    // 0x80003F50: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80003F54: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003F58: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003F5C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003F60: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80003F64: mflo        $v0
    ctx->r2 = lo;
    // 0x80003F68: srl         $t7, $v0, 8
    ctx->r15 = S32(U32(ctx->r2) >> 8);
    // 0x80003F6C: sll         $a2, $t7, 16
    ctx->r6 = S32(ctx->r15 << 16);
    // 0x80003F70: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003F74: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80003F78: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80003F7C: nop

    // 0x80003F80: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80003F84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003F88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003F8C: nop

    // 0x80003F90: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80003F94: mfc1        $s0, $f18
    ctx->r16 = (int32_t)ctx->f18.u32l;
    // 0x80003F98: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80003F9C: jal         0x800C9BB0
    // 0x80003FA0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_27;
    // 0x80003FA0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_27:
    // 0x80003FA4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80003FA8: sh          $t0, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r8;
    // 0x80003FAC: sw          $s1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r17;
    // 0x80003FB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003FB4: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80003FB8: jal         0x800C970C
    // 0x80003FBC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_28;
    // 0x80003FBC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_28:
    // 0x80003FC0: lbu         $t9, 0x3E($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003FC4: nop

    // 0x80003FC8: andi        $t3, $t9, 0x20
    ctx->r11 = ctx->r25 & 0X20;
    // 0x80003FCC: beq         $t3, $zero, L_80003FDC
    if (ctx->r11 == 0) {
        // 0x80003FD0: nop
    
            goto L_80003FDC;
    }
    // 0x80003FD0: nop

    // 0x80003FD4: jal         0x8000418C
    // 0x80003FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_apply_pitch_slide(rdram, ctx);
        goto after_29;
    // 0x80003FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
L_80003FDC:
    // 0x80003FDC: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003FE0: nop

    // 0x80003FE4: andi        $t1, $v0, 0x2D1
    ctx->r9 = ctx->r2 & 0X2D1;
    // 0x80003FE8: b           L_80004094
    // 0x80003FEC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80004094;
    // 0x80003FEC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80003FF0:
    // 0x80003FF0: jal         0x8000410C
    // 0x80003FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_30;
    // 0x80003FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_30:
    // 0x80003FF8: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003FFC: nop

    // 0x80004000: andi        $t2, $v0, 0x2D1
    ctx->r10 = ctx->r2 & 0X2D1;
    // 0x80004004: b           L_80004094
    // 0x80004008: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_80004094;
    // 0x80004008: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8000400C:
    // 0x8000400C: lbu         $t4, 0x3E($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X3E);
    // 0x80004010: nop

    // 0x80004014: andi        $t7, $t4, 0x10
    ctx->r15 = ctx->r12 & 0X10;
    // 0x80004018: beq         $t7, $zero, L_8000407C
    if (ctx->r15 == 0) {
        // 0x8000401C: nop
    
            goto L_8000407C;
    }
    // 0x8000401C: nop

    // 0x80004020: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x80004024: lh          $a1, 0xA($s5)
    ctx->r5 = MEM_H(ctx->r21, 0XA);
    // 0x80004028: lw          $a2, 0x30($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X30);
    // 0x8000402C: jal         0x80004638
    // 0x80004030: nop

    sndp_play(rdram, ctx);
        goto after_31;
    // 0x80004030: nop

    after_31:
    // 0x80004034: beq         $v0, $zero, L_8000407C
    if (ctx->r2 == 0) {
        // 0x80004038: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000407C;
    }
    // 0x80004038: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000403C: lh          $a2, 0x34($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X34);
    // 0x80004040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80004044: jal         0x800049F8
    // 0x80004048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    sndp_set_param(rdram, ctx);
        goto after_32;
    // 0x80004048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_32:
    // 0x8000404C: lbu         $a2, 0x3C($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3C);
    // 0x80004050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004054: jal         0x800049F8
    // 0x80004058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_33;
    // 0x80004058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_33:
    // 0x8000405C: lbu         $a2, 0x3D($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3D);
    // 0x80004060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004064: jal         0x800049F8
    // 0x80004068: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    sndp_set_param(rdram, ctx);
        goto after_34;
    // 0x80004068: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_34:
    // 0x8000406C: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x80004070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004074: jal         0x800049F8
    // 0x80004078: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_35;
    // 0x80004078: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_35:
L_8000407C:
    // 0x8000407C: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80004080: nop

    // 0x80004084: andi        $t5, $v0, 0x2D1
    ctx->r13 = ctx->r2 & 0X2D1;
    // 0x80004088: b           L_80004094
    // 0x8000408C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80004094;
    // 0x8000408C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80004090:
    // 0x80004090: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80004094:
    // 0x80004094: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80004098: nop

    // 0x8000409C: beq         $v1, $zero, L_800040BC
    if (ctx->r3 == 0) {
        // 0x800040A0: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_800040BC;
    }
    // 0x800040A0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800040A4: bne         $v0, $zero, L_800040C0
    if (ctx->r2 != 0) {
        // 0x800040A8: lw          $t0, 0x80($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X80);
            goto L_800040C0;
    }
    // 0x800040A8: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x800040AC: lbu         $t8, 0x3E($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3E);
    // 0x800040B0: nop

    // 0x800040B4: andi        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 & 0X1;
    // 0x800040B8: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
L_800040BC:
    // 0x800040BC: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
L_800040C0:
    // 0x800040C0: nop

    // 0x800040C4: bne         $t0, $zero, L_800040E0
    if (ctx->r8 != 0) {
        // 0x800040C8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800040E0;
    }
    // 0x800040C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800040CC: beq         $v1, $zero, L_800040E0
    if (ctx->r3 == 0) {
        // 0x800040D0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800040E0;
    }
    // 0x800040D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800040D4: beq         $v0, $zero, L_800034C0
    if (ctx->r2 == 0) {
        // 0x800040D8: lw          $t7, 0x74($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X74);
            goto L_800034C0;
    }
    // 0x800040D8: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800040DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800040E0:
    // 0x800040E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800040E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800040E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800040EC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800040F0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800040F4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800040F8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800040FC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80004100: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80004104: jr          $ra
    // 0x80004108: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80004108: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void cheatlist_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AA1C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8008AA20: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8008AA24: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8008AA28: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8008AA2C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8008AA30: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8008AA34: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8008AA38: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8008AA3C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8008AA40: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8008AA44: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8008AA48: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8008AA4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008AA50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008AA54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008AA58: jal         0x800C492C
    // 0x8008AA5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_0;
    // 0x8008AA5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8008AA60: jal         0x800C484C
    // 0x8008AA64: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_1;
    // 0x8008AA64: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8008AA68: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8008AA6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008AA70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008AA74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008AA78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008AA7C: jal         0x800C48E4
    // 0x8008AA80: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x8008AA80: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x8008AA84: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x8008AA88: addiu       $s7, $s7, -0x5E0
    ctx->r23 = ADD32(ctx->r23, -0X5E0);
    // 0x8008AA8C: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8008AA90: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008AA94: addiu       $s5, $s5, 0x693C
    ctx->r21 = ADD32(ctx->r21, 0X693C);
    // 0x8008AA98: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8008AA9C: lw          $a3, 0x50($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X50);
    // 0x8008AAA0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008AAA4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AAA8: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8008AAAC: jal         0x800C49A0
    // 0x8008AAB0: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_3;
    // 0x8008AAB0: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_3:
    // 0x8008AAB4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008AAB8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008AABC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008AAC0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008AAC4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008AAC8: jal         0x800C48E4
    // 0x8008AACC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x8008AACC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8008AAD0: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x8008AAD4: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008AAD8: lw          $a3, 0x50($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X50);
    // 0x8008AADC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008AAE0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AAE4: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008AAE8: jal         0x800C49A0
    // 0x8008AAEC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x8008AAEC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x8008AAF0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008AAF4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008AAF8: lw          $v1, 0x31C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31C);
    // 0x8008AAFC: addiu       $a0, $a0, 0x7240
    ctx->r4 = ADD32(ctx->r4, 0X7240);
    // 0x8008AB00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008AB04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008AB08: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8008AB0C:
    // 0x8008AB0C: and         $t2, $v0, $v1
    ctx->r10 = ctx->r2 & ctx->r3;
    // 0x8008AB10: beq         $t2, $zero, L_8008AB28
    if (ctx->r10 == 0) {
        // 0x8008AB14: sll         $t5, $v0, 1
        ctx->r13 = S32(ctx->r2 << 1);
            goto L_8008AB28;
    }
    // 0x8008AB14: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x8008AB18: sll         $t3, $s3, 1
    ctx->r11 = S32(ctx->r19 << 1);
    // 0x8008AB1C: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8008AB20: sh          $s0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r16;
    // 0x8008AB24: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8008AB28:
    // 0x8008AB28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008AB2C: slti        $at, $s0, 0x20
    ctx->r1 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x8008AB30: bne         $at, $zero, L_8008AB0C
    if (ctx->r1 != 0) {
        // 0x8008AB34: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8008AB0C;
    }
    // 0x8008AB34: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8008AB38: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008AB3C: lw          $fp, 0x695C($fp)
    ctx->r30 = MEM_W(ctx->r30, 0X695C);
    // 0x8008AB40: addiu       $s2, $zero, 0x36
    ctx->r18 = ADD32(0, 0X36);
    // 0x8008AB44: sll         $t6, $fp, 3
    ctx->r14 = S32(ctx->r30 << 3);
    // 0x8008AB48: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8008AB4C: bne         $at, $zero, L_8008AB5C
    if (ctx->r1 != 0) {
        // 0x8008AB50: or          $fp, $t6, $zero
        ctx->r30 = ctx->r14 | 0;
            goto L_8008AB5C;
    }
    // 0x8008AB50: or          $fp, $t6, $zero
    ctx->r30 = ctx->r14 | 0;
    // 0x8008AB54: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x8008AB58: subu        $fp, $t7, $t6
    ctx->r30 = SUB32(ctx->r15, ctx->r14);
L_8008AB5C:
    // 0x8008AB5C: jal         0x800C484C
    // 0x8008AB60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_6;
    // 0x8008AB60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8008AB64: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008AB68: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008AB6C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008AB70: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008AB74: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008AB78: jal         0x800C48E4
    // 0x8008AB7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x8008AB7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8008AB80: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008AB84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008AB88: lw          $t9, 0x7234($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7234);
    // 0x8008AB8C: lw          $v1, 0x6980($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6980);
    // 0x8008AB90: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008AB94: lw          $s6, 0x71F0($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X71F0);
    // 0x8008AB98: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x8008AB9C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008ABA0: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8008ABA4: beq         $at, $zero, L_8008ACDC
    if (ctx->r1 == 0) {
        // 0x8008ABA8: addiu       $s6, $s6, 0x2
        ctx->r22 = ADD32(ctx->r22, 0X2);
            goto L_8008ACDC;
    }
    // 0x8008ABA8: addiu       $s6, $s6, 0x2
    ctx->r22 = ADD32(ctx->r22, 0X2);
    // 0x8008ABAC: slt         $at, $v1, $s3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8008ABB0: beq         $at, $zero, L_8008ACDC
    if (ctx->r1 == 0) {
        // 0x8008ABB4: sll         $t0, $v1, 1
        ctx->r8 = S32(ctx->r3 << 1);
            goto L_8008ACDC;
    }
    // 0x8008ABB4: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x8008ABB8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008ABBC: addiu       $t1, $t1, 0x7240
    ctx->r9 = ADD32(ctx->r9, 0X7240);
    // 0x8008ABC0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008ABC4: addiu       $s4, $s4, 0x7206
    ctx->r20 = ADD32(ctx->r20, 0X7206);
    // 0x8008ABC8: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
L_8008ABCC:
    // 0x8008ABCC: lh          $t2, 0x0($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X0);
    // 0x8008ABD0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008ABD4: bne         $s0, $t2, L_8008ABF0
    if (ctx->r16 != ctx->r10) {
        // 0x8008ABD8: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008ABF0;
    }
    // 0x8008ABD8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008ABDC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8008ABE0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008ABE4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008ABE8: jal         0x800C48E4
    // 0x8008ABEC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x8008ABEC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_8:
L_8008ABF0:
    // 0x8008ABF0: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x8008ABF4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008ABF8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008ABFC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008AC00: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8008AC04: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x8008AC08: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x8008AC0C: lw          $t9, 0x71F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X71F0);
    // 0x8008AC10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008AC14: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AC18: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8008AC1C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008AC20: jal         0x800C49A0
    // 0x8008AC24: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    draw_text(rdram, ctx);
        goto after_9;
    // 0x8008AC24: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    after_9:
    // 0x8008AC28: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x8008AC2C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008AC30: lw          $t3, 0x318($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X318);
    // 0x8008AC34: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8008AC38: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x8008AC3C: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8008AC40: beq         $t4, $zero, L_8008AC6C
    if (ctx->r12 == 0) {
        // 0x8008AC44: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8008AC6C;
    }
    // 0x8008AC44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AC48: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x8008AC4C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AC50: lw          $a3, 0x54($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X54);
    // 0x8008AC54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008AC58: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8008AC5C: jal         0x800C49A0
    // 0x8008AC60: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_10;
    // 0x8008AC60: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_10:
    // 0x8008AC64: b           L_8008AC88
    // 0x8008AC68: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
        goto L_8008AC88;
    // 0x8008AC68: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
L_8008AC6C:
    // 0x8008AC6C: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8008AC70: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8008AC74: lw          $a3, 0x58($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X58);
    // 0x8008AC78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008AC7C: jal         0x800C49A0
    // 0x8008AC80: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_11;
    // 0x8008AC80: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_11:
    // 0x8008AC84: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
L_8008AC88:
    // 0x8008AC88: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008AC8C: bne         $s0, $t7, L_8008ACA8
    if (ctx->r16 != ctx->r15) {
        // 0x8008AC90: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008ACA8;
    }
    // 0x8008AC90: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008AC94: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008AC98: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008AC9C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008ACA0: jal         0x800C48E4
    // 0x8008ACA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_12;
    // 0x8008ACA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
L_8008ACA8:
    // 0x8008ACA8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008ACAC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008ACB0: lw          $t1, 0x7234($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7234);
    // 0x8008ACB4: lw          $t9, 0x6980($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6980);
    // 0x8008ACB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008ACBC: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x8008ACC0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008ACC4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8008ACC8: beq         $at, $zero, L_8008ACDC
    if (ctx->r1 == 0) {
        // 0x8008ACCC: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_8008ACDC;
    }
    // 0x8008ACCC: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x8008ACD0: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8008ACD4: bne         $at, $zero, L_8008ABCC
    if (ctx->r1 != 0) {
        // 0x8008ACD8: nop
    
            goto L_8008ABCC;
    }
    // 0x8008ACD8: nop

L_8008ACDC:
    // 0x8008ACDC: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008ACE0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008ACE4: beq         $at, $zero, L_8008AD38
    if (ctx->r1 == 0) {
        // 0x8008ACE8: addiu       $s4, $s4, 0x7206
        ctx->r20 = ADD32(ctx->r20, 0X7206);
            goto L_8008AD38;
    }
    // 0x8008ACE8: addiu       $s4, $s4, 0x7206
    ctx->r20 = ADD32(ctx->r20, 0X7206);
    // 0x8008ACEC: lh          $t0, 0x0($s4)
    ctx->r8 = MEM_H(ctx->r20, 0X0);
    // 0x8008ACF0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008ACF4: bne         $s3, $t0, L_8008AD10
    if (ctx->r19 != ctx->r8) {
        // 0x8008ACF8: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008AD10;
    }
    // 0x8008ACF8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008ACFC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008AD00: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008AD04: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008AD08: jal         0x800C48E4
    // 0x8008AD0C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x8008AD0C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_13:
L_8008AD10:
    // 0x8008AD10: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x8008AD14: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8008AD18: lw          $a3, 0x14($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X14);
    // 0x8008AD1C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008AD20: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AD24: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8008AD28: jal         0x800C49A0
    // 0x8008AD2C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_14;
    // 0x8008AD2C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_14:
    // 0x8008AD30: b           L_8008AD84
    // 0x8008AD34: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_8008AD84;
    // 0x8008AD34: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8008AD38:
    // 0x8008AD38: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008AD3C: lw          $t5, 0x695C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X695C);
    // 0x8008AD40: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008AD44: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x8008AD48: beq         $t6, $zero, L_8008AD80
    if (ctx->r14 == 0) {
        // 0x8008AD4C: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8008AD80;
    }
    // 0x8008AD4C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008AD50: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8008AD54: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008AD58: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008AD5C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8008AD60: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8008AD64: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008AD68: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8008AD6C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008AD70: addiu       $a1, $a1, 0x9BC
    ctx->r5 = ADD32(ctx->r5, 0X9BC);
    // 0x8008AD74: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x8008AD78: jal         0x80078F08
    // 0x8008AD7C: addiu       $a3, $s2, 0x8
    ctx->r7 = ADD32(ctx->r18, 0X8);
    texrect_draw(rdram, ctx);
        goto after_15;
    // 0x8008AD7C: addiu       $a3, $s2, 0x8
    ctx->r7 = ADD32(ctx->r18, 0X8);
    after_15:
L_8008AD80:
    // 0x8008AD80: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8008AD84:
    // 0x8008AD84: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008AD88: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AD8C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8008AD90: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8008AD94: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8008AD98: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AD9C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8008ADA0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8008ADA4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8008ADA8: jr          $ra
    // 0x8008ADAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8008ADAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void cam_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800660E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800660E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800660E8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800660EC: addiu       $t7, $t7, 0x12F0
    ctx->r15 = ADD32(ctx->r15, 0X12F0);
    // 0x800660F0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800660F4: addiu       $a0, $a0, 0x1320
    ctx->r4 = ADD32(ctx->r4, 0X1320);
    // 0x800660F8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800660FC: sll         $t9, $v1, 6
    ctx->r25 = S32(ctx->r3 << 6);
    // 0x80066100: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066104: sw          $a0, 0x12F0($at)
    MEM_W(0X12F0, ctx->r1) = ctx->r4;
    // 0x80066108: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8006610C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80066110: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80066114: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x80066118: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x8006611C: addiu       $t0, $v1, 0x3
    ctx->r8 = ADD32(ctx->r3, 0X3);
    // 0x80066120: addiu       $t6, $v1, 0x2
    ctx->r14 = ADD32(ctx->r3, 0X2);
    // 0x80066124: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80066128: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8006612C: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x80066130: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80066134: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80066138: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x8006613C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80066140: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80066144: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80066148: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006614C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80066150: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80066154: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x80066158: addiu       $s1, $s1, 0x1264
    ctx->r17 = ADD32(ctx->r17, 0X1264);
    // 0x8006615C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80066160: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x80066164: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
L_80066168:
    // 0x80066168: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x8006616C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80066170: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80066174: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80066178: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8006617C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80066180: jal         0x8006661C
    // 0x80066184: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    camera_reset(rdram, ctx);
        goto after_0;
    // 0x80066184: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80066188: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006618C: bne         $s0, $s2, L_80066168
    if (ctx->r16 != ctx->r18) {
        // 0x80066190: addiu       $t3, $zero, 0xB4
        ctx->r11 = ADD32(0, 0XB4);
            goto L_80066168;
    }
    // 0x80066190: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x80066194: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066198: sb          $zero, 0x1294($at)
    MEM_B(0X1294, ctx->r1) = 0;
    // 0x8006619C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800661A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661A4: sw          $zero, 0x129C($at)
    MEM_W(0X129C, ctx->r1) = 0;
    // 0x800661A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661AC: sw          $zero, 0x12A0($at)
    MEM_W(0X12A0, ctx->r1) = 0;
    // 0x800661B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661B4: sw          $zero, 0x1260($at)
    MEM_W(0X1260, ctx->r1) = 0;
    // 0x800661B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661BC: sw          $zero, 0x128C($at)
    MEM_W(0X128C, ctx->r1) = 0;
    // 0x800661C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661C4: sw          $zero, 0x1298($at)
    MEM_W(0X1298, ctx->r1) = 0;
    // 0x800661C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800661CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800661D0: addiu       $a0, $a0, -0x2A30
    ctx->r4 = ADD32(ctx->r4, -0X2A30);
    // 0x800661D4: lui         $v1, 0xA460
    ctx->r3 = S32(0XA460 << 16);
    // 0x800661D8: sb          $zero, 0x1295($at)
    MEM_B(0X1295, ctx->r1) = 0;
    // 0x800661DC: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x800661E0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x800661E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800661E8: lui         $t6, 0xB000
    ctx->r14 = S32(0XB000 << 16);
    // 0x800661EC: andi        $t4, $v0, 0x3
    ctx->r12 = ctx->r2 & 0X3;
    // 0x800661F0: beq         $t4, $zero, L_8006620C
    if (ctx->r12 == 0) {
        // 0x800661F4: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8006620C;
    }
    // 0x800661F4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
L_800661F8:
    // 0x800661F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800661FC: nop

    // 0x80066200: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
    // 0x80066204: bne         $t5, $zero, L_800661F8
    if (ctx->r13 != 0) {
        // 0x80066208: nop
    
            goto L_800661F8;
    }
    // 0x80066208: nop

L_8006620C:
    // 0x8006620C: lw          $t7, 0x578($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X578);
    // 0x80066210: ori         $at, $zero, 0x8965
    ctx->r1 = 0 | 0X8965;
    // 0x80066214: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80066218: beq         $t8, $at, L_80066228
    if (ctx->r24 == ctx->r1) {
        // 0x8006621C: addiu       $s0, $s0, 0x1460
        ctx->r16 = ADD32(ctx->r16, 0X1460);
            goto L_80066228;
    }
    // 0x8006621C: addiu       $s0, $s0, 0x1460
    ctx->r16 = ADD32(ctx->r16, 0X1460);
    // 0x80066220: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80066224: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
L_80066228:
    // 0x80066228: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006622C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066230: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80066234: lwc1        $f6, 0x762C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X762C);
    // 0x80066238: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006623C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80066240: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80066244: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80066248: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x8006624C: addiu       $a1, $a1, 0x12EC
    ctx->r5 = ADD32(ctx->r5, 0X12EC);
    // 0x80066250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066254: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80066258: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006625C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80066260: jal         0x800CCE80
    // 0x80066264: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_1;
    // 0x80066264: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80066268: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006626C: addiu       $a1, $a1, 0x1560
    ctx->r5 = ADD32(ctx->r5, 0X1560);
    // 0x80066270: jal         0x8006FAB0
    // 0x80066274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtxf_to_mtx(rdram, ctx);
        goto after_2;
    // 0x80066274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80066278: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8006627C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80066280: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80066284: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066288: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006628C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80066290: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80066294: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80066298: jr          $ra
    // 0x8006629C: swc1        $f10, 0x1290($at)
    MEM_W(0X1290, ctx->r1) = ctx->f10.u32l;
    return;
    // 0x8006629C: swc1        $f10, 0x1290($at)
    MEM_W(0X1290, ctx->r1) = ctx->f10.u32l;
;}
RECOMP_FUNC void move_particle_basic_parent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B36A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B36A4: lw          $v0, -0x7DC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DC0);
    // 0x800B36A8: nop

    // 0x800B36AC: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B36B0: beq         $v1, $zero, L_800B3740
    if (ctx->r3 == 0) {
        // 0x800B36B4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B3740;
    }
    // 0x800B36B4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800B36B8:
    // 0x800B36B8: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800B36BC: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800B36C0: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800B36C4: lwc1        $f10, 0x50($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800B36C8: lwc1        $f18, 0x68($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X68);
    // 0x800B36CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B36D0: lwc1        $f6, 0x54($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800B36D4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800B36D8: swc1        $f8, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f8.u32l;
    // 0x800B36DC: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800B36E0: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x800B36E4: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800B36E8: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B36EC: lh          $t7, 0x62($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X62);
    // 0x800B36F0: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800B36F4: lh          $t0, 0x64($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X64);
    // 0x800B36F8: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x800B36FC: lh          $t3, 0x66($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X66);
    // 0x800B3700: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B3704: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B3708: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800B370C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3710: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3714: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3718: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B371C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B3720: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B3724: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    // 0x800B3728: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x800B372C: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    // 0x800B3730: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
    // 0x800B3734: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800B3738: bne         $v1, $zero, L_800B36B8
    if (ctx->r3 != 0) {
        // 0x800B373C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B36B8;
    }
    // 0x800B373C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800B3740:
    // 0x800B3740: lwc1        $f6, 0x4C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800B3744: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800B3748: lwc1        $f10, 0x54($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800B374C: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x800B3750: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x800B3754: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x800B3758: beq         $v0, $zero, L_800B3798
    if (ctx->r2 == 0) {
        // 0x800B375C: swc1        $f10, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
            goto L_800B3798;
    }
    // 0x800B375C: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800B3760: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B3764: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800B3768: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B376C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3770: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B3774: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800B3778: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800B377C: nop

    // 0x800B3780: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3784: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800B3788: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800B378C: nop

    // 0x800B3790: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3794: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
L_800B3798:
    // 0x800B3798: jr          $ra
    // 0x800B379C: nop

    return;
    // 0x800B379C: nop

;}
RECOMP_FUNC void mtxf_transform_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F88C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8006F890: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F894: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8006F898: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006F89C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F8A0: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x8006F8A4: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8006F8A8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F8AC: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8006F8B0: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8006F8B4: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8006F8B8: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8006F8BC: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8006F8C0: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8006F8C4: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8006F8C8: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F8CC: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8006F8D0: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x8006F8D4: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8006F8D8: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8006F8DC: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8006F8E0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8006F8E4: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8006F8E8: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8006F8EC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006F8F0: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8006F8F4: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8006F8F8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F8FC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8006F900: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006F904: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F908: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8006F90C: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006F910: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8006F914: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8006F918: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8006F91C: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8006F920: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006F924: jr          $ra
    // 0x8006F928: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    return;
    // 0x8006F928: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
;}
RECOMP_FUNC void obj_init_snowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038288: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003828C: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038290: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80038294: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80038298: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x8003829C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800382A0: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800382A4: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x800382A8: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800382AC: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x800382B0: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x800382B4: jr          $ra
    // 0x800382B8: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x800382B8: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void screenimage_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FA90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007FA94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007FA98: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007FA9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007FAA0: jal         0x80076EE4
    // 0x8007FAA4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x8007FAA4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x8007FAA8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007FAAC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8007FAB0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007FAB4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007FAB8: beq         $a0, $t6, L_8007FAD0
    if (ctx->r4 == ctx->r14) {
        // 0x8007FABC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007FAD0;
    }
    // 0x8007FABC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007FAC0:
    // 0x8007FAC0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8007FAC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007FAC8: bne         $a0, $t7, L_8007FAC0
    if (ctx->r4 != ctx->r15) {
        // 0x8007FACC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8007FAC0;
    }
    // 0x8007FACC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8007FAD0:
    // 0x8007FAD0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007FAD4: bne         $v1, $zero, L_8007FAEC
    if (ctx->r3 != 0) {
        // 0x8007FAD8: nop
    
            goto L_8007FAEC;
    }
    // 0x8007FAD8: nop

    // 0x8007FADC: jal         0x80071380
    // 0x8007FAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_1;
    // 0x8007FAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8007FAE4: b           L_8007FB54
    // 0x8007FAE8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
        goto L_8007FB54;
    // 0x8007FAE8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
L_8007FAEC:
    // 0x8007FAEC: bltz        $t0, L_8007FAF8
    if (SIGNED(ctx->r8) < 0) {
        // 0x8007FAF0: slt         $at, $t0, $v1
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8007FAF8;
    }
    // 0x8007FAF0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007FAF4: bne         $at, $zero, L_8007FB08
    if (ctx->r1 != 0) {
        // 0x8007FAF8: lui         $a0, 0x800F
        ctx->r4 = S32(0X800F << 16);
            goto L_8007FB08;
    }
L_8007FAF8:
    // 0x8007FAF8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8007FAFC: jal         0x800CA2B4
    // 0x8007FB00: addiu       $a0, $a0, -0x7DE0
    ctx->r4 = ADD32(ctx->r4, -0X7DE0);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007FB00: addiu       $a0, $a0, -0x7DE0
    ctx->r4 = ADD32(ctx->r4, -0X7DE0);
    after_2:
    // 0x8007FB04: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8007FB08:
    // 0x8007FB08: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8007FB0C: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x8007FB10: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007FB14: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8007FB18: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8007FB1C: subu        $a0, $t9, $a2
    ctx->r4 = SUB32(ctx->r25, ctx->r6);
    // 0x8007FB20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007FB24: jal         0x80070EDC
    // 0x8007FB28: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8007FB28: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x8007FB2C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8007FB30: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8007FB34: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8007FB38: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8007FB3C: jal         0x80077190
    // 0x8007FB40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_4;
    // 0x8007FB40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8007FB44: jal         0x80071380
    // 0x8007FB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8007FB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8007FB4C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8007FB50: nop

L_8007FB54:
    // 0x8007FB54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007FB58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007FB5C: jr          $ra
    // 0x8007FB60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007FB60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void update_object_stack_trace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7BD8: bltz        $a0, L_800B7BF4
    if (SIGNED(ctx->r4) < 0) {
        // 0x800B7BDC: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_800B7BF4;
    }
    // 0x800B7BDC: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800B7BE0: beq         $at, $zero, L_800B7BF4
    if (ctx->r1 == 0) {
        // 0x800B7BE4: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800B7BF4;
    }
    // 0x800B7BE4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800B7BE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7BEC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B7BF0: sw          $a1, -0x5A90($at)
    MEM_W(-0X5A90, ctx->r1) = ctx->r5;
L_800B7BF4:
    // 0x800B7BF4: jr          $ra
    // 0x800B7BF8: nop

    return;
    // 0x800B7BF8: nop

;}
RECOMP_FUNC void set_next_taj_challenge_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D874: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D878: jr          $ra
    // 0x8009D87C: sb          $a0, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = ctx->r4;
    return;
    // 0x8009D87C: sb          $a0, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void music_channel_pan_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800011AC: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x800011B0: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x800011B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800011B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800011BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800011C0: beq         $at, $zero, L_800011D8
    if (ctx->r1 == 0) {
        // 0x800011C4: andi        $a2, $a1, 0xFF
        ctx->r6 = ctx->r5 & 0XFF;
            goto L_800011D8;
    }
    // 0x800011C4: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x800011C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800011CC: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800011D0: jal         0x800C7E40
    // 0x800011D4: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    alCSPSetChlPan(rdram, ctx);
        goto after_0;
    // 0x800011D4: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_0:
L_800011D8:
    // 0x800011D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800011DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800011E0: jr          $ra
    // 0x800011E4: nop

    return;
    // 0x800011E4: nop

;}
RECOMP_FUNC void alSynAllocVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9A68: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9A6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9A70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9A74: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C9A78: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800C9A7C: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800C9A80: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C9A84: sh          $t6, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r14;
    // 0x800C9A88: lbu         $t7, 0x4($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X4);
    // 0x800C9A8C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800C9A90: sh          $t7, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r15;
    // 0x800C9A94: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800C9A98: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x800C9A9C: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800C9AA0: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x800C9AA4: lh          $a2, 0x0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X0);
    // 0x800C9AA8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800C9AAC: jal         0x800C9980
    // 0x800C9AB0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _allocatePVoice(rdram, ctx);
        goto after_0;
    // 0x800C9AB0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800C9AB4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9AB8: beql        $t9, $zero, L_800C9B90
    if (ctx->r25 == 0) {
        // 0x800C9ABC: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_800C9B90;
    }
    goto skip_0;
    // 0x800C9ABC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800C9AC0: beq         $v0, $zero, L_800C9B74
    if (ctx->r2 == 0) {
        // 0x800C9AC4: lw          $a0, 0xC($t9)
        ctx->r4 = MEM_W(ctx->r25, 0XC);
            goto L_800C9B74;
    }
    // 0x800C9AC4: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x800C9AC8: addiu       $t0, $zero, 0x200
    ctx->r8 = ADD32(0, 0X200);
    // 0x800C9ACC: sw          $t0, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->r8;
    // 0x800C9AD0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9AD4: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800C9AD8: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x800C9ADC: jal         0x800658A8
    // 0x800C9AE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_1;
    // 0x800C9AE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x800C9AE4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800C9AE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C9AEC: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x800C9AF0: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x800C9AF4: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800C9AF8: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800C9AFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800C9B00: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9B04: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9B08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9B0C: lw          $t7, 0xD8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD8);
    // 0x800C9B10: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x800C9B14: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800C9B18: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9B1C: jalr        $t9
    // 0x800C9B20: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800C9B20: nop

    after_2:
    // 0x800C9B24: jal         0x800658A8
    // 0x800C9B28: nop

    __allocParam(rdram, ctx);
        goto after_3;
    // 0x800C9B28: nop

    after_3:
    // 0x800C9B2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C9B30: beq         $v0, $zero, L_800C9B7C
    if (ctx->r2 == 0) {
        // 0x800C9B34: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9B7C;
    }
    // 0x800C9B34: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9B38: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C9B3C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9B40: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x800C9B44: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x800C9B48: lw          $t3, 0xD8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XD8);
    // 0x800C9B4C: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800C9B50: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C9B54: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C9B58: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800C9B5C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9B60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9B64: jalr        $t9
    // 0x800C9B68: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800C9B68: nop

    after_4:
    // 0x800C9B6C: b           L_800C9B80
    // 0x800C9B70: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_800C9B80;
    // 0x800C9B70: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800C9B74:
    // 0x800C9B74: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9B78: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
L_800C9B7C:
    // 0x800C9B7C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800C9B80:
    // 0x800C9B80: sw          $s0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r16;
    // 0x800C9B84: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9B88: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800C9B8C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_800C9B90:
    // 0x800C9B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9B94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C9B98: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C9B9C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800C9BA0: jr          $ra
    // 0x800C9BA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C9BA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80021600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021634: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x80021638: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002163C: lh          $t6, -0x4C06($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4C06);
    // 0x80021640: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80021644: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80021648: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8002164C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80021650: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80021654: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80021658: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8002165C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80021660: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80021664: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80021668: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002166C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80021670: bgez        $t6, L_80021680
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80021674: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80021680;
    }
    // 0x80021674: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80021678: b           L_8002253C
    // 0x8002167C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002253C;
    // 0x8002167C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80021680:
    // 0x80021680: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021684: lh          $v1, -0x4C08($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4C08);
    // 0x80021688: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002168C: blez        $v1, L_800216E4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80021690: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800216E4;
    }
    // 0x80021690: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80021694: addiu       $a2, $a2, -0x4C0C
    ctx->r6 = ADD32(ctx->r6, -0X4C0C);
    // 0x80021698: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8002169C: nop

    // 0x800216A0: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800216A4: nop

    // 0x800216A8: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x800216AC: nop

    // 0x800216B0: beq         $a1, $t8, L_800216E4
    if (ctx->r5 == ctx->r24) {
        // 0x800216B4: nop
    
            goto L_800216E4;
    }
    // 0x800216B4: nop

L_800216B8:
    // 0x800216B8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800216BC: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800216C0: beq         $at, $zero, L_800216E4
    if (ctx->r1 == 0) {
        // 0x800216C4: sll         $t9, $s7, 2
        ctx->r25 = S32(ctx->r23 << 2);
            goto L_800216E4;
    }
    // 0x800216C4: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x800216C8: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x800216CC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800216D0: nop

    // 0x800216D4: lw          $t5, 0x7C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X7C);
    // 0x800216D8: nop

    // 0x800216DC: bne         $a1, $t5, L_800216B8
    if (ctx->r5 != ctx->r13) {
        // 0x800216E0: nop
    
            goto L_800216B8;
    }
    // 0x800216E0: nop

L_800216E4:
    // 0x800216E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800216E8: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800216EC: bne         $at, $zero, L_800216FC
    if (ctx->r1 != 0) {
        // 0x800216F0: addiu       $a2, $a2, -0x4C0C
        ctx->r6 = ADD32(ctx->r6, -0X4C0C);
            goto L_800216FC;
    }
    // 0x800216F0: addiu       $a2, $a2, -0x4C0C
    ctx->r6 = ADD32(ctx->r6, -0X4C0C);
    // 0x800216F4: b           L_8002253C
    // 0x800216F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002253C;
    // 0x800216F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800216FC:
    // 0x800216FC: addiu       $t6, $s7, 0x1
    ctx->r14 = ADD32(ctx->r23, 0X1);
    // 0x80021700: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021704: beq         $at, $zero, L_8002175C
    if (ctx->r1 == 0) {
        // 0x80021708: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_8002175C;
    }
    // 0x80021708: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8002170C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80021710: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x80021714: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80021718: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8002171C: addu        $v0, $s7, $s5
    ctx->r2 = ADD32(ctx->r23, ctx->r21);
    // 0x80021720: lw          $t3, 0x7C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X7C);
    // 0x80021724: nop

    // 0x80021728: bne         $a1, $t3, L_8002175C
    if (ctx->r5 != ctx->r11) {
        // 0x8002172C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8002175C;
    }
    // 0x8002172C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80021730:
    // 0x80021730: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021734: beq         $at, $zero, L_8002175C
    if (ctx->r1 == 0) {
        // 0x80021738: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8002175C;
    }
    // 0x80021738: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8002173C: sll         $t4, $s5, 2
    ctx->r12 = S32(ctx->r21 << 2);
    // 0x80021740: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80021744: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80021748: nop

    // 0x8002174C: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x80021750: nop

    // 0x80021754: beq         $a1, $t7, L_80021730
    if (ctx->r5 == ctx->r15) {
        // 0x80021758: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80021730;
    }
    // 0x80021758: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002175C:
    // 0x8002175C: slti        $at, $s5, 0x2
    ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x80021760: beq         $at, $zero, L_80021770
    if (ctx->r1 == 0) {
        // 0x80021764: sll         $t8, $s7, 2
        ctx->r24 = S32(ctx->r23 << 2);
            goto L_80021770;
    }
    // 0x80021764: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x80021768: b           L_8002253C
    // 0x8002176C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002253C;
    // 0x8002176C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80021770:
    // 0x80021770: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80021774: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x80021778: addu        $t3, $a3, $t8
    ctx->r11 = ADD32(ctx->r7, ctx->r24);
    // 0x8002177C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80021780: addiu       $s2, $sp, 0x124
    ctx->r18 = ADD32(ctx->r29, 0X124);
    // 0x80021784: lw          $t4, 0x64($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X64);
    // 0x80021788: addiu       $s3, $sp, 0x110
    ctx->r19 = ADD32(ctx->r29, 0X110);
    // 0x8002178C: bne         $t4, $zero, L_8002179C
    if (ctx->r12 != 0) {
        // 0x80021790: sw          $t4, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r12;
            goto L_8002179C;
    }
    // 0x80021790: sw          $t4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r12;
    // 0x80021794: b           L_8002253C
    // 0x80021798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002253C;
    // 0x80021798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002179C:
    // 0x8002179C: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x800217A0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800217A4: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x800217A8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800217AC: sw          $t7, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r15;
    // 0x800217B0: lw          $t8, 0x40($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X40);
    // 0x800217B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800217B8: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800217BC: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x800217C0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800217C4: nop

    // 0x800217C8: div.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800217CC: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x800217D0: sll         $t4, $s5, 2
    ctx->r12 = S32(ctx->r21 << 2);
    // 0x800217D4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800217D8: slti        $at, $s5, 0x3
    ctx->r1 = SIGNED(ctx->r21) < 0X3 ? 1 : 0;
    // 0x800217DC: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x800217E0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800217E4: addiu       $s4, $sp, 0xFC
    ctx->r20 = ADD32(ctx->r29, 0XFC);
    // 0x800217E8: addiu       $fp, $sp, 0xBC
    ctx->r30 = ADD32(ctx->r29, 0XBC);
    // 0x800217EC: addiu       $s6, $sp, 0xA8
    ctx->r22 = ADD32(ctx->r29, 0XA8);
    // 0x800217F0: addiu       $t1, $sp, 0x94
    ctx->r9 = ADD32(ctx->r29, 0X94);
    // 0x800217F4: addiu       $s1, $sp, 0xD0
    ctx->r17 = ADD32(ctx->r29, 0XD0);
    // 0x800217F8: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x800217FC: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x80021800: lw          $t6, -0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X4);
    // 0x80021804: nop

    // 0x80021808: lw          $a1, 0x3C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X3C);
    // 0x8002180C: bne         $at, $zero, L_80021830
    if (ctx->r1 != 0) {
        // 0x80021810: nop
    
            goto L_80021830;
    }
    // 0x80021810: nop

    // 0x80021814: lb          $v0, 0x1D($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1D);
    // 0x80021818: addiu       $t7, $s5, -0x1
    ctx->r15 = ADD32(ctx->r21, -0X1);
    // 0x8002181C: bltz        $v0, L_80021830
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021820: slt         $at, $v0, $t7
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
            goto L_80021830;
    }
    // 0x80021820: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80021824: beq         $at, $zero, L_80021830
    if (ctx->r1 == 0) {
        // 0x80021828: nop
    
            goto L_80021830;
    }
    // 0x80021828: nop

    // 0x8002182C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80021830:
    // 0x80021830: lh          $s0, 0x26($t8)
    ctx->r16 = MEM_H(ctx->r24, 0X26);
    // 0x80021834: sw          $v1, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r3;
    // 0x80021838: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8002183C:
    // 0x8002183C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021840: bne         $s0, $at, L_800219F0
    if (ctx->r16 != ctx->r1) {
        // 0x80021844: slt         $at, $s0, $s5
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_800219F0;
    }
    // 0x80021844: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80021848: lw          $t9, 0x138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X138);
    // 0x8002184C: addu        $t3, $s7, $s5
    ctx->r11 = ADD32(ctx->r23, ctx->r21);
    // 0x80021850: beq         $t9, $zero, L_80021938
    if (ctx->r25 == 0) {
        // 0x80021854: sll         $t4, $t3, 2
        ctx->r12 = S32(ctx->r11 << 2);
            goto L_80021938;
    }
    // 0x80021854: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80021858: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x8002185C: nop

    // 0x80021860: addu        $v0, $a3, $t3
    ctx->r2 = ADD32(ctx->r7, ctx->r11);
    // 0x80021864: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80021868: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8002186C: lwc1        $f0, 0xC($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80021870: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80021874: nop

    // 0x80021878: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8002187C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80021880: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    // 0x80021884: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80021888: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8002188C: lwc1        $f2, 0x10($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80021890: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80021894: nop

    // 0x80021898: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8002189C: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800218A0: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x800218A4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800218A8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800218AC: lwc1        $f12, 0x14($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X14);
    // 0x800218B0: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x800218B4: nop

    // 0x800218B8: sub.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x800218BC: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800218C0: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x800218C4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800218C8: nop

    // 0x800218CC: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x800218D0: nop

    // 0x800218D4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800218D8: nop

    // 0x800218DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800218E0: swc1        $f10, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f10.u32l;
    // 0x800218E4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800218E8: nop

    // 0x800218EC: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x800218F0: nop

    // 0x800218F4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800218F8: nop

    // 0x800218FC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021900: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x80021904: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80021908: nop

    // 0x8002190C: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x80021910: nop

    // 0x80021914: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80021918: nop

    // 0x8002191C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021920: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80021924: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80021928: nop

    // 0x8002192C: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80021930: b           L_80021D08
    // 0x80021934: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_80021D08;
    // 0x80021934: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80021938:
    // 0x80021938: addu        $v0, $a3, $t4
    ctx->r2 = ADD32(ctx->r7, ctx->r12);
    // 0x8002193C: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x80021940: nop

    // 0x80021944: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80021948: nop

    // 0x8002194C: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80021950: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80021954: nop

    // 0x80021958: lwc1        $f8, 0x10($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8002195C: nop

    // 0x80021960: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x80021964: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x80021968: nop

    // 0x8002196C: lwc1        $f10, 0x14($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X14);
    // 0x80021970: nop

    // 0x80021974: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80021978: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x8002197C: nop

    // 0x80021980: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80021984: nop

    // 0x80021988: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8002198C: nop

    // 0x80021990: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021994: swc1        $f4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f4.u32l;
    // 0x80021998: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x8002199C: nop

    // 0x800219A0: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x800219A4: nop

    // 0x800219A8: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800219AC: nop

    // 0x800219B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800219B4: swc1        $f10, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f10.u32l;
    // 0x800219B8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800219BC: nop

    // 0x800219C0: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x800219C4: nop

    // 0x800219C8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800219CC: nop

    // 0x800219D0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800219D4: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x800219D8: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800219DC: nop

    // 0x800219E0: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800219E4: b           L_80021D08
    // 0x800219E8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
        goto L_80021D08;
    // 0x800219E8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x800219EC: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
L_800219F0:
    // 0x800219F0: bne         $at, $zero, L_80021BFC
    if (ctx->r1 != 0) {
        // 0x800219F4: addu        $a2, $s0, $s7
        ctx->r6 = ADD32(ctx->r16, ctx->r23);
            goto L_80021BFC;
    }
    // 0x800219F4: addu        $a2, $s0, $s7
    ctx->r6 = ADD32(ctx->r16, ctx->r23);
    // 0x800219F8: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x800219FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021A00: bne         $t8, $at, L_80021B30
    if (ctx->r24 != ctx->r1) {
        // 0x80021A04: addu        $v0, $s5, $s7
        ctx->r2 = ADD32(ctx->r21, ctx->r23);
            goto L_80021B30;
    }
    // 0x80021A04: addu        $v0, $s5, $s7
    ctx->r2 = ADD32(ctx->r21, ctx->r23);
    // 0x80021A08: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80021A0C: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x80021A10: lw          $t4, -0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X4);
    // 0x80021A14: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x80021A18: lw          $a1, 0x3C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X3C);
    // 0x80021A1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021A20: lb          $t5, 0x22($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X22);
    // 0x80021A24: addiu       $s0, $s5, -0x1
    ctx->r16 = ADD32(ctx->r21, -0X1);
    // 0x80021A28: bne         $t5, $at, L_80021A6C
    if (ctx->r13 != ctx->r1) {
        // 0x80021A2C: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80021A6C;
    }
    // 0x80021A2C: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x80021A30: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x80021A34: nop

    // 0x80021A38: lb          $a0, 0x30($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X30);
    // 0x80021A3C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80021A40: jal         0x80066828
    // 0x80021A44: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    set_active_camera(rdram, ctx);
        goto after_0;
    // 0x80021A44: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80021A48: jal         0x80069F3C
    // 0x80021A4C: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_1;
    // 0x80021A4C: nop

    after_1:
    // 0x80021A50: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80021A54: lw          $a3, -0x4C0C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4C0C);
    // 0x80021A58: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80021A5C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80021A60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80021A64: b           L_80021A78
    // 0x80021A68: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
        goto L_80021A78;
    // 0x80021A68: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
L_80021A6C:
    // 0x80021A6C: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x80021A70: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021A74: nop

L_80021A78:
    // 0x80021A78: lw          $t7, -0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X4);
    // 0x80021A7C: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80021A80: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80021A84: nop

    // 0x80021A88: sub.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80021A8C: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80021A90: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80021A94: lw          $t8, -0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, -0X4);
    // 0x80021A98: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80021A9C: lwc1        $f8, 0x10($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80021AA0: nop

    // 0x80021AA4: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80021AA8: add.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80021AAC: swc1        $f6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f6.u32l;
    // 0x80021AB0: lw          $t9, -0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, -0X4);
    // 0x80021AB4: lwc1        $f12, 0x14($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80021AB8: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80021ABC: nop

    // 0x80021AC0: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80021AC4: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80021AC8: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80021ACC: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80021AD0: nop

    // 0x80021AD4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80021AD8: nop

    // 0x80021ADC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021AE0: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x80021AE4: lh          $t4, 0x4($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X4);
    // 0x80021AE8: nop

    // 0x80021AEC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80021AF0: nop

    // 0x80021AF4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021AF8: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80021AFC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021B00: nop

    // 0x80021B04: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80021B08: nop

    // 0x80021B0C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80021B10: nop

    // 0x80021B14: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021B18: swc1        $f4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f4.u32l;
    // 0x80021B1C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80021B20: nop

    // 0x80021B24: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80021B28: b           L_80021D08
    // 0x80021B2C: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
        goto L_80021D08;
    // 0x80021B2C: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
L_80021B30:
    // 0x80021B30: lw          $t7, 0x138($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X138);
    // 0x80021B34: nop

    // 0x80021B38: addu        $t8, $s7, $t7
    ctx->r24 = ADD32(ctx->r23, ctx->r15);
    // 0x80021B3C: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80021B40: subu        $t3, $t9, $s5
    ctx->r11 = SUB32(ctx->r25, ctx->r21);
    // 0x80021B44: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80021B48: addu        $v0, $a3, $t4
    ctx->r2 = ADD32(ctx->r7, ctx->r12);
    // 0x80021B4C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80021B50: nop

    // 0x80021B54: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80021B58: nop

    // 0x80021B5C: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    // 0x80021B60: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80021B64: nop

    // 0x80021B68: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80021B6C: nop

    // 0x80021B70: swc1        $f6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f6.u32l;
    // 0x80021B74: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80021B78: nop

    // 0x80021B7C: lwc1        $f4, 0x14($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X14);
    // 0x80021B80: nop

    // 0x80021B84: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x80021B88: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80021B8C: nop

    // 0x80021B90: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80021B94: nop

    // 0x80021B98: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80021B9C: nop

    // 0x80021BA0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021BA4: swc1        $f10, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f10.u32l;
    // 0x80021BA8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80021BAC: nop

    // 0x80021BB0: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80021BB4: nop

    // 0x80021BB8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80021BBC: nop

    // 0x80021BC0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021BC4: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x80021BC8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80021BCC: nop

    // 0x80021BD0: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x80021BD4: nop

    // 0x80021BD8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80021BDC: nop

    // 0x80021BE0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021BE4: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80021BE8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80021BEC: nop

    // 0x80021BF0: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80021BF4: b           L_80021D08
    // 0x80021BF8: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_80021D08;
    // 0x80021BF8: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80021BFC:
    // 0x80021BFC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80021C00: addu        $a0, $a3, $t8
    ctx->r4 = ADD32(ctx->r7, ctx->r24);
    // 0x80021C04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80021C08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021C0C: lw          $a1, 0x3C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X3C);
    // 0x80021C10: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80021C14: lb          $t9, 0x22($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X22);
    // 0x80021C18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80021C1C: bne         $t9, $at, L_80021C60
    if (ctx->r25 != ctx->r1) {
        // 0x80021C20: nop
    
            goto L_80021C60;
    }
    // 0x80021C20: nop

    // 0x80021C24: lb          $a0, 0x30($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X30);
    // 0x80021C28: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80021C2C: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80021C30: jal         0x80066828
    // 0x80021C34: sw          $a1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r5;
    set_active_camera(rdram, ctx);
        goto after_2;
    // 0x80021C34: sw          $a1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r5;
    after_2:
    // 0x80021C38: jal         0x80069F3C
    // 0x80021C3C: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_3;
    // 0x80021C3C: nop

    after_3:
    // 0x80021C40: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80021C44: lw          $a3, -0x4C0C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4C0C);
    // 0x80021C48: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80021C4C: lw          $a1, 0x150($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X150);
    // 0x80021C50: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80021C54: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80021C58: b           L_80021C60
    // 0x80021C5C: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
        goto L_80021C60;
    // 0x80021C5C: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
L_80021C60:
    // 0x80021C60: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80021C64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021C68: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80021C6C: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80021C70: nop

    // 0x80021C74: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x80021C78: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80021C7C: nop

    // 0x80021C80: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80021C84: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x80021C88: nop

    // 0x80021C8C: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80021C90: nop

    // 0x80021C94: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021C98: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x80021C9C: lh          $t5, 0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X4);
    // 0x80021CA0: nop

    // 0x80021CA4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80021CA8: nop

    // 0x80021CAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021CB0: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80021CB4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021CB8: nop

    // 0x80021CBC: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80021CC0: nop

    // 0x80021CC4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80021CC8: nop

    // 0x80021CCC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021CD0: swc1        $f4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f4.u32l;
    // 0x80021CD4: lb          $t7, 0x22($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X22);
    // 0x80021CD8: nop

    // 0x80021CDC: bne         $t7, $at, L_80021CF4
    if (ctx->r15 != ctx->r1) {
        // 0x80021CE0: nop
    
            goto L_80021CF4;
    }
    // 0x80021CE0: nop

    // 0x80021CE4: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80021CE8: nop

    // 0x80021CEC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80021CF0: swc1        $f10, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f10.u32l;
L_80021CF4:
    // 0x80021CF4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80021CF8: nop

    // 0x80021CFC: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80021D00: nop

    // 0x80021D04: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80021D08:
    // 0x80021D08: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80021D0C: addiu       $t9, $sp, 0xE4
    ctx->r25 = ADD32(ctx->r29, 0XE4);
    // 0x80021D10: sltu        $at, $s1, $t9
    ctx->r1 = ctx->r17 < ctx->r25 ? 1 : 0;
    // 0x80021D14: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80021D18: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80021D1C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80021D20: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80021D24: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80021D28: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80021D2C: bne         $at, $zero, L_8002183C
    if (ctx->r1 != 0) {
        // 0x80021D30: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8002183C;
    }
    // 0x80021D30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80021D34: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80021D38: addiu       $s0, $sp, 0x124
    ctx->r16 = ADD32(ctx->r29, 0X124);
    // 0x80021D3C: lb          $t4, 0x3F($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X3F);
    // 0x80021D40: lwc1        $f0, 0x0($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80021D44: bne         $t4, $zero, L_80021D9C
    if (ctx->r12 != 0) {
        // 0x80021D48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80021D9C;
    }
    // 0x80021D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021D4C: addiu       $s0, $sp, 0x124
    ctx->r16 = ADD32(ctx->r29, 0X124);
    // 0x80021D50: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80021D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021D58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021D5C: jal         0x80022574
    // 0x80021D60: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_4;
    // 0x80021D60: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80021D64: addiu       $s1, $sp, 0x110
    ctx->r17 = ADD32(ctx->r29, 0X110);
    // 0x80021D68: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021D74: jal         0x80022574
    // 0x80021D78: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_5;
    // 0x80021D78: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80021D7C: addiu       $s2, $sp, 0xFC
    ctx->r18 = ADD32(ctx->r29, 0XFC);
    // 0x80021D80: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021D84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021D88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021D8C: jal         0x80022574
    // 0x80021D90: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_6;
    // 0x80021D90: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80021D94: b           L_80021DE0
    // 0x80021D98: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
        goto L_80021DE0;
    // 0x80021D98: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
L_80021D9C:
    // 0x80021D9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80021DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021DA4: jal         0x800228BC
    // 0x80021DA8: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_7;
    // 0x80021DA8: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80021DAC: addiu       $s1, $sp, 0x110
    ctx->r17 = ADD32(ctx->r29, 0X110);
    // 0x80021DB0: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021DB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021DB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021DBC: jal         0x800228BC
    // 0x80021DC0: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_8;
    // 0x80021DC0: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80021DC4: addiu       $s2, $sp, 0xFC
    ctx->r18 = ADD32(ctx->r29, 0XFC);
    // 0x80021DC8: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021DCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021DD4: jal         0x800228BC
    // 0x80021DD8: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_9;
    // 0x80021DD8: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80021DDC: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
L_80021DE0:
    // 0x80021DE0: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x80021DE4: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80021DE8: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80021DEC: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021DF0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80021DF4: swc1        $f10, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f10.u32l;
    // 0x80021DF8: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80021DFC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80021E00: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80021E04: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021E08: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    // 0x80021E0C: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80021E10: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80021E14: sub.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80021E18: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80021E1C: jal         0x80011570
    // 0x80021E20: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    move_object(rdram, ctx);
        goto after_10;
    // 0x80021E20: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80021E24: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021E28: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x80021E2C: jal         0x80022574
    // 0x80021E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_11;
    // 0x80021E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80021E34: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80021E38: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x80021E3C: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80021E40: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80021E44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021E48: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80021E4C: nop

    // 0x80021E50: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80021E54: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x80021E58: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x80021E5C: nop

    // 0x80021E60: lbu         $v0, 0x2E($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X2E);
    // 0x80021E64: nop

    // 0x80021E68: beq         $v0, $at, L_80022538
    if (ctx->r2 == ctx->r1) {
        // 0x80021E6C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80022538;
    }
    // 0x80021E6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80021E70: beq         $v0, $at, L_80021E88
    if (ctx->r2 == ctx->r1) {
        // 0x80021E74: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80021E88;
    }
    // 0x80021E74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80021E78: beq         $v0, $at, L_80021FD4
    if (ctx->r2 == ctx->r1) {
        // 0x80021E7C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80021FD4;
    }
    // 0x80021E7C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021E80: b           L_80022104
    // 0x80021E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80022104;
    // 0x80021E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80021E88:
    // 0x80021E88: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x80021E8C: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021E90: lb          $t3, 0x3F($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X3F);
    // 0x80021E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021E98: bne         $t3, $zero, L_80021EE4
    if (ctx->r11 != 0) {
        // 0x80021E9C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80021EE4;
    }
    // 0x80021E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021EA0: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021EA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021EAC: jal         0x80022670
    // 0x80021EB0: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    cubic_spline_interpolation(rdram, ctx);
        goto after_12;
    // 0x80021EB0: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    after_12:
    // 0x80021EB4: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021EC0: jal         0x80022670
    // 0x80021EC4: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    cubic_spline_interpolation(rdram, ctx);
        goto after_13;
    // 0x80021EC4: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    after_13:
    // 0x80021EC8: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021ECC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021ED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021ED4: jal         0x80022670
    // 0x80021ED8: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    cubic_spline_interpolation(rdram, ctx);
        goto after_14;
    // 0x80021ED8: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    after_14:
    // 0x80021EDC: b           L_80021F18
    // 0x80021EE0: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
        goto L_80021F18;
    // 0x80021EE0: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
L_80021EE4:
    // 0x80021EE4: jal         0x800228E4
    // 0x80021EE8: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    lerp_and_get_derivative(rdram, ctx);
        goto after_15;
    // 0x80021EE8: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    after_15:
    // 0x80021EEC: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021EF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021EF8: jal         0x800228E4
    // 0x80021EFC: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    lerp_and_get_derivative(rdram, ctx);
        goto after_16;
    // 0x80021EFC: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    after_16:
    // 0x80021F00: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021F04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021F08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021F0C: jal         0x800228E4
    // 0x80021F10: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    lerp_and_get_derivative(rdram, ctx);
        goto after_17;
    // 0x80021F10: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    after_17:
    // 0x80021F14: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
L_80021F18:
    // 0x80021F18: lwc1        $f2, 0xF4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021F1C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80021F20: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021F24: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80021F28: nop

    // 0x80021F2C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80021F30: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80021F34: jal         0x800CA030
    // 0x80021F38: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_18;
    // 0x80021F38: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_18:
    // 0x80021F3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80021F40: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80021F44: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80021F48: nop

    // 0x80021F4C: bc1t        L_80021F94
    if (c1cs) {
        // 0x80021F50: nop
    
            goto L_80021F94;
    }
    // 0x80021F50: nop

    // 0x80021F54: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80021F58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80021F5C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80021F60: nop

    // 0x80021F64: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x80021F68: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80021F6C: lwc1        $f2, 0xF4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021F70: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021F74: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80021F78: mul.s       $f20, $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x80021F7C: nop

    // 0x80021F80: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80021F84: swc1        $f20, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f20.u32l;
    // 0x80021F88: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80021F8C: swc1        $f2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f2.u32l;
    // 0x80021F90: swc1        $f14, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f14.u32l;
L_80021F94:
    // 0x80021F94: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021F98: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80021F9C: jal         0x80070990
    // 0x80021FA0: nop

    arctan2_f(rdram, ctx);
        goto after_19;
    // 0x80021FA0: nop

    after_19:
    // 0x80021FA4: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80021FA8: lw          $t5, 0x154($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X154);
    // 0x80021FAC: addu        $t4, $v0, $at
    ctx->r12 = ADD32(ctx->r2, ctx->r1);
    // 0x80021FB0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80021FB4: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x80021FB8: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021FBC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80021FC0: jal         0x80070990
    // 0x80021FC4: nop

    arctan2_f(rdram, ctx);
        goto after_20;
    // 0x80021FC4: nop

    after_20:
    // 0x80021FC8: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x80021FCC: b           L_80022538
    // 0x80021FD0: sh          $v0, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r2;
        goto L_80022538;
    // 0x80021FD0: sh          $v0, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r2;
L_80021FD4:
    // 0x80021FD4: lh          $v1, -0x4C08($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4C08);
    // 0x80021FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021FDC: blez        $v1, L_80022030
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80021FE0: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80022030;
    }
    // 0x80021FE0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80021FE4: lw          $a3, -0x4C0C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4C0C);
    // 0x80021FE8: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x80021FEC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80021FF0: lb          $v0, 0x3E($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X3E);
    // 0x80021FF4: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x80021FF8: nop

    // 0x80021FFC: beq         $v0, $t9, L_80022030
    if (ctx->r2 == ctx->r25) {
        // 0x80022000: nop
    
            goto L_80022030;
    }
    // 0x80022000: nop

L_80022004:
    // 0x80022004: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80022008: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002200C: beq         $at, $zero, L_80022030
    if (ctx->r1 == 0) {
        // 0x80022010: sll         $t3, $a1, 2
        ctx->r11 = S32(ctx->r5 << 2);
            goto L_80022030;
    }
    // 0x80022010: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80022014: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80022018: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8002201C: nop

    // 0x80022020: lw          $t7, 0x7C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X7C);
    // 0x80022024: nop

    // 0x80022028: bne         $v0, $t7, L_80022004
    if (ctx->r2 != ctx->r15) {
        // 0x8002202C: nop
    
            goto L_80022004;
    }
    // 0x8002202C: nop

L_80022030:
    // 0x80022030: beq         $a1, $v1, L_80022538
    if (ctx->r5 == ctx->r3) {
        // 0x80022034: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80022538;
    }
    // 0x80022034: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80022038: lw          $t6, -0x4C0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C0C);
    // 0x8002203C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80022040: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80022044: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80022048: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x8002204C: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x80022050: nop

    // 0x80022054: beq         $v1, $zero, L_8002253C
    if (ctx->r3 == 0) {
        // 0x80022058: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002253C;
    }
    // 0x80022058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002205C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80022060: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80022064: nop

    // 0x80022068: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8002206C: swc1        $f10, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f10.u32l;
    // 0x80022070: lwc1        $f6, 0x10($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80022074: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80022078: nop

    // 0x8002207C: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80022080: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
    // 0x80022084: lwc1        $f8, 0x14($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X14);
    // 0x80022088: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8002208C: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80022090: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80022094: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80022098: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8002209C: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    // 0x800220A0: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800220A4: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800220A8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800220AC: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800220B0: jal         0x800CA030
    // 0x800220B4: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_21;
    // 0x800220B4: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_21:
    // 0x800220B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800220BC: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800220C0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800220C4: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800220C8: bc1f        L_80022538
    if (!c1cs) {
        // 0x800220CC: swc1        $f0, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
            goto L_80022538;
    }
    // 0x800220CC: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    // 0x800220D0: jal         0x80070990
    // 0x800220D4: nop

    arctan2_f(rdram, ctx);
        goto after_22;
    // 0x800220D4: nop

    after_22:
    // 0x800220D8: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x800220DC: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800220E0: addu        $t5, $v0, $at
    ctx->r13 = ADD32(ctx->r2, ctx->r1);
    // 0x800220E4: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x800220E8: lwc1        $f14, 0xEC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800220EC: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800220F0: jal         0x80070990
    // 0x800220F4: nop

    arctan2_f(rdram, ctx);
        goto after_23;
    // 0x800220F4: nop

    after_23:
    // 0x800220F8: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x800220FC: b           L_80022538
    // 0x80022100: sh          $v0, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r2;
        goto L_80022538;
    // 0x80022100: sh          $v0, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r2;
L_80022104:
    // 0x80022104: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x80022108: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8002210C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80022110: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80022114: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80022118: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8002211C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80022120: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80022124: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80022128: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8002212C: addiu       $fp, $sp, 0xC0
    ctx->r30 = ADD32(ctx->r29, 0XC0);
    // 0x80022130: addiu       $s6, $sp, 0xAC
    ctx->r22 = ADD32(ctx->r29, 0XAC);
    // 0x80022134: addiu       $t1, $sp, 0x98
    ctx->r9 = ADD32(ctx->r29, 0X98);
    // 0x80022138: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8002213C: addiu       $t0, $sp, 0xA8
    ctx->r8 = ADD32(ctx->r29, 0XA8);
    // 0x80022140: addiu       $a3, $sp, 0xBC
    ctx->r7 = ADD32(ctx->r29, 0XBC);
    // 0x80022144: addiu       $a2, $sp, 0xD0
    ctx->r6 = ADD32(ctx->r29, 0XD0);
L_80022148:
    // 0x80022148: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x8002214C: lwc1        $f8, -0x4($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, -0X4);
    // 0x80022150: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80022154: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80022158: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x8002215C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80022160: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x80022164: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x80022168: bc1f        L_80022180
    if (!c1cs) {
        // 0x8002216C: subu        $a0, $t2, $a1
        ctx->r4 = SUB32(ctx->r10, ctx->r5);
            goto L_80022180;
    }
    // 0x8002216C: subu        $a0, $t2, $a1
    ctx->r4 = SUB32(ctx->r10, ctx->r5);
    // 0x80022170: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80022174: sub.d       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f4.d - ctx->f14.d;
    // 0x80022178: b           L_8002219C
    // 0x8002217C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_8002219C;
    // 0x8002217C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80022180:
    // 0x80022180: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80022184: nop

    // 0x80022188: bc1f        L_8002219C
    if (!c1cs) {
        // 0x8002218C: nop
    
            goto L_8002219C;
    }
    // 0x8002218C: nop

    // 0x80022190: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80022194: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x80022198: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_8002219C:
    // 0x8002219C: beq         $at, $zero, L_80022220
    if (ctx->r1 == 0) {
        // 0x800221A0: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_80022220;
    }
    // 0x800221A0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800221A4: andi        $t8, $a0, 0x3
    ctx->r24 = ctx->r4 & 0X3;
    // 0x800221A8: beq         $t8, $zero, L_800221D8
    if (ctx->r24 == 0) {
        // 0x800221AC: addu        $v1, $t8, $a1
        ctx->r3 = ADD32(ctx->r24, ctx->r5);
            goto L_800221D8;
    }
    // 0x800221AC: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x800221B0: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x800221B4: addiu       $t3, $sp, 0xBC
    ctx->r11 = ADD32(ctx->r29, 0XBC);
    // 0x800221B8: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
L_800221BC:
    // 0x800221BC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800221C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800221C4: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800221C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800221CC: bne         $v1, $s0, L_800221BC
    if (ctx->r3 != ctx->r16) {
        // 0x800221D0: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_800221BC;
    }
    // 0x800221D0: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800221D4: beq         $s0, $t2, L_8002221C
    if (ctx->r16 == ctx->r10) {
        // 0x800221D8: sll         $t4, $s0, 2
        ctx->r12 = S32(ctx->r16 << 2);
            goto L_8002221C;
    }
L_800221D8:
    // 0x800221D8: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800221DC: addiu       $t5, $sp, 0xBC
    ctx->r13 = ADD32(ctx->r29, 0XBC);
    // 0x800221E0: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_800221E4:
    // 0x800221E4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800221E8: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800221EC: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800221F0: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800221F4: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800221F8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800221FC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80022200: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80022204: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80022208: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002220C: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80022210: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80022214: bne         $v0, $a2, L_800221E4
    if (ctx->r2 != ctx->r6) {
        // 0x80022218: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_800221E4;
    }
    // 0x80022218: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
L_8002221C:
    // 0x8002221C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
L_80022220:
    // 0x80022220: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80022224: lwc1        $f8, -0x4($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, -0X4);
    // 0x80022228: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8002222C: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80022230: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80022234: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80022238: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x8002223C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x80022240: bc1f        L_80022258
    if (!c1cs) {
        // 0x80022244: addiu       $t7, $zero, 0x5
        ctx->r15 = ADD32(0, 0X5);
            goto L_80022258;
    }
    // 0x80022244: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80022248: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8002224C: sub.d       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f4.d - ctx->f14.d;
    // 0x80022250: b           L_80022274
    // 0x80022254: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_80022274;
    // 0x80022254: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80022258:
    // 0x80022258: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x8002225C: nop

    // 0x80022260: bc1f        L_80022274
    if (!c1cs) {
        // 0x80022264: nop
    
            goto L_80022274;
    }
    // 0x80022264: nop

    // 0x80022268: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x8002226C: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x80022270: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80022274:
    // 0x80022274: beq         $at, $zero, L_800222F8
    if (ctx->r1 == 0) {
        // 0x80022278: subu        $a0, $t7, $a1
        ctx->r4 = SUB32(ctx->r15, ctx->r5);
            goto L_800222F8;
    }
    // 0x80022278: subu        $a0, $t7, $a1
    ctx->r4 = SUB32(ctx->r15, ctx->r5);
    // 0x8002227C: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x80022280: beq         $t6, $zero, L_800222B0
    if (ctx->r14 == 0) {
        // 0x80022284: addu        $v1, $t6, $a1
        ctx->r3 = ADD32(ctx->r14, ctx->r5);
            goto L_800222B0;
    }
    // 0x80022284: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x80022288: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8002228C: addiu       $t9, $sp, 0xA8
    ctx->r25 = ADD32(ctx->r29, 0XA8);
    // 0x80022290: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
L_80022294:
    // 0x80022294: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022298: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002229C: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800222A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800222A4: bne         $v1, $s0, L_80022294
    if (ctx->r3 != ctx->r16) {
        // 0x800222A8: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80022294;
    }
    // 0x800222A8: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800222AC: beq         $s0, $t2, L_800222F4
    if (ctx->r16 == ctx->r10) {
        // 0x800222B0: sll         $t3, $s0, 2
        ctx->r11 = S32(ctx->r16 << 2);
            goto L_800222F4;
    }
L_800222B0:
    // 0x800222B0: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x800222B4: addiu       $t4, $sp, 0xA8
    ctx->r12 = ADD32(ctx->r29, 0XA8);
    // 0x800222B8: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_800222BC:
    // 0x800222BC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800222C0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800222C4: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800222C8: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800222CC: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800222D0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800222D4: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800222D8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800222DC: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800222E0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800222E4: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800222E8: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800222EC: bne         $v0, $a3, L_800222BC
    if (ctx->r2 != ctx->r7) {
        // 0x800222F0: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_800222BC;
    }
    // 0x800222F0: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
L_800222F4:
    // 0x800222F4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
L_800222F8:
    // 0x800222F8: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800222FC: lwc1        $f8, -0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, -0X4);
    // 0x80022300: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80022304: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80022308: subu        $a0, $t5, $a1
    ctx->r4 = SUB32(ctx->r13, ctx->r5);
    // 0x8002230C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80022310: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x80022314: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x80022318: bc1f        L_80022330
    if (!c1cs) {
        // 0x8002231C: slti        $at, $a1, 0x5
        ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
            goto L_80022330;
    }
    // 0x8002231C: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80022320: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80022324: sub.d       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f4.d - ctx->f14.d;
    // 0x80022328: b           L_8002234C
    // 0x8002232C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_8002234C;
    // 0x8002232C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80022330:
    // 0x80022330: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80022334: nop

    // 0x80022338: bc1f        L_8002234C
    if (!c1cs) {
        // 0x8002233C: nop
    
            goto L_8002234C;
    }
    // 0x8002233C: nop

    // 0x80022340: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80022344: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x80022348: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_8002234C:
    // 0x8002234C: beq         $at, $zero, L_800223C8
    if (ctx->r1 == 0) {
        // 0x80022350: andi        $t7, $a0, 0x3
        ctx->r15 = ctx->r4 & 0X3;
            goto L_800223C8;
    }
    // 0x80022350: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x80022354: beq         $t7, $zero, L_80022384
    if (ctx->r15 == 0) {
        // 0x80022358: addu        $v1, $t7, $a1
        ctx->r3 = ADD32(ctx->r15, ctx->r5);
            goto L_80022384;
    }
    // 0x80022358: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x8002235C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80022360: addiu       $t8, $sp, 0x94
    ctx->r24 = ADD32(ctx->r29, 0X94);
    // 0x80022364: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
L_80022368:
    // 0x80022368: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002236C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80022370: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80022374: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022378: bne         $v1, $s0, L_80022368
    if (ctx->r3 != ctx->r16) {
        // 0x8002237C: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80022368;
    }
    // 0x8002237C: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80022380: beq         $s0, $t2, L_800223C8
    if (ctx->r16 == ctx->r10) {
        // 0x80022384: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_800223C8;
    }
L_80022384:
    // 0x80022384: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80022388: addiu       $t3, $sp, 0x94
    ctx->r11 = ADD32(ctx->r29, 0X94);
    // 0x8002238C: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
L_80022390:
    // 0x80022390: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022394: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80022398: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8002239C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800223A0: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800223A4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800223A8: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800223AC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800223B0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800223B4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800223B8: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800223BC: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800223C0: bne         $v0, $t0, L_80022390
    if (ctx->r2 != ctx->r8) {
        // 0x800223C4: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80022390;
    }
    // 0x800223C4: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
L_800223C8:
    // 0x800223C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800223CC: bne         $a1, $t2, L_80022148
    if (ctx->r5 != ctx->r10) {
        // 0x800223D0: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_80022148;
    }
    // 0x800223D0: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800223D4: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x800223D8: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800223DC: lb          $t5, 0x3F($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X3F);
    // 0x800223E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800223E4: bne         $t5, $zero, L_80022494
    if (ctx->r13 != 0) {
        // 0x800223E8: addiu       $a0, $sp, 0xBC
        ctx->r4 = ADD32(ctx->r29, 0XBC);
            goto L_80022494;
    }
    // 0x800223E8: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x800223EC: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800223F0: jal         0x80022574
    // 0x800223F4: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    catmull_rom_interpolation(rdram, ctx);
        goto after_24;
    // 0x800223F4: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    after_24:
    // 0x800223F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800223FC: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x80022400: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80022404: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022408: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002240C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80022410: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80022414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022418: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8002241C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80022420: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x80022424: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80022428: jal         0x80022574
    // 0x8002242C: nop

    catmull_rom_interpolation(rdram, ctx);
        goto after_25;
    // 0x8002242C: nop

    after_25:
    // 0x80022430: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80022434: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x80022438: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002243C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022440: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022444: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80022448: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8002244C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022450: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80022454: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80022458: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x8002245C: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80022460: jal         0x80022574
    // 0x80022464: nop

    catmull_rom_interpolation(rdram, ctx);
        goto after_26;
    // 0x80022464: nop

    after_26:
    // 0x80022468: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002246C: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x80022470: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80022474: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022478: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002247C: nop

    // 0x80022480: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80022484: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80022488: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002248C: b           L_80022538
    // 0x80022490: sh          $t7, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r15;
        goto L_80022538;
    // 0x80022490: sh          $t7, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r15;
L_80022494:
    // 0x80022494: jal         0x800228BC
    // 0x80022498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lerp(rdram, ctx);
        goto after_27;
    // 0x80022498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x8002249C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800224A0: lw          $t3, 0x154($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X154);
    // 0x800224A4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800224A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800224AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800224B0: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800224B4: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800224B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800224BC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800224C0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800224C4: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
    // 0x800224C8: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800224CC: jal         0x800228BC
    // 0x800224D0: nop

    lerp(rdram, ctx);
        goto after_28;
    // 0x800224D0: nop

    after_28:
    // 0x800224D4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800224D8: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x800224DC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800224E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800224E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800224E8: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x800224EC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800224F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800224F4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800224F8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800224FC: sh          $t5, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r13;
    // 0x80022500: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80022504: jal         0x800228BC
    // 0x80022508: nop

    lerp(rdram, ctx);
        goto after_29;
    // 0x80022508: nop

    after_29:
    // 0x8002250C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80022510: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x80022514: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80022518: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002251C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022520: nop

    // 0x80022524: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80022528: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8002252C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80022530: sh          $t8, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r24;
    // 0x80022534: nop

L_80022538:
    // 0x80022538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002253C:
    // 0x8002253C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80022540: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80022544: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80022548: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002254C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80022550: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80022554: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80022558: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8002255C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80022560: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80022564: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80022568: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8002256C: jr          $ra
    // 0x80022570: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x80022570: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
;}
RECOMP_FUNC void get_previous_particle_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4A8C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B4A90: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B4A94: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x800B4A98: bgez        $v1, L_800B4AC0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B4A9C: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_800B4AC0;
    }
    // 0x800B4A9C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B4AA0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B4AA4: addiu       $v0, $v0, 0x3278
    ctx->r2 = ADD32(ctx->r2, 0X3278);
L_800B4AA8:
    // 0x800B4AA8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B4AAC: nop

    // 0x800B4AB0: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800B4AB4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B4AB8: bltz        $t9, L_800B4AA8
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B4ABC: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800B4AA8;
    }
    // 0x800B4ABC: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_800B4AC0:
    // 0x800B4AC0: lw          $t0, 0x3280($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3280);
    // 0x800B4AC4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800B4AC8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B4ACC: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800B4AD0: jr          $ra
    // 0x800B4AD4: nop

    return;
    // 0x800B4AD4: nop

;}
RECOMP_FUNC void decrypt_magic_codes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C2D8: sra         $a2, $a1, 2
    ctx->r6 = S32(SIGNED(ctx->r5) >> 2);
    // 0x8000C2DC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000C2E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000C2E4: blez        $a2, L_8000C458
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000C2E8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C458;
    }
    // 0x8000C2E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000C2EC:
    // 0x8000C2EC: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C2F0: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C2F4: andi        $t7, $t6, 0xC0
    ctx->r15 = ctx->r14 & 0XC0;
    // 0x8000C2F8: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C2FC: sra         $t8, $t7, 6
    ctx->r24 = S32(SIGNED(ctx->r15) >> 6);
    // 0x8000C300: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C304: andi        $t1, $t9, 0xC0
    ctx->r9 = ctx->r25 & 0XC0;
    // 0x8000C308: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8000C30C: andi        $t4, $t3, 0xC0
    ctx->r12 = ctx->r11 & 0XC0;
    // 0x8000C310: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x8000C314: andi        $t9, $t7, 0xC0
    ctx->r25 = ctx->r15 & 0XC0;
    // 0x8000C318: sra         $t8, $t9, 4
    ctx->r24 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8000C31C: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x8000C320: or          $t1, $t6, $t8
    ctx->r9 = ctx->r14 | ctx->r24;
    // 0x8000C324: sb          $t1, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r9;
    // 0x8000C328: lbu         $t3, 0x3($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C32C: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C330: andi        $t4, $t3, 0x30
    ctx->r12 = ctx->r11 & 0X30;
    // 0x8000C334: sra         $t2, $t4, 4
    ctx->r10 = S32(SIGNED(ctx->r12) >> 4);
    // 0x8000C338: lbu         $t4, 0x2($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C33C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C340: andi        $t7, $t5, 0x30
    ctx->r15 = ctx->r13 & 0X30;
    // 0x8000C344: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000C348: or          $t6, $t2, $t9
    ctx->r14 = ctx->r10 | ctx->r25;
    // 0x8000C34C: andi        $t5, $t4, 0x30
    ctx->r13 = ctx->r12 & 0X30;
    // 0x8000C350: andi        $t1, $t8, 0x30
    ctx->r9 = ctx->r24 & 0X30;
    // 0x8000C354: or          $t3, $t6, $t1
    ctx->r11 = ctx->r14 | ctx->r9;
    // 0x8000C358: sra         $t7, $t5, 2
    ctx->r15 = S32(SIGNED(ctx->r13) >> 2);
    // 0x8000C35C: or          $t2, $t3, $t7
    ctx->r10 = ctx->r11 | ctx->r15;
    // 0x8000C360: sb          $t2, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r10;
    // 0x8000C364: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C368: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C36C: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C370: andi        $t4, $t1, 0xC
    ctx->r12 = ctx->r9 & 0XC;
    // 0x8000C374: andi        $t8, $t9, 0xC
    ctx->r24 = ctx->r25 & 0XC;
    // 0x8000C378: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C37C: sra         $t6, $t8, 2
    ctx->r14 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8000C380: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8000C384: andi        $t2, $t7, 0xC
    ctx->r10 = ctx->r15 & 0XC;
    // 0x8000C388: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x8000C38C: or          $t3, $t6, $t5
    ctx->r11 = ctx->r14 | ctx->r13;
    // 0x8000C390: or          $t8, $t3, $t9
    ctx->r24 = ctx->r11 | ctx->r25;
    // 0x8000C394: andi        $t4, $t1, 0xC
    ctx->r12 = ctx->r9 & 0XC;
    // 0x8000C398: or          $t6, $t8, $t4
    ctx->r14 = ctx->r24 | ctx->r12;
    // 0x8000C39C: sb          $t6, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r14;
    // 0x8000C3A0: lbu         $t5, 0x3($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C3A4: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C3A8: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C3AC: andi        $t7, $t5, 0x3
    ctx->r15 = ctx->r13 & 0X3;
    // 0x8000C3B0: andi        $t4, $t8, 0x3
    ctx->r12 = ctx->r24 & 0X3;
    // 0x8000C3B4: sll         $t9, $t3, 6
    ctx->r25 = S32(ctx->r11 << 6);
    // 0x8000C3B8: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C3BC: lbu         $a0, 0x0($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X0);
    // 0x8000C3C0: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x8000C3C4: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x8000C3C8: or          $t5, $t1, $t6
    ctx->r13 = ctx->r9 | ctx->r14;
    // 0x8000C3CC: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x8000C3D0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8000C3D4: andi        $t1, $a0, 0xAA
    ctx->r9 = ctx->r4 & 0XAA;
    // 0x8000C3D8: andi        $t8, $a0, 0x55
    ctx->r24 = ctx->r4 & 0X55;
    // 0x8000C3DC: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x8000C3E0: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x8000C3E4: sra         $t6, $t1, 1
    ctx->r14 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8000C3E8: sb          $t9, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r25;
    // 0x8000C3EC: or          $t2, $t4, $t6
    ctx->r10 = ctx->r12 | ctx->r14;
    // 0x8000C3F0: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x8000C3F4: lbu         $a1, 0x1($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1);
    // 0x8000C3F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000C3FC: andi        $t3, $a1, 0x55
    ctx->r11 = ctx->r5 & 0X55;
    // 0x8000C400: andi        $t7, $a1, 0xAA
    ctx->r15 = ctx->r5 & 0XAA;
    // 0x8000C404: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000C408: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x8000C40C: or          $t8, $t5, $t9
    ctx->r24 = ctx->r13 | ctx->r25;
    // 0x8000C410: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8000C414: lbu         $a3, 0x2($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2);
    // 0x8000C418: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000C41C: andi        $t1, $a3, 0x55
    ctx->r9 = ctx->r7 & 0X55;
    // 0x8000C420: andi        $t6, $a3, 0xAA
    ctx->r14 = ctx->r7 & 0XAA;
    // 0x8000C424: sra         $t2, $t6, 1
    ctx->r10 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8000C428: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x8000C42C: or          $t3, $t4, $t2
    ctx->r11 = ctx->r12 | ctx->r10;
    // 0x8000C430: sb          $t3, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r11;
    // 0x8000C434: lbu         $t0, 0x3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3);
    // 0x8000C438: nop

    // 0x8000C43C: andi        $t7, $t0, 0x55
    ctx->r15 = ctx->r8 & 0X55;
    // 0x8000C440: andi        $t9, $t0, 0xAA
    ctx->r25 = ctx->r8 & 0XAA;
    // 0x8000C444: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8000C448: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x8000C44C: or          $t1, $t5, $t8
    ctx->r9 = ctx->r13 | ctx->r24;
    // 0x8000C450: bne         $v1, $a2, L_8000C2EC
    if (ctx->r3 != ctx->r6) {
        // 0x8000C454: sb          $t1, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r9;
            goto L_8000C2EC;
    }
    // 0x8000C454: sb          $t1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r9;
L_8000C458:
    // 0x8000C458: jr          $ra
    // 0x8000C45C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8000C45C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void tex_init_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B0C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B0C8: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007B0CC: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007B0D0: jal         0x80070EDC
    // 0x8007B0D4: addiu       $a0, $zero, 0x15E0
    ctx->r4 = ADD32(0, 0X15E0);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8007B0D4: addiu       $a0, $zero, 0x15E0
    ctx->r4 = ADD32(0, 0X15E0);
    after_0:
    // 0x8007B0D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B0DC: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007B0E0: sw          $v0, 0x68C8($at)
    MEM_W(0X68C8, ctx->r1) = ctx->r2;
    // 0x8007B0E4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007B0E8: jal         0x80070EDC
    // 0x8007B0EC: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8007B0EC: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    after_1:
    // 0x8007B0F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B0F4: sw          $v0, 0x68CC($at)
    MEM_W(0X68CC, ctx->r1) = ctx->r2;
    // 0x8007B0F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B0FC: sw          $zero, 0x68D0($at)
    MEM_W(0X68D0, ctx->r1) = 0;
    // 0x8007B100: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B104: sw          $zero, 0x68E0($at)
    MEM_W(0X68E0, ctx->r1) = 0;
    // 0x8007B108: jal         0x80076EE4
    // 0x8007B10C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    asset_table_load(rdram, ctx);
        goto after_2;
    // 0x8007B10C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x8007B110: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007B114: addiu       $a1, $a1, 0x68C0
    ctx->r5 = ADD32(ctx->r5, 0X68C0);
    // 0x8007B118: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8007B11C: jal         0x80076EE4
    // 0x8007B120: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    asset_table_load(rdram, ctx);
        goto after_3;
    // 0x8007B120: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8007B124: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007B128: addiu       $a1, $a1, 0x68C0
    ctx->r5 = ADD32(ctx->r5, 0X68C0);
    // 0x8007B12C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8007B130: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8007B134: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007B138: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8007B13C: beq         $a3, $t6, L_8007B158
    if (ctx->r7 == ctx->r14) {
        // 0x8007B140: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007B158;
    }
    // 0x8007B140: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007B144: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007B148:
    // 0x8007B148: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8007B14C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007B150: bne         $a3, $t7, L_8007B148
    if (ctx->r7 != ctx->r15) {
        // 0x8007B154: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8007B148;
    }
    // 0x8007B154: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8007B158:
    // 0x8007B158: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007B15C: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    // 0x8007B160: addiu       $a2, $a2, 0x68D8
    ctx->r6 = ADD32(ctx->r6, 0X68D8);
    // 0x8007B164: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007B168: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8007B16C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8007B170: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007B174: beq         $a3, $t8, L_8007B190
    if (ctx->r7 == ctx->r24) {
        // 0x8007B178: lui         $a1, 0xFF00
        ctx->r5 = S32(0XFF00 << 16);
            goto L_8007B190;
    }
    // 0x8007B178: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007B17C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007B180:
    // 0x8007B180: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8007B184: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007B188: bne         $a3, $t9, L_8007B180
    if (ctx->r7 != ctx->r25) {
        // 0x8007B18C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8007B180;
    }
    // 0x8007B18C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8007B190:
    // 0x8007B190: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007B194: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x8007B198: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    // 0x8007B19C: jal         0x80070EDC
    // 0x8007B1A0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x8007B1A0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_4:
    // 0x8007B1A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B1A8: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007B1AC: sw          $v0, 0x68EC($at)
    MEM_W(0X68EC, ctx->r1) = ctx->r2;
    // 0x8007B1B0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007B1B4: jal         0x80070EDC
    // 0x8007B1B8: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8007B1B8: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_5:
    // 0x8007B1BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B1C0: sw          $v0, 0x68F0($at)
    MEM_W(0X68F0, ctx->r1) = ctx->r2;
    // 0x8007B1C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B1C8: sw          $zero, 0x68F8($at)
    MEM_W(0X68F8, ctx->r1) = 0;
    // 0x8007B1CC: jal         0x80076EE4
    // 0x8007B1D0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    asset_table_load(rdram, ctx);
        goto after_6;
    // 0x8007B1D0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_6:
    // 0x8007B1D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007B1D8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007B1DC: addiu       $a2, $a2, 0x68F4
    ctx->r6 = ADD32(ctx->r6, 0X68F4);
    // 0x8007B1E0: addiu       $a1, $a1, 0x68E8
    ctx->r5 = ADD32(ctx->r5, 0X68E8);
    // 0x8007B1E4: sll         $t0, $zero, 2
    ctx->r8 = S32(0 << 2);
    // 0x8007B1E8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8007B1EC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8007B1F0: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8007B1F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8007B1F8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8007B1FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8007B200: beq         $a3, $t2, L_8007B228
    if (ctx->r7 == ctx->r10) {
        // 0x8007B204: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007B228;
    }
    // 0x8007B204: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007B208: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
L_8007B20C:
    // 0x8007B20C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007B210: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8007B214: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8007B218: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8007B21C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x8007B220: bne         $a3, $t6, L_8007B20C
    if (ctx->r7 != ctx->r14) {
        // 0x8007B224: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_8007B20C;
    }
    // 0x8007B224: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
L_8007B228:
    // 0x8007B228: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8007B22C: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007B230: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007B234: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007B238: jal         0x80070EDC
    // 0x8007B23C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x8007B23C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_7:
    // 0x8007B240: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B248: sw          $v0, 0x690C($at)
    MEM_W(0X690C, ctx->r1) = ctx->r2;
    // 0x8007B24C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B250: sw          $zero, 0x68E4($at)
    MEM_W(0X68E4, ctx->r1) = 0;
    // 0x8007B254: jr          $ra
    // 0x8007B258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007B258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void music_voicelimit_change_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C1C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000C20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000C24: jr          $ra
    // 0x80000C28: sb          $t6, -0x3420($at)
    MEM_B(-0X3420, ctx->r1) = ctx->r14;
    return;
    // 0x80000C28: sb          $t6, -0x3420($at)
    MEM_B(-0X3420, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void rumble_set_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072670: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80072674: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80072678: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x8007267C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80072680: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80072684: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80072688: slti        $at, $t8, 0x13
    ctx->r1 = SIGNED(ctx->r24) < 0X13 ? 1 : 0;
    // 0x8007268C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80072690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072694: beq         $at, $zero, L_800727B4
    if (ctx->r1 == 0) {
        // 0x80072698: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800727B4;
    }
    // 0x80072698: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007269C: bltz        $t7, L_800727B4
    if (SIGNED(ctx->r15) < 0) {
        // 0x800726A0: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_800727B4;
    }
    // 0x800726A0: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x800726A4: beq         $at, $zero, L_800727B8
    if (ctx->r1 == 0) {
        // 0x800726A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800727B8;
    }
    // 0x800726A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800726AC: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
    // 0x800726B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800726B4: jal         0x80072490
    // 0x800726B8: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    input_get_id(rdram, ctx);
        goto after_0;
    // 0x800726B8: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800726BC: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x800726C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800726C4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800726C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800726CC: addiu       $t1, $t1, 0x4738
    ctx->r9 = ADD32(ctx->r9, 0X4738);
    // 0x800726D0: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800726D4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x800726D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800726DC: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800726E0: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x800726E4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800726E8: bne         $a2, $t2, L_8007271C
    if (ctx->r6 != ctx->r10) {
        // 0x800726EC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8007271C;
    }
    // 0x800726EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800726F0: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x800726F4: addiu       $t4, $zero, -0x12C
    ctx->r12 = ADD32(0, -0X12C);
    // 0x800726F8: bgez        $t3, L_80072704
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800726FC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80072704;
    }
    // 0x800726FC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80072700: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
L_80072704:
    // 0x80072704: lw          $t5, 0x4760($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4760);
    // 0x80072708: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8007270C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80072710: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80072714: b           L_800727B4
    // 0x80072718: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
        goto L_800727B4;
    // 0x80072718: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
L_8007271C:
    // 0x8007271C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80072720: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80072724: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80072728: nop

    // 0x8007272C: bc1f        L_80072738
    if (!c1cs) {
        // 0x80072730: nop
    
            goto L_80072738;
    }
    // 0x80072730: nop

    // 0x80072734: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80072738:
    // 0x80072738: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007273C: nop

    // 0x80072740: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80072744: nop

    // 0x80072748: bc1f        L_80072754
    if (!c1cs) {
        // 0x8007274C: nop
    
            goto L_80072754;
    }
    // 0x8007274C: nop

    // 0x80072750: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80072754:
    // 0x80072754: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x80072758: lw          $t0, 0x4760($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4760);
    // 0x8007275C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80072760: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x80072764: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x80072768: nop

    // 0x8007276C: beq         $a3, $zero, L_800727B8
    if (ctx->r7 == 0) {
        // 0x80072770: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800727B8;
    }
    // 0x80072770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072774: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x80072778: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x8007277C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80072780: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80072784: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80072788: nop

    // 0x8007278C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80072790: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80072794: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80072798: nop

    // 0x8007279C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800727A0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800727A4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800727A8: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x800727AC: jal         0x800727C4
    // 0x800727B0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    rumble_start(rdram, ctx);
        goto after_1;
    // 0x800727B0: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_1:
L_800727B4:
    // 0x800727B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800727B8:
    // 0x800727B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800727BC: jr          $ra
    // 0x800727C0: nop

    return;
    // 0x800727C0: nop

;}
RECOMP_FUNC void increment_ai_behaviour_chances(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043F0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043F14: bne         $a0, $zero, L_80043F38
    if (ctx->r4 != 0) {
        // 0x80043F18: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80043F38;
    }
    // 0x80043F18: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80043F1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043F20: sb          $zero, -0x24C6($at)
    MEM_B(-0X24C6, ctx->r1) = 0;
    // 0x80043F24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043F28: sb          $zero, -0x24C5($at)
    MEM_B(-0X24C5, ctx->r1) = 0;
    // 0x80043F2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043F30: b           L_800441A0
    // 0x80043F34: sb          $zero, -0x24C4($at)
    MEM_B(-0X24C4, ctx->r1) = 0;
        goto L_800441A0;
    // 0x80043F34: sb          $zero, -0x24C4($at)
    MEM_B(-0X24C4, ctx->r1) = 0;
L_80043F38:
    // 0x80043F38: jal         0x8006C3CC
    // 0x80043F3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    aitable_get(rdram, ctx);
        goto after_0;
    // 0x80043F3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80043F40: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80043F44: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80043F48: lb          $t6, 0x1D3($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1D3);
    // 0x80043F4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043F50: beq         $t6, $zero, L_80043FBC
    if (ctx->r14 == 0) {
        // 0x80043F54: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_80043FBC;
    }
    // 0x80043F54: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80043F58: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80043F5C: lb          $t7, -0x24C5($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X24C5);
    // 0x80043F60: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80043F64: bne         $t7, $zero, L_80043F94
    if (ctx->r15 != 0) {
        // 0x80043F68: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80043F94;
    }
    // 0x80043F68: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80043F6C: lb          $t8, 0x14($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X14);
    // 0x80043F70: lb          $t9, 0x16($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X16);
    // 0x80043F74: lb          $t1, 0x15($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X15);
    // 0x80043F78: lb          $t2, 0x17($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X17);
    // 0x80043F7C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80043F80: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80043F84: sb          $t0, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r8;
    // 0x80043F88: sb          $t3, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r11;
    // 0x80043F8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043F90: sb          $t4, -0x24C5($at)
    MEM_B(-0X24C5, ctx->r1) = ctx->r12;
L_80043F94:
    // 0x80043F94: lw          $t5, -0x2558($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2558);
    // 0x80043F98: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80043F9C: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80043FA0: bne         $t6, $zero, L_80043FFC
    if (ctx->r14 != 0) {
        // 0x80043FA4: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80043FFC;
    }
    // 0x80043FA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80043FA8: lb          $t7, -0x24C6($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X24C6);
    // 0x80043FAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043FB0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80043FB4: b           L_80043FFC
    // 0x80043FB8: sb          $t9, -0x24C6($at)
    MEM_B(-0X24C6, ctx->r1) = ctx->r25;
        goto L_80043FFC;
    // 0x80043FB8: sb          $t9, -0x24C6($at)
    MEM_B(-0X24C6, ctx->r1) = ctx->r25;
L_80043FBC:
    // 0x80043FBC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80043FC0: lb          $t0, -0x24C6($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X24C6);
    // 0x80043FC4: sb          $zero, -0x24C5($at)
    MEM_B(-0X24C5, ctx->r1) = 0;
    // 0x80043FC8: slti        $at, $t0, 0x15
    ctx->r1 = SIGNED(ctx->r8) < 0X15 ? 1 : 0;
    // 0x80043FCC: bne         $at, $zero, L_80043FF4
    if (ctx->r1 != 0) {
        // 0x80043FD0: nop
    
            goto L_80043FF4;
    }
    // 0x80043FD0: nop

    // 0x80043FD4: lb          $t1, 0x8($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X8);
    // 0x80043FD8: lb          $t2, 0xA($v0)
    ctx->r10 = MEM_B(ctx->r2, 0XA);
    // 0x80043FDC: lb          $t4, 0x9($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X9);
    // 0x80043FE0: lb          $t5, 0xB($v0)
    ctx->r13 = MEM_B(ctx->r2, 0XB);
    // 0x80043FE4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80043FE8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80043FEC: sb          $t3, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r11;
    // 0x80043FF0: sb          $t6, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r14;
L_80043FF4:
    // 0x80043FF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043FF8: sb          $zero, -0x24C6($at)
    MEM_B(-0X24C6, ctx->r1) = 0;
L_80043FFC:
    // 0x80043FFC: lb          $t7, 0x173($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X173);
    // 0x80044000: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80044004: beq         $t7, $zero, L_80044058
    if (ctx->r15 == 0) {
        // 0x80044008: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80044058;
    }
    // 0x80044008: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004400C: lb          $v1, 0x174($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X174);
    // 0x80044010: lb          $t8, -0x24C4($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X24C4);
    // 0x80044014: nop

    // 0x80044018: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004401C: beq         $at, $zero, L_8004404C
    if (ctx->r1 == 0) {
        // 0x80044020: nop
    
            goto L_8004404C;
    }
    // 0x80044020: nop

    // 0x80044024: lb          $t9, 0xC($v0)
    ctx->r25 = MEM_B(ctx->r2, 0XC);
    // 0x80044028: lb          $t0, 0xE($v0)
    ctx->r8 = MEM_B(ctx->r2, 0XE);
    // 0x8004402C: lb          $t2, 0xD($v0)
    ctx->r10 = MEM_B(ctx->r2, 0XD);
    // 0x80044030: lb          $t3, 0xF($v0)
    ctx->r11 = MEM_B(ctx->r2, 0XF);
    // 0x80044034: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80044038: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004403C: sb          $t1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r9;
    // 0x80044040: sb          $t4, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r12;
    // 0x80044044: lb          $v1, 0x174($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X174);
    // 0x80044048: nop

L_8004404C:
    // 0x8004404C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044050: b           L_8004405C
    // 0x80044054: sb          $v1, -0x24C4($at)
    MEM_B(-0X24C4, ctx->r1) = ctx->r3;
        goto L_8004405C;
    // 0x80044054: sb          $v1, -0x24C4($at)
    MEM_B(-0X24C4, ctx->r1) = ctx->r3;
L_80044058:
    // 0x80044058: sb          $zero, -0x24C4($at)
    MEM_B(-0X24C4, ctx->r1) = 0;
L_8004405C:
    // 0x8004405C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80044060: jal         0x8001E2D0
    // 0x80044064: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80044064: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80044068: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004406C: lw          $t5, -0x2550($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2550);
    // 0x80044070: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80044074: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80044078: andi        $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 & 0X2000;
    // 0x8004407C: beq         $t6, $zero, L_80044108
    if (ctx->r14 == 0) {
        // 0x80044080: nop
    
            goto L_80044108;
    }
    // 0x80044080: nop

    // 0x80044084: lb          $t7, 0x173($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X173);
    // 0x80044088: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8004408C: beq         $t7, $zero, L_80044108
    if (ctx->r15 == 0) {
        // 0x80044090: nop
    
            goto L_80044108;
    }
    // 0x80044090: nop

    // 0x80044094: lb          $v1, 0x174($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X174);
    // 0x80044098: nop

    // 0x8004409C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800440A0: beq         $at, $zero, L_800440CC
    if (ctx->r1 == 0) {
        // 0x800440A4: nop
    
            goto L_800440CC;
    }
    // 0x800440A4: nop

    // 0x800440A8: lb          $t8, 0x172($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X172);
    // 0x800440AC: nop

    // 0x800440B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800440B4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800440B8: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x800440BC: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x800440C0: lb          $a0, 0x0($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X0);
    // 0x800440C4: b           L_800440D8
    // 0x800440C8: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
        goto L_800440D8;
    // 0x800440C8: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
L_800440CC:
    // 0x800440CC: lb          $a0, 0x172($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X172);
    // 0x800440D0: nop

    // 0x800440D4: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
L_800440D8:
    // 0x800440D8: lb          $t2, -0x2D00($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X2D00);
    // 0x800440DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800440E0: bne         $t2, $at, L_8004410C
    if (ctx->r10 != ctx->r1) {
        // 0x800440E4: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8004410C;
    }
    // 0x800440E4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800440E8: lb          $t3, 0x10($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X10);
    // 0x800440EC: lb          $t4, 0x12($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X12);
    // 0x800440F0: lb          $t6, 0x11($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X11);
    // 0x800440F4: lb          $t7, 0x13($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X13);
    // 0x800440F8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800440FC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80044100: sb          $t5, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r13;
    // 0x80044104: sb          $t8, 0x11($a2)
    MEM_B(0X11, ctx->r6) = ctx->r24;
L_80044108:
    // 0x80044108: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8004410C:
    // 0x8004410C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80044110: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80044114: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
L_80044118:
    // 0x80044118: lb          $v1, 0xC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0XC);
    // 0x8004411C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80044120: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x80044124: beq         $at, $zero, L_80044134
    if (ctx->r1 == 0) {
        // 0x80044128: nop
    
            goto L_80044134;
    }
    // 0x80044128: nop

    // 0x8004412C: bgez        $v1, L_80044138
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80044130: nop
    
            goto L_80044138;
    }
    // 0x80044130: nop

L_80044134:
    // 0x80044134: sb          $a0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r4;
L_80044138:
    // 0x80044138: lb          $v1, 0x8($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X8);
    // 0x8004413C: nop

    // 0x80044140: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x80044144: beq         $at, $zero, L_80044154
    if (ctx->r1 == 0) {
        // 0x80044148: nop
    
            goto L_80044154;
    }
    // 0x80044148: nop

    // 0x8004414C: bgez        $v1, L_80044158
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80044150: nop
    
            goto L_80044158;
    }
    // 0x80044150: nop

L_80044154:
    // 0x80044154: sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
L_80044158:
    // 0x80044158: lb          $v1, 0x14($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X14);
    // 0x8004415C: nop

    // 0x80044160: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x80044164: beq         $at, $zero, L_80044174
    if (ctx->r1 == 0) {
        // 0x80044168: nop
    
            goto L_80044174;
    }
    // 0x80044168: nop

    // 0x8004416C: bgez        $v1, L_80044178
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80044170: nop
    
            goto L_80044178;
    }
    // 0x80044170: nop

L_80044174:
    // 0x80044174: sb          $a0, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r4;
L_80044178:
    // 0x80044178: lb          $v1, 0x10($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X10);
    // 0x8004417C: nop

    // 0x80044180: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x80044184: beq         $at, $zero, L_80044194
    if (ctx->r1 == 0) {
        // 0x80044188: nop
    
            goto L_80044194;
    }
    // 0x80044188: nop

    // 0x8004418C: bgez        $v1, L_80044198
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80044190: nop
    
            goto L_80044198;
    }
    // 0x80044190: nop

L_80044194:
    // 0x80044194: sb          $a0, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r4;
L_80044198:
    // 0x80044198: bne         $a1, $a2, L_80044118
    if (ctx->r5 != ctx->r6) {
        // 0x8004419C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80044118;
    }
    // 0x8004419C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800441A0:
    // 0x800441A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800441A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800441A8: jr          $ra
    // 0x800441AC: nop

    return;
    // 0x800441AC: nop

;}
RECOMP_FUNC void gfxtask_run_fifo2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077D18: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80077D1C: addiu       $v1, $v1, -0x15AC
    ctx->r3 = ADD32(ctx->r3, -0X15AC);
    // 0x80077D20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80077D24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077D28: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80077D2C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077D30: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80077D34: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80077D38: addiu       $t7, $t7, 0x64E0
    ctx->r15 = ADD32(ctx->r15, 0X64E0);
    // 0x80077D3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80077D40: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80077D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077D48: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80077D4C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80077D50: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80077D54: bne         $t8, $at, L_80077D60
    if (ctx->r24 != ctx->r1) {
        // 0x80077D58: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80077D60;
    }
    // 0x80077D58: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077D5C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80077D60:
    // 0x80077D60: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80077D64: subu        $t0, $a1, $a0
    ctx->r8 = SUB32(ctx->r5, ctx->r4);
    // 0x80077D68: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80077D6C: addiu       $v0, $v0, -0x75E0
    ctx->r2 = ADD32(ctx->r2, -0X75E0);
    // 0x80077D70: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80077D74: addiu       $t5, $t5, -0x7510
    ctx->r13 = ADD32(ctx->r13, -0X7510);
    // 0x80077D78: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80077D7C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80077D80: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80077D84: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80077D88: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80077D8C: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x80077D90: addiu       $t7, $t7, -0x6310
    ctx->r15 = ADD32(ctx->r15, -0X6310);
    // 0x80077D94: addiu       $t8, $t8, -0x56E0
    ctx->r24 = ADD32(ctx->r24, -0X56E0);
    // 0x80077D98: sw          $t2, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r10;
    // 0x80077D9C: sw          $t3, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r11;
    // 0x80077DA0: sw          $t4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r12;
    // 0x80077DA4: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x80077DA8: sw          $t8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r24;
    // 0x80077DAC: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
    // 0x80077DB0: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x80077DB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80077DB8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80077DBC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80077DC0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80077DC4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077DC8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80077DCC: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x80077DD0: sw          $t9, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r25;
    // 0x80077DD4: addiu       $t0, $t0, 0x4840
    ctx->r8 = ADD32(ctx->r8, 0X4840);
    // 0x80077DD8: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x80077DDC: addiu       $t2, $t2, 0x4C40
    ctx->r10 = ADD32(ctx->r10, 0X4C40);
    // 0x80077DE0: addiu       $t3, $t3, 0x6440
    ctx->r11 = ADD32(ctx->r11, 0X6440);
    // 0x80077DE4: addiu       $t4, $t4, 0x7770
    ctx->r12 = ADD32(ctx->r12, 0X7770);
    // 0x80077DE8: addiu       $t5, $zero, 0xA00
    ctx->r13 = ADD32(0, 0XA00);
    // 0x80077DEC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80077DF0: addiu       $t7, $t7, 0x6478
    ctx->r15 = ADD32(ctx->r15, 0X6478);
    // 0x80077DF4: addiu       $t8, $t8, -0x15F0
    ctx->r24 = ADD32(ctx->r24, -0X15F0);
    // 0x80077DF8: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80077DFC: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x80077E00: sw          $t1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r9;
    // 0x80077E04: sw          $t2, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r10;
    // 0x80077E08: sw          $t3, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r11;
    // 0x80077E0C: sw          $t4, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r12;
    // 0x80077E10: sw          $t5, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r13;
    // 0x80077E14: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80077E18: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
    // 0x80077E1C: sw          $t7, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r15;
    // 0x80077E20: sw          $t8, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r24;
    // 0x80077E24: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80077E28: lw          $t9, 0x6874($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6874);
    // 0x80077E2C: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80077E30: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x80077E34: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x80077E38: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x80077E3C: sw          $t9, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r25;
    // 0x80077E40: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80077E44: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80077E48: beq         $t0, $zero, L_80077E58
    if (ctx->r8 == 0) {
        // 0x80077E4C: nop
    
            goto L_80077E58;
    }
    // 0x80077E4C: nop

    // 0x80077E50: sw          $v0, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r2;
    // 0x80077E54: sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
L_80077E58:
    // 0x80077E58: sw          $zero, 0x68($a3)
    MEM_W(0X68, ctx->r7) = 0;
    // 0x80077E5C: jal         0x800D1E00
    // 0x80077E60: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077E60: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80077E64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077E68: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80077E6C: lw          $a0, 0x66A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66A0);
    // 0x80077E70: jal         0x800C9390
    // 0x80077E74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077E74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80077E78: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80077E7C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077E80: beq         $t1, $zero, L_80077E94
    if (ctx->r9 == 0) {
        // 0x80077E84: addiu       $a0, $a0, 0x6478
        ctx->r4 = ADD32(ctx->r4, 0X6478);
            goto L_80077E94;
    }
    // 0x80077E84: addiu       $a0, $a0, 0x6478
    ctx->r4 = ADD32(ctx->r4, 0X6478);
    // 0x80077E88: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80077E8C: jal         0x800C9110
    // 0x80077E90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077E90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_80077E94:
    // 0x80077E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077E98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077E9C: jr          $ra
    // 0x80077EA0: nop

    return;
    // 0x80077EA0: nop

;}
RECOMP_FUNC void music_sequence_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800022BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800022C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800022C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800022C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800022CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800022D0: sb          $a2, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r6;
    // 0x800022D4: jal         0x80002570
    // 0x800022D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    music_sequence_stop(rdram, ctx);
        goto after_0;
    // 0x800022D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800022DC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800022E0: lw          $t6, 0x6278($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6278);
    // 0x800022E4: lbu         $a2, 0x1B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1B);
    // 0x800022E8: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x800022EC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800022F0: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800022F4: beq         $at, $zero, L_8000231C
    if (ctx->r1 == 0) {
        // 0x800022F8: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8000231C;
    }
    // 0x800022F8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800022FC: lw          $t9, -0x3460($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3460);
    // 0x80002300: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002304: bne         $t8, $t9, L_80002318
    if (ctx->r24 != ctx->r25) {
        // 0x80002308: nop
    
            goto L_80002318;
    }
    // 0x80002308: nop

    // 0x8000230C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002310: b           L_8000231C
    // 0x80002314: sb          $a2, -0x3434($at)
    MEM_B(-0X3434, ctx->r1) = ctx->r6;
        goto L_8000231C;
    // 0x80002314: sb          $a2, -0x3434($at)
    MEM_B(-0X3434, ctx->r1) = ctx->r6;
L_80002318:
    // 0x80002318: sb          $a2, -0x3430($at)
    MEM_B(-0X3430, ctx->r1) = ctx->r6;
L_8000231C:
    // 0x8000231C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002324: jr          $ra
    // 0x80002328: nop

    return;
    // 0x80002328: nop

;}
RECOMP_FUNC void func_80045C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045C88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045C8C: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x80045C90: sw          $zero, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = 0;
    // 0x80045C94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045C98: sw          $zero, -0x2554($at)
    MEM_W(-0X2554, ctx->r1) = 0;
    // 0x80045C9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045CA0: sw          $zero, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = 0;
    // 0x80045CA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045CA8: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
    // 0x80045CAC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80045CB0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80045CB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045CB8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80045CBC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80045CC0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80045CC4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80045CC8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80045CCC: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x80045CD0: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x80045CD4: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
    // 0x80045CD8: jal         0x8001BA98
    // 0x80045CDC: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
    get_checkpoint_count(rdram, ctx);
        goto after_0;
    // 0x80045CDC: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
    after_0:
    // 0x80045CE0: bne         $v0, $zero, L_80045CF8
    if (ctx->r2 != 0) {
        // 0x80045CE4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80045CF8;
    }
    // 0x80045CE4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80045CE8: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x80045CEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045CF0: b           L_80046544
    // 0x80045CF4: sw          $t6, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r14;
        goto L_80046544;
    // 0x80045CF4: sw          $t6, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r14;
L_80045CF8:
    // 0x80045CF8: lwc1        $f4, 0xA8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x80045CFC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80045D00: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80045D04: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80045D08: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80045D0C: sub.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d - ctx->f6.d;
    // 0x80045D10: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80045D14: cvt.s.d     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f20.fl = CVT_S_D(ctx->f8.d);
    // 0x80045D18: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80045D1C: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x80045D20: lb          $s0, 0x192($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X192);
    // 0x80045D24: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80045D28: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80045D2C: bc1f        L_80045D40
    if (!c1cs) {
        // 0x80045D30: addiu       $s0, $s0, -0x2
        ctx->r16 = ADD32(ctx->r16, -0X2);
            goto L_80045D40;
    }
    // 0x80045D30: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // 0x80045D34: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80045D38: nop

    // 0x80045D3C: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
L_80045D40:
    // 0x80045D40: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80045D44: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x80045D48: bc1f        L_80045D5C
    if (!c1cs) {
        // 0x80045D4C: addiu       $a3, $sp, 0xA0
        ctx->r7 = ADD32(ctx->r29, 0XA0);
            goto L_80045D5C;
    }
    // 0x80045D4C: addiu       $a3, $sp, 0xA0
    ctx->r7 = ADD32(ctx->r29, 0XA0);
    // 0x80045D50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80045D54: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80045D58: nop

L_80045D5C:
    // 0x80045D5C: bgez        $s0, L_80045D68
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80045D60: addiu       $v1, $sp, 0x90
        ctx->r3 = ADD32(ctx->r29, 0X90);
            goto L_80045D68;
    }
    // 0x80045D60: addiu       $v1, $sp, 0x90
    ctx->r3 = ADD32(ctx->r29, 0X90);
    // 0x80045D64: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_80045D68:
    // 0x80045D68: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80045D6C: bne         $at, $zero, L_80045D78
    if (ctx->r1 != 0) {
        // 0x80045D70: nop
    
            goto L_80045D78;
    }
    // 0x80045D70: nop

    // 0x80045D74: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
L_80045D78:
    // 0x80045D78: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x80045D7C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80045D80: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80045D84: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80045D88: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80045D8C: jal         0x8001BA50
    // 0x80045D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_1;
    // 0x80045D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80045D94: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80045D98: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80045D9C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80045DA0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80045DA4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80045DA8: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x80045DAC: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80045DB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80045DB4: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x80045DB8: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80045DBC: nop

    // 0x80045DC0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80045DC4: lbu         $t7, 0x1C9($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1C9);
    // 0x80045DC8: nop

    // 0x80045DCC: bne         $t7, $zero, L_80045EAC
    if (ctx->r15 != 0) {
        // 0x80045DD0: nop
    
            goto L_80045EAC;
    }
    // 0x80045DD0: nop

    // 0x80045DD4: lb          $t8, 0x1CA($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X1CA);
    // 0x80045DD8: addu        $t2, $sp, $t0
    ctx->r10 = ADD32(ctx->r29, ctx->r8);
    // 0x80045DDC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80045DE0: lb          $t1, 0x2E($t9)
    ctx->r9 = MEM_B(ctx->r25, 0X2E);
    // 0x80045DE4: addu        $t6, $sp, $t0
    ctx->r14 = ADD32(ctx->r29, ctx->r8);
    // 0x80045DE8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80045DEC: nop

    // 0x80045DF0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80045DF4: swc1        $f10, 0x74($t2)
    MEM_W(0X74, ctx->r10) = ctx->f10.u32l;
    // 0x80045DF8: lb          $t3, 0x1CA($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X1CA);
    // 0x80045DFC: nop

    // 0x80045E00: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80045E04: lb          $t5, 0x32($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X32);
    // 0x80045E08: nop

    // 0x80045E0C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80045E10: nop

    // 0x80045E14: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80045E18: swc1        $f4, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->f4.u32l;
    // 0x80045E1C: lb          $t7, 0x1CA($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1CA);
    // 0x80045E20: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80045E24: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80045E28: lb          $t9, 0x2E($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X2E);
    // 0x80045E2C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80045E30: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80045E34: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80045E38: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80045E3C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80045E40: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80045E44: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80045E48: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x80045E4C: lb          $t1, 0x1CA($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1CA);
    // 0x80045E50: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80045E54: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80045E58: lb          $t3, 0x32($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X32);
    // 0x80045E5C: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80045E60: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80045E64: nop

    // 0x80045E68: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80045E6C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80045E70: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80045E74: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x80045E78: lb          $t4, 0x1CA($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X1CA);
    // 0x80045E7C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80045E80: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80045E84: lb          $t6, 0x2E($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X2E);
    // 0x80045E88: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80045E8C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80045E90: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x80045E94: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80045E98: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80045E9C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80045EA0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80045EA4: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80045EA8: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_80045EAC:
    // 0x80045EAC: bne         $s0, $s2, L_80045EB8
    if (ctx->r16 != ctx->r18) {
        // 0x80045EB0: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80045EB8;
    }
    // 0x80045EB0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80045EB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80045EB8:
    // 0x80045EB8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80045EBC: addiu       $t7, $sp, 0xA0
    ctx->r15 = ADD32(ctx->r29, 0XA0);
    // 0x80045EC0: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x80045EC4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80045EC8: bne         $at, $zero, L_80045D78
    if (ctx->r1 != 0) {
        // 0x80045ECC: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80045D78;
    }
    // 0x80045ECC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80045ED0: lbu         $v0, 0x1C9($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1C9);
    // 0x80045ED4: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x80045ED8: bne         $v0, $zero, L_80045F64
    if (ctx->r2 != 0) {
        // 0x80045EDC: nop
    
            goto L_80045F64;
    }
    // 0x80045EDC: nop

    // 0x80045EE0: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80045EE4: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80045EE8: nop

    // 0x80045EEC: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80045EF0: mul.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80045EF4: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80045EF8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80045EFC: nop

    // 0x80045F00: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80045F04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80045F08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80045F0C: nop

    // 0x80045F10: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80045F14: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80045F18: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80045F1C: sh          $t9, 0x1BA($s1)
    MEM_H(0X1BA, ctx->r17) = ctx->r25;
    // 0x80045F20: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80045F24: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80045F28: nop

    // 0x80045F2C: sub.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80045F30: mul.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80045F34: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80045F38: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80045F3C: nop

    // 0x80045F40: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80045F44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80045F48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80045F4C: nop

    // 0x80045F50: cvt.w.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80045F54: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80045F58: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80045F5C: sh          $t2, 0x1BC($s1)
    MEM_H(0X1BC, ctx->r17) = ctx->r10;
    // 0x80045F60: nop

L_80045F64:
    // 0x80045F64: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80045F68: jal         0x800227B0
    // 0x80045F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_derivative(rdram, ctx);
        goto after_2;
    // 0x80045F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80045F70: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80045F74: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80045F78: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80045F7C: jal         0x800227B0
    // 0x80045F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_derivative(rdram, ctx);
        goto after_3;
    // 0x80045F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80045F84: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80045F88: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80045F8C: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x80045F90: jal         0x800227B0
    // 0x80045F94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_derivative(rdram, ctx);
        goto after_4;
    // 0x80045F94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80045F98: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80045F9C: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80045FA0: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80045FA4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80045FA8: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80045FAC: nop

    // 0x80045FB0: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80045FB4: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80045FB8: jal         0x800CA030
    // 0x80045FBC: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80045FBC: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_5:
    // 0x80045FC0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80045FC4: nop

    // 0x80045FC8: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x80045FCC: nop

    // 0x80045FD0: bc1t        L_80046008
    if (c1cs) {
        // 0x80045FD4: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80046008;
    }
    // 0x80045FD4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80045FD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80045FDC: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80045FE0: div.s       $f20, $f8, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80045FE4: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80045FE8: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80045FEC: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80045FF0: nop

    // 0x80045FF4: mul.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80045FF8: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80045FFC: mul.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80046000: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x80046004: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
L_80046008:
    // 0x80046008: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004600C: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80046010: jal         0x80070990
    // 0x80046014: nop

    arctan2_f(rdram, ctx);
        goto after_6;
    // 0x80046014: nop

    after_6:
    // 0x80046018: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8004601C: addu        $s0, $v0, $at
    ctx->r16 = ADD32(ctx->r2, ctx->r1);
    // 0x80046020: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80046024: andi        $t3, $s0, 0xFFFF
    ctx->r11 = ctx->r16 & 0XFFFF;
    // 0x80046028: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004602C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80046030: jal         0x80070990
    // 0x80046034: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    arctan2_f(rdram, ctx);
        goto after_7;
    // 0x80046034: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    after_7:
    // 0x80046038: lh          $t4, 0x1BE($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X1BE);
    // 0x8004603C: lh          $t5, 0x1C0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1C0);
    // 0x80046040: sh          $t4, 0x1C2($s1)
    MEM_H(0X1C2, ctx->r17) = ctx->r12;
    // 0x80046044: lh          $t6, 0x1C2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1C2);
    // 0x80046048: ori         $t0, $zero, 0x8001
    ctx->r8 = 0 | 0X8001;
    // 0x8004604C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80046050: subu        $a0, $s0, $t7
    ctx->r4 = SUB32(ctx->r16, ctx->r15);
    // 0x80046054: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80046058: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004605C: sh          $s0, 0x1BE($s1)
    MEM_H(0X1BE, ctx->r17) = ctx->r16;
    // 0x80046060: sh          $a1, 0x1C0($s1)
    MEM_H(0X1C0, ctx->r17) = ctx->r5;
    // 0x80046064: bne         $at, $zero, L_80046078
    if (ctx->r1 != 0) {
        // 0x80046068: sh          $t5, 0x1C4($s1)
        MEM_H(0X1C4, ctx->r17) = ctx->r13;
            goto L_80046078;
    }
    // 0x80046068: sh          $t5, 0x1C4($s1)
    MEM_H(0X1C4, ctx->r17) = ctx->r13;
    // 0x8004606C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80046070: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80046074: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80046078:
    // 0x80046078: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x8004607C: beq         $at, $zero, L_80046088
    if (ctx->r1 == 0) {
        // 0x80046080: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80046088;
    }
    // 0x80046080: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80046084: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80046088:
    // 0x80046088: lh          $t8, 0x1C4($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X1C4);
    // 0x8004608C: sra         $t1, $a0, 3
    ctx->r9 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80046090: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80046094: subu        $v1, $a1, $t9
    ctx->r3 = SUB32(ctx->r5, ctx->r25);
    // 0x80046098: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004609C: bne         $at, $zero, L_800460B0
    if (ctx->r1 != 0) {
        // 0x800460A0: negu        $t2, $t1
        ctx->r10 = SUB32(0, ctx->r9);
            goto L_800460B0;
    }
    // 0x800460A0: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x800460A4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800460A8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800460AC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800460B0:
    // 0x800460B0: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800460B4: beq         $at, $zero, L_800460C0
    if (ctx->r1 == 0) {
        // 0x800460B8: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800460C0;
    }
    // 0x800460B8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800460BC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800460C0:
    // 0x800460C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800460C4: sw          $t2, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r10;
    // 0x800460C8: sra         $t3, $v1, 3
    ctx->r11 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800460CC: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x800460D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800460D4: sw          $t4, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r12;
    // 0x800460D8: lh          $t5, 0x1A0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1A0);
    // 0x800460DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800460E0: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800460E4: subu        $a0, $s0, $t6
    ctx->r4 = SUB32(ctx->r16, ctx->r14);
    // 0x800460E8: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800460EC: bne         $at, $zero, L_800460FC
    if (ctx->r1 != 0) {
        // 0x800460F0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800460FC;
    }
    // 0x800460F0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800460F4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800460F8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800460FC:
    // 0x800460FC: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x80046100: beq         $at, $zero, L_8004610C
    if (ctx->r1 == 0) {
        // 0x80046104: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004610C;
    }
    // 0x80046104: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80046108: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_8004610C:
    // 0x8004610C: slti        $at, $a0, 0x3001
    ctx->r1 = SIGNED(ctx->r4) < 0X3001 ? 1 : 0;
    // 0x80046110: beq         $at, $zero, L_8004611C
    if (ctx->r1 == 0) {
        // 0x80046114: slti        $at, $a0, -0x3000
        ctx->r1 = SIGNED(ctx->r4) < -0X3000 ? 1 : 0;
            goto L_8004611C;
    }
    // 0x80046114: slti        $at, $a0, -0x3000
    ctx->r1 = SIGNED(ctx->r4) < -0X3000 ? 1 : 0;
    // 0x80046118: beq         $at, $zero, L_80046124
    if (ctx->r1 == 0) {
        // 0x8004611C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80046124;
    }
L_8004611C:
    // 0x8004611C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80046120: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
L_80046124:
    // 0x80046124: lwc1        $f4, 0xA8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x80046128: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004612C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80046130: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80046134: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x80046138: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x8004613C: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x80046140: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80046144: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x80046148: lb          $s0, 0x192($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X192);
    // 0x8004614C: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x80046150: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80046154: bc1f        L_80046168
    if (!c1cs) {
        // 0x80046158: addiu       $s0, $s0, -0x2
        ctx->r16 = ADD32(ctx->r16, -0X2);
            goto L_80046168;
    }
    // 0x80046158: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // 0x8004615C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80046160: nop

    // 0x80046164: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
L_80046168:
    // 0x80046168: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004616C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80046170: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x80046174: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80046178: nop

    // 0x8004617C: bc1f        L_8004618C
    if (!c1cs) {
        // 0x80046180: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004618C;
    }
    // 0x80046180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046184: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80046188: nop

L_8004618C:
    // 0x8004618C: beq         $t8, $zero, L_8004619C
    if (ctx->r24 == 0) {
        // 0x80046190: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004619C;
    }
    // 0x80046190: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046194: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80046198: nop

L_8004619C:
    // 0x8004619C: lbu         $t9, 0x1C9($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X1C9);
    // 0x800461A0: nop

    // 0x800461A4: beq         $t9, $zero, L_80046284
    if (ctx->r25 == 0) {
        // 0x800461A8: nop
    
            goto L_80046284;
    }
    // 0x800461A8: nop

    // 0x800461AC: bgez        $s0, L_800461B8
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800461B0: addiu       $a2, $sp, 0xB0
        ctx->r6 = ADD32(ctx->r29, 0XB0);
            goto L_800461B8;
    }
    // 0x800461B0: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x800461B4: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
L_800461B8:
    // 0x800461B8: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800461BC: bne         $at, $zero, L_800461C8
    if (ctx->r1 != 0) {
        // 0x800461C0: addiu       $a3, $sp, 0xA0
        ctx->r7 = ADD32(ctx->r29, 0XA0);
            goto L_800461C8;
    }
    // 0x800461C0: addiu       $a3, $sp, 0xA0
    ctx->r7 = ADD32(ctx->r29, 0XA0);
    // 0x800461C4: subu        $s0, $s0, $s2
    ctx->r16 = SUB32(ctx->r16, ctx->r18);
L_800461C8:
    // 0x800461C8: addiu       $v1, $sp, 0x90
    ctx->r3 = ADD32(ctx->r29, 0X90);
L_800461CC:
    // 0x800461CC: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x800461D0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800461D4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800461D8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800461DC: jal         0x8001BA50
    // 0x800461E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_8;
    // 0x800461E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800461E4: lh          $t1, 0x1BA($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X1BA);
    // 0x800461E8: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800461EC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800461F0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800461F4: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800461F8: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800461FC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80046200: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80046204: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80046208: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8004620C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80046210: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80046214: addiu       $t4, $sp, 0xA0
    ctx->r12 = ADD32(ctx->r29, 0XA0);
    // 0x80046218: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8004621C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80046220: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80046224: swc1        $f18, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f18.u32l;
    // 0x80046228: lh          $t2, 0x1BC($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1BC);
    // 0x8004622C: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80046230: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80046234: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80046238: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004623C: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80046240: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80046244: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x80046248: lh          $t3, 0x1BA($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X1BA);
    // 0x8004624C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80046250: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80046254: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80046258: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8004625C: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80046260: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80046264: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80046268: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004626C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80046270: bne         $s0, $s2, L_8004627C
    if (ctx->r16 != ctx->r18) {
        // 0x80046274: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_8004627C;
    }
    // 0x80046274: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80046278: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8004627C:
    // 0x8004627C: bne         $v1, $t4, L_800461CC
    if (ctx->r3 != ctx->r12) {
        // 0x80046280: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800461CC;
    }
    // 0x80046280: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80046284:
    // 0x80046284: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80046288: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x8004628C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80046290: jal         0x80022670
    // 0x80046294: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_9;
    // 0x80046294: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_9:
    // 0x80046298: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004629C: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x800462A0: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x800462A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800462A8: jal         0x80022670
    // 0x800462AC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    cubic_spline_interpolation(rdram, ctx);
        goto after_10;
    // 0x800462AC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_10:
    // 0x800462B0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800462B4: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x800462B8: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x800462BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800462C0: jal         0x80022670
    // 0x800462C4: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    cubic_spline_interpolation(rdram, ctx);
        goto after_11;
    // 0x800462C4: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_11:
    // 0x800462C8: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800462CC: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800462D0: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800462D4: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800462D8: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x800462DC: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800462E0: nop

    // 0x800462E4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800462E8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800462EC: jal         0x800CA030
    // 0x800462F0: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x800462F0: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_12:
    // 0x800462F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800462F8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800462FC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80046300: nop

    // 0x80046304: bc1t        L_80046340
    if (c1cs) {
        // 0x80046308: lw          $v0, 0xE8($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XE8);
            goto L_80046340;
    }
    // 0x80046308: lw          $v0, 0xE8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE8);
    // 0x8004630C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046310: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80046314: div.s       $f20, $f8, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80046318: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8004631C: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80046320: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80046324: nop

    // 0x80046328: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8004632C: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x80046330: mul.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80046334: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x80046338: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x8004633C: lw          $v0, 0xE8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE8);
L_80046340:
    // 0x80046340: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80046344: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80046348: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004634C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80046350: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80046354: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80046358: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004635C: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x80046360: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80046364: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80046368: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8004636C: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80046370: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80046374: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80046378: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004637C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80046380: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80046384: jal         0x80070990
    // 0x80046388: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    arctan2_f(rdram, ctx);
        goto after_13;
    // 0x80046388: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    after_13:
    // 0x8004638C: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80046390: addu        $s0, $v0, $at
    ctx->r16 = ADD32(ctx->r2, ctx->r1);
    // 0x80046394: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80046398: andi        $t5, $s0, 0xFFFF
    ctx->r13 = ctx->r16 & 0XFFFF;
    // 0x8004639C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800463A0: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800463A4: jal         0x80070990
    // 0x800463A8: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    arctan2_f(rdram, ctx);
        goto after_14;
    // 0x800463A8: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    after_14:
    // 0x800463AC: lh          $a1, 0x1A0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X1A0);
    // 0x800463B0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800463B4: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x800463B8: subu        $a0, $s0, $t6
    ctx->r4 = SUB32(ctx->r16, ctx->r14);
    // 0x800463BC: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800463C0: bne         $at, $zero, L_800463D4
    if (ctx->r1 != 0) {
        // 0x800463C4: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800463D4;
    }
    // 0x800463C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800463C8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800463CC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800463D0: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800463D4:
    // 0x800463D4: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x800463D8: beq         $at, $zero, L_800463E4
    if (ctx->r1 == 0) {
        // 0x800463DC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800463E4;
    }
    // 0x800463DC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800463E0: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800463E4:
    // 0x800463E4: lw          $t8, 0xE8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE8);
    // 0x800463E8: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x800463EC: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800463F0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800463F4: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x800463F8: subu        $v1, $t7, $t1
    ctx->r3 = SUB32(ctx->r15, ctx->r9);
    // 0x800463FC: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80046400: bne         $at, $zero, L_80046414
    if (ctx->r1 != 0) {
        // 0x80046404: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_80046414;
    }
    // 0x80046404: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80046408: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004640C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80046410: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80046414:
    // 0x80046414: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80046418: beq         $at, $zero, L_80046428
    if (ctx->r1 == 0) {
        // 0x8004641C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80046428;
    }
    // 0x8004641C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80046420: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80046424: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80046428:
    // 0x80046428: lb          $a2, 0x1D6($s1)
    ctx->r6 = MEM_B(ctx->r17, 0X1D6);
    // 0x8004642C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80046430: bne         $a2, $at, L_8004643C
    if (ctx->r6 != ctx->r1) {
        // 0x80046434: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_8004643C;
    }
    // 0x80046434: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80046438: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8004643C:
    // 0x8004643C: bne         $a3, $a2, L_8004645C
    if (ctx->r7 != ctx->r6) {
        // 0x80046440: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004645C;
    }
    // 0x80046440: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046444: lb          $t2, 0x1D4($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X1D4);
    // 0x80046448: sra         $t3, $a0, 1
    ctx->r11 = S32(SIGNED(ctx->r4) >> 1);
    // 0x8004644C: bne         $t2, $zero, L_8004645C
    if (ctx->r10 != 0) {
        // 0x80046450: subu        $t4, $a1, $t3
        ctx->r12 = SUB32(ctx->r5, ctx->r11);
            goto L_8004645C;
    }
    // 0x80046450: subu        $t4, $a1, $t3
    ctx->r12 = SUB32(ctx->r5, ctx->r11);
    // 0x80046454: lb          $a2, 0x1D6($s1)
    ctx->r6 = MEM_B(ctx->r17, 0X1D6);
    // 0x80046458: sh          $t4, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r12;
L_8004645C:
    // 0x8004645C: beq         $a2, $a3, L_800464C4
    if (ctx->r6 == ctx->r7) {
        // 0x80046460: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800464C4;
    }
    // 0x80046460: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80046464: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80046468: beq         $a2, $at, L_800464B8
    if (ctx->r6 == ctx->r1) {
        // 0x8004646C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800464B8;
    }
    // 0x8004646C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80046470: beq         $a2, $at, L_800464E0
    if (ctx->r6 == ctx->r1) {
        // 0x80046474: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800464E0;
    }
    // 0x80046474: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80046478: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004647C: beq         $a2, $at, L_80046504
    if (ctx->r6 == ctx->r1) {
        // 0x80046480: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80046504;
    }
    // 0x80046480: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80046484: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80046488: lw          $t5, -0x254C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X254C);
    // 0x8004648C: srav        $t6, $a0, $v0
    ctx->r14 = S32(SIGNED(ctx->r4) >> (ctx->r2 & 31));
    // 0x80046490: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80046494: lw          $t9, -0x2548($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2548);
    // 0x80046498: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004649C: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x800464A0: sw          $t8, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r24;
    // 0x800464A4: srav        $t7, $v1, $v0
    ctx->r15 = S32(SIGNED(ctx->r3) >> (ctx->r2 & 31));
    // 0x800464A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800464AC: addu        $t1, $t9, $t7
    ctx->r9 = ADD32(ctx->r25, ctx->r15);
    // 0x800464B0: b           L_80046534
    // 0x800464B4: sw          $t1, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r9;
        goto L_80046534;
    // 0x800464B4: sw          $t1, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r9;
L_800464B8:
    // 0x800464B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800464BC: b           L_80046534
    // 0x800464C0: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
        goto L_80046534;
    // 0x800464C0: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
L_800464C4:
    // 0x800464C4: lw          $t2, -0x254C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X254C);
    // 0x800464C8: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
    // 0x800464CC: srav        $t3, $a0, $v0
    ctx->r11 = S32(SIGNED(ctx->r4) >> (ctx->r2 & 31));
    // 0x800464D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800464D4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800464D8: b           L_80046534
    // 0x800464DC: sw          $t4, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r12;
        goto L_80046534;
    // 0x800464DC: sw          $t4, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r12;
L_800464E0:
    // 0x800464E0: lw          $t5, -0x254C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X254C);
    // 0x800464E4: addiu       $t6, $v0, 0x1F
    ctx->r14 = ADD32(ctx->r2, 0X1F);
    // 0x800464E8: srav        $t8, $a0, $t6
    ctx->r24 = S32(SIGNED(ctx->r4) >> (ctx->r14 & 31));
    // 0x800464EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800464F0: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800464F4: sw          $t9, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r25;
    // 0x800464F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800464FC: b           L_80046534
    // 0x80046500: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
        goto L_80046534;
    // 0x80046500: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
L_80046504:
    // 0x80046504: lw          $t7, -0x254C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X254C);
    // 0x80046508: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004650C: srav        $t1, $a0, $v0
    ctx->r9 = S32(SIGNED(ctx->r4) >> (ctx->r2 & 31));
    // 0x80046510: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80046514: lw          $t3, -0x2548($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2548);
    // 0x80046518: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004651C: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x80046520: sw          $t2, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r10;
    // 0x80046524: srav        $t4, $v1, $v0
    ctx->r12 = S32(SIGNED(ctx->r3) >> (ctx->r2 & 31));
    // 0x80046528: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004652C: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x80046530: sw          $t6, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r14;
L_80046534:
    // 0x80046534: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80046538: lw          $a2, 0xF0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF0);
    // 0x8004653C: jal         0x80042D60
    // 0x80046540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042D20(rdram, ctx);
        goto after_15;
    // 0x80046540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
L_80046544:
    // 0x80046544: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80046548: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8004654C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80046550: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80046554: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80046558: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8004655C: jr          $ra
    // 0x80046560: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x80046560: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void obj_loop_overridepos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037DA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80037DA4: jr          $ra
    // 0x80037DA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80037DA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void waves_visibility(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9124: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B9128: lw          $t2, -0x5970($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5970);
    // 0x800B912C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B9130: lw          $t0, -0x5998($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5998);
    // 0x800B9134: subu        $t6, $a0, $t2
    ctx->r14 = SUB32(ctx->r4, ctx->r10);
    // 0x800B9138: div         $zero, $t6, $t0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r8)));
    // 0x800B913C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B9140: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800B9144: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B9148: lw          $t4, -0x596C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X596C);
    // 0x800B914C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B9150: lw          $t1, -0x5994($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5994);
    // 0x800B9154: subu        $t7, $a2, $t4
    ctx->r15 = SUB32(ctx->r6, ctx->r12);
    // 0x800B9158: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800B915C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B9160: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B9164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B9168: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800B916C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800B9170: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B9174: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800B9178: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B917C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800B9180: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800B9184: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800B9188: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B918C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B9190: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B9194: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B9198: bne         $t0, $zero, L_800B91A4
    if (ctx->r8 != 0) {
        // 0x800B919C: nop
    
            goto L_800B91A4;
    }
    // 0x800B919C: nop

    // 0x800B91A0: break       7
    do_break(2148241824);
L_800B91A4:
    // 0x800B91A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B91A8: bne         $t0, $at, L_800B91BC
    if (ctx->r8 != ctx->r1) {
        // 0x800B91AC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B91BC;
    }
    // 0x800B91AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B91B0: bne         $t6, $at, L_800B91BC
    if (ctx->r14 != ctx->r1) {
        // 0x800B91B4: nop
    
            goto L_800B91BC;
    }
    // 0x800B91B4: nop

    // 0x800B91B8: break       6
    do_break(2148241848);
L_800B91BC:
    // 0x800B91BC: mflo        $a1
    ctx->r5 = lo;
    // 0x800B91C0: addiu       $v1, $v1, -0x5440
    ctx->r3 = ADD32(ctx->r3, -0X5440);
    // 0x800B91C4: addiu       $a0, $a0, -0x5320
    ctx->r4 = ADD32(ctx->r4, -0X5320);
    // 0x800B91C8: div         $zero, $t7, $t1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r9)));
    // 0x800B91CC: bne         $t1, $zero, L_800B91D8
    if (ctx->r9 != 0) {
        // 0x800B91D0: nop
    
            goto L_800B91D8;
    }
    // 0x800B91D0: nop

    // 0x800B91D4: break       7
    do_break(2148241876);
L_800B91D8:
    // 0x800B91D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B91DC: bne         $t1, $at, L_800B91F0
    if (ctx->r9 != ctx->r1) {
        // 0x800B91E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B91F0;
    }
    // 0x800B91E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B91E4: bne         $t7, $at, L_800B91F0
    if (ctx->r15 != ctx->r1) {
        // 0x800B91E8: nop
    
            goto L_800B91F0;
    }
    // 0x800B91E8: nop

    // 0x800B91EC: break       6
    do_break(2148241900);
L_800B91F0:
    // 0x800B91F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B91F4: sh          $t8, -0x5458($at)
    MEM_H(-0X5458, ctx->r1) = ctx->r24;
    // 0x800B91F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B91FC: sh          $t9, -0x544C($at)
    MEM_H(-0X544C, ctx->r1) = ctx->r25;
    // 0x800B9200: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B9204: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B9208: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B920C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B9210: mflo        $s7
    ctx->r23 = lo;
    // 0x800B9214: nop

    // 0x800B9218: nop

L_800B921C:
    // 0x800B921C: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x800B9220: sh          $v0, -0x30($v1)
    MEM_H(-0X30, ctx->r3) = ctx->r2;
    // 0x800B9224: sh          $v0, -0x24($v1)
    MEM_H(-0X24, ctx->r3) = ctx->r2;
    // 0x800B9228: sh          $v0, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r2;
    // 0x800B922C: bne         $v1, $a0, L_800B921C
    if (ctx->r3 != ctx->r4) {
        // 0x800B9230: sh          $v0, -0xC($v1)
        MEM_H(-0XC, ctx->r3) = ctx->r2;
            goto L_800B921C;
    }
    // 0x800B9230: sh          $v0, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = ctx->r2;
    // 0x800B9234: addiu       $t3, $t3, -0x5A78
    ctx->r11 = ADD32(ctx->r11, -0X5A78);
    // 0x800B9238: lw          $t6, 0x28($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X28);
    // 0x800B923C: nop

    // 0x800B9240: beq         $t6, $zero, L_800B9564
    if (ctx->r14 == 0) {
        // 0x800B9244: nop
    
            goto L_800B9564;
    }
    // 0x800B9244: nop

    // 0x800B9248: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B924C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800B9250: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B9254: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B9258: addiu       $s2, $s2, 0x370C
    ctx->r18 = ADD32(ctx->r18, 0X370C);
    // 0x800B925C: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x800B9260: addiu       $ra, $zero, 0x1C
    ctx->r31 = ADD32(0, 0X1C);
    // 0x800B9264: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9268: subu        $t8, $s0, $t7
    ctx->r24 = SUB32(ctx->r16, ctx->r15);
    // 0x800B926C: subu        $s0, $t8, $t2
    ctx->r16 = SUB32(ctx->r24, ctx->r10);
    // 0x800B9270: multu       $s7, $t1
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9274: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800B9278: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800B927C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B9280: sra         $t8, $t1, 1
    ctx->r24 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800B9284: addiu       $s0, $s0, -0x5458
    ctx->r16 = ADD32(ctx->r16, -0X5458);
    // 0x800B9288: mflo        $t9
    ctx->r25 = lo;
    // 0x800B928C: subu        $t6, $a2, $t9
    ctx->r14 = SUB32(ctx->r6, ctx->r25);
    // 0x800B9290: beq         $at, $zero, L_800B92A0
    if (ctx->r1 == 0) {
        // 0x800B9294: subu        $a2, $t6, $t4
        ctx->r6 = SUB32(ctx->r14, ctx->r12);
            goto L_800B92A0;
    }
    // 0x800B9294: subu        $a2, $t6, $t4
    ctx->r6 = SUB32(ctx->r14, ctx->r12);
    // 0x800B9298: b           L_800B92A4
    // 0x800B929C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_800B92A4;
    // 0x800B929C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800B92A0:
    // 0x800B92A0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800B92A4:
    // 0x800B92A4: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800B92A8: beq         $at, $zero, L_800B92B8
    if (ctx->r1 == 0) {
        // 0x800B92AC: nop
    
            goto L_800B92B8;
    }
    // 0x800B92AC: nop

    // 0x800B92B0: b           L_800B92B8
    // 0x800B92B4: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
        goto L_800B92B8;
    // 0x800B92B4: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
L_800B92B8:
    // 0x800B92B8: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B92BC: nop

    // 0x800B92C0: sra         $v0, $a0, 1
    ctx->r2 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800B92C4: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800B92C8: subu        $v1, $v1, $t9
    ctx->r3 = SUB32(ctx->r3, ctx->r25);
    // 0x800B92CC: bgez        $v1, L_800B92E0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B92D0: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_800B92E0;
    }
    // 0x800B92D0: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
L_800B92D4:
    // 0x800B92D4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B92D8: bltz        $v1, L_800B92D4
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B92DC: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800B92D4;
    }
    // 0x800B92DC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_800B92E0:
    // 0x800B92E0: subu        $s4, $s4, $t6
    ctx->r20 = SUB32(ctx->r20, ctx->r14);
    // 0x800B92E4: bgez        $s4, L_800B92F8
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800B92E8: nop
    
            goto L_800B92F8;
    }
    // 0x800B92E8: nop

L_800B92EC:
    // 0x800B92EC: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x800B92F0: bltz        $s4, L_800B92EC
    if (SIGNED(ctx->r20) < 0) {
        // 0x800B92F4: addiu       $s7, $s7, -0x1
        ctx->r23 = ADD32(ctx->r23, -0X1);
            goto L_800B92EC;
    }
    // 0x800B92F4: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
L_800B92F8:
    // 0x800B92F8: blez        $a0, L_800B9708
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B92FC: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_800B9708;
    }
    // 0x800B92FC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B9300: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800B9304: addiu       $fp, $fp, -0x5968
    ctx->r30 = ADD32(ctx->r30, -0X5968);
    // 0x800B9308: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
L_800B930C:
    // 0x800B930C: bltz        $s7, L_800B9534
    if (SIGNED(ctx->r23) < 0) {
        // 0x800B9310: sw          $v1, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r3;
            goto L_800B9534;
    }
    // 0x800B9310: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800B9314: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B9318: lw          $t7, -0x5964($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5964);
    // 0x800B931C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800B9320: slt         $at, $s7, $t7
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B9324: beq         $at, $zero, L_800B9534
    if (ctx->r1 == 0) {
        // 0x800B9328: nop
    
            goto L_800B9534;
    }
    // 0x800B9328: nop

    // 0x800B932C: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B9330: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800B9334: multu       $s7, $t8
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9338: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x800B933C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B9340: mflo        $t9
    ctx->r25 = lo;
    // 0x800B9344: addu        $t2, $t9, $s3
    ctx->r10 = ADD32(ctx->r25, ctx->r19);
    // 0x800B9348: blez        $a0, L_800B9534
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B934C: nop
    
            goto L_800B9534;
    }
    // 0x800B934C: nop

L_800B9350:
    // 0x800B9350: bltz        $s3, L_800B9508
    if (SIGNED(ctx->r19) < 0) {
        // 0x800B9354: nop
    
            goto L_800B9508;
    }
    // 0x800B9354: nop

    // 0x800B9358: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800B935C: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x800B9360: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B9364: beq         $at, $zero, L_800B9508
    if (ctx->r1 == 0) {
        // 0x800B9368: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800B9508;
    }
    // 0x800B9368: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B936C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B9370: lw          $t8, -0x5958($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5958);
    // 0x800B9374: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B9378: sllv        $t6, $t9, $s3
    ctx->r14 = S32(ctx->r25 << (ctx->r19 & 31));
    // 0x800B937C: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x800B9380: beq         $t7, $zero, L_800B9508
    if (ctx->r15 == 0) {
        // 0x800B9384: nop
    
            goto L_800B9508;
    }
    // 0x800B9384: nop

    // 0x800B9388: multu       $s6, $a0
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B938C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B9390: lw          $t9, 0x3664($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3664);
    // 0x800B9394: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x800B9398: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B939C: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x800B93A0: lw          $t6, 0x3670($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3670);
    // 0x800B93A4: addu        $t4, $t5, $s4
    ctx->r12 = ADD32(ctx->r13, ctx->r20);
    // 0x800B93A8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B93AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B93B0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B93B4: mflo        $t7
    ctx->r15 = lo;
    // 0x800B93B8: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800B93BC: sll         $t7, $s5, 1
    ctx->r15 = S32(ctx->r21 << 1);
    // 0x800B93C0: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800B93C4: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800B93C8: lh          $t9, 0x0($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X0);
    // 0x800B93CC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800B93D0: sllv        $t8, $t9, $t4
    ctx->r24 = S32(ctx->r25 << (ctx->r12 & 31));
    // 0x800B93D4: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800B93D8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800B93DC: lw          $t0, -0x5960($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5960);
    // 0x800B93E0: nop

    // 0x800B93E4: blez        $t0, L_800B9508
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B93E8: nop
    
            goto L_800B9508;
    }
    // 0x800B93E8: nop

    // 0x800B93EC: lw          $t1, 0x3668($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3668);
    // 0x800B93F0: nop

L_800B93F4:
    // 0x800B93F4: multu       $v0, $ra
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B93F8: mflo        $t9
    ctx->r25 = lo;
    // 0x800B93FC: addu        $a2, $t1, $t9
    ctx->r6 = ADD32(ctx->r9, ctx->r25);
    // 0x800B9400: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x800B9404: nop

    // 0x800B9408: bne         $t2, $t7, L_800B94F8
    if (ctx->r10 != ctx->r15) {
        // 0x800B940C: nop
    
            goto L_800B94F8;
    }
    // 0x800B940C: nop

    // 0x800B9410: multu       $a3, $s1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9414: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800B9418: sra         $t6, $t4, 3
    ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800B941C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B9420: mflo        $t8
    ctx->r24 = lo;
    // 0x800B9424: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x800B9428: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B942C: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9430: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
    // 0x800B9434: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9438: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800B943C: lh          $t8, 0x12($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X12);
    // 0x800B9440: beq         $t5, $zero, L_800B9490
    if (ctx->r13 == 0) {
        // 0x800B9444: sh          $t8, 0x4($v1)
        MEM_H(0X4, ctx->r3) = ctx->r24;
            goto L_800B9490;
    }
    // 0x800B9444: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x800B9448: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x800B944C: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x800B9450: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800B9454: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x800B9458: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x800B945C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800B9460: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x800B9464: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B9468: nop

    // 0x800B946C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B9470: bne         $at, $zero, L_800B9490
    if (ctx->r1 != 0) {
        // 0x800B9474: subu        $t6, $v0, $a0
        ctx->r14 = SUB32(ctx->r2, ctx->r4);
            goto L_800B9490;
    }
    // 0x800B9474: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
L_800B9478:
    // 0x800B9478: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800B947C: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B9480: nop

    // 0x800B9484: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B9488: beq         $at, $zero, L_800B9478
    if (ctx->r1 == 0) {
        // 0x800B948C: subu        $t6, $v0, $a0
        ctx->r14 = SUB32(ctx->r2, ctx->r4);
            goto L_800B9478;
    }
    // 0x800B948C: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
L_800B9490:
    // 0x800B9490: lh          $t9, 0x10($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X10);
    // 0x800B9494: beq         $s4, $zero, L_800B94F4
    if (ctx->r20 == 0) {
        // 0x800B9498: sh          $t9, 0x6($v1)
        MEM_H(0X6, ctx->r3) = ctx->r25;
            goto L_800B94F4;
    }
    // 0x800B9498: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
    // 0x800B949C: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x800B94A0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B94A4: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x800B94A8: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800B94AC: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B94B0: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x800B94B4: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x800B94B8: mflo        $t9
    ctx->r25 = lo;
    // 0x800B94BC: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800B94C0: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800B94C4: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x800B94C8: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x800B94CC: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800B94D0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B94D4: bne         $at, $zero, L_800B94F4
    if (ctx->r1 != 0) {
        // 0x800B94D8: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_800B94F4;
    }
    // 0x800B94D8: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
L_800B94DC:
    // 0x800B94DC: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
    // 0x800B94E0: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x800B94E4: nop

    // 0x800B94E8: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B94EC: beq         $at, $zero, L_800B94DC
    if (ctx->r1 == 0) {
        // 0x800B94F0: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_800B94DC;
    }
    // 0x800B94F0: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
L_800B94F4:
    // 0x800B94F4: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_800B94F8:
    // 0x800B94F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B94FC: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B9500: bne         $at, $zero, L_800B93F4
    if (ctx->r1 != 0) {
        // 0x800B9504: nop
    
            goto L_800B93F4;
    }
    // 0x800B9504: nop

L_800B9508:
    // 0x800B9508: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x800B950C: slti        $at, $t5, 0x9
    ctx->r1 = SIGNED(ctx->r13) < 0X9 ? 1 : 0;
    // 0x800B9510: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B9514: bne         $at, $zero, L_800B9528
    if (ctx->r1 != 0) {
        // 0x800B9518: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800B9528;
    }
    // 0x800B9518: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800B951C: addiu       $t5, $t5, -0x10
    ctx->r13 = ADD32(ctx->r13, -0X10);
    // 0x800B9520: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B9524: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_800B9528:
    // 0x800B9528: slt         $at, $s5, $a0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B952C: bne         $at, $zero, L_800B9350
    if (ctx->r1 != 0) {
        // 0x800B9530: nop
    
            goto L_800B9350;
    }
    // 0x800B9530: nop

L_800B9534:
    // 0x800B9534: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x800B9538: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800B953C: slti        $at, $s4, 0x11
    ctx->r1 = SIGNED(ctx->r20) < 0X11 ? 1 : 0;
    // 0x800B9540: bne         $at, $zero, L_800B9550
    if (ctx->r1 != 0) {
        // 0x800B9544: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800B9550;
    }
    // 0x800B9544: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800B9548: addiu       $s4, $s4, -0x20
    ctx->r20 = ADD32(ctx->r20, -0X20);
    // 0x800B954C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_800B9550:
    // 0x800B9550: slt         $at, $s6, $a0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B9554: bne         $at, $zero, L_800B930C
    if (ctx->r1 != 0) {
        // 0x800B9558: nop
    
            goto L_800B930C;
    }
    // 0x800B9558: nop

    // 0x800B955C: b           L_800B970C
    // 0x800B9560: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
        goto L_800B970C;
    // 0x800B9560: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
L_800B9564:
    // 0x800B9564: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B9568: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B956C: sra         $v0, $a0, 1
    ctx->r2 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800B9570: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x800B9574: blez        $a0, L_800B9708
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B9578: subu        $s7, $s7, $v0
        ctx->r23 = SUB32(ctx->r23, ctx->r2);
            goto L_800B9708;
    }
    // 0x800B9578: subu        $s7, $s7, $v0
    ctx->r23 = SUB32(ctx->r23, ctx->r2);
    // 0x800B957C: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800B9580: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800B9584: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B9588: addiu       $s0, $s0, -0x5458
    ctx->r16 = ADD32(ctx->r16, -0X5458);
    // 0x800B958C: addiu       $s2, $s2, 0x370C
    ctx->r18 = ADD32(ctx->r18, 0X370C);
    // 0x800B9590: addiu       $fp, $fp, -0x5968
    ctx->r30 = ADD32(ctx->r30, -0X5968);
    // 0x800B9594: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800B9598: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x800B959C: addiu       $ra, $zero, 0x1C
    ctx->r31 = ADD32(0, 0X1C);
L_800B95A0:
    // 0x800B95A0: bltz        $s7, L_800B96F8
    if (SIGNED(ctx->r23) < 0) {
        // 0x800B95A4: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800B96F8;
    }
    // 0x800B95A4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B95A8: lw          $t8, -0x5964($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5964);
    // 0x800B95AC: nop

    // 0x800B95B0: slt         $at, $s7, $t8
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B95B4: beq         $at, $zero, L_800B96F8
    if (ctx->r1 == 0) {
        // 0x800B95B8: nop
    
            goto L_800B96F8;
    }
    // 0x800B95B8: nop

    // 0x800B95BC: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800B95C0: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800B95C4: multu       $s7, $t7
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B95C8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B95CC: mflo        $t9
    ctx->r25 = lo;
    // 0x800B95D0: addu        $t2, $t9, $s3
    ctx->r10 = ADD32(ctx->r25, ctx->r19);
    // 0x800B95D4: blez        $a0, L_800B96F8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B95D8: nop
    
            goto L_800B96F8;
    }
    // 0x800B95D8: nop

L_800B95DC:
    // 0x800B95DC: bltz        $s3, L_800B96E0
    if (SIGNED(ctx->r19) < 0) {
        // 0x800B95E0: nop
    
            goto L_800B96E0;
    }
    // 0x800B95E0: nop

    // 0x800B95E4: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B95E8: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x800B95EC: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B95F0: beq         $at, $zero, L_800B96E0
    if (ctx->r1 == 0) {
        // 0x800B95F4: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_800B96E0;
    }
    // 0x800B95F4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B95F8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800B95FC: lw          $t9, -0x5958($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5958);
    // 0x800B9600: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B9604: sllv        $t8, $t6, $s3
    ctx->r24 = S32(ctx->r14 << (ctx->r19 & 31));
    // 0x800B9608: and         $t7, $t9, $t8
    ctx->r15 = ctx->r25 & ctx->r24;
    // 0x800B960C: beq         $t7, $zero, L_800B96E0
    if (ctx->r15 == 0) {
        // 0x800B9610: nop
    
            goto L_800B96E0;
    }
    // 0x800B9610: nop

    // 0x800B9614: multu       $s6, $a0
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9618: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B961C: lw          $t6, 0x3670($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3670);
    // 0x800B9620: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B9624: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B9628: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B962C: mflo        $t9
    ctx->r25 = lo;
    // 0x800B9630: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800B9634: sll         $t9, $s5, 1
    ctx->r25 = S32(ctx->r21 << 1);
    // 0x800B9638: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800B963C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800B9640: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B9644: lw          $t7, 0x3664($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3664);
    // 0x800B9648: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x800B964C: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x800B9650: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800B9654: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800B9658: lw          $t0, -0x5960($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5960);
    // 0x800B965C: nop

    // 0x800B9660: blez        $t0, L_800B96E0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B9664: nop
    
            goto L_800B96E0;
    }
    // 0x800B9664: nop

    // 0x800B9668: lw          $t1, 0x3668($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3668);
    // 0x800B966C: nop

L_800B9670:
    // 0x800B9670: multu       $v0, $ra
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9674: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9678: addu        $a2, $t1, $t7
    ctx->r6 = ADD32(ctx->r9, ctx->r15);
    // 0x800B967C: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x800B9680: nop

    // 0x800B9684: bne         $t2, $t9, L_800B96D0
    if (ctx->r10 != ctx->r25) {
        // 0x800B9688: nop
    
            goto L_800B96D0;
    }
    // 0x800B9688: nop

    // 0x800B968C: multu       $a3, $s1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9690: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800B9694: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B9698: mflo        $t8
    ctx->r24 = lo;
    // 0x800B969C: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x800B96A0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B96A4: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B96A8: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x800B96AC: lh          $t6, 0x12($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X12);
    // 0x800B96B0: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x800B96B4: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800B96B8: lh          $t7, 0x10($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X10);
    // 0x800B96BC: nop

    // 0x800B96C0: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x800B96C4: mflo        $t8
    ctx->r24 = lo;
    // 0x800B96C8: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800B96CC: nop

L_800B96D0:
    // 0x800B96D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B96D4: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B96D8: bne         $at, $zero, L_800B9670
    if (ctx->r1 != 0) {
        // 0x800B96DC: nop
    
            goto L_800B9670;
    }
    // 0x800B96DC: nop

L_800B96E0:
    // 0x800B96E0: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B96E4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800B96E8: slt         $at, $s5, $a0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B96EC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B96F0: bne         $at, $zero, L_800B95DC
    if (ctx->r1 != 0) {
        // 0x800B96F4: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_800B95DC;
    }
    // 0x800B96F4: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_800B96F8:
    // 0x800B96F8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800B96FC: slt         $at, $s6, $a0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B9700: bne         $at, $zero, L_800B95A0
    if (ctx->r1 != 0) {
        // 0x800B9704: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_800B95A0;
    }
    // 0x800B9704: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_800B9708:
    // 0x800B9708: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
L_800B970C:
    // 0x800B970C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800B9710: jal         0x800BA7A8
    // 0x800B9714: nop

    func_800BA288(rdram, ctx);
        goto after_0;
    // 0x800B9714: nop

    after_0:
    // 0x800B9718: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B971C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B9720: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9724: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B9728: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B972C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B9730: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9734: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800B9738: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800B973C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800B9740: jr          $ra
    // 0x800B9744: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800B9744: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4470: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x800D4474: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800D4478: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D447C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D4480: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800D4484: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D4488: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D448C: sw          $a3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r7;
    // 0x800D4490: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800D4494: lui         $s6, 0x800F
    ctx->r22 = S32(0X800F << 16);
    // 0x800D4498: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800D449C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800D44A0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800D44A4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800D44A8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D44AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D44B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D44B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D44B8: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x800D44BC: sw          $zero, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = 0;
    // 0x800D44C0: addiu       $s7, $s7, 0x4E50
    ctx->r23 = ADD32(ctx->r23, 0X4E50);
    // 0x800D44C4: addiu       $s6, $s6, -0x63BC
    ctx->r22 = ADD32(ctx->r22, -0X63BC);
    // 0x800D44C8: addiu       $s5, $s5, 0x4E74
    ctx->r21 = ADD32(ctx->r21, 0X4E74);
    // 0x800D44CC: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
L_800D44D0:
    // 0x800D44D0: lbu         $s0, 0x0($a3)
    ctx->r16 = MEM_BU(ctx->r7, 0X0);
    // 0x800D44D4: addiu       $s2, $a3, 0x1
    ctx->r18 = ADD32(ctx->r7, 0X1);
    // 0x800D44D8: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x800D44DC: blez        $s0, L_800D4504
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D44E0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D4504;
    }
    // 0x800D44E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800D44E4:
    // 0x800D44E4: bnel        $v1, $s0, L_800D44F8
    if (ctx->r3 != ctx->r16) {
        // 0x800D44E8: lbu         $s0, 0x0($s2)
        ctx->r16 = MEM_BU(ctx->r18, 0X0);
            goto L_800D44F8;
    }
    goto skip_0;
    // 0x800D44E8: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
    skip_0:
    // 0x800D44EC: b           L_800D4504
    // 0x800D44F0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_800D4504;
    // 0x800D44F0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800D44F4: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
L_800D44F8:
    // 0x800D44F8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D44FC: bgtz        $s0, L_800D44E4
    if (SIGNED(ctx->r16) > 0) {
        // 0x800D4500: nop
    
            goto L_800D44E4;
    }
    // 0x800D4500: nop

L_800D4504:
    // 0x800D4504: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
    // 0x800D4508: blez        $v0, L_800D453C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D450C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_800D453C;
    }
    // 0x800D450C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D4510: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D4514: jalr        $s4
    // 0x800D4518: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x800D4518: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x800D451C: beq         $v0, $zero, L_800D4534
    if (ctx->r2 == 0) {
        // 0x800D4520: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4534;
    }
    // 0x800D4520: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4524: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4528: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800D452C: b           L_800D453C
    // 0x800D4530: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
        goto L_800D453C;
    // 0x800D4530: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
L_800D4534:
    // 0x800D4534: b           L_800D4A84
    // 0x800D4538: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4538: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D453C:
    // 0x800D453C: bne         $s0, $zero, L_800D454C
    if (ctx->r16 != 0) {
        // 0x800D4540: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800D454C;
    }
    // 0x800D4540: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4544: b           L_800D4A84
    // 0x800D4548: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4548: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D454C:
    // 0x800D454C: sw          $zero, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = 0;
    // 0x800D4550: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800D4554: jal         0x800CE724
    // 0x800D4558: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x800D4558: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x800D455C: beq         $v0, $zero, L_800D459C
    if (ctx->r2 == 0) {
        // 0x800D4560: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D459C;
    }
    // 0x800D4560: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D4564:
    // 0x800D4564: subu        $t9, $s0, $s6
    ctx->r25 = SUB32(ctx->r16, ctx->r22);
    // 0x800D4568: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800D456C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D4570: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800D4574: lw          $t7, -0x63B4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X63B4);
    // 0x800D4578: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x800D457C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4580: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D4584: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800D4588: sw          $t9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r25;
    // 0x800D458C: jal         0x800CE724
    // 0x800D4590: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x800D4590: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_2:
    // 0x800D4594: bne         $v0, $zero, L_800D4564
    if (ctx->r2 != 0) {
        // 0x800D4598: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D4564;
    }
    // 0x800D4598: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D459C:
    // 0x800D459C: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x800D45A0: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x800D45A4: lw          $t8, 0xEC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XEC);
    // 0x800D45A8: bne         $v0, $t6, L_800D45F0
    if (ctx->r2 != ctx->r14) {
        // 0x800D45AC: lui         $a0, 0x800F
        ctx->r4 = S32(0X800F << 16);
            goto L_800D45F0;
    }
    // 0x800D45AC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D45B0: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x800D45B4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D45B8: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x800D45BC: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800D45C0: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x800D45C4: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800D45C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D45CC: bgez        $t8, L_800D45E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D45D0: sw          $t8, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->r24;
            goto L_800D45E8;
    }
    // 0x800D45D0: sw          $t8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r24;
    // 0x800D45D4: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x800D45D8: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x800D45DC: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
    // 0x800D45E0: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x800D45E4: sw          $t9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r25;
L_800D45E8:
    // 0x800D45E8: b           L_800D464C
    // 0x800D45EC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800D464C;
    // 0x800D45EC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800D45F0:
    // 0x800D45F0: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x800D45F4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800D45F8: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D45FC: bne         $at, $zero, L_800D464C
    if (ctx->r1 != 0) {
        // 0x800D4600: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D464C;
    }
    // 0x800D4600: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D4604: beql        $at, $zero, L_800D4650
    if (ctx->r1 == 0) {
        // 0x800D4608: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800D4650;
    }
    goto skip_1;
    // 0x800D4608: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_1:
    // 0x800D460C: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
L_800D4610:
    // 0x800D4610: slti        $at, $t8, 0x3E7
    ctx->r1 = SIGNED(ctx->r24) < 0X3E7 ? 1 : 0;
    // 0x800D4614: beql        $at, $zero, L_800D4634
    if (ctx->r1 == 0) {
        // 0x800D4618: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_800D4634;
    }
    goto skip_2;
    // 0x800D4618: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_2:
    // 0x800D461C: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D4620: mflo        $t7
    ctx->r15 = lo;
    // 0x800D4624: addu        $t6, $a1, $t7
    ctx->r14 = ADD32(ctx->r5, ctx->r15);
    // 0x800D4628: addiu       $t9, $t6, -0x30
    ctx->r25 = ADD32(ctx->r14, -0X30);
    // 0x800D462C: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x800D4630: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_800D4634:
    // 0x800D4634: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4638: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D463C: bne         $at, $zero, L_800D464C
    if (ctx->r1 != 0) {
        // 0x800D4640: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D464C;
    }
    // 0x800D4640: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D4644: bnel        $at, $zero, L_800D4610
    if (ctx->r1 != 0) {
        // 0x800D4648: lw          $t8, 0xD0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XD0);
            goto L_800D4610;
    }
    goto skip_3;
    // 0x800D4648: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    skip_3:
L_800D464C:
    // 0x800D464C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800D4650:
    // 0x800D4650: beq         $a1, $at, L_800D4664
    if (ctx->r5 == ctx->r1) {
        // 0x800D4654: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_800D4664;
    }
    // 0x800D4654: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800D4658: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
    // 0x800D465C: b           L_800D46F8
    // 0x800D4660: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800D46F8;
    // 0x800D4660: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800D4664:
    // 0x800D4664: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x800D4668: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x800D466C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4670: bne         $v0, $t7, L_800D469C
    if (ctx->r2 != ctx->r15) {
        // 0x800D4674: addiu       $t9, $t6, 0x3
        ctx->r25 = ADD32(ctx->r14, 0X3);
            goto L_800D469C;
    }
    // 0x800D4674: addiu       $t9, $t6, 0x3
    ctx->r25 = ADD32(ctx->r14, 0X3);
    // 0x800D4678: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D467C: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D4680: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x800D4684: sw          $t7, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r15;
    // 0x800D4688: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800D468C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4690: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800D4694: b           L_800D46F8
    // 0x800D4698: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800D46F8;
    // 0x800D4698: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800D469C:
    // 0x800D469C: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x800D46A0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800D46A4: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D46A8: bne         $at, $zero, L_800D46F8
    if (ctx->r1 != 0) {
        // 0x800D46AC: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D46F8;
    }
    // 0x800D46AC: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D46B0: beq         $at, $zero, L_800D46F8
    if (ctx->r1 == 0) {
        // 0x800D46B4: nop
    
            goto L_800D46F8;
    }
    // 0x800D46B4: nop

    // 0x800D46B8: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
L_800D46BC:
    // 0x800D46BC: slti        $at, $t9, 0x3E7
    ctx->r1 = SIGNED(ctx->r25) < 0X3E7 ? 1 : 0;
    // 0x800D46C0: beql        $at, $zero, L_800D46E0
    if (ctx->r1 == 0) {
        // 0x800D46C4: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_800D46E0;
    }
    goto skip_4;
    // 0x800D46C4: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_4:
    // 0x800D46C8: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D46CC: mflo        $t7
    ctx->r15 = lo;
    // 0x800D46D0: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800D46D4: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x800D46D8: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800D46DC: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_800D46E0:
    // 0x800D46E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D46E4: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D46E8: bne         $at, $zero, L_800D46F8
    if (ctx->r1 != 0) {
        // 0x800D46EC: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D46F8;
    }
    // 0x800D46EC: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D46F0: bnel        $at, $zero, L_800D46BC
    if (ctx->r1 != 0) {
        // 0x800D46F4: lw          $t9, 0xCC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XCC);
            goto L_800D46BC;
    }
    goto skip_5;
    // 0x800D46F4: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    skip_5:
L_800D46F8:
    // 0x800D46F8: jal         0x800CE724
    // 0x800D46FC: addiu       $a0, $a0, -0x63C0
    ctx->r4 = ADD32(ctx->r4, -0X63C0);
    strchr_recomp(rdram, ctx);
        goto after_3;
    // 0x800D46FC: addiu       $a0, $a0, -0x63C0
    ctx->r4 = ADD32(ctx->r4, -0X63C0);
    after_3:
    // 0x800D4700: beq         $v0, $zero, L_800D4718
    if (ctx->r2 == 0) {
        // 0x800D4704: addiu       $s0, $sp, 0xA8
        ctx->r16 = ADD32(ctx->r29, 0XA8);
            goto L_800D4718;
    }
    // 0x800D4704: addiu       $s0, $sp, 0xA8
    ctx->r16 = ADD32(ctx->r29, 0XA8);
    // 0x800D4708: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x800D470C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4710: b           L_800D471C
    // 0x800D4714: sb          $t9, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = ctx->r25;
        goto L_800D471C;
    // 0x800D4714: sb          $t9, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = ctx->r25;
L_800D4718:
    // 0x800D4718: sb          $zero, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = 0;
L_800D471C:
    // 0x800D471C: lbu         $t7, 0xDC($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XDC);
    // 0x800D4720: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x800D4724: addiu       $a2, $sp, 0xEC
    ctx->r6 = ADD32(ctx->r29, 0XEC);
    // 0x800D4728: bne         $v0, $t7, L_800D4748
    if (ctx->r2 != ctx->r15) {
        // 0x800D472C: addiu       $a3, $sp, 0x7C
        ctx->r7 = ADD32(ctx->r29, 0X7C);
            goto L_800D4748;
    }
    // 0x800D472C: addiu       $a3, $sp, 0x7C
    ctx->r7 = ADD32(ctx->r29, 0X7C);
    // 0x800D4730: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800D4734: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x800D4738: bne         $v0, $t8, L_800D4748
    if (ctx->r2 != ctx->r24) {
        // 0x800D473C: nop
    
            goto L_800D4748;
    }
    // 0x800D473C: nop

    // 0x800D4740: sb          $t6, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = ctx->r14;
    // 0x800D4744: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D4748:
    // 0x800D4748: jal         0x800D3E00
    // 0x800D474C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    static_3_800D3E00(rdram, ctx);
        goto after_4;
    // 0x800D474C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_4:
    // 0x800D4750: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800D4754: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800D4758: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800D475C: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800D4760: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800D4764: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800D4768: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800D476C: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800D4770: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800D4774: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800D4778: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800D477C: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800D4780: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x800D4784: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800D4788: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x800D478C: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800D4790: bne         $t8, $zero, L_800D47FC
    if (ctx->r24 != 0) {
        // 0x800D4794: slt         $t6, $zero, $t9
        ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_800D47FC;
    }
    // 0x800D4794: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D4798: beql        $t6, $zero, L_800D4800
    if (ctx->r14 == 0) {
        // 0x800D479C: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800D4800;
    }
    goto skip_6;
    // 0x800D479C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_6:
    // 0x800D47A0: beq         $t6, $zero, L_800D47FC
    if (ctx->r14 == 0) {
        // 0x800D47A4: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D47FC;
    }
    // 0x800D47A4: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D47A8: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D47AC:
    // 0x800D47AC: bne         $at, $zero, L_800D47BC
    if (ctx->r1 != 0) {
        // 0x800D47B0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D47BC;
    }
    // 0x800D47B0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D47B4: b           L_800D47BC
    // 0x800D47B8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D47BC;
    // 0x800D47B8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D47BC:
    // 0x800D47BC: blez        $s0, L_800D47F0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D47C0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D47F0;
    }
    // 0x800D47C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D47C4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800D47C8: jalr        $s4
    // 0x800D47CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x800D47CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x800D47D0: beq         $v0, $zero, L_800D47E8
    if (ctx->r2 == 0) {
        // 0x800D47D4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D47E8;
    }
    // 0x800D47D4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D47D8: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x800D47DC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800D47E0: b           L_800D47F0
    // 0x800D47E4: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D47F0;
    // 0x800D47E4: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D47E8:
    // 0x800D47E8: b           L_800D4A84
    // 0x800D47EC: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D47EC: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D47F0:
    // 0x800D47F0: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D47F4: bgtzl       $s1, L_800D47AC
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D47F8: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D47AC;
    }
    goto skip_7;
    // 0x800D47F8: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_7:
L_800D47FC:
    // 0x800D47FC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800D4800:
    // 0x800D4800: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D4804: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x800D4808: blezl       $t9, L_800D4840
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D480C: lw          $t9, 0xB8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB8);
            goto L_800D4840;
    }
    goto skip_8;
    // 0x800D480C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    skip_8:
    // 0x800D4810: jalr        $s4
    // 0x800D4814: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x800D4814: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_6:
    // 0x800D4818: beq         $v0, $zero, L_800D4834
    if (ctx->r2 == 0) {
        // 0x800D481C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4834;
    }
    // 0x800D481C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4820: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4824: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800D4828: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D482C: b           L_800D483C
    // 0x800D4830: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D483C;
    // 0x800D4830: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4834:
    // 0x800D4834: b           L_800D4A84
    // 0x800D4838: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4838: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D483C:
    // 0x800D483C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
L_800D4840:
    // 0x800D4840: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D4844: beql        $t6, $zero, L_800D48AC
    if (ctx->r14 == 0) {
        // 0x800D4848: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_800D48AC;
    }
    goto skip_9;
    // 0x800D4848: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    skip_9:
    // 0x800D484C: beq         $t6, $zero, L_800D48A8
    if (ctx->r14 == 0) {
        // 0x800D4850: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D48A8;
    }
    // 0x800D4850: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D4854: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D4858:
    // 0x800D4858: bne         $at, $zero, L_800D4868
    if (ctx->r1 != 0) {
        // 0x800D485C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D4868;
    }
    // 0x800D485C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D4860: b           L_800D4868
    // 0x800D4864: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D4868;
    // 0x800D4864: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D4868:
    // 0x800D4868: blez        $s0, L_800D489C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D486C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D489C;
    }
    // 0x800D486C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D4870: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D4874: jalr        $s4
    // 0x800D4878: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x800D4878: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800D487C: beq         $v0, $zero, L_800D4894
    if (ctx->r2 == 0) {
        // 0x800D4880: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4894;
    }
    // 0x800D4880: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4884: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4888: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800D488C: b           L_800D489C
    // 0x800D4890: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D489C;
    // 0x800D4890: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4894:
    // 0x800D4894: b           L_800D4A84
    // 0x800D4898: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4898: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D489C:
    // 0x800D489C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D48A0: bgtzl       $s1, L_800D4858
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D48A4: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D4858;
    }
    goto skip_10;
    // 0x800D48A4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_10:
L_800D48A8:
    // 0x800D48A8: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
L_800D48AC:
    // 0x800D48AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D48B0: lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB0);
    // 0x800D48B4: blezl       $t9, L_800D48EC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D48B8: lw          $t9, 0xC0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC0);
            goto L_800D48EC;
    }
    goto skip_11;
    // 0x800D48B8: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    skip_11:
    // 0x800D48BC: jalr        $s4
    // 0x800D48C0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x800D48C0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x800D48C4: beq         $v0, $zero, L_800D48E0
    if (ctx->r2 == 0) {
        // 0x800D48C8: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D48E0;
    }
    // 0x800D48C8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D48CC: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D48D0: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800D48D4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D48D8: b           L_800D48E8
    // 0x800D48DC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D48E8;
    // 0x800D48DC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D48E0:
    // 0x800D48E0: b           L_800D4A84
    // 0x800D48E4: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D48E4: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D48E8:
    // 0x800D48E8: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
L_800D48EC:
    // 0x800D48EC: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D48F0: beql        $t6, $zero, L_800D4958
    if (ctx->r14 == 0) {
        // 0x800D48F4: lw          $t9, 0xC4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC4);
            goto L_800D4958;
    }
    goto skip_12;
    // 0x800D48F4: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    skip_12:
    // 0x800D48F8: beq         $t6, $zero, L_800D4954
    if (ctx->r14 == 0) {
        // 0x800D48FC: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D4954;
    }
    // 0x800D48FC: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D4900: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D4904:
    // 0x800D4904: bne         $at, $zero, L_800D4914
    if (ctx->r1 != 0) {
        // 0x800D4908: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D4914;
    }
    // 0x800D4908: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D490C: b           L_800D4914
    // 0x800D4910: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D4914;
    // 0x800D4910: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D4914:
    // 0x800D4914: blez        $s0, L_800D4948
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D4918: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D4948;
    }
    // 0x800D4918: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D491C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D4920: jalr        $s4
    // 0x800D4924: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x800D4924: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x800D4928: beq         $v0, $zero, L_800D4940
    if (ctx->r2 == 0) {
        // 0x800D492C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4940;
    }
    // 0x800D492C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4930: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4934: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800D4938: b           L_800D4948
    // 0x800D493C: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D4948;
    // 0x800D493C: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4940:
    // 0x800D4940: b           L_800D4A84
    // 0x800D4944: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4944: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D4948:
    // 0x800D4948: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D494C: bgtzl       $s1, L_800D4904
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D4950: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D4904;
    }
    goto skip_13;
    // 0x800D4950: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_13:
L_800D4954:
    // 0x800D4954: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
L_800D4958:
    // 0x800D4958: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D495C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800D4960: blez        $t9, L_800D4998
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D4964: lw          $t7, 0xBC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XBC);
            goto L_800D4998;
    }
    // 0x800D4964: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800D4968: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800D496C: jalr        $s4
    // 0x800D4970: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x800D4970: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_10:
    // 0x800D4974: beq         $v0, $zero, L_800D4990
    if (ctx->r2 == 0) {
        // 0x800D4978: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4990;
    }
    // 0x800D4978: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D497C: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4980: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800D4984: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800D4988: b           L_800D4998
    // 0x800D498C: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
        goto L_800D4998;
    // 0x800D498C: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
L_800D4990:
    // 0x800D4990: b           L_800D4A84
    // 0x800D4994: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4994: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D4998:
    // 0x800D4998: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800D499C: slt         $t8, $zero, $t9
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D49A0: beql        $t8, $zero, L_800D4A08
    if (ctx->r24 == 0) {
        // 0x800D49A4: lw          $t9, 0xD8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD8);
            goto L_800D4A08;
    }
    goto skip_14;
    // 0x800D49A4: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    skip_14:
    // 0x800D49A8: beq         $t8, $zero, L_800D4A04
    if (ctx->r24 == 0) {
        // 0x800D49AC: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D4A04;
    }
    // 0x800D49AC: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D49B0: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D49B4:
    // 0x800D49B4: bne         $at, $zero, L_800D49C4
    if (ctx->r1 != 0) {
        // 0x800D49B8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D49C4;
    }
    // 0x800D49B8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D49BC: b           L_800D49C4
    // 0x800D49C0: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D49C4;
    // 0x800D49C0: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D49C4:
    // 0x800D49C4: blez        $s0, L_800D49F8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D49C8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D49F8;
    }
    // 0x800D49C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D49CC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D49D0: jalr        $s4
    // 0x800D49D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x800D49D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x800D49D8: beq         $v0, $zero, L_800D49F0
    if (ctx->r2 == 0) {
        // 0x800D49DC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D49F0;
    }
    // 0x800D49DC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D49E0: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D49E4: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800D49E8: b           L_800D49F8
    // 0x800D49EC: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
        goto L_800D49F8;
    // 0x800D49EC: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
L_800D49F0:
    // 0x800D49F0: b           L_800D4A84
    // 0x800D49F4: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D49F4: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D49F8:
    // 0x800D49F8: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D49FC: bgtzl       $s1, L_800D49B4
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D4A00: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D49B4;
    }
    goto skip_15;
    // 0x800D4A00: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_15:
L_800D4A04:
    // 0x800D4A04: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
L_800D4A08:
    // 0x800D4A08: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x800D4A0C: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x800D4A10: beq         $t8, $zero, L_800D4A7C
    if (ctx->r24 == 0) {
        // 0x800D4A14: slt         $t7, $zero, $t6
        ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_800D4A7C;
    }
    // 0x800D4A14: slt         $t7, $zero, $t6
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D4A18: beq         $t7, $zero, L_800D4A7C
    if (ctx->r15 == 0) {
        // 0x800D4A1C: nop
    
            goto L_800D4A7C;
    }
    // 0x800D4A1C: nop

    // 0x800D4A20: beq         $t7, $zero, L_800D4A7C
    if (ctx->r15 == 0) {
        // 0x800D4A24: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_800D4A7C;
    }
    // 0x800D4A24: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800D4A28: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D4A2C:
    // 0x800D4A2C: bne         $at, $zero, L_800D4A3C
    if (ctx->r1 != 0) {
        // 0x800D4A30: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D4A3C;
    }
    // 0x800D4A30: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D4A34: b           L_800D4A3C
    // 0x800D4A38: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D4A3C;
    // 0x800D4A38: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D4A3C:
    // 0x800D4A3C: blez        $s0, L_800D4A70
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D4A40: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D4A70;
    }
    // 0x800D4A40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D4A44: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800D4A48: jalr        $s4
    // 0x800D4A4C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_12;
    // 0x800D4A4C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x800D4A50: beq         $v0, $zero, L_800D4A68
    if (ctx->r2 == 0) {
        // 0x800D4A54: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4A68;
    }
    // 0x800D4A54: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4A58: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4A5C: addu        $t8, $t9, $s0
    ctx->r24 = ADD32(ctx->r25, ctx->r16);
    // 0x800D4A60: b           L_800D4A70
    // 0x800D4A64: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D4A70;
    // 0x800D4A64: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4A68:
    // 0x800D4A68: b           L_800D4A84
    // 0x800D4A6C: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4A84;
    // 0x800D4A6C: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D4A70:
    // 0x800D4A70: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D4A74: bgtzl       $s1, L_800D4A2C
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D4A78: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D4A2C;
    }
    goto skip_16;
    // 0x800D4A78: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_16:
L_800D4A7C:
    // 0x800D4A7C: b           L_800D44D0
    // 0x800D4A80: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
        goto L_800D44D0;
    // 0x800D4A80: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
L_800D4A84:
    // 0x800D4A84: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800D4A88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4A8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4A90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D4A94: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D4A98: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D4A9C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4AA0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D4AA4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800D4AA8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800D4AAC: jr          $ra
    // 0x800D4AB0: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x800D4AB0: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_80084854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C8C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80084C90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084C94: addiu       $a1, $a1, 0x6FA0
    ctx->r5 = ADD32(ctx->r5, 0X6FA0);
    // 0x80084C98: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80084C9C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80084CA0: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80084CA4: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80084CA8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80084CAC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80084CB0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80084CB4: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80084CB8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80084CBC: lw          $s3, 0x3C($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X3C);
    // 0x80084CC0: slti        $at, $t6, 0x30
    ctx->r1 = SIGNED(ctx->r14) < 0X30 ? 1 : 0;
    // 0x80084CC4: bne         $at, $zero, L_80084CE0
    if (ctx->r1 != 0) {
        // 0x80084CC8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80084CE0;
    }
    // 0x80084CC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80084CCC: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x80084CD0: nop

    // 0x80084CD4: slti        $at, $t7, 0x3A
    ctx->r1 = SIGNED(ctx->r15) < 0X3A ? 1 : 0;
    // 0x80084CD8: bne         $at, $zero, L_80084D0C
    if (ctx->r1 != 0) {
        // 0x80084CDC: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80084D0C;
    }
    // 0x80084CDC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_80084CE0:
    // 0x80084CE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80084CE4: addu        $t8, $v1, $s1
    ctx->r24 = ADD32(ctx->r3, ctx->r17);
    // 0x80084CE8: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x80084CEC: nop

    // 0x80084CF0: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x80084CF4: bne         $at, $zero, L_80084CE0
    if (ctx->r1 != 0) {
        // 0x80084CF8: nop
    
            goto L_80084CE0;
    }
    // 0x80084CF8: nop

    // 0x80084CFC: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x80084D00: beq         $at, $zero, L_80084CE0
    if (ctx->r1 == 0) {
        // 0x80084D04: nop
    
            goto L_80084CE0;
    }
    // 0x80084D04: nop

    // 0x80084D08: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_80084D0C:
    // 0x80084D0C: div         $zero, $s3, $a0
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r4)));
    // 0x80084D10: addu        $t0, $v1, $s1
    ctx->r8 = ADD32(ctx->r3, ctx->r17);
    // 0x80084D14: bne         $a0, $zero, L_80084D20
    if (ctx->r4 != 0) {
        // 0x80084D18: nop
    
            goto L_80084D20;
    }
    // 0x80084D18: nop

    // 0x80084D1C: break       7
    do_break(2148027676);
L_80084D20:
    // 0x80084D20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80084D24: bne         $a0, $at, L_80084D38
    if (ctx->r4 != ctx->r1) {
        // 0x80084D28: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80084D38;
    }
    // 0x80084D28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80084D2C: bne         $s3, $at, L_80084D38
    if (ctx->r19 != ctx->r1) {
        // 0x80084D30: nop
    
            goto L_80084D38;
    }
    // 0x80084D30: nop

    // 0x80084D34: break       6
    do_break(2148027700);
L_80084D38:
    // 0x80084D38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80084D3C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80084D40: addiu       $s2, $s2, 0x693C
    ctx->r18 = ADD32(ctx->r18, 0X693C);
    // 0x80084D44: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80084D48: mflo        $v0
    ctx->r2 = lo;
    // 0x80084D4C: addiu       $t9, $v0, 0x30
    ctx->r25 = ADD32(ctx->r2, 0X30);
    // 0x80084D50: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x80084D54: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80084D58: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80084D5C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084D60: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80084D64: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80084D68: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x80084D6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084D70: mflo        $t1
    ctx->r9 = lo;
    // 0x80084D74: subu        $s3, $s3, $t1
    ctx->r19 = SUB32(ctx->r19, ctx->r9);
    // 0x80084D78: addiu       $t2, $s3, 0x30
    ctx->r10 = ADD32(ctx->r19, 0X30);
    // 0x80084D7C: sb          $t2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r10;
    // 0x80084D80: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80084D84: lw          $s3, 0x695C($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X695C);
    // 0x80084D88: nop

    // 0x80084D8C: sll         $t5, $s3, 3
    ctx->r13 = S32(ctx->r19 << 3);
    // 0x80084D90: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x80084D94: bne         $at, $zero, L_80084DA4
    if (ctx->r1 != 0) {
        // 0x80084D98: or          $s3, $t5, $zero
        ctx->r19 = ctx->r13 | 0;
            goto L_80084DA4;
    }
    // 0x80084D98: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x80084D9C: addiu       $t6, $zero, 0x1FF
    ctx->r14 = ADD32(0, 0X1FF);
    // 0x80084DA0: subu        $s3, $t6, $t5
    ctx->r19 = SUB32(ctx->r14, ctx->r13);
L_80084DA4:
    // 0x80084DA4: lw          $t7, 0x48($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X48);
    // 0x80084DA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084DAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80084DB0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80084DB4: lw          $t9, 0x6F90($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6F90);
    // 0x80084DB8: jal         0x8006816C
    // 0x80084DBC: sw          $t9, -0x38($at)
    MEM_W(-0X38, ctx->r1) = ctx->r25;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x80084DBC: sw          $t9, -0x38($at)
    MEM_W(-0X38, ctx->r1) = ctx->r25;
    after_0:
    // 0x80084DC0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80084DC4: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x80084DC8: lui         $s1, 0xFFC0
    ctx->r17 = S32(0XFFC0 << 16);
    // 0x80084DCC: bne         $t0, $zero, L_80084DDC
    if (ctx->r8 != 0) {
        // 0x80084DD0: ori         $s1, $s1, 0x40FF
        ctx->r17 = ctx->r17 | 0X40FF;
            goto L_80084DDC;
    }
    // 0x80084DD0: ori         $s1, $s1, 0x40FF
    ctx->r17 = ctx->r17 | 0X40FF;
    // 0x80084DD4: b           L_80084DE0
    // 0x80084DD8: addiu       $s0, $zero, 0x65
    ctx->r16 = ADD32(0, 0X65);
        goto L_80084DE0;
    // 0x80084DD8: addiu       $s0, $zero, 0x65
    ctx->r16 = ADD32(0, 0X65);
L_80084DDC:
    // 0x80084DDC: addiu       $s0, $zero, 0x71
    ctx->r16 = ADD32(0, 0X71);
L_80084DE0:
    // 0x80084DE0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80084DE4: lw          $t5, 0x6C00($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6C00);
    // 0x80084DE8: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x80084DEC: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x80084DF0: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80084DF4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80084DF8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80084DFC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80084E00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80084E04: subu        $a2, $t1, $s0
    ctx->r6 = SUB32(ctx->r9, ctx->r16);
    // 0x80084E08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084E0C: addiu       $a1, $zero, -0x48
    ctx->r5 = ADD32(0, -0X48);
    // 0x80084E10: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x80084E14: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80084E18: jal         0x800809D0
    // 0x80084E1C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    func_80080580(rdram, ctx);
        goto after_1;
    // 0x80084E1C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_1:
    // 0x80084E20: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80084E24: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x80084E28: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80084E2C: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x80084E30: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80084E34: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80084E38: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80084E3C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80084E40: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80084E44: subu        $a2, $t6, $s0
    ctx->r6 = SUB32(ctx->r14, ctx->r16);
    // 0x80084E48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084E4C: addiu       $a1, $zero, -0x48
    ctx->r5 = ADD32(0, -0X48);
    // 0x80084E50: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x80084E54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80084E58: jal         0x800809D0
    // 0x80084E5C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_80080580(rdram, ctx);
        goto after_2;
    // 0x80084E5C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_2:
    // 0x80084E60: jal         0x80081018
    // 0x80084E64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80080BC8(rdram, ctx);
        goto after_3;
    // 0x80084E64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80084E68: jal         0x800C59F4
    // 0x80084E6C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_4;
    // 0x80084E6C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_4:
    // 0x80084E70: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80084E74: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80084E78: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80084E7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084E80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084E84: jal         0x800C551C
    // 0x80084E88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_5;
    // 0x80084E88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80084E8C: addiu       $t3, $zero, 0x7B
    ctx->r11 = ADD32(0, 0X7B);
    // 0x80084E90: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80084E94: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80084E98: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x80084E9C: addiu       $a2, $zero, 0x75
    ctx->r6 = ADD32(0, 0X75);
    // 0x80084EA0: jal         0x800C543C
    // 0x80084EA4: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_6;
    // 0x80084EA4: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    after_6:
    // 0x80084EA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084EB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084EB4: jal         0x800C60B8
    // 0x80084EB8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_7;
    // 0x80084EB8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_7:
    // 0x80084EBC: addiu       $t2, $zero, 0xA3
    ctx->r10 = ADD32(0, 0XA3);
    // 0x80084EC0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80084EC4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80084EC8: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x80084ECC: addiu       $a2, $zero, 0x9D
    ctx->r6 = ADD32(0, 0X9D);
    // 0x80084ED0: jal         0x800C543C
    // 0x80084ED4: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_8;
    // 0x80084ED4: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    after_8:
    // 0x80084ED8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084EE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084EE4: jal         0x800C60B8
    // 0x80084EE8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_9;
    // 0x80084EE8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_9:
    // 0x80084EEC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084EF0: lw          $a2, 0x40($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X40);
    // 0x80084EF4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80084EF8: addiu       $s0, $s0, 0x9AC
    ctx->r16 = ADD32(ctx->r16, 0X9AC);
    // 0x80084EFC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80084F00: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80084F04: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80084F08: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80084F0C: sra         $t4, $a2, 1
    ctx->r12 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80084F10: addiu       $a2, $t4, 0x60
    ctx->r6 = ADD32(ctx->r12, 0X60);
    // 0x80084F14: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80084F18: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80084F1C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80084F20: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80084F24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80084F28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084F2C: jal         0x80078F08
    // 0x80084F30: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    texrect_draw(rdram, ctx);
        goto after_10;
    // 0x80084F30: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    after_10:
    // 0x80084F34: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084F38: lw          $a2, 0x44($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X44);
    // 0x80084F3C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80084F40: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80084F44: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80084F48: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80084F4C: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80084F50: addiu       $a2, $t9, 0x60
    ctx->r6 = ADD32(ctx->r25, 0X60);
    // 0x80084F54: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80084F58: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80084F5C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80084F60: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80084F64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084F68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80084F6C: jal         0x80078F08
    // 0x80084F70: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    texrect_draw(rdram, ctx);
        goto after_11;
    // 0x80084F70: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    after_11:
    // 0x80084F74: jal         0x8007B820
    // 0x80084F78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rendermode_reset(rdram, ctx);
        goto after_12;
    // 0x80084F78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x80084F7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084F84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084F88: jal         0x800C492C
    // 0x80084F8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_13;
    // 0x80084F8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x80084F90: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80084F94: lw          $t4, 0x6980($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6980);
    // 0x80084F98: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80084F9C: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x80084FA0: beq         $at, $zero, L_80084FB8
    if (ctx->r1 == 0) {
        // 0x80084FA4: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_80084FB8;
    }
    // 0x80084FA4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80084FA8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80084FAC: lh          $s1, 0x7206($s1)
    ctx->r17 = MEM_H(ctx->r17, 0X7206);
    // 0x80084FB0: b           L_80084FEC
    // 0x80084FB4: nop

        goto L_80084FEC;
    // 0x80084FB4: nop

L_80084FB8:
    // 0x80084FB8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80084FBC: lh          $v0, 0x7206($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7206);
    // 0x80084FC0: nop

    // 0x80084FC4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80084FC8: beq         $at, $zero, L_80084FDC
    if (ctx->r1 == 0) {
        // 0x80084FCC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80084FDC;
    }
    // 0x80084FCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80084FD0: b           L_80084FEC
    // 0x80084FD4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_80084FEC;
    // 0x80084FD4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80084FD8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80084FDC:
    // 0x80084FDC: bne         $v0, $at, L_80084FEC
    if (ctx->r2 != ctx->r1) {
        // 0x80084FE0: addiu       $s1, $zero, 0x3
        ctx->r17 = ADD32(0, 0X3);
            goto L_80084FEC;
    }
    // 0x80084FE0: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80084FE4: b           L_80084FEC
    // 0x80084FE8: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
        goto L_80084FEC;
    // 0x80084FE8: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_80084FEC:
    // 0x80084FEC: lw          $t5, -0x38($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X38);
    // 0x80084FF0: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80084FF4: beq         $t5, $zero, L_80085090
    if (ctx->r13 == 0) {
        // 0x80084FF8: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80085090;
    }
    // 0x80084FF8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80084FFC: addiu       $t7, $t7, -0x44
    ctx->r15 = ADD32(ctx->r15, -0X44);
    // 0x80085000: sll         $t8, $s1, 4
    ctx->r24 = S32(ctx->r17 << 4);
    // 0x80085004: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80085008: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8008500C: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
L_80085010:
    // 0x80085010: lbu         $a0, 0x9($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9);
    // 0x80085014: jal         0x800C484C
    // 0x80085018: nop

    set_text_font(rdram, ctx);
        goto after_14;
    // 0x80085018: nop

    after_14:
    // 0x8008501C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80085020: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80085024: bne         $s0, $t0, L_80085048
    if (ctx->r16 != ctx->r8) {
        // 0x80085028: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80085048;
    }
    // 0x80085028: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008502C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80085030: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80085034: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80085038: jal         0x800C48E4
    // 0x8008503C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x8008503C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_15:
    // 0x80085040: b           L_80085068
    // 0x80085044: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
        goto L_80085068;
    // 0x80085044: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
L_80085048:
    // 0x80085048: lbu         $t3, 0x8($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X8);
    // 0x8008504C: lbu         $a0, 0x4($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4);
    // 0x80085050: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80085054: lbu         $a2, 0x6($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X6);
    // 0x80085058: lbu         $a3, 0x7($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X7);
    // 0x8008505C: jal         0x800C48E4
    // 0x80085060: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    set_text_colour(rdram, ctx);
        goto after_16;
    // 0x80085060: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_16:
    // 0x80085064: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
L_80085068:
    // 0x80085068: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8008506C: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x80085070: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x80085074: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80085078: jal         0x800C49A0
    // 0x8008507C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    draw_text(rdram, ctx);
        goto after_17;
    // 0x8008507C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_17:
    // 0x80085080: lw          $t4, 0x1C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C);
    // 0x80085084: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80085088: bne         $t4, $zero, L_80085010
    if (ctx->r12 != 0) {
        // 0x8008508C: nop
    
            goto L_80085010;
    }
    // 0x8008508C: nop

L_80085090:
    // 0x80085090: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80085094: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80085098: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8008509C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800850A0: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800850A4: jr          $ra
    // 0x800850A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800850A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void __vsPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AAAC: lbu         $t7, 0x31($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X31);
    // 0x8000AAB0: lw          $t6, 0x60($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X60);
    // 0x8000AAB4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000AAB8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000AABC: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x8000AAC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000AAC4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000AAC8: lbu         $t0, 0x7($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X7);
    // 0x8000AACC: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x8000AAD0: nop

    // 0x8000AAD4: addu        $v1, $t0, $t2
    ctx->r3 = ADD32(ctx->r8, ctx->r10);
    // 0x8000AAD8: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x8000AADC: bgtz        $v1, L_8000AAEC
    if (SIGNED(ctx->r3) > 0) {
        // 0x8000AAE0: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_8000AAEC;
    }
    // 0x8000AAE0: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    // 0x8000AAE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000AAE8: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_8000AAEC:
    // 0x8000AAEC: bne         $at, $zero, L_8000AAF8
    if (ctx->r1 != 0) {
        // 0x8000AAF0: nop
    
            goto L_8000AAF8;
    }
    // 0x8000AAF0: nop

    // 0x8000AAF4: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_8000AAF8:
    // 0x8000AAF8: jr          $ra
    // 0x8000AAFC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x8000AAFC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void mtx_get_modelmtx_s16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066444: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066448: jr          $ra
    // 0x8006644C: addiu       $v0, $v0, 0x1620
    ctx->r2 = ADD32(ctx->r2, 0X1620);
    return;
    // 0x8006644C: addiu       $v0, $v0, 0x1620
    ctx->r2 = ADD32(ctx->r2, 0X1620);
;}
RECOMP_FUNC void render_level_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029698: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8002969C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800296A0: lw          $t6, -0x3178($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3178);
    // 0x800296A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800296A8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800296AC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800296B0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800296B4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800296B8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800296BC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800296C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800296C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800296C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800296CC: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800296D0: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800296D4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800296D8: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800296DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800296E0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800296E4: beq         $a1, $zero, L_80029710
    if (ctx->r5 == 0) {
        // 0x800296E8: sw          $t9, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r25;
            goto L_80029710;
    }
    // 0x800296E8: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x800296EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800296F0: lw          $t4, -0x26FC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X26FC);
    // 0x800296F4: nop

    // 0x800296F8: beq         $t4, $zero, L_80029710
    if (ctx->r12 == 0) {
        // 0x800296FC: nop
    
            goto L_80029710;
    }
    // 0x800296FC: nop

    // 0x80029700: jal         0x800B9748
    // 0x80029704: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    waves_block_hq(rdram, ctx);
        goto after_0;
    // 0x80029704: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x80029708: b           L_80029714
    // 0x8002970C: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
        goto L_80029714;
    // 0x8002970C: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
L_80029710:
    // 0x80029710: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_80029714:
    // 0x80029714: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x80029718: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x8002971C: beq         $t5, $zero, L_8002973C
    if (ctx->r13 == 0) {
        // 0x80029720: lui         $fp, 0x8000
        ctx->r30 = S32(0X8000 << 16);
            goto L_8002973C;
    }
    // 0x80029720: lui         $fp, 0x8000
    ctx->r30 = S32(0X8000 << 16);
    // 0x80029724: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x80029728: nop

    // 0x8002972C: lh          $t7, 0x20($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X20);
    // 0x80029730: lbu         $v0, 0x40($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X40);
    // 0x80029734: b           L_80029748
    // 0x80029738: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
        goto L_80029748;
    // 0x80029738: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
L_8002973C:
    // 0x8002973C: lbu         $t3, 0x40($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X40);
    // 0x80029740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029744: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
L_80029748:
    // 0x80029748: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8002974C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80029750: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80029754: beq         $at, $zero, L_80029B08
    if (ctx->r1 == 0) {
        // 0x80029758: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_80029B08;
    }
    // 0x80029758: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8002975C: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80029760: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80029764: addiu       $s2, $s2, -0x49E0
    ctx->r18 = ADD32(ctx->r18, -0X49E0);
    // 0x80029768: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
L_8002976C:
    // 0x8002976C: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80029770: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80029774: lw          $t5, 0xC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC);
    // 0x80029778: nop

    // 0x8002977C: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    // 0x80029780: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x80029784: nop

    // 0x80029788: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8002978C: bne         $v0, $zero, L_80029AF8
    if (ctx->r2 != 0) {
        // 0x80029790: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_80029AF8;
    }
    // 0x80029790: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80029794: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80029798: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8002979C: bne         $v0, $at, L_800297AC
    if (ctx->r2 != ctx->r1) {
        // 0x800297A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800297AC;
    }
    // 0x800297A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800297A4: b           L_800297D4
    // 0x800297A8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
        goto L_800297D4;
    // 0x800297A8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_800297AC:
    // 0x800297AC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800297B0: lw          $t6, -0x3178($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3178);
    // 0x800297B4: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800297B8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800297BC: nop

    // 0x800297C0: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x800297C4: lw          $s5, 0x0($t3)
    ctx->r21 = MEM_W(ctx->r11, 0X0);
    // 0x800297C8: nop

    // 0x800297CC: lh          $a2, 0x6($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X6);
    // 0x800297D0: nop

L_800297D4:
    // 0x800297D4: ori         $t4, $s1, 0xA
    ctx->r12 = ctx->r17 | 0XA;
    // 0x800297D8: andi        $t9, $t4, 0x10
    ctx->r25 = ctx->r12 & 0X10;
    // 0x800297DC: bne         $t9, $zero, L_800297FC
    if (ctx->r25 != 0) {
        // 0x800297E0: or          $s1, $t4, $zero
        ctx->r17 = ctx->r12 | 0;
            goto L_800297FC;
    }
    // 0x800297E0: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800297E4: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800297E8: bne         $t5, $zero, L_800297FC
    if (ctx->r13 != 0) {
        // 0x800297EC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800297FC;
    }
    // 0x800297EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800297F0: lw          $t6, -0x4984($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4984);
    // 0x800297F4: nop

    // 0x800297F8: or          $s1, $t4, $t6
    ctx->r17 = ctx->r12 | ctx->r14;
L_800297FC:
    // 0x800297FC: andi        $t7, $a2, 0x4
    ctx->r15 = ctx->r6 & 0X4;
    // 0x80029800: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x80029804: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80029808: bne         $t7, $zero, L_80029814
    if (ctx->r15 != 0) {
        // 0x8002980C: andi        $t8, $s1, 0x2000
        ctx->r24 = ctx->r17 & 0X2000;
            goto L_80029814;
    }
    // 0x8002980C: andi        $t8, $s1, 0x2000
    ctx->r24 = ctx->r17 & 0X2000;
    // 0x80029810: beq         $t8, $zero, L_80029820
    if (ctx->r24 == 0) {
        // 0x80029814: andi        $t3, $s1, 0x800
        ctx->r11 = ctx->r17 & 0X800;
            goto L_80029820;
    }
L_80029814:
    // 0x80029814: andi        $t3, $s1, 0x800
    ctx->r11 = ctx->r17 & 0X800;
    // 0x80029818: beq         $t3, $zero, L_80029824
    if (ctx->r11 == 0) {
        // 0x8002981C: nop
    
            goto L_80029824;
    }
    // 0x8002981C: nop

L_80029820:
    // 0x80029820: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80029824:
    // 0x80029824: beq         $t4, $zero, L_80029838
    if (ctx->r12 == 0) {
        // 0x80029828: andi        $t6, $s1, 0x2000
        ctx->r14 = ctx->r17 & 0X2000;
            goto L_80029838;
    }
    // 0x80029828: andi        $t6, $s1, 0x2000
    ctx->r14 = ctx->r17 & 0X2000;
    // 0x8002982C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80029830: andi        $t9, $a0, 0x1
    ctx->r25 = ctx->r4 & 0X1;
    // 0x80029834: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_80029838:
    // 0x80029838: beq         $t5, $zero, L_8002984C
    if (ctx->r13 == 0) {
        // 0x8002983C: nop
    
            goto L_8002984C;
    }
    // 0x8002983C: nop

    // 0x80029840: beq         $t6, $zero, L_8002984C
    if (ctx->r14 == 0) {
        // 0x80029844: nop
    
            goto L_8002984C;
    }
    // 0x80029844: nop

    // 0x80029848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8002984C:
    // 0x8002984C: beq         $a0, $zero, L_80029AFC
    if (ctx->r4 == 0) {
        // 0x80029850: lw          $t7, 0x70($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X70);
            goto L_80029AFC;
    }
    // 0x80029850: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80029854: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
    // 0x80029858: lw          $t3, 0xAC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XAC);
    // 0x8002985C: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x80029860: lh          $t7, 0xE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XE);
    // 0x80029864: lh          $t8, 0x10($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X10);
    // 0x80029868: lbu         $a3, 0x7($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X7);
    // 0x8002986C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80029870: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80029874: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80029878: sra         $a0, $s1, 28
    ctx->r4 = S32(SIGNED(ctx->r17) >> 28);
    // 0x8002987C: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80029880: subu        $s3, $t7, $v0
    ctx->r19 = SUB32(ctx->r15, ctx->r2);
    // 0x80029884: subu        $s4, $t8, $v1
    ctx->r20 = SUB32(ctx->r24, ctx->r3);
    // 0x80029888: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8002988C: andi        $t8, $a0, 0x7
    ctx->r24 = ctx->r4 & 0X7;
    // 0x80029890: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80029894: sll         $t7, $a3, 14
    ctx->r15 = S32(ctx->r7 << 14);
    // 0x80029898: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8002989C: addu        $s6, $t4, $t9
    ctx->r22 = ADD32(ctx->r12, ctx->r25);
    // 0x800298A0: beq         $t8, $zero, L_80029904
    if (ctx->r24 == 0) {
        // 0x800298A4: addu        $s7, $t5, $t6
        ctx->r23 = ADD32(ctx->r13, ctx->r14);
            goto L_80029904;
    }
    // 0x800298A4: addu        $s7, $t5, $t6
    ctx->r23 = ADD32(ctx->r13, ctx->r14);
    // 0x800298A8: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800298AC: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800298B0: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800298B4: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800298B8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800298BC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800298C0: lw          $t3, -0x3174($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3174);
    // 0x800298C4: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x800298C8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800298CC: lw          $v0, 0x70($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X70);
    // 0x800298D0: nop

    // 0x800298D4: lbu         $t9, 0x10($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X10);
    // 0x800298D8: lbu         $t8, 0x13($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X13);
    // 0x800298DC: sll         $t3, $t9, 24
    ctx->r11 = S32(ctx->r25 << 24);
    // 0x800298E0: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x800298E4: or          $t5, $t8, $t3
    ctx->r13 = ctx->r24 | ctx->r11;
    // 0x800298E8: lbu         $t3, 0x12($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X12);
    // 0x800298EC: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800298F0: or          $t9, $t5, $t4
    ctx->r25 = ctx->r13 | ctx->r12;
    // 0x800298F4: sll         $t6, $t3, 8
    ctx->r14 = S32(ctx->r11 << 8);
    // 0x800298F8: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800298FC: b           L_80029920
    // 0x80029900: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_80029920;
    // 0x80029900: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_80029904:
    // 0x80029904: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029908: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x8002990C: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80029910: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80029914: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    // 0x80029918: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8002991C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_80029920:
    // 0x80029920: sll         $t3, $s1, 13
    ctx->r11 = S32(ctx->r17 << 13);
    // 0x80029924: bgez        $t3, L_80029A40
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80029928: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80029A40;
    }
    // 0x80029928: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002992C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80029930: lw          $t9, -0x3174($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3174);
    // 0x80029934: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029938: lw          $t6, 0xAC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XAC);
    // 0x8002993C: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80029940: lw          $t0, 0x8($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X8);
    // 0x80029944: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80029948: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x8002994C: sll         $t4, $v0, 24
    ctx->r12 = S32(ctx->r2 << 24);
    // 0x80029950: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80029954: or          $t3, $t4, $t8
    ctx->r11 = ctx->r12 | ctx->r24;
    // 0x80029958: sll         $t9, $v0, 8
    ctx->r25 = S32(ctx->r2 << 8);
    // 0x8002995C: or          $t6, $t3, $t9
    ctx->r14 = ctx->r11 | ctx->r25;
    // 0x80029960: or          $t7, $t6, $v0
    ctx->r15 = ctx->r14 | ctx->r2;
    // 0x80029964: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80029968: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8002996C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80029970: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80029974: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x80029978: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002997C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80029980: jal         0x8007BEAC
    // 0x80029984: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    material_set_blinking_lights(rdram, ctx);
        goto after_1;
    // 0x80029984: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x80029988: addu        $v1, $s6, $fp
    ctx->r3 = ADD32(ctx->r22, ctx->r30);
    // 0x8002998C: addiu       $t4, $s3, -0x1
    ctx->r12 = ADD32(ctx->r19, -0X1);
    // 0x80029990: sll         $t8, $t4, 3
    ctx->r24 = S32(ctx->r12 << 3);
    // 0x80029994: andi        $t3, $v1, 0x6
    ctx->r11 = ctx->r3 & 0X6;
    // 0x80029998: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x8002999C: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800299A0: sll         $t4, $s3, 3
    ctx->r12 = S32(ctx->r19 << 3);
    // 0x800299A4: addu        $t8, $t4, $s3
    ctx->r24 = ADD32(ctx->r12, ctx->r19);
    // 0x800299A8: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x800299AC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800299B0: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800299B4: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800299B8: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800299BC: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x800299C0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800299C4: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800299C8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800299CC: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x800299D0: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800299D4: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800299D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800299DC: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x800299E0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800299E4: addiu       $t8, $s4, -0x1
    ctx->r24 = ADD32(ctx->r20, -0X1);
    // 0x800299E8: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x800299EC: ori         $t9, $t3, 0x1
    ctx->r25 = ctx->r11 | 0X1;
    // 0x800299F0: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800299F4: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800299F8: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x800299FC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80029A00: sll         $t4, $s4, 4
    ctx->r12 = S32(ctx->r20 << 4);
    // 0x80029A04: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80029A08: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80029A0C: andi        $t8, $t4, 0xFFFF
    ctx->r24 = ctx->r12 & 0XFFFF;
    // 0x80029A10: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x80029A14: addu        $t9, $s7, $fp
    ctx->r25 = ADD32(ctx->r23, ctx->r30);
    // 0x80029A18: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80029A1C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80029A20: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029A24: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80029A28: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80029A2C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80029A30: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80029A34: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80029A38: b           L_80029AF8
    // 0x80029A3C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
        goto L_80029AF8;
    // 0x80029A3C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
L_80029A40:
    // 0x80029A40: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80029A44: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80029A48: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x80029A4C: jal         0x8007B938
    // 0x80029A50: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    material_set(rdram, ctx);
        goto after_2;
    // 0x80029A50: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    after_2:
    // 0x80029A54: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80029A58: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80029A5C: bne         $s5, $zero, L_80029A68
    if (ctx->r21 != 0) {
        // 0x80029A60: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80029A68;
    }
    // 0x80029A60: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80029A64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80029A68:
    // 0x80029A68: addu        $v1, $s6, $fp
    ctx->r3 = ADD32(ctx->r22, ctx->r30);
    // 0x80029A6C: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x80029A70: sll         $t3, $t8, 3
    ctx->r11 = S32(ctx->r24 << 3);
    // 0x80029A74: andi        $t9, $v1, 0x6
    ctx->r25 = ctx->r3 & 0X6;
    // 0x80029A78: or          $t5, $t3, $t9
    ctx->r13 = ctx->r11 | ctx->r25;
    // 0x80029A7C: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029A80: sll         $t8, $s3, 3
    ctx->r24 = S32(ctx->r19 << 3);
    // 0x80029A84: addu        $t3, $t8, $s3
    ctx->r11 = ADD32(ctx->r24, ctx->r19);
    // 0x80029A88: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80029A8C: sll         $t4, $t6, 16
    ctx->r12 = S32(ctx->r14 << 16);
    // 0x80029A90: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x80029A94: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80029A98: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80029A9C: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x80029AA0: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80029AA4: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x80029AA8: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80029AAC: or          $t4, $t7, $t6
    ctx->r12 = ctx->r15 | ctx->r14;
    // 0x80029AB0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80029AB4: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80029AB8: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029ABC: addiu       $t3, $s4, -0x1
    ctx->r11 = ADD32(ctx->r20, -0X1);
    // 0x80029AC0: sll         $t9, $t3, 4
    ctx->r25 = S32(ctx->r11 << 4);
    // 0x80029AC4: or          $t5, $t9, $s1
    ctx->r13 = ctx->r25 | ctx->r17;
    // 0x80029AC8: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80029ACC: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80029AD0: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x80029AD4: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80029AD8: sll         $t8, $s4, 4
    ctx->r24 = S32(ctx->r20 << 4);
    // 0x80029ADC: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80029AE0: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x80029AE4: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x80029AE8: or          $t9, $t4, $t3
    ctx->r25 = ctx->r12 | ctx->r11;
    // 0x80029AEC: addu        $t5, $s7, $fp
    ctx->r13 = ADD32(ctx->r23, ctx->r30);
    // 0x80029AF0: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x80029AF4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_80029AF8:
    // 0x80029AF8: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
L_80029AFC:
    // 0x80029AFC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80029B00: bne         $t1, $t7, L_8002976C
    if (ctx->r9 != ctx->r15) {
        // 0x80029B04: addiu       $t2, $t2, 0xC
        ctx->r10 = ADD32(ctx->r10, 0XC);
            goto L_8002976C;
    }
    // 0x80029B04: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
L_80029B08:
    // 0x80029B08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80029B0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029B10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80029B14: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80029B18: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80029B1C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80029B20: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80029B24: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80029B28: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80029B2C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80029B30: jr          $ra
    // 0x80029B34: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80029B34: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void obj_loop_cameracontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800391C8: jr          $ra
    // 0x800391CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800391CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void mempool_slot_find(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070F7C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80070F80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80070F84: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80070F88: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80070F8C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80070F90: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80070F94: jal         0x8006F750
    // 0x80070F98: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80070F98: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x80070F9C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80070FA0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80070FA4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80070FA8: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x80070FAC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80070FB0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80070FB4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80070FB8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80070FBC: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80070FC0: bne         $t2, $t3, L_80070FDC
    if (ctx->r10 != ctx->r11) {
        // 0x80070FC4: andi        $t4, $s1, 0xF
        ctx->r12 = ctx->r17 & 0XF;
            goto L_80070FDC;
    }
    // 0x80070FC4: andi        $t4, $s1, 0xF
    ctx->r12 = ctx->r17 & 0XF;
    // 0x80070FC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80070FCC: jal         0x8006F77C
    // 0x80070FD0: nop

    interrupts_enable(rdram, ctx);
        goto after_1;
    // 0x80070FD0: nop

    after_1:
    // 0x80070FD4: b           L_800710BC
    // 0x80070FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800710BC;
    // 0x80070FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80070FDC:
    // 0x80070FDC: beq         $t4, $zero, L_80070FF0
    if (ctx->r12 == 0) {
        // 0x80070FE0: addiu       $s0, $zero, -0x1
        ctx->r16 = ADD32(0, -0X1);
            goto L_80070FF0;
    }
    // 0x80070FE0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80070FE4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80070FE8: and         $t5, $s1, $at
    ctx->r13 = ctx->r17 & ctx->r1;
    // 0x80070FEC: addiu       $s1, $t5, 0x10
    ctx->r17 = ADD32(ctx->r13, 0X10);
L_80070FF0:
    // 0x80070FF0: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80070FF4: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80070FF8: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80070FFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071000: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80071004: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80071008:
    // 0x80071008: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007100C: mflo        $t6
    ctx->r14 = lo;
    // 0x80071010: addu        $v0, $t6, $t1
    ctx->r2 = ADD32(ctx->r14, ctx->r9);
    // 0x80071014: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x80071018: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007101C: bne         $t7, $zero, L_80071048
    if (ctx->r15 != 0) {
        // 0x80071020: nop
    
            goto L_80071048;
    }
    // 0x80071020: nop

    // 0x80071024: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80071028: nop

    // 0x8007102C: slt         $at, $v1, $s1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80071030: bne         $at, $zero, L_80071048
    if (ctx->r1 != 0) {
        // 0x80071034: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80071048;
    }
    // 0x80071034: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80071038: beq         $at, $zero, L_80071048
    if (ctx->r1 == 0) {
        // 0x8007103C: nop
    
            goto L_80071048;
    }
    // 0x8007103C: nop

    // 0x80071040: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80071044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_80071048:
    // 0x80071048: lh          $a0, 0xC($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XC);
    // 0x8007104C: nop

    // 0x80071050: bne         $a0, $a3, L_80071008
    if (ctx->r4 != ctx->r7) {
        // 0x80071054: nop
    
            goto L_80071008;
    }
    // 0x80071054: nop

    // 0x80071058: beq         $s0, $a3, L_800710AC
    if (ctx->r16 == ctx->r7) {
        // 0x8007105C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800710AC;
    }
    // 0x8007105C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80071060: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80071064: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80071068: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8007106C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80071070: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80071074: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80071078: jal         0x800719CC
    // 0x8007107C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    mempool_slot_assign(rdram, ctx);
        goto after_2;
    // 0x8007107C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_2:
    // 0x80071080: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80071084: jal         0x8006F77C
    // 0x80071088: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80071088: nop

    after_3:
    // 0x8007108C: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80071090: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071094: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80071098: mflo        $t9
    ctx->r25 = lo;
    // 0x8007109C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800710A0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800710A4: b           L_800710C0
    // 0x800710A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800710C0;
    // 0x800710A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800710AC:
    // 0x800710AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800710B0: jal         0x8006F77C
    // 0x800710B4: nop

    interrupts_enable(rdram, ctx);
        goto after_4;
    // 0x800710B4: nop

    after_4:
    // 0x800710B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800710BC:
    // 0x800710BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800710C0:
    // 0x800710C0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800710C4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800710C8: jr          $ra
    // 0x800710CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800710CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void init_save_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081668: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008166C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081670: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80081674: jal         0x8006B464
    // 0x80081678: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    level_count(rdram, ctx);
        goto after_0;
    // 0x80081678: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8008167C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80081680: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80081684: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80081688: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8008168C: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x80081690: addiu       $v1, $v1, 0x11B
    ctx->r3 = ADD32(ctx->r3, 0X11B);
    // 0x80081694: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80081698: and         $t9, $v1, $at
    ctx->r25 = ctx->r3 & ctx->r1;
    // 0x8008169C: sll         $a0, $t9, 2
    ctx->r4 = S32(ctx->r25 << 2);
    // 0x800816A0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800816A4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800816A8: jal         0x80070EDC
    // 0x800816AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800816AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800816B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800816B4: addiu       $a0, $a0, 0x6AD0
    ctx->r4 = ADD32(ctx->r4, 0X6AD0);
    // 0x800816B8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800816BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800816C0: sw          $v0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r2;
    // 0x800816C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800816C8: lw          $t1, 0x6AD0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6AD0);
    // 0x800816CC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800816D0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800816D4: addiu       $t2, $t1, 0x118
    ctx->r10 = ADD32(ctx->r9, 0X118);
    // 0x800816D8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800816DC: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x800816E0: lw          $t3, 0x6AD0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6AD0);
    // 0x800816E4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800816E8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800816EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800816F0: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800816F4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x800816F8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800816FC: addu        $v1, $a3, $a3
    ctx->r3 = ADD32(ctx->r7, ctx->r7);
    // 0x80081700: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80081704: sw          $t7, 0x6AD4($at)
    MEM_W(0X6AD4, ctx->r1) = ctx->r15;
    // 0x80081708: lw          $t8, 0x6AD4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6AD4);
    // 0x8008170C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081710: addiu       $t9, $t8, 0x118
    ctx->r25 = ADD32(ctx->r24, 0X118);
    // 0x80081714: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80081718: lw          $t0, 0x6AD4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6AD4);
    // 0x8008171C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80081720: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x80081724: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80081728: addu        $t1, $t2, $a2
    ctx->r9 = ADD32(ctx->r10, ctx->r6);
    // 0x8008172C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80081730: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80081734: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80081738: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8008173C: sw          $t5, 0x6AD8($at)
    MEM_W(0X6AD8, ctx->r1) = ctx->r13;
    // 0x80081740: lw          $t3, 0x6AD8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6AD8);
    // 0x80081744: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80081748: addiu       $t6, $t3, 0x118
    ctx->r14 = ADD32(ctx->r11, 0X118);
    // 0x8008174C: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80081750: lw          $t7, 0x6AD8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6AD8);
    // 0x80081754: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80081758: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8008175C: nop

    // 0x80081760: addu        $t8, $t9, $a2
    ctx->r24 = ADD32(ctx->r25, ctx->r6);
    // 0x80081764: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80081768: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8008176C: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x80081770: addu        $t1, $t2, $v1
    ctx->r9 = ADD32(ctx->r10, ctx->r3);
    // 0x80081774: sw          $t1, 0x6ADC($at)
    MEM_W(0X6ADC, ctx->r1) = ctx->r9;
    // 0x80081778: lw          $t0, 0x6ADC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6ADC);
    // 0x8008177C: nop

    // 0x80081780: addiu       $t4, $t0, 0x118
    ctx->r12 = ADD32(ctx->r8, 0X118);
    // 0x80081784: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80081788: lw          $t5, 0x6ADC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6ADC);
    // 0x8008178C: nop

    // 0x80081790: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80081794: nop

    // 0x80081798: addu        $t3, $t6, $a2
    ctx->r11 = ADD32(ctx->r14, ctx->r6);
    // 0x8008179C: jal         0x8001E2D0
    // 0x800817A0: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    get_misc_asset(rdram, ctx);
        goto after_2;
    // 0x800817A0: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    after_2:
    // 0x800817A4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800817A8: addiu       $v1, $v1, 0x71F0
    ctx->r3 = ADD32(ctx->r3, 0X71F0);
    // 0x800817AC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800817B0: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x800817B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800817B8: addiu       $a0, $zero, 0x1400
    ctx->r4 = ADD32(0, 0X1400);
    // 0x800817BC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800817C0: jal         0x80070EDC
    // 0x800817C4: sw          $t8, 0x71F8($at)
    MEM_W(0X71F8, ctx->r1) = ctx->r24;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x800817C4: sw          $t8, 0x71F8($at)
    MEM_W(0X71F8, ctx->r1) = ctx->r24;
    after_3:
    // 0x800817C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800817CC: sw          $v0, -0x5E0($at)
    MEM_W(-0X5E0, ctx->r1) = ctx->r2;
    // 0x800817D0: jal         0x8007FD50
    // 0x800817D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    load_menu_text(rdram, ctx);
        goto after_4;
    // 0x800817D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800817D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800817DC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800817E0: addiu       $v1, $v1, 0x6CF0
    ctx->r3 = ADD32(ctx->r3, 0X6CF0);
    // 0x800817E4: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
L_800817E8:
    // 0x800817E8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800817EC: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x800817F0: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x800817F4: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x800817F8: bne         $v0, $v1, L_800817E8
    if (ctx->r2 != ctx->r3) {
        // 0x800817FC: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_800817E8;
    }
    // 0x800817FC: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80081800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081804: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80081808: jr          $ra
    // 0x8008180C: nop

    return;
    // 0x8008180C: nop

;}
RECOMP_FUNC void input_get_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072494: beq         $a0, $zero, L_800724A8
    if (ctx->r4 == 0) {
        // 0x80072498: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800724A8;
    }
    // 0x80072498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007249C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800724A0: bne         $a0, $at, L_800724C0
    if (ctx->r4 != ctx->r1) {
        // 0x800724A4: nop
    
            goto L_800724C0;
    }
    // 0x800724A4: nop

L_800724A8:
    // 0x800724A8: jal         0x8000E158
    // 0x800724AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_race_started_by_player_two(rdram, ctx);
        goto after_0;
    // 0x800724AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800724B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800724B4: beq         $v0, $zero, L_800724C0
    if (ctx->r2 == 0) {
        // 0x800724B8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800724C0;
    }
    // 0x800724B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800724BC: subu        $a0, $t6, $a0
    ctx->r4 = SUB32(ctx->r14, ctx->r4);
L_800724C0:
    // 0x800724C0: jal         0x8006A738
    // 0x800724C4: nop

    input_player_id(rdram, ctx);
        goto after_1;
    // 0x800724C4: nop

    after_1:
    // 0x800724C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800724CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800724D0: jr          $ra
    // 0x800724D4: nop

    return;
    // 0x800724D4: nop

;}
RECOMP_FUNC void func_8001E4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E4F8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8001E4FC: addiu       $t0, $t0, -0x4C24
    ctx->r8 = ADD32(ctx->r8, -0X4C24);
    // 0x8001E500: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001E504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E508: blez        $v1, L_8001E558
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E50C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001E558;
    }
    // 0x8001E50C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001E510: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001E514: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x8001E518: addiu       $a2, $zero, -0x2001
    ctx->r6 = ADD32(0, -0X2001);
L_8001E51C:
    // 0x8001E51C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001E520: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E524: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8001E528: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x8001E52C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001E530: lh          $t8, 0x6($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X6);
    // 0x8001E534: nop

    // 0x8001E538: and         $t9, $t8, $a2
    ctx->r25 = ctx->r24 & ctx->r6;
    // 0x8001E53C: sh          $t9, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r25;
    // 0x8001E540: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001E544: nop

    // 0x8001E548: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E54C: bne         $at, $zero, L_8001E51C
    if (ctx->r1 != 0) {
        // 0x8001E550: nop
    
            goto L_8001E51C;
    }
    // 0x8001E550: nop

    // 0x8001E554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001E558:
    // 0x8001E558: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001E55C: blez        $v1, L_8001E610
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E560: addiu       $t1, $t1, -0x4C28
        ctx->r9 = ADD32(ctx->r9, -0X4C28);
            goto L_8001E610;
    }
    // 0x8001E560: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x8001E564: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001E568: addiu       $t3, $t3, -0x4C06
    ctx->r11 = ADD32(ctx->r11, -0X4C06);
    // 0x8001E56C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001E570: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8001E574: addiu       $t2, $zero, 0x31
    ctx->r10 = ADD32(0, 0X31);
L_8001E578:
    // 0x8001E578: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8001E57C: nop

    // 0x8001E580: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x8001E584: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8001E588: nop

    // 0x8001E58C: beq         $a1, $zero, L_8001E5F8
    if (ctx->r5 == 0) {
        // 0x8001E590: nop
    
            goto L_8001E5F8;
    }
    // 0x8001E590: nop

    // 0x8001E594: lh          $v1, 0x6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X6);
    // 0x8001E598: nop

    // 0x8001E59C: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x8001E5A0: bne         $t7, $zero, L_8001E5F8
    if (ctx->r15 != 0) {
        // 0x8001E5A4: nop
    
            goto L_8001E5F8;
    }
    // 0x8001E5A4: nop

    // 0x8001E5A8: lh          $t8, 0x48($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X48);
    // 0x8001E5AC: nop

    // 0x8001E5B0: bne         $t2, $t8, L_8001E5F8
    if (ctx->r10 != ctx->r24) {
        // 0x8001E5B4: nop
    
            goto L_8001E5F8;
    }
    // 0x8001E5B4: nop

    // 0x8001E5B8: lw          $a2, 0x3C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X3C);
    // 0x8001E5BC: lh          $t9, 0x0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X0);
    // 0x8001E5C0: lb          $a3, 0x21($a2)
    ctx->r7 = MEM_B(ctx->r6, 0X21);
    // 0x8001E5C4: nop

    // 0x8001E5C8: beq         $t9, $a3, L_8001E5F8
    if (ctx->r25 == ctx->r7) {
        // 0x8001E5CC: nop
    
            goto L_8001E5F8;
    }
    // 0x8001E5CC: nop

    // 0x8001E5D0: beq         $t4, $a3, L_8001E5F8
    if (ctx->r12 == ctx->r7) {
        // 0x8001E5D4: nop
    
            goto L_8001E5F8;
    }
    // 0x8001E5D4: nop

    // 0x8001E5D8: lw          $a2, 0x64($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X64);
    // 0x8001E5DC: ori         $t5, $v1, 0x2000
    ctx->r13 = ctx->r3 | 0X2000;
    // 0x8001E5E0: beq         $a2, $zero, L_8001E5F8
    if (ctx->r6 == 0) {
        // 0x8001E5E4: sh          $t5, 0x6($a1)
        MEM_H(0X6, ctx->r5) = ctx->r13;
            goto L_8001E5F8;
    }
    // 0x8001E5E4: sh          $t5, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r13;
    // 0x8001E5E8: lh          $t6, 0x6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X6);
    // 0x8001E5EC: nop

    // 0x8001E5F0: ori         $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 | 0X2000;
    // 0x8001E5F4: sh          $t7, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r15;
L_8001E5F8:
    // 0x8001E5F8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001E5FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E600: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E604: bne         $at, $zero, L_8001E578
    if (ctx->r1 != 0) {
        // 0x8001E608: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8001E578;
    }
    // 0x8001E608: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001E60C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001E610:
    // 0x8001E610: addiu       $a2, $v1, -0x1
    ctx->r6 = ADD32(ctx->r3, -0X1);
    // 0x8001E614: bltz        $a2, L_8001E70C
    if (SIGNED(ctx->r6) < 0) {
        // 0x8001E618: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_8001E70C;
    }
    // 0x8001E618: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8001E61C: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
L_8001E620:
    // 0x8001E620: bne         $at, $zero, L_8001E674
    if (ctx->r1 != 0) {
        // 0x8001E624: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001E674;
    }
    // 0x8001E624: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001E628: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001E62C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8001E630: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
L_8001E634:
    // 0x8001E634: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8001E638: nop

    // 0x8001E63C: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8001E640: nop

    // 0x8001E644: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x8001E648: beq         $t7, $zero, L_8001E65C
    if (ctx->r15 == 0) {
        // 0x8001E64C: nop
    
            goto L_8001E65C;
    }
    // 0x8001E64C: nop

    // 0x8001E650: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E654: b           L_8001E660
    // 0x8001E658: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_8001E660;
    // 0x8001E658: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8001E65C:
    // 0x8001E65C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8001E660:
    // 0x8001E660: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001E664: bne         $at, $zero, L_8001E674
    if (ctx->r1 != 0) {
        // 0x8001E668: nop
    
            goto L_8001E674;
    }
    // 0x8001E668: nop

    // 0x8001E66C: beq         $v1, $zero, L_8001E634
    if (ctx->r3 == 0) {
        // 0x8001E670: nop
    
            goto L_8001E634;
    }
    // 0x8001E670: nop

L_8001E674:
    // 0x8001E674: bltz        $a2, L_8001E6C4
    if (SIGNED(ctx->r6) < 0) {
        // 0x8001E678: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001E6C4;
    }
    // 0x8001E678: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001E67C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001E680: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8001E684: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
L_8001E688:
    // 0x8001E688: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8001E68C: nop

    // 0x8001E690: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8001E694: nop

    // 0x8001E698: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x8001E69C: beq         $t7, $zero, L_8001E6AC
    if (ctx->r15 == 0) {
        // 0x8001E6A0: nop
    
            goto L_8001E6AC;
    }
    // 0x8001E6A0: nop

    // 0x8001E6A4: b           L_8001E6B4
    // 0x8001E6A8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_8001E6B4;
    // 0x8001E6A8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8001E6AC:
    // 0x8001E6AC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001E6B0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
L_8001E6B4:
    // 0x8001E6B4: bltz        $a2, L_8001E6C8
    if (SIGNED(ctx->r6) < 0) {
        // 0x8001E6B8: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001E6C8;
    }
    // 0x8001E6B8: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001E6BC: beq         $v1, $zero, L_8001E688
    if (ctx->r3 == 0) {
        // 0x8001E6C0: nop
    
            goto L_8001E688;
    }
    // 0x8001E6C0: nop

L_8001E6C4:
    // 0x8001E6C4: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
L_8001E6C8:
    // 0x8001E6C8: beq         $at, $zero, L_8001E700
    if (ctx->r1 == 0) {
        // 0x8001E6CC: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8001E700;
    }
    // 0x8001E6CC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001E6D0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8001E6D4: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8001E6D8: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x8001E6DC: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8001E6E0: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
    // 0x8001E6E4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001E6E8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8001E6EC: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001E6F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E6F4: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8001E6F8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001E6FC: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
L_8001E700:
    // 0x8001E700: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001E704: beq         $at, $zero, L_8001E620
    if (ctx->r1 == 0) {
        // 0x8001E708: slt         $at, $a3, $v0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001E620;
    }
    // 0x8001E708: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
L_8001E70C:
    // 0x8001E70C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E710: sw          $v0, -0x4C20($at)
    MEM_W(-0X4C20, ctx->r1) = ctx->r2;
    // 0x8001E714: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E718: jr          $ra
    // 0x8001E71C: sh          $zero, -0x4C04($at)
    MEM_H(-0X4C04, ctx->r1) = 0;
    return;
    // 0x8001E71C: sh          $zero, -0x4C04($at)
    MEM_H(-0X4C04, ctx->r1) = 0;
;}
RECOMP_FUNC void obj_init_dino_whale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039208: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003920C: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80039210: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80039214: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80039218: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x8003921C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80039220: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80039224: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80039228: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8003922C: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x80039230: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80039234: jr          $ra
    // 0x80039238: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x80039238: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void set_player_selected_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C7A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C7AC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8009C7B0: jr          $ra
    // 0x8009C7B4: sb          $a1, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = ctx->r5;
    return;
    // 0x8009C7B4: sb          $a1, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void sprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4F74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B4F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4F7C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B4F80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B4F84: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800B4F88: jal         0x800B4FA0
    // 0x800B4F8C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    vsprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B4F8C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800B4F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4F94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B4F98: jr          $ra
    // 0x800B4F9C: nop

    return;
    // 0x800B4F9C: nop

;}
RECOMP_FUNC void pakmenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DB8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80088DBC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80088DC0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80088DC4: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80088DC8: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80088DCC: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80088DD0: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80088DD4: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80088DD8: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80088DDC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80088DE0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80088DE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80088DE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088DF0: jal         0x800C492C
    // 0x80088DF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_0;
    // 0x80088DF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80088DF8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80088DFC: lw          $s6, 0x695C($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X695C);
    // 0x80088E00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80088E04: sll         $t6, $s6, 3
    ctx->r14 = S32(ctx->r22 << 3);
    // 0x80088E08: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80088E0C: bne         $at, $zero, L_80088E1C
    if (ctx->r1 != 0) {
        // 0x80088E10: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_80088E1C;
    }
    // 0x80088E10: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x80088E14: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x80088E18: subu        $s6, $t7, $t6
    ctx->r22 = SUB32(ctx->r15, ctx->r14);
L_80088E1C:
    // 0x80088E1C: lw          $t8, 0x7188($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7188);
    // 0x80088E20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80088E24: beq         $t8, $zero, L_80088E44
    if (ctx->r24 == 0) {
        // 0x80088E28: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_80088E44;
    }
    // 0x80088E28: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80088E2C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80088E30: addiu       $a1, $a1, 0x234
    ctx->r5 = ADD32(ctx->r5, 0X234);
    // 0x80088E34: jal         0x8008263C
    // 0x80088E38: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_1;
    // 0x80088E38: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80088E3C: b           L_80089518
    // 0x80088E40: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80089518;
    // 0x80088E40: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80088E44:
    // 0x80088E44: lw          $t9, 0x314($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X314);
    // 0x80088E48: nop

    // 0x80088E4C: beq         $t9, $zero, L_80089518
    if (ctx->r25 == 0) {
        // 0x80088E50: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80089518;
    }
    // 0x80088E50: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80088E54: jal         0x800C484C
    // 0x80088E58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x80088E58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80088E5C: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x80088E60: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80088E64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80088E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088E6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088E70: jal         0x800C48E4
    // 0x80088E74: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x80088E74: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x80088E78: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80088E7C: addiu       $s7, $s7, -0x5E0
    ctx->r23 = ADD32(ctx->r23, -0X5E0);
    // 0x80088E80: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x80088E84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088E88: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80088E8C: lw          $a3, 0x8C($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8C);
    // 0x80088E90: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80088E94: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80088E98: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80088E9C: jal         0x800C49A0
    // 0x80088EA0: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    draw_text(rdram, ctx);
        goto after_4;
    // 0x80088EA0: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    after_4:
    // 0x80088EA4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80088EA8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80088EAC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80088EB0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088EB4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088EB8: jal         0x800C48E4
    // 0x80088EBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_5;
    // 0x80088EBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80088EC0: lw          $t4, 0x0($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X0);
    // 0x80088EC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088EC8: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80088ECC: lw          $a3, 0x8C($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8C);
    // 0x80088ED0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80088ED4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80088ED8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80088EDC: jal         0x800C49A0
    // 0x80088EE0: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x80088EE0: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_6:
    // 0x80088EE4: addiu       $s5, $zero, 0x30
    ctx->r21 = ADD32(0, 0X30);
    // 0x80088EE8: jal         0x800C59F4
    // 0x80088EEC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_7;
    // 0x80088EEC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_7:
    // 0x80088EF0: addiu       $t6, $s5, 0x1E
    ctx->r14 = ADD32(ctx->r21, 0X1E);
    // 0x80088EF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80088EF8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088EFC: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80088F00: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80088F04: jal         0x800C543C
    // 0x80088F08: addiu       $a3, $zero, 0x106
    ctx->r7 = ADD32(0, 0X106);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_8;
    // 0x80088F08: addiu       $a3, $zero, 0x106
    ctx->r7 = ADD32(0, 0X106);
    after_8:
    // 0x80088F0C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80088F10: lw          $t7, -0x620($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X620);
    // 0x80088F14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80088F18: bne         $t7, $at, L_80088F44
    if (ctx->r15 != ctx->r1) {
        // 0x80088F1C: sra         $t8, $s6, 1
        ctx->r24 = S32(SIGNED(ctx->r22) >> 1);
            goto L_80088F44;
    }
    // 0x80088F1C: sra         $t8, $s6, 1
    ctx->r24 = S32(SIGNED(ctx->r22) >> 1);
    // 0x80088F20: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x80088F24: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80088F28: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F2C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088F30: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088F34: jal         0x800C551C
    // 0x80088F38: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_9;
    // 0x80088F38: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_9:
    // 0x80088F3C: b           L_80088F64
    // 0x80088F40: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
        goto L_80088F64;
    // 0x80088F40: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_80088F44:
    // 0x80088F44: addiu       $t0, $zero, 0xE0
    ctx->r8 = ADD32(0, 0XE0);
    // 0x80088F48: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80088F4C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F50: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x80088F54: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80088F58: jal         0x800C551C
    // 0x80088F5C: addiu       $a3, $zero, 0x5C
    ctx->r7 = ADD32(0, 0X5C);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_10;
    // 0x80088F5C: addiu       $a3, $zero, 0x5C
    ctx->r7 = ADD32(0, 0X5C);
    after_10:
    // 0x80088F60: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_80088F64:
    // 0x80088F64: jal         0x800C54DC
    // 0x80088F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_11;
    // 0x80088F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80088F6C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80088F70: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80088F74: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F78: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088F7C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088F80: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80088F84: jal         0x800C5560
    // 0x80088F88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_12;
    // 0x80088F88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_12:
    // 0x80088F8C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088F94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088F98: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80088F9C: jal         0x800C55B0
    // 0x80088FA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_13;
    // 0x80088FA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x80088FA4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80088FA8: lw          $t3, 0x7028($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7028);
    // 0x80088FAC: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x80088FB0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80088FB4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80088FB8: lw          $a3, 0x158($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X158);
    // 0x80088FBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80088FC0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80088FC4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80088FC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80088FCC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088FD0: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80088FD4: jal         0x800C56C8
    // 0x80088FD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_text(rdram, ctx);
        goto after_14;
    // 0x80088FD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_14:
    // 0x80088FDC: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80088FE0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80088FE4: lw          $t9, 0x7170($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7170);
    // 0x80088FE8: lw          $a3, 0x1C8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X1C8);
    // 0x80088FEC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80088FF0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80088FF4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088FF8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80088FFC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80089000: jal         0x800C56C8
    // 0x80089004: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    render_dialogue_text(rdram, ctx);
        goto after_15;
    // 0x80089004: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_15:
    // 0x80089008: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008900C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089018: jal         0x800C60B8
    // 0x8008901C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_16;
    // 0x8008901C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_16:
    // 0x80089020: addiu       $s5, $s5, 0x22
    ctx->r21 = ADD32(ctx->r21, 0X22);
    // 0x80089024: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089028: jal         0x800C54DC
    // 0x8008902C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    set_dialogue_font(rdram, ctx);
        goto after_17;
    // 0x8008902C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80089030: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089038: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008903C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80089040: jal         0x800C55B0
    // 0x80089044: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_18;
    // 0x80089044: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_18:
    // 0x80089048: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008904C: lw          $v0, 0x7174($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7174);
    // 0x80089050: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80089054: bltz        $v0, L_80089248
    if (SIGNED(ctx->r2) < 0) {
        // 0x80089058: nop
    
            goto L_80089248;
    }
    // 0x80089058: nop

L_8008905C:
    // 0x8008905C: jal         0x800C59F4
    // 0x80089060: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_19;
    // 0x80089060: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_19:
    // 0x80089064: addiu       $t1, $s5, 0xE
    ctx->r9 = ADD32(ctx->r21, 0XE);
    // 0x80089068: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008906C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089070: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80089074: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80089078: jal         0x800C543C
    // 0x8008907C: addiu       $a3, $zero, 0x124
    ctx->r7 = ADD32(0, 0X124);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_20;
    // 0x8008907C: addiu       $a3, $zero, 0x124
    ctx->r7 = ADD32(0, 0X124);
    after_20:
    // 0x80089080: bgez        $s1, L_800890EC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80089084: lui         $t6, 0x800F
        ctx->r14 = S32(0X800F << 16);
            goto L_800890EC;
    }
    // 0x80089084: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80089088: addiu       $t3, $zero, 0xE0
    ctx->r11 = ADD32(0, 0XE0);
    // 0x8008908C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089090: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089094: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80089098: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x8008909C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x800890A0: jal         0x800C551C
    // 0x800890A4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_21;
    // 0x800890A4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    after_21:
    // 0x800890A8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800890AC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800890B0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800890B4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800890B8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800890BC: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x800890C0: addiu       $a2, $zero, 0xE0
    ctx->r6 = ADD32(0, 0XE0);
    // 0x800890C4: jal         0x800C5560
    // 0x800890C8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    set_current_text_colour(rdram, ctx);
        goto after_22;
    // 0x800890C8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_22:
    // 0x800890CC: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x800890D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800890D4: lw          $t5, 0x6978($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6978);
    // 0x800890D8: lw          $s2, 0x1CC($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X1CC);
    // 0x800890DC: lw          $s0, 0x1D0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X1D0);
    // 0x800890E0: lw          $s4, 0x1D4($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X1D4);
    // 0x800890E4: b           L_800891A0
    // 0x800890E8: addu        $v1, $s1, $t5
    ctx->r3 = ADD32(ctx->r17, ctx->r13);
        goto L_800891A0;
    // 0x800890E8: addu        $v1, $s1, $t5
    ctx->r3 = ADD32(ctx->r17, ctx->r13);
L_800890EC:
    // 0x800890EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800890F0: lw          $t8, 0x6978($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6978);
    // 0x800890F4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800890F8: lw          $t7, -0x620($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X620);
    // 0x800890FC: addiu       $s4, $t6, -0x7864
    ctx->r20 = ADD32(ctx->r14, -0X7864);
    // 0x80089100: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80089104: bne         $t7, $t9, L_80089134
    if (ctx->r15 != ctx->r25) {
        // 0x80089108: or          $s2, $s4, $zero
        ctx->r18 = ctx->r20 | 0;
            goto L_80089134;
    }
    // 0x80089108: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x8008910C: sra         $t0, $s6, 1
    ctx->r8 = S32(SIGNED(ctx->r22) >> 1);
    // 0x80089110: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x80089114: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089118: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008911C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089120: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089124: jal         0x800C551C
    // 0x80089128: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_23;
    // 0x80089128: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_23:
    // 0x8008912C: b           L_80089154
    // 0x80089130: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
        goto L_80089154;
    // 0x80089130: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_80089134:
    // 0x80089134: addiu       $t3, $zero, 0xE0
    ctx->r11 = ADD32(0, 0XE0);
    // 0x80089138: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008913C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089140: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80089144: addiu       $a2, $zero, 0xE0
    ctx->r6 = ADD32(0, 0XE0);
    // 0x80089148: jal         0x800C551C
    // 0x8008914C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_24;
    // 0x8008914C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_24:
    // 0x80089150: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_80089154:
    // 0x80089154: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80089158: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8008915C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80089160: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089164: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80089168: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8008916C: jal         0x800C5560
    // 0x80089170: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    set_current_text_colour(rdram, ctx);
        goto after_25;
    // 0x80089170: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    after_25:
    // 0x80089174: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80089178: lw          $t5, 0x6978($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6978);
    // 0x8008917C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80089180: addu        $v1, $t5, $s1
    ctx->r3 = ADD32(ctx->r13, ctx->r17);
    // 0x80089184: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80089188: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8008918C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80089190: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x80089194: lw          $s0, 0x7060($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7060);
    // 0x80089198: lw          $s3, 0x7130($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X7130);
    // 0x8008919C: nop

L_800891A0:
    // 0x800891A0: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800891A4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800891A8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800891AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800891B0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800891B4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x800891B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800891BC: jal         0x800C56C8
    // 0x800891C0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_26;
    // 0x800891C0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_26:
    // 0x800891C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800891C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800891CC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800891D0: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x800891D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800891D8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800891DC: jal         0x800C56C8
    // 0x800891E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    render_dialogue_text(rdram, ctx);
        goto after_27;
    // 0x800891E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_27:
    // 0x800891E4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800891E8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800891EC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800891F0: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x800891F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800891F8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800891FC: jal         0x800C56C8
    // 0x80089200: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    render_dialogue_text(rdram, ctx);
        goto after_28;
    // 0x80089200: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_28:
    // 0x80089204: jal         0x800C46C4
    // 0x80089208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_kerning(rdram, ctx);
        goto after_29;
    // 0x80089208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_29:
    // 0x8008920C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089210: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089218: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008921C: jal         0x800C60B8
    // 0x80089220: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_30;
    // 0x80089220: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_30:
    // 0x80089224: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x80089228: jal         0x800C46C4
    // 0x8008922C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_kerning(rdram, ctx);
        goto after_31;
    // 0x8008922C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x80089230: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089234: lw          $v0, 0x7174($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7174);
    // 0x80089238: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008923C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80089240: bne         $at, $zero, L_8008905C
    if (ctx->r1 != 0) {
        // 0x80089244: nop
    
            goto L_8008905C;
    }
    // 0x80089244: nop

L_80089248:
    // 0x80089248: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008924C: lw          $t0, 0x6978($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6978);
    // 0x80089250: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // 0x80089254: subu        $t1, $s0, $v0
    ctx->r9 = SUB32(ctx->r16, ctx->r2);
    // 0x80089258: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8008925C: beq         $at, $zero, L_800892C0
    if (ctx->r1 == 0) {
        // 0x80089260: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800892C0;
    }
    // 0x80089260: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80089264: lw          $t3, 0x695C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X695C);
    // 0x80089268: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008926C: andi        $t2, $t3, 0x8
    ctx->r10 = ctx->r11 & 0X8;
    // 0x80089270: beq         $t2, $zero, L_80089338
    if (ctx->r10 == 0) {
        // 0x80089274: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_80089338;
    }
    // 0x80089274: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089278: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008927C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80089280: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80089284: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80089288: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008928C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80089290: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80089294: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80089298: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008929C: addiu       $a1, $a1, 0x9BC
    ctx->r5 = ADD32(ctx->r5, 0X9BC);
    // 0x800892A0: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x800892A4: jal         0x80078F08
    // 0x800892A8: addiu       $a3, $s5, 0x8
    ctx->r7 = ADD32(ctx->r21, 0X8);
    texrect_draw(rdram, ctx);
        goto after_32;
    // 0x800892A8: addiu       $a3, $s5, 0x8
    ctx->r7 = ADD32(ctx->r21, 0X8);
    after_32:
    // 0x800892AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800892B0: jal         0x8007B820
    // 0x800892B4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    rendermode_reset(rdram, ctx);
        goto after_33;
    // 0x800892B4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_33:
    // 0x800892B8: b           L_80089338
    // 0x800892BC: nop

        goto L_80089338;
    // 0x800892BC: nop

L_800892C0:
    // 0x800892C0: jal         0x800C484C
    // 0x800892C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_34;
    // 0x800892C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x800892C8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800892CC: lw          $t7, -0x620($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X620);
    // 0x800892D0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800892D4: bne         $s0, $t7, L_80089300
    if (ctx->r16 != ctx->r15) {
        // 0x800892D8: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80089300;
    }
    // 0x800892D8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800892DC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800892E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800892E4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800892E8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800892EC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800892F0: jal         0x800C48E4
    // 0x800892F4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    set_text_colour(rdram, ctx);
        goto after_35;
    // 0x800892F4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_35:
    // 0x800892F8: b           L_80089318
    // 0x800892FC: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
        goto L_80089318;
    // 0x800892FC: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
L_80089300:
    // 0x80089300: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80089304: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80089308: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008930C: jal         0x800C48E4
    // 0x80089310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_36;
    // 0x80089310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_36:
    // 0x80089314: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
L_80089318:
    // 0x80089318: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008931C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80089320: lw          $a3, 0xCC($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XCC);
    // 0x80089324: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089328: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008932C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089330: jal         0x800C49A0
    // 0x80089334: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    draw_text(rdram, ctx);
        goto after_37;
    // 0x80089334: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_37:
L_80089338:
    // 0x80089338: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8008933C: addiu       $s3, $s3, 0x6980
    ctx->r19 = ADD32(ctx->r19, 0X6980);
    // 0x80089340: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80089344: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80089348: beq         $t2, $zero, L_800894C0
    if (ctx->r10 == 0) {
        // 0x8008934C: nop
    
            goto L_800894C0;
    }
    // 0x8008934C: nop

    // 0x80089350: lw          $t4, 0x71D0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X71D0);
    // 0x80089354: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80089358: bne         $t4, $zero, L_800894C0
    if (ctx->r12 != 0) {
        // 0x8008935C: nop
    
            goto L_800894C0;
    }
    // 0x8008935C: nop

    // 0x80089360: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x80089364: addiu       $s5, $zero, 0x78
    ctx->r21 = ADD32(0, 0X78);
    // 0x80089368: bne         $t5, $zero, L_80089378
    if (ctx->r13 != 0) {
        // 0x8008936C: nop
    
            goto L_80089378;
    }
    // 0x8008936C: nop

    // 0x80089370: b           L_80089378
    // 0x80089374: addiu       $s5, $zero, 0x86
    ctx->r21 = ADD32(0, 0X86);
        goto L_80089378;
    // 0x80089374: addiu       $s5, $zero, 0x86
    ctx->r21 = ADD32(0, 0X86);
L_80089378:
    // 0x80089378: jal         0x800C59F4
    // 0x8008937C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_38;
    // 0x8008937C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_38:
    // 0x80089380: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089384: jal         0x800C54DC
    // 0x80089388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_39;
    // 0x80089388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x8008938C: addiu       $t6, $s5, 0x1C
    ctx->r14 = ADD32(ctx->r21, 0X1C);
    // 0x80089390: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80089394: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089398: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8008939C: addiu       $a2, $s5, -0x1C
    ctx->r6 = ADD32(ctx->r21, -0X1C);
    // 0x800893A0: jal         0x800C543C
    // 0x800893A4: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_40;
    // 0x800893A4: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    after_40:
    // 0x800893A8: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x800893AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800893B0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800893B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800893B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800893BC: jal         0x800C551C
    // 0x800893C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_41;
    // 0x800893C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_41:
    // 0x800893C4: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x800893C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800893CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800893D0: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_800893D4:
    // 0x800893D4: bne         $s1, $zero, L_80089404
    if (ctx->r17 != 0) {
        // 0x800893D8: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_80089404;
    }
    // 0x800893D8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800893DC: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x800893E0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800893E4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800893E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800893EC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800893F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800893F4: jal         0x800C5560
    // 0x800893F8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_text_colour(rdram, ctx);
        goto after_42;
    // 0x800893F8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_42:
    // 0x800893FC: b           L_80089458
    // 0x80089400: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
        goto L_80089458;
    // 0x80089400: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
L_80089404:
    // 0x80089404: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80089408: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008940C: bne         $s1, $t0, L_8008943C
    if (ctx->r17 != ctx->r8) {
        // 0x80089410: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008943C;
    }
    // 0x80089410: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089414: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80089418: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8008941C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80089420: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089424: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089428: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8008942C: jal         0x800C5560
    // 0x80089430: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    set_current_text_colour(rdram, ctx);
        goto after_43;
    // 0x80089430: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_43:
    // 0x80089434: b           L_80089458
    // 0x80089438: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
        goto L_80089458;
    // 0x80089438: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
L_8008943C:
    // 0x8008943C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80089440: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80089444: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089448: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8008944C: jal         0x800C5560
    // 0x80089450: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_44;
    // 0x80089450: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_44:
    // 0x80089454: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
L_80089458:
    // 0x80089458: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008945C: lw          $t5, -0x620($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X620);
    // 0x80089460: addu        $t4, $t2, $s0
    ctx->r12 = ADD32(ctx->r10, ctx->r16);
    // 0x80089464: lw          $a3, 0x1BC($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X1BC);
    // 0x80089468: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8008946C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80089470: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80089474: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80089478: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008947C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089480: jal         0x800C56C8
    // 0x80089484: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_45;
    // 0x80089484: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_45:
    // 0x80089488: beq         $s1, $zero, L_80089498
    if (ctx->r17 == 0) {
        // 0x8008948C: nop
    
            goto L_80089498;
    }
    // 0x8008948C: nop

    // 0x80089490: b           L_8008949C
    // 0x80089494: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
        goto L_8008949C;
    // 0x80089494: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
L_80089498:
    // 0x80089498: addiu       $s5, $s5, 0x14
    ctx->r21 = ADD32(ctx->r21, 0X14);
L_8008949C:
    // 0x8008949C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800894A0: bne         $s1, $s2, L_800893D4
    if (ctx->r17 != ctx->r18) {
        // 0x800894A4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800893D4;
    }
    // 0x800894A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800894A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800894AC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800894B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800894B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800894B8: jal         0x800C60B8
    // 0x800894BC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_46;
    // 0x800894BC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_46:
L_800894C0:
    // 0x800894C0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800894C4: lw          $t7, 0x71D0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X71D0);
    // 0x800894C8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800894CC: beq         $t7, $zero, L_80089514
    if (ctx->r15 == 0) {
        // 0x800894D0: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80089514;
    }
    // 0x800894D0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800894D4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800894D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800894DC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800894E0: jal         0x800C48E4
    // 0x800894E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_47;
    // 0x800894E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_47:
    // 0x800894E8: jal         0x800C484C
    // 0x800894EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_48;
    // 0x800894EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_48:
    // 0x800894F0: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x800894F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800894F8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800894FC: lw          $a3, 0x1F0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X1F0);
    // 0x80089500: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089504: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089508: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008950C: jal         0x800C49A0
    // 0x80089510: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    draw_text(rdram, ctx);
        goto after_49;
    // 0x80089510: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_49:
L_80089514:
    // 0x80089514: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80089518:
    // 0x80089518: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8008951C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80089520: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80089524: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80089528: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8008952C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80089530: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80089534: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80089538: jr          $ra
    // 0x8008953C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8008953C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void sndp_get_global_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000317C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80003180: lw          $v0, -0x33D0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X33D0);
    // 0x80003184: jr          $ra
    // 0x80003188: nop

    return;
    // 0x80003188: nop

;}
RECOMP_FUNC void music_jingle_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001BC0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001BC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80001BC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001BCC: addiu       $v0, $v0, 0x6285
    ctx->r2 = ADD32(ctx->r2, 0X6285);
    // 0x80001BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001BD4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80001BD8: sb          $t6, -0x344C($at)
    MEM_B(-0X344C, ctx->r1) = ctx->r14;
    // 0x80001BDC: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x80001BE0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80001BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001BE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001BEC: lw          $a1, -0x345C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X345C);
    // 0x80001BF0: jal         0x800022BC
    // 0x80001BF4: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    music_sequence_start(rdram, ctx);
        goto after_0;
    // 0x80001BF4: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    after_0:
    // 0x80001BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001C00: jr          $ra
    // 0x80001C04: nop

    return;
    // 0x80001C04: nop

;}
RECOMP_FUNC void _Ldtob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7470: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800D7474: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D7478: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800D747C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800D7480: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800D7484: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800D7488: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800D748C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800D7490: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800D7494: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x800D7498: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x800D749C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x800D74A0: addiu       $s5, $sp, 0xB0
    ctx->r21 = ADD32(ctx->r29, 0XB0);
    // 0x800D74A4: ldc1        $f20, 0x0($a0)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
    // 0x800D74A8: bgez        $v0, L_800D74B8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D74AC: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_800D74B8;
    }
    // 0x800D74AC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800D74B0: b           L_800D74E4
    // 0x800D74B4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
        goto L_800D74E4;
    // 0x800D74B4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_800D74B8:
    // 0x800D74B8: bne         $v0, $zero, L_800D74E4
    if (ctx->r2 != 0) {
        // 0x800D74BC: lbu         $t8, 0xD7($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0XD7);
            goto L_800D74E4;
    }
    // 0x800D74BC: lbu         $t8, 0xD7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD7);
    // 0x800D74C0: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x800D74C4: beq         $t8, $at, L_800D74D8
    if (ctx->r24 == ctx->r1) {
        // 0x800D74C8: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_800D74D8;
    }
    // 0x800D74C8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x800D74CC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800D74D0: bnel        $t8, $at, L_800D74E8
    if (ctx->r24 != ctx->r1) {
        // 0x800D74D4: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_800D74E8;
    }
    goto skip_0;
    // 0x800D74D4: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    skip_0:
L_800D74D8:
    // 0x800D74D8: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x800D74DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D74E0: sw          $t9, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r25;
L_800D74E4:
    // 0x800D74E4: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_800D74E8:
    // 0x800D74E8: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x800D74EC: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x800D74F0: andi        $v1, $a0, 0x7FF0
    ctx->r3 = ctx->r4 & 0X7FF0;
    // 0x800D74F4: sra         $t8, $v1, 4
    ctx->r24 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800D74F8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D74FC: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D7500: bne         $v1, $at, L_800D7564
    if (ctx->r3 != ctx->r1) {
        // 0x800D7504: nop
    
            goto L_800D7564;
    }
    // 0x800D7504: nop

    // 0x800D7508: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x800D750C: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x800D7510: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800D7514: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800D7518: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800D751C: bnel        $t9, $zero, L_800D7548
    if (ctx->r25 != 0) {
        // 0x800D7520: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D7548;
    }
    goto skip_1;
    // 0x800D7520: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_1:
    // 0x800D7524: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x800D7528: bnel        $t7, $zero, L_800D7548
    if (ctx->r15 != 0) {
        // 0x800D752C: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D7548;
    }
    goto skip_2;
    // 0x800D752C: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_2:
    // 0x800D7530: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800D7534: bnel        $t8, $zero, L_800D7548
    if (ctx->r24 != 0) {
        // 0x800D7538: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D7548;
    }
    goto skip_3;
    // 0x800D7538: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_3:
    // 0x800D753C: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x800D7540: beq         $t9, $zero, L_800D7550
    if (ctx->r25 == 0) {
        // 0x800D7544: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D7550;
    }
    // 0x800D7544: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
L_800D7548:
    // 0x800D7548: b           L_800D759C
    // 0x800D754C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800D759C;
    // 0x800D754C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800D7550:
    // 0x800D7550: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D7554: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800D7558: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800D755C: b           L_800D759C
    // 0x800D7560: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800D759C;
    // 0x800D7560: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800D7564:
    // 0x800D7564: blez        $v1, L_800D7588
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800D7568: andi        $t8, $a0, 0x800F
        ctx->r24 = ctx->r4 & 0X800F;
            goto L_800D7588;
    }
    // 0x800D7568: andi        $t8, $a0, 0x800F
    ctx->r24 = ctx->r4 & 0X800F;
    // 0x800D756C: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800D7570: ori         $t6, $t8, 0x3FF0
    ctx->r14 = ctx->r24 | 0X3FF0;
    // 0x800D7574: addiu       $t7, $v1, -0x3FE
    ctx->r15 = ADD32(ctx->r3, -0X3FE);
    // 0x800D7578: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x800D757C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800D7580: b           L_800D759C
    // 0x800D7584: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800D759C;
    // 0x800D7584: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D7588:
    // 0x800D7588: bgez        $v1, L_800D7598
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D758C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D7598;
    }
    // 0x800D758C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D7590: b           L_800D759C
    // 0x800D7594: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800D759C;
    // 0x800D7594: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800D7598:
    // 0x800D7598: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_800D759C:
    // 0x800D759C: blez        $v0, L_800D75E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D75A0: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_800D75E8;
    }
    // 0x800D75A0: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800D75A4: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800D75A8: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D75AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D75B0: bne         $t6, $at, L_800D75C4
    if (ctx->r14 != ctx->r1) {
        // 0x800D75B4: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_800D75C4;
    }
    // 0x800D75B4: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800D75B8: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800D75BC: b           L_800D75CC
    // 0x800D75C0: addiu       $a1, $a1, -0x61D8
    ctx->r5 = ADD32(ctx->r5, -0X61D8);
        goto L_800D75CC;
    // 0x800D75C0: addiu       $a1, $a1, -0x61D8
    ctx->r5 = ADD32(ctx->r5, -0X61D8);
L_800D75C4:
    // 0x800D75C4: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800D75C8: addiu       $a1, $a1, -0x61D4
    ctx->r5 = ADD32(ctx->r5, -0X61D4);
L_800D75CC:
    // 0x800D75CC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800D75D0: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    // 0x800D75D4: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x800D75D8: jal         0x800CE6D0
    // 0x800D75DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800D75DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x800D75E0: b           L_800D7998
    // 0x800D75E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800D7998;
    // 0x800D75E4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800D75E8:
    // 0x800D75E8: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D75EC: bne         $t6, $zero, L_800D75FC
    if (ctx->r14 != 0) {
        // 0x800D75F0: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800D75FC;
    }
    // 0x800D75F0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800D75F4: b           L_800D7980
    // 0x800D75F8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
        goto L_800D7980;
    // 0x800D75F8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_800D75FC:
    // 0x800D75FC: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800D7600: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D7604: lbu         $t7, 0xD7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD7);
    // 0x800D7608: lh          $t9, 0x9A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9A);
    // 0x800D760C: c.lt.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d < ctx->f2.d;
    // 0x800D7610: addiu       $at, $zero, 0x7597
    ctx->r1 = ADD32(0, 0X7597);
    // 0x800D7614: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D7618: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800D761C: bc1f        L_800D7628
    if (!c1cs) {
        // 0x800D7620: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_800D7628;
    }
    // 0x800D7620: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800D7624: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_800D7628:
    // 0x800D7628: multu       $t9, $at
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D762C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800D7630: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x800D7634: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800D7638: mflo        $t8
    ctx->r24 = lo;
    // 0x800D763C: nop

    // 0x800D7640: nop

    // 0x800D7644: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800D7648: mflo        $t6
    ctx->r14 = lo;
    // 0x800D764C: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x800D7650: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800D7654: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D7658: bgez        $t8, L_800D76C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D765C: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_800D76C0;
    }
    // 0x800D765C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800D7660: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800D7664: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D7668: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800D766C: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x800D7670: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D7674: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x800D7678: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x800D767C: blez        $v0, L_800D7730
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D7680: sh          $t9, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r25;
            goto L_800D7730;
    }
    // 0x800D7680: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x800D7684: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D7688: addiu       $a0, $a0, -0x6220
    ctx->r4 = ADD32(ctx->r4, -0X6220);
L_800D768C:
    // 0x800D768C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800D7690: beq         $t6, $zero, L_800D76AC
    if (ctx->r14 == 0) {
        // 0x800D7694: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800D76AC;
    }
    // 0x800D7694: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800D7698: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800D769C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x800D76A0: ldc1        $f4, 0x0($t7)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r15, 0X0);
    // 0x800D76A4: mul.d       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x800D76A8: nop

L_800D76AC:
    // 0x800D76AC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800D76B0: bgtz        $t9, L_800D768C
    if (SIGNED(ctx->r25) > 0) {
        // 0x800D76B4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D768C;
    }
    // 0x800D76B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D76B8: b           L_800D7734
    // 0x800D76BC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
        goto L_800D7734;
    // 0x800D76BC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800D76C0:
    // 0x800D76C0: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x800D76C4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D76C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D76CC: blez        $t6, L_800D7730
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D76D0: andi        $t8, $t6, 0xFFFC
        ctx->r24 = ctx->r14 & 0XFFFC;
            goto L_800D7730;
    }
    // 0x800D76D0: andi        $t8, $t6, 0xFFFC
    ctx->r24 = ctx->r14 & 0XFFFC;
    // 0x800D76D4: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x800D76D8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D76DC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800D76E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D76E4: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D76E8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800D76EC: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x800D76F0: blez        $t6, L_800D772C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D76F4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800D772C;
    }
    // 0x800D76F4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800D76F8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D76FC: addiu       $a0, $a0, -0x6220
    ctx->r4 = ADD32(ctx->r4, -0X6220);
L_800D7700:
    // 0x800D7700: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800D7704: beq         $t7, $zero, L_800D7720
    if (ctx->r15 == 0) {
        // 0x800D7708: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800D7720;
    }
    // 0x800D7708: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800D770C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800D7710: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800D7714: ldc1        $f6, 0x0($t9)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r25, 0X0);
    // 0x800D7718: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800D771C: nop

L_800D7720:
    // 0x800D7720: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800D7724: bgtz        $t6, L_800D7700
    if (SIGNED(ctx->r14) > 0) {
        // 0x800D7728: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D7700;
    }
    // 0x800D7728: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D772C:
    // 0x800D772C: div.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f0.d);
L_800D7730:
    // 0x800D7730: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800D7734:
    // 0x800D7734: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800D7738: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800D773C: bne         $t7, $at, L_800D7750
    if (ctx->r15 != ctx->r1) {
        // 0x800D7740: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_800D7750;
    }
    // 0x800D7740: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800D7744: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x800D7748: b           L_800D7750
    // 0x800D774C: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
        goto L_800D7750;
    // 0x800D774C: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_800D7750:
    // 0x800D7750: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800D7754: addu        $s4, $a1, $t9
    ctx->r20 = ADD32(ctx->r5, ctx->r25);
    // 0x800D7758: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x800D775C: bne         $at, $zero, L_800D7768
    if (ctx->r1 != 0) {
        // 0x800D7760: nop
    
            goto L_800D7768;
    }
    // 0x800D7760: nop

    // 0x800D7764: addiu       $s4, $zero, 0x13
    ctx->r20 = ADD32(0, 0X13);
L_800D7768:
    // 0x800D7768: blez        $s4, L_800D7838
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800D776C: sb          $t6, 0xB0($sp)
        MEM_B(0XB0, ctx->r29) = ctx->r14;
            goto L_800D7838;
    }
    // 0x800D776C: sb          $t6, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r14;
    // 0x800D7770: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800D7774: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x800D7778: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x800D777C: bc1fl       L_800D783C
    if (!c1cs) {
        // 0x800D7780: lh          $t8, 0x9A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X9A);
            goto L_800D783C;
    }
    goto skip_4;
    // 0x800D7780: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
    skip_4:
    // 0x800D7784: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
L_800D7788:
    // 0x800D7788: addiu       $s4, $s4, -0x8
    ctx->r20 = ADD32(ctx->r20, -0X8);
    // 0x800D778C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800D7790: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x800D7794: blez        $s4, L_800D77B8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800D7798: nop
    
            goto L_800D77B8;
    }
    // 0x800D7798: nop

    // 0x800D779C: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x800D77A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D77A4: ldc1        $f8, -0x61C8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X61C8);
    // 0x800D77A8: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x800D77AC: sub.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f20.d - ctx->f4.d;
    // 0x800D77B0: mul.d       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f20.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800D77B4: nop

L_800D77B8:
    // 0x800D77B8: blez        $s1, L_800D7800
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800D77BC: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_800D7800;
    }
    // 0x800D77BC: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x800D77C0: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x800D77C4: bltz        $s0, L_800D7800
    if (SIGNED(ctx->r16) < 0) {
        // 0x800D77C8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D7800;
    }
    // 0x800D77C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800D77CC:
    // 0x800D77CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D77D0: jal         0x800D7AD0
    // 0x800D77D4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_1;
    // 0x800D77D4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x800D77D8: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800D77DC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800D77E0: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x800D77E4: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x800D77E8: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x800D77EC: blezl       $s1, L_800D7804
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800D77F0: mtc1        $zero, $f3
        ctx->f_odd[(3 - 1) * 2] = 0;
            goto L_800D7804;
    }
    goto skip_5;
    // 0x800D77F0: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    skip_5:
    // 0x800D77F4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D77F8: bgezl       $s0, L_800D77CC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800D77FC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D77CC;
    }
    goto skip_6;
    // 0x800D77FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
L_800D7800:
    // 0x800D7800: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
L_800D7804:
    // 0x800D7804: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D7808: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D780C: bltz        $s0, L_800D7820
    if (SIGNED(ctx->r16) < 0) {
        // 0x800D7810: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800D7820;
    }
L_800D7810:
    // 0x800D7810: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D7814: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800D7818: bgez        $s0, L_800D7810
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800D781C: sb          $s3, 0x0($s5)
        MEM_B(0X0, ctx->r21) = ctx->r19;
            goto L_800D7810;
    }
    // 0x800D781C: sb          $s3, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r19;
L_800D7820:
    // 0x800D7820: blez        $s4, L_800D7838
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800D7824: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_800D7838;
    }
    // 0x800D7824: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800D7828: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800D782C: nop

    // 0x800D7830: bc1tl       L_800D7788
    if (c1cs) {
        // 0x800D7834: trunc.w.d   $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
            goto L_800D7788;
    }
    goto skip_7;
    // 0x800D7834: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
    skip_7:
L_800D7838:
    // 0x800D7838: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
L_800D783C:
    // 0x800D783C: lbu         $t6, 0xB1($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB1);
    // 0x800D7840: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x800D7844: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800D7848: subu        $s4, $s5, $t7
    ctx->r20 = SUB32(ctx->r21, ctx->r15);
    // 0x800D784C: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800D7850: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800D7854: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x800D7858: bne         $v0, $t6, L_800D7880
    if (ctx->r2 != ctx->r14) {
        // 0x800D785C: addiu       $s5, $sp, 0xB1
        ctx->r21 = ADD32(ctx->r29, 0XB1);
            goto L_800D7880;
    }
    // 0x800D785C: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800D7860: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
L_800D7864:
    // 0x800D7864: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800D7868: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800D786C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800D7870: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x800D7874: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x800D7878: beql        $v0, $t9, L_800D7864
    if (ctx->r2 == ctx->r25) {
        // 0x800D787C: lh          $t7, 0x9A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X9A);
            goto L_800D7864;
    }
    goto skip_8;
    // 0x800D787C: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
    skip_8:
L_800D7880:
    // 0x800D7880: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800D7884: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800D7888: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800D788C: bne         $t6, $at, L_800D78A0
    if (ctx->r14 != ctx->r1) {
        // 0x800D7890: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_800D78A0;
    }
    // 0x800D7890: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800D7894: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x800D7898: b           L_800D78C0
    // 0x800D789C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_800D78C0;
    // 0x800D789C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800D78A0:
    // 0x800D78A0: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x800D78A4: beq         $t7, $at, L_800D78B4
    if (ctx->r15 == ctx->r1) {
        // 0x800D78A8: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_800D78B4;
    }
    // 0x800D78A8: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x800D78AC: bne         $t7, $at, L_800D78BC
    if (ctx->r15 != ctx->r1) {
        // 0x800D78B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D78BC;
    }
    // 0x800D78B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D78B4:
    // 0x800D78B4: b           L_800D78BC
    // 0x800D78B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D78BC;
    // 0x800D78B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D78BC:
    // 0x800D78BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800D78C0:
    // 0x800D78C0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800D78C4: addu        $s3, $a1, $t9
    ctx->r19 = ADD32(ctx->r5, ctx->r25);
    // 0x800D78C8: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800D78CC: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D78D0: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D78D4: beq         $at, $zero, L_800D78E8
    if (ctx->r1 == 0) {
        // 0x800D78D8: nop
    
            goto L_800D78E8;
    }
    // 0x800D78D8: nop

    // 0x800D78DC: sll         $s3, $s4, 16
    ctx->r19 = S32(ctx->r20 << 16);
    // 0x800D78E0: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D78E4: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_800D78E8:
    // 0x800D78E8: blez        $s3, L_800D7980
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800D78EC: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_800D7980;
    }
    // 0x800D78EC: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800D78F0: beq         $at, $zero, L_800D7910
    if (ctx->r1 == 0) {
        // 0x800D78F4: addu        $v0, $s3, $s5
        ctx->r2 = ADD32(ctx->r19, ctx->r21);
            goto L_800D7910;
    }
    // 0x800D78F4: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
    // 0x800D78F8: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800D78FC: slti        $at, $t9, 0x35
    ctx->r1 = SIGNED(ctx->r25) < 0X35 ? 1 : 0;
    // 0x800D7900: bnel        $at, $zero, L_800D7914
    if (ctx->r1 != 0) {
        // 0x800D7904: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_800D7914;
    }
    goto skip_9;
    // 0x800D7904: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    skip_9:
    // 0x800D7908: b           L_800D7918
    // 0x800D790C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_800D7918;
    // 0x800D790C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_800D7910:
    // 0x800D7910: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_800D7914:
    // 0x800D7914: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
L_800D7918:
    // 0x800D7918: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x800D791C: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x800D7920: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D7924: bne         $a1, $t6, L_800D794C
    if (ctx->r5 != ctx->r14) {
        // 0x800D7928: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_800D794C;
    }
    // 0x800D7928: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x800D792C: addu        $v0, $v1, $s5
    ctx->r2 = ADD32(ctx->r3, ctx->r21);
L_800D7930:
    // 0x800D7930: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x800D7934: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800D7938: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800D793C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800D7940: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D7944: beq         $a0, $t9, L_800D7930
    if (ctx->r4 == ctx->r25) {
        // 0x800D7948: sra         $s3, $t7, 16
        ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
            goto L_800D7930;
    }
    // 0x800D7948: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_800D794C:
    // 0x800D794C: bne         $a0, $at, L_800D7960
    if (ctx->r4 != ctx->r1) {
        // 0x800D7950: addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
            goto L_800D7960;
    }
    // 0x800D7950: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x800D7954: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800D7958: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D795C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_800D7960:
    // 0x800D7960: bgez        $v1, L_800D7980
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D7964: lh          $t6, 0x9A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X9A);
            goto L_800D7980;
    }
    // 0x800D7964: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x800D7968: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800D796C: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800D7970: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D7974: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800D7978: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D797C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_800D7980:
    // 0x800D7980: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x800D7984: lbu         $s4, 0xD7($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XD7);
    // 0x800D7988: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x800D798C: jal         0x800D6F00
    // 0x800D7990: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    static_3_800D6F00(rdram, ctx);
        goto after_2;
    // 0x800D7990: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    after_2:
    // 0x800D7994: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800D7998:
    // 0x800D7998: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800D799C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800D79A0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800D79A4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800D79A8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800D79AC: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800D79B0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800D79B4: jr          $ra
    // 0x800D79B8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800D79B8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void music_animation_fraction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800015F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800015FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001600: jal         0x800C7E30
    // 0x80001604: nop

    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x80001604: nop

    after_0:
    // 0x80001608: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000160C: lw          $a0, -0x3444($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3444);
    // 0x80001610: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80001614: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80001618: beq         $at, $zero, L_80001668
    if (ctx->r1 == 0) {
        // 0x8000161C: lui         $t1, 0x8011
        ctx->r9 = S32(0X8011 << 16);
            goto L_80001668;
    }
    // 0x8000161C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80001620: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x80001624: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80001628: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000162C: addiu       $v1, $v1, 0x62B4
    ctx->r3 = ADD32(ctx->r3, 0X62B4);
    // 0x80001630: bgez        $t6, L_80001648
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80001634: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80001648;
    }
    // 0x80001634: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80001638: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000163C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80001640: nop

    // 0x80001644: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80001648:
    // 0x80001648: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000164C: lwc1        $f10, 0x4F70($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4F70);
    // 0x80001650: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80001654: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80001658: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000165C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80001660: b           L_800016B0
    // 0x80001664: swc1        $f4, 0x62B4($at)
    MEM_W(0X62B4, ctx->r1) = ctx->f4.u32l;
        goto L_800016B0;
    // 0x80001664: swc1        $f4, 0x62B4($at)
    MEM_W(0X62B4, ctx->r1) = ctx->f4.u32l;
L_80001668:
    // 0x80001668: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x8000166C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80001670: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80001674: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80001678: addiu       $v1, $v1, 0x62B4
    ctx->r3 = ADD32(ctx->r3, 0X62B4);
    // 0x8000167C: bgez        $t8, L_80001694
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80001680: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80001694;
    }
    // 0x80001680: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80001684: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80001688: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000168C: nop

    // 0x80001690: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80001694:
    // 0x80001694: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001698: lwc1        $f18, 0x4F74($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4F74);
    // 0x8000169C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800016A0: div.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800016A4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800016A8: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800016AC: swc1        $f8, 0x62B4($at)
    MEM_W(0X62B4, ctx->r1) = ctx->f8.u32l;
L_800016B0:
    // 0x800016B0: lbu         $t9, 0x62C0($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X62C0);
    // 0x800016B4: addiu       $t0, $zero, 0xB6
    ctx->r8 = ADD32(0, 0XB6);
    // 0x800016B8: bne         $t9, $zero, L_800016C4
    if (ctx->r25 != 0) {
        // 0x800016BC: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800016C4;
    }
    // 0x800016BC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800016C0: sh          $t0, 0x62B0($at)
    MEM_H(0X62B0, ctx->r1) = ctx->r8;
L_800016C4:
    // 0x800016C4: lh          $t1, 0x62B0($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X62B0);
    // 0x800016C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800016CC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800016D0: lwc1        $f10, 0x4F78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4F78);
    // 0x800016D4: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800016D8: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800016DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800016E0: div.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800016E4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800016E8: nop

    // 0x800016EC: bc1f        L_80001718
    if (!c1cs) {
        // 0x800016F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001718;
    }
    // 0x800016F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800016F4:
    // 0x800016F4: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800016F8: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800016FC: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80001700: nop

    // 0x80001704: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80001708: nop

    // 0x8000170C: bc1t        L_800016F4
    if (c1cs) {
        // 0x80001710: nop
    
            goto L_800016F4;
    }
    // 0x80001710: nop

    // 0x80001714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001718:
    // 0x80001718: sw          $v0, -0x3444($at)
    MEM_W(-0X3444, ctx->r1) = ctx->r2;
    // 0x8000171C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001720: jr          $ra
    // 0x80001724: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    return;
    // 0x80001724: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
;}
RECOMP_FUNC void music_can_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800018D0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800018D4: lbu         $v0, -0x3450($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3450);
    // 0x800018D8: jr          $ra
    // 0x800018DC: nop

    return;
    // 0x800018DC: nop

;}
