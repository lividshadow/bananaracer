#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void _bcopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA300: beq         $a2, $zero, L_800CA36C
    if (ctx->r6 == 0) {
        // 0x800CA304: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800CA36C;
    }
    // 0x800CA304: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CA308: beq         $a0, $a1, L_800CA36C
    if (ctx->r4 == ctx->r5) {
        // 0x800CA30C: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800CA36C;
    }
    // 0x800CA30C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CA310: bnel        $at, $zero, L_800CA334
    if (ctx->r1 != 0) {
        // 0x800CA314: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CA334;
    }
    goto skip_0;
    // 0x800CA314: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x800CA318: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x800CA31C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CA320: beql        $at, $zero, L_800CA334
    if (ctx->r1 == 0) {
        // 0x800CA324: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CA334;
    }
    goto skip_1;
    // 0x800CA324: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x800CA328: b           L_800CA498
    // 0x800CA32C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_800CA498;
    // 0x800CA32C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800CA330: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CA334:
    // 0x800CA334: bne         $at, $zero, L_800CA34C
    if (ctx->r1 != 0) {
        // 0x800CA338: nop
    
            goto L_800CA34C;
    }
    // 0x800CA338: nop

    // 0x800CA33C: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800CA340: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800CA344: beq         $v0, $v1, L_800CA374
    if (ctx->r2 == ctx->r3) {
        // 0x800CA348: nop
    
            goto L_800CA374;
    }
    // 0x800CA348: nop

L_800CA34C:
    // 0x800CA34C: beq         $a2, $zero, L_800CA36C
    if (ctx->r6 == 0) {
        // 0x800CA350: nop
    
            goto L_800CA36C;
    }
    // 0x800CA350: nop

    // 0x800CA354: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_800CA358:
    // 0x800CA358: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CA35C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CA360: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CA364: bne         $a0, $v1, L_800CA358
    if (ctx->r4 != ctx->r3) {
        // 0x800CA368: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_800CA358;
    }
    // 0x800CA368: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_800CA36C:
    // 0x800CA36C: jr          $ra
    // 0x800CA370: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800CA370: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800CA374:
    // 0x800CA374: beq         $v0, $zero, L_800CA3D8
    if (ctx->r2 == 0) {
        // 0x800CA378: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800CA3D8;
    }
    // 0x800CA378: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CA37C: beq         $v0, $at, L_800CA3BC
    if (ctx->r2 == ctx->r1) {
        // 0x800CA380: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CA3BC;
    }
    // 0x800CA380: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CA384: beql        $v0, $at, L_800CA3A8
    if (ctx->r2 == ctx->r1) {
        // 0x800CA388: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_800CA3A8;
    }
    goto skip_2;
    // 0x800CA388: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x800CA38C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CA390: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CA394: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CA398: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800CA39C: b           L_800CA3D8
    // 0x800CA3A0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_800CA3D8;
    // 0x800CA3A0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x800CA3A4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_800CA3A8:
    // 0x800CA3A8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800CA3AC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800CA3B0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800CA3B4: b           L_800CA3D8
    // 0x800CA3B8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_800CA3D8;
    // 0x800CA3B8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_800CA3BC:
    // 0x800CA3BC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CA3C0: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x800CA3C4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800CA3C8: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800CA3CC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800CA3D0: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x800CA3D4: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_800CA3D8:
    // 0x800CA3D8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800CA3DC: bnel        $at, $zero, L_800CA438
    if (ctx->r1 != 0) {
        // 0x800CA3E0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CA438;
    }
    goto skip_3;
    // 0x800CA3E0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x800CA3E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CA3E8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800CA3EC: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800CA3F0: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800CA3F4: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x800CA3F8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800CA3FC: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x800CA400: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x800CA404: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800CA408: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800CA40C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800CA410: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x800CA414: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x800CA418: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x800CA41C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x800CA420: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x800CA424: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x800CA428: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x800CA42C: b           L_800CA3D8
    // 0x800CA430: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_800CA3D8;
    // 0x800CA430: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_800CA434:
    // 0x800CA434: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CA438:
    // 0x800CA438: bnel        $at, $zero, L_800CA474
    if (ctx->r1 != 0) {
        // 0x800CA43C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800CA474;
    }
    goto skip_4;
    // 0x800CA43C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x800CA440: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CA444: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800CA448: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800CA44C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800CA450: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800CA454: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800CA458: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800CA45C: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x800CA460: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x800CA464: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x800CA468: b           L_800CA434
    // 0x800CA46C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_800CA434;
    // 0x800CA46C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_800CA470:
    // 0x800CA470: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800CA474:
    // 0x800CA474: bne         $at, $zero, L_800CA34C
    if (ctx->r1 != 0) {
        // 0x800CA478: nop
    
            goto L_800CA34C;
    }
    // 0x800CA478: nop

    // 0x800CA47C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CA480: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800CA484: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800CA488: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800CA48C: b           L_800CA470
    // 0x800CA490: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_800CA470;
    // 0x800CA490: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x800CA494: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CA498:
    // 0x800CA498: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800CA49C: bne         $at, $zero, L_800CA4B4
    if (ctx->r1 != 0) {
        // 0x800CA4A0: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_800CA4B4;
    }
    // 0x800CA4A0: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800CA4A4: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800CA4A8: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800CA4AC: beq         $v0, $v1, L_800CA4E4
    if (ctx->r2 == ctx->r3) {
        // 0x800CA4B0: nop
    
            goto L_800CA4E4;
    }
    // 0x800CA4B0: nop

L_800CA4B4:
    // 0x800CA4B4: beq         $a2, $zero, L_800CA36C
    if (ctx->r6 == 0) {
        // 0x800CA4B8: nop
    
            goto L_800CA36C;
    }
    // 0x800CA4B8: nop

    // 0x800CA4BC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CA4C0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CA4C4: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_800CA4C8:
    // 0x800CA4C8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800CA4CC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CA4D0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CA4D4: bne         $a0, $v1, L_800CA4C8
    if (ctx->r4 != ctx->r3) {
        // 0x800CA4D8: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_800CA4C8;
    }
    // 0x800CA4D8: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x800CA4DC: jr          $ra
    // 0x800CA4E0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800CA4E0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800CA4E4:
    // 0x800CA4E4: beq         $v0, $zero, L_800CA548
    if (ctx->r2 == 0) {
        // 0x800CA4E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800CA548;
    }
    // 0x800CA4E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CA4EC: beq         $v0, $at, L_800CA52C
    if (ctx->r2 == ctx->r1) {
        // 0x800CA4F0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CA52C;
    }
    // 0x800CA4F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CA4F4: beql        $v0, $at, L_800CA518
    if (ctx->r2 == ctx->r1) {
        // 0x800CA4F8: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_800CA518;
    }
    goto skip_5;
    // 0x800CA4F8: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x800CA4FC: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800CA500: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CA504: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800CA508: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800CA50C: b           L_800CA548
    // 0x800CA510: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_800CA548;
    // 0x800CA510: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800CA514: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_800CA518:
    // 0x800CA518: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x800CA51C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800CA520: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800CA524: b           L_800CA548
    // 0x800CA528: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_800CA548;
    // 0x800CA528: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_800CA52C:
    // 0x800CA52C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800CA530: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x800CA534: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x800CA538: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x800CA53C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800CA540: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x800CA544: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_800CA548:
    // 0x800CA548: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800CA54C: bnel        $at, $zero, L_800CA5A8
    if (ctx->r1 != 0) {
        // 0x800CA550: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800CA5A8;
    }
    goto skip_6;
    // 0x800CA550: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x800CA554: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CA558: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800CA55C: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800CA560: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800CA564: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x800CA568: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x800CA56C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x800CA570: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x800CA574: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x800CA578: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x800CA57C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800CA580: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x800CA584: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x800CA588: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x800CA58C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x800CA590: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x800CA594: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800CA598: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800CA59C: b           L_800CA548
    // 0x800CA5A0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_800CA548;
    // 0x800CA5A0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800CA5A4:
    // 0x800CA5A4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800CA5A8:
    // 0x800CA5A8: bnel        $at, $zero, L_800CA5E4
    if (ctx->r1 != 0) {
        // 0x800CA5AC: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800CA5E4;
    }
    goto skip_7;
    // 0x800CA5AC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x800CA5B0: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CA5B4: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800CA5B8: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800CA5BC: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800CA5C0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800CA5C4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800CA5C8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800CA5CC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x800CA5D0: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x800CA5D4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800CA5D8: b           L_800CA5A4
    // 0x800CA5DC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_800CA5A4;
    // 0x800CA5DC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_800CA5E0:
    // 0x800CA5E0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800CA5E4:
    // 0x800CA5E4: bne         $at, $zero, L_800CA4B4
    if (ctx->r1 != 0) {
        // 0x800CA5E8: nop
    
            goto L_800CA4B4;
    }
    // 0x800CA5E8: nop

    // 0x800CA5EC: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800CA5F0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800CA5F4: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800CA5F8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800CA5FC: b           L_800CA5E0
    // 0x800CA600: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_800CA5E0;
    // 0x800CA600: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void obj_loop_laserbolt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800348A0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800348A4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800348A8: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800348AC: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800348B0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800348B4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800348B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800348BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800348C0: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800348C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800348C8: bne         $t7, $zero, L_800348E8
    if (ctx->r15 != 0) {
        // 0x800348CC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800348E8;
    }
    // 0x800348CC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800348D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800348D4: lwc1        $f9, 0x6588($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6588);
    // 0x800348D8: lwc1        $f8, 0x658C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X658C);
    // 0x800348DC: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800348E0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800348E4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800348E8:
    // 0x800348E8: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800348EC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800348F0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800348F4: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800348F8: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x800348FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80034900: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80034904: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80034908: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x8003490C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80034910: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034914: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80034918: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8003491C: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80034920: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80034924: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x80034928: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003492C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034930: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80034934: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80034938: sb          $t0, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r8;
    // 0x8003493C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80034940: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80034944: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80034948: jal         0x80031170
    // 0x8003494C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_0;
    // 0x8003494C: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80034950: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80034954: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80034958: addiu       $t9, $sp, 0x38
    ctx->r25 = ADD32(ctx->r29, 0X38);
    // 0x8003495C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80034960: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80034964: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80034968: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8003496C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80034970: jal         0x80031640
    // 0x80034974: addiu       $a3, $sp, 0x4E
    ctx->r7 = ADD32(ctx->r29, 0X4E);
    resolve_collisions(rdram, ctx);
        goto after_1;
    // 0x80034974: addiu       $a3, $sp, 0x4E
    ctx->r7 = ADD32(ctx->r29, 0X4E);
    after_1:
    // 0x80034978: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8003497C: lb          $t0, 0x4F($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X4F);
    // 0x80034980: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80034984: beq         $t1, $zero, L_800349D8
    if (ctx->r9 == 0) {
        // 0x80034988: nop
    
            goto L_800349D8;
    }
    // 0x80034988: nop

    // 0x8003498C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80034990: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034994: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034998: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003499C: nop

    // 0x800349A0: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800349A4: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800349A8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800349AC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800349B0: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800349B4: nop

    // 0x800349B8: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800349BC: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800349C0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800349C4: nop

    // 0x800349C8: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800349CC: nop

    // 0x800349D0: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800349D4: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_800349D8:
    // 0x800349D8: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800349DC: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800349E0: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800349E4: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800349E8: sb          $t0, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r8;
    // 0x800349EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800349F0: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800349F4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800349F8: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800349FC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80034A00: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80034A04: jal         0x80011570
    // 0x80034A08: nop

    move_object(rdram, ctx);
        goto after_2;
    // 0x80034A08: nop

    after_2:
    // 0x80034A0C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80034A10: lb          $t0, 0x4F($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X4F);
    // 0x80034A14: beq         $t2, $zero, L_80034A50
    if (ctx->r10 == 0) {
        // 0x80034A18: lui         $at, 0x4210
        ctx->r1 = S32(0X4210 << 16);
            goto L_80034A50;
    }
    // 0x80034A18: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80034A1C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034A20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80034A24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034A28: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034A2C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80034A30: lwc1        $f4, 0x6590($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6590);
    // 0x80034A34: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80034A38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80034A3C: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80034A40: sub.s       $f14, $f16, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80034A44: jal         0x8003FC84
    // 0x80034A48: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_3;
    // 0x80034A48: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80034A4C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80034A50:
    // 0x80034A50: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80034A54: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80034A58: blez        $v0, L_80034A68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80034A5C: subu        $t4, $v0, $t3
        ctx->r12 = SUB32(ctx->r2, ctx->r11);
            goto L_80034A68;
    }
    // 0x80034A5C: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x80034A60: b           L_80034A6C
    // 0x80034A64: sw          $t4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r12;
        goto L_80034A6C;
    // 0x80034A64: sw          $t4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r12;
L_80034A68:
    // 0x80034A68: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80034A6C:
    // 0x80034A6C: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x80034A70: nop

    // 0x80034A74: lbu         $t5, 0x13($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X13);
    // 0x80034A78: nop

    // 0x80034A7C: slti        $at, $t5, 0x50
    ctx->r1 = SIGNED(ctx->r13) < 0X50 ? 1 : 0;
    // 0x80034A80: beq         $at, $zero, L_80034B10
    if (ctx->r1 == 0) {
        // 0x80034A84: nop
    
            goto L_80034B10;
    }
    // 0x80034A84: nop

    // 0x80034A88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80034A8C: nop

    // 0x80034A90: beq         $v0, $zero, L_80034B10
    if (ctx->r2 == 0) {
        // 0x80034A94: nop
    
            goto L_80034B10;
    }
    // 0x80034A94: nop

    // 0x80034A98: lh          $t6, 0x48($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X48);
    // 0x80034A9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80034AA0: bne         $a0, $t6, L_80034B10
    if (ctx->r4 != ctx->r14) {
        // 0x80034AA4: addiu       $a3, $zero, 0x2C
        ctx->r7 = ADD32(0, 0X2C);
            goto L_80034B10;
    }
    // 0x80034AA4: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80034AA8: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80034AAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80034AB0: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80034AB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80034AB8: beq         $t7, $at, L_80034AC4
    if (ctx->r15 == ctx->r1) {
        // 0x80034ABC: addiu       $t9, $zero, 0x11
        ctx->r25 = ADD32(0, 0X11);
            goto L_80034AC4;
    }
    // 0x80034ABC: addiu       $t9, $zero, 0x11
    ctx->r25 = ADD32(0, 0X11);
    // 0x80034AC0: sb          $a0, 0x187($v1)
    MEM_B(0X187, ctx->r3) = ctx->r4;
L_80034AC4:
    // 0x80034AC4: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80034AC8: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x80034ACC: beq         $v0, $zero, L_80034AD8
    if (ctx->r2 == 0) {
        // 0x80034AD0: lui         $at, 0x4210
        ctx->r1 = S32(0X4210 << 16);
            goto L_80034AD8;
    }
    // 0x80034AD0: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80034AD4: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
L_80034AD8:
    // 0x80034AD8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034ADC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80034AE0: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034AE4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80034AE8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80034AEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80034AF0: sb          $t0, 0x4F($sp)
    MEM_B(0X4F, ctx->r29) = ctx->r8;
    // 0x80034AF4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80034AF8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80034AFC: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80034B00: jal         0x8003FC84
    // 0x80034B04: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_4;
    // 0x80034B04: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80034B08: lb          $t0, 0x4F($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X4F);
    // 0x80034B0C: nop

L_80034B10:
    // 0x80034B10: beq         $t0, $zero, L_80034B24
    if (ctx->r8 == 0) {
        // 0x80034B14: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80034B24;
    }
    // 0x80034B14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80034B18: jal         0x8000FFB8
    // 0x80034B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_5;
    // 0x80034B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80034B20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80034B24:
    // 0x80034B24: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80034B28: jr          $ra
    // 0x80034B2C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80034B2C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void level_properties_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C524: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C528: jr          $ra
    // 0x8006C52C: sh          $zero, -0x2768($at)
    MEM_H(-0X2768, ctx->r1) = 0;
    return;
    // 0x8006C52C: sh          $zero, -0x2768($at)
    MEM_H(-0X2768, ctx->r1) = 0;
;}
RECOMP_FUNC void reset_save_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EC9C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006ECA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ECA4: lw          $a0, 0x3A90($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3A90);
    // 0x8006ECA8: jal         0x8006E9B0
    // 0x8006ECAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    clear_lap_records(rdram, ctx);
        goto after_0;
    // 0x8006ECAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x8006ECB0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006ECB4: lw          $a0, 0x3A90($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3A90);
    // 0x8006ECB8: jal         0x8006EBD4
    // 0x8006ECBC: nop

    clear_game_progress(rdram, ctx);
        goto after_1;
    // 0x8006ECBC: nop

    after_1:
    // 0x8006ECC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ECC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ECC8: jr          $ra
    // 0x8006ECCC: nop

    return;
    // 0x8006ECCC: nop

;}
RECOMP_FUNC void update_wizpig(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005EC34: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005EC38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005EC3C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005EC40: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005EC44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005EC48: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005EC4C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005EC50: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8005EC54: jal         0x8005CC18
    // 0x8005EC58: addiu       $a0, $a0, -0x2C30
    ctx->r4 = ADD32(ctx->r4, -0X2C30);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005EC58: addiu       $a0, $a0, -0x2C30
    ctx->r4 = ADD32(ctx->r4, -0X2C30);
    after_0:
    // 0x8005EC5C: sb          $zero, 0x1EC($s0)
    MEM_B(0X1EC, ctx->r16) = 0;
    // 0x8005EC60: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EC64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EC68: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x8005EC6C: lh          $t7, 0x18($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X18);
    // 0x8005EC70: lwc1        $f7, 0x7040($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X7040);
    // 0x8005EC74: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x8005EC78: lh          $t8, 0x16A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X16A);
    // 0x8005EC7C: lwc1        $f6, 0x7044($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7044);
    // 0x8005EC80: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
    // 0x8005EC84: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005EC88: nop

    // 0x8005EC8C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005EC90: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8005EC94: nop

    // 0x8005EC98: bc1f        L_8005ECC0
    if (!c1cs) {
        // 0x8005EC9C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005ECC0;
    }
    // 0x8005EC9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005ECA0: lwc1        $f9, 0x7048($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X7048);
    // 0x8005ECA4: lwc1        $f8, 0x704C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X704C);
    // 0x8005ECA8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8005ECAC: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005ECB0: nop

    // 0x8005ECB4: bc1f        L_8005ECC0
    if (!c1cs) {
        // 0x8005ECB8: nop
    
            goto L_8005ECC0;
    }
    // 0x8005ECB8: nop

    // 0x8005ECBC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8005ECC0:
    // 0x8005ECC0: lb          $t2, 0x1D8($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005ECC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005ECC8: bne         $t2, $at, L_8005ECFC
    if (ctx->r10 != ctx->r1) {
        // 0x8005ECCC: lw          $v1, 0x58($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X58);
            goto L_8005ECFC;
    }
    // 0x8005ECCC: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005ECD0: jal         0x8002359C
    // 0x8005ECD4: nop

    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005ECD4: nop

    after_1:
    // 0x8005ECD8: beq         $v0, $zero, L_8005ECFC
    if (ctx->r2 == 0) {
        // 0x8005ECDC: lw          $v1, 0x58($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X58);
            goto L_8005ECFC;
    }
    // 0x8005ECDC: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005ECE0: jal         0x80021434
    // 0x8005ECE4: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005ECE4: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_2:
    // 0x8005ECE8: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005ECEC: nop

    // 0x8005ECF0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005ECF4: sb          $t4, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r12;
    // 0x8005ECF8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
L_8005ECFC:
    // 0x8005ECFC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005ED00: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8005ED04: nop

    // 0x8005ED08: bne         $t1, $a0, L_8005ED14
    if (ctx->r9 != ctx->r4) {
        // 0x8005ED0C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005ED14;
    }
    // 0x8005ED0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005ED10: sb          $zero, -0x2480($at)
    MEM_B(-0X2480, ctx->r1) = 0;
L_8005ED14:
    // 0x8005ED14: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x8005ED18: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005ED1C: bne         $t0, $t5, L_8005ED98
    if (ctx->r8 != ctx->r13) {
        // 0x8005ED20: sb          $zero, 0x1F5($s0)
        MEM_B(0X1F5, ctx->r16) = 0;
            goto L_8005ED98;
    }
    // 0x8005ED20: sb          $zero, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = 0;
    // 0x8005ED24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005ED28: nop

    // 0x8005ED2C: beq         $a0, $v0, L_8005ED98
    if (ctx->r4 == ctx->r2) {
        // 0x8005ED30: addiu       $t6, $v0, -0x1E
        ctx->r14 = ADD32(ctx->r2, -0X1E);
            goto L_8005ED98;
    }
    // 0x8005ED30: addiu       $t6, $v0, -0x1E
    ctx->r14 = ADD32(ctx->r2, -0X1E);
    // 0x8005ED34: bgez        $t6, L_8005ED90
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005ED38: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8005ED90;
    }
    // 0x8005ED38: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8005ED3C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005ED40: lb          $t8, -0x247F($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X247F);
    // 0x8005ED44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005ED48: bne         $t8, $zero, L_8005ED6C
    if (ctx->r24 != 0) {
        // 0x8005ED4C: lw          $v0, 0x50($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X50);
            goto L_8005ED6C;
    }
    // 0x8005ED4C: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8005ED50: jal         0x8005CCA4
    // 0x8005ED54: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005ED54: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_3:
    // 0x8005ED58: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005ED5C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005ED60: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8005ED64: sb          $t9, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r25;
    // 0x8005ED68: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
L_8005ED6C:
    // 0x8005ED6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005ED70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005ED74: sb          $t2, -0x247F($at)
    MEM_B(-0X247F, ctx->r1) = ctx->r10;
    // 0x8005ED78: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8005ED7C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8005ED80: nop

    // 0x8005ED84: ori         $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 | 0X8000;
    // 0x8005ED88: b           L_8005ED98
    // 0x8005ED8C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8005ED98;
    // 0x8005ED8C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8005ED90:
    // 0x8005ED90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005ED94: sb          $zero, -0x247F($at)
    MEM_B(-0X247F, ctx->r1) = 0;
L_8005ED98:
    // 0x8005ED98: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8005ED9C: sb          $t5, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r13;
    // 0x8005EDA0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8005EDA4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8005EDA8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8005EDAC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005EDB0: jal         0x800497D4
    // 0x8005EDB4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_4;
    // 0x8005EDB4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8005EDB8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8005EDBC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8005EDC0: lb          $t6, 0x1D7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D7);
    // 0x8005EDC4: nop

    // 0x8005EDC8: sb          $t6, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r14;
    // 0x8005EDCC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8005EDD0: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005EDD4: lh          $t7, 0x3A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3A);
    // 0x8005EDD8: nop

    // 0x8005EDDC: sh          $t7, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r15;
    // 0x8005EDE0: lh          $t8, 0x3E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3E);
    // 0x8005EDE4: nop

    // 0x8005EDE8: sb          $t8, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r24;
    // 0x8005EDEC: lh          $t9, 0x3C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X3C);
    // 0x8005EDF0: nop

    // 0x8005EDF4: sh          $t9, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r25;
    // 0x8005EDF8: lb          $t2, 0x187($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X187);
    // 0x8005EDFC: nop

    // 0x8005EE00: beq         $t2, $zero, L_8005EEA0
    if (ctx->r10 == 0) {
        // 0x8005EE04: nop
    
            goto L_8005EEA0;
    }
    // 0x8005EE04: nop

    // 0x8005EE08: lb          $t3, 0x3B($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EE0C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005EE10: beq         $t3, $at, L_8005EEA0
    if (ctx->r11 == ctx->r1) {
        // 0x8005EE14: nop
    
            goto L_8005EEA0;
    }
    // 0x8005EE14: nop

    // 0x8005EE18: jal         0x8005CCA4
    // 0x8005EE1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005EE1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8005EE20: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005EE24: jal         0x80001D04
    // 0x8005EE28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005EE28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005EE2C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005EE30: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005EE34: jal         0x8006A168
    // 0x8005EE38: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005EE38: nop

    after_7:
    // 0x8005EE3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EE40: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005EE44: lwc1        $f1, 0x7050($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X7050);
    // 0x8005EE48: lwc1        $f0, 0x7054($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7054);
    // 0x8005EE4C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005EE50: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005EE54: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005EE58: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005EE5C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005EE60: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8005EE64: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005EE68: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005EE6C: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005EE70: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x8005EE74: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005EE78: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005EE7C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005EE80: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x8005EE84: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005EE88: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005EE8C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005EE90: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005EE94: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005EE98: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005EE9C: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
L_8005EEA0:
    // 0x8005EEA0: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005EEA4: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005EEA8: beq         $t5, $zero, L_8005EF10
    if (ctx->r13 == 0) {
        // 0x8005EEAC: nop
    
            goto L_8005EF10;
    }
    // 0x8005EEAC: nop

    // 0x8005EEB0: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005EEB4: lwc1        $f14, 0x24($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005EEB8: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005EEBC: nop

    // 0x8005EEC0: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005EEC4: nop

    // 0x8005EEC8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005EECC: nop

    // 0x8005EED0: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8005EED4: jal         0x800CA030
    // 0x8005EED8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005EED8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_8:
    // 0x8005EEDC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8005EEE0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005EEE4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005EEE8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8005EEEC: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8005EEF0: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8005EEF4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005EEF8: bc1f        L_8005EF10
    if (!c1cs) {
        // 0x8005EEFC: swc1        $f2, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
            goto L_8005EF10;
    }
    // 0x8005EEFC: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8005EF00: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8005EF04: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    // 0x8005EF08: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x8005EF0C: swc1        $f18, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f18.u32l;
L_8005EF10:
    // 0x8005EF10: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005EF14: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8005EF18: jal         0x8001BA50
    // 0x8005EF1C: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_9;
    // 0x8005EF1C: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
    after_9:
    // 0x8005EF20: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005EF24: lh          $a2, 0x38($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X38);
    // 0x8005EF28: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8005EF2C: lb          $t8, 0x36($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X36);
    // 0x8005EF30: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005EF34: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005EF38: bne         $t1, $t8, L_8005EF4C
    if (ctx->r9 != ctx->r24) {
        // 0x8005EF3C: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8005EF4C;
    }
    // 0x8005EF3C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005EF40: sll         $a2, $t1, 16
    ctx->r6 = S32(ctx->r9 << 16);
    // 0x8005EF44: sra         $t9, $a2, 16
    ctx->r25 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005EF48: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_8005EF4C:
    // 0x8005EF4C: lh          $t2, 0x2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2);
    // 0x8005EF50: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8005EF54: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8005EF58: sh          $t3, 0x162($s0)
    MEM_H(0X162, ctx->r16) = ctx->r11;
    // 0x8005EF5C: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x8005EF60: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EF64: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8005EF68: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8005EF6C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8005EF70: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005EF74: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x8005EF78: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8005EF7C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8005EF80: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8005EF84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EF88: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8005EF8C: addiu       $t2, $t9, -0x11
    ctx->r10 = ADD32(ctx->r25, -0X11);
    // 0x8005EF90: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8005EF94: lwc1        $f5, 0x7058($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X7058);
    // 0x8005EF98: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005EF9C: lwc1        $f4, 0x705C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X705C);
    // 0x8005EFA0: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8005EFA4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005EFA8: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8005EFAC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005EFB0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8005EFB4: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005EFB8: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x8005EFBC: nop

    // 0x8005EFC0: bc1f        L_8005EFF0
    if (!c1cs) {
        // 0x8005EFC4: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_8005EFF0;
    }
    // 0x8005EFC4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005EFC8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005EFCC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005EFD0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005EFD4: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8005EFD8: nop

    // 0x8005EFDC: bc1f        L_8005F018
    if (!c1cs) {
        // 0x8005EFE0: nop
    
            goto L_8005F018;
    }
    // 0x8005EFE0: nop

    // 0x8005EFE4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005EFE8: b           L_8005F01C
    // 0x8005EFEC: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
        goto L_8005F01C;
    // 0x8005EFEC: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005EFF0:
    // 0x8005EFF0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005EFF4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005EFF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005EFFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005F000: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005F004: nop

    // 0x8005F008: bc1f        L_8005F018
    if (!c1cs) {
        // 0x8005F00C: nop
    
            goto L_8005F018;
    }
    // 0x8005F00C: nop

    // 0x8005F010: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005F014: nop

L_8005F018:
    // 0x8005F018: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005F01C:
    // 0x8005F01C: beq         $at, $zero, L_8005F15C
    if (ctx->r1 == 0) {
        // 0x8005F020: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_8005F15C;
    }
    // 0x8005F020: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8005F024: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F028: addu        $at, $at, $t3
    gpr jr_addend_8005F034 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8005F02C: lw          $t3, 0x7060($at)
    ctx->r11 = ADD32(ctx->r1, 0X7060);
    // 0x8005F030: nop

    // 0x8005F034: jr          $t3
    // 0x8005F038: nop

    switch (jr_addend_8005F034 >> 2) {
        case 0: goto L_8005F03C; break;
        case 1: goto L_8005F060; break;
        case 2: goto L_8005F098; break;
        case 3: goto L_8005F0B4; break;
        case 4: goto L_8005F10C; break;
        case 5: goto L_8005F138; break;
        default: switch_error(__func__, 0x8005F034, 0x800E7060);
    }
    // 0x8005F038: nop

L_8005F03C:
    // 0x8005F03C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F040: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x8005F044: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005F048: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8005F04C: sb          $zero, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = 0;
    // 0x8005F050: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005F054: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005F058: b           L_8005F160
    // 0x8005F05C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_8005F160;
    // 0x8005F05C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_8005F060:
    // 0x8005F060: lbu         $t4, 0x1CD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F064: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005F068: bne         $a0, $t4, L_8005F084
    if (ctx->r4 != ctx->r12) {
        // 0x8005F06C: nop
    
            goto L_8005F084;
    }
    // 0x8005F06C: nop

    // 0x8005F070: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F074: nop

    // 0x8005F078: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8005F07C: b           L_8005F160
    // 0x8005F080: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005F160;
    // 0x8005F080: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005F084:
    // 0x8005F084: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F088: nop

    // 0x8005F08C: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8005F090: b           L_8005F160
    // 0x8005F094: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_8005F160;
    // 0x8005F094: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_8005F098:
    // 0x8005F098: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F09C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8005F0A0: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8005F0A4: sb          $t5, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r13;
    // 0x8005F0A8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8005F0AC: b           L_8005F160
    // 0x8005F0B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005F160;
    // 0x8005F0B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005F0B4:
    // 0x8005F0B4: lbu         $t6, 0x1CD($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F0B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005F0BC: bne         $t6, $at, L_8005F0E8
    if (ctx->r14 != ctx->r1) {
        // 0x8005F0C0: nop
    
            goto L_8005F0E8;
    }
    // 0x8005F0C0: nop

    // 0x8005F0C4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F0C8: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005F0CC: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005F0D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005F0D4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005F0D8: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8005F0DC: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8005F0E0: b           L_8005F160
    // 0x8005F0E4: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005F160;
    // 0x8005F0E4: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005F0E8:
    // 0x8005F0E8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F0EC: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005F0F0: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8005F0F4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005F0F8: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8005F0FC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005F100: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005F104: b           L_8005F160
    // 0x8005F108: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005F160;
    // 0x8005F108: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005F10C:
    // 0x8005F10C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F110: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005F114: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x8005F118: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8005F11C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005F120: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8005F124: sb          $t7, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r15;
    // 0x8005F128: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005F12C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005F130: b           L_8005F160
    // 0x8005F134: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8005F160;
    // 0x8005F134: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_8005F138:
    // 0x8005F138: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F13C: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x8005F140: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x8005F144: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005F148: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8005F14C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005F150: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005F154: b           L_8005F160
    // 0x8005F158: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005F160;
    // 0x8005F158: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005F15C:
    // 0x8005F15C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005F160:
    // 0x8005F160: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F164: nop

    // 0x8005F168: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005F16C: nop

    // 0x8005F170: bc1f        L_8005F19C
    if (!c1cs) {
        // 0x8005F174: nop
    
            goto L_8005F19C;
    }
    // 0x8005F174: nop

L_8005F178:
    // 0x8005F178: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005F17C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005F180: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005F184: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F188: nop

    // 0x8005F18C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005F190: nop

    // 0x8005F194: bc1t        L_8005F178
    if (c1cs) {
        // 0x8005F198: nop
    
            goto L_8005F178;
    }
    // 0x8005F198: nop

L_8005F19C:
    // 0x8005F19C: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F1A0: nop

    // 0x8005F1A4: bc1f        L_8005F1D0
    if (!c1cs) {
        // 0x8005F1A8: nop
    
            goto L_8005F1D0;
    }
    // 0x8005F1A8: nop

L_8005F1AC:
    // 0x8005F1AC: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005F1B0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005F1B4: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005F1B8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F1BC: nop

    // 0x8005F1C0: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8005F1C4: nop

    // 0x8005F1C8: bc1t        L_8005F1AC
    if (c1cs) {
        // 0x8005F1CC: nop
    
            goto L_8005F1AC;
    }
    // 0x8005F1CC: nop

L_8005F1D0:
    // 0x8005F1D0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F1D4: nop

    // 0x8005F1D8: bne         $a0, $v1, L_8005F1F8
    if (ctx->r4 != ctx->r3) {
        // 0x8005F1DC: nop
    
            goto L_8005F1F8;
    }
    // 0x8005F1DC: nop

    // 0x8005F1E0: beq         $a2, $zero, L_8005F1F8
    if (ctx->r6 == 0) {
        // 0x8005F1E4: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_8005F1F8;
    }
    // 0x8005F1E4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8005F1E8: sb          $a3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r7;
    // 0x8005F1EC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005F1F0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F1F4: nop

L_8005F1F8:
    // 0x8005F1F8: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8005F1FC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8005F200: beq         $t0, $t8, L_8005F210
    if (ctx->r8 == ctx->r24) {
        // 0x8005F204: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005F210;
    }
    // 0x8005F204: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005F208: bne         $v1, $zero, L_8005F384
    if (ctx->r3 != 0) {
        // 0x8005F20C: nop
    
            goto L_8005F384;
    }
    // 0x8005F20C: nop

L_8005F210:
    // 0x8005F210: bne         $v1, $at, L_8005F234
    if (ctx->r3 != ctx->r1) {
        // 0x8005F214: nop
    
            goto L_8005F234;
    }
    // 0x8005F214: nop

    // 0x8005F218: lbu         $t9, 0x1CD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F21C: nop

    // 0x8005F220: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005F224: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005F228: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F22C: b           L_8005F388
    // 0x8005F230: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F388;
    // 0x8005F230: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F234:
    // 0x8005F234: bne         $t1, $v1, L_8005F264
    if (ctx->r9 != ctx->r3) {
        // 0x8005F238: nop
    
            goto L_8005F264;
    }
    // 0x8005F238: nop

    // 0x8005F23C: lbu         $t2, 0x1CD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F240: nop

    // 0x8005F244: bne         $t2, $zero, L_8005F254
    if (ctx->r10 != 0) {
        // 0x8005F248: nop
    
            goto L_8005F254;
    }
    // 0x8005F248: nop

    // 0x8005F24C: b           L_8005F258
    // 0x8005F250: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005F258;
    // 0x8005F250: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005F254:
    // 0x8005F254: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005F258:
    // 0x8005F258: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F25C: b           L_8005F388
    // 0x8005F260: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F388;
    // 0x8005F260: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F264:
    // 0x8005F264: bne         $a3, $v1, L_8005F294
    if (ctx->r7 != ctx->r3) {
        // 0x8005F268: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005F294;
    }
    // 0x8005F268: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F26C: lbu         $t3, 0x1CD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005F270: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005F274: bne         $t3, $at, L_8005F284
    if (ctx->r11 != ctx->r1) {
        // 0x8005F278: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005F284;
    }
    // 0x8005F278: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005F27C: b           L_8005F288
    // 0x8005F280: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005F288;
    // 0x8005F280: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005F284:
    // 0x8005F284: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
L_8005F288:
    // 0x8005F288: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F28C: b           L_8005F388
    // 0x8005F290: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F388;
    // 0x8005F290: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F294:
    // 0x8005F294: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005F298: lwc1        $f11, 0x7078($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X7078);
    // 0x8005F29C: lwc1        $f10, 0x707C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X707C);
    // 0x8005F2A0: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8005F2A4: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x8005F2A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005F2AC: bc1f        L_8005F320
    if (!c1cs) {
        // 0x8005F2B0: nop
    
            goto L_8005F320;
    }
    // 0x8005F2B0: nop

    // 0x8005F2B4: lwc1        $f5, 0x7080($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X7080);
    // 0x8005F2B8: lwc1        $f4, 0x7084($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7084);
    // 0x8005F2BC: nop

    // 0x8005F2C0: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8005F2C4: nop

    // 0x8005F2C8: bc1f        L_8005F320
    if (!c1cs) {
        // 0x8005F2CC: nop
    
            goto L_8005F320;
    }
    // 0x8005F2CC: nop

    // 0x8005F2D0: bne         $a0, $v1, L_8005F310
    if (ctx->r4 != ctx->r3) {
        // 0x8005F2D4: nop
    
            goto L_8005F310;
    }
    // 0x8005F2D4: nop

    // 0x8005F2D8: sb          $t1, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r9;
    // 0x8005F2DC: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F2E0: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x8005F2E4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8005F2E8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8005F2EC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8005F2F0: nop

    // 0x8005F2F4: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x8005F2F8: addiu       $t3, $t2, -0x11
    ctx->r11 = ADD32(ctx->r10, -0X11);
    // 0x8005F2FC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8005F300: nop

    // 0x8005F304: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005F308: b           L_8005F314
    // 0x8005F30C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8005F314;
    // 0x8005F30C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_8005F310:
    // 0x8005F310: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005F314:
    // 0x8005F314: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F318: b           L_8005F388
    // 0x8005F31C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
        goto L_8005F388;
    // 0x8005F31C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F320:
    // 0x8005F320: bne         $v1, $zero, L_8005F338
    if (ctx->r3 != 0) {
        // 0x8005F324: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005F338;
    }
    // 0x8005F324: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005F328: sb          $t1, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r9;
    // 0x8005F32C: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005F330: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F334: nop

L_8005F338:
    // 0x8005F338: bne         $v1, $at, L_8005F384
    if (ctx->r3 != ctx->r1) {
        // 0x8005F33C: nop
    
            goto L_8005F384;
    }
    // 0x8005F33C: nop

    // 0x8005F340: bne         $a2, $zero, L_8005F384
    if (ctx->r6 != 0) {
        // 0x8005F344: nop
    
            goto L_8005F384;
    }
    // 0x8005F344: nop

    // 0x8005F348: sb          $a3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r7;
    // 0x8005F34C: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F350: lw          $t4, 0x44($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X44);
    // 0x8005F354: sll         $t5, $t6, 3
    ctx->r13 = S32(ctx->r14 << 3);
    // 0x8005F358: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8005F35C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8005F360: nop

    // 0x8005F364: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8005F368: addiu       $t2, $t9, -0x11
    ctx->r10 = ADD32(ctx->r25, -0X11);
    // 0x8005F36C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8005F370: nop

    // 0x8005F374: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005F378: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005F37C: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F380: nop

L_8005F384:
    // 0x8005F384: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
