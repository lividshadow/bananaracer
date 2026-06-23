#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void obj_loop_wavepower(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C04FC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C0500: lw          $t6, 0x3728($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3728);
    // 0x800C0504: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800C0508: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C050C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C0510: beq         $a0, $t6, L_800C0680
    if (ctx->r4 == ctx->r14) {
        // 0x800C0514: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800C0680;
    }
    // 0x800C0514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C0518: jal         0x8001BAA8
    // 0x800C051C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800C051C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x800C0520: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800C0524: nop

    // 0x800C0528: blez        $a1, L_800C0684
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C052C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C0684;
    }
    // 0x800C052C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0530: blez        $a1, L_800C057C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C0534: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800C057C;
    }
    // 0x800C0534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C0538: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C053C: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800C0540: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x800C0544: addu        $a3, $t7, $v0
    ctx->r7 = ADD32(ctx->r15, ctx->r2);
L_800C0548:
    // 0x800C0548: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800C054C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C0550: lw          $a0, 0x64($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X64);
    // 0x800C0554: sltu        $at, $v1, $a3
    ctx->r1 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x800C0558: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x800C055C: nop

    // 0x800C0560: bne         $t9, $zero, L_800C056C
    if (ctx->r25 != 0) {
        // 0x800C0564: nop
    
            goto L_800C056C;
    }
    // 0x800C0564: nop

    // 0x800C0568: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_800C056C:
    // 0x800C056C: beq         $at, $zero, L_800C057C
    if (ctx->r1 == 0) {
        // 0x800C0570: nop
    
            goto L_800C057C;
    }
    // 0x800C0570: nop

    // 0x800C0574: beq         $a2, $zero, L_800C0548
    if (ctx->r6 == 0) {
        // 0x800C0578: nop
    
            goto L_800C0548;
    }
    // 0x800C0578: nop

L_800C057C:
    // 0x800C057C: beq         $a2, $zero, L_800C0684
    if (ctx->r6 == 0) {
        // 0x800C0580: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C0684;
    }
    // 0x800C0580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0584: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x800C0588: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C058C: lhu         $t0, 0x8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X8);
    // 0x800C0590: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C0594: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800C0598: bgez        $t0, L_800C05AC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800C059C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C05AC;
    }
    // 0x800C059C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C05A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C05A4: nop

    // 0x800C05A8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_800C05AC:
    // 0x800C05AC: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800C05B0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800C05B4: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C05B8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800C05BC: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800C05C0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800C05C4: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C05C8: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800C05CC: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800C05D0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800C05D4: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800C05D8: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C05DC: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C05E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C05E4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800C05E8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800C05EC: nop

    // 0x800C05F0: bc1f        L_800C0684
    if (!c1cs) {
        // 0x800C05F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C0684;
    }
    // 0x800C05F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C05F8: lhu         $t1, 0xA($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XA);
    // 0x800C05FC: addiu       $v1, $v1, -0x5320
    ctx->r3 = ADD32(ctx->r3, -0X5320);
    // 0x800C0600: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800C0604: bgez        $t1, L_800C061C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800C0608: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800C061C;
    }
    // 0x800C0608: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C060C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0610: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C0614: nop

    // 0x800C0618: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800C061C:
    // 0x800C061C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800C0620: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C0624: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0628: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C062C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x800C0630: lhu         $t2, 0xC($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XC);
    // 0x800C0634: lwc1        $f6, -0x5A38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5A38);
    // 0x800C0638: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C063C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800C0640: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C0644: bgez        $t2, L_800C065C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800C0648: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C065C;
    }
    // 0x800C0648: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C064C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0650: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C0654: nop

    // 0x800C0658: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800C065C:
    // 0x800C065C: nop

    // 0x800C0660: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C0664: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0668: swc1        $f4, -0x531C($at)
    MEM_W(-0X531C, ctx->r1) = ctx->f4.u32l;
    // 0x800C066C: lhu         $t3, 0xC($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XC);
    // 0x800C0670: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0674: sw          $t3, -0x5318($at)
    MEM_W(-0X5318, ctx->r1) = ctx->r11;
    // 0x800C0678: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C067C: sw          $s0, 0x3728($at)
    MEM_W(0X3728, ctx->r1) = ctx->r16;
L_800C0680:
    // 0x800C0680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C0684:
    // 0x800C0684: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C0688: jr          $ra
    // 0x800C068C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800C068C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void obj_loop_scenery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033E10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80033E14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80033E18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80033E1C: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x80033E20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80033E24: beq         $v0, $zero, L_80033F78
    if (ctx->r2 == 0) {
        // 0x80033E28: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80033F78;
    }
    // 0x80033E28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80033E2C: lh          $t6, 0x7C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X7C);
    // 0x80033E30: addiu       $v1, $a0, 0x78
    ctx->r3 = ADD32(ctx->r4, 0X78);
    // 0x80033E34: blez        $t6, L_80033E54
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80033E38: nop
    
            goto L_80033E54;
    }
    // 0x80033E38: nop

    // 0x80033E3C: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80033E40: nop

    // 0x80033E44: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x80033E48: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80033E4C: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x80033E50: nop

L_80033E54:
    // 0x80033E54: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x80033E58: addiu       $v1, $s0, 0x78
    ctx->r3 = ADD32(ctx->r16, 0X78);
    // 0x80033E5C: andi        $t0, $t9, 0x40
    ctx->r8 = ctx->r25 & 0X40;
    // 0x80033E60: beq         $t0, $zero, L_80033F2C
    if (ctx->r8 == 0) {
        // 0x80033E64: nop
    
            goto L_80033F2C;
    }
    // 0x80033E64: nop

    // 0x80033E68: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x80033E6C: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    // 0x80033E70: bgtz        $t1, L_80033F2C
    if (SIGNED(ctx->r9) > 0) {
        // 0x80033E74: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_80033F2C;
    }
    // 0x80033E74: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80033E78: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80033E7C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80033E80: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80033E84: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80033E88: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80033E8C: jal         0x80009558
    // 0x80033E90: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_0;
    // 0x80033E90: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_0:
    // 0x80033E94: lw          $t3, 0x4C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4C);
    // 0x80033E98: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033E9C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80033EA0: addiu       $t5, $zero, 0x71C
    ctx->r13 = ADD32(0, 0X71C);
    // 0x80033EA4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80033EA8: sh          $t5, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r13;
    // 0x80033EAC: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x80033EB0: jal         0x8009C90C
    // 0x80033EB4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    get_number_of_active_players(rdram, ctx);
        goto after_1;
    // 0x80033EB4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    after_1:
    // 0x80033EB8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033EBC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80033EC0: beq         $at, $zero, L_80033F40
    if (ctx->r1 == 0) {
        // 0x80033EC4: nop
    
            goto L_80033F40;
    }
    // 0x80033EC4: nop

    // 0x80033EC8: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x80033ECC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80033ED0: lb          $v0, 0x57($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X57);
    // 0x80033ED4: nop

    // 0x80033ED8: blez        $v0, L_80033F40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80033EDC: nop
    
            goto L_80033F40;
    }
    // 0x80033EDC: nop

    // 0x80033EE0: bne         $v0, $at, L_80033EF0
    if (ctx->r2 != ctx->r1) {
        // 0x80033EE4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80033EF0;
    }
    // 0x80033EE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80033EE8: b           L_80033F04
    // 0x80033EEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80033F04;
    // 0x80033EEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80033EF0:
    // 0x80033EF0: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80033EF4: jal         0x8006FB8C
    // 0x80033EF8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x80033EF8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_2:
    // 0x80033EFC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033F00: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80033F04:
    // 0x80033F04: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80033F08: sllv        $t9, $t8, $a2
    ctx->r25 = S32(ctx->r24 << (ctx->r6 & 31));
    // 0x80033F0C: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
    // 0x80033F10: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80033F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033F18: jal         0x800B019C
    // 0x80033F1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    obj_spawn_particle(rdram, ctx);
        goto after_3;
    // 0x80033F1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80033F20: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033F24: b           L_80033F44
    // 0x80033F28: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
        goto L_80033F44;
    // 0x80033F28: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
L_80033F2C:
    // 0x80033F2C: lh          $t0, 0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X4);
    // 0x80033F30: nop

    // 0x80033F34: bgtz        $t0, L_80033F40
    if (SIGNED(ctx->r8) > 0) {
        // 0x80033F38: nop
    
            goto L_80033F40;
    }
    // 0x80033F38: nop

    // 0x80033F3C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80033F40:
    // 0x80033F40: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
L_80033F44:
    // 0x80033F44: nop

    // 0x80033F48: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    // 0x80033F4C: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
    // 0x80033F50: nop

    // 0x80033F54: negu        $at, $t2
    ctx->r1 = SUB32(0, ctx->r10);
    // 0x80033F58: sll         $t3, $at, 2
    ctx->r11 = S32(ctx->r1 << 2);
    // 0x80033F5C: subu        $t3, $t3, $at
    ctx->r11 = SUB32(ctx->r11, ctx->r1);
    // 0x80033F60: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80033F64: addu        $t3, $t3, $at
    ctx->r11 = ADD32(ctx->r11, ctx->r1);
    // 0x80033F68: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80033F6C: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x80033F70: sh          $t4, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r12;
    // 0x80033F74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033F78:
    // 0x80033F78: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80033F7C: jr          $ra
    // 0x80033F80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80033F80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void fb_memcpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B04C: blez        $a2, L_8007B0B0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8007B050: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007B0B0;
    }
    // 0x8007B050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007B054: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x8007B058: beq         $a3, $zero, L_8007B080
    if (ctx->r7 == 0) {
        // 0x8007B05C: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8007B080;
    }
    // 0x8007B05C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_8007B060:
    // 0x8007B060: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8007B064: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007B068: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007B06C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007B070: bne         $v1, $v0, L_8007B060
    if (ctx->r3 != ctx->r2) {
        // 0x8007B074: sb          $t6, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r14;
            goto L_8007B060;
    }
    // 0x8007B074: sb          $t6, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r14;
    // 0x8007B078: beq         $v0, $a2, L_8007B0B0
    if (ctx->r2 == ctx->r6) {
        // 0x8007B07C: nop
    
            goto L_8007B0B0;
    }
    // 0x8007B07C: nop

L_8007B080:
    // 0x8007B080: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8007B084: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8007B088: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x8007B08C: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x8007B090: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8007B094: sb          $t8, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r24;
    // 0x8007B098: lbu         $t9, 0x2($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2);
    // 0x8007B09C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8007B0A0: sb          $t9, -0x2($a1)
    MEM_B(-0X2, ctx->r5) = ctx->r25;
    // 0x8007B0A4: lbu         $t0, -0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X1);
    // 0x8007B0A8: bne         $v0, $a2, L_8007B080
    if (ctx->r2 != ctx->r6) {
        // 0x8007B0AC: sb          $t0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r8;
            goto L_8007B080;
    }
    // 0x8007B0AC: sb          $t0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r8;
L_8007B0B0:
    // 0x8007B0B0: jr          $ra
    // 0x8007B0B4: nop

    return;
    // 0x8007B0B4: nop

;}
RECOMP_FUNC void thread30_bgload(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C7A04: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800C7A08: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800C7A0C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C7A10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C7A14: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C7A18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C7A1C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C7A20: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800C7A24: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800C7A28: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800C7A2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C7A30: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C7A34: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800C7A38: addiu       $s5, $s5, 0x3D00
    ctx->r21 = ADD32(ctx->r21, 0X3D00);
    // 0x800C7A3C: addiu       $s4, $s4, 0x3D08
    ctx->r20 = ADD32(ctx->r20, 0X3D08);
    // 0x800C7A40: addiu       $s3, $s3, 0x3D04
    ctx->r19 = ADD32(ctx->r19, 0X3D04);
    // 0x800C7A44: addiu       $s0, $s0, -0x4DA0
    ctx->r16 = ADD32(ctx->r16, -0X4DA0);
    // 0x800C7A48: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x800C7A4C: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_800C7A50:
    // 0x800C7A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C7A54:
    // 0x800C7A54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C7A58: jal         0x800C9110
    // 0x800C7A5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7A5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800C7A60: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800C7A64: nop

    // 0x800C7A68: bne         $t6, $s2, L_800C7A54
    if (ctx->r14 != ctx->r18) {
        // 0x800C7A6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C7A54;
    }
    // 0x800C7A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C7A70: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800C7A74: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x800C7A78: jal         0x8006E528
    // 0x800C7A7C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_1;
    // 0x800C7A7C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800C7A80: b           L_800C7A50
    // 0x800C7A84: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
        goto L_800C7A50;
    // 0x800C7A84: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800C7A88: nop

    // 0x800C7A8C: nop

    // 0x800C7A90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7A94: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C7A98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C7A9C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7AA0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C7AA4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800C7AA8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800C7AAC: jr          $ra
    // 0x800C7AB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C7AB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void menu_save_options_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FD0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80087FD4: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x80087FD8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80087FDC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80087FE0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80087FE4: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80087FE8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80087FEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80087FF0: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80087FF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80087FF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80087FFC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80088000: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80088004: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80088008: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008800C: beq         $v0, $zero, L_80088034
    if (ctx->r2 == 0) {
        // 0x80088010: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80088034;
    }
    // 0x80088010: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80088014: blez        $v0, L_8008802C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80088018: subu        $t0, $v0, $s0
        ctx->r8 = SUB32(ctx->r2, ctx->r16);
            goto L_8008802C;
    }
    // 0x80088018: subu        $t0, $v0, $s0
    ctx->r8 = SUB32(ctx->r2, ctx->r16);
    // 0x8008801C: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x80088020: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088024: b           L_80088034
    // 0x80088028: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
        goto L_80088034;
    // 0x80088028: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
L_8008802C:
    // 0x8008802C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088030: sw          $t0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r8;
L_80088034:
    // 0x80088034: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80088038: lw          $t1, 0x6980($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6980);
    // 0x8008803C: nop

    // 0x80088040: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x80088044: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80088048: bne         $at, $zero, L_80088058
    if (ctx->r1 != 0) {
        // 0x8008804C: nop
    
            goto L_80088058;
    }
    // 0x8008804C: nop

    // 0x80088050: jal         0x80086E88
    // 0x80088054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    savemenu_move(rdram, ctx);
        goto after_0;
    // 0x80088054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_80088058:
    // 0x80088058: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008805C: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80088060: nop

    // 0x80088064: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x80088068: bne         $at, $zero, L_8008808C
    if (ctx->r1 != 0) {
        // 0x8008806C: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_8008808C;
    }
    // 0x8008806C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80088070: beq         $at, $zero, L_8008808C
    if (ctx->r1 == 0) {
        // 0x80088074: nop
    
            goto L_8008808C;
    }
    // 0x80088074: nop

    // 0x80088078: jal         0x80085FDC
    // 0x8008807C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    savemenu_render(rdram, ctx);
        goto after_1;
    // 0x8008807C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80088080: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80088084: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80088088: nop

L_8008808C:
    // 0x8008808C: beq         $v0, $zero, L_800880DC
    if (ctx->r2 == 0) {
        // 0x80088090: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800880DC;
    }
    // 0x80088090: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088094: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80088098: bne         $at, $zero, L_800880BC
    if (ctx->r1 != 0) {
        // 0x8008809C: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_800880BC;
    }
    // 0x8008809C: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x800880A0: jal         0x80088328
    // 0x800880A4: nop

    savemenu_free(rdram, ctx);
        goto after_2;
    // 0x800880A4: nop

    after_2:
    // 0x800880A8: jal         0x80081820
    // 0x800880AC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    menu_init(rdram, ctx);
        goto after_3;
    // 0x800880AC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_3:
    // 0x800880B0: b           L_80088308
    // 0x800880B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80088308;
    // 0x800880B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800880B8: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
L_800880BC:
    // 0x800880BC: beq         $at, $zero, L_800880D4
    if (ctx->r1 == 0) {
        // 0x800880C0: nop
    
            goto L_800880D4;
    }
    // 0x800880C0: nop

    // 0x800880C4: jal         0x80088328
    // 0x800880C8: nop

    savemenu_free(rdram, ctx);
        goto after_4;
    // 0x800880C8: nop

    after_4:
    // 0x800880CC: jal         0x80081820
    // 0x800880D0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_5;
    // 0x800880D0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_5:
L_800880D4:
    // 0x800880D4: b           L_80088308
    // 0x800880D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80088308;
    // 0x800880D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800880DC:
    // 0x800880DC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800880E0: lw          $t3, 0x6964($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6964);
    // 0x800880E4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800880E8: bne         $t3, $zero, L_8008813C
    if (ctx->r11 != 0) {
        // 0x800880EC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8008813C;
    }
    // 0x800880EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800880F0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800880F4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800880F8: addiu       $s2, $s2, 0x6A04
    ctx->r18 = ADD32(ctx->r18, 0X6A04);
    // 0x800880FC: addiu       $s1, $s1, 0x69FC
    ctx->r17 = ADD32(ctx->r17, 0X69FC);
    // 0x80088100: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80088104:
    // 0x80088104: lb          $t4, 0x0($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X0);
    // 0x80088108: lb          $t5, 0x0($s2)
    ctx->r13 = MEM_B(ctx->r18, 0X0);
    // 0x8008810C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80088110: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80088114: addu        $s4, $s4, $t4
    ctx->r20 = ADD32(ctx->r20, ctx->r12);
    // 0x80088118: jal         0x8006A794
    // 0x8008811C: addu        $s3, $s3, $t5
    ctx->r19 = ADD32(ctx->r19, ctx->r13);
    input_pressed(rdram, ctx);
        goto after_6;
    // 0x8008811C: addu        $s3, $s3, $t5
    ctx->r19 = ADD32(ctx->r19, ctx->r13);
    after_6:
    // 0x80088120: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80088124: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80088128: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008812C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80088130: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80088134: bne         $s0, $at, L_80088104
    if (ctx->r16 != ctx->r1) {
        // 0x80088138: or          $a2, $a2, $v0
        ctx->r6 = ctx->r6 | ctx->r2;
            goto L_80088104;
    }
    // 0x80088138: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
L_8008813C:
    // 0x8008813C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088140: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x80088144: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80088148: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x8008814C: beq         $t6, $zero, L_80088168
    if (ctx->r14 == 0) {
        // 0x80088150: sltiu       $at, $v0, 0x8
        ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
            goto L_80088168;
    }
    // 0x80088150: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80088154: jal         0x80087BA4
    // 0x80088158: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    savemenu_input_message(rdram, ctx);
        goto after_7;
    // 0x80088158: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x8008815C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088160: b           L_800882FC
    // 0x80088164: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
        goto L_800882FC;
    // 0x80088164: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
L_80088168:
    // 0x80088168: beq         $at, $zero, L_800882E0
    if (ctx->r1 == 0) {
        // 0x8008816C: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_800882E0;
    }
    // 0x8008816C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80088170: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80088174: addu        $at, $at, $t7
    gpr jr_addend_80088180 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80088178: lw          $t7, -0x75C0($at)
    ctx->r15 = ADD32(ctx->r1, -0X75C0);
    // 0x8008817C: nop

    // 0x80088180: jr          $t7
    // 0x80088184: nop

    switch (jr_addend_80088180 >> 2) {
        case 0: goto L_80088188; break;
        case 1: goto L_80088198; break;
        case 2: goto L_800881C4; break;
        case 3: goto L_80088204; break;
        case 4: goto L_8008821C; break;
        case 5: goto L_8008825C; break;
        case 6: goto L_80088274; break;
        case 7: goto L_8008828C; break;
        default: switch_error(__func__, 0x80088180, 0x800E8A40);
    }
    // 0x80088184: nop

L_80088188:
    // 0x80088188: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8008818C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088190: b           L_800882E0
    // 0x80088194: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
        goto L_800882E0;
    // 0x80088194: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
L_80088198:
    // 0x80088198: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008819C: addiu       $s0, $s0, 0x6978
    ctx->r16 = ADD32(ctx->r16, 0X6978);
    // 0x800881A0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800881A4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800881A8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800881AC: slti        $at, $t0, 0xB
    ctx->r1 = SIGNED(ctx->r8) < 0XB ? 1 : 0;
    // 0x800881B0: bne         $at, $zero, L_800882E0
    if (ctx->r1 != 0) {
        // 0x800881B4: sw          $t0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r8;
            goto L_800882E0;
    }
    // 0x800881B4: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800881B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800881BC: b           L_800882E0
    // 0x800881C0: sw          $t2, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r10;
        goto L_800882E0;
    // 0x800881C0: sw          $t2, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r10;
L_800881C4:
    // 0x800881C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800881C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800881CC: sw          $zero, 0x7194($at)
    MEM_W(0X7194, ctx->r1) = 0;
    // 0x800881D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800881D4: jal         0x80086704
    // 0x800881D8: swc1        $f4, 0x719C($at)
    MEM_W(0X719C, ctx->r1) = ctx->f4.u32l;
    savemenu_load_sources(rdram, ctx);
        goto after_8;
    // 0x800881D8: swc1        $f4, 0x719C($at)
    MEM_W(0X719C, ctx->r1) = ctx->f4.u32l;
    after_8:
    // 0x800881DC: beq         $v0, $zero, L_800881F4
    if (ctx->r2 == 0) {
        // 0x800881E0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800881F4;
    }
    // 0x800881E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800881E4: jal         0x80087648
    // 0x800881E8: nop

    savemenu_render_error(rdram, ctx);
        goto after_9;
    // 0x800881E8: nop

    after_9:
    // 0x800881EC: b           L_800882E0
    // 0x800881F0: nop

        goto L_800882E0;
    // 0x800881F0: nop

L_800881F4:
    // 0x800881F4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800881F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800881FC: b           L_800882E0
    // 0x80088200: sw          $t3, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r11;
        goto L_800882E0;
    // 0x80088200: sw          $t3, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r11;
L_80088204:
    // 0x80088204: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80088208: jal         0x80087940
    // 0x8008820C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    savemenu_input_source(rdram, ctx);
        goto after_10;
    // 0x8008820C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_10:
    // 0x80088210: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088214: b           L_800882E0
    // 0x80088218: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
        goto L_800882E0;
    // 0x80088218: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
L_8008821C:
    // 0x8008821C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088220: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80088224: sw          $zero, 0x71A4($at)
    MEM_W(0X71A4, ctx->r1) = 0;
    // 0x80088228: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008822C: jal         0x80086C14
    // 0x80088230: swc1        $f6, 0x71AC($at)
    MEM_W(0X71AC, ctx->r1) = ctx->f6.u32l;
    savemenu_load_destinations(rdram, ctx);
        goto after_11;
    // 0x80088230: swc1        $f6, 0x71AC($at)
    MEM_W(0X71AC, ctx->r1) = ctx->f6.u32l;
    after_11:
    // 0x80088234: beq         $v0, $zero, L_8008824C
    if (ctx->r2 == 0) {
        // 0x80088238: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8008824C;
    }
    // 0x80088238: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008823C: jal         0x80087648
    // 0x80088240: nop

    savemenu_render_error(rdram, ctx);
        goto after_12;
    // 0x80088240: nop

    after_12:
    // 0x80088244: b           L_800882E0
    // 0x80088248: nop

        goto L_800882E0;
    // 0x80088248: nop

L_8008824C:
    // 0x8008824C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80088250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088254: b           L_800882E0
    // 0x80088258: sw          $t4, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r12;
        goto L_800882E0;
    // 0x80088258: sw          $t4, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r12;
L_8008825C:
    // 0x8008825C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80088260: jal         0x80087A54
    // 0x80088264: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    savemenu_input_dest(rdram, ctx);
        goto after_13;
    // 0x80088264: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_13:
    // 0x80088268: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008826C: b           L_800882E0
    // 0x80088270: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
        goto L_800882E0;
    // 0x80088270: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
L_80088274:
    // 0x80088274: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80088278: jal         0x80087B3C
    // 0x8008827C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    savemenu_input_confirm(rdram, ctx);
        goto after_14;
    // 0x8008827C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_14:
    // 0x80088280: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80088284: b           L_800882E0
    // 0x80088288: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
        goto L_800882E0;
    // 0x80088288: sw          $v0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r2;
L_8008828C:
    // 0x8008828C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80088290: addiu       $s0, $s0, 0x6978
    ctx->r16 = ADD32(ctx->r16, 0X6978);
    // 0x80088294: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80088298: nop

    // 0x8008829C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800882A0: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x800882A4: bne         $at, $zero, L_800882E0
    if (ctx->r1 != 0) {
        // 0x800882A8: sw          $t6, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r14;
            goto L_800882E0;
    }
    // 0x800882A8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800882AC: jal         0x80086F3C
    // 0x800882B0: nop

    savemenu_write(rdram, ctx);
        goto after_15;
    // 0x800882B0: nop

    after_15:
    // 0x800882B4: beq         $v0, $zero, L_800882CC
    if (ctx->r2 == 0) {
        // 0x800882B8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800882CC;
    }
    // 0x800882B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800882BC: jal         0x80087648
    // 0x800882C0: nop

    savemenu_render_error(rdram, ctx);
        goto after_16;
    // 0x800882C0: nop

    after_16:
    // 0x800882C4: b           L_800882E0
    // 0x800882C8: nop

        goto L_800882E0;
    // 0x800882C8: nop

L_800882CC:
    // 0x800882CC: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x800882D0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800882D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800882D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800882DC: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
L_800882E0:
    // 0x800882E0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800882E4: lw          $t0, -0x604($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X604);
    // 0x800882E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800882EC: beq         $t0, $zero, L_800882FC
    if (ctx->r8 == 0) {
        // 0x800882F0: nop
    
            goto L_800882FC;
    }
    // 0x800882F0: nop

    // 0x800882F4: jal         0x800C06F8
    // 0x800882F8: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_17;
    // 0x800882F8: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_17:
L_800882FC:
    // 0x800882FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088300: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x80088304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80088308:
    // 0x80088308: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008830C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80088310: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80088314: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80088318: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008831C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80088320: jr          $ra
    // 0x80088324: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80088324: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void set_racer_position_and_angle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E170: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001E174: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001E178: addiu       $t3, $t3, -0x4C24
    ctx->r11 = ADD32(ctx->r11, -0X4C24);
    // 0x8001E17C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8001E180: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8001E184: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x8001E188: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8001E18C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8001E190: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8001E194: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8001E198: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8001E19C: blez        $v1, L_8001E2C0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E1A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001E2C0;
    }
    // 0x8001E1A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E1A4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001E1A8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001E1AC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8001E1B0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001E1B4: addiu       $t4, $t4, -0x4C28
    ctx->r12 = ADD32(ctx->r12, -0X4C28);
    // 0x8001E1B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8001E1BC:
    // 0x8001E1BC: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8001E1C0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001E1C4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001E1C8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8001E1CC: nop

    // 0x8001E1D0: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8001E1D4: nop

    // 0x8001E1D8: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8001E1DC: bne         $t7, $zero, L_8001E2B0
    if (ctx->r15 != 0) {
        // 0x8001E1E0: nop
    
            goto L_8001E2B0;
    }
    // 0x8001E1E0: nop

    // 0x8001E1E4: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    // 0x8001E1E8: nop

    // 0x8001E1EC: bne         $t5, $t8, L_8001E2B0
    if (ctx->r13 != ctx->r24) {
        // 0x8001E1F0: nop
    
            goto L_8001E2B0;
    }
    // 0x8001E1F0: nop

    // 0x8001E1F4: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8001E1F8: nop

    // 0x8001E1FC: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x8001E200: nop

    // 0x8001E204: bne         $s0, $t9, L_8001E2B4
    if (ctx->r16 != ctx->r25) {
        // 0x8001E208: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001E2B4;
    }
    // 0x8001E208: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E20C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001E210: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001E214: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001E218: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001E21C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001E220: nop

    // 0x8001E224: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001E228: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001E22C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8001E230: nop

    // 0x8001E234: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001E238: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    // 0x8001E23C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001E240: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001E244: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001E248: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001E24C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001E250: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001E254: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001E258: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8001E25C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001E260: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x8001E264: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001E268: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001E26C: nop

    // 0x8001E270: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8001E274: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8001E278: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001E27C: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x8001E280: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x8001E284: nop

    // 0x8001E288: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x8001E28C: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8001E290: nop

    // 0x8001E294: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x8001E298: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8001E29C: nop

    // 0x8001E2A0: sh          $t6, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r14;
    // 0x8001E2A4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8001E2A8: nop

    // 0x8001E2AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001E2B0:
    // 0x8001E2B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001E2B4:
    // 0x8001E2B4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E2B8: bne         $at, $zero, L_8001E1BC
    if (ctx->r1 != 0) {
        // 0x8001E2BC: nop
    
            goto L_8001E1BC;
    }
    // 0x8001E2BC: nop

L_8001E2C0:
    // 0x8001E2C0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8001E2C4: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8001E2C8: jr          $ra
    // 0x8001E2CC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001E2CC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void update_tricky(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C504: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005C508: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8005C50C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005C510: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005C514: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005C518: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005C51C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005C520: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005C524: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005C528: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005C52C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8005C530: jal         0x8005CC18
    // 0x8005C534: addiu       $a0, $a0, -0x2CB0
    ctx->r4 = ADD32(ctx->r4, -0X2CB0);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005C534: addiu       $a0, $a0, -0x2CB0
    ctx->r4 = ADD32(ctx->r4, -0X2CB0);
    after_0:
    // 0x8005C538: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8005C53C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005C540: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005C544: addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // 0x8005C548: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x8005C54C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005C550: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8005C554: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C558: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x8005C55C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005C560: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C564: nop

    // 0x8005C568: sh          $t2, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r10;
    // 0x8005C56C: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005C570: nop

    // 0x8005C574: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x8005C578: lh          $t4, 0x16A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X16A);
    // 0x8005C57C: nop

    // 0x8005C580: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8005C584: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005C588: nop

    // 0x8005C58C: bne         $t5, $at, L_8005C5B0
    if (ctx->r13 != ctx->r1) {
        // 0x8005C590: lw          $t1, 0x70($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X70);
            goto L_8005C5B0;
    }
    // 0x8005C590: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005C594: jal         0x80021434
    // 0x8005C598: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_1;
    // 0x8005C598: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_1:
    // 0x8005C59C: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005C5A0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005C5A4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005C5A8: sb          $t7, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r15;
    // 0x8005C5AC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
L_8005C5B0:
    // 0x8005C5B0: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8005C5B4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005C5B8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C5BC: bne         $t0, $t8, L_8005C634
    if (ctx->r8 != ctx->r24) {
        // 0x8005C5C0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005C634;
    }
    // 0x8005C5C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005C5C4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005C5C8: beq         $v0, $at, L_8005C634
    if (ctx->r2 == ctx->r1) {
        // 0x8005C5CC: addiu       $t9, $v0, -0xF
        ctx->r25 = ADD32(ctx->r2, -0XF);
            goto L_8005C634;
    }
    // 0x8005C5CC: addiu       $t9, $v0, -0xF
    ctx->r25 = ADD32(ctx->r2, -0XF);
    // 0x8005C5D0: bgez        $t9, L_8005C62C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005C5D4: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_8005C62C;
    }
    // 0x8005C5D4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005C5D8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005C5DC: lb          $t3, -0x24B4($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X24B4);
    // 0x8005C5E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005C5E4: bne         $t3, $zero, L_8005C60C
    if (ctx->r11 != 0) {
        // 0x8005C5E8: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005C60C;
    }
    // 0x8005C5E8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005C5EC: jal         0x8005CCA4
    // 0x8005C5F0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    play_random_boss_sound(rdram, ctx);
        goto after_2;
    // 0x8005C5F0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005C5F4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005C5F8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005C5FC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005C600: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8005C604: sb          $t4, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r12;
    // 0x8005C608: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8005C60C:
    // 0x8005C60C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C610: sb          $t5, -0x24B4($at)
    MEM_B(-0X24B4, ctx->r1) = ctx->r13;
    // 0x8005C614: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005C618: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8005C61C: nop

    // 0x8005C620: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8005C624: b           L_8005C634
    // 0x8005C628: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
        goto L_8005C634;
    // 0x8005C628: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_8005C62C:
    // 0x8005C62C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C630: sb          $zero, -0x24B4($at)
    MEM_B(-0X24B4, ctx->r1) = 0;
L_8005C634:
    // 0x8005C634: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8005C638: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005C63C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005C640: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005C644: jal         0x8004F834
    // 0x8005C648: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    func_8004F7F4(rdram, ctx);
        goto after_3;
    // 0x8005C648: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_3:
    // 0x8005C64C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005C650: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005C654: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005C658: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8005C65C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x8005C660: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x8005C664: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C668: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005C66C: lh          $t9, 0x56($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X56);
    // 0x8005C670: nop

    // 0x8005C674: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005C678: lh          $t2, 0x54($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X54);
    // 0x8005C67C: nop

    // 0x8005C680: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005C684: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005C688: nop

    // 0x8005C68C: beq         $t3, $zero, L_8005C718
    if (ctx->r11 == 0) {
        // 0x8005C690: nop
    
            goto L_8005C718;
    }
    // 0x8005C690: nop

    // 0x8005C694: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C698: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005C69C: beq         $a1, $v1, L_8005C718
    if (ctx->r5 == ctx->r3) {
        // 0x8005C6A0: lui         $at, 0x401E
        ctx->r1 = S32(0X401E << 16);
            goto L_8005C718;
    }
    // 0x8005C6A0: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8005C6A4: sb          $v1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r3;
    // 0x8005C6A8: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005C6AC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005C6B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005C6B4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005C6B8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005C6BC: sb          $a1, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r5;
    // 0x8005C6C0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005C6C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005C6C8: jal         0x8005CCA4
    // 0x8005C6CC: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    play_random_boss_sound(rdram, ctx);
        goto after_4;
    // 0x8005C6CC: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    after_4:
    // 0x8005C6D0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005C6D4: jal         0x80001D04
    // 0x8005C6D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8005C6D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8005C6DC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005C6E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005C6E4: jal         0x8006A168
    // 0x8005C6E8: nop

    set_camera_shake(rdram, ctx);
        goto after_6;
    // 0x8005C6E8: nop

    after_6:
    // 0x8005C6EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C6F0: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C6F4: lwc1        $f9, 0x6FA0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FA0);
    // 0x8005C6F8: lwc1        $f8, 0x6FA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x8005C6FC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005C700: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005C704: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005C708: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C70C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005C710: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005C714: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_8005C718:
    // 0x8005C718: lw          $t4, 0x148($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X148);
    // 0x8005C71C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8005C720: beq         $t4, $zero, L_8005C768
    if (ctx->r12 == 0) {
        // 0x8005C724: sb          $zero, 0x187($s0)
        MEM_B(0X187, ctx->r16) = 0;
            goto L_8005C768;
    }
    // 0x8005C724: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005C728: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005C72C: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005C730: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005C734: nop

    // 0x8005C738: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005C73C: nop

    // 0x8005C740: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005C744: nop

    // 0x8005C748: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005C74C: jal         0x800CA030
    // 0x8005C750: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8005C750: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_7:
    // 0x8005C754: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8005C758: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005C75C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8005C760: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005C764: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_8005C768:
    // 0x8005C768: lw          $t5, 0x68($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X68);
    // 0x8005C76C: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C770: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8005C774: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8005C778: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005C77C: nop

    // 0x8005C780: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x8005C784: nop

    // 0x8005C788: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8005C78C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8005C790: nop

    // 0x8005C794: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x8005C798: addiu       $t3, $t2, -0x11
    ctx->r11 = ADD32(ctx->r10, -0X11);
    // 0x8005C79C: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8005C7A0: beq         $a1, $v1, L_8005C890
    if (ctx->r5 == ctx->r3) {
        // 0x8005C7A4: cvt.s.w     $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8005C890;
    }
    // 0x8005C7A4: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005C7A8: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C7AC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005C7B0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005C7B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C7B8: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8005C7BC: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005C7C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005C7C4: bc1f        L_8005C808
    if (!c1cs) {
        // 0x8005C7C8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005C808;
    }
    // 0x8005C7C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C7CC: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005C7D0: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C7D4: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C7D8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8005C7DC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005C7E0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005C7E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C7E8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C7EC: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005C7F0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8005C7F4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005C7F8: sub.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f10.d - ctx->f6.d;
    // 0x8005C7FC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005C800: b           L_8005C8B0
    // 0x8005C804: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005C8B0;
    // 0x8005C804: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005C808:
    // 0x8005C808: lwc1        $f9, 0x6FA8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FA8);
    // 0x8005C80C: lwc1        $f8, 0x6FAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FAC);
    // 0x8005C810: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C814: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005C818: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8005C81C: bc1t        L_8005C840
    if (c1cs) {
        // 0x8005C820: nop
    
            goto L_8005C840;
    }
    // 0x8005C820: nop

    // 0x8005C824: lwc1        $f11, 0x6FB0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6FB0);
    // 0x8005C828: lwc1        $f10, 0x6FB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6FB4);
    // 0x8005C82C: nop

    // 0x8005C830: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8005C834: nop

    // 0x8005C838: bc1f        L_8005C86C
    if (!c1cs) {
        // 0x8005C83C: nop
    
            goto L_8005C86C;
    }
    // 0x8005C83C: nop

L_8005C840:
    // 0x8005C840: sb          $t5, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r13;
    // 0x8005C844: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C848: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005C84C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005C850: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8005C854: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005C858: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C85C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005C860: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8005C864: b           L_8005C8B0
    // 0x8005C868: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005C8B0;
    // 0x8005C868: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005C86C:
    // 0x8005C86C: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8005C870: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C874: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C878: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8005C87C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8005C880: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x8005C884: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005C888: b           L_8005C8B0
    // 0x8005C88C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005C8B0;
    // 0x8005C88C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005C890:
    // 0x8005C890: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005C894: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C898: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8005C89C: add.d       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f0.d + ctx->f0.d;
    // 0x8005C8A0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005C8A4: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8005C8A8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005C8AC: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_8005C8B0:
    // 0x8005C8B0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C8B4: nop

    // 0x8005C8B8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005C8BC: nop

    // 0x8005C8C0: bc1f        L_8005C8EC
    if (!c1cs) {
        // 0x8005C8C4: nop
    
            goto L_8005C8EC;
    }
    // 0x8005C8C4: nop

L_8005C8C8:
    // 0x8005C8C8: add.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005C8CC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8005C8D0: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005C8D4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C8D8: nop

    // 0x8005C8DC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005C8E0: nop

    // 0x8005C8E4: bc1t        L_8005C8C8
    if (c1cs) {
        // 0x8005C8E8: nop
    
            goto L_8005C8C8;
    }
    // 0x8005C8E8: nop

L_8005C8EC:
    // 0x8005C8EC: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005C8F0: nop

    // 0x8005C8F4: bc1f        L_8005C920
    if (!c1cs) {
        // 0x8005C8F8: nop
    
            goto L_8005C920;
    }
    // 0x8005C8F8: nop

L_8005C8FC:
    // 0x8005C8FC: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005C900: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8005C904: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005C908: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C90C: nop

    // 0x8005C910: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005C914: nop

    // 0x8005C918: bc1t        L_8005C8FC
    if (c1cs) {
        // 0x8005C91C: nop
    
            goto L_8005C8FC;
    }
    // 0x8005C91C: nop

L_8005C920:
    // 0x8005C920: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x8005C924: nop

    // 0x8005C928: bne         $t0, $t6, L_8005C954
    if (ctx->r8 != ctx->r14) {
        // 0x8005C92C: nop
    
            goto L_8005C954;
    }
    // 0x8005C92C: nop

    // 0x8005C930: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C934: nop

    // 0x8005C938: bne         $a1, $t7, L_8005C954
    if (ctx->r5 != ctx->r15) {
        // 0x8005C93C: nop
    
            goto L_8005C954;
    }
    // 0x8005C93C: nop

    // 0x8005C940: lbu         $t8, 0x1CD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005C944: nop

    // 0x8005C948: sb          $t8, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r24;
    // 0x8005C94C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005C950: nop

L_8005C954:
    // 0x8005C954: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005C958: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    // 0x8005C95C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005C960: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005C964: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005C968: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x8005C96C: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005C970: lb          $t4, 0x3B($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C974: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8005C978: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C97C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005C980: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005C984: bne         $t4, $at, L_8005C9B8
    if (ctx->r12 != ctx->r1) {
        // 0x8005C988: sh          $t3, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r11;
            goto L_8005C9B8;
    }
    // 0x8005C988: sh          $t3, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r11;
    // 0x8005C98C: lh          $a2, 0x54($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X54);
    // 0x8005C990: addiu       $t5, $zero, 0xAD
    ctx->r13 = ADD32(0, 0XAD);
    // 0x8005C994: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005C998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005C99C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8005C9A0: jal         0x800113CC
    // 0x8005C9A4: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_8;
    // 0x8005C9A4: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_8:
    // 0x8005C9A8: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x8005C9AC: nop

    // 0x8005C9B0: ori         $t7, $t6, 0x3
    ctx->r15 = ctx->r14 | 0X3;
    // 0x8005C9B4: sw          $t7, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r15;
L_8005C9B8:
    // 0x8005C9B8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8005C9BC: jal         0x800B019C
    // 0x8005C9C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_9;
    // 0x8005C9C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8005C9C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005C9C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005C9CC: jal         0x8005D1E8
    // 0x8005C9D0: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    fade_when_near_camera(rdram, ctx);
        goto after_10;
    // 0x8005C9D0: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_10:
    // 0x8005C9D4: lb          $v0, 0x3B($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3B);
    // 0x8005C9D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005C9DC: beq         $v0, $at, L_8005C9F8
    if (ctx->r2 == ctx->r1) {
        // 0x8005C9E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005C9F8;
    }
    // 0x8005C9E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005C9E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005C9E8: beq         $v0, $at, L_8005CA00
    if (ctx->r2 == ctx->r1) {
        // 0x8005C9EC: addiu       $a1, $zero, 0x100
        ctx->r5 = ADD32(0, 0X100);
            goto L_8005CA00;
    }
    // 0x8005C9EC: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8005C9F0: b           L_8005CA00
    // 0x8005C9F4: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
        goto L_8005CA00;
    // 0x8005C9F4: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
L_8005C9F8:
    // 0x8005C9F8: b           L_8005CA00
    // 0x8005C9FC: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
        goto L_8005CA00;
    // 0x8005C9FC: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
L_8005CA00:
    // 0x8005CA00: jal         0x8001BAFC
    // 0x8005CA04: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    get_racer_object(rdram, ctx);
        goto after_11;
    // 0x8005CA04: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_11:
    // 0x8005CA08: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8005CA0C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005CA10: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005CA14: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005CA18: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005CA1C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005CA20: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005CA24: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005CA28: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x8005CA2C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005CA30: jal         0x800CA030
    // 0x8005CA34: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x8005CA34: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_12:
    // 0x8005CA38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005CA3C: lwc1        $f9, 0x6FB8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FB8);
    // 0x8005CA40: lwc1        $f8, 0x6FBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FBC);
    // 0x8005CA44: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005CA48: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8005CA4C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005CA50: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8005CA54: bc1f        L_8005CAD0
    if (!c1cs) {
        // 0x8005CA58: nop
    
            goto L_8005CAD0;
    }
    // 0x8005CA58: nop

    // 0x8005CA5C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8005CA60: jal         0x80070990
    // 0x8005CA64: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_13;
    // 0x8005CA64: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_13:
    // 0x8005CA68: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x8005CA6C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005CA70: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8005CA74: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x8005CA78: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005CA7C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005CA80: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005CA84: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005CA88: bne         $at, $zero, L_8005CA9C
    if (ctx->r1 != 0) {
        // 0x8005CA8C: negu        $v0, $a1
        ctx->r2 = SUB32(0, ctx->r5);
            goto L_8005CA9C;
    }
    // 0x8005CA8C: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
    // 0x8005CA90: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005CA94: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005CA98: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005CA9C:
    // 0x8005CA9C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005CAA0: beq         $at, $zero, L_8005CAAC
    if (ctx->r1 == 0) {
        // 0x8005CAA4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005CAAC;
    }
    // 0x8005CAA4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005CAA8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005CAAC:
    // 0x8005CAAC: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005CAB0: beq         $at, $zero, L_8005CAC0
    if (ctx->r1 == 0) {
        // 0x8005CAB4: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8005CAC0;
    }
    // 0x8005CAB4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005CAB8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8005CABC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8005CAC0:
    // 0x8005CAC0: beq         $at, $zero, L_8005CACC
    if (ctx->r1 == 0) {
        // 0x8005CAC4: nop
    
            goto L_8005CACC;
    }
    // 0x8005CAC4: nop

    // 0x8005CAC8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8005CACC:
    // 0x8005CACC: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005CAD0:
    // 0x8005CAD0: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005CAD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CAD8: bne         $t2, $at, L_8005CB08
    if (ctx->r10 != ctx->r1) {
        // 0x8005CADC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8005CB08;
    }
    // 0x8005CADC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005CAE0: lb          $t3, 0x1E7($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005CAE4: nop

    // 0x8005CAE8: andi        $t4, $t3, 0x1F
    ctx->r12 = ctx->r11 & 0X1F;
    // 0x8005CAEC: slti        $at, $t4, 0xA
    ctx->r1 = SIGNED(ctx->r12) < 0XA ? 1 : 0;
    // 0x8005CAF0: beq         $at, $zero, L_8005CB0C
    if (ctx->r1 == 0) {
        // 0x8005CAF4: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_8005CB0C;
    }
    // 0x8005CAF4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8005CAF8: lh          $t5, 0x16C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X16C);
    // 0x8005CAFC: nop

    // 0x8005CB00: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8005CB04: sh          $t6, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r14;
L_8005CB08:
    // 0x8005CB08: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_8005CB0C:
    // 0x8005CB0C: addiu       $v0, $v0, -0x24C0
    ctx->r2 = ADD32(ctx->r2, -0X24C0);
    // 0x8005CB10: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005CB14: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005CB18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005CB1C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005CB20: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005CB24: bc1f        L_8005CB3C
    if (!c1cs) {
        // 0x8005CB28: lui         $at, 0x4079
        ctx->r1 = S32(0X4079 << 16);
            goto L_8005CB3C;
    }
    // 0x8005CB28: lui         $at, 0x4079
    ctx->r1 = S32(0X4079 << 16);
    // 0x8005CB2C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8005CB30: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005CB34: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005CB38: nop

L_8005CB3C:
    // 0x8005CB3C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005CB40: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8005CB44: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x8005CB48: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8005CB4C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005CB50: nop

    // 0x8005CB54: bc1f        L_8005CB94
    if (!c1cs) {
        // 0x8005CB58: nop
    
            goto L_8005CB94;
    }
    // 0x8005CB58: nop

    // 0x8005CB5C: jal         0x800C06AC
    // 0x8005CB60: nop

    check_fadeout_transition(rdram, ctx);
        goto after_14;
    // 0x8005CB60: nop

    after_14:
    // 0x8005CB64: bne         $v0, $zero, L_8005CB84
    if (ctx->r2 != 0) {
        // 0x8005CB68: nop
    
            goto L_8005CB84;
    }
    // 0x8005CB68: nop

    // 0x8005CB6C: jal         0x8009F1C4
    // 0x8005CB70: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_15;
    // 0x8005CB70: nop

    after_15:
    // 0x8005CB74: beq         $v0, $zero, L_8005CB84
    if (ctx->r2 == 0) {
        // 0x8005CB78: nop
    
            goto L_8005CB84;
    }
    // 0x8005CB78: nop

    // 0x8005CB7C: jal         0x8006F5D8
    // 0x8005CB80: nop

    swap_lead_player(rdram, ctx);
        goto after_16;
    // 0x8005CB80: nop

    after_16:
L_8005CB84:
    // 0x8005CB84: jal         0x8006F380
    // 0x8005CB88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    level_transition_begin(rdram, ctx);
        goto after_17;
    // 0x8005CB88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x8005CB8C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8005CB90: nop

L_8005CB94:
    // 0x8005CB94: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005CB98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005CB9C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8005CBA0: addiu       $a1, $a1, -0x24BC
    ctx->r5 = ADD32(ctx->r5, -0X24BC);
    // 0x8005CBA4: bne         $s1, $t7, L_8005CBD4
    if (ctx->r17 != ctx->r15) {
        // 0x8005CBA8: nop
    
            goto L_8005CBD4;
    }
    // 0x8005CBA8: nop

    // 0x8005CBAC: lh          $t8, 0x14($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X14);
    // 0x8005CBB0: nop

    // 0x8005CBB4: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8005CBB8: beq         $t9, $zero, L_8005CBD4
    if (ctx->r25 == 0) {
        // 0x8005CBBC: nop
    
            goto L_8005CBD4;
    }
    // 0x8005CBBC: nop

    // 0x8005CBC0: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005CBC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CBC8: bne         $t2, $at, L_8005CBD4
    if (ctx->r10 != ctx->r1) {
        // 0x8005CBCC: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_8005CBD4;
    }
    // 0x8005CBCC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8005CBD0: sb          $t3, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r11;
L_8005CBD4:
    // 0x8005CBD4: lb          $t4, 0x1D8($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005CBD8: nop

    // 0x8005CBDC: beq         $t4, $zero, L_8005CC00
    if (ctx->r12 == 0) {
        // 0x8005CBE0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005CC00;
    }
    // 0x8005CBE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CBE4: lb          $t5, 0x0($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X0);
    // 0x8005CBE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005CBEC: bne         $t5, $zero, L_8005CBFC
    if (ctx->r13 != 0) {
        // 0x8005CBF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005CBFC;
    }
    // 0x8005CBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CBF4: jal         0x8005CD08
    // 0x8005CBF8: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    racer_boss_finish(rdram, ctx);
        goto after_18;
    // 0x8005CBF8: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    after_18:
L_8005CBFC:
    // 0x8005CBFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005CC00:
    // 0x8005CC00: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005CC04: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005CC08: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005CC0C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005CC10: jr          $ra
    // 0x8005CC14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005CC14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void set_collision_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002AD0C: jr          $ra
    // 0x8002AD10: sw          $a0, -0x498C($at)
    MEM_W(-0X498C, ctx->r1) = ctx->r4;
    return;
    // 0x8002AD10: sw          $a0, -0x498C($at)
    MEM_W(-0X498C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void charselect_pick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B980: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008B984: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008B988: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008B98C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B990: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008B994: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008B998: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008B99C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008B9A0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008B9A4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008B9A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008B9AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008B9B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008B9B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008B9B8: addiu       $s4, $s4, 0x6D78
    ctx->r20 = ADD32(ctx->r20, 0X6D78);
    // 0x8008B9BC: addiu       $s1, $s1, 0x6974
    ctx->r17 = ADD32(ctx->r17, 0X6974);
    // 0x8008B9C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8008B9C4:
    // 0x8008B9C4: lb          $t6, 0x0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X0);
    // 0x8008B9C8: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8008B9CC: beq         $t6, $zero, L_8008B9E0
    if (ctx->r14 == 0) {
        // 0x8008B9D0: addu        $t8, $s4, $t7
        ctx->r24 = ADD32(ctx->r20, ctx->r15);
            goto L_8008B9E0;
    }
    // 0x8008B9D0: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x8008B9D4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8008B9D8: nop

    // 0x8008B9DC: or          $v0, $v0, $t9
    ctx->r2 = ctx->r2 | ctx->r25;
L_8008B9E0:
    // 0x8008B9E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B9E4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8008B9E8: bne         $at, $zero, L_8008B9C4
    if (ctx->r1 != 0) {
        // 0x8008B9EC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8008B9C4;
    }
    // 0x8008B9EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008B9F0: andi        $t0, $v0, 0x9000
    ctx->r8 = ctx->r2 & 0X9000;
    // 0x8008B9F4: beq         $t0, $zero, L_8008BB14
    if (ctx->r8 == 0) {
        // 0x8008B9F8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8008BB14;
    }
    // 0x8008B9F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008B9FC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8008BA00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BA04: jal         0x8006EDE8
    // 0x8008BA08: sw          $s2, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r18;
    mark_read_all_save_files(rdram, ctx);
        goto after_0;
    // 0x8008BA08: sw          $s2, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r18;
    after_0:
    // 0x8008BA0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008BA10: jal         0x800C06F8
    // 0x8008BA14: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8008BA14: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_1:
    // 0x8008BA18: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008BA1C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8008BA20: addiu       $v0, $v0, 0x6D78
    ctx->r2 = ADD32(ctx->r2, 0X6D78);
    // 0x8008BA24: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8008BA28:
    // 0x8008BA28: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8008BA2C: nop

    // 0x8008BA30: andi        $t2, $t1, 0x9000
    ctx->r10 = ctx->r9 & 0X9000;
    // 0x8008BA34: beq         $t2, $zero, L_8008BA40
    if (ctx->r10 == 0) {
        // 0x8008BA38: nop
    
            goto L_8008BA40;
    }
    // 0x8008BA38: nop

    // 0x8008BA3C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_8008BA40:
    // 0x8008BA40: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008BA44: slti        $t3, $s0, 0x4
    ctx->r11 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8008BA48: slti        $t4, $s1, 0x0
    ctx->r12 = SIGNED(ctx->r17) < 0X0 ? 1 : 0;
    // 0x8008BA4C: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x8008BA50: bne         $t5, $zero, L_8008BA28
    if (ctx->r13 != 0) {
        // 0x8008BA54: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8008BA28;
    }
    // 0x8008BA54: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008BA58: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008BA5C: addiu       $s7, $s7, 0x6DA8
    ctx->r23 = ADD32(ctx->r23, 0X6DA8);
    // 0x8008BA60: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8008BA64: addu        $s0, $s7, $t6
    ctx->r16 = ADD32(ctx->r23, ctx->r14);
    // 0x8008BA68: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008BA6C: nop

    // 0x8008BA70: beq         $a0, $zero, L_8008BA80
    if (ctx->r4 == 0) {
        // 0x8008BA74: nop
    
            goto L_8008BA80;
    }
    // 0x8008BA74: nop

    // 0x8008BA78: jal         0x8000488C
    // 0x8008BA7C: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x8008BA7C: nop

    after_2:
L_8008BA80:
    // 0x8008BA80: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008BA84: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x8008BA88: lb          $t8, 0x6988($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X6988);
    // 0x8008BA8C: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008BA90: addiu       $fp, $fp, 0x696C
    ctx->r30 = ADD32(ctx->r30, 0X696C);
    // 0x8008BA94: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8008BA98: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x8008BA9C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8008BAA0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8008BAA4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8008BAA8: lh          $a0, 0xC($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XC);
    // 0x8008BAAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8008BAB0: addiu       $a0, $a0, 0x19E
    ctx->r4 = ADD32(ctx->r4, 0X19E);
    // 0x8008BAB4: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x8008BAB8: jal         0x80001D04
    // 0x8008BABC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008BABC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
    // 0x8008BAC0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008BAC4: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8008BAC8: nop

    // 0x8008BACC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8008BAD0: beq         $at, $zero, L_8008BB04
    if (ctx->r1 == 0) {
        // 0x8008BAD4: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8008BB04;
    }
    // 0x8008BAD4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8008BAD8: bne         $at, $zero, L_8008BAF0
    if (ctx->r1 != 0) {
        // 0x8008BADC: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_8008BAF0;
    }
    // 0x8008BADC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008BAE0: lw          $t2, 0x318($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X318);
    // 0x8008BAE4: nop

    // 0x8008BAE8: sll         $t3, $t2, 7
    ctx->r11 = S32(ctx->r10 << 7);
    // 0x8008BAEC: bgez        $t3, L_8008BB04
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8008BAF0: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8008BB04;
    }
L_8008BAF0:
    // 0x8008BAF0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008BAF4: lw          $t4, 0x550($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X550);
    // 0x8008BAF8: nop

    // 0x8008BAFC: bne         $s2, $t4, L_8008BBE4
    if (ctx->r18 != ctx->r12) {
        // 0x8008BB00: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8008BBE4;
    }
    // 0x8008BB00: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8008BB04:
    // 0x8008BB04: jal         0x80000C98
    // 0x8008BB08: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_4;
    // 0x8008BB08: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_4:
    // 0x8008BB0C: b           L_8008BBE4
    // 0x8008BB10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8008BBE4;
    // 0x8008BB10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8008BB14:
    // 0x8008BB14: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008BB18: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008BB1C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008BB20: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008BB24: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008BB28: addiu       $s3, $s3, -0x600
    ctx->r19 = ADD32(ctx->r19, -0X600);
    // 0x8008BB2C: addiu       $s5, $s5, 0x697C
    ctx->r21 = ADD32(ctx->r21, 0X697C);
    // 0x8008BB30: addiu       $s7, $s7, 0x6DA8
    ctx->r23 = ADD32(ctx->r23, 0X6DA8);
    // 0x8008BB34: addiu       $fp, $fp, 0x696C
    ctx->r30 = ADD32(ctx->r30, 0X696C);
    // 0x8008BB38: addiu       $s1, $s1, 0x6974
    ctx->r17 = ADD32(ctx->r17, 0X6974);
    // 0x8008BB3C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_8008BB40:
    // 0x8008BB40: lb          $t5, 0x0($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X0);
    // 0x8008BB44: addu        $v1, $s5, $s0
    ctx->r3 = ADD32(ctx->r21, ctx->r16);
    // 0x8008BB48: beq         $t5, $zero, L_8008BBD4
    if (ctx->r13 == 0) {
        // 0x8008BB4C: nop
    
            goto L_8008BBD4;
    }
    // 0x8008BB4C: nop

    // 0x8008BB50: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x8008BB54: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8008BB58: beq         $t6, $zero, L_8008BBD4
    if (ctx->r14 == 0) {
        // 0x8008BB5C: addu        $t8, $s4, $v0
        ctx->r24 = ADD32(ctx->r20, ctx->r2);
            goto L_8008BBD4;
    }
    // 0x8008BB5C: addu        $t8, $s4, $v0
    ctx->r24 = ADD32(ctx->r20, ctx->r2);
    // 0x8008BB60: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8008BB64: addu        $a1, $s7, $v0
    ctx->r5 = ADD32(ctx->r23, ctx->r2);
    // 0x8008BB68: andi        $t9, $t7, 0x4000
    ctx->r25 = ctx->r15 & 0X4000;
    // 0x8008BB6C: beq         $t9, $zero, L_8008BBD4
    if (ctx->r25 == 0) {
        // 0x8008BB70: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8008BBD4;
    }
    // 0x8008BB70: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008BB74: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8008BB78: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8008BB7C: addiu       $t2, $t2, 0x6988
    ctx->r10 = ADD32(ctx->r10, 0X6988);
    // 0x8008BB80: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8008BB84: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8008BB88: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x8008BB8C: beq         $a0, $zero, L_8008BBA4
    if (ctx->r4 == 0) {
        // 0x8008BB90: addu        $s2, $s0, $t2
        ctx->r18 = ADD32(ctx->r16, ctx->r10);
            goto L_8008BBA4;
    }
    // 0x8008BB90: addu        $s2, $s0, $t2
    ctx->r18 = ADD32(ctx->r16, ctx->r10);
    // 0x8008BB94: jal         0x8000488C
    // 0x8008BB98: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_5;
    // 0x8008BB98: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_5:
    // 0x8008BB9C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8008BBA0: nop

L_8008BBA4:
    // 0x8008BBA4: lb          $t4, 0x0($s2)
    ctx->r12 = MEM_B(ctx->r18, 0X0);
    // 0x8008BBA8: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x8008BBAC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8008BBB0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008BBB4: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8008BBB8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8008BBBC: lh          $a0, 0xC($t6)
    ctx->r4 = MEM_H(ctx->r14, 0XC);
    // 0x8008BBC0: nop

    // 0x8008BBC4: addiu       $a0, $a0, 0x93
    ctx->r4 = ADD32(ctx->r4, 0X93);
    // 0x8008BBC8: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x8008BBCC: jal         0x80001D04
    // 0x8008BBD0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008BBD0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_6:
L_8008BBD4:
    // 0x8008BBD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008BBD8: bne         $s0, $s6, L_8008BB40
    if (ctx->r16 != ctx->r22) {
        // 0x8008BBDC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8008BB40;
    }
    // 0x8008BBDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008BBE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8008BBE4:
    // 0x8008BBE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008BBE8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BBEC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008BBF0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008BBF4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008BBF8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008BBFC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008BC00: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008BC04: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8008BC08: jr          $ra
    // 0x8008BC0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8008BC0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void bgdraw_primcolour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077F84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077F88: sb          $a0, -0x15D0($at)
    MEM_B(-0X15D0, ctx->r1) = ctx->r4;
    // 0x80077F8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077F90: sb          $a1, -0x15CC($at)
    MEM_B(-0X15CC, ctx->r1) = ctx->r5;
    // 0x80077F94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077F98: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80077F9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80077FA0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80077FA4: jr          $ra
    // 0x80077FA8: sb          $a2, -0x15C8($at)
    MEM_B(-0X15C8, ctx->r1) = ctx->r6;
    return;
    // 0x80077FA8: sb          $a2, -0x15C8($at)
    MEM_B(-0X15C8, ctx->r1) = ctx->r6;
;}
RECOMP_FUNC void bootscreen_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088C44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088C48: jal         0x8009C9EC
    // 0x80088C4C: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x80088C4C: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    after_0:
    // 0x80088C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088C54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80088C58: jr          $ra
    // 0x80088C5C: nop

    return;
    // 0x80088C5C: nop

;}
RECOMP_FUNC void handle_car_steering(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800534B8: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800534BC: mtc1        $zero, $f13
    ctx->f_odd[(13 - 1) * 2] = 0;
    // 0x800534C0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800534C4: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800534C8: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    // 0x800534CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800534D0: bc1f        L_800534E0
    if (!c1cs) {
        // 0x800534D4: nop
    
            goto L_800534E0;
    }
    // 0x800534D4: nop

    // 0x800534D8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800534DC: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_800534E0:
    // 0x800534E0: lwc1        $f5, 0x6CE0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6CE0);
    // 0x800534E4: lwc1        $f4, 0x6CE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6CE4);
    // 0x800534E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800534EC: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x800534F0: nop

    // 0x800534F4: bc1f        L_80053508
    if (!c1cs) {
        // 0x800534F8: nop
    
            goto L_80053508;
    }
    // 0x800534F8: nop

    // 0x800534FC: lwc1        $f0, 0x6CE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6CE8);
    // 0x80053500: nop

    // 0x80053504: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_80053508:
    // 0x80053508: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005350C: lwc1        $f7, 0x6CF0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6CF0);
    // 0x80053510: lwc1        $f6, 0x6CF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6CF4);
    // 0x80053514: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x80053518: sub.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d - ctx->f6.d;
    // 0x8005351C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80053520: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80053524: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x80053528: nop

    // 0x8005352C: bc1f        L_8005353C
    if (!c1cs) {
        // 0x80053530: nop
    
            goto L_8005353C;
    }
    // 0x80053530: nop

    // 0x80053534: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80053538: nop

L_8005353C:
    // 0x8005353C: lb          $t6, 0x1E6($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1E6);
    // 0x80053540: nop

    // 0x80053544: beq         $t6, $zero, L_80053588
    if (ctx->r14 == 0) {
        // 0x80053548: nop
    
            goto L_80053588;
    }
    // 0x80053548: nop

    // 0x8005354C: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    // 0x80053550: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80053554: nop

    // 0x80053558: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8005355C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80053560: nop

    // 0x80053564: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80053568: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005356C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80053570: nop

    // 0x80053574: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80053578: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8005357C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80053580: b           L_800535C0
    // 0x80053584: lb          $t0, 0x1E1($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X1E1);
        goto L_800535C0;
    // 0x80053584: lb          $t0, 0x1E1($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X1E1);
L_80053588:
    // 0x80053588: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005358C: nop

    // 0x80053590: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80053594: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80053598: nop

    // 0x8005359C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800535A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800535A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800535A8: nop

    // 0x800535AC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800535B0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800535B4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800535B8: nop

    // 0x800535BC: lb          $t0, 0x1E1($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X1E1);
L_800535C0:
    // 0x800535C0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800535C4: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800535C8: addiu       $v1, $v1, -0x252C
    ctx->r3 = ADD32(ctx->r3, -0X252C);
    // 0x800535CC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800535D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800535D4: mflo        $t1
    ctx->r9 = lo;
    // 0x800535D8: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x800535DC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800535E0: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800535E4: negu        $t4, $t2
    ctx->r12 = SUB32(0, ctx->r10);
    // 0x800535E8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800535EC: nop

    // 0x800535F0: bc1f        L_800535FC
    if (!c1cs) {
        // 0x800535F4: nop
    
            goto L_800535FC;
    }
    // 0x800535F4: nop

    // 0x800535F8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_800535FC:
    // 0x800535FC: jr          $ra
    // 0x80053600: nop

    return;
    // 0x80053600: nop

;}
RECOMP_FUNC void fb_mode_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A92C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007A930: lw          $t6, 0x686C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X686C);
    // 0x8007A934: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007A938: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8007A93C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8007A940: addiu       $t9, $t9, -0x1304
    ctx->r25 = ADD32(ctx->r25, -0X1304);
    // 0x8007A944: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8007A948: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8007A94C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8007A950: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A954: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8007A958: sw          $t0, 0x6850($at)
    MEM_W(0X6850, ctx->r1) = ctx->r8;
    // 0x8007A95C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8007A960: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A964: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8007A968: jr          $ra
    // 0x8007A96C: sw          $t1, 0x6858($at)
    MEM_W(0X6858, ctx->r1) = ctx->r9;
    return;
    // 0x8007A96C: sw          $t1, 0x6858($at)
    MEM_W(0X6858, ctx->r1) = ctx->r9;
;}
RECOMP_FUNC void mempool_free_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800712F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800712F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800712F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800712FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80071300: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80071304: jal         0x8006F750
    // 0x80071308: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80071308: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x8007130C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80071310: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80071314: bne         $s0, $zero, L_8007135C
    if (ctx->r16 != 0) {
        // 0x80071318: sw          $s0, 0x434C($at)
        MEM_W(0X434C, ctx->r1) = ctx->r16;
            goto L_8007135C;
    }
    // 0x80071318: sw          $s0, 0x434C($at)
    MEM_W(0X434C, ctx->r1) = ctx->r16;
    // 0x8007131C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80071320: addiu       $s1, $s1, 0x4348
    ctx->r17 = ADD32(ctx->r17, 0X4348);
    // 0x80071324: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80071328: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007132C: blez        $s0, L_8007135C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80071330: addiu       $s2, $s2, 0x3B48
        ctx->r18 = ADD32(ctx->r18, 0X3B48);
            goto L_8007135C;
    }
    // 0x80071330: addiu       $s2, $s2, 0x3B48
    ctx->r18 = ADD32(ctx->r18, 0X3B48);
    // 0x80071334: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
L_80071338:
    // 0x80071338: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8007133C: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x80071340: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80071344: jal         0x800714B8
    // 0x80071348: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    mempool_free_addr(rdram, ctx);
        goto after_1;
    // 0x80071348: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_1:
    // 0x8007134C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80071350: nop

    // 0x80071354: bgtz        $s0, L_80071338
    if (SIGNED(ctx->r16) > 0) {
        // 0x80071358: addiu       $v0, $s0, -0x1
        ctx->r2 = ADD32(ctx->r16, -0X1);
            goto L_80071338;
    }
    // 0x80071358: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
L_8007135C:
    // 0x8007135C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80071360: jal         0x8006F77C
    // 0x80071364: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x80071364: nop

    after_2:
    // 0x80071368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007136C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071370: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80071374: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80071378: jr          $ra
    // 0x8007137C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007137C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void sound_reverb_enabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002630: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002634: lbu         $t7, 0x6284($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X6284);
    // 0x80002638: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8000263C: lw          $t6, 0x629C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X629C);
    // 0x80002640: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80002644: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80002648: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000264C: lbu         $v0, 0x2($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X2);
    // 0x80002650: jr          $ra
    // 0x80002654: nop

    return;
    // 0x80002654: nop

;}
RECOMP_FUNC void transition_render_fullscreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0F30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C0F34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C0F38: jal         0x8007A970
    // 0x800C0F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800C0F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C0F40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C0F44: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C0F48: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0F4C: addiu       $t8, $t8, 0x3768
    ctx->r24 = ADD32(ctx->r24, 0X3768);
    // 0x800C0F50: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C0F54: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C0F58: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C0F5C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C0F60: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C0F64: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0F68: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800C0F6C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C0F70: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C0F74: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C0F78: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800C0F7C: lbu         $t6, -0x530B($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0X530B);
    // 0x800C0F80: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C0F84: lbu         $t3, -0x530C($t2)
    ctx->r11 = MEM_BU(ctx->r10, -0X530C);
    // 0x800C0F88: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C0F8C: lbu         $t1, -0x530A($t9)
    ctx->r9 = MEM_BU(ctx->r25, -0X530A);
    // 0x800C0F90: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800C0F94: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C0F98: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x800C0F9C: lbu         $t6, -0x5309($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0X5309);
    // 0x800C0FA0: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800C0FA4: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800C0FA8: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x800C0FAC: or          $t4, $t3, $t6
    ctx->r12 = ctx->r11 | ctx->r14;
    // 0x800C0FB0: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800C0FB4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0FB8: lui         $t1, 0xFFFD
    ctx->r9 = S32(0XFFFD << 16);
    // 0x800C0FBC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800C0FC0: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800C0FC4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800C0FC8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800C0FCC: ori         $t1, $t1, 0xF6FB
    ctx->r9 = ctx->r9 | 0XF6FB;
    // 0x800C0FD0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800C0FD4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C0FD8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C0FDC: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C0FE0: andi        $t5, $v0, 0x3FF
    ctx->r13 = ctx->r2 & 0X3FF;
    // 0x800C0FE4: sll         $t3, $t5, 14
    ctx->r11 = S32(ctx->r13 << 14);
    // 0x800C0FE8: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x800C0FEC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C0FF0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800C0FF4: or          $t6, $t3, $at
    ctx->r14 = ctx->r11 | ctx->r1;
    // 0x800C0FF8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800C0FFC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800C1000: or          $t8, $t6, $t1
    ctx->r24 = ctx->r14 | ctx->r9;
    // 0x800C1004: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C1008: jal         0x8007B820
    // 0x800C100C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C100C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    after_1:
    // 0x800C1010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1018: jr          $ra
    // 0x800C101C: nop

    return;
    // 0x800C101C: nop

;}
RECOMP_FUNC void audspat_reverb_validate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009AB4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80009AB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80009ABC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80009AC0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80009AC4: addiu       $t8, $t8, -0x53A8
    ctx->r24 = ADD32(ctx->r24, -0X53A8);
    // 0x80009AC8: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x80009ACC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80009AD0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80009AD4: lb          $a3, 0xB8($v0)
    ctx->r7 = MEM_B(ctx->r2, 0XB8);
    // 0x80009AD8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80009ADC: bgtz        $a3, L_80009AEC
    if (SIGNED(ctx->r7) > 0) {
        // 0x80009AE0: addiu       $a2, $v0, 0x4
        ctx->r6 = ADD32(ctx->r2, 0X4);
            goto L_80009AEC;
    }
    // 0x80009AE0: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x80009AE4: jr          $ra
    // 0x80009AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80009AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009AEC:
    // 0x80009AEC: blez        $a3, L_80009B70
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80009AF0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80009B70;
    }
    // 0x80009AF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009AF4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009AF8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80009AFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009B00: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80009B04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80009B08: lwc1        $f3, 0x54B0($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X54B0);
    // 0x80009B0C: lwc1        $f2, 0x54B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X54B4);
    // 0x80009B10: lb          $a1, 0xB8($v0)
    ctx->r5 = MEM_B(ctx->r2, 0XB8);
    // 0x80009B14: nop

L_80009B18:
    // 0x80009B18: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80009B1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80009B20: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80009B24: c.eq.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d == ctx->f4.d;
    // 0x80009B28: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80009B2C: bc1t        L_80009B64
    if (c1cs) {
        // 0x80009B30: nop
    
            goto L_80009B64;
    }
    // 0x80009B30: nop

    // 0x80009B34: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80009B38: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80009B3C: c.eq.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d == ctx->f8.d;
    // 0x80009B40: nop

    // 0x80009B44: bc1t        L_80009B64
    if (c1cs) {
        // 0x80009B48: nop
    
            goto L_80009B64;
    }
    // 0x80009B48: nop

    // 0x80009B4C: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80009B50: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80009B54: c.eq.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d == ctx->f16.d;
    // 0x80009B58: nop

    // 0x80009B5C: bc1f        L_80009B68
    if (!c1cs) {
        // 0x80009B60: nop
    
            goto L_80009B68;
    }
    // 0x80009B60: nop

L_80009B64:
    // 0x80009B64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009B68:
    // 0x80009B68: bne         $at, $zero, L_80009B18
    if (ctx->r1 != 0) {
        // 0x80009B6C: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_80009B18;
    }
    // 0x80009B6C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_80009B70:
    // 0x80009B70: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80009B74: jr          $ra
    // 0x80009B78: nop

    return;
    // 0x80009B78: nop

;}
RECOMP_FUNC void scroll_particle_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF964: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF968: addiu       $t0, $t0, 0x33B8
    ctx->r8 = ADD32(ctx->r8, 0X33B8);
    // 0x800AF96C: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x800AF970: sll         $t7, $a0, 6
    ctx->r15 = S32(ctx->r4 << 6);
    // 0x800AF974: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AF978: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800AF97C: sh          $t9, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r25;
    // 0x800AF980: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF984: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AF988: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF98C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x800AF990: addiu       $v1, $v1, 0x32E8
    ctx->r3 = ADD32(ctx->r3, 0X32E8);
    // 0x800AF994: addiu       $a3, $a3, 0x32E8
    ctx->r7 = ADD32(ctx->r7, 0X32E8);
    // 0x800AF998: addiu       $a2, $a2, 0x3298
    ctx->r6 = ADD32(ctx->r6, 0X3298);
L_800AF99C:
    // 0x800AF99C: lh          $t1, 0x0($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X0);
    // 0x800AF9A0: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x800AF9A4: lh          $t5, 0x4($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X4);
    // 0x800AF9A8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800AF9AC: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800AF9B0: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800AF9B4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800AF9B8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800AF9BC: sh          $t2, -0xA($a2)
    MEM_H(-0XA, ctx->r6) = ctx->r10;
    // 0x800AF9C0: sh          $t4, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r12;
    // 0x800AF9C4: sh          $t6, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r14;
    // 0x800AF9C8: bne         $at, $zero, L_800AF99C
    if (ctx->r1 != 0) {
        // 0x800AF9CC: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_800AF99C;
    }
    // 0x800AF9CC: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x800AF9D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AF9D4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF9D8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF9DC: addiu       $v1, $v1, 0x3388
    ctx->r3 = ADD32(ctx->r3, 0X3388);
    // 0x800AF9E0: addiu       $a2, $a2, 0x3388
    ctx->r6 = ADD32(ctx->r6, 0X3388);
    // 0x800AF9E4: addiu       $a0, $a0, 0x3308
    ctx->r4 = ADD32(ctx->r4, 0X3308);
L_800AF9E8:
    // 0x800AF9E8: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x800AF9EC: lh          $t9, 0x2($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2);
    // 0x800AF9F0: lh          $t2, 0x4($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X4);
    // 0x800AF9F4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800AF9F8: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800AF9FC: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
    // 0x800AFA00: sh          $t1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r9;
    // 0x800AFA04: lh          $t1, 0xC($a2)
    ctx->r9 = MEM_H(ctx->r6, 0XC);
    // 0x800AFA08: lh          $t8, 0xA($a2)
    ctx->r24 = MEM_H(ctx->r6, 0XA);
    // 0x800AFA0C: lh          $t4, 0x6($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X6);
    // 0x800AFA10: lh          $t6, 0x8($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X8);
    // 0x800AFA14: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800AFA18: sh          $t3, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r11;
    // 0x800AFA1C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800AFA20: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800AFA24: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800AFA28: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800AFA2C: lh          $t3, 0xE($a2)
    ctx->r11 = MEM_H(ctx->r6, 0XE);
    // 0x800AFA30: sh          $t7, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r15;
    // 0x800AFA34: sh          $t5, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r13;
    // 0x800AFA38: sh          $t9, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r25;
    // 0x800AFA3C: sh          $t2, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r10;
    // 0x800AFA40: lh          $t2, 0x16($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X16);
    // 0x800AFA44: lh          $t9, 0x14($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X14);
    // 0x800AFA48: lh          $t5, 0x10($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X10);
    // 0x800AFA4C: lh          $t7, 0x12($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X12);
    // 0x800AFA50: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800AFA54: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x800AFA58: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800AFA5C: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800AFA60: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800AFA64: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800AFA68: sh          $t8, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r24;
    // 0x800AFA6C: sh          $t6, -0x12($a0)
    MEM_H(-0X12, ctx->r4) = ctx->r14;
    // 0x800AFA70: sh          $t1, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r9;
    // 0x800AFA74: sh          $t3, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r11;
    // 0x800AFA78: sh          $t4, -0x16($a0)
    MEM_H(-0X16, ctx->r4) = ctx->r12;
    // 0x800AFA7C: bne         $a0, $v1, L_800AF9E8
    if (ctx->r4 != ctx->r3) {
        // 0x800AFA80: addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
            goto L_800AF9E8;
    }
    // 0x800AFA80: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x800AFA84: jr          $ra
    // 0x800AFA88: nop

    return;
    // 0x800AFA88: nop

;}
RECOMP_FUNC void race_transition_adventure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A928: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001A92C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A930: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8001A934: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001A938: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001A93C: jal         0x8006F5C8
    // 0x8001A940: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_0;
    // 0x8001A940: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001A944: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001A948: addiu       $s0, $s0, -0x4D32
    ctx->r16 = ADD32(ctx->r16, -0X4D32);
    // 0x8001A94C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x8001A950: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8001A954: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001A958: subu        $t7, $v1, $t6
    ctx->r15 = SUB32(ctx->r3, ctx->r14);
    // 0x8001A95C: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x8001A960: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8001A964: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x8001A968: bgtz        $t8, L_8001A974
    if (SIGNED(ctx->r24) > 0) {
        // 0x8001A96C: nop
    
            goto L_8001A974;
    }
    // 0x8001A96C: nop

    // 0x8001A970: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
L_8001A974:
    // 0x8001A974: bne         $at, $zero, L_8001A998
    if (ctx->r1 != 0) {
        // 0x8001A978: nop
    
            goto L_8001A998;
    }
    // 0x8001A978: nop

    // 0x8001A97C: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8001A980: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001A984: slti        $at, $t1, 0x33
    ctx->r1 = SIGNED(ctx->r9) < 0X33 ? 1 : 0;
    // 0x8001A988: beq         $at, $zero, L_8001A998
    if (ctx->r1 == 0) {
        // 0x8001A98C: nop
    
            goto L_8001A998;
    }
    // 0x8001A98C: nop

    // 0x8001A990: jal         0x800C06F8
    // 0x8001A994: addiu       $a0, $a0, -0x3238
    ctx->r4 = ADD32(ctx->r4, -0X3238);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8001A994: addiu       $a0, $a0, -0x3238
    ctx->r4 = ADD32(ctx->r4, -0X3238);
    after_1:
L_8001A998:
    // 0x8001A998: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001A99C: lb          $v0, -0x4D30($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D30);
    // 0x8001A9A0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8001A9A4: bne         $v0, $zero, L_8001AB6C
    if (ctx->r2 != 0) {
        // 0x8001A9A8: nop
    
            goto L_8001AB6C;
    }
    // 0x8001A9A8: nop

    // 0x8001A9AC: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x8001A9B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A9B4: bne         $t2, $at, L_8001AB6C
    if (ctx->r10 != ctx->r1) {
        // 0x8001A9B8: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_8001AB6C;
    }
    // 0x8001A9B8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001A9BC: addiu       $s1, $s1, -0x4B90
    ctx->r17 = ADD32(ctx->r17, -0X4B90);
    // 0x8001A9C0: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8001A9C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001A9C8: blez        $t3, L_8001AA70
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8001A9CC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001AA70;
    }
    // 0x8001A9CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001A9D0:
    // 0x8001A9D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001A9D4: lw          $t4, -0x4B9C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B9C);
    // 0x8001A9D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001A9DC: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8001A9E0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001A9E4: nop

    // 0x8001A9E8: lw          $a1, 0x64($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X64);
    // 0x8001A9EC: nop

    // 0x8001A9F0: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8001A9F4: sw          $zero, 0x140($a1)
    MEM_W(0X140, ctx->r5) = 0;
    // 0x8001A9F8: beq         $t7, $at, L_8001AA14
    if (ctx->r15 == ctx->r1) {
        // 0x8001A9FC: nop
    
            goto L_8001AA14;
    }
    // 0x8001A9FC: nop

    // 0x8001AA00: lh          $t8, 0x1AC($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X1AC);
    // 0x8001AA04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001AA08: bne         $t8, $at, L_8001AA14
    if (ctx->r24 != ctx->r1) {
        // 0x8001AA0C: nop
    
            goto L_8001AA14;
    }
    // 0x8001AA0C: nop

    // 0x8001AA10: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
L_8001AA14:
    // 0x8001AA14: lw          $a0, 0x178($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X178);
    // 0x8001AA18: nop

    // 0x8001AA1C: beq         $a0, $zero, L_8001AA3C
    if (ctx->r4 == 0) {
        // 0x8001AA20: nop
    
            goto L_8001AA3C;
    }
    // 0x8001AA20: nop

    // 0x8001AA24: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8001AA28: jal         0x8000488C
    // 0x8001AA2C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x8001AA2C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_2:
    // 0x8001AA30: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001AA34: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8001AA38: nop

L_8001AA3C:
    // 0x8001AA3C: lw          $a0, 0x17C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X17C);
    // 0x8001AA40: nop

    // 0x8001AA44: beq         $a0, $zero, L_8001AA5C
    if (ctx->r4 == 0) {
        // 0x8001AA48: nop
    
            goto L_8001AA5C;
    }
    // 0x8001AA48: nop

    // 0x8001AA4C: jal         0x800096F8
    // 0x8001AA50: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    audspat_point_stop(rdram, ctx);
        goto after_3;
    // 0x8001AA50: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x8001AA54: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001AA58: nop

L_8001AA5C:
    // 0x8001AA5C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8001AA60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001AA64: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001AA68: bne         $at, $zero, L_8001A9D0
    if (ctx->r1 != 0) {
        // 0x8001AA6C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8001A9D0;
    }
    // 0x8001AA6C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8001AA70:
    // 0x8001AA70: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8001AA74: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AA78: lw          $v0, -0x4B9C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B9C);
    // 0x8001AA7C: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8001AA80: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8001AA84: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8001AA88: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8001AA8C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001AA90: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8001AA94: lw          $t4, -0x4B9C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B9C);
    // 0x8001AA98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001AA9C: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x8001AAA0: sw          $a2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r6;
    // 0x8001AAA4: lw          $t6, -0x4B9C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B9C);
    // 0x8001AAA8: nop

    // 0x8001AAAC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8001AAB0: jal         0x80006AC8
    // 0x8001AAB4: nop

    racer_sound_free(rdram, ctx);
        goto after_4;
    // 0x8001AAB4: nop

    after_4:
    // 0x8001AAB8: jal         0x800A10B4
    // 0x8001AABC: nop

    hud_audio_init(rdram, ctx);
        goto after_5;
    // 0x8001AABC: nop

    after_5:
    // 0x8001AAC0: jal         0x8003F110
    // 0x8001AAC4: nop

    reset_rocket_sound_timer(rdram, ctx);
        goto after_6;
    // 0x8001AAC4: nop

    after_6:
    // 0x8001AAC8: jal         0x800049D8
    // 0x8001AACC: nop

    sndp_stop_all_looped(rdram, ctx);
        goto after_7;
    // 0x8001AACC: nop

    after_7:
    // 0x8001AAD0: jal         0x8009F1C4
    // 0x8001AAD4: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_8;
    // 0x8001AAD4: nop

    after_8:
    // 0x8001AAD8: beq         $v0, $zero, L_8001AB4C
    if (ctx->r2 == 0) {
        // 0x8001AADC: nop
    
            goto L_8001AB4C;
    }
    // 0x8001AADC: nop

    // 0x8001AAE0: jal         0x80024A20
    // 0x8001AAE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_scene_viewport_num(rdram, ctx);
        goto after_9;
    // 0x8001AAE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8001AAE8: jal         0x8006676C
    // 0x8001AAEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_layout(rdram, ctx);
        goto after_10;
    // 0x8001AAEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8001AAF0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001AAF4: lw          $t7, -0x4B9C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B9C);
    // 0x8001AAF8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AAFC: addiu       $a3, $a3, -0x4B94
    ctx->r7 = ADD32(ctx->r7, -0X4B94);
    // 0x8001AB00: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8001AB04: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8001AB08: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8001AB0C: lw          $a1, 0x64($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X64);
    // 0x8001AB10: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8001AB14: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8001AB18: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8001AB1C: addiu       $t0, $t0, -0x334C
    ctx->r8 = ADD32(ctx->r8, -0X334C);
    // 0x8001AB20: sw          $a2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r6;
    // 0x8001AB24: lb          $t9, 0x0($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X0);
    // 0x8001AB28: nop

    // 0x8001AB2C: beq         $t9, $zero, L_8001AB4C
    if (ctx->r25 == 0) {
        // 0x8001AB30: nop
    
            goto L_8001AB4C;
    }
    // 0x8001AB30: nop

    // 0x8001AB34: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8001AB38: jal         0x8006F5D8
    // 0x8001AB3C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    swap_lead_player(rdram, ctx);
        goto after_11;
    // 0x8001AB3C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_11:
    // 0x8001AB40: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8001AB44: nop

    // 0x8001AB48: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_8001AB4C:
    // 0x8001AB4C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8001AB50: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AB54: addiu       $a3, $a3, -0x4D2F
    ctx->r7 = ADD32(ctx->r7, -0X4D2F);
    // 0x8001AB58: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001AB5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AB60: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
    // 0x8001AB64: sb          $t2, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = ctx->r10;
    // 0x8001AB68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001AB6C:
    // 0x8001AB6C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001AB70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001AB74: bne         $v0, $at, L_8001ACCC
    if (ctx->r2 != ctx->r1) {
        // 0x8001AB78: addiu       $s1, $s1, -0x4B90
        ctx->r17 = ADD32(ctx->r17, -0X4B90);
            goto L_8001ACCC;
    }
    // 0x8001AB78: addiu       $s1, $s1, -0x4B90
    ctx->r17 = ADD32(ctx->r17, -0X4B90);
    // 0x8001AB7C: jal         0x800AB730
    // 0x8001AB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_visibility(rdram, ctx);
        goto after_12;
    // 0x8001AB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x8001AB84: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AB88: addiu       $a3, $a3, -0x4D2F
    ctx->r7 = ADD32(ctx->r7, -0X4D2F);
    // 0x8001AB8C: lb          $t3, 0x0($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X0);
    // 0x8001AB90: nop

    // 0x8001AB94: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8001AB98: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
    // 0x8001AB9C: lb          $a2, 0x0($a3)
    ctx->r6 = MEM_B(ctx->r7, 0X0);
    // 0x8001ABA0: nop

    // 0x8001ABA4: blez        $a2, L_8001ACC0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001ABA8: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8001ACC0;
    }
    // 0x8001ABA8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001ABAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8001ABB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001ABB4: blez        $a0, L_8001AC0C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001ABB8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001AC0C;
    }
    // 0x8001ABB8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001ABBC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001ABC0: lw          $t5, -0x4B9C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4B9C);
    // 0x8001ABC4: addiu       $a1, $a1, -0x4B98
    ctx->r5 = ADD32(ctx->r5, -0X4B98);
    // 0x8001ABC8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8001ABCC: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8001ABD0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8001ABD4: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8001ABD8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001ABDC: nop

    // 0x8001ABE0: beq         $t8, $v1, L_8001AC0C
    if (ctx->r24 == ctx->r3) {
        // 0x8001ABE4: nop
    
            goto L_8001AC0C;
    }
    // 0x8001ABE4: nop

L_8001ABE8:
    // 0x8001ABE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001ABEC: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001ABF0: beq         $at, $zero, L_8001AC0C
    if (ctx->r1 == 0) {
        // 0x8001ABF4: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_8001AC0C;
    }
    // 0x8001ABF4: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8001ABF8: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x8001ABFC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001AC00: nop

    // 0x8001AC04: bne         $t2, $v1, L_8001ABE8
    if (ctx->r10 != ctx->r3) {
        // 0x8001AC08: nop
    
            goto L_8001ABE8;
    }
    // 0x8001AC08: nop

L_8001AC0C:
    // 0x8001AC0C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001AC10: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001AC14: beq         $at, $zero, L_8001AC64
    if (ctx->r1 == 0) {
        // 0x8001AC18: addiu       $a1, $a1, -0x4B98
        ctx->r5 = ADD32(ctx->r5, -0X4B98);
            goto L_8001AC64;
    }
    // 0x8001AC18: addiu       $a1, $a1, -0x4B98
    ctx->r5 = ADD32(ctx->r5, -0X4B98);
    // 0x8001AC1C: addiu       $t3, $a0, -0x1
    ctx->r11 = ADD32(ctx->r4, -0X1);
    // 0x8001AC20: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001AC24: beq         $at, $zero, L_8001AC64
    if (ctx->r1 == 0) {
        // 0x8001AC28: sll         $v1, $s0, 2
        ctx->r3 = S32(ctx->r16 << 2);
            goto L_8001AC64;
    }
    // 0x8001AC28: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
L_8001AC2C:
    // 0x8001AC2C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8001AC30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001AC34: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x8001AC38: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8001AC3C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001AC40: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8001AC44: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001AC48: nop

    // 0x8001AC4C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001AC50: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001AC54: bne         $at, $zero, L_8001AC2C
    if (ctx->r1 != 0) {
        // 0x8001AC58: nop
    
            goto L_8001AC2C;
    }
    // 0x8001AC58: nop

    // 0x8001AC5C: lb          $a2, 0x0($a3)
    ctx->r6 = MEM_B(ctx->r7, 0X0);
    // 0x8001AC60: nop

L_8001AC64:
    // 0x8001AC64: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001AC68: lw          $t8, -0x4B9C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4B9C);
    // 0x8001AC6C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8001AC70: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8001AC74: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8001AC78: jal         0x8000FFB8
    // 0x8001AC7C: nop

    free_object(rdram, ctx);
        goto after_13;
    // 0x8001AC7C: nop

    after_13:
    // 0x8001AC80: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001AC84: addiu       $a3, $a3, -0x4D2F
    ctx->r7 = ADD32(ctx->r7, -0X4D2F);
    // 0x8001AC88: lb          $t3, 0x0($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X0);
    // 0x8001AC8C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001AC90: lw          $t2, -0x4B9C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4B9C);
    // 0x8001AC94: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001AC98: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8001AC9C: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x8001ACA0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001ACA4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001ACA8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001ACAC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8001ACB0: lb          $v0, -0x4D30($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D30);
    // 0x8001ACB4: b           L_8001ACD0
    // 0x8001ACB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_8001ACD0;
    // 0x8001ACB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001ACBC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
L_8001ACC0:
    // 0x8001ACC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001ACC4: sb          $t8, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = ctx->r24;
    // 0x8001ACC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8001ACCC:
    // 0x8001ACCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8001ACD0:
    // 0x8001ACD0: bne         $v0, $at, L_8001AD2C
    if (ctx->r2 != ctx->r1) {
        // 0x8001ACD4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8001AD2C;
    }
    // 0x8001ACD4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8001ACD8: lw          $t9, -0x4B9C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4B9C);
    // 0x8001ACDC: nop

    // 0x8001ACE0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8001ACE4: nop

    // 0x8001ACE8: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8001ACEC: jal         0x80023104
    // 0x8001ACF0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_800230D0(rdram, ctx);
        goto after_14;
    // 0x8001ACF0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_14:
    // 0x8001ACF4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8001ACF8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8001ACFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AD00: sb          $zero, 0x1D8($a1)
    MEM_B(0X1D8, ctx->r5) = 0;
    // 0x8001AD04: sb          $t1, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = ctx->r9;
    // 0x8001AD08: jal         0x8001E490
    // 0x8001AD0C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8001E45C(rdram, ctx);
        goto after_15;
    // 0x8001AD0C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_15:
    // 0x8001AD10: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001AD14: addiu       $s0, $s0, -0x4CB8
    ctx->r16 = ADD32(ctx->r16, -0X4CB8);
    // 0x8001AD18: jal         0x8001E970
    // 0x8001AD1C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    func_8001E93C(rdram, ctx);
        goto after_16;
    // 0x8001AD1C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    after_16:
    // 0x8001AD20: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AD24: lb          $v0, -0x4D30($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D30);
    // 0x8001AD28: nop

L_8001AD2C:
    // 0x8001AD2C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8001AD30: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001AD34: bne         $v0, $at, L_8001AD68
    if (ctx->r2 != ctx->r1) {
        // 0x8001AD38: addiu       $s0, $s0, -0x4CB8
        ctx->r16 = ADD32(ctx->r16, -0X4CB8);
            goto L_8001AD68;
    }
    // 0x8001AD38: addiu       $s0, $s0, -0x4CB8
    ctx->r16 = ADD32(ctx->r16, -0X4CB8);
    // 0x8001AD3C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001AD40: jal         0x800C06F8
    // 0x8001AD44: addiu       $a0, $a0, -0x3230
    ctx->r4 = ADD32(ctx->r4, -0X3230);
    transition_begin(rdram, ctx);
        goto after_17;
    // 0x8001AD44: addiu       $a0, $a0, -0x3230
    ctx->r4 = ADD32(ctx->r4, -0X3230);
    after_17:
    // 0x8001AD48: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8001AD4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AD50: sb          $t3, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = ctx->r11;
    // 0x8001AD54: jal         0x80028FE0
    // 0x8001AD58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_anti_aliasing(rdram, ctx);
        goto after_18;
    // 0x8001AD58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_18:
    // 0x8001AD5C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AD60: lb          $v0, -0x4D30($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D30);
    // 0x8001AD64: nop

L_8001AD68:
    // 0x8001AD68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001AD6C: bne         $v0, $at, L_8001AE68
    if (ctx->r2 != ctx->r1) {
        // 0x8001AD70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001AE68;
    }
    // 0x8001AD70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AD74: jal         0x80028FE0
    // 0x8001AD78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_anti_aliasing(rdram, ctx);
        goto after_19;
    // 0x8001AD78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x8001AD7C: jal         0x8005A41C
    // 0x8001AD80: nop

    disable_racer_input(rdram, ctx);
        goto after_20;
    // 0x8001AD80: nop

    after_20:
    // 0x8001AD84: jal         0x8006BFD8
    // 0x8001AD88: nop

    level_type(rdram, ctx);
        goto after_21;
    // 0x8001AD88: nop

    after_21:
    // 0x8001AD8C: andi        $t2, $v0, 0x40
    ctx->r10 = ctx->r2 & 0X40;
    // 0x8001AD90: bne         $t2, $zero, L_8001ADE0
    if (ctx->r10 != 0) {
        // 0x8001AD94: lui         $t4, 0x8000
        ctx->r12 = S32(0X8000 << 16);
            goto L_8001ADE0;
    }
    // 0x8001AD94: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8001AD98: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8001AD9C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8001ADA0: bne         $t4, $zero, L_8001ADB0
    if (ctx->r12 != 0) {
        // 0x8001ADA4: addiu       $v0, $zero, 0x21C
        ctx->r2 = ADD32(0, 0X21C);
            goto L_8001ADB0;
    }
    // 0x8001ADA4: addiu       $v0, $zero, 0x21C
    ctx->r2 = ADD32(0, 0X21C);
    // 0x8001ADA8: b           L_8001ADB0
    // 0x8001ADAC: addiu       $v0, $zero, 0x19F
    ctx->r2 = ADD32(0, 0X19F);
        goto L_8001ADB0;
    // 0x8001ADAC: addiu       $v0, $zero, 0x19F
    ctx->r2 = ADD32(0, 0X19F);
L_8001ADB0:
    // 0x8001ADB0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8001ADB4: nop

    // 0x8001ADB8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8001ADBC: sltu        $at, $t7, $v0
    ctx->r1 = ctx->r15 < ctx->r2 ? 1 : 0;
    // 0x8001ADC0: beq         $at, $zero, L_8001ADD8
    if (ctx->r1 == 0) {
        // 0x8001ADC4: sw          $t7, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r15;
            goto L_8001ADD8;
    }
    // 0x8001ADC4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8001ADC8: jal         0x800AB6F0
    // 0x8001ADCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    minimap_fade(rdram, ctx);
        goto after_22;
    // 0x8001ADCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_22:
    // 0x8001ADD0: b           L_8001ADE0
    // 0x8001ADD4: nop

        goto L_8001ADE0;
    // 0x8001ADD4: nop

L_8001ADD8:
    // 0x8001ADD8: jal         0x800AB730
    // 0x8001ADDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    hud_visibility(rdram, ctx);
        goto after_23;
    // 0x8001ADDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_23:
L_8001ADE0:
    // 0x8001ADE0: jal         0x8006A794
    // 0x8001ADE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_24;
    // 0x8001ADE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
    // 0x8001ADE8: jal         0x8006ECD0
    // 0x8001ADEC: andi        $s0, $v0, 0x8000
    ctx->r16 = ctx->r2 & 0X8000;
    get_settings(rdram, ctx);
        goto after_25;
    // 0x8001ADEC: andi        $s0, $v0, 0x8000
    ctx->r16 = ctx->r2 & 0X8000;
    after_25:
    // 0x8001ADF0: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x8001ADF4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8001ADF8: sll         $t1, $t9, 13
    ctx->r9 = S32(ctx->r25 << 13);
    // 0x8001ADFC: bltz        $t1, L_8001AE08
    if (SIGNED(ctx->r9) < 0) {
        // 0x8001AE00: nop
    
            goto L_8001AE08;
    }
    // 0x8001AE00: nop

    // 0x8001AE04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001AE08:
    // 0x8001AE08: jal         0x800214F8
    // 0x8001AE0C: nop

    func_800214C4(rdram, ctx);
        goto after_26;
    // 0x8001AE0C: nop

    after_26:
    // 0x8001AE10: bne         $v0, $zero, L_8001AE30
    if (ctx->r2 != 0) {
        // 0x8001AE14: nop
    
            goto L_8001AE30;
    }
    // 0x8001AE14: nop

    // 0x8001AE18: beq         $s0, $zero, L_8001AE68
    if (ctx->r16 == 0) {
        // 0x8001AE1C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001AE68;
    }
    // 0x8001AE1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AE20: jal         0x800C06AC
    // 0x8001AE24: nop

    check_fadeout_transition(rdram, ctx);
        goto after_27;
    // 0x8001AE24: nop

    after_27:
    // 0x8001AE28: bne         $v0, $zero, L_8001AE68
    if (ctx->r2 != 0) {
        // 0x8001AE2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001AE68;
    }
    // 0x8001AE2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001AE30:
    // 0x8001AE30: beq         $s0, $zero, L_8001AE40
    if (ctx->r16 == 0) {
        // 0x8001AE34: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8001AE40;
    }
    // 0x8001AE34: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8001AE38: jal         0x800C06F8
    // 0x8001AE3C: addiu       $a0, $a0, -0x3398
    ctx->r4 = ADD32(ctx->r4, -0X3398);
    transition_begin(rdram, ctx);
        goto after_28;
    // 0x8001AE3C: addiu       $a0, $a0, -0x3398
    ctx->r4 = ADD32(ctx->r4, -0X3398);
    after_28:
L_8001AE40:
    // 0x8001AE40: jal         0x8006F380
    // 0x8001AE44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    level_transition_begin(rdram, ctx);
        goto after_29;
    // 0x8001AE44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_29:
    // 0x8001AE48: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001AE4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001AE50: sb          $t3, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = ctx->r11;
    // 0x8001AE54: lw          $t2, 0x10($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X10);
    // 0x8001AE58: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8001AE5C: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x8001AE60: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
    // 0x8001AE64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001AE68:
    // 0x8001AE68: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001AE6C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001AE70: jr          $ra
    // 0x8001AE74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001AE74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void render_3d_misc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011AD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80011AD4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80011AD8: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
    // 0x80011ADC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80011AE0: beq         $v0, $at, L_80011BB4
    if (ctx->r2 == ctx->r1) {
        // 0x80011AE4: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80011BB4;
    }
    // 0x80011AE4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80011AE8: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80011AEC: beq         $v0, $at, L_80011B10
    if (ctx->r2 == ctx->r1) {
        // 0x80011AF0: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80011B10;
    }
    // 0x80011AF0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80011AF4: beq         $v0, $at, L_80011B58
    if (ctx->r2 == ctx->r1) {
        // 0x80011AF8: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80011B58;
    }
    // 0x80011AF8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80011AFC: addiu       $at, $zero, 0x59
    ctx->r1 = ADD32(0, 0X59);
    // 0x80011B00: beq         $v0, $at, L_80011C38
    if (ctx->r2 == ctx->r1) {
        // 0x80011B04: nop
    
            goto L_80011C38;
    }
    // 0x80011B04: nop

    // 0x80011B08: b           L_80011C88
    // 0x80011B0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011B0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011B10:
    // 0x80011B10: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80011B14: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80011B18: bltz        $t6, L_80011C84
    if (SIGNED(ctx->r14) < 0) {
        // 0x80011B1C: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80011C84;
    }
    // 0x80011B1C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80011B20: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80011B24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011B28: lw          $a1, 0x20($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X20);
    // 0x80011B2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80011B30: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x80011B34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80011B38: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x80011B3C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80011B40: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80011B44: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80011B48: jal         0x80011960
    // 0x80011B4C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    render_misc_model(rdram, ctx);
        goto after_0;
    // 0x80011B4C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80011B50: b           L_80011C88
    // 0x80011B54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011B54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011B58:
    // 0x80011B58: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80011B5C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80011B60: lbu         $t0, 0xFC($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0XFC);
    // 0x80011B64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80011B68: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80011B6C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80011B70: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80011B74: lw          $t4, 0xF8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XF8);
    // 0x80011B78: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80011B7C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80011B80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011B84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011B88: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80011B8C: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80011B90: addu        $a1, $a3, $t2
    ctx->r5 = ADD32(ctx->r7, ctx->r10);
    // 0x80011B94: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    // 0x80011B98: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80011B9C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80011BA0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80011BA4: jal         0x80011960
    // 0x80011BA8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    render_misc_model(rdram, ctx);
        goto after_1;
    // 0x80011BA8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80011BAC: b           L_80011C88
    // 0x80011BB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011BB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011BB4:
    // 0x80011BB4: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80011BB8: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80011BBC: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x80011BC0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80011BC4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80011BC8: bgez        $t7, L_80011BE0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80011BCC: cvt.s.w     $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80011BE0;
    }
    // 0x80011BCC: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80011BD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80011BD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80011BD8: nop

    // 0x80011BDC: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_80011BE0:
    // 0x80011BE0: lbu         $t8, 0xFC($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XFC);
    // 0x80011BE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011BE8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80011BEC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80011BF0: lwc1        $f16, 0x5AE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5AE0);
    // 0x80011BF4: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80011BF8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80011BFC: lw          $t2, 0xF8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0XF8);
    // 0x80011C00: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80011C04: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80011C08: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80011C0C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80011C10: addu        $a1, $a3, $t0
    ctx->r5 = ADD32(ctx->r7, ctx->r8);
    // 0x80011C14: addiu       $t3, $zero, 0x1A
    ctx->r11 = ADD32(0, 0X1A);
    // 0x80011C18: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80011C1C: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    // 0x80011C20: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80011C24: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80011C28: jal         0x80011960
    // 0x80011C2C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    render_misc_model(rdram, ctx);
        goto after_2;
    // 0x80011C2C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_2:
    // 0x80011C30: b           L_80011C88
    // 0x80011C34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80011C88;
    // 0x80011C34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011C38:
    // 0x80011C38: lw          $t4, 0x78($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X78);
    // 0x80011C3C: nop

    // 0x80011C40: beq         $t4, $zero, L_80011C88
    if (ctx->r12 == 0) {
        // 0x80011C44: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80011C88;
    }
    // 0x80011C44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80011C48: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80011C4C: nop

    // 0x80011C50: lbu         $t5, 0x70($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X70);
    // 0x80011C54: nop

    // 0x80011C58: bgtz        $t5, L_80011C7C
    if (SIGNED(ctx->r13) > 0) {
        // 0x80011C5C: nop
    
            goto L_80011C7C;
    }
    // 0x80011C5C: nop

    // 0x80011C60: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80011C64: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80011C68: nop

    // 0x80011C6C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80011C70: nop

    // 0x80011C74: bc1f        L_80011C88
    if (!c1cs) {
        // 0x80011C78: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80011C88;
    }
    // 0x80011C78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011C7C:
    // 0x80011C7C: jal         0x800135B8
    // 0x80011C80: nop

    func_800135B8(rdram, ctx);
        goto after_3;
    // 0x80011C80: nop

    after_3:
L_80011C84:
    // 0x80011C84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80011C88:
    // 0x80011C88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80011C8C: jr          $ra
    // 0x80011C90: nop

    return;
    // 0x80011C90: nop

;}
RECOMP_FUNC void func_8004CC20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CC60: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8004CC64: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004CC68: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8004CC6C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8004CC70: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x8004CC74: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x8004CC78: sb          $zero, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = 0;
    // 0x8004CC7C: lw          $a1, 0x17C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X17C);
    // 0x8004CC80: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8004CC84: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8004CC88: sh          $zero, 0x18E($a3)
    MEM_H(0X18E, ctx->r7) = 0;
    // 0x8004CC8C: beq         $a1, $zero, L_8004CCA0
    if (ctx->r5 == 0) {
        // 0x8004CC90: sb          $zero, 0x189($a3)
        MEM_B(0X189, ctx->r7) = 0;
            goto L_8004CCA0;
    }
    // 0x8004CC90: sb          $zero, 0x189($a3)
    MEM_B(0X189, ctx->r7) = 0;
    // 0x8004CC94: jal         0x800096F8
    // 0x8004CC98: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    audspat_point_stop(rdram, ctx);
        goto after_0;
    // 0x8004CC98: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8004CC9C: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_8004CCA0:
    // 0x8004CCA0: lb          $v0, 0x1D3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004CCA4: nop

    // 0x8004CCA8: bne         $v0, $zero, L_8004CCC8
    if (ctx->r2 != 0) {
        // 0x8004CCAC: addiu       $t6, $zero, 0x8
        ctx->r14 = ADD32(0, 0X8);
            goto L_8004CCC8;
    }
    // 0x8004CCAC: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8004CCB0: sb          $t6, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r14;
    // 0x8004CCB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004CCB8: jal         0x80057088
    // 0x8004CCBC: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    racer_play_sound(rdram, ctx);
        goto after_1;
    // 0x8004CCBC: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    after_1:
    // 0x8004CCC0: lb          $v0, 0x1D3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004CCC4: nop

L_8004CCC8:
    // 0x8004CCC8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8004CCCC: beq         $at, $zero, L_8004CCDC
    if (ctx->r1 == 0) {
        // 0x8004CCD0: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8004CCDC;
    }
    // 0x8004CCD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8004CCD4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8004CCD8: sb          $t7, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r15;
L_8004CCDC:
    // 0x8004CCDC: jal         0x8002AD08
    // 0x8004CCE0: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
    set_collision_mode(rdram, ctx);
        goto after_2;
    // 0x8004CCE0: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
    after_2:
    // 0x8004CCE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004CCE8: sh          $zero, -0x2530($at)
    MEM_H(-0X2530, ctx->r1) = 0;
    // 0x8004CCEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004CCF0: sw          $zero, -0x252C($at)
    MEM_W(-0X252C, ctx->r1) = 0;
    // 0x8004CCF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004CCF8: sw          $zero, -0x2528($at)
    MEM_W(-0X2528, ctx->r1) = 0;
    // 0x8004CCFC: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004CD00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004CD04: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
    // 0x8004CD08: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004CD0C: lw          $t8, -0x254C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X254C);
    // 0x8004CD10: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x8004CD14: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004CD18: lw          $t0, 0xD8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD8);
    // 0x8004CD1C: swc1        $f8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f8.u32l;
    // 0x8004CD20: lb          $a0, 0x1E1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E1);
    // 0x8004CD24: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004CD28: subu        $v1, $t8, $a0
    ctx->r3 = SUB32(ctx->r24, ctx->r4);
    // 0x8004CD2C: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004CD30: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004CD34: mflo        $v0
    ctx->r2 = lo;
    // 0x8004CD38: sra         $t9, $v0, 4
    ctx->r25 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8004CD3C: beq         $v1, $zero, L_8004CD64
    if (ctx->r3 == 0) {
        // 0x8004CD40: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_8004CD64;
    }
    // 0x8004CD40: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8004CD44: bne         $t9, $zero, L_8004CD68
    if (ctx->r25 != 0) {
        // 0x8004CD48: addu        $t3, $a0, $a2
        ctx->r11 = ADD32(ctx->r4, ctx->r6);
            goto L_8004CD68;
    }
    // 0x8004CD48: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
    // 0x8004CD4C: blez        $v1, L_8004CD58
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004CD50: nop
    
            goto L_8004CD58;
    }
    // 0x8004CD50: nop

    // 0x8004CD54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8004CD58:
    // 0x8004CD58: bgez        $v1, L_8004CD68
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004CD5C: addu        $t3, $a0, $a2
        ctx->r11 = ADD32(ctx->r4, ctx->r6);
            goto L_8004CD68;
    }
    // 0x8004CD5C: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
    // 0x8004CD60: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004CD64:
    // 0x8004CD64: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
L_8004CD68:
    // 0x8004CD68: sb          $t3, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = ctx->r11;
    // 0x8004CD6C: lw          $t4, -0x2548($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2548);
    // 0x8004CD70: lb          $a3, 0x1E8($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1E8);
    // 0x8004CD74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004CD78: subu        $v1, $t4, $a3
    ctx->r3 = SUB32(ctx->r12, ctx->r7);
    // 0x8004CD7C: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004CD80: mflo        $v0
    ctx->r2 = lo;
    // 0x8004CD84: sra         $t5, $v0, 4
    ctx->r13 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8004CD88: beq         $v1, $zero, L_8004CDB0
    if (ctx->r3 == 0) {
        // 0x8004CD8C: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_8004CDB0;
    }
    // 0x8004CD8C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8004CD90: bne         $t5, $zero, L_8004CDB4
    if (ctx->r13 != 0) {
        // 0x8004CD94: addu        $t6, $a3, $a2
        ctx->r14 = ADD32(ctx->r7, ctx->r6);
            goto L_8004CDB4;
    }
    // 0x8004CD94: addu        $t6, $a3, $a2
    ctx->r14 = ADD32(ctx->r7, ctx->r6);
    // 0x8004CD98: blez        $v1, L_8004CDA4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004CD9C: nop
    
            goto L_8004CDA4;
    }
    // 0x8004CD9C: nop

    // 0x8004CDA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8004CDA4:
    // 0x8004CDA4: bgez        $v1, L_8004CDB4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004CDA8: addu        $t6, $a3, $a2
        ctx->r14 = ADD32(ctx->r7, ctx->r6);
            goto L_8004CDB4;
    }
    // 0x8004CDA8: addu        $t6, $a3, $a2
    ctx->r14 = ADD32(ctx->r7, ctx->r6);
    // 0x8004CDAC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8004CDB0:
    // 0x8004CDB0: addu        $t6, $a3, $a2
    ctx->r14 = ADD32(ctx->r7, ctx->r6);
L_8004CDB4:
    // 0x8004CDB4: sb          $t6, 0x1E8($s0)
    MEM_B(0X1E8, ctx->r16) = ctx->r14;
    // 0x8004CDB8: sh          $zero, 0x160($s0)
    MEM_H(0X160, ctx->r16) = 0;
    // 0x8004CDBC: sh          $zero, 0x162($s0)
    MEM_H(0X162, ctx->r16) = 0;
    // 0x8004CDC0: jal         0x8005762C
    // 0x8004CDC4: sh          $zero, 0x164($s0)
    MEM_H(0X164, ctx->r16) = 0;
    func_800575EC(rdram, ctx);
        goto after_3;
    // 0x8004CDC4: sh          $zero, 0x164($s0)
    MEM_H(0X164, ctx->r16) = 0;
    after_3:
    // 0x8004CDC8: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8004CDCC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004CDD0: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x8004CDD4: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8004CDD8: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x8004CDDC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004CDE0: sh          $t8, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r24;
    // 0x8004CDE4: lh          $t9, 0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4);
    // 0x8004CDE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004CDEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004CDF0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8004CDF4: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8004CDF8: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x8004CDFC: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x8004CE00: sh          $t9, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r25;
    // 0x8004CE04: jal         0x8006FE70
    // 0x8004CE08: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_4;
    // 0x8004CE08: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    after_4:
    // 0x8004CE0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004CE10: addiu       $t3, $s0, 0x44
    ctx->r11 = ADD32(ctx->r16, 0X44);
    // 0x8004CE14: addiu       $t4, $s0, 0x48
    ctx->r12 = ADD32(ctx->r16, 0X48);
    // 0x8004CE18: addiu       $t5, $s0, 0x4C
    ctx->r13 = ADD32(ctx->r16, 0X4C);
    // 0x8004CE1C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004CE20: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8004CE24: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8004CE28: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8004CE2C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8004CE30: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8004CE34: jal         0x8006F88C
    // 0x8004CE38: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_5;
    // 0x8004CE38: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x8004CE3C: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8004CE40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004CE44: sw          $t6, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r14;
    // 0x8004CE48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004CE4C: jal         0x80053604
    // 0x8004CE50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800535C4(rdram, ctx);
        goto after_6;
    // 0x8004CE50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8004CE54: jal         0x800536A4
    // 0x8004CE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    handle_car_velocity_control(rdram, ctx);
        goto after_7;
    // 0x8004CE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8004CE5C: lw          $a2, 0xDC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XDC);
    // 0x8004CE60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004CE64: jal         0x80053790
    // 0x8004CE68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80053750(rdram, ctx);
        goto after_8;
    // 0x8004CE68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x8004CE6C: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8004CE70: lb          $v0, 0x1E1($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E1);
    // 0x8004CE74: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x8004CE78: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8004CE7C: subu        $v0, $t8, $t7
    ctx->r2 = SUB32(ctx->r24, ctx->r15);
    // 0x8004CE80: bgez        $v0, L_8004CE90
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004CE84: slti        $at, $v0, 0x4A
        ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
            goto L_8004CE90;
    }
    // 0x8004CE84: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // 0x8004CE88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004CE8C: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
L_8004CE90:
    // 0x8004CE90: bne         $at, $zero, L_8004CE9C
    if (ctx->r1 != 0) {
        // 0x8004CE94: nop
    
            goto L_8004CE9C;
    }
    // 0x8004CE94: nop

    // 0x8004CE98: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
L_8004CE9C:
    // 0x8004CE9C: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8004CEA0: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8004CEA4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8004CEA8: beq         $t0, $t9, L_8004CEBC
    if (ctx->r8 == ctx->r25) {
        // 0x8004CEAC: addiu       $a3, $zero, 0xA
        ctx->r7 = ADD32(0, 0XA);
            goto L_8004CEBC;
    }
    // 0x8004CEAC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8004CEB0: lb          $a3, 0x1E1($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1E1);
    // 0x8004CEB4: b           L_8004D00C
    // 0x8004CEB8: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
        goto L_8004D00C;
    // 0x8004CEB8: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
L_8004CEBC:
    // 0x8004CEBC: lw          $a1, 0x158($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X158);
    // 0x8004CEC0: nop

    // 0x8004CEC4: beq         $a1, $zero, L_8004D008
    if (ctx->r5 == 0) {
        // 0x8004CEC8: nop
    
            goto L_8004D008;
    }
    // 0x8004CEC8: nop

    // 0x8004CECC: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8004CED0: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004CED4: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8004CED8: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8004CEDC: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004CEE0: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8004CEE4: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004CEE8: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8004CEEC: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004CEF0: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004CEF4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004CEF8: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    // 0x8004CEFC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8004CF00: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8004CF04: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8004CF08: jal         0x800CA030
    // 0x8004CF0C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x8004CF0C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_9:
    // 0x8004CF10: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x8004CF14: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004CF18: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004CF1C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8004CF20: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8004CF24: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8004CF28: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x8004CF2C: bc1f        L_8004CF98
    if (!c1cs) {
        // 0x8004CF30: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8004CF98;
    }
    // 0x8004CF30: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8004CF34: lw          $a2, 0x64($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X64);
    // 0x8004CF38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004CF3C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
L_8004CF40:
    // 0x8004CF40: addu        $v1, $a2, $t3
    ctx->r3 = ADD32(ctx->r6, ctx->r11);
    // 0x8004CF44: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004CF48: nop

    // 0x8004CF4C: beq         $a0, $zero, L_8004CF74
    if (ctx->r4 == 0) {
        // 0x8004CF50: nop
    
            goto L_8004CF74;
    }
    // 0x8004CF50: nop

    // 0x8004CF54: lw          $t4, 0x15C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X15C);
    // 0x8004CF58: nop

    // 0x8004CF5C: beq         $t4, $a0, L_8004CF78
    if (ctx->r12 == ctx->r4) {
        // 0x8004CF60: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8004CF78;
    }
    // 0x8004CF60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004CF64: sw          $a1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r5;
    // 0x8004CF68: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8004CF6C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004CF70: sw          $t5, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->r13;
L_8004CF74:
    // 0x8004CF74: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8004CF78:
    // 0x8004CF78: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8004CF7C: bne         $at, $zero, L_8004CF40
    if (ctx->r1 != 0) {
        // 0x8004CF80: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_8004CF40;
    }
    // 0x8004CF80: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8004CF84: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004CF88: beq         $v0, $at, L_8004D008
    if (ctx->r2 == ctx->r1) {
        // 0x8004CF8C: nop
    
            goto L_8004D008;
    }
    // 0x8004CF8C: nop

    // 0x8004CF90: b           L_8004D008
    // 0x8004CF94: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
        goto L_8004D008;
    // 0x8004CF94: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
L_8004CF98:
    // 0x8004CF98: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004CF9C: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004CFA0: lwc1        $f14, 0x58($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004CFA4: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8004CFA8: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004CFAC: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8004CFB0: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8004CFB4: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8004CFB8: nop

    // 0x8004CFBC: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8004CFC0: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8004CFC4: mul.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8004CFC8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8004CFCC: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004CFD0: add.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8004CFD4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8004CFD8: nop

    // 0x8004CFDC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8004CFE0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004CFE4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004CFE8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004CFEC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8004CFF0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8004CFF4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8004CFF8: div         $zero, $a3, $at
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r1)));
    // 0x8004CFFC: mflo        $a3
    ctx->r7 = lo;
    // 0x8004D000: nop

    // 0x8004D004: nop

L_8004D008:
    // 0x8004D008: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
L_8004D00C:
    // 0x8004D00C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004D010: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004D014: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8004D018: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004D01C: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8004D020: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004D024: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8004D028: sb          $zero, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = 0;
    // 0x8004D02C: div.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8004D030: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D034: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D038: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004D03C: addiu       $t1, $t1, -0x2524
    ctx->r9 = ADD32(ctx->r9, -0X2524);
    // 0x8004D040: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004D044: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004D048: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004D04C: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8004D050: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D054: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x8004D058: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004D05C: nop

    // 0x8004D060: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004D064: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8004D068: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x8004D06C: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004D070: nop

    // 0x8004D074: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8004D078: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8004D07C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8004D080: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8004D084: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
    // 0x8004D088: bne         $t0, $t8, L_8004D098
    if (ctx->r8 != ctx->r24) {
        // 0x8004D08C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004D098;
    }
    // 0x8004D08C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004D090: lwc1        $f2, 0x6B10($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B10);
    // 0x8004D094: nop

L_8004D098:
    // 0x8004D098: lh          $t9, 0x19A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X19A);
    // 0x8004D09C: nop

    // 0x8004D0A0: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8004D0A4: sh          $t3, 0x19A($s0)
    MEM_H(0X19A, ctx->r16) = ctx->r11;
    // 0x8004D0A8: lh          $t4, 0x19A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X19A);
    // 0x8004D0AC: nop

    // 0x8004D0B0: slti        $at, $t4, 0x259
    ctx->r1 = SIGNED(ctx->r12) < 0X259 ? 1 : 0;
    // 0x8004D0B4: bne         $at, $zero, L_8004D0E0
    if (ctx->r1 != 0) {
        // 0x8004D0B8: nop
    
            goto L_8004D0E0;
    }
    // 0x8004D0B8: nop

    // 0x8004D0BC: lb          $t5, 0x1D7($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004D0C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004D0C4: sb          $t5, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r13;
    // 0x8004D0C8: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x8004D0CC: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8004D0D0: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004D0D4: bltz        $t6, L_8004D0E0
    if (SIGNED(ctx->r14) < 0) {
        // 0x8004D0D8: nop
    
            goto L_8004D0E0;
    }
    // 0x8004D0D8: nop

    // 0x8004D0DC: sb          $t7, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r15;
L_8004D0E0:
    // 0x8004D0E0: lb          $t8, 0x1E2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004D0E4: nop

    // 0x8004D0E8: bne         $t8, $zero, L_8004D130
    if (ctx->r24 != 0) {
        // 0x8004D0EC: nop
    
            goto L_8004D130;
    }
    // 0x8004D0EC: nop

    // 0x8004D0F0: lb          $t9, 0x1E0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004D0F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004D0F8: lwc1        $f2, 0x6B14($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B14);
    // 0x8004D0FC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8004D100: sb          $t3, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r11;
    // 0x8004D104: lb          $t4, 0x1E0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004D108: nop

    // 0x8004D10C: slti        $at, $t4, 0x3D
    ctx->r1 = SIGNED(ctx->r12) < 0X3D ? 1 : 0;
    // 0x8004D110: bne         $at, $zero, L_8004D134
    if (ctx->r1 != 0) {
        // 0x8004D114: nop
    
            goto L_8004D134;
    }
    // 0x8004D114: nop

    // 0x8004D118: lb          $t5, 0x1D7($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004D11C: nop

    // 0x8004D120: sb          $t5, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r13;
    // 0x8004D124: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x8004D128: b           L_8004D134
    // 0x8004D12C: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
        goto L_8004D134;
    // 0x8004D12C: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
L_8004D130:
    // 0x8004D130: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
L_8004D134:
    // 0x8004D134: lh          $v1, 0x1A0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004D138: lh          $t6, 0x198($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X198);
    // 0x8004D13C: andi        $t7, $v1, 0xFFFF
    ctx->r15 = ctx->r3 & 0XFFFF;
    // 0x8004D140: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004D144: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x8004D148: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004D14C: bne         $at, $zero, L_8004D15C
    if (ctx->r1 != 0) {
        // 0x8004D150: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004D15C;
    }
    // 0x8004D150: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004D154: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004D158: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004D15C:
    // 0x8004D15C: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8004D160: beq         $at, $zero, L_8004D16C
    if (ctx->r1 == 0) {
        // 0x8004D164: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004D16C;
    }
    // 0x8004D164: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004D168: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004D16C:
    // 0x8004D16C: slti        $at, $v0, 0x1001
    ctx->r1 = SIGNED(ctx->r2) < 0X1001 ? 1 : 0;
    // 0x8004D170: beq         $at, $zero, L_8004D184
    if (ctx->r1 == 0) {
        // 0x8004D174: sra         $t8, $v0, 3
        ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8004D184;
    }
    // 0x8004D174: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8004D178: slti        $at, $v0, -0x1000
    ctx->r1 = SIGNED(ctx->r2) < -0X1000 ? 1 : 0;
    // 0x8004D17C: beq         $at, $zero, L_8004D18C
    if (ctx->r1 == 0) {
        // 0x8004D180: nop
    
            goto L_8004D18C;
    }
    // 0x8004D180: nop

L_8004D184:
    // 0x8004D184: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D188: nop

L_8004D18C:
    // 0x8004D18C: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8004D190: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8004D194: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004D198: sh          $t9, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r25;
    // 0x8004D19C: sh          $zero, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = 0;
    // 0x8004D1A0: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D1A4: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D1A8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004D1AC: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D1B0: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
    // 0x8004D1B4: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004D1B8: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8004D1BC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8004D1C0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8004D1C4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004D1C8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004D1CC: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8004D1D0: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D1D4: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x8004D1D8: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004D1DC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004D1E0: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004D1E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004D1E8: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8004D1EC: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x8004D1F0: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004D1F4: nop

    // 0x8004D1F8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8004D1FC: mul.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x8004D200: lwc1        $f16, 0x20($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D204: nop

    // 0x8004D208: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8004D20C: sub.d       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f8.d - ctx->f4.d;
    // 0x8004D210: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8004D214: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8004D218: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004D21C: nop

    // 0x8004D220: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8004D224: mul.d       $f18, $f4, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x8004D228: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D22C: nop

    // 0x8004D230: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8004D234: sub.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f10.d - ctx->f18.d;
    // 0x8004D238: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x8004D23C: swc1        $f16, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f16.u32l;
    // 0x8004D240: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004D244: nop

    // 0x8004D248: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8004D24C: mul.d       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f12.d);
    // 0x8004D250: sub.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f4.d - ctx->f6.d;
    // 0x8004D254: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8004D258: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x8004D25C: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004D260: lwc1        $f18, 0x6B18($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6B18);
    // 0x8004D264: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004D268: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8004D26C: mul.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8004D270: bc1f        L_8004D27C
    if (!c1cs) {
        // 0x8004D274: nop
    
            goto L_8004D27C;
    }
    // 0x8004D274: nop

    // 0x8004D278: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8004D27C:
    // 0x8004D27C: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8004D280: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D284: mul.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004D288: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004D28C: lwc1        $f12, 0x6B1C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6B1C);
    // 0x8004D290: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D294: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8004D298: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D29C: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x8004D2A0: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004D2A4: nop

    // 0x8004D2A8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004D2AC: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8004D2B0: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x8004D2B4: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004D2B8: nop

    // 0x8004D2BC: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004D2C0: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8004D2C4: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8004D2C8: lwc1        $f2, 0x30($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8004D2CC: nop

    // 0x8004D2D0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004D2D4: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8004D2D8: mul.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8004D2DC: bc1f        L_8004D2E8
    if (!c1cs) {
        // 0x8004D2E0: nop
    
            goto L_8004D2E8;
    }
    // 0x8004D2E0: nop

    // 0x8004D2E4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8004D2E8:
    // 0x8004D2E8: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004D2EC: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D2F0: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004D2F4: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D2F8: sub.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8004D2FC: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D300: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    // 0x8004D304: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004D308: nop

    // 0x8004D30C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004D310: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8004D314: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x8004D318: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004D31C: nop

    // 0x8004D320: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004D324: sub.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8004D328: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8004D32C: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8004D330: nop

    // 0x8004D334: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004D338: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8004D33C: mul.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8004D340: bc1f        L_8004D34C
    if (!c1cs) {
        // 0x8004D344: nop
    
            goto L_8004D34C;
    }
    // 0x8004D344: nop

    // 0x8004D348: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8004D34C:
    // 0x8004D34C: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004D350: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D354: mul.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004D358: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D35C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004D360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004D364: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8004D368: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D36C: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8004D370: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004D374: nop

    // 0x8004D378: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004D37C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8004D380: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x8004D384: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004D388: nop

    // 0x8004D38C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004D390: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8004D394: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8004D398: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x8004D39C: lw          $t3, -0x252C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X252C);
    // 0x8004D3A0: lh          $v0, 0x1A2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004D3A4: lh          $t7, 0x1A0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004D3A8: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x8004D3AC: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8004D3B0: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8004D3B4: sh          $t6, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r14;
    // 0x8004D3B8: lh          $t8, 0x1A2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004D3BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004D3C0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8004D3C4: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
    // 0x8004D3C8: lh          $v1, 0x1A6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004D3CC: lw          $t3, -0x2528($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2528);
    // 0x8004D3D0: lh          $t7, 0x1A4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004D3D4: subu        $t4, $t3, $v1
    ctx->r12 = SUB32(ctx->r11, ctx->r3);
    // 0x8004D3D8: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8004D3DC: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8004D3E0: sh          $t6, 0x1A6($s0)
    MEM_H(0X1A6, ctx->r16) = ctx->r14;
    // 0x8004D3E4: lh          $t8, 0x1A6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004D3E8: lwc1        $f2, 0xDC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004D3EC: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004D3F0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8004D3F4: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004D3F8: sh          $t9, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r25;
    // 0x8004D3FC: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004D400: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
    // 0x8004D404: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004D408: nop

    // 0x8004D40C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8004D410: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8004D414: mul.s       $f16, $f12, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8004D418: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8004D41C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8004D420: jal         0x80011570
    // 0x8004D424: nop

    move_object(rdram, ctx);
        goto after_10;
    // 0x8004D424: nop

    after_10:
    // 0x8004D428: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004D42C: addiu       $t1, $t1, -0x2524
    ctx->r9 = ADD32(ctx->r9, -0X2524);
    // 0x8004D430: beq         $v0, $zero, L_8004D44C
    if (ctx->r2 == 0) {
        // 0x8004D434: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8004D44C;
    }
    // 0x8004D434: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8004D438: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8004D43C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004D440: beq         $t0, $t3, L_8004D44C
    if (ctx->r8 == ctx->r11) {
        // 0x8004D444: nop
    
            goto L_8004D44C;
    }
    // 0x8004D444: nop

    // 0x8004D448: sb          $t4, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r12;
L_8004D44C:
    // 0x8004D44C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8004D450: lw          $a2, 0xD8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD8);
    // 0x8004D454: bne         $t0, $t5, L_8004D474
    if (ctx->r8 != ctx->r13) {
        // 0x8004D458: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004D474;
    }
    // 0x8004D458: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004D45C: lw          $a2, 0xD8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD8);
    // 0x8004D460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004D464: jal         0x80055AC4
    // 0x8004D468: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    onscreen_ai_racer_physics(rdram, ctx);
        goto after_11;
    // 0x8004D468: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8004D46C: b           L_8004D480
    // 0x8004D470: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_8004D480;
    // 0x8004D470: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8004D474:
    // 0x8004D474: jal         0x80055010
    // 0x8004D478: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80054FD0(rdram, ctx);
        goto after_12;
    // 0x8004D478: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x8004D47C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8004D480:
    // 0x8004D480: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004D484: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004D488: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004D48C: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004D490: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8004D494: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8004D498: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8004D49C: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004D4A0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004D4A4: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8004D4A8: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x8004D4AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004D4B0: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x8004D4B4: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8004D4B8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004D4BC: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8004D4C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004D4C4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8004D4C8: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8004D4CC: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x8004D4D0: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8004D4D4: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x8004D4D8: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004D4DC: mul.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004D4E0: swc1        $f12, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f12.u32l;
    // 0x8004D4E4: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8004D4E8: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x8004D4EC: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x8004D4F0: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8004D4F4: sh          $t9, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r25;
    // 0x8004D4F8: swc1        $f14, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f14.u32l;
    // 0x8004D4FC: swc1        $f14, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f14.u32l;
    // 0x8004D500: swc1        $f14, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f14.u32l;
    // 0x8004D504: jal         0x800700B4
    // 0x8004D508: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_13;
    // 0x8004D508: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    after_13:
    // 0x8004D50C: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x8004D510: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x8004D514: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x8004D518: addiu       $t3, $s0, 0x30
    ctx->r11 = ADD32(ctx->r16, 0X30);
    // 0x8004D51C: addiu       $t4, $s0, 0x34
    ctx->r12 = ADD32(ctx->r16, 0X34);
    // 0x8004D520: addiu       $t5, $s0, 0x2C
    ctx->r13 = ADD32(ctx->r16, 0X2C);
    // 0x8004D524: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8004D528: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8004D52C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8004D530: jal         0x8006F88C
    // 0x8004D534: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    mtxf_transform_point(rdram, ctx);
        goto after_14;
    // 0x8004D534: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_14:
    // 0x8004D538: lw          $a3, 0xDC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XDC);
    // 0x8004D53C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004D540: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004D544: jal         0x800580F4
    // 0x8004D548: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    second_racer_camera_update(rdram, ctx);
        goto after_15;
    // 0x8004D548: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_15:
    // 0x8004D54C: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8004D550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004D554: beq         $v0, $zero, L_8004D5A4
    if (ctx->r2 == 0) {
        // 0x8004D558: lb          $t9, 0x3F($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X3F);
            goto L_8004D5A4;
    }
    // 0x8004D558: lb          $t9, 0x3F($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X3F);
    // 0x8004D55C: lb          $t6, 0x1D7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004D560: nop

    // 0x8004D564: bne         $t6, $zero, L_8004D5A4
    if (ctx->r14 != 0) {
        // 0x8004D568: lb          $t9, 0x3F($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X3F);
            goto L_8004D5A4;
    }
    // 0x8004D568: lb          $t9, 0x3F($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X3F);
    // 0x8004D56C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8004D570: nop

    // 0x8004D574: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8004D578: bne         $at, $zero, L_8004D5A4
    if (ctx->r1 != 0) {
        // 0x8004D57C: lb          $t9, 0x3F($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X3F);
            goto L_8004D5A4;
    }
    // 0x8004D57C: lb          $t9, 0x3F($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X3F);
    // 0x8004D580: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8004D584: nop

    // 0x8004D588: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8004D58C: lw          $t8, 0x60($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X60);
    // 0x8004D590: nop

    // 0x8004D594: lw          $a1, 0x10($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X10);
    // 0x8004D598: nop

    // 0x8004D59C: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8004D5A0: lb          $t9, 0x3F($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X3F);
L_8004D5A4:
    // 0x8004D5A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004D5A8: beq         $t9, $zero, L_8004D5C0
    if (ctx->r25 == 0) {
        // 0x8004D5AC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8004D5C0;
    }
    // 0x8004D5AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D5B0: lb          $t3, 0x1D7($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004D5B4: jal         0x80023104
    // 0x8004D5B8: sb          $t3, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r11;
    func_800230D0(rdram, ctx);
        goto after_16;
    // 0x8004D5B8: sb          $t3, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r11;
    after_16:
    // 0x8004D5BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004D5C0:
    // 0x8004D5C0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8004D5C4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8004D5C8: jr          $ra
    // 0x8004D5CC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8004D5CC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void unload_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C478C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C4790: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C4794: lw          $t6, -0x5260($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5260);
    // 0x800C4798: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C479C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C47A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C47A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C47A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C47AC: beq         $at, $zero, L_800C4830
    if (ctx->r1 == 0) {
        // 0x800C47B0: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800C4830;
    }
    // 0x800C47B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C47B4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C47B8: lw          $t8, -0x525C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X525C);
    // 0x800C47BC: sll         $t7, $a0, 10
    ctx->r15 = S32(ctx->r4 << 10);
    // 0x800C47C0: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x800C47C4: lbu         $v0, 0x28($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X28);
    // 0x800C47C8: nop

    // 0x800C47CC: blez        $v0, L_800C4830
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C47D0: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800C4830;
    }
    // 0x800C47D0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800C47D4: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x800C47D8: bne         $t0, $zero, L_800C4830
    if (ctx->r8 != 0) {
        // 0x800C47DC: sb          $t9, 0x28($s2)
        MEM_B(0X28, ctx->r18) = ctx->r25;
            goto L_800C4830;
    }
    // 0x800C47DC: sb          $t9, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r25;
    // 0x800C47E0: lh          $t1, 0x40($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X40);
    // 0x800C47E4: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800C47E8: beq         $s3, $t1, L_800C4830
    if (ctx->r19 == ctx->r9) {
        // 0x800C47EC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800C4830;
    }
    // 0x800C47EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800C47F0: sll         $t2, $zero, 2
    ctx->r10 = S32(0 << 2);
    // 0x800C47F4: addu        $s0, $s2, $t2
    ctx->r16 = ADD32(ctx->r18, ctx->r10);
L_800C47F8:
    // 0x800C47F8: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    // 0x800C47FC: jal         0x8007B70C
    // 0x800C4800: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800C4800: nop

    after_0:
    // 0x800C4804: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C4808: slti        $at, $s1, 0x20
    ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
    // 0x800C480C: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // 0x800C4810: beq         $at, $zero, L_800C4830
    if (ctx->r1 == 0) {
        // 0x800C4814: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800C4830;
    }
    // 0x800C4814: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800C4818: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
    // 0x800C481C: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x800C4820: lh          $t5, 0x40($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X40);
    // 0x800C4824: nop

    // 0x800C4828: bne         $s3, $t5, L_800C47F8
    if (ctx->r19 != ctx->r13) {
        // 0x800C482C: nop
    
            goto L_800C47F8;
    }
    // 0x800C482C: nop

L_800C4830:
    // 0x800C4830: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4834: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C4838: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C483C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4840: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C4844: jr          $ra
    // 0x800C4848: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C4848: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void savemenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FDC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80085FE0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80085FE4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80085FE8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80085FEC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80085FF0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80085FF4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80085FF8: jal         0x8007A970
    // 0x80085FFC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80085FFC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_0:
    // 0x80086000: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80086004: lw          $v1, 0x6980($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6980);
    // 0x80086008: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008600C: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x80086010: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80086014: addu        $at, $at, $t6
    gpr jr_addend_80086030 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80086018: lw          $t6, -0x7690($at)
    ctx->r14 = ADD32(ctx->r1, -0X7690);
    // 0x8008601C: andi        $s4, $v0, 0xFFFF
    ctx->r20 = ctx->r2 & 0XFFFF;
    // 0x80086020: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80086024: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80086028: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008602C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80086030: jr          $t6
    // 0x80086034: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    switch (jr_addend_80086030 >> 2) {
        case 0: goto L_80086070; break;
        case 1: goto L_80086038; break;
        case 2: goto L_80086038; break;
        case 3: goto L_80086040; break;
        case 4: goto L_80086040; break;
        case 5: goto L_80086048; break;
        case 6: goto L_80086054; break;
        case 7: goto L_80086064; break;
        default: switch_error(__func__, 0x80086030, 0x800E8970);
    }
    // 0x80086034: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80086038:
    // 0x80086038: b           L_80086070
    // 0x8008603C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80086070;
    // 0x8008603C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80086040:
    // 0x80086040: b           L_80086070
    // 0x80086044: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80086070;
    // 0x80086044: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80086048:
    // 0x80086048: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008604C: b           L_80086070
    // 0x80086050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80086070;
    // 0x80086050: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80086054:
    // 0x80086054: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80086058: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008605C: b           L_80086070
    // 0x80086060: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80086070;
    // 0x80086060: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80086064:
    // 0x80086064: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80086068: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008606C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80086070:
    // 0x80086070: andi        $t7, $v1, 0x8
    ctx->r15 = ctx->r3 & 0X8;
    // 0x80086074: beq         $t7, $zero, L_80086080
    if (ctx->r15 == 0) {
        // 0x80086078: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80086080;
    }
    // 0x80086078: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008607C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80086080:
    // 0x80086080: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086084: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x80086088: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008608C: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x80086090: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80086094: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80086098: jal         0x8006816C
    // 0x8008609C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    mtx_ortho(rdram, ctx);
        goto after_1;
    // 0x8008609C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    after_1:
    // 0x800860A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800860A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800860A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800860AC: jal         0x800C492C
    // 0x800860B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_2;
    // 0x800860B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x800860B4: jal         0x800C484C
    // 0x800860B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_3;
    // 0x800860B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x800860BC: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800860C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800860C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800860C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800860CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800860D0: jal         0x800C48E4
    // 0x800860D4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x800860D4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x800860D8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800860DC: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x800860E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800860E4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800860E8: lw          $a3, 0x294($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X294);
    // 0x800860EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800860F0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800860F4: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x800860F8: jal         0x800C49A0
    // 0x800860FC: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x800860FC: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_5:
    // 0x80086100: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80086104: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80086108: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008610C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80086110: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80086114: jal         0x800C48E4
    // 0x80086118: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_6;
    // 0x80086118: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8008611C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80086120: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x80086124: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086128: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8008612C: lw          $a3, 0x294($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X294);
    // 0x80086130: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80086134: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80086138: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008613C: jal         0x800C49A0
    // 0x80086140: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_7;
    // 0x80086140: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_7:
    // 0x80086144: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80086148: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8008614C: beq         $t6, $zero, L_800861CC
    if (ctx->r14 == 0) {
        // 0x80086150: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800861CC;
    }
    // 0x80086150: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80086154: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80086158: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8008615C: bne         $t7, $zero, L_8008616C
    if (ctx->r15 != 0) {
        // 0x80086160: lui         $s1, 0x800E
        ctx->r17 = S32(0X800E << 16);
            goto L_8008616C;
    }
    // 0x80086160: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80086164: b           L_80086170
    // 0x80086168: addiu       $s0, $zero, 0x84
    ctx->r16 = ADD32(0, 0X84);
        goto L_80086170;
    // 0x80086168: addiu       $s0, $zero, 0x84
    ctx->r16 = ADD32(0, 0X84);
L_8008616C:
    // 0x8008616C: addiu       $s0, $zero, 0x78
    ctx->r16 = ADD32(0, 0X78);
L_80086170:
    // 0x80086170: lw          $t8, 0x695C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X695C);
    // 0x80086174: addiu       $s1, $s1, 0x9BC
    ctx->r17 = ADD32(ctx->r17, 0X9BC);
    // 0x80086178: andi        $t9, $t8, 0x1F
    ctx->r25 = ctx->r24 & 0X1F;
    // 0x8008617C: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80086180: addu        $s0, $s0, $t2
    ctx->r16 = ADD32(ctx->r16, ctx->r10);
L_80086184:
    // 0x80086184: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086188: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8008618C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80086190: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80086194: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80086198: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8008619C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800861A0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800861A4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800861A8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800861AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800861B0: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x800861B4: jal         0x80078F08
    // 0x800861B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    texrect_draw(rdram, ctx);
        goto after_8;
    // 0x800861B8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_8:
    // 0x800861BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800861C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800861C4: bne         $s2, $at, L_80086184
    if (ctx->r18 != ctx->r1) {
        // 0x800861C8: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80086184;
    }
    // 0x800861C8: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_800861CC:
    // 0x800861CC: beq         $s3, $zero, L_800862F8
    if (ctx->r19 == 0) {
        // 0x800861D0: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800862F8;
    }
    // 0x800861D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800861D4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800861D8: lwc1        $f0, 0x719C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X719C);
    // 0x800861DC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800861E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800861E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800861E8: lui         $at, 0x4324
    ctx->r1 = S32(0X4324 << 16);
    // 0x800861EC: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800861F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800861F4: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x800861F8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800861FC: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
    // 0x80086200: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x80086204: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80086208: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008620C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80086210: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80086214: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80086218: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8008621C: nop

    // 0x80086220: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80086224: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80086228: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008622C: nop

    // 0x80086230: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80086234: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80086238: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8008623C: subu        $v0, $t2, $t9
    ctx->r2 = SUB32(ctx->r10, ctx->r25);
    // 0x80086240: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80086244: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80086248: beq         $at, $zero, L_800862AC
    if (ctx->r1 == 0) {
        // 0x8008624C: sw          $v0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r2;
            goto L_800862AC;
    }
    // 0x8008624C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80086250: lw          $t3, 0x6FC8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6FC8);
    // 0x80086254: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80086258: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8008625C: beq         $at, $zero, L_800862AC
    if (ctx->r1 == 0) {
        // 0x80086260: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_800862AC;
    }
    // 0x80086260: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80086264: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80086268: addiu       $s3, $s3, 0x6FCC
    ctx->r19 = ADD32(ctx->r19, 0X6FCC);
L_8008626C:
    // 0x8008626C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80086270: sll         $t4, $s0, 4
    ctx->r12 = S32(ctx->r16 << 4);
    // 0x80086274: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80086278: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8008627C: jal         0x80085810
    // 0x80086280: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    savemenu_render_element(rdram, ctx);
        goto after_9;
    // 0x80086280: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_9:
    // 0x80086284: addiu       $s1, $s1, 0xA4
    ctx->r17 = ADD32(ctx->r17, 0XA4);
    // 0x80086288: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8008628C: beq         $at, $zero, L_800862AC
    if (ctx->r1 == 0) {
        // 0x80086290: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800862AC;
    }
    // 0x80086290: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80086294: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086298: lw          $t6, 0x6FC8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FC8);
    // 0x8008629C: nop

    // 0x800862A0: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800862A4: bne         $at, $zero, L_8008626C
    if (ctx->r1 != 0) {
        // 0x800862A8: nop
    
            goto L_8008626C;
    }
    // 0x800862A8: nop

L_800862AC:
    // 0x800862AC: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800862B0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800862B4: addiu       $s3, $s3, 0x6FCC
    ctx->r19 = ADD32(ctx->r19, 0X6FCC);
    // 0x800862B8: blez        $s1, L_800862F8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800862BC: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800862F8;
    }
    // 0x800862BC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800862C0: blez        $s2, L_800862FC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800862C4: lw          $t2, 0x4C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X4C);
            goto L_800862FC;
    }
    // 0x800862C4: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
L_800862C8:
    // 0x800862C8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800862CC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800862D0: addiu       $s1, $s1, -0xA4
    ctx->r17 = ADD32(ctx->r17, -0XA4);
    // 0x800862D4: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x800862D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800862DC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800862E0: jal         0x80085810
    // 0x800862E4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    savemenu_render_element(rdram, ctx);
        goto after_10;
    // 0x800862E4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_10:
    // 0x800862E8: blez        $s1, L_800862FC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800862EC: lw          $t2, 0x4C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X4C);
            goto L_800862FC;
    }
    // 0x800862EC: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800862F0: bgtz        $s0, L_800862C8
    if (SIGNED(ctx->r16) > 0) {
        // 0x800862F4: nop
    
            goto L_800862C8;
    }
    // 0x800862F4: nop

L_800862F8:
    // 0x800862F8: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
L_800862FC:
    // 0x800862FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086300: beq         $t2, $zero, L_80086420
    if (ctx->r10 == 0) {
        // 0x80086304: nop
    
            goto L_80086420;
    }
    // 0x80086304: nop

    // 0x80086308: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8008630C: lwc1        $f0, 0x71AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X71AC);
    // 0x80086310: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80086314: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80086318: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008631C: lui         $at, 0x4324
    ctx->r1 = S32(0X4324 << 16);
    // 0x80086320: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80086324: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80086328: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x8008632C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80086330: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x80086334: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x80086338: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008633C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086340: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80086344: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80086348: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8008634C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80086350: nop

    // 0x80086354: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80086358: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008635C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80086360: nop

    // 0x80086364: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80086368: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x8008636C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80086370: subu        $s1, $t5, $t4
    ctx->r17 = SUB32(ctx->r13, ctx->r12);
    // 0x80086374: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80086378: beq         $at, $zero, L_800863D4
    if (ctx->r1 == 0) {
        // 0x8008637C: sw          $s1, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r17;
            goto L_800863D4;
    }
    // 0x8008637C: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80086380: lw          $t7, 0x6FC0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6FC0);
    // 0x80086384: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80086388: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008638C: beq         $at, $zero, L_800863D4
    if (ctx->r1 == 0) {
        // 0x80086390: addiu       $s3, $s3, 0x6FC4
        ctx->r19 = ADD32(ctx->r19, 0X6FC4);
            goto L_800863D4;
    }
    // 0x80086390: addiu       $s3, $s3, 0x6FC4
    ctx->r19 = ADD32(ctx->r19, 0X6FC4);
L_80086394:
    // 0x80086394: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80086398: sll         $t8, $s0, 4
    ctx->r24 = S32(ctx->r16 << 4);
    // 0x8008639C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800863A0: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x800863A4: jal         0x80085810
    // 0x800863A8: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
    savemenu_render_element(rdram, ctx);
        goto after_11;
    // 0x800863A8: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
    after_11:
    // 0x800863AC: addiu       $s1, $s1, 0xA4
    ctx->r17 = ADD32(ctx->r17, 0XA4);
    // 0x800863B0: slt         $at, $s1, $s4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800863B4: beq         $at, $zero, L_800863D4
    if (ctx->r1 == 0) {
        // 0x800863B8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800863D4;
    }
    // 0x800863B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800863BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800863C0: lw          $t9, 0x6FC0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6FC0);
    // 0x800863C4: nop

    // 0x800863C8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800863CC: bne         $at, $zero, L_80086394
    if (ctx->r1 != 0) {
        // 0x800863D0: nop
    
            goto L_80086394;
    }
    // 0x800863D0: nop

L_800863D4:
    // 0x800863D4: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800863D8: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800863DC: addiu       $s3, $s3, 0x6FC4
    ctx->r19 = ADD32(ctx->r19, 0X6FC4);
    // 0x800863E0: blez        $s1, L_80086420
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800863E4: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_80086420;
    }
    // 0x800863E4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800863E8: blez        $s2, L_80086420
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800863EC: nop
    
            goto L_80086420;
    }
    // 0x800863EC: nop

L_800863F0:
    // 0x800863F0: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800863F4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800863F8: addiu       $s1, $s1, -0xA4
    ctx->r17 = ADD32(ctx->r17, -0XA4);
    // 0x800863FC: sll         $t5, $s0, 4
    ctx->r13 = S32(ctx->r16 << 4);
    // 0x80086400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80086404: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80086408: jal         0x80085810
    // 0x8008640C: addu        $a0, $t5, $t4
    ctx->r4 = ADD32(ctx->r13, ctx->r12);
    savemenu_render_element(rdram, ctx);
        goto after_12;
    // 0x8008640C: addu        $a0, $t5, $t4
    ctx->r4 = ADD32(ctx->r13, ctx->r12);
    after_12:
    // 0x80086410: blez        $s1, L_80086420
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80086414: nop
    
            goto L_80086420;
    }
    // 0x80086414: nop

    // 0x80086418: bgtz        $s0, L_800863F0
    if (SIGNED(ctx->r16) > 0) {
        // 0x8008641C: nop
    
            goto L_800863F0;
    }
    // 0x8008641C: nop

L_80086420:
    // 0x80086420: jal         0x800C484C
    // 0x80086424: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_13;
    // 0x80086424: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x80086428: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8008642C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80086430: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80086434: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80086438: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008643C: jal         0x800C48E4
    // 0x80086440: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_14;
    // 0x80086440: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80086444: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80086448: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008644C: beq         $t7, $zero, L_80086470
    if (ctx->r15 == 0) {
        // 0x80086450: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_80086470;
    }
    // 0x80086450: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80086454: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80086458: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8008645C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80086460: addiu       $a3, $a3, -0x7868
    ctx->r7 = ADD32(ctx->r7, -0X7868);
    // 0x80086464: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80086468: jal         0x800C49A0
    // 0x8008646C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    draw_text(rdram, ctx);
        goto after_15;
    // 0x8008646C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_15:
L_80086470:
    // 0x80086470: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80086474: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086478: beq         $t2, $zero, L_800864A0
    if (ctx->r10 == 0) {
        // 0x8008647C: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_800864A0;
    }
    // 0x8008647C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80086480: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80086484: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x80086488: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8008648C: lw          $a3, 0x1F0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X1F0);
    // 0x80086490: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80086494: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80086498: jal         0x800C49A0
    // 0x8008649C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    draw_text(rdram, ctx);
        goto after_16;
    // 0x8008649C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_16:
L_800864A0:
    // 0x800864A0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800864A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800864A8: beq         $t5, $zero, L_800864C0
    if (ctx->r13 == 0) {
        // 0x800864AC: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_800864C0;
    }
    // 0x800864AC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800864B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800864B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800864B8: jal         0x800C60B8
    // 0x800864BC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_17;
    // 0x800864BC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_17:
L_800864C0:
    // 0x800864C0: jal         0x800812BC
    // 0x800864C4: nop

    menu_geometry_end(rdram, ctx);
        goto after_18;
    // 0x800864C4: nop

    after_18:
    // 0x800864C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800864CC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800864D0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800864D4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800864D8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800864DC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800864E0: jr          $ra
    // 0x800864E4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800864E4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void cam_get_viewport_layout(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066450: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066454: lw          $v0, 0x1260($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1260);
    // 0x80066458: jr          $ra
    // 0x8006645C: nop

    return;
    // 0x8006645C: nop

;}
RECOMP_FUNC void func_80074AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80074D04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074D08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074D0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80074D10: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80074D14: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80074D18: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80074D1C: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x80074D20: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80074D24: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x80074D28: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    // 0x80074D2C: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x80074D30: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80074D34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074D38: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x80074D3C: sll         $a2, $t7, 2
    ctx->r6 = S32(ctx->r15 << 2);
    // 0x80074D40: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
    // 0x80074D44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80074D48: subu        $a2, $a2, $t7
    ctx->r6 = SUB32(ctx->r6, ctx->r15);
    // 0x80074D4C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80074D50: jal         0x800CA300
    // 0x80074D54: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    _bcopy(rdram, ctx);
        goto after_0;
    // 0x80074D54: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x80074D58: jal         0x80074CA4
    // 0x80074D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    calculate_ghost_header_checksum(rdram, ctx);
        goto after_1;
    // 0x80074D5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80074D60: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80074D64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074D68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074D6C: jr          $ra
    // 0x80074D70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80074D70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void menu_image_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CE48: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009CE4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8009CE50: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009CE54: addiu       $s1, $s1, -0x324
    ctx->r17 = ADD32(ctx->r17, -0X324);
    // 0x8009CE58: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x8009CE5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009CE60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8009CE64: bne         $a2, $zero, L_8009CE84
    if (ctx->r6 != 0) {
        // 0x8009CE68: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_8009CE84;
    }
    // 0x8009CE68: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8009CE6C: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8009CE70: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8009CE74: jal         0x80070EDC
    // 0x8009CE78: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8009CE78: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    after_0:
    // 0x8009CE7C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8009CE80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8009CE84:
    // 0x8009CE84: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8009CE88: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009CE8C: addiu       $t7, $t7, -0x570
    ctx->r15 = ADD32(ctx->r15, -0X570);
    // 0x8009CE90: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x8009CE94: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8009CE98: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x8009CE9C: addu        $t9, $a2, $t6
    ctx->r25 = ADD32(ctx->r6, ctx->r14);
    // 0x8009CEA0: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x8009CEA4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEA8: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x8009CEAC: addu        $t2, $t1, $t6
    ctx->r10 = ADD32(ctx->r9, ctx->r14);
    // 0x8009CEB0: sh          $t0, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r8;
    // 0x8009CEB4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEB8: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x8009CEBC: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x8009CEC0: sh          $t3, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r11;
    // 0x8009CEC4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEC8: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8009CECC: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x8009CED0: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8009CED4: sh          $t6, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r14;
    // 0x8009CED8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEDC: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8009CEE0: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x8009CEE4: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x8009CEE8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEEC: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8009CEF0: addu        $t2, $t0, $s0
    ctx->r10 = ADD32(ctx->r8, ctx->r16);
    // 0x8009CEF4: swc1        $f6, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f6.u32l;
    // 0x8009CEF8: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009CEFC: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8009CF00: addu        $t3, $t4, $s0
    ctx->r11 = ADD32(ctx->r12, ctx->r16);
    // 0x8009CF04: swc1        $f8, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f8.u32l;
    // 0x8009CF08: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF0C: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8009CF10: addu        $t7, $t5, $s0
    ctx->r15 = ADD32(ctx->r13, ctx->r16);
    // 0x8009CF14: swc1        $f10, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f10.u32l;
    // 0x8009CF18: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF1C: lh          $t6, 0x18($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X18);
    // 0x8009CF20: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8009CF24: sh          $t6, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r14;
    // 0x8009CF28: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8009CF2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009CF30: jal         0x8006FB8C
    // 0x8009CF34: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    rand_range(rdram, ctx);
        goto after_1;
    // 0x8009CF34: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_1:
    // 0x8009CF38: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009CF40: addu        $t0, $t1, $s0
    ctx->r8 = ADD32(ctx->r9, ctx->r16);
    // 0x8009CF44: sb          $v0, 0x1A($t0)
    MEM_B(0X1A, ctx->r8) = ctx->r2;
    // 0x8009CF48: jal         0x8006FB8C
    // 0x8009CF4C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x8009CF4C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_2:
    // 0x8009CF50: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009CF58: addu        $t4, $t2, $s0
    ctx->r12 = ADD32(ctx->r10, ctx->r16);
    // 0x8009CF5C: sb          $v0, 0x1B($t4)
    MEM_B(0X1B, ctx->r12) = ctx->r2;
    // 0x8009CF60: jal         0x8006FB8C
    // 0x8009CF64: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    rand_range(rdram, ctx);
        goto after_3;
    // 0x8009CF64: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_3:
    // 0x8009CF68: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF6C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009CF70: addu        $t5, $t3, $s0
    ctx->r13 = ADD32(ctx->r11, ctx->r16);
    // 0x8009CF74: sb          $v0, 0x1C($t5)
    MEM_B(0X1C, ctx->r13) = ctx->r2;
    // 0x8009CF78: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8009CF7C: lb          $t7, 0x1D($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1D);
    // 0x8009CF80: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x8009CF84: sb          $t7, 0x1D($t6)
    MEM_B(0X1D, ctx->r14) = ctx->r15;
    // 0x8009CF88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CF8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8009CF90: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8009CF94: jr          $ra
    // 0x8009CF98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8009CF98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void allocate_object_model_pools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F9F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F9F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F9F8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8005F9FC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8005FA00: jal         0x80070EDC
    // 0x8005FA04: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8005FA04: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    after_0:
    // 0x8005FA08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FA0C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8005FA10: sw          $v0, -0x245C($at)
    MEM_W(-0X245C, ctx->r1) = ctx->r2;
    // 0x8005FA14: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8005FA18: jal         0x80070EDC
    // 0x8005FA1C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8005FA1C: addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_1:
    // 0x8005FA20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FA24: sw          $v0, -0x2458($at)
    MEM_W(-0X2458, ctx->r1) = ctx->r2;
    // 0x8005FA28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FA2C: sw          $zero, -0x2454($at)
    MEM_W(-0X2454, ctx->r1) = 0;
    // 0x8005FA30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FA34: sw          $zero, -0x244C($at)
    MEM_W(-0X244C, ctx->r1) = 0;
    // 0x8005FA38: jal         0x80076EE4
    // 0x8005FA3C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    asset_table_load(rdram, ctx);
        goto after_2;
    // 0x8005FA3C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_2:
    // 0x8005FA40: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005FA44: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8005FA48: addiu       $a3, $a3, -0x2460
    ctx->r7 = ADD32(ctx->r7, -0X2460);
    // 0x8005FA4C: addiu       $a1, $a1, -0x2450
    ctx->r5 = ADD32(ctx->r5, -0X2450);
    // 0x8005FA50: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8005FA54: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8005FA58: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8005FA5C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8005FA60: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8005FA64: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005FA68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005FA6C: beq         $a2, $t8, L_8005FA94
    if (ctx->r6 == ctx->r24) {
        // 0x8005FA70: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005FA94;
    }
    // 0x8005FA70: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005FA74: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8005FA78:
    // 0x8005FA78: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005FA7C: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8005FA80: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005FA84: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8005FA88: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8005FA8C: bne         $a2, $t2, L_8005FA78
    if (ctx->r6 != ctx->r10) {
        // 0x8005FA90: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8005FA78;
    }
    // 0x8005FA90: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8005FA94:
    // 0x8005FA94: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x8005FA98: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8005FA9C: jal         0x80076EE4
    // 0x8005FAA0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    asset_table_load(rdram, ctx);
        goto after_3;
    // 0x8005FAA0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_3:
    // 0x8005FAA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FAA8: sw          $v0, -0x2448($at)
    MEM_W(-0X2448, ctx->r1) = ctx->r2;
    // 0x8005FAAC: jal         0x80076EE4
    // 0x8005FAB0: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8005FAB0: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_4:
    // 0x8005FAB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FAB8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8005FABC: sw          $v0, -0x2444($at)
    MEM_W(-0X2444, ctx->r1) = ctx->r2;
    // 0x8005FAC0: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8005FAC4: jal         0x80070EDC
    // 0x8005FAC8: addiu       $a0, $zero, 0xC00
    ctx->r4 = ADD32(0, 0XC00);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8005FAC8: addiu       $a0, $zero, 0xC00
    ctx->r4 = ADD32(0, 0XC00);
    after_5:
    // 0x8005FACC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FAD0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005FAD4: lw          $a1, -0x2BEC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2BEC);
    // 0x8005FAD8: sw          $v0, -0x243C($at)
    MEM_W(-0X243C, ctx->r1) = ctx->r2;
    // 0x8005FADC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005FAE0: sw          $zero, -0x2440($at)
    MEM_W(-0X2440, ctx->r1) = 0;
    // 0x8005FAE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005FAE8: blez        $a1, L_8005FB10
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005FAEC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005FB10;
    }
    // 0x8005FAEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005FAF0: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x8005FAF4: addiu       $v0, $v0, 0x4D94
    ctx->r2 = ADD32(ctx->r2, 0X4D94);
L_8005FAF8:
    // 0x8005FAF8: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x8005FAFC: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8005FB00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005FB04: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005FB08: bne         $at, $zero, L_8005FAF8
    if (ctx->r1 != 0) {
        // 0x8005FB0C: addu        $a0, $a0, $t5
        ctx->r4 = ADD32(ctx->r4, ctx->r13);
            goto L_8005FAF8;
    }
    // 0x8005FB0C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
L_8005FB10:
    // 0x8005FB10: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8005FB14: lw          $t6, -0x2BF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BF0);
    // 0x8005FB18: nop

    // 0x8005FB1C: beq         $a0, $t6, L_8005FB30
    if (ctx->r4 == ctx->r14) {
        // 0x8005FB20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FB30;
    }
    // 0x8005FB20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005FB24: jal         0x8005C3FC
    // 0x8005FB28: nop

    drm_vehicle_traction(rdram, ctx);
        goto after_6;
    // 0x8005FB28: nop

    after_6:
    // 0x8005FB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FB30:
    // 0x8005FB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005FB34: jr          $ra
    // 0x8005FB38: nop

    return;
    // 0x8005FB38: nop

;}
RECOMP_FUNC void check_for_controller_pak_errors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887A4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800887A8: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800887AC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800887B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800887B4: addiu       $a3, $a3, 0x7188
    ctx->r7 = ADD32(ctx->r7, 0X7188);
    // 0x800887B8: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800887BC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800887C0: addiu       $t6, $t6, 0x6FF4
    ctx->r14 = ADD32(ctx->r14, 0X6FF4);
    // 0x800887C4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800887C8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800887CC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800887D0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800887D4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800887D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800887DC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800887E0: addiu       $t0, $t0, 0x234
    ctx->r8 = ADD32(ctx->r8, 0X234);
    // 0x800887E4: addiu       $t1, $t1, -0x5E0
    ctx->r9 = ADD32(ctx->r9, -0X5E0);
    // 0x800887E8: addiu       $t3, $t3, 0x6FF8
    ctx->r11 = ADD32(ctx->r11, 0X6FF8);
    // 0x800887EC: addiu       $t4, $t4, 0x7020
    ctx->r12 = ADD32(ctx->r12, 0X7020);
    // 0x800887F0: addiu       $s1, $s1, 0x6FFC
    ctx->r17 = ADD32(ctx->r17, 0X6FFC);
    // 0x800887F4: addu        $a0, $zero, $t6
    ctx->r4 = ADD32(0, ctx->r14);
    // 0x800887F8: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800887FC: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80088800: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80088804: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80088808: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8008880C:
    // 0x8008880C: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80088810: nop

    // 0x80088814: beq         $t7, $zero, L_80088874
    if (ctx->r15 == 0) {
        // 0x80088818: addu        $t8, $t3, $v1
        ctx->r24 = ADD32(ctx->r11, ctx->r3);
            goto L_80088874;
    }
    // 0x80088818: addu        $t8, $t3, $v1
    ctx->r24 = ADD32(ctx->r11, ctx->r3);
    // 0x8008881C: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80088820: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80088824: lw          $t8, 0x100($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X100);
    // 0x80088828: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8008882C: sw          $t8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r24;
    // 0x80088830: lw          $t9, 0x100($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X100);
    // 0x80088834: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80088838: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x8008883C: lw          $t8, 0x158($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X158);
    // 0x80088840: nop

    // 0x80088844: sw          $t8, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r24;
    // 0x80088848: lw          $t9, 0x17C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X17C);
    // 0x8008884C: nop

    // 0x80088850: sw          $t9, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r25;
    // 0x80088854: lw          $t6, 0x28C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X28C);
    // 0x80088858: nop

    // 0x8008885C: sw          $t6, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r14;
    // 0x80088860: lw          $t7, 0x290($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X290);
    // 0x80088864: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80088868: b           L_80088940
    // 0x8008886C: sw          $t7, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = ctx->r15;
        goto L_80088940;
    // 0x8008886C: sw          $t7, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = ctx->r15;
    // 0x80088870: addu        $t8, $t3, $v1
    ctx->r24 = ADD32(ctx->r11, ctx->r3);
L_80088874:
    // 0x80088874: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80088878: addu        $a2, $t4, $v1
    ctx->r6 = ADD32(ctx->r12, ctx->r3);
    // 0x8008887C: beq         $t9, $zero, L_800888E8
    if (ctx->r25 == 0) {
        // 0x80088880: addu        $t6, $s1, $v1
        ctx->r14 = ADD32(ctx->r17, ctx->r3);
            goto L_800888E8;
    }
    // 0x80088880: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
    // 0x80088884: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80088888: nop

    // 0x8008888C: bne         $t6, $zero, L_800888E8
    if (ctx->r14 != 0) {
        // 0x80088890: addu        $t6, $s1, $v1
        ctx->r14 = ADD32(ctx->r17, ctx->r3);
            goto L_800888E8;
    }
    // 0x80088890: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
    // 0x80088894: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80088898: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8008889C: lw          $t7, 0x260($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X260);
    // 0x800888A0: addu        $t6, $a1, $t9
    ctx->r14 = ADD32(ctx->r5, ctx->r25);
    // 0x800888A4: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
    // 0x800888A8: lw          $t8, 0x260($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X260);
    // 0x800888AC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800888B0: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
    // 0x800888B4: lw          $t7, 0x158($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X158);
    // 0x800888B8: nop

    // 0x800888BC: sw          $t7, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r15;
    // 0x800888C0: lw          $t8, 0x110($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X110);
    // 0x800888C4: nop

    // 0x800888C8: sw          $t8, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r24;
    // 0x800888CC: lw          $t9, 0x188($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X188);
    // 0x800888D0: sw          $zero, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = 0;
    // 0x800888D4: sb          $t5, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r13;
    // 0x800888D8: sw          $s0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r16;
    // 0x800888DC: b           L_80088940
    // 0x800888E0: sw          $t9, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r25;
        goto L_80088940;
    // 0x800888E0: sw          $t9, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r25;
    // 0x800888E4: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
L_800888E8:
    // 0x800888E8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800888EC: nop

    // 0x800888F0: beq         $t7, $zero, L_80088940
    if (ctx->r15 == 0) {
        // 0x800888F4: nop
    
            goto L_80088940;
    }
    // 0x800888F4: nop

    // 0x800888F8: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800888FC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80088900: lw          $t8, 0x260($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X260);
    // 0x80088904: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80088908: sw          $t8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r24;
    // 0x8008890C: lw          $t9, 0x260($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X260);
    // 0x80088910: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80088914: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x80088918: lw          $t8, 0x158($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X158);
    // 0x8008891C: nop

    // 0x80088920: sw          $t8, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r24;
    // 0x80088924: lw          $t9, 0x2E0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2E0);
    // 0x80088928: nop

    // 0x8008892C: sw          $t9, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r25;
    // 0x80088930: lw          $t6, 0x2E4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2E4);
    // 0x80088934: sw          $zero, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = 0;
    // 0x80088938: sw          $s2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r18;
    // 0x8008893C: sw          $t6, 0x94($t0)
    MEM_W(0X94, ctx->r8) = ctx->r14;
L_80088940:
    // 0x80088940: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80088944: bgtz        $v1, L_80088954
    if (SIGNED(ctx->r3) > 0) {
        // 0x80088948: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80088954;
    }
    // 0x80088948: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008894C: beq         $v0, $zero, L_8008880C
    if (ctx->r2 == 0) {
        // 0x80088950: nop
    
            goto L_8008880C;
    }
    // 0x80088950: nop

L_80088954:
    // 0x80088954: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80088958: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8008895C: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80088960: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80088964: jr          $ra
    // 0x80088968: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80088968: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void set_animated_texture_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B8BC: blez        $a1, L_8007B910
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8007B8C0: nop
    
            goto L_8007B910;
    }
    // 0x8007B8C0: nop

    // 0x8007B8C4: lhu         $v0, 0x12($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X12);
    // 0x8007B8C8: nop

    // 0x8007B8CC: sll         $t6, $v0, 8
    ctx->r14 = S32(ctx->r2 << 8);
    // 0x8007B8D0: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007B8D4: beq         $at, $zero, L_8007B8F8
    if (ctx->r1 == 0) {
        // 0x8007B8D8: sra         $t0, $v0, 8
        ctx->r8 = S32(SIGNED(ctx->r2) >> 8);
            goto L_8007B8F8;
    }
    // 0x8007B8D8: sra         $t0, $v0, 8
    ctx->r8 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8007B8DC: lh          $t8, 0x16($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X16);
    // 0x8007B8E0: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007B8E4: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B8E8: mflo        $t9
    ctx->r25 = lo;
    // 0x8007B8EC: addu        $v0, $a0, $t9
    ctx->r2 = ADD32(ctx->r4, ctx->r25);
    // 0x8007B8F0: jr          $ra
    // 0x8007B8F4: nop

    return;
    // 0x8007B8F4: nop

L_8007B8F8:
    // 0x8007B8F8: lh          $t2, 0x16($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X16);
    // 0x8007B8FC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007B900: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B904: mflo        $t3
    ctx->r11 = lo;
    // 0x8007B908: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8007B90C: nop

L_8007B910:
    // 0x8007B910: jr          $ra
    // 0x8007B914: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8007B914: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void obj_loop_silvercoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DD54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DD58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DD5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003DD60: jal         0x8006C3DC
    // 0x8003DD64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    race_is_adventure_2P(rdram, ctx);
        goto after_0;
    // 0x8003DD64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DD68: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003DD6C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8003DD70: beq         $v0, $zero, L_8003DD88
    if (ctx->r2 == 0) {
        // 0x8003DD74: nop
    
            goto L_8003DD88;
    }
    // 0x8003DD74: nop

    // 0x8003DD78: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
    // 0x8003DD7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003DD80: bne         $a1, $at, L_8003DDA0
    if (ctx->r5 != ctx->r1) {
        // 0x8003DD84: nop
    
            goto L_8003DDA0;
    }
    // 0x8003DD84: nop

L_8003DD88:
    // 0x8003DD88: bne         $v0, $zero, L_8003DE80
    if (ctx->r2 != 0) {
        // 0x8003DD8C: nop
    
            goto L_8003DE80;
    }
    // 0x8003DD8C: nop

    // 0x8003DD90: lw          $a1, 0x78($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X78);
    // 0x8003DD94: nop

    // 0x8003DD98: bne         $a1, $zero, L_8003DE80
    if (ctx->r5 != 0) {
        // 0x8003DD9C: nop
    
            goto L_8003DE80;
    }
    // 0x8003DD9C: nop

L_8003DDA0:
    // 0x8003DDA0: lw          $v0, 0x4C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4C);
    // 0x8003DDA4: nop

    // 0x8003DDA8: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x8003DDAC: nop

    // 0x8003DDB0: slti        $at, $t6, 0x50
    ctx->r1 = SIGNED(ctx->r14) < 0X50 ? 1 : 0;
    // 0x8003DDB4: beq         $at, $zero, L_8003DE70
    if (ctx->r1 == 0) {
        // 0x8003DDB8: nop
    
            goto L_8003DE70;
    }
    // 0x8003DDB8: nop

    // 0x8003DDBC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003DDC0: nop

    // 0x8003DDC4: beq         $v1, $zero, L_8003DE70
    if (ctx->r3 == 0) {
        // 0x8003DDC8: nop
    
            goto L_8003DE70;
    }
    // 0x8003DDC8: nop

    // 0x8003DDCC: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8003DDD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DDD4: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x8003DDD8: nop

    // 0x8003DDDC: bne         $t8, $at, L_8003DE70
    if (ctx->r24 != ctx->r1) {
        // 0x8003DDE0: nop
    
            goto L_8003DE70;
    }
    // 0x8003DDE0: nop

    // 0x8003DDE4: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003DDE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003DDEC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8003DDF0: nop

    // 0x8003DDF4: beq         $a0, $at, L_8003DE70
    if (ctx->r4 == ctx->r1) {
        // 0x8003DDF8: nop
    
            goto L_8003DE70;
    }
    // 0x8003DDF8: nop

    // 0x8003DDFC: lb          $t9, 0x1D8($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1D8);
    // 0x8003DE00: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003DE04: bne         $t9, $zero, L_8003DE70
    if (ctx->r25 != 0) {
        // 0x8003DE08: sllv        $v1, $t0, $a0
        ctx->r3 = S32(ctx->r8 << (ctx->r4 & 31));
            goto L_8003DE70;
    }
    // 0x8003DE08: sllv        $v1, $t0, $a0
    ctx->r3 = S32(ctx->r8 << (ctx->r4 & 31));
    // 0x8003DE0C: and         $t1, $a1, $v1
    ctx->r9 = ctx->r5 & ctx->r3;
    // 0x8003DE10: bne         $t1, $zero, L_8003DE70
    if (ctx->r9 != 0) {
        // 0x8003DE14: or          $t2, $a1, $v1
        ctx->r10 = ctx->r5 | ctx->r3;
            goto L_8003DE70;
    }
    // 0x8003DE14: or          $t2, $a1, $v1
    ctx->r10 = ctx->r5 | ctx->r3;
    // 0x8003DE18: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8003DE1C: sw          $t2, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r10;
    // 0x8003DE20: sw          $t3, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r11;
    // 0x8003DE24: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x8003DE28: lh          $t4, 0x6($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X6);
    // 0x8003DE2C: addiu       $t6, $zero, 0x200
    ctx->r14 = ADD32(0, 0X200);
    // 0x8003DE30: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x8003DE34: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8003DE38: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
    // 0x8003DE3C: lb          $a0, 0x202($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X202);
    // 0x8003DE40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003DE44: addiu       $a0, $a0, 0x2B
    ctx->r4 = ADD32(ctx->r4, 0X2B);
    // 0x8003DE48: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x8003DE4C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8003DE50: jal         0x80001BC0
    // 0x8003DE54: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    music_jingle_play(rdram, ctx);
        goto after_1;
    // 0x8003DE54: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003DE58: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003DE5C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003DE60: lb          $t0, 0x202($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X202);
    // 0x8003DE64: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8003DE68: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8003DE6C: sb          $t1, 0x202($v0)
    MEM_B(0X202, ctx->r2) = ctx->r9;
L_8003DE70:
    // 0x8003DE70: lh          $t2, 0x18($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X18);
    // 0x8003DE74: sll         $t3, $a3, 3
    ctx->r11 = S32(ctx->r7 << 3);
    // 0x8003DE78: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x8003DE7C: sh          $t6, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r14;
L_8003DE80:
    // 0x8003DE80: lw          $v0, 0x7C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X7C);
    // 0x8003DE84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003DE88: blez        $v0, L_8003DEA4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003DE8C: subu        $t5, $v0, $a3
        ctx->r13 = SUB32(ctx->r2, ctx->r7);
            goto L_8003DEA4;
    }
    // 0x8003DE8C: subu        $t5, $v0, $a3
    ctx->r13 = SUB32(ctx->r2, ctx->r7);
    // 0x8003DE90: sw          $t5, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r13;
    // 0x8003DE94: sw          $t4, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r12;
    // 0x8003DE98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8003DE9C: jal         0x800B019C
    // 0x8003DEA0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_2;
    // 0x8003DEA0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
L_8003DEA4:
    // 0x8003DEA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DEA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DEAC: jr          $ra
    // 0x8003DEB0: nop

    return;
    // 0x8003DEB0: nop

;}
RECOMP_FUNC void obj_init_audioreverb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004005C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80040060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040064: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80040068: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8004006C: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x80040070: nop

    // 0x80040074: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x80040078: lbu         $t8, 0x9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X9);
    // 0x8004007C: lbu         $a3, 0x3($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X3);
    // 0x80040080: sb          $t8, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r24;
    // 0x80040084: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x80040088: andi        $t3, $t8, 0xFF
    ctx->r11 = ctx->r24 & 0XFF;
    // 0x8004008C: sb          $t9, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r25;
    // 0x80040090: lh          $t2, 0x6($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X6);
    // 0x80040094: lh          $t1, 0x4($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X4);
    // 0x80040098: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8004009C: lh          $t0, 0x2($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X2);
    // 0x800400A0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800400A4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800400A8: lbu         $t4, 0x5($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X5);
    // 0x800400AC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800400B0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800400B4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800400B8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800400BC: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800400C0: jal         0x80009968
    // 0x800400C4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    audspat_reverb_add_vertex(rdram, ctx);
        goto after_0;
    // 0x800400C4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x800400C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800400CC: jal         0x8000FFB8
    // 0x800400D0: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x800400D0: nop

    after_1:
    // 0x800400D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800400D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800400DC: jr          $ra
    // 0x800400E0: nop

    return;
    // 0x800400E0: nop

;}
RECOMP_FUNC void hud_time_trial_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A738C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7390: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7394: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A739C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A73A0: lbu         $t6, 0x1DA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1DA);
    // 0x800A73A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A73A8: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x800A73AC: beq         $at, $zero, L_800A76D8
    if (ctx->r1 == 0) {
        // 0x800A73B0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800A76D8;
    }
    // 0x800A73B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A73B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A73B8: addu        $at, $at, $t6
    gpr jr_addend_800A73C4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A73BC: lw          $t6, -0x7318($at)
    ctx->r14 = ADD32(ctx->r1, -0X7318);
    // 0x800A73C0: nop

    // 0x800A73C4: jr          $t6
    // 0x800A73C8: nop

    switch (jr_addend_800A73C4 >> 2) {
        case 0: goto L_800A73CC; break;
        case 1: goto L_800A7498; break;
        case 2: goto L_800A7570; break;
        case 3: goto L_800A7630; break;
        case 4: goto L_800A76B4; break;
        default: switch_error(__func__, 0x800A73C4, 0x800E8CE8);
    }
    // 0x800A73C8: nop

L_800A73CC:
    // 0x800A73CC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A73D0: addiu       $v1, $v1, 0x2CF0
    ctx->r3 = ADD32(ctx->r3, 0X2CF0);
    // 0x800A73D4: addiu       $t7, $zero, 0x7F
    ctx->r15 = ADD32(0, 0X7F);
    // 0x800A73D8: sb          $t7, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r15;
    // 0x800A73DC: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800A73E0: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x800A73E4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800A73E8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A73EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A73F0: jal         0x80001D04
    // 0x800A73F4: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x800A73F4: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    after_0:
    // 0x800A73F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A73FC: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x800A7400: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A7404: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7408: beq         $v1, $zero, L_800A7418
    if (ctx->r3 == 0) {
        // 0x800A740C: addiu       $t0, $t0, 0x729C
        ctx->r8 = ADD32(ctx->r8, 0X729C);
            goto L_800A7418;
    }
    // 0x800A740C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7410: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7414: bne         $v1, $at, L_800A7438
    if (ctx->r3 != ctx->r1) {
        // 0x800A7418: lui         $at, 0xC348
        ctx->r1 = S32(0XC348 << 16);
            goto L_800A7438;
    }
L_800A7418:
    // 0x800A7418: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A741C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A7420: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A7424: nop

    // 0x800A7428: swc1        $f4, 0x1CC($t9)
    MEM_W(0X1CC, ctx->r25) = ctx->f4.u32l;
    // 0x800A742C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A7430: b           L_800A7488
    // 0x800A7434: sb          $zero, 0x1DD($t1)
    MEM_B(0X1DD, ctx->r9) = 0;
        goto L_800A7488;
    // 0x800A7434: sb          $zero, 0x1DD($t1)
    MEM_B(0X1DD, ctx->r9) = 0;
L_800A7438:
    // 0x800A7438: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x800A743C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A7440: beq         $v0, $zero, L_800A7450
    if (ctx->r2 == 0) {
        // 0x800A7444: addiu       $t2, $zero, -0x50
        ctx->r10 = ADD32(0, -0X50);
            goto L_800A7450;
    }
    // 0x800A7444: addiu       $t2, $zero, -0x50
    ctx->r10 = ADD32(0, -0X50);
    // 0x800A7448: bne         $v0, $at, L_800A746C
    if (ctx->r2 != ctx->r1) {
        // 0x800A744C: addiu       $t5, $zero, 0x50
        ctx->r13 = ADD32(0, 0X50);
            goto L_800A746C;
    }
    // 0x800A744C: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
L_800A7450:
    // 0x800A7450: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A7454: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A7458: sb          $t2, 0x1DD($t3)
    MEM_B(0X1DD, ctx->r11) = ctx->r10;
    // 0x800A745C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A7460: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A7464: b           L_800A7488
    // 0x800A7468: swc1        $f6, 0x1CC($t4)
    MEM_W(0X1CC, ctx->r12) = ctx->f6.u32l;
        goto L_800A7488;
    // 0x800A7468: swc1        $f6, 0x1CC($t4)
    MEM_W(0X1CC, ctx->r12) = ctx->f6.u32l;
L_800A746C:
    // 0x800A746C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A7470: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A7474: sb          $t5, 0x1DD($t6)
    MEM_B(0X1DD, ctx->r14) = ctx->r13;
    // 0x800A7478: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A747C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A7480: nop

    // 0x800A7484: swc1        $f8, 0x1CC($t7)
    MEM_W(0X1CC, ctx->r15) = ctx->f8.u32l;
L_800A7488:
    // 0x800A7488: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A748C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A7490: b           L_800A76D8
    // 0x800A7494: sb          $t8, 0x1DA($t9)
    MEM_B(0X1DA, ctx->r25) = ctx->r24;
        goto L_800A76D8;
    // 0x800A7494: sb          $t8, 0x1DA($t9)
    MEM_B(0X1DA, ctx->r25) = ctx->r24;
L_800A7498:
    // 0x800A7498: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800A749C: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800A74A0: lb          $a0, 0x1DD($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X1DD);
    // 0x800A74A4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800A74A8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800A74AC: subu        $t1, $a0, $v1
    ctx->r9 = SUB32(ctx->r4, ctx->r3);
    // 0x800A74B0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800A74B4: lwc1        $f0, 0x1CC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x800A74B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A74BC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800A74C0: nop

    // 0x800A74C4: bc1f        L_800A74E4
    if (!c1cs) {
        // 0x800A74C8: nop
    
            goto L_800A74E4;
    }
    // 0x800A74C8: nop

    // 0x800A74CC: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x800A74D0: nop

    // 0x800A74D4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A74D8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800A74DC: b           L_800A7544
    // 0x800A74E0: swc1        $f6, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f6.u32l;
        goto L_800A7544;
    // 0x800A74E0: swc1        $f6, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f6.u32l;
L_800A74E4:
    // 0x800A74E4: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800A74E8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800A74EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A74F0: addiu       $t4, $zero, -0x78
    ctx->r12 = ADD32(0, -0X78);
    // 0x800A74F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A74F8: swc1        $f10, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f10.u32l;
    // 0x800A74FC: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A7500: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A7504: sb          $t2, 0x1DA($t3)
    MEM_B(0X1DA, ctx->r11) = ctx->r10;
    // 0x800A7508: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A750C: nop

    // 0x800A7510: sb          $t4, 0x1DB($t5)
    MEM_B(0X1DB, ctx->r13) = ctx->r12;
    // 0x800A7514: lw          $t6, 0x7300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7300);
    // 0x800A7518: nop

    // 0x800A751C: bne         $t6, $zero, L_800A7544
    if (ctx->r14 != 0) {
        // 0x800A7520: nop
    
            goto L_800A7544;
    }
    // 0x800A7520: nop

    // 0x800A7524: lbu         $t7, 0x7331($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7331);
    // 0x800A7528: nop

    // 0x800A752C: bne         $t7, $zero, L_800A7544
    if (ctx->r15 != 0) {
        // 0x800A7530: nop
    
            goto L_800A7544;
    }
    // 0x800A7530: nop

    // 0x800A7534: jal         0x800A72FC
    // 0x800A7538: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    hud_time_trial_message(rdram, ctx);
        goto after_1;
    // 0x800A7538: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x800A753C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7540: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
L_800A7544:
    // 0x800A7544: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A7548: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A754C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7550: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7554: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7558: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A755C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7560: jal         0x800AAB5C
    // 0x800A7564: addiu       $a3, $a3, 0x1C0
    ctx->r7 = ADD32(ctx->r7, 0X1C0);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A7564: addiu       $a3, $a3, 0x1C0
    ctx->r7 = ADD32(ctx->r7, 0X1C0);
    after_2:
    // 0x800A7568: b           L_800A76DC
    // 0x800A756C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A76DC;
    // 0x800A756C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7570:
    // 0x800A7570: lb          $t8, 0x1DB($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1DB);
    // 0x800A7574: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800A7578: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800A757C: sb          $t9, 0x1DB($v0)
    MEM_B(0X1DB, ctx->r2) = ctx->r25;
    // 0x800A7580: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7584: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A7588: lb          $t1, 0x1DB($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X1DB);
    // 0x800A758C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A7590: slti        $at, $t1, 0x78
    ctx->r1 = SIGNED(ctx->r9) < 0X78 ? 1 : 0;
    // 0x800A7594: bne         $at, $zero, L_800A7608
    if (ctx->r1 != 0) {
        // 0x800A7598: nop
    
            goto L_800A7608;
    }
    // 0x800A7598: nop

    // 0x800A759C: sb          $t2, 0x1DA($v0)
    MEM_B(0X1DA, ctx->r2) = ctx->r10;
    // 0x800A75A0: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x800A75A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A75A8: beq         $v1, $zero, L_800A75B8
    if (ctx->r3 == 0) {
        // 0x800A75AC: addiu       $t3, $zero, 0x38
        ctx->r11 = ADD32(0, 0X38);
            goto L_800A75B8;
    }
    // 0x800A75AC: addiu       $t3, $zero, 0x38
    ctx->r11 = ADD32(0, 0X38);
    // 0x800A75B0: bne         $v1, $at, L_800A75C4
    if (ctx->r3 != ctx->r1) {
        // 0x800A75B4: nop
    
            goto L_800A75C4;
    }
    // 0x800A75B4: nop

L_800A75B8:
    // 0x800A75B8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A75BC: b           L_800A75F4
    // 0x800A75C0: sb          $t3, 0x1DD($t4)
    MEM_B(0X1DD, ctx->r12) = ctx->r11;
        goto L_800A75F4;
    // 0x800A75C0: sb          $t3, 0x1DD($t4)
    MEM_B(0X1DD, ctx->r12) = ctx->r11;
L_800A75C4:
    // 0x800A75C4: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x800A75C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A75CC: beq         $v0, $zero, L_800A75DC
    if (ctx->r2 == 0) {
        // 0x800A75D0: addiu       $t5, $zero, 0x38
        ctx->r13 = ADD32(0, 0X38);
            goto L_800A75DC;
    }
    // 0x800A75D0: addiu       $t5, $zero, 0x38
    ctx->r13 = ADD32(0, 0X38);
    // 0x800A75D4: bne         $v0, $at, L_800A75E8
    if (ctx->r2 != ctx->r1) {
        // 0x800A75D8: nop
    
            goto L_800A75E8;
    }
    // 0x800A75D8: nop

L_800A75DC:
    // 0x800A75DC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A75E0: b           L_800A75F4
    // 0x800A75E4: sb          $t5, 0x1DD($t6)
    MEM_B(0X1DD, ctx->r14) = ctx->r13;
        goto L_800A75F4;
    // 0x800A75E4: sb          $t5, 0x1DD($t6)
    MEM_B(0X1DD, ctx->r14) = ctx->r13;
L_800A75E8:
    // 0x800A75E8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A75EC: addiu       $t7, $zero, -0x28
    ctx->r15 = ADD32(0, -0X28);
    // 0x800A75F0: sb          $t7, 0x1DD($t8)
    MEM_B(0X1DD, ctx->r24) = ctx->r15;
L_800A75F4:
    // 0x800A75F4: jal         0x80001D04
    // 0x800A75F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A75F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800A75FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7600: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A7604: nop

L_800A7608:
    // 0x800A7608: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A760C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7610: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7614: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7618: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A761C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7620: jal         0x800AAB5C
    // 0x800A7624: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A7624: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    after_4:
    // 0x800A7628: b           L_800A76DC
    // 0x800A762C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A76DC;
    // 0x800A762C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7630:
    // 0x800A7630: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800A7634: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x800A7638: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A763C: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x800A7640: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800A7644: lwc1        $f16, 0x1CC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x800A7648: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A764C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7650: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7654: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800A7658: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A765C: swc1        $f6, 0x1CC($v0)
    MEM_W(0X1CC, ctx->r2) = ctx->f6.u32l;
    // 0x800A7660: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7664: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800A7668: lb          $t1, 0x1DD($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X1DD);
    // 0x800A766C: lwc1        $f8, 0x1CC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x800A7670: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800A7674: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7678: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A767C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7680: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7684: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x800A7688: nop

    // 0x800A768C: bc1f        L_800A76A4
    if (!c1cs) {
        // 0x800A7690: nop
    
            goto L_800A76A4;
    }
    // 0x800A7690: nop

    // 0x800A7694: sb          $t2, 0x1DA($v0)
    MEM_B(0X1DA, ctx->r2) = ctx->r10;
    // 0x800A7698: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A769C: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A76A0: nop

L_800A76A4:
    // 0x800A76A4: jal         0x800AAB5C
    // 0x800A76A8: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A76A8: addiu       $a3, $v0, 0x1C0
    ctx->r7 = ADD32(ctx->r2, 0X1C0);
    after_5:
    // 0x800A76AC: b           L_800A76DC
    // 0x800A76B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A76DC;
    // 0x800A76B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A76B4:
    // 0x800A76B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A76B8: addiu       $v1, $v1, 0x2CF0
    ctx->r3 = ADD32(ctx->r3, 0X2CF0);
    // 0x800A76BC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800A76C0: sb          $t3, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r11;
    // 0x800A76C4: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800A76C8: sb          $t4, 0x1DA($v0)
    MEM_B(0X1DA, ctx->r2) = ctx->r12;
    // 0x800A76CC: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A76D0: nop

    // 0x800A76D4: sb          $zero, 0x1DB($t5)
    MEM_B(0X1DB, ctx->r13) = 0;
L_800A76D8:
    // 0x800A76D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A76DC:
    // 0x800A76DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A76E0: jr          $ra
    // 0x800A76E4: nop

    return;
    // 0x800A76E4: nop

;}
RECOMP_FUNC void debug_text_newline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7464: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B7468: lw          $t6, -0x7D84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D84);
    // 0x800B746C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B7470: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7474: addiu       $v0, $v0, -0x7D92
    ctx->r2 = ADD32(ctx->r2, -0X7D92);
    // 0x800B7478: sh          $t6, -0x7D94($at)
    MEM_H(-0X7D94, ctx->r1) = ctx->r14;
    // 0x800B747C: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800B7480: nop

    // 0x800B7484: addiu       $t8, $t7, 0xB
    ctx->r24 = ADD32(ctx->r15, 0XB);
    // 0x800B7488: jr          $ra
    // 0x800B748C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800B748C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_800BDC80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE1A0: addiu       $sp, $sp, -0x370
    ctx->r29 = ADD32(ctx->r29, -0X370);
    // 0x800BE1A4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BE1A8: lw          $t6, 0x370C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X370C);
    // 0x800BE1AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE1B0: multu       $a0, $t6
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE1B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BE1B8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800BE1BC: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BE1C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE1C4: lwc1        $f4, -0x5988($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BE1C8: addiu       $a3, $a3, -0x5A78
    ctx->r7 = ADD32(ctx->r7, -0X5A78);
    // 0x800BE1CC: lwc1        $f8, 0x44($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X44);
    // 0x800BE1D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE1D4: lwc1        $f6, -0x5984($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800BE1D8: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800BE1DC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800BE1E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BE1E4: lw          $t7, 0x28($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X28);
    // 0x800BE1E8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800BE1EC: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BE1F0: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800BE1F4: mflo        $t0
    ctx->r8 = lo;
    // 0x800BE1F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BE1FC: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800BE200: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800BE204: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800BE208: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800BE20C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800BE210: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800BE214: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800BE218: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800BE21C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800BE220: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800BE224: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x800BE228: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800BE22C: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800BE230: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800BE234: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800BE238: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BE23C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800BE240: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BE244: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BE248: sw          $a1, 0x374($sp)
    MEM_W(0X374, ctx->r29) = ctx->r5;
    // 0x800BE24C: sw          $a2, 0x378($sp)
    MEM_W(0X378, ctx->r29) = ctx->r6;
    // 0x800BE250: swc1        $f4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f4.u32l;
    // 0x800BE254: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x800BE258: beq         $t7, $zero, L_800BE2A4
    if (ctx->r15 == 0) {
        // 0x800BE25C: div.s       $f24, $f10, $f8
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
            goto L_800BE2A4;
    }
    // 0x800BE25C: div.s       $f24, $f10, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BE260: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x800BE264: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800BE268: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x800BE26C: cvt.d.s     $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f28.d = CVT_D_S(ctx->f4.fl);
    // 0x800BE270: mul.d       $f28, $f28, $f30
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.d); NAN_CHECK(ctx->f30.d); 
    ctx->f28.d = MUL_D(ctx->f28.d, ctx->f30.d);
    // 0x800BE274: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800BE278: cvt.d.s     $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f26.d = CVT_D_S(ctx->f6.fl);
    // 0x800BE27C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BE280: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800BE284: mul.d       $f30, $f26, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.d); NAN_CHECK(ctx->f30.d); 
    ctx->f30.d = MUL_D(ctx->f26.d, ctx->f30.d);
    // 0x800BE288: cvt.s.d     $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.d); 
    ctx->f4.fl = CVT_S_D(ctx->f28.d);
    // 0x800BE28C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BE290: swc1        $f4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f4.u32l;
    // 0x800BE294: sw          $t9, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r25;
    // 0x800BE298: cvt.s.d     $f4, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.d); 
    ctx->f4.fl = CVT_S_D(ctx->f30.d);
    // 0x800BE29C: b           L_800BE2B0
    // 0x800BE2A0: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
        goto L_800BE2B0;
    // 0x800BE2A0: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
L_800BE2A4:
    // 0x800BE2A4: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800BE2A8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800BE2AC: sw          $t2, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r10;
L_800BE2B0:
    // 0x800BE2B0: sll         $t3, $s0, 3
    ctx->r11 = S32(ctx->r16 << 3);
    // 0x800BE2B4: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x800BE2B8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BE2BC: lw          $t4, 0x3668($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3668);
    // 0x800BE2C0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800BE2C4: sw          $t3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r11;
    // 0x800BE2C8: addu        $a2, $t4, $t3
    ctx->r6 = ADD32(ctx->r12, ctx->r11);
    // 0x800BE2CC: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
    // 0x800BE2D0: lh          $t1, 0x8($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X8);
    // 0x800BE2D4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800BE2D8: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800BE2DC: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BE2E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BE2E4: lwc1        $f14, 0x380($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X380);
    // 0x800BE2E8: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800BE2EC: lwc1        $f16, 0x384($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X384);
    // 0x800BE2F0: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BE2F4: lwc1        $f18, 0x388($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X388);
    // 0x800BE2F8: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE2FC: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800BE300: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800BE304: sub.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800BE308: bc1f        L_800BE318
    if (!c1cs) {
        // 0x800BE30C: sub.s       $f18, $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f2.fl;
            goto L_800BE318;
    }
    // 0x800BE30C: sub.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800BE310: b           L_800BE34C
    // 0x800BE314: sw          $zero, 0x368($sp)
    MEM_W(0X368, ctx->r29) = 0;
        goto L_800BE34C;
    // 0x800BE314: sw          $zero, 0x368($sp)
    MEM_W(0X368, ctx->r29) = 0;
L_800BE318:
    // 0x800BE318: nop

    // 0x800BE31C: div.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800BE320: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800BE324: nop

    // 0x800BE328: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800BE32C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE330: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE334: nop

    // 0x800BE338: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE33C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800BE340: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800BE344: sw          $t8, 0x368($sp)
    MEM_W(0X368, ctx->r29) = ctx->r24;
    // 0x800BE348: nop

L_800BE34C:
    // 0x800BE34C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800BE350: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE354: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x800BE358: nop

    // 0x800BE35C: bc1f        L_800BE370
    if (!c1cs) {
        // 0x800BE360: nop
    
            goto L_800BE370;
    }
    // 0x800BE360: nop

    // 0x800BE364: b           L_800BE3A0
    // 0x800BE368: sw          $zero, 0x364($sp)
    MEM_W(0X364, ctx->r29) = 0;
        goto L_800BE3A0;
    // 0x800BE368: sw          $zero, 0x364($sp)
    MEM_W(0X364, ctx->r29) = 0;
    // 0x800BE36C: nop

L_800BE370:
    // 0x800BE370: div.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800BE374: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BE378: nop

    // 0x800BE37C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BE380: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE384: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE388: nop

    // 0x800BE38C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE390: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800BE394: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BE398: sw          $t2, 0x364($sp)
    MEM_W(0X364, ctx->r29) = ctx->r10;
    // 0x800BE39C: nop

L_800BE3A0:
    // 0x800BE3A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE3A4: lwc1        $f8, -0x59A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800BE3A8: lw          $t3, 0x36C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE3AC: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x800BE3B0: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE3B4: bc1f        L_800BE3C8
    if (!c1cs) {
        // 0x800BE3B8: nop
    
            goto L_800BE3C8;
    }
    // 0x800BE3B8: nop

    // 0x800BE3BC: b           L_800BE3F8
    // 0x800BE3C0: sw          $t3, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r11;
        goto L_800BE3F8;
    // 0x800BE3C0: sw          $t3, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r11;
    // 0x800BE3C4: nop

L_800BE3C8:
    // 0x800BE3C8: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800BE3CC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BE3D0: nop

    // 0x800BE3D4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BE3D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE3DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE3E0: nop

    // 0x800BE3E4: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE3E8: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800BE3EC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BE3F0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800BE3F4: sw          $t6, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r14;
L_800BE3F8:
    // 0x800BE3F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE3FC: lwc1        $f8, -0x599C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800BE400: lw          $t7, 0x36C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE404: c.le.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl <= ctx->f18.fl;
    // 0x800BE408: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE40C: bc1f        L_800BE420
    if (!c1cs) {
        // 0x800BE410: nop
    
            goto L_800BE420;
    }
    // 0x800BE410: nop

    // 0x800BE414: b           L_800BE450
    // 0x800BE418: sw          $t7, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r15;
        goto L_800BE450;
    // 0x800BE418: sw          $t7, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r15;
    // 0x800BE41C: nop

L_800BE420:
    // 0x800BE420: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800BE424: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BE428: nop

    // 0x800BE42C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BE430: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE434: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE438: nop

    // 0x800BE43C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE440: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BE444: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BE448: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800BE44C: sw          $t2, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r10;
L_800BE450:
    // 0x800BE450: lh          $t3, 0x12($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X12);
    // 0x800BE454: lw          $t4, 0x368($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X368);
    // 0x800BE458: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x800BE45C: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x800BE460: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE464: bne         $at, $zero, L_800BE47C
    if (ctx->r1 != 0) {
        // 0x800BE468: nop
    
            goto L_800BE47C;
    }
    // 0x800BE468: nop

L_800BE46C:
    // 0x800BE46C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800BE470: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE474: beq         $at, $zero, L_800BE46C
    if (ctx->r1 == 0) {
        // 0x800BE478: nop
    
            goto L_800BE46C;
    }
    // 0x800BE478: nop

L_800BE47C:
    // 0x800BE47C: lh          $t5, 0x10($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X10);
    // 0x800BE480: lw          $t6, 0x364($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X364);
    // 0x800BE484: lw          $t7, 0x364($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X364);
    // 0x800BE488: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x800BE48C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE490: bne         $at, $zero, L_800BE4AC
    if (ctx->r1 != 0) {
        // 0x800BE494: lw          $t8, 0x354($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X354);
            goto L_800BE4AC;
    }
    // 0x800BE494: lw          $t8, 0x354($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X354);
L_800BE498:
    // 0x800BE498: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800BE49C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE4A0: beq         $at, $zero, L_800BE498
    if (ctx->r1 == 0) {
        // 0x800BE4A4: nop
    
            goto L_800BE498;
    }
    // 0x800BE4A4: nop

    // 0x800BE4A8: lw          $t8, 0x354($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X354);
L_800BE4AC:
    // 0x800BE4AC: or          $s6, $t7, $zero
    ctx->r22 = ctx->r15 | 0;
    // 0x800BE4B0: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BE4B4: bne         $at, $zero, L_800BE690
    if (ctx->r1 != 0) {
        // 0x800BE4B8: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_800BE690;
    }
    // 0x800BE4B8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800BE4BC: lw          $t3, 0x36C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE4C0: lw          $t9, 0x368($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X368);
    // 0x800BE4C4: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE4C8: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x800BE4CC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800BE4D0: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800BE4D4: addiu       $fp, $fp, 0x35D0
    ctx->r30 = ADD32(ctx->r30, 0X35D0);
    // 0x800BE4D8: sw          $t6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r14;
    // 0x800BE4DC: sw          $v0, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r2;
    // 0x800BE4E0: sw          $v1, 0x350($sp)
    MEM_W(0X350, ctx->r29) = ctx->r3;
    // 0x800BE4E4: sw          $s0, 0x370($sp)
    MEM_W(0X370, ctx->r29) = ctx->r16;
    // 0x800BE4E8: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x800BE4EC: mflo        $t4
    ctx->r12 = lo;
    // 0x800BE4F0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800BE4F4: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
L_800BE4F8:
    // 0x800BE4F8: lw          $v0, 0x34C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34C);
    // 0x800BE4FC: lw          $t3, 0x358($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X358);
    // 0x800BE500: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE504: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BE508: sll         $t2, $s7, 1
    ctx->r10 = S32(ctx->r23 << 1);
    // 0x800BE50C: addiu       $t4, $sp, 0xD8
    ctx->r12 = ADD32(ctx->r29, 0XD8);
    // 0x800BE510: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BE514: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800BE518: addu        $s3, $t2, $t4
    ctx->r19 = ADD32(ctx->r10, ctx->r12);
    // 0x800BE51C: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x800BE520: addiu       $s5, $t3, 0x1
    ctx->r21 = ADD32(ctx->r11, 0X1);
    // 0x800BE524: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800BE528: mflo        $t7
    ctx->r15 = lo;
    // 0x800BE52C: addu        $s2, $t7, $v1
    ctx->r18 = ADD32(ctx->r15, ctx->r3);
    // 0x800BE530: bne         $at, $zero, L_800BE658
    if (ctx->r1 != 0) {
        // 0x800BE534: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800BE658;
    }
L_800BE534:
    // 0x800BE534: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BE538: lw          $t5, 0x35D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X35D4);
    // 0x800BE53C: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x800BE540: addu        $v1, $t5, $t8
    ctx->r3 = ADD32(ctx->r13, ctx->r24);
    // 0x800BE544: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800BE548: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800BE54C: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x800BE550: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800BE554: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x800BE558: addu        $t3, $v0, $t4
    ctx->r11 = ADD32(ctx->r2, ctx->r12);
    // 0x800BE55C: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x800BE560: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BE564: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800BE568: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x800BE56C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800BE570: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BE574: lw          $t5, 0x3718($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3718);
    // 0x800BE578: mul.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800BE57C: blez        $t5, L_800BE5B0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800BE580: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800BE5B0;
    }
    // 0x800BE580: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800BE584: lw          $a0, 0x370($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X370);
    // 0x800BE588: jal         0x800BF4E4
    // 0x800BE58C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    waves_get_y(rdram, ctx);
        goto after_0;
    // 0x800BE58C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_0:
    // 0x800BE590: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800BE594: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BE598: lw          $t8, 0x3668($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3668);
    // 0x800BE59C: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800BE5A0: addiu       $a3, $a3, -0x5A78
    ctx->r7 = ADD32(ctx->r7, -0X5A78);
    // 0x800BE5A4: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x800BE5A8: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x800BE5AC: addu        $a2, $t8, $t6
    ctx->r6 = ADD32(ctx->r24, ctx->r14);
L_800BE5B0:
    // 0x800BE5B0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BE5B4: lw          $t9, 0x3708($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3708);
    // 0x800BE5B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800BE5BC: addu        $t7, $t9, $s4
    ctx->r15 = ADD32(ctx->r25, ctx->r20);
    // 0x800BE5C0: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800BE5C4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800BE5C8: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800BE5CC: beq         $at, $zero, L_800BE5F0
    if (ctx->r1 == 0) {
        // 0x800BE5D0: nop
    
            goto L_800BE5F0;
    }
    // 0x800BE5D0: nop

    // 0x800BE5D4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BE5D8: lwc1        $f8, 0x44($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X44);
    // 0x800BE5DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE5E0: mul.s       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800BE5E4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BE5E8: mul.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800BE5EC: nop

L_800BE5F0:
    // 0x800BE5F0: mul.s       $f6, $f20, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800BE5F4: lh          $t2, 0x6($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X6);
    // 0x800BE5F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BE5FC: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800BE600: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BE604: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800BE608: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BE60C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE610: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE614: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE618: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE61C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BE620: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800BE624: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BE628: addu        $t6, $t2, $t8
    ctx->r14 = ADD32(ctx->r10, ctx->r24);
    // 0x800BE62C: bne         $at, $zero, L_800BE63C
    if (ctx->r1 != 0) {
        // 0x800BE630: sh          $t6, -0x2($s3)
        MEM_H(-0X2, ctx->r19) = ctx->r14;
            goto L_800BE63C;
    }
    // 0x800BE630: sh          $t6, -0x2($s3)
    MEM_H(-0X2, ctx->r19) = ctx->r14;
    // 0x800BE634: subu        $s0, $s0, $a0
    ctx->r16 = SUB32(ctx->r16, ctx->r4);
    // 0x800BE638: subu        $s2, $s2, $a0
    ctx->r18 = SUB32(ctx->r18, ctx->r4);
L_800BE63C:
    // 0x800BE63C: bne         $s5, $s1, L_800BE534
    if (ctx->r21 != ctx->r17) {
        // 0x800BE640: nop
    
            goto L_800BE534;
    }
    // 0x800BE640: nop

    // 0x800BE644: lw          $t0, 0x368($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X368);
    // 0x800BE648: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BE64C: lw          $v1, 0x350($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X350);
    // 0x800BE650: lw          $v0, 0x34C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34C);
    // 0x800BE654: nop

L_800BE658:
    // 0x800BE658: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BE65C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BE660: bne         $at, $zero, L_800BE66C
    if (ctx->r1 != 0) {
        // 0x800BE664: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800BE66C;
    }
    // 0x800BE664: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800BE668: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
L_800BE66C:
    // 0x800BE66C: lw          $t9, 0x36C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE670: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x800BE674: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x800BE678: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x800BE67C: bne         $t7, $s6, L_800BE4F8
    if (ctx->r15 != ctx->r22) {
        // 0x800BE680: sw          $v0, 0x34C($sp)
        MEM_W(0X34C, ctx->r29) = ctx->r2;
            goto L_800BE4F8;
    }
    // 0x800BE680: sw          $v0, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r2;
    // 0x800BE684: lh          $t1, 0x8($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X8);
    // 0x800BE688: lw          $s6, 0x364($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X364);
    // 0x800BE68C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_800BE690:
    // 0x800BE690: lw          $t8, 0x364($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X364);
    // 0x800BE694: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE698: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BE69C: lw          $t4, 0x358($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X358);
    // 0x800BE6A0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BE6A4: lw          $t3, 0x368($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X368);
    // 0x800BE6A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800BE6AC: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800BE6B0: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x800BE6B4: sw          $t2, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r10;
    // 0x800BE6B8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BE6BC: nop

    // 0x800BE6C0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BE6C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE6C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE6CC: nop

    // 0x800BE6D0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BE6D4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800BE6D8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BE6DC: lw          $t6, 0x354($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X354);
    // 0x800BE6E0: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    // 0x800BE6E4: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x800BE6E8: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BE6EC: beq         $at, $zero, L_800BEB10
    if (ctx->r1 == 0) {
        // 0x800BE6F0: sra         $a1, $t5, 16
        ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
            goto L_800BEB10;
    }
    // 0x800BE6F0: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800BE6F4: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800BE6F8: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE6FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE700: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BE704: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BE708: nop

    // 0x800BE70C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BE710: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE714: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE718: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE71C: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800BE720: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800BE724: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800BE728: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BE72C: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800BE730: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800BE734: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
L_800BE738:
    // 0x800BE738: addiu       $v0, $s6, 0x1
    ctx->r2 = ADD32(ctx->r22, 0X1);
    // 0x800BE73C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800BE740: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE744: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BE748: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BE74C: lw          $t2, 0x3668($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3668);
    // 0x800BE750: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BE754: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800BE758: nop

    // 0x800BE75C: addu        $a2, $t2, $t8
    ctx->r6 = ADD32(ctx->r10, ctx->r24);
    // 0x800BE760: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BE764: lh          $t4, 0x8($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X8);
    // 0x800BE768: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BE76C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE770: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE774: lh          $t8, 0x4($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X4);
    // 0x800BE778: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BE77C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800BE780: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BE784: addu        $fp, $t4, $t7
    ctx->r30 = ADD32(ctx->r12, ctx->r15);
    // 0x800BE788: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x800BE78C: lw          $t7, 0x358($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X358);
    // 0x800BE790: lw          $t4, 0x368($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X368);
    // 0x800BE794: addu        $s3, $t8, $t6
    ctx->r19 = ADD32(ctx->r24, ctx->r14);
    // 0x800BE798: sll         $t5, $fp, 16
    ctx->r13 = S32(ctx->r30 << 16);
    // 0x800BE79C: sll         $t3, $s3, 16
    ctx->r11 = S32(ctx->r19 << 16);
    // 0x800BE7A0: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BE7A4: sra         $fp, $t5, 16
    ctx->r30 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800BE7A8: sra         $s3, $t3, 16
    ctx->r19 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800BE7AC: beq         $at, $zero, L_800BEAF8
    if (ctx->r1 == 0) {
        // 0x800BE7B0: or          $s1, $t4, $zero
        ctx->r17 = ctx->r12 | 0;
            goto L_800BEAF8;
    }
    // 0x800BE7B0: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800BE7B4: lw          $t9, 0x364($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X364);
    // 0x800BE7B8: lw          $t7, 0x36C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X36C);
    // 0x800BE7BC: subu        $a2, $s6, $t9
    ctx->r6 = SUB32(ctx->r22, ctx->r25);
    // 0x800BE7C0: multu       $a2, $t7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE7C4: sll         $t2, $s7, 2
    ctx->r10 = S32(ctx->r23 << 2);
    // 0x800BE7C8: lw          $t5, 0x374($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X374);
    // 0x800BE7CC: addu        $t2, $t2, $s7
    ctx->r10 = ADD32(ctx->r10, ctx->r23);
    // 0x800BE7D0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800BE7D4: addu        $s0, $t5, $t2
    ctx->r16 = ADD32(ctx->r13, ctx->r10);
    // 0x800BE7D8: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
    // 0x800BE7DC: subu        $t8, $t4, $t4
    ctx->r24 = SUB32(ctx->r12, ctx->r12);
    // 0x800BE7E0: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x800BE7E4: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800BE7E8: addiu       $t3, $sp, 0xD8
    ctx->r11 = ADD32(ctx->r29, 0XD8);
    // 0x800BE7EC: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE7F0: mflo        $a3
    ctx->r7 = lo;
    // 0x800BE7F4: addu        $v0, $t6, $t3
    ctx->r2 = ADD32(ctx->r14, ctx->r11);
    // 0x800BE7F8: sll         $t5, $a3, 1
    ctx->r13 = S32(ctx->r7 << 1);
    // 0x800BE7FC: multu       $t2, $t7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE800: mul.s       $f26, $f0, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800BE804: negu        $at, $t4
    ctx->r1 = SUB32(0, ctx->r12);
    // 0x800BE808: sll         $t3, $at, 1
    ctx->r11 = S32(ctx->r1 << 1);
    // 0x800BE80C: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x800BE810: addu        $s4, $v0, $t5
    ctx->r20 = ADD32(ctx->r2, ctx->r13);
    // 0x800BE814: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800BE818: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x800BE81C: addiu       $t5, $sp, 0xD8
    ctx->r13 = ADD32(ctx->r29, 0XD8);
    // 0x800BE820: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x800BE824: mul.s       $f28, $f26, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x800BE828: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x800BE82C: mflo        $t0
    ctx->r8 = lo;
    // 0x800BE830: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x800BE834: addu        $s5, $v0, $t8
    ctx->r21 = ADD32(ctx->r2, ctx->r24);
    // 0x800BE838: addu        $a0, $t1, $t8
    ctx->r4 = ADD32(ctx->r9, ctx->r24);
L_800BE83C:
    // 0x800BE83C: addiu       $s6, $s1, 0x1
    ctx->r22 = ADD32(ctx->r17, 0X1);
    // 0x800BE840: mtc1        $s6, $f8
    ctx->f8.u32l = ctx->r22;
    // 0x800BE844: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BE848: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE84C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BE850: lw          $t2, 0x3668($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3668);
    // 0x800BE854: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800BE858: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800BE85C: lwc1        $f2, 0xC8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE860: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x800BE864: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BE868: lh          $t4, 0x4($t8)
    ctx->r12 = MEM_H(ctx->r24, 0X4);
    // 0x800BE86C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BE870: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE874: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE878: sh          $s3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r19;
    // 0x800BE87C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BE880: sh          $s3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r19;
    // 0x800BE884: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800BE888: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BE88C: addu        $s2, $t4, $t5
    ctx->r18 = ADD32(ctx->r12, ctx->r13);
    // 0x800BE890: sll         $t2, $s2, 16
    ctx->r10 = S32(ctx->r18 << 16);
    // 0x800BE894: sra         $s2, $t2, 16
    ctx->r18 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800BE898: sh          $s2, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r18;
    // 0x800BE89C: lh          $t8, 0x0($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X0);
    // 0x800BE8A0: nop

    // 0x800BE8A4: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800BE8A8: lh          $t6, 0x0($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X0);
    // 0x800BE8AC: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x800BE8B0: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x800BE8B4: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x800BE8B8: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x800BE8BC: sh          $t3, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r11;
    // 0x800BE8C0: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    // 0x800BE8C4: subu        $t2, $v0, $t5
    ctx->r10 = SUB32(ctx->r2, ctx->r13);
    // 0x800BE8C8: subu        $t4, $v0, $t9
    ctx->r12 = SUB32(ctx->r2, ctx->r25);
    // 0x800BE8CC: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800BE8D0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800BE8D4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE8D8: sh          $a1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r5;
    // 0x800BE8DC: sh          $fp, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r30;
    // 0x800BE8E0: mul.s       $f20, $f4, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BE8E4: sh          $a1, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r5;
    // 0x800BE8E8: sh          $a1, 0x332($sp)
    MEM_H(0X332, ctx->r29) = ctx->r5;
    // 0x800BE8EC: sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
    // 0x800BE8F0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BE8F4: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    // 0x800BE8F8: mul.s       $f22, $f10, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BE8FC: nop

    // 0x800BE900: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800BE904: nop

    // 0x800BE908: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800BE90C: add.s       $f4, $f8, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x800BE910: jal         0x800CA030
    // 0x800BE914: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800BE914: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x800BE918: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BE91C: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x800BE920: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800BE924: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800BE928: lh          $a1, 0x332($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X332);
    // 0x800BE92C: bc1f        L_800BE9A8
    if (!c1cs) {
        // 0x800BE930: nop
    
            goto L_800BE9A8;
    }
    // 0x800BE930: nop

    // 0x800BE934: div.s       $f24, $f30, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x800BE938: lw          $t7, 0x378($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X378);
    // 0x800BE93C: sll         $t8, $s7, 4
    ctx->r24 = S32(ctx->r23 << 4);
    // 0x800BE940: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800BE944: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800BE948: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800BE94C: mul.s       $f2, $f20, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800BE950: nop

    // 0x800BE954: mul.s       $f14, $f26, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x800BE958: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800BE95C: mul.s       $f12, $f22, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x800BE960: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x800BE964: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x800BE968: lh          $t6, -0x14($s0)
    ctx->r14 = MEM_H(ctx->r16, -0X14);
    // 0x800BE96C: lh          $t3, -0x12($s0)
    ctx->r11 = MEM_H(ctx->r16, -0X12);
    // 0x800BE970: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800BE974: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800BE978: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE97C: lh          $t9, -0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, -0X10);
    // 0x800BE980: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BE984: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BE988: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BE98C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800BE990: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BE994: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE998: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800BE99C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800BE9A0: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x800BE9A4: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
L_800BE9A8:
    // 0x800BE9A8: sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
    // 0x800BE9AC: sh          $s3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r19;
    // 0x800BE9B0: sh          $s2, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r18;
    // 0x800BE9B4: lh          $t4, 0x2($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X2);
    // 0x800BE9B8: nop

    // 0x800BE9BC: sh          $t4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r12;
    // 0x800BE9C0: lh          $t5, 0x0($s5)
    ctx->r13 = MEM_H(ctx->r21, 0X0);
    // 0x800BE9C4: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x800BE9C8: sh          $t5, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r13;
    // 0x800BE9CC: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x800BE9D0: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x800BE9D4: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    // 0x800BE9D8: lh          $v0, 0xE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE);
    // 0x800BE9DC: sh          $a1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r5;
    // 0x800BE9E0: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x800BE9E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BE9E8: sh          $fp, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r30;
    // 0x800BE9EC: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BE9F0: sh          $fp, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r30;
    // 0x800BE9F4: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800BE9F8: subu        $t3, $t6, $v0
    ctx->r11 = SUB32(ctx->r14, ctx->r2);
    // 0x800BE9FC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800BEA00: mul.s       $f20, $f10, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BEA04: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800BEA08: sh          $a1, 0x332($sp)
    MEM_H(0X332, ctx->r29) = ctx->r5;
    // 0x800BEA0C: sw          $a0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r4;
    // 0x800BEA10: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BEA14: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    // 0x800BEA18: mul.s       $f22, $f4, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800BEA1C: nop

    // 0x800BEA20: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800BEA24: nop

    // 0x800BEA28: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800BEA2C: add.s       $f6, $f8, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x800BEA30: jal         0x800CA030
    // 0x800BEA34: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800BEA34: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_2:
    // 0x800BEA38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BEA3C: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x800BEA40: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800BEA44: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800BEA48: lh          $a1, 0x332($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X332);
    // 0x800BEA4C: bc1f        L_800BEACC
    if (!c1cs) {
        // 0x800BEA50: sll         $s3, $s2, 16
        ctx->r19 = S32(ctx->r18 << 16);
            goto L_800BEACC;
    }
    // 0x800BEA50: sll         $s3, $s2, 16
    ctx->r19 = S32(ctx->r18 << 16);
    // 0x800BEA54: nop

    // 0x800BEA58: div.s       $f24, $f30, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x800BEA5C: lw          $t9, 0x378($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X378);
    // 0x800BEA60: sll         $t4, $s7, 4
    ctx->r12 = S32(ctx->r23 << 4);
    // 0x800BEA64: addu        $v0, $t9, $t4
    ctx->r2 = ADD32(ctx->r25, ctx->r12);
    // 0x800BEA68: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800BEA6C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800BEA70: mul.s       $f2, $f20, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x800BEA74: nop

    // 0x800BEA78: mul.s       $f14, $f26, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x800BEA7C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800BEA80: mul.s       $f12, $f22, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x800BEA84: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x800BEA88: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x800BEA8C: lh          $t5, -0x14($s0)
    ctx->r13 = MEM_H(ctx->r16, -0X14);
    // 0x800BEA90: lh          $t2, -0x12($s0)
    ctx->r10 = MEM_H(ctx->r16, -0X12);
    // 0x800BEA94: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800BEA98: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800BEA9C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BEAA0: lh          $t7, -0x10($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X10);
    // 0x800BEAA4: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BEAA8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BEAAC: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800BEAB0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800BEAB4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BEAB8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BEABC: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800BEAC0: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800BEAC4: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x800BEAC8: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
L_800BEACC:
    // 0x800BEACC: lw          $t6, 0x358($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X358);
    // 0x800BEAD0: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800BEAD4: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x800BEAD8: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x800BEADC: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x800BEAE0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800BEAE4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800BEAE8: bne         $s6, $t6, L_800BE83C
    if (ctx->r22 != ctx->r14) {
        // 0x800BEAEC: or          $s3, $t8, $zero
        ctx->r19 = ctx->r24 | 0;
            goto L_800BE83C;
    }
    // 0x800BEAEC: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x800BEAF0: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x800BEAF4: nop

L_800BEAF8:
    // 0x800BEAF8: lw          $t9, 0x354($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X354);
    // 0x800BEAFC: sll         $a1, $fp, 16
    ctx->r5 = S32(ctx->r30 << 16);
    // 0x800BEB00: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800BEB04: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800BEB08: bne         $v0, $t9, L_800BE738
    if (ctx->r2 != ctx->r25) {
        // 0x800BEB0C: or          $a1, $t3, $zero
        ctx->r5 = ctx->r11 | 0;
            goto L_800BE738;
    }
    // 0x800BEB0C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
L_800BEB10:
    // 0x800BEB10: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800BEB14: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x800BEB18: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800BEB1C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BEB20: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BEB24: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BEB28: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BEB2C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BEB30: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BEB34: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BEB38: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BEB3C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800BEB40: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BEB44: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x800BEB48: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800BEB4C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800BEB50: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800BEB54: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800BEB58: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800BEB5C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800BEB60: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800BEB64: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800BEB68: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800BEB6C: jr          $ra
    // 0x800BEB70: addiu       $sp, $sp, 0x370
    ctx->r29 = ADD32(ctx->r29, 0X370);
    return;
    // 0x800BEB70: addiu       $sp, $sp, 0x370
    ctx->r29 = ADD32(ctx->r29, 0X370);
;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D79D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D79D4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D79D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D79DC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800D79E0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800D79E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800D79E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D79EC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800D79F0: jal         0x800CF0CC
    // 0x800D79F4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x800D79F4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x800D79F8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D79FC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800D7A00: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800D7A04: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800D7A08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D7A0C: jal         0x800CF128
    // 0x800D7A10: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800D7A10: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x800D7A14: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800D7A18: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800D7A1C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800D7A20: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x800D7A24: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x800D7A28: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x800D7A2C: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x800D7A30: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800D7A34: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800D7A38: bgtz        $t0, L_800D7A98
    if (SIGNED(ctx->r8) > 0) {
        // 0x800D7A3C: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_800D7A98;
    }
    // 0x800D7A3C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800D7A40: bltz        $t0, L_800D7A50
    if (SIGNED(ctx->r8) < 0) {
        // 0x800D7A44: nop
    
            goto L_800D7A50;
    }
    // 0x800D7A44: nop

    // 0x800D7A48: b           L_800D7A9C
    // 0x800D7A4C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_800D7A9C;
    // 0x800D7A4C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800D7A50:
    // 0x800D7A50: bltzl       $t8, L_800D7A9C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800D7A54: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800D7A9C;
    }
    goto skip_0;
    // 0x800D7A54: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x800D7A58: bgtz        $t8, L_800D7A68
    if (SIGNED(ctx->r24) > 0) {
        // 0x800D7A5C: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_800D7A68;
    }
    // 0x800D7A5C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x800D7A60: beql        $t9, $zero, L_800D7A9C
    if (ctx->r25 == 0) {
        // 0x800D7A64: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800D7A9C;
    }
    goto skip_1;
    // 0x800D7A64: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_800D7A68:
    // 0x800D7A68: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800D7A6C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800D7A70: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800D7A74: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x800D7A78: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x800D7A7C: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x800D7A80: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x800D7A84: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x800D7A88: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800D7A8C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800D7A90: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800D7A94: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_800D7A98:
    // 0x800D7A98: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800D7A9C:
    // 0x800D7A9C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800D7AA0: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800D7AA4: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x800D7AA8: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800D7AAC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800D7AB0: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x800D7AB4: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x800D7AB8: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x800D7ABC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800D7AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7AC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D7AC8: jr          $ra
    // 0x800D7ACC: nop

    return;
    // 0x800D7ACC: nop

;}
RECOMP_FUNC void racer_special_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C498: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C49C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8005C4A0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8005C4A4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C4A8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8005C4AC: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8005C4B0: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C4B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C4B8: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8005C4BC: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8005C4C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C4C4: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8005C4C8: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x8005C4CC: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005C4D0: nop

    // 0x8005C4D4: swc1        $f6, -0x24C0($at)
    MEM_W(-0X24C0, ctx->r1) = ctx->f6.u32l;
    // 0x8005C4D8: lw          $t2, 0x118($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X118);
    // 0x8005C4DC: nop

    // 0x8005C4E0: beq         $t2, $zero, L_8005C4F4
    if (ctx->r10 == 0) {
        // 0x8005C4E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005C4F4;
    }
    // 0x8005C4E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C4E8: jal         0x80006AC8
    // 0x8005C4EC: nop

    racer_sound_free(rdram, ctx);
        goto after_0;
    // 0x8005C4EC: nop

    after_0:
    // 0x8005C4F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005C4F4:
    // 0x8005C4F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005C4F8: sb          $zero, -0x24BC($at)
    MEM_B(-0X24BC, ctx->r1) = 0;
    // 0x8005C4FC: jr          $ra
    // 0x8005C500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005C500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002B0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B134: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002B138: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002B13C: sb          $zero, -0x2778($at)
    MEM_B(-0X2778, ctx->r1) = 0;
    // 0x8002B140: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x8002B144: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002B148: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002B14C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002B150: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8002B154: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002B158: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002B15C: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x8002B160: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8002B164: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002B168: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8002B16C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002B170: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002B174: mfc1        $s6, $f4
    ctx->r22 = (int32_t)ctx->f4.u32l;
    // 0x8002B178: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002B17C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002B180: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002B184: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002B188: cvt.w.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    ctx->f6.u32l = CVT_W_S(ctx->f22.fl);
    // 0x8002B18C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002B190: mfc1        $s4, $f6
    ctx->r20 = (int32_t)ctx->f6.u32l;
    // 0x8002B194: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002B198: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8002B19C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8002B1A0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002B1A4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8002B1A8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8002B1AC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8002B1B0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002B1B4: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002B1B8: sw          $a3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r7;
    // 0x8002B1BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002B1C0: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8002B1C4: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x8002B1C8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8002B1CC: jal         0x8002A09C
    // 0x8002B1D0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    get_inside_segment_count_xz(rdram, ctx);
        goto after_0;
    // 0x8002B1D0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8002B1D4: beq         $v0, $zero, L_8002B1E8
    if (ctx->r2 == 0) {
        // 0x8002B1D8: sw          $v0, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->r2;
            goto L_8002B1E8;
    }
    // 0x8002B1D8: sw          $v0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r2;
    // 0x8002B1DC: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002B1E0: bne         $at, $zero, L_8002B1F0
    if (ctx->r1 != 0) {
        // 0x8002B1E4: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8002B1F0;
    }
    // 0x8002B1E4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8002B1E8:
    // 0x8002B1E8: b           L_8002B9BC
    // 0x8002B1EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002B9BC;
    // 0x8002B1EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002B1F0:
    // 0x8002B1F0: blez        $v0, L_8002B6C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002B1F4: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_8002B6C8;
    }
    // 0x8002B1F4: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8002B1F8: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8002B1FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002B200: sw          $s0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r16;
    // 0x8002B204: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x8002B208: sll         $t9, $fp, 2
    ctx->r25 = S32(ctx->r30 << 2);
L_8002B20C:
    // 0x8002B20C: addu        $t1, $sp, $t9
    ctx->r9 = ADD32(ctx->r29, ctx->r25);
    // 0x8002B210: lw          $t1, 0xB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XB0);
    // 0x8002B214: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8002B218: lw          $t3, -0x3178($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3178);
    // 0x8002B21C: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8002B220: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x8002B224: sll         $t6, $t1, 4
    ctx->r14 = S32(ctx->r9 << 4);
    // 0x8002B228: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x8002B22C: lw          $t7, 0x4($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X4);
    // 0x8002B230: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002B234: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8002B238: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B23C: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x8002B240: addu        $ra, $t6, $t7
    ctx->r31 = ADD32(ctx->r14, ctx->r15);
    // 0x8002B244: lh          $t6, 0x6($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X6);
    // 0x8002B248: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x8002B24C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002B250: subu        $a2, $t6, $t0
    ctx->r6 = SUB32(ctx->r14, ctx->r8);
    // 0x8002B254: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002B258: addiu       $a2, $t7, 0x1
    ctx->r6 = ADD32(ctx->r15, 0X1);
    // 0x8002B25C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002B260: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B264: addu        $v1, $a2, $t0
    ctx->r3 = ADD32(ctx->r6, ctx->r8);
    // 0x8002B268: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x8002B26C: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002B270: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002B274: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002B278: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B27C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002B280: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002B284: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8002B288:
    // 0x8002B288: slt         $at, $v1, $s6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002B28C: bne         $at, $zero, L_8002B2AC
    if (ctx->r1 != 0) {
        // 0x8002B290: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002B2AC;
    }
    // 0x8002B290: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B294: slt         $at, $s6, $a0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002B298: bne         $at, $zero, L_8002B2B0
    if (ctx->r1 != 0) {
        // 0x8002B29C: sll         $t7, $v1, 16
        ctx->r15 = S32(ctx->r3 << 16);
            goto L_8002B2B0;
    }
    // 0x8002B29C: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8002B2A0: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002B2A4: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8002B2A8: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
L_8002B2AC:
    // 0x8002B2AC: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
L_8002B2B0:
    // 0x8002B2B0: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B2B4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002B2B8: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B2BC: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002B2C0: slti        $at, $a3, 0x8
    ctx->r1 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x8002B2C4: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8002B2C8: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002B2CC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B2D0: bne         $at, $zero, L_8002B288
    if (ctx->r1 != 0) {
        // 0x8002B2D4: sra         $a1, $t8, 16
        ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8002B288;
    }
    // 0x8002B2D4: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B2D8: lh          $t0, 0x4($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X4);
    // 0x8002B2DC: lh          $t6, 0xA($t2)
    ctx->r14 = MEM_H(ctx->r10, 0XA);
    // 0x8002B2E0: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x8002B2E4: subu        $a2, $t6, $t0
    ctx->r6 = SUB32(ctx->r14, ctx->r8);
    // 0x8002B2E8: sra         $t7, $a2, 3
    ctx->r15 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002B2EC: addiu       $a2, $t7, 0x1
    ctx->r6 = ADD32(ctx->r15, 0X1);
    // 0x8002B2F0: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8002B2F4: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B2F8: addu        $v1, $a2, $t0
    ctx->r3 = ADD32(ctx->r6, ctx->r8);
    // 0x8002B2FC: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002B300: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002B304: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B308: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002B30C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8002B310:
    // 0x8002B310: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B314: bne         $at, $zero, L_8002B334
    if (ctx->r1 != 0) {
        // 0x8002B318: addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
            goto L_8002B334;
    }
    // 0x8002B318: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B31C: slt         $at, $s4, $a0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002B320: bne         $at, $zero, L_8002B338
    if (ctx->r1 != 0) {
        // 0x8002B324: sll         $t7, $v1, 16
        ctx->r15 = S32(ctx->r3 << 16);
            goto L_8002B338;
    }
    // 0x8002B324: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8002B328: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002B32C: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8002B330: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
L_8002B334:
    // 0x8002B334: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
L_8002B338:
    // 0x8002B338: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B33C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B340: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x8002B344: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002B348: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B34C: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002B350: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B354: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B358: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8002B35C: bne         $at, $zero, L_8002B37C
    if (ctx->r1 != 0) {
        // 0x8002B360: or          $a1, $t9, $zero
        ctx->r5 = ctx->r25 | 0;
            goto L_8002B37C;
    }
    // 0x8002B360: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8002B364: slt         $at, $s4, $t6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002B368: bne         $at, $zero, L_8002B37C
    if (ctx->r1 != 0) {
        // 0x8002B36C: nop
    
            goto L_8002B37C;
    }
    // 0x8002B36C: nop

    // 0x8002B370: or          $s1, $s1, $t9
    ctx->r17 = ctx->r17 | ctx->r25;
    // 0x8002B374: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8002B378: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
L_8002B37C:
    // 0x8002B37C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B380: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x8002B384: sra         $v1, $t8, 16
    ctx->r3 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B388: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B38C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8002B390: or          $t8, $a1, $zero
    ctx->r24 = ctx->r5 | 0;
    // 0x8002B394: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x8002B398: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B39C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B3A0: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B3A4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8002B3A8: bne         $at, $zero, L_8002B3C8
    if (ctx->r1 != 0) {
        // 0x8002B3AC: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8002B3C8;
    }
    // 0x8002B3AC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8002B3B0: slt         $at, $s4, $t7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002B3B4: bne         $at, $zero, L_8002B3C8
    if (ctx->r1 != 0) {
        // 0x8002B3B8: nop
    
            goto L_8002B3C8;
    }
    // 0x8002B3B8: nop

    // 0x8002B3BC: or          $s1, $s1, $t6
    ctx->r17 = ctx->r17 | ctx->r14;
    // 0x8002B3C0: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8002B3C4: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
L_8002B3C8:
    // 0x8002B3C8: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B3CC: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8002B3D0: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002B3D4: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B3D8: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8002B3DC: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002B3E0: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002B3E4: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B3E8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B3EC: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002B3F0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8002B3F4: bne         $at, $zero, L_8002B414
    if (ctx->r1 != 0) {
        // 0x8002B3F8: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_8002B414;
    }
    // 0x8002B3F8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8002B3FC: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002B400: bne         $at, $zero, L_8002B414
    if (ctx->r1 != 0) {
        // 0x8002B404: nop
    
            goto L_8002B414;
    }
    // 0x8002B404: nop

    // 0x8002B408: or          $s1, $s1, $t7
    ctx->r17 = ctx->r17 | ctx->r15;
    // 0x8002B40C: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x8002B410: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
L_8002B414:
    // 0x8002B414: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002B418: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8002B41C: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002B420: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8002B424: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8002B428: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8002B42C: sll         $t7, $t6, 17
    ctx->r15 = S32(ctx->r14 << 17);
    // 0x8002B430: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8002B434: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002B438: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002B43C: bne         $a3, $at, L_8002B310
    if (ctx->r7 != ctx->r1) {
        // 0x8002B440: sra         $a0, $t8, 16
        ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
            goto L_8002B310;
    }
    // 0x8002B440: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002B444: lh          $a1, 0x20($ra)
    ctx->r5 = MEM_H(ctx->r31, 0X20);
    // 0x8002B448: nop

    // 0x8002B44C: blez        $a1, L_8002B6AC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002B450: sll         $t6, $s7, 2
        ctx->r14 = S32(ctx->r23 << 2);
            goto L_8002B6AC;
    }
    // 0x8002B450: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
L_8002B454:
    // 0x8002B454: lw          $t9, 0xC($ra)
    ctx->r25 = MEM_W(ctx->r31, 0XC);
    // 0x8002B458: subu        $t6, $t6, $s7
    ctx->r14 = SUB32(ctx->r14, ctx->r23);
    // 0x8002B45C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B460: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8002B464: lw          $t7, -0x3178($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3178);
    // 0x8002B468: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x8002B46C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8002B470: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8002B474: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x8002B478: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8002B47C: lb          $s2, 0x7($t7)
    ctx->r18 = MEM_B(ctx->r15, 0X7);
    // 0x8002B480: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    // 0x8002B484: lh          $t5, 0x2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2);
    // 0x8002B488: lh          $s0, 0x10($v1)
    ctx->r16 = MEM_H(ctx->r3, 0X10);
    // 0x8002B48C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8002B490: beq         $s2, $at, L_8002B4B8
    if (ctx->r18 == ctx->r1) {
        // 0x8002B494: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_8002B4B8;
    }
    // 0x8002B494: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8002B498: beq         $s2, $at, L_8002B4BC
    if (ctx->r18 == ctx->r1) {
        // 0x8002B49C: slt         $at, $a0, $s0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_8002B4BC;
    }
    // 0x8002B49C: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002B4A0: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x8002B4A4: nop

    // 0x8002B4A8: andi        $t8, $t9, 0x300
    ctx->r24 = ctx->r25 & 0X300;
    // 0x8002B4AC: beq         $t8, $zero, L_8002B4BC
    if (ctx->r24 == 0) {
        // 0x8002B4B0: slt         $at, $a0, $s0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_8002B4BC;
    }
    // 0x8002B4B0: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002B4B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8002B4B8:
    // 0x8002B4B8: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
L_8002B4BC:
    // 0x8002B4BC: beq         $at, $zero, L_8002B69C
    if (ctx->r1 == 0) {
        // 0x8002B4C0: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_8002B69C;
    }
    // 0x8002B4C0: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
L_8002B4C4:
    // 0x8002B4C4: lw          $t6, 0x10($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X10);
    // 0x8002B4C8: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x8002B4CC: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8002B4D0: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x8002B4D4: nop

    // 0x8002B4D8: and         $t6, $t8, $s1
    ctx->r14 = ctx->r24 & ctx->r17;
    // 0x8002B4DC: bne         $s1, $t6, L_8002B684
    if (ctx->r17 != ctx->r14) {
        // 0x8002B4E0: nop
    
            goto L_8002B684;
    }
    // 0x8002B4E0: nop

    // 0x8002B4E4: lw          $t7, 0x4($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X4);
    // 0x8002B4E8: sll         $t9, $t2, 4
    ctx->r25 = S32(ctx->r10 << 4);
    // 0x8002B4EC: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x8002B4F0: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x8002B4F4: lbu         $t9, 0x2($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2);
    // 0x8002B4F8: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x8002B4FC: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B500: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x8002B504: lw          $a1, 0x0($ra)
    ctx->r5 = MEM_W(ctx->r31, 0X0);
    // 0x8002B508: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B50C: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x8002B510: lbu         $t7, 0x3($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3);
    // 0x8002B514: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B518: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x8002B51C: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x8002B520: lh          $a3, 0x4($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X4);
    // 0x8002B524: nop

    // 0x8002B528: subu        $a0, $s4, $a3
    ctx->r4 = SUB32(ctx->r20, ctx->r7);
    // 0x8002B52C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002B530: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x8002B534: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x8002B538: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B53C: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x8002B540: subu        $t9, $t0, $a2
    ctx->r25 = SUB32(ctx->r8, ctx->r6);
    // 0x8002B544: subu        $t6, $t1, $a3
    ctx->r14 = SUB32(ctx->r9, ctx->r7);
    // 0x8002B548: mflo        $t8
    ctx->r24 = lo;
    // 0x8002B54C: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x8002B550: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x8002B554: lh          $t4, 0x4($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X4);
    // 0x8002B558: subu        $v1, $s6, $a2
    ctx->r3 = SUB32(ctx->r22, ctx->r6);
    // 0x8002B55C: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B560: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B564: nop

    // 0x8002B568: nop

    // 0x8002B56C: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B570: subu        $t9, $s6, $t0
    ctx->r25 = SUB32(ctx->r22, ctx->r8);
    // 0x8002B574: mflo        $t8
    ctx->r24 = lo;
    // 0x8002B578: subu        $a1, $t7, $t8
    ctx->r5 = SUB32(ctx->r15, ctx->r24);
    // 0x8002B57C: subu        $t7, $t4, $t1
    ctx->r15 = SUB32(ctx->r12, ctx->r9);
    // 0x8002B580: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B584: slti        $t6, $a1, 0x0
    ctx->r14 = SIGNED(ctx->r5) < 0X0 ? 1 : 0;
    // 0x8002B588: xori        $a1, $t6, 0x1
    ctx->r5 = ctx->r14 ^ 0X1;
    // 0x8002B58C: subu        $t9, $s4, $t1
    ctx->r25 = SUB32(ctx->r20, ctx->r9);
    // 0x8002B590: subu        $t6, $t3, $t0
    ctx->r14 = SUB32(ctx->r11, ctx->r8);
    // 0x8002B594: mflo        $t8
    ctx->r24 = lo;
    // 0x8002B598: nop

    // 0x8002B59C: nop

    // 0x8002B5A0: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B5A4: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B5A8: subu        $t6, $t8, $t7
    ctx->r14 = SUB32(ctx->r24, ctx->r15);
    // 0x8002B5AC: slti        $t9, $t6, 0x0
    ctx->r25 = SIGNED(ctx->r14) < 0X0 ? 1 : 0;
    // 0x8002B5B0: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x8002B5B4: bne         $t9, $a1, L_8002B684
    if (ctx->r25 != ctx->r5) {
        // 0x8002B5B8: subu        $t8, $t4, $a3
        ctx->r24 = SUB32(ctx->r12, ctx->r7);
            goto L_8002B684;
    }
    // 0x8002B5B8: subu        $t8, $t4, $a3
    ctx->r24 = SUB32(ctx->r12, ctx->r7);
    // 0x8002B5BC: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B5C0: subu        $t6, $t3, $a2
    ctx->r14 = SUB32(ctx->r11, ctx->r6);
    // 0x8002B5C4: mflo        $t7
    ctx->r15 = lo;
    // 0x8002B5C8: nop

    // 0x8002B5CC: nop

    // 0x8002B5D0: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B5D4: mflo        $t9
    ctx->r25 = lo;
    // 0x8002B5D8: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x8002B5DC: slti        $t6, $t8, 0x0
    ctx->r14 = SIGNED(ctx->r24) < 0X0 ? 1 : 0;
    // 0x8002B5E0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8002B5E4: beq         $a1, $t6, L_8002B684
    if (ctx->r5 == ctx->r14) {
        // 0x8002B5E8: nop
    
            goto L_8002B684;
    }
    // 0x8002B5E8: nop

    // 0x8002B5EC: lw          $t7, 0x14($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X14);
    // 0x8002B5F0: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x8002B5F4: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x8002B5F8: lhu         $t7, 0x0($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0X0);
    // 0x8002B5FC: lw          $t6, 0x18($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X18);
    // 0x8002B600: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8002B604: addu        $v1, $t6, $t9
    ctx->r3 = ADD32(ctx->r14, ctx->r25);
    // 0x8002B608: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002B60C: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002B610: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B614: c.eq.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d == ctx->f8.d;
    // 0x8002B618: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002B61C: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002B620: bc1t        L_8002B684
    if (c1cs) {
        // 0x8002B624: nop
    
            goto L_8002B684;
    }
    // 0x8002B624: nop

    // 0x8002B628: mul.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8002B62C: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x8002B630: addu        $t8, $t8, $s5
    ctx->r24 = ADD32(ctx->r24, ctx->r21);
    // 0x8002B634: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002B638: mul.s       $f18, $f12, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x8002B63C: addiu       $t7, $t7, -0x2958
    ctx->r15 = ADD32(ctx->r15, -0X2958);
    // 0x8002B640: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002B644: addu        $v1, $t8, $t7
    ctx->r3 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B648: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8002B64C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8002B650: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8002B654: slti        $at, $s5, 0x14
    ctx->r1 = SIGNED(ctx->r21) < 0X14 ? 1 : 0;
    // 0x8002B658: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002B65C: sb          $s2, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r18;
    // 0x8002B660: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x8002B664: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8002B668: swc1        $f12, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f12.u32l;
    // 0x8002B66C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8002B670: bne         $at, $zero, L_8002B684
    if (ctx->r1 != 0) {
        // 0x8002B674: swc1        $f10, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
            goto L_8002B684;
    }
    // 0x8002B674: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8002B678: lh          $s7, 0x20($ra)
    ctx->r23 = MEM_H(ctx->r31, 0X20);
    // 0x8002B67C: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x8002B680: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_8002B684:
    // 0x8002B684: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8002B688: slt         $at, $t2, $s0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002B68C: bne         $at, $zero, L_8002B4C4
    if (ctx->r1 != 0) {
        // 0x8002B690: nop
    
            goto L_8002B4C4;
    }
    // 0x8002B690: nop

    // 0x8002B694: lh          $a1, 0x20($ra)
    ctx->r5 = MEM_H(ctx->r31, 0X20);
    // 0x8002B698: nop

L_8002B69C:
    // 0x8002B69C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002B6A0: slt         $at, $s7, $a1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002B6A4: bne         $at, $zero, L_8002B454
    if (ctx->r1 != 0) {
        // 0x8002B6A8: sll         $t6, $s7, 2
        ctx->r14 = S32(ctx->r23 << 2);
            goto L_8002B454;
    }
    // 0x8002B6A8: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
L_8002B6AC:
    // 0x8002B6AC: lw          $t6, 0x108($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X108);
    // 0x8002B6B0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8002B6B4: slt         $at, $fp, $t6
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002B6B8: bne         $at, $zero, L_8002B20C
    if (ctx->r1 != 0) {
        // 0x8002B6BC: sll         $t9, $fp, 2
        ctx->r25 = S32(ctx->r30 << 2);
            goto L_8002B20C;
    }
    // 0x8002B6BC: sll         $t9, $fp, 2
    ctx->r25 = S32(ctx->r30 << 2);
    // 0x8002B6C0: lw          $s0, 0x128($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X128);
    // 0x8002B6C4: nop

L_8002B6C8:
    // 0x8002B6C8: bltz        $s0, L_8002B77C
    if (SIGNED(ctx->r16) < 0) {
        // 0x8002B6CC: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_8002B77C;
    }
    // 0x8002B6CC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8002B6D0: lw          $t3, -0x3178($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3178);
    // 0x8002B6D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002B6D8: lh          $t9, 0x1A($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X1A);
    // 0x8002B6DC: addiu       $t0, $t0, -0x2958
    ctx->r8 = ADD32(ctx->r8, -0X2958);
    // 0x8002B6E0: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002B6E4: beq         $at, $zero, L_8002B77C
    if (ctx->r1 == 0) {
        // 0x8002B6E8: sll         $t7, $s0, 4
        ctx->r15 = S32(ctx->r16 << 4);
            goto L_8002B77C;
    }
    // 0x8002B6E8: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x8002B6EC: sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21 << 2);
    // 0x8002B6F0: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8002B6F4: lw          $t8, 0x4($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X4);
    // 0x8002B6F8: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x8002B6FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002B700: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002B704: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x8002B708: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8002B70C: sb          $t6, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r14;
    // 0x8002B710: addu        $ra, $t8, $t7
    ctx->r31 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B714: lb          $t9, 0x2B($ra)
    ctx->r25 = MEM_B(ctx->r31, 0X2B);
    // 0x8002B718: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002B71C: beq         $t9, $zero, L_8002B754
    if (ctx->r25 == 0) {
        // 0x8002B720: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8002B754;
    }
    // 0x8002B720: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002B724: lw          $t8, -0x26FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26FC);
    // 0x8002B728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002B72C: beq         $t8, $zero, L_8002B754
    if (ctx->r24 == 0) {
        // 0x8002B730: addu        $a3, $v0, $t0
        ctx->r7 = ADD32(ctx->r2, ctx->r8);
            goto L_8002B754;
    }
    // 0x8002B730: addu        $a3, $v0, $t0
    ctx->r7 = ADD32(ctx->r2, ctx->r8);
    // 0x8002B734: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8002B738: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8002B73C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8002B740: jal         0x800BB814
    // 0x8002B744: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    func_800BB2F4(rdram, ctx);
        goto after_1;
    // 0x8002B744: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_1:
    // 0x8002B748: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8002B74C: b           L_8002B778
    // 0x8002B750: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_8002B778;
    // 0x8002B750: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_8002B754:
    // 0x8002B754: lh          $t7, 0x38($ra)
    ctx->r15 = MEM_H(ctx->r31, 0X38);
    // 0x8002B758: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002B75C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8002B760: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002B764: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002B768: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8002B76C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8002B770: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8002B774: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
L_8002B778:
    // 0x8002B778: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_8002B77C:
    // 0x8002B77C: blez        $s5, L_8002B83C
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8002B780: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8002B83C;
    }
    // 0x8002B780: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002B784: andi        $a1, $s5, 0x3
    ctx->r5 = ctx->r21 & 0X3;
    // 0x8002B788: beq         $a1, $zero, L_8002B7C8
    if (ctx->r5 == 0) {
        // 0x8002B78C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8002B7C8;
    }
    // 0x8002B78C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002B790: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002B794: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002B798: addiu       $t7, $t7, -0x2958
    ctx->r15 = ADD32(ctx->r15, -0X2958);
    // 0x8002B79C: addiu       $t9, $t9, -0x27C8
    ctx->r25 = ADD32(ctx->r25, -0X27C8);
    // 0x8002B7A0: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8002B7A4: sll         $t8, $zero, 4
    ctx->r24 = S32(0 << 4);
    // 0x8002B7A8: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B7AC: addu        $v1, $t6, $t9
    ctx->r3 = ADD32(ctx->r14, ctx->r25);
L_8002B7B0:
    // 0x8002B7B0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002B7B4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002B7B8: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x8002B7BC: bne         $a0, $a3, L_8002B7B0
    if (ctx->r4 != ctx->r7) {
        // 0x8002B7C0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8002B7B0;
    }
    // 0x8002B7C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002B7C4: beq         $a3, $s5, L_8002B83C
    if (ctx->r7 == ctx->r21) {
        // 0x8002B7C8: sll         $t6, $s5, 2
        ctx->r14 = S32(ctx->r21 << 2);
            goto L_8002B83C;
    }
L_8002B7C8:
    // 0x8002B7C8: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8002B7CC: addu        $t6, $t6, $s5
    ctx->r14 = ADD32(ctx->r14, ctx->r21);
    // 0x8002B7D0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002B7D4: addiu       $t9, $t9, -0x291C
    ctx->r25 = ADD32(ctx->r25, -0X291C);
    // 0x8002B7D8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B7DC: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x8002B7E0: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8002B7E4: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x8002B7E8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002B7EC: addiu       $t9, $t9, -0x2958
    ctx->r25 = ADD32(ctx->r25, -0X2958);
    // 0x8002B7F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B7F4: addu        $v0, $t6, $t9
    ctx->r2 = ADD32(ctx->r14, ctx->r25);
    // 0x8002B7F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002B7FC: addiu       $t7, $t7, -0x27C8
    ctx->r15 = ADD32(ctx->r15, -0X27C8);
    // 0x8002B800: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8002B804: addu        $v1, $t8, $t7
    ctx->r3 = ADD32(ctx->r24, ctx->r15);
    // 0x8002B808: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    // 0x8002B80C: addiu       $a2, $v0, 0x28
    ctx->r6 = ADD32(ctx->r2, 0X28);
    // 0x8002B810: addiu       $a0, $v0, 0x3C
    ctx->r4 = ADD32(ctx->r2, 0X3C);
L_8002B814:
    // 0x8002B814: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
    // 0x8002B818: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8002B81C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002B820: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8002B824: sw          $a2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r6;
    // 0x8002B828: addiu       $a2, $a2, 0x50
    ctx->r6 = ADD32(ctx->r6, 0X50);
    // 0x8002B82C: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x8002B830: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x8002B834: bne         $a0, $t0, L_8002B814
    if (ctx->r4 != ctx->r8) {
        // 0x8002B838: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8002B814;
    }
    // 0x8002B838: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8002B83C:
    // 0x8002B83C: addiu       $t1, $s5, -0x1
    ctx->r9 = ADD32(ctx->r21, -0X1);
    // 0x8002B840: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8002B844:
    // 0x8002B844: blez        $t1, L_8002B998
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8002B848: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8002B998;
    }
    // 0x8002B848: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002B84C: addiu       $v0, $s5, -0x1
    ctx->r2 = ADD32(ctx->r21, -0X1);
    // 0x8002B850: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8002B854: beq         $t8, $zero, L_8002B8A8
    if (ctx->r24 == 0) {
        // 0x8002B858: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_8002B8A8;
    }
    // 0x8002B858: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8002B85C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002B860: addiu       $t6, $t6, -0x27C8
    ctx->r14 = ADD32(ctx->r14, -0X27C8);
    // 0x8002B864: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x8002B868: addu        $v1, $t7, $t6
    ctx->r3 = ADD32(ctx->r15, ctx->r14);
L_8002B86C:
    // 0x8002B86C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8002B870: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8002B874: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B878: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B87C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002B880: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8002B884: nop

    // 0x8002B888: bc1f        L_8002B89C
    if (!c1cs) {
        // 0x8002B88C: nop
    
            goto L_8002B89C;
    }
    // 0x8002B88C: nop

    // 0x8002B890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B894: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8002B898: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
L_8002B89C:
    // 0x8002B89C: bne         $t0, $a3, L_8002B86C
    if (ctx->r8 != ctx->r7) {
        // 0x8002B8A0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8002B86C;
    }
    // 0x8002B8A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002B8A4: beq         $a3, $t1, L_8002B998
    if (ctx->r7 == ctx->r9) {
        // 0x8002B8A8: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8002B998;
    }
L_8002B8A8:
    // 0x8002B8A8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002B8AC: addiu       $t8, $t8, -0x27C8
    ctx->r24 = ADD32(ctx->r24, -0X27C8);
    // 0x8002B8B0: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8002B8B4: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8002B8B8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8002B8BC: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
L_8002B8C0:
    // 0x8002B8C0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8002B8C4: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8002B8C8: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B8CC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B8D0: nop

    // 0x8002B8D4: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8002B8D8: nop

    // 0x8002B8DC: bc1f        L_8002B8F8
    if (!c1cs) {
        // 0x8002B8E0: nop
    
            goto L_8002B8F8;
    }
    // 0x8002B8E0: nop

    // 0x8002B8E4: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8002B8E8: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8002B8EC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B8F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B8F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8002B8F8:
    // 0x8002B8F8: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x8002B8FC: nop

    // 0x8002B900: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B904: nop

    // 0x8002B908: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002B90C: nop

    // 0x8002B910: bc1f        L_8002B92C
    if (!c1cs) {
        // 0x8002B914: nop
    
            goto L_8002B92C;
    }
    // 0x8002B914: nop

    // 0x8002B918: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8002B91C: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x8002B920: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B924: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002B928: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8002B92C:
    // 0x8002B92C: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x8002B930: nop

    // 0x8002B934: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002B938: nop

    // 0x8002B93C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002B940: nop

    // 0x8002B944: bc1f        L_8002B960
    if (!c1cs) {
        // 0x8002B948: nop
    
            goto L_8002B960;
    }
    // 0x8002B948: nop

    // 0x8002B94C: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x8002B950: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8002B954: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B958: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002B95C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8002B960:
    // 0x8002B960: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x8002B964: nop

    // 0x8002B968: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002B96C: nop

    // 0x8002B970: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8002B974: nop

    // 0x8002B978: bc1f        L_8002B98C
    if (!c1cs) {
        // 0x8002B97C: nop
    
            goto L_8002B98C;
    }
    // 0x8002B97C: nop

    // 0x8002B980: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002B984: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8002B988: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
L_8002B98C:
    // 0x8002B98C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8002B990: bne         $v1, $t0, L_8002B8C0
    if (ctx->r3 != ctx->r8) {
        // 0x8002B994: nop
    
            goto L_8002B8C0;
    }
    // 0x8002B994: nop

L_8002B998:
    // 0x8002B998: beq         $a2, $zero, L_8002B844
    if (ctx->r6 == 0) {
        // 0x8002B99C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8002B844;
    }
    // 0x8002B99C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8002B9A0: lw          $t9, 0x134($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X134);
    // 0x8002B9A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002B9A8: addiu       $t6, $t6, -0x27C8
    ctx->r14 = ADD32(ctx->r14, -0X27C8);
    // 0x8002B9AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002B9B0: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8002B9B4: sb          $s5, -0x2778($at)
    MEM_B(-0X2778, ctx->r1) = ctx->r21;
    // 0x8002B9B8: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_8002B9BC:
    // 0x8002B9BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002B9C0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002B9C4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002B9C8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002B9CC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002B9D0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002B9D4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B9D8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002B9DC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002B9E0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8002B9E4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8002B9E8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002B9EC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8002B9F0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8002B9F4: jr          $ra
    // 0x8002B9F8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x8002B9F8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void func_800753D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075630: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80075634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80075638: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8007563C: jal         0x80075B34
    // 0x80075640: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075640: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x80075644: beq         $v0, $zero, L_80075664
    if (ctx->r2 == 0) {
        // 0x80075648: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_80075664;
    }
    // 0x80075648: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007564C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075650: jal         0x80075D44
    // 0x80075654: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80075654: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_1:
    // 0x80075658: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8007565C: b           L_80075920
    // 0x80075660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80075920;
    // 0x80075660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80075664:
    // 0x80075664: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075668: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007566C: addiu       $a2, $a2, 0x7D44
    ctx->r6 = ADD32(ctx->r6, 0X7D44);
    // 0x80075670: addiu       $a1, $a1, 0x7D34
    ctx->r5 = ADD32(ctx->r5, 0X7D34);
    // 0x80075674: jal         0x80076740
    // 0x80075678: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x80075678: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x8007567C: bne         $v0, $zero, L_80075904
    if (ctx->r2 != 0) {
        // 0x80075680: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80075904;
    }
    // 0x80075680: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80075684: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075688: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8007568C: jal         0x80076B7C
    // 0x80075690: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x80075690: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80075694: beq         $v0, $zero, L_800756B4
    if (ctx->r2 == 0) {
        // 0x80075698: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_800756B4;
    }
    // 0x80075698: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8007569C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800756A0: jal         0x80075D44
    // 0x800756A4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_4;
    // 0x800756A4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_4:
    // 0x800756A8: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800756AC: b           L_80075920
    // 0x800756B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80075920;
    // 0x800756B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800756B4:
    // 0x800756B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800756B8: jal         0x80070EDC
    // 0x800756BC: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x800756BC: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_5:
    // 0x800756C0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800756C4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800756C8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800756CC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800756D0: jal         0x80076868
    // 0x800756D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_6;
    // 0x800756D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
    // 0x800756D8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800756DC: jal         0x80075D44
    // 0x800756E0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_7;
    // 0x800756E0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_7:
    // 0x800756E4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800756E8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800756EC: bne         $v1, $zero, L_800758EC
    if (ctx->r3 != 0) {
        // 0x800756F0: lui         $at, 0x4748
        ctx->r1 = S32(0X4748 << 16);
            goto L_800758EC;
    }
    // 0x800756F0: lui         $at, 0x4748
    ctx->r1 = S32(0X4748 << 16);
    // 0x800756F4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800756F8: ori         $at, $at, 0x5353
    ctx->r1 = ctx->r1 | 0X5353;
    // 0x800756FC: bne         $t7, $at, L_800758D8
    if (ctx->r15 != ctx->r1) {
        // 0x80075700: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_800758D8;
    }
    // 0x80075700: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x80075704: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80075708: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007570C: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80075710: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80075714: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x80075718: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x8007571C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80075720: subu        $a3, $t9, $t2
    ctx->r7 = SUB32(ctx->r25, ctx->r10);
    // 0x80075724: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80075728: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8007572C: jal         0x80070EDC
    // 0x80075730: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x80075730: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_8:
    // 0x80075734: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80075738: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007573C: addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
    // 0x80075740: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80075744: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x80075748: lh          $a2, 0x2($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X2);
    // 0x8007574C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80075750: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80075754: jal         0x800CA300
    // 0x80075758: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bcopy(rdram, ctx);
        goto after_9;
    // 0x80075758: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x8007575C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80075760: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80075764: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80075768: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007576C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80075770: beq         $t0, $at, L_800757B0
    if (ctx->r8 == ctx->r1) {
        // 0x80075774: slti        $at, $t0, 0x6
        ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
            goto L_800757B0;
    }
    // 0x80075774: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x80075778: lh          $v0, 0x6($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X6);
    // 0x8007577C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80075780: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80075784: lh          $t7, 0x1A($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X1A);
    // 0x80075788: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8007578C: addu        $a1, $t5, $a3
    ctx->r5 = ADD32(ctx->r13, ctx->r7);
    // 0x80075790: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80075794: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x80075798: jal         0x800CA300
    // 0x8007579C: subu        $a2, $t7, $v0
    ctx->r6 = SUB32(ctx->r15, ctx->r2);
    _bcopy(rdram, ctx);
        goto after_10;
    // 0x8007579C: subu        $a2, $t7, $v0
    ctx->r6 = SUB32(ctx->r15, ctx->r2);
    after_10:
    // 0x800757A0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800757A4: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x800757A8: nop

    // 0x800757AC: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
L_800757B0:
    // 0x800757B0: beq         $at, $zero, L_80075898
    if (ctx->r1 == 0) {
        // 0x800757B4: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80075898;
    }
    // 0x800757B4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800757B8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800757BC: subu        $a2, $a1, $t0
    ctx->r6 = SUB32(ctx->r5, ctx->r8);
    // 0x800757C0: andi        $t8, $a2, 0x3
    ctx->r24 = ctx->r6 & 0X3;
    // 0x800757C4: beq         $t8, $zero, L_8007580C
    if (ctx->r24 == 0) {
        // 0x800757C8: addu        $a0, $t8, $t0
        ctx->r4 = ADD32(ctx->r24, ctx->r8);
            goto L_8007580C;
    }
    // 0x800757C8: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    // 0x800757CC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800757D0: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x800757D4: addu        $v0, $t1, $t6
    ctx->r2 = ADD32(ctx->r9, ctx->r14);
    // 0x800757D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800757DC:
    // 0x800757DC: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x800757E0: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x800757E4: lbu         $t2, 0x5($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X5);
    // 0x800757E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800757EC: addu        $t4, $t3, $a3
    ctx->r12 = ADD32(ctx->r11, ctx->r7);
    // 0x800757F0: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x800757F4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800757F8: sb          $t9, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r25;
    // 0x800757FC: bne         $a0, $v1, L_800757DC
    if (ctx->r4 != ctx->r3) {
        // 0x80075800: sb          $t2, -0x3($v0)
        MEM_B(-0X3, ctx->r2) = ctx->r10;
            goto L_800757DC;
    }
    // 0x80075800: sb          $t2, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r10;
    // 0x80075804: beq         $v1, $a1, L_8007589C
    if (ctx->r3 == ctx->r5) {
        // 0x80075808: lw          $t1, 0x44($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X44);
            goto L_8007589C;
    }
    // 0x80075808: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_8007580C:
    // 0x8007580C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80075810: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80075814: addu        $v0, $t1, $t5
    ctx->r2 = ADD32(ctx->r9, ctx->r13);
    // 0x80075818: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8007581C:
    // 0x8007581C: lh          $t4, 0xA($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XA);
    // 0x80075820: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x80075824: lbu         $t2, 0x8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X8);
    // 0x80075828: lbu         $t3, 0x9($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X9);
    // 0x8007582C: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x80075830: lbu         $t8, 0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5);
    // 0x80075834: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x80075838: addu        $t9, $t6, $a3
    ctx->r25 = ADD32(ctx->r14, ctx->r7);
    // 0x8007583C: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x80075840: lh          $t4, 0x12($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X12);
    // 0x80075844: sb          $t2, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r10;
    // 0x80075848: sb          $t3, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r11;
    // 0x8007584C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80075850: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x80075854: lbu         $t8, 0xD($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XD);
    // 0x80075858: lbu         $t7, 0xC($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC);
    // 0x8007585C: lbu         $t3, 0x11($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X11);
    // 0x80075860: lbu         $t2, 0x10($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X10);
    // 0x80075864: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // 0x80075868: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x8007586C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80075870: addu        $t9, $t6, $a3
    ctx->r25 = ADD32(ctx->r14, ctx->r7);
    // 0x80075874: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x80075878: sh          $t5, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r13;
    // 0x8007587C: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x80075880: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80075884: sb          $t8, -0x7($v0)
    MEM_B(-0X7, ctx->r2) = ctx->r24;
    // 0x80075888: sb          $t7, -0x8($v0)
    MEM_B(-0X8, ctx->r2) = ctx->r15;
    // 0x8007588C: sb          $t3, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r11;
    // 0x80075890: bne         $v1, $a1, L_8007581C
    if (ctx->r3 != ctx->r5) {
        // 0x80075894: sb          $t2, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = ctx->r10;
            goto L_8007581C;
    }
    // 0x80075894: sb          $t2, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r10;
L_80075898:
    // 0x80075898: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
L_8007589C:
    // 0x8007589C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800758A0: addiu       $v0, $t1, 0x4
    ctx->r2 = ADD32(ctx->r9, 0X4);
    // 0x800758A4: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x800758A8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800758AC: sh          $t7, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r15;
    // 0x800758B0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800758B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800758B8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800758BC: addiu       $a3, $a3, 0x7D58
    ctx->r7 = ADD32(ctx->r7, 0X7D58);
    // 0x800758C0: addiu       $a2, $a2, 0x7D48
    ctx->r6 = ADD32(ctx->r6, 0X7D48);
    // 0x800758C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800758C8: jal         0x8007692C
    // 0x800758CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    write_controller_pak_file(rdram, ctx);
        goto after_11;
    // 0x800758CC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_11:
    // 0x800758D0: b           L_800758D8
    // 0x800758D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800758D8;
    // 0x800758D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800758D8:
    // 0x800758D8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800758DC: jal         0x80071380
    // 0x800758E0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_12;
    // 0x800758E0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_12:
    // 0x800758E4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800758E8: nop

L_800758EC:
    // 0x800758EC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800758F0: jal         0x80071380
    // 0x800758F4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_13;
    // 0x800758F4: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_13:
    // 0x800758F8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800758FC: b           L_8007591C
    // 0x80075900: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8007591C;
    // 0x80075900: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80075904:
    // 0x80075904: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80075908: jal         0x80075D44
    // 0x8007590C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_14;
    // 0x8007590C: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_14:
    // 0x80075910: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80075914: nop

    // 0x80075918: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8007591C:
    // 0x8007591C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80075920:
    // 0x80075920: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80075924: jr          $ra
    // 0x80075928: nop

    return;
    // 0x80075928: nop

;}
RECOMP_FUNC void allocate_object_pools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BF8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BF90: lwc1        $f12, 0x56DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X56DC);
    // 0x8000BF94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BF98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BF9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000BFA0: lwc1        $f14, 0x56E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X56E0);
    // 0x8000BFA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8000BFA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000BFAC: jal         0x8001D28C
    // 0x8000BFB0: addiu       $a3, $zero, -0x2000
    ctx->r7 = ADD32(0, -0X2000);
    set_world_shading(rdram, ctx);
        goto after_0;
    // 0x8000BFB0: addiu       $a3, $zero, -0x2000
    ctx->r7 = ADD32(0, -0X2000);
    after_0:
    // 0x8000BFB4: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8000BFB8: ori         $a0, $a0, 0x5800
    ctx->r4 = ctx->r4 | 0X5800;
    // 0x8000BFBC: jal         0x80070DB8
    // 0x8000BFC0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    mempool_new_sub(rdram, ctx);
        goto after_1;
    // 0x8000BFC0: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_1:
    // 0x8000BFC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BFC8: sw          $v0, -0x4C18($at)
    MEM_W(-0X4C18, ctx->r1) = ctx->r2;
    // 0x8000BFCC: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    // 0x8000BFD0: jal         0x80070EDC
    // 0x8000BFD4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x8000BFD4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_2:
    // 0x8000BFD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BFDC: sw          $v0, -0x4BBC($at)
    MEM_W(-0X4BBC, ctx->r1) = ctx->r2;
    // 0x8000BFE0: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x8000BFE4: jal         0x80070EDC
    // 0x8000BFE8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8000BFE8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_3:
    // 0x8000BFEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BFF0: sw          $v0, -0x4C14($at)
    MEM_W(-0X4C14, ctx->r1) = ctx->r2;
    // 0x8000BFF4: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x8000BFF8: jal         0x80070EDC
    // 0x8000BFFC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x8000BFFC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_4:
    // 0x8000C000: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C004: sw          $v0, -0x4C0C($at)
    MEM_W(-0X4C0C, ctx->r1) = ctx->r2;
    // 0x8000C008: addiu       $a0, $zero, 0xE10
    ctx->r4 = ADD32(0, 0XE10);
    // 0x8000C00C: jal         0x80070EDC
    // 0x8000C010: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8000C010: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_5:
    // 0x8000C014: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C018: sw          $v0, -0x4BB4($at)
    MEM_W(-0X4BB4, ctx->r1) = ctx->r2;
    // 0x8000C01C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x8000C020: jal         0x80070EDC
    // 0x8000C024: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x8000C024: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_6:
    // 0x8000C028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C02C: sw          $v0, -0x4BA4($at)
    MEM_W(-0X4BA4, ctx->r1) = ctx->r2;
    // 0x8000C030: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000C034: jal         0x80070EDC
    // 0x8000C038: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x8000C038: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_7:
    // 0x8000C03C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C040: sw          $v0, -0x4B9C($at)
    MEM_W(-0X4B9C, ctx->r1) = ctx->r2;
    // 0x8000C044: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000C048: jal         0x80070EDC
    // 0x8000C04C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x8000C04C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_8:
    // 0x8000C050: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C054: sw          $v0, -0x4B94($at)
    MEM_W(-0X4B94, ctx->r1) = ctx->r2;
    // 0x8000C058: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8000C05C: jal         0x80070EDC
    // 0x8000C060: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_9;
    // 0x8000C060: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_9:
    // 0x8000C064: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C068: sw          $v0, -0x4B98($at)
    MEM_W(-0X4B98, ctx->r1) = ctx->r2;
    // 0x8000C06C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x8000C070: jal         0x80070EDC
    // 0x8000C074: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_10;
    // 0x8000C074: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_10:
    // 0x8000C078: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C07C: sw          $v0, -0x4B7C($at)
    MEM_W(-0X4B7C, ctx->r1) = ctx->r2;
    // 0x8000C080: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8000C084: jal         0x80070EDC
    // 0x8000C088: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_11;
    // 0x8000C088: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_11:
    // 0x8000C08C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C090: sw          $v0, -0x4CB4($at)
    MEM_W(-0X4CB4, ctx->r1) = ctx->r2;
    // 0x8000C094: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x8000C098: jal         0x80070EDC
    // 0x8000C09C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_12;
    // 0x8000C09C: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_12:
    // 0x8000C0A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C0A4: sw          $v0, -0x4A8C($at)
    MEM_W(-0X4A8C, ctx->r1) = ctx->r2;
    // 0x8000C0A8: jal         0x80076EE4
    // 0x8000C0AC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    asset_table_load(rdram, ctx);
        goto after_13;
    // 0x8000C0AC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_13:
    // 0x8000C0B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C0B4: sw          $v0, -0x4BC8($at)
    MEM_W(-0X4BC8, ctx->r1) = ctx->r2;
    // 0x8000C0B8: jal         0x800772DC
    // 0x8000C0BC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    asset_table_size(rdram, ctx);
        goto after_14;
    // 0x8000C0BC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_14:
    // 0x8000C0C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C0C4: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8000C0C8: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x8000C0CC: addiu       $a0, $a0, -0x4BC4
    ctx->r4 = ADD32(ctx->r4, -0X4BC4);
    // 0x8000C0D0: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8000C0D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C0D8: lw          $a1, -0x4BC8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4BC8);
    // 0x8000C0DC: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x8000C0E0: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x8000C0E4: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8000C0E8: nop

    // 0x8000C0EC: bne         $t0, $zero, L_8000C110
    if (ctx->r8 != 0) {
        // 0x8000C0F0: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8000C110;
    }
    // 0x8000C0F0: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_8000C0F4:
    // 0x8000C0F4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8000C0F8: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8000C0FC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8000C100: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8000C104: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8000C108: beq         $t4, $zero, L_8000C0F4
    if (ctx->r12 == 0) {
        // 0x8000C10C: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8000C0F4;
    }
    // 0x8000C10C: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_8000C110:
    // 0x8000C110: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x8000C114: jal         0x80070EDC
    // 0x8000C118: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_15;
    // 0x8000C118: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_15:
    // 0x8000C11C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C120: sw          $v0, -0x4D28($at)
    MEM_W(-0X4D28, ctx->r1) = ctx->r2;
    // 0x8000C124: jal         0x80076EE4
    // 0x8000C128: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    asset_table_load(rdram, ctx);
        goto after_16;
    // 0x8000C128: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_16:
    // 0x8000C12C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C130: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C134: addiu       $a2, $a2, -0x4D18
    ctx->r6 = ADD32(ctx->r6, -0X4D18);
    // 0x8000C138: addiu       $a1, $a1, -0x4D1C
    ctx->r5 = ADD32(ctx->r5, -0X4D1C);
    // 0x8000C13C: sll         $t5, $zero, 2
    ctx->r13 = S32(0 << 2);
    // 0x8000C140: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000C144: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8000C148: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8000C14C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000C150: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8000C154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000C158: beq         $a3, $t7, L_8000C180
    if (ctx->r7 == ctx->r15) {
        // 0x8000C15C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C180;
    }
    // 0x8000C15C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000C160: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
L_8000C164:
    // 0x8000C164: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000C168: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8000C16C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8000C170: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000C174: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8000C178: bne         $a3, $t1, L_8000C164
    if (ctx->r7 != ctx->r9) {
        // 0x8000C17C: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8000C164;
    }
    // 0x8000C17C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
L_8000C180:
    // 0x8000C180: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x8000C184: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x8000C188: sll         $a0, $t2, 2
    ctx->r4 = S32(ctx->r10 << 2);
    // 0x8000C18C: jal         0x80070EDC
    // 0x8000C190: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_17;
    // 0x8000C190: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_17:
    // 0x8000C194: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C198: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C19C: sw          $v0, -0x4C38($at)
    MEM_W(-0X4C38, ctx->r1) = ctx->r2;
    // 0x8000C1A0: addiu       $a2, $a2, -0x4D18
    ctx->r6 = ADD32(ctx->r6, -0X4D18);
    // 0x8000C1A4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8000C1A8: jal         0x80070EDC
    // 0x8000C1AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_18;
    // 0x8000C1AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_18:
    // 0x8000C1B0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000C1B4: addiu       $a2, $a2, -0x4D18
    ctx->r6 = ADD32(ctx->r6, -0X4D18);
    // 0x8000C1B8: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8000C1BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C1C0: addiu       $a0, $a0, -0x4C34
    ctx->r4 = ADD32(ctx->r4, -0X4C34);
    // 0x8000C1C4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8000C1C8: blez        $t4, L_8000C1F4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000C1CC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C1F4;
    }
    // 0x8000C1CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000C1D0:
    // 0x8000C1D0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8000C1D4: nop

    // 0x8000C1D8: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8000C1DC: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8000C1E0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8000C1E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000C1E8: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000C1EC: bne         $at, $zero, L_8000C1D0
    if (ctx->r1 != 0) {
        // 0x8000C1F0: nop
    
            goto L_8000C1D0;
    }
    // 0x8000C1F0: nop

L_8000C1F4:
    // 0x8000C1F4: jal         0x80076EE4
    // 0x8000C1F8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    asset_table_load(rdram, ctx);
        goto after_19;
    // 0x8000C1F8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_19:
    // 0x8000C1FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C200: sw          $v0, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r2;
    // 0x8000C204: jal         0x80076EE4
    // 0x8000C208: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    asset_table_load(rdram, ctx);
        goto after_20;
    // 0x8000C208: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_20:
    // 0x8000C20C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C210: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C214: addiu       $a1, $a1, -0x4D10
    ctx->r5 = ADD32(ctx->r5, -0X4D10);
    // 0x8000C218: addiu       $a0, $a0, -0x4CE0
    ctx->r4 = ADD32(ctx->r4, -0X4CE0);
    // 0x8000C21C: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x8000C220: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000C224: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000C228: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8000C22C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8000C230: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8000C234: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C238: beq         $a3, $t0, L_8000C260
    if (ctx->r7 == ctx->r8) {
        // 0x8000C23C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C260;
    }
    // 0x8000C23C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000C240: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
L_8000C244:
    // 0x8000C244: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000C248: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x8000C24C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8000C250: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8000C254: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8000C258: bne         $a3, $t4, L_8000C244
    if (ctx->r7 != ctx->r12) {
        // 0x8000C25C: addiu       $t1, $v1, 0x1
        ctx->r9 = ADD32(ctx->r3, 0X1);
            goto L_8000C244;
    }
    // 0x8000C25C: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
L_8000C260:
    // 0x8000C260: lw          $v0, 0x104($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X104);
    // 0x8000C264: lw          $t7, 0x108($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X108);
    // 0x8000C268: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000C26C: lw          $t6, -0x4D14($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D14);
    // 0x8000C270: subu        $a1, $t7, $v0
    ctx->r5 = SUB32(ctx->r15, ctx->r2);
    // 0x8000C274: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8000C278: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8000C27C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8000C280: jal         0x8000C2D8
    // 0x8000C284: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    decrypt_magic_codes(rdram, ctx);
        goto after_21;
    // 0x8000C284: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_21:
    // 0x8000C288: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x8000C28C: jal         0x80070EDC
    // 0x8000C290: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_22;
    // 0x8000C290: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_22:
    // 0x8000C294: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C298: sw          $v0, -0x4C28($at)
    MEM_W(-0X4C28, ctx->r1) = ctx->r2;
    // 0x8000C29C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2A0: sb          $zero, -0x4CBC($at)
    MEM_B(-0X4CBC, ctx->r1) = 0;
    // 0x8000C2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2A8: sb          $zero, -0x4B8C($at)
    MEM_B(-0X4B8C, ctx->r1) = 0;
    // 0x8000C2AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2B0: sb          $zero, -0x4B8B($at)
    MEM_B(-0X4B8B, ctx->r1) = 0;
    // 0x8000C2B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000C2B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000C2BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C2C0: jal         0x8000C460
    // 0x8000C2C4: swc1        $f4, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->f4.u32l;
    clear_object_pointers(rdram, ctx);
        goto after_23;
    // 0x8000C2C4: swc1        $f4, -0x4CD8($at)
    MEM_W(-0X4CD8, ctx->r1) = ctx->f4.u32l;
    after_23:
    // 0x8000C2C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C2CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000C2D0: jr          $ra
    // 0x8000C2D4: nop

    return;
    // 0x8000C2D4: nop

;}
RECOMP_FUNC void osScGetCmdQ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800799C4: jr          $ra
    // 0x800799C8: addiu       $v0, $a0, 0x78
    ctx->r2 = ADD32(ctx->r4, 0X78);
    return;
    // 0x800799C8: addiu       $v0, $a0, 0x78
    ctx->r2 = ADD32(ctx->r4, 0X78);
;}
RECOMP_FUNC void has_ghost_to_save(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7B4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B7B8: lbu         $v0, -0x3360($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3360);
    // 0x8001B7BC: jr          $ra
    // 0x8001B7C0: nop

    return;
    // 0x8001B7C0: nop

;}
RECOMP_FUNC void savemenu_load_sources(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086704: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x80086708: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8008670C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80086710: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80086714: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80086718: addiu       $s2, $s2, 0x6FC8
    ctx->r18 = ADD32(ctx->r18, 0X6FC8);
    // 0x8008671C: lw          $s6, 0x6ADC($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X6ADC);
    // 0x80086720: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x80086724: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086728: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008672C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80086730: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80086734: sw          $zero, 0x7194($at)
    MEM_W(0X7194, ctx->r1) = 0;
    // 0x80086738: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008673C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80086740: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086744: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80086748: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008674C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80086750: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80086754: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80086758: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8008675C: addiu       $s4, $s4, 0x6FCC
    ctx->r20 = ADD32(ctx->r20, 0X6FCC);
    // 0x80086760: addiu       $s1, $s1, 0x6AD0
    ctx->r17 = ADD32(ctx->r17, 0X6AD0);
    // 0x80086764: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80086768: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008676C: swc1        $f4, 0x719C($at)
    MEM_W(0X719C, ctx->r1) = ctx->f4.u32l;
L_80086770:
    // 0x80086770: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80086774: nop

    // 0x80086778: lbu         $t7, 0x4B($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4B);
    // 0x8008677C: nop

    // 0x80086780: bne         $t7, $zero, L_8008680C
    if (ctx->r15 != 0) {
        // 0x80086784: nop
    
            goto L_8008680C;
    }
    // 0x80086784: nop

    // 0x80086788: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8008678C: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80086790: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x80086794: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80086798: sb          $s3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r19;
    // 0x8008679C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800867A0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800867A4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800867A8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800867AC: sb          $s3, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r19;
    // 0x800867B0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800867B4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800867B8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800867BC: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x800867C0: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x800867C4: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x800867C8: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x800867CC: sb          $t8, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r24;
    // 0x800867D0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800867D4: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800867D8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800867DC: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x800867E0: jal         0x80073EA4
    // 0x800867E4: sb          $s0, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r16;
    get_game_data_file_size(rdram, ctx);
        goto after_0;
    // 0x800867E4: sb          $s0, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r16;
    after_0:
    // 0x800867E8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800867EC: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800867F0: sll         $t4, $t1, 4
    ctx->r12 = S32(ctx->r9 << 4);
    // 0x800867F4: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x800867F8: sw          $v0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r2;
    // 0x800867FC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80086800: nop

    // 0x80086804: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80086808: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
L_8008680C:
    // 0x8008680C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80086810: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80086814: bne         $s0, $at, L_80086770
    if (ctx->r16 != ctx->r1) {
        // 0x80086818: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80086770;
    }
    // 0x80086818: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8008681C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80086820: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80086824: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x80086828: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8008682C: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x80086830: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x80086834: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80086838: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8008683C: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x80086840: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80086844: jal         0x80073EAC
    // 0x80086848: sb          $s3, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r19;
    get_time_data_file_size(rdram, ctx);
        goto after_1;
    // 0x80086848: sb          $s3, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r19;
    after_1:
    // 0x8008684C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80086850: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80086854: sll         $t1, $t7, 4
    ctx->r9 = S32(ctx->r15 << 4);
    // 0x80086858: addu        $t5, $t9, $t1
    ctx->r13 = ADD32(ctx->r25, ctx->r9);
    // 0x8008685C: sw          $v0, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r2;
    // 0x80086860: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80086864: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80086868: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8008686C: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x80086870: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80086874: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80086878: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x8008687C: sb          $t4, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r12;
    // 0x80086880: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80086884: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80086888: addiu       $t5, $t1, 0x1
    ctx->r13 = ADD32(ctx->r9, 0X1);
    // 0x8008688C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80086890: lw          $s0, 0x7024($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7024);
    // 0x80086894: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x80086898: addiu       $fp, $sp, 0xB4
    ctx->r30 = ADD32(ctx->r29, 0XB4);
L_8008689C:
    // 0x8008689C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800868A0: lw          $t2, 0x6FD8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6FD8);
    // 0x800868A4: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800868A8: beq         $t2, $zero, L_80086BDC
    if (ctx->r10 == 0) {
        // 0x800868AC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80086BDC;
    }
    // 0x800868AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800868B0: sw          $zero, 0x6FD4($at)
    MEM_W(0X6FD4, ctx->r1) = 0;
    // 0x800868B4: addiu       $t8, $sp, 0x60
    ctx->r24 = ADD32(ctx->r29, 0X60);
L_800868B8:
    // 0x800868B8: addiu       $t6, $sp, 0xA4
    ctx->r14 = ADD32(ctx->r29, 0XA4);
    // 0x800868BC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800868C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800868C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800868C8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800868CC: addiu       $a2, $sp, 0xF4
    ctx->r6 = ADD32(ctx->r29, 0XF4);
    // 0x800868D0: jal         0x800760B8
    // 0x800868D4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    get_controller_pak_file_list(rdram, ctx);
        goto after_2;
    // 0x800868D4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_2:
    // 0x800868D8: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800868DC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800868E0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800868E4: bne         $v1, $at, L_800868F8
    if (ctx->r3 != ctx->r1) {
        // 0x800868E8: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_800868F8;
    }
    // 0x800868E8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800868EC: slti        $at, $s7, 0x3
    ctx->r1 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
    // 0x800868F0: bne         $at, $zero, L_800868B8
    if (ctx->r1 != 0) {
        // 0x800868F4: addiu       $t8, $sp, 0x60
        ctx->r24 = ADD32(ctx->r29, 0X60);
            goto L_800868B8;
    }
    // 0x800868F4: addiu       $t8, $sp, 0x60
    ctx->r24 = ADD32(ctx->r29, 0X60);
L_800868F8:
    // 0x800868F8: bne         $v0, $zero, L_80086B68
    if (ctx->r2 != 0) {
        // 0x800868FC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80086B68;
    }
    // 0x800868FC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086900: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80086904: addiu       $s5, $sp, 0xA4
    ctx->r21 = ADD32(ctx->r29, 0XA4);
L_80086908:
    // 0x80086908: lbu         $v0, 0x0($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X0);
    // 0x8008690C: nop

    // 0x80086910: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80086914: bne         $at, $zero, L_80086B44
    if (ctx->r1 != 0) {
        // 0x80086918: slti        $at, $v0, 0x7
        ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
            goto L_80086B44;
    }
    // 0x80086918: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8008691C: beq         $at, $zero, L_80086B44
    if (ctx->r1 == 0) {
        // 0x80086920: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80086B44;
    }
    // 0x80086920: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80086924: addiu       $a0, $a0, 0x6FE0
    ctx->r4 = ADD32(ctx->r4, 0X6FE0);
    // 0x80086928: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8008692C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80086930: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80086934: addiu       $t7, $t3, -0x1
    ctx->r15 = ADD32(ctx->r11, -0X1);
    // 0x80086938: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x8008693C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80086940: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x80086944: sb          $v0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r2;
    // 0x80086948: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8008694C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80086950: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x80086954: addu        $t3, $t2, $t6
    ctx->r11 = ADD32(ctx->r10, ctx->r14);
    // 0x80086958: sb          $zero, 0x6($t3)
    MEM_B(0X6, ctx->r11) = 0;
    // 0x8008695C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80086960: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80086964: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x80086968: addu        $t1, $t7, $t4
    ctx->r9 = ADD32(ctx->r15, ctx->r12);
    // 0x8008696C: sb          $s3, 0x7($t1)
    MEM_B(0X7, ctx->r9) = ctx->r19;
    // 0x80086970: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80086974: sll         $a3, $s3, 2
    ctx->r7 = S32(ctx->r19 << 2);
    // 0x80086978: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8008697C: addu        $t5, $sp, $a3
    ctx->r13 = ADD32(ctx->r29, ctx->r7);
    // 0x80086980: lw          $t5, 0x60($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X60);
    // 0x80086984: sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10 << 4);
    // 0x80086988: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x8008698C: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    // 0x80086990: lbu         $v1, 0x0($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X0);
    // 0x80086994: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80086998: bne         $v1, $at, L_80086A54
    if (ctx->r3 != ctx->r1) {
        // 0x8008699C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80086A54;
    }
    // 0x8008699C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800869A0: addu        $s1, $fp, $a3
    ctx->r17 = ADD32(ctx->r30, ctx->r7);
    // 0x800869A4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800869A8: sw          $t0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r8;
    // 0x800869AC: jal         0x80074074
    // 0x800869B0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    read_game_data_from_controller_pak(rdram, ctx);
        goto after_3;
    // 0x800869B0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_3:
    // 0x800869B4: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x800869B8: bne         $v0, $zero, L_80086A40
    if (ctx->r2 != 0) {
        // 0x800869BC: nop
    
            goto L_80086A40;
    }
    // 0x800869BC: nop

    // 0x800869C0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800869C4: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800869C8: sll         $t4, $t7, 4
    ctx->r12 = S32(ctx->r15 << 4);
    // 0x800869CC: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x800869D0: sw          $s0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r16;
    // 0x800869D4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800869D8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800869DC: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x800869E0: sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // 0x800869E4: sb          $t8, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r24;
    // 0x800869E8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800869EC: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800869F0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800869F4: lh          $t5, 0x0($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X0);
    // 0x800869F8: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800869FC: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x80086A00: sb          $t5, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r13;
    // 0x80086A04: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80086A08: lw          $t1, 0x10($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X10);
    // 0x80086A0C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80086A10: sll         $t3, $t7, 4
    ctx->r11 = S32(ctx->r15 << 4);
    // 0x80086A14: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x80086A18: sltu        $t8, $zero, $t2
    ctx->r24 = 0 < ctx->r10 ? 1 : 0;
    // 0x80086A1C: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x80086A20: sb          $t8, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r24;
    // 0x80086A24: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80086A28: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80086A2C: lw          $t5, 0x50($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X50);
    // 0x80086A30: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80086A34: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x80086A38: b           L_80086B34
    // 0x80086A3C: sh          $t5, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r13;
        goto L_80086B34;
    // 0x80086A3C: sh          $t5, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r13;
L_80086A40:
    // 0x80086A40: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80086A44: nop

    // 0x80086A48: addiu       $t3, $t6, -0x1
    ctx->r11 = ADD32(ctx->r14, -0X1);
    // 0x80086A4C: b           L_80086B34
    // 0x80086A50: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
        goto L_80086B34;
    // 0x80086A50: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
L_80086A54:
    // 0x80086A54: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80086A58: beq         $v1, $at, L_80086A68
    if (ctx->r3 == ctx->r1) {
        // 0x80086A5C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80086A68;
    }
    // 0x80086A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80086A60: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80086A64: bne         $v1, $at, L_80086B34
    if (ctx->r3 != ctx->r1) {
        // 0x80086A68: addiu       $t8, $sp, 0xF4
        ctx->r24 = ADD32(ctx->r29, 0XF4);
            goto L_80086B34;
    }
L_80086A68:
    // 0x80086A68: addiu       $t8, $sp, 0xF4
    ctx->r24 = ADD32(ctx->r29, 0XF4);
    // 0x80086A6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80086A70: addu        $a0, $a3, $t8
    ctx->r4 = ADD32(ctx->r7, ctx->r24);
    // 0x80086A74: bne         $v1, $at, L_80086A80
    if (ctx->r3 != ctx->r1) {
        // 0x80086A78: addu        $s1, $fp, $a3
        ctx->r17 = ADD32(ctx->r30, ctx->r7);
            goto L_80086A80;
    }
    // 0x80086A78: addu        $s1, $fp, $a3
    ctx->r17 = ADD32(ctx->r30, ctx->r7);
    // 0x80086A7C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80086A80:
    // 0x80086A80: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80086A84: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80086A88: sll         $t4, $t1, 4
    ctx->r12 = S32(ctx->r9 << 4);
    // 0x80086A8C: addu        $t2, $t9, $t4
    ctx->r10 = ADD32(ctx->r25, ctx->r12);
    // 0x80086A90: sw          $s0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r16;
    // 0x80086A94: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80086A98: nop

    // 0x80086A9C: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x80086AA0: lbu         $v1, 0x0($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X0);
    // 0x80086AA4: nop

    // 0x80086AA8: beq         $v1, $zero, L_80086AD0
    if (ctx->r3 == 0) {
        // 0x80086AAC: nop
    
            goto L_80086AD0;
    }
    // 0x80086AAC: nop

L_80086AB0:
    // 0x80086AB0: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x80086AB4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80086AB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80086ABC: addu        $t3, $t6, $v0
    ctx->r11 = ADD32(ctx->r14, ctx->r2);
    // 0x80086AC0: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x80086AC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80086AC8: bne         $v1, $zero, L_80086AB0
    if (ctx->r3 != 0) {
        // 0x80086ACC: nop
    
            goto L_80086AB0;
    }
    // 0x80086ACC: nop

L_80086AD0:
    // 0x80086AD0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80086AD4: nop

    // 0x80086AD8: beq         $a0, $zero, L_80086B2C
    if (ctx->r4 == 0) {
        // 0x80086ADC: nop
    
            goto L_80086B2C;
    }
    // 0x80086ADC: nop

    // 0x80086AE0: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x80086AE4: addiu       $t1, $zero, 0x2E
    ctx->r9 = ADD32(0, 0X2E);
    // 0x80086AE8: beq         $t8, $zero, L_80086B2C
    if (ctx->r24 == 0) {
        // 0x80086AEC: nop
    
            goto L_80086B2C;
    }
    // 0x80086AEC: nop

    // 0x80086AF0: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    // 0x80086AF4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80086AF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80086AFC: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80086B00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80086B04: beq         $t9, $zero, L_80086B2C
    if (ctx->r25 == 0) {
        // 0x80086B08: andi        $v1, $t9, 0xFF
        ctx->r3 = ctx->r25 & 0XFF;
            goto L_80086B2C;
    }
    // 0x80086B08: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
L_80086B0C:
    // 0x80086B0C: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x80086B10: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80086B14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80086B18: addu        $t2, $t4, $v0
    ctx->r10 = ADD32(ctx->r12, ctx->r2);
    // 0x80086B1C: lbu         $v1, 0x0($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X0);
    // 0x80086B20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80086B24: bne         $v1, $zero, L_80086B0C
    if (ctx->r3 != 0) {
        // 0x80086B28: nop
    
            goto L_80086B0C;
    }
    // 0x80086B28: nop

L_80086B2C:
    // 0x80086B2C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80086B30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80086B34:
    // 0x80086B34: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80086B38: nop

    // 0x80086B3C: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80086B40: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
L_80086B44:
    // 0x80086B44: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80086B48: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80086B4C: bne         $s3, $at, L_80086908
    if (ctx->r19 != ctx->r1) {
        // 0x80086B50: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80086908;
    }
    // 0x80086B50: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80086B54: jal         0x800763BC
    // 0x80086B58: sw          $t0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r8;
    cpak_free_files(rdram, ctx);
        goto after_4;
    // 0x80086B58: sw          $t0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r8;
    after_4:
    // 0x80086B5C: lw          $t0, 0x138($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X138);
    // 0x80086B60: b           L_80086BDC
    // 0x80086B64: nop

        goto L_80086BDC;
    // 0x80086B64: nop

L_80086B68:
    // 0x80086B68: bne         $v1, $at, L_80086BAC
    if (ctx->r3 != ctx->r1) {
        // 0x80086B6C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80086BAC;
    }
    // 0x80086B6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80086B70: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80086B74: lw          $t3, 0x6FD8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6FD8);
    // 0x80086B78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086B7C: bgez        $t3, L_80086B88
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80086B80: sw          $t6, 0x6FD4($at)
        MEM_W(0X6FD4, ctx->r1) = ctx->r14;
            goto L_80086B88;
    }
    // 0x80086B80: sw          $t6, 0x6FD4($at)
    MEM_W(0X6FD4, ctx->r1) = ctx->r14;
    // 0x80086B84: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80086B88:
    // 0x80086B88: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80086B8C: lw          $t8, 0x702C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X702C);
    // 0x80086B90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80086B94: beq         $t8, $zero, L_80086BDC
    if (ctx->r24 == 0) {
        // 0x80086B98: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80086BDC;
    }
    // 0x80086B98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086B9C: sw          $t1, 0x6FD0($at)
    MEM_W(0X6FD0, ctx->r1) = ctx->r9;
    // 0x80086BA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80086BA4: b           L_80086BDC
    // 0x80086BA8: sw          $zero, 0x702C($at)
    MEM_W(0X702C, ctx->r1) = 0;
        goto L_80086BDC;
    // 0x80086BA8: sw          $zero, 0x702C($at)
    MEM_W(0X702C, ctx->r1) = 0;
L_80086BAC:
    // 0x80086BAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80086BB0: bne         $v1, $at, L_80086BC0
    if (ctx->r3 != ctx->r1) {
        // 0x80086BB4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80086BC0;
    }
    // 0x80086BB4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80086BB8: b           L_80086BDC
    // 0x80086BBC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_80086BDC;
    // 0x80086BBC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80086BC0:
    // 0x80086BC0: lw          $t9, 0x6FD8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6FD8);
    // 0x80086BC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80086BC8: bgez        $t9, L_80086BDC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80086BCC: nop
    
            goto L_80086BDC;
    }
    // 0x80086BCC: nop

    // 0x80086BD0: bne         $v1, $at, L_80086BDC
    if (ctx->r3 != ctx->r1) {
        // 0x80086BD4: nop
    
            goto L_80086BDC;
    }
    // 0x80086BD4: nop

    // 0x80086BD8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80086BDC:
    // 0x80086BDC: beq         $s7, $zero, L_8008689C
    if (ctx->r23 == 0) {
        // 0x80086BE0: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8008689C;
    }
    // 0x80086BE0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80086BE4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80086BE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80086BEC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80086BF0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80086BF4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80086BF8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80086BFC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80086C00: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80086C04: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80086C08: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80086C0C: jr          $ra
    // 0x80086C10: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x80086C10: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void sndp_allocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004384: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80004388: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000438C: addiu       $v1, $v1, -0x33E0
    ctx->r3 = ADD32(ctx->r3, -0X33E0);
    // 0x80004390: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004394: lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X8);
    // 0x80004398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000439C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800043A0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800043A4: lw          $a2, 0x4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4);
    // 0x800043A8: beq         $s0, $zero, L_8000450C
    if (ctx->r16 == 0) {
        // 0x800043AC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000450C;
    }
    // 0x800043AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800043B0: jal         0x800C9F90
    // 0x800043B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800043B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x800043B8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800043BC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800043C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800043C4: addiu       $v1, $v1, -0x33E0
    ctx->r3 = ADD32(ctx->r3, -0X33E0);
    // 0x800043C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800043CC: jal         0x800C8CC0
    // 0x800043D0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800043D0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    after_1:
    // 0x800043D4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800043D8: addiu       $v1, $v1, -0x33E0
    ctx->r3 = ADD32(ctx->r3, -0X33E0);
    // 0x800043DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800043E0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800043E4: beq         $v0, $zero, L_80004408
    if (ctx->r2 == 0) {
        // 0x800043E8: nop
    
            goto L_80004408;
    }
    // 0x800043E8: nop

    // 0x800043EC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800043F0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800043F4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800043F8: nop

    // 0x800043FC: sw          $s0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r16;
    // 0x80004400: b           L_80004418
    // 0x80004404: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
        goto L_80004418;
    // 0x80004404: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
L_80004408:
    // 0x80004408: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000440C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80004410: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x80004414: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
L_80004418:
    // 0x80004418: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000441C: jal         0x800C9F90
    // 0x80004420: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80004420: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_2:
    // 0x80004424: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80004428: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8000442C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80004430: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80004434: lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X4);
    // 0x80004438: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000443C: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x80004440: sltiu       $t0, $t0, 0x1
    ctx->r8 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x80004444: addiu       $a1, $t0, 0x40
    ctx->r5 = ADD32(ctx->r8, 0X40);
    // 0x80004448: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8000444C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80004450: sb          $a1, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r5;
    // 0x80004454: sb          $t1, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r9;
    // 0x80004458: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    // 0x8000445C: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    // 0x80004460: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80004464: lbu         $t3, 0x3($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X3);
    // 0x80004468: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8000446C: andi        $t5, $t3, 0xF0
    ctx->r13 = ctx->r11 & 0XF0;
    // 0x80004470: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x80004474: beq         $t6, $zero, L_800044AC
    if (ctx->r14 == 0) {
        // 0x80004478: sb          $t5, 0x3E($s0)
        MEM_B(0X3E, ctx->r16) = ctx->r13;
            goto L_800044AC;
    }
    // 0x80004478: sb          $t5, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r13;
    // 0x8000447C: lbu         $a0, 0x4($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X4);
    // 0x80004480: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80004484: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80004488: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8000448C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004490: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80004494: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80004498: jal         0x800C9F40
    // 0x8000449C: addiu       $a0, $t7, -0x1770
    ctx->r4 = ADD32(ctx->r15, -0X1770);
    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x8000449C: addiu       $a0, $t7, -0x1770
    ctx->r4 = ADD32(ctx->r15, -0X1770);
    after_3:
    // 0x800044A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800044A4: b           L_800044E0
    // 0x800044A8: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
        goto L_800044E0;
    // 0x800044A8: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_800044AC:
    // 0x800044AC: lbu         $t8, 0x4($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X4);
    // 0x800044B0: lb          $t0, 0x5($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X5);
    // 0x800044B4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800044B8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800044BC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800044C0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800044C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800044C8: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x800044CC: addiu       $a0, $a0, -0x1770
    ctx->r4 = ADD32(ctx->r4, -0X1770);
    // 0x800044D0: jal         0x800C9F40
    // 0x800044D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    alCents2Ratio(rdram, ctx);
        goto after_4;
    // 0x800044D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x800044D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800044DC: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_800044E0:
    // 0x800044E0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800044E4: beq         $a1, $at, L_800044FC
    if (ctx->r5 == ctx->r1) {
        // 0x800044E8: addiu       $t3, $zero, 0x40
        ctx->r11 = ADD32(0, 0X40);
            goto L_800044FC;
    }
    // 0x800044E8: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x800044EC: lbu         $t1, 0x3E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X3E);
    // 0x800044F0: nop

    // 0x800044F4: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x800044F8: sb          $t2, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r10;
L_800044FC:
    // 0x800044FC: addiu       $t4, $zero, 0x7FFF
    ctx->r12 = ADD32(0, 0X7FFF);
    // 0x80004500: sb          $zero, 0x3D($s0)
    MEM_B(0X3D, ctx->r16) = 0;
    // 0x80004504: sb          $t3, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r11;
    // 0x80004508: sh          $t4, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r12;
L_8000450C:
    // 0x8000450C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80004510: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80004514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004518: jr          $ra
    // 0x8000451C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000451C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void update_rocket(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F4B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005F4B4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005F4B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005F4BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005F4C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005F4C4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8005F4C8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8005F4CC: addiu       $a0, $a0, -0x2C10
    ctx->r4 = ADD32(ctx->r4, -0X2C10);
    // 0x8005F4D0: jal         0x8005CC18
    // 0x8005F4D4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005F4D4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8005F4D8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F4DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F4E0: sb          $zero, 0x1EC($a3)
    MEM_B(0X1EC, ctx->r7) = 0;
    // 0x8005F4E4: lb          $t6, 0x3B($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F4E8: lwc1        $f6, 0x7094($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7094);
    // 0x8005F4EC: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x8005F4F0: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x8005F4F4: lwc1        $f7, 0x7090($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X7090);
    // 0x8005F4F8: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x8005F4FC: lh          $t8, 0x16A($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X16A);
    // 0x8005F500: nop

    // 0x8005F504: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
    // 0x8005F508: lwc1        $f4, 0x2C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x8005F50C: nop

    // 0x8005F510: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005F514: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8005F518: nop

    // 0x8005F51C: bc1f        L_8005F544
    if (!c1cs) {
        // 0x8005F520: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005F544;
    }
    // 0x8005F520: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F524: lwc1        $f9, 0x7098($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X7098);
    // 0x8005F528: lwc1        $f8, 0x709C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X709C);
    // 0x8005F52C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8005F530: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005F534: nop

    // 0x8005F538: bc1f        L_8005F544
    if (!c1cs) {
        // 0x8005F53C: nop
    
            goto L_8005F544;
    }
    // 0x8005F53C: nop

    // 0x8005F540: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8005F544:
    // 0x8005F544: lb          $t2, 0x1D8($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X1D8);
    // 0x8005F548: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F54C: bne         $t2, $at, L_8005F58C
    if (ctx->r10 != ctx->r1) {
        // 0x8005F550: lw          $t1, 0x58($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X58);
            goto L_8005F58C;
    }
    // 0x8005F550: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8005F554: jal         0x8002359C
    // 0x8005F558: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005F558: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8005F55C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F560: beq         $v0, $zero, L_8005F588
    if (ctx->r2 == 0) {
        // 0x8005F564: addiu       $a0, $zero, 0x82
        ctx->r4 = ADD32(0, 0X82);
            goto L_8005F588;
    }
    // 0x8005F564: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    // 0x8005F568: jal         0x80021434
    // 0x8005F56C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005F56C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8005F570: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F574: nop

    // 0x8005F578: lb          $t3, 0x1D8($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X1D8);
    // 0x8005F57C: nop

    // 0x8005F580: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005F584: sb          $t4, 0x1D8($a3)
    MEM_B(0X1D8, ctx->r7) = ctx->r12;
L_8005F588:
    // 0x8005F588: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
L_8005F58C:
    // 0x8005F58C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005F590: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8005F594: nop

    // 0x8005F598: bne         $t0, $at, L_8005F5A4
    if (ctx->r8 != ctx->r1) {
        // 0x8005F59C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005F5A4;
    }
    // 0x8005F59C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F5A0: sb          $zero, -0x2470($at)
    MEM_B(-0X2470, ctx->r1) = 0;
L_8005F5A4:
    // 0x8005F5A4: lh          $t5, 0x0($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X0);
    // 0x8005F5A8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F5AC: bne         $v1, $t5, L_8005F62C
    if (ctx->r3 != ctx->r13) {
        // 0x8005F5B0: sb          $zero, 0x1F5($a3)
        MEM_B(0X1F5, ctx->r7) = 0;
            goto L_8005F62C;
    }
    // 0x8005F5B0: sb          $zero, 0x1F5($a3)
    MEM_B(0X1F5, ctx->r7) = 0;
    // 0x8005F5B4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005F5B8: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005F5BC: beq         $v0, $at, L_8005F62C
    if (ctx->r2 == ctx->r1) {
        // 0x8005F5C0: addiu       $t6, $v0, -0x1E
        ctx->r14 = ADD32(ctx->r2, -0X1E);
            goto L_8005F62C;
    }
    // 0x8005F5C0: addiu       $t6, $v0, -0x1E
    ctx->r14 = ADD32(ctx->r2, -0X1E);
    // 0x8005F5C4: bgez        $t6, L_8005F624
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005F5C8: sw          $t6, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r14;
            goto L_8005F624;
    }
    // 0x8005F5C8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8005F5CC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005F5D0: lb          $t8, -0x246F($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X246F);
    // 0x8005F5D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005F5D8: bne         $t8, $zero, L_8005F600
    if (ctx->r24 != 0) {
        // 0x8005F5DC: lw          $v0, 0x50($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X50);
            goto L_8005F600;
    }
    // 0x8005F5DC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8005F5E0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005F5E4: jal         0x8005CCA4
    // 0x8005F5E8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005F5E8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_3:
    // 0x8005F5EC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F5F0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F5F4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8005F5F8: nop

    // 0x8005F5FC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
L_8005F600:
    // 0x8005F600: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005F604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F608: sb          $t9, -0x246F($at)
    MEM_B(-0X246F, ctx->r1) = ctx->r25;
    // 0x8005F60C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005F610: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8005F614: nop

    // 0x8005F618: ori         $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 | 0X8000;
    // 0x8005F61C: b           L_8005F62C
    // 0x8005F620: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8005F62C;
    // 0x8005F620: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8005F624:
    // 0x8005F624: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005F628: sb          $zero, -0x246F($at)
    MEM_B(-0X246F, ctx->r1) = 0;
L_8005F62C:
    // 0x8005F62C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8005F630: sb          $t4, 0x1D6($a3)
    MEM_B(0X1D6, ctx->r7) = ctx->r12;
    // 0x8005F634: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8005F638: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005F63C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8005F640: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005F644: jal         0x800497D4
    // 0x8005F648: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_4;
    // 0x8005F648: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x8005F64C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F650: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F654: lb          $t5, 0x1D7($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1D7);
    // 0x8005F658: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F65C: sb          $t5, 0x1D6($a3)
    MEM_B(0X1D6, ctx->r7) = ctx->r13;
    // 0x8005F660: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8005F664: nop

    // 0x8005F668: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8005F66C: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8005F670: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x8005F674: nop

    // 0x8005F678: sh          $t7, 0x16A($a3)
    MEM_H(0X16A, ctx->r7) = ctx->r15;
    // 0x8005F67C: lh          $t8, 0x3E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3E);
    // 0x8005F680: nop

    // 0x8005F684: sb          $t8, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r24;
    // 0x8005F688: lh          $t9, 0x3C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3C);
    // 0x8005F68C: nop

    // 0x8005F690: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    // 0x8005F694: lb          $t2, 0x187($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X187);
    // 0x8005F698: nop

    // 0x8005F69C: beq         $t2, $zero, L_8005F744
    if (ctx->r10 == 0) {
        // 0x8005F6A0: nop
    
            goto L_8005F744;
    }
    // 0x8005F6A0: nop

    // 0x8005F6A4: lb          $t3, 0x3B($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F6A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F6AC: beq         $t3, $at, L_8005F744
    if (ctx->r11 == ctx->r1) {
        // 0x8005F6B0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8005F744;
    }
    // 0x8005F6B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005F6B4: jal         0x8005CCA4
    // 0x8005F6B8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005F6B8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_5:
    // 0x8005F6BC: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005F6C0: jal         0x80001D04
    // 0x8005F6C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005F6C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005F6C8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005F6CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005F6D0: jal         0x8006A168
    // 0x8005F6D4: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005F6D4: nop

    after_7:
    // 0x8005F6D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F6DC: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8005F6E0: lwc1        $f1, 0x70A0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X70A0);
    // 0x8005F6E4: lwc1        $f0, 0x70A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X70A4);
    // 0x8005F6E8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005F6EC: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005F6F0: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8005F6F4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F6F8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005F6FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005F700: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005F704: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005F708: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005F70C: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x8005F710: sb          $t4, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r12;
    // 0x8005F714: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005F718: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F71C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005F720: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005F724: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8005F728: swc1        $f18, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f18.u32l;
    // 0x8005F72C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8005F730: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005F734: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005F738: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005F73C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005F740: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
L_8005F744:
    // 0x8005F744: lw          $t5, 0x148($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X148);
    // 0x8005F748: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005F74C: beq         $t5, $zero, L_8005F7BC
    if (ctx->r13 == 0) {
        // 0x8005F750: sb          $zero, 0x187($a3)
        MEM_B(0X187, ctx->r7) = 0;
            goto L_8005F7BC;
    }
    // 0x8005F750: sb          $zero, 0x187($a3)
    MEM_B(0X187, ctx->r7) = 0;
    // 0x8005F754: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8005F758: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8005F75C: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005F760: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005F764: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005F768: nop

    // 0x8005F76C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005F770: nop

    // 0x8005F774: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8005F778: jal         0x800CA030
    // 0x8005F77C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005F77C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_8:
    // 0x8005F780: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8005F784: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005F788: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005F78C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8005F790: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8005F794: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F798: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8005F79C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005F7A0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005F7A4: bc1f        L_8005F7BC
    if (!c1cs) {
        // 0x8005F7A8: swc1        $f2, 0x2C($a3)
        MEM_W(0X2C, ctx->r7) = ctx->f2.u32l;
            goto L_8005F7BC;
    }
    // 0x8005F7A8: swc1        $f2, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f2.u32l;
    // 0x8005F7AC: swc1        $f18, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f18.u32l;
    // 0x8005F7B0: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x8005F7B4: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x8005F7B8: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_8005F7BC:
    // 0x8005F7BC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005F7C0: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F7C4: cvt.d.s     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f12.d = CVT_D_S(ctx->f4.fl);
    // 0x8005F7C8: add.d       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f12.d + ctx->f12.d;
    // 0x8005F7CC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005F7D0: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8005F7D4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005F7D8: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x8005F7DC: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    // 0x8005F7E0: lb          $t8, 0x3B($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F7E4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8005F7E8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8005F7EC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005F7F0: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F7F4: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x8005F7F8: nop

    // 0x8005F7FC: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x8005F800: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8005F804: nop

    // 0x8005F808: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8005F80C: addiu       $t5, $t4, -0x11
    ctx->r13 = ADD32(ctx->r12, -0X11);
    // 0x8005F810: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8005F814: nop

    // 0x8005F818: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005F81C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005F820: nop

    // 0x8005F824: bc1f        L_8005F850
    if (!c1cs) {
        // 0x8005F828: nop
    
            goto L_8005F850;
    }
    // 0x8005F828: nop

L_8005F82C:
    // 0x8005F82C: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005F830: swc1        $f10, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f10.u32l;
    // 0x8005F834: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x8005F838: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F83C: nop

    // 0x8005F840: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005F844: nop

    // 0x8005F848: bc1t        L_8005F82C
    if (c1cs) {
        // 0x8005F84C: nop
    
            goto L_8005F82C;
    }
    // 0x8005F84C: nop

L_8005F850:
    // 0x8005F850: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F854: nop

    // 0x8005F858: bc1f        L_8005F884
    if (!c1cs) {
        // 0x8005F85C: nop
    
            goto L_8005F884;
    }
    // 0x8005F85C: nop

L_8005F860:
    // 0x8005F860: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005F864: swc1        $f4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f4.u32l;
    // 0x8005F868: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x8005F86C: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F870: nop

    // 0x8005F874: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F878: nop

    // 0x8005F87C: bc1t        L_8005F860
    if (c1cs) {
        // 0x8005F880: nop
    
            goto L_8005F860;
    }
    // 0x8005F880: nop

L_8005F884:
    // 0x8005F884: lb          $t6, 0x3B($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F888: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F88C: bne         $t6, $at, L_8005F8B4
    if (ctx->r14 != ctx->r1) {
        // 0x8005F890: nop
    
            goto L_8005F8B4;
    }
    // 0x8005F890: nop

    // 0x8005F894: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8005F898: nop

    // 0x8005F89C: bne         $v1, $t8, L_8005F8B4
    if (ctx->r3 != ctx->r24) {
        // 0x8005F8A0: nop
    
            goto L_8005F8B4;
    }
    // 0x8005F8A0: nop

    // 0x8005F8A4: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8005F8A8: swc1        $f18, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f18.u32l;
    // 0x8005F8AC: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8005F8B0: nop

L_8005F8B4:
    // 0x8005F8B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005F8B8: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8005F8BC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005F8C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005F8C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005F8C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F8CC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005F8D0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8005F8D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005F8D8: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    // 0x8005F8DC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8005F8E0: jal         0x800AFC74
    // 0x8005F8E4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    update_vehicle_particles(rdram, ctx);
        goto after_9;
    // 0x8005F8E4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_9:
    // 0x8005F8E8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F8EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F8F0: jal         0x8005D1E8
    // 0x8005F8F4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_10;
    // 0x8005F8F4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_10:
    // 0x8005F8F8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8005F8FC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8005F900: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8005F904: nop

    // 0x8005F908: beq         $t3, $at, L_8005F96C
    if (ctx->r11 == ctx->r1) {
        // 0x8005F90C: nop
    
            goto L_8005F96C;
    }
    // 0x8005F90C: nop

    // 0x8005F910: jal         0x8000BF44
    // 0x8005F914: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    racerfx_get_boost(rdram, ctx);
        goto after_11;
    // 0x8005F914: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_11:
    // 0x8005F918: beq         $v0, $zero, L_8005F96C
    if (ctx->r2 == 0) {
        // 0x8005F91C: nop
    
            goto L_8005F96C;
    }
    // 0x8005F91C: nop

    // 0x8005F920: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8005F924: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x8005F928: beq         $v1, $zero, L_8005F96C
    if (ctx->r3 == 0) {
        // 0x8005F92C: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8005F96C;
    }
    // 0x8005F92C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8005F930: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8005F934: lbu         $t4, 0x72($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X72);
    // 0x8005F938: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005F93C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005F940: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8005F944: sb          $t6, 0x72($v1)
    MEM_B(0X72, ctx->r3) = ctx->r14;
    // 0x8005F948: sb          $t8, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r24;
    // 0x8005F94C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005F950: swc1        $f8, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f8.u32l;
    // 0x8005F954: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005F958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F95C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8005F960: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005F964: jal         0x8000B750
    // 0x8005F968: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8000B750(rdram, ctx);
        goto after_12;
    // 0x8005F968: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
L_8005F96C:
    // 0x8005F96C: jal         0x8001BAFC
    // 0x8005F970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_13;
    // 0x8005F970: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x8005F974: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x8005F978: lw          $a3, 0x64($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X64);
    // 0x8005F97C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8005F980: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005F984: bne         $s0, $t9, L_8005F9B4
    if (ctx->r16 != ctx->r25) {
        // 0x8005F988: addiu       $a1, $a1, -0x2470
        ctx->r5 = ADD32(ctx->r5, -0X2470);
            goto L_8005F9B4;
    }
    // 0x8005F988: addiu       $a1, $a1, -0x2470
    ctx->r5 = ADD32(ctx->r5, -0X2470);
    // 0x8005F98C: lh          $t2, 0x14($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X14);
    // 0x8005F990: nop

    // 0x8005F994: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8005F998: beq         $t3, $zero, L_8005F9B4
    if (ctx->r11 == 0) {
        // 0x8005F99C: nop
    
            goto L_8005F9B4;
    }
    // 0x8005F99C: nop

    // 0x8005F9A0: lb          $t4, 0x3B($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X3B);
    // 0x8005F9A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F9A8: bne         $t4, $at, L_8005F9B4
    if (ctx->r12 != ctx->r1) {
        // 0x8005F9AC: addiu       $t5, $zero, 0x4
        ctx->r13 = ADD32(0, 0X4);
            goto L_8005F9B4;
    }
    // 0x8005F9AC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8005F9B0: sb          $t5, 0x187($a3)
    MEM_B(0X187, ctx->r7) = ctx->r13;
L_8005F9B4:
    // 0x8005F9B4: lb          $t6, 0x1D8($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1D8);
    // 0x8005F9B8: nop

    // 0x8005F9BC: beq         $t6, $zero, L_8005F9E0
    if (ctx->r14 == 0) {
        // 0x8005F9C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005F9E0;
    }
    // 0x8005F9C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005F9C4: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x8005F9C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005F9CC: bne         $t8, $zero, L_8005F9DC
    if (ctx->r24 != 0) {
        // 0x8005F9D0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8005F9DC;
    }
    // 0x8005F9D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8005F9D4: jal         0x8005CD08
    // 0x8005F9D8: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    racer_boss_finish(rdram, ctx);
        goto after_14;
    // 0x8005F9D8: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    after_14:
L_8005F9DC:
    // 0x8005F9DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005F9E0:
    // 0x8005F9E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005F9E4: jr          $ra
    // 0x8005F9E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005F9E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_init_trophycab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034EB0: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80034EB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80034EB8: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80034EBC: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80034EC0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80034EC4: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80034EC8: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x80034ECC: nop

    // 0x80034ED0: sll         $t2, $t1, 10
    ctx->r10 = S32(ctx->r9 << 10);
    // 0x80034ED4: jr          $ra
    // 0x80034ED8: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    return;
    // 0x80034ED8: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void func_8001F450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F484: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001F488: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001F48C: jr          $ra
    // 0x8001F490: sb          $t6, -0x4D2D($at)
    MEM_B(-0X4D2D, ctx->r1) = ctx->r14;
    return;
    // 0x8001F490: sb          $t6, -0x4D2D($at)
    MEM_B(-0X4D2D, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void update_car_velocity_offground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052DBC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80052DC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80052DC4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80052DC8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80052DCC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80052DD0: sb          $zero, 0x33($sp)
    MEM_B(0X33, ctx->r29) = 0;
    // 0x80052DD4: lbu         $t6, 0x1FE($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1FE);
    // 0x80052DD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052DDC: bne         $t6, $at, L_80052DFC
    if (ctx->r14 != ctx->r1) {
        // 0x80052DE0: nop
    
            goto L_80052DFC;
    }
    // 0x80052DE0: nop

    // 0x80052DE4: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x80052DE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052DEC: bne         $t7, $at, L_80052DFC
    if (ctx->r15 != ctx->r1) {
        // 0x80052DF0: addiu       $t8, $zero, 0x3C
        ctx->r24 = ADD32(0, 0X3C);
            goto L_80052DFC;
    }
    // 0x80052DF0: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80052DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80052DF8: sw          $t8, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r24;
L_80052DFC:
    // 0x80052DFC: lbu         $t9, 0x1F0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1F0);
    // 0x80052E00: nop

    // 0x80052E04: beq         $t9, $zero, L_80052E98
    if (ctx->r25 == 0) {
        // 0x80052E08: nop
    
            goto L_80052E98;
    }
    // 0x80052E08: nop

    // 0x80052E0C: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80052E10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052E14: beq         $t0, $at, L_80052E28
    if (ctx->r8 == ctx->r1) {
        // 0x80052E18: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80052E28;
    }
    // 0x80052E18: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80052E1C: lb          $v1, 0x1E1($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1E1);
    // 0x80052E20: b           L_80052E34
    // 0x80052E24: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
        goto L_80052E34;
    // 0x80052E24: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
L_80052E28:
    // 0x80052E28: lw          $v1, -0x254C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X254C);
    // 0x80052E2C: nop

    // 0x80052E30: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
L_80052E34:
    // 0x80052E34: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80052E38: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x80052E3C: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80052E40: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80052E44: lh          $a0, 0x1A4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X1A4);
    // 0x80052E48: lh          $t6, 0x1A0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X1A0);
    // 0x80052E4C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80052E50: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80052E54: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80052E58: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80052E5C: mflo        $t3
    ctx->r11 = lo;
    // 0x80052E60: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80052E64: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x80052E68: bne         $at, $zero, L_80052E7C
    if (ctx->r1 != 0) {
        // 0x80052E6C: sh          $t7, 0x1A0($a1)
        MEM_H(0X1A0, ctx->r5) = ctx->r15;
            goto L_80052E7C;
    }
    // 0x80052E6C: sh          $t7, 0x1A0($a1)
    MEM_H(0X1A0, ctx->r5) = ctx->r15;
    // 0x80052E70: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80052E74: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80052E78: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80052E7C:
    // 0x80052E7C: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x80052E80: beq         $at, $zero, L_80052E8C
    if (ctx->r1 == 0) {
        // 0x80052E84: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80052E8C;
    }
    // 0x80052E84: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80052E88: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80052E8C:
    // 0x80052E8C: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80052E90: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80052E94: sh          $t9, 0x1A4($a1)
    MEM_H(0X1A4, ctx->r5) = ctx->r25;
L_80052E98:
    // 0x80052E98: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80052E9C: nop

    // 0x80052EA0: beq         $v0, $zero, L_80052EB8
    if (ctx->r2 == 0) {
        // 0x80052EA4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80052EB8;
    }
    // 0x80052EA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80052EA8: jal         0x8000488C
    // 0x80052EAC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80052EAC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80052EB0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80052EB4: nop

L_80052EB8:
    // 0x80052EB8: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x80052EBC: nop

    // 0x80052EC0: beq         $v0, $zero, L_80052ED8
    if (ctx->r2 == 0) {
        // 0x80052EC4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80052ED8;
    }
    // 0x80052EC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80052EC8: jal         0x8000488C
    // 0x80052ECC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_1;
    // 0x80052ECC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_1:
    // 0x80052ED0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80052ED4: nop

L_80052ED8:
    // 0x80052ED8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80052EDC: nop

    // 0x80052EE0: beq         $v0, $zero, L_80052EF8
    if (ctx->r2 == 0) {
        // 0x80052EE4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80052EF8;
    }
    // 0x80052EE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80052EE8: jal         0x8000488C
    // 0x80052EEC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x80052EEC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_2:
    // 0x80052EF0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80052EF4: nop

L_80052EF8:
    // 0x80052EF8: lbu         $v0, 0x1FE($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1FE);
    // 0x80052EFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052F00: beq         $v0, $at, L_80052F10
    if (ctx->r2 == ctx->r1) {
        // 0x80052F04: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80052F10;
    }
    // 0x80052F04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052F08: bne         $v0, $at, L_80052F1C
    if (ctx->r2 != ctx->r1) {
        // 0x80052F0C: nop
    
            goto L_80052F1C;
    }
    // 0x80052F0C: nop

L_80052F10:
    // 0x80052F10: lb          $t0, 0x1E1($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X1E1);
    // 0x80052F14: nop

    // 0x80052F18: sb          $t0, 0x1E8($a1)
    MEM_B(0X1E8, ctx->r5) = ctx->r8;
L_80052F1C:
    // 0x80052F1C: lwc1        $f6, 0xC0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC0);
    // 0x80052F20: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80052F24: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80052F28: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80052F2C: c.eq.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d == ctx->f8.d;
    // 0x80052F30: nop

    // 0x80052F34: bc1t        L_800530C4
    if (c1cs) {
        // 0x80052F38: nop
    
            goto L_800530C4;
    }
    // 0x80052F38: nop

    // 0x80052F3C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80052F40: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80052F44: lwc1        $f10, 0x20($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X20);
    // 0x80052F48: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80052F4C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80052F50: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80052F54: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x80052F58: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80052F5C: bc1f        L_80052F78
    if (!c1cs) {
        // 0x80052F60: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80052F78;
    }
    // 0x80052F60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80052F64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80052F68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80052F6C: nop

    // 0x80052F70: swc1        $f18, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f18.u32l;
    // 0x80052F74: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
L_80052F78:
    // 0x80052F78: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80052F7C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80052F80: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80052F84: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x80052F88: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80052F8C: bc1f        L_80052FA0
    if (!c1cs) {
        // 0x80052F90: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80052FA0;
    }
    // 0x80052F90: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80052F94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80052F98: nop

    // 0x80052F9C: swc1        $f4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f4.u32l;
L_80052FA0:
    // 0x80052FA0: lb          $t3, 0x1E1($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X1E1);
    // 0x80052FA4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80052FA8: sb          $t3, 0x1E8($a1)
    MEM_B(0X1E8, ctx->r5) = ctx->r11;
    // 0x80052FAC: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x80052FB0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80052FB4: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    // 0x80052FB8: beq         $t4, $zero, L_80052FEC
    if (ctx->r12 == 0) {
        // 0x80052FBC: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_80052FEC;
    }
    // 0x80052FBC: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x80052FC0: lwc1        $f8, 0x2C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80052FC4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80052FC8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80052FCC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80052FD0: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x80052FD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80052FD8: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80052FDC: swc1        $f6, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f6.u32l;
    // 0x80052FE0: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x80052FE4: nop

    // 0x80052FE8: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
L_80052FEC:
    // 0x80052FEC: beq         $t6, $zero, L_80053028
    if (ctx->r14 == 0) {
        // 0x80052FF0: nop
    
            goto L_80053028;
    }
    // 0x80052FF0: nop

    // 0x80052FF4: lw          $t5, -0x2548($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2548);
    // 0x80052FF8: nop

    // 0x80052FFC: slti        $at, $t5, -0x19
    ctx->r1 = SIGNED(ctx->r13) < -0X19 ? 1 : 0;
    // 0x80053000: beq         $at, $zero, L_80053028
    if (ctx->r1 == 0) {
        // 0x80053004: nop
    
            goto L_80053028;
    }
    // 0x80053004: nop

    // 0x80053008: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8005300C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80053010: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80053014: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80053018: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8005301C: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80053020: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80053024: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
L_80053028:
    // 0x80053028: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005302C: sb          $t7, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r15;
    // 0x80053030: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80053034: lwc1        $f1, 0x6C88($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6C88);
    // 0x80053038: lwc1        $f0, 0x6C8C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6C8C);
    // 0x8005303C: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80053040: mul.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80053044: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80053048: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005304C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80053050: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80053054: mul.d       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80053058: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005305C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80053060: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
    // 0x80053064: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80053068: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8005306C: addiu       $a2, $a2, -0x2588
    ctx->r6 = ADD32(ctx->r6, -0X2588);
    // 0x80053070: swc1        $f4, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f4.u32l;
    // 0x80053074: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80053078: lwc1        $f16, 0x6C94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6C94);
    // 0x8005307C: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80053080: lwc1        $f17, 0x6C90($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6C90);
    // 0x80053084: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80053088: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8005308C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80053090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80053094: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80053098: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x8005309C: lw          $t0, -0x254C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X254C);
    // 0x800530A0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800530A4: lb          $a3, -0x257C($a3)
    ctx->r7 = MEM_B(ctx->r7, -0X257C);
    // 0x800530A8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800530AC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800530B0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800530B4: jal         0x80049520
    // 0x800530B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    rotate_racer_in_water(rdram, ctx);
        goto after_3;
    // 0x800530B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x800530BC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800530C0: nop

L_800530C4:
    // 0x800530C4: lh          $t1, 0x0($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X0);
    // 0x800530C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800530CC: bne         $t1, $at, L_800530E0
    if (ctx->r9 != ctx->r1) {
        // 0x800530D0: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800530E0;
    }
    // 0x800530D0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800530D4: lb          $t2, 0x1E1($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1E1);
    // 0x800530D8: nop

    // 0x800530DC: sb          $t2, 0x1E8($a1)
    MEM_B(0X1E8, ctx->r5) = ctx->r10;
L_800530E0:
    // 0x800530E0: lb          $v0, 0x1D3($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1D3);
    // 0x800530E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800530E8: blez        $v0, L_80053104
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800530EC: addiu       $a2, $a2, -0x252C
        ctx->r6 = ADD32(ctx->r6, -0X252C);
            goto L_80053104;
    }
    // 0x800530EC: addiu       $a2, $a2, -0x252C
    ctx->r6 = ADD32(ctx->r6, -0X252C);
    // 0x800530F0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800530F4: nop

    // 0x800530F8: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x800530FC: b           L_80053108
    // 0x80053100: sb          $t4, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = ctx->r12;
        goto L_80053108;
    // 0x80053100: sb          $t4, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = ctx->r12;
L_80053104:
    // 0x80053104: sb          $zero, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = 0;
L_80053108:
    // 0x80053108: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8005310C: lb          $v0, 0x1E8($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1E8);
    // 0x80053110: lwc1        $f9, 0x6C98($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6C98);
    // 0x80053114: lwc1        $f8, 0x6C9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C9C);
    // 0x80053118: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8005311C: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x80053120: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80053124: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80053128: bc1f        L_80053148
    if (!c1cs) {
        // 0x8005312C: sll         $v0, $t6, 1
        ctx->r2 = S32(ctx->r14 << 1);
            goto L_80053148;
    }
    // 0x8005312C: sll         $v0, $t6, 1
    ctx->r2 = S32(ctx->r14 << 1);
    // 0x80053130: lb          $v0, 0x1E1($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1E1);
    // 0x80053134: nop

    // 0x80053138: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8005313C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80053140: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80053144: sll         $v0, $t5, 1
    ctx->r2 = S32(ctx->r13 << 1);
L_80053148:
    // 0x80053148: lh          $t7, 0x1A0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X1A0);
    // 0x8005314C: lw          $t0, 0x110($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X110);
    // 0x80053150: subu        $t9, $t7, $v0
    ctx->r25 = SUB32(ctx->r15, ctx->r2);
    // 0x80053154: sh          $t9, 0x1A0($a1)
    MEM_H(0X1A0, ctx->r5) = ctx->r25;
    // 0x80053158: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x8005315C: lb          $t1, 0x1D3($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X1D3);
    // 0x80053160: lui         $at, 0xC034
    ctx->r1 = S32(0XC034 << 16);
    // 0x80053164: beq         $t1, $zero, L_800531A4
    if (ctx->r9 == 0) {
        // 0x80053168: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800531A4;
    }
    // 0x80053168: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005316C: lwc1        $f18, 0x2C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80053170: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80053174: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80053178: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8005317C: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80053180: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053184: bc1f        L_800531A4
    if (!c1cs) {
        // 0x80053188: nop
    
            goto L_800531A4;
    }
    // 0x80053188: nop

    // 0x8005318C: lwc1        $f5, 0x6CA0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6CA0);
    // 0x80053190: lwc1        $f4, 0x6CA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6CA4);
    // 0x80053194: nop

    // 0x80053198: sub.d       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f0.d - ctx->f4.d;
    // 0x8005319C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800531A0: swc1        $f8, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f8.u32l;
L_800531A4:
    // 0x800531A4: lw          $v1, -0x2548($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2548);
    // 0x800531A8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800531AC: slti        $at, $v1, 0x32
    ctx->r1 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // 0x800531B0: beq         $at, $zero, L_800531C4
    if (ctx->r1 == 0) {
        // 0x800531B4: slti        $at, $v1, -0x31
        ctx->r1 = SIGNED(ctx->r3) < -0X31 ? 1 : 0;
            goto L_800531C4;
    }
    // 0x800531B4: slti        $at, $v1, -0x31
    ctx->r1 = SIGNED(ctx->r3) < -0X31 ? 1 : 0;
    // 0x800531B8: bne         $at, $zero, L_800531C4
    if (ctx->r1 != 0) {
        // 0x800531BC: nop
    
            goto L_800531C4;
    }
    // 0x800531BC: nop

    // 0x800531C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800531C4:
    // 0x800531C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800531C8: lwc1        $f16, 0x20($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X20);
    // 0x800531CC: lwc1        $f19, 0x6CA8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6CA8);
    // 0x800531D0: lwc1        $f18, 0x6CAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6CAC);
    // 0x800531D4: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x800531D8: mul.d       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800531DC: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800531E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800531E4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800531E8: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800531EC: sub.d       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f0.d - ctx->f8.d;
    // 0x800531F0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800531F4: swc1        $f18, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f18.u32l;
    // 0x800531F8: lbu         $t3, 0x1F1($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X1F1);
    // 0x800531FC: lwc1        $f2, -0x2514($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2514);
    // 0x80053200: bne         $t3, $zero, L_80053218
    if (ctx->r11 != 0) {
        // 0x80053204: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80053218;
    }
    // 0x80053204: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053208: lbu         $t4, 0x1F0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1F0);
    // 0x8005320C: nop

    // 0x80053210: beq         $t4, $zero, L_80053254
    if (ctx->r12 == 0) {
        // 0x80053214: nop
    
            goto L_80053254;
    }
    // 0x80053214: nop

L_80053218:
    // 0x80053218: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8005321C: lh          $t6, 0x160($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X160);
    // 0x80053220: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80053224: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80053228: sll         $t7, $t7, 8
    ctx->r15 = S32(ctx->r15 << 8);
    // 0x8005322C: lwc1        $f2, 0x6CB0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6CB0);
    // 0x80053230: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80053234: sh          $t8, 0x160($a1)
    MEM_H(0X160, ctx->r5) = ctx->r24;
    // 0x80053238: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8005323C: lh          $t9, 0x162($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X162);
    // 0x80053240: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80053244: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80053248: sll         $t1, $t1, 9
    ctx->r9 = S32(ctx->r9 << 9);
    // 0x8005324C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80053250: sh          $t2, 0x162($a1)
    MEM_H(0X162, ctx->r5) = ctx->r10;
L_80053254:
    // 0x80053254: lbu         $v0, 0x1FE($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1FE);
    // 0x80053258: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005325C: beq         $v0, $at, L_80053268
    if (ctx->r2 == ctx->r1) {
        // 0x80053260: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80053268;
    }
    // 0x80053260: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80053264: bne         $v0, $at, L_800532F4
    if (ctx->r2 != ctx->r1) {
        // 0x80053268: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800532F4;
    }
L_80053268:
    // 0x80053268: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005326C: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80053270: lwc1        $f1, 0x6CB8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6CB8);
    // 0x80053274: lwc1        $f0, 0x6CBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6CBC);
    // 0x80053278: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005327C: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80053280: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80053284: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x80053288: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8005328C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80053290: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80053294: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80053298: swc1        $f8, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f8.u32l;
    // 0x8005329C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800532A0: swc1        $f6, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f6.u32l;
    // 0x800532A4: bne         $at, $zero, L_800532CC
    if (ctx->r1 != 0) {
        // 0x800532A8: sb          $t3, 0x33($sp)
        MEM_B(0X33, ctx->r29) = ctx->r11;
            goto L_800532CC;
    }
    // 0x800532A8: sb          $t3, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r11;
    // 0x800532AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800532B0: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800532B4: lwc1        $f17, 0x6CC0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6CC0);
    // 0x800532B8: lwc1        $f16, 0x6CC4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CC4);
    // 0x800532BC: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800532C0: sub.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f8.d - ctx->f16.d;
    // 0x800532C4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800532C8: swc1        $f4, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f4.u32l;
L_800532CC:
    // 0x800532CC: slti        $at, $v1, -0x32
    ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
    // 0x800532D0: beq         $at, $zero, L_800532F4
    if (ctx->r1 == 0) {
        // 0x800532D4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800532F4;
    }
    // 0x800532D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800532D8: lwc1        $f6, 0x2C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800532DC: lwc1        $f9, 0x6CC8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6CC8);
    // 0x800532E0: lwc1        $f8, 0x6CCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6CCC);
    // 0x800532E4: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800532E8: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x800532EC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800532F0: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
L_800532F4:
    // 0x800532F4: lb          $t4, 0x33($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X33);
    // 0x800532F8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800532FC: beq         $t4, $zero, L_80053354
    if (ctx->r12 == 0) {
        // 0x80053300: slti        $at, $v1, 0x33
        ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
            goto L_80053354;
    }
    // 0x80053300: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x80053304: sw          $zero, 0x74($t5)
    MEM_W(0X74, ctx->r13) = 0;
    // 0x80053308: sb          $zero, 0x1E6($a1)
    MEM_B(0X1E6, ctx->r5) = 0;
    // 0x8005330C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80053310: lw          $v0, 0x10C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10C);
    // 0x80053314: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80053318: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005331C: mflo        $t7
    ctx->r15 = lo;
    // 0x80053320: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x80053324: subu        $t0, $v0, $t8
    ctx->r8 = SUB32(ctx->r2, ctx->r24);
    // 0x80053328: sw          $t0, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = ctx->r8;
    // 0x8005332C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80053330: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80053334: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80053338: jal         0x800534B8
    // 0x8005333C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    handle_car_steering(rdram, ctx);
        goto after_4;
    // 0x8005333C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_4:
    // 0x80053340: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80053344: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80053348: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005334C: b           L_80053394
    // 0x80053350: lb          $t9, 0x1D3($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1D3);
        goto L_80053394;
    // 0x80053350: lb          $t9, 0x1D3($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1D3);
L_80053354:
    // 0x80053354: bne         $at, $zero, L_80053370
    if (ctx->r1 != 0) {
        // 0x80053358: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80053370;
    }
    // 0x80053358: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005335C: lwc1        $f7, 0x6CD0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6CD0);
    // 0x80053360: lwc1        $f6, 0x6CD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6CD4);
    // 0x80053364: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80053368: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005336C: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_80053370:
    // 0x80053370: slti        $at, $v1, -0x32
    ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
    // 0x80053374: beq         $at, $zero, L_80053390
    if (ctx->r1 == 0) {
        // 0x80053378: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80053390;
    }
    // 0x80053378: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005337C: lwc1        $f17, 0x6CD8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6CD8);
    // 0x80053380: lwc1        $f16, 0x6CDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CDC);
    // 0x80053384: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80053388: mul.d       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8005338C: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
L_80053390:
    // 0x80053390: lb          $t9, 0x1D3($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1D3);
L_80053394:
    // 0x80053394: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80053398: beq         $t9, $zero, L_800533B8
    if (ctx->r25 == 0) {
        // 0x8005339C: sll         $t1, $v1, 6
        ctx->r9 = S32(ctx->r3 << 6);
            goto L_800533B8;
    }
    // 0x8005339C: sll         $t1, $v1, 6
    ctx->r9 = S32(ctx->r3 << 6);
    // 0x800533A0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800533A4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800533A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800533AC: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800533B0: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800533B4: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_800533B8:
    // 0x800533B8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800533BC: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800533C0: lh          $a0, 0x2($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X2);
    // 0x800533C4: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800533C8: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x800533CC: subu        $v0, $t2, $t4
    ctx->r2 = SUB32(ctx->r10, ctx->r12);
    // 0x800533D0: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800533D4: bne         $at, $zero, L_800533E4
    if (ctx->r1 != 0) {
        // 0x800533D8: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800533E4;
    }
    // 0x800533D8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800533DC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800533E0: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800533E4:
    // 0x800533E4: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x800533E8: beq         $at, $zero, L_800533F4
    if (ctx->r1 == 0) {
        // 0x800533EC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800533F4;
    }
    // 0x800533EC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800533F0: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800533F4:
    // 0x800533F4: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800533F8: sra         $t5, $v0, 3
    ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800533FC: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80053400: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x80053404: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80053408: lwc1        $f8, 0x20($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8005340C: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80053410: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80053414: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80053418: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8005341C: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80053420: swc1        $f4, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f4.u32l;
    // 0x80053424: lwc1        $f10, 0xC0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC0);
    // 0x80053428: nop

    // 0x8005342C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80053430: c.eq.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d == ctx->f16.d;
    // 0x80053434: nop

    // 0x80053438: bc1f        L_800534A0
    if (!c1cs) {
        // 0x8005343C: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_800534A0;
    }
    // 0x8005343C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80053440: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80053444: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80053448: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8005344C: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80053450: mul.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x80053454: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80053458: nop

    // 0x8005345C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80053460: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80053464: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80053468: nop

    // 0x8005346C: cvt.w.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_D(ctx->f6.d);
    // 0x80053470: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80053474: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80053478: slti        $at, $v1, 0x32
    ctx->r1 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // 0x8005347C: beq         $at, $zero, L_8005348C
    if (ctx->r1 == 0) {
        // 0x80053480: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_8005348C;
    }
    // 0x80053480: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x80053484: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x80053488: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
L_8005348C:
    // 0x8005348C: bne         $at, $zero, L_80053498
    if (ctx->r1 != 0) {
        // 0x80053490: nop
    
            goto L_80053498;
    }
    // 0x80053490: nop

    // 0x80053494: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80053498:
    // 0x80053498: sb          $v1, 0x1E0($a1)
    MEM_B(0X1E0, ctx->r5) = ctx->r3;
    // 0x8005349C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
L_800534A0:
    // 0x800534A0: nop

    // 0x800534A4: sw          $zero, 0x74($t0)
    MEM_W(0X74, ctx->r8) = 0;
    // 0x800534A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800534AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800534B0: jr          $ra
    // 0x800534B4: nop

    return;
    // 0x800534B4: nop

;}
RECOMP_FUNC void timetrial_save_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B76C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B770: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B774: jal         0x800599F8
    // 0x8001B778: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    timetrial_map_id(rdram, ctx);
        goto after_0;
    // 0x8001B778: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001B77C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001B780: lh          $t6, -0x336C($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X336C);
    // 0x8001B784: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8001B788: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8001B78C: lh          $a3, -0x3364($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X3364);
    // 0x8001B790: lh          $a2, -0x3368($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X3368);
    // 0x8001B794: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001B798: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001B79C: jal         0x80059BCC
    // 0x8001B7A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    timetrial_write_player_ghost(rdram, ctx);
        goto after_1;
    // 0x8001B7A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8001B7A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B7A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B7AC: jr          $ra
    // 0x8001B7B0: nop

    return;
    // 0x8001B7B0: nop

;}
RECOMP_FUNC void weather_clip_planes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB868: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AB86C: addiu       $v0, $v0, -0x7E48
    ctx->r2 = ADD32(ctx->r2, -0X7E48);
    // 0x800AB870: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x800AB874: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800AB878: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800AB87C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x800AB880: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800AB884: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AB888: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AB88C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800AB890: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800AB894: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800AB898: beq         $at, $zero, L_800AB8AC
    if (ctx->r1 == 0) {
        // 0x800AB89C: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800AB8AC;
    }
    // 0x800AB89C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800AB8A0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800AB8A4: jr          $ra
    // 0x800AB8A8: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    return;
    // 0x800AB8A8: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
L_800AB8AC:
    // 0x800AB8AC: sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // 0x800AB8B0: sh          $a0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r4;
    // 0x800AB8B4: jr          $ra
    // 0x800AB8B8: nop

    return;
    // 0x800AB8B8: nop

;}
RECOMP_FUNC void alSeqFileNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7D08: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800C7D0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C7D10: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C7D14: blez        $t6, L_800C7D40
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800C7D18: nop
    
            goto L_800C7D40;
    }
    // 0x800C7D18: nop

    // 0x800C7D1C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
L_800C7D20:
    // 0x800C7D20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C7D24: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C7D28: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C7D2C: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x800C7D30: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800C7D34: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C7D38: bnel        $at, $zero, L_800C7D20
    if (ctx->r1 != 0) {
        // 0x800C7D3C: lw          $t7, 0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X4);
            goto L_800C7D20;
    }
    goto skip_0;
    // 0x800C7D3C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    skip_0:
L_800C7D40:
    // 0x800C7D40: jr          $ra
    // 0x800C7D44: nop

    return;
    // 0x800C7D44: nop

;}
