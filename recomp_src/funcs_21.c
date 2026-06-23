#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void menu_camera_centre(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C2A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009C2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C2A8: jal         0x8006676C
    // 0x8009C2AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_layout(rdram, ctx);
        goto after_0;
    // 0x8009C2AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8009C2B0: jal         0x80066828
    // 0x8009C2B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_active_camera(rdram, ctx);
        goto after_1;
    // 0x8009C2B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8009C2B8: jal         0x80069F60
    // 0x8009C2BC: nop

    cam_get_active_camera(rdram, ctx);
        goto after_2;
    // 0x8009C2BC: nop

    after_2:
    // 0x8009C2C0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8009C2C4: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x8009C2C8: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    // 0x8009C2CC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8009C2D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009C2D4: sh          $t7, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r15;
    // 0x8009C2D8: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8009C2DC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8009C2E0: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
    // 0x8009C2E4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009C2E8: addiu       $t9, $zero, -0x8000
    ctx->r25 = ADD32(0, -0X8000);
    // 0x8009C2EC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8009C2F0: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009C2F4: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x8009C2F8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8009C2FC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009C300: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8009C304: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8009C308: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8009C30C: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8009C310: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8009C314: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8009C318: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x8009C31C: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x8009C320: jal         0x8001D614
    // 0x8009C324: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    update_envmap_position(rdram, ctx);
        goto after_3;
    // 0x8009C324: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8009C328: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009C32C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009C330: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8009C334: jal         0x80066F1C
    // 0x8009C338: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    viewport_main(rdram, ctx);
        goto after_4;
    // 0x8009C338: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_4:
    // 0x8009C33C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8009C340: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x8009C344: nop

    // 0x8009C348: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x8009C34C: lh          $t1, 0x28($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X28);
    // 0x8009C350: nop

    // 0x8009C354: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x8009C358: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x8009C35C: nop

    // 0x8009C360: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x8009C364: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8009C368: nop

    // 0x8009C36C: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x8009C370: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8009C374: nop

    // 0x8009C378: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x8009C37C: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8009C380: nop

    // 0x8009C384: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x8009C388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C38C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009C390: jr          $ra
    // 0x8009C394: nop

    return;
    // 0x8009C394: nop

;}
RECOMP_FUNC void cheatmenu_checksum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B1FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008B200: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008B204: lw          $t6, 0x2398($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2398);
    // 0x8008B208: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008B20C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008B210: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008B214: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008B218: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008B21C: bne         $t6, $zero, L_8008B30C
    if (ctx->r14 != 0) {
        // 0x8008B220: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8008B30C;
    }
    // 0x8008B220: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B224: lui         $s0, 0xB9
    ctx->r16 = S32(0XB9 << 16);
    // 0x8008B228: addiu       $s0, $s0, -0x3030
    ctx->r16 = ADD32(ctx->r16, -0X3030);
    // 0x8008B22C: addiu       $s0, $s0, -0x1000
    ctx->r16 = ADD32(ctx->r16, -0X1000);
    // 0x8008B230: addiu       $s3, $zero, 0x1000
    ctx->r19 = ADD32(0, 0X1000);
    // 0x8008B234: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x8008B238: addiu       $a0, $zero, 0x5000
    ctx->r4 = ADD32(0, 0X5000);
    // 0x8008B23C: jal         0x80070EDC
    // 0x8008B240: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8008B240: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_0:
    // 0x8008B244: beq         $s0, $zero, L_8008B2F8
    if (ctx->r16 == 0) {
        // 0x8008B248: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8008B2F8;
    }
    // 0x8008B248: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_8008B24C:
    // 0x8008B24C: slti        $at, $s2, 0x5001
    ctx->r1 = SIGNED(ctx->r18) < 0X5001 ? 1 : 0;
    // 0x8008B250: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x8008B254: bne         $at, $zero, L_8008B260
    if (ctx->r1 != 0) {
        // 0x8008B258: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8008B260;
    }
    // 0x8008B258: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008B25C: addiu       $s1, $zero, 0x5000
    ctx->r17 = ADD32(0, 0X5000);
L_8008B260:
    // 0x8008B260: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008B264: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8008B268: jal         0x80077370
    // 0x8008B26C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    dmacopy(rdram, ctx);
        goto after_1;
    // 0x8008B26C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x8008B270: blez        $s1, L_8008B2F0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8008B274: subu        $s2, $s2, $s1
        ctx->r18 = SUB32(ctx->r18, ctx->r17);
            goto L_8008B2F0;
    }
    // 0x8008B274: subu        $s2, $s2, $s1
    ctx->r18 = SUB32(ctx->r18, ctx->r17);
    // 0x8008B278: andi        $a0, $s1, 0x3
    ctx->r4 = ctx->r17 & 0X3;
    // 0x8008B27C: beq         $a0, $zero, L_8008B2B0
    if (ctx->r4 == 0) {
        // 0x8008B280: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8008B2B0;
    }
    // 0x8008B280: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8008B284: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008B288: lw          $a1, 0x2394($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2394);
    // 0x8008B28C: addu        $v0, $s4, $s0
    ctx->r2 = ADD32(ctx->r20, ctx->r16);
L_8008B290:
    // 0x8008B290: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8008B294: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008B298: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B29C: bne         $v1, $s0, L_8008B290
    if (ctx->r3 != ctx->r16) {
        // 0x8008B2A0: addu        $a1, $a1, $t7
        ctx->r5 = ADD32(ctx->r5, ctx->r15);
            goto L_8008B290;
    }
    // 0x8008B2A0: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8008B2A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B2A8: beq         $s0, $s1, L_8008B2F0
    if (ctx->r16 == ctx->r17) {
        // 0x8008B2AC: sw          $a1, 0x2394($at)
        MEM_W(0X2394, ctx->r1) = ctx->r5;
            goto L_8008B2F0;
    }
    // 0x8008B2AC: sw          $a1, 0x2394($at)
    MEM_W(0X2394, ctx->r1) = ctx->r5;
L_8008B2B0:
    // 0x8008B2B0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008B2B4: lw          $a1, 0x2394($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2394);
    // 0x8008B2B8: addu        $v0, $s4, $s0
    ctx->r2 = ADD32(ctx->r20, ctx->r16);
L_8008B2BC:
    // 0x8008B2BC: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8008B2C0: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8008B2C4: lbu         $t0, 0x2($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2);
    // 0x8008B2C8: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8008B2CC: lbu         $t1, 0x3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X3);
    // 0x8008B2D0: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8008B2D4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008B2D8: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x8008B2DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008B2E0: bne         $s0, $s1, L_8008B2BC
    if (ctx->r16 != ctx->r17) {
        // 0x8008B2E4: addu        $a1, $a1, $t1
        ctx->r5 = ADD32(ctx->r5, ctx->r9);
            goto L_8008B2BC;
    }
    // 0x8008B2E4: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x8008B2E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B2EC: sw          $a1, 0x2394($at)
    MEM_W(0X2394, ctx->r1) = ctx->r5;
L_8008B2F0:
    // 0x8008B2F0: bne         $s2, $zero, L_8008B24C
    if (ctx->r18 != 0) {
        // 0x8008B2F4: addu        $s3, $s3, $s1
        ctx->r19 = ADD32(ctx->r19, ctx->r17);
            goto L_8008B24C;
    }
    // 0x8008B2F4: addu        $s3, $s3, $s1
    ctx->r19 = ADD32(ctx->r19, ctx->r17);
L_8008B2F8:
    // 0x8008B2F8: jal         0x80071380
    // 0x8008B2FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mempool_free(rdram, ctx);
        goto after_2;
    // 0x8008B2FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x8008B300: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008B304: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B308: sw          $t2, 0x2398($at)
    MEM_W(0X2398, ctx->r1) = ctx->r10;
L_8008B30C:
    // 0x8008B30C: lui         $s0, 0xB9
    ctx->r16 = S32(0XB9 << 16);
    // 0x8008B310: addiu       $s0, $s0, -0x3030
    ctx->r16 = ADD32(ctx->r16, -0X3030);
    // 0x8008B314: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008B318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B31C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008B320: jal         0x800B6814
    // 0x8008B324: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_render_printf_background_colour(rdram, ctx);
        goto after_3;
    // 0x8008B324: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_3:
    // 0x8008B328: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8008B32C: jal         0x800B68BC
    // 0x8008B330: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    set_render_printf_position(rdram, ctx);
        goto after_4;
    // 0x8008B330: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    after_4:
    // 0x8008B334: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008B338: lw          $a1, 0x2394($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2394);
    // 0x8008B33C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008B340: addiu       $a0, $a0, -0x7858
    ctx->r4 = ADD32(ctx->r4, -0X7858);
    // 0x8008B344: jal         0x800B643C
    // 0x8008B348: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    render_printf(rdram, ctx);
        goto after_5;
    // 0x8008B348: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x8008B34C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B350: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B354: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B358: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008B35C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008B360: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008B364: jr          $ra
    // 0x8008B368: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008B368: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void lensflare_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACDC0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ACDC4: lw          $t6, 0x3010($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3010);
    // 0x800ACDC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACDCC: beq         $t6, $zero, L_800ACDD8
    if (ctx->r14 == 0) {
        // 0x800ACDD0: nop
    
            goto L_800ACDD8;
    }
    // 0x800ACDD0: nop

    // 0x800ACDD4: sw          $zero, 0x3014($at)
    MEM_W(0X3014, ctx->r1) = 0;
L_800ACDD8:
    // 0x800ACDD8: jr          $ra
    // 0x800ACDDC: nop

    return;
    // 0x800ACDDC: nop

;}
RECOMP_FUNC void render_misc_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011960: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80011964: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80011968: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001196C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80011970: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80011974: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80011978: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001197C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80011980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80011984: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80011988: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001198C: addiu       $a0, $a0, -0x4BF4
    ctx->r4 = ADD32(ctx->r4, -0X4BF4);
    // 0x80011990: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80011994: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80011998: jal         0x800696C4
    // 0x8001199C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_0;
    // 0x8001199C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800119A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800119A4: addiu       $a0, $a0, -0x4BF4
    ctx->r4 = ADD32(ctx->r4, -0X4BF4);
    // 0x800119A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800119AC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800119B0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800119B4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800119B8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800119BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800119C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800119C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800119C8: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x800119CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800119D0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800119D4: addiu       $t3, $zero, -0x100
    ctx->r11 = ADD32(0, -0X100);
    // 0x800119D8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800119DC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800119E0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800119E4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800119E8: beq         $t4, $zero, L_800119F8
    if (ctx->r12 == 0) {
        // 0x800119EC: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_800119F8;
    }
    // 0x800119EC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800119F0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800119F4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_800119F8:
    // 0x800119F8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800119FC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80011A00: jal         0x8007B938
    // 0x80011A04: nop

    material_set(rdram, ctx);
        goto after_1;
    // 0x80011A04: nop

    after_1:
    // 0x80011A08: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80011A0C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80011A10: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80011A14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80011A18: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x80011A1C: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    // 0x80011A20: addiu       $a0, $a0, -0x4BF4
    ctx->r4 = ADD32(ctx->r4, -0X4BF4);
    // 0x80011A24: andi        $t2, $a1, 0x6
    ctx->r10 = ctx->r5 & 0X6;
    // 0x80011A28: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80011A2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80011A30: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80011A34: sll         $t7, $t1, 3
    ctx->r15 = S32(ctx->r9 << 3);
    // 0x80011A38: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x80011A3C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80011A40: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80011A44: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011A48: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80011A4C: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80011A50: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80011A54: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80011A58: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80011A5C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80011A60: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x80011A64: or          $t4, $t6, $t3
    ctx->r12 = ctx->r14 | ctx->r11;
    // 0x80011A68: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80011A6C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80011A70: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80011A74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80011A78: addiu       $t7, $a3, -0x1
    ctx->r15 = ADD32(ctx->r7, -0X1);
    // 0x80011A7C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80011A80: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x80011A84: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80011A88: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80011A8C: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x80011A90: sll         $t3, $t6, 16
    ctx->r11 = S32(ctx->r14 << 16);
    // 0x80011A94: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80011A98: sll         $t5, $a3, 4
    ctx->r13 = S32(ctx->r7 << 4);
    // 0x80011A9C: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x80011AA0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80011AA4: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80011AA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011AAC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80011AB0: nop

    // 0x80011AB4: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80011AB8: jal         0x80069C80
    // 0x80011ABC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    mtx_pop(rdram, ctx);
        goto after_2;
    // 0x80011ABC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    after_2:
    // 0x80011AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80011AC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80011AC8: jr          $ra
    // 0x80011ACC: nop

    return;
    // 0x80011ACC: nop

;}
RECOMP_FUNC void is_in_adventure_two(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F1B4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009F1B8: lw          $v0, -0x5EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5EC);
    // 0x8009F1BC: jr          $ra
    // 0x8009F1C0: nop

    return;
    // 0x8009F1C0: nop

;}
RECOMP_FUNC void fb_swap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AFEC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AFF0: addiu       $a1, $a1, 0x6868
    ctx->r5 = ADD32(ctx->r5, 0X6868);
    // 0x8007AFF4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007AFF8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007AFFC: addiu       $a0, $a0, 0x6860
    ctx->r4 = ADD32(ctx->r4, 0X6860);
    // 0x8007B000: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8007B004: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8007B008: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007B00C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B010: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007B014: lw          $v1, -0x1310($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1310);
    // 0x8007B018: sw          $t8, 0x6878($at)
    MEM_W(0X6878, ctx->r1) = ctx->r24;
    // 0x8007B01C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B020: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007B024: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8007B028: sw          $v1, 0x6880($at)
    MEM_W(0X6880, ctx->r1) = ctx->r3;
    // 0x8007B02C: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x8007B030: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8007B034: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007B038: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B03C: sw          $t3, 0x6874($at)
    MEM_W(0X6874, ctx->r1) = ctx->r11;
    // 0x8007B040: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B044: jr          $ra
    // 0x8007B048: sw          $v1, 0x687C($at)
    MEM_W(0X687C, ctx->r1) = ctx->r3;
    return;
    // 0x8007B048: sw          $v1, 0x687C($at)
    MEM_W(0X687C, ctx->r1) = ctx->r3;
;}
RECOMP_FUNC void skydome_spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028004: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80028008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002800C: jal         0x8005A43C
    // 0x80028010: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    drm_checksum_balloon(rdram, ctx);
        goto after_0;
    // 0x80028010: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80028014: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80028018: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002801C: bne         $v0, $at, L_80028030
    if (ctx->r2 != ctx->r1) {
        // 0x80028020: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80028030;
    }
    // 0x80028020: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80028024: addiu       $a0, $a0, -0x49C8
    ctx->r4 = ADD32(ctx->r4, -0X49C8);
    // 0x80028028: b           L_80028074
    // 0x8002802C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_80028074;
    // 0x8002802C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80028030:
    // 0x80028030: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80028034: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
    // 0x80028038: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // 0x8002803C: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // 0x80028040: sb          $t6, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r14;
    // 0x80028044: sb          $v0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r2;
    // 0x80028048: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002804C: jal         0x8000EA54
    // 0x80028050: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    spawn_object(rdram, ctx);
        goto after_1;
    // 0x80028050: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80028054: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80028058: addiu       $a0, $a0, -0x49C8
    ctx->r4 = ADD32(ctx->r4, -0X49C8);
    // 0x8002805C: beq         $v0, $zero, L_80028074
    if (ctx->r2 == 0) {
        // 0x80028060: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80028074;
    }
    // 0x80028060: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80028064: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80028068: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8002806C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80028070: sh          $t7, 0x4A($t8)
    MEM_H(0X4A, ctx->r24) = ctx->r15;
L_80028074:
    // 0x80028074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002807C: jr          $ra
    // 0x80028080: nop

    return;
    // 0x80028080: nop

;}
RECOMP_FUNC void bgdraw_texture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800785E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800785E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800785E8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800785EC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800785F0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800785F4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800785F8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800785FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80078600: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80078604: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80078608: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007860C: jal         0x8007A970
    // 0x80078610: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80078610: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80078614: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80078618: sra         $t0, $v0, 16
    ctx->r8 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007861C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078620: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80078624: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078628: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007862C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80078630: andi        $t6, $t0, 0xFFFF
    ctx->r14 = ctx->r8 & 0XFFFF;
    // 0x80078634: addiu       $t9, $t9, -0x14E8
    ctx->r25 = ADD32(ctx->r25, -0X14E8);
    // 0x80078638: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8007863C: addiu       $t2, $t2, -0x15B8
    ctx->r10 = ADD32(ctx->r10, -0X15B8);
    // 0x80078640: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x80078644: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078648: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007864C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80078650: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80078654: bne         $t6, $zero, L_80078818
    if (ctx->r14 != 0) {
        // 0x80078658: addiu       $t1, $t1, -0x15BC
        ctx->r9 = ADD32(ctx->r9, -0X15BC);
            goto L_80078818;
    }
    // 0x80078658: addiu       $t1, $t1, -0x15BC
    ctx->r9 = ADD32(ctx->r9, -0X15BC);
    // 0x8007865C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078660: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80078664: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078668: addiu       $t1, $t1, -0x15BC
    ctx->r9 = ADD32(ctx->r9, -0X15BC);
    // 0x8007866C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078670: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80078674: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80078678: lh          $a3, 0xA($t8)
    ctx->r7 = MEM_H(ctx->r24, 0XA);
    // 0x8007867C: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x80078680: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x80078684: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80078688: sll         $t8, $a3, 3
    ctx->r24 = S32(ctx->r7 << 3);
    // 0x8007868C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80078690: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80078694: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80078698: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007869C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800786A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800786A4: lw          $t7, 0xC($t8)
    ctx->r15 = MEM_W(ctx->r24, 0XC);
    // 0x800786A8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800786AC: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x800786B0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800786B4: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x800786B8: sll         $s6, $t0, 2
    ctx->r22 = S32(ctx->r8 << 2);
    // 0x800786BC: lbu         $s0, 0x0($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X0);
    // 0x800786C0: lbu         $s4, 0x1($a2)
    ctx->r20 = MEM_BU(ctx->r6, 0X1);
    // 0x800786C4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800786C8: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x800786CC: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800786D0: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800786D4: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x800786D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800786DC: blez        $s6, L_80078B80
    if (SIGNED(ctx->r22) <= 0) {
        // 0x800786E0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80078B80;
    }
    // 0x800786E0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800786E4: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800786E8: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800786EC: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x800786F0: addiu       $s7, $s7, -0x15C0
    ctx->r23 = ADD32(ctx->r23, -0X15C0);
    // 0x800786F4: addiu       $s5, $t8, -0x1
    ctx->r21 = ADD32(ctx->r24, -0X1);
    // 0x800786F8: lui         $t5, 0xB200
    ctx->r13 = S32(0XB200 << 16);
    // 0x800786FC: lui         $t4, 0xB300
    ctx->r12 = S32(0XB300 << 16);
    // 0x80078700: lui         $t3, 0xE400
    ctx->r11 = S32(0XE400 << 16);
L_80078704:
    // 0x80078704: negu        $v0, $s3
    ctx->r2 = SUB32(0, ctx->r19);
    // 0x80078708: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8007870C: beq         $at, $zero, L_800787F8
    if (ctx->r1 == 0) {
        // 0x80078710: addu        $t1, $s2, $s4
        ctx->r9 = ADD32(ctx->r18, ctx->r20);
            goto L_800787F8;
    }
    // 0x80078710: addu        $t1, $s2, $s4
    ctx->r9 = ADD32(ctx->r18, ctx->r20);
    // 0x80078714: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x80078718: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8007871C: andi        $t2, $s2, 0xFFF
    ctx->r10 = ctx->r18 & 0XFFF;
L_80078720:
    // 0x80078720: bgez        $v0, L_8007878C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80078724: addu        $a2, $v0, $s0
        ctx->r6 = ADD32(ctx->r2, ctx->r16);
            goto L_8007878C;
    }
    // 0x80078724: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x80078728: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007872C: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x80078730: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x80078734: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078738: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007873C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80078740: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x80078744: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x80078748: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007874C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80078750: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078754: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80078758: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8007875C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078760: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x80078764: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80078768: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007876C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078770: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078774: nop

    // 0x80078778: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8007877C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078780: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80078784: b           L_800787EC
    // 0x80078788: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
        goto L_800787EC;
    // 0x80078788: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_8007878C:
    // 0x8007878C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078790: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x80078794: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80078798: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x8007879C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800787A0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800787A4: andi        $t6, $v0, 0xFFF
    ctx->r14 = ctx->r2 & 0XFFF;
    // 0x800787A8: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800787AC: or          $t9, $t7, $t1
    ctx->r25 = ctx->r15 | ctx->r9;
    // 0x800787B0: or          $t7, $t8, $t2
    ctx->r15 = ctx->r24 | ctx->r10;
    // 0x800787B4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800787B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800787BC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800787C0: nop

    // 0x800787C4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800787C8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800787CC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800787D0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800787D4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800787D8: nop

    // 0x800787DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800787E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800787E4: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x800787E8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800787EC:
    // 0x800787EC: slt         $at, $a2, $s1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800787F0: bne         $at, $zero, L_80078720
    if (ctx->r1 != 0) {
        // 0x800787F4: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80078720;
    }
    // 0x800787F4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800787F8:
    // 0x800787F8: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800787FC: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
    // 0x80078800: slt         $at, $s2, $s6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80078804: addu        $t7, $s3, $t8
    ctx->r15 = ADD32(ctx->r19, ctx->r24);
    // 0x80078808: bne         $at, $zero, L_80078704
    if (ctx->r1 != 0) {
        // 0x8007880C: and         $s3, $t7, $s5
        ctx->r19 = ctx->r15 & ctx->r21;
            goto L_80078704;
    }
    // 0x8007880C: and         $s3, $t7, $s5
    ctx->r19 = ctx->r15 & ctx->r21;
    // 0x80078810: b           L_80078B84
    // 0x80078814: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
        goto L_80078B84;
    // 0x80078814: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_80078818:
    // 0x80078818: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007881C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80078820: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078824: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078828: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8007882C: andi        $s1, $v0, 0xFFFF
    ctx->r17 = ctx->r2 & 0XFFFF;
    // 0x80078830: lh          $a3, 0xA($t6)
    ctx->r7 = MEM_H(ctx->r14, 0XA);
    // 0x80078834: sll         $s6, $t0, 2
    ctx->r22 = S32(ctx->r8 << 2);
    // 0x80078838: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x8007883C: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80078840: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x80078844: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80078848: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007884C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80078850: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80078854: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80078858: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007885C: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x80078860: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80078864: addu        $t8, $t9, $at
    ctx->r24 = ADD32(ctx->r25, ctx->r1);
    // 0x80078868: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007886C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80078870: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80078874: lbu         $s0, 0x0($a2)
    ctx->r16 = MEM_BU(ctx->r6, 0X0);
    // 0x80078878: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x8007887C: lbu         $s4, 0x1($a2)
    ctx->r20 = MEM_BU(ctx->r6, 0X1);
    // 0x80078880: lbu         $t7, 0x1($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X1);
    // 0x80078884: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80078888: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8007888C: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x80078890: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80078894: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80078898: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
    // 0x8007889C: addu        $fp, $t6, $t9
    ctx->r30 = ADD32(ctx->r14, ctx->r25);
    // 0x800788A0: blez        $s6, L_800789D8
    if (SIGNED(ctx->r22) <= 0) {
        // 0x800788A4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800789D8;
    }
    // 0x800788A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800788A8: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800788AC: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x800788B0: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x800788B4: addiu       $s7, $s7, -0x15C0
    ctx->r23 = ADD32(ctx->r23, -0X15C0);
    // 0x800788B8: addiu       $s5, $s0, -0x1
    ctx->r21 = ADD32(ctx->r16, -0X1);
    // 0x800788BC: lui         $t5, 0xB200
    ctx->r13 = S32(0XB200 << 16);
    // 0x800788C0: lui         $t4, 0xB300
    ctx->r12 = S32(0XB300 << 16);
    // 0x800788C4: lui         $t3, 0xE400
    ctx->r11 = S32(0XE400 << 16);
L_800788C8:
    // 0x800788C8: negu        $v0, $s3
    ctx->r2 = SUB32(0, ctx->r19);
    // 0x800788CC: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800788D0: beq         $at, $zero, L_800789BC
    if (ctx->r1 == 0) {
        // 0x800788D4: addu        $t1, $s2, $s4
        ctx->r9 = ADD32(ctx->r18, ctx->r20);
            goto L_800789BC;
    }
    // 0x800788D4: addu        $t1, $s2, $s4
    ctx->r9 = ADD32(ctx->r18, ctx->r20);
    // 0x800788D8: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x800788DC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x800788E0: andi        $t2, $s2, 0xFFF
    ctx->r10 = ctx->r18 & 0XFFF;
L_800788E4:
    // 0x800788E4: bgez        $v0, L_80078950
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800788E8: addu        $a2, $v0, $s0
        ctx->r6 = ADD32(ctx->r2, ctx->r16);
            goto L_80078950;
    }
    // 0x800788E8: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x800788EC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800788F0: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x800788F4: andi        $t7, $a2, 0xFFF
    ctx->r15 = ctx->r6 & 0XFFF;
    // 0x800788F8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800788FC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078900: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x80078904: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x80078908: or          $t8, $t9, $t1
    ctx->r24 = ctx->r25 | ctx->r9;
    // 0x8007890C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078910: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80078914: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078918: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8007891C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078920: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078924: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x80078928: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8007892C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078930: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078934: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078938: nop

    // 0x8007893C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078940: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078944: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80078948: b           L_800789B0
    // 0x8007894C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
        goto L_800789B0;
    // 0x8007894C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80078950:
    // 0x80078950: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078954: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x80078958: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8007895C: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x80078960: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078964: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078968: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x8007896C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80078970: or          $t9, $t6, $t1
    ctx->r25 = ctx->r14 | ctx->r9;
    // 0x80078974: or          $t6, $t7, $t2
    ctx->r14 = ctx->r15 | ctx->r10;
    // 0x80078978: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007897C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078980: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078984: nop

    // 0x80078988: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007898C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078990: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078994: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078998: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007899C: nop

    // 0x800789A0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800789A4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800789A8: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x800789AC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800789B0:
    // 0x800789B0: slt         $at, $a2, $s1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800789B4: bne         $at, $zero, L_800788E4
    if (ctx->r1 != 0) {
        // 0x800789B8: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800788E4;
    }
    // 0x800789B8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800789BC:
    // 0x800789BC: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800789C0: addu        $s2, $s2, $fp
    ctx->r18 = ADD32(ctx->r18, ctx->r30);
    // 0x800789C4: slt         $at, $s2, $s6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x800789C8: addu        $t6, $s3, $t7
    ctx->r14 = ADD32(ctx->r19, ctx->r15);
    // 0x800789CC: bne         $at, $zero, L_800788C8
    if (ctx->r1 != 0) {
        // 0x800789D0: and         $s3, $t6, $s5
        ctx->r19 = ctx->r14 & ctx->r21;
            goto L_800788C8;
    }
    // 0x800789D0: and         $s3, $t6, $s5
    ctx->r19 = ctx->r14 & ctx->r21;
    // 0x800789D4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800789D8:
    // 0x800789D8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800789DC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800789E0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800789E4: addiu       $a2, $a2, -0x15B8
    ctx->r6 = ADD32(ctx->r6, -0X15B8);
    // 0x800789E8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800789EC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800789F0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800789F4: lh          $a1, 0xA($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XA);
    // 0x800789F8: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x800789FC: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80078A00: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80078A04: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x80078A08: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x80078A0C: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80078A10: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80078A14: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80078A18: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80078A1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80078A20: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80078A24: sll         $t8, $s6, 2
    ctx->r24 = S32(ctx->r22 << 2);
    // 0x80078A28: addu        $t7, $t9, $at
    ctx->r15 = ADD32(ctx->r25, ctx->r1);
    // 0x80078A2C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078A30: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80078A34: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x80078A38: lbu         $s4, 0x1($t9)
    ctx->r20 = MEM_BU(ctx->r25, 0X1);
    // 0x80078A3C: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80078A40: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80078A44: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80078A48: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80078A4C: addiu       $s7, $s7, -0x15C0
    ctx->r23 = ADD32(ctx->r23, -0X15C0);
    // 0x80078A50: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x80078A54: lui         $t3, 0xE400
    ctx->r11 = S32(0XE400 << 16);
    // 0x80078A58: lui         $t4, 0xB300
    ctx->r12 = S32(0XB300 << 16);
    // 0x80078A5C: lui         $t5, 0xB200
    ctx->r13 = S32(0XB200 << 16);
    // 0x80078A60: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x80078A64: or          $s6, $t8, $zero
    ctx->r22 = ctx->r24 | 0;
    // 0x80078A68: beq         $at, $zero, L_80078B80
    if (ctx->r1 == 0) {
        // 0x80078A6C: or          $s4, $t7, $zero
        ctx->r20 = ctx->r15 | 0;
            goto L_80078B80;
    }
    // 0x80078A6C: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x80078A70: addiu       $s5, $s0, -0x1
    ctx->r21 = ADD32(ctx->r16, -0X1);