L_8005F388:
    // 0x8005F388: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005F38C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005F390: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005F394: sh          $t3, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r11;
    // 0x8005F398: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005F39C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005F3A0: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005F3A4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005F3A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8005F3AC: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8005F3B0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005F3B4: bne         $a0, $v1, L_8005F3D8
    if (ctx->r4 != ctx->r3) {
        // 0x8005F3B8: sh          $t4, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r12;
            goto L_8005F3D8;
    }
    // 0x8005F3B8: sh          $t4, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r12;
    // 0x8005F3BC: lh          $a2, 0x3C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3C);
    // 0x8005F3C0: addiu       $t5, $zero, 0xAD
    ctx->r13 = ADD32(0, 0XAD);
    // 0x8005F3C4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005F3C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F3CC: jal         0x800113CC
    // 0x8005F3D0: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_10;
    // 0x8005F3D0: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_10:
    // 0x8005F3D4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8005F3D8:
    // 0x8005F3D8: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8005F3DC: nop

    // 0x8005F3E0: bne         $t0, $t7, L_8005F414
    if (ctx->r8 != ctx->r15) {
        // 0x8005F3E4: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_8005F414;
    }
    // 0x8005F3E4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8005F3E8: jal         0x8002359C
    // 0x8005F3EC: nop

    func_80023568(rdram, ctx);
        goto after_11;
    // 0x8005F3EC: nop

    after_11:
    // 0x8005F3F0: beq         $v0, $zero, L_8005F410
    if (ctx->r2 == 0) {
        // 0x8005F3F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005F410;
    }
    // 0x8005F3F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F3F8: addiu       $t8, $zero, 0xA5
    ctx->r24 = ADD32(0, 0XA5);
    // 0x8005F3FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005F400: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005F404: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8005F408: jal         0x8005E3A4
    // 0x8005F40C: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    spawn_boss_hazard(rdram, ctx);
        goto after_12;
    // 0x8005F40C: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    after_12:
L_8005F410:
    // 0x8005F410: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_8005F414:
    // 0x8005F414: jal         0x800B019C
    // 0x8005F418: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_13;
    // 0x8005F418: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8005F41C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005F420: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005F424: jal         0x8005D1E8
    // 0x8005F428: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_14;
    // 0x8005F428: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_14:
    // 0x8005F42C: jal         0x8001BAFC
    // 0x8005F430: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_15;
    // 0x8005F430: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x8005F434: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x8005F438: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x8005F43C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8005F440: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005F444: bne         $s1, $t9, L_8005F474
    if (ctx->r17 != ctx->r25) {
        // 0x8005F448: addiu       $a1, $a1, -0x2480
        ctx->r5 = ADD32(ctx->r5, -0X2480);
            goto L_8005F474;
    }
    // 0x8005F448: addiu       $a1, $a1, -0x2480
    ctx->r5 = ADD32(ctx->r5, -0X2480);
    // 0x8005F44C: lh          $t2, 0x14($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X14);
    // 0x8005F450: nop

    // 0x8005F454: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8005F458: beq         $t3, $zero, L_8005F474
    if (ctx->r11 == 0) {
        // 0x8005F45C: nop
    
            goto L_8005F474;
    }
    // 0x8005F45C: nop

    // 0x8005F460: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005F464: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F468: bne         $t6, $at, L_8005F474
    if (ctx->r14 != ctx->r1) {
        // 0x8005F46C: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005F474;
    }
    // 0x8005F46C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005F470: sb          $t4, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r12;
L_8005F474:
    // 0x8005F474: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005F478: nop

    // 0x8005F47C: beq         $t5, $zero, L_8005F4A0
    if (ctx->r13 == 0) {
        // 0x8005F480: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005F4A0;
    }
    // 0x8005F480: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005F484: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8005F488: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005F48C: bne         $t7, $zero, L_8005F49C
    if (ctx->r15 != 0) {
        // 0x8005F490: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005F49C;
    }
    // 0x8005F490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F494: jal         0x8005CD08
    // 0x8005F498: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    racer_boss_finish(rdram, ctx);
        goto after_16;
    // 0x8005F498: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    after_16:
L_8005F49C:
    // 0x8005F49C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005F4A0:
    // 0x8005F4A0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F4A4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8005F4A8: jr          $ra
    // 0x8005F4AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8005F4AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void level_name(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C01C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006C020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C024: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006C028: bltz        $a0, L_8006C048
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006C02C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006C048;
    }
    // 0x8006C02C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006C030: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006C034: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006C038: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006C03C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006C040: bne         $at, $zero, L_8006C050
    if (ctx->r1 != 0) {
        // 0x8006C044: nop
    
            goto L_8006C050;
    }
    // 0x8006C044: nop

L_8006C048:
    // 0x8006C048: b           L_8006C12C
    // 0x8006C04C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006C12C;
    // 0x8006C04C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006C050:
    // 0x8006C050: lw          $t7, 0x16EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16EC);
    // 0x8006C054: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8006C058: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006C05C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8006C060: sb          $v1, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r3;
    // 0x8006C064: jal         0x8009F064
    // 0x8006C068: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    get_language(rdram, ctx);
        goto after_0;
    // 0x8006C068: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006C06C: lbu         $v1, 0x1B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1B);
    // 0x8006C070: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C074: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C078: beq         $v0, $at, L_8006C098
    if (ctx->r2 == ctx->r1) {
        // 0x8006C07C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8006C098;
    }
    // 0x8006C07C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006C080: beq         $v0, $at, L_8006C0C8
    if (ctx->r2 == ctx->r1) {
        // 0x8006C084: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8006C0C8;
    }
    // 0x8006C084: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8006C088: beq         $v0, $at, L_8006C0FC
    if (ctx->r2 == ctx->r1) {
        // 0x8006C08C: nop
    
            goto L_8006C0FC;
    }
    // 0x8006C08C: nop

    // 0x8006C090: b           L_8006C12C
    // 0x8006C094: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006C12C;
    // 0x8006C094: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006C098:
    // 0x8006C098: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006C09C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006C0A0: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006C0A4: beq         $t0, $zero, L_8006C0B8
    if (ctx->r8 == 0) {
        // 0x8006C0A8: nop
    
            goto L_8006C0B8;
    }
    // 0x8006C0A8: nop

    // 0x8006C0AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C0B0: andi        $t1, $v1, 0xFF
    ctx->r9 = ctx->r3 & 0XFF;
    // 0x8006C0B4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_8006C0B8:
    // 0x8006C0B8: blez        $v1, L_8006C098
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006C0BC: nop
    
            goto L_8006C098;
    }
    // 0x8006C0BC: nop

    // 0x8006C0C0: b           L_8006C12C
    // 0x8006C0C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006C12C;
    // 0x8006C0C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006C0C8:
    // 0x8006C0C8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006C0CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006C0D0: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006C0D4: beq         $t2, $zero, L_8006C0EC
    if (ctx->r10 == 0) {
        // 0x8006C0D8: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8006C0EC;
    }
    // 0x8006C0D8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8006C0DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C0E0: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x8006C0E4: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x8006C0E8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
L_8006C0EC:
    // 0x8006C0EC: bne         $at, $zero, L_8006C0C8
    if (ctx->r1 != 0) {
        // 0x8006C0F0: nop
    
            goto L_8006C0C8;
    }
    // 0x8006C0F0: nop

    // 0x8006C0F4: b           L_8006C12C
    // 0x8006C0F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8006C12C;
    // 0x8006C0F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006C0FC:
    // 0x8006C0FC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006C100: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006C104: sltiu       $t4, $v0, 0x1
    ctx->r12 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006C108: beq         $t4, $zero, L_8006C120
    if (ctx->r12 == 0) {
        // 0x8006C10C: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_8006C120;
    }
    // 0x8006C10C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8006C110: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C114: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x8006C118: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x8006C11C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_8006C120:
    // 0x8006C120: bne         $at, $zero, L_8006C0FC
    if (ctx->r1 != 0) {
        // 0x8006C124: nop
    
            goto L_8006C0FC;
    }
    // 0x8006C124: nop

    // 0x8006C128: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006C12C:
    // 0x8006C12C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C130: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006C134: jr          $ra
    // 0x8006C138: nop

    return;
    // 0x8006C138: nop

;}
RECOMP_FUNC void second_racer_camera_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800580F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800580F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800580FC: lw          $t6, -0x2524($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2524);
    // 0x80058100: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80058104: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058108: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8005810C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058110: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80058114: beq         $t6, $at, L_80058218
    if (ctx->r14 == ctx->r1) {
        // 0x80058118: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80058218;
    }
    // 0x80058118: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005811C: lb          $t7, 0x1D8($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1D8);
    // 0x80058120: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80058124: beq         $t7, $at, L_80058218
    if (ctx->r15 == ctx->r1) {
        // 0x80058128: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80058218;
    }
    // 0x80058128: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005812C: addiu       $v1, $v1, -0x2578
    ctx->r3 = ADD32(ctx->r3, -0X2578);
    // 0x80058130: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80058134: nop

    // 0x80058138: lh          $t9, 0x36($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X36);
    // 0x8005813C: nop

    // 0x80058140: beq         $a2, $t9, L_8005821C
    if (ctx->r6 == ctx->r25) {
        // 0x80058144: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005821C;
    }
    // 0x80058144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058148: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8005814C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80058150: jal         0x80057A80
    // 0x80058154: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    update_player_camera(rdram, ctx);
        goto after_0;
    // 0x80058154: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80058158: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005815C: addiu       $v1, $v1, -0x2578
    ctx->r3 = ADD32(ctx->r3, -0X2578);
    // 0x80058160: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80058164: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80058168: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005816C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80058170: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80058174: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80058178: nop

    // 0x8005817C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80058180: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80058184: nop

    // 0x80058188: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8005818C: sh          $a3, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r7;
    // 0x80058190: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80058194: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80058198: jal         0x80057A80
    // 0x8005819C: nop

    update_player_camera(rdram, ctx);
        goto after_1;
    // 0x8005819C: nop

    after_1:
    // 0x800581A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800581A4: lw          $t0, -0x2540($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2540);
    // 0x800581A8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800581AC: bne         $t0, $zero, L_80058218
    if (ctx->r8 != 0) {
        // 0x800581B0: addiu       $v1, $v1, -0x2578
        ctx->r3 = ADD32(ctx->r3, -0X2578);
            goto L_80058218;
    }
    // 0x800581B0: addiu       $v1, $v1, -0x2578
    ctx->r3 = ADD32(ctx->r3, -0X2578);
    // 0x800581B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800581B8: lb          $t1, -0x24FE($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X24FE);
    // 0x800581BC: nop

    // 0x800581C0: bne         $t1, $zero, L_8005821C
    if (ctx->r9 != 0) {
        // 0x800581C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005821C;
    }
    // 0x800581C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800581C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800581CC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800581D0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800581D4: nop

    // 0x800581D8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800581DC: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x800581E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800581E4: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800581E8: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800581EC: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800581F0: nop

    // 0x800581F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800581F8: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800581FC: swc1        $f16, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f16.u32l;
    // 0x80058200: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80058204: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80058208: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005820C: nop

    // 0x80058210: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80058214: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
L_80058218:
    // 0x80058218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005821C:
    // 0x8005821C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80058220: jr          $ra
    // 0x80058224: nop

    return;
    // 0x80058224: nop

;}
RECOMP_FUNC void get_misc_asset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E2D0: bltz        $a0, L_8001E2EC
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001E2D4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001E2EC;
    }
    // 0x8001E2D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001E2D8: lw          $t6, -0x4CE0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CE0);
    // 0x8001E2DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001E2E0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001E2E4: bne         $at, $zero, L_8001E2FC
    if (ctx->r1 != 0) {
        // 0x8001E2E8: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8001E2FC;
    }
    // 0x8001E2E8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
L_8001E2EC:
    // 0x8001E2EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E2F0: lw          $v0, -0x4D14($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D14);
    // 0x8001E2F4: jr          $ra
    // 0x8001E2F8: nop

    return;
    // 0x8001E2F8: nop

L_8001E2FC:
    // 0x8001E2FC: lw          $t7, -0x4D10($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4D10);
    // 0x8001E300: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001E304: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001E308: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8001E30C: lw          $t2, -0x4D14($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4D14);
    // 0x8001E310: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001E314: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8001E318: jr          $ra
    // 0x8001E31C: nop

    return;
    // 0x8001E31C: nop

;}
RECOMP_FUNC void alCSPPlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8B08: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800C8B0C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C8B10: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C8B14: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C8B18: jal         0x800C970C
    // 0x800C8B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C8B1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C8B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8B24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C8B28: jr          $ra
    // 0x800C8B2C: nop

    return;
    // 0x800C8B2C: nop

;}
RECOMP_FUNC void obj_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E9B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E9B4: lw          $v0, -0x4C24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C24);
    // 0x8000E9B8: jr          $ra
    // 0x8000E9BC: nop

    return;
    // 0x8000E9BC: nop

;}
RECOMP_FUNC void update_colour_cycle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F69C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007F6A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007F6A4: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8007F6A8: bne         $at, $zero, L_8007F85C
    if (ctx->r1 != 0) {
        // 0x8007F6AC: nop
    
            goto L_8007F85C;
    }
    // 0x8007F6AC: nop

    // 0x8007F6B0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8007F6B4: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x8007F6B8: addu        $v0, $t7, $a1
    ctx->r2 = ADD32(ctx->r15, ctx->r5);
    // 0x8007F6BC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F6C0: bne         $at, $zero, L_8007F6DC
    if (ctx->r1 != 0) {
        // 0x8007F6C4: sw          $v0, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r2;
            goto L_8007F6DC;
    }
    // 0x8007F6C4: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
L_8007F6C8:
    // 0x8007F6C8: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x8007F6CC: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F6D0: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8007F6D4: beq         $at, $zero, L_8007F6C8
    if (ctx->r1 == 0) {
        // 0x8007F6D8: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8007F6C8;
    }
    // 0x8007F6D8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007F6DC:
    // 0x8007F6DC: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8007F6E0: nop

    // 0x8007F6E4: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8007F6E8: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8007F6EC: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    // 0x8007F6F0: nop

    // 0x8007F6F4: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F6F8: bne         $at, $zero, L_8007F748
    if (ctx->r1 != 0) {
        // 0x8007F6FC: nop
    
            goto L_8007F748;
    }
    // 0x8007F6FC: nop

L_8007F700:
    // 0x8007F700: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007F704: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8007F708: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x8007F70C: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007F710: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8007F714: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F718: bne         $at, $zero, L_8007F728
    if (ctx->r1 != 0) {
        // 0x8007F71C: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_8007F728;
    }
    // 0x8007F71C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8007F720: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007F724: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007F728:
    // 0x8007F728: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8007F72C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8007F730: lw          $a1, 0x18($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X18);
    // 0x8007F734: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8007F738: nop

    // 0x8007F73C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F740: beq         $at, $zero, L_8007F700
    if (ctx->r1 == 0) {
        // 0x8007F744: nop
    
            goto L_8007F700;
    }
    // 0x8007F744: nop

L_8007F748:
    // 0x8007F748: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8007F74C: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x8007F750: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8007F754: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8007F758: bne         $at, $zero, L_8007F764
    if (ctx->r1 != 0) {
        // 0x8007F75C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8007F764;
    }
    // 0x8007F75C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8007F760: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8007F764:
    // 0x8007F764: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x8007F768: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8007F76C: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x8007F770: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8007F774: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x8007F778: sll         $t9, $a3, 3
    ctx->r25 = S32(ctx->r7 << 3);
    // 0x8007F77C: addu        $t5, $a0, $t9
    ctx->r13 = ADD32(ctx->r4, ctx->r25);
    // 0x8007F780: lbu         $t0, 0x14($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X14);
    // 0x8007F784: lbu         $t4, 0x14($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X14);
    // 0x8007F788: lbu         $t6, 0x15($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X15);
    // 0x8007F78C: subu        $t9, $t4, $t0
    ctx->r25 = SUB32(ctx->r12, ctx->r8);
    // 0x8007F790: lbu         $t1, 0x15($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X15);
    // 0x8007F794: lbu         $t2, 0x16($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X16);
    // 0x8007F798: lbu         $t3, 0x17($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X17);
    // 0x8007F79C: bne         $t8, $zero, L_8007F7A8
    if (ctx->r24 != 0) {
        // 0x8007F7A0: nop
    
            goto L_8007F7A8;
    }
    // 0x8007F7A0: nop

    // 0x8007F7A4: break       7
    do_break(2148005796);
L_8007F7A8:
    // 0x8007F7A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007F7AC: bne         $t8, $at, L_8007F7C0
    if (ctx->r24 != ctx->r1) {
        // 0x8007F7B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007F7C0;
    }
    // 0x8007F7B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F7B4: bne         $t7, $at, L_8007F7C0
    if (ctx->r15 != ctx->r1) {
        // 0x8007F7B8: nop
    
            goto L_8007F7C0;
    }
    // 0x8007F7B8: nop

    // 0x8007F7BC: break       6
    do_break(2148005820);
L_8007F7C0:
    // 0x8007F7C0: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8007F7C4: lbu         $t7, 0x16($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X16);
    // 0x8007F7C8: nop

    // 0x8007F7CC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8007F7D0: lbu         $t8, 0x17($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X17);
    // 0x8007F7D4: nop

    // 0x8007F7D8: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x8007F7DC: mflo        $a1
    ctx->r5 = lo;
    // 0x8007F7E0: nop

    // 0x8007F7E4: nop

    // 0x8007F7E8: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F7EC: mflo        $t6
    ctx->r14 = lo;
    // 0x8007F7F0: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x8007F7F4: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8007F7F8: sb          $t8, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r24;
    // 0x8007F7FC: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8007F800: nop

    // 0x8007F804: subu        $t6, $t9, $t1
    ctx->r14 = SUB32(ctx->r25, ctx->r9);
    // 0x8007F808: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F80C: mflo        $t7
    ctx->r15 = lo;
    // 0x8007F810: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x8007F814: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x8007F818: sb          $t9, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r25;
    // 0x8007F81C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007F820: nop

    // 0x8007F824: subu        $t7, $t6, $t2
    ctx->r15 = SUB32(ctx->r14, ctx->r10);
    // 0x8007F828: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F82C: mflo        $t8
    ctx->r24 = lo;
    // 0x8007F830: srl         $t9, $t8, 16
    ctx->r25 = S32(U32(ctx->r24) >> 16);
    // 0x8007F834: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8007F838: sb          $t6, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r14;
    // 0x8007F83C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007F840: nop

    // 0x8007F844: subu        $t8, $t7, $t3
    ctx->r24 = SUB32(ctx->r15, ctx->r11);
    // 0x8007F848: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F84C: mflo        $t9
    ctx->r25 = lo;
    // 0x8007F850: srl         $t6, $t9, 16
    ctx->r14 = S32(U32(ctx->r25) >> 16);
    // 0x8007F854: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x8007F858: sb          $t7, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r15;
L_8007F85C:
    // 0x8007F85C: jr          $ra
    // 0x8007F860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8007F860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void handle_menu_joystick_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D7B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D7B4: lb          $v0, 0x6A04($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6A04);
    // 0x8009D7B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009D7BC: bgez        $v0, L_8009D7EC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009D7C0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009D7EC;
    }
    // 0x8009D7C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D7C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D7C8: addiu       $v0, $v0, 0x6A78
    ctx->r2 = ADD32(ctx->r2, 0X6A78);
    // 0x8009D7CC: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009D7D0: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    // 0x8009D7D4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009D7D8: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8009D7DC: jal         0x80001D04
    // 0x8009D7E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x8009D7E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8009D7E4: b           L_8009D810
    // 0x8009D7E8: nop

        goto L_8009D810;
    // 0x8009D7E8: nop

L_8009D7EC:
    // 0x8009D7EC: blez        $v0, L_8009D810
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009D7F0: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8009D810;
    }
    // 0x8009D7F0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009D7F4: lb          $t8, 0x6A78($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X6A78);
    // 0x8009D7F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D7FC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8009D800: sb          $t9, 0x6A78($at)
    MEM_B(0X6A78, ctx->r1) = ctx->r25;
    // 0x8009D804: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    // 0x8009D808: jal         0x80001D04
    // 0x8009D80C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8009D80C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_8009D810:
    // 0x8009D810: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009D814: addiu       $v1, $v1, 0x6A78
    ctx->r3 = ADD32(ctx->r3, 0X6A78);
    // 0x8009D818: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009D81C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009D820: bgez        $v0, L_8009D840
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009D824: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8009D840;
    }
    // 0x8009D824: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009D828: lb          $t0, 0x6AA4($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X6AA4);
    // 0x8009D82C: nop

    // 0x8009D830: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8009D834: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x8009D838: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8009D83C: nop

L_8009D840:
    // 0x8009D840: lb          $t2, 0x6AA4($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X6AA4);
    // 0x8009D844: nop

    // 0x8009D848: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8009D84C: bne         $at, $zero, L_8009D85C
    if (ctx->r1 != 0) {
        // 0x8009D850: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009D85C;
    }
    // 0x8009D850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D854: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8009D858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009D85C:
    // 0x8009D85C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009D860: jr          $ra
    // 0x8009D864: nop

    return;
    // 0x8009D864: nop

;}
RECOMP_FUNC void get_contpak_error(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E0B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E0B4: lw          $t6, -0x4D48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D48);
    // 0x8000E0B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E0BC: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x8000E0C0: beq         $at, $zero, L_8000E114
    if (ctx->r1 == 0) {
        // 0x8000E0C4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000E114;
    }
    // 0x8000E0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E0C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000E0CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E0D0: addu        $at, $at, $t6
    gpr jr_addend_8000E0DC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000E0D4: lw          $t6, 0x5718($at)
    ctx->r14 = ADD32(ctx->r1, 0X5718);
    // 0x8000E0D8: nop

    // 0x8000E0DC: jr          $t6
    // 0x8000E0E0: nop

    switch (jr_addend_8000E0DC >> 2) {
        case 0: goto L_8000E104; break;
        case 1: goto L_8000E0E4; break;
        case 2: goto L_8000E0F4; break;
        case 3: goto L_8000E0F4; break;
        case 4: goto L_8000E0FC; break;
        case 5: goto L_8000E104; break;
        case 6: goto L_8000E0FC; break;
        case 7: goto L_8000E0EC; break;
        case 8: goto L_8000E104; break;
        default: switch_error(__func__, 0x8000E0DC, 0x800E5718);
    }
    // 0x8000E0E0: nop

L_8000E0E4:
    // 0x8000E0E4: b           L_8000E118
    // 0x8000E0E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E118;
    // 0x8000E0E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000E0EC:
    // 0x8000E0EC: b           L_8000E118
    // 0x8000E0F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E118;
    // 0x8000E0F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E0F4:
    // 0x8000E0F4: b           L_8000E118
    // 0x8000E0F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8000E118;
    // 0x8000E0F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8000E0FC:
    // 0x8000E0FC: b           L_8000E118
    // 0x8000E100: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000E118;
    // 0x8000E100: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000E104:
    // 0x8000E104: jal         0x80059E70
    // 0x8000E108: nop

    timetrial_ghost_full(rdram, ctx);
        goto after_0;
    // 0x8000E108: nop

    after_0:
    // 0x8000E10C: b           L_8000E11C
    // 0x8000E110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000E11C;
    // 0x8000E110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E114:
    // 0x8000E114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E118:
    // 0x8000E118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E11C:
    // 0x8000E11C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000E120: jr          $ra
    // 0x8000E124: nop

    return;
    // 0x8000E124: nop

;}
RECOMP_FUNC void menu_element_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CFA4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009CFA8: addiu       $t3, $t3, -0x324
    ctx->r11 = ADD32(ctx->r11, -0X324);
    // 0x8009CFAC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8009CFB0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8009CFB4: sll         $t0, $a0, 5
    ctx->r8 = S32(ctx->r4 << 5);
    // 0x8009CFB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009CFBC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009CFC0: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8009CFC4: addu        $t7, $v1, $t0
    ctx->r15 = ADD32(ctx->r3, ctx->r8);
    // 0x8009CFC8: lh          $a1, 0x6($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X6);
    // 0x8009CFCC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009CFD0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8009CFD4: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8009CFD8: lw          $t2, 0x6AF0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6AF0);
    // 0x8009CFDC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009CFE0: beq         $t2, $zero, L_8009D2B4
    if (ctx->r10 == 0) {
        // 0x8009CFE4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009D2B4;
    }
    // 0x8009CFE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009CFE8: lw          $t9, -0x330($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X330);
    // 0x8009CFEC: sll         $t4, $a1, 1
    ctx->r12 = S32(ctx->r5 << 1);
    // 0x8009CFF0: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8009CFF4: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x8009CFF8: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8009CFFC: andi        $t6, $v0, 0xC000
    ctx->r14 = ctx->r2 & 0XC000;
    // 0x8009D000: beq         $t6, $at, L_8009D2B0
    if (ctx->r14 == ctx->r1) {
        // 0x8009D004: andi        $t7, $v0, 0x4000
        ctx->r15 = ctx->r2 & 0X4000;
            goto L_8009D2B0;
    }
    // 0x8009D004: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x8009D008: beq         $t7, $zero, L_8009D0A8
    if (ctx->r15 == 0) {
        // 0x8009D00C: andi        $t5, $v0, 0x8000
        ctx->r13 = ctx->r2 & 0X8000;
            goto L_8009D0A8;
    }
    // 0x8009D00C: andi        $t5, $v0, 0x8000
    ctx->r13 = ctx->r2 & 0X8000;
    // 0x8009D010: sll         $t9, $a0, 5
    ctx->r25 = S32(ctx->r4 << 5);
    // 0x8009D014: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x8009D018: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8009D01C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009D020: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
    // 0x8009D024: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x8009D028: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009D02C: sh          $t5, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r13;
    // 0x8009D030: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8009D034: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D038: sh          $t6, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r14;
    // 0x8009D03C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009D040: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009D044: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x8009D048: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009D04C: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8009D050: swc1        $f6, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f6.u32l;
    // 0x8009D054: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009D058: addiu       $a0, $s0, 0x693C
    ctx->r4 = ADD32(ctx->r16, 0X693C);
    // 0x8009D05C: swc1        $f8, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->f8.u32l;
    // 0x8009D060: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009D064: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009D068: swc1        $f10, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f10.u32l;
    // 0x8009D06C: lw          $t7, -0x618($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X618);
    // 0x8009D070: addiu       $a2, $a2, 0x694C
    ctx->r6 = ADD32(ctx->r6, 0X694C);
    // 0x8009D074: bne         $t7, $zero, L_8009D094
    if (ctx->r15 != 0) {
        // 0x8009D078: addiu       $a1, $a1, 0x6944
        ctx->r5 = ADD32(ctx->r5, 0X6944);
            goto L_8009D094;
    }
    // 0x8009D078: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009D07C: lb          $t8, 0x1D($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1D);
    // 0x8009D080: nop

    // 0x8009D084: sh          $t8, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r24;
    // 0x8009D088: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
    // 0x8009D08C: nop

    // 0x8009D090: sb          $t9, 0x3A($t2)
    MEM_B(0X3A, ctx->r10) = ctx->r25;
L_8009D094:
    // 0x8009D094: lw          $t4, -0x31C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X31C);
    // 0x8009D098: jal         0x80012D5C
    // 0x8009D09C: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
    render_object(rdram, ctx);
        goto after_0;
    // 0x8009D09C: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
    after_0:
    // 0x8009D0A0: b           L_8009D2B4
    // 0x8009D0A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8009D2B4;
    // 0x8009D0A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009D0A8:
    // 0x8009D0A8: beq         $t5, $zero, L_8009D17C
    if (ctx->r13 == 0) {
        // 0x8009D0AC: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8009D17C;
    }
    // 0x8009D0AC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009D0B0: addiu       $s0, $s0, 0x693C
    ctx->r16 = ADD32(ctx->r16, 0X693C);
    // 0x8009D0B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D0B8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8009D0BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D0C0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009D0C4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D0C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D0CC: lbu         $t9, -0x5DC($t8)
    ctx->r25 = MEM_BU(ctx->r24, -0X5DC);
    // 0x8009D0D0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009D0D4: lbu         $t6, -0x5D8($t5)
    ctx->r14 = MEM_BU(ctx->r13, -0X5D8);
    // 0x8009D0D8: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x8009D0DC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8009D0E0: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8009D0E4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009D0E8: lbu         $t5, -0x5D4($t9)
    ctx->r13 = MEM_BU(ctx->r25, -0X5D4);
    // 0x8009D0EC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009D0F0: lw          $t7, -0x31C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X31C);
    // 0x8009D0F4: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x8009D0F8: or          $t4, $t8, $t6
    ctx->r12 = ctx->r24 | ctx->r14;
    // 0x8009D0FC: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8009D100: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x8009D104: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8009D108: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D10C: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x8009D110: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D114: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009D118: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8009D11C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009D120: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009D124: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8009D128: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D12C: lw          $t8, -0x5CC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5CC);
    // 0x8009D130: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8009D134: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D138: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009D13C: sll         $t9, $t4, 5
    ctx->r25 = S32(ctx->r12 << 5);
    // 0x8009D140: addiu       $a2, $a2, 0x694C
    ctx->r6 = ADD32(ctx->r6, 0X694C);
    // 0x8009D144: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009D148: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009D14C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009D150: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009D154: jal         0x80068E34
    // 0x8009D158: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    render_ortho_triangle_image(rdram, ctx);
        goto after_1;
    // 0x8009D158: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    after_1:
    // 0x8009D15C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D160: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8009D164: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D168: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009D16C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8009D170: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8009D174: b           L_8009D2B0
    // 0x8009D178: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_8009D2B0;
    // 0x8009D178: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8009D17C:
    // 0x8009D17C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009D180: addiu       $t1, $t1, -0x31C
    ctx->r9 = ADD32(ctx->r9, -0X31C);
    // 0x8009D184: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8009D188: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D18C: slti        $at, $t9, 0xFF
    ctx->r1 = SIGNED(ctx->r25) < 0XFF ? 1 : 0;
    // 0x8009D190: beq         $at, $zero, L_8009D1CC
    if (ctx->r1 == 0) {
        // 0x8009D194: addiu       $a1, $a1, 0x6944
        ctx->r5 = ADD32(ctx->r5, 0X6944);
            goto L_8009D1CC;
    }
    // 0x8009D194: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009D198: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009D19C: addiu       $s0, $s0, 0x693C
    ctx->r16 = ADD32(ctx->r16, 0X693C);
    // 0x8009D1A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D1A4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8009D1A8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8009D1AC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8009D1B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009D1B4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8009D1B8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8009D1BC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8009D1C0: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x8009D1C4: b           L_8009D1F0
    // 0x8009D1C8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_8009D1F0;
    // 0x8009D1C8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_8009D1CC:
    // 0x8009D1CC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009D1D0: addiu       $s0, $s0, 0x693C
    ctx->r16 = ADD32(ctx->r16, 0X693C);
    // 0x8009D1D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D1D8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8009D1DC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009D1E0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009D1E4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8009D1E8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009D1EC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8009D1F0:
    // 0x8009D1F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D1F4: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8009D1F8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D1FC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8009D200: addiu       $t4, $zero, -0x100
    ctx->r12 = ADD32(0, -0X100);
    // 0x8009D204: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8009D208: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009D20C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8009D210: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8009D214: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009D218: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8009D21C: lw          $a3, -0x62C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X62C);
    // 0x8009D220: sll         $t5, $t9, 5
    ctx->r13 = S32(ctx->r25 << 5);
    // 0x8009D224: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8009D228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009D22C: addu        $a2, $t5, $t8
    ctx->r6 = ADD32(ctx->r13, ctx->r24);
    // 0x8009D230: jal         0x800696C4
    // 0x8009D234: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_2;
    // 0x8009D234: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8009D238: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009D23C: addiu       $t3, $t3, -0x324
    ctx->r11 = ADD32(ctx->r11, -0X324);
    // 0x8009D240: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8009D244: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8009D248: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009D24C: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8009D250: lh          $t4, 0x6($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X6);
    // 0x8009D254: nop

    // 0x8009D258: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8009D25C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8009D260: lw          $v0, 0x6AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6AF0);
    // 0x8009D264: nop

    // 0x8009D268: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8009D26C: jal         0x8009D2C0
    // 0x8009D270: nop

    render_track_selection_viewport_border(rdram, ctx);
        goto after_3;
    // 0x8009D270: nop

    after_3:
    // 0x8009D274: jal         0x80069C80
    // 0x8009D278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtx_pop(rdram, ctx);
        goto after_4;
    // 0x8009D278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8009D27C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009D280: lw          $t5, -0x31C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X31C);
    // 0x8009D284: nop

    // 0x8009D288: slti        $at, $t5, 0xFF
    ctx->r1 = SIGNED(ctx->r13) < 0XFF ? 1 : 0;
    // 0x8009D28C: beq         $at, $zero, L_8009D2B4
    if (ctx->r1 == 0) {
        // 0x8009D290: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009D2B4;
    }
    // 0x8009D290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009D294: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009D298: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8009D29C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009D2A0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8009D2A4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8009D2A8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009D2AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8009D2B0:
    // 0x8009D2B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009D2B4:
    // 0x8009D2B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8009D2B8: jr          $ra
    // 0x8009D2BC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8009D2BC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800228DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022910: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80022914: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80022918: jr          $ra
    // 0x8002291C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x8002291C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void obj_collision_transform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800170D0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800170D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800170D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800170DC: lw          $s0, 0x5C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X5C);
    // 0x800170E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800170E4: lbu         $t6, 0x104($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X104);
    // 0x800170E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800170EC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800170F0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800170F4: sb          $t8, 0x104($s0)
    MEM_B(0X104, ctx->r16) = ctx->r24;
    // 0x800170F8: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x800170FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017100: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80017104: sh          $t3, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r11;
    // 0x80017108: lh          $t4, 0x2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X2);
    // 0x8001710C: andi        $t0, $t8, 0xFF
    ctx->r8 = ctx->r24 & 0XFF;
    // 0x80017110: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80017114: sh          $t5, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r13;
    // 0x80017118: lh          $t6, 0x4($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X4);
    // 0x8001711C: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x80017120: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80017124: sh          $t7, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r15;
    // 0x80017128: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8001712C: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x80017130: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80017134: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80017138: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8001713C: addu        $a0, $s0, $t1
    ctx->r4 = ADD32(ctx->r16, ctx->r9);
    // 0x80017140: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80017144: swc1        $f16, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f16.u32l;
    // 0x80017148: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8001714C: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    // 0x80017150: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80017154: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x80017158: sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    // 0x8001715C: jal         0x800700B4
    // 0x80017160: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x80017160: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_0:
    // 0x80017164: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x80017168: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001716C: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80017170: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80017174: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80017178: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001717C: nop

    // 0x80017180: div.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f12.d, ctx->f8.d);
    // 0x80017184: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80017188: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001718C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80017190: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80017194: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
    // 0x80017198: addiu       $v1, $sp, 0x6C
    ctx->r3 = ADD32(ctx->r29, 0X6C);
    // 0x8001719C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800171A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800171A4: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_800171A8:
    // 0x800171A8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800171AC: swc1        $f0, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f0.u32l;
    // 0x800171B0: swc1        $f0, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f0.u32l;
    // 0x800171B4: swc1        $f0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f0.u32l;
    // 0x800171B8: bne         $v0, $v1, L_800171A8
    if (ctx->r2 != ctx->r3) {
        // 0x800171BC: swc1        $f0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
            goto L_800171A8;
    }
    // 0x800171BC: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800171C0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800171C4: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x800171C8: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x800171CC: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x800171D0: sw          $a3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r7;
    // 0x800171D4: jal         0x8006F9A8
    // 0x800171D8: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x800171D8: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800171DC: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800171E0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800171E4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800171E8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800171EC: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x800171F0: nop

    // 0x800171F4: div.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800171F8: lw          $a3, 0x90($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X90);
    // 0x800171FC: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x80017200: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x80017204: nop

    // 0x80017208: sh          $t8, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r24;
    // 0x8001720C: lh          $t9, 0x2($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2);
    // 0x80017210: nop

    // 0x80017214: sh          $t9, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r25;
    // 0x80017218: lh          $t0, 0x4($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X4);
    // 0x8001721C: nop

    // 0x80017220: sh          $t0, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r8;
    // 0x80017224: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80017228: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x8001722C: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80017230: nop

    // 0x80017234: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x80017238: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8001723C: nop

    // 0x80017240: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x80017244: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80017248: nop

    // 0x8001724C: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x80017250: lbu         $t1, 0x104($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X104);
    // 0x80017254: nop

    // 0x80017258: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x8001725C: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80017260: jal         0x8006FE70
    // 0x80017264: addu        $a0, $s0, $t4
    ctx->r4 = ADD32(ctx->r16, ctx->r12);
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x80017264: addu        $a0, $s0, $t4
    ctx->r4 = ADD32(ctx->r16, ctx->r12);
    after_2:
    // 0x80017268: sw          $zero, 0x100($s0)
    MEM_W(0X100, ctx->r16) = 0;
    // 0x8001726C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80017270: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017274: jr          $ra
    // 0x80017278: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80017278: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void audspat_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008174: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80008178: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000817C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80008180: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x80008184: addiu       $v1, $v1, -0x5E34
    ctx->r3 = ADD32(ctx->r3, -0X5E34);
    // 0x80008188: lw          $a0, -0x5E38($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E38);
    // 0x8000818C: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80008190: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80008194: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80008198: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000819C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800081A0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800081A4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800081A8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800081AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800081B0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800081B4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800081B8: beq         $at, $zero, L_800081F4
    if (ctx->r1 == 0) {
        // 0x800081BC: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_800081F4;
    }
    // 0x800081BC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800081C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800081C4: addiu       $a1, $a1, -0x5E30
    ctx->r5 = ADD32(ctx->r5, -0X5E30);
L_800081C8:
    // 0x800081C8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800081CC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800081D0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800081D4: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x800081D8: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800081DC: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    // 0x800081E0: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x800081E4: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x800081E8: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x800081EC: bne         $at, $zero, L_800081C8
    if (ctx->r1 != 0) {
        // 0x800081F0: sb          $t1, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r9;
            goto L_800081C8;
    }
    // 0x800081F0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
L_800081F4:
    // 0x800081F4: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800081F8: addiu       $s4, $s4, -0x33B0
    ctx->r20 = ADD32(ctx->r20, -0X33B0);
    // 0x800081FC: lhu         $t3, 0x0($s4)
    ctx->r11 = MEM_HU(ctx->r20, 0X0);
    // 0x80008200: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80008204: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80008208: blez        $t3, L_8000825C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8000820C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000825C;
    }
    // 0x8000820C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80008210: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80008214: addiu       $s2, $s2, -0x5E3C
    ctx->r18 = ADD32(ctx->r18, -0X5E3C);
    // 0x80008218: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000821C:
    // 0x8000821C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80008220: nop

    // 0x80008224: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80008228: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8000822C: nop

    // 0x80008230: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80008234: sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // 0x80008238: beq         $a0, $zero, L_80008248
    if (ctx->r4 == 0) {
        // 0x8000823C: nop
    
            goto L_80008248;
    }
    // 0x8000823C: nop

    // 0x80008240: jal         0x8000488C
    // 0x80008244: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80008244: nop

    after_0:
