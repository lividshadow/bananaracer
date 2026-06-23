#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80021104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021138: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002113C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021140: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80021144: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80021148: lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C);
    // 0x8002114C: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80021150: bne         $t6, $at, L_80021178
    if (ctx->r14 != ctx->r1) {
        // 0x80021154: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80021178;
    }
    // 0x80021154: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80021158: addiu       $v0, $v0, -0x4D42
    ctx->r2 = ADD32(ctx->r2, -0X4D42);
    // 0x8002115C: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x80021160: nop

    // 0x80021164: sb          $t7, 0x44($a1)
    MEM_B(0X44, ctx->r5) = ctx->r15;
    // 0x80021168: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x8002116C: nop

    // 0x80021170: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80021174: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_80021178:
    // 0x80021178: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002117C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80021180: lb          $a0, 0x22($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X22);
    // 0x80021184: nop

    // 0x80021188: bne         $a0, $at, L_8002120C
    if (ctx->r4 != ctx->r1) {
        // 0x8002118C: slti        $at, $a0, 0xA
        ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
            goto L_8002120C;
    }
    // 0x8002118C: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x80021190: lb          $a0, 0x30($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X30);
    // 0x80021194: jal         0x80066828
    // 0x80021198: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    set_active_camera(rdram, ctx);
        goto after_0;
    // 0x80021198: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002119C: jal         0x80069F3C
    // 0x800211A0: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_1;
    // 0x800211A0: nop

    after_1:
    // 0x800211A4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800211A8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800211AC: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x800211B0: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    // 0x800211B4: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800211B8: nop

    // 0x800211BC: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
    // 0x800211C0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800211C4: nop

    // 0x800211C8: swc1        $f8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f8.u32l;
    // 0x800211CC: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800211D0: nop

    // 0x800211D4: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x800211D8: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x800211DC: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x800211E0: nop

    // 0x800211E4: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800211E8: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
    // 0x800211EC: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800211F0: nop

    // 0x800211F4: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800211F8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800211FC: nop

    // 0x80021200: lb          $a0, 0x22($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X22);
    // 0x80021204: nop

    // 0x80021208: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
L_8002120C:
    // 0x8002120C: bne         $at, $zero, L_80021280
    if (ctx->r1 != 0) {
        // 0x80021210: slti        $at, $a0, 0x12
        ctx->r1 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
            goto L_80021280;
    }
    // 0x80021210: slti        $at, $a0, 0x12
    ctx->r1 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // 0x80021214: beq         $at, $zero, L_80021280
    if (ctx->r1 == 0) {
        // 0x80021218: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80021280;
    }
    // 0x80021218: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002121C: lw          $t8, -0x4B9C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4B9C);
    // 0x80021220: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80021224: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80021228: lw          $v0, -0x28($t0)
    ctx->r2 = MEM_W(ctx->r8, -0X28);
    // 0x8002122C: nop

    // 0x80021230: beq         $v0, $zero, L_80021284
    if (ctx->r2 == 0) {
        // 0x80021234: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80021284;
    }
    // 0x80021234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021238: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002123C: nop

    // 0x80021240: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x80021244: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80021248: nop

    // 0x8002124C: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x80021250: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80021254: nop

    // 0x80021258: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x8002125C: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x80021260: nop

    // 0x80021264: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x80021268: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x8002126C: nop

    // 0x80021270: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x80021274: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x80021278: nop

    // 0x8002127C: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
L_80021280:
    // 0x80021280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021284:
    // 0x80021284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80021288: jr          $ra
    // 0x8002128C: nop

    return;
    // 0x8002128C: nop

;}
RECOMP_FUNC void osScRemoveClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007993C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80079940: lw          $v1, 0x260($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X260);
    // 0x80079944: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80079948: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007994C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80079950: jal         0x800C9F90
    // 0x80079954: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80079954: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80079958: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8007995C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80079960: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80079964: beq         $v1, $zero, L_800799AC
    if (ctx->r3 == 0) {
        // 0x80079968: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800799AC;
    }
    // 0x80079968: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8007996C:
    // 0x8007996C: bne         $v1, $a1, L_80079998
    if (ctx->r3 != ctx->r5) {
        // 0x80079970: nop
    
            goto L_80079998;
    }
    // 0x80079970: nop

    // 0x80079974: beq         $a2, $zero, L_80079988
    if (ctx->r6 == 0) {
        // 0x80079978: nop
    
            goto L_80079988;
    }
    // 0x80079978: nop

    // 0x8007997C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80079980: b           L_800799AC
    // 0x80079984: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
        goto L_800799AC;
    // 0x80079984: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
L_80079988:
    // 0x80079988: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8007998C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80079990: b           L_800799AC
    // 0x80079994: sw          $t8, 0x260($t9)
    MEM_W(0X260, ctx->r25) = ctx->r24;
        goto L_800799AC;
    // 0x80079994: sw          $t8, 0x260($t9)
    MEM_W(0X260, ctx->r25) = ctx->r24;
L_80079998:
    // 0x80079998: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8007999C: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x800799A0: nop

    // 0x800799A4: bne         $v1, $zero, L_8007996C
    if (ctx->r3 != 0) {
        // 0x800799A8: nop
    
            goto L_8007996C;
    }
    // 0x800799A8: nop

L_800799AC:
    // 0x800799AC: jal         0x800C9F90
    // 0x800799B0: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800799B0: nop

    after_1:
    // 0x800799B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800799B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800799BC: jr          $ra
    // 0x800799C0: nop

    return;
    // 0x800799C0: nop

;}
RECOMP_FUNC void check_if_inside_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029E20: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80029E24: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x80029E28: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80029E2C: lh          $t6, 0x1A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1A);
    // 0x80029E30: nop

    // 0x80029E34: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80029E38: bne         $at, $zero, L_80029E48
    if (ctx->r1 != 0) {
        // 0x80029E3C: nop
    
            goto L_80029E48;
    }
    // 0x80029E3C: nop

    // 0x80029E40: jr          $ra
    // 0x80029E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80029E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80029E48:
    // 0x80029E48: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80029E4C: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80029E50: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80029E54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029E58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029E5C: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80029E60: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80029E64: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80029E68: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80029E6C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80029E70: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80029E74: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80029E78: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80029E7C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80029E80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029E84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029E88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80029E8C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80029E90: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80029E94: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80029E98: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x80029E9C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80029EA0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80029EA4: addiu       $t4, $t3, 0x19
    ctx->r12 = ADD32(ctx->r11, 0X19);
    // 0x80029EA8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80029EAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029EB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029EB4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80029EB8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80029EBC: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80029EC0: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80029EC4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80029EC8: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029ECC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80029F50;
    }
    // 0x80029ECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029ED0: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80029ED4: nop

    // 0x80029ED8: addiu       $t6, $t5, -0x19
    ctx->r14 = ADD32(ctx->r13, -0X19);
    // 0x80029EDC: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80029EE0: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029EE4: nop
    
            goto L_80029F50;
    }
    // 0x80029EE4: nop

    // 0x80029EE8: lh          $t7, 0xA($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA);
    // 0x80029EEC: nop

    // 0x80029EF0: addiu       $t8, $t7, 0x19
    ctx->r24 = ADD32(ctx->r15, 0X19);
    // 0x80029EF4: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80029EF8: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029EFC: nop
    
            goto L_80029F50;
    }
    // 0x80029EFC: nop

    // 0x80029F00: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80029F04: nop

    // 0x80029F08: addiu       $t1, $t9, -0x19
    ctx->r9 = ADD32(ctx->r25, -0X19);
    // 0x80029F0C: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80029F10: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029F14: nop
    
            goto L_80029F50;
    }
    // 0x80029F14: nop

    // 0x80029F18: lh          $t2, 0x8($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X8);
    // 0x80029F1C: nop

    // 0x80029F20: addiu       $t3, $t2, 0x19
    ctx->r11 = ADD32(ctx->r10, 0X19);
    // 0x80029F24: slt         $at, $a3, $t3
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80029F28: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029F2C: nop
    
            goto L_80029F50;
    }
    // 0x80029F2C: nop

    // 0x80029F30: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x80029F34: nop

    // 0x80029F38: addiu       $t5, $t4, -0x19
    ctx->r13 = ADD32(ctx->r12, -0X19);
    // 0x80029F3C: slt         $at, $t5, $a3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80029F40: beq         $at, $zero, L_80029F50
    if (ctx->r1 == 0) {
        // 0x80029F44: nop
    
            goto L_80029F50;
    }
    // 0x80029F44: nop

    // 0x80029F48: jr          $ra
    // 0x80029F4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80029F4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80029F50:
    // 0x80029F50: jr          $ra
    // 0x80029F54: nop

    return;
    // 0x80029F54: nop

;}
RECOMP_FUNC void is_bridge_raised(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E320: bltz        $a0, L_8001E36C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001E324: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_8001E36C;
    }
    // 0x8001E324: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8001E328: beq         $at, $zero, L_8001E36C
    if (ctx->r1 == 0) {
        // 0x8001E32C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001E36C;
    }
    // 0x8001E32C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001E330: lw          $t6, -0x4CB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CB4);
    // 0x8001E334: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001E338: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x8001E33C: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x8001E340: nop

    // 0x8001E344: blez        $v1, L_8001E364
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E348: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8001E364;
    }
    // 0x8001E348: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8001E34C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8001E350: lw          $t8, -0x4CB4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4CB4);
    // 0x8001E354: nop

    // 0x8001E358: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8001E35C: lb          $v1, 0x0($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X0);
    // 0x8001E360: nop

L_8001E364:
    // 0x8001E364: jr          $ra
    // 0x8001E368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001E368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001E36C:
    // 0x8001E36C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E370: jr          $ra
    // 0x8001E374: nop

    return;
    // 0x8001E374: nop

;}
RECOMP_FUNC void alSynSetFXMix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9D78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9D7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9D80: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C9D84: beql        $t6, $zero, L_800C9DF8
    if (ctx->r14 == 0) {
        // 0x800C9D88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9DF8;
    }
    goto skip_0;
    // 0x800C9D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9D8C: jal         0x800658A8
    // 0x800C9D90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9D90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C9D94: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9D98: beq         $v0, $zero, L_800C9DF4
    if (ctx->r2 == 0) {
        // 0x800C9D9C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9DF4;
    }
    // 0x800C9D9C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9DA0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C9DA4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C9DA8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800C9DAC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C9DB0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C9DB4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C9DB8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C9DBC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9DC0: lbu         $v1, 0x23($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X23);
    // 0x800C9DC4: bgez        $v1, L_800C9DD4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800C9DC8: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_800C9DD4;
    }
    // 0x800C9DC8: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x800C9DCC: b           L_800C9DD8
    // 0x800C9DD0: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
        goto L_800C9DD8;
    // 0x800C9DD0: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_800C9DD4:
    // 0x800C9DD4: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800C9DD8:
    // 0x800C9DD8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800C9DDC: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x800C9DE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9DE4: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800C9DE8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9DEC: jalr        $t9
    // 0x800C9DF0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9DF0: nop

    after_1:
L_800C9DF4:
    // 0x800C9DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9DF8:
    // 0x800C9DF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9DFC: jr          $ra
    // 0x800C9E00: nop

    return;
    // 0x800C9E00: nop

;}
RECOMP_FUNC void homing_rocket_prevent_overshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EE18: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8003EE1C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003EE20: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8003EE24: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8003EE28: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8003EE2C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8003EE30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003EE34: beq         $v0, $zero, L_8003F0BC
    if (ctx->r2 == 0) {
        // 0x8003EE38: or          $s1, $a2, $zero
        ctx->r17 = ctx->r6 | 0;
            goto L_8003F0BC;
    }
    // 0x8003EE38: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8003EE3C: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003EE40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003EE44: lh          $t6, 0x1BA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1BA);
    // 0x8003EE48: lwc1        $f13, 0x6788($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X6788);
    // 0x8003EE4C: lwc1        $f12, 0x678C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X678C);
    // 0x8003EE50: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8003EE54: sh          $t7, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r15;
    // 0x8003EE58: lh          $t8, 0x1BC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X1BC);
    // 0x8003EE5C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8003EE60: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8003EE64: sh          $t9, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r25;
    // 0x8003EE68: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8003EE6C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003EE70: nop

    // 0x8003EE74: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003EE78: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x8003EE7C: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003EE80: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003EE84: nop

    // 0x8003EE88: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8003EE8C: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8003EE90: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x8003EE94: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8003EE98: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003EE9C: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8003EEA0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003EEA4: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8003EEA8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003EEAC: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003EEB0: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8003EEB4: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003EEB8: mul.s       $f2, $f10, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8003EEBC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8003EEC0: c.lt.d      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.d < ctx->f12.d;
    // 0x8003EEC4: nop

    // 0x8003EEC8: bc1f        L_8003EEEC
    if (!c1cs) {
        // 0x8003EECC: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_8003EEEC;
    }
    // 0x8003EECC: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8003EED0: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8003EED4: c.lt.d      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.d < ctx->f6.d;
    // 0x8003EED8: nop

    // 0x8003EEDC: bc1f        L_8003EEEC
    if (!c1cs) {
        // 0x8003EEE0: nop
    
            goto L_8003EEEC;
    }
    // 0x8003EEE0: nop

    // 0x8003EEE4: b           L_8003F0FC
    // 0x8003EEE8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_8003F0FC;
    // 0x8003EEE8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8003EEEC:
    // 0x8003EEEC: add.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8003EEF0: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x8003EEF4: jal         0x800CA030
    // 0x8003EEF8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8003EEF8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    after_0:
    // 0x8003EEFC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003EF00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003EF04: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x8003EF08: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8003EF0C: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8003EF10: bc1f        L_8003EF98
    if (!c1cs) {
        // 0x8003EF14: swc1        $f0, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
            goto L_8003EF98;
    }
    // 0x8003EF14: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x8003EF18: lb          $a1, 0x19($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X19);
    // 0x8003EF1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003EF20: beq         $a1, $at, L_8003EF9C
    if (ctx->r5 == ctx->r1) {
        // 0x8003EF24: lui         $at, 0xC1C8
        ctx->r1 = S32(0XC1C8 << 16);
            goto L_8003EF9C;
    }
    // 0x8003EF24: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8003EF28: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x8003EF2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003EF30: bne         $t2, $zero, L_8003EF98
    if (ctx->r10 != 0) {
        // 0x8003EF34: addiu       $t4, $sp, 0x68
        ctx->r12 = ADD32(ctx->r29, 0X68);
            goto L_8003EF98;
    }
    // 0x8003EF34: addiu       $t4, $sp, 0x68
    ctx->r12 = ADD32(ctx->r29, 0X68);
    // 0x8003EF38: lh          $t3, 0x16($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X16);
    // 0x8003EF3C: lbu         $a2, 0x1C8($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1C8);
    // 0x8003EF40: lh          $a3, 0x14($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X14);
    // 0x8003EF44: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003EF48: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003EF4C: addiu       $t5, $sp, 0x64
    ctx->r13 = ADD32(ctx->r29, 0X64);
    // 0x8003EF50: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x8003EF54: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8003EF58: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8003EF5C: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x8003EF60: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8003EF64: jal         0x80019590
    // 0x8003EF68: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    homing_rocket_get_next_direction(rdram, ctx);
        goto after_1;
    // 0x8003EF68: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8003EF6C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8003EF70: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003EF74: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003EF78: jal         0x80070990
    // 0x8003EF7C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x8003EF7C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    after_2:
    // 0x8003EF80: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8003EF84: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8003EF88: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8003EF8C: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8003EF90: b           L_8003EFAC
    // 0x8003EF94: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
        goto L_8003EFAC;
    // 0x8003EF94: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_8003EF98:
    // 0x8003EF98: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
L_8003EF9C:
    // 0x8003EF9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003EFA0: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
    // 0x8003EFA4: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
    // 0x8003EFA8: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8003EFAC:
    // 0x8003EFAC: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8003EFB0: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003EFB4: jal         0x80070990
    // 0x8003EFB8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x8003EFB8: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    after_3:
    // 0x8003EFBC: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8003EFC0: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8003EFC4: addu        $a0, $v0, $at
    ctx->r4 = ADD32(ctx->r2, ctx->r1);
    // 0x8003EFC8: andi        $a2, $a0, 0xFFFF
    ctx->r6 = ctx->r4 & 0XFFFF;
    // 0x8003EFCC: andi        $t2, $a1, 0xFFFF
    ctx->r10 = ctx->r5 & 0XFFFF;
    // 0x8003EFD0: ori         $a3, $zero, 0x8001
    ctx->r7 = 0 | 0X8001;
    // 0x8003EFD4: subu        $v1, $a2, $t2
    ctx->r3 = SUB32(ctx->r6, ctx->r10);
    // 0x8003EFD8: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8003EFDC: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8003EFE0: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8003EFE4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8003EFE8: bne         $at, $zero, L_8003EFF8
    if (ctx->r1 != 0) {
        // 0x8003EFEC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003EFF8;
    }
    // 0x8003EFEC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003EFF0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003EFF4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003EFF8:
    // 0x8003EFF8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8003EFFC: beq         $at, $zero, L_8003F008
    if (ctx->r1 == 0) {
        // 0x8003F000: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003F008;
    }
    // 0x8003F000: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003F004: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003F008:
    // 0x8003F008: beq         $t3, $zero, L_8003F078
    if (ctx->r11 == 0) {
        // 0x8003F00C: slti        $at, $v1, 0x6001
        ctx->r1 = SIGNED(ctx->r3) < 0X6001 ? 1 : 0;
            goto L_8003F078;
    }
    // 0x8003F00C: slti        $at, $v1, 0x6001
    ctx->r1 = SIGNED(ctx->r3) < 0X6001 ? 1 : 0;
    // 0x8003F010: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8003F014: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x8003F018: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003F01C: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x8003F020: mflo        $t4
    ctx->r12 = lo;
    // 0x8003F024: srav        $t5, $t4, $t1
    ctx->r13 = S32(SIGNED(ctx->r12) >> (ctx->r9 & 31));
    // 0x8003F028: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x8003F02C: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x8003F030: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8003F034: nop

    // 0x8003F038: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x8003F03C: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8003F040: bne         $at, $zero, L_8003F050
    if (ctx->r1 != 0) {
        // 0x8003F044: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003F050;
    }
    // 0x8003F044: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003F048: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003F04C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003F050:
    // 0x8003F050: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8003F054: beq         $at, $zero, L_8003F060
    if (ctx->r1 == 0) {
        // 0x8003F058: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003F060;
    }
    // 0x8003F058: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003F05C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003F060:
    // 0x8003F060: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003F064: mflo        $t9
    ctx->r25 = lo;
    // 0x8003F068: srav        $t2, $t9, $t1
    ctx->r10 = S32(SIGNED(ctx->r25) >> (ctx->r9 & 31));
    // 0x8003F06C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8003F070: b           L_8003F0BC
    // 0x8003F074: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
        goto L_8003F0BC;
    // 0x8003F074: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
L_8003F078:
    // 0x8003F078: beq         $at, $zero, L_8003F088
    if (ctx->r1 == 0) {
        // 0x8003F07C: slti        $at, $v1, -0x6000
        ctx->r1 = SIGNED(ctx->r3) < -0X6000 ? 1 : 0;
            goto L_8003F088;
    }
    // 0x8003F07C: slti        $at, $v1, -0x6000
    ctx->r1 = SIGNED(ctx->r3) < -0X6000 ? 1 : 0;
    // 0x8003F080: beq         $at, $zero, L_8003F0A0
    if (ctx->r1 == 0) {
        // 0x8003F084: nop
    
            goto L_8003F0A0;
    }
    // 0x8003F084: nop

L_8003F088:
    // 0x8003F088: lw          $t4, 0x4C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4C);
    // 0x8003F08C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003F090: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x8003F094: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003F098: nop

    // 0x8003F09C: sb          $t5, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r13;
L_8003F0A0:
    // 0x8003F0A0: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003F0A4: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8003F0A8: jal         0x80070990
    // 0x8003F0AC: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    arctan2_f(rdram, ctx);
        goto after_4;
    // 0x8003F0AC: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_4:
    // 0x8003F0B0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8003F0B4: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8003F0B8: sh          $a2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r6;
L_8003F0BC:
    // 0x8003F0BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F0C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003F0C4: jal         0x8003F138
    // 0x8003F0C8: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    play_rocket_trailing_sound(rdram, ctx);
        goto after_5;
    // 0x8003F0C8: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    after_5:
    // 0x8003F0CC: jal         0x8009C90C
    // 0x8003F0D0: nop

    get_number_of_active_players(rdram, ctx);
        goto after_6;
    // 0x8003F0D0: nop

    after_6:
    // 0x8003F0D4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8003F0D8: beq         $at, $zero, L_8003F100
    if (ctx->r1 == 0) {
        // 0x8003F0DC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8003F100;
    }
    // 0x8003F0DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8003F0E0: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x8003F0E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F0E8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8003F0EC: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
    // 0x8003F0F0: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x8003F0F4: jal         0x800B019C
    // 0x8003F0F8: nop

    obj_spawn_particle(rdram, ctx);
        goto after_7;
    // 0x8003F0F8: nop

    after_7:
L_8003F0FC:
    // 0x8003F0FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8003F100:
    // 0x8003F100: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F104: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8003F108: jr          $ra
    // 0x8003F10C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8003F10C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void vi_refresh_rate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AF84: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007AF88: lw          $t6, 0x6710($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6710);
    // 0x8007AF8C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007AF90: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8007AF94: lbu         $t7, 0x68A9($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X68A9);
    // 0x8007AF98: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007AF9C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8007AFA0: bgez        $t7, L_8007AFB8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8007AFA4: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8007AFB8;
    }
    // 0x8007AFA4: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8007AFA8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007AFAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007AFB0: nop

    // 0x8007AFB4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8007AFB8:
    // 0x8007AFB8: nop

    // 0x8007AFBC: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8007AFC0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007AFC4: nop

    // 0x8007AFC8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8007AFCC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007AFD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007AFD4: nop

    // 0x8007AFD8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8007AFDC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8007AFE0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007AFE4: jr          $ra
    // 0x8007AFE8: nop

    return;
    // 0x8007AFE8: nop

;}
RECOMP_FUNC void begin_level_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F578: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F57C: lh          $t6, -0x26FC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X26FC);
    // 0x8006F580: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F584: bne         $t6, $zero, L_8006F5B8
    if (ctx->r14 != 0) {
        // 0x8006F588: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006F5B8;
    }
    // 0x8006F588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F58C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F590: sb          $a0, 0x3AA5($at)
    MEM_B(0X3AA5, ctx->r1) = ctx->r4;
    // 0x8006F594: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F598: jal         0x800C06F8
    // 0x8006F59C: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8006F59C: addiu       $a0, $a0, -0x2674
    ctx->r4 = ADD32(ctx->r4, -0X2674);
    after_0:
    // 0x8006F5A0: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8006F5A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F5A8: sh          $t7, -0x26FC($at)
    MEM_H(-0X26FC, ctx->r1) = ctx->r15;
    // 0x8006F5AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F5B0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8006F5B4: sb          $t8, 0x3AA4($at)
    MEM_B(0X3AA4, ctx->r1) = ctx->r24;
L_8006F5B8:
    // 0x8006F5B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F5BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F5C0: jr          $ra
    // 0x8006F5C4: nop

    return;
    // 0x8006F5C4: nop

;}
RECOMP_FUNC void obj_loop_animcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038750: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80038754: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80038758: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003875C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80038760: jal         0x8001F494
    // 0x80038764: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80038764: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80038768: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x8003876C: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80038770: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80038774: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x80038778: bne         $v0, $zero, L_800387F0
    if (ctx->r2 != 0) {
        // 0x8003877C: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_800387F0;
    }
    // 0x8003877C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80038780: jal         0x80066450
    // 0x80038784: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80038784: nop

    after_1:
    // 0x80038788: bne         $v0, $zero, L_800387AC
    if (ctx->r2 != 0) {
        // 0x8003878C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800387AC;
    }
    // 0x8003878C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80038790: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80038794: nop

    // 0x80038798: lb          $a0, 0x44($t9)
    ctx->r4 = MEM_B(ctx->r25, 0X44);
    // 0x8003879C: jal         0x80021100
    // 0x800387A0: nop

    func_800210CC(rdram, ctx);
        goto after_2;
    // 0x800387A0: nop

    after_2:
    // 0x800387A4: b           L_800387AC
    // 0x800387A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800387AC;
    // 0x800387A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800387AC:
    // 0x800387AC: beq         $v1, $zero, L_800387F0
    if (ctx->r3 == 0) {
        // 0x800387B0: ori         $t2, $zero, 0x8000
        ctx->r10 = 0 | 0X8000;
            goto L_800387F0;
    }
    // 0x800387B0: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x800387B4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800387B8: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x800387BC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800387C0: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800387C4: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x800387C8: lb          $a0, 0x30($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X30);
    // 0x800387CC: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x800387D0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800387D4: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x800387D8: nop

    // 0x800387DC: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800387E0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800387E4: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800387E8: jal         0x800666C8
    // 0x800387EC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    write_to_object_render_stack(rdram, ctx);
        goto after_3;
    // 0x800387EC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_3:
L_800387F0:
    // 0x800387F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800387F4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800387F8: jr          $ra
    // 0x800387FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800387FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void get_all_save_files_ptr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C9D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C9D8: jr          $ra
    // 0x8009C9DC: addiu       $v0, $v0, 0x6AD0
    ctx->r2 = ADD32(ctx->r2, 0X6AD0);
    return;
    // 0x8009C9DC: addiu       $v0, $v0, 0x6AD0
    ctx->r2 = ADD32(ctx->r2, 0X6AD0);
;}
RECOMP_FUNC void set_text_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C48E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C48E8: addiu       $v0, $v0, -0x5258
    ctx->r2 = ADD32(ctx->r2, -0X5258);
    // 0x800C48EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C48F0: nop

    // 0x800C48F4: sb          $a0, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r4;
    // 0x800C48F8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800C48FC: nop

    // 0x800C4900: sb          $a1, 0x15($t7)
    MEM_B(0X15, ctx->r15) = ctx->r5;
    // 0x800C4904: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800C4908: nop

    // 0x800C490C: sb          $a2, 0x16($t8)
    MEM_B(0X16, ctx->r24) = ctx->r6;
    // 0x800C4910: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C4914: nop

    // 0x800C4918: sb          $a3, 0x17($t9)
    MEM_B(0X17, ctx->r25) = ctx->r7;
    // 0x800C491C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800C4920: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800C4924: jr          $ra
    // 0x800C4928: sb          $t0, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r8;
    return;
    // 0x800C4928: sb          $t0, 0x1C($t1)
    MEM_B(0X1C, ctx->r9) = ctx->r8;
;}
RECOMP_FUNC void free_message_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2FD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2FD8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C2FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2FE0: lw          $a0, -0x5278($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5278);
    // 0x800C2FE4: jal         0x80071380
    // 0x800C2FE8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800C2FE8: nop

    after_0:
    // 0x800C2FEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2FF0: sh          $zero, -0x528A($at)
    MEM_H(-0X528A, ctx->r1) = 0;
    // 0x800C2FF4: jal         0x800C5B80
    // 0x800C2FF8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_close(rdram, ctx);
        goto after_1;
    // 0x800C2FF8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x800C2FFC: jal         0x800C59F4
    // 0x800C3000: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_2;
    // 0x800C3000: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_2:
    // 0x800C3004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3008: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C300C: jr          $ra
    // 0x800C3010: nop

    return;
    // 0x800C3010: nop

;}
RECOMP_FUNC void func_80059208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059248: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8005924C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059250: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80059254: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80059258: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005925C: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x80059260: jal         0x8001BA98
    // 0x80059264: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    get_checkpoint_count(rdram, ctx);
        goto after_0;
    // 0x80059264: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    after_0:
    // 0x80059268: beq         $v0, $zero, L_800597D0
    if (ctx->r2 == 0) {
        // 0x8005926C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800597D0;
    }
    // 0x8005926C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059270: jal         0x8006BFC8
    // 0x80059274: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_1;
    // 0x80059274: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    after_1:
    // 0x80059278: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x8005927C: bne         $v0, $zero, L_800592A4
    if (ctx->r2 != 0) {
        // 0x80059280: nop
    
            goto L_800592A4;
    }
    // 0x80059280: nop

    // 0x80059284: lb          $t6, 0x192($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X192);
    // 0x80059288: nop

    // 0x8005928C: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80059290: bne         $at, $zero, L_800592A4
    if (ctx->r1 != 0) {
        // 0x80059294: nop
    
            goto L_800592A4;
    }
    // 0x80059294: nop

    // 0x80059298: sb          $zero, 0x193($s1)
    MEM_B(0X193, ctx->r17) = 0;
    // 0x8005929C: sb          $zero, 0x192($s1)
    MEM_B(0X192, ctx->r17) = 0;
    // 0x800592A0: sh          $zero, 0x190($s1)
    MEM_H(0X190, ctx->r17) = 0;
L_800592A4:
    // 0x800592A4: lwc1        $f6, 0xA8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x800592A8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800592AC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800592B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800592B4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800592B8: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x800592BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800592C0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800592C4: lwc1        $f17, 0x6EB0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6EB0);
    // 0x800592C8: lwc1        $f16, 0x6EB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6EB4);
    // 0x800592CC: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800592D0: c.lt.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d < ctx->f16.d;
    // 0x800592D4: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x800592D8: bc1f        L_80059390
    if (!c1cs) {
        // 0x800592DC: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_80059390;
    }
    // 0x800592DC: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800592E0: sb          $t7, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r15;
    // 0x800592E4: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x800592E8: nop

    // 0x800592EC: bgez        $a0, L_8005930C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800592F0: nop
    
            goto L_8005930C;
    }
    // 0x800592F0: nop

    // 0x800592F4: lb          $v0, 0x193($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X193);
    // 0x800592F8: addu        $t8, $a0, $t0
    ctx->r24 = ADD32(ctx->r4, ctx->r8);
    // 0x800592FC: blez        $v0, L_8005930C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80059300: sb          $t8, 0x192($s1)
        MEM_B(0X192, ctx->r17) = ctx->r24;
            goto L_8005930C;
    }
    // 0x80059300: sb          $t8, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r24;
    // 0x80059304: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80059308: sb          $t9, 0x193($s1)
    MEM_B(0X193, ctx->r17) = ctx->r25;
L_8005930C:
    // 0x8005930C: lh          $v0, 0x190($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X190);
    // 0x80059310: nop

    // 0x80059314: slti        $at, $v0, -0x7CFF
    ctx->r1 = SIGNED(ctx->r2) < -0X7CFF ? 1 : 0;
    // 0x80059318: bne         $at, $zero, L_80059324
    if (ctx->r1 != 0) {
        // 0x8005931C: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_80059324;
    }
    // 0x8005931C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80059320: sh          $t1, 0x190($s1)
    MEM_H(0X190, ctx->r17) = ctx->r9;
L_80059324:
    // 0x80059324: lbu         $t2, 0x1C8($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1C8);
    // 0x80059328: nop

    // 0x8005932C: beq         $t2, $zero, L_800597D0
    if (ctx->r10 == 0) {
        // 0x80059330: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800597D0;
    }
    // 0x80059330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059334: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x80059338: jal         0x8001BA34
    // 0x8005933C: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    get_checkpoint_node(rdram, ctx);
        goto after_2;
    // 0x8005933C: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    after_2:
    // 0x80059340: lb          $t3, 0x3A($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X3A);
    // 0x80059344: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80059348: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8005934C: bne         $s0, $t3, L_80059358
    if (ctx->r16 != ctx->r11) {
        // 0x80059350: nop
    
            goto L_80059358;
    }
    // 0x80059350: nop

    // 0x80059354: sb          $zero, 0x1C8($s1)
    MEM_B(0X1C8, ctx->r17) = 0;
L_80059358:
    // 0x80059358: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x8005935C: nop

    // 0x80059360: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80059364: bgez        $a0, L_80059370
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80059368: nop
    
            goto L_80059370;
    }
    // 0x80059368: nop

    // 0x8005936C: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
L_80059370:
    // 0x80059370: jal         0x8001BA34
    // 0x80059374: nop

    get_checkpoint_node(rdram, ctx);
        goto after_3;
    // 0x80059374: nop

    after_3:
    // 0x80059378: lb          $t4, 0x3A($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X3A);
    // 0x8005937C: nop

    // 0x80059380: bne         $s0, $t4, L_800597D0
    if (ctx->r16 != ctx->r12) {
        // 0x80059384: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800597D0;
    }
    // 0x80059384: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059388: b           L_800597CC
    // 0x8005938C: sb          $zero, 0x1C8($s1)
    MEM_B(0X1C8, ctx->r17) = 0;
        goto L_800597CC;
    // 0x8005938C: sb          $zero, 0x1C8($s1)
    MEM_B(0X1C8, ctx->r17) = 0;
L_80059390:
    // 0x80059390: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80059394: nop

    // 0x80059398: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8005939C: nop

    // 0x800593A0: bc1f        L_800593B0
    if (!c1cs) {
        // 0x800593A4: nop
    
            goto L_800593B0;
    }
    // 0x800593A4: nop

    // 0x800593A8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800593AC: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_800593B0:
    // 0x800593B0: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x800593B4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800593B8: swc1        $f3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(3 - 1) * 2];
    // 0x800593BC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800593C0: jal         0x8001BA50
    // 0x800593C4: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    find_next_checkpoint_node(rdram, ctx);
        goto after_4;
    // 0x800593C4: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    after_4:
    // 0x800593C8: lb          $s0, 0x192($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X192);
    // 0x800593CC: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800593D0: lwc1        $f2, 0x1C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800593D4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800593D8: bgez        $s0, L_800593E8
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800593DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800593E8;
    }
    // 0x800593DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800593E0: addiu       $s0, $t0, -0x1
    ctx->r16 = ADD32(ctx->r8, -0X1);
    // 0x800593E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800593E8:
    // 0x800593E8: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x800593EC: jal         0x8001BA34
    // 0x800593F0: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    get_checkpoint_node(rdram, ctx);
        goto after_5;
    // 0x800593F0: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x800593F4: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800593F8: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800593FC: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80059400: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80059404: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80059408: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8005940C: addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    // 0x80059410: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    // 0x80059414: addiu       $v1, $sp, 0x74
    ctx->r3 = ADD32(ctx->r29, 0X74);
    // 0x80059418: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8005941C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80059420: lb          $s0, 0x192($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X192);
    // 0x80059424: nop

    // 0x80059428: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // 0x8005942C: bgez        $s0, L_80059438
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80059430: nop
    
            goto L_80059438;
    }
    // 0x80059430: nop

    // 0x80059434: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
L_80059438:
    // 0x80059438: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x8005943C: sw          $t0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r8;
    // 0x80059440: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80059444: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80059448: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8005944C: jal         0x8001BA50
    // 0x80059450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_6;
    // 0x80059450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80059454: lh          $t5, 0x1BA($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1BA);
    // 0x80059458: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005945C: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80059460: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80059464: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80059468: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005946C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80059470: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80059474: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80059478: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8005947C: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80059480: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80059484: addiu       $t8, $sp, 0x88
    ctx->r24 = ADD32(ctx->r29, 0X88);
    // 0x80059488: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005948C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80059490: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80059494: sltu        $at, $v1, $t8
    ctx->r1 = ctx->r3 < ctx->r24 ? 1 : 0;
    // 0x80059498: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x8005949C: lh          $t6, 0x1BC($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1BC);
    // 0x800594A0: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800594A4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800594A8: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800594AC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800594B0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800594B4: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800594B8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800594BC: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x800594C0: lh          $t7, 0x1BA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X1BA);
    // 0x800594C4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800594C8: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800594CC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800594D0: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800594D4: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800594D8: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800594DC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800594E0: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800594E4: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800594E8: bne         $s0, $t0, L_800594F4
    if (ctx->r16 != ctx->r8) {
        // 0x800594EC: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_800594F4;
    }
    // 0x800594EC: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800594F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800594F4:
    // 0x800594F4: bne         $at, $zero, L_80059438
    if (ctx->r1 != 0) {
        // 0x800594F8: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80059438;
    }
    // 0x800594F8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800594FC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80059500: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80059504: lwc1        $f1, 0x28($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80059508: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005950C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80059510: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80059514: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x80059518: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x8005951C: bc1f        L_80059534
    if (!c1cs) {
        // 0x80059520: addiu       $a3, $sp, 0x54
        ctx->r7 = ADD32(ctx->r29, 0X54);
            goto L_80059534;
    }
    // 0x80059520: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x80059524: sub.d       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f0.d - ctx->f2.d;
    // 0x80059528: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8005952C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80059530: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
L_80059534:
    // 0x80059534: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80059538: jal         0x80022670
    // 0x8005953C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    cubic_spline_interpolation(rdram, ctx);
        goto after_7;
    // 0x8005953C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80059540: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80059544: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80059548: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8005954C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80059550: jal         0x80022670
    // 0x80059554: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    cubic_spline_interpolation(rdram, ctx);
        goto after_8;
    // 0x80059554: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_8:
    // 0x80059558: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8005955C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80059560: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80059564: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80059568: jal         0x80022670
    // 0x8005956C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_9;
    // 0x8005956C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_9:
    // 0x80059570: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059574: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80059578: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005957C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80059580: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80059584: jal         0x800CA030
    // 0x80059588: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x80059588: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_10:
    // 0x8005958C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059590: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80059594: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80059598: nop

    // 0x8005959C: bc1t        L_800595C8
    if (c1cs) {
        // 0x800595A0: nop
    
            goto L_800595C8;
    }
    // 0x800595A0: nop

    // 0x800595A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800595A8: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800595AC: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800595B0: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800595B4: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800595B8: nop

    // 0x800595BC: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800595C0: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800595C4: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
L_800595C8:
    // 0x800595C8: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800595CC: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800595D0: jal         0x80070990
    // 0x800595D4: nop

    arctan2_f(rdram, ctx);
        goto after_11;
    // 0x800595D4: nop

    after_11:
    // 0x800595D8: lh          $t9, 0x1A0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1A0);
    // 0x800595DC: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800595E0: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x800595E4: subu        $a0, $v0, $t1
    ctx->r4 = SUB32(ctx->r2, ctx->r9);
    // 0x800595E8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x800595EC: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800595F0: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800595F4: bne         $at, $zero, L_80059604
    if (ctx->r1 != 0) {
        // 0x800595F8: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80059604;
    }
    // 0x800595F8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800595FC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80059600: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80059604:
    // 0x80059604: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x80059608: beq         $at, $zero, L_80059614
    if (ctx->r1 == 0) {
        // 0x8005960C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80059614;
    }
    // 0x8005960C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80059610: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80059614:
    // 0x80059614: slti        $at, $a0, 0x4001
    ctx->r1 = SIGNED(ctx->r4) < 0X4001 ? 1 : 0;
    // 0x80059618: beq         $at, $zero, L_80059628
    if (ctx->r1 == 0) {
        // 0x8005961C: slti        $at, $a0, -0x4000
        ctx->r1 = SIGNED(ctx->r4) < -0X4000 ? 1 : 0;
            goto L_80059628;
    }
    // 0x8005961C: slti        $at, $a0, -0x4000
    ctx->r1 = SIGNED(ctx->r4) < -0X4000 ? 1 : 0;
    // 0x80059620: beq         $at, $zero, L_80059678
    if (ctx->r1 == 0) {
        // 0x80059624: nop
    
            goto L_80059678;
    }
    // 0x80059624: nop

L_80059628:
    // 0x80059628: lb          $t2, 0x1D8($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X1D8);
    // 0x8005962C: nop

    // 0x80059630: bne         $t2, $zero, L_80059678
    if (ctx->r10 != 0) {
        // 0x80059634: nop
    
            goto L_80059678;
    }
    // 0x80059634: nop

    // 0x80059638: lbu         $v0, 0x1FC($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1FC);
    // 0x8005963C: nop

    // 0x80059640: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x80059644: beq         $at, $zero, L_8005967C
    if (ctx->r1 == 0) {
        // 0x80059648: nop
    
            goto L_8005967C;
    }
    // 0x80059648: nop

    // 0x8005964C: lwc1        $f18, 0x2C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80059650: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80059654: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80059658: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005965C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80059660: c.le.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d <= ctx->f16.d;
    // 0x80059664: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x80059668: bc1f        L_8005967C
    if (!c1cs) {
        // 0x8005966C: addu        $t4, $v0, $t3
        ctx->r12 = ADD32(ctx->r2, ctx->r11);
            goto L_8005967C;
    }
    // 0x8005966C: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80059670: b           L_8005967C
    // 0x80059674: sb          $t4, 0x1FC($s1)
    MEM_B(0X1FC, ctx->r17) = ctx->r12;
        goto L_8005967C;
    // 0x80059674: sb          $t4, 0x1FC($s1)
    MEM_B(0X1FC, ctx->r17) = ctx->r12;
L_80059678:
    // 0x80059678: sb          $zero, 0x1FC($s1)
    MEM_B(0X1FC, ctx->r17) = 0;
L_8005967C:
    // 0x8005967C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059680: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80059684: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80059688: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005968C: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80059690: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x80059694: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x80059698: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8005969C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800596A0: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800596A4: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
    // 0x800596A8: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800596AC: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x800596B0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800596B4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800596B8: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800596BC: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800596C0: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800596C4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800596C8: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800596CC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800596D0: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800596D4: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x800596D8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800596DC: add.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800596E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800596E4: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800596E8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800596EC: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800596F0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800596F4: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800596F8: bc1f        L_80059704
    if (!c1cs) {
        // 0x800596FC: nop
    
            goto L_80059704;
    }
    // 0x800596FC: nop

    // 0x80059700: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
L_80059704:
    // 0x80059704: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059708: nop

    // 0x8005970C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80059710: nop

    // 0x80059714: bc1f        L_80059720
    if (!c1cs) {
        // 0x80059718: nop
    
            goto L_80059720;
    }
    // 0x80059718: nop

    // 0x8005971C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
L_80059720:
    // 0x80059720: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80059724: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059728: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005972C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059730: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059734: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80059738: lh          $t5, 0x1BA($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1BA);
    // 0x8005973C: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80059740: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80059744: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80059748: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005974C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80059750: sh          $t8, 0x1BA($s1)
    MEM_H(0X1BA, ctx->r17) = ctx->r24;
    // 0x80059754: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80059758: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005975C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80059760: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80059764: nop

    // 0x80059768: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8005976C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80059770: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x80059774: bc1f        L_80059780
    if (!c1cs) {
        // 0x80059778: nop
    
            goto L_80059780;
    }
    // 0x80059778: nop

    // 0x8005977C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
L_80059780:
    // 0x80059780: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059784: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80059788: nop

    // 0x8005978C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80059790: nop

    // 0x80059794: bc1f        L_800597A0
    if (!c1cs) {
        // 0x80059798: nop
    
            goto L_800597A0;
    }
    // 0x80059798: nop

    // 0x8005979C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
L_800597A0:
    // 0x800597A0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800597A4: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800597A8: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800597AC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800597B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800597B4: lh          $t9, 0x1BC($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1BC);
    // 0x800597B8: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800597BC: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800597C0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800597C4: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800597C8: sh          $t3, 0x1BC($s1)
    MEM_H(0X1BC, ctx->r17) = ctx->r11;
L_800597CC:
    // 0x800597CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800597D0:
    // 0x800597D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800597D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800597D8: jr          $ra
    // 0x800597DC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800597DC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void light_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032464: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80032468: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003246C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80032470: lw          $a3, 0xC($a0)
    ctx->r7 = MEM_W(ctx->r4, 0XC);
    // 0x80032474: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80032478: beq         $a3, $zero, L_80032504
    if (ctx->r7 == 0) {
        // 0x8003247C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80032504;
    }
    // 0x8003247C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80032480: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80032484: lh          $t7, 0x8($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X8);
    // 0x80032488: lh          $t8, 0xA($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XA);
    // 0x8003248C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80032490: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80032494: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80032498: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003249C: addiu       $a1, $a2, 0x10
    ctx->r5 = ADD32(ctx->r6, 0X10);
    // 0x800324A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800324A4: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x800324A8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800324AC: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800324B0: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800324B4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800324B8: jal         0x80070560
    // 0x800324BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800324BC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800324C0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800324C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800324C8: lw          $a3, 0xC($a2)
    ctx->r7 = MEM_W(ctx->r6, 0XC);
    // 0x800324CC: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800324D0: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800324D4: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800324D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800324DC: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800324E0: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x800324E4: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800324E8: nop

    // 0x800324EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800324F0: swc1        $f18, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f18.u32l;
    // 0x800324F4: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800324F8: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
    // 0x800324FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80032500: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_80032504:
    // 0x80032504: lw          $a1, 0x44($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X44);
    // 0x80032508: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003250C: beq         $a1, $zero, L_800326C8
    if (ctx->r5 == 0) {
        // 0x80032510: nop
    
            goto L_800326C8;
    }
    // 0x80032510: nop

    // 0x80032514: lhu         $t9, 0x4C($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X4C);
    // 0x80032518: lhu         $v0, 0x4A($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4A);
    // 0x8003251C: addu        $t4, $t9, $s0
    ctx->r12 = ADD32(ctx->r25, ctx->r16);
    // 0x80032520: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x80032524: sh          $t4, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = ctx->r12;
    // 0x80032528: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x8003252C: lw          $v1, 0x4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X4);
    // 0x80032530: andi        $a0, $t4, 0xFFFF
    ctx->r4 = ctx->r12 & 0XFFFF;
    // 0x80032534: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80032538: bne         $at, $zero, L_8003258C
    if (ctx->r1 != 0) {
        // 0x8003253C: nop
    
            goto L_8003258C;
    }
    // 0x8003253C: nop

L_80032540:
    // 0x80032540: lhu         $t9, 0x48($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X48);
    // 0x80032544: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80032548: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x8003254C: subu        $t7, $a0, $v1
    ctx->r15 = SUB32(ctx->r4, ctx->r3);
    // 0x80032550: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032554: sh          $t7, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = ctx->r15;
    // 0x80032558: beq         $at, $zero, L_8003256C
    if (ctx->r1 == 0) {
        // 0x8003255C: sh          $t8, 0x4A($a2)
        MEM_H(0X4A, ctx->r6) = ctx->r24;
            goto L_8003256C;
    }
    // 0x8003255C: sh          $t8, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r24;
    // 0x80032560: lw          $a1, 0x44($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X44);
    // 0x80032564: sh          $zero, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = 0;
    // 0x80032568: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
L_8003256C:
    // 0x8003256C: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x80032570: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80032574: lw          $v1, 0x4($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X4);
    // 0x80032578: lhu         $a0, 0x4C($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X4C);
    // 0x8003257C: nop

    // 0x80032580: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80032584: beq         $at, $zero, L_80032540
    if (ctx->r1 == 0) {
        // 0x80032588: nop
    
            goto L_80032540;
    }
    // 0x80032588: nop

L_8003258C:
    // 0x8003258C: lhu         $t7, 0x48($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X48);
    // 0x80032590: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80032594: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80032598: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003259C: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x800325A0: beq         $at, $zero, L_800325B8
    if (ctx->r1 == 0) {
        // 0x800325A4: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_800325B8;
    }
    // 0x800325A4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800325A8: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800325AC: sll         $t4, $t9, 3
    ctx->r12 = S32(ctx->r25 << 3);
    // 0x800325B0: b           L_800325BC
    // 0x800325B4: addu        $a3, $a1, $t4
    ctx->r7 = ADD32(ctx->r5, ctx->r12);
        goto L_800325BC;
    // 0x800325B4: addu        $a3, $a1, $t4
    ctx->r7 = ADD32(ctx->r5, ctx->r12);
L_800325B8:
    // 0x800325B8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_800325BC:
    // 0x800325BC: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x800325C0: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800325C4: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x800325C8: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x800325CC: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x800325D0: bne         $t5, $zero, L_800325DC
    if (ctx->r13 != 0) {
        // 0x800325D4: nop
    
            goto L_800325DC;
    }
    // 0x800325D4: nop

    // 0x800325D8: break       7
    do_break(2147689944);
L_800325DC:
    // 0x800325DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800325E0: bne         $t5, $at, L_800325F4
    if (ctx->r13 != ctx->r1) {
        // 0x800325E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800325F4;
    }
    // 0x800325E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800325E8: bne         $t6, $at, L_800325F4
    if (ctx->r14 != ctx->r1) {
        // 0x800325EC: nop
    
            goto L_800325F4;
    }
    // 0x800325EC: nop

    // 0x800325F0: break       6
    do_break(2147689968);
L_800325F4:
    // 0x800325F4: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x800325F8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800325FC: mflo        $v0
    ctx->r2 = lo;
    // 0x80032600: nop

    // 0x80032604: nop

    // 0x80032608: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003260C: mflo        $t9
    ctx->r25 = lo;
    // 0x80032610: nop

    // 0x80032614: nop

    // 0x80032618: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003261C: mflo        $t4
    ctx->r12 = lo;
    // 0x80032620: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x80032624: sw          $t5, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r13;
    // 0x80032628: lbu         $t7, 0x1($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X1);
    // 0x8003262C: lbu         $t0, 0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1);
    // 0x80032630: nop

    // 0x80032634: subu        $t8, $t7, $t0
    ctx->r24 = SUB32(ctx->r15, ctx->r8);
    // 0x80032638: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003263C: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x80032640: mflo        $t9
    ctx->r25 = lo;
    // 0x80032644: nop

    // 0x80032648: nop

    // 0x8003264C: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032650: mflo        $t4
    ctx->r12 = lo;
    // 0x80032654: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x80032658: sw          $t5, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r13;
    // 0x8003265C: lbu         $t7, 0x2($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X2);
    // 0x80032660: lbu         $t1, 0x2($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X2);
    // 0x80032664: nop

    // 0x80032668: subu        $t8, $t7, $t1
    ctx->r24 = SUB32(ctx->r15, ctx->r9);
    // 0x8003266C: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032670: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x80032674: mflo        $t9
    ctx->r25 = lo;
    // 0x80032678: nop

    // 0x8003267C: nop

    // 0x80032680: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032684: mflo        $t4
    ctx->r12 = lo;
    // 0x80032688: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x8003268C: sw          $t5, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r13;
    // 0x80032690: lbu         $t7, 0x3($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X3);
    // 0x80032694: lbu         $t2, 0x3($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X3);
    // 0x80032698: nop

    // 0x8003269C: subu        $t8, $t7, $t2
    ctx->r24 = SUB32(ctx->r15, ctx->r10);
    // 0x800326A0: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800326A4: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x800326A8: mflo        $t9
    ctx->r25 = lo;
    // 0x800326AC: nop

    // 0x800326B0: nop

    // 0x800326B4: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800326B8: mflo        $t4
    ctx->r12 = lo;
    // 0x800326BC: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x800326C0: b           L_80032828
    // 0x800326C4: sw          $t5, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r13;
        goto L_80032828;
    // 0x800326C4: sw          $t5, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r13;
L_800326C8:
    // 0x800326C8: lhu         $v1, 0x3C($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X3C);
    // 0x800326CC: nop

    // 0x800326D0: beq         $v1, $zero, L_80032720
    if (ctx->r3 == 0) {
        // 0x800326D4: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80032720;
    }
    // 0x800326D4: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800326D8: beq         $at, $zero, L_80032704
    if (ctx->r1 == 0) {
        // 0x800326DC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80032704;
    }
    // 0x800326DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800326E0: lw          $t8, 0x2C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2C);
    // 0x800326E4: lw          $t7, 0x1C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1C);
    // 0x800326E8: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800326EC: subu        $t6, $v1, $s0
    ctx->r14 = SUB32(ctx->r3, ctx->r16);
    // 0x800326F0: sh          $t6, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = ctx->r14;
    // 0x800326F4: mflo        $t9
    ctx->r25 = lo;
    // 0x800326F8: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x800326FC: b           L_80032720
    // 0x80032700: sw          $t4, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r12;
        goto L_80032720;
    // 0x80032700: sw          $t4, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r12;
L_80032704:
    // 0x80032704: lw          $t8, 0x2C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2C);
    // 0x80032708: lw          $t5, 0x1C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X1C);
    // 0x8003270C: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032710: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    // 0x80032714: mflo        $t7
    ctx->r15 = lo;
    // 0x80032718: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8003271C: sw          $t9, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r25;
L_80032720:
    // 0x80032720: lhu         $v1, 0x3E($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X3E);
    // 0x80032724: nop

    // 0x80032728: beq         $v1, $zero, L_80032778
    if (ctx->r3 == 0) {
        // 0x8003272C: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80032778;
    }
    // 0x8003272C: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80032730: beq         $at, $zero, L_8003275C
    if (ctx->r1 == 0) {
        // 0x80032734: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8003275C;
    }
    // 0x80032734: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80032738: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x8003273C: lw          $t4, 0x20($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X20);
    // 0x80032740: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032744: subu        $t7, $v1, $s0
    ctx->r15 = SUB32(ctx->r3, ctx->r16);
    // 0x80032748: sh          $t7, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = ctx->r15;
    // 0x8003274C: mflo        $t8
    ctx->r24 = lo;
    // 0x80032750: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    // 0x80032754: b           L_80032778
    // 0x80032758: sw          $t5, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r13;
        goto L_80032778;
    // 0x80032758: sw          $t5, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r13;
L_8003275C:
    // 0x8003275C: lw          $t6, 0x30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X30);
    // 0x80032760: lw          $t9, 0x20($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X20);
    // 0x80032764: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032768: sh          $zero, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = 0;
    // 0x8003276C: mflo        $t4
    ctx->r12 = lo;
    // 0x80032770: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x80032774: sw          $t8, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r24;
L_80032778:
    // 0x80032778: lhu         $v1, 0x40($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X40);
    // 0x8003277C: nop

    // 0x80032780: beq         $v1, $zero, L_800327D0
    if (ctx->r3 == 0) {
        // 0x80032784: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800327D0;
    }
    // 0x80032784: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80032788: beq         $at, $zero, L_800327B4
    if (ctx->r1 == 0) {
        // 0x8003278C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800327B4;
    }
    // 0x8003278C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80032790: lw          $t7, 0x34($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X34);
    // 0x80032794: lw          $t5, 0x24($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X24);
    // 0x80032798: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003279C: subu        $t4, $v1, $s0
    ctx->r12 = SUB32(ctx->r3, ctx->r16);
    // 0x800327A0: sh          $t4, 0x40($a2)
    MEM_H(0X40, ctx->r6) = ctx->r12;
    // 0x800327A4: mflo        $t6
    ctx->r14 = lo;
    // 0x800327A8: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x800327AC: b           L_800327D0
    // 0x800327B0: sw          $t9, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r25;
        goto L_800327D0;
    // 0x800327B0: sw          $t9, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r25;
L_800327B4:
    // 0x800327B4: lw          $t7, 0x34($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X34);
    // 0x800327B8: lw          $t8, 0x24($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X24);
    // 0x800327BC: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800327C0: sh          $zero, 0x40($a2)
    MEM_H(0X40, ctx->r6) = 0;
    // 0x800327C4: mflo        $t5
    ctx->r13 = lo;
    // 0x800327C8: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x800327CC: sw          $t6, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r14;
L_800327D0:
    // 0x800327D0: lhu         $v1, 0x42($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X42);
    // 0x800327D4: nop

    // 0x800327D8: beq         $v1, $zero, L_80032828
    if (ctx->r3 == 0) {
        // 0x800327DC: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80032828;
    }
    // 0x800327DC: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800327E0: beq         $at, $zero, L_8003280C
    if (ctx->r1 == 0) {
        // 0x800327E4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8003280C;
    }
    // 0x800327E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800327E8: lw          $t4, 0x38($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X38);
    // 0x800327EC: lw          $t9, 0x28($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X28);
    // 0x800327F0: multu       $t4, $s0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800327F4: subu        $t5, $v1, $s0
    ctx->r13 = SUB32(ctx->r3, ctx->r16);
    // 0x800327F8: sh          $t5, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r13;
    // 0x800327FC: mflo        $t7
    ctx->r15 = lo;
    // 0x80032800: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80032804: b           L_80032828
    // 0x80032808: sw          $t8, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r24;
        goto L_80032828;
    // 0x80032808: sw          $t8, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r24;
L_8003280C:
    // 0x8003280C: lw          $t4, 0x38($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X38);
    // 0x80032810: lw          $t6, 0x28($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X28);
    // 0x80032814: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032818: sh          $zero, 0x42($a2)
    MEM_H(0X42, ctx->r6) = 0;
    // 0x8003281C: mflo        $t9
    ctx->r25 = lo;
    // 0x80032820: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80032824: sw          $t7, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r15;
L_80032828:
    // 0x80032828: lhu         $v1, 0x78($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X78);
    // 0x8003282C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80032830: beq         $v1, $zero, L_800328AC
    if (ctx->r3 == 0) {
        // 0x80032834: nop
    
            goto L_800328AC;
    }
    // 0x80032834: nop

    // 0x80032838: bne         $v1, $at, L_8003285C
    if (ctx->r3 != ctx->r1) {
        // 0x8003283C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8003285C;
    }
    // 0x8003283C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80032840: lh          $t5, 0x74($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X74);
    // 0x80032844: lh          $t8, 0x70($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X70);
    // 0x80032848: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003284C: mflo        $t4
    ctx->r12 = lo;
    // 0x80032850: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x80032854: b           L_800328A8
    // 0x80032858: sh          $t6, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r14;
        goto L_800328A8;
    // 0x80032858: sh          $t6, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r14;
L_8003285C:
    // 0x8003285C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032860: beq         $at, $zero, L_8003288C
    if (ctx->r1 == 0) {
        // 0x80032864: nop
    
            goto L_8003288C;
    }
    // 0x80032864: nop

    // 0x80032868: lh          $t7, 0x74($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X74);
    // 0x8003286C: lh          $t9, 0x70($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X70);
    // 0x80032870: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032874: subu        $t4, $v0, $s0
    ctx->r12 = SUB32(ctx->r2, ctx->r16);
    // 0x80032878: sh          $t4, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r12;
    // 0x8003287C: mflo        $t5
    ctx->r13 = lo;
    // 0x80032880: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x80032884: b           L_800328A8
    // 0x80032888: sh          $t8, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r24;
        goto L_800328A8;
    // 0x80032888: sh          $t8, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r24;
L_8003288C:
    // 0x8003288C: lh          $t7, 0x74($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X74);
    // 0x80032890: lh          $t6, 0x70($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X70);
    // 0x80032894: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032898: sh          $zero, 0x78($a2)
    MEM_H(0X78, ctx->r6) = 0;
    // 0x8003289C: mflo        $t9
    ctx->r25 = lo;
    // 0x800328A0: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x800328A4: sh          $t5, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r13;
L_800328A8:
    // 0x800328A8: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
L_800328AC:
    // 0x800328AC: lhu         $v1, 0x7A($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X7A);
    // 0x800328B0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800328B4: beq         $v1, $zero, L_80032930
    if (ctx->r3 == 0) {
        // 0x800328B8: nop
    
            goto L_80032930;
    }
    // 0x800328B8: nop

    // 0x800328BC: bne         $v1, $at, L_800328E0
    if (ctx->r3 != ctx->r1) {
        // 0x800328C0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800328E0;
    }
    // 0x800328C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800328C4: lh          $t4, 0x76($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X76);
    // 0x800328C8: lh          $t8, 0x72($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X72);
    // 0x800328CC: multu       $t4, $s0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800328D0: mflo        $t7
    ctx->r15 = lo;
    // 0x800328D4: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800328D8: b           L_8003292C
    // 0x800328DC: sh          $t6, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r14;
        goto L_8003292C;
    // 0x800328DC: sh          $t6, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r14;
L_800328E0:
    // 0x800328E0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800328E4: beq         $at, $zero, L_80032910
    if (ctx->r1 == 0) {
        // 0x800328E8: nop
    
            goto L_80032910;
    }
    // 0x800328E8: nop

    // 0x800328EC: lh          $t5, 0x76($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X76);
    // 0x800328F0: lh          $t9, 0x72($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X72);
    // 0x800328F4: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800328F8: subu        $t7, $v0, $s0
    ctx->r15 = SUB32(ctx->r2, ctx->r16);
    // 0x800328FC: sh          $t7, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = ctx->r15;
    // 0x80032900: mflo        $t4
    ctx->r12 = lo;
    // 0x80032904: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x80032908: b           L_8003292C
    // 0x8003290C: sh          $t8, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r24;
        goto L_8003292C;
    // 0x8003290C: sh          $t8, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r24;
L_80032910:
    // 0x80032910: lh          $t5, 0x76($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X76);
    // 0x80032914: lh          $t6, 0x72($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X72);
    // 0x80032918: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003291C: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
    // 0x80032920: mflo        $t9
    ctx->r25 = lo;
    // 0x80032924: addu        $t4, $t6, $t9
    ctx->r12 = ADD32(ctx->r14, ctx->r25);
    // 0x80032928: sh          $t4, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r12;
L_8003292C:
    // 0x8003292C: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
L_80032930:
    // 0x80032930: lbu         $t8, 0x5($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X5);
    // 0x80032934: nop

    // 0x80032938: beq         $t8, $zero, L_80032BE0
    if (ctx->r24 == 0) {
        // 0x8003293C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80032BE0;
    }
    // 0x8003293C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032940: lwc1        $f2, 0x10($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80032944: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x80032948: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x8003294C: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032950: addiu       $s0, $a2, 0x7C
    ctx->r16 = ADD32(ctx->r6, 0X7C);
    // 0x80032954: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80032958: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003295C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032960: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032964: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032968: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8003296C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80032970: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032974: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80032978: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8003297C: sh          $t5, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r13;
    // 0x80032980: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80032984: nop

    // 0x80032988: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003298C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032990: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032994: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032998: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8003299C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800329A0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800329A4: bne         $t4, $at, L_80032A10
    if (ctx->r12 != ctx->r1) {
        // 0x800329A8: sh          $t9, 0x56($a2)
        MEM_H(0X56, ctx->r6) = ctx->r25;
            goto L_80032A10;
    }
    // 0x800329A8: sh          $t9, 0x56($a2)
    MEM_H(0X56, ctx->r6) = ctx->r25;
    // 0x800329AC: lwc1        $f2, 0x14($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800329B0: nop

    // 0x800329B4: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800329B8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800329BC: nop

    // 0x800329C0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800329C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800329C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800329CC: nop

    // 0x800329D0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800329D4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800329D8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800329DC: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800329E0: sh          $t7, 0x52($a2)
    MEM_H(0X52, ctx->r6) = ctx->r15;
    // 0x800329E4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800329E8: nop

    // 0x800329EC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800329F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800329F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800329F8: nop

    // 0x800329FC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80032A00: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80032A04: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80032A08: b           L_80032A78
    // 0x80032A0C: sh          $t6, 0x58($a2)
    MEM_H(0X58, ctx->r6) = ctx->r14;
        goto L_80032A78;
    // 0x80032A0C: sh          $t6, 0x58($a2)
    MEM_H(0X58, ctx->r6) = ctx->r14;
L_80032A10:
    // 0x80032A10: lwc1        $f2, 0x14($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80032A14: lwc1        $f0, 0x60($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X60);
    // 0x80032A18: nop

    // 0x80032A1C: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032A20: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80032A24: nop

    // 0x80032A28: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80032A2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032A30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032A34: nop

    // 0x80032A38: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80032A3C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80032A40: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80032A44: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80032A48: sh          $t4, 0x52($a2)
    MEM_H(0X52, ctx->r6) = ctx->r12;
    // 0x80032A4C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80032A50: nop

    // 0x80032A54: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80032A58: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032A5C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032A60: nop

    // 0x80032A64: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80032A68: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80032A6C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80032A70: sh          $t7, 0x58($a2)
    MEM_H(0X58, ctx->r6) = ctx->r15;
    // 0x80032A74: nop

L_80032A78:
    // 0x80032A78: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x80032A7C: nop

    // 0x80032A80: bne         $t5, $zero, L_80032AF0
    if (ctx->r13 != 0) {
        // 0x80032A84: nop
    
            goto L_80032AF0;
    }
    // 0x80032A84: nop

    // 0x80032A88: lwc1        $f2, 0x18($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80032A8C: lwc1        $f0, 0x64($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X64);
    // 0x80032A90: nop

    // 0x80032A94: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032A98: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80032A9C: nop

    // 0x80032AA0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80032AA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032AA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032AAC: nop

    // 0x80032AB0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80032AB4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80032AB8: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80032ABC: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80032AC0: sh          $t9, 0x54($a2)
    MEM_H(0X54, ctx->r6) = ctx->r25;
    // 0x80032AC4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80032AC8: nop

    // 0x80032ACC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80032AD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032AD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032AD8: nop

    // 0x80032ADC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80032AE0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80032AE4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80032AE8: b           L_80032B58
    // 0x80032AEC: sh          $t8, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r24;
        goto L_80032B58;
    // 0x80032AEC: sh          $t8, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r24;
L_80032AF0:
    // 0x80032AF0: lwc1        $f2, 0x18($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80032AF4: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x80032AF8: nop

    // 0x80032AFC: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80032B00: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80032B04: nop

    // 0x80032B08: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032B0C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032B10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032B14: nop

    // 0x80032B18: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80032B1C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032B20: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80032B24: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80032B28: sh          $t5, 0x54($a2)
    MEM_H(0X54, ctx->r6) = ctx->r13;
    // 0x80032B2C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80032B30: nop

    // 0x80032B34: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80032B38: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032B3C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032B40: nop

    // 0x80032B44: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80032B48: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80032B4C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80032B50: sh          $t9, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r25;
    // 0x80032B54: nop

L_80032B58:
    // 0x80032B58: lbu         $t4, 0x1($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1);
    // 0x80032B5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80032B60: bne         $t4, $at, L_80032BD8
    if (ctx->r12 != ctx->r1) {
        // 0x80032B64: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80032BD8;
    }
    // 0x80032B64: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80032B68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80032B6C: lh          $t8, 0x70($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X70);
    // 0x80032B70: swc1        $f18, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->f18.u32l;
    // 0x80032B74: sh          $t8, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r24;
    // 0x80032B78: lh          $t7, 0x72($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X72);
    // 0x80032B7C: sh          $zero, 0x44($sp)
    MEM_H(0X44, ctx->r29) = 0;
    // 0x80032B80: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80032B84: jal         0x800706D0
    // 0x80032B88: sh          $t7, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r15;
    vec3f_rotate_py(rdram, ctx);
        goto after_1;
    // 0x80032B88: sh          $t7, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r15;
    after_1:
    // 0x80032B8C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80032B90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80032B94: lw          $a3, 0xC($a2)
    ctx->r7 = MEM_W(ctx->r6, 0XC);
    // 0x80032B98: nop

    // 0x80032B9C: beq         $a3, $zero, L_80032BB4
    if (ctx->r7 == 0) {
        // 0x80032BA0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80032BB4;
    }
    // 0x80032BA0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80032BA4: jal         0x80070560
    // 0x80032BA8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    vec3f_rotate(rdram, ctx);
        goto after_2;
    // 0x80032BA8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_2:
    // 0x80032BAC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80032BB0: nop

L_80032BB4:
    // 0x80032BB4: lwc1        $f4, 0x7C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X7C);
    // 0x80032BB8: lwc1        $f8, 0x80($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X80);
    // 0x80032BBC: lwc1        $f16, 0x84($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X84);
    // 0x80032BC0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80032BC4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80032BC8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80032BCC: swc1        $f6, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->f6.u32l;
    // 0x80032BD0: swc1        $f10, 0x80($a2)
    MEM_W(0X80, ctx->r6) = ctx->f10.u32l;
    // 0x80032BD4: swc1        $f18, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->f18.u32l;
L_80032BD8:
    // 0x80032BD8: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
    // 0x80032BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80032BE0:
    // 0x80032BE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80032BE4: jr          $ra
    // 0x80032BE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80032BE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alCSeqSecToTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C87E4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C87E8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C87EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C87F0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800C87F4: ldc1        $f6, -0x65D0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X65D0);
    // 0x800C87F8: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800C87FC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800C8800: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800C8804: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800C8808: bgez        $t7, L_800C8820
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C880C: cvt.d.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
            goto L_800C8820;
    }
    // 0x800C880C: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x800C8810: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C8814: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C8818: nop

    // 0x800C881C: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_800C8820:
    // 0x800C8820: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800C8824: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800C8828: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800C882C: bgez        $a2, L_800C8844
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C8830: cvt.d.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
            goto L_800C8844;
    }
    // 0x800C8830: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x800C8834: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800C8838: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C883C: nop

    // 0x800C8840: add.d       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f10.d + ctx->f18.d;
L_800C8844:
    // 0x800C8844: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800C8848: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C884C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800C8850: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C8854: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800C8858: nop

    // 0x800C885C: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C8860: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800C8864: nop

    // 0x800C8868: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800C886C: beql        $v0, $zero, L_800C88C8
    if (ctx->r2 == 0) {
        // 0x800C8870: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_800C88C8;
    }
    goto skip_0;
    // 0x800C8870: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x800C8874: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C8878: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C887C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C8880: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C8884: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x800C8888: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800C888C: nop

    // 0x800C8890: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x800C8894: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800C8898: nop

    // 0x800C889C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800C88A0: bnel        $v0, $zero, L_800C88BC
    if (ctx->r2 != 0) {
        // 0x800C88A4: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_800C88BC;
    }
    goto skip_1;
    // 0x800C88A4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_1:
    // 0x800C88A8: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800C88AC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C88B0: jr          $ra
    // 0x800C88B4: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x800C88B4: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x800C88B8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
L_800C88BC:
    // 0x800C88BC: jr          $ra
    // 0x800C88C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800C88C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C88C4: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_800C88C8:
    // 0x800C88C8: nop

    // 0x800C88CC: bltzl       $v0, L_800C88BC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800C88D0: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_800C88BC;
    }
    goto skip_2;
    // 0x800C88D0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_2:
    // 0x800C88D4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C88D8: jr          $ra
    // 0x800C88DC: nop

    return;
    // 0x800C88DC: nop

;}
RECOMP_FUNC void func_800135B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800135B8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800135BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800135C0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800135C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800135C8: lw          $s0, 0x7C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X7C);
    // 0x800135CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800135D0: sra         $t6, $s0, 28
    ctx->r14 = S32(SIGNED(ctx->r16) >> 28);
    // 0x800135D4: andi        $s0, $t6, 0xF
    ctx->r16 = ctx->r14 & 0XF;
    // 0x800135D8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800135DC: lbu         $v0, -0x4A38($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4A38);
    // 0x800135E0: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x800135E4: beq         $v0, $zero, L_80013600
    if (ctx->r2 == 0) {
        // 0x800135E8: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80013600;
    }
    // 0x800135E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800135EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800135F0: beq         $v0, $at, L_80013608
    if (ctx->r2 == ctx->r1) {
        // 0x800135F4: addiu       $v1, $s1, 0x24
        ctx->r3 = ADD32(ctx->r17, 0X24);
            goto L_80013608;
    }
    // 0x800135F4: addiu       $v1, $s1, 0x24
    ctx->r3 = ADD32(ctx->r17, 0X24);
    // 0x800135F8: b           L_80013608
    // 0x800135FC: addiu       $v1, $s1, 0x48
    ctx->r3 = ADD32(ctx->r17, 0X48);
        goto L_80013608;
    // 0x800135FC: addiu       $v1, $s1, 0x48
    ctx->r3 = ADD32(ctx->r17, 0X48);
L_80013600:
    // 0x80013600: b           L_80013608
    // 0x80013604: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
        goto L_80013608;
    // 0x80013604: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_80013608:
    // 0x80013608: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8001360C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x80013610: jal         0x8001E2D0
    // 0x80013614: sw          $a1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r5;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013614: sw          $a1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r5;
    after_0:
    // 0x80013618: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001361C: addiu       $t8, $t8, -0x4A28
    ctx->r24 = ADD32(ctx->r24, -0X4A28);
    // 0x80013620: addu        $a1, $s0, $t8
    ctx->r5 = ADD32(ctx->r16, ctx->r24);
    // 0x80013624: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x80013628: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8001362C: sll         $t4, $t9, 7
    ctx->r12 = S32(ctx->r25 << 7);
    // 0x80013630: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80013634: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x80013638: lw          $a0, 0x78($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X78);
    // 0x8001363C: jal         0x80012E28
    // 0x80013640: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    object_do_player_tumble(rdram, ctx);
        goto after_1;
    // 0x80013640: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_1:
    // 0x80013644: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80013648: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001364C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80013650: addiu       $s0, $s0, -0x4BF4
    ctx->r16 = ADD32(ctx->r16, -0X4BF4);
    // 0x80013654: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80013658: lw          $a2, 0x78($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X78);
    // 0x8001365C: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80013660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80013664: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80013668: jal         0x800696C4
    // 0x8001366C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_2;
    // 0x8001366C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80013670: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80013674: nop

    // 0x80013678: lw          $a0, 0x78($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X78);
    // 0x8001367C: jal         0x80012F30
    // 0x80013680: nop

    object_undo_player_tumble(rdram, ctx);
        goto after_3;
    // 0x80013680: nop

    after_3:
    // 0x80013684: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80013688: nop

    // 0x8001368C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80013690: nop

    // 0x80013694: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x80013698: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001369C: nop

    // 0x800136A0: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x800136A4: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800136A8: nop

    // 0x800136AC: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x800136B0: lbu         $t9, 0x72($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X72);
    // 0x800136B4: nop

    // 0x800136B8: sll         $t4, $t9, 28
    ctx->r12 = S32(ctx->r25 << 28);
    // 0x800136BC: jal         0x80070A38
    // 0x800136C0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_4;
    // 0x800136C0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_4:
    // 0x800136C4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800136C8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800136CC: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800136D0: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800136D4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800136D8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800136DC: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800136E0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800136E4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800136E8: addiu       $a2, $a2, -0x4BEC
    ctx->r6 = ADD32(ctx->r6, -0X4BEC);
    // 0x800136EC: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800136F0: lbu         $t6, 0x70($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X70);
    // 0x800136F4: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x800136F8: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800136FC: beq         $at, $zero, L_80013714
    if (ctx->r1 == 0) {
        // 0x80013700: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80013714;
    }
    // 0x80013700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80013704: lwc1        $f8, 0x74($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80013708: nop

    // 0x8001370C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80013710: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
L_80013714:
    // 0x80013714: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80013718: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001371C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80013720: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80013724: beq         $t8, $zero, L_80013740
    if (ctx->r24 == 0) {
        // 0x80013728: addiu       $a3, $sp, 0x54
        ctx->r7 = ADD32(ctx->r29, 0X54);
            goto L_80013740;
    }
    // 0x80013728: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x8001372C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013730: lwc1        $f18, 0x5AF8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5AF8);
    // 0x80013734: nop

    // 0x80013738: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001373C: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
L_80013740:
    // 0x80013740: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013744: sh          $zero, 0x58($sp)
    MEM_H(0X58, ctx->r29) = 0;
    // 0x80013748: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001374C: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x80013750: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80013754: sh          $zero, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = 0;
    // 0x80013758: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8001375C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80013760: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80013764: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013768: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    // 0x8001376C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80013770: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80013774: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80013778: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001377C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80013780: addiu       $t5, $zero, 0x10A
    ctx->r13 = ADD32(0, 0X10A);
    // 0x80013784: lw          $t4, 0x78($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X78);
    // 0x80013788: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8001378C: jal         0x80068754
    // 0x80013790: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    render_sprite_billboard(rdram, ctx);
        goto after_5;
    // 0x80013790: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_5:
    // 0x80013794: lbu         $t6, 0x70($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X70);
    // 0x80013798: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001379C: bne         $t6, $at, L_8001388C
    if (ctx->r14 != ctx->r1) {
        // 0x800137A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001388C;
    }
    // 0x800137A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800137A4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800137A8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x800137AC: lw          $a1, 0x7C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X7C);
    // 0x800137B0: jal         0x8007B938
    // 0x800137B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    material_set(rdram, ctx);
        goto after_6;
    // 0x800137B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x800137B8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800137BC: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800137C0: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x800137C4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800137C8: beq         $t9, $zero, L_800137D8
    if (ctx->r25 == 0) {
        // 0x800137CC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800137D8;
    }
    // 0x800137CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800137D0: b           L_800137DC
    // 0x800137D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_800137DC;
    // 0x800137D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800137D8:
    // 0x800137D8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_800137DC:
    // 0x800137DC: lw          $v1, 0x7C($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X7C);
    // 0x800137E0: lw          $a0, -0x4A78($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4A78);
    // 0x800137E4: sra         $t7, $v1, 14
    ctx->r15 = S32(SIGNED(ctx->r3) >> 14);
    // 0x800137E8: andi        $t8, $t7, 0x3FFF
    ctx->r24 = ctx->r15 & 0X3FFF;
    // 0x800137EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800137F0: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800137F4: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800137F8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800137FC: lw          $t6, -0x3344($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3344);
    // 0x80013800: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80013804: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80013808: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8001380C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80013810: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80013814: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x80013818: addu        $a2, $t0, $t3
    ctx->r6 = ADD32(ctx->r8, ctx->r11);
    // 0x8001381C: andi        $t5, $v1, 0x3FFF
    ctx->r13 = ctx->r3 & 0X3FFF;
    // 0x80013820: lw          $t4, -0x333C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X333C);
    // 0x80013824: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013828: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8001382C: andi        $t6, $a2, 0x6
    ctx->r14 = ctx->r6 & 0X6;
    // 0x80013830: ori         $t9, $t6, 0x40
    ctx->r25 = ctx->r14 | 0X40;
    // 0x80013834: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x80013838: addu        $t1, $t4, $t7
    ctx->r9 = ADD32(ctx->r12, ctx->r15);
    // 0x8001383C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80013840: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80013844: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x80013848: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8001384C: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x80013850: ori         $t8, $t7, 0xAA
    ctx->r24 = ctx->r15 | 0XAA;
    // 0x80013854: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80013858: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8001385C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80013860: ori         $t9, $t2, 0x70
    ctx->r25 = ctx->r10 | 0X70;
    // 0x80013864: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x80013868: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001386C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80013870: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x80013874: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80013878: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x8001387C: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80013880: addu        $t6, $t1, $t3
    ctx->r14 = ADD32(ctx->r9, ctx->r11);
    // 0x80013884: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80013888: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8001388C:
    // 0x8001388C: jal         0x80069C80
    // 0x80013890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtx_pop(rdram, ctx);
        goto after_7;
    // 0x80013890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80013894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013898: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001389C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800138A0: jr          $ra
    // 0x800138A4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800138A4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80053750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053790: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80053794: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x80053798: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8005379C: beq         $v0, $zero, L_80053ED4
    if (ctx->r2 == 0) {
        // 0x800537A0: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80053ED4;
    }
    // 0x800537A0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800537A4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800537A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800537AC: bne         $v1, $at, L_800537D8
    if (ctx->r3 != ctx->r1) {
        // 0x800537B0: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_800537D8;
    }
    // 0x800537B0: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800537B4: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800537B8: addiu       $a3, $zero, 0x4000
    ctx->r7 = ADD32(0, 0X4000);
    // 0x800537BC: sh          $a3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r7;
    // 0x800537C0: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x800537C4: nop

    // 0x800537C8: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x800537CC: nop

    // 0x800537D0: sh          $a3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r7;
    // 0x800537D4: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_800537D8:
    // 0x800537D8: bne         $at, $zero, L_80053ED4
    if (ctx->r1 != 0) {
        // 0x800537DC: nop
    
            goto L_80053ED4;
    }
    // 0x800537DC: nop

    // 0x800537E0: lwc1        $f0, 0x2C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x800537E4: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x800537E8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800537EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800537F0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800537F4: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x800537F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800537FC: bc1f        L_80053810
    if (!c1cs) {
        // 0x80053800: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80053810;
    }
    // 0x80053800: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80053804: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80053808: nop

    // 0x8005380C: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_80053810:
    // 0x80053810: lui         $at, 0xC014
    ctx->r1 = S32(0XC014 << 16);
    // 0x80053814: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80053818: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8005381C: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x80053820: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80053824: bc1f        L_80053834
    if (!c1cs) {
        // 0x80053828: nop
    
            goto L_80053834;
    }
    // 0x80053828: nop

    // 0x8005382C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80053830: nop

L_80053834:
    // 0x80053834: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053838: lwc1        $f6, 0xB8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XB8);
    // 0x8005383C: lwc1        $f3, 0x6D18($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X6D18);
    // 0x80053840: lwc1        $f2, 0x6D1C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6D1C);
    // 0x80053844: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80053848: c.lt.d      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.d < ctx->f8.d;
    // 0x8005384C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80053850: bc1f        L_8005387C
    if (!c1cs) {
        // 0x80053854: nop
    
            goto L_8005387C;
    }
    // 0x80053854: nop

    // 0x80053858: lwc1        $f10, 0xB4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XB4);
    // 0x8005385C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80053860: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80053864: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80053868: nop

    // 0x8005386C: bc1f        L_8005387C
    if (!c1cs) {
        // 0x80053870: nop
    
            goto L_8005387C;
    }
    // 0x80053870: nop

    // 0x80053874: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80053878: nop

L_8005387C:
    // 0x8005387C: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80053880: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80053884: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80053888: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005388C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80053890: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80053894: lwc1        $f6, 0xB0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XB0);
    // 0x80053898: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005389C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800538A0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800538A4: sub.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d - ctx->f4.d;
    // 0x800538A8: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x800538AC: swc1        $f6, 0xB0($a2)
    MEM_W(0XB0, ctx->r6) = ctx->f6.u32l;
    // 0x800538B0: lwc1        $f2, 0xB0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XB0);
    // 0x800538B4: nop

    // 0x800538B8: cvt.d.s     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.d = CVT_D_S(ctx->f2.fl);
    // 0x800538BC: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x800538C0: nop

    // 0x800538C4: bc1f        L_80053A64
    if (!c1cs) {
        // 0x800538C8: nop
    
            goto L_80053A64;
    }
    // 0x800538C8: nop

L_800538CC:
    // 0x800538CC: sub.d       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f12.d - ctx->f16.d;
    // 0x800538D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800538D4: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x800538D8: swc1        $f4, 0xB0($a2)
    MEM_W(0XB0, ctx->r6) = ctx->f4.u32l;
    // 0x800538DC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_800538E0:
    // 0x800538E0: bne         $at, $zero, L_800538F0
    if (ctx->r1 != 0) {
        // 0x800538E4: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_800538F0;
    }
    // 0x800538E4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800538E8: beq         $v0, $zero, L_80053990
    if (ctx->r2 == 0) {
        // 0x800538EC: nop
    
            goto L_80053990;
    }
    // 0x800538EC: nop

L_800538F0:
    // 0x800538F0: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x800538F4: lb          $t0, 0x1FB($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X1FB);
    // 0x800538F8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800538FC: lw          $a3, 0x4($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X4);
    // 0x80053900: beq         $t0, $zero, L_80053914
    if (ctx->r8 == 0) {
        // 0x80053904: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80053914;
    }
    // 0x80053904: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80053908: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8005390C: beq         $at, $zero, L_8005391C
    if (ctx->r1 == 0) {
        // 0x80053910: nop
    
            goto L_8005391C;
    }
    // 0x80053910: nop

L_80053914:
    // 0x80053914: bne         $t0, $zero, L_80053990
    if (ctx->r8 != 0) {
        // 0x80053918: nop
    
            goto L_80053990;
    }
    // 0x80053918: nop

L_8005391C:
    // 0x8005391C: lw          $t2, 0x78($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X78);
    // 0x80053920: nop

    // 0x80053924: beq         $t2, $zero, L_80053968
    if (ctx->r10 == 0) {
        // 0x80053928: nop
    
            goto L_80053968;
    }
    // 0x80053928: nop

    // 0x8005392C: lb          $t3, 0x3A($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X3A);
    // 0x80053930: nop

    // 0x80053934: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80053938: sb          $t4, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r12;
    // 0x8005393C: lb          $t5, 0x3A($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X3A);
    // 0x80053940: nop

    // 0x80053944: bgez        $t5, L_80053990
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80053948: nop
    
            goto L_80053990;
    }
    // 0x80053948: nop

    // 0x8005394C: lw          $t6, 0x40($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X40);
    // 0x80053950: nop

    // 0x80053954: lb          $t7, 0x55($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X55);
    // 0x80053958: nop

    // 0x8005395C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80053960: b           L_80053990
    // 0x80053964: sb          $t8, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r24;
        goto L_80053990;
    // 0x80053964: sb          $t8, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r24;
L_80053968:
    // 0x80053968: lb          $t9, 0x3A($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X3A);
    // 0x8005396C: lw          $t3, 0x40($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X40);
    // 0x80053970: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80053974: sb          $t2, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r10;
    // 0x80053978: lb          $t5, 0x3A($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X3A);
    // 0x8005397C: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x80053980: nop

    // 0x80053984: bne         $t4, $t5, L_80053990
    if (ctx->r12 != ctx->r13) {
        // 0x80053988: nop
    
            goto L_80053990;
    }
    // 0x80053988: nop

    // 0x8005398C: sb          $zero, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = 0;
L_80053990:
    // 0x80053990: blez        $v1, L_800539A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80053994: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800539A0;
    }
    // 0x80053994: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80053998: beq         $v0, $zero, L_80053A3C
    if (ctx->r2 == 0) {
        // 0x8005399C: nop
    
            goto L_80053A3C;
    }
    // 0x8005399C: nop

L_800539A0:
    // 0x800539A0: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x800539A4: lb          $t0, 0x1FB($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X1FB);
    // 0x800539A8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800539AC: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    // 0x800539B0: beq         $t0, $zero, L_800539C0
    if (ctx->r8 == 0) {
        // 0x800539B4: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800539C0;
    }
    // 0x800539B4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800539B8: beq         $at, $zero, L_800539C8
    if (ctx->r1 == 0) {
        // 0x800539BC: nop
    
            goto L_800539C8;
    }
    // 0x800539BC: nop

L_800539C0:
    // 0x800539C0: bne         $t0, $zero, L_80053A3C
    if (ctx->r8 != 0) {
        // 0x800539C4: nop
    
            goto L_80053A3C;
    }
    // 0x800539C4: nop

L_800539C8:
    // 0x800539C8: lw          $t9, 0x78($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X78);
    // 0x800539CC: nop

    // 0x800539D0: beq         $t9, $zero, L_80053A14
    if (ctx->r25 == 0) {
        // 0x800539D4: nop
    
            goto L_80053A14;
    }
    // 0x800539D4: nop

    // 0x800539D8: lb          $t2, 0x3A($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X3A);
    // 0x800539DC: nop

    // 0x800539E0: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800539E4: sb          $t3, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r11;
    // 0x800539E8: lb          $t4, 0x3A($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X3A);
    // 0x800539EC: nop

    // 0x800539F0: bgez        $t4, L_80053A3C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800539F4: nop
    
            goto L_80053A3C;
    }
    // 0x800539F4: nop

    // 0x800539F8: lw          $t5, 0x40($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X40);
    // 0x800539FC: nop

    // 0x80053A00: lb          $t6, 0x55($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X55);
    // 0x80053A04: nop

    // 0x80053A08: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80053A0C: b           L_80053A3C
    // 0x80053A10: sb          $t7, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r15;
        goto L_80053A3C;
    // 0x80053A10: sb          $t7, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r15;
L_80053A14:
    // 0x80053A14: lb          $t8, 0x3A($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X3A);
    // 0x80053A18: lw          $t2, 0x40($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X40);
    // 0x80053A1C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80053A20: sb          $t9, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r25;
    // 0x80053A24: lb          $t4, 0x3A($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X3A);
    // 0x80053A28: lb          $t3, 0x55($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X55);
    // 0x80053A2C: nop

    // 0x80053A30: bne         $t3, $t4, L_80053A3C
    if (ctx->r11 != ctx->r12) {
        // 0x80053A34: nop
    
            goto L_80053A3C;
    }
    // 0x80053A34: nop

    // 0x80053A38: sb          $zero, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = 0;
L_80053A3C:
    // 0x80053A3C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80053A40: bne         $v1, $t1, L_800538E0
    if (ctx->r3 != ctx->r9) {
        // 0x80053A44: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800538E0;
    }
    // 0x80053A44: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80053A48: lwc1        $f2, 0xB0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XB0);
    // 0x80053A4C: nop

    // 0x80053A50: cvt.d.s     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.d = CVT_D_S(ctx->f2.fl);
    // 0x80053A54: c.lt.d      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.d < ctx->f12.d;
    // 0x80053A58: nop

    // 0x80053A5C: bc1t        L_800538CC
    if (c1cs) {
        // 0x80053A60: nop
    
            goto L_800538CC;
    }
    // 0x80053A60: nop

L_80053A64:
    // 0x80053A64: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80053A68: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80053A6C: bc1f        L_80053C0C
    if (!c1cs) {
        // 0x80053A70: nop
    
            goto L_80053C0C;
    }
    // 0x80053A70: nop

L_80053A74:
    // 0x80053A74: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80053A78: add.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f10.d + ctx->f16.d;
    // 0x80053A7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80053A80: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80053A84: swc1        $f8, 0xB0($a2)
    MEM_W(0XB0, ctx->r6) = ctx->f8.u32l;
    // 0x80053A88: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_80053A8C:
    // 0x80053A8C: bne         $at, $zero, L_80053A9C
    if (ctx->r1 != 0) {
        // 0x80053A90: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80053A9C;
    }
    // 0x80053A90: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80053A94: beq         $v0, $zero, L_80053B3C
    if (ctx->r2 == 0) {
        // 0x80053A98: nop
    
            goto L_80053B3C;
    }
    // 0x80053A98: nop

L_80053A9C:
    // 0x80053A9C: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x80053AA0: lb          $t0, 0x1FB($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X1FB);
    // 0x80053AA4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80053AA8: lw          $a3, 0x4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X4);
    // 0x80053AAC: beq         $t0, $zero, L_80053AC0
    if (ctx->r8 == 0) {
        // 0x80053AB0: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80053AC0;
    }
    // 0x80053AB0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80053AB4: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80053AB8: beq         $at, $zero, L_80053AC8
    if (ctx->r1 == 0) {
        // 0x80053ABC: nop
    
            goto L_80053AC8;
    }
    // 0x80053ABC: nop

L_80053AC0:
    // 0x80053AC0: bne         $t0, $zero, L_80053B3C
    if (ctx->r8 != 0) {
        // 0x80053AC4: nop
    
            goto L_80053B3C;
    }
    // 0x80053AC4: nop

L_80053AC8:
    // 0x80053AC8: lw          $t8, 0x78($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X78);
    // 0x80053ACC: nop

    // 0x80053AD0: bne         $t8, $zero, L_80053B14
    if (ctx->r24 != 0) {
        // 0x80053AD4: nop
    
            goto L_80053B14;
    }
    // 0x80053AD4: nop

    // 0x80053AD8: lb          $t9, 0x3A($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X3A);
    // 0x80053ADC: nop

    // 0x80053AE0: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80053AE4: sb          $t2, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r10;
    // 0x80053AE8: lb          $t3, 0x3A($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X3A);
    // 0x80053AEC: nop

    // 0x80053AF0: bgez        $t3, L_80053B3C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80053AF4: nop
    
            goto L_80053B3C;
    }
    // 0x80053AF4: nop

    // 0x80053AF8: lw          $t4, 0x40($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X40);
    // 0x80053AFC: nop

    // 0x80053B00: lb          $t5, 0x55($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X55);
    // 0x80053B04: nop

    // 0x80053B08: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80053B0C: b           L_80053B3C
    // 0x80053B10: sb          $t6, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r14;
        goto L_80053B3C;
    // 0x80053B10: sb          $t6, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r14;
L_80053B14:
    // 0x80053B14: lb          $t7, 0x3A($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X3A);
    // 0x80053B18: lw          $t9, 0x40($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X40);
    // 0x80053B1C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80053B20: sb          $t8, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r24;
    // 0x80053B24: lb          $t3, 0x3A($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X3A);
    // 0x80053B28: lb          $t2, 0x55($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X55);
    // 0x80053B2C: nop

    // 0x80053B30: bne         $t2, $t3, L_80053B3C
    if (ctx->r10 != ctx->r11) {
        // 0x80053B34: nop
    
            goto L_80053B3C;
    }
    // 0x80053B34: nop

    // 0x80053B38: sb          $zero, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = 0;
L_80053B3C:
    // 0x80053B3C: blez        $v1, L_80053B4C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80053B40: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_80053B4C;
    }
    // 0x80053B40: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80053B44: beq         $v0, $zero, L_80053BE8
    if (ctx->r2 == 0) {
        // 0x80053B48: nop
    
            goto L_80053BE8;
    }
    // 0x80053B48: nop

L_80053B4C:
    // 0x80053B4C: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80053B50: lb          $t0, 0x1FB($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X1FB);
    // 0x80053B54: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80053B58: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    // 0x80053B5C: beq         $t0, $zero, L_80053B6C
    if (ctx->r8 == 0) {
        // 0x80053B60: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80053B6C;
    }
    // 0x80053B60: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80053B64: beq         $at, $zero, L_80053B74
    if (ctx->r1 == 0) {
        // 0x80053B68: nop
    
            goto L_80053B74;
    }
    // 0x80053B68: nop

L_80053B6C:
    // 0x80053B6C: bne         $t0, $zero, L_80053BE8
    if (ctx->r8 != 0) {
        // 0x80053B70: nop
    
            goto L_80053BE8;
    }
    // 0x80053B70: nop

L_80053B74:
    // 0x80053B74: lw          $t7, 0x78($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X78);
    // 0x80053B78: nop

    // 0x80053B7C: bne         $t7, $zero, L_80053BC0
    if (ctx->r15 != 0) {
        // 0x80053B80: nop
    
            goto L_80053BC0;
    }
    // 0x80053B80: nop

    // 0x80053B84: lb          $t8, 0x3A($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X3A);
    // 0x80053B88: nop

    // 0x80053B8C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80053B90: sb          $t9, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r25;
    // 0x80053B94: lb          $t2, 0x3A($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X3A);
    // 0x80053B98: nop

    // 0x80053B9C: bgez        $t2, L_80053BE8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80053BA0: nop
    
            goto L_80053BE8;
    }
    // 0x80053BA0: nop

    // 0x80053BA4: lw          $t3, 0x40($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X40);
    // 0x80053BA8: nop

    // 0x80053BAC: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x80053BB0: nop

    // 0x80053BB4: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80053BB8: b           L_80053BE8
    // 0x80053BBC: sb          $t5, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r13;
        goto L_80053BE8;
    // 0x80053BBC: sb          $t5, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r13;
L_80053BC0:
    // 0x80053BC0: lb          $t6, 0x3A($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X3A);
    // 0x80053BC4: lw          $t8, 0x40($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X40);
    // 0x80053BC8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80053BCC: sb          $t7, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r15;
    // 0x80053BD0: lb          $t2, 0x3A($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X3A);
    // 0x80053BD4: lb          $t9, 0x55($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X55);
    // 0x80053BD8: nop

    // 0x80053BDC: bne         $t9, $t2, L_80053BE8
    if (ctx->r25 != ctx->r10) {
        // 0x80053BE0: nop
    
            goto L_80053BE8;
    }
    // 0x80053BE0: nop

    // 0x80053BE4: sb          $zero, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = 0;
L_80053BE8:
    // 0x80053BE8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80053BEC: bne         $v1, $t1, L_80053A8C
    if (ctx->r3 != ctx->r9) {
        // 0x80053BF0: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80053A8C;
    }
    // 0x80053BF0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80053BF4: lwc1        $f2, 0xB0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XB0);
    // 0x80053BF8: nop

    // 0x80053BFC: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80053C00: nop

    // 0x80053C04: bc1t        L_80053A74
    if (c1cs) {
        // 0x80053C08: nop
    
            goto L_80053A74;
    }
    // 0x80053C08: nop

L_80053C0C:
    // 0x80053C0C: lb          $t3, 0x1FB($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X1FB);
    // 0x80053C10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80053C14: beq         $t3, $zero, L_80053CC4
    if (ctx->r11 == 0) {
        // 0x80053C18: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80053CC4;
    }
    // 0x80053C18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80053C20: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_80053C24:
    // 0x80053C24: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80053C28: nop

    // 0x80053C2C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80053C30: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    // 0x80053C34: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80053C38: lw          $t6, 0x78($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X78);
    // 0x80053C3C: nop

    // 0x80053C40: beq         $t6, $zero, L_80053C84
    if (ctx->r14 == 0) {
        // 0x80053C44: nop
    
            goto L_80053C84;
    }
    // 0x80053C44: nop

    // 0x80053C48: lb          $t7, 0x3A($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X3A);
    // 0x80053C4C: nop

    // 0x80053C50: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80053C54: sb          $t8, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r24;
    // 0x80053C58: lb          $t9, 0x3A($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X3A);
    // 0x80053C5C: nop

    // 0x80053C60: bgez        $t9, L_80053CAC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80053C64: nop
    
            goto L_80053CAC;
    }
    // 0x80053C64: nop

    // 0x80053C68: lw          $t2, 0x40($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X40);
    // 0x80053C6C: nop

    // 0x80053C70: lb          $t3, 0x55($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X55);
    // 0x80053C74: nop

    // 0x80053C78: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80053C7C: b           L_80053CAC
    // 0x80053C80: sb          $t4, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r12;
        goto L_80053CAC;
    // 0x80053C80: sb          $t4, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r12;
L_80053C84:
    // 0x80053C84: lb          $t5, 0x3A($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X3A);
    // 0x80053C88: lw          $t7, 0x40($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X40);
    // 0x80053C8C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80053C90: sb          $t6, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = ctx->r14;
    // 0x80053C94: lb          $t9, 0x3A($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X3A);
    // 0x80053C98: lb          $t8, 0x55($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X55);
    // 0x80053C9C: nop

    // 0x80053CA0: bne         $t8, $t9, L_80053CAC
    if (ctx->r24 != ctx->r25) {
        // 0x80053CA4: nop
    
            goto L_80053CAC;
    }
    // 0x80053CA4: nop

    // 0x80053CA8: sb          $zero, 0x3A($a1)
    MEM_B(0X3A, ctx->r5) = 0;
L_80053CAC:
    // 0x80053CAC: bne         $v0, $v1, L_80053C24
    if (ctx->r2 != ctx->r3) {
        // 0x80053CB0: nop
    
            goto L_80053C24;
    }
    // 0x80053CB0: nop

    // 0x80053CB4: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x80053CB8: nop

    // 0x80053CBC: ori         $t3, $t2, 0xC00
    ctx->r11 = ctx->r10 | 0XC00;
    // 0x80053CC0: sw          $t3, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r11;
L_80053CC4:
    // 0x80053CC4: lwc1        $f19, 0x6D20($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6D20);
    // 0x80053CC8: lwc1        $f18, 0x6D24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6D24);
    // 0x80053CCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053CD0: lwc1        $f17, 0x6D28($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6D28);
    // 0x80053CD4: lwc1        $f16, 0x6D2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6D2C);
    // 0x80053CD8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80053CDC: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x80053CE0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80053CE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80053CE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80053CEC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_80053CF0:
    // 0x80053CF0: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80053CF4: lb          $t6, 0x1E3($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X1E3);
    // 0x80053CF8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80053CFC: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    // 0x80053D00: and         $t7, $t6, $a3
    ctx->r15 = ctx->r14 & ctx->r7;
    // 0x80053D04: bne         $t7, $zero, L_80053D70
    if (ctx->r15 != 0) {
        // 0x80053D08: sll         $t3, $a3, 1
        ctx->r11 = S32(ctx->r7 << 1);
            goto L_80053D70;
    }
    // 0x80053D08: sll         $t3, $a3, 1
    ctx->r11 = S32(ctx->r7 << 1);
    // 0x80053D0C: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80053D10: nop

    // 0x80053D14: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80053D18: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80053D1C: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x80053D20: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80053D24: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80053D28: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80053D2C: swc1        $f6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f6.u32l;
    // 0x80053D30: lb          $t8, 0x1E5($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X1E5);
    // 0x80053D34: nop

    // 0x80053D38: beq         $t8, $zero, L_80053DB8
    if (ctx->r24 == 0) {
        // 0x80053D3C: nop
    
            goto L_80053DB8;
    }
    // 0x80053D3C: nop

    // 0x80053D40: lw          $t9, 0x40($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X40);
    // 0x80053D44: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80053D48: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80053D4C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80053D50: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80053D54: mul.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80053D58: sub.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f6.d - ctx->f0.d;
    // 0x80053D5C: mul.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80053D60: add.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d + ctx->f8.d;
    // 0x80053D64: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80053D68: b           L_80053DB8
    // 0x80053D6C: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
        goto L_80053DB8;
    // 0x80053D6C: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
L_80053D70:
    // 0x80053D70: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80053D74: lw          $t2, 0x40($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X40);
    // 0x80053D78: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80053D7C: mul.d       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f14.d);
    // 0x80053D80: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80053D84: nop

    // 0x80053D88: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80053D8C: sub.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d - ctx->f8.d;
    // 0x80053D90: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80053D94: swc1        $f6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f6.u32l;
    // 0x80053D98: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80053D9C: nop

    // 0x80053DA0: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80053DA4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80053DA8: mul.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f18.d);
    // 0x80053DAC: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80053DB0: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80053DB4: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
L_80053DB8:
    // 0x80053DB8: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80053DBC: lb          $t6, 0x1E3($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X1E3);
    // 0x80053DC0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80053DC4: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    // 0x80053DC8: and         $t7, $t6, $t3
    ctx->r15 = ctx->r14 & ctx->r11;
    // 0x80053DCC: bne         $t7, $zero, L_80053E38
    if (ctx->r15 != 0) {
        // 0x80053DD0: or          $a3, $t3, $zero
        ctx->r7 = ctx->r11 | 0;
            goto L_80053E38;
    }
    // 0x80053DD0: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x80053DD4: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80053DD8: nop

    // 0x80053DDC: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80053DE0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80053DE4: mul.d       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x80053DE8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80053DEC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80053DF0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80053DF4: swc1        $f10, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f10.u32l;
    // 0x80053DF8: lb          $t8, 0x1E5($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X1E5);
    // 0x80053DFC: nop

    // 0x80053E00: beq         $t8, $zero, L_80053E84
    if (ctx->r24 == 0) {
        // 0x80053E04: sll         $t3, $a3, 1
        ctx->r11 = S32(ctx->r7 << 1);
            goto L_80053E84;
    }
    // 0x80053E04: sll         $t3, $a3, 1
    ctx->r11 = S32(ctx->r7 << 1);
    // 0x80053E08: lw          $t9, 0x40($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X40);
    // 0x80053E0C: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80053E10: lwc1        $f6, 0xC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80053E14: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80053E18: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80053E1C: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80053E20: sub.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f10.d - ctx->f0.d;
    // 0x80053E24: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80053E28: add.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d + ctx->f6.d;
    // 0x80053E2C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80053E30: b           L_80053E80
    // 0x80053E34: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
        goto L_80053E80;
    // 0x80053E34: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
L_80053E38:
    // 0x80053E38: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80053E3C: lw          $t2, 0x40($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X40);
    // 0x80053E40: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80053E44: mul.d       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f14.d);
    // 0x80053E48: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80053E4C: nop

    // 0x80053E50: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80053E54: sub.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d - ctx->f6.d;
    // 0x80053E58: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80053E5C: swc1        $f10, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f10.u32l;
    // 0x80053E60: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80053E64: nop

    // 0x80053E68: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80053E6C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80053E70: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80053E74: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80053E78: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80053E7C: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
L_80053E80:
    // 0x80053E80: sll         $t3, $a3, 1
    ctx->r11 = S32(ctx->r7 << 1);
L_80053E84:
    // 0x80053E84: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80053E88: bne         $v0, $v1, L_80053CF0
    if (ctx->r2 != ctx->r3) {
        // 0x80053E8C: or          $a3, $t3, $zero
        ctx->r7 = ctx->r11 | 0;
            goto L_80053CF0;
    }
    // 0x80053E8C: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x80053E90: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80053E94: addiu       $v0, $v0, -0x254C
    ctx->r2 = ADD32(ctx->r2, -0X254C);
    // 0x80053E98: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80053E9C: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x80053EA0: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053EA4: lw          $t4, 0x60($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X60);
    // 0x80053EA8: nop

    // 0x80053EAC: lw          $a1, 0xC($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC);
    // 0x80053EB0: mflo        $t6
    ctx->r14 = lo;
    // 0x80053EB4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80053EB8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80053EBC: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x80053EC0: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053EC4: lw          $a1, 0x10($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X10);
    // 0x80053EC8: mflo        $t9
    ctx->r25 = lo;
    // 0x80053ECC: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x80053ED0: nop

L_80053ED4:
    // 0x80053ED4: jr          $ra
    // 0x80053ED8: nop

    return;
    // 0x80053ED8: nop

;}
RECOMP_FUNC void func_80050A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050A68: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80050A6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80050A70: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80050A74: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80050A78: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80050A7C: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x80050A80: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80050A84: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80050A88: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80050A8C: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80050A90: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80050A94: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80050A98: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80050A9C: bc1f        L_80050AB4
    if (!c1cs) {
        // 0x80050AA0: swc1        $f4, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
            goto L_80050AB4;
    }
    // 0x80050AA0: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80050AA4: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80050AA8: nop

    // 0x80050AAC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80050AB0: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
L_80050AB4:
    // 0x80050AB4: swc1        $f14, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f14.u32l;
    // 0x80050AB8: swc1        $f14, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f14.u32l;
    // 0x80050ABC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80050AC0: lh          $t6, -0x24FA($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X24FA);
    // 0x80050AC4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80050AC8: bne         $t6, $zero, L_80050BD0
    if (ctx->r14 != 0) {
        // 0x80050ACC: addiu       $t0, $t0, -0x2558
        ctx->r8 = ADD32(ctx->r8, -0X2558);
            goto L_80050BD0;
    }
    // 0x80050ACC: addiu       $t0, $t0, -0x2558
    ctx->r8 = ADD32(ctx->r8, -0X2558);
    // 0x80050AD0: lb          $t7, 0x1E7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E7);
    // 0x80050AD4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80050AD8: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x80050ADC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80050AE0: lb          $t9, -0x2CE0($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2CE0);
    // 0x80050AE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80050AE8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80050AEC: lwc1        $f7, 0x6BC8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6BC8);
    // 0x80050AF0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80050AF4: lwc1        $f6, 0x6BCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6BCC);
    // 0x80050AF8: lwc1        $f10, 0xA0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x80050AFC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80050B00: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80050B04: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x80050B08: lwc1        $f6, 0xA4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x80050B0C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80050B10: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80050B14: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80050B18: lwc1        $f18, 0x9C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80050B1C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80050B20: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x80050B24: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80050B28: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80050B2C: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x80050B30: swc1        $f6, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f6.u32l;
    // 0x80050B34: lw          $v1, 0x60($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X60);
    // 0x80050B38: nop

    // 0x80050B3C: beq         $v1, $zero, L_80050BC8
    if (ctx->r3 == 0) {
        // 0x80050B40: nop
    
            goto L_80050BC8;
    }
    // 0x80050B40: nop

    // 0x80050B44: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80050B48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80050B4C: blez        $t2, L_80050BC8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80050B50: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80050BC8;
    }
    // 0x80050B50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80050B54: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80050B58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80050B5C:
    // 0x80050B5C: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80050B60: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80050B64: div.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80050B68: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x80050B6C: addu        $t3, $v1, $a0
    ctx->r11 = ADD32(ctx->r3, ctx->r4);
    // 0x80050B70: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // 0x80050B74: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80050B78: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80050B7C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80050B80: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x80050B84: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80050B88: nop

    // 0x80050B8C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80050B90: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80050B94: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80050B98: lwc1        $f18, 0x80($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80050B9C: nop

    // 0x80050BA0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80050BA4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80050BA8: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x80050BAC: lw          $v1, 0x60($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X60);
    // 0x80050BB0: nop

    // 0x80050BB4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80050BB8: nop

    // 0x80050BBC: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80050BC0: bne         $at, $zero, L_80050B5C
    if (ctx->r1 != 0) {
        // 0x80050BC4: nop
    
            goto L_80050B5C;
    }
    // 0x80050BC4: nop

L_80050BC8:
    // 0x80050BC8: b           L_80050BE0
    // 0x80050BCC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
        goto L_80050BE0;
    // 0x80050BCC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
L_80050BD0:
    // 0x80050BD0: swc1        $f14, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f14.u32l;
    // 0x80050BD4: swc1        $f14, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f14.u32l;
    // 0x80050BD8: swc1        $f14, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f14.u32l;
    // 0x80050BDC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
L_80050BE0:
    // 0x80050BE0: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80050BE4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80050BE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80050BEC: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80050BF0: c.lt.d      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.d < ctx->f18.d;
    // 0x80050BF4: nop

    // 0x80050BF8: bc1f        L_80050C24
    if (!c1cs) {
        // 0x80050BFC: nop
    
            goto L_80050C24;
    }
    // 0x80050BFC: nop

    // 0x80050C00: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80050C04: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80050C08: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80050C0C: beq         $t6, $zero, L_80050C1C
    if (ctx->r14 == 0) {
        // 0x80050C10: nop
    
            goto L_80050C1C;
    }
    // 0x80050C10: nop

    // 0x80050C14: b           L_80050C40
    // 0x80050C18: sb          $t7, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r15;
        goto L_80050C40;
    // 0x80050C18: sb          $t7, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r15;
L_80050C1C:
    // 0x80050C1C: b           L_80050C40
    // 0x80050C20: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
        goto L_80050C40;
    // 0x80050C20: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
L_80050C24:
    // 0x80050C24: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80050C28: lw          $t8, -0x2558($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2558);
    // 0x80050C2C: nop

    // 0x80050C30: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80050C34: bne         $t9, $zero, L_80050C40
    if (ctx->r25 != 0) {
        // 0x80050C38: nop
    
            goto L_80050C40;
    }
    // 0x80050C38: nop

    // 0x80050C3C: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
L_80050C40:
    // 0x80050C40: lb          $v0, 0x1FB($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1FB);
    // 0x80050C44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80050C48: blez        $v0, L_80050C64
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80050C4C: addiu       $t0, $t0, -0x2558
        ctx->r8 = ADD32(ctx->r8, -0X2558);
            goto L_80050C64;
    }
    // 0x80050C4C: addiu       $t0, $t0, -0x2558
    ctx->r8 = ADD32(ctx->r8, -0X2558);
    // 0x80050C50: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80050C54: nop

    // 0x80050C58: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80050C5C: b           L_80050C68
    // 0x80050C60: sb          $t3, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r11;
        goto L_80050C68;
    // 0x80050C60: sb          $t3, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r11;
L_80050C64:
    // 0x80050C64: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
L_80050C68:
    // 0x80050C68: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80050C6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80050C70: lwc1        $f6, 0xB8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80050C74: lwc1        $f5, 0x6BD0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6BD0);
    // 0x80050C78: lwc1        $f4, 0x6BD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6BD4);
    // 0x80050C7C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80050C80: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x80050C84: nop

    // 0x80050C88: bc1f        L_80050DAC
    if (!c1cs) {
        // 0x80050C8C: nop
    
            goto L_80050DAC;
    }
    // 0x80050C8C: nop

    // 0x80050C90: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050C94: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80050C98: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80050C9C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80050CA0: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80050CA4: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80050CA8: nop

    // 0x80050CAC: bc1f        L_80050CDC
    if (!c1cs) {
        // 0x80050CB0: nop
    
            goto L_80050CDC;
    }
    // 0x80050CB0: nop

    // 0x80050CB4: lb          $t4, 0x1D8($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D8);
    // 0x80050CB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80050CBC: bne         $t4, $zero, L_80050CDC
    if (ctx->r12 != 0) {
        // 0x80050CC0: nop
    
            goto L_80050CDC;
    }
    // 0x80050CC0: nop

    // 0x80050CC4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80050CC8: jal         0x80072594
    // 0x80050CCC: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    rumble_set(rdram, ctx);
        goto after_0;
    // 0x80050CCC: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    after_0:
    // 0x80050CD0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80050CD4: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80050CD8: addiu       $t0, $t0, -0x2558
    ctx->r8 = ADD32(ctx->r8, -0X2558);
L_80050CDC:
    // 0x80050CDC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80050CE0: lw          $t6, -0x2524($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2524);
    // 0x80050CE4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80050CE8: bltz        $t6, L_80050D60
    if (SIGNED(ctx->r14) < 0) {
        // 0x80050CEC: sw          $t5, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r13;
            goto L_80050D60;
    }
    // 0x80050CEC: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x80050CF0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80050CF4: lw          $t7, -0x2EF8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2EF8);
    // 0x80050CF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80050CFC: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80050D00: beq         $at, $zero, L_80050D5C
    if (ctx->r1 == 0) {
        // 0x80050D04: nop
    
            goto L_80050D5C;
    }
    // 0x80050D04: nop

    // 0x80050D08: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x80050D0C: nop

    // 0x80050D10: blez        $a0, L_80050D2C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80050D14: nop
    
            goto L_80050D2C;
    }
    // 0x80050D14: nop

    // 0x80050D18: lw          $t8, 0x74($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X74);
    // 0x80050D1C: nop

    // 0x80050D20: ori         $t9, $t8, 0x1400
    ctx->r25 = ctx->r24 | 0X1400;
    // 0x80050D24: b           L_80050D60
    // 0x80050D28: sw          $t9, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r25;
        goto L_80050D60;
    // 0x80050D28: sw          $t9, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r25;
L_80050D2C:
    // 0x80050D2C: bgez        $a0, L_80050D48
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80050D30: nop
    
            goto L_80050D48;
    }
    // 0x80050D30: nop

    // 0x80050D34: lw          $t2, 0x74($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X74);
    // 0x80050D38: nop

    // 0x80050D3C: ori         $t3, $t2, 0x2800
    ctx->r11 = ctx->r10 | 0X2800;
    // 0x80050D40: b           L_80050D60
    // 0x80050D44: sw          $t3, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r11;
        goto L_80050D60;
    // 0x80050D44: sw          $t3, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r11;
L_80050D48:
    // 0x80050D48: lw          $t4, 0x74($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X74);
    // 0x80050D4C: nop

    // 0x80050D50: ori         $t5, $t4, 0x3000
    ctx->r13 = ctx->r12 | 0X3000;
    // 0x80050D54: b           L_80050D60
    // 0x80050D58: sw          $t5, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r13;
        goto L_80050D60;
    // 0x80050D58: sw          $t5, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r13;
L_80050D5C:
    // 0x80050D5C: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_80050D60:
    // 0x80050D60: lb          $t7, 0x1E7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E7);
    // 0x80050D64: addiu       $a0, $zero, -0x19
    ctx->r4 = ADD32(0, -0X19);
    // 0x80050D68: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80050D6C: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80050D70: beq         $at, $zero, L_80050D90
    if (ctx->r1 == 0) {
        // 0x80050D74: addiu       $a1, $zero, 0x19
        ctx->r5 = ADD32(0, 0X19);
            goto L_80050D90;
    }
    // 0x80050D74: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80050D78: jal         0x8006FB8C
    // 0x80050D7C: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    rand_range(rdram, ctx);
        goto after_1;
    // 0x80050D7C: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    after_1:
    // 0x80050D80: sb          $v0, 0x1D1($s0)
    MEM_B(0X1D1, ctx->r16) = ctx->r2;
    // 0x80050D84: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80050D88: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80050D8C: addiu       $t0, $t0, -0x2558
    ctx->r8 = ADD32(ctx->r8, -0X2558);
L_80050D90:
    // 0x80050D90: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80050D94: addiu       $t1, $t1, -0x254C
    ctx->r9 = ADD32(ctx->r9, -0X254C);
    // 0x80050D98: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80050D9C: lb          $t2, 0x1D1($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D1);
    // 0x80050DA0: nop

    // 0x80050DA4: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80050DA8: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
L_80050DAC:
    // 0x80050DAC: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050DB0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80050DB4: bne         $a0, $zero, L_80050E38
    if (ctx->r4 != 0) {
        // 0x80050DB8: addiu       $t1, $t1, -0x254C
        ctx->r9 = ADD32(ctx->r9, -0X254C);
            goto L_80050E38;
    }
    // 0x80050DB8: addiu       $t1, $t1, -0x254C
    ctx->r9 = ADD32(ctx->r9, -0X254C);
    // 0x80050DBC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050DC0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80050DC4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80050DC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80050DCC: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80050DD0: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80050DD4: nop

    // 0x80050DD8: bc1f        L_80050E38
    if (!c1cs) {
        // 0x80050DDC: nop
    
            goto L_80050E38;
    }
    // 0x80050DDC: nop

    // 0x80050DE0: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80050DE4: nop

    // 0x80050DE8: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80050DEC: beq         $t5, $zero, L_80050E38
    if (ctx->r13 == 0) {
        // 0x80050DF0: nop
    
            goto L_80050E38;
    }
    // 0x80050DF0: nop

    // 0x80050DF4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80050DF8: nop

    // 0x80050DFC: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x80050E00: beq         $at, $zero, L_80050E10
    if (ctx->r1 == 0) {
        // 0x80050E04: slti        $at, $v0, -0x32
        ctx->r1 = SIGNED(ctx->r2) < -0X32 ? 1 : 0;
            goto L_80050E10;
    }
    // 0x80050E04: slti        $at, $v0, -0x32
    ctx->r1 = SIGNED(ctx->r2) < -0X32 ? 1 : 0;
    // 0x80050E08: beq         $at, $zero, L_80050E38
    if (ctx->r1 == 0) {
        // 0x80050E0C: nop
    
            goto L_80050E38;
    }
    // 0x80050E0C: nop

L_80050E10:
    // 0x80050E10: blez        $v0, L_80050E2C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80050E14: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_80050E2C;
    }
    // 0x80050E14: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80050E18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80050E1C: sb          $t6, 0x1FA($s0)
    MEM_B(0X1FA, ctx->r16) = ctx->r14;
    // 0x80050E20: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050E24: b           L_80050E38
    // 0x80050E28: nop

        goto L_80050E38;
    // 0x80050E28: nop

L_80050E2C:
    // 0x80050E2C: sb          $t7, 0x1FA($s0)
    MEM_B(0X1FA, ctx->r16) = ctx->r15;
    // 0x80050E30: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050E34: nop

L_80050E38:
    // 0x80050E38: beq         $a0, $zero, L_80050F48
    if (ctx->r4 == 0) {
        // 0x80050E3C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80050F48;
    }
    // 0x80050E3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80050E40: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80050E44: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80050E48: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80050E4C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80050E50: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80050E54: ori         $t3, $t9, 0x4000
    ctx->r11 = ctx->r25 | 0X4000;
    // 0x80050E58: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80050E5C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80050E60: lw          $t6, -0x2EF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2EF8);
    // 0x80050E64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80050E68: addiu       $t4, $zero, -0x46
    ctx->r12 = ADD32(0, -0X46);
    // 0x80050E6C: sw          $t4, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r12;
    // 0x80050E70: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80050E74: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80050E78: beq         $at, $zero, L_80050E94
    if (ctx->r1 == 0) {
        // 0x80050E7C: sw          $t5, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r13;
            goto L_80050E94;
    }
    // 0x80050E7C: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x80050E80: lw          $t7, 0x74($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X74);
    // 0x80050E84: nop

    // 0x80050E88: ori         $t8, $t7, 0x3C00
    ctx->r24 = ctx->r15 | 0X3C00;
    // 0x80050E8C: b           L_80050E9C
    // 0x80050E90: sw          $t8, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r24;
        goto L_80050E9C;
    // 0x80050E90: sw          $t8, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r24;
L_80050E94:
    // 0x80050E94: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80050E98: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_80050E9C:
    // 0x80050E9C: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80050EA0: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050EA4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80050EA8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80050EAC: sll         $t3, $t3, 9
    ctx->r11 = S32(ctx->r11 << 9);
    // 0x80050EB0: multu       $t3, $a0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80050EB4: lh          $v1, 0x1A2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A2);
    // 0x80050EB8: nop

    // 0x80050EBC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80050EC0: mflo        $t4
    ctx->r12 = lo;
    // 0x80050EC4: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80050EC8: blez        $a0, L_80050EF8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80050ECC: sh          $t5, 0x1A2($s0)
        MEM_H(0X1A2, ctx->r16) = ctx->r13;
            goto L_80050EF8;
    }
    // 0x80050ECC: sh          $t5, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r13;
    // 0x80050ED0: lh          $t6, 0x1A2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A2);
    // 0x80050ED4: nop

    // 0x80050ED8: bgez        $t6, L_80050F1C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80050EDC: nop
    
            goto L_80050F1C;
    }
    // 0x80050EDC: nop

    // 0x80050EE0: bltz        $v1, L_80050F1C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80050EE4: addiu       $t7, $zero, 0x7FFF
        ctx->r15 = ADD32(0, 0X7FFF);
            goto L_80050F1C;
    }
    // 0x80050EE4: addiu       $t7, $zero, 0x7FFF
    ctx->r15 = ADD32(0, 0X7FFF);
    // 0x80050EE8: sb          $zero, 0x1FA($s0)
    MEM_B(0X1FA, ctx->r16) = 0;
    // 0x80050EEC: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050EF0: b           L_80050F1C
    // 0x80050EF4: sh          $t7, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r15;
        goto L_80050F1C;
    // 0x80050EF4: sh          $t7, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r15;
L_80050EF8:
    // 0x80050EF8: lh          $t8, 0x1A2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A2);
    // 0x80050EFC: nop

    // 0x80050F00: blez        $t8, L_80050F1C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80050F04: nop
    
            goto L_80050F1C;
    }
    // 0x80050F04: nop

    // 0x80050F08: bgtz        $a2, L_80050F1C
    if (SIGNED(ctx->r6) > 0) {
        // 0x80050F0C: addiu       $t9, $zero, -0x8000
        ctx->r25 = ADD32(0, -0X8000);
            goto L_80050F1C;
    }
    // 0x80050F0C: addiu       $t9, $zero, -0x8000
    ctx->r25 = ADD32(0, -0X8000);
    // 0x80050F10: sb          $zero, 0x1FA($s0)
    MEM_B(0X1FA, ctx->r16) = 0;
    // 0x80050F14: lb          $a0, 0x1FA($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1FA);
    // 0x80050F18: sh          $t9, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r25;
L_80050F1C:
    // 0x80050F1C: bne         $a0, $zero, L_80050F48
    if (ctx->r4 != 0) {
        // 0x80050F20: nop
    
            goto L_80050F48;
    }
    // 0x80050F20: nop

    // 0x80050F24: lh          $v1, 0x1A2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A2);
    // 0x80050F28: lh          $t2, 0x1A0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A0);
    // 0x80050F2C: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050F30: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80050F34: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80050F38: sh          $t3, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r11;
    // 0x80050F3C: sh          $zero, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = 0;
    // 0x80050F40: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x80050F44: sh          $v1, 0x19E($s0)
    MEM_H(0X19E, ctx->r16) = ctx->r3;
L_80050F48:
    // 0x80050F48: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x80050F4C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80050F50: beq         $a0, $zero, L_80050FB8
    if (ctx->r4 == 0) {
        // 0x80050F54: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80050FB8;
    }
    // 0x80050F54: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80050F58: lw          $t4, -0x2524($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2524);
    // 0x80050F5C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80050F60: bltz        $t4, L_80050FB8
    if (SIGNED(ctx->r12) < 0) {
        // 0x80050F64: nop
    
            goto L_80050FB8;
    }
    // 0x80050F64: nop

    // 0x80050F68: lw          $t5, -0x2EF8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2EF8);
    // 0x80050F6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80050F70: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80050F74: beq         $at, $zero, L_80050FB4
    if (ctx->r1 == 0) {
        // 0x80050F78: nop
    
            goto L_80050FB4;
    }
    // 0x80050F78: nop

    // 0x80050F7C: blez        $a0, L_80050F98
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80050F80: nop
    
            goto L_80050F98;
    }
    // 0x80050F80: nop

    // 0x80050F84: lw          $t6, 0x74($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X74);
    // 0x80050F88: nop

    // 0x80050F8C: ori         $t7, $t6, 0x1400
    ctx->r15 = ctx->r14 | 0X1400;
    // 0x80050F90: b           L_80050FA8
    // 0x80050F94: sw          $t7, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r15;
        goto L_80050FA8;
    // 0x80050F94: sw          $t7, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r15;
L_80050F98:
    // 0x80050F98: lw          $t8, 0x74($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X74);
    // 0x80050F9C: nop

    // 0x80050FA0: ori         $t9, $t8, 0x2800
    ctx->r25 = ctx->r24 | 0X2800;
    // 0x80050FA4: sw          $t9, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r25;
L_80050FA8:
    // 0x80050FA8: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x80050FAC: b           L_80050FB8
    // 0x80050FB0: nop

        goto L_80050FB8;
    // 0x80050FB0: nop

L_80050FB4:
    // 0x80050FB4: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_80050FB8:
    // 0x80050FB8: bne         $a0, $zero, L_80051030
    if (ctx->r4 != 0) {
        // 0x80050FBC: nop
    
            goto L_80051030;
    }
    // 0x80050FBC: nop

    // 0x80050FC0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80050FC4: lui         $at, 0xC008
    ctx->r1 = S32(0XC008 << 16);
    // 0x80050FC8: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80050FCC: beq         $t4, $zero, L_80051030
    if (ctx->r12 == 0) {
        // 0x80050FD0: nop
    
            goto L_80051030;
    }
    // 0x80050FD0: nop

    // 0x80050FD4: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80050FD8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80050FDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80050FE0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80050FE4: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80050FE8: nop

    // 0x80050FEC: bc1f        L_80051030
    if (!c1cs) {
        // 0x80050FF0: nop
    
            goto L_80051030;
    }
    // 0x80050FF0: nop

    // 0x80050FF4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80050FF8: nop

    // 0x80050FFC: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80051000: beq         $at, $zero, L_80051010
    if (ctx->r1 == 0) {
        // 0x80051004: slti        $at, $v0, -0xF
        ctx->r1 = SIGNED(ctx->r2) < -0XF ? 1 : 0;
            goto L_80051010;
    }
    // 0x80051004: slti        $at, $v0, -0xF
    ctx->r1 = SIGNED(ctx->r2) < -0XF ? 1 : 0;
    // 0x80051008: beq         $at, $zero, L_80051030
    if (ctx->r1 == 0) {
        // 0x8005100C: nop
    
            goto L_80051030;
    }
    // 0x8005100C: nop

L_80051010:
    // 0x80051010: bgez        $v0, L_80051024
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80051014: addiu       $t5, $zero, -0x1
        ctx->r13 = ADD32(0, -0X1);
            goto L_80051024;
    }
    // 0x80051014: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80051018: sb          $t5, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r13;
    // 0x8005101C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80051020: nop

L_80051024:
    // 0x80051024: blez        $v0, L_80051030
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80051028: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80051030;
    }
    // 0x80051028: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005102C: sb          $t6, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r14;
L_80051030:
    // 0x80051030: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051034: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051038: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005103C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80051040: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x80051044: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80051048: bc1f        L_80051054
    if (!c1cs) {
        // 0x8005104C: nop
    
            goto L_80051054;
    }
    // 0x8005104C: nop

    // 0x80051050: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
L_80051054:
    // 0x80051054: jal         0x80057260
    // 0x80051058: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    handle_racer_top_speed(rdram, ctx);
        goto after_2;
    // 0x80051058: sw          $a3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r7;
    after_2:
    // 0x8005105C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80051060: lw          $t7, -0x2558($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2558);
    // 0x80051064: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80051068: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8005106C: beq         $t8, $zero, L_800510D4
    if (ctx->r24 == 0) {
        // 0x80051070: nop
    
            goto L_800510D4;
    }
    // 0x80051070: nop

    // 0x80051074: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x80051078: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005107C: beq         $a0, $zero, L_800510D4
    if (ctx->r4 == 0) {
        // 0x80051080: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800510D4;
    }
    // 0x80051080: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80051084: lwc1        $f9, 0x6BD8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6BD8);
    // 0x80051088: lwc1        $f8, 0x6BDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6BDC);
    // 0x8005108C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80051090: mul.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80051094: lw          $t9, -0x254C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X254C);
    // 0x80051098: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x8005109C: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x800510A0: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800510A4: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800510A8: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x800510AC: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x800510B0: slti        $at, $v0, 0x4C
    ctx->r1 = SIGNED(ctx->r2) < 0X4C ? 1 : 0;
    // 0x800510B4: bne         $at, $zero, L_800510C0
    if (ctx->r1 != 0) {
        // 0x800510B8: swc1        $f18, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
            goto L_800510C0;
    }
    // 0x800510B8: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x800510BC: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
L_800510C0:
    // 0x800510C0: slti        $at, $v0, -0x4B
    ctx->r1 = SIGNED(ctx->r2) < -0X4B ? 1 : 0;
    // 0x800510C4: beq         $at, $zero, L_800510E0
    if (ctx->r1 == 0) {
        // 0x800510C8: nop
    
            goto L_800510E0;
    }
    // 0x800510C8: nop

    // 0x800510CC: b           L_800510E4
    // 0x800510D0: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
        goto L_800510E4;
    // 0x800510D0: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
L_800510D4:
    // 0x800510D4: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
    // 0x800510D8: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x800510DC: nop

L_800510E0:
    // 0x800510E0: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
L_800510E4:
    // 0x800510E4: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800510E8: sll         $t4, $a0, 13
    ctx->r12 = S32(ctx->r4 << 13);
    // 0x800510EC: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x800510F0: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800510F4: lh          $v1, 0x1A2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A2);
    // 0x800510F8: nop

    // 0x800510FC: slti        $at, $v1, 0x1801
    ctx->r1 = SIGNED(ctx->r3) < 0X1801 ? 1 : 0;
    // 0x80051100: mflo        $t7
    ctx->r15 = lo;
    // 0x80051104: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x80051108: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x8005110C: beq         $at, $zero, L_80051144
    if (ctx->r1 == 0) {
        // 0x80051110: sw          $t9, 0x10C($s0)
        MEM_W(0X10C, ctx->r16) = ctx->r25;
            goto L_80051144;
    }
    // 0x80051110: sw          $t9, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r25;
    // 0x80051114: slti        $at, $v1, -0x1800
    ctx->r1 = SIGNED(ctx->r3) < -0X1800 ? 1 : 0;
    // 0x80051118: bne         $at, $zero, L_80051148
    if (ctx->r1 != 0) {
        // 0x8005111C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80051148;
    }
    // 0x8005111C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80051120: bne         $a0, $zero, L_80051148
    if (ctx->r4 != 0) {
        // 0x80051124: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80051148;
    }
    // 0x80051124: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80051128: lb          $t2, 0x1FA($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1FA);
    // 0x8005112C: nop

    // 0x80051130: bne         $t2, $zero, L_80051148
    if (ctx->r10 != 0) {
        // 0x80051134: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80051148;
    }
    // 0x80051134: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80051138: lb          $t3, 0x1FB($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1FB);
    // 0x8005113C: nop

    // 0x80051140: beq         $t3, $zero, L_8005126C
    if (ctx->r11 == 0) {
        // 0x80051144: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8005126C;
    }
L_80051144:
    // 0x80051144: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80051148:
    // 0x80051148: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8005114C: lb          $t5, 0x1FB($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1FB);
    // 0x80051150: nop

    // 0x80051154: beq         $t5, $zero, L_80051180
    if (ctx->r13 == 0) {
        // 0x80051158: nop
    
            goto L_80051180;
    }
    // 0x80051158: nop

    // 0x8005115C: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x80051160: nop

    // 0x80051164: bne         $t6, $zero, L_80051180
    if (ctx->r14 != 0) {
        // 0x80051168: nop
    
            goto L_80051180;
    }
    // 0x80051168: nop

    // 0x8005116C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80051170: jal         0x80072594
    // 0x80051174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    rumble_set(rdram, ctx);
        goto after_3;
    // 0x80051174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80051178: lh          $v1, 0x1A2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A2);
    // 0x8005117C: nop

L_80051180:
    // 0x80051180: bgez        $v1, L_800511A8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80051184: lw          $t0, 0x78($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X78);
            goto L_800511A8;
    }
    // 0x80051184: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80051188: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005118C: nop

    // 0x80051190: lw          $t7, 0x74($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X74);
    // 0x80051194: nop

    // 0x80051198: ori         $t8, $t7, 0x1400
    ctx->r24 = ctx->r15 | 0X1400;
    // 0x8005119C: b           L_800511BC
    // 0x800511A0: sw          $t8, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r24;
        goto L_800511BC;
    // 0x800511A0: sw          $t8, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r24;
    // 0x800511A4: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
L_800511A8:
    // 0x800511A8: nop

    // 0x800511AC: lw          $t2, 0x74($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X74);
    // 0x800511B0: nop

    // 0x800511B4: ori         $t3, $t2, 0x2800
    ctx->r11 = ctx->r10 | 0X2800;
    // 0x800511B8: sw          $t3, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r11;
L_800511BC:
    // 0x800511BC: lb          $t4, 0x1E6($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E6);
    // 0x800511C0: nop

    // 0x800511C4: bne         $t4, $zero, L_800511EC
    if (ctx->r12 != 0) {
        // 0x800511C8: nop
    
            goto L_800511EC;
    }
    // 0x800511C8: nop

    // 0x800511CC: lb          $t5, 0x1FA($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1FA);
    // 0x800511D0: nop

    // 0x800511D4: bne         $t5, $zero, L_800511EC
    if (ctx->r13 != 0) {
        // 0x800511D8: nop
    
            goto L_800511EC;
    }
    // 0x800511D8: nop

    // 0x800511DC: lb          $t6, 0x1FB($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1FB);
    // 0x800511E0: nop

    // 0x800511E4: beq         $t6, $zero, L_8005124C
    if (ctx->r14 == 0) {
        // 0x800511E8: nop
    
            goto L_8005124C;
    }
    // 0x800511E8: nop

L_800511EC:
    // 0x800511EC: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800511F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800511F4: bne         $v0, $zero, L_80051218
    if (ctx->r2 != 0) {
        // 0x800511F8: addiu       $t7, $s0, 0x10
        ctx->r15 = ADD32(ctx->r16, 0X10);
            goto L_80051218;
    }
    // 0x800511F8: addiu       $t7, $s0, 0x10
    ctx->r15 = ADD32(ctx->r16, 0X10);
    // 0x800511FC: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x80051200: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x80051204: lw          $a3, 0x14($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X14);
    // 0x80051208: jal         0x80001EA8
    // 0x8005120C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    sound_play_spatial(rdram, ctx);
        goto after_4;
    // 0x8005120C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x80051210: b           L_80051230
    // 0x80051214: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
        goto L_80051230;
    // 0x80051214: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_80051218:
    // 0x80051218: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x8005121C: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x80051220: lw          $a3, 0x14($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X14);
    // 0x80051224: jal         0x80009B7C
    // 0x80051228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    audspat_calculate_echo(rdram, ctx);
        goto after_5;
    // 0x80051228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8005122C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_80051230:
    // 0x80051230: nop

    // 0x80051234: beq         $v0, $zero, L_80051244
    if (ctx->r2 == 0) {
        // 0x80051238: nop
    
            goto L_80051244;
    }
    // 0x80051238: nop

    // 0x8005123C: jal         0x8000488C
    // 0x80051240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_6;
    // 0x80051240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
L_80051244:
    // 0x80051244: b           L_8005129C
    // 0x80051248: nop

        goto L_8005129C;
    // 0x80051248: nop

L_8005124C:
    // 0x8005124C: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80051250: nop

    // 0x80051254: beq         $v0, $zero, L_8005129C
    if (ctx->r2 == 0) {
        // 0x80051258: nop
    
            goto L_8005129C;
    }
    // 0x80051258: nop

    // 0x8005125C: jal         0x8000488C
    // 0x80051260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_7;
    // 0x80051260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80051264: b           L_8005129C
    // 0x80051268: nop

        goto L_8005129C;
    // 0x80051268: nop

L_8005126C:
    // 0x8005126C: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80051270: nop

    // 0x80051274: beq         $v0, $zero, L_80051284
    if (ctx->r2 == 0) {
        // 0x80051278: nop
    
            goto L_80051284;
    }
    // 0x80051278: nop

    // 0x8005127C: jal         0x8000488C
    // 0x80051280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_8;
    // 0x80051280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
L_80051284:
    // 0x80051284: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80051288: nop

    // 0x8005128C: beq         $v0, $zero, L_8005129C
    if (ctx->r2 == 0) {
        // 0x80051290: nop
    
            goto L_8005129C;
    }
    // 0x80051290: nop

    // 0x80051294: jal         0x8000488C
    // 0x80051298: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_9;
    // 0x80051298: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
L_8005129C:
    // 0x8005129C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800512A0: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x800512A4: lb          $v1, 0x1E1($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E1);
    // 0x800512A8: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x800512AC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800512B0: beq         $t8, $zero, L_800512BC
    if (ctx->r24 == 0) {
        // 0x800512B4: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800512BC;
    }
    // 0x800512B4: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800512B8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
L_800512BC:
    // 0x800512BC: beq         $v0, $zero, L_800512D8
    if (ctx->r2 == 0) {
        // 0x800512C0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800512D8;
    }
    // 0x800512C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800512C4: lb          $t2, 0x1E6($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1E6);
    // 0x800512C8: nop

    // 0x800512CC: beq         $t2, $zero, L_800512D8
    if (ctx->r10 == 0) {
        // 0x800512D0: nop
    
            goto L_800512D8;
    }
    // 0x800512D0: nop

    // 0x800512D4: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
L_800512D8:
    // 0x800512D8: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800512DC: lwc1        $f5, 0x6BE0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6BE0);
    // 0x800512E0: lwc1        $f4, 0x6BE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6BE4);
    // 0x800512E4: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x800512E8: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x800512EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800512F0: bc1f        L_80051308
    if (!c1cs) {
        // 0x800512F4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80051308;
    }
    // 0x800512F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800512F8: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800512FC: mflo        $v0
    ctx->r2 = lo;
    // 0x80051300: nop

    // 0x80051304: nop

L_80051308:
    // 0x80051308: lwc1        $f9, 0x6BE8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6BE8);
    // 0x8005130C: lwc1        $f8, 0x6BEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6BEC);
    // 0x80051310: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80051314: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x80051318: nop

    // 0x8005131C: bc1f        L_80051334
    if (!c1cs) {
        // 0x80051320: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_80051334;
    }
    // 0x80051320: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x80051324: multu       $t3, $a2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80051328: mflo        $v0
    ctx->r2 = lo;
    // 0x8005132C: nop

    // 0x80051330: nop

L_80051334:
    // 0x80051334: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80051338: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005133C: lwc1        $f10, -0x2510($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2510);
    // 0x80051340: lh          $t6, 0x1A0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A0);
    // 0x80051344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80051348: mflo        $v0
    ctx->r2 = lo;
    // 0x8005134C: sra         $t4, $v0, 1
    ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80051350: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80051354: nop

    // 0x80051358: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005135C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80051360: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80051364: nop

    // 0x80051368: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8005136C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80051370: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80051374: nop

    // 0x80051378: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8005137C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80051380: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80051384: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80051388: jal         0x800534B8
    // 0x8005138C: sh          $t8, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r24;
    handle_car_steering(rdram, ctx);
        goto after_10;
    // 0x8005138C: sh          $t8, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r24;
    after_10:
    // 0x80051390: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051394: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x80051398: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005139C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800513A0: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x800513A4: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x800513A8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800513AC: bc1f        L_80051478
    if (!c1cs) {
        // 0x800513B0: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80051478;
    }
    // 0x800513B0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800513B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800513B8: lw          $v0, -0x252C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X252C);
    // 0x800513BC: nop

    // 0x800513C0: slti        $at, $v0, 0x1401
    ctx->r1 = SIGNED(ctx->r2) < 0X1401 ? 1 : 0;
    // 0x800513C4: beq         $at, $zero, L_800513E4
    if (ctx->r1 == 0) {
        // 0x800513C8: nop
    
            goto L_800513E4;
    }
    // 0x800513C8: nop

    // 0x800513CC: lb          $a0, 0x1E6($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E6);
    // 0x800513D0: slti        $at, $v0, -0x1400
    ctx->r1 = SIGNED(ctx->r2) < -0X1400 ? 1 : 0;
    // 0x800513D4: beq         $a0, $zero, L_80051424
    if (ctx->r4 == 0) {
        // 0x800513D8: nop
    
            goto L_80051424;
    }
    // 0x800513D8: nop

    // 0x800513DC: blez        $v0, L_80051424
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800513E0: nop
    
            goto L_80051424;
    }
    // 0x800513E0: nop

L_800513E4:
    // 0x800513E4: lb          $a2, 0x1E7($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1E7);
    // 0x800513E8: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x800513EC: andi        $t2, $a2, 0x7
    ctx->r10 = ctx->r6 & 0X7;
    // 0x800513F0: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x800513F4: bne         $at, $zero, L_80051400
    if (ctx->r1 != 0) {
        // 0x800513F8: or          $a2, $t2, $zero
        ctx->r6 = ctx->r10 | 0;
            goto L_80051400;
    }
    // 0x800513F8: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800513FC: subu        $a2, $t3, $t2
    ctx->r6 = SUB32(ctx->r11, ctx->r10);
L_80051400:
    // 0x80051400: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80051404: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x80051408: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8005140C: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x80051410: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80051414: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x80051418: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005141C: b           L_80051478
    // 0x80051420: sw          $t4, -0x252C($at)
    MEM_W(-0X252C, ctx->r1) = ctx->r12;
        goto L_80051478;
    // 0x80051420: sw          $t4, -0x252C($at)
    MEM_W(-0X252C, ctx->r1) = ctx->r12;
L_80051424:
    // 0x80051424: bne         $at, $zero, L_8005143C
    if (ctx->r1 != 0) {
        // 0x80051428: nop
    
            goto L_8005143C;
    }
    // 0x80051428: nop

    // 0x8005142C: beq         $a0, $zero, L_80051478
    if (ctx->r4 == 0) {
        // 0x80051430: nop
    
            goto L_80051478;
    }
    // 0x80051430: nop

    // 0x80051434: bgez        $v0, L_80051478
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80051438: nop
    
            goto L_80051478;
    }
    // 0x80051438: nop

L_8005143C:
    // 0x8005143C: lb          $a2, 0x1E7($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1E7);
    // 0x80051440: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80051444: andi        $t5, $a2, 0x7
    ctx->r13 = ctx->r6 & 0X7;
    // 0x80051448: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8005144C: bne         $at, $zero, L_80051458
    if (ctx->r1 != 0) {
        // 0x80051450: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_80051458;
    }
    // 0x80051450: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80051454: subu        $a2, $t6, $t5
    ctx->r6 = SUB32(ctx->r14, ctx->r13);
L_80051458:
    // 0x80051458: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8005145C: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80051460: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80051464: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x80051468: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8005146C: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x80051470: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80051474: sw          $t8, -0x252C($at)
    MEM_W(-0X252C, ctx->r1) = ctx->r24;
L_80051478:
    // 0x80051478: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005147C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80051480: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80051484: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80051488: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005148C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
L_80051490:
    // 0x80051490: lbu         $t2, 0x1DC($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1DC);
    // 0x80051494: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80051498: beq         $t2, $at, L_8005157C
    if (ctx->r10 == ctx->r1) {
        // 0x8005149C: nop
    
            goto L_8005157C;
    }
    // 0x8005149C: nop

    // 0x800514A0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x800514A4: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800514A8: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    // 0x800514AC: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x800514B0: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800514B4: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x800514B8: jal         0x8009C850
    // 0x800514BC: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_11;
    // 0x800514BC: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    after_11:
    // 0x800514C0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800514C4: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x800514C8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800514CC: lb          $t0, 0x57($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X57);
    // 0x800514D0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800514D4: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800514D8: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800514DC: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800514E0: sll         $t3, $v0, 8
    ctx->r11 = S32(ctx->r2 << 8);
    // 0x800514E4: bgez        $t3, L_80051500
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800514E8: addiu       $a3, $a3, -0x2EF4
        ctx->r7 = ADD32(ctx->r7, -0X2EF4);
            goto L_80051500;
    }
    // 0x800514E8: addiu       $a3, $a3, -0x2EF4
    ctx->r7 = ADD32(ctx->r7, -0X2EF4);
    // 0x800514EC: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800514F0: lbu         $v0, 0x1DC($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1DC);
    // 0x800514F4: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x800514F8: b           L_8005151C
    // 0x800514FC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_8005151C;
    // 0x800514FC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_80051500:
    // 0x80051500: lbu         $v0, 0x1DC($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1DC);
    // 0x80051504: nop

    // 0x80051508: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8005150C: addu        $t9, $a3, $v1
    ctx->r25 = ADD32(ctx->r7, ctx->r3);
    // 0x80051510: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80051514: nop

    // 0x80051518: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
L_8005151C:
    // 0x8005151C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051520: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80051524: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80051528: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x8005152C: lwc1        $f6, -0x2EA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2EA8);
    // 0x80051530: lw          $t5, -0x2E5C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E5C);
    // 0x80051534: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80051538: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005153C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80051540: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x80051544: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80051548: beq         $at, $zero, L_80051554
    if (ctx->r1 == 0) {
        // 0x8005154C: add.s       $f16, $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
            goto L_80051554;
    }
    // 0x8005154C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80051550: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_80051554:
    // 0x80051554: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80051558: bne         $a0, $at, L_80051570
    if (ctx->r4 != ctx->r1) {
        // 0x8005155C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80051570;
    }
    // 0x8005155C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80051560: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80051564: sll         $t7, $t0, 24
    ctx->r15 = S32(ctx->r8 << 24);
    // 0x80051568: sra         $t0, $t7, 24
    ctx->r8 = S32(SIGNED(ctx->r15) >> 24);
    // 0x8005156C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80051570:
    // 0x80051570: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80051574: nop

    // 0x80051578: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_8005157C:
    // 0x8005157C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80051580: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80051584: bne         $at, $zero, L_80051490
    if (ctx->r1 != 0) {
        // 0x80051588: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80051490;
    }
    // 0x80051588: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005158C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80051590: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80051594: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80051598: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8005159C: nop

    // 0x800515A0: bc1f        L_800515B4
    if (!c1cs) {
        // 0x800515A4: nop
    
            goto L_800515B4;
    }
    // 0x800515A4: nop

    // 0x800515A8: div.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800515AC: nop

    // 0x800515B0: div.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
L_800515B4:
    // 0x800515B4: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x800515B8: nop

    // 0x800515BC: bne         $t2, $zero, L_800515F4
    if (ctx->r10 != 0) {
        // 0x800515C0: nop
    
            goto L_800515F4;
    }
    // 0x800515C0: nop

    // 0x800515C4: lb          $t3, 0x1E2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E2);
    // 0x800515C8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800515CC: beq         $t3, $zero, L_800515F4
    if (ctx->r11 == 0) {
        // 0x800515D0: nop
    
            goto L_800515F4;
    }
    // 0x800515D0: nop

    // 0x800515D4: bne         $t1, $at, L_800515F4
    if (ctx->r9 != ctx->r1) {
        // 0x800515D8: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800515F4;
    }
    // 0x800515D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800515DC: lw          $t9, -0x2554($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2554);
    // 0x800515E0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800515E4: andi        $t4, $t9, 0x2000
    ctx->r12 = ctx->r25 & 0X2000;
    // 0x800515E8: beq         $t4, $zero, L_800515F4
    if (ctx->r12 == 0) {
        // 0x800515EC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800515F4;
    }
    // 0x800515EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800515F0: sb          $t5, -0x24FE($at)
    MEM_B(-0X24FE, ctx->r1) = ctx->r13;
L_800515F4:
    // 0x800515F4: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800515F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800515FC: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80051600: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80051604: nop

    // 0x80051608: bc1t        L_8005161C
    if (c1cs) {
        // 0x8005160C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005161C;
    }
    // 0x8005160C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051610: lwc1        $f14, 0x6BF0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6BF0);
    // 0x80051614: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80051618: nop

L_8005161C:
    // 0x8005161C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051620: bne         $t1, $at, L_8005168C
    if (ctx->r9 != ctx->r1) {
        // 0x80051624: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8005168C;
    }
    // 0x80051624: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80051628: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005162C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051630: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80051634: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80051638: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8005163C: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80051640: nop

    // 0x80051644: bc1f        L_8005168C
    if (!c1cs) {
        // 0x80051648: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8005168C;
    }
    // 0x80051648: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8005164C: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x80051650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80051654: bne         $t6, $zero, L_8005168C
    if (ctx->r14 != 0) {
        // 0x80051658: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_8005168C;
    }
    // 0x80051658: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8005165C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80051660: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x80051664: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80051668: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8005166C: jal         0x80072594
    // 0x80051670: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    rumble_set(rdram, ctx);
        goto after_12;
    // 0x80051670: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    after_12:
    // 0x80051674: lb          $t0, 0x57($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X57);
    // 0x80051678: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8005167C: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80051680: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80051684: nop

    // 0x80051688: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8005168C:
    // 0x8005168C: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    // 0x80051690: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80051694: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80051698: jal         0x8001E2D0
    // 0x8005169C: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    get_misc_asset(rdram, ctx);
        goto after_13;
    // 0x8005169C: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x800516A0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800516A4: lw          $t7, -0x2524($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2524);
    // 0x800516A8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800516AC: lb          $t0, 0x57($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X57);
    // 0x800516B0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800516B4: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800516B8: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800516BC: beq         $v1, $t7, L_80051760
    if (ctx->r3 == ctx->r15) {
        // 0x800516C0: nop
    
            goto L_80051760;
    }
    // 0x800516C0: nop

    // 0x800516C4: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800516C8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800516CC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800516D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800516D4: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x800516D8: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800516DC: nop

    // 0x800516E0: bc1t        L_80051760
    if (c1cs) {
        // 0x800516E4: nop
    
            goto L_80051760;
    }
    // 0x800516E4: nop

    // 0x800516E8: lb          $t8, 0x1E6($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E6);
    // 0x800516EC: nop

    // 0x800516F0: bne         $t8, $zero, L_80051760
    if (ctx->r24 != 0) {
        // 0x800516F4: nop
    
            goto L_80051760;
    }
    // 0x800516F4: nop

    // 0x800516F8: lb          $t2, 0x1D8($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D8);
    // 0x800516FC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80051700: bne         $t2, $zero, L_80051760
    if (ctx->r10 != 0) {
        // 0x80051704: nop
    
            goto L_80051760;
    }
    // 0x80051704: nop

    // 0x80051708: lw          $t3, -0x254C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X254C);
    // 0x8005170C: lb          $t9, 0x3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X3);
    // 0x80051710: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80051714: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80051718: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005171C: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80051720: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80051724: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80051728: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8005172C: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80051730: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051734: div.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80051738: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8005173C: bne         $v1, $t6, L_80051760
    if (ctx->r3 != ctx->r14) {
        // 0x80051740: swc1        $f10, 0x30($s0)
        MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
            goto L_80051760;
    }
    // 0x80051740: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x80051744: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80051748: lwc1        $f19, 0x6BF8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6BF8);
    // 0x8005174C: lwc1        $f18, 0x6BFC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6BFC);
    // 0x80051750: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80051754: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80051758: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8005175C: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_80051760:
    // 0x80051760: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051764: lui         $at, 0xC008
    ctx->r1 = S32(0XC008 << 16);
    // 0x80051768: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005176C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051770: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
    // 0x80051774: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80051778: nop

    // 0x8005177C: bc1f        L_80051834
    if (!c1cs) {
        // 0x80051780: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80051834;
    }
    // 0x80051780: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80051784: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80051788: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005178C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80051790: add.d       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f2.d + ctx->f18.d;
    // 0x80051794: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80051798: neg.d       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = -ctx->f6.d;
    // 0x8005179C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800517A0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800517A4: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x800517A8: c.lt.d      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.d < ctx->f8.d;
    // 0x800517AC: nop

    // 0x800517B0: bc1f        L_800517C4
    if (!c1cs) {
        // 0x800517B4: nop
    
            goto L_800517C4;
    }
    // 0x800517B4: nop

    // 0x800517B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800517BC: nop

    // 0x800517C0: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
L_800517C4:
    // 0x800517C4: lw          $t7, -0x252C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X252C);
    // 0x800517C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800517CC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800517D0: nop

    // 0x800517D4: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800517D8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800517DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800517E0: nop

    // 0x800517E4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800517E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800517EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800517F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800517F4: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800517F8: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800517FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80051800: sw          $t2, -0x252C($at)
    MEM_W(-0X252C, ctx->r1) = ctx->r10;
    // 0x80051804: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80051808: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005180C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051810: lwc1        $f19, 0x6C00($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6C00);
    // 0x80051814: lwc1        $f18, 0x6C04($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6C04);
    // 0x80051818: sub.d       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f8.d - ctx->f12.d;
    // 0x8005181C: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x80051820: nop

    // 0x80051824: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80051828: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8005182C: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x80051830: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
L_80051834:
    // 0x80051834: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80051838: lh          $a0, 0x1A4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A4);
    // 0x8005183C: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80051840: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x80051844: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80051848: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8005184C: jal         0x80070A38
    // 0x80051850: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    coss_f(rdram, ctx);
        goto after_14;
    // 0x80051850: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    after_14:
    // 0x80051854: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80051858: lb          $t0, 0x57($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X57);
    // 0x8005185C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80051860: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051864: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80051868: bc1f        L_80051874
    if (!c1cs) {
        // 0x8005186C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80051874;
    }
    // 0x8005186C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80051870: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80051874:
    // 0x80051874: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80051878: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005187C: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80051880: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x80051884: beq         $t0, $zero, L_800518D4
    if (ctx->r8 == 0) {
        // 0x80051888: sb          $t1, -0x24FF($at)
        MEM_B(-0X24FF, ctx->r1) = ctx->r9;
            goto L_800518D4;
    }
    // 0x80051888: sb          $t1, -0x24FF($at)
    MEM_B(-0X24FF, ctx->r1) = ctx->r9;
    // 0x8005188C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80051890: sb          $t0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r8;
    // 0x80051894: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80051898: jal         0x8001E2D0
    // 0x8005189C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    get_misc_asset(rdram, ctx);
        goto after_15;
    // 0x8005189C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    after_15:
    // 0x800518A0: lb          $t0, 0x57($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X57);
    // 0x800518A4: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800518A8: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x800518AC: addu        $t9, $v0, $t3
    ctx->r25 = ADD32(ctx->r2, ctx->r11);
    // 0x800518B0: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800518B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800518B8: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800518BC: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x800518C0: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800518C4: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x800518C8: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x800518CC: b           L_8005190C
    // 0x800518D0: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
        goto L_8005190C;
    // 0x800518D0: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
L_800518D4:
    // 0x800518D4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800518D8: bne         $t1, $at, L_8005190C
    if (ctx->r9 != ctx->r1) {
        // 0x800518DC: nop
    
            goto L_8005190C;
    }
    // 0x800518DC: nop

    // 0x800518E0: lbu         $t4, 0x1EF($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1EF);
    // 0x800518E4: addiu       $a1, $zero, 0x138
    ctx->r5 = ADD32(0, 0X138);
    // 0x800518E8: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x800518EC: sb          $t5, 0x1EF($s0)
    MEM_B(0X1EF, ctx->r16) = ctx->r13;
    // 0x800518F0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x800518F4: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x800518F8: jal         0x80057088
    // 0x800518FC: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    racer_play_sound(rdram, ctx);
        goto after_16;
    // 0x800518FC: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    after_16:
    // 0x80051900: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051904: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80051908: nop

L_8005190C:
    // 0x8005190C: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x80051910: nop

    // 0x80051914: bne         $t6, $zero, L_8005198C
    if (ctx->r14 != 0) {
        // 0x80051918: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005198C;
    }
    // 0x80051918: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005191C: bne         $t1, $at, L_8005198C
    if (ctx->r9 != ctx->r1) {
        // 0x80051920: addiu       $a0, $zero, 0x2D
        ctx->r4 = ADD32(0, 0X2D);
            goto L_8005198C;
    }
    // 0x80051920: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x80051924: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80051928: jal         0x8000C8B4
    // 0x8005192C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    normalise_time(rdram, ctx);
        goto after_17;
    // 0x8005192C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    after_17:
    // 0x80051930: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80051934: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x80051938: sb          $t7, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r15;
    // 0x8005193C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80051940: jal         0x80057088
    // 0x80051944: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    racer_play_sound(rdram, ctx);
        goto after_18;
    // 0x80051944: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    after_18:
    // 0x80051948: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8005194C: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80051950: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80051954: jal         0x800570F8
    // 0x80051958: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_19;
    // 0x80051958: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_19:
    // 0x8005195C: lb          $t8, 0x1D8($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D8);
    // 0x80051960: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051964: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80051968: bne         $t8, $zero, L_8005198C
    if (ctx->r24 != 0) {
        // 0x8005196C: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_8005198C;
    }
    // 0x8005196C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80051970: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80051974: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x80051978: jal         0x80072594
    // 0x8005197C: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    rumble_set(rdram, ctx);
        goto after_20;
    // 0x8005197C: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    after_20:
    // 0x80051980: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051984: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80051988: nop

L_8005198C:
    // 0x8005198C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80051990: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80051994: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80051998: nop

    // 0x8005199C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800519A0: nop

    // 0x800519A4: bc1f        L_800519E4
    if (!c1cs) {
        // 0x800519A8: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800519E4;
    }
    // 0x800519A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800519AC: lw          $t2, -0x2558($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2558);
    // 0x800519B0: nop

    // 0x800519B4: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x800519B8: bne         $t3, $zero, L_800519E4
    if (ctx->r11 != 0) {
        // 0x800519BC: nop
    
            goto L_800519E4;
    }
    // 0x800519BC: nop

    // 0x800519C0: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800519C4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800519C8: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800519CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800519D0: nop

    // 0x800519D4: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800519D8: sub.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x800519DC: b           L_800519F8
    // 0x800519E0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
        goto L_800519F8;
    // 0x800519E0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_800519E4:
    // 0x800519E4: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800519E8: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800519EC: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800519F0: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800519F4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_800519F8:
    // 0x800519F8: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800519FC: nop

    // 0x80051A00: beq         $t9, $zero, L_80051A24
    if (ctx->r25 == 0) {
        // 0x80051A04: nop
    
            goto L_80051A24;
    }
    // 0x80051A04: nop

    // 0x80051A08: lbu         $v0, 0x1EE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1EE);
    // 0x80051A0C: nop

    // 0x80051A10: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80051A14: beq         $at, $zero, L_80051A28
    if (ctx->r1 == 0) {
        // 0x80051A18: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_80051A28;
    }
    // 0x80051A18: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80051A1C: b           L_80051A28
    // 0x80051A20: sb          $t4, 0x1EE($s0)
    MEM_B(0X1EE, ctx->r16) = ctx->r12;
        goto L_80051A28;
    // 0x80051A20: sb          $t4, 0x1EE($s0)
    MEM_B(0X1EE, ctx->r16) = ctx->r12;
L_80051A24:
    // 0x80051A24: sb          $zero, 0x1EE($s0)
    MEM_B(0X1EE, ctx->r16) = 0;
L_80051A28:
    // 0x80051A28: jal         0x80066450
    // 0x80051A2C: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    cam_get_viewport_layout(rdram, ctx);
        goto after_21;
    // 0x80051A2C: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    after_21:
    // 0x80051A30: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051A34: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80051A38: beq         $at, $zero, L_80051B68
    if (ctx->r1 == 0) {
        // 0x80051A3C: sll         $t8, $t1, 2
        ctx->r24 = S32(ctx->r9 << 2);
            goto L_80051B68;
    }
    // 0x80051A3C: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80051A40: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80051A44: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80051A48: beq         $t5, $zero, L_80051A70
    if (ctx->r13 == 0) {
        // 0x80051A4C: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80051A70;
    }
    // 0x80051A4C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051A50: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051A54: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80051A58: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80051A5C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80051A60: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x80051A64: nop

    // 0x80051A68: bc1t        L_80051A88
    if (c1cs) {
        // 0x80051A6C: nop
    
            goto L_80051A88;
    }
    // 0x80051A6C: nop

L_80051A70:
    // 0x80051A70: bne         $t6, $zero, L_80051A88
    if (ctx->r14 != 0) {
        // 0x80051A74: nop
    
            goto L_80051A88;
    }
    // 0x80051A74: nop

    // 0x80051A78: lb          $t7, 0x1FB($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1FB);
    // 0x80051A7C: nop

    // 0x80051A80: beq         $t7, $zero, L_80051AE8
    if (ctx->r15 == 0) {
        // 0x80051A84: nop
    
            goto L_80051AE8;
    }
    // 0x80051A84: nop

L_80051A88:
    // 0x80051A88: lbu         $v0, 0x1DE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1DE);
    // 0x80051A8C: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051A90: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80051A94: beq         $at, $zero, L_80051AB8
    if (ctx->r1 == 0) {
        // 0x80051A98: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_80051AB8;
    }
    // 0x80051A98: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80051A9C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80051AA0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80051AA4: lw          $t3, -0x2D9C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2D9C);
    // 0x80051AA8: lw          $t8, 0x74($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X74);
    // 0x80051AAC: nop

    // 0x80051AB0: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x80051AB4: sw          $t9, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r25;
L_80051AB8:
    // 0x80051AB8: lbu         $v0, 0x1DF($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1DF);
    // 0x80051ABC: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051AC0: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80051AC4: beq         $at, $zero, L_80051AE8
    if (ctx->r1 == 0) {
        // 0x80051AC8: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_80051AE8;
    }
    // 0x80051AC8: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80051ACC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80051AD0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80051AD4: lw          $t6, -0x2D9C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D9C);
    // 0x80051AD8: lw          $t4, 0x74($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X74);
    // 0x80051ADC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80051AE0: or          $t2, $t4, $t7
    ctx->r10 = ctx->r12 | ctx->r15;
    // 0x80051AE4: sw          $t2, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r10;
L_80051AE8:
    // 0x80051AE8: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051AEC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051AF0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80051AF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051AF8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80051AFC: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x80051B00: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051B04: bc1f        L_80051B68
    if (!c1cs) {
        // 0x80051B08: sll         $t8, $t1, 2
        ctx->r24 = S32(ctx->r9 << 2);
            goto L_80051B68;
    }
    // 0x80051B08: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80051B0C: lbu         $v0, 0x1DE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1DE);
    // 0x80051B10: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80051B14: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80051B18: beq         $at, $zero, L_80051B38
    if (ctx->r1 == 0) {
        // 0x80051B1C: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_80051B38;
    }
    // 0x80051B1C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80051B20: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x80051B24: lw          $t9, -0x2D50($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D50);
    // 0x80051B28: lw          $t8, 0x74($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X74);
    // 0x80051B2C: nop

    // 0x80051B30: or          $t5, $t8, $t9
    ctx->r13 = ctx->r24 | ctx->r25;
    // 0x80051B34: sw          $t5, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r13;
L_80051B38:
    // 0x80051B38: lbu         $v0, 0x1DF($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1DF);
    // 0x80051B3C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80051B40: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80051B44: beq         $at, $zero, L_80051B64
    if (ctx->r1 == 0) {
        // 0x80051B48: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_80051B64;
    }
    // 0x80051B48: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80051B4C: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x80051B50: lw          $t7, -0x2D50($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2D50);
    // 0x80051B54: lw          $t6, 0x74($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X74);
    // 0x80051B58: sll         $t2, $t7, 1
    ctx->r10 = S32(ctx->r15 << 1);
    // 0x80051B5C: or          $t3, $t6, $t2
    ctx->r11 = ctx->r14 | ctx->r10;
    // 0x80051B60: sw          $t3, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r11;
L_80051B64:
    // 0x80051B64: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
L_80051B68:
    // 0x80051B68: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80051B6C: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80051B70: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80051B74: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051B78: lw          $t1, -0x2E10($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E10);
    // 0x80051B7C: bne         $v0, $zero, L_80051BC4
    if (ctx->r2 != 0) {
        // 0x80051B80: nop
    
            goto L_80051BC4;
    }
    // 0x80051B80: nop

    // 0x80051B84: beq         $t1, $zero, L_80051BC4
    if (ctx->r9 == 0) {
        // 0x80051B88: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80051BC4;
    }
    // 0x80051B88: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051B8C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051B90: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80051B94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80051B98: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80051B9C: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80051BA0: andi        $a0, $t1, 0xFFFF
    ctx->r4 = ctx->r9 & 0XFFFF;
    // 0x80051BA4: bc1f        L_80051BC4
    if (!c1cs) {
        // 0x80051BA8: addiu       $a1, $s0, 0x18
        ctx->r5 = ADD32(ctx->r16, 0X18);
            goto L_80051BC4;
    }
    // 0x80051BA8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80051BAC: jal         0x80001D04
    // 0x80051BB0: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    sound_play(rdram, ctx);
        goto after_22;
    // 0x80051BB0: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    after_22:
    // 0x80051BB4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051BB8: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80051BBC: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051BC0: nop

L_80051BC4:
    // 0x80051BC4: beq         $v0, $zero, L_80051C08
    if (ctx->r2 == 0) {
        // 0x80051BC8: nop
    
            goto L_80051C08;
    }
    // 0x80051BC8: nop

    // 0x80051BCC: beq         $t1, $zero, L_80051BF0
    if (ctx->r9 == 0) {
        // 0x80051BD0: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80051BF0;
    }
    // 0x80051BD0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051BD4: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051BD8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80051BDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80051BE0: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80051BE4: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80051BE8: nop

    // 0x80051BEC: bc1f        L_80051C08
    if (!c1cs) {
        // 0x80051BF0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80051C08;
    }
L_80051BF0:
    // 0x80051BF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80051BF4: jal         0x8000488C
    // 0x80051BF8: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    sndp_stop(rdram, ctx);
        goto after_23;
    // 0x80051BF8: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    after_23:
    // 0x80051BFC: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80051C00: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80051C04: nop

L_80051C08:
    // 0x80051C08: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051C0C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051C10: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80051C14: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80051C18: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x80051C1C: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80051C20: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80051C24: bc1f        L_80051CA8
    if (!c1cs) {
        // 0x80051C28: nop
    
            goto L_80051CA8;
    }
    // 0x80051C28: nop

    // 0x80051C2C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80051C30: nop

    // 0x80051C34: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80051C38: bne         $at, $zero, L_80051CA8
    if (ctx->r1 != 0) {
        // 0x80051C3C: nop
    
            goto L_80051CA8;
    }
    // 0x80051C3C: nop

    // 0x80051C40: lb          $t5, 0x1E7($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E7);
    // 0x80051C44: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80051C48: andi        $t4, $t5, 0x1
    ctx->r12 = ctx->r13 & 0X1;
    // 0x80051C4C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80051C50: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80051C54: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80051C58: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80051C5C: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80051C60: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80051C64: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80051C68: lwc1        $f8, 0xA0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x80051C6C: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051C70: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80051C74: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80051C78: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80051C7C: lwc1        $f8, 0xA4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x80051C80: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80051C84: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80051C88: lwc1        $f8, 0x9C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80051C8C: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x80051C90: lwc1        $f18, 0x80($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80051C94: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80051C98: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80051C9C: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x80051CA0: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80051CA4: swc1        $f4, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f4.u32l;
L_80051CA8:
    // 0x80051CA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80051CAC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80051CB0: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80051CB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80051CB8: bc1f        L_80051CC4
    if (!c1cs) {
        // 0x80051CBC: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_80051CC4;
    }
    // 0x80051CBC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80051CC0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_80051CC4:
    // 0x80051CC4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80051CC8: nop

    // 0x80051CCC: bc1f        L_80051CD8
    if (!c1cs) {
        // 0x80051CD0: nop
    
            goto L_80051CD8;
    }
    // 0x80051CD0: nop

    // 0x80051CD4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80051CD8:
    // 0x80051CD8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80051CDC: lw          $t6, -0x251C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X251C);
    // 0x80051CE0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80051CE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80051CE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80051CEC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80051CF0: cvt.w.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80051CF4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80051CF8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80051CFC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80051D00: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80051D04: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80051D08: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80051D0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051D10: addu        $v1, $t6, $t2
    ctx->r3 = ADD32(ctx->r14, ctx->r10);
    // 0x80051D14: sub.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80051D18: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80051D1C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80051D20: sub.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f4.d - ctx->f10.d;
    // 0x80051D24: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80051D28: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80051D2C: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80051D30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051D34: lb          $t3, 0x1D3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D3);
    // 0x80051D38: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80051D3C: lwc1        $f19, 0x6C08($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6C08);
    // 0x80051D40: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80051D44: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80051D48: lwc1        $f18, 0x6C0C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6C0C);
    // 0x80051D4C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80051D50: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80051D54: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x80051D58: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80051D5C: cvt.s.d     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f14.fl = CVT_S_D(ctx->f4.d);
    // 0x80051D60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051D64: mul.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80051D68: blez        $t3, L_80051DC4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80051D6C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80051DC4;
    }
    // 0x80051D6C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80051D70: lw          $t8, -0x2540($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2540);
    // 0x80051D74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80051D78: bne         $t8, $zero, L_80051DBC
    if (ctx->r24 != 0) {
        // 0x80051D7C: nop
    
            goto L_80051DBC;
    }
    // 0x80051D7C: nop

    // 0x80051D80: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80051D84: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80051D88: cvt.d.s     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.d = CVT_D_S(ctx->f14.fl);
    // 0x80051D8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80051D90: c.eq.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d == ctx->f18.d;
    // 0x80051D94: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80051D98: bc1t        L_80051DA8
    if (c1cs) {
        // 0x80051D9C: swc1        $f8, 0xB4($s0)
        MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
            goto L_80051DA8;
    }
    // 0x80051D9C: swc1        $f8, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
    // 0x80051DA0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80051DA4: nop

L_80051DA8:
    // 0x80051DA8: lb          $t9, 0x1D3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D3);
    // 0x80051DAC: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x80051DB0: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051DB4: subu        $t4, $t9, $t5
    ctx->r12 = SUB32(ctx->r25, ctx->r13);
    // 0x80051DB8: sb          $t4, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r12;
L_80051DBC:
    // 0x80051DBC: b           L_80051DD0
    // 0x80051DC0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
        goto L_80051DD0;
    // 0x80051DC0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80051DC4:
    // 0x80051DC4: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051DC8: sb          $zero, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = 0;
    // 0x80051DCC: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80051DD0:
    // 0x80051DD0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80051DD4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80051DD8: nop

    // 0x80051DDC: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80051DE0: nop

    // 0x80051DE4: bc1f        L_80051ECC
    if (!c1cs) {
        // 0x80051DE8: lui         $at, 0x4008
        ctx->r1 = S32(0X4008 << 16);
            goto L_80051ECC;
    }
    // 0x80051DE8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80051DEC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80051DF0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80051DF4: nop

    // 0x80051DF8: c.lt.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d < ctx->f16.d;
    // 0x80051DFC: nop

    // 0x80051E00: bc1f        L_80051ECC
    if (!c1cs) {
        // 0x80051E04: nop
    
            goto L_80051ECC;
    }
    // 0x80051E04: nop

    // 0x80051E08: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80051E0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80051E10: bne         $t7, $at, L_80051E24
    if (ctx->r15 != ctx->r1) {
        // 0x80051E14: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80051E24;
    }
    // 0x80051E14: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80051E18: lb          $t6, 0x214($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X214);
    // 0x80051E1C: nop

    // 0x80051E20: beq         $t6, $zero, L_80051ECC
    if (ctx->r14 == 0) {
        // 0x80051E24: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80051ECC;
    }
L_80051E24:
    // 0x80051E24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051E28: lwc1        $f9, 0x6C10($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6C10);
    // 0x80051E2C: lwc1        $f8, 0x6C14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C14);
    // 0x80051E30: sub.d       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f16.d - ctx->f2.d;
    // 0x80051E34: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80051E38: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80051E3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80051E40: bne         $t1, $at, L_80051E60
    if (ctx->r9 != ctx->r1) {
        // 0x80051E44: cvt.s.d     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
            goto L_80051E60;
    }
    // 0x80051E44: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80051E48: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80051E4C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80051E50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051E54: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80051E58: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80051E5C: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80051E60:
    // 0x80051E60: lw          $t2, -0x2548($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2548);
    // 0x80051E64: nop

    // 0x80051E68: slti        $at, $t2, -0x19
    ctx->r1 = SIGNED(ctx->r10) < -0X19 ? 1 : 0;
    // 0x80051E6C: beq         $at, $zero, L_80051ECC
    if (ctx->r1 == 0) {
        // 0x80051E70: nop
    
            goto L_80051ECC;
    }
    // 0x80051E70: nop

    // 0x80051E74: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x80051E78: nop

    // 0x80051E7C: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    // 0x80051E80: bne         $t3, $zero, L_80051ECC
    if (ctx->r11 != 0) {
        // 0x80051E84: andi        $t8, $v0, 0x4000
        ctx->r24 = ctx->r2 & 0X4000;
            goto L_80051ECC;
    }
    // 0x80051E84: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x80051E88: beq         $t8, $zero, L_80051ECC
    if (ctx->r24 == 0) {
        // 0x80051E8C: nop
    
            goto L_80051ECC;
    }
    // 0x80051E8C: nop

    // 0x80051E90: lb          $t9, 0x1D7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D7);
    // 0x80051E94: nop

    // 0x80051E98: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80051E9C: bne         $at, $zero, L_80051EB8
    if (ctx->r1 != 0) {
        // 0x80051EA0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80051EB8;
    }
    // 0x80051EA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051EA4: lwc1        $f11, 0x6C18($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6C18);
    // 0x80051EA8: lwc1        $f10, 0x6C1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C1C);
    // 0x80051EAC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80051EB0: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80051EB4: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
L_80051EB8:
    // 0x80051EB8: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80051EBC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80051EC0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80051EC4: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051EC8: swc1        $f6, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f6.u32l;
L_80051ECC:
    // 0x80051ECC: lwc1        $f8, 0xB8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80051ED0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051ED4: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80051ED8: lwc1        $f5, 0x6C20($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6C20);
    // 0x80051EDC: lwc1        $f4, 0x6C24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C24);
    // 0x80051EE0: lwc1        $f8, 0xB4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80051EE4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80051EE8: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80051EEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051EF0: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80051EF4: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80051EF8: sub.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80051EFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80051F00: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x80051F04: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051F08: lwc1        $f4, 0x6C2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C2C);
    // 0x80051F0C: lwc1        $f5, 0x6C28($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6C28);
    // 0x80051F10: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80051F14: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80051F18: nop

    // 0x80051F1C: bc1f        L_80051F54
    if (!c1cs) {
        // 0x80051F20: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80051F54;
    }
    // 0x80051F20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051F24: lwc1        $f7, 0x6C30($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6C30);
    // 0x80051F28: lwc1        $f6, 0x6C34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C34);
    // 0x80051F2C: nop

    // 0x80051F30: c.lt.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d < ctx->f6.d;
    // 0x80051F34: nop

    // 0x80051F38: bc1f        L_80051F54
    if (!c1cs) {
        // 0x80051F3C: nop
    
            goto L_80051F54;
    }
    // 0x80051F3C: nop

    // 0x80051F40: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80051F44: nop

    // 0x80051F48: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80051F4C: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051F50: nop

L_80051F54:
    // 0x80051F54: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80051F58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80051F5C: bc1f        L_80051F94
    if (!c1cs) {
        // 0x80051F60: nop
    
            goto L_80051F94;
    }
    // 0x80051F60: nop

    // 0x80051F64: add.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80051F68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051F6C: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x80051F70: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051F74: nop

    // 0x80051F78: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80051F7C: nop

    // 0x80051F80: bc1f        L_80051FC4
    if (!c1cs) {
        // 0x80051F84: nop
    
            goto L_80051FC4;
    }
    // 0x80051F84: nop

    // 0x80051F88: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80051F8C: b           L_80051FC4
    // 0x80051F90: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
        goto L_80051FC4;
    // 0x80051F90: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_80051F94:
    // 0x80051F94: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80051F98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80051F9C: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x80051FA0: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80051FA4: nop

    // 0x80051FA8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80051FAC: nop

    // 0x80051FB0: bc1f        L_80051FC4
    if (!c1cs) {
        // 0x80051FB4: nop
    
            goto L_80051FC4;
    }
    // 0x80051FB4: nop

    // 0x80051FB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80051FBC: nop

    // 0x80051FC0: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
L_80051FC4:
    // 0x80051FC4: lwc1        $f14, -0x2514($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2514);
    // 0x80051FC8: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80051FCC: lwc1        $f8, 0x20($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X20);
    // 0x80051FD0: mul.s       $f18, $f14, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80051FD4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80051FD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051FDC: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80051FE0: swc1        $f4, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f4.u32l;
    // 0x80051FE4: lh          $t5, -0x24FA($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X24FA);
    // 0x80051FE8: nop

    // 0x80051FEC: beq         $t5, $zero, L_80051FFC
    if (ctx->r13 == 0) {
        // 0x80051FF0: nop
    
            goto L_80051FFC;
    }
    // 0x80051FF0: nop

    // 0x80051FF4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80051FF8: nop

L_80051FFC:
    // 0x80051FFC: lwc1        $f6, 0xB8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80052000: lwc1        $f9, 0x6C38($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6C38);
    // 0x80052004: lwc1        $f8, 0x6C3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C3C);
    // 0x80052008: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8005200C: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80052010: nop

    // 0x80052014: bc1f        L_80052114
    if (!c1cs) {
        // 0x80052018: nop
    
            goto L_80052114;
    }
    // 0x80052018: nop

    // 0x8005201C: lb          $t4, 0x1D7($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D7);
    // 0x80052020: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80052024: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x80052028: beq         $at, $zero, L_80052114
    if (ctx->r1 == 0) {
        // 0x8005202C: nop
    
            goto L_80052114;
    }
    // 0x8005202C: nop

    // 0x80052030: lw          $t7, -0x2540($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2540);
    // 0x80052034: nop

    // 0x80052038: bne         $t7, $zero, L_80052114
    if (ctx->r15 != 0) {
        // 0x8005203C: nop
    
            goto L_80052114;
    }
    // 0x8005203C: nop

    // 0x80052040: lwc1        $f12, 0x9C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80052044: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80052048: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005204C: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x80052050: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80052054: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80052058: bc1f        L_800520DC
    if (!c1cs) {
        // 0x8005205C: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_800520DC;
    }
    // 0x8005205C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80052060: lwc1        $f11, 0x6C40($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6C40);
    // 0x80052064: lwc1        $f10, 0x6C44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C44);
    // 0x80052068: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8005206C: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80052070: sub.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d - ctx->f10.d;
    // 0x80052074: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80052078: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8005207C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80052080: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80052084: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x80052088: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005208C: bc1f        L_800520A0
    if (!c1cs) {
        // 0x80052090: nop
    
            goto L_800520A0;
    }
    // 0x80052090: nop

    // 0x80052094: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80052098: nop

    // 0x8005209C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_800520A0:
    // 0x800520A0: lwc1        $f5, 0x6C48($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6C48);
    // 0x800520A4: lwc1        $f4, 0x6C4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C4C);
    // 0x800520A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800520AC: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800520B0: nop

    // 0x800520B4: bc1f        L_800520C4
    if (!c1cs) {
        // 0x800520B8: nop
    
            goto L_800520C4;
    }
    // 0x800520B8: nop

    // 0x800520BC: lwc1        $f2, 0x6C50($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6C50);
    // 0x800520C0: nop

L_800520C4:
    // 0x800520C4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800520C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800520CC: nop

    // 0x800520D0: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800520D4: b           L_800520E8
    // 0x800520D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
        goto L_800520E8;
    // 0x800520D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_800520DC:
    // 0x800520DC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800520E0: nop

    // 0x800520E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_800520E8:
    // 0x800520E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800520EC: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800520F0: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800520F4: nop

    // 0x800520F8: div.s       $f18, $f12, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800520FC: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80052100: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80052104: nop

    // 0x80052108: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005210C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80052110: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_80052114:
    // 0x80052114: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80052118: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005211C: lwc1        $f11, 0x6C58($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6C58);
    // 0x80052120: lwc1        $f10, 0x6C5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C5C);
    // 0x80052124: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80052128: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8005212C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80052130: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80052134: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80052138: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005213C: add.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f0.d + ctx->f18.d;
    // 0x80052140: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80052144: lb          $t6, 0x1E1($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E1);
    // 0x80052148: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8005214C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80052150: sb          $t6, 0x1E8($s0)
    MEM_B(0X1E8, ctx->r16) = ctx->r14;
    // 0x80052154: lb          $t3, 0x1E0($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E0);
    // 0x80052158: sub.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d - ctx->f8.d;
    // 0x8005215C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80052160: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80052164: lw          $t2, -0x252C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X252C);
    // 0x80052168: beq         $t3, $zero, L_800521B8
    if (ctx->r11 == 0) {
        // 0x8005216C: sw          $t2, 0x110($s0)
        MEM_W(0X110, ctx->r16) = ctx->r10;
            goto L_800521B8;
    }
    // 0x8005216C: sw          $t2, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->r10;
    // 0x80052170: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80052174: lw          $t8, -0x2524($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2524);
    // 0x80052178: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005217C: beq         $t8, $at, L_800521BC
    if (ctx->r24 == ctx->r1) {
        // 0x80052180: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800521BC;
    }
    // 0x80052180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80052184: lbu         $v0, 0x1DC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1DC);
    // 0x80052188: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8005218C: beq         $v0, $at, L_800521B8
    if (ctx->r2 == ctx->r1) {
        // 0x80052190: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_800521B8;
    }
    // 0x80052190: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80052194: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80052198: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8005219C: lhu         $t5, -0x2DC4($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2DC4);
    // 0x800521A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800521A4: sh          $t5, -0x2530($at)
    MEM_H(-0X2530, ctx->r1) = ctx->r13;
    // 0x800521A8: lb          $t4, 0x1E0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E0);
    // 0x800521AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800521B0: sh          $t4, -0x252E($at)
    MEM_H(-0X252E, ctx->r1) = ctx->r12;
    // 0x800521B4: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
L_800521B8:
    // 0x800521B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800521BC:
    // 0x800521BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800521C0: jr          $ra
    // 0x800521C4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800521C4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void start_reading_controller_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075D44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075D48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80075D4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80075D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075D54: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x80075D58: jal         0x800CD540
    // 0x80075D5C: nop

    osContStartReadData_recomp(rdram, ctx);
        goto after_0;
    // 0x80075D5C: nop

    after_0:
    // 0x80075D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075D68: jr          $ra
    // 0x80075D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80075D6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void guMtxF2L(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4DA0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800D4DA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D4DA8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D4DAC: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x800D4DB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D4DB4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D4DB8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800D4DBC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800D4DC0: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_800D4DC4:
    // 0x800D4DC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D4DC8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800D4DCC: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D4DD0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D4DD4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D4DD8: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800D4DDC: beq         $a0, $t3, L_800D4E44
    if (ctx->r4 == ctx->r11) {
        // 0x800D4DE0: nop
    
            goto L_800D4E44;
    }
    // 0x800D4DE0: nop

L_800D4DE4:
    // 0x800D4DE4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D4DE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D4DEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D4DF0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D4DF4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800D4DF8: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D4DFC: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800D4E00: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x800D4E04: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800D4E08: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800D4E0C: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x800D4E10: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x800D4E14: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D4E18: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800D4E1C: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x800D4E20: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x800D4E24: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x800D4E28: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800D4E2C: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x800D4E30: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D4E34: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D4E38: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800D4E3C: bne         $a0, $t3, L_800D4DE4
    if (ctx->r4 != ctx->r11) {
        // 0x800D4E40: nop
    
            goto L_800D4DE4;
    }
    // 0x800D4E40: nop

L_800D4E44:
    // 0x800D4E44: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D4E48: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800D4E4C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D4E50: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D4E54: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D4E58: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800D4E5C: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x800D4E60: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800D4E64: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800D4E68: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x800D4E6C: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x800D4E70: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D4E74: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800D4E78: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x800D4E7C: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x800D4E80: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x800D4E84: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800D4E88: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x800D4E8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D4E90: bne         $a2, $t4, L_800D4DC4
    if (ctx->r6 != ctx->r12) {
        // 0x800D4E94: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800D4DC4;
    }
    // 0x800D4E94: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800D4E98: jr          $ra
    // 0x800D4E9C: nop

    return;
    // 0x800D4E9C: nop

;}
RECOMP_FUNC void do_nothing_func_80011364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011364: jr          $ra
    // 0x80011368: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80011368: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void menu_button_uvs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080968: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8008096C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80080970: nop

    // 0x80080974: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80080978: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8008097C: nop

    // 0x80080980: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80080984: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80080988: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008098C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080990: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80080994: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80080998: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8008099C: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800809A0: sw          $t7, 0x2340($at)
    MEM_W(0X2340, ctx->r1) = ctx->r15;
    // 0x800809A4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800809A8: nop

    // 0x800809AC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800809B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800809B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800809B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800809BC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800809C0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800809C4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800809C8: jr          $ra
    // 0x800809CC: sw          $t9, 0x2344($at)
    MEM_W(0X2344, ctx->r1) = ctx->r25;
    return;
    // 0x800809CC: sw          $t9, 0x2344($at)
    MEM_W(0X2344, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void is_controller_missing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F708: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006F70C: lw          $t6, -0x270C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X270C);
    // 0x8006F710: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006F714: bne         $t6, $at, L_8006F724
    if (ctx->r14 != ctx->r1) {
        // 0x8006F718: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006F724;
    }
    // 0x8006F718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006F71C: jr          $ra
    // 0x8006F720: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8006F720: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006F724:
    // 0x8006F724: jr          $ra
    // 0x8006F728: nop

    return;
    // 0x8006F728: nop

;}
RECOMP_FUNC void ainode_register(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C4C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001C4C4: lw          $a1, -0x4B7C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4B7C);
    // 0x8001C4C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001C4CC: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_8001C4D0:
    // 0x8001C4D0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8001C4D4: nop

    // 0x8001C4D8: bne         $t6, $zero, L_8001C4EC
    if (ctx->r14 != 0) {
        // 0x8001C4DC: nop
    
            goto L_8001C4EC;
    }
    // 0x8001C4DC: nop

    // 0x8001C4E0: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8001C4E4: jr          $ra
    // 0x8001C4E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001C4E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001C4EC:
    // 0x8001C4EC: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8001C4F0: nop

    // 0x8001C4F4: bne         $t7, $zero, L_8001C508
    if (ctx->r15 != 0) {
        // 0x8001C4F8: nop
    
            goto L_8001C508;
    }
    // 0x8001C4F8: nop

    // 0x8001C4FC: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x8001C500: jr          $ra
    // 0x8001C504: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x8001C504: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8001C508:
    // 0x8001C508: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8001C50C: nop

    // 0x8001C510: bne         $t8, $zero, L_8001C524
    if (ctx->r24 != 0) {
        // 0x8001C514: nop
    
            goto L_8001C524;
    }
    // 0x8001C514: nop

    // 0x8001C518: sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
    // 0x8001C51C: jr          $ra
    // 0x8001C520: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x8001C520: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
L_8001C524:
    // 0x8001C524: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x8001C528: nop

    // 0x8001C52C: bne         $t9, $zero, L_8001C540
    if (ctx->r25 != 0) {
        // 0x8001C530: nop
    
            goto L_8001C540;
    }
    // 0x8001C530: nop

    // 0x8001C534: sw          $a0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r4;
    // 0x8001C538: jr          $ra
    // 0x8001C53C: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x8001C53C: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
L_8001C540:
    // 0x8001C540: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001C544: bne         $v1, $v0, L_8001C4D0
    if (ctx->r3 != ctx->r2) {
        // 0x8001C548: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_8001C4D0;
    }
    // 0x8001C548: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8001C54C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001C550: jr          $ra
    // 0x8001C554: nop

    return;
    // 0x8001C554: nop

;}
RECOMP_FUNC void alSynSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9BB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C9BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9BB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C9BBC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C9BC0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C9BC4: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800C9BC8: beql        $t7, $zero, L_800C9C40
    if (ctx->r15 == 0) {
        // 0x800C9BCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9C40;
    }
    goto skip_0;
    // 0x800C9BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9BD0: jal         0x800658A8
    // 0x800C9BD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9BD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C9BD8: beq         $v0, $zero, L_800C9C3C
    if (ctx->r2 == 0) {
        // 0x800C9BDC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800C9C3C;
    }
    // 0x800C9BDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800C9BE0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800C9BE4: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x800C9BE8: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x800C9BEC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800C9BF0: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x800C9BF4: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
    // 0x800C9BF8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800C9BFC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800C9C00: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x800C9C04: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x800C9C08: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C9C0C: jal         0x80065A04
    // 0x800C9C10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _timeToSamples(rdram, ctx);
        goto after_1;
    // 0x800C9C10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800C9C14: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9C18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9C1C: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x800C9C20: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800C9C24: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C9C28: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x800C9C2C: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x800C9C30: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9C34: jalr        $t9
    // 0x800C9C38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800C9C38: nop

    after_2:
L_800C9C3C:
    // 0x800C9C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9C40:
    // 0x800C9C40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C9C44: jr          $ra
    // 0x800C9C48: nop

    return;
    // 0x800C9C48: nop

;}
RECOMP_FUNC void func_80083098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834E8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800834EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800834F0: lw          $v0, 0x6EA0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6EA0);
    // 0x800834F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800834F8: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800834FC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80083500: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80083504: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80083508: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008350C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80083510: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80083514: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80083518: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8008351C: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80083520: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80083524: beq         $at, $zero, L_8008394C
    if (ctx->r1 == 0) {
        // 0x80083528: sw          $zero, 0x58($sp)
        MEM_W(0X58, ctx->r29) = 0;
            goto L_8008394C;
    }
    // 0x80083528: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x8008352C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80083530: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80083534: addiu       $v1, $v1, 0x6E98
    ctx->r3 = ADD32(ctx->r3, 0X6E98);
    // 0x80083538: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8008353C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80083540: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80083544: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80083548: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008354C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80083550: addiu       $t7, $t7, -0x244
    ctx->r15 = ADD32(ctx->r15, -0X244);
    // 0x80083554: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80083558: addu        $s3, $t6, $t7
    ctx->r19 = ADD32(ctx->r14, ctx->r15);
    // 0x8008355C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80083560: jal         0x800C484C
    // 0x80083564: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_0;
    // 0x80083564: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80083568: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008356C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083574: jal         0x800C492C
    // 0x80083578: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x80083578: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8008357C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80083580: addiu       $s2, $s2, -0x8C
    ctx->r18 = ADD32(ctx->r18, -0X8C);
    // 0x80083584: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80083588: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008358C: blez        $a0, L_80083690
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80083590: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80083690;
    }
    // 0x80083590: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80083594: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80083598: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8008359C: addiu       $s5, $s5, -0x88
    ctx->r21 = ADD32(ctx->r21, -0X88);
    // 0x800835A0: addiu       $s6, $s6, 0x693C
    ctx->r22 = ADD32(ctx->r22, 0X693C);
    // 0x800835A4: addiu       $s0, $s0, 0x6E18
    ctx->r16 = ADD32(ctx->r16, 0X6E18);
    // 0x800835A8: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
L_800835AC:
    // 0x800835AC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800835B0: nop

    // 0x800835B4: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800835B8: mflo        $t0
    ctx->r8 = lo;
    // 0x800835BC: addu        $v0, $s5, $t0
    ctx->r2 = ADD32(ctx->r21, ctx->r8);
    // 0x800835C0: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x800835C4: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800835C8: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x800835CC: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x800835D0: lbu         $a3, 0x3($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X3);
    // 0x800835D4: jal         0x800C48E4
    // 0x800835D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x800835D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
    // 0x800835DC: lh          $a1, 0x8($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X8);
    // 0x800835E0: lh          $a2, 0xA($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XA);
    // 0x800835E4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800835E8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800835EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800835F0: jal         0x800C49A0
    // 0x800835F4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_3;
    // 0x800835F4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x800835F8: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x800835FC: nop

    // 0x80083600: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80083604: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80083608: bne         $at, $zero, L_80083678
    if (ctx->r1 != 0) {
        // 0x8008360C: sw          $t3, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r11;
            goto L_80083678;
    }
    // 0x8008360C: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    // 0x80083610: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80083614: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x80083618: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8008361C: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80083620: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80083624: beq         $at, $zero, L_80083684
    if (ctx->r1 == 0) {
        // 0x80083628: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80083684;
    }
    // 0x80083628: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8008362C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80083630: addiu       $t8, $t8, 0x6E18
    ctx->r24 = ADD32(ctx->r24, 0X6E18);
    // 0x80083634: sll         $t7, $t0, 4
    ctx->r15 = S32(ctx->r8 << 4);
    // 0x80083638: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x8008363C: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x80083640: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
L_80083644:
    // 0x80083644: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x80083648: lh          $t2, 0x18($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X18);
    // 0x8008364C: lh          $t3, 0x1A($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X1A);
    // 0x80083650: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x80083654: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80083658: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8008365C: sw          $t1, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r9;
    // 0x80083660: sh          $t2, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r10;
    // 0x80083664: sh          $t3, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r11;
    // 0x80083668: bne         $at, $zero, L_80083644
    if (ctx->r1 != 0) {
        // 0x8008366C: sw          $t4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r12;
            goto L_80083644;
    }
    // 0x8008366C: sw          $t4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r12;
    // 0x80083670: b           L_80083688
    // 0x80083674: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
        goto L_80083688;
    // 0x80083674: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
L_80083678:
    // 0x80083678: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8008367C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80083680: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_80083684:
    // 0x80083684: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
L_80083688:
    // 0x80083688: bne         $at, $zero, L_800835AC
    if (ctx->r1 != 0) {
        // 0x8008368C: nop
    
            goto L_800835AC;
    }
    // 0x8008368C: nop

L_80083690:
    // 0x80083690: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083694: lwc1        $f16, 0x6E98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6E98);
    // 0x80083698: lwc1        $f18, 0x4($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8008369C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800836A0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800836A4: addiu       $s6, $s6, 0x693C
    ctx->r22 = ADD32(ctx->r22, 0X693C);
    // 0x800836A8: bc1f        L_800838D4
    if (!c1cs) {
        // 0x800836AC: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_800838D4;
    }
    // 0x800836AC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800836B0: lwc1        $f8, 0x8($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800836B4: nop

    // 0x800836B8: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x800836BC: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800836C0: nop

    // 0x800836C4: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800836C8: nop

    // 0x800836CC: bc1f        L_8008377C
    if (!c1cs) {
        // 0x800836D0: nop
    
            goto L_8008377C;
    }
    // 0x800836D0: nop

    // 0x800836D4: lwc1        $f12, 0x14($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800836D8: lwc1        $f4, 0x1C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x800836DC: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800836E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800836E4: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800836E8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800836EC: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800836F0: nop

    // 0x800836F4: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800836F8: add.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x800836FC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80083700: nop

    // 0x80083704: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80083708: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008370C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083710: nop

    // 0x80083714: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80083718: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8008371C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80083720: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x80083724: lwc1        $f8, 0x20($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X20);
    // 0x80083728: lwc1        $f14, 0x18($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X18);
    // 0x8008372C: nop

    // 0x80083730: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80083734: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80083738: nop

    // 0x8008373C: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80083740: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80083744: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80083748: nop

    // 0x8008374C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80083750: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083754: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083758: nop

    // 0x8008375C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80083760: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80083764: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80083768: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x8008376C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80083770: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x80083774: b           L_800838D4
    // 0x80083778: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
        goto L_800838D4;
    // 0x80083778: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
L_8008377C:
    // 0x8008377C: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80083780: nop

    // 0x80083784: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80083788: nop

    // 0x8008378C: bc1f        L_800837F8
    if (!c1cs) {
        // 0x80083790: nop
    
            goto L_800837F8;
    }
    // 0x80083790: nop

    // 0x80083794: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80083798: lwc1        $f4, 0x1C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x8008379C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800837A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800837A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800837A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800837AC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800837B0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800837B4: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800837B8: nop

    // 0x800837BC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800837C0: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x800837C4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800837C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800837CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800837D0: lwc1        $f8, 0x20($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X20);
    // 0x800837D4: nop

    // 0x800837D8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800837DC: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800837E0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800837E4: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x800837E8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800837EC: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x800837F0: b           L_800838D4
    // 0x800837F4: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
        goto L_800838D4;
    // 0x800837F4: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_800837F8:
    // 0x800837F8: lwc1        $f4, 0x10($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800837FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80083800: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80083804: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80083808: addiu       $v0, $v0, 0x6EA0
    ctx->r2 = ADD32(ctx->r2, 0X6EA0);
    // 0x8008380C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x80083810: nop

    // 0x80083814: bc1f        L_800838C4
    if (!c1cs) {
        // 0x80083818: nop
    
            goto L_800838C4;
    }
    // 0x80083818: nop

    // 0x8008381C: lwc1        $f12, 0x1C($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X1C);
    // 0x80083820: lwc1        $f8, 0x24($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80083824: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80083828: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008382C: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80083830: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80083834: sub.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80083838: nop

    // 0x8008383C: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80083840: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80083844: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80083848: nop

    // 0x8008384C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80083850: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083854: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083858: nop

    // 0x8008385C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80083860: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80083864: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80083868: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8008386C: lwc1        $f4, 0x28($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X28);
    // 0x80083870: lwc1        $f14, 0x20($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X20);
    // 0x80083874: nop

    // 0x80083878: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8008387C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80083880: nop

    // 0x80083884: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80083888: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8008388C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80083890: nop

    // 0x80083894: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80083898: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008389C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800838A0: nop

    // 0x800838A4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800838A8: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800838AC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800838B0: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x800838B4: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800838B8: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x800838BC: b           L_800838D4
    // 0x800838C0: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
        goto L_800838D4;
    // 0x800838C0: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_800838C4:
    // 0x800838C4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800838C8: nop

    // 0x800838CC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800838D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800838D4:
    // 0x800838D4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800838D8: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x800838DC: beq         $t7, $zero, L_8008394C
    if (ctx->r15 == 0) {
        // 0x800838E0: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_8008394C;
    }
    // 0x800838E0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800838E4: beq         $at, $zero, L_80083920
    if (ctx->r1 == 0) {
        // 0x800838E8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80083920;
    }
    // 0x800838E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800838EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800838F0: addiu       $t8, $t8, 0x6E18
    ctx->r24 = ADD32(ctx->r24, 0X6E18);
    // 0x800838F4: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x800838F8: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800838FC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80083900: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80083904: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80083908: addiu       $t4, $a0, 0x1
    ctx->r12 = ADD32(ctx->r4, 0X1);
    // 0x8008390C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80083910: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x80083914: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80083918: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x8008391C: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
L_80083920:
    // 0x80083920: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80083924: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80083928: jal         0x800C48E4
    // 0x8008392C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x8008392C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_4:
    // 0x80083930: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80083934: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x80083938: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8008393C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80083940: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80083944: jal         0x800C49A0
    // 0x80083948: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80083948: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_5:
L_8008394C:
    // 0x8008394C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80083950: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80083954: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80083958: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008395C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80083960: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80083964: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80083968: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008396C: jr          $ra
    // 0x80083970: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80083970: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void alCSeqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C855C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C8560: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C8564: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C8568: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C856C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C8570: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C8574: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C8578: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C857C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C8580: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800C8584: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800C8588: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800C858C: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800C8590: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800C8594: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800C8598: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C859C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C85A0: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x800C85A4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800C85A8: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
L_800C85AC:
    // 0x800C85AC: sb          $zero, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = 0;
    // 0x800C85B0: sw          $zero, 0x58($t4)
    MEM_W(0X58, ctx->r12) = 0;
    // 0x800C85B4: sb          $zero, 0x98($s1)
    MEM_B(0X98, ctx->r17) = 0;
    // 0x800C85B8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800C85BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C85C0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800C85C4: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800C85C8: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x800C85CC: beq         $v0, $zero, L_800C85F8
    if (ctx->r2 == 0) {
        // 0x800C85D0: addu        $t6, $s4, $v0
        ctx->r14 = ADD32(ctx->r20, ctx->r2);
            goto L_800C85F8;
    }
    // 0x800C85D0: addu        $t6, $s4, $v0
    ctx->r14 = ADD32(ctx->r20, ctx->r2);
    // 0x800C85D4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800C85D8: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800C85DC: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x800C85E0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800C85E4: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800C85E8: jal         0x800C8204
    // 0x800C85EC: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    static_3_800C8204(rdram, ctx);
        goto after_0;
    // 0x800C85EC: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    after_0:
    // 0x800C85F0: b           L_800C85FC
    // 0x800C85F4: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
        goto L_800C85FC;
    // 0x800C85F4: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
L_800C85F8:
    // 0x800C85F8: sw          $zero, 0x18($t4)
    MEM_W(0X18, ctx->r12) = 0;
L_800C85FC:
    // 0x800C85FC: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800C8600: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C8604: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C8608: bne         $t5, $s3, L_800C85AC
    if (ctx->r13 != ctx->r19) {
        // 0x800C860C: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_800C85AC;
    }
    // 0x800C860C: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x800C8610: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800C8614: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C8618: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800C861C: lw          $t7, 0x40($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X40);
    // 0x800C8620: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C8624: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C8628: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800C862C: bgez        $t7, L_800C8640
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C8630: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800C8640;
    }
    // 0x800C8630: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C8634: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C8638: nop

    // 0x800C863C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800C8640:
    // 0x800C8640: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800C8644: div.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x800C8648: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x800C864C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800C8650: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C8654: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C8658: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C865C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C8660: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C8668: jr          $ra
    // 0x800C866C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C866C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mempool_new_sub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070DB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80070DBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070DC0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80070DC4: jal         0x8006F750
    // 0x80070DC8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80070DC8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80070DCC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80070DD0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80070DD4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80070DD8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80070DDC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80070DE0: addu        $a3, $t6, $t8
    ctx->r7 = ADD32(ctx->r14, ctx->r24);
    // 0x80070DE4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80070DE8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80070DEC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80070DF0: jal         0x80070EDC
    // 0x80070DF4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80070DF4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x80070DF8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80070DFC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80070E00: jal         0x80070E24
    // 0x80070E04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mempool_init(rdram, ctx);
        goto after_2;
    // 0x80070E04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80070E08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80070E0C: jal         0x8006F77C
    // 0x80070E10: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80070E10: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80070E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070E18: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80070E1C: jr          $ra
    // 0x80070E20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80070E20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void set_shading_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D4E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D4EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D4F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001D4F4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8001D4F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D4FC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D500: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D504: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D508: sh          $a3, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r7;
    // 0x8001D50C: swc1        $f12, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f12.u32l;
    // 0x8001D510: swc1        $f14, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f14.u32l;
    // 0x8001D514: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8001D518: lh          $t8, 0x42($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X42);
    // 0x8001D51C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001D520: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x8001D524: lh          $t9, 0x46($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X46);
    // 0x8001D528: lui         $at, 0xC680
    ctx->r1 = S32(0XC680 << 16);
    // 0x8001D52C: sh          $t9, 0x26($a0)
    MEM_H(0X26, ctx->r4) = ctx->r25;
    // 0x8001D530: lh          $t0, 0x46($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X46);
    // 0x8001D534: lh          $t1, 0x42($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X42);
    // 0x8001D538: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D53C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001D540: sh          $a3, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r7;
    // 0x8001D544: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001D548: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001D54C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8001D550: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8001D554: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8001D558: sh          $t0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r8;
    // 0x8001D55C: sh          $t1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r9;
    // 0x8001D560: jal         0x80070560
    // 0x8001D564: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x8001D564: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8001D568: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001D56C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8001D570: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001D574: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8001D578: nop

    // 0x8001D57C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8001D580: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D584: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D588: nop

    // 0x8001D58C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001D590: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8001D594: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8001D598: sh          $t3, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = ctx->r11;
    // 0x8001D59C: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001D5A0: nop

    // 0x8001D5A4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8001D5A8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8001D5AC: nop

    // 0x8001D5B0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8001D5B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D5B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D5BC: nop

    // 0x8001D5C0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001D5C4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8001D5C8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8001D5CC: sh          $t5, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r13;
    // 0x8001D5D0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001D5D4: sb          $zero, 0x18($a2)
    MEM_B(0X18, ctx->r6) = 0;
    // 0x8001D5D8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001D5DC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001D5E0: sb          $zero, 0x19($a2)
    MEM_B(0X19, ctx->r6) = 0;
    // 0x8001D5E4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001D5E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D5EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D5F0: sb          $zero, 0x1A($a2)
    MEM_B(0X1A, ctx->r6) = 0;
    // 0x8001D5F4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001D5F8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x8001D5FC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001D600: sh          $t7, 0x20($a2)
    MEM_H(0X20, ctx->r6) = ctx->r15;
    // 0x8001D604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D608: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001D60C: jr          $ra
    // 0x8001D610: nop

    return;
    // 0x8001D610: nop

;}
RECOMP_FUNC void update_perspective_and_envmap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030FE8: jal         0x80069F60
    // 0x80030FEC: nop

    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80030FEC: nop

    after_0:
    // 0x80030FF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80030FF4: jal         0x80031058
    // 0x80030FF8: sw          $v0, -0x49D0($at)
    MEM_W(-0X49D0, ctx->r1) = ctx->r2;
    compute_scene_camera_transform_matrix(rdram, ctx);
        goto after_1;
    // 0x80030FF8: sw          $v0, -0x49D0($at)
    MEM_W(-0X49D0, ctx->r1) = ctx->r2;
    after_1:
    // 0x80030FFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80031000: addiu       $v0, $v0, -0x2618
    ctx->r2 = ADD32(ctx->r2, -0X2618);
    // 0x80031004: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80031008: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8003100C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80031010: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80031014: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80031018: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8003101C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80031020: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80031024: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80031028: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003102C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80031030: nop

    // 0x80031034: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80031038: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003103C: div.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80031040: jal         0x8001D614
    // 0x80031044: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    update_envmap_position(rdram, ctx);
        goto after_2;
    // 0x80031044: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    after_2:
    // 0x80031048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003104C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031050: jr          $ra
    // 0x80031054: nop

    return;
    // 0x80031054: nop

;}
RECOMP_FUNC void rain_opacity_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADA0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ADA10: jr          $ra
    // 0x800ADA14: sw          $a0, 0x31FC($at)
    MEM_W(0X31FC, ctx->r1) = ctx->r4;
    return;
    // 0x800ADA14: sw          $a0, 0x31FC($at)
    MEM_W(0X31FC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_loop_ttdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C324: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003C328: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003C32C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003C330: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003C334: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003C338: lw          $s0, 0x64($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X64);
    // 0x8003C33C: jal         0x8006ECD0
    // 0x8003C340: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003C340: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_0:
    // 0x8003C344: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8003C348: lbu         $t6, 0xF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XF);
    // 0x8003C34C: nop

    // 0x8003C350: bne         $t6, $zero, L_8003C370
    if (ctx->r14 != 0) {
        // 0x8003C354: nop
    
            goto L_8003C370;
    }
    // 0x8003C354: nop

    // 0x8003C358: lbu         $t7, 0x16($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X16);
    // 0x8003C35C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8003C360: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8003C364: lb          $t8, -0x2FFC($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X2FFC);
    // 0x8003C368: b           L_8003C388
    // 0x8003C36C: sb          $t8, 0x3A($s1)
    MEM_B(0X3A, ctx->r17) = ctx->r24;
        goto L_8003C388;
    // 0x8003C36C: sb          $t8, 0x3A($s1)
    MEM_B(0X3A, ctx->r17) = ctx->r24;
L_8003C370:
    // 0x8003C370: lbu         $t9, 0x16($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X16);
    // 0x8003C374: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8003C378: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8003C37C: lb          $t0, -0x2FF4($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2FF4);
    // 0x8003C380: nop

    // 0x8003C384: sb          $t0, 0x3A($s1)
    MEM_B(0X3A, ctx->r17) = ctx->r8;
L_8003C388:
    // 0x8003C388: lw          $v1, 0x4C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C38C: lbu         $t2, 0x12($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12);
    // 0x8003C390: lbu         $t1, 0x13($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X13);
    // 0x8003C394: nop

    // 0x8003C398: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003C39C: beq         $at, $zero, L_8003C4AC
    if (ctx->r1 == 0) {
        // 0x8003C3A0: nop
    
            goto L_8003C4AC;
    }
    // 0x8003C3A0: nop

    // 0x8003C3A4: lbu         $t3, 0x16($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X16);
    // 0x8003C3A8: nop

    // 0x8003C3AC: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8003C3B0: bne         $at, $zero, L_8003C3D4
    if (ctx->r1 != 0) {
        // 0x8003C3B4: nop
    
            goto L_8003C3D4;
    }
    // 0x8003C3B4: nop

    // 0x8003C3B8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8003C3BC: nop

    // 0x8003C3C0: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8003C3C4: nop

    // 0x8003C3C8: slti        $at, $t5, 0x2F
    ctx->r1 = SIGNED(ctx->r13) < 0X2F ? 1 : 0;
    // 0x8003C3CC: beq         $at, $zero, L_8003C4AC
    if (ctx->r1 == 0) {
        // 0x8003C3D0: nop
    
            goto L_8003C4AC;
    }
    // 0x8003C3D0: nop

L_8003C3D4:
    // 0x8003C3D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003C3D8: nop

    // 0x8003C3DC: beq         $v0, $zero, L_8003C4AC
    if (ctx->r2 == 0) {
        // 0x8003C3E0: nop
    
            goto L_8003C4AC;
    }
    // 0x8003C3E0: nop

    // 0x8003C3E4: lw          $t6, 0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X40);
    // 0x8003C3E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003C3EC: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x8003C3F0: nop

    // 0x8003C3F4: bne         $t7, $at, L_8003C4AC
    if (ctx->r15 != ctx->r1) {
        // 0x8003C3F8: nop
    
            goto L_8003C4AC;
    }
    // 0x8003C3F8: nop

    // 0x8003C3FC: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003C400: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8003C404: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x8003C408: nop

    // 0x8003C40C: beq         $a0, $t8, L_8003C498
    if (ctx->r4 == ctx->r24) {
        // 0x8003C410: nop
    
            goto L_8003C498;
    }
    // 0x8003C410: nop

    // 0x8003C414: lw          $t9, 0x5C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X5C);
    // 0x8003C418: nop

    // 0x8003C41C: lw          $t0, 0x100($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X100);
    // 0x8003C420: nop

    // 0x8003C424: bne         $v0, $t0, L_8003C498
    if (ctx->r2 != ctx->r8) {
        // 0x8003C428: nop
    
            goto L_8003C498;
    }
    // 0x8003C428: nop

    // 0x8003C42C: lb          $t1, 0x13($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X13);
    // 0x8003C430: nop

    // 0x8003C434: beq         $a0, $t1, L_8003C494
    if (ctx->r4 == ctx->r9) {
        // 0x8003C438: addiu       $t5, $zero, 0x12C
        ctx->r13 = ADD32(0, 0X12C);
            goto L_8003C494;
    }
    // 0x8003C438: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x8003C43C: jal         0x800C3958
    // 0x8003C440: nop

    textbox_visible(rdram, ctx);
        goto after_1;
    // 0x8003C440: nop

    after_1:
    // 0x8003C444: bne         $v0, $zero, L_8003C494
    if (ctx->r2 != 0) {
        // 0x8003C448: addiu       $t5, $zero, 0x12C
        ctx->r13 = ADD32(0, 0X12C);
            goto L_8003C494;
    }
    // 0x8003C448: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x8003C44C: lh          $t2, 0xC($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XC);
    // 0x8003C450: nop

    // 0x8003C454: bne         $t2, $zero, L_8003C494
    if (ctx->r10 != 0) {
        // 0x8003C458: addiu       $t5, $zero, 0x12C
        ctx->r13 = ADD32(0, 0X12C);
            goto L_8003C494;
    }
    // 0x8003C458: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
    // 0x8003C45C: jal         0x80000C98
    // 0x8003C460: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    music_fade(rdram, ctx);
        goto after_2;
    // 0x8003C460: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    after_2:
    // 0x8003C464: addiu       $t3, $zero, 0x8C
    ctx->r11 = ADD32(0, 0X8C);
    // 0x8003C468: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x8003C46C: jal         0x80000C38
    // 0x8003C470: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_3;
    // 0x8003C470: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
    // 0x8003C474: jal         0x80001BC0
    // 0x8003C478: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    music_jingle_play(rdram, ctx);
        goto after_4;
    // 0x8003C478: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_4:
    // 0x8003C47C: lb          $a0, 0x13($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X13);
    // 0x8003C480: nop

    // 0x8003C484: andi        $t4, $a0, 0xFF
    ctx->r12 = ctx->r4 & 0XFF;
    // 0x8003C488: jal         0x800C3744
    // 0x8003C48C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    set_current_text(rdram, ctx);
        goto after_5;
    // 0x8003C48C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_5:
    // 0x8003C490: addiu       $t5, $zero, 0x12C
    ctx->r13 = ADD32(0, 0X12C);
L_8003C494:
    // 0x8003C494: sh          $t5, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r13;
L_8003C498:
    // 0x8003C498: jal         0x800C3958
    // 0x8003C49C: nop

    textbox_visible(rdram, ctx);
        goto after_6;
    // 0x8003C49C: nop

    after_6:
    // 0x8003C4A0: beq         $v0, $zero, L_8003C4AC
    if (ctx->r2 == 0) {
        // 0x8003C4A4: addiu       $t6, $zero, 0x12C
        ctx->r14 = ADD32(0, 0X12C);
            goto L_8003C4AC;
    }
    // 0x8003C4A4: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x8003C4A8: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
L_8003C4AC:
    // 0x8003C4AC: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8003C4B0: nop

    // 0x8003C4B4: beq         $t7, $zero, L_8003C4FC
    if (ctx->r15 == 0) {
        // 0x8003C4B8: nop
    
            goto L_8003C4FC;
    }
    // 0x8003C4B8: nop

    // 0x8003C4BC: jal         0x80001C08
    // 0x8003C4C0: nop

    music_jingle_playing(rdram, ctx);
        goto after_7;
    // 0x8003C4C0: nop

    after_7:
    // 0x8003C4C4: bne         $v0, $zero, L_8003C4FC
    if (ctx->r2 != 0) {
        // 0x8003C4C8: nop
    
            goto L_8003C4FC;
    }
    // 0x8003C4C8: nop

    // 0x8003C4CC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8003C4D0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8003C4D4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8003C4D8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003C4DC: beq         $at, $zero, L_8003C4EC
    if (ctx->r1 == 0) {
        // 0x8003C4E0: subu        $t8, $v0, $v1
        ctx->r24 = SUB32(ctx->r2, ctx->r3);
            goto L_8003C4EC;
    }
    // 0x8003C4E0: subu        $t8, $v0, $v1
    ctx->r24 = SUB32(ctx->r2, ctx->r3);
    // 0x8003C4E4: b           L_8003C4FC
    // 0x8003C4E8: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
        goto L_8003C4FC;
    // 0x8003C4E8: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
L_8003C4EC:
    // 0x8003C4EC: jal         0x80000C98
    // 0x8003C4F0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    music_fade(rdram, ctx);
        goto after_8;
    // 0x8003C4F0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    after_8:
    // 0x8003C4F4: jal         0x80000C38
    // 0x8003C4F8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_9;
    // 0x8003C4F8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
L_8003C4FC:
    // 0x8003C4FC: lh          $v0, 0xC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XC);
    // 0x8003C500: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8003C504: blez        $v0, L_8003C514
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003C508: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_8003C514;
    }
    // 0x8003C508: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x8003C50C: b           L_8003C518
    // 0x8003C510: sh          $t9, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r25;
        goto L_8003C518;
    // 0x8003C510: sh          $t9, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r25;
L_8003C514:
    // 0x8003C514: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
L_8003C518:
    // 0x8003C518: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8003C51C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003C520: lbu         $t1, 0x16($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X16);
    // 0x8003C524: nop

    // 0x8003C528: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8003C52C: bne         $at, $zero, L_8003C588
    if (ctx->r1 != 0) {
        // 0x8003C530: nop
    
            goto L_8003C588;
    }
    // 0x8003C530: nop

    // 0x8003C534: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C538: lbu         $t4, 0x12($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X12);
    // 0x8003C53C: lbu         $t3, 0x13($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X13);
    // 0x8003C540: nop

    // 0x8003C544: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003C548: beq         $at, $zero, L_8003C588
    if (ctx->r1 == 0) {
        // 0x8003C54C: nop
    
            goto L_8003C588;
    }
    // 0x8003C54C: nop

    // 0x8003C550: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8003C554: nop

    // 0x8003C558: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8003C55C: nop

    // 0x8003C560: slti        $at, $t6, 0x2F
    ctx->r1 = SIGNED(ctx->r14) < 0X2F ? 1 : 0;
    // 0x8003C564: bne         $at, $zero, L_8003C588
    if (ctx->r1 != 0) {
        // 0x8003C568: nop
    
            goto L_8003C588;
    }
    // 0x8003C568: nop

    // 0x8003C56C: lh          $v1, 0x0($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X0);
    // 0x8003C570: lw          $t7, 0x7C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X7C);
    // 0x8003C574: nop

    // 0x8003C578: subu        $v0, $v1, $t7
    ctx->r2 = SUB32(ctx->r3, ctx->r15);
    // 0x8003C57C: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8003C580: b           L_8003C5A0
    // 0x8003C584: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
        goto L_8003C5A0;
    // 0x8003C584: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
L_8003C588:
    // 0x8003C588: lh          $v1, 0x0($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X0);
    // 0x8003C58C: lw          $t1, 0x78($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X78);
    // 0x8003C590: nop

    // 0x8003C594: subu        $v0, $v1, $t1
    ctx->r2 = SUB32(ctx->r3, ctx->r9);
    // 0x8003C598: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x8003C59C: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
L_8003C5A0:
    // 0x8003C5A0: sra         $t4, $v0, 3
    ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8003C5A4: sll         $t0, $t4, 16
    ctx->r8 = S32(ctx->r12 << 16);
    // 0x8003C5A8: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8003C5AC: slti        $at, $v0, 0x201
    ctx->r1 = SIGNED(ctx->r2) < 0X201 ? 1 : 0;
    // 0x8003C5B0: bne         $at, $zero, L_8003C5C0
    if (ctx->r1 != 0) {
        // 0x8003C5B4: slti        $at, $v0, -0x200
        ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
            goto L_8003C5C0;
    }
    // 0x8003C5B4: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
    // 0x8003C5B8: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8003C5BC: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
L_8003C5C0:
    // 0x8003C5C0: beq         $at, $zero, L_8003C5D0
    if (ctx->r1 == 0) {
        // 0x8003C5C4: subu        $t6, $v1, $v0
        ctx->r14 = SUB32(ctx->r3, ctx->r2);
            goto L_8003C5D0;
    }
    // 0x8003C5C4: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x8003C5C8: addiu       $v0, $zero, -0x200
    ctx->r2 = ADD32(0, -0X200);
    // 0x8003C5CC: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
L_8003C5D0:
    // 0x8003C5D0: bne         $v0, $zero, L_8003C5DC
    if (ctx->r2 != 0) {
        // 0x8003C5D4: sh          $t6, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r14;
            goto L_8003C5DC;
    }
    // 0x8003C5D4: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x8003C5D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8003C5DC:
    // 0x8003C5DC: beq         $a0, $zero, L_8003C618
    if (ctx->r4 == 0) {
        // 0x8003C5E0: nop
    
            goto L_8003C618;
    }
    // 0x8003C5E0: nop

    // 0x8003C5E4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8003C5E8: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    // 0x8003C5EC: bne         $t7, $zero, L_8003C634
    if (ctx->r15 != 0) {
        // 0x8003C5F0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8003C634;
    }
    // 0x8003C5F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003C5F4: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8003C5F8: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8003C5FC: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8003C600: addiu       $t9, $s0, 0x4
    ctx->r25 = ADD32(ctx->r16, 0X4);
    // 0x8003C604: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003C608: jal         0x80009558
    // 0x8003C60C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_10;
    // 0x8003C60C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_10:
    // 0x8003C610: b           L_8003C638
    // 0x8003C614: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
        goto L_8003C638;
    // 0x8003C614: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
L_8003C618:
    // 0x8003C618: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8003C61C: nop

    // 0x8003C620: beq         $v0, $zero, L_8003C634
    if (ctx->r2 == 0) {
        // 0x8003C624: nop
    
            goto L_8003C634;
    }
    // 0x8003C624: nop

    // 0x8003C628: jal         0x800096F8
    // 0x8003C62C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    audspat_point_stop(rdram, ctx);
        goto after_11;
    // 0x8003C62C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8003C630: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8003C634:
    // 0x8003C634: lw          $t2, 0x4C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4C);
L_8003C638:
    // 0x8003C638: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8003C63C: sb          $t1, 0x13($t2)
    MEM_B(0X13, ctx->r10) = ctx->r9;
    // 0x8003C640: lw          $t3, 0x4C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C644: nop

    // 0x8003C648: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8003C64C: lw          $v1, 0x4C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4C);
    // 0x8003C650: nop

    // 0x8003C654: lh          $t4, 0x14($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X14);
    // 0x8003C658: nop

    // 0x8003C65C: andi        $t0, $t4, 0xFFF7
    ctx->r8 = ctx->r12 & 0XFFF7;
    // 0x8003C660: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    // 0x8003C664: lw          $t5, 0x5C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X5C);
    // 0x8003C668: nop

    // 0x8003C66C: sw          $zero, 0x100($t5)
    MEM_W(0X100, ctx->r13) = 0;
    // 0x8003C670: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003C674: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003C678: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C67C: jr          $ra
    // 0x8003C680: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8003C680: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void cam_move_dir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069DB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80069DB4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80069DB8: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80069DBC: addiu       $s2, $s2, 0x1264
    ctx->r18 = ADD32(ctx->r18, 0X1264);
    // 0x80069DC0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80069DC4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80069DC8: addiu       $s3, $zero, 0x44
    ctx->r19 = ADD32(0, 0X44);
    // 0x80069DCC: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069DD0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80069DD4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80069DD8: addiu       $s1, $s1, 0x1040
    ctx->r17 = ADD32(ctx->r17, 0X1040);
    // 0x80069DDC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80069DE0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80069DE4: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80069DE8: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80069DEC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80069DF0: mflo        $t7
    ctx->r15 = lo;
    // 0x80069DF4: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80069DF8: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    // 0x80069DFC: jal         0x80070A38
    // 0x80069E00: nop

    coss_f(rdram, ctx);
        goto after_0;
    // 0x80069E00: nop

    after_0:
    // 0x80069E04: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80069E08: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069E0C: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069E10: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80069E14: mflo        $t0
    ctx->r8 = lo;
    // 0x80069E18: addu        $s0, $s1, $t0
    ctx->r16 = ADD32(ctx->r17, ctx->r8);
    // 0x80069E1C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069E20: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80069E24: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80069E28: jal         0x80070A04
    // 0x80069E2C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80069E2C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x80069E30: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80069E34: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069E38: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069E3C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80069E40: mflo        $t2
    ctx->r10 = lo;
    // 0x80069E44: addu        $s0, $s1, $t2
    ctx->r16 = ADD32(ctx->r17, ctx->r10);
    // 0x80069E48: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80069E4C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80069E50: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80069E54: jal         0x80070A04
    // 0x80069E58: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80069E58: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80069E5C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80069E60: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80069E64: multu       $t3, $s3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069E68: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80069E6C: mflo        $t4
    ctx->r12 = lo;
    // 0x80069E70: addu        $s0, $s1, $t4
    ctx->r16 = ADD32(ctx->r17, ctx->r12);
    // 0x80069E74: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069E78: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80069E7C: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80069E80: jal         0x80070A38
    // 0x80069E84: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    coss_f(rdram, ctx);
        goto after_3;
    // 0x80069E84: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x80069E88: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80069E8C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80069E90: multu       $t5, $s3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069E94: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80069E98: mflo        $t6
    ctx->r14 = lo;
    // 0x80069E9C: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
    // 0x80069EA0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80069EA4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069EA8: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069EAC: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80069EB0: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x80069EB4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80069EB8: jal         0x80029F58
    // 0x80069EBC: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_4;
    // 0x80069EBC: nop

    after_4:
    // 0x80069EC0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80069EC4: nop

    // 0x80069EC8: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069ECC: mflo        $t8
    ctx->r24 = lo;
    // 0x80069ED0: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80069ED4: sh          $v0, 0x34($t9)
    MEM_H(0X34, ctx->r25) = ctx->r2;
    // 0x80069ED8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80069EDC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80069EE0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80069EE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80069EE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80069EEC: jr          $ra
    // 0x80069EF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80069EF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void racer_AI_pathing_inputs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800441B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800441B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800441B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800441BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800441C0: jal         0x8006BFD8
    // 0x800441C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    level_type(rdram, ctx);
        goto after_0;
    // 0x800441C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800441C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800441CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800441D0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800441D4: beq         $v0, $at, L_800441F8
    if (ctx->r2 == ctx->r1) {
        // 0x800441D8: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800441F8;
    }
    // 0x800441D8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800441DC: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800441E0: beq         $v0, $at, L_800441F8
    if (ctx->r2 == ctx->r1) {
        // 0x800441E4: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_800441F8;
    }
    // 0x800441E4: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800441E8: beq         $v0, $at, L_8004421C
    if (ctx->r2 == ctx->r1) {
        // 0x800441EC: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_8004421C;
    }
    // 0x800441EC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800441F0: b           L_8004423C
    // 0x800441F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
        goto L_8004423C;
    // 0x800441F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_800441F8:
    // 0x800441F8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800441FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80044200: jal         0x800444BC
    // 0x80044204: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    racer_ai_challenge(rdram, ctx);
        goto after_1;
    // 0x80044204: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80044208: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004420C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80044210: b           L_80044258
    // 0x80044214: lb          $t6, 0x214($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X214);
        goto L_80044258;
    // 0x80044214: lb          $t6, 0x214($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X214);
    // 0x80044218: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_8004421C:
    // 0x8004421C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80044220: jal         0x800452E0
    // 0x80044224: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    racer_ai_eggs(rdram, ctx);
        goto after_2;
    // 0x80044224: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80044228: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004422C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80044230: b           L_80044258
    // 0x80044234: lb          $t6, 0x214($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X214);
        goto L_80044258;
    // 0x80044234: lb          $t6, 0x214($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X214);
    // 0x80044238: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_8004423C:
    // 0x8004423C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80044240: jal         0x80045C88
    // 0x80044244: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80045C48(rdram, ctx);
        goto after_3;
    // 0x80044244: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_3:
    // 0x80044248: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004424C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80044250: nop

    // 0x80044254: lb          $t6, 0x214($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X214);
L_80044258:
    // 0x80044258: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004425C: bne         $t6, $zero, L_800442A8
    if (ctx->r14 != 0) {
        // 0x80044260: lui         $at, 0xBFE0
        ctx->r1 = S32(0XBFE0 << 16);
            goto L_800442A8;
    }
    // 0x80044260: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80044264: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80044268: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004426C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80044270: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80044274: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80044278: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8004427C: bc1f        L_800442A8
    if (!c1cs) {
        // 0x80044280: nop
    
            goto L_800442A8;
    }
    // 0x80044280: nop

    // 0x80044284: lb          $t7, 0x215($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X215);
    // 0x80044288: nop

    // 0x8004428C: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x80044290: sb          $t8, 0x215($a1)
    MEM_B(0X215, ctx->r5) = ctx->r24;
    // 0x80044294: lb          $t9, 0x215($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X215);
    // 0x80044298: nop

    // 0x8004429C: bgez        $t9, L_800442A8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800442A0: nop
    
            goto L_800442A8;
    }
    // 0x800442A0: nop

    // 0x800442A4: sb          $zero, 0x215($a1)
    MEM_B(0X215, ctx->r5) = 0;
L_800442A8:
    // 0x800442A8: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800442AC: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800442B0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800442B4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800442B8: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x800442BC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800442C0: lb          $v0, 0x214($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X214);
    // 0x800442C4: bc1f        L_800443B4
    if (!c1cs) {
        // 0x800442C8: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_800443B4;
    }
    // 0x800442C8: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x800442CC: bne         $v0, $zero, L_800443B0
    if (ctx->r2 != 0) {
        // 0x800442D0: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800443B0;
    }
    // 0x800442D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800442D4: lw          $t0, -0x2540($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2540);
    // 0x800442D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800442DC: bne         $t0, $zero, L_800443B4
    if (ctx->r8 != 0) {
        // 0x800442E0: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_800443B4;
    }
    // 0x800442E0: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x800442E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800442E8: lwc1        $f6, -0x253C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X253C);
    // 0x800442EC: nop

    // 0x800442F0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800442F4: nop

    // 0x800442F8: bc1f        L_800443B4
    if (!c1cs) {
        // 0x800442FC: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_800443B4;
    }
    // 0x800442FC: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x80044300: lb          $t1, 0x1E2($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X1E2);
    // 0x80044304: nop

    // 0x80044308: beq         $t1, $zero, L_800443B4
    if (ctx->r9 == 0) {
        // 0x8004430C: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_800443B4;
    }
    // 0x8004430C: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x80044310: lb          $t2, 0x215($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X215);
    // 0x80044314: nop

    // 0x80044318: bne         $t2, $zero, L_800443B4
    if (ctx->r10 != 0) {
        // 0x8004431C: subu        $t2, $v0, $v1
        ctx->r10 = SUB32(ctx->r2, ctx->r3);
            goto L_800443B4;
    }
    // 0x8004431C: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x80044320: lb          $t3, 0x213($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X213);
    // 0x80044324: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80044328: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x8004432C: sb          $t4, 0x213($a1)
    MEM_B(0X213, ctx->r5) = ctx->r12;
    // 0x80044330: lb          $t5, 0x213($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X213);
    // 0x80044334: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x80044338: slti        $at, $t5, 0x3D
    ctx->r1 = SIGNED(ctx->r13) < 0X3D ? 1 : 0;
    // 0x8004433C: bne         $at, $zero, L_800443A4
    if (ctx->r1 != 0) {
        // 0x80044340: andi        $t8, $a3, 0x40
        ctx->r24 = ctx->r7 & 0X40;
            goto L_800443A4;
    }
    // 0x80044340: andi        $t8, $a3, 0x40
    ctx->r24 = ctx->r7 & 0X40;
    // 0x80044344: sb          $zero, 0x213($a1)
    MEM_B(0X213, ctx->r5) = 0;
    // 0x80044348: sb          $t6, 0x214($a1)
    MEM_B(0X214, ctx->r5) = ctx->r14;
    // 0x8004434C: bne         $t8, $zero, L_8004436C
    if (ctx->r24 != 0) {
        // 0x80044350: sb          $t7, 0x215($a1)
        MEM_B(0X215, ctx->r5) = ctx->r15;
            goto L_8004436C;
    }
    // 0x80044350: sb          $t7, 0x215($a1)
    MEM_B(0X215, ctx->r5) = ctx->r15;
    // 0x80044354: lb          $t9, 0x1CA($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1CA);
    // 0x80044358: nop

    // 0x8004435C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80044360: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80044364: b           L_800443A4
    // 0x80044368: sb          $t1, 0x1CA($a1)
    MEM_B(0X1CA, ctx->r5) = ctx->r9;
        goto L_800443A4;
    // 0x80044368: sb          $t1, 0x1CA($a1)
    MEM_B(0X1CA, ctx->r5) = ctx->r9;
L_8004436C:
    // 0x8004436C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80044370: beq         $a3, $at, L_80044380
    if (ctx->r7 == ctx->r1) {
        // 0x80044374: addiu       $at, $zero, 0x41
        ctx->r1 = ADD32(0, 0X41);
            goto L_80044380;
    }
    // 0x80044374: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x80044378: bne         $a3, $at, L_800443A4
    if (ctx->r7 != ctx->r1) {
        // 0x8004437C: nop
    
            goto L_800443A4;
    }
    // 0x8004437C: nop

L_80044380:
    // 0x80044380: lbu         $a0, 0x1CE($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X1CE);
    // 0x80044384: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044388: beq         $a0, $at, L_800443A4
    if (ctx->r4 == ctx->r1) {
        // 0x8004438C: nop
    
            goto L_800443A4;
    }
    // 0x8004438C: nop

    // 0x80044390: jal         0x8001D248
    // 0x80044394: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    ainode_get(rdram, ctx);
        goto after_4;
    // 0x80044394: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x80044398: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004439C: nop

    // 0x800443A0: sw          $v0, 0x154($a1)
    MEM_W(0X154, ctx->r5) = ctx->r2;
L_800443A4:
    // 0x800443A4: lb          $v0, 0x214($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X214);
    // 0x800443A8: b           L_800443D4
    // 0x800443AC: nop

        goto L_800443D4;
    // 0x800443AC: nop

L_800443B0:
    // 0x800443B0: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
L_800443B4:
    // 0x800443B4: sb          $t2, 0x214($a1)
    MEM_B(0X214, ctx->r5) = ctx->r10;
    // 0x800443B8: lb          $v0, 0x214($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X214);
    // 0x800443BC: sb          $zero, 0x213($a1)
    MEM_B(0X213, ctx->r5) = 0;
    // 0x800443C0: bgez        $v0, L_800443D4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800443C4: nop
    
            goto L_800443D4;
    }
    // 0x800443C4: nop

    // 0x800443C8: sb          $zero, 0x214($a1)
    MEM_B(0X214, ctx->r5) = 0;
    // 0x800443CC: lb          $v0, 0x214($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X214);
    // 0x800443D0: nop

L_800443D4:
    // 0x800443D4: beq         $v0, $zero, L_80044420
    if (ctx->r2 == 0) {
        // 0x800443D8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80044420;
    }
    // 0x800443D8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800443DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800443E0: addiu       $v0, $v0, -0x2558
    ctx->r2 = ADD32(ctx->r2, -0X2558);
    // 0x800443E4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800443E8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800443EC: addiu       $v1, $v1, -0x254C
    ctx->r3 = ADD32(ctx->r3, -0X254C);
    // 0x800443F0: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x800443F4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800443F8: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800443FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80044400: addiu       $a0, $a0, -0x2548
    ctx->r4 = ADD32(ctx->r4, -0X2548);
    // 0x80044404: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80044408: addiu       $t7, $zero, -0x32
    ctx->r15 = ADD32(0, -0X32);
    // 0x8004440C: ori         $t9, $t6, 0x4000
    ctx->r25 = ctx->r14 | 0X4000;
    // 0x80044410: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x80044414: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80044418: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8004441C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80044420:
    // 0x80044420: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80044424: addiu       $v1, $v1, -0x254C
    ctx->r3 = ADD32(ctx->r3, -0X254C);
    // 0x80044428: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8004442C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80044430: slti        $at, $v0, 0x4C
    ctx->r1 = SIGNED(ctx->r2) < 0X4C ? 1 : 0;
    // 0x80044434: bne         $at, $zero, L_80044444
    if (ctx->r1 != 0) {
        // 0x80044438: addiu       $a0, $a0, -0x2548
        ctx->r4 = ADD32(ctx->r4, -0X2548);
            goto L_80044444;
    }
    // 0x80044438: addiu       $a0, $a0, -0x2548
    ctx->r4 = ADD32(ctx->r4, -0X2548);
    // 0x8004443C: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // 0x80044440: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80044444:
    // 0x80044444: slti        $at, $v0, -0x4B
    ctx->r1 = SIGNED(ctx->r2) < -0X4B ? 1 : 0;
    // 0x80044448: beq         $at, $zero, L_80044454
    if (ctx->r1 == 0) {
        // 0x8004444C: addiu       $t1, $zero, -0x4B
        ctx->r9 = ADD32(0, -0X4B);
            goto L_80044454;
    }
    // 0x8004444C: addiu       $t1, $zero, -0x4B
    ctx->r9 = ADD32(0, -0X4B);
    // 0x80044450: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_80044454:
    // 0x80044454: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80044458: addiu       $t3, $zero, -0x4B
    ctx->r11 = ADD32(0, -0X4B);
    // 0x8004445C: slti        $at, $v0, 0x4C
    ctx->r1 = SIGNED(ctx->r2) < 0X4C ? 1 : 0;
    // 0x80044460: bne         $at, $zero, L_80044474
    if (ctx->r1 != 0) {
        // 0x80044464: slti        $at, $v0, -0x4B
        ctx->r1 = SIGNED(ctx->r2) < -0X4B ? 1 : 0;
            goto L_80044474;
    }
    // 0x80044464: slti        $at, $v0, -0x4B
    ctx->r1 = SIGNED(ctx->r2) < -0X4B ? 1 : 0;
    // 0x80044468: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // 0x8004446C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80044470: slti        $at, $v0, -0x4B
    ctx->r1 = SIGNED(ctx->r2) < -0X4B ? 1 : 0;
L_80044474:
    // 0x80044474: beq         $at, $zero, L_80044484
    if (ctx->r1 == 0) {
        // 0x80044478: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80044484;
    }
    // 0x80044478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004447C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80044480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044484:
    // 0x80044484: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80044488: jr          $ra
    // 0x8004448C: nop

    return;
    // 0x8004448C: nop

;}
RECOMP_FUNC void obj_loop_posarrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003767C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80037680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037684: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80037688: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003768C: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80037690: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80037694: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80037698: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x8003769C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x800376A0: jal         0x8001BAE0
    // 0x800376A4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    get_racer_objects_by_position(rdram, ctx);
        goto after_0;
    // 0x800376A4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x800376A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800376AC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800376B0: lw          $v1, 0x78($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X78);
    // 0x800376B4: nop

    // 0x800376B8: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800376BC: beq         $at, $zero, L_80037710
    if (ctx->r1 == 0) {
        // 0x800376C0: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80037710;
    }
    // 0x800376C0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800376C4: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800376C8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800376CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800376D0: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x800376D4: nop

    // 0x800376D8: lh          $t1, 0x0($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X0);
    // 0x800376DC: nop

    // 0x800376E0: bne         $t1, $at, L_80037708
    if (ctx->r9 != ctx->r1) {
        // 0x800376E4: sll         $t4, $v1, 7
        ctx->r12 = S32(ctx->r3 << 7);
            goto L_80037708;
    }
    // 0x800376E4: sll         $t4, $v1, 7
    ctx->r12 = S32(ctx->r3 << 7);
    // 0x800376E8: lh          $t2, 0x6($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X6);
    // 0x800376EC: nop

    // 0x800376F0: andi        $t3, $t2, 0xBFFF
    ctx->r11 = ctx->r10 & 0XBFFF;
    // 0x800376F4: sh          $t3, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r11;
    // 0x800376F8: sw          $a1, 0x150($a2)
    MEM_W(0X150, ctx->r6) = ctx->r5;
    // 0x800376FC: lw          $v1, 0x78($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X78);
    // 0x80037700: nop

    // 0x80037704: sll         $t4, $v1, 7
    ctx->r12 = S32(ctx->r3 << 7);
L_80037708:
    // 0x80037708: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8003770C: sh          $t4, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r12;
L_80037710:
    // 0x80037710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037714: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80037718: jr          $ra
    // 0x8003771C: nop

    return;
    // 0x8003771C: nop

;}
RECOMP_FUNC void rdp_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800784A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800784A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800784AC: jal         0x8007A970
    // 0x800784B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800784B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800784B4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800784B8: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800784BC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800784C0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800784C4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800784C8: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x800784CC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800784D0: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x800784D4: lui         $t1, 0x100
    ctx->r9 = S32(0X100 << 16);
    // 0x800784D8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800784DC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800784E0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800784E4: lui         $t3, 0xFE00
    ctx->r11 = S32(0XFE00 << 16);
    // 0x800784E8: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800784EC: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800784F0: lui         $t4, 0x200
    ctx->r12 = S32(0X200 << 16);
    // 0x800784F4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800784F8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800784FC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80078500: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80078504: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80078508: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8007850C: addiu       $t7, $t7, -0x1560
    ctx->r15 = ADD32(ctx->r15, -0X1560);
    // 0x80078510: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80078514: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80078518: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007851C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078524: jr          $ra
    // 0x80078528: nop

    return;
    // 0x80078528: nop

;}
RECOMP_FUNC void block_boundbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A31C: bltz        $a0, L_8002A340
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002A320: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8002A340;
    }
    // 0x8002A320: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8002A324: lw          $v1, -0x3178($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3178);
    // 0x8002A328: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8002A32C: lh          $t6, 0x1A($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1A);
    // 0x8002A330: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8002A334: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002A338: beq         $at, $zero, L_8002A348
    if (ctx->r1 == 0) {
        // 0x8002A33C: nop
    
            goto L_8002A348;
    }
    // 0x8002A33C: nop

L_8002A340:
    // 0x8002A340: jr          $ra
    // 0x8002A344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002A344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A348:
    // 0x8002A348: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8002A34C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002A350: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002A354: jr          $ra
    // 0x8002A358: nop

    return;
    // 0x8002A358: nop

;}
RECOMP_FUNC void func_8000E898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E898: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000E89C: addiu       $t7, $t7, -0x4BE0
    ctx->r15 = ADD32(ctx->r15, -0X4BE0);
    // 0x8000E8A0: sll         $a2, $a1, 2
    ctx->r6 = S32(ctx->r5 << 2);
    // 0x8000E8A4: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8000E8A8: addu        $a3, $a2, $t7
    ctx->r7 = ADD32(ctx->r6, ctx->r15);
    // 0x8000E8AC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000E8B0: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8000E8B4: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x8000E8B8: lw          $t8, -0x4BE8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BE8);
    // 0x8000E8BC: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x8000E8C0: addu        $t9, $t0, $t6
    ctx->r25 = ADD32(ctx->r8, ctx->r14);
    // 0x8000E8C4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000E8C8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000E8CC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8000E8D0: blez        $t6, L_8000E940
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000E8D4: addu        $v1, $t0, $t8
        ctx->r3 = ADD32(ctx->r8, ctx->r24);
            goto L_8000E940;
    }
    // 0x8000E8D4: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x8000E8D8: andi        $t0, $t6, 0x3
    ctx->r8 = ctx->r14 & 0X3;
    // 0x8000E8DC: beq         $t0, $zero, L_8000E908
    if (ctx->r8 == 0) {
        // 0x8000E8E0: or          $a1, $t0, $zero
        ctx->r5 = ctx->r8 | 0;
            goto L_8000E908;
    }
    // 0x8000E8E0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8000E8E4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x8000E8E8: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
L_8000E8EC:
    // 0x8000E8EC: lbu         $t2, 0x0($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X0);
    // 0x8000E8F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8000E8F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000E8F8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8000E8FC: bne         $a1, $t1, L_8000E8EC
    if (ctx->r5 != ctx->r9) {
        // 0x8000E900: sb          $t2, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r10;
            goto L_8000E8EC;
    }
    // 0x8000E900: sb          $t2, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r10;
    // 0x8000E904: beq         $t1, $v0, L_8000E940
    if (ctx->r9 == ctx->r2) {
        // 0x8000E908: addu        $a2, $v1, $t1
        ctx->r6 = ADD32(ctx->r3, ctx->r9);
            goto L_8000E940;
    }
L_8000E908:
    // 0x8000E908: addu        $a2, $v1, $t1
    ctx->r6 = ADD32(ctx->r3, ctx->r9);
    // 0x8000E90C: addu        $a3, $a0, $t1
    ctx->r7 = ADD32(ctx->r4, ctx->r9);
L_8000E910:
    // 0x8000E910: lbu         $t3, 0x0($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X0);
    // 0x8000E914: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8000E918: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x8000E91C: lbu         $t4, 0x1($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X1);
    // 0x8000E920: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8000E924: sb          $t4, -0x3($a2)
    MEM_B(-0X3, ctx->r6) = ctx->r12;
    // 0x8000E928: lbu         $t5, 0x2($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X2);
    // 0x8000E92C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8000E930: sb          $t5, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r13;
    // 0x8000E934: lbu         $t6, -0x1($a3)
    ctx->r14 = MEM_BU(ctx->r7, -0X1);
    // 0x8000E938: bne         $t1, $v0, L_8000E910
    if (ctx->r9 != ctx->r2) {
        // 0x8000E93C: sb          $t6, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r14;
            goto L_8000E910;
    }
    // 0x8000E93C: sb          $t6, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r14;
L_8000E940:
    // 0x8000E940: jr          $ra
    // 0x8000E944: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000E944: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80049794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800497D4: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x800497D8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800497DC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800497E0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800497E4: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800497E8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800497EC: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800497F0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800497F4: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x800497F8: jal         0x8000E138
    // 0x800497FC: sw          $a1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r5;
    func_8000E138(rdram, ctx);
        goto after_0;
    // 0x800497FC: sw          $a1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r5;
    after_0:
    // 0x80049800: beq         $v0, $zero, L_80049824
    if (ctx->r2 == 0) {
        // 0x80049804: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80049824;
    }
    // 0x80049804: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049808: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x8004980C: lwc1        $f9, 0x6A38($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A38);
    // 0x80049810: lwc1        $f8, 0x6A3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A3C);
    // 0x80049814: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80049818: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8004981C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80049820: swc1        $f18, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f18.u32l;
L_80049824:
    // 0x80049824: sb          $zero, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = 0;
    // 0x80049828: lb          $t6, 0x1E2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004982C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80049830: blez        $t6, L_80049848
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80049834: nop
    
            goto L_80049848;
    }
    // 0x80049834: nop

    // 0x80049838: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004983C: nop

    // 0x80049840: swc1        $f14, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f14.u32l;
    // 0x80049844: swc1        $f14, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f14.u32l;
L_80049848:
    // 0x80049848: lbu         $t7, 0x1FE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004984C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80049850: bne         $t7, $at, L_8004987C
    if (ctx->r15 != ctx->r1) {
        // 0x80049854: nop
    
            goto L_8004987C;
    }
    // 0x80049854: nop

    // 0x80049858: lb          $t8, 0x1DB($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004985C: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    // 0x80049860: bne         $t8, $zero, L_8004987C
    if (ctx->r24 != 0) {
        // 0x80049864: nop
    
            goto L_8004987C;
    }
    // 0x80049864: nop

    // 0x80049868: jal         0x80001D04
    // 0x8004986C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8004986C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80049870: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80049874: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80049878: sb          $t9, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r25;
L_8004987C:
    // 0x8004987C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80049880: lw          $t3, -0x2524($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2524);
    // 0x80049884: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80049888: beq         $t1, $t3, L_80049B1C
    if (ctx->r9 == ctx->r11) {
        // 0x8004988C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80049B1C;
    }
    // 0x8004988C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80049890: lb          $t4, 0x1D7($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D7);
    // 0x80049894: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80049898: beq         $t4, $at, L_80049B1C
    if (ctx->r12 == ctx->r1) {
        // 0x8004989C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80049B1C;
    }
    // 0x8004989C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800498A0: lb          $v0, -0x24D2($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X24D2);
    // 0x800498A4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800498A8: beq         $v0, $zero, L_80049B1C
    if (ctx->r2 == 0) {
        // 0x800498AC: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_80049B1C;
    }
    // 0x800498AC: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800498B0: bltz        $v1, L_8004991C
    if (SIGNED(ctx->r3) < 0) {
        // 0x800498B4: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8004991C;
    }
    // 0x800498B4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800498B8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800498BC: lw          $t5, -0x24D0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X24D0);
    // 0x800498C0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800498C4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800498C8: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x800498CC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800498D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800498D4: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800498D8: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800498DC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800498E0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800498E4: nop

    // 0x800498E8: bc1f        L_8004991C
    if (!c1cs) {
        // 0x800498EC: nop
    
            goto L_8004991C;
    }
    // 0x800498EC: nop

L_800498F0:
    // 0x800498F0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800498F4: bltz        $a0, L_8004991C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800498F8: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_8004991C;
    }
    // 0x800498F8: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800498FC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80049900: nop

    // 0x80049904: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80049908: nop

    // 0x8004990C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80049910: nop

    // 0x80049914: bc1t        L_800498F0
    if (c1cs) {
        // 0x80049918: nop
    
            goto L_800498F0;
    }
    // 0x80049918: nop

L_8004991C:
    // 0x8004991C: lw          $t9, -0x24D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X24D0);
    // 0x80049920: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x80049924: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80049928: bne         $a0, $v1, L_80049938
    if (ctx->r4 != ctx->r3) {
        // 0x8004992C: addu        $v0, $t9, $a1
        ctx->r2 = ADD32(ctx->r25, ctx->r5);
            goto L_80049938;
    }
    // 0x8004992C: addu        $v0, $t9, $a1
    ctx->r2 = ADD32(ctx->r25, ctx->r5);
    // 0x80049930: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80049934: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_80049938:
    // 0x80049938: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8004993C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80049940: lwc1        $f2, 0x0($t3)
    ctx->f2.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80049944: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80049948: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8004994C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80049950: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80049954: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80049958: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8004995C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80049960: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049964: bc1f        L_80049970
    if (!c1cs) {
        // 0x80049968: lui         $at, 0x4020
        ctx->r1 = S32(0X4020 << 16);
            goto L_80049970;
    }
    // 0x80049968: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8004996C: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
L_80049970:
    // 0x80049970: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80049974: nop

    // 0x80049978: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8004997C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80049980: nop

    // 0x80049984: bc1f        L_80049990
    if (!c1cs) {
        // 0x80049988: nop
    
            goto L_80049990;
    }
    // 0x80049988: nop

    // 0x8004998C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_80049990:
    // 0x80049990: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80049994: nop

    // 0x80049998: bc1f        L_800499C0
    if (!c1cs) {
        // 0x8004999C: nop
    
            goto L_800499C0;
    }
    // 0x8004999C: nop

    // 0x800499A0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800499A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800499A8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800499AC: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x800499B0: nop

    // 0x800499B4: bc1f        L_800499C0
    if (!c1cs) {
        // 0x800499B8: nop
    
            goto L_800499C0;
    }
    // 0x800499B8: nop

    // 0x800499BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800499C0:
    // 0x800499C0: lb          $t4, 0x1E6($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E6);
    // 0x800499C4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800499C8: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800499CC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800499D0: bne         $t4, $zero, L_80049A08
    if (ctx->r12 != 0) {
        // 0x800499D4: lui         $at, 0x4218
        ctx->r1 = S32(0X4218 << 16);
            goto L_80049A08;
    }
    // 0x800499D4: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x800499D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800499DC: nop

    // 0x800499E0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x800499E4: nop

    // 0x800499E8: bc1f        L_80049A08
    if (!c1cs) {
        // 0x800499EC: nop
    
            goto L_80049A08;
    }
    // 0x800499EC: nop

    // 0x800499F0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800499F4: c.le.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d <= ctx->f4.d;
    // 0x800499F8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800499FC: bc1f        L_80049A08
    if (!c1cs) {
        // 0x80049A00: nop
    
            goto L_80049A08;
    }
    // 0x80049A00: nop

    // 0x80049A04: sb          $t5, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r13;
L_80049A08:
    // 0x80049A08: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x80049A0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049A10: beq         $v0, $at, L_80049A50
    if (ctx->r2 == ctx->r1) {
        // 0x80049A14: nop
    
            goto L_80049A50;
    }
    // 0x80049A14: nop

    // 0x80049A18: beq         $t1, $v0, L_80049A50
    if (ctx->r9 == ctx->r2) {
        // 0x80049A1C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80049A50;
    }
    // 0x80049A1C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80049A20: lw          $t6, -0x24D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X24D0);
    // 0x80049A24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049A28: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80049A2C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80049A30: lwc1        $f11, 0x6A40($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6A40);
    // 0x80049A34: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80049A38: lwc1        $f10, 0x6A44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6A44);
    // 0x80049A3C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80049A40: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80049A44: nop

    // 0x80049A48: bc1f        L_80049A58
    if (!c1cs) {
        // 0x80049A4C: nop
    
            goto L_80049A58;
    }
    // 0x80049A4C: nop

L_80049A50:
    // 0x80049A50: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
    // 0x80049A54: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_80049A58:
    // 0x80049A58: lb          $t9, 0x1E6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E6);
    // 0x80049A5C: nop

    // 0x80049A60: beq         $t9, $zero, L_80049B20
    if (ctx->r25 == 0) {
        // 0x80049A64: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80049B20;
    }
    // 0x80049A64: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80049A68: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80049A6C: c.lt.d      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.d < ctx->f12.d;
    // 0x80049A70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80049A74: bc1t        L_80049A94
    if (c1cs) {
        // 0x80049A78: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80049A94;
    }
    // 0x80049A78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80049A7C: addiu       $t0, $t0, -0x2548
    ctx->r8 = ADD32(ctx->r8, -0X2548);
    // 0x80049A80: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80049A84: nop

    // 0x80049A88: slti        $at, $t3, -0xA
    ctx->r1 = SIGNED(ctx->r11) < -0XA ? 1 : 0;
    // 0x80049A8C: beq         $at, $zero, L_80049AA4
    if (ctx->r1 == 0) {
        // 0x80049A90: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80049AA4;
    }
    // 0x80049A90: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_80049A94:
    // 0x80049A94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80049A98: addiu       $t0, $t0, -0x2548
    ctx->r8 = ADD32(ctx->r8, -0X2548);
    // 0x80049A9C: sb          $zero, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = 0;
    // 0x80049AA0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_80049AA4:
    // 0x80049AA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80049AA8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80049AAC: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80049AB0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80049AB4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80049AB8: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80049ABC: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80049AC0: bc1f        L_80049AD0
    if (!c1cs) {
        // 0x80049AC4: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80049AD0;
    }
    // 0x80049AC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049AC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80049ACC: nop

L_80049AD0:
    // 0x80049AD0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049AD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049AD8: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x80049ADC: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80049AE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80049AE4: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80049AE8: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80049AEC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80049AF0: nop

    // 0x80049AF4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80049AF8: nop

    // 0x80049AFC: div.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80049B00: add.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80049B04: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x80049B08: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80049B0C: nop

    // 0x80049B10: blez        $v0, L_80049B1C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80049B14: sra         $t4, $v0, 1
        ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80049B1C;
    }
    // 0x80049B14: sra         $t4, $v0, 1
    ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80049B18: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_80049B1C:
    // 0x80049B1C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_80049B20:
    // 0x80049B20: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80049B24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80049B28: sh          $zero, -0x2530($at)
    MEM_H(-0X2530, ctx->r1) = 0;
    // 0x80049B2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80049B30: sw          $zero, -0x252C($at)
    MEM_W(-0X252C, ctx->r1) = 0;
    // 0x80049B34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80049B38: sw          $zero, -0x2528($at)
    MEM_W(-0X2528, ctx->r1) = 0;
    // 0x80049B3C: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80049B40: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80049B44: swc1        $f4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f4.u32l;
    // 0x80049B48: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80049B4C: addiu       $t0, $t0, -0x2548
    ctx->r8 = ADD32(ctx->r8, -0X2548);
    // 0x80049B50: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
    // 0x80049B54: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80049B58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80049B5C: swc1        $f8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f8.u32l;
    // 0x80049B60: lb          $t5, 0x1E0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E0);
    // 0x80049B64: nop

    // 0x80049B68: beq         $t5, $zero, L_80049B7C
    if (ctx->r13 == 0) {
        // 0x80049B6C: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80049B7C;
    }
    // 0x80049B6C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80049B70: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80049B74: b           L_80049B84
    // 0x80049B78: lb          $a1, 0x1E1($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E1);
        goto L_80049B84;
    // 0x80049B78: lb          $a1, 0x1E1($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E1);
L_80049B7C:
    // 0x80049B7C: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x80049B80: lb          $a1, 0x1E1($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E1);
L_80049B84:
    // 0x80049B84: lw          $t6, -0x254C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X254C);
    // 0x80049B88: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80049B8C: subu        $v0, $t6, $a1
    ctx->r2 = SUB32(ctx->r14, ctx->r5);
    // 0x80049B90: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80049B94: nop

    // 0x80049B98: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80049B9C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80049BA0: nop

    // 0x80049BA4: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80049BA8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80049BAC: nop

    // 0x80049BB0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80049BB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80049BB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049BBC: nop

    // 0x80049BC0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80049BC4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80049BC8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80049BCC: beq         $v0, $zero, L_80049BF4
    if (ctx->r2 == 0) {
        // 0x80049BD0: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80049BF4;
    }
    // 0x80049BD0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80049BD4: bne         $a0, $zero, L_80049BF8
    if (ctx->r4 != 0) {
        // 0x80049BD8: addu        $t8, $a1, $v1
        ctx->r24 = ADD32(ctx->r5, ctx->r3);
            goto L_80049BF8;
    }
    // 0x80049BD8: addu        $t8, $a1, $v1
    ctx->r24 = ADD32(ctx->r5, ctx->r3);
    // 0x80049BDC: blez        $v0, L_80049BE8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80049BE0: nop
    
            goto L_80049BE8;
    }
    // 0x80049BE0: nop

    // 0x80049BE4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80049BE8:
    // 0x80049BE8: bgez        $v0, L_80049BF8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80049BEC: addu        $t8, $a1, $v1
        ctx->r24 = ADD32(ctx->r5, ctx->r3);
            goto L_80049BF8;
    }
    // 0x80049BEC: addu        $t8, $a1, $v1
    ctx->r24 = ADD32(ctx->r5, ctx->r3);
    // 0x80049BF0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80049BF4:
    // 0x80049BF4: addu        $t8, $a1, $v1
    ctx->r24 = ADD32(ctx->r5, ctx->r3);
L_80049BF8:
    // 0x80049BF8: sb          $t8, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = ctx->r24;
    // 0x80049BFC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80049C00: lb          $a3, 0x1E8($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1E8);
    // 0x80049C04: lwc1        $f6, 0xFC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80049C08: subu        $v0, $t9, $a3
    ctx->r2 = SUB32(ctx->r25, ctx->r7);
    // 0x80049C0C: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80049C10: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x80049C14: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80049C18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80049C1C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80049C20: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80049C24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80049C28: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80049C2C: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80049C30: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80049C34: nop

    // 0x80049C38: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80049C3C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80049C40: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049C44: nop

    // 0x80049C48: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80049C4C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80049C50: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80049C54: beq         $v0, $zero, L_80049C7C
    if (ctx->r2 == 0) {
        // 0x80049C58: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80049C7C;
    }
    // 0x80049C58: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80049C5C: bne         $a0, $zero, L_80049C80
    if (ctx->r4 != 0) {
        // 0x80049C60: addu        $t4, $a3, $v1
        ctx->r12 = ADD32(ctx->r7, ctx->r3);
            goto L_80049C80;
    }
    // 0x80049C60: addu        $t4, $a3, $v1
    ctx->r12 = ADD32(ctx->r7, ctx->r3);
    // 0x80049C64: blez        $v0, L_80049C70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80049C68: nop
    
            goto L_80049C70;
    }
    // 0x80049C68: nop

    // 0x80049C6C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80049C70:
    // 0x80049C70: bgez        $v0, L_80049C80
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80049C74: addu        $t4, $a3, $v1
        ctx->r12 = ADD32(ctx->r7, ctx->r3);
            goto L_80049C80;
    }
    // 0x80049C74: addu        $t4, $a3, $v1
    ctx->r12 = ADD32(ctx->r7, ctx->r3);
    // 0x80049C78: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80049C7C:
    // 0x80049C7C: addu        $t4, $a3, $v1
    ctx->r12 = ADD32(ctx->r7, ctx->r3);
L_80049C80:
    // 0x80049C80: sb          $t4, 0x1E8($s0)
    MEM_B(0X1E8, ctx->r16) = ctx->r12;
    // 0x80049C84: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x80049C88: sb          $t2, 0xA2($sp)
    MEM_B(0XA2, ctx->r29) = ctx->r10;
    // 0x80049C8C: jal         0x80055F00
    // 0x80049C90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    handle_racer_items(rdram, ctx);
        goto after_2;
    // 0x80049C90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80049C94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80049C98: jal         0x80053604
    // 0x80049C9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800535C4(rdram, ctx);
        goto after_3;
    // 0x80049C9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80049CA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80049CA4: jal         0x8004C180
    // 0x80049CA8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_attack_handler_plane(rdram, ctx);
        goto after_4;
    // 0x80049CA8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80049CAC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80049CB0: lw          $t5, -0x2524($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2524);
    // 0x80049CB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80049CB8: beq         $t5, $at, L_80049CD8
    if (ctx->r13 == ctx->r1) {
        // 0x80049CBC: nop
    
            goto L_80049CD8;
    }
    // 0x80049CBC: nop

    // 0x80049CC0: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x80049CC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80049CC8: jal         0x80052204
    // 0x80049CCC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    handle_racer_head_turning(rdram, ctx);
        goto after_5;
    // 0x80049CCC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80049CD0: b           L_80049CE0
    // 0x80049CD4: nop

        goto L_80049CE0;
    // 0x80049CD4: nop

L_80049CD8:
    // 0x80049CD8: jal         0x8005238C
    // 0x80049CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    slowly_reset_head_angle(rdram, ctx);
        goto after_6;
    // 0x80049CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80049CE0:
    // 0x80049CE0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80049CE4: lw          $t6, -0x2558($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2558);
    // 0x80049CE8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80049CEC: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80049CF0: beq         $t7, $zero, L_80049D58
    if (ctx->r15 == 0) {
        // 0x80049CF4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80049D58;
    }
    // 0x80049CF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049CF8: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80049CFC: lwc1        $f5, 0x6A48($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6A48);
    // 0x80049D00: lwc1        $f4, 0x6A4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6A4C);
    // 0x80049D04: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80049D08: mul.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80049D0C: lwc1        $f10, 0xB4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80049D10: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80049D14: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80049D18: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80049D1C: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x80049D20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80049D24: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80049D28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80049D2C: swc1        $f10, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f10.u32l;
    // 0x80049D30: lwc1        $f18, 0xB4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80049D34: nop

    // 0x80049D38: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80049D3C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80049D40: nop

    // 0x80049D44: bc1f        L_80049DB0
    if (!c1cs) {
        // 0x80049D48: nop
    
            goto L_80049DB0;
    }
    // 0x80049D48: nop

    // 0x80049D4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049D50: b           L_80049DB0
    // 0x80049D54: swc1        $f8, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
        goto L_80049DB0;
    // 0x80049D54: swc1        $f8, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
L_80049D58:
    // 0x80049D58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049D5C: lwc1        $f10, 0xFC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80049D60: lwc1        $f7, 0x6A50($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6A50);
    // 0x80049D64: lwc1        $f6, 0x6A54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6A54);
    // 0x80049D68: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80049D6C: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x80049D70: lwc1        $f18, 0xB4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80049D74: nop

    // 0x80049D78: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80049D7C: sub.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d - ctx->f8.d;
    // 0x80049D80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80049D84: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80049D88: swc1        $f18, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f18.u32l;
    // 0x80049D8C: lwc1        $f6, 0xB4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80049D90: nop

    // 0x80049D94: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80049D98: nop

    // 0x80049D9C: bc1f        L_80049DB0
    if (!c1cs) {
        // 0x80049DA0: nop
    
            goto L_80049DB0;
    }
    // 0x80049DA0: nop

    // 0x80049DA4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80049DA8: nop

    // 0x80049DAC: swc1        $f8, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
L_80049DB0:
    // 0x80049DB0: lw          $t8, 0x108($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X108);
    // 0x80049DB4: nop

    // 0x80049DB8: beq         $t8, $zero, L_80049DCC
    if (ctx->r24 == 0) {
        // 0x80049DBC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80049DCC;
    }
    // 0x80049DBC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80049DC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80049DC4: nop

    // 0x80049DC8: swc1        $f10, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f10.u32l;
L_80049DCC:
    // 0x80049DCC: lw          $t9, -0x2558($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2558);
    // 0x80049DD0: lwc1        $f18, 0xB4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80049DD4: andi        $t3, $t9, 0x4000
    ctx->r11 = ctx->r25 & 0X4000;
    // 0x80049DD8: beq         $t3, $zero, L_80049EBC
    if (ctx->r11 == 0) {
        // 0x80049DDC: swc1        $f18, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
            goto L_80049EBC;
    }
    // 0x80049DDC: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    // 0x80049DE0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80049DE4: lw          $t4, -0x2548($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2548);
    // 0x80049DE8: nop

    // 0x80049DEC: slti        $at, $t4, -0x28
    ctx->r1 = SIGNED(ctx->r12) < -0X28 ? 1 : 0;
    // 0x80049DF0: bne         $at, $zero, L_80049E10
    if (ctx->r1 != 0) {
        // 0x80049DF4: nop
    
            goto L_80049E10;
    }
    // 0x80049DF4: nop

    // 0x80049DF8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80049DFC: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80049E00: nop

    // 0x80049E04: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80049E08: nop

    // 0x80049E0C: bc1f        L_80049EBC
    if (!c1cs) {
        // 0x80049E10: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80049EBC;
    }
L_80049E10:
    // 0x80049E10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049E14: lwc1        $f11, 0x6A58($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6A58);
    // 0x80049E18: lwc1        $f10, 0x6A5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6A5C);
    // 0x80049E1C: lwc1        $f4, 0xB8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049E20: mul.d       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x80049E24: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80049E28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049E2C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80049E30: add.d       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f8.d + ctx->f18.d;
    // 0x80049E34: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80049E38: swc1        $f4, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f4.u32l;
    // 0x80049E3C: lwc1        $f8, 0xB8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049E40: lwc1        $f10, 0x6A64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6A64);
    // 0x80049E44: lwc1        $f11, 0x6A60($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6A60);
    // 0x80049E48: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80049E4C: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x80049E50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80049E54: bc1f        L_80049E68
    if (!c1cs) {
        // 0x80049E58: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80049E68;
    }
    // 0x80049E58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049E5C: lwc1        $f6, 0x6A68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6A68);
    // 0x80049E60: nop

    // 0x80049E64: swc1        $f6, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f6.u32l;
L_80049E68:
    // 0x80049E68: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80049E6C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80049E70: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80049E74: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80049E78: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80049E7C: nop

    // 0x80049E80: bc1f        L_80049EB0
    if (!c1cs) {
        // 0x80049E84: nop
    
            goto L_80049EB0;
    }
    // 0x80049E84: nop

    // 0x80049E88: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x80049E8C: nop

    // 0x80049E90: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x80049E94: bne         $at, $zero, L_80049EB0
    if (ctx->r1 != 0) {
        // 0x80049E98: nop
    
            goto L_80049EB0;
    }
    // 0x80049E98: nop

    // 0x80049E9C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80049EA0: jal         0x80072594
    // 0x80049EA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    rumble_set(rdram, ctx);
        goto after_7;
    // 0x80049EA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80049EA8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80049EAC: nop

L_80049EB0:
    // 0x80049EB0: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049EB4: b           L_80049F0C
    // 0x80049EB8: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
        goto L_80049F0C;
    // 0x80049EB8: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
L_80049EBC:
    // 0x80049EBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80049EC0: lwc1        $f5, 0x6A70($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6A70);
    // 0x80049EC4: lwc1        $f4, 0x6A74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6A74);
    // 0x80049EC8: lwc1        $f18, 0xB8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049ECC: mul.d       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80049ED0: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80049ED4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80049ED8: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80049EDC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80049EE0: swc1        $f18, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f18.u32l;
    // 0x80049EE4: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049EE8: nop

    // 0x80049EEC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80049EF0: nop

    // 0x80049EF4: bc1f        L_80049F08
    if (!c1cs) {
        // 0x80049EF8: nop
    
            goto L_80049F08;
    }
    // 0x80049EF8: nop

    // 0x80049EFC: swc1        $f12, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f12.u32l;
    // 0x80049F00: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80049F04: nop

L_80049F08:
    // 0x80049F08: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
L_80049F0C:
    // 0x80049F0C: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x80049F10: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80049F14: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x80049F18: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80049F1C: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x80049F20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80049F24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80049F28: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80049F2C: swc1        $f12, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f12.u32l;
    // 0x80049F30: swc1        $f12, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f12.u32l;
    // 0x80049F34: swc1        $f12, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f12.u32l;
    // 0x80049F38: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80049F3C: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x80049F40: jal         0x8006FE70
    // 0x80049F44: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_8;
    // 0x80049F44: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_8:
    // 0x80049F48: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80049F4C: addiu       $t8, $s0, 0x38
    ctx->r24 = ADD32(ctx->r16, 0X38);
    // 0x80049F50: addiu       $t9, $s0, 0x3C
    ctx->r25 = ADD32(ctx->r16, 0X3C);
    // 0x80049F54: addiu       $t3, $s0, 0x40
    ctx->r11 = ADD32(ctx->r16, 0X40);
    // 0x80049F58: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80049F5C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80049F60: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80049F64: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80049F68: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80049F6C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80049F70: jal         0x8006F88C
    // 0x80049F74: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_9;
    // 0x80049F74: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_9:
    // 0x80049F78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80049F7C: addiu       $t4, $s0, 0x50
    ctx->r12 = ADD32(ctx->r16, 0X50);
    // 0x80049F80: addiu       $t5, $s0, 0x54
    ctx->r13 = ADD32(ctx->r16, 0X54);
    // 0x80049F84: addiu       $t6, $s0, 0x58
    ctx->r14 = ADD32(ctx->r16, 0X58);
    // 0x80049F88: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80049F8C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80049F90: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80049F94: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80049F98: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80049F9C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80049FA0: jal         0x8006F88C
    // 0x80049FA4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_10;
    // 0x80049FA4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
    // 0x80049FA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80049FAC: addiu       $t7, $s0, 0x44
    ctx->r15 = ADD32(ctx->r16, 0X44);
    // 0x80049FB0: addiu       $t8, $s0, 0x48
    ctx->r24 = ADD32(ctx->r16, 0X48);
    // 0x80049FB4: addiu       $t9, $s0, 0x4C
    ctx->r25 = ADD32(ctx->r16, 0X4C);
    // 0x80049FB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80049FBC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80049FC0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80049FC4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80049FC8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80049FCC: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80049FD0: jal         0x8006F88C
    // 0x80049FD4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_11;
    // 0x80049FD4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_11:
    // 0x80049FD8: lw          $t3, 0x148($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X148);
    // 0x80049FDC: nop

    // 0x80049FE0: bne         $t3, $zero, L_80049FF8
    if (ctx->r11 != 0) {
        // 0x80049FE4: nop
    
            goto L_80049FF8;
    }
    // 0x80049FE4: nop

    // 0x80049FE8: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    // 0x80049FEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80049FF0: jal         0x8004C0E0
    // 0x80049FF4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    apply_plane_tilt_anim(rdram, ctx);
        goto after_12;
    // 0x80049FF4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
L_80049FF8:
    // 0x80049FF8: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80049FFC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8004A000: bne         $v1, $v0, L_8004A024
    if (ctx->r3 != ctx->r2) {
        // 0x8004A004: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8004A024;
    }
    // 0x8004A004: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004A008: lw          $t4, -0x2524($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2524);
    // 0x8004A00C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A010: beq         $v1, $t4, L_8004A024
    if (ctx->r3 == ctx->r12) {
        // 0x8004A014: nop
    
            goto L_8004A024;
    }
    // 0x8004A014: nop

    // 0x8004A018: lwc1        $f6, 0x6A78($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6A78);
    // 0x8004A01C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004A020: swc1        $f6, -0x2510($at)
    MEM_W(-0X2510, ctx->r1) = ctx->f6.u32l;
L_8004A024:
    // 0x8004A024: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004A028: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004A02C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8004A030: lwc1        $f14, 0x20($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004A034: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004A038: nop

    // 0x8004A03C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8004A040: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004A044: jal         0x800CA030
    // 0x8004A048: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_13;
    // 0x8004A048: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_13:
    // 0x8004A04C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004A050: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8004A054: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004A058: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8004A05C: lb          $t5, 0x1D6($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004A060: sub.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d - ctx->f14.d;
    // 0x8004A064: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x8004A068: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8004A06C: bne         $at, $zero, L_8004A094
    if (ctx->r1 != 0) {
        // 0x8004A070: mov.s       $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
            goto L_8004A094;
    }
    // 0x8004A070: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x8004A074: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8004A078: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004A07C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004A080: sub.d       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = ctx->f10.d - ctx->f14.d;
    // 0x8004A084: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004A088: nop

    // 0x8004A08C: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8004A090: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
L_8004A094:
    // 0x8004A094: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004A098: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8004A09C: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x8004A0A0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004A0A4: bc1f        L_8004A0B0
    if (!c1cs) {
        // 0x8004A0A8: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8004A0B0;
    }
    // 0x8004A0A8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004A0AC: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_8004A0B0:
    // 0x8004A0B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004A0B4: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8004A0B8: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8004A0BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004A0C0: bc1f        L_8004A0D4
    if (!c1cs) {
        // 0x8004A0C4: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8004A0D4;
    }
    // 0x8004A0C4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004A0C8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A0CC: nop

    // 0x8004A0D0: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
L_8004A0D4:
    // 0x8004A0D4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004A0D8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004A0DC: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8004A0E0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004A0E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004A0E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004A0EC: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x8004A0F0: lwc1        $f8, -0x2590($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2590);
    // 0x8004A0F4: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8004A0F8: sb          $zero, 0xA3($sp)
    MEM_B(0XA3, ctx->r29) = 0;
    // 0x8004A0FC: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004A100: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x8004A104: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004A108: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004A10C: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8004A110: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004A114: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8004A118: sub.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d - ctx->f10.d;
    // 0x8004A11C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004A120: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004A124: sub.d       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f4.d - ctx->f8.d;
    // 0x8004A128: beq         $at, $zero, L_8004A1B8
    if (ctx->r1 == 0) {
        // 0x8004A12C: cvt.s.d     $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
            goto L_8004A1B8;
    }
    // 0x8004A12C: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x8004A130: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
    // 0x8004A134: bne         $at, $zero, L_8004A1B8
    if (ctx->r1 != 0) {
        // 0x8004A138: nop
    
            goto L_8004A1B8;
    }
    // 0x8004A138: nop

    // 0x8004A13C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8004A140: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x8004A144: bc1f        L_8004A1B8
    if (!c1cs) {
        // 0x8004A148: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8004A1B8;
    }
    // 0x8004A148: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004A14C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004A150: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004A154: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x8004A158: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8004A15C: nop

    // 0x8004A160: div.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f4.d);
    // 0x8004A164: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004A168: addiu       $t1, $t1, -0x2548
    ctx->r9 = ADD32(ctx->r9, -0X2548);
    // 0x8004A16C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8004A170: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8004A174: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004A178: slti        $at, $t6, -0x14
    ctx->r1 = SIGNED(ctx->r14) < -0X14 ? 1 : 0;
    // 0x8004A17C: addiu       $t7, $zero, -0x14
    ctx->r15 = ADD32(0, -0X14);
    // 0x8004A180: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x8004A184: beq         $at, $zero, L_8004A190
    if (ctx->r1 == 0) {
        // 0x8004A188: cvt.s.d     $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
            goto L_8004A190;
    }
    // 0x8004A188: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
    // 0x8004A18C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_8004A190:
    // 0x8004A190: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x8004A194: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004A198: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x8004A19C: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8004A1A0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8004A1A4: bc1f        L_8004A1B4
    if (!c1cs) {
        // 0x8004A1A8: nop
    
            goto L_8004A1B4;
    }
    // 0x8004A1A8: nop

    // 0x8004A1AC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A1B0: nop

L_8004A1B4:
    // 0x8004A1B4: sb          $t8, 0xA3($sp)
    MEM_B(0XA3, ctx->r29) = ctx->r24;
L_8004A1B8:
    // 0x8004A1B8: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004A1BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004A1C0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004A1C4: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8004A1C8: addiu       $t1, $t1, -0x2548
    ctx->r9 = ADD32(ctx->r9, -0X2548);
    // 0x8004A1CC: bc1f        L_8004A1D8
    if (!c1cs) {
        // 0x8004A1D0: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_8004A1D8;
    }
    // 0x8004A1D0: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8004A1D4: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_8004A1D8:
    // 0x8004A1D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004A1DC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004A1E0: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8004A1E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004A1E8: bc1f        L_8004A1F4
    if (!c1cs) {
        // 0x8004A1EC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8004A1F4;
    }
    // 0x8004A1EC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8004A1F0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_8004A1F4:
    // 0x8004A1F4: add.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8004A1F8: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x8004A1FC: nop

    // 0x8004A200: bc1f        L_8004A214
    if (!c1cs) {
        // 0x8004A204: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8004A214;
    }
    // 0x8004A204: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8004A208: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004A20C: nop

    // 0x8004A210: add.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f4.fl;
L_8004A214:
    // 0x8004A214: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8004A218: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004A21C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A220: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8004A224: nop

    // 0x8004A228: bc1f        L_8004A234
    if (!c1cs) {
        // 0x8004A22C: nop
    
            goto L_8004A234;
    }
    // 0x8004A22C: nop

    // 0x8004A230: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8004A234:
    // 0x8004A234: lwc1        $f2, 0x6A7C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6A7C);
    // 0x8004A238: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A23C: lwc1        $f12, 0x6A80($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6A80);
    // 0x8004A240: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8004A244: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A248: lwc1        $f16, 0x6A84($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6A84);
    // 0x8004A24C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8004A250: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004A254: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004A258: lw          $t3, -0x251C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X251C);
    // 0x8004A25C: cvt.w.s     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.u32l = CVT_W_S(ctx->f14.fl);
    // 0x8004A260: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004A264: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8004A268: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8004A26C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8004A270: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8004A274: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004A278: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004A27C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004A280: sub.s       $f0, $f14, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8004A284: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x8004A288: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004A28C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8004A290: sub.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f6.d - ctx->f4.d;
    // 0x8004A294: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8004A298: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004A29C: mul.d       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8004A2A0: swc1        $f2, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f2.u32l;
    // 0x8004A2A4: swc1        $f12, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f12.u32l;
    // 0x8004A2A8: swc1        $f16, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f16.u32l;
    // 0x8004A2AC: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004A2B0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004A2B4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8004A2B8: add.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d + ctx->f10.d;
    // 0x8004A2BC: beq         $t5, $zero, L_8004A540
    if (ctx->r13 == 0) {
        // 0x8004A2C0: cvt.s.d     $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
            goto L_8004A540;
    }
    // 0x8004A2C0: cvt.s.d     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f14.fl = CVT_S_D(ctx->f18.d);
    // 0x8004A2C4: swc1        $f12, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f12.u32l;
    // 0x8004A2C8: swc1        $f2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f2.u32l;
    // 0x8004A2CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004A2D0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004A2D4: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8004A2D8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8004A2DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8004A2E0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8004A2E4:
    // 0x8004A2E4: lbu         $v0, 0x1DC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1DC);
    // 0x8004A2E8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8004A2EC: beq         $a0, $v0, L_8004A300
    if (ctx->r4 == ctx->r2) {
        // 0x8004A2F0: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8004A300;
    }
    // 0x8004A2F0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004A2F4: beq         $at, $zero, L_8004A300
    if (ctx->r1 == 0) {
        // 0x8004A2F8: nop
    
            goto L_8004A300;
    }
    // 0x8004A2F8: nop

    // 0x8004A2FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8004A300:
    // 0x8004A300: bne         $t0, $a2, L_8004A2E4
    if (ctx->r8 != ctx->r6) {
        // 0x8004A304: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004A2E4;
    }
    // 0x8004A304: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004A308: bne         $a1, $a2, L_8004A314
    if (ctx->r5 != ctx->r6) {
        // 0x8004A30C: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8004A314;
    }
    // 0x8004A30C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004A310: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
L_8004A314:
    // 0x8004A314: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8004A318: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8004A31C: bne         $t6, $zero, L_8004A344
    if (ctx->r14 != 0) {
        // 0x8004A320: nop
    
            goto L_8004A344;
    }
    // 0x8004A320: nop

    // 0x8004A324: bne         $a1, $at, L_8004A344
    if (ctx->r5 != ctx->r1) {
        // 0x8004A328: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8004A344;
    }
    // 0x8004A328: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004A32C: lw          $t7, -0x2554($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2554);
    // 0x8004A330: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8004A334: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x8004A338: beq         $t8, $zero, L_8004A344
    if (ctx->r24 == 0) {
        // 0x8004A33C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004A344;
    }
    // 0x8004A33C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004A340: sb          $t9, -0x24FE($at)
    MEM_B(-0X24FE, ctx->r1) = ctx->r25;
L_8004A344:
    // 0x8004A344: lw          $t3, -0x2558($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2558);
    // 0x8004A348: nop

    // 0x8004A34C: andi        $t4, $t3, 0x4000
    ctx->r12 = ctx->r11 & 0X4000;
    // 0x8004A350: beq         $t4, $zero, L_8004A3A0
    if (ctx->r12 == 0) {
        // 0x8004A354: nop
    
            goto L_8004A3A0;
    }
    // 0x8004A354: nop

    // 0x8004A358: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8004A35C: nop

    // 0x8004A360: slti        $at, $t5, -0x28
    ctx->r1 = SIGNED(ctx->r13) < -0X28 ? 1 : 0;
    // 0x8004A364: bne         $at, $zero, L_8004A3A0
    if (ctx->r1 != 0) {
        // 0x8004A368: nop
    
            goto L_8004A3A0;
    }
    // 0x8004A368: nop

    // 0x8004A36C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004A370: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8004A374: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004A378: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004A37C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8004A380: c.le.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d <= ctx->f8.d;
    // 0x8004A384: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004A388: bc1f        L_8004A3A0
    if (!c1cs) {
        // 0x8004A38C: nop
    
            goto L_8004A3A0;
    }
    // 0x8004A38C: nop

    // 0x8004A390: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004A394: nop

    // 0x8004A398: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8004A39C: swc1        $f18, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f18.u32l;
L_8004A3A0:
    // 0x8004A3A0: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004A3A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A3A8: bne         $t6, $zero, L_8004A444
    if (ctx->r14 != 0) {
        // 0x8004A3AC: nop
    
            goto L_8004A444;
    }
    // 0x8004A3AC: nop

    // 0x8004A3B0: bne         $a1, $at, L_8004A444
    if (ctx->r5 != ctx->r1) {
        // 0x8004A3B4: addiu       $a0, $zero, 0x2D
        ctx->r4 = ADD32(0, 0X2D);
            goto L_8004A444;
    }
    // 0x8004A3B4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x8004A3B8: swc1        $f1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x8004A3BC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8004A3C0: jal         0x8000C8B4
    // 0x8004A3C4: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    normalise_time(rdram, ctx);
        goto after_14;
    // 0x8004A3C4: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_14:
    // 0x8004A3C8: lbu         $t8, 0x20C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X20C);
    // 0x8004A3CC: lwc1        $f1, 0x48($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x8004A3D0: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004A3D4: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A3D8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8004A3DC: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x8004A3E0: beq         $t8, $zero, L_8004A3F8
    if (ctx->r24 == 0) {
        // 0x8004A3E4: sb          $t7, 0x203($s0)
        MEM_B(0X203, ctx->r16) = ctx->r15;
            goto L_8004A3F8;
    }
    // 0x8004A3E4: sb          $t7, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r15;
    // 0x8004A3E8: lb          $t9, 0x203($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X203);
    // 0x8004A3EC: nop

    // 0x8004A3F0: ori         $t3, $t9, 0x4
    ctx->r11 = ctx->r25 | 0X4;
    // 0x8004A3F4: sb          $t3, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r11;
L_8004A3F8:
    // 0x8004A3F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004A3FC: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    // 0x8004A400: swc1        $f1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x8004A404: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8004A408: jal         0x80057088
    // 0x8004A40C: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    racer_play_sound(rdram, ctx);
        goto after_15;
    // 0x8004A40C: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_15:
    // 0x8004A410: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004A414: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x8004A418: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8004A41C: jal         0x800570F8
    // 0x8004A420: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_16;
    // 0x8004A420: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_16:
    // 0x8004A424: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004A428: jal         0x80072594
    // 0x8004A42C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_17;
    // 0x8004A42C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_17:
    // 0x8004A430: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8004A434: lwc1        $f1, 0x48($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x8004A438: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004A43C: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A440: addiu       $t1, $t1, -0x2548
    ctx->r9 = ADD32(ctx->r9, -0X2548);
L_8004A444:
    // 0x8004A444: lb          $t4, 0x1D6($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004A448: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004A44C: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8004A450: bne         $at, $zero, L_8004A4B4
    if (ctx->r1 != 0) {
        // 0x8004A454: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8004A4B4;
    }
    // 0x8004A454: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8004A458: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004A45C: lui         $at, 0xC018
    ctx->r1 = S32(0XC018 << 16);
    // 0x8004A460: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004A464: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004A468: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8004A46C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8004A470: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8004A474: bc1f        L_8004A4B4
    if (!c1cs) {
        // 0x8004A478: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004A4B4;
    }
    // 0x8004A478: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A47C: lwc1        $f9, 0x6A88($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A88);
    // 0x8004A480: lwc1        $f8, 0x6A8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A8C);
    // 0x8004A484: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8004A488: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8004A48C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004A490: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8004A494: lwc1        $f9, 0x6A90($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A90);
    // 0x8004A498: lwc1        $f8, 0x6A94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A94);
    // 0x8004A49C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004A4A0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8004A4A4: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x8004A4A8: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x8004A4AC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004A4B0: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
L_8004A4B4:
    // 0x8004A4B4: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004A4B8: lw          $t5, -0x2558($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2558);
    // 0x8004A4BC: nop

    // 0x8004A4C0: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x8004A4C4: beq         $t6, $zero, L_8004A4E4
    if (ctx->r14 == 0) {
        // 0x8004A4C8: nop
    
            goto L_8004A4E4;
    }
    // 0x8004A4C8: nop

    // 0x8004A4CC: lw          $t7, -0x2EF8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2EF8);
    // 0x8004A4D0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8004A4D4: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8004A4D8: beq         $at, $zero, L_8004A4E4
    if (ctx->r1 == 0) {
        // 0x8004A4DC: nop
    
            goto L_8004A4E4;
    }
    // 0x8004A4DC: nop

    // 0x8004A4E0: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
L_8004A4E4:
    // 0x8004A4E4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8004A4E8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004A4EC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8004A4F0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004A4F4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004A4F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004A4FC: nop

    // 0x8004A500: sub.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d - ctx->f0.d;
    // 0x8004A504: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8004A508: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8004A50C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8004A510: nop

    // 0x8004A514: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8004A518: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004A51C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004A520: nop

    // 0x8004A524: cvt.w.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_D(ctx->f10.d);
    // 0x8004A528: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x8004A52C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8004A530: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8004A534: blez        $t4, L_8004A544
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8004A538: lb          $t5, 0xA3($sp)
        ctx->r13 = MEM_B(ctx->r29, 0XA3);
            goto L_8004A544;
    }
    // 0x8004A538: lb          $t5, 0xA3($sp)
    ctx->r13 = MEM_B(ctx->r29, 0XA3);
    // 0x8004A53C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_8004A540:
    // 0x8004A540: lb          $t5, 0xA3($sp)
    ctx->r13 = MEM_B(ctx->r29, 0XA3);
L_8004A544:
    // 0x8004A544: lb          $v0, 0x1D6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004A548: bne         $t5, $zero, L_8004A588
    if (ctx->r13 != 0) {
        // 0x8004A54C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8004A588;
    }
    // 0x8004A54C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8004A550: lui         $at, 0x4590
    ctx->r1 = S32(0X4590 << 16);
    // 0x8004A554: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004A558: nop

    // 0x8004A55C: mul.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8004A560: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8004A564: nop

    // 0x8004A568: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8004A56C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004A570: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004A574: nop

    // 0x8004A578: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8004A57C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8004A580: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8004A584: nop

L_8004A588:
    // 0x8004A588: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8004A58C: bne         $at, $zero, L_8004A598
    if (ctx->r1 != 0) {
        // 0x8004A590: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8004A598;
    }
    // 0x8004A590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004A594: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8004A598:
    // 0x8004A598: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004A59C: bne         $v0, $at, L_8004A5AC
    if (ctx->r2 != ctx->r1) {
        // 0x8004A5A0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8004A5AC;
    }
    // 0x8004A5A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004A5A4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004A5A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8004A5AC:
    // 0x8004A5AC: sll         $a3, $t0, 16
    ctx->r7 = S32(ctx->r8 << 16);
    // 0x8004A5B0: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8004A5B4: lw          $a1, 0xF8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF8);
    // 0x8004A5B8: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8004A5BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8004A5C0: jal         0x80050890
    // 0x8004A5C4: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    apply_vehicle_rotation_offset(rdram, ctx);
        goto after_18;
    // 0x8004A5C4: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_18:
    // 0x8004A5C8: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004A5CC: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A5D0: bne         $v0, $zero, L_8004A5F4
    if (ctx->r2 != 0) {
        // 0x8004A5D4: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8004A5F4;
    }
    // 0x8004A5D4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004A5D8: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x8004A5DC: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x8004A5E0: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x8004A5E4: sw          $t9, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r25;
    // 0x8004A5E8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A5EC: lbu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1FE);
    // 0x8004A5F0: nop

L_8004A5F4:
    // 0x8004A5F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004A5F8: bne         $v0, $at, L_8004A608
    if (ctx->r2 != ctx->r1) {
        // 0x8004A5FC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8004A608;
    }
    // 0x8004A5FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004A600: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A604: nop

L_8004A608:
    // 0x8004A608: lwc1        $f18, 0xC0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004A60C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8004A610: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004A614: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8004A618: c.eq.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d == ctx->f4.d;
    // 0x8004A61C: nop

    // 0x8004A620: bc1t        L_8004A6A8
    if (c1cs) {
        // 0x8004A624: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8004A6A8;
    }
    // 0x8004A624: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8004A628: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004A62C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004A630: addiu       $t3, $zero, -0x3C
    ctx->r11 = ADD32(0, -0X3C);
    // 0x8004A634: sw          $t3, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = ctx->r11;
    // 0x8004A638: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004A63C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004A640: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004A644: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8004A648: sub.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8004A64C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004A650: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x8004A654: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8004A658: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004A65C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004A660: bc1f        L_8004A674
    if (!c1cs) {
        // 0x8004A664: nop
    
            goto L_8004A674;
    }
    // 0x8004A664: nop

    // 0x8004A668: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004A66C: nop

    // 0x8004A670: nop

L_8004A674:
    // 0x8004A674: div.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8004A678: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8004A67C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004A680: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004A684: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004A688: sub.s       $f20, $f0, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8004A68C: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x8004A690: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8004A694: nop

    // 0x8004A698: bc1f        L_8004A6A8
    if (!c1cs) {
        // 0x8004A69C: nop
    
            goto L_8004A6A8;
    }
    // 0x8004A69C: nop

    // 0x8004A6A0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A6A4: nop

L_8004A6A8:
    // 0x8004A6A8: lw          $t4, -0x2540($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2540);
    // 0x8004A6AC: nop

    // 0x8004A6B0: beq         $t4, $zero, L_8004A6C0
    if (ctx->r12 == 0) {
        // 0x8004A6B4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004A6C0;
    }
    // 0x8004A6B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004A6B8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A6BC: nop

L_8004A6C0:
    // 0x8004A6C0: lb          $t5, 0x1D7($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004A6C4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8004A6C8: bne         $t5, $at, L_8004A6F8
    if (ctx->r13 != ctx->r1) {
        // 0x8004A6CC: nop
    
            goto L_8004A6F8;
    }
    // 0x8004A6CC: nop

    // 0x8004A6D0: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8004A6D4: nop

    // 0x8004A6D8: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8004A6DC: beq         $at, $zero, L_8004A6F0
    if (ctx->r1 == 0) {
        // 0x8004A6E0: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8004A6F0;
    }
    // 0x8004A6E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004A6E4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004A6E8: b           L_8004A6F8
    // 0x8004A6EC: nop

        goto L_8004A6F8;
    // 0x8004A6EC: nop

L_8004A6F0:
    // 0x8004A6F0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004A6F4: nop

L_8004A6F8:
    // 0x8004A6F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004A6FC: lwc1        $f10, -0x2514($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2514);
    // 0x8004A700: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004A704: mul.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8004A708: sub.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x8004A70C: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x8004A710: lbu         $t7, 0x1F5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1F5);
    // 0x8004A714: nop

    // 0x8004A718: beq         $t7, $zero, L_8004A894
    if (ctx->r15 == 0) {
        // 0x8004A71C: nop
    
            goto L_8004A894;
    }
    // 0x8004A71C: nop

    // 0x8004A720: lb          $t8, 0x1DB($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004A724: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004A728: bne         $t8, $zero, L_8004A894
    if (ctx->r24 != 0) {
        // 0x8004A72C: nop
    
            goto L_8004A894;
    }
    // 0x8004A72C: nop

    // 0x8004A730: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    // 0x8004A734: lh          $v1, 0x1A0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004A738: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x8004A73C: sb          $zero, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = 0;
    // 0x8004A740: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004A744: lh          $t3, 0x0($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X0);
    // 0x8004A748: andi        $t4, $v1, 0xFFFF
    ctx->r12 = ctx->r3 & 0XFFFF;
    // 0x8004A74C: subu        $v0, $t3, $t4
    ctx->r2 = SUB32(ctx->r11, ctx->r12);
    // 0x8004A750: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004A754: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8004A758: bne         $at, $zero, L_8004A768
    if (ctx->r1 != 0) {
        // 0x8004A75C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004A768;
    }
    // 0x8004A75C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004A760: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004A764: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004A768:
    // 0x8004A768: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8004A76C: beq         $at, $zero, L_8004A778
    if (ctx->r1 == 0) {
        // 0x8004A770: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004A778;
    }
    // 0x8004A770: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004A774: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004A778:
    // 0x8004A778: multu       $v0, $t5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004A77C: slti        $at, $v0, 0x400
    ctx->r1 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // 0x8004A780: mflo        $t6
    ctx->r14 = lo;
    // 0x8004A784: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8004A788: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8004A78C: beq         $at, $zero, L_8004A7A0
    if (ctx->r1 == 0) {
        // 0x8004A790: sh          $t8, 0x1A0($s0)
        MEM_H(0X1A0, ctx->r16) = ctx->r24;
            goto L_8004A7A0;
    }
    // 0x8004A790: sh          $t8, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r24;
    // 0x8004A794: slti        $at, $v0, -0x3FF
    ctx->r1 = SIGNED(ctx->r2) < -0X3FF ? 1 : 0;
    // 0x8004A798: beq         $at, $zero, L_8004A7B0
    if (ctx->r1 == 0) {
        // 0x8004A79C: nop
    
            goto L_8004A7B0;
    }
    // 0x8004A79C: nop

L_8004A7A0:
    // 0x8004A7A0: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8004A7A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A7A8: bne         $t9, $at, L_8004A844
    if (ctx->r25 != ctx->r1) {
        // 0x8004A7AC: nop
    
            goto L_8004A844;
    }
    // 0x8004A7AC: nop

L_8004A7B0:
    // 0x8004A7B0: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x8004A7B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A7B8: beq         $t3, $at, L_8004A7F4
    if (ctx->r11 == ctx->r1) {
        // 0x8004A7BC: addiu       $a0, $zero, 0x107
        ctx->r4 = ADD32(0, 0X107);
            goto L_8004A7F4;
    }
    // 0x8004A7BC: addiu       $a0, $zero, 0x107
    ctx->r4 = ADD32(0, 0X107);
    // 0x8004A7C0: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8004A7C4: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8004A7C8: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8004A7CC: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    // 0x8004A7D0: jal         0x80001EA8
    // 0x8004A7D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_19;
    // 0x8004A7D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_19:
    // 0x8004A7D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004A7DC: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x8004A7E0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8004A7E4: jal         0x800570F8
    // 0x8004A7E8: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_20;
    // 0x8004A7E8: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_20:
    // 0x8004A7EC: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A7F0: nop

L_8004A7F4:
    // 0x8004A7F4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x8004A7F8: jal         0x8000C8B4
    // 0x8004A7FC: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    normalise_time(rdram, ctx);
        goto after_21;
    // 0x8004A7FC: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_21:
    // 0x8004A800: lbu         $t5, 0x20C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X20C);
    // 0x8004A804: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A808: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8004A80C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x8004A810: beq         $t5, $zero, L_8004A828
    if (ctx->r13 == 0) {
        // 0x8004A814: sb          $t4, 0x203($s0)
        MEM_B(0X203, ctx->r16) = ctx->r12;
            goto L_8004A828;
    }
    // 0x8004A814: sb          $t4, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r12;
    // 0x8004A818: lb          $t6, 0x203($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X203);
    // 0x8004A81C: nop

    // 0x8004A820: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x8004A824: sb          $t7, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r15;
L_8004A828:
    // 0x8004A828: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004A82C: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    // 0x8004A830: jal         0x80072594
    // 0x8004A834: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_22;
    // 0x8004A834: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_22:
    // 0x8004A838: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A83C: b           L_8004A894
    // 0x8004A840: sb          $zero, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = 0;
        goto L_8004A894;
    // 0x8004A840: sb          $zero, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = 0;
L_8004A844:
    // 0x8004A844: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004A848: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x8004A84C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8004A850: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004A854: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8004A858: mul.d       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8004A85C: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004A860: nop

    // 0x8004A864: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8004A868: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8004A86C: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x8004A870: mul.d       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8004A874: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004A878: nop

    // 0x8004A87C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8004A880: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x8004A884: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x8004A888: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x8004A88C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8004A890: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
L_8004A894:
    // 0x8004A894: lb          $t8, 0x1DB($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004A898: nop

    // 0x8004A89C: beq         $t8, $zero, L_8004AAA4
    if (ctx->r24 == 0) {
        // 0x8004A8A0: nop
    
            goto L_8004AAA4;
    }
    // 0x8004A8A0: nop

    // 0x8004A8A4: lbu         $t9, 0x1F1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1F1);
    // 0x8004A8A8: lh          $a0, 0x162($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X162);
    // 0x8004A8AC: bne         $t9, $zero, L_8004A8B8
    if (ctx->r25 != 0) {
        // 0x8004A8B0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8004A8B8;
    }
    // 0x8004A8B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004A8B4: sb          $t3, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r11;
L_8004A8B8:
    // 0x8004A8B8: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004A8BC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8004A8C0: bne         $t4, $zero, L_8004A8D8
    if (ctx->r12 != 0) {
        // 0x8004A8C4: nop
    
            goto L_8004A8D8;
    }
    // 0x8004A8C4: nop

    // 0x8004A8C8: lbu         $t5, 0x1F1($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1F1);
    // 0x8004A8CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004A8D0: bne         $t5, $at, L_8004A968
    if (ctx->r13 != ctx->r1) {
        // 0x8004A8D4: lw          $t7, 0xF8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XF8);
            goto L_8004A968;
    }
    // 0x8004A8D4: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
L_8004A8D8:
    // 0x8004A8D8: sb          $t6, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r14;
    // 0x8004A8DC: lw          $v0, 0xF8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XF8);
    // 0x8004A8E0: lh          $t8, 0x162($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X162);
    // 0x8004A8E4: lh          $v1, 0x164($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X164);
    // 0x8004A8E8: sll         $t7, $v0, 11
    ctx->r15 = S32(ctx->r2 << 11);
    // 0x8004A8EC: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x8004A8F0: addu        $t3, $t7, $v1
    ctx->r11 = ADD32(ctx->r15, ctx->r3);
    // 0x8004A8F4: sh          $t9, 0x162($s0)
    MEM_H(0X162, ctx->r16) = ctx->r25;
    // 0x8004A8F8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8004A8FC: blez        $t3, L_8004A914
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8004A900: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_8004A914;
    }
    // 0x8004A900: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8004A904: bgtz        $t0, L_8004A918
    if (SIGNED(ctx->r8) > 0) {
        // 0x8004A908: addu        $t4, $v1, $v0
        ctx->r12 = ADD32(ctx->r3, ctx->r2);
            goto L_8004A918;
    }
    // 0x8004A908: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x8004A90C: b           L_8004A91C
    // 0x8004A910: sh          $zero, 0x164($s0)
    MEM_H(0X164, ctx->r16) = 0;
        goto L_8004A91C;
    // 0x8004A910: sh          $zero, 0x164($s0)
    MEM_H(0X164, ctx->r16) = 0;
L_8004A914:
    // 0x8004A914: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
L_8004A918:
    // 0x8004A918: sh          $t4, 0x164($s0)
    MEM_H(0X164, ctx->r16) = ctx->r12;
L_8004A91C:
    // 0x8004A91C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004A920: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8004A924: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004A928: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004A92C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8004A930: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x8004A934: nop

    // 0x8004A938: bc1f        L_8004A958
    if (!c1cs) {
        // 0x8004A93C: nop
    
            goto L_8004A958;
    }
    // 0x8004A93C: nop

    // 0x8004A940: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004A944: nop

    // 0x8004A948: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x8004A94C: bne         $at, $zero, L_8004A958
    if (ctx->r1 != 0) {
        // 0x8004A950: nop
    
            goto L_8004A958;
    }
    // 0x8004A950: nop

    // 0x8004A954: sb          $zero, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = 0;
L_8004A958:
    // 0x8004A958: lb          $v1, 0x1E2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004A95C: b           L_8004A97C
    // 0x8004A960: nop

        goto L_8004A97C;
    // 0x8004A960: nop

    // 0x8004A964: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
L_8004A968:
    // 0x8004A968: lh          $t6, 0x164($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X164);
    // 0x8004A96C: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x8004A970: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8004A974: lb          $v1, 0x1E2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004A978: sh          $t9, 0x164($s0)
    MEM_H(0X164, ctx->r16) = ctx->r25;
L_8004A97C:
    // 0x8004A97C: beq         $v1, $zero, L_8004AA08
    if (ctx->r3 == 0) {
        // 0x8004A980: slti        $at, $a0, 0x6001
        ctx->r1 = SIGNED(ctx->r4) < 0X6001 ? 1 : 0;
            goto L_8004AA08;
    }
    // 0x8004A980: slti        $at, $a0, 0x6001
    ctx->r1 = SIGNED(ctx->r4) < 0X6001 ? 1 : 0;
    // 0x8004A984: bne         $at, $zero, L_8004A9A0
    if (ctx->r1 != 0) {
        // 0x8004A988: slti        $at, $a0, -0x5FFF
        ctx->r1 = SIGNED(ctx->r4) < -0X5FFF ? 1 : 0;
            goto L_8004A9A0;
    }
    // 0x8004A988: slti        $at, $a0, -0x5FFF
    ctx->r1 = SIGNED(ctx->r4) < -0X5FFF ? 1 : 0;
    // 0x8004A98C: lh          $t3, 0x162($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X162);
    // 0x8004A990: nop

    // 0x8004A994: slti        $at, $t3, 0x6001
    ctx->r1 = SIGNED(ctx->r11) < 0X6001 ? 1 : 0;
    // 0x8004A998: bne         $at, $zero, L_8004A9D0
    if (ctx->r1 != 0) {
        // 0x8004A99C: slti        $at, $a0, -0x5FFF
        ctx->r1 = SIGNED(ctx->r4) < -0X5FFF ? 1 : 0;
            goto L_8004A9D0;
    }
    // 0x8004A99C: slti        $at, $a0, -0x5FFF
    ctx->r1 = SIGNED(ctx->r4) < -0X5FFF ? 1 : 0;
L_8004A9A0:
    // 0x8004A9A0: bne         $at, $zero, L_8004A9BC
    if (ctx->r1 != 0) {
        // 0x8004A9A4: nop
    
            goto L_8004A9BC;
    }
    // 0x8004A9A4: nop

    // 0x8004A9A8: lh          $t4, 0x162($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X162);
    // 0x8004A9AC: nop

    // 0x8004A9B0: slti        $at, $t4, -0x5FFF
    ctx->r1 = SIGNED(ctx->r12) < -0X5FFF ? 1 : 0;
    // 0x8004A9B4: bne         $at, $zero, L_8004A9D0
    if (ctx->r1 != 0) {
        // 0x8004A9B8: nop
    
            goto L_8004A9D0;
    }
    // 0x8004A9B8: nop

L_8004A9BC:
    // 0x8004A9BC: blez        $a0, L_8004AA08
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8004A9C0: nop
    
            goto L_8004AA08;
    }
    // 0x8004A9C0: nop

    // 0x8004A9C4: lh          $t5, 0x162($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X162);
    // 0x8004A9C8: nop

    // 0x8004A9CC: bgtz        $t5, L_8004AA08
    if (SIGNED(ctx->r13) > 0) {
        // 0x8004A9D0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004AA08;
    }
L_8004A9D0:
    // 0x8004A9D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004A9D4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8004A9D8: jal         0x80057088
    // 0x8004A9DC: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    racer_play_sound(rdram, ctx);
        goto after_23;
    // 0x8004A9DC: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_23:
    // 0x8004A9E0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8004A9E4: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004A9E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004A9EC: beq         $t7, $at, L_8004AA08
    if (ctx->r15 == ctx->r1) {
        // 0x8004A9F0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8004AA08;
    }
    // 0x8004A9F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004A9F4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8004A9F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004A9FC: lw          $t6, -0x2578($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2578);
    // 0x8004AA00: nop

    // 0x8004AA04: swc1        $f6, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f6.u32l;
L_8004AA08:
    // 0x8004AA08: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004AA0C: lw          $t8, -0x2558($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2558);
    // 0x8004AA10: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004AA14: ori         $at, $at, 0x5FFF
    ctx->r1 = ctx->r1 | 0X5FFF;
    // 0x8004AA18: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8004AA1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004AA20: sw          $t9, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r25;
    // 0x8004AA24: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AA28: lb          $t3, 0x1DB($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004AA2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004AA30: subu        $t4, $t3, $a0
    ctx->r12 = SUB32(ctx->r11, ctx->r4);
    // 0x8004AA34: sb          $t4, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r12;
    // 0x8004AA38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004AA3C: lb          $t5, 0x1DB($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004AA40: sb          $zero, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = 0;
    // 0x8004AA44: bgtz        $t5, L_8004AA54
    if (SIGNED(ctx->r13) > 0) {
        // 0x8004AA48: swc1        $f18, 0xB8($s0)
        MEM_W(0XB8, ctx->r16) = ctx->f18.u32l;
            goto L_8004AA54;
    }
    // 0x8004AA48: swc1        $f18, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f18.u32l;
    // 0x8004AA4C: sb          $zero, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = 0;
    // 0x8004AA50: sb          $zero, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = 0;
L_8004AA54:
    // 0x8004AA54: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8004AA58: ori         $t6, $zero, 0xD800
    ctx->r14 = 0 | 0XD800;
    // 0x8004AA5C: andi        $t7, $v1, 0xFFFF
    ctx->r15 = ctx->r3 & 0XFFFF;
    // 0x8004AA60: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x8004AA64: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004AA68: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004AA6C: bne         $at, $zero, L_8004AA7C
    if (ctx->r1 != 0) {
        // 0x8004AA70: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004AA7C;
    }
    // 0x8004AA70: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004AA74: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004AA78: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004AA7C:
    // 0x8004AA7C: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8004AA80: beq         $at, $zero, L_8004AA8C
    if (ctx->r1 == 0) {
        // 0x8004AA84: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004AA8C;
    }
    // 0x8004AA84: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004AA88: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004AA8C:
    // 0x8004AA8C: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AA90: mflo        $t8
    ctx->r24 = lo;
    // 0x8004AA94: sra         $t9, $t8, 4
    ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
    // 0x8004AA98: addu        $t3, $v1, $t9
    ctx->r11 = ADD32(ctx->r3, ctx->r25);
    // 0x8004AA9C: b           L_8004B36C
    // 0x8004AAA0: sh          $t3, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r11;
        goto L_8004B36C;
    // 0x8004AAA0: sh          $t3, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r11;
L_8004AAA4:
    // 0x8004AAA4: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004AAA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004AAAC: beq         $v0, $at, L_8004AAC0
    if (ctx->r2 == ctx->r1) {
        // 0x8004AAB0: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_8004AAC0;
    }
    // 0x8004AAB0: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8004AAB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004AAB8: bne         $v0, $at, L_8004AB7C
    if (ctx->r2 != ctx->r1) {
        // 0x8004AABC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004AB7C;
    }
    // 0x8004AABC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8004AAC0:
    // 0x8004AAC0: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AAC4: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8004AAC8: sll         $t4, $t4, 9
    ctx->r12 = S32(ctx->r12 << 9);
    // 0x8004AACC: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AAD0: lh          $v1, 0x1A4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AAD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004AAD8: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8004AADC: mflo        $t6
    ctx->r14 = lo;
    // 0x8004AAE0: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8004AAE4: sh          $t7, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r15;
    // 0x8004AAE8: lwc1        $f4, 0x6A98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6A98);
    // 0x8004AAEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004AAF0: bne         $v0, $at, L_8004AB38
    if (ctx->r2 != ctx->r1) {
        // 0x8004AAF4: swc1        $f4, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
            goto L_8004AB38;
    }
    // 0x8004AAF4: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
    // 0x8004AAF8: blez        $v1, L_8004AB04
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004AAFC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8004AB04;
    }
    // 0x8004AAFC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004AB00: sb          $t8, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r24;
L_8004AB04:
    // 0x8004AB04: bgez        $t0, L_8004B36C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004AB08: nop
    
            goto L_8004B36C;
    }
    // 0x8004AB08: nop

    // 0x8004AB0C: lh          $t9, 0x1A4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AB10: nop

    // 0x8004AB14: bltz        $t9, L_8004B36C
    if (SIGNED(ctx->r25) < 0) {
        // 0x8004AB18: nop
    
            goto L_8004B36C;
    }
    // 0x8004AB18: nop

    // 0x8004AB1C: lb          $t3, 0x1D4($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004AB20: nop

    // 0x8004AB24: beq         $t3, $zero, L_8004B36C
    if (ctx->r11 == 0) {
        // 0x8004AB28: nop
    
            goto L_8004B36C;
    }
    // 0x8004AB28: nop

    // 0x8004AB2C: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004AB30: b           L_8004B36C
    // 0x8004AB34: sh          $zero, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = 0;
        goto L_8004B36C;
    // 0x8004AB34: sh          $zero, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = 0;
L_8004AB38:
    // 0x8004AB38: bgez        $t0, L_8004AB44
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004AB3C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8004AB44;
    }
    // 0x8004AB3C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004AB40: sb          $t4, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r12;
L_8004AB44:
    // 0x8004AB44: blez        $t0, L_8004B36C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8004AB48: nop
    
            goto L_8004B36C;
    }
    // 0x8004AB48: nop

    // 0x8004AB4C: lh          $t5, 0x1A4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AB50: nop

    // 0x8004AB54: bgtz        $t5, L_8004B36C
    if (SIGNED(ctx->r13) > 0) {
        // 0x8004AB58: nop
    
            goto L_8004B36C;
    }
    // 0x8004AB58: nop

    // 0x8004AB5C: lb          $t6, 0x1D4($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004AB60: nop

    // 0x8004AB64: beq         $t6, $zero, L_8004B36C
    if (ctx->r14 == 0) {
        // 0x8004AB68: nop
    
            goto L_8004B36C;
    }
    // 0x8004AB68: nop

    // 0x8004AB6C: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004AB70: b           L_8004B36C
    // 0x8004AB74: sh          $zero, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = 0;
        goto L_8004B36C;
    // 0x8004AB74: sh          $zero, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = 0;
    // 0x8004AB78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8004AB7C:
    // 0x8004AB7C: beq         $v0, $at, L_8004AB8C
    if (ctx->r2 == ctx->r1) {
        // 0x8004AB80: addiu       $a1, $zero, -0x2
        ctx->r5 = ADD32(0, -0X2);
            goto L_8004AB8C;
    }
    // 0x8004AB80: addiu       $a1, $zero, -0x2
    ctx->r5 = ADD32(0, -0X2);
    // 0x8004AB84: bne         $a1, $v0, L_8004ADB4
    if (ctx->r5 != ctx->r2) {
        // 0x8004AB88: nop
    
            goto L_8004ADB4;
    }
    // 0x8004AB88: nop

L_8004AB8C:
    // 0x8004AB8C: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8004AB90: lb          $t7, 0x1D5($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D5);
    // 0x8004AB94: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004AB98: bne         $t7, $zero, L_8004ABC0
    if (ctx->r15 != 0) {
        // 0x8004AB9C: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_8004ABC0;
    }
    // 0x8004AB9C: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8004ABA0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8004ABA4: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8004ABA8: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8004ABAC: sll         $t8, $t8, 7
    ctx->r24 = S32(ctx->r24 << 7);
    // 0x8004ABB0: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004ABB4: mflo        $t3
    ctx->r11 = lo;
    // 0x8004ABB8: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8004ABBC: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
L_8004ABC0:
    // 0x8004ABC0: lw          $t5, -0x2558($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2558);
    // 0x8004ABC4: nop

    // 0x8004ABC8: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x8004ABCC: bne         $t6, $zero, L_8004ABD8
    if (ctx->r14 != 0) {
        // 0x8004ABD0: nop
    
            goto L_8004ABD8;
    }
    // 0x8004ABD0: nop

    // 0x8004ABD4: sb          $zero, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = 0;
L_8004ABD8:
    // 0x8004ABD8: lb          $v0, 0x1D5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D5);
    // 0x8004ABDC: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x8004ABE0: blez        $v0, L_8004ABF0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004ABE4: subu        $t8, $v0, $t7
        ctx->r24 = SUB32(ctx->r2, ctx->r15);
            goto L_8004ABF0;
    }
    // 0x8004ABE4: subu        $t8, $v0, $t7
    ctx->r24 = SUB32(ctx->r2, ctx->r15);
    // 0x8004ABE8: b           L_8004ABF4
    // 0x8004ABEC: sb          $t8, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r24;
        goto L_8004ABF4;
    // 0x8004ABEC: sb          $t8, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r24;
L_8004ABF0:
    // 0x8004ABF0: sb          $zero, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = 0;
L_8004ABF4:
    // 0x8004ABF4: lh          $v1, 0x1A4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004ABF8: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8004ABFC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004AC00: multu       $v1, $t9
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AC04: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8004AC08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004AC0C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004AC10: mflo        $t3
    ctx->r11 = lo;
    // 0x8004AC14: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8004AC18: subu        $t5, $v1, $t4
    ctx->r13 = SUB32(ctx->r3, ctx->r12);
    // 0x8004AC1C: sh          $t5, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r13;
    // 0x8004AC20: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8004AC24: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004AC28: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004AC2C: nop

    // 0x8004AC30: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004AC34: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x8004AC38: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004AC3C: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004AC40: nop

    // 0x8004AC44: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8004AC48: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x8004AC4C: lb          $t6, 0x1E0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004AC50: nop

    // 0x8004AC54: bne         $t6, $at, L_8004AD08
    if (ctx->r14 != ctx->r1) {
        // 0x8004AC58: nop
    
            goto L_8004AD08;
    }
    // 0x8004AC58: nop

    // 0x8004AC5C: blez        $t0, L_8004AC68
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8004AC60: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8004AC68;
    }
    // 0x8004AC60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004AC64: sb          $t7, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r15;
L_8004AC68:
    // 0x8004AC68: bgez        $t0, L_8004ACD0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004AC6C: slti        $at, $t0, 0x4001
        ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
            goto L_8004ACD0;
    }
    // 0x8004AC6C: slti        $at, $t0, 0x4001
    ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
    // 0x8004AC70: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x8004AC74: nop

    // 0x8004AC78: bltz        $t8, L_8004ACD0
    if (SIGNED(ctx->r24) < 0) {
        // 0x8004AC7C: slti        $at, $t0, 0x4001
        ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
            goto L_8004ACD0;
    }
    // 0x8004AC7C: slti        $at, $t0, 0x4001
    ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
    // 0x8004AC80: lb          $t9, 0x1D4($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004AC84: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8004AC88: beq         $t9, $zero, L_8004ACD0
    if (ctx->r25 == 0) {
        // 0x8004AC8C: slti        $at, $t0, 0x4001
        ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
            goto L_8004ACD0;
    }
    // 0x8004AC8C: slti        $at, $t0, 0x4001
    ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
    // 0x8004AC90: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004AC94: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x8004AC98: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    // 0x8004AC9C: jal         0x8000C8B4
    // 0x8004ACA0: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    normalise_time(rdram, ctx);
        goto after_24;
    // 0x8004ACA0: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    after_24:
    // 0x8004ACA4: lbu         $t3, 0x20C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20C);
    // 0x8004ACA8: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8004ACAC: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004ACB0: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x8004ACB4: beq         $t3, $zero, L_8004ACCC
    if (ctx->r11 == 0) {
        // 0x8004ACB8: sb          $zero, 0x203($s0)
        MEM_B(0X203, ctx->r16) = 0;
            goto L_8004ACCC;
    }
    // 0x8004ACB8: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
    // 0x8004ACBC: lb          $t4, 0x203($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X203);
    // 0x8004ACC0: nop

    // 0x8004ACC4: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x8004ACC8: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
L_8004ACCC:
    // 0x8004ACCC: slti        $at, $t0, 0x4001
    ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
L_8004ACD0:
    // 0x8004ACD0: bne         $at, $zero, L_8004B36C
    if (ctx->r1 != 0) {
        // 0x8004ACD4: nop
    
            goto L_8004B36C;
    }
    // 0x8004ACD4: nop

    // 0x8004ACD8: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x8004ACDC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004ACE0: slti        $at, $t6, -0x4000
    ctx->r1 = SIGNED(ctx->r14) < -0X4000 ? 1 : 0;
    // 0x8004ACE4: beq         $at, $zero, L_8004B36C
    if (ctx->r1 == 0) {
        // 0x8004ACE8: nop
    
            goto L_8004B36C;
    }
    // 0x8004ACE8: nop

    // 0x8004ACEC: lw          $t7, -0x2558($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2558);
    // 0x8004ACF0: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8004ACF4: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8004ACF8: beq         $t8, $zero, L_8004B36C
    if (ctx->r24 == 0) {
        // 0x8004ACFC: nop
    
            goto L_8004B36C;
    }
    // 0x8004ACFC: nop

    // 0x8004AD00: b           L_8004B36C
    // 0x8004AD04: sb          $t9, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r25;
        goto L_8004B36C;
    // 0x8004AD04: sb          $t9, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r25;
L_8004AD08:
    // 0x8004AD08: bgez        $t0, L_8004AD14
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004AD0C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8004AD14;
    }
    // 0x8004AD0C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004AD10: sb          $t3, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r11;
L_8004AD14:
    // 0x8004AD14: blez        $t0, L_8004AD7C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8004AD18: slti        $at, $t0, -0x4000
        ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
            goto L_8004AD7C;
    }
    // 0x8004AD18: slti        $at, $t0, -0x4000
    ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
    // 0x8004AD1C: lh          $t4, 0x2($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2);
    // 0x8004AD20: nop

    // 0x8004AD24: bgtz        $t4, L_8004AD7C
    if (SIGNED(ctx->r12) > 0) {
        // 0x8004AD28: slti        $at, $t0, -0x4000
        ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
            goto L_8004AD7C;
    }
    // 0x8004AD28: slti        $at, $t0, -0x4000
    ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
    // 0x8004AD2C: lb          $t5, 0x1D4($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D4);
    // 0x8004AD30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8004AD34: beq         $t5, $zero, L_8004AD7C
    if (ctx->r13 == 0) {
        // 0x8004AD38: slti        $at, $t0, -0x4000
        ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
            goto L_8004AD7C;
    }
    // 0x8004AD38: slti        $at, $t0, -0x4000
    ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
    // 0x8004AD3C: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x8004AD40: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x8004AD44: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    // 0x8004AD48: jal         0x8000C8B4
    // 0x8004AD4C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    normalise_time(rdram, ctx);
        goto after_25;
    // 0x8004AD4C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    after_25:
    // 0x8004AD50: lbu         $t6, 0x20C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X20C);
    // 0x8004AD54: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8004AD58: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004AD5C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x8004AD60: beq         $t6, $zero, L_8004AD78
    if (ctx->r14 == 0) {
        // 0x8004AD64: sb          $zero, 0x203($s0)
        MEM_B(0X203, ctx->r16) = 0;
            goto L_8004AD78;
    }
    // 0x8004AD64: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
    // 0x8004AD68: lb          $t7, 0x203($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X203);
    // 0x8004AD6C: nop

    // 0x8004AD70: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x8004AD74: sb          $t8, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r24;
L_8004AD78:
    // 0x8004AD78: slti        $at, $t0, -0x4000
    ctx->r1 = SIGNED(ctx->r8) < -0X4000 ? 1 : 0;
L_8004AD7C:
    // 0x8004AD7C: beq         $at, $zero, L_8004B36C
    if (ctx->r1 == 0) {
        // 0x8004AD80: nop
    
            goto L_8004B36C;
    }
    // 0x8004AD80: nop

    // 0x8004AD84: lh          $t9, 0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2);
    // 0x8004AD88: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004AD8C: slti        $at, $t9, 0x4001
    ctx->r1 = SIGNED(ctx->r25) < 0X4001 ? 1 : 0;
    // 0x8004AD90: bne         $at, $zero, L_8004B36C
    if (ctx->r1 != 0) {
        // 0x8004AD94: nop
    
            goto L_8004B36C;
    }
    // 0x8004AD94: nop

    // 0x8004AD98: lw          $t3, -0x2558($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2558);
    // 0x8004AD9C: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x8004ADA0: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x8004ADA4: beq         $t4, $zero, L_8004B36C
    if (ctx->r12 == 0) {
        // 0x8004ADA8: nop
    
            goto L_8004B36C;
    }
    // 0x8004ADA8: nop

    // 0x8004ADAC: b           L_8004B36C
    // 0x8004ADB0: sb          $t5, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r13;
        goto L_8004B36C;
    // 0x8004ADB0: sb          $t5, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r13;
L_8004ADB4:
    // 0x8004ADB4: lb          $a0, 0x1E1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1E1);
    // 0x8004ADB8: sb          $zero, 0xA1($sp)
    MEM_B(0XA1, ctx->r29) = 0;
    // 0x8004ADBC: lb          $v1, 0x1E2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004ADC0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004ADC4: beq         $v1, $zero, L_8004ADF4
    if (ctx->r3 == 0) {
        // 0x8004ADC8: addiu       $at, $zero, -0x11
        ctx->r1 = ADD32(0, -0X11);
            goto L_8004ADF4;
    }
    // 0x8004ADC8: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8004ADCC: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x8004ADD0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004ADD4: andi        $t6, $v0, 0x10
    ctx->r14 = ctx->r2 & 0X10;
    // 0x8004ADD8: beq         $t6, $zero, L_8004ADE4
    if (ctx->r14 == 0) {
        // 0x8004ADDC: and         $t8, $v0, $at
        ctx->r24 = ctx->r2 & ctx->r1;
            goto L_8004ADE4;
    }
    // 0x8004ADDC: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x8004ADE0: sb          $t7, 0xA1($sp)
    MEM_B(0XA1, ctx->r29) = ctx->r15;
L_8004ADE4:
    // 0x8004ADE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004ADE8: sw          $t8, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r24;
    // 0x8004ADEC: lb          $v1, 0x1E2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004ADF0: nop

L_8004ADF4:
    // 0x8004ADF4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8004ADF8: beq         $at, $zero, L_8004B008
    if (ctx->r1 == 0) {
        // 0x8004ADFC: nop
    
            goto L_8004B008;
    }
    // 0x8004ADFC: nop

    // 0x8004AE00: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8004AE04: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8004AE08: slti        $at, $v1, 0x3001
    ctx->r1 = SIGNED(ctx->r3) < 0X3001 ? 1 : 0;
    // 0x8004AE0C: bne         $at, $zero, L_8004AE2C
    if (ctx->r1 != 0) {
        // 0x8004AE10: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004AE2C;
    }
    // 0x8004AE10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004AE14: addiu       $a0, $v1, -0x3000
    ctx->r4 = ADD32(ctx->r3, -0X3000);
    // 0x8004AE18: slti        $at, $a0, 0x1001
    ctx->r1 = SIGNED(ctx->r4) < 0X1001 ? 1 : 0;
    // 0x8004AE1C: bne         $at, $zero, L_8004AE50
    if (ctx->r1 != 0) {
        // 0x8004AE20: nop
    
            goto L_8004AE50;
    }
    // 0x8004AE20: nop

    // 0x8004AE24: b           L_8004AE50
    // 0x8004AE28: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
        goto L_8004AE50;
    // 0x8004AE28: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
L_8004AE2C:
    // 0x8004AE2C: slti        $at, $v1, -0x3000
    ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
    // 0x8004AE30: beq         $at, $zero, L_8004AE50
    if (ctx->r1 == 0) {
        // 0x8004AE34: nop
    
            goto L_8004AE50;
    }
    // 0x8004AE34: nop

    // 0x8004AE38: addiu       $a0, $v1, 0x3000
    ctx->r4 = ADD32(ctx->r3, 0X3000);
    // 0x8004AE3C: slti        $at, $a0, -0x1000
    ctx->r1 = SIGNED(ctx->r4) < -0X1000 ? 1 : 0;
    // 0x8004AE40: beq         $at, $zero, L_8004AE50
    if (ctx->r1 == 0) {
        // 0x8004AE44: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_8004AE50;
    }
    // 0x8004AE44: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8004AE48: addiu       $a0, $zero, -0x1000
    ctx->r4 = ADD32(0, -0X1000);
    // 0x8004AE4C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_8004AE50:
    // 0x8004AE50: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8004AE54: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x8004AE58: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004AE5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004AE60: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004AE64: div.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004AE68: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004AE6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004AE70: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004AE74: lw          $t3, -0x2558($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2558);
    // 0x8004AE78: nop

    // 0x8004AE7C: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x8004AE80: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8004AE84: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8004AE88: sub.d       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f4.d - ctx->f18.d;
    // 0x8004AE8C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004AE90: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x8004AE94: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8004AE98: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8004AE9C: nop

    // 0x8004AEA0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8004AEA4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004AEA8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004AEAC: nop

    // 0x8004AEB0: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8004AEB4: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8004AEB8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8004AEBC: beq         $t4, $zero, L_8004AEF4
    if (ctx->r12 == 0) {
        // 0x8004AEC0: lw          $t7, 0xF8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XF8);
            goto L_8004AEF4;
    }
    // 0x8004AEC0: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AEC4: lw          $t5, 0x74($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X74);
    // 0x8004AEC8: sll         $t7, $t0, 4
    ctx->r15 = S32(ctx->r8 << 4);
    // 0x8004AECC: ori         $t6, $t5, 0xC0
    ctx->r14 = ctx->r13 | 0XC0;
    // 0x8004AED0: sw          $t6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r14;
    // 0x8004AED4: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AED8: lh          $t4, 0x1A4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AEDC: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AEE0: mflo        $t9
    ctx->r25 = lo;
    // 0x8004AEE4: sra         $t3, $t9, 1
    ctx->r11 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8004AEE8: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x8004AEEC: sh          $t5, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r13;
    // 0x8004AEF0: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
L_8004AEF4:
    // 0x8004AEF4: lh          $t6, 0x1A4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AEF8: multu       $t0, $t7
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AEFC: mflo        $t8
    ctx->r24 = lo;
    // 0x8004AF00: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004AF04: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8004AF08: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8004AF0C: sra         $t4, $t9, 1
    ctx->r12 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8004AF10: subu        $t3, $t6, $t4
    ctx->r11 = SUB32(ctx->r14, ctx->r12);
    // 0x8004AF14: sh          $t3, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r11;
    // 0x8004AF18: lh          $v1, 0x1A4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AF1C: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AF20: lbu         $t6, 0x1F5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1F5);
    // 0x8004AF24: multu       $v1, $t5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AF28: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004AF2C: mflo        $t7
    ctx->r15 = lo;
    // 0x8004AF30: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x8004AF34: subu        $t9, $v1, $t8
    ctx->r25 = SUB32(ctx->r3, ctx->r24);
    // 0x8004AF38: bne         $t6, $zero, L_8004B094
    if (ctx->r14 != 0) {
        // 0x8004AF3C: sh          $t9, 0x1A4($s0)
        MEM_H(0X1A4, ctx->r16) = ctx->r25;
            goto L_8004B094;
    }
    // 0x8004AF3C: sh          $t9, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r25;
    // 0x8004AF40: lw          $t4, -0x2524($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2524);
    // 0x8004AF44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004AF48: beq         $t4, $at, L_8004AFE0
    if (ctx->r12 == ctx->r1) {
        // 0x8004AF4C: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8004AFE0;
    }
    // 0x8004AF4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004AF50: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8004AF54: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004AF58: bne         $t3, $zero, L_8004AFE0
    if (ctx->r11 != 0) {
        // 0x8004AF5C: nop
    
            goto L_8004AFE0;
    }
    // 0x8004AF5C: nop

    // 0x8004AF60: lh          $t0, 0x1A4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004AF64: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x8004AF68: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x8004AF6C: sra         $t5, $t0, 6
    ctx->r13 = S32(SIGNED(ctx->r8) >> 6);
    // 0x8004AF70: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    // 0x8004AF74: beq         $t7, $zero, L_8004AF8C
    if (ctx->r15 == 0) {
        // 0x8004AF78: or          $t0, $t5, $zero
        ctx->r8 = ctx->r13 | 0;
            goto L_8004AF8C;
    }
    // 0x8004AF78: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8004AF7C: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x8004AF80: beq         $t8, $zero, L_8004AF8C
    if (ctx->r24 == 0) {
        // 0x8004AF84: nop
    
            goto L_8004AF8C;
    }
    // 0x8004AF84: nop

    // 0x8004AF88: sll         $t0, $t5, 1
    ctx->r8 = S32(ctx->r13 << 1);
L_8004AF8C:
    // 0x8004AF8C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8004AF90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004AF94: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004AF98: lwc1        $f8, -0x2510($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2510);
    // 0x8004AF9C: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AFA0: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8004AFA4: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004AFA8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8004AFAC: nop

    // 0x8004AFB0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8004AFB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004AFB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004AFBC: nop

    // 0x8004AFC0: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8004AFC4: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8004AFC8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8004AFCC: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AFD0: mflo        $t7
    ctx->r15 = lo;
    // 0x8004AFD4: subu        $t8, $t4, $t7
    ctx->r24 = SUB32(ctx->r12, ctx->r15);
    // 0x8004AFD8: b           L_8004B094
    // 0x8004AFDC: sh          $t8, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r24;
        goto L_8004B094;
    // 0x8004AFDC: sh          $t8, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r24;
L_8004AFE0:
    // 0x8004AFE0: lw          $t0, -0x254C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X254C);
    // 0x8004AFE4: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8004AFE8: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8004AFEC: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004AFF0: lh          $t6, 0x1A0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004AFF4: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x8004AFF8: mflo        $t4
    ctx->r12 = lo;
    // 0x8004AFFC: subu        $t7, $t6, $t4
    ctx->r15 = SUB32(ctx->r14, ctx->r12);
    // 0x8004B000: b           L_8004B094
    // 0x8004B004: sh          $t7, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r15;
        goto L_8004B094;
    // 0x8004B004: sh          $t7, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r15;
L_8004B008:
    // 0x8004B008: lh          $v1, 0x1A4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004B00C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004B010: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x8004B014: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8004B018: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004B01C: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B020: bne         $at, $zero, L_8004B034
    if (ctx->r1 != 0) {
        // 0x8004B024: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_8004B034;
    }
    // 0x8004B024: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8004B028: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004B02C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004B030: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004B034:
    // 0x8004B034: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8004B038: beq         $at, $zero, L_8004B044
    if (ctx->r1 == 0) {
        // 0x8004B03C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004B044;
    }
    // 0x8004B03C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004B040: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8004B044:
    // 0x8004B044: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B048: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004B04C: mflo        $t9
    ctx->r25 = lo;
    // 0x8004B050: sra         $t3, $t9, 4
    ctx->r11 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8004B054: addu        $t5, $v1, $t3
    ctx->r13 = ADD32(ctx->r3, ctx->r11);
    // 0x8004B058: sh          $t5, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r13;
    // 0x8004B05C: lw          $t6, -0x2558($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2558);
    // 0x8004B060: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B064: andi        $t4, $t6, 0x10
    ctx->r12 = ctx->r14 & 0X10;
    // 0x8004B068: beq         $t4, $zero, L_8004B080
    if (ctx->r12 == 0) {
        // 0x8004B06C: nop
    
            goto L_8004B080;
    }
    // 0x8004B06C: nop

    // 0x8004B070: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8004B074: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8004B078: b           L_8004B080
    // 0x8004B07C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
        goto L_8004B080;
    // 0x8004B07C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
L_8004B080:
    // 0x8004B080: multu       $t0, $t8
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B084: lh          $t7, 0x1A0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004B088: mflo        $t3
    ctx->r11 = lo;
    // 0x8004B08C: subu        $t5, $t7, $t3
    ctx->r13 = SUB32(ctx->r15, ctx->r11);
    // 0x8004B090: sh          $t5, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r13;
L_8004B094:
    // 0x8004B094: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004B098: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x8004B09C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004B0A0: andi        $t6, $v0, 0x10
    ctx->r14 = ctx->r2 & 0X10;
    // 0x8004B0A4: beq         $t6, $zero, L_8004B0CC
    if (ctx->r14 == 0) {
        // 0x8004B0A8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8004B0CC;
    }
    // 0x8004B0A8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8004B0AC: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004B0B0: nop

    // 0x8004B0B4: beq         $t4, $zero, L_8004B0CC
    if (ctx->r12 == 0) {
        // 0x8004B0B8: nop
    
            goto L_8004B0CC;
    }
    // 0x8004B0B8: nop

    // 0x8004B0BC: lbu         $t8, 0x1F5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1F5);
    // 0x8004B0C0: nop

    // 0x8004B0C4: beq         $t8, $zero, L_8004B148
    if (ctx->r24 == 0) {
        // 0x8004B0C8: nop
    
            goto L_8004B148;
    }
    // 0x8004B0C8: nop

L_8004B0CC:
    // 0x8004B0CC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8004B0D0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B0D4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004B0D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B0DC: lwc1        $f5, 0x6AA0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6AA0);
    // 0x8004B0E0: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B0E4: lwc1        $f4, 0x6AA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6AA4);
    // 0x8004B0E8: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B0EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004B0F0: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8004B0F4: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8004B0F8: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004B0FC: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8004B100: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B104: mul.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8004B108: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004B10C: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x8004B110: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004B114: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B118: mul.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8004B11C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004B120: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x8004B124: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004B128: nop

    // 0x8004B12C: mul.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8004B130: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004B134: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x8004B138: lw          $v0, -0x2558($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2558);
    // 0x8004B13C: nop

    // 0x8004B140: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
    // 0x8004B144: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8004B148:
    // 0x8004B148: lw          $t7, -0x2524($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2524);
    // 0x8004B14C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8004B150: lw          $t0, -0x2548($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2548);
    // 0x8004B154: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004B158: beq         $t7, $at, L_8004B178
    if (ctx->r15 == ctx->r1) {
        // 0x8004B15C: nop
    
            goto L_8004B178;
    }
    // 0x8004B15C: nop

    // 0x8004B160: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8004B164: nop

    // 0x8004B168: bne         $t3, $zero, L_8004B178
    if (ctx->r11 != 0) {
        // 0x8004B16C: nop
    
            goto L_8004B178;
    }
    // 0x8004B16C: nop

    // 0x8004B170: lb          $t0, 0x1E8($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E8);
    // 0x8004B174: nop

L_8004B178:
    // 0x8004B178: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B17C: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8004B180: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004B184: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004B188: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8004B18C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8004B190: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8004B194: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004B198: bc1f        L_8004B1AC
    if (!c1cs) {
        // 0x8004B19C: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8004B1AC;
    }
    // 0x8004B19C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004B1A0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004B1A4: nop

    // 0x8004B1A8: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_8004B1AC:
    // 0x8004B1AC: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x8004B1B0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004B1B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004B1B8: c.lt.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d < ctx->f0.d;
    // 0x8004B1BC: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B1C0: bc1f        L_8004B1D4
    if (!c1cs) {
        // 0x8004B1C4: lui         $at, 0x4160
        ctx->r1 = S32(0X4160 << 16);
            goto L_8004B1D4;
    }
    // 0x8004B1C4: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8004B1C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004B1CC: nop

    // 0x8004B1D0: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_8004B1D4:
    // 0x8004B1D4: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x8004B1D8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004B1DC: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8004B1E0: div.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f4.d);
    // 0x8004B1E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004B1E8: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B1EC: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8004B1F0: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8004B1F4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8004B1F8: nop

    // 0x8004B1FC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8004B200: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004B204: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004B208: nop

    // 0x8004B20C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8004B210: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8004B214: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8004B218: bne         $v0, $zero, L_8004B26C
    if (ctx->r2 != 0) {
        // 0x8004B21C: nop
    
            goto L_8004B26C;
    }
    // 0x8004B21C: nop

    // 0x8004B220: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8004B224: sra         $t6, $t0, 1
    ctx->r14 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8004B228: multu       $v1, $t4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B22C: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8004B230: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8004B234: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8004B238: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x8004B23C: mflo        $t8
    ctx->r24 = lo;
    // 0x8004B240: sra         $t9, $t8, 4
    ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
    // 0x8004B244: subu        $t7, $v1, $t9
    ctx->r15 = SUB32(ctx->r3, ctx->r25);
    // 0x8004B248: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
    // 0x8004B24C: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B250: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x8004B254: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B258: mflo        $t6
    ctx->r14 = lo;
    // 0x8004B25C: sra         $t4, $t6, 1
    ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8004B260: subu        $t9, $t8, $t4
    ctx->r25 = SUB32(ctx->r24, ctx->r12);
    // 0x8004B264: b           L_8004B2B0
    // 0x8004B268: sh          $t9, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r25;
        goto L_8004B2B0;
    // 0x8004B268: sh          $t9, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r25;
L_8004B26C:
    // 0x8004B26C: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8004B270: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8004B274: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B278: sll         $t4, $t7, 4
    ctx->r12 = S32(ctx->r15 << 4);
    // 0x8004B27C: subu        $t4, $t4, $t7
    ctx->r12 = SUB32(ctx->r12, ctx->r15);
    // 0x8004B280: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8004B284: mflo        $t5
    ctx->r13 = lo;
    // 0x8004B288: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8004B28C: subu        $t8, $v1, $t6
    ctx->r24 = SUB32(ctx->r3, ctx->r14);
    // 0x8004B290: sh          $t8, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r24;
    // 0x8004B294: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B298: lh          $t5, 0x2($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2);
    // 0x8004B29C: multu       $t4, $t9
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004B2A0: mflo        $t7
    ctx->r15 = lo;
    // 0x8004B2A4: sra         $t3, $t7, 1
    ctx->r11 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8004B2A8: subu        $t6, $t5, $t3
    ctx->r14 = SUB32(ctx->r13, ctx->r11);
    // 0x8004B2AC: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
L_8004B2B0:
    // 0x8004B2B0: lb          $t8, 0x1EC($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1EC);
    // 0x8004B2B4: nop

    // 0x8004B2B8: beq         $t8, $zero, L_8004B36C
    if (ctx->r24 == 0) {
        // 0x8004B2BC: nop
    
            goto L_8004B36C;
    }
    // 0x8004B2BC: nop

    // 0x8004B2C0: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004B2C4: sb          $zero, 0x1EC($s0)
    MEM_B(0X1EC, ctx->r16) = 0;
    // 0x8004B2C8: bne         $t4, $zero, L_8004B36C
    if (ctx->r12 != 0) {
        // 0x8004B2CC: lui         $at, 0xC01A
        ctx->r1 = S32(0XC01A << 16);
            goto L_8004B36C;
    }
    // 0x8004B2CC: lui         $at, 0xC01A
    ctx->r1 = S32(0XC01A << 16);
    // 0x8004B2D0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B2D4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004B2D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004B2DC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8004B2E0: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8004B2E4: nop

    // 0x8004B2E8: bc1f        L_8004B36C
    if (!c1cs) {
        // 0x8004B2EC: nop
    
            goto L_8004B36C;
    }
    // 0x8004B2EC: nop

    // 0x8004B2F0: lb          $t9, 0x1E5($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E5);
    // 0x8004B2F4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004B2F8: bne         $t9, $zero, L_8004B36C
    if (ctx->r25 != 0) {
        // 0x8004B2FC: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8004B36C;
    }
    // 0x8004B2FC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004B300: lw          $v0, -0x254C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X254C);
    // 0x8004B304: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8004B308: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x8004B30C: bne         $at, $zero, L_8004B324
    if (ctx->r1 != 0) {
        // 0x8004B310: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8004B324;
    }
    // 0x8004B310: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8004B314: sb          $t7, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r15;
    // 0x8004B318: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004B31C: lw          $v0, -0x254C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X254C);
    // 0x8004B320: nop

L_8004B324:
    // 0x8004B324: slti        $at, $v0, -0x28
    ctx->r1 = SIGNED(ctx->r2) < -0X28 ? 1 : 0;
    // 0x8004B328: beq         $at, $zero, L_8004B334
    if (ctx->r1 == 0) {
        // 0x8004B32C: nop
    
            goto L_8004B334;
    }
    // 0x8004B32C: nop

    // 0x8004B330: sb          $t5, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r13;
L_8004B334:
    // 0x8004B334: lw          $t3, -0x2548($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2548);
    // 0x8004B338: nop

    // 0x8004B33C: slti        $at, $t3, 0x29
    ctx->r1 = SIGNED(ctx->r11) < 0X29 ? 1 : 0;
    // 0x8004B340: bne         $at, $zero, L_8004B350
    if (ctx->r1 != 0) {
        // 0x8004B344: nop
    
            goto L_8004B350;
    }
    // 0x8004B344: nop

    // 0x8004B348: b           L_8004B364
    // 0x8004B34C: sb          $a1, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r5;
        goto L_8004B364;
    // 0x8004B34C: sb          $a1, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r5;
L_8004B350:
    // 0x8004B350: lb          $t6, 0x1E0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004B354: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8004B358: bne         $t6, $zero, L_8004B364
    if (ctx->r14 != 0) {
        // 0x8004B35C: nop
    
            goto L_8004B364;
    }
    // 0x8004B35C: nop

    // 0x8004B360: sb          $t8, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r24;
L_8004B364:
    // 0x8004B364: sb          $zero, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = 0;
    // 0x8004B368: sb          $zero, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = 0;
L_8004B36C:
    // 0x8004B36C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004B370: lw          $t4, -0x2524($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2524);
    // 0x8004B374: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004B378: beq         $t4, $at, L_8004B3B8
    if (ctx->r12 == ctx->r1) {
        // 0x8004B37C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004B3B8;
    }
    // 0x8004B37C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004B380: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8004B384: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B388: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B38C: nop

    // 0x8004B390: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8004B394: nop

    // 0x8004B398: bc1f        L_8004B3BC
    if (!c1cs) {
        // 0x8004B39C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8004B3BC;
    }
    // 0x8004B39C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004B3A0: lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X74);
    // 0x8004B3A4: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x8004B3A8: andi        $t9, $v0, 0xC0
    ctx->r25 = ctx->r2 & 0XC0;
    // 0x8004B3AC: beq         $t9, $at, L_8004B3B8
    if (ctx->r25 == ctx->r1) {
        // 0x8004B3B0: ori         $t7, $v0, 0xC
        ctx->r15 = ctx->r2 | 0XC;
            goto L_8004B3B8;
    }
    // 0x8004B3B0: ori         $t7, $v0, 0xC
    ctx->r15 = ctx->r2 | 0XC;
    // 0x8004B3B4: sw          $t7, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r15;
L_8004B3B8:
    // 0x8004B3B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
L_8004B3BC:
    // 0x8004B3BC: jal         0x80057260
    // 0x8004B3C0: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    handle_racer_top_speed(rdram, ctx);
        goto after_26;
    // 0x8004B3C0: swc1        $f14, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f14.u32l;
    after_26:
    // 0x8004B3C4: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8004B3C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B3CC: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8004B3D0: lwc1        $f9, 0x6AA8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6AA8);
    // 0x8004B3D4: lwc1        $f8, 0x6AAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6AAC);
    // 0x8004B3D8: lb          $v0, 0x1D3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004B3DC: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x8004B3E0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8004B3E4: blez        $v0, L_8004B430
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004B3E8: cvt.s.d     $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
            goto L_8004B430;
    }
    // 0x8004B3E8: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8004B3EC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004B3F0: lw          $t5, -0x2540($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2540);
    // 0x8004B3F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004B3F8: bne         $t5, $zero, L_8004B434
    if (ctx->r13 != 0) {
        // 0x8004B3FC: nop
    
            goto L_8004B434;
    }
    // 0x8004B3FC: nop

    // 0x8004B400: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004B404: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004B408: swc1        $f18, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f18.u32l;
    // 0x8004B40C: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8004B410: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004B414: subu        $t6, $v0, $t3
    ctx->r14 = SUB32(ctx->r2, ctx->r11);
    // 0x8004B418: sb          $t6, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r14;
    // 0x8004B41C: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x8004B420: nop

    // 0x8004B424: ori         $t4, $t8, 0xC0
    ctx->r12 = ctx->r24 | 0XC0;
    // 0x8004B428: b           L_8004B434
    // 0x8004B42C: sw          $t4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r12;
        goto L_8004B434;
    // 0x8004B42C: sw          $t4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r12;
L_8004B430:
    // 0x8004B430: sb          $zero, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = 0;
L_8004B434:
    // 0x8004B434: lbu         $t9, 0x1F5($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1F5);
    // 0x8004B438: nop

    // 0x8004B43C: bne         $t9, $zero, L_8004B8E0
    if (ctx->r25 != 0) {
        // 0x8004B440: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8004B8E0;
    }
    // 0x8004B440: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004B444: lw          $t7, -0x2540($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2540);
    // 0x8004B448: nop

    // 0x8004B44C: bne         $t7, $zero, L_8004B8E0
    if (ctx->r15 != 0) {
        // 0x8004B450: nop
    
            goto L_8004B8E0;
    }
    // 0x8004B450: nop

    // 0x8004B454: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004B458: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8004B45C: bne         $t5, $zero, L_8004B49C
    if (ctx->r13 != 0) {
        // 0x8004B460: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004B49C;
    }
    // 0x8004B460: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B464: lwc1        $f9, 0x6AB0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6AB0);
    // 0x8004B468: lwc1        $f8, 0x6AB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6AB4);
    // 0x8004B46C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8004B470: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8004B474: nop

    // 0x8004B478: bc1f        L_8004B49C
    if (!c1cs) {
        // 0x8004B47C: nop
    
            goto L_8004B49C;
    }
    // 0x8004B47C: nop

    // 0x8004B480: lb          $t3, 0x1D6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004B484: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004B488: beq         $t3, $at, L_8004B49C
    if (ctx->r11 == ctx->r1) {
        // 0x8004B48C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004B49C;
    }
    // 0x8004B48C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B490: lwc1        $f0, 0x6AB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6AB8);
    // 0x8004B494: nop

    // 0x8004B498: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
L_8004B49C:
    // 0x8004B49C: lwc1        $f0, 0xC8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8004B4A0: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8004B4A4: mul.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8004B4A8: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B4AC: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B4B0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004B4B4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B4B8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8004B4BC: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8004B4C0: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004B4C4: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B4C8: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B4CC: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004B4D0: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x8004B4D4: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004B4D8: nop

    // 0x8004B4DC: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B4E0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004B4E4: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8004B4E8: lb          $v1, 0x1E2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004B4EC: nop

    // 0x8004B4F0: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8004B4F4: beq         $at, $zero, L_8004B530
    if (ctx->r1 == 0) {
        // 0x8004B4F8: nop
    
            goto L_8004B530;
    }
    // 0x8004B4F8: nop

    // 0x8004B4FC: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B500: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8004B504: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8004B508: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004B50C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8004B510: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x8004B514: nop

    // 0x8004B518: bc1t        L_8004B530
    if (c1cs) {
        // 0x8004B51C: nop
    
            goto L_8004B530;
    }
    // 0x8004B51C: nop

    // 0x8004B520: lb          $t6, 0x1D6($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004B524: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004B528: bne         $t6, $at, L_8004B5A8
    if (ctx->r14 != ctx->r1) {
        // 0x8004B52C: nop
    
            goto L_8004B5A8;
    }
    // 0x8004B52C: nop

L_8004B530:
    // 0x8004B530: bne         $v1, $zero, L_8004B54C
    if (ctx->r3 != 0) {
        // 0x8004B534: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8004B54C;
    }
    // 0x8004B534: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004B538: lwc1        $f0, 0xC4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8004B53C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004B540: nop

    // 0x8004B544: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004B548: swc1        $f0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f0.u32l;
L_8004B54C:
    // 0x8004B54C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004B550: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004B554: lwc1        $f0, 0xC4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8004B558: div.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8004B55C: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8004B560: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B564: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004B568: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B56C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B570: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004B574: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x8004B578: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004B57C: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B580: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B584: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004B588: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x8004B58C: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004B590: nop

    // 0x8004B594: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8004B598: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004B59C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8004B5A0: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B5A4: nop

L_8004B5A8:
    // 0x8004B5A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004B5AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004B5B0: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8004B5B4: mul.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004B5B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004B5BC: bc1f        L_8004B5C8
    if (!c1cs) {
        // 0x8004B5C0: nop
    
            goto L_8004B5C8;
    }
    // 0x8004B5C0: nop

    // 0x8004B5C4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_8004B5C8:
    // 0x8004B5C8: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8004B5CC: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8004B5D0: bc1f        L_8004B608
    if (!c1cs) {
        // 0x8004B5D4: nop
    
            goto L_8004B608;
    }
    // 0x8004B5D4: nop

    // 0x8004B5D8: lw          $t8, -0x2558($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2558);
    // 0x8004B5DC: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8004B5E0: andi        $t4, $t8, 0x8000
    ctx->r12 = ctx->r24 & 0X8000;
    // 0x8004B5E4: bne         $t4, $zero, L_8004B608
    if (ctx->r12 != 0) {
        // 0x8004B5E8: nop
    
            goto L_8004B608;
    }
    // 0x8004B5E8: nop

    // 0x8004B5EC: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8004B5F0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004B5F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B5F8: nop

    // 0x8004B5FC: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8004B600: b           L_8004B614
    // 0x8004B604: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
        goto L_8004B614;
    // 0x8004B604: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
L_8004B608:
    // 0x8004B608: mul.s       $f20, $f12, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8004B60C: nop

    // 0x8004B610: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
L_8004B614:
    // 0x8004B614: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B618: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8004B61C: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B620: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8004B624: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x8004B628: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8004B62C: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B630: mul.s       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8004B634: sub.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8004B638: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x8004B63C: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8004B640: nop

    // 0x8004B644: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8004B648: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004B64C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004B650: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x8004B654: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8004B658: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8004B65C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8004B660: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8004B664: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8004B668: mul.s       $f20, $f10, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004B66C: bc1f        L_8004B678
    if (!c1cs) {
        // 0x8004B670: nop
    
            goto L_8004B678;
    }
    // 0x8004B670: nop

    // 0x8004B674: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_8004B678:
    // 0x8004B678: mul.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004B67C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004B680: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004B684: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004B688: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8004B68C: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B690: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004B694: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x8004B698: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B69C: mul.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B6A0: sub.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8004B6A4: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x8004B6A8: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004B6AC: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B6B0: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B6B4: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8004B6B8: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x8004B6BC: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004B6C0: nop

    // 0x8004B6C4: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B6C8: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8004B6CC: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8004B6D0: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004B6D4: nop

    // 0x8004B6D8: beq         $v0, $at, L_8004B6E4
    if (ctx->r2 == ctx->r1) {
        // 0x8004B6DC: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8004B6E4;
    }
    // 0x8004B6DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004B6E0: bne         $v0, $at, L_8004B81C
    if (ctx->r2 != ctx->r1) {
        // 0x8004B6E4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004B81C;
    }
L_8004B6E4:
    // 0x8004B6E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B6E8: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B6EC: lwc1        $f11, 0x6AC0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6AC0);
    // 0x8004B6F0: lwc1        $f10, 0x6AC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6AC4);
    // 0x8004B6F4: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8004B6F8: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8004B6FC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8004B700: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004B704: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004B708: lh          $a0, 0x1A4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004B70C: mul.d       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8004B710: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x8004B714: jal         0x80070A38
    // 0x8004B718: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    coss_f(rdram, ctx);
        goto after_27;
    // 0x8004B718: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_27:
    // 0x8004B71C: lb          $t9, 0x1E0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004B720: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004B724: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8004B728: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8004B72C: lh          $v1, 0x1A4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004B730: nop

    // 0x8004B734: slti        $at, $v1, 0x4001
    ctx->r1 = SIGNED(ctx->r3) < 0X4001 ? 1 : 0;
    // 0x8004B738: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004B73C: mul.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B740: beq         $at, $zero, L_8004B74C
    if (ctx->r1 == 0) {
        // 0x8004B744: slti        $at, $v1, -0x4000
        ctx->r1 = SIGNED(ctx->r3) < -0X4000 ? 1 : 0;
            goto L_8004B74C;
    }
    // 0x8004B744: slti        $at, $v1, -0x4000
    ctx->r1 = SIGNED(ctx->r3) < -0X4000 ? 1 : 0;
    // 0x8004B748: beq         $at, $zero, L_8004B760
    if (ctx->r1 == 0) {
        // 0x8004B74C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8004B760;
    }
L_8004B74C:
    // 0x8004B74C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004B750: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004B754: nop

    // 0x8004B758: mul.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8004B75C: nop

L_8004B760:
    // 0x8004B760: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8004B764: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B768: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8004B76C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B770: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8004B774: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x8004B778: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8004B77C: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B780: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8004B784: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8004B788: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x8004B78C: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8004B790: nop

    // 0x8004B794: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8004B798: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8004B79C: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
    // 0x8004B7A0: lh          $a0, 0x1A4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004B7A4: jal         0x80070A04
    // 0x8004B7A8: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    sins_f(rdram, ctx);
        goto after_28;
    // 0x8004B7A8: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_28:
    // 0x8004B7AC: lb          $t7, 0x1E0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E0);
    // 0x8004B7B0: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004B7B4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8004B7B8: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8004B7BC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8004B7C0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004B7C4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004B7C8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004B7CC: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B7D0: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B7D4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8004B7D8: mul.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x8004B7DC: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004B7E0: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8004B7E4: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B7E8: mul.s       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8004B7EC: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8004B7F0: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x8004B7F4: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004B7F8: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B7FC: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8004B800: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004B804: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x8004B808: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004B80C: nop

    // 0x8004B810: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8004B814: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8004B818: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
L_8004B81C:
    // 0x8004B81C: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8004B820: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004B824: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004B828: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8004B82C: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8004B830: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8004B834: mul.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004B838: bc1f        L_8004B844
    if (!c1cs) {
        // 0x8004B83C: nop
    
            goto L_8004B844;
    }
    // 0x8004B83C: nop

    // 0x8004B840: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_8004B844:
    // 0x8004B844: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8004B848: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004B84C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004B850: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8004B854: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8004B858: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B85C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004B860: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x8004B864: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004B868: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B86C: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8004B870: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    // 0x8004B874: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8004B878: lwc1        $f18, 0x24($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B87C: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B880: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8004B884: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x8004B888: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8004B88C: nop

    // 0x8004B890: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8004B894: sub.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8004B898: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x8004B89C: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004B8A0: lwc1        $f4, 0x6ACC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6ACC);
    // 0x8004B8A4: lwc1        $f5, 0x6AC8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6AC8);
    // 0x8004B8A8: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8004B8AC: mul.d       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8004B8B0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004B8B4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8004B8B8: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8004B8BC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004B8C0: add.d       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f0.d + ctx->f10.d;
    // 0x8004B8C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004B8C8: nop

    // 0x8004B8CC: mul.d       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8004B8D0: sub.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f0.d - ctx->f18.d;
    // 0x8004B8D4: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8004B8D8: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8004B8DC: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
L_8004B8E0:
    // 0x8004B8E0: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004B8E4: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x8004B8E8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004B8EC: lw          $t5, -0x252C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X252C);
    // 0x8004B8F0: lh          $v0, 0x1A2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004B8F4: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004B8F8: subu        $t3, $t5, $v0
    ctx->r11 = SUB32(ctx->r13, ctx->r2);
    // 0x8004B8FC: sra         $t6, $t3, 3
    ctx->r14 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8004B900: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x8004B904: sh          $t8, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r24;
    // 0x8004B908: lh          $t9, 0x1A2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A2);
    // 0x8004B90C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004B910: addu        $t7, $t4, $t9
    ctx->r15 = ADD32(ctx->r12, ctx->r25);
    // 0x8004B914: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    // 0x8004B918: lh          $v1, 0x1A6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004B91C: lw          $t5, -0x2528($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2528);
    // 0x8004B920: lh          $t4, 0x1A4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A4);
    // 0x8004B924: subu        $t3, $t5, $v1
    ctx->r11 = SUB32(ctx->r13, ctx->r3);
    // 0x8004B928: sra         $t6, $t3, 3
    ctx->r14 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8004B92C: addu        $t8, $v1, $t6
    ctx->r24 = ADD32(ctx->r3, ctx->r14);
    // 0x8004B930: sh          $t8, 0x1A6($s0)
    MEM_H(0X1A6, ctx->r16) = ctx->r24;
    // 0x8004B934: lh          $t9, 0x1A6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A6);
    // 0x8004B938: nop

    // 0x8004B93C: addu        $t7, $t4, $t9
    ctx->r15 = ADD32(ctx->r12, ctx->r25);
    // 0x8004B940: sh          $t7, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r15;
    // 0x8004B944: lb          $t5, 0x175($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X175);
    // 0x8004B948: nop

    // 0x8004B94C: beq         $t5, $zero, L_8004B96C
    if (ctx->r13 == 0) {
        // 0x8004B950: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004B96C;
    }
    // 0x8004B950: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004B954: lwc1        $f8, -0x2508($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2508);
    // 0x8004B958: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004B95C: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x8004B960: lwc1        $f6, -0x2504($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2504);
    // 0x8004B964: nop

    // 0x8004B968: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
L_8004B96C:
    // 0x8004B96C: lw          $t3, 0x148($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X148);
    // 0x8004B970: nop

    // 0x8004B974: bne         $t3, $zero, L_8004BAFC
    if (ctx->r11 != 0) {
        // 0x8004B978: lw          $a2, 0xFC($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XFC);
            goto L_8004BAFC;
    }
    // 0x8004B978: lw          $a2, 0xFC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XFC);
    // 0x8004B97C: lb          $t6, 0x1D2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D2);
    // 0x8004B980: lwc1        $f20, 0x1C($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8004B984: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004B988: beq         $t6, $zero, L_8004B9CC
    if (ctx->r14 == 0) {
        // 0x8004B98C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8004B9CC;
    }
    // 0x8004B98C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004B990: lwc1        $f4, 0x11C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8004B994: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004B998: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8004B99C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004B9A0: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8004B9A4: mul.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x8004B9A8: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8004B9AC: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x8004B9B0: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x8004B9B4: add.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f18.d + ctx->f8.d;
    // 0x8004B9B8: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8004B9BC: mul.d       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x8004B9C0: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8004B9C4: add.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d + ctx->f8.d;
    // 0x8004B9C8: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
L_8004B9CC:
    // 0x8004B9CC: lb          $t8, -0x24FC($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X24FC);
    // 0x8004B9D0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004B9D4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8004B9D8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004B9DC: beq         $t8, $zero, L_8004BA88
    if (ctx->r24 == 0) {
        // 0x8004B9E0: nop
    
            goto L_8004BA88;
    }
    // 0x8004B9E0: nop

    // 0x8004B9E4: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x8004B9E8: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8004B9EC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8004B9F0: bc1t        L_8004BA10
    if (c1cs) {
        // 0x8004B9F4: nop
    
            goto L_8004BA10;
    }
    // 0x8004B9F4: nop

    // 0x8004B9F8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004B9FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004BA00: nop

    // 0x8004BA04: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8004BA08: nop

    // 0x8004BA0C: bc1f        L_8004BA2C
    if (!c1cs) {
        // 0x8004BA10: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004BA2C;
    }
L_8004BA10:
    // 0x8004BA10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004BA14: lwc1        $f19, 0x6AD0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6AD0);
    // 0x8004BA18: lwc1        $f18, 0x6AD4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6AD4);
    // 0x8004BA1C: nop

    // 0x8004BA20: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x8004BA24: b           L_8004BA34
    // 0x8004BA28: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
        goto L_8004BA34;
    // 0x8004BA28: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
L_8004BA2C:
    // 0x8004BA2C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8004BA30: nop

L_8004BA34:
    // 0x8004BA34: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8004BA38: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8004BA3C: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8004BA40: bc1t        L_8004BA60
    if (c1cs) {
        // 0x8004BA44: nop
    
            goto L_8004BA60;
    }
    // 0x8004BA44: nop

    // 0x8004BA48: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004BA4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004BA50: nop

    // 0x8004BA54: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8004BA58: nop

    // 0x8004BA5C: bc1f        L_8004BA7C
    if (!c1cs) {
        // 0x8004BA60: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004BA7C;
    }
L_8004BA60:
    // 0x8004BA60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004BA64: lwc1        $f7, 0x6AD8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6AD8);
    // 0x8004BA68: lwc1        $f6, 0x6ADC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6ADC);
    // 0x8004BA6C: nop

    // 0x8004BA70: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8004BA74: b           L_8004BA98
    // 0x8004BA78: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
        goto L_8004BA98;
    // 0x8004BA78: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_8004BA7C:
    // 0x8004BA7C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8004BA80: b           L_8004BA9C
    // 0x8004BA84: lwc1        $f0, 0xFC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XFC);
        goto L_8004BA9C;
    // 0x8004BA84: lwc1        $f0, 0xFC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XFC);
L_8004BA88:
    // 0x8004BA88: lwc1        $f18, 0x84($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8004BA8C: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8004BA90: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x8004BA94: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
L_8004BA98:
    // 0x8004BA98: lwc1        $f0, 0xFC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XFC);
L_8004BA9C:
    // 0x8004BA9C: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004BAA0: mul.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8004BAA4: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    // 0x8004BAA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BAAC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004BAB0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004BAB4: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8004BAB8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8004BABC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8004BAC0: jal         0x80011570
    // 0x8004BAC4: nop

    move_object(rdram, ctx);
        goto after_29;
    // 0x8004BAC4: nop

    after_29:
    // 0x8004BAC8: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004BACC: beq         $v0, $zero, L_8004BAE8
    if (ctx->r2 == 0) {
        // 0x8004BAD0: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8004BAE8;
    }
    // 0x8004BAD0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004BAD4: lw          $t4, -0x2524($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2524);
    // 0x8004BAD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BADC: beq         $t4, $at, L_8004BAE8
    if (ctx->r12 == ctx->r1) {
        // 0x8004BAE0: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8004BAE8;
    }
    // 0x8004BAE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004BAE4: sb          $t9, 0x5F($sp)
    MEM_B(0X5F, ctx->r29) = ctx->r25;
L_8004BAE8:
    // 0x8004BAE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004BAEC: lw          $v0, -0x2524($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2524);
    // 0x8004BAF0: b           L_8004BB20
    // 0x8004BAF4: lb          $t0, 0x1E2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E2);
        goto L_8004BB20;
    // 0x8004BAF4: lb          $t0, 0x1E2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004BAF8: lw          $a2, 0xFC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XFC);
L_8004BAFC:
    // 0x8004BAFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BB00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004BB04: jal         0x80050794
    // 0x8004BB08: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    racer_approach_object(rdram, ctx);
        goto after_30;
    // 0x8004BB08: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_30:
    // 0x8004BB0C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004BB10: lw          $v0, -0x2524($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2524);
    // 0x8004BB14: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004BB18: nop

    // 0x8004BB1C: lb          $t0, 0x1E2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E2);
L_8004BB20:
    // 0x8004BB20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BB24: bne         $v0, $at, L_8004BB84
    if (ctx->r2 != ctx->r1) {
        // 0x8004BB28: lw          $a2, 0xF8($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XF8);
            goto L_8004BB84;
    }
    // 0x8004BB28: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x8004BB2C: lb          $t7, 0x1D7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004BB30: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8004BB34: bne         $t7, $at, L_8004BB4C
    if (ctx->r15 != ctx->r1) {
        // 0x8004BB38: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8004BB4C;
    }
    // 0x8004BB38: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004BB3C: lw          $t5, -0x2540($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2540);
    // 0x8004BB40: nop

    // 0x8004BB44: beq         $t5, $zero, L_8004BB74
    if (ctx->r13 == 0) {
        // 0x8004BB48: nop
    
            goto L_8004BB74;
    }
    // 0x8004BB48: nop

L_8004BB4C:
    // 0x8004BB4C: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x8004BB50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BB54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004BB58: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x8004BB5C: jal         0x80055AC4
    // 0x8004BB60: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    onscreen_ai_racer_physics(rdram, ctx);
        goto after_31;
    // 0x8004BB60: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_31:
    // 0x8004BB64: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8004BB68: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004BB6C: b           L_8004BBA4
    // 0x8004BB70: nop

        goto L_8004BBA4;
    // 0x8004BB70: nop

L_8004BB74:
    // 0x8004BB74: sb          $zero, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = 0;
    // 0x8004BB78: b           L_8004BBA4
    // 0x8004BB7C: sb          $zero, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = 0;
        goto L_8004BBA4;
    // 0x8004BB7C: sb          $zero, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = 0;
    // 0x8004BB80: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
L_8004BB84:
    // 0x8004BB84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BB88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004BB8C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x8004BB90: jal         0x80055010
    // 0x8004BB94: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    func_80054FD0(rdram, ctx);
        goto after_32;
    // 0x8004BB94: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_32:
    // 0x8004BB98: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8004BB9C: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004BBA0: nop

L_8004BBA4:
    // 0x8004BBA4: bne         $t0, $zero, L_8004BBFC
    if (ctx->r8 != 0) {
        // 0x8004BBA8: nop
    
            goto L_8004BBFC;
    }
    // 0x8004BBA8: nop

    // 0x8004BBAC: lb          $t3, 0x1E2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004BBB0: nop

    // 0x8004BBB4: beq         $t3, $zero, L_8004BBFC
    if (ctx->r11 == 0) {
        // 0x8004BBB8: nop
    
            goto L_8004BBFC;
    }
    // 0x8004BBB8: nop

    // 0x8004BBBC: lb          $t6, 0x1DB($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1DB);
    // 0x8004BBC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004BBC4: beq         $t6, $zero, L_8004BBFC
    if (ctx->r14 == 0) {
        // 0x8004BBC8: addiu       $a1, $zero, 0xC
        ctx->r5 = ADD32(0, 0XC);
            goto L_8004BBFC;
    }
    // 0x8004BBC8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8004BBCC: jal         0x80057088
    // 0x8004BBD0: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    racer_play_sound(rdram, ctx);
        goto after_33;
    // 0x8004BBD0: swc1        $f12, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f12.u32l;
    after_33:
    // 0x8004BBD4: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8004BBD8: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x8004BBDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BBE0: beq         $t8, $at, L_8004BBFC
    if (ctx->r24 == ctx->r1) {
        // 0x8004BBE4: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8004BBFC;
    }
    // 0x8004BBE4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8004BBE8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8004BBEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004BBF0: lw          $t4, -0x2578($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2578);
    // 0x8004BBF4: nop

    // 0x8004BBF8: swc1        $f4, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f4.u32l;
L_8004BBFC:
    // 0x8004BBFC: lb          $v0, 0x1D2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D2);
    // 0x8004BC00: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004BC04: beq         $v0, $zero, L_8004BC34
    if (ctx->r2 == 0) {
        // 0x8004BC08: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8004BC34;
    }
    // 0x8004BC08: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004BC0C: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x8004BC10: nop

    // 0x8004BC14: subu        $t7, $v0, $t9
    ctx->r15 = SUB32(ctx->r2, ctx->r25);
    // 0x8004BC18: sb          $t7, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r15;
    // 0x8004BC1C: lb          $t5, 0x1D2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D2);
    // 0x8004BC20: nop

    // 0x8004BC24: bgez        $t5, L_8004BC94
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8004BC28: nop
    
            goto L_8004BC94;
    }
    // 0x8004BC28: nop

    // 0x8004BC2C: b           L_8004BC94
    // 0x8004BC30: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
        goto L_8004BC94;
    // 0x8004BC30: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
L_8004BC34:
    // 0x8004BC34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004BC38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004BC3C: lwc1        $f6, 0xFC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x8004BC40: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8004BC44: div.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8004BC48: lwc1        $f18, 0xE8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x8004BC4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004BC50: lwc1        $f8, -0x2538($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2538);
    // 0x8004BC54: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8004BC58: lwc1        $f18, 0xE4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8004BC5C: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8004BC60: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004BC64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004BC68: mul.s       $f20, $f6, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8004BC6C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8004BC70: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004BC74: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004BC78: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x8004BC7C: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8004BC80: lwc1        $f4, -0x2534($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2534);
    // 0x8004BC84: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8004BC88: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8004BC8C: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8004BC90: nop

L_8004BC94:
    // 0x8004BC94: lw          $t3, -0x2540($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2540);
    // 0x8004BC98: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8004BC9C: bne         $t3, $at, L_8004BCB4
    if (ctx->r11 != ctx->r1) {
        // 0x8004BCA0: addiu       $a1, $a1, -0x2570
        ctx->r5 = ADD32(ctx->r5, -0X2570);
            goto L_8004BCB4;
    }
    // 0x8004BCA0: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x8004BCA4: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8004BCA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004BCAC: nop

    // 0x8004BCB0: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
L_8004BCB4:
    // 0x8004BCB4: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x8004BCB8: swc1        $f20, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f20.u32l;
    // 0x8004BCBC: swc1        $f12, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f12.u32l;
    // 0x8004BCC0: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x8004BCC4: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8004BCC8: lh          $t4, 0x2($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2);
    // 0x8004BCCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004BCD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004BCD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004BCD8: negu        $t9, $t4
    ctx->r25 = SUB32(0, ctx->r12);
    // 0x8004BCDC: sh          $t9, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r25;
    // 0x8004BCE0: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x8004BCE4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8004BCE8: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8004BCEC: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x8004BCF0: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x8004BCF4: jal         0x800700B4
    // 0x8004BCF8: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_34;
    // 0x8004BCF8: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    after_34:
    // 0x8004BCFC: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x8004BD00: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x8004BD04: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x8004BD08: addiu       $t7, $s0, 0x30
    ctx->r15 = ADD32(ctx->r16, 0X30);
    // 0x8004BD0C: addiu       $t5, $s0, 0x34
    ctx->r13 = ADD32(ctx->r16, 0X34);
    // 0x8004BD10: addiu       $t3, $s0, 0x2C
    ctx->r11 = ADD32(ctx->r16, 0X2C);
    // 0x8004BD14: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8004BD18: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8004BD1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8004BD20: jal         0x8006F88C
    // 0x8004BD24: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    mtxf_transform_point(rdram, ctx);
        goto after_35;
    // 0x8004BD24: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_35:
    // 0x8004BD28: lw          $v1, 0x60($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X60);
    // 0x8004BD2C: nop

    // 0x8004BD30: beq         $v1, $zero, L_8004BD80
    if (ctx->r3 == 0) {
        // 0x8004BD34: nop
    
            goto L_8004BD80;
    }
    // 0x8004BD34: nop

    // 0x8004BD38: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004BD3C: nop

    // 0x8004BD40: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8004BD44: bne         $at, $zero, L_8004BD80
    if (ctx->r1 != 0) {
        // 0x8004BD48: nop
    
            goto L_8004BD80;
    }
    // 0x8004BD48: nop

    // 0x8004BD4C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8004BD50: addiu       $t8, $zero, 0x4000
    ctx->r24 = ADD32(0, 0X4000);
    // 0x8004BD54: lb          $t4, 0x3A($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X3A);
    // 0x8004BD58: lw          $t7, 0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X40);
    // 0x8004BD5C: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x8004BD60: sb          $t9, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r25;
    // 0x8004BD64: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8004BD68: lb          $t3, 0x3A($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X3A);
    // 0x8004BD6C: lb          $t5, 0x55($t7)
    ctx->r13 = MEM_B(ctx->r15, 0X55);
    // 0x8004BD70: nop

    // 0x8004BD74: bne         $t5, $t3, L_8004BD80
    if (ctx->r13 != ctx->r11) {
        // 0x8004BD78: nop
    
            goto L_8004BD80;
    }
    // 0x8004BD78: nop

    // 0x8004BD7C: sb          $zero, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = 0;
L_8004BD80:
    // 0x8004BD80: lw          $v1, 0x60($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X60);
    // 0x8004BD84: nop

    // 0x8004BD88: beq         $v1, $zero, L_8004BF08
    if (ctx->r3 == 0) {
        // 0x8004BD8C: nop
    
            goto L_8004BF08;
    }
    // 0x8004BD8C: nop

    // 0x8004BD90: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004BD94: nop

    // 0x8004BD98: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8004BD9C: bne         $at, $zero, L_8004BF08
    if (ctx->r1 != 0) {
        // 0x8004BDA0: nop
    
            goto L_8004BF08;
    }
    // 0x8004BDA0: nop

    // 0x8004BDA4: lb          $t8, 0x1E2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004BDA8: lb          $t4, 0xA2($sp)
    ctx->r12 = MEM_B(ctx->r29, 0XA2);
    // 0x8004BDAC: bne         $t8, $zero, L_8004BDBC
    if (ctx->r24 != 0) {
        // 0x8004BDB0: nop
    
            goto L_8004BDBC;
    }
    // 0x8004BDB0: nop

    // 0x8004BDB4: beq         $t4, $zero, L_8004BE78
    if (ctx->r12 == 0) {
        // 0x8004BDB8: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8004BE78;
    }
    // 0x8004BDB8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8004BDBC:
    // 0x8004BDBC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8004BDC0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004BDC4: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004BDC8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004BDCC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8004BDD0: nop

    // 0x8004BDD4: bc1f        L_8004BDF8
    if (!c1cs) {
        // 0x8004BDD8: nop
    
            goto L_8004BDF8;
    }
    // 0x8004BDD8: nop

    // 0x8004BDDC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004BDE0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004BDE4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8004BDE8: sub.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d - ctx->f8.d;
    // 0x8004BDEC: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8004BDF0: b           L_8004BE04
    // 0x8004BDF4: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
        goto L_8004BE04;
    // 0x8004BDF4: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
L_8004BDF8:
    // 0x8004BDF8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004BDFC: nop

    // 0x8004BE00: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
L_8004BE04:
    // 0x8004BE04: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8004BE08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004BE0C: andi        $t7, $t9, 0xBFFF
    ctx->r15 = ctx->r25 & 0XBFFF;
    // 0x8004BE10: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x8004BE14: lw          $t5, 0x60($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X60);
    // 0x8004BE18: addiu       $v1, $zero, -0x4001
    ctx->r3 = ADD32(0, -0X4001);
    // 0x8004BE1C: lw          $v0, 0x8($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X8);
    // 0x8004BE20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004BE24: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004BE28: nop

    // 0x8004BE2C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8004BE30: nop

    // 0x8004BE34: bc1f        L_8004BE58
    if (!c1cs) {
        // 0x8004BE38: nop
    
            goto L_8004BE58;
    }
    // 0x8004BE38: nop

    // 0x8004BE3C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004BE40: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004BE44: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8004BE48: sub.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d - ctx->f6.d;
    // 0x8004BE4C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8004BE50: b           L_8004BE64
    // 0x8004BE54: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
        goto L_8004BE64;
    // 0x8004BE54: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
L_8004BE58:
    // 0x8004BE58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004BE5C: nop

    // 0x8004BE60: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
L_8004BE64:
    // 0x8004BE64: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8004BE68: nop

    // 0x8004BE6C: and         $t6, $t3, $v1
    ctx->r14 = ctx->r11 & ctx->r3;
    // 0x8004BE70: b           L_8004BF08
    // 0x8004BE74: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
        goto L_8004BF08;
    // 0x8004BE74: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
L_8004BE78:
    // 0x8004BE78: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8004BE7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004BE80: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004BE84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004BE88: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8004BE8C: nop

    // 0x8004BE90: bc1f        L_8004BEAC
    if (!c1cs) {
        // 0x8004BE94: nop
    
            goto L_8004BEAC;
    }
    // 0x8004BE94: nop

    // 0x8004BE98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004BE9C: nop

    // 0x8004BEA0: add.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8004BEA4: b           L_8004BEBC
    // 0x8004BEA8: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
        goto L_8004BEBC;
    // 0x8004BEA8: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
L_8004BEAC:
    // 0x8004BEAC: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x8004BEB0: nop

    // 0x8004BEB4: ori         $t4, $t8, 0x4000
    ctx->r12 = ctx->r24 | 0X4000;
    // 0x8004BEB8: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
L_8004BEBC:
    // 0x8004BEBC: lw          $t9, 0x60($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X60);
    // 0x8004BEC0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004BEC4: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x8004BEC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004BECC: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004BED0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004BED4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8004BED8: nop

    // 0x8004BEDC: bc1f        L_8004BEF8
    if (!c1cs) {
        // 0x8004BEE0: nop
    
            goto L_8004BEF8;
    }
    // 0x8004BEE0: nop

    // 0x8004BEE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004BEE8: nop

    // 0x8004BEEC: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004BEF0: b           L_8004BF08
    // 0x8004BEF4: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
        goto L_8004BF08;
    // 0x8004BEF4: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
L_8004BEF8:
    // 0x8004BEF8: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8004BEFC: nop

    // 0x8004BF00: ori         $t5, $t7, 0x4000
    ctx->r13 = ctx->r15 | 0X4000;
    // 0x8004BF04: sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
L_8004BF08:
    // 0x8004BF08: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004BF0C: lw          $t3, -0x2524($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2524);
    // 0x8004BF10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004BF14: beq         $t3, $at, L_8004C030
    if (ctx->r11 == ctx->r1) {
        // 0x8004BF18: nop
    
            goto L_8004C030;
    }
    // 0x8004BF18: nop

    // 0x8004BF1C: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x8004BF20: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8004BF24: bne         $t6, $zero, L_8004C030
    if (ctx->r14 != 0) {
        // 0x8004BF28: nop
    
            goto L_8004C030;
    }
    // 0x8004BF28: nop

    // 0x8004BF2C: lw          $t8, -0x2EF8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2EF8);
    // 0x8004BF30: nop

    // 0x8004BF34: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8004BF38: beq         $at, $zero, L_8004C030
    if (ctx->r1 == 0) {
        // 0x8004BF3C: nop
    
            goto L_8004C030;
    }
    // 0x8004BF3C: nop

    // 0x8004BF40: jal         0x8001E2D0
    // 0x8004BF44: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_36;
    // 0x8004BF44: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_36:
    // 0x8004BF48: lb          $t0, 0x203($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X203);
    // 0x8004BF4C: lb          $t4, 0x2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X2);
    // 0x8004BF50: andi        $t7, $t0, 0x4
    ctx->r15 = ctx->r8 & 0X4;
    // 0x8004BF54: sra         $t5, $t7, 2
    ctx->r13 = S32(SIGNED(ctx->r15) >> 2);
    // 0x8004BF58: addiu       $t0, $t5, 0x9
    ctx->r8 = ADD32(ctx->r13, 0X9);
    // 0x8004BF5C: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x8004BF60: sll         $t9, $t4, 7
    ctx->r25 = S32(ctx->r12 << 7);
    // 0x8004BF64: bne         $at, $zero, L_8004BFB0
    if (ctx->r1 != 0) {
        // 0x8004BF68: addu        $v1, $t9, $v0
        ctx->r3 = ADD32(ctx->r25, ctx->r2);
            goto L_8004BFB0;
    }
    // 0x8004BF68: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x8004BF6C: lbu         $t3, 0x70($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X70);
    // 0x8004BF70: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004BF74: bgtz        $t3, L_8004BF9C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8004BF78: nop
    
            goto L_8004BF9C;
    }
    // 0x8004BF78: nop

    // 0x8004BF7C: lwc1        $f10, 0x74($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8004BF80: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8004BF84: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004BF88: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8004BF8C: c.lt.d      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.d < ctx->f18.d;
    // 0x8004BF90: nop

    // 0x8004BF94: bc1f        L_8004C030
    if (!c1cs) {
        // 0x8004BF98: nop
    
            goto L_8004C030;
    }
    // 0x8004BF98: nop

L_8004BF9C:
    // 0x8004BF9C: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x8004BFA0: sllv        $t4, $t8, $t0
    ctx->r12 = S32(ctx->r24 << (ctx->r8 & 31));
    // 0x8004BFA4: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x8004BFA8: b           L_8004C030
    // 0x8004BFAC: sw          $t9, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r25;
        goto L_8004C030;
    // 0x8004BFAC: sw          $t9, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r25;
L_8004BFB0:
    // 0x8004BFB0: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x8004BFB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004BFB8: bne         $v0, $at, L_8004BFFC
    if (ctx->r2 != ctx->r1) {
        // 0x8004BFBC: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8004BFFC;
    }
    // 0x8004BFBC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004BFC0: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8004BFC4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004BFC8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004BFCC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004BFD0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8004BFD4: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8004BFD8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8004BFDC: bc1f        L_8004BFFC
    if (!c1cs) {
        // 0x8004BFE0: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8004BFFC;
    }
    // 0x8004BFE0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004BFE4: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x8004BFE8: sllv        $t3, $t5, $t0
    ctx->r11 = S32(ctx->r13 << (ctx->r8 & 31));
    // 0x8004BFEC: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x8004BFF0: b           L_8004C030
    // 0x8004BFF4: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
        goto L_8004C030;
    // 0x8004BFF4: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
    // 0x8004BFF8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_8004BFFC:
    // 0x8004BFFC: beq         $at, $zero, L_8004C030
    if (ctx->r1 == 0) {
        // 0x8004C000: nop
    
            goto L_8004C030;
    }
    // 0x8004C000: nop

    // 0x8004C004: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004C008: lwc1        $f18, 0x74($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8004C00C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004C010: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8004C014: nop

    // 0x8004C018: bc1f        L_8004C030
    if (!c1cs) {
        // 0x8004C01C: nop
    
            goto L_8004C030;
    }
    // 0x8004C01C: nop

    // 0x8004C020: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x8004C024: sllv        $t9, $t4, $t0
    ctx->r25 = S32(ctx->r12 << (ctx->r8 & 31));
    // 0x8004C028: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x8004C02C: sw          $t5, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r13;
L_8004C030:
    // 0x8004C030: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8004C034: lw          $t7, -0x2524($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2524);
    // 0x8004C038: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C03C: bne         $t7, $at, L_8004C048
    if (ctx->r15 != ctx->r1) {
        // 0x8004C040: nop
    
            goto L_8004C048;
    }
    // 0x8004C040: nop

    // 0x8004C044: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
L_8004C048:
    // 0x8004C048: lb          $t3, 0x201($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X201);
    // 0x8004C04C: nop

    // 0x8004C050: bne         $t3, $zero, L_8004C05C
    if (ctx->r11 != 0) {
        // 0x8004C054: nop
    
            goto L_8004C05C;
    }
    // 0x8004C054: nop

    // 0x8004C058: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
L_8004C05C:
    // 0x8004C05C: lb          $t8, 0x1D7($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D7);
    // 0x8004C060: lw          $a1, 0xF8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XF8);
    // 0x8004C064: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x8004C068: beq         $at, $zero, L_8004C07C
    if (ctx->r1 == 0) {
        // 0x8004C06C: lb          $t4, 0xA1($sp)
        ctx->r12 = MEM_B(ctx->r29, 0XA1);
            goto L_8004C07C;
    }
    // 0x8004C06C: lb          $t4, 0xA1($sp)
    ctx->r12 = MEM_B(ctx->r29, 0XA1);
    // 0x8004C070: jal         0x800AFC74
    // 0x8004C074: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    update_vehicle_particles(rdram, ctx);
        goto after_37;
    // 0x8004C074: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_37:
    // 0x8004C078: lb          $t4, 0xA1($sp)
    ctx->r12 = MEM_B(ctx->r29, 0XA1);
L_8004C07C:
    // 0x8004C07C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004C080: beq         $t4, $zero, L_8004C0A0
    if (ctx->r12 == 0) {
        // 0x8004C084: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8004C0A0;
    }
    // 0x8004C084: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004C088: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004C08C: addiu       $v0, $v0, -0x2558
    ctx->r2 = ADD32(ctx->r2, -0X2558);
    // 0x8004C090: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004C094: nop

    // 0x8004C098: ori         $t9, $t6, 0x10
    ctx->r25 = ctx->r14 | 0X10;
    // 0x8004C09C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8004C0A0:
    // 0x8004C0A0: lw          $a3, 0xFC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XFC);
    // 0x8004C0A4: jal         0x800580F4
    // 0x8004C0A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    second_racer_camera_update(rdram, ctx);
        goto after_38;
    // 0x8004C0A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_38:
    // 0x8004C0AC: lb          $t5, 0x5F($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X5F);
    // 0x8004C0B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004C0B4: beq         $t5, $zero, L_8004C0C8
    if (ctx->r13 == 0) {
        // 0x8004C0B8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8004C0C8;
    }
    // 0x8004C0B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8004C0BC: jal         0x80023104
    // 0x8004C0C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800230D0(rdram, ctx);
        goto after_39;
    // 0x8004C0C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_39:
    // 0x8004C0C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8004C0C8:
    // 0x8004C0C8: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8004C0CC: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004C0D0: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8004C0D4: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8004C0D8: jr          $ra
    // 0x8004C0DC: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x8004C0DC: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_80063A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063CD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063CD8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063CDC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063CE0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063CE4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063CE8: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80063CEC: addiu       $t8, $zero, 0x5F
    ctx->r24 = ADD32(0, 0X5F);
    // 0x80063CF0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063CF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063CF8: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063CFC: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063D00: sb          $a3, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r7;
    // 0x80063D04: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063D08: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063D0C: jal         0x800C970C
    // 0x80063D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80063D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063D18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063D1C: jr          $ra
    // 0x80063D20: nop

    return;
    // 0x80063D20: nop

;}
RECOMP_FUNC void drm_validate_dmem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F1F8: lui         $t6, 0xA400
    ctx->r14 = S32(0XA400 << 16);
    // 0x8006F1FC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8006F200: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006F204: beq         $t7, $at, L_8006F214
    if (ctx->r15 == ctx->r1) {
        // 0x8006F208: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006F214;
    }
    // 0x8006F208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F20C: jr          $ra
    // 0x8006F210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006F210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006F214:
    // 0x8006F214: jr          $ra
    // 0x8006F218: nop

    return;
    // 0x8006F218: nop

;}
RECOMP_FUNC void func_80073588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800737E0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800737E4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800737E8: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x800737EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800737F0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800737F4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800737F8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800737FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80073800: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80073804: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80073808: jal         0x8006E9B0
    // 0x8007380C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    clear_lap_records(rdram, ctx);
        goto after_0;
    // 0x8007380C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80073810: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80073814: jal         0x8006B464
    // 0x80073818: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    level_count(rdram, ctx);
        goto after_1;
    // 0x80073818: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x8007381C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80073820: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80073824: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80073828: beq         $t8, $zero, L_8007397C
    if (ctx->r24 == 0) {
        // 0x8007382C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8007397C;
    }
    // 0x8007382C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073830: sw          $t9, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r25;
    // 0x80073834: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073838: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x8007383C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073840: sw          $zero, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = 0;
    // 0x80073844: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80073848: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x8007384C: addiu       $v0, $t9, 0x2
    ctx->r2 = ADD32(ctx->r25, 0X2);
L_80073850:
    // 0x80073850: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80073854: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073858: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x8007385C: slti        $at, $s1, 0xC0
    ctx->r1 = SIGNED(ctx->r17) < 0XC0 ? 1 : 0;
    // 0x80073860: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x80073864: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80073868: bne         $at, $zero, L_80073850
    if (ctx->r1 != 0) {
        // 0x8007386C: sra         $s0, $t1, 16
        ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
            goto L_80073850;
    }
    // 0x8007386C: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80073870: jal         0x80072EAC
    // 0x80073874: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_2;
    // 0x80073874: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x80073878: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x8007387C: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x80073880: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80073884: bne         $t4, $zero, L_80073980
    if (ctx->r12 != 0) {
        // 0x80073888: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80073980;
    }
    // 0x80073888: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8007388C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80073890: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80073894: blez        $t5, L_80073980
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80073898: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80073980;
    }
    // 0x80073898: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
L_8007389C:
    // 0x8007389C: jal         0x8006B38C
    // 0x800738A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_3;
    // 0x800738A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800738A4: bne         $v0, $zero, L_8007396C
    if (ctx->r2 != 0) {
        // 0x800738A8: lw          $t4, 0x40($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X40);
            goto L_8007396C;
    }
    // 0x800738A8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800738AC: jal         0x8006B338
    // 0x800738B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_4;
    // 0x800738B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800738B4: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x800738B8: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800738BC: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800738C0: beq         $t9, $zero, L_800738F8
    if (ctx->r25 == 0) {
        // 0x800738C4: or          $s2, $t6, $zero
        ctx->r18 = ctx->r14 | 0;
            goto L_800738F8;
    }
    // 0x800738C4: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x800738C8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800738CC: jal         0x80072EAC
    // 0x800738D0: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_5;
    // 0x800738D0: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_5:
    // 0x800738D4: lw          $t0, 0x24($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X24);
    // 0x800738D8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800738DC: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x800738E0: jal         0x80072EAC
    // 0x800738E4: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_6;
    // 0x800738E4: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    after_6:
    // 0x800738E8: lw          $t2, 0x18($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X18);
    // 0x800738EC: nop

    // 0x800738F0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800738F4: sh          $v0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r2;
L_800738F8:
    // 0x800738F8: andi        $t4, $s2, 0x2
    ctx->r12 = ctx->r18 & 0X2;
    // 0x800738FC: beq         $t4, $zero, L_80073930
    if (ctx->r12 == 0) {
        // 0x80073900: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80073930;
    }
    // 0x80073900: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073904: jal         0x80072EAC
    // 0x80073908: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_7;
    // 0x80073908: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_7:
    // 0x8007390C: lw          $t5, 0x28($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X28);
    // 0x80073910: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073914: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80073918: jal         0x80072EAC
    // 0x8007391C: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_8;
    // 0x8007391C: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    after_8:
    // 0x80073920: lw          $t7, 0x1C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X1C);
    // 0x80073924: nop

    // 0x80073928: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8007392C: sh          $v0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r2;
L_80073930:
    // 0x80073930: andi        $t9, $s2, 0x4
    ctx->r25 = ctx->r18 & 0X4;
    // 0x80073934: beq         $t9, $zero, L_80073968
    if (ctx->r25 == 0) {
        // 0x80073938: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80073968;
    }
    // 0x80073938: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007393C: jal         0x80072EAC
    // 0x80073940: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_9;
    // 0x80073940: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_9:
    // 0x80073944: lw          $t0, 0x2C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X2C);
    // 0x80073948: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007394C: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80073950: jal         0x80072EAC
    // 0x80073954: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_10;
    // 0x80073954: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    after_10:
    // 0x80073958: lw          $t2, 0x20($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X20);
    // 0x8007395C: nop

    // 0x80073960: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80073964: sh          $v0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r2;
L_80073968:
    // 0x80073968: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_8007396C:
    // 0x8007396C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073970: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80073974: bne         $at, $zero, L_8007389C
    if (ctx->r1 != 0) {
        // 0x80073978: nop
    
            goto L_8007389C;
    }
    // 0x80073978: nop

L_8007397C:
    // 0x8007397C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
L_80073980:
    // 0x80073980: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80073984: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80073988: beq         $t6, $zero, L_80073AE0
    if (ctx->r14 == 0) {
        // 0x8007398C: addiu       $t8, $t7, 0xC0
        ctx->r24 = ADD32(ctx->r15, 0XC0);
            goto L_80073AE0;
    }
    // 0x8007398C: addiu       $t8, $t7, 0xC0
    ctx->r24 = ADD32(ctx->r15, 0XC0);
    // 0x80073990: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073994: sw          $t8, 0x476C($at)
    MEM_W(0X476C, ctx->r1) = ctx->r24;
    // 0x80073998: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007399C: sw          $zero, 0x4770($at)
    MEM_W(0X4770, ctx->r1) = 0;
    // 0x800739A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800739A4: sw          $zero, 0x4774($at)
    MEM_W(0X4774, ctx->r1) = 0;
    // 0x800739A8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x800739AC: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x800739B0: addiu       $v0, $t8, 0x2
    ctx->r2 = ADD32(ctx->r24, 0X2);
L_800739B4:
    // 0x800739B4: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800739B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800739BC: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x800739C0: slti        $at, $s1, 0xC0
    ctx->r1 = SIGNED(ctx->r17) < 0XC0 ? 1 : 0;
    // 0x800739C4: sll         $t0, $s0, 16
    ctx->r8 = S32(ctx->r16 << 16);
    // 0x800739C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800739CC: bne         $at, $zero, L_800739B4
    if (ctx->r1 != 0) {
        // 0x800739D0: sra         $s0, $t0, 16
        ctx->r16 = S32(SIGNED(ctx->r8) >> 16);
            goto L_800739B4;
    }
    // 0x800739D0: sra         $s0, $t0, 16
    ctx->r16 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800739D4: jal         0x80072EAC
    // 0x800739D8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_11;
    // 0x800739D8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_11:
    // 0x800739DC: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800739E0: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x800739E4: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800739E8: bne         $t3, $zero, L_80073AE4
    if (ctx->r11 != 0) {
        // 0x800739EC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80073AE4;
    }
    // 0x800739EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800739F0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800739F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800739F8: blez        $t4, L_80073AE4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800739FC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80073AE4;
    }
    // 0x800739FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80073A00:
    // 0x80073A00: jal         0x8006B38C
    // 0x80073A04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_12;
    // 0x80073A04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80073A08: bne         $v0, $zero, L_80073AD0
    if (ctx->r2 != 0) {
        // 0x80073A0C: lw          $t3, 0x40($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X40);
            goto L_80073AD0;
    }
    // 0x80073A0C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80073A10: jal         0x8006B338
    // 0x80073A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_13;
    // 0x80073A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80073A18: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x80073A1C: sra         $t5, $s2, 16
    ctx->r13 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80073A20: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80073A24: beq         $t8, $zero, L_80073A5C
    if (ctx->r24 == 0) {
        // 0x80073A28: or          $s2, $t5, $zero
        ctx->r18 = ctx->r13 | 0;
            goto L_80073A5C;
    }
    // 0x80073A28: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
    // 0x80073A2C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073A30: jal         0x80072EAC
    // 0x80073A34: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_14;
    // 0x80073A34: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_14:
    // 0x80073A38: lw          $t9, 0x3C($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X3C);
    // 0x80073A3C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073A40: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80073A44: jal         0x80072EAC
    // 0x80073A48: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_15;
    // 0x80073A48: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    after_15:
    // 0x80073A4C: lw          $t1, 0x30($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X30);
    // 0x80073A50: nop

    // 0x80073A54: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073A58: sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
L_80073A5C:
    // 0x80073A5C: andi        $t3, $s2, 0x2
    ctx->r11 = ctx->r18 & 0X2;
    // 0x80073A60: beq         $t3, $zero, L_80073A94
    if (ctx->r11 == 0) {
        // 0x80073A64: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80073A94;
    }
    // 0x80073A64: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073A68: jal         0x80072EAC
    // 0x80073A6C: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_16;
    // 0x80073A6C: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_16:
    // 0x80073A70: lw          $t4, 0x40($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X40);
    // 0x80073A74: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073A78: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80073A7C: jal         0x80072EAC
    // 0x80073A80: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_17;
    // 0x80073A80: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
    after_17:
    // 0x80073A84: lw          $t6, 0x34($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X34);
    // 0x80073A88: nop

    // 0x80073A8C: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80073A90: sh          $v0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r2;
L_80073A94:
    // 0x80073A94: andi        $t8, $s2, 0x4
    ctx->r24 = ctx->r18 & 0X4;
    // 0x80073A98: beq         $t8, $zero, L_80073ACC
    if (ctx->r24 == 0) {
        // 0x80073A9C: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80073ACC;
    }
    // 0x80073A9C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073AA0: jal         0x80072EAC
    // 0x80073AA4: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    func_80072C54(rdram, ctx);
        goto after_18;
    // 0x80073AA4: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    after_18:
    // 0x80073AA8: lw          $t9, 0x44($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X44);
    // 0x80073AAC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073AB0: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80073AB4: jal         0x80072EAC
    // 0x80073AB8: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    func_80072C54(rdram, ctx);
        goto after_19;
    // 0x80073AB8: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    after_19:
    // 0x80073ABC: lw          $t1, 0x38($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X38);
    // 0x80073AC0: nop

    // 0x80073AC4: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073AC8: sh          $v0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r2;
L_80073ACC:
    // 0x80073ACC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
L_80073AD0:
    // 0x80073AD0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073AD4: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80073AD8: bne         $at, $zero, L_80073A00
    if (ctx->r1 != 0) {
        // 0x80073ADC: nop
    
            goto L_80073A00;
    }
    // 0x80073ADC: nop

L_80073AE0:
    // 0x80073AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80073AE4:
    // 0x80073AE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80073AE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80073AEC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80073AF0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80073AF4: jr          $ra
    // 0x80073AF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80073AF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void charselect_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BC10: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008BC14: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8008BC18: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8008BC1C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8008BC20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008BC24: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8008BC28: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8008BC2C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008BC30: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008BC34: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008BC38: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x8008BC3C: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008BC40: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8008BC44: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8008BC48: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8008BC4C: addiu       $fp, $fp, 0x696C
    ctx->r30 = ADD32(ctx->r30, 0X696C);
    // 0x8008BC50: addiu       $s7, $s7, -0x600
    ctx->r23 = ADD32(ctx->r23, -0X600);
    // 0x8008BC54: addiu       $s6, $s6, 0x6988
    ctx->r22 = ADD32(ctx->r22, 0X6988);
    // 0x8008BC58: addiu       $s0, $s0, 0x6960
    ctx->r16 = ADD32(ctx->r16, 0X6960);
    // 0x8008BC5C: addiu       $s3, $zero, 0xE
    ctx->r19 = ADD32(0, 0XE);
    // 0x8008BC60: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8008BC64: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
    // 0x8008BC68: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8008BC6C:
    // 0x8008BC6C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8008BC70: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8008BC74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008BC78: beq         $t6, $zero, L_8008BFB0
    if (ctx->r14 == 0) {
        // 0x8008BC7C: addiu       $t7, $t7, 0x697C
        ctx->r15 = ADD32(ctx->r15, 0X697C);
            goto L_8008BFB0;
    }
    // 0x8008BC7C: addiu       $t7, $t7, 0x697C
    ctx->r15 = ADD32(ctx->r15, 0X697C);
    // 0x8008BC80: addu        $a1, $s4, $t7
    ctx->r5 = ADD32(ctx->r20, ctx->r15);
    // 0x8008BC84: lb          $t9, 0x0($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X0);
    // 0x8008BC88: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008BC8C: addiu       $t8, $t8, 0x6D78
    ctx->r24 = ADD32(ctx->r24, 0X6D78);
    // 0x8008BC90: sll         $a2, $s4, 2
    ctx->r6 = S32(ctx->r20 << 2);
    // 0x8008BC94: beq         $t9, $zero, L_8008BD10
    if (ctx->r25 == 0) {
        // 0x8008BC98: addu        $v0, $a2, $t8
        ctx->r2 = ADD32(ctx->r6, ctx->r24);
            goto L_8008BD10;
    }
    // 0x8008BC98: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x8008BC9C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8008BCA0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008BCA4: andi        $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 & 0X4000;
    // 0x8008BCA8: beq         $t1, $zero, L_8008BFB0
    if (ctx->r9 == 0) {
        // 0x8008BCAC: addiu       $t4, $t4, 0x6DA8
        ctx->r12 = ADD32(ctx->r12, 0X6DA8);
            goto L_8008BFB0;
    }
    // 0x8008BCAC: addiu       $t4, $t4, 0x6DA8
    ctx->r12 = ADD32(ctx->r12, 0X6DA8);
    // 0x8008BCB0: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x8008BCB4: addu        $s1, $a2, $t4
    ctx->r17 = ADD32(ctx->r6, ctx->r12);
    // 0x8008BCB8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008BCBC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8008BCC0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8008BCC4: sw          $t3, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r11;
    // 0x8008BCC8: beq         $a0, $zero, L_8008BCD8
    if (ctx->r4 == 0) {
        // 0x8008BCCC: addu        $s2, $s6, $s4
        ctx->r18 = ADD32(ctx->r22, ctx->r20);
            goto L_8008BCD8;
    }
    // 0x8008BCCC: addu        $s2, $s6, $s4
    ctx->r18 = ADD32(ctx->r22, ctx->r20);
    // 0x8008BCD0: jal         0x8000488C
    // 0x8008BCD4: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x8008BCD4: nop

    after_0:
L_8008BCD8:
    // 0x8008BCD8: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8008BCDC: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x8008BCE0: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BCE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008BCE8: mflo        $t7
    ctx->r15 = lo;
    // 0x8008BCEC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8008BCF0: lh          $a0, 0xC($t8)
    ctx->r4 = MEM_H(ctx->r24, 0XC);
    // 0x8008BCF4: nop

    // 0x8008BCF8: addiu       $a0, $a0, 0x93
    ctx->r4 = ADD32(ctx->r4, 0X93);
    // 0x8008BCFC: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8008BD00: jal         0x80001D04
    // 0x8008BD04: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8008BD04: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x8008BD08: b           L_8008BFB4
    // 0x8008BD0C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
        goto L_8008BFB4;
    // 0x8008BD0C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008BD10:
    // 0x8008BD10: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8008BD14: addu        $s2, $s6, $s4
    ctx->r18 = ADD32(ctx->r22, ctx->r20);
    // 0x8008BD18: andi        $t0, $v1, 0x4000
    ctx->r8 = ctx->r3 & 0X4000;
    // 0x8008BD1C: beq         $t0, $zero, L_8008BE10
    if (ctx->r8 == 0) {
        // 0x8008BD20: andi        $t8, $v1, 0x9000
        ctx->r24 = ctx->r3 & 0X9000;
            goto L_8008BE10;
    }
    // 0x8008BD20: andi        $t8, $v1, 0x9000
    ctx->r24 = ctx->r3 & 0X9000;
    // 0x8008BD24: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008BD28: lw          $t1, -0x5C4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5C4);
    // 0x8008BD2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BD30: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8008BD34: sw          $t2, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r10;
    // 0x8008BD38: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008BD3C: lw          $a2, -0x5C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5C4);
    // 0x8008BD40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008BD44: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x8008BD48: blez        $a2, L_8008BDE4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008BD4C: sb          $zero, 0x6974($at)
        MEM_B(0X6974, ctx->r1) = 0;
            goto L_8008BDE4;
    }
    // 0x8008BD4C: sb          $zero, 0x6974($at)
    MEM_B(0X6974, ctx->r1) = 0;
    // 0x8008BD50: lb          $t4, 0x0($s2)
    ctx->r12 = MEM_B(ctx->r18, 0X0);
    // 0x8008BD54: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BD58: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BD5C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008BD60: lb          $t3, 0x6954($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X6954);
    // 0x8008BD64: mflo        $t6
    ctx->r14 = lo;
    // 0x8008BD68: addu        $t5, $a1, $t6
    ctx->r13 = ADD32(ctx->r5, ctx->r14);
    // 0x8008BD6C: lh          $t7, 0xC($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XC);
    // 0x8008BD70: nop

    // 0x8008BD74: bne         $t3, $t7, L_8008BDE8
    if (ctx->r11 != ctx->r15) {
        // 0x8008BD78: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_8008BDE8;
    }
    // 0x8008BD78: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8008BD7C: lb          $t8, 0x1($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1);
    // 0x8008BD80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008BD84: bgtz        $t8, L_8008BDE4
    if (SIGNED(ctx->r24) > 0) {
        // 0x8008BD88: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8008BDE4;
    }
    // 0x8008BD88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008BD8C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008BD90: addiu       $t9, $t9, 0x6974
    ctx->r25 = ADD32(ctx->r25, 0X6974);
    // 0x8008BD94: addu        $v0, $zero, $t9
    ctx->r2 = ADD32(0, ctx->r25);
L_8008BD98:
    // 0x8008BD98: lb          $t0, 0x0($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X0);
    // 0x8008BD9C: addu        $t1, $s6, $v1
    ctx->r9 = ADD32(ctx->r22, ctx->r3);
    // 0x8008BDA0: beq         $t0, $zero, L_8008BDCC
    if (ctx->r8 == 0) {
        // 0x8008BDA4: nop
    
            goto L_8008BDCC;
    }
    // 0x8008BDA4: nop

    // 0x8008BDA8: lb          $t2, 0x0($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X0);
    // 0x8008BDAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008BDB0: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BDB4: mflo        $t4
    ctx->r12 = lo;
    // 0x8008BDB8: addu        $t6, $a1, $t4
    ctx->r14 = ADD32(ctx->r5, ctx->r12);
    // 0x8008BDBC: lh          $t5, 0xC($t6)
    ctx->r13 = MEM_H(ctx->r14, 0XC);
    // 0x8008BDC0: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8008BDC4: sb          $s5, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r21;
    // 0x8008BDC8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
L_8008BDCC:
    // 0x8008BDCC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008BDD0: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8008BDD4: beq         $at, $zero, L_8008BDE4
    if (ctx->r1 == 0) {
        // 0x8008BDD8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008BDE4;
    }
    // 0x8008BDD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008BDDC: beq         $a0, $zero, L_8008BD98
    if (ctx->r4 == 0) {
        // 0x8008BDE0: nop
    
            goto L_8008BD98;
    }
    // 0x8008BDE0: nop

L_8008BDE4:
    // 0x8008BDE4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_8008BDE8:
    // 0x8008BDE8: bgtz        $a2, L_8008BFB0
    if (SIGNED(ctx->r6) > 0) {
        // 0x8008BDEC: sb          $t3, 0x0($s2)
        MEM_B(0X0, ctx->r18) = ctx->r11;
            goto L_8008BFB0;
    }
    // 0x8008BDEC: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
    // 0x8008BDF0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008BDF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008BDF8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008BDFC: sw          $t7, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r15;
    // 0x8008BE00: jal         0x800C06F8
    // 0x8008BE04: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8008BE04: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_2:
    // 0x8008BE08: b           L_8008BFB4
    // 0x8008BE0C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
        goto L_8008BFB4;
    // 0x8008BE0C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008BE10:
    // 0x8008BE10: beq         $t8, $zero, L_8008BE7C
    if (ctx->r24 == 0) {
        // 0x8008BE14: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008BE7C;
    }
    // 0x8008BE14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008BE18: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008BE1C: addiu       $t2, $t2, 0x6DA8
    ctx->r10 = ADD32(ctx->r10, 0X6DA8);
    // 0x8008BE20: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x8008BE24: addu        $s1, $a2, $t2
    ctx->r17 = ADD32(ctx->r6, ctx->r10);
    // 0x8008BE28: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8008BE2C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8008BE30: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
    // 0x8008BE34: beq         $a0, $zero, L_8008BE44
    if (ctx->r4 == 0) {
        // 0x8008BE38: sw          $t1, 0x0($s7)
        MEM_W(0X0, ctx->r23) = ctx->r9;
            goto L_8008BE44;
    }
    // 0x8008BE38: sw          $t1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r9;
    // 0x8008BE3C: jal         0x8000488C
    // 0x8008BE40: nop

    sndp_stop(rdram, ctx);
        goto after_3;
    // 0x8008BE40: nop

    after_3:
L_8008BE44:
    // 0x8008BE44: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8008BE48: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x8008BE4C: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BE50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008BE54: mflo        $t5
    ctx->r13 = lo;
    // 0x8008BE58: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x8008BE5C: lh          $a0, 0xC($t3)
    ctx->r4 = MEM_H(ctx->r11, 0XC);
    // 0x8008BE60: nop

    // 0x8008BE64: addiu       $a0, $a0, 0x87
    ctx->r4 = ADD32(ctx->r4, 0X87);
    // 0x8008BE68: andi        $t7, $a0, 0xFFFF
    ctx->r15 = ctx->r4 & 0XFFFF;
    // 0x8008BE6C: jal         0x80001D04
    // 0x8008BE70: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008BE70: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x8008BE74: b           L_8008BFB4
    // 0x8008BE78: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
        goto L_8008BFB4;
    // 0x8008BE78: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008BE7C:
    // 0x8008BE7C: lb          $t8, 0x0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X0);
    // 0x8008BE80: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x8008BE84: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BE88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008BE8C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008BE90: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BE94: lh          $a0, 0x6DD0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6DD0);
    // 0x8008BE98: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8008BE9C: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    // 0x8008BEA0: addiu       $t9, $zero, 0x15C
    ctx->r25 = ADD32(0, 0X15C);
    // 0x8008BEA4: mflo        $v0
    ctx->r2 = lo;
    // 0x8008BEA8: addu        $s1, $v0, $a1
    ctx->r17 = ADD32(ctx->r2, ctx->r5);
    // 0x8008BEAC: blez        $a0, L_8008BEDC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8008BEB0: nop
    
            goto L_8008BEDC;
    }
    // 0x8008BEB0: nop

    // 0x8008BEB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BEB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8008BEBC: jal         0x8008C4A0
    // 0x8008BEC0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    charselect_move(rdram, ctx);
        goto after_5;
    // 0x8008BEC0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_5:
    // 0x8008BEC4: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BEC8: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BECC: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x8008BED0: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x8008BED4: b           L_8008BF8C
    // 0x8008BED8: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
        goto L_8008BF8C;
    // 0x8008BED8: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
L_8008BEDC:
    // 0x8008BEDC: bgez        $a0, L_8008BF14
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8008BEE0: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_8008BF14;
    }
    // 0x8008BEE0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8008BEE4: addiu       $t1, $zero, 0x15C
    ctx->r9 = ADD32(0, 0X15C);
    // 0x8008BEE8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008BEEC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BEF0: addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    // 0x8008BEF4: jal         0x8008C4A0
    // 0x8008BEF8: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    charselect_move(rdram, ctx);
        goto after_6;
    // 0x8008BEF8: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    after_6:
    // 0x8008BEFC: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BF00: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BF04: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x8008BF08: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x8008BF0C: b           L_8008BF8C
    // 0x8008BF10: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
        goto L_8008BF8C;
    // 0x8008BF10: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
L_8008BF14:
    // 0x8008BF14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008BF18: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8008BF1C: lh          $a0, 0x6DB8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6DB8);
    // 0x8008BF20: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8008BF24: bgez        $a0, L_8008BF58
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8008BF28: addiu       $a3, $zero, 0xEC
        ctx->r7 = ADD32(0, 0XEC);
            goto L_8008BF58;
    }
    // 0x8008BF28: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    // 0x8008BF2C: addiu       $t6, $zero, 0x15C
    ctx->r14 = ADD32(0, 0X15C);
    // 0x8008BF30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008BF34: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BF38: jal         0x8008C4A0
    // 0x8008BF3C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    charselect_move(rdram, ctx);
        goto after_7;
    // 0x8008BF3C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_7:
    // 0x8008BF40: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BF44: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BF48: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x8008BF4C: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x8008BF50: b           L_8008BF8C
    // 0x8008BF54: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
        goto L_8008BF8C;
    // 0x8008BF54: sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12 << 1);
L_8008BF58:
    // 0x8008BF58: blez        $a0, L_8008BF8C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8008BF5C: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_8008BF8C;
    }
    // 0x8008BF5C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8008BF60: addiu       $t5, $zero, 0x15C
    ctx->r13 = ADD32(0, 0X15C);
    // 0x8008BF64: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008BF68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008BF6C: addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    // 0x8008BF70: jal         0x8008C4A0
    // 0x8008BF74: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    charselect_move(rdram, ctx);
        goto after_8;
    // 0x8008BF74: addiu       $a3, $zero, 0xEC
    ctx->r7 = ADD32(0, 0XEC);
    after_8:
    // 0x8008BF78: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8008BF7C: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x8008BF80: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x8008BF84: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x8008BF88: sll         $v0, $t3, 1
    ctx->r2 = S32(ctx->r11 << 1);
L_8008BF8C:
    // 0x8008BF8C: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x8008BF90: lh          $v1, 0xC($t7)
    ctx->r3 = MEM_H(ctx->r15, 0XC);
    // 0x8008BF94: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
    // 0x8008BF98: nop

    // 0x8008BF9C: beq         $t8, $v1, L_8008BFB4
    if (ctx->r24 == ctx->r3) {
        // 0x8008BFA0: lw          $v0, 0x4C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X4C);
            goto L_8008BFB4;
    }
    // 0x8008BFA0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8008BFA4: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x8008BFA8: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8008BFAC: sb          $s5, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r21;
L_8008BFB0:
    // 0x8008BFB0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_8008BFB4:
    // 0x8008BFB4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8008BFB8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008BFBC: bne         $s4, $at, L_8008BC6C
    if (ctx->r20 != ctx->r1) {
        // 0x8008BFC0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008BC6C;
    }
    // 0x8008BFC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008BFC4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8008BFC8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008BFCC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8008BFD0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008BFD4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8008BFD8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008BFDC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8008BFE0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008BFE4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8008BFE8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8008BFEC: jr          $ra
    // 0x8008BFF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8008BFF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _loadBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800646E0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800646E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800646E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800646EC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800646F0: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800646F4: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800646F8: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800646FC: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80064700: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80064704: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80064708: beq         $at, $zero, L_80064714
    if (ctx->r1 == 0) {
        // 0x8006470C: addu        $t0, $v0, $t7
        ctx->r8 = ADD32(ctx->r2, ctx->r15);
            goto L_80064714;
    }
    // 0x8006470C: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x80064710: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
L_80064714:
    // 0x80064714: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80064718: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8006471C: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80064720: addu        $a3, $t8, $a1
    ctx->r7 = ADD32(ctx->r24, ctx->r5);
    // 0x80064724: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x80064728: beq         $at, $zero, L_80064808
    if (ctx->r1 == 0) {
        // 0x8006472C: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_80064808;
    }
    // 0x8006472C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80064730: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80064734: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80064738: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x8006473C: sra         $t6, $t1, 1
    ctx->r14 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80064740: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80064744: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80064748: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8006474C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80064750: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80064754: addiu       $s0, $t9, 0x8
    ctx->r16 = ADD32(ctx->r25, 0X8);
    // 0x80064758: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006475C: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x80064760: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80064764: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x80064768: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8006476C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80064770: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80064774: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80064778: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8006477C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80064780: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064784: jal         0x800C9250
    // 0x80064788: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80064788: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8006478C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80064790: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80064794: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80064798: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8006479C: sw          $v0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r2;
    // 0x800647A0: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800647A4: subu        $t7, $a3, $t0
    ctx->r15 = SUB32(ctx->r7, ctx->r8);
    // 0x800647A8: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800647AC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800647B0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800647B4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800647B8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800647BC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800647C0: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800647C4: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x800647C8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800647CC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800647D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800647D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800647D8: lui         $t4, 0x400
    ctx->r12 = S32(0X400 << 16);
    // 0x800647DC: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800647E0: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800647E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800647E8: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x800647EC: jal         0x800C9250
    // 0x800647F0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800647F0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800647F4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800647F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800647FC: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80064800: b           L_80064854
    // 0x80064804: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
        goto L_80064854;
    // 0x80064804: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
L_80064808:
    // 0x80064808: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8006480C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80064810: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80064814: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80064818: addiu       $s0, $t6, 0x8
    ctx->r16 = ADD32(ctx->r14, 0X8);
    // 0x8006481C: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
    // 0x80064820: sw          $a3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r7;
    // 0x80064824: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80064828: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8006482C: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x80064830: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80064834: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80064838: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8006483C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80064840: jal         0x800C9250
    // 0x80064844: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80064844: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80064848: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8006484C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80064850: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80064854:
    // 0x80064854: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80064858: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x8006485C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80064860: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80064864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80064868: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x8006486C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064870: jr          $ra
    // 0x80064874: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80064874: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void enable_new_screen_transitions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0690: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C0694: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0698: jr          $ra
    // 0x800C069C: sw          $t6, 0x3730($at)
    MEM_W(0X3730, ctx->r1) = ctx->r14;
    return;
    // 0x800C069C: sw          $t6, 0x3730($at)
    MEM_W(0X3730, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void path_update_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001136C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80011370: lw          $t6, -0x4CD4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CD4);
    // 0x80011374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011378: beq         $t6, $zero, L_80011388
    if (ctx->r14 == 0) {
        // 0x8001137C: nop
    
            goto L_80011388;
    }
    // 0x8001137C: nop

    // 0x80011380: jr          $ra
    // 0x80011384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80011384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011388:
    // 0x80011388: jr          $ra
    // 0x8001138C: nop

    return;
    // 0x8001138C: nop

;}
RECOMP_FUNC void load_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C46D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C46D4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C46D8: lw          $t6, -0x5260($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5260);
    // 0x800C46DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C46E0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C46E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C46E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C46EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C46F0: beq         $at, $zero, L_800C4770
    if (ctx->r1 == 0) {
        // 0x800C46F4: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800C4770;
    }
    // 0x800C46F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C46F8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C46FC: lw          $t8, -0x525C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X525C);
    // 0x800C4700: sll         $t7, $a0, 10
    ctx->r15 = S32(ctx->r4 << 10);
    // 0x800C4704: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800C4708: lbu         $t9, 0x28($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X28);
    // 0x800C470C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C4710: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C4714: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800C4718: bne         $t1, $at, L_800C4770
    if (ctx->r9 != ctx->r1) {
        // 0x800C471C: sb          $t0, 0x28($v0)
        MEM_B(0X28, ctx->r2) = ctx->r8;
            goto L_800C4770;
    }
    // 0x800C471C: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x800C4720: lh          $t2, 0x40($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X40);
    // 0x800C4724: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800C4728: beq         $s3, $t2, L_800C4770
    if (ctx->r19 == ctx->r10) {
        // 0x800C472C: sll         $s0, $zero, 1
        ctx->r16 = S32(0 << 1);
            goto L_800C4770;
    }
    // 0x800C472C: sll         $s0, $zero, 1
    ctx->r16 = S32(0 << 1);
    // 0x800C4730: addu        $s1, $v0, $s0
    ctx->r17 = ADD32(ctx->r2, ctx->r16);
    // 0x800C4734: sll         $t3, $zero, 2
    ctx->r11 = S32(0 << 2);
    // 0x800C4738: lh          $a0, 0x40($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X40);
    // 0x800C473C: addu        $s2, $v0, $t3
    ctx->r18 = ADD32(ctx->r2, ctx->r11);
L_800C4740:
    // 0x800C4740: jal         0x8007B2C4
    // 0x800C4744: nop

    load_texture(rdram, ctx);
        goto after_0;
    // 0x800C4744: nop

    after_0:
    // 0x800C4748: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800C474C: slti        $at, $s0, 0x40
    ctx->r1 = SIGNED(ctx->r16) < 0X40 ? 1 : 0;
    // 0x800C4750: sw          $v0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r2;
    // 0x800C4754: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C4758: beq         $at, $zero, L_800C4770
    if (ctx->r1 == 0) {
        // 0x800C475C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800C4770;
    }
    // 0x800C475C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C4760: lh          $a0, 0x40($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X40);
    // 0x800C4764: nop

    // 0x800C4768: bne         $s3, $a0, L_800C4740
    if (ctx->r19 != ctx->r4) {
        // 0x800C476C: nop
    
            goto L_800C4740;
    }
    // 0x800C476C: nop

L_800C4770:
    // 0x800C4770: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4774: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C4778: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C477C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4780: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C4784: jr          $ra
    // 0x800C4788: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C4788: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_loop_wizpigship(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037DB8: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x80037DBC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80037DC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037DC4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80037DC8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80037DCC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80037DD0: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80037DD4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80037DD8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80037DDC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80037DE0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80037DE4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80037DE8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80037DEC: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80037DF0: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80037DF4: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80037DF8: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80037DFC: jal         0x8001F494
    // 0x80037E00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80037E00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80037E04: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    // 0x80037E08: nop

    // 0x80037E0C: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x80037E10: nop

    // 0x80037E14: beq         $v1, $zero, L_800380FC
    if (ctx->r3 == 0) {
        // 0x80037E18: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800380FC;
    }
    // 0x80037E18: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80037E1C: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80037E20: lw          $s3, 0x0($v1)
    ctx->r19 = MEM_W(ctx->r3, 0X0);
    // 0x80037E24: blez        $v0, L_80037E34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80037E28: subu        $t7, $v0, $s1
        ctx->r15 = SUB32(ctx->r2, ctx->r17);
            goto L_80037E34;
    }
    // 0x80037E28: subu        $t7, $v0, $s1
    ctx->r15 = SUB32(ctx->r2, ctx->r17);
    // 0x80037E2C: b           L_80037E38
    // 0x80037E30: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
        goto L_80037E38;
    // 0x80037E30: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
L_80037E34:
    // 0x80037E34: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_80037E38:
    // 0x80037E38: lw          $t8, 0x60($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X60);
    // 0x80037E3C: nop

    // 0x80037E40: beq         $t8, $zero, L_800380FC
    if (ctx->r24 == 0) {
        // 0x80037E44: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800380FC;
    }
    // 0x80037E44: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80037E48: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x80037E4C: nop

    // 0x80037E50: bne         $t9, $zero, L_800380FC
    if (ctx->r25 != 0) {
        // 0x80037E54: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800380FC;
    }
    // 0x80037E54: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80037E58: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80037E5C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80037E60: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80037E64: beq         $t2, $zero, L_800380F8
    if (ctx->r10 == 0) {
        // 0x80037E68: addiu       $a0, $sp, 0xCC
        ctx->r4 = ADD32(ctx->r29, 0XCC);
            goto L_800380F8;
    }
    // 0x80037E68: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80037E6C: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x80037E70: jal         0x8006FE70
    // 0x80037E74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mtxf_from_transform(rdram, ctx);
        goto after_1;
    // 0x80037E74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80037E78: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80037E7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80037E80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037E84: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x80037E88: swc1        $f20, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f20.u32l;
    // 0x80037E8C: swc1        $f20, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f20.u32l;
    // 0x80037E90: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80037E94: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x80037E98: addiu       $s4, $sp, 0x8C
    ctx->r20 = ADD32(ctx->r29, 0X8C);
    // 0x80037E9C: sh          $t4, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r12;
    // 0x80037EA0: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x80037EA4: sh          $zero, 0x70($sp)
    MEM_H(0X70, ctx->r29) = 0;
    // 0x80037EA8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80037EAC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80037EB0: jal         0x8006FE70
    // 0x80037EB4: sh          $t5, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r13;
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x80037EB4: sh          $t5, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r13;
    after_2:
    // 0x80037EB8: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80037EBC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80037EC0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80037EC4: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80037EC8: blez        $t6, L_800380F8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80037ECC: addiu       $fp, $sp, 0x84
        ctx->r30 = ADD32(ctx->r29, 0X84);
            goto L_800380F8;
    }
    // 0x80037ECC: addiu       $fp, $sp, 0x84
    ctx->r30 = ADD32(ctx->r29, 0X84);
    // 0x80037ED0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80037ED4: addiu       $s7, $sp, 0x114
    ctx->r23 = ADD32(ctx->r29, 0X114);
    // 0x80037ED8: addiu       $s6, $sp, 0x118
    ctx->r22 = ADD32(ctx->r29, 0X118);
    // 0x80037EDC: addiu       $s5, $sp, 0x11C
    ctx->r21 = ADD32(ctx->r29, 0X11C);
    // 0x80037EE0: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_80037EE4:
    // 0x80037EE4: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x80037EE8: nop

    // 0x80037EEC: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80037EF0: lb          $v1, 0x0($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X0);
    // 0x80037EF4: nop

    // 0x80037EF8: bltz        $v1, L_800380DC
    if (SIGNED(ctx->r3) < 0) {
        // 0x80037EFC: nop
    
            goto L_800380DC;
    }
    // 0x80037EFC: nop

    // 0x80037F00: lh          $t9, 0x18($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X18);
    // 0x80037F04: nop

    // 0x80037F08: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80037F0C: beq         $at, $zero, L_800380DC
    if (ctx->r1 == 0) {
        // 0x80037F10: nop
    
            goto L_800380DC;
    }
    // 0x80037F10: nop

    // 0x80037F14: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x80037F18: nop

    // 0x80037F1C: beq         $t0, $zero, L_800380DC
    if (ctx->r8 == 0) {
        // 0x80037F20: nop
    
            goto L_800380DC;
    }
    // 0x80037F20: nop

    // 0x80037F24: lw          $t1, 0x14($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X14);
    // 0x80037F28: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80037F2C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80037F30: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80037F34: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80037F38: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037F3C: mflo        $t4
    ctx->r12 = lo;
    // 0x80037F40: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80037F44: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80037F48: nop

    // 0x80037F4C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80037F50: nop

    // 0x80037F54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80037F58: swc1        $f8, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f8.u32l;
    // 0x80037F5C: lw          $t8, 0x14($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X14);
    // 0x80037F60: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x80037F64: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80037F68: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x80037F6C: lw          $a1, 0x11C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X11C);
    // 0x80037F70: multu       $t1, $s2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037F74: mflo        $t2
    ctx->r10 = lo;
    // 0x80037F78: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x80037F7C: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80037F80: nop

    // 0x80037F84: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80037F88: nop

    // 0x80037F8C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80037F90: swc1        $f16, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f16.u32l;
    // 0x80037F94: lw          $t6, 0x14($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X14);
    // 0x80037F98: lw          $t5, 0x44($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X44);
    // 0x80037F9C: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x80037FA0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80037FA4: lw          $a2, 0x118($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X118);
    // 0x80037FA8: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037FAC: mflo        $t1
    ctx->r9 = lo;
    // 0x80037FB0: addu        $t7, $t5, $t1
    ctx->r15 = ADD32(ctx->r13, ctx->r9);
    // 0x80037FB4: lh          $t2, 0x4($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X4);
    // 0x80037FB8: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x80037FBC: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80037FC0: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80037FC4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80037FC8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80037FCC: swc1        $f4, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f4.u32l;
    // 0x80037FD0: lw          $a3, 0x114($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X114);
    // 0x80037FD4: jal         0x8006F88C
    // 0x80037FD8: nop

    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x80037FD8: nop

    after_3:
    // 0x80037FDC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80037FE0: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80037FE4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80037FE8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037FEC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037FF0: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80037FF4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80037FF8: lwc1        $f18, 0x114($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80037FFC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80038000: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80038004: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80038008: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003800C: addiu       $t7, $zero, 0xC6
    ctx->r15 = ADD32(0, 0XC6);
    // 0x80038010: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80038014: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80038018: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003801C: sb          $t1, 0x85($sp)
    MEM_B(0X85, ctx->r29) = ctx->r9;
    // 0x80038020: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80038024: sb          $t7, 0x84($sp)
    MEM_B(0X84, ctx->r29) = ctx->r15;
    // 0x80038028: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003802C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80038030: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80038034: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80038038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003803C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80038040: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80038044: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80038048: sh          $t4, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r12;
    // 0x8003804C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80038050: sh          $t8, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r24;
    // 0x80038054: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80038058: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8003805C: jal         0x8000EA54
    // 0x80038060: sh          $t5, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r13;
    spawn_object(rdram, ctx);
        goto after_4;
    // 0x80038060: sh          $t5, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r13;
    after_4:
    // 0x80038064: beq         $v0, $zero, L_800380DC
    if (ctx->r2 == 0) {
        // 0x80038068: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_800380DC;
    }
    // 0x80038068: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003806C: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80038070: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x80038074: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80038078: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x8003807C: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x80038080: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80038084: sw          $t8, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r24;
    // 0x80038088: negu        $t6, $t4
    ctx->r14 = SUB32(0, ctx->r12);
    // 0x8003808C: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x80038090: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80038094: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80038098: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8003809C: addiu       $t9, $v0, 0x1C
    ctx->r25 = ADD32(ctx->r2, 0X1C);
    // 0x800380A0: addiu       $t5, $v0, 0x20
    ctx->r13 = ADD32(ctx->r2, 0X20);
    // 0x800380A4: addiu       $t1, $v0, 0x24
    ctx->r9 = ADD32(ctx->r2, 0X24);
    // 0x800380A8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800380AC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800380B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800380B4: jal         0x8006F88C
    // 0x800380B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtxf_transform_point(rdram, ctx);
        goto after_5;
    // 0x800380B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x800380BC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800380C0: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800380C4: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x800380C8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800380CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800380D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800380D4: jal         0x80009558
    // 0x800380D8: addiu       $a0, $zero, 0x133
    ctx->r4 = ADD32(0, 0X133);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_6;
    // 0x800380D8: addiu       $a0, $zero, 0x133
    ctx->r4 = ADD32(0, 0X133);
    after_6:
L_800380DC:
    // 0x800380DC: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x800380E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800380E4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800380E8: nop

    // 0x800380EC: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800380F0: bne         $at, $zero, L_80037EE4
    if (ctx->r1 != 0) {
        // 0x800380F4: nop
    
            goto L_80037EE4;
    }
    // 0x800380F4: nop

L_800380F8:
    // 0x800380F8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800380FC:
    // 0x800380FC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80038100: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80038104: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80038108: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8003810C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80038110: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80038114: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80038118: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8003811C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80038120: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80038124: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80038128: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8003812C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80038130: jr          $ra
    // 0x80038134: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x80038134: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void obj_loop_animobject(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037D30: jal         0x8001F494
    // 0x80037D34: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80037D34: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x80037D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037D3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037D40: jr          $ra
    // 0x80037D44: nop

    return;
    // 0x80037D44: nop

;}
RECOMP_FUNC void obj_loop_unknown25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038AB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038AC0: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80038AC4: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80038AC8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80038ACC: sh          $t8, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r24;
    // 0x80038AD0: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
    // 0x80038AD4: nop

    // 0x80038AD8: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80038ADC: bne         $at, $zero, L_80038AFC
    if (ctx->r1 != 0) {
        // 0x80038AE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038AFC;
    }
    // 0x80038AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038AE4: jal         0x8000FFB8
    // 0x80038AE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    free_object(rdram, ctx);
        goto after_0;
    // 0x80038AE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038AEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038AF0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80038AF4: sh          $t0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r8;
    // 0x80038AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038AFC:
    // 0x80038AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038B00: jr          $ra
    // 0x80038B04: nop

    return;
    // 0x80038B04: nop

;}
