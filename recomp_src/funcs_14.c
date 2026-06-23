#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void obj_loop_fogchanger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030AB4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80030AB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80030ABC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80030AC0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80030AC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80030AC8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80030ACC: lw          $t3, 0x3C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X3C);
    // 0x80030AD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80030AD4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80030AD8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80030ADC: jal         0x80066750
    // 0x80030AE0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_0;
    // 0x80030AE0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_0:
    // 0x80030AE4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80030AE8: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80030AEC: beq         $v0, $zero, L_80030B1C
    if (ctx->r2 == 0) {
        // 0x80030AF0: addiu       $a0, $sp, 0x74
        ctx->r4 = ADD32(ctx->r29, 0X74);
            goto L_80030B1C;
    }
    // 0x80030AF0: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80030AF4: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x80030AF8: jal         0x80069FBC
    // 0x80030AFC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    cam_get_cameras(rdram, ctx);
        goto after_1;
    // 0x80030AFC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_1:
    // 0x80030B00: jal         0x80066450
    // 0x80030B04: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x80030B04: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_2:
    // 0x80030B08: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80030B0C: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80030B10: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80030B14: b           L_80030B2C
    // 0x80030B18: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
        goto L_80030B2C;
    // 0x80030B18: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
L_80030B1C:
    // 0x80030B1C: jal         0x8001BAA8
    // 0x80030B20: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    get_racer_objects(rdram, ctx);
        goto after_3;
    // 0x80030B20: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    after_3:
    // 0x80030B24: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80030B28: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
L_80030B2C:
    // 0x80030B2C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80030B30: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80030B34: blez        $t7, L_80030E04
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80030B38: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80030E04;
    }
    // 0x80030B38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80030B3C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80030B40: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80030B44: addiu       $t4, $t4, -0x26F8
    ctx->r12 = ADD32(ctx->r12, -0X26F8);
    // 0x80030B48: addiu       $s2, $zero, 0x44
    ctx->r18 = ADD32(0, 0X44);
    // 0x80030B4C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80030B50: addiu       $t5, $zero, 0x38
    ctx->r13 = ADD32(0, 0X38);
L_80030B54:
    // 0x80030B54: beq         $ra, $zero, L_80030BB8
    if (ctx->r31 == 0) {
        // 0x80030B58: or          $t2, $s1, $zero
        ctx->r10 = ctx->r17 | 0;
            goto L_80030BB8;
    }
    // 0x80030B58: or          $t2, $s1, $zero
    ctx->r10 = ctx->r17 | 0;
    // 0x80030B5C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80030B60: addu        $t9, $ra, $t8
    ctx->r25 = ADD32(ctx->r31, ctx->r24);
    // 0x80030B64: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80030B68: nop

    // 0x80030B6C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80030B70: nop

    // 0x80030B74: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80030B78: nop

    // 0x80030B7C: bltz        $v0, L_80030BFC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80030B80: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_80030BFC;
    }
    // 0x80030B80: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80030B84: beq         $at, $zero, L_80030BFC
    if (ctx->r1 == 0) {
        // 0x80030B88: nop
    
            goto L_80030BFC;
    }
    // 0x80030B88: nop

    // 0x80030B8C: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030B90: mflo        $t6
    ctx->r14 = lo;
    // 0x80030B94: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80030B98: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x80030B9C: nop

    // 0x80030BA0: beq         $s0, $t8, L_80030BFC
    if (ctx->r16 == ctx->r24) {
        // 0x80030BA4: nop
    
            goto L_80030BFC;
    }
    // 0x80030BA4: nop

    // 0x80030BA8: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80030BAC: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80030BB0: b           L_80030BFC
    // 0x80030BB4: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
        goto L_80030BFC;
    // 0x80030BB4: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_80030BB8:
    // 0x80030BB8: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80030BBC: beq         $at, $zero, L_80030BFC
    if (ctx->r1 == 0) {
        // 0x80030BC0: nop
    
            goto L_80030BFC;
    }
    // 0x80030BC0: nop

    // 0x80030BC4: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030BC8: mflo        $t9
    ctx->r25 = lo;
    // 0x80030BCC: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x80030BD0: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x80030BD4: nop

    // 0x80030BD8: beq         $s0, $t7, L_80030BFC
    if (ctx->r16 == ctx->r15) {
        // 0x80030BDC: nop
    
            goto L_80030BFC;
    }
    // 0x80030BDC: nop

    // 0x80030BE0: multu       $a2, $s2
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030BE4: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x80030BE8: mflo        $t8
    ctx->r24 = lo;
    // 0x80030BEC: addu        $v0, $s3, $t8
    ctx->r2 = ADD32(ctx->r19, ctx->r24);
    // 0x80030BF0: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80030BF4: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80030BF8: nop

L_80030BFC:
    // 0x80030BFC: beq         $t2, $s1, L_80030DF0
    if (ctx->r10 == ctx->r17) {
        // 0x80030C00: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_80030DF0;
    }
    // 0x80030C00: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80030C04: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80030C08: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80030C0C: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80030C10: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80030C14: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80030C18: sub.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80030C1C: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80030C20: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80030C24: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80030C28: nop

    // 0x80030C2C: bc1f        L_80030DF0
    if (!c1cs) {
        // 0x80030C30: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_80030DF0;
    }
    // 0x80030C30: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80030C34: lh          $a0, 0xC($t3)
    ctx->r4 = MEM_H(ctx->r11, 0XC);
    // 0x80030C38: lh          $v1, 0xE($t3)
    ctx->r3 = MEM_H(ctx->r11, 0XE);
    // 0x80030C3C: lbu         $a3, 0x9($t3)
    ctx->r7 = MEM_BU(ctx->r11, 0X9);
    // 0x80030C40: lbu         $t0, 0xA($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0XA);
    // 0x80030C44: lbu         $t1, 0xB($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0XB);
    // 0x80030C48: lh          $a1, 0x10($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X10);
    // 0x80030C4C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80030C50: beq         $at, $zero, L_80030C60
    if (ctx->r1 == 0) {
        // 0x80030C54: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80030C60;
    }
    // 0x80030C54: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80030C58: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80030C5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80030C60:
    // 0x80030C60: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80030C64: bne         $at, $zero, L_80030C74
    if (ctx->r1 != 0) {
        // 0x80030C68: addiu       $v0, $v1, -0x5
        ctx->r2 = ADD32(ctx->r3, -0X5);
            goto L_80030C74;
    }
    // 0x80030C68: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x80030C6C: addiu       $v1, $zero, 0x3FF
    ctx->r3 = ADD32(0, 0X3FF);
    // 0x80030C70: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
L_80030C74:
    // 0x80030C74: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030C78: bne         $at, $zero, L_80030C84
    if (ctx->r1 != 0) {
        // 0x80030C7C: nop
    
            goto L_80030C84;
    }
    // 0x80030C7C: nop

    // 0x80030C80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80030C84:
    // 0x80030C84: multu       $t2, $t5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030C88: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80030C8C: mflo        $t9
    ctx->r25 = lo;
    // 0x80030C90: addu        $v0, $t4, $t9
    ctx->r2 = ADD32(ctx->r12, ctx->r25);
    // 0x80030C94: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80030C98: sb          $a3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r7;
    // 0x80030C9C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030CA0: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030CA4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80030CA8: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x80030CAC: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80030CB0: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80030CB4: sh          $a0, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r4;
    // 0x80030CB8: sh          $v1, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r3;
    // 0x80030CBC: bne         $a1, $zero, L_80030CC8
    if (ctx->r5 != 0) {
        // 0x80030CC0: nop
    
            goto L_80030CC8;
    }
    // 0x80030CC0: nop

    // 0x80030CC4: break       7
    do_break(2147683524);
L_80030CC8:
    // 0x80030CC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030CCC: bne         $a1, $at, L_80030CE0
    if (ctx->r5 != ctx->r1) {
        // 0x80030CD0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030CE0;
    }
    // 0x80030CD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030CD4: bne         $t8, $at, L_80030CE0
    if (ctx->r24 != ctx->r1) {
        // 0x80030CD8: nop
    
            goto L_80030CE0;
    }
    // 0x80030CD8: nop

    // 0x80030CDC: break       6
    do_break(2147683548);
L_80030CE0:
    // 0x80030CE0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030CE4: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80030CE8: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x80030CEC: sw          $a1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r5;
    // 0x80030CF0: sw          $s0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r16;
    // 0x80030CF4: mflo        $t9
    ctx->r25 = lo;
    // 0x80030CF8: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x80030CFC: nop

    // 0x80030D00: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030D04: bne         $a1, $zero, L_80030D10
    if (ctx->r5 != 0) {
        // 0x80030D08: nop
    
            goto L_80030D10;
    }
    // 0x80030D08: nop

    // 0x80030D0C: break       7
    do_break(2147683596);
L_80030D10:
    // 0x80030D10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030D14: bne         $a1, $at, L_80030D28
    if (ctx->r5 != ctx->r1) {
        // 0x80030D18: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030D28;
    }
    // 0x80030D18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030D1C: bne         $t8, $at, L_80030D28
    if (ctx->r24 != ctx->r1) {
        // 0x80030D20: nop
    
            goto L_80030D28;
    }
    // 0x80030D20: nop

    // 0x80030D24: break       6
    do_break(2147683620);
L_80030D28:
    // 0x80030D28: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030D2C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x80030D30: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80030D34: mflo        $t9
    ctx->r25 = lo;
    // 0x80030D38: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x80030D3C: nop

    // 0x80030D40: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030D44: bne         $a1, $zero, L_80030D50
    if (ctx->r5 != 0) {
        // 0x80030D48: nop
    
            goto L_80030D50;
    }
    // 0x80030D48: nop

    // 0x80030D4C: break       7
    do_break(2147683660);
L_80030D50:
    // 0x80030D50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030D54: bne         $a1, $at, L_80030D68
    if (ctx->r5 != ctx->r1) {
        // 0x80030D58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030D68;
    }
    // 0x80030D58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030D5C: bne         $t8, $at, L_80030D68
    if (ctx->r24 != ctx->r1) {
        // 0x80030D60: nop
    
            goto L_80030D68;
    }
    // 0x80030D60: nop

    // 0x80030D64: break       6
    do_break(2147683684);
L_80030D68:
    // 0x80030D68: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030D6C: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80030D70: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80030D74: mflo        $t9
    ctx->r25 = lo;
    // 0x80030D78: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x80030D7C: nop

    // 0x80030D80: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030D84: bne         $a1, $zero, L_80030D90
    if (ctx->r5 != 0) {
        // 0x80030D88: nop
    
            goto L_80030D90;
    }
    // 0x80030D88: nop

    // 0x80030D8C: break       7
    do_break(2147683724);
L_80030D90:
    // 0x80030D90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030D94: bne         $a1, $at, L_80030DA8
    if (ctx->r5 != ctx->r1) {
        // 0x80030D98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030DA8;
    }
    // 0x80030D98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030D9C: bne         $t8, $at, L_80030DA8
    if (ctx->r24 != ctx->r1) {
        // 0x80030DA0: nop
    
            goto L_80030DA8;
    }
    // 0x80030DA0: nop

    // 0x80030DA4: break       6
    do_break(2147683748);
L_80030DA8:
    // 0x80030DA8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80030DAC: mflo        $t9
    ctx->r25 = lo;
    // 0x80030DB0: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    // 0x80030DB4: nop

    // 0x80030DB8: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80030DBC: bne         $a1, $zero, L_80030DC8
    if (ctx->r5 != 0) {
        // 0x80030DC0: nop
    
            goto L_80030DC8;
    }
    // 0x80030DC0: nop

    // 0x80030DC4: break       7
    do_break(2147683780);
L_80030DC8:
    // 0x80030DC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030DCC: bne         $a1, $at, L_80030DE0
    if (ctx->r5 != ctx->r1) {
        // 0x80030DD0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030DE0;
    }
    // 0x80030DD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030DD4: bne         $t8, $at, L_80030DE0
    if (ctx->r24 != ctx->r1) {
        // 0x80030DD8: nop
    
            goto L_80030DE0;
    }
    // 0x80030DD8: nop

    // 0x80030DDC: break       6
    do_break(2147683804);
L_80030DE0:
    // 0x80030DE0: mflo        $t9
    ctx->r25 = lo;
    // 0x80030DE4: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x80030DE8: nop

    // 0x80030DEC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80030DF0:
    // 0x80030DF0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80030DF4: bne         $a2, $t6, L_80030B54
    if (ctx->r6 != ctx->r14) {
        // 0x80030DF8: nop
    
            goto L_80030B54;
    }
    // 0x80030DF8: nop

    // 0x80030DFC: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    // 0x80030E00: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
L_80030E04:
    // 0x80030E04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80030E08: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80030E0C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80030E10: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80030E14: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80030E18: jr          $ra
    // 0x80030E1C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80030E1C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8007AB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AF74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007AF78: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007AF7C: jr          $ra
    // 0x8007AF80: sb          $a0, 0x6884($at)
    MEM_B(0X6884, ctx->r1) = ctx->r4;
    return;
    // 0x8007AF80: sb          $a0, 0x6884($at)
    MEM_B(0X6884, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void viewport_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066F1C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80066F20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80066F24: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80066F28: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
    // 0x80066F2C: lw          $v0, 0x0($ra)
    ctx->r2 = MEM_W(ctx->r31, 0X0);
    // 0x80066F30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80066F34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066F38: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80066F3C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80066F40: jal         0x8000E184
    // 0x80066F44: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    is_player_two_in_control(rdram, ctx);
        goto after_0;
    // 0x80066F44: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_0:
    // 0x80066F48: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80066F4C: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80066F50: beq         $v0, $zero, L_80066F74
    if (ctx->r2 == 0) {
        // 0x80066F54: addiu       $ra, $ra, 0x1264
        ctx->r31 = ADD32(ctx->r31, 0X1264);
            goto L_80066F74;
    }
    // 0x80066F54: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
    // 0x80066F58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80066F5C: lw          $t6, 0x1260($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1260);
    // 0x80066F60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80066F64: bne         $t6, $zero, L_80066F74
    if (ctx->r14 != 0) {
        // 0x80066F68: nop
    
            goto L_80066F74;
    }
    // 0x80066F68: nop

    // 0x80066F6C: sw          $t7, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r15;
    // 0x80066F70: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80066F74:
    // 0x80066F74: jal         0x8007A970
    // 0x80066F78: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    fb_size(rdram, ctx);
        goto after_1;
    // 0x80066F78: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_1:
    // 0x80066F7C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80066F80: addiu       $t3, $zero, 0x34
    ctx->r11 = ADD32(0, 0X34);
    // 0x80066F84: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066F88: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80066F8C: addiu       $t2, $t2, -0x2A2C
    ctx->r10 = ADD32(ctx->r10, -0X2A2C);
    // 0x80066F90: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80066F94: srl         $t0, $v0, 16
    ctx->r8 = S32(U32(ctx->r2) >> 16);
    // 0x80066F98: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
    // 0x80066F9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80066FA0: srl         $a3, $t0, 1
    ctx->r7 = S32(U32(ctx->r8) >> 1);
    // 0x80066FA4: mflo        $t8
    ctx->r24 = lo;
    // 0x80066FA8: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80066FAC: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x80066FB0: nop

    // 0x80066FB4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80066FB8: beq         $t7, $zero, L_8006714C
    if (ctx->r15 == 0) {
        // 0x80066FBC: nop
    
            goto L_8006714C;
    }
    // 0x80066FBC: nop

    // 0x80066FC0: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x80066FC4: sw          $t1, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r9;
    // 0x80066FC8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80066FCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80066FD0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80066FD4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066FD8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80066FDC: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x80066FE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066FE4: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066FEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80066FF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80066FF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80066FF8: mflo        $t7
    ctx->r15 = lo;
    // 0x80066FFC: addu        $v1, $t2, $t7
    ctx->r3 = ADD32(ctx->r10, ctx->r15);
    // 0x80067000: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x80067004: nop

    // 0x80067008: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8006700C: nop

    // 0x80067010: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80067014: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067018: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8006701C: nop

    // 0x80067020: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067024: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067028: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006702C: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067030: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067034: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067038: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x8006703C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80067040: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80067044: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067048: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006704C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80067050: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067054: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067058: nop

    // 0x8006705C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067060: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067064: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067068: nop

    // 0x8006706C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80067070: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80067074: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067078: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8006707C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80067080: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80067084: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80067088: lw          $t9, 0x0($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X0);
    // 0x8006708C: nop

    // 0x80067090: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80067094: mflo        $t8
    ctx->r24 = lo;
    // 0x80067098: addu        $v1, $t2, $t8
    ctx->r3 = ADD32(ctx->r10, ctx->r24);
    // 0x8006709C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x800670A0: nop

    // 0x800670A4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800670A8: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x800670AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800670B0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800670B4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800670B8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800670BC: nop

    // 0x800670C0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800670C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800670C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800670CC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800670D0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800670D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800670D8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800670DC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800670E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800670E4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800670E8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800670EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800670F0: nop

    // 0x800670F4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800670F8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800670FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067100: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067104: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80067108: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8006710C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80067110: jal         0x80068398
    // 0x80067114: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    viewport_rsp_set(rdram, ctx);
        goto after_2;
    // 0x80067114: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80067118: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8006711C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80067120: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80067124: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
    // 0x80067128: beq         $a1, $zero, L_80067140
    if (ctx->r5 == 0) {
        // 0x8006712C: sw          $t6, 0x0($ra)
        MEM_W(0X0, ctx->r31) = ctx->r14;
            goto L_80067140;
    }
    // 0x8006712C: sw          $t6, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r14;
    // 0x80067130: jal         0x80067F7C
    // 0x80067134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80067D3C(rdram, ctx);
        goto after_3;
    // 0x80067134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80067138: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8006713C: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
L_80067140:
    // 0x80067140: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80067144: b           L_80067C6C
    // 0x80067148: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
        goto L_80067C6C;
    // 0x80067148: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
L_8006714C:
    // 0x8006714C: lw          $v1, 0x1260($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1260);
    // 0x80067150: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80067154: bne         $v1, $a0, L_80067160
    if (ctx->r3 != ctx->r4) {
        // 0x80067158: andi        $t1, $v0, 0xFFFF
        ctx->r9 = ctx->r2 & 0XFFFF;
            goto L_80067160;
    }
    // 0x80067158: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x8006715C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80067160:
    // 0x80067160: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80067164: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067168: srl         $a2, $t1, 1
    ctx->r6 = S32(U32(ctx->r9) >> 1);
    // 0x8006716C: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80067170: bne         $t2, $zero, L_80067180
    if (ctx->r10 != 0) {
        // 0x80067174: sw          $a3, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r7;
            goto L_80067180;
    }
    // 0x80067174: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x80067178: addiu       $t7, $zero, 0x91
    ctx->r15 = ADD32(0, 0X91);
    // 0x8006717C: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
L_80067180:
    // 0x80067180: beq         $v1, $zero, L_800671B4
    if (ctx->r3 == 0) {
        // 0x80067184: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800671B4;
    }
    // 0x80067184: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80067188: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006718C: beq         $v1, $t3, L_8006728C
    if (ctx->r3 == ctx->r11) {
        // 0x80067190: nop
    
            goto L_8006728C;
    }
    // 0x80067190: nop

    // 0x80067194: beq         $v1, $a0, L_8006748C
    if (ctx->r3 == ctx->r4) {
        // 0x80067198: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8006748C;
    }
    // 0x80067198: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8006719C: beq         $v1, $a1, L_80067684
    if (ctx->r3 == ctx->r5) {
        // 0x800671A0: srl         $t7, $a2, 1
        ctx->r15 = S32(U32(ctx->r6) >> 1);
            goto L_80067684;
    }
    // 0x800671A0: srl         $t7, $a2, 1
    ctx->r15 = S32(U32(ctx->r6) >> 1);
    // 0x800671A4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800671A8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800671AC: b           L_80067C24
    // 0x800671B0: nop

        goto L_80067C24;
    // 0x800671B0: nop

L_800671B4:
    // 0x800671B4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800671B8: bne         $t2, $zero, L_800671C4
    if (ctx->r10 != 0) {
        // 0x800671BC: or          $t3, $t9, $zero
        ctx->r11 = ctx->r25 | 0;
            goto L_800671C4;
    }
    // 0x800671BC: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x800671C0: addiu       $t3, $t9, -0x12
    ctx->r11 = ADD32(ctx->r25, -0X12);
L_800671C4:
    // 0x800671C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800671C8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800671CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800671D0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800671D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800671D8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800671DC: lui         $t8, 0xED00
    ctx->r24 = S32(0XED00 << 16);
    // 0x800671E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800671E4: bgez        $t1, L_800671FC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800671E8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800671FC;
    }
    // 0x800671E8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800671EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800671F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800671F4: nop

    // 0x800671F8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800671FC:
    // 0x800671FC: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067200: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80067204: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80067208: nop

    // 0x8006720C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80067210: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067214: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067218: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006721C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80067220: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80067224: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067228: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8006722C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80067230: bgez        $t0, L_80067244
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80067234: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067244;
    }
    // 0x80067234: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067238: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006723C: nop

    // 0x80067240: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067244:
    // 0x80067244: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067248: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8006724C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80067250: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80067254: nop

    // 0x80067258: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8006725C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067260: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067264: nop

    // 0x80067268: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8006726C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80067270: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067274: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067278: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8006727C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80067280: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067284: b           L_80067C24
    // 0x80067288: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
        goto L_80067C24;
    // 0x80067288: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
L_8006728C:
    // 0x8006728C: lw          $t3, 0x0($ra)
    ctx->r11 = MEM_W(ctx->r31, 0X0);
    // 0x80067290: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80067294: bne         $t3, $zero, L_8006736C
    if (ctx->r11 != 0) {
        // 0x80067298: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8006736C;
    }
    // 0x80067298: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8006729C: srl         $v0, $t0, 2
    ctx->r2 = S32(U32(ctx->r8) >> 2);
    // 0x800672A0: bne         $t2, $zero, L_800672AC
    if (ctx->r10 != 0) {
        // 0x800672A4: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_800672AC;
    }
    // 0x800672A4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800672A8: addiu       $t3, $v0, -0xC
    ctx->r11 = ADD32(ctx->r2, -0XC);
L_800672AC:
    // 0x800672AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800672B0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800672B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800672B8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800672BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800672C0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800672C4: lui         $t8, 0xED00
    ctx->r24 = S32(0XED00 << 16);
    // 0x800672C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800672CC: bgez        $t1, L_800672E4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800672D0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800672E4;
    }
    // 0x800672D0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800672D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800672D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800672DC: nop

    // 0x800672E0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800672E4:
    // 0x800672E4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800672E8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800672EC: nop

    // 0x800672F0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800672F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800672F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800672FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067300: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067304: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80067308: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8006730C: srl         $t6, $t0, 7
    ctx->r14 = S32(U32(ctx->r8) >> 7);
    // 0x80067310: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80067314: subu        $t7, $a3, $t6
    ctx->r15 = SUB32(ctx->r7, ctx->r14);
    // 0x80067318: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8006731C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80067320: bgez        $t7, L_80067334
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80067324: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80067334;
    }
    // 0x80067324: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80067328: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006732C: nop

    // 0x80067330: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80067334:
    // 0x80067334: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80067338: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8006733C: nop

    // 0x80067340: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067344: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067348: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006734C: nop

    // 0x80067350: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067354: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80067358: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006735C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067360: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80067364: b           L_80067478
    // 0x80067368: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80067478;
    // 0x80067368: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_8006736C:
    // 0x8006736C: srl         $v1, $t0, 7
    ctx->r3 = S32(U32(ctx->r8) >> 7);
    // 0x80067370: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067374: addu        $t7, $a3, $v1
    ctx->r15 = ADD32(ctx->r7, ctx->r3);
    // 0x80067378: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8006737C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067380: srl         $t6, $t0, 2
    ctx->r14 = S32(U32(ctx->r8) >> 2);
    // 0x80067384: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80067388: addu        $t3, $a3, $t6
    ctx->r11 = ADD32(ctx->r7, ctx->r14);
    // 0x8006738C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80067390: bgez        $t7, L_800673A8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80067394: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800673A8;
    }
    // 0x80067394: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80067398: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006739C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800673A0: nop

    // 0x800673A4: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_800673A8:
    // 0x800673A8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800673AC: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800673B0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800673B4: nop

    // 0x800673B8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800673BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800673C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800673C4: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800673C8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800673CC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800673D0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800673D4: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800673D8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800673DC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800673E0: bgez        $t1, L_800673F8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800673E4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800673F8;
    }
    // 0x800673E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800673E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800673EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800673F0: nop

    // 0x800673F4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800673F8:
    // 0x800673F8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800673FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067400: nop

    // 0x80067404: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067408: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006740C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067410: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067414: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80067418: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006741C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80067420: subu        $t9, $t0, $v1
    ctx->r25 = SUB32(ctx->r8, ctx->r3);
    // 0x80067424: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80067428: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8006742C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80067430: bgez        $t9, L_80067444
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80067434: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067444;
    }
    // 0x80067434: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067438: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006743C: nop

    // 0x80067440: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067444:
    // 0x80067444: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067448: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8006744C: nop

    // 0x80067450: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067454: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067458: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006745C: nop

    // 0x80067460: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067464: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80067468: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8006746C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80067470: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80067474: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
