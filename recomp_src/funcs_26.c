#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void toggle_lead_player_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E194: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E198: addiu       $v0, $v0, -0x3354
    ctx->r2 = ADD32(ctx->r2, -0X3354);
    // 0x8000E19C: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8000E1A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000E1A4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8000E1A8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8000E1AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E1B0: jr          $ra
    // 0x8000E1B4: sb          $zero, -0x3350($at)
    MEM_B(-0X3350, ctx->r1) = 0;
    return;
    // 0x8000E1B4: sb          $zero, -0x3350($at)
    MEM_B(-0X3350, ctx->r1) = 0;
;}
RECOMP_FUNC void savemenu_render_element(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085810: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80085814: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x80085818: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008581C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80085820: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80085824: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x80085828: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x8008582C: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80085830: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80085834: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80085838: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x8008583C: beq         $at, $zero, L_80085C68
    if (ctx->r1 == 0) {
        // 0x80085840: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80085C68;
    }
    // 0x80085840: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80085844: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80085848: addu        $at, $at, $t8
    gpr jr_addend_80085854 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8008584C: lw          $t8, -0x76B8($at)
    ctx->r24 = ADD32(ctx->r1, -0X76B8);
    // 0x80085850: nop

    // 0x80085854: jr          $t8
    // 0x80085858: nop

    switch (jr_addend_80085854 >> 2) {
        case 0: goto L_8008585C; break;
        case 1: goto L_8008597C; break;
        case 2: goto L_800859B4; break;
        case 3: goto L_80085AD0; break;
        case 4: goto L_80085B1C; break;
        case 5: goto L_80085B68; break;
        case 6: goto L_80085C68; break;
        case 7: goto L_80085BB4; break;
        case 8: goto L_80085C00; break;
        case 9: goto L_80085C30; break;
        default: switch_error(__func__, 0x80085854, 0x800E8948);
    }
    // 0x80085858: nop

L_8008585C:
    // 0x8008585C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80085860: addiu       $t9, $t9, 0x190
    ctx->r25 = ADD32(ctx->r25, 0X190);
    // 0x80085864: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80085868: lbu         $v1, 0x6($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X6);
    // 0x8008586C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80085870: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80085874: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80085878: lw          $v0, 0x6AD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6AD0);
    // 0x8008587C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085880: lbu         $t3, 0x4B($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4B);
    // 0x80085884: lw          $t0, 0x6BFC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6BFC);
    // 0x80085888: lui         $t1, 0xB0E0
    ctx->r9 = S32(0XB0E0 << 16);
    // 0x8008588C: ori         $t1, $t1, 0xC0FF
    ctx->r9 = ctx->r9 | 0XC0FF;
    // 0x80085890: bne         $t3, $zero, L_80085950
    if (ctx->r11 != 0) {
        // 0x80085894: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80085950;
    }
    // 0x80085894: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80085898: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x8008589C: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x800858A0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800858A4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800858A8: jal         0x80097C34
    // 0x800858AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    filename_decompress(rdram, ctx);
        goto after_0;
    // 0x800858AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x800858B0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800858B4: jal         0x80097D0C
    // 0x800858B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    filename_trim(rdram, ctx);
        goto after_1;
    // 0x800858B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_1:
    // 0x800858BC: addiu       $t4, $sp, 0x50
    ctx->r12 = ADD32(ctx->r29, 0X50);
    // 0x800858C0: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x800858C4: lbu         $t5, 0x6($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6);
    // 0x800858C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800858CC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800858D0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800858D4: lw          $v0, 0x6AD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6AD0);
    // 0x800858D8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800858DC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800858E0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800858E4: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
    // 0x800858E8: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x800858EC: div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // 0x800858F0: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x800858F4: bne         $a0, $zero, L_80085900
    if (ctx->r4 != 0) {
        // 0x800858F8: nop
    
            goto L_80085900;
    }
    // 0x800858F8: nop

    // 0x800858FC: break       7
    do_break(2148030716);
L_80085900:
    // 0x80085900: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80085904: bne         $a0, $at, L_80085918
    if (ctx->r4 != ctx->r1) {
        // 0x80085908: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80085918;
    }
    // 0x80085908: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008590C: bne         $v1, $at, L_80085918
    if (ctx->r3 != ctx->r1) {
        // 0x80085910: nop
    
            goto L_80085918;
    }
    // 0x80085910: nop

    // 0x80085914: break       6
    do_break(2148030740);
L_80085918:
    // 0x80085918: mflo        $t8
    ctx->r24 = lo;
    // 0x8008591C: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x80085920: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x80085924: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80085928: mflo        $t2
    ctx->r10 = lo;
    // 0x8008592C: subu        $t3, $v1, $t2
    ctx->r11 = SUB32(ctx->r3, ctx->r10);
    // 0x80085930: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x80085934: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x80085938: nop

    // 0x8008593C: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x80085940: beq         $t5, $zero, L_80085964
    if (ctx->r13 == 0) {
        // 0x80085944: nop
    
            goto L_80085964;
    }
    // 0x80085944: nop

    // 0x80085948: b           L_80085964
    // 0x8008594C: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
        goto L_80085964;
    // 0x8008594C: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_80085950:
    // 0x80085950: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80085954: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80085958: lw          $t7, 0x930($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X930);
    // 0x8008595C: nop

    // 0x80085960: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
L_80085964:
    // 0x80085964: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80085968: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8008596C: nop

    // 0x80085970: lw          $t9, 0x1DC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1DC);
    // 0x80085974: b           L_80085C98
    // 0x80085978: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
        goto L_80085C98;
    // 0x80085978: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
L_8008597C:
    // 0x8008597C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80085980: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085984: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x80085988: addiu       $t2, $t2, 0x1A0
    ctx->r10 = ADD32(ctx->r10, 0X1A0);
    // 0x8008598C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80085990: lw          $t3, 0x1E0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1E0);
    // 0x80085994: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085998: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x8008599C: lw          $t4, 0x1DC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1DC);
    // 0x800859A0: lw          $t0, 0x6BFC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6BFC);
    // 0x800859A4: lui         $t1, 0xB0E0
    ctx->r9 = S32(0XB0E0 << 16);
    // 0x800859A8: ori         $t1, $t1, 0xC0FF
    ctx->r9 = ctx->r9 | 0XC0FF;
    // 0x800859AC: b           L_80085C98
    // 0x800859B0: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
        goto L_80085C98;
    // 0x800859B0: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
L_800859B4:
    // 0x800859B4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800859B8: addiu       $t5, $t5, 0x190
    ctx->r13 = ADD32(ctx->r13, 0X190);
    // 0x800859BC: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800859C0: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    // 0x800859C4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800859C8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800859CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800859D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800859D4: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800859D8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800859DC: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x800859E0: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x800859E4: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x800859E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800859EC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800859F0: jal         0x80097C34
    // 0x800859F4: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    filename_decompress(rdram, ctx);
        goto after_2;
    // 0x800859F4: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    after_2:
    // 0x800859F8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800859FC: lw          $a2, 0x2390($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2390);
    // 0x80085A00: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80085A04: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x80085A08: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x80085A0C: beq         $t8, $zero, L_80085A38
    if (ctx->r24 == 0) {
        // 0x80085A10: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80085A38;
    }
    // 0x80085A10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085A14: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x80085A18: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x80085A1C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80085A20:
    // 0x80085A20: sb          $a0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r4;
    // 0x80085A24: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x80085A28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80085A2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80085A30: bne         $a0, $zero, L_80085A20
    if (ctx->r4 != 0) {
        // 0x80085A34: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80085A20;
    }
    // 0x80085A34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80085A38:
    // 0x80085A38: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80085A3C: addiu       $t9, $sp, 0x50
    ctx->r25 = ADD32(ctx->r29, 0X50);
    // 0x80085A40: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80085A44: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x80085A48: addiu       $t4, $zero, 0x29
    ctx->r12 = ADD32(0, 0X29);
    // 0x80085A4C: sb          $t4, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r12;
    // 0x80085A50: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x80085A54: sb          $t3, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r11;
    // 0x80085A58: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    // 0x80085A5C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80085A60: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x80085A64: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80085A68: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80085A6C: lw          $t9, 0x158($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X158);
    // 0x80085A70: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80085A74: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x80085A78: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x80085A7C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80085A80: div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // 0x80085A84: bne         $a0, $zero, L_80085A90
    if (ctx->r4 != 0) {
        // 0x80085A88: nop
    
            goto L_80085A90;
    }
    // 0x80085A88: nop

    // 0x80085A8C: break       7
    do_break(2148031116);
L_80085A90:
    // 0x80085A90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80085A94: bne         $a0, $at, L_80085AA8
    if (ctx->r4 != ctx->r1) {
        // 0x80085A98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80085AA8;
    }
    // 0x80085A98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80085A9C: bne         $v1, $at, L_80085AA8
    if (ctx->r3 != ctx->r1) {
        // 0x80085AA0: nop
    
            goto L_80085AA8;
    }
    // 0x80085AA0: nop

    // 0x80085AA4: break       6
    do_break(2148031140);
L_80085AA8:
    // 0x80085AA8: mflo        $t2
    ctx->r10 = lo;
    // 0x80085AAC: mfhi        $t3
    ctx->r11 = hi;
    // 0x80085AB0: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x80085AB4: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x80085AB8: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x80085ABC: nop

    // 0x80085AC0: beq         $t4, $zero, L_80085C9C
    if (ctx->r12 == 0) {
        // 0x80085AC4: lw          $a1, 0x84($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X84);
            goto L_80085C9C;
    }
    // 0x80085AC4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085AC8: b           L_80085C98
    // 0x80085ACC: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
        goto L_80085C98;
    // 0x80085ACC: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_80085AD0:
    // 0x80085AD0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80085AD4: addiu       $t5, $t5, 0x1A0
    ctx->r13 = ADD32(ctx->r13, 0X1A0);
    // 0x80085AD8: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80085ADC: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80085AE0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80085AE4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80085AE8: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x80085AEC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80085AF0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085AF4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80085AF8: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x80085AFC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80085B00: lw          $t4, 0x158($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X158);
    // 0x80085B04: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085B08: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x80085B0C: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x80085B10: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x80085B14: b           L_80085C98
    // 0x80085B18: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
        goto L_80085C98;
    // 0x80085B18: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
L_80085B1C:
    // 0x80085B1C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80085B20: addiu       $t6, $t6, 0x1B0
    ctx->r14 = ADD32(ctx->r14, 0X1B0);
    // 0x80085B24: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085B28: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x80085B2C: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x80085B30: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80085B34: lw          $t7, 0x1E4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1E4);
    // 0x80085B38: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80085B3C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085B40: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80085B44: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80085B48: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80085B4C: lw          $t2, 0x158($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X158);
    // 0x80085B50: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085B54: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x80085B58: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x80085B5C: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x80085B60: b           L_80085C98
    // 0x80085B64: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
        goto L_80085C98;
    // 0x80085B64: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
L_80085B68:
    // 0x80085B68: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80085B6C: addiu       $t3, $t3, 0x1C0
    ctx->r11 = ADD32(ctx->r11, 0X1C0);
    // 0x80085B70: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x80085B74: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80085B78: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80085B7C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80085B80: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x80085B84: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80085B88: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085B8C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80085B90: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80085B94: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80085B98: lw          $t9, 0x158($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X158);
    // 0x80085B9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085BA0: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x80085BA4: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x80085BA8: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x80085BAC: b           L_80085C98
    // 0x80085BB0: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
        goto L_80085C98;
    // 0x80085BB0: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
L_80085BB4:
    // 0x80085BB4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80085BB8: addiu       $t2, $t2, 0x1D0
    ctx->r10 = ADD32(ctx->r10, 0X1D0);
    // 0x80085BBC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085BC0: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x80085BC4: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80085BC8: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80085BCC: lw          $t4, 0x1E8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1E8);
    // 0x80085BD0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80085BD4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085BD8: addu        $t5, $v1, $t6
    ctx->r13 = ADD32(ctx->r3, ctx->r14);
    // 0x80085BDC: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80085BE0: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80085BE4: lw          $t7, 0x158($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X158);
    // 0x80085BE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085BEC: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80085BF0: lw          $t0, 0x6C00($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C00);
    // 0x80085BF4: lw          $t1, 0x4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4C);
    // 0x80085BF8: b           L_80085C98
    // 0x80085BFC: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
        goto L_80085C98;
    // 0x80085BFC: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
L_80085C00:
    // 0x80085C00: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80085C04: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80085C08: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x80085C0C: addiu       $t8, $t8, 0x1B0
    ctx->r24 = ADD32(ctx->r24, 0X1B0);
    // 0x80085C10: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x80085C14: lw          $t2, 0x1EC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1EC);
    // 0x80085C18: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085C1C: lw          $t0, 0x6C04($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C04);
    // 0x80085C20: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80085C24: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80085C28: b           L_80085C98
    // 0x80085C2C: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
        goto L_80085C98;
    // 0x80085C2C: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
L_80085C30:
    // 0x80085C30: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80085C34: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085C38: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x80085C3C: addiu       $t3, $t3, 0x190
    ctx->r11 = ADD32(ctx->r11, 0X190);
    // 0x80085C40: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x80085C44: lw          $t4, 0x2D4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2D4);
    // 0x80085C48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085C4C: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80085C50: lw          $t6, 0x1DC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1DC);
    // 0x80085C54: lw          $t0, 0x6BFC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6BFC);
    // 0x80085C58: lui         $t1, 0xB0E0
    ctx->r9 = S32(0XB0E0 << 16);
    // 0x80085C5C: ori         $t1, $t1, 0xC0FF
    ctx->r9 = ctx->r9 | 0XC0FF;
    // 0x80085C60: b           L_80085C98
    // 0x80085C64: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
        goto L_80085C98;
    // 0x80085C64: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
L_80085C68:
    // 0x80085C68: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80085C6C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80085C70: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x80085C74: addiu       $t5, $t5, 0x1E0
    ctx->r13 = ADD32(ctx->r13, 0X1E0);
    // 0x80085C78: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80085C7C: lw          $t8, 0x144($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X144);
    // 0x80085C80: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80085C84: lui         $t1, 0x8080
    ctx->r9 = S32(0X8080 << 16);
    // 0x80085C88: lw          $t0, 0x6C04($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C04);
    // 0x80085C8C: ori         $t1, $t1, 0x80FF
    ctx->r9 = ctx->r9 | 0X80FF;
    // 0x80085C90: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80085C94: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
L_80085C98:
    // 0x80085C98: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
L_80085C9C:
    // 0x80085C9C: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x80085CA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085CA4: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x80085CA8: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80085CAC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80085CB0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80085CB4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80085CB8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80085CBC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80085CC0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085CC4: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    // 0x80085CC8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80085CCC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80085CD0: addiu       $a1, $a1, -0xA0
    ctx->r5 = ADD32(ctx->r5, -0XA0);
    // 0x80085CD4: jal         0x800809D0
    // 0x80085CD8: subu        $a2, $t2, $t9
    ctx->r6 = SUB32(ctx->r10, ctx->r25);
    func_80080580(rdram, ctx);
        goto after_3;
    // 0x80085CD8: subu        $a2, $t2, $t9
    ctx->r6 = SUB32(ctx->r10, ctx->r25);
    after_3:
    // 0x80085CDC: lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // 0x80085CE0: lw          $v1, 0x300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X300);
    // 0x80085CE4: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x80085CE8: bne         $v1, $zero, L_80085CF4
    if (ctx->r3 != 0) {
        // 0x80085CEC: addiu       $t7, $t5, 0xC
        ctx->r15 = ADD32(ctx->r13, 0XC);
            goto L_80085CF4;
    }
    // 0x80085CEC: addiu       $t7, $t5, 0xC
    ctx->r15 = ADD32(ctx->r13, 0XC);
    // 0x80085CF0: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
L_80085CF4:
    // 0x80085CF4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80085CF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085CFC: beq         $v0, $at, L_80085D38
    if (ctx->r2 == ctx->r1) {
        // 0x80085D00: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80085D38;
    }
    // 0x80085D00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80085D04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80085D08: bne         $v0, $at, L_80085E4C
    if (ctx->r2 != ctx->r1) {
        // 0x80085D0C: lw          $t2, 0x68($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X68);
            goto L_80085E4C;
    }
    // 0x80085D0C: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80085D10: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
    // 0x80085D14: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80085D18: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80085D1C: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x80085D20: lw          $t9, 0x6AD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6AD0);
    // 0x80085D24: nop

    // 0x80085D28: lbu         $t3, 0x4B($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X4B);
    // 0x80085D2C: nop

    // 0x80085D30: bne         $t3, $zero, L_80085E4C
    if (ctx->r11 != 0) {
        // 0x80085D34: lw          $t2, 0x68($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X68);
            goto L_80085E4C;
    }
    // 0x80085D34: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
L_80085D38:
    // 0x80085D38: bne         $v1, $zero, L_80085D48
    if (ctx->r3 != 0) {
        // 0x80085D3C: addiu       $a1, $zero, 0x78
        ctx->r5 = ADD32(0, 0X78);
            goto L_80085D48;
    }
    // 0x80085D3C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80085D40: b           L_80085D48
    // 0x80085D44: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
        goto L_80085D48;
    // 0x80085D44: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
L_80085D48:
    // 0x80085D48: jal         0x80068748
    // 0x80085D4C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_4;
    // 0x80085D4C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    after_4:
    // 0x80085D50: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x80085D54: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80085D58: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80085D5C: subu        $v0, $a1, $t4
    ctx->r2 = SUB32(ctx->r5, ctx->r12);
    // 0x80085D60: addiu       $t6, $v0, -0x31
    ctx->r14 = ADD32(ctx->r2, -0X31);
    // 0x80085D64: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80085D68: addiu       $v1, $v1, -0x324
    ctx->r3 = ADD32(ctx->r3, -0X324);
    // 0x80085D6C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80085D70: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80085D74: addiu       $t8, $v0, -0x18
    ctx->r24 = ADD32(ctx->r2, -0X18);
    // 0x80085D78: swc1        $f6, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f6.u32l;
    // 0x80085D7C: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80085D80: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80085D84: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80085D88: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80085D8C: sll         $t7, $s0, 5
    ctx->r15 = S32(ctx->r16 << 5);
    // 0x80085D90: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x80085D94: swc1        $f10, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f10.u32l;
    // 0x80085D98: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80085D9C: jal         0x8007C36C
    // 0x80085DA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_5;
    // 0x80085DA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80085DA4: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x80085DA8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80085DAC: addiu       $t4, $t3, -0x85
    ctx->r12 = ADD32(ctx->r11, -0X85);
    // 0x80085DB0: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80085DB4: addiu       $v0, $v0, -0x324
    ctx->r2 = ADD32(ctx->r2, -0X324);
    // 0x80085DB8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80085DBC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80085DC0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80085DC4: swc1        $f18, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f18.u32l;
    // 0x80085DC8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80085DCC: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80085DD0: jal         0x8009CFA4
    // 0x80085DD4: sh          $t5, 0x58($t7)
    MEM_H(0X58, ctx->r15) = ctx->r13;
    menu_element_render(rdram, ctx);
        goto after_6;
    // 0x80085DD4: sh          $t5, 0x58($t7)
    MEM_H(0X58, ctx->r15) = ctx->r13;
    after_6:
    // 0x80085DD8: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x80085DDC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80085DE0: addiu       $t2, $t8, -0x7D
    ctx->r10 = ADD32(ctx->r24, -0X7D);
    // 0x80085DE4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80085DE8: addiu       $v0, $v0, -0x324
    ctx->r2 = ADD32(ctx->r2, -0X324);
    // 0x80085DEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80085DF0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80085DF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80085DF8: swc1        $f6, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->f6.u32l;
    // 0x80085DFC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80085E00: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80085E04: jal         0x8009CFA4
    // 0x80085E08: sh          $t3, 0x58($t4)
    MEM_H(0X58, ctx->r12) = ctx->r11;
    menu_element_render(rdram, ctx);
        goto after_7;
    // 0x80085E08: sh          $t3, 0x58($t4)
    MEM_H(0X58, ctx->r12) = ctx->r11;
    after_7:
    // 0x80085E0C: jal         0x8007C36C
    // 0x80085E10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_8;
    // 0x80085E10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80085E14: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x80085E18: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80085E1C: addiu       $t5, $t6, -0x80
    ctx->r13 = ADD32(ctx->r14, -0X80);
    // 0x80085E20: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80085E24: lw          $t7, -0x324($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X324);
    // 0x80085E28: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80085E2C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80085E30: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    // 0x80085E34: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80085E38: jal         0x8009CFA4
    // 0x80085E3C: nop

    menu_element_render(rdram, ctx);
        goto after_9;
    // 0x80085E3C: nop

    after_9:
    // 0x80085E40: jal         0x80068748
    // 0x80085E44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_10;
    // 0x80085E44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80085E48: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
L_80085E4C:
    // 0x80085E4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085E50: beq         $t2, $zero, L_80085E90
    if (ctx->r10 == 0) {
        // 0x80085E54: addiu       $a0, $a0, 0x693C
        ctx->r4 = ADD32(ctx->r4, 0X693C);
            goto L_80085E90;
    }
    // 0x80085E54: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085E58: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80085E5C: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80085E60: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80085E64: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80085E68: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80085E6C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80085E70: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80085E74: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80085E78: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80085E7C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80085E80: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80085E84: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    // 0x80085E88: jal         0x80078F08
    // 0x80085E8C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    texrect_draw(rdram, ctx);
        goto after_11;
    // 0x80085E8C: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    after_11:
L_80085E90:
    // 0x80085E90: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80085E94: nop

    // 0x80085E98: beq         $t5, $zero, L_80085F34
    if (ctx->r13 == 0) {
        // 0x80085E9C: lw          $t3, 0x64($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X64);
            goto L_80085F34;
    }
    // 0x80085E9C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80085EA0: jal         0x800C484C
    // 0x80085EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_12;
    // 0x80085EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x80085EA8: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80085EAC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80085EB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80085EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085EB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085EBC: jal         0x800C48E4
    // 0x80085EC0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x80085EC0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_13:
    // 0x80085EC4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085EC8: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085ECC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085ED0: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80085ED4: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80085ED8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80085EDC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085EE0: addiu       $a1, $a1, 0x51
    ctx->r5 = ADD32(ctx->r5, 0X51);
    // 0x80085EE4: jal         0x800C49A0
    // 0x80085EE8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    draw_text(rdram, ctx);
        goto after_14;
    // 0x80085EE8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_14:
    // 0x80085EEC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80085EF0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80085EF4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80085EF8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80085EFC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80085F00: jal         0x800C48E4
    // 0x80085F04: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x80085F04: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_15:
    // 0x80085F08: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085F0C: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085F10: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085F14: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80085F18: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80085F1C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80085F20: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085F24: addiu       $a1, $a1, 0x4F
    ctx->r5 = ADD32(ctx->r5, 0X4F);
    // 0x80085F28: jal         0x800C49A0
    // 0x80085F2C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    draw_text(rdram, ctx);
        goto after_16;
    // 0x80085F2C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_16:
    // 0x80085F30: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
L_80085F34:
    // 0x80085F34: lw          $s0, 0x84($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X84);
    // 0x80085F38: beq         $t3, $zero, L_80085FCC
    if (ctx->r11 == 0) {
        // 0x80085F3C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80085FCC;
    }
    // 0x80085F3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80085F40: jal         0x800C484C
    // 0x80085F44: addiu       $s0, $s0, 0x51
    ctx->r16 = ADD32(ctx->r16, 0X51);
    set_text_font(rdram, ctx);
        goto after_17;
    // 0x80085F44: addiu       $s0, $s0, 0x51
    ctx->r16 = ADD32(ctx->r16, 0X51);
    after_17:
    // 0x80085F48: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80085F4C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80085F50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80085F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80085F58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80085F5C: jal         0x800C48E4
    // 0x80085F60: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x80085F60: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_18:
    // 0x80085F64: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085F68: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085F6C: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80085F70: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80085F74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80085F78: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085F7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80085F80: jal         0x800C49A0
    // 0x80085F84: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    draw_text(rdram, ctx);
        goto after_19;
    // 0x80085F84: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    after_19:
    // 0x80085F88: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80085F8C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80085F90: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80085F94: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80085F98: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80085F9C: jal         0x800C48E4
    // 0x80085FA0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_20;
    // 0x80085FA0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_20:
    // 0x80085FA4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80085FA8: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x80085FAC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085FB0: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80085FB4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80085FB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80085FBC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80085FC0: addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // 0x80085FC4: jal         0x800C49A0
    // 0x80085FC8: addiu       $a2, $a2, 0x2F
    ctx->r6 = ADD32(ctx->r6, 0X2F);
    draw_text(rdram, ctx);
        goto after_21;
    // 0x80085FC8: addiu       $a2, $a2, 0x2F
    ctx->r6 = ADD32(ctx->r6, 0X2F);
    after_21:
L_80085FCC:
    // 0x80085FCC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80085FD0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80085FD4: jr          $ra
    // 0x80085FD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80085FD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void material_set_blinking_lights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BEAC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8007BEB0: beq         $a3, $zero, L_8007BEE8
    if (ctx->r7 == 0) {
        // 0x8007BEB4: sw          $a2, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r6;
            goto L_8007BEE8;
    }
    // 0x8007BEB4: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8007BEB8: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x8007BEBC: nop

    // 0x8007BEC0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8007BEC4: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8007BEC8: beq         $at, $zero, L_8007BEE8
    if (ctx->r1 == 0) {
        // 0x8007BECC: nop
    
            goto L_8007BEE8;
    }
    // 0x8007BECC: nop

    // 0x8007BED0: lh          $t9, 0x16($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X16);
    // 0x8007BED4: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8007BED8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007BEDC: mflo        $t6
    ctx->r14 = lo;
    // 0x8007BEE0: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x8007BEE4: nop

L_8007BEE8:
    // 0x8007BEE8: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x8007BEEC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8007BEF0: bne         $t7, $at, L_8007C0C0
    if (ctx->r15 != ctx->r1) {
        // 0x8007BEF4: lui         $a2, 0xB700
        ctx->r6 = S32(0XB700 << 16);
            goto L_8007C0C0;
    }
    // 0x8007BEF4: lui         $a2, 0xB700
    ctx->r6 = S32(0XB700 << 16);
    // 0x8007BEF8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BEFC: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007BF00: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BF04: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BF08: addu        $t9, $a1, $t1
    ctx->r25 = ADD32(ctx->r5, ctx->r9);
    // 0x8007BF0C: lui         $a3, 0xFD10
    ctx->r7 = S32(0XFD10 << 16);
    // 0x8007BF10: addiu       $t6, $t9, 0x20
    ctx->r14 = ADD32(ctx->r25, 0X20);
    // 0x8007BF14: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007BF18: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007BF1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF20: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x8007BF24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BF28: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BF2C: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007BF30: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8007BF34: ori         $t9, $t9, 0x60
    ctx->r25 = ctx->r25 | 0X60;
    // 0x8007BF38: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007BF3C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BF40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF44: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8007BF48: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BF4C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BF50: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BF54: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007BF58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF5C: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8007BF60: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007BF64: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BF68: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8007BF6C: ori         $t8, $t8, 0xF080
    ctx->r24 = ctx->r24 | 0XF080;
    // 0x8007BF70: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007BF74: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007BF78: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF7C: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8007BF80: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BF84: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BF88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BF8C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007BF90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF94: lui         $t9, 0x101
    ctx->r25 = S32(0X101 << 16);
    // 0x8007BF98: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8007BF9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BFA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BFA4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8007BFA8: lui         $t7, 0xF510
    ctx->r15 = S32(0XF510 << 16);
    // 0x8007BFAC: ori         $t7, $t7, 0x2100
    ctx->r15 = ctx->r15 | 0X2100;
    // 0x8007BFB0: ori         $t9, $t9, 0x60
    ctx->r25 = ctx->r25 | 0X60;
    // 0x8007BFB4: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8007BFB8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8007BFBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BFC0: lui         $t9, 0x10F
    ctx->r25 = S32(0X10F << 16);
    // 0x8007BFC4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8007BFC8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007BFCC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007BFD0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007BFD4: ori         $t9, $t9, 0xC03C
    ctx->r25 = ctx->r25 | 0XC03C;
    // 0x8007BFD8: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x8007BFDC: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8007BFE0: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8007BFE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BFE8: addu        $t6, $a1, $t1
    ctx->r14 = ADD32(ctx->r5, ctx->r9);
    // 0x8007BFEC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BFF0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BFF4: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007BFF8: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8007BFFC: addiu       $t9, $t6, 0x820
    ctx->r25 = ADD32(ctx->r14, 0X820);
    // 0x8007C000: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007C004: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C008: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x8007C00C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C010: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C014: ori         $t6, $t6, 0x60
    ctx->r14 = ctx->r14 | 0X60;
    // 0x8007C018: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007C01C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007C020: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007C024: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C028: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8007C02C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C030: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C034: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C038: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007C03C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C040: ori         $t6, $t6, 0xF080
    ctx->r14 = ctx->r14 | 0XF080;
    // 0x8007C044: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8007C048: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C04C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C050: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8007C054: nop

    // 0x8007C058: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8007C05C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8007C060: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C064: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007C068: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007C06C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C070: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C074: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8007C078: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8007C07C: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8007C080: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8007C084: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C088: ori         $t9, $t9, 0x60
    ctx->r25 = ctx->r25 | 0X60;
    // 0x8007C08C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C090: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C094: ori         $t8, $t8, 0x2000
    ctx->r24 = ctx->r24 | 0X2000;
    // 0x8007C098: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007C09C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007C0A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C0A4: lui         $t6, 0xF
    ctx->r14 = S32(0XF << 16);
    // 0x8007C0A8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C0AC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C0B0: ori         $t6, $t6, 0xC03C
    ctx->r14 = ctx->r14 | 0XC03C;
    // 0x8007C0B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007C0B8: b           L_8007C2A0
    // 0x8007C0BC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8007C2A0;
    // 0x8007C0BC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8007C0C0:
    // 0x8007C0C0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C0C4: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007C0C8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007C0CC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007C0D0: addu        $t9, $a1, $t1
    ctx->r25 = ADD32(ctx->r5, ctx->r9);
    // 0x8007C0D4: lui         $a3, 0xFD10
    ctx->r7 = S32(0XFD10 << 16);
    // 0x8007C0D8: addiu       $t7, $t9, 0x20
    ctx->r15 = ADD32(ctx->r25, 0X20);
    // 0x8007C0DC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007C0E0: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007C0E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C0E8: lui         $t9, 0x701
    ctx->r25 = S32(0X701 << 16);
    // 0x8007C0EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C0F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C0F4: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007C0F8: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8007C0FC: ori         $t9, $t9, 0x4050
    ctx->r25 = ctx->r25 | 0X4050;
    // 0x8007C100: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007C104: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007C108: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C10C: lui         $t2, 0xE600
    ctx->r10 = S32(0XE600 << 16);
    // 0x8007C110: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C114: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C118: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C11C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007C120: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C124: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8007C128: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C12C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C130: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8007C134: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007C138: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8007C13C: ori         $t8, $t8, 0xF100
    ctx->r24 = ctx->r24 | 0XF100;
    // 0x8007C140: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007C144: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C148: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8007C14C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007C150: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C154: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C158: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C15C: lui         $t8, 0xF510
    ctx->r24 = S32(0XF510 << 16);
    // 0x8007C160: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8007C164: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8007C168: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C16C: lui         $t7, 0x101
    ctx->r15 = S32(0X101 << 16);
    // 0x8007C170: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007C174: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C178: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C17C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8007C180: ori         $t7, $t7, 0x4050
    ctx->r15 = ctx->r15 | 0X4050;
    // 0x8007C184: ori         $t8, $t8, 0x1100
    ctx->r24 = ctx->r24 | 0X1100;
    // 0x8007C188: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007C18C: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8007C190: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C194: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x8007C198: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8007C19C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C1A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C1A4: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x8007C1A8: lui         $t7, 0x107
    ctx->r15 = S32(0X107 << 16);
    // 0x8007C1AC: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8007C1B0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8007C1B4: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x8007C1B8: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8007C1BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C1C0: addu        $t8, $a1, $t1
    ctx->r24 = ADD32(ctx->r5, ctx->r9);
    // 0x8007C1C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C1C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C1CC: addiu       $t7, $t8, 0x820
    ctx->r15 = ADD32(ctx->r24, 0X820);
    // 0x8007C1D0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007C1D4: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8007C1D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C1DC: lui         $t8, 0x701
    ctx->r24 = S32(0X701 << 16);
    // 0x8007C1E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C1E4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C1E8: ori         $t8, $t8, 0x4050
    ctx->r24 = ctx->r24 | 0X4050;
    // 0x8007C1EC: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8007C1F0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007C1F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007C1F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C1FC: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8007C200: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C204: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C208: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C20C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007C210: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C214: ori         $t8, $t8, 0xF100
    ctx->r24 = ctx->r24 | 0XF100;
    // 0x8007C218: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8007C21C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C220: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C224: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007C228: nop

    // 0x8007C22C: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8007C230: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8007C234: nop

    // 0x8007C238: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8007C23C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C240: nop

    // 0x8007C244: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x8007C248: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C24C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C250: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8007C254: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x8007C258: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8007C25C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007C260: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8007C264: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8007C268: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C26C: ori         $t6, $t6, 0x4050
    ctx->r14 = ctx->r14 | 0X4050;
    // 0x8007C270: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C274: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C278: ori         $t9, $t9, 0x1000
    ctx->r25 = ctx->r25 | 0X1000;
    // 0x8007C27C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007C280: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007C284: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C288: lui         $t7, 0x7
    ctx->r15 = S32(0X7 << 16);
    // 0x8007C28C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007C290: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007C294: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x8007C298: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007C29C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8007C2A0:
    // 0x8007C2A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C2A8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C2AC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C2B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C2B4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007C2B8: sw          $zero, 0x691C($at)
    MEM_W(0X691C, ctx->r1) = 0;
    // 0x8007C2BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C2C0: andi        $t6, $t5, 0x1F
    ctx->r14 = ctx->r13 & 0X1F;
    // 0x8007C2C4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007C2C8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007C2CC: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8007C2D0: andi        $t9, $t6, 0x2
    ctx->r25 = ctx->r14 & 0X2;
    // 0x8007C2D4: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x8007C2D8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007C2DC: beq         $t9, $zero, L_8007C300
    if (ctx->r25 == 0) {
        // 0x8007C2E0: sw          $a2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r6;
            goto L_8007C300;
    }
    // 0x8007C2E0: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8007C2E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C2E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007C2EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007C2F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007C2F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007C2F8: b           L_8007C31C
    // 0x8007C2FC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_8007C31C;
    // 0x8007C2FC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_8007C300:
    // 0x8007C300: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C304: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8007C308: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C30C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C310: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C314: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007C318: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007C31C:
    // 0x8007C31C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007C320: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C324: sh          $t8, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r24;
    // 0x8007C328: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C32C: sw          $zero, 0x6914($at)
    MEM_W(0X6914, ctx->r1) = 0;
    // 0x8007C330: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C334: lui         $t9, 0x702
    ctx->r25 = S32(0X702 << 16);
    // 0x8007C338: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007C33C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007C340: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007C344: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x8007C348: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C34C: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8007C350: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x8007C354: addiu       $t7, $t7, -0x8D8
    ctx->r15 = ADD32(ctx->r15, -0X8D8);
    // 0x8007C358: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007C35C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8007C360: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8007C364: jr          $ra
    // 0x8007C368: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    return;
    // 0x8007C368: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void minimap_opacity_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB708: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AB70C: lbu         $t6, 0x774B($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X774B);
    // 0x800AB710: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB714: sb          $t6, 0x7290($at)
    MEM_B(0X7290, ctx->r1) = ctx->r14;
    // 0x800AB718: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB71C: jr          $ra
    // 0x800AB720: sb          $a0, 0x7293($at)
    MEM_B(0X7293, ctx->r1) = ctx->r4;
    return;
    // 0x800AB720: sb          $a0, 0x7293($at)
    MEM_B(0X7293, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void get_inside_segment_count_xyz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A178: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8002A17C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002A180: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002A184: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8002A188: lh          $s0, 0x2A($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X2A);
    // 0x8002A18C: lh          $s1, 0x2E($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X2E);
    // 0x8002A190: lh          $s2, 0x32($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X32);
    // 0x8002A194: lw          $t0, -0x3178($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3178);
    // 0x8002A198: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002A19C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002A1A0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8002A1A4: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002A1A8: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
    // 0x8002A1AC: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8002A1B0: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8002A1B4: addiu       $a1, $t7, -0x4
    ctx->r5 = ADD32(ctx->r15, -0X4);
    // 0x8002A1B8: addiu       $a2, $t9, -0x4
    ctx->r6 = ADD32(ctx->r25, -0X4);
    // 0x8002A1BC: addiu       $a3, $t4, -0x4
    ctx->r7 = ADD32(ctx->r12, -0X4);
    // 0x8002A1C0: lh          $t1, 0x1A($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X1A);
    // 0x8002A1C4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8002A1C8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8002A1CC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8002A1D0: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x8002A1D4: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8002A1D8: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x8002A1DC: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x8002A1E0: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8002A1E4: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x8002A1E8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8002A1EC: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8002A1F0: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002A1F4: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002A1F8: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8002A1FC: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002A200: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002A204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002A208: blez        $t1, L_8002A2C0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8002A20C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002A2C0;
    }
    // 0x8002A20C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002A210: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8002A214:
    // 0x8002A214: lw          $t3, 0x8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X8);
    // 0x8002A218: nop

    // 0x8002A21C: addu        $a0, $t3, $t2
    ctx->r4 = ADD32(ctx->r11, ctx->r10);
    // 0x8002A220: lh          $t4, 0x6($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X6);
    // 0x8002A224: nop

    // 0x8002A228: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002A22C: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A230: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A230: nop

    // 0x8002A234: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x8002A238: nop

    // 0x8002A23C: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002A240: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A244: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A244: nop

    // 0x8002A248: lh          $t6, 0xA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA);
    // 0x8002A24C: nop

    // 0x8002A250: slt         $at, $t6, $a3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8002A254: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A258: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A258: nop

    // 0x8002A25C: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x8002A260: nop

    // 0x8002A264: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002A268: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A26C: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A26C: nop

    // 0x8002A270: lh          $t8, 0x8($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8);
    // 0x8002A274: nop

    // 0x8002A278: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002A27C: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A280: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A280: nop

    // 0x8002A284: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8002A288: nop

    // 0x8002A28C: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002A290: bne         $at, $zero, L_8002A2B0
    if (ctx->r1 != 0) {
        // 0x8002A294: nop
    
            goto L_8002A2B0;
    }
    // 0x8002A294: nop

    // 0x8002A298: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8002A29C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8002A2A0: lw          $t0, -0x3178($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3178);
    // 0x8002A2A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002A2A8: lh          $t1, 0x1A($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X1A);
    // 0x8002A2AC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8002A2B0:
    // 0x8002A2B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A2B4: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002A2B8: bne         $at, $zero, L_8002A214
    if (ctx->r1 != 0) {
        // 0x8002A2BC: addiu       $t2, $t2, 0xC
        ctx->r10 = ADD32(ctx->r10, 0XC);
            goto L_8002A214;
    }
    // 0x8002A2BC: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
L_8002A2C0:
    // 0x8002A2C0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002A2C4: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002A2C8: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8002A2CC: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8002A2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A2D4: jr          $ra
    // 0x8002A2D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002A2D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void render_global_dialogue_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C566C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C5670: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5674: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5678: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C567C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C5680: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5684: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C5688: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C568C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5690: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C5694: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5698: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C569C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C56A0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C56A4: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x800C56A8: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x800C56AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C56B0: jal         0x800C56C8
    // 0x800C56B4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    render_dialogue_text(rdram, ctx);
        goto after_0;
    // 0x800C56B4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x800C56B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C56BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C56C0: jr          $ra
    // 0x800C56C4: nop

    return;
    // 0x800C56C4: nop

;}
RECOMP_FUNC void fb_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AC38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007AC3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007AC40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007AC44: addiu       $t6, $t6, 0x6860
    ctx->r14 = ADD32(ctx->r14, 0X6860);
    // 0x8007AC48: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x8007AC4C: addu        $s0, $a1, $t6
    ctx->r16 = ADD32(ctx->r5, ctx->r14);
    // 0x8007AC50: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8007AC54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007AC58: beq         $a2, $zero, L_8007AC7C
    if (ctx->r6 == 0) {
        // 0x8007AC5C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8007AC7C;
    }
    // 0x8007AC5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007AC60: jal         0x80071778
    // 0x8007AC64: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    mempool_locked_unset(rdram, ctx);
        goto after_0;
    // 0x8007AC64: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007AC68: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007AC6C: jal         0x80071380
    // 0x8007AC70: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x8007AC70: nop

    after_1:
    // 0x8007AC74: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007AC78: nop

