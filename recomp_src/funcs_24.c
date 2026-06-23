#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void set_time_trial_enabled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E4C0: jr          $ra
    // 0x8000E4C4: sb          $a0, -0x4B8C($at)
    MEM_B(-0X4B8C, ctx->r1) = ctx->r4;
    return;
    // 0x8000E4C4: sb          $a0, -0x4B8C($at)
    MEM_B(-0X4B8C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void hud_speedometre_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3DB8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A3DBC: lw          $t7, 0x729C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X729C);
    // 0x800A3DC0: addiu       $t6, $zero, 0x6490
    ctx->r14 = ADD32(0, 0X6490);
    // 0x800A3DC4: jr          $ra
    // 0x800A3DC8: sh          $t6, 0x4C4($t7)
    MEM_H(0X4C4, ctx->r15) = ctx->r14;
    return;
    // 0x800A3DC8: sh          $t6, 0x4C4($t7)
    MEM_H(0X4C4, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void __osPfsReleasePages(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D10B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D10B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D10B8: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x800D10BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D10C0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800D10C4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800D10C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D10CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D10D0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800D10D4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800D10D8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800D10DC: lhu         $at, 0x0($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X0);
    // 0x800D10E0: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x800D10E4: sh          $at, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r1;
    // 0x800D10E8: lhu         $t4, 0x24($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X24);
    // 0x800D10EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D10F0: beq         $t4, $at, L_800D1120
    if (ctx->r12 == ctx->r1) {
        // 0x800D10F4: nop
    
            goto L_800D1120;
    }
    // 0x800D10F4: nop

    // 0x800D10F8: lbu         $t5, 0x24($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X24);
    // 0x800D10FC: blez        $t5, L_800D1110
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800D1100: nop
    
            goto L_800D1110;
    }
    // 0x800D1100: nop

    // 0x800D1104: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D1108: b           L_800D1144
    // 0x800D110C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_800D1144;
    // 0x800D110C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_800D1110:
    // 0x800D1110: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D1114: lw          $t9, 0x60($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X60);
    // 0x800D1118: b           L_800D1144
    // 0x800D111C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
        goto L_800D1144;
    // 0x800D111C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800D1120:
    // 0x800D1120: lbu         $t2, 0x3B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3B);
    // 0x800D1124: blez        $t2, L_800D1138
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800D1128: nop
    
            goto L_800D1138;
    }
    // 0x800D1128: nop

    // 0x800D112C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D1130: b           L_800D1144
    // 0x800D1134: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
        goto L_800D1144;
    // 0x800D1134: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_800D1138:
    // 0x800D1138: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800D113C: lw          $t0, 0x60($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X60);
    // 0x800D1140: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_800D1144:
    // 0x800D1144: lbu         $t3, 0x25($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X25);
    // 0x800D1148: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800D114C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800D1150: beq         $at, $zero, L_800D1170
    if (ctx->r1 == 0) {
        // 0x800D1154: nop
    
            goto L_800D1170;
    }
    // 0x800D1154: nop

    // 0x800D1158: lhu         $t5, 0x24($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X24);
    // 0x800D115C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D1160: beq         $t5, $at, L_800D1170
    if (ctx->r13 == ctx->r1) {
        // 0x800D1164: nop
    
            goto L_800D1170;
    }
    // 0x800D1164: nop

    // 0x800D1168: b           L_800D12D8
    // 0x800D116C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800D12D8;
    // 0x800D116C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800D1170:
    // 0x800D1170: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x800D1174: lhu         $at, 0x0($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X0);
    // 0x800D1178: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800D117C: sh          $at, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r1;
    // 0x800D1180: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800D1184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D1188: bne         $t1, $at, L_800D11A8
    if (ctx->r9 != ctx->r1) {
        // 0x800D118C: nop
    
            goto L_800D11A8;
    }
    // 0x800D118C: nop

    // 0x800D1190: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x800D1194: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1198: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800D119C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800D11A0: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800D11A4: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_800D11A8:
    // 0x800D11A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800D11AC: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    // 0x800D11B0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800D11B4: jal         0x800D12E8
    // 0x800D11B8: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    __osBlockSum(rdram, ctx);
        goto after_0;
    // 0x800D11B8: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    after_0:
    // 0x800D11BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D11C0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800D11C4: beq         $t9, $zero, L_800D11D4
    if (ctx->r25 == 0) {
        // 0x800D11C8: nop
    
            goto L_800D11D4;
    }
    // 0x800D11C8: nop

    // 0x800D11CC: b           L_800D12D8
    // 0x800D11D0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800D12D8;
    // 0x800D11D0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800D11D4:
    // 0x800D11D4: lhu         $t8, 0x24($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X24);
    // 0x800D11D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D11DC: bne         $t8, $at, L_800D11EC
    if (ctx->r24 != ctx->r1) {
        // 0x800D11E0: nop
    
            goto L_800D11EC;
    }
    // 0x800D11E0: nop

    // 0x800D11E4: b           L_800D12D8
    // 0x800D11E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D12D8;
    // 0x800D11E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D11EC:
    // 0x800D11EC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800D11F0: lhu         $t7, 0x24($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X24);
    // 0x800D11F4: lw          $t1, 0x60($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X60);
    // 0x800D11F8: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D11FC: bne         $at, $zero, L_800D1294
    if (ctx->r1 != 0) {
        // 0x800D1200: nop
    
            goto L_800D1294;
    }
    // 0x800D1200: nop

L_800D1204:
    // 0x800D1204: lbu         $t6, 0x25($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X25);
    // 0x800D1208: lhu         $t3, 0x24($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X24);
    // 0x800D120C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1210: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800D1214: sh          $t3, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r11;
    // 0x800D1218: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x800D121C: lhu         $at, 0x0($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X0);
    // 0x800D1220: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x800D1224: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800D1228: sh          $at, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r1;
    // 0x800D122C: lbu         $t3, 0x21($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X21);
    // 0x800D1230: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1234: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800D1238: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x800D123C: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x800D1240: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    // 0x800D1244: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800D1248: lbu         $a1, 0x21($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X21);
    // 0x800D124C: jal         0x800D12E8
    // 0x800D1250: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osBlockSum(rdram, ctx);
        goto after_1;
    // 0x800D1250: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800D1254: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D1258: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800D125C: beq         $t5, $zero, L_800D126C
    if (ctx->r13 == 0) {
        // 0x800D1260: nop
    
            goto L_800D126C;
    }
    // 0x800D1260: nop

    // 0x800D1264: b           L_800D12D8
    // 0x800D1268: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800D12D8;
    // 0x800D1268: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_800D126C:
    // 0x800D126C: lbu         $t8, 0x24($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X24);
    // 0x800D1270: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x800D1274: bne         $t8, $t0, L_800D1294
    if (ctx->r24 != ctx->r8) {
        // 0x800D1278: nop
    
            goto L_800D1294;
    }
    // 0x800D1278: nop

    // 0x800D127C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800D1280: lhu         $t9, 0x24($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X24);
    // 0x800D1284: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x800D1288: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800D128C: beq         $at, $zero, L_800D1204
    if (ctx->r1 == 0) {
        // 0x800D1290: nop
    
            goto L_800D1204;
    }
    // 0x800D1290: nop

L_800D1294:
    // 0x800D1294: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800D1298: lhu         $t1, 0x24($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X24);
    // 0x800D129C: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x800D12A0: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D12A4: bne         $at, $zero, L_800D12C4
    if (ctx->r1 != 0) {
        // 0x800D12A8: nop
    
            goto L_800D12C4;
    }
    // 0x800D12A8: nop

    // 0x800D12AC: lbu         $t8, 0x25($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X25);
    // 0x800D12B0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800D12B4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800D12B8: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800D12BC: addu        $t2, $t5, $t0
    ctx->r10 = ADD32(ctx->r13, ctx->r8);
    // 0x800D12C0: sh          $t4, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r12;
L_800D12C4:
    // 0x800D12C4: addiu       $t3, $sp, 0x24
    ctx->r11 = ADD32(ctx->r29, 0X24);
    // 0x800D12C8: lhu         $at, 0x0($t3)
    ctx->r1 = MEM_HU(ctx->r11, 0X0);
    // 0x800D12CC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800D12D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D12D4: sh          $at, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r1;
L_800D12D8:
    // 0x800D12D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D12DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D12E0: jr          $ra
    // 0x800D12E4: nop

    return;
    // 0x800D12E4: nop

;}
RECOMP_FUNC void osScGetInterruptQ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800799CC: jr          $ra
    // 0x800799D0: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
    return;
    // 0x800799D0: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
;}
RECOMP_FUNC void music_channel_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001170: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80001174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001178: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x8000117C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001180: beq         $at, $zero, L_80001198
    if (ctx->r1 == 0) {
        // 0x80001184: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80001198;
    }
    // 0x80001184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001188: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000118C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001190: jal         0x80063D84
    // 0x80001194: nop

    alSeqChOn(rdram, ctx);
        goto after_0;
    // 0x80001194: nop

    after_0:
L_80001198:
    // 0x80001198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000119C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800011A0: jr          $ra
    // 0x800011A4: nop

    return;
    // 0x800011A4: nop

;}
RECOMP_FUNC void hud_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A057C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A0580: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0584: lw          $v0, 0x72B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72B8);
    // 0x800A0588: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A058C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A0590: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A0594: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A0598: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A059C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A05A0: blez        $v0, L_800A066C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A05A4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800A066C;
    }
    // 0x800A05A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A05A8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A05AC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A05B0: addiu       $s2, $s2, 0x72B4
    ctx->r18 = ADD32(ctx->r18, 0X72B4);
    // 0x800A05B4: addiu       $s4, $s4, 0x72B0
    ctx->r20 = ADD32(ctx->r20, 0X72B0);
    // 0x800A05B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A05BC: ori         $s3, $zero, 0xC000
    ctx->r19 = 0 | 0XC000;
L_800A05C0:
    // 0x800A05C0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800A05C4: nop

    // 0x800A05C8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800A05CC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800A05D0: nop

    // 0x800A05D4: beq         $a0, $zero, L_800A065C
    if (ctx->r4 == 0) {
        // 0x800A05D8: nop
    
            goto L_800A065C;
    }
    // 0x800A05D8: nop

    // 0x800A05DC: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800A05E0: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x800A05E4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800A05E8: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x800A05EC: nop

    // 0x800A05F0: andi        $t1, $v0, 0xC000
    ctx->r9 = ctx->r2 & 0XC000;
    // 0x800A05F4: bne         $s3, $t1, L_800A060C
    if (ctx->r19 != ctx->r9) {
        // 0x800A05F8: andi        $t2, $v0, 0x8000
        ctx->r10 = ctx->r2 & 0X8000;
            goto L_800A060C;
    }
    // 0x800A05F8: andi        $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 & 0X8000;
    // 0x800A05FC: jal         0x8007B70C
    // 0x800A0600: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800A0600: nop

    after_0:
    // 0x800A0604: b           L_800A0648
    // 0x800A0608: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
        goto L_800A0648;
    // 0x800A0608: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A060C:
    // 0x800A060C: beq         $t2, $zero, L_800A0624
    if (ctx->r10 == 0) {
        // 0x800A0610: andi        $t3, $v0, 0x4000
        ctx->r11 = ctx->r2 & 0X4000;
            goto L_800A0624;
    }
    // 0x800A0610: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x800A0614: jal         0x8007D100
    // 0x800A0618: nop

    sprite_free(rdram, ctx);
        goto after_1;
    // 0x800A0618: nop

    after_1:
    // 0x800A061C: b           L_800A0648
    // 0x800A0620: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
        goto L_800A0648;
    // 0x800A0620: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A0624:
    // 0x800A0624: beq         $t3, $zero, L_800A063C
    if (ctx->r11 == 0) {
        // 0x800A0628: nop
    
            goto L_800A063C;
    }
    // 0x800A0628: nop

    // 0x800A062C: jal         0x8000FFB8
    // 0x800A0630: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x800A0630: nop

    after_2:
    // 0x800A0634: b           L_800A0648
    // 0x800A0638: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
        goto L_800A0648;
    // 0x800A0638: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A063C:
    // 0x800A063C: jal         0x80060180
    // 0x800A0640: nop

    free_3d_model(rdram, ctx);
        goto after_3;
    // 0x800A0640: nop

    after_3:
    // 0x800A0644: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_800A0648:
    // 0x800A0648: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A064C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x800A0650: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800A0654: lw          $v0, 0x72B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72B8);
    // 0x800A0658: nop

L_800A065C:
    // 0x800A065C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A0660: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800A0664: bne         $at, $zero, L_800A05C0
    if (ctx->r1 != 0) {
        // 0x800A0668: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800A05C0;
    }
    // 0x800A0668: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800A066C:
    // 0x800A066C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0670: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A0674: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A0678: lw          $a0, 0x72A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72A0);
    // 0x800A067C: addiu       $s4, $s4, 0x72B0
    ctx->r20 = ADD32(ctx->r20, 0X72B0);
    // 0x800A0680: jal         0x80071380
    // 0x800A0684: addiu       $s2, $s2, 0x72B4
    ctx->r18 = ADD32(ctx->r18, 0X72B4);
    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800A0684: addiu       $s2, $s2, 0x72B4
    ctx->r18 = ADD32(ctx->r18, 0X72B4);
    after_4:
    // 0x800A0688: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800A068C: jal         0x80071380
    // 0x800A0690: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800A0690: nop

    after_5:
    // 0x800A0694: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0698: sw          $zero, 0x72B8($at)
    MEM_W(0X72B8, ctx->r1) = 0;
    // 0x800A069C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800A06A0: jal         0x80071380
    // 0x800A06A4: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800A06A4: nop

    after_6:
    // 0x800A06A8: jal         0x8001004C
    // 0x800A06AC: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_7;
    // 0x800A06AC: nop

    after_7:
    // 0x800A06B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A06B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A06B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A06BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A06C0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A06C4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A06C8: jr          $ra
    // 0x800A06CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A06CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D58AC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800D58B0: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x800D58B4: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x800D58B8: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x800D58BC: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800D58C0: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800D58C4:
    // 0x800D58C4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800D58C8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800D58CC: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800D58D0: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x800D58D4: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x800D58D8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x800D58DC: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x800D58E0: lhu         $t3, 0x6($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6);
    // 0x800D58E4: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x800D58E8: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x800D58EC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800D58F0: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x800D58F4: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800D58F8: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800D58FC: sltiu       $at, $t7, 0x1C
    ctx->r1 = ctx->r15 < 0X1C ? 1 : 0;
    // 0x800D5900: bne         $at, $zero, L_800D58C4
    if (ctx->r1 != 0) {
        // 0x800D5904: sw          $t7, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r15;
            goto L_800D58C4;
    }
    // 0x800D5904: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800D5908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D590C: jr          $ra
    // 0x800D5910: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800D5910: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void get_race_countdown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001139C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800113A0: lw          $v0, -0x4CD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4CD0);
    // 0x800113A4: jr          $ra
    // 0x800113A8: nop

    return;
    // 0x800113A8: nop