L_80067478:
    // 0x80067478: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8006747C: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067480: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80067484: b           L_80067C24
    // 0x80067488: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
        goto L_80067C24;
    // 0x80067488: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8006748C:
    // 0x8006748C: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x80067490: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80067494: bne         $t8, $zero, L_80067560
    if (ctx->r24 != 0) {
        // 0x80067498: lui         $t2, 0x8000
        ctx->r10 = S32(0X8000 << 16);
            goto L_80067560;
    }
    // 0x80067498: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8006749C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800674A0: srl         $t6, $t1, 8
    ctx->r14 = S32(U32(ctx->r9) >> 8);
    // 0x800674A4: subu        $t8, $a2, $t6
    ctx->r24 = SUB32(ctx->r6, ctx->r14);
    // 0x800674A8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800674AC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800674B0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800674B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800674B8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800674BC: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x800674C0: srl         $a1, $t1, 2
    ctx->r5 = S32(U32(ctx->r9) >> 2);
    // 0x800674C4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800674C8: bgez        $t8, L_800674E0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800674CC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800674E0;
    }
    // 0x800674CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800674D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800674D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800674D8: nop

    // 0x800674DC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800674E0:
    // 0x800674E0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800674E4: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800674E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800674EC: nop

    // 0x800674F0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800674F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800674F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800674FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067500: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067504: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80067508: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8006750C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067510: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80067514: bgez        $t0, L_80067528
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80067518: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80067528;
    }
    // 0x80067518: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006751C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067520: nop

    // 0x80067524: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80067528:
    // 0x80067528: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8006752C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80067530: nop

    // 0x80067534: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80067538: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006753C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067540: nop

    // 0x80067544: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067548: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8006754C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067550: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067554: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80067558: b           L_80067674
    // 0x8006755C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
        goto L_80067674;
    // 0x8006755C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80067560:
    // 0x80067560: srl         $a0, $t1, 8
    ctx->r4 = S32(U32(ctx->r9) >> 8);
    // 0x80067564: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80067568: addu        $t6, $a2, $a0
    ctx->r14 = ADD32(ctx->r6, ctx->r4);
    // 0x8006756C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80067570: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067574: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067578: srl         $t9, $t1, 2
    ctx->r25 = S32(U32(ctx->r9) >> 2);
    // 0x8006757C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80067580: addu        $a1, $a2, $t9
    ctx->r5 = ADD32(ctx->r6, ctx->r25);
    // 0x80067584: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80067588: bgez        $t6, L_800675A0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006758C: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800675A0;
    }
    // 0x8006758C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80067590: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067594: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067598: nop

    // 0x8006759C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_800675A0:
    // 0x800675A0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800675A4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800675A8: nop

    // 0x800675AC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800675B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800675B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800675B8: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800675BC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800675C0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800675C4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800675C8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800675CC: subu        $t9, $t1, $a0
    ctx->r25 = SUB32(ctx->r9, ctx->r4);
    // 0x800675D0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800675D4: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800675D8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800675DC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800675E0: bgez        $t9, L_800675F8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800675E4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800675F8;
    }
    // 0x800675E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800675E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800675EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800675F0: nop

    // 0x800675F4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800675F8:
    // 0x800675F8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800675FC: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80067600: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067604: nop

    // 0x80067608: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8006760C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067610: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067614: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067618: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8006761C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80067620: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80067624: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067628: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8006762C: bgez        $t0, L_80067640
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80067630: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067640;
    }
    // 0x80067630: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067634: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067638: nop

    // 0x8006763C: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067640:
    // 0x80067640: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067644: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067648: nop

    // 0x8006764C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80067650: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067654: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067658: nop

    // 0x8006765C: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067660: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80067664: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80067668: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8006766C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80067670: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_80067674:
    // 0x80067674: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067678: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8006767C: b           L_80067C24
    // 0x80067680: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
        goto L_80067C24;
    // 0x80067680: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_80067684:
    // 0x80067684: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80067688: lw          $v0, 0x0($ra)
    ctx->r2 = MEM_W(ctx->r31, 0X0);
    // 0x8006768C: srl         $t9, $t6, 1
    ctx->r25 = S32(U32(ctx->r14) >> 1);
    // 0x80067690: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80067694: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80067698: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8006769C: beq         $v0, $zero, L_800676C4
    if (ctx->r2 == 0) {
        // 0x800676A0: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_800676C4;
    }
    // 0x800676A0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800676A4: beq         $v0, $t3, L_8006782C
    if (ctx->r2 == ctx->r11) {
        // 0x800676A8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8006782C;
    }
    // 0x800676A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800676AC: beq         $v0, $a0, L_80067954
    if (ctx->r2 == ctx->r4) {
        // 0x800676B0: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80067954;
    }
    // 0x800676B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800676B4: beq         $v0, $a1, L_80067A78
    if (ctx->r2 == ctx->r5) {
        // 0x800676B8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80067A78;
    }
    // 0x800676B8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800676BC: b           L_80067BF4
    // 0x800676C0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_80067BF4;
    // 0x800676C0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_800676C4:
    // 0x800676C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800676C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800676CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800676D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800676D4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800676D8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800676DC: bgez        $zero, L_800676F4
    if (SIGNED(0) >= 0) {
        // 0x800676E0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800676F4;
    }
    // 0x800676E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800676E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800676E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800676EC: nop

    // 0x800676F0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800676F4:
    // 0x800676F4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800676F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800676FC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067700: nop

    // 0x80067704: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067708: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006770C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067710: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067714: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067718: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8006771C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067720: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80067724: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80067728: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8006772C: bgez        $zero, L_80067744
    if (SIGNED(0) >= 0) {
        // 0x80067730: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80067744;
    }
    // 0x80067730: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80067734: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067738: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006773C: nop

    // 0x80067740: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80067744:
    // 0x80067744: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80067748: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8006774C: nop

    // 0x80067750: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067754: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067758: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006775C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067760: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067764: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80067768: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006776C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80067770: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80067774: srl         $t7, $t1, 8
    ctx->r15 = S32(U32(ctx->r9) >> 8);
    // 0x80067778: subu        $t6, $a2, $t7
    ctx->r14 = SUB32(ctx->r6, ctx->r15);
    // 0x8006777C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80067780: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80067784: bgez        $t6, L_80067798
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80067788: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80067798;
    }
    // 0x80067788: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006778C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067790: nop

    // 0x80067794: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80067798:
    // 0x80067798: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8006779C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800677A0: nop

    // 0x800677A4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800677A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800677AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800677B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800677B4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800677B8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800677BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800677C0: srl         $t8, $t0, 7
    ctx->r24 = S32(U32(ctx->r8) >> 7);
    // 0x800677C4: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800677C8: subu        $t9, $a3, $t8
    ctx->r25 = SUB32(ctx->r7, ctx->r24);
    // 0x800677CC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800677D0: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x800677D4: bgez        $t9, L_800677E8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800677D8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800677E8;
    }
    // 0x800677D8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800677DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800677E0: nop

    // 0x800677E4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800677E8:
    // 0x800677E8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800677EC: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800677F0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800677F4: nop

    // 0x800677F8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800677FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067800: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067804: nop

    // 0x80067808: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8006780C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80067810: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067814: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80067818: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8006781C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80067820: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067824: b           L_80067BF4
    // 0x80067828: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_80067BF4;
    // 0x80067828: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_8006782C:
    // 0x8006782C: srl         $a0, $t1, 8
    ctx->r4 = S32(U32(ctx->r9) >> 8);
    // 0x80067830: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80067834: addu        $t6, $a2, $a0
    ctx->r14 = ADD32(ctx->r6, ctx->r4);
    // 0x80067838: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8006783C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067840: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80067844: or          $t4, $a2, $zero
    ctx->r12 = ctx->r6 | 0;
    // 0x80067848: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006784C: bgez        $t6, L_80067864
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80067850: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067864;
    }
    // 0x80067850: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067854: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067858: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006785C: nop

    // 0x80067860: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067864:
    // 0x80067864: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067868: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8006786C: nop

    // 0x80067870: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067874: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067878: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006787C: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067880: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067884: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80067888: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006788C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80067890: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80067894: addu        $t7, $a2, $a2
    ctx->r15 = ADD32(ctx->r6, ctx->r6);
    // 0x80067898: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x8006789C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800678A0: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800678A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800678A8: bgez        $t8, L_800678C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800678AC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800678C0;
    }
    // 0x800678AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800678B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800678B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800678B8: nop

    // 0x800678BC: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800678C0:
    // 0x800678C0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800678C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800678C8: nop

    // 0x800678CC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800678D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800678D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800678D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800678DC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800678E0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800678E4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800678E8: srl         $t6, $t0, 7
    ctx->r14 = S32(U32(ctx->r8) >> 7);
    // 0x800678EC: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800678F0: subu        $t9, $a3, $t6
    ctx->r25 = SUB32(ctx->r7, ctx->r14);
    // 0x800678F4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800678F8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800678FC: bgez        $t9, L_80067910
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80067900: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80067910;
    }
    // 0x80067900: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80067904: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067908: nop

    // 0x8006790C: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80067910:
    // 0x80067910: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80067914: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80067918: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006791C: nop

    // 0x80067920: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80067924: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067928: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006792C: nop

    // 0x80067930: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067934: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80067938: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8006793C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80067940: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x80067944: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80067948: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x8006794C: b           L_80067BF4
    // 0x80067950: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_80067BF4;
    // 0x80067950: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80067954:
    // 0x80067954: srl         $v1, $t0, 7
    ctx->r3 = S32(U32(ctx->r8) >> 7);
    // 0x80067958: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006795C: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x80067960: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80067964: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067968: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8006796C: or          $t5, $a3, $zero
    ctx->r13 = ctx->r7 | 0;
    // 0x80067970: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80067974: bgez        $t8, L_8006798C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80067978: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8006798C;
    }
    // 0x80067978: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006797C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067980: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067984: nop

    // 0x80067988: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_8006798C:
    // 0x8006798C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067990: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067994: nop

    // 0x80067998: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8006799C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800679A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800679A4: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800679A8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800679AC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800679B0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800679B4: srl         $t9, $t1, 8
    ctx->r25 = S32(U32(ctx->r9) >> 8);
    // 0x800679B8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x800679BC: subu        $t7, $a2, $t9
    ctx->r15 = SUB32(ctx->r6, ctx->r25);
    // 0x800679C0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800679C4: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800679C8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800679CC: bgez        $t7, L_800679E4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800679D0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800679E4;
    }
    // 0x800679D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800679D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800679D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800679DC: nop

    // 0x800679E0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800679E4:
    // 0x800679E4: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800679E8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800679EC: nop

    // 0x800679F0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800679F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800679F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800679FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067A00: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80067A04: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80067A08: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067A0C: addu        $t6, $a3, $a3
    ctx->r14 = ADD32(ctx->r7, ctx->r7);
    // 0x80067A10: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80067A14: subu        $t8, $t6, $v1
    ctx->r24 = SUB32(ctx->r14, ctx->r3);
    // 0x80067A18: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80067A1C: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80067A20: bgez        $t8, L_80067A34
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80067A24: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067A34;
    }
    // 0x80067A24: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067A28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067A2C: nop

    // 0x80067A30: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067A34:
    // 0x80067A34: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067A38: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80067A3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067A40: nop

    // 0x80067A44: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067A48: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067A4C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067A50: nop

    // 0x80067A54: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067A58: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80067A5C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067A60: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80067A64: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80067A68: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80067A6C: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067A70: b           L_80067BF4
    // 0x80067A74: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_80067BF4;
    // 0x80067A74: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80067A78:
    // 0x80067A78: srl         $a0, $t1, 8
    ctx->r4 = S32(U32(ctx->r9) >> 8);
    // 0x80067A7C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80067A80: addu        $t7, $a2, $a0
    ctx->r15 = ADD32(ctx->r6, ctx->r4);
    // 0x80067A84: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80067A88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067A8C: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80067A90: or          $t4, $a2, $zero
    ctx->r12 = ctx->r6 | 0;
    // 0x80067A94: or          $t5, $a3, $zero
    ctx->r13 = ctx->r7 | 0;
    // 0x80067A98: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80067A9C: srl         $v1, $t0, 7
    ctx->r3 = S32(U32(ctx->r8) >> 7);
    // 0x80067AA0: bgez        $t7, L_80067AB8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80067AA4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80067AB8;
    }
    // 0x80067AA4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067AA8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067AAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067AB0: nop

    // 0x80067AB4: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80067AB8:
    // 0x80067AB8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80067ABC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067AC0: nop

    // 0x80067AC4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80067AC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067ACC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067AD0: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067AD4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067AD8: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80067ADC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80067AE0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067AE4: addu        $t9, $a3, $v1
    ctx->r25 = ADD32(ctx->r7, ctx->r3);
    // 0x80067AE8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80067AEC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80067AF0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80067AF4: bgez        $t9, L_80067B0C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80067AF8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80067B0C;
    }
    // 0x80067AF8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80067AFC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067B00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067B04: nop

    // 0x80067B08: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80067B0C:
    // 0x80067B0C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80067B10: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067B14: nop

    // 0x80067B18: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067B1C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067B20: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067B24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067B28: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067B2C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80067B30: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80067B34: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80067B38: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80067B3C: addu        $t7, $a2, $a2
    ctx->r15 = ADD32(ctx->r6, ctx->r6);
    // 0x80067B40: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x80067B44: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80067B48: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80067B4C: bgez        $t8, L_80067B60
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80067B50: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80067B60;
    }
    // 0x80067B50: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80067B54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067B58: nop

    // 0x80067B5C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80067B60:
    // 0x80067B60: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067B64: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067B68: nop

    // 0x80067B6C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067B70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067B74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067B78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067B7C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067B80: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80067B84: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067B88: addu        $t9, $a3, $a3
    ctx->r25 = ADD32(ctx->r7, ctx->r7);
    // 0x80067B8C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067B90: subu        $t6, $t9, $v1
    ctx->r14 = SUB32(ctx->r25, ctx->r3);
    // 0x80067B94: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80067B98: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80067B9C: bgez        $t6, L_80067BB0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80067BA0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80067BB0;
    }
    // 0x80067BA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067BA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067BA8: nop

    // 0x80067BAC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80067BB0:
    // 0x80067BB0: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067BB4: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80067BB8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80067BBC: nop

    // 0x80067BC0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80067BC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067BC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067BCC: nop

    // 0x80067BD0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80067BD4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80067BD8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067BDC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067BE0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80067BE4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80067BE8: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067BEC: nop

    // 0x80067BF0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80067BF4:
    // 0x80067BF4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80067BF8: addu        $v0, $t5, $t9
    ctx->r2 = ADD32(ctx->r13, ctx->r25);
    // 0x80067BFC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80067C00: bne         $t2, $zero, L_80067C24
    if (ctx->r10 != 0) {
        // 0x80067C04: addu        $a3, $t4, $t8
        ctx->r7 = ADD32(ctx->r12, ctx->r24);
            goto L_80067C24;
    }
    // 0x80067C04: addu        $a3, $t4, $t8
    ctx->r7 = ADD32(ctx->r12, ctx->r24);
    // 0x80067C08: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x80067C0C: addiu       $t3, $v0, -0x6
    ctx->r11 = ADD32(ctx->r2, -0X6);
    // 0x80067C10: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80067C14: beq         $at, $zero, L_80067C24
    if (ctx->r1 == 0) {
        // 0x80067C18: nop
    
            goto L_80067C24;
    }
    // 0x80067C18: nop

    // 0x80067C1C: b           L_80067C24
    // 0x80067C20: addiu       $t3, $v0, -0x14
    ctx->r11 = ADD32(ctx->r2, -0X14);
        goto L_80067C24;
    // 0x80067C20: addiu       $t3, $v0, -0x14
    ctx->r11 = ADD32(ctx->r2, -0X14);
L_80067C24:
    // 0x80067C24: bne         $t2, $zero, L_80067C30
    if (ctx->r10 != 0) {
        // 0x80067C28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80067C30;
    }
    // 0x80067C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80067C2C: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
L_80067C30:
    // 0x80067C30: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80067C34: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80067C38: jal         0x80068398
    // 0x80067C3C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    viewport_rsp_set(rdram, ctx);
        goto after_4;
    // 0x80067C3C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x80067C40: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80067C44: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80067C48: beq         $a1, $zero, L_80067C60
    if (ctx->r5 == 0) {
        // 0x80067C4C: addiu       $ra, $ra, 0x1264
        ctx->r31 = ADD32(ctx->r31, 0X1264);
            goto L_80067C60;
    }
    // 0x80067C4C: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
    // 0x80067C50: jal         0x80067F7C
    // 0x80067C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80067D3C(rdram, ctx);
        goto after_5;
    // 0x80067C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80067C58: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80067C5C: addiu       $ra, $ra, 0x1264
    ctx->r31 = ADD32(ctx->r31, 0X1264);
L_80067C60:
    // 0x80067C60: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80067C64: nop

    // 0x80067C68: sw          $t7, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r15;
L_80067C6C:
    // 0x80067C6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80067C70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80067C74: jr          $ra
    // 0x80067C78: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80067C78: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8001790C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017940: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80017944: lw          $a2, -0x4A8C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4A8C);
    // 0x80017948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001794C: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
L_80017950:
    // 0x80017950: addu        $v1, $t6, $a2
    ctx->r3 = ADD32(ctx->r14, ctx->r6);
    // 0x80017954: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80017958: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001795C: beq         $t7, $zero, L_80017990
    if (ctx->r15 == 0) {
        // 0x80017960: sll         $t0, $v0, 16
        ctx->r8 = S32(ctx->r2 << 16);
            goto L_80017990;
    }
    // 0x80017960: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80017964: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80017968: nop

    // 0x8001796C: bne         $a0, $t8, L_80017990
    if (ctx->r4 != ctx->r24) {
        // 0x80017970: nop
    
            goto L_80017990;
    }
    // 0x80017970: nop

    // 0x80017974: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80017978: nop

    // 0x8001797C: bne         $a1, $t9, L_80017994
    if (ctx->r5 != ctx->r25) {
        // 0x80017980: sra         $v0, $t0, 16
        ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
            goto L_80017994;
    }
    // 0x80017980: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80017984: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80017988: jr          $ra
    // 0x8001798C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001798C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80017990:
    // 0x80017990: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
L_80017994:
    // 0x80017994: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80017998: bne         $at, $zero, L_80017950
    if (ctx->r1 != 0) {
        // 0x8001799C: sll         $t6, $v0, 6
        ctx->r14 = S32(ctx->r2 << 6);
            goto L_80017950;
    }
    // 0x8001799C: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x800179A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800179A4: jr          $ra
    // 0x800179A8: nop

    return;
    // 0x800179A8: nop

;}
RECOMP_FUNC void load_texture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B2C4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8007B2C8: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8007B2CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007B2D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007B2D4: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8007B2D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007B2DC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007B2E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007B2E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007B2E8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8007B2EC: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8007B2F0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8007B2F4: beq         $t7, $zero, L_8007B308
    if (ctx->r15 == 0) {
        // 0x8007B2F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007B308;
    }
    // 0x8007B2F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007B2FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B300: andi        $t0, $t6, 0x7FFF
    ctx->r8 = ctx->r14 & 0X7FFF;
    // 0x8007B304: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_8007B308:
    // 0x8007B308: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8007B30C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007B310: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x8007B314: lw          $t8, 0x68D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X68D8);
    // 0x8007B318: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B31C: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007B320: beq         $at, $zero, L_8007B330
    if (ctx->r1 == 0) {
        // 0x8007B324: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8007B330;
    }
    // 0x8007B324: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007B328: bgez        $t0, L_8007B334
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007B32C: nop
    
            goto L_8007B334;
    }
    // 0x8007B32C: nop

L_8007B330:
    // 0x8007B330: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007B334:
    // 0x8007B334: lw          $v0, 0x68D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68D0);
    // 0x8007B338: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007B33C: blez        $v0, L_8007B388
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007B340: lui         $s4, 0x8012
        ctx->r20 = S32(0X8012 << 16);
            goto L_8007B388;
    }
    // 0x8007B340: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8007B344: lw          $a0, 0x68C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68C8);
    // 0x8007B348: nop

    // 0x8007B34C: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
L_8007B350:
    // 0x8007B350: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
    // 0x8007B354: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8007B358: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007B35C: bne         $s0, $t3, L_8007B380
    if (ctx->r16 != ctx->r11) {
        // 0x8007B360: slt         $at, $s1, $v0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8007B380;
    }
    // 0x8007B360: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007B364: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8007B368: nop

    // 0x8007B36C: lbu         $t4, 0x5($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X5);
    // 0x8007B370: nop

    // 0x8007B374: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007B378: b           L_8007B6EC
    // 0x8007B37C: sb          $t5, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r13;
        goto L_8007B6EC;
    // 0x8007B37C: sb          $t5, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r13;
L_8007B380:
    // 0x8007B380: bne         $at, $zero, L_8007B350
    if (ctx->r1 != 0) {
        // 0x8007B384: sll         $t2, $s1, 3
        ctx->r10 = S32(ctx->r17 << 3);
            goto L_8007B350;
    }
    // 0x8007B384: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
L_8007B388:
    // 0x8007B388: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007B38C: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8007B390: lw          $t6, 0x68C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68C0);
    // 0x8007B394: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8007B398: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8007B39C: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x8007B3A0: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8007B3A4: addiu       $s4, $s4, 0x690C
    ctx->r20 = ADD32(ctx->r20, 0X690C);
    // 0x8007B3A8: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x8007B3AC: subu        $t9, $t8, $s2
    ctx->r25 = SUB32(ctx->r24, ctx->r18);
    // 0x8007B3B0: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8007B3B4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8007B3B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8007B3BC: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x8007B3C0: jal         0x80077190
    // 0x8007B3C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007B3C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x8007B3C8: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8007B3CC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8007B3D0: lhu         $s1, 0x12($v1)
    ctx->r17 = MEM_HU(ctx->r3, 0X12);
    // 0x8007B3D4: lbu         $t4, 0x1D($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1D);
    // 0x8007B3D8: sra         $t2, $s1, 8
    ctx->r10 = S32(SIGNED(ctx->r17) >> 8);
    // 0x8007B3DC: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8007B3E0: bne         $t4, $zero, L_8007B438
    if (ctx->r12 != 0) {
        // 0x8007B3E4: or          $s1, $t3, $zero
        ctx->r17 = ctx->r11 | 0;
            goto L_8007B438;
    }
    // 0x8007B3E4: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x8007B3E8: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8007B3EC: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x8007B3F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007B3F4: lw          $a1, -0x12C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X12C0);
    // 0x8007B3F8: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x8007B3FC: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x8007B400: jal         0x80070F50
    // 0x8007B404: or          $s4, $t3, $zero
    ctx->r20 = ctx->r11 | 0;
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x8007B404: or          $s4, $t3, $zero
    ctx->r20 = ctx->r11 | 0;
    after_1:
    // 0x8007B408: bne         $v0, $zero, L_8007B418
    if (ctx->r2 != 0) {
        // 0x8007B40C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007B418;
    }
    // 0x8007B40C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8007B410: b           L_8007B6EC
    // 0x8007B414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B6EC;
    // 0x8007B414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B418:
    // 0x8007B418: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007B41C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8007B420: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8007B424: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8007B428: jal         0x80077190
    // 0x8007B42C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    asset_load(rdram, ctx);
        goto after_2;
    // 0x8007B42C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_2:
    // 0x8007B430: b           L_8007B4DC
    // 0x8007B434: nop

        goto L_8007B4DC;
    // 0x8007B434: nop

L_8007B438:
    // 0x8007B438: jal         0x800C670C
    // 0x8007B43C: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    byteswap32(rdram, ctx);
        goto after_3;
    // 0x8007B43C: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    after_3:
    // 0x8007B440: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8007B444: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8007B448: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8007B44C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007B450: addiu       $t7, $v0, 0x20
    ctx->r15 = ADD32(ctx->r2, 0X20);
    // 0x8007B454: lw          $a1, -0x12C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X12C0);
    // 0x8007B458: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    // 0x8007B45C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8007B460: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8007B464: jal         0x80070F50
    // 0x8007B468: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    mempool_alloc(rdram, ctx);
        goto after_4;
    // 0x8007B468: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    after_4:
    // 0x8007B46C: bne         $v0, $zero, L_8007B47C
    if (ctx->r2 != 0) {
        // 0x8007B470: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007B47C;
    }
    // 0x8007B470: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8007B474: b           L_8007B6EC
    // 0x8007B478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B6EC;
    // 0x8007B478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B47C:
    // 0x8007B47C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8007B480: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8007B484: addu        $t2, $s3, $t9
    ctx->r10 = ADD32(ctx->r19, ctx->r25);
    // 0x8007B488: subu        $v0, $t2, $t3
    ctx->r2 = SUB32(ctx->r10, ctx->r11);
    // 0x8007B48C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007B490: bgez        $v0, L_8007B4A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007B494: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_8007B4A4;
    }
    // 0x8007B494: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x8007B498: beq         $t4, $zero, L_8007B4A4
    if (ctx->r12 == 0) {
        // 0x8007B49C: nop
    
            goto L_8007B4A4;
    }
    // 0x8007B49C: nop

    // 0x8007B4A0: addiu       $t4, $t4, -0x10
    ctx->r12 = ADD32(ctx->r12, -0X10);
L_8007B4A4:
    // 0x8007B4A4: subu        $a1, $v0, $t4
    ctx->r5 = SUB32(ctx->r2, ctx->r12);
    // 0x8007B4A8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8007B4AC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8007B4B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007B4B4: jal         0x80077190
    // 0x8007B4B8: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    asset_load(rdram, ctx);
        goto after_5;
    // 0x8007B4B8: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    after_5:
    // 0x8007B4BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8007B4C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8007B4C4: jal         0x800C6778
    // 0x8007B4C8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    gzip_inflate(rdram, ctx);
        goto after_6;
    // 0x8007B4C8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_6:
    // 0x8007B4CC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8007B4D0: nop

    // 0x8007B4D4: addiu       $t6, $t5, -0x20
    ctx->r14 = ADD32(ctx->r13, -0X20);
    // 0x8007B4D8: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_8007B4DC:
    // 0x8007B4DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B4E0: lw          $v0, 0x68D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68D0);
    // 0x8007B4E4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8007B4E8: blez        $v0, L_8007B52C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007B4EC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007B52C;
    }
    // 0x8007B4EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007B4F0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007B4F4: lw          $a0, 0x68C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68C8);
    // 0x8007B4F8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007B4FC: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
L_8007B500:
    // 0x8007B500: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8007B504: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8007B508: nop

    // 0x8007B50C: bne         $v1, $t2, L_8007B518
    if (ctx->r3 != ctx->r10) {
        // 0x8007B510: nop
    
            goto L_8007B518;
    }
    // 0x8007B510: nop

    // 0x8007B514: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
L_8007B518:
    // 0x8007B518: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007B51C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007B520: bne         $at, $zero, L_8007B500
    if (ctx->r1 != 0) {
        // 0x8007B524: sll         $t8, $s1, 3
        ctx->r24 = S32(ctx->r17 << 3);
            goto L_8007B500;
    }
    // 0x8007B524: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x8007B528: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007B52C:
    // 0x8007B52C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007B530: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007B534: lw          $a0, 0x68C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68C8);
    // 0x8007B538: bne         $a1, $v1, L_8007B54C
    if (ctx->r5 != ctx->r3) {
        // 0x8007B53C: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_8007B54C;
    }
    // 0x8007B53C: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8007B540: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B544: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007B548: sw          $t4, 0x68D0($at)
    MEM_W(0X68D0, ctx->r1) = ctx->r12;
L_8007B54C:
    // 0x8007B54C: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8007B550: addu        $t5, $a0, $t3
    ctx->r13 = ADD32(ctx->r4, ctx->r11);
    // 0x8007B554: sw          $s0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r16;
    // 0x8007B558: lw          $t6, 0x68C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68C8);
    // 0x8007B55C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007B560: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x8007B564: sw          $s3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r19;
    // 0x8007B568: lbu         $a2, 0x2($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X2);
    // 0x8007B56C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007B570: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007B574: bne         $t8, $at, L_8007B5F0
    if (ctx->r24 != ctx->r1) {
        // 0x8007B578: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8007B5F0;
    }
    // 0x8007B578: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8007B57C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007B580: addiu       $s2, $s2, 0x68E4
    ctx->r18 = ADD32(ctx->r18, 0X68E4);
    // 0x8007B584: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8007B588: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8007B58C: bne         $t9, $zero, L_8007B5E0
    if (ctx->r25 != 0) {
        // 0x8007B590: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8007B5E0;
    }
    // 0x8007B590: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007B594: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007B598: lw          $t4, 0x68E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X68E0);
    // 0x8007B59C: lw          $t2, 0x68CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X68CC);
    // 0x8007B5A0: lh          $a2, 0x8($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X8);
    // 0x8007B5A4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8007B5A8: jal         0x80077190
    // 0x8007B5AC: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    asset_load(rdram, ctx);
        goto after_7;
    // 0x8007B5AC: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    after_7:
    // 0x8007B5B0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007B5B4: lw          $t3, 0x68E0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X68E0);
    // 0x8007B5B8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8007B5BC: sh          $t3, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r11;
    // 0x8007B5C0: lw          $t5, 0x68E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X68E0);
    // 0x8007B5C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B5C8: addiu       $t6, $t5, 0x20
    ctx->r14 = ADD32(ctx->r13, 0X20);
    // 0x8007B5CC: sw          $t6, 0x68E0($at)
    MEM_W(0X68E0, ctx->r1) = ctx->r14;
    // 0x8007B5D0: lbu         $a2, 0x2($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X2);
    // 0x8007B5D4: nop

    // 0x8007B5D8: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007B5DC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8007B5E0:
    // 0x8007B5E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007B5E4: lw          $v1, 0x68E0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X68E0);
    // 0x8007B5E8: nop

    // 0x8007B5EC: addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
L_8007B5F0:
    // 0x8007B5F0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007B5F4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8007B5F8: bne         $a2, $at, L_8007B654
    if (ctx->r6 != ctx->r1) {
        // 0x8007B5FC: addiu       $s2, $s2, 0x68E4
        ctx->r18 = ADD32(ctx->r18, 0X68E4);
            goto L_8007B654;
    }
    // 0x8007B5FC: addiu       $s2, $s2, 0x68E4
    ctx->r18 = ADD32(ctx->r18, 0X68E4);
    // 0x8007B600: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8007B604: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8007B608: lw          $s0, 0x68E0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X68E0);
    // 0x8007B60C: bne         $t8, $zero, L_8007B650
    if (ctx->r24 != 0) {
        // 0x8007B610: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8007B650;
    }
    // 0x8007B610: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8007B614: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007B618: lw          $t9, 0x68CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X68CC);
    // 0x8007B61C: lh          $a2, 0x8($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X8);
    // 0x8007B620: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x8007B624: jal         0x80077190
    // 0x8007B628: addu        $a1, $t9, $s0
    ctx->r5 = ADD32(ctx->r25, ctx->r16);
    asset_load(rdram, ctx);
        goto after_8;
    // 0x8007B628: addu        $a1, $t9, $s0
    ctx->r5 = ADD32(ctx->r25, ctx->r16);
    after_8:
    // 0x8007B62C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007B630: addiu       $v1, $v1, 0x68E0
    ctx->r3 = ADD32(ctx->r3, 0X68E0);
    // 0x8007B634: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8007B638: nop

    // 0x8007B63C: sh          $t2, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r10;
    // 0x8007B640: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8007B644: nop

    // 0x8007B648: addiu       $s0, $t4, 0x80
    ctx->r16 = ADD32(ctx->r12, 0X80);
    // 0x8007B64C: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
L_8007B650:
    // 0x8007B650: addiu       $v1, $s0, -0x80
    ctx->r3 = ADD32(ctx->r16, -0X80);
L_8007B654:
    // 0x8007B654: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8007B658: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8007B65C: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x8007B660: jal         0x80071A90
    // 0x8007B664: addu        $a0, $s3, $t5
    ctx->r4 = ADD32(ctx->r19, ctx->r13);
    align16(rdram, ctx);
        goto after_9;
    // 0x8007B664: addu        $a0, $s3, $t5
    ctx->r4 = ADD32(ctx->r19, ctx->r13);
    after_9:
    // 0x8007B668: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8007B66C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8007B670: blez        $s4, L_8007B6B0
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8007B674: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_8007B6B0;
    }
    // 0x8007B674: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
L_8007B678:
    // 0x8007B678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B67C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8007B680: jal         0x8007D544
    // 0x8007B684: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    material_init(rdram, ctx);
        goto after_10;
    // 0x8007B684: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    after_10:
    // 0x8007B688: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8007B68C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007B690: bltz        $v1, L_8007B6A0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8007B694: nop
    
            goto L_8007B6A0;
    }
    // 0x8007B694: nop

    // 0x8007B698: sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
    // 0x8007B69C: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
L_8007B6A0:
    // 0x8007B6A0: lh          $t6, 0x16($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16);
    // 0x8007B6A4: addiu       $s2, $s2, 0x60
    ctx->r18 = ADD32(ctx->r18, 0X60);
    // 0x8007B6A8: bne         $s1, $s4, L_8007B678
    if (ctx->r17 != ctx->r20) {
        // 0x8007B6AC: addu        $s0, $s0, $t6
        ctx->r16 = ADD32(ctx->r16, ctx->r14);
            goto L_8007B678;
    }
    // 0x8007B6AC: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_8007B6B0:
    // 0x8007B6B0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007B6B4: lw          $t7, 0x68E0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68E0);
    // 0x8007B6B8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007B6BC: slti        $at, $t7, 0x280
    ctx->r1 = SIGNED(ctx->r15) < 0X280 ? 1 : 0;
    // 0x8007B6C0: bne         $at, $zero, L_8007B6D0
    if (ctx->r1 != 0) {
        // 0x8007B6C4: nop
    
            goto L_8007B6D0;
    }
    // 0x8007B6C4: nop

    // 0x8007B6C8: b           L_8007B6EC
    // 0x8007B6CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B6EC;
    // 0x8007B6CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B6D0:
    // 0x8007B6D0: lw          $t8, 0x68D0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X68D0);
    // 0x8007B6D4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8007B6D8: slti        $at, $t8, 0x2BD
    ctx->r1 = SIGNED(ctx->r24) < 0X2BD ? 1 : 0;
    // 0x8007B6DC: bne         $at, $zero, L_8007B6EC
    if (ctx->r1 != 0) {
        // 0x8007B6E0: nop
    
            goto L_8007B6EC;
    }
    // 0x8007B6E0: nop

    // 0x8007B6E4: b           L_8007B6EC
    // 0x8007B6E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B6EC;
    // 0x8007B6E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B6EC:
    // 0x8007B6EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B6F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007B6F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B6F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007B6FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007B700: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007B704: jr          $ra
    // 0x8007B708: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8007B708: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void input_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A34C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006A350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A354: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A358: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006A35C: addiu       $a1, $a1, 0x1678
    ctx->r5 = ADD32(ctx->r5, 0X1678);
    // 0x8006A360: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    // 0x8006A364: jal         0x800C8D80
    // 0x8006A368: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A368: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8006A36C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A370: lw          $a2, 0x167C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X167C);
    // 0x8006A374: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006A378: addiu       $a1, $a1, 0x1660
    ctx->r5 = ADD32(ctx->r5, 0X1660);
    // 0x8006A37C: jal         0x800CD110
    // 0x8006A380: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A380: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x8006A384: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A388: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A38C: addiu       $a2, $a2, 0x1680
    ctx->r6 = ADD32(ctx->r6, 0X1680);
    // 0x8006A390: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    // 0x8006A394: jal         0x800CD180
    // 0x8006A398: addiu       $a1, $sp, 0x23
    ctx->r5 = ADD32(ctx->r29, 0X23);
    osContInit_recomp(rdram, ctx);
        goto after_2;
    // 0x8006A398: addiu       $a1, $sp, 0x23
    ctx->r5 = ADD32(ctx->r29, 0X23);
    after_2:
    // 0x8006A39C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A3A0: jal         0x800CD540
    // 0x8006A3A4: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    osContStartReadData_recomp(rdram, ctx);
        goto after_3;
    // 0x8006A3A4: addiu       $a0, $a0, 0x1660
    ctx->r4 = ADD32(ctx->r4, 0X1660);
    after_3:
    // 0x8006A3A8: jal         0x8006A674
    // 0x8006A3AC: nop

    input_assign_players(rdram, ctx);
        goto after_4;
    // 0x8006A3AC: nop

    after_4:
    // 0x8006A3B0: lbu         $v0, 0x23($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X23);
    // 0x8006A3B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006A3B8: addiu       $v1, $v1, -0x2790
    ctx->r3 = ADD32(ctx->r3, -0X2790);
    // 0x8006A3BC: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8006A3C0: beq         $t6, $zero, L_8006A3E8
    if (ctx->r14 == 0) {
        // 0x8006A3C4: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8006A3E8;
    }
    // 0x8006A3C4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8006A3C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006A3CC: lbu         $t7, 0x1683($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1683);
    // 0x8006A3D0: nop

    // 0x8006A3D4: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8006A3D8: bne         $t8, $zero, L_8006A3EC
    if (ctx->r24 != 0) {
        // 0x8006A3DC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8006A3EC;
    }
    // 0x8006A3DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006A3E0: b           L_8006A3F4
    // 0x8006A3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A3F4;
    // 0x8006A3E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A3E8:
    // 0x8006A3E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_8006A3EC:
    // 0x8006A3EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006A3F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006A3F4:
    // 0x8006A3F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A3F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006A3FC: jr          $ra
    // 0x8006A400: nop

    return;
    // 0x8006A400: nop