L_80008248:
    // 0x80008248: lhu         $t6, 0x0($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X0);
    // 0x8000824C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80008250: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80008254: bne         $at, $zero, L_8000821C
    if (ctx->r1 != 0) {
        // 0x80008258: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000821C;
    }
    // 0x80008258: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000825C:
    // 0x8000825C: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x80008260: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008264: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80008268: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8000826C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80008270: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80008274: lwc1        $f20, 0x54A0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X54A0);
    // 0x80008278: addiu       $s5, $s5, -0x53A0
    ctx->r21 = ADD32(ctx->r21, -0X53A0);
    // 0x8000827C: addiu       $s3, $s3, -0x5E20
    ctx->r19 = ADD32(ctx->r19, -0X5E20);
    // 0x80008280: addiu       $s2, $s2, -0x5E24
    ctx->r18 = ADD32(ctx->r18, -0X5E24);
    // 0x80008284: addiu       $s1, $s1, -0x5E28
    ctx->r17 = ADD32(ctx->r17, -0X5E28);
    // 0x80008288: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8000828C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80008290: addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
L_80008294:
    // 0x80008294: lw          $a0, 0x178($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X178);
    // 0x80008298: sw          $zero, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = 0;
    // 0x8000829C: beq         $a0, $zero, L_800082D8
    if (ctx->r4 == 0) {
        // 0x800082A0: nop
    
            goto L_800082D8;
    }
    // 0x800082A0: nop

    // 0x800082A4: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800082A8: nop

    // 0x800082AC: bne         $v0, $zero, L_800082C4
    if (ctx->r2 != 0) {
        // 0x800082B0: nop
    
            goto L_800082C4;
    }
    // 0x800082B0: nop

    // 0x800082B4: jal         0x8000488C
    // 0x800082B8: nop

    sndp_stop(rdram, ctx);
        goto after_1;
    // 0x800082B8: nop

    after_1:
    // 0x800082BC: b           L_800082D8
    // 0x800082C0: sw          $zero, 0x178($s1)
    MEM_W(0X178, ctx->r17) = 0;
        goto L_800082D8;
    // 0x800082C0: sw          $zero, 0x178($s1)
    MEM_W(0X178, ctx->r17) = 0;
L_800082C4:
    // 0x800082C4: bne         $s6, $v0, L_800082D4
    if (ctx->r22 != ctx->r2) {
        // 0x800082C8: nop
    
            goto L_800082D4;
    }
    // 0x800082C8: nop

    // 0x800082CC: jal         0x800018E0
    // 0x800082D0: nop

    music_jingle_stop(rdram, ctx);
        goto after_2;
    // 0x800082D0: nop

    after_2:
L_800082D4:
    // 0x800082D4: sw          $zero, 0x178($s1)
    MEM_W(0X178, ctx->r17) = 0;
L_800082D8:
    // 0x800082D8: sb          $s4, 0x17C($s1)
    MEM_B(0X17C, ctx->r17) = ctx->r20;
    // 0x800082DC: swc1        $f20, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
    // 0x800082E0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800082E4: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
    // 0x800082E8: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x800082EC: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x800082F0: swc1        $f20, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f20.u32l;
    // 0x800082F4: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x800082F8: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x800082FC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80008300:
    // 0x80008300: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80008304: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x80008308: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x8000830C: swc1        $f20, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f20.u32l;
    // 0x80008310: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x80008314: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    // 0x80008318: swc1        $f20, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f20.u32l;
    // 0x8000831C: swc1        $f20, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f20.u32l;
    // 0x80008320: swc1        $f20, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f20.u32l;
    // 0x80008324: swc1        $f20, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x80008328: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x8000832C: swc1        $f20, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->f20.u32l;
    // 0x80008330: swc1        $f20, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x80008334: bne         $v1, $s0, L_80008300
    if (ctx->r3 != ctx->r16) {
        // 0x80008338: swc1        $f20, -0x28($v0)
        MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
            goto L_80008300;
    }
    // 0x80008338: swc1        $f20, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
    // 0x8000833C: addiu       $s3, $s3, 0x180
    ctx->r19 = ADD32(ctx->r19, 0X180);
    // 0x80008340: sltu        $at, $s3, $s5
    ctx->r1 = ctx->r19 < ctx->r21 ? 1 : 0;
    // 0x80008344: addiu       $s1, $s1, 0x180
    ctx->r17 = ADD32(ctx->r17, 0X180);
    // 0x80008348: bne         $at, $zero, L_80008294
    if (ctx->r1 != 0) {
        // 0x8000834C: addiu       $s2, $s2, 0x180
        ctx->r18 = ADD32(ctx->r18, 0X180);
            goto L_80008294;
    }
    // 0x8000834C: addiu       $s2, $s2, 0x180
    ctx->r18 = ADD32(ctx->r18, 0X180);
    // 0x80008350: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80008354: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80008358: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8000835C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80008360: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80008364: addiu       $t0, $t0, -0x4E60
    ctx->r8 = ADD32(ctx->r8, -0X4E60);
    // 0x80008368: addiu       $a3, $a3, -0x53A0
    ctx->r7 = ADD32(ctx->r7, -0X53A0);
    // 0x8000836C: addiu       $a2, $a2, -0x53A4
    ctx->r6 = ADD32(ctx->r6, -0X53A4);
    // 0x80008370: addiu       $a1, $a1, -0x53A8
    ctx->r5 = ADD32(ctx->r5, -0X53A8);
    // 0x80008374: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
L_80008378:
    // 0x80008378: sb          $s4, 0xB8($a1)
    MEM_B(0XB8, ctx->r5) = ctx->r20;
    // 0x8000837C: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80008380: swc1        $f0, 0xBC($a1)
    MEM_W(0XBC, ctx->r5) = ctx->f0.u32l;
    // 0x80008384: swc1        $f20, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f20.u32l;
    // 0x80008388: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8000838C: swc1        $f20, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f20.u32l;
    // 0x80008390: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    // 0x80008394: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x80008398: swc1        $f20, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f20.u32l;
    // 0x8000839C: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x800083A0: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x800083A4: swc1        $f20, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f20.u32l;
    // 0x800083A8: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x800083AC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800083B0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800083B4:
    // 0x800083B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800083B8: swc1        $f20, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f20.u32l;
    // 0x800083BC: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x800083C0: swc1        $f20, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f20.u32l;
    // 0x800083C4: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x800083C8: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    // 0x800083CC: swc1        $f20, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f20.u32l;
    // 0x800083D0: swc1        $f20, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f20.u32l;
    // 0x800083D4: swc1        $f20, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f20.u32l;
    // 0x800083D8: swc1        $f20, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x800083DC: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800083E0: swc1        $f20, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->f20.u32l;
    // 0x800083E4: swc1        $f20, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x800083E8: bne         $v1, $a0, L_800083B4
    if (ctx->r3 != ctx->r4) {
        // 0x800083EC: swc1        $f20, -0x28($v0)
        MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
            goto L_800083B4;
    }
    // 0x800083EC: swc1        $f20, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = ctx->f20.u32l;
    // 0x800083F0: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
    // 0x800083F4: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    // 0x800083F8: bne         $a3, $t0, L_80008378
    if (ctx->r7 != ctx->r8) {
        // 0x800083FC: addiu       $a2, $a2, 0xC0
        ctx->r6 = ADD32(ctx->r6, 0XC0);
            goto L_80008378;
    }
    // 0x800083FC: addiu       $a2, $a2, 0xC0
    ctx->r6 = ADD32(ctx->r6, 0XC0);
    // 0x80008400: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80008404: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80008408: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8000840C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80008410: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80008414: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80008418: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000841C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80008420: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80008424: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80008428: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000842C: sb          $zero, -0x4E68($at)
    MEM_B(-0X4E68, ctx->r1) = 0;
    // 0x80008430: jr          $ra
    // 0x80008434: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80008434: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void light_disable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032250: jr          $ra
    // 0x80032254: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    return;
    // 0x80032254: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
;}
RECOMP_FUNC void generate_collision_candidates(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031170: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80031174: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80031178: lui         $t1, 0xFFFE
    ctx->r9 = S32(0XFFFE << 16);
    // 0x8003117C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80031180: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80031184: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80031188: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8003118C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80031190: ori         $t0, $t0, 0x86A0
    ctx->r8 = ctx->r8 | 0X86A0;
    // 0x80031194: ori         $t1, $t1, 0x7960
    ctx->r9 = ctx->r9 | 0X7960;
    // 0x80031198: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8003119C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800311A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800311A4: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
    // 0x800311A8: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
    // 0x800311AC: or          $s3, $t0, $zero
    ctx->r19 = ctx->r8 | 0;
    // 0x800311B0: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x800311B4: beq         $a0, $zero, L_8003128C
    if (ctx->r4 == 0) {
        // 0x800311B8: or          $s6, $a3, $zero
        ctx->r22 = ctx->r7 | 0;
            goto L_8003128C;
    }
    // 0x800311B8: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x800311BC: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x800311C0: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x800311C4: add         $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x800311C8: add         $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
L_800311CC:
    // 0x800311CC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800311D0: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800311D4: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800311D8: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800311DC: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800311E0: trunc.w.s   $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800311E4: mfc1        $t0, $f0
    ctx->r8 = (int32_t)ctx->f0.u32l;
    // 0x800311E8: trunc.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800311EC: mfc1        $t1, $f2
    ctx->r9 = (int32_t)ctx->f2.u32l;
    // 0x800311F0: slt         $at, $s4, $t0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800311F4: trunc.w.s   $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800311F8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800311FC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80031200: beql        $at, $zero, L_80031210
    if (ctx->r1 == 0) {
        // 0x80031204: slt         $at, $t0, $s5
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_80031210;
    }
    goto skip_0;
    // 0x80031204: slt         $at, $t0, $s5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
    skip_0:
    // 0x80031208: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
    // 0x8003120C: slt         $at, $t0, $s5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
L_80031210:
    // 0x80031210: beql        $at, $zero, L_80031220
    if (ctx->r1 == 0) {
        // 0x80031214: slt         $at, $s2, $t1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80031220;
    }
    goto skip_1;
    // 0x80031214: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    skip_1:
    // 0x80031218: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
    // 0x8003121C: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
L_80031220:
    // 0x80031220: beql        $at, $zero, L_80031230
    if (ctx->r1 == 0) {
        // 0x80031224: slt         $at, $t1, $s3
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80031230;
    }
    goto skip_2;
    // 0x80031224: slt         $at, $t1, $s3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r19) ? 1 : 0;
    skip_2:
    // 0x80031228: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x8003122C: slt         $at, $t1, $s3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r19) ? 1 : 0;
L_80031230:
    // 0x80031230: beql        $at, $zero, L_80031240
    if (ctx->r1 == 0) {
        // 0x80031234: slt         $at, $s4, $t2
        ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80031240;
    }
    goto skip_3;
    // 0x80031234: slt         $at, $s4, $t2
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
    skip_3:
    // 0x80031238: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x8003123C: slt         $at, $s4, $t2
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
L_80031240:
    // 0x80031240: beql        $at, $zero, L_80031250
    if (ctx->r1 == 0) {
        // 0x80031244: slt         $at, $t2, $s5
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_80031250;
    }
    goto skip_4;
    // 0x80031244: slt         $at, $t2, $s5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r21) ? 1 : 0;
    skip_4:
    // 0x80031248: or          $s4, $t2, $zero
    ctx->r20 = ctx->r10 | 0;
    // 0x8003124C: slt         $at, $t2, $s5
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r21) ? 1 : 0;
L_80031250:
    // 0x80031250: beql        $at, $zero, L_80031260
    if (ctx->r1 == 0) {
        // 0x80031254: slt         $at, $s2, $t3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80031260;
    }
    goto skip_5;
    // 0x80031254: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    skip_5:
    // 0x80031258: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
    // 0x8003125C: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
L_80031260:
    // 0x80031260: beql        $at, $zero, L_80031270
    if (ctx->r1 == 0) {
        // 0x80031264: slt         $at, $t3, $s3
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80031270;
    }
    goto skip_6;
    // 0x80031264: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
    skip_6:
    // 0x80031268: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x8003126C: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
L_80031270:
    // 0x80031270: beql        $at, $zero, L_80031280
    if (ctx->r1 == 0) {
        // 0x80031274: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_80031280;
    }
    goto skip_7;
    // 0x80031274: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    skip_7:
    // 0x80031278: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x8003127C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_80031280:
    // 0x80031280: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80031284: bne         $at, $zero, L_800311CC
    if (ctx->r1 != 0) {
        // 0x80031288: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_800311CC;
    }
    // 0x80031288: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
L_8003128C:
    // 0x8003128C: addiu       $s5, $s5, -0x14
    ctx->r21 = ADD32(ctx->r21, -0X14);
    // 0x80031290: addiu       $s4, $s4, 0x14
    ctx->r20 = ADD32(ctx->r20, 0X14);
    // 0x80031294: slt         $at, $s4, $s5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80031298: addiu       $s3, $s3, -0x14
    ctx->r19 = ADD32(ctx->r19, -0X14);
    // 0x8003129C: beq         $at, $zero, L_800312B0
    if (ctx->r1 == 0) {
        // 0x800312A0: addiu       $s2, $s2, 0x14
        ctx->r18 = ADD32(ctx->r18, 0X14);
            goto L_800312B0;
    }
    // 0x800312A0: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x800312A4: or          $t0, $s5, $zero
    ctx->r8 = ctx->r21 | 0;
    // 0x800312A8: or          $s5, $s4, $zero
    ctx->r21 = ctx->r20 | 0;
    // 0x800312AC: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
L_800312B0:
    // 0x800312B0: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800312B4: beq         $at, $zero, L_800312C8
    if (ctx->r1 == 0) {
        // 0x800312B8: nop
    
            goto L_800312C8;
    }
    // 0x800312B8: nop

    // 0x800312BC: or          $t0, $s3, $zero
    ctx->r8 = ctx->r19 | 0;
    // 0x800312C0: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x800312C4: or          $s2, $t0, $zero
    ctx->r18 = ctx->r8 | 0;
L_800312C8:
    // 0x800312C8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800312CC: lw          $t0, -0x3178($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3178);
    // 0x800312D0: addi        $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x800312D4: addi        $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x800312D8: lh          $t7, 0x1A($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X1A);
    // 0x800312DC: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800312E0: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x800312E4: beq         $t7, $zero, L_80031374
    if (ctx->r15 == 0) {
        // 0x800312E8: lw          $t6, 0x4($t0)
        ctx->r14 = MEM_W(ctx->r8, 0X4);
            goto L_80031374;
    }
    // 0x800312E8: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
L_800312EC:
    // 0x800312EC: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x800312F0: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x800312F4: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x800312F8: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800312FC: bne         $at, $zero, L_80031364
    if (ctx->r1 != 0) {
        // 0x80031300: addiu       $v1, $v1, -0x5
        ctx->r3 = ADD32(ctx->r3, -0X5);
            goto L_80031364;
    }
    // 0x80031300: addiu       $v1, $v1, -0x5
    ctx->r3 = ADD32(ctx->r3, -0X5);
    // 0x80031304: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80031308: bnel        $at, $zero, L_80031368
    if (ctx->r1 != 0) {
        // 0x8003130C: addiu       $t7, $t7, -0x1
        ctx->r15 = ADD32(ctx->r15, -0X1);
            goto L_80031368;
    }
    goto skip_8;
    // 0x8003130C: addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
    skip_8:
    // 0x80031310: lh          $t0, 0xA($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XA);
    // 0x80031314: lh          $t1, 0x4($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4);
    // 0x80031318: addiu       $t0, $t0, 0x5
    ctx->r8 = ADD32(ctx->r8, 0X5);
    // 0x8003131C: slt         $at, $t0, $s3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80031320: bne         $at, $zero, L_80031364
    if (ctx->r1 != 0) {
        // 0x80031324: addiu       $t1, $t1, -0x5
        ctx->r9 = ADD32(ctx->r9, -0X5);
            goto L_80031364;
    }
    // 0x80031324: addiu       $t1, $t1, -0x5
    ctx->r9 = ADD32(ctx->r9, -0X5);
    // 0x80031328: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8003132C: bnel        $at, $zero, L_80031368
    if (ctx->r1 != 0) {
        // 0x80031330: addiu       $t7, $t7, -0x1
        ctx->r15 = ADD32(ctx->r15, -0X1);
            goto L_80031368;
    }
    goto skip_9;
    // 0x80031330: addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
    skip_9:
    // 0x80031334: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80031338: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8003133C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80031340: jal         0x8003151C
    // 0x80031344: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    compute_grid_overlap_mask(rdram, ctx);
        goto after_0;
    // 0x80031344: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // 0x80031348: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8003134C: addiu       $t8, $t8, 0x1
    ctx->r24 = ADD32(ctx->r24, 0X1);
    // 0x80031350: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80031354: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80031358: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8003135C: beq         $t8, $at, L_80031374
    if (ctx->r24 == ctx->r1) {
        // 0x80031360: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80031374;
    }
    // 0x80031360: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80031364:
    // 0x80031364: addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
L_80031368:
    // 0x80031368: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8003136C: bne         $t7, $zero, L_800312EC
    if (ctx->r15 != 0) {
        // 0x80031370: addiu       $t6, $t6, 0x44
        ctx->r14 = ADD32(ctx->r14, 0X44);
            goto L_800312EC;
    }
    // 0x80031370: addiu       $t6, $t6, 0x44
    ctx->r14 = ADD32(ctx->r14, 0X44);
L_80031374:
    // 0x80031374: beq         $t8, $zero, L_800314E8
    if (ctx->r24 == 0) {
        // 0x80031378: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800314E8;
    }
    // 0x80031378: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003137C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80031380: lw          $a0, -0x3178($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3178);
    // 0x80031384: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80031388: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8003138C: addi        $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80031390: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80031394: lw          $s2, -0x2710($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X2710);
    // 0x80031398: lw          $t9, -0x270C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X270C);
    // 0x8003139C: addi        $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x800313A0: add         $t8, $s1, $t8
    ctx->r24 = ADD32(ctx->r17, ctx->r24);
    // 0x800313A4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
L_800313A8:
    // 0x800313A8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800313AC: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800313B0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800313B4: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x800313B8: and         $v0, $t7, $at
    ctx->r2 = ctx->r15 & ctx->r1;
    // 0x800313BC: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800313C0: lh          $t0, 0x20($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X20);
    // 0x800313C4: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x800313C8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800313CC: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x800313D0: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x800313D4: add         $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x800313D8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800313DC: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800313E0: add         $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x800313E4: addiu       $t4, $t5, 0xC
    ctx->r12 = ADD32(ctx->r13, 0XC);
L_800313E8:
    // 0x800313E8: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x800313EC: andi        $v0, $t0, 0x200
    ctx->r2 = ctx->r8 & 0X200;
    // 0x800313F0: bne         $v0, $zero, L_800314C8
    if (ctx->r2 != 0) {
        // 0x800313F4: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800314C8;
    }
    // 0x800313F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800313F8: bnel        $s6, $at, L_80031410
    if (ctx->r22 != ctx->r1) {
        // 0x800313FC: lbu         $v1, 0x0($t5)
        ctx->r3 = MEM_BU(ctx->r13, 0X0);
            goto L_80031410;
    }
    goto skip_10;
    // 0x800313FC: lbu         $v1, 0x0($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X0);
    skip_10:
    // 0x80031400: andi        $v0, $t0, 0x100
    ctx->r2 = ctx->r8 & 0X100;
    // 0x80031404: bnel        $v0, $zero, L_800314CC
    if (ctx->r2 != 0) {
        // 0x80031408: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_800314CC;
    }
    goto skip_11;
    // 0x80031408: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    skip_11:
    // 0x8003140C: lbu         $v1, 0x0($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X0);
L_80031410:
    // 0x80031410: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80031414: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80031418: beql        $v1, $at, L_8003145C
    if (ctx->r3 == ctx->r1) {
        // 0x8003141C: lh          $t0, 0x4($t5)
        ctx->r8 = MEM_H(ctx->r13, 0X4);
            goto L_8003145C;
    }
    goto skip_12;
    // 0x8003141C: lh          $t0, 0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X4);
    skip_12:
    // 0x80031420: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80031424: add         $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80031428: lb          $t2, 0x7($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X7);
    // 0x8003142C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80031430: beq         $t2, $at, L_800314C8
    if (ctx->r10 == ctx->r1) {
        // 0x80031434: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800314C8;
    }
    // 0x80031434: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80031438: bne         $s6, $at, L_80031448
    if (ctx->r22 != ctx->r1) {
        // 0x8003143C: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80031448;
    }
    // 0x8003143C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80031440: beql        $t2, $at, L_800314CC
    if (ctx->r10 == ctx->r1) {
        // 0x80031444: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_800314CC;
    }
    goto skip_13;
    // 0x80031444: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    skip_13:
L_80031448:
    // 0x80031448: beq         $s6, $zero, L_80031458
    if (ctx->r22 == 0) {
        // 0x8003144C: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80031458;
    }
    // 0x8003144C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80031450: beql        $t2, $at, L_800314CC
    if (ctx->r10 == ctx->r1) {
        // 0x80031454: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_800314CC;
    }
    goto skip_14;
    // 0x80031454: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    skip_14:
L_80031458:
    // 0x80031458: lh          $t0, 0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X4);
L_8003145C:
    // 0x8003145C: lh          $t1, 0x4($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X4);
    // 0x80031460: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x80031464: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    // 0x80031468: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8003146C: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
    // 0x80031470: sll         $v1, $t0, 3
    ctx->r3 = S32(ctx->r8 << 3);
    // 0x80031474: add         $a1, $a2, $t1
    ctx->r5 = ADD32(ctx->r6, ctx->r9);
    // 0x80031478: add         $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8003147C: add         $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
L_80031480:
    // 0x80031480: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x80031484: and         $t0, $t0, $t6
    ctx->r8 = ctx->r8 & ctx->r14;
    // 0x80031488: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x8003148C: beq         $v0, $zero, L_800314B8
    if (ctx->r2 == 0) {
        // 0x80031490: andi        $v1, $t0, 0xFF00
        ctx->r3 = ctx->r8 & 0XFF00;
            goto L_800314B8;
    }
    // 0x80031490: andi        $v1, $t0, 0xFF00
    ctx->r3 = ctx->r8 & 0XFF00;
    // 0x80031494: beql        $v1, $zero, L_800314BC
    if (ctx->r3 == 0) {
        // 0x80031498: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_800314BC;
    }
    goto skip_15;
    // 0x80031498: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_15:
    // 0x8003149C: sw          $a3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r7;
    // 0x800314A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800314A4: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x800314A8: sb          $t2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r10;
    // 0x800314AC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800314B0: beq         $s3, $at, L_800314E8
    if (ctx->r19 == ctx->r1) {
        // 0x800314B4: addiu       $t9, $t9, 0x1
        ctx->r25 = ADD32(ctx->r25, 0X1);
            goto L_800314E8;
    }
    // 0x800314B4: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
L_800314B8:
    // 0x800314B8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_800314BC:
    // 0x800314BC: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800314C0: bne         $at, $zero, L_80031480
    if (ctx->r1 != 0) {
        // 0x800314C4: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80031480;
    }
    // 0x800314C4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_800314C8:
    // 0x800314C8: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
L_800314CC:
    // 0x800314CC: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800314D0: bne         $at, $zero, L_800313E8
    if (ctx->r1 != 0) {
        // 0x800314D4: addiu       $t4, $t4, 0xC
        ctx->r12 = ADD32(ctx->r12, 0XC);
            goto L_800313E8;
    }
    // 0x800314D4: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x800314D8: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800314DC: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800314E0: bne         $at, $zero, L_800313A8
    if (ctx->r1 != 0) {
        // 0x800314E4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800313A8;
    }
    // 0x800314E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800314E8:
    // 0x800314E8: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800314EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800314F0: sw          $s3, -0x2708($at)
    MEM_W(-0X2708, ctx->r1) = ctx->r19;
    // 0x800314F4: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800314F8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800314FC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80031500: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80031504: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80031508: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003150C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80031510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031514: jr          $ra
    // 0x80031518: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80031518: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void menu_options_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084594: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008459C: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x800845A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800845A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800845A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800845AC: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x800845B0: jal         0x800C06F8
    // 0x800845B4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x800845B4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_0:
    // 0x800845B8: jal         0x800C46D0
    // 0x800845BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_1;
    // 0x800845BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x800845C0: jal         0x800C484C
    // 0x800845C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x800845C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800845C8: jal         0x80000BE0
    // 0x800845CC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_3;
    // 0x800845CC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_3:
    // 0x800845D0: jal         0x80000B34
    // 0x800845D4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_4;
    // 0x800845D4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_4:
    // 0x800845D8: jal         0x80000B18
    // 0x800845DC: nop

    music_change_off(rdram, ctx);
        goto after_5;
    // 0x800845DC: nop

    after_5:
    // 0x800845E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800845E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800845E8: jr          $ra
    // 0x800845EC: nop

    return;
    // 0x800845EC: nop

;}
RECOMP_FUNC void obj_loop_smoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800389F8: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800389FC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80038A00: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80038A04: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80038A08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038A10: bne         $t6, $zero, L_80038A30
    if (ctx->r14 != 0) {
        // 0x80038A14: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80038A30;
    }
    // 0x80038A14: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80038A18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80038A1C: lwc1        $f9, 0x65E0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X65E0);
    // 0x80038A20: lwc1        $f8, 0x65E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X65E4);
    // 0x80038A24: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80038A28: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80038A2C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80038A30:
    // 0x80038A30: lwc1        $f18, 0x1C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80038A34: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80038A38: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80038A3C: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80038A40: lh          $t7, 0x18($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X18);
    // 0x80038A44: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80038A48: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80038A4C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80038A50: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80038A54: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80038A58: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80038A5C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80038A60: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80038A64: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    // 0x80038A68: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80038A6C: lh          $t0, 0x18($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X18);
    // 0x80038A70: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80038A74: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x80038A78: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80038A7C: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80038A80: bne         $at, $zero, L_80038A9C
    if (ctx->r1 != 0) {
        // 0x80038A84: swc1        $f8, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
            goto L_80038A9C;
    }
    // 0x80038A84: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80038A88: jal         0x8000FFB8
    // 0x80038A8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    free_object(rdram, ctx);
        goto after_0;
    // 0x80038A8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038A90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038A94: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80038A98: sh          $t1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r9;
L_80038A9C:
    // 0x80038A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038AA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038AA4: jr          $ra
    // 0x80038AA8: nop

    return;
    // 0x80038AA8: nop

;}
RECOMP_FUNC void func_8001F3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F3EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001F3F0: lb          $v0, -0x4CAC($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4CAC);
    // 0x8001F3F4: jr          $ra
    // 0x8001F3F8: nop

    return;
    // 0x8001F3F8: nop

;}
RECOMP_FUNC void snow_vertices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC77C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800AC780: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC784: lw          $v0, -0x7E24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7E24);
    // 0x800AC788: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800AC78C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800AC790: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800AC794: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800AC798: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800AC79C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800AC7A0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800AC7A4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800AC7A8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800AC7AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AC7B0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AC7B4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800AC7B8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800AC7BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AC7C0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AC7C4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800AC7C8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AC7CC: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AC7D0: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800AC7D4: addiu       $s4, $s4, 0x2E98
    ctx->r20 = ADD32(ctx->r20, 0X2E98);
    // 0x800AC7D8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AC7DC: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x800AC7E0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AC7E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC7E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC7EC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800AC7F0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC7F4: lw          $t9, -0x7E8C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7E8C);
    // 0x800AC7F8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AC7FC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800AC800: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800AC804: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800AC808: lw          $s1, 0x2E94($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X2E94);
    // 0x800AC80C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800AC810: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AC814: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800AC818: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AC81C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC820: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC824: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800AC828: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AC82C: addiu       $fp, $fp, -0x7E20
    ctx->r30 = ADD32(ctx->r30, -0X7E20);
    // 0x800AC830: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AC834: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800AC838: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AC83C: addiu       $s7, $s7, 0x2E64
    ctx->r23 = ADD32(ctx->r23, 0X2E64);
    // 0x800AC840: addiu       $s6, $s6, -0x7E48
    ctx->r22 = ADD32(ctx->r22, -0X7E48);
    // 0x800AC844: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800AC848: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AC84C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800AC850: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AC854: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC858: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC85C: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x800AC860: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800AC864: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800AC868: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800AC86C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AC870: blez        $t9, L_800ACACC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800AC874: addiu       $s5, $sp, 0x64
        ctx->r21 = ADD32(ctx->r29, 0X64);
            goto L_800ACACC;
    }
    // 0x800AC874: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x800AC878: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800AC87C: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x800AC880: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800AC884: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800AC888: addiu       $s0, $s0, 0x2E68
    ctx->r16 = ADD32(ctx->r16, 0X2E68);
L_800AC88C:
    // 0x800AC88C: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x800AC890: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800AC894: addu        $v0, $t1, $s3
    ctx->r2 = ADD32(ctx->r9, ctx->r19);
    // 0x800AC898: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800AC89C: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x800AC8A0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800AC8A4: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x800AC8A8: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x800AC8AC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AC8B0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800AC8B4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x800AC8B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AC8BC: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x800AC8C0: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800AC8C4: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800AC8C8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800AC8CC: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x800AC8D0: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x800AC8D4: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x800AC8D8: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800AC8DC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AC8E0: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x800AC8E4: and         $t2, $t9, $t1
    ctx->r10 = ctx->r25 & ctx->r9;
    // 0x800AC8E8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800AC8EC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800AC8F0: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800AC8F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AC8F8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800AC8FC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800AC900: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x800AC904: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800AC908: nop

    // 0x800AC90C: subu        $t6, $t5, $t0
    ctx->r14 = SUB32(ctx->r13, ctx->r8);
    // 0x800AC910: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x800AC914: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800AC918: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800AC91C: nop

    // 0x800AC920: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AC924: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800AC928: jal         0x8006F92C
    // 0x800AC92C: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    mtxf_transform_dir(rdram, ctx);
        goto after_0;
    // 0x800AC92C: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800AC930: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800AC934: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800AC938: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800AC93C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC940: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC944: lh          $t5, 0x0($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X0);
    // 0x800AC948: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AC94C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800AC950: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800AC954: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x800AC958: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800AC95C: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AC960: beq         $at, $zero, L_800ACAB4
    if (ctx->r1 == 0) {
        // 0x800AC964: sh          $t4, 0x74($sp)
        MEM_H(0X74, ctx->r29) = ctx->r12;
            goto L_800ACAB4;
    }
    // 0x800AC964: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800AC968: lw          $t6, 0x4($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X4);
    // 0x800AC96C: sh          $t4, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r12;
    // 0x800AC970: slt         $at, $t6, $t4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AC974: beq         $at, $zero, L_800ACAB4
    if (ctx->r1 == 0) {
        // 0x800AC978: nop
    
            goto L_800ACAB4;
    }
    // 0x800AC978: nop

    // 0x800AC97C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AC980: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800AC984: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AC988: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC98C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC990: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800AC994: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AC998: lh          $t2, 0x24($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X24);
    // 0x800AC99C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AC9A0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800AC9A4: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x800AC9A8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AC9AC: sh          $t4, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r12;
    // 0x800AC9B0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AC9B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AC9B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AC9BC: subu        $t5, $t4, $t2
    ctx->r13 = SUB32(ctx->r12, ctx->r10);
    // 0x800AC9C0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AC9C4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800AC9C8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AC9CC: sh          $t1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r9;
    // 0x800AC9D0: sh          $t5, -0x28($s1)
    MEM_H(-0X28, ctx->r17) = ctx->r13;
    // 0x800AC9D4: lh          $t7, 0x26($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X26);
    // 0x800AC9D8: lh          $t6, 0x72($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X72);
    // 0x800AC9DC: nop

    // 0x800AC9E0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800AC9E4: sh          $t9, -0x26($s1)
    MEM_H(-0X26, ctx->r17) = ctx->r25;
    // 0x800AC9E8: lh          $t1, 0x74($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X74);
    // 0x800AC9EC: nop

    // 0x800AC9F0: sh          $t1, -0x24($s1)
    MEM_H(-0X24, ctx->r17) = ctx->r9;
    // 0x800AC9F4: lh          $t3, 0x24($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X24);
    // 0x800AC9F8: lh          $t8, 0x70($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X70);
    // 0x800AC9FC: nop

    // 0x800ACA00: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800ACA04: sh          $t4, -0x1E($s1)
    MEM_H(-0X1E, ctx->r17) = ctx->r12;
    // 0x800ACA08: lh          $t5, 0x26($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X26);
    // 0x800ACA0C: lh          $t2, 0x72($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X72);
    // 0x800ACA10: nop

    // 0x800ACA14: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x800ACA18: sh          $t6, -0x1C($s1)
    MEM_H(-0X1C, ctx->r17) = ctx->r14;
    // 0x800ACA1C: lh          $t7, 0x74($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X74);
    // 0x800ACA20: nop

    // 0x800ACA24: sh          $t7, -0x1A($s1)
    MEM_H(-0X1A, ctx->r17) = ctx->r15;
    // 0x800ACA28: lh          $t1, 0x24($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X24);
    // 0x800ACA2C: lh          $t9, 0x70($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X70);
    // 0x800ACA30: nop

    // 0x800ACA34: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x800ACA38: sh          $t8, -0x14($s1)
    MEM_H(-0X14, ctx->r17) = ctx->r24;
    // 0x800ACA3C: lh          $t4, 0x26($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X26);
    // 0x800ACA40: lh          $t3, 0x72($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X72);
    // 0x800ACA44: nop

    // 0x800ACA48: subu        $t2, $t3, $t4
    ctx->r10 = SUB32(ctx->r11, ctx->r12);
    // 0x800ACA4C: sh          $t2, -0x12($s1)
    MEM_H(-0X12, ctx->r17) = ctx->r10;
    // 0x800ACA50: lh          $t5, 0x74($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X74);
    // 0x800ACA54: nop

    // 0x800ACA58: sh          $t5, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r13;
    // 0x800ACA5C: lh          $t7, 0x24($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X24);
    // 0x800ACA60: lh          $t6, 0x70($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X70);
    // 0x800ACA64: nop

    // 0x800ACA68: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800ACA6C: sh          $t9, -0xA($s1)
    MEM_H(-0XA, ctx->r17) = ctx->r25;
    // 0x800ACA70: lh          $t8, 0x26($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X26);
    // 0x800ACA74: lh          $t1, 0x72($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X72);
    // 0x800ACA78: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ACA7C: subu        $t3, $t1, $t8
    ctx->r11 = SUB32(ctx->r9, ctx->r24);
    // 0x800ACA80: sh          $t3, -0x8($s1)
    MEM_H(-0X8, ctx->r17) = ctx->r11;
    // 0x800ACA84: lh          $t4, 0x74($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X74);
    // 0x800ACA88: nop

    // 0x800ACA8C: sh          $t4, -0x6($s1)
    MEM_H(-0X6, ctx->r17) = ctx->r12;
    // 0x800ACA90: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800ACA94: nop

    // 0x800ACA98: addiu       $t5, $t2, 0x4
    ctx->r13 = ADD32(ctx->r10, 0X4);
    // 0x800ACA9C: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800ACAA0: lw          $t6, 0x2EA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2EA0);
    // 0x800ACAA4: sra         $t9, $t5, 2
    ctx->r25 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800ACAA8: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800ACAAC: addu        $t8, $t6, $t1
    ctx->r24 = ADD32(ctx->r14, ctx->r9);
    // 0x800ACAB0: sh          $s2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r18;
L_800ACAB4:
    // 0x800ACAB4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800ACAB8: lw          $t3, -0x7E8C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7E8C);
    // 0x800ACABC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800ACAC0: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800ACAC4: bne         $at, $zero, L_800AC88C
    if (ctx->r1 != 0) {
        // 0x800ACAC8: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_800AC88C;
    }
    // 0x800ACAC8: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
L_800ACACC:
    // 0x800ACACC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800ACAD0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800ACAD4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800ACAD8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800ACADC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800ACAE0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800ACAE4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800ACAE8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800ACAEC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800ACAF0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800ACAF4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800ACAF8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800ACAFC: jr          $ra
    // 0x800ACB00: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800ACB00: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void alClose(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8D14: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C8D18: lw          $t6, 0x3D10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3D10);
    // 0x800C8D1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8D24: beql        $t6, $zero, L_800C8D40
    if (ctx->r14 == 0) {
        // 0x800C8D28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8D40;
    }
    goto skip_0;
    // 0x800C8D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C8D2C: jal         0x800D31C0
    // 0x800C8D30: nop

    alSynDelete(rdram, ctx);
        goto after_0;
    // 0x800C8D30: nop

    after_0:
    // 0x800C8D34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C8D38: sw          $zero, 0x3D10($at)
    MEM_W(0X3D10, ctx->r1) = 0;
    // 0x800C8D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8D40:
    // 0x800C8D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8D44: jr          $ra
    // 0x800C8D48: nop

    return;
    // 0x800C8D48: nop

;}
RECOMP_FUNC void camera_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006661C: addiu       $t0, $zero, 0xB6
    ctx->r8 = ADD32(0, 0XB6);
    // 0x80066620: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066624: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x80066628: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006662C: lw          $v0, 0x1264($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1264);
    // 0x80066630: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x80066634: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80066638: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006663C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80066640: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066644: addiu       $t7, $t7, 0x1040
    ctx->r15 = ADD32(ctx->r15, 0X1040);
    // 0x80066648: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8006664C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80066650: mflo        $t8
    ctx->r24 = lo;
    // 0x80066654: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80066658: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x8006665C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066660: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80066664: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80066668: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8006666C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066670: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80066674: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80066678: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x8006667C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80066680: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x80066684: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x80066688: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x8006668C: mflo        $t1
    ctx->r9 = lo;
    // 0x80066690: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x80066694: sh          $zero, 0x38($v1)
    MEM_H(0X38, ctx->r3) = 0;
    // 0x80066698: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006669C: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x800666A0: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x800666A4: swc1        $f0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f0.u32l;
    // 0x800666A8: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x800666AC: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x800666B0: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x800666B4: mflo        $t3
    ctx->r11 = lo;
    // 0x800666B8: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x800666BC: lbu         $t4, -0x2798($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2798);
    // 0x800666C0: jr          $ra
    // 0x800666C4: sb          $t4, 0x3B($v1)
    MEM_B(0X3B, ctx->r3) = ctx->r12;
    return;
    // 0x800666C4: sb          $t4, 0x3B($v1)
    MEM_B(0X3B, ctx->r3) = ctx->r12;
;}
RECOMP_FUNC void move_particle_attached_to_parent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B37A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B37A4: lw          $v0, -0x7DC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DC0);
    // 0x800B37A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B37AC: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B37B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B37B4: beq         $v1, $zero, L_800B380C
    if (ctx->r3 == 0) {
        // 0x800B37B8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B380C;
    }
    // 0x800B37B8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B37BC: lh          $a1, 0x62($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X62);
    // 0x800B37C0: lh          $a2, 0x64($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X64);
    // 0x800B37C4: lh          $a3, 0x66($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X66);
    // 0x800B37C8: lwc1        $f0, 0x28($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B37CC: nop

L_800B37D0:
    // 0x800B37D0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B37D4: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x800B37D8: lh          $t0, 0x4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4);
    // 0x800B37DC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B37E0: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B37E4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800B37E8: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800B37EC: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x800B37F0: addu        $t1, $t0, $a3
    ctx->r9 = ADD32(ctx->r8, ctx->r7);
    // 0x800B37F4: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x800B37F8: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    // 0x800B37FC: sh          $t1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r9;
    // 0x800B3800: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800B3804: bne         $v1, $zero, L_800B37D0
    if (ctx->r3 != 0) {
        // 0x800B3808: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B37D0;
    }
    // 0x800B3808: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800B380C:
    // 0x800B380C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B3810: lwc1        $f8, 0x58($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X58);
    // 0x800B3814: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800B3818: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800B381C: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800B3820: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x800B3824: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B3828: jal         0x80070560
    // 0x800B382C: addiu       $a1, $a0, 0xC
    ctx->r5 = ADD32(ctx->r4, 0XC);
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800B382C: addiu       $a1, $a0, 0xC
    ctx->r5 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800B3830: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800B3834: nop

    // 0x800B3838: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B383C: lwc1        $f18, 0x4C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800B3840: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B3844: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3848: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800B384C: lwc1        $f18, 0x54($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800B3850: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B3854: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x800B3858: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800B385C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3860: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3864: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800B3868: beq         $v0, $zero, L_800B38A8
    if (ctx->r2 == 0) {
        // 0x800B386C: swc1        $f4, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
            goto L_800B38A8;
    }
    // 0x800B386C: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x800B3870: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B3874: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800B3878: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B387C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3880: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B3884: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x800B3888: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800B388C: nop

    // 0x800B3890: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3894: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x800B3898: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800B389C: nop

    // 0x800B38A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B38A4: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