L_80078A74:
    // 0x80078A74: negu        $v0, $s3
    ctx->r2 = SUB32(0, ctx->r19);
    // 0x80078A78: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80078A7C: beq         $at, $zero, L_80078B68
    if (ctx->r1 == 0) {
        // 0x80078A80: addu        $t1, $s2, $s4
        ctx->r9 = ADD32(ctx->r18, ctx->r20);
            goto L_80078B68;
    }
    // 0x80078A80: addu        $t1, $s2, $s4
    ctx->r9 = ADD32(ctx->r18, ctx->r20);
    // 0x80078A84: andi        $t6, $t1, 0xFFF
    ctx->r14 = ctx->r9 & 0XFFF;
    // 0x80078A88: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x80078A8C: andi        $t2, $s2, 0xFFF
    ctx->r10 = ctx->r18 & 0XFFF;
L_80078A90:
    // 0x80078A90: bgez        $v0, L_80078AFC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80078A94: addu        $a2, $v0, $s0
        ctx->r6 = ADD32(ctx->r2, ctx->r16);
            goto L_80078AFC;
    }
    // 0x80078A94: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x80078A98: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078A9C: addu        $a2, $v0, $s0
    ctx->r6 = ADD32(ctx->r2, ctx->r16);
    // 0x80078AA0: andi        $t9, $a2, 0xFFF
    ctx->r25 = ctx->r6 & 0XFFF;
    // 0x80078AA4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078AA8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078AAC: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80078AB0: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x80078AB4: or          $t8, $t6, $t1
    ctx->r24 = ctx->r14 | ctx->r9;
    // 0x80078AB8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078ABC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80078AC0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078AC4: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80078AC8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80078ACC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80078AD0: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80078AD4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80078AD8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80078ADC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078AE0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078AE4: nop

    // 0x80078AE8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80078AEC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078AF0: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80078AF4: b           L_80078B5C
    // 0x80078AF8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
        goto L_80078B5C;
    // 0x80078AF8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80078AFC:
    // 0x80078AFC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078B00: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x80078B04: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80078B08: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x80078B0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078B10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078B14: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x80078B18: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80078B1C: or          $t6, $t7, $t1
    ctx->r14 = ctx->r15 | ctx->r9;
    // 0x80078B20: or          $t7, $t9, $t2
    ctx->r15 = ctx->r25 | ctx->r10;
    // 0x80078B24: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078B28: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80078B2C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078B30: nop

    // 0x80078B34: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078B38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078B3C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078B40: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078B44: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80078B48: nop

    // 0x80078B4C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80078B50: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078B54: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80078B58: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80078B5C:
    // 0x80078B5C: slt         $at, $a2, $s1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80078B60: bne         $at, $zero, L_80078A90
    if (ctx->r1 != 0) {
        // 0x80078B64: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80078A90;
    }
    // 0x80078B64: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80078B68:
    // 0x80078B68: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80078B6C: addu        $s2, $s2, $fp
    ctx->r18 = ADD32(ctx->r18, ctx->r30);
    // 0x80078B70: slt         $at, $s2, $s6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80078B74: addu        $t7, $s3, $t9
    ctx->r15 = ADD32(ctx->r19, ctx->r25);
    // 0x80078B78: bne         $at, $zero, L_80078A74
    if (ctx->r1 != 0) {
        // 0x80078B7C: and         $s3, $t7, $s5
        ctx->r19 = ctx->r15 & ctx->r21;
            goto L_80078A74;
    }
    // 0x80078B7C: and         $s3, $t7, $s5
    ctx->r19 = ctx->r15 & ctx->r21;
L_80078B80:
    // 0x80078B80: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_80078B84:
    // 0x80078B84: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80078B88: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078B8C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80078B90: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078B94: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078B98: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80078B9C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80078BA0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80078BA4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80078BA8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80078BAC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80078BB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80078BB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80078BB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80078BBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80078BC0: jr          $ra
    // 0x80078BC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80078BC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void trophyround_adventure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80098748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009874C: jal         0x8006ECD0
    // 0x80098750: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80098750: nop

    after_0:
    // 0x80098754: lbu         $t6, 0x48($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X48);
    // 0x80098758: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009875C: sw          $t6, 0x1568($at)
    MEM_W(0X1568, ctx->r1) = ctx->r14;
    // 0x80098760: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098764: sw          $zero, 0x156C($at)
    MEM_W(0X156C, ctx->r1) = 0;
    // 0x80098768: lw          $t8, 0x4C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4C);
    // 0x8009876C: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x80098770: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098774: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80098778: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x8009877C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80098780: sb          $zero, 0xF($t9)
    MEM_B(0XF, ctx->r25) = 0;
    // 0x80098784: lw          $t0, 0x4C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4C);
    // 0x80098788: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009878C: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x80098790: jal         0x8000E4BC
    // 0x80098794: sb          $t1, -0x630($at)
    MEM_B(-0X630, ctx->r1) = ctx->r9;
    set_time_trial_enabled(rdram, ctx);
        goto after_1;
    // 0x80098794: sb          $t1, -0x630($at)
    MEM_B(-0X630, ctx->r1) = ctx->r9;
    after_1:
    // 0x80098798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009879C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800987A0: jr          $ra
    // 0x800987A4: nop

    return;
    // 0x800987A4: nop

;}
RECOMP_FUNC void rocket_prevent_overshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EC54: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003EC58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003EC5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003EC60: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8003EC64: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x8003EC68: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8003EC6C: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x8003EC70: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8003EC74: slti        $at, $t6, 0x50
    ctx->r1 = SIGNED(ctx->r14) < 0X50 ? 1 : 0;
    // 0x8003EC78: bne         $at, $zero, L_8003EC90
    if (ctx->r1 != 0) {
        // 0x8003EC7C: nop
    
            goto L_8003EC90;
    }
    // 0x8003EC7C: nop

    // 0x8003EC80: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x8003EC84: nop

    // 0x8003EC88: beq         $t7, $zero, L_8003ECC4
    if (ctx->r15 == 0) {
        // 0x8003EC8C: nop
    
            goto L_8003ECC4;
    }
    // 0x8003EC8C: nop

L_8003EC90:
    // 0x8003EC90: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8003EC94: nop

    // 0x8003EC98: beq         $a1, $zero, L_8003ECC4
    if (ctx->r5 == 0) {
        // 0x8003EC9C: nop
    
            goto L_8003ECC4;
    }
    // 0x8003EC9C: nop

    // 0x8003ECA0: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8003ECA4: nop

    // 0x8003ECA8: beq         $a1, $t8, L_8003ECC4
    if (ctx->r5 == ctx->r24) {
        // 0x8003ECAC: nop
    
            goto L_8003ECC4;
    }
    // 0x8003ECAC: nop

    // 0x8003ECB0: lh          $t9, 0x48($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X48);
    // 0x8003ECB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003ECB8: bne         $t9, $at, L_8003ECC4
    if (ctx->r25 != ctx->r1) {
        // 0x8003ECBC: nop
    
            goto L_8003ECC4;
    }
    // 0x8003ECBC: nop

    // 0x8003ECC0: sw          $a1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r5;
L_8003ECC4:
    // 0x8003ECC4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8003ECC8: nop

    // 0x8003ECCC: beq         $v0, $zero, L_8003EDFC
    if (ctx->r2 == 0) {
        // 0x8003ECD0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8003EDFC;
    }
    // 0x8003ECD0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8003ECD4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003ECD8: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8003ECDC: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003ECE0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003ECE4: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8003ECE8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003ECEC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003ECF0: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003ECF4: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8003ECF8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003ECFC: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003ED00: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8003ED04: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8003ED08: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003ED0C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003ED10: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8003ED14: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8003ED18: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003ED1C: jal         0x800CA030
    // 0x8003ED20: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8003ED20: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003ED24: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003ED28: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8003ED2C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8003ED30: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003ED34: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003ED38: bc1f        L_8003EDF8
    if (!c1cs) {
        // 0x8003ED3C: swc1        $f0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
            goto L_8003EDF8;
    }
    // 0x8003ED3C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8003ED40: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8003ED44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003ED48: nop

    // 0x8003ED4C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8003ED50: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003ED54: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8003ED58: jal         0x80070990
    // 0x8003ED5C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_1;
    // 0x8003ED5C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_1:
    // 0x8003ED60: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003ED64: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8003ED68: lh          $t1, 0x0($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X0);
    // 0x8003ED6C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8003ED70: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
    // 0x8003ED74: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8003ED78: subu        $a0, $a2, $t2
    ctx->r4 = SUB32(ctx->r6, ctx->r10);
    // 0x8003ED7C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003ED80: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8003ED84: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003ED88: bne         $at, $zero, L_8003ED98
    if (ctx->r1 != 0) {
        // 0x8003ED8C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003ED98;
    }
    // 0x8003ED8C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003ED90: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003ED94: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_8003ED98:
    // 0x8003ED98: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x8003ED9C: beq         $at, $zero, L_8003EDA8
    if (ctx->r1 == 0) {
        // 0x8003EDA0: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003EDA8;
    }
    // 0x8003EDA0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003EDA4: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_8003EDA8:
    // 0x8003EDA8: slti        $at, $a0, 0x6001
    ctx->r1 = SIGNED(ctx->r4) < 0X6001 ? 1 : 0;
    // 0x8003EDAC: beq         $at, $zero, L_8003EDBC
    if (ctx->r1 == 0) {
        // 0x8003EDB0: slti        $at, $a0, -0x6000
        ctx->r1 = SIGNED(ctx->r4) < -0X6000 ? 1 : 0;
            goto L_8003EDBC;
    }
    // 0x8003EDB0: slti        $at, $a0, -0x6000
    ctx->r1 = SIGNED(ctx->r4) < -0X6000 ? 1 : 0;
    // 0x8003EDB4: beq         $at, $zero, L_8003EDD4
    if (ctx->r1 == 0) {
        // 0x8003EDB8: nop
    
            goto L_8003EDD4;
    }
    // 0x8003EDB8: nop

L_8003EDBC:
    // 0x8003EDBC: lw          $t3, 0x4C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X4C);
    // 0x8003EDC0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003EDC4: sw          $a1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r5;
    // 0x8003EDC8: lw          $t5, 0x4C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4C);
    // 0x8003EDCC: nop

    // 0x8003EDD0: sb          $t4, 0x13($t5)
    MEM_B(0X13, ctx->r13) = ctx->r12;
L_8003EDD4:
    // 0x8003EDD4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8003EDD8: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003EDDC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003EDE0: jal         0x80070990
    // 0x8003EDE4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x8003EDE4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x8003EDE8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003EDEC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003EDF0: sh          $v0, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r2;
    // 0x8003EDF4: sh          $a2, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r6;
L_8003EDF8:
    // 0x8003EDF8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8003EDFC:
    // 0x8003EDFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003EE00: jal         0x8003F138
    // 0x8003EE04: addiu       $a2, $zero, 0x137
    ctx->r6 = ADD32(0, 0X137);
    play_rocket_trailing_sound(rdram, ctx);
        goto after_3;
    // 0x8003EE04: addiu       $a2, $zero, 0x137
    ctx->r6 = ADD32(0, 0X137);
    after_3:
    // 0x8003EE08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003EE0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003EE10: jr          $ra
    // 0x8003EE14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003EE14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void audspat_jingle_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008168: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000816C: jr          $ra
    // 0x80008170: sb          $zero, -0x4E68($at)
    MEM_B(-0X4E68, ctx->r1) = 0;
    return;
    // 0x80008170: sb          $zero, -0x4E68($at)
    MEM_B(-0X4E68, ctx->r1) = 0;
;}
RECOMP_FUNC void race_calc_distance_to_start_line(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B988: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B98C: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
    // 0x8001B990: nop

    // 0x8001B994: bgtz        $v0, L_8001B9A8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001B998: nop
    
            goto L_8001B9A8;
    }
    // 0x8001B998: nop

    // 0x8001B99C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001B9A0: jr          $ra
    // 0x8001B9A4: nop

    return;
    // 0x8001B9A4: nop

L_8001B9A8:
    // 0x8001B9A8: lb          $a1, 0x192($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X192);
    // 0x8001B9AC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001B9B0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001B9B4: beq         $at, $zero, L_8001B9EC
    if (ctx->r1 == 0) {
        // 0x8001B9B8: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8001B9EC;
    }
    // 0x8001B9B8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8001B9BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B9C0: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8001B9C4: lw          $t6, -0x4BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BB4);
    // 0x8001B9C8: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8001B9CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001B9D0: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
L_8001B9D4:
    // 0x8001B9D4: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x8001B9D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001B9DC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001B9E0: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    // 0x8001B9E4: bne         $at, $zero, L_8001B9D4
    if (ctx->r1 != 0) {
        // 0x8001B9E8: add.s       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_8001B9D4;
    }
    // 0x8001B9E8: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
L_8001B9EC:
    // 0x8001B9EC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B9F0: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8001B9F4: lw          $a2, -0x4BB4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4BB4);
    // 0x8001B9F8: bgez        $v1, L_8001BA08
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001B9FC: sll         $t8, $v1, 4
        ctx->r24 = S32(ctx->r3 << 4);
            goto L_8001BA08;
    }
    // 0x8001B9FC: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x8001BA00: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8001BA04: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
L_8001BA08:
    // 0x8001BA08: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8001BA0C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001BA10: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8001BA14: lwc1        $f6, 0x20($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8001BA18: lwc1        $f8, 0xA8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x8001BA1C: nop

    // 0x8001BA20: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001BA24: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8001BA28: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001BA2C: jr          $ra
    // 0x8001BA30: nop

    return;
    // 0x8001BA30: nop

;}
RECOMP_FUNC void mempool_alloc_safe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070EDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80070EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070EE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80070EE8: bne         $a0, $zero, L_80070F0C
    if (ctx->r4 != 0) {
        // 0x80070EEC: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80070F0C;
    }
    // 0x80070EEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80070EF0: jal         0x800B8230
    // 0x80070EF4: nop

    stack_pointer(rdram, ctx);
        goto after_0;
    // 0x80070EF4: nop

    after_0:
    // 0x80070EF8: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80070EFC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80070F00: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80070F04: jal         0x800B7980
    // 0x80070F08: nop

    dump_memory_to_cpak(rdram, ctx);
        goto after_1;
    // 0x80070F08: nop

    after_1:
L_80070F0C:
    // 0x80070F0C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80070F10: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80070F14: jal         0x80070F7C
    // 0x80070F18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_slot_find(rdram, ctx);
        goto after_2;
    // 0x80070F18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80070F1C: bne         $v0, $zero, L_80070F40
    if (ctx->r2 != 0) {
        // 0x80070F20: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80070F40;
    }
    // 0x80070F20: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80070F24: jal         0x800B8230
    // 0x80070F28: nop

    stack_pointer(rdram, ctx);
        goto after_3;
    // 0x80070F28: nop

    after_3:
    // 0x80070F2C: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80070F30: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80070F34: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80070F38: jal         0x800B7980
    // 0x80070F3C: nop

    dump_memory_to_cpak(rdram, ctx);
        goto after_4;
    // 0x80070F3C: nop

    after_4:
L_80070F40:
    // 0x80070F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070F44: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80070F48: jr          $ra
    // 0x80070F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80070F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void free_particle_vertices_triangles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE998: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE99C: lw          $a0, 0x3270($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3270);
    // 0x800AE9A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE9A4: beq         $a0, $zero, L_800AE9BC
    if (ctx->r4 == 0) {
        // 0x800AE9A8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE9BC;
    }
    // 0x800AE9A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE9AC: jal         0x80071380
    // 0x800AE9B0: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AE9B0: nop

    after_0:
    // 0x800AE9B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE9B8: sw          $zero, 0x3270($at)
    MEM_W(0X3270, ctx->r1) = 0;
L_800AE9BC:
    // 0x800AE9BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE9C0: lw          $a0, 0x3274($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3274);
    // 0x800AE9C4: nop

    // 0x800AE9C8: beq         $a0, $zero, L_800AE9E4
    if (ctx->r4 == 0) {
        // 0x800AE9CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AE9E4;
    }
    // 0x800AE9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE9D0: jal         0x80071380
    // 0x800AE9D4: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AE9D4: nop

    after_1:
    // 0x800AE9D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE9DC: sw          $zero, 0x3274($at)
    MEM_W(0X3274, ctx->r1) = 0;
    // 0x800AE9E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AE9E4:
    // 0x800AE9E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE9E8: jr          $ra
    // 0x800AE9EC: nop

    return;
    // 0x800AE9EC: nop

;}
RECOMP_FUNC void asset_table_load_zipped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076FB0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80076FB4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80076FB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80076FBC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80076FC0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076FC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80076FC8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80076FCC: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80076FD0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80076FD4: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80076FD8: jal         0x800C9110
    // 0x80076FDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80076FDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80076FE0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80076FE4: lw          $v1, 0x4830($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4830);
    // 0x80076FE8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80076FEC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80076FF0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80076FF4: sltu        $at, $t6, $a3
    ctx->r1 = ctx->r14 < ctx->r7 ? 1 : 0;
    // 0x80076FF8: beq         $at, $zero, L_80077008
    if (ctx->r1 == 0) {
        // 0x80076FFC: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80077008;
    }
    // 0x80076FFC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80077000: b           L_800770D8
    // 0x80077004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800770D8;
    // 0x80077004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077008:
    // 0x80077008: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8007700C: addu        $s0, $t7, $v1
    ctx->r16 = ADD32(ctx->r15, ctx->r3);
    // 0x80077010: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80077014: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80077018: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8007701C: subu        $t9, $t8, $t0
    ctx->r25 = SUB32(ctx->r24, ctx->r8);
    // 0x80077020: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80077024: jal         0x80070EDC
    // 0x80077028: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80077028: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x8007702C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80077030: lui         $t1, 0xF
    ctx->r9 = S32(0XF << 16);
    // 0x80077034: addiu       $t1, $t1, -0x2E50
    ctx->r9 = ADD32(ctx->r9, -0X2E50);
    // 0x80077038: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x8007703C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80077040: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80077044: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80077048: jal         0x800773D4
    // 0x8007704C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    dmacopy_v1(rdram, ctx);
        goto after_2;
    // 0x8007704C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80077050: jal         0x800C670C
    // 0x80077054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    byteswap32(rdram, ctx);
        goto after_3;
    // 0x80077054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80077058: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8007705C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80077060: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80077064: jal         0x80071380
    // 0x80077068: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80077068: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    after_4:
    // 0x8007706C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80077070: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80077074: lui         $a1, 0x7F7F
    ctx->r5 = S32(0X7F7F << 16);
    // 0x80077078: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x8007707C: jal         0x80070EDC
    // 0x80077080: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x80077080: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_5:
    // 0x80077084: bne         $v0, $zero, L_80077094
    if (ctx->r2 != 0) {
        // 0x80077088: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80077094;
    }
    // 0x80077088: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007708C: b           L_800770D8
    // 0x80077090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800770D8;
    // 0x80077090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077094:
    // 0x80077094: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80077098: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8007709C: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800770A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800770A4: subu        $a3, $t7, $a2
    ctx->r7 = SUB32(ctx->r15, ctx->r6);
    // 0x800770A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800770AC: jal         0x800773D4
    // 0x800770B0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    dmacopy_v1(rdram, ctx);
        goto after_6;
    // 0x800770B0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_6:
    // 0x800770B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800770B8: jal         0x800C6778
    // 0x800770BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gzip_inflate(rdram, ctx);
        goto after_7;
    // 0x800770BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800770C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800770C4: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x800770C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800770CC: jal         0x800C9390
    // 0x800770D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x800770D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x800770D4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800770D8:
    // 0x800770D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800770DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800770E0: jr          $ra
    // 0x800770E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800770E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_init_treasuresucker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D078: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8003D07C: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x8003D080: lb          $t7, 0x8($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X8);
    // 0x8003D084: nop

    // 0x8003D088: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8003D08C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x8003D090: jr          $ra
    // 0x8003D094: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
    return;
    // 0x8003D094: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void racetype_demo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E148: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E14C: lb          $v0, -0x3374($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X3374);
    // 0x8000E150: jr          $ra
    // 0x8000E154: nop

    return;
    // 0x8000E154: nop

;}
RECOMP_FUNC void update_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030878: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003087C: blez        $a0, L_80030974
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80030880: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80030974;
    }
    // 0x80030880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030884: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80030888: addiu       $v1, $v1, -0x26F8
    ctx->r3 = ADD32(ctx->r3, -0X26F8);
L_8003088C:
    // 0x8003088C: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    // 0x80030890: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80030894: blez        $a1, L_8003096C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80030898: slt         $at, $a2, $a1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8003096C;
    }
    // 0x80030898: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003089C: beq         $at, $zero, L_8003092C
    if (ctx->r1 == 0) {
        // 0x800308A0: nop
    
            goto L_8003092C;
    }
    // 0x800308A0: nop

    // 0x800308A4: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x800308A8: lw          $t1, 0x18($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X18);
    // 0x800308AC: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800308B0: lw          $t5, 0x1C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X1C);
    // 0x800308B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800308B8: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x800308BC: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800308C0: mflo        $t8
    ctx->r24 = lo;
    // 0x800308C4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800308C8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800308CC: multu       $t1, $a2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800308D0: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x800308D4: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x800308D8: mflo        $t2
    ctx->r10 = lo;
    // 0x800308DC: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800308E0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800308E4: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800308E8: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x800308EC: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
    // 0x800308F0: mflo        $t7
    ctx->r15 = lo;
    // 0x800308F4: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x800308F8: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x800308FC: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030900: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x80030904: subu        $t6, $t7, $a2
    ctx->r14 = SUB32(ctx->r15, ctx->r6);
    // 0x80030908: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x8003090C: mflo        $t1
    ctx->r9 = lo;
    // 0x80030910: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x80030914: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x80030918: multu       $t3, $a2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003091C: mflo        $t5
    ctx->r13 = lo;
    // 0x80030920: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x80030924: b           L_8003096C
    // 0x80030928: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
        goto L_8003096C;
    // 0x80030928: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
L_8003092C:
    // 0x8003092C: lbu         $t9, 0x28($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X28);
    // 0x80030930: lbu         $t1, 0x29($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X29);
    // 0x80030934: lbu         $t3, 0x2A($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2A);
    // 0x80030938: lh          $t5, 0x2C($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2C);
    // 0x8003093C: lh          $t7, 0x2E($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2E);
    // 0x80030940: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80030944: sll         $t0, $t1, 16
    ctx->r8 = S32(ctx->r9 << 16);
    // 0x80030948: sll         $t2, $t3, 16
    ctx->r10 = S32(ctx->r11 << 16);
    // 0x8003094C: sll         $t4, $t5, 16
    ctx->r12 = S32(ctx->r13 << 16);
    // 0x80030950: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80030954: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80030958: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8003095C: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80030960: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x80030964: sw          $t6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r14;
    // 0x80030968: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
L_8003096C:
    // 0x8003096C: bne         $v0, $a0, L_8003088C
    if (ctx->r2 != ctx->r4) {
        // 0x80030970: addiu       $v1, $v1, 0x38
        ctx->r3 = ADD32(ctx->r3, 0X38);
            goto L_8003088C;
    }
    // 0x80030970: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
L_80030974:
    // 0x80030974: jr          $ra
    // 0x80030978: nop

    return;
    // 0x80030978: nop

;}
RECOMP_FUNC void aitable_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C208: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C20C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006C210: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006C214: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006C218: jal         0x8009C814
    // 0x8006C21C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8006C21C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x8006C220: bne         $v0, $zero, L_8006C268
    if (ctx->r2 != 0) {
        // 0x8006C224: nop
    
            goto L_8006C268;
    }
    // 0x8006C224: nop

    // 0x8006C228: jal         0x8006ECD0
    // 0x8006C22C: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x8006C22C: nop

    after_1:
    // 0x8006C230: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x8006C234: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8006C238: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006C23C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8006C240: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8006C244: nop

    // 0x8006C248: andi        $t1, $a3, 0x2
    ctx->r9 = ctx->r7 & 0X2;
    // 0x8006C24C: beq         $t1, $zero, L_8006C258
    if (ctx->r9 == 0) {
        // 0x8006C250: andi        $t2, $a3, 0x4
        ctx->r10 = ctx->r7 & 0X4;
            goto L_8006C258;
    }
    // 0x8006C250: andi        $t2, $a3, 0x4
    ctx->r10 = ctx->r7 & 0X4;
    // 0x8006C254: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8006C258:
    // 0x8006C258: beq         $t2, $zero, L_8006C26C
    if (ctx->r10 == 0) {
        // 0x8006C25C: nop
    
            goto L_8006C26C;
    }
    // 0x8006C25C: nop

    // 0x8006C260: b           L_8006C26C
    // 0x8006C264: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_8006C26C;
    // 0x8006C264: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_8006C268:
    // 0x8006C268: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_8006C26C:
    // 0x8006C26C: jal         0x80099B68
    // 0x8006C270: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_2;
    // 0x8006C270: nop

    after_2:
    // 0x8006C274: beq         $v0, $zero, L_8006C280
    if (ctx->r2 == 0) {
        // 0x8006C278: nop
    
            goto L_8006C280;
    }
    // 0x8006C278: nop

    // 0x8006C27C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_8006C280:
    // 0x8006C280: jal         0x8009F1B4
    // 0x8006C284: nop

    is_in_adventure_two(rdram, ctx);
        goto after_3;
    // 0x8006C284: nop

    after_3:
    // 0x8006C288: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8006C28C: beq         $v0, $zero, L_8006C2A4
    if (ctx->r2 == 0) {
        // 0x8006C290: addu        $t7, $s0, $t5
        ctx->r15 = ADD32(ctx->r16, ctx->r13);
            goto L_8006C2A4;
    }
    // 0x8006C290: addu        $t7, $s0, $t5
    ctx->r15 = ADD32(ctx->r16, ctx->r13);
    // 0x8006C294: addiu       $s0, $s0, 0x5
    ctx->r16 = ADD32(ctx->r16, 0X5);
    // 0x8006C298: sll         $t3, $s0, 24
    ctx->r11 = S32(ctx->r16 << 24);
    // 0x8006C29C: sra         $s0, $t3, 24
    ctx->r16 = S32(SIGNED(ctx->r11) >> 24);
    // 0x8006C2A0: addu        $t7, $s0, $t5
    ctx->r15 = ADD32(ctx->r16, ctx->r13);