L_8007AC7C:
    // 0x8007AC7C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007AC80: lw          $v0, 0x686C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X686C);
    // 0x8007AC84: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007AC88: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x8007AC8C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8007AC90: addiu       $t0, $t0, -0x1304
    ctx->r8 = ADD32(ctx->r8, -0X1304);
    // 0x8007AC94: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x8007AC98: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007AC9C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007ACA0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8007ACA4: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x8007ACA8: addiu       $t7, $t7, 0x6850
    ctx->r15 = ADD32(ctx->r15, 0X6850);
    // 0x8007ACAC: addiu       $t2, $t2, 0x6858
    ctx->r10 = ADD32(ctx->r10, 0X6858);
    // 0x8007ACB0: addu        $a2, $a1, $t7
    ctx->r6 = ADD32(ctx->r5, ctx->r15);
    // 0x8007ACB4: addu        $a3, $a1, $t2
    ctx->r7 = ADD32(ctx->r5, ctx->r10);
    // 0x8007ACB8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8007ACBC: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x8007ACC0: bne         $at, $zero, L_8007AD28
    if (ctx->r1 != 0) {
        // 0x8007ACC4: sw          $t3, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r11;
            goto L_8007AD28;
    }
    // 0x8007ACC4: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8007ACC8: lui         $a0, 0x9
    ctx->r4 = S32(0X9 << 16);
    // 0x8007ACCC: ori         $a0, $a0, 0x6030
    ctx->r4 = ctx->r4 | 0X6030;
    // 0x8007ACD0: jal         0x80070EDC
    // 0x8007ACD4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x8007ACD4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x8007ACD8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007ACDC: addiu       $v1, $v1, -0x1310
    ctx->r3 = ADD32(ctx->r3, -0X1310);
    // 0x8007ACE0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8007ACE4: addiu       $t4, $v0, 0x3F
    ctx->r12 = ADD32(ctx->r2, 0X3F);
    // 0x8007ACE8: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x8007ACEC: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8007ACF0: bne         $t6, $zero, L_8007ADB4
    if (ctx->r14 != 0) {
        // 0x8007ACF4: sw          $t5, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r13;
            goto L_8007ADB4;
    }
    // 0x8007ACF4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8007ACF8: lui         $a0, 0x9
    ctx->r4 = S32(0X9 << 16);
    // 0x8007ACFC: ori         $a0, $a0, 0x6030
    ctx->r4 = ctx->r4 | 0X6030;
    // 0x8007AD00: jal         0x80070EDC
    // 0x8007AD04: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8007AD04: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x8007AD08: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007AD0C: addiu       $v1, $v1, -0x1310
    ctx->r3 = ADD32(ctx->r3, -0X1310);
    // 0x8007AD10: addiu       $t8, $v0, 0x3F
    ctx->r24 = ADD32(ctx->r2, 0X3F);
    // 0x8007AD14: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x8007AD18: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8007AD1C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8007AD20: b           L_8007ADB4
    // 0x8007AD24: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_8007ADB4;
    // 0x8007AD24: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8007AD28:
    // 0x8007AD28: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8007AD2C: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8007AD30: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8007AD34: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AD38: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8007AD3C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8007AD40: mflo        $a0
    ctx->r4 = lo;
    // 0x8007AD44: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    // 0x8007AD48: jal         0x80070EDC
    // 0x8007AD4C: addiu       $a0, $t2, 0x30
    ctx->r4 = ADD32(ctx->r10, 0X30);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x8007AD4C: addiu       $a0, $t2, 0x30
    ctx->r4 = ADD32(ctx->r10, 0X30);
    after_4:
    // 0x8007AD50: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007AD54: addiu       $v1, $v1, -0x1310
    ctx->r3 = ADD32(ctx->r3, -0X1310);
    // 0x8007AD58: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8007AD5C: addiu       $t3, $v0, 0x3F
    ctx->r11 = ADD32(ctx->r2, 0X3F);
    // 0x8007AD60: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x8007AD64: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8007AD68: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8007AD6C: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8007AD70: bne         $t5, $zero, L_8007ADB4
    if (ctx->r13 != 0) {
        // 0x8007AD74: sw          $t4, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r12;
            goto L_8007ADB4;
    }
    // 0x8007AD74: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8007AD78: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8007AD7C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8007AD80: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8007AD84: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AD88: mflo        $a0
    ctx->r4 = lo;
    // 0x8007AD8C: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x8007AD90: jal         0x80070EDC
    // 0x8007AD94: addiu       $a0, $t8, 0x30
    ctx->r4 = ADD32(ctx->r24, 0X30);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8007AD94: addiu       $a0, $t8, 0x30
    ctx->r4 = ADD32(ctx->r24, 0X30);
    after_5:
    // 0x8007AD98: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007AD9C: addiu       $v1, $v1, -0x1310
    ctx->r3 = ADD32(ctx->r3, -0X1310);
    // 0x8007ADA0: addiu       $t0, $v0, 0x3F
    ctx->r8 = ADD32(ctx->r2, 0X3F);
    // 0x8007ADA4: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x8007ADA8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8007ADAC: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8007ADB0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8007ADB4:
    // 0x8007ADB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007ADB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007ADBC: jr          $ra
    // 0x8007ADC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007ADC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void postrace_viewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009522C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80095230: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80095234: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80095238: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8009523C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80095240: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80095244: jal         0x8006ECD0
    // 0x80095248: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80095248: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009524C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80095250: lw          $t6, -0x5C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C4);
    // 0x80095254: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80095258: bne         $t6, $at, L_80095274
    if (ctx->r14 != ctx->r1) {
        // 0x8009525C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80095274;
    }
    // 0x8009525C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80095260: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80095264: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80095268: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009526C: jal         0x8006816C
    // 0x80095270: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    mtx_ortho(rdram, ctx);
        goto after_1;
    // 0x80095270: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_1:
L_80095274:
    // 0x80095274: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80095278: jal         0x80066AD4
    // 0x8009527C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camDisableUserView(rdram, ctx);
        goto after_2;
    // 0x8009527C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80095280: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80095284: lw          $s3, 0x695C($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X695C);
    // 0x80095288: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009528C: sll         $t7, $s3, 3
    ctx->r15 = S32(ctx->r19 << 3);
    // 0x80095290: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80095294: bne         $at, $zero, L_800952A4
    if (ctx->r1 != 0) {
        // 0x80095298: or          $s3, $t7, $zero
        ctx->r19 = ctx->r15 | 0;
            goto L_800952A4;
    }
    // 0x80095298: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
    // 0x8009529C: addiu       $t8, $zero, 0x1FF
    ctx->r24 = ADD32(0, 0X1FF);
    // 0x800952A0: subu        $s3, $t8, $s3
    ctx->r19 = SUB32(ctx->r24, ctx->r19);
L_800952A4:
    // 0x800952A4: lw          $t9, 0x6980($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6980);
    // 0x800952A8: nop

    // 0x800952AC: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x800952B0: sltiu       $at, $t2, 0x6
    ctx->r1 = ctx->r10 < 0X6 ? 1 : 0;
    // 0x800952B4: beq         $at, $zero, L_80095A8C
    if (ctx->r1 == 0) {
        // 0x800952B8: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80095A8C;
    }
    // 0x800952B8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800952BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800952C0: addu        $at, $at, $t2
    gpr jr_addend_800952CC = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800952C4: lw          $t2, -0x7568($at)
    ctx->r10 = ADD32(ctx->r1, -0X7568);
    // 0x800952C8: nop

    // 0x800952CC: jr          $t2
    // 0x800952D0: nop

    switch (jr_addend_800952CC >> 2) {
        case 0: goto L_800952D4; break;
        case 1: goto L_800954B4; break;
        case 2: goto L_80095588; break;
        case 3: goto L_80095A8C; break;
        case 4: goto L_80095614; break;
        case 5: goto L_800956D0; break;
        default: switch_error(__func__, 0x800952CC, 0x800E8A98);
    }
    // 0x800952D0: nop

L_800952D4:
    // 0x800952D4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800952D8: lw          $s0, 0x7054($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7054);
    // 0x800952DC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800952E0: slti        $at, $s0, 0x3D
    ctx->r1 = SIGNED(ctx->r16) < 0X3D ? 1 : 0;
    // 0x800952E4: bne         $at, $zero, L_800952F0
    if (ctx->r1 != 0) {
        // 0x800952E8: addiu       $s1, $s1, 0x6A18
        ctx->r17 = ADD32(ctx->r17, 0X6A18);
            goto L_800952F0;
    }
    // 0x800952E8: addiu       $s1, $s1, 0x6A18
    ctx->r17 = ADD32(ctx->r17, 0X6A18);
    // 0x800952EC: addiu       $s0, $zero, 0x3C
    ctx->r16 = ADD32(0, 0X3C);
L_800952F0:
    // 0x800952F0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800952F4: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x800952F8: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x800952FC: div         $zero, $t3, $t1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r9)));
    // 0x80095300: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x80095304: bne         $t1, $zero, L_80095310
    if (ctx->r9 != 0) {
        // 0x80095308: nop
    
            goto L_80095310;
    }
    // 0x80095308: nop

    // 0x8009530C: break       7
    do_break(2148094732);
L_80095310:
    // 0x80095310: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80095314: bne         $t1, $at, L_80095328
    if (ctx->r9 != ctx->r1) {
        // 0x80095318: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80095328;
    }
    // 0x80095318: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8009531C: bne         $t3, $at, L_80095328
    if (ctx->r11 != ctx->r1) {
        // 0x80095320: nop
    
            goto L_80095328;
    }
    // 0x80095320: nop

    // 0x80095324: break       6
    do_break(2148094756);
L_80095328:
    // 0x80095328: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009532C: lw          $t7, 0x6A20($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A20);
    // 0x80095330: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80095334: mflo        $t4
    ctx->r12 = lo;
    // 0x80095338: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x8009533C: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80095340: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095344: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x80095348: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x8009534C: addiu       $t5, $zero, 0x140
    ctx->r13 = ADD32(0, 0X140);
    // 0x80095350: mflo        $t6
    ctx->r14 = lo;
    // 0x80095354: nop

    // 0x80095358: nop

    // 0x8009535C: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x80095360: bne         $v1, $zero, L_8009536C
    if (ctx->r3 != 0) {
        // 0x80095364: nop
    
            goto L_8009536C;
    }
    // 0x80095364: nop

    // 0x80095368: break       7
    do_break(2148094824);
L_8009536C:
    // 0x8009536C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80095370: bne         $v1, $at, L_80095384
    if (ctx->r3 != ctx->r1) {
        // 0x80095374: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80095384;
    }
    // 0x80095374: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095378: bne         $t6, $at, L_80095384
    if (ctx->r14 != ctx->r1) {
        // 0x8009537C: nop
    
            goto L_80095384;
    }
    // 0x8009537C: nop

    // 0x80095380: break       6
    do_break(2148094848);
L_80095384:
    // 0x80095384: mflo        $s2
    ctx->r18 = lo;
    // 0x80095388: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8009538C: nop

    // 0x80095390: div         $zero, $v0, $t1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r9)));
    // 0x80095394: bne         $t1, $zero, L_800953A0
    if (ctx->r9 != 0) {
        // 0x80095398: nop
    
            goto L_800953A0;
    }
    // 0x80095398: nop

    // 0x8009539C: break       7
    do_break(2148094876);
L_800953A0:
    // 0x800953A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800953A4: bne         $t1, $at, L_800953B8
    if (ctx->r9 != ctx->r1) {
        // 0x800953A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800953B8;
    }
    // 0x800953A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800953AC: bne         $v0, $at, L_800953B8
    if (ctx->r2 != ctx->r1) {
        // 0x800953B0: nop
    
            goto L_800953B8;
    }
    // 0x800953B0: nop

    // 0x800953B4: break       6
    do_break(2148094900);
L_800953B8:
    // 0x800953B8: mflo        $t8
    ctx->r24 = lo;
    // 0x800953BC: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x800953C0: nop

    // 0x800953C4: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800953C8: mflo        $t2
    ctx->r10 = lo;
    // 0x800953CC: nop

    // 0x800953D0: nop

    // 0x800953D4: div         $zero, $t2, $v1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r3)));
    // 0x800953D8: bne         $v1, $zero, L_800953E4
    if (ctx->r3 != 0) {
        // 0x800953DC: nop
    
            goto L_800953E4;
    }
    // 0x800953DC: nop

    // 0x800953E0: break       7
    do_break(2148094944);
L_800953E4:
    // 0x800953E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800953E8: bne         $v1, $at, L_800953FC
    if (ctx->r3 != ctx->r1) {
        // 0x800953EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800953FC;
    }
    // 0x800953EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800953F0: bne         $t2, $at, L_800953FC
    if (ctx->r10 != ctx->r1) {
        // 0x800953F4: nop
    
            goto L_800953FC;
    }
    // 0x800953F4: nop

    // 0x800953F8: break       6
    do_break(2148094968);
L_800953FC:
    // 0x800953FC: mflo        $t3
    ctx->r11 = lo;
    // 0x80095400: subu        $t0, $t7, $t3
    ctx->r8 = SUB32(ctx->r15, ctx->r11);
    // 0x80095404: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80095408: div         $zero, $t4, $v1
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r3)));
    // 0x8009540C: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x80095410: bne         $v1, $zero, L_8009541C
    if (ctx->r3 != 0) {
        // 0x80095414: nop
    
            goto L_8009541C;
    }
    // 0x80095414: nop

    // 0x80095418: break       7
    do_break(2148095000);
L_8009541C:
    // 0x8009541C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80095420: bne         $v1, $at, L_80095434
    if (ctx->r3 != ctx->r1) {
        // 0x80095424: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80095434;
    }
    // 0x80095424: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80095428: bne         $t4, $at, L_80095434
    if (ctx->r12 != ctx->r1) {
        // 0x8009542C: nop
    
            goto L_80095434;
    }
    // 0x8009542C: nop

    // 0x80095430: break       6
    do_break(2148095024);
L_80095434:
    // 0x80095434: mflo        $a1
    ctx->r5 = lo;
    // 0x80095438: subu        $a3, $t5, $a1
    ctx->r7 = SUB32(ctx->r13, ctx->r5);
    // 0x8009543C: jal         0x80066B80
    // 0x80095440: nop

    viewport_menu_set(rdram, ctx);
        goto after_3;
    // 0x80095440: nop

    after_3:
    // 0x80095444: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80095448: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x8009544C: addiu       $v0, $v0, -0x324
    ctx->r2 = ADD32(ctx->r2, -0X324);
    // 0x80095450: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80095454: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80095458: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009545C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80095460: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80095464: swc1        $f4, 0x8C($t6)
    MEM_W(0X8C, ctx->r14) = ctx->f4.u32l;
    // 0x80095468: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009546C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80095470: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80095474: addu        $t2, $s2, $t9
    ctx->r10 = ADD32(ctx->r18, ctx->r25);
    // 0x80095478: sra         $t7, $t2, 1
    ctx->r15 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8009547C: subu        $t3, $t8, $t7
    ctx->r11 = SUB32(ctx->r24, ctx->r15);
    // 0x80095480: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80095484: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80095488: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8009548C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80095490: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095494: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095498: swc1        $f8, 0x90($t4)
    MEM_W(0X90, ctx->r12) = ctx->f8.u32l;
    // 0x8009549C: lwc1        $f10, -0x4E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4E8);
    // 0x800954A0: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800954A4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800954A8: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800954AC: b           L_80095A8C
    // 0x800954B0: swc1        $f16, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->f16.u32l;
        goto L_80095A8C;
    // 0x800954B0: swc1        $f16, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->f16.u32l;
L_800954B4:
    // 0x800954B4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800954B8: addiu       $v0, $v0, 0x116C
    ctx->r2 = ADD32(ctx->r2, 0X116C);
    // 0x800954BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800954C0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800954C4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800954C8: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x800954CC: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x800954D0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800954D4:
    // 0x800954D4: lb          $t6, 0x117($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X117);
    // 0x800954D8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800954DC: beq         $t6, $zero, L_80095518
    if (ctx->r14 == 0) {
        // 0x800954E0: nop
    
            goto L_80095518;
    }
    // 0x800954E0: nop

    // 0x800954E4: lb          $t9, 0x58($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X58);
    // 0x800954E8: sllv        $t8, $t2, $a1
    ctx->r24 = S32(ctx->r10 << (ctx->r5 & 31));
    // 0x800954EC: and         $t7, $t9, $t8
    ctx->r15 = ctx->r25 & ctx->r24;
    // 0x800954F0: beq         $t7, $zero, L_80095518
    if (ctx->r15 == 0) {
        // 0x800954F4: nop
    
            goto L_80095518;
    }
    // 0x800954F4: nop

    // 0x800954F8: multu       $s3, $v1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800954FC: subu        $t6, $t0, $s3
    ctx->r14 = SUB32(ctx->r8, ctx->r19);
    // 0x80095500: sb          $t6, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r14;
    // 0x80095504: mflo        $t3
    ctx->r11 = lo;
    // 0x80095508: sra         $t4, $t3, 2
    ctx->r12 = S32(SIGNED(ctx->r11) >> 2);
    // 0x8009550C: subu        $t5, $a0, $t4
    ctx->r13 = SUB32(ctx->r4, ctx->r12);
    // 0x80095510: b           L_80095520
    // 0x80095514: sb          $t5, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r13;
        goto L_80095520;
    // 0x80095514: sb          $t5, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r13;
L_80095518:
    // 0x80095518: sb          $a2, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r6;
    // 0x8009551C: sb          $a3, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r7;
L_80095520:
    // 0x80095520: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80095524: bne         $a1, $v1, L_800954D4
    if (ctx->r5 != ctx->r3) {
        // 0x80095528: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_800954D4;
    }
    // 0x80095528: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8009552C: lb          $t2, 0x117($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X117);
    // 0x80095530: nop

    // 0x80095534: beq         $t2, $zero, L_8009556C
    if (ctx->r10 == 0) {
        // 0x80095538: nop
    
            goto L_8009556C;
    }
    // 0x80095538: nop

    // 0x8009553C: lb          $t9, 0x58($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X58);
    // 0x80095540: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80095544: andi        $t8, $t9, 0x80
    ctx->r24 = ctx->r25 & 0X80;
    // 0x80095548: beq         $t8, $zero, L_8009556C
    if (ctx->r24 == 0) {
        // 0x8009554C: addiu       $v0, $v0, 0x116C
        ctx->r2 = ADD32(ctx->r2, 0X116C);
            goto L_8009556C;
    }
    // 0x8009554C: addiu       $v0, $v0, 0x116C
    ctx->r2 = ADD32(ctx->r2, 0X116C);
    // 0x80095550: sra         $t7, $s3, 1
    ctx->r15 = S32(SIGNED(ctx->r19) >> 1);
    // 0x80095554: addiu       $t3, $t7, 0x80
    ctx->r11 = ADD32(ctx->r15, 0X80);
    // 0x80095558: subu        $v1, $t0, $s3
    ctx->r3 = SUB32(ctx->r8, ctx->r19);
    // 0x8009555C: sb          $t3, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = ctx->r11;
    // 0x80095560: sb          $v1, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r3;
    // 0x80095564: b           L_80095A8C
    // 0x80095568: sb          $v1, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r3;
        goto L_80095A8C;
    // 0x80095568: sb          $v1, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r3;
L_8009556C:
    // 0x8009556C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80095570: addiu       $v0, $v0, 0x116C
    ctx->r2 = ADD32(ctx->r2, 0X116C);
    // 0x80095574: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80095578: sb          $t4, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = ctx->r12;
    // 0x8009557C: sb          $a3, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r7;
    // 0x80095580: b           L_80095A8C
    // 0x80095584: sb          $a3, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r7;
        goto L_80095A8C;
    // 0x80095584: sb          $a3, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r7;
L_80095588:
    // 0x80095588: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8009558C: addiu       $a2, $a2, 0x134C
    ctx->r6 = ADD32(ctx->r6, 0X134C);
    // 0x80095590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80095594: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_80095598:
    // 0x80095598: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8009559C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800955A0: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x800955A4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800955A8: jal         0x8009F1C4
    // 0x800955AC: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    is_in_two_player_adventure(rdram, ctx);
        goto after_4;
    // 0x800955AC: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_4:
    // 0x800955B0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800955B4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800955B8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800955BC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800955C0: beq         $v0, $zero, L_800955E0
    if (ctx->r2 == 0) {
        // 0x800955C4: nop
    
            goto L_800955E0;
    }
    // 0x800955C4: nop

    // 0x800955C8: lb          $t5, 0x72($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X72);
    // 0x800955CC: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x800955D0: bne         $a0, $t5, L_800955E0
    if (ctx->r4 != ctx->r13) {
        // 0x800955D4: nop
    
            goto L_800955E0;
    }
    // 0x800955D4: nop

    // 0x800955D8: sra         $v1, $s3, 1
    ctx->r3 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800955DC: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
L_800955E0:
    // 0x800955E0: lb          $t6, 0x5A($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X5A);
    // 0x800955E4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800955E8: bne         $a0, $t6, L_800955F8
    if (ctx->r4 != ctx->r14) {
        // 0x800955EC: nop
    
            goto L_800955F8;
    }
    // 0x800955EC: nop

    // 0x800955F0: sra         $v1, $s3, 1
    ctx->r3 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800955F4: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
L_800955F8:
    // 0x800955F8: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800955FC: sb          $v1, 0x2C($a2)
    MEM_B(0X2C, ctx->r6) = ctx->r3;
    // 0x80095600: sb          $v1, 0x2D($a2)
    MEM_B(0X2D, ctx->r6) = ctx->r3;
    // 0x80095604: bne         $a1, $s1, L_80095598
    if (ctx->r5 != ctx->r17) {
        // 0x80095608: sb          $v1, 0x2E($a2)
        MEM_B(0X2E, ctx->r6) = ctx->r3;
            goto L_80095598;
    }
    // 0x80095608: sb          $v1, 0x2E($a2)
    MEM_B(0X2E, ctx->r6) = ctx->r3;
    // 0x8009560C: b           L_80095A8C
    // 0x80095610: nop

        goto L_80095A8C;
    // 0x80095610: nop

L_80095614:
    // 0x80095614: lb          $t2, 0x117($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X117);
    // 0x80095618: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009561C: beq         $t2, $zero, L_80095670
    if (ctx->r10 == 0) {
        // 0x80095620: addiu       $v0, $v0, 0x13CC
        ctx->r2 = ADD32(ctx->r2, 0X13CC);
            goto L_80095670;
    }
    // 0x80095620: addiu       $v0, $v0, 0x13CC
    ctx->r2 = ADD32(ctx->r2, 0X13CC);
    // 0x80095624: lb          $t9, 0x58($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X58);
    // 0x80095628: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8009562C: andi        $t8, $t9, 0x7F
    ctx->r24 = ctx->r25 & 0X7F;
    // 0x80095630: beq         $t8, $zero, L_80095674
    if (ctx->r24 == 0) {
        // 0x80095634: addiu       $a3, $zero, 0xFF
        ctx->r7 = ADD32(0, 0XFF);
            goto L_80095674;
    }
    // 0x80095634: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80095638: multu       $s3, $v1
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009563C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80095640: addiu       $v0, $v0, 0x13CC
    ctx->r2 = ADD32(ctx->r2, 0X13CC);
    // 0x80095644: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x80095648: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8009564C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80095650: subu        $t5, $t0, $s3
    ctx->r13 = SUB32(ctx->r8, ctx->r19);
    // 0x80095654: sb          $a3, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = ctx->r7;
    // 0x80095658: sb          $t5, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r13;
    // 0x8009565C: mflo        $t7
    ctx->r15 = lo;
    // 0x80095660: sra         $t3, $t7, 2
    ctx->r11 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80095664: subu        $t4, $a0, $t3
    ctx->r12 = SUB32(ctx->r4, ctx->r11);
    // 0x80095668: b           L_80095688
    // 0x8009566C: sb          $t4, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r12;
        goto L_80095688;
    // 0x8009566C: sb          $t4, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r12;
L_80095670:
    // 0x80095670: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_80095674:
    // 0x80095674: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80095678: sb          $a3, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = ctx->r7;
    // 0x8009567C: sb          $a2, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = ctx->r6;
    // 0x80095680: sb          $a3, 0xCE($v0)
    MEM_B(0XCE, ctx->r2) = ctx->r7;
    // 0x80095684: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_80095688:
    // 0x80095688: lb          $t6, 0x117($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X117);
    // 0x8009568C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80095690: beq         $t6, $zero, L_800956C0
    if (ctx->r14 == 0) {
        // 0x80095694: nop
    
            goto L_800956C0;
    }
    // 0x80095694: nop

    // 0x80095698: lb          $t2, 0x58($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X58);
    // 0x8009569C: sra         $t8, $s3, 1
    ctx->r24 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800956A0: andi        $t9, $t2, 0x80
    ctx->r25 = ctx->r10 & 0X80;
    // 0x800956A4: beq         $t9, $zero, L_800956C0
    if (ctx->r25 == 0) {
        // 0x800956A8: addiu       $t7, $t8, 0x80
        ctx->r15 = ADD32(ctx->r24, 0X80);
            goto L_800956C0;
    }
    // 0x800956A8: addiu       $t7, $t8, 0x80
    ctx->r15 = ADD32(ctx->r24, 0X80);
    // 0x800956AC: subu        $v1, $t0, $s3
    ctx->r3 = SUB32(ctx->r8, ctx->r19);
    // 0x800956B0: sb          $t7, 0x6C($v0)
    MEM_B(0X6C, ctx->r2) = ctx->r15;
    // 0x800956B4: sb          $v1, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r3;
    // 0x800956B8: b           L_80095A8C
    // 0x800956BC: sb          $v1, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r3;
        goto L_80095A8C;
    // 0x800956BC: sb          $v1, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r3;
L_800956C0:
    // 0x800956C0: sb          $t3, 0x6C($v0)
    MEM_B(0X6C, ctx->r2) = ctx->r11;
    // 0x800956C4: sb          $a3, 0x6D($v0)
    MEM_B(0X6D, ctx->r2) = ctx->r7;
    // 0x800956C8: b           L_80095A8C
    // 0x800956CC: sb          $a3, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r7;
        goto L_80095A8C;
    // 0x800956CC: sb          $a3, 0x6E($v0)
    MEM_B(0X6E, ctx->r2) = ctx->r7;
L_800956D0:
    // 0x800956D0: jal         0x800C5C30
    // 0x800956D4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_5;
    // 0x800956D4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_5:
    // 0x800956D8: jal         0x800C59F4
    // 0x800956DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_6;
    // 0x800956DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_6:
    // 0x800956E0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800956E4: jal         0x800C54DC
    // 0x800956E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_7;
    // 0x800956E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800956EC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800956F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800956F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800956F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800956FC: jal         0x800C55B0
    // 0x80095700: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_8;
    // 0x80095700: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80095704: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80095708: addiu       $s1, $s1, 0x7058
    ctx->r17 = ADD32(ctx->r17, 0X7058);
    // 0x8009570C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80095710: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095714: beq         $t4, $zero, L_80095724
    if (ctx->r12 == 0) {
        // 0x80095718: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80095724;
    }
    // 0x80095718: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009571C: b           L_80095750
    // 0x80095720: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80095750;
    // 0x80095720: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80095724:
    // 0x80095724: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80095728: lw          $t5, 0x71DC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X71DC);
    // 0x8009572C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80095730: beq         $t5, $zero, L_80095748
    if (ctx->r13 == 0) {
        // 0x80095734: nop
    
            goto L_80095748;
    }
    // 0x80095734: nop

    // 0x80095738: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009573C: lw          $s0, 0x71E4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X71E4);
    // 0x80095740: b           L_80095754
    // 0x80095744: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
        goto L_80095754;
    // 0x80095744: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
L_80095748:
    // 0x80095748: lw          $s0, 0x71D4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X71D4);
    // 0x8009574C: nop

L_80095750:
    // 0x80095750: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
L_80095754:
    // 0x80095754: bne         $at, $zero, L_8009576C
    if (ctx->r1 != 0) {
        // 0x80095758: addiu       $a3, $zero, 0x140
        ctx->r7 = ADD32(0, 0X140);
            goto L_8009576C;
    }
    // 0x80095758: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // 0x8009575C: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x80095760: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80095764: b           L_80095778
    // 0x80095768: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
        goto L_80095778;
    // 0x80095768: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
L_8009576C:
    // 0x8009576C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80095770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80095774: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
L_80095778:
    // 0x80095778: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8009577C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80095780: multu       $s0, $t9
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80095784: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80095788: addiu       $s0, $zero, 0xC0
    ctx->r16 = ADD32(0, 0XC0);
    // 0x8009578C: mflo        $s2
    ctx->r18 = lo;
    // 0x80095790: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80095794: sra         $t8, $s2, 1
    ctx->r24 = S32(SIGNED(ctx->r18) >> 1);
    // 0x80095798: bne         $t7, $zero, L_800957A4
    if (ctx->r15 != 0) {
        // 0x8009579C: or          $s2, $t8, $zero
        ctx->r18 = ctx->r24 | 0;
            goto L_800957A4;
    }
    // 0x8009579C: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800957A0: addiu       $s0, $zero, 0xDA
    ctx->r16 = ADD32(0, 0XDA);
L_800957A4:
    // 0x800957A4: addu        $t4, $s0, $s2
    ctx->r12 = ADD32(ctx->r16, ctx->r18);
    // 0x800957A8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800957AC: subu        $t3, $s0, $s2
    ctx->r11 = SUB32(ctx->r16, ctx->r18);
    // 0x800957B0: subu        $a2, $t3, $v0
    ctx->r6 = SUB32(ctx->r11, ctx->r2);
    // 0x800957B4: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800957B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800957BC: jal         0x800C543C
    // 0x800957C0: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_9;
    // 0x800957C0: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    after_9:
    // 0x800957C4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800957C8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800957CC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800957D0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800957D4: jal         0x800C551C
    // 0x800957D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_10;
    // 0x800957D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_10:
    // 0x800957DC: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x800957E0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800957E4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800957E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800957EC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800957F0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800957F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800957F8: jal         0x800C5560
    // 0x800957FC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_text_colour(rdram, ctx);
        goto after_11;
    // 0x800957FC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_11:
    // 0x80095800: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80095804: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80095808: beq         $t8, $zero, L_80095844
    if (ctx->r24 == 0) {
        // 0x8009580C: addiu       $v0, $v0, 0x71DC
        ctx->r2 = ADD32(ctx->r2, 0X71DC);
            goto L_80095844;
    }
    // 0x8009580C: addiu       $v0, $v0, 0x71DC
    ctx->r2 = ADD32(ctx->r2, 0X71DC);
    // 0x80095810: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80095814: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x80095818: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8009581C: lw          $a3, 0x1F0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X1F0);
    // 0x80095820: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80095824: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80095828: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009582C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095830: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80095834: jal         0x800C56C8
    // 0x80095838: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    render_dialogue_text(rdram, ctx);
        goto after_12;
    // 0x80095838: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_12:
    // 0x8009583C: b           L_80095A84
    // 0x80095840: nop

        goto L_80095A84;
    // 0x80095840: nop

L_80095844:
    // 0x80095844: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80095848: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009584C: beq         $t5, $zero, L_800958D0
    if (ctx->r13 == 0) {
        // 0x80095850: addiu       $s1, $s1, 0xF08
        ctx->r17 = ADD32(ctx->r17, 0XF08);
            goto L_800958D0;
    }
    // 0x80095850: addiu       $s1, $s1, 0xF08
    ctx->r17 = ADD32(ctx->r17, 0XF08);
    // 0x80095854: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80095858: lw          $t6, 0x71E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X71E4);
    // 0x8009585C: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x80095860: blez        $t6, L_80095A84
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80095864: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80095A84;
    }
    // 0x80095864: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80095868: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8009586C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80095870:
    // 0x80095870: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80095874: addiu       $v0, $v0, 0x71DC
    ctx->r2 = ADD32(ctx->r2, 0X71DC);
    // 0x80095878: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8009587C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80095880: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x80095884: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x80095888: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8009588C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80095890: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80095894: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80095898: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009589C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x800958A0: jal         0x800C56C8
    // 0x800958A4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_13;
    // 0x800958A4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_13:
    // 0x800958A8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800958AC: lw          $t3, 0x71E4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X71E4);
    // 0x800958B0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800958B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800958B8: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800958BC: addu        $s2, $s2, $s1
    ctx->r18 = ADD32(ctx->r18, ctx->r17);
    // 0x800958C0: bne         $at, $zero, L_80095870
    if (ctx->r1 != 0) {
        // 0x800958C4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80095870;
    }
    // 0x800958C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800958C8: b           L_80095A84
    // 0x800958CC: nop

        goto L_80095A84;
    // 0x800958CC: nop

L_800958D0:
    // 0x800958D0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800958D4: addiu       $s2, $s2, -0x18
    ctx->r18 = ADD32(ctx->r18, -0X18);
    // 0x800958D8: beq         $t4, $zero, L_800959D4
    if (ctx->r12 == 0) {
        // 0x800958DC: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800959D4;
    }
    // 0x800958DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800958E0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800958E4: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x800958E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800958EC: lw          $a3, 0x210($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X210);
    // 0x800958F0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800958F4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800958F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800958FC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095900: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80095904: jal         0x800C56C8
    // 0x80095908: addiu       $a2, $s2, 0x8
    ctx->r6 = ADD32(ctx->r18, 0X8);
    render_dialogue_text(rdram, ctx);
        goto after_14;
    // 0x80095908: addiu       $a2, $s2, 0x8
    ctx->r6 = ADD32(ctx->r18, 0X8);
    after_14:
    // 0x8009590C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80095910: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80095914: bne         $t9, $at, L_80095920
    if (ctx->r25 != ctx->r1) {
        // 0x80095918: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80095920;
    }
    // 0x80095918: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009591C: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
L_80095920:
    // 0x80095920: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80095924: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80095928: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009592C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80095930: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095934: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80095938: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009593C: jal         0x800C5560
    // 0x80095940: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_text_colour(rdram, ctx);
        goto after_15;
    // 0x80095940: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_15:
    // 0x80095944: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80095948: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x8009594C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80095950: lw          $a3, 0x218($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X218);
    // 0x80095954: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80095958: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8009595C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80095960: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095964: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80095968: jal         0x800C56C8
    // 0x8009596C: addiu       $a2, $s2, 0x1A
    ctx->r6 = ADD32(ctx->r18, 0X1A);
    render_dialogue_text(rdram, ctx);
        goto after_16;
    // 0x8009596C: addiu       $a2, $s2, 0x1A
    ctx->r6 = ADD32(ctx->r18, 0X1A);
    after_16:
    // 0x80095970: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80095974: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80095978: bne         $t5, $at, L_80095984
    if (ctx->r13 != ctx->r1) {
        // 0x8009597C: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80095984;
    }
    // 0x8009597C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095980: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
L_80095984:
    // 0x80095984: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80095988: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8009598C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80095990: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80095994: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80095998: jal         0x800C5560
    // 0x8009599C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    set_current_text_colour(rdram, ctx);
        goto after_17;
    // 0x8009599C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_17:
    // 0x800959A0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800959A4: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x800959A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800959AC: lw          $a3, 0x154($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X154);
    // 0x800959B0: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800959B4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800959B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800959BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800959C0: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x800959C4: jal         0x800C56C8
    // 0x800959C8: addiu       $a2, $s2, 0x2A
    ctx->r6 = ADD32(ctx->r18, 0X2A);
    render_dialogue_text(rdram, ctx);
        goto after_18;
    // 0x800959C8: addiu       $a2, $s2, 0x2A
    ctx->r6 = ADD32(ctx->r18, 0X2A);
    after_18:
    // 0x800959CC: b           L_80095A84
    // 0x800959D0: nop

        goto L_80095A84;
    // 0x800959D0: nop

L_800959D4:
    // 0x800959D4: lw          $t7, 0x71D4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X71D4);
    // 0x800959D8: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x800959DC: blez        $t7, L_80095A84
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800959E0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80095A84;
    }
    // 0x800959E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800959E4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800959E8: addiu       $s1, $s1, 0x71B0
    ctx->r17 = ADD32(ctx->r17, 0X71B0);
L_800959EC:
    // 0x800959EC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800959F0: lw          $t3, 0x7028($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7028);
    // 0x800959F4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800959F8: bne         $s0, $t3, L_80095A28
    if (ctx->r16 != ctx->r11) {
        // 0x800959FC: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80095A28;
    }
    // 0x800959FC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80095A00: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80095A04: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80095A08: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095A0C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80095A10: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80095A14: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80095A18: jal         0x800C5560
    // 0x80095A1C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    set_current_text_colour(rdram, ctx);
        goto after_19;
    // 0x80095A1C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_19:
    // 0x80095A20: b           L_80095A44
    // 0x80095A24: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
        goto L_80095A44;
    // 0x80095A24: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
L_80095A28:
    // 0x80095A28: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80095A2C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80095A30: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80095A34: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80095A38: jal         0x800C5560
    // 0x80095A3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_20;
    // 0x80095A3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_20:
    // 0x80095A40: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