L_800B38A8:
    // 0x800B38A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B38AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B38B0: jr          $ra
    // 0x800B38B4: nop

    return;
    // 0x800B38B4: nop

;}
RECOMP_FUNC void hud_audio_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A10B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A10B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A10BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A10C0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800A10C4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800A10C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A10CC: addiu       $s1, $s1, 0x2D10
    ctx->r17 = ADD32(ctx->r17, 0X2D10);
    // 0x800A10D0: addiu       $s0, $s0, 0x2CF0
    ctx->r16 = ADD32(ctx->r16, 0X2CF0);
L_800A10D4:
    // 0x800A10D4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800A10D8: nop

    // 0x800A10DC: beq         $a0, $zero, L_800A10F4
    if (ctx->r4 == 0) {
        // 0x800A10E0: nop
    
            goto L_800A10F4;
    }
    // 0x800A10E0: nop

    // 0x800A10E4: jal         0x8000488C
    // 0x800A10E8: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x800A10E8: nop

    after_0:
    // 0x800A10EC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800A10F0: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
L_800A10F4:
    // 0x800A10F4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800A10F8: bne         $s0, $s1, L_800A10D4
    if (ctx->r16 != ctx->r17) {
        // 0x800A10FC: nop
    
            goto L_800A10D4;
    }
    // 0x800A10FC: nop

    // 0x800A1100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A1104: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A1108: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A110C: jr          $ra
    // 0x800A1110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A1110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void set_world_shading(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D28C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D290: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001D294: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001D298: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x8001D29C: lh          $t7, 0x32($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X32);
    // 0x8001D2A0: lh          $a3, 0x2A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X2A);
    // 0x8001D2A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D2A8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D2AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001D2B0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001D2B4: addiu       $a0, $a0, -0x4B50
    ctx->r4 = ADD32(ctx->r4, -0X4B50);
    // 0x8001D2B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001D2BC: jal         0x8001D4E8
    // 0x8001D2C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    set_shading_properties(rdram, ctx);
        goto after_0;
    // 0x8001D2C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8001D2C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D2C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D2CC: jr          $ra
    // 0x8001D2D0: nop

    return;
    // 0x8001D2D0: nop

;}
RECOMP_FUNC void music_tempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800015B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800015BC: lh          $v0, 0x62B0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X62B0);
    // 0x800015C0: jr          $ra
    // 0x800015C4: nop

    return;
    // 0x800015C4: nop

;}
RECOMP_FUNC void func_80046524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046564: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x80046568: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004656C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80046570: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80046574: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80046578: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8004657C: sw          $a0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r4;
    // 0x80046580: jal         0x8000E138
    // 0x80046584: sw          $a1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r5;
    func_8000E138(rdram, ctx);
        goto after_0;
    // 0x80046584: sw          $a1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80046588: beq         $v0, $zero, L_800465B0
    if (ctx->r2 == 0) {
        // 0x8004658C: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800465B0;
    }
    // 0x8004658C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80046590: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046594: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80046598: lwc1        $f9, 0x6938($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6938);
    // 0x8004659C: lwc1        $f8, 0x693C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X693C);
    // 0x800465A0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800465A4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800465A8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800465AC: swc1        $f4, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f4.u32l;
L_800465B0:
    // 0x800465B0: sb          $zero, 0x67($sp)
    MEM_B(0X67, ctx->r29) = 0;
    // 0x800465B4: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800465B8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800465BC: bltz        $t6, L_800465EC
    if (SIGNED(ctx->r14) < 0) {
        // 0x800465C0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800465EC;
    }
    // 0x800465C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800465C4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800465C8: lw          $t7, -0x2EF8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2EF8);
    // 0x800465CC: nop

    // 0x800465D0: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800465D4: beq         $at, $zero, L_800465F0
    if (ctx->r1 == 0) {
        // 0x800465D8: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_800465F0;
    }
    // 0x800465D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800465DC: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x800465E0: nop

    // 0x800465E4: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x800465E8: sw          $t9, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r25;
L_800465EC:
    // 0x800465EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_800465F0:
    // 0x800465F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800465F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800465F8: sh          $zero, -0x2530($at)
    MEM_H(-0X2530, ctx->r1) = 0;
    // 0x800465FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046600: sw          $zero, -0x252C($at)
    MEM_W(-0X252C, ctx->r1) = 0;
    // 0x80046604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046608: sw          $zero, -0x2528($at)
    MEM_W(-0X2528, ctx->r1) = 0;
    // 0x8004660C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80046610: lh          $t2, -0x24FA($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X24FA);
    // 0x80046614: swc1        $f6, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f6.u32l;
    // 0x80046618: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004661C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80046620: swc1        $f8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f8.u32l;
    // 0x80046624: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80046628: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8004662C: lui         $at, 0x4620
    ctx->r1 = S32(0X4620 << 16);
    // 0x80046630: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046634: swc1        $f10, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f10.u32l;
    // 0x80046638: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004663C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80046640: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80046644: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80046648: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004664C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80046650: lw          $t3, -0x2524($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2524);
    // 0x80046654: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80046658: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004665C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80046660: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80046664: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80046668: sub.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d - ctx->f4.d;
    // 0x8004666C: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x80046670: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80046674: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80046678: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004667C: swc1        $f8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f8.u32l;
    // 0x80046680: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80046684: nop

    // 0x80046688: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8004668C: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80046690: nop

    // 0x80046694: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80046698: beq         $t3, $at, L_800466AC
    if (ctx->r11 == ctx->r1) {
        // 0x8004669C: swc1        $f8, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
            goto L_800466AC;
    }
    // 0x8004669C: swc1        $f8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f8.u32l;
    // 0x800466A0: lb          $t4, 0x1D8($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D8);
    // 0x800466A4: nop

    // 0x800466A8: beq         $t4, $zero, L_800466B8
    if (ctx->r12 == 0) {
        // 0x800466AC: lui         $at, 0x4200
        ctx->r1 = S32(0X4200 << 16);
            goto L_800466B8;
    }
L_800466AC:
    // 0x800466AC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800466B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800466B4: nop

L_800466B8:
    // 0x800466B8: lb          $t0, 0x1E1($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E1);
    // 0x800466BC: lw          $t5, -0x254C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X254C);
    // 0x800466C0: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800466C4: subu        $v1, $t5, $t0
    ctx->r3 = SUB32(ctx->r13, ctx->r8);
    // 0x800466C8: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800466CC: nop

    // 0x800466D0: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800466D4: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800466D8: nop

    // 0x800466DC: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800466E0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800466E4: nop

    // 0x800466E8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800466EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800466F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800466F4: nop

    // 0x800466F8: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800466FC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80046700: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80046704: beq         $v1, $zero, L_8004672C
    if (ctx->r3 == 0) {
        // 0x80046708: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8004672C;
    }
    // 0x80046708: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8004670C: bne         $v0, $zero, L_80046730
    if (ctx->r2 != 0) {
        // 0x80046710: addu        $t7, $t0, $a3
        ctx->r15 = ADD32(ctx->r8, ctx->r7);
            goto L_80046730;
    }
    // 0x80046710: addu        $t7, $t0, $a3
    ctx->r15 = ADD32(ctx->r8, ctx->r7);
    // 0x80046714: blez        $v1, L_80046720
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80046718: nop
    
            goto L_80046720;
    }
    // 0x80046718: nop

    // 0x8004671C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80046720:
    // 0x80046720: bgez        $v1, L_80046730
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80046724: addu        $t7, $t0, $a3
        ctx->r15 = ADD32(ctx->r8, ctx->r7);
            goto L_80046730;
    }
    // 0x80046724: addu        $t7, $t0, $a3
    ctx->r15 = ADD32(ctx->r8, ctx->r7);
    // 0x80046728: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8004672C:
    // 0x8004672C: addu        $t7, $t0, $a3
    ctx->r15 = ADD32(ctx->r8, ctx->r7);
L_80046730:
    // 0x80046730: sb          $t7, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = ctx->r15;
    // 0x80046734: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80046738: jal         0x80055F00
    // 0x8004673C: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    handle_racer_items(rdram, ctx);
        goto after_1;
    // 0x8004673C: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80046740: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80046744: jal         0x80053604
    // 0x80046748: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800535C4(rdram, ctx);
        goto after_2;
    // 0x80046748: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8004674C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80046750: jal         0x80048CBC
    // 0x80046754: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    racer_attack_handler_hovercraft(rdram, ctx);
        goto after_3;
    // 0x80046754: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80046758: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8004675C: lw          $t8, -0x2524($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2524);
    // 0x80046760: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046764: beq         $t8, $at, L_80046784
    if (ctx->r24 == ctx->r1) {
        // 0x80046768: nop
    
            goto L_80046784;
    }
    // 0x80046768: nop

    // 0x8004676C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80046770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80046774: jal         0x80052204
    // 0x80046778: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    handle_racer_head_turning(rdram, ctx);
        goto after_4;
    // 0x80046778: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8004677C: b           L_8004678C
    // 0x80046780: nop

        goto L_8004678C;
    // 0x80046780: nop

L_80046784:
    // 0x80046784: jal         0x8005238C
    // 0x80046788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    slowly_reset_head_angle(rdram, ctx);
        goto after_5;
    // 0x80046788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8004678C:
    // 0x8004678C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80046790: lw          $t9, -0x2558($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2558);
    // 0x80046794: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80046798: andi        $t2, $t9, 0x8000
    ctx->r10 = ctx->r25 & 0X8000;
    // 0x8004679C: beq         $t2, $zero, L_80046818
    if (ctx->r10 == 0) {
        // 0x800467A0: nop
    
            goto L_80046818;
    }
    // 0x800467A0: nop

    // 0x800467A4: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800467A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800467AC: lwc1        $f11, 0x6940($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6940);
    // 0x800467B0: lwc1        $f10, 0x6944($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6944);
    // 0x800467B4: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800467B8: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800467BC: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800467C0: swc1        $f9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800467C4: lwc1        $f4, 0xB4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x800467C8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800467CC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800467D0: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800467D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800467D8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800467DC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800467E0: swc1        $f4, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f4.u32l;
    // 0x800467E4: lwc1        $f2, 0xB4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x800467E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800467EC: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800467F0: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x800467F4: nop

    // 0x800467F8: bc1f        L_80046880
    if (!c1cs) {
        // 0x800467FC: nop
    
            goto L_80046880;
    }
    // 0x800467FC: nop

    // 0x80046800: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80046804: nop

    // 0x80046808: swc1        $f10, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f10.u32l;
    // 0x8004680C: lwc1        $f2, 0xB4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80046810: b           L_80046884
    // 0x80046814: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
        goto L_80046884;
    // 0x80046814: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
L_80046818:
    // 0x80046818: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8004681C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046820: lwc1        $f7, 0x6948($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6948);
    // 0x80046824: lwc1        $f6, 0x694C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X694C);
    // 0x80046828: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8004682C: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x80046830: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80046834: swc1        $f9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x80046838: lwc1        $f4, 0xB4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x8004683C: nop

    // 0x80046840: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80046844: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x80046848: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004684C: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80046850: swc1        $f4, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f4.u32l;
    // 0x80046854: lwc1        $f2, 0xB4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80046858: nop

    // 0x8004685C: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80046860: nop

    // 0x80046864: bc1f        L_80046880
    if (!c1cs) {
        // 0x80046868: nop
    
            goto L_80046880;
    }
    // 0x80046868: nop

    // 0x8004686C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80046870: nop

    // 0x80046874: swc1        $f10, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f10.u32l;
    // 0x80046878: lwc1        $f2, 0xB4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x8004687C: nop

L_80046880:
    // 0x80046880: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
L_80046884:
    // 0x80046884: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80046888: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8004688C: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x80046890: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80046894: bc1f        L_800468B8
    if (!c1cs) {
        // 0x80046898: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800468B8;
    }
    // 0x80046898: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004689C: lw          $t3, -0x2558($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2558);
    // 0x800468A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800468A4: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x800468A8: beq         $t4, $zero, L_800468B8
    if (ctx->r12 == 0) {
        // 0x800468AC: nop
    
            goto L_800468B8;
    }
    // 0x800468AC: nop

    // 0x800468B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800468B4: nop

L_800468B8:
    // 0x800468B8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800468BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800468C0: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800468C4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800468C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800468CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800468D0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800468D4: nop

    // 0x800468D8: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800468DC: swc1        $f12, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f12.u32l;
    // 0x800468E0: lw          $t5, 0x108($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X108);
    // 0x800468E4: nop

    // 0x800468E8: beq         $t5, $zero, L_800468FC
    if (ctx->r13 == 0) {
        // 0x800468EC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800468FC;
    }
    // 0x800468EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800468F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800468F4: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800468F8: swc1        $f6, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f6.u32l;
L_800468FC:
    // 0x800468FC: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80046900: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80046904: lw          $a0, -0x2558($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2558);
    // 0x80046908: bc1f        L_8004692C
    if (!c1cs) {
        // 0x8004690C: andi        $t6, $a0, 0x4000
        ctx->r14 = ctx->r4 & 0X4000;
            goto L_8004692C;
    }
    // 0x8004690C: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x80046910: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046914: lwc1        $f7, 0x6950($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6950);
    // 0x80046918: lwc1        $f6, 0x6954($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6954);
    // 0x8004691C: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80046920: mul.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80046924: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80046928: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
L_8004692C:
    // 0x8004692C: beq         $t6, $zero, L_800469EC
    if (ctx->r14 == 0) {
        // 0x80046930: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800469EC;
    }
    // 0x80046930: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80046934: lw          $t7, -0x2548($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2548);
    // 0x80046938: lwc1        $f7, 0x50($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x8004693C: slti        $at, $t7, -0x28
    ctx->r1 = SIGNED(ctx->r15) < -0X28 ? 1 : 0;
    // 0x80046940: bne         $at, $zero, L_8004695C
    if (ctx->r1 != 0) {
        // 0x80046944: nop
    
            goto L_8004695C;
    }
    // 0x80046944: nop

    // 0x80046948: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004694C: nop

    // 0x80046950: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x80046954: nop

    // 0x80046958: bc1f        L_800469EC
    if (!c1cs) {
        // 0x8004695C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800469EC;
    }
L_8004695C:
    // 0x8004695C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046960: lwc1        $f5, 0x6958($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6958);
    // 0x80046964: lwc1        $f4, 0x695C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X695C);
    // 0x80046968: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004696C: lwc1        $f10, 0xB8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80046970: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80046974: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80046978: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004697C: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x80046980: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80046984: swc1        $f10, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f10.u32l;
    // 0x80046988: lwc1        $f8, 0xB8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x8004698C: lwc1        $f6, 0x6964($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6964);
    // 0x80046990: lwc1        $f7, 0x6960($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6960);
    // 0x80046994: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80046998: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x8004699C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800469A0: bc1f        L_800469B4
    if (!c1cs) {
        // 0x800469A4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800469B4;
    }
    // 0x800469A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800469A8: lwc1        $f10, 0x6968($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6968);
    // 0x800469AC: nop

    // 0x800469B0: swc1        $f10, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f10.u32l;
L_800469B4:
    // 0x800469B4: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800469B8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800469BC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800469C0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800469C4: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x800469C8: nop

    // 0x800469CC: bc1f        L_800469E0
    if (!c1cs) {
        // 0x800469D0: nop
    
            goto L_800469E0;
    }
    // 0x800469D0: nop

    // 0x800469D4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800469D8: jal         0x80072594
    // 0x800469DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    rumble_set(rdram, ctx);
        goto after_6;
    // 0x800469DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
L_800469E0:
    // 0x800469E0: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x800469E4: b           L_80046A4C
    // 0x800469E8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
        goto L_80046A4C;
    // 0x800469E8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_800469EC:
    // 0x800469EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800469F0: lwc1        $f9, 0x6970($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6970);
    // 0x800469F4: lwc1        $f8, 0x6974($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6974);
    // 0x800469F8: lwc1        $f11, 0x50($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x800469FC: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80046A00: lwc1        $f4, 0xB8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80046A04: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80046A08: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80046A0C: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x80046A10: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80046A14: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80046A18: swc1        $f4, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f4.u32l;
    // 0x80046A1C: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80046A20: nop

    // 0x80046A24: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80046A28: nop

    // 0x80046A2C: bc1f        L_80046A4C
    if (!c1cs) {
        // 0x80046A30: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80046A4C;
    }
    // 0x80046A30: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80046A34: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80046A38: nop

    // 0x80046A3C: swc1        $f6, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f6.u32l;
    // 0x80046A40: lwc1        $f2, 0xB8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80046A44: nop

    // 0x80046A48: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_80046A4C:
    // 0x80046A4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046A50: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80046A54: mul.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80046A58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80046A5C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80046A60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80046A64: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80046A68: nop

    // 0x80046A6C: div.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80046A70: swc1        $f12, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f12.u32l;
    // 0x80046A74: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80046A78: nop

    // 0x80046A7C: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80046A80: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80046A84: nop

    // 0x80046A88: bc1f        L_80046AA8
    if (!c1cs) {
        // 0x80046A8C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80046AA8;
    }
    // 0x80046A8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80046A90: lwc1        $f11, 0x6978($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6978);
    // 0x80046A94: lwc1        $f10, 0x697C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X697C);
    // 0x80046A98: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80046A9C: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80046AA0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80046AA4: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
L_80046AA8:
    // 0x80046AA8: lbu         $t8, 0x1F5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1F5);
    // 0x80046AAC: nop

    // 0x80046AB0: beq         $t8, $zero, L_80046C18
    if (ctx->r24 == 0) {
        // 0x80046AB4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80046C18;
    }
    // 0x80046AB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046AB8: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
    // 0x80046ABC: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    // 0x80046AC0: lh          $v0, 0x1A0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A0);
    // 0x80046AC4: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x80046AC8: sb          $zero, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = 0;
    // 0x80046ACC: sb          $zero, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = 0;
    // 0x80046AD0: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x80046AD4: lh          $t2, 0x0($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X0);
    // 0x80046AD8: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x80046ADC: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80046AE0: subu        $v1, $t2, $t3
    ctx->r3 = SUB32(ctx->r10, ctx->r11);
    // 0x80046AE4: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80046AE8: lw          $t4, 0x128($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X128);
    // 0x80046AEC: bne         $at, $zero, L_80046AFC
    if (ctx->r1 != 0) {
        // 0x80046AF0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80046AFC;
    }
    // 0x80046AF0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80046AF4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80046AF8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80046AFC:
    // 0x80046AFC: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80046B00: beq         $at, $zero, L_80046B0C
    if (ctx->r1 == 0) {
        // 0x80046B04: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80046B0C;
    }
    // 0x80046B04: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80046B08: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80046B0C:
    // 0x80046B0C: multu       $v1, $t4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046B10: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80046B14: mflo        $t5
    ctx->r13 = lo;
    // 0x80046B18: sra         $t6, $t5, 3
    ctx->r14 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80046B1C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80046B20: beq         $at, $zero, L_80046B34
    if (ctx->r1 == 0) {
        // 0x80046B24: sh          $t7, 0x1A0($s0)
        MEM_H(0X1A0, ctx->r16) = ctx->r15;
            goto L_80046B34;
    }
    // 0x80046B24: sh          $t7, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r15;
    // 0x80046B28: slti        $at, $v1, -0x3FF
    ctx->r1 = SIGNED(ctx->r3) < -0X3FF ? 1 : 0;
    // 0x80046B2C: beq         $at, $zero, L_80046B44
    if (ctx->r1 == 0) {
        // 0x80046B30: nop
    
            goto L_80046B44;
    }
    // 0x80046B30: nop

L_80046B34:
    // 0x80046B34: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80046B38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046B3C: bne         $t8, $at, L_80046BC4
    if (ctx->r24 != ctx->r1) {
        // 0x80046B40: nop
    
            goto L_80046BC4;
    }
    // 0x80046B40: nop

L_80046B44:
    // 0x80046B44: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80046B48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046B4C: beq         $t9, $at, L_80046B7C
    if (ctx->r25 == ctx->r1) {
        // 0x80046B50: addiu       $a0, $zero, 0x107
        ctx->r4 = ADD32(0, 0X107);
            goto L_80046B7C;
    }
    // 0x80046B50: addiu       $a0, $zero, 0x107
    ctx->r4 = ADD32(0, 0X107);
    // 0x80046B54: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80046B58: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x80046B5C: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80046B60: jal         0x80001EA8
    // 0x80046B64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_7;
    // 0x80046B64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80046B68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80046B6C: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80046B70: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80046B74: jal         0x800570F8
    // 0x80046B78: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_8;
    // 0x80046B78: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_8:
L_80046B7C:
    // 0x80046B7C: jal         0x8000C8B4
    // 0x80046B80: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    normalise_time(rdram, ctx);
        goto after_9;
    // 0x80046B80: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_9:
    // 0x80046B84: lbu         $t3, 0x20C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20C);
    // 0x80046B88: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80046B8C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x80046B90: beq         $t3, $zero, L_80046BA8
    if (ctx->r11 == 0) {
        // 0x80046B94: sb          $t2, 0x203($s0)
        MEM_B(0X203, ctx->r16) = ctx->r10;
            goto L_80046BA8;
    }
    // 0x80046B94: sb          $t2, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r10;
    // 0x80046B98: lb          $t4, 0x203($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X203);
    // 0x80046B9C: nop

    // 0x80046BA0: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x80046BA4: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
L_80046BA8:
    // 0x80046BA8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80046BAC: sb          $zero, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = 0;
    // 0x80046BB0: jal         0x80072594
    // 0x80046BB4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_10;
    // 0x80046BB4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_10:
    // 0x80046BB8: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80046BBC: b           L_80046C1C
    // 0x80046BC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
        goto L_80046C1C;
    // 0x80046BC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80046BC4:
    // 0x80046BC4: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80046BC8: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80046BCC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80046BD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046BD4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80046BD8: mul.d       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80046BDC: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80046BE0: nop

    // 0x80046BE4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80046BE8: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80046BEC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80046BF0: mul.d       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80046BF4: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x80046BF8: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80046BFC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80046C00: mul.d       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80046C04: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x80046C08: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80046C0C: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x80046C10: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80046C14: nop

L_80046C18:
    // 0x80046C18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80046C1C:
    // 0x80046C1C: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x80046C20: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80046C24: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80046C28: bc1f        L_80046C34
    if (!c1cs) {
        // 0x80046C2C: lui         $at, 0x402C
        ctx->r1 = S32(0X402C << 16);
            goto L_80046C34;
    }
    // 0x80046C2C: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x80046C30: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80046C34:
    // 0x80046C34: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80046C38: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80046C3C: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x80046C40: nop

    // 0x80046C44: bc1f        L_80046C54
    if (!c1cs) {
        // 0x80046C48: lui         $at, 0x4160
        ctx->r1 = S32(0X4160 << 16);
            goto L_80046C54;
    }
    // 0x80046C48: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80046C4C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80046C50: nop

L_80046C54:
    // 0x80046C54: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80046C58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80046C5C: lb          $t6, 0x1D4($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046C60: div.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80046C64: bne         $t6, $zero, L_80046C80
    if (ctx->r14 != 0) {
        // 0x80046C68: lw          $a1, 0x128($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X128);
            goto L_80046C80;
    }
    // 0x80046C68: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x80046C6C: lb          $t7, 0x1D5($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D5);
    // 0x80046C70: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80046C74: beq         $t7, $zero, L_80046C9C
    if (ctx->r15 == 0) {
        // 0x80046C78: lui         $at, 0x4580
        ctx->r1 = S32(0X4580 << 16);
            goto L_80046C9C;
    }
    // 0x80046C78: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x80046C7C: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
L_80046C80:
    // 0x80046C80: lh          $a2, 0x160($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X160);
    // 0x80046C84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80046C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80046C8C: jal         0x80050890
    // 0x80046C90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    apply_vehicle_rotation_offset(rdram, ctx);
        goto after_11;
    // 0x80046C90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80046C94: b           L_80046CEC
    // 0x80046C98: lb          $t3, 0x1D5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D5);
        goto L_80046CEC;
    // 0x80046C98: lb          $t3, 0x1D5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D5);
L_80046C9C:
    // 0x80046C9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80046CA0: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x80046CA4: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80046CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80046CAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80046CB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80046CB4: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80046CB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80046CBC: nop

    // 0x80046CC0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80046CC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80046CC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80046CCC: nop

    // 0x80046CD0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80046CD4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80046CD8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80046CDC: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x80046CE0: jal         0x80050890
    // 0x80046CE4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    apply_vehicle_rotation_offset(rdram, ctx);
        goto after_12;
    // 0x80046CE4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    after_12:
    // 0x80046CE8: lb          $t3, 0x1D5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D5);
L_80046CEC:
    // 0x80046CEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046CF0: beq         $t3, $zero, L_80046D34
    if (ctx->r11 == 0) {
        // 0x80046CF4: nop
    
            goto L_80046D34;
    }
    // 0x80046CF4: nop

    // 0x80046CF8: lh          $v0, 0x160($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X160);
    // 0x80046CFC: nop

    // 0x80046D00: sra         $t4, $v0, 3
    ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80046D04: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x80046D08: sh          $t5, 0x160($s0)
    MEM_H(0X160, ctx->r16) = ctx->r13;
    // 0x80046D0C: lh          $v0, 0x160($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X160);
    // 0x80046D10: nop

    // 0x80046D14: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80046D18: beq         $at, $zero, L_80046D2C
    if (ctx->r1 == 0) {
        // 0x80046D1C: slti        $at, $v0, -0xF
        ctx->r1 = SIGNED(ctx->r2) < -0XF ? 1 : 0;
            goto L_80046D2C;
    }
    // 0x80046D1C: slti        $at, $v0, -0xF
    ctx->r1 = SIGNED(ctx->r2) < -0XF ? 1 : 0;
    // 0x80046D20: bne         $at, $zero, L_80046D2C
    if (ctx->r1 != 0) {
        // 0x80046D24: nop
    
            goto L_80046D2C;
    }
    // 0x80046D24: nop

    // 0x80046D28: sb          $zero, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = 0;
L_80046D2C:
    // 0x80046D2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046D30: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
L_80046D34:
    // 0x80046D34: lb          $v0, 0x1DB($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1DB);
    // 0x80046D38: nop

    // 0x80046D3C: blez        $v0, L_80046D74
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80046D40: nop
    
            goto L_80046D74;
    }
    // 0x80046D40: nop

    // 0x80046D44: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80046D48: lb          $t6, 0x1D4($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046D4C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80046D50: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x80046D54: sb          $t7, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r15;
    // 0x80046D58: lb          $t8, 0x1D4($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046D5C: nop

    // 0x80046D60: slti        $at, $t8, 0xB
    ctx->r1 = SIGNED(ctx->r24) < 0XB ? 1 : 0;
    // 0x80046D64: bne         $at, $zero, L_80046E0C
    if (ctx->r1 != 0) {
        // 0x80046D68: nop
    
            goto L_80046E0C;
    }
    // 0x80046D68: nop

    // 0x80046D6C: b           L_80046E0C
    // 0x80046D70: sb          $t9, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r25;
        goto L_80046E0C;
    // 0x80046D70: sb          $t9, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r25;
L_80046D74:
    // 0x80046D74: bgez        $v0, L_80046DAC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80046D78: nop
    
            goto L_80046DAC;
    }
    // 0x80046D78: nop

    // 0x80046D7C: lb          $t2, 0x1D4($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046D80: lw          $t3, 0x128($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X128);
    // 0x80046D84: addiu       $t6, $zero, -0xA
    ctx->r14 = ADD32(0, -0XA);
    // 0x80046D88: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80046D8C: sb          $t4, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r12;
    // 0x80046D90: lb          $t5, 0x1D4($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046D94: nop

    // 0x80046D98: slti        $at, $t5, -0xA
    ctx->r1 = SIGNED(ctx->r13) < -0XA ? 1 : 0;
    // 0x80046D9C: beq         $at, $zero, L_80046E0C
    if (ctx->r1 == 0) {
        // 0x80046DA0: nop
    
            goto L_80046E0C;
    }
    // 0x80046DA0: nop

    // 0x80046DA4: b           L_80046E0C
    // 0x80046DA8: sb          $t6, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r14;
        goto L_80046E0C;
    // 0x80046DA8: sb          $t6, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r14;
L_80046DAC:
    // 0x80046DAC: lb          $v1, 0x1D4($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046DB0: lw          $t7, 0x128($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X128);
    // 0x80046DB4: bgez        $v1, L_80046DDC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80046DB8: addu        $t8, $v1, $t7
        ctx->r24 = ADD32(ctx->r3, ctx->r15);
            goto L_80046DDC;
    }
    // 0x80046DB8: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80046DBC: sb          $t8, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r24;
    // 0x80046DC0: lb          $t9, 0x1D4($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046DC4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80046DC8: blez        $t9, L_80046E0C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80046DCC: nop
    
            goto L_80046E0C;
    }
    // 0x80046DCC: nop

    // 0x80046DD0: sb          $zero, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = 0;
    // 0x80046DD4: b           L_80046E0C
    // 0x80046DD8: sb          $t2, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r10;
        goto L_80046E0C;
    // 0x80046DD8: sb          $t2, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r10;
L_80046DDC:
    // 0x80046DDC: blez        $v1, L_80046E0C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80046DE0: nop
    
            goto L_80046E0C;
    }
    // 0x80046DE0: nop

    // 0x80046DE4: lw          $t3, 0x128($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X128);
    // 0x80046DE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80046DEC: subu        $t4, $v1, $t3
    ctx->r12 = SUB32(ctx->r3, ctx->r11);
    // 0x80046DF0: sb          $t4, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r12;
    // 0x80046DF4: lb          $t5, 0x1D4($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046DF8: nop

    // 0x80046DFC: bgez        $t5, L_80046E0C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80046E00: nop
    
            goto L_80046E0C;
    }
    // 0x80046E00: nop

    // 0x80046E04: sb          $zero, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = 0;
    // 0x80046E08: sb          $t6, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r14;
L_80046E0C:
    // 0x80046E0C: lb          $a1, 0x1E2($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E2);
    // 0x80046E10: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80046E14: beq         $a1, $zero, L_80046E5C
    if (ctx->r5 == 0) {
        // 0x80046E18: slti        $at, $a1, 0x3
        ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
            goto L_80046E5C;
    }
    // 0x80046E18: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80046E1C: beq         $at, $zero, L_80046E5C
    if (ctx->r1 == 0) {
        // 0x80046E20: nop
    
            goto L_80046E5C;
    }
    // 0x80046E20: nop

    // 0x80046E24: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80046E28: nop

    // 0x80046E2C: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046E30: mflo        $t7
    ctx->r15 = lo;
    // 0x80046E34: sra         $t8, $t7, 6
    ctx->r24 = S32(SIGNED(ctx->r15) >> 6);
    // 0x80046E38: subu        $t9, $a0, $t8
    ctx->r25 = SUB32(ctx->r4, ctx->r24);
    // 0x80046E3C: sh          $t9, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r25;
    // 0x80046E40: lh          $a1, 0x1A4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1A4);
    // 0x80046E44: nop

    // 0x80046E48: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046E4C: mflo        $t2
    ctx->r10 = lo;
    // 0x80046E50: sra         $t3, $t2, 6
    ctx->r11 = S32(SIGNED(ctx->r10) >> 6);
    // 0x80046E54: subu        $t4, $a1, $t3
    ctx->r12 = SUB32(ctx->r5, ctx->r11);
    // 0x80046E58: sh          $t4, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r12;
L_80046E5C:
    // 0x80046E5C: lb          $v1, 0x1D4($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046E60: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80046E64: beq         $v1, $zero, L_80046F6C
    if (ctx->r3 == 0) {
        // 0x80046E68: addiu       $a1, $a1, -0x2570
        ctx->r5 = ADD32(ctx->r5, -0X2570);
            goto L_80046F6C;
    }
    // 0x80046E68: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x80046E6C: lh          $v0, 0x160($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X160);
    // 0x80046E70: sb          $zero, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = 0;
    // 0x80046E74: blez        $v1, L_80046ED8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80046E78: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80046ED8;
    }
    // 0x80046E78: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80046E7C: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80046E80: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x80046E84: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80046E88: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x80046E8C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80046E90: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x80046E94: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80046E98: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x80046E9C: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046EA0: slti        $at, $v0, -0x1000
    ctx->r1 = SIGNED(ctx->r2) < -0X1000 ? 1 : 0;
    // 0x80046EA4: mflo        $t6
    ctx->r14 = lo;
    // 0x80046EA8: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80046EAC: beq         $at, $zero, L_80046ED8
    if (ctx->r1 == 0) {
        // 0x80046EB0: sh          $t7, 0x160($s0)
        MEM_H(0X160, ctx->r16) = ctx->r15;
            goto L_80046ED8;
    }
    // 0x80046EB0: sh          $t7, 0x160($s0)
    MEM_H(0X160, ctx->r16) = ctx->r15;
    // 0x80046EB4: lh          $t8, 0x160($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X160);
    // 0x80046EB8: nop

    // 0x80046EBC: slti        $at, $t8, -0x1000
    ctx->r1 = SIGNED(ctx->r24) < -0X1000 ? 1 : 0;
    // 0x80046EC0: bne         $at, $zero, L_80046ED8
    if (ctx->r1 != 0) {
        // 0x80046EC4: nop
    
            goto L_80046ED8;
    }
    // 0x80046EC4: nop

    // 0x80046EC8: lb          $t9, 0x1DB($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1DB);
    // 0x80046ECC: lb          $v1, 0x1D4($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1D4);
    // 0x80046ED0: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80046ED4: sb          $t2, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r10;
L_80046ED8:
    // 0x80046ED8: bgez        $v1, L_80046F40
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80046EDC: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80046F40;
    }
    // 0x80046EDC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80046EE0: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80046EE4: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80046EE8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80046EEC: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80046EF0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80046EF4: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x80046EF8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80046EFC: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80046F00: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80046F04: lh          $t3, 0x160($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X160);
    // 0x80046F08: slti        $at, $t0, 0x1001
    ctx->r1 = SIGNED(ctx->r8) < 0X1001 ? 1 : 0;
    // 0x80046F0C: mflo        $t5
    ctx->r13 = lo;
    // 0x80046F10: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x80046F14: bne         $at, $zero, L_80046F40
    if (ctx->r1 != 0) {
        // 0x80046F18: sh          $t6, 0x160($s0)
        MEM_H(0X160, ctx->r16) = ctx->r14;
            goto L_80046F40;
    }
    // 0x80046F18: sh          $t6, 0x160($s0)
    MEM_H(0X160, ctx->r16) = ctx->r14;
    // 0x80046F1C: lh          $t7, 0x160($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X160);
    // 0x80046F20: nop

    // 0x80046F24: slti        $at, $t7, 0x1001
    ctx->r1 = SIGNED(ctx->r15) < 0X1001 ? 1 : 0;
    // 0x80046F28: beq         $at, $zero, L_80046F40
    if (ctx->r1 == 0) {
        // 0x80046F2C: nop
    
            goto L_80046F40;
    }
    // 0x80046F2C: nop

    // 0x80046F30: lb          $t8, 0x1DB($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1DB);
    // 0x80046F34: nop

    // 0x80046F38: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80046F3C: sb          $t9, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r25;
L_80046F40:
    // 0x80046F40: lw          $t2, -0x2558($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2558);
    // 0x80046F44: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80046F48: ori         $at, $at, 0x3FFF
    ctx->r1 = ctx->r1 | 0X3FFF;
    // 0x80046F4C: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x80046F50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046F54: sw          $t4, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r12;
    // 0x80046F58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046F5C: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
    // 0x80046F60: sb          $zero, 0x1E1($s0)
    MEM_B(0X1E1, ctx->r16) = 0;
    // 0x80046F64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046F68: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
L_80046F6C:
    // 0x80046F6C: lbu         $t3, 0x1F1($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1F1);
    // 0x80046F70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046F74: beq         $t3, $zero, L_80046FAC
    if (ctx->r11 == 0) {
        // 0x80046F78: addiu       $a0, $sp, 0x68
        ctx->r4 = ADD32(ctx->r29, 0X68);
            goto L_80046FAC;
    }
    // 0x80046F78: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80046F7C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80046F80: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80046F84: lh          $t5, 0x160($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X160);
    // 0x80046F88: lh          $t8, 0x162($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X162);
    // 0x80046F8C: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80046F90: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x80046F94: sll         $t6, $t6, 8
    ctx->r14 = S32(ctx->r14 << 8);
    // 0x80046F98: sll         $t9, $t9, 9
    ctx->r25 = S32(ctx->r25 << 9);
    // 0x80046F9C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80046FA0: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80046FA4: sh          $t7, 0x160($s0)
    MEM_H(0X160, ctx->r16) = ctx->r15;
    // 0x80046FA8: sh          $t2, 0x162($s0)
    MEM_H(0X162, ctx->r16) = ctx->r10;
L_80046FAC:
    // 0x80046FAC: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x80046FB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80046FB4: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x80046FB8: lh          $t3, 0x2($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X2);
    // 0x80046FBC: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80046FC0: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x80046FC4: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80046FC8: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x80046FCC: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x80046FD0: jal         0x8006FE70
    // 0x80046FD4: sh          $t3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r11;
    mtxf_from_transform(rdram, ctx);
        goto after_13;
    // 0x80046FD4: sh          $t3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r11;
    after_13:
    // 0x80046FD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80046FDC: addiu       $t5, $s0, 0x38
    ctx->r13 = ADD32(ctx->r16, 0X38);
    // 0x80046FE0: addiu       $t6, $s0, 0x3C
    ctx->r14 = ADD32(ctx->r16, 0X3C);
    // 0x80046FE4: addiu       $t7, $s0, 0x40
    ctx->r15 = ADD32(ctx->r16, 0X40);
    // 0x80046FE8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80046FEC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80046FF0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80046FF4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80046FF8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80046FFC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80047000: jal         0x8006F88C
    // 0x80047004: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_14;
    // 0x80047004: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_14:
    // 0x80047008: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004700C: addiu       $t8, $s0, 0x44
    ctx->r24 = ADD32(ctx->r16, 0X44);
    // 0x80047010: addiu       $t9, $s0, 0x48
    ctx->r25 = ADD32(ctx->r16, 0X48);
    // 0x80047014: addiu       $t2, $s0, 0x4C
    ctx->r10 = ADD32(ctx->r16, 0X4C);
    // 0x80047018: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8004701C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80047020: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80047024: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80047028: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8004702C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80047030: jal         0x8006F88C
    // 0x80047034: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_15;
    // 0x80047034: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_15:
    // 0x80047038: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004703C: addiu       $t4, $s0, 0x50
    ctx->r12 = ADD32(ctx->r16, 0X50);
    // 0x80047040: addiu       $t3, $s0, 0x54
    ctx->r11 = ADD32(ctx->r16, 0X54);
    // 0x80047044: addiu       $t5, $s0, 0x58
    ctx->r13 = ADD32(ctx->r16, 0X58);
    // 0x80047048: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004704C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80047050: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80047054: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80047058: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8004705C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80047060: jal         0x8006F88C
    // 0x80047064: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_16;
    // 0x80047064: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_16:
    // 0x80047068: lw          $t6, 0x148($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X148);
    // 0x8004706C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047070: bne         $t6, $zero, L_800470AC
    if (ctx->r14 != 0) {
        // 0x80047074: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800470AC;
    }
    // 0x80047074: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80047078: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8004707C: lb          $v0, 0x1E1($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E1);
    // 0x80047080: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80047084: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80047088: subu        $v0, $t8, $t7
    ctx->r2 = SUB32(ctx->r24, ctx->r15);
    // 0x8004708C: bgez        $v0, L_8004709C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80047090: slti        $at, $v0, 0x4A
        ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
            goto L_8004709C;
    }
    // 0x80047090: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // 0x80047094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80047098: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