;}
RECOMP_FUNC void calc_and_alloc_heap_for_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E5FC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006E600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E604: jal         0x8006A8F0
    // 0x8006E608: nop

    level_global_init(rdram, ctx);
        goto after_0;
    // 0x8006E608: nop

    after_0:
    // 0x8006E60C: jal         0x8009C698
    // 0x8006E610: nop

    reset_character_id_slots(rdram, ctx);
        goto after_1;
    // 0x8006E610: nop

    after_1:
    // 0x8006E614: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006E618: jal         0x8006B464
    // 0x8006E61C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    level_count(rdram, ctx);
        goto after_2;
    // 0x8006E61C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8006E620: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8006E624: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E628: addiu       $v1, $zero, 0x118
    ctx->r3 = ADD32(0, 0X118);
    // 0x8006E62C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8006E630: addu        $a2, $v1, $t6
    ctx->r6 = ADD32(ctx->r3, ctx->r14);
    // 0x8006E634: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8006E638: addu        $t0, $a2, $t8
    ctx->r8 = ADD32(ctx->r6, ctx->r24);
    // 0x8006E63C: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x8006E640: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8006E644: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8006E648: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8006E64C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8006E650: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8006E654: addu        $ra, $t5, $v0
    ctx->r31 = ADD32(ctx->r13, ctx->r2);
    // 0x8006E658: addu        $t9, $ra, $v0
    ctx->r25 = ADD32(ctx->r31, ctx->r2);
    // 0x8006E65C: addu        $t7, $t9, $v0
    ctx->r15 = ADD32(ctx->r25, ctx->r2);
    // 0x8006E660: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8006E664: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8006E668: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8006E66C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8006E670: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    // 0x8006E674: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8006E678: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8006E67C: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x8006E680: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x8006E684: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8006E688: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8006E68C: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8006E690: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8006E694: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8006E698: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8006E69C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8006E6A0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8006E6A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8006E6A8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8006E6AC: jal         0x80070EDC
    // 0x8006E6B0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8006E6B0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x8006E6B4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8006E6B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006E6BC: addiu       $a0, $a0, 0x3A90
    ctx->r4 = ADD32(ctx->r4, 0X3A90);
    // 0x8006E6C0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8006E6C4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8006E6C8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006E6CC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E6D0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8006E6D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006E6D8: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8006E6DC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006E6E0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8006E6E4: nop

    // 0x8006E6E8: sh          $zero, 0x14($t8)
    MEM_H(0X14, ctx->r24) = 0;
    // 0x8006E6EC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E6F0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8006E6F4: nop

    // 0x8006E6F8: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E6FC: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
    // 0x8006E700: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E704: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E708: nop

    // 0x8006E70C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E710: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x8006E714: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E718: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8006E71C: nop

    // 0x8006E720: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E724: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
    // 0x8006E728: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E72C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8006E730: nop

    // 0x8006E734: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E738: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x8006E73C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E740: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006E744: nop

    // 0x8006E748: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E74C: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
    // 0x8006E750: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E754: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8006E758: nop

    // 0x8006E75C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E760: sw          $t8, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r24;
    // 0x8006E764: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E768: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8006E76C: nop

    // 0x8006E770: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E774: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x8006E778: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E77C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8006E780: nop

    // 0x8006E784: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E788: sw          $t8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r24;
    // 0x8006E78C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E790: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8006E794: nop

    // 0x8006E798: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E79C: sw          $t6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r14;
    // 0x8006E7A0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E7A4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8006E7A8: nop

    // 0x8006E7AC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E7B0: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
    // 0x8006E7B4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E7B8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8006E7BC: nop

    // 0x8006E7C0: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E7C4: sw          $t6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r14;
    // 0x8006E7C8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E7CC: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8006E7D0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006E7D4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E7D8: sw          $t8, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r24;
    // 0x8006E7DC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8006E7E0: addiu       $t9, $t9, 0x17D0
    ctx->r25 = ADD32(ctx->r25, 0X17D0);
    // 0x8006E7E4: sw          $t9, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->r25;
    // 0x8006E7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E7EC: addiu       $t7, $zero, 0x107
    ctx->r15 = ADD32(0, 0X107);
    // 0x8006E7F0: sw          $t7, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r15;
    // 0x8006E7F4: jr          $ra
    // 0x8006E7F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006E7F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void sound_distance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001CB8: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80001CBC: lw          $t7, 0x62A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62A0);
    // 0x80001CC0: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001CC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80001CC8: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80001CCC: beq         $at, $zero, L_80001CDC
    if (ctx->r1 == 0) {
        // 0x80001CD0: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80001CDC;
    }
    // 0x80001CD0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80001CD4: jr          $ra
    // 0x80001CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80001CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80001CDC:
    // 0x80001CDC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001CE0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80001CE4: lw          $t8, 0x6298($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6298);
    // 0x80001CE8: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x80001CEC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80001CF0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80001CF4: lhu         $v0, 0x6($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6);
    // 0x80001CF8: nop

    // 0x80001CFC: jr          $ra
    // 0x80001D00: nop

    return;
    // 0x80001D00: nop

;}
RECOMP_FUNC void obj_door_open(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80023608: jr          $ra
    // 0x8002360C: sb          $a0, -0x4CAB($at)
    MEM_B(-0X4CAB, ctx->r1) = ctx->r4;
    return;
    // 0x8002360C: sb          $a0, -0x4CAB($at)
    MEM_B(-0X4CAB, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void free_particle_buffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE8D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE8D8: lw          $a0, 0x3238($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3238);
    // 0x800AE8DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE8E0: beq         $a0, $zero, L_800AE8F8
    if (ctx->r4 == 0) {
        // 0x800AE8E4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE8F8;
    }
    // 0x800AE8E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE8E8: jal         0x80071380
    // 0x800AE8EC: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AE8EC: nop

    after_0:
    // 0x800AE8F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE8F4: sw          $zero, 0x3238($at)
    MEM_W(0X3238, ctx->r1) = 0;
L_800AE8F8:
    // 0x800AE8F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE8FC: lw          $a0, 0x3244($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3244);
    // 0x800AE900: nop

    // 0x800AE904: beq         $a0, $zero, L_800AE91C
    if (ctx->r4 == 0) {
        // 0x800AE908: nop
    
            goto L_800AE91C;
    }
    // 0x800AE908: nop

    // 0x800AE90C: jal         0x80071380
    // 0x800AE910: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AE910: nop

    after_1:
    // 0x800AE914: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE918: sw          $zero, 0x3244($at)
    MEM_W(0X3244, ctx->r1) = 0;
L_800AE91C:
    // 0x800AE91C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE920: lw          $a0, 0x3250($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3250);
    // 0x800AE924: nop

    // 0x800AE928: beq         $a0, $zero, L_800AE940
    if (ctx->r4 == 0) {
        // 0x800AE92C: nop
    
            goto L_800AE940;
    }
    // 0x800AE92C: nop

    // 0x800AE930: jal         0x80071380
    // 0x800AE934: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800AE934: nop

    after_2:
    // 0x800AE938: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE93C: sw          $zero, 0x3250($at)
    MEM_W(0X3250, ctx->r1) = 0;
L_800AE940:
    // 0x800AE940: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE944: lw          $a0, 0x325C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X325C);
    // 0x800AE948: nop

    // 0x800AE94C: beq         $a0, $zero, L_800AE964
    if (ctx->r4 == 0) {
        // 0x800AE950: nop
    
            goto L_800AE964;
    }
    // 0x800AE950: nop

    // 0x800AE954: jal         0x80071380
    // 0x800AE958: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800AE958: nop

    after_3:
    // 0x800AE95C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE960: sw          $zero, 0x325C($at)
    MEM_W(0X325C, ctx->r1) = 0;
L_800AE964:
    // 0x800AE964: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE968: lw          $a0, 0x3268($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3268);
    // 0x800AE96C: nop

    // 0x800AE970: beq         $a0, $zero, L_800AE98C
    if (ctx->r4 == 0) {
        // 0x800AE974: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AE98C;
    }
    // 0x800AE974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE978: jal         0x80071380
    // 0x800AE97C: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800AE97C: nop

    after_4:
    // 0x800AE980: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE984: sw          $zero, 0x3268($at)
    MEM_W(0X3268, ctx->r1) = 0;
    // 0x800AE988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AE98C:
    // 0x800AE98C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE990: jr          $ra
    // 0x800AE994: nop

    return;
    // 0x800AE994: nop

;}
RECOMP_FUNC void fb_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ADDC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007ADE0: addiu       $v1, $v1, 0x6870
    ctx->r3 = ADD32(ctx->r3, 0X6870);
    // 0x8007ADE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007ADE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8007ADEC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007ADF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007ADF4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007ADF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007ADFC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007AE00: beq         $v0, $zero, L_8007AE1C
    if (ctx->r2 == 0) {
        // 0x8007AE04: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8007AE1C;
    }
    // 0x8007AE04: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8007AE08: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8007AE0C: bne         $t6, $zero, L_8007AE1C
    if (ctx->r14 != 0) {
        // 0x8007AE10: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8007AE1C;
    }
    // 0x8007AE10: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007AE14: jal         0x800D2270
    // 0x8007AE18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_0;
    // 0x8007AE18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
L_8007AE1C:
    // 0x8007AE1C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8007AE20: beq         $s1, $at, L_8007AE30
    if (ctx->r17 == ctx->r1) {
        // 0x8007AE24: nop
    
            goto L_8007AE30;
    }
    // 0x8007AE24: nop

    // 0x8007AE28: jal         0x8007AFEC
    // 0x8007AE2C: nop

    fb_swap(rdram, ctx);
        goto after_1;
    // 0x8007AE2C: nop

    after_1:
L_8007AE30:
    // 0x8007AE30: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007AE34: addiu       $s2, $s2, 0x6740
    ctx->r18 = ADD32(ctx->r18, 0X6740);
    // 0x8007AE38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007AE3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007AE40: jal         0x800C9110
    // 0x8007AE44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8007AE44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8007AE48: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8007AE4C: beq         $v0, $s1, L_8007AE78
    if (ctx->r2 == ctx->r17) {
        // 0x8007AE50: nop
    
            goto L_8007AE78;
    }
    // 0x8007AE50: nop

L_8007AE54:
    // 0x8007AE54: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007AE58: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x8007AE5C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8007AE60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007AE64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007AE68: jal         0x800C9110
    // 0x8007AE6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8007AE6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8007AE70: bne         $v0, $s1, L_8007AE54
    if (ctx->r2 != ctx->r17) {
        // 0x8007AE74: nop
    
            goto L_8007AE54;
    }
    // 0x8007AE74: nop

L_8007AE78:
    // 0x8007AE78: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8007AE7C: addiu       $s1, $s1, 0x68A9
    ctx->r17 = ADD32(ctx->r17, 0X68A9);
    // 0x8007AE80: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8007AE84: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007AE88: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007AE8C: beq         $at, $zero, L_8007AED8
    if (ctx->r1 == 0) {
        // 0x8007AE90: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8007AED8;
    }
    // 0x8007AE90: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007AE94: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007AE98: addiu       $a2, $a2, 0x68A8
    ctx->r6 = ADD32(ctx->r6, 0X68A8);
    // 0x8007AE9C: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x8007AEA0: nop

    // 0x8007AEA4: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // 0x8007AEA8: beq         $at, $zero, L_8007AEBC
    if (ctx->r1 == 0) {
        // 0x8007AEAC: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8007AEBC;
    }
    // 0x8007AEAC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8007AEB0: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x8007AEB4: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x8007AEB8: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
L_8007AEBC:
    // 0x8007AEBC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8007AEC0: bne         $v0, $at, L_8007AF0C
    if (ctx->r2 != ctx->r1) {
        // 0x8007AEC4: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007AF0C;
    }
    // 0x8007AEC4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007AEC8: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    // 0x8007AECC: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8007AED0: b           L_8007AF08
    // 0x8007AED4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
        goto L_8007AF08;
    // 0x8007AED4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_8007AED8:
    // 0x8007AED8: addiu       $a2, $a2, 0x68A8
    ctx->r6 = ADD32(ctx->r6, 0X68A8);
    // 0x8007AEDC: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007AEE0: beq         $at, $zero, L_8007AF08
    if (ctx->r1 == 0) {
        // 0x8007AEE4: sb          $zero, 0x0($a2)
        MEM_B(0X0, ctx->r6) = 0;
            goto L_8007AF08;
    }
    // 0x8007AEE4: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8007AEE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007AEEC: lbu         $t0, 0x6884($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X6884);
    // 0x8007AEF0: nop

    // 0x8007AEF4: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007AEF8: bne         $at, $zero, L_8007AF0C
    if (ctx->r1 != 0) {
        // 0x8007AEFC: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007AF0C;
    }
    // 0x8007AEFC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007AF00: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    // 0x8007AF04: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_8007AF08:
    // 0x8007AF08: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_8007AF0C:
    // 0x8007AF0C: beq         $at, $zero, L_8007AF38
    if (ctx->r1 == 0) {
        // 0x8007AF10: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007AF38;
    }
L_8007AF10:
    // 0x8007AF10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007AF14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007AF18: jal         0x800C9110
    // 0x8007AF1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8007AF1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8007AF20: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x8007AF24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007AF28: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x8007AF2C: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007AF30: bne         $at, $zero, L_8007AF10
    if (ctx->r1 != 0) {
        // 0x8007AF34: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_8007AF10;
    }
    // 0x8007AF34: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_8007AF38:
    // 0x8007AF38: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007AF3C: lw          $a0, 0x6878($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6878);
    // 0x8007AF40: jal         0x800D2980
    // 0x8007AF44: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_5;
    // 0x8007AF44: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_5:
    // 0x8007AF48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007AF4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007AF50: jal         0x800C9110
    // 0x8007AF54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x8007AF54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8007AF58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007AF5C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8007AF60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007AF64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007AF68: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007AF6C: jr          $ra
    // 0x8007AF70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007AF70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void debug_text_bounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B73B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B73B4: lhu         $v0, -0x7D70($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7D70);
    // 0x800B73B8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800B73BC: slti        $at, $v0, 0x141
    ctx->r1 = SIGNED(ctx->r2) < 0X141 ? 1 : 0;
    // 0x800B73C0: beq         $at, $zero, L_800B73E4
    if (ctx->r1 == 0) {
        // 0x800B73C4: addiu       $t9, $v0, -0x20
        ctx->r25 = ADD32(ctx->r2, -0X20);
            goto L_800B73E4;
    }
    // 0x800B73C4: addiu       $t9, $v0, -0x20
    ctx->r25 = ADD32(ctx->r2, -0X20);
    // 0x800B73C8: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800B73CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B73D0: sw          $t6, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = ctx->r14;
    // 0x800B73D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B73D8: addiu       $t7, $v0, -0x10
    ctx->r15 = ADD32(ctx->r2, -0X10);
    // 0x800B73DC: b           L_800B73F4
    // 0x800B73E0: sw          $t7, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = ctx->r15;
        goto L_800B73F4;
    // 0x800B73E0: sw          $t7, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = ctx->r15;
L_800B73E4:
    // 0x800B73E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B73E8: sw          $t8, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = ctx->r24;
    // 0x800B73EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B73F0: sw          $t9, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = ctx->r25;
L_800B73F4:
    // 0x800B73F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B73F8: lhu         $v0, -0x7D6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7D6E);
    // 0x800B73FC: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x800B7400: slti        $at, $v0, 0xF1
    ctx->r1 = SIGNED(ctx->r2) < 0XF1 ? 1 : 0;
    // 0x800B7404: beq         $at, $zero, L_800B7428
    if (ctx->r1 == 0) {
        // 0x800B7408: addiu       $t3, $v0, -0x20
        ctx->r11 = ADD32(ctx->r2, -0X20);
            goto L_800B7428;
    }
    // 0x800B7408: addiu       $t3, $v0, -0x20
    ctx->r11 = ADD32(ctx->r2, -0X20);
    // 0x800B740C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800B7410: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7414: sw          $t0, -0x7D7C($at)
    MEM_W(-0X7D7C, ctx->r1) = ctx->r8;
    // 0x800B7418: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B741C: addiu       $t1, $v0, -0x10
    ctx->r9 = ADD32(ctx->r2, -0X10);
    // 0x800B7420: jr          $ra
    // 0x800B7424: sw          $t1, -0x7D78($at)
    MEM_W(-0X7D78, ctx->r1) = ctx->r9;
    return;
    // 0x800B7424: sw          $t1, -0x7D78($at)
    MEM_W(-0X7D78, ctx->r1) = ctx->r9;
L_800B7428:
    // 0x800B7428: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B742C: sw          $t2, -0x7D7C($at)
    MEM_W(-0X7D7C, ctx->r1) = ctx->r10;
    // 0x800B7430: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7434: sw          $t3, -0x7D78($at)
    MEM_W(-0X7D78, ctx->r1) = ctx->r11;
    // 0x800B7438: jr          $ra
    // 0x800B743C: nop

    return;
    // 0x800B743C: nop

;}
RECOMP_FUNC void dmacopy_doubleword(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_80070D44:
    // 0x80070D44: ld          $t0, 0x0($a0)
    ctx->r8 = LD(ctx->r4, 0X0);
    // 0x80070D48: ld          $t1, 0x8($a0)
    ctx->r9 = LD(ctx->r4, 0X8);
    // 0x80070D4C: addi        $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80070D50: addi        $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80070D54: sd          $t0, -0x10($a1)
    SD(ctx->r8, -0X10, ctx->r5);
    // 0x80070D58: bne         $a1, $a2, L_80070D44
    if (ctx->r5 != ctx->r6) {
        // 0x80070D5C: sd          $t1, -0x8($a1)
        SD(ctx->r9, -0X8, ctx->r5);
            goto L_80070D44;
    }
    // 0x80070D5C: sd          $t1, -0x8($a1)
    SD(ctx->r9, -0X8, ctx->r5);
    // 0x80070D60: jr          $ra
    // 0x80070D64: nop

    return;
    // 0x80070D64: nop

;}
RECOMP_FUNC void timetrial_valid_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B2BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B2C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B2C4: jal         0x800599F8
    // 0x8001B2C8: nop

    timetrial_map_id(rdram, ctx);
        goto after_0;
    // 0x8001B2C8: nop

    after_0:
    // 0x8001B2CC: jal         0x8006BFC8
    // 0x8001B2D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_1;
    // 0x8001B2D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001B2D4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B2DC: beq         $v0, $t6, L_8001B2EC
    if (ctx->r2 == ctx->r14) {
        // 0x8001B2E0: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8001B2EC;
    }
    // 0x8001B2E0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B2E4: b           L_8001B30C
    // 0x8001B2E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B30C;
    // 0x8001B2E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B2EC:
    // 0x8001B2EC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001B2F0: lh          $t8, -0x3368($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3368);
    // 0x8001B2F4: lh          $t7, -0x4BFE($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X4BFE);
    // 0x8001B2F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B2FC: beq         $t7, $t8, L_8001B30C
    if (ctx->r15 == ctx->r24) {
        // 0x8001B300: nop
    
            goto L_8001B30C;
    }
    // 0x8001B300: nop

    // 0x8001B304: b           L_8001B30C
    // 0x8001B308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B30C;
    // 0x8001B308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B30C:
    // 0x8001B30C: jr          $ra
    // 0x8001B310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001B310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_init_animobject(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EFD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001EFDC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001EFE0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001EFE4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001EFE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001EFEC: lw          $s1, 0x3C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X3C);
    // 0x8001EFF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EFF4: lbu         $t7, 0xB($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XB);
    // 0x8001EFF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001EFFC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8001F000: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8001F004: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F008: lw          $s0, 0x64($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X64);
    // 0x8001F00C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001F010: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001F014: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8001F018: bc1f        L_8001F028
    if (!c1cs) {
        // 0x8001F01C: nop
    
            goto L_8001F028;
    }
    // 0x8001F01C: nop

    // 0x8001F020: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001F024: nop

L_8001F028:
    // 0x8001F028: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001F02C: lw          $t8, 0x40($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X40);
    // 0x8001F030: nop

    // 0x8001F034: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8001F038: sw          $zero, 0x78($a1)
    MEM_W(0X78, ctx->r5) = 0;
    // 0x8001F03C: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
    // 0x8001F040: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001F044: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    // 0x8001F048: lb          $v0, 0x22($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X22);
    // 0x8001F04C: nop

    // 0x8001F050: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8001F054: bne         $at, $zero, L_8001F070
    if (ctx->r1 != 0) {
        // 0x8001F058: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8001F070;
    }
    // 0x8001F058: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001F05C: beq         $at, $zero, L_8001F070
    if (ctx->r1 == 0) {
        // 0x8001F060: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8001F070;
    }
    // 0x8001F060: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8001F064: sw          $t9, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r25;
    // 0x8001F068: lb          $v0, 0x22($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X22);
    // 0x8001F06C: nop

L_8001F070:
    // 0x8001F070: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001F074: bne         $at, $zero, L_8001F088
    if (ctx->r1 != 0) {
        // 0x8001F078: slti        $at, $v0, 0x12
        ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
            goto L_8001F088;
    }
    // 0x8001F078: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x8001F07C: beq         $at, $zero, L_8001F088
    if (ctx->r1 == 0) {
        // 0x8001F080: addiu       $t0, $v0, -0x9
        ctx->r8 = ADD32(ctx->r2, -0X9);
            goto L_8001F088;
    }
    // 0x8001F080: addiu       $t0, $v0, -0x9
    ctx->r8 = ADD32(ctx->r2, -0X9);
    // 0x8001F084: sw          $t0, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r8;
L_8001F088:
    // 0x8001F088: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8001F08C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001F090: swc1        $f16, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f16.u32l;
    // 0x8001F094: lwc1        $f18, 0x10($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8001F098: nop

    // 0x8001F09C: swc1        $f18, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f18.u32l;
    // 0x8001F0A0: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8001F0A4: nop

    // 0x8001F0A8: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
    // 0x8001F0AC: lh          $t1, 0x0($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X0);
    // 0x8001F0B0: nop

    // 0x8001F0B4: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x8001F0B8: lh          $t2, 0x4($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X4);
    // 0x8001F0BC: nop

    // 0x8001F0C0: sh          $t2, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r10;
    // 0x8001F0C4: lh          $t3, 0x2($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X2);
    // 0x8001F0C8: nop

    // 0x8001F0CC: sh          $t3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r11;
    // 0x8001F0D0: sh          $zero, 0x26($s0)
    MEM_H(0X26, ctx->r16) = 0;
    // 0x8001F0D4: lb          $t4, 0x21($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X21);
    // 0x8001F0D8: nop

    // 0x8001F0DC: sb          $t4, 0x3D($s0)
    MEM_B(0X3D, ctx->r16) = ctx->r12;
    // 0x8001F0E0: lb          $t5, 0x10($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X10);
    // 0x8001F0E4: nop

    // 0x8001F0E8: sh          $t5, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r13;
    // 0x8001F0EC: lb          $t6, 0x14($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X14);
    // 0x8001F0F0: lwc1        $f16, 0x5BFC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5BFC);
    // 0x8001F0F4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8001F0F8: lwc1        $f17, 0x5BF8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X5BF8);
    // 0x8001F0FC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F100: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8001F104: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8001F108: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8001F10C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8001F110: lh          $a0, 0xE($s1)
    ctx->r4 = MEM_H(ctx->r17, 0XE);
    // 0x8001F114: jal         0x8000C8B4
    // 0x8001F118: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    normalise_time(rdram, ctx);
        goto after_0;
    // 0x8001F118: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001F11C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F120: sh          $v0, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r2;
    // 0x8001F124: lb          $t7, 0x12($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X12);
    // 0x8001F128: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001F12C: sb          $t7, 0x3B($a1)
    MEM_B(0X3B, ctx->r5) = ctx->r15;
    // 0x8001F130: lbu         $t8, 0x16($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X16);
    // 0x8001F134: nop

    // 0x8001F138: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x8001F13C: lb          $t9, 0x17($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X17);
    // 0x8001F140: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8001F144: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8001F148: nop

    // 0x8001F14C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F150: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8001F154: lbu         $t0, 0x18($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X18);
    // 0x8001F158: nop

    // 0x8001F15C: sb          $t0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r8;
    // 0x8001F160: lbu         $t1, 0x19($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X19);
    // 0x8001F164: nop

    // 0x8001F168: sb          $t1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r9;
    // 0x8001F16C: lb          $t2, 0x2C($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X2C);
    // 0x8001F170: nop

    // 0x8001F174: sb          $t2, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r10;
    // 0x8001F178: lb          $t3, 0x2D($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X2D);
    // 0x8001F17C: nop

    // 0x8001F180: sb          $t3, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r11;
    // 0x8001F184: lb          $t4, 0x1A($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X1A);
    // 0x8001F188: nop

    // 0x8001F18C: sb          $t4, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r12;
    // 0x8001F190: lb          $t5, 0x1B($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X1B);
    // 0x8001F194: nop

    // 0x8001F198: sb          $t5, 0x32($s0)
    MEM_B(0X32, ctx->r16) = ctx->r13;
    // 0x8001F19C: lb          $t6, 0x1C($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1C);
    // 0x8001F1A0: nop

    // 0x8001F1A4: sb          $t6, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r14;
    // 0x8001F1A8: lb          $t7, 0x20($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X20);
    // 0x8001F1AC: sb          $zero, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = 0;
    // 0x8001F1B0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8001F1B4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8001F1B8: sb          $t7, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r15;
    // 0x8001F1BC: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
    // 0x8001F1C0: lh          $a0, 0x24($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X24);
    // 0x8001F1C4: jal         0x8000C8B4
    // 0x8001F1C8: nop

    normalise_time(rdram, ctx);
        goto after_1;
    // 0x8001F1C8: nop

    after_1:
    // 0x8001F1CC: sh          $v0, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r2;
    // 0x8001F1D0: lb          $t8, 0x26($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X26);
    // 0x8001F1D4: nop

    // 0x8001F1D8: sb          $t8, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r24;
    // 0x8001F1DC: lb          $v1, 0x13($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X13);
    // 0x8001F1E0: nop

    // 0x8001F1E4: bltz        $v1, L_8001F1F0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8001F1E8: nop
    
            goto L_8001F1F0;
    }
    // 0x8001F1E8: nop

    // 0x8001F1EC: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
L_8001F1F0:
    // 0x8001F1F0: lb          $t9, 0x1F($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1F);
    // 0x8001F1F4: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x8001F1F8: sb          $t9, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r25;
    // 0x8001F1FC: lbu         $t0, 0x1E($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1E);
    // 0x8001F200: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8001F204: sb          $t0, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r8;
    // 0x8001F208: lb          $t1, 0x29($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X29);
    // 0x8001F20C: nop

    // 0x8001F210: sb          $t1, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r9;
    // 0x8001F214: lb          $t2, 0x2E($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X2E);
    // 0x8001F218: nop

    // 0x8001F21C: sb          $t2, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r10;
    // 0x8001F220: lb          $t3, 0x2F($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X2F);
    // 0x8001F224: nop

    // 0x8001F228: sb          $t3, 0x41($s0)
    MEM_B(0X41, ctx->r16) = ctx->r11;
    // 0x8001F22C: lb          $t4, 0x2B($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X2B);
    // 0x8001F230: sb          $t5, 0x42($s0)
    MEM_B(0X42, ctx->r16) = ctx->r13;
    // 0x8001F234: beq         $a0, $zero, L_8001F244
    if (ctx->r4 == 0) {
        // 0x8001F238: sb          $t4, 0x3C($s0)
        MEM_B(0X3C, ctx->r16) = ctx->r12;
            goto L_8001F244;
    }
    // 0x8001F238: sb          $t4, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r12;
    // 0x8001F23C: jal         0x8000488C
    // 0x8001F240: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x8001F240: nop

    after_2:
L_8001F244:
    // 0x8001F244: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8001F248: lb          $t6, 0x30($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X30);
    // 0x8001F24C: sw          $s2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r18;
    // 0x8001F250: sb          $zero, 0x45($s0)
    MEM_B(0X45, ctx->r16) = 0;
    // 0x8001F254: sb          $t6, 0x43($s0)
    MEM_B(0X43, ctx->r16) = ctx->r14;
    // 0x8001F258: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001F25C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001F260: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001F268: jr          $ra
    // 0x8001F26C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001F26C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_trigger_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B03BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800B03C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B03C4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800B03C8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800B03CC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B03D0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B03D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B03D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B03DC: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x800B03E0: lw          $s4, 0x0($a1)
    ctx->r20 = MEM_W(ctx->r5, 0X0);
    // 0x800B03E4: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x800B03E8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800B03EC: beq         $t6, $zero, L_800B043C
    if (ctx->r14 == 0) {
        // 0x800B03F0: or          $s5, $a0, $zero
        ctx->r21 = ctx->r4 | 0;
            goto L_800B043C;
    }
    // 0x800B03F0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800B03F4: jal         0x800B110C
    // 0x800B03F8: nop

    create_line_particle(rdram, ctx);
        goto after_0;
    // 0x800B03F8: nop

    after_0:
    // 0x800B03FC: beq         $v0, $zero, L_800B040C
    if (ctx->r2 == 0) {
        // 0x800B0400: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800B040C;
    }
    // 0x800B0400: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B0404: jal         0x8000E9D0
    // 0x800B0408: nop

    add_particle_to_entity_list(rdram, ctx);
        goto after_1;
    // 0x800B0408: nop

    after_1:
L_800B040C:
    // 0x800B040C: lbu         $v0, 0x6($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X6);
    // 0x800B0410: lh          $t7, 0x4($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X4);
    // 0x800B0414: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800B0418: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800B041C: andi        $t8, $t7, 0xDFFF
    ctx->r24 = ctx->r15 & 0XDFFF;
    // 0x800B0420: bne         $at, $zero, L_800B0434
    if (ctx->r1 != 0) {
        // 0x800B0424: sh          $t8, 0x4($s2)
        MEM_H(0X4, ctx->r18) = ctx->r24;
            goto L_800B0434;
    }
    // 0x800B0424: sh          $t8, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r24;
    // 0x800B0428: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800B042C: b           L_800B054C
    // 0x800B0430: sb          $t9, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r25;
        goto L_800B054C;
    // 0x800B0430: sb          $t9, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r25;
L_800B0434:
    // 0x800B0434: b           L_800B054C
    // 0x800B0438: sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
        goto L_800B054C;
    // 0x800B0438: sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
L_800B043C:
    // 0x800B043C: andi        $t0, $v0, 0x400
    ctx->r8 = ctx->r2 & 0X400;
    // 0x800B0440: beq         $t0, $zero, L_800B04C0
    if (ctx->r8 == 0) {
        // 0x800B0444: nop
    
            goto L_800B04C0;
    }
    // 0x800B0444: nop

    // 0x800B0448: lbu         $t1, 0x6($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X6);
    // 0x800B044C: lbu         $t2, 0x7($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X7);
    // 0x800B0450: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B0454: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B0458: beq         $at, $zero, L_800B0550
    if (ctx->r1 == 0) {
        // 0x800B045C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800B0550;
    }
    // 0x800B045C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0460: jal         0x800B0BF8
    // 0x800B0464: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    create_point_particle(rdram, ctx);
        goto after_2;
    // 0x800B0464: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800B0468: lh          $t3, 0x4($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X4);
    // 0x800B046C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B0470: andi        $t4, $t3, 0xDFFF
    ctx->r12 = ctx->r11 & 0XDFFF;
    // 0x800B0474: beq         $v0, $zero, L_800B054C
    if (ctx->r2 == 0) {
        // 0x800B0478: sh          $t4, 0x4($s2)
        MEM_H(0X4, ctx->r18) = ctx->r12;
            goto L_800B054C;
    }
    // 0x800B0478: sh          $t4, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r12;
    // 0x800B047C: jal         0x8000E9D0
    // 0x800B0480: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    add_particle_to_entity_list(rdram, ctx);
        goto after_3;
    // 0x800B0480: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800B0484: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x800B0488: lbu         $t5, 0x6($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X6);
    // 0x800B048C: ori         $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 | 0X2000;
    // 0x800B0490: sw          $t7, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r15;
    // 0x800B0494: sb          $t5, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r13;
    // 0x800B0498: lbu         $t9, 0x6($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X6);
    // 0x800B049C: lw          $t8, 0xC($s2)
    ctx->r24 = MEM_W(ctx->r18, 0XC);
    // 0x800B04A0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800B04A4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800B04A8: sw          $s0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r16;
    // 0x800B04AC: lbu         $t2, 0x6($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X6);
    // 0x800B04B0: nop

    // 0x800B04B4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B04B8: b           L_800B054C
    // 0x800B04BC: sb          $t3, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r11;
        goto L_800B054C;
    // 0x800B04BC: sb          $t3, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r11;
L_800B04C0:
    // 0x800B04C0: lh          $v0, 0xA($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA);
    // 0x800B04C4: lh          $v1, 0x40($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X40);
    // 0x800B04C8: addiu       $s3, $zero, -0x2001
    ctx->r19 = ADD32(0, -0X2001);
    // 0x800B04CC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B04D0: bne         $at, $zero, L_800B054C
    if (ctx->r1 != 0) {
        // 0x800B04D4: subu        $t4, $v0, $v1
        ctx->r12 = SUB32(ctx->r2, ctx->r3);
            goto L_800B054C;
    }
    // 0x800B04D4: subu        $t4, $v0, $v1
    ctx->r12 = SUB32(ctx->r2, ctx->r3);