L_80095A44:
    // 0x80095A44: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80095A48: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80095A4C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80095A50: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80095A54: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80095A58: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80095A5C: jal         0x800C56C8
    // 0x80095A60: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_21;
    // 0x80095A60: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_21:
    // 0x80095A64: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80095A68: lw          $t8, 0x71D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X71D4);
    // 0x80095A6C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80095A70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80095A74: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80095A78: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80095A7C: bne         $at, $zero, L_800959EC
    if (ctx->r1 != 0) {
        // 0x80095A80: addu        $s2, $s2, $t9
        ctx->r18 = ADD32(ctx->r18, ctx->r25);
            goto L_800959EC;
    }
    // 0x80095A80: addu        $s2, $s2, $t9
    ctx->r18 = ADD32(ctx->r18, ctx->r25);
L_80095A84:
    // 0x80095A84: jal         0x800C5B54
    // 0x80095A88: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    open_dialogue_box(rdram, ctx);
        goto after_22;
    // 0x80095A88: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_22:
L_80095A8C:
    // 0x80095A8C: jal         0x8006DC4C
    // 0x80095A90: nop

    get_game_mode(rdram, ctx);
        goto after_23;
    // 0x80095A90: nop

    after_23:
    // 0x80095A94: bne         $v0, $zero, L_80095B0C
    if (ctx->r2 != 0) {
        // 0x80095A98: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80095B0C;
    }
    // 0x80095A98: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80095A9C: lw          $t7, -0x5C4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5C4);
    // 0x80095AA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80095AA4: bne         $t7, $at, L_80095B0C
    if (ctx->r15 != ctx->r1) {
        // 0x80095AA8: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_80095B0C;
    }
    // 0x80095AA8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80095AAC: lw          $t3, 0x1568($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1568);
    // 0x80095AB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80095AB4: bne         $t3, $zero, L_80095B10
    if (ctx->r11 != 0) {
        // 0x80095AB8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80095B10;
    }
    // 0x80095AB8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80095ABC: jal         0x80066A58
    // 0x80095AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_24;
    // 0x80095AC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80095AC4: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80095AC8: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x80095ACC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80095AD0: bne         $t4, $zero, L_80095AE4
    if (ctx->r12 != 0) {
        // 0x80095AD4: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80095AE4;
    }
    // 0x80095AD4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80095AD8: lwc1        $f18, -0x7550($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7550);
    // 0x80095ADC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095AE0: swc1        $f18, -0x62C($at)
    MEM_W(-0X62C, ctx->r1) = ctx->f18.u32l;
L_80095AE4:
    // 0x80095AE4: lw          $t5, 0x6980($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6980);
    // 0x80095AE8: nop

    // 0x80095AEC: blez        $t5, L_80095B00
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80095AF0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80095B00;
    }
    // 0x80095AF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80095AF4: jal         0x8009CFA4
    // 0x80095AF8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    menu_element_render(rdram, ctx);
        goto after_25;
    // 0x80095AF8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_25:
    // 0x80095AFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80095B00:
    // 0x80095B00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80095B04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80095B08: swc1        $f6, -0x62C($at)
    MEM_W(-0X62C, ctx->r1) = ctx->f6.u32l;
L_80095B0C:
    // 0x80095B0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80095B10:
    // 0x80095B10: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80095B14: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80095B18: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80095B1C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80095B20: jr          $ra
    // 0x80095B24: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80095B24: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void obj_tex_animate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011134: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80011138: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001113C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80011140: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80011144: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80011148: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001114C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80011150: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80011154: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80011158: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001115C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80011160: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x80011164: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80011168: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001116C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80011170: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80011174: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80011178: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x8001117C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80011180: lh          $s5, 0x50($s3)
    ctx->r21 = MEM_H(ctx->r19, 0X50);
    // 0x80011184: lw          $s4, 0x38($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X38);
    // 0x80011188: blez        $s5, L_80011238
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8001118C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80011238;
    }
    // 0x8001118C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80011190: lh          $t0, 0x28($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X28);
    // 0x80011194: sll         $s2, $zero, 2
    ctx->r18 = S32(0 << 2);
    // 0x80011198: blez        $t0, L_80011234
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8001119C: subu        $s2, $s2, $zero
        ctx->r18 = SUB32(ctx->r18, 0);
            goto L_80011234;
    }
    // 0x8001119C: subu        $s2, $s2, $zero
    ctx->r18 = SUB32(ctx->r18, 0);
    // 0x800111A0: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x800111A4: addu        $s0, $s4, $s2
    ctx->r16 = ADD32(ctx->r20, ctx->r18);
    // 0x800111A8: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x800111AC: lui         $s7, 0x1
    ctx->r23 = S32(0X1 << 16);
L_800111B0:
    // 0x800111B0: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x800111B4: nop

    // 0x800111B8: and         $t2, $t1, $s7
    ctx->r10 = ctx->r9 & ctx->r23;
    // 0x800111BC: beq         $t2, $zero, L_80011210
    if (ctx->r10 == 0) {
        // 0x800111C0: nop
    
            goto L_80011210;
    }
    // 0x800111C0: nop

    // 0x800111C4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800111C8: addu        $a1, $s2, $s4
    ctx->r5 = ADD32(ctx->r18, ctx->r20);
    // 0x800111CC: beq         $fp, $v0, L_80011210
    if (ctx->r30 == ctx->r2) {
        // 0x800111D0: sll         $t4, $v0, 3
        ctx->r12 = S32(ctx->r2 << 3);
            goto L_80011210;
    }
    // 0x800111D0: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x800111D4: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800111D8: lbu         $t7, 0x7($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7);
    // 0x800111DC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800111E0: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800111E4: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x800111E8: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x800111EC: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x800111F0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800111F4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x800111F8: jal         0x8007F3D0
    // 0x800111FC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    tex_animate_texture(rdram, ctx);
        goto after_0;
    // 0x800111FC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_0:
    // 0x80011200: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80011204: nop

    // 0x80011208: sra         $t1, $t9, 6
    ctx->r9 = S32(SIGNED(ctx->r25) >> 6);
    // 0x8001120C: sb          $t1, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r9;
L_80011210:
    // 0x80011210: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80011214: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80011218: blez        $s5, L_80011234
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8001121C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80011234;
    }
    // 0x8001121C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80011220: lh          $t2, 0x28($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X28);
    // 0x80011224: nop

    // 0x80011228: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8001122C: bne         $at, $zero, L_800111B0
    if (ctx->r1 != 0) {
        // 0x80011230: nop
    
            goto L_800111B0;
    }
    // 0x80011230: nop

L_80011234:
    // 0x80011234: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80011238:
    // 0x80011238: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001123C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80011240: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80011244: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80011248: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001124C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80011250: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80011254: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80011258: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001125C: jr          $ra
    // 0x80011260: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80011260: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void alEvtqFlush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C969C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C96A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C96A4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C96A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C96AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C96B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C96B4: jal         0x800C9F90
    // 0x800C96B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C96B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C96BC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800C96C0: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800C96C4: beq         $s0, $zero, L_800C96EC
    if (ctx->r16 == 0) {
        // 0x800C96C8: nop
    
            goto L_800C96EC;
    }
    // 0x800C96C8: nop

L_800C96CC:
    // 0x800C96CC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800C96D0: jal         0x800C8CC0
    // 0x800C96D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C96D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C96D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C96DC: jal         0x800C8CF0
    // 0x800C96E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C96E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800C96E4: bne         $s1, $zero, L_800C96CC
    if (ctx->r17 != 0) {
        // 0x800C96E8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800C96CC;
    }
    // 0x800C96E8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800C96EC:
    // 0x800C96EC: jal         0x800C9F90
    // 0x800C96F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C96F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800C96F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C96F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C96FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9700: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C9704: jr          $ra
    // 0x800C9708: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C9708: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void hud_magnet_reticle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7FBC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A7FC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A7FC4: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x800A7FC8: nop

    // 0x800A7FCC: lw          $t6, 0x140($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X140);
    // 0x800A7FD0: nop

    // 0x800A7FD4: beq         $t6, $zero, L_800A80B8
    if (ctx->r14 == 0) {
        // 0x800A7FD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A80B8;
    }
    // 0x800A7FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7FDC: jal         0x80066460
    // 0x800A7FE0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    get_current_viewport(rdram, ctx);
        goto after_0;
    // 0x800A7FE0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x800A7FE4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800A7FE8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A7FEC: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A7FF0: nop

    // 0x800A7FF4: bne         $v0, $t7, L_800A80B8
    if (ctx->r2 != ctx->r15) {
        // 0x800A7FF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A80B8;
    }
    // 0x800A7FF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7FFC: lw          $t8, 0x140($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X140);
    // 0x800A8000: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A8004: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800A8008: lh          $a2, 0x226($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X226);
    // 0x800A800C: swc1        $f4, 0x22C($a3)
    MEM_W(0X22C, ctx->r7) = ctx->f4.u32l;
    // 0x800A8010: lw          $t9, 0x140($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X140);
    // 0x800A8014: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A8018: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800A801C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x800A8020: swc1        $f6, 0x230($a3)
    MEM_W(0X230, ctx->r7) = ctx->f6.u32l;
    // 0x800A8024: lw          $t0, 0x140($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X140);
    // 0x800A8028: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A802C: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800A8030: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A8034: swc1        $f8, 0x234($a3)
    MEM_W(0X234, ctx->r7) = ctx->f8.u32l;
    // 0x800A8038: lw          $t1, 0x72B4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X72B4);
    // 0x800A803C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A8040: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800A8044: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800A8048: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A804C: beq         $v0, $zero, L_800A80B4
    if (ctx->r2 == 0) {
        // 0x800A8050: addiu       $a3, $a3, 0x220
        ctx->r7 = ADD32(ctx->r7, 0X220);
            goto L_800A80B4;
    }
    // 0x800A8050: addiu       $a3, $a3, 0x220
    ctx->r7 = ADD32(ctx->r7, 0X220);
    // 0x800A8054: lw          $t4, 0x7298($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7298);
    // 0x800A8058: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A805C: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800A8060: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x800A8064: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800A8068: jal         0x80066F1C
    // 0x800A806C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    viewport_main(rdram, ctx);
        goto after_1;
    // 0x800A806C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A8070: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A8074: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8078: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A807C: jal         0x80068648
    // 0x800A8080: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    mtx_world_origin(rdram, ctx);
        goto after_2;
    // 0x800A8080: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_2:
    // 0x800A8084: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800A8088: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800A808C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A8090: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8094: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A8098: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x800A809C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A80A0: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A80A4: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A80A8: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A80AC: jal         0x80068754
    // 0x800A80B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    render_sprite_billboard(rdram, ctx);
        goto after_3;
    // 0x800A80B0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
L_800A80B4:
    // 0x800A80B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A80B8:
    // 0x800A80B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A80BC: jr          $ra
    // 0x800A80C0: nop

    return;
    // 0x800A80C0: nop

;}
RECOMP_FUNC void init_point_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF584: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800AF588: sh          $a3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r7;
    // 0x800AF58C: sh          $a3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r7;
    // 0x800AF590: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800AF594: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AF598: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800AF59C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800AF5A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800AF5A4: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800AF5A8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AF5AC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800AF5B0:
    // 0x800AF5B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AF5B4: sb          $a0, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r4;
    // 0x800AF5B8: sb          $a0, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r4;
    // 0x800AF5BC: sb          $a0, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r4;
    // 0x800AF5C0: sb          $a0, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r4;
    // 0x800AF5C4: sb          $a0, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r4;
    // 0x800AF5C8: sb          $a0, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r4;
    // 0x800AF5CC: sb          $a0, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r4;
    // 0x800AF5D0: sb          $a0, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r4;
    // 0x800AF5D4: sb          $a0, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r4;
    // 0x800AF5D8: sb          $a0, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r4;
    // 0x800AF5DC: sb          $a0, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r4;
    // 0x800AF5E0: sb          $a0, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r4;
    // 0x800AF5E4: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800AF5E8: sb          $a0, -0x22($v0)
    MEM_B(-0X22, ctx->r2) = ctx->r4;
    // 0x800AF5EC: sb          $a0, -0x21($v0)
    MEM_B(-0X21, ctx->r2) = ctx->r4;
    // 0x800AF5F0: sb          $a0, -0x20($v0)
    MEM_B(-0X20, ctx->r2) = ctx->r4;
    // 0x800AF5F4: bne         $v1, $a2, L_800AF5B0
    if (ctx->r3 != ctx->r6) {
        // 0x800AF5F8: sb          $a0, -0x1F($v0)
        MEM_B(-0X1F, ctx->r2) = ctx->r4;
            goto L_800AF5B0;
    }
    // 0x800AF5F8: sb          $a0, -0x1F($v0)
    MEM_B(-0X1F, ctx->r2) = ctx->r4;
    // 0x800AF5FC: jr          $ra
    // 0x800AF600: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    return;
    // 0x800AF600: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void init_rectangle_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF418: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800AF41C: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x800AF420: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800AF424: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF428: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800AF42C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AF430: addiu       $v1, $v1, 0x3404
    ctx->r3 = ADD32(ctx->r3, 0X3404);
    // 0x800AF434: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AF438: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_800AF43C:
    // 0x800AF43C: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800AF440: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800AF444: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800AF448: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x800AF44C: sll         $t2, $a3, 16
    ctx->r10 = S32(ctx->r7 << 16);
    // 0x800AF450: sra         $a3, $t2, 16
    ctx->r7 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800AF454: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x800AF458: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AF45C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800AF460: sb          $t0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r8;
    // 0x800AF464: sb          $t0, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r8;
    // 0x800AF468: sb          $t0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r8;
    // 0x800AF46C: sb          $t0, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r8;
    // 0x800AF470: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800AF474: bne         $at, $zero, L_800AF43C
    if (ctx->r1 != 0) {
        // 0x800AF478: sh          $t9, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r25;
            goto L_800AF43C;
    }
    // 0x800AF478: sh          $t9, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r25;
    // 0x800AF47C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AF480: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800AF484: sh          $t4, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r12;
    // 0x800AF488: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800AF48C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800AF490: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    // 0x800AF494: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800AF498: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800AF49C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AF4A0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800AF4A4: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x800AF4A8: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    // 0x800AF4AC: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x800AF4B0: sb          $t1, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r9;
    // 0x800AF4B4: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x800AF4B8: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800AF4BC: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x800AF4C0: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x800AF4C4: sb          $a3, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r7;
    // 0x800AF4C8: sb          $t0, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r8;
    // 0x800AF4CC: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x800AF4D0: sb          $t6, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r14;
    // 0x800AF4D4: sb          $t1, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r9;
    // 0x800AF4D8: sh          $zero, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = 0;
    // 0x800AF4DC: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800AF4E0: jr          $ra
    // 0x800AF4E4: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    return;
    // 0x800AF4E4: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
;}
RECOMP_FUNC void hud_main_battle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2144: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A2148: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A214C: lbu         $t7, 0x72F7($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X72F7);
    // 0x800A2150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2154: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800A2158: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800A215C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800A2160: lw          $a3, 0x64($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X64);
    // 0x800A2164: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A2168: bne         $t7, $at, L_800A2180
    if (ctx->r15 != ctx->r1) {
        // 0x800A216C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A2180;
    }
    // 0x800A216C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A2170: lb          $t8, 0x1D8($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A2174: nop

    // 0x800A2178: bne         $t8, $zero, L_800A237C
    if (ctx->r24 != 0) {
        // 0x800A217C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A237C;
    }
    // 0x800A217C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2180:
    // 0x800A2180: jal         0x80068748
    // 0x800A2184: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A2184: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A2188: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A218C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800A2190: jal         0x800A422C
    // 0x800A2194: nop

    hud_race_start(rdram, ctx);
        goto after_1;
    // 0x800A2194: nop

    after_1:
    // 0x800A2198: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A219C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800A21A0: jal         0x800A7A7C
    // 0x800A21A4: nop

    hud_weapon(rdram, ctx);
        goto after_2;
    // 0x800A21A4: nop

    after_2:
    // 0x800A21A8: jal         0x8001BAA8
    // 0x800A21AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    get_racer_objects(rdram, ctx);
        goto after_3;
    // 0x800A21AC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x800A21B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A21B4: lbu         $v1, 0x72F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X72F7);
    // 0x800A21B8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800A21BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A21C0: beq         $v1, $at, L_800A21D8
    if (ctx->r3 == ctx->r1) {
        // 0x800A21C4: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_800A21D8;
    }
    // 0x800A21C4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800A21C8: beq         $v1, $t2, L_800A21F4
    if (ctx->r3 == ctx->r10) {
        // 0x800A21CC: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_800A21F4;
    }
    // 0x800A21CC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800A21D0: b           L_800A2368
    // 0x800A21D4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
        goto L_800A2368;
    // 0x800A21D4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800A21D8:
    // 0x800A21D8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A21DC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800A21E0: jal         0x800A2388
    // 0x800A21E4: nop

    hud_battle_portraits(rdram, ctx);
        goto after_4;
    // 0x800A21E4: nop

    after_4:
    // 0x800A21E8: b           L_800A2370
    // 0x800A21EC: nop

        goto L_800A2370;
    // 0x800A21EC: nop

    // 0x800A21F0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_800A21F4:
    // 0x800A21F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A21F8: blez        $t9, L_800A2354
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800A21FC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800A2354;
    }
    // 0x800A21FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A2200: andi        $v1, $t9, 0x3
    ctx->r3 = ctx->r25 & 0X3;
    // 0x800A2204: beq         $v1, $zero, L_800A2264
    if (ctx->r3 == 0) {
        // 0x800A2208: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_800A2264;
    }
    // 0x800A2208: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800A220C: sll         $t3, $zero, 2
    ctx->r11 = S32(0 << 2);
    // 0x800A2210: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x800A2214: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A2218:
    // 0x800A2218: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800A221C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800A2220: lw          $v1, 0x64($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X64);
    // 0x800A2224: nop

    // 0x800A2228: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A222C: nop

    // 0x800A2230: beq         $t0, $t5, L_800A224C
    if (ctx->r8 == ctx->r13) {
        // 0x800A2234: nop
    
            goto L_800A224C;
    }
    // 0x800A2234: nop

    // 0x800A2238: lb          $t6, 0x1D8($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A223C: nop

    // 0x800A2240: beq         $t6, $zero, L_800A224C
    if (ctx->r14 == 0) {
        // 0x800A2244: nop
    
            goto L_800A224C;
    }
    // 0x800A2244: nop

    // 0x800A2248: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A224C:
    // 0x800A224C: bne         $t1, $a2, L_800A2218
    if (ctx->r9 != ctx->r6) {
        // 0x800A2250: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A2218;
    }
    // 0x800A2250: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A2254: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800A2258: nop

    // 0x800A225C: beq         $a2, $t7, L_800A2354
    if (ctx->r6 == ctx->r15) {
        // 0x800A2260: nop
    
            goto L_800A2354;
    }
    // 0x800A2260: nop

L_800A2264:
    // 0x800A2264: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800A2268: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800A226C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A2270: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800A2274: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x800A2278: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A227C:
    // 0x800A227C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800A2280: nop

    // 0x800A2284: lw          $v1, 0x64($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X64);
    // 0x800A2288: nop

    // 0x800A228C: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A2290: nop

    // 0x800A2294: beq         $t0, $t5, L_800A22B0
    if (ctx->r8 == ctx->r13) {
        // 0x800A2298: nop
    
            goto L_800A22B0;
    }
    // 0x800A2298: nop

    // 0x800A229C: lb          $t6, 0x1D8($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A22A0: nop

    // 0x800A22A4: beq         $t6, $zero, L_800A22B0
    if (ctx->r14 == 0) {
        // 0x800A22A8: nop
    
            goto L_800A22B0;
    }
    // 0x800A22A8: nop

    // 0x800A22AC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A22B0:
    // 0x800A22B0: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800A22B4: nop

    // 0x800A22B8: lw          $a3, 0x64($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X64);
    // 0x800A22BC: nop

    // 0x800A22C0: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800A22C4: nop

    // 0x800A22C8: beq         $t0, $t8, L_800A22E4
    if (ctx->r8 == ctx->r24) {
        // 0x800A22CC: nop
    
            goto L_800A22E4;
    }
    // 0x800A22CC: nop

    // 0x800A22D0: lb          $t9, 0x1D8($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A22D4: nop

    // 0x800A22D8: beq         $t9, $zero, L_800A22E4
    if (ctx->r25 == 0) {
        // 0x800A22DC: nop
    
            goto L_800A22E4;
    }
    // 0x800A22DC: nop

    // 0x800A22E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A22E4:
    // 0x800A22E4: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x800A22E8: nop

    // 0x800A22EC: lw          $a3, 0x64($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X64);
    // 0x800A22F0: nop

    // 0x800A22F4: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x800A22F8: nop

    // 0x800A22FC: beq         $t0, $t4, L_800A2318
    if (ctx->r8 == ctx->r12) {
        // 0x800A2300: nop
    
            goto L_800A2318;
    }
    // 0x800A2300: nop

    // 0x800A2304: lb          $t5, 0x1D8($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A2308: nop

    // 0x800A230C: beq         $t5, $zero, L_800A2318
    if (ctx->r13 == 0) {
        // 0x800A2310: nop
    
            goto L_800A2318;
    }
    // 0x800A2310: nop

    // 0x800A2314: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A2318:
    // 0x800A2318: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800A231C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A2320: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x800A2324: nop

    // 0x800A2328: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800A232C: nop

    // 0x800A2330: beq         $t0, $t7, L_800A234C
    if (ctx->r8 == ctx->r15) {
        // 0x800A2334: nop
    
            goto L_800A234C;
    }
    // 0x800A2334: nop

    // 0x800A2338: lb          $t8, 0x1D8($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1D8);
    // 0x800A233C: nop

    // 0x800A2340: beq         $t8, $zero, L_800A234C
    if (ctx->r24 == 0) {
        // 0x800A2344: nop
    
            goto L_800A234C;
    }
    // 0x800A2344: nop

    // 0x800A2348: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800A234C:
    // 0x800A234C: bne         $a0, $t1, L_800A227C
    if (ctx->r4 != ctx->r9) {
        // 0x800A2350: nop
    
            goto L_800A227C;
    }
    // 0x800A2350: nop

L_800A2354:
    // 0x800A2354: bne         $a1, $t2, L_800A2370
    if (ctx->r5 != ctx->r10) {
        // 0x800A2358: nop
    
            goto L_800A2370;
    }
    // 0x800A2358: nop

    // 0x800A235C: b           L_800A237C
    // 0x800A2360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A237C;
    // 0x800A2360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2364: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800A2368:
    // 0x800A2368: jal         0x800A469C
    // 0x800A236C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_bananas(rdram, ctx);
        goto after_5;
    // 0x800A236C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
L_800A2370:
    // 0x800A2370: jal         0x80068748
    // 0x800A2374: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_6;
    // 0x800A2374: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800A2378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A237C:
    // 0x800A237C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A2380: jr          $ra
    // 0x800A2384: nop

    return;
    // 0x800A2384: nop

;}
RECOMP_FUNC void rand_range(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB8C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006FB90: lw          $t0, -0x265C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X265C);
    // 0x8006FB94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006FB98: sub         $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // 0x8006FB9C: dsll32      $t1, $t0, 31
    ctx->r9 = ctx->r8 << (31 + 32);
    // 0x8006FBA0: dsll        $t2, $t0, 31
    ctx->r10 = ctx->r8 << 31;
    // 0x8006FBA4: dsrl        $t1, $t1, 31
    ctx->r9 = ctx->r9 >> 31;
    // 0x8006FBA8: dsrl32      $t2, $t2, 0
    ctx->r10 = ctx->r10 >> (0 + 32);
    // 0x8006FBAC: dsll32      $t3, $t0, 12
    ctx->r11 = ctx->r8 << (12 + 32);
    // 0x8006FBB0: or          $t1, $t1, $t2
    ctx->r9 = ctx->r9 | ctx->r10;
    // 0x8006FBB4: dsrl32      $t3, $t3, 0
    ctx->r11 = ctx->r11 >> (0 + 32);
    // 0x8006FBB8: xor         $t1, $t1, $t3
    ctx->r9 = ctx->r9 ^ ctx->r11;
    // 0x8006FBBC: dsrl        $t3, $t1, 20
    ctx->r11 = ctx->r9 >> 20;
    // 0x8006FBC0: andi        $t3, $t3, 0xFFF
    ctx->r11 = ctx->r11 & 0XFFF;
    // 0x8006FBC4: xor         $t0, $t3, $t1
    ctx->r8 = ctx->r11 ^ ctx->r9;
    // 0x8006FBC8: sw          $t0, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = ctx->r8;
    // 0x8006FBCC: addi        $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006FBD0: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8006FBD4: divu        $zero, $t0, $a1
    lo = S32(U32(ctx->r8) / U32(ctx->r5)); hi = S32(U32(ctx->r8) % U32(ctx->r5));
    // 0x8006FBD8: mflo        $t0
    ctx->r8 = lo;
    // 0x8006FBDC: mfhi        $v0
    ctx->r2 = hi;
    // 0x8006FBE0: add         $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006FBE4: bne         $a1, $zero, L_8006FBF0
    if (ctx->r5 != 0) {
        // 0x8006FBE8: nop
    
            goto L_8006FBF0;
    }
    // 0x8006FBE8: nop

    // 0x8006FBEC: break       7
    do_break(2147941356);
L_8006FBF0:
    // 0x8006FBF0: jr          $ra
    // 0x8006FBF4: nop

    return;
    // 0x8006FBF4: nop

;}
RECOMP_FUNC void is_player_two_in_control(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E184: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E188: lb          $v0, -0x3348($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X3348);
    // 0x8000E18C: jr          $ra
    // 0x8000E190: nop

    return;
    // 0x8000E190: nop

;}
RECOMP_FUNC void obj_init_checkpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ACFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003AD00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AD04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003AD08: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003AD0C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003AD10: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003AD14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003AD18: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003AD1C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003AD20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003AD24: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003AD28: nop

    // 0x8003AD2C: bc1f        L_8003AD3C
    if (!c1cs) {
        // 0x8003AD30: nop
    
            goto L_8003AD3C;
    }
    // 0x8003AD30: nop

    // 0x8003AD34: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003AD38: nop

L_8003AD3C:
    // 0x8003AD3C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003AD40: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8003AD44: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x8003AD48: nop

    // 0x8003AD4C: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x8003AD50: jal         0x80011390
    // 0x8003AD54: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    path_enable(rdram, ctx);
        goto after_0;
    // 0x8003AD54: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    after_0:
    // 0x8003AD58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AD5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003AD60: jr          $ra
    // 0x8003AD64: nop

    return;
    // 0x8003AD64: nop

;}
RECOMP_FUNC void directional_lighting_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B8A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B8A8: sh          $zero, 0x6924($at)
    MEM_H(0X6924, ctx->r1) = 0;
    // 0x8007B8AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B8B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007B8B4: jr          $ra
    // 0x8007B8B8: sh          $t6, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r14;
    return;
    // 0x8007B8B8: sh          $t6, 0x6922($at)
    MEM_H(0X6922, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void menu_options_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084794: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084798: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008479C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800847A0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800847A4: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x800847A8: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800847AC: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800847B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800847B4: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x800847B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800847BC: beq         $v0, $zero, L_800847E4
    if (ctx->r2 == 0) {
        // 0x800847C0: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_800847E4;
    }
    // 0x800847C0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800847C4: blez        $v0, L_800847DC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800847C8: subu        $t2, $v0, $a0
        ctx->r10 = SUB32(ctx->r2, ctx->r4);
            goto L_800847DC;
    }
    // 0x800847C8: subu        $t2, $v0, $a0
    ctx->r10 = SUB32(ctx->r2, ctx->r4);
    // 0x800847CC: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x800847D0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800847D4: b           L_800847E4
    // 0x800847D8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800847E4;
    // 0x800847D8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800847DC:
    // 0x800847DC: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800847E0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800847E4:
    // 0x800847E4: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x800847E8: bne         $at, $zero, L_80084808
    if (ctx->r1 != 0) {
        // 0x800847EC: slti        $at, $v0, 0x23
        ctx->r1 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
            goto L_80084808;
    }
    // 0x800847EC: slti        $at, $v0, 0x23
    ctx->r1 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
    // 0x800847F0: beq         $at, $zero, L_80084808
    if (ctx->r1 == 0) {
        // 0x800847F4: nop
    
            goto L_80084808;
    }
    // 0x800847F4: nop

    // 0x800847F8: jal         0x800845F0
    // 0x800847FC: nop

    optionscreen_render(rdram, ctx);
        goto after_0;
    // 0x800847FC: nop

    after_0:
    // 0x80084800: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084804: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80084808:
    // 0x80084808: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008480C: lw          $t3, 0x6964($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6964);
    // 0x80084810: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084814: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80084818: bne         $t3, $zero, L_800848A0
    if (ctx->r11 != 0) {
        // 0x8008481C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800848A0;
    }
    // 0x8008481C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80084820: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80084824: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084828: bne         $t4, $zero, L_800848A0
    if (ctx->r12 != 0) {
        // 0x8008482C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800848A0;
    }
    // 0x8008482C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80084830: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084834: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x80084838: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
L_8008483C:
    // 0x8008483C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80084840: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80084844: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80084848: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x8008484C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80084850: jal         0x8006A794
    // 0x80084854: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x80084854: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_1:
    // 0x80084858: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8008485C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80084860: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80084864: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80084868: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8008486C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80084870: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x80084874: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x80084878: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008487C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80084880: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80084884: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80084888: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x8008488C: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x80084890: bne         $a0, $at, L_8008483C
    if (ctx->r4 != ctx->r1) {
        // 0x80084894: addu        $t0, $t0, $t6
        ctx->r8 = ADD32(ctx->r8, ctx->r14);
            goto L_8008483C;
    }
    // 0x80084894: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x80084898: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008489C: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_800848A0:
    // 0x800848A0: andi        $t7, $a2, 0x4000
    ctx->r15 = ctx->r6 & 0X4000;
    // 0x800848A4: bne         $t7, $zero, L_800848C8
    if (ctx->r15 != 0) {
        // 0x800848A8: andi        $v1, $a2, 0x9000
        ctx->r3 = ctx->r6 & 0X9000;
            goto L_800848C8;
    }
    // 0x800848A8: andi        $v1, $a2, 0x9000
    ctx->r3 = ctx->r6 & 0X9000;
    // 0x800848AC: beq         $v1, $zero, L_80084908
    if (ctx->r3 == 0) {
        // 0x800848B0: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_80084908;
    }
    // 0x800848B0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800848B4: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x800848B8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800848BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800848C0: bne         $t8, $at, L_80084908
    if (ctx->r24 != ctx->r1) {
        // 0x800848C4: nop
    
            goto L_80084908;
    }
    // 0x800848C4: nop

L_800848C8:
    // 0x800848C8: jal         0x80000C98
    // 0x800848CC: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_2;
    // 0x800848CC: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_2:
    // 0x800848D0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800848D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800848D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800848DC: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
    // 0x800848E0: jal         0x800C06F8
    // 0x800848E4: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x800848E4: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_3:
    // 0x800848E8: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800848EC: jal         0x80001D04
    // 0x800848F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800848F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800848F4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800848F8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800848FC: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x80084900: b           L_80084AB0
    // 0x80084904: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
        goto L_80084AB0;
    // 0x80084904: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80084908:
    // 0x80084908: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008490C: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x80084910: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80084914: beq         $v1, $zero, L_80084948
    if (ctx->r3 == 0) {
        // 0x80084918: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80084948;
    }
    // 0x80084918: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8008491C: bne         $at, $zero, L_80084948
    if (ctx->r1 != 0) {
        // 0x80084920: addiu       $t2, $zero, 0x1F
        ctx->r10 = ADD32(0, 0X1F);
            goto L_80084948;
    }
    // 0x80084920: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x80084924: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80084928: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008492C: jal         0x80001D04
    // 0x80084930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x80084930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80084934: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084938: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008493C: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x80084940: b           L_80084AB0
    // 0x80084944: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
        goto L_80084AB0;
    // 0x80084944: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80084948:
    // 0x80084948: bne         $v0, $zero, L_800849AC
    if (ctx->r2 != 0) {
        // 0x8008494C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800849AC;
    }
    // 0x8008494C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80084950: beq         $a3, $zero, L_800849AC
    if (ctx->r7 == 0) {
        // 0x80084954: nop
    
            goto L_800849AC;
    }
    // 0x80084954: nop

    // 0x80084958: jal         0x8009F064
    // 0x8008495C: nop

    get_language(rdram, ctx);
        goto after_6;
    // 0x8008495C: nop

    after_6:
    // 0x80084960: sra         $t4, $v0, 31
    ctx->r12 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80084964: bne         $t4, $zero, L_80084984
    if (ctx->r12 != 0) {
        // 0x80084968: nop
    
            goto L_80084984;
    }
    // 0x80084968: nop

    // 0x8008496C: bne         $v0, $zero, L_80084984
    if (ctx->r2 != 0) {
        // 0x80084970: nop
    
            goto L_80084984;
    }
    // 0x80084970: nop

    // 0x80084974: jal         0x8009F0D8
    // 0x80084978: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_language(rdram, ctx);
        goto after_7;
    // 0x80084978: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x8008497C: b           L_80084990
    // 0x80084980: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
        goto L_80084990;
    // 0x80084980: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
L_80084984:
    // 0x80084984: jal         0x8009F0D8
    // 0x80084988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_language(rdram, ctx);
        goto after_8;
    // 0x80084988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x8008498C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
L_80084990:
    // 0x80084990: jal         0x80001D04
    // 0x80084994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x80084994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80084998: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008499C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800849A0: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x800849A4: b           L_80084AB0
    // 0x800849A8: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
        goto L_80084AB0;
    // 0x800849A8: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_800849AC:
    // 0x800849AC: bne         $v0, $at, L_80084A50
    if (ctx->r2 != ctx->r1) {
        // 0x800849B0: nop
    
            goto L_80084A50;
    }
    // 0x800849B0: nop

    // 0x800849B4: beq         $a3, $zero, L_80084A50
    if (ctx->r7 == 0) {
        // 0x800849B8: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80084A50;
    }
    // 0x800849B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800849BC: lw          $t7, 0x69EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69EC);
    // 0x800849C0: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800849C4: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x800849C8: beq         $t9, $zero, L_80084A08
    if (ctx->r25 == 0) {
        // 0x800849CC: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80084A08;
    }
    // 0x800849CC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800849D0: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800849D4: jal         0x80001D04
    // 0x800849D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800849D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x800849DC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x800849E0: jal         0x8009F000
    // 0x800849E4: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    unset_eeprom_settings_value(rdram, ctx);
        goto after_11;
    // 0x800849E4: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    after_11:
    // 0x800849E8: jal         0x800C3014
    // 0x800849EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_subtitles(rdram, ctx);
        goto after_12;
    // 0x800849EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x800849F0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800849F4: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x800849F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800849FC: lw          $t2, 0x2DC($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X2DC);
    // 0x80084A00: b           L_80084A3C
    // 0x80084A04: sw          $t2, -0x6C($at)
    MEM_W(-0X6C, ctx->r1) = ctx->r10;
        goto L_80084A3C;
    // 0x80084A04: sw          $t2, -0x6C($at)
    MEM_W(-0X6C, ctx->r1) = ctx->r10;
L_80084A08:
    // 0x80084A08: jal         0x80001D04
    // 0x80084A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x80084A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80084A10: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80084A14: jal         0x8009EFBC
    // 0x80084A18: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    set_eeprom_settings_value(rdram, ctx);
        goto after_14;
    // 0x80084A18: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    after_14:
    // 0x80084A1C: jal         0x800C3014
    // 0x80084A20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_subtitles(rdram, ctx);
        goto after_15;
    // 0x80084A20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x80084A24: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80084A28: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x80084A2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084A30: lw          $t5, 0x2D8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2D8);
    // 0x80084A34: nop

    // 0x80084A38: sw          $t5, -0x6C($at)
    MEM_W(-0X6C, ctx->r1) = ctx->r13;
L_80084A3C:
    // 0x80084A3C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084A40: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084A44: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x80084A48: b           L_80084AB0
    // 0x80084A4C: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
        goto L_80084AB0;
    // 0x80084A4C: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80084A50:
    // 0x80084A50: bgez        $t0, L_80084A74
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80084A54: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80084A74;
    }
    // 0x80084A54: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80084A58: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80084A5C: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x80084A60: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80084A64: bne         $at, $zero, L_80084A74
    if (ctx->r1 != 0) {
        // 0x80084A68: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80084A74;
    }
    // 0x80084A68: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80084A6C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80084A70: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80084A74:
    // 0x80084A74: blez        $t0, L_80084A90
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80084A78: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80084A90;
    }
    // 0x80084A78: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80084A7C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80084A80: bgez        $t8, L_80084A90
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80084A84: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80084A90;
    }
    // 0x80084A84: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80084A88: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80084A8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084A90:
    // 0x80084A90: beq         $v1, $v0, L_80084AB0
    if (ctx->r3 == ctx->r2) {
        // 0x80084A94: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80084AB0;
    }
    // 0x80084A94: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80084A98: jal         0x80001D04
    // 0x80084A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_16;
    // 0x80084A9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80084AA0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80084AA4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084AA8: addiu       $a2, $a2, -0x620
    ctx->r6 = ADD32(ctx->r6, -0X620);
    // 0x80084AAC: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80084AB0:
    // 0x80084AB0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80084AB4: nop

    // 0x80084AB8: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80084ABC: bne         $at, $zero, L_80084B2C
    if (ctx->r1 != 0) {
        // 0x80084AC0: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_80084B2C;
    }
    // 0x80084AC0: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x80084AC4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80084AC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80084ACC: bne         $v0, $at, L_80084AF0
    if (ctx->r2 != ctx->r1) {
        // 0x80084AD0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80084AF0;
    }
    // 0x80084AD0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80084AD4: jal         0x80084B6C
    // 0x80084AD8: nop

    optionscreen_free(rdram, ctx);
        goto after_17;
    // 0x80084AD8: nop

    after_17:
    // 0x80084ADC: jal         0x80081820
    // 0x80084AE0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    menu_init(rdram, ctx);
        goto after_18;
    // 0x80084AE0: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_18:
    // 0x80084AE4: b           L_80084B5C
    // 0x80084AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084B5C;
    // 0x80084AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80084AEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80084AF0:
    // 0x80084AF0: bne         $v0, $at, L_80084B10
    if (ctx->r2 != ctx->r1) {
        // 0x80084AF4: nop
    
            goto L_80084B10;
    }
    // 0x80084AF4: nop

    // 0x80084AF8: jal         0x80084B6C
    // 0x80084AFC: nop

    optionscreen_free(rdram, ctx);
        goto after_19;
    // 0x80084AFC: nop

    after_19:
    // 0x80084B00: jal         0x80081820
    // 0x80084B04: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    menu_init(rdram, ctx);
        goto after_20;
    // 0x80084B04: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_20:
    // 0x80084B08: b           L_80084B5C
    // 0x80084B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084B5C;
    // 0x80084B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084B10:
    // 0x80084B10: jal         0x80084B6C
    // 0x80084B14: nop

    optionscreen_free(rdram, ctx);
        goto after_21;
    // 0x80084B14: nop

    after_21:
    // 0x80084B18: jal         0x80081820
    // 0x80084B1C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    menu_init(rdram, ctx);
        goto after_22;
    // 0x80084B1C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_22:
    // 0x80084B20: b           L_80084B5C
    // 0x80084B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084B5C;
    // 0x80084B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80084B28: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