L_8004709C:
    // 0x8004709C: bne         $at, $zero, L_800470A8
    if (ctx->r1 != 0) {
        // 0x800470A0: nop
    
            goto L_800470A8;
    }
    // 0x800470A0: nop

    // 0x800470A4: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
L_800470A8:
    // 0x800470A8: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
L_800470AC:
    // 0x800470AC: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800470B0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800470B4: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x800470B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800470BC: bc1f        L_800470C8
    if (!c1cs) {
        // 0x800470C0: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800470C8;
    }
    // 0x800470C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800470C4: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_800470C8:
    // 0x800470C8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800470CC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800470D0: bc1f        L_800470DC
    if (!c1cs) {
        // 0x800470D4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800470DC;
    }
    // 0x800470D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800470D8: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_800470DC:
    // 0x800470DC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800470E0: lw          $t2, -0x251C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X251C);
    // 0x800470E4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800470E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800470EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800470F0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800470F4: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800470F8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800470FC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80047100: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80047104: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80047108: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004710C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80047110: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80047114: addu        $v1, $t2, $t4
    ctx->r3 = ADD32(ctx->r10, ctx->r12);
    // 0x80047118: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8004711C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80047120: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80047124: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x80047128: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8004712C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80047130: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80047134: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80047138: addiu       $a2, $a2, -0x2514
    ctx->r6 = ADD32(ctx->r6, -0X2514);
    // 0x8004713C: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80047140: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80047144: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80047148: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8004714C: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x80047150: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80047154: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047158: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004715C: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x80047160: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80047164: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80047168: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8004716C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x80047170: lb          $t3, 0x1E2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E2);
    // 0x80047174: nop

    // 0x80047178: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x8004717C: bne         $at, $zero, L_800471C0
    if (ctx->r1 != 0) {
        // 0x80047180: nop
    
            goto L_800471C0;
    }
    // 0x80047180: nop

    // 0x80047184: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80047188: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8004718C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80047190: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047194: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80047198: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8004719C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800471A0: lwc1        $f7, 0x50($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x800471A4: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800471A8: mul.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x800471AC: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800471B0: sub.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f10.d - ctx->f8.d;
    // 0x800471B4: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x800471B8: b           L_800471D8
    // 0x800471BC: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
        goto L_800471D8;
    // 0x800471BC: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
L_800471C0:
    // 0x800471C0: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800471C4: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800471C8: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800471CC: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800471D0: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800471D4: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
L_800471D8:
    // 0x800471D8: lw          $t5, -0x2524($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2524);
    // 0x800471DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800471E0: beq         $t5, $at, L_80047204
    if (ctx->r13 == ctx->r1) {
        // 0x800471E4: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80047204;
    }
    // 0x800471E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800471E8: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x800471EC: nop

    // 0x800471F0: bne         $t6, $zero, L_80047204
    if (ctx->r14 != 0) {
        // 0x800471F4: nop
    
            goto L_80047204;
    }
    // 0x800471F4: nop

    // 0x800471F8: lb          $t0, 0x1E1($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1E1);
    // 0x800471FC: b           L_80047210
    // 0x80047200: nop

        goto L_80047210;
    // 0x80047200: nop

L_80047204:
    // 0x80047204: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80047208: lw          $t0, -0x254C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X254C);
    // 0x8004720C: nop

L_80047210:
    // 0x80047210: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047214: lwc1        $f2, 0x6980($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6980);
    // 0x80047218: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004721C: swc1        $f2, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f2.u32l;
    // 0x80047220: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047224: lwc1        $f5, 0x6988($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6988);
    // 0x80047228: lwc1        $f4, 0x698C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X698C);
    // 0x8004722C: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80047230: mul.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80047234: lwc1        $f11, 0x50($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x80047238: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8004723C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80047240: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80047244: sub.d       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f0.d - ctx->f8.d;
    // 0x80047248: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004724C: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x80047250: lw          $t7, -0x2558($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2558);
    // 0x80047254: nop

    // 0x80047258: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x8004725C: beq         $t8, $zero, L_800472AC
    if (ctx->r24 == 0) {
        // 0x80047260: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800472AC;
    }
    // 0x80047260: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80047264: lw          $t9, -0x2548($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2548);
    // 0x80047268: nop

    // 0x8004726C: slti        $at, $t9, -0x28
    ctx->r1 = SIGNED(ctx->r25) < -0X28 ? 1 : 0;
    // 0x80047270: bne         $at, $zero, L_800472B0
    if (ctx->r1 != 0) {
        // 0x80047274: lw          $a0, 0x128($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X128);
            goto L_800472B0;
    }
    // 0x80047274: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    // 0x80047278: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8004727C: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80047280: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80047284: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047288: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x8004728C: c.le.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d <= ctx->f8.d;
    // 0x80047290: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80047294: bc1f        L_800472B0
    if (!c1cs) {
        // 0x80047298: lw          $a0, 0x128($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X128);
            goto L_800472B0;
    }
    // 0x80047298: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    // 0x8004729C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800472A0: nop

    // 0x800472A4: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800472A8: swc1        $f10, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f10.u32l;
L_800472AC:
    // 0x800472AC: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
L_800472B0:
    // 0x800472B0: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x800472B4: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800472B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800472BC: lw          $v0, -0x2548($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2548);
    // 0x800472C0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800472C4: mflo        $t4
    ctx->r12 = lo;
    // 0x800472C8: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800472CC: nop

    // 0x800472D0: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800472D4: bgez        $v0, L_80047348
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800472D8: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_80047348;
    }
    // 0x800472D8: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x800472DC: negu        $t3, $v0
    ctx->r11 = SUB32(0, ctx->r2);
    // 0x800472E0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800472E4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800472E8: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800472EC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800472F0: lui         $at, 0x405C
    ctx->r1 = S32(0X405C << 16);
    // 0x800472F4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800472F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800472FC: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80047300: nop

    // 0x80047304: div.d       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x80047308: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004730C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80047310: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80047314: add.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d + ctx->f8.d;
    // 0x80047318: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004731C: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80047320: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047324: lwc1        $f11, 0x6990($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6990);
    // 0x80047328: lwc1        $f10, 0x6994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6994);
    // 0x8004732C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047330: div.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x80047334: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80047338: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8004733C: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x80047340: mul.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80047344: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
L_80047348:
    // 0x80047348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004734C: lwc1        $f4, -0x2510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2510);
    // 0x80047350: lh          $t5, 0x1A0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A0);
    // 0x80047354: mul.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80047358: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x8004735C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80047360: nop

    // 0x80047364: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80047368: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004736C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80047370: nop

    // 0x80047374: cvt.w.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = CVT_W_S(ctx->f14.fl);
    // 0x80047378: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8004737C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80047380: subu        $t2, $t5, $t9
    ctx->r10 = SUB32(ctx->r13, ctx->r25);
    // 0x80047384: bne         $t4, $zero, L_800473F0
    if (ctx->r12 != 0) {
        // 0x80047388: sh          $t2, 0x1A0($s0)
        MEM_H(0X1A0, ctx->r16) = ctx->r10;
            goto L_800473F0;
    }
    // 0x80047388: sh          $t2, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r10;
    // 0x8004738C: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80047390: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80047394: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047398: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8004739C: c.eq.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d == ctx->f4.d;
    // 0x800473A0: nop

    // 0x800473A4: bc1f        L_800473F0
    if (!c1cs) {
        // 0x800473A8: nop
    
            goto L_800473F0;
    }
    // 0x800473A8: nop

    // 0x800473AC: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800473B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800473B4: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    // 0x800473B8: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800473BC: nop

    // 0x800473C0: bc1f        L_800473D8
    if (!c1cs) {
        // 0x800473C4: nop
    
            goto L_800473D8;
    }
    // 0x800473C4: nop

    // 0x800473C8: lb          $t3, 0x1E0($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E0);
    // 0x800473CC: nop

    // 0x800473D0: addu        $t6, $t3, $a0
    ctx->r14 = ADD32(ctx->r11, ctx->r4);
    // 0x800473D4: sb          $t6, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r14;
L_800473D8:
    // 0x800473D8: lb          $t7, 0x1E0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E0);
    // 0x800473DC: nop

    // 0x800473E0: slti        $at, $t7, 0x1A
    ctx->r1 = SIGNED(ctx->r15) < 0X1A ? 1 : 0;
    // 0x800473E4: bne         $at, $zero, L_800473F0
    if (ctx->r1 != 0) {
        // 0x800473E8: nop
    
            goto L_800473F0;
    }
    // 0x800473E8: nop

    // 0x800473EC: sb          $t8, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r24;
L_800473F0:
    // 0x800473F0: lb          $a1, 0x1E2($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E2);
    // 0x800473F4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800473F8:
    // 0x800473F8: lbu         $v0, 0x1DC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1DC);
    // 0x800473FC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80047400: beq         $a0, $v0, L_80047430
    if (ctx->r4 == ctx->r2) {
        // 0x80047404: slt         $at, $t1, $v0
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80047430;
    }
    // 0x80047404: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80047408: beq         $at, $zero, L_8004741C
    if (ctx->r1 == 0) {
        // 0x8004740C: nop
    
            goto L_8004741C;
    }
    // 0x8004740C: nop

    // 0x80047410: sll         $t1, $v0, 24
    ctx->r9 = S32(ctx->r2 << 24);
    // 0x80047414: sra         $t5, $t1, 24
    ctx->r13 = S32(SIGNED(ctx->r9) >> 24);
    // 0x80047418: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
L_8004741C:
    // 0x8004741C: bne         $a2, $v0, L_80047434
    if (ctx->r6 != ctx->r2) {
        // 0x80047420: slti        $at, $t0, 0x4
        ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
            goto L_80047434;
    }
    // 0x80047420: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80047424: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80047428: sll         $t9, $a3, 24
    ctx->r25 = S32(ctx->r7 << 24);
    // 0x8004742C: sra         $a3, $t9, 24
    ctx->r7 = S32(SIGNED(ctx->r25) >> 24);
L_80047430:
    // 0x80047430: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
L_80047434:
    // 0x80047434: bne         $at, $zero, L_800473F8
    if (ctx->r1 != 0) {
        // 0x80047438: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800473F8;
    }
    // 0x80047438: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004743C: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x80047440: nop

    // 0x80047444: bne         $t4, $zero, L_8004747C
    if (ctx->r12 != 0) {
        // 0x80047448: nop
    
            goto L_8004747C;
    }
    // 0x80047448: nop

    // 0x8004744C: beq         $a1, $zero, L_8004747C
    if (ctx->r5 == 0) {
        // 0x80047450: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8004747C;
    }
    // 0x80047450: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80047454: bne         $t1, $at, L_8004747C
    if (ctx->r9 != ctx->r1) {
        // 0x80047458: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8004747C;
    }
    // 0x80047458: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004745C: lw          $t3, -0x2554($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2554);
    // 0x80047460: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80047464: andi        $t6, $t3, 0x2000
    ctx->r14 = ctx->r11 & 0X2000;
    // 0x80047468: beq         $t6, $zero, L_8004747C
    if (ctx->r14 == 0) {
        // 0x8004746C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004747C;
    }
    // 0x8004746C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80047470: sb          $t7, -0x24FE($at)
    MEM_B(-0X24FE, ctx->r1) = ctx->r15;
    // 0x80047474: lb          $a1, 0x1E2($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X1E2);
    // 0x80047478: nop

L_8004747C:
    // 0x8004747C: bne         $a1, $zero, L_800474A0
    if (ctx->r5 != 0) {
        // 0x80047480: nop
    
            goto L_800474A0;
    }
    // 0x80047480: nop

    // 0x80047484: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047488: lwc1        $f4, 0xC0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004748C: nop

    // 0x80047490: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80047494: nop

    // 0x80047498: bc1f        L_800475D8
    if (!c1cs) {
        // 0x8004749C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800475D8;
    }
    // 0x8004749C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800474A0:
    // 0x800474A0: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x800474A4: nop

    // 0x800474A8: beq         $v0, $zero, L_800475D8
    if (ctx->r2 == 0) {
        // 0x800474AC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800475D8;
    }
    // 0x800474AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800474B0: beq         $a1, $zero, L_8004752C
    if (ctx->r5 == 0) {
        // 0x800474B4: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8004752C;
    }
    // 0x800474B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800474B8: lw          $t8, -0x2540($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2540);
    // 0x800474BC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800474C0: beq         $t8, $at, L_8004756C
    if (ctx->r24 == ctx->r1) {
        // 0x800474C4: nop
    
            goto L_8004756C;
    }
    // 0x800474C4: nop

    // 0x800474C8: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x800474CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800474D0: beq         $t5, $at, L_8004756C
    if (ctx->r13 == ctx->r1) {
        // 0x800474D4: slti        $at, $v0, 0x6
        ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_8004756C;
    }
    // 0x800474D4: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800474D8: bne         $at, $zero, L_8004756C
    if (ctx->r1 != 0) {
        // 0x800474DC: addiu       $a0, $zero, 0xAE
        ctx->r4 = ADD32(0, 0XAE);
            goto L_8004756C;
    }
    // 0x800474DC: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
    // 0x800474E0: addiu       $a1, $s0, 0x21C
    ctx->r5 = ADD32(ctx->r16, 0X21C);
    // 0x800474E4: sb          $a3, 0xAD($sp)
    MEM_B(0XAD, ctx->r29) = ctx->r7;
    // 0x800474E8: sb          $t1, 0xAF($sp)
    MEM_B(0XAF, ctx->r29) = ctx->r9;
    // 0x800474EC: jal         0x80001D04
    // 0x800474F0: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    sound_play(rdram, ctx);
        goto after_17;
    // 0x800474F0: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x800474F4: lb          $a2, 0x1E0($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1E0);
    // 0x800474F8: lw          $a1, 0x21C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X21C);
    // 0x800474FC: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x80047500: addiu       $a2, $t9, 0x32
    ctx->r6 = ADD32(ctx->r25, 0X32);
    // 0x80047504: andi        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 & 0XFF;
    // 0x80047508: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x8004750C: jal         0x80001FB8
    // 0x80047510: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
    sound_volume_set_relative(rdram, ctx);
        goto after_18;
    // 0x80047510: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
    after_18:
    // 0x80047514: lb          $a3, 0xAD($sp)
    ctx->r7 = MEM_B(ctx->r29, 0XAD);
    // 0x80047518: lb          $t1, 0xAF($sp)
    ctx->r9 = MEM_B(ctx->r29, 0XAF);
    // 0x8004751C: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80047520: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x80047524: b           L_80047570
    // 0x80047528: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
        goto L_80047570;
    // 0x80047528: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_8004752C:
    // 0x8004752C: lw          $t4, 0x148($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X148);
    // 0x80047530: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80047534: bne         $t4, $zero, L_8004756C
    if (ctx->r12 != 0) {
        // 0x80047538: addiu       $a1, $zero, 0xAF
        ctx->r5 = ADD32(0, 0XAF);
            goto L_8004756C;
    }
    // 0x80047538: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // 0x8004753C: sb          $a3, 0xAD($sp)
    MEM_B(0XAD, ctx->r29) = ctx->r7;
    // 0x80047540: sb          $t1, 0xAF($sp)
    MEM_B(0XAF, ctx->r29) = ctx->r9;
    // 0x80047544: jal         0x80057088
    // 0x80047548: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    racer_play_sound(rdram, ctx);
        goto after_19;
    // 0x80047548: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_19:
    // 0x8004754C: lw          $t3, 0x74($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X74);
    // 0x80047550: lb          $a3, 0xAD($sp)
    ctx->r7 = MEM_B(ctx->r29, 0XAD);
    // 0x80047554: lb          $t1, 0xAF($sp)
    ctx->r9 = MEM_B(ctx->r29, 0XAF);
    // 0x80047558: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x8004755C: ori         $t6, $t3, 0x30
    ctx->r14 = ctx->r11 | 0X30;
    // 0x80047560: sw          $t6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r14;
    // 0x80047564: lb          $v0, 0x1E0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E0);
    // 0x80047568: nop

L_8004756C:
    // 0x8004756C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_80047570:
    // 0x80047570: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80047574: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80047578: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004757C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047580: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80047584: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80047588: nop

    // 0x8004758C: bc1f        L_800475D0
    if (!c1cs) {
        // 0x80047590: nop
    
            goto L_800475D0;
    }
    // 0x80047590: nop

    // 0x80047594: lw          $t7, 0x148($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X148);
    // 0x80047598: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004759C: bne         $t7, $zero, L_800475D0
    if (ctx->r15 != 0) {
        // 0x800475A0: nop
    
            goto L_800475D0;
    }
    // 0x800475A0: nop

    // 0x800475A4: lwc1        $f11, 0x6998($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6998);
    // 0x800475A8: lwc1        $f10, 0x699C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X699C);
    // 0x800475AC: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800475B0: mul.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800475B4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800475B8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800475BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800475C0: nop

    // 0x800475C4: sub.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d - ctx->f8.d;
    // 0x800475C8: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800475CC: swc1        $f10, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f10.u32l;
L_800475D0:
    // 0x800475D0: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    // 0x800475D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800475D8:
    // 0x800475D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800475DC: sb          $a3, 0xAD($sp)
    MEM_B(0XAD, ctx->r29) = ctx->r7;
    // 0x800475E0: sb          $t1, 0xAF($sp)
    MEM_B(0XAF, ctx->r29) = ctx->r9;
    // 0x800475E4: jal         0x80057260
    // 0x800475E8: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    handle_racer_top_speed(rdram, ctx);
        goto after_20;
    // 0x800475E8: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x800475EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800475F0: lwc1        $f9, 0x69A0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69A0);
    // 0x800475F4: lwc1        $f8, 0x69A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69A4);
    // 0x800475F8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800475FC: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80047600: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80047604: lb          $v1, 0x1D3($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1D3);
    // 0x80047608: cvt.d.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.d = CVT_D_S(ctx->f18.fl);
    // 0x8004760C: lb          $a3, 0xAD($sp)
    ctx->r7 = MEM_B(ctx->r29, 0XAD);
    // 0x80047610: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80047614: lb          $t1, 0xAF($sp)
    ctx->r9 = MEM_B(ctx->r29, 0XAF);
    // 0x80047618: blez        $v1, L_80047680
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004761C: cvt.s.d     $f18, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
            goto L_80047680;
    }
    // 0x8004761C: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x80047620: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80047624: lw          $v0, -0x2540($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2540);
    // 0x80047628: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004762C: bne         $v0, $zero, L_80047690
    if (ctx->r2 != 0) {
        // 0x80047630: nop
    
            goto L_80047690;
    }
    // 0x80047630: nop

    // 0x80047634: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80047638: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004763C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80047640: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80047644: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047648: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x8004764C: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    // 0x80047650: bc1t        L_80047664
    if (c1cs) {
        // 0x80047654: swc1        $f10, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
            goto L_80047664;
    }
    // 0x80047654: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80047658: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8004765C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80047660: nop

L_80047664:
    // 0x80047664: lw          $t8, 0x128($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X128);
    // 0x80047668: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004766C: subu        $t5, $v1, $t8
    ctx->r13 = SUB32(ctx->r3, ctx->r24);
    // 0x80047670: sb          $t5, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r13;
    // 0x80047674: lw          $v0, -0x2540($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2540);
    // 0x80047678: b           L_80047690
    // 0x8004767C: nop

        goto L_80047690;
    // 0x8004767C: nop

L_80047680:
    // 0x80047680: sb          $zero, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = 0;
    // 0x80047684: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80047688: lw          $v0, -0x2540($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2540);
    // 0x8004768C: nop

L_80047690:
    // 0x80047690: beq         $v0, $zero, L_800476A0
    if (ctx->r2 == 0) {
        // 0x80047694: nop
    
            goto L_800476A0;
    }
    // 0x80047694: nop

    // 0x80047698: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004769C: nop

L_800476A0:
    // 0x800476A0: beq         $a3, $zero, L_800476EC
    if (ctx->r7 == 0) {
        // 0x800476A4: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_800476EC;
    }
    // 0x800476A4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x800476A8: sb          $a3, 0xAD($sp)
    MEM_B(0XAD, ctx->r29) = ctx->r7;
    // 0x800476AC: sb          $t1, 0xAF($sp)
    MEM_B(0XAF, ctx->r29) = ctx->r9;
    // 0x800476B0: jal         0x8001E2D0
    // 0x800476B4: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    get_misc_asset(rdram, ctx);
        goto after_21;
    // 0x800476B4: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_21:
    // 0x800476B8: lb          $a3, 0xAD($sp)
    ctx->r7 = MEM_B(ctx->r29, 0XAD);
    // 0x800476BC: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800476C0: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x800476C4: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x800476C8: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800476CC: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800476D0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800476D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800476D8: lb          $t1, 0xAF($sp)
    ctx->r9 = MEM_B(ctx->r29, 0XAF);
    // 0x800476DC: mul.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800476E0: swc1        $f10, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f10.u32l;
    // 0x800476E4: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x800476E8: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
L_800476EC:
    // 0x800476EC: lb          $t4, 0x1D3($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D3);
    // 0x800476F0: nop

    // 0x800476F4: bne         $t4, $zero, L_8004776C
    if (ctx->r12 != 0) {
        // 0x800476F8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004776C;
    }
    // 0x800476F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800476FC: bne         $t1, $at, L_8004776C
    if (ctx->r9 != ctx->r1) {
        // 0x80047700: addiu       $a0, $zero, 0x2D
        ctx->r4 = ADD32(0, 0X2D);
            goto L_8004776C;
    }
    // 0x80047700: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x80047704: jal         0x8000C8B4
    // 0x80047708: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    normalise_time(rdram, ctx);
        goto after_22;
    // 0x80047708: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_22:
    // 0x8004770C: lbu         $t6, 0x20C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X20C);
    // 0x80047710: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80047714: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80047718: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x8004771C: beq         $t6, $zero, L_80047734
    if (ctx->r14 == 0) {
        // 0x80047720: sb          $t3, 0x203($s0)
        MEM_B(0X203, ctx->r16) = ctx->r11;
            goto L_80047734;
    }
    // 0x80047720: sb          $t3, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r11;
    // 0x80047724: lb          $t7, 0x203($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X203);
    // 0x80047728: nop

    // 0x8004772C: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x80047730: sb          $t8, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r24;
L_80047734:
    // 0x80047734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80047738: addiu       $a1, $zero, 0x107
    ctx->r5 = ADD32(0, 0X107);
    // 0x8004773C: jal         0x80057088
    // 0x80047740: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    racer_play_sound(rdram, ctx);
        goto after_23;
    // 0x80047740: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    after_23:
    // 0x80047744: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80047748: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x8004774C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80047750: jal         0x800570F8
    // 0x80047754: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_24;
    // 0x80047754: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_24:
    // 0x80047758: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004775C: jal         0x80072594
    // 0x80047760: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_25;
    // 0x80047760: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_25:
    // 0x80047764: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80047768: nop

L_8004776C:
    // 0x8004776C: lwc1        $f14, 0x24($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047770: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047774: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80047778: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x8004777C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80047780: jal         0x800CA030
    // 0x80047784: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_26;
    // 0x80047784: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_26:
    // 0x80047788: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8004778C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80047790: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047794: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80047798: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8004779C: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800477A0: bc1f        L_800479A0
    if (!c1cs) {
        // 0x800477A4: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800479A0;
    }
    // 0x800477A4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800477A8: lwc1        $f12, 0x1C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800477AC: lwc1        $f14, 0x24($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800477B0: swc1        $f18, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f18.u32l;
    // 0x800477B4: jal         0x80070990
    // 0x800477B8: swc1        $f2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f2.u32l;
    arctan2_f(rdram, ctx);
        goto after_27;
    // 0x800477B8: swc1        $f2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f2.u32l;
    after_27:
    // 0x800477BC: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x800477C0: lwc1        $f2, 0xD0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800477C4: addu        $t5, $v0, $a1
    ctx->r13 = ADD32(ctx->r2, ctx->r5);
    // 0x800477C8: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800477CC: sh          $t5, 0x168($s0)
    MEM_H(0X168, ctx->r16) = ctx->r13;
    // 0x800477D0: lh          $t9, 0x168($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X168);
    // 0x800477D4: lh          $a0, 0x196($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X196);
    // 0x800477D8: subu        $t2, $a1, $t9
    ctx->r10 = SUB32(ctx->r5, ctx->r25);
    // 0x800477DC: andi        $t4, $t2, 0xFFFF
    ctx->r12 = ctx->r10 & 0XFFFF;
    // 0x800477E0: andi        $t3, $a0, 0xFFFF
    ctx->r11 = ctx->r4 & 0XFFFF;
    // 0x800477E4: ori         $t1, $zero, 0x8001
    ctx->r9 = 0 | 0X8001;
    // 0x800477E8: subu        $v1, $t4, $t3
    ctx->r3 = SUB32(ctx->r12, ctx->r11);
    // 0x800477EC: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800477F0: bne         $at, $zero, L_80047804
    if (ctx->r1 != 0) {
        // 0x800477F4: cvt.d.s     $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.d = CVT_D_S(ctx->f2.fl);
            goto L_80047804;
    }
    // 0x800477F4: cvt.d.s     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.d = CVT_D_S(ctx->f2.fl);
    // 0x800477F8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800477FC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80047800: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80047804:
    // 0x80047804: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80047808: beq         $at, $zero, L_80047814
    if (ctx->r1 == 0) {
        // 0x8004780C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80047814;
    }
    // 0x8004780C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80047810: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80047814:
    // 0x80047814: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80047818: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004781C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047820: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80047824: sub.d       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f12.d - ctx->f6.d;
    // 0x80047828: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8004782C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80047830: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047834: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80047838: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8004783C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047840: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80047844: bc1f        L_80047854
    if (!c1cs) {
        // 0x80047848: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80047854;
    }
    // 0x80047848: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8004784C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80047850: nop

L_80047854:
    // 0x80047854: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80047858: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004785C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80047860: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80047864: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80047868: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x8004786C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80047870: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047874: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80047878: lw          $t0, 0x128($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X128);
    // 0x8004787C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80047880: lh          $v0, 0x1A0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A0);
    // 0x80047884: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80047888: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x8004788C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80047890: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80047894: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80047898: nop

    // 0x8004789C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800478A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800478A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800478A8: nop

    // 0x800478AC: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800478B0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800478B4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800478B8: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800478BC: mflo        $t7
    ctx->r15 = lo;
    // 0x800478C0: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x800478C4: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x800478C8: sh          $t5, 0x196($s0)
    MEM_H(0X196, ctx->r16) = ctx->r13;
    // 0x800478CC: lh          $t9, 0x196($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X196);
    // 0x800478D0: nop

    // 0x800478D4: subu        $t2, $a1, $t9
    ctx->r10 = SUB32(ctx->r5, ctx->r25);
    // 0x800478D8: subu        $v1, $t2, $t4
    ctx->r3 = SUB32(ctx->r10, ctx->r12);
    // 0x800478DC: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800478E0: bne         $at, $zero, L_800478F0
    if (ctx->r1 != 0) {
        // 0x800478E4: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800478F0;
    }
    // 0x800478E4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800478E8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800478EC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800478F0:
    // 0x800478F0: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800478F4: beq         $at, $zero, L_80047900
    if (ctx->r1 == 0) {
        // 0x800478F8: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80047900;
    }
    // 0x800478F8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800478FC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80047900:
    // 0x80047900: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80047904: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80047908: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004790C: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80047910: nop

    // 0x80047914: bc1f        L_8004792C
    if (!c1cs) {
        // 0x80047918: nop
    
            goto L_8004792C;
    }
    // 0x80047918: nop

    // 0x8004791C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80047920: nop

    // 0x80047924: cvt.d.s     $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.d = CVT_D_S(ctx->f2.fl);
    // 0x80047928: nop

L_8004792C:
    // 0x8004792C: div.d       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = DIV_D(ctx->f12.d, ctx->f0.d);
    // 0x80047930: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80047934: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80047938: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004793C: lw          $a0, -0x2558($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2558);
    // 0x80047940: nop

    // 0x80047944: andi        $t6, $a0, 0x8000
    ctx->r14 = ctx->r4 & 0X8000;
    // 0x80047948: andi        $t7, $a0, 0x10
    ctx->r15 = ctx->r4 & 0X10;
    // 0x8004794C: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x80047950: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80047954: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80047958: nop

    // 0x8004795C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80047960: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80047964: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80047968: nop

    // 0x8004796C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80047970: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80047974: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80047978: bne         $t6, $zero, L_80047988
    if (ctx->r14 != 0) {
        // 0x8004797C: sll         $t8, $v1, 1
        ctx->r24 = S32(ctx->r3 << 1);
            goto L_80047988;
    }
    // 0x8004797C: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x80047980: beq         $t7, $zero, L_8004798C
    if (ctx->r15 == 0) {
        // 0x80047984: nop
    
            goto L_8004798C;
    }
    // 0x80047984: nop

L_80047988:
    // 0x80047988: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8004798C:
    // 0x8004798C: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80047990: mflo        $t5
    ctx->r13 = lo;
    // 0x80047994: sra         $t9, $t5, 7
    ctx->r25 = S32(SIGNED(ctx->r13) >> 7);
    // 0x80047998: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x8004799C: sh          $t2, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r10;
L_800479A0:
    // 0x800479A0: lh          $a0, 0x196($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X196);
    // 0x800479A4: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x800479A8: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x800479AC: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800479B0: subu        $t3, $a1, $t4
    ctx->r11 = SUB32(ctx->r5, ctx->r12);
    // 0x800479B4: ori         $t1, $zero, 0x8001
    ctx->r9 = 0 | 0X8001;
    // 0x800479B8: subu        $v1, $t3, $t6
    ctx->r3 = SUB32(ctx->r11, ctx->r14);
    // 0x800479BC: lw          $t0, 0x128($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X128);
    // 0x800479C0: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800479C4: bne         $at, $zero, L_800479D4
    if (ctx->r1 != 0) {
        // 0x800479C8: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800479D4;
    }
    // 0x800479C8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800479CC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800479D0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800479D4:
    // 0x800479D4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800479D8: beq         $at, $zero, L_800479E4
    if (ctx->r1 == 0) {
        // 0x800479DC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800479E4;
    }
    // 0x800479DC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800479E0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800479E4:
    // 0x800479E4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800479E8: lui         $at, 0x3FFC
    ctx->r1 = S32(0X3FFC << 16);
    // 0x800479EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800479F0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800479F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800479F8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800479FC: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80047A00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047A04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80047A08: lbu         $t2, 0x1F5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1F5);
    // 0x80047A0C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80047A10: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80047A14: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80047A18: nop

    // 0x80047A1C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80047A20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80047A24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80047A28: nop

    // 0x80047A2C: cvt.w.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_D(ctx->f10.d);
    // 0x80047A30: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80047A34: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80047A38: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80047A3C: mflo        $t8
    ctx->r24 = lo;
    // 0x80047A40: sra         $t5, $t8, 6
    ctx->r13 = S32(SIGNED(ctx->r24) >> 6);
    // 0x80047A44: addu        $t9, $a0, $t5
    ctx->r25 = ADD32(ctx->r4, ctx->r13);
    // 0x80047A48: bne         $t2, $zero, L_80047ECC
    if (ctx->r10 != 0) {
        // 0x80047A4C: sh          $t9, 0x196($s0)
        MEM_H(0X196, ctx->r16) = ctx->r25;
            goto L_80047ECC;
    }
    // 0x80047A4C: sh          $t9, 0x196($s0)
    MEM_H(0X196, ctx->r16) = ctx->r25;
    // 0x80047A50: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80047A54: lw          $t4, -0x2524($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2524);
    // 0x80047A58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80047A5C: bne         $t4, $at, L_80047B40
    if (ctx->r12 != ctx->r1) {
        // 0x80047A60: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80047B40;
    }
    // 0x80047A60: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80047A64: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x80047A68: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80047A6C: bne         $t3, $zero, L_80047B40
    if (ctx->r11 != 0) {
        // 0x80047A70: nop
    
            goto L_80047B40;
    }
    // 0x80047A70: nop

    // 0x80047A74: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80047A78: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80047A7C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047A80: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80047A84: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80047A88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047A8C: lwc1        $f9, 0x69A8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69A8);
    // 0x80047A90: lwc1        $f8, 0x69AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69AC);
    // 0x80047A94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047A98: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x80047A9C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80047AA0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80047AA4: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80047AA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80047AAC: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80047AB0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80047AB4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80047AB8: c.lt.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d < ctx->f4.d;
    // 0x80047ABC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80047AC0: bc1f        L_80047ACC
    if (!c1cs) {
        // 0x80047AC4: nop
    
            goto L_80047ACC;
    }
    // 0x80047AC4: nop

    // 0x80047AC8: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
L_80047ACC:
    // 0x80047ACC: lwc1        $f9, 0x69B0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69B0);
    // 0x80047AD0: lwc1        $f8, 0x69B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69B4);
    // 0x80047AD4: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80047AD8: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80047ADC: nop

    // 0x80047AE0: bc1f        L_80047AF8
    if (!c1cs) {
        // 0x80047AE4: nop
    
            goto L_80047AF8;
    }
    // 0x80047AE4: nop

    // 0x80047AE8: lw          $t6, -0x2558($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2558);
    // 0x80047AEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80047AF0: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80047AF4: sw          $t7, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r15;
L_80047AF8:
    // 0x80047AF8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80047AFC: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047B00: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80047B04: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047B08: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80047B0C: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x80047B10: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047B14: nop

    // 0x80047B18: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80047B1C: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047B20: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80047B24: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x80047B28: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047B2C: nop

    // 0x80047B30: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80047B34: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80047B38: b           L_80047C20
    // 0x80047B3C: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
        goto L_80047C20;
    // 0x80047B3C: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
L_80047B40:
    // 0x80047B40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047B44: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80047B48: lwc1        $f7, 0x69B8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X69B8);
    // 0x80047B4C: lwc1        $f6, 0x69BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X69BC);
    // 0x80047B50: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80047B54: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x80047B58: lw          $a0, -0x2558($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2558);
    // 0x80047B5C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80047B60: andi        $t8, $a0, 0x10
    ctx->r24 = ctx->r4 & 0X10;
    // 0x80047B64: beq         $t8, $zero, L_80047C20
    if (ctx->r24 == 0) {
        // 0x80047B68: cvt.s.d     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
            goto L_80047C20;
    }
    // 0x80047B68: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80047B6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80047B70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80047B74: lw          $v0, -0x254C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X254C);
    // 0x80047B78: mul.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80047B7C: slti        $at, $v0, -0x27
    ctx->r1 = SIGNED(ctx->r2) < -0X27 ? 1 : 0;
    // 0x80047B80: bne         $at, $zero, L_80047BB4
    if (ctx->r1 != 0) {
        // 0x80047B84: andi        $t5, $a0, 0x4000
        ctx->r13 = ctx->r4 & 0X4000;
            goto L_80047BB4;
    }
    // 0x80047B84: andi        $t5, $a0, 0x4000
    ctx->r13 = ctx->r4 & 0X4000;
    // 0x80047B88: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80047B8C: beq         $at, $zero, L_80047BB4
    if (ctx->r1 == 0) {
        // 0x80047B90: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80047BB4;
    }
    // 0x80047B90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047B94: lwc1        $f4, 0xF4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80047B98: lwc1        $f9, 0x69C0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69C0);
    // 0x80047B9C: lwc1        $f8, 0x69C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69C4);
    // 0x80047BA0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80047BA4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80047BA8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80047BAC: b           L_80047C08
    // 0x80047BB0: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
        goto L_80047C08;
    // 0x80047BB0: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
L_80047BB4:
    // 0x80047BB4: lui         $at, 0x4004
    ctx->r1 = S32(0X4004 << 16);
    // 0x80047BB8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80047BBC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047BC0: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80047BC4: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80047BC8: lui         $at, 0xC004
    ctx->r1 = S32(0XC004 << 16);
    // 0x80047BCC: bc1t        L_80047BEC
    if (c1cs) {
        // 0x80047BD0: nop
    
            goto L_80047BEC;
    }
    // 0x80047BD0: nop

    // 0x80047BD4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80047BD8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047BDC: nop

    // 0x80047BE0: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x80047BE4: nop

    // 0x80047BE8: bc1f        L_80047C08
    if (!c1cs) {
        // 0x80047BEC: lui         $at, 0x3FF8
        ctx->r1 = S32(0X3FF8 << 16);
            goto L_80047C08;
    }
L_80047BEC:
    // 0x80047BEC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80047BF0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80047BF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047BF8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80047BFC: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80047C00: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80047C04: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
L_80047C08:
    // 0x80047C08: beq         $t5, $zero, L_80047C20
    if (ctx->r13 == 0) {
        // 0x80047C0C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80047C20;
    }
    // 0x80047C0C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80047C10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80047C14: nop

    // 0x80047C18: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80047C1C: nop

L_80047C20:
    // 0x80047C20: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80047C24: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047C28: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80047C2C: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047C30: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80047C34: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80047C38: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80047C3C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80047C40: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80047C44: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80047C48: nop

    // 0x80047C4C: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80047C50: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047C54: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80047C58: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x80047C5C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80047C60: nop

    // 0x80047C64: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80047C68: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80047C6C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x80047C70: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80047C74: nop

    // 0x80047C78: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80047C7C: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x80047C80: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80047C84: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047C88: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80047C8C: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80047C90: swc1        $f10, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f10.u32l;
    // 0x80047C94: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047C98: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80047C9C: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047CA0: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80047CA4: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80047CA8: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x80047CAC: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047CB0: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80047CB4: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047CB8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80047CBC: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80047CC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80047CC4: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    // 0x80047CC8: div.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80047CCC: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80047CD0: nop

    // 0x80047CD4: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80047CD8: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
    // 0x80047CDC: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80047CE0: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047CE4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80047CE8: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80047CEC: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x80047CF0: lwc1        $f4, 0xF0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80047CF4: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047CF8: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047CFC: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80047D00: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80047D04: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x80047D08: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80047D0C: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047D10: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047D14: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80047D18: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80047D1C: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x80047D20: lb          $t9, 0x1E2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E2);
    // 0x80047D24: nop

    // 0x80047D28: beq         $t9, $zero, L_80047DF0
    if (ctx->r25 == 0) {
        // 0x80047D2C: nop
    
            goto L_80047DF0;
    }
    // 0x80047D2C: nop

    // 0x80047D30: lb          $t2, -0x24FC($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X24FC);
    // 0x80047D34: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80047D38: bne         $t2, $zero, L_80047DF0
    if (ctx->r10 != 0) {
        // 0x80047D3C: nop
    
            goto L_80047DF0;
    }
    // 0x80047D3C: nop

    // 0x80047D40: lw          $t4, -0x2540($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2540);
    // 0x80047D44: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80047D48: bne         $t4, $zero, L_80047DF0
    if (ctx->r12 != 0) {
        // 0x80047D4C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80047DF0;
    }
    // 0x80047D4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80047D50: lwc1        $f6, -0x2514($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2514);
    // 0x80047D54: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80047D58: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80047D5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047D60: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80047D64: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80047D68: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80047D6C: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x80047D70: lwc1        $f4, 0xA0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x80047D74: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80047D78: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80047D7C: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80047D80: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80047D84: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80047D88: nop

    // 0x80047D8C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80047D90: nop

    // 0x80047D94: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80047D98: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047D9C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80047DA0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80047DA4: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x80047DA8: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047DAC: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80047DB0: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80047DB4: nop

    // 0x80047DB8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80047DBC: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047DC0: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80047DC4: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80047DC8: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x80047DCC: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047DD0: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80047DD4: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80047DD8: nop

    // 0x80047DDC: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80047DE0: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047DE4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80047DE8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80047DEC: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