;}
RECOMP_FUNC void lensflare_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACDB0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800ACDB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACDB8: jr          $ra
    // 0x800ACDBC: sw          $t6, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = ctx->r14;
    return;
    // 0x800ACDBC: sw          $t6, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void obj_wave_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEB74: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800BEB78: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BEB7C: lw          $t6, 0x35D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X35D0);
    // 0x800BEB80: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800BEB84: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x800BEB88: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800BEB8C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BEB90: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BEB94: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BEB98: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800BEB9C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BEBA0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800BEBA4: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x800BEBA8: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x800BEBAC: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800BEBB0: beq         $t6, $zero, L_800BF3AC
    if (ctx->r14 == 0) {
        // 0x800BEBB4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800BF3AC;
    }
    // 0x800BEBB4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BEBB8: bltz        $a0, L_800BF3AC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800BEBBC: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800BF3AC;
    }
    // 0x800BEBBC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BEBC0: lw          $t7, -0x5960($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5960);
    // 0x800BEBC4: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800BEBC8: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BEBCC: beq         $at, $zero, L_800BF3AC
    if (ctx->r1 == 0) {
        // 0x800BEBD0: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800BF3AC;
    }
    // 0x800BEBD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BEBD4: lw          $a0, -0x5A58($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5A58);
    // 0x800BEBD8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800BEBDC: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800BEBE0: addiu       $a0, $t8, 0xE
    ctx->r4 = ADD32(ctx->r24, 0XE);
    // 0x800BEBE4: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x800BEBE8: jal         0x80070EDC
    // 0x800BEBEC: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800BEBEC: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
    after_0:
    // 0x800BEBF0: lw          $ra, 0xE8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE8);
    // 0x800BEBF4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BEBF8: addiu       $t5, $t5, 0x3668
    ctx->r13 = ADD32(ctx->r13, 0X3668);
    // 0x800BEBFC: sll         $t1, $ra, 3
    ctx->r9 = S32(ctx->r31 << 3);
    // 0x800BEC00: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800BEC04: subu        $t1, $t1, $ra
    ctx->r9 = SUB32(ctx->r9, ctx->r31);
    // 0x800BEC08: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800BEC0C: addu        $t6, $t9, $t1
    ctx->r14 = ADD32(ctx->r25, ctx->r9);
    // 0x800BEC10: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x800BEC14: lh          $t0, 0xA6($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA6);
    // 0x800BEC18: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BEC1C: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800BEC20: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
    // 0x800BEC24: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800BEC28: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BEC2C: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800BEC30: lw          $t9, -0x5A58($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5A58);
    // 0x800BEC34: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BEC38: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x800BEC3C: lw          $t6, 0x370C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X370C);
    // 0x800BEC40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BEC44: multu       $ra, $t6
    result = U64(U32(ctx->r31)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEC48: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800BEC4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BEC50: lwc1        $f20, -0x5984($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800BEC54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BEC58: lwc1        $f22, -0x5988($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BEC5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BEC60: lwc1        $f4, -0x5A34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BEC64: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800BEC68: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BEC6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BEC70: lw          $t8, -0x5A50($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5A50);
    // 0x800BEC74: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x800BEC78: mflo        $t7
    ctx->r15 = lo;
    // 0x800BEC7C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800BEC80: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x800BEC84: beq         $t8, $zero, L_800BECB4
    if (ctx->r24 == 0) {
        // 0x800BEC88: div.s       $f2, $f6, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_800BECB4;
    }
    // 0x800BEC88: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BEC8C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BEC90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BEC94: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800BEC98: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800BEC9C: lw          $t4, -0x5A78($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5A78);
    // 0x800BECA0: nop

    // 0x800BECA4: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x800BECA8: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800BECAC: b           L_800BECC4
    // 0x800BECB0: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
        goto L_800BECC4;
    // 0x800BECB0: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
L_800BECB4:
    // 0x800BECB4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800BECB8: lw          $t4, -0x5A78($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5A78);
    // 0x800BECBC: nop

    // 0x800BECC0: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_800BECC4:
    // 0x800BECC4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800BECC8: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800BECCC: addu        $a3, $t6, $t1
    ctx->r7 = ADD32(ctx->r14, ctx->r9);
    // 0x800BECD0: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x800BECD4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800BECD8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800BECDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BECE0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BECE4: sub.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800BECE8: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x800BECEC: nop

    // 0x800BECF0: bc1f        L_800BED00
    if (!c1cs) {
        // 0x800BECF4: nop
    
            goto L_800BED00;
    }
    // 0x800BECF4: nop

    // 0x800BECF8: b           L_800BED30
    // 0x800BECFC: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
        goto L_800BED30;
    // 0x800BECFC: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
L_800BED00:
    // 0x800BED00: lwc1        $f0, -0x59A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800BED04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BED08: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x800BED0C: swc1        $f16, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f16.u32l;
    // 0x800BED10: bc1f        L_800BED30
    if (!c1cs) {
        // 0x800BED14: nop
    
            goto L_800BED30;
    }
    // 0x800BED14: nop

    // 0x800BED18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BED1C: nop

    // 0x800BED20: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800BED24: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x800BED28: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800BED2C: nop

L_800BED30:
    // 0x800BED30: lh          $t8, 0x8($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X8);
    // 0x800BED34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BED38: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BED3C: div.s       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f22.fl);
    // 0x800BED40: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BED44: sub.s       $f24, $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x800BED48: c.lt.s      $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f24.fl < ctx->f14.fl;
    // 0x800BED4C: nop

    // 0x800BED50: bc1f        L_800BED60
    if (!c1cs) {
        // 0x800BED54: nop
    
            goto L_800BED60;
    }
    // 0x800BED54: nop

    // 0x800BED58: b           L_800BED84
    // 0x800BED5C: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
        goto L_800BED84;
    // 0x800BED5C: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
L_800BED60:
    // 0x800BED60: lwc1        $f0, -0x599C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800BED64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BED68: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x800BED6C: nop

    // 0x800BED70: bc1f        L_800BED84
    if (!c1cs) {
        // 0x800BED74: nop
    
            goto L_800BED84;
    }
    // 0x800BED74: nop

    // 0x800BED78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BED7C: nop

    // 0x800BED80: sub.s       $f24, $f0, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f6.fl;
L_800BED84:
    // 0x800BED84: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BED88: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BED8C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BED90: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BED94: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BED98: nop

    // 0x800BED9C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BEDA0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BEDA4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800BEDA8: div.s       $f4, $f24, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800BEDAC: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800BEDB0: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x800BEDB4: sh          $ra, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r31;
    // 0x800BEDB8: sh          $a1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r5;
    // 0x800BEDBC: addiu       $ra, $sp, 0x50
    ctx->r31 = ADD32(ctx->r29, 0X50);
    // 0x800BEDC0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BEDC4: nop

    // 0x800BEDC8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BEDCC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BEDD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BEDD4: nop

    // 0x800BEDD8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BEDDC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800BEDE0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BEDE4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800BEDE8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BEDEC: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
    // 0x800BEDF0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800BEDF4: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800BEDF8: addu        $a3, $t7, $t1
    ctx->r7 = ADD32(ctx->r15, ctx->r9);
    // 0x800BEDFC: lh          $t8, 0x12($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X12);
    // 0x800BEE00: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x800BEE04: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BEE08: lw          $v1, -0x5A74($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5A74);
    // 0x800BEE0C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800BEE10: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800BEE14: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEE18: addiu       $t5, $sp, 0x80
    ctx->r13 = ADD32(ctx->r29, 0X80);
    // 0x800BEE1C: sub.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800BEE20: bne         $at, $zero, L_800BEE38
    if (ctx->r1 != 0) {
        // 0x800BEE24: sub.s       $f24, $f24, $f10
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f10.fl;
            goto L_800BEE38;
    }
    // 0x800BEE24: sub.s       $f24, $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f10.fl;
L_800BEE28:
    // 0x800BEE28: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800BEE2C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEE30: beq         $at, $zero, L_800BEE28
    if (ctx->r1 == 0) {
        // 0x800BEE34: nop
    
            goto L_800BEE28;
    }
    // 0x800BEE34: nop

L_800BEE38:
    // 0x800BEE38: lh          $t6, 0x10($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X10);
    // 0x800BEE3C: addiu       $a2, $a0, 0x1
    ctx->r6 = ADD32(ctx->r4, 0X1);
    // 0x800BEE40: addu        $v0, $t6, $t3
    ctx->r2 = ADD32(ctx->r14, ctx->r11);
    // 0x800BEE44: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEE48: bne         $at, $zero, L_800BEE60
    if (ctx->r1 != 0) {
        // 0x800BEE4C: nop
    
            goto L_800BEE60;
    }
    // 0x800BEE4C: nop

L_800BEE50:
    // 0x800BEE50: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800BEE54: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEE58: beq         $at, $zero, L_800BEE50
    if (ctx->r1 == 0) {
        // 0x800BEE5C: nop
    
            goto L_800BEE50;
    }
    // 0x800BEE5C: nop

L_800BEE60:
    // 0x800BEE60: c.eq.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl == ctx->f20.fl;
    // 0x800BEE64: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800BEE68: bc1t        L_800BEE94
    if (c1cs) {
        // 0x800BEE6C: slt         $at, $a2, $v1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BEE94;
    }
    // 0x800BEE6C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEE70: sub.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x800BEE74: nop

    // 0x800BEE78: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800BEE7C: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800BEE80: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800BEE84: nop

    // 0x800BEE88: bc1f        L_800BEE94
    if (!c1cs) {
        // 0x800BEE8C: nop
    
            goto L_800BEE94;
    }
    // 0x800BEE8C: nop

    // 0x800BEE90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800BEE94:
    // 0x800BEE94: beq         $t1, $zero, L_800BEF2C
    if (ctx->r9 == 0) {
        // 0x800BEE98: addiu       $a1, $v0, 0x1
        ctx->r5 = ADD32(ctx->r2, 0X1);
            goto L_800BEF2C;
    }
    // 0x800BEE98: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x800BEE9C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEEA0: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x800BEEA4: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEEA8: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x800BEEAC: mflo        $a2
    ctx->r6 = lo;
    // 0x800BEEB0: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x800BEEB4: bne         $at, $zero, L_800BEEC4
    if (ctx->r1 != 0) {
        // 0x800BEEB8: sw          $a3, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r7;
            goto L_800BEEC4;
    }
    // 0x800BEEB8: sw          $a3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r7;
    // 0x800BEEBC: b           L_800BEED4
    // 0x800BEEC0: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
        goto L_800BEED4;
    // 0x800BEEC0: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
L_800BEEC4:
    // 0x800BEEC4: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEEC8: mflo        $t7
    ctx->r15 = lo;
    // 0x800BEECC: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800BEED0: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
L_800BEED4:
    // 0x800BEED4: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEED8: bne         $at, $zero, L_800BEEE8
    if (ctx->r1 != 0) {
        // 0x800BEEDC: addiu       $v0, $a3, 0x1
        ctx->r2 = ADD32(ctx->r7, 0X1);
            goto L_800BEEE8;
    }
    // 0x800BEEDC: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x800BEEE0: b           L_800BEEEC
    // 0x800BEEE4: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
        goto L_800BEEEC;
    // 0x800BEEE4: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
L_800BEEE8:
    // 0x800BEEE8: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
L_800BEEEC:
    // 0x800BEEEC: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEEF0: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x800BEEF4: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800BEEF8: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800BEEFC: swc1        $f14, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f14.u32l;
    // 0x800BEF00: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800BEF04: mflo        $t8
    ctx->r24 = lo;
    // 0x800BEF08: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x800BEF0C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800BEF10: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEF14: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x800BEF18: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x800BEF1C: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEF20: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEF24: b           L_800BEFF0
    // 0x800BEF28: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
        goto L_800BEFF0;
    // 0x800BEF28: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
L_800BEF2C:
    // 0x800BEF2C: bne         $at, $zero, L_800BEF48
    if (ctx->r1 != 0) {
        // 0x800BEF30: nop
    
            goto L_800BEF48;
    }
    // 0x800BEF30: nop

    // 0x800BEF34: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEF38: mflo        $t9
    ctx->r25 = lo;
    // 0x800BEF3C: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x800BEF40: b           L_800BEF60
    // 0x800BEF44: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_800BEF60;
    // 0x800BEF44: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_800BEF48:
    // 0x800BEF48: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEF4C: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEF50: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800BEF54: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BEF58: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
    // 0x800BEF5C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_800BEF60:
    // 0x800BEF60: bne         $at, $zero, L_800BEF70
    if (ctx->r1 != 0) {
        // 0x800BEF64: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800BEF70;
    }
    // 0x800BEF64: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800BEF68: b           L_800BEF80
    // 0x800BEF6C: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
        goto L_800BEF80;
    // 0x800BEF6C: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
L_800BEF70:
    // 0x800BEF70: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEF74: mflo        $t9
    ctx->r25 = lo;
    // 0x800BEF78: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x800BEF7C: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
L_800BEF80:
    // 0x800BEF80: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEF84: bne         $at, $zero, L_800BEF94
    if (ctx->r1 != 0) {
        // 0x800BEF88: nop
    
            goto L_800BEF94;
    }
    // 0x800BEF88: nop

    // 0x800BEF8C: b           L_800BEF94
    // 0x800BEF90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BEF94;
    // 0x800BEF90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BEF94:
    // 0x800BEF94: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEF98: beq         $at, $zero, L_800BEFB0
    if (ctx->r1 == 0) {
        // 0x800BEF9C: sw          $v0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r2;
            goto L_800BEFB0;
    }
    // 0x800BEF9C: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x800BEFA0: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEFA4: mflo        $t7
    ctx->r15 = lo;
    // 0x800BEFA8: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800BEFAC: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
L_800BEFB0:
    // 0x800BEFB0: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEFB4: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800BEFB8: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x800BEFBC: swc1        $f22, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f22.u32l;
    // 0x800BEFC0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800BEFC4: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x800BEFC8: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEFCC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEFD0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BEFD4: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEFD8: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x800BEFDC: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEFE0: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEFE4: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800BEFE8: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x800BEFEC: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
L_800BEFF0:
    // 0x800BEFF0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BEFF4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BEFF8: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    // 0x800BEFFC: lw          $t4, 0x3708($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3708);
    // 0x800BF000: lw          $t3, 0x35D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X35D4);
    // 0x800BF004: addiu       $t1, $sp, 0x68
    ctx->r9 = ADD32(ctx->r29, 0X68);
    // 0x800BF008: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BF00C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_800BF010:
    // 0x800BF010: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800BF014: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800BF018: sll         $t9, $a3, 3
    ctx->r25 = S32(ctx->r7 << 3);
    // 0x800BF01C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BF020: addu        $a0, $t3, $t8
    ctx->r4 = ADD32(ctx->r11, ctx->r24);
    // 0x800BF024: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x800BF028: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x800BF02C: addu        $a1, $ra, $v0
    ctx->r5 = ADD32(ctx->r31, ctx->r2);
    // 0x800BF030: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BF034: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800BF038: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    // 0x800BF03C: addu        $t7, $sp, $v0
    ctx->r15 = ADD32(ctx->r29, ctx->r2);
    // 0x800BF040: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800BF044: lw          $t7, 0x5C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5C);
    // 0x800BF048: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BF04C: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x800BF050: lbu         $a2, 0x0($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X0);
    // 0x800BF054: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x800BF058: slti        $at, $a2, 0x7F
    ctx->r1 = SIGNED(ctx->r6) < 0X7F ? 1 : 0;
    // 0x800BF05C: beq         $at, $zero, L_800BF088
    if (ctx->r1 == 0) {
        // 0x800BF060: sra         $a3, $t9, 16
        ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
            goto L_800BF088;
    }
    // 0x800BF060: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800BF064: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800BF068: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF06C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BF070: lwc1        $f10, -0x5A34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5A34);
    // 0x800BF074: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BF078: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BF07C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800BF080: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800BF084: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_800BF088:
    // 0x800BF088: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800BF08C: bne         $at, $zero, L_800BF010
    if (ctx->r1 != 0) {
        // 0x800BF090: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_800BF010;
    }
    // 0x800BF090: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800BF094: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BF098: lw          $t7, -0x5A50($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5A50);
    // 0x800BF09C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800BF0A0: beq         $t7, $zero, L_800BF0F0
    if (ctx->r15 == 0) {
        // 0x800BF0A4: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800BF0F0;
    }
    // 0x800BF0A4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BF0A8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800BF0AC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800BF0B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BF0B4: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800BF0B8: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800BF0BC: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800BF0C0: nop

    // 0x800BF0C4: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800BF0C8: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800BF0CC: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800BF0D0: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800BF0D4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800BF0D8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800BF0DC: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800BF0E0: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800BF0E4: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800BF0E8: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800BF0EC: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
L_800BF0F0:
    // 0x800BF0F0: lw          $t8, -0x5A58($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5A58);
    // 0x800BF0F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BF0F8: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800BF0FC: blez        $t9, L_800BF3B0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BF100: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800BF3B0;
    }
    // 0x800BF100: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF104: mul.s       $f18, $f20, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800BF108: swc1        $f16, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f16.u32l;
    // 0x800BF10C: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800BF110: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800BF114: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
L_800BF118:
    // 0x800BF118: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800BF11C: lw          $v0, 0x35D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X35D0);
    // 0x800BF120: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800BF124: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BF128: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800BF12C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BF130: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BF134: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BF138: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BF13C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800BF140: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800BF144: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BF148: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BF14C: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x800BF150: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800BF154: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BF158: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BF15C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800BF160: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BF164: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BF168: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800BF16C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800BF170: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BF174: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800BF178: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BF17C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800BF180: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BF184: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BF188: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BF18C: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BF190: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BF194: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800BF198: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BF19C: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800BF1A0: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BF1A4: beq         $t8, $zero, L_800BF1C4
    if (ctx->r24 == 0) {
        // 0x800BF1A8: nop
    
            goto L_800BF1C4;
    }
    // 0x800BF1A8: nop

    // 0x800BF1AC: sub.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800BF1B0: mul.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BF1B4: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800BF1B8: mul.s       $f14, $f4, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800BF1BC: b           L_800BF1D8
    // 0x800BF1C0: nop

        goto L_800BF1D8;
    // 0x800BF1C0: nop

L_800BF1C4:
    // 0x800BF1C4: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800BF1C8: mul.s       $f2, $f8, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800BF1CC: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800BF1D0: mul.s       $f14, $f10, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800BF1D4: nop

L_800BF1D8:
    // 0x800BF1D8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800BF1DC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800BF1E0: sh          $a3, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r7;
    // 0x800BF1E4: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
    // 0x800BF1E8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800BF1EC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BF1F0: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x800BF1F4: swc1        $f2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f2.u32l;
    // 0x800BF1F8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BF1FC: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
    // 0x800BF200: swc1        $f16, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f16.u32l;
    // 0x800BF204: jal         0x800CA030
    // 0x800BF208: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800BF208: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x800BF20C: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BF210: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BF214: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800BF218: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800BF21C: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800BF220: lwc1        $f16, 0xE0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800BF224: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800BF228: lh          $t0, 0xA6($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA6);
    // 0x800BF22C: lh          $a3, 0xA2($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XA2);
    // 0x800BF230: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800BF234: addiu       $t1, $sp, 0x68
    ctx->r9 = ADD32(ctx->r29, 0X68);
    // 0x800BF238: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF23C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BF240: negu        $t6, $t0
    ctx->r14 = SUB32(0, ctx->r8);
    // 0x800BF244: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800BF248: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800BF24C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800BF250: div.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BF254: mul.s       $f8, $f14, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x800BF258: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BF25C: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BF260: nop

    // 0x800BF264: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800BF268: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BF26C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BF270: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800BF274: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800BF278: nop

    // 0x800BF27C: div.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800BF280: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BF284: nop

    // 0x800BF288: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BF28C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF290: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF294: nop

    // 0x800BF298: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BF29C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800BF2A0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BF2A4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800BF2A8: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BF2AC: beq         $at, $zero, L_800BF2C0
    if (ctx->r1 == 0) {
        // 0x800BF2B0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800BF2C0;
    }
    // 0x800BF2B0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800BF2B4: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BF2B8: beq         $at, $zero, L_800BF330
    if (ctx->r1 == 0) {
        // 0x800BF2BC: nop
    
            goto L_800BF330;
    }
    // 0x800BF2BC: nop

L_800BF2C0:
    // 0x800BF2C0: addu        $t0, $t0, $t0
    ctx->r8 = ADD32(ctx->r8, ctx->r8);
    // 0x800BF2C4: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800BF2C8: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800BF2CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BF2D0: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x800BF2D4: slt         $at, $a2, $t8
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BF2D8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800BF2DC: beq         $at, $zero, L_800BF2C0
    if (ctx->r1 == 0) {
        // 0x800BF2E0: sra         $v1, $t9, 16
        ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
            goto L_800BF2C0;
    }
    // 0x800BF2E0: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800BF2E4: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x800BF2E8: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BF2EC: bne         $at, $zero, L_800BF2C0
    if (ctx->r1 != 0) {
        // 0x800BF2F0: nop
    
            goto L_800BF2C0;
    }
    // 0x800BF2F0: nop

    // 0x800BF2F4: blez        $a3, L_800BF320
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800BF2F8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800BF320;
    }
    // 0x800BF2F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800BF2FC:
    // 0x800BF2FC: addu        $v0, $t2, $a1
    ctx->r2 = ADD32(ctx->r10, ctx->r5);
    // 0x800BF300: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BF304: lb          $t8, 0xE($v0)
    ctx->r24 = MEM_B(ctx->r2, 0XE);
    // 0x800BF308: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800BF30C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BF310: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800BF314: srav        $t9, $t8, $v1
    ctx->r25 = S32(SIGNED(ctx->r24) >> (ctx->r3 & 31));
    // 0x800BF318: bne         $at, $zero, L_800BF2FC
    if (ctx->r1 != 0) {
        // 0x800BF31C: sb          $t9, 0xE($v0)
        MEM_B(0XE, ctx->r2) = ctx->r25;
            goto L_800BF2FC;
    }
    // 0x800BF31C: sb          $t9, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r25;
L_800BF320:
    // 0x800BF320: lbu         $t8, 0x2($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X2);
    // 0x800BF324: nop

    // 0x800BF328: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800BF32C: sb          $t9, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r25;
L_800BF330:
    // 0x800BF330: lbu         $t6, 0x2($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X2);
    // 0x800BF334: addu        $t8, $t2, $a3
    ctx->r24 = ADD32(ctx->r10, ctx->r7);
    // 0x800BF338: srav        $t7, $a2, $t6
    ctx->r15 = S32(SIGNED(ctx->r6) >> (ctx->r14 & 31));
    // 0x800BF33C: sb          $t7, 0xE($t8)
    MEM_B(0XE, ctx->r24) = ctx->r15;
    // 0x800BF340: lw          $a0, -0x5A58($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5A58);
    // 0x800BF344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BF348: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
L_800BF34C:
    // 0x800BF34C: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x800BF350: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BF354: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BF358: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x800BF35C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BF360: bne         $at, $zero, L_800BF37C
    if (ctx->r1 != 0) {
        // 0x800BF364: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800BF37C;
    }
    // 0x800BF364: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800BF368:
    // 0x800BF368: subu        $t8, $v0, $a0
    ctx->r24 = SUB32(ctx->r2, ctx->r4);
    // 0x800BF36C: slt         $at, $t8, $a0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BF370: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800BF374: beq         $at, $zero, L_800BF368
    if (ctx->r1 == 0) {
        // 0x800BF378: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800BF368;
    }
    // 0x800BF378: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800BF37C:
    // 0x800BF37C: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x800BF380: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800BF384: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x800BF388: bne         $at, $zero, L_800BF34C
    if (ctx->r1 != 0) {
        // 0x800BF38C: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_800BF34C;
    }
    // 0x800BF38C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800BF390: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BF394: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x800BF398: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800BF39C: sra         $t9, $a0, 1
    ctx->r25 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800BF3A0: slt         $at, $a3, $t9
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BF3A4: bne         $at, $zero, L_800BF118
    if (ctx->r1 != 0) {
        // 0x800BF3A8: lw          $t6, 0x68($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X68);
            goto L_800BF118;
    }
    // 0x800BF3A8: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
L_800BF3AC:
    // 0x800BF3AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800BF3B0:
    // 0x800BF3B0: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800BF3B4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BF3B8: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BF3BC: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BF3C0: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BF3C4: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BF3C8: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x800BF3CC: jr          $ra
    // 0x800BF3D0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x800BF3D0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
;}
RECOMP_FUNC void __lookupVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A84C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000A850: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000A854: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8000A858: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8000A85C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8000A860: beq         $v1, $zero, L_8000A8C4
    if (ctx->r3 == 0) {
        // 0x8000A864: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_8000A8C4;
    }
    // 0x8000A864: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000A868: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000A86C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8000A870: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_8000A874:
    // 0x8000A874: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
    // 0x8000A878: nop

    // 0x8000A87C: bne         $v0, $t8, L_8000A8B4
    if (ctx->r2 != ctx->r24) {
        // 0x8000A880: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A880: nop

    // 0x8000A884: lbu         $t9, 0x31($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X31);
    // 0x8000A888: nop

    // 0x8000A88C: bne         $a2, $t9, L_8000A8B4
    if (ctx->r6 != ctx->r25) {
        // 0x8000A890: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A890: nop

    // 0x8000A894: lbu         $a0, 0x35($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X35);
    // 0x8000A898: nop

    // 0x8000A89C: beq         $a1, $a0, L_8000A8B4
    if (ctx->r5 == ctx->r4) {
        // 0x8000A8A0: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A8A0: nop

    // 0x8000A8A4: beq         $a3, $a0, L_8000A8B4
    if (ctx->r7 == ctx->r4) {
        // 0x8000A8A8: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A8A8: nop

    // 0x8000A8AC: jr          $ra
    // 0x8000A8B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000A8B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000A8B4:
    // 0x8000A8B4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000A8B8: nop

    // 0x8000A8BC: bne         $v1, $zero, L_8000A874
    if (ctx->r3 != 0) {
        // 0x8000A8C0: nop
    
            goto L_8000A874;
    }
    // 0x8000A8C0: nop

L_8000A8C4:
    // 0x8000A8C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000A8C8: jr          $ra
    // 0x8000A8CC: nop

    return;
    // 0x8000A8CC: nop

;}
RECOMP_FUNC void audspat_distance_to_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800092A8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800092AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800092B0: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800092B4: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800092B8: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800092BC: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800092C0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800092C4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800092C8: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x800092CC: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800092D0: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800092D4: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800092D8: lwc1        $f20, 0x0($a3)
    ctx->f20.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800092DC: lwc1        $f22, 0x4($a3)
    ctx->f22.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800092E0: lwc1        $f24, 0x8($a3)
    ctx->f24.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800092E4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800092E8: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800092EC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800092F0: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800092F4: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800092F8: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800092FC: sub.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x80009300: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80009304: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80009308: sub.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x8000930C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80009310: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80009314: sub.s       $f6, $f10, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f24.fl;
    // 0x80009318: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8000931C: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80009320: c.eq.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d == ctx->f10.d;
    // 0x80009324: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80009328: mov.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = ctx->f8.fl;
    // 0x8000932C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80009330: bc1f        L_8000936C
    if (!c1cs) {
        // 0x80009334: mov.s       $f18, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
            goto L_8000936C;
    }
    // 0x80009334: mov.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
    // 0x80009338: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8000933C: c.eq.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d == ctx->f4.d;
    // 0x80009340: nop

    // 0x80009344: bc1f        L_8000936C
    if (!c1cs) {
        // 0x80009348: nop
    
            goto L_8000936C;
    }
    // 0x80009348: nop

    // 0x8000934C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80009350: c.eq.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d == ctx->f10.d;
    // 0x80009354: nop

    // 0x80009358: bc1f        L_8000936C
    if (!c1cs) {
        // 0x8000935C: nop
    
            goto L_8000936C;
    }
    // 0x8000935C: nop

    // 0x80009360: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80009364: b           L_800093BC
    // 0x80009368: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_800093BC;
    // 0x80009368: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8000936C:
    // 0x8000936C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80009370: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80009374: sub.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x80009378: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8000937C: sub.s       $f8, $f10, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x80009380: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80009384: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80009388: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8000938C: sub.s       $f6, $f8, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80009390: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80009394: nop

    // 0x80009398: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000939C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800093A0: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800093A4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800093A8: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800093AC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800093B0: nop

    // 0x800093B4: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800093B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_800093BC:
    // 0x800093BC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800093C0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800093C4: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800093C8: bc1f        L_8000941C
    if (!c1cs) {
        // 0x800093CC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000941C;
    }
    // 0x800093CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800093D0: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x800093D4: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
    // 0x800093D8: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800093DC: nop

    // 0x800093E0: swc1        $f24, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f24.u32l;
    // 0x800093E4: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800093E8: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800093EC: sub.s       $f0, $f20, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x800093F0: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800093F4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800093F8: sub.s       $f2, $f22, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x800093FC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80009400: sub.s       $f14, $f24, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x80009404: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80009408: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000940C: jal         0x800CA030
    // 0x80009410: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80009410: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80009414: b           L_8000951C
    // 0x80009418: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8000951C;
    // 0x80009418: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8000941C:
    // 0x8000941C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80009420: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x80009424: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80009428: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000942C: bc1f        L_800094A0
    if (!c1cs) {
        // 0x80009430: nop
    
            goto L_800094A0;
    }
    // 0x80009430: nop

    // 0x80009434: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80009438: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x8000943C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80009440: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80009444: nop

    // 0x80009448: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8000944C: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80009450: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80009454: nop

    // 0x80009458: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x8000945C: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80009460: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80009464: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80009468: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000946C: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80009470: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80009474: sub.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80009478: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000947C: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80009480: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80009484: nop

    // 0x80009488: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000948C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80009490: jal         0x800CA030
    // 0x80009494: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80009494: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_1:
    // 0x80009498: b           L_8000951C
    // 0x8000949C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8000951C;
    // 0x8000949C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_800094A0:
    // 0x800094A0: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800094A4: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800094A8: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800094AC: add.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800094B0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800094B4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800094B8: nop

    // 0x800094BC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800094C0: add.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x800094C4: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800094C8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800094CC: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x800094D0: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800094D4: add.s       $f16, $f6, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x800094D8: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x800094DC: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800094E0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800094E4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800094E8: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800094EC: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800094F0: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800094F4: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800094F8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800094FC: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80009500: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80009504: nop

    // 0x80009508: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8000950C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80009510: jal         0x800CA030
    // 0x80009514: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80009514: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_2:
    // 0x80009518: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8000951C:
    // 0x8000951C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80009520: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80009524: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80009528: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000952C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80009530: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80009534: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80009538: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8000953C: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80009540: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009544: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80009548: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000954C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80009550: jr          $ra
    // 0x80009554: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80009554: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void calc_env_mapping_for_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DD88: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x8001DD8C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001DD90: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001DD94: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001DD98: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001DD9C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001DDA0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001DDA4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001DDA8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001DDAC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001DDB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DDB4: sw          $a1, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r5;
    // 0x8001DDB8: sw          $a2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r6;
    // 0x8001DDBC: sw          $a3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r7;
    // 0x8001DDC0: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x8001DDC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001DDC8: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x8001DDCC: lw          $t2, 0x40($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X40);
    // 0x8001DDD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DDD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001DDD8: addiu       $s1, $sp, 0x98
    ctx->r17 = ADD32(ctx->r29, 0X98);
    // 0x8001DDDC: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8001DDE0: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8001DDE4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001DDE8: sh          $t6, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r14;
    // 0x8001DDEC: sh          $a2, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r6;
    // 0x8001DDF0: sh          $a3, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r7;
    // 0x8001DDF4: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x8001DDF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DDFC: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x8001DE00: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x8001DE04: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8001DE08: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x8001DE0C: jal         0x8006FE70
    // 0x8001DE10: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x8001DE10: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001DE14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DE18: jal         0x8006F820
    // 0x8001DE1C: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    mtxf_to_mtxs(rdram, ctx);
        goto after_1;
    // 0x8001DE1C: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    after_1:
    // 0x8001DE20: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x8001DE24: lh          $v0, 0x28($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X28);
    // 0x8001DE28: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8001DE2C: blez        $v0, L_8001E140
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001DE30: addiu       $s3, $s3, -0x4B18
        ctx->r19 = ADD32(ctx->r19, -0X4B18);
            goto L_8001E140;
    }
    // 0x8001DE30: addiu       $s3, $s3, -0x4B18
    ctx->r19 = ADD32(ctx->r19, -0X4B18);
    // 0x8001DE34: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001DE38: lw          $a2, 0x38($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X38);
    // 0x8001DE3C: addiu       $s1, $s1, -0x4A98
    ctx->r17 = ADD32(ctx->r17, -0X4A98);
L_8001DE40:
    // 0x8001DE40: lh          $s7, 0x62($sp)
    ctx->r23 = MEM_H(ctx->r29, 0X62);
    // 0x8001DE44: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8001DE48: sll         $t3, $s7, 2
    ctx->r11 = S32(ctx->r23 << 2);
    // 0x8001DE4C: subu        $t3, $t3, $s7
    ctx->r11 = SUB32(ctx->r11, ctx->r23);
    // 0x8001DE50: sll         $s7, $t3, 2
    ctx->r23 = S32(ctx->r11 << 2);
    // 0x8001DE54: addu        $a1, $a2, $s7
    ctx->r5 = ADD32(ctx->r6, ctx->r23);
    // 0x8001DE58: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x8001DE5C: nop

    // 0x8001DE60: andi        $t4, $v1, 0x8000
    ctx->r12 = ctx->r3 & 0X8000;
    // 0x8001DE64: beq         $t4, $zero, L_8001E0F4
    if (ctx->r12 == 0) {
        // 0x8001DE68: and         $t5, $v1, $at
        ctx->r13 = ctx->r3 & ctx->r1;
            goto L_8001E0F4;
    }
    // 0x8001DE68: and         $t5, $v1, $at
    ctx->r13 = ctx->r3 & ctx->r1;
    // 0x8001DE6C: ori         $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 | 0X8000;
    // 0x8001DE70: xori        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 ^ 0X8000;
    // 0x8001DE74: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x8001DE78: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x8001DE7C: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8001DE80: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8001DE84: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8001DE88: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8001DE8C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8001DE90: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8001DE94: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001DE98: beq         $v0, $a3, L_8001DEEC
    if (ctx->r2 == ctx->r7) {
        // 0x8001DE9C: addiu       $t9, $zero, 0x6
        ctx->r25 = ADD32(0, 0X6);
            goto L_8001DEEC;
    }
    // 0x8001DE9C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8001DEA0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001DEA4: beq         $v0, $at, L_8001DEDC
    if (ctx->r2 == ctx->r1) {
        // 0x8001DEA8: addiu       $t6, $zero, 0x5
        ctx->r14 = ADD32(0, 0X5);
            goto L_8001DEDC;
    }
    // 0x8001DEA8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8001DEAC: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001DEB0: beq         $v0, $at, L_8001DECC
    if (ctx->r2 == ctx->r1) {
        // 0x8001DEB4: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8001DECC;
    }
    // 0x8001DEB4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001DEB8: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8001DEBC: addiu       $t3, $zero, 0x1FF
    ctx->r11 = ADD32(0, 0X1FF);
    // 0x8001DEC0: sh          $t3, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r11;
    // 0x8001DEC4: b           L_8001DEF8
    // 0x8001DEC8: sh          $t2, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r10;
        goto L_8001DEF8;
    // 0x8001DEC8: sh          $t2, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r10;
L_8001DECC:
    // 0x8001DECC: addiu       $t5, $zero, 0xFFF
    ctx->r13 = ADD32(0, 0XFFF);
    // 0x8001DED0: sh          $t5, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r13;
    // 0x8001DED4: b           L_8001DEF8
    // 0x8001DED8: sh          $t4, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r12;
        goto L_8001DEF8;
    // 0x8001DED8: sh          $t4, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r12;
L_8001DEDC:
    // 0x8001DEDC: addiu       $t7, $zero, 0x7FF
    ctx->r15 = ADD32(0, 0X7FF);
    // 0x8001DEE0: sh          $t7, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r15;
    // 0x8001DEE4: b           L_8001DEF8
    // 0x8001DEE8: sh          $t6, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r14;
        goto L_8001DEF8;
    // 0x8001DEE8: sh          $t6, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r14;
L_8001DEEC:
    // 0x8001DEEC: addiu       $t8, $zero, 0x3FF
    ctx->r24 = ADD32(0, 0X3FF);
    // 0x8001DEF0: sh          $t8, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r24;
    // 0x8001DEF4: sh          $t9, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r25;
L_8001DEF8:
    // 0x8001DEF8: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8001DEFC: addiu       $s5, $zero, 0x6
    ctx->r21 = ADD32(0, 0X6);
    // 0x8001DF00: beq         $v0, $a3, L_8001DF3C
    if (ctx->r2 == ctx->r7) {
        // 0x8001DF04: addiu       $s6, $zero, 0x3FF
        ctx->r22 = ADD32(0, 0X3FF);
            goto L_8001DF3C;
    }
    // 0x8001DF04: addiu       $s6, $zero, 0x3FF
    ctx->r22 = ADD32(0, 0X3FF);
    // 0x8001DF08: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001DF0C: beq         $v0, $at, L_8001DF34
    if (ctx->r2 == ctx->r1) {
        // 0x8001DF10: addiu       $s5, $zero, 0x5
        ctx->r21 = ADD32(0, 0X5);
            goto L_8001DF34;
    }
    // 0x8001DF10: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x8001DF14: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001DF18: beq         $v0, $at, L_8001DF2C
    if (ctx->r2 == ctx->r1) {
        // 0x8001DF1C: addiu       $s5, $zero, 0x4
        ctx->r21 = ADD32(0, 0X4);
            goto L_8001DF2C;
    }
    // 0x8001DF1C: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x8001DF20: addiu       $s5, $zero, 0x7
    ctx->r21 = ADD32(0, 0X7);
    // 0x8001DF24: b           L_8001DF3C
    // 0x8001DF28: addiu       $s6, $zero, 0x1FF
    ctx->r22 = ADD32(0, 0X1FF);
        goto L_8001DF3C;
    // 0x8001DF28: addiu       $s6, $zero, 0x1FF
    ctx->r22 = ADD32(0, 0X1FF);
L_8001DF2C:
    // 0x8001DF2C: b           L_8001DF3C
    // 0x8001DF30: addiu       $s6, $zero, 0xFFF
    ctx->r22 = ADD32(0, 0XFFF);
        goto L_8001DF3C;
    // 0x8001DF30: addiu       $s6, $zero, 0xFFF
    ctx->r22 = ADD32(0, 0XFFF);
L_8001DF34:
    // 0x8001DF34: b           L_8001DF3C
    // 0x8001DF38: addiu       $s6, $zero, 0x7FF
    ctx->r22 = ADD32(0, 0X7FF);
        goto L_8001DF3C;
    // 0x8001DF38: addiu       $s6, $zero, 0x7FF
    ctx->r22 = ADD32(0, 0X7FF);
L_8001DF3C:
    // 0x8001DF3C: lh          $s0, 0x2($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X2);
    // 0x8001DF40: lh          $t0, 0xE($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XE);
    // 0x8001DF44: nop

    // 0x8001DF48: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001DF4C: beq         $at, $zero, L_8001E050
    if (ctx->r1 == 0) {
        // 0x8001DF50: sll         $t2, $s4, 2
        ctx->r10 = S32(ctx->r20 << 2);
            goto L_8001E050;
    }
L_8001DF50:
    // 0x8001DF50: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x8001DF54: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8001DF58: subu        $t2, $t2, $s4
    ctx->r10 = SUB32(ctx->r10, ctx->r20);
    // 0x8001DF5C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8001DF60: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8001DF64: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x8001DF68: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001DF6C: sh          $t3, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r11;
    // 0x8001DF70: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x8001DF74: sll         $t6, $s4, 16
    ctx->r14 = S32(ctx->r20 << 16);
    // 0x8001DF78: sh          $t4, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r12;
    // 0x8001DF7C: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x8001DF80: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001DF84: sra         $s4, $t6, 16
    ctx->r20 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001DF88: addiu       $a1, $a1, -0x4A92
    ctx->r5 = ADD32(ctx->r5, -0X4A92);
    // 0x8001DF8C: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x8001DF90: jal         0x8006FDA0
    // 0x8001DF94: sh          $t5, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r13;
    mtxs_transform_dir(rdram, ctx);
        goto after_2;
    // 0x8001DF94: sh          $t5, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r13;
    after_2:
    // 0x8001DF98: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8001DF9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DFA0: bne         $t9, $zero, L_8001DFB0
    if (ctx->r25 != 0) {
        // 0x8001DFA4: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001DFB0;
    }
    // 0x8001DFA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001DFA8: jal         0x8006FBF8
    // 0x8001DFAC: addiu       $a1, $a1, -0x4A92
    ctx->r5 = ADD32(ctx->r5, -0X4A92);
    vec3s_reflect(rdram, ctx);
        goto after_3;
    // 0x8001DFAC: addiu       $a1, $a1, -0x4A92
    ctx->r5 = ADD32(ctx->r5, -0X4A92);
    after_3:
L_8001DFB0:
    // 0x8001DFB0: lh          $v0, 0x6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X6);
    // 0x8001DFB4: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x8001DFB8: blez        $v0, L_8001DFCC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001DFBC: ori         $a3, $zero, 0x8000
        ctx->r7 = 0 | 0X8000;
            goto L_8001DFCC;
    }
    // 0x8001DFBC: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // 0x8001DFC0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001DFC4: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8001DFC8: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
L_8001DFCC:
    // 0x8001DFCC: blez        $v1, L_8001DFE0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001DFD0: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_8001DFE0;
    }
    // 0x8001DFD0: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8001DFD4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8001DFD8: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x8001DFDC: sra         $v1, $t1, 16
    ctx->r3 = S32(SIGNED(ctx->r9) >> 16);
L_8001DFE0:
    // 0x8001DFE0: addu        $v0, $t3, $a3
    ctx->r2 = ADD32(ctx->r11, ctx->r7);
    // 0x8001DFE4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8001DFE8: lh          $t0, 0x6A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X6A);
    // 0x8001DFEC: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8001DFF0: addu        $v1, $t6, $a3
    ctx->r3 = ADD32(ctx->r14, ctx->r7);
    // 0x8001DFF4: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001DFF8: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8001DFFC: lh          $t2, 0x68($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X68);
    // 0x8001E000: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001E004: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x8001E008: srav        $t1, $t5, $t0
    ctx->r9 = S32(SIGNED(ctx->r13) >> (ctx->r8 & 31));
    // 0x8001E00C: addu        $a0, $s3, $t8
    ctx->r4 = ADD32(ctx->r19, ctx->r24);
    // 0x8001E010: srav        $t4, $t9, $s5
    ctx->r12 = S32(SIGNED(ctx->r25) >> (ctx->r21 & 31));
    // 0x8001E014: and         $t5, $t4, $s6
    ctx->r13 = ctx->r12 & ctx->r22;
    // 0x8001E018: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8001E01C: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x8001E020: sh          $t5, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r13;
    // 0x8001E024: lw          $a2, 0x38($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X38);
    // 0x8001E028: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E02C: addu        $a1, $a2, $s7
    ctx->r5 = ADD32(ctx->r6, ctx->r23);
    // 0x8001E030: lh          $t0, 0xE($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XE);
    // 0x8001E034: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x8001E038: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001E03C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001E040: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x8001E044: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001E048: bne         $at, $zero, L_8001DF50
    if (ctx->r1 != 0) {
        // 0x8001E04C: sra         $s2, $t9, 16
        ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
            goto L_8001DF50;
    }
    // 0x8001E04C: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
L_8001E050:
    // 0x8001E050: lh          $s0, 0x4($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X4);
    // 0x8001E054: lh          $t1, 0x10($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X10);
    // 0x8001E058: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x8001E05C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001E060: beq         $at, $zero, L_8001E0E8
    if (ctx->r1 == 0) {
        // 0x8001E064: sll         $t2, $s0, 4
        ctx->r10 = S32(ctx->r16 << 4);
            goto L_8001E0E8;
    }
    // 0x8001E064: sll         $t2, $s0, 4
    ctx->r10 = S32(ctx->r16 << 4);
L_8001E068:
    // 0x8001E068: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x8001E06C: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x8001E070: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8001E074: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001E078: addu        $v1, $s3, $t4
    ctx->r3 = ADD32(ctx->r19, ctx->r12);
    // 0x8001E07C: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x8001E080: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8001E084: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x8001E088: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x8001E08C: addu        $a0, $s3, $t9
    ctx->r4 = ADD32(ctx->r19, ctx->r25);
    // 0x8001E090: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x8001E094: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x8001E098: lbu         $t1, 0x3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X3);
    // 0x8001E09C: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x8001E0A0: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x8001E0A4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001E0A8: addu        $a1, $s3, $t2
    ctx->r5 = ADD32(ctx->r19, ctx->r10);
    // 0x8001E0AC: sh          $t0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r8;
    // 0x8001E0B0: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x8001E0B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E0B8: sh          $t3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r11;
    // 0x8001E0BC: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8001E0C0: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x8001E0C4: sh          $t4, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r12;
    // 0x8001E0C8: lw          $a2, 0x38($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X38);
    // 0x8001E0CC: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8001E0D0: addu        $t7, $a2, $s7
    ctx->r15 = ADD32(ctx->r6, ctx->r23);
    // 0x8001E0D4: lh          $t9, 0x10($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X10);
    // 0x8001E0D8: nop

    // 0x8001E0DC: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001E0E0: bne         $at, $zero, L_8001E068
    if (ctx->r1 != 0) {
        // 0x8001E0E4: sll         $t2, $s0, 4
        ctx->r10 = S32(ctx->r16 << 4);
            goto L_8001E068;
    }
    // 0x8001E0E4: sll         $t2, $s0, 4
    ctx->r10 = S32(ctx->r16 << 4);
L_8001E0E8:
    // 0x8001E0E8: lh          $v0, 0x28($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X28);
    // 0x8001E0EC: b           L_8001E124
    // 0x8001E0F0: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
        goto L_8001E124;
    // 0x8001E0F0: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
L_8001E0F4:
    // 0x8001E0F4: lbu         $t8, 0x6($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X6);
    // 0x8001E0F8: nop

    // 0x8001E0FC: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x8001E100: beq         $at, $zero, L_8001E124
    if (ctx->r1 == 0) {
        // 0x8001E104: lh          $t5, 0x62($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X62);
            goto L_8001E124;
    }
    // 0x8001E104: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
    // 0x8001E108: lh          $t0, 0xE($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XE);
    // 0x8001E10C: lh          $t2, 0x2($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X2);
    // 0x8001E110: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x8001E114: subu        $s4, $t1, $t2
    ctx->r20 = SUB32(ctx->r9, ctx->r10);
    // 0x8001E118: sll         $t3, $s4, 16
    ctx->r11 = S32(ctx->r20 << 16);
    // 0x8001E11C: sra         $s4, $t3, 16
    ctx->r20 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8001E120: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
L_8001E124:
    // 0x8001E124: nop

    // 0x8001E128: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001E12C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8001E130: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001E134: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001E138: bne         $at, $zero, L_8001DE40
    if (ctx->r1 != 0) {
        // 0x8001E13C: sh          $t6, 0x62($sp)
        MEM_H(0X62, ctx->r29) = ctx->r14;
            goto L_8001DE40;
    }
    // 0x8001E13C: sh          $t6, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r14;
L_8001E140:
    // 0x8001E140: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001E144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E148: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E14C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001E150: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001E154: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001E158: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E15C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001E160: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001E164: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001E168: jr          $ra
    // 0x8001E16C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x8001E16C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void is_drumstick_unlocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F214: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009F218: lw          $v0, 0x318($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X318);
    // 0x8009F21C: nop

    // 0x8009F220: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8009F224: jr          $ra
    // 0x8009F228: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8009F228: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void obj_init_log(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800404DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800404E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800404E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800404E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800404EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800404F0: lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC);
    // 0x800404F4: lw          $a2, 0x14($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X14);
    // 0x800404F8: lh          $a0, 0x2E($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2E);
    // 0x800404FC: jal         0x800BEB74
    // 0x80040500: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    obj_wave_init(rdram, ctx);
        goto after_0;
    // 0x80040500: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80040504: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80040508: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004050C: lw          $t7, 0x4C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4C);
    // 0x80040510: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80040514: sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
    // 0x80040518: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8004051C: lw          $t9, 0x4C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4C);
    // 0x80040520: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80040524: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80040528: lw          $t1, 0x4C($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X4C);
    // 0x8004052C: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x80040530: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x80040534: lbu         $t3, 0x9($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X9);
    // 0x80040538: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004053C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80040540: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80040544: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80040548: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8004054C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80040550: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80040554: nop

    // 0x80040558: bc1f        L_80040568
    if (!c1cs) {
        // 0x8004055C: nop
    
            goto L_80040568;
    }
    // 0x8004055C: nop

    // 0x80040560: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80040564: nop

L_80040568:
    // 0x80040568: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004056C: lw          $t4, 0x40($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X40);
    // 0x80040570: nop

    // 0x80040574: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80040578: nop

    // 0x8004057C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80040580: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
    // 0x80040584: lbu         $t5, 0x8($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X8);
    // 0x80040588: nop

    // 0x8004058C: sb          $t5, 0x3A($a3)
    MEM_B(0X3A, ctx->r7) = ctx->r13;
    // 0x80040590: lbu         $t7, 0xA($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XA);
    // 0x80040594: nop

    // 0x80040598: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x8004059C: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
    // 0x800405A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800405A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800405A8: jr          $ra
    // 0x800405AC: nop

    return;
    // 0x800405AC: nop

;}
RECOMP_FUNC void music_get_fx_mix_all_channels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001440: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001444: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80001448: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8000144C: addiu       $s3, $s3, -0x3460
    ctx->r19 = ADD32(ctx->r19, -0X3460);
    // 0x80001450: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80001454: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80001458: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000145C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80001460: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80001464: lbu         $t6, 0x34($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X34);
    // 0x80001468: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000146C: blez        $t6, L_800014A0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80001470: or          $s2, $a0, $zero
        ctx->r18 = ctx->r4 | 0;
            goto L_800014A0;
    }
    // 0x80001470: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80001474: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80001478:
    // 0x80001478: jal         0x800C7F20
    // 0x8000147C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    alSeqpGetChlFXMix(rdram, ctx);
        goto after_0;
    // 0x8000147C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_0:
    // 0x80001480: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x80001484: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80001488: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000148C: lbu         $t7, 0x34($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X34);
    // 0x80001490: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80001494: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80001498: bne         $at, $zero, L_80001478
    if (ctx->r1 != 0) {
        // 0x8000149C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80001478;
    }
    // 0x8000149C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800014A0:
    // 0x800014A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800014A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800014A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800014AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800014B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800014B4: jr          $ra
    // 0x800014B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800014B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void track_spawn_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C8F8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8000C8FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000C900: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000C904: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000C908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000C90C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8000C910: jal         0x8006ECD0
    // 0x8000C914: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8000C914: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000C918: lbu         $t8, 0x49($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X49);
    // 0x8000C91C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8000C920: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000C924: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8000C928: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8000C92C: lhu         $s0, 0xC($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0XC);
    // 0x8000C930: andi        $t1, $v1, 0x4
    ctx->r9 = ctx->r3 & 0X4;
    // 0x8000C934: sltiu       $v1, $t1, 0x1
    ctx->r3 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8000C938: beq         $v1, $zero, L_8000C958
    if (ctx->r3 == 0) {
        // 0x8000C93C: ori         $t6, $s0, 0x820
        ctx->r14 = ctx->r16 | 0X820;
            goto L_8000C958;
    }
    // 0x8000C93C: ori         $t6, $s0, 0x820
    ctx->r14 = ctx->r16 | 0X820;
    // 0x8000C940: lbu         $t3, 0x48($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X48);
    // 0x8000C944: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000C948: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x8000C94C: and         $v1, $t5, $t6
    ctx->r3 = ctx->r13 & ctx->r14;
    // 0x8000C950: sltu        $t6, $zero, $v1
    ctx->r14 = 0 < ctx->r3 ? 1 : 0;
    // 0x8000C954: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8000C958:
    // 0x8000C958: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000C95C: addiu       $s0, $s0, -0x4C7D
    ctx->r16 = ADD32(ctx->r16, -0X4C7D);
    // 0x8000C960: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x8000C964: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x8000C968: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8000C96C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000C970: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8000C974: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000C978: nop

    // 0x8000C97C: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8000C980: bne         $t2, $zero, L_8000C98C
    if (ctx->r10 != 0) {
        // 0x8000C984: nop
    
            goto L_8000C98C;
    }
    // 0x8000C984: nop

    // 0x8000C988: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8000C98C:
    // 0x8000C98C: jal         0x8009C814
    // 0x8000C990: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_1;
    // 0x8000C990: nop

    after_1:
    // 0x8000C994: beq         $v0, $zero, L_8000C9A0
    if (ctx->r2 == 0) {
        // 0x8000C998: nop
    
            goto L_8000C9A0;
    }
    // 0x8000C998: nop

    // 0x8000C99C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8000C9A0:
    // 0x8000C9A0: jal         0x8006BFD8
    // 0x8000C9A4: nop

    level_type(rdram, ctx);
        goto after_2;
    // 0x8000C9A4: nop

    after_2:
    // 0x8000C9A8: beq         $v0, $zero, L_8000C9B4
    if (ctx->r2 == 0) {
        // 0x8000C9AC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000C9B4;
    }
    // 0x8000C9AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C9B0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8000C9B4:
    // 0x8000C9B4: sb          $zero, -0x4D42($at)
    MEM_B(-0X4D42, ctx->r1) = 0;
    // 0x8000C9B8: addiu       $a0, $zero, 0x3000
    ctx->r4 = ADD32(0, 0X3000);
    // 0x8000C9BC: jal         0x80070EDC
    // 0x8000C9C0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8000C9C0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_3:
    // 0x8000C9C4: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8000C9C8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000C9CC: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x8000C9D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000C9D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000C9D8: addiu       $t3, $t3, -0x4BD0
    ctx->r11 = ADD32(ctx->r11, -0X4BD0);
    // 0x8000C9DC: addiu       $t5, $t5, -0x4BE8
    ctx->r13 = ADD32(ctx->r13, -0X4BE8);
    // 0x8000C9E0: addiu       $t7, $t7, -0x4BE0
    ctx->r15 = ADD32(ctx->r15, -0X4BE0);
    // 0x8000C9E4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8000C9E8: addu        $a1, $t4, $t3
    ctx->r5 = ADD32(ctx->r12, ctx->r11);
    // 0x8000C9EC: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x8000C9F0: addiu       $t6, $v0, 0x10
    ctx->r14 = ADD32(ctx->r2, 0X10);
    // 0x8000C9F4: addu        $s2, $t4, $t7
    ctx->r18 = ADD32(ctx->r12, ctx->r15);
    // 0x8000C9F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C9FC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000CA00: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000CA04: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8000CA08: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8000CA0C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8000CA10: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8000CA14: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8000CA18: jal         0x80076EE4
    // 0x8000CA1C: sw          $t8, -0x4BD8($at)
    MEM_W(-0X4BD8, ctx->r1) = ctx->r24;
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8000CA1C: sw          $t8, -0x4BD8($at)
    MEM_W(-0X4BD8, ctx->r1) = ctx->r24;
    after_4:
    // 0x8000CA20: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8000CA24: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8000CA28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000CA2C: beq         $a1, $t9, L_8000CA48
    if (ctx->r5 == ctx->r25) {
        // 0x8000CA30: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000CA48;
    }
    // 0x8000CA30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000CA34: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8000CA38:
    // 0x8000CA38: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8000CA3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000CA40: bne         $a1, $t0, L_8000CA38
    if (ctx->r5 != ctx->r8) {
        // 0x8000CA44: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000CA38;
    }
    // 0x8000CA44: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000CA48:
    // 0x8000CA48: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8000CA4C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8000CA50: slt         $at, $t1, $a0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000CA54: bne         $at, $zero, L_8000CA60
    if (ctx->r1 != 0) {
        // 0x8000CA58: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_8000CA60;
    }
    // 0x8000CA58: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8000CA5C: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8000CA60:
    // 0x8000CA60: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8000CA64: nop

    // 0x8000CA68: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8000CA6C: addu        $v1, $v0, $t4
    ctx->r3 = ADD32(ctx->r2, ctx->r12);
    // 0x8000CA70: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x8000CA74: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x8000CA78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000CA7C: subu        $a3, $t3, $s0
    ctx->r7 = SUB32(ctx->r11, ctx->r16);
    // 0x8000CA80: beq         $a3, $zero, L_8000CBAC
    if (ctx->r7 == 0) {
        // 0x8000CA84: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000CBAC;
    }
    // 0x8000CA84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000CA88: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x8000CA8C: jal         0x800C673C
    // 0x8000CA90: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    gzip_size_uncompressed(rdram, ctx);
        goto after_5;
    // 0x8000CA90: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_5:
    // 0x8000CA94: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8000CA98: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8000CA9C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000CAA0: subu        $a1, $t6, $a3
    ctx->r5 = SUB32(ctx->r14, ctx->r7);
    // 0x8000CAA4: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8000CAA8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8000CAAC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8000CAB0: jal         0x80077190
    // 0x8000CAB4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_6;
    // 0x8000CAB4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x8000CAB8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8000CABC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8000CAC0: jal         0x800C6778
    // 0x8000CAC4: nop

    gzip_inflate(rdram, ctx);
        goto after_7;
    // 0x8000CAC4: nop

    after_7:
    // 0x8000CAC8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000CACC: jal         0x80071380
    // 0x8000CAD0: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8000CAD0: nop

    after_8:
    // 0x8000CAD4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000CAD8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8000CADC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000CAE0: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8000CAE4: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8000CAE8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000CAEC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000CAF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CAF4: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x8000CAF8: sw          $t2, -0x4BC0($at)
    MEM_W(-0X4BC0, ctx->r1) = ctx->r10;
    // 0x8000CAFC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8000CB00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000CB04: blez        $t4, L_8000CB58
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000CB08: nop
    
            goto L_8000CB58;
    }
    // 0x8000CB08: nop