L_8006C2A4:
    // 0x8006C2A4: lb          $s0, 0x0($t7)
    ctx->r16 = MEM_B(ctx->r15, 0X0);
    // 0x8006C2A8: jal         0x8009C850
    // 0x8006C2AC: nop

    get_filtered_cheats(rdram, ctx);
        goto after_4;
    // 0x8006C2AC: nop

    after_4:
    // 0x8006C2B0: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x8006C2B4: bgez        $t6, L_8006C2C0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006C2B8: nop
    
            goto L_8006C2C0;
    }
    // 0x8006C2B8: nop

    // 0x8006C2BC: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_8006C2C0:
    // 0x8006C2C0: jal         0x8006DC4C
    // 0x8006C2C4: nop

    get_game_mode(rdram, ctx);
        goto after_5;
    // 0x8006C2C4: nop

    after_5:
    // 0x8006C2C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C2CC: bne         $v0, $at, L_8006C2D8
    if (ctx->r2 != ctx->r1) {
        // 0x8006C2D0: nop
    
            goto L_8006C2D8;
    }
    // 0x8006C2D0: nop

    // 0x8006C2D4: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_8006C2D8:
    // 0x8006C2D8: jal         0x80076EE4
    // 0x8006C2DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    asset_table_load(rdram, ctx);
        goto after_6;
    // 0x8006C2DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8006C2E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C2E4: addiu       $t0, $t0, 0x16E0
    ctx->r8 = ADD32(ctx->r8, 0X16E0);
    // 0x8006C2E8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8006C2EC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8006C2F0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8006C2F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006C2F8: beq         $a0, $t8, L_8006C324
    if (ctx->r4 == ctx->r24) {
        // 0x8006C2FC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8006C324;
    }
    // 0x8006C2FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8006C300:
    // 0x8006C300: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C304: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8006C308: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8006C30C: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8006C310: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x8006C314: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8006C318: nop

    // 0x8006C31C: bne         $a0, $t4, L_8006C300
    if (ctx->r4 != ctx->r12) {
        // 0x8006C320: nop
    
            goto L_8006C300;
    }
    // 0x8006C320: nop

L_8006C324:
    // 0x8006C324: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8006C328: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x8006C32C: sra         $t7, $t5, 16
    ctx->r15 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8006C330: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8006C334: bne         $at, $zero, L_8006C340
    if (ctx->r1 != 0) {
        // 0x8006C338: lui         $a1, 0xFFFF
        ctx->r5 = S32(0XFFFF << 16);
            goto L_8006C340;
    }
    // 0x8006C338: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006C33C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006C340:
    // 0x8006C340: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8006C344: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x8006C348: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8006C34C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8006C350: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006C354: subu        $a0, $t8, $v1
    ctx->r4 = SUB32(ctx->r24, ctx->r3);
    // 0x8006C358: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8006C35C: jal         0x80070EDC
    // 0x8006C360: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x8006C360: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_7:
    // 0x8006C364: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006C368: addiu       $v1, $v1, 0x1740
    ctx->r3 = ADD32(ctx->r3, 0X1740);
    // 0x8006C36C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8006C370: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8006C374: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8006C378: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006C37C: jal         0x80077190
    // 0x8006C380: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_8;
    // 0x8006C380: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x8006C384: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C388: lw          $a0, 0x16E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E0);
    // 0x8006C38C: jal         0x80071380
    // 0x8006C390: nop

    mempool_free(rdram, ctx);
        goto after_9;
    // 0x8006C390: nop

    after_9:
    // 0x8006C394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C39C: jr          $ra
    // 0x8006C3A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006C3A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void unload_level_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DE24: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DE28: addiu       $v0, $v0, 0x3A94
    ctx->r2 = ADD32(ctx->r2, 0X3A94);
    // 0x8006DE2C: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8006DE30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DE34: bne         $t6, $zero, L_8006DE88
    if (ctx->r14 != 0) {
        // 0x8006DE38: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006DE88;
    }
    // 0x8006DE38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006DE3C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006DE40: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8006DE44: jal         0x800712F0
    // 0x8006DE48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006DE48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006DE4C: jal         0x8006C13C
    // 0x8006DE50: nop

    level_free(rdram, ctx);
        goto after_1;
    // 0x8006DE50: nop

    after_1:
    // 0x8006DE54: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006DE58: jal         0x800C06F8
    // 0x8006DE5C: addiu       $a0, $a0, -0x269C
    ctx->r4 = ADD32(ctx->r4, -0X269C);
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8006DE5C: addiu       $a0, $a0, -0x269C
    ctx->r4 = ADD32(ctx->r4, -0X269C);
    after_2:
    // 0x8006DE60: jal         0x800AE7D0
    // 0x8006DE64: nop

    reset_particles(rdram, ctx);
        goto after_3;
    // 0x8006DE64: nop

    after_3:
    // 0x8006DE68: jal         0x800A057C
    // 0x8006DE6C: nop

    hud_free(rdram, ctx);
        goto after_4;
    // 0x8006DE6C: nop

    after_4:
    // 0x8006DE70: jal         0x800C3624
    // 0x8006DE74: nop

    free_game_text_table(rdram, ctx);
        goto after_5;
    // 0x8006DE74: nop

    after_5:
    // 0x8006DE78: jal         0x800712F0
    // 0x8006DE7C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_6;
    // 0x8006DE7C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x8006DE80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DE84: addiu       $v0, $v0, 0x3A94
    ctx->r2 = ADD32(ctx->r2, 0X3A94);
L_8006DE88:
    // 0x8006DE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006DE8C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8006DE90: jr          $ra
    // 0x8006DE94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006DE94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void alSynFreeVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9E98: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x800C9E9C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800C9EA0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C9EA4: beql        $a2, $zero, L_800C9F34
    if (ctx->r6 == 0) {
        // 0x800C9EA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9F34;
    }
    goto skip_0;
    // 0x800C9EA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9EAC: lw          $t6, 0xD8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD8);
    // 0x800C9EB0: beql        $t6, $zero, L_800C9F1C
    if (ctx->r14 == 0) {
        // 0x800C9EB4: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800C9F1C;
    }
    goto skip_1;
    // 0x800C9EB4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    skip_1:
    // 0x800C9EB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C9EBC: jal         0x800658A8
    // 0x800C9EC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9EC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C9EC4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9EC8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C9ECC: beq         $v0, $zero, L_800C9F30
    if (ctx->r2 == 0) {
        // 0x800C9ED0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9F30;
    }
    // 0x800C9ED0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9ED4: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x800C9ED8: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800C9EDC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9EE0: lw          $t9, 0xD8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD8);
    // 0x800C9EE4: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x800C9EE8: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x800C9EEC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9EF0: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800C9EF4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800C9EF8: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800C9EFC: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800C9F00: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800C9F04: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9F08: jalr        $t9
    // 0x800C9F0C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9F0C: nop

    after_1:
    // 0x800C9F10: b           L_800C9F2C
    // 0x800C9F14: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_800C9F2C;
    // 0x800C9F14: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9F18: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800C9F1C:
    // 0x800C9F1C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800C9F20: jal         0x8006595C
    // 0x800C9F24: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    _freePVoice(rdram, ctx);
        goto after_2;
    // 0x800C9F24: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x800C9F28: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800C9F2C:
    // 0x800C9F2C: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
L_800C9F30:
    // 0x800C9F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9F34:
    // 0x800C9F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9F38: jr          $ra
    // 0x800C9F3C: nop

    return;
    // 0x800C9F3C: nop

;}
RECOMP_FUNC void func_8007FFEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008043C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80080440: addiu       $a2, $a2, 0x71EC
    ctx->r6 = ADD32(ctx->r6, 0X71EC);
    // 0x80080444: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80080448: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8008044C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80080450: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80080454: beq         $t6, $zero, L_80080464
    if (ctx->r14 == 0) {
        // 0x80080458: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80080464;
    }
    // 0x80080458: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008045C: jal         0x800803D8
    // 0x80080460: nop

    menu_button_free(rdram, ctx);
        goto after_0;
    // 0x80080460: nop

    after_0:
L_80080464:
    // 0x80080464: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80080468: multu       $s0, $t1
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008046C: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80080470: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x80080474: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80080478: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8008047C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80080480: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80080484: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080488: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x8008048C: sw          $v0, 0x2340($at)
    MEM_W(0X2340, ctx->r1) = ctx->r2;
    // 0x80080490: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080494: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
    // 0x80080498: mflo        $v1
    ctx->r3 = lo;
    // 0x8008049C: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x800804A0: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800804A4: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800804A8: sw          $v0, 0x2344($at)
    MEM_W(0X2344, ctx->r1) = ctx->r2;
    // 0x800804AC: addu        $a0, $t6, $t4
    ctx->r4 = ADD32(ctx->r14, ctx->r12);
    // 0x800804B0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800804B4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800804B8: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800804BC: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800804C0: jal         0x80070EDC
    // 0x800804C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800804C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800804C8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800804CC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800804D0: addiu       $a3, $a3, 0x232C
    ctx->r7 = ADD32(ctx->r7, 0X232C);
    // 0x800804D4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800804D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800804DC: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
    // 0x800804E0: sw          $t8, 0x2330($at)
    MEM_W(0X2330, ctx->r1) = ctx->r24;
    // 0x800804E4: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x800804E8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800804EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800804F0: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800804F4: addiu       $a2, $a2, 0x71EC
    ctx->r6 = ADD32(ctx->r6, 0X71EC);
    // 0x800804F8: sw          $t6, 0x71EC($at)
    MEM_W(0X71EC, ctx->r1) = ctx->r14;
    // 0x800804FC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80080500: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080504: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80080508: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008050C: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80080510: addiu       $t0, $t0, 0x2324
    ctx->r8 = ADD32(ctx->r8, 0X2324);
    // 0x80080514: sw          $t8, 0x2324($at)
    MEM_W(0X2324, ctx->r1) = ctx->r24;
    // 0x80080518: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8008051C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80080520: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80080524: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80080528: sw          $t6, 0x2328($at)
    MEM_W(0X2328, ctx->r1) = ctx->r14;
    // 0x8008052C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80080530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80080534: blez        $s0, L_80080858
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80080538: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_80080858;
    }
    // 0x80080538: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8008053C: andi        $a0, $s0, 0x3
    ctx->r4 = ctx->r16 & 0X3;
    // 0x80080540: beq         $a0, $zero, L_800805F4
    if (ctx->r4 == 0) {
        // 0x80080544: or          $t4, $a0, $zero
        ctx->r12 = ctx->r4 | 0;
            goto L_800805F4;
    }
    // 0x80080544: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x80080548: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008054C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80080550: sll         $v0, $zero, 5
    ctx->r2 = S32(0 << 5);
L_80080554:
    // 0x80080554: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80080558: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8008055C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080560: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080564: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80080568: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008056C: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80080570: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080574: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80080578: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8008057C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080580: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80080584: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80080588: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8008058C: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80080590: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x80080594: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80080598: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x8008059C: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800805A0: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800805A4: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x800805A8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800805AC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800805B0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800805B4: sw          $zero, 0x10($t8)
    MEM_W(0X10, ctx->r24) = 0;
    // 0x800805B8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800805BC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x800805C0: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800805C4: sw          $zero, 0x14($t6)
    MEM_W(0X14, ctx->r14) = 0;
    // 0x800805C8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800805CC: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x800805D0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800805D4: sw          $zero, 0x18($t8)
    MEM_W(0X18, ctx->r24) = 0;
    // 0x800805D8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800805DC: addiu       $t2, $t2, 0x14
    ctx->r10 = ADD32(ctx->r10, 0X14);
    // 0x800805E0: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800805E4: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
    // 0x800805E8: bne         $t4, $t3, L_80080554
    if (ctx->r12 != ctx->r11) {
        // 0x800805EC: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_80080554;
    }
    // 0x800805EC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800805F0: beq         $t3, $s0, L_80080854
    if (ctx->r11 == ctx->r16) {
        // 0x800805F4: sll         $v1, $t2, 2
        ctx->r3 = S32(ctx->r10 << 2);
            goto L_80080854;
    }
L_800805F4:
    // 0x800805F4: sll         $v1, $t2, 2
    ctx->r3 = S32(ctx->r10 << 2);
    // 0x800805F8: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x800805FC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80080600: sll         $v0, $t3, 5
    ctx->r2 = S32(ctx->r11 << 5);
    // 0x80080604: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
L_80080608:
    // 0x80080608: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8008060C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080610: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080614: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080618: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8008061C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80080620: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80080624: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080628: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x8008062C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80080630: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080634: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80080638: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x8008063C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080640: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80080644: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x80080648: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008064C: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80080650: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080654: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x80080658: sw          $t9, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r25;
    // 0x8008065C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080660: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x80080664: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080668: sw          $zero, 0x10($t8)
    MEM_W(0X10, ctx->r24) = 0;
    // 0x8008066C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080670: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80080674: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080678: sw          $zero, 0x14($t6)
    MEM_W(0X14, ctx->r14) = 0;
    // 0x8008067C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080680: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80080684: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080688: sw          $zero, 0x18($t8)
    MEM_W(0X18, ctx->r24) = 0;
    // 0x8008068C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080690: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80080694: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080698: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
    // 0x8008069C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800806A0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800806A4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800806A8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800806AC: sw          $t8, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r24;
    // 0x800806B0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800806B4: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x800806B8: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800806BC: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800806C0: sw          $t9, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r25;
    // 0x800806C4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800806C8: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800806CC: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800806D0: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800806D4: sw          $t8, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r24;
    // 0x800806D8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800806DC: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x800806E0: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800806E4: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800806E8: sw          $t9, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r25;
    // 0x800806EC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800806F0: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x800806F4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800806F8: sw          $zero, 0x30($t8)
    MEM_W(0X30, ctx->r24) = 0;
    // 0x800806FC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080700: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80080704: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080708: sw          $zero, 0x34($t6)
    MEM_W(0X34, ctx->r14) = 0;
    // 0x8008070C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080710: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80080714: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080718: sw          $zero, 0x38($t8)
    MEM_W(0X38, ctx->r24) = 0;
    // 0x8008071C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080720: nop

    // 0x80080724: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080728: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    // 0x8008072C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080730: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80080734: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080738: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8008073C: sw          $t8, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r24;
    // 0x80080740: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80080744: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x80080748: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x8008074C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80080750: sw          $t9, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r25;
    // 0x80080754: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080758: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8008075C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080760: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x80080764: sw          $t8, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r24;
    // 0x80080768: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8008076C: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80080770: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080774: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x80080778: sw          $t9, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->r25;
    // 0x8008077C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080780: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x80080784: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080788: sw          $zero, 0x50($t8)
    MEM_W(0X50, ctx->r24) = 0;
    // 0x8008078C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080790: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x80080794: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080798: sw          $zero, 0x54($t6)
    MEM_W(0X54, ctx->r14) = 0;
    // 0x8008079C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800807A0: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x800807A4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800807A8: sw          $zero, 0x58($t8)
    MEM_W(0X58, ctx->r24) = 0;
    // 0x800807AC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800807B0: nop

    // 0x800807B4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800807B8: sw          $zero, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = 0;
    // 0x800807BC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800807C0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800807C4: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800807C8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800807CC: sw          $t8, 0x60($t6)
    MEM_W(0X60, ctx->r14) = ctx->r24;
    // 0x800807D0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800807D4: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x800807D8: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800807DC: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800807E0: sw          $t9, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r25;
    // 0x800807E4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800807E8: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800807EC: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x800807F0: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800807F4: sw          $t8, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->r24;
    // 0x800807F8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800807FC: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80080800: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80080804: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x80080808: sw          $t9, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->r25;
    // 0x8008080C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080810: addiu       $v1, $v1, 0xC8
    ctx->r3 = ADD32(ctx->r3, 0XC8);
    // 0x80080814: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080818: sw          $zero, 0x70($t8)
    MEM_W(0X70, ctx->r24) = 0;
    // 0x8008081C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080820: nop

    // 0x80080824: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080828: sw          $zero, 0x74($t6)
    MEM_W(0X74, ctx->r14) = 0;
    // 0x8008082C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80080830: nop

    // 0x80080834: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80080838: sw          $zero, 0x78($t8)
    MEM_W(0X78, ctx->r24) = 0;
    // 0x8008083C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80080840: nop

    // 0x80080844: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x80080848: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x8008084C: bne         $v0, $t4, L_80080608
    if (ctx->r2 != ctx->r12) {
        // 0x80080850: sw          $zero, 0x7C($t6)
        MEM_W(0X7C, ctx->r14) = 0;
            goto L_80080608;
    }
    // 0x80080850: sw          $zero, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = 0;
L_80080854:
    // 0x80080854: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_80080858:
    // 0x80080858: blez        $s0, L_80080944
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008085C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80080944;
    }
    // 0x8008085C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080860: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80080864: addiu       $a2, $a2, 0x2334
    ctx->r6 = ADD32(ctx->r6, 0X2334);
    // 0x80080868: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008086C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
L_80080870:
    // 0x80080870: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80080874: addiu       $a0, $a0, 0x2250
    ctx->r4 = ADD32(ctx->r4, 0X2250);
    // 0x80080878: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8008087C:
    // 0x8008087C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80080880: addiu       $v0, $v0, 0x232C
    ctx->r2 = ADD32(ctx->r2, 0X232C);
L_80080884:
    // 0x80080884: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80080888: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008088C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080890: sb          $a1, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r5;
    // 0x80080894: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80080898: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8008089C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800808A0: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x800808A4: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800808A8: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x800808AC: addu        $t9, $t6, $v1
    ctx->r25 = ADD32(ctx->r14, ctx->r3);
    // 0x800808B0: sb          $t8, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r24;
    // 0x800808B4: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x800808B8: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
    // 0x800808BC: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800808C0: sb          $t7, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r15;
    // 0x800808C4: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800808C8: nop

    // 0x800808CC: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800808D0: sh          $zero, 0x4($t6)
    MEM_H(0X4, ctx->r14) = 0;
    // 0x800808D4: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800808D8: nop

    // 0x800808DC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800808E0: sh          $zero, 0x6($t8)
    MEM_H(0X6, ctx->r24) = 0;
    // 0x800808E4: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800808E8: nop

    // 0x800808EC: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800808F0: sh          $zero, 0x8($t6)
    MEM_H(0X8, ctx->r14) = 0;
    // 0x800808F4: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800808F8: nop

    // 0x800808FC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080900: sh          $zero, 0xA($t8)
    MEM_H(0XA, ctx->r24) = 0;
    // 0x80080904: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x80080908: nop

    // 0x8008090C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x80080910: sh          $zero, 0xC($t6)
    MEM_H(0XC, ctx->r14) = 0;
    // 0x80080914: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x80080918: nop

    // 0x8008091C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80080920: bne         $v0, $a2, L_80080884
    if (ctx->r2 != ctx->r6) {
        // 0x80080924: sh          $zero, 0xE($t8)
        MEM_H(0XE, ctx->r24) = 0;
            goto L_80080884;
    }
    // 0x80080924: sh          $zero, 0xE($t8)
    MEM_H(0XE, ctx->r24) = 0;
    // 0x80080928: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8008092C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80080930: bne         $a3, $t1, L_8008087C
    if (ctx->r7 != ctx->r9) {
        // 0x80080934: addiu       $a0, $a0, 0x3
        ctx->r4 = ADD32(ctx->r4, 0X3);
            goto L_8008087C;
    }
    // 0x80080934: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x80080938: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8008093C: bne         $t3, $s0, L_80080870
    if (ctx->r11 != ctx->r16) {
        // 0x80080940: nop
    
            goto L_80080870;
    }
    // 0x80080940: nop

L_80080944:
    // 0x80080944: sw          $zero, 0x2334($at)
    MEM_W(0X2334, ctx->r1) = 0;
    // 0x80080948: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008094C: sw          $zero, 0x2338($at)
    MEM_W(0X2338, ctx->r1) = 0;
    // 0x80080950: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80080958: sw          $s0, 0x233C($at)
    MEM_W(0X233C, ctx->r1) = ctx->r16;
    // 0x8008095C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80080960: jr          $ra
    // 0x80080964: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80080964: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void audspat_play_sound_at_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009558: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000955C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80009560: lhu         $t7, 0x3A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3A);
    // 0x80009564: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80009568: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000956C: lw          $t6, -0x5E40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E40);
    // 0x80009570: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80009574: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80009578: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    // 0x8000957C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80009580: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80009584: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80009588: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8000958C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80009590: lbu         $t0, 0x3($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X3);
    // 0x80009594: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80009598: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8000959C: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x800095A0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800095A4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800095A8: lhu         $t2, 0x6($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X6);
    // 0x800095AC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800095B0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800095B4: lbu         $t3, 0x4($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4);
    // 0x800095B8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800095BC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800095C0: lbu         $t4, 0x8($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X8);
    // 0x800095C4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800095C8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800095CC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x800095D0: jal         0x8000974C
    // 0x800095D4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    audspat_point_create(rdram, ctx);
        goto after_0;
    // 0x800095D4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    after_0:
    // 0x800095D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800095DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800095E0: jr          $ra
    // 0x800095E4: nop

    return;
    // 0x800095E4: nop

;}
RECOMP_FUNC void rain_render_splashes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADBB8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800ADBBC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADBC0: lw          $t6, 0x321C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X321C);
    // 0x800ADBC4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800ADBC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800ADBCC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800ADBD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800ADBD4: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800ADBD8: beq         $t6, $zero, L_800AE000
    if (ctx->r14 == 0) {
        // 0x800ADBDC: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_800AE000;
    }
    // 0x800ADBDC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800ADBE0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800ADBE4: lw          $t7, 0x31FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31FC);
    // 0x800ADBE8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800ADBEC: lw          $t9, 0x31F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X31F0);
    // 0x800ADBF0: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x800ADBF4: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800ADBF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800ADBFC: mflo        $v0
    ctx->r2 = lo;
    // 0x800ADC00: sra         $t0, $v0, 14
    ctx->r8 = S32(SIGNED(ctx->r2) >> 14);
    // 0x800ADC04: slti        $at, $t0, 0x4001
    ctx->r1 = SIGNED(ctx->r8) < 0X4001 ? 1 : 0;
    // 0x800ADC08: bne         $at, $zero, L_800ADF0C
    if (ctx->r1 != 0) {
        // 0x800ADC0C: nop
    
            goto L_800ADF0C;
    }
    // 0x800ADC0C: nop

    // 0x800ADC10: jal         0x8001BB4C
    // 0x800ADC14: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    get_racer_object_by_port(rdram, ctx);
        goto after_0;
    // 0x800ADC14: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_0:
    // 0x800ADC18: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800ADC1C: addiu       $a2, $a2, 0x3214
    ctx->r6 = ADD32(ctx->r6, 0X3214);
    // 0x800ADC20: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800ADC24: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x800ADC28: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800ADC2C: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800ADC30: bgtz        $t3, L_800ADF0C
    if (SIGNED(ctx->r11) > 0) {
        // 0x800ADC34: sw          $t3, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r11;
            goto L_800ADF0C;
    }
    // 0x800ADC34: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800ADC38: beq         $v0, $zero, L_800ADF0C
    if (ctx->r2 == 0) {
        // 0x800ADC3C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800ADF0C;
    }
    // 0x800ADC3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800ADC40: sll         $t5, $zero, 3
    ctx->r13 = S32(0 << 3);
    // 0x800ADC44: subu        $t5, $t5, $zero
    ctx->r13 = SUB32(ctx->r13, 0);
    // 0x800ADC48: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADC4C: addiu       $t6, $t6, 0x30DC
    ctx->r14 = ADD32(ctx->r14, 0X30DC);
    // 0x800ADC50: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800ADC54: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800ADC58: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
L_800ADC5C:
    // 0x800ADC5C: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x800ADC60: nop

    // 0x800ADC64: bne         $t7, $zero, L_800ADC70
    if (ctx->r15 != 0) {
        // 0x800ADC68: nop
    
            goto L_800ADC70;
    }
    // 0x800ADC68: nop

    // 0x800ADC6C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800ADC70:
    // 0x800ADC70: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800ADC74: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x800ADC78: beq         $at, $zero, L_800ADC88
    if (ctx->r1 == 0) {
        // 0x800ADC7C: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800ADC88;
    }
    // 0x800ADC7C: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x800ADC80: bltz        $s1, L_800ADC5C
    if (SIGNED(ctx->r17) < 0) {
        // 0x800ADC84: nop
    
            goto L_800ADC5C;
    }
    // 0x800ADC84: nop

L_800ADC88:
    // 0x800ADC88: bltz        $s1, L_800ADF0C
    if (SIGNED(ctx->r17) < 0) {
        // 0x800ADC8C: addiu       $a0, $zero, -0x2000
        ctx->r4 = ADD32(0, -0X2000);
            goto L_800ADF0C;
    }
    // 0x800ADC8C: addiu       $a0, $zero, -0x2000
    ctx->r4 = ADD32(0, -0X2000);
    // 0x800ADC90: jal         0x8006FB8C
    // 0x800ADC94: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800ADC94: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    after_1:
    // 0x800ADC98: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800ADC9C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800ADCA0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800ADCA4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800ADCA8: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800ADCAC: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x800ADCB0: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x800ADCB4: jal         0x8006FB8C
    // 0x800ADCB8: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800ADCB8: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_2:
    // 0x800ADCBC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800ADCC0: lh          $s0, 0x6E($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X6E);
    // 0x800ADCC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800ADCC8: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800ADCCC: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800ADCD0: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800ADCD4: jal         0x80070A04
    // 0x800ADCD8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x800ADCD8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_3:
    // 0x800ADCDC: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800ADCE0: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800ADCE4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800ADCE8: lwc1        $f16, 0xC($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800ADCEC: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800ADCF0: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800ADCF4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ADCF8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800ADCFC: jal         0x80070A38
    // 0x800ADD00: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    coss_f(rdram, ctx);
        goto after_4;
    // 0x800ADD00: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x800ADD04: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800ADD08: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x800ADD0C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800ADD10: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800ADD14: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800ADD18: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800ADD1C: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800ADD20: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800ADD24: jal         0x80029F58
    // 0x800ADD28: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_5;
    // 0x800ADD28: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x800ADD2C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800ADD30: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800ADD34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800ADD38: jal         0x8002B134
    // 0x800ADD3C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    func_8002B0F4(rdram, ctx);
        goto after_6;
    // 0x800ADD3C: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_6:
    // 0x800ADD40: beq         $v0, $zero, L_800ADF0C
    if (ctx->r2 == 0) {
        // 0x800ADD44: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_800ADF0C;
    }
    // 0x800ADD44: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800ADD48: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800ADD4C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800ADD50: bne         $at, $zero, L_800ADE08
    if (ctx->r1 != 0) {
        // 0x800ADD54: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800ADE08;
    }
    // 0x800ADD54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800ADD58: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x800ADD5C: blez        $a0, L_800ADDC8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800ADD60: nop
    
            goto L_800ADDC8;
    }
    // 0x800ADD60: nop

    // 0x800ADD64: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800ADD68: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800ADD6C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800ADD70: lwc1        $f0, 0x10($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800ADD74: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800ADD78: nop

    // 0x800ADD7C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800ADD80: nop

    // 0x800ADD84: bc1f        L_800ADDC8
    if (!c1cs) {
        // 0x800ADD88: nop
    
            goto L_800ADDC8;
    }
    // 0x800ADD88: nop