L_80084B2C:
    // 0x80084B2C: beq         $at, $zero, L_80084B54
    if (ctx->r1 == 0) {
        // 0x80084B30: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80084B54;
    }
    // 0x80084B30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80084B34: jal         0x80000B28
    // 0x80084B38: nop

    music_change_on(rdram, ctx);
        goto after_23;
    // 0x80084B38: nop

    after_23:
    // 0x80084B3C: jal         0x80084B6C
    // 0x80084B40: nop

    optionscreen_free(rdram, ctx);
        goto after_24;
    // 0x80084B40: nop

    after_24:
    // 0x80084B44: jal         0x80081820
    // 0x80084B48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    menu_init(rdram, ctx);
        goto after_25;
    // 0x80084B48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_25:
    // 0x80084B4C: b           L_80084B5C
    // 0x80084B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80084B5C;
    // 0x80084B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80084B54:
    // 0x80084B54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084B58: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_80084B5C:
    // 0x80084B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084B60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80084B64: jr          $ra
    // 0x80084B68: nop

    return;
    // 0x80084B68: nop

;}
RECOMP_FUNC void update_smokey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D9C0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005D9C4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8005D9C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005D9CC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005D9D0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005D9D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D9D8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005D9DC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005D9E0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005D9E4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005D9E8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8005D9EC: jal         0x8005CC18
    // 0x8005D9F0: addiu       $a0, $a0, -0x2C70
    ctx->r4 = ADD32(ctx->r4, -0X2C70);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005D9F0: addiu       $a0, $a0, -0x2C70
    ctx->r4 = ADD32(ctx->r4, -0X2C70);
    after_0:
    // 0x8005D9F4: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D9F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D9FC: sh          $t6, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r14;
    // 0x8005DA00: lh          $t7, 0x16A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X16A);
    // 0x8005DA04: lh          $t2, 0x18($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X18);
    // 0x8005DA08: sh          $t7, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r15;
    // 0x8005DA0C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005DA10: lwc1        $f7, 0x6FE0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6FE0);
    // 0x8005DA14: lwc1        $f6, 0x6FE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6FE4);
    // 0x8005DA18: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DA1C: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8005DA20: nop

    // 0x8005DA24: bc1f        L_8005DA4C
    if (!c1cs) {
        // 0x8005DA28: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005DA4C;
    }
    // 0x8005DA28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DA2C: lwc1        $f9, 0x6FE8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6FE8);
    // 0x8005DA30: lwc1        $f8, 0x6FEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FEC);
    // 0x8005DA34: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8005DA38: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005DA3C: nop

    // 0x8005DA40: bc1f        L_8005DA4C
    if (!c1cs) {
        // 0x8005DA44: nop
    
            goto L_8005DA4C;
    }
    // 0x8005DA44: nop

    // 0x8005DA48: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_8005DA4C:
    // 0x8005DA4C: lb          $t9, 0x1D8($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005DA50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DA54: bne         $t9, $at, L_8005DA8C
    if (ctx->r25 != ctx->r1) {
        // 0x8005DA58: lw          $t0, 0x78($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X78);
            goto L_8005DA8C;
    }
    // 0x8005DA58: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005DA5C: jal         0x8002359C
    // 0x8005DA60: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005DA60: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    after_1:
    // 0x8005DA64: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005DA68: beq         $v0, $zero, L_8005DA88
    if (ctx->r2 == 0) {
        // 0x8005DA6C: addiu       $a0, $zero, 0x82
        ctx->r4 = ADD32(0, 0X82);
            goto L_8005DA88;
    }
    // 0x8005DA6C: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    // 0x8005DA70: jal         0x80021434
    // 0x8005DA74: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005DA74: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    after_2:
    // 0x8005DA78: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005DA7C: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005DA80: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8005DA84: sb          $t4, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r12;
L_8005DA88:
    // 0x8005DA88: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
L_8005DA8C:
    // 0x8005DA8C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005DA90: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8005DA94: nop

    // 0x8005DA98: bne         $v1, $a0, L_8005DAA4
    if (ctx->r3 != ctx->r4) {
        // 0x8005DA9C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005DAA4;
    }
    // 0x8005DA9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005DAA0: sb          $zero, -0x24A0($at)
    MEM_B(-0X24A0, ctx->r1) = 0;
L_8005DAA4:
    // 0x8005DAA4: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x8005DAA8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005DAAC: bne         $t1, $t5, L_8005DB34
    if (ctx->r9 != ctx->r13) {
        // 0x8005DAB0: addiu       $t6, $zero, 0x7
        ctx->r14 = ADD32(0, 0X7);
            goto L_8005DB34;
    }
    // 0x8005DAB0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8005DAB4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005DAB8: nop

    // 0x8005DABC: beq         $a0, $v0, L_8005DB30
    if (ctx->r4 == ctx->r2) {
        // 0x8005DAC0: addiu       $t6, $v0, -0x3C
        ctx->r14 = ADD32(ctx->r2, -0X3C);
            goto L_8005DB30;
    }
    // 0x8005DAC0: addiu       $t6, $v0, -0x3C
    ctx->r14 = ADD32(ctx->r2, -0X3C);
    // 0x8005DAC4: bgez        $t6, L_8005DB28
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8005DAC8: sw          $t6, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r14;
            goto L_8005DB28;
    }
    // 0x8005DAC8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8005DACC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005DAD0: lb          $t8, -0x249F($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X249F);
    // 0x8005DAD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005DAD8: bne         $t8, $zero, L_8005DB04
    if (ctx->r24 != 0) {
        // 0x8005DADC: lw          $v0, 0x70($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X70);
            goto L_8005DB04;
    }
    // 0x8005DADC: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8005DAE0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8005DAE4: jal         0x8005CCA4
    // 0x8005DAE8: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005DAE8: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    after_3:
    // 0x8005DAEC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8005DAF0: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005DAF4: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005DAF8: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8005DAFC: sb          $t9, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r25;
    // 0x8005DB00: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
L_8005DB04:
    // 0x8005DB04: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005DB08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005DB0C: sb          $t3, -0x249F($at)
    MEM_B(-0X249F, ctx->r1) = ctx->r11;
    // 0x8005DB10: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8005DB14: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8005DB18: nop

    // 0x8005DB1C: ori         $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 | 0X8000;
    // 0x8005DB20: b           L_8005DB30
    // 0x8005DB24: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_8005DB30;
    // 0x8005DB24: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8005DB28:
    // 0x8005DB28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005DB2C: sb          $zero, -0x249F($at)
    MEM_B(-0X249F, ctx->r1) = 0;
L_8005DB30:
    // 0x8005DB30: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
L_8005DB34:
    // 0x8005DB34: sb          $t6, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r14;
    // 0x8005DB38: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8005DB3C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005DB40: sh          $t2, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r10;
    // 0x8005DB44: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8005DB48: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005DB4C: jal         0x800497D4
    // 0x8005DB50: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80049794(rdram, ctx);
        goto after_4;
    // 0x8005DB50: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8005DB54: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8005DB58: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8005DB5C: lb          $t7, 0x1D7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D7);
    // 0x8005DB60: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005DB64: sb          $t7, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r15;
    // 0x8005DB68: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8005DB6C: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005DB70: lh          $t8, 0x5A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5A);
    // 0x8005DB74: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005DB78: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005DB7C: lh          $t9, 0x5E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5E);
    // 0x8005DB80: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005DB84: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005DB88: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005DB8C: nop

    // 0x8005DB90: beq         $t3, $zero, L_8005DC34
    if (ctx->r11 == 0) {
        // 0x8005DB94: nop
    
            goto L_8005DC34;
    }
    // 0x8005DB94: nop

    // 0x8005DB98: lb          $t4, 0x3B($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DB9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005DBA0: beq         $t4, $at, L_8005DC34
    if (ctx->r12 == ctx->r1) {
        // 0x8005DBA4: nop
    
            goto L_8005DC34;
    }
    // 0x8005DBA4: nop

    // 0x8005DBA8: jal         0x8005CCA4
    // 0x8005DBAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005DBAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8005DBB0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005DBB4: jal         0x80001D04
    // 0x8005DBB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005DBB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005DBBC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005DBC0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005DBC4: jal         0x8006A168
    // 0x8005DBC8: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005DBC8: nop

    after_7:
    // 0x8005DBCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DBD0: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005DBD4: lwc1        $f1, 0x6FF0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6FF0);
    // 0x8005DBD8: lwc1        $f0, 0x6FF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6FF4);
    // 0x8005DBDC: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005DBE0: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8005DBE4: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005DBE8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005DBEC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005DBF0: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8005DBF4: mul.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8005DBF8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005DBFC: sb          $t5, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r13;
    // 0x8005DC00: swc1        $f6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f6.u32l;
    // 0x8005DC04: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8005DC08: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005DC0C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005DC10: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x8005DC14: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005DC18: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005DC1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005DC20: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005DC24: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x8005DC28: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005DC2C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005DC30: swc1        $f4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f4.u32l;
L_8005DC34:
    // 0x8005DC34: lw          $t6, 0x148($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X148);
    // 0x8005DC38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005DC3C: beq         $t6, $zero, L_8005DCA8
    if (ctx->r14 == 0) {
        // 0x8005DC40: sb          $zero, 0x187($s0)
        MEM_B(0X187, ctx->r16) = 0;
            goto L_8005DCA8;
    }
    // 0x8005DC40: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005DC44: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005DC48: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005DC4C: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005DC50: nop

    // 0x8005DC54: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005DC58: nop

    // 0x8005DC5C: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005DC60: nop

    // 0x8005DC64: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005DC68: jal         0x800CA030
    // 0x8005DC6C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005DC6C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_8:
    // 0x8005DC70: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x8005DC74: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005DC78: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005DC7C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8005DC80: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x8005DC84: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8005DC88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005DC8C: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8005DC90: bc1f        L_8005DCA8
    if (!c1cs) {
        // 0x8005DC94: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_8005DCA8;
    }
    // 0x8005DC94: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005DC98: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x8005DC9C: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
    // 0x8005DCA0: swc1        $f16, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f16.u32l;
    // 0x8005DCA4: swc1        $f16, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f16.u32l;
L_8005DCA8:
    // 0x8005DCA8: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    // 0x8005DCAC: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DCB0: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8005DCB4: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8005DCB8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8005DCBC: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005DCC0: lw          $t8, 0x44($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X44);
    // 0x8005DCC4: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005DCC8: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8005DCCC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8005DCD0: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8005DCD4: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8005DCD8: addiu       $t6, $t5, -0x11
    ctx->r14 = ADD32(ctx->r13, -0X11);
    // 0x8005DCDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DCE0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8005DCE4: lwc1        $f19, 0x6FF8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6FF8);
    // 0x8005DCE8: lwc1        $f18, 0x6FFC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6FFC);
    // 0x8005DCEC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005DCF0: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005DCF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005DCF8: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8005DCFC: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8005DD00: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x8005DD04: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8005DD08: c.le.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d <= ctx->f6.d;
    // 0x8005DD0C: nop

    // 0x8005DD10: bc1f        L_8005DD40
    if (!c1cs) {
        // 0x8005DD14: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_8005DD40;
    }
    // 0x8005DD14: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005DD18: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005DD1C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005DD20: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005DD24: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8005DD28: nop

    // 0x8005DD2C: bc1f        L_8005DD68
    if (!c1cs) {
        // 0x8005DD30: nop
    
            goto L_8005DD68;
    }
    // 0x8005DD30: nop

    // 0x8005DD34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005DD38: b           L_8005DD6C
    // 0x8005DD3C: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
        goto L_8005DD6C;
    // 0x8005DD3C: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005DD40:
    // 0x8005DD40: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005DD44: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005DD48: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005DD4C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005DD50: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8005DD54: nop

    // 0x8005DD58: bc1f        L_8005DD68
    if (!c1cs) {
        // 0x8005DD5C: nop
    
            goto L_8005DD68;
    }
    // 0x8005DD5C: nop

    // 0x8005DD60: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005DD64: nop

L_8005DD68:
    // 0x8005DD68: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
L_8005DD6C:
    // 0x8005DD6C: beq         $at, $zero, L_8005DEAC
    if (ctx->r1 == 0) {
        // 0x8005DD70: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8005DEAC;
    }
    // 0x8005DD70: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8005DD74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DD78: addu        $at, $at, $t7
    gpr jr_addend_8005DD84 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005DD7C: lw          $t7, 0x7000($at)
    ctx->r15 = ADD32(ctx->r1, 0X7000);
    // 0x8005DD80: nop

    // 0x8005DD84: jr          $t7
    // 0x8005DD88: nop

    switch (jr_addend_8005DD84 >> 2) {
        case 0: goto L_8005DD8C; break;
        case 1: goto L_8005DDB0; break;
        case 2: goto L_8005DDE8; break;
        case 3: goto L_8005DE04; break;
        case 4: goto L_8005DE5C; break;
        case 5: goto L_8005DE88; break;
        default: switch_error(__func__, 0x8005DD84, 0x800E7000);
    }
    // 0x8005DD88: nop

L_8005DD8C:
    // 0x8005DD8C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DD90: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DD94: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8005DD98: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8005DD9C: sb          $zero, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = 0;
    // 0x8005DDA0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8005DDA4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DDA8: b           L_8005DEB0
    // 0x8005DDAC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005DEB0;
    // 0x8005DDAC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005DDB0:
    // 0x8005DDB0: lbu         $t8, 0x1CD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DDB4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DDB8: bne         $a0, $t8, L_8005DDD4
    if (ctx->r4 != ctx->r24) {
        // 0x8005DDBC: nop
    
            goto L_8005DDD4;
    }
    // 0x8005DDBC: nop

    // 0x8005DDC0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DDC4: nop

    // 0x8005DDC8: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8005DDCC: b           L_8005DEB0
    // 0x8005DDD0: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_8005DEB0;
    // 0x8005DDD0: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005DDD4:
    // 0x8005DDD4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DDD8: nop

    // 0x8005DDDC: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8005DDE0: b           L_8005DEB0
    // 0x8005DDE4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8005DEB0;
    // 0x8005DDE4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_8005DDE8:
    // 0x8005DDE8: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DDEC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8005DDF0: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8005DDF4: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x8005DDF8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005DDFC: b           L_8005DEB0
    // 0x8005DE00: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005DEB0;
    // 0x8005DE00: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005DE04:
    // 0x8005DE04: lbu         $t3, 0x1CD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DE08: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005DE0C: bne         $t3, $at, L_8005DE38
    if (ctx->r11 != ctx->r1) {
        // 0x8005DE10: nop
    
            goto L_8005DE38;
    }
    // 0x8005DE10: nop

    // 0x8005DE14: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DE18: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DE1C: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DE20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DE24: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DE28: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8005DE2C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DE30: b           L_8005DEB0
    // 0x8005DE34: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005DEB0;
    // 0x8005DE34: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005DE38:
    // 0x8005DE38: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DE3C: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DE40: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DE44: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DE48: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005DE4C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DE50: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005DE54: b           L_8005DEB0
    // 0x8005DE58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8005DEB0;
    // 0x8005DE58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005DE5C:
    // 0x8005DE5C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DE60: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DE64: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DE68: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005DE6C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DE70: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005DE74: sb          $t4, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r12;
    // 0x8005DE78: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DE7C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DE80: b           L_8005DEB0
    // 0x8005DE84: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005DEB0;
    // 0x8005DE84: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005DE88:
    // 0x8005DE88: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DE8C: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8005DE90: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8005DE94: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8005DE98: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005DE9C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005DEA0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005DEA4: b           L_8005DEB0
    // 0x8005DEA8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005DEB0;
    // 0x8005DEA8: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005DEAC:
    // 0x8005DEAC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005DEB0:
    // 0x8005DEB0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DEB4: nop

    // 0x8005DEB8: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x8005DEBC: nop

    // 0x8005DEC0: bc1f        L_8005DEEC
    if (!c1cs) {
        // 0x8005DEC4: nop
    
            goto L_8005DEEC;
    }
    // 0x8005DEC4: nop

L_8005DEC8:
    // 0x8005DEC8: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005DECC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005DED0: sh          $t1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r9;
    // 0x8005DED4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DED8: nop

    // 0x8005DEDC: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x8005DEE0: nop

    // 0x8005DEE4: bc1t        L_8005DEC8
    if (c1cs) {
        // 0x8005DEE8: nop
    
            goto L_8005DEC8;
    }
    // 0x8005DEE8: nop

L_8005DEEC:
    // 0x8005DEEC: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8005DEF0: nop

    // 0x8005DEF4: bc1f        L_8005DF20
    if (!c1cs) {
        // 0x8005DEF8: nop
    
            goto L_8005DF20;
    }
    // 0x8005DEF8: nop

L_8005DEFC:
    // 0x8005DEFC: add.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005DF00: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005DF04: sh          $t1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r9;
    // 0x8005DF08: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005DF0C: nop

    // 0x8005DF10: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8005DF14: nop

    // 0x8005DF18: bc1t        L_8005DEFC
    if (c1cs) {
        // 0x8005DF1C: nop
    
            goto L_8005DEFC;
    }
    // 0x8005DF1C: nop

L_8005DF20:
    // 0x8005DF20: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DF24: nop

    // 0x8005DF28: bne         $a0, $v1, L_8005DF70
    if (ctx->r4 != ctx->r3) {
        // 0x8005DF2C: nop
    
            goto L_8005DF70;
    }
    // 0x8005DF2C: nop

    // 0x8005DF30: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005DF34: lui         $at, 0xC01A
    ctx->r1 = S32(0XC01A << 16);
    // 0x8005DF38: bne         $t5, $zero, L_8005DF70
    if (ctx->r13 != 0) {
        // 0x8005DF3C: nop
    
            goto L_8005DF70;
    }
    // 0x8005DF3C: nop

    // 0x8005DF40: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005DF44: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005DF48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005DF4C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8005DF50: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8005DF54: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8005DF58: bc1f        L_8005DF70
    if (!c1cs) {
        // 0x8005DF5C: nop
    
            goto L_8005DF70;
    }
    // 0x8005DF5C: nop

    // 0x8005DF60: sb          $a2, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r6;
    // 0x8005DF64: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005DF68: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DF6C: nop

L_8005DF70:
    // 0x8005DF70: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x8005DF74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8005DF78: beq         $t1, $t6, L_8005DF88
    if (ctx->r9 == ctx->r14) {
        // 0x8005DF7C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005DF88;
    }
    // 0x8005DF7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005DF80: bne         $v1, $zero, L_8005E12C
    if (ctx->r3 != 0) {
        // 0x8005DF84: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005E12C;
    }
    // 0x8005DF84: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8005DF88:
    // 0x8005DF88: bne         $v1, $at, L_8005DFB0
    if (ctx->r3 != ctx->r1) {
        // 0x8005DF8C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005DFB0;
    }
    // 0x8005DF8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005DF90: lbu         $t7, 0x1CD($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DF94: nop

    // 0x8005DF98: sb          $t7, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r15;
    // 0x8005DF9C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005DFA0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DFA4: b           L_8005E130
    // 0x8005DFA8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005E130;
    // 0x8005DFA8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8005DFAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8005DFB0:
    // 0x8005DFB0: bne         $v1, $at, L_8005DFE0
    if (ctx->r3 != ctx->r1) {
        // 0x8005DFB4: nop
    
            goto L_8005DFE0;
    }
    // 0x8005DFB4: nop

    // 0x8005DFB8: lbu         $t8, 0x1CD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DFBC: nop

    // 0x8005DFC0: bne         $t8, $zero, L_8005DFD0
    if (ctx->r24 != 0) {
        // 0x8005DFC4: nop
    
            goto L_8005DFD0;
    }
    // 0x8005DFC4: nop

    // 0x8005DFC8: b           L_8005DFD4
    // 0x8005DFCC: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005DFD4;
    // 0x8005DFCC: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005DFD0:
    // 0x8005DFD0: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005DFD4:
    // 0x8005DFD4: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005DFD8: b           L_8005E130
    // 0x8005DFDC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005E130;
    // 0x8005DFDC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005DFE0:
    // 0x8005DFE0: bne         $a2, $v1, L_8005E010
    if (ctx->r6 != ctx->r3) {
        // 0x8005DFE4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005E010;
    }
    // 0x8005DFE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005DFE8: lbu         $t9, 0x1CD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005DFEC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005DFF0: bne         $t9, $at, L_8005E000
    if (ctx->r25 != ctx->r1) {
        // 0x8005DFF4: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_8005E000;
    }
    // 0x8005DFF4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8005DFF8: b           L_8005E004
    // 0x8005DFFC: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
        goto L_8005E004;
    // 0x8005DFFC: sb          $a0, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r4;
L_8005E000:
    // 0x8005E000: sb          $t3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r11;
L_8005E004:
    // 0x8005E004: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E008: b           L_8005E130
    // 0x8005E00C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005E130;
    // 0x8005E00C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005E010:
    // 0x8005E010: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005E014: lwc1        $f7, 0x7018($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X7018);
    // 0x8005E018: lwc1        $f6, 0x701C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X701C);
    // 0x8005E01C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005E020: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8005E024: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005E028: bc1f        L_8005E09C
    if (!c1cs) {
        // 0x8005E02C: nop
    
            goto L_8005E09C;
    }
    // 0x8005E02C: nop

    // 0x8005E030: lwc1        $f9, 0x7020($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X7020);
    // 0x8005E034: lwc1        $f8, 0x7024($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7024);
    // 0x8005E038: nop

    // 0x8005E03C: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005E040: nop

    // 0x8005E044: bc1f        L_8005E09C
    if (!c1cs) {
        // 0x8005E048: nop
    
            goto L_8005E09C;
    }
    // 0x8005E048: nop

    // 0x8005E04C: bne         $a0, $v1, L_8005E08C
    if (ctx->r4 != ctx->r3) {
        // 0x8005E050: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8005E08C;
    }
    // 0x8005E050: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005E054: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005E058: lb          $t6, 0x3B($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E05C: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x8005E060: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8005E064: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8005E068: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8005E06C: nop

    // 0x8005E070: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8005E074: addiu       $t4, $t3, -0x11
    ctx->r12 = ADD32(ctx->r11, -0X11);
    // 0x8005E078: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8005E07C: nop

    // 0x8005E080: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005E084: b           L_8005E090
    // 0x8005E088: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005E090;
    // 0x8005E088: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005E08C:
    // 0x8005E08C: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
L_8005E090:
    // 0x8005E090: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E094: b           L_8005E130
    // 0x8005E098: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
        goto L_8005E130;
    // 0x8005E098: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005E09C:
    // 0x8005E09C: bne         $v1, $zero, L_8005E0B8
    if (ctx->r3 != 0) {
        // 0x8005E0A0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005E0B8;
    }
    // 0x8005E0A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005E0A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005E0A8: sb          $t6, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r14;
    // 0x8005E0AC: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005E0B0: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E0B4: nop

L_8005E0B8:
    // 0x8005E0B8: bne         $v1, $at, L_8005E12C
    if (ctx->r3 != ctx->r1) {
        // 0x8005E0BC: nop
    
            goto L_8005E12C;
    }
    // 0x8005E0BC: nop

    // 0x8005E0C0: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x8005E0C4: lui         $at, 0xC018
    ctx->r1 = S32(0XC018 << 16);
    // 0x8005E0C8: beq         $t5, $zero, L_8005E12C
    if (ctx->r13 == 0) {
        // 0x8005E0CC: nop
    
            goto L_8005E12C;
    }
    // 0x8005E0CC: nop

    // 0x8005E0D0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005E0D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005E0D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005E0DC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005E0E0: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8005E0E4: nop

    // 0x8005E0E8: bc1f        L_8005E12C
    if (!c1cs) {
        // 0x8005E0EC: nop
    
            goto L_8005E12C;
    }
    // 0x8005E0EC: nop

    // 0x8005E0F0: sb          $a2, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r6;
    // 0x8005E0F4: lb          $t8, 0x3B($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E0F8: lw          $t7, 0x44($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X44);
    // 0x8005E0FC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8005E100: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x8005E104: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8005E108: nop

    // 0x8005E10C: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x8005E110: addiu       $t5, $t6, -0x11
    ctx->r13 = ADD32(ctx->r14, -0X11);
    // 0x8005E114: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8005E118: nop

    // 0x8005E11C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005E120: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005E124: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E128: nop

L_8005E12C:
    // 0x8005E12C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
L_8005E130:
    // 0x8005E130: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E134: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8005E138: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E13C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E140: lh          $t2, 0x18($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X18);
    // 0x8005E144: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8005E148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E14C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8005E150: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8005E154: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005E158: beq         $v1, $at, L_8005E1B8
    if (ctx->r3 == ctx->r1) {
        // 0x8005E15C: sh          $t7, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r15;
            goto L_8005E1B8;
    }
    // 0x8005E15C: sh          $t7, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r15;
    // 0x8005E160: beq         $a0, $v1, L_8005E1B8
    if (ctx->r4 == ctx->r3) {
        // 0x8005E164: sra         $t9, $t2, 4
        ctx->r25 = S32(SIGNED(ctx->r10) >> 4);
            goto L_8005E1B8;
    }
    // 0x8005E164: sra         $t9, $t2, 4
    ctx->r25 = S32(SIGNED(ctx->r10) >> 4);
    // 0x8005E168: sll         $t3, $t9, 16
    ctx->r11 = S32(ctx->r25 << 16);
    // 0x8005E16C: sra         $t2, $t3, 16
    ctx->r10 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8005E170: bne         $v1, $zero, L_8005E17C
    if (ctx->r3 != 0) {
        // 0x8005E174: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005E17C;
    }
    // 0x8005E174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E178: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8005E17C:
    // 0x8005E17C: bne         $t2, $v0, L_8005E1B8
    if (ctx->r10 != ctx->r2) {
        // 0x8005E180: nop
    
            goto L_8005E1B8;
    }
    // 0x8005E180: nop

    // 0x8005E184: lh          $t5, 0x18($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X18);
    // 0x8005E188: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8005E18C: sra         $t8, $t5, 4
    ctx->r24 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8005E190: bne         $t6, $t8, L_8005E1B8
    if (ctx->r14 != ctx->r24) {
        // 0x8005E194: addiu       $a0, $zero, 0x223
        ctx->r4 = ADD32(0, 0X223);
            goto L_8005E1B8;
    }
    // 0x8005E194: addiu       $a0, $zero, 0x223
    ctx->r4 = ADD32(0, 0X223);
    // 0x8005E198: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8005E19C: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8005E1A0: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8005E1A4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8005E1A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005E1AC: jal         0x80009558
    // 0x8005E1B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_9;
    // 0x8005E1B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x8005E1B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_8005E1B8:
    // 0x8005E1B8: lb          $t9, 0x1D7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D7);
    // 0x8005E1BC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005E1C0: bne         $t9, $at, L_8005E204
    if (ctx->r25 != ctx->r1) {
        // 0x8005E1C4: lw          $a1, 0x60($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X60);
            goto L_8005E204;
    }
    // 0x8005E1C4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8005E1C8: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x8005E1CC: nop

    // 0x8005E1D0: bne         $t1, $t3, L_8005E204
    if (ctx->r9 != ctx->r11) {
        // 0x8005E1D4: lw          $a1, 0x60($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X60);
            goto L_8005E204;
    }
    // 0x8005E1D4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8005E1D8: jal         0x8002359C
    // 0x8005E1DC: nop

    func_80023568(rdram, ctx);
        goto after_10;
    // 0x8005E1DC: nop

    after_10:
    // 0x8005E1E0: beq         $v0, $zero, L_8005E200
    if (ctx->r2 == 0) {
        // 0x8005E1E4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005E200;
    }
    // 0x8005E1E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E1E8: addiu       $t4, $zero, 0xA5
    ctx->r12 = ADD32(0, 0XA5);
    // 0x8005E1EC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8005E1F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005E1F4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8005E1F8: jal         0x8005E3A4
    // 0x8005E1FC: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    spawn_boss_hazard(rdram, ctx);
        goto after_11;
    // 0x8005E1FC: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    after_11:
L_8005E200:
    // 0x8005E200: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
L_8005E204:
    // 0x8005E204: jal         0x800B019C
    // 0x8005E208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_12;
    // 0x8005E208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8005E20C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005E210: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005E214: jal         0x8005D1E8
    // 0x8005E218: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_13;
    // 0x8005E218: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_13:
    // 0x8005E21C: jal         0x8001BAFC
    // 0x8005E220: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_14;
    // 0x8005E220: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8005E224: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8005E228: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005E22C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005E230: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005E234: sub.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005E238: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005E23C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005E240: sub.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8005E244: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    // 0x8005E248: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005E24C: jal         0x800CA030
    // 0x8005E250: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_15;
    // 0x8005E250: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_15:
    // 0x8005E254: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005E258: lwc1        $f19, 0x7028($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X7028);
    // 0x8005E25C: lwc1        $f18, 0x702C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X702C);
    // 0x8005E260: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8005E264: c.lt.d      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.d < ctx->f18.d;
    // 0x8005E268: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005E26C: bc1f        L_8005E2DC
    if (!c1cs) {
        // 0x8005E270: nop
    
            goto L_8005E2DC;
    }
    // 0x8005E270: nop

    // 0x8005E274: jal         0x80070990
    // 0x8005E278: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_16;
    // 0x8005E278: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_16:
    // 0x8005E27C: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8005E280: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005E284: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8005E288: subu        $v1, $v0, $t6
    ctx->r3 = SUB32(ctx->r2, ctx->r14);
    // 0x8005E28C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005E290: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005E294: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005E298: bne         $at, $zero, L_8005E2A8
    if (ctx->r1 != 0) {
        // 0x8005E29C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8005E2A8;
    }
    // 0x8005E29C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005E2A0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005E2A4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005E2A8:
    // 0x8005E2A8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005E2AC: beq         $at, $zero, L_8005E2B8
    if (ctx->r1 == 0) {
        // 0x8005E2B0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005E2B8;
    }
    // 0x8005E2B0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005E2B4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005E2B8:
    // 0x8005E2B8: slti        $at, $v1, 0xC01
    ctx->r1 = SIGNED(ctx->r3) < 0XC01 ? 1 : 0;
    // 0x8005E2BC: bne         $at, $zero, L_8005E2CC
    if (ctx->r1 != 0) {
        // 0x8005E2C0: slti        $at, $v1, -0xC00
        ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
            goto L_8005E2CC;
    }
    // 0x8005E2C0: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
    // 0x8005E2C4: addiu       $v1, $zero, 0xC00
    ctx->r3 = ADD32(0, 0XC00);
    // 0x8005E2C8: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
L_8005E2CC:
    // 0x8005E2CC: beq         $at, $zero, L_8005E2D8
    if (ctx->r1 == 0) {
        // 0x8005E2D0: nop
    
            goto L_8005E2D8;
    }
    // 0x8005E2D0: nop

    // 0x8005E2D4: addiu       $v1, $zero, -0xC00
    ctx->r3 = ADD32(0, -0XC00);
L_8005E2D8:
    // 0x8005E2D8: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005E2DC:
    // 0x8005E2DC: lb          $t8, 0x3B($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E2E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005E2E4: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8005E2E8: bne         $at, $zero, L_8005E318
    if (ctx->r1 != 0) {
        // 0x8005E2EC: addiu       $a1, $a1, -0x24A0
        ctx->r5 = ADD32(ctx->r5, -0X24A0);
            goto L_8005E318;
    }
    // 0x8005E2EC: addiu       $a1, $a1, -0x24A0
    ctx->r5 = ADD32(ctx->r5, -0X24A0);
    // 0x8005E2F0: lb          $t7, 0x1E7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005E2F4: nop

    // 0x8005E2F8: andi        $t9, $t7, 0x1F
    ctx->r25 = ctx->r15 & 0X1F;
    // 0x8005E2FC: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x8005E300: beq         $at, $zero, L_8005E31C
    if (ctx->r1 == 0) {
        // 0x8005E304: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_8005E31C;
    }
    // 0x8005E304: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8005E308: lh          $t3, 0x16C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X16C);
    // 0x8005E30C: nop

    // 0x8005E310: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8005E314: sh          $t4, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r12;
L_8005E318:
    // 0x8005E318: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_8005E31C:
    // 0x8005E31C: nop

    // 0x8005E320: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005E324: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005E328: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8005E32C: nop

    // 0x8005E330: bne         $s1, $t5, L_8005E360
    if (ctx->r17 != ctx->r13) {
        // 0x8005E334: nop
    
            goto L_8005E360;
    }
    // 0x8005E334: nop

    // 0x8005E338: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8005E33C: nop

    // 0x8005E340: andi        $t8, $t6, 0x8
    ctx->r24 = ctx->r14 & 0X8;
    // 0x8005E344: beq         $t8, $zero, L_8005E360
    if (ctx->r24 == 0) {
        // 0x8005E348: nop
    
            goto L_8005E360;
    }
    // 0x8005E348: nop

    // 0x8005E34C: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E350: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E354: bne         $t7, $at, L_8005E360
    if (ctx->r15 != ctx->r1) {
        // 0x8005E358: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8005E360;
    }
    // 0x8005E358: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8005E35C: sb          $t9, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r25;
L_8005E360:
    // 0x8005E360: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005E364: nop

    // 0x8005E368: beq         $t3, $zero, L_8005E38C
    if (ctx->r11 == 0) {
        // 0x8005E36C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005E38C;
    }
    // 0x8005E36C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E370: lb          $t4, 0x0($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X0);
    // 0x8005E374: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005E378: bne         $t4, $zero, L_8005E388
    if (ctx->r12 != 0) {
        // 0x8005E37C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005E388;
    }
    // 0x8005E37C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E380: jal         0x8005CD08
    // 0x8005E384: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    racer_boss_finish(rdram, ctx);
        goto after_17;
    // 0x8005E384: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    after_17:
L_8005E388:
    // 0x8005E388: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005E38C:
    // 0x8005E38C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005E390: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005E394: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005E398: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005E39C: jr          $ra
    // 0x8005E3A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8005E3A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _timeToSamples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065A0C: jal         0x80065994
    // 0x80065A10: nop

    static_3_80065994(rdram, ctx);
        goto after_0;
    // 0x80065A10: nop

    after_0:
    // 0x80065A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065A18: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80065A1C: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x80065A20: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80065A24: jr          $ra
    // 0x80065A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80065A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void coss_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070ACC: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x80070AD0: sll         $v0, $a0, 17
    ctx->r2 = S32(ctx->r4 << 17);
    // 0x80070AD4: bgezl       $v0, L_80070AE4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80070AD8: srl         $t2, $a0, 3
        ctx->r10 = S32(U32(ctx->r4) >> 3);
            goto L_80070AE4;
    }
    goto skip_0;
    // 0x80070AD8: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
    skip_0:
    // 0x80070ADC: xori        $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 ^ 0X7FFF;
    // 0x80070AE0: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
L_80070AE4:
    // 0x80070AE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80070AE8: andi        $t2, $t2, 0x7FE
    ctx->r10 = ctx->r10 & 0X7FE;
    // 0x80070AEC: addiu       $v0, $v0, -0x2654
    ctx->r2 = ADD32(ctx->r2, -0X2654);
    // 0x80070AF0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80070AF4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80070AF8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80070AFC: bgez        $a0, L_80070B08
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80070B00: sll         $v0, $v0, 1
        ctx->r2 = S32(ctx->r2 << 1);
            goto L_80070B08;
    }
    // 0x80070B00: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80070B04: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80070B08:
    // 0x80070B08: jr          $ra
    // 0x80070B0C: nop

    return;
    // 0x80070B0C: nop

;}
RECOMP_FUNC void light_update_shading(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032CBC: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80032CC0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80032CC4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80032CC8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80032CCC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80032CD0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80032CD4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80032CD8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80032CDC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80032CE0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80032CE4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80032CE8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80032CEC: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80032CF0: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80032CF4: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80032CF8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80032CFC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80032D00: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80032D04: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80032D08: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x80032D0C: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80032D10: lbu         $t6, 0x3D($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3D);
    // 0x80032D14: nop

    // 0x80032D18: bne         $t6, $zero, L_800337D8
    if (ctx->r14 != 0) {
        // 0x80032D1C: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_800337D8;
    }
    // 0x80032D1C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80032D20: lb          $v0, 0x53($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X53);
    // 0x80032D24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032D28: beq         $v0, $zero, L_80032D50
    if (ctx->r2 == 0) {
        // 0x80032D2C: lui         $s7, 0x8012
        ctx->r23 = S32(0X8012 << 16);
            goto L_80032D50;
    }
    // 0x80032D2C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80032D30: beq         $v0, $at, L_80032D58
    if (ctx->r2 == ctx->r1) {
        // 0x80032D34: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80032D58;
    }
    // 0x80032D34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80032D38: beq         $v0, $at, L_80032D60
    if (ctx->r2 == ctx->r1) {
        // 0x80032D3C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80032D60;
    }
    // 0x80032D3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80032D40: beq         $v0, $at, L_80032D68
    if (ctx->r2 == ctx->r1) {
        // 0x80032D44: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_80032D68;
    }
    // 0x80032D44: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80032D48: b           L_80032D68
    // 0x80032D4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80032D68;
    // 0x80032D4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80032D50:
    // 0x80032D50: b           L_80032D68
    // 0x80032D54: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80032D68;
    // 0x80032D54: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80032D58:
    // 0x80032D58: b           L_80032D68
    // 0x80032D5C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80032D68;
    // 0x80032D5C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80032D60:
    // 0x80032D60: b           L_80032D68
    // 0x80032D64: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80032D68;
    // 0x80032D64: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80032D68:
    // 0x80032D68: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80032D6C: lwc1        $f4, 0xC($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0XC);
    // 0x80032D70: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80032D74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032D78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032D7C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80032D80: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80032D84: addiu       $s1, $s1, -0x3128
    ctx->r17 = ADD32(ctx->r17, -0X3128);
    // 0x80032D88: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80032D8C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80032D90: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80032D94: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80032D98: sh          $t8, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r24;
    // 0x80032D9C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80032DA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032DA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032DA8: lwc1        $f8, 0x10($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X10);
    // 0x80032DAC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80032DB0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80032DB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032DB8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80032DBC: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80032DC0: addiu       $s7, $s7, -0x25B4
    ctx->r23 = ADD32(ctx->r23, -0X25B4);
    // 0x80032DC4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80032DC8: sh          $t2, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r10;
    // 0x80032DCC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80032DD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80032DD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80032DD8: lwc1        $f16, 0x14($fp)
    ctx->f16.u32l = MEM_W(ctx->r30, 0X14);
    // 0x80032DDC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80032DE0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80032DE4: lw          $t5, -0x3134($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3134);
    // 0x80032DE8: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80032DEC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80032DF0: blez        $t5, L_800332D0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80032DF4: sh          $t4, 0x7E($sp)
        MEM_H(0X7E, ctx->r29) = ctx->r12;
            goto L_800332D0;
    }
    // 0x80032DF4: sh          $t4, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r12;
    // 0x80032DF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80032DFC: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80032E00: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80032E04: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80032E08: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80032E0C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80032E10: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80032E14: addiu       $s3, $s3, -0x3130
    ctx->r19 = ADD32(ctx->r19, -0X3130);
    // 0x80032E18: addiu       $s4, $s4, -0x25B8
    ctx->r20 = ADD32(ctx->r20, -0X25B8);
    // 0x80032E1C: addiu       $s6, $s6, -0x25BC
    ctx->r22 = ADD32(ctx->r22, -0X25BC);
    // 0x80032E20: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x80032E24: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