L_8000CB0C:
    // 0x8000CB0C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000CB10: jal         0x8000EA54
    // 0x8000CB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_9;
    // 0x8000CB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8000CB18: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000CB1C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8000CB20: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x8000CB24: nop

    // 0x8000CB28: andi        $t3, $a0, 0x3F
    ctx->r11 = ctx->r4 & 0X3F;
    // 0x8000CB2C: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x8000CB30: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x8000CB34: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000CB38: bne         $at, $zero, L_8000CB0C
    if (ctx->r1 != 0) {
        // 0x8000CB3C: sw          $t5, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r13;
            goto L_8000CB0C;
    }
    // 0x8000CB3C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8000CB40: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000CB44: nop

    // 0x8000CB48: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000CB4C: nop

    // 0x8000CB50: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8000CB54: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_8000CB58:
    // 0x8000CB58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CB5C: sw          $zero, -0x4C10($at)
    MEM_W(-0X4C10, ctx->r1) = 0;
    // 0x8000CB60: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8000CB64: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000CB68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CB6C: addiu       $s1, $s1, -0x4CD4
    ctx->r17 = ADD32(ctx->r17, -0X4CD4);
    // 0x8000CB70: sw          $s0, -0x4CC0($at)
    MEM_W(-0X4CC0, ctx->r1) = ctx->r16;
    // 0x8000CB74: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8000CB78: nop

    // 0x8000CB7C: bne         $t0, $zero, L_8000CBA4
    if (ctx->r8 != 0) {
        // 0x8000CB80: nop
    
            goto L_8000CBA4;
    }
    // 0x8000CB80: nop

    // 0x8000CB84: jal         0x8001004C
    // 0x8000CB88: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_10;
    // 0x8000CB88: nop

    after_10:
    // 0x8000CB8C: jal         0x80017ECC
    // 0x8000CB90: nop

    checkpoint_update_all(rdram, ctx);
        goto after_11;
    // 0x8000CB90: nop

    after_11:
    // 0x8000CB94: jal         0x8001BC88
    // 0x8000CB98: nop

    spectate_update(rdram, ctx);
        goto after_12;
    // 0x8000CB98: nop

    after_12:
    // 0x8000CB9C: jal         0x8001E970
    // 0x8000CBA0: nop

    func_8001E93C(rdram, ctx);
        goto after_13;
    // 0x8000CBA0: nop

    after_13:
L_8000CBA4:
    // 0x8000CBA4: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x8000CBA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000CBAC:
    // 0x8000CBAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000CBB0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000CBB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000CBB8: jr          $ra
    // 0x8000CBBC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8000CBBC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void generate_track(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C104: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002C108: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002C10C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002C110: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002C114: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x8002C118: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8002C11C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8002C120: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8002C124: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002C128: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002C12C: jal         0x8007B7C4
    // 0x8002C130: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    set_texture_colour_tag(rdram, ctx);
        goto after_0;
    // 0x8002C130: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_0:
    // 0x8002C134: lui         $s5, 0x8
    ctx->r21 = S32(0X8 << 16);
    // 0x8002C138: ori         $s5, $s5, 0x2A00
    ctx->r21 = ctx->r21 | 0X2A00;
    // 0x8002C13C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8002C140: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8002C144: jal         0x80070EDC
    // 0x8002C148: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8002C148: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8002C14C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002C150: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8002C154: addiu       $s1, $s1, -0x3178
    ctx->r17 = ADD32(ctx->r17, -0X3178);
    // 0x8002C158: addiu       $v1, $v1, -0x2774
    ctx->r3 = ADD32(ctx->r3, -0X2774);
    // 0x8002C15C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8002C160: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002C164: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8002C168: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8002C16C: jal         0x80070EDC
    // 0x8002C170: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x8002C170: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    after_2:
    // 0x8002C174: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002C178: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8002C17C: sw          $v0, -0x2710($at)
    MEM_W(-0X2710, ctx->r1) = ctx->r2;
    // 0x8002C180: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8002C184: jal         0x80070EDC
    // 0x8002C188: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8002C188: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    after_3:
    // 0x8002C18C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002C190: sw          $v0, -0x270C($at)
    MEM_W(-0X270C, ctx->r1) = ctx->r2;
    // 0x8002C194: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002C198: sw          $zero, -0x2708($at)
    MEM_W(-0X2708, ctx->r1) = 0;
    // 0x8002C19C: jal         0x80076EE4
    // 0x8002C1A0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8002C1A0: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_4:
    // 0x8002C1A4: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002C1A8: addiu       $s4, $s4, -0x2770
    ctx->r20 = ADD32(ctx->r20, -0X2770);
    // 0x8002C1AC: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x8002C1B0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8002C1B4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8002C1B8: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8002C1BC: beq         $v1, $t7, L_8002C1D4
    if (ctx->r3 == ctx->r15) {
        // 0x8002C1C0: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8002C1D4;
    }
    // 0x8002C1C0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_8002C1C4:
    // 0x8002C1C4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8002C1C8: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8002C1CC: bne         $v1, $t8, L_8002C1C4
    if (ctx->r3 != ctx->r24) {
        // 0x8002C1D0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8002C1C4;
    }
    // 0x8002C1D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002C1D4:
    // 0x8002C1D4: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x8002C1D8: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002C1DC: bne         $at, $zero, L_8002C1E8
    if (ctx->r1 != 0) {
        // 0x8002C1E0: addiu       $a0, $zero, 0x1B
        ctx->r4 = ADD32(0, 0X1B);
            goto L_8002C1E8;
    }
    // 0x8002C1E0: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x8002C1E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8002C1E8:
    // 0x8002C1E8: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x8002C1EC: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x8002C1F0: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8002C1F4: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8002C1F8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8002C1FC: subu        $s3, $t5, $a2
    ctx->r19 = SUB32(ctx->r13, ctx->r6);
    // 0x8002C200: addu        $t6, $s0, $s5
    ctx->r14 = ADD32(ctx->r16, ctx->r21);
    // 0x8002C204: subu        $s0, $t6, $s3
    ctx->r16 = SUB32(ctx->r14, ctx->r19);
    // 0x8002C208: bgez        $s0, L_8002C21C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8002C20C: andi        $t7, $s0, 0xF
        ctx->r15 = ctx->r16 & 0XF;
            goto L_8002C21C;
    }
    // 0x8002C20C: andi        $t7, $s0, 0xF
    ctx->r15 = ctx->r16 & 0XF;
    // 0x8002C210: beq         $t7, $zero, L_8002C21C
    if (ctx->r15 == 0) {
        // 0x8002C214: nop
    
            goto L_8002C21C;
    }
    // 0x8002C214: nop

    // 0x8002C218: addiu       $t7, $t7, -0x10
    ctx->r15 = ADD32(ctx->r15, -0X10);
L_8002C21C:
    // 0x8002C21C: subu        $s0, $s0, $t7
    ctx->r16 = SUB32(ctx->r16, ctx->r15);
    // 0x8002C220: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002C224: jal         0x80077190
    // 0x8002C228: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    asset_load(rdram, ctx);
        goto after_5;
    // 0x8002C228: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_5:
    // 0x8002C22C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8002C230: jal         0x800C6778
    // 0x8002C234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gzip_inflate(rdram, ctx);
        goto after_6;
    // 0x8002C234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8002C238: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x8002C23C: jal         0x80071380
    // 0x8002C240: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8002C240: nop

    after_7:
    // 0x8002C244: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C248: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002C24C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8002C250: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002C254: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8002C258: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8002C25C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C260: nop

    // 0x8002C264: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x8002C268: nop

    // 0x8002C26C: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8002C270: sw          $t6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r14;
    // 0x8002C274: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C278: nop

    // 0x8002C27C: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x8002C280: nop

    // 0x8002C284: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x8002C288: sw          $t8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r24;
    // 0x8002C28C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C290: nop

    // 0x8002C294: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x8002C298: nop

    // 0x8002C29C: addu        $t5, $t9, $a2
    ctx->r13 = ADD32(ctx->r25, ctx->r6);
    // 0x8002C2A0: sw          $t5, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r13;
    // 0x8002C2A4: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C2A8: nop

    // 0x8002C2AC: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    // 0x8002C2B0: nop

    // 0x8002C2B4: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8002C2B8: sw          $t7, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r15;
    // 0x8002C2BC: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C2C0: nop

    // 0x8002C2C4: lw          $t8, 0x14($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X14);
    // 0x8002C2C8: nop

    // 0x8002C2CC: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8002C2D0: sw          $t9, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r25;
    // 0x8002C2D4: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C2D8: nop

    // 0x8002C2DC: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C2E0: nop

    // 0x8002C2E4: blez        $v1, L_8002C394
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002C2E8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8002C394;
    }
    // 0x8002C2E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8002C2EC:
    // 0x8002C2EC: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x8002C2F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C2F4: addu        $v0, $t5, $s3
    ctx->r2 = ADD32(ctx->r13, ctx->r19);
    // 0x8002C2F8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002C2FC: nop

    // 0x8002C300: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8002C304: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002C308: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002C30C: nop

    // 0x8002C310: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8002C314: nop

    // 0x8002C318: addu        $v0, $t9, $s3
    ctx->r2 = ADD32(ctx->r25, ctx->r19);
    // 0x8002C31C: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8002C320: nop

    // 0x8002C324: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8002C328: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002C32C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8002C330: nop

    // 0x8002C334: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8002C338: nop

    // 0x8002C33C: addu        $v0, $t8, $s3
    ctx->r2 = ADD32(ctx->r24, ctx->r19);
    // 0x8002C340: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8002C344: nop

    // 0x8002C348: addu        $t5, $t9, $a2
    ctx->r13 = ADD32(ctx->r25, ctx->r6);
    // 0x8002C34C: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x8002C350: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C354: nop

    // 0x8002C358: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C35C: nop

    // 0x8002C360: addu        $v0, $t7, $s3
    ctx->r2 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C364: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x8002C368: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
    // 0x8002C36C: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8002C370: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x8002C374: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C378: nop

    // 0x8002C37C: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C380: nop

    // 0x8002C384: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002C388: bne         $at, $zero, L_8002C2EC
    if (ctx->r1 != 0) {
        // 0x8002C38C: nop
    
            goto L_8002C2EC;
    }
    // 0x8002C38C: nop

    // 0x8002C390: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002C394:
    // 0x8002C394: lh          $t5, 0x18($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X18);
    // 0x8002C398: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002C39C: blez        $t5, L_8002C400
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8002C3A0: nop
    
            goto L_8002C400;
    }
    // 0x8002C3A0: nop

L_8002C3A4:
    // 0x8002C3A4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8002C3A8: nop

    // 0x8002C3AC: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x8002C3B0: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8002C3B4: nop

    // 0x8002C3B8: ori         $t8, $a0, 0x8000
    ctx->r24 = ctx->r4 | 0X8000;
    // 0x8002C3BC: jal         0x8007B2C4
    // 0x8002C3C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    load_texture(rdram, ctx);
        goto after_8;
    // 0x8002C3C0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_8:
    // 0x8002C3C4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002C3C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C3CC: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8002C3D0: nop

    // 0x8002C3D4: addu        $t6, $t5, $s3
    ctx->r14 = ADD32(ctx->r13, ctx->r19);
    // 0x8002C3D8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8002C3DC: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C3E0: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8002C3E4: lh          $t7, 0x18($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X18);
    // 0x8002C3E8: nop

    // 0x8002C3EC: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002C3F0: bne         $at, $zero, L_8002C3A4
    if (ctx->r1 != 0) {
        // 0x8002C3F4: nop
    
            goto L_8002C3A4;
    }
    // 0x8002C3F4: nop

    // 0x8002C3F8: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C3FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002C400:
    // 0x8002C400: lw          $t8, 0x48($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X48);
    // 0x8002C404: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8002C408: blez        $v1, L_8002C52C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002C40C: addu        $s4, $s2, $t8
        ctx->r20 = ADD32(ctx->r18, ctx->r24);
            goto L_8002C52C;
    }
    // 0x8002C40C: addu        $s4, $s2, $t8
    ctx->r20 = ADD32(ctx->r18, ctx->r24);
    // 0x8002C410: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002C414: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8002C418:
    // 0x8002C418: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x8002C41C: nop

    // 0x8002C420: addu        $t5, $t9, $s3
    ctx->r13 = ADD32(ctx->r25, ctx->r19);
    // 0x8002C424: sw          $s4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r20;
    // 0x8002C428: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C42C: nop

    // 0x8002C430: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C434: nop

    // 0x8002C438: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C43C: lh          $t9, 0x1E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X1E);
    // 0x8002C440: nop

    // 0x8002C444: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8002C448: jal         0x80071A90
    // 0x8002C44C: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    align16(rdram, ctx);
        goto after_9;
    // 0x8002C44C: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    after_9:
    // 0x8002C450: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C454: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8002C458: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C45C: nop

    // 0x8002C460: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C464: sw          $v0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r2;
    // 0x8002C468: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002C46C: nop

    // 0x8002C470: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8002C474: jal         0x8002CC70
    // 0x8002C478: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    track_init_collision(rdram, ctx);
        goto after_10;
    // 0x8002C478: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    after_10:
    // 0x8002C47C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C480: addu        $s4, $v0, $s4
    ctx->r20 = ADD32(ctx->r2, ctx->r20);
    // 0x8002C484: lw          $t6, 0x4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X4);
    // 0x8002C488: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x8002C48C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8002C490: addu        $a0, $t6, $s3
    ctx->r4 = ADD32(ctx->r14, ctx->r19);
    // 0x8002C494: jal         0x8002C994
    // 0x8002C498: addu        $a1, $t7, $s5
    ctx->r5 = ADD32(ctx->r15, ctx->r21);
    func_8002C954(rdram, ctx);
        goto after_11;
    // 0x8002C498: addu        $a1, $t7, $s5
    ctx->r5 = ADD32(ctx->r15, ctx->r21);
    after_11:
    // 0x8002C49C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4A0: nop

    // 0x8002C4A4: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8002C4A8: nop

    // 0x8002C4AC: addu        $t5, $t9, $s3
    ctx->r13 = ADD32(ctx->r25, ctx->r19);
    // 0x8002C4B0: sh          $zero, 0x30($t5)
    MEM_H(0X30, ctx->r13) = 0;
    // 0x8002C4B4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4B8: nop

    // 0x8002C4BC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C4C0: nop

    // 0x8002C4C4: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C4C8: sw          $s4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r20;
    // 0x8002C4CC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4D0: nop

    // 0x8002C4D4: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8002C4D8: jal         0x8002C75C
    // 0x8002C4DC: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    func_8002C71C(rdram, ctx);
        goto after_12;
    // 0x8002C4DC: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    after_12:
    // 0x8002C4E0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4E4: nop

    // 0x8002C4E8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C4EC: nop

    // 0x8002C4F0: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C4F4: lh          $t9, 0x32($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X32);
    // 0x8002C4F8: nop

    // 0x8002C4FC: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8002C500: jal         0x80071A90
    // 0x8002C504: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    align16(rdram, ctx);
        goto after_13;
    // 0x8002C504: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    after_13:
    // 0x8002C508: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C50C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C510: lh          $t6, 0x1A($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C514: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
    // 0x8002C518: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002C51C: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x8002C520: bne         $at, $zero, L_8002C418
    if (ctx->r1 != 0) {
        // 0x8002C524: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8002C418;
    }
    // 0x8002C524: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8002C528: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8002C52C:
    // 0x8002C52C: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8002C530: subu        $s3, $s4, $v0
    ctx->r19 = SUB32(ctx->r20, ctx->r2);
    // 0x8002C534: ori         $at, $at, 0x2A01
    ctx->r1 = ctx->r1 | 0X2A01;
    // 0x8002C538: slt         $at, $s3, $at
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8002C53C: bne         $at, $zero, L_8002C550
    if (ctx->r1 != 0) {
        // 0x8002C540: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8002C550;
    }
    // 0x8002C540: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002C544: addiu       $a0, $a0, 0x63C8
    ctx->r4 = ADD32(ctx->r4, 0X63C8);
    // 0x8002C548: jal         0x800CA2B4
    // 0x8002C54C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_14;
    // 0x8002C54C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_14:
L_8002C550:
    // 0x8002C550: jal         0x800712F0
    // 0x8002C554: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_15;
    // 0x8002C554: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x8002C558: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C55C: lw          $a0, -0x2774($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2774);
    // 0x8002C560: jal         0x80071380
    // 0x8002C564: nop

    mempool_free(rdram, ctx);
        goto after_16;
    // 0x8002C564: nop

    after_16:
    // 0x8002C568: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002C56C: lw          $a1, -0x2774($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2774);
    // 0x8002C570: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x8002C574: ori         $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 | 0XFF;
    // 0x8002C578: jal         0x80071138
    // 0x8002C57C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_alloc_fixed(rdram, ctx);
        goto after_17;
    // 0x8002C57C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_17:
    // 0x8002C580: jal         0x800712F0
    // 0x8002C584: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_18;
    // 0x8002C584: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_18:
    // 0x8002C588: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002C58C: jal         0x800A8910
    // 0x8002C590: nop

    minimap_init(rdram, ctx);
        goto after_19;
    // 0x8002C590: nop

    after_19:
    // 0x8002C594: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C598: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8002C59C: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C5A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C5A4: blez        $v1, L_8002C72C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002C5A8: lui         $t3, 0x800
        ctx->r11 = S32(0X800 << 16);
            goto L_8002C72C;
    }
    // 0x8002C5A8: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x8002C5AC: lw          $a2, 0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4);
    // 0x8002C5B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002C5B4: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
L_8002C5B8:
    // 0x8002C5B8: lh          $v0, 0x20($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X20);
    // 0x8002C5BC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8002C5C0: blez        $v0, L_8002C71C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002C5C4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8002C71C;
    }
    // 0x8002C5C4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002C5C8: lw          $a0, 0xC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC);
    // 0x8002C5CC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8002C5D0:
    // 0x8002C5D0: lh          $s0, 0x2($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X2);
    // 0x8002C5D4: lh          $t1, 0xE($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XE);
    // 0x8002C5D8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002C5DC: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C5E0: beq         $at, $zero, L_8002C708
    if (ctx->r1 == 0) {
        // 0x8002C5E4: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002C708;
    }
    // 0x8002C5E4: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002C5E8: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8002C5EC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8002C5F0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8002C5F4:
    // 0x8002C5F4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8002C5F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C5FC: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x8002C600: lbu         $t8, 0x6($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X6);
    // 0x8002C604: nop

    // 0x8002C608: bne         $t2, $t8, L_8002C6F4
    if (ctx->r10 != ctx->r24) {
        // 0x8002C60C: slt         $at, $s0, $t1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8002C6F4;
    }
    // 0x8002C60C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C610: lbu         $t9, 0x7($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X7);
    // 0x8002C614: nop

    // 0x8002C618: bne         $t2, $t9, L_8002C6F4
    if (ctx->r10 != ctx->r25) {
        // 0x8002C61C: slt         $at, $s0, $t1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8002C6F4;
    }
    // 0x8002C61C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C620: lbu         $t5, 0x8($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X8);
    // 0x8002C624: nop

    // 0x8002C628: sb          $t5, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r13;
    // 0x8002C62C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C630: nop

    // 0x8002C634: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C638: nop

    // 0x8002C63C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C640: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002C644: nop

    // 0x8002C648: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x8002C64C: sb          $a3, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r7;
    // 0x8002C650: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C654: nop

    // 0x8002C658: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C65C: nop

    // 0x8002C660: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C664: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002C668: nop

    // 0x8002C66C: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x8002C670: sb          $a3, 0x7($t5)
    MEM_B(0X7, ctx->r13) = ctx->r7;
    // 0x8002C674: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C678: nop

    // 0x8002C67C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C680: nop

    // 0x8002C684: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C688: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002C68C: nop

    // 0x8002C690: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x8002C694: sb          $a3, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r7;
    // 0x8002C698: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C69C: nop

    // 0x8002C6A0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C6A4: nop

    // 0x8002C6A8: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C6AC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8002C6B0: nop

    // 0x8002C6B4: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x8002C6B8: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x8002C6BC: nop

    // 0x8002C6C0: or          $t6, $t5, $t3
    ctx->r14 = ctx->r13 | ctx->r11;
    // 0x8002C6C4: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8002C6C8: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C6CC: nop

    // 0x8002C6D0: lw          $t7, 0x4($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X4);
    // 0x8002C6D4: nop

    // 0x8002C6D8: addu        $a2, $t7, $a1
    ctx->r6 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C6DC: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x8002C6E0: nop

    // 0x8002C6E4: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    // 0x8002C6E8: lh          $t1, 0xE($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XE);
    // 0x8002C6EC: nop

    // 0x8002C6F0: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
L_8002C6F4:
    // 0x8002C6F4: bne         $at, $zero, L_8002C5F4
    if (ctx->r1 != 0) {
        // 0x8002C6F8: addiu       $v0, $v0, 0xA
        ctx->r2 = ADD32(ctx->r2, 0XA);
            goto L_8002C5F4;
    }
    // 0x8002C6F8: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8002C6FC: lh          $v0, 0x20($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X20);
    // 0x8002C700: nop

    // 0x8002C704: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
L_8002C708:
    // 0x8002C708: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8002C70C: bne         $at, $zero, L_8002C5D0
    if (ctx->r1 != 0) {
        // 0x8002C710: addiu       $a0, $a0, 0xC
        ctx->r4 = ADD32(ctx->r4, 0XC);
            goto L_8002C5D0;
    }
    // 0x8002C710: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8002C714: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C718: nop

L_8002C71C:
    // 0x8002C71C: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002C720: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    // 0x8002C724: bne         $at, $zero, L_8002C5B8
    if (ctx->r1 != 0) {
        // 0x8002C728: addiu       $a2, $a2, 0x44
        ctx->r6 = ADD32(ctx->r6, 0X44);
            goto L_8002C5B8;
    }
    // 0x8002C728: addiu       $a2, $a2, 0x44
    ctx->r6 = ADD32(ctx->r6, 0X44);
L_8002C72C:
    // 0x8002C72C: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x8002C730: jal         0x8007B7C4
    // 0x8002C734: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    set_texture_colour_tag(rdram, ctx);
        goto after_20;
    // 0x8002C734: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_20:
    // 0x8002C738: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C73C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002C740: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002C744: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C748: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002C74C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8002C750: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8002C754: jr          $ra
    // 0x8002C758: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002C758: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void waves_block_hq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9748: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B974C: lw          $a1, -0x5960($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5960);
    // 0x800B9750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B9754: blez        $a1, L_800B97A4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800B9758: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800B97A4;
    }
    // 0x800B9758: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B975C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800B9760: lw          $a2, 0x3668($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3668);
    // 0x800B9764: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x800B9768: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800B976C: nop

    // 0x800B9770: beq         $a0, $t6, L_800B97A4
    if (ctx->r4 == ctx->r14) {
        // 0x800B9774: nop
    
            goto L_800B97A4;
    }
    // 0x800B9774: nop

L_800B9778:
    // 0x800B9778: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B977C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800B9780: beq         $at, $zero, L_800B97A4
    if (ctx->r1 == 0) {
        // 0x800B9784: nop
    
            goto L_800B97A4;
    }
    // 0x800B9784: nop

    // 0x800B9788: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B978C: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9790: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x800B9794: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B9798: nop

    // 0x800B979C: bne         $a0, $t9, L_800B9778
    if (ctx->r4 != ctx->r25) {
        // 0x800B97A0: nop
    
            goto L_800B9778;
    }
    // 0x800B97A0: nop

L_800B97A4:
    // 0x800B97A4: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x800B97A8: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B97AC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B97B0: lw          $t0, 0x3668($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3668);
    // 0x800B97B4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B97B8: lw          $t5, 0x3664($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3664);
    // 0x800B97BC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800B97C0: addiu       $a1, $a1, 0x366C
    ctx->r5 = ADD32(ctx->r5, 0X366C);
    // 0x800B97C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B97C8: mflo        $t1
    ctx->r9 = lo;
    // 0x800B97CC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B97D0: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x800B97D4: nop

    // 0x800B97D8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B97DC: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800B97E0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B97E4: nop

    // 0x800B97E8: beq         $t7, $zero, L_800B980C
    if (ctx->r15 == 0) {
        // 0x800B97EC: nop
    
            goto L_800B980C;
    }
    // 0x800B97EC: nop

    // 0x800B97F0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800B97F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B97F8: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800B97FC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B9800: sh          $v0, -0x5858($at)
    MEM_H(-0X5858, ctx->r1) = ctx->r2;
    // 0x800B9804: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x800B9808: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_800B980C:
    // 0x800B980C: jr          $ra
    // 0x800B9810: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B9810: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void load_level_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CD98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006CD9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006CDA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006CDA4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006CDA8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006CDAC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006CDB0: jal         0x8006EF3C
    // 0x8006CDB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    alloc_displaylist_heap(rdram, ctx);
        goto after_0;
    // 0x8006CDB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8006CDB8: jal         0x800712F0
    // 0x8006CDBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_1;
    // 0x8006CDBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8006CDC0: jal         0x800660E0
    // 0x8006CDC4: nop

    cam_init(rdram, ctx);
        goto after_2;
    // 0x8006CDC4: nop

    after_2:
    // 0x8006CDC8: jal         0x800C35A0
    // 0x8006CDCC: nop

    load_game_text_table(rdram, ctx);
        goto after_3;
    // 0x8006CDCC: nop

    after_3:
    // 0x8006CDD0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006CDD4: lw          $t6, 0x3A88($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A88);
    // 0x8006CDD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006CDDC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006CDE0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8006CDE4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CDE8: jal         0x8006B490
    // 0x8006CDEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    level_load(rdram, ctx);
        goto after_4;
    // 0x8006CDEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
    // 0x8006CDF0: jal         0x80066450
    // 0x8006CDF4: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_5;
    // 0x8006CDF4: nop

    after_5:
    // 0x8006CDF8: jal         0x8009F230
    // 0x8006CDFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    hud_init(rdram, ctx);
        goto after_6;
    // 0x8006CDFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8006CE00: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8006CE04: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006CE08: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8006CE0C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8006CE10: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8006CE14: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x8006CE18: jal         0x800AEC88
    // 0x8006CE1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    init_particle_buffers(rdram, ctx);
        goto after_7;
    // 0x8006CE1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x8006CE20: jal         0x8001BF54
    // 0x8006CE24: nop

    ainode_update(rdram, ctx);
        goto after_8;
    // 0x8006CE24: nop

    after_8:
    // 0x8006CE28: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006CE2C: jal         0x800CD7C0
    // 0x8006CE30: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_9;
    // 0x8006CE30: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
    // 0x8006CE34: jal         0x800712F0
    // 0x8006CE38: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_10;
    // 0x8006CE38: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x8006CE3C: jal         0x800724E4
    // 0x8006CE40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_init(rdram, ctx);
        goto after_11;
    // 0x8006CE40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x8006CE44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CE48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006CE4C: jr          $ra
    // 0x8006CE50: nop

    return;
    // 0x8006CE50: nop

;}
RECOMP_FUNC void update_camera_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D5D0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004D5D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004D5D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004D5DC: lw          $v0, -0x2540($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2540);
    // 0x8004D5E0: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8004D5E4: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8004D5E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004D5EC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004D5F0: swc1        $f12, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f12.u32l;
    // 0x8004D5F4: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x8004D5F8: bne         $at, $zero, L_8004D620
    if (ctx->r1 != 0) {
        // 0x8004D5FC: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_8004D620;
    }
    // 0x8004D5FC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8004D600: addiu       $t6, $v0, -0x3C
    ctx->r14 = ADD32(ctx->r2, -0X3C);
    // 0x8004D604: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8004D608: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004D60C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004D610: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004D614: nop

    // 0x8004D618: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004D61C: add.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f10.fl;
L_8004D620:
    // 0x8004D620: lh          $t7, 0x1A0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X1A0);
    // 0x8004D624: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x8004D628: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x8004D62C: sh          $t9, 0x196($a2)
    MEM_H(0X196, ctx->r6) = ctx->r25;
    // 0x8004D630: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
    // 0x8004D634: jal         0x80066450
    // 0x8004D638: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8004D638: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    after_0:
    // 0x8004D63C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004D640: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8004D644: bne         $v0, $a0, L_8004D658
    if (ctx->r2 != ctx->r4) {
        // 0x8004D648: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8004D658;
    }
    // 0x8004D648: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8004D64C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8004D650: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004D654: nop

L_8004D658:
    // 0x8004D658: addiu       $s0, $s0, -0x2578
    ctx->r16 = ADD32(ctx->r16, -0X2578);
    // 0x8004D65C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D660: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004D664: lbu         $v1, 0x3B($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3B);
    // 0x8004D668: nop

    // 0x8004D66C: bne         $a0, $v1, L_8004D680
    if (ctx->r4 != ctx->r3) {
        // 0x8004D670: lui         $at, 0x420C
        ctx->r1 = S32(0X420C << 16);
            goto L_8004D680;
    }
    // 0x8004D670: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8004D674: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004D678: nop

    // 0x8004D67C: add.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f16.fl;
L_8004D680:
    // 0x8004D680: bne         $a0, $v1, L_8004D694
    if (ctx->r4 != ctx->r3) {
        // 0x8004D684: lui         $at, 0x420C
        ctx->r1 = S32(0X420C << 16);
            goto L_8004D694;
    }
    // 0x8004D684: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8004D688: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004D68C: nop

    // 0x8004D690: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
L_8004D694:
    // 0x8004D694: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8004D698: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8004D69C: sub.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8004D6A0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004D6A4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8004D6A8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8004D6AC: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8004D6B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004D6B4: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x8004D6B8: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x8004D6BC: add.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
    // 0x8004D6C0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D6C4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8004D6C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004D6CC: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x8004D6D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D6D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004D6D8: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x8004D6DC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8004D6E0: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x8004D6E4: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x8004D6E8: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x8004D6EC: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x8004D6F0: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x8004D6F4: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x8004D6F8: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x8004D6FC: swc1        $f2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f2.u32l;
    // 0x8004D700: swc1        $f2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f2.u32l;
    // 0x8004D704: jal         0x8006FE70
    // 0x8004D708: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_1;
    // 0x8004D708: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    after_1:
    // 0x8004D70C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8004D710: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D714: lw          $a3, 0x1C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X1C);
    // 0x8004D718: addiu       $t8, $sp, 0x90
    ctx->r24 = ADD32(ctx->r29, 0X90);
    // 0x8004D71C: addiu       $t7, $sp, 0x8C
    ctx->r15 = ADD32(ctx->r29, 0X8C);
    // 0x8004D720: addiu       $t9, $sp, 0x88
    ctx->r25 = ADD32(ctx->r29, 0X88);
    // 0x8004D724: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8004D728: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8004D72C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8004D730: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8004D734: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8004D738: jal         0x8006F88C
    // 0x8004D73C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x8004D73C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x8004D740: lw          $v0, 0xAC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XAC);
    // 0x8004D744: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8004D748: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004D74C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8004D750: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8004D754: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x8004D758: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    // 0x8004D75C: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8004D760: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004D764: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8004D768: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004D76C: swc1        $f6, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f6.u32l;
    // 0x8004D770: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004D774: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004D778: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8004D77C: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8004D780: jal         0x80070A04
    // 0x8004D784: swc1        $f10, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f10.u32l;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x8004D784: swc1        $f10, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f10.u32l;
    after_3:
    // 0x8004D788: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8004D78C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D790: lwc1        $f18, 0x1C($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x8004D794: addiu       $t5, $sp, 0x90
    ctx->r13 = ADD32(ctx->r29, 0X90);
    // 0x8004D798: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8004D79C: addiu       $t6, $sp, 0x8C
    ctx->r14 = ADD32(ctx->r29, 0X8C);
    // 0x8004D7A0: addiu       $t8, $sp, 0x88
    ctx->r24 = ADD32(ctx->r29, 0X88);
    // 0x8004D7A4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8004D7A8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8004D7AC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8004D7B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8004D7B4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8004D7B8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8004D7BC: jal         0x8006F88C
    // 0x8004D7C0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    mtxf_transform_point(rdram, ctx);
        goto after_4;
    // 0x8004D7C0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_4:
    // 0x8004D7C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D7C8: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8004D7CC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004D7D0: ori         $t0, $zero, 0x8001
    ctx->r8 = 0 | 0X8001;
    // 0x8004D7D4: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004D7D8: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x8004D7DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D7E0: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8004D7E4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004D7E8: nop

    // 0x8004D7EC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8004D7F0: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8004D7F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D7F8: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004D7FC: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004D800: nop

    // 0x8004D804: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004D808: swc1        $f16, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f16.u32l;
    // 0x8004D80C: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8004D810: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D814: lh          $a0, 0x4($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X4);
    // 0x8004D818: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x8004D81C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8004D820: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8004D824: andi        $t2, $a2, 0xFFFF
    ctx->r10 = ctx->r6 & 0XFFFF;
    // 0x8004D828: subu        $v1, $t9, $t2
    ctx->r3 = SUB32(ctx->r25, ctx->r10);
    // 0x8004D82C: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004D830: bne         $at, $zero, L_8004D840
    if (ctx->r1 != 0) {
        // 0x8004D834: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004D840;
    }
    // 0x8004D834: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004D838: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004D83C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004D840:
    // 0x8004D840: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004D844: beq         $at, $zero, L_8004D850
    if (ctx->r1 == 0) {
        // 0x8004D848: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004D850;
    }
    // 0x8004D848: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004D84C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004D850:
    // 0x8004D850: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8004D854: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8004D858: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8004D85C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004D860: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004D864: nop

    // 0x8004D868: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8004D86C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8004D870: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8004D874: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004D878: mflo        $t3
    ctx->r11 = lo;
    // 0x8004D87C: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8004D880: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x8004D884: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x8004D888: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x8004D88C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D890: lh          $a0, 0x2($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X2);
    // 0x8004D894: lh          $a3, 0x2($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X2);
    // 0x8004D898: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8004D89C: andi        $t8, $a3, 0xFFFF
    ctx->r24 = ctx->r7 & 0XFFFF;
    // 0x8004D8A0: subu        $v1, $a0, $t8
    ctx->r3 = SUB32(ctx->r4, ctx->r24);
    // 0x8004D8A4: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004D8A8: bne         $at, $zero, L_8004D8B8
    if (ctx->r1 != 0) {
        // 0x8004D8AC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004D8B8;
    }
    // 0x8004D8AC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004D8B0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004D8B4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004D8B8:
    // 0x8004D8B8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004D8BC: beq         $at, $zero, L_8004D8C8
    if (ctx->r1 == 0) {
        // 0x8004D8C0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004D8C8;
    }
    // 0x8004D8C0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004D8C4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004D8C8:
    // 0x8004D8C8: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004D8CC: mflo        $t7
    ctx->r15 = lo;
    // 0x8004D8D0: sra         $t9, $t7, 4
    ctx->r25 = S32(SIGNED(ctx->r15) >> 4);
    // 0x8004D8D4: addu        $t2, $a3, $t9
    ctx->r10 = ADD32(ctx->r7, ctx->r25);
    // 0x8004D8D8: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x8004D8DC: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8004D8E0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8004D8E4: lh          $t3, 0x196($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X196);
    // 0x8004D8E8: nop

    // 0x8004D8EC: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x8004D8F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D8F4: nop

    // 0x8004D8F8: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004D8FC: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004D900: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x8004D904: jal         0x80029F58
    // 0x8004D908: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_5;
    // 0x8004D908: nop

    after_5:
    // 0x8004D90C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004D910: beq         $v0, $at, L_8004D924
    if (ctx->r2 == ctx->r1) {
        // 0x8004D914: nop
    
            goto L_8004D924;
    }
    // 0x8004D914: nop

    // 0x8004D918: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8004D91C: nop

    // 0x8004D920: sh          $v0, 0x34($t5)
    MEM_H(0X34, ctx->r13) = ctx->r2;