L_800ADD8C:
    // 0x800ADD8C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800ADD90: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800ADD94: beq         $at, $zero, L_800ADDC8
    if (ctx->r1 == 0) {
        // 0x800ADD98: nop
    
            goto L_800ADDC8;
    }
    // 0x800ADD98: nop

    // 0x800ADD9C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800ADDA0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800ADDA4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800ADDA8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800ADDAC: nop

    // 0x800ADDB0: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800ADDB4: nop

    // 0x800ADDB8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800ADDBC: nop

    // 0x800ADDC0: bc1t        L_800ADD8C
    if (c1cs) {
        // 0x800ADDC4: nop
    
            goto L_800ADD8C;
    }
    // 0x800ADDC4: nop

L_800ADDC8:
    // 0x800ADDC8: blez        $v1, L_800ADE08
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800ADDCC: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_800ADE08;
    }
    // 0x800ADDCC: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800ADDD0: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800ADDD4: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800ADDD8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800ADDDC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800ADDE0: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x800ADDE4: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800ADDE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800ADDEC: sub.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800ADDF0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800ADDF4: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800ADDF8: nop

    // 0x800ADDFC: bc1f        L_800ADE08
    if (!c1cs) {
        // 0x800ADE00: nop
    
            goto L_800ADE08;
    }
    // 0x800ADE00: nop

    // 0x800ADE04: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_800ADE08:
    // 0x800ADE08: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800ADE0C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800ADE10: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800ADE14: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800ADE18: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800ADE1C: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800ADE20: lwc1        $f8, 0x10($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800ADE24: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800ADE28: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800ADE2C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800ADE30: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800ADE34: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800ADE38: bc1f        L_800ADE44
    if (!c1cs) {
        // 0x800ADE3C: addiu       $t2, $t2, 0x30DC
        ctx->r10 = ADD32(ctx->r10, 0X30DC);
            goto L_800ADE44;
    }
    // 0x800ADE3C: addiu       $t2, $t2, 0x30DC
    ctx->r10 = ADD32(ctx->r10, 0X30DC);
    // 0x800ADE40: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800ADE44:
    // 0x800ADE44: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800ADE48: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800ADE4C: bc1f        L_800ADE78
    if (!c1cs) {
        // 0x800ADE50: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800ADE78;
    }
    // 0x800ADE50: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800ADE54: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800ADE58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ADE5C: nop

    // 0x800ADE60: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800ADE64: nop

    // 0x800ADE68: bc1f        L_800ADE94
    if (!c1cs) {
        // 0x800ADE6C: nop
    
            goto L_800ADE94;
    }
    // 0x800ADE6C: nop

    // 0x800ADE70: b           L_800ADE94
    // 0x800ADE74: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
        goto L_800ADE94;
    // 0x800ADE74: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_800ADE78:
    // 0x800ADE78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ADE7C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800ADE80: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800ADE84: nop

    // 0x800ADE88: bc1f        L_800ADE94
    if (!c1cs) {
        // 0x800ADE8C: nop
    
            goto L_800ADE94;
    }
    // 0x800ADE8C: nop

    // 0x800ADE90: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_800ADE94:
    // 0x800ADE94: bltz        $s1, L_800ADF0C
    if (SIGNED(ctx->r17) < 0) {
        // 0x800ADE98: sll         $t1, $s1, 3
        ctx->r9 = S32(ctx->r17 << 3);
            goto L_800ADF0C;
    }
    // 0x800ADE98: sll         $t1, $s1, 3
    ctx->r9 = S32(ctx->r17 << 3);
    // 0x800ADE9C: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x800ADEA0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800ADEA4: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x800ADEA8: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800ADEAC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800ADEB0: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800ADEB4: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800ADEB8: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800ADEBC: sra         $t5, $v1, 10
    ctx->r13 = S32(SIGNED(ctx->r3) >> 10);
    // 0x800ADEC0: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800ADEC4: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x800ADEC8: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800ADECC: addiu       $a1, $t5, 0xBF
    ctx->r5 = ADD32(ctx->r13, 0XBF);
    // 0x800ADED0: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800ADED4: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x800ADED8: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x800ADEDC: jal         0x8006FB8C
    // 0x800ADEE0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800ADEE0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    after_7:
    // 0x800ADEE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800ADEE8: addiu       $a0, $a0, 0x3214
    ctx->r4 = ADD32(ctx->r4, 0X3214);
    // 0x800ADEEC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800ADEF0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800ADEF4: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // 0x800ADEF8: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x800ADEFC: addiu       $t8, $t7, 0x40
    ctx->r24 = ADD32(ctx->r15, 0X40);
    // 0x800ADF00: bgez        $t8, L_800ADF0C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800ADF04: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_800ADF0C;
    }
    // 0x800ADF04: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800ADF08: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800ADF0C:
    // 0x800ADF0C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800ADF10: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800ADF14: addiu       $s1, $s1, -0x7E34
    ctx->r17 = ADD32(ctx->r17, -0X7E34);
    // 0x800ADF18: addiu       $s0, $s0, 0x30DC
    ctx->r16 = ADD32(ctx->r16, 0X30DC);
L_800ADF1C:
    // 0x800ADF1C: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800ADF20: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x800ADF24: beq         $t0, $zero, L_800ADFD0
    if (ctx->r8 == 0) {
        // 0x800ADF28: nop
    
            goto L_800ADFD0;
    }
    // 0x800ADF28: nop

    // 0x800ADF2C: lh          $t1, 0x18($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X18);
    // 0x800ADF30: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800ADF34: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800ADF38: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
    // 0x800ADF3C: lh          $t5, 0x18($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18);
    // 0x800ADF40: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x800ADF44: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x800ADF48: bne         $at, $zero, L_800ADF58
    if (ctx->r1 != 0) {
        // 0x800ADF4C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800ADF58;
    }
    // 0x800ADF4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800ADF50: b           L_800ADFD0
    // 0x800ADF54: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
        goto L_800ADFD0;
    // 0x800ADF54: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
L_800ADF58:
    // 0x800ADF58: beq         $s2, $zero, L_800ADF80
    if (ctx->r18 == 0) {
        // 0x800ADF5C: lui         $at, 0xC0C0
        ctx->r1 = S32(0XC0C0 << 16);
            goto L_800ADF80;
    }
    // 0x800ADF5C: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x800ADF60: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800ADF64: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800ADF68: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800ADF6C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800ADF70: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    // 0x800ADF74: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800ADF78: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800ADF7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800ADF80:
    // 0x800ADF80: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800ADF84: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x800ADF88: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800ADF8C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800ADF90: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800ADF94: lh          $t2, 0x1A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A);
    // 0x800ADF98: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800ADF9C: andi        $t1, $t2, 0xFF
    ctx->r9 = ctx->r10 & 0XFF;
    // 0x800ADFA0: or          $t3, $t1, $at
    ctx->r11 = ctx->r9 | ctx->r1;
    // 0x800ADFA4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800ADFA8: lw          $t4, 0x321C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X321C);
    // 0x800ADFAC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800ADFB0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800ADFB4: addiu       $t5, $zero, 0x10E
    ctx->r13 = ADD32(0, 0X10E);
    // 0x800ADFB8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800ADFBC: addiu       $a2, $a2, -0x7E2C
    ctx->r6 = ADD32(ctx->r6, -0X7E2C);
    // 0x800ADFC0: addiu       $a1, $a1, -0x7E30
    ctx->r5 = ADD32(ctx->r5, -0X7E30);
    // 0x800ADFC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800ADFC8: jal         0x80068754
    // 0x800ADFCC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    render_sprite_billboard(rdram, ctx);
        goto after_8;
    // 0x800ADFCC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_8:
L_800ADFD0:
    // 0x800ADFD0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADFD4: addiu       $t6, $t6, 0x31BC
    ctx->r14 = ADD32(ctx->r14, 0X31BC);
    // 0x800ADFD8: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x800ADFDC: bne         $s0, $t6, L_800ADF1C
    if (ctx->r16 != ctx->r14) {
        // 0x800ADFE0: nop
    
            goto L_800ADF1C;
    }
    // 0x800ADFE0: nop

    // 0x800ADFE4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800ADFE8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800ADFEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800ADFF0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800ADFF4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800ADFF8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800ADFFC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800AE000:
    // 0x800AE000: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AE004: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800AE008: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800AE00C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800AE010: jr          $ra
    // 0x800AE014: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800AE014: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void init_particle_buffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEC88: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800AEC8C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800AEC90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AEC94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AEC98: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AEC9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AECA0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800AECA4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800AECA8: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800AECAC: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x800AECB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AECB4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800AECB8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AECBC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AECC0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AECC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AECC8: bgez        $a0, L_800AECD4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800AECCC: sw          $zero, 0x3290($at)
        MEM_W(0X3290, ctx->r1) = 0;
            goto L_800AECD4;
    }
    // 0x800AECCC: sw          $zero, 0x3290($at)
    MEM_W(0X3290, ctx->r1) = 0;
    // 0x800AECD0: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_800AECD4:
    // 0x800AECD4: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x800AECD8: bgez        $s3, L_800AECE4
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800AECDC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AECE4;
    }
    // 0x800AECDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AECE0: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_800AECE4:
    // 0x800AECE4: bgez        $s7, L_800AECF0
    if (SIGNED(ctx->r23) >= 0) {
        // 0x800AECE8: nop
    
            goto L_800AECF0;
    }
    // 0x800AECE8: nop

    // 0x800AECEC: addiu       $s7, $zero, 0xD0
    ctx->r23 = ADD32(0, 0XD0);
L_800AECF0:
    // 0x800AECF0: bgez        $s4, L_800AECFC
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800AECF4: nop
    
            goto L_800AECFC;
    }
    // 0x800AECF4: nop

    // 0x800AECF8: addiu       $s4, $zero, 0xA0
    ctx->r20 = ADD32(0, 0XA0);
L_800AECFC:
    // 0x800AECFC: bgez        $fp, L_800AED08
    if (SIGNED(ctx->r30) >= 0) {
        // 0x800AED00: nop
    
            goto L_800AED08;
    }
    // 0x800AED00: nop

    // 0x800AED04: addiu       $fp, $zero, 0x40
    ctx->r30 = ADD32(0, 0X40);
L_800AED08:
    // 0x800AED08: sw          $s1, 0x33DC($at)
    MEM_W(0X33DC, ctx->r1) = ctx->r17;
    // 0x800AED0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED10: sw          $zero, 0x3234($at)
    MEM_W(0X3234, ctx->r1) = 0;
    // 0x800AED14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED18: sw          $s3, 0x33E0($at)
    MEM_W(0X33E0, ctx->r1) = ctx->r19;
    // 0x800AED1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED20: sw          $zero, 0x3240($at)
    MEM_W(0X3240, ctx->r1) = 0;
    // 0x800AED24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED28: sw          $s7, 0x33E4($at)
    MEM_W(0X33E4, ctx->r1) = ctx->r23;
    // 0x800AED2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED30: sw          $zero, 0x324C($at)
    MEM_W(0X324C, ctx->r1) = 0;
    // 0x800AED34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED38: sw          $s4, 0x33E8($at)
    MEM_W(0X33E8, ctx->r1) = ctx->r20;
    // 0x800AED3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED40: sw          $zero, 0x3258($at)
    MEM_W(0X3258, ctx->r1) = 0;
    // 0x800AED44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED48: sw          $fp, 0x33EC($at)
    MEM_W(0X33EC, ctx->r1) = ctx->r30;
    // 0x800AED4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AED50: jal         0x800AE998
    // 0x800AED54: sw          $zero, 0x3264($at)
    MEM_W(0X3264, ctx->r1) = 0;
    free_particle_vertices_triangles(rdram, ctx);
        goto after_0;
    // 0x800AED54: sw          $zero, 0x3264($at)
    MEM_W(0X3264, ctx->r1) = 0;
    after_0:
    // 0x800AED58: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800AED5C: sll         $t1, $s4, 2
    ctx->r9 = S32(ctx->r20 << 2);
    // 0x800AED60: subu        $t1, $t1, $s4
    ctx->r9 = SUB32(ctx->r9, ctx->r20);
    // 0x800AED64: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800AED68: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x800AED6C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AED70: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800AED74: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800AED78: sll         $t3, $fp, 4
    ctx->r11 = S32(ctx->r30 << 4);
    // 0x800AED7C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x800AED80: lui         $s2, 0x8080
    ctx->r18 = S32(0X8080 << 16);
    // 0x800AED84: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800AED88: ori         $s2, $s2, 0x8080
    ctx->r18 = ctx->r18 | 0X8080;
    // 0x800AED8C: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x800AED90: sll         $a0, $t4, 1
    ctx->r4 = S32(ctx->r12 << 1);
    // 0x800AED94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800AED98: jal         0x80070EDC
    // 0x800AED9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800AED9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_1:
    // 0x800AEDA0: sll         $t5, $s3, 1
    ctx->r13 = S32(ctx->r19 << 1);
    // 0x800AEDA4: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x800AEDA8: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    // 0x800AEDAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEDB0: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x800AEDB4: sw          $v0, 0x3270($at)
    MEM_W(0X3270, ctx->r1) = ctx->r2;
    // 0x800AEDB8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800AEDBC: jal         0x80070EDC
    // 0x800AEDC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800AEDC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800AEDC4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800AEDC8: addiu       $s0, $s0, 0x3274
    ctx->r16 = ADD32(ctx->r16, 0X3274);
    // 0x800AEDCC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800AEDD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEDD4: jal         0x800AE8D4
    // 0x800AEDD8: sw          $zero, 0x326C($at)
    MEM_W(0X326C, ctx->r1) = 0;
    free_particle_buffers(rdram, ctx);
        goto after_3;
    // 0x800AEDD8: sw          $zero, 0x326C($at)
    MEM_W(0X326C, ctx->r1) = 0;
    after_3:
    // 0x800AEDDC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AEDE0: lw          $t8, 0x33DC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X33DC);
    // 0x800AEDE4: nop

    // 0x800AEDE8: blez        $t8, L_800AEE0C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800AEDEC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AEE0C;
    }
    // 0x800AEDEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEDF0: sw          $zero, 0x3230($at)
    MEM_W(0X3230, ctx->r1) = 0;
    // 0x800AEDF4: sll         $a0, $s1, 7
    ctx->r4 = S32(ctx->r17 << 7);
    // 0x800AEDF8: jal         0x80070EDC
    // 0x800AEDFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800AEDFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800AEE00: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AEE04: addiu       $s5, $s5, 0x3238
    ctx->r21 = ADD32(ctx->r21, 0X3238);
    // 0x800AEE08: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
L_800AEE0C:
    // 0x800AEE0C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AEE10: lw          $t9, 0x33E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X33E0);
    // 0x800AEE14: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AEE18: blez        $t9, L_800AEE40
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800AEE1C: addiu       $s5, $s5, 0x3238
        ctx->r21 = ADD32(ctx->r21, 0X3238);
            goto L_800AEE40;
    }
    // 0x800AEE1C: addiu       $s5, $s5, 0x3238
    ctx->r21 = ADD32(ctx->r21, 0X3238);
    // 0x800AEE20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEE24: sw          $zero, 0x323C($at)
    MEM_W(0X323C, ctx->r1) = 0;
    // 0x800AEE28: sll         $a0, $s3, 7
    ctx->r4 = S32(ctx->r19 << 7);
    // 0x800AEE2C: jal         0x80070EDC
    // 0x800AEE30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x800AEE30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x800AEE34: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800AEE38: addiu       $s6, $s6, 0x3244
    ctx->r22 = ADD32(ctx->r22, 0X3244);
    // 0x800AEE3C: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
L_800AEE40:
    // 0x800AEE40: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AEE44: lw          $t1, 0x33E4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X33E4);
    // 0x800AEE48: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800AEE4C: blez        $t1, L_800AEE78
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800AEE50: addiu       $s6, $s6, 0x3244
        ctx->r22 = ADD32(ctx->r22, 0X3244);
            goto L_800AEE78;
    }
    // 0x800AEE50: addiu       $s6, $s6, 0x3244
    ctx->r22 = ADD32(ctx->r22, 0X3244);
    // 0x800AEE54: sll         $a0, $s7, 3
    ctx->r4 = S32(ctx->r23 << 3);
    // 0x800AEE58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEE5C: subu        $a0, $a0, $s7
    ctx->r4 = SUB32(ctx->r4, ctx->r23);
    // 0x800AEE60: sw          $zero, 0x3248($at)
    MEM_W(0X3248, ctx->r1) = 0;
    // 0x800AEE64: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x800AEE68: jal         0x80070EDC
    // 0x800AEE6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x800AEE6C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x800AEE70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEE74: sw          $v0, 0x3250($at)
    MEM_W(0X3250, ctx->r1) = ctx->r2;
L_800AEE78:
    // 0x800AEE78: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AEE7C: lw          $t2, 0x33E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X33E8);
    // 0x800AEE80: nop

    // 0x800AEE84: blez        $t2, L_800AEEA8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AEE88: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800AEEA8;
    }
    // 0x800AEE88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEE8C: sw          $zero, 0x3254($at)
    MEM_W(0X3254, ctx->r1) = 0;
    // 0x800AEE90: sll         $a0, $s4, 7
    ctx->r4 = S32(ctx->r20 << 7);
    // 0x800AEE94: jal         0x80070EDC
    // 0x800AEE98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x800AEE98: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x800AEE9C: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800AEEA0: addiu       $s7, $s7, 0x325C
    ctx->r23 = ADD32(ctx->r23, 0X325C);
    // 0x800AEEA4: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
L_800AEEA8:
    // 0x800AEEA8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AEEAC: lw          $t3, 0x33EC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X33EC);
    // 0x800AEEB0: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800AEEB4: blez        $t3, L_800AEEE4
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800AEEB8: addiu       $s7, $s7, 0x325C
        ctx->r23 = ADD32(ctx->r23, 0X325C);
            goto L_800AEEE4;
    }
    // 0x800AEEB8: addiu       $s7, $s7, 0x325C
    ctx->r23 = ADD32(ctx->r23, 0X325C);
    // 0x800AEEBC: sll         $a0, $fp, 4
    ctx->r4 = S32(ctx->r30 << 4);
    // 0x800AEEC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AEEC4: addu        $a0, $a0, $fp
    ctx->r4 = ADD32(ctx->r4, ctx->r30);
    // 0x800AEEC8: sw          $zero, 0x3260($at)
    MEM_W(0X3260, ctx->r1) = 0;
    // 0x800AEECC: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800AEED0: jal         0x80070EDC
    // 0x800AEED4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x800AEED4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x800AEED8: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800AEEDC: addiu       $fp, $fp, 0x3268
    ctx->r30 = ADD32(ctx->r30, 0X3268);
    // 0x800AEEE0: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
L_800AEEE4:
    // 0x800AEEE4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AEEE8: lw          $v0, 0x33DC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X33DC);
    // 0x800AEEEC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AEEF0: lw          $t5, 0x3270($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3270);
    // 0x800AEEF4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800AEEF8: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800AEEFC: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x800AEF00: sll         $t4, $zero, 3
    ctx->r12 = S32(0 << 3);
    // 0x800AEF04: sll         $t7, $zero, 4
    ctx->r15 = S32(0 << 4);
    // 0x800AEF08: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800AEF0C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x800AEF10: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800AEF14: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800AEF18: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AEF1C: addiu       $fp, $fp, 0x3268
    ctx->r30 = ADD32(ctx->r30, 0X3268);
    // 0x800AEF20: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x800AEF24: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x800AEF28: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AEF2C: blez        $v0, L_800AEF88
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AEF30: addu        $s2, $t1, $t2
        ctx->r18 = ADD32(ctx->r9, ctx->r10);
            goto L_800AEF88;
    }
    // 0x800AEF30: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x800AEF34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AEF38: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x800AEF3C: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
L_800AEF40:
    // 0x800AEF40: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x800AEF44: sll         $t3, $s1, 4
    ctx->r11 = S32(ctx->r17 << 4);
    // 0x800AEF48: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800AEF4C: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800AEF50: sw          $t4, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r12;
    // 0x800AEF54: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800AEF58: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AEF5C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AEF60: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    // 0x800AEF64: jal         0x800AF374
    // 0x800AEF68: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_triangle_particle_model(rdram, ctx);
        goto after_9;
    // 0x800AEF68: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_9:
    // 0x800AEF6C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AEF70: lw          $t9, 0x33DC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X33DC);
    // 0x800AEF74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEF78: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AEF7C: bne         $at, $zero, L_800AEF40
    if (ctx->r1 != 0) {
        // 0x800AEF80: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AEF40;
    }
    // 0x800AEF80: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AEF84: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AEF88:
    // 0x800AEF88: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AEF8C: addiu       $v1, $v1, 0x33E0
    ctx->r3 = ADD32(ctx->r3, 0X33E0);
    // 0x800AEF90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AEF94: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x800AEF98: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800AEF9C: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800AEFA0: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800AEFA4: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
    // 0x800AEFA8: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x800AEFAC: blez        $v0, L_800AF008
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AEFB0: addu        $s2, $t1, $t2
        ctx->r18 = ADD32(ctx->r9, ctx->r10);
            goto L_800AF008;
    }
    // 0x800AEFB0: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x800AEFB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AEFB8:
    // 0x800AEFB8: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x800AEFBC: sll         $t3, $s1, 4
    ctx->r11 = S32(ctx->r17 << 4);
    // 0x800AEFC0: addu        $t5, $t3, $s2
    ctx->r13 = ADD32(ctx->r11, ctx->r18);
    // 0x800AEFC4: addu        $t6, $t4, $s0
    ctx->r14 = ADD32(ctx->r12, ctx->r16);
    // 0x800AEFC8: sw          $t5, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r13;
    // 0x800AEFCC: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x800AEFD0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AEFD4: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AEFD8: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    // 0x800AEFDC: jal         0x800AF418
    // 0x800AEFE0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_rectangle_particle_model(rdram, ctx);
        goto after_10;
    // 0x800AEFE0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_10:
    // 0x800AEFE4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AEFE8: lw          $t9, 0x33E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X33E0);
    // 0x800AEFEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AEFF0: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AEFF4: bne         $at, $zero, L_800AEFB8
    if (ctx->r1 != 0) {
        // 0x800AEFF8: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AEFB8;
    }
    // 0x800AEFF8: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AEFFC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF000: addiu       $v1, $v1, 0x33E0
    ctx->r3 = ADD32(ctx->r3, 0X33E0);
    // 0x800AF004: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF008:
    // 0x800AF008: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AF00C: addiu       $a3, $a3, 0x33E8
    ctx->r7 = ADD32(ctx->r7, 0X33E8);
    // 0x800AF010: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800AF014: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x800AF018: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800AF01C: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800AF020: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800AF024: blez        $v0, L_800AF094
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AF028: addu        $s2, $t1, $t2
        ctx->r18 = ADD32(ctx->r9, ctx->r10);
            goto L_800AF094;
    }
    // 0x800AF028: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x800AF02C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AF030:
    // 0x800AF030: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x800AF034: sll         $t3, $s1, 4
    ctx->r11 = S32(ctx->r17 << 4);
    // 0x800AF038: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800AF03C: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800AF040: sw          $t4, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r12;
    // 0x800AF044: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800AF048: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AF04C: addiu       $t7, $t7, 0x3298
    ctx->r15 = ADD32(ctx->r15, 0X3298);
    // 0x800AF050: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x800AF054: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800AF058: lw          $a0, 0x44($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X44);
    // 0x800AF05C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AF060: jal         0x800AF4E8
    // 0x800AF064: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_line_particle_model(rdram, ctx);
        goto after_11;
    // 0x800AF064: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_11:
    // 0x800AF068: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AF06C: lw          $t1, 0x33E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X33E8);
    // 0x800AF070: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF074: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800AF078: bne         $at, $zero, L_800AF030
    if (ctx->r1 != 0) {
        // 0x800AF07C: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AF030;
    }
    // 0x800AF07C: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AF080: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AF084: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF088: addiu       $v1, $v1, 0x33E0
    ctx->r3 = ADD32(ctx->r3, 0X33E0);
    // 0x800AF08C: addiu       $a3, $a3, 0x33E8
    ctx->r7 = ADD32(ctx->r7, 0X33E8);
    // 0x800AF090: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF094:
    // 0x800AF094: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF098: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF09C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800AF0A0: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800AF0A4: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x800AF0A8: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800AF0AC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800AF0B0: blez        $v0, L_800AF128
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AF0B4: addu        $s2, $t2, $t3
        ctx->r18 = ADD32(ctx->r10, ctx->r11);
            goto L_800AF128;
    }
    // 0x800AF0B4: addu        $s2, $t2, $t3
    ctx->r18 = ADD32(ctx->r10, ctx->r11);
    // 0x800AF0B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AF0BC:
    // 0x800AF0BC: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800AF0C0: sll         $t5, $s1, 4
    ctx->r13 = S32(ctx->r17 << 4);
    // 0x800AF0C4: addu        $t4, $t5, $s2
    ctx->r12 = ADD32(ctx->r13, ctx->r18);
    // 0x800AF0C8: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800AF0CC: sw          $t4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r12;
    // 0x800AF0D0: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800AF0D4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AF0D8: addiu       $t8, $t8, 0x3308
    ctx->r24 = ADD32(ctx->r24, 0X3308);
    // 0x800AF0DC: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800AF0E0: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800AF0E4: lw          $a0, 0x44($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X44);
    // 0x800AF0E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AF0EC: jal         0x800AF584
    // 0x800AF0F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    init_point_particle_model(rdram, ctx);
        goto after_12;
    // 0x800AF0F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_12:
    // 0x800AF0F4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800AF0F8: lw          $t2, 0x33EC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X33EC);
    // 0x800AF0FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF100: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800AF104: bne         $at, $zero, L_800AF0BC
    if (ctx->r1 != 0) {
        // 0x800AF108: addiu       $s0, $s0, 0x78
        ctx->r16 = ADD32(ctx->r16, 0X78);
            goto L_800AF0BC;
    }
    // 0x800AF108: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x800AF10C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF110: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AF114: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF118: addiu       $v1, $v1, 0x33E0
    ctx->r3 = ADD32(ctx->r3, 0X33E0);
    // 0x800AF11C: addiu       $a3, $a3, 0x33E8
    ctx->r7 = ADD32(ctx->r7, 0X33E8);
    // 0x800AF120: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF124: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF128:
    // 0x800AF128: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AF12C: lw          $t3, 0x33DC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X33DC);
    // 0x800AF130: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AF134: blez        $t3, L_800AF170
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800AF138: addiu       $s3, $s3, 0x33F0
        ctx->r19 = ADD32(ctx->r19, 0X33F0);
            goto L_800AF170;
    }
    // 0x800AF138: addiu       $s3, $s3, 0x33F0
    ctx->r19 = ADD32(ctx->r19, 0X33F0);
    // 0x800AF13C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AF140:
    // 0x800AF140: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x800AF144: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AF148: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800AF14C: sh          $zero, 0x2C($t6)
    MEM_H(0X2C, ctx->r14) = 0;
    // 0x800AF150: lw          $t4, 0x33DC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X33DC);
    // 0x800AF154: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF158: slt         $at, $s1, $t4
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AF15C: bne         $at, $zero, L_800AF140
    if (ctx->r1 != 0) {
        // 0x800AF160: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800AF140;
    }
    // 0x800AF160: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AF164: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF168: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF16C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF170:
    // 0x800AF170: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AF174: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AF178: blez        $t7, L_800AF1B0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800AF17C: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800AF1B0;
    }
    // 0x800AF17C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