L_80047DF0:
    // 0x80047DF0: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80047DF4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80047DF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047DFC: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x80047E00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80047E04: mul.s       $f12, $f14, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80047E08: bc1f        L_80047E14
    if (!c1cs) {
        // 0x80047E0C: nop
    
            goto L_80047E14;
    }
    // 0x80047E0C: nop

    // 0x80047E10: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_80047E14:
    // 0x80047E14: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80047E18: lwc1        $f4, 0xFC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80047E1C: bc1f        L_80047E54
    if (!c1cs) {
        // 0x80047E20: nop
    
            goto L_80047E54;
    }
    // 0x80047E20: nop

    // 0x80047E24: lw          $t3, -0x2558($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2558);
    // 0x80047E28: lwc1        $f8, 0xFC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x80047E2C: andi        $t6, $t3, 0x8000
    ctx->r14 = ctx->r11 & 0X8000;
    // 0x80047E30: bne         $t6, $zero, L_80047E54
    if (ctx->r14 != 0) {
        // 0x80047E34: nop
    
            goto L_80047E54;
    }
    // 0x80047E34: nop

    // 0x80047E38: mul.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80047E3C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80047E40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80047E44: nop

    // 0x80047E48: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80047E4C: b           L_80047E60
    // 0x80047E50: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
        goto L_80047E60;
    // 0x80047E50: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
L_80047E54:
    // 0x80047E54: mul.s       $f16, $f12, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80047E58: nop

    // 0x80047E5C: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
L_80047E60:
    // 0x80047E60: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047E64: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80047E68: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80047E6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80047E70: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80047E74: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80047E78: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047E7C: nop

    // 0x80047E80: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80047E84: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047E88: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80047E8C: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
    // 0x80047E90: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047E94: nop

    // 0x80047E98: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80047E9C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80047EA0: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x80047EA4: lb          $t7, 0x175($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X175);
    // 0x80047EA8: nop

    // 0x80047EAC: beq         $t7, $zero, L_80047ECC
    if (ctx->r15 == 0) {
        // 0x80047EB0: nop
    
            goto L_80047ECC;
    }
    // 0x80047EB0: nop

    // 0x80047EB4: lwc1        $f6, -0x2508($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2508);
    // 0x80047EB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80047EBC: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x80047EC0: lwc1        $f8, -0x2504($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2504);
    // 0x80047EC4: nop

    // 0x80047EC8: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
L_80047ECC:
    // 0x80047ECC: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x80047ED0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80047ED4: lw          $t8, -0x252C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X252C);
    // 0x80047ED8: lh          $v0, 0x1A2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A2);
    // 0x80047EDC: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x80047EE0: subu        $t5, $t8, $v0
    ctx->r13 = SUB32(ctx->r24, ctx->r2);
    // 0x80047EE4: sra         $t9, $t5, 3
    ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80047EE8: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x80047EEC: sh          $t2, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r10;
    // 0x80047EF0: lh          $t3, 0x1A2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X1A2);
    // 0x80047EF4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80047EF8: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80047EFC: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x80047F00: lh          $v1, 0x1A6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A6);
    // 0x80047F04: lw          $t7, -0x2528($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2528);
    // 0x80047F08: lh          $t2, 0x1A4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A4);
    // 0x80047F0C: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x80047F10: sra         $t5, $t8, 3
    ctx->r13 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80047F14: addu        $t9, $v1, $t5
    ctx->r25 = ADD32(ctx->r3, ctx->r13);
    // 0x80047F18: sh          $t9, 0x1A6($s0)
    MEM_H(0X1A6, ctx->r16) = ctx->r25;
    // 0x80047F1C: lh          $t4, 0x1A6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A6);
    // 0x80047F20: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80047F24: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80047F28: sh          $t3, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r11;
    // 0x80047F2C: lb          $a0, 0x1D2($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1D2);
    // 0x80047F30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80047F34: blez        $a0, L_80047F44
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80047F38: subu        $t6, $a0, $t0
        ctx->r14 = SUB32(ctx->r4, ctx->r8);
            goto L_80047F44;
    }
    // 0x80047F38: subu        $t6, $a0, $t0
    ctx->r14 = SUB32(ctx->r4, ctx->r8);
    // 0x80047F3C: b           L_80047F48
    // 0x80047F40: sb          $t6, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r14;
        goto L_80047F48;
    // 0x80047F40: sb          $t6, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r14;
L_80047F44:
    // 0x80047F44: sb          $zero, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = 0;
L_80047F48:
    // 0x80047F48: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80047F4C: lwc1        $f0, 0xC8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80047F50: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80047F54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80047F58: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047F5C: lwc1        $f2, 0xE8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80047F60: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80047F64: lwc1        $f14, 0xE4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80047F68: lw          $t7, 0x148($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X148);
    // 0x80047F6C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80047F70: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80047F74: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80047F78: bne         $t7, $zero, L_800480E0
    if (ctx->r15 != 0) {
        // 0x80047F7C: add.s       $f14, $f14, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
            goto L_800480E0;
    }
    // 0x80047F7C: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80047F80: lb          $t8, 0x1D2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D2);
    // 0x80047F84: lwc1        $f16, 0x1C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80047F88: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80047F8C: beq         $t8, $zero, L_80047FA4
    if (ctx->r24 == 0) {
        // 0x80047F90: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80047FA4;
    }
    // 0x80047F90: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80047F94: lwc1        $f10, 0x11C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x80047F98: lwc1        $f4, 0x120($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
    // 0x80047F9C: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80047FA0: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
L_80047FA4:
    // 0x80047FA4: lb          $t5, -0x24FC($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X24FC);
    // 0x80047FA8: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x80047FAC: beq         $t5, $zero, L_80048068
    if (ctx->r13 == 0) {
        // 0x80047FB0: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_80048068;
    }
    // 0x80047FB0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80047FB4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80047FB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047FBC: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80047FC0: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80047FC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80047FC8: bc1t        L_80047FE8
    if (c1cs) {
        // 0x80047FCC: lui         $at, 0xBFE0
        ctx->r1 = S32(0XBFE0 << 16);
            goto L_80047FE8;
    }
    // 0x80047FCC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80047FD0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80047FD4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80047FD8: nop

    // 0x80047FDC: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x80047FE0: nop

    // 0x80047FE4: bc1f        L_80048004
    if (!c1cs) {
        // 0x80047FE8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80048004;
    }
L_80047FE8:
    // 0x80047FE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80047FEC: lwc1        $f11, 0x69C8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X69C8);
    // 0x80047FF0: lwc1        $f10, 0x69CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X69CC);
    // 0x80047FF4: nop

    // 0x80047FF8: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x80047FFC: b           L_8004800C
    // 0x80048000: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
        goto L_8004800C;
    // 0x80048000: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
L_80048004:
    // 0x80048004: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80048008: nop

L_8004800C:
    // 0x8004800C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80048010: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80048014: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x80048018: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8004801C: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80048020: bc1t        L_80048040
    if (c1cs) {
        // 0x80048024: nop
    
            goto L_80048040;
    }
    // 0x80048024: nop

    // 0x80048028: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004802C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048030: nop

    // 0x80048034: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x80048038: nop

    // 0x8004803C: bc1f        L_8004805C
    if (!c1cs) {
        // 0x80048040: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8004805C;
    }
L_80048040:
    // 0x80048040: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048044: lwc1        $f11, 0x69D0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X69D0);
    // 0x80048048: lwc1        $f10, 0x69D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X69D4);
    // 0x8004804C: nop

    // 0x80048050: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x80048054: b           L_80048084
    // 0x80048058: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
        goto L_80048084;
    // 0x80048058: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
L_8004805C:
    // 0x8004805C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80048060: b           L_80048088
    // 0x80048064: lwc1        $f0, 0x12C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X12C);
        goto L_80048088;
    // 0x80048064: lwc1        $f0, 0x12C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X12C);
L_80048068:
    // 0x80048068: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8004806C: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80048070: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80048074: nop

    // 0x80048078: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8004807C: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80048080: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
L_80048084:
    // 0x80048084: lwc1        $f0, 0x12C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X12C);
L_80048088:
    // 0x80048088: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8004808C: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80048090: swc1        $f14, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f14.u32l;
    // 0x80048094: swc1        $f2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f2.u32l;
    // 0x80048098: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004809C: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800480A0: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800480A4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800480A8: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800480AC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800480B0: add.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x800480B4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800480B8: jal         0x80011570
    // 0x800480BC: nop

    move_object(rdram, ctx);
        goto after_28;
    // 0x800480BC: nop

    after_28:
    // 0x800480C0: beq         $v0, $zero, L_80048100
    if (ctx->r2 == 0) {
        // 0x800480C4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80048100;
    }
    // 0x800480C4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800480C8: lw          $t9, -0x2524($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2524);
    // 0x800480CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800480D0: beq         $t9, $at, L_80048100
    if (ctx->r25 == ctx->r1) {
        // 0x800480D4: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80048100;
    }
    // 0x800480D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800480D8: b           L_80048100
    // 0x800480DC: sb          $t2, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r10;
        goto L_80048100;
    // 0x800480DC: sb          $t2, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r10;
L_800480E0:
    // 0x800480E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800480E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800480E8: lw          $a2, 0x12C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X12C);
    // 0x800480EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800480F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800480F4: swc1        $f8, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f8.u32l;
    // 0x800480F8: jal         0x80050794
    // 0x800480FC: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
    racer_approach_object(rdram, ctx);
        goto after_29;
    // 0x800480FC: swc1        $f6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f6.u32l;
    after_29:
L_80048100:
    // 0x80048100: lwc1        $f10, 0xD0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80048104: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80048108: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004810C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048110: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80048114: mul.d       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80048118: lwc1        $f7, 0x50($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x8004811C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80048120: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x80048124: addiu       $a1, $sp, 0x118
    ctx->r5 = ADD32(ctx->r29, 0X118);
    // 0x80048128: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8004812C: sub.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f0.d - ctx->f10.d;
    // 0x80048130: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80048134: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80048138: swc1        $f8, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f8.u32l;
    // 0x8004813C: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048140: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048144: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x80048148: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8004814C: mul.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80048150: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048154: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80048158: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8004815C: swc1        $f10, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f10.u32l;
    // 0x80048160: lwc1        $f4, 0xD4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x80048164: lwc1        $f8, 0x69DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69DC);
    // 0x80048168: lwc1        $f9, 0x69D8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69D8);
    // 0x8004816C: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x80048170: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x80048174: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048178: bc1f        L_80048198
    if (!c1cs) {
        // 0x8004817C: lui         $at, 0x420C
        ctx->r1 = S32(0X420C << 16);
            goto L_80048198;
    }
    // 0x8004817C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80048180: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048184: nop

    // 0x80048188: swc1        $f6, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f6.u32l;
    // 0x8004818C: lwc1        $f10, 0xD4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD4);
    // 0x80048190: nop

    // 0x80048194: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
L_80048198:
    // 0x80048198: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8004819C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800481A0: bc1f        L_800481B4
    if (!c1cs) {
        // 0x800481A4: nop
    
            goto L_800481B4;
    }
    // 0x800481A4: nop

    // 0x800481A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800481AC: nop

    // 0x800481B0: swc1        $f8, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f8.u32l;
L_800481B4:
    // 0x800481B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800481B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800481BC: lwc1        $f6, 0x69E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X69E0);
    // 0x800481C0: addiu       $a2, $sp, 0xD4
    ctx->r6 = ADD32(ctx->r29, 0XD4);
    // 0x800481C4: swc1        $f6, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f6.u32l;
    // 0x800481C8: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800481CC: jal         0x8002AD48
    // 0x800481D0: swc1        $f14, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f14.u32l;
    get_wave_properties(rdram, ctx);
        goto after_30;
    // 0x800481D0: swc1        $f14, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f14.u32l;
    after_30:
    // 0x800481D4: sll         $a3, $v0, 24
    ctx->r7 = S32(ctx->r2 << 24);
    // 0x800481D8: sll         $t3, $v0, 24
    ctx->r11 = S32(ctx->r2 << 24);
    // 0x800481DC: sra         $t6, $t3, 24
    ctx->r14 = S32(SIGNED(ctx->r11) >> 24);
    // 0x800481E0: sra         $t4, $a3, 24
    ctx->r12 = S32(SIGNED(ctx->r7) >> 24);
    // 0x800481E4: lwc1        $f14, 0x114($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800481E8: beq         $t6, $zero, L_80048280
    if (ctx->r14 == 0) {
        // 0x800481EC: or          $a3, $t4, $zero
        ctx->r7 = ctx->r12 | 0;
            goto L_80048280;
    }
    // 0x800481EC: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x800481F0: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800481F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800481F8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800481FC: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x80048200: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80048204: bc1f        L_80048210
    if (!c1cs) {
        // 0x80048208: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80048210;
    }
    // 0x80048208: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004820C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_80048210:
    // 0x80048210: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048214: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x80048218: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8004821C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80048220: bc1f        L_80048234
    if (!c1cs) {
        // 0x80048224: nop
    
            goto L_80048234;
    }
    // 0x80048224: nop

    // 0x80048228: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004822C: nop

    // 0x80048230: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
L_80048234:
    // 0x80048234: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048238: lwc1        $f9, 0x69E8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69E8);
    // 0x8004823C: lwc1        $f8, 0x69EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69EC);
    // 0x80048240: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80048244: mul.d       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f8.d);
    // 0x80048248: lwc1        $f4, 0x118($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X118);
    // 0x8004824C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80048250: sub.s       $f2, $f10, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80048254: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80048258: nop

    // 0x8004825C: bc1f        L_80048274
    if (!c1cs) {
        // 0x80048260: nop
    
            goto L_80048274;
    }
    // 0x80048260: nop

    // 0x80048264: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80048268: sb          $t7, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r15;
    // 0x8004826C: b           L_80048280
    // 0x80048270: swc1        $f8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f8.u32l;
        goto L_80048280;
    // 0x80048270: swc1        $f8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f8.u32l;
L_80048274:
    // 0x80048274: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80048278: nop

    // 0x8004827C: swc1        $f6, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f6.u32l;
L_80048280:
    // 0x80048280: lb          $v0, 0x1E5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E5);
    // 0x80048284: nop

    // 0x80048288: blez        $v0, L_80048298
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004828C: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80048298;
    }
    // 0x8004828C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80048290: b           L_800482A4
    // 0x80048294: sb          $t8, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r24;
        goto L_800482A4;
    // 0x80048294: sb          $t8, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r24;
L_80048298:
    // 0x80048298: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004829C: nop

    // 0x800482A0: swc1        $f10, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f10.u32l;
L_800482A4:
    // 0x800482A4: lb          $t5, 0x1E5($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E5);
    // 0x800482A8: nop

    // 0x800482AC: blez        $t5, L_800482EC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800482B0: nop
    
            goto L_800482EC;
    }
    // 0x800482B0: nop

    // 0x800482B4: lwc1        $f8, 0x118($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800482B8: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800482BC: add.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800482C0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800482C4: nop

    // 0x800482C8: bc1f        L_800482EC
    if (!c1cs) {
        // 0x800482CC: nop
    
            goto L_800482EC;
    }
    // 0x800482CC: nop

    // 0x800482D0: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x800482D4: nop

    // 0x800482D8: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x800482DC: nop

    // 0x800482E0: ori         $t2, $t9, 0x10
    ctx->r10 = ctx->r25 | 0X10;
    // 0x800482E4: b           L_80048304
    // 0x800482E8: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
        goto L_80048304;
    // 0x800482E8: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
L_800482EC:
    // 0x800482EC: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x800482F0: nop

    // 0x800482F4: lh          $t4, 0x14($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X14);
    // 0x800482F8: nop

    // 0x800482FC: andi        $t3, $t4, 0xFFEF
    ctx->r11 = ctx->r12 & 0XFFEF;
    // 0x80048300: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
L_80048304:
    // 0x80048304: lwc1        $f8, 0x118($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80048308: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8004830C: add.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x80048310: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048314: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80048318: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x8004831C: swc1        $f6, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f6.u32l;
    // 0x80048320: lwc1        $f12, 0xC0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80048324: nop

    // 0x80048328: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x8004832C: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x80048330: nop

    // 0x80048334: bc1f        L_80048394
    if (!c1cs) {
        // 0x80048338: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80048394;
    }
    // 0x80048338: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8004833C: lw          $t6, -0x2558($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2558);
    // 0x80048340: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80048344: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x80048348: beq         $t7, $zero, L_80048364
    if (ctx->r15 == 0) {
        // 0x8004834C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80048364;
    }
    // 0x8004834C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048350: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80048354: lw          $t0, -0x254C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X254C);
    // 0x80048358: nop

    // 0x8004835C: sll         $t8, $t0, 1
    ctx->r24 = S32(ctx->r8 << 1);
    // 0x80048360: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_80048364:
    // 0x80048364: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80048368: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004836C: lw          $t5, 0x128($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X128);
    // 0x80048370: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80048374: addiu       $a2, $sp, 0xD4
    ctx->r6 = ADD32(ctx->r29, 0XD4);
    // 0x80048378: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8004837C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80048380: jal         0x80049520
    // 0x80048384: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    rotate_racer_in_water(rdram, ctx);
        goto after_31;
    // 0x80048384: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_31:
    // 0x80048388: lwc1        $f12, 0xC0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004838C: nop

    // 0x80048390: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_80048394:
    // 0x80048394: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80048398: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004839C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800483A0: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x800483A4: nop

    // 0x800483A8: bc1f        L_800483F8
    if (!c1cs) {
        // 0x800483AC: nop
    
            goto L_800483F8;
    }
    // 0x800483AC: nop

    // 0x800483B0: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800483B4: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800483B8: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800483BC: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x800483C0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800483C4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800483C8: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800483CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800483D0: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    // 0x800483D4: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800483D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800483DC: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800483E0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800483E4: sub.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f6.d - ctx->f0.d;
    // 0x800483E8: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800483EC: add.d       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f0.d + ctx->f8.d;
    // 0x800483F0: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800483F4: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
L_800483F8:
    // 0x800483F8: lw          $t9, -0x2524($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2524);
    // 0x800483FC: lb          $t0, 0x1D2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D2);
    // 0x80048400: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048404: bne         $t9, $at, L_80048440
    if (ctx->r25 != ctx->r1) {
        // 0x80048408: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80048440;
    }
    // 0x80048408: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x8004840C: jal         0x8002359C
    // 0x80048410: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    func_80023568(rdram, ctx);
        goto after_32;
    // 0x80048410: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    after_32:
    // 0x80048414: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x80048418: bne         $v0, $zero, L_8004843C
    if (ctx->r2 != 0) {
        // 0x8004841C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004843C;
    }
    // 0x8004841C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048420: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x80048424: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80048428: jal         0x80055AC4
    // 0x8004842C: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    onscreen_ai_racer_physics(rdram, ctx);
        goto after_33;
    // 0x8004842C: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    after_33:
    // 0x80048430: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x80048434: b           L_80048458
    // 0x80048438: nop

        goto L_80048458;
    // 0x80048438: nop

L_8004843C:
    // 0x8004843C: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
L_80048440:
    // 0x80048440: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048444: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80048448: jal         0x80055010
    // 0x8004844C: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    func_80054FD0(rdram, ctx);
        goto after_34;
    // 0x8004844C: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    after_34:
    // 0x80048450: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x80048454: nop

L_80048458:
    // 0x80048458: bne         $t0, $zero, L_80048474
    if (ctx->r8 != 0) {
        // 0x8004845C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80048474;
    }
    // 0x8004845C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80048460: lb          $t2, 0x1D2($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D2);
    // 0x80048464: nop

    // 0x80048468: beq         $t2, $zero, L_80048474
    if (ctx->r10 == 0) {
        // 0x8004846C: nop
    
            goto L_80048474;
    }
    // 0x8004846C: nop

    // 0x80048470: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80048474:
    // 0x80048474: sb          $t0, 0x1D2($s0)
    MEM_B(0X1D2, ctx->r16) = ctx->r8;
    // 0x80048478: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8004847C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048480: lwc1        $f10, 0xE8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80048484: div.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80048488: lwc1        $f6, 0x110($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X110);
    // 0x8004848C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80048490: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80048494: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80048498: lwc1        $f10, -0x2538($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2538);
    // 0x8004849C: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800484A0: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800484A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800484A8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800484AC: addiu       $v1, $v1, -0x2EF8
    ctx->r3 = ADD32(ctx->r3, -0X2EF8);
    // 0x800484B0: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800484B4: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800484B8: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800484BC: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800484C0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800484C4: lwc1        $f6, -0x2534($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2534);
    // 0x800484C8: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800484CC: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
    // 0x800484D0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800484D4: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800484D8: mul.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800484DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800484E0: swc1        $f12, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f12.u32l;
    // 0x800484E4: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800484E8: nop

    // 0x800484EC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800484F0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800484F4: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x800484F8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800484FC: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80048500: lwc1        $f8, 0x69F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69F4);
    // 0x80048504: lwc1        $f9, 0x69F0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X69F0);
    // 0x80048508: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8004850C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80048510: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80048514: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80048518: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8004851C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80048520: add.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f0.d + ctx->f10.d;
    // 0x80048524: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80048528: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004852C: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80048530: sub.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d - ctx->f8.d;
    // 0x80048534: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80048538: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8004853C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80048540: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x80048544: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80048548: bc1f        L_8004858C
    if (!c1cs) {
        // 0x8004854C: nop
    
            goto L_8004858C;
    }
    // 0x8004854C: nop

    // 0x80048550: lb          $t4, 0x1FB($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1FB);
    // 0x80048554: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80048558: bne         $t4, $zero, L_8004858C
    if (ctx->r12 != 0) {
        // 0x8004855C: nop
    
            goto L_8004858C;
    }
    // 0x8004855C: nop

    // 0x80048560: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048564: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80048568: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004856C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80048570: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80048574: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048578: bc1f        L_8004858C
    if (!c1cs) {
        // 0x8004857C: nop
    
            goto L_8004858C;
    }
    // 0x8004857C: nop

    // 0x80048580: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80048584: nop

    // 0x80048588: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
L_8004858C:
    // 0x8004858C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80048590: nop

    // 0x80048594: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80048598: beq         $at, $zero, L_80048634
    if (ctx->r1 == 0) {
        // 0x8004859C: nop
    
            goto L_80048634;
    }
    // 0x8004859C: nop

    // 0x800485A0: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x800485A4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800485A8: lb          $t7, 0x57($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X57);
    // 0x800485AC: nop

    // 0x800485B0: slti        $at, $t7, 0x9
    ctx->r1 = SIGNED(ctx->r15) < 0X9 ? 1 : 0;
    // 0x800485B4: bne         $at, $zero, L_80048634
    if (ctx->r1 != 0) {
        // 0x800485B8: nop
    
            goto L_80048634;
    }
    // 0x800485B8: nop

    // 0x800485BC: lw          $t8, -0x2558($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2558);
    // 0x800485C0: ori         $at, $zero, 0x8010
    ctx->r1 = 0 | 0X8010;
    // 0x800485C4: andi        $t5, $t8, 0x8010
    ctx->r13 = ctx->r24 & 0X8010;
    // 0x800485C8: bne         $t5, $at, L_80048610
    if (ctx->r13 != ctx->r1) {
        // 0x800485CC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80048610;
    }
    // 0x800485CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800485D0: lw          $v0, -0x254C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X254C);
    // 0x800485D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800485D8: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x800485DC: bne         $at, $zero, L_800485F0
    if (ctx->r1 != 0) {
        // 0x800485E0: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_800485F0;
    }
    // 0x800485E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800485E4: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x800485E8: bne         $at, $zero, L_80048614
    if (ctx->r1 != 0) {
        // 0x800485EC: lw          $a2, 0x128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X128);
            goto L_80048614;
    }
    // 0x800485EC: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
L_800485F0:
    // 0x800485F0: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x800485F4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800485F8: sll         $t9, $a2, 10
    ctx->r25 = S32(ctx->r6 << 10);
    // 0x800485FC: jal         0x800B4BC8
    // 0x80048600: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    increase_emitter_opacity(rdram, ctx);
        goto after_35;
    // 0x80048600: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_35:
    // 0x80048604: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80048608: b           L_80048634
    // 0x8004860C: addiu       $v1, $v1, -0x2EF8
    ctx->r3 = ADD32(ctx->r3, -0X2EF8);
        goto L_80048634;
    // 0x8004860C: addiu       $v1, $v1, -0x2EF8
    ctx->r3 = ADD32(ctx->r3, -0X2EF8);
L_80048610:
    // 0x80048610: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
L_80048614:
    // 0x80048614: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048618: sll         $t2, $a2, 9
    ctx->r10 = S32(ctx->r6 << 9);
    // 0x8004861C: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x80048620: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80048624: jal         0x800B4C1C
    // 0x80048628: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    decrease_emitter_opacity(rdram, ctx);
        goto after_36;
    // 0x80048628: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_36:
    // 0x8004862C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80048630: addiu       $v1, $v1, -0x2EF8
    ctx->r3 = ADD32(ctx->r3, -0X2EF8);
L_80048634:
    // 0x80048634: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80048638: lw          $v0, -0x2524($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2524);
    // 0x8004863C: nop

    // 0x80048640: bltz        $v0, L_800487A0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80048644: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800487A0;
    }
    // 0x80048644: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048648: lwc1        $f4, 0xC0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8004864C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80048650: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048654: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80048658: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x8004865C: nop

    // 0x80048660: bc1f        L_800487A0
    if (!c1cs) {
        // 0x80048664: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800487A0;
    }
    // 0x80048664: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048668: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004866C: nop

    // 0x80048670: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80048674: beq         $at, $zero, L_8004874C
    if (ctx->r1 == 0) {
        // 0x80048678: nop
    
            goto L_8004874C;
    }
    // 0x80048678: nop

    // 0x8004867C: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80048680: lwc1        $f12, 0x20($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048684: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80048688: lwc1        $f14, 0x24($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8004868C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80048690: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80048694: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80048698: nop

    // 0x8004869C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800486A0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800486A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800486A8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800486AC: add.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800486B0: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800486B4: nop

    // 0x800486B8: bc1f        L_80048740
    if (!c1cs) {
        // 0x800486BC: nop
    
            goto L_80048740;
    }
    // 0x800486BC: nop

    // 0x800486C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800486C4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800486C8: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800486CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800486D0: bc1f        L_800486E8
    if (!c1cs) {
        // 0x800486D4: nop
    
            goto L_800486E8;
    }
    // 0x800486D4: nop

    // 0x800486D8: lw          $t3, 0x74($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X74);
    // 0x800486DC: nop

    // 0x800486E0: ori         $t6, $t3, 0xC
    ctx->r14 = ctx->r11 | 0XC;
    // 0x800486E4: sw          $t6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r14;
L_800486E8:
    // 0x800486E8: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x800486EC: nop

    // 0x800486F0: bc1f        L_80048708
    if (!c1cs) {
        // 0x800486F4: nop
    
            goto L_80048708;
    }
    // 0x800486F4: nop

    // 0x800486F8: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x800486FC: nop

    // 0x80048700: ori         $t8, $t7, 0x3
    ctx->r24 = ctx->r15 | 0X3;
    // 0x80048704: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
L_80048708:
    // 0x80048708: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8004870C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80048710: bne         $t5, $at, L_80048740
    if (ctx->r13 != ctx->r1) {
        // 0x80048714: lui         $at, 0x4124
        ctx->r1 = S32(0X4124 << 16);
            goto L_80048740;
    }
    // 0x80048714: lui         $at, 0x4124
    ctx->r1 = S32(0X4124 << 16);
    // 0x80048718: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004871C: nop

    // 0x80048720: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80048724: nop

    // 0x80048728: bc1f        L_80048740
    if (!c1cs) {
        // 0x8004872C: nop
    
            goto L_80048740;
    }
    // 0x8004872C: nop

    // 0x80048730: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x80048734: nop

    // 0x80048738: ori         $t2, $t9, 0x40
    ctx->r10 = ctx->r25 | 0X40;
    // 0x8004873C: sw          $t2, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r10;
L_80048740:
    // 0x80048740: lw          $v0, -0x2524($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2524);
    // 0x80048744: b           L_800487A0
    // 0x80048748: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
        goto L_800487A0;
    // 0x80048748: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8004874C:
    // 0x8004874C: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80048750: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80048754: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80048758: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8004875C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048760: bc1f        L_80048770
    if (!c1cs) {
        // 0x80048764: nop
    
            goto L_80048770;
    }
    // 0x80048764: nop

    // 0x80048768: b           L_80048774
    // 0x8004876C: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
        goto L_80048774;
    // 0x8004876C: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
L_80048770:
    // 0x80048770: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80048774:
    // 0x80048774: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80048778: nop

    // 0x8004877C: bc1f        L_800487A0
    if (!c1cs) {
        // 0x80048780: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800487A0;
    }
    // 0x80048780: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048784: lw          $t4, 0x74($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X74);
    // 0x80048788: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004878C: ori         $t3, $t4, 0xC
    ctx->r11 = ctx->r12 | 0XC;
    // 0x80048790: sw          $t3, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r11;
    // 0x80048794: lw          $v0, -0x2524($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2524);
    // 0x80048798: nop

    // 0x8004879C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_800487A0:
    // 0x800487A0: beq         $v0, $at, L_800488BC
    if (ctx->r2 == ctx->r1) {
        // 0x800487A4: nop
    
            goto L_800488BC;
    }
    // 0x800487A4: nop

    // 0x800487A8: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x800487AC: nop

    // 0x800487B0: bne         $t6, $zero, L_800488BC
    if (ctx->r14 != 0) {
        // 0x800487B4: nop
    
            goto L_800488BC;
    }
    // 0x800487B4: nop

    // 0x800487B8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800487BC: nop

    // 0x800487C0: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800487C4: beq         $at, $zero, L_800488BC
    if (ctx->r1 == 0) {
        // 0x800487C8: nop
    
            goto L_800488BC;
    }
    // 0x800487C8: nop

    // 0x800487CC: jal         0x8001E2D0
    // 0x800487D0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_37;
    // 0x800487D0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_37:
    // 0x800487D4: lb          $t0, 0x203($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X203);
    // 0x800487D8: lb          $t8, 0x2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X2);
    // 0x800487DC: andi        $t9, $t0, 0x4
    ctx->r25 = ctx->r8 & 0X4;
    // 0x800487E0: sra         $t2, $t9, 2
    ctx->r10 = S32(SIGNED(ctx->r25) >> 2);
    // 0x800487E4: addiu       $t0, $t2, 0xA
    ctx->r8 = ADD32(ctx->r10, 0XA);
    // 0x800487E8: slti        $at, $t0, 0xB
    ctx->r1 = SIGNED(ctx->r8) < 0XB ? 1 : 0;
    // 0x800487EC: sll         $t5, $t8, 7
    ctx->r13 = S32(ctx->r24 << 7);
    // 0x800487F0: bne         $at, $zero, L_8004883C
    if (ctx->r1 != 0) {
        // 0x800487F4: addu        $v1, $t5, $v0
        ctx->r3 = ADD32(ctx->r13, ctx->r2);
            goto L_8004883C;
    }
    // 0x800487F4: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x800487F8: lbu         $t4, 0x70($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X70);
    // 0x800487FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80048800: bgtz        $t4, L_80048828
    if (SIGNED(ctx->r12) > 0) {
        // 0x80048804: nop
    
            goto L_80048828;
    }
    // 0x80048804: nop

    // 0x80048808: lwc1        $f6, 0x74($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8004880C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80048810: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048814: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80048818: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8004881C: nop

    // 0x80048820: bc1f        L_800488BC
    if (!c1cs) {
        // 0x80048824: nop
    
            goto L_800488BC;
    }
    // 0x80048824: nop

L_80048828:
    // 0x80048828: lw          $t3, 0x74($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X74);
    // 0x8004882C: sllv        $t7, $t6, $t0
    ctx->r15 = S32(ctx->r14 << (ctx->r8 & 31));
    // 0x80048830: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x80048834: b           L_800488BC
    // 0x80048838: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
        goto L_800488BC;
    // 0x80048838: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
L_8004883C:
    // 0x8004883C: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80048840: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048844: bne         $v0, $at, L_80048888
    if (ctx->r2 != ctx->r1) {
        // 0x80048848: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80048888;
    }
    // 0x80048848: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004884C: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80048850: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80048854: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80048858: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004885C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80048860: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80048864: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80048868: bc1f        L_80048888
    if (!c1cs) {
        // 0x8004886C: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80048888;
    }
    // 0x8004886C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80048870: lw          $t5, 0x74($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X74);
    // 0x80048874: sllv        $t2, $t9, $t0
    ctx->r10 = S32(ctx->r25 << (ctx->r8 & 31));
    // 0x80048878: or          $t4, $t5, $t2
    ctx->r12 = ctx->r13 | ctx->r10;
    // 0x8004887C: b           L_800488BC
    // 0x80048880: sw          $t4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r12;
        goto L_800488BC;
    // 0x80048880: sw          $t4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r12;
    // 0x80048884: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80048888:
    // 0x80048888: beq         $at, $zero, L_800488BC
    if (ctx->r1 == 0) {
        // 0x8004888C: nop
    
            goto L_800488BC;
    }
    // 0x8004888C: nop

    // 0x80048890: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80048894: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80048898: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004889C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800488A0: nop

    // 0x800488A4: bc1f        L_800488BC
    if (!c1cs) {
        // 0x800488A8: nop
    
            goto L_800488BC;
    }
    // 0x800488A8: nop

    // 0x800488AC: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x800488B0: sllv        $t7, $t3, $t0
    ctx->r15 = S32(ctx->r11 << (ctx->r8 & 31));
    // 0x800488B4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800488B8: sw          $t8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r24;
L_800488BC:
    // 0x800488BC: lb          $t9, 0x201($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X201);
    // 0x800488C0: nop

    // 0x800488C4: bne         $t9, $zero, L_800488D8
    if (ctx->r25 != 0) {
        // 0x800488C8: lw          $t5, 0x128($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X128);
            goto L_800488D8;
    }
    // 0x800488C8: lw          $t5, 0x128($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X128);
    // 0x800488CC: b           L_80048924
    // 0x800488D0: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
        goto L_80048924;
    // 0x800488D0: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x800488D4: lw          $t5, 0x128($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X128);
L_800488D8:
    // 0x800488D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800488DC: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800488E0: lwc1        $f10, -0x2514($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2514);
    // 0x800488E4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800488E8: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800488EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800488F0: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800488F4: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800488F8: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x800488FC: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x80048900: jal         0x800AFC74
    // 0x80048904: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    update_vehicle_particles(rdram, ctx);
        goto after_38;
    // 0x80048904: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_38:
    // 0x80048908: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004890C: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80048910: lwc1        $f8, -0x2514($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2514);
    // 0x80048914: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048918: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8004891C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80048920: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
L_80048924:
    // 0x80048924: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x80048928: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004892C: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x80048930: negu        $t4, $t2
    ctx->r12 = SUB32(0, ctx->r10);
    // 0x80048934: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x80048938: lh          $t3, 0x2($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X2);
    // 0x8004893C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80048940: negu        $t6, $t3
    ctx->r14 = SUB32(0, ctx->r11);
    // 0x80048944: sh          $t6, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r14;
    // 0x80048948: lh          $t7, 0x4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4);
    // 0x8004894C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80048950: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80048954: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048958: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004895C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80048960: sh          $t8, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r24;
    // 0x80048964: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80048968: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x8004896C: swc1        $f10, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f10.u32l;
    // 0x80048970: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x80048974: jal         0x800700B4
    // 0x80048978: swc1        $f6, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f6.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_39;
    // 0x80048978: swc1        $f6, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f6.u32l;
    after_39:
    // 0x8004897C: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80048980: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x80048984: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x80048988: addiu       $t9, $s0, 0x30
    ctx->r25 = ADD32(ctx->r16, 0X30);
    // 0x8004898C: addiu       $t5, $s0, 0x34
    ctx->r13 = ADD32(ctx->r16, 0X34);
    // 0x80048990: addiu       $t2, $s0, 0x2C
    ctx->r10 = ADD32(ctx->r16, 0X2C);
    // 0x80048994: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80048998: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8004899C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800489A0: jal         0x8006F88C
    // 0x800489A4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    mtxf_transform_point(rdram, ctx);
        goto after_40;
    // 0x800489A4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_40:
    // 0x800489A8: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x800489AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800489B0: bne         $t4, $zero, L_80048A60
    if (ctx->r12 != 0) {
        // 0x800489B4: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80048A60;
    }
    // 0x800489B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800489B8: lb          $t3, 0x1E5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E5);
    // 0x800489BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800489C0: bne         $t3, $zero, L_80048A60
    if (ctx->r11 != 0) {
        // 0x800489C4: ori         $at, $zero, 0x8001
        ctx->r1 = 0 | 0X8001;
            goto L_80048A60;
    }
    // 0x800489C4: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800489C8: lw          $t0, -0x2548($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2548);
    // 0x800489CC: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x800489D0: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800489D4: sll         $t6, $t0, 6
    ctx->r14 = S32(ctx->r8 << 6);
    // 0x800489D8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800489DC: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x800489E0: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x800489E4: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800489E8: bne         $at, $zero, L_800489F8
    if (ctx->r1 != 0) {
        // 0x800489EC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800489F8;
    }
    // 0x800489EC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800489F0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800489F4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800489F8:
    // 0x800489F8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800489FC: beq         $at, $zero, L_80048A08
    if (ctx->r1 == 0) {
        // 0x80048A00: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80048A08;
    }
    // 0x80048A00: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80048A04: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80048A08:
    // 0x80048A08: sra         $t9, $v1, 2
    ctx->r25 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80048A0C: addu        $t5, $a0, $t9
    ctx->r13 = ADD32(ctx->r4, ctx->r25);
    // 0x80048A10: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
    // 0x80048A14: lh          $a1, 0x1A4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1A4);
    // 0x80048A18: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80048A1C: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x80048A20: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80048A24: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80048A28: lw          $t2, 0x128($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X128);
    // 0x80048A2C: bne         $at, $zero, L_80048A3C
    if (ctx->r1 != 0) {
        // 0x80048A30: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80048A3C;
    }
    // 0x80048A30: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80048A34: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80048A38: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80048A3C:
    // 0x80048A3C: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x80048A40: beq         $at, $zero, L_80048A4C
    if (ctx->r1 == 0) {
        // 0x80048A44: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80048A4C;
    }
    // 0x80048A44: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80048A48: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80048A4C:
    // 0x80048A4C: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80048A50: mflo        $v0
    ctx->r2 = lo;
    // 0x80048A54: sra         $t4, $v0, 4
    ctx->r12 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80048A58: addu        $t3, $a1, $t4
    ctx->r11 = ADD32(ctx->r5, ctx->r12);
    // 0x80048A5C: sh          $t3, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r11;