L_8004D924:
    // 0x8004D924: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8004D928: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8004D92C: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8004D930: nop

    // 0x8004D934: sh          $t8, 0x196($t7)
    MEM_H(0X196, ctx->r15) = ctx->r24;
    // 0x8004D938: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D93C: nop

    // 0x8004D940: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004D944: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8004D948: nop

    // 0x8004D94C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004D950: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8004D954: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D958: nop

    // 0x8004D95C: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004D960: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8004D964: nop

    // 0x8004D968: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8004D96C: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x8004D970: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D974: nop

    // 0x8004D978: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004D97C: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8004D980: nop

    // 0x8004D984: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004D988: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x8004D98C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D990: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004D994: jr          $ra
    // 0x8004D998: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8004D998: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_8006D968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DBA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006DBAC: lw          $t6, 0x3A6C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3A6C);
    // 0x8006DBB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006DBB4: beq         $t6, $at, L_8006DC44
    if (ctx->r14 == ctx->r1) {
        // 0x8006DBB8: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8006DC44;
    }
    // 0x8006DBB8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DBBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006DBC0: lw          $t7, 0x3A74($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3A74);
    // 0x8006DBC4: addiu       $a2, $a2, 0x17D0
    ctx->r6 = ADD32(ctx->r6, 0X17D0);
    // 0x8006DBC8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006DBCC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DBD0: addiu       $v0, $v0, 0x17D2
    ctx->r2 = ADD32(ctx->r2, 0X17D2);
    // 0x8006DBD4: addiu       $v1, $v1, 0x17D0
    ctx->r3 = ADD32(ctx->r3, 0X17D0);
    // 0x8006DBD8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006DBDC: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
L_8006DBE0:
    // 0x8006DBE0: lb          $t8, 0x8($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X8);
    // 0x8006DBE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006DBE8: sb          $t8, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r24;
    // 0x8006DBEC: lb          $t9, 0xA($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XA);
    // 0x8006DBF0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006DBF4: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
    // 0x8006DBF8: lb          $t0, 0xB($a1)
    ctx->r8 = MEM_B(ctx->r5, 0XB);
    // 0x8006DBFC: nop

    // 0x8006DC00: sb          $t0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r8;
    // 0x8006DC04: lb          $t1, 0xD($a1)
    ctx->r9 = MEM_B(ctx->r5, 0XD);
    // 0x8006DC08: nop

    // 0x8006DC0C: sb          $t1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r9;
    // 0x8006DC10: lb          $t2, 0x11($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X11);
    // 0x8006DC14: nop

    // 0x8006DC18: sb          $t2, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r10;
    // 0x8006DC1C: lb          $t3, 0x13($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X13);
    // 0x8006DC20: bne         $v1, $v0, L_8006DBE0
    if (ctx->r3 != ctx->r2) {
        // 0x8006DC24: sb          $t3, 0xB($v1)
        MEM_B(0XB, ctx->r3) = ctx->r11;
            goto L_8006DBE0;
    }
    // 0x8006DC24: sb          $t3, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r11;
    // 0x8006DC28: lb          $t4, 0x16($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X16);
    // 0x8006DC2C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006DC30: sb          $t4, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r12;
    // 0x8006DC34: lb          $t5, 0x17($a0)
    ctx->r13 = MEM_B(ctx->r4, 0X17);
    // 0x8006DC38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DC3C: sb          $t5, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r13;
    // 0x8006DC40: sw          $t6, 0x3A7C($at)
    MEM_W(0X3A7C, ctx->r1) = ctx->r14;
L_8006DC44:
    // 0x8006DC44: jr          $ra
    // 0x8006DC48: nop

    return;
    // 0x8006DC48: nop

;}
RECOMP_FUNC void audspat_point_set_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800096D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800096DC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800096E0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800096E4: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x800096E8: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x800096EC: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800096F0: jr          $ra
    // 0x800096F4: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800096F4: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void hud_balloons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A76E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A76EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A76F0: jal         0x8006ECD0
    // 0x800A76F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x800A76F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A76F8: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A76FC: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A7700: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A7704: bne         $t6, $zero, L_800A7714
    if (ctx->r14 != 0) {
        // 0x800A7708: addiu       $t7, $zero, 0x286
        ctx->r15 = ADD32(0, 0X286);
            goto L_800A7714;
    }
    // 0x800A7708: addiu       $t7, $zero, 0x286
    ctx->r15 = ADD32(0, 0X286);
    // 0x800A770C: b           L_800A771C
    // 0x800A7710: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
        goto L_800A771C;
    // 0x800A7710: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800A7714:
    // 0x800A7714: addiu       $t8, $zero, 0x348
    ctx->r24 = ADD32(0, 0X348);
    // 0x800A7718: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_800A771C:
    // 0x800A771C: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x800A7720: nop

    // 0x800A7724: andi        $t2, $t9, 0x4
    ctx->r10 = ctx->r25 & 0X4;
    // 0x800A7728: beq         $t2, $zero, L_800A773C
    if (ctx->r10 == 0) {
        // 0x800A772C: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800A773C;
    }
    // 0x800A772C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A7730: lw          $t4, 0x729C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X729C);
    // 0x800A7734: addiu       $t3, $zero, 0x45
    ctx->r11 = ADD32(0, 0X45);
    // 0x800A7738: sh          $t3, 0x266($t4)
    MEM_H(0X266, ctx->r12) = ctx->r11;
L_800A773C:
    // 0x800A773C: jal         0x8001E474
    // 0x800A7740: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    cutscene_id(rdram, ctx);
        goto after_1;
    // 0x800A7740: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x800A7744: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7748: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A774C: bne         $v0, $at, L_800A7784
    if (ctx->r2 != ctx->r1) {
        // 0x800A7750: nop
    
            goto L_800A7784;
    }
    // 0x800A7750: nop

    // 0x800A7754: jal         0x8001AE88
    // 0x800A7758: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    get_balloon_cutscene_timer(rdram, ctx);
        goto after_2;
    // 0x800A7758: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x800A775C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800A7760: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7764: sltu        $at, $v0, $t5
    ctx->r1 = ctx->r2 < ctx->r13 ? 1 : 0;
    // 0x800A7768: beq         $at, $zero, L_800A7784
    if (ctx->r1 == 0) {
        // 0x800A776C: nop
    
            goto L_800A7784;
    }
    // 0x800A776C: nop

    // 0x800A7770: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A7774: nop

    // 0x800A7778: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
    // 0x800A777C: b           L_800A77F4
    // 0x800A7780: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
        goto L_800A77F4;
    // 0x800A7780: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_800A7784:
    // 0x800A7784: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A7788: nop

    // 0x800A778C: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
    // 0x800A7790: jal         0x8001E474
    // 0x800A7794: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    cutscene_id(rdram, ctx);
        goto after_3;
    // 0x800A7794: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x800A7798: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800A779C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A77A0: bne         $v0, $at, L_800A77F4
    if (ctx->r2 != ctx->r1) {
        // 0x800A77A4: nop
    
            goto L_800A77F4;
    }
    // 0x800A77A4: nop

    // 0x800A77A8: jal         0x8001AE88
    // 0x800A77AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    get_balloon_cutscene_timer(rdram, ctx);
        goto after_4;
    // 0x800A77AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_4:
    // 0x800A77B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A77B4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800A77B8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A77BC: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x800A77C0: beq         $at, $zero, L_800A77F4
    if (ctx->r1 == 0) {
        // 0x800A77C4: nop
    
            goto L_800A77F4;
    }
    // 0x800A77C4: nop

    // 0x800A77C8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A77CC: addiu       $a1, $a1, 0x7304
    ctx->r5 = ADD32(ctx->r5, 0X7304);
    // 0x800A77D0: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A77D4: nop

    // 0x800A77D8: bne         $t2, $zero, L_800A77F4
    if (ctx->r10 != 0) {
        // 0x800A77DC: nop
    
            goto L_800A77F4;
    }
    // 0x800A77DC: nop

    // 0x800A77E0: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x800A77E4: jal         0x80001D04
    // 0x800A77E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x800A77E8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x800A77EC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800A77F0: nop

L_800A77F4:
    // 0x800A77F4: bgez        $v1, L_800A7800
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A77F8: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_800A7800;
    }
    // 0x800A77F8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800A77FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800A7800:
    // 0x800A7800: div         $zero, $v1, $t1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r9)));
    // 0x800A7804: bne         $t1, $zero, L_800A7810
    if (ctx->r9 != 0) {
        // 0x800A7808: nop
    
            goto L_800A7810;
    }
    // 0x800A7808: nop

    // 0x800A780C: break       7
    do_break(2148169740);
L_800A7810:
    // 0x800A7810: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7814: bne         $t1, $at, L_800A7828
    if (ctx->r9 != ctx->r1) {
        // 0x800A7818: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A7828;
    }
    // 0x800A7818: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A781C: bne         $v1, $at, L_800A7828
    if (ctx->r3 != ctx->r1) {
        // 0x800A7820: nop
    
            goto L_800A7828;
    }
    // 0x800A7820: nop

    // 0x800A7824: break       6
    do_break(2148169764);
L_800A7828:
    // 0x800A7828: mflo        $v0
    ctx->r2 = lo;
    // 0x800A782C: beq         $v0, $zero, L_800A78A4
    if (ctx->r2 == 0) {
        // 0x800A7830: nop
    
            goto L_800A78A4;
    }
    // 0x800A7830: nop

    // 0x800A7834: div         $zero, $v1, $t1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r9)));
    // 0x800A7838: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A783C: addiu       $t0, $t0, 0x729C
    ctx->r8 = ADD32(ctx->r8, 0X729C);
    // 0x800A7840: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A7844: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7848: sh          $v0, 0x2B8($t3)
    MEM_H(0X2B8, ctx->r11) = ctx->r2;
    // 0x800A784C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A7850: bne         $t1, $zero, L_800A785C
    if (ctx->r9 != 0) {
        // 0x800A7854: nop
    
            goto L_800A785C;
    }
    // 0x800A7854: nop

    // 0x800A7858: break       7
    do_break(2148169816);
L_800A785C:
    // 0x800A785C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7860: bne         $t1, $at, L_800A7874
    if (ctx->r9 != ctx->r1) {
        // 0x800A7864: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A7874;
    }
    // 0x800A7864: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A7868: bne         $v1, $at, L_800A7874
    if (ctx->r3 != ctx->r1) {
        // 0x800A786C: nop
    
            goto L_800A7874;
    }
    // 0x800A786C: nop

    // 0x800A7870: break       6
    do_break(2148169840);
L_800A7874:
    // 0x800A7874: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7878: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A787C: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7880: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7884: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7888: mfhi        $t4
    ctx->r12 = hi;
    // 0x800A788C: sh          $t4, 0x2D8($t5)
    MEM_H(0X2D8, ctx->r13) = ctx->r12;
    // 0x800A7890: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A7894: jal         0x800AAB5C
    // 0x800A7898: addiu       $a3, $a3, 0x2C0
    ctx->r7 = ADD32(ctx->r7, 0X2C0);
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A7898: addiu       $a3, $a3, 0x2C0
    ctx->r7 = ADD32(ctx->r7, 0X2C0);
    after_6:
    // 0x800A789C: b           L_800A78E0
    // 0x800A78A0: nop

        goto L_800A78E0;
    // 0x800A78A0: nop

L_800A78A4:
    // 0x800A78A4: div         $zero, $v1, $t1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r9)));
    // 0x800A78A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A78AC: lw          $t7, 0x729C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X729C);
    // 0x800A78B0: bne         $t1, $zero, L_800A78BC
    if (ctx->r9 != 0) {
        // 0x800A78B4: nop
    
            goto L_800A78BC;
    }
    // 0x800A78B4: nop

    // 0x800A78B8: break       7
    do_break(2148169912);
L_800A78BC:
    // 0x800A78BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A78C0: bne         $t1, $at, L_800A78D4
    if (ctx->r9 != ctx->r1) {
        // 0x800A78C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A78D4;
    }
    // 0x800A78C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A78C8: bne         $v1, $at, L_800A78D4
    if (ctx->r3 != ctx->r1) {
        // 0x800A78CC: nop
    
            goto L_800A78D4;
    }
    // 0x800A78CC: nop

    // 0x800A78D0: break       6
    do_break(2148169936);
L_800A78D4:
    // 0x800A78D4: mfhi        $t6
    ctx->r14 = hi;
    // 0x800A78D8: sh          $t6, 0x2B8($t7)
    MEM_H(0X2B8, ctx->r15) = ctx->r14;
    // 0x800A78DC: nop

L_800A78E0:
    // 0x800A78E0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A78E4: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A78E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A78EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A78F0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A78F4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A78F8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A78FC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7900: jal         0x800AAB5C
    // 0x800A7904: addiu       $a3, $a3, 0x2A0
    ctx->r7 = ADD32(ctx->r7, 0X2A0);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A7904: addiu       $a3, $a3, 0x2A0
    ctx->r7 = ADD32(ctx->r7, 0X2A0);
    after_7:
    // 0x800A7908: jal         0x800662D8
    // 0x800A790C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_8;
    // 0x800A790C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x800A7910: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800A7914: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800A7918: nop

    // 0x800A791C: bne         $t8, $zero, L_800A792C
    if (ctx->r24 != 0) {
        // 0x800A7920: nop
    
            goto L_800A792C;
    }
    // 0x800A7920: nop

    // 0x800A7924: jal         0x8007C36C
    // 0x800A7928: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_9;
    // 0x800A7928: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
L_800A792C:
    // 0x800A792C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A7930: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A7934: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7938: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A793C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7940: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A7944: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7948: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A794C: jal         0x800AAB5C
    // 0x800A7950: addiu       $a3, $a3, 0x260
    ctx->r7 = ADD32(ctx->r7, 0X260);
    hud_element_render(rdram, ctx);
        goto after_10;
    // 0x800A7950: addiu       $a3, $a3, 0x260
    ctx->r7 = ADD32(ctx->r7, 0X260);
    after_10:
    // 0x800A7954: jal         0x8007C36C
    // 0x800A7958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_11;
    // 0x800A7958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A795C: jal         0x800662D8
    // 0x800A7960: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_12;
    // 0x800A7960: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x800A7964: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A7968: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A796C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7970: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7974: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7978: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A797C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A7980: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A7984: jal         0x800AAB5C
    // 0x800A7988: addiu       $a3, $a3, 0x280
    ctx->r7 = ADD32(ctx->r7, 0X280);
    hud_element_render(rdram, ctx);
        goto after_13;
    // 0x800A7988: addiu       $a3, $a3, 0x280
    ctx->r7 = ADD32(ctx->r7, 0X280);
    after_13:
    // 0x800A798C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A7994: jr          $ra
    // 0x800A7998: nop

    return;
    // 0x800A7998: nop

;}
RECOMP_FUNC void void_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025810: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80025814: lw          $t6, -0x316C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X316C);
    // 0x80025818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002581C: beq         $t6, $zero, L_8002584C
    if (ctx->r14 == 0) {
        // 0x80025820: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8002584C;
    }
    // 0x80025820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025824: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80025828: lw          $a0, -0x260C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X260C);
    // 0x8002582C: jal         0x80071380
    // 0x80025830: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x80025830: nop

    after_0:
    // 0x80025834: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80025838: lw          $a0, -0x316C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X316C);
    // 0x8002583C: jal         0x80071380
    // 0x80025840: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x80025840: nop

    after_1:
    // 0x80025844: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80025848: sw          $zero, -0x316C($at)
    MEM_W(-0X316C, ctx->r1) = 0;
L_8002584C:
    // 0x8002584C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025854: jr          $ra
    // 0x80025858: nop

    return;
    // 0x80025858: nop

;}
RECOMP_FUNC void coss_f(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A38: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070A3C: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070A40: jal         0x80070A6C
    // 0x80070A44: nop

    coss_s16(rdram, ctx);
        goto after_0;
    // 0x80070A44: nop

    after_0:
    // 0x80070A48: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070A4C: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x80070A50: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80070A54: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070A58: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070A5C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070A60: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80070A64: jr          $ra
    // 0x80070A68: nop

    return;
    // 0x80070A68: nop

;}
RECOMP_FUNC void obj_init_door(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B80C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003B810: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003B814: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003B818: lb          $a3, 0xC($a1)
    ctx->r7 = MEM_B(ctx->r5, 0XC);
    // 0x8003B81C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8003B820: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B824: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B828: bne         $a3, $at, L_8003B84C
    if (ctx->r7 != ctx->r1) {
        // 0x8003B82C: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8003B84C;
    }
    // 0x8003B82C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003B830: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8003B834: jal         0x8000CC20
    // 0x8003B838: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8000CC20(rdram, ctx);
        goto after_0;
    // 0x8003B838: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003B83C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B840: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003B844: b           L_8003B86C
    // 0x8003B848: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
        goto L_8003B86C;
    // 0x8003B848: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
L_8003B84C:
    // 0x8003B84C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B850: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8003B854: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8003B858: jal         0x8000CBF0
    // 0x8003B85C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_8000CBF0(rdram, ctx);
        goto after_1;
    // 0x8003B85C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003B860: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003B864: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B868: nop

L_8003B86C:
    // 0x8003B86C: lb          $t6, 0xC($a2)
    ctx->r14 = MEM_B(ctx->r6, 0XC);
    // 0x8003B870: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B874: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
    // 0x8003B878: lbu         $t7, 0xE($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0XE);
    // 0x8003B87C: lb          $t1, 0xE($v1)
    ctx->r9 = MEM_B(ctx->r3, 0XE);
    // 0x8003B880: sb          $t7, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r15;
    // 0x8003B884: lbu         $t8, 0xD($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XD);
    // 0x8003B888: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003B88C: sb          $t8, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r24;
    // 0x8003B890: lbu         $t9, 0xD($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XD);
    // 0x8003B894: addiu       $a0, $a0, 0x6544
    ctx->r4 = ADD32(ctx->r4, 0X6544);
    // 0x8003B898: sb          $t9, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r25;
    // 0x8003B89C: lbu         $t0, 0xB($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0XB);
    // 0x8003B8A0: bne         $t1, $at, L_8003B8C0
    if (ctx->r9 != ctx->r1) {
        // 0x8003B8A4: sb          $t0, 0x12($v1)
        MEM_B(0X12, ctx->r3) = ctx->r8;
            goto L_8003B8C0;
    }
    // 0x8003B8A4: sb          $t0, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r8;
    // 0x8003B8A8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8003B8AC: jal         0x800CA2B4
    // 0x8003B8B0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003B8B0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x8003B8B4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003B8B8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B8BC: nop

L_8003B8C0:
    // 0x8003B8C0: lbu         $t2, 0xA($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XA);
    // 0x8003B8C4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003B8C8: sb          $t2, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r10;
    // 0x8003B8CC: lbu         $t4, 0x8($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X8);
    // 0x8003B8D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003B8D4: sll         $t5, $t4, 10
    ctx->r13 = S32(ctx->r12 << 10);
    // 0x8003B8D8: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x8003B8DC: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8003B8E0: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8003B8E4: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8003B8E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B8EC: sw          $t6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r14;
    // 0x8003B8F0: lbu         $t7, 0x9($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X9);
    // 0x8003B8F4: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003B8F8: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8003B8FC: sll         $t9, $t8, 10
    ctx->r25 = S32(ctx->r24 << 10);
    // 0x8003B900: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x8003B904: lbu         $t1, 0x12($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X12);
    // 0x8003B908: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003B90C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8003B910: nop

    // 0x8003B914: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003B918: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B91C: nop

    // 0x8003B920: bc1f        L_8003B930
    if (!c1cs) {
        // 0x8003B924: nop
    
            goto L_8003B930;
    }
    // 0x8003B924: nop

    // 0x8003B928: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003B92C: nop

L_8003B930:
    // 0x8003B930: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003B934: lw          $t2, 0x40($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X40);
    // 0x8003B938: addiu       $t5, $zero, 0x21
    ctx->r13 = ADD32(0, 0X21);
    // 0x8003B93C: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8003B940: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003B944: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8003B948: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003B94C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8003B950: lbu         $t3, 0xF($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XF);
    // 0x8003B954: nop

    // 0x8003B958: sb          $t3, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r11;
    // 0x8003B95C: lb          $t4, 0x11($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X11);
    // 0x8003B960: nop

    // 0x8003B964: sb          $t4, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r12;
    // 0x8003B968: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B96C: nop

    // 0x8003B970: sh          $t5, 0x14($t6)
    MEM_H(0X14, ctx->r14) = ctx->r13;
    // 0x8003B974: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B978: nop

    // 0x8003B97C: sb          $t7, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r15;
    // 0x8003B980: lw          $t0, 0x4C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B984: nop

    // 0x8003B988: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003B98C: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B990: nop

    // 0x8003B994: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8003B998: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x8003B99C: lb          $t2, 0x3A($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X3A);
    // 0x8003B9A0: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x8003B9A4: nop

    // 0x8003B9A8: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003B9AC: bne         $at, $zero, L_8003B9BC
    if (ctx->r1 != 0) {
        // 0x8003B9B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003B9BC;
    }
    // 0x8003B9B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B9B4: sb          $zero, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = 0;
    // 0x8003B9B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003B9BC:
    // 0x8003B9BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003B9C0: jr          $ra
    // 0x8003B9C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003B9C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sound_volume_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000890: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80000894: lbu         $t7, 0x64F9($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X64F9);
    // 0x80000898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000089C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800008A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800008A4: bne         $t7, $zero, L_80000958
    if (ctx->r15 != 0) {
        // 0x800008A8: andi        $t6, $a0, 0xFF
        ctx->r14 = ctx->r4 & 0XFF;
            goto L_80000958;
    }
    // 0x800008A8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800008AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800008B0: addiu       $v0, $v0, 0x64F8
    ctx->r2 = ADD32(ctx->r2, 0X64F8);
    // 0x800008B4: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800008B8: bne         $t8, $zero, L_80000958
    if (ctx->r24 != 0) {
        // 0x800008BC: sb          $t6, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r14;
            goto L_80000958;
    }
    // 0x800008BC: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800008C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800008C4: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x800008C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800008CC: lbu         $a0, -0x3458($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3458);
    // 0x800008D0: jal         0x80001990
    // 0x800008D4: sw          $t9, -0x3424($at)
    MEM_W(-0X3424, ctx->r1) = ctx->r25;
    music_volume_set(rdram, ctx);
        goto after_0;
    // 0x800008D4: sw          $t9, -0x3424($at)
    MEM_W(-0X3424, ctx->r1) = ctx->r25;
    after_0:
    // 0x800008D8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800008DC: lw          $a1, -0x3424($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3424);
    // 0x800008E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800008E4: sll         $t0, $a1, 7
    ctx->r8 = S32(ctx->r5 << 7);
    // 0x800008E8: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x800008EC: andi        $t1, $a1, 0xFFFF
    ctx->r9 = ctx->r5 & 0XFFFF;
    // 0x800008F0: jal         0x80004A60
    // 0x800008F4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_1;
    // 0x800008F4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_1:
    // 0x800008F8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800008FC: lw          $a1, -0x3424($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3424);
    // 0x80000900: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000904: sll         $t2, $a1, 7
    ctx->r10 = S32(ctx->r5 << 7);
    // 0x80000908: addiu       $a1, $t2, -0x1
    ctx->r5 = ADD32(ctx->r10, -0X1);
    // 0x8000090C: andi        $t3, $a1, 0xFFFF
    ctx->r11 = ctx->r5 & 0XFFFF;
    // 0x80000910: jal         0x80004A60
    // 0x80000914: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_2;
    // 0x80000914: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x80000918: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000091C: lw          $a1, -0x3424($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3424);
    // 0x80000920: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000924: sll         $t4, $a1, 7
    ctx->r12 = S32(ctx->r5 << 7);
    // 0x80000928: addiu       $a1, $t4, -0x1
    ctx->r5 = ADD32(ctx->r12, -0X1);
    // 0x8000092C: andi        $t5, $a1, 0xFFFF
    ctx->r13 = ctx->r5 & 0XFFFF;
    // 0x80000930: jal         0x80004A60
    // 0x80000934: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_3;
    // 0x80000934: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_3:
    // 0x80000938: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000093C: lw          $a1, -0x3424($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3424);
    // 0x80000940: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000944: sll         $t6, $a1, 7
    ctx->r14 = S32(ctx->r5 << 7);
    // 0x80000948: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    // 0x8000094C: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x80000950: jal         0x80004A60
    // 0x80000954: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_4;
    // 0x80000954: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_4:
L_80000958:
    // 0x80000958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000095C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000960: jr          $ra
    // 0x80000964: nop

    return;
    // 0x80000964: nop

;}
RECOMP_FUNC void menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800819F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800819F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800819FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80081A00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80081A04: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80081A08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80081A0C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80081A10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081A14: sw          $t7, 0x693C($at)
    MEM_W(0X693C, ctx->r1) = ctx->r15;
    // 0x80081A18: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80081A1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081A20: sw          $t9, 0x6944($at)
    MEM_W(0X6944, ctx->r1) = ctx->r25;
    // 0x80081A24: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80081A28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081A2C: sw          $t1, 0x694C($at)
    MEM_W(0X694C, ctx->r1) = ctx->r9;
    // 0x80081A30: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80081A34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081A38: jal         0x8009C464
    // 0x80081A3C: sw          $t3, 0x6950($at)
    MEM_W(0X6950, ctx->r1) = ctx->r11;
    update_controller_sticks(rdram, ctx);
        goto after_0;
    // 0x80081A3C: sw          $t3, 0x6950($at)
    MEM_W(0X6950, ctx->r1) = ctx->r11;
    after_0:
    // 0x80081A40: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80081A44: lw          $t4, -0x610($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X610);
    // 0x80081A48: nop

    // 0x80081A4C: sltiu       $at, $t4, 0x1D
    ctx->r1 = ctx->r12 < 0X1D ? 1 : 0;
    // 0x80081A50: beq         $at, $zero, L_80081BFC
    if (ctx->r1 == 0) {
        // 0x80081A54: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80081BFC;
    }
    // 0x80081A54: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80081A58: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80081A5C: addu        $at, $at, $t4
    gpr jr_addend_80081A68 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80081A60: lw          $t4, -0x7778($at)
    ctx->r12 = ADD32(ctx->r1, -0X7778);
    // 0x80081A64: nop

    // 0x80081A68: jr          $t4
    // 0x80081A6C: nop

    switch (jr_addend_80081A68 >> 2) {
        case 0: goto L_80081A84; break;
        case 1: goto L_80081A70; break;
        case 2: goto L_80081BFC; break;
        case 3: goto L_80081AFC; break;
        case 4: goto L_80081BFC; break;
        case 5: goto L_80081B4C; break;
        case 6: goto L_80081B10; break;
        case 7: goto L_80081BFC; break;
        case 8: goto L_80081BFC; break;
        case 9: goto L_80081BFC; break;
        case 10: goto L_80081AD4; break;
        case 11: goto L_80081AE8; break;
        case 12: goto L_80081A98; break;
        case 13: goto L_80081AAC; break;
        case 14: goto L_80081AC0; break;
        case 15: goto L_80081B38; break;
        case 16: goto L_80081BFC; break;
        case 17: goto L_80081B60; break;
        case 18: goto L_80081BFC; break;
        case 19: goto L_80081B24; break;
        case 20: goto L_80081B74; break;
        case 21: goto L_80081B88; break;
        case 22: goto L_80081BFC; break;
        case 23: goto L_80081B9C; break;
        case 24: goto L_80081BB0; break;
        case 25: goto L_80081BC4; break;
        case 26: goto L_80081BD8; break;
        case 27: goto L_80081BFC; break;
        case 28: goto L_80081BEC; break;
        default: switch_error(__func__, 0x80081A68, 0x800E8888);
    }
    // 0x80081A6C: nop

L_80081A70:
    // 0x80081A70: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081A74: jal         0x80082FD4
    // 0x80081A78: nop

    menu_logo_screen_loop(rdram, ctx);
        goto after_1;
    // 0x80081A78: nop

    after_1:
    // 0x80081A7C: b           L_80081BFC
    // 0x80081A80: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081A80: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081A84:
    // 0x80081A84: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081A88: jal         0x80083E1C
    // 0x80081A8C: nop

    menu_title_screen_loop(rdram, ctx);
        goto after_2;
    // 0x80081A8C: nop

    after_2:
    // 0x80081A90: b           L_80081BFC
    // 0x80081A94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081A94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081A98:
    // 0x80081A98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081A9C: jal         0x80084794
    // 0x80081AA0: nop

    menu_options_loop(rdram, ctx);
        goto after_3;
    // 0x80081AA0: nop

    after_3:
    // 0x80081AA4: b           L_80081BFC
    // 0x80081AA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081AA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081AAC:
    // 0x80081AAC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081AB0: jal         0x800850AC
    // 0x80081AB4: nop

    menu_audio_options_loop(rdram, ctx);
        goto after_4;
    // 0x80081AB4: nop

    after_4:
    // 0x80081AB8: b           L_80081BFC
    // 0x80081ABC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081ABC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081AC0:
    // 0x80081AC0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081AC4: jal         0x80087FD0
    // 0x80081AC8: nop

    menu_save_options_loop(rdram, ctx);
        goto after_5;
    // 0x80081AC8: nop

    after_5:
    // 0x80081ACC: b           L_80081BFC
    // 0x80081AD0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081AD0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081AD4:
    // 0x80081AD4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081AD8: jal         0x8008A174
    // 0x80081ADC: nop

    menu_magic_codes_loop(rdram, ctx);
        goto after_6;
    // 0x80081ADC: nop

    after_6:
    // 0x80081AE0: b           L_80081BFC
    // 0x80081AE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081AE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081AE8:
    // 0x80081AE8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081AEC: jal         0x8008ADE0
    // 0x80081AF0: nop

    menu_magic_codes_list_loop(rdram, ctx);
        goto after_7;
    // 0x80081AF0: nop

    after_7:
    // 0x80081AF4: b           L_80081BFC
    // 0x80081AF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081AF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081AFC:
    // 0x80081AFC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B00: jal         0x8008C1DC
    // 0x80081B04: nop

    menu_character_select_loop(rdram, ctx);
        goto after_8;
    // 0x80081B04: nop

    after_8:
    // 0x80081B08: b           L_80081BFC
    // 0x80081B0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B10:
    // 0x80081B10: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B14: jal         0x8008E328
    // 0x80081B18: nop

    menu_file_select_loop(rdram, ctx);
        goto after_9;
    // 0x80081B18: nop

    after_9:
    // 0x80081B1C: b           L_80081BFC
    // 0x80081B20: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B20: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B24:
    // 0x80081B24: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B28: jal         0x8008CC74
    // 0x80081B2C: nop

    menu_game_select_loop(rdram, ctx);
        goto after_10;
    // 0x80081B2C: nop

    after_10:
    // 0x80081B30: b           L_80081BFC
    // 0x80081B34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B38:
    // 0x80081B38: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B3C: jal         0x8008F6EC
    // 0x80081B40: nop

    menu_track_select_loop(rdram, ctx);
        goto after_11;
    // 0x80081B40: nop

    after_11:
    // 0x80081B44: b           L_80081BFC
    // 0x80081B48: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B48: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B4C:
    // 0x80081B4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B50: jal         0x80093B04
    // 0x80081B54: nop

    menu_adventure_track_loop(rdram, ctx);
        goto after_12;
    // 0x80081B54: nop

    after_12:
    // 0x80081B58: b           L_80081BFC
    // 0x80081B5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B60:
    // 0x80081B60: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B64: jal         0x800977E4
    // 0x80081B68: nop

    menu_results_loop(rdram, ctx);
        goto after_13;
    // 0x80081B68: nop

    after_13:
    // 0x80081B6C: b           L_80081BFC
    // 0x80081B70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B74:
    // 0x80081B74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B78: jal         0x80098AD8
    // 0x80081B7C: nop

    menu_trophy_race_round_loop(rdram, ctx);
        goto after_14;
    // 0x80081B7C: nop

    after_14:
    // 0x80081B80: b           L_80081BFC
    // 0x80081B84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B88:
    // 0x80081B88: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081B8C: jal         0x80099510
    // 0x80081B90: nop

    menu_trophy_race_rankings_loop(rdram, ctx);
        goto after_15;
    // 0x80081B90: nop

    after_15:
    // 0x80081B94: b           L_80081BFC
    // 0x80081B98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081B98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081B9C:
    // 0x80081B9C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081BA0: jal         0x8009B238
    // 0x80081BA4: nop

    menu_cinematic_loop(rdram, ctx);
        goto after_16;
    // 0x80081BA4: nop

    after_16:
    // 0x80081BA8: b           L_80081BFC
    // 0x80081BAC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081BAC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081BB0:
    // 0x80081BB0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081BB4: jal         0x8009AD10
    // 0x80081BB8: nop

    menu_ghost_data_loop(rdram, ctx);
        goto after_17;
    // 0x80081BB8: nop

    after_17:
    // 0x80081BBC: b           L_80081BFC
    // 0x80081BC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081BC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081BC4:
    // 0x80081BC4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081BC8: jal         0x8009B870
    // 0x80081BCC: nop

    menu_credits_loop(rdram, ctx);
        goto after_18;
    // 0x80081BCC: nop

    after_18:
    // 0x80081BD0: b           L_80081BFC
    // 0x80081BD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081BD4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081BD8:
    // 0x80081BD8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081BDC: jal         0x80088A84
    // 0x80081BE0: nop

    menu_boot_loop(rdram, ctx);
        goto after_19;
    // 0x80081BE0: nop

    after_19:
    // 0x80081BE4: b           L_80081BFC
    // 0x80081BE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80081BFC;
    // 0x80081BE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081BEC:
    // 0x80081BEC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081BF0: jal         0x8008C8B4
    // 0x80081BF4: nop

    menu_caution_loop(rdram, ctx);
        goto after_20;
    // 0x80081BF4: nop

    after_20:
    // 0x80081BF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081BFC:
    // 0x80081BFC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80081C00: lw          $t5, 0x693C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X693C);
    // 0x80081C04: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80081C08: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80081C0C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80081C10: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80081C14: lw          $t7, 0x6944($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6944);
    // 0x80081C18: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80081C1C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80081C20: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80081C24: lw          $t9, 0x694C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X694C);
    // 0x80081C28: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80081C2C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80081C30: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80081C34: lw          $t1, 0x6950($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6950);
    // 0x80081C38: nop

    // 0x80081C3C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80081C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081C44: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80081C48: jr          $ra
    // 0x80081C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80081C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_enable_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFA8C: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x800AFA90: sll         $t7, $a1, 5
    ctx->r15 = S32(ctx->r5 << 5);
    // 0x800AFA94: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800AFA98: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x800AFA9C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800AFAA0: andi        $t8, $a2, 0x4000
    ctx->r24 = ctx->r6 & 0X4000;
    // 0x800AFAA4: beq         $t8, $zero, L_800AFAD0
    if (ctx->r24 == 0) {
        // 0x800AFAA8: sh          $zero, 0xA($v0)
        MEM_H(0XA, ctx->r2) = 0;
            goto L_800AFAD0;
    }
    // 0x800AFAA8: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x800AFAAC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800AFAB0: nop

    // 0x800AFAB4: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800AFAB8: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AFABC: nop

    // 0x800AFAC0: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800AFAC4: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AFAC8: b           L_800AFC10
    // 0x800AFACC: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
        goto L_800AFC10;
    // 0x800AFACC: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