L_80032E28:
    // 0x80032E28: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80032E2C: lw          $t6, -0x3140($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3140);
    // 0x80032E30: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80032E34: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80032E38: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x80032E3C: nop

    // 0x80032E40: lbu         $t8, 0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2);
    // 0x80032E44: nop

    // 0x80032E48: and         $t2, $t8, $t9
    ctx->r10 = ctx->r24 & ctx->r25;
    // 0x80032E4C: beq         $t2, $zero, L_800332B8
    if (ctx->r10 == 0) {
        // 0x80032E50: nop
    
            goto L_800332B8;
    }
    // 0x80032E50: nop

    // 0x80032E54: lbu         $t3, 0x4($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X4);
    // 0x80032E58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032E5C: bne         $t3, $at, L_800332B8
    if (ctx->r11 != ctx->r1) {
        // 0x80032E60: nop
    
            goto L_800332B8;
    }
    // 0x80032E60: nop

    // 0x80032E64: lh          $t4, 0x82($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X82);
    // 0x80032E68: lh          $t5, 0x50($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X50);
    // 0x80032E6C: nop

    // 0x80032E70: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80032E74: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032E78: nop
    
            goto L_800332B8;
    }
    // 0x80032E78: nop

    // 0x80032E7C: lh          $t6, 0x56($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X56);
    // 0x80032E80: lh          $t7, 0x80($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X80);
    // 0x80032E84: slt         $at, $t6, $t4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80032E88: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032E8C: nop
    
            goto L_800332B8;
    }
    // 0x80032E8C: nop

    // 0x80032E90: lh          $t8, 0x52($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X52);
    // 0x80032E94: nop

    // 0x80032E98: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80032E9C: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032EA0: nop
    
            goto L_800332B8;
    }
    // 0x80032EA0: nop

    // 0x80032EA4: lh          $t9, 0x58($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X58);
    // 0x80032EA8: lh          $t2, 0x7E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X7E);
    // 0x80032EAC: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80032EB0: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032EB4: nop
    
            goto L_800332B8;
    }
    // 0x80032EB4: nop

    // 0x80032EB8: lh          $t3, 0x54($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X54);
    // 0x80032EBC: nop

    // 0x80032EC0: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80032EC4: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032EC8: nop
    
            goto L_800332B8;
    }
    // 0x80032EC8: nop

    // 0x80032ECC: lh          $t5, 0x5A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X5A);
    // 0x80032ED0: nop

    // 0x80032ED4: slt         $at, $t5, $t2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80032ED8: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032EDC: nop
    
            goto L_800332B8;
    }
    // 0x80032EDC: nop

    // 0x80032EE0: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80032EE4: nop

    // 0x80032EE8: bne         $t6, $zero, L_80032FC0
    if (ctx->r14 != 0) {
        // 0x80032EEC: nop
    
            goto L_80032FC0;
    }
    // 0x80032EEC: nop

    // 0x80032EF0: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80032EF4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80032EF8: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80032EFC: bne         $at, $zero, L_800332B8
    if (ctx->r1 != 0) {
        // 0x80032F00: nop
    
            goto L_800332B8;
    }
    // 0x80032F00: nop

    // 0x80032F04: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80032F08: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80032F0C: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F10: mflo        $t7
    ctx->r15 = lo;
    // 0x80032F14: addu        $t3, $t8, $t7
    ctx->r11 = ADD32(ctx->r24, ctx->r15);
    // 0x80032F18: sw          $s0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r16;
    // 0x80032F1C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032F20: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80032F24: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F28: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x80032F2C: nop

    // 0x80032F30: sra         $t2, $t5, 16
    ctx->r10 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80032F34: mflo        $t9
    ctx->r25 = lo;
    // 0x80032F38: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80032F3C: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x80032F40: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032F44: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80032F48: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F4C: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x80032F50: nop

    // 0x80032F54: sra         $t3, $t7, 16
    ctx->r11 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80032F58: mflo        $t6
    ctx->r14 = lo;
    // 0x80032F5C: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80032F60: sw          $t3, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r11;
    // 0x80032F64: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032F68: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80032F6C: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F70: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80032F74: nop

    // 0x80032F78: sra         $t8, $t2, 16
    ctx->r24 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80032F7C: mflo        $t5
    ctx->r13 = lo;
    // 0x80032F80: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x80032F84: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80032F88: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80032F8C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80032F90: multu       $t4, $s2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032F94: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
    // 0x80032F98: nop

    // 0x80032F9C: sra         $t9, $t3, 16
    ctx->r25 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80032FA0: mflo        $t7
    ctx->r15 = lo;
    // 0x80032FA4: addu        $t5, $t2, $t7
    ctx->r13 = ADD32(ctx->r10, ctx->r15);
    // 0x80032FA8: sw          $t9, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r25;
    // 0x80032FAC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80032FB0: nop

    // 0x80032FB4: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80032FB8: b           L_800332B8
    // 0x80032FBC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
        goto L_800332B8;
    // 0x80032FBC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_80032FC0:
    // 0x80032FC0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80032FC4: lwc1        $f6, 0xC($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0XC);
    // 0x80032FC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80032FCC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80032FD0: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    // 0x80032FD4: lwc1        $f16, 0x10($fp)
    ctx->f16.u32l = MEM_W(ctx->r30, 0X10);
    // 0x80032FD8: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80032FDC: nop

    // 0x80032FE0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80032FE4: swc1        $f18, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f18.u32l;
    // 0x80032FE8: lwc1        $f6, 0x14($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X14);
    // 0x80032FEC: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80032FF0: nop

    // 0x80032FF4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80032FF8: swc1        $f8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f8.u32l;
    // 0x80032FFC: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x80033000: nop

    // 0x80033004: bne         $t3, $at, L_80033010
    if (ctx->r11 != ctx->r1) {
        // 0x80033008: nop
    
            goto L_80033010;
    }
    // 0x80033008: nop

    // 0x8003300C: swc1        $f22, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f22.u32l;
L_80033010:
    // 0x80033010: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80033014: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80033018: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003301C: lwc1        $f12, 0x0($s7)
    ctx->f12.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80033020: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033024: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80033028: nop

    // 0x8003302C: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80033030: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80033034: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80033038: swc1        $f6, -0x25C0($at)
    MEM_W(-0X25C0, ctx->r1) = ctx->f6.u32l;
    // 0x8003303C: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80033040: nop

    // 0x80033044: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80033048: nop

    // 0x8003304C: bc1f        L_800332B8
    if (!c1cs) {
        // 0x80033050: nop
    
            goto L_800332B8;
    }
    // 0x80033050: nop

    // 0x80033054: lbu         $t4, 0x1($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1);
    // 0x80033058: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003305C: bne         $t4, $at, L_80033078
    if (ctx->r12 != ctx->r1) {
        // 0x80033060: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80033078;
    }
    // 0x80033060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033064: jal         0x80033C48
    // 0x80033068: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    light_direction_calc(rdram, ctx);
        goto after_0;
    // 0x80033068: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003306C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80033070: b           L_8003307C
    // 0x80033074: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8003307C;
    // 0x80033074: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80033078:
    // 0x80033078: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
L_8003307C:
    // 0x8003307C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x80033080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033084: bc1f        L_800332B8
    if (!c1cs) {
        // 0x80033088: nop
    
            goto L_800332B8;
    }
    // 0x80033088: nop

    // 0x8003308C: jal         0x80033A54
    // 0x80033090: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    light_distance_calc(rdram, ctx);
        goto after_1;
    // 0x80033090: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_1:
    // 0x80033094: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80033098: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x8003309C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800330A0: addiu       $t0, $t0, -0x312C
    ctx->r8 = ADD32(ctx->r8, -0X312C);
    // 0x800330A4: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x800330A8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800330AC: bc1f        L_800332B8
    if (!c1cs) {
        // 0x800330B0: nop
    
            goto L_800332B8;
    }
    // 0x800330B0: nop

    // 0x800330B4: lw          $t2, 0x40($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X40);
    // 0x800330B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800330BC: lbu         $t7, 0x71($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X71);
    // 0x800330C0: nop

    // 0x800330C4: beq         $t7, $zero, L_80033194
    if (ctx->r15 == 0) {
        // 0x800330C8: nop
    
            goto L_80033194;
    }
    // 0x800330C8: nop

    // 0x800330CC: lwc1        $f12, -0x25C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25C0);
    // 0x800330D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800330D4: c.lt.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl < ctx->f12.fl;
    // 0x800330D8: nop

    // 0x800330DC: bc1f        L_80033130
    if (!c1cs) {
        // 0x800330E0: nop
    
            goto L_80033130;
    }
    // 0x800330E0: nop

    // 0x800330E4: jal         0x800CA030
    // 0x800330E8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800330E8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_2:
    // 0x800330EC: nop

    // 0x800330F0: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800330F4: lwc1        $f10, 0x0($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800330F8: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800330FC: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80033100: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80033104: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80033108: addiu       $t0, $t0, -0x312C
    ctx->r8 = ADD32(ctx->r8, -0X312C);
    // 0x8003310C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80033110: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80033114: nop

    // 0x80033118: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8003311C: swc1        $f16, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f16.u32l;
    // 0x80033120: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80033124: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x80033128: b           L_80033140
    // 0x8003312C: swc1        $f8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f8.u32l;
        goto L_80033140;
    // 0x8003312C: swc1        $f8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f8.u32l;
L_80033130:
    // 0x80033130: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033134: swc1        $f26, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f26.u32l;
    // 0x80033138: swc1        $f26, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f26.u32l;
    // 0x8003313C: swc1        $f10, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->f10.u32l;
L_80033140:
    // 0x80033140: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80033144: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80033148: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003314C: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80033150: mflo        $t8
    ctx->r24 = lo;
    // 0x80033154: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80033158: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x8003315C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80033160: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80033164: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033168: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8003316C: mflo        $t2
    ctx->r10 = lo;
    // 0x80033170: addu        $t7, $t3, $t2
    ctx->r15 = ADD32(ctx->r11, ctx->r10);
    // 0x80033174: swc1        $f18, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f18.u32l;
    // 0x80033178: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8003317C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80033180: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033184: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80033188: mflo        $t8
    ctx->r24 = lo;
    // 0x8003318C: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x80033190: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
L_80033194:
    // 0x80033194: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80033198: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8003319C: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800331A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800331A4: mflo        $t2
    ctx->r10 = lo;
    // 0x800331A8: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x800331AC: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x800331B0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800331B4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800331B8: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800331BC: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x800331C0: nop

    // 0x800331C4: sra         $t5, $t9, 16
    ctx->r13 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800331C8: mflo        $t3
    ctx->r11 = lo;
    // 0x800331CC: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800331D0: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x800331D4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800331D8: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800331DC: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800331E0: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x800331E4: nop

    // 0x800331E8: sra         $t7, $t2, 16
    ctx->r15 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800331EC: mflo        $t8
    ctx->r24 = lo;
    // 0x800331F0: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x800331F4: sw          $t7, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r15;
    // 0x800331F8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800331FC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80033200: multu       $t6, $s2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033204: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80033208: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8003320C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80033210: cvt.w.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = CVT_W_S(ctx->f20.fl);
    // 0x80033214: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80033218: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8003321C: sra         $t4, $t5, 16
    ctx->r12 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80033220: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80033224: mflo        $t9
    ctx->r25 = lo;
    // 0x80033228: addu        $t8, $t2, $t9
    ctx->r24 = ADD32(ctx->r10, ctx->r25);
    // 0x8003322C: beq         $t3, $zero, L_80033278
    if (ctx->r11 == 0) {
        // 0x80033230: sw          $t4, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->r12;
            goto L_80033278;
    }
    // 0x80033230: sw          $t4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r12;
    // 0x80033234: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033238: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003323C: sub.s       $f6, $f20, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x80033240: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80033244: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80033248: nop

    // 0x8003324C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80033250: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80033254: nop

    // 0x80033258: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8003325C: bne         $t3, $zero, L_80033270
    if (ctx->r11 != 0) {
        // 0x80033260: nop
    
            goto L_80033270;
    }
    // 0x80033260: nop

    // 0x80033264: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80033268: b           L_80033288
    // 0x8003326C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80033288;
    // 0x8003326C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80033270:
    // 0x80033270: b           L_80033288
    // 0x80033274: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80033288;
    // 0x80033274: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80033278:
    // 0x80033278: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8003327C: nop

    // 0x80033280: bltz        $t3, L_80033270
    if (SIGNED(ctx->r11) < 0) {
        // 0x80033284: nop
    
            goto L_80033270;
    }
    // 0x80033284: nop

L_80033288:
    // 0x80033288: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8003328C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80033290: multu       $t2, $s2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033294: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x80033298: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003329C: mflo        $t9
    ctx->r25 = lo;
    // 0x800332A0: addu        $t4, $t6, $t9
    ctx->r12 = ADD32(ctx->r14, ctx->r25);
    // 0x800332A4: sw          $t5, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r13;
    // 0x800332A8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800332AC: nop

    // 0x800332B0: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800332B4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_800332B8:
    // 0x800332B8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800332BC: lw          $t3, -0x3134($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3134);
    // 0x800332C0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800332C4: slt         $at, $s5, $t3
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800332C8: bne         $at, $zero, L_80032E28
    if (ctx->r1 != 0) {
        // 0x800332CC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80032E28;
    }
    // 0x800332CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800332D0:
    // 0x800332D0: lw          $t2, 0x40($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X40);
    // 0x800332D4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800332D8: lbu         $t6, 0x71($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X71);
    // 0x800332DC: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800332E0: addiu       $s3, $s3, -0x3130
    ctx->r19 = ADD32(ctx->r19, -0X3130);
    // 0x800332E4: addiu       $t0, $t0, -0x312C
    ctx->r8 = ADD32(ctx->r8, -0X312C);
    // 0x800332E8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800332EC: beq         $t6, $zero, L_80033734
    if (ctx->r14 == 0) {
        // 0x800332F0: addiu       $s2, $zero, 0x14
        ctx->r18 = ADD32(0, 0X14);
            goto L_80033734;
    }
    // 0x800332F0: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
    // 0x800332F4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800332F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800332FC: bne         $a3, $zero, L_8003331C
    if (ctx->r7 != 0) {
        // 0x80033300: nop
    
            goto L_8003331C;
    }
    // 0x80033300: nop

    // 0x80033304: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x80033308: nop

    // 0x8003330C: sb          $zero, 0x7($t9)
    MEM_B(0X7, ctx->r25) = 0;
    // 0x80033310: lw          $t5, 0x54($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X54);
    // 0x80033314: b           L_800337D4
    // 0x80033318: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
        goto L_800337D4;
    // 0x80033318: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
L_8003331C:
    // 0x8003331C: bne         $a3, $at, L_8003342C
    if (ctx->r7 != ctx->r1) {
        // 0x80033320: nop
    
            goto L_8003342C;
    }
    // 0x80033320: nop

    // 0x80033324: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80033328: lw          $t7, 0x54($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X54);
    // 0x8003332C: lw          $t8, 0x4($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X4);
    // 0x80033330: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80033334: sb          $t8, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r24;
    // 0x80033338: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8003333C: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x80033340: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x80033344: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80033348: sb          $t2, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r10;
    // 0x8003334C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80033350: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x80033354: lw          $t5, 0xC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC);
    // 0x80033358: nop

    // 0x8003335C: sb          $t5, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r13;
    // 0x80033360: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80033364: lw          $t3, 0x54($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X54);
    // 0x80033368: lw          $t7, 0x10($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X10);
    // 0x8003336C: nop

    // 0x80033370: sb          $t7, 0x7($t3)
    MEM_B(0X7, ctx->r11) = ctx->r15;
    // 0x80033374: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x80033378: nop

    // 0x8003337C: sb          $zero, 0x11($t2)
    MEM_B(0X11, ctx->r10) = 0;
    // 0x80033380: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80033384: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x80033388: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8003338C: nop

    // 0x80033390: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033394: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80033398: nop

    // 0x8003339C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800333A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800333A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800333A8: nop

    // 0x800333AC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800333B0: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x800333B4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800333B8: sh          $t5, 0x8($t4)
    MEM_H(0X8, ctx->r12) = ctx->r13;
    // 0x800333BC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800333C0: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x800333C4: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800333C8: nop

    // 0x800333CC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800333D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800333D4: nop

    // 0x800333D8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800333DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800333E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800333E4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800333E8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800333EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800333F0: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800333F4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800333F8: sh          $t3, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r11;
    // 0x800333FC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80033400: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x80033404: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80033408: nop

    // 0x8003340C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033410: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033414: nop

    // 0x80033418: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003341C: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80033420: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80033424: b           L_800337D4
    // 0x80033428: sh          $t5, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r13;
        goto L_800337D4;
    // 0x80033428: sh          $t5, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r13;
L_8003342C:
    // 0x8003342C: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x80033430: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80033434: lw          $t8, 0x24($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X24);
    // 0x80033438: lw          $t7, 0x10($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X10);
    // 0x8003343C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80033440: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80033444: beq         $at, $zero, L_80033458
    if (ctx->r1 == 0) {
        // 0x80033448: addiu       $v1, $a2, 0x28
        ctx->r3 = ADD32(ctx->r6, 0X28);
            goto L_80033458;
    }
    // 0x80033448: addiu       $v1, $a2, 0x28
    ctx->r3 = ADD32(ctx->r6, 0X28);
    // 0x8003344C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80033450: b           L_80033458
    // 0x80033454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80033458;
    // 0x80033454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80033458:
    // 0x80033458: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x8003345C: bne         $at, $zero, L_800334E0
    if (ctx->r1 != 0) {
        // 0x80033460: addiu       $s5, $zero, 0x2
        ctx->r21 = ADD32(0, 0X2);
            goto L_800334E0;
    }
    // 0x80033460: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_80033464:
    // 0x80033464: multu       $a1, $s2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033468: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8003346C: mflo        $t3
    ctx->r11 = lo;
    // 0x80033470: addu        $t2, $a2, $t3
    ctx->r10 = ADD32(ctx->r6, ctx->r11);
    // 0x80033474: lw          $t6, 0x10($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X10);
    // 0x80033478: nop

    // 0x8003347C: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80033480: beq         $at, $zero, L_800334D0
    if (ctx->r1 == 0) {
        // 0x80033484: nop
    
            goto L_800334D0;
    }
    // 0x80033484: nop

    // 0x80033488: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003348C: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x80033490: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80033494: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80033498: mflo        $t9
    ctx->r25 = lo;
    // 0x8003349C: addu        $t5, $a2, $t9
    ctx->r13 = ADD32(ctx->r6, ctx->r25);
    // 0x800334A0: lw          $t4, 0x10($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X10);
    // 0x800334A4: nop

    // 0x800334A8: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800334AC: beq         $at, $zero, L_800334D0
    if (ctx->r1 == 0) {
        // 0x800334B0: nop
    
            goto L_800334D0;
    }
    // 0x800334B0: nop

    // 0x800334B4: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x800334B8: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x800334BC: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800334C0: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800334C4: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800334C8: b           L_800334D0
    // 0x800334CC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
        goto L_800334D0;
    // 0x800334CC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800334D0:
    // 0x800334D0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800334D4: slt         $at, $s5, $a3
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800334D8: bne         $at, $zero, L_80033464
    if (ctx->r1 != 0) {
        // 0x800334DC: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_80033464;
    }
    // 0x800334DC: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
L_800334E0:
    // 0x800334E0: multu       $a0, $s2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800334E4: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x800334E8: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x800334EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800334F0: mflo        $v0
    ctx->r2 = lo;
    // 0x800334F4: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x800334F8: lw          $t6, 0x4($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X4);
    // 0x800334FC: multu       $a0, $t1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033500: sb          $t6, 0x4($t9)
    MEM_B(0X4, ctx->r25) = ctx->r14;
    // 0x80033504: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80033508: lw          $t7, 0x54($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X54);
    // 0x8003350C: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x80033510: lw          $t8, 0x8($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X8);
    // 0x80033514: nop

    // 0x80033518: sb          $t8, 0x5($t7)
    MEM_B(0X5, ctx->r15) = ctx->r24;
    // 0x8003351C: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80033520: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x80033524: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x80033528: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x8003352C: mflo        $v1
    ctx->r3 = lo;
    // 0x80033530: sb          $t6, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r14;
    // 0x80033534: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80033538: lw          $t7, 0x54($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X54);
    // 0x8003353C: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x80033540: lw          $t8, 0x10($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X10);
    // 0x80033544: multu       $a1, $s2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80033548: sb          $t8, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r24;
    // 0x8003354C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80033550: lw          $t5, 0x54($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X54);
    // 0x80033554: addu        $t2, $t3, $v1
    ctx->r10 = ADD32(ctx->r11, ctx->r3);
    // 0x80033558: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8003355C: nop

    // 0x80033560: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80033564: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80033568: mflo        $a3
    ctx->r7 = lo;
    // 0x8003356C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80033570: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033574: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033578: multu       $a1, $t1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003357C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80033580: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80033584: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80033588: sh          $t9, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r25;
    // 0x8003358C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80033590: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x80033594: addu        $t8, $t4, $v1
    ctx->r24 = ADD32(ctx->r12, ctx->r3);
    // 0x80033598: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8003359C: nop

    // 0x800335A0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800335A4: mflo        $v0
    ctx->r2 = lo;
    // 0x800335A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800335AC: nop

    // 0x800335B0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800335B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800335B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800335BC: nop

    // 0x800335C0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800335C4: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x800335C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800335CC: sh          $t3, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r11;
    // 0x800335D0: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800335D4: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x800335D8: addu        $t9, $t6, $v1
    ctx->r25 = ADD32(ctx->r14, ctx->r3);
    // 0x800335DC: lwc1        $f18, 0x8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800335E0: nop

    // 0x800335E4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800335E8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800335EC: nop

    // 0x800335F0: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800335F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800335F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800335FC: nop

    // 0x80033600: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80033604: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80033608: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8003360C: sh          $t4, 0xC($t8)
    MEM_H(0XC, ctx->r24) = ctx->r12;
    // 0x80033610: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80033614: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x80033618: addu        $t3, $t7, $a3
    ctx->r11 = ADD32(ctx->r15, ctx->r7);
    // 0x8003361C: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x80033620: nop

    // 0x80033624: sb          $t2, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r10;
    // 0x80033628: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8003362C: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x80033630: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x80033634: lw          $t4, 0x8($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X8);
    // 0x80033638: nop

    // 0x8003363C: sb          $t4, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r12;
    // 0x80033640: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80033644: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x80033648: addu        $t3, $t7, $a3
    ctx->r11 = ADD32(ctx->r15, ctx->r7);
    // 0x8003364C: lw          $t2, 0xC($t3)
    ctx->r10 = MEM_W(ctx->r11, 0XC);
    // 0x80033650: nop

    // 0x80033654: sb          $t2, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r10;
    // 0x80033658: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8003365C: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x80033660: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x80033664: lw          $t4, 0x10($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X10);
    // 0x80033668: nop

    // 0x8003366C: sb          $t4, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r12;
    // 0x80033670: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80033674: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x80033678: addu        $t3, $t7, $v0
    ctx->r11 = ADD32(ctx->r15, ctx->r2);
    // 0x8003367C: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80033680: nop

    // 0x80033684: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033688: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8003368C: nop

    // 0x80033690: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80033694: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033698: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003369C: nop

    // 0x800336A0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800336A4: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800336A8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800336AC: sh          $t6, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r14;
    // 0x800336B0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800336B4: lw          $t3, 0x54($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X54);
    // 0x800336B8: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x800336BC: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800336C0: nop

    // 0x800336C4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800336C8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800336CC: nop

    // 0x800336D0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800336D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800336D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800336DC: nop

    // 0x800336E0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800336E4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800336E8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800336EC: sh          $t7, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r15;
    // 0x800336F0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800336F4: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x800336F8: addu        $t6, $t2, $v0
    ctx->r14 = ADD32(ctx->r10, ctx->r2);
    // 0x800336FC: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80033700: nop

    // 0x80033704: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033708: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8003370C: nop

    // 0x80033710: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80033714: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033718: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003371C: nop

    // 0x80033720: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80033724: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x80033728: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8003372C: b           L_800337D4
    // 0x80033730: sh          $t5, 0x16($t4)
    MEM_H(0X16, ctx->r12) = ctx->r13;
        goto L_800337D4;
    // 0x80033730: sh          $t5, 0x16($t4)
    MEM_H(0X16, ctx->r12) = ctx->r13;
L_80033734:
    // 0x80033734: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80033738: nop

    // 0x8003373C: blez        $a3, L_800337A4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80033740: slti        $at, $a3, 0x2
        ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_800337A4;
    }
    // 0x80033740: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80033744: bne         $at, $zero, L_80033754
    if (ctx->r1 != 0) {
        // 0x80033748: nop
    
            goto L_80033754;
    }
    // 0x80033748: nop

    // 0x8003374C: jal         0x80033824
    // 0x80033750: nop

    light_update_ambience(rdram, ctx);
        goto after_3;
    // 0x80033750: nop

    after_3:
L_80033754:
    // 0x80033754: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80033758: lw          $t3, 0x54($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X54);
    // 0x8003375C: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x80033760: nop

    // 0x80033764: sb          $t7, 0x4($t3)
    MEM_B(0X4, ctx->r11) = ctx->r15;
    // 0x80033768: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8003376C: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x80033770: lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8);
    // 0x80033774: nop

    // 0x80033778: sb          $t6, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r14;
    // 0x8003377C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80033780: lw          $t8, 0x54($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X54);
    // 0x80033784: lw          $t4, 0xC($t5)
    ctx->r12 = MEM_W(ctx->r13, 0XC);
    // 0x80033788: nop

    // 0x8003378C: sb          $t4, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r12;
    // 0x80033790: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80033794: lw          $t2, 0x54($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X54);
    // 0x80033798: lw          $t3, 0x10($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X10);
    // 0x8003379C: b           L_800337D4
    // 0x800337A0: sb          $t3, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r11;
        goto L_800337D4;
    // 0x800337A0: sb          $t3, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r11;
L_800337A4:
    // 0x800337A4: lw          $t6, 0x54($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X54);
    // 0x800337A8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800337AC: sb          $v0, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r2;
    // 0x800337B0: lw          $t9, 0x54($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X54);
    // 0x800337B4: nop

    // 0x800337B8: sb          $v0, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r2;
    // 0x800337BC: lw          $t5, 0x54($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X54);
    // 0x800337C0: nop

    // 0x800337C4: sb          $v0, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r2;
    // 0x800337C8: lw          $t4, 0x54($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X54);
    // 0x800337CC: nop

    // 0x800337D0: sb          $zero, 0x7($t4)
    MEM_B(0X7, ctx->r12) = 0;
L_800337D4:
    // 0x800337D4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_800337D8:
    // 0x800337D8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800337DC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800337E0: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800337E4: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800337E8: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800337EC: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800337F0: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800337F4: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800337F8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800337FC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80033800: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80033804: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80033808: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8003380C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80033810: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80033814: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80033818: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8003381C: jr          $ra
    // 0x80033820: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80033820: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void __seqpReleaseVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AB00: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8000AB04: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000AB08: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000AB0C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000AB10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000AB14: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000AB18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000AB1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000AB20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000AB24: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8000AB28: lw          $s6, 0x10($a1)
    ctx->r22 = MEM_W(ctx->r5, 0X10);
    // 0x8000AB2C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8000AB30: lbu         $t6, 0x34($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X34);
    // 0x8000AB34: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8000AB38: bne         $t6, $zero, L_8000ABAC
    if (ctx->r14 != 0) {
        // 0x8000AB3C: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8000ABAC;
    }
    // 0x8000AB3C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8000AB40: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x8000AB44: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x8000AB48: beq         $s0, $zero, L_8000ABAC
    if (ctx->r16 == 0) {
        // 0x8000AB4C: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8000ABAC;
    }
    // 0x8000AB4C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_8000AB50:
    // 0x8000AB50: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x8000AB54: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000AB58: bne         $s3, $t7, L_8000ABA0
    if (ctx->r19 != ctx->r15) {
        // 0x8000AB5C: nop
    
            goto L_8000ABA0;
    }
    // 0x8000AB5C: nop

    // 0x8000AB60: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x8000AB64: nop

    // 0x8000AB68: bne         $s5, $t8, L_8000ABA0
    if (ctx->r21 != ctx->r24) {
        // 0x8000AB6C: nop
    
            goto L_8000ABA0;
    }
    // 0x8000AB6C: nop

    // 0x8000AB70: beq         $s1, $zero, L_8000AB8C
    if (ctx->r17 == 0) {
        // 0x8000AB74: addiu       $s2, $s4, 0x48
        ctx->r18 = ADD32(ctx->r20, 0X48);
            goto L_8000AB8C;
    }
    // 0x8000AB74: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    // 0x8000AB78: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x8000AB7C: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8000AB80: nop

    // 0x8000AB84: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8000AB88: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_8000AB8C:
    // 0x8000AB8C: jal         0x800C8CC0
    // 0x8000AB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x8000AB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000AB94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000AB98: jal         0x800C8CF0
    // 0x8000AB9C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x8000AB9C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
L_8000ABA0:
    // 0x8000ABA0: bne         $s1, $zero, L_8000AB50
    if (ctx->r17 != 0) {
        // 0x8000ABA4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000AB50;
    }
    // 0x8000ABA4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8000ABA8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_8000ABAC:
    // 0x8000ABAC: sb          $zero, 0x33($s6)
    MEM_B(0X33, ctx->r22) = 0;
    // 0x8000ABB0: sb          $t2, 0x34($s6)
    MEM_B(0X34, ctx->r22) = ctx->r10;
    // 0x8000ABB4: sb          $zero, 0x30($s6)
    MEM_B(0X30, ctx->r22) = 0;
    // 0x8000ABB8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8000ABBC: lw          $t3, 0x1C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X1C);
    // 0x8000ABC0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000ABC4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8000ABC8: sw          $t5, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r13;
    // 0x8000ABCC: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x8000ABD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000ABD4: jal         0x800CA040
    // 0x8000ABD8: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    alSynSetPriority(rdram, ctx);
        goto after_2;
    // 0x8000ABD8: addiu       $s2, $s4, 0x48
    ctx->r18 = ADD32(ctx->r20, 0X48);
    after_2:
    // 0x8000ABDC: lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X14);
    // 0x8000ABE0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8000ABE4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000ABE8: jal         0x800C9BB0
    // 0x8000ABEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alSynSetVol(rdram, ctx);
        goto after_3;
    // 0x8000ABEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8000ABF0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8000ABF4: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8000ABF8: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x8000ABFC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8000AC00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AC04: jal         0x800C970C
    // 0x8000AC08: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x8000AC08: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x8000AC0C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000AC10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000AC14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AC18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000AC1C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000AC20: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000AC24: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AC28: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000AC2C: jr          $ra
    // 0x8000AC30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8000AC30: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void alSynSetPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9CE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9CE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9CEC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9CF0: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C9CF4: beql        $t6, $zero, L_800C9D58
    if (ctx->r14 == 0) {
        // 0x800C9CF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9D58;
    }
    goto skip_0;
    // 0x800C9CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9CFC: jal         0x800658A8
    // 0x800C9D00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9D00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C9D04: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9D08: beq         $v0, $zero, L_800C9D54
    if (ctx->r2 == 0) {
        // 0x800C9D0C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9D54;
    }
    // 0x800C9D0C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9D10: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C9D14: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C9D18: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x800C9D1C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C9D20: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C9D24: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C9D28: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9D2C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C9D30: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9D34: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C9D38: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C9D3C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800C9D40: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800C9D44: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800C9D48: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9D4C: jalr        $t9
    // 0x800C9D50: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9D50: nop

    after_1:
L_800C9D54:
    // 0x800C9D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9D58:
    // 0x800C9D58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9D5C: jr          $ra
    // 0x800C9D60: nop

    return;
    // 0x800C9D60: nop

;}
RECOMP_FUNC void update_vehicle_particles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFC74: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800AFC78: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AFC7C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800AFC80: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800AFC84: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AFC88: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AFC8C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AFC90: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AFC94: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AFC98: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AFC9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AFCA0: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800AFCA4: lw          $s3, 0x64($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X64);
    // 0x800AFCA8: lw          $s7, 0x74($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X74);
    // 0x800AFCAC: lb          $fp, 0x1D6($s3)
    ctx->r30 = MEM_B(ctx->r19, 0X1D6);
    // 0x800AFCB0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800AFCB4: jal         0x80012E28
    // 0x800AFCB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    object_do_player_tumble(rdram, ctx);
        goto after_0;
    // 0x800AFCB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x800AFCBC: lw          $t6, 0x40($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X40);
    // 0x800AFCC0: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800AFCC4: lb          $t7, 0x57($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X57);
    // 0x800AFCC8: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x800AFCCC: blez        $t7, L_800B0164
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800AFCD0: lui         $s4, 0x800E
        ctx->r20 = S32(0X800E << 16);
            goto L_800B0164;
    }
    // 0x800AFCD0: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800AFCD4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800AFCD8: addiu       $s1, $s1, 0x3290
    ctx->r17 = ADD32(ctx->r17, 0X3290);
    // 0x800AFCDC: addiu       $s4, $s4, 0x3414
    ctx->r20 = ADD32(ctx->r20, 0X3414);
L_800AFCE0:
    // 0x800AFCE0: andi        $t8, $s7, 0x1
    ctx->r24 = ctx->r23 & 0X1;
    // 0x800AFCE4: beq         $t8, $zero, L_800B0088
    if (ctx->r24 == 0) {
        // 0x800AFCE8: nop
    
            goto L_800B0088;
    }
    // 0x800AFCE8: nop

    // 0x800AFCEC: beq         $fp, $zero, L_800AFD10
    if (ctx->r30 == 0) {
        // 0x800AFCF0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800AFD10;
    }
    // 0x800AFCF0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AFCF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AFCF8: beq         $fp, $at, L_800AFF60
    if (ctx->r30 == ctx->r1) {
        // 0x800AFCFC: nop
    
            goto L_800AFF60;
    }
    // 0x800AFCFC: nop

    // 0x800AFD00: beq         $fp, $s6, L_800AFF10
    if (ctx->r30 == ctx->r22) {
        // 0x800AFD04: nop
    
            goto L_800AFF10;
    }
    // 0x800AFD04: nop

    // 0x800AFD08: b           L_800AFFB4
    // 0x800AFD0C: nop

        goto L_800AFFB4;
    // 0x800AFD0C: nop

L_800AFD10:
    // 0x800AFD10: bltz        $s0, L_800AFE44
    if (SIGNED(ctx->r16) < 0) {
        // 0x800AFD14: slti        $at, $s0, 0xA
        ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
            goto L_800AFE44;
    }
    // 0x800AFD14: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x800AFD18: beq         $at, $zero, L_800AFE48
    if (ctx->r1 == 0) {
        // 0x800AFD1C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800AFE48;
    }
    // 0x800AFD1C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800AFD20: lh          $v0, 0x16E($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X16E);
    // 0x800AFD24: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
    // 0x800AFD28: bgez        $v0, L_800AFD34
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800AFD2C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800AFD34;
    }
    // 0x800AFD2C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AFD30: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_800AFD34:
    // 0x800AFD34: addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
    // 0x800AFD38: blez        $v0, L_800AFFB4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AFD3C: slti        $at, $v0, 0x21
        ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
            goto L_800AFFB4;
    }
    // 0x800AFD3C: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x800AFD40: lw          $t9, 0x6C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFD44: lw          $t8, 0x3280($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3280);
    // 0x800AFD48: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x800AFD4C: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x800AFD50: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AFD54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AFD58: addiu       $t5, $t5, 0x3454
    ctx->r13 = ADD32(ctx->r13, 0X3454);
    // 0x800AFD5C: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800AFD60: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800AFD64: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x800AFD68: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x800AFD6C: bne         $at, $zero, L_800AFD78
    if (ctx->r1 != 0) {
        // 0x800AFD70: addiu       $t2, $t0, 0x3
        ctx->r10 = ADD32(ctx->r8, 0X3);
            goto L_800AFD78;
    }
    // 0x800AFD70: addiu       $t2, $t0, 0x3
    ctx->r10 = ADD32(ctx->r8, 0X3);
    // 0x800AFD74: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_800AFD78:
    // 0x800AFD78: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFD7C: lbu         $a0, 0x14($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X14);
    // 0x800AFD80: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x800AFD84: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800AFD88: subu        $t9, $t7, $a0
    ctx->r25 = SUB32(ctx->r15, ctx->r4);
    // 0x800AFD8C: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x800AFD90: mflo        $t6
    ctx->r14 = lo;
    // 0x800AFD94: sra         $t8, $t6, 2
    ctx->r24 = S32(SIGNED(ctx->r14) >> 2);
    // 0x800AFD98: subu        $v1, $t1, $t8
    ctx->r3 = SUB32(ctx->r9, ctx->r24);
    // 0x800AFD9C: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFDA0: lbu         $t9, 0x1($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X1);
    // 0x800AFDA4: mflo        $t4
    ctx->r12 = lo;
    // 0x800AFDA8: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800AFDAC: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x800AFDB0: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800AFDB4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800AFDB8: lbu         $a1, 0x15($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X15);
    // 0x800AFDBC: nop

    // 0x800AFDC0: subu        $t4, $t9, $a1
    ctx->r12 = SUB32(ctx->r25, ctx->r5);
    // 0x800AFDC4: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFDC8: mflo        $t5
    ctx->r13 = lo;
    // 0x800AFDCC: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800AFDD0: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x800AFDD4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800AFDD8: or          $t5, $t7, $t9
    ctx->r13 = ctx->r15 | ctx->r25;
    // 0x800AFDDC: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800AFDE0: lbu         $a2, 0x16($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X16);
    // 0x800AFDE4: lbu         $t6, 0x2($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X2);
    // 0x800AFDE8: nop

    // 0x800AFDEC: subu        $t8, $t6, $a2
    ctx->r24 = SUB32(ctx->r14, ctx->r6);
    // 0x800AFDF0: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFDF4: mflo        $t7
    ctx->r15 = lo;
    // 0x800AFDF8: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800AFDFC: addu        $t4, $a2, $t9
    ctx->r12 = ADD32(ctx->r6, ctx->r25);
    // 0x800AFE00: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x800AFE04: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x800AFE08: bne         $at, $zero, L_800AFE14
    if (ctx->r1 != 0) {
        // 0x800AFE0C: sw          $t8, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r24;
            goto L_800AFE14;
    }
    // 0x800AFE0C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800AFE10: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