L_80048A60:
    // 0x80048A60: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80048A64: lw          $t6, -0x2540($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2540);
    // 0x80048A68: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80048A6C: beq         $t6, $zero, L_80048A8C
    if (ctx->r14 == 0) {
        // 0x80048A70: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80048A8C;
    }
    // 0x80048A70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048A74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80048A78: lw          $t7, -0x2554($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2554);
    // 0x80048A7C: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80048A80: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80048A84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80048A88: sw          $t8, -0x2554($at)
    MEM_W(-0X2554, ctx->r1) = ctx->r24;
L_80048A8C:
    // 0x80048A8C: lwc1        $f10, 0xC0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80048A90: nop

    // 0x80048A94: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80048A98: nop

    // 0x80048A9C: bc1f        L_80048AB4
    if (!c1cs) {
        // 0x80048AA0: nop
    
            goto L_80048AB4;
    }
    // 0x80048AA0: nop

    // 0x80048AA4: lb          $t9, 0x1E2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E2);
    // 0x80048AA8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80048AAC: bne         $t9, $at, L_80048AB8
    if (ctx->r25 != ctx->r1) {
        // 0x80048AB0: nop
    
            goto L_80048AB8;
    }
    // 0x80048AB0: nop

L_80048AB4:
    // 0x80048AB4: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
L_80048AB8:
    // 0x80048AB8: lw          $t5, -0x2554($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2554);
    // 0x80048ABC: nop

    // 0x80048AC0: andi        $t2, $t5, 0x10
    ctx->r10 = ctx->r13 & 0X10;
    // 0x80048AC4: beq         $t2, $zero, L_80048BF0
    if (ctx->r10 == 0) {
        // 0x80048AC8: nop
    
            goto L_80048BF0;
    }
    // 0x80048AC8: nop

    // 0x80048ACC: lwc1        $f12, 0xC0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80048AD0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048AD4: nop

    // 0x80048AD8: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80048ADC: nop

    // 0x80048AE0: bc1t        L_80048AFC
    if (c1cs) {
        // 0x80048AE4: nop
    
            goto L_80048AFC;
    }
    // 0x80048AE4: nop

    // 0x80048AE8: lb          $t4, 0x1E2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E2);
    // 0x80048AEC: nop

    // 0x80048AF0: slti        $at, $t4, 0x2
    ctx->r1 = SIGNED(ctx->r12) < 0X2 ? 1 : 0;
    // 0x80048AF4: bne         $at, $zero, L_80048BF0
    if (ctx->r1 != 0) {
        // 0x80048AF8: nop
    
            goto L_80048BF0;
    }
    // 0x80048AF8: nop

L_80048AFC:
    // 0x80048AFC: lb          $t3, 0x1FB($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1FB);
    // 0x80048B00: nop

    // 0x80048B04: bne         $t3, $zero, L_80048BF0
    if (ctx->r11 != 0) {
        // 0x80048B08: nop
    
            goto L_80048BF0;
    }
    // 0x80048B08: nop

    // 0x80048B0C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80048B10: lui         $at, 0x400C
    ctx->r1 = S32(0X400C << 16);
    // 0x80048B14: c.eq.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl == ctx->f12.fl;
    // 0x80048B18: nop

    // 0x80048B1C: bc1t        L_80048B80
    if (c1cs) {
        // 0x80048B20: nop
    
            goto L_80048B80;
    }
    // 0x80048B20: nop

    // 0x80048B24: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048B28: lui         $at, 0x4012
    ctx->r1 = S32(0X4012 << 16);
    // 0x80048B2C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80048B30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048B34: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80048B38: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x80048B3C: lui         $at, 0x4016
    ctx->r1 = S32(0X4016 << 16);
    // 0x80048B40: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80048B44: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80048B48: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x80048B4C: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048B50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048B54: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80048B58: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80048B5C: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x80048B60: bc1f        L_80048BA8
    if (!c1cs) {
        // 0x80048B64: nop
    
            goto L_80048BA8;
    }
    // 0x80048B64: nop

    // 0x80048B68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048B6C: nop

    // 0x80048B70: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x80048B74: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048B78: b           L_80048BA8
    // 0x80048B7C: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
        goto L_80048BA8;
    // 0x80048B7C: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
L_80048B80:
    // 0x80048B80: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048B84: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80048B88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80048B8C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80048B90: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80048B94: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80048B98: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x80048B9C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80048BA0: nop

    // 0x80048BA4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
L_80048BA8:
    // 0x80048BA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80048BAC: lwc1        $f8, -0x2514($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2514);
    // 0x80048BB0: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x80048BB4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80048BB8: nop

    // 0x80048BBC: div.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x80048BC0: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x80048BC4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80048BC8: nop

    // 0x80048BCC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80048BD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80048BD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80048BD8: nop

    // 0x80048BDC: cvt.w.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80048BE0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80048BE4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80048BE8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80048BEC: sb          $t8, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r24;
L_80048BF0:
    // 0x80048BF0: lb          $v0, 0x1FB($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1FB);
    // 0x80048BF4: lw          $t9, 0x128($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X128);
    // 0x80048BF8: blez        $v0, L_80048C0C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80048BFC: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_80048C0C;
    }
    // 0x80048BFC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80048C00: subu        $t5, $v0, $t9
    ctx->r13 = SUB32(ctx->r2, ctx->r25);
    // 0x80048C04: b           L_80048C10
    // 0x80048C08: sb          $t5, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r13;
        goto L_80048C10;
    // 0x80048C08: sb          $t5, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = ctx->r13;
L_80048C0C:
    // 0x80048C0C: sb          $zero, 0x1FB($s0)
    MEM_B(0X1FB, ctx->r16) = 0;
L_80048C10:
    // 0x80048C10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048C14: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80048C18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048C1C: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80048C20: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80048C24: bc1f        L_80048C38
    if (!c1cs) {
        // 0x80048C28: nop
    
            goto L_80048C38;
    }
    // 0x80048C28: nop

    // 0x80048C2C: lwc1        $f4, 0x69F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69F8);
    // 0x80048C30: nop

    // 0x80048C34: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
L_80048C38:
    // 0x80048C38: lw          $v1, 0x60($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X60);
    // 0x80048C3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80048C40: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80048C44: nop

    // 0x80048C48: bne         $t2, $at, L_80048C88
    if (ctx->r10 != ctx->r1) {
        // 0x80048C4C: lw          $a3, 0x12C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X12C);
            goto L_80048C88;
    }
    // 0x80048C4C: lw          $a3, 0x12C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X12C);
    // 0x80048C50: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80048C54: lw          $t4, -0x254C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X254C);
    // 0x80048C58: lb          $t7, 0x3A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3A);
    // 0x80048C5C: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80048C60: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80048C64: sb          $t8, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r24;
    // 0x80048C68: lb          $t9, 0x3A($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3A);
    // 0x80048C6C: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x80048C70: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80048C74: addiu       $t6, $t3, 0x4000
    ctx->r14 = ADD32(ctx->r11, 0X4000);
    // 0x80048C78: andi        $t5, $t9, 0x1
    ctx->r13 = ctx->r25 & 0X1;
    // 0x80048C7C: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80048C80: sb          $t5, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r13;
    // 0x80048C84: lw          $a3, 0x12C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X12C);
L_80048C88:
    // 0x80048C88: jal         0x800580F4
    // 0x80048C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    second_racer_camera_update(rdram, ctx);
        goto after_41;
    // 0x80048C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_41:
    // 0x80048C90: lb          $t2, 0x67($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X67);
    // 0x80048C94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048C98: beq         $t2, $zero, L_80048CAC
    if (ctx->r10 == 0) {
        // 0x80048C9C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80048CAC;
    }
    // 0x80048C9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80048CA0: jal         0x80023104
    // 0x80048CA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800230D0(rdram, ctx);
        goto after_42;
    // 0x80048CA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_42:
    // 0x80048CA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80048CAC:
    // 0x80048CAC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80048CB0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80048CB4: jr          $ra
    // 0x80048CB8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x80048CB8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void timetrial_reset_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059994: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80059998: lb          $t6, -0x24E3($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X24E3);
    // 0x8005999C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800599A0: addiu       $v1, $v1, -0x24E4
    ctx->r3 = ADD32(ctx->r3, -0X24E4);
    // 0x800599A4: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x800599A8: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x800599AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800599B0: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800599B4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800599B8: sh          $zero, -0x24E0($at)
    MEM_H(-0X24E0, ctx->r1) = 0;
    // 0x800599BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800599C0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800599C4: sh          $zero, -0x24D8($at)
    MEM_H(-0X24D8, ctx->r1) = 0;
    // 0x800599C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800599CC: jr          $ra
    // 0x800599D0: sh          $zero, -0x24E2($at)
    MEM_H(-0X24E2, ctx->r1) = 0;
    return;
    // 0x800599D0: sh          $zero, -0x24E2($at)
    MEM_H(-0X24E2, ctx->r1) = 0;
;}
RECOMP_FUNC void render_sprite_billboard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068754: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80068758: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8006875C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80068760: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80068764: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068768: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8006876C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80068770: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80068774: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80068778: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006877C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80068780: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80068784: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80068788: beq         $t8, $zero, L_80068ADC
    if (ctx->r24 == 0) {
        // 0x8006878C: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_80068ADC;
    }
    // 0x8006878C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80068790: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80068794: lw          $v0, 0x12A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X12A0);
    // 0x80068798: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006879C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800687A0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800687A4: lwc1        $f4, 0x12A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X12A8);
    // 0x800687A8: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800687AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800687B0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800687B4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800687B8: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x800687BC: lwc1        $f18, 0x10($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800687C0: lwc1        $f10, 0x12C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X12C0);
    // 0x800687C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800687C8: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800687CC: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800687D0: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800687D4: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800687D8: lwc1        $f6, 0x12D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12D8);
    // 0x800687DC: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x800687E0: jal         0x80070A04
    // 0x800687E4: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800687E4: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    after_0:
    // 0x800687E8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800687EC: jal         0x80070A38
    // 0x800687F0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800687F0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800687F4: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800687F8: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800687FC: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80068800: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80068804: mul.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80068808: nop

    // 0x8006880C: mul.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80068810: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80068814: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80068818: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8006881C: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80068820: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80068824: nop

    // 0x80068828: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8006882C: jal         0x800CA030
    // 0x80068830: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80068830: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_2:
    // 0x80068834: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80068838: jal         0x80070990
    // 0x8006883C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x8006883C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_3:
    // 0x80068840: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80068844: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80068848: jal         0x80070990
    // 0x8006884C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_4;
    // 0x8006884C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_4:
    // 0x80068850: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80068854: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80068858: jal         0x80070A70
    // 0x8006885C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    static_3_80070A70(rdram, ctx);
        goto after_5;
    // 0x8006885C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_5:
    // 0x80068860: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80068864: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x80068868: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x8006886C: sra         $t3, $v1, 8
    ctx->r11 = S32(SIGNED(ctx->r3) >> 8);
    // 0x80068870: bc1f        L_80068890
    if (!c1cs) {
        // 0x80068874: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_80068890;
    }
    // 0x80068874: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80068878: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8006887C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80068880: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80068884: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x80068888: subu        $a0, $t4, $t3
    ctx->r4 = SUB32(ctx->r12, ctx->r11);
    // 0x8006888C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_80068890:
    // 0x80068890: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80068894: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80068898: jal         0x80070990
    // 0x8006889C: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    arctan2_f(rdram, ctx);
        goto after_6;
    // 0x8006889C: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_6:
    // 0x800688A0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800688A4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800688A8: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800688AC: bne         $at, $zero, L_800688BC
    if (ctx->r1 != 0) {
        // 0x800688B0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800688BC;
    }
    // 0x800688B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800688B4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800688B8: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
L_800688BC:
    // 0x800688BC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800688C0: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800688C4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800688C8: sra         $t8, $v0, 7
    ctx->r24 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800688CC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800688D0: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800688D4: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x800688D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800688DC: mflo        $v1
    ctx->r3 = lo;
    // 0x800688E0: sra         $t7, $v1, 8
    ctx->r15 = S32(SIGNED(ctx->r3) >> 8);
    // 0x800688E4: bne         $at, $zero, L_800688FC
    if (ctx->r1 != 0) {
        // 0x800688E8: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_800688FC;
    }
    // 0x800688E8: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800688EC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800688F0: subu        $s2, $t2, $t9
    ctx->r18 = SUB32(ctx->r10, ctx->r25);
    // 0x800688F4: addu        $v1, $t7, $at
    ctx->r3 = ADD32(ctx->r15, ctx->r1);
    // 0x800688F8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800688FC:
    // 0x800688FC: lw          $v0, 0x12A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X12A0);
    // 0x80068900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068904: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80068908: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8006890C: lwc1        $f6, 0x12A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12A8);
    // 0x80068910: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068914: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80068918: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006891C: lwc1        $f10, 0x12C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X12C0);
    // 0x80068920: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80068924: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80068928: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006892C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80068930: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80068934: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x80068938: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006893C: lwc1        $f6, 0x12D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12D8);
    // 0x80068940: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80068944: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80068948: sll         $t3, $s2, 1
    ctx->r11 = S32(ctx->r18 << 1);
    // 0x8006894C: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x80068950: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80068954: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80068958: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8006895C: jal         0x800CA030
    // 0x80068960: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x80068960: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_7:
    // 0x80068964: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80068968: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8006896C: jal         0x80070990
    // 0x80068970: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_8;
    // 0x80068970: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_8:
    // 0x80068974: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068978: addiu       $a1, $a1, 0x1270
    ctx->r5 = ADD32(ctx->r5, 0X1270);
    // 0x8006897C: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80068980: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80068984: jal         0x80070990
    // 0x80068988: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    arctan2_f(rdram, ctx);
        goto after_9;
    // 0x80068988: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    after_9:
    // 0x8006898C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068990: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80068994: addiu       $a1, $a1, 0x1270
    ctx->r5 = ADD32(ctx->r5, 0X1270);
    // 0x80068998: negu        $t5, $v0
    ctx->r13 = SUB32(0, ctx->r2);
    // 0x8006899C: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x800689A0: sh          $t6, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r14;
    // 0x800689A4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800689A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800689AC: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x800689B0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800689B4: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x800689B8: swc1        $f6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f6.u32l;
    // 0x800689BC: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800689C0: nop

    // 0x800689C4: swc1        $f8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f8.u32l;
    // 0x800689C8: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800689CC: jal         0x8006FE70
    // 0x800689D0: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_10;
    // 0x800689D0: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    after_10:
    // 0x800689D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800689D8: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x800689DC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800689E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800689E4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800689E8: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800689EC: addiu       $t3, $t3, 0x12F0
    ctx->r11 = ADD32(ctx->r11, 0X12F0);
    // 0x800689F0: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x800689F4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800689F8: addiu       $s0, $s0, 0x15E0
    ctx->r16 = ADD32(ctx->r16, 0X15E0);
    // 0x800689FC: lw          $a1, -0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X4);
    // 0x80068A00: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80068A04: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80068A08: jal         0x8006F9A8
    // 0x80068A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtxf_mul(rdram, ctx);
        goto after_11;
    // 0x80068A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80068A10: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068A14: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068A18: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80068A1C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068A20: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80068A24: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80068A28: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068A2C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068A30: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    // 0x80068A34: jal         0x8006F9A8
    // 0x80068A38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mtxf_mul(rdram, ctx);
        goto after_12;
    // 0x80068A38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x80068A3C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80068A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068A44: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80068A48: jal         0x8006FAB0
    // 0x80068A4C: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_13;
    // 0x80068A4C: nop

    after_13:
    // 0x80068A50: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068A54: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068A58: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x80068A5C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80068A60: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80068A64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068A68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80068A6C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80068A70: sw          $t7, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r15;
    // 0x80068A74: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068A78: lui         $t3, 0x180
    ctx->r11 = S32(0X180 << 16);
    // 0x80068A7C: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80068A80: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80068A84: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x80068A88: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80068A8C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80068A90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068A94: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80068A98: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80068A9C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80068AA0: lui         $a1, 0xE
    ctx->r5 = S32(0XE << 16);
    // 0x80068AA4: addiu       $t8, $t6, 0x40
    ctx->r24 = ADD32(ctx->r14, 0X40);
    // 0x80068AA8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80068AAC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068AB0: addiu       $t9, $a1, -0x2958
    ctx->r25 = ADD32(ctx->r5, -0X2958);
    // 0x80068AB4: andi        $t2, $t9, 0x6
    ctx->r10 = ctx->r25 & 0X6;
    // 0x80068AB8: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80068ABC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80068AC0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80068AC4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80068AC8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80068ACC: ori         $t5, $t4, 0x1A
    ctx->r13 = ctx->r12 | 0X1A;
    // 0x80068AD0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80068AD4: b           L_80068D00
    // 0x80068AD8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80068D00;
    // 0x80068AD8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80068ADC:
    // 0x80068ADC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80068AE0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80068AE4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80068AE8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068AEC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068AF0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068AF4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80068AF8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80068AFC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80068B00: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80068B04: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80068B08: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80068B0C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80068B10: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80068B14: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068B18: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068B1C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80068B20: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068B24: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80068B28: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068B2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80068B30: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80068B34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068B38: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80068B3C: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x80068B40: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80068B44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80068B48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80068B4C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80068B50: sb          $a1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r5;
    // 0x80068B54: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80068B58: sb          $a1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r5;
    // 0x80068B5C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80068B60: sb          $a1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r5;
    // 0x80068B64: sb          $a1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r5;
    // 0x80068B68: sh          $t3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r11;
    // 0x80068B6C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068B70: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80068B74: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80068B78: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068B7C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80068B80: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80068B84: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x80068B88: andi        $t7, $t8, 0x6
    ctx->r15 = ctx->r24 & 0X6;
    // 0x80068B8C: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80068B90: or          $t2, $t9, $at
    ctx->r10 = ctx->r25 | ctx->r1;
    // 0x80068B94: ori         $t3, $t2, 0x1A
    ctx->r11 = ctx->r10 | 0X1A;
    // 0x80068B98: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80068B9C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80068BA0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80068BA4: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x80068BA8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80068BAC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80068BB0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80068BB4: addiu       $t8, $t6, 0xA
    ctx->r24 = ADD32(ctx->r14, 0XA);
    // 0x80068BB8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80068BBC: lb          $t7, 0x1294($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X1294);
    // 0x80068BC0: nop

    // 0x80068BC4: bne         $t7, $zero, L_80068BFC
    if (ctx->r15 != 0) {
        // 0x80068BC8: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80068BFC;
    }
    // 0x80068BC8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80068BCC: lw          $t9, 0x1264($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1264);
    // 0x80068BD0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80068BD4: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x80068BD8: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80068BDC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80068BE0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80068BE4: lh          $t3, 0x1044($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1044);
    // 0x80068BE8: lh          $t4, 0x4($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4);
    // 0x80068BEC: nop

    // 0x80068BF0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80068BF4: b           L_80068C2C
    // 0x80068BF8: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
        goto L_80068C2C;
    // 0x80068BF8: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_80068BFC:
    // 0x80068BFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80068C00: lw          $t6, 0x1264($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1264);
    // 0x80068C04: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80068C08: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x80068C0C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80068C10: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80068C14: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80068C18: lh          $t7, 0x1154($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1154);
    // 0x80068C1C: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x80068C20: nop

    // 0x80068C24: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x80068C28: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80068C2C:
    // 0x80068C2C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80068C30: lh          $s2, 0x18($s0)
    ctx->r18 = MEM_H(ctx->r16, 0X18);
    // 0x80068C34: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80068C38: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80068C3C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80068C40: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80068C44: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068C48: lw          $a3, 0x6714($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6714);
    // 0x80068C4C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80068C50: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80068C54: jal         0x80070370
    // 0x80068C58: nop

    mtxf_billboard(rdram, ctx);
        goto after_14;
    // 0x80068C58: nop

    after_14:
    // 0x80068C5C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068C60: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068C64: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80068C68: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80068C6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068C70: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80068C74: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80068C78: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80068C7C: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80068C80: jal         0x8006FAB0
    // 0x80068C84: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_15;
    // 0x80068C84: nop

    after_15:
    // 0x80068C88: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068C8C: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068C90: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80068C94: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80068C98: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80068C9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068CA0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80068CA4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80068CA8: sw          $t2, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r10;
    // 0x80068CAC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068CB0: lui         $t6, 0x180
    ctx->r14 = S32(0X180 << 16);
    // 0x80068CB4: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80068CB8: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80068CBC: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x80068CC0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80068CC4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80068CC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068CCC: addu        $t7, $t8, $at
    ctx->r15 = ADD32(ctx->r24, ctx->r1);
    // 0x80068CD0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80068CD4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80068CD8: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x80068CDC: addiu       $t3, $t9, 0x40
    ctx->r11 = ADD32(ctx->r25, 0X40);
    // 0x80068CE0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80068CE4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068CE8: ori         $t4, $t4, 0x2
    ctx->r12 = ctx->r12 | 0X2;
    // 0x80068CEC: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80068CF0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80068CF4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80068CF8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80068CFC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80068D00:
    // 0x80068D00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80068D04: lw          $t6, 0x128C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X128C);
    // 0x80068D08: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80068D0C: bne         $t6, $zero, L_80068D34
    if (ctx->r14 != 0) {
        // 0x80068D10: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80068D34;
    }
    // 0x80068D10: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80068D14: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80068D18: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x80068D1C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80068D20: nop

    // 0x80068D24: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068D28: mflo        $s2
    ctx->r18 = lo;
    // 0x80068D2C: sra         $t9, $s2, 8
    ctx->r25 = S32(SIGNED(ctx->r18) >> 8);
    // 0x80068D30: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_80068D34:
    // 0x80068D34: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x80068D38: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80068D3C: andi        $t2, $t3, 0x4
    ctx->r10 = ctx->r11 & 0X4;
    // 0x80068D40: beq         $t2, $zero, L_80068D4C
    if (ctx->r10 == 0) {
        // 0x80068D44: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80068D4C;
    }
    // 0x80068D44: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80068D48: ori         $v0, $t3, 0x1
    ctx->r2 = ctx->r11 | 0X1;
L_80068D4C:
    // 0x80068D4C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80068D50: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x80068D54: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80068D58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80068D5C: jal         0x8007C384
    // 0x80068D60: or          $a1, $t5, $t6
    ctx->r5 = ctx->r13 | ctx->r14;
    material_load_simple(rdram, ctx);
        goto after_16;
    // 0x80068D60: or          $a1, $t5, $t6
    ctx->r5 = ctx->r13 | ctx->r14;
    after_16:
    // 0x80068D64: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80068D68: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80068D6C: andi        $t7, $t8, 0x100
    ctx->r15 = ctx->r24 & 0X100;
    // 0x80068D70: bne         $t7, $zero, L_80068D94
    if (ctx->r15 != 0) {
        // 0x80068D74: addiu       $t0, $t0, 0x129C
        ctx->r8 = ADD32(ctx->r8, 0X129C);
            goto L_80068D94;
    }
    // 0x80068D74: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x80068D78: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068D7C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80068D80: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80068D84: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80068D88: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80068D8C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80068D90: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80068D94:
    // 0x80068D94: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068D98: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80068D9C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80068DA0: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068DA4: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x80068DA8: addu        $t8, $s0, $t6
    ctx->r24 = ADD32(ctx->r16, ctx->r14);
    // 0x80068DAC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80068DB0: lw          $t7, 0xC($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XC);
    // 0x80068DB4: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x80068DB8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80068DBC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80068DC0: ori         $t5, $t5, 0xA
    ctx->r13 = ctx->r13 | 0XA;
    // 0x80068DC4: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80068DC8: bne         $t3, $zero, L_80068DD8
    if (ctx->r11 != 0) {
        // 0x80068DCC: sw          $t3, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r11;
            goto L_80068DD8;
    }
    // 0x80068DCC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80068DD0: b           L_80068DDC
    // 0x80068DD4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80068DDC;
    // 0x80068DD4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80068DD8:
    // 0x80068DD8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80068DDC:
    // 0x80068DDC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068DE0: sll         $t6, $s2, 6
    ctx->r14 = S32(ctx->r18 << 6);
    // 0x80068DE4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80068DE8: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80068DEC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80068DF0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80068DF4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80068DF8: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x80068DFC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80068E00: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80068E04: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x80068E08: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80068E0C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80068E10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80068E14: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80068E18: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80068E1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80068E20: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80068E24: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80068E28: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80068E2C: jr          $ra
    // 0x80068E30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80068E30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void dialogue_race_defeat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DF38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009DF3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DF40: addiu       $t6, $zero, 0x87
    ctx->r14 = ADD32(0, 0X87);
    // 0x8009DF44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009DF48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DF4C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009DF50: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009DF54: jal         0x800C543C
    // 0x8009DF58: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_0;
    // 0x8009DF58: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_0:
    // 0x8009DF5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DF60: jal         0x800C54DC
    // 0x8009DF64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_1;
    // 0x8009DF64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8009DF68: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8009DF6C: jal         0x8006A794
    // 0x8009DF70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_2;
    // 0x8009DF70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8009DF74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DF78: sb          $zero, 0x6AA4($at)
    MEM_B(0X6AA4, ctx->r1) = 0;
    // 0x8009DF7C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009DF80: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x8009DF84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009DF88: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009DF8C: sb          $zero, -0x5A4($at)
    MEM_B(-0X5A4, ctx->r1) = 0;
    // 0x8009DF90: lw          $a3, 0xC4($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XC4);
    // 0x8009DF94: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009DF98: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8009DF9C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009DFA0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009DFA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DFA8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DFAC: jal         0x800C56C8
    // 0x8009DFB0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_3;
    // 0x8009DFB0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
    // 0x8009DFB4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009DFB8: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x8009DFBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009DFC0: lw          $a3, 0xC8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC8);
    // 0x8009DFC4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009DFC8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009DFCC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009DFD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009DFD4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009DFD8: jal         0x800C56C8
    // 0x8009DFDC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    render_dialogue_text(rdram, ctx);
        goto after_4;
    // 0x8009DFDC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_4:
    // 0x8009DFE0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009DFE4: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009DFE8: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x8009DFEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DFF0: sb          $t3, 0x6AAE($at)
    MEM_B(0X6AAE, ctx->r1) = ctx->r11;
    // 0x8009DFF4: lw          $a0, 0x5C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X5C);
    // 0x8009DFF8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009DFFC: jal         0x8009D6FC
    // 0x8009E000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_5;
    // 0x8009E000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8009E004: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009E008: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009E00C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E010: lw          $a0, 0xCC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XCC);
    // 0x8009E014: jal         0x8009D6FC
    // 0x8009E018: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_6;
    // 0x8009E018: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8009E01C: jal         0x8009D7B0
    // 0x8009E020: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_7;
    // 0x8009E020: nop

    after_7:
    // 0x8009E024: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8009E028: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009E02C: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8009E030: beq         $t7, $zero, L_8009E074
    if (ctx->r15 == 0) {
        // 0x8009E034: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009E074;
    }
    // 0x8009E034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E038: jal         0x80001D04
    // 0x8009E03C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8009E03C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8009E040: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009E044: lb          $v0, 0x6AB6($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6AB6);
    // 0x8009E048: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009E04C: beq         $v0, $zero, L_8009E064
    if (ctx->r2 == 0) {
        // 0x8009E050: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8009E064;
    }
    // 0x8009E050: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009E054: beq         $v0, $at, L_8009E06C
    if (ctx->r2 == ctx->r1) {
        // 0x8009E058: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8009E06C;
    }
    // 0x8009E058: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8009E05C: b           L_8009E074
    // 0x8009E060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009E074;
    // 0x8009E060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009E064:
    // 0x8009E064: b           L_8009E070
    // 0x8009E068: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_8009E070;
    // 0x8009E068: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8009E06C:
    // 0x8009E06C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_8009E070:
    // 0x8009E070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009E074:
    // 0x8009E074: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8009E078: jr          $ra
    // 0x8009E07C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009E07C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void get_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F04C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009F050: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009F054: lw          $v1, 0x69EC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X69EC);
    // 0x8009F058: lw          $v0, 0x69E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X69E8);
    // 0x8009F05C: jr          $ra
    // 0x8009F060: nop

    return;
    // 0x8009F060: nop

;}
RECOMP_FUNC void _allocatePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9980: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9988: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C998C: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x800C9990: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800C9994: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C9998: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C999C: beq         $a3, $zero, L_800C99D4
    if (ctx->r7 == 0) {
        // 0x800C99A0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C99D4;
    }
    // 0x800C99A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C99A4: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C99A8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C99AC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C99B0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C99B4: jal         0x800C8CC0
    // 0x800C99B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800C99B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800C99BC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C99C0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800C99C4: jal         0x800C8CF0
    // 0x800C99C8: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_1;
    // 0x800C99C8: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_1:
    // 0x800C99CC: b           L_800C9A54
    // 0x800C99D0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800C9A54;
    // 0x800C99D0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800C99D4:
    // 0x800C99D4: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x800C99D8: beq         $a3, $zero, L_800C9A0C
    if (ctx->r7 == 0) {
        // 0x800C99DC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800C9A0C;
    }
    // 0x800C99DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800C99E0: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C99E4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C99E8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C99EC: jal         0x800C8CC0
    // 0x800C99F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800C99F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800C99F4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C99F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800C99FC: jal         0x800C8CF0
    // 0x800C9A00: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800C9A00: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800C9A04: b           L_800C9A54
    // 0x800C9A08: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800C9A54;
    // 0x800C9A08: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800C9A0C:
    // 0x800C9A0C: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x800C9A10: beql        $a3, $zero, L_800C9A58
    if (ctx->r7 == 0) {
        // 0x800C9A14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9A58;
    }
    goto skip_0;
    // 0x800C9A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9A18: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
L_800C9A1C:
    // 0x800C9A1C: lh          $t9, 0x16($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X16);
    // 0x800C9A20: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C9A24: bnel        $at, $zero, L_800C9A4C
    if (ctx->r1 != 0) {
        // 0x800C9A28: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800C9A4C;
    }
    goto skip_1;
    // 0x800C9A28: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x800C9A2C: lw          $t1, 0xD8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XD8);
    // 0x800C9A30: bnel        $t1, $zero, L_800C9A4C
    if (ctx->r9 != 0) {
        // 0x800C9A34: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800C9A4C;
    }
    goto skip_2;
    // 0x800C9A34: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x800C9A38: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800C9A3C: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800C9A40: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C9A44: lh          $a2, 0x16($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X16);
    // 0x800C9A48: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
L_800C9A4C:
    // 0x800C9A4C: bnel        $a3, $zero, L_800C9A1C
    if (ctx->r7 != 0) {
        // 0x800C9A50: lw          $t8, 0x8($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X8);
            goto L_800C9A1C;
    }
    goto skip_3;
    // 0x800C9A50: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    skip_3:
L_800C9A54:
    // 0x800C9A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9A58:
    // 0x800C9A58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9A5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C9A60: jr          $ra
    // 0x800C9A64: nop

    return;
    // 0x800C9A64: nop

;}
RECOMP_FUNC void atan2s(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800708AC: or          $t0, $a0, $a1
    ctx->r8 = ctx->r4 | ctx->r5;
    // 0x800708B0: bne         $zero, $t0, L_800708C0
    if (0 != ctx->r8) {
        // 0x800708B4: nop
    
            goto L_800708C0;
    }
    // 0x800708B4: nop

    // 0x800708B8: jr          $ra
    // 0x800708BC: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x800708BC: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_800708C0:
    // 0x800708C0: bltz        $a0, L_800708D8
    if (SIGNED(ctx->r4) < 0) {
        // 0x800708C4: nop
    
            goto L_800708D8;
    }
    // 0x800708C4: nop

    // 0x800708C8: bltzl       $a1, L_800708F8
    if (SIGNED(ctx->r5) < 0) {
        // 0x800708CC: negu        $a1, $a1
        ctx->r5 = SUB32(0, ctx->r5);
            goto L_800708F8;
    }
    goto skip_0;
    // 0x800708CC: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    skip_0:
    // 0x800708D0: j           L_80070908
    // 0x800708D4: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
        goto L_80070908;
    // 0x800708D4: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_800708D8:
    // 0x800708D8: bltz        $a1, L_800708E8
    if (SIGNED(ctx->r5) < 0) {
        // 0x800708DC: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_800708E8;
    }
    // 0x800708DC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800708E0: j           L_800708FC
    // 0x800708E4: ori         $v0, $zero, 0xC000
    ctx->r2 = 0 | 0XC000;
        goto L_800708FC;
    // 0x800708E4: ori         $v0, $zero, 0xC000
    ctx->r2 = 0 | 0XC000;
L_800708E8:
    // 0x800708E8: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800708EC: j           L_80070908
    // 0x800708F0: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
        goto L_80070908;
    // 0x800708F0: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x800708F4: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_800708F8:
    // 0x800708F8: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
L_800708FC:
    // 0x800708FC: xor         $a0, $a0, $a1
    ctx->r4 = ctx->r4 ^ ctx->r5;
    // 0x80070900: xor         $a1, $a0, $a1
    ctx->r5 = ctx->r4 ^ ctx->r5;
    // 0x80070904: xor         $a0, $a0, $a1
    ctx->r4 = ctx->r4 ^ ctx->r5;
L_80070908:
    // 0x80070908: subu        $t0, $a0, $a1
    ctx->r8 = SUB32(ctx->r4, ctx->r5);
    // 0x8007090C: bltzl       $t0, L_80070958
    if (SIGNED(ctx->r8) < 0) {
        // 0x80070910: dsll        $t0, $a0, 11
        ctx->r8 = ctx->r4 << 11;
            goto L_80070958;
    }
    goto skip_1;
    // 0x80070910: dsll        $t0, $a0, 11
    ctx->r8 = ctx->r4 << 11;
    skip_1:
    // 0x80070914: dsll        $t0, $a1, 11
    ctx->r8 = ctx->r5 << 11;
    // 0x80070918: ddivu       $zero, $t0, $a0
    DDIVU(U64(ctx->r8), U64(ctx->r4), &lo, &hi);
    // 0x8007091C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80070920: addiu       $t1, $t1, -0x1E52
    ctx->r9 = ADD32(ctx->r9, -0X1E52);
    // 0x80070924: addiu       $v0, $v0, 0x4000
    ctx->r2 = ADD32(ctx->r2, 0X4000);
    // 0x80070928: bne         $a0, $zero, L_80070934
    if (ctx->r4 != 0) {
        // 0x8007092C: nop
    
            goto L_80070934;
    }
    // 0x8007092C: nop

    // 0x80070930: break       7
    do_break(2147944752);
L_80070934:
    // 0x80070934: mflo        $t0
    ctx->r8 = lo;
    // 0x80070938: mflo        $t0
    ctx->r8 = lo;
    // 0x8007093C: andi        $t0, $t0, 0xFFE
    ctx->r8 = ctx->r8 & 0XFFE;
    // 0x80070940: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80070944: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
    // 0x80070948: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x8007094C: jr          $ra
    // 0x80070950: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x80070950: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80070954: dsll        $t0, $a0, 11
    ctx->r8 = ctx->r4 << 11;
L_80070958:
    // 0x80070958: ddivu       $zero, $t0, $a1
    DDIVU(U64(ctx->r8), U64(ctx->r5), &lo, &hi);
    // 0x8007095C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80070960: addiu       $t1, $t1, -0x1E52
    ctx->r9 = ADD32(ctx->r9, -0X1E52);
    // 0x80070964: bne         $a1, $zero, L_80070970
    if (ctx->r5 != 0) {
        // 0x80070968: nop
    
            goto L_80070970;
    }
    // 0x80070968: nop

    // 0x8007096C: break       7
    do_break(2147944812);
L_80070970:
    // 0x80070970: mflo        $t0
    ctx->r8 = lo;
    // 0x80070974: mflo        $t0
    ctx->r8 = lo;
    // 0x80070978: andi        $t0, $t0, 0xFFE
    ctx->r8 = ctx->r8 & 0XFFE;
    // 0x8007097C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80070980: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
    // 0x80070984: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80070988: jr          $ra
    // 0x8007098C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    return;
    // 0x8007098C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
;}
RECOMP_FUNC void obj_loop_rampswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CEE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003CEE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003CEE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003CEEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003CEF0: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CEF4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003CEF8: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x8003CEFC: nop

    // 0x8003CF00: slti        $at, $t6, 0x2D
    ctx->r1 = SIGNED(ctx->r14) < 0X2D ? 1 : 0;
    // 0x8003CF04: beq         $at, $zero, L_8003CF2C
    if (ctx->r1 == 0) {
        // 0x8003CF08: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_8003CF2C;
    }
    // 0x8003CF08: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8003CF0C: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x8003CF10: jal         0x8001E378
    // 0x8003CF14: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    start_bridge_timer(rdram, ctx);
        goto after_0;
    // 0x8003CF14: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003CF18: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8003CF1C: nop

    // 0x8003CF20: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8003CF24: nop

    // 0x8003CF28: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
L_8003CF2C:
    // 0x8003CF2C: sb          $t7, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r15;
    // 0x8003CF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003CF34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003CF38: jr          $ra
    // 0x8003CF3C: nop

    return;
    // 0x8003CF3C: nop

;}
RECOMP_FUNC void find_non_car_racers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E1D0: lb          $v0, -0x4C7E($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4C7E);
    // 0x8000E1D4: jr          $ra
    // 0x8000E1D8: nop

    return;
    // 0x8000E1D8: nop

;}
RECOMP_FUNC void menu_dialogue_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094AB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094ABC: jal         0x800724E4
    // 0x80094AC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_init(rdram, ctx);
        goto after_0;
    // 0x80094AC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80094AC4: jal         0x800C5B80
    // 0x80094AC8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_close(rdram, ctx);
        goto after_1;
    // 0x80094AC8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    // 0x80094ACC: jal         0x800C59F4
    // 0x80094AD0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_2;
    // 0x80094AD0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x80094AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094AD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094ADC: sw          $zero, 0xF04($at)
    MEM_W(0XF04, ctx->r1) = 0;
    // 0x80094AE0: jr          $ra
    // 0x80094AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80094AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_filtered_cheats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C850: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009C854: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009C858: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C85C: lw          $t6, -0x5C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C8);
    // 0x8009C860: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009C864: lw          $s0, 0x318($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X318);
    // 0x8009C868: beq         $t6, $zero, L_8009C87C
    if (ctx->r14 == 0) {
        // 0x8009C86C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8009C87C;
    }
    // 0x8009C86C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009C870: jal         0x8000E4C8
    // 0x8009C874: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_0;
    // 0x8009C874: nop

    after_0:
    // 0x8009C878: beq         $v0, $zero, L_8009C88C
    if (ctx->r2 == 0) {
        // 0x8009C87C: lui         $at, 0x1B40
        ctx->r1 = S32(0X1B40 << 16);
            goto L_8009C88C;
    }