L_800B04D8:
    // 0x800B04D8: sh          $t4, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r12;
    // 0x800B04DC: lh          $t5, 0x42($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X42);
    // 0x800B04E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800B04E4: blez        $t5, L_800B0534
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800B04E8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800B0534;
    }
    // 0x800B04E8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B04EC:
    // 0x800B04EC: jal         0x800B1690
    // 0x800B04F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    create_general_particle(rdram, ctx);
        goto after_4;
    // 0x800B04F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800B04F4: beq         $v0, $zero, L_800B0510
    if (ctx->r2 == 0) {
        // 0x800B04F8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B0510;
    }
    // 0x800B04F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B04FC: jal         0x8000E9D0
    // 0x800B0500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    add_particle_to_entity_list(rdram, ctx);
        goto after_5;
    // 0x800B0500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800B0504: lh          $a1, 0xA($s2)
    ctx->r5 = MEM_H(ctx->r18, 0XA);
    // 0x800B0508: jal         0x800B285C
    // 0x800B050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    particle_update(rdram, ctx);
        goto after_6;
    // 0x800B050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800B0510:
    // 0x800B0510: lh          $t6, 0x4($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X4);
    // 0x800B0514: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800B0518: and         $t7, $t6, $s3
    ctx->r15 = ctx->r14 & ctx->r19;
    // 0x800B051C: sh          $t7, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r15;
    // 0x800B0520: lh          $t9, 0x42($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X42);
    // 0x800B0524: nop

    // 0x800B0528: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B052C: bne         $at, $zero, L_800B04EC
    if (ctx->r1 != 0) {
        // 0x800B0530: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800B04EC;
    }
    // 0x800B0530: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B0534:
    // 0x800B0534: lh          $v0, 0xA($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA);
    // 0x800B0538: lh          $v1, 0x40($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X40);
    // 0x800B053C: nop

    // 0x800B0540: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B0544: beq         $at, $zero, L_800B04D8
    if (ctx->r1 == 0) {
        // 0x800B0548: subu        $t4, $v0, $v1
        ctx->r12 = SUB32(ctx->r2, ctx->r3);
            goto L_800B04D8;
    }
    // 0x800B0548: subu        $t4, $v0, $v1
    ctx->r12 = SUB32(ctx->r2, ctx->r3);
L_800B054C:
    // 0x800B054C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B0550:
    // 0x800B0550: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B0554: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B0558: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B055C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B0560: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800B0564: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800B0568: jr          $ra
    // 0x800B056C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B056C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void safe_mark_write_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE88: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006EE8C: lw          $t6, 0x3A6C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A6C);
    // 0x8006EE90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EE98: bne         $t6, $zero, L_8006EEDC
    if (ctx->r14 != 0) {
        // 0x8006EE9C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8006EEDC;
    }
    // 0x8006EE9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006EEA0: jal         0x8009C814
    // 0x8006EEA4: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8006EEA4: nop

    after_0:
    // 0x8006EEA8: bne         $v0, $zero, L_8006EEDC
    if (ctx->r2 != 0) {
        // 0x8006EEAC: addiu       $at, $zero, -0xC01
        ctx->r1 = ADD32(0, -0XC01);
            goto L_8006EEDC;
    }
    // 0x8006EEAC: addiu       $at, $zero, -0xC01
    ctx->r1 = ADD32(0, -0XC01);
    // 0x8006EEB0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EEB4: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EEB8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8006EEBC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006EEC0: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8006EEC4: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x8006EEC8: sll         $t3, $t2, 10
    ctx->r11 = S32(ctx->r10 << 10);
    // 0x8006EECC: ori         $t0, $t8, 0x40
    ctx->r8 = ctx->r24 | 0X40;
    // 0x8006EED0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006EED4: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8006EED8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8006EEDC:
    // 0x8006EEDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EEE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EEE4: jr          $ra
    // 0x8006EEE8: nop

    return;
    // 0x8006EEE8: nop

;}
RECOMP_FUNC void input_held(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A768: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A76C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A770: lbu         $t6, 0x16D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X16D0);
    // 0x8006A774: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A778: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006A77C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006A780: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006A784: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8006A788: lhu         $v0, 0x1690($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1690);
    // 0x8006A78C: jr          $ra
    // 0x8006A790: nop

    return;
    // 0x8006A790: nop

;}
RECOMP_FUNC void adventuretrack_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093F18: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80093F1C: jal         0x8009C9EC
    // 0x80093F20: addiu       $a0, $a0, 0x1534
    ctx->r4 = ADD32(ctx->r4, 0X1534);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x80093F20: addiu       $a0, $a0, 0x1534
    ctx->r4 = ADD32(ctx->r4, 0X1534);
    after_0:
    // 0x80093F24: jal         0x800C478C
    // 0x80093F28: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x80093F28: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80093F2C: jal         0x80000B28
    // 0x80093F30: nop

    music_change_on(rdram, ctx);
        goto after_2;
    // 0x80093F30: nop

    after_2:
    // 0x80093F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80093F38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80093F3C: jr          $ra
    // 0x80093F40: nop

    return;
    // 0x80093F40: nop

;}
RECOMP_FUNC void main_game_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C84C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C854: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006C858: jal         0x800CD7C0
    // 0x8006C85C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8006C85C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x8006C860: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006C864: lw          $t6, -0x2710($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2710);
    // 0x8006C868: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006C86C: bne         $t6, $at, L_8006C8EC
    if (ctx->r14 != ctx->r1) {
        // 0x8006C870: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8006C8EC;
    }
    // 0x8006C870: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006C874: lw          $t7, 0x3A68($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3A68);
    // 0x8006C878: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006C87C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006C880: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006C884: lw          $t9, 0x1770($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1770);
    // 0x8006C888: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C88C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C890: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006C894: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006C898: jal         0x8007A720
    // 0x8006C89C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    rsp_segment(rdram, ctx);
        goto after_1;
    // 0x8006C89C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    after_1:
    // 0x8006C8A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C8A4: lw          $a2, 0x6874($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6874);
    // 0x8006C8A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C8AC: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C8B0: jal         0x8007A720
    // 0x8006C8B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rsp_segment(rdram, ctx);
        goto after_2;
    // 0x8006C8B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8006C8B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C8BC: lw          $a2, 0x6880($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6880);
    // 0x8006C8C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C8C4: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C8C8: jal         0x8007A720
    // 0x8006C8CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rsp_segment(rdram, ctx);
        goto after_3;
    // 0x8006C8CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8006C8D0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C8D4: lw          $a2, 0x6874($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6874);
    // 0x8006C8D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C8DC: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C8E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8006C8E4: jal         0x8007A720
    // 0x8006C8E8: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    rsp_segment(rdram, ctx);
        goto after_4;
    // 0x8006C8E8: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    after_4:
L_8006C8EC:
    // 0x8006C8EC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006C8F0: lb          $v1, -0x26A0($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X26A0);
    // 0x8006C8F4: nop

    // 0x8006C8F8: bne         $v1, $zero, L_8006C94C
    if (ctx->r3 != 0) {
        // 0x8006C8FC: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8006C94C;
    }
    // 0x8006C8FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C900: lw          $t0, 0x3A68($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3A68);
    // 0x8006C904: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C908: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8006C90C: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8006C910: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C914: lw          $a1, 0x1778($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1778);
    // 0x8006C918: lw          $a0, 0x1770($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1770);
    // 0x8006C91C: jal         0x800778A0
    // 0x8006C920: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gfxtask_run_xbus(rdram, ctx);
        goto after_5;
    // 0x8006C920: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8006C924: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006C928: addiu       $a3, $a3, 0x3A68
    ctx->r7 = ADD32(ctx->r7, 0X3A68);
    // 0x8006C92C: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8006C930: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006C934: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8006C938: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8006C93C: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x8006C940: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8006C944: lb          $v1, -0x26A0($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X26A0);
    // 0x8006C948: nop

L_8006C94C:
    // 0x8006C94C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006C950: beq         $v1, $zero, L_8006C964
    if (ctx->r3 == 0) {
        // 0x8006C954: addiu       $a3, $a3, 0x3A68
        ctx->r7 = ADD32(ctx->r7, 0X3A68);
            goto L_8006C964;
    }
    // 0x8006C954: addiu       $a3, $a3, 0x3A68
    ctx->r7 = ADD32(ctx->r7, 0X3A68);
    // 0x8006C958: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8006C95C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C960: sb          $t6, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = ctx->r14;
L_8006C964:
    // 0x8006C964: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8006C968: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006C96C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006C970: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006C974: lw          $t8, 0x1770($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1770);
    // 0x8006C978: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C97C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C980: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006C984: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8006C988: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8006C98C: lw          $t9, 0x1780($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1780);
    // 0x8006C990: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C994: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C998: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8006C99C: lw          $t0, 0x1790($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1790);
    // 0x8006C9A0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006C9A4: sw          $t9, 0x1788($at)
    MEM_W(0X1788, ctx->r1) = ctx->r25;
    // 0x8006C9A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C9AC: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x8006C9B0: lw          $t1, 0x17A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X17A0);
    // 0x8006C9B4: sw          $t0, 0x1798($at)
    MEM_W(0X1798, ctx->r1) = ctx->r8;
    // 0x8006C9B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C9BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006C9C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006C9C4: jal         0x8007A720
    // 0x8006C9C8: sw          $t1, 0x17A8($at)
    MEM_W(0X17A8, ctx->r1) = ctx->r9;
    rsp_segment(rdram, ctx);
        goto after_6;
    // 0x8006C9C8: sw          $t1, 0x17A8($at)
    MEM_W(0X17A8, ctx->r1) = ctx->r9;
    after_6:
    // 0x8006C9CC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C9D0: lw          $a2, 0x6878($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6878);
    // 0x8006C9D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C9D8: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C9DC: jal         0x8007A720
    // 0x8006C9E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rsp_segment(rdram, ctx);
        goto after_7;
    // 0x8006C9E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8006C9E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C9E8: lw          $a2, 0x6880($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6880);
    // 0x8006C9EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C9F0: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006C9F4: jal         0x8007A720
    // 0x8006C9F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rsp_segment(rdram, ctx);
        goto after_8;
    // 0x8006C9F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8006C9FC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006CA00: lw          $a2, 0x6878($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6878);
    // 0x8006CA04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CA08: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006CA0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8006CA10: jal         0x8007A720
    // 0x8006CA14: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    rsp_segment(rdram, ctx);
        goto after_9;
    // 0x8006CA14: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    after_9:
    // 0x8006CA18: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CA1C: jal         0x8007852C
    // 0x8006CA20: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    rsp_init(rdram, ctx);
        goto after_10;
    // 0x8006CA20: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_10:
    // 0x8006CA24: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CA28: jal         0x800784A4
    // 0x8006CA2C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    rdp_init(rdram, ctx);
        goto after_11;
    // 0x8006CA2C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_11:
    // 0x8006CA30: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CA34: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CA38: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006CA3C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006CA40: jal         0x80077FEC
    // 0x8006CA44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bgdraw_render(rdram, ctx);
        goto after_12;
    // 0x8006CA44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x8006CA48: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CA4C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006CA50: lw          $a1, -0x268C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X268C);
    // 0x8006CA54: lw          $a0, -0x2714($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2714);
    // 0x8006CA58: jal         0x8006A404
    // 0x8006CA5C: nop

    input_update(rdram, ctx);
        goto after_13;
    // 0x8006CA5C: nop

    after_13:
    // 0x8006CA60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CA64: jal         0x800B7BFC
    // 0x8006CA68: sw          $v0, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r2;
    get_lockup_status(rdram, ctx);
        goto after_14;
    // 0x8006CA68: sw          $v0, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r2;
    after_14:
    // 0x8006CA6C: beq         $v0, $zero, L_8006CA88
    if (ctx->r2 == 0) {
        // 0x8006CA70: nop
    
            goto L_8006CA88;
    }
    // 0x8006CA70: nop

    // 0x8006CA74: jal         0x800B7D30
    // 0x8006CA78: nop

    render_epc_lock_up_display(rdram, ctx);
        goto after_15;
    // 0x8006CA78: nop

    after_15:
    // 0x8006CA7C: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8006CA80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006CA84: sw          $t2, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = ctx->r10;
L_8006CA88:
    // 0x8006CA88: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006CA8C: lb          $t3, -0x26F0($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X26F0);
    // 0x8006CA90: nop

    // 0x8006CA94: beq         $t3, $zero, L_8006CACC
    if (ctx->r11 == 0) {
        // 0x8006CA98: lui         $v1, 0x98
        ctx->r3 = S32(0X98 << 16);
            goto L_8006CACC;
    }
    // 0x8006CA98: lui         $v1, 0x98
    ctx->r3 = S32(0X98 << 16);
    // 0x8006CA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006CAA0: ori         $v1, $v1, 0x9680
    ctx->r3 = ctx->r3 | 0X9680;
L_8006CAA4:
    // 0x8006CAA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006CAA8: bne         $v0, $v1, L_8006CAA4
    if (ctx->r2 != ctx->r3) {
        // 0x8006CAAC: nop
    
            goto L_8006CAA4;
    }
    // 0x8006CAAC: nop

    // 0x8006CAB0: lui         $at, 0x131
    ctx->r1 = S32(0X131 << 16);
    // 0x8006CAB4: ori         $at, $at, 0x2D01
    ctx->r1 = ctx->r1 | 0X2D01;
    // 0x8006CAB8: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8006CABC: bne         $at, $zero, L_8006CACC
    if (ctx->r1 != 0) {
        // 0x8006CAC0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006CACC;
    }
    // 0x8006CAC0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CAC4: jal         0x800B643C
    // 0x8006CAC8: addiu       $a0, $a0, 0x76C4
    ctx->r4 = ADD32(ctx->r4, 0X76C4);
    render_printf(rdram, ctx);
        goto after_16;
    // 0x8006CAC8: addiu       $a0, $a0, 0x76C4
    ctx->r4 = ADD32(ctx->r4, 0X76C4);
    after_16:
L_8006CACC:
    // 0x8006CACC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006CAD0: lw          $v0, 0x3A6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A6C);
    // 0x8006CAD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006CAD8: beq         $v0, $at, L_8006CB08
    if (ctx->r2 == ctx->r1) {
        // 0x8006CADC: nop
    
            goto L_8006CB08;
    }
    // 0x8006CADC: nop

    // 0x8006CAE0: beq         $v0, $zero, L_8006CB2C
    if (ctx->r2 == 0) {
        // 0x8006CAE4: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006CB2C;
    }
    // 0x8006CAE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CAE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CAEC: beq         $v0, $at, L_8006CB18
    if (ctx->r2 == ctx->r1) {
        // 0x8006CAF0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006CB18;
    }
    // 0x8006CAF0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CAF4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006CAF8: beq         $v0, $at, L_8006CB40
    if (ctx->r2 == ctx->r1) {
        // 0x8006CAFC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006CB40;
    }
    // 0x8006CAFC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CB00: b           L_8006CB4C
    // 0x8006CB04: nop

        goto L_8006CB4C;
    // 0x8006CB04: nop

L_8006CB08:
    // 0x8006CB08: jal         0x8006F67C
    // 0x8006CB0C: nop

    mode_intro(rdram, ctx);
        goto after_17;
    // 0x8006CB0C: nop

    after_17:
    // 0x8006CB10: b           L_8006CB4C
    // 0x8006CB14: nop

        goto L_8006CB4C;
    // 0x8006CB14: nop

L_8006CB18:
    // 0x8006CB18: lw          $a0, -0x268C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X268C);
    // 0x8006CB1C: jal         0x8006DF38
    // 0x8006CB20: nop

    mode_menu(rdram, ctx);
        goto after_18;
    // 0x8006CB20: nop

    after_18:
    // 0x8006CB24: b           L_8006CB4C
    // 0x8006CB28: nop

        goto L_8006CB4C;
    // 0x8006CB28: nop

L_8006CB2C:
    // 0x8006CB2C: lw          $a0, -0x268C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X268C);
    // 0x8006CB30: jal         0x8006CF30
    // 0x8006CB34: nop

    mode_game(rdram, ctx);
        goto after_19;
    // 0x8006CB34: nop

    after_19:
    // 0x8006CB38: b           L_8006CB4C
    // 0x8006CB3C: nop

        goto L_8006CB4C;
    // 0x8006CB3C: nop

L_8006CB40:
    // 0x8006CB40: lw          $a0, -0x268C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X268C);
    // 0x8006CB44: jal         0x800B7CF4
    // 0x8006CB48: nop

    mode_lockup(rdram, ctx);
        goto after_20;
    // 0x8006CB48: nop

    after_20:
L_8006CB4C:
    // 0x8006CB4C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CB50: lbu         $a0, -0x2689($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2689);
    // 0x8006CB54: jal         0x80000D00
    // 0x8006CB58: nop

    sound_update_queue(rdram, ctx);
        goto after_21;
    // 0x8006CB58: nop

    after_21:
    // 0x8006CB5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CB60: jal         0x800B64D8
    // 0x8006CB64: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    debug_text_print(rdram, ctx);
        goto after_22;
    // 0x8006CB64: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_22:
    // 0x8006CB68: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CB6C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CB70: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006CB74: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006CB78: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006CB7C: jal         0x800C5C5C
    // 0x8006CB80: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    render_dialogue_boxes(rdram, ctx);
        goto after_23;
    // 0x8006CB80: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_23:
    // 0x8006CB84: jal         0x800C5B80
    // 0x8006CB88: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    dialogue_close(rdram, ctx);
        goto after_24;
    // 0x8006CB88: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_24:
    // 0x8006CB8C: jal         0x800C59F4
    // 0x8006CB90: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    dialogue_clear(rdram, ctx);
        goto after_25;
    // 0x8006CB90: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_25:
    // 0x8006CB94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CB98: lw          $a0, -0x268C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X268C);
    // 0x8006CB9C: jal         0x800C09B4
    // 0x8006CBA0: nop

    transition_update(rdram, ctx);
        goto after_26;
    // 0x8006CBA0: nop

    after_26:
    // 0x8006CBA4: beq         $v0, $zero, L_8006CBC4
    if (ctx->r2 == 0) {
        // 0x8006CBA8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006CBC4;
    }
    // 0x8006CBA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CBAC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CBB0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006CBB4: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006CBB8: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006CBBC: jal         0x800C0AE8
    // 0x8006CBC0: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    transition_render(rdram, ctx);
        goto after_27;
    // 0x8006CBC0: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_27:
L_8006CBC4:
    // 0x8006CBC4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006CBC8: lw          $t4, 0x3AA0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3AA0);
    // 0x8006CBCC: nop

    // 0x8006CBD0: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x8006CBD4: bne         $at, $zero, L_8006CBFC
    if (ctx->r1 != 0) {
        // 0x8006CBD8: nop
    
            goto L_8006CBFC;
    }
    // 0x8006CBD8: nop

    // 0x8006CBDC: jal         0x8006F708
    // 0x8006CBE0: nop

    is_controller_missing(rdram, ctx);
        goto after_28;
    // 0x8006CBE0: nop

    after_28:
    // 0x8006CBE4: beq         $v0, $zero, L_8006CBFC
    if (ctx->r2 == 0) {
        // 0x8006CBE8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006CBFC;
    }
    // 0x8006CBE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CBEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006CBF0: lw          $a1, -0x268C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X268C);
    // 0x8006CBF4: jal         0x80082E48
    // 0x8006CBF8: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    menu_missing_controller(rdram, ctx);
        goto after_29;
    // 0x8006CBF8: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_29:
L_8006CBFC:
    // 0x8006CBFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006CC00: lw          $v0, 0x1778($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1778);
    // 0x8006CC04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006CC08: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8006CC0C: sw          $t5, 0x1778($at)
    MEM_W(0X1778, ctx->r1) = ctx->r13;
    // 0x8006CC10: lui         $t6, 0xE900
    ctx->r14 = S32(0XE900 << 16);
    // 0x8006CC14: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006CC18: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006CC1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006CC20: lw          $v0, 0x1778($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1778);
    // 0x8006CC24: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x8006CC28: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006CC2C: sw          $t7, 0x1778($at)
    MEM_W(0X1778, ctx->r1) = ctx->r15;
    // 0x8006CC30: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006CC34: jal         0x80066850
    // 0x8006CC38: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    copy_viewports_to_stack(rdram, ctx);
        goto after_30;
    // 0x8006CC38: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_30:
    // 0x8006CC3C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006CC40: lb          $t9, -0x26A0($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X26A0);
    // 0x8006CC44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CC48: beq         $t9, $at, L_8006CC74
    if (ctx->r25 == ctx->r1) {
        // 0x8006CC4C: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_8006CC74;
    }
    // 0x8006CC4C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006CC50: lb          $t0, -0x2704($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2704);
    // 0x8006CC54: nop

    // 0x8006CC58: bne         $t0, $zero, L_8006CC7C
    if (ctx->r8 != 0) {
        // 0x8006CC5C: nop
    
            goto L_8006CC7C;
    }
    // 0x8006CC5C: nop

    // 0x8006CC60: jal         0x80077EA4
    // 0x8006CC64: nop

    gfxtask_wait(rdram, ctx);
        goto after_31;
    // 0x8006CC64: nop

    after_31:
    // 0x8006CC68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CC6C: b           L_8006CC7C
    // 0x8006CC70: sw          $v0, -0x2710($at)
    MEM_W(-0X2710, ctx->r1) = ctx->r2;
        goto L_8006CC7C;
    // 0x8006CC70: sw          $v0, -0x2710($at)
    MEM_W(-0X2710, ctx->r1) = ctx->r2;
L_8006CC74:
    // 0x8006CC74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CC78: sb          $zero, -0x26A0($at)
    MEM_B(-0X26A0, ctx->r1) = 0;
L_8006CC7C:
    // 0x8006CC7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CC80: jal         0x800713D8
    // 0x8006CC84: sb          $zero, -0x2704($at)
    MEM_B(-0X2704, ctx->r1) = 0;
    mempool_free_queue_clear(rdram, ctx);
        goto after_32;
    // 0x8006CC84: sb          $zero, -0x2704($at)
    MEM_B(-0X2704, ctx->r1) = 0;
    after_32:
    // 0x8006CC88: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006CC8C: lb          $t1, 0x3A95($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X3A95);
    // 0x8006CC90: nop

    // 0x8006CC94: bne         $t1, $zero, L_8006CCA4
    if (ctx->r9 != 0) {
        // 0x8006CC98: nop
    
            goto L_8006CCA4;
    }
    // 0x8006CC98: nop

    // 0x8006CC9C: jal         0x80066760
    // 0x8006CCA0: nop

    disable_cutscene_camera(rdram, ctx);
        goto after_33;
    // 0x8006CCA0: nop

    after_33:
L_8006CCA4:
    // 0x8006CCA4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006CCA8: lb          $t2, -0x26A0($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X26A0);
    // 0x8006CCAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006CCB0: bne         $t2, $at, L_8006CCE8
    if (ctx->r10 != ctx->r1) {
        // 0x8006CCB4: lui         $t3, 0x8000
        ctx->r11 = S32(0X8000 << 16);
            goto L_8006CCE8;
    }
    // 0x8006CCB4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8006CCB8: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x8006CCBC: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x8006CCC0: bne         $t3, $zero, L_8006CCD0
    if (ctx->r11 != 0) {
        // 0x8006CCC4: ori         $v0, $v0, 0x5800
        ctx->r2 = ctx->r2 | 0X5800;
            goto L_8006CCD0;
    }
    // 0x8006CCC4: ori         $v0, $v0, 0x5800
    ctx->r2 = ctx->r2 | 0X5800;
    // 0x8006CCC8: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x8006CCCC: ori         $v0, $v0, 0x9400
    ctx->r2 = ctx->r2 | 0X9400;
L_8006CCD0:
    // 0x8006CCD0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CCD4: lw          $a1, 0x6874($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6874);
    // 0x8006CCD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CCDC: lw          $a0, 0x6878($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6878);
    // 0x8006CCE0: jal         0x80070D44
    // 0x8006CCE4: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
    dmacopy_doubleword(rdram, ctx);
        goto after_34;
    // 0x8006CCE4: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
    after_34:
L_8006CCE8:
    // 0x8006CCE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CCEC: lw          $a0, -0x2710($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2710);
    // 0x8006CCF0: jal         0x8007ADDC
    // 0x8006CCF4: nop

    fb_update(rdram, ctx);
        goto after_35;
    // 0x8006CCF4: nop

    after_35:
    // 0x8006CCF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CCFC: sw          $v0, -0x268C($at)
    MEM_W(-0X268C, ctx->r1) = ctx->r2;
    // 0x8006CD00: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8006CD04: bne         $at, $zero, L_8006CD14
    if (ctx->r1 != 0) {
        // 0x8006CD08: addiu       $t4, $zero, 0x6
        ctx->r12 = ADD32(0, 0X6);
            goto L_8006CD14;
    }
    // 0x8006CD08: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8006CD0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CD10: sw          $t4, -0x268C($at)
    MEM_W(-0X268C, ctx->r1) = ctx->r12;
L_8006CD14:
    // 0x8006CD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CD18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CD1C: jr          $ra
    // 0x8006CD20: nop

    return;
    // 0x8006CD20: nop

;}
RECOMP_FUNC void gfxtask_run_fifo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077B84: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80077B88: addiu       $v1, $v1, -0x15A8
    ctx->r3 = ADD32(ctx->r3, -0X15A8);
    // 0x80077B8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80077B90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077B94: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80077B98: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077B9C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80077BA0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80077BA4: addiu       $t7, $t7, 0x65C0
    ctx->r15 = ADD32(ctx->r15, 0X65C0);
    // 0x80077BA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80077BAC: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80077BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077BB4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80077BB8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80077BBC: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80077BC0: bne         $t8, $at, L_80077BCC
    if (ctx->r24 != ctx->r1) {
        // 0x80077BC4: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80077BCC;
    }
    // 0x80077BC4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077BC8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80077BCC:
    // 0x80077BCC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80077BD0: subu        $t0, $a1, $a0
    ctx->r8 = SUB32(ctx->r5, ctx->r4);
    // 0x80077BD4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80077BD8: addiu       $v0, $v0, -0x75E0
    ctx->r2 = ADD32(ctx->r2, -0X75E0);
    // 0x80077BDC: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80077BE0: addiu       $t5, $t5, -0x7510
    ctx->r13 = ADD32(ctx->r13, -0X7510);
    // 0x80077BE4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80077BE8: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80077BEC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80077BF0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80077BF4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80077BF8: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x80077BFC: addiu       $t7, $t7, -0x6310
    ctx->r15 = ADD32(ctx->r15, -0X6310);
    // 0x80077C00: addiu       $t8, $t8, -0x56E0
    ctx->r24 = ADD32(ctx->r24, -0X56E0);
    // 0x80077C04: sw          $t2, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r10;
    // 0x80077C08: sw          $t3, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r11;
    // 0x80077C0C: sw          $t4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r12;
    // 0x80077C10: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x80077C14: sw          $t8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r24;
    // 0x80077C18: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
    // 0x80077C1C: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x80077C20: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80077C24: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80077C28: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80077C2C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80077C30: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077C34: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80077C38: sw          $t9, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r25;
    // 0x80077C3C: addiu       $t0, $t0, 0x4840
    ctx->r8 = ADD32(ctx->r8, 0X4840);
    // 0x80077C40: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x80077C44: addiu       $t2, $t2, 0x4C40
    ctx->r10 = ADD32(ctx->r10, 0X4C40);
    // 0x80077C48: addiu       $t3, $t3, 0x6440
    ctx->r11 = ADD32(ctx->r11, 0X6440);
    // 0x80077C4C: addiu       $t4, $t4, 0x7770
    ctx->r12 = ADD32(ctx->r12, 0X7770);
    // 0x80077C50: addiu       $t5, $zero, 0xA00
    ctx->r13 = ADD32(0, 0XA00);
    // 0x80077C54: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80077C58: addiu       $t7, $t7, 0x6478
    ctx->r15 = ADD32(ctx->r15, 0X6478);
    // 0x80077C5C: addiu       $t8, $t8, -0x15F0
    ctx->r24 = ADD32(ctx->r24, -0X15F0);
    // 0x80077C60: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80077C64: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x80077C68: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x80077C6C: sw          $t1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r9;
    // 0x80077C70: sw          $t2, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r10;
    // 0x80077C74: sw          $t3, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r11;
    // 0x80077C78: sw          $t4, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r12;
    // 0x80077C7C: sw          $t5, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r13;
    // 0x80077C80: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80077C84: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
    // 0x80077C88: sw          $t7, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r15;
    // 0x80077C8C: sw          $t8, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r24;
    // 0x80077C90: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80077C94: lw          $t9, 0x6874($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6874);
    // 0x80077C98: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x80077C9C: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x80077CA0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80077CA4: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x80077CA8: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x80077CAC: sw          $v1, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r3;
    // 0x80077CB0: sw          $v1, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r3;
    // 0x80077CB4: sw          $zero, 0x68($a3)
    MEM_W(0X68, ctx->r7) = 0;
    // 0x80077CB8: sw          $t9, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r25;
    // 0x80077CBC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80077CC0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80077CC4: beq         $t0, $zero, L_80077CD0
    if (ctx->r8 == 0) {
        // 0x80077CC8: addiu       $t1, $t1, 0x6440
        ctx->r9 = ADD32(ctx->r9, 0X6440);
            goto L_80077CD0;
    }
    // 0x80077CC8: addiu       $t1, $t1, 0x6440
    ctx->r9 = ADD32(ctx->r9, 0X6440);
    // 0x80077CCC: sw          $t1, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r9;
L_80077CD0:
    // 0x80077CD0: jal         0x800D1E00
    // 0x80077CD4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077CD4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80077CD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077CDC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80077CE0: lw          $a0, 0x66A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66A0);
    // 0x80077CE4: jal         0x800C9390
    // 0x80077CE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077CE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80077CEC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80077CF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077CF4: beq         $t2, $zero, L_80077D08
    if (ctx->r10 == 0) {
        // 0x80077CF8: addiu       $a0, $a0, 0x6440
        ctx->r4 = ADD32(ctx->r4, 0X6440);
            goto L_80077D08;
    }
    // 0x80077CF8: addiu       $a0, $a0, 0x6440
    ctx->r4 = ADD32(ctx->r4, 0X6440);
    // 0x80077CFC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80077D00: jal         0x800C9110
    // 0x80077D04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077D04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_80077D08:
    // 0x80077D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077D0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077D10: jr          $ra
    // 0x80077D14: nop

    return;
    // 0x80077D14: nop

;}
RECOMP_FUNC void set_camera_shake_by_distance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A054: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006A058: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8006A05C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8006A060: addiu       $s2, $s2, 0x1260
    ctx->r18 = ADD32(ctx->r18, 0X1260);
    // 0x8006A064: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8006A068: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8006A06C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8006A070: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8006A074: mtc1        $a2, $f28
    ctx->f28.u32l = ctx->r6;
    // 0x8006A078: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8006A07C: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8006A080: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8006A084: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8006A088: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8006A08C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x8006A090: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x8006A094: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8006A098: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8006A09C: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8006A0A0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8006A0A4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8006A0A8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8006A0AC: bltz        $t6, L_8006A128
    if (SIGNED(ctx->r14) < 0) {
        // 0x8006A0B0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8006A128;
    }
    // 0x8006A0B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006A0B4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006A0B8: lwc1        $f22, 0x60($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006A0BC: addiu       $s0, $s0, 0x1040
    ctx->r16 = ADD32(ctx->r16, 0X1040);