L_800AF180:
    // 0x800AF180: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800AF184: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF188: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800AF18C: sh          $zero, 0x2C($t9)
    MEM_H(0X2C, ctx->r25) = 0;
    // 0x800AF190: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800AF194: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AF198: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800AF19C: bne         $at, $zero, L_800AF180
    if (ctx->r1 != 0) {
        // 0x800AF1A0: nop
    
            goto L_800AF180;
    }
    // 0x800AF1A0: nop

    // 0x800AF1A4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF1A8: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF1AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF1B0:
    // 0x800AF1B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AF1B4: addiu       $v1, $v1, 0x33E4
    ctx->r3 = ADD32(ctx->r3, 0X33E4);
    // 0x800AF1B8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800AF1BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AF1C0: blez        $t2, L_800AF1F8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AF1C4: addiu       $v0, $v0, 0x3250
        ctx->r2 = ADD32(ctx->r2, 0X3250);
            goto L_800AF1F8;
    }
    // 0x800AF1C4: addiu       $v0, $v0, 0x3250
    ctx->r2 = ADD32(ctx->r2, 0X3250);
L_800AF1C8:
    // 0x800AF1C8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800AF1CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF1D0: addu        $t5, $t3, $s0
    ctx->r13 = ADD32(ctx->r11, ctx->r16);
    // 0x800AF1D4: sh          $zero, 0x2C($t5)
    MEM_H(0X2C, ctx->r13) = 0;
    // 0x800AF1D8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800AF1DC: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AF1E0: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AF1E4: bne         $at, $zero, L_800AF1C8
    if (ctx->r1 != 0) {
        // 0x800AF1E8: nop
    
            goto L_800AF1C8;
    }
    // 0x800AF1E8: nop

    // 0x800AF1EC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF1F0: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF1F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF1F8:
    // 0x800AF1F8: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800AF1FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AF200: blez        $t4, L_800AF238
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800AF204: addiu       $a0, $zero, 0x2F
        ctx->r4 = ADD32(0, 0X2F);
            goto L_800AF238;
    }
    // 0x800AF204: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
L_800AF208:
    // 0x800AF208: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800AF20C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF210: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AF214: sh          $zero, 0x2C($t8)
    MEM_H(0X2C, ctx->r24) = 0;
    // 0x800AF218: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800AF21C: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x800AF220: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AF224: bne         $at, $zero, L_800AF208
    if (ctx->r1 != 0) {
        // 0x800AF228: nop
    
            goto L_800AF208;
    }
    // 0x800AF228: nop

    // 0x800AF22C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF230: addiu       $t0, $t0, 0x33EC
    ctx->r8 = ADD32(ctx->r8, 0X33EC);
    // 0x800AF234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AF238:
    // 0x800AF238: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800AF23C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AF240: blez        $t1, L_800AF26C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800AF244: nop
    
            goto L_800AF26C;
    }
    // 0x800AF244: nop

L_800AF248:
    // 0x800AF248: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800AF24C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF250: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800AF254: sh          $zero, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = 0;
    // 0x800AF258: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800AF25C: addiu       $s0, $s0, 0x78
    ctx->r16 = ADD32(ctx->r16, 0X78);
    // 0x800AF260: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AF264: bne         $at, $zero, L_800AF248
    if (ctx->r1 != 0) {
        // 0x800AF268: nop
    
            goto L_800AF248;
    }
    // 0x800AF268: nop

L_800AF26C:
    // 0x800AF26C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800AF270: nop

    // 0x800AF274: bne         $t6, $zero, L_800AF348
    if (ctx->r14 != 0) {
        // 0x800AF278: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AF348;
    }
    // 0x800AF278: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AF27C: jal         0x80076EE4
    // 0x800AF280: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    asset_table_load(rdram, ctx);
        goto after_13;
    // 0x800AF280: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_13:
    // 0x800AF284: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF288: addiu       $a2, $a2, 0x33F4
    ctx->r6 = ADD32(ctx->r6, 0X33F4);
    // 0x800AF28C: sll         $t4, $zero, 1
    ctx->r12 = S32(0 << 1);
    // 0x800AF290: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800AF294: addu        $t7, $v0, $t4
    ctx->r15 = ADD32(ctx->r2, ctx->r12);
    // 0x800AF298: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800AF29C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800AF2A0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800AF2A4: beq         $a0, $t8, L_800AF2CC
    if (ctx->r4 == ctx->r24) {
        // 0x800AF2A8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AF2CC;
    }
    // 0x800AF2A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AF2AC: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AF2B0:
    // 0x800AF2B0: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800AF2B4: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x800AF2B8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800AF2BC: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x800AF2C0: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800AF2C4: bne         $a0, $t3, L_800AF2B0
    if (ctx->r4 != ctx->r11) {
        // 0x800AF2C8: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_800AF2B0;
    }
    // 0x800AF2C8: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AF2CC:
    // 0x800AF2CC: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800AF2D0: jal         0x80070EDC
    // 0x800AF2D4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_14;
    // 0x800AF2D4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_14:
    // 0x800AF2D8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF2DC: addiu       $a2, $a2, 0x33F4
    ctx->r6 = ADD32(ctx->r6, 0X33F4);
    // 0x800AF2E0: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800AF2E4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800AF2E8: blez        $t5, L_800AF33C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800AF2EC: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800AF33C;
    }
    // 0x800AF2EC: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800AF2F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800AF2F4:
    // 0x800AF2F4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800AF2F8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800AF2FC: andi        $t6, $a0, 0x3FFF
    ctx->r14 = ctx->r4 & 0X3FFF;
    // 0x800AF300: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800AF304: jal         0x8007C57C
    // 0x800AF308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    tex_load_sprite(rdram, ctx);
        goto after_15;
    // 0x800AF308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x800AF30C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800AF310: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800AF314: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AF318: addu        $t7, $t4, $v1
    ctx->r15 = ADD32(ctx->r12, ctx->r3);
    // 0x800AF31C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x800AF320: addiu       $a2, $a2, 0x33F4
    ctx->r6 = ADD32(ctx->r6, 0X33F4);
    // 0x800AF324: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800AF328: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AF32C: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AF330: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800AF334: bne         $at, $zero, L_800AF2F4
    if (ctx->r1 != 0) {
        // 0x800AF338: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800AF2F4;
    }
    // 0x800AF338: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800AF33C:
    // 0x800AF33C: jal         0x80071380
    // 0x800AF340: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_16;
    // 0x800AF340: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_16:
    // 0x800AF344: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800AF348:
    // 0x800AF348: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AF34C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF350: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AF354: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AF358: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AF35C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AF360: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AF364: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800AF368: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800AF36C: jr          $ra
    // 0x800AF370: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AF370: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void set_current_dialogue_box_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C543C: blez        $a0, L_800C54D4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C5440: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C54D4;
    }
    // 0x800C5440: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C5444: beq         $at, $zero, L_800C54D4
    if (ctx->r1 == 0) {
        // 0x800C5448: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C54D4;
    }
    // 0x800C5448: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C544C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5450: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C5454: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5458: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C545C: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C5460: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5464: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800C5468: beq         $at, $zero, L_800C547C
    if (ctx->r1 == 0) {
        // 0x800C546C: sh          $zero, 0x2($v0)
        MEM_H(0X2, ctx->r2) = 0;
            goto L_800C547C;
    }
    // 0x800C546C: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x800C5470: sh          $a1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r5;
    // 0x800C5474: b           L_800C5484
    // 0x800C5478: sh          $a3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r7;
        goto L_800C5484;
    // 0x800C5478: sh          $a3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r7;
L_800C547C:
    // 0x800C547C: sh          $a1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r5;
    // 0x800C5480: sh          $a3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r7;
L_800C5484:
    // 0x800C5484: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800C5488: nop

    // 0x800C548C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C5490: beq         $at, $zero, L_800C54A4
    if (ctx->r1 == 0) {
        // 0x800C5494: nop
    
            goto L_800C54A4;
    }
    // 0x800C5494: nop

    // 0x800C5498: sh          $a2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r6;
    // 0x800C549C: b           L_800C54AC
    // 0x800C54A0: sh          $v1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r3;
        goto L_800C54AC;
    // 0x800C54A0: sh          $v1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r3;
L_800C54A4:
    // 0x800C54A4: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
    // 0x800C54A8: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
L_800C54AC:
    // 0x800C54AC: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x800C54B0: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800C54B4: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x800C54B8: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x800C54BC: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800C54C0: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800C54C4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C54C8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800C54CC: sh          $t1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r9;
    // 0x800C54D0: sh          $t5, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r13;
L_800C54D4:
    // 0x800C54D4: jr          $ra
    // 0x800C54D8: nop

    return;
    // 0x800C54D8: nop

;}
RECOMP_FUNC void sins_f(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070A04: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070A08: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070A0C: jal         0x80070A70
    // 0x80070A10: nop

    static_3_80070A70(rdram, ctx);
        goto after_0;
    // 0x80070A10: nop

    after_0:
    // 0x80070A14: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80070A18: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x80070A1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80070A20: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070A24: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070A28: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070A2C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80070A30: jr          $ra
    // 0x80070A34: nop

    return;
    // 0x80070A34: nop

;}
RECOMP_FUNC void init_pulsating_light_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F864: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8007F868: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F86C: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x8007F870: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x8007F874: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x8007F878: blez        $v1, L_8007F8A8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007F87C: sw          $t6, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r14;
            goto L_8007F8A8;
    }
    // 0x8007F87C: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8007F880: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8007F884: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x8007F888: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007F88C:
    // 0x8007F88C: lhu         $t8, 0x6($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X6);
    // 0x8007F890: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x8007F894: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8007F898: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8007F89C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8007F8A0: bne         $at, $zero, L_8007F88C
    if (ctx->r1 != 0) {
        // 0x8007F8A4: sh          $t0, 0x6($a0)
        MEM_H(0X6, ctx->r4) = ctx->r8;
            goto L_8007F88C;
    }
    // 0x8007F8A4: sh          $t0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r8;
L_8007F8A8:
    // 0x8007F8A8: jr          $ra
    // 0x8007F8AC: nop

    return;
    // 0x8007F8AC: nop

;}
RECOMP_FUNC void si_mesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A340: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A344: jr          $ra
    // 0x8006A348: addiu       $v0, $v0, 0x1660
    ctx->r2 = ADD32(ctx->r2, 0X1660);
    return;
    // 0x8006A348: addiu       $v0, $v0, 0x1660
    ctx->r2 = ADD32(ctx->r2, 0X1660);
;}
RECOMP_FUNC void hud_treasure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4B38: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A4B3C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800A4B40: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A4B44: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x800A4B48: addiu       $s7, $s7, 0x729C
    ctx->r23 = ADD32(ctx->r23, 0X729C);
    // 0x800A4B4C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A4B50: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800A4B54: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A4B58: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800A4B5C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800A4B60: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800A4B64: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800A4B68: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800A4B6C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800A4B70: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A4B74: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A4B78: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A4B7C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A4B80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A4B84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A4B88: lwc1        $f4, 0x410($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X410);
    // 0x800A4B8C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A4B90: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A4B94: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A4B98: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800A4B9C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A4BA0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800A4BA4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800A4BA8: bne         $at, $zero, L_800A4BCC
    if (ctx->r1 != 0) {
        // 0x800A4BAC: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_800A4BCC;
    }
    // 0x800A4BAC: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800A4BB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A4BB4: bne         $v0, $at, L_800A4C14
    if (ctx->r2 != ctx->r1) {
        // 0x800A4BB8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_800A4C14;
    }
    // 0x800A4BB8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800A4BBC: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x800A4BC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A4BC4: bne         $t8, $at, L_800A4C14
    if (ctx->r24 != ctx->r1) {
        // 0x800A4BC8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_800A4C14;
    }
    // 0x800A4BC8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_800A4BCC:
    // 0x800A4BCC: lb          $t9, 0x3($s6)
    ctx->r25 = MEM_B(ctx->r22, 0X3);
    // 0x800A4BD0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A4BD4: addiu       $t0, $t9, 0x38
    ctx->r8 = ADD32(ctx->r25, 0X38);
    // 0x800A4BD8: sh          $t0, 0x646($s1)
    MEM_H(0X646, ctx->r17) = ctx->r8;
    // 0x800A4BDC: lw          $a3, 0x0($s7)
    ctx->r7 = MEM_W(ctx->r23, 0X0);
    // 0x800A4BE0: addiu       $s2, $s2, 0x7295
    ctx->r18 = ADD32(ctx->r18, 0X7295);
    // 0x800A4BE4: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800A4BE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4BEC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4BF0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4BF4: sb          $fp, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r30;
    // 0x800A4BF8: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4BFC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4C00: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4C04: jal         0x800AAB5C
    // 0x800A4C08: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A4C08: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_0:
    // 0x800A4C0C: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800A4C10: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_800A4C14:
    // 0x800A4C14: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A4C18: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800A4C1C: lui         $s3, 0x8080
    ctx->r19 = S32(0X8080 << 16);
    // 0x800A4C20: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A4C24: addiu       $s2, $s2, 0x7295
    ctx->r18 = ADD32(ctx->r18, 0X7295);
    // 0x800A4C28: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800A4C2C: ori         $s3, $s3, 0x8080
    ctx->r19 = ctx->r19 | 0X8080;
    // 0x800A4C30: addiu       $s5, $s5, 0x2DB4
    ctx->r21 = ADD32(ctx->r21, 0X2DB4);
    // 0x800A4C34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A4C38: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_800A4C3C:
    // 0x800A4C3C: lb          $t1, 0x193($s6)
    ctx->r9 = MEM_B(ctx->r22, 0X193);
    // 0x800A4C40: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800A4C44: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A4C48: bne         $at, $zero, L_800A4C54
    if (ctx->r1 != 0) {
        // 0x800A4C4C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A4C54;
    }
    // 0x800A4C4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4C50: sw          $s3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r19;
L_800A4C54:
    // 0x800A4C54: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4C58: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4C5C: sb          $fp, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r30;
    // 0x800A4C60: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A4C64: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A4C68: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A4C6C: jal         0x800AAB5C
    // 0x800A4C70: addiu       $a3, $s1, 0x400
    ctx->r7 = ADD32(ctx->r17, 0X400);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A4C70: addiu       $a3, $s1, 0x400
    ctx->r7 = ADD32(ctx->r17, 0X400);
    after_1:
    // 0x800A4C74: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800A4C78: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800A4C7C: lwc1        $f8, 0x410($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X410);
    // 0x800A4C80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A4C84: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800A4C88: bne         $s0, $s4, L_800A4C3C
    if (ctx->r16 != ctx->r20) {
        // 0x800A4C8C: swc1        $f10, 0x410($s1)
        MEM_W(0X410, ctx->r17) = ctx->f10.u32l;
            goto L_800A4C3C;
    }
    // 0x800A4C8C: swc1        $f10, 0x410($s1)
    MEM_W(0X410, ctx->r17) = ctx->f10.u32l;
    // 0x800A4C90: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800A4C94: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x800A4C98: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800A4C9C: addiu       $t4, $zero, -0x2
    ctx->r12 = ADD32(0, -0X2);
    // 0x800A4CA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A4CA4: swc1        $f18, 0x410($t3)
    MEM_W(0X410, ctx->r11) = ctx->f18.u32l;
    // 0x800A4CA8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800A4CAC: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x800A4CB0: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800A4CB4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A4CB8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800A4CBC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800A4CC0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4CC4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800A4CC8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800A4CCC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4CD0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A4CD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A4CD8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A4CDC: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A4CE0: jr          $ra
    // 0x800A4CE4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800A4CE4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void obj_loop_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038E04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038E0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038E10: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80038E14: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80038E18: beq         $t6, $zero, L_80038E70
    if (ctx->r14 == 0) {
        // 0x80038E1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038E70;
    }
    // 0x80038E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038E20: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038E24: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x80038E28: lbu         $t8, 0x13($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X13);
    // 0x80038E2C: nop

    // 0x80038E30: slti        $at, $t8, 0x78
    ctx->r1 = SIGNED(ctx->r24) < 0X78 ? 1 : 0;
    // 0x80038E34: beq         $at, $zero, L_80038E70
    if (ctx->r1 == 0) {
        // 0x80038E38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038E70;
    }
    // 0x80038E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038E3C: lb          $a0, 0x8($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X8);
    // 0x80038E40: jal         0x8006F578
    // 0x80038E44: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    begin_level_teleport(rdram, ctx);
        goto after_0;
    // 0x80038E44: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80038E48: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80038E4C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80038E50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038E54: jal         0x80001D04
    // 0x80038E58: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80038E58: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    after_1:
    // 0x80038E5C: addiu       $a0, $zero, 0x12A
    ctx->r4 = ADD32(0, 0X12A);
    // 0x80038E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038E64: jal         0x80000FDC
    // 0x80038E68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_2;
    // 0x80038E68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x80038E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038E70:
    // 0x80038E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038E74: jr          $ra
    // 0x80038E78: nop

    return;
    // 0x80038E78: nop

;}
RECOMP_FUNC void cutscene_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E474: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E478: lh          $v0, -0x4C06($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4C06);
    // 0x8001E47C: jr          $ra
    // 0x8001E480: nop

    return;
    // 0x8001E480: nop

;}
RECOMP_FUNC void obj_init_texscroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800400E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800400E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800400EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800400F0: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x800400F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800400F8: jal         0x8002C804
    // 0x800400FC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x800400FC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80040100: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80040104: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80040108: lh          $t6, 0x8($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X8);
    // 0x8004010C: nop

    // 0x80040110: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x80040114: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80040118: nop

    // 0x8004011C: bgez        $a0, L_80040130
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80040120: nop
    
            goto L_80040130;
    }
    // 0x80040120: nop

    // 0x80040124: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80040128: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x8004012C: nop

L_80040130:
    // 0x80040130: lh          $a1, 0x18($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X18);
    // 0x80040134: nop

    // 0x80040138: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8004013C: bne         $at, $zero, L_80040148
    if (ctx->r1 != 0) {
        // 0x80040140: addiu       $t7, $a1, -0x1
        ctx->r15 = ADD32(ctx->r5, -0X1);
            goto L_80040148;
    }
    // 0x80040140: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x80040144: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
L_80040148:
    // 0x80040148: lb          $t8, 0xA($a3)
    ctx->r24 = MEM_B(ctx->r7, 0XA);
    // 0x8004014C: nop

    // 0x80040150: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80040154: lb          $t9, 0xB($a3)
    ctx->r25 = MEM_B(ctx->r7, 0XB);
    // 0x80040158: nop

    // 0x8004015C: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
    // 0x80040160: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80040164: nop

    // 0x80040168: bne         $t0, $zero, L_8004017C
    if (ctx->r8 != 0) {
        // 0x8004016C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004017C;
    }
    // 0x8004016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040170: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x80040174: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x80040178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004017C:
    // 0x8004017C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80040180: jr          $ra
    // 0x80040184: nop

    return;
    // 0x80040184: nop

;}
RECOMP_FUNC void alAuxBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B40: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80065B44: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80065B48: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80065B4C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80065B50: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80065B54: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80065B58: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80065B5C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80065B60: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80065B64: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80065B68: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80065B6C: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x80065B70: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80065B74: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x80065B78: ori         $t6, $t6, 0x6C0
    ctx->r14 = ctx->r14 | 0X6C0;
    // 0x80065B7C: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x80065B80: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80065B84: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80065B88: sw          $t7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r15;
    // 0x80065B8C: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80065B90: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x80065B94: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80065B98: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80065B9C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x80065BA0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80065BA4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80065BA8: blez        $t8, L_80065BE8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80065BAC: addiu       $s2, $s1, 0x10
        ctx->r18 = ADD32(ctx->r17, 0X10);
            goto L_80065BE8;
    }
    // 0x80065BAC: addiu       $s2, $s1, 0x10
    ctx->r18 = ADD32(ctx->r17, 0X10);
    // 0x80065BB0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_80065BB4:
    // 0x80065BB4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80065BB8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80065BBC: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80065BC0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80065BC4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80065BC8: jalr        $t9
    // 0x80065BCC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80065BCC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_0:
    // 0x80065BD0: lw          $t0, 0x14($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X14);
    // 0x80065BD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065BD8: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80065BDC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80065BE0: bne         $at, $zero, L_80065BB4
    if (ctx->r1 != 0) {
        // 0x80065BE4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80065BB4;
    }
    // 0x80065BE4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80065BE8:
    // 0x80065BE8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80065BEC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80065BF0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80065BF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80065BF8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80065BFC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80065C00: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80065C04: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80065C08: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80065C0C: jr          $ra
    // 0x80065C10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80065C10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void transition_init_shape(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1020: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C1024: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800C1028: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x800C102C: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x800C1030: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800C1034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C1038: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800C103C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800C1040: sll         $t0, $a2, 4
    ctx->r8 = S32(ctx->r6 << 4);
    // 0x800C1044: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C1048: addu        $t6, $v1, $t0
    ctx->r14 = ADD32(ctx->r3, ctx->r8);
    // 0x800C104C: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800C1050: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C1054: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C1058: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C105C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800C1060: subu        $t8, $t8, $t1
    ctx->r24 = SUB32(ctx->r24, ctx->r9);
    // 0x800C1064: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800C1068: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x800C106C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800C1070: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800C1074: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C1078: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800C107C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800C1080: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800C1084: jal         0x80070EDC
    // 0x800C1088: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C1088: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x800C108C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800C1090: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800C1094: addiu       $a0, $a0, 0x3750
    ctx->r4 = ADD32(ctx->r4, 0X3750);
    // 0x800C1098: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C109C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C10A0: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x800C10A4: sw          $t4, 0x3754($at)
    MEM_W(0X3754, ctx->r1) = ctx->r12;
    // 0x800C10A8: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x800C10AC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C10B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C10B4: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x800C10B8: addiu       $a1, $a1, 0x3758
    ctx->r5 = ADD32(ctx->r5, 0X3758);
    // 0x800C10BC: sw          $t6, 0x3758($at)
    MEM_W(0X3758, ctx->r1) = ctx->r14;
    // 0x800C10C0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C10C4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800C10C8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C10CC: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x800C10D0: sw          $t8, 0x375C($at)
    MEM_W(0X375C, ctx->r1) = ctx->r24;
    // 0x800C10D4: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800C10D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C10DC: addu        $t4, $t9, $t0
    ctx->r12 = ADD32(ctx->r25, ctx->r8);
    // 0x800C10E0: addiu       $a2, $a2, -0x52D0
    ctx->r6 = ADD32(ctx->r6, -0X52D0);
    // 0x800C10E4: sw          $t4, -0x52D0($at)
    MEM_W(-0X52D0, ctx->r1) = ctx->r12;
    // 0x800C10E8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C10EC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C10F0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C10F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C10F8: addu        $t6, $t5, $t1
    ctx->r14 = ADD32(ctx->r13, ctx->r9);
    // 0x800C10FC: addiu       $t3, $t3, -0x52CC
    ctx->r11 = ADD32(ctx->r11, -0X52CC);
    // 0x800C1100: sw          $t6, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r14;
    // 0x800C1104: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800C1108: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800C110C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1110: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x800C1114: sw          $t8, -0x52C8($at)
    MEM_W(-0X52C8, ctx->r1) = ctx->r24;
    // 0x800C1118: lbu         $t4, 0x0($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X0);
    // 0x800C111C: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800C1120: andi        $t5, $t4, 0x80
    ctx->r13 = ctx->r12 & 0X80;
    // 0x800C1124: beq         $t5, $zero, L_800C1148
    if (ctx->r13 == 0) {
        // 0x800C1128: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_800C1148;
    }
    // 0x800C1128: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C112C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800C1130: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800C1134: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800C1138: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800C113C: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x800C1140: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x800C1144: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
L_800C1148:
    // 0x800C1148: blez        $s0, L_800C137C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800C114C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800C137C;
    }
    // 0x800C114C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800C1150: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C1154: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800C1158: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800C115C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800C1160: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800C1164: addiu       $v1, $v1, -0x52C8
    ctx->r3 = ADD32(ctx->r3, -0X52C8);
    // 0x800C1168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C116C: addiu       $t1, $t1, 0x3740
    ctx->r9 = ADD32(ctx->r9, 0X3740);