L_8009C87C:
    // 0x8009C87C: lui         $at, 0x1B40
    ctx->r1 = S32(0X1B40 << 16);
    // 0x8009C880: ori         $at, $at, 0x133
    ctx->r1 = ctx->r1 | 0X133;
    // 0x8009C884: and         $t7, $s0, $at
    ctx->r15 = ctx->r16 & ctx->r1;
    // 0x8009C888: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_8009C88C:
    // 0x8009C88C: jal         0x8006B480
    // 0x8009C890: nop

    level_is_race(rdram, ctx);
        goto after_1;
    // 0x8009C890: nop

    after_1:
    // 0x8009C894: bne         $v0, $zero, L_8009C8A4
    if (ctx->r2 != 0) {
        // 0x8009C898: addiu       $at, $zero, -0x5
        ctx->r1 = ADD32(0, -0X5);
            goto L_8009C8A4;
    }
    // 0x8009C898: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8009C89C: and         $t8, $s0, $at
    ctx->r24 = ctx->r16 & ctx->r1;
    // 0x8009C8A0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_8009C8A4:
    // 0x8009C8A4: jal         0x8006ECD0
    // 0x8009C8A8: nop

    get_settings(rdram, ctx);
        goto after_2;
    // 0x8009C8A8: nop

    after_2:
    // 0x8009C8AC: lbu         $a0, 0x49($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X49);
    // 0x8009C8B0: jal         0x8006B38C
    // 0x8009C8B4: nop

    leveltable_type(rdram, ctx);
        goto after_3;
    // 0x8009C8B4: nop

    after_3:
    // 0x8009C8B8: andi        $t9, $v0, 0x40
    ctx->r25 = ctx->r2 & 0X40;
    // 0x8009C8BC: beq         $t9, $zero, L_8009C8D4
    if (ctx->r25 == 0) {
        // 0x8009C8C0: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8009C8D4;
    }
    // 0x8009C8C0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009C8C4: lui         $at, 0xFFF0
    ctx->r1 = S32(0XFFF0 << 16);
    // 0x8009C8C8: ori         $at, $at, 0x677F
    ctx->r1 = ctx->r1 | 0X677F;
    // 0x8009C8CC: and         $t0, $s0, $at
    ctx->r8 = ctx->r16 & ctx->r1;
    // 0x8009C8D0: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_8009C8D4:
    // 0x8009C8D4: lw          $t1, -0x5EC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5EC);
    // 0x8009C8D8: nop

    // 0x8009C8DC: beq         $t1, $zero, L_8009C8FC
    if (ctx->r9 == 0) {
        // 0x8009C8E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009C8FC;
    }
    // 0x8009C8E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C8E4: jal         0x8006B480
    // 0x8009C8E8: nop

    level_is_race(rdram, ctx);
        goto after_4;
    // 0x8009C8E8: nop

    after_4:
    // 0x8009C8EC: beq         $v0, $zero, L_8009C8F8
    if (ctx->r2 == 0) {
        // 0x8009C8F0: ori         $t2, $s0, 0x4
        ctx->r10 = ctx->r16 | 0X4;
            goto L_8009C8F8;
    }
    // 0x8009C8F0: ori         $t2, $s0, 0x4
    ctx->r10 = ctx->r16 | 0X4;
    // 0x8009C8F4: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8009C8F8:
    // 0x8009C8F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009C8FC:
    // 0x8009C8FC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8009C900: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009C904: jr          $ra
    // 0x8009C908: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009C908: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void racerfx_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B020: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000B024: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000B028: sll         $s1, $a0, 2
    ctx->r17 = S32(ctx->r4 << 2);
    // 0x8000B02C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8000B030: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000B034: addu        $s1, $s1, $a0
    ctx->r17 = ADD32(ctx->r17, ctx->r4);
    // 0x8000B038: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000B03C: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x8000B040: sll         $s0, $a1, 4
    ctx->r16 = S32(ctx->r5 << 4);
    // 0x8000B044: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8000B048: addu        $a0, $s0, $s1
    ctx->r4 = ADD32(ctx->r16, ctx->r17);
    // 0x8000B04C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000B050: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000B054: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x8000B058: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x8000B05C: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x8000B060: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8000B064: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8000B068: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8000B06C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8000B070: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8000B074: jal         0x80070EDC
    // 0x8000B078: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8000B078: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_0:
    // 0x8000B07C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000B080: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000B084: addu        $t8, $v0, $s0
    ctx->r24 = ADD32(ctx->r2, ctx->r16);
    // 0x8000B088: addiu       $a1, $a1, -0x3344
    ctx->r5 = ADD32(ctx->r5, -0X3344);
    // 0x8000B08C: addiu       $v1, $v1, -0x333C
    ctx->r3 = ADD32(ctx->r3, -0X333C);
    // 0x8000B090: addu        $t0, $t8, $s0
    ctx->r8 = ADD32(ctx->r24, ctx->r16);
    // 0x8000B094: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x8000B098: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000B09C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8000B0A0: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8000B0A4: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x8000B0A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0AC: sw          $s3, -0x4A88($at)
    MEM_W(-0X4A88, ctx->r1) = ctx->r19;
    // 0x8000B0B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0B4: sw          $zero, -0x4A84($at)
    MEM_W(-0X4A84, ctx->r1) = 0;
    // 0x8000B0B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0BC: sw          $s2, -0x4A80($at)
    MEM_W(-0X4A80, ctx->r1) = ctx->r18;
    // 0x8000B0C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0C4: sw          $zero, -0x4A7C($at)
    MEM_W(-0X4A7C, ctx->r1) = 0;
    // 0x8000B0C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B0CC: sw          $zero, -0x4A78($at)
    MEM_W(-0X4A78, ctx->r1) = 0;
    // 0x8000B0D0: jal         0x8001E2D0
    // 0x8000B0D4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8000B0D4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_1:
    // 0x8000B0D8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000B0DC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000B0E0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8000B0E4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8000B0E8: addiu       $s3, $s3, -0x4A18
    ctx->r19 = ADD32(ctx->r19, -0X4A18);
    // 0x8000B0EC: addiu       $s1, $s1, -0x4A60
    ctx->r17 = ADD32(ctx->r17, -0X4A60);
    // 0x8000B0F0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000B0F4: addiu       $s7, $sp, 0x58
    ctx->r23 = ADD32(ctx->r29, 0X58);
    // 0x8000B0F8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_8000B0FC:
    // 0x8000B0FC: addiu       $t3, $zero, 0x7E
    ctx->r11 = ADD32(0, 0X7E);
    // 0x8000B100: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8000B104: sb          $t3, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r11;
    // 0x8000B108: sb          $t4, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r12;
    // 0x8000B10C: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
    // 0x8000B110: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    // 0x8000B114: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x8000B118: sb          $s2, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r18;
    // 0x8000B11C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000B120: jal         0x8000EA54
    // 0x8000B124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x8000B124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8000B128: beq         $v0, $zero, L_8000B198
    if (ctx->r2 == 0) {
        // 0x8000B12C: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8000B198;
    }
    // 0x8000B12C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8000B130: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x8000B134: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8000B138: sll         $t7, $s2, 7
    ctx->r15 = S32(ctx->r18 << 7);
    // 0x8000B13C: addu        $s0, $s5, $t7
    ctx->r16 = ADD32(ctx->r21, ctx->r15);
    // 0x8000B140: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000B144: sw          $zero, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = 0;
    // 0x8000B148: lh          $a0, 0x6C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6C);
    // 0x8000B14C: addiu       $t8, $t8, -0x4A70
    ctx->r24 = ADD32(ctx->r24, -0X4A70);
    // 0x8000B150: sb          $zero, 0x70($s0)
    MEM_B(0X70, ctx->r16) = 0;
    // 0x8000B154: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
    // 0x8000B158: addu        $s4, $s2, $t8
    ctx->r20 = ADD32(ctx->r18, ctx->r24);
    // 0x8000B15C: jal         0x8007C57C
    // 0x8000B160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_3;
    // 0x8000B160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8000B164: lh          $a0, 0x6E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6E);
    // 0x8000B168: jal         0x8007B2C4
    // 0x8000B16C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    load_texture(rdram, ctx);
        goto after_4;
    // 0x8000B16C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    after_4:
    // 0x8000B170: sw          $v0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r2;
    // 0x8000B174: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B178: jal         0x8006FB8C
    // 0x8000B17C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_5;
    // 0x8000B17C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_5:
    // 0x8000B180: sb          $v0, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r2;
    // 0x8000B184: sb          $zero, 0x73($s0)
    MEM_B(0X73, ctx->r16) = 0;
    // 0x8000B188: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B18C: jal         0x8006FB8C
    // 0x8000B190: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_6;
    // 0x8000B190: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_6:
    // 0x8000B194: sb          $v0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r2;
L_8000B198:
    // 0x8000B198: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000B19C: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x8000B1A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000B1A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000B1A8: bne         $at, $zero, L_8000B0FC
    if (ctx->r1 != 0) {
        // 0x8000B1AC: sb          $s6, -0x1($s3)
        MEM_B(-0X1, ctx->r19) = ctx->r22;
            goto L_8000B0FC;
    }
    // 0x8000B1AC: sb          $s6, -0x1($s3)
    MEM_B(-0X1, ctx->r19) = ctx->r22;
    // 0x8000B1B0: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8000B1B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B1B8: addiu       $t0, $zero, 0x8D
    ctx->r8 = ADD32(0, 0X8D);
    // 0x8000B1BC: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8000B1C0: sw          $t9, -0x3330($at)
    MEM_W(-0X3330, ctx->r1) = ctx->r25;
    // 0x8000B1C4: sb          $t0, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r8;
    // 0x8000B1C8: sb          $t1, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r9;
    // 0x8000B1CC: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
    // 0x8000B1D0: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    // 0x8000B1D4: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x8000B1D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000B1DC: jal         0x8000EA54
    // 0x8000B1E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    spawn_object(rdram, ctx);
        goto after_7;
    // 0x8000B1E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8000B1E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B1E8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000B1EC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000B1F0: sw          $v0, -0x3334($at)
    MEM_W(-0X3334, ctx->r1) = ctx->r2;
    // 0x8000B1F4: addiu       $s1, $s1, -0x49E0
    ctx->r17 = ADD32(ctx->r17, -0X49E0);
    // 0x8000B1F8: addiu       $s0, $s0, -0x4A08
    ctx->r16 = ADD32(ctx->r16, -0X4A08);
L_8000B1FC:
    // 0x8000B1FC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8000B200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B204: jal         0x8006FB8C
    // 0x8000B208: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_8;
    // 0x8000B208: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_8:
    // 0x8000B20C: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x8000B210: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B214: jal         0x8006FB8C
    // 0x8000B218: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_9;
    // 0x8000B218: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_9:
    // 0x8000B21C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000B220: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // 0x8000B224: bne         $s0, $s1, L_8000B1FC
    if (ctx->r16 != ctx->r17) {
        // 0x8000B228: sb          $zero, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = 0;
            goto L_8000B1FC;
    }
    // 0x8000B228: sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // 0x8000B22C: addiu       $t2, $zero, 0x1B
    ctx->r10 = ADD32(0, 0X1B);
    // 0x8000B230: addiu       $t3, $zero, 0x8A
    ctx->r11 = ADD32(0, 0X8A);
    // 0x8000B234: sb          $t2, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r10;
    // 0x8000B238: sb          $t3, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r11;
    // 0x8000B23C: sh          $zero, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = 0;
    // 0x8000B240: sh          $zero, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = 0;
    // 0x8000B244: sh          $zero, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = 0;
    // 0x8000B248: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8000B24C: jal         0x8000EA54
    // 0x8000B250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    spawn_object(rdram, ctx);
        goto after_10;
    // 0x8000B250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8000B254: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000B258: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B25C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8000B260: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8000B264: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B268: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000B26C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8000B270: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8000B274: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B278: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8000B27C: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8000B280: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8000B284: sw          $v0, -0x332C($at)
    MEM_W(-0X332C, ctx->r1) = ctx->r2;
    // 0x8000B288: jr          $ra
    // 0x8000B28C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8000B28C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void cheatmenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A97C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A980: jal         0x800C478C
    // 0x8008A984: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x8008A984: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008A988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A98C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A990: jr          $ra
    // 0x8008A994: nop

    return;
    // 0x8008A994: nop

;}
RECOMP_FUNC void is_tt_unlocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F1FC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009F200: lw          $v0, 0x318($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X318);
    // 0x8009F204: nop

    // 0x8009F208: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8009F20C: jr          $ra
    // 0x8009F210: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8009F210: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void obj_taj_create_balloon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022D30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80022D34: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80022D38: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80022D3C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80022D40: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80022D44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80022D48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80022D4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80022D50: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80022D54: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80022D58: jal         0x8006ECD0
    // 0x80022D5C: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80022D5C: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80022D60: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80022D64: lw          $t0, -0x4C24($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4C24);
    // 0x80022D68: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80022D6C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80022D70: blez        $t0, L_80022E34
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80022D74: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80022E34;
    }
    // 0x80022D74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80022D78: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80022D7C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80022D80: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80022D84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022D88: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x80022D8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80022D90: addiu       $t2, $zero, 0x4D
    ctx->r10 = ADD32(0, 0X4D);
L_80022D94:
    // 0x80022D94: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80022D98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80022D9C: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80022DA0: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80022DA4: nop

    // 0x80022DA8: lh          $t8, 0x48($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X48);
    // 0x80022DAC: nop

    // 0x80022DB0: bne         $t2, $t8, L_80022E2C
    if (ctx->r10 != ctx->r24) {
        // 0x80022DB4: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022E2C;
    }
    // 0x80022DB4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022DB8: lw          $a0, 0x3C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X3C);
    // 0x80022DBC: nop

    // 0x80022DC0: beq         $a0, $zero, L_80022E2C
    if (ctx->r4 == 0) {
        // 0x80022DC4: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022E2C;
    }
    // 0x80022DC4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022DC8: lb          $a1, 0xA($a0)
    ctx->r5 = MEM_B(ctx->r4, 0XA);
    // 0x80022DCC: nop

    // 0x80022DD0: blez        $a1, L_80022E2C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80022DD4: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022E2C;
    }
    // 0x80022DD4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022DD8: lhu         $a0, 0x14($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X14);
    // 0x80022DDC: addiu       $t9, $a1, 0x2
    ctx->r25 = ADD32(ctx->r5, 0X2);
    // 0x80022DE0: beq         $a0, $zero, L_80022E28
    if (ctx->r4 == 0) {
        // 0x80022DE4: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80022E28;
    }
    // 0x80022DE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80022DE8: sllv        $t4, $t3, $t9
    ctx->r12 = S32(ctx->r11 << (ctx->r25 & 31));
    // 0x80022DEC: and         $t5, $a0, $t4
    ctx->r13 = ctx->r4 & ctx->r12;
    // 0x80022DF0: beq         $t5, $zero, L_80022E2C
    if (ctx->r13 == 0) {
        // 0x80022DF4: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80022E2C;
    }
    // 0x80022DF4: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80022DF8: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80022DFC: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x80022E00: swc1        $f12, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f12.u32l;
    // 0x80022E04: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80022E08: swc1        $f20, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f20.u32l;
    // 0x80022E0C: swc1        $f8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f8.u32l;
    // 0x80022E10: sh          $s0, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = ctx->r16;
    // 0x80022E14: sw          $zero, 0x78($v1)
    MEM_W(0X78, ctx->r3) = 0;
    // 0x80022E18: sb          $zero, 0x39($v1)
    MEM_B(0X39, ctx->r3) = 0;
    // 0x80022E1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80022E20: lw          $t0, -0x4C24($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4C24);
    // 0x80022E24: nop

L_80022E28:
    // 0x80022E28: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
L_80022E2C:
    // 0x80022E2C: bne         $at, $zero, L_80022D94
    if (ctx->r1 != 0) {
        // 0x80022E30: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80022D94;
    }
    // 0x80022E30: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80022E34:
    // 0x80022E34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80022E38: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80022E3C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80022E40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80022E44: jr          $ra
    // 0x80022E48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80022E48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_loop_trophycab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034EDC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80034EE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80034EE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80034EE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80034EEC: jal         0x8006ECD0
    // 0x80034EF0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80034EF0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80034EF4: jal         0x8006BFF0
    // 0x80034EF8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    level_header(rdram, ctx);
        goto after_1;
    // 0x80034EF8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_1:
    // 0x80034EFC: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80034F00: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80034F04: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x80034F08: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x80034F0C: nop

    // 0x80034F10: bne         $t7, $zero, L_80034FB8
    if (ctx->r15 != 0) {
        // 0x80034F14: nop
    
            goto L_80034FB8;
    }
    // 0x80034F14: nop

    // 0x80034F18: lb          $a0, 0x4C($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X4C);
    // 0x80034F1C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80034F20: beq         $a0, $at, L_80034FB8
    if (ctx->r4 == ctx->r1) {
        // 0x80034F24: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80034FB8;
    }
    // 0x80034F24: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80034F28: beq         $a0, $at, L_80034FB8
    if (ctx->r4 == ctx->r1) {
        // 0x80034F2C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80034FB8;
    }
    // 0x80034F2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80034F30: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x80034F34: lbu         $t0, 0x48($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X48);
    // 0x80034F38: lhu         $t9, 0xE($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XE);
    // 0x80034F3C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80034F40: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80034F44: srav        $t3, $t9, $t2
    ctx->r11 = S32(SIGNED(ctx->r25) >> (ctx->r10 & 31));
    // 0x80034F48: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x80034F4C: beq         $t4, $zero, L_80034FB8
    if (ctx->r12 == 0) {
        // 0x80034F50: addiu       $t5, $zero, 0x80
        ctx->r13 = ADD32(0, 0X80);
            goto L_80034FB8;
    }
    // 0x80034F50: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80034F54: sb          $t5, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r13;
    // 0x80034F58: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x80034F5C: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80034F60: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80034F64: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80034F68: sh          $t7, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r15;
    // 0x80034F6C: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80034F70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80034F74: lh          $t0, 0x4($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X4);
    // 0x80034F78: nop

    // 0x80034F7C: sh          $t0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r8;
    // 0x80034F80: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x80034F84: nop

    // 0x80034F88: lh          $t9, 0x6($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X6);
    // 0x80034F8C: sb          $t2, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r10;
    // 0x80034F90: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x80034F94: jal         0x8000EA54
    // 0x80034F98: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
    spawn_object(rdram, ctx);
        goto after_2;
    // 0x80034F98: sh          $t9, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r25;
    after_2:
    // 0x80034F9C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80034FA0: beq         $v0, $zero, L_80034FB8
    if (ctx->r2 == 0) {
        // 0x80034FA4: nop
    
            goto L_80034FB8;
    }
    // 0x80034FA4: nop

    // 0x80034FA8: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80034FAC: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80034FB0: nop

    // 0x80034FB4: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
L_80034FB8:
    // 0x80034FB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034FBC: lwc1        $f4, 0x6594($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6594);
    // 0x80034FC0: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
    // 0x80034FC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80034FC8: swc1        $f4, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f4.u32l;
    // 0x80034FCC: lw          $t5, 0x54($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X54);
    // 0x80034FD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80034FD4: swc1        $f6, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f6.u32l;
    // 0x80034FD8: jal         0x8001BAFC
    // 0x80034FDC: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    get_racer_object(rdram, ctx);
        goto after_3;
    // 0x80034FDC: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    after_3:
    // 0x80034FE0: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80034FE4: beq         $v0, $zero, L_80035260
    if (ctx->r2 == 0) {
        // 0x80034FE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035260;
    }
    // 0x80034FE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80034FEC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034FF0: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80034FF4: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034FF8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80034FFC: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80035000: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80035004: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80035008: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x8003500C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80035010: jal         0x800CA030
    // 0x80035014: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80035014: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_4:
    // 0x80035018: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8003501C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80035020: lbu         $a0, 0x48($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X48);
    // 0x80035024: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80035028: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x8003502C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80035030: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80035034: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80035038: slti        $t9, $t1, 0x8
    ctx->r25 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x8003503C: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x80035040: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80035044: beq         $t9, $zero, L_80035060
    if (ctx->r25 == 0) {
        // 0x80035048: ori         $t6, $v0, 0x800
        ctx->r14 = ctx->r2 | 0X800;
            goto L_80035060;
    }
    // 0x80035048: ori         $t6, $v0, 0x800
    ctx->r14 = ctx->r2 | 0X800;
    // 0x8003504C: addiu       $t3, $a0, 0x6
    ctx->r11 = ADD32(ctx->r4, 0X6);
    // 0x80035050: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x80035054: and         $t6, $t5, $t6
    ctx->r14 = ctx->r13 & ctx->r14;
    // 0x80035058: sltu        $t7, $zero, $t6
    ctx->r15 = 0 < ctx->r14 ? 1 : 0;
    // 0x8003505C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80035060:
    // 0x80035060: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x80035064: nop

    // 0x80035068: bne         $t8, $zero, L_80035108
    if (ctx->r24 != 0) {
        // 0x8003506C: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_80035108;
    }
    // 0x8003506C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035070: jal         0x800C3958
    // 0x80035074: nop

    textbox_visible(rdram, ctx);
        goto after_5;
    // 0x80035074: nop

    after_5:
    // 0x80035078: bne         $v0, $zero, L_80035108
    if (ctx->r2 != 0) {
        // 0x8003507C: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_80035108;
    }
    // 0x8003507C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035080: lw          $t0, 0x5C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X5C);
    // 0x80035084: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035088: lw          $t1, 0x100($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X100);
    // 0x8003508C: nop

    // 0x80035090: beq         $t1, $zero, L_80035104
    if (ctx->r9 == 0) {
        // 0x80035094: nop
    
            goto L_80035104;
    }
    // 0x80035094: nop

    // 0x80035098: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x8003509C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800350A0: bne         $t9, $zero, L_80035108
    if (ctx->r25 != 0) {
        // 0x800350A4: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_80035108;
    }
    // 0x800350A4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800350A8: beq         $t2, $zero, L_800350D0
    if (ctx->r10 == 0) {
        // 0x800350AC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800350D0;
    }
    // 0x800350AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800350B0: sw          $t4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r12;
    // 0x800350B4: addiu       $a0, $zero, 0x12F
    ctx->r4 = ADD32(0, 0X12F);
    // 0x800350B8: jal         0x80001D04
    // 0x800350BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x800350BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x800350C0: jal         0x800A3DB8
    // 0x800350C4: nop

    hud_speedometre_reset(rdram, ctx);
        goto after_7;
    // 0x800350C4: nop

    after_7:
    // 0x800350C8: b           L_80035108
    // 0x800350CC: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
        goto L_80035108;
    // 0x800350CC: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_800350D0:
    // 0x800350D0: jal         0x800C3744
    // 0x800350D4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    set_current_text(rdram, ctx);
        goto after_8;
    // 0x800350D4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_8:
    // 0x800350D8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800350DC: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x800350E0: addiu       $t6, $zero, 0x8C
    ctx->r14 = ADD32(0, 0X8C);
    // 0x800350E4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800350E8: sh          $t3, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r11;
    // 0x800350EC: jal         0x80000C38
    // 0x800350F0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_9;
    // 0x800350F0: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    after_9:
    // 0x800350F4: jal         0x80000C98
    // 0x800350F8: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    music_fade(rdram, ctx);
        goto after_10;
    // 0x800350F8: addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    after_10:
    // 0x800350FC: jal         0x80001BC0
    // 0x80035100: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    music_jingle_play(rdram, ctx);
        goto after_11;
    // 0x80035100: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_11:
L_80035104:
    // 0x80035104: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_80035108:
    // 0x80035108: nop

    // 0x8003510C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80035110: nop

    // 0x80035114: beq         $t7, $zero, L_80035164
    if (ctx->r15 == 0) {
        // 0x80035118: nop
    
            goto L_80035164;
    }
    // 0x80035118: nop

    // 0x8003511C: jal         0x80001C08
    // 0x80035120: nop

    music_jingle_playing(rdram, ctx);
        goto after_12;
    // 0x80035120: nop

    after_12:
    // 0x80035124: bne         $v0, $zero, L_80035164
    if (ctx->r2 != 0) {
        // 0x80035128: nop
    
            goto L_80035164;
    }
    // 0x80035128: nop

    // 0x8003512C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80035130: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80035134: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80035138: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8003513C: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80035140: beq         $at, $zero, L_80035154
    if (ctx->r1 == 0) {
        // 0x80035144: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80035154;
    }
    // 0x80035144: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80035148: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x8003514C: b           L_80035164
    // 0x80035150: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
        goto L_80035164;
    // 0x80035150: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
L_80035154:
    // 0x80035154: jal         0x80000C98
    // 0x80035158: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    music_fade(rdram, ctx);
        goto after_13;
    // 0x80035158: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    after_13:
    // 0x8003515C: jal         0x80000C38
    // 0x80035160: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_jingle_voicelimit_set(rdram, ctx);
        goto after_14;
    // 0x80035160: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_14:
L_80035164:
    // 0x80035164: lw          $t2, 0x5C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X5C);
    // 0x80035168: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8003516C: lw          $t4, 0x100($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X100);
    // 0x80035170: nop

    // 0x80035174: bne         $t4, $zero, L_80035198
    if (ctx->r12 != 0) {
        // 0x80035178: addiu       $t3, $zero, 0xB4
        ctx->r11 = ADD32(0, 0XB4);
            goto L_80035198;
    }
    // 0x80035178: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x8003517C: jal         0x800C3958
    // 0x80035180: nop

    textbox_visible(rdram, ctx);
        goto after_15;
    // 0x80035180: nop

    after_15:
    // 0x80035184: beq         $v0, $zero, L_800351A0
    if (ctx->r2 == 0) {
        // 0x80035188: lw          $v1, 0x50($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X50);
            goto L_800351A0;
    }
    // 0x80035188: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8003518C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80035190: nop

    // 0x80035194: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
L_80035198:
    // 0x80035198: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x8003519C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_800351A0:
    // 0x800351A0: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800351A4: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800351A8: nop

    // 0x800351AC: blez        $v0, L_800351BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800351B0: subu        $t5, $v0, $t6
        ctx->r13 = SUB32(ctx->r2, ctx->r14);
            goto L_800351BC;
    }
    // 0x800351B0: subu        $t5, $v0, $t6
    ctx->r13 = SUB32(ctx->r2, ctx->r14);
    // 0x800351B4: b           L_800351C0
    // 0x800351B8: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
        goto L_800351C0;
    // 0x800351B8: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
L_800351BC:
    // 0x800351BC: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
L_800351C0:
    // 0x800351C0: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x800351C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800351C8: bne         $t7, $at, L_80035230
    if (ctx->r15 != ctx->r1) {
        // 0x800351CC: nop
    
            goto L_80035230;
    }
    // 0x800351CC: nop

    // 0x800351D0: jal         0x800AB708
    // 0x800351D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    minimap_opacity_set(rdram, ctx);
        goto after_16;
    // 0x800351D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x800351D8: jal         0x800AB730
    // 0x800351DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_visibility(rdram, ctx);
        goto after_17;
    // 0x800351DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x800351E0: jal         0x8009D530
    // 0x800351E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    npc_dialogue_loop(rdram, ctx);
        goto after_18;
    // 0x800351E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_18:
    // 0x800351E8: beq         $v0, $zero, L_80035228
    if (ctx->r2 == 0) {
        // 0x800351EC: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80035228;
    }
    // 0x800351EC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800351F0: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x800351F4: jal         0x8009D4AC
    // 0x800351F8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    dialogue_npc_finish(rdram, ctx);
        goto after_19;
    // 0x800351F8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_19:
    // 0x800351FC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80035200: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80035204: bne         $v1, $at, L_80035220
    if (ctx->r3 != ctx->r1) {
        // 0x80035208: nop
    
            goto L_80035220;
    }
    // 0x80035208: nop

    // 0x8003520C: jal         0x8006F494
    // 0x80035210: nop

    begin_trophy_race_teleport(rdram, ctx);
        goto after_20;
    // 0x80035210: nop

    after_20:
    // 0x80035214: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80035218: b           L_80035228
    // 0x8003521C: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
        goto L_80035228;
    // 0x8003521C: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
L_80035220:
    // 0x80035220: jal         0x800AB730
    // 0x80035224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    hud_visibility(rdram, ctx);
        goto after_21;
    // 0x80035224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_21:
L_80035228:
    // 0x80035228: jal         0x8005A41C
    // 0x8003522C: nop

    disable_racer_input(rdram, ctx);
        goto after_22;
    // 0x8003522C: nop

    after_22:
L_80035230:
    // 0x80035230: lw          $t1, 0x5C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X5C);
    // 0x80035234: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80035238: sw          $zero, 0x100($t1)
    MEM_W(0X100, ctx->r9) = 0;
    // 0x8003523C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80035240: nop

    // 0x80035244: beq         $t8, $zero, L_80035260
    if (ctx->r24 == 0) {
        // 0x80035248: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035260;
    }
    // 0x80035248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003524C: lwc1        $f8, 0x6598($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6598);
    // 0x80035250: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x80035254: nop

    // 0x80035258: swc1        $f8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f8.u32l;
    // 0x8003525C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80035260:
    // 0x80035260: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80035264: jr          $ra
    // 0x80035268: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80035268: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void mempool_alloc_pool(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800710D0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800710D4: lw          $a3, 0x3B40($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X3B40);
    // 0x800710D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800710DC: beq         $a3, $zero, L_80071124
    if (ctx->r7 == 0) {
        // 0x800710E0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80071124;
    }
    // 0x800710E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800710E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800710E8: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x800710EC: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x800710F0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_800710F4:
    // 0x800710F4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800710F8: nop

    // 0x800710FC: bne         $a0, $t8, L_80071118
    if (ctx->r4 != ctx->r24) {
        // 0x80071100: nop
    
            goto L_80071118;
    }
    // 0x80071100: nop

    // 0x80071104: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80071108: jal         0x80070F7C
    // 0x8007110C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mempool_slot_find(rdram, ctx);
        goto after_0;
    // 0x8007110C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80071110: b           L_8007112C
    // 0x80071114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8007112C;
    // 0x80071114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80071118:
    // 0x80071118: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8007111C: bne         $a3, $zero, L_800710F4
    if (ctx->r7 != 0) {
        // 0x80071120: addiu       $v0, $v0, -0x10
        ctx->r2 = ADD32(ctx->r2, -0X10);
            goto L_800710F4;
    }
    // 0x80071120: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
L_80071124:
    // 0x80071124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80071128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007112C:
    // 0x8007112C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071130: jr          $ra
    // 0x80071134: nop

    return;
    // 0x80071134: nop

;}
RECOMP_FUNC void obj_init_wavegenerator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800409E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800409E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800409EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800409F0: jal         0x800BFA44
    // 0x800409F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    wavegen_add(rdram, ctx);
        goto after_0;
    // 0x800409F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800409F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800409FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040A00: jr          $ra
    // 0x80040A04: nop

    return;
    // 0x80040A04: nop

;}
RECOMP_FUNC void init_controller_paks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075D70: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80075D74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80075D78: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80075D7C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80075D80: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80075D84: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80075D88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80075D8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80075D90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80075D94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80075D98: jal         0x8006A340
    // 0x80075D9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80075D9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80075DA0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80075DA4: addiu       $s4, $s4, 0x4590
    ctx->r20 = ADD32(ctx->r20, 0X4590);
    // 0x80075DA8: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80075DAC: jal         0x8001E2D0
    // 0x80075DB0: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80075DB0: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_1:
    // 0x80075DB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075DB8: sw          $v0, 0x4760($at)
    MEM_W(0X4760, ctx->r1) = ctx->r2;
    // 0x80075DBC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80075DC0: addiu       $v1, $v1, 0x4767
    ctx->r3 = ADD32(ctx->r3, 0X4767);
    // 0x80075DC4: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80075DC8: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80075DCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075DD0: sb          $t7, 0x4766($at)
    MEM_B(0X4766, ctx->r1) = ctx->r15;
    // 0x80075DD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075DD8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075DDC: sb          $t8, 0x4764($at)
    MEM_B(0X4764, ctx->r1) = ctx->r24;
    // 0x80075DE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80075DE4: sw          $zero, 0x4768($at)
    MEM_W(0X4768, ctx->r1) = 0;
    // 0x80075DE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80075DEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80075DF0: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80075DF4: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x80075DF8: sw          $t9, -0x1604($at)
    MEM_W(-0X1604, ctx->r1) = ctx->r25;
    // 0x80075DFC: addiu       $s6, $s6, -0x1608
    ctx->r22 = ADD32(ctx->r22, -0X1608);
    // 0x80075E00: addiu       $s5, $s5, 0x4765
    ctx->r21 = ADD32(ctx->r21, 0X4765);
    // 0x80075E04: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075E08: sb          $zero, 0x0($s5)
    MEM_B(0X0, ctx->r21) = 0;
    // 0x80075E0C: sb          $zero, 0x0($s6)
    MEM_B(0X0, ctx->r22) = 0;
    // 0x80075E10: jal         0x800CD7F0
    // 0x80075E14: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_2;
    // 0x80075E14: addiu       $a1, $sp, 0x4E
    ctx->r5 = ADD32(ctx->r29, 0X4E);
    after_2:
    // 0x80075E18: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80075E1C: addiu       $s1, $s1, 0x4738
    ctx->r17 = ADD32(ctx->r17, 0X4738);
    // 0x80075E20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80075E24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80075E28: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x80075E2C: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
L_80075E30:
    // 0x80075E30: lbu         $t2, 0x4E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X4E);
    // 0x80075E34: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x80075E38: lh          $t1, 0x2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X2);
    // 0x80075E3C: and         $t3, $t2, $v1
    ctx->r11 = ctx->r10 & ctx->r3;
    // 0x80075E40: sh          $s7, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r23;
    // 0x80075E44: sh          $s7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r23;
    // 0x80075E48: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80075E4C: beq         $t3, $zero, L_80075EE4
    if (ctx->r11 == 0) {
        // 0x80075E50: sh          $t1, 0x6($s1)
        MEM_H(0X6, ctx->r17) = ctx->r9;
            goto L_80075EE4;
    }
    // 0x80075E50: sh          $t1, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r9;
    // 0x80075E54: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80075E58: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80075E5C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80075E60: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x80075E64: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80075E68: addiu       $t5, $t5, 0x4598
    ctx->r13 = ADD32(ctx->r13, 0X4598);
    // 0x80075E6C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80075E70: addu        $s2, $t4, $t5
    ctx->r18 = ADD32(ctx->r12, ctx->r13);
    // 0x80075E74: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075E78: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80075E7C: jal         0x800CF280
    // 0x80075E80: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80075E80: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80075E84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075E88: bne         $v0, $at, L_80075E9C
    if (ctx->r2 != ctx->r1) {
        // 0x80075E8C: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80075E9C;
    }
    // 0x80075E8C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80075E90: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075E94: jal         0x800CF280
    // 0x80075E98: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_4;
    // 0x80075E98: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
L_80075E9C:
    // 0x80075E9C: bne         $v0, $zero, L_80075EB8
    if (ctx->r2 != 0) {
        // 0x80075EA0: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80075EB8;
    }
    // 0x80075EA0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80075EA4: lbu         $t6, 0x0($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X0);
    // 0x80075EA8: nop

    // 0x80075EAC: or          $t7, $t6, $s3
    ctx->r15 = ctx->r14 | ctx->r19;
    // 0x80075EB0: b           L_80075EE4
    // 0x80075EB4: sb          $t7, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r15;
        goto L_80075EE4;
    // 0x80075EB4: sb          $t7, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r15;
L_80075EB8:
    // 0x80075EB8: bne         $v0, $at, L_80075EE4
    if (ctx->r2 != ctx->r1) {
        // 0x80075EBC: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80075EE4;
    }
    // 0x80075EBC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80075EC0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075EC4: jal         0x8007231C
    // 0x80075EC8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_5;
    // 0x80075EC8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80075ECC: bne         $v0, $zero, L_80075EE8
    if (ctx->r2 != 0) {
        // 0x80075ED0: sll         $v1, $s3, 1
        ctx->r3 = S32(ctx->r19 << 1);
            goto L_80075EE8;
    }
    // 0x80075ED0: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
    // 0x80075ED4: lbu         $t8, 0x0($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X0);
    // 0x80075ED8: nop

    // 0x80075EDC: or          $t9, $t8, $s3
    ctx->r25 = ctx->r24 | ctx->r19;
    // 0x80075EE0: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
L_80075EE4:
    // 0x80075EE4: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
L_80075EE8:
    // 0x80075EE8: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x80075EEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80075EF0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80075EF4: bne         $s0, $fp, L_80075E30
    if (ctx->r16 != ctx->r30) {
        // 0x80075EF8: addiu       $s1, $s1, 0xA
        ctx->r17 = ADD32(ctx->r17, 0XA);
            goto L_80075E30;
    }
    // 0x80075EF8: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80075EFC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075F00: jal         0x800CD540
    // 0x80075F04: nop

    osContStartReadData_recomp(rdram, ctx);
        goto after_6;
    // 0x80075F04: nop

    after_6:
    // 0x80075F08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80075F0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80075F10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80075F14: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80075F18: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80075F1C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80075F20: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80075F24: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80075F28: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80075F2C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80075F30: jr          $ra
    // 0x80075F34: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80075F34: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void gfxtask_run_rdp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077F04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80077F08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80077F0C: jal         0x800D1E00
    // 0x80077F10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077F10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80077F14: jal         0x800D1E30
    // 0x80077F18: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_1;
    // 0x80077F18: nop

    after_1:
    // 0x80077F1C: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x80077F20: beq         $t6, $zero, L_80077F40
    if (ctx->r14 == 0) {
        // 0x80077F24: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80077F40;
    }
    // 0x80077F24: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80077F28:
    // 0x80077F28: jal         0x800D1E30
    // 0x80077F2C: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_2;
    // 0x80077F2C: nop

    after_2:
    // 0x80077F30: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x80077F34: bne         $t7, $zero, L_80077F28
    if (ctx->r15 != 0) {
        // 0x80077F38: nop
    
            goto L_80077F28;
    }
    // 0x80077F38: nop

    // 0x80077F3C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80077F40:
    // 0x80077F40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80077F44: jal         0x800D1E40
    // 0x80077F48: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x80077F48: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_3:
    // 0x80077F4C: jal         0x800D1E30
    // 0x80077F50: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_4;
    // 0x80077F50: nop

    after_4:
    // 0x80077F54: andi        $t9, $v0, 0x100
    ctx->r25 = ctx->r2 & 0X100;
    // 0x80077F58: beq         $t9, $zero, L_80077F78
    if (ctx->r25 == 0) {
        // 0x80077F5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80077F78;
    }
    // 0x80077F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80077F60:
    // 0x80077F60: jal         0x800D1E30
    // 0x80077F64: nop

    osDpGetStatus_recomp(rdram, ctx);
        goto after_5;
    // 0x80077F64: nop

    after_5:
    // 0x80077F68: andi        $t0, $v0, 0x100
    ctx->r8 = ctx->r2 & 0X100;
    // 0x80077F6C: bne         $t0, $zero, L_80077F60
    if (ctx->r8 != 0) {
        // 0x80077F70: nop
    
            goto L_80077F60;
    }
    // 0x80077F70: nop

    // 0x80077F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80077F78:
    // 0x80077F78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077F7C: jr          $ra
    // 0x80077F80: nop

    return;
    // 0x80077F80: nop

;}
RECOMP_FUNC void cam_rotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069EF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069EF8: lw          $t6, 0x1264($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1264);
    // 0x80069EFC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069F00: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80069F04: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80069F08: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069F0C: addiu       $t8, $t8, 0x1040
    ctx->r24 = ADD32(ctx->r24, 0X1040);
    // 0x80069F10: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80069F14: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80069F18: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80069F1C: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x80069F20: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x80069F24: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x80069F28: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x80069F2C: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x80069F30: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x80069F34: jr          $ra
    // 0x80069F38: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
    return;
    // 0x80069F38: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
;}