L_8006A0C0:
    // 0x8006A0C0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006A0C4: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006A0C8: sub.s       $f0, $f24, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x8006A0CC: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006A0D0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A0D4: sub.s       $f2, $f26, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f26.fl - ctx->f6.fl;
    // 0x8006A0D8: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A0DC: sub.s       $f14, $f28, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f28.fl - ctx->f8.fl;
    // 0x8006A0E0: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8006A0E4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006A0E8: jal         0x800CA030
    // 0x8006A0EC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A0EC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x8006A0F0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8006A0F4: nop

    // 0x8006A0F8: bc1f        L_8006A114
    if (!c1cs) {
        // 0x8006A0FC: nop
    
            goto L_8006A114;
    }
    // 0x8006A0FC: nop

    // 0x8006A100: sub.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8006A104: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8006A108: nop

    // 0x8006A10C: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8006A110: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_8006A114:
    // 0x8006A114: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8006A118: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006A11C: slt         $at, $t7, $s1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8006A120: beq         $at, $zero, L_8006A0C0
    if (ctx->r1 == 0) {
        // 0x8006A124: addiu       $s0, $s0, 0x44
        ctx->r16 = ADD32(ctx->r16, 0X44);
            goto L_8006A0C0;
    }
    // 0x8006A124: addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
L_8006A128:
    // 0x8006A128: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A12C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8006A130: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8006A134: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8006A138: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006A13C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8006A140: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006A144: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8006A148: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8006A14C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8006A150: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8006A154: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8006A158: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8006A15C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8006A160: jr          $ra
    // 0x8006A164: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8006A164: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8007C660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CAB0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007CAB4: andi        $t7, $a0, 0x8000
    ctx->r15 = ctx->r4 & 0X8000;
    // 0x8007CAB8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007CABC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007CAC0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8007CAC4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8007CAC8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007CACC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007CAD0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007CAD4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007CAD8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007CADC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007CAE0: beq         $t7, $zero, L_8007CAF0
    if (ctx->r15 == 0) {
        // 0x8007CAE4: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_8007CAF0;
    }
    // 0x8007CAE4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8007CAE8: b           L_8007CC80
    // 0x8007CAEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007CC80;
    // 0x8007CAEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007CAF0:
    // 0x8007CAF0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8007CAF4: addiu       $s3, $s3, 0x6910
    ctx->r19 = ADD32(ctx->r19, 0X6910);
    // 0x8007CAF8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8007CAFC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8007CB00: bne         $t8, $zero, L_8007CC68
    if (ctx->r24 != 0) {
        // 0x8007CB04: addiu       $s0, $s0, 0x68D8
        ctx->r16 = ADD32(ctx->r16, 0X68D8);
            goto L_8007CC68;
    }
    // 0x8007CB04: addiu       $s0, $s0, 0x68D8
    ctx->r16 = ADD32(ctx->r16, 0X68D8);
    // 0x8007CB08: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007CB0C: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007CB10: jal         0x80070EDC
    // 0x8007CB14: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8007CB14: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_0:
    // 0x8007CB18: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8007CB1C: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8007CB20: blez        $t9, L_8007CB50
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8007CB24: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8007CB50;
    }
    // 0x8007CB24: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8007CB28:
    // 0x8007CB28: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8007CB2C: nop

    // 0x8007CB30: addu        $t1, $t0, $s4
    ctx->r9 = ADD32(ctx->r8, ctx->r20);
    // 0x8007CB34: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x8007CB38: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8007CB3C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8007CB40: slt         $at, $s4, $t2
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007CB44: bne         $at, $zero, L_8007CB28
    if (ctx->r1 != 0) {
        // 0x8007CB48: nop
    
            goto L_8007CB28;
    }
    // 0x8007CB48: nop

    // 0x8007CB4C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8007CB50:
    // 0x8007CB50: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8007CB54: addiu       $fp, $fp, 0x68F4
    ctx->r30 = ADD32(ctx->r30, 0X68F4);
    // 0x8007CB58: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x8007CB5C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8007CB60: blez        $t3, L_8007CC68
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8007CB64: lui         $s7, 0x8012
        ctx->r23 = S32(0X8012 << 16);
            goto L_8007CC68;
    }
    // 0x8007CB64: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8007CB68: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8007CB6C: addiu       $s6, $s6, 0x68F0
    ctx->r22 = ADD32(ctx->r22, 0X68F0);
    // 0x8007CB70: addiu       $s7, $s7, 0x68E8
    ctx->r23 = ADD32(ctx->r23, 0X68E8);
    // 0x8007CB74: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8007CB78:
    // 0x8007CB78: lw          $t4, 0x0($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X0);
    // 0x8007CB7C: lw          $s1, 0x0($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X0);
    // 0x8007CB80: addu        $v0, $t4, $s5
    ctx->r2 = ADD32(ctx->r12, ctx->r21);
    // 0x8007CB84: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007CB88: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8007CB8C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007CB90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007CB94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8007CB98: jal         0x80077190
    // 0x8007CB9C: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    asset_load(rdram, ctx);
        goto after_1;
    // 0x8007CB9C: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    after_1:
    // 0x8007CBA0: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x8007CBA4: nop

    // 0x8007CBA8: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8007CBAC: lbu         $v1, 0xC($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0XC);
    // 0x8007CBB0: nop

    // 0x8007CBB4: blez        $v1, L_8007CC54
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007CBB8: andi        $a0, $v1, 0x3
        ctx->r4 = ctx->r3 & 0X3;
            goto L_8007CC54;
    }
    // 0x8007CBB8: andi        $a0, $v1, 0x3
    ctx->r4 = ctx->r3 & 0X3;
    // 0x8007CBBC: beq         $a0, $zero, L_8007CBEC
    if (ctx->r4 == 0) {
        // 0x8007CBC0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8007CBEC;
    }
    // 0x8007CBC0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007CBC4:
    // 0x8007CBC4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8007CBC8: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x8007CBCC: nop

    // 0x8007CBD0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8007CBD4: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x8007CBD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007CBDC: bne         $v0, $s0, L_8007CBC4
    if (ctx->r2 != ctx->r16) {
        // 0x8007CBE0: sb          $s2, 0x0($t1)
        MEM_B(0X0, ctx->r9) = ctx->r18;
            goto L_8007CBC4;
    }
    // 0x8007CBE0: sb          $s2, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r18;
    // 0x8007CBE4: beq         $s0, $v1, L_8007CC54
    if (ctx->r16 == ctx->r3) {
        // 0x8007CBE8: nop
    
            goto L_8007CC54;
    }
    // 0x8007CBE8: nop

L_8007CBEC:
    // 0x8007CBEC: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8007CBF0: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    // 0x8007CBF4: nop

    // 0x8007CBF8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8007CBFC: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8007CC00: sb          $s2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r18;
    // 0x8007CC04: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8007CC08: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8007CC0C: nop

    // 0x8007CC10: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007CC14: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8007CC18: sb          $s2, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r18;
    // 0x8007CC1C: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x8007CC20: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8007CC24: nop

    // 0x8007CC28: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8007CC2C: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8007CC30: sb          $s2, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r18;
    // 0x8007CC34: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8007CC38: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8007CC3C: nop

    // 0x8007CC40: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8007CC44: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8007CC48: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8007CC4C: bne         $s0, $v1, L_8007CBEC
    if (ctx->r16 != ctx->r3) {
        // 0x8007CC50: sb          $s2, 0x3($t7)
        MEM_B(0X3, ctx->r15) = ctx->r18;
            goto L_8007CBEC;
    }
    // 0x8007CC50: sb          $s2, 0x3($t7)
    MEM_B(0X3, ctx->r15) = ctx->r18;
L_8007CC54:
    // 0x8007CC54: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8007CC58: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8007CC5C: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007CC60: bne         $at, $zero, L_8007CB78
    if (ctx->r1 != 0) {
        // 0x8007CC64: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8007CB78;
    }
    // 0x8007CC64: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8007CC68:
    // 0x8007CC68: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8007CC6C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8007CC70: nop

    // 0x8007CC74: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8007CC78: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x8007CC7C: nop

L_8007CC80:
    // 0x8007CC80: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007CC84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007CC88: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CC8C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007CC90: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007CC94: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007CC98: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007CC9C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8007CCA0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8007CCA4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8007CCA8: jr          $ra
    // 0x8007CCAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007CCAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mempool_alloc_fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071138: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007113C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80071140: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80071144: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80071148: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8007114C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80071150: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80071154: jal         0x8006F750
    // 0x80071158: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80071158: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007115C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80071160: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80071164: addiu       $v0, $v0, 0x3B00
    ctx->r2 = ADD32(ctx->r2, 0X3B00);
    // 0x80071168: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8007116C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80071170: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80071174: bne         $t7, $t8, L_80071190
    if (ctx->r15 != ctx->r24) {
        // 0x80071178: andi        $t9, $s2, 0xF
        ctx->r25 = ctx->r18 & 0XF;
            goto L_80071190;
    }
    // 0x80071178: andi        $t9, $s2, 0xF
    ctx->r25 = ctx->r18 & 0XF;
    // 0x8007117C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80071180: jal         0x8006F77C
    // 0x80071184: nop

    interrupts_enable(rdram, ctx);
        goto after_1;
    // 0x80071184: nop

    after_1:
    // 0x80071188: b           L_800712D8
    // 0x8007118C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800712D8;
    // 0x8007118C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80071190:
    // 0x80071190: beq         $t9, $zero, L_800711A4
    if (ctx->r25 == 0) {
        // 0x80071194: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800711A4;
    }
    // 0x80071194: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80071198: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8007119C: and         $t2, $s2, $at
    ctx->r10 = ctx->r18 & ctx->r1;
    // 0x800711A0: addiu       $s2, $t2, 0x10
    ctx->r18 = ADD32(ctx->r10, 0X10);
L_800711A4:
    // 0x800711A4: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800711A8: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800711AC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800711B0:
    // 0x800711B0: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800711B4: mflo        $t3
    ctx->r11 = lo;
    // 0x800711B8: addu        $v1, $t3, $t1
    ctx->r3 = ADD32(ctx->r11, ctx->r9);
    // 0x800711BC: lh          $t4, 0x8($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X8);
    // 0x800711C0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800711C4: bne         $t4, $zero, L_800712B8
    if (ctx->r12 != 0) {
        // 0x800711C8: nop
    
            goto L_800712B8;
    }
    // 0x800711C8: nop

    // 0x800711CC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800711D0: nop

    // 0x800711D4: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x800711D8: bne         $at, $zero, L_800712B8
    if (ctx->r1 != 0) {
        // 0x800711DC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800712B8;
    }
    // 0x800711DC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800711E0: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x800711E4: addu        $t7, $s1, $s2
    ctx->r15 = ADD32(ctx->r17, ctx->r18);
    // 0x800711E8: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800711EC: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x800711F0: bne         $at, $zero, L_800712B8
    if (ctx->r1 != 0) {
        // 0x800711F4: nop
    
            goto L_800712B8;
    }
    // 0x800711F4: nop

    // 0x800711F8: bne         $s1, $a0, L_80071244
    if (ctx->r17 != ctx->r4) {
        // 0x800711FC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80071244;
    }
    // 0x800711FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80071200: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80071204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071208: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8007120C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80071210: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80071214: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80071218: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8007121C: jal         0x800719CC
    // 0x80071220: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    mempool_slot_assign(rdram, ctx);
        goto after_2;
    // 0x80071220: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_2:
    // 0x80071224: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80071228: jal         0x8006F77C
    // 0x8007122C: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x8007122C: nop

    after_3:
    // 0x80071230: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80071234: nop

    // 0x80071238: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8007123C: b           L_800712DC
    // 0x80071240: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800712DC;
    // 0x80071240: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80071244:
    // 0x80071244: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80071248: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007124C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80071250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071254: subu        $a2, $s1, $v0
    ctx->r6 = SUB32(ctx->r17, ctx->r2);
    // 0x80071258: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8007125C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80071260: jal         0x800719CC
    // 0x80071264: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    mempool_slot_assign(rdram, ctx);
        goto after_4;
    // 0x80071264: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_4:
    // 0x80071268: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8007126C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80071270: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071274: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80071278: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8007127C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80071280: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80071284: jal         0x800719CC
    // 0x80071288: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    mempool_slot_assign(rdram, ctx);
        goto after_5;
    // 0x80071288: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_5:
    // 0x8007128C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80071290: jal         0x8006F77C
    // 0x80071294: nop

    interrupts_enable(rdram, ctx);
        goto after_6;
    // 0x80071294: nop

    after_6:
    // 0x80071298: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8007129C: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800712A0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800712A4: mflo        $t4
    ctx->r12 = lo;
    // 0x800712A8: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x800712AC: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x800712B0: b           L_800712DC
    // 0x800712B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800712DC;
    // 0x800712B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800712B8:
    // 0x800712B8: lh          $s0, 0xC($a1)
    ctx->r16 = MEM_H(ctx->r5, 0XC);
    // 0x800712BC: nop

    // 0x800712C0: bne         $s0, $a2, L_800711B0
    if (ctx->r16 != ctx->r6) {
        // 0x800712C4: nop
    
            goto L_800711B0;
    }
    // 0x800712C4: nop

    // 0x800712C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800712CC: jal         0x8006F77C
    // 0x800712D0: nop

    interrupts_enable(rdram, ctx);
        goto after_7;
    // 0x800712D0: nop

    after_7:
    // 0x800712D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800712D8:
    // 0x800712D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800712DC:
    // 0x800712DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800712E0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800712E4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800712E8: jr          $ra
    // 0x800712EC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800712EC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void lights_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031BFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031C00: jal         0x80031BA0
    // 0x80031C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    lights_free(rdram, ctx);
        goto after_0;
    // 0x80031C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80031C08: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80031C0C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80031C10: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80031C14: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80031C18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80031C1C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80031C20: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80031C24: addiu       $a2, $a2, -0x3138
    ctx->r6 = ADD32(ctx->r6, -0X3138);
    // 0x80031C28: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80031C2C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80031C30: sll         $a0, $t7, 2
    ctx->r4 = S32(ctx->r15 << 2);
    // 0x80031C34: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80031C38: jal         0x80070EDC
    // 0x80031C3C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80031C3C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    after_1:
    // 0x80031C40: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80031C44: addiu       $a2, $a2, -0x3138
    ctx->r6 = ADD32(ctx->r6, -0X3138);
    // 0x80031C48: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80031C4C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80031C50: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x80031C54: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80031C58: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x80031C5C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80031C60: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80031C64: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80031C68: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80031C6C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80031C70: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80031C74: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x80031C78: addiu       $t1, $t1, -0x3130
    ctx->r9 = ADD32(ctx->r9, -0X3130);
    // 0x80031C7C: addiu       $a3, $a3, -0x3140
    ctx->r7 = ADD32(ctx->r7, -0X3140);
    // 0x80031C80: addiu       $a1, $a1, -0x313C
    ctx->r5 = ADD32(ctx->r5, -0X313C);
    // 0x80031C84: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80031C88: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80031C8C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80031C90: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80031C94: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80031C98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031C9C: sw          $t7, -0x312C($at)
    MEM_W(-0X312C, ctx->r1) = ctx->r15;
    // 0x80031CA0: blez        $t0, L_80031CDC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80031CA4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80031CDC;
    }
    // 0x80031CA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80031CA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031CAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80031CB0:
    // 0x80031CB0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80031CB4: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80031CB8: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80031CBC: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80031CC0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80031CC4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80031CC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80031CCC: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80031CD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80031CD4: bne         $at, $zero, L_80031CB0
    if (ctx->r1 != 0) {
        // 0x80031CD8: addiu       $a0, $a0, 0x88
        ctx->r4 = ADD32(ctx->r4, 0X88);
            goto L_80031CB0;
    }
    // 0x80031CD8: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
L_80031CDC:
    // 0x80031CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031CE4: jr          $ra
    // 0x80031CE8: nop

    return;
    // 0x80031CE8: nop

;}
RECOMP_FUNC void menu_caution_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C8B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008C8B8: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x8008C8BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C8C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C8C8: beq         $v0, $zero, L_8008C8DC
    if (ctx->r2 == 0) {
        // 0x8008C8CC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8008C8DC;
    }
    // 0x8008C8CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C8D0: addu        $t7, $v0, $a0
    ctx->r15 = ADD32(ctx->r2, ctx->r4);
    // 0x8008C8D4: b           L_8008C924
    // 0x8008C8D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_8008C924;
    // 0x8008C8D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8008C8DC:
    // 0x8008C8DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008C8E0: lw          $t8, 0x6964($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6964);
    // 0x8008C8E4: nop

    // 0x8008C8E8: bgtz        $t8, L_8008C924
    if (SIGNED(ctx->r24) > 0) {
        // 0x8008C8EC: nop
    
            goto L_8008C924;
    }
    // 0x8008C8EC: nop

    // 0x8008C8F0: jal         0x8006A794
    // 0x8008C8F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8008C8F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8008C8F8: andi        $t9, $v0, 0xD000
    ctx->r25 = ctx->r2 & 0XD000;
    // 0x8008C8FC: beq         $t9, $zero, L_8008C924
    if (ctx->r25 == 0) {
        // 0x8008C900: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008C924;
    }
    // 0x8008C900: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008C904: jal         0x80001D04
    // 0x8008C908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8008C908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8008C90C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008C910: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C914: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C918: sw          $t0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r8;
    // 0x8008C91C: jal         0x800C06F8
    // 0x8008C920: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8008C920: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_2:
L_8008C924:
    // 0x8008C924: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008C928: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x8008C92C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C930: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008C934: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8008C938: beq         $at, $zero, L_8008C958
    if (ctx->r1 == 0) {
        // 0x8008C93C: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8008C958;
    }
    // 0x8008C93C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008C940: addiu       $a1, $a1, 0x558
    ctx->r5 = ADD32(ctx->r5, 0X558);
    // 0x8008C944: jal         0x8008263C
    // 0x8008C948: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_3;
    // 0x8008C948: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x8008C94C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008C950: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008C954: nop

L_8008C958:
    // 0x8008C958: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8008C95C: bne         $at, $zero, L_8008C974
    if (ctx->r1 != 0) {
        // 0x8008C960: nop
    
            goto L_8008C974;
    }
    // 0x8008C960: nop

    // 0x8008C964: jal         0x8008C9A0
    // 0x8008C968: nop

    caution_free(rdram, ctx);
        goto after_4;
    // 0x8008C968: nop

    after_4:
    // 0x8008C96C: jal         0x80081820
    // 0x8008C970: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_5;
    // 0x8008C970: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_5:
L_8008C974:
    // 0x8008C974: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C978: addiu       $v1, $v1, 0x6964
    ctx->r3 = ADD32(ctx->r3, 0X6964);
    // 0x8008C97C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C980: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008C984: blez        $v0, L_8008C990
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008C988: subu        $t2, $v0, $t1
        ctx->r10 = SUB32(ctx->r2, ctx->r9);
            goto L_8008C990;
    }
    // 0x8008C988: subu        $t2, $v0, $t1
    ctx->r10 = SUB32(ctx->r2, ctx->r9);
    // 0x8008C98C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_8008C990:
    // 0x8008C990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C998: jr          $ra
    // 0x8008C99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8008C99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void fb_mode_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A910: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A914: jr          $ra
    // 0x8007A918: sw          $a0, 0x686C($at)
    MEM_W(0X686C, ctx->r1) = ctx->r4;
    return;
    // 0x8007A918: sw          $a0, 0x686C($at)
    MEM_W(0X686C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void input_player_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A738: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A73C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006A740: lbu         $v0, 0x16D0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X16D0);
    // 0x8006A744: jr          $ra
    // 0x8006A748: nop

    return;
    // 0x8006A748: nop

;}
RECOMP_FUNC void bgload_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7940: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C7944: lw          $v0, 0x3D00($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3D00);
    // 0x800C7948: jr          $ra
    // 0x800C794C: nop

    return;
    // 0x800C794C: nop

;}
RECOMP_FUNC void aitable_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C3A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C3AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C3B0: lw          $a0, 0x1740($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1740);
    // 0x8006C3B4: jal         0x80071380
    // 0x8006C3B8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8006C3B8: nop

    after_0:
    // 0x8006C3BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C3C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C3C4: jr          $ra
    // 0x8006C3C8: nop

    return;
    // 0x8006C3C8: nop

;}
RECOMP_FUNC void func_8009D324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D868: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D86C: jr          $ra
    // 0x8009D870: sb          $zero, -0x5A8($at)
    MEM_B(-0X5A8, ctx->r1) = 0;
    return;
    // 0x8009D870: sb          $zero, -0x5A8($at)
    MEM_B(-0X5A8, ctx->r1) = 0;
;}
RECOMP_FUNC void alEvtqPostEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C970C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C9710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9714: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C9718: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C971C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800C9720: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C9724: jal         0x800C9F90
    // 0x800C9728: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9728: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C972C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C9730: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C9734: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C9738: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x800C973C: bne         $t0, $zero, L_800C9754
    if (ctx->r8 != 0) {
        // 0x800C9740: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800C9754;
    }
    // 0x800C9740: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800C9744: jal         0x800C9F90
    // 0x800C9748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800C9748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800C974C: b           L_800C9824
    // 0x800C9750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C9824;
    // 0x800C9750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9754:
    // 0x800C9754: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C9758: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800C975C: jal         0x800C8CC0
    // 0x800C9760: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800C9760: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800C9764: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9768: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800C976C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800C9770: jal         0x800D3D80
    // 0x800C9774: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alCopy(rdram, ctx);
        goto after_3;
    // 0x800C9774: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800C9778: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C977C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800C9780: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800C9784: bne         $a3, $at, L_800C9794
    if (ctx->r7 != ctx->r1) {
        // 0x800C9788: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_800C9794;
    }
    // 0x800C9788: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C978C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C9790: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800C9794:
    // 0x800C9794: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800C9798: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800C979C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800C97A0: beq         $v0, $at, L_800C9818
    if (ctx->r2 == ctx->r1) {
        // 0x800C97A4: addiu       $a1, $v0, 0x8
        ctx->r5 = ADD32(ctx->r2, 0X8);
            goto L_800C9818;
    }
    // 0x800C97A4: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
L_800C97A8:
    // 0x800C97A8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800C97AC: bnel        $v0, $zero, L_800C97DC
    if (ctx->r2 != 0) {
        // 0x800C97B0: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800C97DC;
    }
    goto skip_0;
    // 0x800C97B0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x800C97B4: beql        $t8, $zero, L_800C97C8
    if (ctx->r24 == 0) {
        // 0x800C97B8: sw          $a3, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r7;
            goto L_800C97C8;
    }
    goto skip_1;
    // 0x800C97B8: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    skip_1:
    // 0x800C97BC: b           L_800C97C8
    // 0x800C97C0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
        goto L_800C97C8;
    // 0x800C97C0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x800C97C4: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
L_800C97C8:
    // 0x800C97C8: jal         0x800C8CF0
    // 0x800C97CC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    alLink(rdram, ctx);
        goto after_4;
    // 0x800C97CC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x800C97D0: b           L_800C9818
    // 0x800C97D4: nop

        goto L_800C9818;
    // 0x800C97D4: nop

    // 0x800C97D8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800C97DC:
    // 0x800C97DC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C97E0: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C97E4: beql        $at, $zero, L_800C9810
    if (ctx->r1 == 0) {
        // 0x800C97E8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800C9810;
    }
    goto skip_2;
    // 0x800C97E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    skip_2:
    // 0x800C97EC: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // 0x800C97F0: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800C97F4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800C97F8: subu        $t1, $t9, $a3
    ctx->r9 = SUB32(ctx->r25, ctx->r7);
    // 0x800C97FC: jal         0x800C8CF0
    // 0x800C9800: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    alLink(rdram, ctx);
        goto after_5;
    // 0x800C9800: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    after_5:
    // 0x800C9804: b           L_800C9818
    // 0x800C9808: nop

        goto L_800C9818;
    // 0x800C9808: nop

    // 0x800C980C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800C9810:
    // 0x800C9810: bne         $v0, $zero, L_800C97A8
    if (ctx->r2 != 0) {
        // 0x800C9814: subu        $a3, $a3, $v1
        ctx->r7 = SUB32(ctx->r7, ctx->r3);
            goto L_800C97A8;
    }
    // 0x800C9814: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
L_800C9818:
    // 0x800C9818: jal         0x800C9F90
    // 0x800C981C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x800C981C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x800C9820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9824:
    // 0x800C9824: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C9828: jr          $ra
    // 0x800C982C: nop

    return;
    // 0x800C982C: nop

;}
RECOMP_FUNC void bgdraw_chequer_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078C40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80078C44: jr          $ra
    // 0x80078C48: sw          $zero, -0x15B4($at)
    MEM_W(-0X15B4, ctx->r1) = 0;
    return;
    // 0x80078C48: sw          $zero, -0x15B4($at)
    MEM_W(-0X15B4, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8001E45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E490: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E494: addiu       $v0, $v0, -0x4C06
    ctx->r2 = ADD32(ctx->r2, -0X4C06);
    // 0x8001E498: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8001E49C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E4A0: beq         $a0, $t6, L_8001E4D8
    if (ctx->r4 == ctx->r14) {
        // 0x8001E4A4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8001E4D8;
    }
    // 0x8001E4A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E4A8: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x8001E4AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E4B0: sw          $zero, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = 0;
    // 0x8001E4B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E4B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E4BC: jal         0x8006DC4C
    // 0x8001E4C0: sb          $t7, -0x4C02($at)
    MEM_B(-0X4C02, ctx->r1) = ctx->r15;
    get_game_mode(rdram, ctx);
        goto after_0;
    // 0x8001E4C0: sb          $t7, -0x4C02($at)
    MEM_B(-0X4C02, ctx->r1) = ctx->r15;
    after_0:
    // 0x8001E4C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E4C8: bne         $v0, $at, L_8001E4DC
    if (ctx->r2 != ctx->r1) {
        // 0x8001E4CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E4DC;
    }
    // 0x8001E4CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E4D0: jal         0x8006F66C
    // 0x8001E4D4: nop

    set_frame_blackout_timer(rdram, ctx);
        goto after_1;
    // 0x8001E4D4: nop

    after_1:
L_8001E4D8:
    // 0x8001E4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E4DC:
    // 0x8001E4DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E4E0: jr          $ra
    // 0x8001E4E4: nop

    return;
    // 0x8001E4E4: nop

;}
RECOMP_FUNC void func_80026E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026E94: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80026E98: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80026E9C: sll         $s5, $a0, 16
    ctx->r21 = S32(ctx->r4 << 16);
    // 0x80026EA0: sra         $t6, $s5, 16
    ctx->r14 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80026EA4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80026EA8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80026EAC: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80026EB0: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80026EB4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80026EB8: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80026EBC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80026EC0: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
    // 0x80026EC4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80026EC8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80026ECC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80026ED0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80026ED4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80026ED8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80026EDC: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80026EE0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80026EE4: beq         $at, $zero, L_8002718C
    if (ctx->r1 == 0) {
        // 0x80026EE8: sw          $a0, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->r4;
            goto L_8002718C;
    }
    // 0x80026EE8: sw          $a0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r4;
    // 0x80026EEC: beq         $t6, $zero, L_8002718C
    if (ctx->r14 == 0) {
        // 0x80026EF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002718C;
    }
    // 0x80026EF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026EF4: blez        $t6, L_8002702C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80026EF8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8002702C;
    }
    // 0x80026EF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80026EFC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80026F00: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80026F04: lw          $a3, -0x2608($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2608);
    // 0x80026F08: lw          $t0, -0x2604($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2604);
    // 0x80026F0C: addiu       $s4, $sp, 0x94
    ctx->r20 = ADD32(ctx->r29, 0X94);
    // 0x80026F10: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x80026F14: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
L_80026F18:
    // 0x80026F18: addu        $t7, $s0, $s3
    ctx->r15 = ADD32(ctx->r16, ctx->r19);
    // 0x80026F1C: lb          $t8, 0x0($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X0);
    // 0x80026F20: nop

    // 0x80026F24: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x80026F28: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80026F2C: addu        $a0, $t2, $t0
    ctx->r4 = ADD32(ctx->r10, ctx->r8);
    // 0x80026F30: lb          $t3, 0x0($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X0);
    // 0x80026F34: lb          $t5, 0x1($a0)
    ctx->r13 = MEM_B(ctx->r4, 0X1);
    // 0x80026F38: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80026F3C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80026F40: addu        $v1, $t4, $a3
    ctx->r3 = ADD32(ctx->r12, ctx->r7);
    // 0x80026F44: addu        $a2, $t6, $a3
    ctx->r6 = ADD32(ctx->r14, ctx->r7);
    // 0x80026F48: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80026F4C: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x80026F50: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80026F54: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80026F58: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026F5C: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80026F60: lh          $t2, 0x2($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X2);
    // 0x80026F64: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026F68: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80026F6C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80026F70: c.eq.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl == ctx->f14.fl;
    // 0x80026F74: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80026F78: bc1t        L_8002718C
    if (c1cs) {
        // 0x80026F7C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8002718C;
    }
    // 0x80026F7C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80026F80: sub.s       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80026F84: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80026F88: sub.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x80026F8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80026F90: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80026F94: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80026F98: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x80026F9C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80026FA0: addu        $t4, $s4, $t3
    ctx->r12 = ADD32(ctx->r20, ctx->r11);
    // 0x80026FA4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80026FA8: addu        $v1, $s4, $t8
    ctx->r3 = ADD32(ctx->r20, ctx->r24);
    // 0x80026FAC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80026FB0: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x80026FB4: addu        $t9, $s2, $s0
    ctx->r25 = ADD32(ctx->r18, ctx->r16);
    // 0x80026FB8: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80026FBC: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x80026FC0: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80026FC4: sub.s       $f6, $f22, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f14.fl;
    // 0x80026FC8: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80026FCC: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80026FD0: nop

    // 0x80026FD4: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80026FD8: sub.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80026FDC: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x80026FE0: lwc1        $f4, -0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80026FE4: sb          $s0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r16;
    // 0x80026FE8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80026FEC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80026FF0: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x80026FF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80026FF8: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x80026FFC: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80027000: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80027004: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80027008: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8002700C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80027010: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80027014: lwc1        $f18, -0x4($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, -0X4);
    // 0x80027018: nop

    // 0x8002701C: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80027020: bne         $at, $zero, L_80026F18
    if (ctx->r1 != 0) {
        // 0x80027024: swc1        $f8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
            goto L_80026F18;
    }
    // 0x80027024: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80027028: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002702C:
    // 0x8002702C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80027030: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x80027034: addiu       $s4, $sp, 0x94
    ctx->r20 = ADD32(ctx->r29, 0X94);
    // 0x80027038: addiu       $s1, $s5, -0x1
    ctx->r17 = ADD32(ctx->r21, -0X1);
L_8002703C:
    // 0x8002703C: blez        $s1, L_800270BC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80027040: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800270BC;
    }
    // 0x80027040: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80027044: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
L_80027048:
    // 0x80027048: lb          $t8, 0x1($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X1);
    // 0x8002704C: lb          $t3, 0x0($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X0);
    // 0x80027050: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80027054: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80027058: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x8002705C: addu        $t2, $a1, $t9
    ctx->r10 = ADD32(ctx->r5, ctx->r25);
    // 0x80027060: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80027064: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80027068: addu        $a0, $s0, $s3
    ctx->r4 = ADD32(ctx->r16, ctx->r19);
    // 0x8002706C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80027070: nop

    // 0x80027074: bc1f        L_800270A0
    if (!c1cs) {
        // 0x80027078: nop
    
            goto L_800270A0;
    }
    // 0x80027078: nop

    // 0x8002707C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80027080: lb          $t6, 0x1($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1);
    // 0x80027084: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x80027088: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8002708C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80027090: lb          $t7, 0x1($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1);
    // 0x80027094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80027098: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8002709C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_800270A0:
    // 0x800270A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800270A4: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x800270A8: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800270AC: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800270B0: bne         $at, $zero, L_80027048
    if (ctx->r1 != 0) {
        // 0x800270B4: addu        $v1, $s2, $s0
        ctx->r3 = ADD32(ctx->r18, ctx->r16);
            goto L_80027048;
    }
    // 0x800270B4: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
    // 0x800270B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800270BC:
    // 0x800270BC: beq         $a2, $zero, L_8002703C
    if (ctx->r6 == 0) {
        // 0x800270C0: nop
    
            goto L_8002703C;
    }
    // 0x800270C0: nop

    // 0x800270C4: blez        $s1, L_8002718C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800270C8: lui         $s6, 0x8012
        ctx->r22 = S32(0X8012 << 16);
            goto L_8002718C;
    }
    // 0x800270C8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800270CC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800270D0: addiu       $s5, $s5, -0x2608
    ctx->r21 = ADD32(ctx->r21, -0X2608);
    // 0x800270D4: addiu       $s6, $s6, -0x2604
    ctx->r22 = ADD32(ctx->r22, -0X2604);
    // 0x800270D8: addu        $a0, $s0, $s3
    ctx->r4 = ADD32(ctx->r16, ctx->r19);