L_800AFAD0:
    // 0x800AFAD0: andi        $t9, $a2, 0x400
    ctx->r25 = ctx->r6 & 0X400;
    // 0x800AFAD4: beq         $t9, $zero, L_800AFB98
    if (ctx->r25 == 0) {
        // 0x800AFAD8: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800AFB98;
    }
    // 0x800AFAD8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AFADC: lh          $t1, 0x8($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X8);
    // 0x800AFAE0: lw          $t0, 0x3280($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3280);
    // 0x800AFAE4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800AFAE8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800AFAEC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800AFAF0: lbu         $a1, 0x6($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X6);
    // 0x800AFAF4: lbu         $t5, 0x17($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X17);
    // 0x800AFAF8: nop

    // 0x800AFAFC: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800AFB00: blez        $a1, L_800AFB40
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800AFB04: sh          $t6, 0xA($v0)
        MEM_H(0XA, ctx->r2) = ctx->r14;
            goto L_800AFB40;
    }
    // 0x800AFB04: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800AFB08: blez        $a1, L_800AFB40
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800AFB0C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800AFB40;
    }
    // 0x800AFB0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AFB10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800AFB14:
    // 0x800AFB14: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800AFB18: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800AFB1C: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800AFB20: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x800AFB24: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800AFB28: sh          $zero, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = 0;
    // 0x800AFB2C: lbu         $t9, 0x6($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X6);
    // 0x800AFB30: nop

    // 0x800AFB34: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AFB38: bne         $at, $zero, L_800AFB14
    if (ctx->r1 != 0) {
        // 0x800AFB3C: nop
    
            goto L_800AFB14;
    }
    // 0x800AFB3C: nop

L_800AFB40:
    // 0x800AFB40: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AFB44: nop

    // 0x800AFB48: andi        $t1, $a1, 0x1
    ctx->r9 = ctx->r5 & 0X1;
    // 0x800AFB4C: beq         $t1, $zero, L_800AFB78
    if (ctx->r9 == 0) {
        // 0x800AFB50: andi        $t3, $a1, 0x4
        ctx->r11 = ctx->r5 & 0X4;
            goto L_800AFB78;
    }
    // 0x800AFB50: andi        $t3, $a1, 0x4
    ctx->r11 = ctx->r5 & 0X4;
    // 0x800AFB54: lh          $t0, 0x14($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X14);
    // 0x800AFB58: nop

    // 0x800AFB5C: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x800AFB60: lh          $t2, 0x16($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X16);
    // 0x800AFB64: nop

    // 0x800AFB68: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x800AFB6C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AFB70: nop

    // 0x800AFB74: andi        $t3, $a1, 0x4
    ctx->r11 = ctx->r5 & 0X4;
L_800AFB78:
    // 0x800AFB78: beq         $t3, $zero, L_800AFC10
    if (ctx->r11 == 0) {
        // 0x800AFB7C: nop
    
            goto L_800AFC10;
    }
    // 0x800AFB7C: nop

    // 0x800AFB80: lh          $t4, 0x22($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X22);
    // 0x800AFB84: nop

    // 0x800AFB88: sh          $t4, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r12;
    // 0x800AFB8C: lh          $t5, 0x24($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X24);
    // 0x800AFB90: b           L_800AFC10
    // 0x800AFB94: sh          $t5, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r13;
        goto L_800AFC10;
    // 0x800AFB94: sh          $t5, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r13;
L_800AFB98:
    // 0x800AFB98: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AFB9C: nop

    // 0x800AFBA0: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x800AFBA4: beq         $t6, $zero, L_800AFBE0
    if (ctx->r14 == 0) {
        // 0x800AFBA8: andi        $t1, $a1, 0x4
        ctx->r9 = ctx->r5 & 0X4;
            goto L_800AFBE0;
    }
    // 0x800AFBA8: andi        $t1, $a1, 0x4
    ctx->r9 = ctx->r5 & 0X4;
    // 0x800AFBAC: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x800AFBB0: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x800AFBB4: nop

    // 0x800AFBB8: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    // 0x800AFBBC: lh          $t8, 0x16($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X16);
    // 0x800AFBC0: nop

    // 0x800AFBC4: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x800AFBC8: lh          $t9, 0x18($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X18);
    // 0x800AFBCC: nop

    // 0x800AFBD0: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    // 0x800AFBD4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AFBD8: nop

    // 0x800AFBDC: andi        $t1, $a1, 0x4
    ctx->r9 = ctx->r5 & 0X4;
L_800AFBE0:
    // 0x800AFBE0: beq         $t1, $zero, L_800AFC10
    if (ctx->r9 == 0) {
        // 0x800AFBE4: nop
    
            goto L_800AFC10;
    }
    // 0x800AFBE4: nop

    // 0x800AFBE8: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // 0x800AFBEC: lh          $t0, 0x22($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X22);
    // 0x800AFBF0: nop

    // 0x800AFBF4: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x800AFBF8: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    // 0x800AFBFC: nop

    // 0x800AFC00: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
    // 0x800AFC04: lh          $t3, 0x26($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X26);
    // 0x800AFC08: nop

    // 0x800AFC0C: sh          $t3, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r11;
L_800AFC10:
    // 0x800AFC10: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x800AFC14: nop

    // 0x800AFC18: andi        $t5, $t4, 0xFDFF
    ctx->r13 = ctx->r12 & 0XFDFF;
    // 0x800AFC1C: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x800AFC20: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800AFC24: nop

    // 0x800AFC28: ori         $t7, $t6, 0xA000
    ctx->r15 = ctx->r14 | 0XA000;
    // 0x800AFC2C: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x800AFC30: lh          $t8, 0x1A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X1A);
    // 0x800AFC34: nop

    // 0x800AFC38: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800AFC3C: jr          $ra
    // 0x800AFC40: sh          $t9, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r25;
    return;
    // 0x800AFC40: sh          $t9, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void rumble_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072964: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80072968: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007296C: lw          $t6, -0x1600($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1600);
    // 0x80072970: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80072974: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80072978: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8007297C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80072980: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80072984: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80072988: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8007298C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80072990: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80072994: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80072998: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8007299C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800729A0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800729A4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800729A8: beq         $t6, $zero, L_80072E6C
    if (ctx->r14 == 0) {
        // 0x800729AC: sw          $a0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r4;
            goto L_80072E6C;
    }
    // 0x800729AC: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x800729B0: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x800729B4: addiu       $fp, $fp, 0x4766
    ctx->r30 = ADD32(ctx->r30, 0X4766);
    // 0x800729B8: lbu         $t7, 0x0($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X0);
    // 0x800729BC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800729C0: bne         $t7, $zero, L_800729D4
    if (ctx->r15 != 0) {
        // 0x800729C4: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800729D4;
    }
    // 0x800729C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800729C8: lw          $t8, -0x1604($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1604);
    // 0x800729CC: nop

    // 0x800729D0: beq         $t8, $zero, L_80072E6C
    if (ctx->r24 == 0) {
        // 0x800729D4: addiu       $v0, $v0, 0x4768
        ctx->r2 = ADD32(ctx->r2, 0X4768);
            goto L_80072E6C;
    }
L_800729D4:
    // 0x800729D4: addiu       $v0, $v0, 0x4768
    ctx->r2 = ADD32(ctx->r2, 0X4768);
    // 0x800729D8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800729DC: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x800729E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800729E4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800729E8: slti        $at, $t1, 0x79
    ctx->r1 = SIGNED(ctx->r9) < 0X79 ? 1 : 0;
    // 0x800729EC: bne         $at, $zero, L_80072ADC
    if (ctx->r1 != 0) {
        // 0x800729F0: sw          $t1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r9;
            goto L_80072ADC;
    }
    // 0x800729F0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800729F4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800729F8: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x800729FC: jal         0x800CD7F0
    // 0x80072A00: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_0;
    // 0x80072A00: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    after_0:
    // 0x80072A04: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80072A08: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80072A0C: addiu       $s4, $s4, 0x4767
    ctx->r20 = ADD32(ctx->r20, 0X4767);
    // 0x80072A10: addiu       $s6, $s6, 0x4598
    ctx->r22 = ADD32(ctx->r22, 0X4598);
    // 0x80072A14: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80072A18: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80072A1C: addiu       $s7, $zero, 0x68
    ctx->r23 = ADD32(0, 0X68);
L_80072A20:
    // 0x80072A20: lbu         $t3, 0x6D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X6D);
    // 0x80072A24: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80072A28: and         $t4, $t3, $v1
    ctx->r12 = ctx->r11 & ctx->r3;
    // 0x80072A2C: beq         $t4, $zero, L_80072ABC
    if (ctx->r12 == 0) {
        // 0x80072A30: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80072ABC;
    }
    // 0x80072A30: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80072A34: lbu         $t5, 0x0($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0X0);
    // 0x80072A38: lbu         $t7, 0x4765($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4765);
    // 0x80072A3C: nor         $t6, $t5, $zero
    ctx->r14 = ~(ctx->r13 | 0);
    // 0x80072A40: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80072A44: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x80072A48: bne         $t9, $zero, L_80072ABC
    if (ctx->r25 != 0) {
        // 0x80072A4C: nop
    
            goto L_80072ABC;
    }
    // 0x80072A4C: nop

    // 0x80072A50: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072A54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072A58: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x80072A5C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80072A60: mflo        $t0
    ctx->r8 = lo;
    // 0x80072A64: addu        $a1, $s6, $t0
    ctx->r5 = ADD32(ctx->r22, ctx->r8);
    // 0x80072A68: jal         0x8007231C
    // 0x80072A6C: nop

    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x80072A6C: nop

    after_1:
    // 0x80072A70: beq         $v0, $zero, L_80072AAC
    if (ctx->r2 == 0) {
        // 0x80072A74: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80072AAC;
    }
    // 0x80072A74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80072A78: lbu         $t1, 0x0($fp)
    ctx->r9 = MEM_BU(ctx->r30, 0X0);
    // 0x80072A7C: lbu         $t3, 0x0($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X0);
    // 0x80072A80: nor         $v0, $s1, $zero
    ctx->r2 = ~(ctx->r17 | 0);
    // 0x80072A84: and         $t2, $t1, $v0
    ctx->r10 = ctx->r9 & ctx->r2;
    // 0x80072A88: and         $t4, $t3, $v0
    ctx->r12 = ctx->r11 & ctx->r2;
    // 0x80072A8C: sb          $t2, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r10;
    // 0x80072A90: sb          $t4, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r12;
    // 0x80072A94: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80072A98: lbu         $t5, 0x4765($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X4765);
    // 0x80072A9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072AA0: and         $t6, $t5, $v0
    ctx->r14 = ctx->r13 & ctx->r2;
    // 0x80072AA4: b           L_80072ABC
    // 0x80072AA8: sb          $t6, 0x4765($at)
    MEM_B(0X4765, ctx->r1) = ctx->r14;
        goto L_80072ABC;
    // 0x80072AA8: sb          $t6, 0x4765($at)
    MEM_B(0X4765, ctx->r1) = ctx->r14;
L_80072AAC:
    // 0x80072AAC: lbu         $t7, 0x4765($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4765);
    // 0x80072AB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072AB4: or          $t8, $t7, $s1
    ctx->r24 = ctx->r15 | ctx->r17;
    // 0x80072AB8: sb          $t8, 0x4765($at)
    MEM_B(0X4765, ctx->r1) = ctx->r24;
L_80072ABC:
    // 0x80072ABC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80072AC0: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x80072AC4: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x80072AC8: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x80072ACC: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80072AD0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80072AD4: bne         $at, $zero, L_80072A20
    if (ctx->r1 != 0) {
        // 0x80072AD8: or          $s3, $t9, $zero
        ctx->r19 = ctx->r25 | 0;
            goto L_80072A20;
    }
    // 0x80072AD8: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
L_80072ADC:
    // 0x80072ADC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072AE0: lbu         $t1, 0x4765($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X4765);
    // 0x80072AE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072AE8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80072AEC: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80072AF0: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072AF4: addiu       $s6, $s6, 0x4598
    ctx->r22 = ADD32(ctx->r22, 0X4598);
    // 0x80072AF8: addiu       $s4, $s4, 0x4767
    ctx->r20 = ADD32(ctx->r20, 0X4767);
    // 0x80072AFC: bne         $t1, $zero, L_80072B0C
    if (ctx->r9 != 0) {
        // 0x80072B00: addiu       $s7, $zero, 0x68
        ctx->r23 = ADD32(0, 0X68);
            goto L_80072B0C;
    }
    // 0x80072B00: addiu       $s7, $zero, 0x68
    ctx->r23 = ADD32(0, 0X68);
    // 0x80072B04: beq         $a0, $zero, L_80072E70
    if (ctx->r4 == 0) {
        // 0x80072B08: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80072E70;
    }
    // 0x80072B08: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80072B0C:
    // 0x80072B0C: beq         $a0, $zero, L_80072B30
    if (ctx->r4 == 0) {
        // 0x80072B10: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80072B30;
    }
    // 0x80072B10: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80072B14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072B18: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x80072B1C: jal         0x800CD7F0
    // 0x80072B20: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_2;
    // 0x80072B20: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    after_2:
    // 0x80072B24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072B28: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072B2C: nop

L_80072B30:
    // 0x80072B30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80072B34: lwc1        $f23, 0x7D78($at)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r1, 0X7D78);
    // 0x80072B38: lwc1        $f22, 0x7D7C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7D7C);
    // 0x80072B3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80072B40: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80072B44: lwc1        $f21, 0x7D80($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X7D80);
    // 0x80072B48: lwc1        $f20, 0x7D84($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7D84);
    // 0x80072B4C: addiu       $s0, $s0, 0x4738
    ctx->r16 = ADD32(ctx->r16, 0X4738);
    // 0x80072B50: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80072B54: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80072B58:
    // 0x80072B58: beq         $a0, $zero, L_80072BD8
    if (ctx->r4 == 0) {
        // 0x80072B5C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80072BD8;
    }
    // 0x80072B5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80072B60: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80072B64: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    // 0x80072B68: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x80072B6C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80072B70: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x80072B74: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80072B78: lbu         $t3, 0x6D($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X6D);
    // 0x80072B7C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072B80: and         $t4, $t3, $v1
    ctx->r12 = ctx->r11 & ctx->r3;
    // 0x80072B84: bne         $t4, $zero, L_80072B98
    if (ctx->r12 != 0) {
        // 0x80072B88: nop
    
            goto L_80072B98;
    }
    // 0x80072B88: nop

    // 0x80072B8C: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072B90: b           L_80072E30
    // 0x80072B94: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072E30;
    // 0x80072B94: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072B98:
    // 0x80072B98: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072B9C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072BA0: lw          $a0, 0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4590);
    // 0x80072BA4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80072BA8: mflo        $t5
    ctx->r13 = lo;
    // 0x80072BAC: addu        $s2, $s6, $t5
    ctx->r18 = ADD32(ctx->r22, ctx->r13);
    // 0x80072BB0: jal         0x8007231C
    // 0x80072BB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_3;
    // 0x80072BB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80072BB8: bne         $v0, $zero, L_80072BC8
    if (ctx->r2 != 0) {
        // 0x80072BBC: nop
    
            goto L_80072BC8;
    }
    // 0x80072BBC: nop

    // 0x80072BC0: jal         0x80071F70
    // 0x80072BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    osMotorStop_recomp(rdram, ctx);
        goto after_4;
    // 0x80072BC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
L_80072BC8:
    // 0x80072BC8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072BCC: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072BD0: b           L_80072E30
    // 0x80072BD4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072E30;
    // 0x80072BD4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072BD8:
    // 0x80072BD8: lbu         $v0, 0x0($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X0);
    // 0x80072BDC: lbu         $t6, 0x4765($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4765);
    // 0x80072BE0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80072BE4: and         $t7, $v0, $t6
    ctx->r15 = ctx->r2 & ctx->r14;
    // 0x80072BE8: and         $t8, $t7, $v1
    ctx->r24 = ctx->r15 & ctx->r3;
    // 0x80072BEC: beq         $t8, $zero, L_80072E2C
    if (ctx->r24 == 0) {
        // 0x80072BF0: nop
    
            goto L_80072E2C;
    }
    // 0x80072BF0: nop

    // 0x80072BF4: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
    // 0x80072BF8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80072BFC: bgtz        $v1, L_80072C40
    if (SIGNED(ctx->r3) > 0) {
        // 0x80072C00: subu        $t4, $v1, $t3
        ctx->r12 = SUB32(ctx->r3, ctx->r11);
            goto L_80072C40;
    }
    // 0x80072C00: subu        $t4, $v1, $t3
    ctx->r12 = SUB32(ctx->r3, ctx->r11);
    // 0x80072C04: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072C08: nor         $t9, $s1, $zero
    ctx->r25 = ~(ctx->r17 | 0);
    // 0x80072C0C: and         $t0, $v0, $t9
    ctx->r8 = ctx->r2 & ctx->r25;
    // 0x80072C10: sb          $t0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r8;
    // 0x80072C14: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80072C18: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80072C1C: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80072C20: mflo        $t2
    ctx->r10 = lo;
    // 0x80072C24: addu        $a0, $s6, $t2
    ctx->r4 = ADD32(ctx->r22, ctx->r10);
    // 0x80072C28: jal         0x80071F70
    // 0x80072C2C: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_5;
    // 0x80072C2C: nop

    after_5:
    // 0x80072C30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072C34: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072C38: b           L_80072E30
    // 0x80072C3C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072E30;
    // 0x80072C3C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072C40:
    // 0x80072C40: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x80072C44: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80072C48: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x80072C4C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072C50: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80072C54: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x80072C58: lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8);
    // 0x80072C5C: nop

    // 0x80072C60: bgez        $v0, L_80072C74
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80072C64: slti        $at, $v0, 0x259
        ctx->r1 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
            goto L_80072C74;
    }
    // 0x80072C64: slti        $at, $v0, 0x259
    ctx->r1 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
    // 0x80072C68: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072C6C: b           L_80072E30
    // 0x80072C70: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072E30;
    // 0x80072C70: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072C74:
    // 0x80072C74: bne         $at, $zero, L_80072CC0
    if (ctx->r1 != 0) {
        // 0x80072C78: nop
    
            goto L_80072CC0;
    }
    // 0x80072C78: nop

    // 0x80072C7C: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072C80: lbu         $t8, 0x0($fp)
    ctx->r24 = MEM_BU(ctx->r30, 0X0);
    // 0x80072C84: nor         $t9, $s1, $zero
    ctx->r25 = ~(ctx->r17 | 0);
    // 0x80072C88: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80072C8C: sb          $t0, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r8;
    // 0x80072C90: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80072C94: addiu       $t2, $zero, -0x12C
    ctx->r10 = ADD32(0, -0X12C);
    // 0x80072C98: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80072C9C: sh          $t2, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r10;
    // 0x80072CA0: mflo        $t3
    ctx->r11 = lo;
    // 0x80072CA4: addu        $a0, $s6, $t3
    ctx->r4 = ADD32(ctx->r22, ctx->r11);
    // 0x80072CA8: jal         0x80071F70
    // 0x80072CAC: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_6;
    // 0x80072CAC: nop

    after_6:
    // 0x80072CB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072CB4: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072CB8: b           L_80072E30
    // 0x80072CBC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072E30;
    // 0x80072CBC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072CC0:
    // 0x80072CC0: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80072CC4: nop

    // 0x80072CC8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80072CCC: nop

    // 0x80072CD0: cvt.d.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.d = CVT_D_W(ctx->f4.u32l);
    // 0x80072CD4: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x80072CD8: nop

    // 0x80072CDC: bc1f        L_80072D20
    if (!c1cs) {
        // 0x80072CE0: nop
    
            goto L_80072D20;
    }
    // 0x80072CE0: nop

    // 0x80072CE4: lbu         $t4, 0x0($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X0);
    // 0x80072CE8: nop

    // 0x80072CEC: and         $t5, $t4, $s1
    ctx->r13 = ctx->r12 & ctx->r17;
    // 0x80072CF0: bne         $t5, $zero, L_80072E20
    if (ctx->r13 != 0) {
        // 0x80072CF4: nop
    
            goto L_80072E20;
    }
    // 0x80072CF4: nop

    // 0x80072CF8: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072CFC: mflo        $t6
    ctx->r14 = lo;
    // 0x80072D00: addu        $a0, $s6, $t6
    ctx->r4 = ADD32(ctx->r22, ctx->r14);
    // 0x80072D04: jal         0x80072098
    // 0x80072D08: nop

    osMotorStart_recomp(rdram, ctx);
        goto after_7;
    // 0x80072D08: nop

    after_7:
    // 0x80072D0C: lbu         $t7, 0x0($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X0);
    // 0x80072D10: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072D14: or          $t8, $t7, $s1
    ctx->r24 = ctx->r15 | ctx->r17;
    // 0x80072D18: b           L_80072E20
    // 0x80072D1C: sb          $t8, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r24;
        goto L_80072E20;
    // 0x80072D1C: sb          $t8, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r24;
L_80072D20:
    // 0x80072D20: c.lt.d      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.d < ctx->f22.d;
    // 0x80072D24: nop

    // 0x80072D28: bc1f        L_80072D70
    if (!c1cs) {
        // 0x80072D2C: nop
    
            goto L_80072D70;
    }
    // 0x80072D2C: nop

    // 0x80072D30: lbu         $t9, 0x0($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X0);
    // 0x80072D34: nop

    // 0x80072D38: and         $t0, $t9, $s1
    ctx->r8 = ctx->r25 & ctx->r17;
    // 0x80072D3C: beq         $t0, $zero, L_80072E20
    if (ctx->r8 == 0) {
        // 0x80072D40: nop
    
            goto L_80072E20;
    }
    // 0x80072D40: nop

    // 0x80072D44: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072D48: mflo        $t1
    ctx->r9 = lo;
    // 0x80072D4C: addu        $a0, $s6, $t1
    ctx->r4 = ADD32(ctx->r22, ctx->r9);
    // 0x80072D50: jal         0x80071F70
    // 0x80072D54: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_8;
    // 0x80072D54: nop

    after_8:
    // 0x80072D58: lbu         $t2, 0x0($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X0);
    // 0x80072D5C: nor         $t3, $s1, $zero
    ctx->r11 = ~(ctx->r17 | 0);
    // 0x80072D60: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x80072D64: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072D68: b           L_80072E20
    // 0x80072D6C: sb          $t4, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r12;
        goto L_80072E20;
    // 0x80072D6C: sb          $t4, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r12;
L_80072D70:
    // 0x80072D70: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80072D74: nop

    // 0x80072D78: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80072D7C: bne         $at, $zero, L_80072DD0
    if (ctx->r1 != 0) {
        // 0x80072D80: nop
    
            goto L_80072DD0;
    }
    // 0x80072D80: nop

    // 0x80072D84: lbu         $t5, 0x0($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X0);
    // 0x80072D88: nop

    // 0x80072D8C: and         $t6, $t5, $s1
    ctx->r14 = ctx->r13 & ctx->r17;
    // 0x80072D90: bne         $t6, $zero, L_80072DC8
    if (ctx->r14 != 0) {
        // 0x80072D94: addiu       $t0, $v1, -0x100
        ctx->r8 = ADD32(ctx->r3, -0X100);
            goto L_80072DC8;
    }
    // 0x80072D94: addiu       $t0, $v1, -0x100
    ctx->r8 = ADD32(ctx->r3, -0X100);
    // 0x80072D98: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072D9C: mflo        $t7
    ctx->r15 = lo;
    // 0x80072DA0: addu        $a0, $s6, $t7
    ctx->r4 = ADD32(ctx->r22, ctx->r15);
    // 0x80072DA4: jal         0x80072098
    // 0x80072DA8: nop

    osMotorStart_recomp(rdram, ctx);
        goto after_9;
    // 0x80072DA8: nop

    after_9:
    // 0x80072DAC: lbu         $t8, 0x0($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X0);
    // 0x80072DB0: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072DB4: or          $t9, $t8, $s1
    ctx->r25 = ctx->r24 | ctx->r17;
    // 0x80072DB8: sb          $t9, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r25;
    // 0x80072DBC: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80072DC0: nop

    // 0x80072DC4: addiu       $t0, $v1, -0x100
    ctx->r8 = ADD32(ctx->r3, -0X100);
L_80072DC8:
    // 0x80072DC8: b           L_80072E20
    // 0x80072DCC: sh          $t0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r8;
        goto L_80072E20;
    // 0x80072DCC: sh          $t0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r8;
L_80072DD0:
    // 0x80072DD0: lbu         $t1, 0x0($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X0);
    // 0x80072DD4: nop

    // 0x80072DD8: and         $t2, $t1, $s1
    ctx->r10 = ctx->r9 & ctx->r17;
    // 0x80072DDC: beq         $t2, $zero, L_80072E18
    if (ctx->r10 == 0) {
        // 0x80072DE0: addu        $t7, $v1, $a0
        ctx->r15 = ADD32(ctx->r3, ctx->r4);
            goto L_80072E18;
    }
    // 0x80072DE0: addu        $t7, $v1, $a0
    ctx->r15 = ADD32(ctx->r3, ctx->r4);
    // 0x80072DE4: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072DE8: mflo        $t3
    ctx->r11 = lo;
    // 0x80072DEC: addu        $a0, $s6, $t3
    ctx->r4 = ADD32(ctx->r22, ctx->r11);
    // 0x80072DF0: jal         0x80071F70
    // 0x80072DF4: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_10;
    // 0x80072DF4: nop

    after_10:
    // 0x80072DF8: lbu         $t4, 0x0($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X0);
    // 0x80072DFC: nor         $t5, $s1, $zero
    ctx->r13 = ~(ctx->r17 | 0);
    // 0x80072E00: and         $t6, $t4, $t5
    ctx->r14 = ctx->r12 & ctx->r13;
    // 0x80072E04: sb          $t6, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r14;
    // 0x80072E08: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80072E0C: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80072E10: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072E14: addu        $t7, $v1, $a0
    ctx->r15 = ADD32(ctx->r3, ctx->r4);
L_80072E18:
    // 0x80072E18: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80072E1C: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_80072E20:
    // 0x80072E20: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072E24: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x80072E28: nop

L_80072E2C:
    // 0x80072E2C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072E30:
    // 0x80072E30: andi        $t9, $s3, 0xFF
    ctx->r25 = ctx->r19 & 0XFF;
    // 0x80072E34: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x80072E38: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x80072E3C: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80072E40: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80072E44: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80072E48: bne         $at, $zero, L_80072B58
    if (ctx->r1 != 0) {
        // 0x80072E4C: addiu       $s0, $s0, 0xA
        ctx->r16 = ADD32(ctx->r16, 0XA);
            goto L_80072B58;
    }
    // 0x80072E4C: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x80072E50: beq         $s5, $zero, L_80072E5C
    if (ctx->r21 == 0) {
        // 0x80072E54: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80072E5C;
    }
    // 0x80072E54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072E58: sb          $zero, 0x4765($at)
    MEM_B(0X4765, ctx->r1) = 0;
L_80072E5C:
    // 0x80072E5C: beq         $a0, $zero, L_80072E6C
    if (ctx->r4 == 0) {
        // 0x80072E60: addiu       $t1, $a0, -0x1
        ctx->r9 = ADD32(ctx->r4, -0X1);
            goto L_80072E6C;
    }
    // 0x80072E60: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x80072E64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80072E68: sw          $t1, -0x1604($at)
    MEM_W(-0X1604, ctx->r1) = ctx->r9;
L_80072E6C:
    // 0x80072E6C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80072E70:
    // 0x80072E70: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80072E74: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80072E78: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80072E7C: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80072E80: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80072E84: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80072E88: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80072E8C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80072E90: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80072E94: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80072E98: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80072E9C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80072EA0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80072EA4: jr          $ra
    // 0x80072EA8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80072EA8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void menu_magic_codes_list_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A998: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A99C: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008A9A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A9A4: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008A9A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A9AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A9B0: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8008A9B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A9B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A9BC: sh          $zero, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = 0;
    // 0x8008A9C0: jal         0x800C46D0
    // 0x8008A9C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_0;
    // 0x8008A9C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008A9C8: jal         0x8009CC18
    // 0x8008A9CC: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    menu_asset_load(rdram, ctx);
        goto after_1;
    // 0x8008A9CC: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_1:
    // 0x8008A9D0: jal         0x8008E968
    // 0x8008A9D4: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_2;
    // 0x8008A9D4: nop

    after_2:
    // 0x8008A9D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008A9DC: jal         0x800C06F8
    // 0x8008A9E0: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8008A9E0: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_3:
    // 0x8008A9E4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8008A9E8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8008A9EC: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8008A9F0: bne         $t6, $zero, L_8008AA08
    if (ctx->r14 != 0) {
        // 0x8008A9F4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008AA08;
    }
    // 0x8008A9F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A9F8: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8008A9FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008AA00: b           L_8008AA0C
    // 0x8008AA04: sw          $t7, 0x7234($at)
    MEM_W(0X7234, ctx->r1) = ctx->r15;
        goto L_8008AA0C;
    // 0x8008AA04: sw          $t7, 0x7234($at)
    MEM_W(0X7234, ctx->r1) = ctx->r15;
L_8008AA08:
    // 0x8008AA08: sw          $t8, 0x7234($at)
    MEM_W(0X7234, ctx->r1) = ctx->r24;
L_8008AA0C:
    // 0x8008AA0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008AA10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008AA14: jr          $ra
    // 0x8008AA18: nop

    return;
    // 0x8008AA18: nop

