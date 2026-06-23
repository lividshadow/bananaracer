#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void input_swap_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A74C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006A750: addiu       $v1, $v1, 0x16D0
    ctx->r3 = ADD32(ctx->r3, 0X16D0);
    // 0x8006A754: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006A758: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x8006A75C: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8006A760: jr          $ra
    // 0x8006A764: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    return;
    // 0x8006A764: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
;}
RECOMP_FUNC void vsprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4FA0: addiu       $sp, $sp, -0x1B8
    ctx->r29 = ADD32(ctx->r29, -0X1B8);
    // 0x800B4FA4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800B4FA8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800B4FAC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800B4FB0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800B4FB4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800B4FB8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800B4FBC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800B4FC0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800B4FC4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800B4FC8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B4FCC: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B4FD0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800B4FD4: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4FD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B4FDC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800B4FE0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800B4FE4: beq         $t6, $zero, L_800B63A8
    if (ctx->r14 == 0) {
        // 0x800B4FE8: or          $t3, $a1, $zero
        ctx->r11 = ctx->r5 | 0;
            goto L_800B63A8;
    }
    // 0x800B4FE8: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800B4FEC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800B4FF0: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800B4FF4: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4FF8: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800B4FFC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B5000: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B5004: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B5008: lwc1        $f17, 0xE0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x800B500C: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800B5010: lw          $s4, 0xC8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC8);
    // 0x800B5014: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800B5018: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x800B501C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B5020:
    // 0x800B5020: beq         $a0, $v0, L_800B5060
    if (ctx->r4 == ctx->r2) {
        // 0x800B5024: nop
    
            goto L_800B5060;
    }
    // 0x800B5024: nop

    // 0x800B5028: beq         $a0, $v0, L_800B638C
    if (ctx->r4 == ctx->r2) {
        // 0x800B502C: nop
    
            goto L_800B638C;
    }
    // 0x800B502C: nop

    // 0x800B5030: beq         $v0, $zero, L_800B638C
    if (ctx->r2 == 0) {
        // 0x800B5034: nop
    
            goto L_800B638C;
    }
    // 0x800B5034: nop

L_800B5038:
    // 0x800B5038: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x800B503C: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B5040: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5044: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5048: beq         $a0, $v1, L_800B638C
    if (ctx->r4 == ctx->r3) {
        // 0x800B504C: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_800B638C;
    }
    // 0x800B504C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5050: bne         $v1, $zero, L_800B5038
    if (ctx->r3 != 0) {
        // 0x800B5054: nop
    
            goto L_800B5038;
    }
    // 0x800B5054: nop

    // 0x800B5058: b           L_800B6390
    // 0x800B505C: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
        goto L_800B6390;
    // 0x800B505C: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
L_800B5060:
    // 0x800B5060: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B5064: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5068: bne         $a0, $v1, L_800B5088
    if (ctx->r4 != ctx->r3) {
        // 0x800B506C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B5088;
    }
    // 0x800B506C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5070: addiu       $t7, $zero, 0x25
    ctx->r15 = ADD32(0, 0X25);
    // 0x800B5074: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5078: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x800B507C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5080: b           L_800B638C
    // 0x800B5084: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B638C;
    // 0x800B5084: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5088:
    // 0x800B5088: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B508C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800B5090: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800B5094: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B5098: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B509C: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
    // 0x800B50A0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800B50A4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800B50A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B50AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B50B0: beq         $v0, $at, L_800B50D8
    if (ctx->r2 == ctx->r1) {
        // 0x800B50B4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800B50D8;
    }
    // 0x800B50B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B50B8: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x800B50BC: beq         $v0, $at, L_800B50D8
    if (ctx->r2 == ctx->r1) {
        // 0x800B50C0: addiu       $at, $zero, 0x2D
        ctx->r1 = ADD32(0, 0X2D);
            goto L_800B50D8;
    }
    // 0x800B50C0: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800B50C4: beq         $v0, $at, L_800B50D8
    if (ctx->r2 == ctx->r1) {
        // 0x800B50C8: addiu       $at, $zero, 0x23
        ctx->r1 = ADD32(0, 0X23);
            goto L_800B50D8;
    }
    // 0x800B50C8: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x800B50CC: beq         $v0, $at, L_800B50D8
    if (ctx->r2 == ctx->r1) {
        // 0x800B50D0: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B50D8;
    }
    // 0x800B50D0: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B50D4: bne         $v0, $at, L_800B5168
    if (ctx->r2 != ctx->r1) {
        // 0x800B50D8: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B5168;
    }
L_800B50D8:
    // 0x800B50D8: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
L_800B50DC:
    // 0x800B50DC: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x800B50E0: beq         $at, $zero, L_800B5128
    if (ctx->r1 == 0) {
        // 0x800B50E4: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_800B5128;
    }
    // 0x800B50E4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B50E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800B50EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B50F0: addu        $at, $at, $t8
    gpr jr_addend_800B50FC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B50F4: lw          $t8, -0x6DD4($at)
    ctx->r24 = ADD32(ctx->r1, -0X6DD4);
    // 0x800B50F8: nop

    // 0x800B50FC: jr          $t8
    // 0x800B5100: nop

    switch (jr_addend_800B50FC >> 2) {
        case 0: goto L_800B5104; break;
        case 1: goto L_800B5128; break;
        case 2: goto L_800B5128; break;
        case 3: goto L_800B511C; break;
        case 4: goto L_800B5128; break;
        case 5: goto L_800B5128; break;
        case 6: goto L_800B5128; break;
        case 7: goto L_800B5128; break;
        case 8: goto L_800B5128; break;
        case 9: goto L_800B5128; break;
        case 10: goto L_800B5128; break;
        case 11: goto L_800B510C; break;
        case 12: goto L_800B5128; break;
        case 13: goto L_800B5114; break;
        case 14: goto L_800B5128; break;
        case 15: goto L_800B5128; break;
        case 16: goto L_800B5124; break;
        default: switch_error(__func__, 0x800B50FC, 0x800E922C);
    }
    // 0x800B5100: nop

L_800B5104:
    // 0x800B5104: b           L_800B5128
    // 0x800B5108: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
        goto L_800B5128;
    // 0x800B5108: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800B510C:
    // 0x800B510C: b           L_800B5128
    // 0x800B5110: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_800B5128;
    // 0x800B5110: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800B5114:
    // 0x800B5114: b           L_800B5128
    // 0x800B5118: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
        goto L_800B5128;
    // 0x800B5118: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800B511C:
    // 0x800B511C: b           L_800B5128
    // 0x800B5120: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
        goto L_800B5128;
    // 0x800B5120: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_800B5124:
    // 0x800B5124: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
L_800B5128:
    // 0x800B5128: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B512C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B5130: beq         $v1, $at, L_800B50D8
    if (ctx->r3 == ctx->r1) {
        // 0x800B5134: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B50D8;
    }
    // 0x800B5134: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5138: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x800B513C: beq         $v1, $at, L_800B50DC
    if (ctx->r3 == ctx->r1) {
        // 0x800B5140: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B50DC;
    }
    // 0x800B5140: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
    // 0x800B5144: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800B5148: beq         $v1, $at, L_800B50DC
    if (ctx->r3 == ctx->r1) {
        // 0x800B514C: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B50DC;
    }
    // 0x800B514C: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
    // 0x800B5150: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x800B5154: beq         $v1, $at, L_800B50DC
    if (ctx->r3 == ctx->r1) {
        // 0x800B5158: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B50DC;
    }
    // 0x800B5158: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
    // 0x800B515C: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B5160: beq         $v1, $at, L_800B50DC
    if (ctx->r3 == ctx->r1) {
        // 0x800B5164: addiu       $t8, $v0, -0x20
        ctx->r24 = ADD32(ctx->r2, -0X20);
            goto L_800B50DC;
    }
    // 0x800B5164: addiu       $t8, $v0, -0x20
    ctx->r24 = ADD32(ctx->r2, -0X20);
L_800B5168:
    // 0x800B5168: beq         $s7, $zero, L_800B5174
    if (ctx->r23 == 0) {
        // 0x800B516C: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_800B5174;
    }
    // 0x800B516C: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x800B5170: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
L_800B5174:
    // 0x800B5174: bne         $v0, $at, L_800B51B4
    if (ctx->r2 != ctx->r1) {
        // 0x800B5178: slti        $at, $v0, 0x30
        ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
            goto L_800B51B4;
    }
    // 0x800B5178: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x800B517C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5180: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5184: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B5188: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B518C: lw          $t0, -0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, -0X4);
    // 0x800B5190: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5194: bgez        $t0, L_800B51A4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B5198: nop
    
            goto L_800B51A4;
    }
    // 0x800B5198: nop

    // 0x800B519C: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800B51A0: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800B51A4:
    // 0x800B51A4: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B51A8: b           L_800B51F4
    // 0x800B51AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B51F4;
    // 0x800B51AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B51B0: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
L_800B51B4:
    // 0x800B51B4: bne         $at, $zero, L_800B51F4
    if (ctx->r1 != 0) {
        // 0x800B51B8: slti        $at, $v0, 0x3A
        ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
            goto L_800B51F4;
    }
    // 0x800B51B8: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B51BC: beq         $at, $zero, L_800B51F4
    if (ctx->r1 == 0) {
        // 0x800B51C0: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_800B51F4;
    }
    // 0x800B51C0: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
L_800B51C4:
    // 0x800B51C4: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B51C8: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x800B51CC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800B51D0: addu        $t0, $t6, $v0
    ctx->r8 = ADD32(ctx->r14, ctx->r2);
    // 0x800B51D4: slti        $at, $v1, 0x30
    ctx->r1 = SIGNED(ctx->r3) < 0X30 ? 1 : 0;
    // 0x800B51D8: addiu       $t0, $t0, -0x30
    ctx->r8 = ADD32(ctx->r8, -0X30);
    // 0x800B51DC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B51E0: bne         $at, $zero, L_800B51F4
    if (ctx->r1 != 0) {
        // 0x800B51E4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B51F4;
    }
    // 0x800B51E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B51E8: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B51EC: bne         $at, $zero, L_800B51C4
    if (ctx->r1 != 0) {
        // 0x800B51F0: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_800B51C4;
    }
    // 0x800B51F0: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
L_800B51F4:
    // 0x800B51F4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x800B51F8: bne         $v0, $at, L_800B52A0
    if (ctx->r2 != ctx->r1) {
        // 0x800B51FC: addiu       $at, $zero, 0x68
        ctx->r1 = ADD32(0, 0X68);
            goto L_800B52A0;
    }
    // 0x800B51FC: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800B5200: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B5204: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x800B5208: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B520C: bne         $v1, $at, L_800B5244
    if (ctx->r3 != ctx->r1) {
        // 0x800B5210: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B5244;
    }
    // 0x800B5210: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5214: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5218: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B521C: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B5220: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B5224: lw          $t2, -0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, -0X4);
    // 0x800B5228: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B522C: bgez        $t2, L_800B5238
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B5230: nop
    
            goto L_800B5238;
    }
    // 0x800B5230: nop

    // 0x800B5234: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_800B5238:
    // 0x800B5238: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B523C: b           L_800B529C
    // 0x800B5240: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B529C;
    // 0x800B5240: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B5244:
    // 0x800B5244: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x800B5248: bne         $at, $zero, L_800B529C
    if (ctx->r1 != 0) {
        // 0x800B524C: slti        $at, $v0, 0x3A
        ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
            goto L_800B529C;
    }
    // 0x800B524C: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B5250: beq         $at, $zero, L_800B529C
    if (ctx->r1 == 0) {
        // 0x800B5254: slti        $at, $v0, 0x30
        ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
            goto L_800B529C;
    }
    // 0x800B5254: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x800B5258: bne         $at, $zero, L_800B529C
    if (ctx->r1 != 0) {
        // 0x800B525C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800B529C;
    }
    // 0x800B525C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800B5260: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B5264: beq         $at, $zero, L_800B529C
    if (ctx->r1 == 0) {
        // 0x800B5268: sll         $t8, $t2, 2
        ctx->r24 = S32(ctx->r10 << 2);
            goto L_800B529C;
    }
    // 0x800B5268: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
L_800B526C:
    // 0x800B526C: lbu         $v1, 0x1($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X1);
    // 0x800B5270: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x800B5274: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800B5278: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800B527C: slti        $at, $v1, 0x30
    ctx->r1 = SIGNED(ctx->r3) < 0X30 ? 1 : 0;
    // 0x800B5280: addiu       $t2, $t2, -0x30
    ctx->r10 = ADD32(ctx->r10, -0X30);
    // 0x800B5284: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5288: bne         $at, $zero, L_800B529C
    if (ctx->r1 != 0) {
        // 0x800B528C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B529C;
    }
    // 0x800B528C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5290: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800B5294: bne         $at, $zero, L_800B526C
    if (ctx->r1 != 0) {
        // 0x800B5298: sll         $t8, $t2, 2
        ctx->r24 = S32(ctx->r10 << 2);
            goto L_800B526C;
    }
    // 0x800B5298: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
L_800B529C:
    // 0x800B529C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
L_800B52A0:
    // 0x800B52A0: beq         $v0, $at, L_800B52C4
    if (ctx->r2 == ctx->r1) {
        // 0x800B52A4: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_800B52C4;
    }
    // 0x800B52A4: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800B52A8: beq         $v0, $at, L_800B52C4
    if (ctx->r2 == ctx->r1) {
        // 0x800B52AC: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800B52C4;
    }
    // 0x800B52AC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800B52B0: beq         $v0, $at, L_800B52C4
    if (ctx->r2 == ctx->r1) {
        // 0x800B52B4: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_800B52C4;
    }
    // 0x800B52B4: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x800B52B8: beq         $v0, $at, L_800B52C4
    if (ctx->r2 == ctx->r1) {
        // 0x800B52BC: addiu       $at, $zero, 0x71
        ctx->r1 = ADD32(0, 0X71);
            goto L_800B52C4;
    }
    // 0x800B52BC: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x800B52C0: bne         $v0, $at, L_800B5364
    if (ctx->r2 != ctx->r1) {
        // 0x800B52C4: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B5364;
    }
L_800B52C4:
    // 0x800B52C4: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
L_800B52C8:
    // 0x800B52C8: sltiu       $at, $t9, 0x26
    ctx->r1 = ctx->r25 < 0X26 ? 1 : 0;
    // 0x800B52CC: beq         $at, $zero, L_800B5324
    if (ctx->r1 == 0) {
        // 0x800B52D0: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_800B5324;
    }
    // 0x800B52D0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B52D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800B52D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B52DC: addu        $at, $at, $t9
    gpr jr_addend_800B52E8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800B52E0: lw          $t9, -0x6D90($at)
    ctx->r25 = ADD32(ctx->r1, -0X6D90);
    // 0x800B52E4: nop

    // 0x800B52E8: jr          $t9
    // 0x800B52EC: nop

    switch (jr_addend_800B52E8 >> 2) {
        case 0: goto L_800B5310; break;
        case 1: goto L_800B5324; break;
        case 2: goto L_800B5324; break;
        case 3: goto L_800B5324; break;
        case 4: goto L_800B5324; break;
        case 5: goto L_800B5324; break;
        case 6: goto L_800B5324; break;
        case 7: goto L_800B5324; break;
        case 8: goto L_800B5324; break;
        case 9: goto L_800B5324; break;
        case 10: goto L_800B5324; break;
        case 11: goto L_800B5324; break;
        case 12: goto L_800B5324; break;
        case 13: goto L_800B5324; break;
        case 14: goto L_800B5318; break;
        case 15: goto L_800B5324; break;
        case 16: goto L_800B5324; break;
        case 17: goto L_800B5324; break;
        case 18: goto L_800B5324; break;
        case 19: goto L_800B5324; break;
        case 20: goto L_800B5324; break;
        case 21: goto L_800B5324; break;
        case 22: goto L_800B5324; break;
        case 23: goto L_800B5324; break;
        case 24: goto L_800B5324; break;
        case 25: goto L_800B5324; break;
        case 26: goto L_800B5324; break;
        case 27: goto L_800B5324; break;
        case 28: goto L_800B52F0; break;
        case 29: goto L_800B5324; break;
        case 30: goto L_800B5324; break;
        case 31: goto L_800B5324; break;
        case 32: goto L_800B52F8; break;
        case 33: goto L_800B5324; break;
        case 34: goto L_800B5324; break;
        case 35: goto L_800B5324; break;
        case 36: goto L_800B5324; break;
        case 37: goto L_800B5320; break;
        default: switch_error(__func__, 0x800B52E8, 0x800E9270);
    }
    // 0x800B52EC: nop

L_800B52F0:
    // 0x800B52F0: b           L_800B5324
    // 0x800B52F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800B5324;
    // 0x800B52F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800B52F8:
    // 0x800B52F8: beq         $a1, $zero, L_800B5308
    if (ctx->r5 == 0) {
        // 0x800B52FC: nop
    
            goto L_800B5308;
    }
    // 0x800B52FC: nop

    // 0x800B5300: b           L_800B5324
    // 0x800B5304: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B5324;
    // 0x800B5304: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B5308:
    // 0x800B5308: b           L_800B5324
    // 0x800B530C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800B5324;
    // 0x800B530C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800B5310:
    // 0x800B5310: b           L_800B5324
    // 0x800B5314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800B5324;
    // 0x800B5314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B5318:
    // 0x800B5318: b           L_800B5324
    // 0x800B531C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800B5324;
    // 0x800B531C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800B5320:
    // 0x800B5320: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800B5324:
    // 0x800B5324: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x800B5328: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800B532C: beq         $v1, $at, L_800B52C4
    if (ctx->r3 == ctx->r1) {
        // 0x800B5330: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B52C4;
    }
    // 0x800B5330: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B5334: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800B5338: beq         $v1, $at, L_800B52C8
    if (ctx->r3 == ctx->r1) {
        // 0x800B533C: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B52C8;
    }
    // 0x800B533C: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
    // 0x800B5340: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800B5344: beq         $v1, $at, L_800B52C8
    if (ctx->r3 == ctx->r1) {
        // 0x800B5348: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B52C8;
    }
    // 0x800B5348: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
    // 0x800B534C: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x800B5350: beq         $v1, $at, L_800B52C8
    if (ctx->r3 == ctx->r1) {
        // 0x800B5354: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B52C8;
    }
    // 0x800B5354: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
    // 0x800B5358: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x800B535C: beq         $v1, $at, L_800B52C8
    if (ctx->r3 == ctx->r1) {
        // 0x800B5360: addiu       $t9, $v0, -0x4C
        ctx->r25 = ADD32(ctx->r2, -0X4C);
            goto L_800B52C8;
    }
    // 0x800B5360: addiu       $t9, $v0, -0x4C
    ctx->r25 = ADD32(ctx->r2, -0X4C);
L_800B5364:
    // 0x800B5364: andi        $s3, $v1, 0xFF
    ctx->r19 = ctx->r3 & 0XFF;
    // 0x800B5368: addiu       $t6, $s3, -0x45
    ctx->r14 = ADD32(ctx->r19, -0X45);
    // 0x800B536C: sltiu       $at, $t6, 0x34
    ctx->r1 = ctx->r14 < 0X34 ? 1 : 0;
    // 0x800B5370: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800B5374: beq         $at, $zero, L_800B636C
    if (ctx->r1 == 0) {
        // 0x800B5378: sb          $s3, 0x19A($sp)
        MEM_B(0X19A, ctx->r29) = ctx->r19;
            goto L_800B636C;
    }
    // 0x800B5378: sb          $s3, 0x19A($sp)
    MEM_B(0X19A, ctx->r29) = ctx->r19;
    // 0x800B537C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B5380: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B5384: addu        $at, $at, $t6
    gpr jr_addend_800B5390 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B5388: lw          $t6, -0x6CF8($at)
    ctx->r14 = ADD32(ctx->r1, -0X6CF8);
    // 0x800B538C: nop

    // 0x800B5390: jr          $t6
    // 0x800B5394: nop

    switch (jr_addend_800B5390 >> 2) {
        case 0: goto L_800B5824; break;
        case 1: goto L_800B636C; break;
        case 2: goto L_800B5CF4; break;
        case 3: goto L_800B636C; break;
        case 4: goto L_800B636C; break;
        case 5: goto L_800B636C; break;
        case 6: goto L_800B636C; break;
        case 7: goto L_800B636C; break;
        case 8: goto L_800B636C; break;
        case 9: goto L_800B636C; break;
        case 10: goto L_800B636C; break;
        case 11: goto L_800B636C; break;
        case 12: goto L_800B636C; break;
        case 13: goto L_800B636C; break;
        case 14: goto L_800B636C; break;
        case 15: goto L_800B636C; break;
        case 16: goto L_800B636C; break;
        case 17: goto L_800B636C; break;
        case 18: goto L_800B636C; break;
        case 19: goto L_800B54E4; break;
        case 20: goto L_800B636C; break;
        case 21: goto L_800B636C; break;
        case 22: goto L_800B636C; break;
        case 23: goto L_800B636C; break;
        case 24: goto L_800B636C; break;
        case 25: goto L_800B636C; break;
        case 26: goto L_800B636C; break;
        case 27: goto L_800B636C; break;
        case 28: goto L_800B636C; break;
        case 29: goto L_800B636C; break;
        case 30: goto L_800B6024; break;
        case 31: goto L_800B5398; break;
        case 32: goto L_800B5824; break;
        case 33: goto L_800B5D04; break;
        case 34: goto L_800B5CF4; break;
        case 35: goto L_800B636C; break;
        case 36: goto L_800B5398; break;
        case 37: goto L_800B636C; break;
        case 38: goto L_800B636C; break;
        case 39: goto L_800B636C; break;
        case 40: goto L_800B636C; break;
        case 41: goto L_800B62D8; break;
        case 42: goto L_800B54C4; break;
        case 43: goto L_800B61EC; break;
        case 44: goto L_800B636C; break;
        case 45: goto L_800B636C; break;
        case 46: goto L_800B60A8; break;
        case 47: goto L_800B636C; break;
        case 48: goto L_800B54A4; break;
        case 49: goto L_800B636C; break;
        case 50: goto L_800B636C; break;
        case 51: goto L_800B5504; break;
        default: switch_error(__func__, 0x800B5390, 0x800E9308);
    }
    // 0x800B5394: nop

L_800B5398:
    // 0x800B5398: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B539C: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B53A0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800B53A4: beq         $a0, $zero, L_800B53D0
    if (ctx->r4 == 0) {
        // 0x800B53A8: addiu       $ra, $sp, 0x17B
        ctx->r31 = ADD32(ctx->r29, 0X17B);
            goto L_800B53D0;
    }
    // 0x800B53A8: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
    // 0x800B53AC: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B53B0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B53B4: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B53B8: addiu       $s1, $t7, 0x8
    ctx->r17 = ADD32(ctx->r15, 0X8);
    // 0x800B53BC: lw          $t8, -0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, -0X8);
    // 0x800B53C0: lw          $t9, -0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, -0X4);
    // 0x800B53C4: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B53C8: b           L_800B544C
    // 0x800B53CC: sw          $t9, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r25;
        goto L_800B544C;
    // 0x800B53CC: sw          $t9, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r25;
L_800B53D0:
    // 0x800B53D0: beq         $a1, $zero, L_800B53FC
    if (ctx->r5 == 0) {
        // 0x800B53D4: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B53FC;
    }
    // 0x800B53D4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B53D8: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B53DC: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B53E0: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B53E4: lw          $t7, -0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, -0X4);
    // 0x800B53E8: nop

    // 0x800B53EC: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800B53F0: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B53F4: b           L_800B544C
    // 0x800B53F8: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
        goto L_800B544C;
    // 0x800B53F8: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
L_800B53FC:
    // 0x800B53FC: bne         $a2, $zero, L_800B542C
    if (ctx->r6 != 0) {
        // 0x800B5400: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B542C;
    }
    // 0x800B5400: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5404: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5408: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B540C: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B5410: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B5414: lw          $t7, -0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, -0X4);
    // 0x800B5418: nop

    // 0x800B541C: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800B5420: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B5424: b           L_800B544C
    // 0x800B5428: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
        goto L_800B544C;
    // 0x800B5428: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
L_800B542C:
    // 0x800B542C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5430: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B5434: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B5438: lh          $t7, -0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, -0X2);
    // 0x800B543C: nop

    // 0x800B5440: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800B5444: sw          $t8, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r24;
    // 0x800B5448: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
L_800B544C:
    // 0x800B544C: lw          $t6, 0x180($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X180);
    // 0x800B5450: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800B5454: slti        $v0, $t6, 0x0
    ctx->r2 = SIGNED(ctx->r14) < 0X0 ? 1 : 0;
    // 0x800B5458: bgtz        $v0, L_800B546C
    if (SIGNED(ctx->r2) > 0) {
        // 0x800B545C: sltiu       $at, $t7, 0x1
        ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
            goto L_800B546C;
    }
    // 0x800B545C: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800B5460: bgtz        $t6, L_800B5470
    if (SIGNED(ctx->r14) > 0) {
        // 0x800B5464: andi        $t8, $v0, 0xFF
        ctx->r24 = ctx->r2 & 0XFF;
            goto L_800B5470;
    }
    // 0x800B5464: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x800B5468: sltiu       $v0, $t7, 0x0
    ctx->r2 = ctx->r15 < 0X0 ? 1 : 0;
L_800B546C:
    // 0x800B546C: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
L_800B5470:
    // 0x800B5470: beq         $t8, $zero, L_800B5490
    if (ctx->r24 == 0) {
        // 0x800B5474: andi        $s2, $v0, 0xFF
        ctx->r18 = ctx->r2 & 0XFF;
            goto L_800B5490;
    }
    // 0x800B5474: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x800B5478: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x800B547C: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x800B5480: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800B5484: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800B5488: b           L_800B55B8
    // 0x800B548C: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
        goto L_800B55B8;
    // 0x800B548C: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
L_800B5490:
    // 0x800B5490: lw          $t6, 0x180($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X180);
    // 0x800B5494: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800B5498: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B549C: b           L_800B55B8
    // 0x800B54A0: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
        goto L_800B55B8;
    // 0x800B54A0: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
L_800B54A4:
    // 0x800B54A4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B54A8: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B54AC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800B54B0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B54B4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B54B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B54BC: b           L_800B5520
    // 0x800B54C0: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B5520;
    // 0x800B54C0: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B54C4:
    // 0x800B54C4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B54C8: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B54CC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800B54D0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B54D4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B54D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B54DC: b           L_800B5520
    // 0x800B54E0: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B5520;
    // 0x800B54E0: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B54E4:
    // 0x800B54E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B54E8: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B54EC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800B54F0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B54F4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B54F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B54FC: b           L_800B5520
    // 0x800B5500: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B5520;
    // 0x800B5500: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B5504:
    // 0x800B5504: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5508: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B550C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800B5510: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B5514: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B5518: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B551C: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B5520:
    // 0x800B5520: beq         $a0, $zero, L_800B5548
    if (ctx->r4 == 0) {
        // 0x800B5524: addiu       $at, $zero, -0x8
        ctx->r1 = ADD32(0, -0X8);
            goto L_800B5548;
    }
    // 0x800B5524: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B5528: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B552C: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B5530: addiu       $s1, $t8, 0x8
    ctx->r17 = ADD32(ctx->r24, 0X8);
    // 0x800B5534: lw          $t6, -0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, -0X8);
    // 0x800B5538: lw          $t7, -0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, -0X4);
    // 0x800B553C: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B5540: b           L_800B55B8
    // 0x800B5544: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
        goto L_800B55B8;
    // 0x800B5544: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
L_800B5548:
    // 0x800B5548: beq         $a1, $zero, L_800B5570
    if (ctx->r5 == 0) {
        // 0x800B554C: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B5570;
    }
    // 0x800B554C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5550: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5554: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B5558: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B555C: lw          $t8, -0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, -0X4);
    // 0x800B5560: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B5564: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B5568: b           L_800B55B8
    // 0x800B556C: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
        goto L_800B55B8;
    // 0x800B556C: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
L_800B5570:
    // 0x800B5570: bne         $a2, $zero, L_800B559C
    if (ctx->r6 != 0) {
        // 0x800B5574: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B559C;
    }
    // 0x800B5574: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5578: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B557C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5580: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B5584: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B5588: lw          $t8, -0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, -0X4);
    // 0x800B558C: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B5590: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B5594: b           L_800B55B8
    // 0x800B5598: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
        goto L_800B55B8;
    // 0x800B5598: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
L_800B559C:
    // 0x800B559C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B55A0: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B55A4: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B55A8: lhu         $t8, -0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, -0X2);
    // 0x800B55AC: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B55B0: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B55B4: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
L_800B55B8:
    // 0x800B55B8: beq         $v1, $zero, L_800B55D0
    if (ctx->r3 == 0) {
        // 0x800B55BC: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800B55D0;
    }
    // 0x800B55BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B55C0: addiu       $t9, $zero, 0x84
    ctx->r25 = ADD32(0, 0X84);
    // 0x800B55C4: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B55C8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B55CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B55D0:
    // 0x800B55D0: bltz        $t2, L_800B55DC
    if (SIGNED(ctx->r10) < 0) {
        // 0x800B55D4: addiu       $a2, $sp, 0x17C
        ctx->r6 = ADD32(ctx->r29, 0X17C);
            goto L_800B55DC;
    }
    // 0x800B55D4: addiu       $a2, $sp, 0x17C
    ctx->r6 = ADD32(ctx->r29, 0X17C);
    // 0x800B55D8: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
L_800B55DC:
    // 0x800B55DC: bne         $t2, $at, L_800B55E8
    if (ctx->r10 != ctx->r1) {
        // 0x800B55E0: xori        $t8, $s3, 0x58
        ctx->r24 = ctx->r19 ^ 0X58;
            goto L_800B55E8;
    }
    // 0x800B55E0: xori        $t8, $s3, 0x58
    ctx->r24 = ctx->r19 ^ 0X58;
    // 0x800B55E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800B55E8:
    // 0x800B55E8: lw          $a0, 0x188($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X188);
    // 0x800B55EC: lw          $a1, 0x18C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18C);
    // 0x800B55F0: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x800B55F4: sw          $ra, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r31;
    // 0x800B55F8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800B55FC: sw          $a3, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r7;
    // 0x800B5600: sw          $t0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r8;
    // 0x800B5604: sw          $t1, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r9;
    // 0x800B5608: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800B560C: sw          $t3, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r11;
    // 0x800B5610: sb          $t4, 0x1A4($sp)
    MEM_B(0X1A4, ctx->r29) = ctx->r12;
    // 0x800B5614: swc1        $f17, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800B5618: jal         0x800B4EA0
    // 0x800B561C: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    _itoa(rdram, ctx);
        goto after_0;
    // 0x800B561C: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800B5620: addiu       $t6, $sp, 0x17B
    ctx->r14 = ADD32(ctx->r29, 0X17B);
    // 0x800B5624: lw          $t0, 0x1A0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A0);
    // 0x800B5628: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800B562C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800B5630: subu        $v1, $t6, $v0
    ctx->r3 = SUB32(ctx->r14, ctx->r2);
    // 0x800B5634: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B5638: lw          $a3, 0x194($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X194);
    // 0x800B563C: lw          $t1, 0x1AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1AC);
    // 0x800B5640: lw          $t3, 0x1B4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B4);
    // 0x800B5644: lbu         $t4, 0x1A4($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1A4);
    // 0x800B5648: lw          $ra, 0xF8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XF8);
    // 0x800B564C: lwc1        $f17, 0xE0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x800B5650: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800B5654: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B5658: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x800B565C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B5660: sltu        $a2, $zero, $fp
    ctx->r6 = 0 < ctx->r30 ? 1 : 0;
    // 0x800B5664: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B5668: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800B566C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x800B5670: beq         $a2, $zero, L_800B5698
    if (ctx->r6 == 0) {
        // 0x800B5674: subu        $t2, $t2, $v1
        ctx->r10 = SUB32(ctx->r10, ctx->r3);
            goto L_800B5698;
    }
    // 0x800B5674: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x800B5678: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800B567C: bne         $a3, $at, L_800B569C
    if (ctx->r7 != ctx->r1) {
        // 0x800B5680: slt         $s3, $zero, $t2
        ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800B569C;
    }
    // 0x800B5680: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B5684: bgtz        $t2, L_800B5698
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B5688: addiu       $t7, $zero, 0x30
        ctx->r15 = ADD32(0, 0X30);
            goto L_800B5698;
    }
    // 0x800B5688: addiu       $t7, $zero, 0x30
    ctx->r15 = ADD32(0, 0X30);
    // 0x800B568C: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x800B5690: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x800B5694: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5698:
    // 0x800B5698: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
L_800B569C:
    // 0x800B569C: beq         $s3, $zero, L_800B56C8
    if (ctx->r19 == 0) {
        // 0x800B56A0: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800B56C8;
    }
    // 0x800B56A0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800B56A4: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x800B56A8: beq         $s3, $zero, L_800B56C8
    if (ctx->r19 == 0) {
        // 0x800B56AC: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_800B56C8;
    }
    // 0x800B56AC: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800B56B0: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_800B56B4:
    // 0x800B56B4: slt         $v1, $zero, $t2
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B56B8: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800B56BC: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800B56C0: bne         $v1, $zero, L_800B56B4
    if (ctx->r3 != 0) {
        // 0x800B56C4: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800B56B4;
    }
    // 0x800B56C4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_800B56C8:
    // 0x800B56C8: beq         $a2, $zero, L_800B56DC
    if (ctx->r6 == 0) {
        // 0x800B56CC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800B56DC;
    }
    // 0x800B56CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B56D0: bne         $a3, $at, L_800B56DC
    if (ctx->r7 != ctx->r1) {
        // 0x800B56D4: nop
    
            goto L_800B56DC;
    }
    // 0x800B56D4: nop

    // 0x800B56D8: addiu       $t0, $t0, -0x2
    ctx->r8 = ADD32(ctx->r8, -0X2);
L_800B56DC:
    // 0x800B56DC: bne         $s2, $zero, L_800B56F4
    if (ctx->r18 != 0) {
        // 0x800B56E0: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_800B56F4;
    }
    // 0x800B56E0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B56E4: bne         $s5, $zero, L_800B56F4
    if (ctx->r21 != 0) {
        // 0x800B56E8: nop
    
            goto L_800B56F4;
    }
    // 0x800B56E8: nop

    // 0x800B56EC: beq         $s6, $zero, L_800B56F8
    if (ctx->r22 == 0) {
        // 0x800B56F0: nop
    
            goto L_800B56F8;
    }
    // 0x800B56F0: nop

L_800B56F4:
    // 0x800B56F4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B56F8:
    // 0x800B56F8: bne         $s7, $zero, L_800B5728
    if (ctx->r23 != 0) {
        // 0x800B56FC: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_800B5728;
    }
    // 0x800B56FC: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B5700: bne         $t4, $at, L_800B5728
    if (ctx->r12 != ctx->r1) {
        // 0x800B5704: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5728;
    }
    // 0x800B5704: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5708: beq         $v1, $zero, L_800B5728
    if (ctx->r3 == 0) {
        // 0x800B570C: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5728;
    }
    // 0x800B570C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5710:
    // 0x800B5710: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5714: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5718: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B571C: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5720: bne         $v1, $zero, L_800B5710
    if (ctx->r3 != 0) {
        // 0x800B5724: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5710;
    }
    // 0x800B5724: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5728:
    // 0x800B5728: beq         $s2, $zero, L_800B5740
    if (ctx->r18 == 0) {
        // 0x800B572C: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800B5740;
    }
    // 0x800B572C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800B5730: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5734: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5738: b           L_800B576C
    // 0x800B573C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B576C;
    // 0x800B573C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5740:
    // 0x800B5740: beq         $s5, $zero, L_800B5758
    if (ctx->r21 == 0) {
        // 0x800B5744: addiu       $t8, $zero, 0x2B
        ctx->r24 = ADD32(0, 0X2B);
            goto L_800B5758;
    }
    // 0x800B5744: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x800B5748: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B574C: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B5750: b           L_800B576C
    // 0x800B5754: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B576C;
    // 0x800B5754: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5758:
    // 0x800B5758: beq         $s6, $zero, L_800B576C
    if (ctx->r22 == 0) {
        // 0x800B575C: nop
    
            goto L_800B576C;
    }
    // 0x800B575C: nop

    // 0x800B5760: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5764: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5768: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B576C:
    // 0x800B576C: beq         $a2, $zero, L_800B5790
    if (ctx->r6 == 0) {
        // 0x800B5770: addiu       $t8, $sp, 0x17B
        ctx->r24 = ADD32(ctx->r29, 0X17B);
            goto L_800B5790;
    }
    // 0x800B5770: addiu       $t8, $sp, 0x17B
    ctx->r24 = ADD32(ctx->r29, 0X17B);
    // 0x800B5774: bne         $a3, $at, L_800B5790
    if (ctx->r7 != ctx->r1) {
        // 0x800B5778: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_800B5790;
    }
    // 0x800B5778: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800B577C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800B5780: lbu         $t7, 0x19A($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X19A);
    // 0x800B5784: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800B5788: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800B578C: sb          $t7, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r15;
L_800B5790:
    // 0x800B5790: bne         $s7, $zero, L_800B57C4
    if (ctx->r23 != 0) {
        // 0x800B5794: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B57C4;
    }
    // 0x800B5794: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B5798: bne         $t4, $at, L_800B57C4
    if (ctx->r12 != ctx->r1) {
        // 0x800B579C: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B57C4;
    }
    // 0x800B579C: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B57A0: beq         $v1, $zero, L_800B57C4
    if (ctx->r3 == 0) {
        // 0x800B57A4: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B57C4;
    }
    // 0x800B57A4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B57A8:
    // 0x800B57A8: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x800B57AC: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B57B0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B57B4: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B57B8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B57BC: bne         $v1, $zero, L_800B57A8
    if (ctx->r3 != 0) {
        // 0x800B57C0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B57A8;
    }
    // 0x800B57C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B57C4:
    // 0x800B57C4: sltu        $at, $t8, $a0
    ctx->r1 = ctx->r24 < ctx->r4 ? 1 : 0;
    // 0x800B57C8: bne         $at, $zero, L_800B57EC
    if (ctx->r1 != 0) {
        // 0x800B57CC: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B57EC;
    }
    // 0x800B57CC: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
L_800B57D0:
    // 0x800B57D0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800B57D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B57D8: sltu        $at, $ra, $a0
    ctx->r1 = ctx->r31 < ctx->r4 ? 1 : 0;
    // 0x800B57DC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B57E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B57E4: beq         $at, $zero, L_800B57D0
    if (ctx->r1 == 0) {
        // 0x800B57E8: sb          $t6, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r14;
            goto L_800B57D0;
    }
    // 0x800B57E8: sb          $t6, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r14;
L_800B57EC:
    // 0x800B57EC: beq         $s7, $zero, L_800B5814
    if (ctx->r23 == 0) {
        // 0x800B57F0: nop
    
            goto L_800B5814;
    }
    // 0x800B57F0: nop

    // 0x800B57F4: beq         $v1, $zero, L_800B5814
    if (ctx->r3 == 0) {
        // 0x800B57F8: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5814;
    }
    // 0x800B57F8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B57FC:
    // 0x800B57FC: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5800: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5804: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5808: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B580C: bne         $v1, $zero, L_800B57FC
    if (ctx->r3 != 0) {
        // 0x800B5810: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B57FC;
    }
    // 0x800B5810: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5814:
    // 0x800B5814: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5818: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B581C: b           L_800B6378
    // 0x800B5820: nop

        goto L_800B6378;
    // 0x800B5820: nop

L_800B5824:
    // 0x800B5824: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B5828: lw          $t7, 0x3480($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3480);
    // 0x800B582C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B5830: beq         $t7, $zero, L_800B5844
    if (ctx->r15 == 0) {
        // 0x800B5834: addiu       $t9, $zero, 0x84
        ctx->r25 = ADD32(0, 0X84);
            goto L_800B5844;
    }
    // 0x800B5834: addiu       $t9, $zero, 0x84
    ctx->r25 = ADD32(0, 0X84);
    // 0x800B5838: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B583C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5840: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5844:
    // 0x800B5844: bgez        $t2, L_800B5850
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B5848: andi        $t6, $s1, 0x1
        ctx->r14 = ctx->r17 & 0X1;
            goto L_800B5850;
    }
    // 0x800B5848: andi        $t6, $s1, 0x1
    ctx->r14 = ctx->r17 & 0X1;
    // 0x800B584C: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
L_800B5850:
    // 0x800B5850: beq         $a2, $zero, L_800B587C
    if (ctx->r6 == 0) {
        // 0x800B5854: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B587C;
    }
    // 0x800B5854: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5858: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B585C: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B5860: addiu       $s1, $t8, 0x4
    ctx->r17 = ADD32(ctx->r24, 0X4);
    // 0x800B5864: lwc1        $f4, -0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X4);
    // 0x800B5868: nop

    // 0x800B586C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B5870: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x800B5874: b           L_800B58C8
    // 0x800B5878: swc1        $f7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
        goto L_800B58C8;
    // 0x800B5878: swc1        $f7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
L_800B587C:
    // 0x800B587C: beq         $t6, $zero, L_800B5890
    if (ctx->r14 == 0) {
        // 0x800B5880: andi        $t7, $s1, 0x2
        ctx->r15 = ctx->r17 & 0X2;
            goto L_800B5890;
    }
    // 0x800B5880: andi        $t7, $s1, 0x2
    ctx->r15 = ctx->r17 & 0X2;
    // 0x800B5884: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B5888: b           L_800B58B8
    // 0x800B588C: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
        goto L_800B58B8;
    // 0x800B588C: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
L_800B5890:
    // 0x800B5890: beq         $t7, $zero, L_800B58A4
    if (ctx->r15 == 0) {
        // 0x800B5894: addiu       $at, $zero, -0x8
        ctx->r1 = ADD32(0, -0X8);
            goto L_800B58A4;
    }
    // 0x800B5894: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B5898: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x800B589C: b           L_800B58B4
    // 0x800B58A0: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
        goto L_800B58B4;
    // 0x800B58A0: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
L_800B58A4:
    // 0x800B58A4: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B58A8: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B58AC: addiu       $s1, $t9, 0x8
    ctx->r17 = ADD32(ctx->r25, 0X8);
    // 0x800B58B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800B58B4:
    // 0x800B58B4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800B58B8:
    // 0x800B58B8: lwc1        $f9, -0x8($v1)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r3, -0X8);
    // 0x800B58BC: lwc1        $f8, -0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X4);
    // 0x800B58C0: swc1        $f9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800B58C4: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
L_800B58C8:
    // 0x800B58C8: lb          $t8, 0xD0($sp)
    ctx->r24 = MEM_B(ctx->r29, 0XD0);
    // 0x800B58CC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800B58D0: bgez        $t8, L_800B58F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B58D4: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_800B58F0;
    }
    // 0x800B58D4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B58D8: lwc1        $f11, 0xD0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B58DC: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B58E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B58E4: neg.d       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = -ctx->f10.d;
    // 0x800B58E8: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x800B58EC: swc1        $f5, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
L_800B58F0:
    // 0x800B58F0: lwc1        $f7, 0xD0($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B58F4: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B58F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B58FC: lwc1        $f11, 0xD0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5900: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x800B5904: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5908: lwc1        $f7, 0xD0($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B590C: bc1f        L_800B5920
    if (!c1cs) {
        // 0x800B5910: andi        $a0, $t2, 0x3
        ctx->r4 = ctx->r10 & 0X3;
            goto L_800B5920;
    }
    // 0x800B5910: andi        $a0, $t2, 0x3
    ctx->r4 = ctx->r10 & 0X3;
    // 0x800B5914: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B5918: b           L_800B596C
    // 0x800B591C: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
        goto L_800B596C;
    // 0x800B591C: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
L_800B5920:
    // 0x800B5920: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5924: nop

    // 0x800B5928: c.lt.d      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.d < ctx->f20.d;
    // 0x800B592C: nop

    // 0x800B5930: bc1f        L_800B596C
    if (!c1cs) {
        // 0x800B5934: nop
    
            goto L_800B596C;
    }
    // 0x800B5934: nop

    // 0x800B5938: c.lt.d      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.d < ctx->f20.d;
    // 0x800B593C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B5940: bc1f        L_800B596C
    if (!c1cs) {
        // 0x800B5944: mov.d       $f16, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
            goto L_800B596C;
    }
    // 0x800B5944: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
    // 0x800B5948: nop

L_800B594C:
    // 0x800B594C: div.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x800B5950: lwc1        $f5, 0xD0($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5954: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5958: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800B595C: c.lt.d      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.d < ctx->f16.d;
    // 0x800B5960: nop

    // 0x800B5964: bc1t        L_800B594C
    if (c1cs) {
        // 0x800B5968: nop
    
            goto L_800B594C;
    }
    // 0x800B5968: nop

L_800B596C:
    // 0x800B596C: c.le.d      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.d <= ctx->f6.d;
    // 0x800B5970: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800B5974: bc1f        L_800B59B4
    if (!c1cs) {
        // 0x800B5978: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_800B59B4;
    }
    // 0x800B5978: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800B597C: c.le.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d <= ctx->f6.d;
    // 0x800B5980: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B5984: mov.d       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.d = ctx->f20.d;
    // 0x800B5988: bc1f        L_800B59B4
    if (!c1cs) {
        // 0x800B598C: mov.d       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.d = ctx->f18.d;
            goto L_800B59B4;
    }
    // 0x800B598C: mov.d       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.d = ctx->f18.d;
L_800B5990:
    // 0x800B5990: mov.d       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.d = ctx->f0.d;
    // 0x800B5994: mul.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800B5998: lwc1        $f9, 0xD0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B599C: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B59A0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800B59A4: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x800B59A8: nop

    // 0x800B59AC: bc1t        L_800B5990
    if (c1cs) {
        // 0x800B59B0: nop
    
            goto L_800B5990;
    }
    // 0x800B59B0: nop

L_800B59B4:
    // 0x800B59B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B59B8: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B59BC: mul.d       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f16.d, ctx->f10.d);
    // 0x800B59C0: beq         $s3, $zero, L_800B5A24
    if (ctx->r19 == 0) {
        // 0x800B59C4: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800B5A24;
    }
    // 0x800B59C4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800B59C8: beq         $a0, $zero, L_800B59E0
    if (ctx->r4 == 0) {
        // 0x800B59CC: addu        $v1, $a0, $t2
        ctx->r3 = ADD32(ctx->r4, ctx->r10);
            goto L_800B59E0;
    }
    // 0x800B59CC: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
L_800B59D0:
    // 0x800B59D0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B59D4: bne         $v1, $v0, L_800B59D0
    if (ctx->r3 != ctx->r2) {
        // 0x800B59D8: div.d       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
            goto L_800B59D0;
    }
    // 0x800B59D8: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B59DC: beq         $v0, $zero, L_800B5A24
    if (ctx->r2 == 0) {
        // 0x800B59E0: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800B5A24;
    }
L_800B59E0:
    // 0x800B59E0: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800B59E4: beq         $v0, $zero, L_800B5A0C
    if (ctx->r2 == 0) {
        // 0x800B59E8: div.d       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
            goto L_800B5A0C;
    }
    // 0x800B59E8: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
L_800B59EC:
    // 0x800B59EC: nop

    // 0x800B59F0: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B59F4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800B59F8: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B59FC: nop

    // 0x800B5A00: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B5A04: bne         $v0, $zero, L_800B59EC
    if (ctx->r2 != 0) {
        // 0x800B5A08: div.d       $f0, $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
            goto L_800B59EC;
    }
    // 0x800B5A08: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
L_800B5A0C:
    // 0x800B5A0C: nop

    // 0x800B5A10: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B5A14: nop

    // 0x800B5A18: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
    // 0x800B5A1C: nop

    // 0x800B5A20: div.d       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f18.d);
L_800B5A24:
    // 0x800B5A24: mul.d       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800B5A28: lwc1        $f5, 0xD0($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5A2C: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5A30: sltu        $v0, $zero, $a1
    ctx->r2 = 0 < ctx->r5 ? 1 : 0;
    // 0x800B5A34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B5A38: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x800B5A3C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B5A40: c.le.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d <= ctx->f6.d;
    // 0x800B5A44: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x800B5A48: bc1f        L_800B5A58
    if (!c1cs) {
        // 0x800B5A4C: swc1        $f7, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
            goto L_800B5A58;
    }
    // 0x800B5A4C: swc1        $f7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
    // 0x800B5A50: mov.d       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.d = ctx->f2.d;
    // 0x800B5A54: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800B5A58:
    // 0x800B5A58: slti        $a2, $s4, 0x64
    ctx->r6 = SIGNED(ctx->r20) < 0X64 ? 1 : 0;
    // 0x800B5A5C: bne         $v0, $zero, L_800B5A74
    if (ctx->r2 != 0) {
        // 0x800B5A60: xori        $a2, $a2, 0x1
        ctx->r6 = ctx->r6 ^ 0X1;
            goto L_800B5A74;
    }
    // 0x800B5A60: xori        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 ^ 0X1;
    // 0x800B5A64: sltu        $a0, $zero, $s5
    ctx->r4 = 0 < ctx->r21 ? 1 : 0;
    // 0x800B5A68: bne         $a0, $zero, L_800B5A74
    if (ctx->r4 != 0) {
        // 0x800B5A6C: nop
    
            goto L_800B5A74;
    }
    // 0x800B5A6C: nop

    // 0x800B5A70: sltu        $a0, $zero, $s6
    ctx->r4 = 0 < ctx->r22 ? 1 : 0;
L_800B5A74:
    // 0x800B5A74: bne         $s3, $zero, L_800B5A80
    if (ctx->r19 != 0) {
        // 0x800B5A78: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_800B5A80;
    }
    // 0x800B5A78: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x800B5A7C: sltu        $v1, $zero, $fp
    ctx->r3 = 0 < ctx->r30 ? 1 : 0;
L_800B5A80:
    // 0x800B5A80: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x800B5A84: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x800B5A88: addu        $a1, $t7, $a2
    ctx->r5 = ADD32(ctx->r15, ctx->r6);
    // 0x800B5A8C: bne         $s7, $zero, L_800B5ABC
    if (ctx->r23 != 0) {
        // 0x800B5A90: addiu       $a1, $a1, 0x5
        ctx->r5 = ADD32(ctx->r5, 0X5);
            goto L_800B5ABC;
    }
    // 0x800B5A90: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
    // 0x800B5A94: bne         $t4, $at, L_800B5ABC
    if (ctx->r12 != ctx->r1) {
        // 0x800B5A98: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5ABC;
    }
    // 0x800B5A98: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5A9C: beq         $v1, $zero, L_800B5ABC
    if (ctx->r3 == 0) {
        // 0x800B5AA0: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5ABC;
    }
    // 0x800B5AA0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5AA4:
    // 0x800B5AA4: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5AA8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5AAC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5AB0: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B5AB4: bne         $v1, $zero, L_800B5AA4
    if (ctx->r3 != 0) {
        // 0x800B5AB8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5AA4;
    }
    // 0x800B5AB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5ABC:
    // 0x800B5ABC: beq         $v0, $zero, L_800B5AD4
    if (ctx->r2 == 0) {
        // 0x800B5AC0: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_800B5AD4;
    }
    // 0x800B5AC0: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B5AC4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5AC8: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5ACC: b           L_800B5B00
    // 0x800B5AD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B5B00;
    // 0x800B5AD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5AD4:
    // 0x800B5AD4: beq         $s5, $zero, L_800B5AEC
    if (ctx->r21 == 0) {
        // 0x800B5AD8: addiu       $t8, $zero, 0x2B
        ctx->r24 = ADD32(0, 0X2B);
            goto L_800B5AEC;
    }
    // 0x800B5AD8: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x800B5ADC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5AE0: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B5AE4: b           L_800B5B00
    // 0x800B5AE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B5B00;
    // 0x800B5AE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5AEC:
    // 0x800B5AEC: beq         $s6, $zero, L_800B5B00
    if (ctx->r22 == 0) {
        // 0x800B5AF0: nop
    
            goto L_800B5B00;
    }
    // 0x800B5AF0: nop

    // 0x800B5AF4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5AF8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5AFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5B00:
    // 0x800B5B00: bne         $s7, $zero, L_800B5B30
    if (ctx->r23 != 0) {
        // 0x800B5B04: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B5B30;
    }
    // 0x800B5B04: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B5B08: bne         $t4, $at, L_800B5B30
    if (ctx->r12 != ctx->r1) {
        // 0x800B5B0C: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5B30;
    }
    // 0x800B5B0C: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5B10: beq         $v1, $zero, L_800B5B30
    if (ctx->r3 == 0) {
        // 0x800B5B14: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5B30;
    }
    // 0x800B5B14: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5B18:
    // 0x800B5B18: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5B1C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5B20: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5B24: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B5B28: bne         $v1, $zero, L_800B5B18
    if (ctx->r3 != 0) {
        // 0x800B5B2C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5B18;
    }
    // 0x800B5B2C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5B30:
    // 0x800B5B30: lwc1        $f9, 0xD0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5B34: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5B38: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B5B3C: c.le.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d <= ctx->f8.d;
    // 0x800B5B40: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5B44: bc1f        L_800B5B6C
    if (!c1cs) {
        // 0x800B5B48: addiu       $t6, $zero, 0x2E
        ctx->r14 = ADD32(0, 0X2E);
            goto L_800B5B6C;
    }
    // 0x800B5B48: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
L_800B5B4C:
    // 0x800B5B4C: lwc1        $f11, 0xD0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5B50: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5B54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5B58: sub.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f10.d - ctx->f16.d;
    // 0x800B5B5C: c.le.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d <= ctx->f4.d;
    // 0x800B5B60: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x800B5B64: bc1t        L_800B5B4C
    if (c1cs) {
        // 0x800B5B68: swc1        $f5, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
            goto L_800B5B4C;
    }
    // 0x800B5B68: swc1        $f5, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
L_800B5B6C:
    // 0x800B5B6C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5B70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5B74: bne         $s3, $zero, L_800B5B84
    if (ctx->r19 != 0) {
        // 0x800B5B78: div.d       $f16, $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
            goto L_800B5B84;
    }
    // 0x800B5B78: div.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x800B5B7C: beq         $fp, $zero, L_800B5B90
    if (ctx->r30 == 0) {
        // 0x800B5B80: nop
    
            goto L_800B5B90;
    }
    // 0x800B5B80: nop

L_800B5B84:
    // 0x800B5B84: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5B88: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800B5B8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5B90:
    // 0x800B5B90: beq         $s3, $zero, L_800B5BE4
    if (ctx->r19 == 0) {
        // 0x800B5B94: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800B5BE4;
    }
    // 0x800B5B94: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800B5B98:
    // 0x800B5B98: lwc1        $f7, 0xD0($sp)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5B9C: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5BA0: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B5BA4: c.le.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d <= ctx->f6.d;
    // 0x800B5BA8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5BAC: bc1f        L_800B5BD4
    if (!c1cs) {
        // 0x800B5BB0: addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
            goto L_800B5BD4;
    }
    // 0x800B5BB0: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
L_800B5BB4:
    // 0x800B5BB4: lwc1        $f9, 0xD0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0XD0);
    // 0x800B5BB8: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800B5BBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5BC0: sub.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f8.d - ctx->f16.d;
    // 0x800B5BC4: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x800B5BC8: swc1        $f10, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f10.u32l;
    // 0x800B5BCC: bc1t        L_800B5BB4
    if (c1cs) {
        // 0x800B5BD0: swc1        $f11, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
            goto L_800B5BB4;
    }
    // 0x800B5BD0: swc1        $f11, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f_odd[(11 - 1) * 2];
L_800B5BD4:
    // 0x800B5BD4: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5BD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5BDC: bgtz        $t2, L_800B5B98
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B5BE0: div.d       $f16, $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
            goto L_800B5B98;
    }
    // 0x800B5BE0: div.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = DIV_D(ctx->f16.d, ctx->f18.d);
L_800B5BE4:
    // 0x800B5BE4: lbu         $t7, 0x19A($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X19A);
    // 0x800B5BE8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5BEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5BF0: bgez        $s4, L_800B5C4C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800B5BF4: sb          $t7, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r15;
            goto L_800B5C4C;
    }
    // 0x800B5BF4: sb          $t7, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r15;
    // 0x800B5BF8: negu        $s4, $s4
    ctx->r20 = SUB32(0, ctx->r20);
    // 0x800B5BFC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800B5C00: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5C04: slti        $a2, $s4, 0x64
    ctx->r6 = SIGNED(ctx->r20) < 0X64 ? 1 : 0;
    // 0x800B5C08: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B5C0C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5C10: xori        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 ^ 0X1;
    // 0x800B5C14: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5C18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5C1C: mflo        $v1
    ctx->r3 = lo;
    // 0x800B5C20: nop

    // 0x800B5C24: nop

    // 0x800B5C28: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800B5C2C: mfhi        $t8
    ctx->r24 = hi;
    // 0x800B5C30: addiu       $v1, $t8, 0x30
    ctx->r3 = ADD32(ctx->r24, 0X30);
    // 0x800B5C34: nop

    // 0x800B5C38: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5C3C: mfhi        $a0
    ctx->r4 = hi;
    // 0x800B5C40: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800B5C44: b           L_800B5C8C
    // 0x800B5C48: nop

        goto L_800B5C8C;
    // 0x800B5C48: nop

L_800B5C4C:
    // 0x800B5C4C: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5C50: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x800B5C54: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x800B5C58: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5C5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5C60: mflo        $v1
    ctx->r3 = lo;
    // 0x800B5C64: nop

    // 0x800B5C68: nop

    // 0x800B5C6C: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800B5C70: mfhi        $t6
    ctx->r14 = hi;
    // 0x800B5C74: addiu       $v1, $t6, 0x30
    ctx->r3 = ADD32(ctx->r14, 0X30);
    // 0x800B5C78: nop

    // 0x800B5C7C: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5C80: mfhi        $a0
    ctx->r4 = hi;
    // 0x800B5C84: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x800B5C88: nop

L_800B5C8C:
    // 0x800B5C8C: beq         $a2, $zero, L_800B5CAC
    if (ctx->r6 == 0) {
        // 0x800B5C90: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_800B5CAC;
    }
    // 0x800B5C90: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800B5C94: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x800B5C98: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5C9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5CA0: mflo        $v0
    ctx->r2 = lo;
    // 0x800B5CA4: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800B5CA8: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
L_800B5CAC:
    // 0x800B5CAC: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x800B5CB0: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800B5CB4: sb          $a0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r4;
    // 0x800B5CB8: beq         $s7, $zero, L_800B5CE4
    if (ctx->r23 == 0) {
        // 0x800B5CBC: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_800B5CE4;
    }
    // 0x800B5CBC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800B5CC0: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5CC4: beq         $v1, $zero, L_800B5CE4
    if (ctx->r3 == 0) {
        // 0x800B5CC8: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5CE4;
    }
    // 0x800B5CC8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5CCC:
    // 0x800B5CCC: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5CD0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5CD4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5CD8: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5CDC: bne         $v1, $zero, L_800B5CCC
    if (ctx->r3 != 0) {
        // 0x800B5CE0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5CCC;
    }
    // 0x800B5CE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5CE4:
    // 0x800B5CE4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5CE8: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B5CEC: b           L_800B6378
    // 0x800B5CF0: nop

        goto L_800B6378;
    // 0x800B5CF0: nop

L_800B5CF4:
    // 0x800B5CF4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B5CF8: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B5CFC: b           L_800B6378
    // 0x800B5D00: nop

        goto L_800B6378;
    // 0x800B5D00: nop

L_800B5D04:
    // 0x800B5D04: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B5D08: lw          $t9, 0x3480($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3480);
    // 0x800B5D0C: mov.d       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.d = ctx->f20.d;
    // 0x800B5D10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B5D14: beq         $t9, $zero, L_800B5D2C
    if (ctx->r25 == 0) {
        // 0x800B5D18: mov.d       $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.d = ctx->f18.d;
            goto L_800B5D2C;
    }
    // 0x800B5D18: mov.d       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.d = ctx->f18.d;
    // 0x800B5D1C: addiu       $t8, $zero, 0x84
    ctx->r24 = ADD32(0, 0X84);
    // 0x800B5D20: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B5D24: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5D28: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5D2C:
    // 0x800B5D2C: bgez        $t2, L_800B5D3C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B5D30: slt         $s3, $zero, $t2
        ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800B5D3C;
    }
    // 0x800B5D30: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B5D34: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x800B5D38: slt         $s3, $zero, $t2
    ctx->r19 = SIGNED(0) < SIGNED(ctx->r10) ? 1 : 0;
L_800B5D3C:
    // 0x800B5D3C: beq         $s3, $zero, L_800B5DA4
    if (ctx->r19 == 0) {
        // 0x800B5D40: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B5DA4;
    }
    // 0x800B5D40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B5D44: andi        $a0, $t2, 0x3
    ctx->r4 = ctx->r10 & 0X3;
    // 0x800B5D48: beq         $a0, $zero, L_800B5D60
    if (ctx->r4 == 0) {
        // 0x800B5D4C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800B5D60;
    }
    // 0x800B5D4C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800B5D50:
    // 0x800B5D50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5D54: bne         $v1, $v0, L_800B5D50
    if (ctx->r3 != ctx->r2) {
        // 0x800B5D58: div.d       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
            goto L_800B5D50;
    }
    // 0x800B5D58: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D5C: beq         $v0, $t2, L_800B5DA4
    if (ctx->r2 == ctx->r10) {
        // 0x800B5D60: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800B5DA4;
    }
L_800B5D60:
    // 0x800B5D60: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B5D64: beq         $v0, $t2, L_800B5D8C
    if (ctx->r2 == ctx->r10) {
        // 0x800B5D68: div.d       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
            goto L_800B5D8C;
    }
    // 0x800B5D68: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
L_800B5D6C:
    // 0x800B5D6C: nop

    // 0x800B5D70: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B5D78: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D7C: nop

    // 0x800B5D80: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D84: bne         $v0, $t2, L_800B5D6C
    if (ctx->r2 != ctx->r10) {
        // 0x800B5D88: div.d       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
            goto L_800B5D6C;
    }
    // 0x800B5D88: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
L_800B5D8C:
    // 0x800B5D8C: nop

    // 0x800B5D90: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D94: nop

    // 0x800B5D98: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
    // 0x800B5D9C: nop

    // 0x800B5DA0: div.d       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f18.d);
L_800B5DA4:
    // 0x800B5DA4: beq         $a2, $zero, L_800B5DC8
    if (ctx->r6 == 0) {
        // 0x800B5DA8: andi        $t7, $s1, 0x1
        ctx->r15 = ctx->r17 & 0X1;
            goto L_800B5DC8;
    }
    // 0x800B5DA8: andi        $t7, $s1, 0x1
    ctx->r15 = ctx->r17 & 0X1;
    // 0x800B5DAC: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B5DB0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B5DB4: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B5DB8: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B5DBC: lwc1        $f4, -0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, -0X4);
    // 0x800B5DC0: b           L_800B5E10
    // 0x800B5DC4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
        goto L_800B5E10;
    // 0x800B5DC4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
L_800B5DC8:
    // 0x800B5DC8: beq         $t7, $zero, L_800B5DDC
    if (ctx->r15 == 0) {
        // 0x800B5DCC: andi        $t9, $s1, 0x2
        ctx->r25 = ctx->r17 & 0X2;
            goto L_800B5DDC;
    }
    // 0x800B5DCC: andi        $t9, $s1, 0x2
    ctx->r25 = ctx->r17 & 0X2;
    // 0x800B5DD0: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B5DD4: b           L_800B5E04
    // 0x800B5DD8: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
        goto L_800B5E04;
    // 0x800B5DD8: addiu       $v1, $s1, -0x16
    ctx->r3 = ADD32(ctx->r17, -0X16);
L_800B5DDC:
    // 0x800B5DDC: beq         $t9, $zero, L_800B5DF0
    if (ctx->r25 == 0) {
        // 0x800B5DE0: addiu       $at, $zero, -0x8
        ctx->r1 = ADD32(0, -0X8);
            goto L_800B5DF0;
    }
    // 0x800B5DE0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800B5DE4: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x800B5DE8: b           L_800B5E00
    // 0x800B5DEC: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
        goto L_800B5E00;
    // 0x800B5DEC: addiu       $a0, $s1, -0x28
    ctx->r4 = ADD32(ctx->r17, -0X28);
L_800B5DF0:
    // 0x800B5DF0: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x800B5DF4: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B5DF8: addiu       $s1, $t8, 0x8
    ctx->r17 = ADD32(ctx->r24, 0X8);
    // 0x800B5DFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800B5E00:
    // 0x800B5E00: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800B5E04:
    // 0x800B5E04: lwc1        $f1, -0x8($v1)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r3, -0X8);
    // 0x800B5E08: lwc1        $f0, -0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X4);
    // 0x800B5E0C: nop

L_800B5E10:
    // 0x800B5E10: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800B5E14: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B5E18: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800B5E1C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800B5E20: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B5E24: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x800B5E28: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x800B5E2C: bc1f        L_800B5E3C
    if (!c1cs) {
        // 0x800B5E30: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_800B5E3C;
    }
    // 0x800B5E30: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B5E34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B5E38: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
L_800B5E3C:
    // 0x800B5E3C: add.d       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = ctx->f0.d + ctx->f10.d;
    // 0x800B5E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B5E44: c.le.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d <= ctx->f0.d;
    // 0x800B5E48: mov.d       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.d = ctx->f20.d;
    // 0x800B5E4C: bc1f        L_800B5E70
    if (!c1cs) {
        // 0x800B5E50: sltu        $a2, $zero, $a1
        ctx->r6 = 0 < ctx->r5 ? 1 : 0;
            goto L_800B5E70;
    }
    // 0x800B5E50: sltu        $a2, $zero, $a1
    ctx->r6 = 0 < ctx->r5 ? 1 : 0;
L_800B5E54:
    // 0x800B5E54: mov.d       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.d = ctx->f14.d;
    // 0x800B5E58: mul.d       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = MUL_D(ctx->f14.d, ctx->f18.d);
    // 0x800B5E5C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5E60: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800B5E64: nop

    // 0x800B5E68: bc1t        L_800B5E54
    if (c1cs) {
        // 0x800B5E6C: nop
    
            goto L_800B5E54;
    }
    // 0x800B5E6C: nop

L_800B5E70:
    // 0x800B5E70: bne         $a2, $zero, L_800B5E88
    if (ctx->r6 != 0) {
        // 0x800B5E74: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800B5E88;
    }
    // 0x800B5E74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B5E78: sltu        $a0, $zero, $s5
    ctx->r4 = 0 < ctx->r21 ? 1 : 0;
    // 0x800B5E7C: bne         $a0, $zero, L_800B5E88
    if (ctx->r4 != 0) {
        // 0x800B5E80: nop
    
            goto L_800B5E88;
    }
    // 0x800B5E80: nop

    // 0x800B5E84: sltu        $a0, $zero, $s6
    ctx->r4 = 0 < ctx->r22 ? 1 : 0;
L_800B5E88:
    // 0x800B5E88: bne         $s3, $zero, L_800B5E94
    if (ctx->r19 != 0) {
        // 0x800B5E8C: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_800B5E94;
    }
    // 0x800B5E8C: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x800B5E90: sltu        $v1, $zero, $fp
    ctx->r3 = 0 < ctx->r30 ? 1 : 0;
L_800B5E94:
    // 0x800B5E94: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x800B5E98: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800B5E9C: bne         $s7, $zero, L_800B5ECC
    if (ctx->r23 != 0) {
        // 0x800B5EA0: addu        $a1, $t7, $t2
        ctx->r5 = ADD32(ctx->r15, ctx->r10);
            goto L_800B5ECC;
    }
    // 0x800B5EA0: addu        $a1, $t7, $t2
    ctx->r5 = ADD32(ctx->r15, ctx->r10);
    // 0x800B5EA4: bne         $t4, $at, L_800B5ECC
    if (ctx->r12 != ctx->r1) {
        // 0x800B5EA8: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5ECC;
    }
    // 0x800B5EA8: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5EAC: beq         $v1, $zero, L_800B5ECC
    if (ctx->r3 == 0) {
        // 0x800B5EB0: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5ECC;
    }
    // 0x800B5EB0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5EB4:
    // 0x800B5EB4: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5EB8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5EBC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5EC0: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B5EC4: bne         $v1, $zero, L_800B5EB4
    if (ctx->r3 != 0) {
        // 0x800B5EC8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5EB4;
    }
    // 0x800B5EC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5ECC:
    // 0x800B5ECC: beq         $a2, $zero, L_800B5EE4
    if (ctx->r6 == 0) {
        // 0x800B5ED0: addiu       $t9, $zero, 0x2D
        ctx->r25 = ADD32(0, 0X2D);
            goto L_800B5EE4;
    }
    // 0x800B5ED0: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800B5ED4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5ED8: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B5EDC: b           L_800B5F10
    // 0x800B5EE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B5F10;
    // 0x800B5EE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5EE4:
    // 0x800B5EE4: beq         $s5, $zero, L_800B5EFC
    if (ctx->r21 == 0) {
        // 0x800B5EE8: addiu       $t8, $zero, 0x2B
        ctx->r24 = ADD32(0, 0X2B);
            goto L_800B5EFC;
    }
    // 0x800B5EE8: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x800B5EEC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5EF0: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x800B5EF4: b           L_800B5F10
    // 0x800B5EF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800B5F10;
    // 0x800B5EF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5EFC:
    // 0x800B5EFC: beq         $s6, $zero, L_800B5F10
    if (ctx->r22 == 0) {
        // 0x800B5F00: nop
    
            goto L_800B5F10;
    }
    // 0x800B5F00: nop

    // 0x800B5F04: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5F08: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B5F0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5F10:
    // 0x800B5F10: bne         $s7, $zero, L_800B5F40
    if (ctx->r23 != 0) {
        // 0x800B5F14: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_800B5F40;
    }
    // 0x800B5F14: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800B5F18: bne         $t4, $at, L_800B5F40
    if (ctx->r12 != ctx->r1) {
        // 0x800B5F1C: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5F40;
    }
    // 0x800B5F1C: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5F20: beq         $v1, $zero, L_800B5F40
    if (ctx->r3 == 0) {
        // 0x800B5F24: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B5F40;
    }
    // 0x800B5F24: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5F28:
    // 0x800B5F28: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B5F2C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B5F30: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5F34: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B5F38: bne         $v1, $zero, L_800B5F28
    if (ctx->r3 != 0) {
        // 0x800B5F3C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5F28;
    }
    // 0x800B5F3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5F40:
    // 0x800B5F40: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B5F44: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B5F48: bc1f        L_800B5F6C
    if (!c1cs) {
        // 0x800B5F4C: nop
    
            goto L_800B5F6C;
    }
    // 0x800B5F4C: nop

L_800B5F50:
    // 0x800B5F50: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x800B5F54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5F58: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B5F5C: nop

    // 0x800B5F60: bc1t        L_800B5F50
    if (c1cs) {
        // 0x800B5F64: nop
    
            goto L_800B5F50;
    }
    // 0x800B5F64: nop

    // 0x800B5F68: nop

L_800B5F6C:
    // 0x800B5F6C: div.d       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f18.d);
    // 0x800B5F70: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5F74: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5F78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5F7C: c.le.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d <= ctx->f2.d;
    // 0x800B5F80: nop

    // 0x800B5F84: bc1t        L_800B5F40
    if (c1cs) {
        // 0x800B5F88: nop
    
            goto L_800B5F40;
    }
    // 0x800B5F88: nop

    // 0x800B5F8C: bne         $s3, $zero, L_800B5F9C
    if (ctx->r19 != 0) {
        // 0x800B5F90: addiu       $t6, $zero, 0x2E
        ctx->r14 = ADD32(0, 0X2E);
            goto L_800B5F9C;
    }
    // 0x800B5F90: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800B5F94: beq         $fp, $zero, L_800B5FA8
    if (ctx->r30 == 0) {
        // 0x800B5F98: nop
    
            goto L_800B5FA8;
    }
    // 0x800B5F98: nop

L_800B5F9C:
    // 0x800B5F9C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B5FA0: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800B5FA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B5FA8:
    // 0x800B5FA8: beq         $s3, $zero, L_800B5FEC
    if (ctx->r19 == 0) {
        // 0x800B5FAC: slt         $v1, $a1, $t0
        ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B5FEC;
    }
    // 0x800B5FAC: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
L_800B5FB0:
    // 0x800B5FB0: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B5FB4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800B5FB8: bc1f        L_800B5FD8
    if (!c1cs) {
        // 0x800B5FBC: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800B5FD8;
    }
    // 0x800B5FBC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800B5FC0:
    // 0x800B5FC0: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x800B5FC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B5FC8: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800B5FCC: nop

    // 0x800B5FD0: bc1t        L_800B5FC0
    if (c1cs) {
        // 0x800B5FD4: nop
    
            goto L_800B5FC0;
    }
    // 0x800B5FD4: nop

L_800B5FD8:
    // 0x800B5FD8: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800B5FDC: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B5FE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5FE4: bgtz        $t2, L_800B5FB0
    if (SIGNED(ctx->r10) > 0) {
        // 0x800B5FE8: div.d       $f2, $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f18.d);
            goto L_800B5FB0;
    }
    // 0x800B5FE8: div.d       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f18.d);
L_800B5FEC:
    // 0x800B5FEC: beq         $s7, $zero, L_800B6014
    if (ctx->r23 == 0) {
        // 0x800B5FF0: nop
    
            goto L_800B6014;
    }
    // 0x800B5FF0: nop

    // 0x800B5FF4: beq         $v1, $zero, L_800B6014
    if (ctx->r3 == 0) {
        // 0x800B5FF8: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B6014;
    }
    // 0x800B5FF8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B5FFC:
    // 0x800B5FFC: slt         $v1, $a1, $t0
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B6000: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B6004: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6008: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B600C: bne         $v1, $zero, L_800B5FFC
    if (ctx->r3 != 0) {
        // 0x800B6010: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B5FFC;
    }
    // 0x800B6010: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B6014:
    // 0x800B6014: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B6018: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B601C: b           L_800B6378
    // 0x800B6020: nop

        goto L_800B6378;
    // 0x800B6020: nop

L_800B6024:
    // 0x800B6024: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B6028: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B602C: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B6030: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B6034: lw          $t9, -0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, -0X4);
    // 0x800B6038: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B603C: sra         $t8, $t9, 31
    ctx->r24 = S32(SIGNED(ctx->r25) >> 31);
    // 0x800B6040: sw          $t8, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r24;
    // 0x800B6044: bne         $s7, $zero, L_800B606C
    if (ctx->r23 != 0) {
        // 0x800B6048: sw          $t9, 0x18C($sp)
        MEM_W(0X18C, ctx->r29) = ctx->r25;
            goto L_800B606C;
    }
    // 0x800B6048: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800B604C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B6050: blez        $t0, L_800B6070
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B6054: lw          $t7, 0x18C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18C);
            goto L_800B6070;
    }
    // 0x800B6054: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
L_800B6058:
    // 0x800B6058: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B605C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6060: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x800B6064: bgtz        $t0, L_800B6058
    if (SIGNED(ctx->r8) > 0) {
        // 0x800B6068: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B6058;
    }
    // 0x800B6068: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B606C:
    // 0x800B606C: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
L_800B6070:
    // 0x800B6070: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6074: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B6078: beq         $s7, $zero, L_800B609C
    if (ctx->r23 == 0) {
        // 0x800B607C: sb          $t7, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r15;
            goto L_800B609C;
    }
    // 0x800B607C: sb          $t7, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r15;
    // 0x800B6080: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B6084: blez        $t0, L_800B609C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B6088: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B609C;
    }
L_800B6088:
    // 0x800B6088: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B608C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6090: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B6094: bgtz        $t0, L_800B6088
    if (SIGNED(ctx->r8) > 0) {
        // 0x800B6098: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B6088;
    }
    // 0x800B6098: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B609C:
    // 0x800B609C: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B60A0: b           L_800B6378
    // 0x800B60A4: nop

        goto L_800B6378;
    // 0x800B60A4: nop

L_800B60A8:
    // 0x800B60A8: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B60AC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B60B0: and         $t9, $s1, $at
    ctx->r25 = ctx->r17 & ctx->r1;
    // 0x800B60B4: addiu       $s1, $t9, 0x4
    ctx->r17 = ADD32(ctx->r25, 0X4);
    // 0x800B60B8: lw          $a1, -0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, -0X4);
    // 0x800B60BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B60C0: bne         $a1, $zero, L_800B60F4
    if (ctx->r5 != 0) {
        // 0x800B60C4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800B60F4;
    }
    // 0x800B60C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B60C8: beq         $t2, $at, L_800B60DC
    if (ctx->r10 == ctx->r1) {
        // 0x800B60CC: lui         $a1, 0x800F
        ctx->r5 = S32(0X800F << 16);
            goto L_800B60DC;
    }
    // 0x800B60CC: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800B60D0: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x800B60D4: bne         $at, $zero, L_800B60E8
    if (ctx->r1 != 0) {
        // 0x800B60D8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B60E8;
    }
    // 0x800B60D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800B60DC:
    // 0x800B60DC: addiu       $a1, $a1, -0x6E2C
    ctx->r5 = ADD32(ctx->r5, -0X6E2C);
    // 0x800B60E0: b           L_800B6144
    // 0x800B60E4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
        goto L_800B6144;
    // 0x800B60E4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_800B60E8:
    // 0x800B60E8: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800B60EC: b           L_800B6144
    // 0x800B60F0: addiu       $a1, $a1, -0x6E30
    ctx->r5 = ADD32(ctx->r5, -0X6E30);
        goto L_800B6144;
    // 0x800B60F0: addiu       $a1, $a1, -0x6E30
    ctx->r5 = ADD32(ctx->r5, -0X6E30);
L_800B60F4:
    // 0x800B60F4: sw          $a1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r5;
    // 0x800B60F8: sw          $t0, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r8;
    // 0x800B60FC: sw          $t1, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r9;
    // 0x800B6100: sw          $t2, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r10;
    // 0x800B6104: sw          $t3, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r11;
    // 0x800B6108: swc1        $f17, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800B610C: jal         0x800CE6FC
    // 0x800B6110: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    strlen_recomp(rdram, ctx);
        goto after_1;
    // 0x800B6110: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x800B6114: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800B6118: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800B611C: lw          $a1, 0x17C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X17C);
    // 0x800B6120: lw          $t0, 0x1A0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A0);
    // 0x800B6124: lw          $t1, 0x1AC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1AC);
    // 0x800B6128: lw          $t2, 0x19C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X19C);
    // 0x800B612C: lw          $t3, 0x1B4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1B4);
    // 0x800B6130: lwc1        $f17, 0xE0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0XE0);
    // 0x800B6134: lwc1        $f16, 0xE4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800B6138: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B613C: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800B6140: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800B6144:
    // 0x800B6144: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B6148: beq         $t2, $at, L_800B615C
    if (ctx->r10 == ctx->r1) {
        // 0x800B614C: slt         $at, $t2, $a0
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800B615C;
    }
    // 0x800B614C: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B6150: beq         $at, $zero, L_800B615C
    if (ctx->r1 == 0) {
        // 0x800B6154: nop
    
            goto L_800B615C;
    }
    // 0x800B6154: nop

    // 0x800B6158: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
L_800B615C:
    // 0x800B615C: bne         $s7, $zero, L_800B6188
    if (ctx->r23 != 0) {
        // 0x800B6160: subu        $t0, $t0, $a0
        ctx->r8 = SUB32(ctx->r8, ctx->r4);
            goto L_800B6188;
    }
    // 0x800B6160: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800B6164: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B6168: beq         $v1, $zero, L_800B6188
    if (ctx->r3 == 0) {
        // 0x800B616C: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B6188;
    }
    // 0x800B616C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B6170:
    // 0x800B6170: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B6174: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B6178: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B617C: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B6180: bne         $v1, $zero, L_800B6170
    if (ctx->r3 != 0) {
        // 0x800B6184: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B6170;
    }
    // 0x800B6184: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B6188:
    // 0x800B6188: slt         $v1, $zero, $a0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B618C: beq         $v1, $zero, L_800B61B4
    if (ctx->r3 == 0) {
        // 0x800B6190: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800B61B4;
    }
    // 0x800B6190: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_800B6194:
    // 0x800B6194: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B6198: slt         $v1, $zero, $a0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B619C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800B61A0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B61A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B61A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B61AC: bne         $v1, $zero, L_800B6194
    if (ctx->r3 != 0) {
        // 0x800B61B0: sb          $t6, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r14;
            goto L_800B6194;
    }
    // 0x800B61B0: sb          $t6, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r14;
L_800B61B4:
    // 0x800B61B4: beq         $s7, $zero, L_800B61DC
    if (ctx->r23 == 0) {
        // 0x800B61B8: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B61DC;
    }
    // 0x800B61B8: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B61BC: beq         $v1, $zero, L_800B61DC
    if (ctx->r3 == 0) {
        // 0x800B61C0: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B61DC;
    }
    // 0x800B61C0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B61C4:
    // 0x800B61C4: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B61C8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B61CC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B61D0: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B61D4: bne         $v1, $zero, L_800B61C4
    if (ctx->r3 != 0) {
        // 0x800B61D8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B61C4;
    }
    // 0x800B61D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B61DC:
    // 0x800B61DC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B61E0: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B61E4: b           L_800B6378
    // 0x800B61E8: nop

        goto L_800B6378;
    // 0x800B61E8: nop

L_800B61EC:
    // 0x800B61EC: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B61F0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B61F4: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B61F8: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B61FC: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B6200: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800B6204: beq         $v0, $zero, L_800B6240
    if (ctx->r2 == 0) {
        // 0x800B6208: addiu       $a0, $a0, -0x6E24
        ctx->r4 = ADD32(ctx->r4, -0X6E24);
            goto L_800B6240;
    }
    // 0x800B6208: addiu       $a0, $a0, -0x6E24
    ctx->r4 = ADD32(ctx->r4, -0X6E24);
    // 0x800B620C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B6210: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x800B6214: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800B6218: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B621C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800B6220: sb          $t8, 0x19A($sp)
    MEM_B(0X19A, ctx->r29) = ctx->r24;
    // 0x800B6224: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800B6228: sw          $t6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r14;
    // 0x800B622C: sw          $v0, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r2;
    // 0x800B6230: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800B6234: addiu       $s3, $zero, 0x78
    ctx->r19 = ADD32(0, 0X78);
    // 0x800B6238: b           L_800B55B8
    // 0x800B623C: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
        goto L_800B55B8;
    // 0x800B623C: addiu       $ra, $sp, 0x17B
    ctx->r31 = ADD32(ctx->r29, 0X17B);
L_800B6240:
    // 0x800B6240: bne         $s7, $zero, L_800B626C
    if (ctx->r23 != 0) {
        // 0x800B6244: addiu       $t0, $t0, -0x5
        ctx->r8 = ADD32(ctx->r8, -0X5);
            goto L_800B626C;
    }
    // 0x800B6244: addiu       $t0, $t0, -0x5
    ctx->r8 = ADD32(ctx->r8, -0X5);
    // 0x800B6248: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B624C: beq         $v1, $zero, L_800B626C
    if (ctx->r3 == 0) {
        // 0x800B6250: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B626C;
    }
    // 0x800B6250: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B6254:
    // 0x800B6254: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B6258: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B625C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6260: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B6264: bne         $v1, $zero, L_800B6254
    if (ctx->r3 != 0) {
        // 0x800B6268: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B6254;
    }
    // 0x800B6268: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B626C:
    // 0x800B626C: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800B6270: lbu         $t9, -0x6E24($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X6E24);
    // 0x800B6274: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800B6278: beq         $t9, $zero, L_800B62A0
    if (ctx->r25 == 0) {
        // 0x800B627C: addiu       $t8, $t8, -0x6E24
        ctx->r24 = ADD32(ctx->r24, -0X6E24);
            goto L_800B62A0;
    }
    // 0x800B627C: addiu       $t8, $t8, -0x6E24
    ctx->r24 = ADD32(ctx->r24, -0X6E24);
    // 0x800B6280: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800B6284: nop

L_800B6288:
    // 0x800B6288: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x800B628C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x800B6290: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6294: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B6298: bne         $v0, $zero, L_800B6288
    if (ctx->r2 != 0) {
        // 0x800B629C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800B6288;
    }
    // 0x800B629C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800B62A0:
    // 0x800B62A0: beq         $s7, $zero, L_800B62C8
    if (ctx->r23 == 0) {
        // 0x800B62A4: slt         $v1, $zero, $t0
        ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800B62C8;
    }
    // 0x800B62A4: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B62A8: beq         $v1, $zero, L_800B62C8
    if (ctx->r3 == 0) {
        // 0x800B62AC: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_800B62C8;
    }
    // 0x800B62AC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800B62B0:
    // 0x800B62B0: slt         $v1, $zero, $t0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B62B4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800B62B8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B62BC: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x800B62C0: bne         $v1, $zero, L_800B62B0
    if (ctx->r3 != 0) {
        // 0x800B62C4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800B62B0;
    }
    // 0x800B62C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B62C8:
    // 0x800B62C8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B62CC: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B62D0: b           L_800B6378
    // 0x800B62D4: nop

        goto L_800B6378;
    // 0x800B62D4: nop

L_800B62D8:
    // 0x800B62D8: beq         $a0, $zero, L_800B6304
    if (ctx->r4 == 0) {
        // 0x800B62DC: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800B6304;
    }
    // 0x800B62DC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B62E0: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B62E4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B62E8: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B62EC: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B62F0: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B62F4: sra         $t8, $t1, 31
    ctx->r24 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800B62F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B62FC: b           L_800B6360
    // 0x800B6300: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
        goto L_800B6360;
    // 0x800B6300: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_800B6304:
    // 0x800B6304: beq         $a1, $zero, L_800B6324
    if (ctx->r5 == 0) {
        // 0x800B6308: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B6324;
    }
    // 0x800B6308: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B630C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B6310: and         $t7, $s1, $at
    ctx->r15 = ctx->r17 & ctx->r1;
    // 0x800B6314: addiu       $s1, $t7, 0x4
    ctx->r17 = ADD32(ctx->r15, 0X4);
    // 0x800B6318: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B631C: b           L_800B6360
    // 0x800B6320: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_800B6360;
    // 0x800B6320: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800B6324:
    // 0x800B6324: bne         $a2, $zero, L_800B6348
    if (ctx->r6 != 0) {
        // 0x800B6328: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800B6348;
    }
    // 0x800B6328: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B632C: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B6330: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800B6334: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x800B6338: addiu       $s1, $t6, 0x4
    ctx->r17 = ADD32(ctx->r14, 0X4);
    // 0x800B633C: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B6340: b           L_800B6360
    // 0x800B6344: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_800B6360;
    // 0x800B6344: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800B6348:
    // 0x800B6348: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800B634C: and         $t8, $s1, $at
    ctx->r24 = ctx->r17 & ctx->r1;
    // 0x800B6350: addiu       $s1, $t8, 0x4
    ctx->r17 = ADD32(ctx->r24, 0X4);
    // 0x800B6354: lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X4);
    // 0x800B6358: nop

    // 0x800B635C: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_800B6360:
    // 0x800B6360: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B6364: b           L_800B6378
    // 0x800B6368: nop

        goto L_800B6378;
    // 0x800B6368: nop

L_800B636C:
    // 0x800B636C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B6370: lw          $v1, 0x3480($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3480);
    // 0x800B6374: nop

L_800B6378:
    // 0x800B6378: beq         $v1, $zero, L_800B638C
    if (ctx->r3 == 0) {
        // 0x800B637C: addiu       $t9, $zero, 0x83
        ctx->r25 = ADD32(0, 0X83);
            goto L_800B638C;
    }
    // 0x800B637C: addiu       $t9, $zero, 0x83
    ctx->r25 = ADD32(0, 0X83);
    // 0x800B6380: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B6384: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800B6388: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800B638C:
    // 0x800B638C: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
L_800B6390:
    // 0x800B6390: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x800B6394: bne         $v1, $zero, L_800B5020
    if (ctx->r3 != 0) {
        // 0x800B6398: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B5020;
    }
    // 0x800B6398: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B639C: swc1        $f17, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800B63A0: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    // 0x800B63A4: sw          $s4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r20;
L_800B63A8:
    // 0x800B63A8: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800B63AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800B63B0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800B63B4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800B63B8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800B63BC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800B63C0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800B63C4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800B63C8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800B63CC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800B63D0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B63D4: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B63D8: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800B63DC: addiu       $sp, $sp, 0x1B8
    ctx->r29 = ADD32(ctx->r29, 0X1B8);
    // 0x800B63E0: jr          $ra
    // 0x800B63E4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800B63E4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void menu_imagegroup_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CF9C: jr          $ra
    // 0x8009CFA0: nop

    return;
    // 0x8009CFA0: nop

;}
RECOMP_FUNC void decrease_emitter_opacity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4C1C: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x800B4C20: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x800B4C24: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x800B4C28: lh          $t8, 0xA($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XA);
    // 0x800B4C2C: sll         $t6, $a3, 8
    ctx->r14 = S32(ctx->r7 << 8);
    // 0x800B4C30: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800B4C34: subu        $v0, $t9, $a2
    ctx->r2 = SUB32(ctx->r25, ctx->r6);
    // 0x800B4C38: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B4C3C: beq         $at, $zero, L_800B4C4C
    if (ctx->r1 == 0) {
        // 0x800B4C40: nop
    
            goto L_800B4C4C;
    }
    // 0x800B4C40: nop

    // 0x800B4C44: b           L_800B4C50
    // 0x800B4C48: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
        goto L_800B4C50;
    // 0x800B4C48: sh          $t6, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r14;
L_800B4C4C:
    // 0x800B4C4C: sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
L_800B4C50:
    // 0x800B4C50: lw          $t1, 0x6C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X6C);
    // 0x800B4C54: nop

    // 0x800B4C58: addu        $t0, $t1, $v1
    ctx->r8 = ADD32(ctx->r9, ctx->r3);
    // 0x800B4C5C: lh          $t2, 0x4($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X4);
    // 0x800B4C60: nop

    // 0x800B4C64: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x800B4C68: jr          $ra
    // 0x800B4C6C: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    return;
    // 0x800B4C6C: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
;}
RECOMP_FUNC void hud_race_finish_multiplayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A679C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800A67A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A67A4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800A67A8: jal         0x8006BFD8
    // 0x800A67AC: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    level_type(rdram, ctx);
        goto after_0;
    // 0x800A67AC: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A67B0: jal         0x8009F1C4
    // 0x800A67B4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    is_in_two_player_adventure(rdram, ctx);
        goto after_1;
    // 0x800A67B4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A67B8: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A67BC: beq         $v0, $zero, L_800A68E4
    if (ctx->r2 == 0) {
        // 0x800A67C0: nop
    
            goto L_800A68E4;
    }
    // 0x800A67C0: nop

    // 0x800A67C4: jal         0x8006ECF0
    // 0x800A67C8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    is_postrace_viewport_active(rdram, ctx);
        goto after_2;
    // 0x800A67C8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_2:
    // 0x800A67CC: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A67D0: beq         $v0, $zero, L_800A68E4
    if (ctx->r2 == 0) {
        // 0x800A67D4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800A68E4;
    }
    // 0x800A67D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A67D8: lbu         $t6, 0x7749($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7749);
    // 0x800A67DC: nop

    // 0x800A67E0: bne         $t6, $zero, L_800A68E4
    if (ctx->r14 != 0) {
        // 0x800A67E4: nop
    
            goto L_800A68E4;
    }
    // 0x800A67E4: nop

    // 0x800A67E8: jal         0x8000E184
    // 0x800A67EC: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    is_player_two_in_control(rdram, ctx);
        goto after_3;
    // 0x800A67EC: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_3:
    // 0x800A67F0: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A67F4: beq         $v0, $zero, L_800A6864
    if (ctx->r2 == 0) {
        // 0x800A67F8: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800A6864;
    }
    // 0x800A67F8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A67FC: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A6800: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6804: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x800A6808: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A680C: lwc1        $f4, 0x5F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5F0);
    // 0x800A6810: nop

    // 0x800A6814: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A6818: swc1        $f6, 0x5F0($v0)
    MEM_W(0X5F0, ctx->r2) = ctx->f6.u32l;
    // 0x800A681C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6820: nop

    // 0x800A6824: lwc1        $f8, 0x610($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X610);
    // 0x800A6828: nop

    // 0x800A682C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A6830: swc1        $f10, 0x610($v0)
    MEM_W(0X610, ctx->r2) = ctx->f10.u32l;
    // 0x800A6834: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6838: nop

    // 0x800A683C: lwc1        $f4, 0x170($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A6840: nop

    // 0x800A6844: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A6848: swc1        $f6, 0x170($v0)
    MEM_W(0X170, ctx->r2) = ctx->f6.u32l;
    // 0x800A684C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6850: nop

    // 0x800A6854: lwc1        $f8, 0x2F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A6858: nop

    // 0x800A685C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A6860: swc1        $f10, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = ctx->f10.u32l;
L_800A6864:
    // 0x800A6864: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A6868: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A686C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6870: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800A6874: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6878: lwc1        $f4, 0x5F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5F0);
    // 0x800A687C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A6880: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A6884: addiu       $v1, $v1, 0x2CF0
    ctx->r3 = ADD32(ctx->r3, 0X2CF0);
    // 0x800A6888: swc1        $f6, 0x5F0($v0)
    MEM_W(0X5F0, ctx->r2) = ctx->f6.u32l;
    // 0x800A688C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6890: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A6894: lwc1        $f8, 0x610($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X610);
    // 0x800A6898: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A689C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A68A0: swc1        $f10, 0x610($v0)
    MEM_W(0X610, ctx->r2) = ctx->f10.u32l;
    // 0x800A68A4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A68A8: nop

    // 0x800A68AC: lwc1        $f4, 0x170($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A68B0: nop

    // 0x800A68B4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A68B8: swc1        $f6, 0x170($v0)
    MEM_W(0X170, ctx->r2) = ctx->f6.u32l;
    // 0x800A68BC: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A68C0: nop

    // 0x800A68C4: lwc1        $f8, 0x2F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A68C8: nop

    // 0x800A68CC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A68D0: swc1        $f10, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = ctx->f10.u32l;
    // 0x800A68D4: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800A68D8: nop

    // 0x800A68DC: sb          $t7, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r15;
    // 0x800A68E0: sb          $t8, 0x7749($at)
    MEM_B(0X7749, ctx->r1) = ctx->r24;
L_800A68E4:
    // 0x800A68E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A68E8: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A68EC: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A68F0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A68F4: lbu         $t9, 0x5FA($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5FA);
    // 0x800A68F8: addiu       $v1, $v1, 0x2CF0
    ctx->r3 = ADD32(ctx->r3, 0X2CF0);
    // 0x800A68FC: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x800A6900: beq         $at, $zero, L_800A72E4
    if (ctx->r1 == 0) {
        // 0x800A6904: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800A72E4;
    }
    // 0x800A6904: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800A6908: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A690C: addu        $at, $at, $t9
    gpr jr_addend_800A6918 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800A6910: lw          $t9, -0x733C($at)
    ctx->r25 = ADD32(ctx->r1, -0X733C);
    // 0x800A6914: nop

    // 0x800A6918: jr          $t9
    // 0x800A691C: nop

    switch (jr_addend_800A6918 >> 2) {
        case 0: goto L_800A6920; break;
        case 1: goto L_800A6E64; break;
        case 2: goto L_800A7114; break;
        case 3: goto L_800A71EC; break;
        case 4: goto L_800A72B0; break;
        default: switch_error(__func__, 0x800A6918, 0x800E8CC4);
    }
    // 0x800A691C: nop

L_800A6920:
    // 0x800A6920: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800A6924: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x800A6928: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x800A692C: bne         $t3, $zero, L_800A6964
    if (ctx->r11 != 0) {
        // 0x800A6930: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800A6964;
    }
    // 0x800A6930: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A6934: sb          $t4, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r12;
    // 0x800A6938: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800A693C: lh          $t5, 0x0($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X0);
    // 0x800A6940: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800A6944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A6948: jal         0x80001D04
    // 0x800A694C: sb          $t5, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r13;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800A694C: sb          $t5, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r13;
    after_4:
    // 0x800A6950: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A6954: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A6958: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A695C: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6960: nop

L_800A6964:
    // 0x800A6964: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A6968: lw          $v1, 0x72CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X72CC);
    // 0x800A696C: addiu       $t6, $zero, -0x14
    ctx->r14 = ADD32(0, -0X14);
    // 0x800A6970: beq         $v1, $zero, L_800A698C
    if (ctx->r3 == 0) {
        // 0x800A6974: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_800A698C;
    }
    // 0x800A6974: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A6978: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A697C: beq         $v1, $t0, L_800A6990
    if (ctx->r3 == ctx->r8) {
        // 0x800A6980: nop
    
            goto L_800A6990;
    }
    // 0x800A6980: nop

    // 0x800A6984: b           L_800A69AC
    // 0x800A6988: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_800A69AC;
    // 0x800A6988: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_800A698C:
    // 0x800A698C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800A6990:
    // 0x800A6990: sb          $t6, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r14;
    // 0x800A6994: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A6998: addiu       $v1, $zero, -0xF
    ctx->r3 = ADD32(0, -0XF);
    // 0x800A699C: sb          $v1, 0x17D($t7)
    MEM_B(0X17D, ctx->r15) = ctx->r3;
    // 0x800A69A0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A69A4: b           L_800A6A00
    // 0x800A69A8: sb          $v1, 0x2FD($t8)
    MEM_B(0X2FD, ctx->r24) = ctx->r3;
        goto L_800A6A00;
    // 0x800A69A8: sb          $v1, 0x2FD($t8)
    MEM_B(0X2FD, ctx->r24) = ctx->r3;
L_800A69AC:
    // 0x800A69AC: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x800A69B0: addiu       $t9, $zero, -0x5A
    ctx->r25 = ADD32(0, -0X5A);
    // 0x800A69B4: beq         $v1, $zero, L_800A69C4
    if (ctx->r3 == 0) {
        // 0x800A69B8: nop
    
            goto L_800A69C4;
    }
    // 0x800A69B8: nop

    // 0x800A69BC: bne         $a2, $v1, L_800A69E4
    if (ctx->r6 != ctx->r3) {
        // 0x800A69C0: addiu       $t4, $zero, 0x37
        ctx->r12 = ADD32(0, 0X37);
            goto L_800A69E4;
    }
    // 0x800A69C0: addiu       $t4, $zero, 0x37
    ctx->r12 = ADD32(0, 0X37);
L_800A69C4:
    // 0x800A69C4: sb          $t9, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r25;
    // 0x800A69C8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800A69CC: addiu       $v1, $zero, -0x55
    ctx->r3 = ADD32(0, -0X55);
    // 0x800A69D0: sb          $v1, 0x17D($t2)
    MEM_B(0X17D, ctx->r10) = ctx->r3;
    // 0x800A69D4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800A69D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A69DC: b           L_800A6A00
    // 0x800A69E0: sb          $v1, 0x2FD($t3)
    MEM_B(0X2FD, ctx->r11) = ctx->r3;
        goto L_800A6A00;
    // 0x800A69E0: sb          $v1, 0x2FD($t3)
    MEM_B(0X2FD, ctx->r11) = ctx->r3;
L_800A69E4:
    // 0x800A69E4: sb          $t4, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r12;
    // 0x800A69E8: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A69EC: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x800A69F0: sb          $v1, 0x17D($t5)
    MEM_B(0X17D, ctx->r13) = ctx->r3;
    // 0x800A69F4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A69F8: nop

    // 0x800A69FC: sb          $v1, 0x2FD($t6)
    MEM_B(0X2FD, ctx->r14) = ctx->r3;
L_800A6A00:
    // 0x800A6A00: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x800A6A04: addiu       $a0, $a0, 0x300
    ctx->r4 = ADD32(ctx->r4, 0X300);
    // 0x800A6A08: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A6A0C: nop

    // 0x800A6A10: bne         $t7, $zero, L_800A6A60
    if (ctx->r15 != 0) {
        // 0x800A6A14: nop
    
            goto L_800A6A60;
    }
    // 0x800A6A14: nop

    // 0x800A6A18: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A1C: nop

    // 0x800A6A20: lb          $t8, 0x5FD($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5FD);
    // 0x800A6A24: nop

    // 0x800A6A28: addiu       $t9, $t8, -0x4
    ctx->r25 = ADD32(ctx->r24, -0X4);
    // 0x800A6A2C: sb          $t9, 0x5FD($v0)
    MEM_B(0X5FD, ctx->r2) = ctx->r25;
    // 0x800A6A30: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A34: nop

    // 0x800A6A38: lb          $t2, 0x17D($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X17D);
    // 0x800A6A3C: nop

    // 0x800A6A40: addiu       $t3, $t2, -0x4
    ctx->r11 = ADD32(ctx->r10, -0X4);
    // 0x800A6A44: sb          $t3, 0x17D($v0)
    MEM_B(0X17D, ctx->r2) = ctx->r11;
    // 0x800A6A48: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A4C: nop

    // 0x800A6A50: lb          $t4, 0x2FD($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X2FD);
    // 0x800A6A54: nop

    // 0x800A6A58: addiu       $t5, $t4, -0x4
    ctx->r13 = ADD32(ctx->r12, -0X4);
    // 0x800A6A5C: sb          $t5, 0x2FD($v0)
    MEM_B(0X2FD, ctx->r2) = ctx->r13;
L_800A6A60:
    // 0x800A6A60: lh          $v0, 0x1AC($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X1AC);
    // 0x800A6A64: nop

    // 0x800A6A68: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800A6A6C: beq         $at, $zero, L_800A6A80
    if (ctx->r1 == 0) {
        // 0x800A6A70: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_800A6A80;
    }
    // 0x800A6A70: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800A6A74: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A78: b           L_800A6A8C
    // 0x800A6A7C: sh          $t6, 0x618($t7)
    MEM_H(0X618, ctx->r15) = ctx->r14;
        goto L_800A6A8C;
    // 0x800A6A7C: sh          $t6, 0x618($t7)
    MEM_H(0X618, ctx->r15) = ctx->r14;
L_800A6A80:
    // 0x800A6A80: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A84: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800A6A88: sh          $t8, 0x618($t9)
    MEM_H(0X618, ctx->r25) = ctx->r24;
L_800A6A8C:
    // 0x800A6A8C: lh          $t2, 0x1AC($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X1AC);
    // 0x800A6A90: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A6A94: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800A6A98: sh          $t3, 0x5F8($t4)
    MEM_H(0X5F8, ctx->r12) = ctx->r11;
    // 0x800A6A9C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A6AA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6AA4: sb          $t0, 0x5FA($t5)
    MEM_B(0X5FA, ctx->r13) = ctx->r8;
    // 0x800A6AA8: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A6AAC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800A6AB0: beq         $v0, $a2, L_800A6AD4
    if (ctx->r2 == ctx->r6) {
        // 0x800A6AB4: nop
    
            goto L_800A6AD4;
    }
    // 0x800A6AB4: nop

    // 0x800A6AB8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A6ABC: beq         $v0, $at, L_800A6C10
    if (ctx->r2 == ctx->r1) {
        // 0x800A6AC0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A6C10;
    }
    // 0x800A6AC0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A6AC4: beq         $v0, $at, L_800A6C10
    if (ctx->r2 == ctx->r1) {
        // 0x800A6AC8: nop
    
            goto L_800A6C10;
    }
    // 0x800A6AC8: nop

    // 0x800A6ACC: b           L_800A6D70
    // 0x800A6AD0: nop

        goto L_800A6D70;
    // 0x800A6AD0: nop

L_800A6AD4:
    // 0x800A6AD4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A6AD8: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x800A6ADC: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A6AE0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A6AE4: bne         $v1, $zero, L_800A6B04
    if (ctx->r3 != 0) {
        // 0x800A6AE8: lui         $at, 0x4337
        ctx->r1 = S32(0X4337 << 16);
            goto L_800A6B04;
    }
    // 0x800A6AE8: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x800A6AEC: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x800A6AF0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6AF4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800A6AF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A6AFC: b           L_800A6B18
    // 0x800A6B00: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
        goto L_800A6B18;
    // 0x800A6B00: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
L_800A6B04:
    // 0x800A6B04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6B08: lui         $at, 0x4346
    ctx->r1 = S32(0X4346 << 16);
    // 0x800A6B0C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A6B10: nop

    // 0x800A6B14: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
L_800A6B18:
    // 0x800A6B18: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A6B1C: bne         $t6, $zero, L_800A6BD4
    if (ctx->r14 != 0) {
        // 0x800A6B20: nop
    
            goto L_800A6BD4;
    }
    // 0x800A6B20: nop

    // 0x800A6B24: lwc1        $f17, -0x7328($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X7328);
    // 0x800A6B28: lwc1        $f16, -0x7324($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7324);
    // 0x800A6B2C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800A6B30: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800A6B34: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A6B38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A6B3C: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800A6B40: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800A6B44: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800A6B48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A6B4C: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800A6B50: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A6B54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A6B58: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x800A6B5C: sub.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800A6B60: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800A6B64: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A6B68: nop

    // 0x800A6B6C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A6B70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6B74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6B78: nop

    // 0x800A6B7C: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800A6B80: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A6B84: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A6B88: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800A6B8C: nop

    // 0x800A6B90: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A6B94: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A6B98: nop

    // 0x800A6B9C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A6BA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6BA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6BA8: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800A6BAC: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800A6BB0: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800A6BB4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A6BB8: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800A6BBC: bne         $v1, $zero, L_800A6BD4
    if (ctx->r3 != 0) {
        // 0x800A6BC0: cvt.s.w     $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800A6BD4;
    }
    // 0x800A6BC0: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A6BC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A6BC8: nop

    // 0x800A6BCC: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800A6BD0: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
L_800A6BD4:
    // 0x800A6BD4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800A6BD8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6BDC: swc1        $f12, 0x16C($t3)
    MEM_W(0X16C, ctx->r11) = ctx->f12.u32l;
    // 0x800A6BE0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A6BE4: nop

    // 0x800A6BE8: swc1        $f0, 0x170($t4)
    MEM_W(0X170, ctx->r12) = ctx->f0.u32l;
    // 0x800A6BEC: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A6BF0: nop

    // 0x800A6BF4: swc1        $f14, 0x2EC($t5)
    MEM_W(0X2EC, ctx->r13) = ctx->f14.u32l;
    // 0x800A6BF8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A6BFC: nop

    // 0x800A6C00: swc1        $f2, 0x2F0($t6)
    MEM_W(0X2F0, ctx->r14) = ctx->f2.u32l;
    // 0x800A6C04: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A6C08: b           L_800A6D70
    // 0x800A6C0C: nop

        goto L_800A6D70;
    // 0x800A6C0C: nop

L_800A6C10:
    // 0x800A6C10: lh          $v1, 0x0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X0);
    // 0x800A6C14: nop

    // 0x800A6C18: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800A6C1C: beq         $at, $zero, L_800A6C38
    if (ctx->r1 == 0) {
        // 0x800A6C20: lui         $at, 0x4296
        ctx->r1 = S32(0X4296 << 16);
            goto L_800A6C38;
    }
    // 0x800A6C20: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x800A6C24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6C28: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800A6C2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A6C30: b           L_800A6C4C
    // 0x800A6C34: nop

        goto L_800A6C4C;
    // 0x800A6C34: nop

L_800A6C38:
    // 0x800A6C38: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x800A6C3C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6C40: lui         $at, 0x4346
    ctx->r1 = S32(0X4346 << 16);
    // 0x800A6C44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A6C48: nop

L_800A6C4C:
    // 0x800A6C4C: beq         $v1, $zero, L_800A6C5C
    if (ctx->r3 == 0) {
        // 0x800A6C50: lui         $at, 0x428C
        ctx->r1 = S32(0X428C << 16);
            goto L_800A6C5C;
    }
    // 0x800A6C50: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800A6C54: bne         $a2, $v1, L_800A6C70
    if (ctx->r6 != ctx->r3) {
        // 0x800A6C58: nop
    
            goto L_800A6C70;
    }
    // 0x800A6C58: nop

L_800A6C5C:
    // 0x800A6C5C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A6C60: lui         $at, 0xC366
    ctx->r1 = S32(0XC366 << 16);
    // 0x800A6C64: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A6C68: b           L_800A6C88
    // 0x800A6C6C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
        goto L_800A6C88;
    // 0x800A6C6C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_800A6C70:
    // 0x800A6C70: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x800A6C74: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A6C78: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x800A6C7C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A6C80: nop

    // 0x800A6C84: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_800A6C88:
    // 0x800A6C88: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A6C8C: bne         $t7, $zero, L_800A6D38
    if (ctx->r15 != 0) {
        // 0x800A6C90: nop
    
            goto L_800A6D38;
    }
    // 0x800A6C90: nop

    // 0x800A6C94: lwc1        $f17, -0x7320($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X7320);
    // 0x800A6C98: lwc1        $f16, -0x731C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X731C);
    // 0x800A6C9C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800A6CA0: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800A6CA4: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800A6CA8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A6CAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A6CB0: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800A6CB4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800A6CB8: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x800A6CBC: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x800A6CC0: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x800A6CC4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A6CC8: nop

    // 0x800A6CCC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A6CD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6CD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6CD8: nop

    // 0x800A6CDC: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800A6CE0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800A6CE4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A6CE8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800A6CEC: nop

    // 0x800A6CF0: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A6CF4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A6CF8: nop

    // 0x800A6CFC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A6D00: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6D04: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6D08: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800A6D0C: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800A6D10: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800A6D14: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A6D18: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800A6D1C: beq         $at, $zero, L_800A6D38
    if (ctx->r1 == 0) {
        // 0x800A6D20: cvt.s.w     $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800A6D38;
    }
    // 0x800A6D20: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A6D24: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800A6D28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A6D2C: nop

    // 0x800A6D30: sub.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800A6D34: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
L_800A6D38:
    // 0x800A6D38: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6D40: swc1        $f12, 0x16C($t4)
    MEM_W(0X16C, ctx->r12) = ctx->f12.u32l;
    // 0x800A6D44: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D48: nop

    // 0x800A6D4C: swc1        $f0, 0x170($t5)
    MEM_W(0X170, ctx->r13) = ctx->f0.u32l;
    // 0x800A6D50: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D54: nop

    // 0x800A6D58: swc1        $f14, 0x2EC($t6)
    MEM_W(0X2EC, ctx->r14) = ctx->f14.u32l;
    // 0x800A6D5C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A6D60: nop

    // 0x800A6D64: swc1        $f2, 0x2F0($t7)
    MEM_W(0X2F0, ctx->r15) = ctx->f2.u32l;
    // 0x800A6D68: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A6D6C: nop

L_800A6D70:
    // 0x800A6D70: beq         $t0, $v0, L_800A72F0
    if (ctx->r8 == ctx->r2) {
        // 0x800A6D74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A72F0;
    }
    // 0x800A6D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6D78: jal         0x8006BFF0
    // 0x800A6D7C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    level_header(rdram, ctx);
        goto after_5;
    // 0x800A6D7C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_5:
    // 0x800A6D80: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A6D84: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A6D88: lw          $t8, 0x128($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X128);
    // 0x800A6D8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A6D90: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800A6D94: lb          $t9, 0x4B($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X4B);
    // 0x800A6D98: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800A6D9C: blez        $t9, L_800A6DD8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800A6DA0: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_800A6DD8;
    }
    // 0x800A6DA0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800A6DA4: lb          $a1, 0x4B($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X4B);
    // 0x800A6DA8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_800A6DAC:
    // 0x800A6DAC: lw          $v0, 0x128($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X128);
    // 0x800A6DB0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800A6DB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A6DB8: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800A6DBC: beq         $at, $zero, L_800A6DC8
    if (ctx->r1 == 0) {
        // 0x800A6DC0: addu        $t0, $t0, $v0
        ctx->r8 = ADD32(ctx->r8, ctx->r2);
            goto L_800A6DC8;
    }
    // 0x800A6DC0: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800A6DC4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
L_800A6DC8:
    // 0x800A6DC8: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800A6DCC: bne         $at, $zero, L_800A6DAC
    if (ctx->r1 != 0) {
        // 0x800A6DD0: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A6DAC;
    }
    // 0x800A6DD0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A6DD4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_800A6DD8:
    // 0x800A6DD8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800A6DDC: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800A6DE0: jal         0x800597E0
    // 0x800A6DE4: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    get_timestamp_from_frames(rdram, ctx);
        goto after_6;
    // 0x800A6DE4: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    after_6:
    // 0x800A6DE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A6DEC: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A6DF0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A6DF4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800A6DF8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800A6DFC: sb          $t3, 0x2FA($t4)
    MEM_B(0X2FA, ctx->r12) = ctx->r11;
    // 0x800A6E00: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A6E04: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800A6E08: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800A6E0C: sb          $t5, 0x2FB($t6)
    MEM_B(0X2FB, ctx->r14) = ctx->r13;
    // 0x800A6E10: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A6E14: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800A6E18: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800A6E1C: sb          $t7, 0x2FC($t8)
    MEM_B(0X2FC, ctx->r24) = ctx->r15;
    // 0x800A6E20: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800A6E24: jal         0x800597E0
    // 0x800A6E28: nop

    get_timestamp_from_frames(rdram, ctx);
        goto after_7;
    // 0x800A6E28: nop

    after_7:
    // 0x800A6E2C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A6E30: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A6E34: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800A6E38: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800A6E3C: nop

    // 0x800A6E40: sb          $t9, 0x17A($t2)
    MEM_B(0X17A, ctx->r10) = ctx->r25;
    // 0x800A6E44: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800A6E48: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800A6E4C: nop

    // 0x800A6E50: sb          $t3, 0x17B($t4)
    MEM_B(0X17B, ctx->r12) = ctx->r11;
    // 0x800A6E54: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A6E58: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800A6E5C: b           L_800A72EC
    // 0x800A6E60: sb          $t5, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r13;
        goto L_800A72EC;
    // 0x800A6E60: sb          $t5, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r13;
L_800A6E64:
    // 0x800A6E64: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800A6E68: lb          $a1, 0x5FD($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X5FD);
    // 0x800A6E6C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A6E70: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A6E74: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A6E78: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A6E7C: subu        $t8, $a1, $t7
    ctx->r24 = SUB32(ctx->r5, ctx->r15);
    // 0x800A6E80: addiu       $t9, $t8, 0xA0
    ctx->r25 = ADD32(ctx->r24, 0XA0);
    // 0x800A6E84: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800A6E88: lwc1        $f2, 0x5EC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X5EC);
    // 0x800A6E8C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A6E90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A6E94: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A6E98: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800A6E9C: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x800A6EA0: bc1f        L_800A6EB0
    if (!c1cs) {
        // 0x800A6EA4: addiu       $t2, $a1, 0xA0
        ctx->r10 = ADD32(ctx->r5, 0XA0);
            goto L_800A6EB0;
    }
    // 0x800A6EA4: addiu       $t2, $a1, 0xA0
    ctx->r10 = ADD32(ctx->r5, 0XA0);
    // 0x800A6EA8: b           L_800A6EE8
    // 0x800A6EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800A6EE8;
    // 0x800A6EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800A6EB0:
    // 0x800A6EB0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800A6EB4: nop

    // 0x800A6EB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A6EBC: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800A6EC0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A6EC4: nop

    // 0x800A6EC8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A6ECC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6ED0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6ED4: nop

    // 0x800A6ED8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A6EDC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A6EE0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A6EE4: nop

L_800A6EE8:
    // 0x800A6EE8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A6EEC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A6EF0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A6EF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A6EF8: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800A6EFC: swc1        $f6, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = ctx->f6.u32l;
    // 0x800A6F00: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6F04: nop

    // 0x800A6F08: lwc1        $f8, 0x60C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X60C);
    // 0x800A6F0C: nop

    // 0x800A6F10: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A6F14: swc1        $f10, 0x60C($v0)
    MEM_W(0X60C, ctx->r2) = ctx->f10.u32l;
    // 0x800A6F18: lbu         $t4, 0x72F7($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X72F7);
    // 0x800A6F1C: nop

    // 0x800A6F20: beq         $t0, $t4, L_800A7038
    if (ctx->r8 == ctx->r12) {
        // 0x800A6F24: nop
    
            goto L_800A7038;
    }
    // 0x800A6F24: nop

    // 0x800A6F28: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6F2C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800A6F30: lb          $a1, 0x17D($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X17D);
    // 0x800A6F34: lwc1        $f0, 0x16C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A6F38: addu        $t5, $a1, $a0
    ctx->r13 = ADD32(ctx->r5, ctx->r4);
    // 0x800A6F3C: addiu       $t6, $t5, 0xA0
    ctx->r14 = ADD32(ctx->r13, 0XA0);
    // 0x800A6F40: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800A6F44: addiu       $t7, $a1, 0xA0
    ctx->r15 = ADD32(ctx->r5, 0XA0);
    // 0x800A6F48: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A6F4C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800A6F50: nop

    // 0x800A6F54: bc1f        L_800A6F64
    if (!c1cs) {
        // 0x800A6F58: nop
    
            goto L_800A6F64;
    }
    // 0x800A6F58: nop

    // 0x800A6F5C: b           L_800A6F9C
    // 0x800A6F60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800A6F9C;
    // 0x800A6F60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800A6F64:
    // 0x800A6F64: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A6F68: nop

    // 0x800A6F6C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A6F70: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A6F74: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A6F78: nop

    // 0x800A6F7C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A6F80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6F84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6F88: nop

    // 0x800A6F8C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A6F90: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A6F94: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800A6F98: nop

L_800A6F9C:
    // 0x800A6F9C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A6FA0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800A6FA4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A6FA8: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A6FAC: swc1        $f4, 0x16C($v0)
    MEM_W(0X16C, ctx->r2) = ctx->f4.u32l;
    // 0x800A6FB0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A6FB4: nop

    // 0x800A6FB8: lb          $a1, 0x2FD($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X2FD);
    // 0x800A6FBC: lwc1        $f2, 0x2EC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A6FC0: subu        $t9, $a1, $a0
    ctx->r25 = SUB32(ctx->r5, ctx->r4);
    // 0x800A6FC4: addiu       $t2, $t9, 0xA0
    ctx->r10 = ADD32(ctx->r25, 0XA0);
    // 0x800A6FC8: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800A6FCC: addiu       $t3, $a1, 0xA0
    ctx->r11 = ADD32(ctx->r5, 0XA0);
    // 0x800A6FD0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A6FD4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800A6FD8: nop

    // 0x800A6FDC: bc1f        L_800A6FEC
    if (!c1cs) {
        // 0x800A6FE0: nop
    
            goto L_800A6FEC;
    }
    // 0x800A6FE0: nop

    // 0x800A6FE4: b           L_800A7024
    // 0x800A6FE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800A7024;
    // 0x800A6FE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800A6FEC:
    // 0x800A6FEC: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800A6FF0: nop

    // 0x800A6FF4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A6FF8: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A6FFC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A7000: nop

    // 0x800A7004: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A7008: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A700C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7010: nop

    // 0x800A7014: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A7018: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A701C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800A7020: nop

L_800A7024:
    // 0x800A7024: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A7028: nop

    // 0x800A702C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A7030: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800A7034: swc1        $f6, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = ctx->f6.u32l;
L_800A7038:
    // 0x800A7038: beq         $a2, $zero, L_800A7104
    if (ctx->r6 == 0) {
        // 0x800A703C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A7104;
    }
    // 0x800A703C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7040: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A7044: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A7048: sb          $a2, 0x5FA($t5)
    MEM_B(0X5FA, ctx->r13) = ctx->r6;
    // 0x800A704C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800A7050: addiu       $t6, $zero, -0x78
    ctx->r14 = ADD32(0, -0X78);
    // 0x800A7054: sb          $t6, 0x5FB($t7)
    MEM_B(0X5FB, ctx->r15) = ctx->r14;
    // 0x800A7058: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A705C: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A7060: sb          $zero, 0x5FC($t8)
    MEM_B(0X5FC, ctx->r24) = 0;
    // 0x800A7064: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A7068: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800A706C: bne         $t9, $zero, L_800A7104
    if (ctx->r25 != 0) {
        // 0x800A7070: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A7104;
    }
    // 0x800A7070: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A7074: bne         $t2, $at, L_800A70E0
    if (ctx->r10 != ctx->r1) {
        // 0x800A7078: nop
    
            goto L_800A70E0;
    }
    // 0x800A7078: nop

    // 0x800A707C: lh          $v1, 0x1AC($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X1AC);
    // 0x800A7080: addiu       $a0, $zero, 0x146
    ctx->r4 = ADD32(0, 0X146);
    // 0x800A7084: beq         $v1, $t0, L_800A70A4
    if (ctx->r3 == ctx->r8) {
        // 0x800A7088: nop
    
            goto L_800A70A4;
    }
    // 0x800A7088: nop

    // 0x800A708C: beq         $v1, $a2, L_800A70A4
    if (ctx->r3 == ctx->r6) {
        // 0x800A7090: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A70A4;
    }
    // 0x800A7090: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A7094: beq         $v1, $at, L_800A70B8
    if (ctx->r3 == ctx->r1) {
        // 0x800A7098: addiu       $a0, $zero, 0x14C
        ctx->r4 = ADD32(0, 0X14C);
            goto L_800A70B8;
    }
    // 0x800A7098: addiu       $a0, $zero, 0x14C
    ctx->r4 = ADD32(0, 0X14C);
    // 0x800A709C: b           L_800A70CC
    // 0x800A70A0: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
        goto L_800A70CC;
    // 0x800A70A0: addiu       $a0, $zero, 0x14D
    ctx->r4 = ADD32(0, 0X14D);
L_800A70A4:
    // 0x800A70A4: jal         0x80001D04
    // 0x800A70A8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800A70A8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_8:
    // 0x800A70AC: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A70B0: b           L_800A7104
    // 0x800A70B4: nop

        goto L_800A7104;
    // 0x800A70B4: nop

L_800A70B8:
    // 0x800A70B8: jal         0x80001D04
    // 0x800A70BC: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x800A70BC: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_9:
    // 0x800A70C0: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A70C4: b           L_800A7104
    // 0x800A70C8: nop

        goto L_800A7104;
    // 0x800A70C8: nop

L_800A70CC:
    // 0x800A70CC: jal         0x80001D04
    // 0x800A70D0: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A70D0: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_10:
    // 0x800A70D4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A70D8: b           L_800A7104
    // 0x800A70DC: nop

        goto L_800A7104;
    // 0x800A70DC: nop

L_800A70E0:
    // 0x800A70E0: jal         0x8001B674
    // 0x800A70E4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    timetrial_ghost_staff(rdram, ctx);
        goto after_11;
    // 0x800A70E4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_11:
    // 0x800A70E8: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A70EC: bne         $v0, $zero, L_800A7104
    if (ctx->r2 != 0) {
        // 0x800A70F0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800A7104;
    }
    // 0x800A70F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800A70F4: jal         0x800A72FC
    // 0x800A70F8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    hud_time_trial_message(rdram, ctx);
        goto after_12;
    // 0x800A70F8: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_12:
    // 0x800A70FC: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A7100: nop

L_800A7104:
    // 0x800A7104: jal         0x800A6460
    // 0x800A7108: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_13;
    // 0x800A7108: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_13:
    // 0x800A710C: b           L_800A72F0
    // 0x800A7110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A72F0;
    // 0x800A7110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7114:
    // 0x800A7114: lb          $t3, 0x5FB($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X5FB);
    // 0x800A7118: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x800A711C: addiu       $t7, $zero, -0x78
    ctx->r15 = ADD32(0, -0X78);
    // 0x800A7120: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A7124: sb          $t5, 0x5FB($v0)
    MEM_B(0X5FB, ctx->r2) = ctx->r13;
    // 0x800A7128: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A712C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A7130: lb          $t6, 0x5FB($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5FB);
    // 0x800A7134: nop

    // 0x800A7138: slti        $at, $t6, 0x78
    ctx->r1 = SIGNED(ctx->r14) < 0X78 ? 1 : 0;
    // 0x800A713C: bne         $at, $zero, L_800A7168
    if (ctx->r1 != 0) {
        // 0x800A7140: nop
    
            goto L_800A7168;
    }
    // 0x800A7140: nop

    // 0x800A7144: sb          $t7, 0x5FB($v0)
    MEM_B(0X5FB, ctx->r2) = ctx->r15;
    // 0x800A7148: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A714C: nop

    // 0x800A7150: lb          $t8, 0x5FC($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5FC);
    // 0x800A7154: nop

    // 0x800A7158: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800A715C: sb          $t9, 0x5FC($v0)
    MEM_B(0X5FC, ctx->r2) = ctx->r25;
    // 0x800A7160: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A7164: nop

L_800A7168:
    // 0x800A7168: lb          $t2, 0x5FC($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X5FC);
    // 0x800A716C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800A7170: bne         $a2, $t2, L_800A71DC
    if (ctx->r6 != ctx->r10) {
        // 0x800A7174: nop
    
            goto L_800A71DC;
    }
    // 0x800A7174: nop

    // 0x800A7178: lbu         $t3, 0x72F7($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X72F7);
    // 0x800A717C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A7180: beq         $t0, $t3, L_800A71B0
    if (ctx->r8 == ctx->r11) {
        // 0x800A7184: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_800A71B0;
    }
    // 0x800A7184: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800A7188: jal         0x8009F1C4
    // 0x800A718C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    is_in_two_player_adventure(rdram, ctx);
        goto after_14;
    // 0x800A718C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_14:
    // 0x800A7190: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A7194: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A7198: beq         $v0, $zero, L_800A71D0
    if (ctx->r2 == 0) {
        // 0x800A719C: addiu       $t1, $t1, 0x729C
        ctx->r9 = ADD32(ctx->r9, 0X729C);
            goto L_800A71D0;
    }
    // 0x800A719C: addiu       $t1, $t1, 0x729C
    ctx->r9 = ADD32(ctx->r9, 0X729C);
    // 0x800A71A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A71A4: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A71A8: nop

    // 0x800A71AC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_800A71B0:
    // 0x800A71B0: sb          $t4, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r12;
    // 0x800A71B4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800A71B8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A71BC: jal         0x80001D04
    // 0x800A71C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x800A71C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800A71C4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800A71C8: b           L_800A71DC
    // 0x800A71CC: nop

        goto L_800A71DC;
    // 0x800A71CC: nop

L_800A71D0:
    // 0x800A71D0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800A71D4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800A71D8: sb          $t5, 0x5FA($t6)
    MEM_B(0X5FA, ctx->r14) = ctx->r13;
L_800A71DC:
    // 0x800A71DC: jal         0x800A6460
    // 0x800A71E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_16;
    // 0x800A71E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_16:
    // 0x800A71E4: b           L_800A72F0
    // 0x800A71E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A72F0;
    // 0x800A71E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A71EC:
    // 0x800A71EC: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x800A71F0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A71F4: bne         $t7, $at, L_800A7204
    if (ctx->r15 != ctx->r1) {
        // 0x800A71F8: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_800A7204;
    }
    // 0x800A71F8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800A71FC: b           L_800A72A0
    // 0x800A7200: sb          $t8, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r24;
        goto L_800A72A0;
    // 0x800A7200: sb          $t8, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r24;
L_800A7204:
    // 0x800A7204: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x800A7208: lwc1        $f10, 0x5EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5EC);
    // 0x800A720C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800A7210: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x800A7214: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A7218: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800A721C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800A7220: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A7224: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A7228: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800A722C: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800A7230: swc1        $f4, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = ctx->f4.u32l;
    // 0x800A7234: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A7238: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A723C: lwc1        $f6, 0x60C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X60C);
    // 0x800A7240: nop

    // 0x800A7244: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800A7248: swc1        $f8, 0x60C($v0)
    MEM_W(0X60C, ctx->r2) = ctx->f8.u32l;
    // 0x800A724C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A7250: nop

    // 0x800A7254: lwc1        $f10, 0x5EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5EC);
    // 0x800A7258: nop

    // 0x800A725C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800A7260: nop

    // 0x800A7264: bc1f        L_800A7278
    if (!c1cs) {
        // 0x800A7268: nop
    
            goto L_800A7278;
    }
    // 0x800A7268: nop

    // 0x800A726C: sb          $t3, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r11;
    // 0x800A7270: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A7274: nop

L_800A7278:
    // 0x800A7278: lwc1        $f6, 0x16C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A727C: nop

    // 0x800A7280: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A7284: swc1        $f8, 0x16C($v0)
    MEM_W(0X16C, ctx->r2) = ctx->f8.u32l;
    // 0x800A7288: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800A728C: nop

    // 0x800A7290: lwc1        $f10, 0x2EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A7294: nop

    // 0x800A7298: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A729C: swc1        $f4, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = ctx->f4.u32l;
L_800A72A0:
    // 0x800A72A0: jal         0x800A6460
    // 0x800A72A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_17;
    // 0x800A72A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_17:
    // 0x800A72A8: b           L_800A72F0
    // 0x800A72AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A72F0;
    // 0x800A72AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A72B0:
    // 0x800A72B0: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x800A72B4: lb          $t5, 0xC($v1)
    ctx->r13 = MEM_B(ctx->r3, 0XC);
    // 0x800A72B8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800A72BC: bne         $t4, $t5, L_800A72CC
    if (ctx->r12 != ctx->r13) {
        // 0x800A72C0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800A72CC;
    }
    // 0x800A72C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800A72C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A72C8: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
L_800A72CC:
    // 0x800A72CC: sb          $t7, 0x5FA($v0)
    MEM_B(0X5FA, ctx->r2) = ctx->r15;
    // 0x800A72D0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800A72D4: jal         0x800A6460
    // 0x800A72D8: sb          $zero, 0x5FB($t8)
    MEM_B(0X5FB, ctx->r24) = 0;
    hud_finish_position(rdram, ctx);
        goto after_18;
    // 0x800A72D8: sb          $zero, 0x5FB($t8)
    MEM_B(0X5FB, ctx->r24) = 0;
    after_18:
    // 0x800A72DC: b           L_800A72F0
    // 0x800A72E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A72F0;
    // 0x800A72E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A72E4:
    // 0x800A72E4: jal         0x800A6460
    // 0x800A72E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_finish_position(rdram, ctx);
        goto after_19;
    // 0x800A72E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_19:
L_800A72EC:
    // 0x800A72EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A72F0:
    // 0x800A72F0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800A72F4: jr          $ra
    // 0x800A72F8: nop

    return;
    // 0x800A72F8: nop

;}
RECOMP_FUNC void trackbg_render_gradient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800289F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800289FC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80028A00: lw          $v0, -0x3174($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3174);
    // 0x80028A04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80028A08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80028A0C: lbu         $t6, 0xC1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC1);
    // 0x80028A10: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028A14: sb          $t6, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r14;
    // 0x80028A18: lbu         $t7, 0xC2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC2);
    // 0x80028A1C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80028A20: sb          $t7, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r15;
    // 0x80028A24: lbu         $t8, 0xC3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XC3);
    // 0x80028A28: lw          $v1, -0x49D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X49D8);
    // 0x80028A2C: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x80028A30: lbu         $t9, 0xBE($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XBE);
    // 0x80028A34: lw          $a3, -0x49D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X49D4);
    // 0x80028A38: sb          $t9, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r25;
    // 0x80028A3C: lbu         $t6, 0xBF($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XBF);
    // 0x80028A40: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80028A44: sb          $t6, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r14;
    // 0x80028A48: lbu         $t7, 0xC0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC0);
    // 0x80028A4C: addiu       $s0, $s0, -0x49E0
    ctx->r16 = ADD32(ctx->r16, -0X49E0);
    // 0x80028A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80028A54: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80028A58: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80028A5C: jal         0x8007B820
    // 0x80028A60: sb          $t7, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x80028A60: sb          $t7, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r15;
    after_0:
    // 0x80028A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80028A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80028A6C: jal         0x8007B918
    // 0x80028A70: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    material_set_no_tex_offset(rdram, ctx);
        goto after_1;
    // 0x80028A70: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80028A74: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80028A78: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80028A7C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80028A80: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    // 0x80028A84: andi        $t9, $a1, 0x6
    ctx->r25 = ctx->r5 & 0X6;
    // 0x80028A88: ori         $t6, $t9, 0x18
    ctx->r14 = ctx->r25 | 0X18;
    // 0x80028A8C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80028A90: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80028A94: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80028A98: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80028A9C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80028AA0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80028AA4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80028AA8: ori         $t6, $t9, 0x50
    ctx->r14 = ctx->r25 | 0X50;
    // 0x80028AAC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80028AB0: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80028AB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80028AB8: lui         $t8, 0x510
    ctx->r24 = S32(0X510 << 16);
    // 0x80028ABC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80028AC0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80028AC4: ori         $t8, $t8, 0x20
    ctx->r24 = ctx->r24 | 0X20;
    // 0x80028AC8: addu        $t9, $a3, $t0
    ctx->r25 = ADD32(ctx->r7, ctx->r8);
    // 0x80028ACC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80028AD0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80028AD4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80028AD8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80028ADC: addiu       $s0, $zero, -0x96
    ctx->r16 = ADD32(0, -0X96);
    // 0x80028AE0: bne         $t6, $zero, L_80028AF4
    if (ctx->r14 != 0) {
        // 0x80028AE4: addiu       $a0, $zero, 0x96
        ctx->r4 = ADD32(0, 0X96);
            goto L_80028AF4;
    }
    // 0x80028AE4: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80028AE8: addiu       $s0, $zero, -0xB4
    ctx->r16 = ADD32(0, -0XB4);
    // 0x80028AEC: b           L_80028AF4
    // 0x80028AF0: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
        goto L_80028AF4;
    // 0x80028AF0: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
L_80028AF4:
    // 0x80028AF4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80028AF8: sh          $a0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r4;
    // 0x80028AFC: jal         0x80066450
    // 0x80028B00: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    cam_get_viewport_layout(rdram, ctx);
        goto after_2;
    // 0x80028B00: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x80028B04: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80028B08: lh          $a0, 0x30($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X30);
    // 0x80028B0C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80028B10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80028B14: bne         $v0, $at, L_80028B34
    if (ctx->r2 != ctx->r1) {
        // 0x80028B18: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80028B34;
    }
    // 0x80028B18: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80028B1C: sra         $t7, $s0, 1
    ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80028B20: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80028B24: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80028B28: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80028B2C: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80028B30: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
L_80028B34:
    // 0x80028B34: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
    // 0x80028B38: lbu         $t2, 0x2E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2E);
    // 0x80028B3C: lbu         $t3, 0x2D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2D);
    // 0x80028B40: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80028B44: addiu       $a2, $zero, -0xC8
    ctx->r6 = ADD32(0, -0XC8);
    // 0x80028B48: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x80028B4C: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x80028B50: sh          $s0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r16;
    // 0x80028B54: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x80028B58: sb          $a1, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r5;
    // 0x80028B5C: sh          $t0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r8;
    // 0x80028B60: sh          $s0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r16;
    // 0x80028B64: sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
    // 0x80028B68: sb          $t1, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r9;
    // 0x80028B6C: sb          $t1, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r9;
    // 0x80028B70: sb          $t2, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r10;
    // 0x80028B74: sb          $t3, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r11;
    // 0x80028B78: lbu         $ra, 0x2A($sp)
    ctx->r31 = MEM_BU(ctx->r29, 0X2A);
    // 0x80028B7C: lbu         $t5, 0x2B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2B);
    // 0x80028B80: lbu         $t4, 0x2C($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2C);
    // 0x80028B84: sh          $a2, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r6;
    // 0x80028B88: sh          $t0, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r8;
    // 0x80028B8C: sb          $a1, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r5;
    // 0x80028B90: sh          $a0, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r4;
    // 0x80028B94: sh          $v0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r2;
    // 0x80028B98: sb          $a1, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r5;
    // 0x80028B9C: sh          $a0, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r4;
    // 0x80028BA0: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x80028BA4: sb          $a1, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r5;
    // 0x80028BA8: sb          $t2, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r10;
    // 0x80028BAC: sb          $t3, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r11;
    // 0x80028BB0: sb          $ra, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r31;
    // 0x80028BB4: sb          $ra, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r31;
    // 0x80028BB8: sb          $t5, 0x1B($v1)
    MEM_B(0X1B, ctx->r3) = ctx->r13;
    // 0x80028BBC: sb          $t5, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r13;
    // 0x80028BC0: sb          $t4, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r12;
    // 0x80028BC4: sb          $t4, 0x24($v1)
    MEM_B(0X24, ctx->r3) = ctx->r12;
    // 0x80028BC8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80028BCC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80028BD0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80028BD4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80028BD8: sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // 0x80028BDC: sb          $t0, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r8;
    // 0x80028BE0: sb          $t1, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r9;
    // 0x80028BE4: sb          $zero, 0x3($a3)
    MEM_B(0X3, ctx->r7) = 0;
    // 0x80028BE8: sh          $zero, 0x4($a3)
    MEM_H(0X4, ctx->r7) = 0;
    // 0x80028BEC: sh          $zero, 0x6($a3)
    MEM_H(0X6, ctx->r7) = 0;
    // 0x80028BF0: sh          $zero, 0x8($a3)
    MEM_H(0X8, ctx->r7) = 0;
    // 0x80028BF4: sh          $zero, 0xA($a3)
    MEM_H(0XA, ctx->r7) = 0;
    // 0x80028BF8: sh          $zero, 0xC($a3)
    MEM_H(0XC, ctx->r7) = 0;
    // 0x80028BFC: sh          $zero, 0xE($a3)
    MEM_H(0XE, ctx->r7) = 0;
    // 0x80028C00: sb          $a2, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r6;
    // 0x80028C04: sb          $t9, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r25;
    // 0x80028C08: sb          $t0, 0x12($a3)
    MEM_B(0X12, ctx->r7) = ctx->r8;
    // 0x80028C0C: sb          $t1, 0x13($a3)
    MEM_B(0X13, ctx->r7) = ctx->r9;
    // 0x80028C10: sh          $zero, 0x14($a3)
    MEM_H(0X14, ctx->r7) = 0;
    // 0x80028C14: sh          $zero, 0x16($a3)
    MEM_H(0X16, ctx->r7) = 0;
    // 0x80028C18: sh          $zero, 0x18($a3)
    MEM_H(0X18, ctx->r7) = 0;
    // 0x80028C1C: sh          $zero, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = 0;
    // 0x80028C20: sh          $zero, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = 0;
    // 0x80028C24: sh          $zero, 0x1E($a3)
    MEM_H(0X1E, ctx->r7) = 0;
    // 0x80028C28: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x80028C2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028C34: sw          $v1, -0x49D8($at)
    MEM_W(-0X49D8, ctx->r1) = ctx->r3;
    // 0x80028C38: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x80028C3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028C40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028C44: sw          $a3, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = ctx->r7;
    // 0x80028C48: jr          $ra
    // 0x80028C4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80028C4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_loop_collectegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800352A0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800352A4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800352A8: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800352AC: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800352B0: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800352B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800352B8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800352BC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800352C0: lw          $s1, 0x64($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X64);
    // 0x800352C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800352C8: bne         $t6, $zero, L_800352E8
    if (ctx->r14 != 0) {
        // 0x800352CC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800352E8;
    }
    // 0x800352CC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800352D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800352D4: lwc1        $f9, 0x65A0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X65A0);
    // 0x800352D8: lwc1        $f8, 0x65A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X65A4);
    // 0x800352DC: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800352E0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800352E4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800352E8:
    // 0x800352E8: lb          $v0, 0xB($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XB);
    // 0x800352EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800352F0: beq         $v0, $zero, L_8003531C
    if (ctx->r2 == 0) {
        // 0x800352F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003531C;
    }
    // 0x800352F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800352F8: beq         $v0, $at, L_8003532C
    if (ctx->r2 == ctx->r1) {
        // 0x800352FC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8003532C;
    }
    // 0x800352FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80035300: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80035304: beq         $v0, $at, L_8003557C
    if (ctx->r2 == ctx->r1) {
        // 0x80035308: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8003557C;
    }
    // 0x80035308: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003530C: beq         $v0, $at, L_80035634
    if (ctx->r2 == ctx->r1) {
        // 0x80035310: nop
    
            goto L_80035634;
    }
    // 0x80035310: nop

    // 0x80035314: b           L_80035670
    // 0x80035318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80035670;
    // 0x80035318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003531C:
    // 0x8003531C: jal         0x80036080
    // 0x80035320: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    try_to_collect_egg(rdram, ctx);
        goto after_0;
    // 0x80035320: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80035324: b           L_80035670
    // 0x80035328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80035670;
    // 0x80035328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003532C:
    // 0x8003532C: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80035330: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x80035334: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80035338: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003533C: andi        $t8, $t7, 0xBFFF
    ctx->r24 = ctx->r15 & 0XBFFF;
    // 0x80035340: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x80035344: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80035348: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8003534C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80035350: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80035354: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80035358: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003535C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80035360: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80035364: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80035368: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8003536C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80035370: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x80035374: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80035378: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003537C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80035380: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80035384: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80035388: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8003538C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80035390: jal         0x80031170
    // 0x80035394: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_1;
    // 0x80035394: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80035398: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003539C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800353A0: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x800353A4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800353A8: sb          $zero, 0x33($sp)
    MEM_B(0X33, ctx->r29) = 0;
    // 0x800353AC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800353B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800353B4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800353B8: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800353BC: jal         0x80031640
    // 0x800353C0: addiu       $a3, $sp, 0x33
    ctx->r7 = ADD32(ctx->r29, 0X33);
    resolve_collisions(rdram, ctx);
        goto after_2;
    // 0x800353C0: addiu       $a3, $sp, 0x33
    ctx->r7 = ADD32(ctx->r29, 0X33);
    after_2:
    // 0x800353C4: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800353C8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800353CC: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800353D0: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800353D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800353D8: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800353DC: lwc1        $f3, 0x65A8($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X65A8);
    // 0x800353E0: lwc1        $f2, 0x65AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X65AC);
    // 0x800353E4: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800353E8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800353EC: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800353F0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800353F4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800353F8: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800353FC: nop

    // 0x80035400: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80035404: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80035408: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003540C: nop

    // 0x80035410: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80035414: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80035418: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003541C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80035420: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80035424: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80035428: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8003542C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80035430: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80035434: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80035438: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003543C: sub.d       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f8.d - ctx->f18.d;
    // 0x80035440: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80035444: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80035448: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x8003544C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80035450: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80035454: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80035458: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8003545C: mul.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x80035460: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80035464: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80035468: mul.d       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x8003546C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x80035470: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80035474: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x80035478: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8003547C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x80035480: lwc1        $f16, 0x65B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X65B4);
    // 0x80035484: lwc1        $f17, 0x65B0($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X65B0);
    // 0x80035488: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x8003548C: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x80035490: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x80035494: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80035498: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003549C: nop

    // 0x800354A0: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800354A4: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x800354A8: bc1t        L_800354D0
    if (c1cs) {
        // 0x800354AC: swc1        $f4, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
            goto L_800354D0;
    }
    // 0x800354AC: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x800354B0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800354B4: lb          $t2, 0x33($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X33);
    // 0x800354B8: beq         $t1, $zero, L_800354EC
    if (ctx->r9 == 0) {
        // 0x800354BC: slti        $at, $t2, 0x5
        ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
            goto L_800354EC;
    }
    // 0x800354BC: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x800354C0: bne         $at, $zero, L_800354D0
    if (ctx->r1 != 0) {
        // 0x800354C4: slti        $at, $t2, 0xA
        ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
            goto L_800354D0;
    }
    // 0x800354C4: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x800354C8: bne         $at, $zero, L_800354F0
    if (ctx->r1 != 0) {
        // 0x800354CC: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_800354F0;
    }
    // 0x800354CC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_800354D0:
    // 0x800354D0: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800354D4: nop

    // 0x800354D8: beq         $v0, $zero, L_800354E4
    if (ctx->r2 == 0) {
        // 0x800354DC: nop
    
            goto L_800354E4;
    }
    // 0x800354DC: nop

    // 0x800354E0: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
L_800354E4:
    // 0x800354E4: jal         0x8000FFB8
    // 0x800354E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_3;
    // 0x800354E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_800354EC:
    // 0x800354EC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_800354F0:
    // 0x800354F0: lb          $t4, 0x33($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X33);
    // 0x800354F4: beq         $t3, $zero, L_80035514
    if (ctx->r11 == 0) {
        // 0x800354F8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80035514;
    }
    // 0x800354F8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800354FC: bne         $t4, $at, L_80035518
    if (ctx->r12 != ctx->r1) {
        // 0x80035500: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_80035518;
    }
    // 0x80035500: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80035504: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035508: sb          $zero, 0xB($s1)
    MEM_B(0XB, ctx->r17) = 0;
    // 0x8003550C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80035510: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_80035514:
    // 0x80035514: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_80035518:
    // 0x80035518: lb          $t6, 0x33($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X33);
    // 0x8003551C: beq         $t5, $zero, L_8003566C
    if (ctx->r13 == 0) {
        // 0x80035520: slti        $at, $t6, 0x6
        ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
            goto L_8003566C;
    }
    // 0x80035520: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x80035524: bne         $at, $zero, L_8003566C
    if (ctx->r1 != 0) {
        // 0x80035528: slti        $at, $t6, 0xA
        ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
            goto L_8003566C;
    }
    // 0x80035528: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x8003552C: beq         $at, $zero, L_8003566C
    if (ctx->r1 == 0) {
        // 0x80035530: addiu       $t7, $t6, -0x6
        ctx->r15 = ADD32(ctx->r14, -0X6);
            goto L_8003566C;
    }
    // 0x80035530: addiu       $t7, $t6, -0x6
    ctx->r15 = ADD32(ctx->r14, -0X6);
    // 0x80035534: sb          $t7, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r15;
    // 0x80035538: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8003553C: lb          $a0, 0xA($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XA);
    // 0x80035540: jal         0x8001BAFC
    // 0x80035544: sb          $t8, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r24;
    get_racer_object(rdram, ctx);
        goto after_4;
    // 0x80035544: sb          $t8, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r24;
    after_4:
    // 0x80035548: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003554C: beq         $v0, $zero, L_8003556C
    if (ctx->r2 == 0) {
        // 0x80035550: addiu       $t1, $zero, 0x258
        ctx->r9 = ADD32(0, 0X258);
            goto L_8003556C;
    }
    // 0x80035550: addiu       $t1, $zero, 0x258
    ctx->r9 = ADD32(0, 0X258);
    // 0x80035554: lw          $a2, 0x64($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X64);
    // 0x80035558: nop

    // 0x8003555C: lb          $t9, 0x1CF($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X1CF);
    // 0x80035560: nop

    // 0x80035564: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80035568: sb          $t0, 0x1CF($a2)
    MEM_B(0X1CF, ctx->r6) = ctx->r8;
L_8003556C:
    // 0x8003556C: sh          $t1, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r9;
    // 0x80035570: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80035574: b           L_8003566C
    // 0x80035578: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_8003566C;
    // 0x80035578: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8003557C:
    // 0x8003557C: lh          $t2, 0x8($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X8);
    // 0x80035580: lb          $a0, 0xA($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XA);
    // 0x80035584: subu        $t3, $t2, $a1
    ctx->r11 = SUB32(ctx->r10, ctx->r5);
    // 0x80035588: jal         0x8001BAFC
    // 0x8003558C: sh          $t3, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r11;
    get_racer_object(rdram, ctx);
        goto after_5;
    // 0x8003558C: sh          $t3, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r11;
    after_5:
    // 0x80035590: beq         $v0, $zero, L_800355A4
    if (ctx->r2 == 0) {
        // 0x80035594: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800355A4;
    }
    // 0x80035594: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80035598: lw          $a2, 0x64($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X64);
    // 0x8003559C: nop

    // 0x800355A0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
L_800355A4:
    // 0x800355A4: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x800355A8: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800355AC: bgtz        $v1, L_800355E0
    if (SIGNED(ctx->r3) > 0) {
        // 0x800355B0: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_800355E0;
    }
    // 0x800355B0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800355B4: beq         $v0, $zero, L_800355CC
    if (ctx->r2 == 0) {
        // 0x800355B8: nop
    
            goto L_800355CC;
    }
    // 0x800355B8: nop

    // 0x800355BC: lb          $t4, 0x193($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X193);
    // 0x800355C0: nop

    // 0x800355C4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800355C8: sb          $t5, 0x193($a2)
    MEM_B(0X193, ctx->r6) = ctx->r13;
L_800355CC:
    // 0x800355CC: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800355D0: sb          $t6, 0xB($s1)
    MEM_B(0XB, ctx->r17) = ctx->r14;
    // 0x800355D4: sw          $zero, 0x78($t7)
    MEM_W(0X78, ctx->r15) = 0;
    // 0x800355D8: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x800355DC: nop

L_800355E0:
    // 0x800355E0: slti        $at, $v1, 0x21C
    ctx->r1 = SIGNED(ctx->r3) < 0X21C ? 1 : 0;
    // 0x800355E4: beq         $at, $zero, L_80035608
    if (ctx->r1 == 0) {
        // 0x800355E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80035608;
    }
    // 0x800355E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800355EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800355F0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x800355F4: jal         0x80036080
    // 0x800355F8: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    try_to_collect_egg(rdram, ctx);
        goto after_6;
    // 0x800355F8: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    after_6:
    // 0x800355FC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80035600: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80035604: nop

L_80035608:
    // 0x80035608: beq         $a3, $zero, L_80035670
    if (ctx->r7 == 0) {
        // 0x8003560C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80035670;
    }
    // 0x8003560C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80035610: lb          $t8, 0xB($s1)
    ctx->r24 = MEM_B(ctx->r17, 0XB);
    // 0x80035614: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80035618: beq         $t8, $at, L_80035670
    if (ctx->r24 == ctx->r1) {
        // 0x8003561C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80035670;
    }
    // 0x8003561C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80035620: lb          $t9, 0x1CF($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X1CF);
    // 0x80035624: nop

    // 0x80035628: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8003562C: b           L_8003566C
    // 0x80035630: sb          $t0, 0x1CF($a2)
    MEM_B(0X1CF, ctx->r6) = ctx->r8;
        goto L_8003566C;
    // 0x80035630: sb          $t0, 0x1CF($a2)
    MEM_B(0X1CF, ctx->r6) = ctx->r8;
L_80035634:
    // 0x80035634: lb          $a0, 0xA($s1)
    ctx->r4 = MEM_B(ctx->r17, 0XA);
    // 0x80035638: jal         0x8001BAFC
    // 0x8003563C: nop

    get_racer_object(rdram, ctx);
        goto after_7;
    // 0x8003563C: nop

    after_7:
    // 0x80035640: beq         $v0, $zero, L_80035668
    if (ctx->r2 == 0) {
        // 0x80035644: addiu       $t3, $zero, 0x80
        ctx->r11 = ADD32(0, 0X80);
            goto L_80035668;
    }
    // 0x80035644: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80035648: lw          $a2, 0x64($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X64);
    // 0x8003564C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80035650: lb          $t1, 0x193($a2)
    ctx->r9 = MEM_B(ctx->r6, 0X193);
    // 0x80035654: nop

    // 0x80035658: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8003565C: bne         $at, $zero, L_80035668
    if (ctx->r1 != 0) {
        // 0x80035660: nop
    
            goto L_80035668;
    }
    // 0x80035660: nop

    // 0x80035664: sb          $t2, 0x1D8($a2)
    MEM_B(0X1D8, ctx->r6) = ctx->r10;
L_80035668:
    // 0x80035668: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
L_8003566C:
    // 0x8003566C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80035670:
    // 0x80035670: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80035674: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80035678: jr          $ra
    // 0x8003567C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8003567C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void __vsVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A9F8: lbu         $t6, 0x36($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X36);
    // 0x8000A9FC: lbu         $t7, 0x33($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X33);
    // 0x8000AA00: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x8000AA04: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA08: lbu         $t2, 0x31($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X31);
    // 0x8000AA0C: lw          $t1, 0x60($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X60);
    // 0x8000AA10: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000AA14: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8000AA18: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x8000AA1C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000AA20: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000AA24: lbu         $t5, 0x9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X9);
    // 0x8000AA28: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x8000AA2C: mflo        $t8
    ctx->r24 = lo;
    // 0x8000AA30: nop

    // 0x8000AA34: nop

    // 0x8000AA38: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA3C: lh          $t9, 0x32($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X32);
    // 0x8000AA40: mflo        $v1
    ctx->r3 = lo;
    // 0x8000AA44: sra         $t0, $v1, 6
    ctx->r8 = S32(SIGNED(ctx->r3) >> 6);
    // 0x8000AA48: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8000AA4C: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA50: mflo        $t8
    ctx->r24 = lo;
    // 0x8000AA54: nop

    // 0x8000AA58: nop

    // 0x8000AA5C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA60: mflo        $a2
    ctx->r6 = lo;
    // 0x8000AA64: sra         $t0, $a2, 14
    ctx->r8 = S32(SIGNED(ctx->r6) >> 14);
    // 0x8000AA68: nop

    // 0x8000AA6C: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000AA70: mflo        $v1
    ctx->r3 = lo;
    // 0x8000AA74: srl         $t2, $v1, 15
    ctx->r10 = S32(U32(ctx->r3) >> 15);
    // 0x8000AA78: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x8000AA7C: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8000AA80: jr          $ra
    // 0x8000AA84: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x8000AA84: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void apply_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003097C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80030980: addiu       $t1, $t1, -0x49E0
    ctx->r9 = ADD32(ctx->r9, -0X49E0);
    // 0x80030984: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80030988: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8003098C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x80030990: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80030994: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80030998: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8003099C: addiu       $t9, $t9, -0x26F8
    ctx->r25 = ADD32(ctx->r25, -0X26F8);
    // 0x800309A0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800309A4: lui         $t7, 0xF800
    ctx->r15 = S32(0XF800 << 16);
    // 0x800309A8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x800309AC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800309B0: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x800309B4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800309B8: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800309BC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800309C0: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x800309C4: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800309C8: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800309CC: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800309D0: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x800309D4: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800309D8: or          $t2, $t5, $t9
    ctx->r10 = ctx->r13 | ctx->r25;
    // 0x800309DC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800309E0: or          $t8, $t2, $t7
    ctx->r24 = ctx->r10 | ctx->r15;
    // 0x800309E4: ori         $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 | 0XFF;
    // 0x800309E8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800309EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800309F0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800309F4: lui         $t3, 0xBC00
    ctx->r11 = S32(0XBC00 << 16);
    // 0x800309F8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800309FC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80030A00: ori         $t3, $t3, 0x8
    ctx->r11 = ctx->r11 | 0X8;
    // 0x80030A04: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80030A08: lw          $a3, 0xC($a1)
    ctx->r7 = MEM_W(ctx->r5, 0XC);
    // 0x80030A0C: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80030A10: sra         $t4, $a3, 16
    ctx->r12 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80030A14: negu        $t7, $t4
    ctx->r15 = SUB32(0, ctx->r12);
    // 0x80030A18: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80030A1C: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x80030A20: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80030A24: sra         $t2, $t6, 16
    ctx->r10 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80030A28: subu        $t0, $t2, $t4
    ctx->r8 = SUB32(ctx->r10, ctx->r12);
    // 0x80030A2C: addu        $t5, $t8, $at
    ctx->r13 = ADD32(ctx->r24, ctx->r1);
    // 0x80030A30: div         $zero, $t5, $t0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r8)));
    // 0x80030A34: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x80030A38: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80030A3C: ori         $t4, $t4, 0xF400
    ctx->r12 = ctx->r12 | 0XF400;
    // 0x80030A40: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80030A44: bne         $t0, $zero, L_80030A50
    if (ctx->r8 != 0) {
        // 0x80030A48: nop
    
            goto L_80030A50;
    }
    // 0x80030A48: nop

    // 0x80030A4C: break       7
    do_break(2147682892);
L_80030A50:
    // 0x80030A50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030A54: bne         $t0, $at, L_80030A68
    if (ctx->r8 != ctx->r1) {
        // 0x80030A58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030A68;
    }
    // 0x80030A58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030A5C: bne         $t5, $at, L_80030A68
    if (ctx->r13 != ctx->r1) {
        // 0x80030A60: nop
    
            goto L_80030A68;
    }
    // 0x80030A60: nop

    // 0x80030A64: break       6
    do_break(2147682916);
L_80030A68:
    // 0x80030A68: mflo        $t9
    ctx->r25 = lo;
    // 0x80030A6C: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x80030A70: nop

    // 0x80030A74: div         $zero, $t4, $t0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r8)));
    // 0x80030A78: bne         $t0, $zero, L_80030A84
    if (ctx->r8 != 0) {
        // 0x80030A7C: nop
    
            goto L_80030A84;
    }
    // 0x80030A7C: nop

    // 0x80030A80: break       7
    do_break(2147682944);
L_80030A84:
    // 0x80030A84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80030A88: bne         $t0, $at, L_80030A9C
    if (ctx->r8 != ctx->r1) {
        // 0x80030A8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80030A9C;
    }
    // 0x80030A8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80030A90: bne         $t4, $at, L_80030A9C
    if (ctx->r12 != ctx->r1) {
        // 0x80030A94: nop
    
            goto L_80030A9C;
    }
    // 0x80030A94: nop

    // 0x80030A98: break       6
    do_break(2147682968);
L_80030A9C:
    // 0x80030A9C: mflo        $t6
    ctx->r14 = lo;
    // 0x80030AA0: andi        $t2, $t6, 0xFFFF
    ctx->r10 = ctx->r14 & 0XFFFF;
    // 0x80030AA4: sll         $t7, $t2, 16
    ctx->r15 = S32(ctx->r10 << 16);
    // 0x80030AA8: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x80030AAC: jr          $ra
    // 0x80030AB0: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    return;
    // 0x80030AB0: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
;}
RECOMP_FUNC void __resetPerfChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ADF4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8000ADF8: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADFC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000AE00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000AE04: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8000AE08: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
    // 0x8000AE0C: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE10: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x8000AE14: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8000AE18: sb          $zero, 0xA($t9)
    MEM_B(0XA, ctx->r25) = 0;
    // 0x8000AE1C: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE20: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x8000AE24: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8000AE28: sb          $t0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r8;
    // 0x8000AE2C: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE30: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8000AE34: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8000AE38: sb          $v1, 0x9($t4)
    MEM_B(0X9, ctx->r12) = ctx->r3;
    // 0x8000AE3C: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE40: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x8000AE44: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000AE48: sb          $v1, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r3;
    // 0x8000AE4C: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000AE54: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8000AE58: sb          $t7, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r15;
    // 0x8000AE5C: lw          $t1, 0x60($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000AE64: addu        $t0, $t1, $v0
    ctx->r8 = ADD32(ctx->r9, ctx->r2);
    // 0x8000AE68: sb          $zero, 0xB($t0)
    MEM_B(0XB, ctx->r8) = 0;
    // 0x8000AE6C: lw          $t3, 0x60($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE70: nop

    // 0x8000AE74: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8000AE78: sh          $t2, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r10;
    // 0x8000AE7C: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x8000AE80: nop

    // 0x8000AE84: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000AE88: jr          $ra
    // 0x8000AE8C: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    return;
    // 0x8000AE8C: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
;}
RECOMP_FUNC void reset_current_text_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5638: blez        $a0, L_800C5664
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C563C: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C5664;
    }
    // 0x800C563C: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C5640: beq         $at, $zero, L_800C5664
    if (ctx->r1 == 0) {
        // 0x800C5644: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C5664;
    }
    // 0x800C5644: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5648: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C564C: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5650: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5654: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5658: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C565C: sh          $zero, 0x20($v0)
    MEM_H(0X20, ctx->r2) = 0;
    // 0x800C5660: sh          $zero, 0x22($v0)
    MEM_H(0X22, ctx->r2) = 0;
L_800C5664:
    // 0x800C5664: jr          $ra
    // 0x800C5668: nop

    return;
    // 0x800C5668: nop

;}
RECOMP_FUNC void init_line_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF4E8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800AF4EC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800AF4F0: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x800AF4F4: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x800AF4F8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800AF4FC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800AF500: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800AF504: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800AF508: nop

    // 0x800AF50C: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    // 0x800AF510: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AF514: nop

    // 0x800AF518: sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
    // 0x800AF51C: sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    // 0x800AF520: sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
    // 0x800AF524: sb          $v1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r3;
    // 0x800AF528: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x800AF52C: sb          $v1, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r3;
    // 0x800AF530: sb          $v1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r3;
    // 0x800AF534: sb          $v1, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r3;
    // 0x800AF538: sb          $v1, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r3;
    // 0x800AF53C: sb          $v1, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r3;
    // 0x800AF540: sb          $v1, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r3;
    // 0x800AF544: sb          $v1, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r3;
    // 0x800AF548: sb          $v1, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r3;
    // 0x800AF54C: sb          $v1, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r3;
    // 0x800AF550: sb          $v1, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r3;
    // 0x800AF554: sb          $v1, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r3;
    // 0x800AF558: sb          $v1, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r3;
    // 0x800AF55C: sb          $v1, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r3;
    // 0x800AF560: sb          $v1, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r3;
    // 0x800AF564: sb          $v1, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = ctx->r3;
    // 0x800AF568: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x800AF56C: sb          $v1, -0x22($v0)
    MEM_B(-0X22, ctx->r2) = ctx->r3;
    // 0x800AF570: sb          $v1, -0x21($v0)
    MEM_B(-0X21, ctx->r2) = ctx->r3;
    // 0x800AF574: sb          $v1, -0x20($v0)
    MEM_B(-0X20, ctx->r2) = ctx->r3;
    // 0x800AF578: sb          $v1, -0x1F($v0)
    MEM_B(-0X1F, ctx->r2) = ctx->r3;
    // 0x800AF57C: jr          $ra
    // 0x800AF580: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    return;
    // 0x800AF580: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void coss_s16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A6C: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x80070A70: sll         $v0, $a0, 17
    ctx->r2 = S32(ctx->r4 << 17);
    // 0x80070A74: bgezl       $v0, L_80070A84
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80070A78: srl         $t2, $a0, 3
        ctx->r10 = S32(U32(ctx->r4) >> 3);
            goto L_80070A84;
    }
    goto skip_0;
    // 0x80070A78: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
    skip_0:
    // 0x80070A7C: xori        $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 ^ 0X7FFF;
    // 0x80070A80: srl         $t2, $a0, 3
    ctx->r10 = S32(U32(ctx->r4) >> 3);
L_80070A84:
    // 0x80070A84: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80070A88: andi        $t2, $t2, 0x7FE
    ctx->r10 = ctx->r10 & 0X7FE;
    // 0x80070A8C: addiu       $v0, $v0, -0x2654
    ctx->r2 = ADD32(ctx->r2, -0X2654);
    // 0x80070A90: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80070A94: lhu         $t2, 0x2($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X2);
    // 0x80070A98: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80070A9C: andi        $t1, $a0, 0xF
    ctx->r9 = ctx->r4 & 0XF;
    // 0x80070AA0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80070AA4: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80070AA8: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070AAC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80070AB0: mflo        $t2
    ctx->r10 = lo;
    // 0x80070AB4: srl         $t2, $t2, 3
    ctx->r10 = S32(U32(ctx->r10) >> 3);
    // 0x80070AB8: bgez        $a0, L_80070AC4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80070ABC: addu        $v0, $v0, $t2
        ctx->r2 = ADD32(ctx->r2, ctx->r10);
            goto L_80070AC4;
    }
    // 0x80070ABC: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80070AC0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80070AC4:
    // 0x80070AC4: jr          $ra
    // 0x80070AC8: nop

    return;
    // 0x80070AC8: nop

;}
RECOMP_FUNC void hud_finish_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6460: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A6464: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A6468: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A646C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800A6470: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6474: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A6478: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A647C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A6480: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A6484: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A6488: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A648C: jal         0x800AAB5C
    // 0x800A6490: addiu       $a3, $a3, 0x5E0
    ctx->r7 = ADD32(ctx->r7, 0X5E0);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A6490: addiu       $a3, $a3, 0x5E0
    ctx->r7 = ADD32(ctx->r7, 0X5E0);
    after_0:
    // 0x800A6494: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A6498: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A649C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A64A0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A64A4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A64A8: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A64AC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A64B0: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A64B4: jal         0x800AAB5C
    // 0x800A64B8: addiu       $a3, $a3, 0x600
    ctx->r7 = ADD32(ctx->r7, 0X600);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A64B8: addiu       $a3, $a3, 0x600
    ctx->r7 = ADD32(ctx->r7, 0X600);
    after_1:
    // 0x800A64BC: jal         0x8006BFD8
    // 0x800A64C0: nop

    level_type(rdram, ctx);
        goto after_2;
    // 0x800A64C0: nop

    after_2:
    // 0x800A64C4: andi        $t6, $v0, 0x40
    ctx->r14 = ctx->r2 & 0X40;
    // 0x800A64C8: bne         $t6, $zero, L_800A6790
    if (ctx->r14 != 0) {
        // 0x800A64CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6790;
    }
    // 0x800A64CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A64D0: jal         0x8009F1C4
    // 0x800A64D4: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_3;
    // 0x800A64D4: nop

    after_3:
    // 0x800A64D8: bne         $v0, $zero, L_800A6790
    if (ctx->r2 != 0) {
        // 0x800A64DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6790;
    }
    // 0x800A64DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A64E0: jal         0x8001BAA8
    // 0x800A64E4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    get_racer_objects(rdram, ctx);
        goto after_4;
    // 0x800A64E4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x800A64E8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A64EC: lbu         $t7, 0x72F7($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X72F7);
    // 0x800A64F0: nop

    // 0x800A64F4: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800A64F8: bne         $at, $zero, L_800A6790
    if (ctx->r1 != 0) {
        // 0x800A64FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6790;
    }
    // 0x800A64FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6500: jal         0x8009F1C4
    // 0x800A6504: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_5;
    // 0x800A6504: nop

    after_5:
    // 0x800A6508: beq         $v0, $zero, L_800A6520
    if (ctx->r2 == 0) {
        // 0x800A650C: nop
    
            goto L_800A6520;
    }
    // 0x800A650C: nop

    // 0x800A6510: jal         0x8006ECF0
    // 0x800A6514: nop

    is_postrace_viewport_active(rdram, ctx);
        goto after_6;
    // 0x800A6514: nop

    after_6:
    // 0x800A6518: bne         $v0, $zero, L_800A6790
    if (ctx->r2 != 0) {
        // 0x800A651C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A6790;
    }
    // 0x800A651C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A6520:
    // 0x800A6520: jal         0x800C484C
    // 0x800A6524: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x800A6524: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A6528: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A652C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A6530: lh          $t0, 0x1AC($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X1AC);
    // 0x800A6534: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6538: beq         $t8, $t0, L_800A671C
    if (ctx->r24 == ctx->r8) {
        // 0x800A653C: lui         $at, 0x420C
        ctx->r1 = S32(0X420C << 16);
            goto L_800A671C;
    }
    // 0x800A653C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800A6540: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A6544: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800A6548: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800A654C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800A6550: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800A6554: jal         0x800C48E4
    // 0x800A6558: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x800A6558: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x800A655C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A6560: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A6564: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A6568: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A656C: lwc1        $f4, 0x16C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A6570: lwc1        $f16, 0x170($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A6574: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A6578: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A657C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A6580: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800A6584: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A6588: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A658C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6590: addiu       $a3, $a3, -0x73E8
    ctx->r7 = ADD32(ctx->r7, -0X73E8);
    // 0x800A6594: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A6598: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A659C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A65A0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A65A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A65A8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800A65AC: nop

    // 0x800A65B0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800A65B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A65B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A65BC: nop

    // 0x800A65C0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A65C4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800A65C8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800A65CC: jal         0x800C49A0
    // 0x800A65D0: nop

    draw_text(rdram, ctx);
        goto after_9;
    // 0x800A65D0: nop

    after_9:
    // 0x800A65D4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A65D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A65DC: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A65E0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A65E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A65E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A65EC: lwc1        $f4, 0x16C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A65F0: lwc1        $f8, 0x170($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A65F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A65F8: lb          $t6, 0x17C($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X17C);
    // 0x800A65FC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A6600: lb          $a2, 0x17A($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X17A);
    // 0x800A6604: lb          $a3, 0x17B($v0)
    ctx->r7 = MEM_B(ctx->r2, 0X17B);
    // 0x800A6608: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A660C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800A6610: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A6614: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6618: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A661C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A6620: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A6624: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800A6628: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A662C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A6630: jal         0x800A8518
    // 0x800A6634: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    hud_timer_render(rdram, ctx);
        goto after_10;
    // 0x800A6634: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_10:
    // 0x800A6638: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A663C: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A6640: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A6644: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A6648: lwc1        $f16, 0x2EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A664C: lwc1        $f8, 0x2F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A6650: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800A6654: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A6658: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A665C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800A6660: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A6664: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6668: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A666C: addiu       $a3, $a3, -0x73E0
    ctx->r7 = ADD32(ctx->r7, -0X73E0);
    // 0x800A6670: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A6674: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A6678: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A667C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A6680: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A6684: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A6688: nop

    // 0x800A668C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A6690: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6694: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6698: nop

    // 0x800A669C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A66A0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800A66A4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A66A8: jal         0x800C49A0
    // 0x800A66AC: nop

    draw_text(rdram, ctx);
        goto after_11;
    // 0x800A66AC: nop

    after_11:
    // 0x800A66B0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800A66B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A66B8: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A66BC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800A66C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A66C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A66C8: lwc1        $f16, 0x2EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X2EC);
    // 0x800A66CC: lwc1        $f4, 0x2F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x800A66D0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A66D4: lb          $t2, 0x2FC($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X2FC);
    // 0x800A66D8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800A66DC: lb          $a2, 0x2FA($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X2FA);
    // 0x800A66E0: lb          $a3, 0x2FB($v0)
    ctx->r7 = MEM_B(ctx->r2, 0X2FB);
    // 0x800A66E4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A66E8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800A66EC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A66F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A66F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A66F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A66FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A6700: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800A6704: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A6708: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A670C: jal         0x800A8518
    // 0x800A6710: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    hud_timer_render(rdram, ctx);
        goto after_12;
    // 0x800A6710: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_12:
    // 0x800A6714: b           L_800A6790
    // 0x800A6718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A6790;
    // 0x800A6718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A671C:
    // 0x800A671C: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A6720: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A6724: lwc1        $f8, 0x16C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x800A6728: lwc1        $f4, 0x170($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X170);
    // 0x800A672C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A6730: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A6734: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A6738: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800A673C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A6740: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6744: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6748: addiu       $a3, $a3, 0x2DCC
    ctx->r7 = ADD32(ctx->r7, 0X2DCC);
    // 0x800A674C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A6750: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A6754: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A6758: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800A675C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A6760: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A6764: nop

    // 0x800A6768: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A676C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A6770: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A6774: nop

    // 0x800A6778: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A677C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800A6780: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A6784: jal         0x800C49A0
    // 0x800A6788: nop

    draw_text(rdram, ctx);
        goto after_13;
    // 0x800A6788: nop

    after_13:
    // 0x800A678C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A6790:
    // 0x800A6790: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A6794: jr          $ra
    // 0x800A6798: nop

    return;
    // 0x800A6798: nop

;}
RECOMP_FUNC void menu_asset_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CC18: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009CC1C: addiu       $t0, $t0, -0x330
    ctx->r8 = ADD32(ctx->r8, -0X330);
    // 0x8009CC20: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8009CC24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009CC28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CC2C: bne         $a2, $zero, L_8009CCC8
    if (ctx->r6 != 0) {
        // 0x8009CC30: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8009CCC8;
    }
    // 0x8009CC30: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009CC34: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8009CC38: jal         0x80076EE4
    // 0x8009CC3C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x8009CC3C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x8009CC40: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009CC44: addiu       $a1, $a1, -0x32C
    ctx->r5 = ADD32(ctx->r5, -0X32C);
    // 0x8009CC48: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8009CC4C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8009CC50: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009CC54: addiu       $t0, $t0, -0x330
    ctx->r8 = ADD32(ctx->r8, -0X330);
    // 0x8009CC58: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x8009CC5C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8009CC60: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8009CC64: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8009CC68: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8009CC6C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009CC70: beq         $a0, $t8, L_8009CCA0
    if (ctx->r4 == ctx->r24) {
        // 0x8009CC74: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8009CCA0;
    }
    // 0x8009CC74: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8009CC78: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8009CC7C:
    // 0x8009CC7C: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x8009CC80: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x8009CC84: nop

    // 0x8009CC88: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x8009CC8C: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x8009CC90: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8009CC94: nop

    // 0x8009CC98: bne         $a0, $t3, L_8009CC7C
    if (ctx->r4 != ctx->r11) {
        // 0x8009CC9C: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8009CC7C;
    }
    // 0x8009CC9C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_8009CCA0:
    // 0x8009CCA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CCA4: blez        $v1, L_8009CCC8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009CCA8: sh          $zero, -0x328($at)
        MEM_H(-0X328, ctx->r1) = 0;
            goto L_8009CCC8;
    }
    // 0x8009CCA8: sh          $zero, -0x328($at)
    MEM_H(-0X328, ctx->r1) = 0;
    // 0x8009CCAC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009CCB0: addiu       $v0, $t4, 0x6CF0
    ctx->r2 = ADD32(ctx->r12, 0X6CF0);
    // 0x8009CCB4: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
L_8009CCB8:
    // 0x8009CCB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009CCBC: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8009CCC0: bne         $at, $zero, L_8009CCB8
    if (ctx->r1 != 0) {
        // 0x8009CCC4: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_8009CCB8;
    }
    // 0x8009CCC4: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
L_8009CCC8:
    // 0x8009CCC8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8009CCCC: addiu       $t5, $t5, 0x6CF0
    ctx->r13 = ADD32(ctx->r13, 0X6CF0);
    // 0x8009CCD0: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x8009CCD4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8009CCD8: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x8009CCDC: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x8009CCE0: bne         $t8, $zero, L_8009CDD8
    if (ctx->r24 != 0) {
        // 0x8009CCE4: addu        $t1, $a2, $t9
        ctx->r9 = ADD32(ctx->r6, ctx->r25);
            goto L_8009CDD8;
    }
    // 0x8009CCE4: addu        $t1, $a2, $t9
    ctx->r9 = ADD32(ctx->r6, ctx->r25);
    // 0x8009CCE8: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x8009CCEC: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x8009CCF0: andi        $t2, $v0, 0xC000
    ctx->r10 = ctx->r2 & 0XC000;
    // 0x8009CCF4: bne         $t2, $at, L_8009CD20
    if (ctx->r10 != ctx->r1) {
        // 0x8009CCF8: andi        $t4, $v0, 0x8000
        ctx->r12 = ctx->r2 & 0X8000;
            goto L_8009CD20;
    }
    // 0x8009CCF8: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    // 0x8009CCFC: andi        $a0, $v0, 0x3FFF
    ctx->r4 = ctx->r2 & 0X3FFF;
    // 0x8009CD00: jal         0x8007B2C4
    // 0x8009CD04: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    load_texture(rdram, ctx);
        goto after_1;
    // 0x8009CD04: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x8009CD08: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009CD0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009CD10: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x8009CD14: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8009CD18: b           L_8009CDB8
    // 0x8009CD1C: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
        goto L_8009CDB8;
    // 0x8009CD1C: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
L_8009CD20:
    // 0x8009CD20: beq         $t4, $zero, L_8009CD50
    if (ctx->r12 == 0) {
        // 0x8009CD24: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_8009CD50;
    }
    // 0x8009CD24: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x8009CD28: andi        $a0, $v0, 0x3FFF
    ctx->r4 = ctx->r2 & 0X3FFF;
    // 0x8009CD2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009CD30: jal         0x8007C57C
    // 0x8009CD34: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    tex_load_sprite(rdram, ctx);
        goto after_2;
    // 0x8009CD34: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x8009CD38: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009CD3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009CD40: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x8009CD44: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8009CD48: b           L_8009CDB8
    // 0x8009CD4C: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
        goto L_8009CDB8;
    // 0x8009CD4C: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
L_8009CD50:
    // 0x8009CD50: beq         $t6, $zero, L_8009CD98
    if (ctx->r14 == 0) {
        // 0x8009CD54: andi        $a0, $v0, 0x3FFF
        ctx->r4 = ctx->r2 & 0X3FFF;
            goto L_8009CD98;
    }
    // 0x8009CD54: andi        $a0, $v0, 0x3FFF
    ctx->r4 = ctx->r2 & 0X3FFF;
    // 0x8009CD58: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8009CD5C: sb          $v0, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r2;
    // 0x8009CD60: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x8009CD64: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x8009CD68: sh          $zero, 0x30($sp)
    MEM_H(0X30, ctx->r29) = 0;
    // 0x8009CD6C: sh          $zero, 0x32($sp)
    MEM_H(0X32, ctx->r29) = 0;
    // 0x8009CD70: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8009CD74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009CD78: jal         0x8000EA54
    // 0x8009CD7C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    spawn_object(rdram, ctx);
        goto after_3;
    // 0x8009CD7C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_3:
    // 0x8009CD80: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009CD84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009CD88: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8009CD8C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8009CD90: b           L_8009CDB8
    // 0x8009CD94: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
        goto L_8009CDB8;
    // 0x8009CD94: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
L_8009CD98:
    // 0x8009CD98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009CD9C: jal         0x8005FB3C
    // 0x8009CDA0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    object_model_init(rdram, ctx);
        goto after_4;
    // 0x8009CDA0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_4:
    // 0x8009CDA4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009CDA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009CDAC: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x8009CDB0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8009CDB4: sw          $v0, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->r2;
L_8009CDB8:
    // 0x8009CDB8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8009CDBC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8009CDC0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009CDC4: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x8009CDC8: lh          $t4, -0x328($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X328);
    // 0x8009CDCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CDD0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8009CDD4: sh          $t5, -0x328($at)
    MEM_H(-0X328, ctx->r1) = ctx->r13;
L_8009CDD8:
    // 0x8009CDD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CDDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8009CDE0: jr          $ra
    // 0x8009CDE4: nop

    return;
    // 0x8009CDE4: nop

;}
RECOMP_FUNC void func_800BFE98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C03B8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C03BC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800C03C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C03C4: addiu       $t0, $t0, 0x3724
    ctx->r8 = ADD32(ctx->r8, 0X3724);
    // 0x800C03C8: addiu       $t1, $t1, 0x3720
    ctx->r9 = ADD32(ctx->r9, 0X3720);
    // 0x800C03CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C03D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C03D4: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
L_800C03D8:
    // 0x800C03D8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800C03DC: nop

    // 0x800C03E0: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    // 0x800C03E4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800C03E8: nop

    // 0x800C03EC: beq         $t7, $zero, L_800C0428
    if (ctx->r15 == 0) {
        // 0x800C03F0: nop
    
            goto L_800C0428;
    }
    // 0x800C03F0: nop

    // 0x800C03F4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800C03F8: sll         $t9, $v0, 6
    ctx->r25 = S32(ctx->r2 << 6);
    // 0x800C03FC: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x800C0400: lw          $t3, 0x1C($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X1C);
    // 0x800C0404: lhu         $t4, 0x1A($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X1A);
    // 0x800C0408: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C040C: mflo        $a1
    ctx->r5 = lo;
    // 0x800C0410: srl         $t5, $a1, 4
    ctx->r13 = S32(U32(ctx->r5) >> 4);
    // 0x800C0414: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800C0418: sh          $t6, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r14;
    // 0x800C041C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800C0420: nop

    // 0x800C0424: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
L_800C0428:
    // 0x800C0428: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x800C042C: nop

    // 0x800C0430: beq         $t8, $zero, L_800C046C
    if (ctx->r24 == 0) {
        // 0x800C0434: nop
    
            goto L_800C046C;
    }
    // 0x800C0434: nop

    // 0x800C0438: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800C043C: sll         $t3, $v0, 6
    ctx->r11 = S32(ctx->r2 << 6);
    // 0x800C0440: addu        $a2, $t9, $t3
    ctx->r6 = ADD32(ctx->r25, ctx->r11);
    // 0x800C0444: lw          $t4, 0x5C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X5C);
    // 0x800C0448: lhu         $t5, 0x5A($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X5A);
    // 0x800C044C: multu       $t4, $a3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C0450: mflo        $a1
    ctx->r5 = lo;
    // 0x800C0454: srl         $t6, $a1, 4
    ctx->r14 = S32(U32(ctx->r5) >> 4);
    // 0x800C0458: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800C045C: sh          $t7, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r15;
    // 0x800C0460: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800C0464: nop

    // 0x800C0468: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
L_800C046C:
    // 0x800C046C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C0470: nop

    // 0x800C0474: beq         $t9, $zero, L_800C04B0
    if (ctx->r25 == 0) {
        // 0x800C0478: nop
    
            goto L_800C04B0;
    }
    // 0x800C0478: nop

    // 0x800C047C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800C0480: sll         $t4, $v0, 6
    ctx->r12 = S32(ctx->r2 << 6);
    // 0x800C0484: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x800C0488: lw          $t5, 0x9C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X9C);
    // 0x800C048C: lhu         $t6, 0x9A($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X9A);
    // 0x800C0490: multu       $t5, $a3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C0494: mflo        $a1
    ctx->r5 = lo;
    // 0x800C0498: srl         $t7, $a1, 4
    ctx->r15 = S32(U32(ctx->r5) >> 4);
    // 0x800C049C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800C04A0: sh          $t8, 0x9A($a2)
    MEM_H(0X9A, ctx->r6) = ctx->r24;
    // 0x800C04A4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800C04A8: nop

    // 0x800C04AC: addu        $a0, $t9, $v1
    ctx->r4 = ADD32(ctx->r25, ctx->r3);
L_800C04B0:
    // 0x800C04B0: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800C04B4: nop

    // 0x800C04B8: beq         $t3, $zero, L_800C04E8
    if (ctx->r11 == 0) {
        // 0x800C04BC: nop
    
            goto L_800C04E8;
    }
    // 0x800C04BC: nop

    // 0x800C04C0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800C04C4: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x800C04C8: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x800C04CC: lw          $t6, 0xDC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XDC);
    // 0x800C04D0: lhu         $t7, 0xDA($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XDA);
    // 0x800C04D4: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C04D8: mflo        $a1
    ctx->r5 = lo;
    // 0x800C04DC: srl         $t8, $a1, 4
    ctx->r24 = S32(U32(ctx->r5) >> 4);
    // 0x800C04E0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C04E4: sh          $t9, 0xDA($a2)
    MEM_H(0XDA, ctx->r6) = ctx->r25;
L_800C04E8:
    // 0x800C04E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C04EC: bne         $v0, $t2, L_800C03D8
    if (ctx->r2 != ctx->r10) {
        // 0x800C04F0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800C03D8;
    }
    // 0x800C04F0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800C04F4: jr          $ra
    // 0x800C04F8: nop

    return;
    // 0x800C04F8: nop

;}
RECOMP_FUNC void snow_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC628: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800AC62C: addiu       $t1, $t1, -0x7E90
    ctx->r9 = ADD32(ctx->r9, -0X7E90);
    // 0x800AC630: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800AC634: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800AC638: blez        $t6, L_800AC774
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AC63C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800AC774;
    }
    // 0x800AC63C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AC640: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800AC644: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AC648: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AC64C: addiu       $t2, $t2, 0x2E64
    ctx->r10 = ADD32(ctx->r10, 0X2E64);
    // 0x800AC650: addiu       $t4, $t4, 0x2E68
    ctx->r12 = ADD32(ctx->r12, 0X2E68);
    // 0x800AC654: addiu       $t5, $t5, -0x7E88
    ctx->r13 = ADD32(ctx->r13, -0X7E88);
    // 0x800AC658: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AC65C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
L_800AC660:
    // 0x800AC660: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800AC664: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800AC668: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x800AC66C: lbu         $t8, 0xF($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XF);
    // 0x800AC670: nop

    // 0x800AC674: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC678: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x800AC67C: mflo        $t9
    ctx->r25 = lo;
    // 0x800AC680: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x800AC684: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AC688: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AC68C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800AC690: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC694: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800AC698: mflo        $t8
    ctx->r24 = lo;
    // 0x800AC69C: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AC6A0: lw          $t8, 0x18($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X18);
    // 0x800AC6A4: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x800AC6A8: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x800AC6AC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800AC6B0: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800AC6B4: lw          $t8, 0x18($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X18);
    // 0x800AC6B8: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x800AC6BC: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x800AC6C0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AC6C4: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800AC6C8: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC6CC: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800AC6D0: mflo        $t8
    ctx->r24 = lo;
    // 0x800AC6D4: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AC6D8: lw          $t8, 0x1C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X1C);
    // 0x800AC6DC: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800AC6E0: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x800AC6E4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800AC6E8: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800AC6EC: lw          $t8, 0x24($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X24);
    // 0x800AC6F0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800AC6F4: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
    // 0x800AC6F8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800AC6FC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800AC700: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC704: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x800AC708: mflo        $t8
    ctx->r24 = lo;
    // 0x800AC70C: sra         $t7, $t8, 1
    ctx->r15 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800AC710: lw          $t8, 0x20($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X20);
    // 0x800AC714: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x800AC718: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x800AC71C: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800AC720: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800AC724: nop

    // 0x800AC728: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x800AC72C: lbu         $t6, 0xF($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF);
    // 0x800AC730: nop

    // 0x800AC734: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800AC738: sb          $t8, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r24;
    // 0x800AC73C: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800AC740: lw          $t0, 0x4($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X4);
    // 0x800AC744: addu        $a1, $t9, $a0
    ctx->r5 = ADD32(ctx->r25, ctx->r4);
    // 0x800AC748: lbu         $a3, 0xF($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0XF);
    // 0x800AC74C: nop

    // 0x800AC750: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800AC754: bne         $at, $zero, L_800AC760
    if (ctx->r1 != 0) {
        // 0x800AC758: subu        $t7, $a3, $t0
        ctx->r15 = SUB32(ctx->r7, ctx->r8);
            goto L_800AC760;
    }
    // 0x800AC758: subu        $t7, $a3, $t0
    ctx->r15 = SUB32(ctx->r7, ctx->r8);
    // 0x800AC75C: sb          $t7, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r15;
L_800AC760:
    // 0x800AC760: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800AC764: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800AC768: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AC76C: bne         $at, $zero, L_800AC660
    if (ctx->r1 != 0) {
        // 0x800AC770: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800AC660;
    }
    // 0x800AC770: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_800AC774:
    // 0x800AC774: jr          $ra
    // 0x800AC778: nop

    return;
    // 0x800AC778: nop

;}
RECOMP_FUNC void unset_temp_model_transforms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013548: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8001354C: nop

    // 0x80013550: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80013554: bne         $t7, $zero, L_800135B0
    if (ctx->r15 != 0) {
        // 0x80013558: nop
    
            goto L_800135B0;
    }
    // 0x80013558: nop

    // 0x8001355C: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80013560: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80013564: lb          $t9, 0x54($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X54);
    // 0x80013568: nop

    // 0x8001356C: bne         $t9, $at, L_800135B0
    if (ctx->r25 != ctx->r1) {
        // 0x80013570: nop
    
            goto L_800135B0;
    }
    // 0x80013570: nop

    // 0x80013574: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80013578: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001357C: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80013580: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80013584: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80013588: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001358C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80013590: lwc1        $f16, 0x7C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80013594: nop

    // 0x80013598: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8001359C: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x800135A0: lwc1        $f6, 0x80($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X80);
    // 0x800135A4: nop

    // 0x800135A8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800135AC: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
L_800135B0:
    // 0x800135B0: jr          $ra
    // 0x800135B4: nop

    return;
    // 0x800135B4: nop

;}
RECOMP_FUNC void obj_init_property_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023E64: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80023E68: sltiu       $at, $t6, 0x74
    ctx->r1 = ctx->r14 < 0X74 ? 1 : 0;
    // 0x80023E6C: beq         $at, $zero, L_80023F74
    if (ctx->r1 == 0) {
        // 0x80023E70: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80023F74;
    }
    // 0x80023E70: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80023E74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80023E78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80023E7C: addu        $at, $at, $t6
    gpr jr_addend_80023E88 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80023E80: lw          $t6, 0x5FCC($at)
    ctx->r14 = ADD32(ctx->r1, 0X5FCC);
    // 0x80023E84: nop

    // 0x80023E88: jr          $t6
    // 0x80023E8C: nop

    switch (jr_addend_80023E88 >> 2) {
        case 0: goto L_80023E90; break;
        case 1: goto L_80023E98; break;
        case 2: goto L_80023F74; break;
        case 3: goto L_80023F74; break;
        case 4: goto L_80023EA0; break;
        case 5: goto L_80023F74; break;
        case 6: goto L_80023F48; break;
        case 7: goto L_80023F74; break;
        case 8: goto L_80023F74; break;
        case 9: goto L_80023F74; break;
        case 10: goto L_80023F74; break;
        case 11: goto L_80023EA8; break;
        case 12: goto L_80023F48; break;
        case 13: goto L_80023EB0; break;
        case 14: goto L_80023F74; break;
        case 15: goto L_80023F74; break;
        case 16: goto L_80023EB8; break;
        case 17: goto L_80023F48; break;
        case 18: goto L_80023F74; break;
        case 19: goto L_80023F74; break;
        case 20: goto L_80023F74; break;
        case 21: goto L_80023F74; break;
        case 22: goto L_80023F74; break;
        case 23: goto L_80023ED0; break;
        case 24: goto L_80023F74; break;
        case 25: goto L_80023F48; break;
        case 26: goto L_80023F74; break;
        case 27: goto L_80023F74; break;
        case 28: goto L_80023F74; break;
        case 29: goto L_80023F48; break;
        case 30: goto L_80023ED8; break;
        case 31: goto L_80023EE0; break;
        case 32: goto L_80023F74; break;
        case 33: goto L_80023F74; break;
        case 34: goto L_80023F74; break;
        case 35: goto L_80023F48; break;
        case 36: goto L_80023F74; break;
        case 37: goto L_80023EF0; break;
        case 38: goto L_80023EF8; break;
        case 39: goto L_80023F00; break;
        case 40: goto L_80023F48; break;
        case 41: goto L_80023F74; break;
        case 42: goto L_80023F74; break;
        case 43: goto L_80023F74; break;
        case 44: goto L_80023F08; break;
        case 45: goto L_80023F74; break;
        case 46: goto L_80023F74; break;
        case 47: goto L_80023F10; break;
        case 48: goto L_80023F58; break;
        case 49: goto L_80023F20; break;
        case 50: goto L_80023F58; break;
        case 51: goto L_80023F48; break;
        case 52: goto L_80023F74; break;
        case 53: goto L_80023F28; break;
        case 54: goto L_80023F48; break;
        case 55: goto L_80023F20; break;
        case 56: goto L_80023F48; break;
        case 57: goto L_80023F74; break;
        case 58: goto L_80023F74; break;
        case 59: goto L_80023F74; break;
        case 60: goto L_80023F58; break;
        case 61: goto L_80023F60; break;
        case 62: goto L_80023F18; break;
        case 63: goto L_80023EE0; break;
        case 64: goto L_80023F74; break;
        case 65: goto L_80023F74; break;
        case 66: goto L_80023EE8; break;
        case 67: goto L_80023F48; break;
        case 68: goto L_80023F74; break;
        case 69: goto L_80023EC0; break;
        case 70: goto L_80023F74; break;
        case 71: goto L_80023EC0; break;
        case 72: goto L_80023F74; break;
        case 73: goto L_80023F30; break;
        case 74: goto L_80023F74; break;
        case 75: goto L_80023F74; break;
        case 76: goto L_80023EB8; break;
        case 77: goto L_80023F48; break;
        case 78: goto L_80023F48; break;
        case 79: goto L_80023F20; break;
        case 80: goto L_80023F40; break;
        case 81: goto L_80023F50; break;
        case 82: goto L_80023F74; break;
        case 83: goto L_80023F20; break;
        case 84: goto L_80023F74; break;
        case 85: goto L_80023F20; break;
        case 86: goto L_80023F74; break;
        case 87: goto L_80023EE0; break;
        case 88: goto L_80023F74; break;
        case 89: goto L_80023F74; break;
        case 90: goto L_80023F38; break;
        case 91: goto L_80023F74; break;
        case 92: goto L_80023F48; break;
        case 93: goto L_80023F74; break;
        case 94: goto L_80023F30; break;
        case 95: goto L_80023EC0; break;
        case 96: goto L_80023EC0; break;
        case 97: goto L_80023F48; break;
        case 98: goto L_80023F30; break;
        case 99: goto L_80023F30; break;
        case 100: goto L_80023EC8; break;
        case 101: goto L_80023EC8; break;
        case 102: goto L_80023EC8; break;
        case 103: goto L_80023EC8; break;
        case 104: goto L_80023F74; break;
        case 105: goto L_80023F74; break;
        case 106: goto L_80023F74; break;
        case 107: goto L_80023F48; break;
        case 108: goto L_80023F68; break;
        case 109: goto L_80023EE0; break;
        case 110: goto L_80023EB0; break;
        case 111: goto L_80023F74; break;
        case 112: goto L_80023F74; break;
        case 113: goto L_80023F70; break;
        case 114: goto L_80023F20; break;
        case 115: goto L_80023F48; break;
        default: switch_error(__func__, 0x80023E88, 0x800E5FCC);
    }
    // 0x80023E8C: nop

L_80023E90:
    // 0x80023E90: jr          $ra
    // 0x80023E94: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    return;
    // 0x80023E94: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_80023E98:
    // 0x80023E98: jr          $ra
    // 0x80023E9C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    return;
    // 0x80023E9C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_80023EA0:
    // 0x80023EA0: jr          $ra
    // 0x80023EA4: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    return;
    // 0x80023EA4: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_80023EA8:
    // 0x80023EA8: jr          $ra
    // 0x80023EAC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80023EAC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80023EB0:
    // 0x80023EB0: jr          $ra
    // 0x80023EB4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    return;
    // 0x80023EB4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_80023EB8:
    // 0x80023EB8: jr          $ra
    // 0x80023EBC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023EBC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023EC0:
    // 0x80023EC0: jr          $ra
    // 0x80023EC4: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    return;
    // 0x80023EC4: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
L_80023EC8:
    // 0x80023EC8: jr          $ra
    // 0x80023ECC: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
    return;
    // 0x80023ECC: addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
L_80023ED0:
    // 0x80023ED0: jr          $ra
    // 0x80023ED4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80023ED4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80023ED8:
    // 0x80023ED8: jr          $ra
    // 0x80023EDC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80023EDC: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80023EE0:
    // 0x80023EE0: jr          $ra
    // 0x80023EE4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023EE4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023EE8:
    // 0x80023EE8: jr          $ra
    // 0x80023EEC: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    return;
    // 0x80023EEC: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_80023EF0:
    // 0x80023EF0: jr          $ra
    // 0x80023EF4: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    return;
    // 0x80023EF4: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
L_80023EF8:
    // 0x80023EF8: jr          $ra
    // 0x80023EFC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023EFC: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023F00:
    // 0x80023F00: jr          $ra
    // 0x80023F04: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x80023F04: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80023F08:
    // 0x80023F08: jr          $ra
    // 0x80023F0C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023F0C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023F10:
    // 0x80023F10: jr          $ra
    // 0x80023F14: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x80023F14: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80023F18:
    // 0x80023F18: jr          $ra
    // 0x80023F1C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x80023F1C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80023F20:
    // 0x80023F20: jr          $ra
    // 0x80023F24: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80023F24: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80023F28:
    // 0x80023F28: jr          $ra
    // 0x80023F2C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80023F2C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80023F30:
    // 0x80023F30: jr          $ra
    // 0x80023F34: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    return;
    // 0x80023F34: addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
L_80023F38:
    // 0x80023F38: jr          $ra
    // 0x80023F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80023F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80023F40:
    // 0x80023F40: jr          $ra
    // 0x80023F44: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    return;
    // 0x80023F44: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80023F48:
    // 0x80023F48: jr          $ra
    // 0x80023F4C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x80023F4C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80023F50:
    // 0x80023F50: jr          $ra
    // 0x80023F54: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    return;
    // 0x80023F54: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80023F58:
    // 0x80023F58: jr          $ra
    // 0x80023F5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80023F5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80023F60:
    // 0x80023F60: jr          $ra
    // 0x80023F64: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    return;
    // 0x80023F64: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80023F68:
    // 0x80023F68: jr          $ra
    // 0x80023F6C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80023F6C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_80023F70:
    // 0x80023F70: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80023F74:
    // 0x80023F74: jr          $ra
    // 0x80023F78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80023F78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void render_object_parts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001348C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80013490: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013494: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80013498: jal         0x80012F94
    // 0x8001349C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    set_temp_model_transforms(rdram, ctx);
        goto after_0;
    // 0x8001349C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800134A0: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x800134A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800134A8: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x800134AC: beq         $t7, $zero, L_800134DC
    if (ctx->r15 == 0) {
        // 0x800134B0: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800134DC;
    }
    // 0x800134B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800134B4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800134B8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800134BC: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x800134C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800134C4: addiu       $a3, $a3, -0x4BEC
    ctx->r7 = ADD32(ctx->r7, -0X4BEC);
    // 0x800134C8: addiu       $a2, $a2, -0x4BF0
    ctx->r6 = ADD32(ctx->r6, -0X4BF0);
    // 0x800134CC: jal         0x800B3CA0
    // 0x800134D0: addiu       $a1, $a1, -0x4BF4
    ctx->r5 = ADD32(ctx->r5, -0X4BF4);
    render_particle(rdram, ctx);
        goto after_1;
    // 0x800134D0: addiu       $a1, $a1, -0x4BF4
    ctx->r5 = ADD32(ctx->r5, -0X4BF4);
    after_1:
    // 0x800134D4: b           L_80013530
    // 0x800134D8: nop

        goto L_80013530;
    // 0x800134D8: nop

L_800134DC:
    // 0x800134DC: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x800134E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800134E4: lb          $v0, 0x53($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X53);
    // 0x800134E8: nop

    // 0x800134EC: bne         $v0, $zero, L_80013504
    if (ctx->r2 != 0) {
        // 0x800134F0: nop
    
            goto L_80013504;
    }
    // 0x800134F0: nop

    // 0x800134F4: jal         0x800120C8
    // 0x800134F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    render_3d_model(rdram, ctx);
        goto after_2;
    // 0x800134F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800134FC: b           L_80013530
    // 0x80013500: nop

        goto L_80013530;
    // 0x80013500: nop

L_80013504:
    // 0x80013504: bne         $v0, $at, L_80013520
    if (ctx->r2 != ctx->r1) {
        // 0x80013508: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80013520;
    }
    // 0x80013508: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001350C: jal         0x80011C94
    // 0x80013510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    render_3d_billboard(rdram, ctx);
        goto after_3;
    // 0x80013510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80013514: b           L_80013530
    // 0x80013518: nop

        goto L_80013530;
    // 0x80013518: nop

    // 0x8001351C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80013520:
    // 0x80013520: bne         $v0, $at, L_80013530
    if (ctx->r2 != ctx->r1) {
        // 0x80013524: nop
    
            goto L_80013530;
    }
    // 0x80013524: nop

    // 0x80013528: jal         0x80011AD0
    // 0x8001352C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    render_3d_misc(rdram, ctx);
        goto after_4;
    // 0x8001352C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80013530:
    // 0x80013530: jal         0x80013548
    // 0x80013534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    unset_temp_model_transforms(rdram, ctx);
        goto after_5;
    // 0x80013534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80013538: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001353C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80013540: jr          $ra
    // 0x80013544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80013544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80026070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800260B0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800260B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800260B8: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800260BC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800260C0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800260C4: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800260C8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800260CC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800260D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800260D4: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800260D8: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800260DC: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800260E0: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x800260E4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800260E8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800260EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800260F0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800260F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800260F8: addiu       $t4, $sp, 0x40
    ctx->r12 = ADD32(ctx->r29, 0X40);
    // 0x800260FC: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x80026100: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x80026104: addiu       $t3, $sp, 0x80
    ctx->r11 = ADD32(ctx->r29, 0X80);
    // 0x80026108: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8002610C: addiu       $t2, $sp, 0x70
    ctx->r10 = ADD32(ctx->r29, 0X70);
    // 0x80026110: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026114: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x80026118: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x8002611C: lh          $t9, 0x4($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4);
    // 0x80026120: nop

    // 0x80026124: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80026128: nop

    // 0x8002612C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026130: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x80026134: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80026138: nop

    // 0x8002613C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80026140: nop

    // 0x80026144: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026148: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x8002614C: lh          $t7, 0xA($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XA);
    // 0x80026150: nop

    // 0x80026154: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80026158: nop

    // 0x8002615C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026160: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x80026164: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x80026168: nop

    // 0x8002616C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80026170: nop

    // 0x80026174: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026178: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x8002617C: lh          $t9, 0xA($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XA);
    // 0x80026180: nop

    // 0x80026184: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80026188: nop

    // 0x8002618C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026190: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
L_80026194:
    // 0x80026194: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80026198: addu        $t6, $t2, $v0
    ctx->r14 = ADD32(ctx->r10, ctx->r2);
    // 0x8002619C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800261A0: addu        $t7, $t3, $v0
    ctx->r15 = ADD32(ctx->r11, ctx->r2);
    // 0x800261A4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800261A8: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800261AC: addu        $t8, $t1, $v0
    ctx->r24 = ADD32(ctx->r9, ctx->r2);
    // 0x800261B0: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x800261B4: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800261B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800261BC: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x800261C0: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800261C4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800261C8: add.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800261CC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800261D0: c.le.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d <= ctx->f2.d;
    // 0x800261D4: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x800261D8: bc1f        L_800261E4
    if (!c1cs) {
        // 0x800261DC: nop
    
            goto L_800261E4;
    }
    // 0x800261DC: nop

    // 0x800261E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_800261E4:
    // 0x800261E4: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800261E8: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800261EC: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800261F0: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x800261F4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800261F8: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800261FC: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80026200: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026204: bne         $at, $zero, L_80026194
    if (ctx->r1 != 0) {
        // 0x80026208: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_80026194;
    }
    // 0x80026208: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8002620C: beq         $t9, $zero, L_8002645C
    if (ctx->r25 == 0) {
        // 0x80026210: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8002645C;
    }
    // 0x80026210: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80026214: beq         $t9, $at, L_8002645C
    if (ctx->r25 == ctx->r1) {
        // 0x80026218: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8002645C;
    }
    // 0x80026218: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002621C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80026220: addiu       $ra, $sp, 0x4C
    ctx->r31 = ADD32(ctx->r29, 0X4C);
    // 0x80026224: addiu       $t5, $sp, 0x54
    ctx->r13 = ADD32(ctx->r29, 0X54);
L_80026228:
    // 0x80026228: addiu       $a2, $a1, 0x1
    ctx->r6 = ADD32(ctx->r5, 0X1);
    // 0x8002622C: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x80026230: sll         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6 << 16);
    // 0x80026234: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80026238: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002623C: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80026240: bne         $at, $zero, L_8002624C
    if (ctx->r1 != 0) {
        // 0x80026244: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_8002624C;
    }
    // 0x80026244: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80026248: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8002624C:
    // 0x8002624C: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x80026250: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x80026254: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80026258: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8002625C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80026260: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80026264: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80026268: beq         $t9, $t8, L_800262E0
    if (ctx->r25 == ctx->r24) {
        // 0x8002626C: addu        $t7, $t1, $v0
        ctx->r15 = ADD32(ctx->r9, ctx->r2);
            goto L_800262E0;
    }
    // 0x8002626C: addu        $t7, $t1, $v0
    ctx->r15 = ADD32(ctx->r9, ctx->r2);
    // 0x80026270: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x80026274: addu        $t9, $t1, $v1
    ctx->r25 = ADD32(ctx->r9, ctx->r3);
    // 0x80026278: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8002627C: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80026280: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x80026284: sub.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80026288: addu        $t8, $t3, $v0
    ctx->r24 = ADD32(ctx->r11, ctx->r2);
    // 0x8002628C: div.s       $f14, $f12, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80026290: lwc1        $f2, 0x0($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80026294: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80026298: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x8002629C: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800262A0: addu        $t7, $t5, $a0
    ctx->r15 = ADD32(ctx->r13, ctx->r4);
    // 0x800262A4: addu        $t8, $t2, $v1
    ctx->r24 = ADD32(ctx->r10, ctx->r3);
    // 0x800262A8: addu        $t9, $t2, $v0
    ctx->r25 = ADD32(ctx->r10, ctx->r2);
    // 0x800262AC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800262B0: addu        $t6, $ra, $a0
    ctx->r14 = ADD32(ctx->r31, ctx->r4);
    // 0x800262B4: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800262B8: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800262BC: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800262C0: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800262C4: lwc1        $f0, 0x0($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800262C8: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800262CC: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800262D0: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800262D4: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800262D8: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800262DC: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
L_800262E0:
    // 0x800262E0: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x800262E4: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800262E8: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800262EC: bne         $at, $zero, L_80026228
    if (ctx->r1 != 0) {
        // 0x800262F0: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_80026228;
    }
    // 0x800262F0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800262F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800262F8: bne         $t0, $at, L_8002645C
    if (ctx->r8 != ctx->r1) {
        // 0x800262FC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8002645C;
    }
    // 0x800262FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80026300: lwc1        $f0, -0x25DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25DC);
    // 0x80026304: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80026308: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002630C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80026310: lwc1        $f2, -0x25E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X25E0);
    // 0x80026314: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80026318: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002631C: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80026320: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80026324: lwc1        $f12, -0x25D8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X25D8);
    // 0x80026328: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002632C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80026330: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80026334: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80026338: add.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8002633C: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80026340: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80026344: add.s       $f18, $f6, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80026348: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8002634C: nop

    // 0x80026350: bc1f        L_80026364
    if (!c1cs) {
        // 0x80026354: nop
    
            goto L_80026364;
    }
    // 0x80026354: nop

    // 0x80026358: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x8002635C: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x80026360: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
L_80026364:
    // 0x80026364: lwc1        $f13, 0x63F8($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X63F8);
    // 0x80026368: lwc1        $f12, 0x63FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X63FC);
    // 0x8002636C: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x80026370: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80026374: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80026378: bc1t        L_8002645C
    if (c1cs) {
        // 0x8002637C: swc1        $f18, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
            goto L_8002645C;
    }
    // 0x8002637C: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x80026380: lwc1        $f15, 0x6400($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, 0X6400);
    // 0x80026384: lwc1        $f14, 0x6404($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6404);
    // 0x80026388: cvt.d.s     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.d = CVT_D_S(ctx->f16.fl);
    // 0x8002638C: c.lt.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d < ctx->f2.d;
    // 0x80026390: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x80026394: bc1t        L_8002645C
    if (c1cs) {
        // 0x80026398: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_8002645C;
    }
    // 0x80026398: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8002639C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    // 0x800263A0: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x800263A4: bc1f        L_800263B8
    if (!c1cs) {
        // 0x800263A8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800263B8;
    }
    // 0x800263A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800263AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800263B0: nop

    // 0x800263B4: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
L_800263B8:
    // 0x800263B8: c.lt.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d < ctx->f0.d;
    // 0x800263BC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800263C0: bc1f        L_800263D4
    if (!c1cs) {
        // 0x800263C4: nop
    
            goto L_800263D4;
    }
    // 0x800263C4: nop

    // 0x800263C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800263CC: nop

    // 0x800263D0: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
L_800263D4:
    // 0x800263D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800263D8: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800263DC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800263E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800263E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800263E8: lw          $t8, -0x3178($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3178);
    // 0x800263EC: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800263F0: lh          $a1, 0x40($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X40);
    // 0x800263F4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800263F8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800263FC: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x80026400: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80026404: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80026408: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002640C: jal         0x80026C54
    // 0x80026410: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_80026C14(rdram, ctx);
        goto after_0;
    // 0x80026410: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x80026414: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80026418: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8002641C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80026420: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80026424: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80026428: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8002642C: lw          $t7, -0x3178($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3178);
    // 0x80026430: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80026434: lh          $a1, 0x40($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X40);
    // 0x80026438: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8002643C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026440: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x80026444: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80026448: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x8002644C: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026450: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80026454: jal         0x80026C54
    // 0x80026458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80026C14(rdram, ctx);
        goto after_1;
    // 0x80026458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_8002645C:
    // 0x8002645C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026460: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80026464: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80026468: jr          $ra
    // 0x8002646C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8002646C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void menu_boot_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008896C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80088970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088974: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088978: jal         0x800C06F8
    // 0x8008897C: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8008897C: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_0:
    // 0x80088980: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80088984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088988: jal         0x80077F84
    // 0x8008898C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bgdraw_primcolour(rdram, ctx);
        goto after_1;
    // 0x8008898C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80088990: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088994: jal         0x8009CBB8
    // 0x80088998: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x80088998: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    after_2:
    // 0x8008899C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800889A0: lh          $t6, -0x2BC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2BC);
    // 0x800889A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800889A8: addiu       $a0, $a0, 0x6AF0
    ctx->r4 = ADD32(ctx->r4, 0X6AF0);
    // 0x800889AC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800889B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800889B4: lh          $t0, -0x2BA($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2BA);
    // 0x800889B8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800889BC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800889C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800889C4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800889C8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800889CC: lh          $t4, -0x2B8($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X2B8);
    // 0x800889D0: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x800889D4: sw          $t9, -0x2A4($at)
    MEM_W(-0X2A4, ctx->r1) = ctx->r25;
    // 0x800889D8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800889DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800889E0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800889E4: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800889E8: sw          $t3, -0x29C($at)
    MEM_W(-0X29C, ctx->r1) = ctx->r11;
    // 0x800889EC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800889F0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800889F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800889F8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800889FC: addiu       $a1, $a1, -0x2A6
    ctx->r5 = ADD32(ctx->r5, -0X2A6);
    // 0x80088A00: addiu       $v0, $v0, -0x2B6
    ctx->r2 = ADD32(ctx->r2, -0X2B6);
    // 0x80088A04: addiu       $v1, $v1, -0x28C
    ctx->r3 = ADD32(ctx->r3, -0X28C);
    // 0x80088A08: sw          $t7, -0x294($at)
    MEM_W(-0X294, ctx->r1) = ctx->r15;
L_80088A0C:
    // 0x80088A0C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80088A10: lh          $t2, 0x2($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2);
    // 0x80088A14: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80088A18: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80088A1C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80088A20: lh          $t0, 0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X6);
    // 0x80088A24: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80088A28: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80088A2C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80088A30: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80088A34: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80088A38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80088A3C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80088A40: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80088A44: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80088A48: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80088A4C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80088A50: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80088A54: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80088A58: sw          $t5, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r13;
    // 0x80088A5C: sw          $t3, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r11;
    // 0x80088A60: bne         $v0, $a1, L_80088A0C
    if (ctx->r2 != ctx->r5) {
        // 0x80088A64: sw          $t9, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = ctx->r25;
            goto L_80088A0C;
    }
    // 0x80088A64: sw          $t9, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r25;
    // 0x80088A68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088A70: sw          $zero, 0x71E0($at)
    MEM_W(0X71E0, ctx->r1) = 0;
    // 0x80088A74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088A78: sw          $zero, 0x71D8($at)
    MEM_W(0X71D8, ctx->r1) = 0;
    // 0x80088A7C: jr          $ra
    // 0x80088A80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80088A80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void music_jingle_playing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001C08: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80001C0C: lbu         $v1, 0x6285($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6285);
    // 0x80001C10: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001C14: beq         $v1, $zero, L_80001C4C
    if (ctx->r3 == 0) {
        // 0x80001C18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80001C4C;
    }
    // 0x80001C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80001C1C: lbu         $t6, -0x344C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X344C);
    // 0x80001C20: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80001C24: beq         $t6, $zero, L_80001C4C
    if (ctx->r14 == 0) {
        // 0x80001C28: nop
    
            goto L_80001C4C;
    }
    // 0x80001C28: nop

    // 0x80001C2C: lw          $t7, -0x345C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X345C);
    // 0x80001C30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001C34: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80001C38: nop

    // 0x80001C3C: bne         $t8, $at, L_80001C4C
    if (ctx->r24 != ctx->r1) {
        // 0x80001C40: nop
    
            goto L_80001C4C;
    }
    // 0x80001C40: nop

    // 0x80001C44: jr          $ra
    // 0x80001C48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80001C48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80001C4C:
    // 0x80001C4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001C50: sb          $zero, -0x344C($at)
    MEM_B(-0X344C, ctx->r1) = 0;
    // 0x80001C54: jr          $ra
    // 0x80001C58: nop

    return;
    // 0x80001C58: nop

;}
RECOMP_FUNC void func_800BBE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC328: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800BC32C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800BC330: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800BC334: lh          $a2, 0x1A($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1A);
    // 0x800BC338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BC33C: blez        $a2, L_800BC3CC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BC340: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BC3CC;
    }
    // 0x800BC340: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BC344: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800BC348: sll         $t7, $zero, 6
    ctx->r15 = S32(0 << 6);
    // 0x800BC34C: lui         $s1, 0x100
    ctx->r17 = S32(0X100 << 16);
    // 0x800BC350: lui         $s0, 0x100
    ctx->r16 = S32(0X100 << 16);
    // 0x800BC354: ori         $s0, $s0, 0x2000
    ctx->r16 = ctx->r16 | 0X2000;
    // 0x800BC358: ori         $s1, $s1, 0x2100
    ctx->r17 = ctx->r17 | 0X2100;
    // 0x800BC35C: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x800BC360: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_800BC364:
    // 0x800BC364: bne         $v0, $zero, L_800BC3B4
    if (ctx->r2 != 0) {
        // 0x800BC368: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800BC3B4;
    }
    // 0x800BC368: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800BC36C: lh          $t2, 0x20($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X20);
    // 0x800BC370: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x800BC374: blez        $t2, L_800BC3B4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800BC378: subu        $t4, $t4, $zero
        ctx->r12 = SUB32(ctx->r12, 0);
            goto L_800BC3B4;
    }
    // 0x800BC378: subu        $t4, $t4, $zero
    ctx->r12 = SUB32(ctx->r12, 0);
    // 0x800BC37C: lw          $t3, 0xC($a3)
    ctx->r11 = MEM_W(ctx->r7, 0XC);
    // 0x800BC380: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800BC384: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
L_800BC388:
    // 0x800BC388: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x800BC38C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800BC390: and         $t9, $t8, $s1
    ctx->r25 = ctx->r24 & ctx->r17;
    // 0x800BC394: bne         $s0, $t9, L_800BC3A0
    if (ctx->r16 != ctx->r25) {
        // 0x800BC398: addiu       $t5, $t5, 0xC
        ctx->r13 = ADD32(ctx->r13, 0XC);
            goto L_800BC3A0;
    }
    // 0x800BC398: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800BC39C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_800BC3A0:
    // 0x800BC3A0: bne         $v0, $zero, L_800BC3B4
    if (ctx->r2 != 0) {
        // 0x800BC3A4: addiu       $t4, $t4, 0xC
        ctx->r12 = ADD32(ctx->r12, 0XC);
            goto L_800BC3B4;
    }
    // 0x800BC3A4: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x800BC3A8: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BC3AC: bne         $at, $zero, L_800BC388
    if (ctx->r1 != 0) {
        // 0x800BC3B0: nop
    
            goto L_800BC388;
    }
    // 0x800BC3B0: nop

L_800BC3B4:
    // 0x800BC3B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BC3B8: bne         $v0, $zero, L_800BC3CC
    if (ctx->r2 != 0) {
        // 0x800BC3BC: addiu       $t0, $t0, 0x44
        ctx->r8 = ADD32(ctx->r8, 0X44);
            goto L_800BC3CC;
    }
    // 0x800BC3BC: addiu       $t0, $t0, 0x44
    ctx->r8 = ADD32(ctx->r8, 0X44);
    // 0x800BC3C0: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BC3C4: bne         $at, $zero, L_800BC364
    if (ctx->r1 != 0) {
        // 0x800BC3C8: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_800BC364;
    }
    // 0x800BC3C8: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_800BC3CC:
    // 0x800BC3CC: bne         $v0, $zero, L_800BC3DC
    if (ctx->r2 != 0) {
        // 0x800BC3D0: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_800BC3DC;
    }
    // 0x800BC3D0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800BC3D4: b           L_800BC3DC
    // 0x800BC3D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800BC3DC;
    // 0x800BC3D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800BC3DC:
    // 0x800BC3DC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800BC3E0: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800BC3E4: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x800BC3E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800BC3EC: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800BC3F0: lh          $t8, 0x6($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X6);
    // 0x800BC3F4: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800BC3F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC3FC: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x800BC400: sw          $t6, -0x5998($at)
    MEM_W(-0X5998, ctx->r1) = ctx->r14;
    // 0x800BC404: lh          $t8, 0x4($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X4);
    // 0x800BC408: lh          $t7, 0xA($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XA);
    // 0x800BC40C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC410: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800BC414: sw          $t9, -0x5994($at)
    MEM_W(-0X5994, ctx->r1) = ctx->r25;
    // 0x800BC418: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800BC41C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC420: sw          $t6, -0x5990($at)
    MEM_W(-0X5990, ctx->r1) = ctx->r14;
    // 0x800BC424: lh          $t7, 0x4($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X4);
    // 0x800BC428: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC42C: sw          $t7, -0x598C($at)
    MEM_W(-0X598C, ctx->r1) = ctx->r15;
    // 0x800BC430: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC434: sw          $v0, -0x59C4($at)
    MEM_W(-0X59C4, ctx->r1) = ctx->r2;
    // 0x800BC438: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800BC43C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800BC440: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800BC444: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800BC448: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800BC44C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BC450: sw          $t9, -0x59C0($at)
    MEM_W(-0X59C0, ctx->r1) = ctx->r25;
    // 0x800BC454: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800BC458: lui         $at, 0x7000
    ctx->r1 = S32(0X7000 << 16);
    // 0x800BC45C: and         $t8, $a3, $at
    ctx->r24 = ctx->r7 & ctx->r1;
    // 0x800BC460: srl         $t6, $t8, 28
    ctx->r14 = S32(U32(ctx->r24) >> 28);
    // 0x800BC464: blez        $t6, L_800BC484
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BC468: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800BC484;
    }
    // 0x800BC468: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC46C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BC470: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800BC474: lw          $t8, 0x70($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X70);
    // 0x800BC478: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BC47C: b           L_800BC488
    // 0x800BC480: sw          $t8, 0x3710($at)
    MEM_W(0X3710, ctx->r1) = ctx->r24;
        goto L_800BC488;
    // 0x800BC480: sw          $t8, 0x3710($at)
    MEM_W(0X3710, ctx->r1) = ctx->r24;
L_800BC484:
    // 0x800BC484: sw          $zero, 0x3710($at)
    MEM_W(0X3710, ctx->r1) = 0;
L_800BC488:
    // 0x800BC488: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800BC48C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800BC490: jr          $ra
    // 0x800BC494: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800BC494: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void tex_animate_texture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F3D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007F3D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007F3D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007F3DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007F3E0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007F3E4: lui         $t0, 0x400
    ctx->r8 = S32(0X400 << 16);
    // 0x8007F3E8: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8007F3EC: sll         $v1, $v0, 8
    ctx->r3 = S32(ctx->r2 << 8);
    // 0x8007F3F0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8007F3F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007F3F8: and         $t2, $v0, $t0
    ctx->r10 = ctx->r2 & ctx->r8;
    // 0x8007F3FC: bgez        $v1, L_8007F4EC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007F400: and         $t1, $v0, $at
        ctx->r9 = ctx->r2 & ctx->r1;
            goto L_8007F4EC;
    }
    // 0x8007F400: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x8007F404: bne         $t1, $zero, L_8007F440
    if (ctx->r9 != 0) {
        // 0x8007F408: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8007F440;
    }
    // 0x8007F408: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007F40C: jal         0x8006FB8C
    // 0x8007F410: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x8007F410: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_0:
    // 0x8007F414: slti        $at, $v0, 0x3DA
    ctx->r1 = SIGNED(ctx->r2) < 0X3DA ? 1 : 0;
    // 0x8007F418: bne         $at, $zero, L_8007F624
    if (ctx->r1 != 0) {
        // 0x8007F41C: lui         $a1, 0xFBFF
        ctx->r5 = S32(0XFBFF << 16);
            goto L_8007F624;
    }
    // 0x8007F41C: lui         $a1, 0xFBFF
    ctx->r5 = S32(0XFBFF << 16);
    // 0x8007F420: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8007F424: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007F428: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x8007F42C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8007F430: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8007F434: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007F438: b           L_8007F624
    // 0x8007F43C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
        goto L_8007F624;
    // 0x8007F43C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_8007F440:
    // 0x8007F440: bne         $t2, $zero, L_8007F4B4
    if (ctx->r10 != 0) {
        // 0x8007F444: nop
    
            goto L_8007F4B4;
    }
    // 0x8007F444: nop

    // 0x8007F448: lhu         $t4, 0x14($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F44C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8007F450: multu       $t4, $a3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F454: mflo        $t5
    ctx->r13 = lo;
    // 0x8007F458: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8007F45C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007F460: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F464: nop

    // 0x8007F468: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F46C: bne         $at, $zero, L_8007F624
    if (ctx->r1 != 0) {
        // 0x8007F470: sll         $t7, $v1, 1
        ctx->r15 = S32(ctx->r3 << 1);
            goto L_8007F624;
    }
    // 0x8007F470: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8007F474: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8007F478: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007F47C: bgez        $t9, L_8007F4A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007F480: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_8007F4A0;
    }
    // 0x8007F480: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007F484: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8007F488: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8007F48C: lui         $at, 0xF9FF
    ctx->r1 = S32(0XF9FF << 16);
    // 0x8007F490: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007F494: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8007F498: b           L_8007F624
    // 0x8007F49C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_8007F624;
    // 0x8007F49C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_8007F4A0:
    // 0x8007F4A0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8007F4A4: nop

    // 0x8007F4A8: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x8007F4AC: b           L_8007F624
    // 0x8007F4B0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_8007F624;
    // 0x8007F4B0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8007F4B4:
    // 0x8007F4B4: lhu         $t9, 0x14($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F4B8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8007F4BC: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F4C0: lui         $at, 0xF9FF
    ctx->r1 = S32(0XF9FF << 16);
    // 0x8007F4C4: mflo        $t4
    ctx->r12 = lo;
    // 0x8007F4C8: subu        $t3, $t8, $t4
    ctx->r11 = SUB32(ctx->r24, ctx->r12);
    // 0x8007F4CC: bgez        $t3, L_8007F624
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007F4D0: sw          $t3, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r11;
            goto L_8007F624;
    }
    // 0x8007F4D0: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8007F4D4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8007F4D8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8007F4DC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007F4E0: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8007F4E4: b           L_8007F624
    // 0x8007F4E8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_8007F624;
    // 0x8007F4E8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8007F4EC:
    // 0x8007F4EC: beq         $t1, $zero, L_8007F59C
    if (ctx->r9 == 0) {
        // 0x8007F4F0: lui         $a1, 0xFBFF
        ctx->r5 = S32(0XFBFF << 16);
            goto L_8007F59C;
    }
    // 0x8007F4F0: lui         $a1, 0xFBFF
    ctx->r5 = S32(0XFBFF << 16);
    // 0x8007F4F4: bne         $t2, $zero, L_8007F518
    if (ctx->r10 != 0) {
        // 0x8007F4F8: ori         $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 | 0XFFFF;
            goto L_8007F518;
    }
    // 0x8007F4F8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007F4FC: lhu         $t8, 0x14($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F500: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8007F504: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F508: mflo        $t4
    ctx->r12 = lo;
    // 0x8007F50C: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x8007F510: b           L_8007F530
    // 0x8007F514: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
        goto L_8007F530;
    // 0x8007F514: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_8007F518:
    // 0x8007F518: lhu         $t6, 0x14($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F51C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8007F520: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F524: mflo        $t7
    ctx->r15 = lo;
    // 0x8007F528: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x8007F52C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_8007F530:
    // 0x8007F530: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8007F534: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007F538: bgez        $v0, L_8007F55C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007F53C: negu        $t9, $v0
        ctx->r25 = SUB32(0, ctx->r2);
            goto L_8007F55C;
    }
    // 0x8007F53C: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x8007F540: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007F544: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8007F548: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007F54C: and         $t3, $t4, $a1
    ctx->r11 = ctx->r12 & ctx->r5;
    // 0x8007F550: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8007F554: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8007F558: nop

L_8007F55C:
    // 0x8007F55C: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F560: nop

    // 0x8007F564: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F568: bne         $at, $zero, L_8007F58C
    if (ctx->r1 != 0) {
        // 0x8007F56C: sll         $t6, $v1, 1
        ctx->r14 = S32(ctx->r3 << 1);
            goto L_8007F58C;
    }
    // 0x8007F56C: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x8007F570: subu        $t5, $t6, $v0
    ctx->r13 = SUB32(ctx->r14, ctx->r2);
    // 0x8007F574: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007F578: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007F57C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8007F580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007F584: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x8007F588: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_8007F58C:
    // 0x8007F58C: bne         $a0, $zero, L_8007F530
    if (ctx->r4 != 0) {
        // 0x8007F590: nop
    
            goto L_8007F530;
    }
    // 0x8007F590: nop

    // 0x8007F594: b           L_8007F628
    // 0x8007F598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007F628;
    // 0x8007F598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F59C:
    // 0x8007F59C: bne         $t2, $zero, L_8007F5F0
    if (ctx->r10 != 0) {
        // 0x8007F5A0: nop
    
            goto L_8007F5F0;
    }
    // 0x8007F5A0: nop

    // 0x8007F5A4: lhu         $t3, 0x14($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F5A8: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8007F5AC: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F5B0: mflo        $t6
    ctx->r14 = lo;
    // 0x8007F5B4: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x8007F5B8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8007F5BC: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F5C0: nop

    // 0x8007F5C4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F5C8: bne         $at, $zero, L_8007F624
    if (ctx->r1 != 0) {
        // 0x8007F5CC: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_8007F624;
    }
    // 0x8007F5CC: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
L_8007F5D0:
    // 0x8007F5D0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007F5D4: lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F5D8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007F5DC: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F5E0: beq         $at, $zero, L_8007F5D0
    if (ctx->r1 == 0) {
        // 0x8007F5E4: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_8007F5D0;
    }
    // 0x8007F5E4: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x8007F5E8: b           L_8007F628
    // 0x8007F5EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007F628;
    // 0x8007F5EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F5F0:
    // 0x8007F5F0: lhu         $t9, 0x14($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X14);
    // 0x8007F5F4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8007F5F8: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F5FC: mflo        $t3
    ctx->r11 = lo;
    // 0x8007F600: subu        $v0, $t8, $t3
    ctx->r2 = SUB32(ctx->r24, ctx->r11);
    // 0x8007F604: bgez        $v0, L_8007F624
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007F608: sw          $v0, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r2;
            goto L_8007F624;
    }
    // 0x8007F608: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8007F60C:
    // 0x8007F60C: lhu         $t6, 0x12($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X12);
    // 0x8007F610: nop

    // 0x8007F614: addu        $t5, $v0, $t6
    ctx->r13 = ADD32(ctx->r2, ctx->r14);
    // 0x8007F618: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8007F61C: bltz        $t5, L_8007F60C
    if (SIGNED(ctx->r13) < 0) {
        // 0x8007F620: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8007F60C;
    }
    // 0x8007F620: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8007F624:
    // 0x8007F624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007F628:
    // 0x8007F628: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007F62C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007F630: jr          $ra
    // 0x8007F634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8007F634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_loop_fish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037114: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80037118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003711C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80037120: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80037124: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80037128: jal         0x80066450
    // 0x8003712C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8003712C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    after_0:
    // 0x80037130: blez        $v0, L_80037148
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80037134: nop
    
            goto L_80037148;
    }
    // 0x80037134: nop

    // 0x80037138: jal         0x8000FFB8
    // 0x8003713C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x8003713C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80037140: b           L_800375A8
    // 0x80037144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800375A8;
    // 0x80037144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037148:
    // 0x80037148: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8003714C: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80037150: lbu         $v1, 0xFD($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XFD);
    // 0x80037154: nop

    // 0x80037158: beq         $v1, $zero, L_800371C8
    if (ctx->r3 == 0) {
        // 0x8003715C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800371C8;
    }
    // 0x8003715C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80037160: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80037164: nop

    // 0x80037168: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003716C: bne         $at, $zero, L_80037194
    if (ctx->r1 != 0) {
        // 0x80037170: nop
    
            goto L_80037194;
    }
    // 0x80037170: nop

    // 0x80037174: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80037178: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8003717C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80037180: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x80037184: sb          $t6, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = ctx->r14;
    // 0x80037188: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8003718C: b           L_800371C0
    // 0x80037190: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
        goto L_800371C0;
    // 0x80037190: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_80037194:
    // 0x80037194: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80037198: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8003719C: bgez        $v1, L_800371B4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800371A0: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800371B4;
    }
    // 0x800371A0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800371A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800371A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800371AC: nop

    // 0x800371B0: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800371B4:
    // 0x800371B4: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800371B8: sb          $zero, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = 0;
    // 0x800371BC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_800371C0:
    // 0x800371C0: b           L_800372B8
    // 0x800371C4: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
        goto L_800372B8;
    // 0x800371C4: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
L_800371C8:
    // 0x800371C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800371CC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800371D0: jal         0x8006FB8C
    // 0x800371D4: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800371D4: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800371D8: bne         $v0, $zero, L_800372B8
    if (ctx->r2 != 0) {
        // 0x800371DC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800372B8;
    }
    // 0x800371DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800371E0: lwc1        $f10, 0x118($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X118);
    // 0x800371E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800371E8: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x800371EC: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x800371F0: nop

    // 0x800371F4: bc1f        L_800372BC
    if (!c1cs) {
        // 0x800371F8: lw          $a1, 0x74($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X74);
            goto L_800372BC;
    }
    // 0x800371F8: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x800371FC: jal         0x8006FB8C
    // 0x80037200: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    rand_range(rdram, ctx);
        goto after_3;
    // 0x80037200: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_3:
    // 0x80037204: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80037208: lwc1        $f8, 0x118($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8003720C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80037210: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037214: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037218: sb          $v0, 0xFD($s0)
    MEM_B(0XFD, ctx->r16) = ctx->r2;
    // 0x8003721C: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80037220: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80037224: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80037228: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003722C: jal         0x8006FB8C
    // 0x80037230: nop

    rand_range(rdram, ctx);
        goto after_4;
    // 0x80037230: nop

    after_4:
    // 0x80037234: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80037238: lwc1        $f10, 0x10C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x8003723C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80037240: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80037244: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x80037248: lwc1        $f8, 0x10C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x8003724C: nop

    // 0x80037250: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80037254: nop

    // 0x80037258: bc1f        L_80037278
    if (!c1cs) {
        // 0x8003725C: nop
    
            goto L_80037278;
    }
    // 0x8003725C: nop

    // 0x80037260: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80037264: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80037268: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003726C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80037270: b           L_8003728C
    // 0x80037274: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
        goto L_8003728C;
    // 0x80037274: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
L_80037278:
    // 0x80037278: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003727C: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80037280: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80037284: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80037288: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
L_8003728C:
    // 0x8003728C: lbu         $t8, 0xFD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XFD);
    // 0x80037290: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80037294: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80037298: bgez        $t8, L_800372AC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8003729C: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800372AC;
    }
    // 0x8003729C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800372A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800372A4: nop

    // 0x800372A8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800372AC:
    // 0x800372AC: nop

    // 0x800372B0: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800372B4: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
L_800372B8:
    // 0x800372B8: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
L_800372BC:
    // 0x800372BC: lh          $t0, 0x100($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X100);
    // 0x800372C0: lh          $t9, 0xFE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XFE);
    // 0x800372C4: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800372C8: mflo        $t1
    ctx->r9 = lo;
    // 0x800372CC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800372D0: sh          $t2, 0xFE($s0)
    MEM_H(0XFE, ctx->r16) = ctx->r10;
    // 0x800372D4: lh          $t3, 0xFE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XFE);
    // 0x800372D8: nop

    // 0x800372DC: sll         $t4, $t3, 17
    ctx->r12 = S32(ctx->r11 << 17);
    // 0x800372E0: jal         0x80070A04
    // 0x800372E4: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    sins_f(rdram, ctx);
        goto after_5;
    // 0x800372E4: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_5:
    // 0x800372E8: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800372EC: lh          $a0, 0xFE($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XFE);
    // 0x800372F0: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800372F4: jal         0x80070A38
    // 0x800372F8: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    coss_f(rdram, ctx);
        goto after_6;
    // 0x800372F8: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x800372FC: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80037300: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x80037304: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80037308: jal         0x80070A04
    // 0x8003730C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    sins_f(rdram, ctx);
        goto after_7;
    // 0x8003730C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    after_7:
    // 0x80037310: lh          $a0, 0x104($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X104);
    // 0x80037314: jal         0x80070A38
    // 0x80037318: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_8;
    // 0x80037318: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8003731C: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80037320: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80037324: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80037328: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8003732C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80037330: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80037334: nop

    // 0x80037338: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8003733C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80037340: lwc1        $f6, 0x108($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X108);
    // 0x80037344: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80037348: mul.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8003734C: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80037350: sub.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80037354: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80037358: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8003735C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80037360: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80037364: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x80037368: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003736C: nop

    // 0x80037370: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80037374: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x80037378: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8003737C: nop

    // 0x80037380: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80037384: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80037388: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x8003738C: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x80037390: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x80037394: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    // 0x80037398: jal         0x80011560
    // 0x8003739C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_9;
    // 0x8003739C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x800373A0: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800373A4: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800373A8: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800373AC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800373B0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800373B4: jal         0x80011570
    // 0x800373B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    move_object(rdram, ctx);
        goto after_10;
    // 0x800373B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800373BC: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800373C0: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800373C4: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800373C8: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800373CC: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800373D0: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800373D4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800373D8: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x800373DC: jal         0x800CA030
    // 0x800373E0: add.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f14.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x800373E0: add.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f14.fl;
    after_11:
    // 0x800373E4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800373E8: jal         0x800CA030
    // 0x800373EC: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x800373EC: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x800373F0: lui         $at, 0x44C0
    ctx->r1 = S32(0X44C0 << 16);
    // 0x800373F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800373F8: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800373FC: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80037400: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80037404: lh          $t8, 0x106($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X106);
    // 0x80037408: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003740C: nop

    // 0x80037410: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80037414: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037418: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003741C: nop

    // 0x80037420: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80037424: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80037428: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003742C: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x80037430: sh          $t0, 0x106($s0)
    MEM_H(0X106, ctx->r16) = ctx->r8;
    // 0x80037434: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80037438: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003743C: jal         0x80070990
    // 0x80037440: nop

    arctan2_f(rdram, ctx);
        goto after_13;
    // 0x80037440: nop

    after_13:
    // 0x80037444: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80037448: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003744C: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80037450: jal         0x80070990
    // 0x80037454: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    arctan2_f(rdram, ctx);
        goto after_14;
    // 0x80037454: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_14:
    // 0x80037458: lh          $v1, 0x2($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X2);
    // 0x8003745C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80037460: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // 0x80037464: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x80037468: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8003746C: andi        $t1, $a1, 0xFFFF
    ctx->r9 = ctx->r5 & 0XFFFF;
    // 0x80037470: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80037474: beq         $at, $zero, L_8003749C
    if (ctx->r1 == 0) {
        // 0x80037478: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_8003749C;
    }
    // 0x80037478: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8003747C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80037480: nop

    // 0x80037484: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037488: mflo        $t3
    ctx->r11 = lo;
    // 0x8003748C: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80037490: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80037494: b           L_800374B0
    // 0x80037498: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
        goto L_800374B0;
    // 0x80037498: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
L_8003749C:
    // 0x8003749C: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800374A0: mflo        $t8
    ctx->r24 = lo;
    // 0x800374A4: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800374A8: subu        $t0, $v1, $t7
    ctx->r8 = SUB32(ctx->r3, ctx->r15);
    // 0x800374AC: sh          $t0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r8;
L_800374B0:
    // 0x800374B0: lbu         $t9, 0xFC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XFC);
    // 0x800374B4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800374B8: subu        $t2, $t1, $t9
    ctx->r10 = SUB32(ctx->r9, ctx->r25);
    // 0x800374BC: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800374C0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800374C4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800374C8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800374CC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800374D0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800374D4: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800374D8: addu        $v1, $s0, $t5
    ctx->r3 = ADD32(ctx->r16, ctx->r13);
    // 0x800374DC: sb          $t2, 0xFC($s0)
    MEM_B(0XFC, ctx->r16) = ctx->r10;
    // 0x800374E0: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800374E4: lh          $a0, 0x106($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X106);
    // 0x800374E8: jal         0x80070A70
    // 0x800374EC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    static_3_80070A70(rdram, ctx);
        goto after_15;
    // 0x800374EC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_15:
    // 0x800374F0: sra         $s1, $v0, 3
    ctx->r17 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800374F4: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x800374F8: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800374FC: jal         0x80070A38
    // 0x80037500: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    coss_f(rdram, ctx);
        goto after_16;
    // 0x80037500: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_16:
    // 0x80037504: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80037508: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003750C: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x80037510: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80037514: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80037518: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8003751C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80037520: nop

    // 0x80037524: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80037528: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003752C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037530: nop

    // 0x80037534: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80037538: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x8003753C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80037540: jal         0x80070A04
    // 0x80037544: nop

    sins_f(rdram, ctx);
        goto after_17;
    // 0x80037544: nop

    after_17:
    // 0x80037548: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8003754C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037550: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80037554: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80037558: lh          $t1, 0x14($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X14);
    // 0x8003755C: lh          $t2, 0x18($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X18);
    // 0x80037560: lh          $t4, 0x1E($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X1E);
    // 0x80037564: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80037568: lh          $t6, 0x22($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X22);
    // 0x8003756C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80037570: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80037574: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80037578: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8003757C: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80037580: addu        $t8, $t6, $s0
    ctx->r24 = ADD32(ctx->r14, ctx->r16);
    // 0x80037584: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80037588: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8003758C: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x80037590: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80037594: sh          $t9, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r25;
    // 0x80037598: sh          $t3, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = ctx->r11;
    // 0x8003759C: sh          $t5, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r13;
    // 0x800375A0: sh          $t8, 0x36($v1)
    MEM_H(0X36, ctx->r3) = ctx->r24;
    // 0x800375A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800375A8:
    // 0x800375A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800375AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800375B0: jr          $ra
    // 0x800375B4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800375B4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void lensflare_override_remove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD4F8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AD4FC: addiu       $a3, $a3, 0x3018
    ctx->r7 = ADD32(ctx->r7, 0X3018);
    // 0x800AD500: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800AD504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AD508: blez        $a1, L_800AD544
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800AD50C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AD544;
    }
    // 0x800AD50C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AD510: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800AD514: addiu       $t7, $t7, -0x7E00
    ctx->r15 = ADD32(ctx->r15, -0X7E00);
    // 0x800AD518: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800AD51C: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
L_800AD520:
    // 0x800AD520: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800AD524: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AD528: bne         $a0, $t8, L_800AD534
    if (ctx->r4 != ctx->r24) {
        // 0x800AD52C: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800AD534;
    }
    // 0x800AD52C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AD530: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AD534:
    // 0x800AD534: beq         $at, $zero, L_800AD544
    if (ctx->r1 == 0) {
        // 0x800AD538: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800AD544;
    }
    // 0x800AD538: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800AD53C: beq         $v0, $zero, L_800AD520
    if (ctx->r2 == 0) {
        // 0x800AD540: nop
    
            goto L_800AD520;
    }
    // 0x800AD540: nop

L_800AD544:
    // 0x800AD544: beq         $v0, $zero, L_800AD588
    if (ctx->r2 == 0) {
        // 0x800AD548: addiu       $t9, $a1, -0x1
        ctx->r25 = ADD32(ctx->r5, -0X1);
            goto L_800AD588;
    }
    // 0x800AD548: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x800AD54C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AD550: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AD554: beq         $at, $zero, L_800AD588
    if (ctx->r1 == 0) {
        // 0x800AD558: sw          $t9, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r25;
            goto L_800AD588;
    }
    // 0x800AD558: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800AD55C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800AD560: addiu       $t1, $t1, -0x7E00
    ctx->r9 = ADD32(ctx->r9, -0X7E00);
    // 0x800AD564: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800AD568: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800AD56C: addu        $v0, $t2, $t1
    ctx->r2 = ADD32(ctx->r10, ctx->r9);
    // 0x800AD570: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
L_800AD574:
    // 0x800AD574: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
    // 0x800AD578: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800AD57C: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x800AD580: bne         $at, $zero, L_800AD574
    if (ctx->r1 != 0) {
        // 0x800AD584: sw          $t3, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r11;
            goto L_800AD574;
    }
    // 0x800AD584: sw          $t3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r11;
L_800AD588:
    // 0x800AD588: jr          $ra
    // 0x800AD58C: nop

    return;
    // 0x800AD58C: nop

;}
RECOMP_FUNC void reset_lead_player_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E1BC: sb          $zero, -0x3354($at)
    MEM_B(-0X3354, ctx->r1) = 0;
    // 0x8000E1C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E1C4: jr          $ra
    // 0x8000E1C8: sb          $zero, -0x3350($at)
    MEM_B(-0X3350, ctx->r1) = 0;
    return;
    // 0x8000E1C8: sb          $zero, -0x3350($at)
    MEM_B(-0X3350, ctx->r1) = 0;
;}
RECOMP_FUNC void menu_save_options_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800856AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856B0: sw          $v0, 0x702C($at)
    MEM_W(0X702C, ctx->r1) = ctx->r2;
    // 0x800856B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856B8: sw          $zero, 0x6FD0($at)
    MEM_W(0X6FD0, ctx->r1) = 0;
    // 0x800856BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856C0: sw          $v0, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r2;
    // 0x800856C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856C8: sw          $v0, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r2;
    // 0x800856CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856D0: sh          $zero, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = 0;
    // 0x800856D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856D8: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x800856DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800856E0: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x800856E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800856EC: sw          $v0, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r2;
    // 0x800856F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800856F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800856F8: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x800856FC: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x80085700: jal         0x80070EDC
    // 0x80085704: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80085704: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_0:
    // 0x80085708: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008570C: sw          $v0, 0x7024($at)
    MEM_W(0X7024, ctx->r1) = ctx->r2;
    // 0x80085710: addiu       $a0, $zero, 0xA00
    ctx->r4 = ADD32(0, 0XA00);
    // 0x80085714: jal         0x80070EDC
    // 0x80085718: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80085718: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x8008571C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80085720: addiu       $v1, $v1, 0x6FCC
    ctx->r3 = ADD32(ctx->r3, 0X6FCC);
    // 0x80085724: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80085728: addiu       $t7, $v0, 0x500
    ctx->r15 = ADD32(ctx->r2, 0X500);
    // 0x8008572C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085730: sw          $t7, 0x6FC4($at)
    MEM_W(0X6FC4, ctx->r1) = ctx->r15;
    // 0x80085734: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085738: sw          $zero, 0x6FC8($at)
    MEM_W(0X6FC8, ctx->r1) = 0;
    // 0x8008573C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085740: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80085744: sw          $zero, 0x7194($at)
    MEM_W(0X7194, ctx->r1) = 0;
    // 0x80085748: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008574C: swc1        $f0, 0x719C($at)
    MEM_W(0X719C, ctx->r1) = ctx->f0.u32l;
    // 0x80085750: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085754: sw          $zero, 0x6FC0($at)
    MEM_W(0X6FC0, ctx->r1) = 0;
    // 0x80085758: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008575C: sw          $zero, 0x71A4($at)
    MEM_W(0X71A4, ctx->r1) = 0;
    // 0x80085760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085764: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085768: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    // 0x8008576C: jal         0x8009CBB8
    // 0x80085770: swc1        $f0, 0x71AC($at)
    MEM_W(0X71AC, ctx->r1) = ctx->f0.u32l;
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x80085770: swc1        $f0, 0x71AC($at)
    MEM_W(0X71AC, ctx->r1) = ctx->f0.u32l;
    after_2:
    // 0x80085774: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085778: jal         0x8009CDE8
    // 0x8008577C: addiu       $a0, $a0, 0x22C
    ctx->r4 = ADD32(ctx->r4, 0X22C);
    menu_imagegroup_load(rdram, ctx);
        goto after_3;
    // 0x8008577C: addiu       $a0, $a0, 0x22C
    ctx->r4 = ADD32(ctx->r4, 0X22C);
    after_3:
    // 0x80085780: jal         0x8008043C
    // 0x80085784: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8007FFEC(rdram, ctx);
        goto after_4;
    // 0x80085784: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_4:
    // 0x80085788: jal         0x800C46D0
    // 0x8008578C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_5;
    // 0x8008578C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80085790: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80085794: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
    // 0x80085798: lw          $t8, 0x11C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X11C);
    // 0x8008579C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857A0: sw          $t8, 0x190($at)
    MEM_W(0X190, ctx->r1) = ctx->r24;
    // 0x800857A4: lw          $t9, 0x120($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X120);
    // 0x800857A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857AC: sw          $t9, 0x1A0($at)
    MEM_W(0X1A0, ctx->r1) = ctx->r25;
    // 0x800857B0: lw          $t0, 0x12C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X12C);
    // 0x800857B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857B8: sw          $t0, 0x1B0($at)
    MEM_W(0X1B0, ctx->r1) = ctx->r8;
    // 0x800857BC: lw          $t1, 0x128($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X128);
    // 0x800857C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857C4: sw          $t1, 0x1C0($at)
    MEM_W(0X1C0, ctx->r1) = ctx->r9;
    // 0x800857C8: lw          $t2, 0x124($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X124);
    // 0x800857CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857D0: sw          $t2, 0x1D0($at)
    MEM_W(0X1D0, ctx->r1) = ctx->r10;
    // 0x800857D4: lw          $t3, 0x118($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X118);
    // 0x800857D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800857DC: jal         0x8008E968
    // 0x800857E0: sw          $t3, 0x1E0($at)
    MEM_W(0X1E0, ctx->r1) = ctx->r11;
    menu_init_arrow_textures(rdram, ctx);
        goto after_6;
    // 0x800857E0: sw          $t3, 0x1E0($at)
    MEM_W(0X1E0, ctx->r1) = ctx->r11;
    after_6:
    // 0x800857E4: jal         0x8006EDE8
    // 0x800857E8: nop

    mark_read_all_save_files(rdram, ctx);
        goto after_7;
    // 0x800857E8: nop

    after_7:
    // 0x800857EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800857F0: jal         0x800C06F8
    // 0x800857F4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_8;
    // 0x800857F4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_8:
    // 0x800857F8: jal         0x800724D8
    // 0x800857FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rumble_enable(rdram, ctx);
        goto after_9;
    // 0x800857FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80085800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80085808: jr          $ra
    // 0x8008580C: nop

    return;
    // 0x8008580C: nop

;}
RECOMP_FUNC void transition_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C09B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C09B8: addiu       $v1, $v1, 0x3734
    ctx->r3 = ADD32(ctx->r3, 0X3734);
    // 0x800C09BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C09C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C09C4: beq         $v0, $zero, L_800C09DC
    if (ctx->r2 == 0) {
        // 0x800C09C8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C09DC;
    }
    // 0x800C09C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C09CC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800C09D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800C09D4: b           L_800C09EC
    // 0x800C09D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800C09EC;
    // 0x800C09D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800C09DC:
    // 0x800C09DC: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x800C09E0: bne         $at, $zero, L_800C09EC
    if (ctx->r1 != 0) {
        // 0x800C09E4: nop
    
            goto L_800C09EC;
    }
    // 0x800C09E4: nop

    // 0x800C09E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800C09EC:
    // 0x800C09EC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C09F0: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
    // 0x800C09F4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C09F8: nop

    // 0x800C09FC: beq         $t7, $zero, L_800C0AD8
    if (ctx->r15 == 0) {
        // 0x800C0A00: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800C0AD8;
    }
    // 0x800C0A00: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0A04: lhu         $v0, 0x3740($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3740);
    // 0x800C0A08: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800C0A0C: bne         $v0, $zero, L_800C0A18
    if (ctx->r2 != 0) {
        // 0x800C0A10: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800C0A18;
    }
    // 0x800C0A10: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C0A14: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800C0A18:
    // 0x800C0A18: bne         $v0, $zero, L_800C0A44
    if (ctx->r2 != 0) {
        // 0x800C0A1C: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_800C0A44;
    }
    // 0x800C0A1C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C0A20: lhu         $t9, 0x3744($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X3744);
    // 0x800C0A24: nop

    // 0x800C0A28: bne         $t9, $zero, L_800C0A44
    if (ctx->r25 != 0) {
        // 0x800C0A2C: nop
    
            goto L_800C0A44;
    }
    // 0x800C0A2C: nop

    // 0x800C0A30: jal         0x800C0C44
    // 0x800C0A34: nop

    transition_end(rdram, ctx);
        goto after_0;
    // 0x800C0A34: nop

    after_0:
    // 0x800C0A38: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0A3C: b           L_800C0AD8
    // 0x800C0A40: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
        goto L_800C0AD8;
    // 0x800C0A40: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
L_800C0A44:
    // 0x800C0A44: blez        $v0, L_800C0A60
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C0A48: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800C0A60;
    }
    // 0x800C0A48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0A4C: addiu       $v0, $v0, 0x3760
    ctx->r2 = ADD32(ctx->r2, 0X3760);
    // 0x800C0A50: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800C0A54: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C0A58: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x800C0A5C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_800C0A60:
    // 0x800C0A60: lw          $t3, -0x5310($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5310);
    // 0x800C0A64: nop

    // 0x800C0A68: sltiu       $at, $t3, 0x7
    ctx->r1 = ctx->r11 < 0X7 ? 1 : 0;
    // 0x800C0A6C: beq         $at, $zero, L_800C0AD8
    if (ctx->r1 == 0) {
        // 0x800C0A70: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_800C0AD8;
    }
    // 0x800C0A70: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800C0A74: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0A78: addu        $at, $at, $t3
    gpr jr_addend_800C0A84 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C0A7C: lw          $t3, -0x6794($at)
    ctx->r11 = ADD32(ctx->r1, -0X6794);
    // 0x800C0A80: nop

    // 0x800C0A84: jr          $t3
    // 0x800C0A88: nop

    switch (jr_addend_800C0A84 >> 2) {
        case 0: goto L_800C0A8C; break;
        case 1: goto L_800C0AA0; break;
        case 2: goto L_800C0AA0; break;
        case 3: goto L_800C0AB4; break;
        case 4: goto L_800C0AA0; break;
        case 5: goto L_800C0AA0; break;
        case 6: goto L_800C0AC8; break;
        default: switch_error(__func__, 0x800C0A84, 0x800E986C);
    }
    // 0x800C0A88: nop

L_800C0A8C:
    // 0x800C0A8C: jal         0x800C0D54
    // 0x800C0A90: nop

    transition_update_fullscreen(rdram, ctx);
        goto after_1;
    // 0x800C0A90: nop

    after_1:
    // 0x800C0A94: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0A98: b           L_800C0AD8
    // 0x800C0A9C: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
        goto L_800C0AD8;
    // 0x800C0A9C: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
L_800C0AA0:
    // 0x800C0AA0: jal         0x800C1650
    // 0x800C0AA4: nop

    transition_update_shape(rdram, ctx);
        goto after_2;
    // 0x800C0AA4: nop

    after_2:
    // 0x800C0AA8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0AAC: b           L_800C0AD8
    // 0x800C0AB0: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
        goto L_800C0AD8;
    // 0x800C0AB0: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
L_800C0AB4:
    // 0x800C0AB4: jal         0x800C2408
    // 0x800C0AB8: nop

    transition_update_circle(rdram, ctx);
        goto after_3;
    // 0x800C0AB8: nop

    after_3:
    // 0x800C0ABC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0AC0: b           L_800C0AD8
    // 0x800C0AC4: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
        goto L_800C0AD8;
    // 0x800C0AC4: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
L_800C0AC8:
    // 0x800C0AC8: jal         0x800C2CC0
    // 0x800C0ACC: nop

    transition_update_blank(rdram, ctx);
        goto after_4;
    // 0x800C0ACC: nop

    after_4:
    // 0x800C0AD0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0AD4: addiu       $v1, $v1, 0x373C
    ctx->r3 = ADD32(ctx->r3, 0X373C);
L_800C0AD8:
    // 0x800C0AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0ADC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800C0AE0: jr          $ra
    // 0x800C0AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C0AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void osPfsReFormat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D04F0: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x800D04F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D04F8: sw          $a0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r4;
    // 0x800D04FC: sw          $a1, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r5;
    // 0x800D0500: jal         0x800CDBB0
    // 0x800D0504: sw          $a2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r6;
    __osSiGetAccess_recomp(rdram, ctx);
        goto after_0;
    // 0x800D0504: sw          $a2, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D0508: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D050C: jal         0x800CF334
    // 0x800D0510: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    __osPfsGetStatus_recomp(rdram, ctx);
        goto after_1;
    // 0x800D0510: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    after_1:
    // 0x800D0514: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0518: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D051C: beq         $t6, $zero, L_800D052C
    if (ctx->r14 == 0) {
        // 0x800D0520: nop
    
            goto L_800D052C;
    }
    // 0x800D0520: nop

    // 0x800D0524: b           L_800D08E0
    // 0x800D0528: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_800D08E0;
    // 0x800D0528: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_800D052C:
    // 0x800D052C: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800D0530: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800D0534: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x800D0538: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800D053C: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x800D0540: lw          $t0, 0x154($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X154);
    // 0x800D0544: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800D0548: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x800D054C: lw          $t2, 0x158($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X158);
    // 0x800D0550: jal         0x800CDBF4
    // 0x800D0554: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    __osSiRelAccess_recomp(rdram, ctx);
        goto after_2;
    // 0x800D0554: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    after_2:
    // 0x800D0558: jal         0x800D5EC4
    // 0x800D055C: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    __osGetId_recomp(rdram, ctx);
        goto after_3;
    // 0x800D055C: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    after_3:
    // 0x800D0560: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0564: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800D0568: beq         $t4, $zero, L_800D0578
    if (ctx->r12 == 0) {
        // 0x800D056C: nop
    
            goto L_800D0578;
    }
    // 0x800D056C: nop

    // 0x800D0570: b           L_800D08E0
    // 0x800D0574: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_800D08E0;
    // 0x800D0574: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_800D0578:
    // 0x800D0578: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800D057C: lbu         $t6, 0x65($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X65);
    // 0x800D0580: beq         $t6, $zero, L_800D05AC
    if (ctx->r14 == 0) {
        // 0x800D0584: nop
    
            goto L_800D05AC;
    }
    // 0x800D0584: nop

    // 0x800D0588: sb          $zero, 0x65($t5)
    MEM_B(0X65, ctx->r13) = 0;
    // 0x800D058C: jal         0x800D653C
    // 0x800D0590: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_4;
    // 0x800D0590: lw          $a0, 0x150($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X150);
    after_4:
    // 0x800D0594: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0598: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D059C: beq         $t8, $zero, L_800D05AC
    if (ctx->r24 == 0) {
        // 0x800D05A0: nop
    
            goto L_800D05AC;
    }
    // 0x800D05A0: nop

    // 0x800D05A4: b           L_800D08E0
    // 0x800D05A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D08E0;
    // 0x800D05A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D05AC:
    // 0x800D05AC: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
L_800D05B0:
    // 0x800D05B0: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x800D05B4: addu        $t7, $sp, $t9
    ctx->r15 = ADD32(ctx->r29, ctx->r25);
    // 0x800D05B8: sb          $zero, 0x28($t7)
    MEM_B(0X28, ctx->r15) = 0;
    // 0x800D05BC: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D05C0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800D05C4: slti        $at, $t1, 0x20
    ctx->r1 = SIGNED(ctx->r9) < 0X20 ? 1 : 0;
    // 0x800D05C8: bne         $at, $zero, L_800D05B0
    if (ctx->r1 != 0) {
        // 0x800D05CC: sw          $t1, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r9;
            goto L_800D05B0;
    }
    // 0x800D05CC: sw          $t1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r9;
    // 0x800D05D0: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D05D4: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
    // 0x800D05D8: lw          $t3, 0x50($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X50);
    // 0x800D05DC: blez        $t3, L_800D0640
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800D05E0: nop
    
            goto L_800D0640;
    }
    // 0x800D05E0: nop

L_800D05E4:
    // 0x800D05E4: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800D05E8: lw          $t5, 0x14C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14C);
    // 0x800D05EC: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D05F0: lw          $t6, 0x5C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X5C);
    // 0x800D05F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D05F8: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D05FC: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800D0600: jal         0x800CDE50
    // 0x800D0604: addu        $a2, $t6, $t5
    ctx->r6 = ADD32(ctx->r14, ctx->r13);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_5;
    // 0x800D0604: addu        $a2, $t6, $t5
    ctx->r6 = ADD32(ctx->r14, ctx->r13);
    after_5:
    // 0x800D0608: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D060C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D0610: beq         $t8, $zero, L_800D0620
    if (ctx->r24 == 0) {
        // 0x800D0614: nop
    
            goto L_800D0620;
    }
    // 0x800D0614: nop

    // 0x800D0618: b           L_800D08E0
    // 0x800D061C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D08E0;
    // 0x800D061C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D0620:
    // 0x800D0620: lw          $t9, 0x14C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0624: lw          $t0, 0x150($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X150);
    // 0x800D0628: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800D062C: sw          $t7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r15;
    // 0x800D0630: lw          $t1, 0x50($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X50);
    // 0x800D0634: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D0638: bne         $at, $zero, L_800D05E4
    if (ctx->r1 != 0) {
        // 0x800D063C: nop
    
            goto L_800D05E4;
    }
    // 0x800D063C: nop

L_800D0640:
    // 0x800D0640: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D0644: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
    // 0x800D0648: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x800D064C: blez        $t3, L_800D0684
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800D0650: nop
    
            goto L_800D0684;
    }
    // 0x800D0650: nop

L_800D0654:
    // 0x800D0654: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0658: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800D065C: addu        $t5, $sp, $t6
    ctx->r13 = ADD32(ctx->r29, ctx->r14);
    // 0x800D0660: sh          $zero, 0x48($t5)
    MEM_H(0X48, ctx->r13) = 0;
    // 0x800D0664: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0668: lw          $t0, 0x150($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X150);
    // 0x800D066C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D0670: sw          $t9, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r25;
    // 0x800D0674: lw          $t7, 0x60($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X60);
    // 0x800D0678: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D067C: bne         $at, $zero, L_800D0654
    if (ctx->r1 != 0) {
        // 0x800D0680: nop
    
            goto L_800D0654;
    }
    // 0x800D0680: nop

L_800D0684:
    // 0x800D0684: lw          $t1, 0x150($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X150);
    // 0x800D0688: lw          $t2, 0x60($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X60);
    // 0x800D068C: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x800D0690: beq         $at, $zero, L_800D06C0
    if (ctx->r1 == 0) {
        // 0x800D0694: sw          $t2, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r10;
            goto L_800D06C0;
    }
    // 0x800D0694: sw          $t2, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r10;
L_800D0698:
    // 0x800D0698: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800D069C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800D06A0: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800D06A4: addu        $t5, $sp, $t6
    ctx->r13 = ADD32(ctx->r29, ctx->r14);
    // 0x800D06A8: sh          $t3, 0x48($t5)
    MEM_H(0X48, ctx->r13) = ctx->r11;
    // 0x800D06AC: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800D06B0: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800D06B4: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800D06B8: bne         $at, $zero, L_800D0698
    if (ctx->r1 != 0) {
        // 0x800D06BC: sw          $t0, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r8;
            goto L_800D0698;
    }
    // 0x800D06BC: sw          $t0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r8;
L_800D06C0:
    // 0x800D06C0: lw          $t9, 0x150($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X150);
    // 0x800D06C4: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800D06C8: lw          $t7, 0x60($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X60);
    // 0x800D06CC: negu        $a1, $t7
    ctx->r5 = SUB32(0, ctx->r15);
    // 0x800D06D0: sll         $t4, $a1, 1
    ctx->r12 = S32(ctx->r5 << 1);
    // 0x800D06D4: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800D06D8: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x800D06DC: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x800D06E0: jal         0x800D5850
    // 0x800D06E4: addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    __osSumcalc(rdram, ctx);
        goto after_6;
    // 0x800D06E4: addiu       $a1, $a1, 0x100
    ctx->r5 = ADD32(ctx->r5, 0X100);
    after_6:
    // 0x800D06E8: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x800D06EC: sh          $v0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r2;
    // 0x800D06F0: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800D06F4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800D06F8: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
L_800D06FC:
    // 0x800D06FC: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800D0700: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0704: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800D0708: lw          $t8, 0x54($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X54);
    // 0x800D070C: sll         $t9, $t0, 5
    ctx->r25 = S32(ctx->r8 << 5);
    // 0x800D0710: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D0714: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D0718: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D071C: addu        $a3, $t9, $t1
    ctx->r7 = ADD32(ctx->r25, ctx->r9);
    // 0x800D0720: jal         0x800CDE50
    // 0x800D0724: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_7;
    // 0x800D0724: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    after_7:
    // 0x800D0728: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D072C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800D0730: beq         $t2, $zero, L_800D0740
    if (ctx->r10 == 0) {
        // 0x800D0734: nop
    
            goto L_800D0740;
    }
    // 0x800D0734: nop

    // 0x800D0738: b           L_800D08E0
    // 0x800D073C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800D08E0;
    // 0x800D073C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800D0740:
    // 0x800D0740: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800D0744: lw          $t3, 0x14C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0748: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800D074C: lw          $t4, 0x58($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X58);
    // 0x800D0750: sll         $t6, $t3, 5
    ctx->r14 = S32(ctx->r11 << 5);
    // 0x800D0754: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D0758: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D075C: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D0760: addu        $a3, $t6, $t5
    ctx->r7 = ADD32(ctx->r14, ctx->r13);
    // 0x800D0764: jal         0x800CDE50
    // 0x800D0768: addu        $a2, $t4, $t3
    ctx->r6 = ADD32(ctx->r12, ctx->r11);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_8;
    // 0x800D0768: addu        $a2, $t4, $t3
    ctx->r6 = ADD32(ctx->r12, ctx->r11);
    after_8:
    // 0x800D076C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0770: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D0774: beq         $t8, $zero, L_800D0784
    if (ctx->r24 == 0) {
        // 0x800D0778: nop
    
            goto L_800D0784;
    }
    // 0x800D0778: nop

    // 0x800D077C: b           L_800D08E0
    // 0x800D0780: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D08E0;
    // 0x800D0780: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D0784:
    // 0x800D0784: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0788: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800D078C: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800D0790: bne         $at, $zero, L_800D06FC
    if (ctx->r1 != 0) {
        // 0x800D0794: sw          $t9, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r25;
            goto L_800D06FC;
    }
    // 0x800D0794: sw          $t9, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r25;
    // 0x800D0798: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D079C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D07A0: sw          $t1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r9;
    // 0x800D07A4: lbu         $t7, 0x64($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X64);
    // 0x800D07A8: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800D07AC: bne         $at, $zero, L_800D08DC
    if (ctx->r1 != 0) {
        // 0x800D07B0: nop
    
            goto L_800D08DC;
    }
    // 0x800D07B0: nop

L_800D07B4:
    // 0x800D07B4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D07B8: sw          $t4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r12;
L_800D07BC:
    // 0x800D07BC: lw          $t6, 0x14C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14C);
    // 0x800D07C0: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800D07C4: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800D07C8: addu        $t8, $sp, $t5
    ctx->r24 = ADD32(ctx->r29, ctx->r13);
    // 0x800D07CC: sh          $t3, 0x48($t8)
    MEM_H(0X48, ctx->r24) = ctx->r11;
    // 0x800D07D0: lw          $t0, 0x14C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14C);
    // 0x800D07D4: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x800D07D8: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800D07DC: bne         $at, $zero, L_800D07BC
    if (ctx->r1 != 0) {
        // 0x800D07E0: sw          $t9, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r25;
            goto L_800D07BC;
    }
    // 0x800D07E0: sw          $t9, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r25;
    // 0x800D07E4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800D07E8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800D07EC: jal         0x800D5850
    // 0x800D07F0: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    __osSumcalc(rdram, ctx);
        goto after_9;
    // 0x800D07F0: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    after_9:
    // 0x800D07F4: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
    // 0x800D07F8: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // 0x800D07FC: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x800D0800: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800D0804: sw          $zero, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = 0;
L_800D0808:
    // 0x800D0808: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800D080C: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800D0810: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0814: lw          $t4, 0x54($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X54);
    // 0x800D0818: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800D081C: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x800D0820: sll         $t0, $t8, 5
    ctx->r8 = S32(ctx->r24 << 5);
    // 0x800D0824: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x800D0828: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D082C: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D0830: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D0834: addu        $a2, $t5, $t8
    ctx->r6 = ADD32(ctx->r13, ctx->r24);
    // 0x800D0838: jal         0x800CDE50
    // 0x800D083C: addu        $a3, $t0, $t9
    ctx->r7 = ADD32(ctx->r8, ctx->r25);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_10;
    // 0x800D083C: addu        $a3, $t0, $t9
    ctx->r7 = ADD32(ctx->r8, ctx->r25);
    after_10:
    // 0x800D0840: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0844: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800D0848: beq         $t1, $zero, L_800D0858
    if (ctx->r9 == 0) {
        // 0x800D084C: nop
    
            goto L_800D0858;
    }
    // 0x800D084C: nop

    // 0x800D0850: b           L_800D08E0
    // 0x800D0854: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800D08E0;
    // 0x800D0854: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800D0858:
    // 0x800D0858: lw          $t2, 0x150($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X150);
    // 0x800D085C: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800D0860: lw          $t5, 0x14C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14C);
    // 0x800D0864: lw          $t7, 0x58($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X58);
    // 0x800D0868: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800D086C: sll         $t4, $t6, 3
    ctx->r12 = S32(ctx->r14 << 3);
    // 0x800D0870: sll         $t8, $t5, 5
    ctx->r24 = S32(ctx->r13 << 5);
    // 0x800D0874: addu        $t3, $t7, $t4
    ctx->r11 = ADD32(ctx->r15, ctx->r12);
    // 0x800D0878: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D087C: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800D0880: lw          $a1, 0x158($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X158);
    // 0x800D0884: addu        $a2, $t3, $t5
    ctx->r6 = ADD32(ctx->r11, ctx->r13);
    // 0x800D0888: jal         0x800CDE50
    // 0x800D088C: addu        $a3, $t8, $t0
    ctx->r7 = ADD32(ctx->r24, ctx->r8);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_11;
    // 0x800D088C: addu        $a3, $t8, $t0
    ctx->r7 = ADD32(ctx->r24, ctx->r8);
    after_11:
    // 0x800D0890: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D0894: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800D0898: beq         $t9, $zero, L_800D08A8
    if (ctx->r25 == 0) {
        // 0x800D089C: nop
    
            goto L_800D08A8;
    }
    // 0x800D089C: nop

    // 0x800D08A0: b           L_800D08E0
    // 0x800D08A4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800D08E0;
    // 0x800D08A4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800D08A8:
    // 0x800D08A8: lw          $t1, 0x14C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14C);
    // 0x800D08AC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800D08B0: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x800D08B4: bne         $at, $zero, L_800D0808
    if (ctx->r1 != 0) {
        // 0x800D08B8: sw          $t2, 0x14C($sp)
        MEM_W(0X14C, ctx->r29) = ctx->r10;
            goto L_800D0808;
    }
    // 0x800D08B8: sw          $t2, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r10;
    // 0x800D08BC: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800D08C0: lw          $t4, 0x150($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X150);
    // 0x800D08C4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D08C8: sw          $t7, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r15;
    // 0x800D08CC: lbu         $t3, 0x64($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0X64);
    // 0x800D08D0: slt         $at, $t7, $t3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800D08D4: bne         $at, $zero, L_800D07B4
    if (ctx->r1 != 0) {
        // 0x800D08D8: nop
    
            goto L_800D07B4;
    }
    // 0x800D08D8: nop

L_800D08DC:
    // 0x800D08DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D08E0:
    // 0x800D08E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D08E4: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    // 0x800D08E8: jr          $ra
    // 0x800D08EC: nop

    return;
    // 0x800D08EC: nop

;}
RECOMP_FUNC void timetrial_init_staff_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B530: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001B534: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B538: sb          $zero, -0x3358($at)
    MEM_B(-0X3358, ctx->r1) = 0;
    // 0x8001B53C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B540: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001B544: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B548: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001B54C: jal         0x8006ECD0
    // 0x8001B550: sb          $zero, -0x335C($at)
    MEM_B(-0X335C, ctx->r1) = 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8001B550: sb          $zero, -0x335C($at)
    MEM_B(-0X335C, ctx->r1) = 0;
    after_0:
    // 0x8001B554: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8001B558: jal         0x8006B2EC
    // 0x8001B55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_vehicle_default(rdram, ctx);
        goto after_1;
    // 0x8001B55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001B560: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B564: lh          $t6, -0x4BFE($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4BFE);
    // 0x8001B568: nop

    // 0x8001B56C: bne         $v0, $t6, L_8001B660
    if (ctx->r2 != ctx->r14) {
        // 0x8001B570: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001B660;
    }
    // 0x8001B570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B574: jal         0x8001E2D0
    // 0x8001B578: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_2;
    // 0x8001B578: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_2:
    // 0x8001B57C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8001B580: jal         0x8001E2D0
    // 0x8001B584: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x8001B584: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x8001B588: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001B58C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8001B590: lb          $t7, 0x0($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X0);
    // 0x8001B594: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8001B598: beq         $a3, $t7, L_8001B5C8
    if (ctx->r7 == ctx->r15) {
        // 0x8001B59C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001B5C8;
    }
    // 0x8001B59C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001B5A0: lb          $t8, 0x0($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X0);
    // 0x8001B5A4: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8001B5A8: beq         $s0, $t8, L_8001B5CC
    if (ctx->r16 == ctx->r24) {
        // 0x8001B5AC: addu        $t9, $t0, $a2
        ctx->r25 = ADD32(ctx->r8, ctx->r6);
            goto L_8001B5CC;
    }
    // 0x8001B5AC: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
L_8001B5B0:
    // 0x8001B5B0: lb          $a1, 0x1($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X1);
    // 0x8001B5B4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001B5B8: beq         $a3, $a1, L_8001B5C8
    if (ctx->r7 == ctx->r5) {
        // 0x8001B5BC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8001B5C8;
    }
    // 0x8001B5BC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001B5C0: bne         $s0, $a1, L_8001B5B0
    if (ctx->r16 != ctx->r5) {
        // 0x8001B5C4: nop
    
            goto L_8001B5B0;
    }
    // 0x8001B5C4: nop

L_8001B5C8:
    // 0x8001B5C8: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
L_8001B5CC:
    // 0x8001B5CC: lb          $t1, 0x0($t9)
    ctx->r9 = MEM_B(ctx->r25, 0X0);
    // 0x8001B5D0: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x8001B5D4: beq         $a3, $t1, L_8001B65C
    if (ctx->r7 == ctx->r9) {
        // 0x8001B5D8: addu        $t3, $v0, $t2
        ctx->r11 = ADD32(ctx->r2, ctx->r10);
            goto L_8001B65C;
    }
    // 0x8001B5D8: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8001B5DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B5E0: lh          $t6, -0x4BFE($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4BFE);
    // 0x8001B5E4: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x8001B5E8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001B5EC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8001B5F0: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x8001B5F4: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8001B5F8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8001B5FC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8001B600: nop

    // 0x8001B604: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001B608: bne         $at, $zero, L_8001B660
    if (ctx->r1 != 0) {
        // 0x8001B60C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001B660;
    }
    // 0x8001B60C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B610: jal         0x8009F04C
    // 0x8001B614: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    get_eeprom_settings(rdram, ctx);
        goto after_4;
    // 0x8001B614: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_4:
    // 0x8001B618: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8001B61C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8001B620: sllv        $t5, $t6, $a2
    ctx->r13 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x8001B624: sra         $t8, $t5, 31
    ctx->r24 = S32(SIGNED(ctx->r13) >> 31);
    // 0x8001B628: and         $t2, $v0, $t8
    ctx->r10 = ctx->r2 & ctx->r24;
    // 0x8001B62C: bne         $t2, $zero, L_8001B644
    if (ctx->r10 != 0) {
        // 0x8001B630: and         $t3, $v1, $t5
        ctx->r11 = ctx->r3 & ctx->r13;
            goto L_8001B644;
    }
    // 0x8001B630: and         $t3, $v1, $t5
    ctx->r11 = ctx->r3 & ctx->r13;
    // 0x8001B634: bne         $t3, $zero, L_8001B644
    if (ctx->r11 != 0) {
        // 0x8001B638: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8001B644;
    }
    // 0x8001B638: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B63C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B640: sb          $t7, -0x3358($at)
    MEM_B(-0X3358, ctx->r1) = ctx->r15;
L_8001B644:
    // 0x8001B644: jal         0x8001B324
    // 0x8001B648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    timetrial_load_staff_ghost(rdram, ctx);
        goto after_5;
    // 0x8001B648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8001B64C: bne         $v0, $zero, L_8001B65C
    if (ctx->r2 != 0) {
        // 0x8001B650: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8001B65C;
    }
    // 0x8001B650: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001B654: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B658: sb          $t1, -0x335C($at)
    MEM_B(-0X335C, ctx->r1) = ctx->r9;
L_8001B65C:
    // 0x8001B65C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B660:
    // 0x8001B660: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B664: lbu         $v0, -0x335C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X335C);
    // 0x8001B668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B66C: jr          $ra
    // 0x8001B670: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001B670: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void render_scene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024D94: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80024D98: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80024D9C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80024DA0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80024DA4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80024DA8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80024DAC: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80024DB0: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80024DB4: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80024DB8: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x80024DBC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80024DC0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80024DC4: addiu       $s1, $s1, -0x49E0
    ctx->r17 = ADD32(ctx->r17, -0X49E0);
    // 0x80024DC8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80024DCC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80024DD0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80024DD4: addiu       $s2, $s2, -0x49DC
    ctx->r18 = ADD32(ctx->r18, -0X49DC);
    // 0x80024DD8: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80024DDC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80024DE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DE4: sw          $t3, -0x49D8($at)
    MEM_W(-0X49D8, ctx->r1) = ctx->r11;
    // 0x80024DE8: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80024DEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DF0: sw          $t5, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = ctx->r13;
    // 0x80024DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024DF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80024DFC: sw          $t6, -0x49A4($at)
    MEM_W(-0X49A4, ctx->r1) = ctx->r14;
    // 0x80024E00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024E04: sw          $zero, -0x49BC($at)
    MEM_W(-0X49BC, ctx->r1) = 0;
    // 0x80024E08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024E0C: sw          $zero, -0x49C0($at)
    MEM_W(-0X49C0, ctx->r1) = 0;
    // 0x80024E10: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80024E14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024E18: lw          $a0, -0x2704($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2704);
    // 0x80024E1C: jal         0x8006676C
    // 0x80024E20: sw          $zero, -0x49C4($at)
    MEM_W(-0X49C4, ctx->r1) = 0;
    cam_set_layout(rdram, ctx);
        goto after_0;
    // 0x80024E20: sw          $zero, -0x49C4($at)
    MEM_W(-0X49C4, ctx->r1) = 0;
    after_0:
    // 0x80024E24: jal         0x8006ECE0
    // 0x80024E28: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    is_game_paused(rdram, ctx);
        goto after_1;
    // 0x80024E28: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_1:
    // 0x80024E2C: beq         $v0, $zero, L_80024E3C
    if (ctx->r2 == 0) {
        // 0x80024E30: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80024E3C;
    }
    // 0x80024E30: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80024E34: b           L_80024E48
    // 0x80024E38: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
        goto L_80024E48;
    // 0x80024E38: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_80024E3C:
    // 0x80024E3C: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80024E40: nop

    // 0x80024E44: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
L_80024E48:
    // 0x80024E48: lw          $t8, -0x26FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26FC);
    // 0x80024E4C: nop

    // 0x80024E50: beq         $t8, $zero, L_80024E68
    if (ctx->r24 == 0) {
        // 0x80024E54: lw          $a2, 0xA0($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XA0);
            goto L_80024E68;
    }
    // 0x80024E54: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
    // 0x80024E58: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80024E5C: jal         0x800BA138
    // 0x80024E60: nop

    waves_update(rdram, ctx);
        goto after_2;
    // 0x80024E60: nop

    after_2:
    // 0x80024E64: lw          $a2, 0xA0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA0);
L_80024E68:
    // 0x80024E68: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80024E6C: jal         0x8002D91C
    // 0x80024E70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    shadow_update(rdram, ctx);
        goto after_3;
    // 0x80024E70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80024E74: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80024E78: lw          $v1, -0x3174($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3174);
    // 0x80024E7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80024E80: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
L_80024E84:
    // 0x80024E84: lw          $a0, 0x74($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X74);
    // 0x80024E88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024E8C: beq         $a0, $at, L_80024EB0
    if (ctx->r4 == ctx->r1) {
        // 0x80024E90: nop
    
            goto L_80024EB0;
    }
    // 0x80024E90: nop

    // 0x80024E94: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80024E98: jal         0x8007F69C
    // 0x80024E9C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    update_colour_cycle(rdram, ctx);
        goto after_4;
    // 0x80024E9C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_4:
    // 0x80024EA0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80024EA4: lw          $v1, -0x3174($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3174);
    // 0x80024EA8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80024EAC: nop

L_80024EB0:
    // 0x80024EB0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80024EB4: slti        $at, $v0, 0x1C
    ctx->r1 = SIGNED(ctx->r2) < 0X1C ? 1 : 0;
    // 0x80024EB8: bne         $at, $zero, L_80024E84
    if (ctx->r1 != 0) {
        // 0x80024EBC: addu        $t9, $v1, $v0
        ctx->r25 = ADD32(ctx->r3, ctx->r2);
            goto L_80024E84;
    }
    // 0x80024EBC: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x80024EC0: lw          $a0, 0xAC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XAC);
    // 0x80024EC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024EC8: beq         $a0, $at, L_80024EE8
    if (ctx->r4 == ctx->r1) {
        // 0x80024ECC: nop
    
            goto L_80024EE8;
    }
    // 0x80024ECC: nop

    // 0x80024ED0: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x80024ED4: jal         0x8007F8B0
    // 0x80024ED8: nop

    update_pulsating_light_data(rdram, ctx);
        goto after_5;
    // 0x80024ED8: nop

    after_5:
    // 0x80024EDC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80024EE0: lw          $v1, -0x3174($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3174);
    // 0x80024EE4: nop

L_80024EE8:
    // 0x80024EE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80024EEC: addiu       $a0, $a0, -0x49A0
    ctx->r4 = ADD32(ctx->r4, -0X49A0);
    // 0x80024EF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80024EF4: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
    // 0x80024EF8: lb          $v0, 0x4C($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X4C);
    // 0x80024EFC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80024F00: bne         $v0, $at, L_80024F20
    if (ctx->r2 != ctx->r1) {
        // 0x80024F04: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80024F20;
    }
    // 0x80024F04: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80024F08: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80024F0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024F10: sw          $t1, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r9;
    // 0x80024F14: lb          $v0, 0x4C($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X4C);
    // 0x80024F18: nop

    // 0x80024F1C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_80024F20:
    // 0x80024F20: beq         $v0, $at, L_80024F34
    if (ctx->r2 == ctx->r1) {
        // 0x80024F24: nop
    
            goto L_80024F34;
    }
    // 0x80024F24: nop

    // 0x80024F28: lb          $t2, 0xBD($v1)
    ctx->r10 = MEM_B(ctx->r3, 0XBD);
    // 0x80024F2C: nop

    // 0x80024F30: beq         $t2, $zero, L_80024F3C
    if (ctx->r10 == 0) {
        // 0x80024F34: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80024F3C;
    }
L_80024F34:
    // 0x80024F34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80024F38: sw          $t1, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r9;
L_80024F3C:
    // 0x80024F3C: lb          $t3, 0x49($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X49);
    // 0x80024F40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024F44: bne         $t3, $at, L_80024FDC
    if (ctx->r11 != ctx->r1) {
        // 0x80024F48: nop
    
            goto L_80024FDC;
    }
    // 0x80024F48: nop

    // 0x80024F4C: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x80024F50: lb          $t7, 0xA2($v1)
    ctx->r15 = MEM_B(ctx->r3, 0XA2);
    // 0x80024F54: lw          $t4, 0xA4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA4);
    // 0x80024F58: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024F5C: lbu         $t0, 0x0($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X0);
    // 0x80024F60: lh          $t6, 0xA8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA8);
    // 0x80024F64: sll         $t5, $t0, 9
    ctx->r13 = S32(ctx->r8 << 9);
    // 0x80024F68: addiu       $t0, $t5, -0x1
    ctx->r8 = ADD32(ctx->r13, -0X1);
    // 0x80024F6C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80024F70: addiu       $v0, $v0, -0x3174
    ctx->r2 = ADD32(ctx->r2, -0X3174);
    // 0x80024F74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80024F78: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80024F7C: addiu       $a2, $a2, -0x4970
    ctx->r6 = ADD32(ctx->r6, -0X4970);
    // 0x80024F80: addiu       $a1, $a1, -0x496C
    ctx->r5 = ADD32(ctx->r5, -0X496C);
    // 0x80024F84: mflo        $t8
    ctx->r24 = lo;
    // 0x80024F88: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80024F8C: and         $t2, $t9, $t0
    ctx->r10 = ctx->r25 & ctx->r8;
    // 0x80024F90: sh          $t2, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = ctx->r10;
    // 0x80024F94: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80024F98: nop

    // 0x80024F9C: lb          $t7, 0xA3($v1)
    ctx->r15 = MEM_B(ctx->r3, 0XA3);
    // 0x80024FA0: lw          $t3, 0xA4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XA4);
    // 0x80024FA4: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024FA8: lbu         $t0, 0x1($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X1);
    // 0x80024FAC: lh          $t5, 0xAA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XAA);
    // 0x80024FB0: sll         $t4, $t0, 9
    ctx->r12 = S32(ctx->r8 << 9);
    // 0x80024FB4: addiu       $t0, $t4, -0x1
    ctx->r8 = ADD32(ctx->r12, -0X1);
    // 0x80024FB8: mflo        $t6
    ctx->r14 = lo;
    // 0x80024FBC: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x80024FC0: and         $t9, $t8, $t0
    ctx->r25 = ctx->r24 & ctx->r8;
    // 0x80024FC4: sh          $t9, 0xAA($v1)
    MEM_H(0XAA, ctx->r3) = ctx->r25;
    // 0x80024FC8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80024FCC: nop

    // 0x80024FD0: lw          $a0, 0xA4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XA4);
    // 0x80024FD4: jal         0x8007F3D0
    // 0x80024FD8: nop

    tex_animate_texture(rdram, ctx);
        goto after_6;
    // 0x80024FD8: nop

    after_6:
L_80024FDC:
    // 0x80024FDC: jal         0x8009C850
    // 0x80024FE0: sb          $zero, 0x83($sp)
    MEM_B(0X83, ctx->r29) = 0;
    get_filtered_cheats(rdram, ctx);
        goto after_7;
    // 0x80024FE0: sb          $zero, 0x83($sp)
    MEM_B(0X83, ctx->r29) = 0;
    after_7:
    // 0x80024FE4: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x80024FE8: beq         $t3, $zero, L_80024FF8
    if (ctx->r11 == 0) {
        // 0x80024FEC: lui         $t7, 0xA000
        ctx->r15 = S32(0XA000 << 16);
            goto L_80024FF8;
    }
    // 0x80024FEC: lui         $t7, 0xA000
    ctx->r15 = S32(0XA000 << 16);
    // 0x80024FF0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80024FF4: sb          $t4, 0x83($sp)
    MEM_B(0X83, ctx->r29) = ctx->r12;
L_80024FF8:
    // 0x80024FF8: lw          $t5, 0x200($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X200);
    // 0x80024FFC: lui         $at, 0xAC29
    ctx->r1 = S32(0XAC29 << 16);
    // 0x80025000: beq         $t5, $at, L_8002500C
    if (ctx->r13 == ctx->r1) {
        // 0x80025004: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8002500C;
    }
    // 0x80025004: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80025008: sb          $t6, 0x83($sp)
    MEM_B(0X83, ctx->r29) = ctx->r14;
L_8002500C:
    // 0x8002500C: jal         0x8007B820
    // 0x80025010: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rendermode_reset(rdram, ctx);
        goto after_8;
    // 0x80025010: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80025014: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025018: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x8002501C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80025020: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80025024: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x80025028: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002502C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025030: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025034: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x80025038: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8002503C: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80025040: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x80025044: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80025048: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8002504C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025050: lui         $t5, 0xF900
    ctx->r13 = S32(0XF900 << 16);
    // 0x80025054: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80025058: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8002505C: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80025060: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80025064: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80025068: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8002506C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80025070: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80025074: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80025078: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8002507C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80025080: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80025084: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025088: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x8002508C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80025090: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80025094: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80025098: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8002509C: jal         0x800AD96C
    // 0x800250A0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rain_fog(rdram, ctx);
        goto after_9;
    // 0x800250A0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_9:
    // 0x800250A4: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x800250A8: jal         0x80030878
    // 0x800250AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    update_fog(rdram, ctx);
        goto after_10;
    // 0x800250AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x800250B0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800250B4: jal         0x800AF964
    // 0x800250B8: nop

    scroll_particle_textures(rdram, ctx);
        goto after_11;
    // 0x800250B8: nop

    after_11:
    // 0x800250BC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800250C0: lw          $t5, -0x3178($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3178);
    // 0x800250C4: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800250C8: lh          $t6, 0x1E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X1E);
    // 0x800250CC: nop

    // 0x800250D0: blez        $t6, L_800250E0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800250D4: nop
    
            goto L_800250E0;
    }
    // 0x800250D4: nop

    // 0x800250D8: jal         0x80027E64
    // 0x800250DC: nop

    track_tex_anim(rdram, ctx);
        goto after_12;
    // 0x800250DC: nop

    after_12:
L_800250E0:
    // 0x800250E0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800250E4: addiu       $s0, $s0, -0x49CC
    ctx->r16 = ADD32(ctx->r16, -0X49CC);
    // 0x800250E8: slt         $at, $zero, $s3
    ctx->r1 = SIGNED(0) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800250EC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800250F0: beq         $at, $zero, L_800252EC
    if (ctx->r1 == 0) {
        // 0x800250F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800252EC;
    }
    // 0x800250F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800250F8:
    // 0x800250F8: bne         $v0, $zero, L_80025120
    if (ctx->r2 != 0) {
        // 0x800250FC: lb          $t9, 0x83($sp)
        ctx->r25 = MEM_B(ctx->r29, 0X83);
            goto L_80025120;
    }
    // 0x800250FC: lb          $t9, 0x83($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X83);
    // 0x80025100: jal         0x8000E184
    // 0x80025104: nop

    is_player_two_in_control(rdram, ctx);
        goto after_13;
    // 0x80025104: nop

    after_13:
    // 0x80025108: beq         $v0, $zero, L_8002511C
    if (ctx->r2 == 0) {
        // 0x8002510C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8002511C;
    }
    // 0x8002510C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80025110: bne         $s3, $at, L_8002511C
    if (ctx->r19 != ctx->r1) {
        // 0x80025114: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8002511C;
    }
    // 0x80025114: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80025118: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_8002511C:
    // 0x8002511C: lb          $t9, 0x83($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X83);
L_80025120:
    // 0x80025120: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x80025124: beq         $t9, $zero, L_80025144
    if (ctx->r25 == 0) {
        // 0x80025128: nop
    
            goto L_80025144;
    }
    // 0x80025128: nop

    // 0x8002512C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025130: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x80025134: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80025138: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8002513C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80025140: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80025144:
    // 0x80025144: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80025148: jal         0x8003097C
    // 0x8002514C: nop

    apply_fog(rdram, ctx);
        goto after_14;
    // 0x8002514C: nop

    after_14:
    // 0x80025150: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025154: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80025158: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8002515C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80025160: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025164: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80025168: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8002516C: jal         0x80066828
    // 0x80025170: nop

    set_active_camera(rdram, ctx);
        goto after_15;
    // 0x80025170: nop

    after_15:
    // 0x80025174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025178: jal         0x80066F1C
    // 0x8002517C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    viewport_main(rdram, ctx);
        goto after_16;
    // 0x8002517C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x80025180: jal         0x8002A35C
    // 0x80025184: nop

    func_8002A31C(rdram, ctx);
        goto after_17;
    // 0x80025184: nop

    after_17:
    // 0x80025188: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x8002518C: beq         $at, $zero, L_800251DC
    if (ctx->r1 == 0) {
        // 0x80025190: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800251DC;
    }
    // 0x80025190: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025194: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025198: jal         0x80068648
    // 0x8002519C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_18;
    // 0x8002519C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x800251A0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800251A4: lw          $t6, -0x3174($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3174);
    // 0x800251A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800251AC: lb          $t8, 0x49($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X49);
    // 0x800251B0: nop

    // 0x800251B4: bne         $t8, $at, L_800251CC
    if (ctx->r24 != ctx->r1) {
        // 0x800251B8: nop
    
            goto L_800251CC;
    }
    // 0x800251B8: nop

    // 0x800251BC: jal         0x80028090
    // 0x800251C0: nop

    trackbg_render_flashy(rdram, ctx);
        goto after_19;
    // 0x800251C0: nop

    after_19:
    // 0x800251C4: b           L_80025208
    // 0x800251C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_80025208;
    // 0x800251C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_800251CC:
    // 0x800251CC: jal         0x80028C50
    // 0x800251D0: nop

    skydome_render(rdram, ctx);
        goto after_20;
    // 0x800251D0: nop

    after_20:
    // 0x800251D4: b           L_80025208
    // 0x800251D8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_80025208;
    // 0x800251D8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_800251DC:
    // 0x800251DC: jal         0x800682BC
    // 0x800251E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_perspective(rdram, ctx);
        goto after_21;
    // 0x800251E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_21:
    // 0x800251E4: jal         0x800289F8
    // 0x800251E8: nop

    trackbg_render_gradient(rdram, ctx);
        goto after_22;
    // 0x800251E8: nop

    after_22:
    // 0x800251EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800251F0: jal         0x80067F7C
    // 0x800251F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80067D3C(rdram, ctx);
        goto after_23;
    // 0x800251F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_23:
    // 0x800251F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800251FC: jal         0x80068648
    // 0x80025200: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_24;
    // 0x80025200: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_24:
    // 0x80025204: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80025208:
    // 0x80025208: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8002520C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80025210: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80025214: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025218: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8002521C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80025220: jal         0x80028D10
    // 0x80025224: nop

    initialise_player_viewport_vars(rdram, ctx);
        goto after_25;
    // 0x80025224: nop

    after_25:
    // 0x80025228: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8002522C: jal         0x800AB868
    // 0x80025230: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    weather_clip_planes(rdram, ctx);
        goto after_26;
    // 0x80025230: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    after_26:
    // 0x80025234: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80025238: lw          $t3, -0x3174($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3174);
    // 0x8002523C: slti        $at, $s3, 0x2
    ctx->r1 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x80025240: lh          $t4, 0x90($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X90);
    // 0x80025244: nop

    // 0x80025248: blez        $t4, L_80025278
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8002524C: nop
    
            goto L_80025278;
    }
    // 0x8002524C: nop

    // 0x80025250: beq         $at, $zero, L_80025278
    if (ctx->r1 == 0) {
        // 0x80025254: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80025278;
    }
    // 0x80025254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025258: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x8002525C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025260: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80025264: addiu       $a3, $a3, -0x49D4
    ctx->r7 = ADD32(ctx->r7, -0X49D4);
    // 0x80025268: addiu       $a2, $a2, -0x49D8
    ctx->r6 = ADD32(ctx->r6, -0X49D8);
    // 0x8002526C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80025270: jal         0x800AC3C8
    // 0x80025274: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    weather_update(rdram, ctx);
        goto after_27;
    // 0x80025274: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_27:
L_80025278:
    // 0x80025278: jal         0x80069F60
    // 0x8002527C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_28;
    // 0x8002527C: nop

    after_28:
    // 0x80025280: jal         0x800AD590
    // 0x80025284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    lensflare_override(rdram, ctx);
        goto after_29;
    // 0x80025284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_29:
    // 0x80025288: jal         0x80069F60
    // 0x8002528C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_30;
    // 0x8002528C: nop

    after_30:
    // 0x80025290: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025294: addiu       $a2, $a2, -0x49D8
    ctx->r6 = ADD32(ctx->r6, -0X49D8);
    // 0x80025298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002529C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800252A0: jal         0x800ACF80
    // 0x800252A4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lensflare_render(rdram, ctx);
        goto after_31;
    // 0x800252A4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_31:
    // 0x800252A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800252AC: jal         0x8001BB4C
    // 0x800252B0: nop

    get_racer_object_by_port(rdram, ctx);
        goto after_32;
    // 0x800252B0: nop

    after_32:
    // 0x800252B4: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x800252B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800252BC: addiu       $a2, $a2, -0x49D8
    ctx->r6 = ADD32(ctx->r6, -0X49D8);
    // 0x800252C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800252C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800252C8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800252CC: jal         0x800A06E0
    // 0x800252D0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    hud_render_player(rdram, ctx);
        goto after_33;
    // 0x800252D0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_33:
    // 0x800252D4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800252D8: nop

    // 0x800252DC: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x800252E0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800252E4: bne         $at, $zero, L_800250F8
    if (ctx->r1 != 0) {
        // 0x800252E8: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800250F8;
    }
    // 0x800252E8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800252EC:
    // 0x800252EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800252F0: bne         $s3, $at, L_800254A4
    if (ctx->r19 != ctx->r1) {
        // 0x800252F4: nop
    
            goto L_800254A4;
    }
    // 0x800252F4: nop

    // 0x800252F8: jal         0x8006BFD8
    // 0x800252FC: nop

    level_type(rdram, ctx);
        goto after_34;
    // 0x800252FC: nop

    after_34:
    // 0x80025300: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80025304: beq         $v0, $at, L_800254A4
    if (ctx->r2 == ctx->r1) {
        // 0x80025308: nop
    
            goto L_800254A4;
    }
    // 0x80025308: nop

    // 0x8002530C: jal         0x8006BFD8
    // 0x80025310: nop

    level_type(rdram, ctx);
        goto after_35;
    // 0x80025310: nop

    after_35:
    // 0x80025314: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80025318: beq         $v0, $at, L_800254A4
    if (ctx->r2 == ctx->r1) {
        // 0x8002531C: nop
    
            goto L_800254A4;
    }
    // 0x8002531C: nop

    // 0x80025320: jal         0x8006BFD8
    // 0x80025324: nop

    level_type(rdram, ctx);
        goto after_36;
    // 0x80025324: nop

    after_36:
    // 0x80025328: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8002532C: beq         $v0, $at, L_800254A4
    if (ctx->r2 == ctx->r1) {
        // 0x80025330: nop
    
            goto L_800254A4;
    }
    // 0x80025330: nop

    // 0x80025334: jal         0x800A89B4
    // 0x80025338: nop

    hud_setting(rdram, ctx);
        goto after_37;
    // 0x80025338: nop

    after_37:
    // 0x8002533C: bne         $v0, $zero, L_80025490
    if (ctx->r2 != 0) {
        // 0x80025340: nop
    
            goto L_80025490;
    }
    // 0x80025340: nop

    // 0x80025344: lb          $t9, 0x83($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X83);
    // 0x80025348: nop

    // 0x8002534C: beq         $t9, $zero, L_80025370
    if (ctx->r25 == 0) {
        // 0x80025350: nop
    
            goto L_80025370;
    }
    // 0x80025350: nop

    // 0x80025354: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80025358: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x8002535C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80025360: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80025364: addiu       $t4, $zero, 0x1000
    ctx->r12 = ADD32(0, 0X1000);
    // 0x80025368: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8002536C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_80025370:
    // 0x80025370: jal         0x8003097C
    // 0x80025374: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    apply_fog(rdram, ctx);
        goto after_38;
    // 0x80025374: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_38:
    // 0x80025378: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8002537C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80025380: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80025384: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80025388: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002538C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025390: jal         0x80066828
    // 0x80025394: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    set_active_camera(rdram, ctx);
        goto after_39;
    // 0x80025394: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    after_39:
    // 0x80025398: jal         0x80066760
    // 0x8002539C: nop

    disable_cutscene_camera(rdram, ctx);
        goto after_40;
    // 0x8002539C: nop

    after_40:
    // 0x800253A0: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800253A4: jal         0x80027928
    // 0x800253A8: nop

    ttcam_update(rdram, ctx);
        goto after_41;
    // 0x800253A8: nop

    after_41:
    // 0x800253AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800253B0: jal         0x80066F1C
    // 0x800253B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    viewport_main(rdram, ctx);
        goto after_42;
    // 0x800253B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_42:
    // 0x800253B8: jal         0x8002A35C
    // 0x800253BC: nop

    func_8002A31C(rdram, ctx);
        goto after_43;
    // 0x800253BC: nop

    after_43:
    // 0x800253C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800253C4: jal         0x800682BC
    // 0x800253C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_perspective(rdram, ctx);
        goto after_44;
    // 0x800253C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_44:
    // 0x800253CC: jal         0x800289F8
    // 0x800253D0: nop

    trackbg_render_gradient(rdram, ctx);
        goto after_45;
    // 0x800253D0: nop

    after_45:
    // 0x800253D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800253D8: jal         0x80067F7C
    // 0x800253DC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80067D3C(rdram, ctx);
        goto after_46;
    // 0x800253DC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_46:
    // 0x800253E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800253E4: jal         0x80068648
    // 0x800253E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mtx_world_origin(rdram, ctx);
        goto after_47;
    // 0x800253E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_47:
    // 0x800253EC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800253F0: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800253F4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800253F8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800253FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80025400: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80025404: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80025408: jal         0x80028D10
    // 0x8002540C: nop

    initialise_player_viewport_vars(rdram, ctx);
        goto after_48;
    // 0x8002540C: nop

    after_48:
    // 0x80025410: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80025414: jal         0x800AB868
    // 0x80025418: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    weather_clip_planes(rdram, ctx);
        goto after_49;
    // 0x80025418: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    after_49:
    // 0x8002541C: jal         0x80069F60
    // 0x80025420: nop

    cam_get_active_camera(rdram, ctx);
        goto after_50;
    // 0x80025420: nop

    after_50:
    // 0x80025424: jal         0x800AD590
    // 0x80025428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    lensflare_override(rdram, ctx);
        goto after_51;
    // 0x80025428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_51:
    // 0x8002542C: jal         0x80069F60
    // 0x80025430: nop

    cam_get_active_camera(rdram, ctx);
        goto after_52;
    // 0x80025430: nop

    after_52:
    // 0x80025434: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025438: addiu       $a2, $a2, -0x49D8
    ctx->r6 = ADD32(ctx->r6, -0X49D8);
    // 0x8002543C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025440: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80025444: jal         0x800ACF80
    // 0x80025448: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lensflare_render(rdram, ctx);
        goto after_53;
    // 0x80025448: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_53:
    // 0x8002544C: jal         0x800C484C
    // 0x80025450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_54;
    // 0x80025450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_54:
    // 0x80025454: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80025458: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x8002545C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80025460: bne         $t9, $zero, L_80025474
    if (ctx->r25 != 0) {
        // 0x80025464: lui         $a3, 0x800E
        ctx->r7 = S32(0X800E << 16);
            goto L_80025474;
    }
    // 0x80025464: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80025468: addiu       $a1, $zero, 0xA6
    ctx->r5 = ADD32(0, 0XA6);
    // 0x8002546C: b           L_8002547C
    // 0x80025470: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
        goto L_8002547C;
    // 0x80025470: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
L_80025474:
    // 0x80025474: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x80025478: addiu       $a2, $zero, 0x7D
    ctx->r6 = ADD32(0, 0X7D);
L_8002547C:
    // 0x8002547C: addiu       $a3, $a3, 0x6380
    ctx->r7 = ADD32(ctx->r7, 0X6380);
    // 0x80025480: jal         0x800C49A0
    // 0x80025484: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    draw_text(rdram, ctx);
        goto after_55;
    // 0x80025484: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_55:
    // 0x80025488: b           L_800254A4
    // 0x8002548C: nop

        goto L_800254A4;
    // 0x8002548C: nop

L_80025490:
    // 0x80025490: jal         0x80066828
    // 0x80025494: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    set_active_camera(rdram, ctx);
        goto after_56;
    // 0x80025494: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_56:
    // 0x80025498: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8002549C: jal         0x80027928
    // 0x800254A0: nop

    ttcam_update(rdram, ctx);
        goto after_57;
    // 0x800254A0: nop

    after_57:
L_800254A4:
    // 0x800254A4: jal         0x800684EC
    // 0x800254A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    viewport_reset(rdram, ctx);
        goto after_58;
    // 0x800254A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_58:
    // 0x800254AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800254B0: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800254B4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800254B8: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x800254BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800254C0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800254C4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800254C8: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x800254CC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800254D0: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x800254D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800254D8: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800254DC: addiu       $a1, $a1, -0x49B8
    ctx->r5 = ADD32(ctx->r5, -0X49B8);
    // 0x800254E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800254E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800254E8: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800254EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800254F0: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x800254F4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800254F8: subu        $t8, $t6, $t5
    ctx->r24 = SUB32(ctx->r14, ctx->r13);
    // 0x800254FC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80025500: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80025504: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80025508: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8002550C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80025510: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80025514: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x80025518: lw          $t7, -0x49D8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49D8);
    // 0x8002551C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80025520: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80025524: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80025528: lw          $t5, -0x49D4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X49D4);
    // 0x8002552C: nop

    // 0x80025530: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80025534: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80025538: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8002553C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80025540: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80025544: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80025548: jr          $ra
    // 0x8002554C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8002554C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void update_particle_texture_frame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B351C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800B3520: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800B3524: lh          $t6, 0x2C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2C);
    // 0x800B3528: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B352C: bne         $t6, $at, L_800B3550
    if (ctx->r14 != ctx->r1) {
        // 0x800B3530: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800B3550;
    }
    // 0x800B3530: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B3534: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x800B3538: nop

    // 0x800B353C: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x800B3540: nop

    // 0x800B3544: sll         $t8, $a1, 8
    ctx->r24 = S32(ctx->r5 << 8);
    // 0x800B3548: b           L_800B3568
    // 0x800B354C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
        goto L_800B3568;
    // 0x800B354C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_800B3550:
    // 0x800B3550: lw          $t9, 0x44($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X44);
    // 0x800B3554: nop

    // 0x800B3558: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800B355C: nop

    // 0x800B3560: lhu         $a1, 0x12($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X12);
    // 0x800B3564: nop

L_800B3568:
    // 0x800B3568: lw          $a3, 0x40($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X40);
    // 0x800B356C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B3570: addiu       $t4, $t4, -0x7DC0
    ctx->r12 = ADD32(ctx->r12, -0X7DC0);
    // 0x800B3574: lw          $t3, 0x0($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X0);
    // 0x800B3578: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B357C: slt         $t7, $zero, $t3
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B3580: andi        $a2, $a3, 0x1
    ctx->r6 = ctx->r7 & 0X1;
    // 0x800B3584: andi        $t0, $a3, 0x2
    ctx->r8 = ctx->r7 & 0X2;
    // 0x800B3588: andi        $t1, $a3, 0x4
    ctx->r9 = ctx->r7 & 0X4;
    // 0x800B358C: beq         $t7, $zero, L_800B3694
    if (ctx->r15 == 0) {
        // 0x800B3590: andi        $t2, $a3, 0x8
        ctx->r10 = ctx->r7 & 0X8;
            goto L_800B3694;
    }
    // 0x800B3590: andi        $t2, $a3, 0x8
    ctx->r10 = ctx->r7 & 0X8;
    // 0x800B3594: addiu       $s0, $zero, -0x9
    ctx->r16 = ADD32(0, -0X9);
    // 0x800B3598: addiu       $t5, $zero, -0x4
    ctx->r13 = ADD32(0, -0X4);
L_800B359C:
    // 0x800B359C: lh          $a3, 0x18($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X18);
    // 0x800B35A0: lh          $t3, 0x1A($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X1A);
    // 0x800B35A4: bne         $t2, $zero, L_800B361C
    if (ctx->r10 != 0) {
        // 0x800B35A8: subu        $t6, $a3, $t3
        ctx->r14 = SUB32(ctx->r7, ctx->r11);
            goto L_800B361C;
    }
    // 0x800B35A8: subu        $t6, $a3, $t3
    ctx->r14 = SUB32(ctx->r7, ctx->r11);
    // 0x800B35AC: addu        $t8, $a3, $t3
    ctx->r24 = ADD32(ctx->r7, ctx->r11);
    // 0x800B35B0: sh          $t8, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r24;
    // 0x800B35B4: lh          $a3, 0x18($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X18);
    // 0x800B35B8: nop

    // 0x800B35BC: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800B35C0: bne         $at, $zero, L_800B3678
    if (ctx->r1 != 0) {
        // 0x800B35C4: nop
    
            goto L_800B3678;
    }
    // 0x800B35C4: nop

    // 0x800B35C8: beq         $t0, $zero, L_800B35F0
    if (ctx->r8 == 0) {
        // 0x800B35CC: sll         $t9, $a1, 1
        ctx->r25 = S32(ctx->r5 << 1);
            goto L_800B35F0;
    }
    // 0x800B35CC: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x800B35D0: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x800B35D4: subu        $t6, $t9, $a3
    ctx->r14 = SUB32(ctx->r25, ctx->r7);
    // 0x800B35D8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B35DC: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x800B35E0: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x800B35E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B35E8: b           L_800B3678
    // 0x800B35EC: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
        goto L_800B3678;
    // 0x800B35EC: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
L_800B35F0:
    // 0x800B35F0: beq         $t1, $zero, L_800B3604
    if (ctx->r9 == 0) {
        // 0x800B35F4: addiu       $t7, $a1, -0x1
        ctx->r15 = ADD32(ctx->r5, -0X1);
            goto L_800B3604;
    }
    // 0x800B35F4: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x800B35F8: subu        $t6, $a3, $a1
    ctx->r14 = SUB32(ctx->r7, ctx->r5);
    // 0x800B35FC: b           L_800B3678
    // 0x800B3600: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
        goto L_800B3678;
    // 0x800B3600: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
L_800B3604:
    // 0x800B3604: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x800B3608: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x800B360C: and         $t9, $t8, $t5
    ctx->r25 = ctx->r24 & ctx->r13;
    // 0x800B3610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B3614: b           L_800B3678
    // 0x800B3618: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
        goto L_800B3678;
    // 0x800B3618: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
L_800B361C:
    // 0x800B361C: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x800B3620: lh          $a3, 0x18($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X18);
    // 0x800B3624: nop

    // 0x800B3628: bgez        $a3, L_800B3678
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800B362C: nop
    
            goto L_800B3678;
    }
    // 0x800B362C: nop

    // 0x800B3630: beq         $t1, $zero, L_800B3664
    if (ctx->r9 == 0) {
        // 0x800B3634: nop
    
            goto L_800B3664;
    }
    // 0x800B3634: nop

    // 0x800B3638: beq         $a2, $zero, L_800B365C
    if (ctx->r6 == 0) {
        // 0x800B363C: addu        $t6, $a3, $a1
        ctx->r14 = ADD32(ctx->r7, ctx->r5);
            goto L_800B365C;
    }
    // 0x800B363C: addu        $t6, $a3, $a1
    ctx->r14 = ADD32(ctx->r7, ctx->r5);
    // 0x800B3640: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x800B3644: negu        $t7, $a3
    ctx->r15 = SUB32(0, ctx->r7);
    // 0x800B3648: and         $t9, $t8, $s0
    ctx->r25 = ctx->r24 & ctx->r16;
    // 0x800B364C: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x800B3650: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800B3654: b           L_800B3678
    // 0x800B3658: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
        goto L_800B3678;
    // 0x800B3658: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
L_800B365C:
    // 0x800B365C: b           L_800B3678
    // 0x800B3660: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
        goto L_800B3678;
    // 0x800B3660: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
L_800B3664:
    // 0x800B3664: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x800B3668: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x800B366C: and         $t8, $t7, $t5
    ctx->r24 = ctx->r15 & ctx->r13;
    // 0x800B3670: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B3674: sw          $t8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r24;
L_800B3678:
    // 0x800B3678: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800B367C: nop

    // 0x800B3680: slt         $t3, $v1, $t9
    ctx->r11 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800B3684: beq         $t3, $zero, L_800B3694
    if (ctx->r11 == 0) {
        // 0x800B3688: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B3694;
    }
    // 0x800B3688: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B368C: bne         $v0, $zero, L_800B359C
    if (ctx->r2 != 0) {
        // 0x800B3690: nop
    
            goto L_800B359C;
    }
    // 0x800B3690: nop

L_800B3694:
    // 0x800B3694: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800B3698: jr          $ra
    // 0x800B369C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800B369C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void menu_adventure_track_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093B04: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80093B08: lw          $t6, 0x6980($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6980);
    // 0x80093B0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80093B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093B14: bgez        $t6, L_80093B34
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80093B18: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_80093B34;
    }
    // 0x80093B18: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80093B1C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80093B20: lw          $v0, -0x5BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BC);
    // 0x80093B24: nop

    // 0x80093B28: ori         $t7, $v0, 0x80
    ctx->r15 = ctx->r2 | 0X80;
    // 0x80093B2C: b           L_80093F00
    // 0x80093B30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80093F00;
    // 0x80093B30: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80093B34:
    // 0x80093B34: jal         0x8006ECD0
    // 0x80093B38: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80093B38: nop

    after_0:
    // 0x80093B3C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80093B40: lw          $t9, -0x5BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5BC);
    // 0x80093B44: lw          $t8, 0x4C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4C);
    // 0x80093B48: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80093B4C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80093B50: lb          $a0, 0x2($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X2);
    // 0x80093B54: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80093B58: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80093B5C: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80093B60: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80093B64: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x80093B68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093B6C: andi        $t4, $v1, 0x2
    ctx->r12 = ctx->r3 & 0X2;
    // 0x80093B70: beq         $t4, $zero, L_80093B7C
    if (ctx->r12 == 0) {
        // 0x80093B74: andi        $t5, $v1, 0x4
        ctx->r13 = ctx->r3 & 0X4;
            goto L_80093B7C;
    }
    // 0x80093B74: andi        $t5, $v1, 0x4
    ctx->r13 = ctx->r3 & 0X4;
    // 0x80093B78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80093B7C:
    // 0x80093B7C: beq         $t5, $zero, L_80093B88
    if (ctx->r13 == 0) {
        // 0x80093B80: nop
    
            goto L_80093B88;
    }
    // 0x80093B80: nop

    // 0x80093B84: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80093B88:
    // 0x80093B88: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80093B8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80093B90: jal         0x8006B38C
    // 0x80093B94: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    leveltable_type(rdram, ctx);
        goto after_1;
    // 0x80093B94: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80093B98: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80093B9C: andi        $t6, $v0, 0x40
    ctx->r14 = ctx->r2 & 0X40;
    // 0x80093BA0: beq         $t6, $zero, L_80093BAC
    if (ctx->r14 == 0) {
        // 0x80093BA4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80093BAC;
    }
    // 0x80093BA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80093BA8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_80093BAC:
    // 0x80093BAC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80093BB0: jal         0x8000E4C8
    // 0x80093BB4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    is_time_trial_enabled(rdram, ctx);
        goto after_2;
    // 0x80093BB4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80093BB8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80093BBC: bne         $v0, $zero, L_80093BFC
    if (ctx->r2 != 0) {
        // 0x80093BC0: nop
    
            goto L_80093BFC;
    }
    // 0x80093BC0: nop

    // 0x80093BC4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80093BC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80093BCC: bne         $t8, $at, L_80093BFC
    if (ctx->r24 != ctx->r1) {
        // 0x80093BD0: nop
    
            goto L_80093BFC;
    }
    // 0x80093BD0: nop

    // 0x80093BD4: lbu         $v0, 0x48($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X48);
    // 0x80093BD8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80093BDC: beq         $v0, $at, L_80093BF4
    if (ctx->r2 == ctx->r1) {
        // 0x80093BE0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80093BF4;
    }
    // 0x80093BE0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80093BE4: lhu         $t9, 0xC($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0XC);
    // 0x80093BE8: sllv        $t1, $t0, $v0
    ctx->r9 = S32(ctx->r8 << (ctx->r2 & 31));
    // 0x80093BEC: and         $t2, $t9, $t1
    ctx->r10 = ctx->r25 & ctx->r9;
    // 0x80093BF0: beq         $t2, $zero, L_80093BFC
    if (ctx->r10 == 0) {
        // 0x80093BF4: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80093BFC;
    }
L_80093BF4:
    // 0x80093BF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80093BF8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
L_80093BFC:
    // 0x80093BFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80093C00: addiu       $v0, $v0, 0x695C
    ctx->r2 = ADD32(ctx->r2, 0X695C);
    // 0x80093C04: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80093C08: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80093C0C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80093C10: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80093C14: andi        $t6, $t5, 0x3F
    ctx->r14 = ctx->r13 & 0X3F;
    // 0x80093C18: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80093C1C: jal         0x800933DC
    // 0x80093C20: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    adventuretrack_render(rdram, ctx);
        goto after_3;
    // 0x80093C20: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_3:
    // 0x80093C24: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80093C28: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80093C2C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80093C30: beq         $at, $zero, L_80093C48
    if (ctx->r1 == 0) {
        // 0x80093C34: nop
    
            goto L_80093C48;
    }
    // 0x80093C34: nop

    // 0x80093C38: jal         0x8006B2EC
    // 0x80093C3C: nop

    leveltable_vehicle_default(rdram, ctx);
        goto after_4;
    // 0x80093C3C: nop

    after_4:
    // 0x80093C40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093C44: sb          $v0, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = ctx->r2;
L_80093C48:
    // 0x80093C48: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80093C4C: lb          $v1, 0x6F80($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6F80);
    // 0x80093C50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80093C54: jal         0x8006B338
    // 0x80093C58: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_5;
    // 0x80093C58: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_5:
    // 0x80093C5C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80093C60: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80093C64: jal         0x8008E9A4
    // 0x80093C68: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    menu_input(rdram, ctx);
        goto after_6;
    // 0x80093C68: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_6:
    // 0x80093C6C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80093C70: addiu       $a2, $a2, -0x604
    ctx->r6 = ADD32(ctx->r6, -0X604);
    // 0x80093C74: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80093C78: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80093C7C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80093C80: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80093C84: bne         $v0, $zero, L_80093E74
    if (ctx->r2 != 0) {
        // 0x80093C88: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80093E74;
    }
    // 0x80093C88: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80093C8C: addiu       $a3, $a3, 0x6980
    ctx->r7 = ADD32(ctx->r7, 0X6980);
    // 0x80093C90: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80093C94: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80093C98: bne         $t8, $zero, L_80093CB8
    if (ctx->r24 != 0) {
        // 0x80093C9C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80093CB8;
    }
    // 0x80093C9C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80093CA0: bne         $t0, $zero, L_80093CB8
    if (ctx->r8 != 0) {
        // 0x80093CA4: nop
    
            goto L_80093CB8;
    }
    // 0x80093CA4: nop

    // 0x80093CA8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80093CAC: nop

    // 0x80093CB0: beq         $t9, $zero, L_80093D70
    if (ctx->r25 == 0) {
        // 0x80093CB4: nop
    
            goto L_80093D70;
    }
    // 0x80093CB4: nop

L_80093CB8:
    // 0x80093CB8: lw          $v0, 0x6D78($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D78);
    // 0x80093CBC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80093CC0: andi        $t1, $v0, 0x9000
    ctx->r9 = ctx->r2 & 0X9000;
    // 0x80093CC4: beq         $t1, $zero, L_80093D0C
    if (ctx->r9 == 0) {
        // 0x80093CC8: andi        $t4, $v0, 0x4000
        ctx->r12 = ctx->r2 & 0X4000;
            goto L_80093D0C;
    }
    // 0x80093CC8: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    // 0x80093CCC: beq         $t2, $zero, L_80093CE8
    if (ctx->r10 == 0) {
        // 0x80093CD0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80093CE8;
    }
    // 0x80093CD0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80093CD4: jal         0x800C3744
    // 0x80093CD8: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    set_current_text(rdram, ctx);
        goto after_7;
    // 0x80093CD8: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    after_7:
    // 0x80093CDC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80093CE0: addiu       $a2, $a2, -0x604
    ctx->r6 = ADD32(ctx->r6, -0X604);
    // 0x80093CE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80093CE8:
    // 0x80093CE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80093CEC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80093CF0: jal         0x800C06F8
    // 0x80093CF4: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_8;
    // 0x80093CF4: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_8:
    // 0x80093CF8: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80093CFC: jal         0x80001D04
    // 0x80093D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x80093D00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80093D04: b           L_80093EF4
    // 0x80093D08: nop

        goto L_80093EF4;
    // 0x80093D08: nop

L_80093D0C:
    // 0x80093D0C: beq         $t4, $zero, L_80093EF4
    if (ctx->r12 == 0) {
        // 0x80093D10: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_80093EF4;
    }
    // 0x80093D10: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80093D14: jal         0x80001D04
    // 0x80093D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x80093D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80093D1C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80093D20: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80093D24: bne         $t5, $zero, L_80093D38
    if (ctx->r13 != 0) {
        // 0x80093D28: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80093D38;
    }
    // 0x80093D28: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80093D2C: beq         $t6, $zero, L_80093D68
    if (ctx->r14 == 0) {
        // 0x80093D30: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80093D68;
    }
    // 0x80093D30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093D34: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_80093D38:
    // 0x80093D38: nop

    // 0x80093D3C: beq         $t7, $zero, L_80093D4C
    if (ctx->r15 == 0) {
        // 0x80093D40: nop
    
            goto L_80093D4C;
    }
    // 0x80093D40: nop

    // 0x80093D44: jal         0x800C3744
    // 0x80093D48: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    set_current_text(rdram, ctx);
        goto after_11;
    // 0x80093D48: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    after_11:
L_80093D4C:
    // 0x80093D4C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80093D50: jal         0x800C06F8
    // 0x80093D54: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_12;
    // 0x80093D54: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_12:
    // 0x80093D58: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80093D5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093D60: b           L_80093EF4
    // 0x80093D64: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
        goto L_80093EF4;
    // 0x80093D64: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
L_80093D68:
    // 0x80093D68: b           L_80093EF4
    // 0x80093D6C: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
        goto L_80093EF4;
    // 0x80093D6C: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
L_80093D70:
    // 0x80093D70: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80093D74: lw          $v0, 0x6D78($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D78);
    // 0x80093D78: nop

    // 0x80093D7C: andi        $t0, $v0, 0x4000
    ctx->r8 = ctx->r2 & 0X4000;
    // 0x80093D80: beq         $t0, $zero, L_80093DB0
    if (ctx->r8 == 0) {
        // 0x80093D84: andi        $t1, $v0, 0x9000
        ctx->r9 = ctx->r2 & 0X9000;
            goto L_80093DB0;
    }
    // 0x80093D84: andi        $t1, $v0, 0x9000
    ctx->r9 = ctx->r2 & 0X9000;
    // 0x80093D88: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80093D8C: jal         0x80001D04
    // 0x80093D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x80093D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80093D94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80093D98: jal         0x800C06F8
    // 0x80093D9C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_14;
    // 0x80093D9C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_14:
    // 0x80093DA0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80093DA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093DA8: b           L_80093EF4
    // 0x80093DAC: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
        goto L_80093EF4;
    // 0x80093DAC: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
L_80093DB0:
    // 0x80093DB0: beq         $t1, $zero, L_80093DD0
    if (ctx->r9 == 0) {
        // 0x80093DB4: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80093DD0;
    }
    // 0x80093DB4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80093DB8: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80093DBC: addiu       $a0, $zero, 0x131
    ctx->r4 = ADD32(0, 0X131);
    // 0x80093DC0: jal         0x80001D04
    // 0x80093DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x80093DC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80093DC8: b           L_80093EF4
    // 0x80093DCC: nop

        goto L_80093EF4;
    // 0x80093DCC: nop

L_80093DD0:
    // 0x80093DD0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80093DD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80093DD8: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80093DDC: bne         $at, $zero, L_80093EF4
    if (ctx->r1 != 0) {
        // 0x80093DE0: nop
    
            goto L_80093EF4;
    }
    // 0x80093DE0: nop

    // 0x80093DE4: lh          $v0, 0x6DD0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6DD0);
    // 0x80093DE8: nop

    // 0x80093DEC: blez        $v0, L_80093E14
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80093DF0: nop
    
            goto L_80093E14;
    }
    // 0x80093DF0: nop

L_80093DF4:
    // 0x80093DF4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80093DF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80093DFC: sllv        $t5, $t4, $v1
    ctx->r13 = S32(ctx->r12 << (ctx->r3 & 31));
    // 0x80093E00: and         $t6, $t5, $a0
    ctx->r14 = ctx->r13 & ctx->r4;
    // 0x80093E04: bne         $t6, $zero, L_80093E14
    if (ctx->r14 != 0) {
        // 0x80093E08: nop
    
            goto L_80093E14;
    }
    // 0x80093E08: nop

    // 0x80093E0C: bgez        $v1, L_80093DF4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80093E10: nop
    
            goto L_80093DF4;
    }
    // 0x80093E10: nop

L_80093E14:
    // 0x80093E14: bgez        $v0, L_80093E3C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80093E18: nop
    
            goto L_80093E3C;
    }
    // 0x80093E18: nop

L_80093E1C:
    // 0x80093E1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80093E20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80093E24: sllv        $t8, $t7, $v1
    ctx->r24 = S32(ctx->r15 << (ctx->r3 & 31));
    // 0x80093E28: and         $t0, $t8, $a0
    ctx->r8 = ctx->r24 & ctx->r4;
    // 0x80093E2C: bne         $t0, $zero, L_80093E3C
    if (ctx->r8 != 0) {
        // 0x80093E30: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_80093E3C;
    }
    // 0x80093E30: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80093E34: bne         $at, $zero, L_80093E1C
    if (ctx->r1 != 0) {
        // 0x80093E38: nop
    
            goto L_80093E1C;
    }
    // 0x80093E38: nop

L_80093E3C:
    // 0x80093E3C: bltz        $v1, L_80093E4C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80093E40: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_80093E4C;
    }
    // 0x80093E40: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80093E44: bne         $at, $zero, L_80093E50
    if (ctx->r1 != 0) {
        // 0x80093E48: nop
    
            goto L_80093E50;
    }
    // 0x80093E48: nop

L_80093E4C:
    // 0x80093E4C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80093E50:
    // 0x80093E50: beq         $v1, $a1, L_80093EF4
    if (ctx->r3 == ctx->r5) {
        // 0x80093E54: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80093EF4;
    }
    // 0x80093E54: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80093E58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093E5C: jal         0x80001D04
    // 0x80093E60: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    sound_play(rdram, ctx);
        goto after_16;
    // 0x80093E60: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_16:
    // 0x80093E64: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80093E68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093E6C: b           L_80093EF4
    // 0x80093E70: sb          $v1, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = ctx->r3;
        goto L_80093EF4;
    // 0x80093E70: sb          $v1, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = ctx->r3;
L_80093E74:
    // 0x80093E74: bgez        $v0, L_80093E94
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80093E78: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_80093E94;
    }
    // 0x80093E78: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80093E7C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80093E80: nop

    // 0x80093E84: subu        $t1, $v0, $t9
    ctx->r9 = SUB32(ctx->r2, ctx->r25);
    // 0x80093E88: b           L_80093EA0
    // 0x80093E8C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
        goto L_80093EA0;
    // 0x80093E8C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80093E90: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
L_80093E94:
    // 0x80093E94: nop

    // 0x80093E98: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80093E9C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_80093EA0:
    // 0x80093EA0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80093EA4: nop

    // 0x80093EA8: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80093EAC: beq         $at, $zero, L_80093EBC
    if (ctx->r1 == 0) {
        // 0x80093EB0: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_80093EBC;
    }
    // 0x80093EB0: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x80093EB4: beq         $at, $zero, L_80093EF4
    if (ctx->r1 == 0) {
        // 0x80093EB8: nop
    
            goto L_80093EF4;
    }
    // 0x80093EB8: nop

L_80093EBC:
    // 0x80093EBC: jal         0x80093F10
    // 0x80093EC0: nop

    adventuretrack_free(rdram, ctx);
        goto after_17;
    // 0x80093EC0: nop

    after_17:
    // 0x80093EC4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80093EC8: lw          $t4, -0x604($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X604);
    // 0x80093ECC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80093ED0: blez        $t4, L_80093EEC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80093ED4: nop
    
            goto L_80093EEC;
    }
    // 0x80093ED4: nop

    // 0x80093ED8: lw          $v0, -0x5BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BC);
    // 0x80093EDC: nop

    // 0x80093EE0: ori         $t5, $v0, 0x80
    ctx->r13 = ctx->r2 | 0X80;
    // 0x80093EE4: b           L_80093F00
    // 0x80093EE8: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80093F00;
    // 0x80093EE8: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80093EEC:
    // 0x80093EEC: b           L_80093F00
    // 0x80093EF0: addiu       $v0, $zero, 0x103
    ctx->r2 = ADD32(0, 0X103);
        goto L_80093F00;
    // 0x80093EF0: addiu       $v0, $zero, 0x103
    ctx->r2 = ADD32(0, 0X103);
L_80093EF4:
    // 0x80093EF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093EF8: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x80093EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80093F00:
    // 0x80093F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80093F04: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80093F08: jr          $ra
    // 0x80093F0C: nop

    return;
    // 0x80093F0C: nop

;}
RECOMP_FUNC void void_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025550: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80025554: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025558: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8002555C: addiu       $t1, $t1, -0x25C6
    ctx->r9 = ADD32(ctx->r9, -0X25C6);
    // 0x80025560: addiu       $a2, $a2, -0x25C4
    ctx->r6 = ADD32(ctx->r6, -0X25C4);
    // 0x80025564: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80025568: addiu       $t6, $zero, 0xAF
    ctx->r14 = ADD32(0, 0XAF);
    // 0x8002556C: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x80025570: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80025574: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80025578: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002557C: sh          $t6, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r14;
    // 0x80025580: bne         $at, $zero, L_80025598
    if (ctx->r1 != 0) {
        // 0x80025584: sh          $t7, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r15;
            goto L_80025598;
    }
    // 0x80025584: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x80025588: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x8002558C: nop

    // 0x80025590: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80025594: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_80025598:
    // 0x80025598: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x8002559C: lh          $v1, 0x0($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X0);
    // 0x800255A0: sll         $a3, $t0, 2
    ctx->r7 = S32(ctx->r8 << 2);
    // 0x800255A4: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x800255A8: addu        $t5, $t5, $a3
    ctx->r13 = ADD32(ctx->r13, ctx->r7);
    // 0x800255AC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800255B0: sll         $t6, $t0, 5
    ctx->r14 = S32(ctx->r8 << 5);
    // 0x800255B4: sll         $t2, $v1, 3
    ctx->r10 = S32(ctx->r3 << 3);
    // 0x800255B8: addiu       $t3, $t2, 0x30
    ctx->r11 = ADD32(ctx->r10, 0X30);
    // 0x800255BC: addiu       $a3, $t5, 0xC8
    ctx->r7 = ADD32(ctx->r13, 0XC8);
    // 0x800255C0: addiu       $t0, $t6, 0xA0
    ctx->r8 = ADD32(ctx->r14, 0XA0);
    // 0x800255C4: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800255C8: addiu       $t4, $v1, 0x5
    ctx->r12 = ADD32(ctx->r3, 0X5);
    // 0x800255CC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800255D0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x800255D4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800255D8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800255DC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800255E0: jal         0x80070EDC
    // 0x800255E4: sll         $a0, $s0, 4
    ctx->r4 = S32(ctx->r16 << 4);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800255E4: sll         $a0, $s0, 4
    ctx->r4 = S32(ctx->r16 << 4);
    after_0:
    // 0x800255E8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800255EC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800255F0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800255F4: addu        $t2, $a3, $t0
    ctx->r10 = ADD32(ctx->r7, ctx->r8);
    // 0x800255F8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800255FC: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025600: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80025604: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025608: addiu       $a2, $a2, -0x260C
    ctx->r6 = ADD32(ctx->r6, -0X260C);
    // 0x8002560C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80025610: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80025614: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80025618: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8002561C: mflo        $t4
    ctx->r12 = lo;
    // 0x80025620: addu        $a0, $t9, $t4
    ctx->r4 = ADD32(ctx->r25, ctx->r12);
    // 0x80025624: jal         0x80070EDC
    // 0x80025628: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80025628: nop

    after_1:
    // 0x8002562C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80025630: addiu       $a0, $a0, -0x316C
    ctx->r4 = ADD32(ctx->r4, -0X316C);
    // 0x80025634: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025638: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8002563C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80025640: addiu       $a2, $a2, -0x260C
    ctx->r6 = ADD32(ctx->r6, -0X260C);
    // 0x80025644: beq         $v0, $zero, L_800257F8
    if (ctx->r2 == 0) {
        // 0x80025648: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_800257F8;
    }
    // 0x80025648: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002564C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80025650: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025654: sw          $v0, -0x2608($at)
    MEM_W(-0X2608, ctx->r1) = ctx->r2;
    // 0x80025658: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002565C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025660: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
    // 0x80025664: sw          $v1, -0x2604($at)
    MEM_W(-0X2604, ctx->r1) = ctx->r3;
    // 0x80025668: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8002566C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80025670: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80025674: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x80025678: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8002567C: blez        $s0, L_800257F8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80025680: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800257F8;
    }
    // 0x80025680: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80025684: andi        $t1, $s0, 0x3
    ctx->r9 = ctx->r16 & 0X3;
    // 0x80025688: beq         $t1, $zero, L_800256E4
    if (ctx->r9 == 0) {
        // 0x8002568C: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_800256E4;
    }
    // 0x8002568C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80025690: sll         $v0, $zero, 4
    ctx->r2 = S32(0 << 4);
L_80025694:
    // 0x80025694: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80025698: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002569C: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800256A0: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
    // 0x800256A4: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800256A8: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800256AC: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x800256B0: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
    // 0x800256B4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800256B8: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800256BC: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800256C0: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
    // 0x800256C4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800256C8: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800256CC: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800256D0: sw          $v1, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r3;
    // 0x800256D4: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800256D8: bne         $a1, $a0, L_80025694
    if (ctx->r5 != ctx->r4) {
        // 0x800256DC: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_80025694;
    }
    // 0x800256DC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800256E0: beq         $a0, $s0, L_800257F8
    if (ctx->r4 == ctx->r16) {
        // 0x800256E4: sll         $v0, $a0, 4
        ctx->r2 = S32(ctx->r4 << 4);
            goto L_800257F8;
    }
L_800256E4:
    // 0x800256E4: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800256E8: sll         $a1, $s0, 4
    ctx->r5 = S32(ctx->r16 << 4);
L_800256EC:
    // 0x800256EC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800256F0: nop

    // 0x800256F4: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800256F8: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
    // 0x800256FC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80025700: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025704: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80025708: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
    // 0x8002570C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80025710: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025714: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80025718: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
    // 0x8002571C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80025720: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025724: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80025728: sw          $v1, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r3;
    // 0x8002572C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80025730: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025734: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x80025738: sw          $v1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r3;
    // 0x8002573C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80025740: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025744: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80025748: sw          $v1, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r3;
    // 0x8002574C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80025750: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025754: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80025758: sw          $v1, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r3;
    // 0x8002575C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80025760: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025764: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80025768: sw          $v1, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r3;
    // 0x8002576C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80025770: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80025774: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x80025778: sw          $v1, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r3;
    // 0x8002577C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80025780: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025784: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x80025788: sw          $v1, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r3;
    // 0x8002578C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80025790: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80025794: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80025798: sw          $v1, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r3;
    // 0x8002579C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800257A0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800257A4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800257A8: sw          $v1, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r3;
    // 0x800257AC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800257B0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800257B4: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800257B8: sw          $v1, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r3;
    // 0x800257BC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800257C0: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800257C4: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x800257C8: sw          $v1, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r3;
    // 0x800257CC: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800257D0: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800257D4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800257D8: sw          $v1, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r3;
    // 0x800257DC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800257E0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800257E4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800257E8: sw          $v1, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r3;
    // 0x800257EC: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800257F0: bne         $v0, $a1, L_800256EC
    if (ctx->r2 != ctx->r5) {
        // 0x800257F4: addu        $v1, $v1, $a3
        ctx->r3 = ADD32(ctx->r3, ctx->r7);
            goto L_800256EC;
    }
    // 0x800257F4: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
L_800257F8:
    // 0x800257F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800257FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025800: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80025804: sb          $zero, -0x25CC($at)
    MEM_B(-0X25CC, ctx->r1) = 0;
    // 0x80025808: jr          $ra
    // 0x8002580C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002580C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void set_drumstick_unlock_transition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DAE4: addiu       $t6, $zero, 0x2C
    ctx->r14 = ADD32(0, 0X2C);
    // 0x8006DAE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006DAEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DAF0: sb          $t6, -0x2700($at)
    MEM_B(-0X2700, ctx->r1) = ctx->r14;
    // 0x8006DAF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DAF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DAFC: jal         0x80094AE8
    // 0x8006DB00: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    menu_close_dialogue(rdram, ctx);
        goto after_0;
    // 0x8006DB00: sb          $zero, 0x3A95($at)
    MEM_B(0X3A95, ctx->r1) = 0;
    after_0:
    // 0x8006DB04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006DB08: jal         0x800C06F8
    // 0x8006DB0C: addiu       $a0, $a0, -0x2688
    ctx->r4 = ADD32(ctx->r4, -0X2688);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8006DB0C: addiu       $a0, $a0, -0x2688
    ctx->r4 = ADD32(ctx->r4, -0X2688);
    after_1:
    // 0x8006DB10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DB14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006DB18: jr          $ra
    // 0x8006DB1C: nop

    return;
    // 0x8006DB1C: nop

;}
RECOMP_FUNC void get_active_player_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C91C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C924: jal         0x8006BFF0
    // 0x8009C928: nop

    level_header(rdram, ctx);
        goto after_0;
    // 0x8009C928: nop

    after_0:
    // 0x8009C92C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C930: lw          $t6, -0x5C0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C0);
    // 0x8009C934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C938: beq         $t6, $zero, L_8009C970
    if (ctx->r14 == 0) {
        // 0x8009C93C: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8009C970;
    }
    // 0x8009C93C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009C940: lw          $t7, -0x5C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5C8);
    // 0x8009C944: nop

    // 0x8009C948: bne         $t7, $zero, L_8009C970
    if (ctx->r15 != 0) {
        // 0x8009C94C: nop
    
            goto L_8009C970;
    }
    // 0x8009C94C: nop

    // 0x8009C950: lb          $v1, 0x4C($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X4C);
    // 0x8009C954: nop

    // 0x8009C958: beq         $v1, $zero, L_8009C968
    if (ctx->r3 == 0) {
        // 0x8009C95C: andi        $t8, $v1, 0x40
        ctx->r24 = ctx->r3 & 0X40;
            goto L_8009C968;
    }
    // 0x8009C95C: andi        $t8, $v1, 0x40
    ctx->r24 = ctx->r3 & 0X40;
    // 0x8009C960: beq         $t8, $zero, L_8009C970
    if (ctx->r24 == 0) {
        // 0x8009C964: nop
    
            goto L_8009C970;
    }
    // 0x8009C964: nop

L_8009C968:
    // 0x8009C968: b           L_8009C97C
    // 0x8009C96C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8009C97C;
    // 0x8009C96C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8009C970:
    // 0x8009C970: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C974: lw          $v0, -0x5C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5C4);
    // 0x8009C978: nop

L_8009C97C:
    // 0x8009C97C: jr          $ra
    // 0x8009C980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009C980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void write_controller_pak_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007692C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80076930: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80076934: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80076938: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8007693C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80076940: jal         0x80075B34
    // 0x80076944: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80076944: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_0:
    // 0x80076948: beq         $v0, $zero, L_80076968
    if (ctx->r2 == 0) {
        // 0x8007694C: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_80076968;
    }
    // 0x8007694C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80076950: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80076954: jal         0x80075D44
    // 0x80076958: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80076958: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x8007695C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80076960: b           L_80076B70
    // 0x80076964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80076B70;
    // 0x80076964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80076968:
    // 0x80076968: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8007696C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80076970: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80076974: beq         $v0, $zero, L_80076984
    if (ctx->r2 == 0) {
        // 0x80076978: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80076984;
    }
    // 0x80076978: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8007697C: subu        $a3, $v1, $v0
    ctx->r7 = SUB32(ctx->r3, ctx->r2);
    // 0x80076980: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
L_80076984:
    // 0x80076984: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80076988: jal         0x80076C90
    // 0x8007698C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    string_to_font_codes(rdram, ctx);
        goto after_2;
    // 0x8007698C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_2:
    // 0x80076990: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80076994: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80076998: jal         0x80076C90
    // 0x8007699C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    string_to_font_codes(rdram, ctx);
        goto after_3;
    // 0x8007699C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x800769A0: jal         0x8009F064
    // 0x800769A4: nop

    get_language(rdram, ctx);
        goto after_4;
    // 0x800769A4: nop

    after_4:
    // 0x800769A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800769AC: bne         $v0, $at, L_800769C4
    if (ctx->r2 != ctx->r1) {
        // 0x800769B0: lui         $t7, 0x8000
        ctx->r15 = S32(0X8000 << 16);
            goto L_800769C4;
    }
    // 0x800769B0: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800769B4: lui         $t6, 0x4E44
    ctx->r14 = S32(0X4E44 << 16);
    // 0x800769B8: ori         $t6, $t6, 0x594A
    ctx->r14 = ctx->r14 | 0X594A;
    // 0x800769BC: b           L_800769E8
    // 0x800769C0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
        goto L_800769E8;
    // 0x800769C0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_800769C4:
    // 0x800769C4: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800769C8: lui         $t9, 0x4E44
    ctx->r25 = S32(0X4E44 << 16);
    // 0x800769CC: bne         $t7, $zero, L_800769E4
    if (ctx->r15 != 0) {
        // 0x800769D0: ori         $t9, $t9, 0x5945
        ctx->r25 = ctx->r25 | 0X5945;
            goto L_800769E4;
    }
    // 0x800769D0: ori         $t9, $t9, 0x5945
    ctx->r25 = ctx->r25 | 0X5945;
    // 0x800769D4: lui         $t8, 0x4E44
    ctx->r24 = S32(0X4E44 << 16);
    // 0x800769D8: ori         $t8, $t8, 0x5950
    ctx->r24 = ctx->r24 | 0X5950;
    // 0x800769DC: b           L_800769E8
    // 0x800769E0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_800769E8;
    // 0x800769E0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_800769E4:
    // 0x800769E4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_800769E8:
    // 0x800769E8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800769EC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800769F0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x800769F4: jal         0x80076740
    // 0x800769F8: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    get_file_number(rdram, ctx);
        goto after_5;
    // 0x800769F8: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x800769FC: bne         $v0, $zero, L_80076A2C
    if (ctx->r2 != 0) {
        // 0x80076A00: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80076A2C;
    }
    // 0x80076A00: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076A04: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80076A08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80076A0C: beq         $v0, $at, L_80076AC0
    if (ctx->r2 == ctx->r1) {
        // 0x80076A10: nop
    
            goto L_80076AC0;
    }
    // 0x80076A10: nop

    // 0x80076A14: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80076A18: nop

    // 0x80076A1C: beq         $v0, $t0, L_80076AC0
    if (ctx->r2 == ctx->r8) {
        // 0x80076A20: nop
    
            goto L_80076AC0;
    }
    // 0x80076A20: nop

    // 0x80076A24: b           L_80076AC0
    // 0x80076A28: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_80076AC0;
    // 0x80076A28: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80076A2C:
    // 0x80076A2C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80076A30: bne         $v0, $at, L_80076AC0
    if (ctx->r2 != ctx->r1) {
        // 0x80076A34: nop
    
            goto L_80076AC0;
    }
    // 0x80076A34: nop

    // 0x80076A38: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80076A3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80076A40: beq         $t1, $at, L_80076A50
    if (ctx->r9 == ctx->r1) {
        // 0x80076A44: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80076A50;
    }
    // 0x80076A44: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80076A48: b           L_80076AC0
    // 0x80076A4C: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
        goto L_80076AC0;
    // 0x80076A4C: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80076A50:
    // 0x80076A50: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80076A54: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80076A58: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80076A5C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80076A60: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80076A64: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80076A68: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80076A6C: addiu       $t4, $t4, 0x4598
    ctx->r12 = ADD32(ctx->r12, 0X4598);
    // 0x80076A70: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80076A74: addiu       $t5, $sp, 0x3C
    ctx->r13 = ADD32(ctx->r29, 0X3C);
    // 0x80076A78: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
    // 0x80076A7C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80076A80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80076A84: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80076A88: addiu       $a1, $zero, 0x3459
    ctx->r5 = ADD32(0, 0X3459);
    // 0x80076A8C: addiu       $a3, $sp, 0x44
    ctx->r7 = ADD32(ctx->r29, 0X44);
    // 0x80076A90: jal         0x800D15A0
    // 0x80076A94: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    osPfsAllocateFile_recomp(rdram, ctx);
        goto after_6;
    // 0x80076A94: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x80076A98: bne         $v0, $zero, L_80076AA8
    if (ctx->r2 != 0) {
        // 0x80076A9C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80076AA8;
    }
    // 0x80076A9C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80076AA0: b           L_80076AC0
    // 0x80076AA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80076AC0;
    // 0x80076AA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80076AA8:
    // 0x80076AA8: beq         $v0, $at, L_80076AB8
    if (ctx->r2 == ctx->r1) {
        // 0x80076AAC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80076AB8;
    }
    // 0x80076AAC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80076AB0: bne         $v0, $at, L_80076AC0
    if (ctx->r2 != ctx->r1) {
        // 0x80076AB4: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80076AC0;
    }
    // 0x80076AB4: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80076AB8:
    // 0x80076AB8: b           L_80076AC0
    // 0x80076ABC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_80076AC0;
    // 0x80076ABC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80076AC0:
    // 0x80076AC0: bne         $v1, $zero, L_80076B58
    if (ctx->r3 != 0) {
        // 0x80076AC4: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80076B58;
    }
    // 0x80076AC4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80076AC8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80076ACC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80076AD0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80076AD4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80076AD8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80076ADC: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80076AE0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80076AE4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80076AE8: addiu       $t0, $t0, 0x4598
    ctx->r8 = ADD32(ctx->r8, 0X4598);
    // 0x80076AEC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80076AF0: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80076AF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80076AF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80076AFC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80076B00: jal         0x800CF53C
    // 0x80076B04: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_7;
    // 0x80076B04: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_7:
    // 0x80076B08: bne         $v0, $zero, L_80076B18
    if (ctx->r2 != 0) {
        // 0x80076B0C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80076B18;
    }
    // 0x80076B0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80076B10: b           L_80076B58
    // 0x80076B14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80076B58;
    // 0x80076B14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80076B18:
    // 0x80076B18: beq         $v0, $at, L_80076B28
    if (ctx->r2 == ctx->r1) {
        // 0x80076B1C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80076B28;
    }
    // 0x80076B1C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80076B20: bne         $v0, $at, L_80076B34
    if (ctx->r2 != ctx->r1) {
        // 0x80076B24: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80076B34;
    }
    // 0x80076B24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80076B28:
    // 0x80076B28: b           L_80076B58
    // 0x80076B2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80076B58;
    // 0x80076B2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80076B30: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80076B34:
    // 0x80076B34: bne         $v0, $at, L_80076B48
    if (ctx->r2 != ctx->r1) {
        // 0x80076B38: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80076B48;
    }
    // 0x80076B38: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80076B3C: b           L_80076B58
    // 0x80076B40: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80076B58;
    // 0x80076B40: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80076B44: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80076B48:
    // 0x80076B48: bne         $v0, $at, L_80076B58
    if (ctx->r2 != ctx->r1) {
        // 0x80076B4C: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80076B58;
    }
    // 0x80076B4C: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x80076B50: b           L_80076B58
    // 0x80076B54: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80076B58;
    // 0x80076B54: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80076B58:
    // 0x80076B58: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80076B5C: jal         0x80075D44
    // 0x80076B60: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x80076B60: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_8:
    // 0x80076B64: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80076B68: nop

    // 0x80076B6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80076B70:
    // 0x80076B70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80076B74: jr          $ra
    // 0x80076B78: nop

    return;
    // 0x80076B78: nop

;}
RECOMP_FUNC void ainode_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D1E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001D1E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001D1E8: jr          $ra
    // 0x8001D1EC: sw          $t6, -0x4B70($at)
    MEM_W(-0X4B70, ctx->r1) = ctx->r14;
    return;
    // 0x8001D1EC: sw          $t6, -0x4B70($at)
    MEM_W(-0X4B70, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8001F3C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F3FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001F400: addiu       $v0, $v0, -0x4CAC
    ctx->r2 = ADD32(ctx->r2, -0X4CAC);
    // 0x8001F404: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001F408: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001F40C: beq         $a0, $t6, L_8001F418
    if (ctx->r4 == ctx->r14) {
        // 0x8001F410: nop
    
            goto L_8001F418;
    }
    // 0x8001F410: nop

    // 0x8001F414: sh          $zero, -0x4C08($at)
    MEM_H(-0X4C08, ctx->r1) = 0;
L_8001F418:
    // 0x8001F418: jr          $ra
    // 0x8001F41C: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x8001F41C: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void mtxs_transform_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FCB8: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x8006FCBC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8006FCC0: lh          $t1, 0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X2);
    // 0x8006FCC4: lh          $t2, 0x4($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X4);
    // 0x8006FCC8: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FCCC: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    // 0x8006FCD0: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FCD4: nop

    // 0x8006FCD8: nop

    // 0x8006FCDC: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FCE0: lw          $t3, 0x20($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X20);
    // 0x8006FCE4: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FCE8: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FCEC: nop

    // 0x8006FCF0: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FCF4: lw          $t3, 0x30($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X30);
    // 0x8006FCF8: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FCFC: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FD00: add         $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006FD04: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FD08: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x8006FD0C: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8006FD10: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD14: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8006FD18: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FD1C: nop

    // 0x8006FD20: nop

    // 0x8006FD24: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD28: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x8006FD2C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FD30: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FD34: nop

    // 0x8006FD38: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD3C: lw          $t3, 0x34($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X34);
    // 0x8006FD40: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FD44: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FD48: add         $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006FD4C: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FD50: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x8006FD54: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x8006FD58: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD5C: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x8006FD60: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FD64: nop

    // 0x8006FD68: nop

    // 0x8006FD6C: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD70: lw          $t3, 0x28($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X28);
    // 0x8006FD74: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FD78: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FD7C: nop

    // 0x8006FD80: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FD84: lw          $t3, 0x38($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X38);
    // 0x8006FD88: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FD8C: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FD90: add         $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8006FD94: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FD98: jr          $ra
    // 0x8006FD9C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
    return;
    // 0x8006FD9C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
;}
RECOMP_FUNC void obj_init_weaponballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E00C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E014: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E018: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003E01C: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003E020: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E024: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8003E028: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x8003E02C: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E030: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8003E034: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x8003E038: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003E03C: jal         0x8009C850
    // 0x8003E040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x8003E040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003E044: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003E048: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E04C: sll         $t2, $v0, 14
    ctx->r10 = S32(ctx->r2 << 14);
    // 0x8003E050: bgez        $t2, L_8003E060
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8003E054: andi        $t3, $v0, 0x8000
        ctx->r11 = ctx->r2 & 0X8000;
            goto L_8003E060;
    }
    // 0x8003E054: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    // 0x8003E058: b           L_8003E0A8
    // 0x8003E05C: sb          $zero, 0x9($a1)
    MEM_B(0X9, ctx->r5) = 0;
        goto L_8003E0A8;
    // 0x8003E05C: sb          $zero, 0x9($a1)
    MEM_B(0X9, ctx->r5) = 0;
L_8003E060:
    // 0x8003E060: beq         $t3, $zero, L_8003E074
    if (ctx->r11 == 0) {
        // 0x8003E064: sll         $t5, $v0, 15
        ctx->r13 = S32(ctx->r2 << 15);
            goto L_8003E074;
    }
    // 0x8003E064: sll         $t5, $v0, 15
    ctx->r13 = S32(ctx->r2 << 15);
    // 0x8003E068: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003E06C: b           L_8003E0A8
    // 0x8003E070: sb          $t4, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r12;
        goto L_8003E0A8;
    // 0x8003E070: sb          $t4, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r12;
L_8003E074:
    // 0x8003E074: bgez        $t5, L_8003E088
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8003E078: sll         $t7, $v0, 13
        ctx->r15 = S32(ctx->r2 << 13);
            goto L_8003E088;
    }
    // 0x8003E078: sll         $t7, $v0, 13
    ctx->r15 = S32(ctx->r2 << 13);
    // 0x8003E07C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003E080: b           L_8003E0A8
    // 0x8003E084: sb          $t6, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r14;
        goto L_8003E0A8;
    // 0x8003E084: sb          $t6, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r14;
L_8003E088:
    // 0x8003E088: bgez        $t7, L_8003E09C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8003E08C: sll         $t9, $v0, 12
        ctx->r25 = S32(ctx->r2 << 12);
            goto L_8003E09C;
    }
    // 0x8003E08C: sll         $t9, $v0, 12
    ctx->r25 = S32(ctx->r2 << 12);
    // 0x8003E090: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8003E094: b           L_8003E0A8
    // 0x8003E098: sb          $t8, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r24;
        goto L_8003E0A8;
    // 0x8003E098: sb          $t8, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r24;
L_8003E09C:
    // 0x8003E09C: bgez        $t9, L_8003E0A8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8003E0A0: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8003E0A8;
    }
    // 0x8003E0A0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003E0A4: sb          $t0, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r8;
L_8003E0A8:
    // 0x8003E0A8: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003E0AC: nop

    // 0x8003E0B0: slti        $at, $t1, 0x6
    ctx->r1 = SIGNED(ctx->r9) < 0X6 ? 1 : 0;
    // 0x8003E0B4: bne         $at, $zero, L_8003E0C0
    if (ctx->r1 != 0) {
        // 0x8003E0B8: nop
    
            goto L_8003E0C0;
    }
    // 0x8003E0B8: nop

    // 0x8003E0BC: sb          $zero, 0x8($a1)
    MEM_B(0X8, ctx->r5) = 0;
L_8003E0C0:
    // 0x8003E0C0: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x8003E0C4: lb          $t2, 0x3A($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X3A);
    // 0x8003E0C8: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x8003E0CC: nop

    // 0x8003E0D0: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003E0D4: bne         $at, $zero, L_8003E0E0
    if (ctx->r1 != 0) {
        // 0x8003E0D8: nop
    
            goto L_8003E0E0;
    }
    // 0x8003E0D8: nop

    // 0x8003E0DC: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003E0E0:
    // 0x8003E0E0: lbu         $t5, 0x9($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X9);
    // 0x8003E0E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003E0E8: sb          $t5, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r13;
    // 0x8003E0EC: lb          $t6, 0x3A($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3A);
    // 0x8003E0F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003E0F4: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x8003E0F8: lbu         $t8, 0xA($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XA);
    // 0x8003E0FC: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003E100: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8003E104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003E108: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003E10C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003E110: nop

    // 0x8003E114: bc1f        L_8003E124
    if (!c1cs) {
        // 0x8003E118: nop
    
            goto L_8003E124;
    }
    // 0x8003E118: nop

    // 0x8003E11C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003E120: nop

L_8003E124:
    // 0x8003E124: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003E128: lw          $t9, 0x40($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X40);
    // 0x8003E12C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003E130: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8003E134: nop

    // 0x8003E138: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003E13C: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x8003E140: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003E144: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8003E148: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8003E14C: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8003E150: jal         0x8009C850
    // 0x8003E154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_1;
    // 0x8003E154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003E158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003E15C: andi        $t0, $v0, 0x800
    ctx->r8 = ctx->r2 & 0X800;
    // 0x8003E160: beq         $t0, $zero, L_8003E174
    if (ctx->r8 == 0) {
        // 0x8003E164: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003E174;
    }
    // 0x8003E164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E168: jal         0x8000FFB8
    // 0x8003E16C: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x8003E16C: nop

    after_2:
    // 0x8003E170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E174:
    // 0x8003E174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E178: jr          $ra
    // 0x8003E17C: nop

    return;
    // 0x8003E17C: nop

;}
RECOMP_FUNC void erase_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074574: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80074578: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007457C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80074580: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80074584: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80074588: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007458C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80074590: jal         0x8006A340
    // 0x80074594: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074594: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80074598: jal         0x800CE770
    // 0x8007459C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x8007459C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800745A0: beq         $v0, $zero, L_80074718
    if (ctx->r2 == 0) {
        // 0x800745A4: addiu       $a0, $sp, 0x44
        ctx->r4 = ADD32(ctx->r29, 0X44);
            goto L_80074718;
    }
    // 0x800745A4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800745A8: jal         0x8006B464
    // 0x800745AC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    level_count(rdram, ctx);
        goto after_2;
    // 0x800745AC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x800745B0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800745B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800745B8: blez        $t6, L_800745EC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800745BC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800745EC;
    }
    // 0x800745BC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800745C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800745C4:
    // 0x800745C4: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800745C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800745CC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800745D0: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800745D4: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800745D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800745DC: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800745E0: bne         $at, $zero, L_800745C4
    if (ctx->r1 != 0) {
        // 0x800745E4: nop
    
            goto L_800745C4;
    }
    // 0x800745E4: nop

    // 0x800745E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800745EC:
    // 0x800745EC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800745F0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x800745F4: blez        $t0, L_80074628
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800745F8: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_80074628;
    }
    // 0x800745F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800745FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80074600:
    // 0x80074600: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80074604: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074608: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8007460C: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x80074610: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80074614: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80074618: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007461C: bne         $at, $zero, L_80074600
    if (ctx->r1 != 0) {
        // 0x80074620: nop
    
            goto L_80074600;
    }
    // 0x80074620: nop

    // 0x80074624: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80074628:
    // 0x80074628: sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
    // 0x8007462C: sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // 0x80074630: sh          $zero, 0x14($s1)
    MEM_H(0X14, ctx->r17) = 0;
    // 0x80074634: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x80074638: beq         $s2, $zero, L_8007465C
    if (ctx->r18 == 0) {
        // 0x8007463C: sb          $t4, 0x4B($s1)
        MEM_B(0X4B, ctx->r17) = ctx->r12;
            goto L_8007465C;
    }
    // 0x8007463C: sb          $t4, 0x4B($s1)
    MEM_B(0X4B, ctx->r17) = ctx->r12;
    // 0x80074640: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80074644: beq         $s2, $at, L_80074664
    if (ctx->r18 == ctx->r1) {
        // 0x80074648: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80074664;
    }
    // 0x80074648: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007464C: beq         $s2, $at, L_8007466C
    if (ctx->r18 == ctx->r1) {
        // 0x80074650: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8007466C;
    }
    // 0x80074650: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80074654: b           L_8007466C
    // 0x80074658: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
        goto L_8007466C;
    // 0x80074658: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_8007465C:
    // 0x8007465C: b           L_8007466C
    // 0x80074660: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8007466C;
    // 0x80074660: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80074664:
    // 0x80074664: b           L_8007466C
    // 0x80074668: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
        goto L_8007466C;
    // 0x80074668: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
L_8007466C:
    // 0x8007466C: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80074670: jal         0x80070EDC
    // 0x80074674: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80074674: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_3:
    // 0x80074678: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8007467C: b           L_800746A8
    // 0x80074680: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
        goto L_800746A8;
    // 0x80074680: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80074684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80074688: addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
    // 0x8007468C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80074690:
    // 0x80074690: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074694: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80074698: bne         $a1, $s0, L_80074690
    if (ctx->r5 != ctx->r16) {
        // 0x8007469C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80074690;
    }
    // 0x8007469C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800746A0: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800746A4: beq         $s0, $at, L_800746D0
    if (ctx->r16 == ctx->r1) {
        // 0x800746A8: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800746D0;
    }
L_800746A8:
    // 0x800746A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800746AC: sll         $a1, $s2, 3
    ctx->r5 = S32(ctx->r18 << 3);
    // 0x800746B0: addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
L_800746B4:
    // 0x800746B4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800746B8: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x800746BC: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x800746C0: sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // 0x800746C4: sb          $a0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r4;
    // 0x800746C8: bne         $s0, $a1, L_800746B4
    if (ctx->r16 != ctx->r5) {
        // 0x800746CC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800746B4;
    }
    // 0x800746CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800746D0:
    // 0x800746D0: jal         0x8006ED00
    // 0x800746D4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    is_reset_pressed(rdram, ctx);
        goto after_4;
    // 0x800746D4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_4:
    // 0x800746D8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800746DC: bne         $v0, $zero, L_80074710
    if (ctx->r2 != 0) {
        // 0x800746E0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80074710;
    }
    // 0x800746E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800746E4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
L_800746E8:
    // 0x800746E8: jal         0x8006A340
    // 0x800746EC: nop

    si_mesg(rdram, ctx);
        goto after_5;
    // 0x800746EC: nop

    after_5:
    // 0x800746F0: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
    // 0x800746F4: addu        $a2, $t5, $s3
    ctx->r6 = ADD32(ctx->r13, ctx->r19);
    // 0x800746F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800746FC: jal         0x800CEAE0
    // 0x80074700: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    osEepromWrite_recomp(rdram, ctx);
        goto after_6;
    // 0x80074700: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_6:
    // 0x80074704: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074708: bne         $s0, $s2, L_800746E8
    if (ctx->r16 != ctx->r18) {
        // 0x8007470C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800746E8;
    }
    // 0x8007470C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80074710:
    // 0x80074710: jal         0x80071380
    // 0x80074714: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80074714: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
L_80074718:
    // 0x80074718: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007471C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80074720: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80074724: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80074728: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007472C: jr          $ra
    // 0x80074730: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80074730: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void obj_init_bombexplosion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038BB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038BB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80038BBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038BC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038BC8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80038BCC: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x80038BD0: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x80038BD4: lw          $t6, 0x40($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X40);
    // 0x80038BD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80038BDC: lb          $a1, 0x55($t6)
    ctx->r5 = MEM_B(ctx->r14, 0X55);
    // 0x80038BE0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80038BE4: jal         0x8006FB8C
    // 0x80038BE8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x80038BE8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_0:
    // 0x80038BEC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80038BF0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80038BF4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80038BF8: sb          $v0, 0x3A($a2)
    MEM_B(0X3A, ctx->r6) = ctx->r2;
    // 0x80038BFC: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x80038C00: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80038C04: lb          $v1, 0x8($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X8);
    // 0x80038C08: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80038C0C: beq         $v1, $zero, L_80038C20
    if (ctx->r3 == 0) {
        // 0x80038C10: sll         $t9, $v1, 8
        ctx->r25 = S32(ctx->r3 << 8);
            goto L_80038C20;
    }
    // 0x80038C10: sll         $t9, $v1, 8
    ctx->r25 = S32(ctx->r3 << 8);
    // 0x80038C14: andi        $t0, $t9, 0xFF00
    ctx->r8 = ctx->r25 & 0XFF00;
    // 0x80038C18: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80038C1C: sw          $t1, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r9;
L_80038C20:
    // 0x80038C20: sw          $t2, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r10;
    // 0x80038C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038C2C: jr          $ra
    // 0x80038C30: nop

    return;
    // 0x80038C30: nop

;}
RECOMP_FUNC void cheatmenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B40: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80089B44: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80089B48: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80089B4C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80089B50: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80089B54: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80089B58: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80089B5C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80089B60: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80089B64: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80089B68: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80089B6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80089B70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80089B74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089B78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089B7C: jal         0x800C492C
    // 0x80089B80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_0;
    // 0x80089B80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80089B84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089B88: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089B8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089B94: jal         0x800C60B8
    // 0x80089B98: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_1;
    // 0x80089B98: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_1:
    // 0x80089B9C: jal         0x800C484C
    // 0x80089BA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x80089BA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80089BA4: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80089BA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80089BAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80089BB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089BB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089BB8: jal         0x800C48E4
    // 0x80089BBC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x80089BBC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x80089BC0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80089BC4: lw          $t7, -0x5E0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E0);
    // 0x80089BC8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089BCC: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80089BD0: lw          $a3, 0x44($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X44);
    // 0x80089BD4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80089BD8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089BDC: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80089BE0: jal         0x800C49A0
    // 0x80089BE4: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_4;
    // 0x80089BE4: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_4:
    // 0x80089BE8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80089BEC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089BF0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089BF4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089BF8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089BFC: jal         0x800C48E4
    // 0x80089C00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_5;
    // 0x80089C00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80089C04: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80089C08: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x80089C0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089C10: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80089C14: lw          $a3, 0x44($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X44);
    // 0x80089C18: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80089C1C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089C20: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80089C24: jal         0x800C49A0
    // 0x80089C28: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x80089C28: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_6:
    // 0x80089C2C: addiu       $s3, $zero, 0x41
    ctx->r19 = ADD32(0, 0X41);
    // 0x80089C30: jal         0x800C484C
    // 0x80089C34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x80089C34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80089C38: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80089C3C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089C40: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089C44: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089C48: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089C4C: jal         0x800C48E4
    // 0x80089C50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x80089C50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80089C54: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80089C58: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80089C5C: addiu       $s5, $s5, 0x7202
    ctx->r21 = ADD32(ctx->r21, 0X7202);
    // 0x80089C60: addiu       $s6, $s6, 0x7200
    ctx->r22 = ADD32(ctx->r22, 0X7200);
    // 0x80089C64: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80089C68: addiu       $s4, $zero, 0x3C
    ctx->r20 = ADD32(0, 0X3C);
    // 0x80089C6C: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
L_80089C70:
    // 0x80089C70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80089C74: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
L_80089C78:
    // 0x80089C78: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80089C7C: lh          $t4, 0x7206($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7206);
    // 0x80089C80: nop

    // 0x80089C84: bne         $s7, $t4, L_80089CE8
    if (ctx->r23 != ctx->r12) {
        // 0x80089C88: slti        $at, $s3, 0x5B
        ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
            goto L_80089CE8;
    }
    // 0x80089C88: slti        $at, $s3, 0x5B
    ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
    // 0x80089C8C: lh          $t5, 0x0($s5)
    ctx->r13 = MEM_H(ctx->r21, 0X0);
    // 0x80089C90: nop

    // 0x80089C94: bne         $s0, $t5, L_80089CE8
    if (ctx->r16 != ctx->r13) {
        // 0x80089C98: slti        $at, $s3, 0x5B
        ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
            goto L_80089CE8;
    }
    // 0x80089C98: slti        $at, $s3, 0x5B
    ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
    // 0x80089C9C: lh          $t6, 0x0($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X0);
    // 0x80089CA0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80089CA4: bne         $fp, $t6, L_80089CE4
    if (ctx->r30 != ctx->r14) {
        // 0x80089CA8: addiu       $a0, $zero, 0x80
        ctx->r4 = ADD32(0, 0X80);
            goto L_80089CE4;
    }
    // 0x80089CA8: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80089CAC: lw          $s2, 0x695C($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X695C);
    // 0x80089CB0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089CB4: sll         $t7, $s2, 3
    ctx->r15 = S32(ctx->r18 << 3);
    // 0x80089CB8: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80089CBC: bne         $at, $zero, L_80089CCC
    if (ctx->r1 != 0) {
        // 0x80089CC0: or          $s2, $t7, $zero
        ctx->r18 = ctx->r15 | 0;
            goto L_80089CCC;
    }
    // 0x80089CC0: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80089CC4: addiu       $t8, $zero, 0x1FF
    ctx->r24 = ADD32(0, 0X1FF);
    // 0x80089CC8: subu        $s2, $t8, $t7
    ctx->r18 = SUB32(ctx->r24, ctx->r15);
L_80089CCC:
    // 0x80089CCC: sra         $t9, $s2, 1
    ctx->r25 = S32(SIGNED(ctx->r18) >> 1);
    // 0x80089CD0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80089CD4: addiu       $a3, $t9, 0x80
    ctx->r7 = ADD32(ctx->r25, 0X80);
    // 0x80089CD8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089CDC: jal         0x800C48E4
    // 0x80089CE0: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    set_text_colour(rdram, ctx);
        goto after_9;
    // 0x80089CE0: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    after_9:
L_80089CE4:
    // 0x80089CE4: slti        $at, $s3, 0x5B
    ctx->r1 = SIGNED(ctx->r19) < 0X5B ? 1 : 0;
L_80089CE8:
    // 0x80089CE8: beq         $at, $zero, L_80089D1C
    if (ctx->r1 == 0) {
        // 0x80089CEC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80089D1C;
    }
    // 0x80089CEC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089CF0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80089CF4: sb          $s3, 0x5C($sp)
    MEM_B(0X5C, ctx->r29) = ctx->r19;
    // 0x80089CF8: sb          $zero, 0x5D($sp)
    MEM_B(0X5D, ctx->r29) = 0;
    // 0x80089CFC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80089D00: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089D04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80089D08: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80089D0C: jal         0x800C49A0
    // 0x80089D10: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    draw_text(rdram, ctx);
        goto after_10;
    // 0x80089D10: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_10:
    // 0x80089D14: b           L_80089D70
    // 0x80089D18: nop

        goto L_80089D70;
    // 0x80089D18: nop

L_80089D1C:
    // 0x80089D1C: bne         $s0, $s7, L_80089D50
    if (ctx->r16 != ctx->r23) {
        // 0x80089D20: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80089D50;
    }
    // 0x80089D20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089D24: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089D28: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80089D2C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80089D30: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089D34: addiu       $a3, $a3, -0x7860
    ctx->r7 = ADD32(ctx->r7, -0X7860);
    // 0x80089D38: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089D3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80089D40: jal         0x800C49A0
    // 0x80089D44: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    draw_text(rdram, ctx);
        goto after_11;
    // 0x80089D44: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_11:
    // 0x80089D48: b           L_80089D70
    // 0x80089D4C: nop

        goto L_80089D70;
    // 0x80089D4C: nop

L_80089D50:
    // 0x80089D50: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80089D54: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80089D58: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80089D5C: addiu       $a3, $a3, -0x785C
    ctx->r7 = ADD32(ctx->r7, -0X785C);
    // 0x80089D60: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089D64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80089D68: jal         0x800C49A0
    // 0x80089D6C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    draw_text(rdram, ctx);
        goto after_12;
    // 0x80089D6C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_12:
L_80089D70:
    // 0x80089D70: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80089D74: lh          $t5, 0x7206($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7206);
    // 0x80089D78: nop

    // 0x80089D7C: bne         $s7, $t5, L_80089DB8
    if (ctx->r23 != ctx->r13) {
        // 0x80089D80: nop
    
            goto L_80089DB8;
    }
    // 0x80089D80: nop

    // 0x80089D84: lh          $t6, 0x0($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X0);
    // 0x80089D88: nop

    // 0x80089D8C: bne         $s0, $t6, L_80089DB8
    if (ctx->r16 != ctx->r14) {
        // 0x80089D90: nop
    
            goto L_80089DB8;
    }
    // 0x80089D90: nop

    // 0x80089D94: lh          $t7, 0x0($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X0);
    // 0x80089D98: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089D9C: bne         $fp, $t7, L_80089DB8
    if (ctx->r30 != ctx->r15) {
        // 0x80089DA0: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80089DB8;
    }
    // 0x80089DA0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089DA4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80089DA8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80089DAC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089DB0: jal         0x800C48E4
    // 0x80089DB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x80089DB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
L_80089DB8:
    // 0x80089DB8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80089DBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80089DC0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80089DC4: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x80089DC8: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80089DCC: bne         $s0, $at, L_80089C78
    if (ctx->r16 != ctx->r1) {
        // 0x80089DD0: or          $s3, $t9, $zero
        ctx->r19 = ctx->r25 | 0;
            goto L_80089C78;
    }
    // 0x80089DD0: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80089DD4: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80089DD8: slti        $at, $fp, 0x4
    ctx->r1 = SIGNED(ctx->r30) < 0X4 ? 1 : 0;
    // 0x80089DDC: bne         $at, $zero, L_80089C70
    if (ctx->r1 != 0) {
        // 0x80089DE0: addiu       $s4, $s4, 0x16
        ctx->r20 = ADD32(ctx->r20, 0X16);
            goto L_80089C70;
    }
    // 0x80089DE0: addiu       $s4, $s4, 0x16
    ctx->r20 = ADD32(ctx->r20, 0X16);
    // 0x80089DE4: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80089DE8: lw          $s2, 0x695C($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X695C);
    // 0x80089DEC: nop

    // 0x80089DF0: sll         $t1, $s2, 3
    ctx->r9 = S32(ctx->r18 << 3);
    // 0x80089DF4: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x80089DF8: bne         $at, $zero, L_80089E08
    if (ctx->r1 != 0) {
        // 0x80089DFC: or          $s2, $t1, $zero
        ctx->r18 = ctx->r9 | 0;
            goto L_80089E08;
    }
    // 0x80089DFC: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
    // 0x80089E00: addiu       $t2, $zero, 0x1FF
    ctx->r10 = ADD32(0, 0X1FF);
    // 0x80089E04: subu        $s2, $t2, $t1
    ctx->r18 = SUB32(ctx->r10, ctx->r9);
L_80089E08:
    // 0x80089E08: jal         0x800C484C
    // 0x80089E0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_14;
    // 0x80089E0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x80089E10: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
    // 0x80089E14: addiu       $s6, $s6, 0x300
    ctx->r22 = ADD32(ctx->r22, 0X300);
    // 0x80089E18: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80089E1C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80089E20: addiu       $s3, $zero, 0xA4
    ctx->r19 = ADD32(0, 0XA4);
    // 0x80089E24: bne         $t3, $zero, L_80089E30
    if (ctx->r11 != 0) {
        // 0x80089E28: addiu       $s4, $zero, 0x10
        ctx->r20 = ADD32(0, 0X10);
            goto L_80089E30;
    }
    // 0x80089E28: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    // 0x80089E2C: addiu       $s4, $zero, 0x18
    ctx->r20 = ADD32(0, 0X18);
L_80089E30:
    // 0x80089E30: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80089E34: lw          $t4, 0x320($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X320);
    // 0x80089E38: sll         $t5, $fp, 2
    ctx->r13 = S32(ctx->r30 << 2);
    // 0x80089E3C: beq         $t4, $zero, L_80089EC8
    if (ctx->r12 == 0) {
        // 0x80089E40: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80089EC8;
    }
    // 0x80089E40: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80089E44: addiu       $t6, $t6, 0x320
    ctx->r14 = ADD32(ctx->r14, 0X320);
    // 0x80089E48: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80089E4C: addiu       $s5, $s5, 0x6980
    ctx->r21 = ADD32(ctx->r21, 0X6980);
    // 0x80089E50: addu        $s1, $t5, $t6
    ctx->r17 = ADD32(ctx->r13, ctx->r14);
L_80089E54:
    // 0x80089E54: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80089E58: lh          $t7, 0x7206($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7206);
    // 0x80089E5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80089E60: bne         $fp, $t7, L_80089E7C
    if (ctx->r30 != ctx->r15) {
        // 0x80089E64: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80089E7C;
    }
    // 0x80089E64: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089E68: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x80089E6C: nop

    // 0x80089E70: bne         $t8, $zero, L_80089E80
    if (ctx->r24 != 0) {
        // 0x80089E74: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_80089E80;
    }
    // 0x80089E74: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80089E78: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80089E7C:
    // 0x80089E7C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
L_80089E80:
    // 0x80089E80: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089E84: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089E88: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80089E8C: jal         0x800C48E4
    // 0x80089E90: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x80089E90: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_15:
    // 0x80089E94: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089E98: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80089E9C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80089EA0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089EA4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089EA8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089EAC: jal         0x800C49A0
    // 0x80089EB0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    draw_text(rdram, ctx);
        goto after_16;
    // 0x80089EB0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_16:
    // 0x80089EB4: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80089EB8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80089EBC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80089EC0: bne         $t2, $zero, L_80089E54
    if (ctx->r10 != 0) {
        // 0x80089EC4: addu        $s3, $s3, $s4
        ctx->r19 = ADD32(ctx->r19, ctx->r20);
            goto L_80089E54;
    }
    // 0x80089EC4: addu        $s3, $s3, $s4
    ctx->r19 = ADD32(ctx->r19, ctx->r20);
L_80089EC8:
    // 0x80089EC8: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80089ECC: addiu       $s5, $s5, 0x6980
    ctx->r21 = ADD32(ctx->r21, 0X6980);
    // 0x80089ED0: jal         0x800C484C
    // 0x80089ED4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_17;
    // 0x80089ED4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x80089ED8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80089EDC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089EE0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089EE4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089EE8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80089EEC: jal         0x800C48E4
    // 0x80089EF0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x80089EF0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_18:
    // 0x80089EF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80089EF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089EFC: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80089F00: jal         0x800C492C
    // 0x80089F04: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_text_background_colour(rdram, ctx);
        goto after_19;
    // 0x80089F04: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_19:
    // 0x80089F08: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089F0C: lh          $v0, 0x7206($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7206);
    // 0x80089F10: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089F14: bne         $v0, $at, L_80089F98
    if (ctx->r2 != ctx->r1) {
        // 0x80089F18: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80089F98;
    }
    // 0x80089F18: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80089F1C: lh          $t0, 0x720C($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X720C);
    // 0x80089F20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80089F24: bne         $t0, $at, L_80089F5C
    if (ctx->r8 != ctx->r1) {
        // 0x80089F28: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80089F5C;
    }
    // 0x80089F28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089F2C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80089F30: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x80089F34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089F38: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80089F3C: lw          $a3, 0x48($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X48);
    // 0x80089F40: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80089F44: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089F48: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089F4C: jal         0x800C49A0
    // 0x80089F50: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    draw_text(rdram, ctx);
        goto after_20;
    // 0x80089F50: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    after_20:
    // 0x80089F54: b           L_80089FFC
    // 0x80089F58: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
        goto L_80089FFC;
    // 0x80089F58: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089F5C:
    // 0x80089F5C: lw          $v0, 0x71F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71F0);
    // 0x80089F60: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x80089F64: addiu       $v1, $v0, 0x2
    ctx->r3 = ADD32(ctx->r2, 0X2);
    // 0x80089F68: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80089F6C: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x80089F70: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089F74: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80089F78: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089F7C: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089F80: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089F84: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80089F88: jal         0x800C49A0
    // 0x80089F8C: addu        $a3, $t8, $v0
    ctx->r7 = ADD32(ctx->r24, ctx->r2);
    draw_text(rdram, ctx);
        goto after_21;
    // 0x80089F8C: addu        $a3, $t8, $v0
    ctx->r7 = ADD32(ctx->r24, ctx->r2);
    after_21:
    // 0x80089F90: b           L_80089FFC
    // 0x80089F94: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
        goto L_80089FFC;
    // 0x80089F94: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089F98:
    // 0x80089F98: bne         $s7, $v0, L_80089FCC
    if (ctx->r23 != ctx->r2) {
        // 0x80089F9C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80089FCC;
    }
    // 0x80089F9C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80089FA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089FA4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80089FA8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80089FAC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089FB0: addiu       $a3, $a3, 0x7218
    ctx->r7 = ADD32(ctx->r7, 0X7218);
    // 0x80089FB4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089FB8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089FBC: jal         0x800C49A0
    // 0x80089FC0: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    draw_text(rdram, ctx);
        goto after_22;
    // 0x80089FC0: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    after_22:
    // 0x80089FC4: b           L_80089FFC
    // 0x80089FC8: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
        goto L_80089FFC;
    // 0x80089FC8: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089FCC:
    // 0x80089FCC: bne         $v0, $at, L_80089FF8
    if (ctx->r2 != ctx->r1) {
        // 0x80089FD0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80089FF8;
    }
    // 0x80089FD0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089FD4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80089FD8: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x80089FDC: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80089FE0: lw          $a3, 0x4C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X4C);
    // 0x80089FE4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80089FE8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80089FEC: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80089FF0: jal         0x800C49A0
    // 0x80089FF4: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    draw_text(rdram, ctx);
        goto after_23;
    // 0x80089FF4: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    after_23:
L_80089FF8:
    // 0x80089FF8: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
L_80089FFC:
    // 0x80089FFC: nop

    // 0x8008A000: beq         $t4, $zero, L_8008A128
    if (ctx->r12 == 0) {
        // 0x8008A004: nop
    
            goto L_8008A128;
    }
    // 0x8008A004: nop

    // 0x8008A008: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8008A00C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8008A010: bne         $t5, $zero, L_8008A020
    if (ctx->r13 != 0) {
        // 0x8008A014: addiu       $s3, $zero, 0x78
        ctx->r19 = ADD32(0, 0X78);
            goto L_8008A020;
    }
    // 0x8008A014: addiu       $s3, $zero, 0x78
    ctx->r19 = ADD32(0, 0X78);
    // 0x8008A018: b           L_8008A020
    // 0x8008A01C: addiu       $s3, $zero, 0x86
    ctx->r19 = ADD32(0, 0X86);
        goto L_8008A020;
    // 0x8008A01C: addiu       $s3, $zero, 0x86
    ctx->r19 = ADD32(0, 0X86);
L_8008A020:
    // 0x8008A020: jal         0x800C59F4
    // 0x8008A024: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_24;
    // 0x8008A024: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_24:
    // 0x8008A028: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008A02C: jal         0x800C54DC
    // 0x8008A030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_25;
    // 0x8008A030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x8008A034: addiu       $t6, $s3, 0x1C
    ctx->r14 = ADD32(ctx->r19, 0X1C);
    // 0x8008A038: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008A03C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008A040: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8008A044: addiu       $a2, $s3, -0x1C
    ctx->r6 = ADD32(ctx->r19, -0X1C);
    // 0x8008A048: jal         0x800C543C
    // 0x8008A04C: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_26;
    // 0x8008A04C: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    after_26:
    // 0x8008A050: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8008A054: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008A058: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008A05C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008A060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A064: jal         0x800C551C
    // 0x8008A068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_27;
    // 0x8008A068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_27:
    // 0x8008A06C: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8008A070: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008A074: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_8008A078:
    // 0x8008A078: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008A07C: bne         $fp, $zero, L_8008A090
    if (ctx->r30 != 0) {
        // 0x8008A080: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8008A090;
    }
    // 0x8008A080: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008A084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A088: b           L_8008A0A4
    // 0x8008A08C: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
        goto L_8008A0A4;
    // 0x8008A08C: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
L_8008A090:
    // 0x8008A090: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8008A094: nop

    // 0x8008A098: bne         $fp, $t8, L_8008A0A8
    if (ctx->r30 != ctx->r24) {
        // 0x8008A09C: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_8008A0A8;
    }
    // 0x8008A09C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008A0A0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_8008A0A4:
    // 0x8008A0A4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
L_8008A0A8:
    // 0x8008A0A8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8008A0AC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008A0B0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008A0B4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8008A0B8: jal         0x800C5560
    // 0x8008A0BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    set_current_text_colour(rdram, ctx);
        goto after_28;
    // 0x8008A0BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_28:
    // 0x8008A0C0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008A0C4: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x8008A0C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008A0CC: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8008A0D0: lw          $a3, 0x250($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X250);
    // 0x8008A0D4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8008A0D8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8008A0DC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008A0E0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8008A0E4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8008A0E8: jal         0x800C56C8
    // 0x8008A0EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_29;
    // 0x8008A0EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_29:
    // 0x8008A0F0: beq         $fp, $zero, L_8008A100
    if (ctx->r30 == 0) {
        // 0x8008A0F4: nop
    
            goto L_8008A100;
    }
    // 0x8008A0F4: nop

    // 0x8008A0F8: b           L_8008A104
    // 0x8008A0FC: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
        goto L_8008A104;
    // 0x8008A0FC: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
L_8008A100:
    // 0x8008A100: addiu       $s3, $s3, 0x14
    ctx->r19 = ADD32(ctx->r19, 0X14);
L_8008A104:
    // 0x8008A104: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8008A108: bne         $fp, $s4, L_8008A078
    if (ctx->r30 != ctx->r20) {
        // 0x8008A10C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8008A078;
    }
    // 0x8008A10C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8008A110: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008A114: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x8008A118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008A11C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A120: jal         0x800C60B8
    // 0x8008A124: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_30;
    // 0x8008A124: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_30:
L_8008A128:
    // 0x8008A128: jal         0x8009C850
    // 0x8008A12C: nop

    get_filtered_cheats(rdram, ctx);
        goto after_31;
    // 0x8008A12C: nop

    after_31:
    // 0x8008A130: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x8008A134: bgez        $t5, L_8008A148
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8008A138: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8008A148;
    }
    // 0x8008A138: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8008A13C: jal         0x8008B1FC
    // 0x8008A140: nop

    cheatmenu_checksum(rdram, ctx);
        goto after_32;
    // 0x8008A140: nop

    after_32:
    // 0x8008A144: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8008A148:
    // 0x8008A148: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008A14C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8008A150: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008A154: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8008A158: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008A15C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8008A160: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008A164: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A168: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8008A16C: jr          $ra
    // 0x8008A170: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8008A170: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void get_character_id_from_slot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C76C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C770: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C774: lb          $v0, 0x6990($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X6990);
    // 0x8009C778: jr          $ra
    // 0x8009C77C: nop

    return;
    // 0x8009C77C: nop

;}
RECOMP_FUNC void model_anim_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061C34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80061C38: jr          $ra
    // 0x80061C3C: sw          $a0, -0x2440($at)
    MEM_W(-0X2440, ctx->r1) = ctx->r4;
    return;
    // 0x80061C3C: sw          $a0, -0x2440($at)
    MEM_W(-0X2440, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void input_pressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A794: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A798: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A79C: lbu         $t6, 0x16D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X16D0);
    // 0x8006A7A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A7A4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8006A7A8: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8006A7AC: lhu         $v0, 0x16C0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X16C0);
    // 0x8006A7B0: jr          $ra
    // 0x8006A7B4: nop

    return;
    // 0x8006A7B4: nop

;}
RECOMP_FUNC void cam_get_cameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069FBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069FC0: lb          $t6, 0x1294($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X1294);
    // 0x80069FC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069FC8: beq         $t6, $zero, L_80069FDC
    if (ctx->r14 == 0) {
        // 0x80069FCC: addiu       $v0, $v0, 0x1040
        ctx->r2 = ADD32(ctx->r2, 0X1040);
            goto L_80069FDC;
    }
    // 0x80069FCC: addiu       $v0, $v0, 0x1040
    ctx->r2 = ADD32(ctx->r2, 0X1040);
    // 0x80069FD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069FD4: jr          $ra
    // 0x80069FD8: addiu       $v0, $v0, 0x1150
    ctx->r2 = ADD32(ctx->r2, 0X1150);
    return;
    // 0x80069FD8: addiu       $v0, $v0, 0x1150
    ctx->r2 = ADD32(ctx->r2, 0X1150);
L_80069FDC:
    // 0x80069FDC: jr          $ra
    // 0x80069FE0: nop

    return;
    // 0x80069FE0: nop

;}