L_800C1170:
    // 0x800C1170: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1174: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C1178: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C117C: addu        $t4, $s2, $t9
    ctx->r12 = ADD32(ctx->r18, ctx->r25);
    // 0x800C1180: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800C1184: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1188: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C118C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1190: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C1194: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x800C1198: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800C119C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C11A0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C11A4: addu        $t4, $s2, $t9
    ctx->r12 = ADD32(ctx->r18, ctx->r25);
    // 0x800C11A8: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x800C11AC: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C11B0: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800C11B4: nop

    // 0x800C11B8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C11BC: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x800C11C0: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x800C11C4: nop

    // 0x800C11C8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800C11CC: bgez        $t8, L_800C11E0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C11D0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800C11E0;
    }
    // 0x800C11D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C11D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C11D8: nop

    // 0x800C11DC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800C11E0:
    // 0x800C11E0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C11E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C11E8: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C11EC: swc1        $f18, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f18.u32l;
    // 0x800C11F0: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x800C11F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C11F8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800C11FC: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x800C1200: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800C1204: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1208: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800C120C: nop

    // 0x800C1210: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C1214: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x800C1218: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x800C121C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1220: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800C1224: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x800C1228: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800C122C: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1230: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800C1234: nop

    // 0x800C1238: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C123C: swc1        $f16, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f16.u32l;
    // 0x800C1240: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800C1244: nop

    // 0x800C1248: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C124C: bgez        $t5, L_800C1260
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C1250: cvt.s.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C1260;
    }
    // 0x800C1250: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C1254: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C1258: nop

    // 0x800C125C: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_800C1260:
    // 0x800C1260: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1264: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1268: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C126C: swc1        $f18, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f18.u32l;
    // 0x800C1270: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C1274: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C1278: lhu         $t6, 0x0($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X0);
    // 0x800C127C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1280: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C1284: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800C1288: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800C128C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800C1290: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800C1294: bgez        $t6, L_800C12A8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800C1298: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C12A8;
    }
    // 0x800C1298: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C129C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C12A0: nop

    // 0x800C12A4: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_800C12A8:
    // 0x800C12A8: nop

    // 0x800C12AC: div.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800C12B0: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800C12B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C12B8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C12BC: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x800C12C0: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800C12C4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C12C8: lhu         $t7, 0x0($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X0);
    // 0x800C12CC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C12D0: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C12D4: lwc1        $f10, 0x4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C12D8: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800C12DC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800C12E0: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800C12E4: bgez        $t7, L_800C12F8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C12E8: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800C12F8;
    }
    // 0x800C12E8: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C12EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C12F0: nop

    // 0x800C12F4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800C12F8:
    // 0x800C12F8: nop

    // 0x800C12FC: div.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800C1300: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x800C1304: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C1308: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C130C: swc1        $f10, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f10.u32l;
    // 0x800C1310: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C1314: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C1318: lhu         $t8, 0x0($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X0);
    // 0x800C131C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1320: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1324: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x800C1328: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800C132C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800C1330: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800C1334: bgez        $t8, L_800C1348
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C1338: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800C1348;
    }
    // 0x800C1338: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C133C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C1340: nop

    // 0x800C1344: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800C1348:
    // 0x800C1348: nop

    // 0x800C134C: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C1350: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x800C1354: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C1358: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C135C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C1360: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C1364: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C1368: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C136C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C1370: bne         $t2, $s0, L_800C1170
    if (ctx->r10 != ctx->r16) {
        // 0x800C1374: swc1        $f4, 0x8($t4)
        MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
            goto L_800C1170;
    }
    // 0x800C1374: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
    // 0x800C1378: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_800C137C:
    // 0x800C137C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C1380: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C1384: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C1388: addiu       $a2, $a2, -0x530C
    ctx->r6 = ADD32(ctx->r6, -0X530C);
    // 0x800C138C: addiu       $a3, $a3, -0x530B
    ctx->r7 = ADD32(ctx->r7, -0X530B);
    // 0x800C1390: addiu       $t0, $t0, -0x530A
    ctx->r8 = ADD32(ctx->r8, -0X530A);
    // 0x800C1394: addiu       $a0, $zero, -0x10
    ctx->r4 = ADD32(0, -0X10);
L_800C1398:
    // 0x800C1398: blez        $s0, L_800C1530
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800C139C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800C1530;
    }
    // 0x800C139C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C13A0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C13A4: addiu       $t6, $t6, 0x3750
    ctx->r14 = ADD32(ctx->r14, 0X3750);
    // 0x800C13A8: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x800C13AC: andi        $t3, $s0, 0x3
    ctx->r11 = ctx->r16 & 0X3;
    // 0x800C13B0: beq         $t3, $zero, L_800C1410
    if (ctx->r11 == 0) {
        // 0x800C13B4: addu        $v1, $t5, $t6
        ctx->r3 = ADD32(ctx->r13, ctx->r14);
            goto L_800C1410;
    }
    // 0x800C13B4: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x800C13B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C13BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C13C0: or          $t1, $t3, $zero
    ctx->r9 = ctx->r11 | 0;
L_800C13C4:
    // 0x800C13C4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C13C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C13CC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C13D0: sh          $a0, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r4;
    // 0x800C13D4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C13D8: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800C13DC: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C13E0: sb          $t9, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r25;
    // 0x800C13E4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C13E8: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x800C13EC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C13F0: sb          $t6, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r14;
    // 0x800C13F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C13F8: lbu         $t4, 0x0($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X0);
    // 0x800C13FC: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1400: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800C1404: bne         $t1, $a1, L_800C13C4
    if (ctx->r9 != ctx->r5) {
        // 0x800C1408: sb          $t4, 0x8($t5)
        MEM_B(0X8, ctx->r13) = ctx->r12;
            goto L_800C13C4;
    }
    // 0x800C1408: sb          $t4, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r12;
    // 0x800C140C: beq         $a1, $s0, L_800C1530
    if (ctx->r5 == ctx->r16) {
        // 0x800C1410: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_800C1530;
    }
L_800C1410:
    // 0x800C1410: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800C1414: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800C1418: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x800C141C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C1420: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C1424: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
L_800C1428:
    // 0x800C1428: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C142C: nop

    // 0x800C1430: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1434: sh          $a0, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r4;
    // 0x800C1438: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C143C: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1440: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1444: sb          $t8, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r24;
    // 0x800C1448: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C144C: lbu         $t5, 0x0($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X0);
    // 0x800C1450: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1454: sb          $t5, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r13;
    // 0x800C1458: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C145C: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x800C1460: addu        $t4, $t8, $v0
    ctx->r12 = ADD32(ctx->r24, ctx->r2);
    // 0x800C1464: sb          $t9, 0x8($t4)
    MEM_B(0X8, ctx->r12) = ctx->r25;
    // 0x800C1468: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C146C: nop

    // 0x800C1470: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1474: sh          $a0, 0xE($t5)
    MEM_H(0XE, ctx->r13) = ctx->r4;
    // 0x800C1478: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C147C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1480: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C1484: sb          $t6, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r14;
    // 0x800C1488: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C148C: lbu         $t4, 0x0($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X0);
    // 0x800C1490: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1494: sb          $t4, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r12;
    // 0x800C1498: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C149C: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x800C14A0: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x800C14A4: sb          $t8, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r24;
    // 0x800C14A8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C14AC: nop

    // 0x800C14B0: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800C14B4: sh          $a0, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r4;
    // 0x800C14B8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C14BC: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x800C14C0: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800C14C4: sb          $t5, 0x1A($t8)
    MEM_B(0X1A, ctx->r24) = ctx->r13;
    // 0x800C14C8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C14CC: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x800C14D0: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800C14D4: sb          $t9, 0x1B($t4)
    MEM_B(0X1B, ctx->r12) = ctx->r25;
    // 0x800C14D8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C14DC: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x800C14E0: addu        $t8, $t5, $v0
    ctx->r24 = ADD32(ctx->r13, ctx->r2);
    // 0x800C14E4: sb          $t6, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r14;
    // 0x800C14E8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C14EC: nop

    // 0x800C14F0: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C14F4: sh          $a0, 0x22($t9)
    MEM_H(0X22, ctx->r25) = ctx->r4;
    // 0x800C14F8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C14FC: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x800C1500: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C1504: sb          $t4, 0x24($t6)
    MEM_B(0X24, ctx->r14) = ctx->r12;
    // 0x800C1508: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C150C: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x800C1510: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1514: sb          $t8, 0x25($t9)
    MEM_B(0X25, ctx->r25) = ctx->r24;
    // 0x800C1518: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C151C: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800C1520: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1524: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800C1528: bne         $v0, $t1, L_800C1428
    if (ctx->r2 != ctx->r9) {
        // 0x800C152C: sb          $t5, 0x26($t6)
        MEM_B(0X26, ctx->r14) = ctx->r13;
            goto L_800C1428;
    }
    // 0x800C152C: sb          $t5, 0x26($t6)
    MEM_B(0X26, ctx->r14) = ctx->r13;
L_800C1530:
    // 0x800C1530: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C1534: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800C1538: bne         $at, $zero, L_800C1398
    if (ctx->r1 != 0) {
        // 0x800C153C: nop
    
            goto L_800C1398;
    }
    // 0x800C153C: nop

    // 0x800C1540: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800C1544: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800C1548: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C154C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
L_800C1550:
    // 0x800C1550: blez        $s1, L_800C1618
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800C1554: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800C1618;
    }
    // 0x800C1554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C1558: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C155C: addiu       $t8, $t8, 0x3758
    ctx->r24 = ADD32(ctx->r24, 0X3758);
    // 0x800C1560: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800C1564: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800C1568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C156C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_800C1570:
    // 0x800C1570: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C1574: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C1578: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C157C: sb          $a2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r6;
    // 0x800C1580: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C1584: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800C1588: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C158C: sb          $t5, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r13;
    // 0x800C1590: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C1594: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800C1598: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C159C: sh          $zero, 0x4($t9)
    MEM_H(0X4, ctx->r25) = 0;
    // 0x800C15A0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C15A4: nop

    // 0x800C15A8: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C15AC: sh          $zero, 0x6($t6)
    MEM_H(0X6, ctx->r14) = 0;
    // 0x800C15B0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C15B4: lbu         $t5, -0x2($a0)
    ctx->r13 = MEM_BU(ctx->r4, -0X2);
    // 0x800C15B8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C15BC: sb          $t5, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r13;
    // 0x800C15C0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800C15C4: nop

    // 0x800C15C8: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C15CC: sh          $zero, 0x8($t4)
    MEM_H(0X8, ctx->r12) = 0;
    // 0x800C15D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C15D4: nop

    // 0x800C15D8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C15DC: sh          $zero, 0xA($t7)
    MEM_H(0XA, ctx->r15) = 0;
    // 0x800C15E0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800C15E4: lbu         $t5, -0x1($a0)
    ctx->r13 = MEM_BU(ctx->r4, -0X1);
    // 0x800C15E8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C15EC: sb          $t5, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r13;
    // 0x800C15F0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800C15F4: nop

    // 0x800C15F8: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800C15FC: sh          $zero, 0xC($t6)
    MEM_H(0XC, ctx->r14) = 0;
    // 0x800C1600: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800C1604: nop

    // 0x800C1608: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C160C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C1610: bne         $a1, $s1, L_800C1570
    if (ctx->r5 != ctx->r17) {
        // 0x800C1614: sh          $zero, 0xE($t8)
        MEM_H(0XE, ctx->r24) = 0;
            goto L_800C1570;
    }
    // 0x800C1614: sh          $zero, 0xE($t8)
    MEM_H(0XE, ctx->r24) = 0;
L_800C1618:
    // 0x800C1618: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C161C: bne         $t2, $t0, L_800C1550
    if (ctx->r10 != ctx->r8) {
        // 0x800C1620: nop
    
            goto L_800C1550;
    }
    // 0x800C1620: nop

    // 0x800C1624: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800C1628: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C162C: sw          $t5, 0x373C($at)
    MEM_W(0X373C, ctx->r1) = ctx->r13;
    // 0x800C1630: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C1638: sw          $s0, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = ctx->r16;
    // 0x800C163C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C1640: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1644: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C1648: jr          $ra
    // 0x800C164C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C164C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void get_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E948: bltz        $a0, L_8000E964
    if (SIGNED(ctx->r4) < 0) {
        // 0x8000E94C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8000E964;
    }
    // 0x8000E94C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E950: lw          $t6, -0x4C24($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C24);
    // 0x8000E954: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000E958: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000E95C: bne         $at, $zero, L_8000E96C
    if (ctx->r1 != 0) {
        // 0x8000E960: nop
    
            goto L_8000E96C;
    }
    // 0x8000E960: nop

L_8000E964:
    // 0x8000E964: jr          $ra
    // 0x8000E968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000E968: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E96C:
    // 0x8000E96C: lw          $t7, -0x4C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C28);
    // 0x8000E970: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8000E974: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8000E978: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8000E97C: nop

    // 0x8000E980: jr          $ra
    // 0x8000E984: nop

    return;
    // 0x8000E984: nop

;}
RECOMP_FUNC void move_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011570: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80011574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011578: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8001157C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80011580: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80011584: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80011588: jal         0x8002C804
    // 0x8001158C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x8001158C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80011590: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80011594: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80011598: lwc1        $f14, 0x10($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8001159C: lwc1        $f2, 0xC($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800115A0: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x800115A4: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800115A8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800115AC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800115B0: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800115B4: add.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800115B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800115BC: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800115C0: bne         $v0, $zero, L_800115D8
    if (ctx->r2 != 0) {
        // 0x800115C4: swc1        $f4, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
            goto L_800115D8;
    }
    // 0x800115C4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800115C8: addiu       $a0, $a0, -0x3248
    ctx->r4 = ADD32(ctx->r4, -0X3248);
    // 0x800115CC: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x800115D0: b           L_80011950
    // 0x800115D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011950;
    // 0x800115D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800115D8:
    // 0x800115D8: lh          $t6, 0x3E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X3E);
    // 0x800115DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800115E0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800115E4: lwc1        $f13, 0x5AC8($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X5AC8);
    // 0x800115E8: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800115EC: lwc1        $f12, 0x5ACC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5ACC);
    // 0x800115F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800115F4: add.d       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f8.d + ctx->f12.d;
    // 0x800115F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800115FC: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80011600: addiu       $a0, $a0, -0x3248
    ctx->r4 = ADD32(ctx->r4, -0X3248);
    // 0x80011604: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80011608: nop

    // 0x8001160C: bc1f        L_80011618
    if (!c1cs) {
        // 0x80011610: nop
    
            goto L_80011618;
    }
    // 0x80011610: nop

    // 0x80011614: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011618:
    // 0x80011618: lh          $t7, 0x3C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3C);
    // 0x8001161C: nop

    // 0x80011620: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80011624: nop

    // 0x80011628: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8001162C: sub.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f6.d - ctx->f12.d;
    // 0x80011630: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80011634: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80011638: nop

    // 0x8001163C: bc1f        L_80011648
    if (!c1cs) {
        // 0x80011640: nop
    
            goto L_80011648;
    }
    // 0x80011640: nop

    // 0x80011644: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011648:
    // 0x80011648: lh          $t8, 0x42($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X42);
    // 0x8001164C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011650: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80011654: lwc1        $f7, 0x5AD0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5AD0);
    // 0x80011658: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8001165C: lwc1        $f6, 0x5AD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5AD4);
    // 0x80011660: nop

    // 0x80011664: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80011668: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x8001166C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80011670: nop

    // 0x80011674: bc1f        L_80011680
    if (!c1cs) {
        // 0x80011678: nop
    
            goto L_80011680;
    }
    // 0x80011678: nop

    // 0x8001167C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011680:
    // 0x80011680: lh          $t9, 0x40($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X40);
    // 0x80011684: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011688: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8001168C: lwc1        $f7, 0x5AD8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5AD8);
    // 0x80011690: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x80011694: lwc1        $f6, 0x5ADC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5ADC);
    // 0x80011698: nop

    // 0x8001169C: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x800116A0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800116A4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800116A8: nop

    // 0x800116AC: bc1f        L_800116B8
    if (!c1cs) {
        // 0x800116B0: nop
    
            goto L_800116B8;
    }
    // 0x800116B0: nop

    // 0x800116B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800116B8:
    // 0x800116B8: lh          $t1, 0x46($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X46);
    // 0x800116BC: nop

    // 0x800116C0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800116C4: nop

    // 0x800116C8: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x800116CC: add.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f4.d + ctx->f12.d;
    // 0x800116D0: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800116D4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800116D8: nop

    // 0x800116DC: bc1f        L_800116E8
    if (!c1cs) {
        // 0x800116E0: nop
    
            goto L_800116E8;
    }
    // 0x800116E0: nop

    // 0x800116E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800116E8:
    // 0x800116E8: lh          $t2, 0x44($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X44);
    // 0x800116EC: nop

    // 0x800116F0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800116F4: nop

    // 0x800116F8: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800116FC: sub.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f10.d - ctx->f12.d;
    // 0x80011700: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x80011704: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80011708: nop

    // 0x8001170C: bc1f        L_80011718
    if (!c1cs) {
        // 0x80011710: nop
    
            goto L_80011718;
    }
    // 0x80011710: nop

    // 0x80011714: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80011718:
    // 0x80011718: lb          $t3, 0x0($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X0);
    // 0x8001171C: nop

    // 0x80011720: beq         $t3, $zero, L_8001172C
    if (ctx->r11 == 0) {
        // 0x80011724: nop
    
            goto L_8001172C;
    }
    // 0x80011724: nop

    // 0x80011728: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001172C:
    // 0x8001172C: beq         $v1, $zero, L_80011744
    if (ctx->r3 == 0) {
        // 0x80011730: sb          $zero, 0x0($a0)
        MEM_B(0X0, ctx->r4) = 0;
            goto L_80011744;
    }
    // 0x80011730: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80011734: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80011738: sh          $t4, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r12;
    // 0x8001173C: b           L_80011950
    // 0x80011740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80011950;
    // 0x80011740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80011744:
    // 0x80011744: swc1        $f18, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f18.u32l;
    // 0x80011748: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001174C: lh          $a0, 0x2E($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X2E);
    // 0x80011750: swc1        $f6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f6.u32l;
    // 0x80011754: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80011758: nop

    // 0x8001175C: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    // 0x80011760: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80011764: jal         0x8002A31C
    // 0x80011768: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    block_boundbox(rdram, ctx);
        goto after_1;
    // 0x80011768: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_1:
    // 0x8001176C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80011770: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80011774: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80011778: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001177C: bne         $v0, $zero, L_80011834
    if (ctx->r2 != 0) {
        // 0x80011780: nop
    
            goto L_80011834;
    }
    // 0x80011780: nop

    // 0x80011784: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80011788: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8001178C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80011790: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80011794: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011798: nop

    // 0x8001179C: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800117A0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800117A4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800117A8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800117AC: nop

    // 0x800117B0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800117B4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800117B8: nop

    // 0x800117BC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800117C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800117C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800117C8: nop

    // 0x800117CC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800117D0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800117D4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800117D8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800117DC: nop

    // 0x800117E0: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800117E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800117E8: nop

    // 0x800117EC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800117F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800117F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800117F8: nop

    // 0x800117FC: cvt.w.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80011800: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80011804: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80011808: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8001180C: nop

    // 0x80011810: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011814: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80011818: jal         0x80029F58
    // 0x8001181C: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_2;
    // 0x8001181C: nop

    after_2:
    // 0x80011820: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80011824: nop

    // 0x80011828: sh          $v0, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r2;
    // 0x8001182C: b           L_80011950
    // 0x80011830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80011950;
    // 0x80011830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011834:
    // 0x80011834: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80011838: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8001183C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80011840: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80011844: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001184C: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80011850: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80011854: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80011858: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001185C: bne         $at, $zero, L_80011878
    if (ctx->r1 != 0) {
        // 0x80011860: nop
    
            goto L_80011878;
    }
    // 0x80011860: nop

    // 0x80011864: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x80011868: nop

    // 0x8001186C: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80011870: beq         $at, $zero, L_8001187C
    if (ctx->r1 == 0) {
        // 0x80011874: nop
    
            goto L_8001187C;
    }
    // 0x80011874: nop

L_80011878:
    // 0x80011878: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001187C:
    // 0x8001187C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80011880: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80011884: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80011888: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001188C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011890: nop

    // 0x80011894: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80011898: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8001189C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800118A0: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800118A4: bne         $at, $zero, L_800118C0
    if (ctx->r1 != 0) {
        // 0x800118A8: nop
    
            goto L_800118C0;
    }
    // 0x800118A8: nop

    // 0x800118AC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800118B0: nop

    // 0x800118B4: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800118B8: beq         $at, $zero, L_800118C4
    if (ctx->r1 == 0) {
        // 0x800118BC: nop
    
            goto L_800118C4;
    }
    // 0x800118BC: nop

L_800118C0:
    // 0x800118C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800118C4:
    // 0x800118C4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800118C8: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x800118CC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800118D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800118D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800118D8: nop

    // 0x800118DC: cvt.w.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = CVT_W_S(ctx->f2.fl);
    // 0x800118E0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800118E4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800118E8: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800118EC: bne         $at, $zero, L_80011908
    if (ctx->r1 != 0) {
        // 0x800118F0: nop
    
            goto L_80011908;
    }
    // 0x800118F0: nop

    // 0x800118F4: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x800118F8: nop

    // 0x800118FC: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80011900: beq         $at, $zero, L_8001190C
    if (ctx->r1 == 0) {
        // 0x80011904: nop
    
            goto L_8001190C;
    }
    // 0x80011904: nop

L_80011908:
    // 0x80011908: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8001190C:
    // 0x8001190C: beq         $a0, $zero, L_80011950
    if (ctx->r4 == 0) {
        // 0x80011910: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80011950;
    }
    // 0x80011910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011914: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80011918: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8001191C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80011920: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80011924: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80011928: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8001192C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011930: jal         0x80029F58
    // 0x80011934: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    get_level_segment_index_from_position(rdram, ctx);
        goto after_3;
    // 0x80011934: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_3:
    // 0x80011938: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8001193C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80011940: beq         $v0, $at, L_8001194C
    if (ctx->r2 == ctx->r1) {
        // 0x80011944: nop
    
            goto L_8001194C;
    }
    // 0x80011944: nop

    // 0x80011948: sh          $v0, 0x2E($a3)
    MEM_H(0X2E, ctx->r7) = ctx->r2;
L_8001194C:
    // 0x8001194C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011950:
    // 0x80011950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011954: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80011958: jr          $ra
    // 0x8001195C: nop

    return;
    // 0x8001195C: nop

;}
RECOMP_FUNC void hud_audio_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1114: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A1118: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A111C: addiu       $v1, $v1, 0x7334
    ctx->r3 = ADD32(ctx->r3, 0X7334);
    // 0x800A1120: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800A1124: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A1128: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800A112C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800A1130: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800A1134: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800A1138: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A113C: blez        $v0, L_800A1174
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A1140: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800A1174;
    }
    // 0x800A1140: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A1144: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800A1148: bgtz        $t6, L_800A1174
    if (SIGNED(ctx->r14) > 0) {
        // 0x800A114C: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_800A1174;
    }
    // 0x800A114C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800A1150: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1154: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A1158: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800A115C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800A1160: bne         $t8, $zero, L_800A1174
    if (ctx->r24 != 0) {
        // 0x800A1164: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A1174;
    }
    // 0x800A1164: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A1168: lhu         $a0, 0x733C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X733C);
    // 0x800A116C: jal         0x80001D04
    // 0x800A1170: nop

    sound_play(rdram, ctx);
        goto after_0;
    // 0x800A1170: nop

    after_0:
L_800A1174:
    // 0x800A1174: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800A1178: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800A117C: addiu       $s3, $s3, 0x2D10
    ctx->r19 = ADD32(ctx->r19, 0X2D10);
    // 0x800A1180: addiu       $s0, $s0, 0x2CF0
    ctx->r16 = ADD32(ctx->r16, 0X2CF0);
    // 0x800A1184: addiu       $s4, $zero, 0x7F
    ctx->r20 = ADD32(0, 0X7F);
    // 0x800A1188: addiu       $s2, $zero, 0x7F
    ctx->r18 = ADD32(0, 0X7F);
L_800A118C:
    // 0x800A118C: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800A1190: nop

    // 0x800A1194: beq         $a2, $zero, L_800A1248
    if (ctx->r6 == 0) {
        // 0x800A1198: nop
    
            goto L_800A1248;
    }
    // 0x800A1198: nop

    // 0x800A119C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800A11A0: nop

    // 0x800A11A4: bne         $a1, $zero, L_800A11C4
    if (ctx->r5 != 0) {
        // 0x800A11A8: nop
    
            goto L_800A11C4;
    }
    // 0x800A11A8: nop

    // 0x800A11AC: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800A11B0: jal         0x80001D04
    // 0x800A11B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800A11B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x800A11B8: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800A11BC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800A11C0: nop

L_800A11C4:
    // 0x800A11C4: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x800A11C8: jal         0x80001FB8
    // 0x800A11CC: nop

    sound_volume_set_relative(rdram, ctx);
        goto after_2;
    // 0x800A11CC: nop

    after_2:
    // 0x800A11D0: lb          $a0, 0x3($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X3);
    // 0x800A11D4: nop

    // 0x800A11D8: blez        $a0, L_800A1210
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800A11DC: nop
    
            goto L_800A1210;
    }
    // 0x800A11DC: nop

    // 0x800A11E0: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A11E4: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x800A11E8: mflo        $v0
    ctx->r2 = lo;
    // 0x800A11EC: subu        $t9, $s2, $v0
    ctx->r25 = SUB32(ctx->r18, ctx->r2);
    // 0x800A11F0: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A11F4: bne         $at, $zero, L_800A1204
    if (ctx->r1 != 0) {
        // 0x800A11F8: addu        $t0, $v1, $v0
        ctx->r8 = ADD32(ctx->r3, ctx->r2);
            goto L_800A1204;
    }
    // 0x800A11F8: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x800A11FC: b           L_800A1264
    // 0x800A1200: sb          $t0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r8;
        goto L_800A1264;
    // 0x800A1200: sb          $t0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r8;
L_800A1204:
    // 0x800A1204: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800A1208: b           L_800A1264
    // 0x800A120C: sb          $s4, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r20;
        goto L_800A1264;
    // 0x800A120C: sb          $s4, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r20;
L_800A1210:
    // 0x800A1210: bgez        $a0, L_800A1264
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800A1214: nop
    
            goto L_800A1264;
    }
    // 0x800A1214: nop

    // 0x800A1218: multu       $a0, $s1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A121C: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x800A1220: mflo        $v0
    ctx->r2 = lo;
    // 0x800A1224: negu        $t1, $v0
    ctx->r9 = SUB32(0, ctx->r2);
    // 0x800A1228: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800A122C: beq         $at, $zero, L_800A123C
    if (ctx->r1 == 0) {
        // 0x800A1230: addu        $t2, $v1, $v0
        ctx->r10 = ADD32(ctx->r3, ctx->r2);
            goto L_800A123C;
    }
    // 0x800A1230: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x800A1234: b           L_800A1264
    // 0x800A1238: sb          $t2, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r10;
        goto L_800A1264;
    // 0x800A1238: sb          $t2, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r10;
L_800A123C:
    // 0x800A123C: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800A1240: b           L_800A1264
    // 0x800A1244: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
        goto L_800A1264;
    // 0x800A1244: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