L_800AFE14:
    // 0x800AFE14: lbu         $v0, 0x17($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X17);
    // 0x800AFE18: lbu         $t9, 0x0($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X0);
    // 0x800AFE1C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800AFE20: subu        $t4, $t9, $v0
    ctx->r12 = SUB32(ctx->r25, ctx->r2);
    // 0x800AFE24: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AFE28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFE2C: mflo        $t5
    ctx->r13 = lo;
    // 0x800AFE30: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800AFE34: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x800AFE38: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800AFE3C: b           L_800AFFB4
    // 0x800AFE40: sw          $t9, 0x3290($at)
    MEM_W(0X3290, ctx->r1) = ctx->r25;
        goto L_800AFFB4;
    // 0x800AFE40: sw          $t9, 0x3290($at)
    MEM_W(0X3290, ctx->r1) = ctx->r25;
L_800AFE44:
    // 0x800AFE44: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800AFE48:
    // 0x800AFE48: beq         $s0, $at, L_800AFE70
    if (ctx->r16 == ctx->r1) {
        // 0x800AFE4C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800AFE70;
    }
    // 0x800AFE4C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800AFE50: beq         $s0, $at, L_800AFE98
    if (ctx->r16 == ctx->r1) {
        // 0x800AFE54: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_800AFE98;
    }
    // 0x800AFE54: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800AFE58: beq         $s0, $at, L_800AFEC0
    if (ctx->r16 == ctx->r1) {
        // 0x800AFE5C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800AFEC0;
    }
    // 0x800AFE5C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800AFE60: beq         $s0, $at, L_800AFEE8
    if (ctx->r16 == ctx->r1) {
        // 0x800AFE64: nop
    
            goto L_800AFEE8;
    }
    // 0x800AFE64: nop

    // 0x800AFE68: b           L_800AFFB4
    // 0x800AFE6C: nop

        goto L_800AFFB4;
    // 0x800AFE6C: nop

L_800AFE70:
    // 0x800AFE70: lbu         $v0, 0x1DE($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DE);
    // 0x800AFE74: nop

    // 0x800AFE78: bne         $s5, $v0, L_800AFE84
    if (ctx->r21 != ctx->r2) {
        // 0x800AFE7C: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_800AFE84;
    }
    // 0x800AFE7C: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x800AFE80: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AFE84:
    // 0x800AFE84: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AFE88: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x800AFE8C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AFE90: b           L_800AFFB4
    // 0x800AFE94: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
        goto L_800AFFB4;
    // 0x800AFE94: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_800AFE98:
    // 0x800AFE98: lbu         $v0, 0x1DF($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DF);
    // 0x800AFE9C: nop

    // 0x800AFEA0: bne         $s5, $v0, L_800AFEAC
    if (ctx->r21 != ctx->r2) {
        // 0x800AFEA4: andi        $t8, $v0, 0xF
        ctx->r24 = ctx->r2 & 0XF;
            goto L_800AFEAC;
    }
    // 0x800AFEA4: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x800AFEA8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AFEAC:
    // 0x800AFEAC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AFEB0: addu        $t4, $s4, $t9
    ctx->r12 = ADD32(ctx->r20, ctx->r25);
    // 0x800AFEB4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800AFEB8: b           L_800AFFB4
    // 0x800AFEBC: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
        goto L_800AFFB4;
    // 0x800AFEBC: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
L_800AFEC0:
    // 0x800AFEC0: lbu         $v0, 0x1DC($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DC);
    // 0x800AFEC4: nop

    // 0x800AFEC8: bne         $s5, $v0, L_800AFED4
    if (ctx->r21 != ctx->r2) {
        // 0x800AFECC: andi        $t6, $v0, 0xF
        ctx->r14 = ctx->r2 & 0XF;
            goto L_800AFED4;
    }
    // 0x800AFECC: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800AFED0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AFED4:
    // 0x800AFED4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AFED8: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x800AFEDC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800AFEE0: b           L_800AFFB4
    // 0x800AFEE4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
        goto L_800AFFB4;
    // 0x800AFEE4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_800AFEE8:
    // 0x800AFEE8: lbu         $v0, 0x1DD($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1DD);
    // 0x800AFEEC: nop

    // 0x800AFEF0: bne         $s5, $v0, L_800AFEFC
    if (ctx->r21 != ctx->r2) {
        // 0x800AFEF4: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_800AFEFC;
    }
    // 0x800AFEF4: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x800AFEF8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800AFEFC:
    // 0x800AFEFC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AFF00: addu        $t6, $s4, $t5
    ctx->r14 = ADD32(ctx->r20, ctx->r13);
    // 0x800AFF04: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800AFF08: b           L_800AFFB4
    // 0x800AFF0C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
        goto L_800AFFB4;
    // 0x800AFF0C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_800AFF10:
    // 0x800AFF10: bne         $s0, $zero, L_800AFF38
    if (ctx->r16 != 0) {
        // 0x800AFF14: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800AFF38;
    }
    // 0x800AFF14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AFF18: lbu         $t8, 0x1DC($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X1DC);
    // 0x800AFF1C: nop

    // 0x800AFF20: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800AFF24: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800AFF28: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x800AFF2C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800AFF30: b           L_800AFFB4
    // 0x800AFF34: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
        goto L_800AFFB4;
    // 0x800AFF34: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
L_800AFF38:
    // 0x800AFF38: bne         $s0, $at, L_800AFFB4
    if (ctx->r16 != ctx->r1) {
        // 0x800AFF3C: nop
    
            goto L_800AFFB4;
    }
    // 0x800AFF3C: nop

    // 0x800AFF40: lbu         $t7, 0x1DD($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X1DD);
    // 0x800AFF44: nop

    // 0x800AFF48: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x800AFF4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AFF50: addu        $t4, $s4, $t9
    ctx->r12 = ADD32(ctx->r20, ctx->r25);
    // 0x800AFF54: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800AFF58: b           L_800AFFB4
    // 0x800AFF5C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
        goto L_800AFFB4;
    // 0x800AFF5C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
L_800AFF60:
    // 0x800AFF60: beq         $s0, $s6, L_800AFF70
    if (ctx->r16 == ctx->r22) {
        // 0x800AFF64: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AFF70;
    }
    // 0x800AFF64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AFF68: bne         $s0, $at, L_800AFFB4
    if (ctx->r16 != ctx->r1) {
        // 0x800AFF6C: nop
    
            goto L_800AFFB4;
    }
    // 0x800AFF6C: nop

L_800AFF70:
    // 0x800AFF70: lb          $t6, 0x2($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X2);
    // 0x800AFF74: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800AFF78: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x800AFF7C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800AFF80: addiu       $t9, $t9, -0x7DB8
    ctx->r25 = ADD32(ctx->r25, -0X7DB8);
    // 0x800AFF84: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x800AFF88: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800AFF8C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800AFF90: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800AFF94: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x800AFF98: slti        $at, $v0, 0x101
    ctx->r1 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x800AFF9C: bne         $at, $zero, L_800AFFA8
    if (ctx->r1 != 0) {
        // 0x800AFFA0: nop
    
            goto L_800AFFA8;
    }
    // 0x800AFFA0: nop

    // 0x800AFFA4: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_800AFFA8:
    // 0x800AFFA8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800AFFAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AFFB0: sw          $v0, 0x347C($at)
    MEM_W(0X347C, ctx->r1) = ctx->r2;
L_800AFFB4:
    // 0x800AFFB4: beq         $t3, $zero, L_800B0138
    if (ctx->r11 == 0) {
        // 0x800AFFB8: nop
    
            goto L_800B0138;
    }
    // 0x800AFFB8: nop

    // 0x800AFFBC: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFFC0: sll         $a3, $s0, 5
    ctx->r7 = S32(ctx->r16 << 5);
    // 0x800AFFC4: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // 0x800AFFC8: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800AFFCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AFFD0: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x800AFFD4: bne         $t6, $zero, L_800AFFFC
    if (ctx->r14 != 0) {
        // 0x800AFFD8: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800AFFFC;
    }
    // 0x800AFFD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800AFFDC: jal         0x800AFA8C
    // 0x800AFFE0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    obj_enable_emitter(rdram, ctx);
        goto after_1;
    // 0x800AFFE0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_1:
    // 0x800AFFE4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800AFFE8: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800AFFEC: nop

    // 0x800AFFF0: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // 0x800AFFF4: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800AFFF8: nop

L_800AFFFC:
    // 0x800AFFFC: andi        $t7, $v1, 0x4000
    ctx->r15 = ctx->r3 & 0X4000;
    // 0x800B0000: beq         $t7, $zero, L_800B0020
    if (ctx->r15 == 0) {
        // 0x800B0004: andi        $t9, $v1, 0x400
        ctx->r25 = ctx->r3 & 0X400;
            goto L_800B0020;
    }
    // 0x800B0004: andi        $t9, $v1, 0x400
    ctx->r25 = ctx->r3 & 0X400;
    // 0x800B0008: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x800B000C: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    // 0x800B0010: jal         0x800B03BC
    // 0x800B0014: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_trigger_emitter(rdram, ctx);
        goto after_2;
    // 0x800B0014: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800B0018: b           L_800B013C
    // 0x800B001C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_800B013C;
    // 0x800B001C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800B0020:
    // 0x800B0020: beq         $t9, $zero, L_800B003C
    if (ctx->r25 == 0) {
        // 0x800B0024: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B003C;
    }
    // 0x800B0024: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0028: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
    // 0x800B002C: jal         0x800B03BC
    // 0x800B0030: addu        $a1, $a2, $t4
    ctx->r5 = ADD32(ctx->r6, ctx->r12);
    obj_trigger_emitter(rdram, ctx);
        goto after_3;
    // 0x800B0030: addu        $a1, $a2, $t4
    ctx->r5 = ADD32(ctx->r6, ctx->r12);
    after_3:
    // 0x800B0034: b           L_800B013C
    // 0x800B0038: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_800B013C;
    // 0x800B0038: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800B003C:
    // 0x800B003C: lh          $t5, 0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XA);
    // 0x800B0040: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x800B0044: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0048: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800B004C: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x800B0050: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800B0054: sll         $t5, $s0, 5
    ctx->r13 = S32(ctx->r16 << 5);
    // 0x800B0058: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // 0x800B005C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B0060: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800B0064: lh          $t4, 0x40($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X40);
    // 0x800B0068: nop

    // 0x800B006C: slt         $at, $t8, $t4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800B0070: bne         $at, $zero, L_800B0138
    if (ctx->r1 != 0) {
        // 0x800B0074: nop
    
            goto L_800B0138;
    }
    // 0x800B0074: nop

    // 0x800B0078: jal         0x800B03BC
    // 0x800B007C: addu        $a1, $a2, $t5
    ctx->r5 = ADD32(ctx->r6, ctx->r13);
    obj_trigger_emitter(rdram, ctx);
        goto after_4;
    // 0x800B007C: addu        $a1, $a2, $t5
    ctx->r5 = ADD32(ctx->r6, ctx->r13);
    after_4:
    // 0x800B0080: b           L_800B013C
    // 0x800B0084: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_800B013C;
    // 0x800B0084: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800B0088:
    // 0x800B0088: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800B008C: sll         $t6, $s0, 5
    ctx->r14 = S32(ctx->r16 << 5);
    // 0x800B0090: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x800B0094: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800B0098: nop

    // 0x800B009C: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x800B00A0: beq         $t7, $zero, L_800B0138
    if (ctx->r15 == 0) {
        // 0x800B00A4: andi        $t9, $v1, 0x4000
        ctx->r25 = ctx->r3 & 0X4000;
            goto L_800B0138;
    }
    // 0x800B00A4: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x800B00A8: beq         $t9, $zero, L_800B00D0
    if (ctx->r25 == 0) {
        // 0x800B00AC: andi        $t4, $v1, 0x400
        ctx->r12 = ctx->r3 & 0X400;
            goto L_800B00D0;
    }
    // 0x800B00AC: andi        $t4, $v1, 0x400
    ctx->r12 = ctx->r3 & 0X400;
    // 0x800B00B0: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x800B00B4: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x800B00B8: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x800B00BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B00C0: jal         0x800AFC44
    // 0x800B00C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_5;
    // 0x800B00C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800B00C8: b           L_800B0110
    // 0x800B00CC: nop

        goto L_800B0110;
    // 0x800B00CC: nop

L_800B00D0:
    // 0x800B00D0: beq         $t4, $zero, L_800B0108
    if (ctx->r12 == 0) {
        // 0x800B00D4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B0108;
    }
    // 0x800B00D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B00D8: sll         $t5, $s0, 5
    ctx->r13 = S32(ctx->r16 << 5);
    // 0x800B00DC: ori         $t6, $v1, 0x200
    ctx->r14 = ctx->r3 | 0X200;
    // 0x800B00E0: addu        $a0, $a2, $t5
    ctx->r4 = ADD32(ctx->r6, ctx->r13);
    // 0x800B00E4: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x800B00E8: lbu         $t7, 0x6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X6);
    // 0x800B00EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B00F0: bne         $t7, $zero, L_800B0110
    if (ctx->r15 != 0) {
        // 0x800B00F4: nop
    
            goto L_800B0110;
    }
    // 0x800B00F4: nop

    // 0x800B00F8: jal         0x800AFC44
    // 0x800B00FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_6;
    // 0x800B00FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800B0100: b           L_800B0110
    // 0x800B0104: nop

        goto L_800B0110;
    // 0x800B0104: nop

L_800B0108:
    // 0x800B0108: jal         0x800AFC44
    // 0x800B010C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_7;
    // 0x800B010C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
L_800B0110:
    // 0x800B0110: beq         $s0, $s6, L_800B0120
    if (ctx->r16 == ctx->r22) {
        // 0x800B0114: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B0120;
    }
    // 0x800B0114: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B0118: bne         $s0, $at, L_800B0138
    if (ctx->r16 != ctx->r1) {
        // 0x800B011C: nop
    
            goto L_800B0138;
    }
    // 0x800B011C: nop

L_800B0120:
    // 0x800B0120: lb          $t9, 0x2($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X2);
    // 0x800B0124: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B0128: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x800B012C: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x800B0130: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B0134: sh          $zero, -0x7DB8($at)
    MEM_H(-0X7DB8, ctx->r1) = 0;
L_800B0138:
    // 0x800B0138: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800B013C:
    // 0x800B013C: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x800B0140: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B0144: sw          $t6, 0x347C($at)
    MEM_W(0X347C, ctx->r1) = ctx->r14;
    // 0x800B0148: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x800B014C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B0150: lb          $t9, 0x57($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X57);
    // 0x800B0154: srl         $t5, $s7, 1
    ctx->r13 = S32(U32(ctx->r23) >> 1);
    // 0x800B0158: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B015C: bne         $at, $zero, L_800AFCE0
    if (ctx->r1 != 0) {
        // 0x800B0160: or          $s7, $t5, $zero
        ctx->r23 = ctx->r13 | 0;
            goto L_800AFCE0;
    }
    // 0x800B0160: or          $s7, $t5, $zero
    ctx->r23 = ctx->r13 | 0;
L_800B0164:
    // 0x800B0164: jal         0x80012F30
    // 0x800B0168: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    object_undo_player_tumble(rdram, ctx);
        goto after_8;
    // 0x800B0168: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x800B016C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0174: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0178: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B017C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B0180: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B0184: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800B0188: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800B018C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800B0190: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800B0194: jr          $ra
    // 0x800B0198: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800B0198: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void obj_loop_bubbler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800420D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800420D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800420D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800420DC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800420E0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800420E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800420E8: jal         0x8006FB8C
    // 0x800420EC: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800420EC: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_0:
    // 0x800420F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800420F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800420F8: lw          $t6, 0x78($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X78);
    // 0x800420FC: nop

    // 0x80042100: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80042104: bne         $at, $zero, L_80042114
    if (ctx->r1 != 0) {
        // 0x80042108: nop
    
            goto L_80042114;
    }
    // 0x80042108: nop

    // 0x8004210C: b           L_80042118
    // 0x80042110: sw          $t7, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r15;
        goto L_80042118;
    // 0x80042110: sw          $t7, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r15;
L_80042114:
    // 0x80042114: sw          $zero, 0x74($a2)
    MEM_W(0X74, ctx->r6) = 0;
L_80042118:
    // 0x80042118: jal         0x8009C90C
    // 0x8004211C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    get_number_of_active_players(rdram, ctx);
        goto after_1;
    // 0x8004211C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80042120: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80042124: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80042128: beq         $at, $zero, L_80042140
    if (ctx->r1 == 0) {
        // 0x8004212C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80042140;
    }
    // 0x8004212C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042130: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80042134: jal         0x800B019C
    // 0x80042138: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_2;
    // 0x80042138: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8004213C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80042140:
    // 0x80042140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042144: jr          $ra
    // 0x80042148: nop

    return;
    // 0x80042148: nop

;}
RECOMP_FUNC void get_racer_objects_by_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BAE0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BAE4: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8001BAE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BAEC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BAF0: lw          $v0, -0x4B98($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B98);
    // 0x8001BAF4: jr          $ra
    // 0x8001BAF8: nop

    return;
    // 0x8001BAF8: nop

;}
RECOMP_FUNC void hud_sound_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7A48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A7A4C: lhu         $t7, 0x733C($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X733C);
    // 0x800A7A50: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800A7A54: bne         $t7, $t6, L_800A7A74
    if (ctx->r15 != ctx->r14) {
        // 0x800A7A58: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800A7A74;
    }
    // 0x800A7A58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A7A5C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A7A60: lw          $t8, 0x7338($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7338);
    // 0x800A7A64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7A68: bne         $a1, $t8, L_800A7A74
    if (ctx->r5 != ctx->r24) {
        // 0x800A7A6C: nop
    
            goto L_800A7A74;
    }
    // 0x800A7A6C: nop

    // 0x800A7A70: sw          $zero, 0x7334($at)
    MEM_W(0X7334, ctx->r1) = 0;
L_800A7A74:
    // 0x800A7A74: jr          $ra
    // 0x800A7A78: nop

    return;
    // 0x800A7A78: nop

;}
RECOMP_FUNC void mtxf_transform_dir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F92C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8006F930: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F934: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8006F938: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006F93C: mul.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006F940: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006F944: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8006F948: mul.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F94C: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8006F950: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F954: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F958: mul.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006F95C: add.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F960: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8006F964: lwc1        $f14, 0x24($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8006F968: mul.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F96C: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x8006F970: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F974: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8006F978: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F97C: add.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F980: mul.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006F984: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8006F988: lwc1        $f14, 0x28($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8006F98C: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8006F990: mul.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F994: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8006F998: mul.s       $f14, $f8, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F99C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F9A0: jr          $ra
    // 0x8006F9A4: swc1        $f14, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f14.u32l;
    return;
    // 0x8006F9A4: swc1        $f14, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f14.u32l;
;}
RECOMP_FUNC void is_time_trial_enabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E4CC: lbu         $v0, -0x4B8C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4B8C);
    // 0x8000E4D0: jr          $ra
    // 0x8000E4D4: nop

    return;
    // 0x8000E4D4: nop

;}
RECOMP_FUNC void func_80018CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018D14: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80018D18: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80018D1C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80018D20: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80018D24: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80018D28: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80018D2C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80018D30: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80018D34: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80018D38: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80018D3C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80018D40: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80018D44: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x80018D48: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80018D4C: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80018D50: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80018D54: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80018D58: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80018D5C: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80018D60: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80018D64: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80018D68: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80018D6C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80018D70: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x80018D74: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x80018D78: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x80018D7C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80018D80: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80018D84: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80018D88: nop

    // 0x80018D8C: bne         $t3, $zero, L_80019534
    if (ctx->r11 != 0) {
        // 0x80018D90: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80019534;
    }
    // 0x80018D90: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80018D94: jal         0x80066450
    // 0x80018D98: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x80018D98: nop

    after_0:
    // 0x80018D9C: bne         $v0, $zero, L_80019530
    if (ctx->r2 != 0) {
        // 0x80018DA0: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80019530;
    }
    // 0x80018DA0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80018DA4: lw          $t4, -0x4C20($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4C20);
    // 0x80018DA8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80018DAC: lw          $t5, -0x4C24($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4C24);
    // 0x80018DB0: sw          $t4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r12;
    // 0x80018DB4: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80018DB8: beq         $at, $zero, L_80019290
    if (ctx->r1 == 0) {
        // 0x80018DBC: sll         $t8, $t4, 2
        ctx->r24 = S32(ctx->r12 << 2);
            goto L_80019290;
    }
    // 0x80018DBC: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80018DC0: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x80018DC4: addiu       $fp, $zero, 0x7F
    ctx->r30 = ADD32(0, 0X7F);
    // 0x80018DC8: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x80018DCC: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80018DD0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_80018DD4:
    // 0x80018DD4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80018DD8: lw          $t7, -0x4C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C28);
    // 0x80018DDC: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x80018DE0: nop

    // 0x80018DE4: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80018DE8: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x80018DEC: nop

    // 0x80018DF0: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x80018DF4: nop

    // 0x80018DF8: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x80018DFC: bne         $t1, $zero, L_8001926C
    if (ctx->r9 != 0) {
        // 0x80018E00: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80018E00: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80018E04: lh          $v0, 0x48($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X48);
    // 0x80018E08: addiu       $at, $zero, 0x70
    ctx->r1 = ADD32(0, 0X70);
    // 0x80018E0C: bne         $v0, $at, L_80018FD0
    if (ctx->r2 != ctx->r1) {
        // 0x80018E10: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80018FD0;
    }
    // 0x80018E10: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80018E14: lwc1        $f6, 0xC($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80018E18: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018E1C: lwc1        $f10, 0x10($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80018E20: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80018E24: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80018E28: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018E2C: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80018E30: lwc1        $f6, 0x14($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X14);
    // 0x80018E34: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80018E38: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80018E3C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80018E40: nop

    // 0x80018E44: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018E48: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80018E4C: jal         0x800CA030
    // 0x80018E50: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80018E50: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_1:
    // 0x80018E54: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x80018E58: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80018E5C: lhu         $t2, 0x2($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X2);
    // 0x80018E60: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80018E64: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80018E68: bgez        $t2, L_80018E7C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80018E6C: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80018E7C;
    }
    // 0x80018E6C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80018E70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80018E74: nop

    // 0x80018E78: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_80018E7C:
    // 0x80018E7C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80018E80: nop

    // 0x80018E84: bc1f        L_8001926C
    if (!c1cs) {
        // 0x80018E88: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80018E88: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80018E8C: sw          $v1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r3;
    // 0x80018E90: jal         0x80001918
    // 0x80018E94: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    music_current_sequence(rdram, ctx);
        goto after_2;
    // 0x80018E94: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80018E98: lw          $v1, 0xBC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XBC);
    // 0x80018E9C: lwc1        $f2, 0xC0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80018EA0: lbu         $t3, 0x1C($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1C);
    // 0x80018EA4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80018EA8: bne         $t3, $v0, L_80019268
    if (ctx->r11 != ctx->r2) {
        // 0x80018EAC: or          $s3, $v1, $zero
        ctx->r19 = ctx->r3 | 0;
            goto L_80019268;
    }
    // 0x80018EAC: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80018EB0: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80018EB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80018EB8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80018EBC: bgez        $v0, L_80018ED0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80018EC0: cvt.s.w     $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80018ED0;
    }
    // 0x80018EC0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80018EC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018EC8: nop

    // 0x80018ECC: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_80018ED0:
    // 0x80018ED0: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x80018ED4: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80018ED8: bc1f        L_80018EE8
    if (!c1cs) {
        // 0x80018EDC: nop
    
            goto L_80018EE8;
    }
    // 0x80018EDC: nop

    // 0x80018EE0: b           L_80018F34
    // 0x80018EE4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80018F34;
    // 0x80018EE4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80018EE8:
    // 0x80018EE8: lhu         $t5, 0x2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X2);
    // 0x80018EEC: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80018EF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80018EF4: subu        $t4, $t5, $v0
    ctx->r12 = SUB32(ctx->r13, ctx->r2);
    // 0x80018EF8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80018EFC: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80018F00: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80018F04: nop

    // 0x80018F08: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80018F0C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80018F10: nop

    // 0x80018F14: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80018F18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80018F1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80018F20: nop

    // 0x80018F24: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80018F28: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80018F2C: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x80018F30: nop

L_80018F34:
    // 0x80018F34: lbu         $v0, 0xC($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0XC);
    // 0x80018F38: slti        $at, $s2, 0x7B
    ctx->r1 = SIGNED(ctx->r18) < 0X7B ? 1 : 0;
    // 0x80018F3C: beq         $v0, $s5, L_80018F54
    if (ctx->r2 == ctx->r21) {
        // 0x80018F40: nop
    
            goto L_80018F54;
    }
    // 0x80018F40: nop

    // 0x80018F44: beq         $v0, $s6, L_80018F90
    if (ctx->r2 == ctx->r22) {
        // 0x80018F48: andi        $s0, $s1, 0xFF
        ctx->r16 = ctx->r17 & 0XFF;
            goto L_80018F90;
    }
    // 0x80018F48: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x80018F4C: b           L_80018FBC
    // 0x80018F50: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80018FBC;
    // 0x80018F50: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018F54:
    // 0x80018F54: bne         $at, $zero, L_80018F6C
    if (ctx->r1 != 0) {
        // 0x80018F58: andi        $s0, $s1, 0xFF
        ctx->r16 = ctx->r17 & 0XFF;
            goto L_80018F6C;
    }
    // 0x80018F58: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x80018F5C: jal         0x80001114
    // 0x80018F60: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_3;
    // 0x80018F60: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_3:
    // 0x80018F64: b           L_80018FBC
    // 0x80018F68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80018FBC;
    // 0x80018F68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018F6C:
    // 0x80018F6C: subu        $a1, $fp, $s2
    ctx->r5 = SUB32(ctx->r30, ctx->r18);
    // 0x80018F70: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80018F74: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80018F78: jal         0x80001268
    // 0x80018F7C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_4;
    // 0x80018F7C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_4:
    // 0x80018F80: jal         0x80001170
    // 0x80018F84: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_5;
    // 0x80018F84: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_5:
    // 0x80018F88: b           L_80018FBC
    // 0x80018F8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80018FBC;
    // 0x80018F8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018F90:
    // 0x80018F90: jal         0x800012A8
    // 0x80018F94: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade(rdram, ctx);
        goto after_6;
    // 0x80018F94: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_6:
    // 0x80018F98: blez        $v0, L_80018FB8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80018F9C: nop
    
            goto L_80018FB8;
    }
    // 0x80018F9C: nop

    // 0x80018FA0: jal         0x8000114C
    // 0x80018FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    music_channel_active(rdram, ctx);
        goto after_7;
    // 0x80018FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80018FA8: bne         $v0, $zero, L_80018FB8
    if (ctx->r2 != 0) {
        // 0x80018FAC: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80018FB8;
    }
    // 0x80018FAC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80018FB0: jal         0x80001268
    // 0x80018FB4: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_8;
    // 0x80018FB4: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_8:
L_80018FB8:
    // 0x80018FB8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80018FBC:
    // 0x80018FBC: bne         $s1, $s7, L_80018F34
    if (ctx->r17 != ctx->r23) {
        // 0x80018FC0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80018F34;
    }
    // 0x80018FC0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80018FC4: b           L_8001926C
    // 0x80018FC8: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
        goto L_8001926C;
    // 0x80018FC8: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80018FCC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