L_800270DC:
    // 0x800270DC: lb          $t2, 0x0($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X0);
    // 0x800270E0: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x800270E4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800270E8: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x800270EC: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x800270F0: lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X0);
    // 0x800270F4: lb          $t3, 0x1($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X1);
    // 0x800270F8: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800270FC: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80027100: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80027104: lb          $v0, 0x6($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X6);
    // 0x80027108: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x8002710C: lb          $t6, 0x0($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X0);
    // 0x80027110: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80027114: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80027118: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8002711C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80027120: lb          $v1, 0x6($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X6);
    // 0x80027124: sra         $v0, $t9, 24
    ctx->r2 = S32(SIGNED(ctx->r25) >> 24);
    // 0x80027128: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x8002712C: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x80027130: beq         $v0, $zero, L_80027174
    if (ctx->r2 == 0) {
        // 0x80027134: sra         $t3, $t2, 24
        ctx->r11 = S32(SIGNED(ctx->r10) >> 24);
            goto L_80027174;
    }
    // 0x80027134: sra         $t3, $t2, 24
    ctx->r11 = S32(SIGNED(ctx->r10) >> 24);
    // 0x80027138: bne         $t3, $zero, L_80027174
    if (ctx->r11 != 0) {
        // 0x8002713C: addu        $v1, $s2, $s0
        ctx->r3 = ADD32(ctx->r18, ctx->r16);
            goto L_80027174;
    }
    // 0x8002713C: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
    // 0x80027140: lb          $t4, 0x0($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X0);
    // 0x80027144: lb          $t7, 0x1($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1);
    // 0x80027148: sll         $t5, $t4, 17
    ctx->r13 = S32(ctx->r12 << 17);
    // 0x8002714C: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x80027150: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80027154: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80027158: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8002715C: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x80027160: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80027164: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80027168: addu        $a0, $s4, $t2
    ctx->r4 = ADD32(ctx->r20, ctx->r10);
    // 0x8002716C: jal         0x800271C4
    // 0x80027170: addu        $a1, $s4, $t3
    ctx->r5 = ADD32(ctx->r20, ctx->r11);
    void_generate_primitive(rdram, ctx);
        goto after_0;
    // 0x80027170: addu        $a1, $s4, $t3
    ctx->r5 = ADD32(ctx->r20, ctx->r11);
    after_0:
L_80027174:
    // 0x80027174: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80027178: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x8002717C: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80027180: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80027184: bne         $at, $zero, L_800270DC
    if (ctx->r1 != 0) {
        // 0x80027188: addu        $a0, $s0, $s3
        ctx->r4 = ADD32(ctx->r16, ctx->r19);
            goto L_800270DC;
    }
    // 0x80027188: addu        $a0, $s0, $s3
    ctx->r4 = ADD32(ctx->r16, ctx->r19);
L_8002718C:
    // 0x8002718C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80027190: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80027194: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80027198: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002719C: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800271A0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800271A4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800271A8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800271AC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800271B0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800271B4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800271B8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800271BC: jr          $ra
    // 0x800271C0: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800271C0: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void copy_controller_pak_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800765E0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800765E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800765E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800765EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800765F0: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800765F4: jal         0x80075B34
    // 0x800765F8: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800765F8: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    after_0:
    // 0x800765FC: beq         $v0, $zero, L_80076620
    if (ctx->r2 == 0) {
        // 0x80076600: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_80076620;
    }
    // 0x80076600: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80076604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076608: jal         0x80075D44
    // 0x8007660C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x8007660C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x80076610: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80076614: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x80076618: b           L_80076730
    // 0x8007661C: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
        goto L_80076730;
    // 0x8007661C: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
L_80076620:
    // 0x80076620: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80076624: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076628: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8007662C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80076630: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80076634: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80076638: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8007663C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80076640: jal         0x800D0AE0
    // 0x80076644: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    osPfsFileState_recomp(rdram, ctx);
        goto after_2;
    // 0x80076644: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80076648: beq         $v0, $zero, L_8007666C
    if (ctx->r2 == 0) {
        // 0x8007664C: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_8007666C;
    }
    // 0x8007664C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80076650: jal         0x80075D44
    // 0x80076654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_3;
    // 0x80076654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80076658: sll         $v0, $s0, 30
    ctx->r2 = S32(ctx->r16 << 30);
    // 0x8007665C: ori         $t9, $v0, 0x9
    ctx->r25 = ctx->r2 | 0X9;
    // 0x80076660: b           L_80076730
    // 0x80076664: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80076730;
    // 0x80076664: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80076668: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_8007666C:
    // 0x8007666C: jal         0x80070EDC
    // 0x80076670: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80076670: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x80076674: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80076678: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8007667C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80076680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076684: jal         0x80076868
    // 0x80076688: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80076688: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x8007668C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076690: jal         0x80075D44
    // 0x80076694: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_6;
    // 0x80076694: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_6:
    // 0x80076698: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8007669C: addiu       $a0, $sp, 0x42
    ctx->r4 = ADD32(ctx->r29, 0X42);
    // 0x800766A0: beq         $v1, $zero, L_800766C4
    if (ctx->r3 == 0) {
        // 0x800766A4: addiu       $a2, $zero, 0x10
        ctx->r6 = ADD32(0, 0X10);
            goto L_800766C4;
    }
    // 0x800766A4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800766A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800766AC: jal         0x80071380
    // 0x800766B0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x800766B0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_7:
    // 0x800766B4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800766B8: sll         $t0, $s0, 30
    ctx->r8 = S32(ctx->r16 << 30);
    // 0x800766BC: b           L_80076730
    // 0x800766C0: or          $v0, $t0, $v1
    ctx->r2 = ctx->r8 | ctx->r3;
        goto L_80076730;
    // 0x800766C0: or          $v0, $t0, $v1
    ctx->r2 = ctx->r8 | ctx->r3;
L_800766C4:
    // 0x800766C4: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x800766C8: jal         0x80076BE4
    // 0x800766CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    font_codes_to_string(rdram, ctx);
        goto after_8;
    // 0x800766CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800766D0: addiu       $a0, $sp, 0x3E
    ctx->r4 = ADD32(ctx->r29, 0X3E);
    // 0x800766D4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800766D8: jal         0x80076BE4
    // 0x800766DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    font_codes_to_string(rdram, ctx);
        goto after_9;
    // 0x800766DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x800766E0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800766E4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800766E8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800766EC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800766F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800766F4: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x800766F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800766FC: jal         0x8007692C
    // 0x80076700: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    write_controller_pak_file(rdram, ctx);
        goto after_10;
    // 0x80076700: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_10:
    // 0x80076704: beq         $v0, $zero, L_8007671C
    if (ctx->r2 == 0) {
        // 0x80076708: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8007671C;
    }
    // 0x80076708: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007670C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80076710: nop

    // 0x80076714: sll         $t4, $t3, 30
    ctx->r12 = S32(ctx->r11 << 30);
    // 0x80076718: or          $v1, $v0, $t4
    ctx->r3 = ctx->r2 | ctx->r12;
L_8007671C:
    // 0x8007671C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80076720: jal         0x80071380
    // 0x80076724: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_11;
    // 0x80076724: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_11:
    // 0x80076728: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8007672C: nop

L_80076730:
    // 0x80076730: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80076734: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80076738: jr          $ra
    // 0x8007673C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8007673C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void gfxtask_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078558: jal         0x800799CC
    // 0x8007855C: nop

    osScGetInterruptQ(rdram, ctx);
        goto after_0;
    // 0x8007855C: nop

    after_0:
    // 0x80078560: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078564: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80078568: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007856C: sw          $v0, 0x66A0($at)
    MEM_W(0X66A0, ctx->r1) = ctx->r2;
    // 0x80078570: addiu       $a1, $a1, 0x6458
    ctx->r5 = ADD32(ctx->r5, 0X6458);
    // 0x80078574: addiu       $a0, $a0, 0x6440
    ctx->r4 = ADD32(ctx->r4, 0X6440);
    // 0x80078578: jal         0x800C8D80
    // 0x8007857C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8007857C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80078580: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80078584: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80078588: addiu       $a1, $a1, 0x6490
    ctx->r5 = ADD32(ctx->r5, 0X6490);
    // 0x8007858C: addiu       $a0, $a0, 0x6460
    ctx->r4 = ADD32(ctx->r4, 0X6460);
    // 0x80078590: jal         0x800C8D80
    // 0x80078594: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80078594: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80078598: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007859C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800785A0: addiu       $a1, $a1, 0x64B0
    ctx->r5 = ADD32(ctx->r5, 0X64B0);
    // 0x800785A4: addiu       $a0, $a0, 0x6478
    ctx->r4 = ADD32(ctx->r4, 0X6478);
    // 0x800785A8: jal         0x800C8D80
    // 0x800785AC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x800785AC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x800785B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800785B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800785B8: jr          $ra
    // 0x800785BC: nop

    return;
    // 0x800785BC: nop

;}
RECOMP_FUNC void get_next_particle_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4A34: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B4A38: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800B4A3C: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x800B4A40: addiu       $a1, $a1, 0x3278
    ctx->r5 = ADD32(ctx->r5, 0X3278);
    // 0x800B4A44: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B4A48: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B4A4C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B4A50: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4A54: bne         $at, $zero, L_800B4A74
    if (ctx->r1 != 0) {
        // 0x800B4A58: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B4A74;
    }
    // 0x800B4A58: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B4A5C:
    // 0x800B4A5C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B4A60: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B4A64: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800B4A68: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4A6C: beq         $at, $zero, L_800B4A5C
    if (ctx->r1 == 0) {
        // 0x800B4A70: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B4A5C;
    }
    // 0x800B4A70: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B4A74:
    // 0x800B4A74: lw          $t9, 0x3280($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3280);
    // 0x800B4A78: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B4A7C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B4A80: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800B4A84: jr          $ra
    // 0x800B4A88: nop

    return;
    // 0x800B4A88: nop

;}
RECOMP_FUNC void set_scene_viewport_num(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024A20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024A24: sw          $a0, -0x2704($at)
    MEM_W(-0X2704, ctx->r1) = ctx->r4;
    // 0x80024A28: jr          $ra
    // 0x80024A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80024A2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mempool_get_pool(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007182C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80071830: lw          $v1, 0x3B40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3B40);
    // 0x80071834: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80071838: blez        $v1, L_80071884
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007183C: sll         $t6, $v1, 4
        ctx->r14 = S32(ctx->r3 << 4);
            goto L_80071884;
    }
    // 0x8007183C: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80071840: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80071844: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x80071848: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8007184C:
    // 0x8007184C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80071850: nop

    // 0x80071854: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80071858: beq         $at, $zero, L_80071878
    if (ctx->r1 == 0) {
        // 0x8007185C: nop
    
            goto L_80071878;
    }
    // 0x8007185C: nop

    // 0x80071860: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80071864: nop

    // 0x80071868: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8007186C: sltu        $at, $a1, $t9
    ctx->r1 = ctx->r5 < ctx->r25 ? 1 : 0;
    // 0x80071870: bne         $at, $zero, L_80071884
    if (ctx->r1 != 0) {
        // 0x80071874: nop
    
            goto L_80071884;
    }
    // 0x80071874: nop

L_80071878:
    // 0x80071878: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007187C: bgtz        $v1, L_8007184C
    if (SIGNED(ctx->r3) > 0) {
        // 0x80071880: addiu       $v0, $v0, -0x10
        ctx->r2 = ADD32(ctx->r2, -0X10);
            goto L_8007184C;
    }
    // 0x80071880: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
L_80071884:
    // 0x80071884: jr          $ra
    // 0x80071888: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80071888: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void obj_elevation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C44C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C450: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001C454: lwc1        $f2, 0x5BD0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5BD0);
    // 0x8001C458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001C45C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001C460: addiu       $a0, $a0, -0x4B68
    ctx->r4 = ADD32(ctx->r4, -0X4B68);
    // 0x8001C464: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_8001C468:
    // 0x8001C468: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8001C46C: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8001C470: nop

    // 0x8001C474: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8001C478: nop

    // 0x8001C47C: bc1t        L_8001C4A0
    if (c1cs) {
        // 0x8001C480: nop
    
            goto L_8001C4A0;
    }
    // 0x8001C480: nop

    // 0x8001C484: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8001C488: nop

    // 0x8001C48C: bc1f        L_8001C4A0
    if (!c1cs) {
        // 0x8001C490: nop
    
            goto L_8001C4A0;
    }
    // 0x8001C490: nop

    // 0x8001C494: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8001C498: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001C49C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8001C4A0:
    // 0x8001C4A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001C4A4: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8001C4A8: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001C4AC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8001C4B0: bne         $at, $zero, L_8001C468
    if (ctx->r1 != 0) {
        // 0x8001C4B4: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8001C468;
    }
    // 0x8001C4B4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001C4B8: jr          $ra
    // 0x8001C4BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001C4BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void trackmenu_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EC48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008EC4C: lw          $v0, 0xEFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XEFC);
    // 0x8008EC50: jr          $ra
    // 0x8008EC54: nop

    return;
    // 0x8008EC54: nop

;}
RECOMP_FUNC void init_object_interaction_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FD20: sw          $a1, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r5;
    // 0x8000FD24: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8000FD28: sb          $t6, 0x13($a1)
    MEM_B(0X13, ctx->r5) = ctx->r14;
    // 0x8000FD2C: jr          $ra
    // 0x8000FD30: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    return;
    // 0x8000FD30: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
;}
RECOMP_FUNC void __alCSeqNextDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C894C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C8950: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800C8954: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800C8958: bne         $t6, $zero, L_800C8968
    if (ctx->r14 != 0) {
        // 0x800C895C: lw          $v0, 0x10($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X10);
            goto L_800C8968;
    }
    // 0x800C895C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800C8960: jr          $ra
    // 0x800C8964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C8964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C8968:
    // 0x800C8968: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C896C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800C8970: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
L_800C8974:
    // 0x800C8974: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x800C8978: srlv        $t7, $a1, $a2
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r6 & 31));
    // 0x800C897C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C8980: beql        $t8, $zero, L_800C89C4
    if (ctx->r24 == 0) {
        // 0x800C8984: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C89C4;
    }
    goto skip_0;
    // 0x800C8984: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_0:
    // 0x800C8988: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C898C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C8990: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C8994: beql        $t3, $zero, L_800C89B0
    if (ctx->r11 == 0) {
        // 0x800C8998: lw          $t0, 0xB8($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XB8);
            goto L_800C89B0;
    }
    goto skip_1;
    // 0x800C8998: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
    skip_1:
    // 0x800C899C: lw          $t4, 0xB8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XB8);
    // 0x800C89A0: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C89A4: sw          $t5, 0xB8($a3)
    MEM_W(0XB8, ctx->r7) = ctx->r13;
    // 0x800C89A8: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800C89AC: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
L_800C89B0:
    // 0x800C89B0: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C89B4: beql        $at, $zero, L_800C89C4
    if (ctx->r1 == 0) {
        // 0x800C89B8: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C89C4;
    }
    goto skip_2;
    // 0x800C89B8: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_2:
    // 0x800C89BC: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800C89C0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C89C4:
    // 0x800C89C4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C89C8: beq         $t8, $zero, L_800C8A08
    if (ctx->r24 == 0) {
        // 0x800C89CC: addiu       $t6, $a2, 0x2
        ctx->r14 = ADD32(ctx->r6, 0X2);
            goto L_800C8A08;
    }
    // 0x800C89CC: addiu       $t6, $a2, 0x2
    ctx->r14 = ADD32(ctx->r6, 0X2);
    // 0x800C89D0: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C89D4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C89D8: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C89DC: beql        $t3, $zero, L_800C89F8
    if (ctx->r11 == 0) {
        // 0x800C89E0: lw          $t0, 0xBC($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XBC);
            goto L_800C89F8;
    }
    goto skip_3;
    // 0x800C89E0: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
    skip_3:
    // 0x800C89E4: lw          $t4, 0xBC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XBC);
    // 0x800C89E8: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C89EC: sw          $t5, 0xBC($a3)
    MEM_W(0XBC, ctx->r7) = ctx->r13;
    // 0x800C89F0: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800C89F4: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
L_800C89F8:
    // 0x800C89F8: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C89FC: beql        $at, $zero, L_800C8A0C
    if (ctx->r1 == 0) {
        // 0x800C8A00: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C8A0C;
    }
    goto skip_4;
    // 0x800C8A00: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_4:
    // 0x800C8A04: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800C8A08:
    // 0x800C8A08: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C8A0C:
    // 0x800C8A0C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C8A10: beq         $t8, $zero, L_800C8A50
    if (ctx->r24 == 0) {
        // 0x800C8A14: addiu       $t6, $a2, 0x3
        ctx->r14 = ADD32(ctx->r6, 0X3);
            goto L_800C8A50;
    }
    // 0x800C8A14: addiu       $t6, $a2, 0x3
    ctx->r14 = ADD32(ctx->r6, 0X3);
    // 0x800C8A18: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C8A1C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C8A20: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C8A24: beql        $t3, $zero, L_800C8A40
    if (ctx->r11 == 0) {
        // 0x800C8A28: lw          $t0, 0xC0($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XC0);
            goto L_800C8A40;
    }
    goto skip_5;
    // 0x800C8A28: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
    skip_5:
    // 0x800C8A2C: lw          $t4, 0xC0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC0);
    // 0x800C8A30: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C8A34: sw          $t5, 0xC0($a3)
    MEM_W(0XC0, ctx->r7) = ctx->r13;
    // 0x800C8A38: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800C8A3C: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
L_800C8A40:
    // 0x800C8A40: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C8A44: beql        $at, $zero, L_800C8A54
    if (ctx->r1 == 0) {
        // 0x800C8A48: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C8A54;
    }
    goto skip_6;
    // 0x800C8A48: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_6:
    // 0x800C8A4C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800C8A50:
    // 0x800C8A50: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C8A54:
    // 0x800C8A54: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C8A58: beql        $t8, $zero, L_800C8A98
    if (ctx->r24 == 0) {
        // 0x800C8A5C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C8A98;
    }
    goto skip_7;
    // 0x800C8A5C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_7:
    // 0x800C8A60: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C8A64: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C8A68: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C8A6C: beql        $t3, $zero, L_800C8A84
    if (ctx->r11 == 0) {
        // 0x800C8A70: lw          $a1, 0xC4($a3)
        ctx->r5 = MEM_W(ctx->r7, 0XC4);
            goto L_800C8A84;
    }
    goto skip_8;
    // 0x800C8A70: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
    skip_8:
    // 0x800C8A74: lw          $t4, 0xC4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC4);
    // 0x800C8A78: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C8A7C: sw          $t5, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->r13;
    // 0x800C8A80: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
L_800C8A84:
    // 0x800C8A84: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800C8A88: beql        $at, $zero, L_800C8A98
    if (ctx->r1 == 0) {
        // 0x800C8A8C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C8A98;
    }
    goto skip_9;
    // 0x800C8A8C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_9:
    // 0x800C8A90: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C8A94: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_800C8A98:
    // 0x800C8A98: bnel        $a2, $t2, L_800C8974
    if (ctx->r6 != ctx->r10) {
        // 0x800C8A9C: lw          $a1, 0x4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X4);
            goto L_800C8974;
    }
    goto skip_10;
    // 0x800C8A9C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x800C8AA0: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800C8AA4: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x800C8AA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C8AAC: jr          $ra
    // 0x800C8AB0: nop

    return;
    // 0x800C8AB0: nop

;}
RECOMP_FUNC void set_camera_shake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A168: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006A16C: lw          $v1, 0x1260($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1260);
    // 0x8006A170: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A174: bltz        $v1, L_8006A19C
    if (SIGNED(ctx->r3) < 0) {
        // 0x8006A178: addiu       $v0, $t6, 0x1040
        ctx->r2 = ADD32(ctx->r14, 0X1040);
            goto L_8006A19C;
    }
    // 0x8006A178: addiu       $v0, $t6, 0x1040
    ctx->r2 = ADD32(ctx->r14, 0X1040);
    // 0x8006A17C: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8006A180: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8006A184: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8006A188: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
L_8006A18C:
    // 0x8006A18C: addiu       $v0, $v0, 0x44
    ctx->r2 = ADD32(ctx->r2, 0X44);
    // 0x8006A190: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8006A194: beq         $at, $zero, L_8006A18C
    if (ctx->r1 == 0) {
        // 0x8006A198: swc1        $f12, -0x14($v0)
        MEM_W(-0X14, ctx->r2) = ctx->f12.u32l;
            goto L_8006A18C;
    }
    // 0x8006A198: swc1        $f12, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->f12.u32l;
L_8006A19C:
    // 0x8006A19C: jr          $ra
    // 0x8006A1A0: nop

    return;
    // 0x8006A1A0: nop

;}
RECOMP_FUNC void filename_enter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009824C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80098250: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098254: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80098258: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8009825C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80098260: jal         0x8006A794
    // 0x80098264: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x80098264: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80098268: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009826C: jal         0x8006A7DC
    // 0x80098270: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    input_clamp_stick_x(rdram, ctx);
        goto after_1;
    // 0x80098270: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80098274: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80098278: slti        $at, $v0, -0x22
    ctx->r1 = SIGNED(ctx->r2) < -0X22 ? 1 : 0;
    // 0x8009827C: bne         $at, $zero, L_80098294
    if (ctx->r1 != 0) {
        // 0x80098280: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80098294;
    }
    // 0x80098280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80098284: slti        $at, $v0, 0x23
    ctx->r1 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
    // 0x80098288: beq         $at, $zero, L_80098294
    if (ctx->r1 == 0) {
        // 0x8009828C: nop
    
            goto L_80098294;
    }
    // 0x8009828C: nop

    // 0x80098290: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80098294:
    // 0x80098294: bgez        $a0, L_80098300
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80098298: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_80098300;
    }
    // 0x80098298: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009829C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800982A0: addiu       $v0, $v0, 0x71FC
    ctx->r2 = ADD32(ctx->r2, 0X71FC);
    // 0x800982A4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800982A8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800982AC: bltz        $t6, L_800982C0
    if (SIGNED(ctx->r14) < 0) {
        // 0x800982B0: addiu       $v1, $v1, 0x71F4
        ctx->r3 = ADD32(ctx->r3, 0X71F4);
            goto L_800982C0;
    }
    // 0x800982B0: addiu       $v1, $v1, 0x71F4
    ctx->r3 = ADD32(ctx->r3, 0X71F4);
    // 0x800982B4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800982B8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800982BC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800982C0:
    // 0x800982C0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800982C4: addiu       $v1, $v1, 0x71F4
    ctx->r3 = ADD32(ctx->r3, 0X71F4);
    // 0x800982C8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800982CC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800982D0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800982D4: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x800982D8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800982DC: beq         $t3, $t2, L_80098380
    if (ctx->r11 == ctx->r10) {
        // 0x800982E0: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80098380;
    }
    // 0x800982E0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800982E4: slti        $at, $t2, 0x1C
    ctx->r1 = SIGNED(ctx->r10) < 0X1C ? 1 : 0;
    // 0x800982E8: beq         $at, $zero, L_800982F8
    if (ctx->r1 == 0) {
        // 0x800982EC: addiu       $t4, $v0, -0x6
        ctx->r12 = ADD32(ctx->r2, -0X6);
            goto L_800982F8;
    }
    // 0x800982EC: addiu       $t4, $v0, -0x6
    ctx->r12 = ADD32(ctx->r2, -0X6);
    // 0x800982F0: b           L_80098380
    // 0x800982F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80098380;
    // 0x800982F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800982F8:
    // 0x800982F8: b           L_80098380
    // 0x800982FC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
        goto L_80098380;
    // 0x800982FC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80098300:
    // 0x80098300: blez        $a0, L_8009836C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80098304: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8009836C;
    }
    // 0x80098304: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80098308: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009830C: addiu       $v0, $v0, 0x71FC
    ctx->r2 = ADD32(ctx->r2, 0X71FC);
    // 0x80098310: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80098314: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80098318: bgtz        $t5, L_8009832C
    if (SIGNED(ctx->r13) > 0) {
        // 0x8009831C: addiu       $v1, $v1, 0x71F4
        ctx->r3 = ADD32(ctx->r3, 0X71F4);
            goto L_8009832C;
    }
    // 0x8009831C: addiu       $v1, $v1, 0x71F4
    ctx->r3 = ADD32(ctx->r3, 0X71F4);
    // 0x80098320: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80098324: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80098328: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8009832C:
    // 0x8009832C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80098330: addiu       $v1, $v1, 0x71F4
    ctx->r3 = ADD32(ctx->r3, 0X71F4);
    // 0x80098334: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80098338: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8009833C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80098340: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80098344: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80098348: beq         $t2, $t9, L_80098380
    if (ctx->r10 == ctx->r25) {
        // 0x8009834C: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80098380;
    }
    // 0x8009834C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80098350: slti        $at, $t9, 0x1C
    ctx->r1 = SIGNED(ctx->r25) < 0X1C ? 1 : 0;
    // 0x80098354: beq         $at, $zero, L_80098364
    if (ctx->r1 == 0) {
        // 0x80098358: addiu       $t3, $v0, -0x6
        ctx->r11 = ADD32(ctx->r2, -0X6);
            goto L_80098364;
    }
    // 0x80098358: addiu       $t3, $v0, -0x6
    ctx->r11 = ADD32(ctx->r2, -0X6);
    // 0x8009835C: b           L_80098380
    // 0x80098360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80098380;
    // 0x80098360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80098364:
    // 0x80098364: b           L_80098380
    // 0x80098368: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_80098380;
    // 0x80098368: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_8009836C:
    // 0x8009836C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80098370: addiu       $v1, $v1, 0x71F4
    ctx->r3 = ADD32(ctx->r3, 0X71F4);
    // 0x80098374: addiu       $v0, $v0, 0x71FC
    ctx->r2 = ADD32(ctx->r2, 0X71FC);
    // 0x80098378: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8009837C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80098380:
    // 0x80098380: lw          $a1, 0x722C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X722C);
    // 0x80098384: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80098388: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8009838C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80098390: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80098394: blez        $t5, L_80098498
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80098398: cvt.s.w     $f20, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80098498;
    }
    // 0x80098398: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009839C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800983A0: lwc1        $f0, 0x7210($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7210);
    // 0x800983A4: lui         $at, 0x41F8
    ctx->r1 = S32(0X41F8 << 16);
    // 0x800983A8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800983AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800983B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800983B4: addiu       $v0, $v0, 0x7210
    ctx->r2 = ADD32(ctx->r2, 0X7210);
L_800983B8:
    // 0x800983B8: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800983BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800983C0: bc1f        L_800983D8
    if (!c1cs) {
        // 0x800983C4: nop
    
            goto L_800983D8;
    }
    // 0x800983C4: nop

    // 0x800983C8: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800983CC: sub.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800983D0: b           L_800983E4
    // 0x800983D4: sub.s       $f14, $f20, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f6.fl;
        goto L_800983E4;
    // 0x800983D4: sub.s       $f14, $f20, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f6.fl;
L_800983D8:
    // 0x800983D8: add.s       $f8, $f20, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f2.fl;
    // 0x800983DC: sub.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800983E0: sub.s       $f14, $f20, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f0.fl;
L_800983E4:
    // 0x800983E4: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800983E8: nop

    // 0x800983EC: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800983F0: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800983F4: nop

    // 0x800983F8: bc1f        L_80098408
    if (!c1cs) {
        // 0x800983FC: nop
    
            goto L_80098408;
    }
    // 0x800983FC: nop

    // 0x80098400: b           L_8009840C
    // 0x80098404: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
        goto L_8009840C;
    // 0x80098404: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
L_80098408:
    // 0x80098408: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
L_8009840C:
    // 0x8009840C: lwc1        $f6, -0x7504($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7504);
    // 0x80098410: nop

    // 0x80098414: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80098418: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8009841C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80098420: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80098424: nop

    // 0x80098428: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8009842C: nop

    // 0x80098430: bc1f        L_80098458
    if (!c1cs) {
        // 0x80098434: nop
    
            goto L_80098458;
    }
    // 0x80098434: nop

L_80098438:
    // 0x80098438: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8009843C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80098440: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80098444: nop

    // 0x80098448: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8009844C: nop

    // 0x80098450: bc1t        L_80098438
    if (c1cs) {
        // 0x80098454: nop
    
            goto L_80098438;
    }
    // 0x80098454: nop

L_80098458:
    // 0x80098458: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8009845C: nop

    // 0x80098460: bc1f        L_8009848C
    if (!c1cs) {
        // 0x80098464: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_8009848C;
    }
    // 0x80098464: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_80098468:
    // 0x80098468: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8009846C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80098470: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80098474: nop

    // 0x80098478: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8009847C: nop

    // 0x80098480: bc1t        L_80098468
    if (c1cs) {
        // 0x80098484: nop
    
            goto L_80098468;
    }
    // 0x80098484: nop

    // 0x80098488: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_8009848C:
    // 0x8009848C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80098490: bne         $v1, $t6, L_800983B8
    if (ctx->r3 != ctx->r14) {
        // 0x80098494: nop
    
            goto L_800983B8;
    }
    // 0x80098494: nop

L_80098498:
    // 0x80098498: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009849C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800984A0: addiu       $a3, $a3, 0x723C
    ctx->r7 = ADD32(ctx->r7, 0X723C);
    // 0x800984A4: addiu       $v1, $v1, 0x1520
    ctx->r3 = ADD32(ctx->r3, 0X1520);
    // 0x800984A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800984AC: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x800984B0: andi        $t7, $t0, 0x9000
    ctx->r15 = ctx->r8 & 0X9000;
    // 0x800984B4: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800984B8: beq         $at, $zero, L_800986AC
    if (ctx->r1 == 0) {
        // 0x800984BC: andi        $t4, $t0, 0x9000
        ctx->r12 = ctx->r8 & 0X9000;
            goto L_800986AC;
    }
    // 0x800984BC: andi        $t4, $t0, 0x9000
    ctx->r12 = ctx->r8 & 0X9000;
    // 0x800984C0: beq         $t7, $zero, L_80098614
    if (ctx->r15 == 0) {
        // 0x800984C4: andi        $t7, $t0, 0x4000
        ctx->r15 = ctx->r8 & 0X4000;
            goto L_80098614;
    }
    // 0x800984C4: andi        $t7, $t0, 0x4000
    ctx->r15 = ctx->r8 & 0X4000;
    // 0x800984C8: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800984CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800984D0: slti        $at, $t1, 0x1D
    ctx->r1 = SIGNED(ctx->r9) < 0X1D ? 1 : 0;
    // 0x800984D4: beq         $at, $zero, L_8009854C
    if (ctx->r1 == 0) {
        // 0x800984D8: addiu       $t0, $t0, 0x7238
        ctx->r8 = ADD32(ctx->r8, 0X7238);
            goto L_8009854C;
    }
    // 0x800984D8: addiu       $t0, $t0, 0x7238
    ctx->r8 = ADD32(ctx->r8, 0X7238);
    // 0x800984DC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800984E0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800984E4: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x800984E8: lbu         $t8, 0x14EC($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X14EC);
    // 0x800984EC: addu        $t2, $t9, $v0
    ctx->r10 = ADD32(ctx->r25, ctx->r2);
    // 0x800984F0: sb          $t8, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r24;
    // 0x800984F4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800984F8: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800984FC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80098500: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80098504: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80098508: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8009850C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80098510: jal         0x80001D04
    // 0x80098514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80098514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80098518: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009851C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80098520: addiu       $a3, $a3, 0x723C
    ctx->r7 = ADD32(ctx->r7, 0X723C);
    // 0x80098524: addiu       $v1, $v1, 0x1520
    ctx->r3 = ADD32(ctx->r3, 0X1520);
    // 0x80098528: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8009852C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80098530: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80098534: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80098538: bne         $at, $zero, L_800986FC
    if (ctx->r1 != 0) {
        // 0x8009853C: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800986FC;
    }
    // 0x8009853C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80098540: lw          $t3, 0x722C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X722C);
    // 0x80098544: b           L_800986FC
    // 0x80098548: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
        goto L_800986FC;
    // 0x80098548: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