L_800A1248:
    // 0x800A1248: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800A124C: nop

    // 0x800A1250: beq         $a1, $zero, L_800A1264
    if (ctx->r5 == 0) {
        // 0x800A1254: nop
    
            goto L_800A1264;
    }
    // 0x800A1254: nop

    // 0x800A1258: jal         0x8000488C
    // 0x800A125C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    sndp_stop(rdram, ctx);
        goto after_3;
    // 0x800A125C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x800A1260: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_800A1264:
    // 0x800A1264: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800A1268: bne         $s0, $s3, L_800A118C
    if (ctx->r16 != ctx->r19) {
        // 0x800A126C: nop
    
            goto L_800A118C;
    }
    // 0x800A126C: nop

    // 0x800A1270: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1274: addiu       $v1, $v1, 0x7330
    ctx->r3 = ADD32(ctx->r3, 0X7330);
    // 0x800A1278: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x800A127C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800A1280: beq         $t3, $zero, L_800A12E4
    if (ctx->r11 == 0) {
        // 0x800A1284: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A12E4;
    }
    // 0x800A1284: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A1288: lbu         $t4, 0x2CF2($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X2CF2);
    // 0x800A128C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A1290: bne         $t4, $zero, L_800A12E4
    if (ctx->r12 != 0) {
        // 0x800A1294: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800A12E4;
    }
    // 0x800A1294: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A1298: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800A129C: lbu         $v0, 0x72F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X72F7);
    // 0x800A12A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A12A4: bne         $v0, $at, L_800A12C0
    if (ctx->r2 != ctx->r1) {
        // 0x800A12A8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A12C0;
    }
    // 0x800A12A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A12AC: jal         0x8000318C
    // 0x800A12B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_4;
    // 0x800A12B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_4:
    // 0x800A12B4: b           L_800A12E4
    // 0x800A12B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800A12E4;
    // 0x800A12B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800A12BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800A12C0:
    // 0x800A12C0: bne         $v0, $at, L_800A12D8
    if (ctx->r2 != ctx->r1) {
        // 0x800A12C4: nop
    
            goto L_800A12D8;
    }
    // 0x800A12C4: nop

    // 0x800A12C8: jal         0x8000318C
    // 0x800A12CC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_5;
    // 0x800A12CC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_5:
    // 0x800A12D0: b           L_800A12E4
    // 0x800A12D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800A12E4;
    // 0x800A12D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800A12D8:
    // 0x800A12D8: jal         0x8000318C
    // 0x800A12DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_6;
    // 0x800A12DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_6:
    // 0x800A12E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800A12E4:
    // 0x800A12E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A12E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A12EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A12F0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800A12F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800A12F8: jr          $ra
    // 0x800A12FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A12FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void reset_title_logo_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081810: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081814: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081818: jr          $ra
    // 0x8008181C: sw          $t6, -0x628($at)
    MEM_W(-0X628, ctx->r1) = ctx->r14;
    return;
    // 0x8008181C: sw          $t6, -0x628($at)
    MEM_W(-0X628, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void obj_animate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061F70: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80061F74: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x80061F78: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x80061F7C: lb          $t0, 0x3A($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X3A);
    // 0x80061F80: bgezl       $t0, L_80061F90
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80061F84: lw          $t1, 0x40($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X40);
            goto L_80061F90;
    }
    goto skip_0;
    // 0x80061F84: lw          $t1, 0x40($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X40);
    skip_0:
    // 0x80061F88: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80061F8C: lw          $t1, 0x40($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X40);
L_80061F90:
    // 0x80061F90: lb          $t2, 0x55($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X55);
    // 0x80061F94: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80061F98: bnel        $at, $zero, L_80061FA8
    if (ctx->r1 != 0) {
        // 0x80061F9C: lw          $t1, 0x68($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X68);
            goto L_80061FA8;
    }
    goto skip_1;
    // 0x80061F9C: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    skip_1:
    // 0x80061FA0: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x80061FA4: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
L_80061FA8:
    // 0x80061FA8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80061FAC: add         $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80061FB0: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80061FB4: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80061FB8: lw          $t0, 0x44($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X44);
    // 0x80061FBC: bnel        $t0, $zero, L_80061FD0
    if (ctx->r8 != 0) {
        // 0x80061FC0: lh          $t9, 0x18($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X18);
            goto L_80061FD0;
    }
    goto skip_2;
    // 0x80061FC0: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
    skip_2:
    // 0x80061FC4: b           L_800624BC
    // 0x80061FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800624BC;
    // 0x80061FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061FCC: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
L_80061FD0:
    // 0x80061FD0: lh          $t0, 0x14($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X14);
    // 0x80061FD4: lb          $a3, 0x3B($a0)
    ctx->r7 = MEM_B(ctx->r4, 0X3B);
    // 0x80061FD8: bne         $t9, $t0, L_80061FF4
    if (ctx->r25 != ctx->r8) {
        // 0x80061FDC: nop
    
            goto L_80061FF4;
    }
    // 0x80061FDC: nop

    // 0x80061FE0: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x80061FE4: bne         $a3, $t0, L_80061FF4
    if (ctx->r7 != ctx->r8) {
        // 0x80061FE8: nop
    
            goto L_80061FF4;
    }
    // 0x80061FE8: nop

    // 0x80061FEC: b           L_800624BC
    // 0x80061FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800624BC;
    // 0x80061FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80061FF4:
    // 0x80061FF4: bgezl       $a3, L_80062004
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80061FF8: lh          $t0, 0x48($a2)
        ctx->r8 = MEM_H(ctx->r6, 0X48);
            goto L_80062004;
    }
    goto skip_3;
    // 0x80061FF8: lh          $t0, 0x48($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X48);
    skip_3:
    // 0x80061FFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80062000: lh          $t0, 0x48($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X48);
L_80062004:
    // 0x80062004: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80062008: bne         $at, $zero, L_80062014
    if (ctx->r1 != 0) {
        // 0x8006200C: nop
    
            goto L_80062014;
    }
    // 0x8006200C: nop

    // 0x80062010: addiu       $a3, $t0, -0x1
    ctx->r7 = ADD32(ctx->r8, -0X1);
L_80062014:
    // 0x80062014: blez        $t0, L_80062030
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80062018: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80062030;
    }
    // 0x80062018: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8006201C: lw          $t1, 0x44($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X44);
    // 0x80062020: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x80062024: add         $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80062028: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8006202C: addi        $t2, $t2, -0x2
    ctx->r10 = ADD32(ctx->r10, -0X2);
L_80062030:
    // 0x80062030: srl         $a0, $t9, 4
    ctx->r4 = S32(U32(ctx->r25) >> 4);
    // 0x80062034: bgezl       $a0, L_80062048
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80062038: slt         $at, $t2, $a0
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80062048;
    }
    goto skip_4;
    // 0x80062038: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    skip_4:
    // 0x8006203C: or          $t9, $t2, $zero
    ctx->r25 = ctx->r10 | 0;
    // 0x80062040: srl         $a0, $t2, 4
    ctx->r4 = S32(U32(ctx->r10) >> 4);
    // 0x80062044: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
L_80062048:
    // 0x80062048: beql        $at, $zero, L_80062064
    if (ctx->r1 == 0) {
        // 0x8006204C: lh          $t0, 0x10($a1)
        ctx->r8 = MEM_H(ctx->r5, 0X10);
            goto L_80062064;
    }
    goto skip_5;
    // 0x8006204C: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    skip_5:
    // 0x80062050: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80062054: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80062058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006205C: sh          $t0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r8;
    // 0x80062060: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
L_80062064:
    // 0x80062064: lw          $s1, 0xC($a1)
    ctx->r17 = MEM_W(ctx->r5, 0XC);
    // 0x80062068: beql        $a3, $t0, L_8006207C
    if (ctx->r7 == ctx->r8) {
        // 0x8006206C: lh          $s0, 0x12($a1)
        ctx->r16 = MEM_H(ctx->r5, 0X12);
            goto L_8006207C;
    }
    goto skip_6;
    // 0x8006206C: lh          $s0, 0x12($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X12);
    skip_6:
    // 0x80062070: b           L_8006207C
    // 0x80062074: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_8006207C;
    // 0x80062074: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80062078: lh          $s0, 0x12($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X12);
L_8006207C:
    // 0x8006207C: sh          $a3, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r7;
    // 0x80062080: sh          $t9, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r25;
    // 0x80062084: sh          $a0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r4;
    // 0x80062088: beq         $a0, $zero, L_800620A4
    if (ctx->r4 == 0) {
        // 0x8006208C: andi        $t8, $t9, 0xF
        ctx->r24 = ctx->r25 & 0XF;
            goto L_800620A4;
    }
    // 0x8006208C: andi        $t8, $t9, 0xF
    ctx->r24 = ctx->r25 & 0XF;
    // 0x80062090: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80062094: beql        $s0, $at, L_800620A8
    if (ctx->r16 == ctx->r1) {
        // 0x80062098: lw          $v0, 0x44($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X44);
            goto L_800620A8;
    }
    goto skip_7;
    // 0x80062098: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    skip_7:
    // 0x8006209C: b           L_80062138
    // 0x800620A0: lh          $v1, 0x4A($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X4A);
        goto L_80062138;
    // 0x800620A0: lh          $v1, 0x4A($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X4A);
L_800620A4:
    // 0x800620A4: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
L_800620A8:
    // 0x800620A8: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x800620AC: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x800620B0: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800620B4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800620B8: lh          $v0, 0x24($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X24);
    // 0x800620BC: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x800620C0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800620C4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800620C8: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_800620CC:
    // 0x800620CC: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x800620D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800620D4: beql        $v0, $at, L_80062124
    if (ctx->r2 == ctx->r1) {
        // 0x800620D8: addiu       $t5, $t5, 0x2
        ctx->r13 = ADD32(ctx->r13, 0X2);
            goto L_80062124;
    }
    goto skip_8;
    // 0x800620D8: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    skip_8:
    // 0x800620DC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800620E0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800620E4: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800620E8: add         $v1, $s1, $v0
    ctx->r3 = ADD32(ctx->r17, ctx->r2);
    // 0x800620EC: add         $v0, $t6, $v0
    ctx->r2 = ADD32(ctx->r14, ctx->r2);
    // 0x800620F0: lh          $t0, 0x0($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X0);
    // 0x800620F4: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800620F8: add         $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800620FC: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x80062100: lh          $t0, 0x2($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X2);
    // 0x80062104: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80062108: add         $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8006210C: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
    // 0x80062110: lh          $t0, 0x4($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X4);
    // 0x80062114: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x80062118: add         $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8006211C: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x80062120: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
L_80062124:
    // 0x80062124: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80062128: bne         $at, $zero, L_800620CC
    if (ctx->r1 != 0) {
        // 0x8006212C: addiu       $t7, $t7, 0xA
        ctx->r15 = ADD32(ctx->r15, 0XA);
            goto L_800620CC;
    }
    // 0x8006212C: addiu       $t7, $t7, 0xA
    ctx->r15 = ADD32(ctx->r15, 0XA);
    // 0x80062130: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80062134: lh          $v1, 0x4A($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X4A);
L_80062138:
    // 0x80062138: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006213C: add         $v0, $v1, $v1
    ctx->r2 = ADD32(ctx->r3, ctx->r3);
    // 0x80062140: add         $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x80062144: beq         $at, $zero, L_800621E0
    if (ctx->r1 == 0) {
        // 0x80062148: addiu       $t4, $t4, 0xC
        ctx->r12 = ADD32(ctx->r12, 0XC);
            goto L_800621E0;
    }
    // 0x80062148: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8006214C: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    // 0x80062150: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80062154: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062158: addiu       $v1, $s0, 0x2
    ctx->r3 = ADD32(ctx->r16, 0X2);
    // 0x8006215C: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062160: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80062164: mflo        $v1
    ctx->r3 = lo;
    // 0x80062168: add         $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x8006216C: nop

    // 0x80062170: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
L_80062174:
    // 0x80062174: or          $t6, $t2, $zero
    ctx->r14 = ctx->r10 | 0;
    // 0x80062178: or          $t5, $s1, $zero
    ctx->r13 = ctx->r17 | 0;
    // 0x8006217C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80062180: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80062184: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062188: add         $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8006218C: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_80062190:
    // 0x80062190: lh          $t0, 0x0($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X0);
    // 0x80062194: lb          $t1, 0x0($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X0);
    // 0x80062198: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x8006219C: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800621A0: add         $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800621A4: sh          $t0, -0x6($t5)
    MEM_H(-0X6, ctx->r13) = ctx->r8;
    // 0x800621A8: lh          $t0, -0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X4);
    // 0x800621AC: lb          $t1, 0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X1);
    // 0x800621B0: addiu       $t6, $t6, 0x3
    ctx->r14 = ADD32(ctx->r14, 0X3);
    // 0x800621B4: add         $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800621B8: sh          $t0, -0x4($t5)
    MEM_H(-0X4, ctx->r13) = ctx->r8;
    // 0x800621BC: lh          $t0, -0x2($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X2);
    // 0x800621C0: lb          $t1, -0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, -0X1);
    // 0x800621C4: add         $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800621C8: bne         $at, $zero, L_80062190
    if (ctx->r1 != 0) {
        // 0x800621CC: sh          $t0, -0x2($t5)
        MEM_H(-0X2, ctx->r13) = ctx->r8;
            goto L_80062190;
    }
    // 0x800621CC: sh          $t0, -0x2($t5)
    MEM_H(-0X2, ctx->r13) = ctx->r8;
    // 0x800621D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800621D4: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800621D8: bnel        $at, $zero, L_80062174
    if (ctx->r1 != 0) {
        // 0x800621DC: lh          $v0, 0x4A($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X4A);
            goto L_80062174;
    }
    goto skip_9;
    // 0x800621DC: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
    skip_9:
L_800621E0:
    // 0x800621E0: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800621E4: beql        $at, $zero, L_80062284
    if (ctx->r1 == 0) {
        // 0x800621E8: lw          $v0, 0x44($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X44);
            goto L_80062284;
    }
    goto skip_10;
    // 0x800621E8: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    skip_10:
    // 0x800621EC: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    // 0x800621F0: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x800621F4: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800621F8: addiu       $v1, $s0, 0x2
    ctx->r3 = ADD32(ctx->r16, 0X2);
    // 0x800621FC: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062200: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80062204: mflo        $v1
    ctx->r3 = lo;
    // 0x80062208: add         $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x8006220C: nop

    // 0x80062210: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
L_80062214:
    // 0x80062214: sub         $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x80062218: or          $t5, $s1, $zero
    ctx->r13 = ctx->r17 | 0;
    // 0x8006221C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80062220: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80062224: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062228: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006222C: or          $t6, $t2, $zero
    ctx->r14 = ctx->r10 | 0;
    // 0x80062230: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_80062234:
    // 0x80062234: lh          $t0, 0x0($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X0);
    // 0x80062238: lb          $t1, 0x0($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X0);
    // 0x8006223C: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x80062240: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80062244: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80062248: sh          $t0, -0x6($t5)
    MEM_H(-0X6, ctx->r13) = ctx->r8;
    // 0x8006224C: lh          $t0, -0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X4);
    // 0x80062250: lb          $t1, 0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, 0X1);
    // 0x80062254: addiu       $t6, $t6, 0x3
    ctx->r14 = ADD32(ctx->r14, 0X3);
    // 0x80062258: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8006225C: sh          $t0, -0x4($t5)
    MEM_H(-0X4, ctx->r13) = ctx->r8;
    // 0x80062260: lh          $t0, -0x2($t5)
    ctx->r8 = MEM_H(ctx->r13, -0X2);
    // 0x80062264: lb          $t1, -0x1($t6)
    ctx->r9 = MEM_B(ctx->r14, -0X1);
    // 0x80062268: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8006226C: bne         $at, $zero, L_80062234
    if (ctx->r1 != 0) {
        // 0x80062270: sh          $t0, -0x2($t5)
        MEM_H(-0X2, ctx->r13) = ctx->r8;
            goto L_80062234;
    }
    // 0x80062270: sh          $t0, -0x2($t5)
    MEM_H(-0X2, ctx->r13) = ctx->r8;
    // 0x80062274: slt         $at, $a0, $s0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80062278: bnel        $at, $zero, L_80062214
    if (ctx->r1 != 0) {
        // 0x8006227C: lh          $v0, 0x4A($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X4A);
            goto L_80062214;
    }
    goto skip_11;
    // 0x8006227C: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
    skip_11:
    // 0x80062280: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
L_80062284:
    // 0x80062284: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80062288: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006228C: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062290: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80062294: addiu       $v0, $s0, 0x2
    ctx->r2 = ADD32(ctx->r16, 0X2);
    // 0x80062298: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006229C: lh          $v0, 0x4A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4A);
    // 0x800622A0: lw          $t5, -0x243C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X243C);
    // 0x800622A4: mflo        $v1
    ctx->r3 = lo;
    // 0x800622A8: add         $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800622AC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800622B0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800622B4: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800622B8: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_800622BC:
    // 0x800622BC: lb          $t0, 0x0($t6)
    ctx->r8 = MEM_B(ctx->r14, 0X0);
    // 0x800622C0: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x800622C4: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800622C8: multu       $t0, $t8
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800622CC: addiu       $t6, $t6, 0x3
    ctx->r14 = ADD32(ctx->r14, 0X3);
    // 0x800622D0: mflo        $t0
    ctx->r8 = lo;
    // 0x800622D4: srl         $t0, $t0, 4
    ctx->r8 = S32(U32(ctx->r8) >> 4);
    // 0x800622D8: sh          $t0, -0x6($t5)
    MEM_H(-0X6, ctx->r13) = ctx->r8;
    // 0x800622DC: lb          $t1, -0x2($t6)
    ctx->r9 = MEM_B(ctx->r14, -0X2);
    // 0x800622E0: multu       $t1, $t8
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800622E4: mflo        $t1
    ctx->r9 = lo;
    // 0x800622E8: srl         $t1, $t1, 4
    ctx->r9 = S32(U32(ctx->r9) >> 4);
    // 0x800622EC: sh          $t1, -0x4($t5)
    MEM_H(-0X4, ctx->r13) = ctx->r9;
    // 0x800622F0: lb          $t2, -0x1($t6)
    ctx->r10 = MEM_B(ctx->r14, -0X1);
    // 0x800622F4: multu       $t2, $t8
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800622F8: mflo        $t2
    ctx->r10 = lo;
    // 0x800622FC: srl         $t2, $t2, 4
    ctx->r10 = S32(U32(ctx->r10) >> 4);
    // 0x80062300: bne         $at, $zero, L_800622BC
    if (ctx->r1 != 0) {
        // 0x80062304: sh          $t2, -0x2($t5)
        MEM_H(-0X2, ctx->r13) = ctx->r10;
            goto L_800622BC;
    }
    // 0x80062304: sh          $t2, -0x2($t5)
    MEM_H(-0X2, ctx->r13) = ctx->r10;
    // 0x80062308: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    // 0x8006230C: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80062310: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062314: beq         $a0, $zero, L_80062330
    if (ctx->r4 == 0) {
        // 0x80062318: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_80062330;
    }
    // 0x80062318: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006231C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80062320: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062324: mflo        $v1
    ctx->r3 = lo;
    // 0x80062328: add         $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8006232C: addiu       $t6, $t6, -0xC
    ctx->r14 = ADD32(ctx->r14, -0XC);
L_80062330:
    // 0x80062330: lb          $v0, 0x0($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X0);
    // 0x80062334: lbu         $v1, 0x1($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X1);
    // 0x80062338: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8006233C: or          $t0, $v0, $v1
    ctx->r8 = ctx->r2 | ctx->r3;
    // 0x80062340: lb          $v0, 0x2($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X2);
    // 0x80062344: lbu         $v1, 0x3($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X3);
    // 0x80062348: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8006234C: or          $t1, $v0, $v1
    ctx->r9 = ctx->r2 | ctx->r3;
    // 0x80062350: lb          $v0, 0x4($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X4);
    // 0x80062354: lbu         $v1, 0x5($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X5);
    // 0x80062358: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8006235C: or          $t2, $v0, $v1
    ctx->r10 = ctx->r2 | ctx->r3;
    // 0x80062360: lb          $v0, 0xA($t6)
    ctx->r2 = MEM_B(ctx->r14, 0XA);
    // 0x80062364: lbu         $v1, 0xB($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XB);
    // 0x80062368: add         $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8006236C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80062370: bne         $a0, $zero, L_80062380
    if (ctx->r4 != 0) {
        // 0x80062374: or          $t3, $v0, $v1
        ctx->r11 = ctx->r2 | ctx->r3;
            goto L_80062380;
    }
    // 0x80062374: or          $t3, $v0, $v1
    ctx->r11 = ctx->r2 | ctx->r3;
    // 0x80062378: add         $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8006237C: addiu       $t6, $t6, -0xC
    ctx->r14 = ADD32(ctx->r14, -0XC);
L_80062380:
    // 0x80062380: lb          $v0, 0x0($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X0);
    // 0x80062384: lbu         $v1, 0x1($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X1);
    // 0x80062388: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006238C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80062390: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80062394: sub         $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x80062398: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006239C: mflo        $v0
    ctx->r2 = lo;
    // 0x800623A0: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800623A4: add         $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800623A8: sh          $t0, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r8;
    // 0x800623AC: lb          $v0, 0x2($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X2);
    // 0x800623B0: lbu         $v1, 0x3($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X3);
    // 0x800623B4: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800623B8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800623BC: sub         $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x800623C0: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800623C4: mflo        $v0
    ctx->r2 = lo;
    // 0x800623C8: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800623CC: add         $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x800623D0: sh          $t1, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r9;
    // 0x800623D4: lb          $v0, 0x4($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X4);
    // 0x800623D8: lbu         $v1, 0x5($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X5);
    // 0x800623DC: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800623E0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800623E4: sub         $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x800623E8: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800623EC: mflo        $v0
    ctx->r2 = lo;
    // 0x800623F0: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800623F4: add         $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800623F8: sh          $t2, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r10;
    // 0x800623FC: lb          $v0, 0xA($t6)
    ctx->r2 = MEM_B(ctx->r14, 0XA);
    // 0x80062400: lbu         $v1, 0xB($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XB);
    // 0x80062404: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x80062408: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006240C: sub         $v0, $v0, $t3
    ctx->r2 = SUB32(ctx->r2, ctx->r11);
    // 0x80062410: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062414: addiu       $v1, $a1, 0x4
    ctx->r3 = ADD32(ctx->r5, 0X4);
    // 0x80062418: mflo        $v0
    ctx->r2 = lo;
    // 0x8006241C: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x80062420: add         $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x80062424: lb          $v0, 0x1F($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1F);
    // 0x80062428: sh          $t3, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r11;
    // 0x8006242C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80062430: sb          $v0, 0x1F($a1)
    MEM_B(0X1F, ctx->r5) = ctx->r2;
    // 0x80062434: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80062438: add         $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006243C: lh          $v0, 0x24($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X24);
    // 0x80062440: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x80062444: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80062448: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8006244C: lw          $t9, -0x243C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X243C);
    // 0x80062450: add         $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
L_80062454:
    // 0x80062454: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x80062458: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006245C: addi        $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
    // 0x80062460: beql        $v0, $at, L_800624B0
    if (ctx->r2 == ctx->r1) {
        // 0x80062464: slt         $at, $t5, $t3
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800624B0;
    }
    goto skip_12;
    // 0x80062464: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
    skip_12:
    // 0x80062468: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8006246C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80062470: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062474: add         $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x80062478: add         $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    // 0x8006247C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80062480: lh          $v1, 0x0($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X0);
    // 0x80062484: add         $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // 0x80062488: sh          $t2, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r10;
    // 0x8006248C: lh          $v0, 0x2($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X2);
    // 0x80062490: lh          $v1, 0x2($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X2);
    // 0x80062494: add         $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // 0x80062498: sh          $t2, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r10;
    // 0x8006249C: lh          $v0, 0x4($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X4);
    // 0x800624A0: lh          $v1, 0x4($t1)
    ctx->r3 = MEM_H(ctx->r9, 0X4);
    // 0x800624A4: add         $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // 0x800624A8: sh          $t2, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r10;
    // 0x800624AC: slt         $at, $t5, $t3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r11) ? 1 : 0;
L_800624B0:
    // 0x800624B0: bne         $at, $zero, L_80062454
    if (ctx->r1 != 0) {
        // 0x800624B4: addi        $t6, $t6, 0xA
        ctx->r14 = ADD32(ctx->r14, 0XA);
            goto L_80062454;
    }
    // 0x800624B4: addi        $t6, $t6, 0xA
    ctx->r14 = ADD32(ctx->r14, 0XA);
    // 0x800624B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800624BC:
    // 0x800624BC: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800624C0: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x800624C4: jr          $ra
    // 0x800624C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800624C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA030: jr          $ra
    // 0x800CA034: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x800CA034: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void get_distance_to_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A008: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006A00C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8006A010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006A014: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8006A018: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8006A01C: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x8006A020: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x8006A024: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x8006A028: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A02C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8006A030: addiu       $a0, $a0, 0x14E0
    ctx->r4 = ADD32(ctx->r4, 0X14E0);
    // 0x8006A034: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8006A038: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8006A03C: jal         0x8006F88C
    // 0x8006A040: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mtxf_transform_point(rdram, ctx);
        goto after_0;
    // 0x8006A040: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8006A044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006A048: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006A04C: jr          $ra
    // 0x8006A050: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006A050: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void process_subtitles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3474: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C3478: lw          $t6, 0x3C10($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3C10);
    // 0x800C347C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3484: bne         $t6, $zero, L_800C3498
    if (ctx->r14 != 0) {
        // 0x800C3488: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800C3498;
    }
    // 0x800C3488: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800C348C: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C3490: addiu       $a3, $a3, -0x528A
    ctx->r7 = ADD32(ctx->r7, -0X528A);
    // 0x800C3494: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
L_800C3498:
    // 0x800C3498: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C349C: addiu       $a3, $a3, -0x528A
    ctx->r7 = ADD32(ctx->r7, -0X528A);
    // 0x800C34A0: lh          $a0, 0x0($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X0);
    // 0x800C34A4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C34A8: beq         $a0, $zero, L_800C3580
    if (ctx->r4 == 0) {
        // 0x800C34AC: addiu       $a2, $a2, -0x5294
        ctx->r6 = ADD32(ctx->r6, -0X5294);
            goto L_800C3580;
    }
    // 0x800C34AC: addiu       $a2, $a2, -0x5294
    ctx->r6 = ADD32(ctx->r6, -0X5294);
    // 0x800C34B0: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x800C34B4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C34B8: bgtz        $v1, L_800C351C
    if (SIGNED(ctx->r3) > 0) {
        // 0x800C34BC: subu        $t7, $v1, $a1
        ctx->r15 = SUB32(ctx->r3, ctx->r5);
            goto L_800C351C;
    }
    // 0x800C34BC: subu        $t7, $v1, $a1
    ctx->r15 = SUB32(ctx->r3, ctx->r5);
    // 0x800C34C0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C34C4: lh          $t8, -0x5296($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X5296);
    // 0x800C34C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C34CC: multu       $a1, $t8
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C34D0: addiu       $v0, $v0, -0x5298
    ctx->r2 = ADD32(ctx->r2, -0X5298);
    // 0x800C34D4: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800C34D8: mflo        $t9
    ctx->r25 = lo;
    // 0x800C34DC: subu        $t0, $t7, $t9
    ctx->r8 = SUB32(ctx->r15, ctx->r25);
    // 0x800C34E0: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x800C34E4: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800C34E8: nop

    // 0x800C34EC: bgez        $t1, L_800C3580
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800C34F0: nop
    
            goto L_800C3580;
    }
    // 0x800C34F0: nop

    // 0x800C34F4: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800C34F8: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x800C34FC: jal         0x800C5B80
    // 0x800C3500: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_close(rdram, ctx);
        goto after_0;
    // 0x800C3500: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x800C3504: jal         0x800C59F4
    // 0x800C3508: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_1;
    // 0x800C3508: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x800C350C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3510: lh          $a0, -0x528A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X528A);
    // 0x800C3514: b           L_800C3580
    // 0x800C3518: nop

        goto L_800C3580;
    // 0x800C3518: nop

L_800C351C:
    // 0x800C351C: lh          $t3, -0x5296($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X5296);
    // 0x800C3520: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C3524: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C3528: addiu       $v0, $v0, -0x5298
    ctx->r2 = ADD32(ctx->r2, -0X5298);
    // 0x800C352C: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800C3530: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x800C3534: mflo        $t4
    ctx->r12 = lo;
    // 0x800C3538: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800C353C: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x800C3540: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800C3544: nop

    // 0x800C3548: slti        $at, $t6, 0x101
    ctx->r1 = SIGNED(ctx->r14) < 0X101 ? 1 : 0;
    // 0x800C354C: bne         $at, $zero, L_800C3558
    if (ctx->r1 != 0) {
        // 0x800C3550: nop
    
            goto L_800C3558;
    }
    // 0x800C3550: nop

    // 0x800C3554: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