;}
RECOMP_FUNC void set_taj_status(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800521F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800521FC: jr          $ra
    // 0x80052200: sb          $a0, -0x24FE($at)
    MEM_B(-0X24FE, ctx->r1) = ctx->r4;
    return;
    // 0x80052200: sb          $a0, -0x24FE($at)
    MEM_B(-0X24FE, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void music_change_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000B1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000B20: jr          $ra
    // 0x80000B24: sw          $t6, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = ctx->r14;
    return;
    // 0x80000B24: sw          $t6, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void menu_controller_pak_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089540: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80089544: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x80089548: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008954C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80089550: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x80089554: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80089558: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008955C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80089560: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80089564: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80089568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008956C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80089570: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80089574: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80089578: beq         $at, $zero, L_8008959C
    if (ctx->r1 == 0) {
        // 0x8008957C: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008959C;
    }
    // 0x8008957C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80089580: jal         0x80088DB8
    // 0x80089584: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    pakmenu_render(rdram, ctx);
        goto after_0;
    // 0x80089584: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80089588: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008958C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80089590: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x80089594: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80089598: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_8008959C:
    // 0x8008959C: bne         $v0, $zero, L_800899FC
    if (ctx->r2 != 0) {
        // 0x800895A0: addu        $t4, $v0, $a0
        ctx->r12 = ADD32(ctx->r2, ctx->r4);
            goto L_800899FC;
    }
    // 0x800895A0: addu        $t4, $v0, $a0
    ctx->r12 = ADD32(ctx->r2, ctx->r4);
    // 0x800895A4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800895A8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800895AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800895B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800895B4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800895B8: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x800895BC: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
    // 0x800895C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800895C4:
    // 0x800895C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800895C8: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    // 0x800895CC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x800895D0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800895D4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800895D8: jal         0x8006A794
    // 0x800895DC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x800895DC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x800895E0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800895E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800895E8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800895EC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800895F0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800895F4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800895F8: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x800895FC: lb          $t4, 0x0($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X0);
    // 0x80089600: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089604: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80089608: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008960C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80089610: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x80089614: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x80089618: bne         $a0, $at, L_800895C4
    if (ctx->r4 != ctx->r1) {
        // 0x8008961C: addu        $t0, $t0, $t4
        ctx->r8 = ADD32(ctx->r8, ctx->r12);
            goto L_800895C4;
    }
    // 0x8008961C: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80089620: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089624: lw          $v0, 0x7188($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7188);
    // 0x80089628: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008962C: beq         $v0, $zero, L_800896C8
    if (ctx->r2 == 0) {
        // 0x80089630: addiu       $t2, $t2, 0x6980
        ctx->r10 = ADD32(ctx->r10, 0X6980);
            goto L_800896C8;
    }
    // 0x80089630: addiu       $t2, $t2, 0x6980
    ctx->r10 = ADD32(ctx->r10, 0X6980);
    // 0x80089634: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089638: beq         $v0, $at, L_800899A4
    if (ctx->r2 == ctx->r1) {
        // 0x8008963C: andi        $t5, $a2, 0x9000
        ctx->r13 = ctx->r6 & 0X9000;
            goto L_800899A4;
    }
    // 0x8008963C: andi        $t5, $a2, 0x9000
    ctx->r13 = ctx->r6 & 0X9000;
    // 0x80089640: beq         $t5, $zero, L_800899A4
    if (ctx->r13 == 0) {
        // 0x80089644: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_800899A4;
    }
    // 0x80089644: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80089648: jal         0x80001D04
    // 0x8008964C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008964C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80089650: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089654: addiu       $a0, $a0, 0x7028
    ctx->r4 = ADD32(ctx->r4, 0X7028);
    // 0x80089658: jal         0x8008838C
    // 0x8008965C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80087F14(rdram, ctx);
        goto after_3;
    // 0x8008965C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80089660: bne         $v0, $zero, L_80089670
    if (ctx->r2 != 0) {
        // 0x80089664: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80089670;
    }
    // 0x80089664: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089668: b           L_80089684
    // 0x8008966C: sw          $zero, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = 0;
        goto L_80089684;
    // 0x8008966C: sw          $zero, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = 0;
L_80089670:
    // 0x80089670: jal         0x800887A4
    // 0x80089674: nop

    check_for_controller_pak_errors(rdram, ctx);
        goto after_4;
    // 0x80089674: nop

    after_4:
    // 0x80089678: bne         $v0, $zero, L_80089684
    if (ctx->r2 != 0) {
        // 0x8008967C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80089684;
    }
    // 0x8008967C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089680: sw          $zero, 0x314($at)
    MEM_W(0X314, ctx->r1) = 0;
L_80089684:
    // 0x80089684: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80089688: lw          $t6, 0x7188($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7188);
    // 0x8008968C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80089690: bne         $t6, $zero, L_800899A4
    if (ctx->r14 != 0) {
        // 0x80089694: nop
    
            goto L_800899A4;
    }
    // 0x80089694: nop

    // 0x80089698: lw          $t7, 0x314($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X314);
    // 0x8008969C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800896A0: bne         $t7, $zero, L_800899A4
    if (ctx->r15 != 0) {
        // 0x800896A4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800899A4;
    }
    // 0x800896A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800896A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800896AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800896B0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x800896B4: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
    // 0x800896B8: jal         0x800C06F8
    // 0x800896BC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_5;
    // 0x800896BC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_5:
    // 0x800896C0: b           L_800899A8
    // 0x800896C4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
        goto L_800899A8;
    // 0x800896C4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_800896C8:
    // 0x800896C8: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800896CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800896D0: beq         $v0, $zero, L_80089818
    if (ctx->r2 == 0) {
        // 0x800896D4: andi        $t8, $a2, 0x4000
        ctx->r24 = ctx->r6 & 0X4000;
            goto L_80089818;
    }
    // 0x800896D4: andi        $t8, $a2, 0x4000
    ctx->r24 = ctx->r6 & 0X4000;
    // 0x800896D8: addiu       $a0, $a0, 0x71D0
    ctx->r4 = ADD32(ctx->r4, 0X71D0);
    // 0x800896DC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800896E0: andi        $t5, $a2, 0x4000
    ctx->r13 = ctx->r6 & 0X4000;
    // 0x800896E4: beq         $v1, $zero, L_80089798
    if (ctx->r3 == 0) {
        // 0x800896E8: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_80089798;
    }
    // 0x800896E8: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x800896EC: bne         $t4, $zero, L_800899A4
    if (ctx->r12 != 0) {
        // 0x800896F0: sw          $t4, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r12;
            goto L_800899A4;
    }
    // 0x800896F0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800896F4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800896F8: addiu       $t1, $t1, -0x620
    ctx->r9 = ADD32(ctx->r9, -0X620);
    // 0x800896FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089700: lw          $a0, 0x7028($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7028);
    // 0x80089704: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80089708: jal         0x80076520
    // 0x8008970C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    delete_file(rdram, ctx);
        goto after_6;
    // 0x8008970C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80089710: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80089714: beq         $v0, $zero, L_80089748
    if (ctx->r2 == 0) {
        // 0x80089718: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80089748;
    }
    // 0x80089718: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008971C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80089720: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089724: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089728: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008972C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80089730: sw          $t7, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r15;
    // 0x80089734: jal         0x800C06F8
    // 0x80089738: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_7;
    // 0x80089738: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_7:
    // 0x8008973C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80089740: b           L_80089790
    // 0x80089744: addiu       $t2, $t2, 0x6980
    ctx->r10 = ADD32(ctx->r10, 0X6980);
        goto L_80089790;
    // 0x80089744: addiu       $t2, $t2, 0x6980
    ctx->r10 = ADD32(ctx->r10, 0X6980);
L_80089748:
    // 0x80089748: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008974C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80089750: addiu       $a0, $a0, 0x7028
    ctx->r4 = ADD32(ctx->r4, 0X7028);
    // 0x80089754: jal         0x8008838C
    // 0x80089758: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80087F14(rdram, ctx);
        goto after_8;
    // 0x80089758: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
    // 0x8008975C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80089760: beq         $v0, $zero, L_80089790
    if (ctx->r2 == 0) {
        // 0x80089764: addiu       $t2, $t2, 0x6980
        ctx->r10 = ADD32(ctx->r10, 0X6980);
            goto L_80089790;
    }
    // 0x80089764: addiu       $t2, $t2, 0x6980
    ctx->r10 = ADD32(ctx->r10, 0X6980);
    // 0x80089768: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008976C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80089770: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089774: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80089778: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8008977C: sw          $t4, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r12;
    // 0x80089780: jal         0x800C06F8
    // 0x80089784: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_9;
    // 0x80089784: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_9:
    // 0x80089788: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008978C: addiu       $t2, $t2, 0x6980
    ctx->r10 = ADD32(ctx->r10, 0X6980);
L_80089790:
    // 0x80089790: b           L_800899A4
    // 0x80089794: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_800899A4;
    // 0x80089794: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80089798:
    // 0x80089798: beq         $t5, $zero, L_800897B0
    if (ctx->r13 == 0) {
        // 0x8008979C: andi        $t7, $a2, 0x9000
        ctx->r15 = ctx->r6 & 0X9000;
            goto L_800897B0;
    }
    // 0x8008979C: andi        $t7, $a2, 0x9000
    ctx->r15 = ctx->r6 & 0X9000;
    // 0x800897A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800897A4: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800897A8: b           L_800899A4
    // 0x800897AC: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_800899A4;
    // 0x800897AC: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_800897B0:
    // 0x800897B0: beq         $t7, $zero, L_800897D8
    if (ctx->r15 == 0) {
        // 0x800897B4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800897D8;
    }
    // 0x800897B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800897B8: bne         $v0, $at, L_800897C8
    if (ctx->r2 != ctx->r1) {
        // 0x800897BC: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_800897C8;
    }
    // 0x800897BC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800897C0: b           L_800899A4
    // 0x800897C4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
        goto L_800899A4;
    // 0x800897C4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_800897C8:
    // 0x800897C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800897CC: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800897D0: b           L_800899A4
    // 0x800897D4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_800899A4;
    // 0x800897D4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_800897D8:
    // 0x800897D8: blez        $t0, L_800897F8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800897DC: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800897F8;
    }
    // 0x800897DC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800897E0: bne         $at, $zero, L_800897F8
    if (ctx->r1 != 0) {
        // 0x800897E4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800897F8;
    }
    // 0x800897E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800897E8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800897EC: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x800897F0: b           L_800899A4
    // 0x800897F4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
        goto L_800899A4;
    // 0x800897F4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_800897F8:
    // 0x800897F8: bgez        $t0, L_800899A4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800897FC: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800899A4;
    }
    // 0x800897FC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80089800: beq         $at, $zero, L_800899A4
    if (ctx->r1 == 0) {
        // 0x80089804: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_800899A4;
    }
    // 0x80089804: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80089808: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008980C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80089810: b           L_800899A4
    // 0x80089814: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_800899A4;
    // 0x80089814: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80089818:
    // 0x80089818: bne         $t8, $zero, L_80089838
    if (ctx->r24 != 0) {
        // 0x8008981C: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_80089838;
    }
    // 0x8008981C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80089820: addiu       $t1, $t1, -0x620
    ctx->r9 = ADD32(ctx->r9, -0X620);
    // 0x80089824: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80089828: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x8008982C: bne         $t3, $v1, L_80089860
    if (ctx->r11 != ctx->r3) {
        // 0x80089830: andi        $t9, $a2, 0x9000
        ctx->r25 = ctx->r6 & 0X9000;
            goto L_80089860;
    }
    // 0x80089830: andi        $t9, $a2, 0x9000
    ctx->r25 = ctx->r6 & 0X9000;
    // 0x80089834: beq         $t9, $zero, L_80089860
    if (ctx->r25 == 0) {
        // 0x80089838: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80089860;
    }
L_80089838:
    // 0x80089838: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008983C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80089840: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089844: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80089848: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8008984C: sw          $t5, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r13;
    // 0x80089850: jal         0x800C06F8
    // 0x80089854: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_10;
    // 0x80089854: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_10:
    // 0x80089858: b           L_800899A8
    // 0x8008985C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
        goto L_800899A8;
    // 0x8008985C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_80089860:
    // 0x80089860: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80089864: beq         $v1, $at, L_8008987C
    if (ctx->r3 == ctx->r1) {
        // 0x80089868: nop
    
            goto L_8008987C;
    }
    // 0x80089868: nop

    // 0x8008986C: beq         $v1, $t3, L_80089890
    if (ctx->r3 == ctx->r11) {
        // 0x80089870: nop
    
            goto L_80089890;
    }
    // 0x80089870: nop

    // 0x80089874: b           L_800898A8
    // 0x80089878: andi        $v0, $a2, 0x9000
    ctx->r2 = ctx->r6 & 0X9000;
        goto L_800898A8;
    // 0x80089878: andi        $v0, $a2, 0x9000
    ctx->r2 = ctx->r6 & 0X9000;
L_8008987C:
    // 0x8008987C: bgez        $t0, L_800899A4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80089880: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800899A4;
    }
    // 0x80089880: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80089884: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80089888: b           L_800899A4
    // 0x8008988C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
        goto L_800899A4;
    // 0x8008988C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80089890:
    // 0x80089890: blez        $t0, L_800899A4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80089894: addiu       $t7, $zero, 0xF
        ctx->r15 = ADD32(0, 0XF);
            goto L_800899A4;
    }
    // 0x80089894: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80089898: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008989C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800898A0: b           L_800899A4
    // 0x800898A4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_800899A4;
    // 0x800898A4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_800898A8:
    // 0x800898A8: beq         $v0, $zero, L_800898F8
    if (ctx->r2 == 0) {
        // 0x800898AC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800898F8;
    }
    // 0x800898AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800898B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800898B4: lbu         $v0, 0x7120($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7120);
    // 0x800898B8: nop

    // 0x800898BC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800898C0: bne         $at, $zero, L_800898EC
    if (ctx->r1 != 0) {
        // 0x800898C4: slti        $at, $v0, 0x7
        ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
            goto L_800898EC;
    }
    // 0x800898C4: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x800898C8: beq         $at, $zero, L_800898EC
    if (ctx->r1 == 0) {
        // 0x800898CC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800898EC;
    }
    // 0x800898CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800898D0: addiu       $a0, $a0, 0x71D0
    ctx->r4 = ADD32(ctx->r4, 0X71D0);
    // 0x800898D4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800898D8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800898DC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800898E0: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800898E4: b           L_8008993C
    // 0x800898E8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
        goto L_8008993C;
    // 0x800898E8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_800898EC:
    // 0x800898EC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800898F0: b           L_8008993C
    // 0x800898F4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
        goto L_8008993C;
    // 0x800898F4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
L_800898F8:
    // 0x800898F8: blez        $t0, L_80089924
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800898FC: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80089924;
    }
    // 0x800898FC: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80089900: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80089904: bgez        $t6, L_80089918
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80089908: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80089918;
    }
    // 0x80089908: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8008990C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80089910: b           L_8008993C
    // 0x80089914: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8008993C;
    // 0x80089914: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80089918:
    // 0x80089918: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008991C: b           L_8008993C
    // 0x80089920: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_8008993C;
    // 0x80089920: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80089924:
    // 0x80089924: bgez        $t0, L_8008993C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80089928: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8008993C;
    }
    // 0x80089928: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8008992C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089930: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80089934: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80089938: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8008993C:
    // 0x8008993C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80089940: addiu       $a1, $a1, 0x6978
    ctx->r5 = ADD32(ctx->r5, 0X6978);
    // 0x80089944: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089948: lw          $a0, 0x7174($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7174);
    // 0x8008994C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80089950: subu        $t5, $v1, $a0
    ctx->r13 = SUB32(ctx->r3, ctx->r4);
    // 0x80089954: addu        $t4, $v0, $a0
    ctx->r12 = ADD32(ctx->r2, ctx->r4);
    // 0x80089958: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8008995C: bne         $at, $zero, L_80089970
    if (ctx->r1 != 0) {
        // 0x80089960: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80089970;
    }
    // 0x80089960: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80089964: addiu       $v0, $t5, 0x1
    ctx->r2 = ADD32(ctx->r13, 0X1);
    // 0x80089968: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8008996C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_80089970:
    // 0x80089970: beq         $at, $zero, L_80089980
    if (ctx->r1 == 0) {
        // 0x80089974: nop
    
            goto L_80089980;
    }
    // 0x80089974: nop

    // 0x80089978: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8008997C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80089980:
    // 0x80089980: subu        $v1, $t3, $a0
    ctx->r3 = SUB32(ctx->r11, ctx->r4);
    // 0x80089984: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80089988: beq         $at, $zero, L_80089998
    if (ctx->r1 == 0) {
        // 0x8008998C: nop
    
            goto L_80089998;
    }
    // 0x8008998C: nop

    // 0x80089990: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80089994: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80089998:
    // 0x80089998: bgez        $v0, L_800899A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008999C: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_800899A8;
    }
    // 0x8008999C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800899A0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800899A4:
    // 0x800899A4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_800899A8:
    // 0x800899A8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800899AC: beq         $t7, $zero, L_800899C4
    if (ctx->r15 == 0) {
        // 0x800899B0: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_800899C4;
    }
    // 0x800899B0: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800899B4: jal         0x80001D04
    // 0x800899B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_11;
    // 0x800899B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x800899BC: b           L_80089A2C
    // 0x800899C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80089A2C;
    // 0x800899C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800899C4:
    // 0x800899C4: beq         $t8, $zero, L_800899DC
    if (ctx->r24 == 0) {
        // 0x800899C8: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_800899DC;
    }
    // 0x800899C8: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800899CC: jal         0x80001D04
    // 0x800899D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_12;
    // 0x800899D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x800899D4: b           L_80089A2C
    // 0x800899D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80089A2C;
    // 0x800899D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800899DC:
    // 0x800899DC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800899E0: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800899E4: beq         $t9, $zero, L_80089A2C
    if (ctx->r25 == 0) {
        // 0x800899E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80089A2C;
    }
    // 0x800899E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800899EC: jal         0x80001D04
    // 0x800899F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x800899F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x800899F4: b           L_80089A2C
    // 0x800899F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80089A2C;
    // 0x800899F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800899FC:
    // 0x800899FC: slti        $at, $t4, 0x24
    ctx->r1 = SIGNED(ctx->r12) < 0X24 ? 1 : 0;
    // 0x80089A00: bne         $at, $zero, L_80089A28
    if (ctx->r1 != 0) {
        // 0x80089A04: sw          $t4, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r12;
            goto L_80089A28;
    }
    // 0x80089A04: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80089A08: jal         0x80089A38
    // 0x80089A0C: nop

    pakmenu_free(rdram, ctx);
        goto after_14;
    // 0x80089A0C: nop

    after_14:
    // 0x80089A10: jal         0x80081820
    // 0x80089A14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    menu_init(rdram, ctx);
        goto after_15;
    // 0x80089A14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x80089A18: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80089A1C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80089A20: jal         0x8006E528
    // 0x80089A24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_16;
    // 0x80089A24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
L_80089A28:
    // 0x80089A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80089A2C:
    // 0x80089A2C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80089A30: jr          $ra
    // 0x80089A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80089A34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void update_camera_car(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058228: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8005822C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80058230: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80058234: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80058238: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005823C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058240: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80058244: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x80058248: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8005824C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80058250: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80058254: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x80058258: jal         0x80066450
    // 0x8005825C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8005825C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80058260: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80058264: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80058268: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8005826C: bne         $v0, $a0, L_80058284
    if (ctx->r2 != ctx->r4) {
        // 0x80058270: lui         $at, 0x4340
        ctx->r1 = S32(0X4340 << 16);
            goto L_80058284;
    }
    // 0x80058270: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x80058274: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80058278: addiu       $t7, $zero, 0x200
    ctx->r15 = ADD32(0, 0X200);
    // 0x8005827C: b           L_800582A4
    // 0x80058280: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
        goto L_800582A4;
    // 0x80058280: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80058284:
    // 0x80058284: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80058288: bne         $at, $zero, L_800582A4
    if (ctx->r1 != 0) {
        // 0x8005828C: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_800582A4;
    }
    // 0x8005828C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80058290: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80058294: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80058298: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005829C: nop

    // 0x800582A0: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
L_800582A4:
    // 0x800582A4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800582A8: jal         0x8002359C
    // 0x800582AC: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    func_80023568(rdram, ctx);
        goto after_1;
    // 0x800582AC: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x800582B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800582B4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800582B8: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800582BC: beq         $v0, $a0, L_800582C8
    if (ctx->r2 == ctx->r4) {
        // 0x800582C0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800582C8;
    }
    // 0x800582C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800582C4: bne         $v0, $at, L_80058310
    if (ctx->r2 != ctx->r1) {
        // 0x800582C8: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80058310;
    }
L_800582C8:
    // 0x800582C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800582CC: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x800582D0: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x800582D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800582D8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800582DC: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x800582E0: lbu         $t9, 0x3B($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3B);
    // 0x800582E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800582E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800582EC: bne         $t9, $at, L_80058304
    if (ctx->r25 != ctx->r1) {
        // 0x800582F0: mov.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
            goto L_80058304;
    }
    // 0x800582F0: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x800582F4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800582F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800582FC: nop

    // 0x80058300: add.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f8.fl;
L_80058304:
    // 0x80058304: addiu       $t1, $zero, 0xD00
    ctx->r9 = ADD32(0, 0XD00);
    // 0x80058308: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8005830C: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
L_80058310:
    // 0x80058310: lh          $t2, 0x1A0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X1A0);
    // 0x80058314: lh          $v0, 0x19E($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X19E);
    // 0x80058318: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8005831C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80058320: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x80058324: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x80058328: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8005832C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80058330: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80058334: slti        $at, $v1, 0x401
    ctx->r1 = SIGNED(ctx->r3) < 0X401 ? 1 : 0;
    // 0x80058338: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x8005833C: bne         $at, $zero, L_80058348
    if (ctx->r1 != 0) {
        // 0x80058340: sh          $t5, 0x196($a3)
        MEM_H(0X196, ctx->r7) = ctx->r13;
            goto L_80058348;
    }
    // 0x80058340: sh          $t5, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r13;
    // 0x80058344: addiu       $v1, $zero, 0x400
    ctx->r3 = ADD32(0, 0X400);
L_80058348:
    // 0x80058348: slti        $at, $v1, -0x400
    ctx->r1 = SIGNED(ctx->r3) < -0X400 ? 1 : 0;
    // 0x8005834C: beq         $at, $zero, L_80058358
    if (ctx->r1 == 0) {
        // 0x80058350: nop
    
            goto L_80058358;
    }
    // 0x80058350: nop

    // 0x80058354: addiu       $v1, $zero, -0x400
    ctx->r3 = ADD32(0, -0X400);
L_80058358:
    // 0x80058358: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005835C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80058360: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80058364: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058368: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005836C: nop

    // 0x80058370: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80058374: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80058378: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005837C: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80058380: mflo        $v1
    ctx->r3 = lo;
    // 0x80058384: blez        $v1, L_80058398
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80058388: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80058398;
    }
    // 0x80058388: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005838C: beq         $at, $zero, L_80058398
    if (ctx->r1 == 0) {
        // 0x80058390: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_80058398;
    }
    // 0x80058390: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x80058394: sh          $t7, 0x19E($a3)
    MEM_H(0X19E, ctx->r7) = ctx->r15;
L_80058398:
    // 0x80058398: bgez        $v1, L_800583B8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005839C: nop
    
            goto L_800583B8;
    }
    // 0x8005839C: nop

    // 0x800583A0: lh          $v0, 0x19E($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X19E);
    // 0x800583A4: nop

    // 0x800583A8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800583AC: beq         $at, $zero, L_800583B8
    if (ctx->r1 == 0) {
        // 0x800583B0: subu        $t8, $v0, $v1
        ctx->r24 = SUB32(ctx->r2, ctx->r3);
            goto L_800583B8;
    }
    // 0x800583B0: subu        $t8, $v0, $v1
    ctx->r24 = SUB32(ctx->r2, ctx->r3);
    // 0x800583B4: sh          $t8, 0x19E($a3)
    MEM_H(0X19E, ctx->r7) = ctx->r24;
L_800583B8:
    // 0x800583B8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800583BC: lwc1        $f14, 0xB8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x800583C0: lbu         $v0, 0x3B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3B);
    // 0x800583C4: lwc1        $f2, 0x8($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800583C8: beq         $v0, $a0, L_800583E8
    if (ctx->r2 == ctx->r4) {
        // 0x800583CC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800583E8;
    }
    // 0x800583CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800583D0: beq         $v0, $at, L_800583F8
    if (ctx->r2 == ctx->r1) {
        // 0x800583D4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800583F8;
    }
    // 0x800583D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800583D8: beq         $v0, $at, L_80058418
    if (ctx->r2 == ctx->r1) {
        // 0x800583DC: lui         $at, 0x4254
        ctx->r1 = S32(0X4254 << 16);
            goto L_80058418;
    }
    // 0x800583DC: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x800583E0: b           L_8005844C
    // 0x800583E4: lb          $t9, 0x1E2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1E2);
        goto L_8005844C;
    // 0x800583E4: lb          $t9, 0x1E2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1E2);
L_800583E8:
    // 0x800583E8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800583EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800583F0: b           L_80058448
    // 0x800583F4: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
        goto L_80058448;
    // 0x800583F4: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_800583F8:
    // 0x800583F8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800583FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80058400: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80058404: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80058408: sub.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8005840C: b           L_80058448
    // 0x80058410: sub.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f10.fl;
        goto L_80058448;
    // 0x80058410: sub.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80058414: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
L_80058418:
    // 0x80058418: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005841C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80058420: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80058424: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80058428: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005842C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80058430: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80058434: sub.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80058438: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005843C: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80058440: sub.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80058444: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_80058448:
    // 0x80058448: lb          $t9, 0x1E2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1E2);
L_8005844C:
    // 0x8005844C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80058450: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80058454: beq         $at, $zero, L_80058470
    if (ctx->r1 == 0) {
        // 0x80058458: lw          $t2, 0x6C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X6C);
            goto L_80058470;
    }
    // 0x80058458: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8005845C: lb          $t1, 0x1E5($a3)
    ctx->r9 = MEM_B(ctx->r7, 0X1E5);
    // 0x80058460: nop

    // 0x80058464: beq         $t1, $zero, L_800584F8
    if (ctx->r9 == 0) {
        // 0x80058468: nop
    
            goto L_800584F8;
    }
    // 0x80058468: nop

    // 0x8005846C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
L_80058470:
    // 0x80058470: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80058474: lh          $v0, 0x2($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X2);
    // 0x80058478: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005847C: blez        $v0, L_800584A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80058480: nop
    
            goto L_800584A0;
    }
    // 0x80058480: nop

    // 0x80058484: addiu       $v0, $v0, -0x71C
    ctx->r2 = ADD32(ctx->r2, -0X71C);
    // 0x80058488: bgez        $v0, L_80058498
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005848C: sra         $t3, $v0, 1
        ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80058498;
    }
    // 0x8005848C: sra         $t3, $v0, 1
    ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80058490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80058494: sra         $t3, $v0, 1
    ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
L_80058498:
    // 0x80058498: b           L_800584B0
    // 0x8005849C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_800584B0;
    // 0x8005849C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_800584A0:
    // 0x800584A0: addiu       $v0, $v0, 0x71C
    ctx->r2 = ADD32(ctx->r2, 0X71C);
    // 0x800584A4: blez        $v0, L_800584B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800584A8: nop
    
            goto L_800584B0;
    }
    // 0x800584A8: nop

    // 0x800584AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800584B0:
    // 0x800584B0: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x800584B4: subu        $v0, $t4, $v0
    ctx->r2 = SUB32(ctx->r12, ctx->r2);
    // 0x800584B8: andi        $t5, $a0, 0xFFFF
    ctx->r13 = ctx->r4 & 0XFFFF;
    // 0x800584BC: subu        $v1, $v0, $t5
    ctx->r3 = SUB32(ctx->r2, ctx->r13);
    // 0x800584C0: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800584C4: bne         $at, $zero, L_800584D4
    if (ctx->r1 != 0) {
        // 0x800584C8: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800584D4;
    }
    // 0x800584C8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800584CC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800584D0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800584D4:
    // 0x800584D4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800584D8: beq         $at, $zero, L_800584E4
    if (ctx->r1 == 0) {
        // 0x800584DC: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800584E4;
    }
    // 0x800584DC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800584E0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800584E4:
    // 0x800584E4: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800584E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800584EC: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x800584F0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800584F4: sh          $t8, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r24;
L_800584F8:
    // 0x800584F8: lwc1        $f0, 0x2C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x800584FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80058500: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80058504: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80058508: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8005850C: bc1f        L_80058568
    if (!c1cs) {
        // 0x80058510: nop
    
            goto L_80058568;
    }
    // 0x80058510: nop

    // 0x80058514: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80058518: lb          $t9, 0x1E6($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1E6);
    // 0x8005851C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80058520: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80058524: beq         $t9, $zero, L_80058538
    if (ctx->r25 == 0) {
        // 0x80058528: neg.s       $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
            goto L_80058538;
    }
    // 0x80058528: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8005852C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80058530: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80058534: nop

L_80058538:
    // 0x80058538: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8005853C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80058540: lwc1        $f7, 0x6EA0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6EA0);
    // 0x80058544: lwc1        $f6, 0x6EA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6EA4);
    // 0x80058548: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x8005854C: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80058550: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80058554: bc1f        L_80058564
    if (!c1cs) {
        // 0x80058558: nop
    
            goto L_80058564;
    }
    // 0x80058558: nop

    // 0x8005855C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80058560: nop

L_80058564:
    // 0x80058564: sub.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f12.fl;
L_80058568:
    // 0x80058568: lb          $t1, 0x1E6($a3)
    ctx->r9 = MEM_B(ctx->r7, 0X1E6);
    // 0x8005856C: nop

    // 0x80058570: bne         $t1, $zero, L_8005858C
    if (ctx->r9 != 0) {
        // 0x80058574: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_8005858C;
    }
    // 0x80058574: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80058578: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005857C: nop

    // 0x80058580: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80058584: b           L_800585A0
    // 0x80058588: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
        goto L_800585A0;
    // 0x80058588: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8005858C:
    // 0x8005858C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80058590: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80058594: nop

    // 0x80058598: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8005859C: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_800585A0:
    // 0x800585A0: lw          $t2, -0x2540($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2540);
    // 0x800585A4: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x800585A8: bne         $t2, $zero, L_800585FC
    if (ctx->r10 != 0) {
        // 0x800585AC: addiu       $a0, $zero, 0x24
        ctx->r4 = ADD32(0, 0X24);
            goto L_800585FC;
    }
    // 0x800585AC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x800585B0: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800585B4: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x800585B8: jal         0x8000C8B4
    // 0x800585BC: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    normalise_time(rdram, ctx);
        goto after_2;
    // 0x800585BC: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x800585C0: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800585C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800585C8: lb          $v1, 0x1D3($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1D3);
    // 0x800585CC: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800585D0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800585D4: beq         $at, $zero, L_800585EC
    if (ctx->r1 == 0) {
        // 0x800585D8: addiu       $t0, $t0, -0x2578
        ctx->r8 = ADD32(ctx->r8, -0X2578);
            goto L_800585EC;
    }
    // 0x800585D8: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x800585DC: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x800585E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800585E4: b           L_800585FC
    // 0x800585E8: nop

        goto L_800585FC;
    // 0x800585E8: nop

L_800585EC:
    // 0x800585EC: blez        $v1, L_800585FC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800585F0: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_800585FC;
    }
    // 0x800585F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800585F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800585F8: nop

L_800585FC:
    // 0x800585FC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80058600: lw          $t3, -0x2540($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2540);
    // 0x80058604: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80058608: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8005860C: slti        $at, $t3, 0x51
    ctx->r1 = SIGNED(ctx->r11) < 0X51 ? 1 : 0;
    // 0x80058610: bne         $at, $zero, L_80058630
    if (ctx->r1 != 0) {
        // 0x80058614: nop
    
            goto L_80058630;
    }
    // 0x80058614: nop

    // 0x80058618: swc1        $f16, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f16.u32l;
    // 0x8005861C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80058620: nop

    // 0x80058624: swc1        $f18, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f18.u32l;
    // 0x80058628: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8005862C: nop

L_80058630:
    // 0x80058630: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80058634: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80058638: sub.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8005863C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80058640: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80058644: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80058648: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8005864C: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80058650: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x80058654: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80058658: swc1        $f6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f6.u32l;
    // 0x8005865C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058660: nop

    // 0x80058664: lwc1        $f14, 0x20($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80058668: nop

    // 0x8005866C: sub.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x80058670: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80058674: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80058678: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x8005867C: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x80058680: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80058684: swc1        $f4, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f4.u32l;
    // 0x80058688: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8005868C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80058690: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x80058694: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80058698: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    // 0x8005869C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x800586A0: jal         0x80070A04
    // 0x800586A4: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    sins_f(rdram, ctx);
        goto after_3;
    // 0x800586A4: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_3:
    // 0x800586A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800586AC: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x800586B0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800586B4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800586B8: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x800586BC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800586C0: subu        $a0, $t2, $t3
    ctx->r4 = SUB32(ctx->r10, ctx->r11);
    // 0x800586C4: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x800586C8: jal         0x80070A38
    // 0x800586CC: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_4;
    // 0x800586CC: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_4:
    // 0x800586D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800586D4: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x800586D8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800586DC: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800586E0: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800586E4: lwc1        $f14, 0x20($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800586E8: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800586EC: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800586F0: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x800586F4: mul.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800586F8: nop

    // 0x800586FC: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80058700: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80058704: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80058708: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8005870C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80058710: lh          $t6, 0x196($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X196);
    // 0x80058714: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x80058718: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    // 0x8005871C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80058720: jal         0x80070A04
    // 0x80058724: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    sins_f(rdram, ctx);
        goto after_5;
    // 0x80058724: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_5:
    // 0x80058728: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8005872C: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80058730: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80058734: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x80058738: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x8005873C: lh          $t1, 0x196($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X196);
    // 0x80058740: nop

    // 0x80058744: subu        $a0, $t2, $t1
    ctx->r4 = SUB32(ctx->r10, ctx->r9);
    // 0x80058748: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x8005874C: jal         0x80070A38
    // 0x80058750: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    coss_f(rdram, ctx);
        goto after_6;
    // 0x80058750: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_6:
    // 0x80058754: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80058758: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8005875C: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80058760: lw          $t5, -0x2558($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2558);
    // 0x80058764: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80058768: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8005876C: andi        $t7, $t5, 0x8000
    ctx->r15 = ctx->r13 & 0X8000;
    // 0x80058770: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80058774: beq         $t7, $zero, L_80058804
    if (ctx->r15 == 0) {
        // 0x80058778: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_80058804;
    }
    // 0x80058778: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8005877C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80058780: lwc1        $f4, 0x30($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X30);
    // 0x80058784: lwc1        $f7, 0x6EA8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6EA8);
    // 0x80058788: lwc1        $f6, 0x6EAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6EAC);
    // 0x8005878C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80058790: mul.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80058794: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80058798: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8005879C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x800587A0: nop

    // 0x800587A4: bc1f        L_800587DC
    if (!c1cs) {
        // 0x800587A8: nop
    
            goto L_800587DC;
    }
    // 0x800587A8: nop

    // 0x800587AC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800587B0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800587B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800587B8: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800587BC: sub.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d - ctx->f10.d;
    // 0x800587C0: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x800587C4: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x800587C8: nop

    // 0x800587CC: bc1f        L_80058804
    if (!c1cs) {
        // 0x800587D0: nop
    
            goto L_80058804;
    }
    // 0x800587D0: nop

    // 0x800587D4: b           L_80058804
    // 0x800587D8: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_80058804;
    // 0x800587D8: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_800587DC:
    // 0x800587DC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800587E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800587E4: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800587E8: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x800587EC: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x800587F0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x800587F4: nop

    // 0x800587F8: bc1f        L_80058804
    if (!c1cs) {
        // 0x800587FC: nop
    
            goto L_80058804;
    }
    // 0x800587FC: nop

    // 0x80058800: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80058804:
    // 0x80058804: lb          $v0, 0x1E6($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X1E6);
    // 0x80058808: nop

    // 0x8005880C: beq         $v0, $zero, L_80058830
    if (ctx->r2 == 0) {
        // 0x80058810: nop
    
            goto L_80058830;
    }
    // 0x80058810: nop

    // 0x80058814: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80058818: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005881C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80058820: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80058824: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x80058828: mul.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8005882C: nop

L_80058830:
    // 0x80058830: lwc1        $f0, 0xC8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x80058834: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80058838: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005883C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80058840: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80058844: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80058848: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8005884C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80058850: lb          $t6, 0x1DB($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1DB);
    // 0x80058854: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80058858: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8005885C: beq         $t6, $zero, L_8005888C
    if (ctx->r14 == 0) {
        // 0x80058860: swc1        $f4, 0xC8($a3)
        MEM_W(0XC8, ctx->r7) = ctx->f4.u32l;
            goto L_8005888C;
    }
    // 0x80058860: swc1        $f4, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f4.u32l;
    // 0x80058864: lwc1        $f6, 0x94($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80058868: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8005886C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80058870: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80058874: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80058878: mul.d       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x8005887C: sub.d       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f0.d - ctx->f8.d;
    // 0x80058880: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80058884: b           L_800588C0
    // 0x80058888: swc1        $f6, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f6.u32l;
        goto L_800588C0;
    // 0x80058888: swc1        $f6, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f6.u32l;
L_8005888C:
    // 0x8005888C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80058890: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80058894: lwc1        $f10, 0x94($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80058898: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005889C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800588A0: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800588A4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800588A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800588AC: sub.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f8.d - ctx->f0.d;
    // 0x800588B0: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800588B4: add.d       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f0.d + ctx->f10.d;
    // 0x800588B8: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x800588BC: swc1        $f4, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f4.u32l;
L_800588C0:
    // 0x800588C0: lwc1        $f0, 0x94($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X94);
    // 0x800588C4: lwc1        $f10, 0x38($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X38);
    // 0x800588C8: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x800588CC: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800588D0: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800588D4: nop

    // 0x800588D8: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800588DC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800588E0: lwc1        $f6, 0x3C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x800588E4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800588E8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800588EC: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800588F0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800588F4: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x800588F8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800588FC: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80058900: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80058904: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80058908: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x8005890C: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80058910: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x80058914: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80058918: jal         0x80070A04
    // 0x8005891C: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    sins_f(rdram, ctx);
        goto after_7;
    // 0x8005891C: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_7:
    // 0x80058920: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80058924: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80058928: lwc1        $f10, 0xC8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x8005892C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80058930: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80058934: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80058938: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005893C: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x80058940: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80058944: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80058948: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8005894C: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    // 0x80058950: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80058954: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80058958: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8005895C: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80058960: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80058964: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80058968: sub.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x8005896C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80058970: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80058974: mul.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80058978: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005897C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80058980: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80058984: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80058988: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8005898C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80058990: cvt.d.s     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.d = CVT_D_S(ctx->f16.fl);
    // 0x80058994: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x80058998: nop

    // 0x8005899C: bc1f        L_800589D0
    if (!c1cs) {
        // 0x800589A0: nop
    
            goto L_800589D0;
    }
    // 0x800589A0: nop

    // 0x800589A4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800589A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800589AC: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x800589B0: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x800589B4: sub.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d - ctx->f8.d;
    // 0x800589B8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800589BC: swc1        $f6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f6.u32l;
    // 0x800589C0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800589C4: nop

    // 0x800589C8: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800589CC: nop

L_800589D0:
    // 0x800589D0: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800589D4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800589D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800589DC: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x800589E0: mul.d       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x800589E4: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x800589E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800589EC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800589F0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800589F4: swc1        $f8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f8.u32l;
    // 0x800589F8: bc1t        L_80058A10
    if (c1cs) {
        // 0x800589FC: nop
    
            goto L_80058A10;
    }
    // 0x800589FC: nop

    // 0x80058A00: lw          $t1, -0x2540($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2540);
    // 0x80058A04: nop

    // 0x80058A08: beq         $t1, $zero, L_80058A1C
    if (ctx->r9 == 0) {
        // 0x80058A0C: nop
    
            goto L_80058A1C;
    }
    // 0x80058A0C: nop