L_80018FD0:
    // 0x80018FD0: bne         $v0, $at, L_800191B8
    if (ctx->r2 != ctx->r1) {
        // 0x80018FD4: addiu       $at, $zero, 0x76
        ctx->r1 = ADD32(0, 0X76);
            goto L_800191B8;
    }
    // 0x80018FD4: addiu       $at, $zero, 0x76
    ctx->r1 = ADD32(0, 0X76);
    // 0x80018FD8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80018FDC: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80018FE0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80018FE4: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80018FE8: mul.s       $f30, $f16, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80018FEC: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80018FF0: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x80018FF4: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80018FF8: mul.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80018FFC: lwc1        $f24, 0xC($s4)
    ctx->f24.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80019000: lwc1        $f26, 0x10($s4)
    ctx->f26.u32l = MEM_W(ctx->r20, 0X10);
    // 0x80019004: lwc1        $f20, 0x14($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80019008: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8001900C: lwc1        $f28, 0x14($s4)
    ctx->f28.u32l = MEM_W(ctx->r20, 0X14);
    // 0x80019010: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    // 0x80019014: mul.s       $f10, $f12, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x80019018: add.s       $f8, $f6, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f30.fl;
    // 0x8001901C: mul.s       $f6, $f16, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80019020: add.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x80019024: add.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80019028: mul.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8001902C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80019030: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80019034: nop

    // 0x80019038: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8001903C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80019040: bc1f        L_80019068
    if (!c1cs) {
        // 0x80019044: add.s       $f2, $f10, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f20.fl;
            goto L_80019068;
    }
    // 0x80019044: add.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x80019048: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001904C: sll         $v1, $s5, 24
    ctx->r3 = S32(ctx->r21 << 24);
    // 0x80019050: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80019054: sra         $t6, $v1, 24
    ctx->r14 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80019058: bc1f        L_80019068
    if (!c1cs) {
        // 0x8001905C: nop
    
            goto L_80019068;
    }
    // 0x8001905C: nop

    // 0x80019060: b           L_800190A0
    // 0x80019064: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
        goto L_800190A0;
    // 0x80019064: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80019068:
    // 0x80019068: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001906C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019070: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80019074: nop

    // 0x80019078: bc1f        L_800190A0
    if (!c1cs) {
        // 0x8001907C: nop
    
            goto L_800190A0;
    }
    // 0x8001907C: nop

    // 0x80019080: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80019084: nop

    // 0x80019088: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8001908C: nop

    // 0x80019090: bc1f        L_800190A0
    if (!c1cs) {
        // 0x80019094: nop
    
            goto L_800190A0;
    }
    // 0x80019094: nop

    // 0x80019098: b           L_800190A0
    // 0x8001909C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_800190A0;
    // 0x8001909C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800190A0:
    // 0x800190A0: beq         $v1, $zero, L_8001926C
    if (ctx->r3 == 0) {
        // 0x800190A4: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x800190A4: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x800190A8: lwc1        $f6, 0x104($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800190AC: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
    // 0x800190B0: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800190B4: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800190B8: lwc1        $f4, 0x10C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800190BC: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800190C0: sub.s       $f2, $f26, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f26.fl - ctx->f8.fl;
    // 0x800190C4: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800190C8: sub.s       $f10, $f10, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f30.fl;
    // 0x800190CC: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x800190D0: sub.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800190D4: sub.s       $f0, $f24, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f6.fl;
    // 0x800190D8: sub.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800190DC: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800190E0: sub.s       $f14, $f28, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f28.fl - ctx->f4.fl;
    // 0x800190E4: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800190E8: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800190EC: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800190F0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800190F4: nop

    // 0x800190F8: div.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800190FC: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80019100: mul.s       $f4, $f22, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80019104: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80019108: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x8001910C: nop

    // 0x80019110: bc1f        L_8001926C
    if (!c1cs) {
        // 0x80019114: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019114: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019118: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8001911C: nop

    // 0x80019120: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x80019124: nop

    // 0x80019128: bc1f        L_8001926C
    if (!c1cs) {
        // 0x8001912C: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x8001912C: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019130: mul.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80019134: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80019138: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8001913C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80019140: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80019144: nop

    // 0x80019148: bc1f        L_8001926C
    if (!c1cs) {
        // 0x8001914C: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x8001914C: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019150: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80019154: nop

    // 0x80019158: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8001915C: nop

    // 0x80019160: bc1f        L_8001926C
    if (!c1cs) {
        // 0x80019164: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019164: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019168: mul.s       $f4, $f22, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8001916C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80019170: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80019174: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80019178: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8001917C: nop

    // 0x80019180: bc1f        L_8001926C
    if (!c1cs) {
        // 0x80019184: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019184: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019188: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8001918C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80019190: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80019194: nop

    // 0x80019198: bc1f        L_8001926C
    if (!c1cs) {
        // 0x8001919C: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x8001919C: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x800191A0: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x800191A4: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800191A8: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800191AC: b           L_80019268
    // 0x800191B0: sw          $v0, -0x4B20($at)
    MEM_W(-0X4B20, ctx->r1) = ctx->r2;
        goto L_80019268;
    // 0x800191B0: sw          $v0, -0x4B20($at)
    MEM_W(-0X4B20, ctx->r1) = ctx->r2;
    // 0x800191B4: addiu       $at, $zero, 0x76
    ctx->r1 = ADD32(0, 0X76);
L_800191B8:
    // 0x800191B8: bne         $v0, $at, L_8001926C
    if (ctx->r2 != ctx->r1) {
        // 0x800191BC: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x800191BC: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x800191C0: lwc1        $f4, 0xC($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0XC);
    // 0x800191C4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800191C8: lwc1        $f8, 0x10($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X10);
    // 0x800191CC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800191D0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800191D4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800191D8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800191DC: lwc1        $f4, 0x14($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X14);
    // 0x800191E0: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800191E4: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800191E8: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x800191EC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800191F0: nop

    // 0x800191F4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800191F8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800191FC: jal         0x800CA030
    // 0x80019200: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x80019200: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_9:
    // 0x80019204: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x80019208: nop

    // 0x8001920C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80019210: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80019214: nop

    // 0x80019218: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001921C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80019220: nop

    // 0x80019224: bc1f        L_8001926C
    if (!c1cs) {
        // 0x80019228: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019228: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x8001922C: jal         0x8000105C
    // 0x80019230: nop

    music_channel_get_mask(rdram, ctx);
        goto after_10;
    // 0x80019230: nop

    after_10:
    // 0x80019234: lhu         $t0, 0x0($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X0);
    // 0x80019238: nop

    // 0x8001923C: beq         $t0, $v0, L_8001926C
    if (ctx->r8 == ctx->r2) {
        // 0x80019240: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019240: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x80019244: jal         0x80001918
    // 0x80019248: nop

    music_current_sequence(rdram, ctx);
        goto after_11;
    // 0x80019248: nop

    after_11:
    // 0x8001924C: lbu         $t1, 0x3($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X3);
    // 0x80019250: nop

    // 0x80019254: bne         $t1, $v0, L_8001926C
    if (ctx->r9 != ctx->r2) {
        // 0x80019258: lw          $t2, 0xF4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XF4);
            goto L_8001926C;
    }
    // 0x80019258: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
    // 0x8001925C: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80019260: jal         0x80001074
    // 0x80019264: nop

    music_dynamic_set(rdram, ctx);
        goto after_12;
    // 0x80019264: nop

    after_12:
L_80019268:
    // 0x80019268: lw          $t2, 0xF4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF4);
L_8001926C:
    // 0x8001926C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80019270: lw          $t8, -0x4C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4C24);
    // 0x80019274: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x80019278: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8001927C: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80019280: addiu       $t4, $t5, 0x4
    ctx->r12 = ADD32(ctx->r13, 0X4);
    // 0x80019284: sw          $t4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r12;
    // 0x80019288: bne         $at, $zero, L_80018DD4
    if (ctx->r1 != 0) {
        // 0x8001928C: sw          $t3, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r11;
            goto L_80018DD4;
    }
    // 0x8001928C: sw          $t3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r11;
L_80019290:
    // 0x80019290: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80019294: lw          $t7, -0x4B20($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4B20);
    // 0x80019298: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8001929C: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800192A0: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x800192A4: beq         $t7, $zero, L_80019530
    if (ctx->r15 == 0) {
        // 0x800192A8: addiu       $fp, $zero, 0x7F
        ctx->r30 = ADD32(0, 0X7F);
            goto L_80019530;
    }
    // 0x800192A8: addiu       $fp, $zero, 0x7F
    ctx->r30 = ADD32(0, 0X7F);
    // 0x800192AC: jal         0x80001918
    // 0x800192B0: nop

    music_current_sequence(rdram, ctx);
        goto after_13;
    // 0x800192B0: nop

    after_13:
    // 0x800192B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800192B8: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x800192BC: lw          $t0, 0x110($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X110);
    // 0x800192C0: lbu         $t6, 0x40($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X40);
    // 0x800192C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800192C8: bne         $t6, $v0, L_800194F8
    if (ctx->r14 != ctx->r2) {
        // 0x800192CC: addiu       $s4, $zero, 0x3
        ctx->r20 = ADD32(0, 0X3);
            goto L_800194F8;
    }
    // 0x800192CC: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800192D0: lhu         $t9, 0x4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4);
    // 0x800192D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800192D8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800192DC: sh          $t1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r9;
    // 0x800192E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800192E4: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x800192E8: lw          $t5, 0x6710($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6710);
    // 0x800192EC: lbu         $t2, 0x2($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2);
    // 0x800192F0: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x800192F4: multu       $t2, $t5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800192F8: addiu       $t8, $zero, 0xFE
    ctx->r24 = ADD32(0, 0XFE);
    // 0x800192FC: mflo        $a0
    ctx->r4 = lo;
    // 0x80019300: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x80019304: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80019308: beq         $at, $zero, L_80019328
    if (ctx->r1 == 0) {
        // 0x8001930C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_80019328;
    }
    // 0x8001930C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80019310: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
    // 0x80019314: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80019318: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x8001931C: nop

    // 0x80019320: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x80019324: nop

L_80019328:
    // 0x80019328: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001932C: bgez        $v0, L_80019344
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80019330: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80019344;
    }
    // 0x80019330: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80019334: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80019338: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001933C: nop

    // 0x80019340: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80019344:
    // 0x80019344: lui         $at, 0x437E
    ctx->r1 = S32(0X437E << 16);
    // 0x80019348: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001934C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80019350: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80019354: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80019358: bgez        $a0, L_8001936C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001935C: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8001936C;
    }
    // 0x8001935C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80019360: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80019364: nop

    // 0x80019368: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8001936C:
    // 0x8001936C: nop

    // 0x80019370: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80019374: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80019378: nop

    // 0x8001937C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80019380: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80019384: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80019388: nop

    // 0x8001938C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80019390: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80019394: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80019398: slti        $at, $a1, 0xFE
    ctx->r1 = SIGNED(ctx->r5) < 0XFE ? 1 : 0;
    // 0x8001939C: beq         $at, $zero, L_800193AC
    if (ctx->r1 == 0) {
        // 0x800193A0: nop
    
            goto L_800193AC;
    }
    // 0x800193A0: nop

    // 0x800193A4: b           L_800193B0
    // 0x800193A8: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
        goto L_800193B0;
    // 0x800193A8: sb          $a1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r5;
L_800193AC:
    // 0x800193AC: sb          $t8, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r24;
L_800193B0:
    // 0x800193B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800193B4: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x800193B8: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800193BC:
    // 0x800193BC: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x800193C0: addu        $t7, $v1, $s1
    ctx->r15 = ADD32(ctx->r3, ctx->r17);
    // 0x800193C4: lb          $v0, 0x30($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X30);
    // 0x800193C8: bne         $s3, $t6, L_800193D8
    if (ctx->r19 != ctx->r14) {
        // 0x800193CC: sra         $t9, $v0, 2
        ctx->r25 = S32(SIGNED(ctx->r2) >> 2);
            goto L_800193D8;
    }
    // 0x800193CC: sra         $t9, $v0, 2
    ctx->r25 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800193D0: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x800193D4: sra         $v0, $t0, 24
    ctx->r2 = S32(SIGNED(ctx->r8) >> 24);
L_800193D8:
    // 0x800193D8: andi        $t2, $v0, 0x3
    ctx->r10 = ctx->r2 & 0X3;
    // 0x800193DC: sll         $t5, $t2, 24
    ctx->r13 = S32(ctx->r10 << 24);
    // 0x800193E0: sra         $t4, $t5, 24
    ctx->r12 = S32(SIGNED(ctx->r13) >> 24);
    // 0x800193E4: beq         $t4, $zero, L_80019430
    if (ctx->r12 == 0) {
        // 0x800193E8: nop
    
            goto L_80019430;
    }
    // 0x800193E8: nop

    // 0x800193EC: beq         $t4, $s5, L_8001940C
    if (ctx->r12 == ctx->r21) {
        // 0x800193F0: andi        $s0, $s1, 0xFF
        ctx->r16 = ctx->r17 & 0XFF;
            goto L_8001940C;
    }
    // 0x800193F0: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x800193F4: beq         $t4, $s6, L_80019498
    if (ctx->r12 == ctx->r22) {
        // 0x800193F8: nop
    
            goto L_80019498;
    }
    // 0x800193F8: nop

    // 0x800193FC: beq         $t4, $s4, L_80019448
    if (ctx->r12 == ctx->r20) {
        // 0x80019400: nop
    
            goto L_80019448;
    }
    // 0x80019400: nop

    // 0x80019404: b           L_800194F0
    // 0x80019408: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194F0;
    // 0x80019408: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001940C:
    // 0x8001940C: jal         0x80001170
    // 0x80019410: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_14;
    // 0x80019410: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_14:
    // 0x80019414: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80019418: jal         0x80001268
    // 0x8001941C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    music_channel_fade_set(rdram, ctx);
        goto after_15;
    // 0x8001941C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_15:
    // 0x80019420: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80019424: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x80019428: b           L_800194F0
    // 0x8001942C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194F0;
    // 0x8001942C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80019430:
    // 0x80019430: jal         0x80001114
    // 0x80019434: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_16;
    // 0x80019434: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_16:
    // 0x80019438: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001943C: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x80019440: b           L_800194F0
    // 0x80019444: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194F0;
    // 0x80019444: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80019448:
    // 0x80019448: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8001944C: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x80019450: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80019454: bne         $at, $zero, L_80019488
    if (ctx->r1 != 0) {
        // 0x80019458: addiu       $s2, $v0, -0x7F
        ctx->r18 = ADD32(ctx->r2, -0X7F);
            goto L_80019488;
    }
    // 0x80019458: addiu       $s2, $v0, -0x7F
    ctx->r18 = ADD32(ctx->r2, -0X7F);
    // 0x8001945C: andi        $t3, $s2, 0xFF
    ctx->r11 = ctx->r18 & 0XFF;
    // 0x80019460: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
    // 0x80019464: jal         0x80001170
    // 0x80019468: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_17;
    // 0x80019468: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_17:
    // 0x8001946C: jal         0x800012A8
    // 0x80019470: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade(rdram, ctx);
        goto after_18;
    // 0x80019470: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_18:
    // 0x80019474: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80019478: beq         $at, $zero, L_80019488
    if (ctx->r1 == 0) {
        // 0x8001947C: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80019488;
    }
    // 0x8001947C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80019480: jal         0x80001268
    // 0x80019484: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_19;
    // 0x80019484: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_19:
L_80019488:
    // 0x80019488: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001948C: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x80019490: b           L_800194F0
    // 0x80019494: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800194F0;
    // 0x80019494: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80019498:
    // 0x80019498: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8001949C: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x800194A0: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800194A4: beq         $at, $zero, L_800194D8
    if (ctx->r1 == 0) {
        // 0x800194A8: subu        $s2, $fp, $v0
        ctx->r18 = SUB32(ctx->r30, ctx->r2);
            goto L_800194D8;
    }
    // 0x800194A8: subu        $s2, $fp, $v0
    ctx->r18 = SUB32(ctx->r30, ctx->r2);
    // 0x800194AC: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x800194B0: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800194B4: jal         0x800012A8
    // 0x800194B8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_fade(rdram, ctx);
        goto after_20;
    // 0x800194B8: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_20:
    // 0x800194BC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800194C0: beq         $at, $zero, L_800194E0
    if (ctx->r1 == 0) {
        // 0x800194C4: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_800194E0;
    }
    // 0x800194C4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800194C8: jal         0x80001268
    // 0x800194CC: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_21;
    // 0x800194CC: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_21:
    // 0x800194D0: b           L_800194E0
    // 0x800194D4: nop

        goto L_800194E0;
    // 0x800194D4: nop

L_800194D8:
    // 0x800194D8: jal         0x80001114
    // 0x800194DC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_22;
    // 0x800194DC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_22:
L_800194E0:
    // 0x800194E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800194E4: lw          $v1, -0x4B20($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B20);
    // 0x800194E8: nop

    // 0x800194EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800194F0:
    // 0x800194F0: bne         $s1, $s7, L_800193BC
    if (ctx->r17 != ctx->r23) {
        // 0x800194F4: nop
    
            goto L_800193BC;
    }
    // 0x800194F4: nop

L_800194F8:
    // 0x800194F8: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x800194FC: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x80019500: bne         $t7, $at, L_80019534
    if (ctx->r15 != ctx->r1) {
        // 0x80019504: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80019534;
    }
    // 0x80019504: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80019508: jal         0x80001918
    // 0x8001950C: nop

    music_current_sequence(rdram, ctx);
        goto after_23;
    // 0x8001950C: nop

    after_23:
    // 0x80019510: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80019514: lw          $t6, -0x4B20($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B20);
    // 0x80019518: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001951C: lbu         $t9, 0x40($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X40);
    // 0x80019520: nop

    // 0x80019524: bne         $t9, $v0, L_80019534
    if (ctx->r25 != ctx->r2) {
        // 0x80019528: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80019534;
    }
    // 0x80019528: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8001952C: sw          $zero, -0x4B20($at)
    MEM_W(-0X4B20, ctx->r1) = 0;
L_80019530:
    // 0x80019530: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80019534:
    // 0x80019534: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80019538: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001953C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80019540: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80019544: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80019548: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001954C: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80019550: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80019554: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80019558: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001955C: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80019560: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80019564: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80019568: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8001956C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80019570: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80019574: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80019578: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8001957C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80019580: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80019584: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80019588: jr          $ra
    // 0x8001958C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x8001958C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void osScAddClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800798D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800798D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800798D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800798DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800798E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800798E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800798E8: jal         0x800C9F90
    // 0x800798EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800798EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800798F0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800798F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800798F8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800798FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80079900: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x80079904: lw          $t7, 0x260($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X260);
    // 0x80079908: nop

    // 0x8007990C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80079910: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x80079914: nop

    // 0x80079918: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x8007991C: jal         0x800C9F90
    // 0x80079920: sw          $a1, 0x260($v1)
    MEM_W(0X260, ctx->r3) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80079920: sw          $a1, 0x260($v1)
    MEM_W(0X260, ctx->r3) = ctx->r5;
    after_1:
    // 0x80079924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80079928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007992C: jr          $ra
    // 0x80079930: nop

    return;
    // 0x80079930: nop

;}
RECOMP_FUNC void debug_print_float_matrix_values(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A27C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006A280: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8006A284: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006A288: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8006A28C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8006A290: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8006A294: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006A298: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8006A29C: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8006A2A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006A2A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006A2A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006A2AC: addiu       $s6, $s6, 0x7624
    ctx->r22 = ADD32(ctx->r22, 0X7624);
    // 0x8006A2B0: addiu       $s2, $s2, 0x761C
    ctx->r18 = ADD32(ctx->r18, 0X761C);
    // 0x8006A2B4: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x8006A2B8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8006A2BC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8006A2C0: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
L_8006A2C4:
    // 0x8006A2C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006A2C8: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
L_8006A2CC:
    // 0x8006A2CC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006A2D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006A2D4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8006A2D8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8006A2DC: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x8006A2E0: jal         0x800CA2B4
    // 0x8006A2E4: nop

    rmonPrintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A2E4: nop

    after_0:
    // 0x8006A2E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8006A2EC: bne         $s0, $s3, L_8006A2CC
    if (ctx->r16 != ctx->r19) {
        // 0x8006A2F0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8006A2CC;
    }
    // 0x8006A2F0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8006A2F4: jal         0x800CA2B4
    // 0x8006A2F8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A2F8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x8006A2FC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8006A300: bne         $s4, $s7, L_8006A2C4
    if (ctx->r20 != ctx->r23) {
        // 0x8006A304: addiu       $s5, $s5, 0x10
        ctx->r21 = ADD32(ctx->r21, 0X10);
            goto L_8006A2C4;
    }
    // 0x8006A304: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x8006A308: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006A30C: jal         0x800CA2B4
    // 0x8006A310: addiu       $a0, $a0, 0x7628
    ctx->r4 = ADD32(ctx->r4, 0X7628);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8006A310: addiu       $a0, $a0, 0x7628
    ctx->r4 = ADD32(ctx->r4, 0X7628);
    after_2:
    // 0x8006A314: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006A318: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006A31C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006A320: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A324: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006A328: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8006A32C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8006A330: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A334: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8006A338: jr          $ra
    // 0x8006A33C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006A33C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void credits_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C234: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009C238: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009C23C: jal         0x80000BE0
    // 0x8009C240: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    music_voicelimit_set(rdram, ctx);
        goto after_0;
    // 0x8009C240: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_0:
    // 0x8009C244: jal         0x800C06A0
    // 0x8009C248: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_1;
    // 0x8009C248: nop

    after_1:
    // 0x8009C24C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009C250: jal         0x80066AD4
    // 0x8009C254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_2;
    // 0x8009C254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8009C258: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8009C25C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009C260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009C264: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8009C268: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x8009C26C: jal         0x80066CE8
    // 0x8009C270: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    set_viewport_properties(rdram, ctx);
        goto after_3;
    // 0x8009C270: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    after_3:
    // 0x8009C274: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009C278: jal         0x8009C9EC
    // 0x8009C27C: addiu       $a0, $a0, 0x1D58
    ctx->r4 = ADD32(ctx->r4, 0X1D58);
    menu_assetgroup_free(rdram, ctx);
        goto after_4;
    // 0x8009C27C: addiu       $a0, $a0, 0x1D58
    ctx->r4 = ADD32(ctx->r4, 0X1D58);
    after_4:
    // 0x8009C280: jal         0x800C478C
    // 0x8009C284: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_5;
    // 0x8009C284: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x8009C288: jal         0x8006F7A4
    // 0x8009C28C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_gIntDisFlag(rdram, ctx);
        goto after_6;
    // 0x8009C28C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8009C290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009C294: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009C298: jr          $ra
    // 0x8009C29C: nop

    return;
    // 0x8009C29C: nop

;}
RECOMP_FUNC void bgload_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79B8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C79BC: addiu       $v1, $v1, 0x3D00
    ctx->r3 = ADD32(ctx->r3, 0X3D00);
    // 0x800C79C0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C79C4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800C79C8: bne         $t6, $zero, L_800C79F4
    if (ctx->r14 != 0) {
        // 0x800C79CC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800C79F4;
    }
    // 0x800C79CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C79D0: sw          $t7, 0x3D0C($at)
    MEM_W(0X3D0C, ctx->r1) = ctx->r15;
    // 0x800C79D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C79D8: sw          $a0, 0x3D04($at)
    MEM_W(0X3D04, ctx->r1) = ctx->r4;
    // 0x800C79DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C79E0: sw          $a1, 0x3D08($at)
    MEM_W(0X3D08, ctx->r1) = ctx->r5;
    // 0x800C79E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C79E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C79EC: jr          $ra
    // 0x800C79F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C79F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C79F4:
    // 0x800C79F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C79F8: jr          $ra
    // 0x800C79FC: nop

    return;
    // 0x800C79FC: nop

;}
RECOMP_FUNC void get_game_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DC4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DC50: lw          $v0, 0x3A6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A6C);
    // 0x8006DC54: jr          $ra
    // 0x8006DC58: nop

    return;
    // 0x8006DC58: nop

;}
RECOMP_FUNC void obj_loop_worldkey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DF48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DF50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003DF54: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DF58: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003DF5C: lbu         $t6, 0x13($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X13);
    // 0x8003DF60: nop

    // 0x8003DF64: slti        $at, $t6, 0x32
    ctx->r1 = SIGNED(ctx->r14) < 0X32 ? 1 : 0;
    // 0x8003DF68: beq         $at, $zero, L_8003DFEC
    if (ctx->r1 == 0) {
        // 0x8003DF6C: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFEC;
    }
    // 0x8003DF6C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003DF74: nop

    // 0x8003DF78: beq         $v0, $zero, L_8003DFEC
    if (ctx->r2 == 0) {
        // 0x8003DF7C: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFEC;
    }
    // 0x8003DF7C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF80: lw          $t7, 0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X40);
    // 0x8003DF84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003DF88: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x8003DF8C: nop

    // 0x8003DF90: bne         $t8, $at, L_8003DFEC
    if (ctx->r24 != ctx->r1) {
        // 0x8003DF94: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFEC;
    }
    // 0x8003DF94: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF98: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003DF9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003DFA0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x8003DFA4: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x8003DFA8: beq         $t9, $at, L_8003DFEC
    if (ctx->r25 == ctx->r1) {
        // 0x8003DFAC: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8003DFEC;
    }
    // 0x8003DFAC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DFB0: jal         0x80001BC0
    // 0x8003DFB4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    music_jingle_play(rdram, ctx);
        goto after_0;
    // 0x8003DFB4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003DFB8: jal         0x8006ECD0
    // 0x8003DFBC: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x8003DFBC: nop

    after_1:
    // 0x8003DFC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DFC4: lhu         $t0, 0x8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X8);
    // 0x8003DFC8: lw          $t1, 0x78($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X78);
    // 0x8003DFCC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003DFD0: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x8003DFD4: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8003DFD8: jal         0x8000FFB8
    // 0x8003DFDC: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    free_object(rdram, ctx);
        goto after_2;
    // 0x8003DFDC: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    after_2:
    // 0x8003DFE0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8003DFE4: nop

    // 0x8003DFE8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_8003DFEC:
    // 0x8003DFEC: lh          $t5, 0x0($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X0);
    // 0x8003DFF0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8003DFF4: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8003DFF8: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8003DFFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E000: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E004: jr          $ra
    // 0x8003E008: nop

    return;
    // 0x8003E008: nop

;}
RECOMP_FUNC void sprite_table_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B2B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B2B8: lw          $v0, 0x68F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68F4);
    // 0x8007B2BC: jr          $ra
    // 0x8007B2C0: nop

    return;
    // 0x8007B2C0: nop

;}
RECOMP_FUNC void set_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006FB50: jr          $ra
    // 0x8006FB54: sw          $a0, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = ctx->r4;
    return;
    // 0x8006FB54: sw          $a0, -0x265C($at)
    MEM_W(-0X265C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void racer_attack_handler_car(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053EDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80053EE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80053EE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80053EE8: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80053EEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80053EF0: bne         $t6, $at, L_80053F00
    if (ctx->r14 != ctx->r1) {
        // 0x80053EF4: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_80053F00;
    }
    // 0x80053EF4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80053EF8: b           L_80053F0C
    // 0x80053EFC: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
        goto L_80053F0C;
    // 0x80053EFC: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
L_80053F00:
    // 0x80053F00: lb          $t7, 0x185($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X185);
    // 0x80053F04: nop

    // 0x80053F08: sb          $t7, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r15;
L_80053F0C:
    // 0x80053F0C: lb          $v0, 0x1ED($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1ED);
    // 0x80053F10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053F14: blez        $v0, L_80053F60
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80053F18: subu        $t8, $v0, $a2
        ctx->r24 = SUB32(ctx->r2, ctx->r6);
            goto L_80053F60;
    }
    // 0x80053F18: subu        $t8, $v0, $a2
    ctx->r24 = SUB32(ctx->r2, ctx->r6);
    // 0x80053F1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80053F20: sb          $t8, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r24;
    // 0x80053F24: swc1        $f4, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f4.u32l;
    // 0x80053F28: lwc1        $f6, 0x6D30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D30);
    // 0x80053F2C: lb          $t9, 0x1ED($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1ED);
    // 0x80053F30: swc1        $f6, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f6.u32l;
    // 0x80053F34: bgtz        $t9, L_80053F64
    if (SIGNED(ctx->r25) > 0) {
        // 0x80053F38: nop
    
            goto L_80053F64;
    }
    // 0x80053F38: nop

    // 0x80053F3C: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x80053F40: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x80053F44: bltz        $t0, L_80053F64
    if (SIGNED(ctx->r8) < 0) {
        // 0x80053F48: nop
    
            goto L_80053F64;
    }
    // 0x80053F48: nop

    // 0x80053F4C: jal         0x80057088
    // 0x80053F50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    racer_play_sound(rdram, ctx);
        goto after_0;
    // 0x80053F50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80053F54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80053F58: b           L_80053F68
    // 0x80053F5C: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
        goto L_80053F68;
    // 0x80053F5C: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
L_80053F60:
    // 0x80053F60: sb          $zero, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = 0;
L_80053F64:
    // 0x80053F64: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
L_80053F68:
    // 0x80053F68: nop

    // 0x80053F6C: beq         $v0, $zero, L_80053F84
    if (ctx->r2 == 0) {
        // 0x80053F70: nop
    
            goto L_80053F84;
    }
    // 0x80053F70: nop

    // 0x80053F74: lh          $t1, 0x18E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X18E);
    // 0x80053F78: nop

    // 0x80053F7C: blez        $t1, L_80053F8C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80053F80: nop
    
            goto L_80053F8C;
    }
    // 0x80053F80: nop

L_80053F84:
    // 0x80053F84: b           L_80054140
    // 0x80053F88: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
        goto L_80054140;
    // 0x80053F88: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_80053F8C:
    // 0x80053F8C: lb          $t2, 0x1ED($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1ED);
    // 0x80053F90: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053F94: beq         $t2, $zero, L_80053FA0
    if (ctx->r10 == 0) {
        // 0x80053F98: nop
    
            goto L_80053FA0;
    }
    // 0x80053F98: nop

    // 0x80053F9C: beq         $v0, $at, L_80054140
    if (ctx->r2 == ctx->r1) {
        // 0x80053FA0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80054140;
    }
L_80053FA0:
    // 0x80053FA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80053FA4: beq         $v0, $at, L_80053FC8
    if (ctx->r2 == ctx->r1) {
        // 0x80053FA8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80053FC8;
    }
    // 0x80053FA8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80053FAC: beq         $v0, $at, L_80053FC8
    if (ctx->r2 == ctx->r1) {
        // 0x80053FB0: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80053FC8;
    }
    // 0x80053FB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80053FB4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80053FB8: jal         0x80057720
    // 0x80053FBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    drop_bananas(rdram, ctx);
        goto after_1;
    // 0x80053FBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x80053FC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80053FC4: nop

L_80053FC8:
    // 0x80053FC8: lbu         $t4, 0x1C9($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1C9);
    // 0x80053FCC: addiu       $t3, $zero, 0x168
    ctx->r11 = ADD32(0, 0X168);
    // 0x80053FD0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80053FD4: bne         $t4, $at, L_80053FE0
    if (ctx->r12 != ctx->r1) {
        // 0x80053FD8: sh          $t3, 0x18C($s0)
        MEM_H(0X18C, ctx->r16) = ctx->r11;
            goto L_80053FE0;
    }
    // 0x80053FD8: sh          $t3, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r11;
    // 0x80053FDC: sb          $zero, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = 0;
L_80053FE0:
    // 0x80053FE0: lb          $t5, 0x1D6($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D6);
    // 0x80053FE4: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x80053FE8: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x80053FEC: beq         $at, $zero, L_80054140
    if (ctx->r1 == 0) {
        // 0x80053FF0: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_80054140;
    }
    // 0x80053FF0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80053FF4: addiu       $a3, $zero, 0x81
    ctx->r7 = ADD32(0, 0X81);
    // 0x80053FF8: jal         0x800570F8
    // 0x80053FFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    play_random_character_voice(rdram, ctx);
        goto after_2;
    // 0x80053FFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x80054000: lb          $t6, 0x187($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X187);
    // 0x80054004: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80054008: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8005400C: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80054010: beq         $at, $zero, L_8005413C
    if (ctx->r1 == 0) {
        // 0x80054014: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8005413C;
    }
    // 0x80054014: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80054018: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005401C: addu        $at, $at, $t7
    gpr jr_addend_80054028 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80054020: lw          $t7, 0x6D34($at)
    ctx->r15 = ADD32(ctx->r1, 0X6D34);
    // 0x80054024: nop

    // 0x80054028: jr          $t7
    // 0x8005402C: nop

    switch (jr_addend_80054028 >> 2) {
        case 0: goto L_80054030; break;
        case 1: goto L_800540AC; break;
        case 2: goto L_8005413C; break;
        case 3: goto L_800540CC; break;
        case 4: goto L_80054104; break;
        case 5: goto L_800540D8; break;
        default: switch_error(__func__, 0x80054028, 0x800E6D34);
    }
    // 0x8005402C: nop

L_80054030:
    // 0x80054030: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80054034: sb          $t8, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r24;
    // 0x80054038: lb          $t9, 0x27($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X27);
    // 0x8005403C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80054040: bne         $t9, $zero, L_80054074
    if (ctx->r25 != 0) {
        // 0x80054044: nop
    
            goto L_80054074;
    }
    // 0x80054044: nop

    // 0x80054048: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005404C: lui         $at, 0x4025
    ctx->r1 = S32(0X4025 << 16);
    // 0x80054050: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80054054: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80054058: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005405C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80054060: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80054064: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80054068: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005406C: b           L_8005413C
    // 0x80054070: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
        goto L_8005413C;
    // 0x80054070: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
L_80054074:
    // 0x80054074: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80054078: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005407C: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
    // 0x80054080: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80054084: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80054088: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005408C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80054090: lwc1        $f18, 0x20($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80054094: nop

    // 0x80054098: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8005409C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800540A0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800540A4: b           L_8005413C
    // 0x800540A8: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
        goto L_8005413C;
    // 0x800540A8: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
L_800540AC:
    // 0x800540AC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800540B0: addiu       $t1, $zero, 0x1002
    ctx->r9 = ADD32(0, 0X1002);
    // 0x800540B4: sb          $t0, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r8;
    // 0x800540B8: sh          $t1, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r9;
    // 0x800540BC: jal         0x80057088
    // 0x800540C0: addiu       $a1, $zero, 0x13B
    ctx->r5 = ADD32(0, 0X13B);
    racer_play_sound(rdram, ctx);
        goto after_3;
    // 0x800540C0: addiu       $a1, $zero, 0x13B
    ctx->r5 = ADD32(0, 0X13B);
    after_3:
    // 0x800540C4: b           L_80054140
    // 0x800540C8: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
        goto L_80054140;
    // 0x800540C8: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_800540CC:
    // 0x800540CC: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x800540D0: b           L_8005413C
    // 0x800540D4: sb          $t2, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r10;
        goto L_8005413C;
    // 0x800540D4: sb          $t2, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r10;
L_800540D8:
    // 0x800540D8: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800540DC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800540E0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800540E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800540E8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800540EC: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800540F0: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x800540F4: sh          $t3, 0x204($s0)
    MEM_H(0X204, ctx->r16) = ctx->r11;
    // 0x800540F8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800540FC: b           L_8005413C
    // 0x80054100: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
        goto L_8005413C;
    // 0x80054100: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_80054104:
    // 0x80054104: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80054108: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005410C: sb          $t4, 0x1F1($s0)
    MEM_B(0X1F1, ctx->r16) = ctx->r12;
    // 0x80054110: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x80054114: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054118: lwc1        $f16, 0x20($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8005411C: lwc1        $f5, 0x6D50($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6D50);
    // 0x80054120: lwc1        $f4, 0x6D54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D54);
    // 0x80054124: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80054128: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x8005412C: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    // 0x80054130: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80054134: jal         0x80057088
    // 0x80054138: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    racer_play_sound(rdram, ctx);
        goto after_4;
    // 0x80054138: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    after_4:
L_8005413C:
    // 0x8005413C: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_80054140:
    // 0x80054140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80054144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80054148: jr          $ra
    // 0x8005414C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005414C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void menu_file_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E328: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008E32C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008E330: jal         0x8006ECD0
    // 0x8008E334: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8008E334: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008E338: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8008E33C: jal         0x8008C620
    // 0x8008E340: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    charselect_music_channels(rdram, ctx);
        goto after_1;
    // 0x8008E340: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x8008E344: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E348: lw          $v0, 0x6978($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6978);
    // 0x8008E34C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E350: beq         $v0, $zero, L_8008E430
    if (ctx->r2 == 0) {
        // 0x8008E354: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8008E430;
    }
    // 0x8008E354: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8008E358: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
    // 0x8008E35C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008E360: lw          $t7, 0x6978($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6978);
    // 0x8008E364: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8008E368: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8008E36C: bne         $at, $zero, L_8008E430
    if (ctx->r1 != 0) {
        // 0x8008E370: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8008E430;
    }
    // 0x8008E370: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E374: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8008E378: addiu       $a3, $a3, 0x6AD0
    ctx->r7 = ADD32(ctx->r7, 0X6AD0);
    // 0x8008E37C: addiu       $v0, $v0, 0x6A40
    ctx->r2 = ADD32(ctx->r2, 0X6A40);
L_8008E380:
    // 0x8008E380: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8008E384: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008E388: lbu         $t8, 0x4B($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4B);
    // 0x8008E38C: addiu       $t4, $zero, 0x4B
    ctx->r12 = ADD32(0, 0X4B);
    // 0x8008E390: beq         $t8, $zero, L_8008E3BC
    if (ctx->r24 == 0) {
        // 0x8008E394: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008E3BC;
    }
    // 0x8008E394: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E398: addiu       $t9, $zero, 0x44
    ctx->r25 = ADD32(0, 0X44);
    // 0x8008E39C: addiu       $t5, $zero, 0x52
    ctx->r13 = ADD32(0, 0X52);
    // 0x8008E3A0: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x8008E3A4: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008E3A8: sb          $t9, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r25;
    // 0x8008E3AC: sb          $t4, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r12;
    // 0x8008E3B0: sb          $t5, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r13;
    // 0x8008E3B4: b           L_8008E410
    // 0x8008E3B8: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
        goto L_8008E410;
    // 0x8008E3B8: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
L_8008E3BC:
    // 0x8008E3BC: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x8008E3C0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8008E3C4: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8008E3C8: beq         $t7, $zero, L_8008E3D4
    if (ctx->r15 == 0) {
        // 0x8008E3CC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008E3D4;
    }
    // 0x8008E3CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008E3D0: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_8008E3D4:
    // 0x8008E3D4: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8008E3D8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008E3DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8008E3E0: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8008E3E4: nop

    // 0x8008E3E8: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x8008E3EC: lw          $a0, 0x50($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X50);
    // 0x8008E3F0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8008E3F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8008E3F8: jal         0x80097C34
    // 0x8008E3FC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    filename_decompress(rdram, ctx);
        goto after_2;
    // 0x8008E3FC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x8008E400: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8008E404: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8008E408: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008E40C: nop

L_8008E410:
    // 0x8008E410: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8008E414: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008E418: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8008E41C: bne         $t0, $at, L_8008E380
    if (ctx->r8 != ctx->r1) {
        // 0x8008E420: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8008E380;
    }
    // 0x8008E420: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8008E424: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E428: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x8008E42C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_8008E430:
    // 0x8008E430: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008E434: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008E438: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8008E43C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008E440: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008E444: addiu       $a2, $a2, -0x604
    ctx->r6 = ADD32(ctx->r6, -0X604);
    // 0x8008E448: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008E44C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8008E450: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008E454: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8008E458: beq         $v0, $zero, L_8008E480
    if (ctx->r2 == 0) {
        // 0x8008E45C: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008E480;
    }
    // 0x8008E45C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008E460: blez        $v0, L_8008E478
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008E464: subu        $t4, $v0, $a1
        ctx->r12 = SUB32(ctx->r2, ctx->r5);
            goto L_8008E478;
    }
    // 0x8008E464: subu        $t4, $v0, $a1
    ctx->r12 = SUB32(ctx->r2, ctx->r5);
    // 0x8008E468: addu        $t9, $v0, $a1
    ctx->r25 = ADD32(ctx->r2, ctx->r5);
    // 0x8008E46C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8008E470: b           L_8008E480
    // 0x8008E474: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8008E480;
    // 0x8008E474: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8008E478:
    // 0x8008E478: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8008E47C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_8008E480:
    // 0x8008E480: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x8008E484: bne         $at, $zero, L_8008E4B0
    if (ctx->r1 != 0) {
        // 0x8008E488: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_8008E4B0;
    }
    // 0x8008E488: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8008E48C: beq         $at, $zero, L_8008E4B0
    if (ctx->r1 == 0) {
        // 0x8008E490: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8008E4B0;
    }
    // 0x8008E490: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8008E494: jal         0x8008D22C
    // 0x8008E498: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    fileselect_render(rdram, ctx);
        goto after_3;
    // 0x8008E498: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_3:
    // 0x8008E49C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E4A0: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008E4A4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008E4A8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8008E4AC: nop

L_8008E4B0:
    // 0x8008E4B0: bne         $v0, $zero, L_8008E744
    if (ctx->r2 != 0) {
        // 0x8008E4B4: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8008E744;
    }
    // 0x8008E4B4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008E4B8: lw          $t5, 0x6978($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6978);
    // 0x8008E4BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E4C0: bne         $t5, $zero, L_8008E744
    if (ctx->r13 != 0) {
        // 0x8008E4C4: nop
    
            goto L_8008E744;
    }
    // 0x8008E4C4: nop

    // 0x8008E4C8: lw          $t6, 0x6A24($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A24);
    // 0x8008E4CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008E4D0: beq         $t6, $zero, L_8008E4E8
    if (ctx->r14 == 0) {
        // 0x8008E4D4: nop
    
            goto L_8008E4E8;
    }
    // 0x8008E4D4: nop

    // 0x8008E4D8: jal         0x8008DD74
    // 0x8008E4DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    fileselect_input_copy(rdram, ctx);
        goto after_4;
    // 0x8008E4DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x8008E4E0: b           L_8008E744
    // 0x8008E4E4: nop

        goto L_8008E744;
    // 0x8008E4E4: nop

L_8008E4E8:
    // 0x8008E4E8: lw          $t7, 0x6A28($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A28);
    // 0x8008E4EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008E4F0: beq         $t7, $zero, L_8008E508
    if (ctx->r15 == 0) {
        // 0x8008E4F4: nop
    
            goto L_8008E508;
    }
    // 0x8008E4F4: nop

    // 0x8008E4F8: jal         0x8008E134
    // 0x8008E4FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    fileselect_input_erase(rdram, ctx);
        goto after_5;
    // 0x8008E4FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
    // 0x8008E500: b           L_8008E744
    // 0x8008E504: nop

        goto L_8008E744;
    // 0x8008E504: nop

L_8008E508:
    // 0x8008E508: lw          $t8, 0x7280($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7280);
    // 0x8008E50C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008E510: beq         $t8, $zero, L_8008E634
    if (ctx->r24 == 0) {
        // 0x8008E514: nop
    
            goto L_8008E634;
    }
    // 0x8008E514: nop

    // 0x8008E518: jal         0x8006A794
    // 0x8008E51C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_6;
    // 0x8008E51C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_6:
    // 0x8008E520: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8008E524: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x8008E528: beq         $t9, $zero, L_8008E584
    if (ctx->r25 == 0) {
        // 0x8008E52C: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8008E584;
    }
    // 0x8008E52C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008E530: lw          $t4, 0x1520($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1520);
    // 0x8008E534: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8008E538: bne         $t4, $zero, L_8008E584
    if (ctx->r12 != 0) {
        // 0x8008E53C: subu        $t5, $t5, $t0
        ctx->r13 = SUB32(ctx->r13, ctx->r8);
            goto L_8008E584;
    }
    // 0x8008E53C: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8008E540: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E544: addiu       $t6, $t6, 0x6A40
    ctx->r14 = ADD32(ctx->r14, 0X6A40);
    // 0x8008E548: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008E54C: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8008E550: jal         0x80098724
    // 0x8008E554: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    menu_unload_bigfont(rdram, ctx);
        goto after_7;
    // 0x8008E554: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_7:
    // 0x8008E558: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8008E55C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E560: sw          $zero, 0x7280($at)
    MEM_W(0X7280, ctx->r1) = 0;
    // 0x8008E564: addiu       $t7, $zero, 0x44
    ctx->r15 = ADD32(0, 0X44);
    // 0x8008E568: addiu       $t8, $zero, 0x4B
    ctx->r24 = ADD32(0, 0X4B);
    // 0x8008E56C: addiu       $t9, $zero, 0x52
    ctx->r25 = ADD32(0, 0X52);
    // 0x8008E570: sb          $t7, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r15;
    // 0x8008E574: sb          $t8, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r24;
    // 0x8008E578: sb          $t9, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r25;
    // 0x8008E57C: b           L_8008E744
    // 0x8008E580: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
        goto L_8008E744;
    // 0x8008E580: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
L_8008E584:
    // 0x8008E584: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8008E588: jal         0x8009824C
    // 0x8008E58C: nop

    filename_enter(rdram, ctx);
        goto after_8;
    // 0x8008E58C: nop

    after_8:
    // 0x8008E590: beq         $v0, $zero, L_8008E744
    if (ctx->r2 == 0) {
        // 0x8008E594: nop
    
            goto L_8008E744;
    }
    // 0x8008E594: nop

    // 0x8008E598: jal         0x80098724
    // 0x8008E59C: nop

    menu_unload_bigfont(rdram, ctx);
        goto after_9;
    // 0x8008E59C: nop

    after_9:
    // 0x8008E5A0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008E5A4: lw          $t4, -0x5B4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5B4);
    // 0x8008E5A8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E5AC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008E5B0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008E5B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E5B8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8008E5BC: addiu       $t6, $t6, 0x6A40
    ctx->r14 = ADD32(ctx->r14, 0X6A40);
    // 0x8008E5C0: sw          $zero, 0x7280($at)
    MEM_W(0X7280, ctx->r1) = 0;
    // 0x8008E5C4: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8008E5C8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8008E5CC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008E5D0: lw          $t7, -0x5EC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5EC);
    // 0x8008E5D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E5D8: beq         $t7, $zero, L_8008E5E8
    if (ctx->r15 == 0) {
        // 0x8008E5DC: addiu       $a0, $v0, 0x4
        ctx->r4 = ADD32(ctx->r2, 0X4);
            goto L_8008E5E8;
    }
    // 0x8008E5DC: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8008E5E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008E5E4: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_8008E5E8:
    // 0x8008E5E8: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8008E5EC: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008E5F0: jal         0x80097C80
    // 0x8008E5F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    filename_compress(rdram, ctx);
        goto after_10;
    // 0x8008E5F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x8008E5F8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8008E5FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E600: sw          $v0, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->r2;
    // 0x8008E604: lw          $a0, -0x5B4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B4);
    // 0x8008E608: jal         0x8006EDB8
    // 0x8008E60C: nop

    mark_read_save_file(rdram, ctx);
        goto after_11;
    // 0x8008E60C: nop

    after_11:
    // 0x8008E610: jal         0x80000C98
    // 0x8008E614: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_12;
    // 0x8008E614: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_12:
    // 0x8008E618: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E61C: jal         0x800C06F8
    // 0x8008E620: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_13;
    // 0x8008E620: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_13:
    // 0x8008E624: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008E628: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E62C: b           L_8008E744
    // 0x8008E630: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
        goto L_8008E744;
    // 0x8008E630: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
L_8008E634:
    // 0x8008E634: jal         0x8008DAB0
    // 0x8008E638: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    fileselect_input_root(rdram, ctx);
        goto after_14;
    // 0x8008E638: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_14:
    // 0x8008E63C: beq         $v0, $zero, L_8008E744
    if (ctx->r2 == 0) {
        // 0x8008E640: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_8008E744;
    }
    // 0x8008E640: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8008E644: blez        $v0, L_8008E720
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008E648: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8008E720;
    }
    // 0x8008E648: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008E64C: lw          $t1, -0x5B4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5B4);
    // 0x8008E650: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008E654: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8008E658: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x8008E65C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8008E660: addiu       $t7, $t7, 0x6A40
    ctx->r15 = ADD32(ctx->r15, 0X6A40);
    // 0x8008E664: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8008E668: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8008E66C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008E670: beq         $t8, $zero, L_8008E6A4
    if (ctx->r24 == 0) {
        // 0x8008E674: addiu       $t3, $t3, 0x1530
        ctx->r11 = ADD32(ctx->r11, 0X1530);
            goto L_8008E6A4;
    }
    // 0x8008E674: addiu       $t3, $t3, 0x1530
    ctx->r11 = ADD32(ctx->r11, 0X1530);
    // 0x8008E678: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008E67C: jal         0x80001D04
    // 0x8008E680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x8008E680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8008E684: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E688: lw          $a0, -0x5B4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5B4);
    // 0x8008E68C: jal         0x8006EDB8
    // 0x8008E690: nop

    mark_read_save_file(rdram, ctx);
        goto after_16;
    // 0x8008E690: nop

    after_16:
    // 0x8008E694: jal         0x80000C98
    // 0x8008E698: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_17;
    // 0x8008E698: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_17:
    // 0x8008E69C: b           L_8008E724
    // 0x8008E6A0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
        goto L_8008E724;
    // 0x8008E6A0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8008E6A4:
    // 0x8008E6A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E6A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E6AC: sw          $t9, 0x7280($at)
    MEM_W(0X7280, ctx->r1) = ctx->r25;
    // 0x8008E6B0: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8008E6B4: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8008E6B8: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x8008E6BC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8008E6C0: bne         $t4, $zero, L_8008E6CC
    if (ctx->r12 != 0) {
        // 0x8008E6C4: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_8008E6CC;
    }
    // 0x8008E6C4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008E6C8: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