L_800C3558:
    // 0x800C3558: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x800C355C: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800C3560: nop

    // 0x800C3564: bgtz        $t9, L_800C3580
    if (SIGNED(ctx->r25) > 0) {
        // 0x800C3568: nop
    
            goto L_800C3580;
    }
    // 0x800C3568: nop

    // 0x800C356C: jal         0x800C32C4
    // 0x800C3570: nop

    find_next_subtitle(rdram, ctx);
        goto after_2;
    // 0x800C3570: nop

    after_2:
    // 0x800C3574: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3578: lh          $a0, -0x528A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X528A);
    // 0x800C357C: nop

L_800C3580:
    // 0x800C3580: beq         $a0, $zero, L_800C3594
    if (ctx->r4 == 0) {
        // 0x800C3584: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C3594;
    }
    // 0x800C3584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3588: jal         0x800C3020
    // 0x800C358C: nop

    render_subtitles(rdram, ctx);
        goto after_3;
    // 0x800C358C: nop

    after_3:
    // 0x800C3590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C3594:
    // 0x800C3594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3598: jr          $ra
    // 0x800C359C: nop

    return;
    // 0x800C359C: nop

;}
RECOMP_FUNC void get_stereo_pan_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E1C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80065E20: lh          $v0, -0x2A40($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2A40);
    // 0x80065E24: jr          $ra
    // 0x80065E28: nop

    return;
    // 0x80065E28: nop

;}
RECOMP_FUNC void area_triangle_2d(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070C6C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80070C70: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80070C74: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80070C78: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80070C7C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80070C80: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80070C84: sub.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80070C88: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80070C8C: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80070C90: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80070C94: mul.s       $f14, $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80070C98: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80070C9C: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80070CA0: mul.s       $f16, $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80070CA4: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80070CA8: mul.s       $f18, $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80070CAC: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80070CB0: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80070CB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80070CB8: add.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80070CBC: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80070CC0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80070CC4: sqrt.s      $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = sqrtf(ctx->f12.fl);
    // 0x80070CC8: sqrt.s      $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = sqrtf(ctx->f16.fl);
    // 0x80070CCC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80070CD0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80070CD4: add.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x80070CD8: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80070CDC: add.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80070CE0: mul.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80070CE4: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x80070CE8: sub.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80070CEC: mul.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80070CF0: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80070CF4: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80070CF8: nop

    // 0x80070CFC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80070D00: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80070D04: bc1fl       L_80070D10
    if (!c1cs) {
        // 0x80070D08: nop
    
            goto L_80070D10;
    }
    goto skip_0;
    // 0x80070D08: nop

    skip_0:
    // 0x80070D0C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80070D10:
    // 0x80070D10: jr          $ra
    // 0x80070D14: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    return;
    // 0x80070D14: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
;}
RECOMP_FUNC void lensflare_override_add(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD4C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD4C4: addiu       $v1, $v1, 0x3018
    ctx->r3 = ADD32(ctx->r3, 0X3018);
    // 0x800AD4C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AD4CC: nop

    // 0x800AD4D0: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800AD4D4: beq         $at, $zero, L_800AD4F0
    if (ctx->r1 == 0) {
        // 0x800AD4D8: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800AD4F0;
    }
    // 0x800AD4D8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800AD4DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AD4E0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AD4E4: sw          $a0, -0x7E00($at)
    MEM_W(-0X7E00, ctx->r1) = ctx->r4;
    // 0x800AD4E8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800AD4EC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800AD4F0:
    // 0x800AD4F0: jr          $ra
    // 0x800AD4F4: nop

    return;
    // 0x800AD4F4: nop

;}
RECOMP_FUNC void transition_update_shape(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1650: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C1654: addiu       $a3, $a3, 0x3740
    ctx->r7 = ADD32(ctx->r7, 0X3740);
    // 0x800C1658: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800C165C: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x800C1660: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C1664: blez        $v0, L_800C18D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C1668: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C18D4;
    }
    // 0x800C1668: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C166C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C1670: beq         $at, $zero, L_800C1744
    if (ctx->r1 == 0) {
        // 0x800C1674: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_800C1744;
    }
    // 0x800C1674: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C1678: addiu       $t0, $t0, -0x52C4
    ctx->r8 = ADD32(ctx->r8, -0X52C4);
    // 0x800C167C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C1680: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C1684: blez        $a1, L_800C1730
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C1688: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_800C1730;
    }
    // 0x800C1688: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C168C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C1690: addiu       $t1, $t1, -0x52D0
    ctx->r9 = ADD32(ctx->r9, -0X52D0);
    // 0x800C1694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1698: addiu       $t2, $t2, -0x52CC
    ctx->r10 = ADD32(ctx->r10, -0X52CC);
L_800C169C:
    // 0x800C169C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800C16A0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800C16A4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C16A8: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C16AC: addu        $a2, $t6, $v0
    ctx->r6 = ADD32(ctx->r14, ctx->r2);
    // 0x800C16B0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C16B4: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C16B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C16BC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C16C0: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x800C16C4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800C16C8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800C16CC: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C16D0: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C16D4: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    // 0x800C16D8: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C16DC: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800C16E0: nop

    // 0x800C16E4: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800C16E8: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x800C16EC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800C16F0: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C16F4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C16F8: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800C16FC: addu        $a2, $t5, $v0
    ctx->r6 = ADD32(ctx->r13, ctx->r2);
    // 0x800C1700: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800C1704: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800C1708: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C170C: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800C1710: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
    // 0x800C1714: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C1718: nop

    // 0x800C171C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C1720: bne         $at, $zero, L_800C169C
    if (ctx->r1 != 0) {
        // 0x800C1724: nop
    
            goto L_800C169C;
    }
    // 0x800C1724: nop

    // 0x800C1728: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x800C172C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C1730:
    // 0x800C1730: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C1734: subu        $t8, $v0, $a0
    ctx->r24 = SUB32(ctx->r2, ctx->r4);
    // 0x800C1738: addiu       $t1, $t1, -0x52D0
    ctx->r9 = ADD32(ctx->r9, -0X52D0);
    // 0x800C173C: b           L_800C17D8
    // 0x800C1740: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_800C17D8;
    // 0x800C1740: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_800C1744:
    // 0x800C1744: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C1748: addiu       $t0, $t0, -0x52C4
    ctx->r8 = ADD32(ctx->r8, -0X52C4);
    // 0x800C174C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C1750: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C1754: blez        $a1, L_800C17CC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C1758: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_800C17CC;
    }
    // 0x800C1758: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C175C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C1760: addiu       $a0, $a0, -0x52C8
    ctx->r4 = ADD32(ctx->r4, -0X52C8);
    // 0x800C1764: addiu       $t1, $t1, -0x52D0
    ctx->r9 = ADD32(ctx->r9, -0X52D0);
    // 0x800C1768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C176C:
    // 0x800C176C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800C1770: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800C1774: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1778: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800C177C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800C1780: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x800C1784: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C1788: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800C178C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800C1790: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800C1794: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800C1798: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x800C179C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800C17A0: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C17A4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800C17A8: lwc1        $f16, 0x8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800C17AC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800C17B0: swc1        $f16, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f16.u32l;
    // 0x800C17B4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800C17B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C17BC: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C17C0: bne         $at, $zero, L_800C176C
    if (ctx->r1 != 0) {
        // 0x800C17C4: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800C176C;
    }
    // 0x800C17C4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C17C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C17CC:
    // 0x800C17CC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C17D0: addiu       $t1, $t1, -0x52D0
    ctx->r9 = ADD32(ctx->r9, -0X52D0);
    // 0x800C17D4: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
L_800C17D8:
    // 0x800C17D8: blez        $a1, L_800C18FC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C17DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C18FC;
    }
    // 0x800C17DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C17E0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C17E4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C17E8: addiu       $a1, $a1, 0x3750
    ctx->r5 = ADD32(ctx->r5, 0X3750);
    // 0x800C17EC: addiu       $a2, $a2, 0x3760
    ctx->r6 = ADD32(ctx->r6, 0X3760);
    // 0x800C17F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800C17F4:
    // 0x800C17F4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C17F8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800C17FC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800C1800: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1804: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C1808: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C180C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1810: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800C1814: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800C1818: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C181C: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x800C1820: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C1824: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800C1828: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800C182C: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800C1830: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800C1834: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x800C1838: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800C183C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800C1840: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1844: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800C1848: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C184C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1850: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C1854: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C1858: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x800C185C: addu        $t8, $a1, $t3
    ctx->r24 = ADD32(ctx->r5, ctx->r11);
    // 0x800C1860: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800C1864: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800C1868: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800C186C: addu        $t4, $t9, $a0
    ctx->r12 = ADD32(ctx->r25, ctx->r4);
    // 0x800C1870: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800C1874: sh          $t6, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r14;
    // 0x800C1878: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C187C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800C1880: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800C1884: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C1888: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800C188C: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800C1890: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C1894: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800C1898: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C189C: addu        $t4, $a1, $t6
    ctx->r12 = ADD32(ctx->r5, ctx->r14);
    // 0x800C18A0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C18A4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800C18A8: addu        $t7, $t5, $a0
    ctx->r15 = ADD32(ctx->r13, ctx->r4);
    // 0x800C18AC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800C18B0: sb          $t8, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r24;
    // 0x800C18B4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800C18B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C18BC: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800C18C0: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800C18C4: bne         $at, $zero, L_800C17F4
    if (ctx->r1 != 0) {
        // 0x800C18C8: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800C17F4;
    }
    // 0x800C18C8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C18CC: jr          $ra
    // 0x800C18D0: nop

    return;
    // 0x800C18D0: nop

L_800C18D4:
    // 0x800C18D4: addiu       $v1, $v1, 0x3744
    ctx->r3 = ADD32(ctx->r3, 0X3744);
    // 0x800C18D8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800C18DC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800C18E0: beq         $v0, $at, L_800C18FC
    if (ctx->r2 == ctx->r1) {
        // 0x800C18E4: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800C18FC;
    }
    // 0x800C18E4: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C18E8: beq         $at, $zero, L_800C18F8
    if (ctx->r1 == 0) {
        // 0x800C18EC: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_800C18F8;
    }
    // 0x800C18EC: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x800C18F0: jr          $ra
    // 0x800C18F4: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x800C18F4: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
L_800C18F8:
    // 0x800C18F8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_800C18FC:
    // 0x800C18FC: jr          $ra
    // 0x800C1900: nop

    return;
    // 0x800C1900: nop

;}
RECOMP_FUNC void debug_text_character(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6F5C: slti        $at, $a1, 0x40
    ctx->r1 = SIGNED(ctx->r5) < 0X40 ? 1 : 0;
    // 0x800B6F60: beq         $at, $zero, L_800B7070
    if (ctx->r1 == 0) {
        // 0x800B6F64: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B7070;
    }
    // 0x800B6F64: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6F68: addiu       $v1, $v1, -0x7D74
    ctx->r3 = ADD32(ctx->r3, -0X7D74);
    // 0x800B6F6C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B6F70: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B6F74: beq         $t6, $zero, L_800B7068
    if (ctx->r14 == 0) {
        // 0x800B6F78: nop
    
            goto L_800B7068;
    }
    // 0x800B6F78: nop

    // 0x800B6F7C: lw          $t7, -0x7D88($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D88);
    // 0x800B6F80: lui         $t9, 0xFD70
    ctx->r25 = S32(0XFD70 << 16);
    // 0x800B6F84: beq         $t7, $zero, L_800B7064
    if (ctx->r15 == 0) {
        // 0x800B6F88: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_800B7064;
    }
    // 0x800B6F88: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B6F8C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6F90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B6F94: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B6F98: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B6F9C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B6FA0: lw          $t4, -0x7DA0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DA0);
    // 0x800B6FA4: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800B6FA8: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800B6FAC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B6FB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6FB4: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x800B6FB8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B6FBC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B6FC0: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800B6FC4: lui         $t7, 0xF570
    ctx->r15 = S32(0XF570 << 16);
    // 0x800B6FC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B6FCC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B6FD0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6FD4: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800B6FD8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B6FDC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B6FE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B6FE4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B6FE8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B6FEC: lui         $t7, 0x741
    ctx->r15 = S32(0X741 << 16);
    // 0x800B6FF0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B6FF4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B6FF8: ori         $t7, $t7, 0xF056
    ctx->r15 = ctx->r15 | 0XF056;
    // 0x800B6FFC: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800B7000: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B7004: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B7008: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B700C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800B7010: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B7014: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B7018: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B701C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B7020: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7024: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800B7028: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B702C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B7030: lui         $t5, 0xF568
    ctx->r13 = S32(0XF568 << 16);
    // 0x800B7034: ori         $t5, $t5, 0x3000
    ctx->r13 = ctx->r13 | 0X3000;
    // 0x800B7038: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B703C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B7040: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B7044: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7048: lui         $t9, 0x2F
    ctx->r25 = S32(0X2F << 16);
    // 0x800B704C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B7050: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B7054: ori         $t9, $t9, 0xC028
    ctx->r25 = ctx->r25 | 0XC028;
    // 0x800B7058: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B705C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B7060: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800B7064:
    // 0x800B7064: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800B7068:
    // 0x800B7068: b           L_800B7294
    // 0x800B706C: addiu       $a1, $a1, -0x21
    ctx->r5 = ADD32(ctx->r5, -0X21);
        goto L_800B7294;
    // 0x800B706C: addiu       $a1, $a1, -0x21
    ctx->r5 = ADD32(ctx->r5, -0X21);
L_800B7070:
    // 0x800B7070: slti        $at, $a1, 0x60
    ctx->r1 = SIGNED(ctx->r5) < 0X60 ? 1 : 0;
    // 0x800B7074: beq         $at, $zero, L_800B7184
    if (ctx->r1 == 0) {
        // 0x800B7078: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B7184;
    }
    // 0x800B7078: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B707C: addiu       $v1, $v1, -0x7D74
    ctx->r3 = ADD32(ctx->r3, -0X7D74);
    // 0x800B7080: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800B7084: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B7088: beq         $a2, $t4, L_800B717C
    if (ctx->r6 == ctx->r12) {
        // 0x800B708C: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_800B717C;
    }
    // 0x800B708C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800B7090: lw          $t5, -0x7D88($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D88);
    // 0x800B7094: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x800B7098: beq         $t5, $zero, L_800B7178
    if (ctx->r13 == 0) {
        // 0x800B709C: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800B7178;
    }
    // 0x800B709C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B70A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B70A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B70A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B70AC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B70B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B70B4: lw          $t8, -0x7D9C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D9C);
    // 0x800B70B8: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800B70BC: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800B70C0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B70C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B70C8: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800B70CC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B70D0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B70D4: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B70D8: lui         $t5, 0xF570
    ctx->r13 = S32(0XF570 << 16);
    // 0x800B70DC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B70E0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B70E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B70E8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800B70EC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B70F0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B70F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B70F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B70FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7100: lui         $t5, 0x755
    ctx->r13 = S32(0X755 << 16);
    // 0x800B7104: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B7108: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B710C: ori         $t5, $t5, 0x3043
    ctx->r13 = ctx->r13 | 0X3043;
    // 0x800B7110: lui         $t4, 0xF300
    ctx->r12 = S32(0XF300 << 16);
    // 0x800B7114: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B7118: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B711C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7120: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B7124: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B7128: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B712C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B7130: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B7134: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7138: lui         $t4, 0x8
    ctx->r12 = S32(0X8 << 16);
    // 0x800B713C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B7140: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B7144: lui         $t9, 0xF568
    ctx->r25 = S32(0XF568 << 16);
    // 0x800B7148: ori         $t9, $t9, 0x3E00
    ctx->r25 = ctx->r25 | 0X3E00;
    // 0x800B714C: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x800B7150: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B7154: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B7158: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B715C: lui         $t7, 0x3D
    ctx->r15 = S32(0X3D << 16);
    // 0x800B7160: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B7164: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B7168: ori         $t7, $t7, 0xC028
    ctx->r15 = ctx->r15 | 0XC028;
    // 0x800B716C: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800B7170: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B7174: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_800B7178:
    // 0x800B7178: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
L_800B717C:
    // 0x800B717C: b           L_800B7294
    // 0x800B7180: addiu       $a1, $a1, -0x40
    ctx->r5 = ADD32(ctx->r5, -0X40);
        goto L_800B7294;
    // 0x800B7180: addiu       $a1, $a1, -0x40
    ctx->r5 = ADD32(ctx->r5, -0X40);
L_800B7184:
    // 0x800B7184: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x800B7188: beq         $at, $zero, L_800B7294
    if (ctx->r1 == 0) {
        // 0x800B718C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B7294;
    }
    // 0x800B718C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B7190: addiu       $v1, $v1, -0x7D74
    ctx->r3 = ADD32(ctx->r3, -0X7D74);
    // 0x800B7194: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800B7198: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800B719C: beq         $a2, $t8, L_800B7294
    if (ctx->r6 == ctx->r24) {
        // 0x800B71A0: addiu       $a1, $a1, -0x60
        ctx->r5 = ADD32(ctx->r5, -0X60);
            goto L_800B7294;
    }
    // 0x800B71A0: addiu       $a1, $a1, -0x60
    ctx->r5 = ADD32(ctx->r5, -0X60);
    // 0x800B71A4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B71A8: lw          $t9, -0x7D88($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D88);
    // 0x800B71AC: lui         $t5, 0xFD70
    ctx->r13 = S32(0XFD70 << 16);
    // 0x800B71B0: beq         $t9, $zero, L_800B7290
    if (ctx->r25 == 0) {
        // 0x800B71B4: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800B7290;
    }
    // 0x800B71B4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B71B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B71BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B71C0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B71C4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B71C8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B71CC: lw          $t6, -0x7D98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D98);
    // 0x800B71D0: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800B71D4: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800B71D8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B71DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B71E0: lui         $t4, 0x708
    ctx->r12 = S32(0X708 << 16);
    // 0x800B71E4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800B71E8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B71EC: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x800B71F0: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x800B71F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B71F8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800B71FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7200: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800B7204: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800B7208: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B720C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B7210: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B7214: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7218: lui         $t9, 0x741
    ctx->r25 = S32(0X741 << 16);
    // 0x800B721C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B7220: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B7224: ori         $t9, $t9, 0xF056
    ctx->r25 = ctx->r25 | 0XF056;
    // 0x800B7228: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800B722C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B7230: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B7234: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7238: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800B723C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B7240: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B7244: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B7248: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B724C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7250: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x800B7254: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B7258: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B725C: lui         $t7, 0xF568
    ctx->r15 = S32(0XF568 << 16);
    // 0x800B7260: ori         $t7, $t7, 0x3000
    ctx->r15 = ctx->r15 | 0X3000;
    // 0x800B7264: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800B7268: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B726C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B7270: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7274: lui         $t5, 0x2F
    ctx->r13 = S32(0X2F << 16);
    // 0x800B7278: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B727C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B7280: ori         $t5, $t5, 0xC028
    ctx->r13 = ctx->r13 | 0XC028;
    // 0x800B7284: lui         $t4, 0xF200
    ctx->r12 = S32(0XF200 << 16);
    // 0x800B7288: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B728C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_800B7290:
    // 0x800B7290: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
L_800B7294:
    // 0x800B7294: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B7298: addiu       $v1, $v1, -0x7D74
    ctx->r3 = ADD32(ctx->r3, -0X7D74);
    // 0x800B729C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B72A0: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x800B72A4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800B72A8: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800B72AC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B72B0: addiu       $t4, $t4, 0x3484
    ctx->r12 = ADD32(ctx->r12, 0X3484);
    // 0x800B72B4: addu        $v0, $t9, $t4
    ctx->r2 = ADD32(ctx->r25, ctx->r12);
    // 0x800B72B8: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x800B72BC: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x800B72C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B72C4: lw          $t6, -0x7D88($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D88);
    // 0x800B72C8: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    // 0x800B72CC: beq         $t6, $zero, L_800B73A8
    if (ctx->r14 == 0) {
        // 0x800B72D0: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800B73A8;
    }
    // 0x800B72D0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B72D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B72D8: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x800B72DC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B72E0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B72E4: lui         $t9, 0xFFFE
    ctx->r25 = S32(0XFFFE << 16);
    // 0x800B72E8: ori         $t9, $t9, 0xF379
    ctx->r25 = ctx->r25 | 0XF379;
    // 0x800B72EC: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x800B72F0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B72F4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B72F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B72FC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B7300: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B7304: addiu       $t2, $t2, -0x7D94
    ctx->r10 = ADD32(ctx->r10, -0X7D94);
    // 0x800B7308: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B730C: lhu         $t5, 0x0($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X0);
    // 0x800B7310: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B7314: addu        $t6, $t5, $a3
    ctx->r14 = ADD32(ctx->r13, ctx->r7);
    // 0x800B7318: addiu       $t3, $t3, -0x7D92
    ctx->r11 = ADD32(ctx->r11, -0X7D92);
    // 0x800B731C: lhu         $t5, 0x0($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X0);
    // 0x800B7320: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B7324: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B7328: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800B732C: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x800B7330: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B7334: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B7338: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x800B733C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B7340: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x800B7344: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B7348: lhu         $t5, 0x0($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X0);
    // 0x800B734C: lhu         $t8, 0x0($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X0);
    // 0x800B7350: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B7354: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800B7358: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B735C: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x800B7360: sll         $t4, $t7, 12
    ctx->r12 = S32(ctx->r15 << 12);
    // 0x800B7364: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x800B7368: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B736C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7370: sll         $t5, $a2, 21
    ctx->r13 = S32(ctx->r6 << 21);
    // 0x800B7374: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B7378: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B737C: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x800B7380: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B7384: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B7388: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B738C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800B7390: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B7394: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B7398: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x800B739C: lui         $t7, 0xB200
    ctx->r15 = S32(0XB200 << 16);
    // 0x800B73A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B73A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_800B73A8:
    // 0x800B73A8: jr          $ra
    // 0x800B73AC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800B73AC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
;}
RECOMP_FUNC void func_8001EE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EEA8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001EEAC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001EEB0: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8001EEB4: addiu       $s7, $s7, -0x4C08
    ctx->r23 = ADD32(ctx->r23, -0X4C08);
    // 0x8001EEB8: lh          $t6, 0x0($s7)
    ctx->r14 = MEM_H(ctx->r23, 0X0);
    // 0x8001EEBC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001EEC0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001EEC4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001EEC8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001EECC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001EED0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001EED4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001EED8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001EEDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001EEE0: blez        $t6, L_8001EF9C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001EEE4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001EF9C;
    }
    // 0x8001EEE4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001EEE8: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8001EEEC: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8001EEF0: addiu       $s4, $s4, -0x4C0C
    ctx->r20 = ADD32(ctx->r20, -0X4C0C);
    // 0x8001EEF4: addiu       $fp, $fp, -0x4D5A
    ctx->r30 = ADD32(ctx->r30, -0X4D5A);
    // 0x8001EEF8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001EEFC: addiu       $s6, $zero, 0x14
    ctx->r22 = ADD32(0, 0X14);
    // 0x8001EF00: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
L_8001EF04:
    // 0x8001EF04: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8001EF08: nop

    // 0x8001EF0C: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8001EF10: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x8001EF14: nop

    // 0x8001EF18: lw          $t9, 0x64($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X64);
    // 0x8001EF1C: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
    // 0x8001EF20: bne         $t9, $zero, L_8001EF50
    if (ctx->r25 != 0) {
        // 0x8001EF24: nop
    
            goto L_8001EF50;
    }
    // 0x8001EF24: nop

    // 0x8001EF28: lb          $t0, 0x11($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X11);
    // 0x8001EF2C: nop

    // 0x8001EF30: bne         $t0, $zero, L_8001EF50
    if (ctx->r8 != 0) {
        // 0x8001EF34: nop
    
            goto L_8001EF50;
    }
    // 0x8001EF34: nop

    // 0x8001EF38: lh          $t1, 0xC($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XC);
    // 0x8001EF3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001EF40: beq         $s5, $t1, L_8001EF50
    if (ctx->r21 == ctx->r9) {
        // 0x8001EF44: nop
    
            goto L_8001EF50;
    }
    // 0x8001EF44: nop

    // 0x8001EF48: jal         0x8001F270
    // 0x8001EF4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001F23C(rdram, ctx);
        goto after_0;
    // 0x8001EF4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
L_8001EF50:
    // 0x8001EF50: lb          $t2, 0x0($fp)
    ctx->r10 = MEM_B(ctx->r30, 0X0);
    // 0x8001EF54: nop

    // 0x8001EF58: bne         $t2, $zero, L_8001EF70
    if (ctx->r10 != 0) {
        // 0x8001EF5C: nop
    
            goto L_8001EF70;
    }
    // 0x8001EF5C: nop

    // 0x8001EF60: lb          $t3, 0x21($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X21);
    // 0x8001EF64: nop

    // 0x8001EF68: beq         $s6, $t3, L_8001EF88
    if (ctx->r22 == ctx->r11) {
        // 0x8001EF6C: nop
    
            goto L_8001EF88;
    }
    // 0x8001EF6C: nop

L_8001EF70:
    // 0x8001EF70: lw          $a1, 0x64($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X64);
    // 0x8001EF74: nop

    // 0x8001EF78: beq         $a1, $zero, L_8001EF88
    if (ctx->r5 == 0) {
        // 0x8001EF7C: nop
    
            goto L_8001EF88;
    }
    // 0x8001EF7C: nop

    // 0x8001EF80: jal         0x8001EFD8
    // 0x8001EF84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_1;
    // 0x8001EF84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
L_8001EF88:
    // 0x8001EF88: lh          $t4, 0x0($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X0);
    // 0x8001EF8C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001EF90: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001EF94: bne         $at, $zero, L_8001EF04
    if (ctx->r1 != 0) {
        // 0x8001EF98: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8001EF04;
    }
    // 0x8001EF98: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8001EF9C:
    // 0x8001EF9C: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8001EFA0: addiu       $fp, $fp, -0x4D5A
    ctx->r30 = ADD32(ctx->r30, -0X4D5A);
    // 0x8001EFA4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001EFA8: sb          $zero, 0x0($fp)
    MEM_B(0X0, ctx->r30) = 0;
    // 0x8001EFAC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001EFB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001EFB4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EFB8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001EFBC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001EFC0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001EFC4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EFC8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001EFCC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001EFD0: jr          $ra
    // 0x8001EFD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001EFD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mark_read_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EDB8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EDBC: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EDC0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EDC4: addiu       $at, $zero, -0x301
    ctx->r1 = ADD32(0, -0X301);
    // 0x8006EDC8: andi        $t0, $a0, 0x3
    ctx->r8 = ctx->r4 & 0X3;
    // 0x8006EDCC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8006EDD0: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8006EDD4: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8006EDD8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006EDDC: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8006EDE0: jr          $ra
    // 0x8006EDE4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    return;
    // 0x8006EDE4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
;}
