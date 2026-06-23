#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mempool_init_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070D74: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80070D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070D7C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80070D80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80070D84: addiu       $a0, $a0, -0x2650
    ctx->r4 = ADD32(ctx->r4, -0X2650);
    // 0x80070D88: lui         $t7, 0x8040
    ctx->r15 = S32(0X8040 << 16);
    // 0x80070D8C: sw          $t6, 0x3B40($at)
    MEM_W(0X3B40, ctx->r1) = ctx->r14;
    // 0x80070D90: subu        $a1, $t7, $a0
    ctx->r5 = SUB32(ctx->r15, ctx->r4);
    // 0x80070D94: jal         0x80070E24
    // 0x80070D98: addiu       $a2, $zero, 0x640
    ctx->r6 = ADD32(0, 0X640);
    mempool_init(rdram, ctx);
        goto after_0;
    // 0x80070D98: addiu       $a2, $zero, 0x640
    ctx->r6 = ADD32(0, 0X640);
    after_0:
    // 0x80070D9C: jal         0x800712F0
    // 0x80070DA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_1;
    // 0x80070DA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80070DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070DA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80070DAC: sw          $zero, 0x4348($at)
    MEM_W(0X4348, ctx->r1) = 0;
    // 0x80070DB0: jr          $ra
    // 0x80070DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80070DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void alCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D3D84: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800D3D88: blez        $a2, L_800D3DEC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800D3D8C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800D3DEC;
    }
    // 0x800D3D8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D3D90: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x800D3D94: beq         $a1, $zero, L_800D3DBC
    if (ctx->r5 == 0) {
        // 0x800D3D98: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800D3DBC;
    }
    // 0x800D3D98: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800D3D9C:
    // 0x800D3D9C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800D3DA0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800D3DA4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D3DA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D3DAC: bne         $a0, $a3, L_800D3D9C
    if (ctx->r4 != ctx->r7) {
        // 0x800D3DB0: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_800D3D9C;
    }
    // 0x800D3DB0: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800D3DB4: beq         $a3, $a2, L_800D3DEC
    if (ctx->r7 == ctx->r6) {
        // 0x800D3DB8: nop
    
            goto L_800D3DEC;
    }
    // 0x800D3DB8: nop

L_800D3DBC:
    // 0x800D3DBC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800D3DC0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800D3DC4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D3DC8: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x800D3DCC: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800D3DD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D3DD4: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x800D3DD8: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x800D3DDC: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x800D3DE0: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x800D3DE4: bne         $a3, $a2, L_800D3DBC
    if (ctx->r7 != ctx->r6) {
        // 0x800D3DE8: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_800D3DBC;
    }
    // 0x800D3DE8: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
L_800D3DEC:
    // 0x800D3DEC: jr          $ra
    // 0x800D3DF0: nop

    return;
    // 0x800D3DF0: nop

;}
RECOMP_FUNC void menu_adventure_track_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800931CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800931D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800931D4: jal         0x8006ECD0
    // 0x800931D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x800931D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800931DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800931E0: sw          $zero, -0x5BC($at)
    MEM_W(-0X5BC, ctx->r1) = 0;
    // 0x800931E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800931E8: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x800931EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800931F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800931F4: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x800931F8: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    // 0x800931FC: nop

    // 0x80093200: lb          $s0, 0x2($t6)
    ctx->r16 = MEM_B(ctx->r14, 0X2);
    // 0x80093204: jal         0x8006B2EC
    // 0x80093208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_vehicle_default(rdram, ctx);
        goto after_1;
    // 0x80093208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8009320C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093210: sb          $v0, 0x6F80($at)
    MEM_B(0X6F80, ctx->r1) = ctx->r2;
    // 0x80093214: jal         0x8006B38C
    // 0x80093218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_type(rdram, ctx);
        goto after_2;
    // 0x80093218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8009321C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80093220: beq         $v0, $at, L_80093260
    if (ctx->r2 == ctx->r1) {
        // 0x80093224: sll         $t4, $s0, 1
        ctx->r12 = S32(ctx->r16 << 1);
            goto L_80093260;
    }
    // 0x80093224: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x80093228: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8009322C: beq         $v0, $at, L_80093260
    if (ctx->r2 == ctx->r1) {
        // 0x80093230: andi        $t7, $v0, 0x40
        ctx->r15 = ctx->r2 & 0X40;
            goto L_80093260;
    }
    // 0x80093230: andi        $t7, $v0, 0x40
    ctx->r15 = ctx->r2 & 0X40;
    // 0x80093234: bne         $t7, $zero, L_80093294
    if (ctx->r15 != 0) {
        // 0x80093238: sll         $t6, $s0, 1
        ctx->r14 = S32(ctx->r16 << 1);
            goto L_80093294;
    }
    // 0x80093238: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x8009323C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80093240: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80093244: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80093248: nop

    // 0x8009324C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80093250: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80093254: nop

    // 0x80093258: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x8009325C: bne         $t3, $zero, L_80093294
    if (ctx->r11 != 0) {
        // 0x80093260: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80093294;
    }
L_80093260:
    // 0x80093260: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80093264: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80093268: lh          $v0, 0xCD8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0XCD8);
    // 0x8009326C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80093270: beq         $v0, $at, L_80093284
    if (ctx->r2 == ctx->r1) {
        // 0x80093274: andi        $a0, $v0, 0xFFFF
        ctx->r4 = ctx->r2 & 0XFFFF;
            goto L_80093284;
    }
    // 0x80093274: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80093278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009327C: jal         0x80000FDC
    // 0x80093280: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_3;
    // 0x80093280: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
L_80093284:
    // 0x80093284: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80093288: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009328C: b           L_800933A0
    // 0x80093290: sw          $t5, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r13;
        goto L_800933A0;
    // 0x80093290: sw          $t5, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r13;
L_80093294:
    // 0x80093294: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80093298: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8009329C: lh          $v0, 0xCD8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0XCD8);
    // 0x800932A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800932A4: beq         $v0, $at, L_800932B8
    if (ctx->r2 == ctx->r1) {
        // 0x800932A8: andi        $a0, $v0, 0xFFFF
        ctx->r4 = ctx->r2 & 0XFFFF;
            goto L_800932B8;
    }
    // 0x800932A8: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800932AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800932B0: jal         0x80000FDC
    // 0x800932B4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_4;
    // 0x800932B4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_4:
L_800932B8:
    // 0x800932B8: jal         0x80000BE0
    // 0x800932BC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_5;
    // 0x800932BC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_5:
    // 0x800932C0: jal         0x80000B34
    // 0x800932C4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_6;
    // 0x800932C4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_6:
    // 0x800932C8: jal         0x80000B18
    // 0x800932CC: nop

    music_change_off(rdram, ctx);
        goto after_7;
    // 0x800932CC: nop

    after_7:
    // 0x800932D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800932D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800932D8: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x800932DC: jal         0x8009CBB8
    // 0x800932E0: addiu       $a0, $a0, 0x1534
    ctx->r4 = ADD32(ctx->r4, 0X1534);
    menu_assetgroup_load(rdram, ctx);
        goto after_8;
    // 0x800932E0: addiu       $a0, $a0, 0x1534
    ctx->r4 = ADD32(ctx->r4, 0X1534);
    after_8:
    // 0x800932E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800932E8: jal         0x8009CDE8
    // 0x800932EC: addiu       $a0, $a0, 0x1558
    ctx->r4 = ADD32(ctx->r4, 0X1558);
    menu_imagegroup_load(rdram, ctx);
        goto after_9;
    // 0x800932EC: addiu       $a0, $a0, 0x1558
    ctx->r4 = ADD32(ctx->r4, 0X1558);
    after_9:
    // 0x800932F0: jal         0x8008E914
    // 0x800932F4: nop

    menu_init_vehicle_textures(rdram, ctx);
        goto after_10;
    // 0x800932F4: nop

    after_10:
    // 0x800932F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800932FC: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
    // 0x80093300: lw          $t7, 0x7C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X7C);
    // 0x80093304: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093308: sw          $t7, 0xA54($at)
    MEM_W(0XA54, ctx->r1) = ctx->r15;
    // 0x8009330C: lw          $t8, 0x78($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X78);
    // 0x80093310: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093314: sw          $t8, 0xA64($at)
    MEM_W(0XA64, ctx->r1) = ctx->r24;
    // 0x80093318: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x8009331C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093320: sw          $t9, 0xA74($at)
    MEM_W(0XA74, ctx->r1) = ctx->r25;
    // 0x80093324: lw          $t0, 0x80($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X80);
    // 0x80093328: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009332C: sw          $t0, 0xA84($at)
    MEM_W(0XA84, ctx->r1) = ctx->r8;
    // 0x80093330: lw          $t1, 0x8C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8C);
    // 0x80093334: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093338: sw          $t1, 0xA94($at)
    MEM_W(0XA94, ctx->r1) = ctx->r9;
    // 0x8009333C: lw          $t2, 0x88($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X88);
    // 0x80093340: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093344: sw          $t2, 0xAA4($at)
    MEM_W(0XAA4, ctx->r1) = ctx->r10;
    // 0x80093348: lw          $t3, 0xC0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC0);
    // 0x8009334C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093350: sw          $t3, 0xB34($at)
    MEM_W(0XB34, ctx->r1) = ctx->r11;
    // 0x80093354: lw          $t4, 0x1A4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1A4);
    // 0x80093358: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009335C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80093360: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    // 0x80093364: jal         0x800C06F8
    // 0x80093368: sw          $t4, 0xB94($at)
    MEM_W(0XB94, ctx->r1) = ctx->r12;
    transition_begin(rdram, ctx);
        goto after_11;
    // 0x80093368: sw          $t4, 0xB94($at)
    MEM_W(0XB94, ctx->r1) = ctx->r12;
    after_11:
    // 0x8009336C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80093370: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80093374: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093378: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8009337C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80093380: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x80093384: sw          $t5, 0xF00($at)
    MEM_W(0XF00, ctx->r1) = ctx->r13;
    // 0x80093388: jal         0x800C46D0
    // 0x8009338C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_12;
    // 0x8009338C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x80093390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093394: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80093398: jal         0x8006E528
    // 0x8009339C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    load_level_for_menu(rdram, ctx);
        goto after_13;
    // 0x8009339C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
L_800933A0:
    // 0x800933A0: jal         0x800C59F4
    // 0x800933A4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_14;
    // 0x800933A4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_14:
    // 0x800933A8: jal         0x8006B38C
    // 0x800933AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_type(rdram, ctx);
        goto after_15;
    // 0x800933AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x800933B0: andi        $t6, $v0, 0x40
    ctx->r14 = ctx->r2 & 0X40;
    // 0x800933B4: beq         $t6, $zero, L_800933D0
    if (ctx->r14 == 0) {
        // 0x800933B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800933D0;
    }
    // 0x800933B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800933BC: jal         0x8006B3D0
    // 0x800933C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_world(rdram, ctx);
        goto after_16;
    // 0x800933C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800933C4: jal         0x800C3744
    // 0x800933C8: addiu       $a0, $v0, 0x3B
    ctx->r4 = ADD32(ctx->r2, 0X3B);
    set_current_text(rdram, ctx);
        goto after_17;
    // 0x800933C8: addiu       $a0, $v0, 0x3B
    ctx->r4 = ADD32(ctx->r2, 0X3B);
    after_17:
    // 0x800933CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800933D0:
    // 0x800933D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800933D4: jr          $ra
    // 0x800933D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800933D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void draw_menu_elements(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008263C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80082640: swc1        $f20, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f20.u32l;
    // 0x80082644: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80082648: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8008264C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80082650: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80082654: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80082658: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8008265C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80082660: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80082664: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80082668: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8008266C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80082670: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80082674: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80082678: swc1        $f23, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8008267C: swc1        $f22, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f22.u32l;
    // 0x80082680: swc1        $f21, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80082684: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80082688: beq         $a0, $at, L_80082CC8
    if (ctx->r4 == ctx->r1) {
        // 0x8008268C: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80082CC8;
    }
    // 0x8008268C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80082690: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80082694: addiu       $s6, $s6, 0x693C
    ctx->r22 = ADD32(ctx->r22, 0X693C);
    // 0x80082698: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008269C: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x800826A0: jal         0x8006816C
    // 0x800826A4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x800826A4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x800826A8: lw          $s1, 0x14($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X14);
    // 0x800826AC: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800826B0: beq         $s1, $zero, L_80082C88
    if (ctx->r17 == 0) {
        // 0x800826B4: lui         $s7, 0x800E
        ctx->r23 = S32(0X800E << 16);
            goto L_80082C88;
    }
    // 0x800826B4: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800826B8: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800826BC: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800826C0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800826C4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800826C8: addiu       $s4, $s4, -0x324
    ctx->r20 = ADD32(ctx->r20, -0X324);
    // 0x800826CC: addiu       $fp, $fp, -0x2E4
    ctx->r30 = ADD32(ctx->r30, -0X2E4);
    // 0x800826D0: addiu       $s7, $s7, -0x2E0
    ctx->r23 = ADD32(ctx->r23, -0X2E0);
L_800826D4:
    // 0x800826D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800826D8: addiu       $t7, $t7, 0x6DF0
    ctx->r15 = ADD32(ctx->r15, 0X6DF0);
    // 0x800826DC: beq         $t7, $s1, L_80082C78
    if (ctx->r15 == ctx->r17) {
        // 0x800826E0: nop
    
            goto L_80082C78;
    }
    // 0x800826E0: nop

    // 0x800826E4: bne         $a0, $zero, L_80082770
    if (ctx->r4 != 0) {
        // 0x800826E8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80082770;
    }
    // 0x800826E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800826EC: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800826F0: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x800826F4: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x800826F8: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800826FC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80082700: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x80082704: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082708: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x8008270C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80082710: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80082714: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80082718: nop

    // 0x8008271C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80082720: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082724: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082728: nop

    // 0x8008272C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80082730: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80082734: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80082738: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008273C: addu        $s2, $t1, $v0
    ctx->r18 = ADD32(ctx->r9, ctx->r2);
    // 0x80082740: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80082744: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80082748: nop

    // 0x8008274C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80082750: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082754: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082758: nop

    // 0x8008275C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80082760: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80082764: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80082768: b           L_8008280C
    // 0x8008276C: addu        $s3, $t5, $v1
    ctx->r19 = ADD32(ctx->r13, ctx->r3);
        goto L_8008280C;
    // 0x8008276C: addu        $s3, $t5, $v1
    ctx->r19 = ADD32(ctx->r13, ctx->r3);
L_80082770:
    // 0x80082770: bne         $a0, $at, L_80082788
    if (ctx->r4 != ctx->r1) {
        // 0x80082774: nop
    
            goto L_80082788;
    }
    // 0x80082774: nop

    // 0x80082778: lh          $s2, 0x4($s0)
    ctx->r18 = MEM_H(ctx->r16, 0X4);
    // 0x8008277C: lh          $s3, 0x6($s0)
    ctx->r19 = MEM_H(ctx->r16, 0X6);
    // 0x80082780: b           L_80082810
    // 0x80082784: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
        goto L_80082810;
    // 0x80082784: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
L_80082788:
    // 0x80082788: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x8008278C: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x80082790: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80082794: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80082798: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8008279C: lh          $t0, 0xA($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XA);
    // 0x800827A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800827A4: subu        $t1, $t0, $v1
    ctx->r9 = SUB32(ctx->r8, ctx->r3);
    // 0x800827A8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800827AC: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800827B0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800827B4: nop

    // 0x800827B8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800827BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800827C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800827C4: nop

    // 0x800827C8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800827CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800827D0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800827D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800827D8: addu        $s2, $t9, $v0
    ctx->r18 = ADD32(ctx->r25, ctx->r2);
    // 0x800827DC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800827E0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800827E4: nop

    // 0x800827E8: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800827EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800827F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800827F4: nop

    // 0x800827F8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800827FC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80082800: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80082804: addu        $s3, $t3, $v1
    ctx->r19 = ADD32(ctx->r11, ctx->r3);
    // 0x80082808: nop

L_8008280C:
    // 0x8008280C: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
L_80082810:
    // 0x80082810: nop

    // 0x80082814: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x80082818: beq         $at, $zero, L_80082C78
    if (ctx->r1 == 0) {
        // 0x8008281C: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80082C78;
    }
    // 0x8008281C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80082820: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082824: addu        $at, $at, $t4
    gpr jr_addend_80082830 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80082828: lw          $t4, -0x7704($at)
    ctx->r12 = ADD32(ctx->r1, -0X7704);
    // 0x8008282C: nop

    // 0x80082830: jr          $t4
    // 0x80082834: nop

    switch (jr_addend_80082830 >> 2) {
        case 0: goto L_80082838; break;
        case 1: goto L_800828A4; break;
        case 2: goto L_80082908; break;
        case 3: goto L_80082974; break;
        case 4: goto L_800829BC; break;
        case 5: goto L_80082A58; break;
        case 6: goto L_80082BB0; break;
        case 7: goto L_80082C10; break;
        default: switch_error(__func__, 0x80082830, 0x800E88FC);
    }
    // 0x80082834: nop

L_80082838:
    // 0x80082838: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    // 0x8008283C: lh          $a1, 0x1A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1A);
    // 0x80082840: lh          $a2, 0x1C($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X1C);
    // 0x80082844: lh          $a3, 0x1E($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X1E);
    // 0x80082848: jal         0x800C492C
    // 0x8008284C: nop

    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x8008284C: nop

    after_1:
    // 0x80082850: lbu         $t5, 0x10($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X10);
    // 0x80082854: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x80082858: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x8008285C: lbu         $a2, 0xE($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0XE);
    // 0x80082860: lbu         $a3, 0xF($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XF);
    // 0x80082864: jal         0x800C48E4
    // 0x80082868: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x80082868: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8008286C: lbu         $a0, 0x11($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X11);
    // 0x80082870: jal         0x800C484C
    // 0x80082874: nop

    set_text_font(rdram, ctx);
        goto after_3;
    // 0x80082874: nop

    after_3:
    // 0x80082878: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x8008287C: lbu         $t7, 0x12($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X12);
    // 0x80082880: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80082884: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082888: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8008288C: addu        $a2, $s3, $t6
    ctx->r6 = ADD32(ctx->r19, ctx->r14);
    // 0x80082890: jal         0x800C49A0
    // 0x80082894: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    draw_text(rdram, ctx);
        goto after_4;
    // 0x80082894: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x80082898: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8008289C: b           L_80082C7C
    // 0x800828A0: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x800828A0: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_800828A4:
    // 0x800828A4: beq         $s5, $zero, L_800828B4
    if (ctx->r21 == 0) {
        // 0x800828A8: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800828B4;
    }
    // 0x800828A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800828AC: jal         0x8007B820
    // 0x800828B0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x800828B0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_5:
L_800828B4:
    // 0x800828B4: lbu         $t8, 0x10($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X10);
    // 0x800828B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800828BC: sw          $t8, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r24;
    // 0x800828C0: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800828C4: lbu         $t2, 0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XD);
    // 0x800828C8: lbu         $a3, 0xC($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XC);
    // 0x800828CC: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x800828D0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800828D4: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x800828D8: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x800828DC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800828E0: lbu         $t4, 0x11($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X11);
    // 0x800828E4: negu        $t0, $s3
    ctx->r8 = SUB32(0, ctx->r19);
    // 0x800828E8: subu        $a2, $t0, $t1
    ctx->r6 = SUB32(ctx->r8, ctx->r9);
    // 0x800828EC: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    // 0x800828F0: addiu       $a1, $s2, -0xA0
    ctx->r5 = ADD32(ctx->r18, -0XA0);
    // 0x800828F4: jal         0x80081C50
    // 0x800828F8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    menu_timestamp_render(rdram, ctx);
        goto after_6;
    // 0x800828F8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_6:
    // 0x800828FC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082900: b           L_80082C7C
    // 0x80082904: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x80082904: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082908:
    // 0x80082908: beq         $s5, $zero, L_80082920
    if (ctx->r21 == 0) {
        // 0x8008290C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80082920;
    }
    // 0x8008290C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082910: jal         0x8007B820
    // 0x80082914: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    rendermode_reset(rdram, ctx);
        goto after_7;
    // 0x80082914: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_7:
    // 0x80082918: lw          $s1, 0x14($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X14);
    // 0x8008291C: nop

L_80082920:
    // 0x80082920: lbu         $t7, 0xD($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XD);
    // 0x80082924: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80082928: lbu         $a3, 0xC($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XC);
    // 0x8008292C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80082930: lbu         $t8, 0xE($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XE);
    // 0x80082934: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80082938: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8008293C: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x80082940: negu        $t5, $s3
    ctx->r13 = SUB32(0, ctx->r19);
    // 0x80082944: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80082948: lbu         $t0, 0x11($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X11);
    // 0x8008294C: subu        $a2, $t5, $t6
    ctx->r6 = SUB32(ctx->r13, ctx->r14);
    // 0x80082950: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80082954: lbu         $t1, 0x12($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X12);
    // 0x80082958: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    // 0x8008295C: addiu       $a1, $s2, -0xA0
    ctx->r5 = ADD32(ctx->r18, -0XA0);
    // 0x80082960: jal         0x80082054
    // 0x80082964: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    menu_number_render(rdram, ctx);
        goto after_8;
    // 0x80082964: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_8:
    // 0x80082968: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8008296C: b           L_80082C7C
    // 0x80082970: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x80082970: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082974:
    // 0x80082974: lbu         $t3, 0xC($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XC);
    // 0x80082978: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x8008297C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80082980: lbu         $t4, 0xD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XD);
    // 0x80082984: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082988: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8008298C: lbu         $t5, 0xE($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XE);
    // 0x80082990: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80082994: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80082998: lbu         $t6, 0x10($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X10);
    // 0x8008299C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800829A0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800829A4: addu        $a3, $s3, $t2
    ctx->r7 = ADD32(ctx->r19, ctx->r10);
    // 0x800829A8: jal         0x80078F08
    // 0x800829AC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    texrect_draw(rdram, ctx);
        goto after_9;
    // 0x800829AC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_9:
    // 0x800829B0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800829B4: b           L_80082C7C
    // 0x800829B8: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x800829B8: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_800829BC:
    // 0x800829BC: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x800829C0: mtc1        $s2, $f16
    ctx->f16.u32l = ctx->r18;
    // 0x800829C4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800829C8: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800829CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800829D0: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x800829D4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800829D8: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800829DC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800829E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800829E4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800829E8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800829EC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800829F0: lh          $t0, 0x1A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1A);
    // 0x800829F4: nop

    // 0x800829F8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800829FC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80082A00: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80082A04: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80082A08: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80082A0C: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80082A10: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80082A14: lbu         $t3, 0xD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XD);
    // 0x80082A18: lbu         $t1, 0xC($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XC);
    // 0x80082A1C: lbu         $t6, 0xE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XE);
    // 0x80082A20: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80082A24: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x80082A28: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x80082A2C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80082A30: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80082A34: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80082A38: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80082A3C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80082A40: lbu         $t1, 0x12($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X12);
    // 0x80082A44: jal         0x80079150
    // 0x80082A48: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    texrect_draw_scaled(rdram, ctx);
        goto after_10;
    // 0x80082A48: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_10:
    // 0x80082A4C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082A50: b           L_80082C7C
    // 0x80082A54: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x80082A54: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082A58:
    // 0x80082A58: beq         $s5, $zero, L_80082A68
    if (ctx->r21 == 0) {
        // 0x80082A5C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80082A68;
    }
    // 0x80082A5C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082A60: jal         0x8007B820
    // 0x80082A64: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    rendermode_reset(rdram, ctx);
        goto after_11;
    // 0x80082A64: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_11:
L_80082A68:
    // 0x80082A68: jal         0x80068748
    // 0x80082A6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_12;
    // 0x80082A6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80082A70: jal         0x8007C36C
    // 0x80082A74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_13;
    // 0x80082A74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80082A78: addiu       $t3, $s2, -0xA0
    ctx->r11 = ADD32(ctx->r18, -0XA0);
    // 0x80082A7C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80082A80: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x80082A84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082A88: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80082A8C: sll         $t6, $t4, 5
    ctx->r14 = S32(ctx->r12 << 5);
    // 0x80082A90: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x80082A94: swc1        $f6, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f6.u32l;
    // 0x80082A98: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80082A9C: negu        $t7, $s3
    ctx->r15 = SUB32(0, ctx->r19);
    // 0x80082AA0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80082AA4: addiu       $t0, $t9, 0x78
    ctx->r8 = ADD32(ctx->r25, 0X78);
    // 0x80082AA8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80082AAC: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x80082AB0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80082AB4: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80082AB8: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80082ABC: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x80082AC0: swc1        $f10, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f10.u32l;
    // 0x80082AC4: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80082AC8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80082ACC: lbu         $t6, 0x11($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X11);
    // 0x80082AD0: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80082AD4: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x80082AD8: sh          $t6, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r14;
    // 0x80082ADC: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x80082AE0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80082AE4: lh          $t0, 0x18($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X18);
    // 0x80082AE8: sll         $t4, $t1, 5
    ctx->r12 = S32(ctx->r9 << 5);
    // 0x80082AEC: addu        $t2, $t3, $t4
    ctx->r10 = ADD32(ctx->r11, ctx->r12);
    // 0x80082AF0: sh          $t0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r8;
    // 0x80082AF4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80082AF8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80082AFC: lh          $t7, 0x1A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A);
    // 0x80082B00: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x80082B04: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80082B08: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x80082B0C: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x80082B10: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80082B14: lh          $t1, 0x1C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1C);
    // 0x80082B18: sll         $t0, $t4, 5
    ctx->r8 = S32(ctx->r12 << 5);
    // 0x80082B1C: addu        $t2, $t3, $t0
    ctx->r10 = ADD32(ctx->r11, ctx->r8);
    // 0x80082B20: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x80082B24: lh          $t8, 0x1E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1E);
    // 0x80082B28: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80082B2C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80082B30: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80082B34: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80082B38: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80082B3C: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x80082B40: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80082B44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082B48: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x80082B4C: lbu         $t4, 0xC($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XC);
    // 0x80082B50: nop

    // 0x80082B54: sb          $t4, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r12;
    // 0x80082B58: lbu         $t3, 0xD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XD);
    // 0x80082B5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082B60: sb          $t3, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r11;
    // 0x80082B64: lbu         $t0, 0xE($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XE);
    // 0x80082B68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082B6C: sb          $t0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r8;
    // 0x80082B70: lbu         $t1, 0xF($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XF);
    // 0x80082B74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082B78: sb          $t1, -0x5D0($at)
    MEM_B(-0X5D0, ctx->r1) = ctx->r9;
    // 0x80082B7C: lbu         $t2, 0x10($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X10);
    // 0x80082B80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082B84: sw          $t2, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r10;
    // 0x80082B88: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80082B8C: jal         0x8009CFA4
    // 0x80082B90: nop

    menu_element_render(rdram, ctx);
        goto after_14;
    // 0x80082B90: nop

    after_14:
    // 0x80082B94: jal         0x80068748
    // 0x80082B98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_15;
    // 0x80082B98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x80082B9C: jal         0x8007C36C
    // 0x80082BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_16;
    // 0x80082BA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80082BA4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082BA8: b           L_80082C7C
    // 0x80082BAC: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x80082BAC: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082BB0:
    // 0x80082BB0: lh          $t6, 0x1A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A);
    // 0x80082BB4: lh          $a3, 0x18($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X18);
    // 0x80082BB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80082BBC: lh          $t5, 0x1C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1C);
    // 0x80082BC0: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80082BC4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80082BC8: lh          $t7, 0x1E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1E);
    // 0x80082BCC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082BD0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80082BD4: lbu         $t9, 0xC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XC);
    // 0x80082BD8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80082BDC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80082BE0: lbu         $t4, 0xD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XD);
    // 0x80082BE4: addu        $a2, $s3, $t8
    ctx->r6 = ADD32(ctx->r19, ctx->r24);
    // 0x80082BE8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80082BEC: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x80082BF0: nop

    // 0x80082BF4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80082BF8: lbu         $t0, 0x10($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X10);
    // 0x80082BFC: jal         0x800812E0
    // 0x80082C00: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_80080E90(rdram, ctx);
        goto after_17;
    // 0x80082C00: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_17:
    // 0x80082C04: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082C08: b           L_80082C7C
    // 0x80082C0C: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_80082C7C;
    // 0x80082C0C: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082C10:
    // 0x80082C10: lh          $t2, 0x1A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A);
    // 0x80082C14: lh          $a3, 0x18($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X18);
    // 0x80082C18: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80082C1C: lh          $t8, 0x1C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1C);
    // 0x80082C20: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x80082C24: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80082C28: lh          $t6, 0x1E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1E);
    // 0x80082C2C: addu        $a2, $s3, $t1
    ctx->r6 = ADD32(ctx->r19, ctx->r9);
    // 0x80082C30: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80082C34: lbu         $t9, 0xD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XD);
    // 0x80082C38: lbu         $t5, 0xC($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XC);
    // 0x80082C3C: lbu         $t0, 0xE($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XE);
    // 0x80082C40: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x80082C44: sll         $t7, $t5, 24
    ctx->r15 = S32(ctx->r13 << 24);
    // 0x80082C48: lbu         $t8, 0x10($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X10);
    // 0x80082C4C: or          $t3, $t7, $t4
    ctx->r11 = ctx->r15 | ctx->r12;
    // 0x80082C50: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x80082C54: or          $t2, $t3, $t1
    ctx->r10 = ctx->r11 | ctx->r9;
    // 0x80082C58: or          $t6, $t2, $t8
    ctx->r14 = ctx->r10 | ctx->r24;
    // 0x80082C5C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80082C60: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80082C64: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082C68: jal         0x800809D0
    // 0x80082C6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80080580(rdram, ctx);
        goto after_18;
    // 0x80082C6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x80082C70: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082C74: nop

L_80082C78:
    // 0x80082C78: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082C7C:
    // 0x80082C7C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80082C80: bne         $s1, $zero, L_800826D4
    if (ctx->r17 != 0) {
        // 0x80082C84: nop
    
            goto L_800826D4;
    }
    // 0x80082C84: nop

L_80082C88:
    // 0x80082C88: beq         $s5, $zero, L_80082C9C
    if (ctx->r21 == 0) {
        // 0x80082C8C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80082C9C;
    }
    // 0x80082C8C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80082C90: jal         0x8007B820
    // 0x80082C94: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    rendermode_reset(rdram, ctx);
        goto after_19;
    // 0x80082C94: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_19:
    // 0x80082C98: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80082C9C:
    // 0x80082C9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082CA0: sb          $v0, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r2;
    // 0x80082CA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082CA8: sb          $v0, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r2;
    // 0x80082CAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082CB0: sb          $v0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r2;
    // 0x80082CB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082CB8: sb          $zero, -0x5D0($at)
    MEM_B(-0X5D0, ctx->r1) = 0;
    // 0x80082CBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082CC0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80082CC4: sw          $t5, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r13;
L_80082CC8:
    // 0x80082CC8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80082CCC: lwc1        $f21, 0x38($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80082CD0: lwc1        $f20, 0x3C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80082CD4: lwc1        $f23, 0x40($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80082CD8: lwc1        $f22, 0x44($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80082CDC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80082CE0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80082CE4: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80082CE8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80082CEC: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80082CF0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80082CF4: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80082CF8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80082CFC: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80082D00: jr          $ra
    // 0x80082D04: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80082D04: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void obj_loop_seamonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003CF50: jr          $ra
    // 0x8003CF54: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003CF54: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void drm_checksum_balloon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A43C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005A440: lw          $a1, -0x2F40($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2F40);
    // 0x8005A444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A448: blez        $a1, L_8005A470
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005A44C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005A470;
    }
    // 0x8005A44C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A450: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8005A454: addiu       $v1, $v1, -0x4B04
    ctx->r3 = ADD32(ctx->r3, -0X4B04);
L_8005A458:
    // 0x8005A458: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x8005A45C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8005A460: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005A464: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005A468: bne         $at, $zero, L_8005A458
    if (ctx->r1 != 0) {
        // 0x8005A46C: addu        $v0, $v0, $t7
        ctx->r2 = ADD32(ctx->r2, ctx->r15);
            goto L_8005A458;
    }
    // 0x8005A46C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
L_8005A470:
    // 0x8005A470: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005A474: lw          $t8, -0x2CC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2CC0);
    // 0x8005A478: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x8005A47C: beq         $v0, $t8, L_8005A488
    if (ctx->r2 == ctx->r24) {
        // 0x8005A480: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005A488;
    }
    // 0x8005A480: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A484: sh          $t9, -0x2F3C($at)
    MEM_H(-0X2F3C, ctx->r1) = ctx->r25;
L_8005A488:
    // 0x8005A488: jr          $ra
    // 0x8005A48C: nop

    return;
    // 0x8005A48C: nop

;}
RECOMP_FUNC void menu_magic_codes_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089A7C: sh          $zero, 0x7200($at)
    MEM_H(0X7200, ctx->r1) = 0;
    // 0x80089A80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089A84: sh          $zero, 0x7202($at)
    MEM_H(0X7202, ctx->r1) = 0;
    // 0x80089A88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089A8C: sh          $zero, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = 0;
    // 0x80089A90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089A94: sh          $zero, 0x7204($at)
    MEM_H(0X7204, ctx->r1) = 0;
    // 0x80089A98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089A9C: sw          $zero, 0x6A10($at)
    MEM_W(0X6A10, ctx->r1) = 0;
    // 0x80089AA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089AA4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80089AA8: sh          $t6, 0x720C($at)
    MEM_H(0X720C, ctx->r1) = ctx->r14;
    // 0x80089AAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089AB0: sb          $zero, 0x7218($at)
    MEM_B(0X7218, ctx->r1) = 0;
    // 0x80089AB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089AB8: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80089ABC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089AC0: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x80089AC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089AC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80089ACC: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x80089AD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80089AD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089AD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80089ADC: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x80089AE0: jal         0x800C06F8
    // 0x80089AE4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x80089AE4: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_0:
    // 0x80089AE8: addiu       $t7, $zero, 0x84
    ctx->r15 = ADD32(0, 0X84);
    // 0x80089AEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80089AF0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80089AF4: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80089AF8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80089AFC: jal         0x800C543C
    // 0x80089B00: addiu       $a3, $zero, 0x10E
    ctx->r7 = ADD32(0, 0X10E);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x80089B00: addiu       $a3, $zero, 0x10E
    ctx->r7 = ADD32(0, 0X10E);
    after_1:
    // 0x80089B04: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80089B08: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80089B0C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80089B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089B18: jal         0x800C551C
    // 0x80089B1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x80089B1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80089B20: jal         0x800C59F4
    // 0x80089B24: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_3;
    // 0x80089B24: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x80089B28: jal         0x800C46D0
    // 0x80089B2C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_4;
    // 0x80089B2C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80089B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80089B34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80089B38: jr          $ra
    // 0x80089B3C: nop

    return;
    // 0x80089B3C: nop

;}
RECOMP_FUNC void func_8002DE30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DE70: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8002DE74: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002DE78: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002DE7C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002DE80: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002DE84: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002DE88: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002DE8C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002DE90: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002DE94: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002DE98: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002DE9C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002DEA0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002DEA4: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002DEA8: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8002DEAC: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002DEB0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002DEB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DEB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DEBC: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002DEC0: lw          $a1, 0x40($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X40);
    // 0x8002DEC4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002DEC8: lh          $t7, 0x44($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X44);
    // 0x8002DECC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8002DED0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002DED4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8002DED8: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
    // 0x8002DEDC: lh          $t9, 0x42($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X42);
    // 0x8002DEE0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002DEE4: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x8002DEE8: sw          $t4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r12;
    // 0x8002DEEC: lh          $v1, 0x2E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X2E);
    // 0x8002DEF0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8002DEF4: beq         $v1, $at, L_8002E234
    if (ctx->r3 == ctx->r1) {
        // 0x8002DEF8: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8002E234;
    }
    // 0x8002DEF8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002DEFC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002DF00: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002DF04: lwc1        $f0, 0xC($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0XC);
    // 0x8002DF08: lwc1        $f2, 0x14($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8002DF0C: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8002DF10: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8002DF14: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002DF18: addiu       $s0, $s0, -0x3178
    ctx->r16 = ADD32(ctx->r16, -0X3178);
    // 0x8002DF1C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002DF20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DF24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DF28: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8002DF2C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002DF30: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8002DF34: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002DF38: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8002DF3C: sub.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8002DF40: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8002DF44: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002DF48: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002DF4C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002DF50: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DF54: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DF58: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002DF5C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002DF60: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8002DF64: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002DF68: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8002DF6C: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8002DF70: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x8002DF74: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8002DF78: nop

    // 0x8002DF7C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8002DF80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DF84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DF88: nop

    // 0x8002DF8C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002DF90: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8002DF94: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8002DF98: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8002DF9C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002DFA0: nop

    // 0x8002DFA4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8002DFA8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DFAC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DFB0: nop

    // 0x8002DFB4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002DFB8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8002DFBC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002DFC0: jal         0x8003151C
    // 0x8002DFC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    compute_grid_overlap_mask(rdram, ctx);
        goto after_0;
    // 0x8002DFC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002DFC8: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x8002DFCC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8002DFD0: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x8002DFD4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8002DFD8: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8002DFDC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002DFE0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x8002DFE4: addu        $s5, $t8, $t9
    ctx->r21 = ADD32(ctx->r24, ctx->r25);
    // 0x8002DFE8: lh          $t4, 0x20($s5)
    ctx->r12 = MEM_H(ctx->r21, 0X20);
    // 0x8002DFEC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8002DFF0: blez        $t4, L_8002E234
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8002DFF4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8002E234;
    }
    // 0x8002DFF4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8002DFF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002DFFC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8002E000: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E004: lwc1        $f21, 0x64D0($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X64D0);
    // 0x8002E008: lwc1        $f20, 0x64D4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X64D4);
    // 0x8002E00C: lw          $v0, 0xC($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XC);
    // 0x8002E010: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8002E014: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
L_8002E018:
    // 0x8002E018: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8002E01C: nop

    // 0x8002E020: andi        $t6, $v1, 0x6900
    ctx->r14 = ctx->r3 & 0X6900;
    // 0x8002E024: bne         $t6, $zero, L_8002E208
    if (ctx->r14 != 0) {
        // 0x8002E028: srl         $fp, $v1, 19
        ctx->r30 = S32(U32(ctx->r3) >> 19);
            goto L_8002E208;
    }
    // 0x8002E028: srl         $fp, $v1, 19
    ctx->r30 = S32(U32(ctx->r3) >> 19);
    // 0x8002E02C: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8002E030: lh          $s3, 0x4($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X4);
    // 0x8002E034: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x8002E038: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8002E03C: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x8002E040: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002E044: andi        $t7, $fp, 0x7
    ctx->r15 = ctx->r30 & 0X7;
    // 0x8002E048: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8002E04C: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002E050: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x8002E054: beq         $at, $zero, L_8002E208
    if (ctx->r1 == 0) {
        // 0x8002E058: addu        $s0, $t9, $t4
        ctx->r16 = ADD32(ctx->r25, ctx->r12);
            goto L_8002E208;
    }
    // 0x8002E058: addu        $s0, $t9, $t4
    ctx->r16 = ADD32(ctx->r25, ctx->r12);
    // 0x8002E05C: bne         $s7, $zero, L_8002E208
    if (ctx->r23 != 0) {
        // 0x8002E060: sll         $s4, $s3, 1
        ctx->r20 = S32(ctx->r19 << 1);
            goto L_8002E208;
    }
    // 0x8002E060: sll         $s4, $s3, 1
    ctx->r20 = S32(ctx->r19 << 1);
L_8002E064:
    // 0x8002E064: lw          $t6, 0x10($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X10);
    // 0x8002E068: nop

    // 0x8002E06C: addu        $t7, $t6, $s4
    ctx->r15 = ADD32(ctx->r14, ctx->r20);
    // 0x8002E070: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002E074: nop

    // 0x8002E078: and         $v0, $t8, $t3
    ctx->r2 = ctx->r24 & ctx->r11;
    // 0x8002E07C: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8002E080: beq         $t9, $zero, L_8002E1E0
    if (ctx->r25 == 0) {
        // 0x8002E084: andi        $t4, $v0, 0xFF00
        ctx->r12 = ctx->r2 & 0XFF00;
            goto L_8002E1E0;
    }
    // 0x8002E084: andi        $t4, $v0, 0xFF00
    ctx->r12 = ctx->r2 & 0XFF00;
    // 0x8002E088: beq         $t4, $zero, L_8002E1E0
    if (ctx->r12 == 0) {
        // 0x8002E08C: nop
    
            goto L_8002E1E0;
    }
    // 0x8002E08C: nop

    // 0x8002E090: lw          $t5, 0x4($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X4);
    // 0x8002E094: sll         $t6, $s3, 4
    ctx->r14 = S32(ctx->r19 << 4);
    // 0x8002E098: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x8002E09C: lbu         $t7, 0x1($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1);
    // 0x8002E0A0: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x8002E0A4: multu       $t7, $s1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E0A8: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x8002E0AC: addiu       $a0, $t0, 0x1
    ctx->r4 = ADD32(ctx->r8, 0X1);
    // 0x8002E0B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002E0B4: mflo        $t1
    ctx->r9 = lo;
    // 0x8002E0B8: addu        $t8, $s0, $t1
    ctx->r24 = ADD32(ctx->r16, ctx->r9);
    // 0x8002E0BC: lh          $a1, 0x2($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X2);
    // 0x8002E0C0: nop

    // 0x8002E0C4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_8002E0C8:
    // 0x8002E0C8: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8002E0CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E0D0: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E0D4: mflo        $t4
    ctx->r12 = lo;
    // 0x8002E0D8: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x8002E0DC: lh          $v0, 0x2($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X2);
    // 0x8002E0E0: nop

    // 0x8002E0E4: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002E0E8: beq         $at, $zero, L_8002E0FC
    if (ctx->r1 == 0) {
        // 0x8002E0EC: slt         $at, $a2, $v0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002E0FC;
    }
    // 0x8002E0EC: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002E0F0: b           L_8002E108
    // 0x8002E0F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8002E108;
    // 0x8002E0F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002E0F8: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_8002E0FC:
    // 0x8002E0FC: beq         $at, $zero, L_8002E108
    if (ctx->r1 == 0) {
        // 0x8002E100: nop
    
            goto L_8002E108;
    }
    // 0x8002E100: nop

    // 0x8002E104: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8002E108:
    // 0x8002E108: bne         $v1, $s2, L_8002E0C8
    if (ctx->r3 != ctx->r18) {
        // 0x8002E10C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8002E0C8;
    }
    // 0x8002E10C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002E110: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002E114: bne         $at, $zero, L_8002E1E0
    if (ctx->r1 != 0) {
        // 0x8002E118: slt         $at, $t7, $a1
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8002E1E0;
    }
    // 0x8002E118: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002E11C: bne         $at, $zero, L_8002E1E0
    if (ctx->r1 != 0) {
        // 0x8002E120: nop
    
            goto L_8002E1E0;
    }
    // 0x8002E120: nop

    // 0x8002E124: lbu         $t4, 0x2($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X2);
    // 0x8002E128: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002E12C: multu       $t4, $s1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E130: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002E134: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E138: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E13C: lwc1        $f16, 0xC($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0XC);
    // 0x8002E140: lbu         $t6, 0x3($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X3);
    // 0x8002E144: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002E148: lwc1        $f4, 0x14($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8002E14C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002E150: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8002E154: sw          $t3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r11;
    // 0x8002E158: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002E15C: mflo        $t5
    ctx->r13 = lo;
    // 0x8002E160: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002E164: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E168: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E16C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E170: addu        $a3, $t5, $s0
    ctx->r7 = ADD32(ctx->r13, ctx->r16);
    // 0x8002E174: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E178: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8002E17C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8002E180: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002E184: addu        $a2, $t1, $s0
    ctx->r6 = ADD32(ctx->r9, ctx->r16);
    // 0x8002E188: mflo        $t7
    ctx->r15 = lo;
    // 0x8002E18C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8002E190: jal         0x80070730
    // 0x8002E194: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    tri2d_xz_contains_point(rdram, ctx);
        goto after_1;
    // 0x8002E194: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8002E198: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8002E19C: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8002E1A0: beq         $v0, $zero, L_8002E1E0
    if (ctx->r2 == 0) {
        // 0x8002E1A4: sll         $t9, $fp, 2
        ctx->r25 = S32(ctx->r30 << 2);
            goto L_8002E1E0;
    }
    // 0x8002E1A4: sll         $t9, $fp, 2
    ctx->r25 = S32(ctx->r30 << 2);
    // 0x8002E1A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E1AC: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8002E1B0: lwc1        $f10, -0x320C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X320C);
    // 0x8002E1B4: lw          $v0, 0x54($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X54);
    // 0x8002E1B8: sub.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f10.fl;
    // 0x8002E1BC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002E1C0: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8002E1C4: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8002E1C8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E1CC: mul.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x8002E1D0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8002E1D4: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8002E1D8: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002E1DC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_8002E1E0:
    // 0x8002E1E0: lw          $t4, 0xC($s5)
    ctx->r12 = MEM_W(ctx->r21, 0XC);
    // 0x8002E1E4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002E1E8: addu        $v0, $t4, $t2
    ctx->r2 = ADD32(ctx->r12, ctx->r10);
    // 0x8002E1EC: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x8002E1F0: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8002E1F4: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002E1F8: beq         $at, $zero, L_8002E20C
    if (ctx->r1 == 0) {
        // 0x8002E1FC: lw          $t6, 0x78($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X78);
            goto L_8002E20C;
    }
    // 0x8002E1FC: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8002E200: beq         $s7, $zero, L_8002E064
    if (ctx->r23 == 0) {
        // 0x8002E204: nop
    
            goto L_8002E064;
    }
    // 0x8002E204: nop

L_8002E208:
    // 0x8002E208: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
L_8002E20C:
    // 0x8002E20C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8002E210: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002E214: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x8002E218: lh          $t8, 0x20($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X20);
    // 0x8002E21C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8002E220: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002E224: beq         $at, $zero, L_8002E238
    if (ctx->r1 == 0) {
        // 0x8002E228: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8002E238;
    }
    // 0x8002E228: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002E22C: beq         $s7, $zero, L_8002E018
    if (ctx->r23 == 0) {
        // 0x8002E230: nop
    
            goto L_8002E018;
    }
    // 0x8002E230: nop

L_8002E234:
    // 0x8002E234: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8002E238:
    // 0x8002E238: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002E23C: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002E240: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002E244: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002E248: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002E24C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002E250: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002E254: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002E258: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002E25C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002E260: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002E264: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002E268: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002E26C: jr          $ra
    // 0x8002E270: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8002E270: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void set_current_dialogue_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C551C: blez        $a0, L_800C5558
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C5520: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C5558;
    }
    // 0x800C5520: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C5524: beq         $at, $zero, L_800C5558
    if (ctx->r1 == 0) {
        // 0x800C5528: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C5558;
    }
    // 0x800C5528: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C552C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5530: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5534: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5538: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C553C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5540: sb          $a1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r5;
    // 0x800C5544: sb          $a2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r6;
    // 0x800C5548: sb          $a3, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r7;
    // 0x800C554C: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C5550: nop

    // 0x800C5554: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
L_800C5558:
    // 0x800C5558: jr          $ra
    // 0x800C555C: nop

    return;
    // 0x800C555C: nop

;}
RECOMP_FUNC void func_8000B38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B38C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8000B390: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8000B394: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8000B398: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8000B39C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8000B3A0: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8000B3A4: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x8000B3A8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8000B3AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000B3B0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8000B3B4: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x8000B3B8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8000B3BC: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000B3C0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8000B3C4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000B3C8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000B3CC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000B3D0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8000B3D4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8000B3D8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8000B3DC: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x8000B3E0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000B3E4: jal         0x800706D0
    // 0x8000B3E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    vec3f_rotate_py(rdram, ctx);
        goto after_0;
    // 0x8000B3E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8000B3EC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000B3F0: lwc1        $f10, 0xC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8000B3F4: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x8000B3F8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000B3FC: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8000B400: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000B404: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8000B408: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000B40C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B410: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B414: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000B418: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000B41C: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8000B420: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8000B424: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000B428: sh          $t7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r15;
    // 0x8000B42C: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8000B430: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000B434: addiu       $s2, $s2, -0x3328
    ctx->r18 = ADD32(ctx->r18, -0X3328);
    // 0x8000B438: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000B43C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000B440: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000B444: nop

    // 0x8000B448: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000B44C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B450: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B454: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000B458: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000B45C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B460: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000B464: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000B468: sh          $t9, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r25;
    // 0x8000B46C: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8000B470: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000B474: sh          $s4, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r20;
    // 0x8000B478: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000B47C: sh          $s4, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r20;
    // 0x8000B480: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B484: nop

    // 0x8000B488: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000B48C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000B490: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000B494: sh          $t7, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r15;
    // 0x8000B498: nop

L_8000B49C:
    // 0x8000B49C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8000B4A0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8000B4A4: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8000B4A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000B4AC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000B4B0: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x8000B4B4: lwc1        $f16, -0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, -0X4);
    // 0x8000B4B8: swc1        $f22, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f22.u32l;
    // 0x8000B4BC: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8000B4C0: jal         0x80070560
    // 0x8000B4C4: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x8000B4C4: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8000B4C8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000B4CC: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8000B4D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000B4D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000B4D8: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8000B4DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000B4E0: nop

    // 0x8000B4E4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000B4E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B4EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B4F0: nop

    // 0x8000B4F4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000B4F8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000B4FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000B500: sh          $t9, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r25;
    // 0x8000B504: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8000B508: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000B50C: nop

    // 0x8000B510: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000B514: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000B518: nop

    // 0x8000B51C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000B520: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B524: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B528: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000B52C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000B530: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B534: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000B538: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000B53C: sh          $t7, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r15;
    // 0x8000B540: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8000B544: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000B548: sh          $s4, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r20;
    // 0x8000B54C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000B550: sh          $s4, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r20;
    // 0x8000B554: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B558: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x8000B55C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000B560: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8000B564: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000B568: bne         $at, $zero, L_8000B49C
    if (ctx->r1 != 0) {
        // 0x8000B56C: sh          $t9, -0x6($s0)
        MEM_H(-0X6, ctx->r16) = ctx->r25;
            goto L_8000B49C;
    }
    // 0x8000B56C: sh          $t9, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r25;
    // 0x8000B570: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x8000B574: lh          $s1, 0xB6($sp)
    ctx->r17 = MEM_H(ctx->r29, 0XB6);
    // 0x8000B578: lbu         $s6, 0x1($v0)
    ctx->r22 = MEM_BU(ctx->r2, 0X1);
    // 0x8000B57C: lbu         $s2, 0x0($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X0);
    // 0x8000B580: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x8000B584: sll         $t7, $s6, 4
    ctx->r15 = S32(ctx->r22 << 4);
    // 0x8000B588: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8000B58C: sll         $t6, $s2, 4
    ctx->r14 = S32(ctx->r18 << 4);
    // 0x8000B590: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x8000B594: or          $s6, $t7, $zero
    ctx->r22 = ctx->r15 | 0;
    // 0x8000B598: sll         $s3, $t7, 16
    ctx->r19 = S32(ctx->r15 << 16);
    // 0x8000B59C: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x8000B5A0: addiu       $s5, $sp, 0xA0
    ctx->r21 = ADD32(ctx->r29, 0XA0);
    // 0x8000B5A4: lui         $s4, 0xFFFF
    ctx->r20 = S32(0XFFFF << 16);
L_8000B5A8:
    // 0x8000B5A8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8000B5AC: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000B5B0: jal         0x80070A70
    // 0x8000B5B4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    static_3_80070A70(rdram, ctx);
        goto after_2;
    // 0x8000B5B4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x8000B5B8: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000B5BC: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8000B5C0: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000B5C4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8000B5C8: mflo        $t9
    ctx->r25 = lo;
    // 0x8000B5CC: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8000B5D0: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x8000B5D4: jal         0x80070A6C
    // 0x8000B5D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    coss_s16(rdram, ctx);
        goto after_3;
    // 0x8000B5D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    after_3:
    // 0x8000B5DC: multu       $s6, $v0
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000B5E0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8000B5E4: addiu       $s1, $s1, 0x2000
    ctx->r17 = ADD32(ctx->r17, 0X2000);
    // 0x8000B5E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000B5EC: sltu        $at, $s0, $s5
    ctx->r1 = ctx->r16 < ctx->r21 ? 1 : 0;
    // 0x8000B5F0: mflo        $t6
    ctx->r14 = lo;
    // 0x8000B5F4: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x8000B5F8: and         $t8, $t7, $s4
    ctx->r24 = ctx->r15 & ctx->r20;
    // 0x8000B5FC: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8000B600: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000B604: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8000B608: sw          $t6, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r14;
    // 0x8000B60C: bne         $at, $zero, L_8000B5A8
    if (ctx->r1 != 0) {
        // 0x8000B610: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8000B5A8;
    }
    // 0x8000B610: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8000B614: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8000B618: andi        $t7, $s6, 0xFFFF
    ctx->r15 = ctx->r22 & 0XFFFF;
    // 0x8000B61C: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x8000B620: sh          $t9, 0xB6($sp)
    MEM_H(0XB6, ctx->r29) = ctx->r25;
    // 0x8000B624: or          $t4, $t6, $t7
    ctx->r12 = ctx->r14 | ctx->r15;
    // 0x8000B628: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000B62C: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x8000B630: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8000B634: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
L_8000B638:
    // 0x8000B638: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x8000B63C: andi        $a2, $a1, 0x7
    ctx->r6 = ctx->r5 & 0X7;
    // 0x8000B640: addiu       $t8, $a2, 0x1
    ctx->r24 = ADD32(ctx->r6, 0X1);
    // 0x8000B644: sll         $t9, $a1, 8
    ctx->r25 = S32(ctx->r5 << 8);
    // 0x8000B648: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000B64C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000B650: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8000B654: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8000B658: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8000B65C: addu        $t8, $a0, $t9
    ctx->r24 = ADD32(ctx->r4, ctx->r25);
    // 0x8000B660: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8000B664: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8000B668: addiu       $a3, $s1, 0x2
    ctx->r7 = ADD32(ctx->r17, 0X2);
    // 0x8000B66C: andi        $t0, $a3, 0x7
    ctx->r8 = ctx->r7 & 0X7;
    // 0x8000B670: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x8000B674: sll         $t7, $a3, 8
    ctx->r15 = S32(ctx->r7 << 8);
    // 0x8000B678: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8000B67C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x8000B680: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x8000B684: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x8000B688: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8000B68C: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8000B690: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x8000B694: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x8000B698: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8000B69C: addiu       $t1, $s1, 0x3
    ctx->r9 = ADD32(ctx->r17, 0X3);
    // 0x8000B6A0: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x8000B6A4: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x8000B6A8: sll         $t6, $t1, 8
    ctx->r14 = S32(ctx->r9 << 8);
    // 0x8000B6AC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8000B6B0: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    // 0x8000B6B4: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    // 0x8000B6B8: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x8000B6BC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8000B6C0: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8000B6C4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8000B6C8: sw          $t8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r24;
    // 0x8000B6CC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8000B6D0: addiu       $v1, $s1, 0x4
    ctx->r3 = ADD32(ctx->r17, 0X4);
    // 0x8000B6D4: andi        $t3, $v1, 0x7
    ctx->r11 = ctx->r3 & 0X7;
    // 0x8000B6D8: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x8000B6DC: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x8000B6E0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8000B6E4: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
    // 0x8000B6E8: sw          $t4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r12;
    // 0x8000B6EC: sw          $t9, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r25;
    // 0x8000B6F0: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8000B6F4: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8000B6F8: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x8000B6FC: sw          $t9, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r25;
    // 0x8000B700: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000B704: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8000B708: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8000B70C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8000B710: bne         $v1, $t5, L_8000B638
    if (ctx->r3 != ctx->r13) {
        // 0x8000B714: sw          $t7, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r15;
            goto L_8000B638;
    }
    // 0x8000B714: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x8000B718: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000B71C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8000B720: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000B724: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8000B728: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000B72C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000B730: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B734: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000B738: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8000B73C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000B740: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000B744: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8000B748: jr          $ra
    // 0x8000B74C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8000B74C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void _freePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006595C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065964: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065968: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006596C: jal         0x800C8CC0
    // 0x80065970: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x80065970: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80065974: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80065978: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006597C: jal         0x800C8CF0
    // 0x80065980: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    alLink(rdram, ctx);
        goto after_1;
    // 0x80065980: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x80065984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006598C: jr          $ra
    // 0x80065990: nop

    return;
    // 0x80065990: nop

;}
RECOMP_FUNC void sndp_set_active_sound_limit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000318C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80003190: lw          $v0, -0x33D4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X33D4);
    // 0x80003194: nop

    // 0x80003198: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x8000319C: nop

    // 0x800031A0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800031A4: bne         $at, $zero, L_800031B4
    if (ctx->r1 != 0) {
        // 0x800031A8: nop
    
            goto L_800031B4;
    }
    // 0x800031A8: nop

    // 0x800031AC: jr          $ra
    // 0x800031B0: sw          $a0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r4;
    return;
    // 0x800031B0: sw          $a0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r4;
L_800031B4:
    // 0x800031B4: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x800031B8: jr          $ra
    // 0x800031BC: nop

    return;
    // 0x800031BC: nop

;}
RECOMP_FUNC void get_checkpoint_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BA9C: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
    // 0x8001BAA0: jr          $ra
    // 0x8001BAA4: nop

    return;
    // 0x8001BAA4: nop

;}
RECOMP_FUNC void homing_rocket_get_next_direction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019590: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80019594: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80019598: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8001959C: lw          $s6, -0x4BB0($s6)
    ctx->r22 = MEM_W(ctx->r22, -0X4BB0);
    // 0x800195A0: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x800195A4: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800195A8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x800195AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800195B0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800195B4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800195B8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800195BC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800195C0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800195C4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800195C8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800195CC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800195D0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800195D4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800195D8: bne         $s6, $zero, L_800195E8
    if (ctx->r22 != 0) {
        // 0x800195DC: sw          $a0, 0xC0($sp)
        MEM_W(0XC0, ctx->r29) = ctx->r4;
            goto L_800195E8;
    }
    // 0x800195DC: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800195E0: b           L_80019804
    // 0x800195E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80019804;
    // 0x800195E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800195E8:
    // 0x800195E8: addiu       $v0, $a1, -0x2
    ctx->r2 = ADD32(ctx->r5, -0X2);
    // 0x800195EC: bgez        $v0, L_800195F8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800195F0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800195F8;
    }
    // 0x800195F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800195F4: addu        $s1, $v0, $s6
    ctx->r17 = ADD32(ctx->r2, ctx->r22);
L_800195F8:
    // 0x800195F8: mtc1        $a3, $f18
    ctx->f18.u32l = ctx->r7;
    // 0x800195FC: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x80019600: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80019604: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80019608: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8001960C: cvt.s.w     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    ctx->f22.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80019610: addiu       $s2, $sp, 0xA4
    ctx->r18 = ADD32(ctx->r29, 0XA4);
    // 0x80019614: addiu       $s3, $sp, 0x94
    ctx->r19 = ADD32(ctx->r29, 0X94);
    // 0x80019618: addiu       $s0, $sp, 0x84
    ctx->r16 = ADD32(ctx->r29, 0X84);
    // 0x8001961C: addiu       $s5, $sp, 0x94
    ctx->r21 = ADD32(ctx->r29, 0X94);
L_80019620:
    // 0x80019620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80019624: jal         0x8001BA50
    // 0x80019628: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_0;
    // 0x80019628: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8001962C: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80019630: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80019634: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80019638: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001963C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80019640: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80019644: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80019648: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8001964C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80019650: swc1        $f8, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->f8.u32l;
    // 0x80019654: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80019658: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001965C: mul.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80019660: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80019664: swc1        $f4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f4.u32l;
    // 0x80019668: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001966C: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80019670: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x80019674: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80019678: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8001967C: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80019680: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80019684: bne         $s1, $s6, L_80019690
    if (ctx->r17 != ctx->r22) {
        // 0x80019688: swc1        $f8, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f8.u32l;
            goto L_80019690;
    }
    // 0x80019688: swc1        $f8, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8001968C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80019690:
    // 0x80019690: bne         $s0, $s5, L_80019620
    if (ctx->r16 != ctx->r21) {
        // 0x80019694: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80019620;
    }
    // 0x80019694: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80019698: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8001969C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800196A0: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800196A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800196A8: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x800196AC: sub.d       $f18, $f2, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f2.d - ctx->f6.d;
    // 0x800196B0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800196B4: cvt.s.d     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f20.fl = CVT_S_D(ctx->f18.d);
    // 0x800196B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800196BC: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x800196C0: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x800196C4: bc1f        L_800196D0
    if (!c1cs) {
        // 0x800196C8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800196D0;
    }
    // 0x800196C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800196CC: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_800196D0:
    // 0x800196D0: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x800196D4: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x800196D8: nop

    // 0x800196DC: bc1f        L_800196EC
    if (!c1cs) {
        // 0x800196E0: nop
    
            goto L_800196EC;
    }
    // 0x800196E0: nop

    // 0x800196E4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800196E8: nop

L_800196EC:
    // 0x800196EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800196F0: jal         0x80022670
    // 0x800196F4: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    cubic_spline_interpolation(rdram, ctx);
        goto after_1;
    // 0x800196F4: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    after_1:
    // 0x800196F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800196FC: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x80019700: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80019704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019708: jal         0x80022670
    // 0x8001970C: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_2;
    // 0x8001970C: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_2:
    // 0x80019710: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80019714: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80019718: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8001971C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019720: jal         0x80022670
    // 0x80019724: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    cubic_spline_interpolation(rdram, ctx);
        goto after_3;
    // 0x80019724: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x80019728: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001972C: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80019730: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80019734: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80019738: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8001973C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80019740: nop

    // 0x80019744: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80019748: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001974C: jal         0x800CA030
    // 0x80019750: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80019750: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_4:
    // 0x80019754: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80019758: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001975C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80019760: nop

    // 0x80019764: bc1t        L_800197AC
    if (c1cs) {
        // 0x80019768: nop
    
            goto L_800197AC;
    }
    // 0x80019768: nop

    // 0x8001976C: lwc1        $f9, 0x5BC0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5BC0);
    // 0x80019770: lwc1        $f8, 0x5BC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5BC4);
    // 0x80019774: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80019778: nop

    // 0x8001977C: div.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80019780: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80019784: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80019788: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001978C: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x80019790: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80019794: nop

    // 0x80019798: mul.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8001979C: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    // 0x800197A0: mul.s       $f16, $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800197A4: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800197A8: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
L_800197AC:
    // 0x800197AC: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800197B0: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800197B4: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x800197B8: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800197BC: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800197C0: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x800197C4: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800197C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800197CC: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x800197D0: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800197D4: lwc1        $f8, 0x10($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X10);
    // 0x800197D8: add.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f18.fl;
    // 0x800197DC: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x800197E0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800197E4: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x800197E8: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800197EC: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800197F0: lwc1        $f8, 0x14($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X14);
    // 0x800197F4: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800197F8: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x800197FC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80019800: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
L_80019804:
    // 0x80019804: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80019808: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8001980C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80019810: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80019814: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80019818: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001981C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80019820: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80019824: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80019828: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8001982C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80019830: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80019834: jr          $ra
    // 0x80019838: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80019838: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void get_npc_pos_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ACEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003ACF0: lwc1        $f0, -0x25B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25B0);
    // 0x8003ACF4: jr          $ra
    // 0x8003ACF8: nop

    return;
    // 0x8003ACF8: nop

;}
RECOMP_FUNC void obj_init_flycoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D2EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003D2F0: jr          $ra
    // 0x8003D2F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003D2F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void load_level_for_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E528: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006E52C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006E530: lb          $t6, 0x3A94($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3A94);
    // 0x8006E534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E538: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006E53C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006E540: bne         $t6, $zero, L_8006E5AC
    if (ctx->r14 != 0) {
        // 0x8006E544: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8006E5AC;
    }
    // 0x8006E544: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006E548: jal         0x8006DE24
    // 0x8006E54C: nop

    unload_level_menu(rdram, ctx);
        goto after_0;
    // 0x8006E54C: nop

    after_0:
    // 0x8006E550: jal         0x800C7940
    // 0x8006E554: nop

    bgload_active(rdram, ctx);
        goto after_1;
    // 0x8006E554: nop

    after_1:
    // 0x8006E558: bne         $v0, $zero, L_8006E5AC
    if (ctx->r2 != 0) {
        // 0x8006E55C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8006E5AC;
    }
    // 0x8006E55C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E560: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006E564: lw          $t7, 0x3A68($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3A68);
    // 0x8006E568: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006E56C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006E570: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006E574: lw          $t9, 0x1770($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1770);
    // 0x8006E578: addiu       $v1, $v1, 0x1778
    ctx->r3 = ADD32(ctx->r3, 0X1778);
    // 0x8006E57C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006E580: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8006E584: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8006E588: lui         $t1, 0xE900
    ctx->r9 = S32(0XE900 << 16);
    // 0x8006E58C: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8006E590: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8006E594: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006E598: lui         $t3, 0xB800
    ctx->r11 = S32(0XB800 << 16);
    // 0x8006E59C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8006E5A0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8006E5A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006E5A8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8006E5AC:
    // 0x8006E5AC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8006E5B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006E5B4: beq         $t4, $at, L_8006E5E4
    if (ctx->r12 == ctx->r1) {
        // 0x8006E5B8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8006E5E4;
    }
    // 0x8006E5B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006E5BC: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8006E5C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006E5C4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8006E5C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006E5CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8006E5D0: jal         0x8006DD7C
    // 0x8006E5D4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    load_level_menu(rdram, ctx);
        goto after_2;
    // 0x8006E5D4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8006E5D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E5DC: b           L_8006E5EC
    // 0x8006E5E0: sb          $zero, 0x3A94($at)
    MEM_B(0X3A94, ctx->r1) = 0;
        goto L_8006E5EC;
    // 0x8006E5E0: sb          $zero, 0x3A94($at)
    MEM_B(0X3A94, ctx->r1) = 0;
L_8006E5E4:
    // 0x8006E5E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E5E8: sb          $t6, 0x3A94($at)
    MEM_B(0X3A94, ctx->r1) = ctx->r14;
L_8006E5EC:
    // 0x8006E5EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E5F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006E5F4: jr          $ra
    // 0x8006E5F8: nop

    return;
    // 0x8006E5F8: nop

;}
RECOMP_FUNC void dmacopy_v1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800773D4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800773D8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800773DC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800773E0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800773E4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800773E8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800773EC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800773F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800773F4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800773F8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800773FC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80077400: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80077404: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80077408: jal         0x800D1D50
    // 0x8007740C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x8007740C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80077410: blez        $s1, L_80077478
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80077414: addiu       $s0, $zero, 0x5000
        ctx->r16 = ADD32(0, 0X5000);
            goto L_80077478;
    }
    // 0x80077414: addiu       $s0, $zero, 0x5000
    ctx->r16 = ADD32(0, 0X5000);
    // 0x80077418: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8007741C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80077420: addiu       $s4, $s4, 0x47A0
    ctx->r20 = ADD32(ctx->r20, 0X47A0);
    // 0x80077424: addiu       $s5, $s5, 0x4780
    ctx->r21 = ADD32(ctx->r21, 0X4780);
    // 0x80077428: addiu       $s6, $sp, 0x4C
    ctx->r22 = ADD32(ctx->r29, 0X4C);
L_8007742C:
    // 0x8007742C: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80077430: beq         $at, $zero, L_8007743C
    if (ctx->r1 == 0) {
        // 0x80077434: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8007743C;
    }
    // 0x80077434: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80077438: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8007743C:
    // 0x8007743C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80077440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80077444: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80077448: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8007744C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80077450: jal         0x800C94E0
    // 0x80077454: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x80077454: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    after_1:
    // 0x80077458: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8007745C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80077460: jal         0x800C9110
    // 0x80077464: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077464: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80077468: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8007746C: addu        $s3, $s3, $s0
    ctx->r19 = ADD32(ctx->r19, ctx->r16);
    // 0x80077470: bgtz        $s1, L_8007742C
    if (SIGNED(ctx->r17) > 0) {
        // 0x80077474: addu        $s2, $s2, $s0
        ctx->r18 = ADD32(ctx->r18, ctx->r16);
            goto L_8007742C;
    }
    // 0x80077474: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
L_80077478:
    // 0x80077478: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8007747C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80077480: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80077484: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80077488: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8007748C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80077490: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80077494: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80077498: jr          $ra
    // 0x8007749C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007749C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void waves_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAE04: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x800BAE08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BAE0C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800BAE10: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800BAE14: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800BAE18: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800BAE1C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800BAE20: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800BAE24: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800BAE28: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800BAE2C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800BAE30: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800BAE34: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BAE38: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x800BAE3C: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BAE40: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x800BAE44: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BAE48: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800BAE4C: sw          $a0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r4;
    // 0x800BAE50: bne         $a2, $at, L_800BAE6C
    if (ctx->r6 != ctx->r1) {
        // 0x800BAE54: sw          $a1, 0x124($sp)
        MEM_W(0X124, ctx->r29) = ctx->r5;
            goto L_800BAE6C;
    }
    // 0x800BAE54: sw          $a1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r5;
    // 0x800BAE58: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BAE5C: lw          $t6, -0x59C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X59C8);
    // 0x800BAE60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BAE64: beq         $t6, $at, L_800BAE74
    if (ctx->r14 == ctx->r1) {
        // 0x800BAE68: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800BAE74;
    }
    // 0x800BAE68: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_800BAE6C:
    // 0x800BAE6C: b           L_800BAE78
    // 0x800BAE70: sw          $zero, 0x128($sp)
    MEM_W(0X128, ctx->r29) = 0;
        goto L_800BAE78;
    // 0x800BAE70: sw          $zero, 0x128($sp)
    MEM_W(0X128, ctx->r29) = 0;
L_800BAE74:
    // 0x800BAE74: sw          $t7, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r15;
L_800BAE78:
    // 0x800BAE78: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BAE7C: lw          $t8, 0x366C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X366C);
    // 0x800BAE80: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BAE84: blez        $t8, L_800BB7C4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800BAE88: addiu       $s1, $s1, -0x5A80
        ctx->r17 = ADD32(ctx->r17, -0X5A80);
            goto L_800BB7C4;
    }
    // 0x800BAE88: addiu       $s1, $s1, -0x5A80
    ctx->r17 = ADD32(ctx->r17, -0X5A80);
    // 0x800BAE8C: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x800BAE90: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x800BAE94: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800BAE98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BAE9C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BAEA0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800BAEA4: sw          $zero, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = 0;
    // 0x800BAEA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BAEAC: jal         0x8007B820
    // 0x800BAEB0: sw          $t8, -0x5A7C($at)
    MEM_W(-0X5A7C, ctx->r1) = ctx->r24;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800BAEB0: sw          $t8, -0x5A7C($at)
    MEM_W(-0X5A7C, ctx->r1) = ctx->r24;
    after_0:
    // 0x800BAEB4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAEB8: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BAEBC: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BAEC0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BAEC4: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x800BAEC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BAECC: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BAED0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BAED4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BAED8: lw          $t8, 0x4C($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X4C);
    // 0x800BAEDC: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x800BAEE0: beq         $t8, $zero, L_800BB0A0
    if (ctx->r24 == 0) {
        // 0x800BAEE4: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800BB0A0;
    }
    // 0x800BAEE4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BAEE8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAEEC: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x800BAEF0: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BAEF4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BAEF8: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x800BAEFC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BAF00: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BAF04: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BAF08: lw          $a1, -0x59A4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X59A4);
    // 0x800BAF0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BAF10: lw          $a0, 0x3660($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3660);
    // 0x800BAF14: sll         $t8, $a1, 8
    ctx->r24 = S32(ctx->r5 << 8);
    // 0x800BAF18: jal         0x8007B8BC
    // 0x800BAF1C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_1;
    // 0x800BAF1C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_1:
    // 0x800BAF20: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BAF24: lw          $t9, -0x59C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X59C4);
    // 0x800BAF28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BAF2C: lbu         $a1, 0x7($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X7);
    // 0x800BAF30: lw          $a0, -0x59C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X59C0);
    // 0x800BAF34: sll         $t6, $a1, 14
    ctx->r14 = S32(ctx->r5 << 14);
    // 0x800BAF38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800BAF3C: jal         0x8007B8BC
    // 0x800BAF40: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_2;
    // 0x800BAF40: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_2:
    // 0x800BAF44: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800BAF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BAF4C: jal         0x800BA9D8
    // 0x800BAF50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wave_load_material(rdram, ctx);
        goto after_3;
    // 0x800BAF50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x800BAF54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BAF58: jal         0x800BA9D8
    // 0x800BAF5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    wave_load_material(rdram, ctx);
        goto after_4;
    // 0x800BAF5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800BAF60: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAF64: lui         $t8, 0xFC22
    ctx->r24 = S32(0XFC22 << 16);
    // 0x800BAF68: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BAF6C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BAF70: lui         $t9, 0x1010
    ctx->r25 = S32(0X1010 << 16);
    // 0x800BAF74: ori         $t9, $t9, 0x923F
    ctx->r25 = ctx->r25 | 0X923F;
    // 0x800BAF78: ori         $t8, $t8, 0x66AC
    ctx->r24 = ctx->r24 | 0X66AC;
    // 0x800BAF7C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800BAF80: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BAF84: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x800BAF88: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BAF8C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800BAF90: bne         $t7, $zero, L_800BAFD4
    if (ctx->r15 != 0) {
        // 0x800BAF94: addiu       $ra, $ra, -0x5A78
        ctx->r31 = ADD32(ctx->r31, -0X5A78);
            goto L_800BAFD4;
    }
    // 0x800BAF94: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BAF98: jal         0x80066450
    // 0x800BAF9C: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_5;
    // 0x800BAF9C: nop

    after_5:
    // 0x800BAFA0: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BAFA4: bgtz        $v0, L_800BAFD4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800BAFA8: addiu       $ra, $ra, -0x5A78
        ctx->r31 = ADD32(ctx->r31, -0X5A78);
            goto L_800BAFD4;
    }
    // 0x800BAFA8: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BAFAC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAFB0: lui         $t9, 0xEF18
    ctx->r25 = S32(0XEF18 << 16);
    // 0x800BAFB4: lui         $t6, 0x10
    ctx->r14 = S32(0X10 << 16);
    // 0x800BAFB8: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BAFBC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BAFC0: ori         $t6, $t6, 0x45D8
    ctx->r14 = ctx->r14 | 0X45D8;
    // 0x800BAFC4: ori         $t9, $t9, 0x2C0F
    ctx->r25 = ctx->r25 | 0X2C0F;
    // 0x800BAFC8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BAFCC: b           L_800BAFF8
    // 0x800BAFD0: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
        goto L_800BAFF8;
    // 0x800BAFD0: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
L_800BAFD4:
    // 0x800BAFD4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAFD8: lui         $t8, 0xEF18
    ctx->r24 = S32(0XEF18 << 16);
    // 0x800BAFDC: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BAFE0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BAFE4: lui         $t9, 0x11
    ctx->r25 = S32(0X11 << 16);
    // 0x800BAFE8: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x800BAFEC: ori         $t8, $t8, 0x2C0F
    ctx->r24 = ctx->r24 | 0X2C0F;
    // 0x800BAFF0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800BAFF4: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
L_800BAFF8:
    // 0x800BAFF8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAFFC: addiu       $v1, $zero, -0x100
    ctx->r3 = ADD32(0, -0X100);
    // 0x800BB000: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800BB004: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BB008: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BB00C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800BB010: addiu       $t1, $t1, 0x3710
    ctx->r9 = ADD32(ctx->r9, 0X3710);
    // 0x800BB014: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB018: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x800BB01C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BB020: nop

    // 0x800BB024: beq         $t8, $zero, L_800BB080
    if (ctx->r24 == 0) {
        // 0x800BB028: nop
    
            goto L_800BB080;
    }
    // 0x800BB028: nop

    // 0x800BB02C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB030: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800BB034: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BB038: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BB03C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BB040: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800BB044: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
    // 0x800BB048: lbu         $t8, 0x10($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X10);
    // 0x800BB04C: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x800BB050: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800BB054: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800BB058: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800BB05C: lbu         $t9, 0x12($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X12);
    // 0x800BB060: nop

    // 0x800BB064: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x800BB068: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800BB06C: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x800BB070: nop

    // 0x800BB074: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800BB078: b           L_800BB200
    // 0x800BB07C: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
        goto L_800BB200;
    // 0x800BB07C: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
L_800BB080:
    // 0x800BB080: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB084: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800BB088: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BB08C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BB090: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x800BB094: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB098: b           L_800BB200
    // 0x800BB09C: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
        goto L_800BB200;
    // 0x800BB09C: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
L_800BB0A0:
    // 0x800BB0A0: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB0A4: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x800BB0A8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800BB0AC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BB0B0: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BB0B4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800BB0B8: lw          $t7, -0x59C4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X59C4);
    // 0x800BB0BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB0C0: lbu         $a1, 0x7($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X7);
    // 0x800BB0C4: lw          $a0, -0x59C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X59C0);
    // 0x800BB0C8: sll         $t6, $a1, 14
    ctx->r14 = S32(ctx->r5 << 14);
    // 0x800BB0CC: jal         0x8007B8BC
    // 0x800BB0D0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_6;
    // 0x800BB0D0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_6:
    // 0x800BB0D4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB0D8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BB0DC: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB0E0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB0E4: lh          $a0, 0xA($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XA);
    // 0x800BB0E8: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
    // 0x800BB0EC: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x800BB0F0: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800BB0F4: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x800BB0F8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800BB0FC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800BB100: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800BB104: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB108: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800BB10C: lui         $t7, 0xFC56
    ctx->r15 = S32(0XFC56 << 16);
    // 0x800BB110: addu        $t6, $t8, $s2
    ctx->r14 = ADD32(ctx->r24, ctx->r18);
    // 0x800BB114: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800BB118: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB11C: lui         $t8, 0x1FFC
    ctx->r24 = S32(0X1FFC << 16);
    // 0x800BB120: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BB124: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BB128: ori         $t8, $t8, 0xF7F8
    ctx->r24 = ctx->r24 | 0XF7F8;
    // 0x800BB12C: ori         $t7, $t7, 0x7E04
    ctx->r15 = ctx->r15 | 0X7E04;
    // 0x800BB130: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB134: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800BB138: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB13C: lui         $t7, 0xC811
    ctx->r15 = S32(0XC811 << 16);
    // 0x800BB140: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800BB144: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BB148: lui         $t9, 0xEF18
    ctx->r25 = S32(0XEF18 << 16);
    // 0x800BB14C: ori         $t9, $t9, 0x2C0F
    ctx->r25 = ctx->r25 | 0X2C0F;
    // 0x800BB150: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x800BB154: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BB158: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB15C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB160: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BB164: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB168: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB16C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800BB170: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800BB174: addiu       $t1, $t1, 0x3710
    ctx->r9 = ADD32(ctx->r9, 0X3710);
    // 0x800BB178: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BB17C: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BB180: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BB184: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB188: beq         $t7, $zero, L_800BB1E4
    if (ctx->r15 == 0) {
        // 0x800BB18C: addiu       $ra, $ra, -0x5A78
        ctx->r31 = ADD32(ctx->r31, -0X5A78);
            goto L_800BB1E4;
    }
    // 0x800BB18C: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BB190: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB194: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800BB198: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB19C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB1A0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BB1A4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800BB1A8: nop

    // 0x800BB1AC: lbu         $t7, 0x10($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X10);
    // 0x800BB1B0: lbu         $t9, 0x11($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X11);
    // 0x800BB1B4: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800BB1B8: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800BB1BC: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800BB1C0: lbu         $t8, 0x12($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X12);
    // 0x800BB1C4: nop

    // 0x800BB1C8: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x800BB1CC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800BB1D0: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x800BB1D4: nop

    // 0x800BB1D8: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800BB1DC: b           L_800BB200
    // 0x800BB1E0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
        goto L_800BB200;
    // 0x800BB1E0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
L_800BB1E4:
    // 0x800BB1E4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB1E8: addiu       $v1, $zero, -0x100
    ctx->r3 = ADD32(0, -0X100);
    // 0x800BB1EC: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB1F0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB1F4: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800BB1F8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB1FC: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
L_800BB200:
    // 0x800BB200: lw          $t6, 0x28($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X28);
    // 0x800BB204: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB208: beq         $t6, $zero, L_800BB228
    if (ctx->r14 == 0) {
        // 0x800BB20C: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800BB228;
    }
    // 0x800BB20C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BB210: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BB214: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BB218: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB21C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800BB220: b           L_800BB238
    // 0x800BB224: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
        goto L_800BB238;
    // 0x800BB224: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
L_800BB228:
    // 0x800BB228: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800BB22C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BB230: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BB234: swc1        $f24, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f24.u32l;
L_800BB238:
    // 0x800BB238: lw          $t7, 0x366C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X366C);
    // 0x800BB23C: sh          $zero, 0xE8($sp)
    MEM_H(0XE8, ctx->r29) = 0;
    // 0x800BB240: sh          $zero, 0xE6($sp)
    MEM_H(0XE6, ctx->r29) = 0;
    // 0x800BB244: blez        $t7, L_800BB760
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800BB248: sh          $zero, 0xE4($sp)
        MEM_H(0XE4, ctx->r29) = 0;
            goto L_800BB760;
    }
    // 0x800BB248: sh          $zero, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = 0;
    // 0x800BB24C: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x800BB250: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BB254: addiu       $t6, $t6, -0x5858
    ctx->r14 = ADD32(ctx->r14, -0X5858);
    // 0x800BB258: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BB25C: addu        $s0, $t9, $t6
    ctx->r16 = ADD32(ctx->r25, ctx->r14);
    // 0x800BB260: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800BB264: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800BB268: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800BB26C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800BB270: addiu       $s3, $s3, -0x5A28
    ctx->r19 = ADD32(ctx->r19, -0X5A28);
    // 0x800BB274: addiu       $s5, $s5, 0x3600
    ctx->r21 = ADD32(ctx->r21, 0X3600);
    // 0x800BB278: addiu       $s7, $s7, 0x3610
    ctx->r23 = ADD32(ctx->r23, 0X3610);
    // 0x800BB27C: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
    // 0x800BB280: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x800BB284: lui         $s4, 0x400
    ctx->r20 = S32(0X400 << 16);
L_800BB288:
    // 0x800BB288: lw          $t7, 0x4C($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X4C);
    // 0x800BB28C: lw          $s0, 0x74($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X74);
    // 0x800BB290: beq         $t7, $zero, L_800BB2B4
    if (ctx->r15 == 0) {
        // 0x800BB294: nop
    
            goto L_800BB2B4;
    }
    // 0x800BB294: nop

    // 0x800BB298: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800BB29C: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x800BB2A0: jal         0x800B9814
    // 0x800BB2A4: nop

    func_800B92F4(rdram, ctx);
        goto after_7;
    // 0x800BB2A4: nop

    after_7:
    // 0x800BB2A8: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB2AC: b           L_800BB2CC
    // 0x800BB2B0: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
        goto L_800BB2CC;
    // 0x800BB2B0: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
L_800BB2B4:
    // 0x800BB2B4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800BB2B8: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x800BB2BC: jal         0x800B9CC8
    // 0x800BB2C0: nop

    func_800B97A8(rdram, ctx);
        goto after_8;
    // 0x800BB2C0: nop

    after_8:
    // 0x800BB2C4: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB2C8: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
L_800BB2CC:
    // 0x800BB2CC: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800BB2D0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BB2D4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BB2D8: lw          $t6, 0x3668($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3668);
    // 0x800BB2DC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800BB2E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BB2E4: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x800BB2E8: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800BB2EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BB2F0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BB2F4: lw          $t6, 0x3664($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3664);
    // 0x800BB2F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB2FC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BB300: addiu       $a1, $a1, -0x5A7C
    ctx->r5 = ADD32(ctx->r5, -0X5A7C);
    // 0x800BB304: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    // 0x800BB308: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x800BB30C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BB310: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800BB314: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x800BB318: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BB31C: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
    // 0x800BB320: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x800BB324: nop

    // 0x800BB328: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800BB32C: nop

    // 0x800BB330: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BB334: swc1        $f18, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f18.u32l;
    // 0x800BB338: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800BB33C: nop

    // 0x800BB340: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BB344: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800BB348: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800BB34C: lw          $t6, 0x28($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X28);
    // 0x800BB350: sw          $t7, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r15;
    // 0x800BB354: beq         $t6, $zero, L_800BB5E8
    if (ctx->r14 == 0) {
        // 0x800BB358: nop
    
            goto L_800BB5E8;
    }
    // 0x800BB358: nop

    // 0x800BB35C: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
    // 0x800BB360: sw          $v0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r2;
    // 0x800BB364: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
L_800BB368:
    // 0x800BB368: lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE0);
    // 0x800BB36C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800BB370: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800BB374: nop

    // 0x800BB378: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BB37C: nop

    // 0x800BB380: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BB384: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
L_800BB388:
    // 0x800BB388: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BB38C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800BB390: addiu       $a1, $a1, -0x5A7C
    ctx->r5 = ADD32(ctx->r5, -0X5A7C);
    // 0x800BB394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BB398: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x800BB39C: jal         0x800696C4
    // 0x800BB3A0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_9;
    // 0x800BB3A0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_9:
    // 0x800BB3A4: lw          $a1, 0x104($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X104);
    // 0x800BB3A8: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB3AC: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x800BB3B0: beq         $t9, $zero, L_800BB4E0
    if (ctx->r25 == 0) {
        // 0x800BB3B4: addiu       $ra, $ra, -0x5A78
        ctx->r31 = ADD32(ctx->r31, -0X5A78);
            goto L_800BB4E0;
    }
    // 0x800BB3B4: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BB3B8: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BB3BC: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x800BB3C0: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x800BB3C4: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB3C8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800BB3CC: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800BB3D0: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800BB3D4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800BB3D8: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x800BB3DC: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x800BB3E0: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x800BB3E4: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x800BB3E8: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x800BB3EC: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x800BB3F0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800BB3F4: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB3F8: ori         $t7, $t9, 0x1
    ctx->r15 = ctx->r25 | 0X1;
    // 0x800BB3FC: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800BB400: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB404: andi        $t6, $t4, 0xFFFF
    ctx->r14 = ctx->r12 & 0XFFFF;
    // 0x800BB408: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x800BB40C: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x800BB410: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800BB414: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x800BB418: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800BB41C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800BB420: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x800BB424: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BB428: mflo        $t0
    ctx->r8 = lo;
    // 0x800BB42C: blez        $a2, L_800BB578
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BB430: nop
    
            goto L_800BB578;
    }
    // 0x800BB430: nop

L_800BB434:
    // 0x800BB434: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB438: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800BB43C: lw          $t7, 0x128($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X128);
    // 0x800BB440: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB444: addu        $a0, $t8, $t7
    ctx->r4 = ADD32(ctx->r24, ctx->r15);
    // 0x800BB448: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800BB44C: addu        $t6, $s5, $t9
    ctx->r14 = ADD32(ctx->r21, ctx->r25);
    // 0x800BB450: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800BB454: addu        $t9, $s7, $t9
    ctx->r25 = ADD32(ctx->r23, ctx->r25);
    // 0x800BB458: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800BB45C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BB460: addu        $t1, $t8, $t7
    ctx->r9 = ADD32(ctx->r24, ctx->r15);
    // 0x800BB464: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800BB468: multu       $s0, $t8
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB46C: addu        $a1, $t1, $s2
    ctx->r5 = ADD32(ctx->r9, ctx->r18);
    // 0x800BB470: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB474: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB478: sw          $a1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r5;
    // 0x800BB47C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BB480: mflo        $t7
    ctx->r15 = lo;
    // 0x800BB484: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800BB488: andi        $t7, $a1, 0x6
    ctx->r15 = ctx->r5 & 0X6;
    // 0x800BB48C: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x800BB490: or          $t6, $t3, $t7
    ctx->r14 = ctx->r11 | ctx->r15;
    // 0x800BB494: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800BB498: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800BB49C: or          $t7, $t8, $s4
    ctx->r15 = ctx->r24 | ctx->r20;
    // 0x800BB4A0: or          $t6, $t7, $t4
    ctx->r14 = ctx->r15 | ctx->r12;
    // 0x800BB4A4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BB4A8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB4AC: addu        $t8, $t2, $s2
    ctx->r24 = ADD32(ctx->r10, ctx->r18);
    // 0x800BB4B0: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BB4B4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BB4B8: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800BB4BC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800BB4C0: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BB4C4: nop

    // 0x800BB4C8: slt         $at, $s0, $a2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BB4CC: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x800BB4D0: bne         $at, $zero, L_800BB434
    if (ctx->r1 != 0) {
        // 0x800BB4D4: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BB434;
    }
    // 0x800BB4D4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800BB4D8: b           L_800BB578
    // 0x800BB4DC: nop

        goto L_800BB578;
    // 0x800BB4DC: nop

L_800BB4E0:
    // 0x800BB4E0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800BB4E4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800BB4E8: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB4EC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB4F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB4F4: addiu       $a0, $a0, -0x5A18
    ctx->r4 = ADD32(ctx->r4, -0X5A18);
    // 0x800BB4F8: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BB4FC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BB500: mflo        $t9
    ctx->r25 = lo;
    // 0x800BB504: addu        $t8, $a0, $t9
    ctx->r24 = ADD32(ctx->r4, ctx->r25);
    // 0x800BB508: addu        $t7, $t8, $s2
    ctx->r15 = ADD32(ctx->r24, ctx->r18);
    // 0x800BB50C: andi        $t6, $t7, 0x6
    ctx->r14 = ctx->r15 & 0X6;
    // 0x800BB510: ori         $t9, $t6, 0x18
    ctx->r25 = ctx->r14 | 0X18;
    // 0x800BB514: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x800BB518: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800BB51C: or          $t6, $t7, $s4
    ctx->r14 = ctx->r15 | ctx->r20;
    // 0x800BB520: ori         $t9, $t6, 0x50
    ctx->r25 = ctx->r14 | 0X50;
    // 0x800BB524: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB528: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800BB52C: nop

    // 0x800BB530: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB534: mflo        $t7
    ctx->r15 = lo;
    // 0x800BB538: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x800BB53C: addu        $t9, $t6, $s2
    ctx->r25 = ADD32(ctx->r14, ctx->r18);
    // 0x800BB540: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BB544: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB548: lui         $t7, 0x511
    ctx->r15 = S32(0X511 << 16);
    // 0x800BB54C: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB550: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB554: ori         $t7, $t7, 0x20
    ctx->r15 = ctx->r15 | 0X20;
    // 0x800BB558: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB55C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800BB560: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BB564: sll         $t8, $t9, 5
    ctx->r24 = S32(ctx->r25 << 5);
    // 0x800BB568: addu        $t7, $t8, $s2
    ctx->r15 = ADD32(ctx->r24, ctx->r18);
    // 0x800BB56C: addiu       $t6, $t6, 0x3620
    ctx->r14 = ADD32(ctx->r14, 0X3620);
    // 0x800BB570: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800BB574: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
L_800BB578:
    // 0x800BB578: jal         0x80069C80
    // 0x800BB57C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mtx_pop(rdram, ctx);
        goto after_10;
    // 0x800BB57C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800BB580: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB584: lwc1        $f10, -0x59A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X59A0);
    // 0x800BB588: lw          $t8, 0x104($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X104);
    // 0x800BB58C: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800BB590: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800BB594: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800BB598: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800BB59C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800BB5A0: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB5A4: sra         $t7, $t8, 8
    ctx->r15 = S32(SIGNED(ctx->r24) >> 8);
    // 0x800BB5A8: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BB5AC: sw          $t7, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r15;
    // 0x800BB5B0: bne         $fp, $v1, L_800BB388
    if (ctx->r30 != ctx->r3) {
        // 0x800BB5B4: swc1        $f18, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
            goto L_800BB388;
    }
    // 0x800BB5B4: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x800BB5B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB5BC: lwc1        $f6, -0x599C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X599C);
    // 0x800BB5C0: lw          $v0, 0x11C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X11C);
    // 0x800BB5C4: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BB5C8: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800BB5CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BB5D0: sw          $v0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r2;
    // 0x800BB5D4: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800BB5D8: bne         $v0, $v1, L_800BB368
    if (ctx->r2 != ctx->r3) {
        // 0x800BB5DC: swc1        $f8, 0xF8($sp)
        MEM_W(0XF8, ctx->r29) = ctx->f8.u32l;
            goto L_800BB368;
    }
    // 0x800BB5DC: swc1        $f8, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f8.u32l;
    // 0x800BB5E0: b           L_800BB73C
    // 0x800BB5E4: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
        goto L_800BB73C;
    // 0x800BB5E4: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
L_800BB5E8:
    // 0x800BB5E8: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
    // 0x800BB5EC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800BB5F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BB5F4: jal         0x800696C4
    // 0x800BB5F8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_11;
    // 0x800BB5F8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_11:
    // 0x800BB5FC: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB600: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800BB604: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BB608: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BB60C: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800BB610: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800BB614: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x800BB618: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB61C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800BB620: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800BB624: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800BB628: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800BB62C: sll         $t6, $t3, 3
    ctx->r14 = S32(ctx->r11 << 3);
    // 0x800BB630: sll         $t8, $t4, 1
    ctx->r24 = S32(ctx->r12 << 1);
    // 0x800BB634: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x800BB638: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
    // 0x800BB63C: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x800BB640: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800BB644: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x800BB648: mflo        $t7
    ctx->r15 = lo;
    // 0x800BB64C: ori         $t8, $t9, 0x1
    ctx->r24 = ctx->r25 | 0X1;
    // 0x800BB650: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800BB654: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB658: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800BB65C: or          $t4, $t7, $zero
    ctx->r12 = ctx->r15 | 0;
    // 0x800BB660: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x800BB664: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800BB668: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800BB66C: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x800BB670: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800BB674: mflo        $t0
    ctx->r8 = lo;
    // 0x800BB678: blez        $a2, L_800BB728
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BB67C: nop
    
            goto L_800BB728;
    }
    // 0x800BB67C: nop

    // 0x800BB680: lw          $fp, 0x128($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X128);
    // 0x800BB684: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
L_800BB688:
    // 0x800BB688: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB68C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800BB690: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB694: addu        $a0, $t6, $fp
    ctx->r4 = ADD32(ctx->r14, ctx->r30);
    // 0x800BB698: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800BB69C: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x800BB6A0: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800BB6A4: addu        $t8, $s7, $t8
    ctx->r24 = ADD32(ctx->r23, ctx->r24);
    // 0x800BB6A8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800BB6AC: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB6B0: addu        $t1, $t7, $t6
    ctx->r9 = ADD32(ctx->r15, ctx->r14);
    // 0x800BB6B4: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x800BB6B8: multu       $s0, $t7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB6BC: addu        $a1, $t1, $s2
    ctx->r5 = ADD32(ctx->r9, ctx->r18);
    // 0x800BB6C0: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BB6C4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BB6C8: sw          $a1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r5;
    // 0x800BB6CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BB6D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB6D4: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800BB6D8: andi        $t6, $a1, 0x6
    ctx->r14 = ctx->r5 & 0X6;
    // 0x800BB6DC: addu        $t2, $t9, $t8
    ctx->r10 = ADD32(ctx->r25, ctx->r24);
    // 0x800BB6E0: or          $t9, $t3, $t6
    ctx->r25 = ctx->r11 | ctx->r14;
    // 0x800BB6E4: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x800BB6E8: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800BB6EC: or          $t6, $t7, $s4
    ctx->r14 = ctx->r15 | ctx->r20;
    // 0x800BB6F0: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x800BB6F4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB6F8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB6FC: addu        $t7, $t2, $s2
    ctx->r15 = ADD32(ctx->r10, ctx->r18);
    // 0x800BB700: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB704: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB708: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BB70C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800BB710: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BB714: nop

    // 0x800BB718: slt         $at, $s0, $a2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BB71C: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x800BB720: bne         $at, $zero, L_800BB688
    if (ctx->r1 != 0) {
        // 0x800BB724: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BB688;
    }
    // 0x800BB724: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BB728:
    // 0x800BB728: jal         0x80069C80
    // 0x800BB72C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mtx_pop(rdram, ctx);
        goto after_12;
    // 0x800BB72C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800BB730: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB734: addiu       $ra, $ra, -0x5A78
    ctx->r31 = ADD32(ctx->r31, -0X5A78);
    // 0x800BB738: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
L_800BB73C:
    // 0x800BB73C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x800BB740: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800BB744: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BB748: lw          $t6, 0x366C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X366C);
    // 0x800BB74C: addiu       $t7, $t8, 0x2
    ctx->r15 = ADD32(ctx->r24, 0X2);
    // 0x800BB750: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BB754: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x800BB758: bne         $at, $zero, L_800BB288
    if (ctx->r1 != 0) {
        // 0x800BB75C: sw          $t9, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->r25;
            goto L_800BB288;
    }
    // 0x800BB75C: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
L_800BB760:
    // 0x800BB760: lw          $t8, 0x4C($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X4C);
    // 0x800BB764: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x800BB768: beq         $t8, $zero, L_800BB7A4
    if (ctx->r24 == 0) {
        // 0x800BB76C: nop
    
            goto L_800BB7A4;
    }
    // 0x800BB76C: nop

    // 0x800BB770: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB774: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800BB778: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BB77C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BB780: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800BB784: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB788: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB78C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800BB790: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB794: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB798: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800BB79C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB7A0: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
L_800BB7A4:
    // 0x800BB7A4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BB7A8: lw          $t8, 0x120($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X120);
    // 0x800BB7AC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BB7B0: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800BB7B4: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800BB7B8: lw          $t7, -0x5A7C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5A7C);
    // 0x800BB7BC: nop

    // 0x800BB7C0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
L_800BB7C4:
    // 0x800BB7C4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800BB7C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BB7CC: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BB7D0: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BB7D4: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BB7D8: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BB7DC: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BB7E0: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BB7E4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800BB7E8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800BB7EC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800BB7F0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800BB7F4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800BB7F8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800BB7FC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800BB800: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800BB804: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800BB808: sw          $zero, 0x366C($at)
    MEM_W(0X366C, ctx->r1) = 0;
    // 0x800BB80C: jr          $ra
    // 0x800BB810: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x800BB810: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void race_finish_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE78: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AE7C: lh          $v0, -0x4D32($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4D32);
    // 0x8001AE80: jr          $ra
    // 0x8001AE84: nop

    return;
    // 0x8001AE84: nop

;}
RECOMP_FUNC void particle_deallocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B25A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B25A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B25A8: lh          $v0, 0x2C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2C);
    // 0x800B25AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B25B0: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800B25B4: bne         $at, $zero, L_800B25CC
    if (ctx->r1 != 0) {
        // 0x800B25B8: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_800B25CC;
    }
    // 0x800B25B8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B25BC: beq         $v0, $at, L_800B25F0
    if (ctx->r2 == ctx->r1) {
        // 0x800B25C0: nop
    
            goto L_800B25F0;
    }
    // 0x800B25C0: nop

    // 0x800B25C4: b           L_800B27B4
    // 0x800B25C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B27B4;
    // 0x800B25C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B25CC:
    // 0x800B25CC: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x800B25D0: beq         $at, $zero, L_800B27B0
    if (ctx->r1 == 0) {
        // 0x800B25D4: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800B27B0;
    }
    // 0x800B25D4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800B25D8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B25DC: addu        $at, $at, $t6
    gpr jr_addend_800B25E8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B25E0: lw          $t6, -0x6EA4($at)
    ctx->r14 = ADD32(ctx->r1, -0X6EA4);
    // 0x800B25E4: nop

    // 0x800B25E8: jr          $t6
    // 0x800B25EC: nop

    switch (jr_addend_800B25E8 >> 2) {
        case 0: goto L_800B27B0; break;
        case 1: goto L_800B2640; break;
        case 2: goto L_800B2698; break;
        case 3: goto L_800B26F0; break;
        case 4: goto L_800B2748; break;
        default: switch_error(__func__, 0x800B25E8, 0x800E915C);
    }
    // 0x800B25EC: nop

L_800B25F0:
    // 0x800B25F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B25F4: lw          $v0, 0x3248($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3248);
    // 0x800B25F8: nop

    // 0x800B25FC: blez        $v0, L_800B27B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B2600: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B27B4;
    }
    // 0x800B2600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2604: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
    // 0x800B2608: nop

    // 0x800B260C: beq         $a0, $zero, L_800B2630
    if (ctx->r4 == 0) {
        // 0x800B2610: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800B2630;
    }
    // 0x800B2610: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800B2614: jal         0x8007D100
    // 0x800B2618: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    sprite_free(rdram, ctx);
        goto after_0;
    // 0x800B2618: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800B261C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2620: lw          $v0, 0x3248($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3248);
    // 0x800B2624: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2628: nop

    // 0x800B262C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_800B2630:
    // 0x800B2630: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2634: sw          $t7, 0x3248($at)
    MEM_W(0X3248, ctx->r1) = ctx->r15;
    // 0x800B2638: b           L_800B27B0
    // 0x800B263C: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B27B0;
    // 0x800B263C: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B2640:
    // 0x800B2640: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2644: lw          $v0, 0x3230($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3230);
    // 0x800B2648: nop

    // 0x800B264C: blez        $v0, L_800B27B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B2650: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B27B4;
    }
    // 0x800B2650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2654: lw          $t8, 0x44($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X44);
    // 0x800B2658: nop

    // 0x800B265C: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800B2660: nop

    // 0x800B2664: beq         $a0, $zero, L_800B2688
    if (ctx->r4 == 0) {
        // 0x800B2668: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800B2688;
    }
    // 0x800B2668: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800B266C: jal         0x8007B70C
    // 0x800B2670: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_1;
    // 0x800B2670: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x800B2674: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2678: lw          $v0, 0x3230($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3230);
    // 0x800B267C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2680: nop

    // 0x800B2684: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
L_800B2688:
    // 0x800B2688: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B268C: sw          $t9, 0x3230($at)
    MEM_W(0X3230, ctx->r1) = ctx->r25;
    // 0x800B2690: b           L_800B27B0
    // 0x800B2694: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B27B0;
    // 0x800B2694: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B2698:
    // 0x800B2698: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B269C: lw          $v0, 0x323C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X323C);
    // 0x800B26A0: nop

    // 0x800B26A4: blez        $v0, L_800B27B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B26A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B27B4;
    }
    // 0x800B26A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B26AC: lw          $t0, 0x44($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X44);
    // 0x800B26B0: nop

    // 0x800B26B4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B26B8: nop

    // 0x800B26BC: beq         $a0, $zero, L_800B26E0
    if (ctx->r4 == 0) {
        // 0x800B26C0: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_800B26E0;
    }
    // 0x800B26C0: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x800B26C4: jal         0x8007B70C
    // 0x800B26C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_2;
    // 0x800B26C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x800B26CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B26D0: lw          $v0, 0x323C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X323C);
    // 0x800B26D4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B26D8: nop

    // 0x800B26DC: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_800B26E0:
    // 0x800B26E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B26E4: sw          $t1, 0x323C($at)
    MEM_W(0X323C, ctx->r1) = ctx->r9;
    // 0x800B26E8: b           L_800B27B0
    // 0x800B26EC: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B27B0;
    // 0x800B26EC: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B26F0:
    // 0x800B26F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B26F4: lw          $v0, 0x3254($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3254);
    // 0x800B26F8: nop

    // 0x800B26FC: blez        $v0, L_800B27B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B2700: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B27B4;
    }
    // 0x800B2700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2704: lw          $t2, 0x44($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X44);
    // 0x800B2708: nop

    // 0x800B270C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x800B2710: nop

    // 0x800B2714: beq         $a0, $zero, L_800B2738
    if (ctx->r4 == 0) {
        // 0x800B2718: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800B2738;
    }
    // 0x800B2718: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800B271C: jal         0x8007B70C
    // 0x800B2720: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_3;
    // 0x800B2720: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_3:
    // 0x800B2724: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2728: lw          $v0, 0x3254($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3254);
    // 0x800B272C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2730: nop

    // 0x800B2734: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
L_800B2738:
    // 0x800B2738: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B273C: sw          $t3, 0x3254($at)
    MEM_W(0X3254, ctx->r1) = ctx->r11;
    // 0x800B2740: b           L_800B27B0
    // 0x800B2744: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B27B0;
    // 0x800B2744: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B2748:
    // 0x800B2748: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800B274C: lw          $t4, 0x3260($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3260);
    // 0x800B2750: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B2754: blez        $t4, L_800B27B4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B2758: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B27B4;
    }
    // 0x800B2758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B275C: jal         0x800B2B9C
    // 0x800B2760: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    delete_point_particle_from_sequence(rdram, ctx);
        goto after_4;
    // 0x800B2760: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_4:
    // 0x800B2764: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2768: nop

    // 0x800B276C: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x800B2770: nop

    // 0x800B2774: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800B2778: nop

    // 0x800B277C: beq         $a0, $zero, L_800B2794
    if (ctx->r4 == 0) {
        // 0x800B2780: nop
    
            goto L_800B2794;
    }
    // 0x800B2780: nop

    // 0x800B2784: jal         0x8007B70C
    // 0x800B2788: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_5;
    // 0x800B2788: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_5:
    // 0x800B278C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2790: nop

L_800B2794:
    // 0x800B2794: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2798: addiu       $v0, $v0, 0x3260
    ctx->r2 = ADD32(ctx->r2, 0X3260);
    // 0x800B279C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B27A0: nop

    // 0x800B27A4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B27A8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B27AC: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B27B0:
    // 0x800B27B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B27B4:
    // 0x800B27B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B27B8: jr          $ra
    // 0x800B27BC: nop

    return;
    // 0x800B27BC: nop

;}
RECOMP_FUNC void object_model_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FB3C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005FB40: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8005FB44: lw          $t6, -0x2450($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2450);
    // 0x8005FB48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005FB4C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8005FB50: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8005FB54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005FB58: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005FB5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005FB60: bne         $at, $zero, L_8005FB6C
    if (ctx->r1 != 0) {
        // 0x8005FB64: sw          $a1, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r5;
            goto L_8005FB6C;
    }
    // 0x8005FB64: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8005FB68: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8005FB6C:
    // 0x8005FB6C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8005FB70: addiu       $t1, $t1, -0x2454
    ctx->r9 = ADD32(ctx->r9, -0X2454);
    // 0x8005FB74: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8005FB78: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005FB7C: blez        $a0, L_8005FBDC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8005FB80: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8005FBDC;
    }
    // 0x8005FB80: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005FB84: lw          $v1, -0x245C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X245C);
    // 0x8005FB88: nop

    // 0x8005FB8C: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
L_8005FB90:
    // 0x8005FB90: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x8005FB94: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8005FB98: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005FB9C: bne         $s2, $t9, L_8005FBD4
    if (ctx->r18 != ctx->r25) {
        // 0x8005FBA0: slt         $at, $t0, $a0
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8005FBD4;
    }
    // 0x8005FBA0: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005FBA4: lw          $s1, 0x4($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X4);
    // 0x8005FBA8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005FBAC: jal         0x8005FF10
    // 0x8005FBB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    model_instance_init(rdram, ctx);
        goto after_0;
    // 0x8005FBB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8005FBB4: beq         $v0, $zero, L_8005FBCC
    if (ctx->r2 == 0) {
        // 0x8005FBB8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005FBCC;
    }
    // 0x8005FBB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005FBBC: lh          $t2, 0x30($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X30);
    // 0x8005FBC0: nop

    // 0x8005FBC4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8005FBC8: sh          $t3, 0x30($s1)
    MEM_H(0X30, ctx->r17) = ctx->r11;
L_8005FBCC:
    // 0x8005FBCC: b           L_8005FEF8
    // 0x8005FBD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8005FEF8;
    // 0x8005FBD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8005FBD4:
    // 0x8005FBD4: bne         $at, $zero, L_8005FB90
    if (ctx->r1 != 0) {
        // 0x8005FBD8: sll         $t8, $t0, 3
        ctx->r24 = S32(ctx->r8 << 3);
            goto L_8005FB90;
    }
    // 0x8005FBD8: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
L_8005FBDC:
    // 0x8005FBDC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005FBE0: addiu       $v1, $v1, -0x244C
    ctx->r3 = ADD32(ctx->r3, -0X244C);
    // 0x8005FBE4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FBE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005FBEC: blez        $v0, L_8005FC1C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005FBF0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8005FC1C;
    }
    // 0x8005FBF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005FBF4: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8005FBF8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8005FBFC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8005FC00: lw          $t5, -0x2458($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2458);
    // 0x8005FC04: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8005FC08: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8005FC0C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8005FC10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005FC14: b           L_8005FC2C
    // 0x8005FC18: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
        goto L_8005FC2C;
    // 0x8005FC18: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
L_8005FC1C:
    // 0x8005FC1C: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x8005FC20: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8005FC24: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005FC28: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
L_8005FC2C:
    // 0x8005FC2C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005FC30: lw          $t3, -0x2460($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2460);
    // 0x8005FC34: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x8005FC38: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8005FC3C: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8005FC40: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8005FC44: sb          $a3, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = ctx->r7;
    // 0x8005FC48: subu        $t5, $t6, $s0
    ctx->r13 = SUB32(ctx->r14, ctx->r16);
    // 0x8005FC4C: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x8005FC50: sb          $a2, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r6;
    // 0x8005FC54: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8005FC58: jal         0x800C673C
    // 0x8005FC5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gzip_size_uncompressed(rdram, ctx);
        goto after_1;
    // 0x8005FC5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8005FC60: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    // 0x8005FC64: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8005FC68: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x8005FC6C: jal         0x80070F50
    // 0x8005FC70: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc(rdram, ctx);
        goto after_2;
    // 0x8005FC70: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_2:
    // 0x8005FC74: bne         $v0, $zero, L_8005FCC4
    if (ctx->r2 != 0) {
        // 0x8005FC78: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8005FCC4;
    }
    // 0x8005FC78: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8005FC7C: lb          $t7, 0x3E($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X3E);
    // 0x8005FC80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005FC84: beq         $t7, $zero, L_8005FC9C
    if (ctx->r15 == 0) {
        // 0x8005FC88: addiu       $v0, $v0, -0x244C
        ctx->r2 = ADD32(ctx->r2, -0X244C);
            goto L_8005FC9C;
    }
    // 0x8005FC88: addiu       $v0, $v0, -0x244C
    ctx->r2 = ADD32(ctx->r2, -0X244C);
    // 0x8005FC8C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8005FC90: nop

    // 0x8005FC94: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8005FC98: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8005FC9C:
    // 0x8005FC9C: lb          $t2, 0x3D($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3D);
    // 0x8005FCA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005FCA4: beq         $t2, $zero, L_8005FCBC
    if (ctx->r10 == 0) {
        // 0x8005FCA8: addiu       $v0, $v0, -0x2454
        ctx->r2 = ADD32(ctx->r2, -0X2454);
            goto L_8005FCBC;
    }
    // 0x8005FCA8: addiu       $v0, $v0, -0x2454
    ctx->r2 = ADD32(ctx->r2, -0X2454);
    // 0x8005FCAC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8005FCB0: nop

    // 0x8005FCB4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8005FCB8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8005FCBC:
    // 0x8005FCBC: b           L_8005FEF8
    // 0x8005FCC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005FEF8;
    // 0x8005FCC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FCC4:
    // 0x8005FCC4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005FCC8: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8005FCCC: addu        $t5, $s1, $t6
    ctx->r13 = ADD32(ctx->r17, ctx->r14);
    // 0x8005FCD0: subu        $a1, $t5, $a3
    ctx->r5 = SUB32(ctx->r13, ctx->r7);
    // 0x8005FCD4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8005FCD8: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8005FCDC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8005FCE0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005FCE4: jal         0x80077190
    // 0x8005FCE8: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    asset_load(rdram, ctx);
        goto after_3;
    // 0x8005FCE8: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    after_3:
    // 0x8005FCEC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005FCF0: jal         0x800C6778
    // 0x8005FCF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gzip_inflate(rdram, ctx);
        goto after_4;
    // 0x8005FCF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8005FCF8: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8005FCFC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8005FD00: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8005FD04: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x8005FD08: lw          $t6, 0x38($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X38);
    // 0x8005FD0C: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8005FD10: addu        $t2, $t9, $s1
    ctx->r10 = ADD32(ctx->r25, ctx->r17);
    // 0x8005FD14: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8005FD18: lw          $t7, 0x14($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X14);
    // 0x8005FD1C: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
    // 0x8005FD20: lw          $t3, 0x4C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4C);
    // 0x8005FD24: lh          $a0, 0x22($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X22);
    // 0x8005FD28: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8005FD2C: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    // 0x8005FD30: sw          $t4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r12;
    // 0x8005FD34: addu        $t5, $t6, $s1
    ctx->r13 = ADD32(ctx->r14, ctx->r17);
    // 0x8005FD38: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005FD3C: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8005FD40: addu        $t2, $t9, $s1
    ctx->r10 = ADD32(ctx->r25, ctx->r17);
    // 0x8005FD44: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8005FD48: sw          $t5, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r13;
    // 0x8005FD4C: sw          $t8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r24;
    // 0x8005FD50: sw          $t2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r10;
    // 0x8005FD54: sw          $t4, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r12;
    // 0x8005FD58: sh          $t6, 0x30($s1)
    MEM_H(0X30, ctx->r17) = ctx->r14;
    // 0x8005FD5C: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    // 0x8005FD60: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x8005FD64: sh          $zero, 0x32($s1)
    MEM_H(0X32, ctx->r17) = 0;
    // 0x8005FD68: sh          $zero, 0x52($s1)
    MEM_H(0X52, ctx->r17) = 0;
    // 0x8005FD6C: sw          $zero, 0x40($s1)
    MEM_W(0X40, ctx->r17) = 0;
    // 0x8005FD70: sh          $zero, 0x48($s1)
    MEM_H(0X48, ctx->r17) = 0;
    // 0x8005FD74: sw          $zero, 0x44($s1)
    MEM_W(0X44, ctx->r17) = 0;
    // 0x8005FD78: blez        $a0, L_8005FDF0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8005FD7C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8005FDF0;
    }
    // 0x8005FD7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005FD80: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8005FD84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005FD88:
    // 0x8005FD88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005FD8C: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x8005FD90: ori         $t5, $a0, 0x8000
    ctx->r13 = ctx->r4 | 0X8000;
    // 0x8005FD94: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8005FD98: sb          $a1, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r5;
    // 0x8005FD9C: jal         0x8007B2C4
    // 0x8005FDA0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    load_texture(rdram, ctx);
        goto after_5;
    // 0x8005FDA0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x8005FDA4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8005FDA8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8005FDAC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8005FDB0: lb          $a1, 0x3F($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X3F);
    // 0x8005FDB4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8005FDB8: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8005FDBC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8005FDC0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005FDC4: addu        $s0, $t9, $v1
    ctx->r16 = ADD32(ctx->r25, ctx->r3);
    // 0x8005FDC8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8005FDCC: nop

    // 0x8005FDD0: bne         $t2, $zero, L_8005FDDC
    if (ctx->r10 != 0) {
        // 0x8005FDD4: nop
    
            goto L_8005FDDC;
    }
    // 0x8005FDD4: nop

    // 0x8005FDD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8005FDDC:
    // 0x8005FDDC: lh          $a0, 0x22($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X22);
    // 0x8005FDE0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8005FDE4: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005FDE8: bne         $at, $zero, L_8005FD88
    if (ctx->r1 != 0) {
        // 0x8005FDEC: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8005FD88;
    }
    // 0x8005FDEC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8005FDF0:
    // 0x8005FDF0: bne         $a1, $zero, L_8005FEB0
    if (ctx->r5 != 0) {
        // 0x8005FDF4: lb          $t2, 0x3D($sp)
        ctx->r10 = MEM_B(ctx->r29, 0X3D);
            goto L_8005FEB0;
    }
    // 0x8005FDF4: lb          $t2, 0x3D($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3D);
    // 0x8005FDF8: lh          $a1, 0x28($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X28);
    // 0x8005FDFC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8005FE00: blez        $a1, L_8005FE30
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005FE04: nop
    
            goto L_8005FE30;
    }
    // 0x8005FE04: nop

    // 0x8005FE08: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8005FE0C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_8005FE10:
    // 0x8005FE10: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8005FE14: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005FE18: beq         $a2, $v1, L_8005FE24
    if (ctx->r6 == ctx->r3) {
        // 0x8005FE1C: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8005FE24;
    }
    // 0x8005FE1C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005FE20: beq         $at, $zero, L_8005FEAC
    if (ctx->r1 == 0) {
        // 0x8005FE24: slt         $at, $t0, $a1
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8005FEAC;
    }
L_8005FE24:
    // 0x8005FE24: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005FE28: bne         $at, $zero, L_8005FE10
    if (ctx->r1 != 0) {
        // 0x8005FE2C: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_8005FE10;
    }
    // 0x8005FE2C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8005FE30:
    // 0x8005FE30: jal         0x800610E8
    // 0x8005FE34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    model_init_normals(rdram, ctx);
        goto after_6;
    // 0x8005FE34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8005FE38: bne         $v0, $zero, L_8005FEAC
    if (ctx->r2 != 0) {
        // 0x8005FE3C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005FEAC;
    }
    // 0x8005FE3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005FE40: jal         0x80061C40
    // 0x8005FE44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    model_anim_init(rdram, ctx);
        goto after_7;
    // 0x8005FE44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x8005FE48: bne         $v0, $zero, L_8005FEB0
    if (ctx->r2 != 0) {
        // 0x8005FE4C: lb          $t2, 0x3D($sp)
        ctx->r10 = MEM_B(ctx->r29, 0X3D);
            goto L_8005FEB0;
    }
    // 0x8005FE4C: lb          $t2, 0x3D($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3D);
    // 0x8005FE50: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005FE54: jal         0x8005FF10
    // 0x8005FE58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    model_instance_init(rdram, ctx);
        goto after_8;
    // 0x8005FE58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8005FE5C: beq         $v0, $zero, L_8005FEAC
    if (ctx->r2 == 0) {
        // 0x8005FE60: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005FEAC;
    }
    // 0x8005FE60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005FE64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005FE68: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8005FE6C: addiu       $a0, $a0, -0x245C
    ctx->r4 = ADD32(ctx->r4, -0X245C);
    // 0x8005FE70: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005FE74: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8005FE78: addu        $t5, $t6, $t4
    ctx->r13 = ADD32(ctx->r14, ctx->r12);
    // 0x8005FE7C: sw          $s2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r18;
    // 0x8005FE80: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005FE84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8005FE88: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x8005FE8C: sw          $s1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r17;
    // 0x8005FE90: lw          $t9, -0x2454($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2454);
    // 0x8005FE94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005FE98: slti        $at, $t9, 0x46
    ctx->r1 = SIGNED(ctx->r25) < 0X46 ? 1 : 0;
    // 0x8005FE9C: beq         $at, $zero, L_8005FEB0
    if (ctx->r1 == 0) {
        // 0x8005FEA0: lb          $t2, 0x3D($sp)
        ctx->r10 = MEM_B(ctx->r29, 0X3D);
            goto L_8005FEB0;
    }
    // 0x8005FEA0: lb          $t2, 0x3D($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3D);
    // 0x8005FEA4: b           L_8005FEF8
    // 0x8005FEA8: sb          $zero, 0x20($v1)
    MEM_B(0X20, ctx->r3) = 0;
        goto L_8005FEF8;
    // 0x8005FEA8: sb          $zero, 0x20($v1)
    MEM_B(0X20, ctx->r3) = 0;
L_8005FEAC:
    // 0x8005FEAC: lb          $t2, 0x3D($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3D);
L_8005FEB0:
    // 0x8005FEB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005FEB4: beq         $t2, $zero, L_8005FECC
    if (ctx->r10 == 0) {
        // 0x8005FEB8: addiu       $v0, $v0, -0x2454
        ctx->r2 = ADD32(ctx->r2, -0X2454);
            goto L_8005FECC;
    }
    // 0x8005FEB8: addiu       $v0, $v0, -0x2454
    ctx->r2 = ADD32(ctx->r2, -0X2454);
    // 0x8005FEBC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8005FEC0: nop

    // 0x8005FEC4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8005FEC8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8005FECC:
    // 0x8005FECC: lb          $t6, 0x3E($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X3E);
    // 0x8005FED0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8005FED4: beq         $t6, $zero, L_8005FEEC
    if (ctx->r14 == 0) {
        // 0x8005FED8: addiu       $v0, $v0, -0x244C
        ctx->r2 = ADD32(ctx->r2, -0X244C);
            goto L_8005FEEC;
    }
    // 0x8005FED8: addiu       $v0, $v0, -0x244C
    ctx->r2 = ADD32(ctx->r2, -0X244C);
    // 0x8005FEDC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8005FEE0: nop

    // 0x8005FEE4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8005FEE8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8005FEEC:
    // 0x8005FEEC: jal         0x80060298
    // 0x8005FEF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_model_data(rdram, ctx);
        goto after_9;
    // 0x8005FEF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8005FEF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FEF8:
    // 0x8005FEF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005FEFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005FF00: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FF04: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005FF08: jr          $ra
    // 0x8005FF0C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005FF0C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void turn_head_towards_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800523C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800523CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800523D0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800523D4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800523D8: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800523DC: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800523E0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800523E4: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800523E8: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800523EC: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800523F0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800523F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800523F8: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800523FC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80052400: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80052404: nop

    // 0x80052408: bc1f        L_80052540
    if (!c1cs) {
        // 0x8005240C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80052540;
    }
    // 0x8005240C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052410: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80052414: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80052418: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005241C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80052420: jal         0x80070990
    // 0x80052424: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    arctan2_f(rdram, ctx);
        goto after_0;
    // 0x80052424: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80052428: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8005242C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80052430: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80052434: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80052438: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8005243C: subu        $v1, $v0, $t7
    ctx->r3 = SUB32(ctx->r2, ctx->r15);
    // 0x80052440: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80052444: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80052448: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8005244C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80052450: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80052454: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80052458: bne         $at, $zero, L_80052468
    if (ctx->r1 != 0) {
        // 0x8005245C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80052468;
    }
    // 0x8005245C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80052460: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80052464: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80052468:
    // 0x80052468: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005246C: beq         $at, $zero, L_80052478
    if (ctx->r1 == 0) {
        // 0x80052470: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80052478;
    }
    // 0x80052470: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80052474: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80052478:
    // 0x80052478: slti        $at, $v1, 0x3001
    ctx->r1 = SIGNED(ctx->r3) < 0X3001 ? 1 : 0;
    // 0x8005247C: bne         $at, $zero, L_8005248C
    if (ctx->r1 != 0) {
        // 0x80052480: slti        $at, $v1, -0x3000
        ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
            goto L_8005248C;
    }
    // 0x80052480: slti        $at, $v1, -0x3000
    ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
    // 0x80052484: addiu       $v1, $zero, 0x3000
    ctx->r3 = ADD32(0, 0X3000);
    // 0x80052488: slti        $at, $v1, -0x3000
    ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
L_8005248C:
    // 0x8005248C: beq         $at, $zero, L_80052498
    if (ctx->r1 == 0) {
        // 0x80052490: nop
    
            goto L_80052498;
    }
    // 0x80052490: nop

    // 0x80052494: addiu       $v1, $zero, -0x3000
    ctx->r3 = ADD32(0, -0X3000);
L_80052498:
    // 0x80052498: lb          $t8, 0x1E7($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1E7);
    // 0x8005249C: sh          $v1, 0x16C($a1)
    MEM_H(0X16C, ctx->r5) = ctx->r3;
    // 0x800524A0: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x800524A4: slti        $at, $t9, 0x1F
    ctx->r1 = SIGNED(ctx->r25) < 0X1F ? 1 : 0;
    // 0x800524A8: beq         $at, $zero, L_800524B4
    if (ctx->r1 == 0) {
        // 0x800524AC: nop
    
            goto L_800524B4;
    }
    // 0x800524AC: nop

    // 0x800524B0: sh          $zero, 0x16C($a1)
    MEM_H(0X16C, ctx->r5) = 0;
L_800524B4:
    // 0x800524B4: lw          $a1, 0x64($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X64);
    // 0x800524B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800524BC: jal         0x80070990
    // 0x800524C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_1;
    // 0x800524C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800524C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800524C8: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800524CC: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x800524D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800524D4: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x800524D8: subu        $v1, $v0, $t1
    ctx->r3 = SUB32(ctx->r2, ctx->r9);
    // 0x800524DC: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800524E0: bne         $at, $zero, L_800524F0
    if (ctx->r1 != 0) {
        // 0x800524E4: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800524F0;
    }
    // 0x800524E4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800524E8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800524EC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800524F0:
    // 0x800524F0: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800524F4: beq         $at, $zero, L_80052500
    if (ctx->r1 == 0) {
        // 0x800524F8: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80052500;
    }
    // 0x800524F8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800524FC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80052500:
    // 0x80052500: slti        $at, $v1, 0x3001
    ctx->r1 = SIGNED(ctx->r3) < 0X3001 ? 1 : 0;
    // 0x80052504: bne         $at, $zero, L_80052514
    if (ctx->r1 != 0) {
        // 0x80052508: slti        $at, $v1, -0x3000
        ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
            goto L_80052514;
    }
    // 0x80052508: slti        $at, $v1, -0x3000
    ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
    // 0x8005250C: addiu       $v1, $zero, 0x3000
    ctx->r3 = ADD32(0, 0X3000);
    // 0x80052510: slti        $at, $v1, -0x3000
    ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
L_80052514:
    // 0x80052514: beq         $at, $zero, L_80052520
    if (ctx->r1 == 0) {
        // 0x80052518: nop
    
            goto L_80052520;
    }
    // 0x80052518: nop

    // 0x8005251C: addiu       $v1, $zero, -0x3000
    ctx->r3 = ADD32(0, -0X3000);
L_80052520:
    // 0x80052520: lb          $t2, 0x1E7($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1E7);
    // 0x80052524: sh          $v1, 0x16C($a1)
    MEM_H(0X16C, ctx->r5) = ctx->r3;
    // 0x80052528: andi        $t3, $t2, 0x1F
    ctx->r11 = ctx->r10 & 0X1F;
    // 0x8005252C: slti        $at, $t3, 0xA
    ctx->r1 = SIGNED(ctx->r11) < 0XA ? 1 : 0;
    // 0x80052530: beq         $at, $zero, L_8005253C
    if (ctx->r1 == 0) {
        // 0x80052534: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8005253C;
    }
    // 0x80052534: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80052538: sh          $zero, 0x16C($a1)
    MEM_H(0X16C, ctx->r5) = 0;
L_8005253C:
    // 0x8005253C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80052540:
    // 0x80052540: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80052544: jr          $ra
    // 0x80052548: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80052548: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void regenerate_point_particles_mesh(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B43C4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800B43C8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B43CC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800B43D0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800B43D4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800B43D8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800B43DC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B43E0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B43E4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B43E8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B43EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B43F0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B43F4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B43F8: lw          $s6, 0x70($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X70);
    // 0x800B43FC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B4400: beq         $s6, $zero, L_800B49B0
    if (ctx->r22 == 0) {
        // 0x800B4404: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800B49B0;
    }
    // 0x800B4404: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B4408: lw          $t6, 0xC($s6)
    ctx->r14 = MEM_W(ctx->r22, 0XC);
    // 0x800B440C: nop

    // 0x800B4410: beq         $t6, $zero, L_800B49B4
    if (ctx->r14 == 0) {
        // 0x800B4414: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800B49B4;
    }
    // 0x800B4414: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B4418: lbu         $v0, 0x6($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X6);
    // 0x800B441C: addiu       $fp, $sp, 0x7C
    ctx->r30 = ADD32(ctx->r29, 0X7C);
    // 0x800B4420: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B4424: bltz        $v0, L_800B49B0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B4428: sll         $s2, $v0, 2
        ctx->r18 = S32(ctx->r2 << 2);
            goto L_800B49B0;
    }
    // 0x800B4428: sll         $s2, $v0, 2
    ctx->r18 = S32(ctx->r2 << 2);
    // 0x800B442C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B4430: addiu       $s7, $sp, 0x70
    ctx->r23 = ADD32(ctx->r29, 0X70);
    // 0x800B4434: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_800B4438:
    // 0x800B4438: lw          $t7, 0xC($s6)
    ctx->r15 = MEM_W(ctx->r22, 0XC);
    // 0x800B443C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800B4440: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800B4444: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x800B4448: nop

    // 0x800B444C: lh          $t9, 0x3A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X3A);
    // 0x800B4450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4454: beq         $t9, $zero, L_800B49B4
    if (ctx->r25 == 0) {
        // 0x800B4458: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800B49B4;
    }
    // 0x800B4458: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B445C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B4460: lw          $s1, 0x44($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X44);
    // 0x800B4464: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x800B4468: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x800B446C: jal         0x80070560
    // 0x800B4470: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800B4470: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800B4474: swc1        $f20, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f20.u32l;
    // 0x800B4478: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B447C: swc1        $f20, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f20.u32l;
    // 0x800B4480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4484: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800B4488: jal         0x80070560
    // 0x800B448C: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x800B448C: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800B4490: lbu         $t1, 0x75($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X75);
    // 0x800B4494: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B4498: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800B449C: multu       $t2, $s4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B44A0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B44A4: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x800B44A8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B44AC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B44B0: nop

    // 0x800B44B4: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B44B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B44BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B44C0: nop

    // 0x800B44C4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B44C8: mflo        $t3
    ctx->r11 = lo;
    // 0x800B44CC: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800B44D0: addu        $v1, $t0, $t3
    ctx->r3 = ADD32(ctx->r8, ctx->r11);
    // 0x800B44D4: sh          $t5, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r13;
    // 0x800B44D8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B44DC: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B44E0: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B44E4: addiu       $v1, $v1, 0x46
    ctx->r3 = ADD32(ctx->r3, 0X46);
    // 0x800B44E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B44EC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B44F0: nop

    // 0x800B44F4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B44F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B44FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4500: nop

    // 0x800B4504: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B4508: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800B450C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B4510: sh          $t7, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = ctx->r15;
    // 0x800B4514: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B4518: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B451C: nop

    // 0x800B4520: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B4524: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B4528: nop

    // 0x800B452C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B4530: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4534: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4538: nop

    // 0x800B453C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B4540: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800B4544: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B4548: sh          $t9, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r25;
    // 0x800B454C: lbu         $t1, 0x6C($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B4550: nop

    // 0x800B4554: sb          $t1, -0x18($v1)
    MEM_B(-0X18, ctx->r3) = ctx->r9;
    // 0x800B4558: lbu         $t2, 0x6D($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B455C: nop

    // 0x800B4560: sb          $t2, -0x17($v1)
    MEM_B(-0X17, ctx->r3) = ctx->r10;
    // 0x800B4564: lbu         $t0, 0x6E($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B4568: nop

    // 0x800B456C: sb          $t0, -0x16($v1)
    MEM_B(-0X16, ctx->r3) = ctx->r8;
    // 0x800B4570: lh          $t3, 0x5C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X5C);
    // 0x800B4574: nop

    // 0x800B4578: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800B457C: sb          $t4, -0x15($v1)
    MEM_B(-0X15, ctx->r3) = ctx->r12;
    // 0x800B4580: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B4584: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B4588: nop

    // 0x800B458C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B4590: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B4594: nop

    // 0x800B4598: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B459C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B45A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B45A4: nop

    // 0x800B45A8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B45AC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800B45B0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B45B4: sh          $t6, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r14;
    // 0x800B45B8: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B45BC: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B45C0: nop

    // 0x800B45C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B45C8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B45CC: nop

    // 0x800B45D0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B45D4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B45D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B45DC: nop

    // 0x800B45E0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B45E4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800B45E8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B45EC: sh          $t8, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r24;
    // 0x800B45F0: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B45F4: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B45F8: nop

    // 0x800B45FC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B4600: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B4604: nop

    // 0x800B4608: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B460C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4610: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4614: nop

    // 0x800B4618: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B461C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800B4620: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B4624: sh          $t1, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r9;
    // 0x800B4628: lbu         $t2, 0x6C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B462C: nop

    // 0x800B4630: sb          $t2, -0xE($v1)
    MEM_B(-0XE, ctx->r3) = ctx->r10;
    // 0x800B4634: lbu         $t0, 0x6D($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B4638: nop

    // 0x800B463C: sb          $t0, -0xD($v1)
    MEM_B(-0XD, ctx->r3) = ctx->r8;
    // 0x800B4640: lbu         $t3, 0x6E($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B4644: nop

    // 0x800B4648: sb          $t3, -0xC($v1)
    MEM_B(-0XC, ctx->r3) = ctx->r11;
    // 0x800B464C: lh          $t4, 0x5C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X5C);
    // 0x800B4650: nop

    // 0x800B4654: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800B4658: sb          $t5, -0xB($v1)
    MEM_B(-0XB, ctx->r3) = ctx->r13;
    // 0x800B465C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B4660: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B4664: nop

    // 0x800B4668: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B466C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B4670: nop

    // 0x800B4674: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B4678: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B467C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4680: nop

    // 0x800B4684: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B4688: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B468C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B4690: sh          $t7, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r15;
    // 0x800B4694: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B4698: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B469C: nop

    // 0x800B46A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B46A4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B46A8: nop

    // 0x800B46AC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B46B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B46B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B46B8: nop

    // 0x800B46BC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B46C0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800B46C4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B46C8: sh          $t9, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r25;
    // 0x800B46CC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B46D0: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B46D4: nop

    // 0x800B46D8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B46DC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B46E0: nop

    // 0x800B46E4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B46E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B46EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B46F0: nop

    // 0x800B46F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B46F8: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800B46FC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B4700: sh          $t2, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r10;
    // 0x800B4704: lbu         $t0, 0x6C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B4708: nop

    // 0x800B470C: sb          $t0, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r8;
    // 0x800B4710: lbu         $t3, 0x6D($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B4714: nop

    // 0x800B4718: sb          $t3, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r11;
    // 0x800B471C: lbu         $t4, 0x6E($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B4720: nop

    // 0x800B4724: sb          $t4, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r12;
    // 0x800B4728: lh          $t5, 0x5C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X5C);
    // 0x800B472C: nop

    // 0x800B4730: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800B4734: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800B4738: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B473C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B4740: nop

    // 0x800B4744: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B4748: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B474C: nop

    // 0x800B4750: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B4754: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4758: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B475C: nop

    // 0x800B4760: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B4764: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800B4768: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B476C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x800B4770: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B4774: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B4778: nop

    // 0x800B477C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B4780: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B4784: nop

    // 0x800B4788: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B478C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4790: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4794: nop

    // 0x800B4798: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B479C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800B47A0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B47A4: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x800B47A8: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B47AC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B47B0: nop

    // 0x800B47B4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B47B8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800B47BC: nop

    // 0x800B47C0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800B47C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B47C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B47CC: nop

    // 0x800B47D0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B47D4: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800B47D8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800B47DC: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    // 0x800B47E0: lbu         $t3, 0x6C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B47E4: nop

    // 0x800B47E8: sb          $t3, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r11;
    // 0x800B47EC: lbu         $t4, 0x6D($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B47F0: nop

    // 0x800B47F4: sb          $t4, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r12;
    // 0x800B47F8: lbu         $t5, 0x6E($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B47FC: nop

    // 0x800B4800: sb          $t5, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r13;
    // 0x800B4804: lh          $t6, 0x5C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X5C);
    // 0x800B4808: nop

    // 0x800B480C: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800B4810: sb          $t7, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r15;
    // 0x800B4814: lbu         $t9, 0x75($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X75);
    // 0x800B4818: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800B481C: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800B4820: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4824: mflo        $t2
    ctx->r10 = lo;
    // 0x800B4828: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
    // 0x800B482C: beq         $s3, $zero, L_800B4854
    if (ctx->r19 == 0) {
        // 0x800B4830: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800B4854;
    }
    // 0x800B4830: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800B4834: lbu         $t3, 0x75($s5)
    ctx->r11 = MEM_BU(ctx->r21, 0X75);
    // 0x800B4838: lw          $t0, 0x8($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X8);
    // 0x800B483C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800B4840: multu       $t4, $s4
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B4844: mflo        $t5
    ctx->r13 = lo;
    // 0x800B4848: addu        $v0, $t0, $t5
    ctx->r2 = ADD32(ctx->r8, ctx->r13);
    // 0x800B484C: b           L_800B4858
    // 0x800B4850: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
        goto L_800B4858;
    // 0x800B4850: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
L_800B4854:
    // 0x800B4854: addiu       $v0, $a0, 0x28
    ctx->r2 = ADD32(ctx->r4, 0X28);
L_800B4858:
    // 0x800B4858: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800B485C: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x800B4860: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800B4864: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800B4868: addiu       $v1, $v1, 0x1E
    ctx->r3 = ADD32(ctx->r3, 0X1E);
    // 0x800B486C: sh          $t7, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = ctx->r15;
    // 0x800B4870: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800B4874: addiu       $v0, $v0, 0x1E
    ctx->r2 = ADD32(ctx->r2, 0X1E);
    // 0x800B4878: sh          $t9, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r25;
    // 0x800B487C: lbu         $t1, -0x18($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0X18);
    // 0x800B4880: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x800B4884: sb          $t1, -0x18($v1)
    MEM_B(-0X18, ctx->r3) = ctx->r9;
    // 0x800B4888: lbu         $t8, -0x17($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X17);
    // 0x800B488C: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x800B4890: sb          $t8, -0x17($v1)
    MEM_B(-0X17, ctx->r3) = ctx->r24;
    // 0x800B4894: lbu         $t2, -0x16($v0)
    ctx->r10 = MEM_BU(ctx->r2, -0X16);
    // 0x800B4898: nop

    // 0x800B489C: sb          $t2, -0x16($v1)
    MEM_B(-0X16, ctx->r3) = ctx->r10;
    // 0x800B48A0: lbu         $t3, -0x15($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0X15);
    // 0x800B48A4: nop

    // 0x800B48A8: sb          $t3, -0x15($v1)
    MEM_B(-0X15, ctx->r3) = ctx->r11;
    // 0x800B48AC: lh          $t4, -0x14($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X14);
    // 0x800B48B0: nop

    // 0x800B48B4: sh          $t4, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r12;
    // 0x800B48B8: lh          $t0, -0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X12);
    // 0x800B48BC: nop

    // 0x800B48C0: sh          $t0, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r8;
    // 0x800B48C4: lh          $t5, -0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, -0X10);
    // 0x800B48C8: nop

    // 0x800B48CC: sh          $t5, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r13;
    // 0x800B48D0: lbu         $t6, -0xE($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0XE);
    // 0x800B48D4: nop

    // 0x800B48D8: sb          $t6, -0xE($v1)
    MEM_B(-0XE, ctx->r3) = ctx->r14;
    // 0x800B48DC: lbu         $t7, -0xD($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0XD);
    // 0x800B48E0: nop

    // 0x800B48E4: sb          $t7, -0xD($v1)
    MEM_B(-0XD, ctx->r3) = ctx->r15;
    // 0x800B48E8: lbu         $t9, -0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0XC);
    // 0x800B48EC: nop

    // 0x800B48F0: sb          $t9, -0xC($v1)
    MEM_B(-0XC, ctx->r3) = ctx->r25;
    // 0x800B48F4: lbu         $t1, -0xB($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0XB);
    // 0x800B48F8: nop

    // 0x800B48FC: sb          $t1, -0xB($v1)
    MEM_B(-0XB, ctx->r3) = ctx->r9;
    // 0x800B4900: lh          $t8, -0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, -0XA);
    // 0x800B4904: nop

    // 0x800B4908: sh          $t8, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r24;
    // 0x800B490C: lh          $t2, -0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, -0X8);
    // 0x800B4910: nop

    // 0x800B4914: sh          $t2, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r10;
    // 0x800B4918: lh          $t3, -0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X6);
    // 0x800B491C: nop

    // 0x800B4920: sh          $t3, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r11;
    // 0x800B4924: lbu         $t4, -0x4($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X4);
    // 0x800B4928: nop

    // 0x800B492C: sb          $t4, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r12;
    // 0x800B4930: lbu         $t0, -0x3($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X3);
    // 0x800B4934: nop

    // 0x800B4938: sb          $t0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r8;
    // 0x800B493C: lbu         $t5, -0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X2);
    // 0x800B4940: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800B4944: sb          $t5, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r13;
    // 0x800B4948: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x800B494C: nop

    // 0x800B4950: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800B4954: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800B4958: nop

    // 0x800B495C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x800B4960: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800B4964: nop

    // 0x800B4968: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x800B496C: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x800B4970: nop

    // 0x800B4974: sh          $t1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r9;
    // 0x800B4978: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x800B497C: nop

    // 0x800B4980: sb          $t8, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r24;
    // 0x800B4984: lbu         $t2, 0x7($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X7);
    // 0x800B4988: nop

    // 0x800B498C: sb          $t2, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r10;
    // 0x800B4990: lbu         $t3, 0x8($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X8);
    // 0x800B4994: nop

    // 0x800B4998: sb          $t3, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r11;
    // 0x800B499C: lbu         $t4, 0x9($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X9);
    // 0x800B49A0: nop

    // 0x800B49A4: sb          $t4, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r12;
    // 0x800B49A8: bgez        $s2, L_800B4438
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800B49AC: sb          $t0, 0x77($s0)
        MEM_B(0X77, ctx->r16) = ctx->r8;
            goto L_800B4438;
    }
    // 0x800B49AC: sb          $t0, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r8;
L_800B49B0:
    // 0x800B49B0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800B49B4:
    // 0x800B49B4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B49B8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B49BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B49C0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B49C4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B49C8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B49CC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B49D0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800B49D4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800B49D8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800B49DC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800B49E0: jr          $ra
    // 0x800B49E4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800B49E4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void obj_init_fogchanger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF58: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003CF5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8003CF60: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8003CF64: bgez        $t6, L_8003CF78
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8003CF68: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8003CF78;
    }
    // 0x8003CF68: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003CF6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003CF70: nop

    // 0x8003CF74: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8003CF78:
    // 0x8003CF78: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003CF7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CF80: nop

    // 0x8003CF84: mul.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8003CF88: nop

    // 0x8003CF8C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003CF90: jr          $ra
    // 0x8003CF94: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8003CF94: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void cutscene_id_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E488: jr          $ra
    // 0x8001E48C: sh          $a0, -0x4C06($at)
    MEM_H(-0X4C06, ctx->r1) = ctx->r4;
    return;
    // 0x8001E48C: sh          $a0, -0x4C06($at)
    MEM_H(-0X4C06, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_init_groundzipper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035B30: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80035B34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80035B38: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80035B3C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80035B40: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035B44: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80035B48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035B4C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80035B50: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80035B54: bc1f        L_80035B64
    if (!c1cs) {
        // 0x80035B58: nop
    
            goto L_80035B64;
    }
    // 0x80035B58: nop

    // 0x80035B5C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80035B60: nop

L_80035B64:
    // 0x80035B64: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80035B68: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80035B6C: lw          $t8, 0x50($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X50);
    // 0x80035B70: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80035B74: nop

    // 0x80035B78: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80035B7C: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80035B80: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80035B84: nop

    // 0x80035B88: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80035B8C: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x80035B90: lbu         $t0, 0xA($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XA);
    // 0x80035B94: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x80035B98: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x80035B9C: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x80035BA0: lb          $t2, 0x3A($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X3A);
    // 0x80035BA4: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x80035BA8: nop

    // 0x80035BAC: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80035BB0: bne         $at, $zero, L_80035BC0
    if (ctx->r1 != 0) {
        // 0x80035BB4: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_80035BC0;
    }
    // 0x80035BB4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80035BB8: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
    // 0x80035BBC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
L_80035BC0:
    // 0x80035BC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80035BC4: nop

    // 0x80035BC8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80035BCC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80035BD0: nop

    // 0x80035BD4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80035BD8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035BDC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80035BE0: nop

    // 0x80035BE4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80035BE8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80035BEC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80035BF0: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80035BF4: bgez        $v0, L_80035C00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80035BF8: sw          $v0, 0x78($a0)
        MEM_W(0X78, ctx->r4) = ctx->r2;
            goto L_80035C00;
    }
    // 0x80035BF8: sw          $v0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r2;
    // 0x80035BFC: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
L_80035C00:
    // 0x80035C00: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80035C04: nop

    // 0x80035C08: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80035C0C: bne         $at, $zero, L_80035C18
    if (ctx->r1 != 0) {
        // 0x80035C10: nop
    
            goto L_80035C18;
    }
    // 0x80035C10: nop

    // 0x80035C14: sw          $t7, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r15;
L_80035C18:
    // 0x80035C18: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C1C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80035C20: sh          $t8, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r24;
    // 0x80035C24: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C28: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80035C2C: sb          $zero, 0x11($t0)
    MEM_B(0X11, ctx->r8) = 0;
    // 0x80035C30: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C34: addiu       $t4, $zero, -0x64
    ctx->r12 = ADD32(0, -0X64);
    // 0x80035C38: sb          $t1, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r9;
    // 0x80035C3C: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C40: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80035C44: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    // 0x80035C48: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C4C: nop

    // 0x80035C50: sb          $t4, 0x16($t5)
    MEM_B(0X16, ctx->r13) = ctx->r12;
    // 0x80035C54: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C58: nop

    // 0x80035C5C: sb          $t6, 0x17($t7)
    MEM_B(0X17, ctx->r15) = ctx->r14;
    // 0x80035C60: jal         0x8009C850
    // 0x80035C64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x80035C64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80035C68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80035C6C: sll         $t8, $v0, 10
    ctx->r24 = S32(ctx->r2 << 10);
    // 0x80035C70: bgez        $t8, L_80035C84
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80035C74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035C84;
    }
    // 0x80035C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035C78: jal         0x8000FFB8
    // 0x80035C7C: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x80035C7C: nop

    after_1:
    // 0x80035C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035C84:
    // 0x80035C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035C88: jr          $ra
    // 0x80035C8C: nop

    return;
    // 0x80035C8C: nop

;}
RECOMP_FUNC void stack_pointer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8230: jr          $ra
    // 0x800B8234: or          $v0, $sp, $zero
    ctx->r2 = ctx->r29 | 0;
    return;
    // 0x800B8234: or          $v0, $sp, $zero
    ctx->r2 = ctx->r29 | 0;
;}
RECOMP_FUNC void waves_init_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8654: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B8658: lw          $v0, -0x59C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X59C8);
    // 0x800B865C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800B8660: beq         $v1, $v0, L_800B867C
    if (ctx->r3 == ctx->r2) {
        // 0x800B8664: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800B867C;
    }
    // 0x800B8664: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B8668: lbu         $t6, 0x56($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X56);
    // 0x800B866C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B8670: addiu       $a1, $a1, -0x5A78
    ctx->r5 = ADD32(ctx->r5, -0X5A78);
    // 0x800B8674: b           L_800B8688
    // 0x800B8678: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
        goto L_800B8688;
    // 0x800B8678: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_800B867C:
    // 0x800B867C: addiu       $a1, $a1, -0x5A78
    ctx->r5 = ADD32(ctx->r5, -0X5A78);
    // 0x800B8680: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800B8684: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_800B8688:
    // 0x800B8688: lbu         $t8, 0x57($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X57);
    // 0x800B868C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800B8690: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800B8694: lbu         $t9, 0x58($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X58);
    // 0x800B8698: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B869C: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800B86A0: lh          $t0, 0x5A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X5A);
    // 0x800B86A4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800B86A8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B86AC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800B86B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B86B4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B86B8: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x800B86BC: lbu         $t1, 0x59($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X59);
    // 0x800B86C0: nop

    // 0x800B86C4: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800B86C8: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x800B86CC: lbu         $t3, 0x5C($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X5C);
    // 0x800B86D0: nop

    // 0x800B86D4: sw          $t3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r11;
    // 0x800B86D8: lh          $t4, 0x5E($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X5E);
    // 0x800B86DC: nop

    // 0x800B86E0: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800B86E4: nop

    // 0x800B86E8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B86EC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B86F0: swc1        $f18, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f18.u32l;
    // 0x800B86F4: lbu         $t5, 0x5D($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X5D);
    // 0x800B86F8: nop

    // 0x800B86FC: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B8700: sw          $t6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r14;
    // 0x800B8704: lh          $t7, 0x60($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X60);
    // 0x800B8708: nop

    // 0x800B870C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B8710: beq         $v1, $v0, L_800B8724
    if (ctx->r3 == ctx->r2) {
        // 0x800B8714: sw          $t8, 0x20($a1)
        MEM_W(0X20, ctx->r5) = ctx->r24;
            goto L_800B8724;
    }
    // 0x800B8714: sw          $t8, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r24;
    // 0x800B8718: lh          $t9, 0x6E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X6E);
    // 0x800B871C: b           L_800B8728
    // 0x800B8720: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
        goto L_800B8728;
    // 0x800B8720: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
L_800B8724:
    // 0x800B8724: sw          $t0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r8;
L_800B8728:
    // 0x800B8728: lbu         $t1, 0x71($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X71);
    // 0x800B872C: nop

    // 0x800B8730: sw          $t1, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r9;
    // 0x800B8734: lh          $t2, 0x68($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X68);
    // 0x800B8738: nop

    // 0x800B873C: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x800B8740: sw          $t3, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r11;
    // 0x800B8744: lbu         $t4, 0x6A($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X6A);
    // 0x800B8748: nop

    // 0x800B874C: sw          $t4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r12;
    // 0x800B8750: lbu         $t5, 0x6B($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X6B);
    // 0x800B8754: nop

    // 0x800B8758: sw          $t5, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r13;
    // 0x800B875C: lb          $t6, 0x6C($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X6C);
    // 0x800B8760: nop

    // 0x800B8764: sw          $t6, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->r14;
    // 0x800B8768: lb          $t7, 0x6D($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X6D);
    // 0x800B876C: nop

    // 0x800B8770: sw          $t7, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r15;
    // 0x800B8774: lh          $t8, 0x62($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X62);
    // 0x800B8778: nop

    // 0x800B877C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B8780: nop

    // 0x800B8784: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B8788: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B878C: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
    // 0x800B8790: lh          $t9, 0x64($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X64);
    // 0x800B8794: nop

    // 0x800B8798: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800B879C: nop

    // 0x800B87A0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B87A4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B87A8: swc1        $f18, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f18.u32l;
    // 0x800B87AC: lh          $t0, 0x66($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X66);
    // 0x800B87B0: nop

    // 0x800B87B4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B87B8: nop

    // 0x800B87BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B87C0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B87C4: swc1        $f8, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f8.u32l;
    // 0x800B87C8: lbu         $t1, 0x70($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X70);
    // 0x800B87CC: jr          $ra
    // 0x800B87D0: sw          $t1, 0x4C($a1)
    MEM_W(0X4C, ctx->r5) = ctx->r9;
    return;
    // 0x800B87D0: sw          $t1, 0x4C($a1)
    MEM_W(0X4C, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void menu_timestamp_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081C50: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80081C54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081C58: lbu         $t7, 0x73($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X73);
    // 0x80081C5C: sb          $a3, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r7;
    // 0x80081C60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081C64: lbu         $t8, 0x77($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X77);
    // 0x80081C68: lbu         $t9, 0x7B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X7B);
    // 0x80081C6C: sb          $t7, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r15;
    // 0x80081C70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80081C74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081C78: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80081C7C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80081C80: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80081C84: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80081C88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80081C8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80081C90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80081C94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80081C98: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80081C9C: bne         $t9, $zero, L_80081CF4
    if (ctx->r25 != 0) {
        // 0x80081CA0: sb          $t8, -0x5D4($at)
        MEM_B(-0X5D4, ctx->r1) = ctx->r24;
            goto L_80081CF4;
    }
    // 0x80081CA0: sb          $t8, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r24;
    // 0x80081CA4: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80081CA8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80081CAC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80081CB0: addiu       $s2, $s2, -0x324
    ctx->r18 = ADD32(ctx->r18, -0X324);
    // 0x80081CB4: addiu       $t1, $a2, -0x2
    ctx->r9 = ADD32(ctx->r6, -0X2);
    // 0x80081CB8: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80081CBC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80081CC0: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
    // 0x80081CC4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081CC8: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80081CCC: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80081CD0: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80081CD4: swc1        $f10, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->f10.u32l;
    // 0x80081CD8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80081CDC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80081CE0: addiu       $s0, $a1, -0x27
    ctx->r16 = ADD32(ctx->r5, -0X27);
    // 0x80081CE4: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x80081CE8: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80081CEC: b           L_80081D40
    // 0x80081CF0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
        goto L_80081D40;
    // 0x80081CF0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
L_80081CF4:
    // 0x80081CF4: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80081CF8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80081CFC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80081D00: addiu       $s2, $s2, -0x324
    ctx->r18 = ADD32(ctx->r18, -0X324);
    // 0x80081D04: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x80081D08: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80081D0C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80081D10: swc1        $f18, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f18.u32l;
    // 0x80081D14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80081D18: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80081D1C: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x80081D20: swc1        $f6, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f6.u32l;
    // 0x80081D24: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80081D28: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80081D2C: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x80081D30: addiu       $s0, $s0, -0x1C
    ctx->r16 = ADD32(ctx->r16, -0X1C);
    // 0x80081D34: addiu       $s6, $zero, 0x9
    ctx->r22 = ADD32(0, 0X9);
    // 0x80081D38: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80081D3C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_80081D40:
    // 0x80081D40: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80081D44: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x80081D48: jal         0x800597E0
    // 0x80081D4C: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    get_timestamp_from_frames(rdram, ctx);
        goto after_0;
    // 0x80081D4C: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x80081D50: jal         0x80068748
    // 0x80081D54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x80081D54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80081D58: jal         0x8007C36C
    // 0x80081D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_2;
    // 0x80081D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80081D60: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80081D64: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x80081D68: div         $zero, $t0, $s4
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r20)));
    // 0x80081D6C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80081D70: sll         $s1, $s3, 5
    ctx->r17 = S32(ctx->r19 << 5);
    // 0x80081D74: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80081D78: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80081D7C: bne         $s4, $zero, L_80081D88
    if (ctx->r20 != 0) {
        // 0x80081D80: nop
    
            goto L_80081D88;
    }
    // 0x80081D80: nop

    // 0x80081D84: break       7
    do_break(2148015492);
L_80081D88:
    // 0x80081D88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081D8C: bne         $s4, $at, L_80081DA0
    if (ctx->r20 != ctx->r1) {
        // 0x80081D90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081DA0;
    }
    // 0x80081D90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081D94: bne         $t0, $at, L_80081DA0
    if (ctx->r8 != ctx->r1) {
        // 0x80081D98: nop
    
            goto L_80081DA0;
    }
    // 0x80081D98: nop

    // 0x80081D9C: break       6
    do_break(2148015516);
L_80081DA0:
    // 0x80081DA0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081DA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081DA8: mflo        $t1
    ctx->r9 = lo;
    // 0x80081DAC: sh          $t1, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r9;
    // 0x80081DB0: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80081DB4: nop

    // 0x80081DB8: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80081DBC: jal         0x8009CFA4
    // 0x80081DC0: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_3;
    // 0x80081DC0: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
    after_3:
    // 0x80081DC4: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80081DC8: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80081DCC: div         $zero, $t6, $s4
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r20)));
    // 0x80081DD0: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x80081DD4: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80081DD8: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x80081DDC: bne         $s4, $zero, L_80081DE8
    if (ctx->r20 != 0) {
        // 0x80081DE0: nop
    
            goto L_80081DE8;
    }
    // 0x80081DE0: nop

    // 0x80081DE4: break       7
    do_break(2148015588);
L_80081DE8:
    // 0x80081DE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081DEC: bne         $s4, $at, L_80081E00
    if (ctx->r20 != ctx->r1) {
        // 0x80081DF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081E00;
    }
    // 0x80081DF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081DF4: bne         $t6, $at, L_80081E00
    if (ctx->r14 != ctx->r1) {
        // 0x80081DF8: nop
    
            goto L_80081E00;
    }
    // 0x80081DF8: nop

    // 0x80081DFC: break       6
    do_break(2148015612);
L_80081E00:
    // 0x80081E00: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80081E04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081E08: mfhi        $t7
    ctx->r15 = hi;
    // 0x80081E0C: sh          $t7, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r15;
    // 0x80081E10: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80081E14: nop

    // 0x80081E18: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x80081E1C: jal         0x8009CFA4
    // 0x80081E20: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_4;
    // 0x80081E20: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    after_4:
    // 0x80081E24: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80081E28: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80081E2C: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x80081E30: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80081E34: sll         $v0, $s5, 5
    ctx->r2 = S32(ctx->r21 << 5);
    // 0x80081E38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80081E3C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80081E40: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80081E44: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
    // 0x80081E48: jal         0x8009CFA4
    // 0x80081E4C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    menu_element_render(rdram, ctx);
        goto after_5;
    // 0x80081E4C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_5:
    // 0x80081E50: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80081E54: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80081E58: div         $zero, $t6, $s4
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r20)));
    // 0x80081E5C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80081E60: addu        $s0, $s0, $t5
    ctx->r16 = ADD32(ctx->r16, ctx->r13);
    // 0x80081E64: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x80081E68: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80081E6C: bne         $s4, $zero, L_80081E78
    if (ctx->r20 != 0) {
        // 0x80081E70: nop
    
            goto L_80081E78;
    }
    // 0x80081E70: nop

    // 0x80081E74: break       7
    do_break(2148015732);
L_80081E78:
    // 0x80081E78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081E7C: bne         $s4, $at, L_80081E90
    if (ctx->r20 != ctx->r1) {
        // 0x80081E80: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081E90;
    }
    // 0x80081E80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081E84: bne         $t6, $at, L_80081E90
    if (ctx->r14 != ctx->r1) {
        // 0x80081E88: nop
    
            goto L_80081E90;
    }
    // 0x80081E88: nop

    // 0x80081E8C: break       6
    do_break(2148015756);
L_80081E90:
    // 0x80081E90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081E94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081E98: mflo        $t8
    ctx->r24 = lo;
    // 0x80081E9C: sh          $t8, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r24;
    // 0x80081EA0: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80081EA4: nop

    // 0x80081EA8: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x80081EAC: jal         0x8009CFA4
    // 0x80081EB0: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_6;
    // 0x80081EB0: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    after_6:
    // 0x80081EB4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80081EB8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80081EBC: div         $zero, $t1, $s4
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r20)));
    // 0x80081EC0: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x80081EC4: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80081EC8: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x80081ECC: bne         $s4, $zero, L_80081ED8
    if (ctx->r20 != 0) {
        // 0x80081ED0: nop
    
            goto L_80081ED8;
    }
    // 0x80081ED0: nop

    // 0x80081ED4: break       7
    do_break(2148015828);
L_80081ED8:
    // 0x80081ED8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081EDC: bne         $s4, $at, L_80081EF0
    if (ctx->r20 != ctx->r1) {
        // 0x80081EE0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081EF0;
    }
    // 0x80081EE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081EE4: bne         $t1, $at, L_80081EF0
    if (ctx->r9 != ctx->r1) {
        // 0x80081EE8: nop
    
            goto L_80081EF0;
    }
    // 0x80081EE8: nop

    // 0x80081EEC: break       6
    do_break(2148015852);
L_80081EF0:
    // 0x80081EF0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80081EF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081EF8: mfhi        $t3
    ctx->r11 = hi;
    // 0x80081EFC: sh          $t3, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r11;
    // 0x80081F00: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80081F04: nop

    // 0x80081F08: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80081F0C: jal         0x8009CFA4
    // 0x80081F10: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_7;
    // 0x80081F10: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    after_7:
    // 0x80081F14: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80081F18: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80081F1C: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x80081F20: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80081F24: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80081F28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80081F2C: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80081F30: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80081F34: jal         0x8009CFA4
    // 0x80081F38: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
    menu_element_render(rdram, ctx);
        goto after_8;
    // 0x80081F38: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
    after_8:
    // 0x80081F3C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80081F40: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80081F44: div         $zero, $t4, $s4
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r20)));
    // 0x80081F48: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80081F4C: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x80081F50: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80081F54: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80081F58: bne         $s4, $zero, L_80081F64
    if (ctx->r20 != 0) {
        // 0x80081F5C: nop
    
            goto L_80081F64;
    }
    // 0x80081F5C: nop

    // 0x80081F60: break       7
    do_break(2148015968);
L_80081F64:
    // 0x80081F64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081F68: bne         $s4, $at, L_80081F7C
    if (ctx->r20 != ctx->r1) {
        // 0x80081F6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081F7C;
    }
    // 0x80081F6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081F70: bne         $t4, $at, L_80081F7C
    if (ctx->r12 != ctx->r1) {
        // 0x80081F74: nop
    
            goto L_80081F7C;
    }
    // 0x80081F74: nop

    // 0x80081F78: break       6
    do_break(2148015992);
L_80081F7C:
    // 0x80081F7C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081F80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081F84: mflo        $t3
    ctx->r11 = lo;
    // 0x80081F88: sh          $t3, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r11;
    // 0x80081F8C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80081F90: nop

    // 0x80081F94: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80081F98: jal         0x8009CFA4
    // 0x80081F9C: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_9;
    // 0x80081F9C: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    after_9:
    // 0x80081FA0: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80081FA4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80081FA8: div         $zero, $t9, $s4
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r20)));
    // 0x80081FAC: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x80081FB0: addu        $t1, $t2, $s1
    ctx->r9 = ADD32(ctx->r10, ctx->r17);
    // 0x80081FB4: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x80081FB8: bne         $s4, $zero, L_80081FC4
    if (ctx->r20 != 0) {
        // 0x80081FBC: nop
    
            goto L_80081FC4;
    }
    // 0x80081FBC: nop

    // 0x80081FC0: break       7
    do_break(2148016064);
L_80081FC4:
    // 0x80081FC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081FC8: bne         $s4, $at, L_80081FDC
    if (ctx->r20 != ctx->r1) {
        // 0x80081FCC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081FDC;
    }
    // 0x80081FCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081FD0: bne         $t9, $at, L_80081FDC
    if (ctx->r25 != ctx->r1) {
        // 0x80081FD4: nop
    
            goto L_80081FDC;
    }
    // 0x80081FD4: nop

    // 0x80081FD8: break       6
    do_break(2148016088);
L_80081FDC:
    // 0x80081FDC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80081FE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081FE4: mfhi        $t0
    ctx->r8 = hi;
    // 0x80081FE8: sh          $t0, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r8;
    // 0x80081FEC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80081FF0: nop

    // 0x80081FF4: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80081FF8: jal         0x8009CFA4
    // 0x80081FFC: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_10;
    // 0x80081FFC: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
    after_10:
    // 0x80082000: jal         0x80068748
    // 0x80082004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_11;
    // 0x80082004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x80082008: jal         0x8007C36C
    // 0x8008200C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_12;
    // 0x8008200C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80082010: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80082014: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082018: sb          $v0, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r2;
    // 0x8008201C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082020: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80082024: sb          $v0, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r2;
    // 0x80082028: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008202C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80082030: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80082034: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80082038: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008203C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80082040: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80082044: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80082048: sb          $v0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r2;
    // 0x8008204C: jr          $ra
    // 0x80082050: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80082050: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void race_finish_time_trial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE98: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001AE9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001AEA0: jal         0x8006BFF0
    // 0x8001AEA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    level_header(rdram, ctx);
        goto after_0;
    // 0x8001AEA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8001AEA8: jal         0x8006ECD0
    // 0x8001AEAC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_1;
    // 0x8001AEAC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001AEB0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8001AEB4: sb          $zero, 0x114($v0)
    MEM_B(0X114, ctx->r2) = 0;
    // 0x8001AEB8: sb          $zero, 0x116($v0)
    MEM_B(0X116, ctx->r2) = 0;
    // 0x8001AEBC: sb          $zero, 0x115($v0)
    MEM_B(0X115, ctx->r2) = 0;
    // 0x8001AEC0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001AEC4: lw          $t6, -0x4B98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B98);
    // 0x8001AEC8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8001AECC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001AED0: lw          $t9, -0x4B90($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4B90);
    // 0x8001AED4: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x8001AED8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8001AEDC: ori         $s0, $zero, 0x8CA1
    ctx->r16 = 0 | 0X8CA1;
    // 0x8001AEE0: ori         $t1, $zero, 0x8CA1
    ctx->r9 = 0 | 0X8CA1;
    // 0x8001AEE4: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001AEE8: blez        $t9, L_8001B054
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001AEEC: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_8001B054;
    }
    // 0x8001AEEC: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8001AEF0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8001AEF4:
    // 0x8001AEF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001AEF8: lw          $t6, -0x4B98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B98);
    // 0x8001AEFC: nop

    // 0x8001AF00: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x8001AF04: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001AF08: nop

    // 0x8001AF0C: lw          $a3, 0x64($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X64);
    // 0x8001AF10: nop

    // 0x8001AF14: lb          $t9, 0x2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X2);
    // 0x8001AF18: nop

    // 0x8001AF1C: bltz        $t9, L_8001B03C
    if (SIGNED(ctx->r25) < 0) {
        // 0x8001AF20: nop
    
            goto L_8001B03C;
    }
    // 0x8001AF20: nop

    // 0x8001AF24: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8001AF28: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8001AF2C: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x8001AF30: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8001AF34: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8001AF38: jal         0x8009C90C
    // 0x8001AF3C: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    get_number_of_active_players(rdram, ctx);
        goto after_2;
    // 0x8001AF3C: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    after_2:
    // 0x8001AF40: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8001AF44: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8001AF48: lb          $v1, 0x2($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X2);
    // 0x8001AF4C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8001AF50: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8001AF54: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8001AF58: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8001AF5C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001AF60: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001AF64: beq         $at, $zero, L_8001B03C
    if (ctx->r1 == 0) {
        // 0x8001AF68: addiu       $ra, $zero, 0x18
        ctx->r31 = ADD32(0, 0X18);
            goto L_8001B03C;
    }
    // 0x8001AF68: addiu       $ra, $zero, 0x18
    ctx->r31 = ADD32(0, 0X18);
    // 0x8001AF6C: multu       $v1, $ra
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AF70: mflo        $t6
    ctx->r14 = lo;
    // 0x8001AF74: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8001AF78: sb          $zero, 0x58($t7)
    MEM_B(0X58, ctx->r15) = 0;
    // 0x8001AF7C: lb          $v0, 0x1D7($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X1D7);
    // 0x8001AF80: nop

    // 0x8001AF84: bltz        $v0, L_8001B03C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001AF88: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_8001B03C;
    }
    // 0x8001AF88: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001AF8C: beq         $at, $zero, L_8001B03C
    if (ctx->r1 == 0) {
        // 0x8001AF90: nop
    
            goto L_8001B03C;
    }
    // 0x8001AF90: nop

    // 0x8001AF94: lb          $t8, 0x4B($t2)
    ctx->r24 = MEM_B(ctx->r10, 0X4B);
    // 0x8001AF98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001AF9C: blez        $t8, L_8001B010
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001AFA0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001B010;
    }
    // 0x8001AFA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AFA4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8001AFA8: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x8001AFAC: sll         $a1, $a0, 1
    ctx->r5 = S32(ctx->r4 << 1);
L_8001AFB0:
    // 0x8001AFB0: lb          $t7, 0x2($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X2);
    // 0x8001AFB4: lw          $t6, 0x128($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X128);
    // 0x8001AFB8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001AFBC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8001AFC0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8001AFC4: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8001AFC8: addu        $t7, $t9, $a1
    ctx->r15 = ADD32(ctx->r25, ctx->r5);
    // 0x8001AFCC: sh          $t6, 0x66($t7)
    MEM_H(0X66, ctx->r15) = ctx->r14;
    // 0x8001AFD0: lw          $v1, 0x128($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X128);
    // 0x8001AFD4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8001AFD8: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001AFDC: beq         $at, $zero, L_8001AFF4
    if (ctx->r1 == 0) {
        // 0x8001AFE0: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_8001AFF4;
    }
    // 0x8001AFE0: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8001AFE4: sb          $a0, 0x116($t0)
    MEM_B(0X116, ctx->r8) = ctx->r4;
    // 0x8001AFE8: lb          $t8, 0x2($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X2);
    // 0x8001AFEC: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8001AFF0: sb          $t8, 0x115($t0)
    MEM_B(0X115, ctx->r8) = ctx->r24;
L_8001AFF4:
    // 0x8001AFF4: lb          $t9, 0x4B($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X4B);
    // 0x8001AFF8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001AFFC: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001B000: beq         $at, $zero, L_8001B010
    if (ctx->r1 == 0) {
        // 0x8001B004: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8001B010;
    }
    // 0x8001B004: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001B008: bne         $a0, $t3, L_8001AFB0
    if (ctx->r4 != ctx->r11) {
        // 0x8001B00C: nop
    
            goto L_8001AFB0;
    }
    // 0x8001B00C: nop

L_8001B010:
    // 0x8001B010: lb          $t6, 0x2($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X2);
    // 0x8001B014: slt         $at, $a2, $s0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8001B018: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B01C: mflo        $t7
    ctx->r15 = lo;
    // 0x8001B020: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8001B024: beq         $at, $zero, L_8001B03C
    if (ctx->r1 == 0) {
        // 0x8001B028: sh          $a2, 0x64($t8)
        MEM_H(0X64, ctx->r24) = ctx->r6;
            goto L_8001B03C;
    }
    // 0x8001B028: sh          $a2, 0x64($t8)
    MEM_H(0X64, ctx->r24) = ctx->r6;
    // 0x8001B02C: lb          $t9, 0x2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X2);
    // 0x8001B030: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8001B034: sb          $t9, 0x114($t0)
    MEM_B(0X114, ctx->r8) = ctx->r25;
    // 0x8001B038: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
L_8001B03C:
    // 0x8001B03C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B040: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8001B044: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001B048: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001B04C: bne         $at, $zero, L_8001AEF4
    if (ctx->r1 != 0) {
        // 0x8001B050: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_8001AEF4;
    }
    // 0x8001B050: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
L_8001B054:
    // 0x8001B054: sb          $zero, 0x117($t0)
    MEM_B(0X117, ctx->r8) = 0;
    // 0x8001B058: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B05C: lbu         $t7, -0x4B8B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4B8B);
    // 0x8001B060: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001B064: beq         $t7, $zero, L_8001B2AC
    if (ctx->r15 == 0) {
        // 0x8001B068: addiu       $ra, $zero, 0x18
        ctx->r31 = ADD32(0, 0X18);
            goto L_8001B2AC;
    }
    // 0x8001B068: addiu       $ra, $zero, 0x18
    ctx->r31 = ADD32(0, 0X18);
    // 0x8001B06C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B070: lh          $v0, -0x4BFE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4BFE);
    // 0x8001B074: nop

    // 0x8001B078: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001B07C: beq         $at, $zero, L_8001B08C
    if (ctx->r1 == 0) {
        // 0x8001B080: nop
    
            goto L_8001B08C;
    }
    // 0x8001B080: nop

    // 0x8001B084: bgez        $v0, L_8001B090
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001B088: nop
    
            goto L_8001B090;
    }
    // 0x8001B088: nop

L_8001B08C:
    // 0x8001B08C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B090:
    // 0x8001B090: lb          $t9, 0x115($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X115);
    // 0x8001B094: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001B098: bne         $t9, $zero, L_8001B0FC
    if (ctx->r25 != 0) {
        // 0x8001B09C: sb          $t8, 0x117($t0)
        MEM_B(0X117, ctx->r8) = ctx->r24;
            goto L_8001B0FC;
    }
    // 0x8001B09C: sb          $t8, 0x117($t0)
    MEM_B(0X117, ctx->r8) = ctx->r24;
    // 0x8001B0A0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001B0A4: lbu         $t9, 0x49($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X49);
    // 0x8001B0A8: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8001B0AC: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x8001B0B0: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8001B0B4: addu        $a0, $t8, $t6
    ctx->r4 = ADD32(ctx->r24, ctx->r14);
    // 0x8001B0B8: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8001B0BC: nop

    // 0x8001B0C0: beq         $v1, $zero, L_8001B0D0
    if (ctx->r3 == 0) {
        // 0x8001B0C4: slt         $at, $t1, $v1
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001B0D0;
    }
    // 0x8001B0C4: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001B0C8: beq         $at, $zero, L_8001B0FC
    if (ctx->r1 == 0) {
        // 0x8001B0CC: nop
    
            goto L_8001B0FC;
    }
    // 0x8001B0CC: nop

L_8001B0D0:
    // 0x8001B0D0: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x8001B0D4: lb          $t7, 0x115($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X115);
    // 0x8001B0D8: lb          $t6, 0x116($t0)
    ctx->r14 = MEM_B(ctx->r8, 0X116);
    // 0x8001B0DC: multu       $t7, $ra
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B0E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B0E4: mflo        $t9
    ctx->r25 = lo;
    // 0x8001B0E8: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x8001B0EC: lb          $t8, 0x58($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X58);
    // 0x8001B0F0: sllv        $t9, $t7, $t6
    ctx->r25 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8001B0F4: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8001B0F8: sb          $t7, 0x58($v1)
    MEM_B(0X58, ctx->r3) = ctx->r15;
L_8001B0FC:
    // 0x8001B0FC: lb          $a1, 0x114($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X114);
    // 0x8001B100: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001B104: bne         $a1, $zero, L_8001B168
    if (ctx->r5 != 0) {
        // 0x8001B108: nop
    
            goto L_8001B168;
    }
    // 0x8001B108: nop

    // 0x8001B10C: lbu         $t7, 0x49($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X49);
    // 0x8001B110: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x8001B114: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x8001B118: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8001B11C: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x8001B120: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8001B124: nop

    // 0x8001B128: beq         $v1, $zero, L_8001B138
    if (ctx->r3 == 0) {
        // 0x8001B12C: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001B138;
    }
    // 0x8001B12C: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001B130: beq         $at, $zero, L_8001B168
    if (ctx->r1 == 0) {
        // 0x8001B134: nop
    
            goto L_8001B168;
    }
    // 0x8001B134: nop

L_8001B138:
    // 0x8001B138: sh          $s0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r16;
    // 0x8001B13C: lb          $t8, 0x114($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X114);
    // 0x8001B140: nop

    // 0x8001B144: multu       $t8, $ra
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B148: mflo        $t7
    ctx->r15 = lo;
    // 0x8001B14C: addu        $v1, $t0, $t7
    ctx->r3 = ADD32(ctx->r8, ctx->r15);
    // 0x8001B150: lb          $t9, 0x58($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X58);
    // 0x8001B154: nop

    // 0x8001B158: ori         $t6, $t9, 0x80
    ctx->r14 = ctx->r25 | 0X80;
    // 0x8001B15C: sb          $t6, 0x58($v1)
    MEM_B(0X58, ctx->r3) = ctx->r14;
    // 0x8001B160: lb          $a1, 0x114($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X114);
    // 0x8001B164: nop

L_8001B168:
    // 0x8001B168: bne         $a1, $zero, L_8001B2AC
    if (ctx->r5 != 0) {
        // 0x8001B16C: slti        $at, $s0, 0x2A30
        ctx->r1 = SIGNED(ctx->r16) < 0X2A30 ? 1 : 0;
            goto L_8001B2AC;
    }
    // 0x8001B16C: slti        $at, $s0, 0x2A30
    ctx->r1 = SIGNED(ctx->r16) < 0X2A30 ? 1 : 0;
    // 0x8001B170: beq         $at, $zero, L_8001B204
    if (ctx->r1 == 0) {
        // 0x8001B174: nop
    
            goto L_8001B204;
    }
    // 0x8001B174: nop

    // 0x8001B178: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001B17C: lh          $t8, -0x3368($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3368);
    // 0x8001B180: nop

    // 0x8001B184: bne         $v0, $t8, L_8001B1C4
    if (ctx->r2 != ctx->r24) {
        // 0x8001B188: nop
    
            goto L_8001B1C4;
    }
    // 0x8001B188: nop

    // 0x8001B18C: jal         0x800599F8
    // 0x8001B190: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    timetrial_map_id(rdram, ctx);
        goto after_3;
    // 0x8001B190: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_3:
    // 0x8001B194: jal         0x8006BFC8
    // 0x8001B198: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_4;
    // 0x8001B198: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_4:
    // 0x8001B19C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001B1A0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8001B1A4: bne         $v0, $t7, L_8001B1C4
    if (ctx->r2 != ctx->r15) {
        // 0x8001B1A8: addiu       $t3, $zero, 0x5
        ctx->r11 = ADD32(0, 0X5);
            goto L_8001B1C4;
    }
    // 0x8001B1A8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001B1AC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001B1B0: lh          $t9, -0x336C($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X336C);
    // 0x8001B1B4: nop

    // 0x8001B1B8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001B1BC: beq         $at, $zero, L_8001B204
    if (ctx->r1 == 0) {
        // 0x8001B1C0: nop
    
            goto L_8001B204;
    }
    // 0x8001B1C0: nop

L_8001B1C4:
    // 0x8001B1C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B1C8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B1CC: lh          $t6, -0x4BFE($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4BFE);
    // 0x8001B1D0: sh          $s0, -0x336C($at)
    MEM_H(-0X336C, ctx->r1) = ctx->r16;
    // 0x8001B1D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B1D8: sh          $t6, -0x3368($at)
    MEM_H(-0X3368, ctx->r1) = ctx->r14;
    // 0x8001B1DC: lb          $t8, 0x59($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X59);
    // 0x8001B1E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B1E4: jal         0x8006BFC8
    // 0x8001B1E8: sh          $t8, -0x3364($at)
    MEM_H(-0X3364, ctx->r1) = ctx->r24;
    level_id(rdram, ctx);
        goto after_5;
    // 0x8001B1E8: sh          $t8, -0x3364($at)
    MEM_H(-0X3364, ctx->r1) = ctx->r24;
    after_5:
    // 0x8001B1EC: jal         0x800599D4
    // 0x8001B1F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    timetrial_swap_player_ghost(rdram, ctx);
        goto after_6;
    // 0x8001B1F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8001B1F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B1F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B1FC: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001B200: sb          $t7, -0x3360($at)
    MEM_B(-0X3360, ctx->r1) = ctx->r15;
L_8001B204:
    // 0x8001B204: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8001B208: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x8001B20C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8001B210: bne         $t9, $zero, L_8001B254
    if (ctx->r25 != 0) {
        // 0x8001B214: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8001B254;
    }
    // 0x8001B214: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001B218: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x8001B21C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8001B220: div         $zero, $t6, $t3
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r11)));
    // 0x8001B224: bne         $t3, $zero, L_8001B230
    if (ctx->r11 != 0) {
        // 0x8001B228: nop
    
            goto L_8001B230;
    }
    // 0x8001B228: nop

    // 0x8001B22C: break       7
    do_break(2147594796);
L_8001B230:
    // 0x8001B230: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B234: bne         $t3, $at, L_8001B248
    if (ctx->r11 != ctx->r1) {
        // 0x8001B238: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001B248;
    }
    // 0x8001B238: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B23C: bne         $t6, $at, L_8001B248
    if (ctx->r14 != ctx->r1) {
        // 0x8001B240: nop
    
            goto L_8001B248;
    }
    // 0x8001B240: nop

    // 0x8001B244: break       6
    do_break(2147594820);
L_8001B248:
    // 0x8001B248: mflo        $s0
    ctx->r16 = lo;
    // 0x8001B24C: nop

    // 0x8001B250: nop

L_8001B254:
    // 0x8001B254: lh          $t8, -0x4C00($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X4C00);
    // 0x8001B258: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8001B25C: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001B260: beq         $at, $zero, L_8001B2A4
    if (ctx->r1 == 0) {
        // 0x8001B264: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8001B2A4;
    }
    // 0x8001B264: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8001B268: lbu         $t7, -0x335C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X335C);
    // 0x8001B26C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8001B270: beq         $t7, $zero, L_8001B294
    if (ctx->r15 == 0) {
        // 0x8001B274: nop
    
            goto L_8001B294;
    }
    // 0x8001B274: nop

    // 0x8001B278: jal         0x8006BFC8
    // 0x8001B27C: nop

    level_id(rdram, ctx);
        goto after_7;
    // 0x8001B27C: nop

    after_7:
    // 0x8001B280: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8001B284: jal         0x8001B3F8
    // 0x8001B288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tt_ghost_beaten(rdram, ctx);
        goto after_8;
    // 0x8001B288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x8001B28C: b           L_8001B2B0
    // 0x8001B290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001B2B0;
    // 0x8001B290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B294:
    // 0x8001B294: jal         0x800A72FC
    // 0x8001B298: nop

    hud_time_trial_message(rdram, ctx);
        goto after_9;
    // 0x8001B298: nop

    after_9:
    // 0x8001B29C: b           L_8001B2B0
    // 0x8001B2A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001B2B0;
    // 0x8001B2A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B2A4:
    // 0x8001B2A4: jal         0x800A72FC
    // 0x8001B2A8: nop

    hud_time_trial_message(rdram, ctx);
        goto after_10;
    // 0x8001B2A8: nop

    after_10:
L_8001B2AC:
    // 0x8001B2AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B2B0:
    // 0x8001B2B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B2B4: jr          $ra
    // 0x8001B2B8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001B2B8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800179D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017A04: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80017A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017A0C: addiu       $a1, $a1, -0x4A8C
    ctx->r5 = ADD32(ctx->r5, -0X4A8C);
L_80017A10:
    // 0x80017A10: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80017A14: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x80017A18: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80017A1C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80017A20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80017A24: beq         $a0, $zero, L_80017A34
    if (ctx->r4 == 0) {
        // 0x80017A28: sll         $t9, $v0, 16
        ctx->r25 = S32(ctx->r2 << 16);
            goto L_80017A34;
    }
    // 0x80017A28: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80017A2C: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x80017A30: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80017A34:
    // 0x80017A34: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80017A38: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80017A3C: bne         $at, $zero, L_80017A10
    if (ctx->r1 != 0) {
        // 0x80017A40: nop
    
            goto L_80017A10;
    }
    // 0x80017A40: nop

    // 0x80017A44: jr          $ra
    // 0x80017A48: nop

    return;
    // 0x80017A48: nop

;}
RECOMP_FUNC void alCSPSetBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7FC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7FC8: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800C7FCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C7FD0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7FD4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7FD8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C7FDC: jal         0x800C970C
    // 0x800C7FE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7FE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C7FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7FE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7FEC: jr          $ra
    // 0x800C7FF0: nop

    return;
    // 0x800C7FF0: nop

;}
RECOMP_FUNC void input_clamp_stick_mag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A864: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x8006A868: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006A86C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006A870: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x8006A874: beq         $at, $zero, L_8006A890
    if (ctx->r1 == 0) {
        // 0x8006A878: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8006A890;
    }
    // 0x8006A878: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8006A87C: slti        $at, $t7, -0x7
    ctx->r1 = SIGNED(ctx->r15) < -0X7 ? 1 : 0;
    // 0x8006A880: bne         $at, $zero, L_8006A890
    if (ctx->r1 != 0) {
        // 0x8006A884: nop
    
            goto L_8006A890;
    }
    // 0x8006A884: nop

    // 0x8006A888: jr          $ra
    // 0x8006A88C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006A88C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A890:
    // 0x8006A890: blez        $a0, L_8006A8B8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006A894: nop
    
            goto L_8006A8B8;
    }
    // 0x8006A894: nop

    // 0x8006A898: addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    // 0x8006A89C: sll         $t8, $a0, 24
    ctx->r24 = S32(ctx->r4 << 24);
    // 0x8006A8A0: sra         $a0, $t8, 24
    ctx->r4 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8006A8A4: slti        $at, $a0, 0x47
    ctx->r1 = SIGNED(ctx->r4) < 0X47 ? 1 : 0;
    // 0x8006A8A8: bne         $at, $zero, L_8006A8D8
    if (ctx->r1 != 0) {
        // 0x8006A8AC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8006A8D8;
    }
    // 0x8006A8AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006A8B0: b           L_8006A8D4
    // 0x8006A8B4: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
        goto L_8006A8D4;
    // 0x8006A8B4: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
L_8006A8B8:
    // 0x8006A8B8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8006A8BC: sll         $t0, $a0, 24
    ctx->r8 = S32(ctx->r4 << 24);
    // 0x8006A8C0: sra         $a0, $t0, 24
    ctx->r4 = S32(SIGNED(ctx->r8) >> 24);
    // 0x8006A8C4: slti        $at, $a0, -0x46
    ctx->r1 = SIGNED(ctx->r4) < -0X46 ? 1 : 0;
    // 0x8006A8C8: beq         $at, $zero, L_8006A8D8
    if (ctx->r1 == 0) {
        // 0x8006A8CC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8006A8D8;
    }
    // 0x8006A8CC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006A8D0: addiu       $a0, $zero, -0x46
    ctx->r4 = ADD32(0, -0X46);
L_8006A8D4:
    // 0x8006A8D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006A8D8:
    // 0x8006A8D8: jr          $ra
    // 0x8006A8DC: nop

    return;
    // 0x8006A8DC: nop

;}
RECOMP_FUNC void ainode_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BF54: addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // 0x8001BF58: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BF5C: addiu       $v0, $v0, -0x4B70
    ctx->r2 = ADD32(ctx->r2, -0X4B70);
    // 0x8001BF60: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001BF64: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001BF68: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001BF6C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001BF70: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001BF74: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001BF78: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001BF7C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001BF80: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001BF84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001BF88: beq         $t6, $zero, L_8001C41C
    if (ctx->r14 == 0) {
        // 0x8001BF8C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8001C41C;
    }
    // 0x8001BF8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001BF90: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001BF94: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8001BF98: addiu       $t2, $t2, -0x4B7C
    ctx->r10 = ADD32(ctx->r10, -0X4B7C);
    // 0x8001BF9C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_8001BFA0:
    // 0x8001BFA0: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8001BFA4: nop

    // 0x8001BFA8: addu        $t8, $t7, $fp
    ctx->r24 = ADD32(ctx->r15, ctx->r30);
    // 0x8001BFAC: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x8001BFB0: slti        $at, $fp, 0x200
    ctx->r1 = SIGNED(ctx->r30) < 0X200 ? 1 : 0;
    // 0x8001BFB4: bne         $at, $zero, L_8001BFA0
    if (ctx->r1 != 0) {
        // 0x8001BFB8: sw          $zero, 0x0($t8)
        MEM_W(0X0, ctx->r24) = 0;
            goto L_8001BFA0;
    }
    // 0x8001BFB8: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8001BFBC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001BFC0: lw          $a0, -0x4C24($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C24);
    // 0x8001BFC4: sh          $zero, 0x186($sp)
    MEM_H(0X186, ctx->r29) = 0;
    // 0x8001BFC8: blez        $a0, L_8001C080
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001BFCC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001C080;
    }
    // 0x8001BFCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001BFD0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001BFD4: addiu       $a1, $a1, -0x4C28
    ctx->r5 = ADD32(ctx->r5, -0X4C28);
    // 0x8001BFD8: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8001BFDC: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x8001BFE0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_8001BFE4:
    // 0x8001BFE4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8001BFE8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001BFEC: addu        $t3, $t9, $fp
    ctx->r11 = ADD32(ctx->r25, ctx->r30);
    // 0x8001BFF0: lw          $s3, 0x0($t3)
    ctx->r19 = MEM_W(ctx->r11, 0X0);
    // 0x8001BFF4: nop

    // 0x8001BFF8: lh          $t4, 0x6($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X6);
    // 0x8001BFFC: nop

    // 0x8001C000: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8001C004: bne         $t5, $zero, L_8001C078
    if (ctx->r13 != 0) {
        // 0x8001C008: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8001C078;
    }
    // 0x8001C008: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001C00C: lh          $t6, 0x48($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X48);
    // 0x8001C010: nop

    // 0x8001C014: bne         $a2, $t6, L_8001C078
    if (ctx->r6 != ctx->r14) {
        // 0x8001C018: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8001C078;
    }
    // 0x8001C018: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001C01C: lw          $v0, 0x3C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X3C);
    // 0x8001C020: nop

    // 0x8001C024: lbu         $v1, 0x9($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X9);
    // 0x8001C028: nop

    // 0x8001C02C: andi        $t7, $v1, 0x80
    ctx->r15 = ctx->r3 & 0X80;
    // 0x8001C030: bne         $t7, $zero, L_8001C074
    if (ctx->r15 != 0) {
        // 0x8001C034: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_8001C074;
    }
    // 0x8001C034: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8001C038: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8001C03C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001C040: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8001C044: sw          $s3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r19;
    // 0x8001C048: lh          $t5, 0x186($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X186);
    // 0x8001C04C: lbu         $t4, 0x9($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X9);
    // 0x8001C050: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8001C054: sb          $t4, 0xE4($t6)
    MEM_B(0XE4, ctx->r14) = ctx->r12;
    // 0x8001C058: lb          $t7, 0xE($v0)
    ctx->r15 = MEM_B(ctx->r2, 0XE);
    // 0x8001C05C: addu        $t9, $s7, $t5
    ctx->r25 = ADD32(ctx->r23, ctx->r13);
    // 0x8001C060: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x8001C064: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8001C068: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x8001C06C: lw          $a0, -0x4C24($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C24);
    // 0x8001C070: sh          $t3, 0x186($sp)
    MEM_H(0X186, ctx->r29) = ctx->r11;
L_8001C074:
    // 0x8001C074: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
L_8001C078:
    // 0x8001C078: bne         $at, $zero, L_8001BFE4
    if (ctx->r1 != 0) {
        // 0x8001C07C: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_8001BFE4;
    }
    // 0x8001C07C: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
L_8001C080:
    // 0x8001C080: lh          $t4, 0x186($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X186);
    // 0x8001C084: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x8001C088: beq         $t4, $zero, L_8001C41C
    if (ctx->r12 == 0) {
        // 0x8001C08C: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_8001C41C;
    }
    // 0x8001C08C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8001C090: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8001C094: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
L_8001C098:
    // 0x8001C098: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8001C09C: nop

    // 0x8001C0A0: addu        $t7, $t6, $fp
    ctx->r15 = ADD32(ctx->r14, ctx->r30);
    // 0x8001C0A4: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x8001C0A8: nop

    // 0x8001C0AC: beq         $s3, $zero, L_8001C174
    if (ctx->r19 == 0) {
        // 0x8001C0B0: nop
    
            goto L_8001C174;
    }
    // 0x8001C0B0: nop

    // 0x8001C0B4: lw          $s4, 0x64($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X64);
    // 0x8001C0B8: lw          $s0, 0x3C($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X3C);
    // 0x8001C0BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001C0C0:
    // 0x8001C0C0: lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA);
    // 0x8001C0C4: nop

    // 0x8001C0C8: andi        $t8, $v1, 0x80
    ctx->r24 = ctx->r3 & 0X80;
    // 0x8001C0CC: bne         $t8, $zero, L_8001C168
    if (ctx->r24 != 0) {
        // 0x8001C0D0: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_8001C168;
    }
    // 0x8001C0D0: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8001C0D4: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8001C0D8: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8001C0DC: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x8001C0E0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8001C0E4: addu        $t6, $s4, $t4
    ctx->r14 = ADD32(ctx->r20, ctx->r12);
    // 0x8001C0E8: bne         $v0, $zero, L_8001C0F8
    if (ctx->r2 != 0) {
        // 0x8001C0EC: sw          $v0, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->r2;
            goto L_8001C0F8;
    }
    // 0x8001C0EC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8001C0F0: b           L_8001C168
    // 0x8001C0F4: sb          $s5, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r21;
        goto L_8001C168;
    // 0x8001C0F4: sb          $s5, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r21;
L_8001C0F8:
    // 0x8001C0F8: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8001C0FC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C100: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001C104: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001C108: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C10C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001C110: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001C114: lwc1        $f16, 0x14($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001C118: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C11C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001C120: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8001C124: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x8001C128: addu        $s2, $s4, $t7
    ctx->r18 = ADD32(ctx->r20, ctx->r15);
    // 0x8001C12C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001C130: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001C134: jal         0x800CA030
    // 0x8001C138: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C138: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8001C13C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001C140: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001C144: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001C148: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001C14C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001C150: addiu       $t2, $t2, -0x4B7C
    ctx->r10 = ADD32(ctx->r10, -0X4B7C);
    // 0x8001C154: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8001C158: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8001C15C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001C160: sh          $t9, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r25;
    // 0x8001C164: nop

L_8001C168:
    // 0x8001C168: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001C16C: bne         $s1, $s6, L_8001C0C0
    if (ctx->r17 != ctx->r22) {
        // 0x8001C170: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001C0C0;
    }
    // 0x8001C170: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001C174:
    // 0x8001C174: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x8001C178: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8001C17C: bne         $fp, $at, L_8001C098
    if (ctx->r30 != ctx->r1) {
        // 0x8001C180: nop
    
            goto L_8001C098;
    }
    // 0x8001C180: nop

    // 0x8001C184: lh          $t1, 0x186($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X186);
    // 0x8001C188: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001C18C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_8001C190:
    // 0x8001C190: blez        $t1, L_8001C2E0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C194: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8001C2E0;
    }
    // 0x8001C194: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8001C198: lh          $v0, 0x186($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X186);
    // 0x8001C19C: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8001C1A0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001C1A4: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8001C1A8: beq         $t5, $zero, L_8001C210
    if (ctx->r13 == 0) {
        // 0x8001C1AC: addiu       $t7, $sp, 0xE4
        ctx->r15 = ADD32(ctx->r29, 0XE4);
            goto L_8001C210;
    }
    // 0x8001C1AC: addiu       $t7, $sp, 0xE4
    ctx->r15 = ADD32(ctx->r29, 0XE4);
    // 0x8001C1B0: lb          $t3, 0xE5($sp)
    ctx->r11 = MEM_B(ctx->r29, 0XE5);
    // 0x8001C1B4: lb          $t8, 0xE4($sp)
    ctx->r24 = MEM_B(ctx->r29, 0XE4);
    // 0x8001C1B8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001C1BC: addu        $t6, $t0, $t4
    ctx->r14 = ADD32(ctx->r8, ctx->r12);
    // 0x8001C1C0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001C1C4: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x8001C1C8: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8001C1CC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001C1D0: lwc1        $f2, 0x10($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8001C1D4: lwc1        $f0, 0x10($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8001C1D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001C1DC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001C1E0: nop

    // 0x8001C1E4: bc1f        L_8001C208
    if (!c1cs) {
        // 0x8001C1E8: nop
    
            goto L_8001C208;
    }
    // 0x8001C1E8: nop

    // 0x8001C1EC: lb          $v0, 0x64($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X64);
    // 0x8001C1F0: lb          $t6, 0x65($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X65);
    // 0x8001C1F4: sb          $t3, 0xE4($sp)
    MEM_B(0XE4, ctx->r29) = ctx->r11;
    // 0x8001C1F8: sb          $t8, 0xE5($sp)
    MEM_B(0XE5, ctx->r29) = ctx->r24;
    // 0x8001C1FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C200: sb          $v0, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r2;
    // 0x8001C204: sb          $t6, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r14;
L_8001C208:
    // 0x8001C208: beq         $a3, $t1, L_8001C2DC
    if (ctx->r7 == ctx->r9) {
        // 0x8001C20C: addiu       $t7, $sp, 0xE4
        ctx->r15 = ADD32(ctx->r29, 0XE4);
            goto L_8001C2DC;
    }
    // 0x8001C20C: addiu       $t7, $sp, 0xE4
    ctx->r15 = ADD32(ctx->r29, 0XE4);
L_8001C210:
    // 0x8001C210: addu        $a0, $a3, $t7
    ctx->r4 = ADD32(ctx->r7, ctx->r15);
L_8001C214:
    // 0x8001C214: lb          $a1, 0x1($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X1);
    // 0x8001C218: lb          $a2, 0x0($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X0);
    // 0x8001C21C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8001C220: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8001C224: addu        $t3, $t0, $t8
    ctx->r11 = ADD32(ctx->r8, ctx->r24);
    // 0x8001C228: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x8001C22C: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8001C230: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8001C234: lwc1        $f0, 0x10($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8001C238: lwc1        $f18, 0x10($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8001C23C: addu        $v1, $s7, $a3
    ctx->r3 = ADD32(ctx->r23, ctx->r7);
    // 0x8001C240: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8001C244: nop

    // 0x8001C248: bc1f        L_8001C284
    if (!c1cs) {
        // 0x8001C24C: nop
    
            goto L_8001C284;
    }
    // 0x8001C24C: nop

    // 0x8001C250: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x8001C254: sb          $a2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r6;
    // 0x8001C258: lb          $a1, 0x1($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X1);
    // 0x8001C25C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8001C260: lb          $t9, 0x1($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X1);
    // 0x8001C264: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x8001C268: addu        $t4, $t0, $t5
    ctx->r12 = ADD32(ctx->r8, ctx->r13);
    // 0x8001C26C: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8001C270: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x8001C274: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8001C278: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C27C: lwc1        $f0, 0x10($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8001C280: nop

L_8001C284:
    // 0x8001C284: lb          $a2, 0x2($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X2);
    // 0x8001C288: addu        $v1, $s7, $a3
    ctx->r3 = ADD32(ctx->r23, ctx->r7);
    // 0x8001C28C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x8001C290: addu        $t6, $t0, $t3
    ctx->r14 = ADD32(ctx->r8, ctx->r11);
    // 0x8001C294: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001C298: nop

    // 0x8001C29C: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8001C2A0: nop

    // 0x8001C2A4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8001C2A8: nop

    // 0x8001C2AC: bc1f        L_8001C2D0
    if (!c1cs) {
        // 0x8001C2B0: nop
    
            goto L_8001C2D0;
    }
    // 0x8001C2B0: nop

    // 0x8001C2B4: lb          $v0, 0x1($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1);
    // 0x8001C2B8: lb          $t5, 0x2($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X2);
    // 0x8001C2BC: sb          $a2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r6;
    // 0x8001C2C0: sb          $a1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r5;
    // 0x8001C2C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C2C8: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x8001C2CC: sb          $t5, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r13;
L_8001C2D0:
    // 0x8001C2D0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8001C2D4: bne         $a3, $t1, L_8001C214
    if (ctx->r7 != ctx->r9) {
        // 0x8001C2D8: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_8001C214;
    }
    // 0x8001C2D8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_8001C2DC:
    // 0x8001C2DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8001C2E0:
    // 0x8001C2E0: beq         $s1, $zero, L_8001C190
    if (ctx->r17 == 0) {
        // 0x8001C2E4: nop
    
            goto L_8001C190;
    }
    // 0x8001C2E4: nop

    // 0x8001C2E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C2EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001C2F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001C2F4: lwc1        $f0, 0x5BC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5BC8);
    // 0x8001C2F8: addiu       $v1, $v1, -0x4B54
    ctx->r3 = ADD32(ctx->r3, -0X4B54);
    // 0x8001C2FC: addiu       $v0, $v0, -0x4B68
    ctx->r2 = ADD32(ctx->r2, -0X4B68);
L_8001C300:
    // 0x8001C300: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001C304: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8001C308: bne         $at, $zero, L_8001C300
    if (ctx->r1 != 0) {
        // 0x8001C30C: swc1        $f0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
            goto L_8001C300;
    }
    // 0x8001C30C: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8001C310: lb          $v0, 0x64($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X64);
    // 0x8001C314: blez        $t1, L_8001C3F8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C318: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001C3F8;
    }
    // 0x8001C318: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001C31C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8001C320: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001C324: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8001C328: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C32C: addiu       $a2, $a2, -0x4B68
    ctx->r6 = ADD32(ctx->r6, -0X4B68);
    // 0x8001C330: addiu       $t4, $sp, 0x64
    ctx->r12 = ADD32(ctx->r29, 0X64);
L_8001C334:
    // 0x8001C334: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C338: beq         $at, $zero, L_8001C378
    if (ctx->r1 == 0) {
        // 0x8001C33C: addu        $v1, $a3, $t4
        ctx->r3 = ADD32(ctx->r7, ctx->r12);
            goto L_8001C378;
    }
    // 0x8001C33C: addu        $v1, $a3, $t4
    ctx->r3 = ADD32(ctx->r7, ctx->r12);
    // 0x8001C340: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x8001C344: nop

    // 0x8001C348: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001C34C: bne         $at, $zero, L_8001C378
    if (ctx->r1 != 0) {
        // 0x8001C350: nop
    
            goto L_8001C378;
    }
    // 0x8001C350: nop

L_8001C354:
    // 0x8001C354: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001C358: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C35C: beq         $at, $zero, L_8001C378
    if (ctx->r1 == 0) {
        // 0x8001C360: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001C378;
    }
    // 0x8001C360: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001C364: lb          $t3, 0x0($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X0);
    // 0x8001C368: nop

    // 0x8001C36C: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001C370: beq         $at, $zero, L_8001C354
    if (ctx->r1 == 0) {
        // 0x8001C374: nop
    
            goto L_8001C354;
    }
    // 0x8001C374: nop

L_8001C378:
    // 0x8001C378: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x8001C37C: addiu       $t7, $sp, 0xE4
    ctx->r15 = ADD32(ctx->r29, 0XE4);
    // 0x8001C380: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001C384: beq         $at, $zero, L_8001C3E4
    if (ctx->r1 == 0) {
        // 0x8001C388: addu        $a0, $a3, $t7
        ctx->r4 = ADD32(ctx->r7, ctx->r15);
            goto L_8001C3E4;
    }
    // 0x8001C388: addu        $a0, $a3, $t7
    ctx->r4 = ADD32(ctx->r7, ctx->r15);
    // 0x8001C38C: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x8001C390: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8001C394: lb          $t9, -0x1($a0)
    ctx->r25 = MEM_B(ctx->r4, -0X1);
    // 0x8001C398: lb          $t3, 0x0($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X0);
    // 0x8001C39C: sra         $t6, $v0, 24
    ctx->r14 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8001C3A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8001C3A4: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8001C3A8: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8001C3AC: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8001C3B0: addu        $t4, $t0, $t5
    ctx->r12 = ADD32(ctx->r8, ctx->r13);
    // 0x8001C3B4: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8001C3B8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001C3BC: lwc1        $f6, 0x10($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8001C3C0: lwc1        $f8, 0x10($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8001C3C4: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8001C3C8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001C3CC: addu        $t4, $a2, $t5
    ctx->r12 = ADD32(ctx->r6, ctx->r13);
    // 0x8001C3D0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8001C3D4: mul.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x8001C3D8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8001C3DC: b           L_8001C3EC
    // 0x8001C3E0: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
        goto L_8001C3EC;
    // 0x8001C3E0: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
L_8001C3E4:
    // 0x8001C3E4: lh          $a3, 0x186($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X186);
    // 0x8001C3E8: nop

L_8001C3EC:
    // 0x8001C3EC: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C3F0: bne         $at, $zero, L_8001C334
    if (ctx->r1 != 0) {
        // 0x8001C3F4: addiu       $t4, $sp, 0x64
        ctx->r12 = ADD32(ctx->r29, 0X64);
            goto L_8001C334;
    }
    // 0x8001C3F4: addiu       $t4, $sp, 0x64
    ctx->r12 = ADD32(ctx->r29, 0X64);
L_8001C3F8:
    // 0x8001C3F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C3FC: lwc1        $f6, 0x5BCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5BCC);
    // 0x8001C400: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001C404: addiu       $a2, $a2, -0x4B68
    ctx->r6 = ADD32(ctx->r6, -0X4B68);
    // 0x8001C408: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8001C40C: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001C410: nop

    // 0x8001C414: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001C418: swc1        $f10, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f10.u32l;
L_8001C41C:
    // 0x8001C41C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001C420: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C424: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C428: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001C42C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001C430: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001C434: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C438: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001C43C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001C440: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001C444: jr          $ra
    // 0x8001C448: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    return;
    // 0x8001C448: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
;}
RECOMP_FUNC void alAuxBusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065C14: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80065C18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80065C1C: beq         $a1, $at, L_80065C38
    if (ctx->r5 == ctx->r1) {
        // 0x80065C20: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80065C38;
    }
    // 0x80065C20: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80065C24: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80065C28: beq         $a1, $at, L_80065C60
    if (ctx->r5 == ctx->r1) {
        // 0x80065C2C: nop
    
            goto L_80065C60;
    }
    // 0x80065C2C: nop

    // 0x80065C30: jr          $ra
    // 0x80065C34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80065C34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065C38:
    // 0x80065C38: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80065C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80065C40: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80065C44: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80065C48: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x80065C4C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x80065C50: nop

    // 0x80065C54: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80065C58: jr          $ra
    // 0x80065C5C: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    return;
    // 0x80065C5C: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_80065C60:
    // 0x80065C60: lw          $t1, 0x14($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14);
    // 0x80065C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065C68: blez        $t1, L_80065CB8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80065C6C: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80065CB8;
    }
    // 0x80065C6C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_80065C70:
    // 0x80065C70: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80065C74: nop

    // 0x80065C78: bne         $a2, $t2, L_80065CA4
    if (ctx->r6 != ctx->r10) {
        // 0x80065C7C: nop
    
            goto L_80065CA4;
    }
    // 0x80065C7C: nop

    // 0x80065C80: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80065C84: nop

    // 0x80065C88: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80065C8C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80065C90: sw          $t4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r12;
    // 0x80065C94: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80065C98: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80065C9C: nop

    // 0x80065CA0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_80065CA4:
    // 0x80065CA4: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x80065CA8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80065CAC: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80065CB0: bne         $at, $zero, L_80065C70
    if (ctx->r1 != 0) {
        // 0x80065CB4: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80065C70;
    }
    // 0x80065CB4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80065CB8:
    // 0x80065CB8: jr          $ra
    // 0x80065CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80065CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void reset_delayed_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C36A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C36A8: jr          $ra
    // 0x800C36AC: sw          $zero, 0x3C08($at)
    MEM_W(0X3C08, ctx->r1) = 0;
    return;
    // 0x800C36AC: sw          $zero, 0x3C08($at)
    MEM_W(0X3C08, ctx->r1) = 0;
;}
RECOMP_FUNC void drm_validate_imem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F72C: lui         $t6, 0xA400
    ctx->r14 = S32(0XA400 << 16);
    // 0x8006F730: lw          $t7, 0x1000($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1000);
    // 0x8006F734: addiu       $at, $zero, 0x17D7
    ctx->r1 = ADD32(0, 0X17D7);
    // 0x8006F738: beq         $t7, $at, L_8006F748
    if (ctx->r15 == ctx->r1) {
        // 0x8006F73C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006F748;
    }
    // 0x8006F73C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F740: jr          $ra
    // 0x8006F744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006F744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006F748:
    // 0x8006F748: jr          $ra
    // 0x8006F74C: nop

    return;
    // 0x8006F74C: nop

;}
RECOMP_FUNC void amCreateAudioMgr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002660: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80002664: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002668: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000266C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80002670: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80002674: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80002678: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000267C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80002680: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80002684: sw          $a2, 0x6510($at)
    MEM_W(0X6510, ctx->r1) = ctx->r6;
    // 0x80002688: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8000268C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002690: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80002694: addiu       $t7, $t7, 0x3008
    ctx->r15 = ADD32(ctx->r15, 0X3008);
    // 0x80002698: sw          $t6, 0x6514($at)
    MEM_W(0X6514, ctx->r1) = ctx->r14;
    // 0x8000269C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800026A0: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x800026A4: jal         0x800C8B60
    // 0x800026A8: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_0;
    // 0x800026A8: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    after_0:
    // 0x800026AC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800026B0: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
    // 0x800026B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800026B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800026BC: lw          $t8, 0x6710($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6710);
    // 0x800026C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800026C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800026C8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800026CC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800026D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800026D4: addiu       $a0, $a0, -0x6454
    ctx->r4 = ADD32(ctx->r4, -0X6454);
    // 0x800026D8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800026DC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800026E0: addiu       $s4, $s4, -0x6450
    ctx->r20 = ADD32(ctx->r20, -0X6450);
    // 0x800026E4: div.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800026E8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800026EC: nop

    // 0x800026F0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800026F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800026F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800026FC: nop

    // 0x80002700: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80002704: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80002708: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000270C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80002710: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80002714: bgez        $v1, L_8000272C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80002718: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000272C;
    }
    // 0x80002718: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000271C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80002720: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80002724: nop

    // 0x80002728: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_8000272C:
    // 0x8000272C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80002730: nop

    // 0x80002734: bc1f        L_80002744
    if (!c1cs) {
        // 0x80002738: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_80002744;
    }
    // 0x80002738: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8000273C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80002740: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_80002744:
    // 0x80002744: andi        $t3, $v1, 0xF
    ctx->r11 = ctx->r3 & 0XF;
    // 0x80002748: beq         $t3, $zero, L_8000275C
    if (ctx->r11 == 0) {
        // 0x8000274C: addiu       $at, $zero, -0x10
        ctx->r1 = ADD32(0, -0X10);
            goto L_8000275C;
    }
    // 0x8000274C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80002750: and         $t4, $v1, $at
    ctx->r12 = ctx->r3 & ctx->r1;
    // 0x80002754: addiu       $v1, $t4, 0x10
    ctx->r3 = ADD32(ctx->r12, 0X10);
    // 0x80002758: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_8000275C:
    // 0x8000275C: addiu       $t6, $v1, -0x10
    ctx->r14 = ADD32(ctx->r3, -0X10);
    // 0x80002760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80002764: sw          $t6, -0x6458($at)
    MEM_W(-0X6458, ctx->r1) = ctx->r14;
    // 0x80002768: addiu       $t7, $v1, 0x70
    ctx->r15 = ADD32(ctx->r3, 0X70);
    // 0x8000276C: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x80002770: lbu         $t8, 0x1C($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X1C);
    // 0x80002774: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80002778: bne         $t8, $at, L_800027E8
    if (ctx->r24 != ctx->r1) {
        // 0x8000277C: nop
    
            goto L_800027E8;
    }
    // 0x8000277C: nop

    // 0x80002780: jal         0x80076EE4
    // 0x80002784: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x80002784: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80002788: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x8000278C: lw          $t1, 0x20($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X20);
    // 0x80002790: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80002794: subu        $s0, $t9, $t1
    ctx->r16 = SUB32(ctx->r25, ctx->r9);
    // 0x80002798: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000279C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800027A0: jal         0x80070EDC
    // 0x800027A4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800027A4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_2:
    // 0x800027A8: lw          $a2, 0x20($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X20);
    // 0x800027AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800027B0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800027B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800027B8: jal         0x80077190
    // 0x800027BC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_3;
    // 0x800027BC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x800027C0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800027C4: sw          $s1, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r17;
    // 0x800027C8: sw          $zero, 0x24($s3)
    MEM_W(0X24, ctx->r19) = 0;
    // 0x800027CC: addiu       $a0, $a0, 0x6750
    ctx->r4 = ADD32(ctx->r4, 0X6750);
    // 0x800027D0: jal         0x800C8D4C
    // 0x800027D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alInit(rdram, ctx);
        goto after_4;
    // 0x800027D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x800027D8: jal         0x80071380
    // 0x800027DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800027DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800027E0: b           L_800027F8
    // 0x800027E4: nop

        goto L_800027F8;
    // 0x800027E4: nop

L_800027E8:
    // 0x800027E8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800027EC: addiu       $a0, $a0, 0x6750
    ctx->r4 = ADD32(ctx->r4, 0X6750);
    // 0x800027F0: jal         0x800C8D4C
    // 0x800027F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alInit(rdram, ctx);
        goto after_6;
    // 0x800027F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
L_800027F8:
    // 0x800027F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800027FC: addiu       $v0, $v0, -0x6840
    ctx->r2 = ADD32(ctx->r2, -0X6840);
    // 0x80002800: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80002804: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80002808: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000280C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80002810: addiu       $s0, $s0, -0x682C
    ctx->r16 = ADD32(ctx->r16, -0X682C);
    // 0x80002814: addiu       $s2, $s2, -0x6840
    ctx->r18 = ADD32(ctx->r18, -0X6840);
    // 0x80002818: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000281C:
    // 0x8000281C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80002820: jal         0x800C8CF0
    // 0x80002824: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_7;
    // 0x80002824: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80002828: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8000282C: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x80002830: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80002834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80002838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000283C: jal         0x800C7D50
    // 0x80002840: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_8;
    // 0x80002840: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80002844: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80002848: slti        $at, $s1, 0x31
    ctx->r1 = SIGNED(ctx->r17) < 0X31 ? 1 : 0;
    // 0x8000284C: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x80002850: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80002854: bne         $at, $zero, L_8000281C
    if (ctx->r1 != 0) {
        // 0x80002858: sw          $v0, -0x4($s2)
        MEM_W(-0X4, ctx->r18) = ctx->r2;
            goto L_8000281C;
    }
    // 0x80002858: sw          $v0, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r2;
    // 0x8000285C: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80002860: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x80002864: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80002868: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000286C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002870: jal         0x800C7D50
    // 0x80002874: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_9;
    // 0x80002874: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x80002878: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000287C: addiu       $a0, $a0, -0x6448
    ctx->r4 = ADD32(ctx->r4, -0X6448);
    // 0x80002880: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x80002884: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80002888: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x8000288C: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
    // 0x80002890: addiu       $t0, $t0, -0x3404
    ctx->r8 = ADD32(ctx->r8, -0X3404);
    // 0x80002894: lui         $t5, 0x8002
    ctx->r13 = S32(0X8002 << 16);
    // 0x80002898: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x8000289C: addiu       $t5, $t5, -0x67C4
    ctx->r13 = ADD32(ctx->r13, -0X67C4);
    // 0x800028A0: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x800028A4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800028A8: lw          $a1, -0x33FC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X33FC);
    // 0x800028AC: subu        $v1, $t5, $a2
    ctx->r3 = SUB32(ctx->r13, ctx->r6);
    // 0x800028B0: addu        $a3, $a2, $v1
    ctx->r7 = ADD32(ctx->r6, ctx->r3);
    // 0x800028B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800028B8: blez        $a1, L_800028E8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800028BC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800028E8;
    }
    // 0x800028BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800028C0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800028C4:
    // 0x800028C4: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800028C8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800028CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800028D0: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800028D4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800028D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800028DC: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x800028E0: bne         $at, $zero, L_800028C4
    if (ctx->r1 != 0) {
        // 0x800028E4: addu        $v1, $v1, $t6
        ctx->r3 = ADD32(ctx->r3, ctx->r14);
            goto L_800028C4;
    }
    // 0x800028E4: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
L_800028E8:
    // 0x800028E8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800028EC: lw          $t9, -0x3400($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3400);
    // 0x800028F0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800028F4: beq         $v1, $t9, L_80002904
    if (ctx->r3 == ctx->r25) {
        // 0x800028F8: addiu       $s0, $s0, 0x6518
        ctx->r16 = ADD32(ctx->r16, 0X6518);
            goto L_80002904;
    }
    // 0x800028F8: addiu       $s0, $s0, 0x6518
    ctx->r16 = ADD32(ctx->r16, 0X6518);
    // 0x800028FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80002900: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
L_80002904:
    // 0x80002904: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80002908: addiu       $s1, $s1, 0x6520
    ctx->r17 = ADD32(ctx->r17, 0X6520);
L_8000290C:
    // 0x8000290C: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80002910: ori         $t2, $zero, 0xA000
    ctx->r10 = 0 | 0XA000;
    // 0x80002914: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80002918: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000291C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002920: jal         0x800C7D50
    // 0x80002924: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_10;
    // 0x80002924: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80002928: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000292C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80002930: bne         $at, $zero, L_8000290C
    if (ctx->r1 != 0) {
        // 0x80002934: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_8000290C;
    }
    // 0x80002934: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80002938: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8000293C: lui         $t4, 0x803F
    ctx->r12 = S32(0X803F << 16);
    // 0x80002940: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80002944: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x80002948: sll         $a0, $t3, 2
    ctx->r4 = S32(ctx->r11 << 2);
    // 0x8000294C: ori         $t4, $t4, 0xFE00
    ctx->r12 = ctx->r12 | 0XFE00;
    // 0x80002950: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // 0x80002954: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80002958: subu        $a1, $t4, $a0
    ctx->r5 = SUB32(ctx->r12, ctx->r4);
    // 0x8000295C: jal         0x80071138
    // 0x80002960: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    mempool_alloc_fixed(rdram, ctx);
        goto after_11;
    // 0x80002960: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    after_11:
    // 0x80002964: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80002968: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x8000296C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80002970: addiu       $s1, $s1, 0x6524
    ctx->r17 = ADD32(ctx->r17, 0X6524);
    // 0x80002974: addiu       $s0, $s0, 0x6518
    ctx->r16 = ADD32(ctx->r16, 0X6518);
L_80002978:
    // 0x80002978: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8000297C: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x80002980: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80002984: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80002988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000298C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002990: jal         0x800C7D50
    // 0x80002994: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_12;
    // 0x80002994: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x80002998: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8000299C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800029A0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800029A4: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800029A8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800029AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800029B0: bne         $s0, $s1, L_80002978
    if (ctx->r16 != ctx->r17) {
        // 0x800029B4: addu        $v1, $v1, $t7
        ctx->r3 = ADD32(ctx->r3, ctx->r15);
            goto L_80002978;
    }
    // 0x800029B4: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800029B8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800029BC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800029C0: addiu       $a1, $a1, 0x6730
    ctx->r5 = ADD32(ctx->r5, 0X6730);
    // 0x800029C4: addiu       $a0, $a0, 0x6718
    ctx->r4 = ADD32(ctx->r4, 0X6718);
    // 0x800029C8: jal         0x800C8D80
    // 0x800029CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_13;
    // 0x800029CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_13:
    // 0x800029D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800029D4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800029D8: addiu       $a1, $a1, 0x66F8
    ctx->r5 = ADD32(ctx->r5, 0X66F8);
    // 0x800029DC: addiu       $a0, $a0, 0x66E0
    ctx->r4 = ADD32(ctx->r4, 0X66E0);
    // 0x800029E0: jal         0x800C8D80
    // 0x800029E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_14;
    // 0x800029E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_14:
    // 0x800029E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800029EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800029F0: addiu       $a1, $a1, -0x5F78
    ctx->r5 = ADD32(ctx->r5, -0X5F78);
    // 0x800029F4: addiu       $a0, $a0, -0x5F90
    ctx->r4 = ADD32(ctx->r4, -0X5F90);
    // 0x800029F8: jal         0x800C8D80
    // 0x800029FC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_15;
    // 0x800029FC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_15:
    // 0x80002A00: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80002A04: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80002A08: addiu       $t8, $t8, -0x6850
    ctx->r24 = ADD32(ctx->r24, -0X6850);
    // 0x80002A0C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002A10: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80002A14: addiu       $a2, $a2, 0x2A98
    ctx->r6 = ADD32(ctx->r6, 0X2A98);
    // 0x80002A18: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    // 0x80002A1C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80002A20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80002A24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80002A28: jal         0x800C8DB0
    // 0x80002A2C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    osCreateThread_recomp(rdram, ctx);
        goto after_16;
    // 0x80002A2C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_16:
    // 0x80002A30: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80002A34: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80002A38: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80002A3C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80002A40: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80002A44: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80002A48: jr          $ra
    // 0x80002A4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80002A4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void check_for_rumble_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075F38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80075F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075F40: jal         0x80075B34
    // 0x80075F44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075F44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80075F48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80075F4C: jal         0x80075D44
    // 0x80075F50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80075F50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80075F54: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80075F58: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80075F5C: bne         $v1, $at, L_80075F80
    if (ctx->r3 != ctx->r1) {
        // 0x80075F60: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80075F80;
    }
    // 0x80075F60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80075F64: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80075F68: addiu       $v0, $v0, 0x4765
    ctx->r2 = ADD32(ctx->r2, 0X4765);
    // 0x80075F6C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80075F70: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075F74: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x80075F78: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x80075F7C: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_80075F80:
    // 0x80075F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075F84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80075F88: jr          $ra
    // 0x80075F8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80075F8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mode_init_taj_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002297C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80022980: addiu       $v0, $v0, -0x4B89
    ctx->r2 = ADD32(ctx->r2, -0X4B89);
    // 0x80022984: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80022988: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8002298C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80022990: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80022994: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x80022998: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002299C: bne         $t8, $zero, L_80022D20
    if (ctx->r24 != 0) {
        // 0x800229A0: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80022D20;
    }
    // 0x800229A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800229A4: jal         0x8006BFF0
    // 0x800229A8: nop

    level_header(rdram, ctx);
        goto after_0;
    // 0x800229A8: nop

    after_0:
    // 0x800229AC: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800229B0: lbu         $t9, 0x52($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X52);
    // 0x800229B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800229B8: sb          $t9, -0x4B88($at)
    MEM_B(-0X4B88, ctx->r1) = ctx->r25;
    // 0x800229BC: lhu         $t1, 0x54($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X54);
    // 0x800229C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800229C4: addiu       $t2, $zero, 0x1D
    ctx->r10 = ADD32(0, 0X1D);
    // 0x800229C8: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x800229CC: sw          $t1, -0x4B84($at)
    MEM_W(-0X4B84, ctx->r1) = ctx->r9;
    // 0x800229D0: sb          $t2, 0x52($v0)
    MEM_B(0X52, ctx->r2) = ctx->r10;
    // 0x800229D4: sh          $t3, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r11;
    // 0x800229D8: jal         0x8001BAFC
    // 0x800229DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_1;
    // 0x800229DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800229E0: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x800229E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800229E8: lb          $t4, 0x1D6($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D6);
    // 0x800229EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800229F0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800229F4: sb          $t5, -0x4B8A($at)
    MEM_B(-0X4B8A, ctx->r1) = ctx->r13;
    // 0x800229F8: jal         0x80023104
    // 0x800229FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800230D0(rdram, ctx);
        goto after_2;
    // 0x800229FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80022A00: lh          $t6, 0x1A0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A0);
    // 0x80022A04: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80022A08: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80022A0C: sh          $t8, 0x196($s0)
    MEM_H(0X196, ctx->r16) = ctx->r24;
    // 0x80022A10: sb          $zero, 0x1FC($s0)
    MEM_B(0X1FC, ctx->r16) = 0;
    // 0x80022A14: sb          $zero, 0x1F4($s0)
    MEM_B(0X1F4, ctx->r16) = 0;
    // 0x80022A18: sh          $zero, 0x190($s0)
    MEM_H(0X190, ctx->r16) = 0;
    // 0x80022A1C: sb          $zero, 0x192($s0)
    MEM_B(0X192, ctx->r16) = 0;
    // 0x80022A20: sb          $zero, 0x193($s0)
    MEM_B(0X193, ctx->r16) = 0;
    // 0x80022A24: sb          $zero, 0x194($s0)
    MEM_B(0X194, ctx->r16) = 0;
    // 0x80022A28: sw          $zero, 0x128($s0)
    MEM_W(0X128, ctx->r16) = 0;
    // 0x80022A2C: sw          $zero, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = 0;
    // 0x80022A30: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80022A34: sh          $zero, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = 0;
    // 0x80022A38: jal         0x8006ECD0
    // 0x80022A3C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_3;
    // 0x80022A3C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80022A40: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80022A44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022A48: sw          $t9, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = ctx->r25;
    // 0x80022A4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022A50: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x80022A54: sw          $zero, -0x4CCC($at)
    MEM_W(-0X4CCC, ctx->r1) = 0;
    // 0x80022A58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022A5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80022A60: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80022A64: sw          $t1, -0x4CC0($at)
    MEM_W(-0X4CC0, ctx->r1) = ctx->r9;
    // 0x80022A68: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80022A6C: sb          $t2, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r10;
    // 0x80022A70: jal         0x8009F574
    // 0x80022A74: sb          $zero, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = 0;
    hud_init_element(rdram, ctx);
        goto after_4;
    // 0x80022A74: sb          $zero, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = 0;
    after_4:
    // 0x80022A78: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80022A7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022A80: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80022A84:
    // 0x80022A84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022A88: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80022A8C: sw          $zero, 0x128($v1)
    MEM_W(0X128, ctx->r3) = 0;
    // 0x80022A90: bne         $at, $zero, L_80022A84
    if (ctx->r1 != 0) {
        // 0x80022A94: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80022A84;
    }
    // 0x80022A94: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80022A98: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80022A9C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80022AA0: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80022AA4: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80022AA8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80022AAC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80022AB0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80022AB4: nop

    // 0x80022AB8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80022ABC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022AC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022AC4: nop

    // 0x80022AC8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80022ACC: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80022AD0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80022AD4: sh          $t4, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r12;
    // 0x80022AD8: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80022ADC: lwc1        $f18, 0x18($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80022AE0: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80022AE4: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80022AE8: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80022AEC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80022AF0: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80022AF4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80022AF8: nop

    // 0x80022AFC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80022B00: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022B04: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022B08: nop

    // 0x80022B0C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80022B10: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80022B14: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80022B18: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80022B1C: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80022B20: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80022B24: sh          $t7, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r15;
    // 0x80022B28: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80022B2C: lwc1        $f14, 0x14($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80022B30: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x80022B34: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80022B38: jal         0x80029F58
    // 0x80022B3C: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    get_level_segment_index_from_position(rdram, ctx);
        goto after_5;
    // 0x80022B3C: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_5:
    // 0x80022B40: lh          $t2, 0x5A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5A);
    // 0x80022B44: lh          $t3, 0x5E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X5E);
    // 0x80022B48: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80022B4C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80022B50: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80022B54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80022B58: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x80022B5C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80022B60: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80022B64: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80022B68: jal         0x8002BAF0
    // 0x80022B6C: nop

    collision_get_y(rdram, ctx);
        goto after_6;
    // 0x80022B6C: nop

    after_6:
    // 0x80022B70: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80022B74: beq         $v0, $zero, L_80022BA8
    if (ctx->r2 == 0) {
        // 0x80022B78: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_80022BA8;
    }
    // 0x80022B78: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80022B7C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80022B80: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80022B84: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80022B88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022B8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022B90: nop

    // 0x80022B94: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80022B98: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80022B9C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80022BA0: b           L_80022BD4
    // 0x80022BA4: sh          $t4, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r12;
        goto L_80022BD4;
    // 0x80022BA4: sh          $t4, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r12;
L_80022BA8:
    // 0x80022BA8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80022BAC: lwc1        $f16, 0x14($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80022BB0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80022BB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022BB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022BBC: nop

    // 0x80022BC0: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80022BC4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80022BC8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80022BCC: sh          $t8, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r24;
    // 0x80022BD0: nop

L_80022BD4:
    // 0x80022BD4: sb          $t7, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r15;
    // 0x80022BD8: lh          $t9, 0x1A0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A0);
    // 0x80022BDC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80022BE0: addiu       $t2, $zero, 0xDA
    ctx->r10 = ADD32(0, 0XDA);
    // 0x80022BE4: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x80022BE8: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x80022BEC: sh          $t1, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r9;
    // 0x80022BF0: sb          $t2, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r10;
    // 0x80022BF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022BF8: jal         0x80061C34
    // 0x80022BFC: sh          $t9, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r25;
    model_anim_offset(rdram, ctx);
        goto after_7;
    // 0x80022BFC: sh          $t9, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r25;
    after_7:
    // 0x80022C00: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80022C04: jal         0x8000EA54
    // 0x80022C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_8;
    // 0x80022C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80022C0C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80022C10: lw          $t3, -0x4B9C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4B9C);
    // 0x80022C14: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80022C18: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x80022C1C: lw          $t5, -0x4B98($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4B98);
    // 0x80022C20: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80022C24: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x80022C28: lw          $t4, -0x4B94($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B94);
    // 0x80022C2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80022C30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80022C34: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80022C38: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80022C3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022C40: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80022C44: sw          $t6, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r14;
    // 0x80022C48: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x80022C4C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80022C50: sb          $t8, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r24;
    // 0x80022C54: lb          $t7, 0x1D6($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D6);
    // 0x80022C58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80022C5C: sb          $t9, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r25;
    // 0x80022C60: sb          $t7, 0x1D7($s0)
    MEM_B(0X1D7, ctx->r16) = ctx->r15;
    // 0x80022C64: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80022C68: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80022C6C: lb          $t2, 0x59($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X59);
    // 0x80022C70: swc1        $f0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f0.u32l;
    // 0x80022C74: swc1        $f0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f0.u32l;
    // 0x80022C78: sb          $t3, 0x1F7($s0)
    MEM_B(0X1F7, ctx->r16) = ctx->r11;
    // 0x80022C7C: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
    // 0x80022C80: sb          $t2, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r10;
    // 0x80022C84: lw          $t4, 0x4C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4C);
    // 0x80022C88: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80022C8C: sb          $t5, 0x12($t4)
    MEM_B(0X12, ctx->r12) = ctx->r13;
    // 0x80022C90: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80022C94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80022C98: lw          $a1, -0x4C24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4C24);
    // 0x80022C9C: lw          $a0, -0x4C20($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C20);
    // 0x80022CA0: addiu       $a3, $zero, 0x3E
    ctx->r7 = ADD32(0, 0X3E);
    // 0x80022CA4: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022CA8: beq         $at, $zero, L_80022D0C
    if (ctx->r1 == 0) {
        // 0x80022CAC: sll         $v1, $a0, 2
        ctx->r3 = S32(ctx->r4 << 2);
            goto L_80022D0C;
    }
    // 0x80022CAC: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80022CB0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80022CB4: addiu       $a2, $a2, -0x4C28
    ctx->r6 = ADD32(ctx->r6, -0X4C28);
L_80022CB8:
    // 0x80022CB8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80022CBC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80022CC0: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x80022CC4: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80022CC8: nop

    // 0x80022CCC: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x80022CD0: nop

    // 0x80022CD4: andi        $t9, $t7, 0x8000
    ctx->r25 = ctx->r15 & 0X8000;
    // 0x80022CD8: bne         $t9, $zero, L_80022D04
    if (ctx->r25 != 0) {
        // 0x80022CDC: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80022D04;
    }
    // 0x80022CDC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022CE0: lh          $t1, 0x48($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X48);
    // 0x80022CE4: nop

    // 0x80022CE8: bne         $a3, $t1, L_80022D04
    if (ctx->r7 != ctx->r9) {
        // 0x80022CEC: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80022D04;
    }
    // 0x80022CEC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022CF0: sw          $v0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r2;
    // 0x80022CF4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80022CF8: lw          $a1, -0x4C24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4C24);
    // 0x80022CFC: nop

    // 0x80022D00: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80022D04:
    // 0x80022D04: bne         $at, $zero, L_80022CB8
    if (ctx->r1 != 0) {
        // 0x80022D08: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80022CB8;
    }
    // 0x80022D08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80022D0C:
    // 0x80022D0C: jal         0x8006F5C8
    // 0x80022D10: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    set_pause_lockout_timer(rdram, ctx);
        goto after_9;
    // 0x80022D10: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_9:
    // 0x80022D14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80022D18: jal         0x800C06F8
    // 0x80022D1C: addiu       $a0, $a0, -0x33A0
    ctx->r4 = ADD32(ctx->r4, -0X33A0);
    transition_begin(rdram, ctx);
        goto after_10;
    // 0x80022D1C: addiu       $a0, $a0, -0x33A0
    ctx->r4 = ADD32(ctx->r4, -0X33A0);
    after_10:
L_80022D20:
    // 0x80022D20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022D24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022D28: jr          $ra
    // 0x80022D2C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80022D2C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void race_finish_adventure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A908: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x8001A90C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A910: sh          $t6, -0x4D32($at)
    MEM_H(-0X4D32, ctx->r1) = ctx->r14;
    // 0x8001A914: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A918: sb          $zero, -0x4D30($at)
    MEM_B(-0X4D30, ctx->r1) = 0;
    // 0x8001A91C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A920: jr          $ra
    // 0x8001A924: sb          $a0, -0x4D2E($at)
    MEM_B(-0X4D2E, ctx->r1) = ctx->r4;
    return;
    // 0x8001A924: sb          $a0, -0x4D2E($at)
    MEM_B(-0X4D2E, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void material_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D544: addiu       $sp, $sp, -0x280
    ctx->r29 = ADD32(ctx->r29, -0X280);
    // 0x8007D548: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007D54C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007D550: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007D554: sw          $a1, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r5;
    // 0x8007D558: lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2);
    // 0x8007D55C: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    // 0x8007D560: sra         $t7, $v1, 4
    ctx->r15 = S32(SIGNED(ctx->r3) >> 4);
    // 0x8007D564: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8007D568: sw          $t8, 0x278($sp)
    MEM_W(0X278, ctx->r29) = ctx->r24;
    // 0x8007D56C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007D570: lbu         $s0, 0x1($a0)
    ctx->r16 = MEM_BU(ctx->r4, 0X1);
    // 0x8007D574: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x8007D578: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8007D57C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007D580: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007D584: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007D588: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007D58C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007D590: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8007D594: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007D598: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
L_8007D59C:
    // 0x8007D59C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007D5A0: beq         $at, $zero, L_8007D5B0
    if (ctx->r1 == 0) {
        // 0x8007D5A4: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_8007D5B0;
    }
    // 0x8007D5A4: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8007D5A8: b           L_8007D5BC
    // 0x8007D5AC: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
        goto L_8007D5BC;
    // 0x8007D5AC: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
L_8007D5B0:
    // 0x8007D5B0: bne         $v0, $t5, L_8007D5C0
    if (ctx->r2 != ctx->r13) {
        // 0x8007D5B4: slt         $at, $v0, $s0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_8007D5C0;
    }
    // 0x8007D5B4: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8007D5B8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8007D5BC:
    // 0x8007D5BC: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
L_8007D5C0:
    // 0x8007D5C0: beq         $at, $zero, L_8007D5D0
    if (ctx->r1 == 0) {
        // 0x8007D5C4: addiu       $v1, $a2, 0x1
        ctx->r3 = ADD32(ctx->r6, 0X1);
            goto L_8007D5D0;
    }
    // 0x8007D5C4: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x8007D5C8: b           L_8007D5DC
    // 0x8007D5CC: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
        goto L_8007D5DC;
    // 0x8007D5CC: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
L_8007D5D0:
    // 0x8007D5D0: bne         $v0, $s0, L_8007D5E0
    if (ctx->r2 != ctx->r16) {
        // 0x8007D5D4: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8007D5E0;
    }
    // 0x8007D5D4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8007D5D8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8007D5DC:
    // 0x8007D5DC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8007D5E0:
    // 0x8007D5E0: bne         $v1, $a0, L_8007D59C
    if (ctx->r3 != ctx->r4) {
        // 0x8007D5E4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8007D59C;
    }
    // 0x8007D5E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007D5E8: bne         $t0, $zero, L_8007D604
    if (ctx->r8 != 0) {
        // 0x8007D5EC: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8007D604;
    }
    // 0x8007D5EC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8007D5F0: lh          $v0, 0x6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X6);
    // 0x8007D5F4: nop

    // 0x8007D5F8: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    // 0x8007D5FC: beq         $t8, $zero, L_8007D614
    if (ctx->r24 == 0) {
        // 0x8007D600: nop
    
            goto L_8007D614;
    }
    // 0x8007D600: nop

L_8007D604:
    // 0x8007D604: sw          $t9, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r25;
    // 0x8007D608: lh          $v0, 0x6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X6);
    // 0x8007D60C: b           L_8007D618
    // 0x8007D610: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
        goto L_8007D618;
    // 0x8007D610: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8007D614:
    // 0x8007D614: sw          $zero, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = 0;
L_8007D618:
    // 0x8007D618: bne         $t1, $zero, L_8007D628
    if (ctx->r9 != 0) {
        // 0x8007D61C: andi        $t8, $v0, 0x400
        ctx->r24 = ctx->r2 & 0X400;
            goto L_8007D628;
    }
    // 0x8007D61C: andi        $t8, $v0, 0x400
    ctx->r24 = ctx->r2 & 0X400;
    // 0x8007D620: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x8007D624: beq         $t6, $zero, L_8007D638
    if (ctx->r14 == 0) {
        // 0x8007D628: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_8007D638;
    }
L_8007D628:
    // 0x8007D628: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8007D62C: sw          $t7, 0x268($sp)
    MEM_W(0X268, ctx->r29) = ctx->r15;
    // 0x8007D630: b           L_8007D63C
    // 0x8007D634: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
        goto L_8007D63C;
    // 0x8007D634: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_8007D638:
    // 0x8007D638: sw          $zero, 0x268($sp)
    MEM_W(0X268, ctx->r29) = 0;
L_8007D63C:
    // 0x8007D63C: bne         $t8, $zero, L_8007E69C
    if (ctx->r24 != 0) {
        // 0x8007D640: nop
    
            goto L_8007E69C;
    }
    // 0x8007D640: nop

    // 0x8007D644: sw          $t2, 0x264($sp)
    MEM_W(0X264, ctx->r29) = ctx->r10;
    // 0x8007D648: sw          $t3, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r11;
    // 0x8007D64C: bne         $t4, $zero, L_8007D83C
    if (ctx->r12 != 0) {
        // 0x8007D650: sw          $t4, 0x27C($sp)
        MEM_W(0X27C, ctx->r29) = ctx->r12;
            goto L_8007D83C;
    }
    // 0x8007D650: sw          $t4, 0x27C($sp)
    MEM_W(0X27C, ctx->r29) = ctx->r12;
    // 0x8007D654: lw          $t2, 0x284($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X284);
    // 0x8007D658: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D65C: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007D660: addu        $t6, $s1, $at
    ctx->r14 = ADD32(ctx->r17, ctx->r1);
    // 0x8007D664: lui         $t9, 0xFD18
    ctx->r25 = S32(0XFD18 << 16);
    // 0x8007D668: addiu       $a3, $t2, 0x8
    ctx->r7 = ADD32(ctx->r10, 0X8);
    // 0x8007D66C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007D670: lui         $t7, 0xF518
    ctx->r15 = S32(0XF518 << 16);
    // 0x8007D674: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007D678: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8007D67C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D680: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8007D684: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007D688: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007D68C: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007D690: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8007D694: sll         $v0, $t8, 18
    ctx->r2 = S32(ctx->r24 << 18);
    // 0x8007D698: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007D69C: andi        $t8, $a1, 0x3
    ctx->r24 = ctx->r5 & 0X3;
    // 0x8007D6A0: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x8007D6A4: sll         $v1, $t6, 14
    ctx->r3 = S32(ctx->r14 << 14);
    // 0x8007D6A8: sll         $a1, $t8, 8
    ctx->r5 = S32(ctx->r24 << 8);
    // 0x8007D6AC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D6B0: or          $t8, $v0, $at
    ctx->r24 = ctx->r2 | ctx->r1;
    // 0x8007D6B4: andi        $t6, $a2, 0xF
    ctx->r14 = ctx->r6 & 0XF;
    // 0x8007D6B8: sll         $a2, $t6, 4
    ctx->r6 = S32(ctx->r14 << 4);
    // 0x8007D6BC: or          $t9, $t8, $v1
    ctx->r25 = ctx->r24 | ctx->r3;
    // 0x8007D6C0: or          $t6, $t9, $a1
    ctx->r14 = ctx->r25 | ctx->r5;
    // 0x8007D6C4: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007D6C8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D6CC: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007D6D0: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8007D6D4: mflo        $t0
    ctx->r8 = lo;
    // 0x8007D6D8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007D6DC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D6E0: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8007D6E4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007D6E8: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8007D6EC: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007D6F0: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007D6F4: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007D6F8: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8007D6FC: beq         $at, $zero, L_8007D70C
    if (ctx->r1 == 0) {
        // 0x8007D700: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007D70C;
    }
    // 0x8007D700: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D704: b           L_8007D710
    // 0x8007D708: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007D710;
    // 0x8007D708: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007D70C:
    // 0x8007D70C: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007D710:
    // 0x8007D710: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x8007D714: bgez        $t0, L_8007D724
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007D718: sra         $t6, $t0, 3
        ctx->r14 = S32(SIGNED(ctx->r8) >> 3);
            goto L_8007D724;
    }
    // 0x8007D718: sra         $t6, $t0, 3
    ctx->r14 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8007D71C: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x8007D720: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8007D724:
    // 0x8007D724: bgtz        $t6, L_8007D734
    if (SIGNED(ctx->r14) > 0) {
        // 0x8007D728: or          $t0, $t6, $zero
        ctx->r8 = ctx->r14 | 0;
            goto L_8007D734;
    }
    // 0x8007D728: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8007D72C: b           L_8007D738
    // 0x8007D730: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007D738;
    // 0x8007D730: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007D734:
    // 0x8007D734: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
L_8007D738:
    // 0x8007D738: bgtz        $t0, L_8007D748
    if (SIGNED(ctx->r8) > 0) {
        // 0x8007D73C: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8007D748;
    }
    // 0x8007D73C: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8007D740: b           L_8007D74C
    // 0x8007D744: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007D74C;
    // 0x8007D744: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007D748:
    // 0x8007D748: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007D74C:
    // 0x8007D74C: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x8007D750: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007D754: bne         $a0, $zero, L_8007D760
    if (ctx->r4 != 0) {
        // 0x8007D758: nop
    
            goto L_8007D760;
    }
    // 0x8007D758: nop

    // 0x8007D75C: break       7
    do_break(2147997532);
L_8007D760:
    // 0x8007D760: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007D764: bne         $a0, $at, L_8007D778
    if (ctx->r4 != ctx->r1) {
        // 0x8007D768: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007D778;
    }
    // 0x8007D768: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D76C: bne         $t7, $at, L_8007D778
    if (ctx->r15 != ctx->r1) {
        // 0x8007D770: nop
    
            goto L_8007D778;
    }
    // 0x8007D770: nop

    // 0x8007D774: break       6
    do_break(2147997556);
L_8007D778:
    // 0x8007D778: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D77C: andi        $t7, $ra, 0xFFF
    ctx->r15 = ctx->r31 & 0XFFF;
    // 0x8007D780: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D784: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007D788: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D78C: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007D790: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D794: mflo        $t8
    ctx->r24 = lo;
    // 0x8007D798: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8007D79C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007D7A0: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8007D7A4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007D7A8: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8007D7AC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8007D7B0: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x8007D7B4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007D7B8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8007D7BC: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007D7C0: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8007D7C4: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x8007D7C8: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007D7CC: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x8007D7D0: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8007D7D4: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007D7D8: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007D7DC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007D7E0: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007D7E4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007D7E8: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007D7EC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007D7F0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007D7F4: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007D7F8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007D7FC: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007D800: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007D804: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007D808: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007D80C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8007D810: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007D814: lw          $t7, 0x278($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X278);
    // 0x8007D818: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007D81C: beq         $t7, $zero, L_8007D82C
    if (ctx->r15 == 0) {
        // 0x8007D820: nop
    
            goto L_8007D82C;
    }
    // 0x8007D820: nop

    // 0x8007D824: bne         $t7, $at, L_8007D840
    if (ctx->r15 != ctx->r1) {
        // 0x8007D828: lw          $t9, 0x27C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X27C);
            goto L_8007D840;
    }
    // 0x8007D828: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007D82C:
    // 0x8007D82C: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007D830: nop

    // 0x8007D834: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007D838: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007D83C:
    // 0x8007D83C: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007D840:
    // 0x8007D840: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007D844: bne         $t9, $at, L_8007DA48
    if (ctx->r25 != ctx->r1) {
        // 0x8007D848: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007DA48;
    }
    // 0x8007D848: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007D84C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D850: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007D854: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007D858: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007D85C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D860: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8007D864: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007D868: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007D86C: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8007D870: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007D874: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007D878: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007D87C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007D880: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007D884: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007D888: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007D88C: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007D890: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007D894: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007D898: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007D89C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D8A0: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007D8A4: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x8007D8A8: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007D8AC: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x8007D8B0: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x8007D8B4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007D8B8: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D8BC: or          $t6, $t8, $t6
    ctx->r14 = ctx->r24 | ctx->r14;
    // 0x8007D8C0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D8C4: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007D8C8: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007D8CC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007D8D0: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x8007D8D4: addiu       $t8, $t4, 0x7
    ctx->r24 = ADD32(ctx->r12, 0X7);
    // 0x8007D8D8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007D8DC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D8E0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007D8E4: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007D8E8: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007D8EC: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007D8F0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8007D8F4: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007D8F8: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8007D8FC: or          $t8, $v0, $v1
    ctx->r24 = ctx->r2 | ctx->r3;
    // 0x8007D900: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007D904: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007D908: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007D90C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D910: or          $t9, $t6, $a2
    ctx->r25 = ctx->r14 | ctx->r6;
    // 0x8007D914: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007D918: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8007D91C: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007D920: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D924: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8007D928: mflo        $t0
    ctx->r8 = lo;
    // 0x8007D92C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007D930: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007D934: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8007D938: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007D93C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007D940: sw          $t3, 0x21C($sp)
    MEM_W(0X21C, ctx->r29) = ctx->r11;
    // 0x8007D944: beq         $at, $zero, L_8007D954
    if (ctx->r1 == 0) {
        // 0x8007D948: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007D954;
    }
    // 0x8007D948: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D94C: b           L_8007D958
    // 0x8007D950: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007D958;
    // 0x8007D950: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007D954:
    // 0x8007D954: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007D958:
    // 0x8007D958: bgez        $t4, L_8007D968
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007D95C: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007D968;
    }
    // 0x8007D95C: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007D960: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007D964: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007D968:
    // 0x8007D968: bgtz        $t3, L_8007D978
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007D96C: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007D978;
    }
    // 0x8007D96C: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007D970: b           L_8007D978
    // 0x8007D974: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007D978;
    // 0x8007D974: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007D978:
    // 0x8007D978: bgtz        $t3, L_8007D988
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007D97C: addiu       $t8, $t2, 0x7FF
        ctx->r24 = ADD32(ctx->r10, 0X7FF);
            goto L_8007D988;
    }
    // 0x8007D97C: addiu       $t8, $t2, 0x7FF
    ctx->r24 = ADD32(ctx->r10, 0X7FF);
    // 0x8007D980: b           L_8007D98C
    // 0x8007D984: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007D98C;
    // 0x8007D984: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007D988:
    // 0x8007D988: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_8007D98C:
    // 0x8007D98C: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x8007D990: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007D994: bne         $a0, $zero, L_8007D9A0
    if (ctx->r4 != 0) {
        // 0x8007D998: nop
    
            goto L_8007D9A0;
    }
    // 0x8007D998: nop

    // 0x8007D99C: break       7
    do_break(2147998108);
L_8007D9A0:
    // 0x8007D9A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007D9A4: bne         $a0, $at, L_8007D9B8
    if (ctx->r4 != ctx->r1) {
        // 0x8007D9A8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007D9B8;
    }
    // 0x8007D9A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D9AC: bne         $t8, $at, L_8007D9B8
    if (ctx->r24 != ctx->r1) {
        // 0x8007D9B0: nop
    
            goto L_8007D9B8;
    }
    // 0x8007D9B0: nop

    // 0x8007D9B4: break       6
    do_break(2147998132);
L_8007D9B8:
    // 0x8007D9B8: andi        $t8, $ra, 0xFFF
    ctx->r24 = ctx->r31 & 0XFFF;
    // 0x8007D9BC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D9C0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D9C4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007D9C8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D9CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007D9D0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D9D4: mflo        $t9
    ctx->r25 = lo;
    // 0x8007D9D8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007D9DC: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8007D9E0: lw          $t8, 0x21C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X21C);
    // 0x8007D9E4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007D9E8: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8007D9EC: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8007D9F0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007D9F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007D9F8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007D9FC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007DA00: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8007DA04: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007DA08: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007DA0C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DA10: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007DA14: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007DA18: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007DA1C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007DA20: lw          $v0, 0x278($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X278);
    // 0x8007DA24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007DA28: beq         $v0, $zero, L_8007DA38
    if (ctx->r2 == 0) {
        // 0x8007DA2C: sw          $t9, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r25;
            goto L_8007DA38;
    }
    // 0x8007DA2C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8007DA30: bne         $v0, $at, L_8007DA4C
    if (ctx->r2 != ctx->r1) {
        // 0x8007DA34: lw          $t7, 0x27C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X27C);
            goto L_8007DA4C;
    }
    // 0x8007DA34: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
L_8007DA38:
    // 0x8007DA38: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8007DA3C: nop

    // 0x8007DA40: ori         $t8, $t6, 0x4
    ctx->r24 = ctx->r14 | 0X4;
    // 0x8007DA44: sh          $t8, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r24;
L_8007DA48:
    // 0x8007DA48: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
L_8007DA4C:
    // 0x8007DA4C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007DA50: bne         $t7, $at, L_8007DCF4
    if (ctx->r15 != ctx->r1) {
        // 0x8007DA54: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007DCF4;
    }
    // 0x8007DA54: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007DA58: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007DA5C: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007DA60: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007DA64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DA68: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007DA6C: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007DA70: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007DA74: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007DA78: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007DA7C: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007DA80: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007DA84: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DA88: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007DA8C: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007DA90: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DA94: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007DA98: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007DA9C: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007DAA0: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007DAA4: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x8007DAA8: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x8007DAAC: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007DAB0: or          $t9, $t7, $a2
    ctx->r25 = ctx->r15 | ctx->r6;
    // 0x8007DAB4: or          $t6, $v0, $v1
    ctx->r14 = ctx->r2 | ctx->r3;
    // 0x8007DAB8: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x8007DABC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8007DAC0: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007DAC4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8007DAC8: or          $t7, $t8, $a2
    ctx->r15 = ctx->r24 | ctx->r6;
    // 0x8007DACC: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8007DAD0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007DAD4: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007DAD8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8007DADC: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8007DAE0: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8007DAE4: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8007DAE8: mflo        $t2
    ctx->r10 = lo;
    // 0x8007DAEC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8007DAF0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007DAF4: sw          $t5, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r13;
    // 0x8007DAF8: jal         0x8007F3B4
    // 0x8007DAFC: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    tex_palette_id(rdram, ctx);
        goto after_0;
    // 0x8007DAFC: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    after_0:
    // 0x8007DB00: lw          $a3, 0x248($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X248);
    // 0x8007DB04: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007DB08: lw          $t5, 0x274($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X274);
    // 0x8007DB0C: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8007DB10: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DB14: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007DB18: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8007DB1C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DB20: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007DB24: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8007DB28: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007DB2C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007DB30: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8007DB34: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DB38: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007DB3C: addiu       $t0, $t2, 0x3
    ctx->r8 = ADD32(ctx->r10, 0X3);
    // 0x8007DB40: sra         $t8, $t0, 2
    ctx->r24 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007DB44: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007DB48: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007DB4C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DB50: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007DB54: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007DB58: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007DB5C: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007DB60: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8007DB64: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007DB68: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007DB6C: beq         $at, $zero, L_8007DB7C
    if (ctx->r1 == 0) {
        // 0x8007DB70: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007DB7C;
    }
    // 0x8007DB70: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DB74: b           L_8007DB80
    // 0x8007DB78: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007DB80;
    // 0x8007DB78: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007DB7C:
    // 0x8007DB7C: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007DB80:
    // 0x8007DB80: bgez        $t5, L_8007DB90
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007DB84: sra         $t1, $t5, 4
        ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
            goto L_8007DB90;
    }
    // 0x8007DB84: sra         $t1, $t5, 4
    ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8007DB88: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x8007DB8C: sra         $t1, $at, 4
    ctx->r9 = S32(SIGNED(ctx->r1) >> 4);
L_8007DB90:
    // 0x8007DB90: addiu       $t8, $t1, 0x7FF
    ctx->r24 = ADD32(ctx->r9, 0X7FF);
    // 0x8007DB94: div         $zero, $t8, $t1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r9)));
    // 0x8007DB98: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007DB9C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8007DBA0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DBA4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007DBA8: bne         $t1, $zero, L_8007DBB4
    if (ctx->r9 != 0) {
        // 0x8007DBAC: nop
    
            goto L_8007DBB4;
    }
    // 0x8007DBAC: nop

    // 0x8007DBB0: break       7
    do_break(2147998640);
L_8007DBB4:
    // 0x8007DBB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007DBB8: bne         $t1, $at, L_8007DBCC
    if (ctx->r9 != ctx->r1) {
        // 0x8007DBBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007DBCC;
    }
    // 0x8007DBBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DBC0: bne         $t8, $at, L_8007DBCC
    if (ctx->r24 != ctx->r1) {
        // 0x8007DBC4: nop
    
            goto L_8007DBCC;
    }
    // 0x8007DBC4: nop

    // 0x8007DBC8: break       6
    do_break(2147998664);
L_8007DBCC:
    // 0x8007DBCC: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DBD0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DBD4: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8007DBD8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007DBDC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DBE0: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007DBE4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DBE8: mflo        $t9
    ctx->r25 = lo;
    // 0x8007DBEC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007DBF0: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8007DBF4: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8007DBF8: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007DBFC: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x8007DC00: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007DC04: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007DC08: sra         $t8, $t6, 3
    ctx->r24 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8007DC0C: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x8007DC10: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8007DC14: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8007DC18: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007DC1C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007DC20: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DC24: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007DC28: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8007DC2C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007DC30: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007DC34: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DC38: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8007DC3C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DC40: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8007DC44: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007DC48: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007DC4C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8007DC50: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DC54: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007DC58: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8007DC5C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007DC60: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007DC64: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8007DC68: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8007DC6C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DC70: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8007DC74: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007DC78: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007DC7C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007DC80: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DC84: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007DC88: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007DC8C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007DC90: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8007DC94: lw          $a0, 0x278($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X278);
    // 0x8007DC98: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x8007DC9C: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8007DCA0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DCA4: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x8007DCA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007DCAC: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DCB0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007DCB4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007DCB8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007DCBC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007DCC0: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8007DCC4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DCC8: ori         $t8, $t6, 0x20
    ctx->r24 = ctx->r14 | 0X20;
    // 0x8007DCCC: beq         $a0, $zero, L_8007DCE0
    if (ctx->r4 == 0) {
        // 0x8007DCD0: sh          $t8, 0x6($s1)
        MEM_H(0X6, ctx->r17) = ctx->r24;
            goto L_8007DCE0;
    }
    // 0x8007DCD0: sh          $t8, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r24;
    // 0x8007DCD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007DCD8: bne         $a0, $at, L_8007DCF4
    if (ctx->r4 != ctx->r1) {
        // 0x8007DCDC: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007DCF4;
    }
    // 0x8007DCDC: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007DCE0:
    // 0x8007DCE0: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007DCE4: nop

    // 0x8007DCE8: ori         $t7, $t9, 0x4
    ctx->r15 = ctx->r25 | 0X4;
    // 0x8007DCEC: sh          $t7, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r15;
    // 0x8007DCF0: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007DCF4:
    // 0x8007DCF4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007DCF8: bne         $t6, $at, L_8007DEEC
    if (ctx->r14 != ctx->r1) {
        // 0x8007DCFC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007DEEC;
    }
    // 0x8007DCFC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007DD00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DD04: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007DD08: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007DD0C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007DD10: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DD14: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x8007DD18: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007DD1C: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007DD20: lui         $t7, 0xF570
    ctx->r15 = S32(0XF570 << 16);
    // 0x8007DD24: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8007DD28: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007DD2C: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007DD30: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007DD34: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007DD38: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007DD3C: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007DD40: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x8007DD44: sll         $v1, $t9, 14
    ctx->r3 = S32(ctx->r25 << 14);
    // 0x8007DD48: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007DD4C: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007DD50: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DD54: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007DD58: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x8007DD5C: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007DD60: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007DD64: or          $t9, $t8, $a1
    ctx->r25 = ctx->r24 | ctx->r5;
    // 0x8007DD68: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8007DD6C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DD70: or          $t7, $t9, $t7
    ctx->r15 = ctx->r25 | ctx->r15;
    // 0x8007DD74: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DD78: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007DD7C: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8007DD80: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007DD84: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x8007DD88: addiu       $t9, $t4, 0x7
    ctx->r25 = ADD32(ctx->r12, 0X7);
    // 0x8007DD8C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007DD90: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DD94: or          $ra, $a3, $zero
    ctx->r31 = ctx->r7 | 0;
    // 0x8007DD98: sra         $t7, $t9, 3
    ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007DD9C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007DDA0: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007DDA4: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
    // 0x8007DDA8: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8007DDAC: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8007DDB0: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007DDB4: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007DDB8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8007DDBC: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007DDC0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007DDC4: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007DDC8: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8007DDCC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007DDD0: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007DDD4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007DDD8: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007DDDC: mflo        $t0
    ctx->r8 = lo;
    // 0x8007DDE0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007DDE4: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8007DDE8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8007DDEC: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007DDF0: sw          $ra, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r31;
    // 0x8007DDF4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DDF8: bgez        $t4, L_8007DE08
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007DDFC: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007DE08;
    }
    // 0x8007DDFC: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007DE00: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007DE04: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007DE08:
    // 0x8007DE08: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007DE0C: beq         $at, $zero, L_8007DE1C
    if (ctx->r1 == 0) {
        // 0x8007DE10: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007DE1C;
    }
    // 0x8007DE10: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007DE14: b           L_8007DE20
    // 0x8007DE18: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007DE20;
    // 0x8007DE18: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007DE1C:
    // 0x8007DE1C: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007DE20:
    // 0x8007DE20: bgtz        $t3, L_8007DE30
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007DE24: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_8007DE30;
    }
    // 0x8007DE24: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8007DE28: b           L_8007DE30
    // 0x8007DE2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007DE30;
    // 0x8007DE2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007DE30:
    // 0x8007DE30: bgtz        $t3, L_8007DE40
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007DE34: addiu       $t9, $t2, 0x7FF
        ctx->r25 = ADD32(ctx->r10, 0X7FF);
            goto L_8007DE40;
    }
    // 0x8007DE34: addiu       $t9, $t2, 0x7FF
    ctx->r25 = ADD32(ctx->r10, 0X7FF);
    // 0x8007DE38: b           L_8007DE40
    // 0x8007DE3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007DE40;
    // 0x8007DE3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007DE40:
    // 0x8007DE40: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x8007DE44: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007DE48: bne         $a0, $zero, L_8007DE54
    if (ctx->r4 != 0) {
        // 0x8007DE4C: nop
    
            goto L_8007DE54;
    }
    // 0x8007DE4C: nop

    // 0x8007DE50: break       7
    do_break(2147999312);
L_8007DE54:
    // 0x8007DE54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007DE58: bne         $a0, $at, L_8007DE6C
    if (ctx->r4 != ctx->r1) {
        // 0x8007DE5C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007DE6C;
    }
    // 0x8007DE5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DE60: bne         $t9, $at, L_8007DE6C
    if (ctx->r25 != ctx->r1) {
        // 0x8007DE64: nop
    
            goto L_8007DE6C;
    }
    // 0x8007DE64: nop

    // 0x8007DE68: break       6
    do_break(2147999336);
L_8007DE6C:
    // 0x8007DE6C: andi        $t9, $ra, 0xFFF
    ctx->r25 = ctx->r31 & 0XFFF;
    // 0x8007DE70: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DE74: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DE78: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DE7C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DE80: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007DE84: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DE88: mflo        $t6
    ctx->r14 = lo;
    // 0x8007DE8C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007DE90: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8007DE94: lw          $t9, 0x1CC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1CC);
    // 0x8007DE98: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007DE9C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007DEA0: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8007DEA4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007DEA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007DEAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007DEB0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007DEB4: lui         $at, 0xF570
    ctx->r1 = S32(0XF570 << 16);
    // 0x8007DEB8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007DEBC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007DEC0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DEC4: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007DEC8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007DECC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007DED0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007DED4: nop

    // 0x8007DED8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007DEDC: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007DEE0: nop

    // 0x8007DEE4: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8007DEE8: sh          $t9, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r25;
L_8007DEEC:
    // 0x8007DEEC: lw          $t8, 0x27C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X27C);
    // 0x8007DEF0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007DEF4: bne         $t8, $at, L_8007E0E8
    if (ctx->r24 != ctx->r1) {
        // 0x8007DEF8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E0E8;
    }
    // 0x8007DEF8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007DEFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DF00: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007DF04: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007DF08: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007DF0C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DF10: lui         $t6, 0xFD70
    ctx->r14 = S32(0XFD70 << 16);
    // 0x8007DF14: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007DF18: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007DF1C: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x8007DF20: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007DF24: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007DF28: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007DF2C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007DF30: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8007DF34: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007DF38: sll         $v0, $t8, 18
    ctx->r2 = S32(ctx->r24 << 18);
    // 0x8007DF3C: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007DF40: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007DF44: andi        $t8, $a1, 0x3
    ctx->r24 = ctx->r5 & 0X3;
    // 0x8007DF48: sll         $a1, $t8, 8
    ctx->r5 = S32(ctx->r24 << 8);
    // 0x8007DF4C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DF50: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007DF54: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8007DF58: or          $t8, $v0, $at
    ctx->r24 = ctx->r2 | ctx->r1;
    // 0x8007DF5C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DF60: or          $t6, $t8, $v1
    ctx->r14 = ctx->r24 | ctx->r3;
    // 0x8007DF64: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x8007DF68: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8007DF6C: or          $t9, $t7, $t9
    ctx->r25 = ctx->r15 | ctx->r25;
    // 0x8007DF70: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DF74: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007DF78: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8007DF7C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DF80: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8007DF84: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007DF88: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007DF8C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007DF90: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007DF94: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8007DF98: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8007DF9C: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8007DFA0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8007DFA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007DFA8: or          $t8, $t9, $a2
    ctx->r24 = ctx->r25 | ctx->r6;
    // 0x8007DFAC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007DFB0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007DFB4: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x8007DFB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007DFBC: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8007DFC0: mflo        $t2
    ctx->r10 = lo;
    // 0x8007DFC4: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x8007DFC8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007DFCC: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007DFD0: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007DFD4: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007DFD8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8007DFDC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8007DFE0: sw          $t3, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->r11;
    // 0x8007DFE4: beq         $at, $zero, L_8007DFF4
    if (ctx->r1 == 0) {
        // 0x8007DFE8: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007DFF4;
    }
    // 0x8007DFE8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DFEC: b           L_8007DFF8
    // 0x8007DFF0: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007DFF8;
    // 0x8007DFF0: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007DFF4:
    // 0x8007DFF4: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007DFF8:
    // 0x8007DFF8: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x8007DFFC: bgez        $t4, L_8007E00C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007E000: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007E00C;
    }
    // 0x8007E000: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007E004: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007E008: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007E00C:
    // 0x8007E00C: bgtz        $t3, L_8007E01C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007E010: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007E01C;
    }
    // 0x8007E010: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007E014: b           L_8007E01C
    // 0x8007E018: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007E01C;
    // 0x8007E018: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007E01C:
    // 0x8007E01C: bgtz        $t3, L_8007E02C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007E020: addiu       $t8, $t2, 0x7FF
        ctx->r24 = ADD32(ctx->r10, 0X7FF);
            goto L_8007E02C;
    }
    // 0x8007E020: addiu       $t8, $t2, 0x7FF
    ctx->r24 = ADD32(ctx->r10, 0X7FF);
    // 0x8007E024: b           L_8007E030
    // 0x8007E028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007E030;
    // 0x8007E028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007E02C:
    // 0x8007E02C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_8007E030:
    // 0x8007E030: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x8007E034: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E038: bne         $a0, $zero, L_8007E044
    if (ctx->r4 != 0) {
        // 0x8007E03C: nop
    
            goto L_8007E044;
    }
    // 0x8007E03C: nop

    // 0x8007E040: break       7
    do_break(2147999808);
L_8007E044:
    // 0x8007E044: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E048: bne         $a0, $at, L_8007E05C
    if (ctx->r4 != ctx->r1) {
        // 0x8007E04C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E05C;
    }
    // 0x8007E04C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E050: bne         $t8, $at, L_8007E05C
    if (ctx->r24 != ctx->r1) {
        // 0x8007E054: nop
    
            goto L_8007E05C;
    }
    // 0x8007E054: nop

    // 0x8007E058: break       6
    do_break(2147999832);
L_8007E05C:
    // 0x8007E05C: andi        $t8, $ra, 0xFFF
    ctx->r24 = ctx->r31 & 0XFFF;
    // 0x8007E060: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E064: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E068: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E06C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E070: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E074: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E078: mflo        $t9
    ctx->r25 = lo;
    // 0x8007E07C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007E080: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8007E084: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007E088: lw          $t8, 0x1B0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1B0);
    // 0x8007E08C: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8007E090: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8007E094: addiu       $t9, $t4, 0x7
    ctx->r25 = ADD32(ctx->r12, 0X7);
    // 0x8007E098: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007E09C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007E0A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007E0A4: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x8007E0A8: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8007E0AC: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8007E0B0: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007E0B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E0B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007E0BC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E0C0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007E0C4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007E0C8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007E0CC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007E0D0: nop

    // 0x8007E0D4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007E0D8: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007E0DC: nop

    // 0x8007E0E0: ori         $t6, $t9, 0x4
    ctx->r14 = ctx->r25 | 0X4;
    // 0x8007E0E4: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007E0E8:
    // 0x8007E0E8: lw          $t8, 0x27C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X27C);
    // 0x8007E0EC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007E0F0: bne         $t8, $at, L_8007E2C4
    if (ctx->r24 != ctx->r1) {
        // 0x8007E0F4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E2C4;
    }
    // 0x8007E0F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E0F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E0FC: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E100: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E104: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007E108: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E10C: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8007E110: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007E114: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E118: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x8007E11C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007E120: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E124: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E128: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E12C: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8007E130: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E134: sll         $v0, $t8, 18
    ctx->r2 = S32(ctx->r24 << 18);
    // 0x8007E138: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x8007E13C: sll         $v1, $t9, 14
    ctx->r3 = S32(ctx->r25 << 14);
    // 0x8007E140: andi        $t8, $a1, 0x3
    ctx->r24 = ctx->r5 & 0X3;
    // 0x8007E144: sll         $a1, $t8, 8
    ctx->r5 = S32(ctx->r24 << 8);
    // 0x8007E148: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E14C: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007E150: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8007E154: or          $t8, $v0, $at
    ctx->r24 = ctx->r2 | ctx->r1;
    // 0x8007E158: or          $t7, $t8, $v1
    ctx->r15 = ctx->r24 | ctx->r3;
    // 0x8007E15C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E160: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8007E164: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007E168: or          $t6, $t9, $t6
    ctx->r14 = ctx->r25 | ctx->r14;
    // 0x8007E16C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E170: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E174: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8007E178: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E17C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8007E180: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007E184: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8007E188: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8007E18C: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007E190: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007E194: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8007E198: or          $t6, $t9, $a1
    ctx->r14 = ctx->r25 | ctx->r5;
    // 0x8007E19C: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007E1A0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007E1A4: or          $t8, $t6, $a2
    ctx->r24 = ctx->r14 | ctx->r6;
    // 0x8007E1A8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007E1AC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007E1B0: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007E1B4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007E1B8: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007E1BC: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E1C0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007E1C4: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007E1C8: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007E1CC: sra         $t9, $t0, 2
    ctx->r25 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007E1D0: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007E1D4: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007E1D8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8007E1DC: sra         $t9, $ra, 3
    ctx->r25 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007E1E0: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007E1E4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E1E8: bgez        $t5, L_8007E1F8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007E1EC: sra         $t1, $t5, 4
        ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
            goto L_8007E1F8;
    }
    // 0x8007E1EC: sra         $t1, $t5, 4
    ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8007E1F0: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x8007E1F4: sra         $t1, $at, 4
    ctx->r9 = S32(SIGNED(ctx->r1) >> 4);
L_8007E1F8:
    // 0x8007E1F8: addiu       $t8, $t1, 0x7FF
    ctx->r24 = ADD32(ctx->r9, 0X7FF);
    // 0x8007E1FC: div         $zero, $t8, $t1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r9)));
    // 0x8007E200: bne         $t1, $zero, L_8007E20C
    if (ctx->r9 != 0) {
        // 0x8007E204: nop
    
            goto L_8007E20C;
    }
    // 0x8007E204: nop

    // 0x8007E208: break       7
    do_break(2148000264);
L_8007E20C:
    // 0x8007E20C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E210: bne         $t1, $at, L_8007E224
    if (ctx->r9 != ctx->r1) {
        // 0x8007E214: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E224;
    }
    // 0x8007E214: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E218: bne         $t8, $at, L_8007E224
    if (ctx->r24 != ctx->r1) {
        // 0x8007E21C: nop
    
            goto L_8007E224;
    }
    // 0x8007E21C: nop

    // 0x8007E220: break       6
    do_break(2148000288);
L_8007E224:
    // 0x8007E224: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8007E228: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E22C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E230: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E234: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E238: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x8007E23C: mflo        $t6
    ctx->r14 = lo;
    // 0x8007E240: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007E244: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x8007E248: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x8007E24C: beq         $at, $zero, L_8007E25C
    if (ctx->r1 == 0) {
        // 0x8007E250: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_8007E25C;
    }
    // 0x8007E250: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007E254: b           L_8007E25C
    // 0x8007E258: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E25C;
    // 0x8007E258: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E25C:
    // 0x8007E25C: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007E260: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007E264: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8007E268: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E26C: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8007E270: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007E274: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8007E278: lui         $at, 0xF560
    ctx->r1 = S32(0XF560 << 16);
    // 0x8007E27C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007E280: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007E284: or          $t8, $ra, $at
    ctx->r24 = ctx->r31 | ctx->r1;
    // 0x8007E288: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E28C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007E290: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E294: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E298: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E29C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007E2A0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007E2A4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007E2A8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007E2AC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E2B0: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8007E2B4: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007E2B8: nop

    // 0x8007E2BC: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007E2C0: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007E2C4:
    // 0x8007E2C4: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
    // 0x8007E2C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E2CC: bne         $t7, $at, L_8007E4B8
    if (ctx->r15 != ctx->r1) {
        // 0x8007E2D0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E4B8;
    }
    // 0x8007E2D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E2D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E2D8: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E2DC: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E2E0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007E2E4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E2E8: lui         $t9, 0xFD90
    ctx->r25 = S32(0XFD90 << 16);
    // 0x8007E2EC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007E2F0: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E2F4: lui         $t6, 0xF590
    ctx->r14 = S32(0XF590 << 16);
    // 0x8007E2F8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007E2FC: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E300: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E304: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E308: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8007E30C: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E310: sll         $v0, $t7, 18
    ctx->r2 = S32(ctx->r15 << 18);
    // 0x8007E314: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007E318: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007E31C: andi        $t7, $a1, 0x3
    ctx->r15 = ctx->r5 & 0X3;
    // 0x8007E320: sll         $a1, $t7, 8
    ctx->r5 = S32(ctx->r15 << 8);
    // 0x8007E324: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E328: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007E32C: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x8007E330: or          $t7, $v0, $at
    ctx->r15 = ctx->r2 | ctx->r1;
    // 0x8007E334: or          $t9, $t7, $v1
    ctx->r25 = ctx->r15 | ctx->r3;
    // 0x8007E338: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007E33C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007E340: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E344: or          $t6, $t8, $t6
    ctx->r14 = ctx->r24 | ctx->r14;
    // 0x8007E348: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E34C: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E350: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007E354: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E358: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8007E35C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8007E360: or          $ra, $a3, $zero
    ctx->r31 = ctx->r7 | 0;
    // 0x8007E364: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007E368: or          $t8, $v0, $v1
    ctx->r24 = ctx->r2 | ctx->r3;
    // 0x8007E36C: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007E370: sw          $t9, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r25;
    // 0x8007E374: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007E378: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007E37C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007E380: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007E384: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007E388: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007E38C: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007E390: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007E394: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007E398: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007E39C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8007E3A0: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E3A4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8007E3A8: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x8007E3AC: addiu       $t7, $t4, 0x7
    ctx->r15 = ADD32(ctx->r12, 0X7);
    // 0x8007E3B0: sra         $t8, $t0, 1
    ctx->r24 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007E3B4: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007E3B8: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8007E3BC: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007E3C0: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007E3C4: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x8007E3C8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8007E3CC: sw          $ra, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r31;
    // 0x8007E3D0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E3D4: bgez        $t4, L_8007E3E4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007E3D8: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007E3E4;
    }
    // 0x8007E3D8: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007E3DC: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007E3E0: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007E3E4:
    // 0x8007E3E4: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E3E8: beq         $at, $zero, L_8007E3F8
    if (ctx->r1 == 0) {
        // 0x8007E3EC: or          $t4, $t8, $zero
        ctx->r12 = ctx->r24 | 0;
            goto L_8007E3F8;
    }
    // 0x8007E3EC: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x8007E3F0: b           L_8007E3FC
    // 0x8007E3F4: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007E3FC;
    // 0x8007E3F4: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007E3F8:
    // 0x8007E3F8: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007E3FC:
    // 0x8007E3FC: bgtz        $t3, L_8007E40C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007E400: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007E40C;
    }
    // 0x8007E400: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007E404: b           L_8007E40C
    // 0x8007E408: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007E40C;
    // 0x8007E408: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007E40C:
    // 0x8007E40C: bgtz        $t3, L_8007E41C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007E410: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8007E41C;
    }
    // 0x8007E410: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8007E414: b           L_8007E420
    // 0x8007E418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007E420;
    // 0x8007E418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007E41C:
    // 0x8007E41C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_8007E420:
    // 0x8007E420: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x8007E424: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E428: bne         $a0, $zero, L_8007E434
    if (ctx->r4 != 0) {
        // 0x8007E42C: nop
    
            goto L_8007E434;
    }
    // 0x8007E42C: nop

    // 0x8007E430: break       7
    do_break(2148000816);
L_8007E434:
    // 0x8007E434: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E438: bne         $a0, $at, L_8007E44C
    if (ctx->r4 != ctx->r1) {
        // 0x8007E43C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E44C;
    }
    // 0x8007E43C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E440: bne         $t7, $at, L_8007E44C
    if (ctx->r15 != ctx->r1) {
        // 0x8007E444: nop
    
            goto L_8007E44C;
    }
    // 0x8007E444: nop

    // 0x8007E448: break       6
    do_break(2148000840);
L_8007E44C:
    // 0x8007E44C: andi        $t7, $ra, 0xFFF
    ctx->r15 = ctx->r31 & 0XFFF;
    // 0x8007E450: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E454: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E458: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E45C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E460: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E464: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E468: mflo        $t6
    ctx->r14 = lo;
    // 0x8007E46C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8007E470: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007E474: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x8007E478: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8007E47C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8007E480: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8007E484: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007E488: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8007E48C: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x8007E490: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007E494: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E498: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007E49C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E4A0: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007E4A4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007E4A8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007E4AC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007E4B0: nop

    // 0x8007E4B4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
L_8007E4B8:
    // 0x8007E4B8: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007E4BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007E4C0: bne         $t6, $at, L_8007E684
    if (ctx->r14 != ctx->r1) {
        // 0x8007E4C4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E684;
    }
    // 0x8007E4C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E4C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E4CC: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E4D0: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E4D4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007E4D8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E4DC: lui         $t9, 0xFD90
    ctx->r25 = S32(0XFD90 << 16);
    // 0x8007E4E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007E4E4: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E4E8: lui         $t8, 0xF590
    ctx->r24 = S32(0XF590 << 16);
    // 0x8007E4EC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8007E4F0: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E4F4: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E4F8: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E4FC: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007E500: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E504: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007E508: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007E50C: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007E510: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007E514: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007E518: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E51C: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007E520: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8007E524: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007E528: or          $t9, $t6, $v1
    ctx->r25 = ctx->r14 | ctx->r3;
    // 0x8007E52C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E530: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007E534: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8007E538: or          $t8, $t7, $t8
    ctx->r24 = ctx->r15 | ctx->r24;
    // 0x8007E53C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E540: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E544: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8007E548: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E54C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007E550: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8007E554: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8007E558: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8007E55C: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007E560: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007E564: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8007E568: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x8007E56C: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007E570: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E574: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007E578: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007E57C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007E580: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007E584: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E588: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8007E58C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E590: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007E594: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007E598: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007E59C: sra         $t7, $t0, 2
    ctx->r15 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007E5A0: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007E5A4: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007E5A8: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007E5AC: sra         $t7, $ra, 3
    ctx->r15 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007E5B0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007E5B4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E5B8: bgez        $t5, L_8007E5C8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007E5BC: sra         $t1, $t5, 4
        ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
            goto L_8007E5C8;
    }
    // 0x8007E5BC: sra         $t1, $t5, 4
    ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8007E5C0: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x8007E5C4: sra         $t1, $at, 4
    ctx->r9 = S32(SIGNED(ctx->r1) >> 4);
L_8007E5C8:
    // 0x8007E5C8: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8007E5CC: div         $zero, $t6, $t1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r9)));
    // 0x8007E5D0: bne         $t1, $zero, L_8007E5DC
    if (ctx->r9 != 0) {
        // 0x8007E5D4: nop
    
            goto L_8007E5DC;
    }
    // 0x8007E5D4: nop

    // 0x8007E5D8: break       7
    do_break(2148001240);
L_8007E5DC:
    // 0x8007E5DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E5E0: bne         $t1, $at, L_8007E5F4
    if (ctx->r9 != ctx->r1) {
        // 0x8007E5E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E5F4;
    }
    // 0x8007E5E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E5E8: bne         $t6, $at, L_8007E5F4
    if (ctx->r14 != ctx->r1) {
        // 0x8007E5EC: nop
    
            goto L_8007E5F4;
    }
    // 0x8007E5EC: nop

    // 0x8007E5F0: break       6
    do_break(2148001264);
L_8007E5F4:
    // 0x8007E5F4: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8007E5F8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E5FC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E600: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E604: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E608: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x8007E60C: mflo        $t8
    ctx->r24 = lo;
    // 0x8007E610: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8007E614: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8007E618: or          $ra, $t8, $zero
    ctx->r31 = ctx->r24 | 0;
    // 0x8007E61C: beq         $at, $zero, L_8007E62C
    if (ctx->r1 == 0) {
        // 0x8007E620: sw          $t9, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r25;
            goto L_8007E62C;
    }
    // 0x8007E620: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8007E624: b           L_8007E62C
    // 0x8007E628: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E62C;
    // 0x8007E628: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E62C:
    // 0x8007E62C: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007E630: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007E634: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8007E638: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E63C: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8007E640: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007E644: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8007E648: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8007E64C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007E650: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007E654: or          $t6, $ra, $at
    ctx->r14 = ctx->r31 | ctx->r1;
    // 0x8007E658: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E65C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007E660: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E664: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E668: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E66C: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007E670: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007E674: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007E678: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007E67C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E680: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
L_8007E684:
    // 0x8007E684: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x8007E688: nop

    // 0x8007E68C: subu        $t8, $a3, $t6
    ctx->r24 = SUB32(ctx->r7, ctx->r14);
    // 0x8007E690: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007E694: b           L_8007F3A0
    // 0x8007E698: sh          $t9, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r25;
        goto L_8007F3A0;
    // 0x8007E698: sh          $t9, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r25;
L_8007E69C:
    // 0x8007E69C: sw          $t2, 0x264($sp)
    MEM_W(0X264, ctx->r29) = ctx->r10;
    // 0x8007E6A0: sw          $t3, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r11;
    // 0x8007E6A4: bne         $t4, $zero, L_8007E820
    if (ctx->r12 != 0) {
        // 0x8007E6A8: sw          $t4, 0x27C($sp)
        MEM_W(0X27C, ctx->r29) = ctx->r12;
            goto L_8007E820;
    }
    // 0x8007E6A8: sw          $t4, 0x27C($sp)
    MEM_W(0X27C, ctx->r29) = ctx->r12;
    // 0x8007E6AC: lw          $t2, 0x284($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X284);
    // 0x8007E6B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E6B4: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E6B8: addu        $t6, $s1, $at
    ctx->r14 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E6BC: lui         $t7, 0xFD18
    ctx->r15 = S32(0XFD18 << 16);
    // 0x8007E6C0: addiu       $a3, $t2, 0x8
    ctx->r7 = ADD32(ctx->r10, 0X8);
    // 0x8007E6C4: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007E6C8: lui         $t8, 0xF518
    ctx->r24 = S32(0XF518 << 16);
    // 0x8007E6CC: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8007E6D0: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8007E6D4: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E6D8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8007E6DC: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E6E0: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E6E4: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E6E8: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007E6EC: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007E6F0: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E6F4: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007E6F8: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x8007E6FC: sll         $v1, $t6, 14
    ctx->r3 = S32(ctx->r14 << 14);
    // 0x8007E700: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007E704: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E708: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007E70C: andi        $t6, $a2, 0xF
    ctx->r14 = ctx->r6 & 0XF;
    // 0x8007E710: sll         $a2, $t6, 4
    ctx->r6 = S32(ctx->r14 << 4);
    // 0x8007E714: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x8007E718: or          $t6, $t7, $a1
    ctx->r14 = ctx->r15 | ctx->r5;
    // 0x8007E71C: or          $t8, $t6, $a2
    ctx->r24 = ctx->r14 | ctx->r6;
    // 0x8007E720: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E724: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E728: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8007E72C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E730: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007E734: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E738: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007E73C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8007E740: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E744: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E748: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007E74C: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007E750: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8007E754: beq         $at, $zero, L_8007E764
    if (ctx->r1 == 0) {
        // 0x8007E758: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007E764;
    }
    // 0x8007E758: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E75C: b           L_8007E768
    // 0x8007E760: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E768;
    // 0x8007E760: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E764:
    // 0x8007E764: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007E768:
    // 0x8007E768: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x8007E76C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007E770: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E774: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8007E778: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007E77C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8007E780: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x8007E784: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007E788: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007E78C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8007E790: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007E794: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8007E798: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x8007E79C: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007E7A0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E7A4: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x8007E7A8: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8007E7AC: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E7B0: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007E7B4: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007E7B8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007E7BC: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007E7C0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E7C4: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007E7C8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007E7CC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E7D0: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E7D4: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007E7D8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007E7DC: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8007E7E0: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007E7E4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E7E8: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007E7EC: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007E7F0: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8007E7F4: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8007E7F8: lw          $t7, 0x278($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X278);
    // 0x8007E7FC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E800: beq         $t7, $zero, L_8007E810
    if (ctx->r15 == 0) {
        // 0x8007E804: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007E810;
    }
    // 0x8007E804: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E808: bne         $t7, $at, L_8007E824
    if (ctx->r15 != ctx->r1) {
        // 0x8007E80C: lw          $t9, 0x27C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X27C);
            goto L_8007E824;
    }
    // 0x8007E80C: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007E810:
    // 0x8007E810: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007E814: nop

    // 0x8007E818: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007E81C: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007E820:
    // 0x8007E820: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007E824:
    // 0x8007E824: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007E828: bne         $t9, $at, L_8007E9BC
    if (ctx->r25 != ctx->r1) {
        // 0x8007E82C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E9BC;
    }
    // 0x8007E82C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E830: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E834: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E838: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E83C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E840: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8007E844: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007E848: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E84C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007E850: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8007E854: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007E858: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E85C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E860: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E864: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007E868: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007E86C: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E870: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007E874: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007E878: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007E87C: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007E880: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E884: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007E888: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007E88C: sll         $a2, $t8, 4
    ctx->r6 = S32(ctx->r24 << 4);
    // 0x8007E890: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x8007E894: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x8007E898: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007E89C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E8A0: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E8A4: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E8A8: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007E8AC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007E8B0: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007E8B4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E8B8: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x8007E8BC: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x8007E8C0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E8C4: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007E8C8: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007E8CC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8007E8D0: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8007E8D4: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8007E8D8: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8007E8DC: or          $t6, $v0, $v1
    ctx->r14 = ctx->r2 | ctx->r3;
    // 0x8007E8E0: or          $t9, $t6, $a1
    ctx->r25 = ctx->r14 | ctx->r5;
    // 0x8007E8E4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8007E8E8: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007E8EC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8007E8F0: or          $t7, $t9, $a2
    ctx->r15 = ctx->r25 | ctx->r6;
    // 0x8007E8F4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8007E8F8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007E8FC: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007E900: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8007E904: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8007E908: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E90C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007E910: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8007E914: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8007E918: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E91C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007E920: beq         $at, $zero, L_8007E930
    if (ctx->r1 == 0) {
        // 0x8007E924: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007E930;
    }
    // 0x8007E924: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E928: b           L_8007E934
    // 0x8007E92C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E934;
    // 0x8007E92C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E930:
    // 0x8007E930: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007E934:
    // 0x8007E934: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x8007E938: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007E93C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E940: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007E944: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007E948: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E94C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007E950: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007E954: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E958: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007E95C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E960: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8007E964: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E968: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007E96C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007E970: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E974: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E978: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E97C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007E980: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007E984: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007E988: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007E98C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E990: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007E994: lw          $t7, 0x278($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X278);
    // 0x8007E998: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E99C: beq         $t7, $zero, L_8007E9AC
    if (ctx->r15 == 0) {
        // 0x8007E9A0: nop
    
            goto L_8007E9AC;
    }
    // 0x8007E9A0: nop

    // 0x8007E9A4: bne         $t7, $at, L_8007E9C0
    if (ctx->r15 != ctx->r1) {
        // 0x8007E9A8: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007E9C0;
    }
    // 0x8007E9A8: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007E9AC:
    // 0x8007E9AC: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007E9B0: nop

    // 0x8007E9B4: ori         $t8, $t9, 0x4
    ctx->r24 = ctx->r25 | 0X4;
    // 0x8007E9B8: sh          $t8, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r24;
L_8007E9BC:
    // 0x8007E9BC: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007E9C0:
    // 0x8007E9C0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007E9C4: bne         $t6, $at, L_8007EC24
    if (ctx->r14 != ctx->r1) {
        // 0x8007E9C8: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007EC24;
    }
    // 0x8007E9C8: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007E9CC: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E9D0: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E9D4: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E9D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E9DC: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007E9E0: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007E9E4: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E9E8: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E9EC: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E9F0: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x8007E9F4: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007E9F8: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E9FC: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007EA00: sll         $v1, $t6, 14
    ctx->r3 = S32(ctx->r14 << 14);
    // 0x8007EA04: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EA08: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007EA0C: andi        $t6, $a2, 0xF
    ctx->r14 = ctx->r6 & 0XF;
    // 0x8007EA10: sll         $a2, $t6, 4
    ctx->r6 = S32(ctx->r14 << 4);
    // 0x8007EA14: or          $t8, $t9, $v1
    ctx->r24 = ctx->r25 | ctx->r3;
    // 0x8007EA18: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x8007EA1C: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8007EA20: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007EA24: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007EA28: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007EA2C: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007EA30: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8007EA34: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007EA38: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007EA3C: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007EA40: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007EA44: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007EA48: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007EA4C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007EA50: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8007EA54: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007EA58: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8007EA5C: mflo        $t2
    ctx->r10 = lo;
    // 0x8007EA60: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8007EA64: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007EA68: sw          $t5, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r13;
    // 0x8007EA6C: jal         0x8007F3B4
    // 0x8007EA70: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    tex_palette_id(rdram, ctx);
        goto after_1;
    // 0x8007EA70: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    after_1:
    // 0x8007EA74: lw          $a3, 0x248($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X248);
    // 0x8007EA78: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007EA7C: lw          $t5, 0x274($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X274);
    // 0x8007EA80: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x8007EA84: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007EA88: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007EA8C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8007EA90: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EA94: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EA98: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8007EA9C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007EAA0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007EAA4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8007EAA8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EAAC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EAB0: addiu       $t0, $t2, 0x3
    ctx->r8 = ADD32(ctx->r10, 0X3);
    // 0x8007EAB4: sra         $t8, $t0, 2
    ctx->r24 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007EAB8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007EABC: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007EAC0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EAC4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007EAC8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007EACC: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007EAD0: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007EAD4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8007EAD8: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8007EADC: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007EAE0: beq         $at, $zero, L_8007EAF0
    if (ctx->r1 == 0) {
        // 0x8007EAE4: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007EAF0;
    }
    // 0x8007EAE4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EAE8: b           L_8007EAF4
    // 0x8007EAEC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007EAF4;
    // 0x8007EAEC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007EAF0:
    // 0x8007EAF0: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007EAF4:
    // 0x8007EAF4: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007EAF8: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8007EAFC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EB00: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007EB04: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007EB08: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007EB0C: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x8007EB10: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007EB14: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007EB18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007EB1C: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007EB20: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x8007EB24: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8007EB28: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB2C: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8007EB30: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007EB34: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EB38: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007EB3C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007EB40: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EB44: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB48: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007EB4C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007EB50: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007EB54: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8007EB58: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007EB5C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB60: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8007EB64: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007EB68: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB6C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EB70: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8007EB74: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007EB78: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB7C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8007EB80: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EB84: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8007EB88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007EB8C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007EB90: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8007EB94: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8007EB98: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB9C: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8007EBA0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007EBA4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007EBA8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007EBAC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EBB0: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007EBB4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007EBB8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007EBBC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8007EBC0: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x8007EBC4: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8007EBC8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EBCC: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8007EBD0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8007EBD4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007EBD8: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8007EBDC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007EBE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007EBE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007EBE8: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007EBEC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EBF0: ori         $t6, $t9, 0x20
    ctx->r14 = ctx->r25 | 0X20;
    // 0x8007EBF4: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
    // 0x8007EBF8: lw          $t8, 0x278($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X278);
    // 0x8007EBFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007EC00: beq         $t8, $zero, L_8007EC10
    if (ctx->r24 == 0) {
        // 0x8007EC04: nop
    
            goto L_8007EC10;
    }
    // 0x8007EC04: nop

    // 0x8007EC08: bne         $t8, $at, L_8007EC24
    if (ctx->r24 != ctx->r1) {
        // 0x8007EC0C: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007EC24;
    }
    // 0x8007EC0C: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007EC10:
    // 0x8007EC10: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007EC14: nop

    // 0x8007EC18: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8007EC1C: sh          $t9, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r25;
    // 0x8007EC20: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007EC24:
    // 0x8007EC24: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007EC28: bne         $t6, $at, L_8007EDA4
    if (ctx->r14 != ctx->r1) {
        // 0x8007EC2C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007EDA4;
    }
    // 0x8007EC2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EC30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007EC34: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007EC38: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007EC3C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EC40: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x8007EC44: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007EC48: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007EC4C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007EC50: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x8007EC54: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8007EC58: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007EC5C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007EC60: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007EC64: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007EC68: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007EC6C: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007EC70: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007EC74: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007EC78: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007EC7C: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007EC80: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EC84: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007EC88: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007EC8C: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007EC90: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007EC94: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007EC98: or          $t9, $t7, $a2
    ctx->r25 = ctx->r15 | ctx->r6;
    // 0x8007EC9C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ECA0: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007ECA4: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007ECA8: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8007ECAC: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007ECB0: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007ECB4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ECB8: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x8007ECBC: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x8007ECC0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007ECC4: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007ECC8: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007ECCC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007ECD0: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007ECD4: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x8007ECD8: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8007ECDC: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007ECE0: or          $t6, $t9, $a1
    ctx->r14 = ctx->r25 | ctx->r5;
    // 0x8007ECE4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007ECE8: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007ECEC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007ECF0: or          $t8, $t6, $a2
    ctx->r24 = ctx->r14 | ctx->r6;
    // 0x8007ECF4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007ECF8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007ECFC: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007ED00: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007ED04: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007ED08: mflo        $t0
    ctx->r8 = lo;
    // 0x8007ED0C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007ED10: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007ED14: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007ED18: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007ED1C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007ED20: beq         $at, $zero, L_8007ED30
    if (ctx->r1 == 0) {
        // 0x8007ED24: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007ED30;
    }
    // 0x8007ED24: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ED28: b           L_8007ED34
    // 0x8007ED2C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007ED34;
    // 0x8007ED2C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007ED30:
    // 0x8007ED30: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007ED34:
    // 0x8007ED34: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007ED38: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8007ED3C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007ED40: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8007ED44: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8007ED48: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007ED4C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007ED50: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007ED54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007ED58: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007ED5C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ED60: lui         $at, 0xF570
    ctx->r1 = S32(0XF570 << 16);
    // 0x8007ED64: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007ED68: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8007ED6C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007ED70: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007ED74: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ED78: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007ED7C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007ED80: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007ED84: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007ED88: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007ED8C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ED90: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8007ED94: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007ED98: nop

    // 0x8007ED9C: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007EDA0: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007EDA4:
    // 0x8007EDA4: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
    // 0x8007EDA8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007EDAC: bne         $t7, $at, L_8007EF24
    if (ctx->r15 != ctx->r1) {
        // 0x8007EDB0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007EF24;
    }
    // 0x8007EDB0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EDB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007EDB8: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007EDBC: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007EDC0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EDC4: lui         $t9, 0xFD70
    ctx->r25 = S32(0XFD70 << 16);
    // 0x8007EDC8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007EDCC: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007EDD0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007EDD4: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x8007EDD8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8007EDDC: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007EDE0: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007EDE4: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007EDE8: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8007EDEC: sll         $v0, $t7, 18
    ctx->r2 = S32(ctx->r15 << 18);
    // 0x8007EDF0: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007EDF4: andi        $t7, $a1, 0x3
    ctx->r15 = ctx->r5 & 0X3;
    // 0x8007EDF8: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007EDFC: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007EE00: sll         $a1, $t7, 8
    ctx->r5 = S32(ctx->r15 << 8);
    // 0x8007EE04: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EE08: or          $t7, $v0, $at
    ctx->r15 = ctx->r2 | ctx->r1;
    // 0x8007EE0C: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007EE10: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007EE14: sll         $a2, $t8, 4
    ctx->r6 = S32(ctx->r24 << 4);
    // 0x8007EE18: or          $t9, $t7, $v1
    ctx->r25 = ctx->r15 | ctx->r3;
    // 0x8007EE1C: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007EE20: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007EE24: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EE28: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007EE2C: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x8007EE30: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EE34: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8007EE38: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8007EE3C: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007EE40: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007EE44: or          $t8, $v0, $v1
    ctx->r24 = ctx->r2 | ctx->r3;
    // 0x8007EE48: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007EE4C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8007EE50: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007EE54: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007EE58: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007EE5C: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007EE60: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007EE64: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007EE68: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007EE6C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007EE70: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007EE74: mflo        $t2
    ctx->r10 = lo;
    // 0x8007EE78: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x8007EE7C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007EE80: sra         $t8, $t0, 1
    ctx->r24 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007EE84: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007EE88: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007EE8C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8007EE90: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007EE94: beq         $at, $zero, L_8007EEA4
    if (ctx->r1 == 0) {
        // 0x8007EE98: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007EEA4;
    }
    // 0x8007EE98: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EE9C: b           L_8007EEA8
    // 0x8007EEA0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007EEA8;
    // 0x8007EEA0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007EEA4:
    // 0x8007EEA4: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007EEA8:
    // 0x8007EEA8: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007EEAC: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007EEB0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EEB4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8007EEB8: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007EEBC: addiu       $t7, $t5, 0x7
    ctx->r15 = ADD32(ctx->r13, 0X7);
    // 0x8007EEC0: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8007EEC4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007EEC8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007EECC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007EED0: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007EED4: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x8007EED8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EEDC: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8007EEE0: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8007EEE4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007EEE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007EEEC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007EEF0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EEF4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EEF8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EEFC: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007EF00: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007EF04: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007EF08: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007EF0C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EF10: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8007EF14: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007EF18: nop

    // 0x8007EF1C: ori         $t6, $t7, 0x4
    ctx->r14 = ctx->r15 | 0X4;
    // 0x8007EF20: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007EF24:
    // 0x8007EF24: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
    // 0x8007EF28: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007EF2C: bne         $t9, $at, L_8007F0A8
    if (ctx->r25 != ctx->r1) {
        // 0x8007EF30: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007F0A8;
    }
    // 0x8007EF30: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EF34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007EF38: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007EF3C: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007EF40: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EF44: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x8007EF48: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007EF4C: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007EF50: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007EF54: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x8007EF58: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007EF5C: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007EF60: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007EF64: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007EF68: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007EF6C: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007EF70: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007EF74: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007EF78: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007EF7C: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007EF80: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007EF84: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EF88: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007EF8C: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007EF90: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007EF94: or          $t8, $t9, $v1
    ctx->r24 = ctx->r25 | ctx->r3;
    // 0x8007EF98: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007EF9C: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007EFA0: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007EFA4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EFA8: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007EFAC: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007EFB0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EFB4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007EFB8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007EFBC: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007EFC0: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007EFC4: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007EFC8: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007EFCC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007EFD0: or          $t6, $t7, $a1
    ctx->r14 = ctx->r15 | ctx->r5;
    // 0x8007EFD4: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007EFD8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007EFDC: or          $t9, $t6, $a2
    ctx->r25 = ctx->r14 | ctx->r6;
    // 0x8007EFE0: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007EFE4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8007EFE8: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007EFEC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007EFF0: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8007EFF4: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007EFF8: mflo        $t0
    ctx->r8 = lo;
    // 0x8007EFFC: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007F000: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007F004: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007F008: sra         $t7, $t0, 2
    ctx->r15 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007F00C: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8007F010: sra         $t9, $ra, 3
    ctx->r25 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007F014: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007F018: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007F01C: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x8007F020: sll         $ra, $t6, 9
    ctx->r31 = S32(ctx->r14 << 9);
    // 0x8007F024: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007F028: beq         $at, $zero, L_8007F038
    if (ctx->r1 == 0) {
        // 0x8007F02C: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007F038;
    }
    // 0x8007F02C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F030: b           L_8007F03C
    // 0x8007F034: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007F03C;
    // 0x8007F034: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007F038:
    // 0x8007F038: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007F03C:
    // 0x8007F03C: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007F040: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8007F044: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007F048: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007F04C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007F050: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8007F054: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F058: lui         $at, 0xF560
    ctx->r1 = S32(0XF560 << 16);
    // 0x8007F05C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007F060: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007F064: or          $t7, $ra, $at
    ctx->r15 = ctx->r31 | ctx->r1;
    // 0x8007F068: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007F06C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F070: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007F074: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007F078: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F07C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007F080: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8007F084: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007F088: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007F08C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007F090: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F094: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8007F098: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007F09C: nop

    // 0x8007F0A0: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8007F0A4: sh          $t9, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r25;
L_8007F0A8:
    // 0x8007F0A8: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007F0AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007F0B0: bne         $t6, $at, L_8007F218
    if (ctx->r14 != ctx->r1) {
        // 0x8007F0B4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007F218;
    }
    // 0x8007F0B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007F0B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F0BC: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007F0C0: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007F0C4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F0C8: lui         $t8, 0xFD90
    ctx->r24 = S32(0XFD90 << 16);
    // 0x8007F0CC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007F0D0: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007F0D4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F0D8: lui         $t9, 0xF590
    ctx->r25 = S32(0XF590 << 16);
    // 0x8007F0DC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8007F0E0: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007F0E4: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007F0E8: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007F0EC: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007F0F0: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007F0F4: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007F0F8: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007F0FC: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007F100: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007F104: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007F108: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007F10C: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007F110: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007F114: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007F118: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007F11C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F120: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007F124: or          $t9, $t7, $a2
    ctx->r25 = ctx->r15 | ctx->r6;
    // 0x8007F128: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F12C: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007F130: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8007F134: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F138: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007F13C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007F140: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007F144: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007F148: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007F14C: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007F150: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007F154: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8007F158: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007F15C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007F160: or          $t6, $t9, $a2
    ctx->r14 = ctx->r25 | ctx->r6;
    // 0x8007F164: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007F168: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007F16C: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007F170: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007F174: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8007F178: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007F17C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007F180: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8007F184: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007F188: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8007F18C: addiu       $t4, $t5, 0x7
    ctx->r12 = ADD32(ctx->r13, 0X7);
    // 0x8007F190: sra         $t6, $t4, 3
    ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007F194: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007F198: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007F19C: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007F1A0: sll         $t4, $t9, 9
    ctx->r12 = S32(ctx->r25 << 9);
    // 0x8007F1A4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007F1A8: beq         $at, $zero, L_8007F1B8
    if (ctx->r1 == 0) {
        // 0x8007F1AC: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007F1B8;
    }
    // 0x8007F1AC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F1B0: b           L_8007F1BC
    // 0x8007F1B4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007F1BC;
    // 0x8007F1B4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007F1B8:
    // 0x8007F1B8: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007F1BC:
    // 0x8007F1BC: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007F1C0: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007F1C4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007F1C8: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8007F1CC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007F1D0: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007F1D4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F1D8: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8007F1DC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007F1E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007F1E4: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x8007F1E8: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007F1EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F1F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007F1F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007F1F8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F1FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007F200: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007F204: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007F208: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007F20C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007F210: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F214: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
L_8007F218:
    // 0x8007F218: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
    // 0x8007F21C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007F220: bne         $t7, $at, L_8007F38C
    if (ctx->r15 != ctx->r1) {
        // 0x8007F224: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007F38C;
    }
    // 0x8007F224: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007F228: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F22C: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007F230: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007F234: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F238: lui         $t6, 0xFD90
    ctx->r14 = S32(0XFD90 << 16);
    // 0x8007F23C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007F240: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007F244: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F248: lui         $t8, 0xF590
    ctx->r24 = S32(0XF590 << 16);
    // 0x8007F24C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007F250: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007F254: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007F258: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007F25C: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8007F260: sll         $v0, $t7, 18
    ctx->r2 = S32(ctx->r15 << 18);
    // 0x8007F264: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007F268: andi        $t7, $a1, 0x3
    ctx->r15 = ctx->r5 & 0X3;
    // 0x8007F26C: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x8007F270: sll         $v1, $t9, 14
    ctx->r3 = S32(ctx->r25 << 14);
    // 0x8007F274: sll         $a1, $t7, 8
    ctx->r5 = S32(ctx->r15 << 8);
    // 0x8007F278: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007F27C: or          $t7, $v0, $at
    ctx->r15 = ctx->r2 | ctx->r1;
    // 0x8007F280: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007F284: sll         $a2, $t9, 4
    ctx->r6 = S32(ctx->r25 << 4);
    // 0x8007F288: or          $t6, $t7, $v1
    ctx->r14 = ctx->r15 | ctx->r3;
    // 0x8007F28C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F290: or          $t9, $t6, $a1
    ctx->r25 = ctx->r14 | ctx->r5;
    // 0x8007F294: or          $t8, $t9, $a2
    ctx->r24 = ctx->r25 | ctx->r6;
    // 0x8007F298: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F29C: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007F2A0: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8007F2A4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F2A8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8007F2AC: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8007F2B0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007F2B4: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007F2B8: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007F2BC: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8007F2C0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8007F2C4: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007F2C8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8007F2CC: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8007F2D0: or          $t7, $t8, $a2
    ctx->r15 = ctx->r24 | ctx->r6;
    // 0x8007F2D4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007F2D8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007F2DC: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x8007F2E0: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8007F2E4: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8007F2E8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007F2EC: mflo        $t0
    ctx->r8 = lo;
    // 0x8007F2F0: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007F2F4: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007F2F8: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007F2FC: sra         $t9, $t0, 2
    ctx->r25 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007F300: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8007F304: sra         $t7, $ra, 3
    ctx->r15 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007F308: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8007F30C: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007F310: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8007F314: sll         $ra, $t8, 9
    ctx->r31 = S32(ctx->r24 << 9);
    // 0x8007F318: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8007F31C: beq         $at, $zero, L_8007F32C
    if (ctx->r1 == 0) {
        // 0x8007F320: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007F32C;
    }
    // 0x8007F320: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F324: b           L_8007F330
    // 0x8007F328: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007F330;
    // 0x8007F328: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007F32C:
    // 0x8007F32C: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007F330:
    // 0x8007F330: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007F334: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8007F338: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007F33C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007F340: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007F344: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8007F348: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F34C: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8007F350: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8007F354: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007F358: or          $t9, $ra, $at
    ctx->r25 = ctx->r31 | ctx->r1;
    // 0x8007F35C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007F360: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F364: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007F368: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007F36C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F370: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007F374: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007F378: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007F37C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007F380: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007F384: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007F388: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
L_8007F38C:
    // 0x8007F38C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x8007F390: nop

    // 0x8007F394: subu        $t7, $a3, $t9
    ctx->r15 = SUB32(ctx->r7, ctx->r25);
    // 0x8007F398: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8007F39C: sh          $t8, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r24;
L_8007F3A0:
    // 0x8007F3A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007F3A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007F3A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007F3AC: jr          $ra
    // 0x8007F3B0: addiu       $sp, $sp, 0x280
    ctx->r29 = ADD32(ctx->r29, 0X280);
    return;
    // 0x8007F3B0: addiu       $sp, $sp, 0x280
    ctx->r29 = ADD32(ctx->r29, 0X280);
;}
RECOMP_FUNC void read_time_data_from_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074270: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074274: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074278: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007427C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074280: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80074284: jal         0x80075B34
    // 0x80074288: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80074288: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007428C: beq         $v0, $zero, L_800742B0
    if (ctx->r2 == 0) {
        // 0x80074290: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800742B0;
    }
    // 0x80074290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074298: jal         0x80075D44
    // 0x8007429C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x8007429C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x800742A0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800742A4: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x800742A8: b           L_80074390
    // 0x800742AC: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
        goto L_80074390;
    // 0x800742AC: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
L_800742B0:
    // 0x800742B0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800742B4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800742B8: addiu       $a1, $a1, 0x7C20
    ctx->r5 = ADD32(ctx->r5, 0X7C20);
    // 0x800742BC: jal         0x80076740
    // 0x800742C0: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x800742C0: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x800742C4: bne         $v0, $zero, L_8007436C
    if (ctx->r2 != 0) {
        // 0x800742C8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8007436C;
    }
    // 0x800742C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800742CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800742D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800742D4: jal         0x80076B7C
    // 0x800742D8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x800742D8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x800742DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800742E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800742E4: bne         $a0, $zero, L_800742F0
    if (ctx->r4 != 0) {
        // 0x800742E8: nop
    
            goto L_800742F0;
    }
    // 0x800742E8: nop

    // 0x800742EC: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_800742F0:
    // 0x800742F0: bne         $v1, $zero, L_8007436C
    if (ctx->r3 != 0) {
        // 0x800742F4: nop
    
            goto L_8007436C;
    }
    // 0x800742F4: nop

    // 0x800742F8: jal         0x80070EDC
    // 0x800742FC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800742FC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x80074300: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80074304: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80074308: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8007430C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074310: jal         0x80076868
    // 0x80074314: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80074314: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80074318: bne         $v0, $zero, L_80074358
    if (ctx->r2 != 0) {
        // 0x8007431C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80074358;
    }
    // 0x8007431C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80074320: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80074324: lui         $at, 0x5449
    ctx->r1 = S32(0X5449 << 16);
    // 0x80074328: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8007432C: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x80074330: bne         $t7, $at, L_80074358
    if (ctx->r15 != ctx->r1) {
        // 0x80074334: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80074358;
    }
    // 0x80074334: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x80074338: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8007433C: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80074340: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80074344: jal         0x800737E0
    // 0x80074348: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80073588(rdram, ctx);
        goto after_6;
    // 0x80074348: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_6:
    // 0x8007434C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074350: b           L_8007435C
    // 0x80074354: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_8007435C;
    // 0x80074354: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80074358:
    // 0x80074358: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_8007435C:
    // 0x8007435C: jal         0x80071380
    // 0x80074360: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80074360: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x80074364: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074368: nop

L_8007436C:
    // 0x8007436C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074370: jal         0x80075D44
    // 0x80074374: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x80074374: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_8:
    // 0x80074378: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8007437C: sll         $t8, $s0, 30
    ctx->r24 = S32(ctx->r16 << 30);
    // 0x80074380: beq         $v1, $zero, L_80074390
    if (ctx->r3 == 0) {
        // 0x80074384: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80074390;
    }
    // 0x80074384: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80074388: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x8007438C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80074390:
    // 0x80074390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074394: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074398: jr          $ra
    // 0x8007439C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007439C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void music_current_sequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001918: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000191C: lbu         $v1, 0x6284($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6284);
    // 0x80001920: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001924: beq         $v1, $zero, L_8000194C
    if (ctx->r3 == 0) {
        // 0x80001928: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000194C;
    }
    // 0x80001928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000192C: lw          $t6, -0x3460($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3460);
    // 0x80001930: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001934: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80001938: nop

    // 0x8000193C: bne         $t7, $at, L_8000194C
    if (ctx->r15 != ctx->r1) {
        // 0x80001940: nop
    
            goto L_8000194C;
    }
    // 0x80001940: nop

    // 0x80001944: jr          $ra
    // 0x80001948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80001948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000194C:
    // 0x8000194C: jr          $ra
    // 0x80001950: nop

    return;
    // 0x80001950: nop

;}
RECOMP_FUNC void rain_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE128: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AE12C: lw          $t6, 0x31F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31F0);
    // 0x800AE130: lui         $at, 0x4490
    ctx->r1 = S32(0X4490 << 16);
    // 0x800AE134: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x800AE138: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800AE13C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AE140: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800AE144: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AE148: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800AE14C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800AE150: lw          $t8, -0x7E24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E24);
    // 0x800AE154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AE158: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800AE15C: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x800AE160: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    // 0x800AE164: jal         0x80070A04
    // 0x800AE168: nop

    sins_f(rdram, ctx);
        goto after_0;
    // 0x800AE168: nop

    after_0:
    // 0x800AE16C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800AE170: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800AE174: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800AE178: lw          $t9, -0x7E24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7E24);
    // 0x800AE17C: nop

    // 0x800AE180: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    // 0x800AE184: jal         0x80070A38
    // 0x800AE188: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800AE188: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800AE18C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800AE190: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AE194: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800AE198: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800AE19C: lw          $v0, -0x7E24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7E24);
    // 0x800AE1A0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AE1A4: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800AE1A8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AE1AC: addiu       $v1, $v1, 0x3224
    ctx->r3 = ADD32(ctx->r3, 0X3224);
    // 0x800AE1B0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800AE1B4: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AE1B8: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x800AE1BC: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AE1C0: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800AE1C4: sub.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800AE1C8: beq         $a0, $zero, L_800AE1EC
    if (ctx->r4 == 0) {
        // 0x800AE1CC: add.s       $f18, $f6, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_800AE1EC;
    }
    // 0x800AE1CC: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AE1D0: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800AE1D4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800AE1D8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800AE1DC: jal         0x800096D8
    // 0x800AE1E0: nop

    audspat_point_set_position(rdram, ctx);
        goto after_2;
    // 0x800AE1E0: nop

    after_2:
    // 0x800AE1E4: b           L_800AE210
    // 0x800AE1E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800AE210;
    // 0x800AE1E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AE1EC:
    // 0x800AE1EC: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800AE1F0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800AE1F4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800AE1F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800AE1FC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800AE200: addiu       $a0, $zero, 0x23E
    ctx->r4 = ADD32(0, 0X23E);
    // 0x800AE204: jal         0x80009558
    // 0x800AE208: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_3;
    // 0x800AE208: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_3:
    // 0x800AE20C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800AE210:
    // 0x800AE210: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800AE214: jr          $ra
    // 0x800AE218: nop

    return;
    // 0x800AE218: nop

;}
RECOMP_FUNC void racer_boss_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CD08: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005CD0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005CD10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005CD14: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8005CD18: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8005CD1C: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8005CD20: jal         0x8006ECD0
    // 0x8005CD24: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8005CD24: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    after_0:
    // 0x8005CD28: lbu         $t8, 0x48($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X48);
    // 0x8005CD2C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005CD30: sllv        $t1, $t9, $t8
    ctx->r9 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x8005CD34: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8005CD38: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8005CD3C: jal         0x8001E2D0
    // 0x8005CD40: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8005CD40: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_1:
    // 0x8005CD44: lb          $t4, 0x5($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X5);
    // 0x8005CD48: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x8005CD4C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8005CD50: lb          $t5, 0x6($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X6);
    // 0x8005CD54: nop

    // 0x8005CD58: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8005CD5C: lb          $t6, 0x7($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X7);
    // 0x8005CD60: jal         0x8001E2D0
    // 0x8005CD64: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    get_misc_asset(rdram, ctx);
        goto after_2;
    // 0x8005CD64: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_2:
    // 0x8005CD68: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005CD6C: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x8005CD70: lbu         $a0, 0x49($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X49);
    // 0x8005CD74: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005CD78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005CD7C: beq         $a0, $t7, L_8005CD98
    if (ctx->r4 == ctx->r15) {
        // 0x8005CD80: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8005CD98;
    }
    // 0x8005CD80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005CD84: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8005CD88:
    // 0x8005CD88: lb          $t9, 0x2($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X2);
    // 0x8005CD8C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8005CD90: bne         $a0, $t9, L_8005CD88
    if (ctx->r4 != ctx->r25) {
        // 0x8005CD94: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8005CD88;
    }
    // 0x8005CD94: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8005CD98:
    // 0x8005CD98: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8005CD9C: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
    // 0x8005CDA0: lh          $t5, 0x1AC($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X1AC);
    // 0x8005CDA4: addu        $t8, $s0, $v0
    ctx->r24 = ADD32(ctx->r16, ctx->r2);
    // 0x8005CDA8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005CDAC: lb          $s0, 0x1($t8)
    ctx->r16 = MEM_B(ctx->r24, 0X1);
    // 0x8005CDB0: bne         $t6, $v1, L_8005D1C8
    if (ctx->r14 != ctx->r3) {
        // 0x8005CDB4: sw          $t5, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r13;
            goto L_8005D1C8;
    }
    // 0x8005CDB4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8005CDB8: bne         $t5, $v1, L_8005CDE0
    if (ctx->r13 != ctx->r3) {
        // 0x8005CDBC: addiu       $a0, $zero, 0x3E
        ctx->r4 = ADD32(0, 0X3E);
            goto L_8005CDE0;
    }
    // 0x8005CDBC: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    // 0x8005CDC0: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x8005CDC4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8005CDC8: jal         0x80000B34
    // 0x8005CDCC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    music_play(rdram, ctx);
        goto after_3;
    // 0x8005CDCC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_3:
    // 0x8005CDD0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005CDD4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005CDD8: b           L_8005CDFC
    // 0x8005CDDC: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
        goto L_8005CDFC;
    // 0x8005CDDC: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
L_8005CDE0:
    // 0x8005CDE0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8005CDE4: jal         0x80000B34
    // 0x8005CDE8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    music_play(rdram, ctx);
        goto after_4;
    // 0x8005CDE8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_4:
    // 0x8005CDEC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005CDF0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005CDF4: nop

    // 0x8005CDF8: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
L_8005CDFC:
    // 0x8005CDFC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005CE00: beq         $v1, $zero, L_8005CE0C
    if (ctx->r3 == 0) {
        // 0x8005CE04: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005CE0C;
    }
    // 0x8005CE04: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005CE08: bne         $v1, $at, L_8005CF98
    if (ctx->r3 != ctx->r1) {
        // 0x8005CE0C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8005CF98;
    }
L_8005CE0C:
    // 0x8005CE0C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005CE10: bne         $t0, $t3, L_8005CE4C
    if (ctx->r8 != ctx->r11) {
        // 0x8005CE14: nop
    
            goto L_8005CE4C;
    }
    // 0x8005CE14: nop

    // 0x8005CE18: lhu         $t7, 0xC($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0XC);
    // 0x8005CE1C: lbu         $t4, 0x49($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X49);
    // 0x8005CE20: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
    // 0x8005CE24: or          $t9, $t7, $t1
    ctx->r25 = ctx->r15 | ctx->r9;
    // 0x8005CE28: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8005CE2C: sh          $t9, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r25;
    // 0x8005CE30: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x8005CE34: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8005CE38: nop

    // 0x8005CE3C: ori         $t7, $t5, 0x2
    ctx->r15 = ctx->r13 | 0X2;
    // 0x8005CE40: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005CE44: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
    // 0x8005CE48: nop

L_8005CE4C:
    // 0x8005CE4C: bne         $v1, $zero, L_8005CECC
    if (ctx->r3 != 0) {
        // 0x8005CE50: nop
    
            goto L_8005CECC;
    }
    // 0x8005CE50: nop

    // 0x8005CE54: bne         $t0, $t3, L_8005CEA0
    if (ctx->r8 != ctx->r11) {
        // 0x8005CE58: addiu       $a0, $zero, -0xA
        ctx->r4 = ADD32(0, -0XA);
            goto L_8005CEA0;
    }
    // 0x8005CE58: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x8005CE5C: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x8005CE60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CE64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CE68: jal         0x8006C3EC
    // 0x8005CE6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_5;
    // 0x8005CE6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8005CE70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CE74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CE78: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CE7C: jal         0x8006C3EC
    // 0x8005CE80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_6;
    // 0x8005CE80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8005CE84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CE88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CE8C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CE90: jal         0x8006C3EC
    // 0x8005CE94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    level_properties_push(rdram, ctx);
        goto after_7;
    // 0x8005CE94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x8005CE98: b           L_8005CF60
    // 0x8005CE9C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_8005CF60;
    // 0x8005CE9C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CEA0:
    // 0x8005CEA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CEA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CEA8: jal         0x8006C3EC
    // 0x8005CEAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_8;
    // 0x8005CEAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x8005CEB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CEB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CEB8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CEBC: jal         0x8006C3EC
    // 0x8005CEC0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    level_properties_push(rdram, ctx);
        goto after_9;
    // 0x8005CEC0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_9:
    // 0x8005CEC4: b           L_8005CF60
    // 0x8005CEC8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_8005CF60;
    // 0x8005CEC8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CECC:
    // 0x8005CECC: bne         $t0, $t3, L_8005CF38
    if (ctx->r8 != ctx->r11) {
        // 0x8005CED0: addiu       $a0, $zero, -0xA
        ctx->r4 = ADD32(0, -0XA);
            goto L_8005CF38;
    }
    // 0x8005CED0: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x8005CED4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8005CED8: jal         0x8009EFBC
    // 0x8005CEDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    set_eeprom_settings_value(rdram, ctx);
        goto after_10;
    // 0x8005CEDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8005CEE0: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x8005CEE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CEE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CEEC: jal         0x8006C3EC
    // 0x8005CEF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_11;
    // 0x8005CEF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x8005CEF4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8005CEF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CEFC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CF00: jal         0x8006C3EC
    // 0x8005CF04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_12;
    // 0x8005CF04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x8005CF08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8005CF0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CF10: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CF14: jal         0x8006C3EC
    // 0x8005CF18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_13;
    // 0x8005CF18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x8005CF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CF20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CF24: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CF28: jal         0x8006C3EC
    // 0x8005CF2C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    level_properties_push(rdram, ctx);
        goto after_14;
    // 0x8005CF2C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x8005CF30: b           L_8005CF60
    // 0x8005CF34: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_8005CF60;
    // 0x8005CF34: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CF38:
    // 0x8005CF38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CF3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CF40: jal         0x8006C3EC
    // 0x8005CF44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_15;
    // 0x8005CF44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x8005CF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CF4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CF50: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CF54: jal         0x8006C3EC
    // 0x8005CF58: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    level_properties_push(rdram, ctx);
        goto after_16;
    // 0x8005CF58: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_16:
    // 0x8005CF5C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CF60:
    // 0x8005CF60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CF64: bne         $t9, $at, L_8005CF7C
    if (ctx->r25 != ctx->r1) {
        // 0x8005CF68: nop
    
            goto L_8005CF7C;
    }
    // 0x8005CF68: nop

    // 0x8005CF6C: jal         0x8006F380
    // 0x8005CF70: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    level_transition_begin(rdram, ctx);
        goto after_17;
    // 0x8005CF70: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_17:
    // 0x8005CF74: b           L_8005CF88
    // 0x8005CF78: lb          $v0, 0x43($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X43);
        goto L_8005CF88;
    // 0x8005CF78: lb          $v0, 0x43($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X43);
L_8005CF7C:
    // 0x8005CF7C: jal         0x8006F380
    // 0x8005CF80: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    level_transition_begin(rdram, ctx);
        goto after_18;
    // 0x8005CF80: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_18:
    // 0x8005CF84: lb          $v0, 0x43($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X43);
L_8005CF88:
    // 0x8005CF88: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8005CF8C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8005CF90: b           L_8005D1D8
    // 0x8005CF94: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
        goto L_8005D1D8;
    // 0x8005CF94: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
L_8005CF98:
    // 0x8005CF98: lbu         $t7, 0x49($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X49);
    // 0x8005CF9C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8005CFA0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8005CFA4: addu        $v0, $t5, $t9
    ctx->r2 = ADD32(ctx->r13, ctx->r25);
    // 0x8005CFA8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005CFAC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005CFB0: andi        $t4, $v1, 0x2
    ctx->r12 = ctx->r3 & 0X2;
    // 0x8005CFB4: beq         $t4, $zero, L_8005D01C
    if (ctx->r12 == 0) {
        // 0x8005CFB8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005D01C;
    }
    // 0x8005CFB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CFBC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005CFC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CFC4: bne         $t8, $at, L_8005CFE4
    if (ctx->r24 != ctx->r1) {
        // 0x8005CFC8: nop
    
            goto L_8005CFE4;
    }
    // 0x8005CFC8: nop

    // 0x8005CFCC: jal         0x8006F380
    // 0x8005CFD0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    level_transition_begin(rdram, ctx);
        goto after_19;
    // 0x8005CFD0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_19:
    // 0x8005CFD4: jal         0x8000E128
    // 0x8005CFD8: nop

    instShowBearBar(rdram, ctx);
        goto after_20;
    // 0x8005CFD8: nop

    after_20:
    // 0x8005CFDC: b           L_8005D008
    // 0x8005CFE0: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
        goto L_8005D008;
    // 0x8005CFE0: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005CFE4:
    // 0x8005CFE4: jal         0x8006F380
    // 0x8005CFE8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    level_transition_begin(rdram, ctx);
        goto after_21;
    // 0x8005CFE8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_21:
    // 0x8005CFEC: jal         0x8009F1C4
    // 0x8005CFF0: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_22;
    // 0x8005CFF0: nop

    after_22:
    // 0x8005CFF4: beq         $v0, $zero, L_8005D008
    if (ctx->r2 == 0) {
        // 0x8005CFF8: lb          $t6, 0x43($sp)
        ctx->r14 = MEM_B(ctx->r29, 0X43);
            goto L_8005D008;
    }
    // 0x8005CFF8: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
    // 0x8005CFFC: jal         0x8006F5D8
    // 0x8005D000: nop

    swap_lead_player(rdram, ctx);
        goto after_23;
    // 0x8005D000: nop

    after_23:
    // 0x8005D004: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005D008:
    // 0x8005D008: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8005D00C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8005D010: sb          $t9, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r25;
    // 0x8005D014: b           L_8005D1D8
    // 0x8005D018: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
        goto L_8005D1D8;
    // 0x8005D018: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
L_8005D01C:
    // 0x8005D01C: bne         $t8, $at, L_8005D180
    if (ctx->r24 != ctx->r1) {
        // 0x8005D020: addiu       $a0, $zero, -0xA
        ctx->r4 = ADD32(0, -0XA);
            goto L_8005D180;
    }
    // 0x8005D020: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x8005D024: ori         $t6, $v1, 0x2
    ctx->r14 = ctx->r3 | 0X2;
    // 0x8005D028: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005D02C: lhu         $t0, 0xC($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC);
    // 0x8005D030: sll         $t9, $t1, 6
    ctx->r25 = S32(ctx->r9 << 6);
    // 0x8005D034: and         $t7, $t0, $t1
    ctx->r15 = ctx->r8 & ctx->r9;
    // 0x8005D038: bne         $t7, $zero, L_8005D078
    if (ctx->r15 != 0) {
        // 0x8005D03C: and         $t4, $t0, $t9
        ctx->r12 = ctx->r8 & ctx->r25;
            goto L_8005D078;
    }
    // 0x8005D03C: and         $t4, $t0, $t9
    ctx->r12 = ctx->r8 & ctx->r25;
    // 0x8005D040: or          $t5, $t0, $t1
    ctx->r13 = ctx->r8 | ctx->r9;
    // 0x8005D044: sh          $t5, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r13;
    // 0x8005D048: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005D04C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005D054: jal         0x8006C3EC
    // 0x8005D058: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_24;
    // 0x8005D058: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_24:
    // 0x8005D05C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D060: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005D064: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D068: jal         0x8006C3EC
    // 0x8005D06C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    level_properties_push(rdram, ctx);
        goto after_25;
    // 0x8005D06C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_25:
    // 0x8005D070: b           L_8005D168
    // 0x8005D074: nop

        goto L_8005D168;
    // 0x8005D074: nop

L_8005D078:
    // 0x8005D078: bne         $t4, $zero, L_8005D144
    if (ctx->r12 != 0) {
        // 0x8005D07C: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8005D144;
    }
    // 0x8005D07C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005D080: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
    // 0x8005D084: or          $t8, $t0, $t9
    ctx->r24 = ctx->r8 | ctx->r25;
    // 0x8005D088: sh          $t8, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r24;
    // 0x8005D08C: blez        $v1, L_8005D0C0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005D090: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8005D0C0;
    }
    // 0x8005D090: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8005D094: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8005D098: beq         $at, $zero, L_8005D0C0
    if (ctx->r1 == 0) {
        // 0x8005D09C: nop
    
            goto L_8005D0C0;
    }
    // 0x8005D09C: nop

    // 0x8005D0A0: lbu         $t1, 0x17($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X17);
    // 0x8005D0A4: nop

    // 0x8005D0A8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005D0AC: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8005D0B0: bne         $at, $zero, L_8005D0BC
    if (ctx->r1 != 0) {
        // 0x8005D0B4: nop
    
            goto L_8005D0BC;
    }
    // 0x8005D0B4: nop

    // 0x8005D0B8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_8005D0BC:
    // 0x8005D0BC: sb          $t1, 0x17($t2)
    MEM_B(0X17, ctx->r10) = ctx->r9;
L_8005D0C0:
    // 0x8005D0C0: beq         $t1, $zero, L_8005D118
    if (ctx->r9 == 0) {
        // 0x8005D0C4: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8005D118;
    }
    // 0x8005D0C4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005D0C8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005D0CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D0D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005D0D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005D0D8: jal         0x8006C3EC
    // 0x8005D0DC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    level_properties_push(rdram, ctx);
        goto after_26;
    // 0x8005D0DC: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_26:
    // 0x8005D0E0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005D0E4: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8005D0E8: lbu         $a3, 0x17($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X17);
    // 0x8005D0EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D0F0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D0F4: jal         0x8006C3EC
    // 0x8005D0F8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    level_properties_push(rdram, ctx);
        goto after_27;
    // 0x8005D0F8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    after_27:
    // 0x8005D0FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D100: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8005D104: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D108: jal         0x8006C3EC
    // 0x8005D10C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    level_properties_push(rdram, ctx);
        goto after_28;
    // 0x8005D10C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_28:
    // 0x8005D110: b           L_8005D168
    // 0x8005D114: nop

        goto L_8005D168;
    // 0x8005D114: nop

L_8005D118:
    // 0x8005D118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D11C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005D120: jal         0x8006C3EC
    // 0x8005D124: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_29;
    // 0x8005D124: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_29:
    // 0x8005D128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D12C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005D130: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D134: jal         0x8006C3EC
    // 0x8005D138: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    level_properties_push(rdram, ctx);
        goto after_30;
    // 0x8005D138: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_30:
    // 0x8005D13C: b           L_8005D168
    // 0x8005D140: nop

        goto L_8005D168;
    // 0x8005D140: nop

L_8005D144:
    // 0x8005D144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D148: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005D14C: jal         0x8006C3EC
    // 0x8005D150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_31;
    // 0x8005D150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_31:
    // 0x8005D154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D158: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005D15C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D160: jal         0x8006C3EC
    // 0x8005D164: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    level_properties_push(rdram, ctx);
        goto after_32;
    // 0x8005D164: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_32:
L_8005D168:
    // 0x8005D168: jal         0x8006F380
    // 0x8005D16C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    level_transition_begin(rdram, ctx);
        goto after_33;
    // 0x8005D16C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_33:
    // 0x8005D170: jal         0x8000E128
    // 0x8005D174: nop

    instShowBearBar(rdram, ctx);
        goto after_34;
    // 0x8005D174: nop

    after_34:
    // 0x8005D178: b           L_8005D1B0
    // 0x8005D17C: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
        goto L_8005D1B0;
    // 0x8005D17C: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005D180:
    // 0x8005D180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005D188: jal         0x8006C3EC
    // 0x8005D18C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_35;
    // 0x8005D18C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_35:
    // 0x8005D190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D194: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8005D198: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005D19C: jal         0x8006C3EC
    // 0x8005D1A0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    level_properties_push(rdram, ctx);
        goto after_36;
    // 0x8005D1A0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_36:
    // 0x8005D1A4: jal         0x8006F380
    // 0x8005D1A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    level_transition_begin(rdram, ctx);
        goto after_37;
    // 0x8005D1A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_37:
    // 0x8005D1AC: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005D1B0:
    // 0x8005D1B0: nop

    // 0x8005D1B4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005D1B8: jal         0x8009C6E4
    // 0x8005D1BC: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    get_save_file_index(rdram, ctx);
        goto after_38;
    // 0x8005D1BC: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    after_38:
    // 0x8005D1C0: jal         0x8006EE88
    // 0x8005D1C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_39;
    // 0x8005D1C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_39:
L_8005D1C8:
    // 0x8005D1C8: lb          $t5, 0x43($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X43);
    // 0x8005D1CC: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8005D1D0: nop

    // 0x8005D1D4: sb          $t5, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r13;
L_8005D1D8:
    // 0x8005D1D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D1DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D1E0: jr          $ra
    // 0x8005D1E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8005D1E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void sound_seqplayer_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002224: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80002228: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8000222C: addiu       $a2, $a2, 0x6268
    ctx->r6 = ADD32(ctx->r6, 0X6268);
    // 0x80002230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002234: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80002238: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8000223C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80002240: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80002244: sb          $a0, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r4;
    // 0x80002248: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8000224C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80002250: sb          $t8, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r24;
    // 0x80002254: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80002258: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8000225C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80002260: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80002264: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80002268: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000226C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002270: jal         0x800C7D50
    // 0x80002274: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80002274: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80002278: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8000227C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80002280: jal         0x800624D0
    // 0x80002284: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    alCSPNew(rdram, ctx);
        goto after_1;
    // 0x80002284: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80002288: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8000228C: lw          $t0, 0x6290($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6290);
    // 0x80002290: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80002294: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x80002298: jal         0x800C7FC0
    // 0x8000229C: nop

    alCSPSetBank(rdram, ctx);
        goto after_2;
    // 0x8000229C: nop

    after_2:
    // 0x800022A0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800022A4: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x800022A8: sb          $t1, 0x36($v0)
    MEM_B(0X36, ctx->r2) = ctx->r9;
    // 0x800022AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800022B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800022B4: jr          $ra
    // 0x800022B8: nop

    return;
    // 0x800022B8: nop

;}
RECOMP_FUNC void audspat_point_stop_by_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A2E8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000A2EC: addiu       $a3, $a3, -0x33B0
    ctx->r7 = ADD32(ctx->r7, -0X33B0);
    // 0x8000A2F0: lhu         $t6, 0x0($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X0);
    // 0x8000A2F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A2F8: beq         $t6, $zero, L_8000A404
    if (ctx->r14 == 0) {
        // 0x8000A2FC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000A404;
    }
    // 0x8000A2FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A300: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000A304: lw          $t7, -0x5E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E3C);
    // 0x8000A308: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x8000A30C: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x8000A310: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A314: nop

    // 0x8000A318: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x8000A31C: nop

    // 0x8000A320: beq         $a0, $zero, L_8000A34C
    if (ctx->r4 == 0) {
        // 0x8000A324: nop
    
            goto L_8000A34C;
    }
    // 0x8000A324: nop

    // 0x8000A328: jal         0x8000488C
    // 0x8000A32C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x8000A32C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000A330: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000A334: lw          $t8, -0x5E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E3C);
    // 0x8000A338: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A33C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000A340: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x8000A344: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A348: addiu       $a3, $a3, -0x33B0
    ctx->r7 = ADD32(ctx->r7, -0X33B0);
L_8000A34C:
    // 0x8000A34C: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x8000A350: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000A354: beq         $a2, $zero, L_8000A3A4
    if (ctx->r6 == 0) {
        // 0x8000A358: nop
    
            goto L_8000A3A4;
    }
    // 0x8000A358: nop

    // 0x8000A35C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8000A360: lw          $t9, -0x5E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E3C);
    // 0x8000A364: nop

    // 0x8000A368: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x8000A36C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000A370: nop

    // 0x8000A374: lhu         $a0, 0xC($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0XC);
    // 0x8000A378: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000A37C: ori         $t2, $a0, 0x5000
    ctx->r10 = ctx->r4 | 0X5000;
    // 0x8000A380: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8000A384: jal         0x800245E8
    // 0x8000A388: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    func_800245B4(rdram, ctx);
        goto after_1;
    // 0x8000A388: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_1:
    // 0x8000A38C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000A390: lw          $t5, -0x5E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E3C);
    // 0x8000A394: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A398: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000A39C: addiu       $a3, $a3, -0x33B0
    ctx->r7 = ADD32(ctx->r7, -0X33B0);
    // 0x8000A3A0: addu        $v1, $t5, $a1
    ctx->r3 = ADD32(ctx->r13, ctx->r5);
L_8000A3A4:
    // 0x8000A3A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000A3A8: addiu       $a0, $a0, -0x5E34
    ctx->r4 = ADD32(ctx->r4, -0X5E34);
    // 0x8000A3AC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8000A3B0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000A3B4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000A3B8: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x8000A3BC: lw          $t9, -0x5E30($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E30);
    // 0x8000A3C0: andi        $t0, $t7, 0xFF
    ctx->r8 = ctx->r15 & 0XFF;
    // 0x8000A3C4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8000A3C8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000A3CC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000A3D0: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8000A3D4: lhu         $t3, 0x0($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0X0);
    // 0x8000A3D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A3DC: lw          $v0, -0x5E3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E3C);
    // 0x8000A3E0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8000A3E4: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8000A3E8: lw          $t6, -0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X4);
    // 0x8000A3EC: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x8000A3F0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8000A3F4: lhu         $t0, 0x0($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X0);
    // 0x8000A3F8: nop

    // 0x8000A3FC: addiu       $t9, $t0, -0x1
    ctx->r25 = ADD32(ctx->r8, -0X1);
    // 0x8000A400: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_8000A404:
    // 0x8000A404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A408: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A40C: jr          $ra
    // 0x8000A410: nop

    return;
    // 0x8000A410: nop

;}
RECOMP_FUNC void alFxReverbSet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80064B70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80064B74: jr          $ra
    // 0x80064B78: sb          $a0, -0x2BE0($at)
    MEM_B(-0X2BE0, ctx->r1) = ctx->r4;
    return;
    // 0x80064B78: sb          $a0, -0x2BE0($at)
    MEM_B(-0X2BE0, ctx->r1) = ctx->r4;
;}