L_8008E6CC:
    // 0x8008E6CC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008E6D0: addiu       $t6, $t6, 0x94C
    ctx->r14 = ADD32(ctx->r14, 0X94C);
    // 0x8008E6D4: sll         $t5, $t1, 4
    ctx->r13 = S32(ctx->r9 << 4);
    // 0x8008E6D8: addiu       $t2, $t2, 0x97C
    ctx->r10 = ADD32(ctx->r10, 0X97C);
    // 0x8008E6DC: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x8008E6E0: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x8008E6E4: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x8008E6E8: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x8008E6EC: lh          $t9, 0x2($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X2);
    // 0x8008E6F0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8008E6F4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8008E6F8: addiu       $t6, $v0, 0x4
    ctx->r14 = ADD32(ctx->r2, 0X4);
    // 0x8008E6FC: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8008E700: addu        $a2, $t5, $t0
    ctx->r6 = ADD32(ctx->r13, ctx->r8);
    // 0x8008E704: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8008E708: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8008E70C: addiu       $a0, $t0, 0xBB
    ctx->r4 = ADD32(ctx->r8, 0XBB);
    // 0x8008E710: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008E714: jal         0x80097DB0
    // 0x8008E718: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    filename_init(rdram, ctx);
        goto after_18;
    // 0x8008E718: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_18:
    // 0x8008E71C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8008E720:
    // 0x8008E720: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8008E724:
    // 0x8008E724: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008E728: beq         $t8, $zero, L_8008E744
    if (ctx->r24 == 0) {
        // 0x8008E72C: nop
    
            goto L_8008E744;
    }
    // 0x8008E72C: nop

    // 0x8008E730: jal         0x800C06F8
    // 0x8008E734: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_19;
    // 0x8008E734: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_19:
    // 0x8008E738: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8008E73C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E740: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
L_8008E744:
    // 0x8008E744: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008E748: addiu       $a2, $a2, -0x604
    ctx->r6 = ADD32(ctx->r6, -0X604);
    // 0x8008E74C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8008E750: nop

    // 0x8008E754: slti        $at, $v0, 0x24
    ctx->r1 = SIGNED(ctx->r2) < 0X24 ? 1 : 0;
    // 0x8008E758: bne         $at, $zero, L_8008E8AC
    if (ctx->r1 != 0) {
        // 0x8008E75C: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_8008E8AC;
    }
    // 0x8008E75C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008E760: addiu       $a2, $a2, 0x318
    ctx->r6 = ADD32(ctx->r6, 0X318);
    // 0x8008E764: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8008E768: lui         $a0, 0xFBFF
    ctx->r4 = S32(0XFBFF << 16);
    // 0x8008E76C: sll         $t4, $v1, 5
    ctx->r12 = S32(ctx->r3 << 5);
    // 0x8008E770: bgez        $t4, L_8008E7B0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8008E774: ori         $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 | 0XFFFF;
            goto L_8008E7B0;
    }
    // 0x8008E774: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x8008E778: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008E77C: addiu       $a1, $a1, 0x31C
    ctx->r5 = ADD32(ctx->r5, 0X31C);
    // 0x8008E780: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8008E784: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8008E788: and         $t5, $v1, $a0
    ctx->r13 = ctx->r3 & ctx->r4;
    // 0x8008E78C: and         $t7, $t6, $a0
    ctx->r15 = ctx->r14 & ctx->r4;
    // 0x8008E790: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8008E794: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8008E798: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8008E79C: nop

    // 0x8008E7A0: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8008E7A4: nop

    // 0x8008E7A8: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x8008E7AC: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
L_8008E7B0:
    // 0x8008E7B0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008E7B4: lw          $t5, -0x5C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5C4);
    // 0x8008E7B8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E7BC: xori        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 ^ 0X2;
    // 0x8008E7C0: addiu       $v0, $v0, -0x5C0
    ctx->r2 = ADD32(ctx->r2, -0X5C0);
    // 0x8008E7C4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008E7C8: beq         $t6, $zero, L_8008E7D8
    if (ctx->r14 == 0) {
        // 0x8008E7CC: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_8008E7D8;
    }
    // 0x8008E7CC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008E7D0: jal         0x8000E1B8
    // 0x8008E7D4: nop

    reset_lead_player_index(rdram, ctx);
        goto after_20;
    // 0x8008E7D4: nop

    after_20:
L_8008E7D8:
    // 0x8008E7D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008E7DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E7E0: sw          $t8, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r24;
    // 0x8008E7E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E7E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008E7EC: jal         0x8008E8E0
    // 0x8008E7F0: sw          $t9, 0x152C($at)
    MEM_W(0X152C, ctx->r1) = ctx->r25;
    fileselect_free(rdram, ctx);
        goto after_21;
    // 0x8008E7F0: sw          $t9, 0x152C($at)
    MEM_W(0X152C, ctx->r1) = ctx->r25;
    after_21:
    // 0x8008E7F4: jal         0x80000B28
    // 0x8008E7F8: nop

    music_change_on(rdram, ctx);
        goto after_22;
    // 0x8008E7F8: nop

    after_22:
    // 0x8008E7FC: jal         0x8006E7FC
    // 0x8008E800: nop

    init_racer_headers(rdram, ctx);
        goto after_23;
    // 0x8008E800: nop

    after_23:
    // 0x8008E804: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8008E808: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E80C: sw          $zero, 0x1568($at)
    MEM_W(0X1568, ctx->r1) = 0;
    // 0x8008E810: lbu         $t4, 0x4B($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4B);
    // 0x8008E814: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008E818: beq         $t4, $zero, L_8008E878
    if (ctx->r12 == 0) {
        // 0x8008E81C: nop
    
            goto L_8008E878;
    }
    // 0x8008E81C: nop

    // 0x8008E820: lw          $t5, -0x5EC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5EC);
    // 0x8008E824: nop

    // 0x8008E828: beq         $t5, $zero, L_8008E840
    if (ctx->r13 == 0) {
        // 0x8008E82C: nop
    
            goto L_8008E840;
    }
    // 0x8008E82C: nop

    // 0x8008E830: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8008E834: nop

    // 0x8008E838: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x8008E83C: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
L_8008E840:
    // 0x8008E840: jal         0x8001E2D0
    // 0x8008E844: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    get_misc_asset(rdram, ctx);
        goto after_24;
    // 0x8008E844: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_24:
    // 0x8008E848: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008E84C: lw          $a2, -0x5C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5C4);
    // 0x8008E850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008E854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008E858: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008E85C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008E860: jal         0x8009B114
    // 0x8008E864: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    cinematic_start(rdram, ctx);
        goto after_25;
    // 0x8008E864: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_25:
    // 0x8008E868: jal         0x80081820
    // 0x8008E86C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    menu_init(rdram, ctx);
        goto after_26;
    // 0x8008E86C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_26:
    // 0x8008E870: b           L_8008E8D0
    // 0x8008E874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008E8D0;
    // 0x8008E874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008E878:
    // 0x8008E878: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8008E87C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E880: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x8008E884: beq         $t9, $zero, L_8008E89C
    if (ctx->r25 == 0) {
        // 0x8008E888: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8008E89C;
    }
    // 0x8008E888: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E88C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008E890: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008E894: b           L_8008E8A0
    // 0x8008E898: sw          $t4, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r12;
        goto L_8008E8A0;
    // 0x8008E898: sw          $t4, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r12;
L_8008E89C:
    // 0x8008E89C: sw          $zero, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = 0;
L_8008E8A0:
    // 0x8008E8A0: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8008E8A4: b           L_8008E8D4
    // 0x8008E8A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8008E8D4;
    // 0x8008E8A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8008E8AC:
    // 0x8008E8AC: slti        $at, $v0, -0x23
    ctx->r1 = SIGNED(ctx->r2) < -0X23 ? 1 : 0;
    // 0x8008E8B0: beq         $at, $zero, L_8008E8D0
    if (ctx->r1 == 0) {
        // 0x8008E8B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008E8D0;
    }
    // 0x8008E8B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008E8B8: jal         0x8008E8E0
    // 0x8008E8BC: nop

    fileselect_free(rdram, ctx);
        goto after_27;
    // 0x8008E8BC: nop

    after_27:
    // 0x8008E8C0: jal         0x80081820
    // 0x8008E8C4: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_28;
    // 0x8008E8C4: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_28:
    // 0x8008E8C8: b           L_8008E8D0
    // 0x8008E8CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008E8D0;
    // 0x8008E8CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008E8D0:
    // 0x8008E8D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8008E8D4:
    // 0x8008E8D4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8008E8D8: jr          $ra
    // 0x8008E8DC: nop

    return;
    // 0x8008E8DC: nop

;}
RECOMP_FUNC void ainode_find_next(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CC7C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8001CC80: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001CC84: slti        $at, $a0, -0x1
    ctx->r1 = SIGNED(ctx->r4) < -0X1 ? 1 : 0;
    // 0x8001CC88: bne         $at, $zero, L_8001CC9C
    if (ctx->r1 != 0) {
        // 0x8001CC8C: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_8001CC9C;
    }
    // 0x8001CC8C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001CC90: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8001CC94: bne         $at, $zero, L_8001CCA4
    if (ctx->r1 != 0) {
        // 0x8001CC98: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001CCA4;
    }
    // 0x8001CC98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8001CC9C:
    // 0x8001CC9C: b           L_8001CD50
    // 0x8001CCA0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8001CD50;
    // 0x8001CCA0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8001CCA4:
    // 0x8001CCA4: lw          $t6, -0x4B7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B7C);
    // 0x8001CCA8: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001CCAC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001CCB0: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001CCB4: andi        $t9, $a2, 0x3
    ctx->r25 = ctx->r6 & 0X3;
    // 0x8001CCB8: bne         $v0, $zero, L_8001CCC8
    if (ctx->r2 != 0) {
        // 0x8001CCBC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001CCC8;
    }
    // 0x8001CCBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001CCC0: b           L_8001CD50
    // 0x8001CCC4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8001CD50;
    // 0x8001CCC4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8001CCC8:
    // 0x8001CCC8: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x8001CCCC: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x8001CCD0: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8001CCD4: lb          $a3, 0x18($t0)
    ctx->r7 = MEM_B(ctx->r8, 0X18);
    // 0x8001CCD8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8001CCDC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001CCE0: andi        $t2, $a3, 0x3
    ctx->r10 = ctx->r7 & 0X3;
    // 0x8001CCE4: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8001CCE8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8001CCEC:
    // 0x8001CCEC: addu        $t3, $v1, $a3
    ctx->r11 = ADD32(ctx->r3, ctx->r7);
    // 0x8001CCF0: lbu         $v0, 0xA($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0XA);
    // 0x8001CCF4: nop

    // 0x8001CCF8: beq         $a0, $v0, L_8001CD14
    if (ctx->r4 == ctx->r2) {
        // 0x8001CCFC: nop
    
            goto L_8001CD14;
    }
    // 0x8001CCFC: nop

    // 0x8001CD00: beq         $s0, $v0, L_8001CD18
    if (ctx->r16 == ctx->r2) {
        // 0x8001CD04: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8001CD18;
    }
    // 0x8001CD04: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001CD08: sb          $a3, 0x18($t0)
    MEM_B(0X18, ctx->r8) = ctx->r7;
    // 0x8001CD0C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8001CD10: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001CD14:
    // 0x8001CD14: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_8001CD18:
    // 0x8001CD18: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001CD1C: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x8001CD20: andi        $t4, $a3, 0x3
    ctx->r12 = ctx->r7 & 0X3;
    // 0x8001CD24: bne         $at, $zero, L_8001CCEC
    if (ctx->r1 != 0) {
        // 0x8001CD28: or          $a3, $t4, $zero
        ctx->r7 = ctx->r12 | 0;
            goto L_8001CCEC;
    }
    // 0x8001CD28: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x8001CD2C: bne         $a1, $zero, L_8001CD3C
    if (ctx->r5 != 0) {
        // 0x8001CD30: nop
    
            goto L_8001CD3C;
    }
    // 0x8001CD30: nop

    // 0x8001CD34: b           L_8001CD50
    // 0x8001CD38: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8001CD50;
    // 0x8001CD38: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8001CD3C:
    // 0x8001CD3C: lb          $t5, 0x18($t0)
    ctx->r13 = MEM_B(ctx->r8, 0X18);
    // 0x8001CD40: nop

    // 0x8001CD44: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8001CD48: lbu         $v0, 0xA($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA);
    // 0x8001CD4C: nop

L_8001CD50:
    // 0x8001CD50: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001CD54: jr          $ra
    // 0x8001CD58: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8001CD58: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void __assert_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B74A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B74A4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B74A8: jr          $ra
    // 0x800B74AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800B74AC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void trophyround_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800988FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80098900: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098904: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80098908: jal         0x8001E2D0
    // 0x8009890C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8009890C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_0:
    // 0x80098910: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80098914: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80098918: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009891C: bne         $t6, $zero, L_80098930
    if (ctx->r14 != 0) {
        // 0x80098920: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80098930;
    }
    // 0x80098920: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80098924: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x80098928: b           L_80098934
    // 0x8009892C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_80098934;
    // 0x8009892C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80098930:
    // 0x80098930: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80098934:
    // 0x80098934: lw          $a0, 0x1568($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1568);
    // 0x80098938: jal         0x8006B414
    // 0x8009893C: nop

    level_world_id(rdram, ctx);
        goto after_1;
    // 0x8009893C: nop

    after_1:
    // 0x80098940: jal         0x8006C01C
    // 0x80098944: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    level_name(rdram, ctx);
        goto after_2;
    // 0x80098944: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80098948: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009894C: lw          $t8, 0x1568($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1568);
    // 0x80098950: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80098954: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80098958: lw          $t0, 0x156C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X156C);
    // 0x8009895C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80098960: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80098964: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80098968: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8009896C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80098970: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80098974: lb          $a0, -0x6($t3)
    ctx->r4 = MEM_B(ctx->r11, -0X6);
    // 0x80098978: jal         0x8006C01C
    // 0x8009897C: nop

    level_name(rdram, ctx);
        goto after_3;
    // 0x8009897C: nop

    after_3:
    // 0x80098980: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80098984: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80098988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009898C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80098990: jal         0x800C492C
    // 0x80098994: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_4;
    // 0x80098994: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80098998: jal         0x800C484C
    // 0x8009899C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_5;
    // 0x8009899C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x800989A0: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x800989A4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800989A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800989AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800989B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800989B4: jal         0x800C48E4
    // 0x800989B8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_6;
    // 0x800989B8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_6:
    // 0x800989BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800989C0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800989C4: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x800989C8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800989CC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800989D0: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x800989D4: jal         0x800C49A0
    // 0x800989D8: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_7;
    // 0x800989D8: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_7:
    // 0x800989DC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800989E0: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x800989E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800989E8: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x800989EC: lw          $a3, 0x118($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X118);
    // 0x800989F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800989F4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800989F8: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x800989FC: jal         0x800C49A0
    // 0x80098A00: addiu       $a2, $zero, 0x43
    ctx->r6 = ADD32(0, 0X43);
    draw_text(rdram, ctx);
        goto after_8;
    // 0x80098A00: addiu       $a2, $zero, 0x43
    ctx->r6 = ADD32(0, 0X43);
    after_8:
    // 0x80098A04: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80098A08: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80098A0C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80098A10: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80098A14: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80098A18: jal         0x800C48E4
    // 0x80098A1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_9;
    // 0x80098A1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80098A20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098A24: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80098A28: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80098A2C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80098A30: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80098A34: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80098A38: jal         0x800C49A0
    // 0x80098A3C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_10;
    // 0x80098A3C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_10:
    // 0x80098A40: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80098A44: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x80098A48: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098A4C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80098A50: lw          $a3, 0x118($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X118);
    // 0x80098A54: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80098A58: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80098A5C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80098A60: jal         0x800C49A0
    // 0x80098A64: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    draw_text(rdram, ctx);
        goto after_11;
    // 0x80098A64: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_11:
    // 0x80098A68: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80098A6C: lw          $t3, 0x156C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X156C);
    // 0x80098A70: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80098A74: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x80098A78: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80098A7C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80098A80: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80098A84: lw          $a3, 0x228($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X228);
    // 0x80098A88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098A8C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80098A90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80098A94: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80098A98: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80098A9C: jal         0x800C49A0
    // 0x80098AA0: addiu       $a2, $a2, 0xB0
    ctx->r6 = ADD32(ctx->r6, 0XB0);
    draw_text(rdram, ctx);
        goto after_12;
    // 0x80098AA0: addiu       $a2, $a2, 0xB0
    ctx->r6 = ADD32(ctx->r6, 0XB0);
    after_12:
    // 0x80098AA4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80098AA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80098AAC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80098AB0: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80098AB4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80098AB8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80098ABC: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80098AC0: jal         0x800C49A0
    // 0x80098AC4: addiu       $a2, $a2, 0xD0
    ctx->r6 = ADD32(ctx->r6, 0XD0);
    draw_text(rdram, ctx);
        goto after_13;
    // 0x80098AC4: addiu       $a2, $a2, 0xD0
    ctx->r6 = ADD32(ctx->r6, 0XD0);
    after_13:
    // 0x80098AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80098ACC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80098AD0: jr          $ra
    // 0x80098AD4: nop

    return;
    // 0x80098AD4: nop

;}
RECOMP_FUNC void set_render_printf_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B676C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B6770: addiu       $v0, $v0, -0x7468
    ctx->r2 = ADD32(ctx->r2, -0X7468);
    // 0x800B6774: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B6778: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B677C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B6780: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800B6784: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800B6788: addiu       $t0, $zero, 0x81
    ctx->r8 = ADD32(0, 0X81);
    // 0x800B678C: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x800B6790: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800B6794: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x800B6798: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800B679C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800B67A0: sb          $a0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r4;
    // 0x800B67A4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800B67A8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B67AC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800B67B0: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
    // 0x800B67B4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B67B8: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800B67BC: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    // 0x800B67C0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B67C4: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x800B67C8: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800B67CC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B67D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B67D4: sb          $a2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r6;
    // 0x800B67D8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800B67DC: nop

    // 0x800B67E0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B67E4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800B67E8: sb          $a3, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r7;
    // 0x800B67EC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B67F0: nop

    // 0x800B67F4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B67F8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B67FC: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x800B6800: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800B6804: nop

    // 0x800B6808: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B680C: jr          $ra
    // 0x800B6810: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800B6810: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void alHeapInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AC0: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800C7AC4: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x800C7AC8: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x800C7ACC: beq         $v1, $v0, L_800C7ADC
    if (ctx->r3 == ctx->r2) {
        // 0x800C7AD0: addu        $t7, $a1, $v0
        ctx->r15 = ADD32(ctx->r5, ctx->r2);
            goto L_800C7ADC;
    }
    // 0x800C7AD0: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800C7AD4: b           L_800C7AE0
    // 0x800C7AD8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_800C7AE0;
    // 0x800C7AD8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800C7ADC:
    // 0x800C7ADC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_800C7AE0:
    // 0x800C7AE0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800C7AE4: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800C7AE8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800C7AEC: jr          $ra
    // 0x800C7AF0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    return;
    // 0x800C7AF0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void watereffect_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D6B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002D6B4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002D6B8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002D6BC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002D6C0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002D6C4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002D6C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002D6CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002D6D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002D6D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002D6D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D6DC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8002D6E0: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8002D6E4: nop

    // 0x8002D6E8: lh          $t7, 0x36($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X36);
    // 0x8002D6EC: nop

    // 0x8002D6F0: beq         $t7, $zero, L_8002D8F0
    if (ctx->r15 == 0) {
        // 0x8002D6F4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002D8F0;
    }
    // 0x8002D6F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002D6F8: lh          $t9, 0x8($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X8);
    // 0x8002D6FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002D700: beq         $t9, $at, L_8002D8EC
    if (ctx->r25 == ctx->r1) {
        // 0x8002D704: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002D8EC;
    }
    // 0x8002D704: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002D708: lw          $t5, -0x49BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X49BC);
    // 0x8002D70C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002D710: bne         $t5, $zero, L_8002D8EC
    if (ctx->r13 != 0) {
        // 0x8002D714: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8002D8EC;
    }
    // 0x8002D714: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D718: lw          $t6, -0x49B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X49B8);
    // 0x8002D71C: addiu       $s0, $s0, -0x49B0
    ctx->r16 = ADD32(ctx->r16, -0X49B0);
    // 0x8002D720: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8002D724: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8002D728: lh          $s2, 0x8($a1)
    ctx->r18 = MEM_H(ctx->r5, 0X8);
    // 0x8002D72C: lh          $t9, 0x36($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X36);
    // 0x8002D730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D734: bne         $t9, $at, L_8002D778
    if (ctx->r25 != ctx->r1) {
        // 0x8002D738: addiu       $t6, $t6, 0x2
        ctx->r14 = ADD32(ctx->r14, 0X2);
            goto L_8002D778;
    }
    // 0x8002D738: addiu       $t6, $t6, 0x2
    ctx->r14 = ADD32(ctx->r14, 0X2);
    // 0x8002D73C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8002D740: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x8002D744: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002D748: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002D74C: jal         0x80066588
    // 0x8002D750: nop

    get_distance_to_active_camera(rdram, ctx);
        goto after_0;
    // 0x8002D750: nop

    after_0:
    // 0x8002D754: lui         $at, 0x4440
    ctx->r1 = S32(0X4440 << 16);
    // 0x8002D758: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002D75C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002D760: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8002D764: nop

    // 0x8002D768: bc1f        L_8002D778
    if (!c1cs) {
        // 0x8002D76C: nop
    
            goto L_8002D778;
    }
    // 0x8002D76C: nop

    // 0x8002D770: lh          $s2, 0xA($t7)
    ctx->r18 = MEM_H(ctx->r15, 0XA);
    // 0x8002D774: nop

L_8002D778:
    // 0x8002D778: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002D77C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002D780: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8002D784: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002D788: lw          $t9, -0x2730($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2730);
    // 0x8002D78C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002D790: addiu       $s3, $s3, -0x2720
    ctx->r19 = ADD32(ctx->r19, -0X2720);
    // 0x8002D794: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002D798: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x8002D79C: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8002D7A0: lw          $t5, -0x2760($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2760);
    // 0x8002D7A4: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002D7A8: addiu       $s5, $s5, -0x2750
    ctx->r21 = ADD32(ctx->r21, -0X2750);
    // 0x8002D7AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D7B0: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8002D7B4: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x8002D7B8: lw          $t6, -0x2748($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2748);
    // 0x8002D7BC: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8002D7C0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8002D7C4: addiu       $s6, $s6, -0x2738
    ctx->r22 = ADD32(ctx->r22, -0X2738);
    // 0x8002D7C8: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x8002D7CC: lh          $t8, 0xA($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XA);
    // 0x8002D7D0: sll         $s1, $s2, 3
    ctx->r17 = S32(ctx->r18 << 3);
    // 0x8002D7D4: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002D7D8: beq         $at, $zero, L_8002D8EC
    if (ctx->r1 == 0) {
        // 0x8002D7DC: lui         $fp, 0x400
        ctx->r30 = S32(0X400 << 16);
            goto L_8002D8EC;
    }
    // 0x8002D7DC: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x8002D7E0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002D7E4: addiu       $s0, $s0, -0x49E0
    ctx->r16 = ADD32(ctx->r16, -0X49E0);
    // 0x8002D7E8: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x8002D7EC: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
L_8002D7F0:
    // 0x8002D7F0: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8002D7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002D7F8: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x8002D7FC: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x8002D800: jal         0x8007B918
    // 0x8002D804: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    material_set_no_tex_offset(rdram, ctx);
        goto after_1;
    // 0x8002D804: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_1:
    // 0x8002D808: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8002D80C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8002D810: addu        $v1, $t6, $s1
    ctx->r3 = ADD32(ctx->r14, ctx->r17);
    // 0x8002D814: lh          $a2, 0x6($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X6);
    // 0x8002D818: lh          $a1, 0x4($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X4);
    // 0x8002D81C: multu       $a2, $s7
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D820: lh          $t7, 0xC($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XC);
    // 0x8002D824: lh          $t8, 0xE($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XE);
    // 0x8002D828: subu        $a3, $t7, $a1
    ctx->r7 = SUB32(ctx->r15, ctx->r5);
    // 0x8002D82C: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8002D830: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8002D834: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002D838: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x8002D83C: subu        $a0, $t8, $a2
    ctx->r4 = SUB32(ctx->r24, ctx->r6);
    // 0x8002D840: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x8002D844: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x8002D848: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002D84C: mflo        $t6
    ctx->r14 = lo;
    // 0x8002D850: addu        $t4, $t6, $t7
    ctx->r12 = ADD32(ctx->r14, ctx->r15);
    // 0x8002D854: addu        $t1, $t4, $s4
    ctx->r9 = ADD32(ctx->r12, ctx->r20);
    // 0x8002D858: andi        $t6, $t1, 0x6
    ctx->r14 = ctx->r9 & 0X6;
    // 0x8002D85C: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8002D860: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002D864: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8002D868: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8002D86C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8002D870: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8002D874: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8002D878: or          $t5, $t9, $fp
    ctx->r13 = ctx->r25 | ctx->r30;
    // 0x8002D87C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8002D880: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8002D884: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8002D888: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002D88C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002D890: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8002D894: addiu       $t9, $a3, -0x1
    ctx->r25 = ADD32(ctx->r7, -0X1);
    // 0x8002D898: sll         $t5, $t9, 4
    ctx->r13 = S32(ctx->r25 << 4);
    // 0x8002D89C: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x8002D8A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002D8A4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8002D8A8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8002D8AC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8002D8B0: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8002D8B4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8002D8B8: sll         $t5, $a3, 4
    ctx->r13 = S32(ctx->r7 << 4);
    // 0x8002D8BC: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8002D8C0: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8002D8C4: addu        $t8, $t3, $s4
    ctx->r24 = ADD32(ctx->r11, ctx->r20);
    // 0x8002D8C8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8002D8CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002D8D0: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002D8D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002D8D8: lh          $t9, 0xA($t5)
    ctx->r25 = MEM_H(ctx->r13, 0XA);
    // 0x8002D8DC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8002D8E0: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002D8E4: bne         $at, $zero, L_8002D7F0
    if (ctx->r1 != 0) {
        // 0x8002D8E8: nop
    
            goto L_8002D7F0;
    }
    // 0x8002D8E8: nop

L_8002D8EC:
    // 0x8002D8EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8002D8F0:
    // 0x8002D8F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D8F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D8F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002D8FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002D900: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002D904: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D908: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002D90C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002D910: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002D914: jr          $ra
    // 0x8002D918: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002D918: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void menu_track_select_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F6EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008F6F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F6F4: jal         0x8006ECD0
    // 0x8008F6F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8008F6F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008F6FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008F700: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008F704: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008F708: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008F70C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8008F710: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8008F714: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x8008F718: jal         0x800C7940
    // 0x8008F71C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    bgload_active(rdram, ctx);
        goto after_1;
    // 0x8008F71C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    after_1:
    // 0x8008F720: bne         $v0, $zero, L_8008F768
    if (ctx->r2 != 0) {
        // 0x8008F724: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8008F768;
    }
    // 0x8008F724: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F728: addiu       $v1, $v1, -0x604
    ctx->r3 = ADD32(ctx->r3, -0X604);
    // 0x8008F72C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008F730: nop

    // 0x8008F734: beq         $v0, $zero, L_8008F768
    if (ctx->r2 == 0) {
        // 0x8008F738: nop
    
            goto L_8008F768;
    }
    // 0x8008F738: nop

    // 0x8008F73C: bgez        $v0, L_8008F75C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008F740: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_8008F75C;
    }
    // 0x8008F740: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8008F744: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8008F748: nop

    // 0x8008F74C: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x8008F750: b           L_8008F768
    // 0x8008F754: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_8008F768;
    // 0x8008F754: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8008F758: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_8008F75C:
    // 0x8008F75C: nop

    // 0x8008F760: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8008F764: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_8008F768:
    // 0x8008F768: jal         0x8008E9A4
    // 0x8008F76C: nop

    menu_input(rdram, ctx);
        goto after_2;
    // 0x8008F76C: nop

    after_2:
    // 0x8008F770: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008F774: addiu       $a1, $a1, 0x693C
    ctx->r5 = ADD32(ctx->r5, 0X693C);
    // 0x8008F778: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008F77C: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x8008F780: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8008F784: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8008F788: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x8008F78C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008F790: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8008F794: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8008F798: lw          $a0, 0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6D70);
    // 0x8008F79C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008F7A0: beq         $a0, $zero, L_8008F7B8
    if (ctx->r4 == 0) {
        // 0x8008F7A4: nop
    
            goto L_8008F7B8;
    }
    // 0x8008F7A4: nop

    // 0x8008F7A8: beq         $a0, $at, L_8008F7E8
    if (ctx->r4 == ctx->r1) {
        // 0x8008F7AC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8008F7E8;
    }
    // 0x8008F7AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F7B0: b           L_8008F808
    // 0x8008F7B4: nop

        goto L_8008F808;
    // 0x8008F7B4: nop

L_8008F7B8:
    // 0x8008F7B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F7BC: jal         0x800903D4
    // 0x8008F7C0: nop

    func_8008FF1C(rdram, ctx);
        goto after_3;
    // 0x8008F7C0: nop

    after_3:
    // 0x8008F7C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F7C8: jal         0x800909A0
    // 0x8008F7CC: nop

    trackmenu_track_view(rdram, ctx);
        goto after_4;
    // 0x8008F7CC: nop

    after_4:
    // 0x8008F7D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F7D4: jal         0x80090DD0
    // 0x8008F7D8: nop

    trackmenu_input(rdram, ctx);
        goto after_5;
    // 0x8008F7D8: nop

    after_5:
    // 0x8008F7DC: b           L_8008F808
    // 0x8008F7E0: nop

        goto L_8008F808;
    // 0x8008F7E0: nop

    // 0x8008F7E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8008F7E8:
    // 0x8008F7E8: jal         0x80091390
    // 0x8008F7EC: nop

    trackmenu_timetrial_sound(rdram, ctx);
        goto after_6;
    // 0x8008F7EC: nop

    after_6:
    // 0x8008F7F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F7F4: jal         0x800913E8
    // 0x8008F7F8: nop

    trackmenu_setup_render(rdram, ctx);
        goto after_7;
    // 0x8008F7F8: nop

    after_7:
    // 0x8008F7FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F800: jal         0x800926A4
    // 0x8008F804: nop

    func_80092188(rdram, ctx);
        goto after_8;
    // 0x8008F804: nop

    after_8:
L_8008F808:
    // 0x8008F808: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F80C: addiu       $v1, $v1, -0x320
    ctx->r3 = ADD32(ctx->r3, -0X320);
    // 0x8008F810: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008F814: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008F818: bgez        $v0, L_8008F830
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008F81C: sll         $t8, $t7, 1
        ctx->r24 = S32(ctx->r15 << 1);
            goto L_8008F830;
    }
    // 0x8008F81C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8008F820: jal         0x80001990
    // 0x8008F824: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    music_volume_set(rdram, ctx);
        goto after_9;
    // 0x8008F824: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8008F828: b           L_8008F854
    // 0x8008F82C: nop

        goto L_8008F854;
    // 0x8008F82C: nop

L_8008F830:
    // 0x8008F830: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8008F834: slti        $at, $t9, 0x51
    ctx->r1 = SIGNED(ctx->r25) < 0X51 ? 1 : 0;
    // 0x8008F838: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008F83C: bne         $at, $zero, L_8008F84C
    if (ctx->r1 != 0) {
        // 0x8008F840: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8008F84C;
    }
    // 0x8008F840: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8008F844: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8008F848: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8008F84C:
    // 0x8008F84C: jal         0x80001990
    // 0x8008F850: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    music_volume_set(rdram, ctx);
        goto after_10;
    // 0x8008F850: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_10:
L_8008F854:
    // 0x8008F854: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008F858: lw          $v0, 0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D70);
    // 0x8008F85C: nop

    // 0x8008F860: bgez        $v0, L_8008F920
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008F864: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_8008F920;
    }
    // 0x8008F864: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8008F868: jal         0x8008F9EC
    // 0x8008F86C: nop

    menu_track_select_unload(rdram, ctx);
        goto after_11;
    // 0x8008F86C: nop

    after_11:
    // 0x8008F870: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008F874: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8008F878: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F87C: sw          $zero, -0x608($at)
    MEM_W(-0X608, ctx->r1) = 0;
    // 0x8008F880: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8008F884: beq         $at, $zero, L_8008F8A8
    if (ctx->r1 == 0) {
        // 0x8008F888: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008F8A8;
    }
    // 0x8008F888: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008F88C: bne         $v0, $at, L_8008F900
    if (ctx->r2 != ctx->r1) {
        // 0x8008F890: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_8008F900;
    }
    // 0x8008F890: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008F894: lw          $t1, 0x318($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X318);
    // 0x8008F898: nop

    // 0x8008F89C: sll         $t2, $t1, 7
    ctx->r10 = S32(ctx->r9 << 7);
    // 0x8008F8A0: bltz        $t2, L_8008F904
    if (SIGNED(ctx->r10) < 0) {
        // 0x8008F8A4: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_8008F904;
    }
    // 0x8008F8A4: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
L_8008F8A8:
    // 0x8008F8A8: jal         0x8009F214
    // 0x8008F8AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    is_drumstick_unlocked(rdram, ctx);
        goto after_12;
    // 0x8008F8AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_12:
    // 0x8008F8B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F8B4: beq         $v0, $zero, L_8008F8C0
    if (ctx->r2 == 0) {
        // 0x8008F8B8: nop
    
            goto L_8008F8C0;
    }
    // 0x8008F8B8: nop

    // 0x8008F8BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8008F8C0:
    // 0x8008F8C0: jal         0x8009F1FC
    // 0x8008F8C4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    is_tt_unlocked(rdram, ctx);
        goto after_13;
    // 0x8008F8C4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_13:
    // 0x8008F8C8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F8CC: beq         $v0, $zero, L_8008F8DC
    if (ctx->r2 == 0) {
        // 0x8008F8D0: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_8008F8DC;
    }
    // 0x8008F8D0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8008F8D4: xori        $t3, $a2, 0x3
    ctx->r11 = ctx->r6 ^ 0X3;
    // 0x8008F8D8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
L_8008F8DC:
    // 0x8008F8DC: jal         0x8006E528
    // 0x8008F8E0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_14;
    // 0x8008F8E0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_14:
    // 0x8008F8E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008F8E8: jal         0x8008B36C
    // 0x8008F8EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    charselect_prev(rdram, ctx);
        goto after_15;
    // 0x8008F8EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8008F8F0: jal         0x80081820
    // 0x8008F8F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    menu_init(rdram, ctx);
        goto after_16;
    // 0x8008F8F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x8008F8F8: b           L_8008F9DC
    // 0x8008F8FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F9DC;
    // 0x8008F8FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F900:
    // 0x8008F900: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
L_8008F904:
    // 0x8008F904: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008F908: jal         0x8006E528
    // 0x8008F90C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_17;
    // 0x8008F90C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x8008F910: jal         0x80081820
    // 0x8008F914: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_18;
    // 0x8008F914: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_18:
    // 0x8008F918: b           L_8008F9DC
    // 0x8008F91C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F9DC;
    // 0x8008F91C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F920:
    // 0x8008F920: bne         $at, $zero, L_8008F9D4
    if (ctx->r1 != 0) {
        // 0x8008F924: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008F9D4;
    }
    // 0x8008F924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008F928: jal         0x8008F9EC
    // 0x8008F92C: nop

    menu_track_select_unload(rdram, ctx);
        goto after_19;
    // 0x8008F92C: nop

    after_19:
    // 0x8008F930: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008F934: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008F938: lw          $t5, 0x6AE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6AE8);
    // 0x8008F93C: lw          $t4, 0x990($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X990);
    // 0x8008F940: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008F944: beq         $t4, $t5, L_8008F97C
    if (ctx->r12 == ctx->r13) {
        // 0x8008F948: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8008F97C;
    }
    // 0x8008F948: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008F94C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8008F950: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_8008F954:
    // 0x8008F954: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x8008F958: addiu       $t7, $a2, 0x2
    ctx->r15 = ADD32(ctx->r6, 0X2);
    // 0x8008F95C: addiu       $t8, $a2, 0x3
    ctx->r24 = ADD32(ctx->r6, 0X3);
    // 0x8008F960: sb          $a2, 0x5A($v0)
    MEM_B(0X5A, ctx->r2) = ctx->r6;
    // 0x8008F964: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8008F968: sb          $t8, 0xA2($v0)
    MEM_B(0XA2, ctx->r2) = ctx->r24;
    // 0x8008F96C: sb          $t7, 0x8A($v0)
    MEM_B(0X8A, ctx->r2) = ctx->r15;
    // 0x8008F970: sb          $t6, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r14;
    // 0x8008F974: bne         $a2, $v1, L_8008F954
    if (ctx->r6 != ctx->r3) {
        // 0x8008F978: addiu       $v0, $v0, 0x60
        ctx->r2 = ADD32(ctx->r2, 0X60);
            goto L_8008F954;
    }
    // 0x8008F978: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
L_8008F97C:
    // 0x8008F97C: lw          $t9, 0x6F88($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6F88);
    // 0x8008F980: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008F984: beq         $t9, $at, L_8008F9A4
    if (ctx->r25 == ctx->r1) {
        // 0x8008F988: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8008F9A4;
    }
    // 0x8008F988: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008F98C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008F990: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008F994: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F998: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8008F99C: b           L_8008F9DC
    // 0x8008F9A0: sw          $t0, -0x608($at)
    MEM_W(-0X608, ctx->r1) = ctx->r8;
        goto L_8008F9DC;
    // 0x8008F9A0: sw          $t0, -0x608($at)
    MEM_W(-0X608, ctx->r1) = ctx->r8;
L_8008F9A4:
    // 0x8008F9A4: lw          $t1, 0x6F8C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6F8C);
    // 0x8008F9A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F9AC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8008F9B0: sw          $t2, 0x1568($at)
    MEM_W(0X1568, ctx->r1) = ctx->r10;
    // 0x8008F9B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F9B8: sb          $zero, -0x630($at)
    MEM_B(-0X630, ctx->r1) = 0;
    // 0x8008F9BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F9C0: sw          $zero, 0x156C($at)
    MEM_W(0X156C, ctx->r1) = 0;
    // 0x8008F9C4: jal         0x80081820
    // 0x8008F9C8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    menu_init(rdram, ctx);
        goto after_20;
    // 0x8008F9C8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_20:
    // 0x8008F9CC: b           L_8008F9DC
    // 0x8008F9D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F9DC;
    // 0x8008F9D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F9D4:
    // 0x8008F9D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F9D8: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_8008F9DC:
    // 0x8008F9DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F9E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008F9E4: jr          $ra
    // 0x8008F9E8: nop

    return;
    // 0x8008F9E8: nop

;}
RECOMP_FUNC void object_undo_player_tumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F30: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80012F34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012F38: bne         $t6, $at, L_80012F8C
    if (ctx->r14 != ctx->r1) {
        // 0x80012F3C: nop
    
            goto L_80012F8C;
    }
    // 0x80012F3C: nop

    // 0x80012F40: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80012F44: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80012F48: lh          $t8, 0x160($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X160);
    // 0x80012F4C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x80012F50: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80012F54: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80012F58: lh          $t1, 0x162($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X162);
    // 0x80012F5C: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x80012F60: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80012F64: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
    // 0x80012F68: lh          $t4, 0x164($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X164);
    // 0x80012F6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012F70: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80012F74: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x80012F78: lwc1        $f6, -0x4CB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4CB0);
    // 0x80012F7C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80012F80: nop

    // 0x80012F84: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80012F88: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
L_80012F8C:
    // 0x80012F8C: jr          $ra
    // 0x80012F90: nop

    return;
    // 0x80012F90: nop

;}