L_8009854C:
    // 0x8009854C: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80098550: bne         $t1, $at, L_8009858C
    if (ctx->r9 != ctx->r1) {
        // 0x80098554: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009858C;
    }
    // 0x80098554: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80098558: blez        $v0, L_8009857C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009855C: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8009857C;
    }
    // 0x8009855C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80098560: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80098564: addiu       $t0, $t0, 0x7238
    ctx->r8 = ADD32(ctx->r8, 0X7238);
    // 0x80098568: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8009856C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80098570: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80098574: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80098578: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
L_8009857C:
    // 0x8009857C: jal         0x80001D04
    // 0x80098580: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x80098580: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80098584: b           L_80098700
    // 0x80098588: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
        goto L_80098700;
    // 0x80098588: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_8009858C:
    // 0x8009858C: bne         $v0, $zero, L_800985B0
    if (ctx->r2 != 0) {
        // 0x80098590: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800985B0;
    }
    // 0x80098590: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80098594: addiu       $t0, $t0, 0x7238
    ctx->r8 = ADD32(ctx->r8, 0X7238);
    // 0x80098598: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8009859C: nop

    // 0x800985A0: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x800985A4: nop

    // 0x800985A8: bne         $t8, $zero, L_800985EC
    if (ctx->r24 != 0) {
        // 0x800985AC: nop
    
            goto L_800985EC;
    }
    // 0x800985AC: nop

L_800985B0:
    // 0x800985B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800985B4: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800985B8: addiu       $t0, $t0, 0x7238
    ctx->r8 = ADD32(ctx->r8, 0X7238);
    // 0x800985BC: beq         $at, $zero, L_800985EC
    if (ctx->r1 == 0) {
        // 0x800985C0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800985EC;
    }
    // 0x800985C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800985C4: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_800985C8:
    // 0x800985C8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800985CC: nop

    // 0x800985D0: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x800985D4: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
    // 0x800985D8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x800985DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800985E0: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800985E4: bne         $at, $zero, L_800985C8
    if (ctx->r1 != 0) {
        // 0x800985E8: nop
    
            goto L_800985C8;
    }
    // 0x800985E8: nop

L_800985EC:
    // 0x800985EC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800985F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800985F4: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800985F8: jal         0x80001D04
    // 0x800985FC: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800985FC: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    after_4:
    // 0x80098600: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80098604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098608: b           L_800986FC
    // 0x8009860C: sw          $t6, 0x7208($at)
    MEM_W(0X7208, ctx->r1) = ctx->r14;
        goto L_800986FC;
    // 0x8009860C: sw          $t6, 0x7208($at)
    MEM_W(0X7208, ctx->r1) = ctx->r14;
    // 0x80098610: andi        $t7, $t0, 0x4000
    ctx->r15 = ctx->r8 & 0X4000;
L_80098614:
    // 0x80098614: beq         $t7, $zero, L_80098650
    if (ctx->r15 == 0) {
        // 0x80098618: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80098650;
    }
    // 0x80098618: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009861C: blez        $v0, L_80098630
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80098620: addiu       $t0, $t0, 0x7238
        ctx->r8 = ADD32(ctx->r8, 0X7238);
            goto L_80098630;
    }
    // 0x80098620: addiu       $t0, $t0, 0x7238
    ctx->r8 = ADD32(ctx->r8, 0X7238);
    // 0x80098624: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80098628: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8009862C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80098630:
    // 0x80098630: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80098634: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80098638: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x8009863C: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x80098640: jal         0x80001D04
    // 0x80098644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x80098644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80098648: b           L_80098700
    // 0x8009864C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
        goto L_80098700;
    // 0x8009864C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80098650:
    // 0x80098650: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80098654: bgez        $a0, L_80098660
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80098658: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80098660;
    }
    // 0x80098658: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8009865C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80098660:
    // 0x80098660: blez        $a0, L_8009866C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80098664: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8009866C;
    }
    // 0x80098664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80098668: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8009866C:
    // 0x8009866C: bgez        $v0, L_80098678
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80098670: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80098678;
    }
    // 0x80098670: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80098674: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_80098678:
    // 0x80098678: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8009867C: bne         $at, $zero, L_80098688
    if (ctx->r1 != 0) {
        // 0x80098680: nop
    
            goto L_80098688;
    }
    // 0x80098680: nop

    // 0x80098684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80098688:
    // 0x80098688: beq         $v0, $t1, L_800986FC
    if (ctx->r2 == ctx->r9) {
        // 0x8009868C: nop
    
            goto L_800986FC;
    }
    // 0x8009868C: nop

    // 0x80098690: jal         0x80001D04
    // 0x80098694: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x80098694: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_6:
    // 0x80098698: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009869C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800986A0: lw          $t3, 0x722C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X722C);
    // 0x800986A4: b           L_800986FC
    // 0x800986A8: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
        goto L_800986FC;
    // 0x800986A8: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
L_800986AC:
    // 0x800986AC: beq         $t4, $zero, L_800986D0
    if (ctx->r12 == 0) {
        // 0x800986B0: andi        $t6, $t0, 0x4000
        ctx->r14 = ctx->r8 & 0X4000;
            goto L_800986D0;
    }
    // 0x800986B0: andi        $t6, $t0, 0x4000
    ctx->r14 = ctx->r8 & 0X4000;
    // 0x800986B4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800986B8: jal         0x80001D04
    // 0x800986BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x800986BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800986C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800986C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800986C8: b           L_800986FC
    // 0x800986CC: sw          $t5, 0x7208($at)
    MEM_W(0X7208, ctx->r1) = ctx->r13;
        goto L_800986FC;
    // 0x800986CC: sw          $t5, 0x7208($at)
    MEM_W(0X7208, ctx->r1) = ctx->r13;
L_800986D0:
    // 0x800986D0: beq         $t6, $zero, L_800986FC
    if (ctx->r14 == 0) {
        // 0x800986D4: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800986FC;
    }
    // 0x800986D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800986D8: addiu       $t0, $t0, 0x7238
    ctx->r8 = ADD32(ctx->r8, 0X7238);
    // 0x800986DC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800986E0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800986E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800986E8: addu        $t2, $t9, $t7
    ctx->r10 = ADD32(ctx->r25, ctx->r15);
    // 0x800986EC: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x800986F0: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800986F4: jal         0x80001D04
    // 0x800986F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800986F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_800986FC:
    // 0x800986FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80098700:
    // 0x80098700: jal         0x80097E54
    // 0x80098704: nop

    filename_render(rdram, ctx);
        goto after_9;
    // 0x80098704: nop

    after_9:
    // 0x80098708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009870C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80098710: lw          $v0, 0x7208($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7208);
    // 0x80098714: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80098718: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8009871C: jr          $ra
    // 0x80098720: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80098720: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void obj_loop_pigrocketeer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800429D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800429DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800429E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800429E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800429E8: jal         0x8001F494
    // 0x800429EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x800429EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x800429F0: jal         0x8000BF44
    // 0x800429F4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    racerfx_get_boost(rdram, ctx);
        goto after_1;
    // 0x800429F4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
    // 0x800429F8: beq         $v0, $zero, L_80042A50
    if (ctx->r2 == 0) {
        // 0x800429FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80042A50;
    }
    // 0x800429FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042A00: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80042A04: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x80042A08: beq         $v1, $zero, L_80042A4C
    if (ctx->r3 == 0) {
        // 0x80042A0C: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80042A4C;
    }
    // 0x80042A0C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80042A10: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80042A14: lbu         $t6, 0x72($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X72);
    // 0x80042A18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80042A1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80042A20: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80042A24: sb          $t8, 0x72($v1)
    MEM_B(0X72, ctx->r3) = ctx->r24;
    // 0x80042A28: sb          $t9, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r25;
    // 0x80042A2C: swc1        $f4, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f4.u32l;
    // 0x80042A30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80042A34: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80042A38: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80042A3C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80042A40: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80042A44: jal         0x8000B750
    // 0x80042A48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8000B750(rdram, ctx);
        goto after_2;
    // 0x80042A48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
L_80042A4C:
    // 0x80042A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80042A50:
    // 0x80042A50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042A54: jr          $ra
    // 0x80042A58: nop

    return;
    // 0x80042A58: nop

;}
RECOMP_FUNC void transition_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0AE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C0AEC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C0AF0: lw          $t6, 0x373C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X373C);
    // 0x800C0AF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C0AF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C0AFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C0B00: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C0B04: beq         $t6, $zero, L_800C0C30
    if (ctx->r14 == 0) {
        // 0x800C0B08: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800C0C30;
    }
    // 0x800C0B08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C0B0C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800C0B10: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800C0B14: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0B18: bne         $t7, $zero, L_800C0B3C
    if (ctx->r15 != 0) {
        // 0x800C0B1C: nop
    
            goto L_800C0B3C;
    }
    // 0x800C0B1C: nop

    // 0x800C0B20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0B24: lwc1        $f12, -0x6778($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6778);
    // 0x800C0B28: jal         0x80068160
    // 0x800C0B2C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    set_ortho_matrix_height(rdram, ctx);
        goto after_0;
    // 0x800C0B2C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C0B30: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C0B34: b           L_800C0B54
    // 0x800C0B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0B54;
    // 0x800C0B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0B3C:
    // 0x800C0B3C: lwc1        $f12, -0x6774($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6774);
    // 0x800C0B40: jal         0x80068160
    // 0x800C0B44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    set_ortho_matrix_height(rdram, ctx);
        goto after_1;
    // 0x800C0B44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x800C0B48: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C0B4C: nop

    // 0x800C0B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0B54:
    // 0x800C0B54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C0B58: jal         0x8006816C
    // 0x800C0B5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    mtx_ortho(rdram, ctx);
        goto after_2;
    // 0x800C0B5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x800C0B60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C0B64: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C0B68: jal         0x80068160
    // 0x800C0B6C: nop

    set_ortho_matrix_height(rdram, ctx);
        goto after_3;
    // 0x800C0B6C: nop

    after_3:
    // 0x800C0B70: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C0B74: lw          $t8, -0x5310($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5310);
    // 0x800C0B78: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C0B7C: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x800C0B80: beq         $at, $zero, L_800C0C24
    if (ctx->r1 == 0) {
        // 0x800C0B84: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800C0C24;
    }
    // 0x800C0B84: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800C0B88: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0B8C: addu        $at, $at, $t8
    gpr jr_addend_800C0B98 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C0B90: lw          $t8, -0x6770($at)
    ctx->r24 = ADD32(ctx->r1, -0X6770);
    // 0x800C0B94: nop

    // 0x800C0B98: jr          $t8
    // 0x800C0B9C: nop

    switch (jr_addend_800C0B98 >> 2) {
        case 0: goto L_800C0BA0; break;
        case 1: goto L_800C0BB4; break;
        case 2: goto L_800C0BC8; break;
        case 3: goto L_800C0BDC; break;
        case 4: goto L_800C0BF0; break;
        case 5: goto L_800C0C04; break;
        case 6: goto L_800C0C18; break;
        default: switch_error(__func__, 0x800C0B98, 0x800E9890);
    }
    // 0x800C0B9C: nop

L_800C0BA0:
    // 0x800C0BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0BA4: jal         0x800C0F28
    // 0x800C0BA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_fullscreen(rdram, ctx);
        goto after_4;
    // 0x800C0BA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800C0BAC: b           L_800C0C28
    // 0x800C0BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0BB4:
    // 0x800C0BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0BB8: jal         0x800C1904
    // 0x800C0BBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_barndoor_hor(rdram, ctx);
        goto after_5;
    // 0x800C0BBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800C0BC0: b           L_800C0C28
    // 0x800C0BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0BC8:
    // 0x800C0BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0BCC: jal         0x800C19FC
    // 0x800C0BD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_barndoor_vert(rdram, ctx);
        goto after_6;
    // 0x800C0BD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800C0BD4: b           L_800C0C28
    // 0x800C0BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0BDC:
    // 0x800C0BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0BE0: jal         0x800C2794
    // 0x800C0BE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_circle(rdram, ctx);
        goto after_7;
    // 0x800C0BE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800C0BE8: b           L_800C0C28
    // 0x800C0BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0BF0:
    // 0x800C0BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0BF4: jal         0x800C2918
    // 0x800C0BF8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_waves(rdram, ctx);
        goto after_8;
    // 0x800C0BF8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800C0BFC: b           L_800C0C28
    // 0x800C0C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0C04:
    // 0x800C0C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0C08: jal         0x800C2A68
    // 0x800C0C0C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_barndoor_diag(rdram, ctx);
        goto after_9;
    // 0x800C0C0C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x800C0C10: b           L_800C0C28
    // 0x800C0C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0C28;
    // 0x800C0C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0C18:
    // 0x800C0C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0C1C: jal         0x800C2E08
    // 0x800C0C20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_blank(rdram, ctx);
        goto after_10;
    // 0x800C0C20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
L_800C0C24:
    // 0x800C0C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0C28:
    // 0x800C0C28: jal         0x80066F1C
    // 0x800C0C2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    viewport_main(rdram, ctx);
        goto after_11;
    // 0x800C0C2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
L_800C0C30:
    // 0x800C0C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0C34: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C0C38: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C0C3C: jr          $ra
    // 0x800C0C40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C0C40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void material_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B938: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007B93C: addiu       $t3, $t3, 0x6922
    ctx->r11 = ADD32(ctx->r11, 0X6922);
    // 0x8007B940: lh          $v1, 0x0($t3)
    ctx->r3 = MEM_H(ctx->r11, 0X0);
    // 0x8007B944: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007B948: beq         $a1, $zero, L_8007BA0C
    if (ctx->r5 == 0) {
        // 0x8007B94C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8007BA0C;
    }
    // 0x8007B94C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007B950: beq         $a3, $zero, L_8007B988
    if (ctx->r7 == 0) {
        // 0x8007B954: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8007B988;
    }
    // 0x8007B954: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007B958: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x8007B95C: nop

    // 0x8007B960: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8007B964: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8007B968: beq         $at, $zero, L_8007B988
    if (ctx->r1 == 0) {
        // 0x8007B96C: nop
    
            goto L_8007B988;
    }
    // 0x8007B96C: nop

    // 0x8007B970: lh          $t9, 0x16($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X16);
    // 0x8007B974: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8007B978: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B97C: mflo        $t6
    ctx->r14 = lo;
    // 0x8007B980: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x8007B984: nop

L_8007B988:
    // 0x8007B988: addiu       $t4, $t4, 0x691C
    ctx->r12 = ADD32(ctx->r12, 0X691C);
    // 0x8007B98C: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x8007B990: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8007B994: or          $a2, $a2, $t7
    ctx->r6 = ctx->r6 | ctx->r15;
    // 0x8007B998: beq         $a1, $t8, L_8007B9E8
    if (ctx->r5 == ctx->r24) {
        // 0x8007B99C: nop
    
            goto L_8007B9E8;
    }
    // 0x8007B99C: nop

    // 0x8007B9A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B9A4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007B9A8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007B9AC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007B9B0: lh          $t2, 0xA($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XA);
    // 0x8007B9B4: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007B9B8: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x8007B9BC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8007B9C0: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x8007B9C4: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8007B9C8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007B9CC: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007B9D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007B9D4: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x8007B9D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8007B9DC: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8007B9E0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007B9E4: sw          $a1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r5;
L_8007B9E8:
    // 0x8007B9E8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007B9EC: addiu       $t2, $t2, 0x6920
    ctx->r10 = ADD32(ctx->r10, 0X6920);
    // 0x8007B9F0: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x8007B9F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007B9F8: bne         $t6, $zero, L_8007BA2C
    if (ctx->r14 != 0) {
        // 0x8007B9FC: nop
    
            goto L_8007BA2C;
    }
    // 0x8007B9FC: nop

    // 0x8007BA00: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007BA04: b           L_8007BA2C
    // 0x8007BA08: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
        goto L_8007BA2C;
    // 0x8007BA08: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
L_8007BA0C:
    // 0x8007BA0C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007BA10: addiu       $t2, $t2, 0x6920
    ctx->r10 = ADD32(ctx->r10, 0X6920);
    // 0x8007BA14: lh          $t9, 0x0($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X0);
    // 0x8007BA18: nop

    // 0x8007BA1C: beq         $t9, $zero, L_8007BA2C
    if (ctx->r25 == 0) {
        // 0x8007BA20: nop
    
            goto L_8007BA2C;
    }
    // 0x8007BA20: nop

    // 0x8007BA24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007BA28: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
L_8007BA2C:
    // 0x8007BA2C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007BA30: addiu       $t4, $t4, 0x6924
    ctx->r12 = ADD32(ctx->r12, 0X6924);
    // 0x8007BA34: lh          $t8, 0x0($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X0);
    // 0x8007BA38: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007BA3C: beq         $t8, $zero, L_8007BA50
    if (ctx->r24 == 0) {
        // 0x8007BA40: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8007BA50;
    }
    // 0x8007BA40: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007BA44: andi        $t6, $a2, 0x827
    ctx->r14 = ctx->r6 & 0X827;
    // 0x8007BA48: b           L_8007BA60
    // 0x8007BA4C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
        goto L_8007BA60;
    // 0x8007BA4C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
L_8007BA50:
    // 0x8007BA50: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8007BA54: ori         $at, $at, 0x93F
    ctx->r1 = ctx->r1 | 0X93F;
    // 0x8007BA58: and         $t7, $a2, $at
    ctx->r15 = ctx->r6 & ctx->r1;
    // 0x8007BA5C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8007BA60:
    // 0x8007BA60: lw          $t9, 0x6918($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6918);
    // 0x8007BA64: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007BA68: nor         $t8, $t9, $zero
    ctx->r24 = ~(ctx->r25 | 0);
    // 0x8007BA6C: and         $a2, $a2, $t8
    ctx->r6 = ctx->r6 & ctx->r24;
    // 0x8007BA70: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x8007BA74: bgez        $t6, L_8007BA8C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8007BA78: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8007BA8C;
    }
    // 0x8007BA78: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007BA7C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8007BA80: and         $t7, $a2, $at
    ctx->r15 = ctx->r6 & ctx->r1;
    // 0x8007BA84: b           L_8007BA98
    // 0x8007BA88: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
        goto L_8007BA98;
    // 0x8007BA88: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8007BA8C:
    // 0x8007BA8C: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x8007BA90: and         $t9, $a2, $at
    ctx->r25 = ctx->r6 & ctx->r1;
    // 0x8007BA94: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_8007BA98:
    // 0x8007BA98: addiu       $a3, $a3, 0x6914
    ctx->r7 = ADD32(ctx->r7, 0X6914);
    // 0x8007BA9C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007BAA0: nop

    // 0x8007BAA4: bne         $a2, $t5, L_8007BAB4
    if (ctx->r6 != ctx->r13) {
        // 0x8007BAA8: nop
    
            goto L_8007BAB4;
    }
    // 0x8007BAA8: nop

    // 0x8007BAAC: beq         $v1, $zero, L_8007BEA4
    if (ctx->r3 == 0) {
        // 0x8007BAB0: nop
    
            goto L_8007BEA4;
    }
    // 0x8007BAB0: nop

L_8007BAB4:
    // 0x8007BAB4: beq         $t0, $zero, L_8007BAE0
    if (ctx->r8 == 0) {
        // 0x8007BAB8: and         $t0, $a2, $a1
        ctx->r8 = ctx->r6 & ctx->r5;
            goto L_8007BAE0;
    }
    // 0x8007BAB8: and         $t0, $a2, $a1
    ctx->r8 = ctx->r6 & ctx->r5;
    // 0x8007BABC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BAC0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8007BAC4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BAC8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BACC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BAD0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007BAD4: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007BAD8: nop

    // 0x8007BADC: and         $t0, $a2, $a1
    ctx->r8 = ctx->r6 & ctx->r5;
L_8007BAE0:
    // 0x8007BAE0: and         $t7, $t5, $a1
    ctx->r15 = ctx->r13 & ctx->r5;
    // 0x8007BAE4: bne         $t7, $t0, L_8007BAFC
    if (ctx->r15 != ctx->r8) {
        // 0x8007BAE8: nop
    
            goto L_8007BAFC;
    }
    // 0x8007BAE8: nop

    // 0x8007BAEC: lh          $t9, 0x0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X0);
    // 0x8007BAF0: nop

    // 0x8007BAF4: beq         $t9, $zero, L_8007BB68
    if (ctx->r25 == 0) {
        // 0x8007BAF8: andi        $t9, $a2, 0x2
        ctx->r25 = ctx->r6 & 0X2;
            goto L_8007BB68;
    }
    // 0x8007BAF8: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
L_8007BAFC:
    // 0x8007BAFC: bne         $t0, $zero, L_8007BB14
    if (ctx->r8 != 0) {
        // 0x8007BB00: lui         $t7, 0xB600
        ctx->r15 = S32(0XB600 << 16);
            goto L_8007BB14;
    }
    // 0x8007BB00: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8007BB04: lh          $t8, 0x0($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X0);
    // 0x8007BB08: nop

    // 0x8007BB0C: beq         $t8, $zero, L_8007BB38
    if (ctx->r24 == 0) {
        // 0x8007BB10: nop
    
            goto L_8007BB38;
    }
    // 0x8007BB10: nop

L_8007BB14:
    // 0x8007BB14: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BB18: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8007BB1C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BB20: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BB24: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007BB28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007BB2C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007BB30: b           L_8007BB68
    // 0x8007BB34: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
        goto L_8007BB68;
    // 0x8007BB34: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
L_8007BB38:
    // 0x8007BB38: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BB3C: lui         $v1, 0xB700
    ctx->r3 = S32(0XB700 << 16);
    // 0x8007BB40: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8007BB44: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BB48: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BB4C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8007BB50: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8007BB54: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8007BB58: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8007BB5C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007BB60: nop

    // 0x8007BB64: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
L_8007BB68:
    // 0x8007BB68: andi        $t8, $t5, 0x2
    ctx->r24 = ctx->r13 & 0X2;
    // 0x8007BB6C: lui         $v1, 0xB700
    ctx->r3 = S32(0XB700 << 16);
    // 0x8007BB70: bne         $t8, $t9, L_8007BB88
    if (ctx->r24 != ctx->r25) {
        // 0x8007BB74: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_8007BB88;
    }
    // 0x8007BB74: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8007BB78: lh          $t6, 0x0($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X0);
    // 0x8007BB7C: nop

    // 0x8007BB80: beq         $t6, $zero, L_8007BBCC
    if (ctx->r14 == 0) {
        // 0x8007BB84: nop
    
            goto L_8007BBCC;
    }
    // 0x8007BB84: nop

L_8007BB88:
    // 0x8007BB88: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007BB8C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007BB90: beq         $t9, $zero, L_8007BBB4
    if (ctx->r25 == 0) {
        // 0x8007BB94: nop
    
            goto L_8007BBB4;
    }
    // 0x8007BB94: nop

    // 0x8007BB98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BB9C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007BBA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BBA4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BBA8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007BBAC: b           L_8007BBCC
    // 0x8007BBB0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
        goto L_8007BBCC;
    // 0x8007BBB0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_8007BBB4:
    // 0x8007BBB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BBB8: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8007BBBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BBC0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BBC4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007BBC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007BBCC:
    // 0x8007BBCC: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x8007BBD0: sh          $zero, 0x0($t3)
    MEM_H(0X0, ctx->r11) = 0;
    // 0x8007BBD4: bne         $t7, $zero, L_8007BC50
    if (ctx->r15 != 0) {
        // 0x8007BBD8: sw          $a2, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r6;
            goto L_8007BC50;
    }
    // 0x8007BBD8: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x8007BBDC: beq         $t0, $zero, L_8007BC1C
    if (ctx->r8 == 0) {
        // 0x8007BBE0: lui         $t6, 0x702
        ctx->r14 = S32(0X702 << 16);
            goto L_8007BC1C;
    }
    // 0x8007BBE0: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x8007BBE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BBE8: lui         $t9, 0x702
    ctx->r25 = S32(0X702 << 16);
    // 0x8007BBEC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BBF0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BBF4: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x8007BBF8: andi        $t8, $a2, 0x3
    ctx->r24 = ctx->r6 & 0X3;
    // 0x8007BBFC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007BC00: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007BC04: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x8007BC08: addu        $t6, $t7, $t1
    ctx->r14 = ADD32(ctx->r15, ctx->r9);
    // 0x8007BC0C: addiu       $t9, $t9, -0xB98
    ctx->r25 = ADD32(ctx->r25, -0XB98);
    // 0x8007BC10: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8007BC14: b           L_8007BEA4
    // 0x8007BC18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_8007BEA4;
    // 0x8007BC18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8007BC1C:
    // 0x8007BC1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BC20: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x8007BC24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BC28: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BC2C: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007BC30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007BC34: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007BC38: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x8007BC3C: addu        $t7, $t8, $t1
    ctx->r15 = ADD32(ctx->r24, ctx->r9);
    // 0x8007BC40: addiu       $t6, $t6, -0xB58
    ctx->r14 = ADD32(ctx->r14, -0XB58);
    // 0x8007BC44: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8007BC48: b           L_8007BEA4
    // 0x8007BC4C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_8007BEA4;
    // 0x8007BC4C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8007BC50:
    // 0x8007BC50: lh          $t8, 0x0($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X0);
    // 0x8007BC54: andi        $t7, $a2, 0x800
    ctx->r15 = ctx->r6 & 0X800;
    // 0x8007BC58: beq         $t8, $zero, L_8007BD18
    if (ctx->r24 == 0) {
        // 0x8007BC5C: andi        $t9, $a2, 0x800
        ctx->r25 = ctx->r6 & 0X800;
            goto L_8007BD18;
    }
    // 0x8007BC5C: andi        $t9, $a2, 0x800
    ctx->r25 = ctx->r6 & 0X800;
    // 0x8007BC60: beq         $t7, $zero, L_8007BCD8
    if (ctx->r15 == 0) {
        // 0x8007BC64: andi        $t6, $a2, 0x20
        ctx->r14 = ctx->r6 & 0X20;
            goto L_8007BCD8;
    }
    // 0x8007BC64: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
    // 0x8007BC68: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007BC6C: andi        $t9, $a2, 0x1
    ctx->r25 = ctx->r6 & 0X1;
    // 0x8007BC70: beq         $t6, $zero, L_8007BCD4
    if (ctx->r14 == 0) {
        // 0x8007BC74: andi        $t8, $a2, 0x4
        ctx->r24 = ctx->r6 & 0X4;
            goto L_8007BCD4;
    }
    // 0x8007BC74: andi        $t8, $a2, 0x4
    ctx->r24 = ctx->r6 & 0X4;
    // 0x8007BC78: beq         $t9, $zero, L_8007BC84
    if (ctx->r25 == 0) {
        // 0x8007BC7C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8007BC84;
    }
    // 0x8007BC7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007BC80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8007BC84:
    // 0x8007BC84: beq         $t8, $zero, L_8007BC94
    if (ctx->r24 == 0) {
        // 0x8007BC88: andi        $t6, $a2, 0x20
        ctx->r14 = ctx->r6 & 0X20;
            goto L_8007BC94;
    }
    // 0x8007BC88: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
    // 0x8007BC8C: ori         $t7, $a1, 0x2
    ctx->r15 = ctx->r5 | 0X2;
    // 0x8007BC90: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8007BC94:
    // 0x8007BC94: beq         $t6, $zero, L_8007BCA4
    if (ctx->r14 == 0) {
        // 0x8007BC98: lui         $t7, 0x702
        ctx->r15 = S32(0X702 << 16);
            goto L_8007BCA4;
    }
    // 0x8007BC98: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007BC9C: ori         $t9, $a1, 0x4
    ctx->r25 = ctx->r5 | 0X4;
    // 0x8007BCA0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_8007BCA4:
    // 0x8007BCA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BCA8: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007BCAC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BCB0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BCB4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007BCB8: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8007BCBC: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x8007BCC0: addiu       $t8, $t8, -0xA58
    ctx->r24 = ADD32(ctx->r24, -0XA58);
    // 0x8007BCC4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007BCC8: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8007BCCC: b           L_8007BEA4
    // 0x8007BCD0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8007BEA4;
    // 0x8007BCD0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007BCD4:
    // 0x8007BCD4: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
L_8007BCD8:
    // 0x8007BCD8: beq         $t6, $zero, L_8007BCE4
    if (ctx->r14 == 0) {
        // 0x8007BCDC: xori        $t9, $a2, 0x20
        ctx->r25 = ctx->r6 ^ 0X20;
            goto L_8007BCE4;
    }
    // 0x8007BCDC: xori        $t9, $a2, 0x20
    ctx->r25 = ctx->r6 ^ 0X20;
    // 0x8007BCE0: ori         $a2, $t9, 0x8
    ctx->r6 = ctx->r25 | 0X8;
L_8007BCE4:
    // 0x8007BCE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BCE8: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x8007BCEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BCF0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BCF4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007BCF8: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x8007BCFC: sll         $t9, $a2, 4
    ctx->r25 = S32(ctx->r6 << 4);
    // 0x8007BD00: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8007BD04: addiu       $t7, $t7, -0x9D8
    ctx->r15 = ADD32(ctx->r15, -0X9D8);
    // 0x8007BD08: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007BD0C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8007BD10: b           L_8007BEA4
    // 0x8007BD14: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_8007BEA4;
    // 0x8007BD14: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8007BD18:
    // 0x8007BD18: beq         $t9, $zero, L_8007BDA0
    if (ctx->r25 == 0) {
        // 0x8007BD1C: andi        $t6, $a2, 0x10
        ctx->r14 = ctx->r6 & 0X10;
            goto L_8007BDA0;
    }
    // 0x8007BD1C: andi        $t6, $a2, 0x10
    ctx->r14 = ctx->r6 & 0X10;
    // 0x8007BD20: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8007BD24: andi        $t7, $a2, 0x1
    ctx->r15 = ctx->r6 & 0X1;
    // 0x8007BD28: beq         $t8, $zero, L_8007BDA0
    if (ctx->r24 == 0) {
        // 0x8007BD2C: nop
    
            goto L_8007BDA0;
    }
    // 0x8007BD2C: nop

    // 0x8007BD30: beq         $t7, $zero, L_8007BD3C
    if (ctx->r15 == 0) {
        // 0x8007BD34: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8007BD3C;
    }
    // 0x8007BD34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007BD38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8007BD3C:
    // 0x8007BD3C: andi        $t6, $a2, 0x4
    ctx->r14 = ctx->r6 & 0X4;
    // 0x8007BD40: beq         $t6, $zero, L_8007BD50
    if (ctx->r14 == 0) {
        // 0x8007BD44: andi        $t8, $a2, 0x8
        ctx->r24 = ctx->r6 & 0X8;
            goto L_8007BD50;
    }
    // 0x8007BD44: andi        $t8, $a2, 0x8
    ctx->r24 = ctx->r6 & 0X8;
    // 0x8007BD48: ori         $t9, $a1, 0x2
    ctx->r25 = ctx->r5 | 0X2;
    // 0x8007BD4C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_8007BD50:
    // 0x8007BD50: beq         $t8, $zero, L_8007BD60
    if (ctx->r24 == 0) {
        // 0x8007BD54: andi        $t6, $a2, 0x20
        ctx->r14 = ctx->r6 & 0X20;
            goto L_8007BD60;
    }
    // 0x8007BD54: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
    // 0x8007BD58: ori         $t7, $a1, 0x4
    ctx->r15 = ctx->r5 | 0X4;
    // 0x8007BD5C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8007BD60:
    // 0x8007BD60: beq         $t6, $zero, L_8007BD70
    if (ctx->r14 == 0) {
        // 0x8007BD64: lui         $t7, 0x702
        ctx->r15 = S32(0X702 << 16);
            goto L_8007BD70;
    }
    // 0x8007BD64: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007BD68: ori         $t9, $a1, 0x8
    ctx->r25 = ctx->r5 | 0X8;
    // 0x8007BD6C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_8007BD70:
    // 0x8007BD70: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BD74: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007BD78: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BD7C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BD80: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007BD84: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8007BD88: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x8007BD8C: addiu       $t8, $t8, -0xC98
    ctx->r24 = ADD32(ctx->r24, -0XC98);
    // 0x8007BD90: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007BD94: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8007BD98: b           L_8007BEA4
    // 0x8007BD9C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8007BEA4;
    // 0x8007BD9C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007BDA0:
    // 0x8007BDA0: beq         $t6, $zero, L_8007BDF0
    if (ctx->r14 == 0) {
        // 0x8007BDA4: addiu       $at, $zero, -0x801
        ctx->r1 = ADD32(0, -0X801);
            goto L_8007BDF0;
    }
    // 0x8007BDA4: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8007BDA8: andi        $v0, $a2, 0x7
    ctx->r2 = ctx->r6 & 0X7;
    // 0x8007BDAC: andi        $t9, $a2, 0x8
    ctx->r25 = ctx->r6 & 0X8;
    // 0x8007BDB0: beq         $t9, $zero, L_8007BDBC
    if (ctx->r25 == 0) {
        // 0x8007BDB4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8007BDBC;
    }
    // 0x8007BDB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007BDB8: ori         $a1, $v0, 0x8
    ctx->r5 = ctx->r2 | 0X8;