L_80058A10:
    // 0x80058A10: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80058A14: nop

    // 0x80058A18: swc1        $f18, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f18.u32l;
L_80058A1C:
    // 0x80058A1C: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x80058A20: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80058A24: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x80058A28: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x80058A2C: jal         0x80070A38
    // 0x80058A30: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_8;
    // 0x80058A30: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_8:
    // 0x80058A34: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80058A38: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80058A3C: lwc1        $f6, 0xC8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x80058A40: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80058A44: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80058A48: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80058A4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80058A50: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x80058A54: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80058A58: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80058A5C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80058A60: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80058A64: swc1        $f6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f6.u32l;
    // 0x80058A68: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80058A6C: lh          $t6, 0x196($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X196);
    // 0x80058A70: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x80058A74: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x80058A78: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80058A7C: lb          $t2, 0x1E6($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X1E6);
    // 0x80058A80: lh          $v0, 0x4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X4);
    // 0x80058A84: beq         $t2, $zero, L_80058AAC
    if (ctx->r10 == 0) {
        // 0x80058A88: addiu       $t6, $zero, -0x2000
        ctx->r14 = ADD32(0, -0X2000);
            goto L_80058AAC;
    }
    // 0x80058A88: addiu       $t6, $zero, -0x2000
    ctx->r14 = ADD32(0, -0X2000);
    // 0x80058A8C: lwc1        $f10, 0xB8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x80058A90: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80058A94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80058A98: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80058A9C: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x80058AA0: nop

    // 0x80058AA4: bc1t        L_80058ABC
    if (c1cs) {
        // 0x80058AA8: nop
    
            goto L_80058ABC;
    }
    // 0x80058AA8: nop

L_80058AAC:
    // 0x80058AAC: lh          $t1, -0x24FA($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X24FA);
    // 0x80058AB0: nop

    // 0x80058AB4: beq         $t1, $zero, L_80058AC0
    if (ctx->r9 == 0) {
        // 0x80058AB8: nop
    
            goto L_80058AC0;
    }
    // 0x80058AB8: nop

L_80058ABC:
    // 0x80058ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80058AC0:
    // 0x80058AC0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058AC4: nop

    // 0x80058AC8: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80058ACC: nop

    // 0x80058AD0: addu        $t3, $a0, $v0
    ctx->r11 = ADD32(ctx->r4, ctx->r2);
    // 0x80058AD4: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80058AD8: subu        $t5, $a0, $t4
    ctx->r13 = SUB32(ctx->r4, ctx->r12);
    // 0x80058ADC: sh          $t5, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r13;
    // 0x80058AE0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058AE4: nop

    // 0x80058AE8: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80058AEC: nop

    // 0x80058AF0: slti        $at, $a0, 0x2001
    ctx->r1 = SIGNED(ctx->r4) < 0X2001 ? 1 : 0;
    // 0x80058AF4: bne         $at, $zero, L_80058B14
    if (ctx->r1 != 0) {
        // 0x80058AF8: slti        $at, $a0, -0x2000
        ctx->r1 = SIGNED(ctx->r4) < -0X2000 ? 1 : 0;
            goto L_80058B14;
    }
    // 0x80058AF8: slti        $at, $a0, -0x2000
    ctx->r1 = SIGNED(ctx->r4) < -0X2000 ? 1 : 0;
    // 0x80058AFC: sh          $t7, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r15;
    // 0x80058B00: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058B04: nop

    // 0x80058B08: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80058B0C: nop

    // 0x80058B10: slti        $at, $a0, -0x2000
    ctx->r1 = SIGNED(ctx->r4) < -0X2000 ? 1 : 0;
L_80058B14:
    // 0x80058B14: beq         $at, $zero, L_80058B30
    if (ctx->r1 == 0) {
        // 0x80058B18: nop
    
            goto L_80058B30;
    }
    // 0x80058B18: nop

    // 0x80058B1C: sh          $t6, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r14;
    // 0x80058B20: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80058B24: nop

    // 0x80058B28: lh          $a0, 0x4($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X4);
    // 0x80058B2C: nop

L_80058B30:
    // 0x80058B30: jal         0x80070A04
    // 0x80058B34: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    sins_f(rdram, ctx);
        goto after_9;
    // 0x80058B34: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_9:
    // 0x80058B38: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80058B3C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80058B40: lwc1        $f10, 0xC8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x80058B44: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x80058B48: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80058B4C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058B50: nop

    // 0x80058B54: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80058B58: nop

    // 0x80058B5C: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80058B60: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x80058B64: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058B68: nop

    // 0x80058B6C: lwc1        $f12, 0xC($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80058B70: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80058B74: lw          $a2, 0x14($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X14);
    // 0x80058B78: jal         0x80029F58
    // 0x80058B7C: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_10;
    // 0x80058B7C: nop

    after_10:
    // 0x80058B80: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80058B84: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80058B88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058B8C: beq         $v0, $at, L_80058BA0
    if (ctx->r2 == ctx->r1) {
        // 0x80058B90: addiu       $t0, $t0, -0x2578
        ctx->r8 = ADD32(ctx->r8, -0X2578);
            goto L_80058BA0;
    }
    // 0x80058B90: addiu       $t0, $t0, -0x2578
    ctx->r8 = ADD32(ctx->r8, -0X2578);
    // 0x80058B94: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80058B98: nop

    // 0x80058B9C: sh          $v0, 0x34($t9)
    MEM_H(0X34, ctx->r25) = ctx->r2;
L_80058BA0:
    // 0x80058BA0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80058BA4: nop

    // 0x80058BA8: lh          $t1, 0x0($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X0);
    // 0x80058BAC: nop

    // 0x80058BB0: sh          $t1, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r9;
    // 0x80058BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058BB8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80058BBC: jr          $ra
    // 0x80058BC0: nop

    return;
    // 0x80058BC0: nop

;}
RECOMP_FUNC void sound_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001D04: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80001D08: lw          $t7, 0x62A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62A0);
    // 0x80001D0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001D10: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001D14: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001D18: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80001D1C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80001D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001D24: beq         $at, $zero, L_80001D3C
    if (ctx->r1 == 0) {
        // 0x80001D28: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80001D3C;
    }
    // 0x80001D28: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80001D2C: beq         $a1, $zero, L_80001E9C
    if (ctx->r5 == 0) {
        // 0x80001D30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001E9C;
    }
    // 0x80001D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001D34: b           L_80001E98
    // 0x80001D38: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_80001E98;
    // 0x80001D38: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80001D3C:
    // 0x80001D3C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80001D40: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001D44: lw          $t8, 0x6298($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6298);
    // 0x80001D48: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x80001D4C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80001D50: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80001D54: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80001D58: nop

    // 0x80001D5C: bne         $v1, $zero, L_80001D74
    if (ctx->r3 != 0) {
        // 0x80001D60: nop
    
            goto L_80001D74;
    }
    // 0x80001D60: nop

    // 0x80001D64: beq         $a3, $zero, L_80001E9C
    if (ctx->r7 == 0) {
        // 0x80001D68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001E9C;
    }
    // 0x80001D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001D6C: b           L_80001E98
    // 0x80001D70: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_80001E98;
    // 0x80001D70: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80001D74:
    // 0x80001D74: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x80001D78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80001D7C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80001D80: bgez        $t9, L_80001D94
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80001D84: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80001D94;
    }
    // 0x80001D84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80001D88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80001D8C: nop

    // 0x80001D90: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80001D94:
    // 0x80001D94: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80001D98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80001D9C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001DA0: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80001DA4: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001DA8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80001DAC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80001DB0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80001DB4: beq         $a3, $zero, L_80001E34
    if (ctx->r7 == 0) {
        // 0x80001DB8: swc1        $f16, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
            goto L_80001E34;
    }
    // 0x80001DB8: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80001DBC: lw          $t1, 0x6294($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6294);
    // 0x80001DC0: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001DC4: lbu         $a2, 0x8($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X8);
    // 0x80001DC8: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x80001DCC: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001DD0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80001DD4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80001DD8: jal         0x80004668
    // 0x80001DDC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    sndp_play_with_priority(rdram, ctx);
        goto after_0;
    // 0x80001DDC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80001DE0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80001DE4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80001DE8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80001DEC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80001DF0: beq         $a0, $zero, L_80001E9C
    if (ctx->r4 == 0) {
        // 0x80001DF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001E9C;
    }
    // 0x80001DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001DF8: lw          $t3, 0x6298($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6298);
    // 0x80001DFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80001E00: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80001E04: lbu         $a2, 0x2($t4)
    ctx->r6 = MEM_BU(ctx->r12, 0X2);
    // 0x80001E08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80001E0C: sll         $t5, $a2, 8
    ctx->r13 = S32(ctx->r6 << 8);
    // 0x80001E10: jal         0x800049F8
    // 0x80001E14: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    sndp_set_param(rdram, ctx);
        goto after_1;
    // 0x80001E14: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    after_1:
    // 0x80001E18: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80001E1C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80001E20: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80001E24: jal         0x800049F8
    // 0x80001E28: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_2;
    // 0x80001E28: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80001E2C: b           L_80001E9C
    // 0x80001E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80001E9C;
    // 0x80001E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001E34:
    // 0x80001E34: lw          $t6, 0x6294($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6294);
    // 0x80001E38: lbu         $a2, 0x8($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X8);
    // 0x80001E3C: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80001E40: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x80001E44: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80001E48: jal         0x80004668
    // 0x80001E4C: addiu       $a3, $a3, 0x6500
    ctx->r7 = ADD32(ctx->r7, 0X6500);
    sndp_play_with_priority(rdram, ctx);
        goto after_3;
    // 0x80001E4C: addiu       $a3, $a3, 0x6500
    ctx->r7 = ADD32(ctx->r7, 0X6500);
    after_3:
    // 0x80001E50: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001E54: lw          $t8, 0x6500($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6500);
    // 0x80001E58: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80001E5C: beq         $t8, $zero, L_80001E98
    if (ctx->r24 == 0) {
        // 0x80001E60: lui         $t9, 0x8011
        ctx->r25 = S32(0X8011 << 16);
            goto L_80001E98;
    }
    // 0x80001E60: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80001E64: lw          $t9, 0x6298($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6298);
    // 0x80001E68: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80001E6C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80001E70: lbu         $a2, 0x2($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X2);
    // 0x80001E74: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80001E78: sll         $t2, $a2, 8
    ctx->r10 = S32(ctx->r6 << 8);
    // 0x80001E7C: jal         0x800049F8
    // 0x80001E80: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    sndp_set_param(rdram, ctx);
        goto after_4;
    // 0x80001E80: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_4:
    // 0x80001E84: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001E88: lw          $a0, 0x6500($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6500);
    // 0x80001E8C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80001E90: jal         0x800049F8
    // 0x80001E94: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80001E94: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_5:
L_80001E98:
    // 0x80001E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001E9C:
    // 0x80001E9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80001EA0: jr          $ra
    // 0x80001EA4: nop

    return;
    // 0x80001EA4: nop

;}
RECOMP_FUNC void get_memory_colour_tag_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071C64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80071C68: lw          $v0, 0x3B08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3B08);
    // 0x80071C6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80071C70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071C74: addiu       $a2, $zero, 0x640
    ctx->r6 = ADD32(0, 0X640);
L_80071C78:
    // 0x80071C78: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80071C7C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80071C80: beq         $t6, $zero, L_80071C9C
    if (ctx->r14 == 0) {
        // 0x80071C84: nop
    
            goto L_80071C9C;
    }
    // 0x80071C84: nop

    // 0x80071C88: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80071C8C: nop

    // 0x80071C90: bne         $a0, $t7, L_80071C9C
    if (ctx->r4 != ctx->r15) {
        // 0x80071C94: nop
    
            goto L_80071C9C;
    }
    // 0x80071C94: nop

    // 0x80071C98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071C9C:
    // 0x80071C9C: lh          $t8, 0x1C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1C);
    // 0x80071CA0: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071CA4: beq         $t8, $zero, L_80071CC0
    if (ctx->r24 == 0) {
        // 0x80071CA8: nop
    
            goto L_80071CC0;
    }
    // 0x80071CA8: nop

    // 0x80071CAC: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x80071CB0: nop

    // 0x80071CB4: bne         $a0, $t9, L_80071CC0
    if (ctx->r4 != ctx->r25) {
        // 0x80071CB8: nop
    
            goto L_80071CC0;
    }
    // 0x80071CB8: nop

    // 0x80071CBC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071CC0:
    // 0x80071CC0: lh          $t0, 0x1C($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X1C);
    // 0x80071CC4: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071CC8: beq         $t0, $zero, L_80071CE4
    if (ctx->r8 == 0) {
        // 0x80071CCC: nop
    
            goto L_80071CE4;
    }
    // 0x80071CCC: nop

    // 0x80071CD0: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x80071CD4: nop

    // 0x80071CD8: bne         $a0, $t1, L_80071CE4
    if (ctx->r4 != ctx->r9) {
        // 0x80071CDC: nop
    
            goto L_80071CE4;
    }
    // 0x80071CDC: nop

    // 0x80071CE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071CE4:
    // 0x80071CE4: lh          $t2, 0x1C($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1C);
    // 0x80071CE8: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071CEC: beq         $t2, $zero, L_80071D08
    if (ctx->r10 == 0) {
        // 0x80071CF0: nop
    
            goto L_80071D08;
    }
    // 0x80071CF0: nop

    // 0x80071CF4: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x80071CF8: nop

    // 0x80071CFC: bne         $a0, $t3, L_80071D08
    if (ctx->r4 != ctx->r11) {
        // 0x80071D00: nop
    
            goto L_80071D08;
    }
    // 0x80071D00: nop

    // 0x80071D04: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071D08:
    // 0x80071D08: bne         $a1, $a2, L_80071C78
    if (ctx->r5 != ctx->r6) {
        // 0x80071D0C: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_80071C78;
    }
    // 0x80071D0C: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071D10: jr          $ra
    // 0x80071D14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80071D14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mtxf_billboard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070370: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070374: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x80070378: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x8007037C: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070380: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80070384: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070388: jal         0x80070A70
    // 0x8007038C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    static_3_80070A70(rdram, ctx);
        goto after_0;
    // 0x8007038C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80070390: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80070394: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80070398: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007039C: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800703A0: jal         0x80070A6C
    // 0x800703A4: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x800703A4: nop

    after_1:
    // 0x800703A8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800703AC: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800703B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800703B4: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800703B8: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    // 0x800703BC: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    // 0x800703C0: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x800703C4: sw          $zero, 0x18($a3)
    MEM_W(0X18, ctx->r7) = 0;
    // 0x800703C8: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x800703CC: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800703D0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800703D4: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800703D8: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    // 0x800703DC: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x800703E0: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x800703E4: sw          $zero, 0x34($a3)
    MEM_W(0X34, ctx->r7) = 0;
    // 0x800703E8: mul.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800703EC: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800703F0: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800703F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800703F8: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x800703FC: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80070400: swc1        $f16, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f16.u32l;
    // 0x80070404: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x80070408: neg.s       $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = -ctx->f8.fl;
    // 0x8007040C: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
    // 0x80070410: swc1        $f10, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f10.u32l;
    // 0x80070414: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070418: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8007041C: jr          $ra
    // 0x80070420: nop

    return;
    // 0x80070420: nop

;}
RECOMP_FUNC void debug_text_origin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7440: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B7444: lw          $t6, -0x7D84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D84);
    // 0x800B7448: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B744C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B7450: lw          $t7, -0x7D7C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D7C);
    // 0x800B7454: sh          $t6, -0x7D94($at)
    MEM_H(-0X7D94, ctx->r1) = ctx->r14;
    // 0x800B7458: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B745C: jr          $ra
    // 0x800B7460: sh          $t7, -0x7D92($at)
    MEM_H(-0X7D92, ctx->r1) = ctx->r15;
    return;
    // 0x800B7460: sh          $t7, -0x7D92($at)
    MEM_H(-0X7D92, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void level_header_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C000: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C004: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006C008: nop

    // 0x8006C00C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006C010: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8006C014: jr          $ra
    // 0x8006C018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8006C018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void obj_loop_effectbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034BB4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80034BB8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80034BBC: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80034BC0: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80034BC4: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x80034BC8: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80034BCC: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80034BD0: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80034BD4: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80034BD8: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80034BDC: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80034BE0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80034BE4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80034BE8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80034BEC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80034BF0: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x80034BF4: lw          $s0, 0x3C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X3C);
    // 0x80034BF8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80034BFC: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80034C00: jal         0x8001BAA8
    // 0x80034C04: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x80034C04: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    after_0:
    // 0x80034C08: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80034C0C: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    // 0x80034C10: nop

    // 0x80034C14: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x80034C18: negu        $a0, $t6
    ctx->r4 = SUB32(0, ctx->r14);
    // 0x80034C1C: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80034C20: jal         0x80070A38
    // 0x80034C24: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80034C24: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x80034C28: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    // 0x80034C2C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80034C30: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x80034C34: negu        $a0, $t9
    ctx->r4 = SUB32(0, ctx->r25);
    // 0x80034C38: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80034C3C: jal         0x80070A04
    // 0x80034C40: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80034C40: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    after_2:
    // 0x80034C44: lbu         $t2, 0x8($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X8);
    // 0x80034C48: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80034C4C: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034C50: lbu         $t4, 0x9($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X9);
    // 0x80034C54: lbu         $t6, 0xA($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA);
    // 0x80034C58: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80034C5C: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x80034C60: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80034C64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80034C68: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80034C6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80034C70: mflo        $t3
    ctx->r11 = lo;
    // 0x80034C74: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80034C78: nop

    // 0x80034C7C: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034C80: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80034C84: mflo        $t5
    ctx->r13 = lo;
    // 0x80034C88: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80034C8C: nop

    // 0x80034C90: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034C94: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80034C98: mflo        $t7
    ctx->r15 = lo;
    // 0x80034C9C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80034CA0: blez        $t8, L_80034E70
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80034CA4: cvt.s.w     $f24, $f8
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80034E70;
    }
    // 0x80034CA4: cvt.s.w     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80034CA8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80034CAC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80034CB0: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x80034CB4: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80034CB8: neg.s       $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = -ctx->f18.fl;
L_80034CBC:
    // 0x80034CBC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80034CC0: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80034CC4: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80034CC8: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80034CCC: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80034CD0: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80034CD4: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80034CD8: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80034CDC: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80034CE0: c.lt.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl < ctx->f2.fl;
    // 0x80034CE4: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80034CE8: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034CEC: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034CEC: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034CF0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80034CF4: nop

    // 0x80034CF8: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034CFC: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034CFC: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D00: mul.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80034D04: neg.s       $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
    // 0x80034D08: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80034D0C: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80034D10: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80034D14: nop

    // 0x80034D18: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034D1C: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034D1C: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D20: c.lt.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl < ctx->f22.fl;
    // 0x80034D24: nop

    // 0x80034D28: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034D2C: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034D2C: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D30: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x80034D34: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80034D38: neg.s       $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = -ctx->f24.fl;
    // 0x80034D3C: mul.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80034D40: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80034D44: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80034D48: nop

    // 0x80034D4C: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034D50: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034D50: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D54: c.lt.s      $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
    // 0x80034D58: nop

    // 0x80034D5C: bc1f        L_80034E60
    if (!c1cs) {
        // 0x80034D60: nop
    
            goto L_80034E60;
    }
    // 0x80034D60: nop

    // 0x80034D64: div.s       $f12, $f18, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f30.fl);
    // 0x80034D68: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x80034D6C: lbu         $t9, 0xC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XC);
    // 0x80034D70: nop

    // 0x80034D74: sb          $t9, 0x1FE($v0)
    MEM_B(0X1FE, ctx->r2) = ctx->r25;
    // 0x80034D78: lbu         $t0, 0xD($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XD);
    // 0x80034D7C: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x80034D80: sb          $t0, 0x1FF($v0)
    MEM_B(0X1FF, ctx->r2) = ctx->r8;
    // 0x80034D84: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80034D88: nop

    // 0x80034D8C: bc1f        L_80034E64
    if (!c1cs) {
        // 0x80034D90: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034D90: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D94: bne         $a3, $t1, L_80034E64
    if (ctx->r7 != ctx->r9) {
        // 0x80034D98: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E64;
    }
    // 0x80034D98: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D9C: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80034DA0: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x80034DA4: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80034DA8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80034DAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80034DB0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80034DB4: sub.d       $f10, $f26, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f26.d - ctx->f8.d;
    // 0x80034DB8: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x80034DBC: bgez        $t2, L_80034DD0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80034DC0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80034DD0;
    }
    // 0x80034DC0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80034DC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80034DC8: nop

    // 0x80034DCC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80034DD0:
    // 0x80034DD0: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80034DD4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80034DD8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80034DDC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80034DE0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80034DE4: nop

    // 0x80034DE8: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80034DEC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80034DF0: nop

    // 0x80034DF4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80034DF8: beq         $t4, $zero, L_80034E44
    if (ctx->r12 == 0) {
        // 0x80034DFC: nop
    
            goto L_80034E44;
    }
    // 0x80034DFC: nop

    // 0x80034E00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034E04: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80034E08: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80034E0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80034E10: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80034E14: nop

    // 0x80034E18: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80034E1C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80034E20: nop

    // 0x80034E24: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80034E28: bne         $t4, $zero, L_80034E3C
    if (ctx->r12 != 0) {
        // 0x80034E2C: nop
    
            goto L_80034E3C;
    }
    // 0x80034E2C: nop

    // 0x80034E30: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80034E34: b           L_80034E54
    // 0x80034E38: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80034E54;
    // 0x80034E38: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80034E3C:
    // 0x80034E3C: b           L_80034E54
    // 0x80034E40: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80034E54;
    // 0x80034E40: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_80034E44:
    // 0x80034E44: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80034E48: nop

    // 0x80034E4C: bltz        $t4, L_80034E3C
    if (SIGNED(ctx->r12) < 0) {
        // 0x80034E50: nop
    
            goto L_80034E3C;
    }
    // 0x80034E50: nop

L_80034E54:
    // 0x80034E54: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80034E58: sb          $t4, 0x1FF($v0)
    MEM_B(0X1FF, ctx->r2) = ctx->r12;
    // 0x80034E5C: nop

L_80034E60:
    // 0x80034E60: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
L_80034E64:
    // 0x80034E64: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80034E68: bne         $a0, $t5, L_80034CBC
    if (ctx->r4 != ctx->r13) {
        // 0x80034E6C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80034CBC;
    }
    // 0x80034E6C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80034E70:
    // 0x80034E70: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80034E74: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80034E78: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80034E7C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80034E80: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80034E84: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80034E88: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80034E8C: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80034E90: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80034E94: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80034E98: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80034E9C: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80034EA0: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80034EA4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80034EA8: jr          $ra
    // 0x80034EAC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80034EAC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void mempool_print_slots(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071EB4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80071EB8: lw          $v1, 0x3B40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3B40);
    // 0x80071EBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071EC0: bltz        $v1, L_80071F20
    if (SIGNED(ctx->r3) < 0) {
        // 0x80071EC4: addiu       $a0, $t6, 0x3B00
        ctx->r4 = ADD32(ctx->r14, 0X3B00);
            goto L_80071F20;
    }
    // 0x80071EC4: addiu       $a0, $t6, 0x3B00
    ctx->r4 = ADD32(ctx->r14, 0X3B00);
    // 0x80071EC8: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80071ECC: addu        $t0, $t7, $a0
    ctx->r8 = ADD32(ctx->r15, ctx->r4);
    // 0x80071ED0: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80071ED4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80071ED8:
    // 0x80071ED8: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80071EDC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80071EE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80071EE4:
    // 0x80071EE4: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    // 0x80071EE8: lh          $a3, 0xC($v0)
    ctx->r7 = MEM_H(ctx->r2, 0XC);
    // 0x80071EEC: beq         $a1, $zero, L_80071EF4
    if (ctx->r5 == 0) {
        // 0x80071EF0: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80071EF4;
    }
    // 0x80071EF0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
L_80071EF4:
    // 0x80071EF4: beq         $a2, $t3, L_80071F0C
    if (ctx->r6 == ctx->r11) {
        // 0x80071EF8: nop
    
            goto L_80071F0C;
    }
    // 0x80071EF8: nop

    // 0x80071EFC: multu       $a3, $t4
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071F00: mflo        $t8
    ctx->r24 = lo;
    // 0x80071F04: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x80071F08: nop

L_80071F0C:
    // 0x80071F0C: bne         $a2, $t3, L_80071EE4
    if (ctx->r6 != ctx->r11) {
        // 0x80071F10: nop
    
            goto L_80071EE4;
    }
    // 0x80071F10: nop

    // 0x80071F14: sltu        $at, $t0, $a0
    ctx->r1 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80071F18: beq         $at, $zero, L_80071ED8
    if (ctx->r1 == 0) {
        // 0x80071F1C: nop
    
            goto L_80071ED8;
    }
    // 0x80071F1C: nop

L_80071F20:
    // 0x80071F20: jr          $ra
    // 0x80071F24: nop

    return;
    // 0x80071F24: nop

;}
RECOMP_FUNC void func_8001E89C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E8D0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E8D4: addiu       $v0, $v0, -0x4C7F
    ctx->r2 = ADD32(ctx->r2, -0X4C7F);
    // 0x8001E8D8: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001E8DC: nop

    // 0x8001E8E0: beq         $t6, $zero, L_8001E8F0
    if (ctx->r14 == 0) {
        // 0x8001E8E4: nop
    
            goto L_8001E8F0;
    }
    // 0x8001E8E4: nop

    // 0x8001E8E8: jr          $ra
    // 0x8001E8EC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x8001E8EC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8001E8F0:
    // 0x8001E8F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E8F4: lb          $v1, -0x4C80($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X4C80);
    // 0x8001E8F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E8FC: blez        $v1, L_8001E968
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E900: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001E968;
    }
    // 0x8001E900: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001E904: addiu       $a1, $a1, -0x4CA8
    ctx->r5 = ADD32(ctx->r5, -0X4CA8);
L_8001E908:
    // 0x8001E908: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8001E90C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E910: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x8001E914: nop

    // 0x8001E918: lw          $a3, 0xC($a2)
    ctx->r7 = MEM_W(ctx->r6, 0XC);
    // 0x8001E91C: nop

    // 0x8001E920: beq         $a3, $zero, L_8001E960
    if (ctx->r7 == 0) {
        // 0x8001E924: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E960;
    }
    // 0x8001E924: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E928: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001E92C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E930: swc1        $f4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f4.u32l;
    // 0x8001E934: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x8001E938: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001E93C: nop

    // 0x8001E940: swc1        $f6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f6.u32l;
    // 0x8001E944: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x8001E948: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8001E94C: nop

    // 0x8001E950: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
    // 0x8001E954: lb          $v1, -0x4C80($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X4C80);
    // 0x8001E958: nop

    // 0x8001E95C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E960:
    // 0x8001E960: bne         $at, $zero, L_8001E908
    if (ctx->r1 != 0) {
        // 0x8001E964: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001E908;
    }
    // 0x8001E964: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001E968:
    // 0x8001E968: jr          $ra
    // 0x8001E96C: nop

    return;
    // 0x8001E96C: nop

;}
RECOMP_FUNC void obj_door_override(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800235F4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800235F8: lb          $v0, -0x4CAB($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4CAB);
    // 0x800235FC: jr          $ra
    // 0x80023600: nop

    return;
    // 0x80023600: nop

;}
RECOMP_FUNC void obj_init_exit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038E7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80038E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038E84: lbu         $t7, 0x10($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X10);
    // 0x80038E88: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80038E8C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80038E90: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80038E94: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80038E98: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80038E9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038EA0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80038EA4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80038EA8: bc1f        L_80038EB8
    if (!c1cs) {
        // 0x80038EAC: nop
    
            goto L_80038EB8;
    }
    // 0x80038EAC: nop

    // 0x80038EB0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80038EB4: nop

L_80038EB8:
    // 0x80038EB8: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80038EBC: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80038EC0: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x80038EC4: lbu         $t9, 0x11($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X11);
    // 0x80038EC8: nop

    // 0x80038ECC: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x80038ED0: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x80038ED4: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80038ED8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80038EDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80038EE0: jal         0x80070A04
    // 0x80038EE4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x80038EE4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80038EE8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80038EEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80038EF0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80038EF4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80038EF8: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80038EFC: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80038F00: jal         0x80070A38
    // 0x80038F04: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x80038F04: nop

    after_1:
    // 0x80038F08: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80038F0C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80038F10: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80038F14: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80038F18: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80038F1C: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80038F20: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80038F24: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80038F28: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80038F2C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80038F30: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80038F34: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80038F38: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80038F3C: lbu         $t1, 0x10($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X10);
    // 0x80038F40: nop

    // 0x80038F44: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x80038F48: lb          $t2, 0x18($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X18);
    // 0x80038F4C: nop

    // 0x80038F50: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
    // 0x80038F54: lw          $t4, 0x4C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F58: nop

    // 0x80038F5C: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x80038F60: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F64: nop

    // 0x80038F68: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x80038F6C: lw          $t7, 0x4C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F70: lbu         $t6, 0x10($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X10);
    // 0x80038F74: nop

    // 0x80038F78: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x80038F7C: lw          $t8, 0x4C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F80: nop

    // 0x80038F84: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x80038F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038F8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80038F90: jr          $ra
    // 0x80038F94: nop

    return;
    // 0x80038F94: nop

;}
RECOMP_FUNC void waves_get_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF4E4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BF4E8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BF4EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800BF4F0: lw          $t6, 0x3718($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3718);
    // 0x800BF4F4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x800BF4F8: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x800BF4FC: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800BF500: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x800BF504: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800BF508: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800BF50C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800BF510: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x800BF514: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x800BF518: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x800BF51C: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x800BF520: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800BF524: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x800BF528: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800BF52C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800BF530: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BF534: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800BF538: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BF53C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800BF540: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BF544: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800BF548: bgtz        $t6, L_800BF558
    if (SIGNED(ctx->r14) > 0) {
        // 0x800BF54C: mov.s       $f28, $f2
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
            goto L_800BF558;
    }
    // 0x800BF54C: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
    // 0x800BF550: b           L_800BF8B0
    // 0x800BF554: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800BF8B0;
    // 0x800BF554: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800BF558:
    // 0x800BF558: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BF55C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF560: addiu       $v0, $v0, -0x5A78
    ctx->r2 = ADD32(ctx->r2, -0X5A78);
    // 0x800BF564: lwc1        $f0, -0x5988($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BF568: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x800BF56C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF570: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800BF574: lwc1        $f2, -0x5984($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5984);
    // 0x800BF578: beq         $t7, $zero, L_800BF59C
    if (ctx->r15 == 0) {
        // 0x800BF57C: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800BF59C;
    }
    // 0x800BF57C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BF580: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BF584: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800BF588: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800BF58C: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800BF590: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800BF594: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800BF598: nop

L_800BF59C:
    // 0x800BF59C: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x800BF5A0: lw          $t9, 0x3668($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3668);
    // 0x800BF5A4: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800BF5A8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BF5AC: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x800BF5B0: lbu         $t1, 0xA($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0XA);
    // 0x800BF5B4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BF5B8: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BF5BC: lw          $t4, 0x3714($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3714);
    // 0x800BF5C0: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x800BF5C4: mflo        $t2
    ctx->r10 = lo;
    // 0x800BF5C8: addu        $a1, $t2, $s0
    ctx->r5 = ADD32(ctx->r10, ctx->r16);
    // 0x800BF5CC: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x800BF5D0: addu        $a3, $t3, $t4
    ctx->r7 = ADD32(ctx->r11, ctx->r12);
    // 0x800BF5D4: lbu         $t5, 0x0($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X0);
    // 0x800BF5D8: nop

    // 0x800BF5DC: beq         $s5, $t5, L_800BF8AC
    if (ctx->r21 == ctx->r13) {
        // 0x800BF5E0: nop
    
            goto L_800BF8AC;
    }
    // 0x800BF5E0: nop

    // 0x800BF5E4: lbu         $t6, 0xB($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XB);
    // 0x800BF5E8: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800BF5EC: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BF5F0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BF5F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BF5F8: lw          $t8, -0x5970($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5970);
    // 0x800BF5FC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BF600: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BF604: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BF608: lw          $t9, -0x596C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X596C);
    // 0x800BF60C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800BF610: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800BF614: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BF618: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800BF61C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BF620: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x800BF624: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800BF628: add.s       $f30, $f6, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800BF62C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800BF630: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BF634: addiu       $s4, $s4, 0x3720
    ctx->r20 = ADD32(ctx->r20, 0X3720);
    // 0x800BF638: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800BF63C: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800BF640: andi        $v0, $t5, 0xFF
    ctx->r2 = ctx->r13 & 0XFF;
    // 0x800BF644: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BF648: add.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f6.fl;
L_800BF64C:
    // 0x800BF64C: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x800BF650: sll         $t0, $v0, 6
    ctx->r8 = S32(ctx->r2 << 6);
    // 0x800BF654: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    // 0x800BF658: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BF65C: nop

    // 0x800BF660: c.le.s      $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f16.fl <= ctx->f24.fl;
    // 0x800BF664: nop

    // 0x800BF668: bc1f        L_800BF88C
    if (!c1cs) {
        // 0x800BF66C: nop
    
            goto L_800BF88C;
    }
    // 0x800BF66C: nop

    // 0x800BF670: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800BF674: nop

    // 0x800BF678: c.le.s      $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f24.fl <= ctx->f18.fl;
    // 0x800BF67C: nop

    // 0x800BF680: bc1f        L_800BF88C
    if (!c1cs) {
        // 0x800BF684: nop
    
            goto L_800BF88C;
    }
    // 0x800BF684: nop

    // 0x800BF688: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800BF68C: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800BF690: sub.s       $f20, $f30, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f30.fl - ctx->f8.fl;
    // 0x800BF694: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800BF698: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800BF69C: sub.s       $f22, $f24, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x800BF6A0: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800BF6A4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BF6A8: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x800BF6AC: nop

    // 0x800BF6B0: bc1f        L_800BF88C
    if (!c1cs) {
        // 0x800BF6B4: nop
    
            goto L_800BF88C;
    }
    // 0x800BF6B4: nop

    // 0x800BF6B8: jal         0x800CA030
    // 0x800BF6BC: nop

    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800BF6BC: nop

    after_0:
    // 0x800BF6C0: lbu         $t2, 0x30($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X30);
    // 0x800BF6C4: lhu         $s0, 0x1A($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X1A);
    // 0x800BF6C8: beq         $t2, $zero, L_800BF750
    if (ctx->r10 == 0) {
        // 0x800BF6CC: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800BF750;
    }
    // 0x800BF6CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800BF6D0: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800BF6D4: nop

    // 0x800BF6D8: bc1f        L_800BF718
    if (!c1cs) {
        // 0x800BF6DC: nop
    
            goto L_800BF718;
    }
    // 0x800BF6DC: nop

    // 0x800BF6E0: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF6E4: nop

    // 0x800BF6E8: mul.s       $f8, $f20, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800BF6EC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800BF6F0: nop

    // 0x800BF6F4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800BF6F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF6FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF700: nop

    // 0x800BF704: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BF708: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800BF70C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800BF710: b           L_800BF818
    // 0x800BF714: subu        $s0, $s0, $t4
    ctx->r16 = SUB32(ctx->r16, ctx->r12);
        goto L_800BF818;
    // 0x800BF714: subu        $s0, $s0, $t4
    ctx->r16 = SUB32(ctx->r16, ctx->r12);
