#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void hud_main_eggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A196C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1970: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A1974: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A1978: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A197C: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x800A1980: nop

    // 0x800A1984: lb          $t7, 0x1D8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A1988: nop

    // 0x800A198C: bne         $t7, $zero, L_800A1A24
    if (ctx->r15 != 0) {
        // 0x800A1990: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1A24;
    }
    // 0x800A1990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A1994: jal         0x80068748
    // 0x800A1998: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A1998: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A199C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A19A0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A19A4: jal         0x800A422C
    // 0x800A19A8: nop

    hud_race_start(rdram, ctx);
        goto after_1;
    // 0x800A19A8: nop

    after_1:
    // 0x800A19AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A19B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A19B4: jal         0x800A7A7C
    // 0x800A19B8: nop

    hud_weapon(rdram, ctx);
        goto after_2;
    // 0x800A19B8: nop

    after_2:
    // 0x800A19BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A19C0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A19C4: lw          $v1, 0x729C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X729C);
    // 0x800A19C8: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x800A19CC: lb          $a0, 0x67A($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X67A);
    // 0x800A19D0: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800A19D4: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800A19D8: slt         $at, $t9, $a0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A19DC: bne         $at, $zero, L_800A19F0
    if (ctx->r1 != 0) {
        // 0x800A19E0: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800A19F0;
    }
    // 0x800A19E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A19E4: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // 0x800A19E8: b           L_800A19FC
    // 0x800A19EC: sb          $t0, 0x67A($v1)
    MEM_B(0X67A, ctx->r3) = ctx->r8;
        goto L_800A19FC;
    // 0x800A19EC: sb          $t0, 0x67A($v1)
    MEM_B(0X67A, ctx->r3) = ctx->r8;
L_800A19F0:
    // 0x800A19F0: addu        $t1, $a0, $v0
    ctx->r9 = ADD32(ctx->r4, ctx->r2);
    // 0x800A19F4: addiu       $t2, $t1, -0xFF
    ctx->r10 = ADD32(ctx->r9, -0XFF);
    // 0x800A19F8: sb          $t2, 0x67A($v1)
    MEM_B(0X67A, ctx->r3) = ctx->r10;
L_800A19FC:
    // 0x800A19FC: lbu         $t3, 0x72F7($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X72F7);
    // 0x800A1A00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A1A04: beq         $t3, $at, L_800A1A18
    if (ctx->r11 == ctx->r1) {
        // 0x800A1A08: nop
    
            goto L_800A1A18;
    }
    // 0x800A1A08: nop

    // 0x800A1A0C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A1A10: jal         0x800A1A30
    // 0x800A1A14: nop

    hud_draw_eggs(rdram, ctx);
        goto after_3;
    // 0x800A1A14: nop

    after_3:
L_800A1A18:
    // 0x800A1A18: jal         0x80068748
    // 0x800A1A1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_4;
    // 0x800A1A1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A1A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1A24:
    // 0x800A1A24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A1A28: jr          $ra
    // 0x800A1A2C: nop

    return;
    // 0x800A1A2C: nop

;}
RECOMP_FUNC void lensflare_remove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACDE0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800ACDE4: addiu       $v0, $v0, 0x3010
    ctx->r2 = ADD32(ctx->r2, 0X3010);
    // 0x800ACDE8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800ACDEC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ACDF0: bne         $a0, $t6, L_800ACE00
    if (ctx->r4 != ctx->r14) {
        // 0x800ACDF4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800ACE00;
    }
    // 0x800ACDF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACDF8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800ACDFC: sw          $t7, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = ctx->r15;
L_800ACE00:
    // 0x800ACE00: jr          $ra
    // 0x800ACE04: nop

    return;
    // 0x800ACE04: nop

;}
RECOMP_FUNC void play_taj_voice_clip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AC7C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8003AC80: addiu       $a3, $a3, -0x25AC
    ctx->r7 = ADD32(ctx->r7, -0X25AC);
    // 0x8003AC84: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8003AC88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003AC8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AC90: beq         $a2, $zero, L_8003ACBC
    if (ctx->r6 == 0) {
        // 0x8003AC94: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8003ACBC;
    }
    // 0x8003AC94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003AC98: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x8003AC9C: beq         $t6, $zero, L_8003ACBC
    if (ctx->r14 == 0) {
        // 0x8003ACA0: nop
    
            goto L_8003ACBC;
    }
    // 0x8003ACA0: nop

    // 0x8003ACA4: jal         0x8000488C
    // 0x8003ACA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x8003ACA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8003ACAC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8003ACB0: addiu       $a3, $a3, -0x25AC
    ctx->r7 = ADD32(ctx->r7, -0X25AC);
    // 0x8003ACB4: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8003ACB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003ACBC:
    // 0x8003ACBC: bne         $a2, $zero, L_8003ACD4
    if (ctx->r6 != 0) {
        // 0x8003ACC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003ACD4;
    }
    // 0x8003ACC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003ACC4: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x8003ACC8: jal         0x80001D04
    // 0x8003ACCC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8003ACCC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x8003ACD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003ACD4:
    // 0x8003ACD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003ACD8: jr          $ra
    // 0x8003ACDC: nop

    return;
    // 0x8003ACDC: nop

;}
RECOMP_FUNC void camera_init_tracks_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066470: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80066474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066478: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006647C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80066480: jal         0x8006676C
    // 0x80066484: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_layout(rdram, ctx);
        goto after_0;
    // 0x80066484: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80066488: jal         0x80066828
    // 0x8006648C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_active_camera(rdram, ctx);
        goto after_1;
    // 0x8006648C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80066490: jal         0x80069F60
    // 0x80066494: nop

    cam_get_active_camera(rdram, ctx);
        goto after_2;
    // 0x80066494: nop

    after_2:
    // 0x80066498: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8006649C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800664A0: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    // 0x800664A4: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800664A8: addiu       $t0, $zero, -0x8000
    ctx->r8 = ADD32(0, -0X8000);
    // 0x800664AC: sh          $t7, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r15;
    // 0x800664B0: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800664B4: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x800664B8: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
    // 0x800664BC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800664C0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x800664C4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800664C8: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800664CC: nop

    // 0x800664D0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800664D4: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800664D8: nop

    // 0x800664DC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800664E0: lh          $t9, 0x38($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X38);
    // 0x800664E4: nop

    // 0x800664E8: sh          $t9, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r25;
    // 0x800664EC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800664F0: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x800664F4: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x800664F8: sh          $zero, 0x38($v0)
    MEM_H(0X38, ctx->r2) = 0;
    // 0x800664FC: swc1        $f12, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f12.u32l;
    // 0x80066500: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    // 0x80066504: swc1        $f12, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
    // 0x80066508: jal         0x8001D614
    // 0x8006650C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    update_envmap_position(rdram, ctx);
        goto after_3;
    // 0x8006650C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80066510: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80066514: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80066518: jal         0x80066F1C
    // 0x8006651C: nop

    viewport_main(rdram, ctx);
        goto after_4;
    // 0x8006651C: nop

    after_4:
    // 0x80066520: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80066524: lh          $t1, 0x24($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X24);
    // 0x80066528: nop

    // 0x8006652C: sh          $t1, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r9;
    // 0x80066530: lh          $t2, 0x2A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2A);
    // 0x80066534: nop

    // 0x80066538: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x8006653C: lh          $t3, 0x28($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X28);
    // 0x80066540: nop

    // 0x80066544: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
    // 0x80066548: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x8006654C: nop

    // 0x80066550: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
    // 0x80066554: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80066558: nop

    // 0x8006655C: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x80066560: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80066564: nop

    // 0x80066568: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x8006656C: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80066570: nop

    // 0x80066574: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x80066578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006657C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80066580: jr          $ra
    // 0x80066584: nop

    return;
    // 0x80066584: nop

;}
RECOMP_FUNC void divider_draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800774A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800774A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800774A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800774AC: jal         0x8007A970
    // 0x800774B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800774B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800774B4: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x800774B8: srl         $t6, $a1, 8
    ctx->r14 = S32(U32(ctx->r5) >> 8);
    // 0x800774BC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800774C0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800774C4: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x800774C8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800774CC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800774D0: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x800774D4: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x800774D8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800774DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800774E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800774E4: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x800774E8: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800774EC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800774F0: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x800774F4: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x800774F8: srl         $a0, $v0, 16
    ctx->r4 = S32(U32(ctx->r2) >> 16);
    // 0x800774FC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80077500: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80077504: srl         $t2, $a0, 7
    ctx->r10 = S32(U32(ctx->r4) >> 7);
    // 0x80077508: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8007750C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80077510: jal         0x80066450
    // 0x80077514: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80077514: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_1:
    // 0x80077518: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007751C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80077520: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80077524: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80077528: beq         $v0, $at, L_8007754C
    if (ctx->r2 == ctx->r1) {
        // 0x8007752C: srl         $t7, $t0, 1
        ctx->r15 = S32(U32(ctx->r8) >> 1);
            goto L_8007754C;
    }
    // 0x8007752C: srl         $t7, $t0, 1
    ctx->r15 = S32(U32(ctx->r8) >> 1);
    // 0x80077530: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80077534: beq         $v0, $at, L_80077590
    if (ctx->r2 == ctx->r1) {
        // 0x80077538: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80077590;
    }
    // 0x80077538: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007753C: beq         $v0, $at, L_80077620
    if (ctx->r2 == ctx->r1) {
        // 0x80077540: nop
    
            goto L_80077620;
    }
    // 0x80077540: nop

    // 0x80077544: b           L_800776AC
    // 0x80077548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800776AC;
    // 0x80077548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007754C:
    // 0x8007754C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077550: subu        $v0, $t7, $t2
    ctx->r2 = SUB32(ctx->r15, ctx->r10);
    // 0x80077554: andi        $t8, $t1, 0x3FF
    ctx->r24 = ctx->r9 & 0X3FF;
    // 0x80077558: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8007755C: addu        $t4, $v0, $t2
    ctx->r12 = ADD32(ctx->r2, ctx->r10);
    // 0x80077560: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80077564: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077568: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007756C: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x80077570: andi        $t5, $t4, 0x3FF
    ctx->r13 = ctx->r12 & 0X3FF;
    // 0x80077574: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80077578: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x8007757C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80077580: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80077584: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077588: b           L_800776A8
    // 0x8007758C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_800776A8;
    // 0x8007758C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80077590:
    // 0x80077590: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80077594: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80077598: jal         0x8006BFF0
    // 0x8007759C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    level_header(rdram, ctx);
        goto after_2;
    // 0x8007759C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    after_2:
    // 0x800775A0: jal         0x800A89B4
    // 0x800775A4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    hud_setting(rdram, ctx);
        goto after_3;
    // 0x800775A4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x800775A8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800775AC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800775B0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800775B4: bne         $v0, $zero, L_800775D8
    if (ctx->r2 != 0) {
        // 0x800775B8: andi        $t7, $t1, 0x3FF
        ctx->r15 = ctx->r9 & 0X3FF;
            goto L_800775D8;
    }
    // 0x800775B8: andi        $t7, $t1, 0x3FF
    ctx->r15 = ctx->r9 & 0X3FF;
    // 0x800775BC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800775C0: nop

    // 0x800775C4: lb          $t5, 0x4C($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X4C);
    // 0x800775C8: nop

    // 0x800775CC: andi        $t3, $t5, 0x40
    ctx->r11 = ctx->r13 & 0X40;
    // 0x800775D0: beq         $t3, $zero, L_80077620
    if (ctx->r11 == 0) {
        // 0x800775D4: nop
    
            goto L_80077620;
    }
    // 0x800775D4: nop

L_800775D8:
    // 0x800775D8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800775DC: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x800775E0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800775E4: andi        $t4, $t0, 0x3FF
    ctx->r12 = ctx->r8 & 0X3FF;
    // 0x800775E8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800775EC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800775F0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800775F4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800775F8: or          $t3, $t9, $t5
    ctx->r11 = ctx->r25 | ctx->r13;
    // 0x800775FC: srl         $t6, $t1, 1
    ctx->r14 = S32(U32(ctx->r9) >> 1);
    // 0x80077600: srl         $t4, $t0, 1
    ctx->r12 = S32(U32(ctx->r8) >> 1);
    // 0x80077604: andi        $t9, $t4, 0x3FF
    ctx->r25 = ctx->r12 & 0X3FF;
    // 0x80077608: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x8007760C: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80077610: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80077614: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80077618: or          $t3, $t8, $t5
    ctx->r11 = ctx->r24 | ctx->r13;
    // 0x8007761C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_80077620:
    // 0x80077620: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077624: srl         $t7, $t0, 1
    ctx->r15 = S32(U32(ctx->r8) >> 1);
    // 0x80077628: subu        $v0, $t7, $t2
    ctx->r2 = SUB32(ctx->r15, ctx->r10);
    // 0x8007762C: andi        $t4, $t1, 0x3FF
    ctx->r12 = ctx->r9 & 0X3FF;
    // 0x80077630: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80077634: sll         $t9, $t4, 14
    ctx->r25 = S32(ctx->r12 << 14);
    // 0x80077638: addu        $t5, $v0, $t2
    ctx->r13 = ADD32(ctx->r2, ctx->r10);
    // 0x8007763C: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80077640: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077644: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80077648: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8007764C: andi        $t3, $t5, 0x3FF
    ctx->r11 = ctx->r13 & 0X3FF;
    // 0x80077650: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80077654: andi        $t4, $v0, 0x3FF
    ctx->r12 = ctx->r2 & 0X3FF;
    // 0x80077658: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8007765C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80077660: srl         $t3, $t1, 1
    ctx->r11 = S32(U32(ctx->r9) >> 1);
    // 0x80077664: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077668: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007766C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80077670: subu        $a1, $t3, $a3
    ctx->r5 = SUB32(ctx->r11, ctx->r7);
    // 0x80077674: addu        $t8, $a1, $a3
    ctx->r24 = ADD32(ctx->r5, ctx->r7);
    // 0x80077678: andi        $t6, $t8, 0x3FF
    ctx->r14 = ctx->r24 & 0X3FF;
    // 0x8007767C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80077680: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80077684: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80077688: andi        $t9, $t0, 0x3FF
    ctx->r25 = ctx->r8 & 0X3FF;
    // 0x8007768C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80077690: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x80077694: andi        $t8, $a1, 0x3FF
    ctx->r24 = ctx->r5 & 0X3FF;
    // 0x80077698: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x8007769C: or          $t3, $t4, $t5
    ctx->r11 = ctx->r12 | ctx->r13;
    // 0x800776A0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800776A4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800776A8:
    // 0x800776A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800776AC:
    // 0x800776AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800776B0: jr          $ra
    // 0x800776B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800776B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void hud_main_boss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2ACC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2AD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2AD4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A2AD8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A2ADC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A2AE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A2AE4: lw          $s1, 0x64($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X64);
    // 0x800A2AE8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800A2AEC: jal         0x80068748
    // 0x800A2AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_0;
    // 0x800A2AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A2AF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A2AF8: jal         0x800A5FAC
    // 0x800A2AFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_wrong_way(rdram, ctx);
        goto after_1;
    // 0x800A2AFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800A2B00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A2B04: jal         0x800A422C
    // 0x800A2B08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_start(rdram, ctx);
        goto after_2;
    // 0x800A2B08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800A2B0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A2B10: jal         0x800A80C4
    // 0x800A2B14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_time(rdram, ctx);
        goto after_3;
    // 0x800A2B14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800A2B18: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A2B1C: jal         0x800A7A7C
    // 0x800A2B20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_weapon(rdram, ctx);
        goto after_4;
    // 0x800A2B20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800A2B24: jal         0x8006BFF0
    // 0x800A2B28: nop

    level_header(rdram, ctx);
        goto after_5;
    // 0x800A2B28: nop

    after_5:
    // 0x800A2B2C: lb          $t7, 0x4B($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X4B);
    // 0x800A2B30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A2B34: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800A2B38: bne         $at, $zero, L_800A2B48
    if (ctx->r1 != 0) {
        // 0x800A2B3C: nop
    
            goto L_800A2B48;
    }
    // 0x800A2B3C: nop

    // 0x800A2B40: jal         0x800A5498
    // 0x800A2B44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_lap_count(rdram, ctx);
        goto after_6;
    // 0x800A2B44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
L_800A2B48:
    // 0x800A2B48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800A2B4C: jal         0x800A3DCC
    // 0x800A2B50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_speedometre(rdram, ctx);
        goto after_7;
    // 0x800A2B50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800A2B54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A2B58: jal         0x800A518C
    // 0x800A2B5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    hud_race_position(rdram, ctx);
        goto after_8;
    // 0x800A2B5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800A2B60: jal         0x80068748
    // 0x800A2B64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_9;
    // 0x800A2B64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x800A2B68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2B6C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A2B70: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A2B74: jr          $ra
    // 0x800A2B78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A2B78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001CD28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD5C: addiu       $sp, $sp, -0x378
    ctx->r29 = ADD32(ctx->r29, -0X378);
    // 0x8001CD60: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8001CD64: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8001CD68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001CD6C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8001CD70: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8001CD74: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8001CD78: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8001CD7C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8001CD80: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8001CD84: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8001CD88: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8001CD8C: sw          $a0, 0x378($sp)
    MEM_W(0X378, ctx->r29) = ctx->r4;
    // 0x8001CD90: sw          $a2, 0x380($sp)
    MEM_W(0X380, ctx->r29) = ctx->r6;
    // 0x8001CD94: sw          $a3, 0x384($sp)
    MEM_W(0X384, ctx->r29) = ctx->r7;
    // 0x8001CD98: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001CD9C: addiu       $t2, $sp, 0x154
    ctx->r10 = ADD32(ctx->r29, 0X154);
L_8001CDA0:
    // 0x8001CDA0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8001CDA4: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001CDA8: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x8001CDAC: sra         $t5, $t8, 16
    ctx->r13 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001CDB0: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CDB4: slti        $at, $t5, 0x80
    ctx->r1 = SIGNED(ctx->r13) < 0X80 ? 1 : 0;
    // 0x8001CDB8: bne         $at, $zero, L_8001CDA0
    if (ctx->r1 != 0) {
        // 0x8001CDBC: sw          $zero, 0x0($t7)
        MEM_W(0X0, ctx->r15) = 0;
            goto L_8001CDA0;
    }
    // 0x8001CDBC: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8001CDC0: lw          $t6, 0x378($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X378);
    // 0x8001CDC4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001CDC8: lw          $v1, -0x4B7C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4B7C);
    // 0x8001CDCC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001CDD0: addu        $a0, $v1, $t7
    ctx->r4 = ADD32(ctx->r3, ctx->r15);
    // 0x8001CDD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001CDD8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001CDDC: lw          $s4, 0x64($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X64);
    // 0x8001CDE0: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x8001CDE4: lw          $fp, 0x370($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X370);
    // 0x8001CDE8: lh          $a2, 0x36C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X36C);
    // 0x8001CDEC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8001CDF0: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x8001CDF4: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x8001CDF8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001CDFC: sb          $t8, 0x363($sp)
    MEM_B(0X363, ctx->r29) = ctx->r24;
    // 0x8001CE00: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8001CE04: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x8001CE08: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8001CE0C: addiu       $t3, $sp, 0x54
    ctx->r11 = ADD32(ctx->r29, 0X54);
    // 0x8001CE10: addiu       $t0, $sp, 0xD4
    ctx->r8 = ADD32(ctx->r29, 0XD4);
    // 0x8001CE14: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x8001CE18: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_8001CE1C:
    // 0x8001CE1C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
L_8001CE20:
    // 0x8001CE20: addu        $t6, $s4, $t9
    ctx->r14 = ADD32(ctx->r20, ctx->r25);
    // 0x8001CE24: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001CE28: lw          $t8, 0x378($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X378);
    // 0x8001CE2C: beq         $t7, $zero, L_8001D058
    if (ctx->r15 == 0) {
        // 0x8001CE30: addu        $s0, $s1, $t5
        ctx->r16 = ADD32(ctx->r17, ctx->r13);
            goto L_8001D058;
    }
    // 0x8001CE30: addu        $s0, $s1, $t5
    ctx->r16 = ADD32(ctx->r17, ctx->r13);
    // 0x8001CE34: lbu         $v1, 0x9($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X9);
    // 0x8001CE38: lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA);
    // 0x8001CE3C: bne         $t8, $v1, L_8001CE54
    if (ctx->r24 != ctx->r3) {
        // 0x8001CE40: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8001CE54;
    }
    // 0x8001CE40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001CE44: lw          $t9, 0x380($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X380);
    // 0x8001CE48: nop

    // 0x8001CE4C: beq         $v0, $t9, L_8001CE6C
    if (ctx->r2 == ctx->r25) {
        // 0x8001CE50: nop
    
            goto L_8001CE6C;
    }
    // 0x8001CE50: nop

L_8001CE54:
    // 0x8001CE54: lw          $t6, 0x380($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X380);
    // 0x8001CE58: lw          $t7, 0x378($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X378);
    // 0x8001CE5C: bne         $t6, $v1, L_8001CE84
    if (ctx->r14 != ctx->r3) {
        // 0x8001CE60: nop
    
            goto L_8001CE84;
    }
    // 0x8001CE60: nop

    // 0x8001CE64: bne         $v0, $t7, L_8001CE84
    if (ctx->r2 != ctx->r15) {
        // 0x8001CE68: nop
    
            goto L_8001CE84;
    }
    // 0x8001CE68: nop

L_8001CE6C:
    // 0x8001CE6C: beq         $s5, $zero, L_8001CE78
    if (ctx->r21 == 0) {
        // 0x8001CE70: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001CE78;
    }
    // 0x8001CE70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001CE74: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8001CE78:
    // 0x8001CE78: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001CE7C: sll         $t8, $s5, 24
    ctx->r24 = S32(ctx->r21 << 24);
    // 0x8001CE80: sra         $s5, $t8, 24
    ctx->r21 = S32(SIGNED(ctx->r24) >> 24);
L_8001CE84:
    // 0x8001CE84: beq         $a3, $zero, L_8001CF10
    if (ctx->r7 == 0) {
        // 0x8001CE88: addiu       $a0, $t1, -0x1
        ctx->r4 = ADD32(ctx->r9, -0X1);
            goto L_8001CF10;
    }
    // 0x8001CE88: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    // 0x8001CE8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001CE90: blez        $t1, L_8001CED4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001CE94: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001CED4;
    }
    // 0x8001CE94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001CE98: lb          $t6, 0xD4($sp)
    ctx->r14 = MEM_B(ctx->r29, 0XD4);
    // 0x8001CE9C: nop

    // 0x8001CEA0: beq         $v0, $t6, L_8001CED8
    if (ctx->r2 == ctx->r14) {
        // 0x8001CEA4: sll         $t7, $t5, 1
        ctx->r15 = S32(ctx->r13 << 1);
            goto L_8001CED8;
    }
    // 0x8001CEA4: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
L_8001CEA8:
    // 0x8001CEA8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001CEAC: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8001CEB0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001CEB4: slt         $at, $t8, $t1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001CEB8: beq         $at, $zero, L_8001CED4
    if (ctx->r1 == 0) {
        // 0x8001CEBC: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8001CED4;
    }
    // 0x8001CEBC: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8001CEC0: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8001CEC4: lb          $t6, 0x0($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X0);
    // 0x8001CEC8: nop

    // 0x8001CECC: bne         $v0, $t6, L_8001CEA8
    if (ctx->r2 != ctx->r14) {
        // 0x8001CED0: nop
    
            goto L_8001CEA8;
    }
    // 0x8001CED0: nop

L_8001CED4:
    // 0x8001CED4: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
L_8001CED8:
    // 0x8001CED8: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x8001CEDC: lh          $t9, 0x10($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X10);
    // 0x8001CEE0: bne         $a2, $t1, L_8001CEF0
    if (ctx->r6 != ctx->r9) {
        // 0x8001CEE4: addu        $fp, $t9, $ra
        ctx->r30 = ADD32(ctx->r25, ctx->r31);
            goto L_8001CEF0;
    }
    // 0x8001CEE4: addu        $fp, $t9, $ra
    ctx->r30 = ADD32(ctx->r25, ctx->r31);
    // 0x8001CEE8: b           L_8001CF10
    // 0x8001CEEC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_8001CF10;
    // 0x8001CEEC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8001CEF0:
    // 0x8001CEF0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001CEF4: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CEF8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001CEFC: nop

    // 0x8001CF00: slt         $at, $fp, $t8
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001CF04: beq         $at, $zero, L_8001CF10
    if (ctx->r1 == 0) {
        // 0x8001CF08: nop
    
            goto L_8001CF10;
    }
    // 0x8001CF08: nop

    // 0x8001CF0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8001CF10:
    // 0x8001CF10: beq         $a3, $zero, L_8001D058
    if (ctx->r7 == 0) {
        // 0x8001CF14: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_8001D058;
    }
    // 0x8001CF14: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8001CF18: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001CF1C: beq         $at, $zero, L_8001CF50
    if (ctx->r1 == 0) {
        // 0x8001CF20: addu        $t4, $t2, $t9
        ctx->r12 = ADD32(ctx->r10, ctx->r25);
            goto L_8001CF50;
    }
    // 0x8001CF20: addu        $t4, $t2, $t9
    ctx->r12 = ADD32(ctx->r10, ctx->r25);
L_8001CF24:
    // 0x8001CF24: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
    // 0x8001CF28: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
    // 0x8001CF2C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001CF30: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8001CF34: lb          $t6, 0x1($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1);
    // 0x8001CF38: lb          $t7, 0x1($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1);
    // 0x8001CF3C: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001CF40: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001CF44: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8001CF48: bne         $at, $zero, L_8001CF24
    if (ctx->r1 != 0) {
        // 0x8001CF4C: sb          $t7, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r15;
            goto L_8001CF24;
    }
    // 0x8001CF4C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_8001CF50:
    // 0x8001CF50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001CF54: bne         $a3, $at, L_8001CF6C
    if (ctx->r7 != ctx->r1) {
        // 0x8001CF58: nop
    
            goto L_8001CF6C;
    }
    // 0x8001CF58: nop

    // 0x8001CF5C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001CF60: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x8001CF64: sra         $t1, $t6, 16
    ctx->r9 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001CF68: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
L_8001CF6C:
    // 0x8001CF6C: sw          $fp, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r30;
    // 0x8001CF70: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8001CF74: lb          $t6, 0x363($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X363);
    // 0x8001CF78: sll         $a2, $a0, 16
    ctx->r6 = S32(ctx->r4 << 16);
    // 0x8001CF7C: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001CF80: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001CF84: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8001CF88: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8001CF8C: addu        $a1, $t3, $t9
    ctx->r5 = ADD32(ctx->r11, ctx->r25);
    // 0x8001CF90: beq         $t6, $zero, L_8001CFA4
    if (ctx->r14 == 0) {
        // 0x8001CF94: addu        $v1, $t0, $t9
        ctx->r3 = ADD32(ctx->r8, ctx->r25);
            goto L_8001CFA4;
    }
    // 0x8001CF94: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x8001CF98: lbu         $t7, 0xA($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XA);
    // 0x8001CF9C: b           L_8001CFA8
    // 0x8001CFA0: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
        goto L_8001CFA8;
    // 0x8001CFA0: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
L_8001CFA4:
    // 0x8001CFA4: sb          $s3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r19;
L_8001CFA8:
    // 0x8001CFA8: lbu         $t8, 0xA($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XA);
    // 0x8001CFAC: blez        $v0, L_8001D058
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001CFB0: sb          $t8, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r24;
            goto L_8001D058;
    }
    // 0x8001CFB0: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x8001CFB4: lb          $t9, -0x1($v1)
    ctx->r25 = MEM_B(ctx->r3, -0X1);
    // 0x8001CFB8: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
    // 0x8001CFBC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001CFC0: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x8001CFC4: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CFC8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001CFCC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001CFD0: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001CFD4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001CFD8: nop

    // 0x8001CFDC: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001CFE0: beq         $at, $zero, L_8001D058
    if (ctx->r1 == 0) {
        // 0x8001CFE4: nop
    
            goto L_8001D058;
    }
    // 0x8001CFE4: nop

    // 0x8001CFE8: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8001CFEC: lb          $a1, -0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, -0X1);
    // 0x8001CFF0: nop

    // 0x8001CFF4: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
L_8001CFF8:
    // 0x8001CFF8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001CFFC: lb          $a3, 0x0($v1)
    ctx->r7 = MEM_B(ctx->r3, 0X0);
    // 0x8001D000: lb          $t6, -0x1($v1)
    ctx->r14 = MEM_B(ctx->r3, -0X1);
    // 0x8001D004: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8001D008: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001D00C: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x8001D010: sb          $a0, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r4;
    // 0x8001D014: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8001D018: sb          $a3, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r7;
    // 0x8001D01C: blez        $t9, L_8001D058
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001D020: sb          $t6, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r14;
            goto L_8001D058;
    }
    // 0x8001D020: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8001D024: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x8001D028: lb          $a1, -0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, -0X1);
    // 0x8001D02C: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8001D030: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8001D034: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8001D038: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8001D03C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001D040: addu        $t6, $t2, $t9
    ctx->r14 = ADD32(ctx->r10, ctx->r25);
    // 0x8001D044: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001D048: nop

    // 0x8001D04C: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001D050: bne         $at, $zero, L_8001CFF8
    if (ctx->r1 != 0) {
        // 0x8001D054: addu        $v1, $t3, $a2
        ctx->r3 = ADD32(ctx->r11, ctx->r6);
            goto L_8001CFF8;
    }
    // 0x8001D054: addu        $v1, $t3, $a2
    ctx->r3 = ADD32(ctx->r11, ctx->r6);
L_8001D058:
    // 0x8001D058: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001D05C: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8001D060: sra         $t5, $t9, 16
    ctx->r13 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001D064: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8001D068: bne         $at, $zero, L_8001CE20
    if (ctx->r1 != 0) {
        // 0x8001D06C: sll         $t9, $t5, 2
        ctx->r25 = S32(ctx->r13 << 2);
            goto L_8001CE20;
    }
    // 0x8001D06C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8001D070: blez        $t1, L_8001D11C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001D074: nop
    
            goto L_8001D11C;
    }
    // 0x8001D074: nop

    // 0x8001D078: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8001D07C: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8001D080: sra         $t1, $t8, 16
    ctx->r9 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001D084: addu        $t9, $t0, $t1
    ctx->r25 = ADD32(ctx->r8, ctx->r9);
    // 0x8001D088: lb          $v1, 0x0($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X0);
    // 0x8001D08C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8001D090: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8001D094: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x8001D098: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8001D09C: addu        $t9, $t3, $t1
    ctx->r25 = ADD32(ctx->r11, ctx->r9);
    // 0x8001D0A0: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x8001D0A4: lb          $s3, 0x0($t9)
    ctx->r19 = MEM_B(ctx->r25, 0X0);
    // 0x8001D0A8: lbu         $t6, 0x9($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X9);
    // 0x8001D0AC: andi        $t9, $s6, 0x100
    ctx->r25 = ctx->r22 & 0X100;
    // 0x8001D0B0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8001D0B4: addu        $t7, $t2, $t8
    ctx->r15 = ADD32(ctx->r10, ctx->r24);
    // 0x8001D0B8: lw          $ra, 0x0($t7)
    ctx->r31 = MEM_W(ctx->r15, 0X0);
    // 0x8001D0BC: lw          $s4, 0x64($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X64);
    // 0x8001D0C0: beq         $t9, $zero, L_8001D0E4
    if (ctx->r25 == 0) {
        // 0x8001D0C4: sb          $zero, 0x363($sp)
        MEM_B(0X363, ctx->r29) = 0;
            goto L_8001D0E4;
    }
    // 0x8001D0C4: sb          $zero, 0x363($sp)
    MEM_B(0X363, ctx->r29) = 0;
    // 0x8001D0C8: andi        $t6, $s6, 0x7F
    ctx->r14 = ctx->r22 & 0X7F;
    // 0x8001D0CC: bne         $t6, $v1, L_8001D100
    if (ctx->r14 != ctx->r3) {
        // 0x8001D0D0: nop
    
            goto L_8001D100;
    }
    // 0x8001D0D0: nop

    // 0x8001D0D4: sll         $s2, $s3, 16
    ctx->r18 = S32(ctx->r19 << 16);
    // 0x8001D0D8: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D0DC: b           L_8001D100
    // 0x8001D0E0: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
        goto L_8001D100;
    // 0x8001D0E0: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_8001D0E4:
    // 0x8001D0E4: lbu         $t7, 0x8($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X8);
    // 0x8001D0E8: nop

    // 0x8001D0EC: bne         $s6, $t7, L_8001D100
    if (ctx->r22 != ctx->r15) {
        // 0x8001D0F0: nop
    
            goto L_8001D100;
    }
    // 0x8001D0F0: nop

    // 0x8001D0F4: sll         $s2, $s3, 16
    ctx->r18 = S32(ctx->r19 << 16);
    // 0x8001D0F8: sra         $t9, $s2, 16
    ctx->r25 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D0FC: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_8001D100:
    // 0x8001D100: bne         $t1, $zero, L_8001D11C
    if (ctx->r9 != 0) {
        // 0x8001D104: nop
    
            goto L_8001D11C;
    }
    // 0x8001D104: nop

    // 0x8001D108: bne         $s2, $s7, L_8001D11C
    if (ctx->r18 != ctx->r23) {
        // 0x8001D10C: nop
    
            goto L_8001D11C;
    }
    // 0x8001D10C: nop

    // 0x8001D110: sll         $s2, $s3, 16
    ctx->r18 = S32(ctx->r19 << 16);
    // 0x8001D114: sra         $t6, $s2, 16
    ctx->r14 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8001D118: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
L_8001D11C:
    // 0x8001D11C: bne         $s2, $s7, L_8001D134
    if (ctx->r18 != ctx->r23) {
        // 0x8001D120: nop
    
            goto L_8001D134;
    }
    // 0x8001D120: nop

    // 0x8001D124: bgtz        $t1, L_8001CE1C
    if (SIGNED(ctx->r9) > 0) {
        // 0x8001D128: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_8001CE1C;
    }
    // 0x8001D128: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001D12C: sw          $fp, 0x370($sp)
    MEM_W(0X370, ctx->r29) = ctx->r30;
    // 0x8001D130: sh          $a2, 0x36C($sp)
    MEM_H(0X36C, ctx->r29) = ctx->r6;
L_8001D134:
    // 0x8001D134: beq         $s2, $s7, L_8001D1B0
    if (ctx->r18 == ctx->r23) {
        // 0x8001D138: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001D1B0;
    }
    // 0x8001D138: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D13C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8001D140: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001D144: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001D148: nop

    // 0x8001D14C: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x8001D150: lw          $s4, 0x64($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X64);
    // 0x8001D154: lbu         $t7, 0xA($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XA);
    // 0x8001D158: nop

    // 0x8001D15C: beq         $s2, $t7, L_8001D194
    if (ctx->r18 == ctx->r15) {
        // 0x8001D160: slti        $at, $t5, 0x4
        ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
            goto L_8001D194;
    }
    // 0x8001D160: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
L_8001D164:
    // 0x8001D164: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001D168: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x8001D16C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001D170: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x8001D174: beq         $at, $zero, L_8001D190
    if (ctx->r1 == 0) {
        // 0x8001D178: or          $t5, $t6, $zero
        ctx->r13 = ctx->r14 | 0;
            goto L_8001D190;
    }
    // 0x8001D178: or          $t5, $t6, $zero
    ctx->r13 = ctx->r14 | 0;
    // 0x8001D17C: addu        $t8, $s1, $t6
    ctx->r24 = ADD32(ctx->r17, ctx->r14);
    // 0x8001D180: lbu         $t7, 0xA($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XA);
    // 0x8001D184: nop

    // 0x8001D188: bne         $s2, $t7, L_8001D164
    if (ctx->r18 != ctx->r15) {
        // 0x8001D18C: nop
    
            goto L_8001D164;
    }
    // 0x8001D18C: nop

L_8001D190:
    // 0x8001D190: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
L_8001D194:
    // 0x8001D194: beq         $at, $zero, L_8001D1B0
    if (ctx->r1 == 0) {
        // 0x8001D198: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001D1B0;
    }
    // 0x8001D198: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D19C: lw          $t9, 0x384($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X384);
    // 0x8001D1A0: nop

    // 0x8001D1A4: addu        $t6, $s4, $t9
    ctx->r14 = ADD32(ctx->r20, ctx->r25);
    // 0x8001D1A8: sb          $t5, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r13;
    // 0x8001D1AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001D1B0:
    // 0x8001D1B0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8001D1B4: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8001D1B8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8001D1BC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8001D1C0: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8001D1C4: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8001D1C8: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D1CC: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8001D1D0: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8001D1D4: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8001D1D8: jr          $ra
    // 0x8001D1DC: addiu       $sp, $sp, 0x378
    ctx->r29 = ADD32(ctx->r29, 0X378);
    return;
    // 0x8001D1DC: addiu       $sp, $sp, 0x378
    ctx->r29 = ADD32(ctx->r29, 0X378);
;}
RECOMP_FUNC void resolve_collisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031640: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80031644: sb          $t0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r8;
    // 0x80031648: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8003164C: lw          $t0, -0x2708($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2708);
    // 0x80031650: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80031654: sb          $zero, 0x0($sp)
    MEM_B(0X0, ctx->r29) = 0;
    // 0x80031658: beq         $t0, $zero, L_80031B8C
    if (ctx->r8 == 0) {
        // 0x8003165C: sw          $zero, -0x4990($at)
        MEM_W(-0X4990, ctx->r1) = 0;
            goto L_80031B8C;
    }
    // 0x8003165C: sw          $zero, -0x4990($at)
    MEM_W(-0X4990, ctx->r1) = 0;
L_80031660:
    // 0x80031660: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
L_80031664:
    // 0x80031664: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80031668: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8003166C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80031670: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80031674: lw          $t5, -0x270C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X270C);
    // 0x80031678: lw          $t1, -0x2710($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2710);
    // 0x8003167C: lw          $t0, -0x2708($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2708);
L_80031680:
    // 0x80031680: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80031684: blezl       $t2, L_800316A0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80031688: lhu         $v0, 0x0($t2)
        ctx->r2 = MEM_HU(ctx->r10, 0X0);
            goto L_800316A0;
    }
    goto skip_0;
    // 0x80031688: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    skip_0:
    // 0x8003168C: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80031690: or          $t3, $t3, $t2
    ctx->r11 = ctx->r11 | ctx->r10;
    // 0x80031694: j           L_80031984
    // 0x80031698: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
        goto L_80031984;
    // 0x80031698: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
    // 0x8003169C: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
L_800316A0:
    // 0x800316A0: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800316A4: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800316A8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800316AC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800316B0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800316B4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800316B8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800316BC: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800316C0: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800316C4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800316C8: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800316CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800316D0: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800316D4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800316D8: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800316DC: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800316E0: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800316E4: sub.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800316E8: lwc1        $f8, 0x64F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64F0);
    // 0x800316EC: c.olt.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x800316F0: bc1fl       L_80031988
    if (!c1cs) {
        // 0x800316F4: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031988;
    }
    goto skip_1;
    // 0x800316F4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_1:
    // 0x800316F8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800316FC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031700: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80031704: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80031708: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003170C: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80031710: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80031714: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80031718: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8003171C: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80031720: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031724: sub.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80031728: lwc1        $f8, 0x64F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64F4);
    // 0x8003172C: c.olt.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80031730: bc1tl       L_80031988
    if (c1cs) {
        // 0x80031734: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031988;
    }
    goto skip_2;
    // 0x80031734: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_2:
    // 0x80031738: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003173C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031740: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80031744: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031748: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8003174C: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80031750: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80031754: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031758: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8003175C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80031760: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80031764: c.ueq.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80031768: bc1t        L_80031774
    if (c1cs) {
        // 0x8003176C: nop
    
            goto L_80031774;
    }
    // 0x8003176C: nop

    // 0x80031770: div.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
L_80031774:
    // 0x80031774: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80031778: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003177C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80031780: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80031784: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80031788: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8003178C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031790: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80031794: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031798: add.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8003179C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800317A0: add.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f4.fl;
L_800317A4:
    // 0x800317A4: lhu         $v1, 0x2($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X2);
    // 0x800317A8: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x800317AC: andi        $t9, $v1, 0x8000
    ctx->r25 = ctx->r3 & 0X8000;
    // 0x800317B0: beql        $t9, $zero, L_800317C4
    if (ctx->r25 == 0) {
        // 0x800317B4: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_800317C4;
    }
    goto skip_3;
    // 0x800317B4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    skip_3:
    // 0x800317B8: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x800317BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800317C0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
L_800317C4:
    // 0x800317C4: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x800317C8: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800317CC: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800317D0: mul.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800317D4: nop

    // 0x800317D8: mul.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800317DC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800317E0: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800317E4: mul.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800317E8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800317EC: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800317F0: beq         $t8, $zero, L_800317FC
    if (ctx->r24 == 0) {
        // 0x800317F4: add.s       $f6, $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_800317FC;
    }
    // 0x800317F4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800317F8: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
L_800317FC:
    // 0x800317FC: c.ole.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x80031800: bc1fl       L_80031988
    if (!c1cs) {
        // 0x80031804: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031988;
    }
    goto skip_4;
    // 0x80031804: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_4:
    // 0x80031808: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x8003180C: bne         $t4, $zero, L_800317A4
    if (ctx->r12 != 0) {
        // 0x80031810: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_800317A4;
    }
    // 0x80031810: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x80031814: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031818: lwc1        $f0, 0x64F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X64F8);
    // 0x8003181C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80031820: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80031824: c.ult.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80031828: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003182C: bc1t        L_80031888
    if (c1cs) {
        // 0x80031830: nop
    
            goto L_80031888;
    }
    // 0x80031830: nop

    // 0x80031834: lb          $v1, 0x0($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X0);
    // 0x80031838: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003183C: beq         $v1, $at, L_80031888
    if (ctx->r3 == ctx->r1) {
        // 0x80031840: nop
    
            goto L_80031888;
    }
    // 0x80031840: nop

    // 0x80031844: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80031848: lw          $v1, -0x498C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X498C);
    // 0x8003184C: bne         $v1, $zero, L_80031888
    if (ctx->r3 != 0) {
        // 0x80031850: nop
    
            goto L_80031888;
    }
    // 0x80031850: nop

    // 0x80031854: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031858: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003185C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031860: mul.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80031864: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80031868: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8003186C: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031870: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80031874: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031878: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8003187C: div.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80031880: j           L_80031908
    // 0x80031884: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
        goto L_80031908;
    // 0x80031884: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
L_80031888:
    // 0x80031888: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003188C: lwc1        $f10, 0x64FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64FC);
    // 0x80031890: c.olt.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80031894: bc1f        L_800318E0
    if (!c1cs) {
        // 0x80031898: nop
    
            goto L_800318E0;
    }
    // 0x80031898: nop

    // 0x8003189C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800318A0: lw          $v1, -0x498C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X498C);
    // 0x800318A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800318A8: beq         $v1, $at, L_800318E0
    if (ctx->r3 == ctx->r1) {
        // 0x800318AC: nop
    
            goto L_800318E0;
    }
    // 0x800318AC: nop

    // 0x800318B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800318B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800318B8: sw          $v1, -0x4990($at)
    MEM_W(-0X4990, ctx->r1) = ctx->r3;
    // 0x800318BC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800318C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800318C4: swc1        $f6, -0x499C($at)
    MEM_W(-0X499C, ctx->r1) = ctx->f6.u32l;
    // 0x800318C8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800318CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800318D0: swc1        $f6, -0x4998($at)
    MEM_W(-0X4998, ctx->r1) = ctx->f6.u32l;
    // 0x800318D4: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800318D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800318DC: swc1        $f6, -0x4994($at)
    MEM_W(-0X4994, ctx->r1) = ctx->f6.u32l;
L_800318E0:
    // 0x800318E0: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800318E4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800318E8: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800318EC: nop

    // 0x800318F0: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800318F4: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800318F8: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800318FC: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80031900: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031904: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
L_80031908:
    // 0x80031908: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8003190C: lw          $v1, -0x4990($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4990);
    // 0x80031910: bnel        $v1, $zero, L_80031940
    if (ctx->r3 != 0) {
        // 0x80031914: lb          $t4, 0x0($t5)
        ctx->r12 = MEM_B(ctx->r13, 0X0);
            goto L_80031940;
    }
    goto skip_5;
    // 0x80031914: lb          $t4, 0x0($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X0);
    skip_5:
    // 0x80031918: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003191C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80031920: swc1        $f6, -0x499C($at)
    MEM_W(-0X499C, ctx->r1) = ctx->f6.u32l;
    // 0x80031924: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80031928: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003192C: swc1        $f6, -0x4998($at)
    MEM_W(-0X4998, ctx->r1) = ctx->f6.u32l;
    // 0x80031930: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80031934: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80031938: swc1        $f6, -0x4994($at)
    MEM_W(-0X4994, ctx->r1) = ctx->f6.u32l;
    // 0x8003193C: lb          $t4, 0x0($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X0);
L_80031940:
    // 0x80031940: lb          $v0, 0x0($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X0);
    // 0x80031944: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80031948: beql        $at, $zero, L_80031958
    if (ctx->r1 == 0) {
        // 0x8003194C: addiu       $t6, $t6, 0x1
        ctx->r14 = ADD32(ctx->r14, 0X1);
            goto L_80031958;
    }
    goto skip_6;
    // 0x8003194C: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    skip_6:
    // 0x80031950: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
    // 0x80031954: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
L_80031958:
    // 0x80031958: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x8003195C: bne         $at, $zero, L_80031974
    if (ctx->r1 != 0) {
        // 0x80031960: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80031974;
    }
    // 0x80031960: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80031964: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80031968: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8003196C: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031970: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
L_80031974:
    // 0x80031974: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80031978: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x8003197C: j           L_80031994
    // 0x80031980: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
        goto L_80031994;
    // 0x80031980: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
L_80031984:
    // 0x80031984: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_80031988:
    // 0x80031988: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8003198C: bne         $t0, $zero, L_80031680
    if (ctx->r8 != 0) {
        // 0x80031990: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_80031680;
    }
    // 0x80031990: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_80031994:
    // 0x80031994: bne         $t7, $zero, L_80031664
    if (ctx->r15 != 0) {
        // 0x80031998: nop
    
            goto L_80031664;
    }
    // 0x80031998: nop

    // 0x8003199C: beq         $t6, $zero, L_800319C0
    if (ctx->r14 == 0) {
        // 0x800319A0: lbu         $t2, 0x1($sp)
        ctx->r10 = MEM_BU(ctx->r29, 0X1);
            goto L_800319C0;
    }
    // 0x800319A0: lbu         $t2, 0x1($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1);
    // 0x800319A4: lw          $t1, 0x14($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X14);
    // 0x800319A8: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x800319AC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800319B0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800319B4: lbu         $t0, 0x0($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X0);
    // 0x800319B8: or          $t0, $t0, $t2
    ctx->r8 = ctx->r8 | ctx->r10;
    // 0x800319BC: sb          $t0, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r8;
L_800319C0:
    // 0x800319C0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800319C4: sb          $t2, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r10;
    // 0x800319C8: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
L_800319CC:
    // 0x800319CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800319D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800319D4: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x800319D8: lw          $t1, -0x2710($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2710);
    // 0x800319DC: lw          $t0, -0x2708($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2708);
L_800319E0:
    // 0x800319E0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800319E4: blezl       $t2, L_80031A00
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800319E8: lhu         $v0, 0x0($t2)
        ctx->r2 = MEM_HU(ctx->r10, 0X0);
            goto L_80031A00;
    }
    goto skip_7;
    // 0x800319E8: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    skip_7:
    // 0x800319EC: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800319F0: or          $t3, $t3, $t2
    ctx->r11 = ctx->r11 | ctx->r10;
    // 0x800319F4: j           L_80031B58
    // 0x800319F8: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
        goto L_80031B58;
    // 0x800319F8: lw          $t3, 0x18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18);
    // 0x800319FC: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
L_80031A00:
    // 0x80031A00: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031A04: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80031A08: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80031A0C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80031A10: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80031A14: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80031A18: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80031A1C: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80031A20: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031A24: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80031A28: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80031A2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031A30: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80031A34: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80031A38: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80031A3C: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80031A40: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031A44: sub.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80031A48: lwc1        $f8, 0x6500($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6500);
    // 0x80031A4C: c.olt.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80031A50: bc1f        L_80031B58
    if (!c1cs) {
        // 0x80031A54: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80031B58;
    }
    // 0x80031A54: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80031A58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031A5C: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80031A60: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80031A64: neg.s       $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = -ctx->f8.fl;
    // 0x80031A68: c.ole.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x80031A6C: bc1t        L_80031B58
    if (c1cs) {
        // 0x80031A70: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80031B58;
    }
    // 0x80031A70: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80031A74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80031A78: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031A7C: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80031A80: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031A84: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_80031A88:
    // 0x80031A88: lhu         $v1, 0x2($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0X2);
    // 0x80031A8C: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x80031A90: andi        $t9, $v1, 0x8000
    ctx->r25 = ctx->r3 & 0X8000;
    // 0x80031A94: beql        $t9, $zero, L_80031AA8
    if (ctx->r25 == 0) {
        // 0x80031A98: sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3 << 4);
            goto L_80031AA8;
    }
    goto skip_8;
    // 0x80031A98: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    skip_8:
    // 0x80031A9C: andi        $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 & 0X7FFF;
    // 0x80031AA0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80031AA4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
L_80031AA8:
    // 0x80031AA8: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80031AAC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80031AB0: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80031AB4: mul.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80031AB8: nop

    // 0x80031ABC: mul.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80031AC0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80031AC4: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80031AC8: mul.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80031ACC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80031AD0: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80031AD4: beq         $t8, $zero, L_80031AE0
    if (ctx->r24 == 0) {
        // 0x80031AD8: add.s       $f6, $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_80031AE0;
    }
    // 0x80031AD8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80031ADC: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
L_80031AE0:
    // 0x80031AE0: c.ole.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x80031AE4: bc1fl       L_80031B5C
    if (!c1cs) {
        // 0x80031AE8: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80031B5C;
    }
    goto skip_9;
    // 0x80031AE8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    skip_9:
    // 0x80031AEC: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80031AF0: bne         $t4, $zero, L_80031A88
    if (ctx->r12 != 0) {
        // 0x80031AF4: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_80031A88;
    }
    // 0x80031AF4: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x80031AF8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80031AFC: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80031B00: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80031B04: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80031B08: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80031B0C: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x80031B10: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80031B14: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x80031B18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80031B1C: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80031B20: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80031B24: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80031B28: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80031B2C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80031B30: bne         $at, $zero, L_80031B48
    if (ctx->r1 != 0) {
        // 0x80031B34: sub.s       $f4, $f6, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
            goto L_80031B48;
    }
    // 0x80031B34: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80031B38: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80031B3C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80031B40: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80031B44: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
L_80031B48:
    // 0x80031B48: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80031B4C: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x80031B50: j           L_80031B64
    // 0x80031B54: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
        goto L_80031B64;
    // 0x80031B54: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
L_80031B58:
    // 0x80031B58: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_80031B5C:
    // 0x80031B5C: bne         $t0, $zero, L_800319E0
    if (ctx->r8 != 0) {
        // 0x80031B60: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_800319E0;
    }
    // 0x80031B60: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_80031B64:
    // 0x80031B64: bne         $t7, $zero, L_800319CC
    if (ctx->r15 != 0) {
        // 0x80031B68: nop
    
            goto L_800319CC;
    }
    // 0x80031B68: nop

    // 0x80031B6C: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x80031B70: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x80031B74: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80031B78: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80031B7C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80031B80: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80031B84: bne         $t0, $zero, L_80031660
    if (ctx->r8 != 0) {
        // 0x80031B88: sw          $t0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r8;
            goto L_80031660;
    }
    // 0x80031B88: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
L_80031B8C:
    // 0x80031B8C: jr          $ra
    // 0x80031B90: lb          $v0, 0x0($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X0);
    return;
    // 0x80031B90: lb          $v0, 0x0($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X0);
;}
RECOMP_FUNC void spectate_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BDC8: bltz        $a0, L_8001BDE4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001BDCC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001BDE4;
    }
    // 0x8001BDCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BDD0: lw          $t6, -0x4BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BA0);
    // 0x8001BDD4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001BDD8: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001BDDC: bne         $at, $zero, L_8001BDEC
    if (ctx->r1 != 0) {
        // 0x8001BDE0: nop
    
            goto L_8001BDEC;
    }
    // 0x8001BDE0: nop

L_8001BDE4:
    // 0x8001BDE4: jr          $ra
    // 0x8001BDE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BDE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BDEC:
    // 0x8001BDEC: lw          $t7, -0x4BA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4BA4);
    // 0x8001BDF0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8001BDF4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001BDF8: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8001BDFC: nop

    // 0x8001BE00: jr          $ra
    // 0x8001BE04: nop

    return;
    // 0x8001BE04: nop

;}
RECOMP_FUNC void set_voice_limit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B010: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000B014: jr          $ra
    // 0x8000B018: sb          $a1, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r5;
    return;
    // 0x8000B018: sb          $a1, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void mtx_shear_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800691E8: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x800691EC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800691F0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x800691F4: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x800691F8: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800691FC: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x80069200: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80069204: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x80069208: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8006920C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x80069210: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80069214: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x80069218: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8006921C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80069220: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80069224: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80069228: sw          $a0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r4;
    // 0x8006922C: sw          $a1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r5;
    // 0x80069230: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x80069234: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80069238: jal         0x80070A38
    // 0x8006923C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x8006923C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    after_0:
    // 0x80069240: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80069244: jal         0x80070A04
    // 0x80069248: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80069248: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    after_1:
    // 0x8006924C: swc1        $f0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f0.u32l;
    // 0x80069250: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80069254: jal         0x80070A38
    // 0x80069258: nop

    coss_f(rdram, ctx);
        goto after_2;
    // 0x80069258: nop

    after_2:
    // 0x8006925C: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80069260: jal         0x80070A04
    // 0x80069264: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80069264: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_3:
    // 0x80069268: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8006926C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80069270: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
    // 0x80069274: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80069278: nop

    // 0x8006927C: swc1        $f10, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f10.u32l;
    // 0x80069280: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80069284: nop

    // 0x80069288: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x8006928C: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x80069290: jal         0x80070A38
    // 0x80069294: nop

    coss_f(rdram, ctx);
        goto after_4;
    // 0x80069294: nop

    after_4:
    // 0x80069298: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x8006929C: jal         0x80070A04
    // 0x800692A0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_5;
    // 0x800692A0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x800692A4: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x800692A8: jal         0x80070A38
    // 0x800692AC: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    coss_f(rdram, ctx);
        goto after_6;
    // 0x800692AC: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    after_6:
    // 0x800692B0: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x800692B4: jal         0x80070A04
    // 0x800692B8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    sins_f(rdram, ctx);
        goto after_7;
    // 0x800692B8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    after_7:
    // 0x800692BC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800692C0: jal         0x80070A38
    // 0x800692C4: swc1        $f0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_8;
    // 0x800692C4: swc1        $f0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x800692C8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800692CC: jal         0x80070A04
    // 0x800692D0: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    sins_f(rdram, ctx);
        goto after_9;
    // 0x800692D0: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x800692D4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800692D8: lwc1        $f16, 0x138($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X138);
    // 0x800692DC: swc1        $f6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f6.u32l;
    // 0x800692E0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800692E4: lwc1        $f14, 0x100($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800692E8: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x800692EC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800692F0: lwc1        $f12, 0xFC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x800692F4: swc1        $f10, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f10.u32l;
    // 0x800692F8: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800692FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80069300: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80069304: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80069308: addiu       $s0, $s0, 0x1620
    ctx->r16 = ADD32(ctx->r16, 0X1620);
    // 0x8006930C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069310: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80069314: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    // 0x80069318: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8006931C: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80069320: mul.s       $f6, $f20, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x80069324: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    // 0x80069328: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8006932C: nop

    // 0x80069330: mul.s       $f10, $f26, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x80069334: neg.s       $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = -ctx->f24.fl;
    // 0x80069338: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x8006933C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80069340: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069344: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80069348: mul.s       $f6, $f28, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x8006934C: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80069350: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x80069354: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80069358: nop

    // 0x8006935C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80069360: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80069364: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80069368: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006936C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80069370: nop

    // 0x80069374: mul.s       $f4, $f26, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f28.fl);
    // 0x80069378: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x8006937C: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x80069380: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x80069384: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x80069388: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8006938C: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80069390: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80069394: nop

    // 0x80069398: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8006939C: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800693A0: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800693A4: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800693A8: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x800693AC: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800693B0: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x800693B4: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800693B8: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800693BC: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800693C0: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800693C4: nop

    // 0x800693C8: mul.s       $f10, $f26, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f10.fl);
    // 0x800693CC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800693D0: mul.s       $f10, $f28, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f12.fl);
    // 0x800693D4: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800693D8: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800693DC: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800693E0: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x800693E4: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800693E8: nop

    // 0x800693EC: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800693F0: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800693F4: nop

    // 0x800693F8: mul.s       $f10, $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800693FC: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80069400: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80069404: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80069408: nop

    // 0x8006940C: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x80069410: swc1        $f6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f6.u32l;
    // 0x80069414: neg.s       $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = -ctx->f26.fl;
    // 0x80069418: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x8006941C: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80069420: nop

    // 0x80069424: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80069428: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8006942C: nop

    // 0x80069430: mul.s       $f10, $f20, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80069434: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069438: mul.s       $f10, $f24, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x8006943C: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x80069440: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80069444: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80069448: mul.s       $f4, $f22, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x8006944C: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80069450: lwc1        $f4, 0x118($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80069454: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x80069458: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006945C: nop

    // 0x80069460: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80069464: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80069468: nop

    // 0x8006946C: mul.s       $f10, $f10, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x80069470: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80069474: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80069478: nop

    // 0x8006947C: mul.s       $f12, $f20, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80069480: swc1        $f4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f4.u32l;
    // 0x80069484: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80069488: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8006948C: mul.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80069490: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80069494: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80069498: add.s       $f26, $f10, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8006949C: lwc1        $f6, 0x118($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800694A0: mul.s       $f10, $f12, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f30.fl);
    // 0x800694A4: nop

    // 0x800694A8: mul.s       $f6, $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800694AC: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800694B0: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800694B4: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800694B8: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x800694BC: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800694C0: nop

    // 0x800694C4: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800694C8: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800694CC: nop

    // 0x800694D0: mul.s       $f6, $f20, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x800694D4: add.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800694D8: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800694DC: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800694E0: mul.s       $f6, $f24, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f10.fl);
    // 0x800694E4: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800694E8: lwc1        $f20, 0x6C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800694EC: mul.s       $f10, $f22, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x800694F0: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800694F4: lwc1        $f10, 0x118($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X118);
    // 0x800694F8: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x800694FC: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80069500: nop

    // 0x80069504: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80069508: nop

    // 0x8006950C: mul.s       $f6, $f14, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x80069510: lwc1        $f14, 0x118($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80069514: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069518: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8006951C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80069520: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80069524: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x80069528: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x8006952C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80069530: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80069534: mul.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80069538: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8006953C: nop

    // 0x80069540: mul.s       $f10, $f30, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f10.fl);
    // 0x80069544: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069548: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8006954C: nop

    // 0x80069550: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80069554: swc1        $f10, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f10.u32l;
    // 0x80069558: mul.s       $f10, $f30, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f26.fl);
    // 0x8006955C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069560: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80069564: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    // 0x80069568: mul.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8006956C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80069570: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80069574: mul.s       $f10, $f30, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f10.fl);
    // 0x80069578: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8006957C: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80069580: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80069584: lwc1        $f2, 0xEC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x80069588: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    // 0x8006958C: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x80069590: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80069594: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80069598: nop

    // 0x8006959C: mul.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800695A0: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800695A4: nop

    // 0x800695A8: mul.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800695AC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800695B0: lwc1        $f10, 0xEC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800695B4: nop

    // 0x800695B8: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800695BC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800695C0: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800695C4: nop

    // 0x800695C8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800695CC: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800695D0: swc1        $f10, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f10.u32l;
    // 0x800695D4: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800695D8: nop

    // 0x800695DC: mul.s       $f10, $f14, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800695E0: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800695E4: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800695E8: lwc1        $f4, 0xE4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800695EC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800695F0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800695F4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800695F8: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800695FC: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80069600: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    // 0x80069604: mul.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80069608: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8006960C: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80069610: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80069614: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80069618: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006961C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80069620: swc1        $f10, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f10.u32l;
    // 0x80069624: jal         0x8006F9A8
    // 0x80069628: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    mtxf_mul(rdram, ctx);
        goto after_10;
    // 0x80069628: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x8006962C: lw          $t3, 0x12C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X12C);
    // 0x80069630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80069634: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80069638: jal         0x8006FAB0
    // 0x8006963C: nop

    mtxf_to_mtx(rdram, ctx);
        goto after_11;
    // 0x8006963C: nop

    after_11:
    // 0x80069640: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x80069644: lw          $a0, 0x12C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X12C);
    // 0x80069648: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8006964C: lui         $t5, 0x140
    ctx->r13 = S32(0X140 << 16);
    // 0x80069650: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80069654: ori         $t5, $t5, 0x40
    ctx->r13 = ctx->r13 | 0X40;
    // 0x80069658: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8006965C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80069660: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80069664: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80069668: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x8006966C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80069670: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80069674: nop

    // 0x80069678: addiu       $t9, $t8, 0x40
    ctx->r25 = ADD32(ctx->r24, 0X40);
    // 0x8006967C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80069680: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80069684: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80069688: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8006968C: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80069690: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80069694: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80069698: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8006969C: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800696A0: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800696A4: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800696A8: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800696AC: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800696B0: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800696B4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800696B8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800696BC: jr          $ra
    // 0x800696C0: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x800696C0: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void leveltable_vehicle_usable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B338: blez        $a0, L_8006B380
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006B33C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B380;
    }
    // 0x8006B33C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B340: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006B344: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B348: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B34C: beq         $at, $zero, L_8006B380
    if (ctx->r1 == 0) {
        // 0x8006B350: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B380;
    }
    // 0x8006B350: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B354: lw          $t7, 0x16FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16FC);
    // 0x8006B358: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B35C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B360: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B364: lb          $v1, 0x2($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X2);
    // 0x8006B368: nop

    // 0x8006B36C: beq         $v1, $zero, L_8006B380
    if (ctx->r3 == 0) {
        // 0x8006B370: sra         $v0, $v1, 4
        ctx->r2 = S32(SIGNED(ctx->r3) >> 4);
            goto L_8006B380;
    }
    // 0x8006B370: sra         $v0, $v1, 4
    ctx->r2 = S32(SIGNED(ctx->r3) >> 4);
    // 0x8006B374: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x8006B378: jr          $ra
    // 0x8006B37C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8006B37C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8006B380:
    // 0x8006B380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B384: jr          $ra
    // 0x8006B388: nop

    return;
    // 0x8006B388: nop

;}
RECOMP_FUNC void menu_game_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C9C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C9C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008C9C8: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008C9CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C9D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008C9D4: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008C9D8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008C9DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C9E0: addiu       $s4, $s4, 0x6980
    ctx->r20 = ADD32(ctx->r20, 0X6980);
    // 0x8008C9E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008C9E8: sw          $zero, -0x620($at)
    MEM_W(-0X620, ctx->r1) = 0;
    // 0x8008C9EC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8008C9F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C9F4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008C9F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008C9FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008CA00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CA04: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8008CA08: jal         0x800C06F8
    // 0x8008CA0C: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x8008CA0C: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_0:
    // 0x8008CA10: jal         0x8006EDE8
    // 0x8008CA14: nop

    mark_read_all_save_files(rdram, ctx);
        goto after_1;
    // 0x8008CA14: nop

    after_1:
    // 0x8008CA18: jal         0x8001B7C4
    // 0x8008CA1C: nop

    set_ghost_none(rdram, ctx);
        goto after_2;
    // 0x8008CA1C: nop

    after_2:
    // 0x8008CA20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008CA24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008CA28: sw          $t7, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r15;
    // 0x8008CA2C: jal         0x8009CC18
    // 0x8008CA30: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    menu_asset_load(rdram, ctx);
        goto after_3;
    // 0x8008CA30: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_3:
    // 0x8008CA34: jal         0x8008043C
    // 0x8008CA38: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8007FFEC(rdram, ctx);
        goto after_4;
    // 0x8008CA38: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x8008CA3C: jal         0x800C46D0
    // 0x8008CA40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_5;
    // 0x8008CA40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x8008CA44: jal         0x80000B34
    // 0x8008CA48: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    music_play(rdram, ctx);
        goto after_6;
    // 0x8008CA48: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_6:
    // 0x8008CA4C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008CA50: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008CA54: addiu       $s2, $s2, 0x6954
    ctx->r18 = ADD32(ctx->r18, 0X6954);
    // 0x8008CA58: addiu       $s3, $s3, 0x334
    ctx->r19 = ADD32(ctx->r19, 0X334);
    // 0x8008CA5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8008CA60:
    // 0x8008CA60: lb          $t8, 0x0($s2)
    ctx->r24 = MEM_B(ctx->r18, 0X0);
    // 0x8008CA64: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x8008CA68: beq         $s0, $t8, L_8008CA88
    if (ctx->r16 == ctx->r24) {
        // 0x8008CA6C: addu        $s1, $s3, $t9
        ctx->r17 = ADD32(ctx->r19, ctx->r25);
            goto L_8008CA88;
    }
    // 0x8008CA6C: addu        $s1, $s3, $t9
    ctx->r17 = ADD32(ctx->r19, ctx->r25);
    // 0x8008CA70: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8008CA74: jal         0x80001114
    // 0x8008CA78: nop

    music_channel_off(rdram, ctx);
        goto after_7;
    // 0x8008CA78: nop

    after_7:
    // 0x8008CA7C: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x8008CA80: jal         0x80001114
    // 0x8008CA84: nop

    music_channel_off(rdram, ctx);
        goto after_8;
    // 0x8008CA84: nop

    after_8:
L_8008CA88:
    // 0x8008CA88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008CA8C: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8008CA90: bne         $at, $zero, L_8008CA60
    if (ctx->r1 != 0) {
        // 0x8008CA94: nop
    
            goto L_8008CA60;
    }
    // 0x8008CA94: nop

    // 0x8008CA98: jal         0x80001114
    // 0x8008CA9C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_channel_off(rdram, ctx);
        goto after_9;
    // 0x8008CA9C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
    // 0x8008CAA0: jal         0x80000B18
    // 0x8008CAA4: nop

    music_change_off(rdram, ctx);
        goto after_10;
    // 0x8008CAA4: nop

    after_10:
    // 0x8008CAA8: jal         0x8009F1A4
    // 0x8008CAAC: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_11;
    // 0x8008CAAC: nop

    after_11:
    // 0x8008CAB0: beq         $v0, $zero, L_8008CAD8
    if (ctx->r2 == 0) {
        // 0x8008CAB4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8008CAD8;
    }
    // 0x8008CAB4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008CAB8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008CABC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008CAC0: addiu       $v1, $v1, 0x6A00
    ctx->r3 = ADD32(ctx->r3, 0X6A00);
    // 0x8008CAC4: addiu       $t0, $t0, 0x7F8
    ctx->r8 = ADD32(ctx->r8, 0X7F8);
    // 0x8008CAC8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8008CACC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8008CAD0: b           L_8008CAF0
    // 0x8008CAD4: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
        goto L_8008CAF0;
    // 0x8008CAD4: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
L_8008CAD8:
    // 0x8008CAD8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008CADC: addiu       $v1, $v1, 0x6A00
    ctx->r3 = ADD32(ctx->r3, 0X6A00);
    // 0x8008CAE0: addiu       $t2, $t2, 0x718
    ctx->r10 = ADD32(ctx->r10, 0X718);
    // 0x8008CAE4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008CAE8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8008CAEC: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
L_8008CAF0:
    // 0x8008CAF0: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8008CAF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008CAF8: bltz        $t4, L_8008CB30
    if (SIGNED(ctx->r12) < 0) {
        // 0x8008CAFC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8008CB30;
    }
    // 0x8008CAFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008CB00: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
L_8008CB04:
    // 0x8008CB04: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008CB08: or          $t7, $s0, $zero
    ctx->r15 = ctx->r16 | 0;
    // 0x8008CB0C: lw          $t5, 0x10C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10C);
    // 0x8008CB10: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8008CB14: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8008CB18: sw          $t5, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->r13;
    // 0x8008CB1C: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x8008CB20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008CB24: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8008CB28: beq         $at, $zero, L_8008CB04
    if (ctx->r1 == 0) {
        // 0x8008CB2C: nop
    
            goto L_8008CB04;
    }
    // 0x8008CB2C: nop

L_8008CB30:
    // 0x8008CB30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008CB34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008CB38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CB3C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008CB40: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008CB44: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008CB48: jr          $ra
    // 0x8008CB4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008CB4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void catmull_rom_interpolation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022574: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80022578: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002257C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80022580: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80022584: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80022588: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8002258C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022590: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022594: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80022598: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002259C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800225A0: cvt.d.s     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f12.d = CVT_D_S(ctx->f6.fl);
    // 0x800225A4: mul.d       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f14.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800225A8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800225AC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800225B0: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800225B4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800225B8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800225BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800225C0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800225C4: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x800225C8: lui         $at, 0xBFF8
    ctx->r1 = S32(0XBFF8 << 16);
    // 0x800225CC: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800225D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800225D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800225D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800225DC: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800225E0: add.d       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f14.d + ctx->f8.d;
    // 0x800225E4: lui         $at, 0xC004
    ctx->r1 = S32(0XC004 << 16);
    // 0x800225E8: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x800225EC: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x800225F0: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x800225F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800225F8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800225FC: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80022600: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022604: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80022608: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x8002260C: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x80022610: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x80022614: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x80022618: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002261C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80022620: nop

    // 0x80022624: mul.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x80022628: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x8002262C: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80022630: mul.d       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x80022634: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80022638: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x8002263C: add.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f8.d + ctx->f14.d;
    // 0x80022640: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80022644: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80022648: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x8002264C: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80022650: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80022654: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80022658: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8002265C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80022660: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80022664: add.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80022668: jr          $ra
    // 0x8002266C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8002266C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void alCSPSetTempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7F40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7F44: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800C7F48: and         $t9, $a1, $at
    ctx->r25 = ctx->r5 & ctx->r1;
    // 0x800C7F4C: andi        $t2, $a1, 0xFF00
    ctx->r10 = ctx->r5 & 0XFF00;
    // 0x800C7F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7F54: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x800C7F58: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800C7F5C: addiu       $t8, $zero, 0x51
    ctx->r24 = ADD32(0, 0X51);
    // 0x800C7F60: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800C7F64: sra         $t3, $t2, 8
    ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
    // 0x800C7F68: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
    // 0x800C7F6C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7F70: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x800C7F74: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x800C7F78: sb          $t1, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r9;
    // 0x800C7F7C: sb          $t3, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r11;
    // 0x800C7F80: sb          $t4, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r12;
    // 0x800C7F84: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7F88: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C7F8C: jal         0x800C970C
    // 0x800C7F90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7F90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C7F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7F9C: jr          $ra
    // 0x800C7FA0: nop

    return;
    // 0x800C7FA0: nop

;}
RECOMP_FUNC void calc_dynamic_lighting_for_object_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024784: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80024788: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x8002478C: sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // 0x80024790: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x80024794: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x80024798: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x8002479C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800247A0: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x800247A4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800247A8: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800247AC: beq         $t9, $zero, L_800249FC
    if (ctx->r25 == 0) {
        // 0x800247B0: or          $s3, $a3, $zero
        ctx->r19 = ctx->r7 | 0;
            goto L_800249FC;
    }
    // 0x800247B0: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800247B4: lh          $t0, 0x1C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X1C);
    // 0x800247B8: lh          $t1, 0x1E($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X1E);
    // 0x800247BC: lh          $t2, 0x20($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X20);
    // 0x800247C0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800247C4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800247C8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800247CC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800247D0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800247D4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800247D8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800247DC: addiu       $t8, $sp, 0x10
    ctx->r24 = ADD32(ctx->r29, 0X10);
    // 0x800247E0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800247E4: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800247E8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800247EC: swc1        $f6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f6.u32l;
    // 0x800247F0: beq         $a2, $zero, L_80024810
    if (ctx->r6 == 0) {
        // 0x800247F4: swc1        $f8, 0x8($t8)
        MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
            goto L_80024810;
    }
    // 0x800247F4: swc1        $f8, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
    // 0x800247F8: jal         0x80069FE4
    // 0x800247FC: nop

    get_projection_matrix_f32(rdram, ctx);
        goto after_0;
    // 0x800247FC: nop

    after_0:
    // 0x80024800: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80024804: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024808: jal         0x8006F92C
    // 0x8002480C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_1;
    // 0x8002480C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_1:
L_80024810:
    // 0x80024810: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x80024814: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x80024818: addiu       $v1, $zero, 0x0
    ctx->r3 = ADD32(0, 0X0);
    // 0x8002481C: sub         $t0, $zero, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x80024820: sh          $t0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r8;
    // 0x80024824: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x80024828: lui         $v0, 0x3F80
    ctx->r2 = S32(0X3F80 << 16);
    // 0x8002482C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80024830: sub         $t1, $zero, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x80024834: sh          $t1, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r9;
    // 0x80024838: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x8002483C: sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
    // 0x80024840: sw          $v1, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r3;
    // 0x80024844: sub         $t2, $zero, $t2
    ctx->r10 = SUB32(0, ctx->r10);
    // 0x80024848: sh          $t2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r10;
    // 0x8002484C: sw          $v1, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r3;
    // 0x80024850: sw          $v1, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r3;
    // 0x80024854: jal         0x800700B4
    // 0x80024858: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_2;
    // 0x80024858: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_2:
    // 0x8002485C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80024860: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80024864: jal         0x8006F92C
    // 0x80024868: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    mtxf_transform_dir(rdram, ctx);
        goto after_3;
    // 0x80024868: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_3:
    // 0x8002486C: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x80024870: mtc1        $s3, $f6
    ctx->f6.u32l = ctx->r19;
    // 0x80024874: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80024878: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8002487C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80024880: lw          $v1, 0x2C($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X2C);
    // 0x80024884: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80024888: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x8002488C: addiu       $t0, $sp, 0x10
    ctx->r8 = ADD32(ctx->r29, 0X10);
    // 0x80024890: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80024894: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80024898: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8002489C: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x800248A0: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x800248A4: lh          $t0, 0x28($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X28);
    // 0x800248A8: lw          $t5, 0x38($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X38);
    // 0x800248AC: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800248B0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800248B4: lw          $s3, 0x44($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X44);
    // 0x800248B8: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x800248BC: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800248C0: nop

    // 0x800248C4: mul.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800248C8: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800248CC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800248D0: nop

    // 0x800248D4: ori         $v1, $v0, 0x3
    ctx->r3 = ctx->r2 | 0X3;
    // 0x800248D8: xori        $v1, $v1, 0x2
    ctx->r3 = ctx->r3 ^ 0X2;
    // 0x800248DC: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x800248E0: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x800248E4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800248E8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800248EC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800248F0: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800248F4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800248F8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800248FC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80024900: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80024904: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80024908: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002490C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80024910: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80024914: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x80024918: add         $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x8002491C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80024920: add         $s2, $s2, $t5
    ctx->r18 = ADD32(ctx->r18, ctx->r13);
    // 0x80024924: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
L_80024928:
    // 0x80024928: lh          $v0, 0x2($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X2);
    // 0x8002492C: lh          $v1, 0xE($t5)
    ctx->r3 = MEM_H(ctx->r13, 0XE);
    // 0x80024930: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80024934: bne         $t0, $at, L_80024968
    if (ctx->r8 != ctx->r1) {
        // 0x80024938: sub         $t4, $v1, $v0
        ctx->r12 = SUB32(ctx->r3, ctx->r2);
            goto L_80024968;
    }
    // 0x80024938: sub         $t4, $v1, $v0
    ctx->r12 = SUB32(ctx->r3, ctx->r2);
    // 0x8002493C: lw          $t1, 0x8($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X8);
    // 0x80024940: sll         $v0, $t4, 3
    ctx->r2 = S32(ctx->r12 << 3);
    // 0x80024944: sll         $v1, $t4, 1
    ctx->r3 = S32(ctx->r12 << 1);
    // 0x80024948: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002494C: andi        $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 & 0X8000;
    // 0x80024950: beq         $t1, $zero, L_800249EC
    if (ctx->r9 == 0) {
        // 0x80024954: add         $s3, $s3, $v0
        ctx->r19 = ADD32(ctx->r19, ctx->r2);
            goto L_800249EC;
    }
    // 0x80024954: add         $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x80024958: sll         $v0, $t4, 2
    ctx->r2 = S32(ctx->r12 << 2);
    // 0x8002495C: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024960: b           L_800249EC
    // 0x80024964: add         $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
        goto L_800249EC;
    // 0x80024964: add         $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_80024968:
    // 0x80024968: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8002496C: mult        $t0, $a2
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024970: mflo        $a1
    ctx->r5 = lo;
    // 0x80024974: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x80024978: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x8002497C: mult        $t1, $a3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024980: mflo        $v0
    ctx->r2 = lo;
    // 0x80024984: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x80024988: add         $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8002498C: mult        $t2, $t6
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024990: mflo        $v0
    ctx->r2 = lo;
    // 0x80024994: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x80024998: add         $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8002499C: sra         $a1, $a1, 7
    ctx->r5 = S32(SIGNED(ctx->r5) >> 7);
    // 0x800249A0: bgtz        $a1, L_800249B0
    if (SIGNED(ctx->r5) > 0) {
        // 0x800249A4: nop
    
            goto L_800249B0;
    }
    // 0x800249A4: nop

    // 0x800249A8: b           L_800249D0
    // 0x800249AC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
        goto L_800249D0;
    // 0x800249AC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_800249B0:
    // 0x800249B0: mult        $a1, $t7
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800249B4: mflo        $a1
    ctx->r5 = lo;
    // 0x800249B8: srl         $a1, $a1, 21
    ctx->r5 = S32(U32(ctx->r5) >> 21);
    // 0x800249BC: add         $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800249C0: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x800249C4: bnel        $at, $zero, L_800249D4
    if (ctx->r1 != 0) {
        // 0x800249C8: sll         $v0, $a1, 8
        ctx->r2 = S32(ctx->r5 << 8);
            goto L_800249D4;
    }
    goto skip_0;
    // 0x800249C8: sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5 << 8);
    skip_0:
    // 0x800249CC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_800249D0:
    // 0x800249D0: sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5 << 8);
L_800249D4:
    // 0x800249D4: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x800249D8: sh          $a1, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r5;
    // 0x800249DC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800249E0: sh          $a1, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r5;
    // 0x800249E4: bne         $t4, $zero, L_80024968
    if (ctx->r12 != 0) {
        // 0x800249E8: addiu       $s3, $s3, 0xA
        ctx->r19 = ADD32(ctx->r19, 0XA);
            goto L_80024968;
    }
    // 0x800249E8: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
L_800249EC:
    // 0x800249EC: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800249F0: slt         $at, $t5, $s2
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800249F4: bnel        $at, $zero, L_80024928
    if (ctx->r1 != 0) {
        // 0x800249F8: lbu         $t0, 0x6($t5)
        ctx->r8 = MEM_BU(ctx->r13, 0X6);
            goto L_80024928;
    }
    goto skip_1;
    // 0x800249F8: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
    skip_1:
L_800249FC:
    // 0x800249FC: lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X78);
    // 0x80024A00: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x80024A04: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x80024A08: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x80024A0C: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x80024A10: jr          $ra
    // 0x80024A14: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80024A14: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80024A18: nop

;}
RECOMP_FUNC void func_8002FA64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FAA4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8002FAA8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002FAAC: lw          $v1, -0x3850($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3850);
    // 0x8002FAB0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002FAB4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8002FAB8: sw          $s7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r23;
    // 0x8002FABC: sw          $s6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r22;
    // 0x8002FAC0: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x8002FAC4: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8002FAC8: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x8002FACC: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x8002FAD0: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8002FAD4: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x8002FAD8: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8002FADC: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x8002FAE0: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002FAE4: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8002FAE8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002FAEC: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002FAF0: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002FAF4: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8002FAF8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002FAFC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002FB00: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002FB04: blez        $v1, L_8002FD48
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002FB08: swc1        $f20, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
            goto L_8002FD48;
    }
    // 0x8002FB08: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002FB0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002FB10: lw          $t6, -0x2994($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2994);
    // 0x8002FB14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002FB18: beq         $t6, $zero, L_8002FB54
    if (ctx->r14 == 0) {
        // 0x8002FB1C: nop
    
            goto L_8002FB54;
    }
    // 0x8002FB1C: nop

    // 0x8002FB20: lw          $v0, -0x2998($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2998);
    // 0x8002FB24: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8002FB28: blez        $v0, L_8002FD1C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002FB2C: addiu       $s6, $s6, -0x320C
        ctx->r22 = ADD32(ctx->r22, -0X320C);
            goto L_8002FD1C;
    }
    // 0x8002FB2C: addiu       $s6, $s6, -0x320C
    ctx->r22 = ADD32(ctx->r22, -0X320C);
    // 0x8002FB30: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8002FB34: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x8002FB38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002FB3C: lwc1        $f6, -0x299C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X299C);
    // 0x8002FB40: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8002FB44: nop

    // 0x8002FB48: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002FB4C: b           L_8002FD1C
    // 0x8002FB50: nop

        goto L_8002FD1C;
    // 0x8002FB50: nop

L_8002FB54:
    // 0x8002FB54: blez        $v1, L_8002FD1C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002FB58: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8002FD1C;
    }
    // 0x8002FB58: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002FB5C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002FB60: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x8002FB64: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002FB68: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002FB6C: addiu       $s4, $s4, -0x4750
    ctx->r20 = ADD32(ctx->r20, -0X4750);
    // 0x8002FB70: addiu       $s5, $s5, -0x4960
    ctx->r21 = ADD32(ctx->r21, -0X4960);
    // 0x8002FB74: addiu       $s6, $s6, -0x320C
    ctx->r22 = ADD32(ctx->r22, -0X320C);
    // 0x8002FB78: addiu       $s3, $s3, -0x3848
    ctx->r19 = ADD32(ctx->r19, -0X3848);
L_8002FB7C:
    // 0x8002FB7C: lh          $t9, 0xA($s3)
    ctx->r25 = MEM_H(ctx->r19, 0XA);
    // 0x8002FB80: nop

    // 0x8002FB84: blez        $t9, L_8002FD0C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002FB88: nop
    
            goto L_8002FD0C;
    }
    // 0x8002FB88: nop

    // 0x8002FB8C: lbu         $s1, 0x1($s3)
    ctx->r17 = MEM_BU(ctx->r19, 0X1);
    // 0x8002FB90: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x8002FB94: andi        $t0, $s1, 0x1
    ctx->r8 = ctx->r17 & 0X1;
    // 0x8002FB98: beq         $t0, $zero, L_8002FBC0
    if (ctx->r8 == 0) {
        // 0x8002FB9C: nop
    
            goto L_8002FBC0;
    }
    // 0x8002FB9C: nop

    // 0x8002FBA0: lbu         $t1, 0x2($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X2);
    // 0x8002FBA4: nop

    // 0x8002FBA8: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8002FBAC: addu        $v0, $s4, $t2
    ctx->r2 = ADD32(ctx->r20, ctx->r10);
    // 0x8002FBB0: lwc1        $f28, 0x0($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FBB4: lwc1        $f30, 0x8($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FBB8: b           L_8002FBE0
    // 0x8002FBBC: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
        goto L_8002FBE0;
    // 0x8002FBBC: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
L_8002FBC0:
    // 0x8002FBC0: lbu         $t3, 0x2($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X2);
    // 0x8002FBC4: nop

    // 0x8002FBC8: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8002FBCC: addu        $v0, $s5, $t4
    ctx->r2 = ADD32(ctx->r21, ctx->r12);
    // 0x8002FBD0: lwc1        $f28, 0x0($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FBD4: lwc1        $f30, 0x8($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FBD8: nop

    // 0x8002FBDC: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
L_8002FBE0:
    // 0x8002FBE0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8002FBE4: beq         $t6, $zero, L_8002FC0C
    if (ctx->r14 == 0) {
        // 0x8002FBE8: or          $s1, $t5, $zero
        ctx->r17 = ctx->r13 | 0;
            goto L_8002FC0C;
    }
    // 0x8002FBE8: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x8002FBEC: lbu         $t7, 0x3($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X3);
    // 0x8002FBF0: nop

    // 0x8002FBF4: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8002FBF8: addu        $v0, $s4, $t8
    ctx->r2 = ADD32(ctx->r20, ctx->r24);
    // 0x8002FBFC: lwc1        $f24, 0x0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FC00: lwc1        $f26, 0x8($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FC04: b           L_8002FC2C
    // 0x8002FC08: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
        goto L_8002FC2C;
    // 0x8002FC08: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
L_8002FC0C:
    // 0x8002FC0C: lbu         $t9, 0x3($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X3);
    // 0x8002FC10: nop

    // 0x8002FC14: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8002FC18: addu        $v0, $s5, $t0
    ctx->r2 = ADD32(ctx->r21, ctx->r8);
    // 0x8002FC1C: lwc1        $f24, 0x0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FC20: lwc1        $f26, 0x8($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FC24: nop

    // 0x8002FC28: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
L_8002FC2C:
    // 0x8002FC2C: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8002FC30: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8002FC34: bne         $at, $zero, L_8002FD0C
    if (ctx->r1 != 0) {
        // 0x8002FC38: or          $s1, $t1, $zero
        ctx->r17 = ctx->r9 | 0;
            goto L_8002FD0C;
    }
    // 0x8002FC38: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8002FC3C: sll         $t3, $s7, 2
    ctx->r11 = S32(ctx->r23 << 2);
    // 0x8002FC40: subu        $t3, $t3, $s7
    ctx->r11 = SUB32(ctx->r11, ctx->r23);
    // 0x8002FC44: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002FC48: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002FC4C: addiu       $t5, $t5, -0x3848
    ctx->r13 = ADD32(ctx->r13, -0X3848);
    // 0x8002FC50: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x8002FC54: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
L_8002FC58:
    // 0x8002FC58: andi        $t6, $s1, 0x1
    ctx->r14 = ctx->r17 & 0X1;
    // 0x8002FC5C: beq         $t6, $zero, L_8002FC84
    if (ctx->r14 == 0) {
        // 0x8002FC60: nop
    
            goto L_8002FC84;
    }
    // 0x8002FC60: nop

    // 0x8002FC64: lbu         $t7, 0x2($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2);
    // 0x8002FC68: nop

    // 0x8002FC6C: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8002FC70: addu        $v0, $s4, $t8
    ctx->r2 = ADD32(ctx->r20, ctx->r24);
    // 0x8002FC74: lwc1        $f20, 0x0($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FC78: lwc1        $f22, 0x8($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FC7C: b           L_8002FCA4
    // 0x8002FC80: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
        goto L_8002FCA4;
    // 0x8002FC80: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
L_8002FC84:
    // 0x8002FC84: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    // 0x8002FC88: nop

    // 0x8002FC8C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8002FC90: addu        $v0, $s5, $t0
    ctx->r2 = ADD32(ctx->r21, ctx->r8);
    // 0x8002FC94: lwc1        $f20, 0x0($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FC98: lwc1        $f22, 0x8($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FC9C: nop

    // 0x8002FCA0: sra         $t1, $s1, 1
    ctx->r9 = S32(SIGNED(ctx->r17) >> 1);
L_8002FCA4:
    // 0x8002FCA4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8002FCA8: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8002FCAC: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x8002FCB0: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x8002FCB4: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    // 0x8002FCB8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8002FCBC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8002FCC0: jal         0x80070C6C
    // 0x8002FCC4: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    area_triangle_2d(rdram, ctx);
        goto after_0;
    // 0x8002FCC4: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8002FCC8: lh          $t2, 0xA($s3)
    ctx->r10 = MEM_H(ctx->r19, 0XA);
    // 0x8002FCCC: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x8002FCD0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8002FCD4: addu        $t4, $s6, $t3
    ctx->r12 = ADD32(ctx->r22, ctx->r11);
    // 0x8002FCD8: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8002FCDC: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8002FCE0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8002FCE4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002FCE8: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002FCEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002FCF0: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
    // 0x8002FCF4: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
    // 0x8002FCF8: bne         $at, $zero, L_8002FC58
    if (ctx->r1 != 0) {
        // 0x8002FCFC: add.s       $f2, $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
            goto L_8002FC58;
    }
    // 0x8002FCFC: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8002FD00: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002FD04: lw          $v1, -0x3850($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3850);
    // 0x8002FD08: nop

L_8002FD0C:
    // 0x8002FD0C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8002FD10: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002FD14: bne         $at, $zero, L_8002FB7C
    if (ctx->r1 != 0) {
        // 0x8002FD18: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_8002FB7C;
    }
    // 0x8002FD18: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
L_8002FD1C:
    // 0x8002FD1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002FD20: lwc1        $f12, -0x299C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X299C);
    // 0x8002FD24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002FD28: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8002FD2C: nop

    // 0x8002FD30: bc1f        L_8002FD48
    if (!c1cs) {
        // 0x8002FD34: nop
    
            goto L_8002FD48;
    }
    // 0x8002FD34: nop

    // 0x8002FD38: lwc1        $f16, 0x64EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X64EC);
    // 0x8002FD3C: nop

    // 0x8002FD40: mul.s       $f2, $f12, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8002FD44: nop

L_8002FD48:
    // 0x8002FD48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002FD4C: lwc1        $f12, -0x299C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X299C);
    // 0x8002FD50: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8002FD54: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8002FD58: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8002FD5C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002FD60: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002FD64: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002FD68: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002FD6C: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002FD70: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002FD74: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002FD78: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002FD7C: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002FD80: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002FD84: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002FD88: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8002FD8C: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8002FD90: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x8002FD94: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x8002FD98: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x8002FD9C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8002FDA0: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x8002FDA4: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
    // 0x8002FDA8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8002FDAC: jr          $ra
    // 0x8002FDB0: div.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    return;
    // 0x8002FDB0: div.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
;}
RECOMP_FUNC void collision_get_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BAF0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002BAF4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8002BAF8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8002BAFC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8002BB00: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8002BB04: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002BB08: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x8002BB0C: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8002BB10: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8002BB14: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8002BB18: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8002BB1C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8002BB20: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002BB24: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002BB28: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002BB2C: bltz        $a0, L_8002BB54
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002BB30: swc1        $f20, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
            goto L_8002BB54;
    }
    // 0x8002BB30: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x8002BB34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002BB38: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x8002BB3C: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8002BB40: lh          $t6, 0x1A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1A);
    // 0x8002BB44: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8002BB48: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002BB4C: bne         $at, $zero, L_8002BB5C
    if (ctx->r1 != 0) {
        // 0x8002BB50: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8002BB5C;
    }
    // 0x8002BB50: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
L_8002BB54:
    // 0x8002BB54: b           L_8002C0CC
    // 0x8002BB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002C0CC;
    // 0x8002BB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002BB5C:
    // 0x8002BB5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8002BB60: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8002BB64: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8002BB68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002BB6C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8002BB70: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x8002BB74: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002BB78: addu        $t4, $t7, $t8
    ctx->r12 = ADD32(ctx->r15, ctx->r24);
    // 0x8002BB7C: lh          $t7, 0x6($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X6);
    // 0x8002BB80: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x8002BB84: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002BB88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002BB8C: subu        $a2, $t7, $a3
    ctx->r6 = SUB32(ctx->r15, ctx->r7);
    // 0x8002BB90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002BB94: sra         $t8, $a2, 3
    ctx->r24 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002BB98: addiu       $a2, $t8, 0x1
    ctx->r6 = ADD32(ctx->r24, 0X1);
    // 0x8002BB9C: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x8002BBA0: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x8002BBA4: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BBA8: addu        $t0, $a2, $a3
    ctx->r8 = ADD32(ctx->r6, ctx->r7);
    // 0x8002BBAC: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x8002BBB0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002BBB4: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8002BBB8: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8002BBBC: mfc1        $s3, $f4
    ctx->r19 = (int32_t)ctx->f4.u32l;
    // 0x8002BBC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002BBC4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002BBC8: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BBCC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8002BBD0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8002BBD4:
    // 0x8002BBD4: slt         $at, $t0, $s3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8002BBD8: bne         $at, $zero, L_8002BBF8
    if (ctx->r1 != 0) {
        // 0x8002BBDC: addu        $t0, $t0, $a2
        ctx->r8 = ADD32(ctx->r8, ctx->r6);
            goto L_8002BBF8;
    }
    // 0x8002BBDC: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BBE0: slt         $at, $s3, $t1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002BBE4: bne         $at, $zero, L_8002BBFC
    if (ctx->r1 != 0) {
        // 0x8002BBE8: sll         $t9, $t0, 16
        ctx->r25 = S32(ctx->r8 << 16);
            goto L_8002BBFC;
    }
    // 0x8002BBE8: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8002BBEC: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002BBF0: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8002BBF4: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
L_8002BBF8:
    // 0x8002BBF8: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
L_8002BBFC:
    // 0x8002BBFC: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BC00: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8002BC04: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BC08: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002BC0C: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8002BC10: sll         $t7, $t1, 16
    ctx->r15 = S32(ctx->r9 << 16);
    // 0x8002BC14: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002BC18: sra         $t1, $t7, 16
    ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BC1C: bne         $at, $zero, L_8002BBD4
    if (ctx->r1 != 0) {
        // 0x8002BC20: sra         $a1, $t6, 16
        ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
            goto L_8002BBD4;
    }
    // 0x8002BC20: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BC24: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x8002BC28: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x8002BC2C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002BC30: subu        $a2, $t8, $v0
    ctx->r6 = SUB32(ctx->r24, ctx->r2);
    // 0x8002BC34: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002BC38: sra         $t9, $a2, 3
    ctx->r25 = S32(SIGNED(ctx->r6) >> 3);
    // 0x8002BC3C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002BC40: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002BC44: addiu       $a2, $t9, 0x1
    ctx->r6 = ADD32(ctx->r25, 0X1);
    // 0x8002BC48: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8002BC4C: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x8002BC50: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BC54: addu        $t0, $a2, $v0
    ctx->r8 = ADD32(ctx->r6, ctx->r2);
    // 0x8002BC58: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x8002BC5C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002BC60: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x8002BC64: sra         $t6, $t1, 16
    ctx->r14 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8002BC68: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x8002BC6C: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BC70: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8002BC74: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8002BC78: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8002BC7C:
    // 0x8002BC7C: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BC80: bne         $at, $zero, L_8002BCA0
    if (ctx->r1 != 0) {
        // 0x8002BC84: addu        $t0, $t0, $a2
        ctx->r8 = ADD32(ctx->r8, ctx->r6);
            goto L_8002BCA0;
    }
    // 0x8002BC84: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BC88: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002BC8C: bne         $at, $zero, L_8002BCA4
    if (ctx->r1 != 0) {
        // 0x8002BC90: sll         $t6, $t0, 16
        ctx->r14 = S32(ctx->r8 << 16);
            goto L_8002BCA4;
    }
    // 0x8002BC90: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x8002BC94: or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // 0x8002BC98: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x8002BC9C: sra         $s1, $t8, 16
    ctx->r17 = S32(SIGNED(ctx->r24) >> 16);
L_8002BCA0:
    // 0x8002BCA0: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
L_8002BCA4:
    // 0x8002BCA4: sra         $t0, $t6, 16
    ctx->r8 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BCA8: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BCAC: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8002BCB0: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8002BCB4: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BCB8: sll         $t7, $t6, 17
    ctx->r15 = S32(ctx->r14 << 17);
    // 0x8002BCBC: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BCC0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BCC4: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8002BCC8: bne         $at, $zero, L_8002BCE8
    if (ctx->r1 != 0) {
        // 0x8002BCCC: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8002BCE8;
    }
    // 0x8002BCCC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8002BCD0: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002BCD4: bne         $at, $zero, L_8002BCE8
    if (ctx->r1 != 0) {
        // 0x8002BCD8: nop
    
            goto L_8002BCE8;
    }
    // 0x8002BCD8: nop

    // 0x8002BCDC: or          $s1, $s1, $t8
    ctx->r17 = ctx->r17 | ctx->r24;
    // 0x8002BCE0: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8002BCE4: sra         $s1, $t9, 16
    ctx->r17 = S32(SIGNED(ctx->r25) >> 16);
L_8002BCE8:
    // 0x8002BCE8: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BCEC: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x8002BCF0: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BCF4: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BCF8: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8002BCFC: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x8002BD00: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x8002BD04: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BD08: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BD0C: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BD10: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8002BD14: bne         $at, $zero, L_8002BD34
    if (ctx->r1 != 0) {
        // 0x8002BD18: or          $t1, $t6, $zero
        ctx->r9 = ctx->r14 | 0;
            goto L_8002BD34;
    }
    // 0x8002BD18: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8002BD1C: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002BD20: bne         $at, $zero, L_8002BD34
    if (ctx->r1 != 0) {
        // 0x8002BD24: nop
    
            goto L_8002BD34;
    }
    // 0x8002BD24: nop

    // 0x8002BD28: or          $s1, $s1, $t9
    ctx->r17 = ctx->r17 | ctx->r25;
    // 0x8002BD2C: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x8002BD30: sra         $s1, $t6, 16
    ctx->r17 = S32(SIGNED(ctx->r14) >> 16);
L_8002BD34:
    // 0x8002BD34: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BD38: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x8002BD3C: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002BD40: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BD44: sll         $t6, $t1, 16
    ctx->r14 = S32(ctx->r9 << 16);
    // 0x8002BD48: or          $t8, $a1, $zero
    ctx->r24 = ctx->r5 | 0;
    // 0x8002BD4C: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x8002BD50: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BD54: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BD58: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002BD5C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8002BD60: bne         $at, $zero, L_8002BD80
    if (ctx->r1 != 0) {
        // 0x8002BD64: or          $t1, $t7, $zero
        ctx->r9 = ctx->r15 | 0;
            goto L_8002BD80;
    }
    // 0x8002BD64: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x8002BD68: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002BD6C: bne         $at, $zero, L_8002BD80
    if (ctx->r1 != 0) {
        // 0x8002BD70: nop
    
            goto L_8002BD80;
    }
    // 0x8002BD70: nop

    // 0x8002BD74: or          $s1, $s1, $t6
    ctx->r17 = ctx->r17 | ctx->r14;
    // 0x8002BD78: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8002BD7C: sra         $s1, $t7, 16
    ctx->r17 = S32(SIGNED(ctx->r15) >> 16);
L_8002BD80:
    // 0x8002BD80: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002BD84: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8002BD88: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8002BD8C: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
    // 0x8002BD90: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8002BD94: sll         $t7, $t1, 16
    ctx->r15 = S32(ctx->r9 << 16);
    // 0x8002BD98: sll         $t6, $t9, 17
    ctx->r14 = S32(ctx->r25 << 17);
    // 0x8002BD9C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8002BDA0: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002BDA4: bne         $t2, $v0, L_8002BC7C
    if (ctx->r10 != ctx->r2) {
        // 0x8002BDA8: sra         $t1, $t7, 16
        ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
            goto L_8002BC7C;
    }
    // 0x8002BDA8: sra         $t1, $t7, 16
    ctx->r9 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BDAC: lh          $v0, 0x20($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X20);
    // 0x8002BDB0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002BDB4: blez        $v0, L_8002BFA8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002BDB8: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8002BFA8;
    }
    // 0x8002BDB8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8002BDBC: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x8002BDC0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8002BDC4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8002BDC8: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
L_8002BDCC:
    // 0x8002BDCC: lw          $t8, 0xC($t4)
    ctx->r24 = MEM_W(ctx->r12, 0XC);
    // 0x8002BDD0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8002BDD4: addu        $a0, $t8, $s6
    ctx->r4 = ADD32(ctx->r24, ctx->r22);
    // 0x8002BDD8: lh          $v1, 0x4($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4);
    // 0x8002BDDC: lh          $t5, 0x10($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X10);
    // 0x8002BDE0: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x8002BDE4: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002BDE8: beq         $at, $zero, L_8002BF9C
    if (ctx->r1 == 0) {
        // 0x8002BDEC: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8002BF9C;
    }
    // 0x8002BDEC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8002BDF0: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
L_8002BDF4:
    // 0x8002BDF4: lw          $t9, 0x10($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X10);
    // 0x8002BDF8: nop

    // 0x8002BDFC: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8002BE00: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8002BE04: nop

    // 0x8002BE08: and         $t8, $t7, $s1
    ctx->r24 = ctx->r15 & ctx->r17;
    // 0x8002BE0C: bne         $s1, $t8, L_8002BF84
    if (ctx->r17 != ctx->r24) {
        // 0x8002BE10: nop
    
            goto L_8002BF84;
    }
    // 0x8002BE10: nop

    // 0x8002BE14: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8002BE18: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x8002BE1C: addu        $fp, $t9, $t6
    ctx->r30 = ADD32(ctx->r25, ctx->r14);
    // 0x8002BE20: lbu         $t7, 0x1($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1);
    // 0x8002BE24: lbu         $t6, 0x2($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0X2);
    // 0x8002BE28: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x8002BE2C: multu       $t8, $t3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE30: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x8002BE34: lw          $ra, 0x0($t4)
    ctx->r31 = MEM_W(ctx->r12, 0X0);
    // 0x8002BE38: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BE3C: addu        $s7, $t9, $ra
    ctx->r23 = ADD32(ctx->r25, ctx->r31);
    // 0x8002BE40: lbu         $t9, 0x3($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0X3);
    // 0x8002BE44: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE48: addu        $t6, $t9, $t1
    ctx->r14 = ADD32(ctx->r25, ctx->r9);
    // 0x8002BE4C: lh          $v0, 0x0($s7)
    ctx->r2 = MEM_H(ctx->r23, 0X0);
    // 0x8002BE50: lh          $v1, 0x4($s7)
    ctx->r3 = MEM_H(ctx->r23, 0X4);
    // 0x8002BE54: nop

    // 0x8002BE58: subu        $fp, $s0, $v1
    ctx->r30 = SUB32(ctx->r16, ctx->r3);
    // 0x8002BE5C: mflo        $t8
    ctx->r24 = lo;
    // 0x8002BE60: addu        $s7, $t8, $ra
    ctx->r23 = ADD32(ctx->r24, ctx->r31);
    // 0x8002BE64: lh          $a0, 0x0($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X0);
    // 0x8002BE68: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE6C: lh          $a1, 0x4($s7)
    ctx->r5 = MEM_H(ctx->r23, 0X4);
    // 0x8002BE70: subu        $t6, $a0, $v0
    ctx->r14 = SUB32(ctx->r4, ctx->r2);
    // 0x8002BE74: subu        $t8, $a1, $v1
    ctx->r24 = SUB32(ctx->r5, ctx->r3);
    // 0x8002BE78: mflo        $t7
    ctx->r15 = lo;
    // 0x8002BE7C: addu        $s7, $t7, $ra
    ctx->r23 = ADD32(ctx->r15, ctx->r31);
    // 0x8002BE80: lh          $a3, 0x0($s7)
    ctx->r7 = MEM_H(ctx->r23, 0X0);
    // 0x8002BE84: lh          $t0, 0x4($s7)
    ctx->r8 = MEM_H(ctx->r23, 0X4);
    // 0x8002BE88: subu        $s7, $s3, $v0
    ctx->r23 = SUB32(ctx->r19, ctx->r2);
    // 0x8002BE8C: multu       $s7, $t8
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BE90: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BE94: nop

    // 0x8002BE98: nop

    // 0x8002BE9C: multu       $t6, $fp
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BEA0: subu        $t6, $s3, $a0
    ctx->r14 = SUB32(ctx->r19, ctx->r4);
    // 0x8002BEA4: mflo        $t7
    ctx->r15 = lo;
    // 0x8002BEA8: subu        $ra, $t9, $t7
    ctx->r31 = SUB32(ctx->r25, ctx->r15);
    // 0x8002BEAC: subu        $t9, $t0, $a1
    ctx->r25 = SUB32(ctx->r8, ctx->r5);
    // 0x8002BEB0: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BEB4: slti        $t8, $ra, 0x0
    ctx->r24 = SIGNED(ctx->r31) < 0X0 ? 1 : 0;
    // 0x8002BEB8: xori        $ra, $t8, 0x1
    ctx->r31 = ctx->r24 ^ 0X1;
    // 0x8002BEBC: subu        $t6, $s0, $a1
    ctx->r14 = SUB32(ctx->r16, ctx->r5);
    // 0x8002BEC0: subu        $t8, $a3, $a0
    ctx->r24 = SUB32(ctx->r7, ctx->r4);
    // 0x8002BEC4: mflo        $t7
    ctx->r15 = lo;
    // 0x8002BEC8: nop

    // 0x8002BECC: nop

    // 0x8002BED0: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BED4: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BED8: subu        $t8, $t7, $t9
    ctx->r24 = SUB32(ctx->r15, ctx->r25);
    // 0x8002BEDC: slti        $t6, $t8, 0x0
    ctx->r14 = SIGNED(ctx->r24) < 0X0 ? 1 : 0;
    // 0x8002BEE0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x8002BEE4: bne         $t6, $ra, L_8002BF84
    if (ctx->r14 != ctx->r31) {
        // 0x8002BEE8: subu        $t7, $t0, $v1
        ctx->r15 = SUB32(ctx->r8, ctx->r3);
            goto L_8002BF84;
    }
    // 0x8002BEE8: subu        $t7, $t0, $v1
    ctx->r15 = SUB32(ctx->r8, ctx->r3);
    // 0x8002BEEC: multu       $s7, $t7
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BEF0: subu        $t8, $a3, $v0
    ctx->r24 = SUB32(ctx->r7, ctx->r2);
    // 0x8002BEF4: mflo        $t9
    ctx->r25 = lo;
    // 0x8002BEF8: nop

    // 0x8002BEFC: nop

    // 0x8002BF00: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BF04: mflo        $t6
    ctx->r14 = lo;
    // 0x8002BF08: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8002BF0C: slti        $t8, $t7, 0x0
    ctx->r24 = SIGNED(ctx->r15) < 0X0 ? 1 : 0;
    // 0x8002BF10: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x8002BF14: beq         $ra, $t8, L_8002BF84
    if (ctx->r31 == ctx->r24) {
        // 0x8002BF18: nop
    
            goto L_8002BF84;
    }
    // 0x8002BF18: nop

    // 0x8002BF1C: lw          $t9, 0x14($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X14);
    // 0x8002BF20: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x8002BF24: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002BF28: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x8002BF2C: lw          $t8, 0x18($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X18);
    // 0x8002BF30: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8002BF34: addu        $v1, $t8, $t6
    ctx->r3 = ADD32(ctx->r24, ctx->r14);
    // 0x8002BF38: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8002BF3C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002BF40: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8002BF44: c.eq.d      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.d == ctx->f8.d;
    // 0x8002BF48: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002BF4C: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002BF50: bc1t        L_8002BF84
    if (c1cs) {
        // 0x8002BF54: nop
    
            goto L_8002BF84;
    }
    // 0x8002BF54: nop

    // 0x8002BF58: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8002BF5C: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8002BF60: addu        $t9, $s4, $t7
    ctx->r25 = ADD32(ctx->r20, ctx->r15);
    // 0x8002BF64: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002BF68: mul.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8002BF6C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8002BF70: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8002BF74: nop

    // 0x8002BF78: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8002BF7C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8002BF80: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
L_8002BF84:
    // 0x8002BF84: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002BF88: slt         $at, $a2, $t5
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002BF8C: bne         $at, $zero, L_8002BDF4
    if (ctx->r1 != 0) {
        // 0x8002BF90: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_8002BDF4;
    }
    // 0x8002BF90: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x8002BF94: lh          $v0, 0x20($t4)
    ctx->r2 = MEM_H(ctx->r12, 0X20);
    // 0x8002BF98: nop

L_8002BF9C:
    // 0x8002BF9C: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002BFA0: bne         $at, $zero, L_8002BDCC
    if (ctx->r1 != 0) {
        // 0x8002BFA4: addiu       $s6, $s6, 0xC
        ctx->r22 = ADD32(ctx->r22, 0XC);
            goto L_8002BDCC;
    }
    // 0x8002BFA4: addiu       $s6, $s6, 0xC
    ctx->r22 = ADD32(ctx->r22, 0XC);
L_8002BFA8:
    // 0x8002BFA8: addiu       $a0, $s2, -0x1
    ctx->r4 = ADD32(ctx->r18, -0X1);
    // 0x8002BFAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002BFB0:
    // 0x8002BFB0: blez        $a0, L_8002C0C0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8002BFB4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002C0C0;
    }
    // 0x8002BFB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002BFB8: addiu       $a3, $s2, -0x1
    ctx->r7 = ADD32(ctx->r18, -0X1);
    // 0x8002BFBC: andi        $t8, $a3, 0x3
    ctx->r24 = ctx->r7 & 0X3;
    // 0x8002BFC0: beq         $t8, $zero, L_8002C004
    if (ctx->r24 == 0) {
        // 0x8002BFC4: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8002C004;
    }
    // 0x8002BFC4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8002BFC8: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8002BFCC: addu        $a1, $s4, $t6
    ctx->r5 = ADD32(ctx->r20, ctx->r14);
L_8002BFD0:
    // 0x8002BFD0: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8002BFD4: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002BFD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002BFDC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002BFE0: nop

    // 0x8002BFE4: bc1f        L_8002BFF8
    if (!c1cs) {
        // 0x8002BFE8: nop
    
            goto L_8002BFF8;
    }
    // 0x8002BFE8: nop

    // 0x8002BFEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002BFF0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8002BFF4: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
L_8002BFF8:
    // 0x8002BFF8: bne         $a2, $v0, L_8002BFD0
    if (ctx->r6 != ctx->r2) {
        // 0x8002BFFC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8002BFD0;
    }
    // 0x8002BFFC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8002C000: beq         $v0, $a0, L_8002C0C0
    if (ctx->r2 == ctx->r4) {
        // 0x8002C004: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8002C0C0;
    }
L_8002C004:
    // 0x8002C004: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8002C008: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8002C00C: addu        $a2, $t9, $s4
    ctx->r6 = ADD32(ctx->r25, ctx->r20);
    // 0x8002C010: addu        $a1, $s4, $t7
    ctx->r5 = ADD32(ctx->r20, ctx->r15);
L_8002C014:
    // 0x8002C014: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8002C018: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002C01C: nop

    // 0x8002C020: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002C024: nop

    // 0x8002C028: bc1f        L_8002C040
    if (!c1cs) {
        // 0x8002C02C: nop
    
            goto L_8002C040;
    }
    // 0x8002C02C: nop

    // 0x8002C030: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8002C034: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x8002C038: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8002C03C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002C040:
    // 0x8002C040: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8002C044: nop

    // 0x8002C048: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002C04C: nop

    // 0x8002C050: bc1f        L_8002C068
    if (!c1cs) {
        // 0x8002C054: nop
    
            goto L_8002C068;
    }
    // 0x8002C054: nop

    // 0x8002C058: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x8002C05C: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8002C060: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8002C064: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002C068:
    // 0x8002C068: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8002C06C: nop

    // 0x8002C070: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002C074: nop

    // 0x8002C078: bc1f        L_8002C090
    if (!c1cs) {
        // 0x8002C07C: nop
    
            goto L_8002C090;
    }
    // 0x8002C07C: nop

    // 0x8002C080: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8002C084: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x8002C088: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8002C08C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8002C090:
    // 0x8002C090: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002C094: nop

    // 0x8002C098: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002C09C: nop

    // 0x8002C0A0: bc1f        L_8002C0B4
    if (!c1cs) {
        // 0x8002C0A4: nop
    
            goto L_8002C0B4;
    }
    // 0x8002C0A4: nop

    // 0x8002C0A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002C0AC: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x8002C0B0: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
L_8002C0B4:
    // 0x8002C0B4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8002C0B8: bne         $a1, $a2, L_8002C014
    if (ctx->r5 != ctx->r6) {
        // 0x8002C0BC: nop
    
            goto L_8002C014;
    }
    // 0x8002C0BC: nop

L_8002C0C0:
    // 0x8002C0C0: beq         $v1, $zero, L_8002BFB0
    if (ctx->r3 == 0) {
        // 0x8002C0C4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002BFB0;
    }
    // 0x8002C0C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002C0C8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8002C0CC:
    // 0x8002C0CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002C0D0: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x8002C0D4: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8002C0D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002C0DC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002C0E0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8002C0E4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C0E8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8002C0EC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8002C0F0: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8002C0F4: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C0F8: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x8002C0FC: jr          $ra
    // 0x8002C100: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002C100: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void is_in_time_trial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E4DC: lbu         $v0, -0x4B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4B8B);
    // 0x8000E4E0: jr          $ra
    // 0x8000E4E4: nop

    return;
    // 0x8000E4E4: nop

;}
RECOMP_FUNC void obj_init_stopwatchman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800361D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800361D8: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x800361DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800361E0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800361E4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x800361E8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x800361EC: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x800361F0: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x800361F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800361F8: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x800361FC: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80036200: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80036204: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x80036208: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003620C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80036210: sb          $t2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r10;
    // 0x80036214: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80036218: jr          $ra
    // 0x8003621C: sw          $zero, -0x25A8($at)
    MEM_W(-0X25A8, ctx->r1) = 0;
    return;
    // 0x8003621C: sw          $zero, -0x25A8($at)
    MEM_W(-0X25A8, ctx->r1) = 0;
;}
RECOMP_FUNC void tex_load_sprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C57C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007C580: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007C584: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C588: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007C58C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007C590: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8007C594: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8007C598: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8007C59C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007C5A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007C5A4: bltz        $a0, L_8007C5C4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007C5A8: sw          $a1, 0x68FC($at)
        MEM_W(0X68FC, ctx->r1) = ctx->r5;
            goto L_8007C5C4;
    }
    // 0x8007C5A8: sw          $a1, 0x68FC($at)
    MEM_W(0X68FC, ctx->r1) = ctx->r5;
    // 0x8007C5AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C5B0: lw          $t6, 0x68F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F4);
    // 0x8007C5B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007C5B8: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007C5BC: bne         $at, $zero, L_8007C5CC
    if (ctx->r1 != 0) {
        // 0x8007C5C0: addiu       $t2, $t2, 0x68F8
        ctx->r10 = ADD32(ctx->r10, 0X68F8);
            goto L_8007C5CC;
    }
    // 0x8007C5C0: addiu       $t2, $t2, 0x68F8
    ctx->r10 = ADD32(ctx->r10, 0X68F8);
L_8007C5C4:
    // 0x8007C5C4: b           L_8007C958
    // 0x8007C5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C958;
    // 0x8007C5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C5CC:
    // 0x8007C5CC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8007C5D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007C5D4: blez        $a0, L_8007C628
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007C5D8: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8007C628;
    }
    // 0x8007C5D8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8007C5DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C5E0: lw          $v0, 0x68EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68EC);
    // 0x8007C5E4: nop

    // 0x8007C5E8: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
L_8007C5EC:
    // 0x8007C5EC: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x8007C5F0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8007C5F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C5F8: bne         $s1, $t9, L_8007C61C
    if (ctx->r17 != ctx->r25) {
        // 0x8007C5FC: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007C61C;
    }
    // 0x8007C5FC: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007C600: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8007C604: nop

    // 0x8007C608: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x8007C60C: nop

    // 0x8007C610: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8007C614: b           L_8007C958
    // 0x8007C618: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
        goto L_8007C958;
    // 0x8007C618: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
L_8007C61C:
    // 0x8007C61C: bne         $at, $zero, L_8007C5EC
    if (ctx->r1 != 0) {
        // 0x8007C620: sll         $t8, $s0, 3
        ctx->r24 = S32(ctx->r16 << 3);
            goto L_8007C5EC;
    }
    // 0x8007C620: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x8007C624: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007C628:
    // 0x8007C628: blez        $a0, L_8007C668
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007C62C: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8007C668;
    }
    // 0x8007C62C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8007C630: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C634: lw          $v0, 0x68EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68EC);
    // 0x8007C638: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007C63C: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
L_8007C640:
    // 0x8007C640: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8007C644: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007C648: nop

    // 0x8007C64C: bne         $v1, $t8, L_8007C658
    if (ctx->r3 != ctx->r24) {
        // 0x8007C650: nop
    
            goto L_8007C658;
    }
    // 0x8007C650: nop

    // 0x8007C654: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_8007C658:
    // 0x8007C658: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C65C: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007C660: bne         $at, $zero, L_8007C640
    if (ctx->r1 != 0) {
        // 0x8007C664: sll         $t6, $s0, 3
        ctx->r14 = S32(ctx->r16 << 3);
            goto L_8007C640;
    }
    // 0x8007C664: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
L_8007C668:
    // 0x8007C668: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007C66C: bne         $t0, $v1, L_8007C684
    if (ctx->r8 != ctx->r3) {
        // 0x8007C670: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8007C684;
    }
    // 0x8007C670: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007C674: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x8007C678: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007C67C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8007C680: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_8007C684:
    // 0x8007C684: lw          $t3, 0x68E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X68E8);
    // 0x8007C688: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8007C68C: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8007C690: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007C694: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8007C698: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8007C69C: lw          $s4, 0x68F0($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X68F0);
    // 0x8007C6A0: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8007C6A4: sb          $t1, 0x32($sp)
    MEM_B(0X32, ctx->r29) = ctx->r9;
    // 0x8007C6A8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8007C6AC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007C6B0: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    // 0x8007C6B4: jal         0x80077190
    // 0x8007C6B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007C6B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8007C6BC: lh          $a1, 0x2($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X2);
    // 0x8007C6C0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007C6C4: addu        $t6, $s4, $a1
    ctx->r14 = ADD32(ctx->r20, ctx->r5);
    // 0x8007C6C8: lbu         $s5, 0xC($t6)
    ctx->r21 = MEM_BU(ctx->r14, 0XC);
    // 0x8007C6CC: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8007C6D0: sll         $v1, $s5, 2
    ctx->r3 = S32(ctx->r21 << 2);
    // 0x8007C6D4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8007C6D8: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8007C6DC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8007C6E0: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8007C6E4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8007C6E8: addu        $s0, $t9, $t3
    ctx->r16 = ADD32(ctx->r25, ctx->r11);
    // 0x8007C6EC: sll         $t5, $s5, 5
    ctx->r13 = S32(ctx->r21 << 5);
    // 0x8007C6F0: addu        $s0, $s0, $t5
    ctx->r16 = ADD32(ctx->r16, ctx->r13);
    // 0x8007C6F4: jal         0x80071A90
    // 0x8007C6F8: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    align16(rdram, ctx);
        goto after_1;
    // 0x8007C6F8: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    after_1:
    // 0x8007C6FC: lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X2);
    // 0x8007C700: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8007C704: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8007C708: jal         0x80071A90
    // 0x8007C70C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    align16(rdram, ctx);
        goto after_2;
    // 0x8007C70C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
    // 0x8007C710: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007C714: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x8007C718: jal         0x80070F50
    // 0x8007C71C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc(rdram, ctx);
        goto after_3;
    // 0x8007C71C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_3:
    // 0x8007C720: bne         $v0, $zero, L_8007C750
    if (ctx->r2 != 0) {
        // 0x8007C724: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007C750;
    }
    // 0x8007C724: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8007C728: lb          $t7, 0x32($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X32);
    // 0x8007C72C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C730: beq         $t7, $zero, L_8007C748
    if (ctx->r15 == 0) {
        // 0x8007C734: addiu       $v0, $v0, 0x68F8
        ctx->r2 = ADD32(ctx->r2, 0X68F8);
            goto L_8007C748;
    }
    // 0x8007C734: addiu       $v0, $v0, 0x68F8
    ctx->r2 = ADD32(ctx->r2, 0X68F8);
    // 0x8007C738: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8007C73C: nop

    // 0x8007C740: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8007C744: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007C748:
    // 0x8007C748: b           L_8007C958
    // 0x8007C74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C958;
    // 0x8007C74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C750:
    // 0x8007C750: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007C754: jal         0x80071A90
    // 0x8007C758: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    align16(rdram, ctx);
        goto after_4;
    // 0x8007C758: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_4:
    // 0x8007C75C: lh          $a0, 0x2($s4)
    ctx->r4 = MEM_H(ctx->r20, 0X2);
    // 0x8007C760: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8007C764: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8007C768: jal         0x80071A90
    // 0x8007C76C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    align16(rdram, ctx);
        goto after_5;
    // 0x8007C76C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_5:
    // 0x8007C770: addu        $t4, $v0, $s3
    ctx->r12 = ADD32(ctx->r2, ctx->r19);
    // 0x8007C774: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8007C778: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007C77C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007C780: sll         $a0, $s5, 5
    ctx->r4 = S32(ctx->r21 << 5);
    // 0x8007C784: addiu       $a3, $a3, 0x6904
    ctx->r7 = ADD32(ctx->r7, 0X6904);
    // 0x8007C788: addiu       $a1, $a1, 0x6908
    ctx->r5 = ADD32(ctx->r5, 0X6908);
    // 0x8007C78C: addu        $t7, $t5, $a0
    ctx->r15 = ADD32(ctx->r13, ctx->r4);
    // 0x8007C790: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8007C794: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8007C798: lh          $t3, 0x2($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X2);
    // 0x8007C79C: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x8007C7A0: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x8007C7A4: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8007C7A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007C7AC: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8007C7B0: addu        $t7, $t7, $s5
    ctx->r15 = ADD32(ctx->r15, ctx->r21);
    // 0x8007C7B4: addiu       $a2, $a2, 0x6900
    ctx->r6 = ADD32(ctx->r6, 0X6900);
    // 0x8007C7B8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007C7BC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8007C7C0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8007C7C4: sw          $t8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r24;
    // 0x8007C7C8: blez        $s5, L_8007C844
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8007C7CC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007C844;
    }
    // 0x8007C7CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007C7D0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8007C7D4: addiu       $s2, $s2, -0x12C0
    ctx->r18 = ADD32(ctx->r18, -0X12C0);
    // 0x8007C7D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007C7DC:
    // 0x8007C7DC: lui         $t3, 0xFF
    ctx->r11 = S32(0XFF << 16);
    // 0x8007C7E0: ori         $t3, $t3, 0x163
    ctx->r11 = ctx->r11 | 0X163;
    // 0x8007C7E4: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8007C7E8: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x8007C7EC: sb          $v1, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r3;
    // 0x8007C7F0: jal         0x8007B2C4
    // 0x8007C7F4: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    load_texture(rdram, ctx);
        goto after_6;
    // 0x8007C7F4: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    after_6:
    // 0x8007C7F8: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x8007C7FC: lb          $v1, 0x33($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X33);
    // 0x8007C800: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8007C804: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8007C808: lw          $t6, 0x8($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X8);
    // 0x8007C80C: lui         $t3, 0xFF00
    ctx->r11 = S32(0XFF00 << 16);
    // 0x8007C810: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8007C814: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007C818: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x8007C81C: bne         $t8, $zero, L_8007C828
    if (ctx->r24 != 0) {
        // 0x8007C820: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8007C828;
    }
    // 0x8007C820: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007C824: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8007C828:
    // 0x8007C828: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C82C: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8007C830: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C834: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8007C838: bne         $s0, $s5, L_8007C7DC
    if (ctx->r16 != ctx->r21) {
        // 0x8007C83C: sw          $t9, 0x68E4($at)
        MEM_W(0X68E4, ctx->r1) = ctx->r25;
            goto L_8007C7DC;
    }
    // 0x8007C83C: sw          $t9, 0x68E4($at)
    MEM_W(0X68E4, ctx->r1) = ctx->r25;
    // 0x8007C840: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007C844:
    // 0x8007C844: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C848: beq         $v1, $zero, L_8007C8B8
    if (ctx->r3 == 0) {
        // 0x8007C84C: sw          $zero, 0x68E4($at)
        MEM_W(0X68E4, ctx->r1) = 0;
            goto L_8007C8B8;
    }
    // 0x8007C84C: sw          $zero, 0x68E4($at)
    MEM_W(0X68E4, ctx->r1) = 0;
    // 0x8007C850: blez        $s5, L_8007C888
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8007C854: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8007C888;
    }
    // 0x8007C854: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007C858:
    // 0x8007C858: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x8007C85C: nop

    // 0x8007C860: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8007C864: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8007C868: nop

    // 0x8007C86C: beq         $a0, $zero, L_8007C87C
    if (ctx->r4 == 0) {
        // 0x8007C870: nop
    
            goto L_8007C87C;
    }
    // 0x8007C870: nop

    // 0x8007C874: jal         0x8007B70C
    // 0x8007C878: nop

    tex_free(rdram, ctx);
        goto after_7;
    // 0x8007C878: nop

    after_7:
L_8007C87C:
    // 0x8007C87C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C880: bne         $s0, $s5, L_8007C858
    if (ctx->r16 != ctx->r21) {
        // 0x8007C884: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8007C858;
    }
    // 0x8007C884: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8007C888:
    // 0x8007C888: lb          $t6, 0x32($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X32);
    // 0x8007C88C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007C890: beq         $t6, $zero, L_8007C8A8
    if (ctx->r14 == 0) {
        // 0x8007C894: addiu       $v0, $v0, 0x68F8
        ctx->r2 = ADD32(ctx->r2, 0X68F8);
            goto L_8007C8A8;
    }
    // 0x8007C894: addiu       $v0, $v0, 0x68F8
    ctx->r2 = ADD32(ctx->r2, 0X68F8);
    // 0x8007C898: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8007C89C: nop

    // 0x8007C8A0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8007C8A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8007C8A8:
    // 0x8007C8A8: jal         0x80071380
    // 0x8007C8AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8007C8AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x8007C8B0: b           L_8007C958
    // 0x8007C8B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C958;
    // 0x8007C8B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C8B8:
    // 0x8007C8B8: sh          $s5, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r21;
    // 0x8007C8BC: lh          $t3, 0x2($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X2);
    // 0x8007C8C0: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x8007C8C4: sh          $t3, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r11;
    // 0x8007C8C8: lh          $t9, 0x2($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X2);
    // 0x8007C8CC: nop

    // 0x8007C8D0: blez        $t9, L_8007C908
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8007C8D4: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8007C908;
    }
L_8007C8D4:
    // 0x8007C8D4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007C8D8: addiu       $a3, $a3, 0x6904
    ctx->r7 = ADD32(ctx->r7, 0X6904);
    // 0x8007C8DC: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x8007C8E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8007C8E4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8007C8E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8007C8EC: jal         0x8007D210
    // 0x8007C8F0: sw          $t4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r12;
    sprite_init_frame(rdram, ctx);
        goto after_9;
    // 0x8007C8F0: sw          $t4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r12;
    after_9:
    // 0x8007C8F4: lh          $t5, 0x2($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X2);
    // 0x8007C8F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C8FC: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007C900: bne         $at, $zero, L_8007C8D4
    if (ctx->r1 != 0) {
        // 0x8007C904: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8007C8D4;
    }
    // 0x8007C904: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8007C908:
    // 0x8007C908: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C90C: lw          $t6, 0x68F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F8);
    // 0x8007C910: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007C914: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x8007C918: bne         $at, $zero, L_8007C928
    if (ctx->r1 != 0) {
        // 0x8007C91C: addiu       $a0, $a0, 0x68EC
        ctx->r4 = ADD32(ctx->r4, 0X68EC);
            goto L_8007C928;
    }
    // 0x8007C91C: addiu       $a0, $a0, 0x68EC
    ctx->r4 = ADD32(ctx->r4, 0X68EC);
    // 0x8007C920: b           L_8007C958
    // 0x8007C924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C958;
    // 0x8007C924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C928:
    // 0x8007C928: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8007C92C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8007C930: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8007C934: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8007C938: addu        $t4, $t9, $t8
    ctx->r12 = ADD32(ctx->r25, ctx->r24);
    // 0x8007C93C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007C940: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8007C944: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007C948: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x8007C94C: sw          $s3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r19;
    // 0x8007C950: sh          $t7, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r15;
    // 0x8007C954: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_8007C958:
    // 0x8007C958: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C95C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007C960: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007C964: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C968: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007C96C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8007C970: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8007C974: jr          $ra
    // 0x8007C978: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007C978: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void get_object_property_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023610: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80023614: sw          $a1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r5;
    // 0x80023618: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x8002361C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80023620: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80023624: sltiu       $at, $t8, 0x77
    ctx->r1 = ctx->r24 < 0X77 ? 1 : 0;
    // 0x80023628: beq         $at, $zero, L_800238DC
    if (ctx->r1 == 0) {
        // 0x8002362C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800238DC;
    }
    // 0x8002362C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80023630: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80023634: addu        $at, $at, $t8
    gpr jr_addend_80023640 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80023638: lw          $t8, 0x5C18($at)
    ctx->r24 = ADD32(ctx->r1, 0X5C18);
    // 0x8002363C: nop

    // 0x80023640: jr          $t8
    // 0x80023644: nop

    switch (jr_addend_80023640 >> 2) {
        case 0: goto L_80023648; break;
        case 1: goto L_800238DC; break;
        case 2: goto L_8002383C; break;
        case 3: goto L_80023684; break;
        case 4: goto L_80023710; break;
        case 5: goto L_800238DC; break;
        case 6: goto L_80023670; break;
        case 7: goto L_80023698; break;
        case 8: goto L_800236AC; break;
        case 9: goto L_800238DC; break;
        case 10: goto L_800238DC; break;
        case 11: goto L_800237C4; break;
        case 12: goto L_800238DC; break;
        case 13: goto L_8002365C; break;
        case 14: goto L_800238DC; break;
        case 15: goto L_800236C0; break;
        case 16: goto L_80023724; break;
        case 17: goto L_80023710; break;
        case 18: goto L_800236AC; break;
        case 19: goto L_800238DC; break;
        case 20: goto L_800238DC; break;
        case 21: goto L_800238DC; break;
        case 22: goto L_800238DC; break;
        case 23: goto L_800238DC; break;
        case 24: goto L_800238DC; break;
        case 25: goto L_800238DC; break;
        case 26: goto L_800236E8; break;
        case 27: goto L_800238DC; break;
        case 28: goto L_800236FC; break;
        case 29: goto L_800236D4; break;
        case 30: goto L_80023788; break;
        case 31: goto L_80023738; break;
        case 32: goto L_800238DC; break;
        case 33: goto L_800238DC; break;
        case 34: goto L_800238DC; break;
        case 35: goto L_800238DC; break;
        case 36: goto L_800238DC; break;
        case 37: goto L_8002374C; break;
        case 38: goto L_800238DC; break;
        case 39: goto L_80023760; break;
        case 40: goto L_800236D4; break;
        case 41: goto L_800238DC; break;
        case 42: goto L_800238DC; break;
        case 43: goto L_800238DC; break;
        case 44: goto L_80023774; break;
        case 45: goto L_800238DC; break;
        case 46: goto L_80023864; break;
        case 47: goto L_800238DC; break;
        case 48: goto L_800238DC; break;
        case 49: goto L_800237C4; break;
        case 50: goto L_800237C4; break;
        case 51: goto L_800238DC; break;
        case 52: goto L_800237C4; break;
        case 53: goto L_800237C4; break;
        case 54: goto L_800236D4; break;
        case 55: goto L_800237C4; break;
        case 56: goto L_800238DC; break;
        case 57: goto L_800238DC; break;
        case 58: goto L_800238DC; break;
        case 59: goto L_800238DC; break;
        case 60: goto L_80023814; break;
        case 61: goto L_80023788; break;
        case 62: goto L_800238DC; break;
        case 63: goto L_800238DC; break;
        case 64: goto L_800238DC; break;
        case 65: goto L_800238DC; break;
        case 66: goto L_800238DC; break;
        case 67: goto L_800238DC; break;
        case 68: goto L_800238DC; break;
        case 69: goto L_800237C4; break;
        case 70: goto L_800237D8; break;
        case 71: goto L_800237C4; break;
        case 72: goto L_800238DC; break;
        case 73: goto L_800238A0; break;
        case 74: goto L_800238DC; break;
        case 75: goto L_800238DC; break;
        case 76: goto L_80023788; break;
        case 77: goto L_800238DC; break;
        case 78: goto L_8002379C; break;
        case 79: goto L_800237C4; break;
        case 80: goto L_800237C4; break;
        case 81: goto L_800238DC; break;
        case 82: goto L_800237B0; break;
        case 83: goto L_800237C4; break;
        case 84: goto L_800237C4; break;
        case 85: goto L_800237C4; break;
        case 86: goto L_800238DC; break;
        case 87: goto L_800238DC; break;
        case 88: goto L_800238DC; break;
        case 89: goto L_800238DC; break;
        case 90: goto L_800238DC; break;
        case 91: goto L_800238DC; break;
        case 92: goto L_800238DC; break;
        case 93: goto L_8002388C; break;
        case 94: goto L_800238DC; break;
        case 95: goto L_800237C4; break;
        case 96: goto L_800237C4; break;
        case 97: goto L_800238DC; break;
        case 98: goto L_800238DC; break;
        case 99: goto L_800238DC; break;
        case 100: goto L_800237C4; break;
        case 101: goto L_800237C4; break;
        case 102: goto L_800237C4; break;
        case 103: goto L_800237C4; break;
        case 104: goto L_800238DC; break;
        case 105: goto L_800238DC; break;
        case 106: goto L_800238DC; break;
        case 107: goto L_800238DC; break;
        case 108: goto L_800238B4; break;
        case 109: goto L_800238DC; break;
        case 110: goto L_8002365C; break;
        case 111: goto L_800237EC; break;
        case 112: goto L_800237C4; break;
        case 113: goto L_800238DC; break;
        case 114: goto L_800237C4; break;
        case 115: goto L_800238C8; break;
        case 116: goto L_800238DC; break;
        case 117: goto L_80023800; break;
        case 118: goto L_800237C4; break;
        default: switch_error(__func__, 0x80023640, 0x800E5C18);
    }
    // 0x80023644: nop

L_80023648:
    // 0x80023648: addiu       $v1, $zero, 0x224
    ctx->r3 = ADD32(0, 0X224);
    // 0x8002364C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023650: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023654: jr          $ra
    // 0x80023658: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023658: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002365C:
    // 0x8002365C: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x80023660: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023664: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023668: jr          $ra
    // 0x8002366C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002366C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023670:
    // 0x80023670: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x80023674: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023678: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002367C: jr          $ra
    // 0x80023680: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023680: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023684:
    // 0x80023684: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80023688: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002368C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023690: jr          $ra
    // 0x80023694: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023694: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023698:
    // 0x80023698: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8002369C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236A0: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236A4: jr          $ra
    // 0x800236A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236AC:
    // 0x800236AC: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x800236B0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236B4: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236B8: jr          $ra
    // 0x800236BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236C0:
    // 0x800236C0: addiu       $v1, $zero, 0x1C
    ctx->r3 = ADD32(0, 0X1C);
    // 0x800236C4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236C8: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236CC: jr          $ra
    // 0x800236D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236D4:
    // 0x800236D4: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800236D8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236DC: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236E0: jr          $ra
    // 0x800236E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236E8:
    // 0x800236E8: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x800236EC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800236F0: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800236F4: jr          $ra
    // 0x800236F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800236F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800236FC:
    // 0x800236FC: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80023700: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023704: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023708: jr          $ra
    // 0x8002370C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002370C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023710:
    // 0x80023710: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x80023714: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023718: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002371C: jr          $ra
    // 0x80023720: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023720: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023724:
    // 0x80023724: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80023728: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002372C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023730: jr          $ra
    // 0x80023734: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023734: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023738:
    // 0x80023738: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8002373C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023740: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023744: jr          $ra
    // 0x80023748: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023748: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002374C:
    // 0x8002374C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80023750: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023754: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023758: jr          $ra
    // 0x8002375C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002375C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023760:
    // 0x80023760: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x80023764: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023768: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002376C: jr          $ra
    // 0x80023770: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023770: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023774:
    // 0x80023774: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80023778: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002377C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023780: jr          $ra
    // 0x80023784: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023784: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023788:
    // 0x80023788: addiu       $v1, $zero, 0x38
    ctx->r3 = ADD32(0, 0X38);
    // 0x8002378C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023790: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023794: jr          $ra
    // 0x80023798: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023798: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002379C:
    // 0x8002379C: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x800237A0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237A4: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237A8: jr          $ra
    // 0x800237AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237B0:
    // 0x800237B0: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800237B4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237B8: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237BC: jr          $ra
    // 0x800237C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237C4:
    // 0x800237C4: addiu       $v1, $zero, 0x48
    ctx->r3 = ADD32(0, 0X48);
    // 0x800237C8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237CC: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237D0: jr          $ra
    // 0x800237D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237D8:
    // 0x800237D8: addiu       $v1, $zero, 0x44
    ctx->r3 = ADD32(0, 0X44);
    // 0x800237DC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237E0: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237E4: jr          $ra
    // 0x800237E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800237EC:
    // 0x800237EC: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x800237F0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800237F4: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800237F8: jr          $ra
    // 0x800237FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800237FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023800:
    // 0x80023800: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80023804: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023808: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x8002380C: jr          $ra
    // 0x80023810: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023810: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023814:
    // 0x80023814: andi        $t9, $a1, 0xF
    ctx->r25 = ctx->r5 & 0XF;
    // 0x80023818: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8002381C: subu        $v0, $t0, $t9
    ctx->r2 = SUB32(ctx->r8, ctx->r25);
    // 0x80023820: addu        $t1, $a1, $v0
    ctx->r9 = ADD32(ctx->r5, ctx->r2);
    // 0x80023824: addiu       $v1, $v0, 0x110
    ctx->r3 = ADD32(ctx->r2, 0X110);
    // 0x80023828: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002382C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023830: sw          $t1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r9;
    // 0x80023834: jr          $ra
    // 0x80023838: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023838: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002383C:
    // 0x8002383C: andi        $t2, $a1, 0xF
    ctx->r10 = ctx->r5 & 0XF;
    // 0x80023840: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80023844: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
    // 0x80023848: addu        $t4, $a1, $v0
    ctx->r12 = ADD32(ctx->r5, ctx->r2);
    // 0x8002384C: addiu       $v1, $v0, 0x120
    ctx->r3 = ADD32(ctx->r2, 0X120);
    // 0x80023850: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023854: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023858: sw          $t4, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r12;
    // 0x8002385C: jr          $ra
    // 0x80023860: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023860: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80023864:
    // 0x80023864: andi        $t5, $a1, 0xF
    ctx->r13 = ctx->r5 & 0XF;
    // 0x80023868: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8002386C: subu        $v0, $t6, $t5
    ctx->r2 = SUB32(ctx->r14, ctx->r13);
    // 0x80023870: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x80023874: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x80023878: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002387C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023880: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
    // 0x80023884: jr          $ra
    // 0x80023888: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x80023888: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002388C:
    // 0x8002388C: addiu       $v1, $zero, 0x60
    ctx->r3 = ADD32(0, 0X60);
    // 0x80023890: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80023894: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x80023898: jr          $ra
    // 0x8002389C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8002389C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800238A0:
    // 0x800238A0: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x800238A4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800238A8: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800238AC: jr          $ra
    // 0x800238B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800238B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800238B4:
    // 0x800238B4: addiu       $v1, $zero, 0x34
    ctx->r3 = ADD32(0, 0X34);
    // 0x800238B8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800238BC: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800238C0: jr          $ra
    // 0x800238C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800238C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800238C8:
    // 0x800238C8: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x800238CC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800238D0: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800238D4: jr          $ra
    // 0x800238D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800238D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800238DC:
    // 0x800238DC: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x800238E0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800238E4: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800238E8: jr          $ra
    // 0x800238EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800238EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
;}
RECOMP_FUNC void mempool_locked_unset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071778: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007177C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071780: jal         0x8006F750
    // 0x80071784: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80071784: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80071788: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8007178C: jal         0x8007182C
    // 0x80071790: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    mempool_get_pool(rdram, ctx);
        goto after_1;
    // 0x80071790: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80071794: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80071798: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007179C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800717A0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800717A4: lw          $a0, 0x3B08($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3B08);
    // 0x800717A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800717AC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800717B0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_800717B4:
    // 0x800717B4: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800717B8: mflo        $t7
    ctx->r15 = lo;
    // 0x800717BC: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800717C0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800717C4: nop

    // 0x800717C8: bne         $a3, $t8, L_800717FC
    if (ctx->r7 != ctx->r24) {
        // 0x800717CC: nop
    
            goto L_800717FC;
    }
    // 0x800717CC: nop

    // 0x800717D0: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x800717D4: nop

    // 0x800717D8: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x800717DC: beq         $t9, $zero, L_800717FC
    if (ctx->r25 == 0) {
        // 0x800717E0: xori        $t0, $v1, 0x2
        ctx->r8 = ctx->r3 ^ 0X2;
            goto L_800717FC;
    }
    // 0x800717E0: xori        $t0, $v1, 0x2
    ctx->r8 = ctx->r3 ^ 0X2;
    // 0x800717E4: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
    // 0x800717E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800717EC: jal         0x8006F77C
    // 0x800717F0: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x800717F0: nop

    after_2:
    // 0x800717F4: b           L_8007181C
    // 0x800717F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007181C;
    // 0x800717F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800717FC:
    // 0x800717FC: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    // 0x80071800: nop

    // 0x80071804: bne         $v1, $a2, L_800717B4
    if (ctx->r3 != ctx->r6) {
        // 0x80071808: nop
    
            goto L_800717B4;
    }
    // 0x80071808: nop

    // 0x8007180C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80071810: jal         0x8006F77C
    // 0x80071814: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80071814: nop

    after_3:
    // 0x80071818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007181C:
    // 0x8007181C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80071824: jr          $ra
    // 0x80071828: nop

    return;
    // 0x80071828: nop

;}
RECOMP_FUNC void audspat_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008438: addiu       $sp, $sp, -0x268
    ctx->r29 = ADD32(ctx->r29, -0X268);
    // 0x8000843C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80008440: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80008444: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80008448: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8000844C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80008450: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80008454: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80008458: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8000845C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80008460: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80008464: swc1        $f27, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80008468: swc1        $f26, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f26.u32l;
    // 0x8000846C: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80008470: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80008474: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80008478: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x8000847C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80008480: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80008484: sw          $a0, 0x268($sp)
    MEM_W(0X268, ctx->r29) = ctx->r4;
    // 0x80008488: sw          $a1, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r5;
    // 0x8000848C: sw          $a2, 0x270($sp)
    MEM_W(0X270, ctx->r29) = ctx->r6;
    // 0x80008490: jal         0x80066450
    // 0x80008494: sw          $zero, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = 0;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x80008494: sw          $zero, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = 0;
    after_0:
    // 0x80008498: jal         0x8006676C
    // 0x8000849C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    cam_set_layout(rdram, ctx);
        goto after_1;
    // 0x8000849C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800084A0: jal         0x80069FBC
    // 0x800084A4: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    cam_get_cameras(rdram, ctx);
        goto after_2;
    // 0x800084A4: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    after_2:
    // 0x800084A8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800084AC: addiu       $s5, $s5, -0x33B0
    ctx->r21 = ADD32(ctx->r21, -0X33B0);
    // 0x800084B0: lhu         $t6, 0x0($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0X0);
    // 0x800084B4: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x800084B8: blez        $t6, L_80008AD8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800084BC: sw          $zero, 0x260($sp)
        MEM_W(0X260, ctx->r29) = 0;
            goto L_80008AD8;
    }
    // 0x800084BC: sw          $zero, 0x260($sp)
    MEM_W(0X260, ctx->r29) = 0;
    // 0x800084C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800084C4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800084C8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800084CC: addiu       $s6, $s6, -0x5E3C
    ctx->r22 = ADD32(ctx->r22, -0X5E3C);
    // 0x800084D0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800084D4: addiu       $s7, $sp, 0xA8
    ctx->r23 = ADD32(ctx->r29, 0XA8);
    // 0x800084D8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800084DC:
    // 0x800084DC: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800084E0: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x800084E4: addu        $t8, $t7, $s4
    ctx->r24 = ADD32(ctx->r15, ctx->r20);
    // 0x800084E8: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x800084EC: sw          $zero, 0x254($sp)
    MEM_W(0X254, ctx->r29) = 0;
    // 0x800084F0: lbu         $t9, 0x11($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X11);
    // 0x800084F4: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x800084F8: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x800084FC: beq         $t0, $zero, L_800086BC
    if (ctx->r8 == 0) {
        // 0x80008500: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800086BC;
    }
    // 0x80008500: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008504: bne         $t1, $at, L_80008ABC
    if (ctx->r9 != ctx->r1) {
        // 0x80008508: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008508: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x8000850C: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80008510: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80008514: lwc1        $f6, 0xC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80008518: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8000851C: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80008520: lwc1        $f10, 0x10($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80008524: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80008528: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000852C: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80008530: lwc1        $f18, 0x14($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80008534: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80008538: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8000853C: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80008540: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80008544: jal         0x800CA030
    // 0x80008548: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80008548: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_3:
    // 0x8000854C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80008550: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80008554: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80008558: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000855C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008560: nop

    // 0x80008564: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80008568: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8000856C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80008570: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80008574: beq         $at, $zero, L_8000869C
    if (ctx->r1 == 0) {
        // 0x80008578: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8000869C;
    }
    // 0x80008578: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000857C: lbu         $t4, 0x12($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X12);
    // 0x80008580: nop

    // 0x80008584: bne         $t4, $zero, L_8000869C
    if (ctx->r12 != 0) {
        // 0x80008588: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8000869C;
    }
    // 0x80008588: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000858C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008590: nop

    // 0x80008594: bne         $a0, $zero, L_800085D4
    if (ctx->r4 != 0) {
        // 0x80008598: nop
    
            goto L_800085D4;
    }
    // 0x80008598: nop

    // 0x8000859C: lbu         $t5, 0x22($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X22);
    // 0x800085A0: nop

    // 0x800085A4: beq         $t5, $zero, L_800085C0
    if (ctx->r13 == 0) {
        // 0x800085A8: nop
    
            goto L_800085C0;
    }
    // 0x800085A8: nop

    // 0x800085AC: lbu         $t6, 0x11($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X11);
    // 0x800085B0: nop

    // 0x800085B4: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800085B8: bne         $t7, $zero, L_800085D4
    if (ctx->r15 != 0) {
        // 0x800085BC: nop
    
            goto L_800085D4;
    }
    // 0x800085BC: nop

L_800085C0:
    // 0x800085C0: lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XC);
    // 0x800085C4: jal         0x80001F14
    // 0x800085C8: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    sound_play_direct(rdram, ctx);
        goto after_4;
    // 0x800085C8: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    after_4:
    // 0x800085CC: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800085D0: sb          $s2, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r18;
L_800085D4:
    // 0x800085D4: beq         $a0, $zero, L_80008690
    if (ctx->r4 == 0) {
        // 0x800085D8: nop
    
            goto L_80008690;
    }
    // 0x800085D8: nop

    // 0x800085DC: lbu         $t8, 0xF($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0XF);
    // 0x800085E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800085E4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800085E8: bgez        $t8, L_800085FC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800085EC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800085FC;
    }
    // 0x800085EC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800085F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800085F4: nop

    // 0x800085F8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800085FC:
    // 0x800085FC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80008600: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80008604: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80008608: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000860C: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x80008610: lbu         $a2, 0xE($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0XE);
    // 0x80008614: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008618: sll         $t9, $a2, 8
    ctx->r25 = S32(ctx->r6 << 8);
    // 0x8000861C: jal         0x800049F8
    // 0x80008620: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80008620: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_5:
    // 0x80008624: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008628: lw          $a2, 0x0($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X0);
    // 0x8000862C: jal         0x800049F8
    // 0x80008630: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_6;
    // 0x80008630: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_6:
    // 0x80008634: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x80008638: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8000863C: lh          $a2, 0x0($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X0);
    // 0x80008640: jal         0x800090C0
    // 0x80008644: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_7;
    // 0x80008644: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_7:
    // 0x80008648: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8000864C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008650: beq         $t1, $at, L_8000865C
    if (ctx->r9 == ctx->r1) {
        // 0x80008654: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000865C;
    }
    // 0x80008654: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80008658: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
L_8000865C:
    // 0x8000865C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008660: jal         0x800049F8
    // 0x80008664: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_8;
    // 0x80008664: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80008668: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x8000866C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80008670: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80008674: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80008678: jal         0x80009B7C
    // 0x8000867C: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_9;
    // 0x8000867C: nop

    after_9:
    // 0x80008680: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008684: lbu         $a1, 0x21($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X21);
    // 0x80008688: jal         0x80004604
    // 0x8000868C: nop

    sndp_set_priority(rdram, ctx);
        goto after_10;
    // 0x8000868C: nop

    after_10:
L_80008690:
    // 0x80008690: b           L_80008AB8
    // 0x80008694: sb          $s2, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r18;
        goto L_80008AB8;
    // 0x80008694: sb          $s2, 0x12($s1)
    MEM_B(0X12, ctx->r17) = ctx->r18;
    // 0x80008698: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
L_8000869C:
    // 0x8000869C: beq         $at, $zero, L_80008ABC
    if (ctx->r1 == 0) {
        // 0x800086A0: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x800086A0: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x800086A4: lbu         $t2, 0x12($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X12);
    // 0x800086A8: nop

    // 0x800086AC: beq         $t2, $zero, L_80008ABC
    if (ctx->r10 == 0) {
        // 0x800086B0: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x800086B0: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x800086B4: b           L_80008AB8
    // 0x800086B8: sb          $zero, 0x12($s1)
    MEM_B(0X12, ctx->r17) = 0;
        goto L_80008AB8;
    // 0x800086B8: sb          $zero, 0x12($s1)
    MEM_B(0X12, ctx->r17) = 0;
L_800086BC:
    // 0x800086BC: blez        $t3, L_8000884C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800086C0: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_8000884C;
    }
    // 0x800086C0: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800086C4: lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XAC);
    // 0x800086C8: nop

L_800086CC:
    // 0x800086CC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800086D0: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800086D4: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800086D8: sub.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800086DC: lwc1        $f4, 0x10($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800086E0: mul.s       $f16, $f20, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800086E4: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800086E8: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800086EC: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800086F0: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800086F4: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800086F8: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800086FC: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80008700: jal         0x800CA030
    // 0x80008704: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x80008704: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_11:
    // 0x80008708: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8000870C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80008710: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80008714: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008718: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000871C: lw          $t1, 0x254($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X254);
    // 0x80008720: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80008724: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80008728: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8000872C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80008730: beq         $at, $zero, L_80008840
    if (ctx->r1 == 0) {
        // 0x80008734: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_80008840;
    }
    // 0x80008734: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80008738: lbu         $t5, 0x20($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X20);
    // 0x8000873C: subu        $t8, $a0, $v1
    ctx->r24 = SUB32(ctx->r4, ctx->r3);
    // 0x80008740: bne         $t5, $zero, L_800087B0
    if (ctx->r13 != 0) {
        // 0x80008744: nop
    
            goto L_800087B0;
    }
    // 0x80008744: nop

    // 0x80008748: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8000874C: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80008750: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80008754: lbu         $t6, 0xE($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XE);
    // 0x80008758: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000875C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80008760: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80008764: div.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80008768: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000876C: bgez        $t6, L_80008780
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80008770: sub.s       $f8, $f26, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f4.fl;
            goto L_80008780;
    }
    // 0x80008770: sub.s       $f8, $f26, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x80008774: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80008778: nop

    // 0x8000877C: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_80008780:
    // 0x80008780: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80008784: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80008788: nop

    // 0x8000878C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80008790: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008794: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008798: nop

    // 0x8000879C: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800087A0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800087A4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800087A8: b           L_8000881C
    // 0x800087AC: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_8000881C;
    // 0x800087AC: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
L_800087B0:
    // 0x800087B0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800087B4: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800087B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800087BC: lbu         $t9, 0xE($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XE);
    // 0x800087C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800087C4: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800087C8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800087CC: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800087D0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800087D4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800087D8: bgez        $t9, L_800087EC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800087DC: nop
    
            goto L_800087EC;
    }
    // 0x800087DC: nop

    // 0x800087E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800087E4: nop

    // 0x800087E8: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_800087EC:
    // 0x800087EC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800087F0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800087F4: nop

    // 0x800087F8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800087FC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008800: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008804: nop

    // 0x80008808: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000880C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80008810: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80008814: nop

    // 0x80008818: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
L_8000881C:
    // 0x8000881C: beq         $at, $zero, L_80008840
    if (ctx->r1 == 0) {
        // 0x80008820: lw          $t2, 0xB0($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XB0);
            goto L_80008840;
    }
    // 0x80008820: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x80008824: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // 0x80008828: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    // 0x8000882C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80008830: jal         0x800090C0
    // 0x80008834: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_12;
    // 0x80008834: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_12:
    // 0x80008838: sw          $v0, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r2;
    // 0x8000883C: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
L_80008840:
    // 0x80008840: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80008844: bne         $fp, $t2, L_800086CC
    if (ctx->r30 != ctx->r10) {
        // 0x80008848: addiu       $s3, $s3, 0x44
        ctx->r19 = ADD32(ctx->r19, 0X44);
            goto L_800086CC;
    }
    // 0x80008848: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
L_8000884C:
    // 0x8000884C: lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X10);
    // 0x80008850: lw          $t3, 0x254($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X254);
    // 0x80008854: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008858: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000885C: beq         $at, $zero, L_8000892C
    if (ctx->r1 == 0) {
        // 0x80008860: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000892C;
    }
    // 0x80008860: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80008864: lwc1        $f24, 0x54A4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X54A4);
    // 0x80008868: blez        $t4, L_80008928
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000886C: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80008928;
    }
    // 0x8000886C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80008870: lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XAC);
    // 0x80008874: nop

L_80008878:
    // 0x80008878: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8000887C: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80008880: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80008884: sub.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80008888: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8000888C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80008890: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80008894: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80008898: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8000889C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800088A0: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800088A4: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800088A8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800088AC: jal         0x800CA030
    // 0x800088B0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_13;
    // 0x800088B0: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_13:
    // 0x800088B4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800088B8: nop

    // 0x800088BC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800088C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800088C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800088C8: nop

    // 0x800088CC: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800088D0: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
    // 0x800088D4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800088D8: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x800088DC: nop

    // 0x800088E0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800088E4: c.lt.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl < ctx->f24.fl;
    // 0x800088E8: nop

    // 0x800088EC: bc1f        L_80008914
    if (!c1cs) {
        // 0x800088F0: lw          $t6, 0xB0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XB0);
            goto L_80008914;
    }
    // 0x800088F0: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800088F4: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    // 0x800088F8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800088FC: jal         0x800090C0
    // 0x80008900: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_14;
    // 0x80008900: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_14:
    // 0x80008904: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80008908: sw          $v0, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r2;
    // 0x8000890C: cvt.s.w     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80008910: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
L_80008914:
    // 0x80008914: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80008918: bne         $fp, $t6, L_80008878
    if (ctx->r30 != ctx->r14) {
        // 0x8000891C: addiu       $s3, $s3, 0x44
        ctx->r19 = ADD32(ctx->r19, 0X44);
            goto L_80008878;
    }
    // 0x8000891C: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
    // 0x80008920: lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X10);
    // 0x80008924: nop

L_80008928:
    // 0x80008928: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
L_8000892C:
    // 0x8000892C: lw          $t7, 0x254($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X254);
    // 0x80008930: nop

    // 0x80008934: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x80008938: bne         $at, $zero, L_80008A4C
    if (ctx->r1 != 0) {
        // 0x8000893C: nop
    
            goto L_80008A4C;
    }
    // 0x8000893C: nop

    // 0x80008940: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008944: nop

    // 0x80008948: bne         $a0, $zero, L_80008988
    if (ctx->r4 != 0) {
        // 0x8000894C: nop
    
            goto L_80008988;
    }
    // 0x8000894C: nop

    // 0x80008950: lbu         $t8, 0x22($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X22);
    // 0x80008954: nop

    // 0x80008958: beq         $t8, $zero, L_80008974
    if (ctx->r24 == 0) {
        // 0x8000895C: nop
    
            goto L_80008974;
    }
    // 0x8000895C: nop

    // 0x80008960: lbu         $t9, 0x11($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X11);
    // 0x80008964: nop

    // 0x80008968: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8000896C: bne         $t0, $zero, L_80008988
    if (ctx->r8 != 0) {
        // 0x80008970: nop
    
            goto L_80008988;
    }
    // 0x80008970: nop

L_80008974:
    // 0x80008974: lhu         $a0, 0xC($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0XC);
    // 0x80008978: jal         0x80001F14
    // 0x8000897C: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    sound_play_direct(rdram, ctx);
        goto after_15;
    // 0x8000897C: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    after_15:
    // 0x80008980: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008984: sb          $s2, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r18;
L_80008988:
    // 0x80008988: beq         $a0, $zero, L_80008A38
    if (ctx->r4 == 0) {
        // 0x8000898C: nop
    
            goto L_80008A38;
    }
    // 0x8000898C: nop

    // 0x80008990: lbu         $t1, 0xF($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XF);
    // 0x80008994: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80008998: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8000899C: bgez        $t1, L_800089B0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800089A0: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800089B0;
    }
    // 0x800089A0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800089A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800089A8: nop

    // 0x800089AC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800089B0:
    // 0x800089B0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800089B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800089B8: lw          $a2, 0x254($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X254);
    // 0x800089BC: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800089C0: sll         $t2, $a2, 8
    ctx->r10 = S32(ctx->r6 << 8);
    // 0x800089C4: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800089C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800089CC: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x800089D0: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800089D4: jal         0x800049F8
    // 0x800089D8: nop

    sndp_set_param(rdram, ctx);
        goto after_16;
    // 0x800089D8: nop

    after_16:
    // 0x800089DC: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800089E0: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x800089E4: jal         0x800049F8
    // 0x800089E8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_17;
    // 0x800089E8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_17:
    // 0x800089EC: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x800089F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800089F4: beq         $t3, $at, L_80008A00
    if (ctx->r11 == ctx->r1) {
        // 0x800089F8: addiu       $t4, $zero, 0x40
        ctx->r12 = ADD32(0, 0X40);
            goto L_80008A00;
    }
    // 0x800089F8: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800089FC: sw          $t4, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r12;
L_80008A00:
    // 0x80008A00: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A04: lw          $a2, 0x250($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X250);
    // 0x80008A08: jal         0x800049F8
    // 0x80008A0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_18;
    // 0x80008A0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_18:
    // 0x80008A10: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A14: lbu         $a1, 0x21($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X21);
    // 0x80008A18: jal         0x80004604
    // 0x80008A1C: nop

    sndp_set_priority(rdram, ctx);
        goto after_19;
    // 0x80008A1C: nop

    after_19:
    // 0x80008A20: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A24: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80008A28: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80008A2C: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80008A30: jal         0x80009B7C
    // 0x80008A34: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_20;
    // 0x80008A34: nop

    after_20:
L_80008A38:
    // 0x80008A38: lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11);
    // 0x80008A3C: nop

    // 0x80008A40: andi        $t5, $v0, 0x4
    ctx->r13 = ctx->r2 & 0X4;
    // 0x80008A44: b           L_80008A88
    // 0x80008A48: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80008A88;
    // 0x80008A48: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80008A4C:
    // 0x80008A4C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x80008A50: nop

    // 0x80008A54: beq         $a0, $zero, L_80008A78
    if (ctx->r4 == 0) {
        // 0x80008A58: nop
    
            goto L_80008A78;
    }
    // 0x80008A58: nop

    // 0x80008A5C: jal         0x8000488C
    // 0x80008A60: nop

    sndp_stop(rdram, ctx);
        goto after_21;
    // 0x80008A60: nop

    after_21:
    // 0x80008A64: lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11);
    // 0x80008A68: nop

    // 0x80008A6C: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x80008A70: b           L_80008A88
    // 0x80008A74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80008A88;
    // 0x80008A74: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80008A78:
    // 0x80008A78: lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11);
    // 0x80008A7C: sb          $s2, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r18;
    // 0x80008A80: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x80008A84: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80008A88:
    // 0x80008A88: beq         $v0, $zero, L_80008ABC
    if (ctx->r2 == 0) {
        // 0x80008A8C: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008A8C: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x80008A90: lbu         $t8, 0x22($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X22);
    // 0x80008A94: nop

    // 0x80008A98: beq         $t8, $zero, L_80008ABC
    if (ctx->r24 == 0) {
        // 0x80008A9C: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008A9C: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x80008AA0: lw          $t9, 0x18($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X18);
    // 0x80008AA4: lw          $a0, 0x260($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X260);
    // 0x80008AA8: bne         $t9, $zero, L_80008ABC
    if (ctx->r25 != 0) {
        // 0x80008AAC: lw          $t0, 0x260($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X260);
            goto L_80008ABC;
    }
    // 0x80008AAC: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
    // 0x80008AB0: jal         0x8000A2E8
    // 0x80008AB4: nop

    audspat_point_stop_by_index(rdram, ctx);
        goto after_22;
    // 0x80008AB4: nop

    after_22:
L_80008AB8:
    // 0x80008AB8: lw          $t0, 0x260($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X260);
L_80008ABC:
    // 0x80008ABC: lhu         $t2, 0x0($s5)
    ctx->r10 = MEM_HU(ctx->r21, 0X0);
    // 0x80008AC0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80008AC4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80008AC8: sw          $t1, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r9;
    // 0x80008ACC: bne         $at, $zero, L_800084DC
    if (ctx->r1 != 0) {
        // 0x80008AD0: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_800084DC;
    }
    // 0x80008AD0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80008AD4: sw          $zero, 0x260($sp)
    MEM_W(0X260, ctx->r29) = 0;
L_80008AD8:
    // 0x80008AD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80008ADC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80008AE0: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80008AE4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80008AE8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80008AEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80008AF0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80008AF4: addiu       $v0, $v0, -0x5E28
    ctx->r2 = ADD32(ctx->r2, -0X5E28);
L_80008AF8:
    // 0x80008AF8: lw          $t3, 0x16C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X16C);
    // 0x80008AFC: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80008B00: beq         $t3, $zero, L_80008FC4
    if (ctx->r11 == 0) {
        // 0x80008B04: sw          $v0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r2;
            goto L_80008FC4;
    }
    // 0x80008B04: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x80008B08: lbu         $a0, 0x263($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X263);
    // 0x80008B0C: jal         0x800099EC
    // 0x80008B10: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    audspat_line_validate(rdram, ctx);
        goto after_23;
    // 0x80008B10: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    after_23:
    // 0x80008B14: beq         $v0, $zero, L_80008FC8
    if (ctx->r2 == 0) {
        // 0x80008B18: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008B18: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008B1C: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008B20: sw          $zero, 0x254($sp)
    MEM_W(0X254, ctx->r29) = 0;
    // 0x80008B24: blez        $t4, L_80008E44
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80008B28: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_80008E44;
    }
    // 0x80008B28: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80008B2C: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80008B30: nop

    // 0x80008B34: addiu       $t5, $v0, 0x4
    ctx->r13 = ADD32(ctx->r2, 0X4);
    // 0x80008B38: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
    // 0x80008B3C: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
L_80008B40:
    // 0x80008B40: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x80008B44: lw          $v1, 0x170($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X170);
    // 0x80008B48: lb          $t6, 0x17C($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X17C);
    // 0x80008B4C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80008B50: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80008B54: blez        $t6, L_80008C0C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80008B58: or          $s6, $v1, $zero
        ctx->r22 = ctx->r3 | 0;
            goto L_80008C0C;
    }
    // 0x80008B58: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x80008B5C: sll         $t8, $fp, 4
    ctx->r24 = S32(ctx->r30 << 4);
    // 0x80008B60: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80008B64: addu        $t8, $t8, $fp
    ctx->r24 = ADD32(ctx->r24, ctx->r30);
    // 0x80008B68: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80008B6C: addiu       $s0, $sp, 0x1A8
    ctx->r16 = ADD32(ctx->r29, 0X1A8);
    // 0x80008B70: addiu       $s1, $sp, 0x12C
    ctx->r17 = ADD32(ctx->r29, 0X12C);
    // 0x80008B74: addu        $s3, $t7, $t8
    ctx->r19 = ADD32(ctx->r15, ctx->r24);
L_80008B78:
    // 0x80008B78: lwc1        $f12, 0xC($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80008B7C: lwc1        $f14, 0x10($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X10);
    // 0x80008B80: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80008B84: addiu       $t9, $sp, 0x22C
    ctx->r25 = ADD32(ctx->r29, 0X22C);
    // 0x80008B88: addiu       $t0, $sp, 0x228
    ctx->r8 = ADD32(ctx->r29, 0X228);
    // 0x80008B8C: addiu       $t1, $sp, 0x224
    ctx->r9 = ADD32(ctx->r29, 0X224);
    // 0x80008B90: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80008B94: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80008B98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80008B9C: jal         0x800092A8
    // 0x80008BA0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    audspat_distance_to_segment(rdram, ctx);
        goto after_24;
    // 0x80008BA0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_24:
    // 0x80008BA4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80008BA8: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80008BAC: lwc1        $f16, 0x224($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X224);
    // 0x80008BB0: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80008BB4: lwc1        $f8, 0x22C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X22C);
    // 0x80008BB8: lh          $a2, 0x0($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X0);
    // 0x80008BBC: sub.s       $f14, $f16, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80008BC0: jal         0x800090C0
    // 0x80008BC4: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_25;
    // 0x80008BC4: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    after_25:
    // 0x80008BC8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80008BCC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80008BD0: slt         $at, $v1, $s6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80008BD4: beq         $at, $zero, L_80008BE0
    if (ctx->r1 == 0) {
        // 0x80008BD8: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_80008BE0;
    }
    // 0x80008BD8: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80008BDC: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
L_80008BE0:
    // 0x80008BE0: lb          $t2, 0x17C($s7)
    ctx->r10 = MEM_B(ctx->r23, 0X17C);
    // 0x80008BE4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80008BE8: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80008BEC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80008BF0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80008BF4: bne         $at, $zero, L_80008B78
    if (ctx->r1 != 0) {
        // 0x80008BF8: addu        $s5, $s5, $v1
        ctx->r21 = ADD32(ctx->r21, ctx->r3);
            goto L_80008B78;
    }
    // 0x80008BF8: addu        $s5, $s5, $v1
    ctx->r21 = ADD32(ctx->r21, ctx->r3);
    // 0x80008BFC: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80008C00: nop

    // 0x80008C04: lw          $v1, 0x170($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X170);
    // 0x80008C08: nop

L_80008C0C:
    // 0x80008C0C: mtc1        $v1, $f24
    ctx->f24.u32l = ctx->r3;
    // 0x80008C10: lbu         $t4, 0x174($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X174);
    // 0x80008C14: cvt.s.w     $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    ctx->f2.fl = CVT_S_W(ctx->f24.u32l);
    // 0x80008C18: mtc1        $t4, $f24
    ctx->f24.u32l = ctx->r12;
    // 0x80008C1C: bgez        $t4, L_80008C34
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80008C20: cvt.s.w     $f12, $f24
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = CVT_S_W(ctx->f24.u32l);
            goto L_80008C34;
    }
    // 0x80008C20: cvt.s.w     $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = CVT_S_W(ctx->f24.u32l);
    // 0x80008C24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80008C28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80008C2C: nop

    // 0x80008C30: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
L_80008C34:
    // 0x80008C34: lbu         $t5, 0x17D($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X17D);
    // 0x80008C38: lw          $t9, 0x254($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X254);
    // 0x80008C3C: bne         $t5, $zero, L_80008C8C
    if (ctx->r13 != 0) {
        // 0x80008C40: subu        $t7, $v1, $s6
        ctx->r15 = SUB32(ctx->r3, ctx->r22);
            goto L_80008C8C;
    }
    // 0x80008C40: subu        $t7, $v1, $s6
    ctx->r15 = SUB32(ctx->r3, ctx->r22);
    // 0x80008C44: mtc1        $s6, $f6
    ctx->f6.u32l = ctx->r22;
    // 0x80008C48: nop

    // 0x80008C4C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008C50: nop

    // 0x80008C54: div.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80008C58: sub.s       $f18, $f26, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f26.fl - ctx->f10.fl;
    // 0x80008C5C: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80008C60: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80008C64: nop

    // 0x80008C68: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80008C6C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008C70: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008C74: nop

    // 0x80008C78: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80008C7C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80008C80: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80008C84: b           L_80008CD8
    // 0x80008C88: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
        goto L_80008CD8;
    // 0x80008C88: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
L_80008C8C:
    // 0x80008C8C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80008C90: nop

    // 0x80008C94: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008C98: nop

    // 0x80008C9C: div.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80008CA0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80008CA4: nop

    // 0x80008CA8: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80008CAC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80008CB0: nop

    // 0x80008CB4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80008CB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008CBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008CC0: nop

    // 0x80008CC4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80008CC8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80008CCC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80008CD0: nop

    // 0x80008CD4: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
L_80008CD8:
    // 0x80008CD8: bne         $at, $zero, L_80008E38
    if (ctx->r1 != 0) {
        // 0x80008CDC: lw          $t4, 0xB0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XB0);
            goto L_80008E38;
    }
    // 0x80008CDC: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008CE0: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80008CE4: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // 0x80008CE8: lb          $v1, 0x17C($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X17C);
    // 0x80008CEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008CF0: bne         $v1, $at, L_80008D04
    if (ctx->r3 != ctx->r1) {
        // 0x80008CF4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80008D04;
    }
    // 0x80008CF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008CF8: lw          $t1, 0x12C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X12C);
    // 0x80008CFC: b           L_80008DD8
    // 0x80008D00: sw          $t1, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r9;
        goto L_80008DD8;
    // 0x80008D00: sw          $t1, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r9;
L_80008D04:
    // 0x80008D04: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80008D08: blez        $v1, L_80008D50
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80008D0C: sw          $zero, 0x250($sp)
        MEM_W(0X250, ctx->r29) = 0;
            goto L_80008D50;
    }
    // 0x80008D0C: sw          $zero, 0x250($sp)
    MEM_W(0X250, ctx->r29) = 0;
    // 0x80008D10: addiu       $s0, $sp, 0x1A8
    ctx->r16 = ADD32(ctx->r29, 0X1A8);
    // 0x80008D14: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
L_80008D18:
    // 0x80008D18: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80008D1C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80008D20: subu        $v1, $s5, $t2
    ctx->r3 = SUB32(ctx->r21, ctx->r10);
    // 0x80008D24: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80008D28: lb          $t3, 0x17C($s7)
    ctx->r11 = MEM_B(ctx->r23, 0X17C);
    // 0x80008D2C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80008D30: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80008D34: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008D38: bne         $at, $zero, L_80008D18
    if (ctx->r1 != 0) {
        // 0x80008D3C: addu        $a0, $a0, $v1
        ctx->r4 = ADD32(ctx->r4, ctx->r3);
            goto L_80008D18;
    }
    // 0x80008D3C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80008D40: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80008D44: nop

    // 0x80008D48: lb          $v1, 0x17C($t4)
    ctx->r3 = MEM_B(ctx->r12, 0X17C);
    // 0x80008D4C: nop

L_80008D50:
    // 0x80008D50: blez        $v1, L_80008DD8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80008D54: addiu       $s1, $sp, 0x12C
        ctx->r17 = ADD32(ctx->r29, 0X12C);
            goto L_80008DD8;
    }
    // 0x80008D54: addiu       $s1, $sp, 0x12C
    ctx->r17 = ADD32(ctx->r29, 0X12C);
    // 0x80008D58: lb          $a1, 0x17C($s7)
    ctx->r5 = MEM_B(ctx->r23, 0X17C);
    // 0x80008D5C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80008D60: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
    // 0x80008D64: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80008D68: lw          $a0, 0x250($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X250);
    // 0x80008D6C: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x80008D70: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
L_80008D74:
    // 0x80008D74: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80008D78: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80008D7C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80008D80: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80008D84: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008D88: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x80008D8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008D90: div.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80008D94: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80008D98: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80008D9C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80008DA0: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80008DA4: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80008DA8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80008DAC: nop

    // 0x80008DB0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80008DB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008DB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008DBC: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80008DC0: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80008DC4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80008DC8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80008DCC: bne         $at, $zero, L_80008D74
    if (ctx->r1 != 0) {
        // 0x80008DD0: nop
    
            goto L_80008D74;
    }
    // 0x80008DD0: nop

    // 0x80008DD4: sw          $a0, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r4;
L_80008DD8:
    // 0x80008DD8: slti        $at, $s6, 0x190
    ctx->r1 = SIGNED(ctx->r22) < 0X190 ? 1 : 0;
    // 0x80008DDC: beq         $at, $zero, L_80008E38
    if (ctx->r1 == 0) {
        // 0x80008DE0: lw          $t4, 0xB0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XB0);
            goto L_80008E38;
    }
    // 0x80008DE0: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80008DE4: mtc1        $s6, $f16
    ctx->f16.u32l = ctx->r22;
    // 0x80008DE8: lw          $t0, 0x250($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X250);
    // 0x80008DEC: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80008DF0: addiu       $t1, $t0, -0x40
    ctx->r9 = ADD32(ctx->r8, -0X40);
    // 0x80008DF4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80008DF8: div.s       $f18, $f8, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80008DFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80008E00: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80008E04: add.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x80008E08: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80008E0C: nop

    // 0x80008E10: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80008E14: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80008E18: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80008E1C: nop

    // 0x80008E20: cvt.w.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80008E24: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80008E28: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80008E2C: sw          $t3, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r11;
    // 0x80008E30: nop

    // 0x80008E34: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
L_80008E38:
    // 0x80008E38: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80008E3C: bne         $fp, $t4, L_80008B40
    if (ctx->r30 != ctx->r12) {
        // 0x80008E40: lw          $v0, 0x88($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X88);
            goto L_80008B40;
    }
    // 0x80008E40: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
L_80008E44:
    // 0x80008E44: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80008E48: lw          $t5, 0x254($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X254);
    // 0x80008E4C: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x80008E50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008E54: bne         $v0, $zero, L_80008F88
    if (ctx->r2 != 0) {
        // 0x80008E58: nop
    
            goto L_80008F88;
    }
    // 0x80008E58: nop

    // 0x80008E5C: lbu         $v0, 0x175($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X175);
    // 0x80008E60: nop

    // 0x80008E64: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80008E68: beq         $at, $zero, L_80008E78
    if (ctx->r1 == 0) {
        // 0x80008E6C: lw          $t7, 0x254($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X254);
            goto L_80008E78;
    }
    // 0x80008E6C: lw          $t7, 0x254($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X254);
    // 0x80008E70: sw          $v0, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r2;
    // 0x80008E74: lw          $t7, 0x254($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X254);
L_80008E78:
    // 0x80008E78: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x80008E7C: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x80008E80: bne         $at, $zero, L_80008F64
    if (ctx->r1 != 0) {
        // 0x80008E84: lw          $t7, 0x88($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X88);
            goto L_80008F64;
    }
    // 0x80008E84: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x80008E88: lbu         $t9, 0x176($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X176);
    // 0x80008E8C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80008E90: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80008E94: bgez        $t9, L_80008EA8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80008E98: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80008EA8;
    }
    // 0x80008E98: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80008E9C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80008EA0: nop

    // 0x80008EA4: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_80008EA8:
    // 0x80008EA8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80008EAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80008EB0: nop

    // 0x80008EB4: div.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80008EB8: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x80008EBC: lw          $a0, 0x178($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X178);
    // 0x80008EC0: nop

    // 0x80008EC4: bne         $a0, $zero, L_80008EE8
    if (ctx->r4 != 0) {
        // 0x80008EC8: nop
    
            goto L_80008EE8;
    }
    // 0x80008EC8: nop

    // 0x80008ECC: lhu         $a0, 0x16E($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X16E);
    // 0x80008ED0: jal         0x80001F14
    // 0x80008ED4: addiu       $a1, $t8, 0x178
    ctx->r5 = ADD32(ctx->r24, 0X178);
    sound_play_direct(rdram, ctx);
        goto after_26;
    // 0x80008ED4: addiu       $a1, $t8, 0x178
    ctx->r5 = ADD32(ctx->r24, 0X178);
    after_26:
    // 0x80008ED8: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80008EDC: nop

    // 0x80008EE0: lw          $a0, 0x178($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X178);
    // 0x80008EE4: nop

L_80008EE8:
    // 0x80008EE8: beq         $a0, $zero, L_80008FC8
    if (ctx->r4 == 0) {
        // 0x80008EEC: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008EEC: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008EF0: lw          $a2, 0x254($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X254);
    // 0x80008EF4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80008EF8: sll         $t1, $a2, 8
    ctx->r9 = S32(ctx->r6 << 8);
    // 0x80008EFC: jal         0x800049F8
    // 0x80008F00: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    sndp_set_param(rdram, ctx);
        goto after_27;
    // 0x80008F00: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_27:
    // 0x80008F04: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x80008F08: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x80008F0C: lw          $a0, 0x178($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X178);
    // 0x80008F10: jal         0x800049F8
    // 0x80008F14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_28;
    // 0x80008F14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_28:
    // 0x80008F18: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x80008F1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008F20: beq         $t3, $at, L_80008F2C
    if (ctx->r11 == ctx->r1) {
        // 0x80008F24: addiu       $t4, $zero, 0x40
        ctx->r12 = ADD32(0, 0X40);
            goto L_80008F2C;
    }
    // 0x80008F24: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80008F28: sw          $t4, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r12;
L_80008F2C:
    // 0x80008F2C: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80008F30: lw          $a2, 0x250($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X250);
    // 0x80008F34: lw          $a0, 0x178($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X178);
    // 0x80008F38: jal         0x800049F8
    // 0x80008F3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_29;
    // 0x80008F3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_29:
    // 0x80008F40: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x80008F44: nop

    // 0x80008F48: lw          $a0, 0x178($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X178);
    // 0x80008F4C: lbu         $a1, 0x17E($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X17E);
    // 0x80008F50: jal         0x80004604
    // 0x80008F54: nop

    sndp_set_priority(rdram, ctx);
        goto after_30;
    // 0x80008F54: nop

    after_30:
    // 0x80008F58: b           L_80008FC8
    // 0x80008F5C: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
        goto L_80008FC8;
    // 0x80008F5C: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008F60: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
L_80008F64:
    // 0x80008F64: nop

    // 0x80008F68: lw          $a0, 0x178($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X178);
    // 0x80008F6C: nop

    // 0x80008F70: beq         $a0, $zero, L_80008FC8
    if (ctx->r4 == 0) {
        // 0x80008F74: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008F74: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008F78: jal         0x8000488C
    // 0x80008F7C: nop

    sndp_stop(rdram, ctx);
        goto after_31;
    // 0x80008F7C: nop

    after_31:
    // 0x80008F80: b           L_80008FC8
    // 0x80008F84: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
        goto L_80008FC8;
    // 0x80008F84: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
L_80008F88:
    // 0x80008F88: bne         $v0, $at, L_80008FC8
    if (ctx->r2 != ctx->r1) {
        // 0x80008F8C: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008F8C: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008F90: lw          $t9, 0x24C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24C);
    // 0x80008F94: lw          $t8, 0x254($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X254);
    // 0x80008F98: nop

    // 0x80008F9C: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80008FA0: beq         $at, $zero, L_80008FC8
    if (ctx->r1 == 0) {
        // 0x80008FA4: lw          $t3, 0x260($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X260);
            goto L_80008FC8;
    }
    // 0x80008FA4: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
    // 0x80008FA8: lw          $t0, 0x250($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X250);
    // 0x80008FAC: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80008FB0: sw          $t8, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = ctx->r24;
    // 0x80008FB4: sw          $t0, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r8;
    // 0x80008FB8: lw          $t2, 0x16C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X16C);
    // 0x80008FBC: nop

    // 0x80008FC0: sw          $t2, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r10;
L_80008FC4:
    // 0x80008FC4: lw          $t3, 0x260($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X260);
L_80008FC8:
    // 0x80008FC8: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80008FCC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80008FD0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80008FD4: sw          $t4, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r12;
    // 0x80008FD8: bne         $t4, $at, L_80008AF8
    if (ctx->r12 != ctx->r1) {
        // 0x80008FDC: addiu       $v0, $v0, 0x180
        ctx->r2 = ADD32(ctx->r2, 0X180);
            goto L_80008AF8;
    }
    // 0x80008FDC: addiu       $v0, $v0, 0x180
    ctx->r2 = ADD32(ctx->r2, 0X180);
    // 0x80008FE0: lw          $t6, 0x24C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24C);
    // 0x80008FE4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80008FE8: slti        $at, $t6, 0xB
    ctx->r1 = SIGNED(ctx->r14) < 0XB ? 1 : 0;
    // 0x80008FEC: bne         $at, $zero, L_80009044
    if (ctx->r1 != 0) {
        // 0x80008FF0: nop
    
            goto L_80009044;
    }
    // 0x80008FF0: nop

    // 0x80008FF4: lbu         $t5, -0x4E68($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4E68);
    // 0x80008FF8: nop

    // 0x80008FFC: bne         $t5, $zero, L_80009044
    if (ctx->r13 != 0) {
        // 0x80009000: nop
    
            goto L_80009044;
    }
    // 0x80009000: nop

    // 0x80009004: jal         0x80001980
    // 0x80009008: nop

    music_jingle_current(rdram, ctx);
        goto after_32;
    // 0x80009008: nop

    after_32:
    // 0x8000900C: lw          $t7, 0x244($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X244);
    // 0x80009010: lbu         $a0, 0x247($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X247);
    // 0x80009014: beq         $t7, $v0, L_80009024
    if (ctx->r15 == ctx->r2) {
        // 0x80009018: nop
    
            goto L_80009024;
    }
    // 0x80009018: nop

    // 0x8000901C: jal         0x80001784
    // 0x80009020: nop

    music_jingle_play_safe(rdram, ctx);
        goto after_33;
    // 0x80009020: nop

    after_33:
L_80009024:
    // 0x80009024: lbu         $a0, 0x24F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X24F);
    // 0x80009028: jal         0x80001B0C
    // 0x8000902C: nop

    music_jingle_volume_set(rdram, ctx);
        goto after_34;
    // 0x8000902C: nop

    after_34:
    // 0x80009030: lbu         $a0, 0x24B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X24B);
    // 0x80009034: jal         0x80001B58
    // 0x80009038: nop

    music_jingle_pan_set(rdram, ctx);
        goto after_35;
    // 0x80009038: nop

    after_35:
    // 0x8000903C: b           L_80009050
    // 0x80009040: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
        goto L_80009050;
    // 0x80009040: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
L_80009044:
    // 0x80009044: jal         0x800018E0
    // 0x80009048: nop

    music_jingle_stop(rdram, ctx);
        goto after_36;
    // 0x80009048: nop

    after_36:
    // 0x8000904C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
L_80009050:
    // 0x80009050: lw          $a0, 0x268($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X268);
    // 0x80009054: beq         $a1, $zero, L_80009074
    if (ctx->r5 == 0) {
        // 0x80009058: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80009074;
    }
    // 0x80009058: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8000905C: lw          $t9, 0x270($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X270);
    // 0x80009060: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x80009064: lbu         $a3, 0xB3($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0XB3);
    // 0x80009068: jal         0x80006FC8
    // 0x8000906C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    racer_sound_update_all(rdram, ctx);
        goto after_37;
    // 0x8000906C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_37:
    // 0x80009070: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80009074:
    // 0x80009074: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80009078: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000907C: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80009080: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80009084: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80009088: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000908C: lwc1        $f27, 0x40($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80009090: lwc1        $f26, 0x44($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80009094: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80009098: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8000909C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800090A0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800090A4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800090A8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800090AC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800090B0: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800090B4: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800090B8: jr          $ra
    // 0x800090BC: addiu       $sp, $sp, 0x268
    ctx->r29 = ADD32(ctx->r29, 0X268);
    return;
    // 0x800090BC: addiu       $sp, $sp, 0x268
    ctx->r29 = ADD32(ctx->r29, 0X268);
;}
RECOMP_FUNC void cam_get_active_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069F60: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069F64: lb          $t6, 0x1294($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X1294);
    // 0x80069F68: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80069F6C: beq         $t6, $zero, L_80069F9C
    if (ctx->r14 == 0) {
        // 0x80069F70: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_80069F9C;
    }
    // 0x80069F70: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80069F74: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80069F78: lw          $t7, 0x1264($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1264);
    // 0x80069F7C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80069F80: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80069F84: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80069F88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80069F8C: addiu       $t9, $t8, 0x110
    ctx->r25 = ADD32(ctx->r24, 0X110);
    // 0x80069F90: addiu       $t0, $t0, 0x1040
    ctx->r8 = ADD32(ctx->r8, 0X1040);
    // 0x80069F94: jr          $ra
    // 0x80069F98: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    return;
    // 0x80069F98: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
L_80069F9C:
    // 0x80069F9C: lw          $t1, 0x1264($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1264);
    // 0x80069FA0: addiu       $t3, $t3, 0x1040
    ctx->r11 = ADD32(ctx->r11, 0X1040);
    // 0x80069FA4: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80069FA8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80069FAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80069FB0: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80069FB4: jr          $ra
    // 0x80069FB8: nop

    return;
    // 0x80069FB8: nop

;}
RECOMP_FUNC void catmull_rom_derivative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800227B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800227B4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800227B8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800227BC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800227C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800227C4: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800227C8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800227CC: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x800227D0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800227D4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800227D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800227DC: cvt.d.s     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f12.d = CVT_D_S(ctx->f10.fl);
    // 0x800227E0: mul.d       $f14, $f6, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f14.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800227E4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800227E8: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800227EC: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800227F0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800227F4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800227F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800227FC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80022800: mul.d       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80022804: lui         $at, 0xBFF8
    ctx->r1 = S32(0XBFF8 << 16);
    // 0x80022808: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8002280C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80022810: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80022814: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80022818: mul.d       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8002281C: add.d       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f14.d + ctx->f6.d;
    // 0x80022820: lui         $at, 0xC004
    ctx->r1 = S32(0XC004 << 16);
    // 0x80022824: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x80022828: add.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d + ctx->f10.d;
    // 0x8002282C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80022830: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80022834: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80022838: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8002283C: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022840: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80022844: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x80022848: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x8002284C: add.d       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f12.d + ctx->f6.d;
    // 0x80022850: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x80022854: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80022858: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002285C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80022860: mul.d       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x80022864: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80022868: mul.d       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x8002286C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80022870: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x80022874: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x80022878: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8002287C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022880: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80022884: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80022888: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002288C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80022890: swc1        $f6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f6.u32l;
    // 0x80022894: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80022898: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002289C: nop

    // 0x800228A0: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800228A4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800228A8: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800228AC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800228B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800228B4: jr          $ra
    // 0x800228B8: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
    return;
    // 0x800228B8: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
;}
RECOMP_FUNC void mtx_to_mtxs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7BC: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
    // 0x8006F7C0: lui         $t7, 0xFFFF
    ctx->r15 = S32(0XFFFF << 16);
L_8006F7C4:
    // 0x8006F7C4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8006F7C8: lw          $t2, 0x20($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X20);
    // 0x8006F7CC: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8006F7D0: lw          $t4, 0x24($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X24);
    // 0x8006F7D4: sh          $t1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r9;
    // 0x8006F7D8: sh          $t2, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r10;
    // 0x8006F7DC: sh          $t3, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r11;
    // 0x8006F7E0: sh          $t4, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r12;
    // 0x8006F7E4: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x8006F7E8: srl         $t2, $t2, 16
    ctx->r10 = S32(U32(ctx->r10) >> 16);
    // 0x8006F7EC: srl         $t3, $t3, 16
    ctx->r11 = S32(U32(ctx->r11) >> 16);
    // 0x8006F7F0: srl         $t4, $t4, 16
    ctx->r12 = S32(U32(ctx->r12) >> 16);
    // 0x8006F7F4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8006F7F8: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x8006F7FC: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
    // 0x8006F800: sh          $t3, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r11;
    // 0x8006F804: sh          $t4, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r12;
    // 0x8006F808: addi        $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8006F80C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006F810: bnel        $t0, $zero, L_8006F7C4
    if (ctx->r8 != 0) {
        // 0x8006F814: nop
    
            goto L_8006F7C4;
    }
    goto skip_0;
    // 0x8006F814: nop

    skip_0:
    // 0x8006F818: jr          $ra
    // 0x8006F81C: nop

    return;
    // 0x8006F81C: nop

;}
RECOMP_FUNC void slowly_reset_head_angle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005238C: lh          $v0, 0x16C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X16C);
    // 0x80052390: nop

    // 0x80052394: sra         $t6, $v0, 3
    ctx->r14 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80052398: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8005239C: sh          $t7, 0x16C($a0)
    MEM_H(0X16C, ctx->r4) = ctx->r15;
    // 0x800523A0: lh          $v0, 0x16C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X16C);
    // 0x800523A4: nop

    // 0x800523A8: slti        $at, $v0, -0x9
    ctx->r1 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
    // 0x800523AC: bne         $at, $zero, L_800523C0
    if (ctx->r1 != 0) {
        // 0x800523B0: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_800523C0;
    }
    // 0x800523B0: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800523B4: beq         $at, $zero, L_800523C0
    if (ctx->r1 == 0) {
        // 0x800523B8: nop
    
            goto L_800523C0;
    }
    // 0x800523B8: nop

    // 0x800523BC: sh          $zero, 0x16C($a0)
    MEM_H(0X16C, ctx->r4) = 0;
L_800523C0:
    // 0x800523C0: jr          $ra
    // 0x800523C4: nop

    return;
    // 0x800523C4: nop

;}
RECOMP_FUNC void charselect_assign_ai(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BFF4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008BFF8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008BFFC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008C000: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008C004: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008C008: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008C00C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008C010: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008C014: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008C018: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008C01C: jal         0x8009F214
    // 0x8008C020: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    is_drumstick_unlocked(rdram, ctx);
        goto after_0;
    // 0x8008C020: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    after_0:
    // 0x8008C024: beq         $v0, $zero, L_8008C030
    if (ctx->r2 == 0) {
        // 0x8008C028: nop
    
            goto L_8008C030;
    }
    // 0x8008C028: nop

    // 0x8008C02C: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
L_8008C030:
    // 0x8008C030: jal         0x8009F1FC
    // 0x8008C034: nop

    is_tt_unlocked(rdram, ctx);
        goto after_1;
    // 0x8008C034: nop

    after_1:
    // 0x8008C038: beq         $v0, $zero, L_8008C044
    if (ctx->r2 == 0) {
        // 0x8008C03C: slti        $at, $s0, 0x8
        ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
            goto L_8008C044;
    }
    // 0x8008C03C: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8008C040: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_8008C044:
    // 0x8008C044: beq         $at, $zero, L_8008C0A4
    if (ctx->r1 == 0) {
        // 0x8008C048: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8008C0A4;
    }
    // 0x8008C048: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008C04C: blez        $s0, L_8008C08C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008C050: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8008C08C;
    }
    // 0x8008C050: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008C054: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008C058: addiu       $t6, $t6, 0x6990
    ctx->r14 = ADD32(ctx->r14, 0X6990);
    // 0x8008C05C: addu        $s3, $zero, $t6
    ctx->r19 = ADD32(0, ctx->r14);
    // 0x8008C060: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x8008C064: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_8008C068:
    // 0x8008C068: lb          $t7, 0x0($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X0);
    // 0x8008C06C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008C070: bne         $v1, $t7, L_8008C07C
    if (ctx->r3 != ctx->r15) {
        // 0x8008C074: sltu        $at, $s3, $v0
        ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
            goto L_8008C07C;
    }
    // 0x8008C074: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x8008C078: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C07C:
    // 0x8008C07C: beq         $at, $zero, L_8008C08C
    if (ctx->r1 == 0) {
        // 0x8008C080: nop
    
            goto L_8008C08C;
    }
    // 0x8008C080: nop

    // 0x8008C084: beq         $s1, $zero, L_8008C068
    if (ctx->r17 == 0) {
        // 0x8008C088: nop
    
            goto L_8008C068;
    }
    // 0x8008C088: nop

L_8008C08C:
    // 0x8008C08C: bne         $s1, $zero, L_8008C0A4
    if (ctx->r17 != 0) {
        // 0x8008C090: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_8008C0A4;
    }
    // 0x8008C090: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x8008C094: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C098: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8008C09C: sb          $v1, 0x6990($at)
    MEM_B(0X6990, ctx->r1) = ctx->r3;
    // 0x8008C0A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8008C0A4:
    // 0x8008C0A4: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8008C0A8: beq         $at, $zero, L_8008C1B4
    if (ctx->r1 == 0) {
        // 0x8008C0AC: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_8008C1B4;
    }
    // 0x8008C0AC: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x8008C0B0: addiu       $t8, $t8, 0x6990
    ctx->r24 = ADD32(ctx->r24, 0X6990);
    // 0x8008C0B4: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008C0B8: addiu       $s4, $s4, 0x696C
    ctx->r20 = ADD32(ctx->r20, 0X696C);
    // 0x8008C0BC: addu        $s3, $s0, $t8
    ctx->r19 = ADD32(ctx->r16, ctx->r24);
    // 0x8008C0C0: addiu       $s5, $zero, 0xE
    ctx->r21 = ADD32(0, 0XE);
L_8008C0C4:
    // 0x8008C0C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008C0C8:
    // 0x8008C0C8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8008C0CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008C0D0: jal         0x8006FB8C
    // 0x8008C0D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x8008C0D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_2:
    // 0x8008C0D8: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008C0DC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8008C0E0: andi        $a1, $s2, 0x3
    ctx->r5 = ctx->r18 & 0X3;
    // 0x8008C0E4: mflo        $t0
    ctx->r8 = lo;
    // 0x8008C0E8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8008C0EC: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x8008C0F0: blez        $s2, L_8008C19C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8008C0F4: sb          $t2, 0x0($s3)
        MEM_B(0X0, ctx->r19) = ctx->r10;
            goto L_8008C19C;
    }
    // 0x8008C0F4: sb          $t2, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r10;
    // 0x8008C0F8: beq         $a1, $zero, L_8008C130
    if (ctx->r5 == 0) {
        // 0x8008C0FC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8008C130;
    }
    // 0x8008C0FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8008C100: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008C104: addiu       $t3, $t3, 0x6990
    ctx->r11 = ADD32(ctx->r11, 0X6990);
    // 0x8008C108: lb          $v1, 0x0($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X0);
    // 0x8008C10C: addu        $v0, $s0, $t3
    ctx->r2 = ADD32(ctx->r16, ctx->r11);
L_8008C110:
    // 0x8008C110: lb          $t4, 0x0($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X0);
    // 0x8008C114: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008C118: bne         $t4, $v1, L_8008C124
    if (ctx->r12 != ctx->r3) {
        // 0x8008C11C: nop
    
            goto L_8008C124;
    }
    // 0x8008C11C: nop

    // 0x8008C120: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C124:
    // 0x8008C124: bne         $a0, $s0, L_8008C110
    if (ctx->r4 != ctx->r16) {
        // 0x8008C128: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8008C110;
    }
    // 0x8008C128: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008C12C: beq         $s0, $s2, L_8008C19C
    if (ctx->r16 == ctx->r18) {
        // 0x8008C130: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8008C19C;
    }
L_8008C130:
    // 0x8008C130: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008C134: addiu       $t5, $t5, 0x6990
    ctx->r13 = ADD32(ctx->r13, 0X6990);
    // 0x8008C138: lb          $v1, 0x0($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X0);
    // 0x8008C13C: addu        $v0, $s0, $t5
    ctx->r2 = ADD32(ctx->r16, ctx->r13);
    // 0x8008C140: addu        $a0, $s2, $t5
    ctx->r4 = ADD32(ctx->r18, ctx->r13);
L_8008C144:
    // 0x8008C144: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8008C148: nop

    // 0x8008C14C: bne         $t6, $v1, L_8008C158
    if (ctx->r14 != ctx->r3) {
        // 0x8008C150: nop
    
            goto L_8008C158;
    }
    // 0x8008C150: nop

    // 0x8008C154: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C158:
    // 0x8008C158: lb          $t7, 0x1($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1);
    // 0x8008C15C: nop

    // 0x8008C160: bne         $t7, $v1, L_8008C16C
    if (ctx->r15 != ctx->r3) {
        // 0x8008C164: nop
    
            goto L_8008C16C;
    }
    // 0x8008C164: nop

    // 0x8008C168: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C16C:
    // 0x8008C16C: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    // 0x8008C170: nop

    // 0x8008C174: bne         $t8, $v1, L_8008C180
    if (ctx->r24 != ctx->r3) {
        // 0x8008C178: nop
    
            goto L_8008C180;
    }
    // 0x8008C178: nop

    // 0x8008C17C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C180:
    // 0x8008C180: lb          $t9, 0x3($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3);
    // 0x8008C184: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008C188: bne         $t9, $v1, L_8008C194
    if (ctx->r25 != ctx->r3) {
        // 0x8008C18C: nop
    
            goto L_8008C194;
    }
    // 0x8008C18C: nop

    // 0x8008C190: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8008C194:
    // 0x8008C194: bne         $v0, $a0, L_8008C144
    if (ctx->r2 != ctx->r4) {
        // 0x8008C198: nop
    
            goto L_8008C144;
    }
    // 0x8008C198: nop

L_8008C19C:
    // 0x8008C19C: bne         $s1, $zero, L_8008C0C8
    if (ctx->r17 != 0) {
        // 0x8008C1A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008C0C8;
    }
    // 0x8008C1A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008C1A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008C1A8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8008C1AC: bne         $s2, $at, L_8008C0C4
    if (ctx->r18 != ctx->r1) {
        // 0x8008C1B0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8008C0C4;
    }
    // 0x8008C1B0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8008C1B4:
    // 0x8008C1B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8008C1B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C1BC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C1C0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008C1C4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008C1C8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008C1CC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008C1D0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008C1D4: jr          $ra
    // 0x8008C1D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8008C1D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void lights_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BA0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80031BA4: lw          $a0, -0x3140($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3140);
    // 0x80031BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031BAC: beq         $a0, $zero, L_80031BDC
    if (ctx->r4 == 0) {
        // 0x80031BB0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80031BDC;
    }
    // 0x80031BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031BB4: jal         0x80071380
    // 0x80031BB8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x80031BB8: nop

    after_0:
    // 0x80031BBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BC0: sw          $zero, -0x3140($at)
    MEM_W(-0X3140, ctx->r1) = 0;
    // 0x80031BC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BC8: sw          $zero, -0x313C($at)
    MEM_W(-0X313C, ctx->r1) = 0;
    // 0x80031BCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BD0: sw          $zero, -0x3130($at)
    MEM_W(-0X3130, ctx->r1) = 0;
    // 0x80031BD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BD8: sw          $zero, -0x312C($at)
    MEM_W(-0X312C, ctx->r1) = 0;
L_80031BDC:
    // 0x80031BDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031BE4: sw          $zero, -0x3134($at)
    MEM_W(-0X3134, ctx->r1) = 0;
    // 0x80031BE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031BEC: sw          $zero, -0x3138($at)
    MEM_W(-0X3138, ctx->r1) = 0;
    // 0x80031BF0: jr          $ra
    // 0x80031BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80031BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void obj_init_unknown96(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038254: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80038258: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003825C: addiu       $t6, $zero, 0x81
    ctx->r14 = ADD32(0, 0X81);
    // 0x80038260: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80038264: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80038268: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8003826C: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80038270: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80038274: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80038278: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x8003827C: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80038280: jr          $ra
    // 0x80038284: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x80038284: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void sndp_init_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800031C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800031C4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800031C8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800031CC: addiu       $s2, $s2, -0x33D4
    ctx->r18 = ADD32(ctx->r18, -0X33D4);
    // 0x800031D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800031D4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800031D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800031DC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800031E0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800031E4: ori         $t1, $zero, 0x80E8
    ctx->r9 = 0 | 0X80E8;
    // 0x800031E8: sw          $t6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r14;
    // 0x800031EC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800031F0: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800031F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800031F8: sw          $t8, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r24;
    // 0x800031FC: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80003200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80003204: sw          $zero, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = 0;
    // 0x80003208: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8000320C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003210: sw          $t1, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->r9;
    // 0x80003214: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80003218: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8000321C: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x80003220: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80003224: jal         0x800C7D50
    // 0x80003228: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80003228: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8000322C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80003230: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80003234: sw          $v0, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r2;
    // 0x80003238: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8000323C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80003240: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80003244: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80003248: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000324C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80003250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80003254: jal         0x800C7D50
    // 0x80003258: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80003258: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8000325C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80003260: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x80003264: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80003268: jal         0x800C98BC
    // 0x8000326C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqNew(rdram, ctx);
        goto after_2;
    // 0x8000326C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_2:
    // 0x80003270: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80003274: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80003278: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8000327C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80003280: sw          $t9, -0x33D8($at)
    MEM_W(-0X33D8, ctx->r1) = ctx->r25;
    // 0x80003284: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80003288: nop

    // 0x8000328C: sltiu       $at, $t0, 0x2
    ctx->r1 = ctx->r8 < 0X2 ? 1 : 0;
    // 0x80003290: bne         $at, $zero, L_800032C8
    if (ctx->r1 != 0) {
        // 0x80003294: nop
    
            goto L_800032C8;
    }
    // 0x80003294: nop

L_80003298:
    // 0x80003298: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8000329C: sll         $t2, $s0, 6
    ctx->r10 = S32(ctx->r16 << 6);
    // 0x800032A0: lw          $v0, 0x40($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X40);
    // 0x800032A4: nop

    // 0x800032A8: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    // 0x800032AC: jal         0x800C8CF0
    // 0x800032B0: addiu       $a1, $a0, -0x40
    ctx->r5 = ADD32(ctx->r4, -0X40);
    alLink(rdram, ctx);
        goto after_3;
    // 0x800032B0: addiu       $a1, $a0, -0x40
    ctx->r5 = ADD32(ctx->r4, -0X40);
    after_3:
    // 0x800032B4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x800032B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800032BC: sltu        $at, $s0, $t3
    ctx->r1 = ctx->r16 < ctx->r11 ? 1 : 0;
    // 0x800032C0: bne         $at, $zero, L_80003298
    if (ctx->r1 != 0) {
        // 0x800032C4: nop
    
            goto L_80003298;
    }
    // 0x800032C4: nop

L_800032C8:
    // 0x800032C8: lhu         $t4, 0x10($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X10);
    // 0x800032CC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x800032D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800032D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800032D8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800032DC: jal         0x800C7D50
    // 0x800032E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x800032E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_4:
    // 0x800032E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800032E8: addiu       $a0, $a0, -0x5E58
    ctx->r4 = ADD32(ctx->r4, -0X5E58);
    // 0x800032EC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800032F0: lhu         $t5, 0x10($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X10);
    // 0x800032F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800032F8: beq         $t5, $zero, L_8000332C
    if (ctx->r13 == 0) {
        // 0x800032FC: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8000332C;
    }
    // 0x800032FC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80003300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003304: addiu       $v1, $zero, 0x7FFF
    ctx->r3 = ADD32(0, 0X7FFF);
L_80003308:
    // 0x80003308: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000330C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80003310: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80003314: sh          $v1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r3;
    // 0x80003318: lhu         $t8, 0x10($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X10);
    // 0x8000331C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80003320: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x80003324: bne         $at, $zero, L_80003308
    if (ctx->r1 != 0) {
        // 0x80003328: nop
    
            goto L_80003308;
    }
    // 0x80003328: nop

L_8000332C:
    // 0x8000332C: lw          $t9, 0x3D10($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3D10);
    // 0x80003330: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80003334: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80003338: sw          $t9, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r25;
    // 0x8000333C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80003340: addiu       $t2, $t2, 0x33C8
    ctx->r10 = ADD32(ctx->r10, 0X33C8);
    // 0x80003344: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80003348: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8000334C: nop

    // 0x80003350: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x80003354: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003358: nop

    // 0x8000335C: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x80003360: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003364: nop

    // 0x80003368: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8000336C: jal         0x800C9930
    // 0x80003370: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSynAddPlayer(rdram, ctx);
        goto after_5;
    // 0x80003370: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80003374: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003378: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x8000337C: sh          $t4, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r12;
    // 0x80003380: lw          $a2, 0x4C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4C);
    // 0x80003384: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80003388: jal         0x800C970C
    // 0x8000338C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_6;
    // 0x8000338C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_6:
    // 0x80003390: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80003394: nop

    // 0x80003398: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x8000339C: jal         0x800C9830
    // 0x800033A0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    alEvtqNextEvent(rdram, ctx);
        goto after_7;
    // 0x800033A0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_7:
    // 0x800033A4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800033A8: nop

    // 0x800033AC: sw          $v0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r2;
    // 0x800033B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800033B4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800033B8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800033BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800033C0: jr          $ra
    // 0x800033C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800033C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ainode_find_nearest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C558: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8001C55C: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8001C560: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8001C564: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001C568: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8001C56C: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8001C570: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001C574: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8001C578: mov.s       $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.fl = ctx->f14.fl;
    // 0x8001C57C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x8001C580: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8001C584: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8001C588: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8001C58C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8001C590: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8001C594: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8001C598: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8001C59C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8001C5A0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001C5A4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001C5A8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8001C5AC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001C5B0: beq         $a3, $zero, L_8001C5C4
    if (ctx->r7 == 0) {
        // 0x8001C5B4: swc1        $f20, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
            goto L_8001C5C4;
    }
    // 0x8001C5B4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8001C5B8: jal         0x8001C44C
    // 0x8001C5BC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    obj_elevation(rdram, ctx);
        goto after_0;
    // 0x8001C5BC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_0:
    // 0x8001C5C0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
L_8001C5C4:
    // 0x8001C5C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C5C8: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8001C5CC: lw          $fp, 0x64($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X64);
    // 0x8001C5D0: lwc1        $f20, 0x5BD4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5BD4);
    // 0x8001C5D4: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x8001C5D8: addiu       $s3, $s3, -0x4B7C
    ctx->r19 = ADD32(ctx->r19, -0X4B7C);
    // 0x8001C5DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001C5E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C5E4: addiu       $s6, $zero, 0x80
    ctx->r22 = ADD32(0, 0X80);
    // 0x8001C5E8: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8001C5EC: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_8001C5F0:
    // 0x8001C5F0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8001C5F4: nop

    // 0x8001C5F8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8001C5FC: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8001C600: nop

    // 0x8001C604: beq         $v0, $zero, L_8001C698
    if (ctx->r2 == 0) {
        // 0x8001C608: nop
    
            goto L_8001C698;
    }
    // 0x8001C608: nop

    // 0x8001C60C: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x8001C610: beq         $s2, $zero, L_8001C62C
    if (ctx->r18 == 0) {
        // 0x8001C614: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8001C62C;
    }
    // 0x8001C614: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001C618: lb          $t8, 0xE($v1)
    ctx->r24 = MEM_B(ctx->r3, 0XE);
    // 0x8001C61C: nop

    // 0x8001C620: beq         $fp, $t8, L_8001C62C
    if (ctx->r30 == ctx->r24) {
        // 0x8001C624: nop
    
            goto L_8001C62C;
    }
    // 0x8001C624: nop

    // 0x8001C628: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001C62C:
    // 0x8001C62C: bne         $s2, $s4, L_8001C648
    if (ctx->r18 != ctx->r20) {
        // 0x8001C630: nop
    
            goto L_8001C648;
    }
    // 0x8001C630: nop

    // 0x8001C634: lbu         $t9, 0x8($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X8);
    // 0x8001C638: nop

    // 0x8001C63C: beq         $s5, $t9, L_8001C648
    if (ctx->r21 == ctx->r25) {
        // 0x8001C640: nop
    
            goto L_8001C648;
    }
    // 0x8001C640: nop

    // 0x8001C644: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001C648:
    // 0x8001C648: beq         $a0, $zero, L_8001C698
    if (ctx->r4 == 0) {
        // 0x8001C64C: nop
    
            goto L_8001C698;
    }
    // 0x8001C64C: nop

    // 0x8001C650: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C654: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C658: sub.s       $f0, $f4, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x8001C65C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C660: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001C664: sub.s       $f2, $f6, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x8001C668: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001C66C: sub.s       $f14, $f8, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x8001C670: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001C674: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8001C678: jal         0x800CA030
    // 0x8001C67C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001C67C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_1:
    // 0x8001C680: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8001C684: nop

    // 0x8001C688: bc1f        L_8001C698
    if (!c1cs) {
        // 0x8001C68C: nop
    
            goto L_8001C698;
    }
    // 0x8001C68C: nop

    // 0x8001C690: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001C694: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
L_8001C698:
    // 0x8001C698: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001C69C: bne         $s0, $s6, L_8001C5F0
    if (ctx->r16 != ctx->r22) {
        // 0x8001C6A0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8001C5F0;
    }
    // 0x8001C6A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8001C6A4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8001C6A8: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x8001C6AC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8001C6B0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8001C6B4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001C6B8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8001C6BC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001C6C0: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8001C6C4: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001C6C8: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8001C6CC: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001C6D0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8001C6D4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8001C6D8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8001C6DC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8001C6E0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8001C6E4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8001C6E8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8001C6EC: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8001C6F0: jr          $ra
    // 0x8001C6F4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8001C6F4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void tt_menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E080: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009E084: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009E088: jal         0x8006ECD0
    // 0x8009E08C: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009E08C: nop

    after_0:
    // 0x8009E090: jal         0x8009F1C4
    // 0x8009E094: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    is_in_two_player_adventure(rdram, ctx);
        goto after_1;
    // 0x8009E094: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x8009E098: beq         $v0, $zero, L_8009E0B8
    if (ctx->r2 == 0) {
        // 0x8009E09C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009E0B8;
    }
    // 0x8009E09C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E0A0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8009E0A4: nop

    // 0x8009E0A8: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8009E0AC: nop

    // 0x8009E0B0: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8009E0B4: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
L_8009E0B8:
    // 0x8009E0B8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8009E0BC: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8009E0C0: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8009E0C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E0C8: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8009E0CC: bne         $t9, $zero, L_8009E0D8
    if (ctx->r25 != 0) {
        // 0x8009E0D0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009E0D8;
    }
    // 0x8009E0D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E0D4: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
L_8009E0D8:
    // 0x8009E0D8: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E0DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009E0E0: beq         $v1, $at, L_8009E12C
    if (ctx->r3 == ctx->r1) {
        // 0x8009E0E4: addiu       $a1, $zero, 0x18
        ctx->r5 = ADD32(0, 0X18);
            goto L_8009E12C;
    }
    // 0x8009E0E4: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009E0E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009E0EC: beq         $v1, $at, L_8009E12C
    if (ctx->r3 == ctx->r1) {
        // 0x8009E0F0: addiu       $t2, $zero, 0x78
        ctx->r10 = ADD32(0, 0X78);
            goto L_8009E12C;
    }
    // 0x8009E0F0: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x8009E0F4: jal         0x8001B7B4
    // 0x8009E0F8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    has_ghost_to_save(rdram, ctx);
        goto after_2;
    // 0x8009E0F8: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_2:
    // 0x8009E0FC: beq         $v0, $zero, L_8009E10C
    if (ctx->r2 == 0) {
        // 0x8009E100: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009E10C;
    }
    // 0x8009E100: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E104: addiu       $t3, $zero, 0x88
    ctx->r11 = ADD32(0, 0X88);
    // 0x8009E108: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_8009E10C:
    // 0x8009E10C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8009E110: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8009E114: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009E118: addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    // 0x8009E11C: jal         0x800C543C
    // 0x8009E120: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_3;
    // 0x8009E120: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x8009E124: b           L_8009E144
    // 0x8009E128: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8009E144;
    // 0x8009E128: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8009E12C:
    // 0x8009E12C: addiu       $t5, $zero, 0xDC
    ctx->r13 = ADD32(0, 0XDC);
    // 0x8009E130: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009E134: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8009E138: jal         0x800C543C
    // 0x8009E13C: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_4;
    // 0x8009E13C: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_4:
    // 0x8009E140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8009E144:
    // 0x8009E144: jal         0x800C54DC
    // 0x8009E148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_5;
    // 0x8009E148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8009E14C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8009E150: jal         0x8006A794
    // 0x8009E154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_6;
    // 0x8009E154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8009E158: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E15C: sb          $zero, 0x6AA4($at)
    MEM_B(0X6AA4, ctx->r1) = 0;
    // 0x8009E160: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009E164: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E168: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8009E16C: addiu       $t0, $t0, 0x6A82
    ctx->r8 = ADD32(ctx->r8, 0X6A82);
    // 0x8009E170: sb          $t6, 0x6AAE($at)
    MEM_B(0X6AAE, ctx->r1) = ctx->r14;
    // 0x8009E174: lb          $v1, 0x0($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X0);
    // 0x8009E178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009E17C: sltiu       $at, $v1, 0xB
    ctx->r1 = ctx->r3 < 0XB ? 1 : 0;
    // 0x8009E180: beq         $at, $zero, L_8009E8C0
    if (ctx->r1 == 0) {
        // 0x8009E184: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_8009E8C0;
    }
    // 0x8009E184: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8009E188: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8009E18C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009E190: addu        $at, $at, $t7
    gpr jr_addend_8009E19C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8009E194: lw          $t7, -0x7490($at)
    ctx->r15 = ADD32(ctx->r1, -0X7490);
    // 0x8009E198: nop

    // 0x8009E19C: jr          $t7
    // 0x8009E1A0: nop

    switch (jr_addend_8009E19C >> 2) {
        case 0: goto L_8009E1A4; break;
        case 1: goto L_8009E434; break;
        case 2: goto L_8009E8C0; break;
        case 3: goto L_8009E8C0; break;
        case 4: goto L_8009E4F4; break;
        case 5: goto L_8009E530; break;
        case 6: goto L_8009E5DC; break;
        case 7: goto L_8009E6D8; break;
        case 8: goto L_8009E780; break;
        case 9: goto L_8009E8C0; break;
        case 10: goto L_8009E1A4; break;
        default: switch_error(__func__, 0x8009E19C, 0x800E8B70);
    }
    // 0x8009E1A0: nop

L_8009E1A4:
    // 0x8009E1A4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009E1A8: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8009E1AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009E1B0: lw          $a3, 0x2F4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X2F4);
    // 0x8009E1B4: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8009E1B8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8009E1BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009E1C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E1C4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E1C8: jal         0x800C56C8
    // 0x8009E1CC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_7;
    // 0x8009E1CC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_7:
    // 0x8009E1D0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009E1D4: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x8009E1D8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E1DC: lw          $a0, 0x11C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X11C);
    // 0x8009E1E0: jal         0x8009D6FC
    // 0x8009E1E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    render_dialogue_option(rdram, ctx);
        goto after_8;
    // 0x8009E1E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x8009E1E8: jal         0x8009F1C4
    // 0x8009E1EC: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_9;
    // 0x8009E1EC: nop

    after_9:
    // 0x8009E1F0: bne         $v0, $zero, L_8009E260
    if (ctx->r2 != 0) {
        // 0x8009E1F4: nop
    
            goto L_8009E260;
    }
    // 0x8009E1F4: nop

    // 0x8009E1F8: jal         0x8000E4C8
    // 0x8009E1FC: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_10;
    // 0x8009E1FC: nop

    after_10:
    // 0x8009E200: beq         $v0, $zero, L_8009E228
    if (ctx->r2 == 0) {
        // 0x8009E204: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8009E228;
    }
    // 0x8009E204: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009E208: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009E20C: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x8009E210: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E214: lw          $a0, 0x104($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X104);
    // 0x8009E218: jal         0x8009D6FC
    // 0x8009E21C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_11;
    // 0x8009E21C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8009E220: b           L_8009E23C
    // 0x8009E224: nop

        goto L_8009E23C;
    // 0x8009E224: nop

L_8009E228:
    // 0x8009E228: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009E22C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E230: lw          $a0, 0x108($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X108);
    // 0x8009E234: jal         0x8009D6FC
    // 0x8009E238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    render_dialogue_option(rdram, ctx);
        goto after_12;
    // 0x8009E238: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
L_8009E23C:
    // 0x8009E23C: jal         0x8001B7B4
    // 0x8009E240: nop

    has_ghost_to_save(rdram, ctx);
        goto after_13;
    // 0x8009E240: nop

    after_13:
    // 0x8009E244: beq         $v0, $zero, L_8009E260
    if (ctx->r2 == 0) {
        // 0x8009E248: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8009E260;
    }
    // 0x8009E248: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009E24C: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009E250: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E254: lw          $a0, 0x6C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X6C);
    // 0x8009E258: jal         0x8009D6FC
    // 0x8009E25C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    render_dialogue_option(rdram, ctx);
        goto after_14;
    // 0x8009E25C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
L_8009E260:
    // 0x8009E260: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009E264: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8009E268: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8009E26C: lw          $a0, 0x14($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X14);
    // 0x8009E270: jal         0x8009D6FC
    // 0x8009E274: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_option(rdram, ctx);
        goto after_15;
    // 0x8009E274: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_15:
    // 0x8009E278: jal         0x8009D7B0
    // 0x8009E27C: nop

    handle_menu_joystick_input(rdram, ctx);
        goto after_16;
    // 0x8009E27C: nop

    after_16:
    // 0x8009E280: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009E284: lb          $t7, 0x6AB6($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6AB6);
    // 0x8009E288: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009E28C: bne         $t7, $zero, L_8009E2FC
    if (ctx->r15 != 0) {
        // 0x8009E290: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_8009E2FC;
    }
    // 0x8009E290: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8009E294: lb          $v0, 0x69FC($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X69FC);
    // 0x8009E298: nop

    // 0x8009E29C: blez        $v0, L_8009E2CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009E2A0: nop
    
            goto L_8009E2CC;
    }
    // 0x8009E2A0: nop

    // 0x8009E2A4: jal         0x8000E4C8
    // 0x8009E2A8: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_17;
    // 0x8009E2A8: nop

    after_17:
    // 0x8009E2AC: bne         $v0, $zero, L_8009E2BC
    if (ctx->r2 != 0) {
        // 0x8009E2B0: addiu       $a0, $zero, 0x231
        ctx->r4 = ADD32(0, 0X231);
            goto L_8009E2BC;
    }
    // 0x8009E2B0: addiu       $a0, $zero, 0x231
    ctx->r4 = ADD32(0, 0X231);
    // 0x8009E2B4: jal         0x80036C0C
    // 0x8009E2B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_18;
    // 0x8009E2B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
L_8009E2BC:
    // 0x8009E2BC: jal         0x8000E4BC
    // 0x8009E2C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_time_trial_enabled(rdram, ctx);
        goto after_19;
    // 0x8009E2C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x8009E2C4: b           L_8009E2FC
    // 0x8009E2C8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
        goto L_8009E2FC;
    // 0x8009E2C8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8009E2CC:
    // 0x8009E2CC: bgez        $v0, L_8009E2FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009E2D0: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_8009E2FC;
    }
    // 0x8009E2D0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8009E2D4: jal         0x8000E4C8
    // 0x8009E2D8: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_20;
    // 0x8009E2D8: nop

    after_20:
    // 0x8009E2DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009E2E0: bne         $v0, $at, L_8009E2F0
    if (ctx->r2 != ctx->r1) {
        // 0x8009E2E4: addiu       $a0, $zero, 0x230
        ctx->r4 = ADD32(0, 0X230);
            goto L_8009E2F0;
    }
    // 0x8009E2E4: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    // 0x8009E2E8: jal         0x80036C0C
    // 0x8009E2EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_21;
    // 0x8009E2EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
L_8009E2F0:
    // 0x8009E2F0: jal         0x8000E4BC
    // 0x8009E2F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_time_trial_enabled(rdram, ctx);
        goto after_22;
    // 0x8009E2F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x8009E2F8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8009E2FC:
    // 0x8009E2FC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8009E300: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8009E304: beq         $t9, $zero, L_8009E3D0
    if (ctx->r25 == 0) {
        // 0x8009E308: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8009E3D0;
    }
    // 0x8009E308: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009E30C: lb          $t1, 0x6A82($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X6A82);
    // 0x8009E310: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8009E314: beq         $t1, $at, L_8009E3D0
    if (ctx->r9 == ctx->r1) {
        // 0x8009E318: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009E3D0;
    }
    // 0x8009E318: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E31C: lb          $v1, 0x6AB6($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6AB6);
    // 0x8009E320: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009E324: beq         $v1, $at, L_8009E340
    if (ctx->r3 == ctx->r1) {
        // 0x8009E328: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009E340;
    }
    // 0x8009E328: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009E32C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009E330: beq         $v1, $at, L_8009E378
    if (ctx->r3 == ctx->r1) {
        // 0x8009E334: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009E378;
    }
    // 0x8009E334: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009E338: b           L_8009E3C8
    // 0x8009E33C: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
        goto L_8009E3C8;
    // 0x8009E33C: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
L_8009E340:
    // 0x8009E340: jal         0x80001D04
    // 0x8009E344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_23;
    // 0x8009E344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x8009E348: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E34C: addiu       $a0, $a0, 0x6938
    ctx->r4 = ADD32(ctx->r4, 0X6938);
    // 0x8009E350: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8009E354: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E358: sw          $zero, 0x6940($at)
    MEM_W(0X6940, ctx->r1) = 0;
    // 0x8009E35C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E360: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E364: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8009E368: lb          $v1, 0x6AB6($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6AB6);
    // 0x8009E36C: b           L_8009E3C4
    // 0x8009E370: sb          $t2, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r10;
        goto L_8009E3C4;
    // 0x8009E370: sb          $t2, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r10;
    // 0x8009E374: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
L_8009E378:
    // 0x8009E378: jal         0x80001D04
    // 0x8009E37C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_24;
    // 0x8009E37C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x8009E380: addiu       $a0, $zero, 0x22E
    ctx->r4 = ADD32(0, 0X22E);
    // 0x8009E384: jal         0x80036C0C
    // 0x8009E388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_25;
    // 0x8009E388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x8009E38C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009E390: jal         0x8009CBB8
    // 0x8009E394: addiu       $a0, $a0, 0x23AC
    ctx->r4 = ADD32(ctx->r4, 0X23AC);
    menu_assetgroup_load(rdram, ctx);
        goto after_26;
    // 0x8009E394: addiu       $a0, $a0, 0x23AC
    ctx->r4 = ADD32(ctx->r4, 0X23AC);
    after_26:
    // 0x8009E398: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009E39C: jal         0x8009CDE8
    // 0x8009E3A0: addiu       $a0, $a0, 0x23C0
    ctx->r4 = ADD32(ctx->r4, 0X23C0);
    menu_imagegroup_load(rdram, ctx);
        goto after_27;
    // 0x8009E3A0: addiu       $a0, $a0, 0x23C0
    ctx->r4 = ADD32(ctx->r4, 0X23C0);
    after_27:
    // 0x8009E3A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8009E3A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009E3AC: sb          $t3, 0x23A8($at)
    MEM_B(0X23A8, ctx->r1) = ctx->r11;
    // 0x8009E3B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E3B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E3B8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8009E3BC: lb          $v1, 0x6AB6($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6AB6);
    // 0x8009E3C0: sb          $t4, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r12;
L_8009E3C4:
    // 0x8009E3C4: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
L_8009E3C8:
    // 0x8009E3C8: b           L_8009E3EC
    // 0x8009E3CC: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
        goto L_8009E3EC;
    // 0x8009E3CC: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
L_8009E3D0:
    // 0x8009E3D0: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8009E3D4: beq         $t7, $zero, L_8009E3EC
    if (ctx->r15 == 0) {
        // 0x8009E3D8: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8009E3EC;
    }
    // 0x8009E3D8: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009E3DC: jal         0x80001D04
    // 0x8009E3E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_28;
    // 0x8009E3E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x8009E3E4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8009E3E8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_8009E3EC:
    // 0x8009E3EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E3F0: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E3F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009E3F8: bne         $v1, $at, L_8009E404
    if (ctx->r3 != ctx->r1) {
        // 0x8009E3FC: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_8009E404;
    }
    // 0x8009E3FC: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8009E400: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8009E404:
    // 0x8009E404: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8009E408: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009E40C: bne         $t9, $at, L_8009E420
    if (ctx->r25 != ctx->r1) {
        // 0x8009E410: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8009E420;
    }
    // 0x8009E410: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8009E414: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E418: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
    // 0x8009E41C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_8009E420:
    // 0x8009E420: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8009E424: bne         $v1, $at, L_8009E8C4
    if (ctx->r3 != ctx->r1) {
        // 0x8009E428: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8009E8C4;
    }
    // 0x8009E428: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009E42C: b           L_8009E8C0
    // 0x8009E430: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_8009E8C0;
    // 0x8009E430: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_8009E434:
    // 0x8009E434: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E438: lw          $a0, 0x6948($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6948);
    // 0x8009E43C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009E440: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8009E444: addiu       $t6, $zero, 0x3A
    ctx->r14 = ADD32(0, 0X3A);
    // 0x8009E448: beq         $a1, $zero, L_8009E460
    if (ctx->r5 == 0) {
        // 0x8009E44C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8009E460;
    }
    // 0x8009E44C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8009E450:
    // 0x8009E450: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8009E454: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009E458: bne         $t3, $zero, L_8009E450
    if (ctx->r11 != 0) {
        // 0x8009E45C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8009E450;
    }
    // 0x8009E45C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8009E460:
    // 0x8009E460: blez        $v1, L_8009E4D0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009E464: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8009E4D0;
    }
    // 0x8009E464: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8009E468: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8009E46C: beq         $a1, $zero, L_8009E4D0
    if (ctx->r5 == 0) {
        // 0x8009E470: subu        $a2, $t6, $t5
        ctx->r6 = SUB32(ctx->r14, ctx->r13);
            goto L_8009E4D0;
    }
    // 0x8009E470: subu        $a2, $t6, $t5
    ctx->r6 = SUB32(ctx->r14, ctx->r13);
    // 0x8009E474: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8009E478: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009E47C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_8009E480:
    // 0x8009E480: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009E484: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009E488: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009E48C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E490: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E494: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8009E498: jal         0x800C56C8
    // 0x8009E49C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    render_dialogue_text(rdram, ctx);
        goto after_29;
    // 0x8009E49C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_29:
    // 0x8009E4A0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009E4A4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009E4A8: lw          $t9, 0x6948($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6948);
    // 0x8009E4AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009E4B0: addu        $t1, $t9, $v1
    ctx->r9 = ADD32(ctx->r25, ctx->r3);
    // 0x8009E4B4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8009E4B8: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x8009E4BC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8009E4C0: bne         $a3, $zero, L_8009E480
    if (ctx->r7 != 0) {
        // 0x8009E4C4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8009E480;
    }
    // 0x8009E4C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009E4C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009E4CC: addiu       $t0, $t0, 0x6A82
    ctx->r8 = ADD32(ctx->r8, 0X6A82);
L_8009E4D0:
    // 0x8009E4D0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8009E4D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E4D8: andi        $t3, $t2, 0xC000
    ctx->r11 = ctx->r10 & 0XC000;
    // 0x8009E4DC: beq         $t3, $zero, L_8009E4E8
    if (ctx->r11 == 0) {
        // 0x8009E4E0: nop
    
            goto L_8009E4E8;
    }
    // 0x8009E4E0: nop

    // 0x8009E4E4: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_8009E4E8:
    // 0x8009E4E8: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E4EC: b           L_8009E8C4
    // 0x8009E4F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E8C4;
    // 0x8009E4F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E4F4:
    // 0x8009E4F4: andi        $t4, $a0, 0xC000
    ctx->r12 = ctx->r4 & 0XC000;
    // 0x8009E4F8: beq         $t4, $zero, L_8009E8C0
    if (ctx->r12 == 0) {
        // 0x8009E4FC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8009E8C0;
    }
    // 0x8009E4FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009E500: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8009E504: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009E508: sb          $zero, 0x23A8($at)
    MEM_B(0X23A8, ctx->r1) = 0;
    // 0x8009E50C: jal         0x8009C9EC
    // 0x8009E510: addiu       $a0, $a0, 0x23AC
    ctx->r4 = ADD32(ctx->r4, 0X23AC);
    menu_assetgroup_free(rdram, ctx);
        goto after_30;
    // 0x8009E510: addiu       $a0, $a0, 0x23AC
    ctx->r4 = ADD32(ctx->r4, 0X23AC);
    after_30:
    // 0x8009E514: addiu       $a0, $zero, 0x22F
    ctx->r4 = ADD32(0, 0X22F);
    // 0x8009E518: jal         0x80036C0C
    // 0x8009E51C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_31;
    // 0x8009E51C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x8009E520: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E524: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E528: b           L_8009E8C4
    // 0x8009E52C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E8C4;
    // 0x8009E52C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E530:
    // 0x8009E530: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009E534: lw          $v0, -0x5E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E0);
    // 0x8009E538: addiu       $v1, $zero, 0xD0
    ctx->r3 = ADD32(0, 0XD0);
    // 0x8009E53C: lw          $t6, 0xD0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD0);
    // 0x8009E540: nop

    // 0x8009E544: beq         $t6, $zero, L_8009E5AC
    if (ctx->r14 == 0) {
        // 0x8009E548: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_8009E5AC;
    }
    // 0x8009E548: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8009E54C: lw          $a3, 0xD0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XD0);
    // 0x8009E550: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8009E554: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8009E558:
    // 0x8009E558: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8009E55C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009E560: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009E564: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E568: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E56C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8009E570: jal         0x800C56C8
    // 0x8009E574: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    render_dialogue_text(rdram, ctx);
        goto after_32;
    // 0x8009E574: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_32:
    // 0x8009E578: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009E57C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009E580: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x8009E584: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009E588: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009E58C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8009E590: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8009E594: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8009E598: bne         $a3, $zero, L_8009E558
    if (ctx->r7 != 0) {
        // 0x8009E59C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8009E558;
    }
    // 0x8009E59C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009E5A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009E5A4: addiu       $t0, $t0, 0x6A82
    ctx->r8 = ADD32(ctx->r8, 0X6A82);
    // 0x8009E5A8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
L_8009E5AC:
    // 0x8009E5AC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8009E5B0: andi        $t2, $t1, 0xC000
    ctx->r10 = ctx->r9 & 0XC000;
    // 0x8009E5B4: beq         $t2, $zero, L_8009E5D0
    if (ctx->r10 == 0) {
        // 0x8009E5B8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009E5D0;
    }
    // 0x8009E5B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E5BC: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8009E5C0: nop

    // 0x8009E5C4: ori         $t6, $t4, 0x2
    ctx->r14 = ctx->r12 | 0X2;
    // 0x8009E5C8: sw          $t6, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r14;
    // 0x8009E5CC: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
L_8009E5D0:
    // 0x8009E5D0: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E5D4: b           L_8009E8C4
    // 0x8009E5D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E8C4;
    // 0x8009E5D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E5DC:
    // 0x8009E5DC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009E5E0: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009E5E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009E5E8: lw          $a3, 0x27C($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X27C);
    // 0x8009E5EC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009E5F0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009E5F4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009E5F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E5FC: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E600: jal         0x800C56C8
    // 0x8009E604: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    render_dialogue_text(rdram, ctx);
        goto after_33;
    // 0x8009E604: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_33:
    // 0x8009E608: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009E60C: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8009E610: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009E614: lw          $a3, 0x280($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X280);
    // 0x8009E618: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009E61C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009E620: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009E624: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E628: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E62C: jal         0x800C56C8
    // 0x8009E630: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_34;
    // 0x8009E630: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_34:
    // 0x8009E634: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009E638: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009E63C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009E640: lw          $a3, 0x284($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X284);
    // 0x8009E644: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8009E648: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8009E64C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009E650: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E654: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E658: jal         0x800C56C8
    // 0x8009E65C: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    render_dialogue_text(rdram, ctx);
        goto after_35;
    // 0x8009E65C: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    after_35:
    // 0x8009E660: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8009E664: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009E668: andi        $t7, $t5, 0x9000
    ctx->r15 = ctx->r13 & 0X9000;
    // 0x8009E66C: beq         $t7, $zero, L_8009E6A8
    if (ctx->r15 == 0) {
        // 0x8009E670: lw          $t1, 0x40($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X40);
            goto L_8009E6A8;
    }
    // 0x8009E670: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8009E674: jal         0x80001D04
    // 0x8009E678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_36;
    // 0x8009E678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_36:
    // 0x8009E67C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E680: addiu       $a0, $a0, 0x6938
    ctx->r4 = ADD32(ctx->r4, 0X6938);
    // 0x8009E684: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8009E688: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8009E68C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E690: sw          $t8, 0x6940($at)
    MEM_W(0X6940, ctx->r1) = ctx->r24;
    // 0x8009E694: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E698: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8009E69C: b           L_8009E6C8
    // 0x8009E6A0: sb          $t9, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r25;
        goto L_8009E6C8;
    // 0x8009E6A0: sb          $t9, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r25;
    // 0x8009E6A4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
L_8009E6A8:
    // 0x8009E6A8: nop

    // 0x8009E6AC: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x8009E6B0: beq         $t2, $zero, L_8009E6C8
    if (ctx->r10 == 0) {
        // 0x8009E6B4: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8009E6C8;
    }
    // 0x8009E6B4: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009E6B8: jal         0x80001D04
    // 0x8009E6BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_37;
    // 0x8009E6BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x8009E6C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E6C4: sb          $zero, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = 0;
L_8009E6C8:
    // 0x8009E6C8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E6CC: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E6D0: b           L_8009E8C4
    // 0x8009E6D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E8C4;
    // 0x8009E6D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E6D8:
    // 0x8009E6D8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009E6DC: lw          $t4, -0x5E0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5E0);
    // 0x8009E6E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009E6E4: lw          $a3, 0x288($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X288);
    // 0x8009E6E8: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8009E6EC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8009E6F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009E6F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E6F8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E6FC: jal         0x800C56C8
    // 0x8009E700: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    render_dialogue_text(rdram, ctx);
        goto after_38;
    // 0x8009E700: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_38:
    // 0x8009E704: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8009E708: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8009E70C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009E710: lw          $a3, 0x2E8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X2E8);
    // 0x8009E714: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8009E718: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009E71C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009E720: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E724: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E728: jal         0x800C56C8
    // 0x8009E72C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_39;
    // 0x8009E72C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_39:
    // 0x8009E730: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009E734: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8009E738: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009E73C: lw          $a3, 0x2EC($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X2EC);
    // 0x8009E740: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8009E744: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009E748: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009E74C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E750: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E754: jal         0x800C56C8
    // 0x8009E758: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    render_dialogue_text(rdram, ctx);
        goto after_40;
    // 0x8009E758: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    after_40:
    // 0x8009E75C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8009E760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E764: andi        $t6, $t4, 0xD000
    ctx->r14 = ctx->r12 & 0XD000;
    // 0x8009E768: beq         $t6, $zero, L_8009E774
    if (ctx->r14 == 0) {
        // 0x8009E76C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009E774;
    }
    // 0x8009E76C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E770: sb          $zero, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = 0;
L_8009E774:
    // 0x8009E774: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E778: b           L_8009E8C4
    // 0x8009E77C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_8009E8C4;
    // 0x8009E77C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E780:
    // 0x8009E780: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009E784: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x8009E788: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009E78C: lw          $a3, 0x1F0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X1F0);
    // 0x8009E790: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8009E794: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009E798: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8009E79C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E7A0: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E7A4: jal         0x800C56C8
    // 0x8009E7A8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    render_dialogue_text(rdram, ctx);
        goto after_41;
    // 0x8009E7A8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_41:
    // 0x8009E7AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009E7B0: addiu       $a0, $a0, 0x6938
    ctx->r4 = ADD32(ctx->r4, 0X6938);
    // 0x8009E7B4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8009E7B8: nop

    // 0x8009E7BC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8009E7C0: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x8009E7C4: bne         $at, $zero, L_8009E8B4
    if (ctx->r1 != 0) {
        // 0x8009E7C8: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_8009E8B4;
    }
    // 0x8009E7C8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009E7CC: jal         0x8001B76C
    // 0x8009E7D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_save_player_ghost(rdram, ctx);
        goto after_42;
    // 0x8009E7D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_42:
    // 0x8009E7D4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8009E7D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8009E7DC: bne         $v1, $at, L_8009E7F4
    if (ctx->r3 != ctx->r1) {
        // 0x8009E7E0: sltiu       $at, $v1, 0xA
        ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
            goto L_8009E7F4;
    }
    // 0x8009E7E0: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
    // 0x8009E7E4: jal         0x8001B76C
    // 0x8009E7E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_save_player_ghost(rdram, ctx);
        goto after_43;
    // 0x8009E7E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_43:
    // 0x8009E7EC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8009E7F0: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
L_8009E7F4:
    // 0x8009E7F4: beq         $at, $zero, L_8009E898
    if (ctx->r1 == 0) {
        // 0x8009E7F8: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_8009E898;
    }
    // 0x8009E7F8: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8009E7FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009E800: addu        $at, $at, $t2
    gpr jr_addend_8009E80C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8009E804: lw          $t2, -0x7464($at)
    ctx->r10 = ADD32(ctx->r1, -0X7464);
    // 0x8009E808: nop

    // 0x8009E80C: jr          $t2
    // 0x8009E810: nop

    switch (jr_addend_8009E80C >> 2) {
        case 0: goto L_8009E814; break;
        case 1: goto L_8009E838; break;
        case 2: goto L_8009E898; break;
        case 3: goto L_8009E898; break;
        case 4: goto L_8009E858; break;
        case 5: goto L_8009E898; break;
        case 6: goto L_8009E858; break;
        case 7: goto L_8009E828; break;
        case 8: goto L_8009E898; break;
        case 9: goto L_8009E878; break;
        default: switch_error(__func__, 0x8009E80C, 0x800E8B9C);
    }
    // 0x8009E810: nop

L_8009E814:
    // 0x8009E814: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009E818: lw          $t4, 0x6940($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6940);
    // 0x8009E81C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E820: b           L_8009E8B4
    // 0x8009E824: sb          $t4, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r12;
        goto L_8009E8B4;
    // 0x8009E824: sb          $t4, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r12;
L_8009E828:
    // 0x8009E828: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8009E82C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E830: b           L_8009E8B4
    // 0x8009E834: sb          $t6, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r14;
        goto L_8009E8B4;
    // 0x8009E834: sb          $t6, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r14;
L_8009E838:
    // 0x8009E838: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009E83C: addiu       $t3, $t3, 0xF58
    ctx->r11 = ADD32(ctx->r11, 0XF58);
    // 0x8009E840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E844: sw          $t3, 0x6948($at)
    MEM_W(0X6948, ctx->r1) = ctx->r11;
    // 0x8009E848: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E84C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8009E850: b           L_8009E8B4
    // 0x8009E854: sb          $t5, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r13;
        goto L_8009E8B4;
    // 0x8009E854: sb          $t5, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r13;
L_8009E858:
    // 0x8009E858: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009E85C: addiu       $t7, $t7, 0xF44
    ctx->r15 = ADD32(ctx->r15, 0XF44);
    // 0x8009E860: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E864: sw          $t7, 0x6948($at)
    MEM_W(0X6948, ctx->r1) = ctx->r15;
    // 0x8009E868: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E86C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8009E870: b           L_8009E8B4
    // 0x8009E874: sb          $t8, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r24;
        goto L_8009E8B4;
    // 0x8009E874: sb          $t8, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r24;
L_8009E878:
    // 0x8009E878: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009E87C: addiu       $t9, $t9, 0xF6C
    ctx->r25 = ADD32(ctx->r25, 0XF6C);
    // 0x8009E880: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E884: sw          $t9, 0x6948($at)
    MEM_W(0X6948, ctx->r1) = ctx->r25;
    // 0x8009E888: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E88C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009E890: b           L_8009E8B4
    // 0x8009E894: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
        goto L_8009E8B4;
    // 0x8009E894: sb          $t1, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r9;
L_8009E898:
    // 0x8009E898: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8009E89C: addiu       $t2, $t2, 0xF30
    ctx->r10 = ADD32(ctx->r10, 0XF30);
    // 0x8009E8A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E8A4: sw          $t2, 0x6948($at)
    MEM_W(0X6948, ctx->r1) = ctx->r10;
    // 0x8009E8A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009E8AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009E8B0: sb          $t4, 0x6A82($at)
    MEM_B(0X6A82, ctx->r1) = ctx->r12;
L_8009E8B4:
    // 0x8009E8B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E8B8: lb          $v1, 0x6A82($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6A82);
    // 0x8009E8BC: nop

L_8009E8C0:
    // 0x8009E8C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8009E8C4:
    // 0x8009E8C4: beq         $v1, $at, L_8009E8DC
    if (ctx->r3 == ctx->r1) {
        // 0x8009E8C8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8009E8DC;
    }
    // 0x8009E8C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009E8CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009E8D0: beq         $v1, $at, L_8009E8DC
    if (ctx->r3 == ctx->r1) {
        // 0x8009E8D4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8009E8DC;
    }
    // 0x8009E8D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009E8D8: bne         $v1, $at, L_8009E904
    if (ctx->r3 != ctx->r1) {
        // 0x8009E8DC: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_8009E904;
    }
L_8009E8DC:
    // 0x8009E8DC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009E8E0: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8009E8E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8009E8E8: lw          $a3, 0x100($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X100);
    // 0x8009E8EC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8009E8F0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8009E8F4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009E8F8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009E8FC: jal         0x800C56C8
    // 0x8009E900: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    render_dialogue_text(rdram, ctx);
        goto after_44;
    // 0x8009E900: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_44:
L_8009E904:
    // 0x8009E904: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E908: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8009E90C: jr          $ra
    // 0x8009E910: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8009E910: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alLoadParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBAA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CBAA4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CBAA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBAAC: beq         $a1, $at, L_800CBC04
    if (ctx->r5 == ctx->r1) {
        // 0x800CBAB0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800CBC04;
    }
    // 0x800CBAB0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CBAB4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800CBAB8: bnel        $a1, $at, L_800CBC68
    if (ctx->r5 != ctx->r1) {
        // 0x800CBABC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CBC68;
    }
    goto skip_0;
    // 0x800CBABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CBAC0: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x800CBAC4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800CBAC8: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x800CBACC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CBAD0: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x800CBAD4: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x800CBAD8: beql        $v0, $zero, L_800CBAF8
    if (ctx->r2 == 0) {
        // 0x800CBADC: lw          $v0, 0x28($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X28);
            goto L_800CBAF8;
    }
    goto skip_1;
    // 0x800CBADC: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    skip_1:
    // 0x800CBAE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CBAE4: beq         $v0, $a0, L_800CBBB8
    if (ctx->r2 == ctx->r4) {
        // 0x800CBAE8: lui         $t0, 0x800D
        ctx->r8 = S32(0X800D << 16);
            goto L_800CBBB8;
    }
    // 0x800CBAE8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CBAEC: b           L_800CBC68
    // 0x800CBAF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CBC68;
    // 0x800CBAF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBAF4: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
L_800CBAF8:
    // 0x800CBAF8: addiu       $t7, $t7, -0x3EB4
    ctx->r15 = ADD32(ctx->r15, -0X3EB4);
    // 0x800CBAFC: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800CBB00: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800CBB04: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CBB08: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x800CBB0C: mflo        $t9
    ctx->r25 = lo;
    // 0x800CBB10: bne         $a1, $zero, L_800CBB1C
    if (ctx->r5 != 0) {
        // 0x800CBB14: nop
    
            goto L_800CBB1C;
    }
    // 0x800CBB14: nop

    // 0x800CBB18: break       7
    do_break(2148317976);
L_800CBB1C:
    // 0x800CBB1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CBB20: bne         $a1, $at, L_800CBB34
    if (ctx->r5 != ctx->r1) {
        // 0x800CBB24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CBB34;
    }
    // 0x800CBB24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CBB28: bne         $t8, $at, L_800CBB34
    if (ctx->r24 != ctx->r1) {
        // 0x800CBB2C: nop
    
            goto L_800CBB34;
    }
    // 0x800CBB2C: nop

    // 0x800CBB30: break       6
    do_break(2148318000);
L_800CBB34:
    // 0x800CBB34: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CBB38: mflo        $t0
    ctx->r8 = lo;
    // 0x800CBB3C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800CBB40: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800CBB44: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800CBB48: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800CBB4C: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x800CBB50: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800CBB54: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CBB58: mflo        $t4
    ctx->r12 = lo;
    // 0x800CBB5C: sw          $t4, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r12;
    // 0x800CBB60: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CBB64: beql        $v1, $zero, L_800CBBAC
    if (ctx->r3 == 0) {
        // 0x800CBB68: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800CBBAC;
    }
    goto skip_2;
    // 0x800CBB68: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_2:
    // 0x800CBB6C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800CBB70: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    // 0x800CBB74: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800CBB78: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
    // 0x800CBB7C: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800CBB80: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800CBB84: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x800CBB88: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800CBB8C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800CBB90: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
    // 0x800CBB94: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800CBB98: jal         0x800D3D80
    // 0x800CBB9C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    alCopy(rdram, ctx);
        goto after_0;
    // 0x800CBB9C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800CBBA0: b           L_800CBC68
    // 0x800CBBA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CBC68;
    // 0x800CBBA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBBA8: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800CBBAC:
    // 0x800CBBAC: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800CBBB0: b           L_800CBC64
    // 0x800CBBB4: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800CBC64;
    // 0x800CBBB4: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800CBBB8:
    // 0x800CBBB8: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800CBBBC: addiu       $t0, $t0, -0x438C
    ctx->r8 = ADD32(ctx->r8, -0X438C);
    // 0x800CBBC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x800CBBC4: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CBBC8: beql        $v1, $zero, L_800CBBF8
    if (ctx->r3 == 0) {
        // 0x800CBBCC: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800CBBF8;
    }
    goto skip_3;
    // 0x800CBBCC: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_3:
    // 0x800CBBD0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800CBBD4: sw          $t1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r9;
    // 0x800CBBD8: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800CBBDC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800CBBE0: sw          $t3, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r11;
    // 0x800CBBE4: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800CBBE8: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800CBBEC: b           L_800CBC64
    // 0x800CBBF0: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
        goto L_800CBC64;
    // 0x800CBBF0: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
    // 0x800CBBF4: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800CBBF8:
    // 0x800CBBF8: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800CBBFC: b           L_800CBC64
    // 0x800CBC00: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800CBC64;
    // 0x800CBC00: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800CBC04:
    // 0x800CBC04: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800CBC08: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CBC0C: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x800CBC10: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x800CBC14: beq         $v0, $zero, L_800CBC64
    if (ctx->r2 == 0) {
        // 0x800CBC18: sw          $zero, 0x38($a3)
        MEM_W(0X38, ctx->r7) = 0;
            goto L_800CBC64;
    }
    // 0x800CBC18: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800CBC1C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800CBC20: sw          $t6, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r14;
    // 0x800CBC24: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x800CBC28: bne         $v1, $zero, L_800CBC48
    if (ctx->r3 != 0) {
        // 0x800CBC2C: nop
    
            goto L_800CBC48;
    }
    // 0x800CBC2C: nop

    // 0x800CBC30: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CBC34: beql        $v1, $zero, L_800CBC68
    if (ctx->r3 == 0) {
        // 0x800CBC38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CBC68;
    }
    goto skip_4;
    // 0x800CBC38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800CBC3C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800CBC40: b           L_800CBC64
    // 0x800CBC44: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
        goto L_800CBC64;
    // 0x800CBC44: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
L_800CBC48:
    // 0x800CBC48: bnel        $a0, $v1, L_800CBC68
    if (ctx->r4 != ctx->r3) {
        // 0x800CBC4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CBC68;
    }
    goto skip_5;
    // 0x800CBC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800CBC50: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CBC54: beql        $v1, $zero, L_800CBC68
    if (ctx->r3 == 0) {
        // 0x800CBC58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CBC68;
    }
    goto skip_6;
    // 0x800CBC58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x800CBC5C: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800CBC60: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
L_800CBC64:
    // 0x800CBC64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CBC68:
    // 0x800CBC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CBC6C: jr          $ra
    // 0x800CBC70: nop

    return;
    // 0x800CBC70: nop

;}
RECOMP_FUNC void transition_init_circle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1AF4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C1AF8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C1AFC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C1B00: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x800C1B04: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800C1B08: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800C1B0C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800C1B10: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800C1B14: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C1B18: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C1B1C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800C1B20: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C1B24: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C1B28: jal         0x80070EDC
    // 0x800C1B2C: addiu       $a0, $zero, 0xDA0
    ctx->r4 = ADD32(0, 0XDA0);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C1B2C: addiu       $a0, $zero, 0xDA0
    ctx->r4 = ADD32(0, 0XDA0);
    after_0:
    // 0x800C1B30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C1B34: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C1B38: addiu       $t7, $v0, 0x2D0
    ctx->r15 = ADD32(ctx->r2, 0X2D0);
    // 0x800C1B3C: addiu       $a1, $a1, 0x3758
    ctx->r5 = ADD32(ctx->r5, 0X3758);
    // 0x800C1B40: addiu       $a0, $a0, 0x3750
    ctx->r4 = ADD32(ctx->r4, 0X3750);
    // 0x800C1B44: addiu       $t9, $t7, 0x2D0
    ctx->r25 = ADD32(ctx->r15, 0X2D0);
    // 0x800C1B48: addiu       $t5, $t9, 0x400
    ctx->r13 = ADD32(ctx->r25, 0X400);
    // 0x800C1B4C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C1B50: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800C1B54: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800C1B58: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x800C1B5C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C1B60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C1B64: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1B68: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C1B6C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C1B70: addiu       $a2, $a2, -0x530A
    ctx->r6 = ADD32(ctx->r6, -0X530A);
    // 0x800C1B74: addiu       $t2, $t2, 0x3758
    ctx->r10 = ADD32(ctx->r10, 0X3758);
    // 0x800C1B78: addiu       $v1, $v1, 0x3750
    ctx->r3 = ADD32(ctx->r3, 0X3750);
    // 0x800C1B7C: addiu       $a0, $a0, -0x530C
    ctx->r4 = ADD32(ctx->r4, -0X530C);
    // 0x800C1B80: addiu       $a1, $a1, -0x530B
    ctx->r5 = ADD32(ctx->r5, -0X530B);
    // 0x800C1B84: addiu       $t1, $zero, 0x2D0
    ctx->r9 = ADD32(0, 0X2D0);
    // 0x800C1B88: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800C1B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C1B90:
    // 0x800C1B90: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1B94: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1B98: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1B9C: sb          $t6, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r14;
    // 0x800C1BA0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BA4: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800C1BA8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1BAC: sb          $t9, 0x7($t5)
    MEM_B(0X7, ctx->r13) = ctx->r25;
    // 0x800C1BB0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BB4: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1BB8: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1BBC: sb          $t7, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r15;
    // 0x800C1BC0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BC4: nop

    // 0x800C1BC8: addu        $t9, $t4, $v0
    ctx->r25 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1BCC: sb          $t0, 0x9($t9)
    MEM_B(0X9, ctx->r25) = ctx->r8;
    // 0x800C1BD0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BD4: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1BD8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1BDC: sb          $t5, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r13;
    // 0x800C1BE0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BE4: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800C1BE8: addu        $t9, $t4, $v0
    ctx->r25 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1BEC: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800C1BF0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1BF4: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1BF8: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800C1BFC: sb          $t6, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r14;
    // 0x800C1C00: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C04: nop

    // 0x800C1C08: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C0C: sb          $t0, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r8;
    // 0x800C1C10: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C14: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1C18: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C1C1C: sb          $t9, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r25;
    // 0x800C1C20: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C24: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800C1C28: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C2C: sb          $t7, 0x1B($t8)
    MEM_B(0X1B, ctx->r24) = ctx->r15;
    // 0x800C1C30: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C34: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1C38: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1C3C: sb          $t5, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r13;
    // 0x800C1C40: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C44: nop

    // 0x800C1C48: addu        $t7, $t4, $v0
    ctx->r15 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C4C: sb          $t0, 0x1D($t7)
    MEM_B(0X1D, ctx->r15) = ctx->r8;
    // 0x800C1C50: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C54: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1C58: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1C5C: sb          $t8, 0x24($t5)
    MEM_B(0X24, ctx->r13) = ctx->r24;
    // 0x800C1C60: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C64: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800C1C68: addu        $t7, $t4, $v0
    ctx->r15 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C6C: sb          $t6, 0x25($t7)
    MEM_B(0X25, ctx->r15) = ctx->r14;
    // 0x800C1C70: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C74: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1C78: addu        $t5, $t8, $v0
    ctx->r13 = ADD32(ctx->r24, ctx->r2);
    // 0x800C1C7C: sb          $t9, 0x26($t5)
    MEM_B(0X26, ctx->r13) = ctx->r25;
    // 0x800C1C80: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1C84: nop

    // 0x800C1C88: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1C8C: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800C1C90: bne         $v0, $t1, L_800C1B90
    if (ctx->r2 != ctx->r9) {
        // 0x800C1C94: sb          $t0, 0x27($t6)
        MEM_B(0X27, ctx->r14) = ctx->r8;
            goto L_800C1B90;
    }
    // 0x800C1C94: sb          $t0, 0x27($t6)
    MEM_B(0X27, ctx->r14) = ctx->r8;
    // 0x800C1C98: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C1C9C: sltu        $at, $v1, $t2
    ctx->r1 = ctx->r3 < ctx->r10 ? 1 : 0;
    // 0x800C1CA0: bne         $at, $zero, L_800C1B90
    if (ctx->r1 != 0) {
        // 0x800C1CA4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C1B90;
    }
    // 0x800C1CA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1CA8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1CAC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C1CB0: addiu       $t2, $t2, 0x3758
    ctx->r10 = ADD32(ctx->r10, 0X3758);
    // 0x800C1CB4: addiu       $v1, $v1, 0x3750
    ctx->r3 = ADD32(ctx->r3, 0X3750);
    // 0x800C1CB8: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x800C1CBC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_800C1CC0:
    // 0x800C1CC0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1CC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C1CC8: sb          $zero, 0xC7($t7)
    MEM_B(0XC7, ctx->r15) = 0;
    // 0x800C1CCC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C1CD0: nop

    // 0x800C1CD4: sb          $zero, 0x22F($t8)
    MEM_B(0X22F, ctx->r24) = 0;
L_800C1CD8:
    // 0x800C1CD8: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x800C1CDC: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C1CE0: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C1CE4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C1CE8: addiu       $t8, $a3, 0x2
    ctx->r24 = ADD32(ctx->r7, 0X2);
    // 0x800C1CEC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1CF0: mflo        $v0
    ctx->r2 = lo;
    // 0x800C1CF4: addu        $t4, $t5, $v0
    ctx->r12 = ADD32(ctx->r13, ctx->r2);
    // 0x800C1CF8: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C1CFC: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C1D00: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C1D04: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D08: addiu       $t8, $a3, 0x3
    ctx->r24 = ADD32(ctx->r7, 0X3);
    // 0x800C1D0C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1D10: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C1D14: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D18: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800C1D1C: mflo        $a0
    ctx->r4 = lo;
    // 0x800C1D20: addu        $t4, $t5, $a0
    ctx->r12 = ADD32(ctx->r13, ctx->r4);
    // 0x800C1D24: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C1D28: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C1D2C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D30: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C1D34: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800C1D38: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C1D3C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D40: mflo        $a1
    ctx->r5 = lo;
    // 0x800C1D44: addu        $t4, $t5, $a1
    ctx->r12 = ADD32(ctx->r13, ctx->r5);
    // 0x800C1D48: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C1D4C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C1D50: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D54: nop

    // 0x800C1D58: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800C1D5C: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C1D60: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D64: mflo        $a2
    ctx->r6 = lo;
    // 0x800C1D68: addu        $t4, $t5, $a2
    ctx->r12 = ADD32(ctx->r13, ctx->r6);
    // 0x800C1D6C: sb          $zero, 0xC7($t4)
    MEM_B(0XC7, ctx->r12) = 0;
    // 0x800C1D70: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1D74: nop

    // 0x800C1D78: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800C1D7C: bne         $a3, $t1, L_800C1CD8
    if (ctx->r7 != ctx->r9) {
        // 0x800C1D80: sb          $zero, 0x22F($t7)
        MEM_B(0X22F, ctx->r15) = 0;
            goto L_800C1CD8;
    }
    // 0x800C1D80: sb          $zero, 0x22F($t7)
    MEM_B(0X22F, ctx->r15) = 0;
    // 0x800C1D84: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C1D88: sltu        $at, $v1, $t2
    ctx->r1 = ctx->r3 < ctx->r10 ? 1 : 0;
    // 0x800C1D8C: bne         $at, $zero, L_800C1CC0
    if (ctx->r1 != 0) {
        // 0x800C1D90: nop
    
            goto L_800C1CC0;
    }
    // 0x800C1D90: nop

    // 0x800C1D94: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800C1D98: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800C1D9C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800C1DA0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800C1DA4: addiu       $s2, $s2, 0x3758
    ctx->r18 = ADD32(ctx->r18, 0X3758);
    // 0x800C1DA8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C1DAC: addiu       $s0, $zero, -0x10
    ctx->r16 = ADD32(0, -0X10);
L_800C1DB0:
    // 0x800C1DB0: sll         $s3, $s5, 16
    ctx->r19 = S32(ctx->r21 << 16);
    // 0x800C1DB4: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800C1DB8: sll         $a0, $t8, 16
    ctx->r4 = S32(ctx->r24 << 16);
    // 0x800C1DBC: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C1DC0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800C1DC4: jal         0x80070A04
    // 0x800C1DC8: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x800C1DC8: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    after_1:
    // 0x800C1DCC: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800C1DD0: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x800C1DD4: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C1DD8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800C1DDC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800C1DE0: nop

    // 0x800C1DE4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800C1DE8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1DEC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1DF0: nop

    // 0x800C1DF4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800C1DF8: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x800C1DFC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800C1E00: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x800C1E04: jal         0x80070A38
    // 0x800C1E08: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x800C1E08: sra         $s1, $t4, 16
    ctx->r17 = S32(SIGNED(ctx->r12) >> 16);
    after_2:
    // 0x800C1E0C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C1E10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C1E14: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x800C1E18: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C1E1C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800C1E20: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1E24: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C1E28: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C1E2C: addiu       $v0, $v0, 0x3750
    ctx->r2 = ADD32(ctx->r2, 0X3750);
    // 0x800C1E30: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800C1E34: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1E38: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1E3C: sll         $v1, $t8, 1
    ctx->r3 = S32(ctx->r24 << 1);
    // 0x800C1E40: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C1E44: negu        $a1, $s1
    ctx->r5 = SUB32(0, ctx->r17);
    // 0x800C1E48: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x800C1E4C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C1E50: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800C1E54: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
L_800C1E58:
    // 0x800C1E58: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C1E5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C1E60: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C1E64: sh          $s1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r17;
    // 0x800C1E68: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E6C: nop

    // 0x800C1E70: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1E74: sh          $a0, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r4;
    // 0x800C1E78: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E7C: nop

    // 0x800C1E80: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C1E84: sh          $s0, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r16;
    // 0x800C1E88: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E8C: nop

    // 0x800C1E90: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C1E94: sh          $s0, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r16;
    // 0x800C1E98: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C1E9C: nop

    // 0x800C1EA0: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1EA4: sh          $s0, 0xB8($t9)
    MEM_H(0XB8, ctx->r25) = ctx->r16;
    // 0x800C1EA8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C1EAC: nop

    // 0x800C1EB0: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C1EB4: sh          $s0, 0xC2($t4)
    MEM_H(0XC2, ctx->r12) = ctx->r16;
    // 0x800C1EB8: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800C1EBC: nop

    // 0x800C1EC0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C1EC4: sh          $a1, 0x168($t7)
    MEM_H(0X168, ctx->r15) = ctx->r5;
    // 0x800C1EC8: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C1ECC: nop

    // 0x800C1ED0: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1ED4: sh          $a0, 0x16A($t9)
    MEM_H(0X16A, ctx->r25) = ctx->r4;
    // 0x800C1ED8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C1EDC: nop

    // 0x800C1EE0: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C1EE4: sh          $s0, 0x16C($t4)
    MEM_H(0X16C, ctx->r12) = ctx->r16;
    // 0x800C1EE8: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800C1EEC: nop

    // 0x800C1EF0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800C1EF4: sh          $s0, 0x176($t7)
    MEM_H(0X176, ctx->r15) = ctx->r16;
    // 0x800C1EF8: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x800C1EFC: nop

    // 0x800C1F00: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800C1F04: sh          $s0, 0x220($t9)
    MEM_H(0X220, ctx->r25) = ctx->r16;
    // 0x800C1F08: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800C1F0C: nop

    // 0x800C1F10: addu        $t4, $t5, $v1
    ctx->r12 = ADD32(ctx->r13, ctx->r3);
    // 0x800C1F14: bne         $v0, $s2, L_800C1E58
    if (ctx->r2 != ctx->r18) {
        // 0x800C1F18: sh          $s0, 0x22A($t4)
        MEM_H(0X22A, ctx->r12) = ctx->r16;
            goto L_800C1E58;
    }
    // 0x800C1F18: sh          $s0, 0x22A($t4)
    MEM_H(0X22A, ctx->r12) = ctx->r16;
    // 0x800C1F1C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C1F20: slti        $at, $s4, 0x9
    ctx->r1 = SIGNED(ctx->r20) < 0X9 ? 1 : 0;
    // 0x800C1F24: bne         $at, $zero, L_800C1DB0
    if (ctx->r1 != 0) {
        // 0x800C1F28: addiu       $s5, $s5, 0x1000
        ctx->r21 = ADD32(ctx->r21, 0X1000);
            goto L_800C1DB0;
    }
    // 0x800C1F28: addiu       $s5, $s5, 0x1000
    ctx->r21 = ADD32(ctx->r21, 0X1000);
    // 0x800C1F2C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800C1F30: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1F34: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800C1F38: addiu       $v1, $v1, 0x3758
    ctx->r3 = ADD32(ctx->r3, 0X3758);
    // 0x800C1F3C: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x800C1F40: beq         $t8, $zero, L_800C1FB8
    if (ctx->r24 == 0) {
        // 0x800C1F44: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_800C1FB8;
    }
    // 0x800C1F44: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C1F48: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C1F4C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C1F50: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C1F54: lhu         $t9, 0x3740($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X3740);
    // 0x800C1F58: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C1F5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1F60: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800C1F64: swc1        $f2, -0x52E8($at)
    MEM_W(-0X52E8, ctx->r1) = ctx->f2.u32l;
    // 0x800C1F68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1F6C: swc1        $f2, -0x52E4($at)
    MEM_W(-0X52E4, ctx->r1) = ctx->f2.u32l;
    // 0x800C1F70: bgez        $t9, L_800C1F88
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800C1F74: cvt.s.w     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800C1F88;
    }
    // 0x800C1F74: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C1F78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1F7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C1F80: nop

    // 0x800C1F84: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_800C1F88:
    // 0x800C1F88: nop

    // 0x800C1F8C: div.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800C1F90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1F94: div.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800C1F98: swc1        $f6, -0x52E0($at)
    MEM_W(-0X52E0, ctx->r1) = ctx->f6.u32l;
    // 0x800C1F9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1FA0: swc1        $f8, -0x52DC($at)
    MEM_W(-0X52DC, ctx->r1) = ctx->f8.u32l;
    // 0x800C1FA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1FA8: swc1        $f20, -0x52D8($at)
    MEM_W(-0X52D8, ctx->r1) = ctx->f20.u32l;
    // 0x800C1FAC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1FB0: b           L_800C202C
    // 0x800C1FB4: swc1        $f12, -0x52D4($at)
    MEM_W(-0X52D4, ctx->r1) = ctx->f12.u32l;
        goto L_800C202C;
    // 0x800C1FB4: swc1        $f12, -0x52D4($at)
    MEM_W(-0X52D4, ctx->r1) = ctx->f12.u32l;
L_800C1FB8:
    // 0x800C1FB8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C1FBC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C1FC0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C1FC4: lhu         $t5, 0x3740($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X3740);
    // 0x800C1FC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1FCC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800C1FD0: swc1        $f20, -0x52E8($at)
    MEM_W(-0X52E8, ctx->r1) = ctx->f20.u32l;
    // 0x800C1FD4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C1FD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1FDC: swc1        $f12, -0x52E4($at)
    MEM_W(-0X52E4, ctx->r1) = ctx->f12.u32l;
    // 0x800C1FE0: bgez        $t5, L_800C1FF8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C1FE4: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800C1FF8;
    }
    // 0x800C1FE4: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C1FE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1FEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C1FF0: nop

    // 0x800C1FF4: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
L_800C1FF8:
    // 0x800C1FF8: neg.s       $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = -ctx->f20.fl;
    // 0x800C1FFC: nop

    // 0x800C2000: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800C2004: neg.s       $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = -ctx->f12.fl;
    // 0x800C2008: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C200C: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C2010: swc1        $f4, -0x52E0($at)
    MEM_W(-0X52E0, ctx->r1) = ctx->f4.u32l;
    // 0x800C2014: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2018: swc1        $f8, -0x52DC($at)
    MEM_W(-0X52DC, ctx->r1) = ctx->f8.u32l;
    // 0x800C201C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2020: swc1        $f2, -0x52D8($at)
    MEM_W(-0X52D8, ctx->r1) = ctx->f2.u32l;
    // 0x800C2024: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2028: swc1        $f2, -0x52D4($at)
    MEM_W(-0X52D4, ctx->r1) = ctx->f2.u32l;
L_800C202C:
    // 0x800C202C: addiu       $a2, $a2, 0x3760
    ctx->r6 = ADD32(ctx->r6, 0X3760);
    // 0x800C2030: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x800C2034: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800C2038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C203C:
    // 0x800C203C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2040: nop

    // 0x800C2044: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2048: sb          $a0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r4;
    // 0x800C204C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C2050: nop

    // 0x800C2054: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2058: sh          $zero, 0x4($t8)
    MEM_H(0X4, ctx->r24) = 0;
    // 0x800C205C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C2060: nop

    // 0x800C2064: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C2068: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x800C206C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2070: nop

    // 0x800C2074: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2078: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x800C207C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C2080: nop

    // 0x800C2084: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2088: sh          $zero, 0xA($t8)
    MEM_H(0XA, ctx->r24) = 0;
    // 0x800C208C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C2090: nop

    // 0x800C2094: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C2098: sh          $zero, 0xC($t5)
    MEM_H(0XC, ctx->r13) = 0;
    // 0x800C209C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C20A0: nop

    // 0x800C20A4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C20A8: sh          $zero, 0xE($t6)
    MEM_H(0XE, ctx->r14) = 0;
    // 0x800C20AC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C20B0: nop

    // 0x800C20B4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C20B8: sb          $a0, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r4;
    // 0x800C20BC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C20C0: nop

    // 0x800C20C4: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C20C8: sh          $zero, 0x14($t5)
    MEM_H(0X14, ctx->r13) = 0;
    // 0x800C20CC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C20D0: nop

    // 0x800C20D4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C20D8: sh          $zero, 0x16($t6)
    MEM_H(0X16, ctx->r14) = 0;
    // 0x800C20DC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C20E0: nop

    // 0x800C20E4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C20E8: sh          $zero, 0x18($t8)
    MEM_H(0X18, ctx->r24) = 0;
    // 0x800C20EC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C20F0: nop

    // 0x800C20F4: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C20F8: sh          $zero, 0x1A($t5)
    MEM_H(0X1A, ctx->r13) = 0;
    // 0x800C20FC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2100: nop

    // 0x800C2104: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2108: sh          $zero, 0x1C($t6)
    MEM_H(0X1C, ctx->r14) = 0;
    // 0x800C210C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C2110: nop

    // 0x800C2114: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2118: sh          $zero, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = 0;
    // 0x800C211C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C2120: nop

    // 0x800C2124: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C2128: sb          $a0, 0x20($t5)
    MEM_B(0X20, ctx->r13) = ctx->r4;
    // 0x800C212C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2130: nop

    // 0x800C2134: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2138: sh          $zero, 0x24($t6)
    MEM_H(0X24, ctx->r14) = 0;
    // 0x800C213C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C2140: nop

    // 0x800C2144: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2148: sh          $zero, 0x26($t8)
    MEM_H(0X26, ctx->r24) = 0;
    // 0x800C214C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C2150: nop

    // 0x800C2154: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C2158: sh          $zero, 0x28($t5)
    MEM_H(0X28, ctx->r13) = 0;
    // 0x800C215C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2160: nop

    // 0x800C2164: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2168: sh          $zero, 0x2A($t6)
    MEM_H(0X2A, ctx->r14) = 0;
    // 0x800C216C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C2170: nop

    // 0x800C2174: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C2178: sh          $zero, 0x2C($t8)
    MEM_H(0X2C, ctx->r24) = 0;
    // 0x800C217C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C2180: nop

    // 0x800C2184: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C2188: sh          $zero, 0x2E($t5)
    MEM_H(0X2E, ctx->r13) = 0;
    // 0x800C218C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C2190: nop

    // 0x800C2194: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C2198: sb          $a0, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r4;
    // 0x800C219C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C21A0: nop

    // 0x800C21A4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C21A8: sh          $zero, 0x34($t8)
    MEM_H(0X34, ctx->r24) = 0;
    // 0x800C21AC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C21B0: nop

    // 0x800C21B4: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C21B8: sh          $zero, 0x36($t5)
    MEM_H(0X36, ctx->r13) = 0;
    // 0x800C21BC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C21C0: nop

    // 0x800C21C4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C21C8: sh          $zero, 0x38($t6)
    MEM_H(0X38, ctx->r14) = 0;
    // 0x800C21CC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C21D0: nop

    // 0x800C21D4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C21D8: sh          $zero, 0x3A($t8)
    MEM_H(0X3A, ctx->r24) = 0;
    // 0x800C21DC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C21E0: nop

    // 0x800C21E4: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C21E8: sh          $zero, 0x3C($t5)
    MEM_H(0X3C, ctx->r13) = 0;
    // 0x800C21EC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C21F0: nop

    // 0x800C21F4: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C21F8: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800C21FC: bne         $v0, $a1, L_800C203C
    if (ctx->r2 != ctx->r5) {
        // 0x800C2200: sh          $zero, 0x3E($t6)
        MEM_H(0X3E, ctx->r14) = 0;
            goto L_800C203C;
    }
    // 0x800C2200: sh          $zero, 0x3E($t6)
    MEM_H(0X3E, ctx->r14) = 0;
    // 0x800C2204: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C2208: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x800C220C: bne         $at, $zero, L_800C203C
    if (ctx->r1 != 0) {
        // 0x800C2210: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C203C;
    }
    // 0x800C2210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C2214: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C2218: addiu       $t2, $t2, 0x3760
    ctx->r10 = ADD32(ctx->r10, 0X3760);
    // 0x800C221C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C2220: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800C2224: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
L_800C2228:
    // 0x800C2228: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C222C: addiu       $v0, $v0, 0x3758
    ctx->r2 = ADD32(ctx->r2, 0X3758);
    // 0x800C2230: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800C2234: addiu       $a2, $a0, 0x1
    ctx->r6 = ADD32(ctx->r4, 0X1);
    // 0x800C2238: addiu       $a1, $a0, 0x3
    ctx->r5 = ADD32(ctx->r4, 0X3);
    // 0x800C223C: addiu       $t0, $a0, 0x2
    ctx->r8 = ADD32(ctx->r4, 0X2);
L_800C2240:
    // 0x800C2240: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800C2244: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C2248: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C224C: sb          $a0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r4;
    // 0x800C2250: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C2254: nop

    // 0x800C2258: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C225C: sb          $a2, 0x2($t5)
    MEM_B(0X2, ctx->r13) = ctx->r6;
    // 0x800C2260: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C2264: nop

    // 0x800C2268: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C226C: sb          $a1, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r5;
    // 0x800C2270: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C2274: nop

    // 0x800C2278: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C227C: sb          $a0, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r4;
    // 0x800C2280: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C2284: nop

    // 0x800C2288: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C228C: sb          $a1, 0x12($t5)
    MEM_B(0X12, ctx->r13) = ctx->r5;
    // 0x800C2290: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C2294: nop

    // 0x800C2298: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C229C: sb          $t0, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r8;
    // 0x800C22A0: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C22A4: nop

    // 0x800C22A8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C22AC: sb          $a0, 0x101($t8)
    MEM_B(0X101, ctx->r24) = ctx->r4;
    // 0x800C22B0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C22B4: nop

    // 0x800C22B8: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C22BC: sb          $a2, 0x102($t5)
    MEM_B(0X102, ctx->r13) = ctx->r6;
    // 0x800C22C0: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C22C4: nop

    // 0x800C22C8: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C22CC: sb          $a1, 0x103($t6)
    MEM_B(0X103, ctx->r14) = ctx->r5;
    // 0x800C22D0: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C22D4: nop

    // 0x800C22D8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C22DC: sb          $a0, 0x111($t8)
    MEM_B(0X111, ctx->r24) = ctx->r4;
    // 0x800C22E0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C22E4: nop

    // 0x800C22E8: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C22EC: sb          $a1, 0x112($t5)
    MEM_B(0X112, ctx->r13) = ctx->r5;
    // 0x800C22F0: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C22F4: nop

    // 0x800C22F8: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C22FC: sb          $t0, 0x113($t6)
    MEM_B(0X113, ctx->r14) = ctx->r8;
    // 0x800C2300: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C2304: nop

    // 0x800C2308: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C230C: sb          $a0, 0x201($t8)
    MEM_B(0X201, ctx->r24) = ctx->r4;
    // 0x800C2310: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C2314: nop

    // 0x800C2318: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C231C: sb          $a2, 0x202($t5)
    MEM_B(0X202, ctx->r13) = ctx->r6;
    // 0x800C2320: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C2324: nop

    // 0x800C2328: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C232C: sb          $a1, 0x203($t6)
    MEM_B(0X203, ctx->r14) = ctx->r5;
    // 0x800C2330: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C2334: nop

    // 0x800C2338: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C233C: sb          $a0, 0x211($t8)
    MEM_B(0X211, ctx->r24) = ctx->r4;
    // 0x800C2340: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C2344: nop

    // 0x800C2348: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C234C: sb          $a1, 0x212($t5)
    MEM_B(0X212, ctx->r13) = ctx->r5;
    // 0x800C2350: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C2354: nop

    // 0x800C2358: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C235C: sb          $t0, 0x213($t6)
    MEM_B(0X213, ctx->r14) = ctx->r8;
    // 0x800C2360: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C2364: nop

    // 0x800C2368: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C236C: sb          $a0, 0x301($t8)
    MEM_B(0X301, ctx->r24) = ctx->r4;
    // 0x800C2370: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C2374: nop

    // 0x800C2378: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C237C: sb          $a2, 0x302($t5)
    MEM_B(0X302, ctx->r13) = ctx->r6;
    // 0x800C2380: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C2384: nop

    // 0x800C2388: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C238C: sb          $a1, 0x303($t6)
    MEM_B(0X303, ctx->r14) = ctx->r5;
    // 0x800C2390: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800C2394: nop

    // 0x800C2398: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800C239C: sb          $a0, 0x311($t8)
    MEM_B(0X311, ctx->r24) = ctx->r4;
    // 0x800C23A0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800C23A4: nop

    // 0x800C23A8: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x800C23AC: sb          $a1, 0x312($t5)
    MEM_B(0X312, ctx->r13) = ctx->r5;
    // 0x800C23B0: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x800C23B4: nop

    // 0x800C23B8: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800C23BC: bne         $v0, $t2, L_800C2240
    if (ctx->r2 != ctx->r10) {
        // 0x800C23C0: sb          $t0, 0x313($t6)
        MEM_B(0X313, ctx->r14) = ctx->r8;
            goto L_800C2240;
    }
    // 0x800C23C0: sb          $t0, 0x313($t6)
    MEM_B(0X313, ctx->r14) = ctx->r8;
    // 0x800C23C4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C23C8: bne         $s4, $t3, L_800C2228
    if (ctx->r20 != ctx->r11) {
        // 0x800C23CC: sll         $a0, $s4, 1
        ctx->r4 = S32(ctx->r20 << 1);
            goto L_800C2228;
    }
    // 0x800C23CC: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
    // 0x800C23D0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C23D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C23D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C23DC: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800C23E0: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C23E4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C23E8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C23EC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800C23F0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800C23F4: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800C23F8: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800C23FC: sw          $t7, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r15;
    // 0x800C2400: jr          $ra
    // 0x800C2404: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C2404: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mark_to_write_flap_and_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE3C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EE40: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EE44: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EE48: nop

    // 0x8006EE4C: ori         $t7, $t6, 0x30
    ctx->r15 = ctx->r14 | 0X30;
    // 0x8006EE50: jr          $ra
    // 0x8006EE54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EE54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_800575EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005762C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80057630: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80057634: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80057638: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8005763C: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80057640: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80057644: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80057648: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005764C: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x80057650: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80057654: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80057658: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005765C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80057660: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80057664: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80057668: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8005766C: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x80057670: swc1        $f20, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f20.u32l;
    // 0x80057674: swc1        $f20, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f20.u32l;
    // 0x80057678: swc1        $f20, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f20.u32l;
    // 0x8005767C: jal         0x8006FE70
    // 0x80057680: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x80057680: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_0:
    // 0x80057684: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80057688: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8005768C: addiu       $t8, $s0, 0x38
    ctx->r24 = ADD32(ctx->r16, 0X38);
    // 0x80057690: addiu       $t9, $s0, 0x3C
    ctx->r25 = ADD32(ctx->r16, 0X3C);
    // 0x80057694: addiu       $t0, $s0, 0x40
    ctx->r8 = ADD32(ctx->r16, 0X40);
    // 0x80057698: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8005769C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800576A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800576A4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800576A8: jal         0x8006F88C
    // 0x800576AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x800576AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x800576B0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800576B4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800576B8: addiu       $t1, $s0, 0x44
    ctx->r9 = ADD32(ctx->r16, 0X44);
    // 0x800576BC: addiu       $t2, $s0, 0x48
    ctx->r10 = ADD32(ctx->r16, 0X48);
    // 0x800576C0: addiu       $t3, $s0, 0x4C
    ctx->r11 = ADD32(ctx->r16, 0X4C);
    // 0x800576C4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800576C8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800576CC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800576D0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800576D4: jal         0x8006F88C
    // 0x800576D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x800576D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x800576DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800576E0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800576E4: addiu       $t4, $s0, 0x50
    ctx->r12 = ADD32(ctx->r16, 0X50);
    // 0x800576E8: addiu       $t5, $s0, 0x54
    ctx->r13 = ADD32(ctx->r16, 0X54);
    // 0x800576EC: addiu       $t6, $s0, 0x58
    ctx->r14 = ADD32(ctx->r16, 0X58);
    // 0x800576F0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800576F4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800576F8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800576FC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80057700: jal         0x8006F88C
    // 0x80057704: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x80057704: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x80057708: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8005770C: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80057710: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80057714: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80057718: jr          $ra
    // 0x8005771C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8005771C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void object_do_player_tumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012E28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80012E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012E30: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80012E34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012E38: bne         $t6, $at, L_80012F20
    if (ctx->r14 != ctx->r1) {
        // 0x80012E3C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80012F20;
    }
    // 0x80012E3C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80012E40: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80012E44: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80012E48: lh          $t8, 0x160($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X160);
    // 0x80012E4C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x80012E50: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80012E54: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x80012E58: lh          $t1, 0x162($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X162);
    // 0x80012E5C: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x80012E60: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80012E64: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
    // 0x80012E68: lh          $t4, 0x164($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X164);
    // 0x80012E6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80012E70: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80012E74: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x80012E78: lb          $t6, 0x1D7($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1D7);
    // 0x80012E7C: nop

    // 0x80012E80: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80012E84: beq         $at, $zero, L_80012F0C
    if (ctx->r1 == 0) {
        // 0x80012E88: nop
    
            goto L_80012F0C;
    }
    // 0x80012E88: nop

    // 0x80012E8C: lh          $a0, 0x164($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X164);
    // 0x80012E90: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80012E94: jal         0x80070A38
    // 0x80012E98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80012E98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x80012E9C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80012EA0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80012EA4: lh          $t8, 0x166($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X166);
    // 0x80012EA8: lh          $t7, 0x162($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X162);
    // 0x80012EAC: nop

    // 0x80012EB0: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x80012EB4: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80012EB8: jal         0x80070A38
    // 0x80012EBC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80012EBC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_1:
    // 0x80012EC0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80012EC4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80012EC8: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80012ECC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80012ED0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80012ED4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80012ED8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80012EDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012EE0: bc1f        L_80012EF0
    if (!c1cs) {
        // 0x80012EE4: lui         $at, 0x41C0
        ctx->r1 = S32(0X41C0 << 16);
            goto L_80012EF0;
    }
    // 0x80012EE4: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80012EE8: b           L_80012EF8
    // 0x80012EEC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80012EF8;
    // 0x80012EEC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80012EF0:
    // 0x80012EF0: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80012EF4: nop

L_80012EF8:
    // 0x80012EF8: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80012EFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80012F00: lwc1        $f18, 0xD0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XD0);
    // 0x80012F04: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80012F08: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
L_80012F0C:
    // 0x80012F0C: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80012F10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012F14: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80012F18: swc1        $f6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f6.u32l;
    // 0x80012F1C: swc1        $f0, -0x4CB0($at)
    MEM_W(-0X4CB0, ctx->r1) = ctx->f0.u32l;
L_80012F20:
    // 0x80012F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012F24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80012F28: jr          $ra
    // 0x80012F2C: nop

    return;
    // 0x80012F2C: nop

;}
RECOMP_FUNC void obj_spawn_attachment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FD54: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000FD58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000FD5C: lw          $t6, -0x4D18($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D18);
    // 0x8000FD60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000FD64: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000FD68: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000FD6C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000FD70: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000FD74: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000FD78: bne         $at, $zero, L_8000FD84
    if (ctx->r1 != 0) {
        // 0x8000FD7C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8000FD84;
    }
    // 0x8000FD7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000FD80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000FD84:
    // 0x8000FD84: jal         0x8000C718
    // 0x8000FD88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    load_object_header(rdram, ctx);
        goto after_0;
    // 0x8000FD88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000FD8C: bne         $v0, $zero, L_8000FD9C
    if (ctx->r2 != 0) {
        // 0x8000FD90: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8000FD9C;
    }
    // 0x8000FD90: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8000FD94: b           L_8000FF98
    // 0x8000FD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF98;
    // 0x8000FD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FD9C:
    // 0x8000FD9C: lb          $s0, 0x55($s3)
    ctx->r16 = MEM_B(ctx->r19, 0X55);
    // 0x8000FDA0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8000FDA4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8000FDA8: addiu       $s0, $t7, 0x80
    ctx->r16 = ADD32(ctx->r15, 0X80);
    // 0x8000FDAC: jal         0x80070F50
    // 0x8000FDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x8000FDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000FDB4: bne         $v0, $zero, L_8000FDD0
    if (ctx->r2 != 0) {
        // 0x8000FDB8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8000FDD0;
    }
    // 0x8000FDB8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000FDBC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8000FDC0: jal         0x8000C844
    // 0x8000FDC4: nop

    try_free_object_header(rdram, ctx);
        goto after_2;
    // 0x8000FDC4: nop

    after_2:
    // 0x8000FDC8: b           L_8000FF98
    // 0x8000FDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF98;
    // 0x8000FDCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FDD0:
    // 0x8000FDD0: blez        $s0, L_8000FE20
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8000FDD4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000FE20;
    }
    // 0x8000FDD4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000FDD8: andi        $a1, $s0, 0x3
    ctx->r5 = ctx->r16 & 0X3;
    // 0x8000FDDC: beq         $a1, $zero, L_8000FDFC
    if (ctx->r5 == 0) {
        // 0x8000FDE0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8000FDFC;
    }
    // 0x8000FDE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000FDE4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8000FDE8:
    // 0x8000FDE8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FDEC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000FDF0: bne         $a0, $s1, L_8000FDE8
    if (ctx->r4 != ctx->r17) {
        // 0x8000FDF4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000FDE8;
    }
    // 0x8000FDF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000FDF8: beq         $s1, $s0, L_8000FE1C
    if (ctx->r17 == ctx->r16) {
        // 0x8000FDFC: addu        $v1, $v0, $s1
        ctx->r3 = ADD32(ctx->r2, ctx->r17);
            goto L_8000FE1C;
    }
L_8000FDFC:
    // 0x8000FDFC: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
L_8000FE00:
    // 0x8000FE00: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000FE04: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8000FE08: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x8000FE0C: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x8000FE10: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8000FE14: bne         $s1, $s0, L_8000FE00
    if (ctx->r17 != ctx->r16) {
        // 0x8000FE18: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000FE00;
    }
    // 0x8000FE18: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000FE1C:
    // 0x8000FE1C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000FE20:
    // 0x8000FE20: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000FE24: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x8000FE28: sw          $s3, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r19;
    // 0x8000FE2C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8000FE30: nop

    // 0x8000FE34: sh          $t9, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r25;
    // 0x8000FE38: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8000FE3C: nop

    // 0x8000FE40: sh          $t0, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r8;
    // 0x8000FE44: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8000FE48: nop

    // 0x8000FE4C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8000FE50: lhu         $t1, 0x30($s3)
    ctx->r9 = MEM_HU(ctx->r19, 0X30);
    // 0x8000FE54: nop

    // 0x8000FE58: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x8000FE5C: beq         $t2, $zero, L_8000FE74
    if (ctx->r10 == 0) {
        // 0x8000FE60: nop
    
            goto L_8000FE74;
    }
    // 0x8000FE60: nop

    // 0x8000FE64: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8000FE68: nop

    // 0x8000FE6C: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x8000FE70: sh          $t4, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r12;
L_8000FE74:
    // 0x8000FE74: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8000FE78: addiu       $t6, $v0, 0x80
    ctx->r14 = ADD32(ctx->r2, 0X80);
    // 0x8000FE7C: lb          $t5, 0x53($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X53);
    // 0x8000FE80: lb          $s4, 0x55($v1)
    ctx->r20 = MEM_B(ctx->r3, 0X55);
    // 0x8000FE84: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8000FE88: sw          $t6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r14;
    // 0x8000FE8C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8000FE90: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000FE94: bne         $t7, $zero, L_8000FF04
    if (ctx->r15 != 0) {
        // 0x8000FE98: nop
    
            goto L_8000FF04;
    }
    // 0x8000FE98: nop

    // 0x8000FE9C: blez        $s4, L_8000FF64
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8000FEA0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000FF64;
    }
    // 0x8000FEA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000FEA4:
    // 0x8000FEA4: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x8000FEA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000FEAC: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8000FEB0: nop

    // 0x8000FEB4: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000FEB8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8000FEBC: jal         0x8005FB3C
    // 0x8000FEC0: nop

    object_model_init(rdram, ctx);
        goto after_3;
    // 0x8000FEC0: nop

    after_3:
    // 0x8000FEC4: lw          $t1, 0x68($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X68);
    // 0x8000FEC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FECC: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8000FED0: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8000FED4: lw          $t3, 0x68($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X68);
    // 0x8000FED8: nop

    // 0x8000FEDC: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8000FEE0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8000FEE4: nop

    // 0x8000FEE8: bne         $t5, $zero, L_8000FEF4
    if (ctx->r13 != 0) {
        // 0x8000FEEC: nop
    
            goto L_8000FEF4;
    }
    // 0x8000FEEC: nop

    // 0x8000FEF0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8000FEF4:
    // 0x8000FEF4: bne         $s1, $s4, L_8000FEA4
    if (ctx->r17 != ctx->r20) {
        // 0x8000FEF8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000FEA4;
    }
    // 0x8000FEF8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000FEFC: b           L_8000FF64
    // 0x8000FF00: nop

        goto L_8000FF64;
    // 0x8000FF00: nop

L_8000FF04:
    // 0x8000FF04: blez        $s4, L_8000FF64
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8000FF08: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000FF64;
    }
    // 0x8000FF08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000FF0C:
    // 0x8000FF0C: lw          $t6, 0x40($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X40);
    // 0x8000FF10: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8000FF14: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8000FF18: nop

    // 0x8000FF1C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8000FF20: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x8000FF24: jal         0x8007C57C
    // 0x8000FF28: nop

    tex_load_sprite(rdram, ctx);
        goto after_4;
    // 0x8000FF28: nop

    after_4:
    // 0x8000FF2C: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000FF30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FF34: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000FF38: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8000FF3C: lw          $t1, 0x68($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X68);
    // 0x8000FF40: nop

    // 0x8000FF44: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8000FF48: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8000FF4C: nop

    // 0x8000FF50: bne         $t3, $zero, L_8000FF5C
    if (ctx->r11 != 0) {
        // 0x8000FF54: nop
    
            goto L_8000FF5C;
    }
    // 0x8000FF54: nop

    // 0x8000FF58: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8000FF5C:
    // 0x8000FF5C: bne         $s1, $s4, L_8000FF0C
    if (ctx->r17 != ctx->r20) {
        // 0x8000FF60: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000FF0C;
    }
    // 0x8000FF60: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000FF64:
    // 0x8000FF64: beq         $s3, $zero, L_8000FF98
    if (ctx->r19 == 0) {
        // 0x8000FF68: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_8000FF98;
    }
    // 0x8000FF68: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8000FF6C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8000FF70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000FF74: jal         0x8000F648
    // 0x8000FF78: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    objFreeAssets(rdram, ctx);
        goto after_5;
    // 0x8000FF78: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_5:
    // 0x8000FF7C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8000FF80: jal         0x8000C844
    // 0x8000FF84: nop

    try_free_object_header(rdram, ctx);
        goto after_6;
    // 0x8000FF84: nop

    after_6:
    // 0x8000FF88: jal         0x80071380
    // 0x8000FF8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8000FF8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x8000FF90: b           L_8000FF98
    // 0x8000FF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF98;
    // 0x8000FF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FF98:
    // 0x8000FF98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FF9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000FFA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FFA4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000FFA8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000FFAC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000FFB0: jr          $ra
    // 0x8000FFB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000FFB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void sound_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800020E8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800020EC: lw          $t6, 0x6294($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6294);
    // 0x800020F0: nop

    // 0x800020F4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800020F8: nop

    // 0x800020FC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80002100: nop

    // 0x80002104: lhu         $v0, 0xE($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0XE);
    // 0x80002108: jr          $ra
    // 0x8000210C: nop

    return;
    // 0x8000210C: nop

;}
RECOMP_FUNC void obj_loop_wballoonpop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E5FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003E600: jr          $ra
    // 0x8003E604: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003E604: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_loop_bombexplosion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038C34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80038C38: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80038C3C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80038C40: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80038C44: lw          $t0, 0x7C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X7C);
    // 0x80038C48: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x80038C4C: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80038C50: sra         $v1, $t0, 8
    ctx->r3 = S32(SIGNED(ctx->r8) >> 8);
    // 0x80038C54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80038C58: sw          $v0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r2;
    // 0x80038C5C: bne         $at, $zero, L_80038CA8
    if (ctx->r1 != 0) {
        // 0x80038C60: andi        $t8, $v1, 0xFF
        ctx->r24 = ctx->r3 & 0XFF;
            goto L_80038CA8;
    }
    // 0x80038C60: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x80038C64: beq         $t8, $zero, L_80038CA8
    if (ctx->r24 == 0) {
        // 0x80038C68: sll         $t9, $t8, 8
        ctx->r25 = S32(ctx->r24 << 8);
            goto L_80038CA8;
    }
    // 0x80038C68: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80038C6C: xor         $t1, $t0, $t9
    ctx->r9 = ctx->r8 ^ ctx->r25;
    // 0x80038C70: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80038C74: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80038C78: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x80038C7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80038C80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038C84: sw          $t1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r9;
    // 0x80038C88: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x80038C8C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80038C90: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80038C94: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80038C98: jal         0x8003FC84
    // 0x80038C9C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_0;
    // 0x80038C9C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80038CA0: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80038CA4: nop

L_80038CA8:
    // 0x80038CA8: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80038CAC: beq         $at, $zero, L_80038CFC
    if (ctx->r1 == 0) {
        // 0x80038CB0: slti        $at, $v0, 0x28
        ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
            goto L_80038CFC;
    }
    // 0x80038CB0: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x80038CB4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80038CB8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80038CBC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80038CC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038CC4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80038CC8: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80038CCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038CD0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80038CD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038CD8: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
    // 0x80038CDC: nop

    // 0x80038CE0: ori         $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 | 0XFF;
    // 0x80038CE4: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x80038CE8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80038CEC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80038CF0: b           L_80038D58
    // 0x80038CF4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_80038D58;
    // 0x80038CF4: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80038CF8: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
L_80038CFC:
    // 0x80038CFC: beq         $at, $zero, L_80038D50
    if (ctx->r1 == 0) {
        // 0x80038D00: addiu       $t5, $v0, -0x14
        ctx->r13 = ADD32(ctx->r2, -0X14);
            goto L_80038D50;
    }
    // 0x80038D00: addiu       $t5, $v0, -0x14
    ctx->r13 = ADD32(ctx->r2, -0X14);
    // 0x80038D04: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80038D08: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80038D0C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80038D10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038D14: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80038D18: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80038D1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038D20: lui         $at, 0x4128
    ctx->r1 = S32(0X4128 << 16);
    // 0x80038D24: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80038D28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038D2C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80038D30: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80038D34: addiu       $t7, $zero, 0x1EF
    ctx->r15 = ADD32(0, 0X1EF);
    // 0x80038D38: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80038D3C: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x80038D40: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80038D44: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80038D48: b           L_80038D58
    // 0x80038D4C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_80038D58;
    // 0x80038D4C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_80038D50:
    // 0x80038D50: jal         0x8000FFB8
    // 0x80038D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x80038D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80038D58:
    // 0x80038D58: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80038D5C: nop

    // 0x80038D60: beq         $t9, $zero, L_80038D8C
    if (ctx->r25 == 0) {
        // 0x80038D64: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80038D8C;
    }
    // 0x80038D64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80038D68: jal         0x8009C90C
    // 0x80038D6C: nop

    get_number_of_active_players(rdram, ctx);
        goto after_2;
    // 0x80038D6C: nop

    after_2:
    // 0x80038D70: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80038D74: beq         $at, $zero, L_80038D88
    if (ctx->r1 == 0) {
        // 0x80038D78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80038D88;
    }
    // 0x80038D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80038D7C: jal         0x800B019C
    // 0x80038D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    obj_spawn_particle(rdram, ctx);
        goto after_3;
    // 0x80038D80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80038D84: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
L_80038D88:
    // 0x80038D88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80038D8C:
    // 0x80038D8C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80038D90: jr          $ra
    // 0x80038D94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80038D94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void results_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097C08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097C10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80097C14: jal         0x8009C9EC
    // 0x80097C18: addiu       $a0, $a0, 0xFA4
    ctx->r4 = ADD32(ctx->r4, 0XFA4);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x80097C18: addiu       $a0, $a0, 0xFA4
    ctx->r4 = ADD32(ctx->r4, 0XFA4);
    after_0:
    // 0x80097C1C: jal         0x800C478C
    // 0x80097C20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x80097C20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80097C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097C2C: jr          $ra
    // 0x80097C30: nop

    return;
    // 0x80097C30: nop

;}
RECOMP_FUNC void update_player_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057A80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80057A84: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80057A88: lw          $t6, -0x2554($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2554);
    // 0x80057A8C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80057A90: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80057A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057A98: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80057A9C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80057AA0: beq         $t7, $zero, L_80057B80
    if (ctx->r15 == 0) {
        // 0x80057AA4: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_80057B80;
    }
    // 0x80057AA4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80057AA8: jal         0x800A06D0
    // 0x80057AAC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    race_starting(rdram, ctx);
        goto after_0;
    // 0x80057AAC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80057AB0: beq         $v0, $zero, L_80057B80
    if (ctx->r2 == 0) {
        // 0x80057AB4: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80057B80;
    }
    // 0x80057AB4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057AB8: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x80057ABC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057AC0: nop

    // 0x80057AC4: lbu         $t8, 0x3B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3B);
    // 0x80057AC8: nop

    // 0x80057ACC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80057AD0: sb          $t9, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = ctx->r25;
    // 0x80057AD4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057AD8: nop

    // 0x80057ADC: lbu         $a1, 0x3B($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X3B);
    // 0x80057AE0: nop

    // 0x80057AE4: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80057AE8: bne         $at, $zero, L_80057B08
    if (ctx->r1 != 0) {
        // 0x80057AEC: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_80057B08;
    }
    // 0x80057AEC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80057AF0: sb          $zero, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = 0;
    // 0x80057AF4: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80057AF8: nop

    // 0x80057AFC: lbu         $a1, 0x3B($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X3B);
    // 0x80057B00: nop

    // 0x80057B04: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_80057B08:
    // 0x80057B08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80057B0C: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x80057B10: nop

    // 0x80057B14: beq         $a0, $at, L_80057B3C
    if (ctx->r4 == ctx->r1) {
        // 0x80057B18: nop
    
            goto L_80057B3C;
    }
    // 0x80057B18: nop

    // 0x80057B1C: jal         0x800662A0
    // 0x80057B20: nop

    cam_set_zoom(rdram, ctx);
        goto after_1;
    // 0x80057B20: nop

    after_1:
    // 0x80057B24: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057B28: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x80057B2C: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80057B30: nop

    // 0x80057B34: lbu         $a1, 0x3B($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X3B);
    // 0x80057B38: nop

L_80057B3C:
    // 0x80057B3C: beq         $a1, $zero, L_80057B58
    if (ctx->r5 == 0) {
        // 0x80057B40: addiu       $a0, $zero, 0x68
        ctx->r4 = ADD32(0, 0X68);
            goto L_80057B58;
    }
    // 0x80057B40: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x80057B44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80057B48: beq         $a1, $at, L_80057B68
    if (ctx->r5 == ctx->r1) {
        // 0x80057B4C: addiu       $a0, $zero, 0x69
        ctx->r4 = ADD32(0, 0X69);
            goto L_80057B68;
    }
    // 0x80057B4C: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    // 0x80057B50: b           L_80057B78
    // 0x80057B54: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
        goto L_80057B78;
    // 0x80057B54: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
L_80057B58:
    // 0x80057B58: jal         0x80001D04
    // 0x80057B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80057B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80057B60: b           L_80057B84
    // 0x80057B64: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
        goto L_80057B84;
    // 0x80057B64: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_80057B68:
    // 0x80057B68: jal         0x80001D04
    // 0x80057B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x80057B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80057B70: b           L_80057B84
    // 0x80057B74: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
        goto L_80057B84;
    // 0x80057B74: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_80057B78:
    // 0x80057B78: jal         0x80001D04
    // 0x80057B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x80057B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80057B80:
    // 0x80057B80: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_80057B84:
    // 0x80057B84: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057B88: lb          $t3, 0x1D8($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X1D8);
    // 0x80057B8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80057B90: bne         $t3, $at, L_80057BB4
    if (ctx->r11 != ctx->r1) {
        // 0x80057B94: addiu       $a3, $a3, -0x2578
        ctx->r7 = ADD32(ctx->r7, -0X2578);
            goto L_80057BB4;
    }
    // 0x80057B94: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x80057B98: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057B9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80057BA0: lh          $t4, 0x36($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X36);
    // 0x80057BA4: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80057BA8: beq         $t4, $at, L_80057BB4
    if (ctx->r12 == ctx->r1) {
        // 0x80057BAC: nop
    
            goto L_80057BB4;
    }
    // 0x80057BAC: nop

    // 0x80057BB0: sh          $t5, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r13;
L_80057BB4:
    // 0x80057BB4: lw          $t6, 0x108($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X108);
    // 0x80057BB8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057BBC: beq         $t6, $zero, L_80057BD0
    if (ctx->r14 == 0) {
        // 0x80057BC0: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80057BD0;
    }
    // 0x80057BC0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80057BC4: sh          $t7, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r15;
    // 0x80057BC8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057BCC: nop

L_80057BD0:
    // 0x80057BD0: lhu         $t8, 0x36($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X36);
    // 0x80057BD4: nop

    // 0x80057BD8: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80057BDC: beq         $at, $zero, L_80057D10
    if (ctx->r1 == 0) {
        // 0x80057BE0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80057D10;
    }
    // 0x80057BE0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80057BE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057BE8: addu        $at, $at, $t8
    gpr jr_addend_80057BF4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80057BEC: lw          $t8, 0x6E60($at)
    ctx->r24 = ADD32(ctx->r1, 0X6E60);
    // 0x80057BF0: nop

    // 0x80057BF4: jr          $t8
    // 0x80057BF8: nop

    switch (jr_addend_80057BF4 >> 2) {
        case 0: goto L_80057BFC; break;
        case 1: goto L_80057C24; break;
        case 2: goto L_80057D10; break;
        case 3: goto L_80057C4C; break;
        case 4: goto L_80057C74; break;
        case 5: goto L_80057C9C; break;
        case 6: goto L_80057CC4; break;
        case 7: goto L_80057CEC; break;
        default: switch_error(__func__, 0x80057BF4, 0x800E6E60);
    }
    // 0x80057BF8: nop

L_80057BFC:
    // 0x80057BFC: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057C00: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057C04: jal         0x80058228
    // 0x80057C08: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_car(rdram, ctx);
        goto after_5;
    // 0x80057C08: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_5:
    // 0x80057C0C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057C10: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x80057C14: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057C18: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057C1C: b           L_80057D10
    // 0x80057C20: nop

        goto L_80057D10;
    // 0x80057C20: nop

L_80057C24:
    // 0x80057C24: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057C28: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057C2C: jal         0x8004C2F0
    // 0x80057C30: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_plane(rdram, ctx);
        goto after_6;
    // 0x80057C30: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_6:
    // 0x80057C34: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057C38: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x80057C3C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057C40: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057C44: b           L_80057D10
    // 0x80057C48: nop

        goto L_80057D10;
    // 0x80057C48: nop

L_80057C4C:
    // 0x80057C4C: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057C50: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057C54: jal         0x80058F84
    // 0x80057C58: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_fixed(rdram, ctx);
        goto after_7;
    // 0x80057C58: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_7:
    // 0x80057C5C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057C60: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x80057C64: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057C68: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057C6C: b           L_80057D10
    // 0x80057C70: nop

        goto L_80057D10;
    // 0x80057C70: nop

L_80057C74:
    // 0x80057C74: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057C78: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057C7C: jal         0x80048EA4
    // 0x80057C80: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_hovercraft(rdram, ctx);
        goto after_8;
    // 0x80057C80: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_8:
    // 0x80057C84: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057C88: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x80057C8C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057C90: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057C94: b           L_80057D10
    // 0x80057C98: nop

        goto L_80057D10;
    // 0x80057C98: nop

L_80057C9C:
    // 0x80057C9C: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057CA0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057CA4: jal         0x80058BC4
    // 0x80057CA8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_finish_challenge(rdram, ctx);
        goto after_9;
    // 0x80057CA8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_9:
    // 0x80057CAC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057CB0: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x80057CB4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057CB8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057CBC: b           L_80057D10
    // 0x80057CC0: nop

        goto L_80057D10;
    // 0x80057CC0: nop

L_80057CC4:
    // 0x80057CC4: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057CC8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057CCC: jal         0x8004D5D0
    // 0x80057CD0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_loop(rdram, ctx);
        goto after_10;
    // 0x80057CD0: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_10:
    // 0x80057CD4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057CD8: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x80057CDC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057CE0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057CE4: b           L_80057D10
    // 0x80057CE8: nop

        goto L_80057D10;
    // 0x80057CE8: nop

L_80057CEC:
    // 0x80057CEC: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057CF0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80057CF4: jal         0x80058D9C
    // 0x80057CF8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    update_camera_finish_race(rdram, ctx);
        goto after_11;
    // 0x80057CF8: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_11:
    // 0x80057CFC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057D00: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x80057D04: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057D08: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80057D0C: nop

L_80057D10:
    // 0x80057D10: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80057D14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057D18: addiu       $v1, $v1, -0x24FA
    ctx->r3 = ADD32(ctx->r3, -0X24FA);
    // 0x80057D1C: lwc1        $f1, 0x6E80($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6E80);
    // 0x80057D20: lwc1        $f0, 0x6E84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6E84);
    // 0x80057D24: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80057D28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057D2C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80057D30: lwc1        $f13, 0x6E88($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X6E88);
    // 0x80057D34: lwc1        $f12, 0x6E8C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6E8C);
    // 0x80057D38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80057D3C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80057D40: lui         $at, 0x4620
    ctx->r1 = S32(0X4620 << 16);
    // 0x80057D44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80057D48: lwc1        $f18, 0x38($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X38);
    // 0x80057D4C: lwc1        $f10, 0xC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80057D50: div.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80057D54: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80057D58: mul.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80057D5C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80057D60: lwc1        $f10, 0x50($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X50);
    // 0x80057D64: nop

    // 0x80057D68: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80057D6C: mul.d       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f12.d, ctx->f18.d);
    // 0x80057D70: add.d       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f16.d + ctx->f6.d;
    // 0x80057D74: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80057D78: add.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = ctx->f8.d + ctx->f4.d;
    // 0x80057D7C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80057D80: sub.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d - ctx->f10.d;
    // 0x80057D84: cvt.d.s     $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.d = CVT_D_S(ctx->f14.fl);
    // 0x80057D88: mul.d       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x80057D8C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80057D90: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x80057D94: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80057D98: lwc1        $f10, 0x40($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X40);
    // 0x80057D9C: lwc1        $f6, 0x14($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X14);
    // 0x80057DA0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80057DA4: mul.d       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x80057DA8: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80057DAC: lwc1        $f6, 0x58($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X58);
    // 0x80057DB0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057DB4: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80057DB8: mul.d       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f12.d, ctx->f10.d);
    // 0x80057DBC: add.d       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f16.d + ctx->f8.d;
    // 0x80057DC0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80057DC4: add.d       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f4.d + ctx->f18.d;
    // 0x80057DC8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80057DCC: sub.d       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f16.d - ctx->f6.d;
    // 0x80057DD0: mul.d       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x80057DD4: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x80057DD8: swc1        $f18, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f18.u32l;
    // 0x80057DDC: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x80057DE0: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80057DE4: jal         0x8003ACEC
    // 0x80057DE8: swc1        $f3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(3 - 1) * 2];
    get_npc_pos_y(rdram, ctx);
        goto after_12;
    // 0x80057DE8: swc1        $f3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(3 - 1) * 2];
    after_12:
    // 0x80057DEC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80057DF0: addiu       $a3, $a3, -0x2578
    ctx->r7 = ADD32(ctx->r7, -0X2578);
    // 0x80057DF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057DF8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057DFC: lwc1        $f17, 0x6E90($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6E90);
    // 0x80057E00: lwc1        $f16, 0x6E94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6E94);
    // 0x80057E04: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80057E08: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80057E0C: add.d       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f8.d + ctx->f16.d;
    // 0x80057E10: lwc1        $f3, 0x18($sp)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80057E14: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80057E18: sub.d       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f6.d - ctx->f4.d;
    // 0x80057E1C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80057E20: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80057E24: mul.d       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x80057E28: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80057E2C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80057E30: addiu       $v1, $v1, -0x24FA
    ctx->r3 = ADD32(ctx->r3, -0X24FA);
    // 0x80057E34: addiu       $t8, $zero, 0x2800
    ctx->r24 = ADD32(0, 0X2800);
    // 0x80057E38: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80057E3C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80057E40: swc1        $f16, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f16.u32l;
    // 0x80057E44: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057E48: nop

    // 0x80057E4C: lh          $t2, 0x2($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2);
    // 0x80057E50: nop

    // 0x80057E54: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80057E58: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80057E5C: nop

    // 0x80057E60: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80057E64: mul.s       $f4, $f6, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80057E68: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80057E6C: nop

    // 0x80057E70: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80057E74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80057E78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80057E7C: nop

    // 0x80057E80: cvt.w.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80057E84: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80057E88: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80057E8C: sh          $t5, 0x38($v0)
    MEM_H(0X38, ctx->r2) = ctx->r13;
    // 0x80057E90: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057E94: nop

    // 0x80057E98: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80057E9C: lwc1        $f16, 0x24($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80057EA0: nop

    // 0x80057EA4: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80057EA8: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80057EAC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057EB0: nop

    // 0x80057EB4: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80057EB8: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80057EBC: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80057EC0: add.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80057EC4: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80057EC8: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x80057ECC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057ED0: nop

    // 0x80057ED4: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80057ED8: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80057EDC: nop

    // 0x80057EE0: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80057EE4: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x80057EE8: lw          $t6, -0x2540($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2540);
    // 0x80057EEC: nop

    // 0x80057EF0: bne         $t6, $zero, L_80057F68
    if (ctx->r14 != 0) {
        // 0x80057EF4: nop
    
            goto L_80057F68;
    }
    // 0x80057EF4: nop

    // 0x80057EF8: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80057EFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057F00: bne         $t7, $zero, L_80057F68
    if (ctx->r15 != 0) {
        // 0x80057F04: nop
    
            goto L_80057F68;
    }
    // 0x80057F04: nop

    // 0x80057F08: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057F0C: lwc1        $f1, 0x6E98($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6E98);
    // 0x80057F10: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80057F14: lwc1        $f0, 0x6E9C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6E9C);
    // 0x80057F18: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80057F1C: mul.d       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80057F20: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x80057F24: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x80057F28: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057F2C: nop

    // 0x80057F30: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80057F34: nop

    // 0x80057F38: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80057F3C: mul.d       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80057F40: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
    // 0x80057F44: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x80057F48: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80057F4C: nop

    // 0x80057F50: lwc1        $f16, 0x2C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80057F54: nop

    // 0x80057F58: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x80057F5C: mul.d       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80057F60: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80057F64: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
L_80057F68:
    // 0x80057F68: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80057F6C: nop

    // 0x80057F70: slti        $at, $a0, 0x1401
    ctx->r1 = SIGNED(ctx->r4) < 0X1401 ? 1 : 0;
    // 0x80057F74: bne         $at, $zero, L_80057F80
    if (ctx->r1 != 0) {
        // 0x80057F78: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80057F80;
    }
    // 0x80057F78: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80057F7C: subu        $v0, $t8, $a0
    ctx->r2 = SUB32(ctx->r24, ctx->r4);
L_80057F80:
    // 0x80057F80: slti        $at, $v0, 0x601
    ctx->r1 = SIGNED(ctx->r2) < 0X601 ? 1 : 0;
    // 0x80057F84: bne         $at, $zero, L_80057F90
    if (ctx->r1 != 0) {
        // 0x80057F88: nop
    
            goto L_80057F90;
    }
    // 0x80057F88: nop

    // 0x80057F8C: addiu       $v0, $zero, 0x600
    ctx->r2 = ADD32(0, 0X600);
L_80057F90:
    // 0x80057F90: lb          $t0, -0x24FD($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X24FD);
    // 0x80057F94: sra         $t9, $v0, 4
    ctx->r25 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80057F98: beq         $t0, $zero, L_80057FFC
    if (ctx->r8 == 0) {
        // 0x80057F9C: addiu       $v0, $t9, 0x4
        ctx->r2 = ADD32(ctx->r25, 0X4);
            goto L_80057FFC;
    }
    // 0x80057F9C: addiu       $v0, $t9, 0x4
    ctx->r2 = ADD32(ctx->r25, 0X4);
    // 0x80057FA0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80057FA4: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057FA8: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80057FAC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80057FB0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80057FB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80057FB8: cvt.w.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80057FBC: addiu       $t4, $zero, 0x2800
    ctx->r12 = ADD32(0, 0X2800);
    // 0x80057FC0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80057FC4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80057FC8: multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057FCC: mflo        $t2
    ctx->r10 = lo;
    // 0x80057FD0: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80057FD4: sh          $t3, -0x24FA($at)
    MEM_H(-0X24FA, ctx->r1) = ctx->r11;
    // 0x80057FD8: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80057FDC: nop

    // 0x80057FE0: slti        $at, $a0, 0x2801
    ctx->r1 = SIGNED(ctx->r4) < 0X2801 ? 1 : 0;
    // 0x80057FE4: bne         $at, $zero, L_8005804C
    if (ctx->r1 != 0) {
        // 0x80057FE8: nop
    
            goto L_8005804C;
    }
    // 0x80057FE8: nop

    // 0x80057FEC: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x80057FF0: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80057FF4: b           L_80058050
    // 0x80057FF8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
        goto L_80058050;
    // 0x80057FF8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_80057FFC:
    // 0x80057FFC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80058000: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80058004: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80058008: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005800C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80058010: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80058014: cvt.w.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80058018: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005801C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80058020: multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80058024: mflo        $t6
    ctx->r14 = lo;
    // 0x80058028: subu        $t7, $a0, $t6
    ctx->r15 = SUB32(ctx->r4, ctx->r14);
    // 0x8005802C: sh          $t7, -0x24FA($at)
    MEM_H(-0X24FA, ctx->r1) = ctx->r15;
    // 0x80058030: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80058034: nop

    // 0x80058038: bgez        $a0, L_8005804C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005803C: nop
    
            goto L_8005804C;
    }
    // 0x8005803C: nop

    // 0x80058040: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80058044: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80058048: nop

L_8005804C:
    // 0x8005804C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_80058050:
    // 0x80058050: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x80058054: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80058058: nop

    // 0x8005805C: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
    // 0x80058060: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x80058064: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80058068: nop

    // 0x8005806C: lb          $t0, 0x3A($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X3A);
    // 0x80058070: nop

    // 0x80058074: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x80058078: sb          $t1, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r9;
    // 0x8005807C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80058080: nop

    // 0x80058084: lb          $v1, 0x3A($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3A);
    // 0x80058088: nop

    // 0x8005808C: bgez        $v1, L_800580E8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80058090: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800580E8;
    }
    // 0x80058090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058094: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80058098: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005809C: nop

    // 0x800580A0: addiu       $t2, $v1, 0x5
    ctx->r10 = ADD32(ctx->r3, 0X5);
L_800580A4:
    // 0x800580A4: sb          $t2, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r10;
    // 0x800580A8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800580AC: nop

    // 0x800580B0: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800580B4: nop

    // 0x800580B8: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800580BC: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800580C0: mul.d       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800580C4: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x800580C8: swc1        $f16, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f16.u32l;
    // 0x800580CC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800580D0: nop

    // 0x800580D4: lb          $v1, 0x3A($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3A);
    // 0x800580D8: nop

    // 0x800580DC: bltz        $v1, L_800580A4
    if (SIGNED(ctx->r3) < 0) {
        // 0x800580E0: addiu       $t2, $v1, 0x5
        ctx->r10 = ADD32(ctx->r3, 0X5);
            goto L_800580A4;
    }
    // 0x800580E0: addiu       $t2, $v1, 0x5
    ctx->r10 = ADD32(ctx->r3, 0X5);
    // 0x800580E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800580E8:
    // 0x800580E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800580EC: jr          $ra
    // 0x800580F0: nop

    return;
    // 0x800580F0: nop

;}
RECOMP_FUNC void get_racer_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BAFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BB00: lw          $v0, -0x4B90($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4B90);
    // 0x8001BB04: nop

    // 0x8001BB08: bne         $v0, $zero, L_8001BB18
    if (ctx->r2 != 0) {
        // 0x8001BB0C: nop
    
            goto L_8001BB18;
    }
    // 0x8001BB0C: nop

    // 0x8001BB10: jr          $ra
    // 0x8001BB14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BB14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BB18:
    // 0x8001BB18: bltz        $a0, L_8001BB28
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001BB1C: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001BB28;
    }
    // 0x8001BB1C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BB20: bne         $at, $zero, L_8001BB30
    if (ctx->r1 != 0) {
        // 0x8001BB24: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001BB30;
    }
    // 0x8001BB24: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8001BB28:
    // 0x8001BB28: jr          $ra
    // 0x8001BB2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BB2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BB30:
    // 0x8001BB30: lw          $t6, -0x4B9C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B9C);
    // 0x8001BB34: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001BB38: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001BB3C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001BB40: nop

    // 0x8001BB44: jr          $ra
    // 0x8001BB48: nop

    return;
    // 0x8001BB48: nop

;}
RECOMP_FUNC void audspat_line_add_vertex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800098A4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800098A8: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    // 0x800098AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800098B0: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800098B4: lbu         $a3, 0x3($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3);
    // 0x800098B8: slti        $at, $a2, 0x7
    ctx->r1 = SIGNED(ctx->r6) < 0X7 ? 1 : 0;
    // 0x800098BC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800098C0: beq         $at, $zero, L_80009960
    if (ctx->r1 == 0) {
        // 0x800098C4: andi        $t6, $a1, 0xFFFF
        ctx->r14 = ctx->r5 & 0XFFFF;
            goto L_80009960;
    }
    // 0x800098C4: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x800098C8: lbu         $v0, 0x33($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X33);
    // 0x800098CC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800098D0: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x800098D4: beq         $at, $zero, L_80009960
    if (ctx->r1 == 0) {
        // 0x800098D8: subu        $t7, $t7, $a2
        ctx->r15 = SUB32(ctx->r15, ctx->r6);
            goto L_80009960;
    }
    // 0x800098D8: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800098DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800098E0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800098E4: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800098E8: addiu       $t8, $t8, -0x5E28
    ctx->r24 = ADD32(ctx->r24, -0X5E28);
    // 0x800098EC: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x800098F0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800098F4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800098F8: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800098FC: addu        $a0, $v1, $t0
    ctx->r4 = ADD32(ctx->r3, ctx->r8);
    // 0x80009900: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x80009904: swc1        $f14, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f14.u32l;
    // 0x80009908: bne         $v0, $zero, L_80009948
    if (ctx->r2 != 0) {
        // 0x8000990C: swc1        $f4, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
            goto L_80009948;
    }
    // 0x8000990C: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80009910: sw          $t6, 0x16C($v1)
    MEM_W(0X16C, ctx->r3) = ctx->r14;
    // 0x80009914: lhu         $t1, 0x26($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X26);
    // 0x80009918: lbu         $t2, 0x2B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2B);
    // 0x8000991C: lbu         $t3, 0x1B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X1B);
    // 0x80009920: lbu         $t4, 0x17($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X17);
    // 0x80009924: lbu         $t5, 0x1F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X1F);
    // 0x80009928: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x8000992C: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80009930: sw          $t1, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->r9;
    // 0x80009934: sb          $t2, 0x17D($v1)
    MEM_B(0X17D, ctx->r3) = ctx->r10;
    // 0x80009938: sb          $t3, 0x174($v1)
    MEM_B(0X174, ctx->r3) = ctx->r11;
    // 0x8000993C: sb          $t4, 0x175($v1)
    MEM_B(0X175, ctx->r3) = ctx->r12;
    // 0x80009940: sb          $t5, 0x176($v1)
    MEM_B(0X176, ctx->r3) = ctx->r13;
    // 0x80009944: sb          $t6, 0x17E($v1)
    MEM_B(0X17E, ctx->r3) = ctx->r14;
L_80009948:
    // 0x80009948: lb          $t7, 0x17C($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X17C);
    // 0x8000994C: nop

    // 0x80009950: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009954: beq         $at, $zero, L_80009960
    if (ctx->r1 == 0) {
        // 0x80009958: nop
    
            goto L_80009960;
    }
    // 0x80009958: nop

    // 0x8000995C: sb          $v0, 0x17C($v1)
    MEM_B(0X17C, ctx->r3) = ctx->r2;
L_80009960:
    // 0x80009960: jr          $ra
    // 0x80009964: nop

    return;
    // 0x80009964: nop

;}
RECOMP_FUNC void menu_file_select_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CFB4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008CFB8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008CFBC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008CFC0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008CFC4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008CFC8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008CFCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CFD0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8008CFD4: jal         0x8006B464
    // 0x8008CFD8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    level_count(rdram, ctx);
        goto after_0;
    // 0x8008CFD8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8008CFDC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CFE0: jal         0x8009CBB8
    // 0x8008CFE4: addiu       $a0, $a0, 0x918
    ctx->r4 = ADD32(ctx->r4, 0X918);
    menu_assetgroup_load(rdram, ctx);
        goto after_1;
    // 0x8008CFE4: addiu       $a0, $a0, 0x918
    ctx->r4 = ADD32(ctx->r4, 0X918);
    after_1:
    // 0x8008CFE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008CFEC: jal         0x8009CDE8
    // 0x8008CFF0: addiu       $a0, $a0, 0x924
    ctx->r4 = ADD32(ctx->r4, 0X924);
    menu_imagegroup_load(rdram, ctx);
        goto after_2;
    // 0x8008CFF0: addiu       $a0, $a0, 0x924
    ctx->r4 = ADD32(ctx->r4, 0X924);
    after_2:
    // 0x8008CFF4: jal         0x8008043C
    // 0x8008CFF8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8007FFEC(rdram, ctx);
        goto after_3;
    // 0x8008CFF8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_3:
    // 0x8008CFFC: jal         0x8006EDE8
    // 0x8008D000: nop

    mark_read_all_save_files(rdram, ctx);
        goto after_4;
    // 0x8008D000: nop

    after_4:
    // 0x8008D004: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008D008: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D00C: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
    // 0x8008D010: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D014: sw          $zero, -0x5B4($at)
    MEM_W(-0X5B4, ctx->r1) = 0;
    // 0x8008D018: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D01C: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008D020: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D024: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x8008D028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D02C: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008D030: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D034: sw          $zero, 0x6A24($at)
    MEM_W(0X6A24, ctx->r1) = 0;
    // 0x8008D038: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D03C: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
    // 0x8008D040: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D044: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008D048: sw          $zero, 0x7280($at)
    MEM_W(0X7280, ctx->r1) = 0;
    // 0x8008D04C: jal         0x800C06F8
    // 0x8008D050: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_5;
    // 0x8008D050: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_5:
    // 0x8008D054: jal         0x800C46D0
    // 0x8008D058: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_6;
    // 0x8008D058: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x8008D05C: jal         0x80000B34
    // 0x8008D060: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    music_play(rdram, ctx);
        goto after_7;
    // 0x8008D060: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_7:
    // 0x8008D064: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008D068: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008D06C: addiu       $s2, $s2, 0x6954
    ctx->r18 = ADD32(ctx->r18, 0X6954);
    // 0x8008D070: addiu       $s3, $s3, 0x334
    ctx->r19 = ADD32(ctx->r19, 0X334);
    // 0x8008D074: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008D078: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_8008D07C:
    // 0x8008D07C: lb          $t7, 0x0($s2)
    ctx->r15 = MEM_B(ctx->r18, 0X0);
    // 0x8008D080: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x8008D084: beq         $s0, $t7, L_8008D0A4
    if (ctx->r16 == ctx->r15) {
        // 0x8008D088: addu        $s1, $s3, $t8
        ctx->r17 = ADD32(ctx->r19, ctx->r24);
            goto L_8008D0A4;
    }
    // 0x8008D088: addu        $s1, $s3, $t8
    ctx->r17 = ADD32(ctx->r19, ctx->r24);
    // 0x8008D08C: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8008D090: jal         0x80001114
    // 0x8008D094: nop

    music_channel_off(rdram, ctx);
        goto after_8;
    // 0x8008D094: nop

    after_8:
    // 0x8008D098: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x8008D09C: jal         0x80001114
    // 0x8008D0A0: nop

    music_channel_off(rdram, ctx);
        goto after_9;
    // 0x8008D0A0: nop

    after_9:
L_8008D0A4:
    // 0x8008D0A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008D0A8: bne         $s0, $s4, L_8008D07C
    if (ctx->r16 != ctx->r20) {
        // 0x8008D0AC: nop
    
            goto L_8008D07C;
    }
    // 0x8008D0AC: nop

    // 0x8008D0B0: jal         0x80001114
    // 0x8008D0B4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    music_channel_off(rdram, ctx);
        goto after_10;
    // 0x8008D0B4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_10:
    // 0x8008D0B8: jal         0x80000B18
    // 0x8008D0BC: nop

    music_change_off(rdram, ctx);
        goto after_11;
    // 0x8008D0BC: nop

    after_11:
    // 0x8008D0C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008D0C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008D0C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D0CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008D0D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008D0D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008D0D8: jr          $ra
    // 0x8008D0DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008D0DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void draw_dialogue_text_pos_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4A70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C4A74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C4A78: bltz        $a1, L_800C4AF4
    if (SIGNED(ctx->r5) < 0) {
        // 0x800C4A7C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800C4AF4;
    }
    // 0x800C4A7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C4A80: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800C4A84: beq         $at, $zero, L_800C4AF4
    if (ctx->r1 == 0) {
        // 0x800C4A88: addiu       $v0, $zero, -0x8000
        ctx->r2 = ADD32(0, -0X8000);
            goto L_800C4AF4;
    }
    // 0x800C4A88: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800C4A8C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C4A90: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C4A94: lw          $t8, -0x5258($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5258);
    // 0x800C4A98: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x800C4A9C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C4AA0: bne         $a2, $v0, L_800C4ABC
    if (ctx->r6 != ctx->r2) {
        // 0x800C4AA4: addu        $a1, $t7, $t8
        ctx->r5 = ADD32(ctx->r15, ctx->r24);
            goto L_800C4ABC;
    }
    // 0x800C4AA4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800C4AA8: lh          $t9, 0xC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XC);
    // 0x800C4AAC: nop

    // 0x800C4AB0: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800C4AB4: b           L_800C4AC0
    // 0x800C4AB8: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
        goto L_800C4AC0;
    // 0x800C4AB8: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_800C4ABC:
    // 0x800C4ABC: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
L_800C4AC0:
    // 0x800C4AC0: bne         $a3, $v0, L_800C4ADC
    if (ctx->r7 != ctx->r2) {
        // 0x800C4AC4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800C4ADC;
    }
    // 0x800C4AC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4AC8: lh          $t1, 0xE($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XE);
    // 0x800C4ACC: nop

    // 0x800C4AD0: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800C4AD4: b           L_800C4AE0
    // 0x800C4AD8: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
        goto L_800C4AE0;
    // 0x800C4AD8: sh          $t2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r10;
L_800C4ADC:
    // 0x800C4ADC: sh          $a3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r7;
L_800C4AE0:
    // 0x800C4AE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C4AE4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800C4AE8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800C4AEC: jal         0x800C4B04
    // 0x800C4AF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C4AF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
L_800C4AF4:
    // 0x800C4AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4AF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C4AFC: jr          $ra
    // 0x800C4B00: nop

    return;
    // 0x800C4B00: nop

;}
RECOMP_FUNC void input_assign_players(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A674: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006A678: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006A67C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8006A680: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8006A684: sb          $t8, 0x16D3($at)
    MEM_B(0X16D3, ctx->r1) = ctx->r24;
    // 0x8006A688: sb          $t7, 0x16D2($at)
    MEM_B(0X16D2, ctx->r1) = ctx->r15;
    // 0x8006A68C: sb          $t6, 0x16D1($at)
    MEM_B(0X16D1, ctx->r1) = ctx->r14;
    // 0x8006A690: jr          $ra
    // 0x8006A694: sb          $zero, 0x16D0($at)
    MEM_B(0X16D0, ctx->r1) = 0;
    return;
    // 0x8006A694: sb          $zero, 0x16D0($at)
    MEM_B(0X16D0, ctx->r1) = 0;
;}