L_8007BDBC:
    // 0x8007BDBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BDC0: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007BDC4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BDC8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BDCC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007BDD0: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007BDD4: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8007BDD8: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x8007BDDC: addiu       $t8, $t8, -0xD98
    ctx->r24 = ADD32(ctx->r24, -0XD98);
    // 0x8007BDE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007BDE4: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8007BDE8: b           L_8007BEA4
    // 0x8007BDEC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8007BEA4;
    // 0x8007BDEC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007BDF0:
    // 0x8007BDF0: and         $t6, $a2, $at
    ctx->r14 = ctx->r6 & ctx->r1;
    // 0x8007BDF4: and         $t9, $t6, $a1
    ctx->r25 = ctx->r14 & ctx->r5;
    // 0x8007BDF8: beq         $t9, $zero, L_8007BE74
    if (ctx->r25 == 0) {
        // 0x8007BDFC: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8007BE74;
    }
    // 0x8007BDFC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007BE00: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x8007BE04: andi        $t8, $t6, 0x100
    ctx->r24 = ctx->r14 & 0X100;
    // 0x8007BE08: beq         $t8, $zero, L_8007BE18
    if (ctx->r24 == 0) {
        // 0x8007BE0C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8007BE18;
    }
    // 0x8007BE0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007BE10: b           L_8007BE40
    // 0x8007BE14: ori         $a1, $v0, 0x4
    ctx->r5 = ctx->r2 | 0X4;
        goto L_8007BE40;
    // 0x8007BE14: ori         $a1, $v0, 0x4
    ctx->r5 = ctx->r2 | 0X4;
L_8007BE18:
    // 0x8007BE18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BE1C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007BE20: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BE24: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BE28: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007BE2C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8007BE30: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8007BE34: nop

    // 0x8007BE38: ori         $t8, $t9, 0x2
    ctx->r24 = ctx->r25 | 0X2;
    // 0x8007BE3C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_8007BE40:
    // 0x8007BE40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BE44: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x8007BE48: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BE4C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BE50: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007BE54: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x8007BE58: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8007BE5C: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8007BE60: addiu       $t7, $t7, -0x12B8
    ctx->r15 = ADD32(ctx->r15, -0X12B8);
    // 0x8007BE64: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007BE68: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8007BE6C: b           L_8007BEA4
    // 0x8007BE70: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_8007BEA4;
    // 0x8007BE70: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8007BE74:
    // 0x8007BE74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BE78: lui         $t8, 0x702
    ctx->r24 = S32(0X702 << 16);
    // 0x8007BE7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BE80: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BE84: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007BE88: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x8007BE8C: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x8007BE90: addu        $t6, $t7, $t1
    ctx->r14 = ADD32(ctx->r15, ctx->r9);
    // 0x8007BE94: addiu       $t9, $t9, -0x1198
    ctx->r25 = ADD32(ctx->r25, -0X1198);
    // 0x8007BE98: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BE9C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8007BEA0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8007BEA4:
    // 0x8007BEA4: jr          $ra
    // 0x8007BEA8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8007BEA8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void results_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096E7C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80096E80: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80096E84: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80096E88: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80096E8C: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80096E90: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80096E94: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80096E98: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80096E9C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80096EA0: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80096EA4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80096EA8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80096EAC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80096EB0: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80096EB4: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80096EB8: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80096EBC: jal         0x8006ECD0
    // 0x80096EC0: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80096EC0: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    after_0:
    // 0x80096EC4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80096EC8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80096ECC: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80096ED0: bne         $t6, $zero, L_80096EDC
    if (ctx->r14 != 0) {
        // 0x80096ED4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80096EDC;
    }
    // 0x80096ED4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80096ED8: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
L_80096EDC:
    // 0x80096EDC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80096EE0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80096EE4: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x80096EE8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80096EEC: jal         0x8006816C
    // 0x80096EF0: sw          $v1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r3;
    mtx_ortho(rdram, ctx);
        goto after_1;
    // 0x80096EF0: sw          $v1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r3;
    after_1:
    // 0x80096EF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80096EF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80096EFC: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80096F00: nop

    // 0x80096F04: bc1f        L_80096F10
    if (!c1cs) {
        // 0x80096F08: nop
    
            goto L_80096F10;
    }
    // 0x80096F08: nop

    // 0x80096F0C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80096F10:
    // 0x80096F10: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80096F14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80096F18: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80096F1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80096F20: bc1f        L_80096F2C
    if (!c1cs) {
        // 0x80096F24: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_80096F2C;
    }
    // 0x80096F24: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80096F28: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80096F2C:
    // 0x80096F2C: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80096F30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80096F34: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80096F38: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80096F3C: addiu       $s0, $s0, -0x31C
    ctx->r16 = ADD32(ctx->r16, -0X31C);
    // 0x80096F40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80096F44: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80096F48: nop

    // 0x80096F4C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80096F50: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80096F54: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80096F58: nop

    // 0x80096F5C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80096F60: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80096F64: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80096F68: jal         0x800C484C
    // 0x80096F6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x80096F6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    after_2:
    // 0x80096F70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096F74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80096F78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80096F7C: jal         0x800C492C
    // 0x80096F80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_3;
    // 0x80096F80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80096F84: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80096F88: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80096F8C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80096F90: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80096F94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80096F98: jal         0x800C48E4
    // 0x80096F9C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x80096F9C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
    // 0x80096FA0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80096FA4: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x80096FA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80096FAC: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80096FB0: lw          $a3, 0x84($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X84);
    // 0x80096FB4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80096FB8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80096FBC: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80096FC0: jal         0x800C49A0
    // 0x80096FC4: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80096FC4: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_5:
    // 0x80096FC8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80096FCC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80096FD0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80096FD4: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x80096FD8: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80096FDC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80096FE0: bne         $v0, $at, L_80096FF0
    if (ctx->r2 != ctx->r1) {
        // 0x80096FE4: sw          $t3, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r11;
            goto L_80096FF0;
    }
    // 0x80096FE4: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x80096FE8: addiu       $t4, $zero, 0x38
    ctx->r12 = ADD32(0, 0X38);
    // 0x80096FEC: sw          $t4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r12;
L_80096FF0:
    // 0x80096FF0: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x80096FF4: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80096FF8: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80096FFC: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097000: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x80097004: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80097008: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009700C: mflo        $t8
    ctx->r24 = lo;
    // 0x80097010: subu        $s5, $t9, $t8
    ctx->r21 = SUB32(ctx->r25, ctx->r24);
    // 0x80097014: blez        $v0, L_80097100
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097018: sw          $s5, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r21;
            goto L_80097100;
    }
    // 0x80097018: sw          $s5, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r21;
    // 0x8009701C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80097020: addiu       $t3, $zero, 0x36
    ctx->r11 = ADD32(0, 0X36);
    // 0x80097024: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80097028: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8009702C: lw          $s0, 0x84($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X84);
    // 0x80097030: addiu       $s2, $s2, 0x1070
    ctx->r18 = ADD32(ctx->r18, 0X1070);
    // 0x80097034: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80097038: addiu       $s3, $zero, 0x17F
    ctx->r19 = ADD32(0, 0X17F);
    // 0x8009703C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80097040: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80097044: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80097048: nop

    // 0x8009704C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80097050: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80097054: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80097058: subu        $s1, $t3, $t2
    ctx->r17 = SUB32(ctx->r11, ctx->r10);
    // 0x8009705C: nop

L_80097060:
    // 0x80097060: lb          $t4, 0x5A($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X5A);
    // 0x80097064: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80097068: bne         $t4, $zero, L_800970A4
    if (ctx->r12 != 0) {
        // 0x8009706C: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_800970A4;
    }
    // 0x8009706C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80097070: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80097074: lw          $v0, 0x695C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X695C);
    // 0x80097078: nop

    // 0x8009707C: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80097080: beq         $at, $zero, L_80097098
    if (ctx->r1 == 0) {
        // 0x80097084: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80097098;
    }
    // 0x80097084: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80097088: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8009708C: addiu       $t5, $t6, 0x80
    ctx->r13 = ADD32(ctx->r14, 0X80);
    // 0x80097090: b           L_800970AC
    // 0x80097094: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
        goto L_800970AC;
    // 0x80097094: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
L_80097098:
    // 0x80097098: subu        $t9, $s3, $t7
    ctx->r25 = SUB32(ctx->r19, ctx->r15);
    // 0x8009709C: b           L_800970AC
    // 0x800970A0: sw          $t9, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r25;
        goto L_800970AC;
    // 0x800970A0: sw          $t9, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r25;
L_800970A4:
    // 0x800970A4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800970A8: sw          $t8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r24;
L_800970AC:
    // 0x800970AC: lb          $t0, 0x59($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X59);
    // 0x800970B0: lbu         $v0, 0xAB($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XAB);
    // 0x800970B4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800970B8: addu        $t3, $s2, $t1
    ctx->r11 = ADD32(ctx->r18, ctx->r9);
    // 0x800970BC: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x800970C0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800970C4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800970C8: addiu       $a2, $s5, -0x14
    ctx->r6 = ADD32(ctx->r21, -0X14);
    // 0x800970CC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800970D0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800970D4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800970D8: jal         0x80078F08
    // 0x800970DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    texrect_draw(rdram, ctx);
        goto after_6;
    // 0x800970DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x800970E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800970E4: lw          $t6, -0x5C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C4);
    // 0x800970E8: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x800970EC: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800970F0: slt         $at, $s6, $t6
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800970F4: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800970F8: bne         $at, $zero, L_80097060
    if (ctx->r1 != 0) {
        // 0x800970FC: addu        $s5, $s5, $t4
        ctx->r21 = ADD32(ctx->r21, ctx->r12);
            goto L_80097060;
    }
    // 0x800970FC: addu        $s5, $s5, $t4
    ctx->r21 = ADD32(ctx->r21, ctx->r12);
L_80097100:
    // 0x80097100: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80097104: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80097108: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x8009710C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80097110: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80097114: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80097118: nop

    // 0x8009711C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80097120: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80097124: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80097128: nop

    // 0x8009712C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80097130: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80097134: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80097138: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8009713C: jal         0x800C484C
    // 0x80097140: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x80097140: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    after_7:
    // 0x80097144: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x80097148: lw          $v0, 0xAC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XAC);
    // 0x8009714C: addiu       $v1, $v1, 0x68
    ctx->r3 = ADD32(ctx->r3, 0X68);
    // 0x80097150: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80097154: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80097158: addiu       $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
    // 0x8009715C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80097160: addiu       $t2, $t2, 0x114C
    ctx->r10 = ADD32(ctx->r10, 0X114C);
    // 0x80097164: addiu       $t3, $v1, 0x4
    ctx->r11 = ADD32(ctx->r3, 0X4);
    // 0x80097168: addiu       $t4, $v1, 0x2
    ctx->r12 = ADD32(ctx->r3, 0X2);
    // 0x8009716C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80097170: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80097174: addiu       $t5, $v0, -0x22
    ctx->r13 = ADD32(ctx->r2, -0X22);
    // 0x80097178: addiu       $t7, $v0, -0x20
    ctx->r15 = ADD32(ctx->r2, -0X20);
    // 0x8009717C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80097180: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x80097184: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x80097188: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x8009718C: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80097190: addiu       $s3, $s3, -0x324
    ctx->r19 = ADD32(ctx->r19, -0X324);
    // 0x80097194: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x80097198: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x8009719C: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x800971A0: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x800971A4: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x800971A8: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x800971AC: addiu       $s7, $zero, 0x64
    ctx->r23 = ADD32(0, 0X64);
L_800971B0:
    // 0x800971B0: lw          $s5, 0xAC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XAC);
    // 0x800971B4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800971B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800971BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800971C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800971C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800971C8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800971CC: jal         0x800C48E4
    // 0x800971D0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x800971D0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    after_8:
    // 0x800971D4: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800971D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800971DC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800971E0: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x800971E4: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x800971E8: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x800971EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800971F0: jal         0x800C49A0
    // 0x800971F4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    draw_text(rdram, ctx);
        goto after_9;
    // 0x800971F4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_9:
    // 0x800971F8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800971FC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80097200: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80097204: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80097208: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x8009720C: jal         0x800C48E4
    // 0x80097210: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    set_text_colour(rdram, ctx);
        goto after_10;
    // 0x80097210: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_10:
    // 0x80097214: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80097218: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009721C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80097220: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80097224: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80097228: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x8009722C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80097230: jal         0x800C49A0
    // 0x80097234: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    draw_text(rdram, ctx);
        goto after_11;
    // 0x80097234: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_11:
    // 0x80097238: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009723C: jal         0x8007B820
    // 0x80097240: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    rendermode_reset(rdram, ctx);
        goto after_12;
    // 0x80097240: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_12:
    // 0x80097244: jal         0x80068748
    // 0x80097248: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_13;
    // 0x80097248: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x8009724C: jal         0x8007C36C
    // 0x80097250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_14;
    // 0x80097250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x80097254: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80097258: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009725C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80097260: sb          $v0, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r2;
    // 0x80097264: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097268: sb          $t4, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r12;
    // 0x8009726C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097270: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80097274: lw          $t6, -0x5C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C4);
    // 0x80097278: sb          $v0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r2;
    // 0x8009727C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097280: blez        $t6, L_80097440
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80097284: sb          $v0, -0x5D0($at)
        MEM_B(-0X5D0, ctx->r1) = ctx->r2;
            goto L_80097440;
    }
    // 0x80097284: sb          $v0, -0x5D0($at)
    MEM_B(-0X5D0, ctx->r1) = ctx->r2;
    // 0x80097288: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x8009728C: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x80097290: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80097294: subu        $t1, $t0, $t8
    ctx->r9 = SUB32(ctx->r8, ctx->r24);
    // 0x80097298: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8009729C: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x800972A0: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800972A4: cvt.s.w     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    ctx->f22.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800972A8: addu        $s4, $t5, $t9
    ctx->r20 = ADD32(ctx->r13, ctx->r25);
L_800972AC:
    // 0x800972AC: lhu         $s1, 0x5C($s4)
    ctx->r17 = MEM_HU(ctx->r20, 0X5C);
    // 0x800972B0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800972B4: slti        $at, $s1, 0x3E8
    ctx->r1 = SIGNED(ctx->r17) < 0X3E8 ? 1 : 0;
    // 0x800972B8: bne         $at, $zero, L_800972C4
    if (ctx->r1 != 0) {
        // 0x800972BC: addiu       $t6, $s5, -0xAC
        ctx->r14 = ADD32(ctx->r21, -0XAC);
            goto L_800972C4;
    }
    // 0x800972BC: addiu       $t6, $s5, -0xAC
    ctx->r14 = ADD32(ctx->r21, -0XAC);
    // 0x800972C0: addiu       $s1, $zero, 0x3E7
    ctx->r17 = ADD32(0, 0X3E7);
L_800972C4:
    // 0x800972C4: div         $zero, $s1, $s7
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r23)));
    // 0x800972C8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800972CC: bne         $s7, $zero, L_800972D8
    if (ctx->r23 != 0) {
        // 0x800972D0: nop
    
            goto L_800972D8;
    }
    // 0x800972D0: nop

    // 0x800972D4: break       7
    do_break(2148102868);
L_800972D8:
    // 0x800972D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800972DC: bne         $s7, $at, L_800972F0
    if (ctx->r23 != ctx->r1) {
        // 0x800972E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800972F0;
    }
    // 0x800972E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800972E4: bne         $s1, $at, L_800972F0
    if (ctx->r17 != ctx->r1) {
        // 0x800972E8: nop
    
            goto L_800972F0;
    }
    // 0x800972E8: nop

    // 0x800972EC: break       6
    do_break(2148102892);
L_800972F0:
    // 0x800972F0: swc1        $f22, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f22.u32l;
    // 0x800972F4: mflo        $v0
    ctx->r2 = lo;
    // 0x800972F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800972FC: nop

    // 0x80097300: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097304: mflo        $t3
    ctx->r11 = lo;
    // 0x80097308: subu        $s1, $s1, $t3
    ctx->r17 = SUB32(ctx->r17, ctx->r11);
    // 0x8009730C: nop

    // 0x80097310: div         $zero, $s1, $fp
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r30)));
    // 0x80097314: bne         $fp, $zero, L_80097320
    if (ctx->r30 != 0) {
        // 0x80097318: nop
    
            goto L_80097320;
    }
    // 0x80097318: nop

    // 0x8009731C: break       7
    do_break(2148102940);
L_80097320:
    // 0x80097320: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80097324: bne         $fp, $at, L_80097338
    if (ctx->r30 != ctx->r1) {
        // 0x80097328: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80097338;
    }
    // 0x80097328: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009732C: bne         $s1, $at, L_80097338
    if (ctx->r17 != ctx->r1) {
        // 0x80097330: nop
    
            goto L_80097338;
    }
    // 0x80097330: nop

    // 0x80097334: break       6
    do_break(2148102964);
L_80097338:
    // 0x80097338: mflo        $v1
    ctx->r3 = lo;
    // 0x8009733C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x80097340: nop

    // 0x80097344: multu       $v1, $fp
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80097348: mflo        $t2
    ctx->r10 = lo;
    // 0x8009734C: subu        $s1, $s1, $t2
    ctx->r17 = SUB32(ctx->r17, ctx->r10);
    // 0x80097350: blez        $a1, L_800973B8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80097354: nop
    
            goto L_800973B8;
    }
    // 0x80097354: nop

    // 0x80097358: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8009735C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80097360: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80097364: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80097368: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x8009736C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80097370: jal         0x8009CFA4
    // 0x80097374: sh          $a1, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r5;
    menu_element_render(rdram, ctx);
        goto after_15;
    // 0x80097374: sh          $a1, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r5;
    after_15:
    // 0x80097378: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8009737C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80097380: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80097384: nop

    // 0x80097388: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8009738C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80097390: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80097394: jal         0x8009CFA4
    // 0x80097398: sh          $s2, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r18;
    menu_element_render(rdram, ctx);
        goto after_16;
    // 0x80097398: sh          $s2, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r18;
    after_16:
    // 0x8009739C: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800973A0: nop

    // 0x800973A4: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800973A8: nop

    // 0x800973AC: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x800973B0: b           L_80097410
    // 0x800973B4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_80097410;
    // 0x800973B4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_800973B8:
    // 0x800973B8: blez        $s2, L_80097400
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800973BC: addiu       $t3, $s5, -0xA0
        ctx->r11 = ADD32(ctx->r21, -0XA0);
            goto L_80097400;
    }
    // 0x800973BC: addiu       $t3, $s5, -0xA0
    ctx->r11 = ADD32(ctx->r21, -0XA0);
    // 0x800973C0: addiu       $t0, $s5, -0xA6
    ctx->r8 = ADD32(ctx->r21, -0XA6);
    // 0x800973C4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800973C8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800973CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800973D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800973D4: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x800973D8: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800973DC: jal         0x8009CFA4
    // 0x800973E0: sh          $s2, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r18;
    menu_element_render(rdram, ctx);
        goto after_17;
    // 0x800973E0: sh          $s2, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r18;
    after_17:
    // 0x800973E4: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800973E8: nop

    // 0x800973EC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800973F0: nop

    // 0x800973F4: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800973F8: b           L_80097410
    // 0x800973FC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_80097410;
    // 0x800973FC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_80097400:
    // 0x80097400: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80097404: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80097408: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009740C: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
L_80097410:
    // 0x80097410: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80097414: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80097418: jal         0x8009CFA4
    // 0x8009741C: sh          $s1, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r17;
    menu_element_render(rdram, ctx);
        goto after_18;
    // 0x8009741C: sh          $s1, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r17;
    after_18:
    // 0x80097420: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80097424: lw          $t7, -0x5C4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5C4);
    // 0x80097428: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8009742C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80097430: slt         $at, $s6, $t7
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80097434: addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    // 0x80097438: bne         $at, $zero, L_800972AC
    if (ctx->r1 != 0) {
        // 0x8009743C: addu        $s5, $s5, $t6
        ctx->r21 = ADD32(ctx->r21, ctx->r14);
            goto L_800972AC;
    }
    // 0x8009743C: addu        $s5, $s5, $t6
    ctx->r21 = ADD32(ctx->r21, ctx->r14);
L_80097440:
    // 0x80097440: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80097444: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80097448: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8009744C: addiu       $t9, $t5, 0x11
    ctx->r25 = ADD32(ctx->r13, 0X11);
    // 0x80097450: addiu       $t8, $t0, 0x11
    ctx->r24 = ADD32(ctx->r8, 0X11);
    // 0x80097454: addiu       $t3, $t1, 0x11
    ctx->r11 = ADD32(ctx->r9, 0X11);
    // 0x80097458: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x8009745C: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x80097460: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x80097464: jal         0x80068748
    // 0x80097468: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_19;
    // 0x80097468: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x8009746C: jal         0x8007C36C
    // 0x80097470: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_20;
    // 0x80097470: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x80097474: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80097478: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009747C: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x80097480: sb          $t2, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r10;
    // 0x80097484: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80097488: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8009748C: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x80097490: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80097494: sb          $zero, -0x5D0($at)
    MEM_B(-0X5D0, ctx->r1) = 0;
    // 0x80097498: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8009749C: addiu       $t5, $t7, 0x4
    ctx->r13 = ADD32(ctx->r15, 0X4);
    // 0x800974A0: addiu       $t0, $t9, -0x40
    ctx->r8 = ADD32(ctx->r25, -0X40);
    // 0x800974A4: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800974A8: sw          $t0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r8;
    // 0x800974AC: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x800974B0: bne         $at, $zero, L_800971B0
    if (ctx->r1 != 0) {
        // 0x800974B4: sw          $t6, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r14;
            goto L_800971B0;
    }
    // 0x800974B4: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x800974B8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800974BC: lw          $t1, 0x6980($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6980);
    // 0x800974C0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800974C4: blez        $t1, L_800977A4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800974C8: addiu       $s1, $s1, 0x71D4
        ctx->r17 = ADD32(ctx->r17, 0X71D4);
            goto L_800977A4;
    }
    // 0x800974C8: addiu       $s1, $s1, 0x71D4
    ctx->r17 = ADD32(ctx->r17, 0X71D4);
    // 0x800974CC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800974D0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800974D4: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x800974D8: jal         0x800C5C30
    // 0x800974DC: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_21;
    // 0x800974DC: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    after_21:
    // 0x800974E0: jal         0x800C59F4
    // 0x800974E4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_22;
    // 0x800974E4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_22:
    // 0x800974E8: lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA0);
    // 0x800974EC: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x800974F0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800974F4: addu        $t7, $t4, $v0
    ctx->r15 = ADD32(ctx->r12, ctx->r2);
    // 0x800974F8: addiu       $t5, $t7, 0xCC
    ctx->r13 = ADD32(ctx->r15, 0XCC);
    // 0x800974FC: subu        $a2, $v0, $t4
    ctx->r6 = SUB32(ctx->r2, ctx->r12);
    // 0x80097500: addiu       $a2, $a2, 0xC4
    ctx->r6 = ADD32(ctx->r6, 0XC4);
    // 0x80097504: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80097508: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x8009750C: jal         0x800C543C
    // 0x80097510: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_23;
    // 0x80097510: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    after_23:
    // 0x80097514: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80097518: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x8009751C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80097520: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80097524: jal         0x800C551C
    // 0x80097528: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_24;
    // 0x80097528: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_24:
    // 0x8009752C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80097530: jal         0x800C54DC
    // 0x80097534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_25;
    // 0x80097534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80097538: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009753C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80097540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097544: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80097548: jal         0x800C55B0
    // 0x8009754C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_26;
    // 0x8009754C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_26:
    // 0x80097550: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80097554: lw          $v0, 0x695C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X695C);
    // 0x80097558: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009755C: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x80097560: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80097564: bne         $at, $zero, L_80097574
    if (ctx->r1 != 0) {
        // 0x80097568: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80097574;
    }
    // 0x80097568: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8009756C: addiu       $t0, $zero, 0x1FF
    ctx->r8 = ADD32(0, 0X1FF);
    // 0x80097570: subu        $v0, $t0, $t9
    ctx->r2 = SUB32(ctx->r8, ctx->r25);
L_80097574:
    // 0x80097574: addiu       $s0, $s0, 0xF08
    ctx->r16 = ADD32(ctx->r16, 0XF08);
    // 0x80097578: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8009757C: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x80097580: beq         $t6, $zero, L_800976D8
    if (ctx->r14 == 0) {
        // 0x80097584: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_800976D8;
    }
    // 0x80097584: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80097588: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009758C: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x80097590: addiu       $t1, $t8, -0x18
    ctx->r9 = ADD32(ctx->r24, -0X18);
    // 0x80097594: sw          $t1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r9;
    // 0x80097598: lw          $a3, 0x210($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X210);
    // 0x8009759C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800975A0: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x800975A4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800975A8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800975AC: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x800975B0: addiu       $a2, $t1, 0x8
    ctx->r6 = ADD32(ctx->r9, 0X8);
    // 0x800975B4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800975B8: jal         0x800C56C8
    // 0x800975BC: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    render_dialogue_text(rdram, ctx);
        goto after_27;
    // 0x800975BC: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    after_27:
    // 0x800975C0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800975C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800975C8: bne         $t7, $at, L_800975FC
    if (ctx->r15 != ctx->r1) {
        // 0x800975CC: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800975FC;
    }
    // 0x800975CC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800975D0: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x800975D4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800975D8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800975DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800975E0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800975E4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800975E8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800975EC: jal         0x800C5560
    // 0x800975F0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    set_current_text_colour(rdram, ctx);
        goto after_28;
    // 0x800975F0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_28:
    // 0x800975F4: b           L_80097618
    // 0x800975F8: nop

        goto L_80097618;
    // 0x800975F8: nop

L_800975FC:
    // 0x800975FC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80097600: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80097604: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80097608: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009760C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80097610: jal         0x800C5560
    // 0x80097614: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_29;
    // 0x80097614: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_29:
L_80097618:
    // 0x80097618: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009761C: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x80097620: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x80097624: lw          $a3, 0x218($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X218);
    // 0x80097628: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009762C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80097630: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80097634: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80097638: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009763C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80097640: jal         0x800C56C8
    // 0x80097644: addiu       $a2, $a2, 0x1A
    ctx->r6 = ADD32(ctx->r6, 0X1A);
    render_dialogue_text(rdram, ctx);
        goto after_30;
    // 0x80097644: addiu       $a2, $a2, 0x1A
    ctx->r6 = ADD32(ctx->r6, 0X1A);
    after_30:
    // 0x80097648: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8009764C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80097650: bne         $t3, $at, L_80097684
    if (ctx->r11 != ctx->r1) {
        // 0x80097654: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80097684;
    }
    // 0x80097654: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80097658: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x8009765C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80097660: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80097664: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80097668: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009766C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80097670: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80097674: jal         0x800C5560
    // 0x80097678: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_current_text_colour(rdram, ctx);
        goto after_31;
    // 0x80097678: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_31:
    // 0x8009767C: b           L_800976A0
    // 0x80097680: nop

        goto L_800976A0;
    // 0x80097680: nop

L_80097684:
    // 0x80097684: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80097688: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009768C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80097690: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80097694: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80097698: jal         0x800C5560
    // 0x8009769C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_32;
    // 0x8009769C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_32:
L_800976A0:
    // 0x800976A0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800976A4: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x800976A8: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x800976AC: lw          $a3, 0x154($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X154);
    // 0x800976B0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800976B4: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x800976B8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800976BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800976C0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800976C4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x800976C8: jal         0x800C56C8
    // 0x800976CC: addiu       $a2, $a2, 0x2A
    ctx->r6 = ADD32(ctx->r6, 0X2A);
    render_dialogue_text(rdram, ctx);
        goto after_33;
    // 0x800976CC: addiu       $a2, $a2, 0x2A
    ctx->r6 = ADD32(ctx->r6, 0X2A);
    after_33:
    // 0x800976D0: b           L_8009779C
    // 0x800976D4: nop

        goto L_8009779C;
    // 0x800976D4: nop

L_800976D8:
    // 0x800976D8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800976DC: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x800976E0: blez        $t8, L_8009779C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800976E4: sw          $t6, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = ctx->r14;
            goto L_8009779C;
    }
    // 0x800976E4: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x800976E8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800976EC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800976F0: addiu       $s2, $s2, 0x7028
    ctx->r18 = ADD32(ctx->r18, 0X7028);
    // 0x800976F4: addiu       $s0, $s0, 0x71B0
    ctx->r16 = ADD32(ctx->r16, 0X71B0);
    // 0x800976F8: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
L_800976FC:
    // 0x800976FC: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80097700: lw          $v0, 0xA8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA8);
    // 0x80097704: bne         $s6, $t1, L_80097738
    if (ctx->r22 != ctx->r9) {
        // 0x80097708: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80097738;
    }
    // 0x80097708: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009770C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80097710: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80097714: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80097718: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009771C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80097720: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80097724: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80097728: jal         0x800C5560
    // 0x8009772C: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    set_current_text_colour(rdram, ctx);
        goto after_34;
    // 0x8009772C: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    after_34:
    // 0x80097730: b           L_8009775C
    // 0x80097734: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
        goto L_8009775C;
    // 0x80097734: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
L_80097738:
    // 0x80097738: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009773C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80097740: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80097744: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80097748: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009774C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80097750: jal         0x800C5560
    // 0x80097754: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    set_current_text_colour(rdram, ctx);
        goto after_35;
    // 0x80097754: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    after_35:
    // 0x80097758: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
L_8009775C:
    // 0x8009775C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80097760: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80097764: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80097768: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009776C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80097770: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80097774: jal         0x800C56C8
    // 0x80097778: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    render_dialogue_text(rdram, ctx);
        goto after_36;
    // 0x80097778: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_36:
    // 0x8009777C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80097780: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x80097784: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80097788: slt         $at, $s6, $t0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8009778C: addiu       $t9, $t5, 0x10
    ctx->r25 = ADD32(ctx->r13, 0X10);
    // 0x80097790: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80097794: bne         $at, $zero, L_800976FC
    if (ctx->r1 != 0) {
        // 0x80097798: sw          $t9, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = ctx->r25;
            goto L_800976FC;
    }
    // 0x80097798: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
L_8009779C:
    // 0x8009779C: jal         0x800C5B54
    // 0x800977A0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    open_dialogue_box(rdram, ctx);
        goto after_37;
    // 0x800977A0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_37:
L_800977A4:
    // 0x800977A4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800977A8: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800977AC: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800977B0: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800977B4: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800977B8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800977BC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800977C0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800977C4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800977C8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800977CC: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800977D0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800977D4: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800977D8: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800977DC: jr          $ra
    // 0x800977E0: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800977E0: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