L_800BF718:
    // 0x800BF718: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF71C: nop

    // 0x800BF720: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800BF724: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800BF728: nop

    // 0x800BF72C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800BF730: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF734: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF738: nop

    // 0x800BF73C: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BF740: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800BF744: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800BF748: b           L_800BF818
    // 0x800BF74C: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
        goto L_800BF818;
    // 0x800BF74C: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_800BF750:
    // 0x800BF750: lbu         $t7, 0x31($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X31);
    // 0x800BF754: nop

    // 0x800BF758: beq         $t7, $zero, L_800BF7E0
    if (ctx->r15 == 0) {
        // 0x800BF75C: nop
    
            goto L_800BF7E0;
    }
    // 0x800BF75C: nop

    // 0x800BF760: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800BF764: nop

    // 0x800BF768: bc1f        L_800BF7A8
    if (!c1cs) {
        // 0x800BF76C: nop
    
            goto L_800BF7A8;
    }
    // 0x800BF76C: nop

    // 0x800BF770: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF774: nop

    // 0x800BF778: mul.s       $f8, $f22, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x800BF77C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BF780: nop

    // 0x800BF784: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BF788: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF78C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF790: nop

    // 0x800BF794: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BF798: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BF79C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BF7A0: b           L_800BF818
    // 0x800BF7A4: subu        $s0, $s0, $t9
    ctx->r16 = SUB32(ctx->r16, ctx->r25);
        goto L_800BF818;
    // 0x800BF7A4: subu        $s0, $s0, $t9
    ctx->r16 = SUB32(ctx->r16, ctx->r25);
L_800BF7A8:
    // 0x800BF7A8: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF7AC: nop

    // 0x800BF7B0: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x800BF7B4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800BF7B8: nop

    // 0x800BF7BC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800BF7C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF7C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF7C8: nop

    // 0x800BF7CC: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BF7D0: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x800BF7D4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800BF7D8: b           L_800BF818
    // 0x800BF7DC: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
        goto L_800BF818;
    // 0x800BF7DC: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
L_800BF7E0:
    // 0x800BF7E0: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF7E4: nop

    // 0x800BF7E8: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800BF7EC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800BF7F0: nop

    // 0x800BF7F4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800BF7F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF7FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF800: nop

    // 0x800BF804: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BF808: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800BF80C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800BF810: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x800BF814: nop

L_800BF818:
    // 0x800BF818: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800BF81C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BF820: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800BF824: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800BF828: nop

    // 0x800BF82C: div.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BF830: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BF834: nop

    // 0x800BF838: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BF83C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF840: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF844: nop

    // 0x800BF848: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800BF84C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800BF850: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BF854: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800BF858: jal         0x80070A38
    // 0x800BF85C: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800BF85C: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_1:
    // 0x800BF860: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800BF864: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800BF868: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800BF86C: jal         0x80070A04
    // 0x800BF870: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x800BF870: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x800BF874: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800BF878: nop

    // 0x800BF87C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BF880: nop

    // 0x800BF884: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800BF888: add.s       $f28, $f28, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f6.fl;
L_800BF88C:
    // 0x800BF88C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800BF890: slti        $at, $s3, 0x8
    ctx->r1 = SIGNED(ctx->r19) < 0X8 ? 1 : 0;
    // 0x800BF894: beq         $at, $zero, L_800BF8AC
    if (ctx->r1 == 0) {
        // 0x800BF898: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800BF8AC;
    }
    // 0x800BF898: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BF89C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800BF8A0: nop

    // 0x800BF8A4: bne         $s5, $v0, L_800BF64C
    if (ctx->r21 != ctx->r2) {
        // 0x800BF8A8: nop
    
            goto L_800BF64C;
    }
    // 0x800BF8A8: nop

L_800BF8AC:
    // 0x800BF8AC: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_800BF8B0:
    // 0x800BF8B0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800BF8B4: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800BF8B8: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BF8BC: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BF8C0: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BF8C4: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BF8C8: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BF8CC: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BF8D0: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BF8D4: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BF8D8: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BF8DC: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800BF8E0: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BF8E4: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x800BF8E8: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x800BF8EC: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x800BF8F0: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x800BF8F4: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x800BF8F8: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x800BF8FC: jr          $ra
    // 0x800BF900: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BF900: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void debug_text_width(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6954: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x800B6958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B695C: sw          $a0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r4;
    // 0x800B6960: sw          $a1, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r5;
    // 0x800B6964: sw          $a2, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r6;
    // 0x800B6968: sw          $a3, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r7;
    // 0x800B696C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800B6970: jal         0x800B4F68
    // 0x800B6974: sw          $zero, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = 0;
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_0;
    // 0x800B6974: sw          $zero, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = 0;
    after_0:
    // 0x800B6978: lw          $a1, 0x138($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X138);
    // 0x800B697C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800B6980: jal         0x800B4FA0
    // 0x800B6984: addiu       $a2, $sp, 0x13C
    ctx->r6 = ADD32(ctx->r29, 0X13C);
    vsprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B6984: addiu       $a2, $sp, 0x13C
    ctx->r6 = ADD32(ctx->r29, 0X13C);
    after_1:
    // 0x800B6988: jal         0x800B4F68
    // 0x800B698C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_2;
    // 0x800B698C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800B6990: lbu         $t7, 0x2C($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2C);
    // 0x800B6994: lw          $a3, 0x12C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X12C);
    // 0x800B6998: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x800B699C: beq         $t7, $zero, L_800B6A8C
    if (ctx->r15 == 0) {
        // 0x800B69A0: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800B6A8C;
    }
    // 0x800B69A0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800B69A4: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x800B69A8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B69AC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B69B0: addiu       $a2, $a2, -0x7D74
    ctx->r6 = ADD32(ctx->r6, -0X7D74);
    // 0x800B69B4: addiu       $t2, $t2, 0x3484
    ctx->r10 = ADD32(ctx->r10, 0X3484);
    // 0x800B69B8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800B69BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B69C0: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x800B69C4: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x800B69C8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800B69CC:
    // 0x800B69CC: beq         $v0, $t0, L_800B6A7C
    if (ctx->r2 == ctx->r8) {
        // 0x800B69D0: nop
    
            goto L_800B6A7C;
    }
    // 0x800B69D0: nop

    // 0x800B69D4: bne         $v0, $t1, L_800B69E4
    if (ctx->r2 != ctx->r9) {
        // 0x800B69D8: slti        $at, $v0, 0x40
        ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
            goto L_800B69E4;
    }
    // 0x800B69D8: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x800B69DC: b           L_800B6A7C
    // 0x800B69E0: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
        goto L_800B6A7C;
    // 0x800B69E0: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
L_800B69E4:
    // 0x800B69E4: beq         $at, $zero, L_800B6A0C
    if (ctx->r1 == 0) {
        // 0x800B69E8: slti        $at, $v0, 0x60
        ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
            goto L_800B6A0C;
    }
    // 0x800B69E8: slti        $at, $v0, 0x60
    ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
    // 0x800B69EC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800B69F0: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x800B69F4: nop

    // 0x800B69F8: addiu       $t9, $t8, -0x21
    ctx->r25 = ADD32(ctx->r24, -0X21);
    // 0x800B69FC: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x800B6A00: b           L_800B6A54
    // 0x800B6A04: andi        $a1, $t9, 0xFF
    ctx->r5 = ctx->r25 & 0XFF;
        goto L_800B6A54;
    // 0x800B6A04: andi        $a1, $t9, 0xFF
    ctx->r5 = ctx->r25 & 0XFF;
    // 0x800B6A08: slti        $at, $v0, 0x60
    ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
L_800B6A0C:
    // 0x800B6A0C: beq         $at, $zero, L_800B6A34
    if (ctx->r1 == 0) {
        // 0x800B6A10: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_800B6A34;
    }
    // 0x800B6A10: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800B6A14: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800B6A18: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x800B6A1C: nop

    // 0x800B6A20: addiu       $t7, $t5, -0x40
    ctx->r15 = ADD32(ctx->r13, -0X40);
    // 0x800B6A24: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x800B6A28: b           L_800B6A54
    // 0x800B6A2C: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
        goto L_800B6A54;
    // 0x800B6A2C: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    // 0x800B6A30: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
L_800B6A34:
    // 0x800B6A34: beq         $at, $zero, L_800B6A54
    if (ctx->r1 == 0) {
        // 0x800B6A38: nop
    
            goto L_800B6A54;
    }
    // 0x800B6A38: nop

    // 0x800B6A3C: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800B6A40: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800B6A44: nop

    // 0x800B6A48: addiu       $t8, $t6, -0x60
    ctx->r24 = ADD32(ctx->r14, -0X60);
    // 0x800B6A4C: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x800B6A50: andi        $a1, $t8, 0xFF
    ctx->r5 = ctx->r24 & 0XFF;
L_800B6A54:
    // 0x800B6A54: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B6A58: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800B6A5C: sll         $t5, $t9, 6
    ctx->r13 = S32(ctx->r25 << 6);
    // 0x800B6A60: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x800B6A64: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x800B6A68: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800B6A6C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800B6A70: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800B6A74: subu        $a3, $t9, $a0
    ctx->r7 = SUB32(ctx->r25, ctx->r4);
    // 0x800B6A78: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800B6A7C:
    // 0x800B6A7C: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    // 0x800B6A80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B6A84: bne         $a1, $zero, L_800B69CC
    if (ctx->r5 != 0) {
        // 0x800B6A88: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800B69CC;
    }
    // 0x800B6A88: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800B6A8C:
    // 0x800B6A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6A90: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // 0x800B6A94: jr          $ra
    // 0x800B6A98: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800B6A98: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
;}
RECOMP_FUNC void transition_init_blank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2B60: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C2B64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C2B68: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C2B6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C2B70: addiu       $a1, $a1, -0x5300
    ctx->r5 = ADD32(ctx->r5, -0X5300);
    // 0x800C2B74: addiu       $v1, $v1, -0x5308
    ctx->r3 = ADD32(ctx->r3, -0X5308);
    // 0x800C2B78: addiu       $a0, $a0, -0x5304
    ctx->r4 = ADD32(ctx->r4, -0X5304);
    // 0x800C2B7C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C2B80: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800C2B84: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800C2B88: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800C2B8C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C2B90: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800C2B94: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C2B98: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C2B9C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x800C2BA0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C2BA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2BA8: sb          $t2, -0x5309($at)
    MEM_B(-0X5309, ctx->r1) = ctx->r10;
    // 0x800C2BAC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C2BB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C2BB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2BB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C2BBC: swc1        $f4, -0x52F0($at)
    MEM_W(-0X52F0, ctx->r1) = ctx->f4.u32l;
    // 0x800C2BC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2BC4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C2BC8: lbu         $t3, -0x530C($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X530C);
    // 0x800C2BCC: swc1        $f6, -0x52EC($at)
    MEM_W(-0X52EC, ctx->r1) = ctx->f6.u32l;
    // 0x800C2BD0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C2BD4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C2BD8: lhu         $v0, 0x3740($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X3740);
    // 0x800C2BDC: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800C2BE0: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800C2BE4: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800C2BE8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C2BEC: bne         $v0, $zero, L_800C2BF8
    if (ctx->r2 != 0) {
        // 0x800C2BF0: nop
    
            goto L_800C2BF8;
    }
    // 0x800C2BF0: nop

    // 0x800C2BF4: break       7
    do_break(2148281332);
L_800C2BF8:
    // 0x800C2BF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C2BFC: bne         $v0, $at, L_800C2C10
    if (ctx->r2 != ctx->r1) {
        // 0x800C2C00: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C2C10;
    }
    // 0x800C2C00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C2C04: bne         $t6, $at, L_800C2C10
    if (ctx->r14 != ctx->r1) {
        // 0x800C2C08: nop
    
            goto L_800C2C10;
    }
    // 0x800C2C08: nop

    // 0x800C2C0C: break       6
    do_break(2148281356);
L_800C2C10:
    // 0x800C2C10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2C14: lbu         $t8, -0x530B($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X530B);
    // 0x800C2C18: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C2C1C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C2C20: lbu         $t3, -0x530A($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X530A);
    // 0x800C2C24: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C2C28: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800C2C2C: mflo        $t7
    ctx->r15 = lo;
    // 0x800C2C30: sw          $t7, -0x52FC($at)
    MEM_W(-0X52FC, ctx->r1) = ctx->r15;
    // 0x800C2C34: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800C2C38: nop

    // 0x800C2C3C: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800C2C40: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800C2C44: bne         $v0, $zero, L_800C2C50
    if (ctx->r2 != 0) {
        // 0x800C2C48: nop
    
            goto L_800C2C50;
    }
    // 0x800C2C48: nop

    // 0x800C2C4C: break       7
    do_break(2148281420);
L_800C2C50:
    // 0x800C2C50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C2C54: bne         $v0, $at, L_800C2C68
    if (ctx->r2 != ctx->r1) {
        // 0x800C2C58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C2C68;
    }
    // 0x800C2C58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C2C5C: bne         $t1, $at, L_800C2C68
    if (ctx->r9 != ctx->r1) {
        // 0x800C2C60: nop
    
            goto L_800C2C68;
    }
    // 0x800C2C60: nop

    // 0x800C2C64: break       6
    do_break(2148281444);
L_800C2C68:
    // 0x800C2C68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2C6C: mflo        $t2
    ctx->r10 = lo;
    // 0x800C2C70: sw          $t2, -0x52F8($at)
    MEM_W(-0X52F8, ctx->r1) = ctx->r10;
    // 0x800C2C74: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800C2C78: nop

    // 0x800C2C7C: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800C2C80: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800C2C84: bne         $v0, $zero, L_800C2C90
    if (ctx->r2 != 0) {
        // 0x800C2C88: nop
    
            goto L_800C2C90;
    }
    // 0x800C2C88: nop

    // 0x800C2C8C: break       7
    do_break(2148281484);
L_800C2C90:
    // 0x800C2C90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C2C94: bne         $v0, $at, L_800C2CA8
    if (ctx->r2 != ctx->r1) {
        // 0x800C2C98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C2CA8;
    }
    // 0x800C2C98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C2C9C: bne         $t6, $at, L_800C2CA8
    if (ctx->r14 != ctx->r1) {
        // 0x800C2CA0: nop
    
            goto L_800C2CA8;
    }
    // 0x800C2CA0: nop

    // 0x800C2CA4: break       6
    do_break(2148281508);
L_800C2CA8:
    // 0x800C2CA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2CAC: mflo        $t7
    ctx->r15 = lo;
    // 0x800C2CB0: sw          $t7, -0x52F4($at)
    MEM_W(-0X52F4, ctx->r1) = ctx->r15;
    // 0x800C2CB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2CB8: jr          $ra
    // 0x800C2CBC: sw          $t8, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r24;
    return;
    // 0x800C2CBC: sw          $t8, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void trackmenu_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090DD0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80090DD4: lw          $v1, -0x604($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X604);
    // 0x80090DD8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80090DDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80090DE0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80090DE4: blez        $v1, L_80091004
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80090DE8: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_80091004;
    }
    // 0x80090DE8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80090DEC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80090DF0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80090DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090DF8: lwc1        $f4, 0x6FA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FA8);
    // 0x80090DFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090E00: lwc1        $f6, 0x6F9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F9C);
    // 0x80090E04: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80090E08: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80090E0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80090E10: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80090E14: nop

    // 0x80090E18: bc1t        L_80090E68
    if (c1cs) {
        // 0x80090E1C: nop
    
            goto L_80090E68;
    }
    // 0x80090E1C: nop

    // 0x80090E20: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80090E24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090E28: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80090E2C: nop

    // 0x80090E30: bc1t        L_80090E68
    if (c1cs) {
        // 0x80090E34: nop
    
            goto L_80090E68;
    }
    // 0x80090E34: nop

    // 0x80090E38: lwc1        $f8, 0x6FAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FAC);
    // 0x80090E3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090E40: lwc1        $f10, 0x6FA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x80090E44: nop

    // 0x80090E48: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80090E4C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80090E50: nop

    // 0x80090E54: bc1t        L_80090E68
    if (c1cs) {
        // 0x80090E58: nop
    
            goto L_80090E68;
    }
    // 0x80090E58: nop

    // 0x80090E5C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80090E60: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80090E64: bc1f        L_80090E78
    if (!c1cs) {
        // 0x80090E68: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80090E78;
    }
L_80090E68:
    // 0x80090E68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80090E6C: sw          $t6, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r14;
    // 0x80090E70: b           L_80090EA0
    // 0x80090E74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80090EA0;
    // 0x80090E74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80090E78:
    // 0x80090E78: lw          $t7, 0x239C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X239C);
    // 0x80090E7C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80090E80: beq         $t7, $zero, L_80090EA4
    if (ctx->r15 == 0) {
        // 0x80090E84: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80090EA4;
    }
    // 0x80090E84: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80090E88: jal         0x80001D04
    // 0x80090E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80090E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80090E90: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80090E94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80090E98: lw          $v1, -0x604($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X604);
    // 0x80090E9C: sw          $zero, 0x239C($at)
    MEM_W(0X239C, ctx->r1) = 0;
L_80090EA0:
    // 0x80090EA0: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_80090EA4:
    // 0x80090EA4: slti        $at, $t1, 0x15
    ctx->r1 = SIGNED(ctx->r9) < 0X15 ? 1 : 0;
    // 0x80090EA8: bne         $at, $zero, L_80090EB4
    if (ctx->r1 != 0) {
        // 0x80090EAC: addiu       $t2, $zero, 0xA0
        ctx->r10 = ADD32(0, 0XA0);
            goto L_80090EB4;
    }
    // 0x80090EAC: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x80090EB0: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
L_80090EB4:
    // 0x80090EB4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80090EB8: lw          $t4, 0x6A18($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6A18);
    // 0x80090EBC: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x80090EC0: beq         $at, $zero, L_80090F54
    if (ctx->r1 == 0) {
        // 0x80090EC4: or          $t0, $t4, $zero
        ctx->r8 = ctx->r12 | 0;
            goto L_80090F54;
    }
    // 0x80090EC4: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x80090EC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090ECC: lwc1        $f16, 0x6FA8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6FA8);
    // 0x80090ED0: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x80090ED4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80090ED8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090EDC: lwc1        $f18, 0x6F9C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6F9C);
    // 0x80090EE0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80090EE4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80090EE8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80090EEC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80090EF0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80090EF4: nop

    // 0x80090EF8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80090EFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80090F00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090F04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090F08: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80090F0C: lwc1        $f18, 0x6FAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6FAC);
    // 0x80090F10: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80090F14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090F18: lwc1        $f6, 0x6FA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x80090F1C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090F20: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x80090F24: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80090F28: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80090F2C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80090F30: nop

    // 0x80090F34: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80090F38: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80090F3C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090F40: nop

    // 0x80090F44: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80090F48: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80090F4C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80090F50: nop

L_80090F54:
    // 0x80090F54: addiu       $t6, $t1, 0x14
    ctx->r14 = ADD32(ctx->r9, 0X14);
    // 0x80090F58: multu       $t6, $t4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80090F5C: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80090F60: sll         $v1, $t1, 2
    ctx->r3 = S32(ctx->r9 << 2);
    // 0x80090F64: subu        $a1, $t2, $v1
    ctx->r5 = SUB32(ctx->r10, ctx->r3);
    // 0x80090F68: addu        $a3, $v1, $t2
    ctx->r7 = ADD32(ctx->r3, ctx->r10);
    // 0x80090F6C: addiu       $a3, $a3, 0x50
    ctx->r7 = ADD32(ctx->r7, 0X50);
    // 0x80090F70: addiu       $a1, $a1, -0x50
    ctx->r5 = ADD32(ctx->r5, -0X50);
    // 0x80090F74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80090F78: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80090F7C: mflo        $v0
    ctx->r2 = lo;
    // 0x80090F80: nop

    // 0x80090F84: nop

    // 0x80090F88: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80090F8C: mflo        $t7
    ctx->r15 = lo;
    // 0x80090F90: addu        $t3, $t7, $t0
    ctx->r11 = ADD32(ctx->r15, ctx->r8);
    // 0x80090F94: subu        $a2, $t0, $t7
    ctx->r6 = SUB32(ctx->r8, ctx->r15);
    // 0x80090F98: jal         0x80066B80
    // 0x80090F9C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    viewport_menu_set(rdram, ctx);
        goto after_1;
    // 0x80090F9C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_1:
    // 0x80090FA0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80090FA4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80090FA8: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80090FAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80090FB0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80090FB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80090FB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80090FBC: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80090FC0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80090FC4: addiu       $v1, $v1, -0x570
    ctx->r3 = ADD32(ctx->r3, -0X570);
    // 0x80090FC8: lwc1        $f18, 0x88($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80090FCC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80090FD0: addiu       $v0, $v0, -0x324
    ctx->r2 = ADD32(ctx->r2, -0X324);
    // 0x80090FD4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80090FD8: add.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80090FDC: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80090FE0: swc1        $f6, 0x88($t8)
    MEM_W(0X88, ctx->r24) = ctx->f6.u32l;
    // 0x80090FE4: lwc1        $f4, 0xC8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x80090FE8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80090FEC: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80090FF0: swc1        $f10, 0xC8($t9)
    MEM_W(0XC8, ctx->r25) = ctx->f10.u32l;
    // 0x80090FF4: lwc1        $f16, 0xA8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XA8);
    // 0x80090FF8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80090FFC: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80091000: swc1        $f8, 0xA8($t5)
    MEM_W(0XA8, ctx->r13) = ctx->f8.u32l;
L_80091004:
    // 0x80091004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80091008: jal         0x80066A58
    // 0x8009100C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camEnableUserView(rdram, ctx);
        goto after_2;
    // 0x8009100C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80091010: jal         0x800C7940
    // 0x80091014: nop

    bgload_active(rdram, ctx);
        goto after_3;
    // 0x80091014: nop

    after_3:
    // 0x80091018: bne         $v0, $zero, L_80091160
    if (ctx->r2 != 0) {
        // 0x8009101C: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80091160;
    }
    // 0x8009101C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80091020: lw          $v1, -0x604($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X604);
    // 0x80091024: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80091028: bgez        $v1, L_8009104C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009102C: addiu       $t2, $t2, 0x6F88
        ctx->r10 = ADD32(ctx->r10, 0X6F88);
            goto L_8009104C;
    }
    // 0x8009102C: addiu       $t2, $t2, 0x6F88
    ctx->r10 = ADD32(ctx->r10, 0X6F88);
    // 0x80091030: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80091034: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80091038: addiu       $v0, $v0, -0x320
    ctx->r2 = ADD32(ctx->r2, -0X320);
    // 0x8009103C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80091040: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80091044: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x80091048: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8009104C:
    // 0x8009104C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80091050: lw          $t7, 0x6FB4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6FB4);
    // 0x80091054: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80091058: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009105C: bne         $t5, $t7, L_8009109C
    if (ctx->r13 != ctx->r15) {
        // 0x80091060: addiu       $a3, $a3, 0x6F8C
        ctx->r7 = ADD32(ctx->r7, 0X6F8C);
            goto L_8009109C;
    }
    // 0x80091060: addiu       $a3, $a3, 0x6F8C
    ctx->r7 = ADD32(ctx->r7, 0X6F8C);
    // 0x80091064: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80091068: lw          $t8, 0x6FB8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6FB8);
    // 0x8009106C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80091070: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80091074: bne         $t6, $t8, L_8009109C
    if (ctx->r14 != ctx->r24) {
        // 0x80091078: addiu       $v0, $v0, 0x6978
        ctx->r2 = ADD32(ctx->r2, 0X6978);
            goto L_8009109C;
    }
    // 0x80091078: addiu       $v0, $v0, 0x6978
    ctx->r2 = ADD32(ctx->r2, 0X6978);
    // 0x8009107C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80091080: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80091084: nop

    // 0x80091088: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x8009108C: bgez        $t7, L_800910C4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80091090: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_800910C4;
    }
    // 0x80091090: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80091094: b           L_800910C4
    // 0x80091098: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_800910C4;
    // 0x80091098: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8009109C:
    // 0x8009109C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800910A0: addiu       $v0, $v0, 0x6978
    ctx->r2 = ADD32(ctx->r2, 0X6978);
    // 0x800910A4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800910A8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800910AC: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800910B0: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x800910B4: slti        $at, $t5, 0x21
    ctx->r1 = SIGNED(ctx->r13) < 0X21 ? 1 : 0;
    // 0x800910B8: bne         $at, $zero, L_800910C4
    if (ctx->r1 != 0) {
        // 0x800910BC: sw          $t5, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r13;
            goto L_800910C4;
    }
    // 0x800910BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800910C0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800910C4:
    // 0x800910C4: slti        $at, $v1, -0x16
    ctx->r1 = SIGNED(ctx->r3) < -0X16 ? 1 : 0;
    // 0x800910C8: beq         $at, $zero, L_800910EC
    if (ctx->r1 == 0) {
        // 0x800910CC: slti        $at, $v1, 0x1F
        ctx->r1 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
            goto L_800910EC;
    }
    // 0x800910CC: slti        $at, $v1, 0x1F
    ctx->r1 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
    // 0x800910D0: jal         0x80078EFC
    // 0x800910D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    bgdraw_set_func(rdram, ctx);
        goto after_4;
    // 0x800910D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800910D8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800910DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800910E0: lw          $v1, -0x604($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X604);
    // 0x800910E4: sw          $zero, 0xEFC($at)
    MEM_W(0XEFC, ctx->r1) = 0;
    // 0x800910E8: slti        $at, $v1, 0x1F
    ctx->r1 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
L_800910EC:
    // 0x800910EC: bne         $at, $zero, L_8009113C
    if (ctx->r1 != 0) {
        // 0x800910F0: slti        $at, $v1, -0x1E
        ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
            goto L_8009113C;
    }
    // 0x800910F0: slti        $at, $v1, -0x1E
    ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
    // 0x800910F4: jal         0x8009F1A4
    // 0x800910F8: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_5;
    // 0x800910F8: nop

    after_5:
    // 0x800910FC: beq         $v0, $zero, L_80091120
    if (ctx->r2 == 0) {
        // 0x80091100: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80091120;
    }
    // 0x80091100: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80091104: lw          $t8, 0x6F88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6F88);
    // 0x80091108: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009110C: beq         $t8, $at, L_80091120
    if (ctx->r24 == ctx->r1) {
        // 0x80091110: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_80091120;
    }
    // 0x80091110: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80091114: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80091118: b           L_80091128
    // 0x8009111C: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
        goto L_80091128;
    // 0x8009111C: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
L_80091120:
    // 0x80091120: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80091124: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
L_80091128:
    // 0x80091128: jal         0x8008F4C4
    // 0x8009112C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    trackmenu_assets(rdram, ctx);
        goto after_6;
    // 0x8009112C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80091130: b           L_80091164
    // 0x80091134: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
        goto L_80091164;
    // 0x80091134: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80091138: slti        $at, $v1, -0x1E
    ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
L_8009113C:
    // 0x8009113C: beq         $at, $zero, L_80091164
    if (ctx->r1 == 0) {
        // 0x80091140: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_80091164;
    }
    // 0x80091140: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80091144: jal         0x800C06A0
    // 0x80091148: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_7;
    // 0x80091148: nop

    after_7:
    // 0x8009114C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80091150: jal         0x80066AD4
    // 0x80091154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_8;
    // 0x80091154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80091158: jal         0x8008F4C4
    // 0x8009115C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    trackmenu_assets(rdram, ctx);
        goto after_9;
    // 0x8009115C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_9:
L_80091160:
    // 0x80091160: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_80091164:
    // 0x80091164: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80091168: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009116C: addiu       $t2, $t2, 0x6F88
    ctx->r10 = ADD32(ctx->r10, 0X6F88);
    // 0x80091170: bne         $t5, $zero, L_80091380
    if (ctx->r13 != 0) {
        // 0x80091174: addiu       $a3, $a3, 0x6F8C
        ctx->r7 = ADD32(ctx->r7, 0X6F8C);
            goto L_80091380;
    }
    // 0x80091174: addiu       $a3, $a3, 0x6F8C
    ctx->r7 = ADD32(ctx->r7, 0X6F8C);
    // 0x80091178: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009117C: lh          $t7, 0x6ED8($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6ED8);
    // 0x80091180: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80091184: bne         $v1, $t7, L_80091194
    if (ctx->r3 != ctx->r15) {
        // 0x80091188: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80091194;
    }
    // 0x80091188: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009118C: b           L_80091198
    // 0x80091190: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80091198;
    // 0x80091190: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80091194:
    // 0x80091194: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80091198:
    // 0x80091198: lw          $v0, 0x6D88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D88);
    // 0x8009119C: nop

    // 0x800911A0: andi        $t6, $v0, 0x9000
    ctx->r14 = ctx->r2 & 0X9000;
    // 0x800911A4: beq         $t6, $zero, L_800911F0
    if (ctx->r14 == 0) {
        // 0x800911A8: andi        $t5, $v0, 0x4000
        ctx->r13 = ctx->r2 & 0X4000;
            goto L_800911F0;
    }
    // 0x800911A8: andi        $t5, $v0, 0x4000
    ctx->r13 = ctx->r2 & 0X4000;
    // 0x800911AC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800911B0: lw          $v0, -0x5BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5BC);
    // 0x800911B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800911B8: beq         $v1, $v0, L_800911E0
    if (ctx->r3 == ctx->r2) {
        // 0x800911BC: addiu       $a0, $zero, 0x6A
        ctx->r4 = ADD32(0, 0X6A);
            goto L_800911E0;
    }
    // 0x800911BC: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    // 0x800911C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800911C4: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
    // 0x800911C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800911CC: sw          $v0, -0x5AC($at)
    MEM_W(-0X5AC, ctx->r1) = ctx->r2;
    // 0x800911D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800911D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800911D8: b           L_80091380
    // 0x800911DC: sw          $t9, 0x239C($at)
    MEM_W(0X239C, ctx->r1) = ctx->r25;
        goto L_80091380;
    // 0x800911DC: sw          $t9, 0x239C($at)
    MEM_W(0X239C, ctx->r1) = ctx->r25;
L_800911E0:
    // 0x800911E0: jal         0x80001D04
    // 0x800911E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800911E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x800911E8: b           L_80091384
    // 0x800911EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80091384;
    // 0x800911EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800911F0:
    // 0x800911F0: beq         $t5, $zero, L_80091224
    if (ctx->r13 == 0) {
        // 0x800911F4: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80091224;
    }
    // 0x800911F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800911F8: jal         0x800C06A0
    // 0x800911FC: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_11;
    // 0x800911FC: nop

    after_11:
    // 0x80091200: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80091204: jal         0x800C06F8
    // 0x80091208: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_12;
    // 0x80091208: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_12:
    // 0x8009120C: jal         0x800C0690
    // 0x80091210: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_13;
    // 0x80091210: nop

    after_13:
    // 0x80091214: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80091218: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009121C: b           L_80091380
    // 0x80091220: sw          $t7, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r15;
        goto L_80091380;
    // 0x80091220: sw          $t7, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r15;
L_80091224:
    // 0x80091224: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80091228: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8009122C: lh          $a0, 0x6DC0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6DC0);
    // 0x80091230: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80091234: bgez        $a0, L_8009124C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80091238: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_8009124C;
    }
    // 0x80091238: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8009123C: blez        $v0, L_8009124C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80091240: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8009124C;
    }
    // 0x80091240: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80091244: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80091248: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8009124C:
    // 0x8009124C: blez        $a0, L_80091268
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80091250: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80091268;
    }
    // 0x80091250: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80091254: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80091258: beq         $at, $zero, L_80091268
    if (ctx->r1 == 0) {
        // 0x8009125C: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_80091268;
    }
    // 0x8009125C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80091260: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80091264: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80091268:
    // 0x80091268: bne         $a2, $v1, L_80091280
    if (ctx->r6 != ctx->r3) {
        // 0x8009126C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80091280;
    }
    // 0x8009126C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80091270: bne         $v0, $at, L_80091280
    if (ctx->r2 != ctx->r1) {
        // 0x80091274: nop
    
            goto L_80091280;
    }
    // 0x80091274: nop

    // 0x80091278: sw          $a2, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r6;
    // 0x8009127C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80091280:
    // 0x80091280: bne         $a0, $zero, L_800912DC
    if (ctx->r4 != 0) {
        // 0x80091284: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800912DC;
    }
    // 0x80091284: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80091288: lh          $a0, 0x6DD8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6DD8);
    // 0x8009128C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80091290: bgez        $a0, L_800912A4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80091294: nop
    
            goto L_800912A4;
    }
    // 0x80091294: nop

    // 0x80091298: beq         $at, $zero, L_800912A4
    if (ctx->r1 == 0) {
        // 0x8009129C: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_800912A4;
    }
    // 0x8009129C: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x800912A0: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
L_800912A4:
    // 0x800912A4: blez        $a0, L_800912C0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800912A8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800912C0;
    }
    // 0x800912A8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800912AC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800912B0: nop

    // 0x800912B4: blez        $v1, L_800912C0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800912B8: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_800912C0;
    }
    // 0x800912B8: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x800912BC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_800912C0:
    // 0x800912C0: bne         $v0, $at, L_800912DC
    if (ctx->r2 != ctx->r1) {
        // 0x800912C4: nop
    
            goto L_800912DC;
    }
    // 0x800912C4: nop

    // 0x800912C8: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800912CC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800912D0: bne         $a2, $t7, L_800912DC
    if (ctx->r6 != ctx->r15) {
        // 0x800912D4: nop
    
            goto L_800912DC;
    }
    // 0x800912D4: nop

    // 0x800912D8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
L_800912DC:
    // 0x800912DC: bne         $t0, $v0, L_800912F4
    if (ctx->r8 != ctx->r2) {
        // 0x800912E0: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_800912F4;
    }
    // 0x800912E0: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800912E4: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800912E8: nop

    // 0x800912EC: beq         $t1, $t8, L_80091384
    if (ctx->r9 == ctx->r24) {
        // 0x800912F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80091384;
    }
    // 0x800912F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800912F4:
    // 0x800912F4: jal         0x80001D04
    // 0x800912F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_14;
    // 0x800912F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x800912FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80091300: lw          $v1, 0x6F8C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6F8C);
    // 0x80091304: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80091308: lw          $v0, 0x6F88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F88);
    // 0x8009130C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80091310: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80091314: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80091318: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x8009131C: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x80091320: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80091324: lw          $t5, 0x6A20($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6A20);
    // 0x80091328: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009132C: multu       $v1, $t5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80091330: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80091334: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80091338: lh          $t6, 0x6EA8($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6EA8);
    // 0x8009133C: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80091340: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80091344: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80091348: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8009134C: sw          $t6, -0x5BC($at)
    MEM_W(-0X5BC, ctx->r1) = ctx->r14;
    // 0x80091350: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80091354: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80091358: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8009135C: mflo        $t7
    ctx->r15 = lo;
    // 0x80091360: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x80091364: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80091368: sw          $t8, -0x5B8($at)
    MEM_W(-0X5B8, ctx->r1) = ctx->r24;
    // 0x8009136C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80091370: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80091374: swc1        $f6, 0x6FA8($at)
    MEM_W(0X6FA8, ctx->r1) = ctx->f6.u32l;
    // 0x80091378: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009137C: swc1        $f10, 0x6FAC($at)
    MEM_W(0X6FAC, ctx->r1) = ctx->f10.u32l;
L_80091380:
    // 0x80091380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80091384:
    // 0x80091384: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80091388: jr          $ra
    // 0x8009138C: nop

    return;
    // 0x8009138C: nop

;}
